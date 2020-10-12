#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H
//#pragma once

////allam 2020 cyclic include problem ////
#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "HTTPService_resolve_1.h"
#include "HTTPResponse_1.h"
//5-7-2020
#include "HttpClient_11_multiple_threads.h"

#include <boost/predef.h> // Tools to identify the OS.
// We need this to enable cancelling of I/O operations on
// Windows XP, Windows Server 2003 and earlier.
// Refer to "http://www.boost.org/doc/libs/1_58_0/doc/html/boost_asio/reference/basic_stream_socket/Cancel/overload1.html" for details.
//#ifdef BOOST_OS_WINDOWS
//#define _WIN32_WINNT 0x0501
#if _WIN32_WINNT <= 0x0502 // Windows Server 2003 or earlier.
#define BOOST_ASIO_DISABLE_IOCP
#define BOOST_ASIO_ENABLE_CANCELIO
#endif
//#endif


#define BOOST_COROUTINES_NO_DEPRECATION_WARNING

namespace fs = boost::filesystem;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class HTTPClient;
class HTTPRequest :public boost::enable_shared_from_this<HTTPRequest>//4-9-2020 made in line 80 in HTTPClient.cpp CreateRequest
{
	
public:
	/////alllllaaaaammmmm 2020/////////HTTPRequest(boost::asio::io_service&, unsigned int, std::string, const HTTPServiceResolve&, LoggingClass_2 &);
	HTTPRequest(boost::asio::io_service&, unsigned int, std::string, const HTTPServiceResolve&, boost::shared_ptr<LoggingClass_2>,  boost::shared_ptr<HTTPClient>);

	void SetHost(const std::string&);
	//void SetPort(unsigned int);
	void SetUri(const std::string&);
	const std::string GetHost() const;
	//unsigned int GetPort() const;
	const std::string GetUri() const;
	const std::string GetUrl() const;

	const unsigned int GetId() const;
	const std::string GetmUrlLogger() const;

	const bool GetmSendRequest() const;
	const bool GetmReadStatusLine() const;
	const bool GetmReadResponseHeaders() const;
	const bool GetmReadResponseBody() const;

	boost::shared_ptr<HTTPResponse> GetResponseSharedPtr();

	////allam2020 void Execute(boost::asio::yield_context, std::string, std::map<std::string, boost::shared_ptr<HTTPRequest>>&, std::map<std::string, boost::shared_ptr<HTTPResponse>>&);
	////????std::string Execute(boost::asio::yield_context, std::string,  std::map<std::string, boost::shared_ptr<HTTPResponse>>&);
	void Execute(boost::asio::yield_context, std::string,  boost::shared_ptr<std::map<std::string, boost::shared_ptr<HTTPResponse>>>);
	
	

	//4-9-2020 trial of promise
	//13std::string Execute(boost::asio::yield_context, boost::promise<std::string> &, std::string, boost::shared_ptr<std::map<std::string, boost::shared_ptr<HTTPResponse>>>);


	void Cancel();

private:

	// Send the request message.
	void SendRequest(boost::asio::yield_context);

	// Read the status line.
	void ReadStatusLine(boost::asio::yield_context);

	// Now read the response headers.
	void ReadResponseHeaders(boost::asio::yield_context);

	// Now we want to read the response body.
	void ReadResponseBody(boost::asio::yield_context);

	void OnFinish(const boost::system::error_code&);
	//void on_finish_0(const boost::system::error_code&);
	void OnFinishOld(const boost::system::error_code&);
	//4-8-2020 this is new replace
	std::string& replace(std::string&, const std::string&, const std::string&);
	//4-24-2020
	std::string output_compressed_file(boost::asio::streambuf& , const std::string& );
	//std::string output_compressed_file_2(boost::shared_ptr<unsigned char>  data_bin_buffer, size_t, const char * file_name);
	std::string output_compressed_file_2(unsigned char**  data_bin_buffer, size_t, const char * file_name);
	int read_bi5_main(boost::filesystem::path, ptime );
	//8-10-2020
	void read_bi5_to_bin_boost(std::string, std::string);
private:
	// Request parameters.
	std::string mHost;
	//unsigned int mPort;
	std::string mPortStr;
	std::string mUri;
	std::string mUrl;

	// Object unique identifier.
	unsigned int mId;

	// Buffer containing the request line.
	std::string mRequestBuf;
	boost::asio::ip::tcp::socket mSock;

	boost::shared_ptr<HTTPResponse> mResponsePtr = boost::make_shared<HTTPResponse>();//4-9-2020					
	std::atomic_int mSendRequest{ 0 };
    std::atomic_int mReadStatusLine{0};
    std::atomic_int mHttp_1_1{ 0 };
	////allam 2020
	std::string mHTTP_Version{ "" };
	std::string mStatusCode{ "" };
	std::string mStatusMessage{ "" };
	////allam 2020 std::istream mResponse_Stream(&mResponsePtr->get_response_buf());

	std::atomic_int mStatusCodeNot200{ 0 };
	//17-9-2020 add the following marker
	std::atomic_int mStatusCodeisClientError{0};
	std::atomic_int mReadResponseHeaders{ 0 };
	std::string mHeader{""};
	std::string mHeaderName{""};
	std::string mHeaderValue{""};

	int mReadResponseBody{ 0 };
	std::atomic_bool mContinue_for{ false };

	std::atomic_bool mWasCancelled{false};
	boost::mutex mCancelMutex;
	boost::mutex mCoutMutex;
	boost::mutex & mBOOST_LOGMutex;
	boost::mutex m_read_bi5_to_binMutex;
	boost::mutex ExecuteMutex;
	boost::mutex SendRequestMutex;
	boost::mutex ReadStatusLineMutex;
	boost::mutex ReadResponseHeadersMutex;
	boost::mutex ReadResponseBodyMutex;
	boost::mutex OnFinishMutex;

	
	boost::asio::io_service& mIos;
	Shared_ptr_vec_resolver_iterator mRequestSharedPtrVecResolverIterator;
	//const HTTPServiceResolve& mRequestResolveAddr;

	////for logger work
	//allllllllammmm 2020 ///LoggingClass_2 & mRequsetLoggingInstance;
	////alllammmm 2020 ////logging_class & mRequsetLoggingInstance;
	////alllllllllaaaaaaaaaammmmmm 2020 LoggingClass_2 & mRequsetLoggingInstance2;
	////allam 2020 logging_class & mRequsetLoggingInstance2;////allam 2020 convert to shared pointer
	boost::shared_ptr<LoggingClass_2> mHTTPRequest_LoggingInstance_shared_pointer;
	std::string mUrlLogger{};
	ptime mStartLog = second_clock::local_time();

	int mIrange{ 0 };
	/*
	src::channel_logger_mt<> lg0_first_date_with_404{ keywords::channel = "0" };
	src::channel_logger_mt<> lg1_first_date_with_200{ keywords::channel = "1" };
	src::channel_logger_mt<> lg2_dates_with_zero_size_after_first_date_with_200{ keywords::channel = "2" };
	src::channel_logger_mt<> lg3_dates_of_saturday_and_sunday_after_first_date_with_200{ keywords::channel = "3" };
	src::channel_logger_mt<> lg4_dates_not_saturday_or_sunday_after_first_date_with_200_having_zero_size{ keywords::channel = "4" };
	src::channel_logger_mt<> lg5_dates_not_saturday_or_sunday_after_first_date_with_200_having_400{ keywords::channel = "5" };
	src::channel_logger_mt<> lg6_last_date_recieved_and_written_to_file{ keywords::channel = "6" };
	src::channel_logger_mt<> lg7_m_cout_log{ keywords::channel = "m_cout_log" };
	*/
private:
	boost::asio::steady_timer mAsyncTimer;
	//5-7-2020
	boost::shared_ptr<HTTPClient> mHTTPRequest_HTTPClient_shared_pointer;
	std::string mHTTPRequest_Symbol_str{""};
	//21-9-2020	HTTPServiceResolve& mHTTPRequestServiceResolve;
public:
	std::string m_formatting_ostream_string{ "" };
	//4-6-2020 i will change the formatting_ostream to std::ostream so that i find no need to overload << operator in BOOST_LOG_function.cpp
	logging::formatting_ostream m_formatting_ostream{ m_formatting_ostream_string };
	//4-6-2020std::ostream m_formatting_ostream{ m_formatting_ostream_string };

	////std::map<std::string, boost::shared_ptr<HTTPResponse>> responses

	std::string mHTTPRequest_response_name{""};
	std::string miterator_resolveRemoteEndpoint{""};
};


#endif // !HTTP_REQUEST_H

