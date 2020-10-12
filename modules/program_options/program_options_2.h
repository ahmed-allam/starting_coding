#ifndef PROGRAM_OPTIONS_1_H
#define PROGRAM_OPTIONS_1_H

#include <boost/date_time/gregorian/gregorian.hpp> //include all types plus i/o
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
//6-11-2020
#include <boost/bind.hpp>
#include <boost/predef.h>
//#if BOOST_OS_WINDOWS
//	#include <windows.h>//this is to get drives in windows
//#endif

#include "../utils/utils.h"

namespace fs = boost::filesystem;
namespace po = boost::program_options;

using namespace boost::gregorian;

const fs::path path_data_relative("."); // relative path
const std::string  VERSION = "0.2.1";

po::variables_map init_program_options(int,char*[]);

#endif // !PROGRAM_OPTIONS_1_H
