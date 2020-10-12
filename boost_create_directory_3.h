#ifndef BOOST_CREATE_DIRECTORY    // if boost_create_directory.h hasn't been included yet...
#define BOOST_CREATE_DIRECTORY   //   #define this so the compiler knows it has been included

#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
//6-11-2020
#include <boost/predef.h>
#include <unistd.h> // getuid


using namespace boost::filesystem;


extern std::string localpath;
extern boost::filesystem::path abs_localpath;
extern boost::filesystem::path path_log;

std::string& replace(std::string&, const std::string&, const std::string&);

path init_path_Main_begin(std::string,std::string  );//path
path init_path(std::string);//path

std::vector<std::string> GetListOfDrives();

#endif 
