//#include "stdafx.h"
#include "utils_dst.h"


date find_sunday(date::year_type year, date::month_type month, date::day_type position_of_sunday_in_weeks)
{
	date start = date(year, month, 1);
	date_duration onedaymDay_delta = date_duration(1);
	int counter = 0;
	//const char * Sunday = "Sunday";
	//std::string Sunday{"Sunday"};
	//std::cout << counter << start << std::endl;
	
	while (1)
	{
		//auto c = (start.day_of_week().as_long_string());
		if (boost::lexical_cast<std::string>(start.day_of_week().as_long_string()) == "Sunday")
		{
			//std::cout << start.day_of_week().as_long_string() << std::endl;

			counter += 1;
		}

		if (counter == position_of_sunday_in_weeks)
		{
			return start;
		}

		start += onedaymDay_delta;
		//std::cout << start.day_of_week().as_long_string() << std::endl;

	}

}

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

date find_dst_begin(date::year_type year)
{
	//"DST starts the second sunday of March"
	date start_dst = find_sunday(year, 3, 2);
	return start_dst;
}


/*
def find_dst_begin(year):
"""
DST starts the second sunday of March
"""
return find_sunday(year, 3, 2)
*/

date find_dst_end(date::year_type year)
{
	//"DST ends the first sunday of November"
	date end_dst = find_sunday(year, 11, 1);
	return end_dst;
}

/*
def find_dst_end(year):
"""
DST ends the first sunday of November
"""
return find_sunday(year, 11, 1)
*/

bool is_dst_x(date day)
{
	date day_in_dst = day;

	if (day >= find_dst_begin(day.year()) && day < find_dst_end(day.year()))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

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
//.reset(new boost::asio::io_service::work(mIos));

//DATETIME_FORMAT->set_iso_extended_format();
//DATETIME_FORMAT->format("%Y-%m-%d %H:%M:%S.%f");
//std::locale::global(std::locale(std::locale(), DATETIME_FORMAT));
//for csv work
#include <memory>
std::string stringify(ptime timestamp)
{
	//std::unique_ptr<time_input_facet> DATETIME_FORMAT(new time_input_facet("%Y-%m-%d %H:%M:%S.%f"));
	time_input_facet *DATETIME_FORMAT = new time_input_facet("%Y-%m-%d %H:%M:%S.%f");
	std::locale::global(std::locale(std::locale(), DATETIME_FORMAT));

	std::string str_timestamp = to_simple_string(timestamp);
	return str_timestamp;
}

/*
def stringify(timestamp):
return str(datetime.fromtimestamp(timestamp))
*/
