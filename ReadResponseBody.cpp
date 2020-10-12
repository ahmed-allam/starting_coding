#include "HTTPRequest_12_multiple_threads.h"

// Now we want to read the response body.
void HTTPRequest::ReadResponseBody(boost::asio::yield_context yield_r)
{
	boost::unique_lock<boost::mutex> ReadResponseBody_lock(mBOOST_LOGMutex, boost::defer_lock);
	boost::system::error_code ec;
	std::size_t bytes_transferred_read_response_body = boost::asio::async_read(mSock, mResponsePtr->get_response_buf(), yield_r[ec]);

	if (ec.value() == boost::system::errc::errc_t::success)//(ec.value()==0)
	{
		this->mReadResponseBody = 0;
		//??5-17-2020 isolate multithreaded error

		boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
		if (mWasCancelled)
		{
			cancel_lock.unlock();
			OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));
			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read inside HTTPRequest::ReadResponseBody using" << mSock.remote_endpoint().address().to_string() << std::endl;
			ReadResponseBody_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read inside HTTPRequest::ReadResponseBody using" << miterator_resolveRemoteEndpoint << std::endl;
			ReadResponseBody_lock.unlock();

			return;
		}
		cancel_lock.unlock();

		ReadResponseBody(yield_r);////allam2020 4-4-2020 i can not find document which say that async_read with large files will return success and still need to recalled till file is complete>????????>>>>>>>>>>>>?>???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
		//allam2020 4-3-2020 now Response body is stored in mHTTPResponse

	}
	else if (ec.value() == boost::asio::error::eof)////allam2020 eof=2 in error.hpp and error.ipp error_code.hpp   eof means file totally recieved
	{
		this->mReadResponseBody = 0;
		//??5-17-2020 isolate multithreaded error

		boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
		if (mWasCancelled)
		{
			cancel_lock.unlock();
			OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));
			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read inside HTTPRequest::ReadResponseBody using" << mSock.remote_endpoint().address().to_string() << std::endl;
			ReadResponseBody_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read inside HTTPRequest::ReadResponseBody using" << miterator_resolveRemoteEndpoint << std::endl;
			ReadResponseBody_lock.unlock();

			return;
		}
		cancel_lock.unlock();

		//allam2020 4-3-2020 now Response body is stored in mHTTPResponse

		OnFinish(boost::system::error_code());////allam2020 4-3-2020 this boost::system::error_code() constructor makes error_code with value0 and failed== false
	}
	////allam2020 the next if condtion should be modified to contain ec.value()=eof=2 too
	else if ((ec.value() != boost::system::errc::errc_t::success) && (ec.value() != boost::asio::error::eof))//(ec.value()==0) //(ec.value() != 0)
	{
		OnFinish(ec);
		this->mReadResponseBody += 1;
		this->mContinue_for = (!mContinue_for);
		//??5-17-2020 isolate multithreaded error
		ReadResponseBody_lock.lock();

		//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read inside HTTPRequest::ReadResponseBody with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;

		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read inside HTTPRequest::ReadResponseBody with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;
		ReadResponseBody_lock.unlock();

		return;//4-2-2020 now i return to (ReadResponseHeaders OR ReadResponseBody) to return to ReadStatusLine to return to SendRequest to return to Execute to continue for loop
	}
	//??else
	//??{
	//??	ReadResponseBody(yield_r);
	//??}

}



