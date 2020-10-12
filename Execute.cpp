#include "HTTPRequest_12_multiple_threads.h"

void HTTPRequest::Execute(boost::asio::yield_context yield_r, std::string request_name, boost::shared_ptr<std::map<std::string, boost::shared_ptr<HTTPResponse>>> mHTTPClient_Responses_Map_shared_pointer)
{
	std::map<std::string, boost::shared_ptr<HTTPResponse>> & mHTTPClient_Responses_Map = boost::ref(*mHTTPClient_Responses_Map_shared_pointer).get() ;
	ptime startFetch = second_clock::local_time();
	boost::unique_lock<boost::mutex> Execute_lock(mBOOST_LOGMutex, boost::defer_lock);
	boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
	if (mWasCancelled)
	{
		cancel_lock.unlock();
		OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));
		m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user at start of HTTPRequest::Execute coroutine." << std::endl;
		m_formatting_ostream.flush();
		//21-9-2020 c_E means cancel_Execute
		boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "c_E", request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
		m_formatting_ostream_string.clear();
		return;
	}
	cancel_lock.unlock();

	bool iterator_failed = true;
	boost::system::error_code ec;

	// Compose the request message.
	mRequestBuf += "GET " + mUri + " HTTP/1.1\r\n";
	// Add mandatory header.
	mRequestBuf += "Host: " + mHost + "\r\n";
	mRequestBuf += "\r\n";
	for (auto iterator_resolve : *mRequestSharedPtrVecResolverIterator)
	//21-9-2020for (auto iterator_resolve : *(mHTTPRequestServiceResolve.mResolveResults.basic_resolver_iterator))
	{
		//6-18-2020
		miterator_resolveRemoteEndpoint =iterator_resolve->endpoint().address().to_string();

		Execute_lock.lock();

		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t"<<"Request #" << this->GetId() << " for " << mUrl <<" trying to send request using " << iterator_resolve->endpoint().address().to_string() << std::endl<<"\n";
		Execute_lock.unlock();


		//5-8-2020 changing continue to endless loop except for  404
		for (int mIrange2 =1; mIrange2 < ATTEMPTS; ++mIrange2)
		{
			 ++mIrange ;

			resolver_iterator iterator_connect = boost::asio::async_connect(mSock, iterator_resolve, yield_r[ec]);////allam 2020 this gets us back to io_stream_run
			//21-9-2020resolver_iterator iterator_connect = boost::asio::async_connect(mSock, mHTTPRequestServiceResolve.mResolveResults, yield_r[ec]);////allam 2020 this gets us back to io_stream_run

			if (ec.value() == boost::system::errc::errc_t::success)
			{
				////allam 2020
				iterator_failed = false;
				//??5-17-2020 isolate multithreaded error

				boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
				if (mWasCancelled)
				{
					cancel_lock.unlock();
					OnFinish(boost::system::error_code(boost::asio::error::operation_aborted));

					m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " has been cancelled by the user after returning from async_connect inside HTTPRequest::Execute using"<< iterator_resolve->endpoint().address().to_string() << std::endl;
					m_formatting_ostream.flush();
					//4-26-2020
					//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "cancel_async_connect_Execute", iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string);
					boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "c_a_c_E", request_name,m_formatting_ostream_string, mBOOST_LOGMutex);
					//5-16-2020m_formatting_ostream.clear();
					m_formatting_ostream_string.clear();


					//p.set_value(request_name);
					//return request_name;
					return;
				}
				cancel_lock.unlock();

				// Send the request message.
				SendRequest(yield_r);
			}
			else if (ec.value() != boost::system::errc::errc_t::success)
			{
				OnFinish(ec);
				//??5-17-2020 isolate multithreaded error
				Execute_lock.lock();

				BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) <<boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " for " << mUrl <<" failed after trying " << mIrange2 << "times" << " to async_connect inside HTTPRequest::Execute " << std::endl;
				Execute_lock.unlock();

				continue;
			}

			if (mContinue_for==true)
			{
				mContinue_for = !(mContinue_for);
				//5-5-2020 async timer
				//mAsyncTimer.expires_from_now(boost::asio::chrono::milliseconds(mIrange*10));//5-5-2020
				mAsyncTimer.expires_from_now(boost::asio::chrono::milliseconds(300));//5-5-2020 mIrange
				//mAsyncTimer.async_wait(yield_r);
				mAsyncTimer.wait();
				//5-7-2020
				if (mSendRequest == 0)
				{
					if (mReadStatusLine == 0)
					{
						if (mHttp_1_1 == 0)
						{
							if (mStatusCodeNot200 == 0)
							{
								if (mReadResponseHeaders == 0)
								{
									if (mReadResponseBody == 0)
									{
										////allam2020 4-4-2020 no error present and response is recieved in its mHTTPResponse SO DO NOTHING
									}
									else if (mReadResponseBody != 0)
									{
										mIrange2--;
									}
								}
								else if (mReadResponseHeaders != 0)
								{
									mIrange2--;

								}
							}
							else if (mStatusCodeNot200 != 0)
							{
								//17-9-2020 this makes program skips files when it is 503 or 307
								if (mStatusCodeisClientError == 0)
								{
									mIrange2--;
								}

							}
						}
						else if (mHttp_1_1 != 0)
						{
							mIrange2--;
						}
					}
					else if (mReadStatusLine != 0)
					{
						mIrange2--;
					}
				}
				else if (mSendRequest != 0)
				{
					mIrange2--;
				}

				continue;
			}

			// Response is correct.
			//??5-17-2020 isolate multithreaded error

			m_formatting_ostream <<  "Request #" << this->GetId() << " for " << mUrl << " Fetched " << mUrl << " completed in : " << (second_clock::local_time() - startFetch) << "with HTTP code :" << mResponsePtr->get_status_code() << "\t" << "and the code reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(mResponsePtr->get_status_code())) << "with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
			m_formatting_ostream.flush();

			//4-26-2020
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "http_request_completed", HttpStatus::reasonPhrase(static_cast<int>(mResponsePtr->get_status_code())), m_formatting_ostream_string, mBOOST_LOGMutex);
			boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "req_comp", HttpStatus::reasonPhrase(static_cast<int>(mResponsePtr->get_status_code())), m_formatting_ostream_string, mBOOST_LOGMutex);
			//5-16-2020m_formatting_ostream.clear();
			m_formatting_ostream_string.clear();


			if (mResponsePtr->get_response_buf().size() <= 0)
			{
				//??5-17-2020 isolate multithreaded error

				m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " Fetched " << mUrl << " with Buffer for " << mUrl << " is empty  " << "\n" << "with HTTP code :" << mResponsePtr->get_status_code() << "\n" << "and the code reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(mResponsePtr->get_status_code())) << std::endl;
				m_formatting_ostream.flush();

				//4-26-2020
				//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "http_request_completed_empty", HttpStatus::reasonPhrase(static_cast<int>(mResponsePtr->get_status_code())), m_formatting_ostream_string, mBOOST_LOGMutex);
				boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "req_comp_empty", HttpStatus::reasonPhrase(static_cast<int>(mResponsePtr->get_status_code())), m_formatting_ostream_string, mBOOST_LOGMutex);
				//5-16-2020m_formatting_ostream.clear();
				m_formatting_ostream_string.clear();

			}

			//continue work on response
			mHTTPRequest_response_name = "response_" + request_name;
			mHTTPClient_Responses_Map[mHTTPRequest_response_name] = GetResponseSharedPtr();

			//4-24-2020 here i will save to file
			std::size_t pos = mUrl.find("h_ticks.bi5");      // position of "h_ticks.bi5" in str
			std::string mHTTPRequest_file_name = mUrl.substr(pos - 2);     // get from "h_ticks.bi5" to the end
			std::string mHTTPRequest_hour_name = mUrl.substr(pos - 2,2);

			date mHTTPRequest_file_name_ptime_epoch_date =mHTTPRequest_HTTPClient_shared_pointer->m_HttpClient_Day_Full_DateGet() ;
			ptime mHTTPRequest_file_name_ptime_epoch(mHTTPRequest_file_name_ptime_epoch_date, pt::hours(std::stoi(mHTTPRequest_hour_name)));

			std::string compressed_file_path_string =output_compressed_file(mResponsePtr->get_response_buf(), mHTTPRequest_file_name);
			path compressed_file_path{ compressed_file_path_string };



			read_bi5_main(compressed_file_path, mHTTPRequest_file_name_ptime_epoch);
			break;
		}

		//??5-17-2020 isolate multithreaded error
		/*
		//the following conditions test the result of send request
		if (mSendRequest == 0)
		{
			if (mReadStatusLine == 0)
			{
				if (mHttp_1_1 == 0)
				{
					if (mStatusCodeNot200 == 0)
					{
						if (mReadResponseHeaders == 0)
						{
							if (mReadResponseBody == 0)
							{
								////allam2020 4-4-2020 no error present and response is recieved in its mHTTPResponse SO DO NOTHING
							}
							else if (mReadResponseBody != 0)
							{
								m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " has failed completely after trying" << ATTEMPTS << "times" << " to async_read inside HTTPRequest::ReadResponseBody to get ResponseBody  " << "with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
								m_formatting_ostream.flush();
								//4-26-2020
								//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_async_read_inside_HTTPRequest_ReadResponseBody", "requestFailed_ReadResponseBody_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string);
								//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_a_r_in_RRB", "reqFail_RRB_It_" + iterator_resolve->endpoint().address().to_string(),m_formatting_ostream_string, mBOOST_LOGMutex);
								boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_ar_RRB", "_" + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
								//5-16-2020m_formatting_ostream.clear();
								m_formatting_ostream_string.clear();

							}
						}
						else if (mReadResponseHeaders != 0)
						{
							m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " has failed completely after trying" << ATTEMPTS << "times" << " to async_read_until inside HTTPRequest::ReadResponseHeadersto get ResponseHeaders " << "with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
							m_formatting_ostream.flush();
							//4-26-2020
							//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_async_read_until_inside_HTTPRequest_ReadResponseHeaders", "requestFailed_ReadResponseHeaders_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string);
							//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_a_r_until_in_RRH", "reqFail_RRH_It_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
							boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_aru_RRH", "_" + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
							//5-16-2020m_formatting_ostream.clear();
							m_formatting_ostream_string.clear();

						}
					}
					else if (mStatusCodeNot200 != 0)
					{
						m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " has failed completely after" << ATTEMPTS << "times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of status_code not 200:" << http_errors::invalid_response << "the error code is :" << mStatusCode << "\n" << "and the error reasonPhrase is :" << HttpStatus::reasonPhrase(static_cast<int>(std::stoul(mStatusCode))) << "with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
						m_formatting_ostream.flush();
						//4-26-2020
						//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_StatusCodeNot200_inside_HTTPRequest_ReadStatusLine", "requestFailed_ReadStatusLine_StatusCodeNot200:StatusCode_is_" + mStatusCode + "with_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string);
						//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_Not200_in_RSL", "reqFail_RSL_Not200:St_is_" + mStatusCode + "with_It_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
						boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_N200_RSL", "_" + mStatusCode + "_" + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
						//5-16-2020m_formatting_ostream.clear();
						m_formatting_ostream_string.clear();

					}
				}
				else if (mHttp_1_1 != 0)
				{
					////4-2-2020
					m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " after trying " << ATTEMPTS << "times" << " to async_read_until inside HTTPRequest::ReadStatusLine because of bad not http/1.1 version response" << mHTTP_Version << "recieved with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
					m_formatting_ostream.flush();
					//4-26-2020
					//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_Http_1_1_inside_HTTPRequest_ReadStatusLine", "requestFailed_ReadStatusLine_Http_1_1_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string);
					//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_Http_1_1_in_RSL", "reqFail_RSL_Http_1_1_It_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
					boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_H11_RSL", "_" + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
					//5-16-2020m_formatting_ostream.clear();
					m_formatting_ostream_string.clear();

				}
			}
			else if (mReadStatusLine != 0)
			{
				////4-2-2020
				m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " failed completely after trying " << ATTEMPTS << "times" << " to async_read_until inside HTTPRequest::ReadStatusLine  with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
				m_formatting_ostream.flush();
				//4-26-2020
				//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_async_read_until_inside_HTTPRequest_ReadStatusLine", "requestFailed_ReadStatusLine_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
				//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_a_r_u_in_RSL", "reqFail_RSL_It_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
				boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_aru_RSL", "_" + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
				//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_aru_in_RSL", "_" , m_formatting_ostream_string, mBOOST_LOGMutex);
				//5-16-2020m_formatting_ostream.clear();
				m_formatting_ostream_string.clear();

			}
		}
		else if (mSendRequest != 0)
		{
			////4-2-2020
			m_formatting_ostream << "Request #" << this->GetId() << " for " << mUrl << " failed after trying " << ATTEMPTS << "times" << " to async_write inside HTTPRequest::SendRequest  with certain resolver iterator " << iterator_resolve->endpoint().address().to_string() << std::endl;
			m_formatting_ostream.flush();
			//4-26-2020
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_async_write_inside_HTTPRequest_SendRequest", "requestFailed_SendRequest_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "fail_aw_in_SR", "_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
			boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_aw_SR", "_" + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
			//5-16-2020m_formatting_ostream.clear();
			m_formatting_ostream_string.clear();

		}
		*/


		if (iterator_failed == true)
		{
			//??5-17-2020 isolate multithreaded error

			m_formatting_ostream << "Request failed for " << mUrl << " after trying " << ATTEMPTS << "times" << " to async_connect inside HTTPRequest::Execute with certain resolver iterator "<< iterator_resolve->endpoint().address().to_string() << std::endl;
			m_formatting_ostream.flush();
			////allam 2020 i might need to pass iterator resolve which has failed
			//4-26-2020
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_async_connect_inside_HTTPRequest_Execute", "requestFailed_Iterator_" + iterator_resolve->endpoint().address().to_string(), m_formatting_ostream_string, mBOOST_LOGMutex);
			//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "f_ac_E", "_" + iterator_resolve->endpoint().address().to_string()+ request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
			//std::string string_replace = { mSock.remote_endpoint().address().to_string() };
			std::string string_replace = { miterator_resolveRemoteEndpoint };
			replace(string_replace, ".", "");
			boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_ac_E", "_" + string_replace + request_name, m_formatting_ostream_string, mBOOST_LOGMutex);
			//5-16-2020m_formatting_ostream.clear();
			m_formatting_ostream_string.clear();


			continue;////allam 2020 here i should continue for next iterator
		}
	}
	//??5-17-2020 isolate multithreaded error

	if (iterator_failed == true)
	{
		m_formatting_ostream << "Request failed for " << mUrl << " after trying " << ATTEMPTS << "times" << " to async_connect inside HTTPRequest::Execute with ALL resolver iterators" << std::endl;
		m_formatting_ostream.flush();
		////allam 2020 i might need to pass iterator resolve which has failed
		//4-26-2020
		//boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, "failed_async_connect_inside_HTTPRequest_Execute", "requestFailed_Iterator_" + GetmUrlLogger(), m_formatting_ostream_string, mBOOST_LOGMutex);////allam2020 ?????i might need to change this from GetmUrlLogger to request name argument of Execute???????????????????4-2-2020
		boost_log_function(mHTTPRequest_LoggingInstance_shared_pointer, mHTTPRequest_Symbol_str, "f_ac_E", "_" + GetmUrlLogger()+ request_name,m_formatting_ostream_string, mBOOST_LOGMutex);////allam2020 ?????i might need to change this from GetmUrlLogger to request name argument of Execute???????????????????4-2-2020
																								//5-16-2020m_formatting_ostream.clear();
		m_formatting_ostream_string.clear();

		////allam 2020 here i should return from execute because no resolved address could be used so the whole execute request operation failed

		//p.set_value(request_name);
		//return request_name;
	}

	////allam2020 should i put if conditions for mSendRequest ....mReadResponseBody????? to identify final complete error at these functions and end of 5 attempts

}





