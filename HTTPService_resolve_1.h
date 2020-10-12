#ifndef HTTPServiceResolve_H
#define HTTPServiceResolve_H

#include "boost_asio_http_coroutine_class_multiple_threads.h"
#include "my_logger_class_single_map.h"

using resolver_iterator = boost::asio::ip::tcp::resolver::iterator;
using resolver_iterator_vec = std::vector<resolver_iterator>;
using Shared_ptr_vec_resolver_iterator = boost::shared_ptr<resolver_iterator_vec>;

class HTTPServiceResolve
{
	//friend class HTTPRequest;

public:
	HTTPServiceResolve(boost::shared_ptr<LoggingClass_2>);
	HTTPServiceResolve(std::string, boost::shared_ptr<LoggingClass_2>);

	void ResolveFunc();
	void ResolveFunc(std::string);

	boost::asio::io_service& GetServiceReference();
	std::string GetServiceResolveProtocolHostUrl() const;
	Shared_ptr_vec_resolver_iterator GetSharedPtrVecResolverIterator() const;
	const std::string& mHostNameGet() const;
	const std::string& mPortServiceGet() const;
	boost::shared_ptr<LoggingClass_2> mHTTPService_resolve_LoggingInstance_shared_pointerGet();
private:
	boost::asio::io_service mServiceResolveIos;
	std::string mServiceResolveProtocolHostUrl;

	std::string mHostName;
	std::string	mPortService;
	boost::asio::ip::tcp::resolver mProtocolHostUrlResolver{ mServiceResolveIos };

	Shared_ptr_vec_resolver_iterator mShPtrVecResolverIterator{boost::make_shared<resolver_iterator_vec>()};
	boost::shared_ptr<LoggingClass_2> mHTTPService_resolve_LoggingInstance_shared_pointer;
	bool replace(std::string& , const std::string&, const std::string& );

	//20-9-2020 removing resolver_iterator_vec
	//21-9-2020boost::asio::ip::tcp::resolver::results_type mResolveResults;

};

#endif // !HTTPServiceResolve_H

/*
src::channel_logger_mt<> lg0_first_date_with_404{ keywords::channel = "0" };
src::channel_logger_mt<> lg1_first_date_with_200{ keywords::channel = "1" };
src::channel_logger_mt<> lg2_dates_with_zero_size_after_first_date_with_200{ keywords::channel = "2" };
src::channel_logger_mt<> lg3_dates_of_saturday_and_sunday_after_first_date_with_200{ keywords::channel = "3" };
src::channel_logger_mt<> lg4_dates_not_saturday_or_sunday_after_first_date_with_200_having_zero_size{ keywords::channel = "4" };
src::channel_logger_mt<> lg5_dates_not_saturday_or_sunday_after_first_date_with_200_having_400{ keywords::channel = "5" };
src::channel_logger_mt<> lg6_last_date_recieved_and_written_to_file{ keywords::channel = "6" };
*/
