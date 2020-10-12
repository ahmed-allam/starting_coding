#pragma once
#include <map>
#include <string>


using namespace std;

class search_arg_map // Standard way of defining the class
{
public:
	// This means that all of the functions below this(and any variables)
	//  are accessible to the rest of the program.
	//  NOTE: That is a colon, NOT a semicolon...
	search_arg_map(int argc_c1,char *argv_c1[]);	// Constructor
	~search_arg_map();  // destructor

private:
	map<int, string> search_string_map;


};