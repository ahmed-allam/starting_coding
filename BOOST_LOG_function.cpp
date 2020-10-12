//#include "stdafx.h"
#include "BOOST_LOG_function.h"

void boost_log_function(boost::shared_ptr<LoggingClass_2> mLoggingInstance, std::string FX_inst, std::string UniqueSignal, std::string UniqueSignal_value, std::string formatting_ostream_string, boost::mutex & mBOOST_LOGMutex)//??logging::formatting_ostream formatting_ostream
//4-6-2020 void boost_log_function(boost::shared_ptr<LoggingClass_2> mLoggingInstance,std::string FX_inst, std::string UniqueSignal, std::string UniqueSignal_value, std::ostream formatting_ostream)

{
	boost::unique_lock<boost::mutex> BOOST_LOG_lock(mBOOST_LOGMutex);
	BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id()<<" \n inside BOOST_LOG_function "<< FX_inst <<"\t" <<UniqueSignal_value << "\n";

	mLoggingInstance->ModifyUniqueSignal(FX_inst,UniqueSignal);
	BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id() << " \n after ModifyUniqueSignal " << FX_inst << "\t" << UniqueSignal_value << "\n";
	mLoggingInstance->CreateUpdate_RCF_Ban_Map(FX_inst,UniqueSignal, UniqueSignal_value);
	BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id() << " \n after CreateUpdate_RCF_Ban_Map " << FX_inst << "\t" << UniqueSignal_value << "\n";
	mLoggingInstance->CreateUpdateLoggingStructure(FX_inst,UniqueSignal, UniqueSignal_value);
	BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id() << " \n after CreateUpdateLoggingStructure " << FX_inst << "\t" << UniqueSignal_value << "\n";
	//1
	//make LCN index
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_LCN & FX_inst_US_LCN_index = mLoggingInstance->Get_Log_file_Dur_Sig_F_Map().get<FX_inst_US_LCN>();
	//2-2
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_LCN::iterator it_FX_inst_US_LCN_0, it_FX_inst_US_LCN_1, it_FX_inst_US_LCN_update_original;
	boost::tie(it_FX_inst_US_LCN_0, it_FX_inst_US_LCN_1) = FX_inst_US_LCN_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal));

	if (it_FX_inst_US_LCN_0 == it_FX_inst_US_LCN_1)
	{
		//error happens because there is no such US in the folder system so look at Modify_Unique_Signal
		throw;
	}
	else if (it_FX_inst_US_LCN_0 != it_FX_inst_US_LCN_1)
	{
		//5-7-2020 remove cout lines
		/*
		auto itx = it_FX_inst_US_LCN_1;
		std::advance(itx, -1);
		std::cout << "\n" << std::endl;
		std::cout << "boost_log_function" << std::endl;
		boost::fusion::for_each(*it_FX_inst_US_LCN_0, std::cout << arg1 << "\n");
		std::cout << "boost_log_function" << std::endl;
		std::cout << FX_inst_US_LCN_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
		boost::fusion::for_each(*itx, std::cout << arg1 << "\n");
		*/
		//3
		for (auto it_FX_inst_US_LCN_update = it_FX_inst_US_LCN_0; it_FX_inst_US_LCN_update != it_FX_inst_US_LCN_1;)
		{
			//5-7-2020 remove cout lines
			/*
			std::cout << "boost_log_function" << std::endl;
			std::cout << "\n" << std::endl;
			boost::fusion::for_each(*it_FX_inst_US_LCN_update, std::cout << arg1 << "\n");
			std::cout << FX_inst_US_LCN_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
			boost::fusion::for_each(*itx, std::cout << arg1 << "\n");
			*/
			if (it_FX_inst_US_LCN_update->UniqueSignalvalue == UniqueSignal_value)
			{
				/*
				BOOST_LOG((*mLoggingInstance).mloggerCoutLog) << " url_hour logger has registered " << UniqueSignal_value << std::endl;
				BOOST_LOG(*(it_FX_inst_US_LCN_update->loggerChannelSharedPointer)) << " url_hour logger has registered " << UniqueSignal_value;
				*/
				BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id() <<"\t"<< " \n inside BOOST_LOG_function before logging to cout " << FX_inst << "\t" << UniqueSignal_value << "\n";
				BOOST_LOG((*mLoggingInstance).mloggerCoutLog) << boost::this_thread::get_id() << "\t" << formatting_ostream_string << std::endl;
				BOOST_LOG(*(it_FX_inst_US_LCN_update->loggerChannelSharedPointer)) << formatting_ostream_string << UniqueSignal_value;
			}
			BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id() << "\t" << " \n inside BOOST_LOG_function after logging to cout " << FX_inst << "\t" << UniqueSignal_value << "\n";
			////std::cout << it_FX_inst_US_LCN_update->FrontendSharedPointer->locked_backend()->get_current_file_name() << "\n" << std::endl;
			it_FX_inst_US_LCN_update = FX_inst_US_LCN_index.upper_bound(boost::make_tuple(FX_inst,UniqueSignal, it_FX_inst_US_LCN_update->loggerChannelName));

		}
		BOOST_LOG(mLoggingInstance->mloggerCoutLog) << boost::this_thread::get_id() << "\t" << " \n inside BOOST_LOG_function after for loop single iteration " << FX_inst << "\t" << UniqueSignal_value << "\n";
	}
	BOOST_LOG(mLoggingInstance->mloggerCoutLog) <<boost::this_thread::get_id()<< " \n  BOOST_LOG_function finished " << FX_inst << "\t" << UniqueSignal_value << "\n";

	BOOST_LOG_lock.unlock();

}
	
