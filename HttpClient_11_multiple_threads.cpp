#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "HttpClient_11_multiple_threads.h"

HTTPClient::HTTPClient(boost::shared_ptr<HttpSymbolPrepareGet> HttpSymbolPrepareGet_shared_pointer) :
	m_Http_client_Symbol(HttpSymbolPrepareGet_shared_pointer->mSymbolGet()),
	m_HttpClient_Day_Full_Date(HttpSymbolPrepareGet_shared_pointer->mDatePerDayGet()),
	mClientResolveAddr(HttpSymbolPrepareGet_shared_pointer->mHTTPSymbolPrepareGet_refHTTPService_resolveGet()),
	mClientLocalPathMain(HttpSymbolPrepareGet_shared_pointer->mLocalPathMainGet()),
	mHttpClient_LoggingInstance_shared_pointer(HttpSymbolPrepareGet_shared_pointer->mHttpSymbolPrepareGet_LoggingInstance_shared_pointerGet()),
	mHttpClient_HttpSymbolPrepareGet_shared_pointer(HttpSymbolPrepareGet_shared_pointer)
	,mTimer(mIos)
	////single thread5-16-2020
	,mDukaThreads(MAXNUMBERTHREADSPERCLIENT)
	, mBOOST_LOGMutex(HttpSymbolPrepareGet_shared_pointer->mHttpSymbolPrepareGet_mBOOST_LOGMutexGet())
{
	mWork.reset(new boost::asio::io_service::work(mIos));
	////single thread5-16-2020
	mDukaThreads.submit(std::bind(&HTTPClient::FetchDay, this));
	////single thread5-16-2020
	mDukaThreads.underlying_executor().close();

	m_HttpClient_day_data_path_string = mHttpClient_HttpSymbolPrepareGet_shared_pointer->m_dataDailyGet().generic_string() ;
}

const std::string& HTTPClient::m_dataDailyGet() const
{
	return m_HttpClient_day_data_path_string;//allam2020 >>0
}

const date& HTTPClient::m_HttpClient_Day_Full_DateGet() const
{
	return m_HttpClient_Day_Full_Date;//allam2020 >>0
}

boost::mutex & HTTPClient::m_HttpClient_mBOOST_LOGMutexGet()
{
	return mBOOST_LOGMutex;
}

boost::asio::io_service& HTTPClient::GetServiceReference()
{
	return boost::ref(mIos);
}

const HTTPServiceResolve& HTTPClient::GetmClientResolveAddrReference()
{
	return boost::ref(mClientResolveAddr);
}

const std::map<std::string, boost::shared_ptr<HTTPRequest>>& HTTPClient::GetClientRequestsVariablesReference()
{
	return boost::ref(mClientRequestsVariables);
}

std::map<std::string, boost::shared_ptr<HTTPResponse>>& HTTPClient::Get_mHTTPClient_Responses_Map()
{
	return boost::ref(mHTTPClient_Responses_Map);
}

boost::shared_ptr<std::map<std::string, boost::shared_ptr<HTTPResponse>>> HTTPClient::Get_mHTTPClient_Responses_Map_shared_pointer()
{
	return boost::make_shared<std::map<std::string, boost::shared_ptr<HTTPResponse>>>(mHTTPClient_Responses_Map);
}

boost::shared_ptr<HttpSymbolPrepareGet> HTTPClient::Get_mHttpClient_HttpSymbolPrepareGet_shared_pointer()
{
	return mHttpClient_HttpSymbolPrepareGet_shared_pointer->shared_from_this();
}

void HTTPClient::FetchDay()
{	
	mIos.run();
}
boost::shared_ptr<HTTPClient> HTTPClient::HTTPClient_shared_pointer_to_this_Get()
{
	return shared_from_this();
}

boost::shared_ptr<HTTPRequest> HTTPClient::CreateRequest(unsigned int id, std::string URL, const HTTPServiceResolve& resolve_addr, boost::shared_ptr<LoggingClass_2> mHttpClient_LoggingInstance_shared_pointer, boost::shared_ptr<HTTPClient> HTTPClient_shared_pointer_to_this)
{
	return boost::make_shared<HTTPRequest>(mIos, id, URL, resolve_addr, mHttpClient_LoggingInstance_shared_pointer, HTTPClient_shared_pointer_to_this);
}

std::string& HTTPClient::replace(std::string& s, const std::string& from, const std::string& to)
{
	if (!from.empty())
		for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
			s.replace(pos, from.size(), to);
	return s;
}

void HTTPClient::CreateTasks()
{
	int start_dst = 0;//what is its use  >>>may be needed for the two days when clock is changed
	if (is_dst_x(m_HttpClient_Day_Full_Date))
	{
		start_dst = 1;
	}
	
	m_HttpClient_URL_root = mHttpClient_HttpSymbolPrepareGet_shared_pointer->mHTTPSymbolPrepareGet_URL_root_strGet();
	std::size_t pos = m_HttpClient_URL_root.find("datafeed/");      // position of "h_ticks.bi5" in str
	std::string mHTTPRequest_name = m_HttpClient_URL_root.substr(pos +9);
	replace(mHTTPRequest_name,"/","");

	//12-10-2020
	std::vector<int> hour_0{6,8,10,13,14,21};
	//12-10-2020for (int hour = 0; hour < 24; hour++)
	int hour{0};
	for (auto hourx =hour_0.begin(); hourx < hour_0.end(); hourx++)
	{
		hour=*hourx;
		mTimer.expires_from_now(boost::asio::chrono::milliseconds(300));//5-5-2020 mIrange
		mTimer.wait();
		m_HttpClient_ss_hour << std::setw(2) << std::setfill('0') << hour;
		m_HttpClient_url_hour = { m_HttpClient_ss_hour.str() };
		std::stringstream().swap(m_HttpClient_ss_hour); // swap m with a default constructed stringstream
		m_HttpClient_URL = m_HttpClient_URL_root + m_HttpClient_url_hour + "h_ticks.bi5";
		m_HttpClient_request_name = "req" + mHTTPRequest_name+ std::to_string(hour);
		mClientRequestsVariables[m_HttpClient_request_name] = CreateRequest(hour, m_HttpClient_URL, mClientResolveAddr, mHttpClient_LoggingInstance_shared_pointer, HTTPClient_shared_pointer_to_this_Get())->shared_from_this() ;
		boost::asio::spawn(mIos,
			[m_HttpClient_request_name_to_composed = m_HttpClient_request_name,this](boost::asio::yield_context yield)
		{
			(*(mClientRequestsVariables[m_HttpClient_request_name_to_composed]->shared_from_this())).Execute(yield, m_HttpClient_request_name_to_composed, Get_mHTTPClient_Responses_Map_shared_pointer());
		}
		);
	}

	mWork.reset(NULL);

}

void HTTPClient::output_compressed_file(boost::asio::streambuf& taskStreambuf, const std::string& file_name)
{
	std::ofstream ofs(file_name, std::ios::binary); // binary mode!!
	unsigned long int pcbRead{0}; // number of bytes actually read
	ofs.write(boost::asio::buffer_cast<const char*>(taskStreambuf.data()), pcbRead);
	ofs.close();
}


void HTTPClient::CloseClient()
{
	////single thread5-16-2020
	if (mDukaThreads.underlying_executor().closed())
	{
		////single thread5-16-2020
		mDukaThreads.underlying_executor().join();
	}
}
