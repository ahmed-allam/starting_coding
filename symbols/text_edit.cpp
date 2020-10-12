// text_edit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <search_arg_map.h>

using namespace std;
//"BRENTCMDUSD" = > 0,  // Brent starting from Fri 2017.Jan.27 13:00:00

int main(int argc,char *argv[])
{
	string line;
	ifstream myfile("symbols_array.txt");
	ofstream myfile2("symbols_array2.txt");

	search_arg_map(argc, argv);

	string newline,symbol,symbol_value,restofline, mapsyntax1;
	int firstpos, secondpos, thirdpos, fourthpos, fifthpos;

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);

			firstpos =line.find('"', 0);
			secondpos = line.find('"', (firstpos + 1));
			if (firstpos >= 0 && secondpos >= 0)
			{
				symbol = line.substr(firstpos, secondpos);

				thirdpos = line.find("> ", secondpos) + 2;
				fourthpos = line.find(",", secondpos) - 1;

				symbol_value = line.substr(thirdpos, fourthpos);
				restofline = line.substr(fourthpos);

				fifthpos = line.find("from", secondpos) + 5;
			}
			mapsyntax1 = "symbols[" + symbol + "] = " + symbol_value + restofline ;
			newline = mapsyntax1;
			cout << newline<<endl;
			system("pause");
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	return 0;
}