//#include "stdafx.h"
//??#include "boost_asio_http_coroutine_class.h"
#include "HTTPService_resolve_1.h"

//4-8-2020 this is new replace 


bool HTTPServiceResolve::replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t startPos = str.find(from);
	if (startPos == std::string::npos)
		return false;
	str.replace(startPos, from.length(), to);
	return true;
}


HTTPServiceResolve::HTTPServiceResolve(boost::shared_ptr<LoggingClass_2> mHTTPService_resolve_LoggingInstance_shared_pointer) :
	mServiceResolveProtocolHostUrl(gconstProtocolHostUrl),
	mHTTPService_resolve_LoggingInstance_shared_pointer(mHTTPService_resolve_LoggingInstance_shared_pointer)
{

}
HTTPServiceResolve::HTTPServiceResolve(std::string new_protocol_host_URL, boost::shared_ptr<LoggingClass_2> mHTTPService_resolve_LoggingInstance_shared_pointer) :
	mServiceResolveProtocolHostUrl(new_protocol_host_URL),
	mHTTPService_resolve_LoggingInstance_shared_pointer(mHTTPService_resolve_LoggingInstance_shared_pointer)
{

}

void HTTPServiceResolve::ResolveFunc()
{
	return ResolveFunc(mServiceResolveProtocolHostUrl);
}

//20-9-2020 we can give ResolveFunc an URL directly without creating class HTTPServiceResolve instance with this URL
void HTTPServiceResolve::ResolveFunc(std::string protocol_host_URL)
{
	std::string protocol_host_URL_copy{ protocol_host_URL };
	std::vector<std::string> values;
	boost::regex expression(
		//   proto                 host               port
		"^(\?:([^:/\?#]+)://)\?(\\w+[^/\?#:]*)(\?::(\\d+))\?"
		//   path                  file       parameters
		"(/\?(\?:[^\?#/]*/)*)\?([^\?#]*)\?(\\\?(.*))\?"
	);
	if (boost::regex_split(std::back_inserter(values), protocol_host_URL, expression))
	{
		const char* names[] = { "Protocol", "Host", "Port", "Path", "File",
			"Parameters", NULL };
	}

	mHostName = values[1];
	mPortService = values[0];

	//logging url to be resolved request to cout
	std::string urlToResolve{ protocol_host_URL_copy };
	replace(urlToResolve, "/", " ");

	// Prepare the resolving query.			
	boost::shared_ptr<boost::asio::ip::tcp::resolver::query> resolver_query = boost::make_shared<boost::asio::ip::tcp::resolver::query>(mHostName, mPortService);
	boost::system::error_code ec;
	
	for (int i : boost::irange(0, ATTEMPTS))
	{
		//21-9-2020mResolveResults= mProtocolHostUrlResolver.resolve(*resolver_query, ec);
		resolver_iterator iterator_resolve = mProtocolHostUrlResolver.resolve(*resolver_query, ec);/////allam 2020 this is sync resolve because we donot need to do any thing else while resolving the main site DNS

		if (ec.value() == boost::system::errc::errc_t::success)		
		{
			if (iterator_resolve != resolver_iterator())
			{
				for (resolver_iterator i = iterator_resolve;i != resolver_iterator();++i)
				{
					mShPtrVecResolverIterator->push_back(i);////allam 2020 this is member of HTTPService_resolve and is assigned values here then when this function ends the endpoints are already saved in the vector in HTTPService_resolve instance So we do not need to return it from the function at line 87
				}
				mServiceResolveIos.~io_context();
				return;
			}
		}
		else
		{
			BOOST_LOG((*mHTTPService_resolve_LoggingInstance_shared_pointer).mloggerCoutLog) << "Error occured! Error code = " << ec.value() << ". Message: " << ec.message();
		}
	}
	exit(1);
}

std::string HTTPServiceResolve::GetServiceResolveProtocolHostUrl() const
{
	return mServiceResolveProtocolHostUrl;
}
boost::asio::io_service& HTTPServiceResolve::GetServiceReference()
{
	return boost::ref(mServiceResolveIos);
}
Shared_ptr_vec_resolver_iterator HTTPServiceResolve::GetSharedPtrVecResolverIterator() const
{
	return mShPtrVecResolverIterator;
}

const std::string& HTTPServiceResolve::mHostNameGet() const
{
	return mHostName;

}
const std::string& HTTPServiceResolve::mPortServiceGet() const
{
	return mPortService;

}

boost::shared_ptr<LoggingClass_2> HTTPServiceResolve::mHTTPService_resolve_LoggingInstance_shared_pointerGet()
{
	//5-17-2020 shared_from_this
	return mHTTPService_resolve_LoggingInstance_shared_pointer;

}
