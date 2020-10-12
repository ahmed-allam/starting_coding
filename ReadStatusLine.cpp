#include "HTTPRequest_12_multiple_threads.h"

// Read the status line.
void HTTPRequest::ReadStatusLine(boost::asio::yield_context yield_r)
{
	boost::unique_lock<boost::mutex> ReadStatusLine_lock(mBOOST_LOGMutex, boost::defer_lock);
	//6-18-2020
	boost::system::error_code ec;

	std::size_t bytes_transferred_read_status_line = boost::asio::async_read_until(mSock, mResponsePtr->get_response_buf(), "\r\n", yield_r[ec]);

	if (ec.value() != boost::system::errc::errc_t::success)
	{
		OnFinish(ec);
		this->mReadStatusLine += 1;
		this->mContinue_for = (!mContinue_for);
		//??5-17-2020 isolate multithreaded error
		ReadStatusLine_lock.lock();
		//6-17-2020 in the next function mSock.remote_endpoint().address().to_string() is called and i think that this socket is now closed due to eof so this leads to error which leads to terminate thread.i will check this by putting it in try catch and see what exception say
		try
		{
			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		ReadStatusLine_lock.unlock();

		return;//4-2-2020 now i return to SendRequest to return to Execute to continue for loop
	}
	if (ec.value() == boost::system::errc::errc_t::success)
	{
		this->mReadStatusLine = 0;
		//??5-17-2020 isolate multithreaded error

		boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
		if (mWasCancelled)
		{
			cancel_lock.unlock();
			OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));
			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read_until inside HTTPRequest::ReadStatusLine using" << mSock.remote_endpoint().address().to_string() << std::endl;
			ReadStatusLine_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_read_until inside HTTPRequest::ReadStatusLine using" << miterator_resolveRemoteEndpoint << std::endl;
			ReadStatusLine_lock.unlock();

			return;
		}
		cancel_lock.unlock();

		//here we get information to do several things
		//first we make logging system based on received status_code
		//second we make some tests to determine continuing the connection or restarting it
		//so we should determine if to do the previous jobs here or after returning to Execute>>>>>>>>>i think i should make http1/1 test here because its result will determine if to continue to next function ReadResponseHeaders() or not ....and i think i will like to make log file for http1/1 failure

		std::istream response_stream(&(mResponsePtr->get_response_buf()));
		response_stream >> mHTTP_Version;

		////allam2020 i should not set response variables till request is completely finished>>>>>>no this is wrong because the design depends on HTTPResponse to record response then validate response ....so i ll use HTTPResponse instance and if request fails i ll clear it but i ll transfer the following line after mHTTP_Version test succeds
		if (mHTTP_Version != "HTTP/1.1")
		{
			// Response is incorrect.
			OnFinish(http_errors::invalid_response);
			this->mHttp_1_1 += 1;
			this->mContinue_for = (!mContinue_for);
			//??5-17-2020 isolate multithreaded error
			ReadStatusLine_lock.lock();

			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of bad not http/1.1 version:" << mHTTP_Version << " response recieved with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of bad not http/1.1 version:" << mHTTP_Version << " response recieved with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;

			ReadStatusLine_lock.unlock();

			return;
		}
		if (mHTTP_Version == "HTTP/1.1")
		{
			this->mHttp_1_1 = 0;
		}
		mResponsePtr->set_http_version(mHTTP_Version);

		////allam 2020 response_stream >> str_status_code;
		response_stream >> mStatusCode;

		//first we make logging files based on received status_code by async_read_until
		//4-2-2020 i think i should make these files after the end of the 5 ATTEMPTS and only do boost_log now >>>>>i make log files inside mStatusCode==200 and for mStatusCode!=200 i shall make them at the end of 5 attempts

		std::getline(response_stream, mStatusMessage, '\r');
		// Remove symbol '\n' from the buffer.
		response_stream.get();////allam2020 4-3-2020 this function read till next new line so that the next getline after it will read the next line"here it helps to skip the empty line \n"

		if (mStatusCode != std::to_string((HttpStatus::toInt(HttpStatus::Code::OK))))

		{
			//17-9-2020 here i should put condition to solve 307 and 503 and all other than 404
			//if (mStatusCode == std::to_string((HttpStatus::toInt(HttpStatus::Code::OK))))
			if (HttpStatus::isClientError(static_cast<int>(std::stoul(mStatusCode))))
			{
				// Response is incorrect.
				OnFinish(http_errors::invalid_response);
				this->mStatusCodeNot200 += 1;
				this->mStatusCodeisClientError += 1;
				this->mContinue_for = (!mContinue_for);
				//??5-17-2020 isolate multithreaded error
				//ReadStatusLine_lock.unlock();//i forget and made unlock instead of lock so it was unlocking unlocked lock giving error
				ReadStatusLine_lock.lock();

				//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of status_code not 200:" << http_errors::invalid_response << "the error code is :" << mStatusCode << "\n" << "and the error reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(std::stoul(mStatusCode))) << "with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;
				BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of status_code not 200 isClientError 4xx:" << http_errors::invalid_response << "the error code is :" << mStatusCode << "\n" << "and the error reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(std::stoul(mStatusCode))) << "with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;


				ReadStatusLine_lock.unlock();

				return;

			}
			//4-3-2020 i think i should make these files after the end of the 5 ATTEMPTS and only do boost_log now
			// Response is incorrect.
			OnFinish(http_errors::invalid_response);
			this->mStatusCodeNot200 += 1;
			this->mContinue_for = (!mContinue_for);
			//??5-17-2020 isolate multithreaded error
			//ReadStatusLine_lock.unlock();//i forget and made unlock instead of lock so it was unlocking unlocked lock giving error
			ReadStatusLine_lock.lock();

			//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of status_code not 200:" << http_errors::invalid_response << "the error code is :" << mStatusCode << "\n" << "and the error reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(std::stoul(mStatusCode))) << "with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << mIrange << " times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of status_code not 200:" << http_errors::invalid_response << "the error code is :" << mStatusCode << "\n" << "and the error reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(std::stoul(mStatusCode))) << "with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;


			ReadStatusLine_lock.unlock();

			return;
		}

		//4-3-2020 if (std::stoul(mStatusCode) == 200)
		else if (mStatusCode == std::to_string((HttpStatus::toInt(HttpStatus::Code::OK))))
		{
			this->mStatusCodeNot200 = 0;

			////allam2020 4-3-2020 i think that cancel is made with this synchronization to account for cancel operation which happens during async operation So i put the cancel part after ec.value() ==success directly and there is no reason to put cancel code here

			// At this point the status line is successfully
			// received and parsed.
			//??5-17-2020 isolate multithreaded error

			////allam2020 4-3-2020 i now make log files for mStatusCode=200
			//m_formatting_ostream << boost::this_thread::get_id() << "\t" << "Request for " << mUrl << " after trying " << mIrange << " times" << " has returned " << mStatusCode << " after returning from async_read_until inside  HTTPRequest::ReadStatusLine for file:" << this->GetUrl() << " with certain resolver iterator " << mSock.remote_endpoint().address().to_string() << std::endl;
			m_formatting_ostream << boost::this_thread::get_id() << "\t" << "Request for " << mUrl << " after trying " << mIrange << " times" << " has returned " << mStatusCode << " after returning from async_read_until inside  HTTPRequest::ReadStatusLine for file:" << this->GetUrl() << " with certain resolver iterator " << miterator_resolveRemoteEndpoint << std::endl;

			m_formatting_ostream.flush();
			////allam 2020 i might need to pass iterator resolve which has failed
			//4-26-2020
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "status_code_async_read_until_inside_HTTPRequest_ReadStatusLine", "request_status_code_200:this_is_status_code" + mStatusCode + "with_Iterator_" + mSock.remote_endpoint().address().to_string(), m_formatting_ostream_string);
			//std::string string_replace = { mSock.remote_endpoint().address().to_string() };
			//replace(string_replace, ".", "");
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "st_aru_RSL", "_" + mStatusCode + "_"+ string_replace,m_formatting_ostream_string, mBOOST_LOGMutex);
			//5-22-2020 st_aru is too long for BRENTCMDUS
			boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "st_aru_RSL", "_" + mStatusCode  , m_formatting_ostream_string, mBOOST_LOGMutex);
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "s_RSL", "_" + mStatusCode, m_formatting_ostream_string, mBOOST_LOGMutex);
			//5-16-2020m_formatting_ostream.clear();
			m_formatting_ostream_string.clear();

			// Now read the response headers.
			mResponsePtr->set_status_code(std::stoul(mStatusCode));
			mResponsePtr->set_status_message(mStatusMessage);

			ReadStatusLine_lock.lock();
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "ReadResponseHeaders is to be called" <<  std::endl;
			ReadStatusLine_lock.unlock();

			ReadResponseHeaders(yield_r);
			ReadStatusLine_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "ReadResponseHeaders returned" << std::endl;
			ReadStatusLine_lock.unlock();


		}
	}

}




