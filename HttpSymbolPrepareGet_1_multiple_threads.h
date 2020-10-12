#ifndef HTTPmSymbol_PREPARE_GET_H
#define HTTPmSymbol_PREPARE_GET_H

#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "HTTPService_resolve_1.h"
#include "boost_create_directory_3.h"
#include "HttpStatusCodes_C++11.h"
#include "my_logger_class_single_map.h"
#include "modules/utils/utils.h"
#include "modules/utils_dst/utils_dst.h"

class HttpClient;
class HttpSymbolPrepareGet :public boost::enable_shared_from_this<HttpSymbolPrepareGet>
{
	friend class HttpClient;

public:	
	HttpSymbolPrepareGet(symbols_enum, date, HTTPServiceResolve&, boost::mutex&,std::string);
	void GetDay();

	const date& mStartDateGet() const;
	const date& mDatePerDayGet() const;
	const symbols_enum& mSymbolGet() const;
	const std::string& mSymbol_strGet() const;

	const HTTPServiceResolve& mHTTPSymbolPrepareGet_refHTTPService_resolveGet() const;
	const std::string& mLocalPathMainGet() const;
	const path& mLogAllGet() const;
	boost::shared_ptr<LoggingClass_2> mHttpSymbolPrepareGet_LoggingInstance_shared_pointerGet();

	boost::shared_ptr<HttpSymbolPrepareGet> HttpSymbolPrepareGet_shared_pointer_to_this_Get();
	const std::string& mHTTPSymbolPrepareGet_URL_root_strGet() const;////allam2020
	//5-7-2020
	const path& m_dataDailyGet() const;

	//5-22-2020
	boost::mutex&  mHttpSymbolPrepareGet_mBOOST_LOGMutexGet();

private:
	date mStartDate = day_clock::local_day();
	date mDateOfEachDay = day_clock::local_day();////allam 2020 this is used in  GetDay

	symbols_enum mSymbol = symbols_enum::EURUSD;
	std::string mSymbol_str{""};

	HTTPServiceResolve& mHTTPSymbolPrepareGet_refHTTPService_resolve;
	path mLogAll;
	boost::shared_ptr<LoggingClass_2>  mHttpSymbolPrepareGet_LoggingInstance_shared_pointer;

private:
	//used mainly in GetDay method and constructor to make log folders
	//members for path formation
	std::string mRootPath{""};
	std::string mLocalPathMain = "MARKET_WORK/FOREX/forex_instruments/";
	std::string mLocalPathMain0 = "f1/";
	std::string mLocalPathMain_str = "";
	path mLocalPathMain_path;
	path mLogAllTime;

	std::ostringstream m_oss;
	days m_dd{ 1 };
	months m_mm{ 1 };
	years m_yy{ 1 };
		
	int m_previousYear = mStartDate.year();
	int m_previousMonth = mStartDate.month().as_number();

	path m_dataYearly;
	path m_logYearly;
	path m_dataMonthly;
	path m_logMonthly;
	path m_dataDaily;
	path m_logDaily;
		
	std::stringstream m_ss_year;
	std::string m_url_year{ m_ss_year.str() };
	std::stringstream m_ss_month;
	std::string m_url_month{ m_ss_month.str() };
	std::stringstream m_ss_day;
	std::string m_url_day{ m_ss_day.str() };

	std::string mHTTPSymbolPrepareGet_URL_file_name{""};
	std::string mHTTPSymbolPrepareGet_URL_root{ "" };

	//20-9-2020 boost::mutex mConstructFolderDurationMapsMutex;

	//5-22-2020
	boost::mutex&  mHttpSymbolPrepareGet_mBOOST_LOGMutex;
	//10-3-2020
	std::stringstream mHttpSymbolPrepareGet_ss_hour;
	std::string mHttpSymbolPrepareGet_file_hour{ "" };

};
#endif // !HTTPmSymbol_PREPARE_GET_H

