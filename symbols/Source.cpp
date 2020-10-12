// symbols.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <ctime>

using namespace std;
//"BRENTCMDUSD" = > 0,  // Brent starting from Fri 2017.Jan.27 13:00:00

int main(int argc, char *argv[])
{
	string line;
	ifstream myfile;
	myfile.open("symbols_array.txt");

	ofstream myfile2;
	myfile2.open("symbols_array2.h");

	//string newline, symbol, symbol_value, value_to_date, mapsyntax1;
	int firstpos, secondpos, thirdpos, fourthpos, fifthpos;

	struct tm time_struct;
	time_t posix_int = -1;
	//memset(time_struct, 0, sizeof(tm));
	//char buffer[64];
	size_t y = 64;

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			string newline, symbol, symbol_value, value_to_date, comment_value;
			char posix_str[64];

			getline(myfile, line);
			//std::cout << line.at(0) << endl;
			std::cout << line.length() << endl;
			std::cout << line << endl;
			if (line.empty())
			{
				newline = line;
				std::cout << newline << endl;
			}
			//if ((line.at(0) == (*"#" || *"/" || *" " )) || (line.empty()==true))
			//if ((line.at(0) == *"#" || *"/" || *" ") || (line ==""))
			//if (line.at(0) == *"#" || *"/" || *" ") 
			//else if ((line.at(0) == '#' )|| (line.at(0) == '/' )|| (line.at(0) == ' '))
			else if ((line.find('//', 0) == 0) || (line.find('#', 0) == 0))
			{
				newline = line;
				std::cout << newline << endl;
				std::cout << line.at(0) << endl;

			}
			else if ((line.find_first_of(' ', 0) == 0) || (line.find_first_of('\t', 0) == 0))
			{
				size_t x = line.find_first_not_of(" \t", 0);
				if ((x > 0) && (line.substr(x, 2) == "//"))
				{
					newline = line;
					newline = line.substr(x);

					std::cout << newline << endl;
					std::cout << line.at(0) << endl;

				}
				else if ((x > 0) && (line.substr(x, 1) == "\""))
				{
					firstpos = line.find('"', 0);
					secondpos = line.find('"', (firstpos + 1));
					if (firstpos >= 0 && secondpos >= 0)
					{
						//if (secondpos - firstpos > 1)
						//{
						symbol = line.substr(firstpos + 1, secondpos - firstpos - 1);//1st requirement
						std::cout << symbol << endl;
						//}

					}

					thirdpos = line.find("> ", secondpos);// +2;
					fourthpos = line.find(",", secondpos);// -1;
					if (thirdpos >= 0 && fourthpos >= 0)
					{
						symbol_value = line.substr(thirdpos + 2, fourthpos - thirdpos - 2);//2nd requirement
						std::cout << symbol_value << endl;

						posix_int = stoi(symbol_value);
						std::cout << posix_int << endl;

						gmtime_s(&time_struct, &posix_int);
						std::cout << time_struct.tm_year << endl;

						//char* posix_str = ctime(&posix_int);
						//char* posix_str = strftime(posix_str, sizeof(posix_str), "%A %c", time_struct);
						strftime(posix_str, y, "%A %Y-%m-%d %H:%M:%S", &time_struct);

						std::cout << posix_str << endl;

					}

					fifthpos = line.find("from ", secondpos);
					comment_value = line.substr(fourthpos + 1, fifthpos + 5 - fourthpos - 1);//3rd requirement

					std::cout << comment_value << endl;

					if (fifthpos >= 0)
					{
						value_to_date = line.substr(fifthpos + 5);//4th requirement			
						std::cout << value_to_date << endl;

					}

					//if ((firstpos < secondpos) && (thirdpos != -1 ) && (fourthpos != -1) && (fifthpos != -1))

					//newline = "symbols[\"" + symbol + "\"] = " + symbol_value + ";" + comment_value +	value_to_date;
					newline = "{\"" + symbol + "\", " + symbol_value + "}," + comment_value + posix_str;
					std::cout << newline << endl;

				}
			}
			else
			{
				firstpos = line.find('"', 0);
				secondpos = line.find('"', (firstpos + 1));
				if (firstpos >= 0 && secondpos >= 0)
				{
					//if (secondpos - firstpos > 1)
					//{
					symbol = line.substr(firstpos + 1, secondpos - firstpos - 1);//1st requirement
					std::cout << symbol << endl;
					//}

				}

				thirdpos = line.find("> ", secondpos);// +2;
				fourthpos = line.find(",", secondpos);// -1;
				if (thirdpos >= 0 && fourthpos >= 0)
				{
					symbol_value = line.substr(thirdpos + 2, fourthpos - thirdpos - 2);//2nd requirement
					std::cout << symbol_value << endl;

					posix_int = stoi(symbol_value);
					std::cout << posix_int << endl;

					gmtime_s(&time_struct, &posix_int);
					std::cout << time_struct.tm_year << endl;

					//char* posix_str = ctime(&posix_int);
					//char* posix_str = strftime(posix_str, sizeof(posix_str), "%A %c", time_struct);
					strftime(posix_str, y, "%A %Y-%m-%d %H:%M:%S", &time_struct);

					std::cout << posix_str << endl;

				}

				fifthpos = line.find("from ", secondpos);
				comment_value = line.substr(fourthpos + 1, fifthpos + 5 - fourthpos - 1);//3rd requirement

				std::cout << comment_value << endl;

				if (fifthpos >= 0)
				{
					value_to_date = line.substr(fifthpos + 5);//4th requirement			
					std::cout << value_to_date << endl;

				}

				//if ((firstpos < secondpos) && (thirdpos != -1 ) && (fourthpos != -1) && (fifthpos != -1))
				//if (firstpos==0)
				//{
				//newline = "symbols[\"" + symbol + "\"] = " + symbol_value + ";" + comment_value +value_to_date;
				newline = "{\"" + symbol + "\", " + symbol_value + "}," + comment_value + posix_str;

				std::cout << newline << endl;
				//}
				if ((line == "symbols[\"\"] = ;") || (line == "using namespace std;") || (line == "std::map<string, int> symbols; //Create a map."))

				{
					newline = line;

					std::cout << newline << endl;
				}


				//if (!(firstpos == secondpos == thirdpos == fourthpos == fifthpos==-1))
				//{
				//newline = line;

				//	std::cout << newline << endl;
				//}


				//system("pause");
			}
			if (myfile2.is_open())
			{
				if (myfile2.good())
				{
					myfile2 << newline << endl;
				}
			}
			else
			{
				std::cout << "Unable to open file for write";
			}
		}
	}

	else
	{
		std::cout << "Unable to open file";
	}
	myfile.close();
	myfile2.close();
	return 0;
}
