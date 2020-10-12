#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "my_logger_class_single_map.h"
#include "HttpSymbolPrepareGet_1_multiple_threads.h"
#include "HTTPService_resolve_1.h"
#include "modules/utils/utils.h"
#include "modules/utils_dst/utils_dst.h"
#include "modules/program_options/program_options_2.h"
#include "modules/utils_env_sig/utils_env_sig.h"

namespace http_errors
{
	const char* http_errors_category::name() const BOOST_SYSTEM_NOEXCEPT
	{
		return "http_errors";
	}
	std::string http_errors_category::message(int e) const
	{
		switch (e)
		{
		case invalid_response:
			return "Server response cannot be parsed.";
			break;
		default:
			return "Unknown error.";
			break;
		}
	}

} // namespace http_errors
const boost::system::error_category& http_errors::get_http_errors_category()
{
	static http_errors_category cat;
	return cat;
}
boost::system::error_code http_errors::make_error_code(http_error_codes e)
{
	return boost::system::error_code(
		static_cast<int>(e), get_http_errors_category());
}

int main(int argc, char* argv[])
{
	boost::mutex Main_mBOOST_LOGMutex;
	//1-10-2020 i think i must protect BOOST_LOG((*mLoggingInstance_shared_pointer).mloggerCoutLog) with mutex to avoid core problems
	boost::shared_ptr<LoggingClass_2> mLoggingInstance_shared_pointer = boost::make_shared<LoggingClass_2>();
	Main_mBOOST_LOGMutex.lock();
	BOOST_LOG((*mLoggingInstance_shared_pointer).mloggerCoutLog) << "starting program";
	Main_mBOOST_LOGMutex.unlock();

	//1 init program_options and configure it
	po::variables_map vm = init_program_options(argc, argv);
	std::string root_path {vm["folder"].as<std::string>() };
	//3 init signal manipulation
	set_up_signals();
	date day = vm["startdate"].as<date>();//10-9-2020 start date is determined and defined in program_options_2.cpp
	std::vector<symbols_enum> symbols_vec = vm["symbols"].as<std::vector<symbols_enum>>();
	try
	{
		HTTPServiceResolve resolve_addr(mLoggingInstance_shared_pointer);
		resolve_addr.ResolveFunc();
		
		boost::basic_thread_pool tp(MAXNUMBERTHREADS);
		for (auto symbol_each : symbols_vec)
		{
			tp.submit([symbol_each, day, &resolve_addr, &Main_mBOOST_LOGMutex,root_path]()
			{
				boost::shared_ptr<HttpSymbolPrepareGet> HttpSymbolPrepareGet_thread_func = boost::make_shared<HttpSymbolPrepareGet>(symbol_each, day, resolve_addr, Main_mBOOST_LOGMutex,root_path);
				HttpSymbolPrepareGet_thread_func->GetDay();
			}
			);
		}
		tp.close();
		tp.join();
	}
	catch (boost::system::system_error &e)
	{
		Main_mBOOST_LOGMutex.lock();

		BOOST_LOG((*mLoggingInstance_shared_pointer).mloggerCoutLog) << "Error occured! Error code = " << e.code()<< ". Message: " << e.what();
		Main_mBOOST_LOGMutex.unlock();

		return e.code().value();
	}
	return 0;
}

