//refactoring done 10-9-2020

#ifndef BOOST_ASIO_HTTP_COROUTINE_CLASS_H
#define BOOST_ASIO_HTTP_COROUTINE_CLASS_H
//#pragma once
//http://datafeed.dukascopy.com/datafeed/AUCMDUSD/2017/02/09/12h_ticks.bi5
//6-15-2020
//#include <boost/config.hpp>
#if ! defined  BOOST_NO_CXX11_DECLTYPE
#define BOOST_RESULT_OF_USE_DECLTYPE
#endif
//#define BOOST_MEM_FN_ENABLE_CDECL //4-9-2020 this is trial to fix asio post problem with bind 
#include <boost/bind.hpp>
#define BOOST_USE_WINAPI_VERSION _WIN32_WINNT  
#define BOOST_COROUTINES_NO_DEPRECATION_WARNING
//6-15-2020 
#ifdef BOOST_THREAD_VERSION
#undef BOOST_THREAD_VERSION
#endif
#define BOOST_THREAD_VERSION 5
#define BOOST_THREAD_PROVIDES_EXECUTORS
#define BOOST_THREAD_USES_LOG_THREAD_ID
#define BOOST_THREAD_QUEUE_DEPRECATE_OLD
#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION 
#define BOOST_THREAD_USES_MOVE

#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/date_time/gregorian/gregorian.hpp> //include all types plus i/o
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

#include <string>
#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <boost/range/irange.hpp>

#include <boost/thread.hpp>
#include <boost/thread/caller_context.hpp>               // for BOOST_CONTEXTOF, caller_context_t, operator<<
#include <boost/thread/executors/basic_thread_pool.hpp>  // for basic_thread_pool
#include <boost/thread/executors/executor.hpp>           // for executor
#include <boost/thread/executors/executor_adaptor.hpp>   // for executor_adaptor
#include <boost/thread/executors/generic_executor_ref.hpp>

#include <boost/thread/executors/loop_executor.hpp>
#include <boost/thread/executors/serial_executor.hpp>
#include <boost/thread/executors/inline_executor.hpp>
#include <boost/thread/executors/thread_executor.hpp>
#include <boost/thread/executor.hpp>
#include <boost/thread/future.hpp>
#include <boost/thread/mutex.hpp>

#include <boost/coroutine/all.hpp>
#include <boost/ref.hpp>
#include <boost/system/error_code.hpp>
#include <boost/enable_shared_from_this.hpp>  //this is for enable_shared_from_this

//??#include "modules/utils/utils.h"
//??#include "modules/utils_dst/utils_dst.h"

//??#include "modules/logging/my_logger_class_single_map_25.h"

#include "my_logger_class_single_map.h"
//??#include "boost_create_directory_2.h"
#include "HttpStatusCodes_C++11.h"
#include "BOOST_LOG_function.h"

constexpr int MAXNUMBERTHREADSPERCLIENT{ 1 };
constexpr int MAXNUMBERTHREADS{ 1 };//4-8-2020 >>4
const std::string gconstProtocolHostUrl = "http://datafeed.dukascopy.com";

constexpr int ATTEMPTS{ 2};

/*
#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include "HTTPService_resolve.h"
#include "boost_create_directory_2.h"
#include "HttpSymbolPrepareGet.h"
#include "HttpClient.h"
*/
/*
class HTTPClient;
class HTTPRequest;
class HTTPResponse;
class HTTPServiceResolve;
class HttpSymbolPrepareGet;
*/
namespace http_errors
{
	enum http_error_codes
	{
		invalid_response = 1
	};

	class http_errors_category
		: public boost::system::error_category
	{
	public:
		const char* name() const BOOST_SYSTEM_NOEXCEPT;

		std::string message(int) const;
	};

	const boost::system::error_category& get_http_errors_category();

	boost::system::error_code
		make_error_code(http_error_codes);

} // namespace http_errors

namespace boost {
	namespace system {
		template<>
		struct is_error_code_enum
			<http_errors::http_error_codes>
		{
			BOOST_STATIC_CONSTANT(bool, value = true);
		};
	} // namespace system
} // namespace boost







#endif // !BOOST_ASIO_HTTP_COROUTINE_CLASS_H
