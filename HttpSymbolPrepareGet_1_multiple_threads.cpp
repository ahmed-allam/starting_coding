#include "HttpSymbolPrepareGet_1_multiple_threads.h"
#include "HttpClient_11_multiple_threads.h"
#include <cstdio>

HttpSymbolPrepareGet::HttpSymbolPrepareGet(symbols_enum symbol, date day_start, HTTPServiceResolve& resolve_addr,boost::mutex& Main_mBOOST_LOGMutex,std::string root_path) :
	mStartDate(day_start),
	mSymbol(symbol),
	mHTTPSymbolPrepareGet_refHTTPService_resolve(resolve_addr)
	, mHttpSymbolPrepareGet_mBOOST_LOGMutex(Main_mBOOST_LOGMutex)//20-9-2020 Main_mBOOST_LOGMutex of main()
	,mRootPath(root_path)
{	
	m_oss << symbol;
	mSymbol_str = m_oss.str();
	std::ostringstream().swap(m_oss); // swap m with a default constructed stringstream

	mHttpSymbolPrepareGet_LoggingInstance_shared_pointer = resolve_addr.mHTTPService_resolve_LoggingInstance_shared_pointerGet();
	if(BOOST_OS_WINDOWS)
	{
		mLocalPathMain = mLocalPathMain0;
	}
	mLocalPathMain_str = mLocalPathMain + mSymbol_str;
	//convert path string to actual path
	mLocalPathMain_path = init_path_Main_begin(mLocalPathMain_str,mRootPath);

	//make folder structure
	//make the first log folder path for the symbol to store all its logs	
	//6-11-2020
	mLogAllTime = init_path(mLocalPathMain_path.generic_string() + "/" + mSymbol_str + "_AT" + "/" +  mSymbol_str + "_AT");
	//Duration folder     Duration folder specefied

	mLogAll = mLogAllTime.parent_path();
	//pass the previous path to LoggingClass_2 instance to register it for back_ends
	//5-18-2020
	boost::unique_lock<boost::mutex> ConstructFolderDurationMaps_lock(mHttpSymbolPrepareGet_mBOOST_LOGMutex);
	(*mHttpSymbolPrepareGet_LoggingInstance_shared_pointer).ConstructFolderDurationMaps(mSymbol_str,mLogAllTime.filename().generic_string(), mLogAllTime.generic_string(), "AllTime", mLogAllTime, mHttpSymbolPrepareGet_mBOOST_LOGMutex);
	ConstructFolderDurationMaps_lock.unlock();
	
	m_previousYear = day_start.year();
	m_previousMonth = day_start.month().as_number();
	
	m_ss_year << (day_start.year());
	m_url_year = { m_ss_year.str() };
	std::stringstream().swap(m_ss_year);

	m_ss_month << std::setw(2) << std::setfill('0') << ((day_start.month().as_number()) - 1);
	m_url_month = { m_ss_month.str() };
	std::stringstream().swap(m_ss_month);

	m_ss_day << std::setw(2) << std::setfill('0') << day_start.day().as_number();
	m_url_day = { m_ss_day.str() };
	std::stringstream().swap(m_ss_day);

	//make file system for data and log files
	m_dataYearly = init_path(mLocalPathMain_path.generic_string() + "/" + m_url_year);
	m_logYearly = init_path(mLogAllTime.generic_string() + "/" +  mSymbol_str + "_Y" + "/" +  mSymbol_str + "_Y" + m_url_year);
	//5-18-2020
	ConstructFolderDurationMaps_lock.lock();
	(*mHttpSymbolPrepareGet_LoggingInstance_shared_pointer).ConstructFolderDurationMaps(mSymbol_str, m_logYearly.filename().generic_string(), m_logYearly.generic_string(), "Yearly", m_logYearly, mHttpSymbolPrepareGet_mBOOST_LOGMutex);
	ConstructFolderDurationMaps_lock.unlock();

	m_dataMonthly = init_path(m_dataYearly.generic_string() + "/" + m_url_month);
	m_logMonthly = init_path(m_logYearly.generic_string() + "/" + mSymbol_str + "_Y" + m_url_year + "_M" + "/" + mSymbol_str + "_Y" + m_url_year + "_M" + m_url_month);
	//5-18-2020
	ConstructFolderDurationMaps_lock.lock();
	(*mHttpSymbolPrepareGet_LoggingInstance_shared_pointer).ConstructFolderDurationMaps(mSymbol_str, m_logMonthly.filename().generic_string(), m_logMonthly.generic_string(), "Monthly", m_logMonthly, mHttpSymbolPrepareGet_mBOOST_LOGMutex);
	ConstructFolderDurationMaps_lock.unlock();

}

boost::shared_ptr<HttpSymbolPrepareGet> HttpSymbolPrepareGet::HttpSymbolPrepareGet_shared_pointer_to_this_Get()
{
	return shared_from_this();
}

void HttpSymbolPrepareGet::GetDay()
{	
	date_duration dd(1);
	//4-10-2020
	int start_day_present_flag{0};
	std::string days_512MB_filename_string,days_512MB_filename_string_1,days_512MB_filename_string_2;
	for (date startDateFor = mStartDate;startDateFor < day_clock::local_day();startDateFor = startDateFor + dd)
	{
		boost::unique_lock<boost::mutex> ConstructFolderDurationMaps_lock(mHttpSymbolPrepareGet_mBOOST_LOGMutex,boost::defer_lock);

		mDateOfEachDay = startDateFor;
		
		m_ss_year << (mDateOfEachDay.year());
		m_url_year = { m_ss_year.str() };
		std::stringstream().swap(m_ss_year);

		m_ss_month << std::setw(2) << std::setfill('0') << ((mDateOfEachDay.month().as_number()) - 1);
		m_url_month = { m_ss_month.str() };
		std::stringstream().swap(m_ss_month);

		m_ss_day << std::setw(2) << std::setfill('0') << mDateOfEachDay.day().as_number();
		m_url_day = { m_ss_day.str() };
		std::stringstream().swap(m_ss_day);
		
		if (mDateOfEachDay.year() == m_previousYear + 1)
		{

			m_dataYearly = init_path(mLocalPathMain_path.generic_string() + "/" + m_url_year);
			
			m_logYearly = init_path(mLogAllTime.generic_string() + "/" + mSymbol_str + "_Y" + "/" + mSymbol_str + "_Y" + m_url_year);
			//5-18-2020
			ConstructFolderDurationMaps_lock.lock();
			(*mHttpSymbolPrepareGet_LoggingInstance_shared_pointer).ConstructFolderDurationMaps(mSymbol_str, m_logYearly.filename().generic_string(), m_logYearly.generic_string(), "Yearly", m_logYearly, mHttpSymbolPrepareGet_mBOOST_LOGMutex);
			ConstructFolderDurationMaps_lock.unlock();


			m_previousYear = m_previousYear + 1;
		}

		if (mDateOfEachDay.month().as_number() % 12 == (m_previousMonth + 1) % 12)
		{
			m_dataMonthly = init_path(m_dataYearly.generic_string() + "/" + m_url_month);
			m_logMonthly = init_path(m_logYearly.generic_string() + "/" +  mSymbol_str + "_Y" + m_url_year + "_M" + "/" + mSymbol_str + "_Y" + m_url_year + "_M" + m_url_month);
			//5-18-2020
			ConstructFolderDurationMaps_lock.lock();
			(*mHttpSymbolPrepareGet_LoggingInstance_shared_pointer).ConstructFolderDurationMaps(mSymbol_str, m_logMonthly.filename().generic_string(), m_logMonthly.generic_string(), "Monthly", m_logMonthly, mHttpSymbolPrepareGet_mBOOST_LOGMutex);
			ConstructFolderDurationMaps_lock.unlock();

			m_previousMonth = ((m_previousMonth + 1) % 12);//?????????11-30-2019
		}

		m_dataDaily = init_path(m_dataMonthly.generic_string() + "/" + m_url_day);

		m_logDaily = init_path(m_logMonthly.generic_string() + "/" +  mSymbol_str + "_Y" + m_url_year + "_M" + "_" + m_url_month + "_D" + "/" +  mSymbol_str + "_D" + m_url_year + m_url_month + m_url_day);
		//5-18-2020
		ConstructFolderDurationMaps_lock.lock();
		(*mHttpSymbolPrepareGet_LoggingInstance_shared_pointer).ConstructFolderDurationMaps(mSymbol_str, m_logDaily.filename().generic_string(), m_logDaily.generic_string(), "Daily", m_logDaily, mHttpSymbolPrepareGet_mBOOST_LOGMutex);
		ConstructFolderDurationMaps_lock.unlock();

		mHTTPSymbolPrepareGet_URL_file_name={ mSymbol_str + "_" + m_url_year + "_" + m_url_month + "_" + m_url_day + "_" };

		//make the url root to which each hour will be added to request its file
		mHTTPSymbolPrepareGet_URL_root={ mHTTPSymbolPrepareGet_refHTTPService_resolve.GetServiceResolveProtocolHostUrl() + "/" + "datafeed" + "/" + mSymbol_str + "/" + m_url_year + "/" + m_url_month + "/" + m_url_day + "/" };

		
		boost::shared_ptr<HTTPClient> client = boost::make_shared<HTTPClient>((HttpSymbolPrepareGet_shared_pointer_to_this_Get()));

		client->CreateTasks();		
		client->FetchDay();		
		client->CloseClient();
		client.reset();

		//10-3-2020 here I want to collect all 24 hours of day in single csv file

		std::string day_filename_string =m_dataDaily.generic_string() + "/" + mSymbol_str + "_" + m_url_year + "_" + m_url_month + "_" + m_url_day + ".csv";
		std::ofstream ofile(day_filename_string, std::ios::app);
		if (!ofile.is_open())
		{
			//file not open (i.e. not created, access denied, etc). Print an error message or do something else...
			//throw;
		}
		//10-3-2020 here I want to collect all days in single 512MB csv file
		if(start_day_present_flag==0)
		{
			std::string hour_00_filename_string = m_dataDaily.generic_string() + "/" + "00h_ticks.csv";
			std::ifstream ifile00(hour_00_filename_string);
			//check to see that the input file exists:
			if (ifile00.is_open())
			{
				//file not open (i.e. not found, access denied, etc). Print an error message or do something else...
				start_day_present_flag=1;
			}
			init_path(mLocalPathMain_path.generic_string() + "/" + "CUDA_512MB_"+ mSymbol_str + "_files");
			days_512MB_filename_string_1 =mLocalPathMain_path.generic_string() + "/" + "CUDA_512MB_"+ mSymbol_str + "_files" + "/" + mSymbol_str +"_"+ m_url_year + "_" + m_url_month + "_" + m_url_day + "_";
			days_512MB_filename_string =mLocalPathMain_path.generic_string() + "/" + "CUDA_512MB_"+ mSymbol_str + "_files" + "/" + mSymbol_str +"_"+ m_url_year + "_" + m_url_month + "_" + m_url_day + "_"+".csv";
		}

		if(start_day_present_flag==1)
		{
		    std::streampos fsize = 0;
			std::ifstream days_512MB_filename_string_file( days_512MB_filename_string.c_str(),std::ios::binary);
			fsize = days_512MB_filename_string_file.tellg();
			days_512MB_filename_string_file.seekg( 0, std::ios::end );
			fsize = days_512MB_filename_string_file.tellg() - fsize;
			days_512MB_filename_string_file.close();

			if(fsize <= 1024*1024*512)
			{


			}
			else if(fsize > 1024*1024*512)
			{
				days_512MB_filename_string_2 =mLocalPathMain_path.generic_string() + "/" + "CUDA_512MB_"+ mSymbol_str + "_files" + "/" + days_512MB_filename_string_1 +"_"+ m_url_year + "_" + m_url_month + "_" + m_url_day + "_"+".csv";

				if (int x = std::rename(days_512MB_filename_string.c_str(), days_512MB_filename_string_2.c_str()) != 0)
					perror("Error renaming file");
				else
					std::cout << "File renamed successfully";

				days_512MB_filename_string_1 =mLocalPathMain_path.generic_string() + "/" + "CUDA_512MB_"+ mSymbol_str + "_files" + "/" + mSymbol_str +"_"+ m_url_year + "_" + m_url_month + "_" + m_url_day + "_";
				days_512MB_filename_string =mLocalPathMain_path.generic_string() + "/" + "CUDA_512MB_"+ mSymbol_str + "_files" + "/" + mSymbol_str +"_"+ m_url_year + "_" + m_url_month + "_" + m_url_day + "_"+".csv";
			}
			/*
			std::streampos fileSize( const char* filePath ){

			    std::streampos fsize = 0;
			    std::ifstream file( filePath, std::ios::binary );

			    fsize = file.tellg();
			    file.seekg( 0, std::ios::end );
			    fsize = file.tellg() - fsize;
			    file.close();

			    return fsize;
			}
			*/
		}


		std::ofstream ofile512(days_512MB_filename_string, std::ios::app);
		if (!ofile512.is_open())
		{
			//file not open (i.e. not created, access denied, etc). Print an error message or do something else...
			throw;
		}

		//std::ofstream ofile(day_filename_string, std::ios::app);
		//if (!ofile.is_open())
		//{
			//file not open (i.e. not created, access denied, etc). Print an error message or do something else...
		//	throw;
		//}

		for (int hour = 0; hour < 24; hour++)
		{
			//m_dataDaily;//the path to day files
			mHttpSymbolPrepareGet_ss_hour << std::setw(2) << std::setfill('0') << hour;
			mHttpSymbolPrepareGet_file_hour = { mHttpSymbolPrepareGet_ss_hour.str() };
			std::stringstream().swap(mHttpSymbolPrepareGet_ss_hour); // swap m with a default constructed stringstream
			std::string hour_filename_string = m_dataDaily.generic_string() + "/" + mHttpSymbolPrepareGet_file_hour+ "h_ticks.csv";

			std::ifstream ifile(hour_filename_string);

			//check to see that the input file exists:
			if (!ifile.is_open()) {
				//file not open (i.e. not found, access denied, etc). Print an error message or do something else...
				//throw;
			}
			//check to see that the output file exists:
			else if (!ofile.is_open()) {
				//file not open (i.e. not created, access denied, etc). Print an error message or do something else...
				//throw;
			}
			else {
				//then add more lines to the file if need be...

				ofile << ifile.rdbuf();

			}
			std::ifstream ifile2(hour_filename_string);

			//check to see that the input file exists:
			if (!ifile2.is_open()) {
				//file not open (i.e. not found, access denied, etc). Print an error message or do something else...
				//throw;
			}
			//check to see that the output file exists:
			else if (!ofile512.is_open()) {
				//file not open (i.e. not created, access denied, etc). Print an error message or do something else...
				//throw;
			}
			else {
				//then add more lines to the file if need be...
				//ofile512 << "fffffffff" << "\n";

				ofile512 << ifile2.rdbuf();

			}
		}



	}


}

const date& HttpSymbolPrepareGet::mStartDateGet() const
{
	return boost::cref(mStartDate);

}
const date& HttpSymbolPrepareGet::mDatePerDayGet() const
{
	return boost::cref(mDateOfEachDay);

}
const symbols_enum& HttpSymbolPrepareGet::mSymbolGet() const
{
	return mSymbol;

}
const std::string& HttpSymbolPrepareGet::mSymbol_strGet() const
{
	return mSymbol_str;

}
const std::string& HttpSymbolPrepareGet::mHTTPSymbolPrepareGet_URL_root_strGet() const
{
	return mHTTPSymbolPrepareGet_URL_root;

}


const HTTPServiceResolve& HttpSymbolPrepareGet::mHTTPSymbolPrepareGet_refHTTPService_resolveGet() const
{
	return boost::cref(mHTTPSymbolPrepareGet_refHTTPService_resolve);

}
const std::string& HttpSymbolPrepareGet::mLocalPathMainGet() const
{
	return mLocalPathMain0;//allam2020 >>0

}

const path& HttpSymbolPrepareGet::mLogAllGet() const
{
	return boost::cref(mLogAll);

}
boost::shared_ptr<LoggingClass_2>  HttpSymbolPrepareGet::mHttpSymbolPrepareGet_LoggingInstance_shared_pointerGet()
{
	////alllam return boost::ref(mLoggingInstance);
	return mHttpSymbolPrepareGet_LoggingInstance_shared_pointer;
}

const path& HttpSymbolPrepareGet::m_dataDailyGet() const
{
	return m_dataDaily ;//allam2020 >>0

}

//5-22-2020
boost::mutex&  HttpSymbolPrepareGet::mHttpSymbolPrepareGet_mBOOST_LOGMutexGet()
{
	return mHttpSymbolPrepareGet_mBOOST_LOGMutex;
}
