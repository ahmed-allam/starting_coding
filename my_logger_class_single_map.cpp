
#include "my_logger_class_single_map.h"
#include <boost/thread.hpp>

boost::bimap<set_of<std::string>, set_of<std::string>> LoggingClass_2::mMUS_Map;

LoggingClass_2::LoggingClass_2()
{
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesOfSameValue", allUniqueSignalResponsesOfSameValue));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesTogether", allUniqueSignalResponsesTogether));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesForFirstTimeTogether", allUniqueSignalResponsesForFirstTimeTogether));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("UniqueSignalResponseOfCertainValueForFirstTime", UniqueSignalResponseOfCertainValueForFirstTime));
	
	backendCout->add_stream(boost::shared_ptr< std::ostream >(&std::cout, boost::null_deleter()));
	sink_cout->set_filter(expr::attr<std::string>("Channel") == "m_cout_log");//==
	sink_cout->set_formatter(fmt);
	core->add_sink(sink_cout);	
	
	// And also add some logging core attributes
	core->add_global_attribute("TimeStamp", attrs::local_clock());
	core->add_global_attribute("RecordID", attrs::counter< unsigned int >());

	// Setup the common formatter for all sinks
	fmt = expr::format("[%1%] [%2%]  [%3%]")//[%5%] [%4%]
		% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
		% expr::attr<unsigned int>("RecordID")
		//% expr::attr<unsigned int>("ThreadID")
		//% expr::attr<string>("Scope")
		//% trivial::severity		
		% expr::smessage;

	//:format("\t>%1%</record>")
	/*
	TEMPLATE = '%(asctime)s - %(levelname)s - %(threadName)s [%(thread)d] -  %(message)s'
	*/

	////for (S_Str_S_SPFS_bimap::const_iterator it = mlogFrontNFrontSPMap.begin(); it != mlogFrontNFrontSPMap.end(); ++it)
	////{
	////	it->right->locked_backend()->scan_for_files();		
	////}

}
//5-18-2020
LoggingClass_2::LoggingClass_2(std::string FX_inst)
{
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesOfSameValue", allUniqueSignalResponsesOfSameValue));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesTogether", allUniqueSignalResponsesTogether));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesForFirstTimeTogether", allUniqueSignalResponsesForFirstTimeTogether));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("UniqueSignalResponseOfCertainValueForFirstTime", UniqueSignalResponseOfCertainValueForFirstTime));

	backendCout->add_stream(boost::shared_ptr< std::ostream >(&std::cout, boost::null_deleter()));
	sink_cout->set_filter(expr::attr<std::string>("Channel") == "m_cout_log");//==
	sink_cout->set_formatter(fmt);
	core->add_sink(sink_cout);

	// And also add some logging core attributes
	core->add_global_attribute("TimeStamp", attrs::local_clock());
	core->add_global_attribute("RecordID", attrs::counter< unsigned int >());

	// Setup the common formatter for all sinks
	fmt = expr::format("[%1%] [%2%]  [%3%]")//[%5%] [%4%]
		% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
		% expr::attr<unsigned int>("RecordID")
		//% expr::attr<unsigned int>("ThreadID")
		//% expr::attr<string>("Scope")
		//% trivial::severity		
		% expr::smessage;

	//:format("\t>%1%</record>")
	/*
	TEMPLATE = '%(asctime)s - %(levelname)s - %(threadName)s [%(thread)d] -  %(message)s'
	*/

	////for (S_Str_S_SPFS_bimap::const_iterator it = mlogFrontNFrontSPMap.begin(); it != mlogFrontNFrontSPMap.end(); ++it)
	////{
	////	it->right->locked_backend()->scan_for_files();		
	////}
	/////////m_LoggingClass_2FX_inst = FX_inst;
}

LoggingClass_2::LoggingClass_2(std::string pathFolder, std::string folderBehaviour)
{
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesOfSameValue", allUniqueSignalResponsesOfSameValue));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesTogether", allUniqueSignalResponsesTogether));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("allUniqueSignalResponsesForFirstTimeTogether", allUniqueSignalResponsesForFirstTimeTogether));
	LoggingClass_2::mMUS_Map.left.insert(boost::bimap<set_of<std::string>, set_of<std::string>>::left_value_type("UniqueSignalResponseOfCertainValueForFirstTime", UniqueSignalResponseOfCertainValueForFirstTime));
	
	backendCout->add_stream(boost::shared_ptr< std::ostream >(&std::cout, boost::null_deleter()));
	sink_cout->set_filter(expr::attr<std::string>("Channel") == "m_cout_log");
	sink_cout->set_formatter(fmt);
	core->add_sink(sink_cout);

	// And also add some logging core attributes
	core->add_global_attribute("TimeStamp", attrs::local_clock());
	core->add_global_attribute("RecordID", attrs::counter< unsigned int >());

	// Setup the common formatter for all sinks
	fmt = expr::format("[%1%] [%2%]  [%3%]")//[%5%] [%4%]
		% expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
		//% expr::attr<unsigned int>("ThreadID")
		% expr::attr<unsigned int>("RecordID")
		//% expr::attr<string>("Scope")
		//% trivial::severity		
		% expr::smessage;

	//:format("\t>%1%</record>")
	/*
	TEMPLATE = '%(asctime)s - %(levelname)s - %(threadName)s [%(thread)d] -  %(message)s'
	*/
	
	////for (auto it = mlogFrontNFrontSPMap.begin(); it != mlogFrontNFrontSPMap.end(); ++it)
	////{
	////	it->right->locked_backend()->scan_for_files();		
	////}
}




//mLogModifiedUniqueSignalUpdateBackendsParametersMap???????????????????????????//


Log_file_Dur_Sig_F_Map_struct_set &  LoggingClass_2::Get_Log_file_Dur_Sig_F_Map()
{
	return boost::ref(Log_file_Dur_Sig_F_Map);
}


