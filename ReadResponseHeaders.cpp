#include "HTTPRequest_12_multiple_threads.h"

// Now read the response headers.
void HTTPRequest::ReadResponseHeaders(boost::asio::yield_context yield_r)
{
	boost::unique_lock<boost::mutex> ReadResponseHeaders_lock(mBOOST_LOGMutex, boost::defer_lock);

	boost::system::error_code ec;
	std::size_t bytes_transferred_read_response_headers = boost::asio::async_read_until(mSock, mResponsePtr->get_response_buf(), "\r\n\r\n", yield_r[ec]);

	if (ec.value() != boost::system::errc::errc_t::success)
	{
		OnFinish(ec);
		this->mReadResponseHeaders += 1;
		this->mContinue_for = (!mContinue_for);
		//??5-17-2020 isolate multithreaded error
		ReadResponseHeaders_lock.lock();

		//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadResponseHeaders with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;

		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadResponseHeaders with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;
		ReadResponseHeaders_lock.unlock();

		return;//4-2-2020 now i return to ReadStatusLine to return to SendRequest to return to Execute to continue for loop
	}
	if (ec.value() == boost::system::errc::errc_t::success)
	{
		this->mReadResponseHeaders = 0;
		//??5-17-2020 isolate multithreaded error

		boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
		if (mWasCancelled)
		{
			cancel_lock.unlock();
			OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));
			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read_until inside HTTPRequest::ReadResponseHeaders using" << mSock.remote_endpoint().address().to_string() << std::endl;
			ReadResponseHeaders_lock.lock();
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read_until inside HTTPRequest::ReadResponseHeaders using" << miterator_resolveRemoteEndpoint << std::endl;
			ReadResponseHeaders_lock.unlock();

			return;
		}
		cancel_lock.unlock();

		// Parse and store headers.
		////allam2020 4-3-2020 std::string header, header_name, header_value;
		std::istream response_stream(&mResponsePtr->get_response_buf());
		while (true)
		{
			std::getline(response_stream, mHeader, '\r');
			// Remove \n symbol from the stream.
			response_stream.get();////allam2020 4-3-2020 this function read till next new line so that the next getline after it will read the next line"here it helps to skip the empty line \n"
			if (mHeader == "")
				break;
			size_t separator_pos = mHeader.find(':');
			if (separator_pos != std::string::npos)
			{
				mHeaderName = mHeader.substr(0,
					separator_pos);
				if (separator_pos < mHeader.length() - 1)
					mHeaderValue =
					mHeader.substr(separator_pos + 1);
				else
					mHeaderValue = "";

				mResponsePtr->add_header(mHeaderName, mHeaderValue);
			}
		}

		// Now we want to read the response body.
		ReadResponseBody(yield_r);
	}
}



