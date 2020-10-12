#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

//#pragma once

#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "HttpSymbolPrepareGet_1_multiple_threads.h"
#include "HTTPResponse_1.h"
#include "HTTPRequest_12_multiple_threads.h"
#include "HTTPService_resolve_1.h"

#include "modules/utils/utils.h"
#include "modules/utils_dst/utils_dst.h"

#include <boost/beast/core.hpp>
namespace net = boost::asio;
namespace beast = boost::beast;
using boost::system::error_code;

//6-7-2020 make next line to make the class declared???what is benefit of header file
class HTTPRequest;

class HTTPClient :public boost::enable_shared_from_this<HTTPClient>
{
	//friend class HTTPServiceResolve;

public:
	//??HTTPClient(HttpSymbolPrepareGet * const);//allam 2020 i change * const to shared_pointer	
	HTTPClient(boost::shared_ptr<HttpSymbolPrepareGet>);
	HTTPClient(const HTTPServiceResolve&, std::string, boost::shared_ptr<LoggingClass_2>, const symbols_enum, date);

	boost::asio::io_service& GetServiceReference();
	const HTTPServiceResolve& GetmClientResolveAddrReference();
	const std::map<std::string, boost::shared_ptr<HTTPRequest>>& GetClientRequestsVariablesReference();
	////allam2020
	std::map<std::string, boost::shared_ptr<HTTPResponse>>& Get_mHTTPClient_Responses_Map();

	boost::shared_ptr<HTTPClient> HTTPClient_shared_pointer_to_this_Get();

	boost::shared_ptr<HTTPRequest> CreateRequest(unsigned int, std::string, const HTTPServiceResolve&, boost::shared_ptr<LoggingClass_2>, boost::shared_ptr<HTTPClient>);
	//void CreateTasks(const symbols_enum, date);
	void CreateTasks();
	void output_compressed_file(boost::asio::streambuf&, const std::string&);

	void FetchDay();
	void CloseClient();

	//5-7-2020
	const std::string& m_dataDailyGet() const;

	//5-11-2020
	const date& m_HttpClient_Day_Full_DateGet() const;

	boost::shared_ptr<HttpSymbolPrepareGet> Get_mHttpClient_HttpSymbolPrepareGet_shared_pointer();
	//4-7-2020
	/*
	template<class F, class...Args>
	auto execute(F&& func, Args&&...args)
	{
		using zF = std::decay_t<F>&&;
		using R = std::result_of_t< zF(Args...) >;
		std::packaged_task<R()> task(
			std::bind([func = std::forward<F>(func)](auto&&...args)mutable->R{
			return std::move(func)(decltype(args)(args)...);
		}, std::forward<Args>(args)...)
		);
		return std::move(task);
	}
	*/
	//4-9-2020
	/*
	template<class F, class...Args>
	void execute(F&& func, Args&&...args);
	*/

	boost::shared_ptr<std::map<std::string, boost::shared_ptr<HTTPResponse>>> Get_mHTTPClient_Responses_Map_shared_pointer();

	//4-9-2020
	/*
	void using_yield_ec(boost::asio::yield_context yield);
	void using_handler();
	void using_future();
	void using_future_composed();
	//void async_composed_Execute();
	*/
	//std::string using_future_composed(std::string);
	/*
	template<				
		class CompletionToken>
		auto
		async_composed_Execute(std::string ,
			//boost::asio::io_service,
			//std::string, 
			//boost::shared_ptr<std::map<std::string, boost::shared_ptr<HTTPResponse>>>,
			CompletionToken&& token) ->
		typename net::async_result< //< `async_result` deduces the return type from the completion handler >
		typename std::decay<CompletionToken>::type,
		void(error_code,std::string) //< The completion handler signature goes here >
		>::return_type;
	*/
	std::string& replace(std::string&, const std::string&, const std::string&);
	boost::mutex & m_HttpClient_mBOOST_LOGMutexGet() ;

private:
	boost::asio::io_service mIos;
	std::unique_ptr<boost::asio::io_service::work> mWork;

	////allam2020 4-5-2020 the threads are done in boost_asio_http_coroutine_class.cpp>>>>>NO i ll make thread to run mIos
	////single thread5-16-2020
	boost::executor_adaptor<boost::basic_thread_pool> mDukaThreads;
	//5-16-2020 this mutex is made to guard BOOST_LOG multiindex iterators when using multiple threads to run mIos
	//5-22-2020
	boost::mutex & mBOOST_LOGMutex;
	boost::asio::steady_timer mTimer;


	/*
	boost::thread_group threads;
	*/
	//std::vector<std::future<std::string> > mPendingData; // vector of futures
	//std::vector<boost::future<std::string> > mPendingData; // vector of futures
	//std::vector<boost::future<void> > mPendingData; // vector of futures

	
	std::map<std::string, boost::shared_ptr<HTTPRequest>> mClientRequestsVariables;
	//std::map<std::string, boost::shared_ptr<HTTPResponse>> mClientResponses;
	////allam 2020
	std::map<std::string, boost::shared_ptr<HTTPResponse>> mHTTPClient_Responses_Map;

	symbols_enum m_Http_client_Symbol = symbols_enum::EURUSD;
	//10-3-2020day_clock::universal_day()
	date m_HttpClient_Day_Full_Date = date(2020, Mar, 24);//take care this date is the date of daysaving time change not random date
	//date m_HttpClient_Day_Full_Date =day_clock::universal_day();

	const HTTPServiceResolve& mClientResolveAddr;
	std::string mClientLocalPathMain;
	//allam2020 LoggingClass_2 & mClientLoggingInstance;//allam2020 i change reference to shared pointer
	boost::shared_ptr<LoggingClass_2>  mHttpClient_LoggingInstance_shared_pointer;
	boost::shared_ptr<HttpSymbolPrepareGet> mHttpClient_HttpSymbolPrepareGet_shared_pointer;
	
	//src::channel_logger_mt<> lg6_last_date_recieved_and_written_to_file{ keywords::channel = "6" };
	//src::channel_logger_mt<> lg7_m_cout_log{ keywords::channel = "m_cout_log" };
private: //// allam 2020 these members are used for intermediate stream operations
	std::stringstream m_HttpClient_ss_hour;
	std::string m_HttpClient_url_hour{ "" };
	std::string m_HttpClient_url_currency{ "" };
	std::string m_HttpClient_URL_root{ "" };
	std::string m_HttpClient_request_name{ "request_" };
	std::string m_HttpClient_URL{ "" };
	//5-7-2020 i want to make member string having the data folder pathway for the retreived files of client specefic requested day 
	std::string m_HttpClient_day_data_path_string{ "" };

	

};

#endif // !HTTP_CLIENT_H

