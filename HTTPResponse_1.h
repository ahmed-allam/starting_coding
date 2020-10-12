#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H
//#pragma once
#include "boost_asio_http_coroutine_class_multiple_threads.h"


class HTTPResponse :public boost::enable_shared_from_this<HTTPResponse>//4-8-2020 made in HTTPRequest_1.h at line 90
{
	friend class HTTPRequest;
	//HTTPResponse() ;//allam : both private members

public:
	HTTPResponse();//allam : both private members

	unsigned int get_status_code() const;
	const std::string & get_http_version() const;
	const std::string & get_status_message() const;
	const std::map<std::string, std::string>& get_headers();
	const std::istream & get_response() const;
	//const HTTPResponse& operator=(const HTTPResponse &) const;
	boost::asio::streambuf& get_response_buf();


private:
	//4-5-2020 boost::asio::streambuf& get_response_buf();
	void set_status_code(unsigned int);
	void set_http_version(const std::string&);
	void set_status_message(const std::string&);
	void add_header(const std::string&, const std::string&);
private:
	std::string m_http_version; // HTTP version
	unsigned int m_status_code; // HTTP status code.
	std::string m_status_message; // HTTP status message.

	std::map<std::string, std::string> m_headers;// Response headers.
	boost::asio::streambuf m_response_buf;
	std::istream m_response_stream;
};


#endif // !HTTP_RESPONSE_H

