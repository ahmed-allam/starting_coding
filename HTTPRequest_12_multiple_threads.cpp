#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "HTTPRequest_12_multiple_threads.h"

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem.hpp>
#include <ninety47/dukascopy.h>
#include <ninety47/dukascopy/defs.h>
#include <cstring>
#include <iostream>
#include <fstream>
namespace fs = boost::filesystem;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

HTTPRequest::HTTPRequest(boost::asio::io_service& ios, unsigned int id, std::string URL, const HTTPServiceResolve& resolve_addr, boost::shared_ptr<LoggingClass_2> mHTTPRequest_LoggingInstance_shared_pointer, boost::shared_ptr<HTTPClient> mHTTPRequest_HTTPClient_shared_pointer) :
	
	mId(id),
	mSock(ios),
	mUrl(URL),
	mUrlLogger(URL),
	mWasCancelled(false),
	mIos(ios),
	mHTTPRequest_LoggingInstance_shared_pointer(mHTTPRequest_LoggingInstance_shared_pointer),
	mRequestSharedPtrVecResolverIterator(resolve_addr.GetSharedPtrVecResolverIterator()),
	//21-9-2020	mHTTPRequestServiceResolve(resolve_addr),
	mAsyncTimer(ios),//5-5-2020
	mHTTPRequest_HTTPClient_shared_pointer(mHTTPRequest_HTTPClient_shared_pointer),
	mBOOST_LOGMutex(mHTTPRequest_HTTPClient_shared_pointer->m_HttpClient_mBOOST_LOGMutexGet())
{
	mHTTPRequest_Symbol_str = mHTTPRequest_HTTPClient_shared_pointer->Get_mHttpClient_HttpSymbolPrepareGet_shared_pointer()->mSymbol_strGet();

	std::vector<std::string> values;
	boost::regex expression(
		//   proto                 host               port
		"^(\?:([^:/\?#]+)://)\?(\\w+[^/\?#:]*)(\?::(\\d+))\?"
		//   path                  file       parameters
		"(/\?(\?:[^\?#/]*/)*)\?([^\?#]*)\?(\\\?(.*))\?"
	);
	if (boost::regex_split(std::back_inserter(values), URL, expression))
	{
		const char* names[] = { "Protocol", "Host", "Port", "Path", "File",
			"Parameters", NULL };		
	}
	//??5-17-2020 isolate multithreaded error
	mBOOST_LOGMutex.lock();
	BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "IP addresses:"<< (*(*(resolve_addr.GetSharedPtrVecResolverIterator())).begin())->endpoint().address().to_string() <<" \n";
	mBOOST_LOGMutex.unlock();

	mUri = values[2] + values[3] + values[4] + values[5];
	mHost = resolve_addr.mHostNameGet();
	mPortStr = resolve_addr.mPortServiceGet();
	
	replace(mUrlLogger, "/", "-");
	// Put message to the "m_cout_log" channel
	//??5-17-2020 isolate multithreaded error
	mBOOST_LOGMutex.lock();

	BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "Fetching " << mUrlLogger;//allammmm2020 logging//
	mBOOST_LOGMutex.unlock();

}
//4-8-2020 this is new replace
std::string& HTTPRequest::replace(std::string& s, const std::string& from, const std::string& to)
{
	if (!from.empty())
		for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
			s.replace(pos, from.size(), to);
	return s;
}
void HTTPRequest::SetHost(const std::string& host)
{
	mHost = host;
}

void HTTPRequest::SetUri(const std::string& uri)
{
	mUri = uri;
}
const std::string HTTPRequest::GetHost() const
{
	return mHost;
}

const std::string HTTPRequest::GetUri() const
{
	return mUri;
}
const std::string HTTPRequest::GetmUrlLogger() const
{
	return mUrlLogger;
}
const std::string HTTPRequest::GetUrl() const
{
	return mUrl;
}

const unsigned int HTTPRequest::GetId() const
{
	return mId;
}

const bool HTTPRequest::GetmSendRequest() const
{
	return mSendRequest;
}
const bool HTTPRequest::GetmReadStatusLine() const
{
	return mReadStatusLine;
}
const bool HTTPRequest::GetmReadResponseHeaders() const
{
	return mReadResponseHeaders;
}
const bool HTTPRequest::GetmReadResponseBody() const
{
	return mReadResponseBody;
}

boost::shared_ptr<HTTPResponse> HTTPRequest::GetResponseSharedPtr()
{
	//4-9-2020 i ll change mResponsePtr to shared_from_this
	//return mResponsePtr;
	return mResponsePtr->shared_from_this();
}




void HTTPRequest::Cancel()
{
	boost::unique_lock<boost::mutex> cancel_lock(mCancelMutex);
	mWasCancelled = true;
	//m_resolver.Cancel();
	if (mSock.is_open())
	{
		mSock.cancel();
	}
}

void HTTPRequest::OnFinish(const boost::system::error_code& ec)
{
	boost::unique_lock<boost::mutex> OnFinish_lock(mBOOST_LOGMutex, boost::defer_lock);

	//??boost::unique_lock<boost::mutex> cout_lock(mCoutMutex, boost::defer_lock);
	//>>>>>>>>>>>>>>from http error value
	if (ec.value() == boost::system::errc::errc_t::success)
	{
		
		//4-27-2020BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " has completed. Response: " << this->GetResponseSharedPtr()-> ->get_response().rdbuf() << std::endl;
		//??5-17-2020 isolate multithreaded error
		OnFinish_lock.lock();

		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " has completed. Response: " << mHTTPRequest_response_name << std::endl;
		OnFinish_lock.unlock();

		return;
		//break;
	}
	else if (ec.value() != boost::system::errc::errc_t::success)
	{
		
		//5-7-2020 remove cout lines
		/*
		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "Error occured! Error code = " << ec.value() << ". Message: " << ec.message() << std::endl;
		*/
		//case boost::asio::error::operation_aborted:
		if (ec.value() == boost::asio::error::operation_aborted)
		{
			//??5-17-2020 isolate multithreaded error
			OnFinish_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " has been cancelled by the user." << std::endl;
			OnFinish_lock.unlock();

		}
		else
		{
			//??5-17-2020 isolate multithreaded error
			OnFinish_lock.lock();

			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << "Request #" << this->GetId() << " failed! Error code = " << ec.value() << ". Error message = " << ec.message() << " .mStatusCode ="<< mStatusCode << std::endl;
			OnFinish_lock.unlock();

		}
	}
	
	return;
}

