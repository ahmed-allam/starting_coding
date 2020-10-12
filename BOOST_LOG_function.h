////#pragma once
#ifndef BOOST_LOG_function
#define BOOST_LOG_function

#include "my_logger_class_single_map.h"
#include "boost_asio_http_coroutine_class_multiple_threads.h"

void boost_log_function(boost::shared_ptr<LoggingClass_2>, std::string, std::string, std::string , std::string, boost::mutex &);//??logging::formatting_ostream

//4-6-2020 void boost_log_function(boost::shared_ptr<LoggingClass_2>, std::string, std::string, std::ostream);


#endif // !BOOST_LOG_function
