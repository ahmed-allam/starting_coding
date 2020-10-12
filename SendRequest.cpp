#include "HTTPRequest_12_multiple_threads.h"

// Send the request message.
void HTTPRequest::SendRequest(boost::asio::yield_context yield_r)
{
	//6-18-2020

	boost::unique_lock<boost::mutex> SendRequest_lock(mBOOST_LOGMutex, boost::defer_lock);

	boost::system::error_code ec;
	std::size_t bytes_transferred_send_request = boost::asio::async_write(mSock, boost::asio::buffer(mRequestBuf), yield_r[ec]);

	if (ec.value() != boost::system::errc::errc_t::success)
	{
		OnFinish(ec);
		this->mSendRequest += 1;
		this->mContinue_for =(!mContinue_for);
		//??5-17-2020 isolate multithreaded error
		SendRequest_lock.lock();
		//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_write inside HTTPRequest::SendRequest  with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;

		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_write inside HTTPRequest::SendRequest  with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;
		SendRequest_lock.unlock();

		return;////allam2020 now i return to Execute to continue for loop
	}

	if (ec.value() == boost::system::errc::errc_t::success)//(ec.value()==0)
	{
		this->mSendRequest = 0;

		mSock.shutdown(boost::asio::ip::tcp::socket::shutdown_send);
		//??5-17-2020 isolate multithreaded error

		boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
		if (mWasCancelled)
		{
			cancel_lock.unlock();
			OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));
			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_write inside HTTPRequest::SendRequest using" << mSock.remote_endpoint().address().to_string() << std::endl;
			SendRequest_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_write inside HTTPRequest::SendRequest using" << miterator_resolveRemoteEndpoint << std::endl;
			SendRequest_lock.unlock();

			return;
		}
		cancel_lock.unlock();

		// Read the status line.
		ReadStatusLine(yield_r);
	}
}




