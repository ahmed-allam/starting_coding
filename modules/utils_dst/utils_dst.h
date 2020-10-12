#ifndef UTILS_DST_H
#define UTILS_DST_H
//#pragma once
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp> //include all types plus i/o
#include <string>
#include <iostream>
#include <locale>
#include <boost/lexical_cast.hpp>

//using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;

date find_sunday(date::year_type, date::month_type, date::day_type);
	
/*
def find_sunday(year, month, position):
    start = date(year, month, 1)
    day_delta = timedelta(days=1)
    counter = 0

    while True:
        if start.isoweekday() == SUNDAY:
            counter += 1
        if counter == position:
            return start
        start += day_delta
*/

date find_dst_begin(date::year_type);

/*
def find_dst_begin(year):
    """
    DST starts the second sunday of March
    """
    return find_sunday(year, 3, 2)
*/

date find_dst_end(date::year_type);

/*
def find_dst_end(year):
    """
    DST ends the first sunday of November
    """
    return find_sunday(year, 11, 1)
*/

bool is_dst_x(date);

/*
def is_dst(day):
    return day >= find_dst_begin(day.year) and day < find_dst_end(day.year)
*/





/*------ - not used in python version------
ptime to_utc_timestamp(string time_str)
{
	return time_from_string(time_str);
}
*/    
/*
def to_utc_timestamp(time_str):
    return time.mktime(from_time_string(time_str).timetuple())
*/
/*------ - not used in python version------
ptime from_time_string(std::string time_str)
{
	

	if (time_str.find('.',0) == NULL)
	{
		time_str += ".0";		
	}
	ptime pt = time_from_string(time_str);
	return pt;
}
*/    
/*
def from_time_string(time_str):
    if '.' not in time_str:
        time_str += '.0'
    return datetime.strptime(time_str, DATETIME_FORMAT)
*/

//for csv work
//DATETIME_FORMAT = "%Y-%m-%d %H:%M:%S.%f"
//#include <memory>
//std::unique_ptr<time_input_facet> DATETIME_FORMAT;

//time_input_facet *DATETIME_FORMAT = new time_input_facet("%Y-%m-%d %H:%M:%S.%f");???????
//DATETIME_FORMAT->set_iso_extended_format();
//DATETIME_FORMAT->format("%Y-%m-%d %H:%M:%S.%f");
//std::locale::global(std::locale(std::locale(), DATETIME_FORMAT));
//for csv work
std::string stringify(ptime);
/*
def stringify(timestamp):
    return str(datetime.fromtimestamp(timestamp))
*/	
#endif // !UTILS_DST_H
