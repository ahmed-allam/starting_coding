//refactoring done

//#pragma once
//#include "../../stdafx.h"

#include "../utils/utils.h"
#include "program_options_2.h"




po::variables_map init_program_options(int argc, char* argv[])
{
	try {
		date_duration single_day(1);
		auto facet = new date_input_facet();
		facet->set_iso_extended_format();
		//facet->format("%Y-%m-%d");
		std::locale::global(std::locale(std::locale(), facet));

		std::vector<symbols_enum> symbols_default ;

		//5-22-2020
		for (std::map<symbols_enum, std::string>::const_iterator it = symbols_enum_to_str_map_x::symbols_enum_to_str_map.begin(); it != symbols_enum_to_str_map_x::symbols_enum_to_str_map.end(); ++it)
		{
			symbols_default.push_back(it->first);
		}
		
		//29-9-2020date day = date(2019, Dec, 31);
		date day = date(2020, Sep, 30);

		std::string prog = "DUKA";

		po::options_description desc(prog + " Allowed options");

		desc.add_options()
			("help", "produce help message")
			("version,v", "outputs Version of program")
			//5-22-2020 day
			("day,d", po::value<date>()->default_value(day), "specific day format YYYY-MM-DD (default today)")//it should be yesterday due to  subtracting single day
			("startdate,s", po::value<date>()->default_value(day), "start date format YYYY-MM-DD (default today>>>yesterday)")

			//("day,d", po::value<date>()->default_value(day_clock::universal_day() - single_day), "specific day format YYYY-MM-DD (default today)")//it should be yesterday due to  subtracting single day
			//("startdate,s", po::value<date>()->default_value(day_clock::universal_day() - single_day), "start date format YYYY-MM-DD (default today>>>yesterday)")
			("enddate,e", po::value<date>()->default_value(day_clock::universal_day() - single_day), "end date format YYYY-MM-DD (default today>>>yesterday)")
			("thread,t", po::value<int>()->default_value(20), "number of threads (default 20)")
			//6-11-2020
			("folder,f", po::value<std::string>()->default_value("default_answer"), "destination folder (default .)")//native()????????//10-9-2020 this default_answer value will be used in boost_create_directory_3.cpp in init_path line36
			//("folder,f", po::value<std::string>()->default_value(path_data_relative.generic_string()), "destination folder (default .)")//native()????????
			//("folder,f", po::value<std::string>()->default_value("default_answer")->notifier					(boost::bind(&check_folder<std::string>, _1, 0, 10)), "destination folder (default depends)")//native()????????
			("candle,c", po::value<timeframe_enum>()->default_value(timeframe_enum::TICK, "TICK"), "use candles instead of ticks. Accepted values TICK M1 M2 M5 M10 M15 M30 H1 H4")
			("header", po::value<bool>()->default_value(false), "include CSV header (default false)")
			("symbols", po::value<std::vector<symbols_enum>>()->multitoken()->composing()->default_value(symbols_default, "GBPJPY"), "symbol list using format EURUSD EURGBP")
			;
		po::positional_options_description pd;
		pd.add("symbols", -1);

		command_line_parser parser{ argc, argv };
		parser.options(desc).positional(pd);
		parsed_options parsed_options = parser.run();

		po::variables_map vm;
		po::store(parsed_options, vm);
		po::notify(vm);

		if (vm.count("help")) {
			std::cout << desc << "\n";
			exit (0);
		}

		if (vm.count("version")) {
			std::cout << VERSION << "\n";
			exit (0);
		}

		if (vm.count("day")) {
			std::cout << "day set to "
				<< vm["day"].as<date>() << ".\n";

		}
		else {
			std::cout << "day was not set.\n";
		}

		if (vm.count("startdate")) {
			std::cout << "startdate set to "
				<< vm["startdate"].as<date>() << ".\n";

		}
		else {
			std::cout << "startdate was not set.\n";
		}

		if (vm.count("enddate")) {
			std::cout << "enddate set to "
				<< vm["enddate"].as<date>() << ".\n";

		}
		else {
			std::cout << "enddate was not set.\n";
		}

		if (vm.count("thread")) {
			std::cout << "thread set to "
				<< vm["thread"].as<int>() << ".\n";

		}
		else {
			std::cout << "thread was not set.\n";
		}

		if (vm.count("folder")) {
			std::cout << "folder set to "
				<< vm["folder"].as<std::string>() << ".\n";

		}
		else {
			std::cout << "folder was not set.\n";
		}

		if (vm.count("candle")) {
			std::cout << "candle set to "
				<< vm["candle"].as<timeframe_enum>() << ".\n";

		}
		else {
			std::cout << "candle level was not set.\n";
		}



		if (vm.count("header")) {
			std::cout << "header set to "
				<< vm["header"].as<bool>() << ".\n";

		}
		else {
			std::cout << "header was not set.\n";
		}

		if (vm.count("symbols")) {
			std::cout << "symbols set to "
				<< vm["symbols"].as<std::vector<symbols_enum>>() << ".\n";

		}
		else {
			std::cout << "symbols was not set.\n";
		}
		return vm;
	}
	catch (std::exception& e) {
		std::cerr << "error: " << e.what() << "\n";
		exit (1);
	}
	catch (...) {
		std::cerr << "Exception of unknown type!\n";
	}

}
