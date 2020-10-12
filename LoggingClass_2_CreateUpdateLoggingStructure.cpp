#include "my_logger_class_single_map.h"
#include <boost/thread.hpp>



void LoggingClass_2::CreateUpdateLoggingStructure(std::string FX_inst, std::string UniqueSignal, std::string UniqueSignalValue)
{
	//4-26-2020std::system("cls");
	//make RCF_ items clear
	//make index and get range having RCF_
	//using iterator clear RCF_ items to ""
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_MUS & FX_inst_US_MUS_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US_MUS>();

	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_MUS::iterator it_FX_inst_US_MUS_0, it_FX_inst_US_MUS_1;
	boost::tie(it_FX_inst_US_MUS_0, it_FX_inst_US_MUS_1) = FX_inst_US_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalResponseOfCertainValueForFirstTime));
	//5-7-2020 remove cout lines
	/*
	std::cout << FX_inst_US_MUS_index.size() << std::endl;
	*/
	////////////////
	//4-30-2020 the following line has iterator name which must be modified
	for (auto it_FX_inst_US_USvalue_D_MUS_update0 = FX_inst_US_MUS_index.begin(); it_FX_inst_US_USvalue_D_MUS_update0 != FX_inst_US_MUS_index.end(); ++it_FX_inst_US_USvalue_D_MUS_update0)
	{
		//5-7-2020 remove cout lines
		/*
		boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_update0, std::cout << arg1 << "\n");
		*/
	}
	//////////////
	if (it_FX_inst_US_MUS_0 != it_FX_inst_US_MUS_1)//4-27-2020 this is repeated at line 533
	{
		//4-27-2020 this is inside CreateUpdateLoggingStructure after getting structs with RCF MUS
		//4-30-2020////std::cout << "this is inside CreateUpdateLoggingStructure after getting structs with RCF MUS" << "\n";
		//4-30-2020////boost::fusion::for_each(*it_FX_inst_US_MUS_0, std::cout << arg1 << "\n");
	}
	if (it_FX_inst_US_MUS_0 == it_FX_inst_US_MUS_1)
	{
		//error happens because there is no such US in the folder system so look at Modify_Unique_Signal
		throw;
	}
	else if (it_FX_inst_US_MUS_0 != it_FX_inst_US_MUS_1)
	{
		for (auto it_FX_inst_US_MUS_update = it_FX_inst_US_MUS_0; it_FX_inst_US_MUS_update != it_FX_inst_US_MUS_1;)
		{
			if (it_FX_inst_US_MUS_update->BackendName != "")
			{
				//21-9-2020
				boost::fusion::for_each(*it_FX_inst_US_MUS_update, std::cout << arg1 << "\n");
				// Flush all log records that may have left buffered
				it_FX_inst_US_MUS_update->FrontendSharedPointer->flush();

				it_FX_inst_US_MUS_update->FrontendSharedPointer->locked_backend()->rotate_file();
				it_FX_inst_US_MUS_update->FrontendSharedPointer->reset_filter();
				it_FX_inst_US_MUS_update->FrontendSharedPointer->reset_formatter();
				it_FX_inst_US_MUS_update->FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(
					keywords::target = ""));//< the target directory >

				// Remove the sink from the core, so that no records are passed to it
				std::cout <<  boost::this_thread::get_id()<<"it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() << '\n';
				std::cout << boost::this_thread::get_id()<< "it_FX_inst_US_MUS_update->BackendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->BackendSharedPointer.use_count() << '\n';

				core->remove_sink(it_FX_inst_US_MUS_update->FrontendSharedPointer);

				std::cout <<  boost::this_thread::get_id()<<"it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() << '\n';
				std::cout << boost::this_thread::get_id()<< "it_FX_inst_US_MUS_update->BackendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->BackendSharedPointer.use_count() << '\n';

				std::cout << boost::this_thread::get_id()<< "it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() << '\n';



				if (it_FX_inst_US_MUS_update->FrontendSharedPointer.unique() == true)
				{
					assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_FSP_reset(it_FX_inst_US_MUS_update->FrontendSharedPointer)));
					std::cout << boost::this_thread::get_id()<< "it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() << '\n';
				}
				else if (it_FX_inst_US_MUS_update->FrontendSharedPointer.unique() != true)
				{
					std::cout <<  boost::this_thread::get_id()<<"it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->FrontendSharedPointer.use_count() << '\n';

					boost::fusion::for_each(*it_FX_inst_US_MUS_update, std::cout << arg1 << "\n");

					throw;

				}
				if (it_FX_inst_US_MUS_update->BackendSharedPointer.unique() == true)
				{
					assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_BSP_reset(it_FX_inst_US_MUS_update->BackendSharedPointer)));
				}
				else if (it_FX_inst_US_MUS_update->BackendSharedPointer.unique() != true)
				{
					std::cout << boost::this_thread::get_id()<< "it_FX_inst_US_MUS_update->BackendSharedPointer.use_count() == " << it_FX_inst_US_MUS_update->BackendSharedPointer.use_count() << '\n';
					throw;
				}
				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_LCN("")));

				//the next line might be changed so that channel=ModifiedUniqueSignalCertainUniqueSignal with AR_,ARF_,RCF_ and channel=ModifiedUniqueSignalCertainUniqueSignalCertainValue with ARS_
				if (it_FX_inst_US_MUS_update->loggerChannelSharedPointer.unique() == true)
				{
					assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_LCSP_reset(it_FX_inst_US_MUS_update->loggerChannelSharedPointer)));
				}
				else if (it_FX_inst_US_MUS_update->loggerChannelSharedPointer.unique() != true)
				{
					throw;
				}


				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_USvalue("")));
				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_BName("")));
				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_BFName("")));
				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_BFNamePS("")));
				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_BFNamePS_parent("")));
				assert(FX_inst_US_MUS_index.modify(it_FX_inst_US_MUS_update, change_FName("")));

				++it_FX_inst_US_MUS_update;
			}
			else if (it_FX_inst_US_MUS_update->BackendName == "")
			{
				//this happens at begin of program for example
				++it_FX_inst_US_MUS_update;
			}

		}
	}

	//4-27-2020std::system("cls");
	BOOST_LOG(this->mloggerCoutLog) << boost::this_thread::get_id() << " \n after CreateUpdateLoggingStructure line 807 " << FX_inst << "\t" << UniqueSignalValue << "\n";

	vector_new_structs.clear();
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS_BName & FX_inst_US_D_FD_FDS_MUS_BName_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US_D_FD_FDS_MUS_BName>();
	//2-2
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS_BName::iterator it_FX_inst_US_D_FD_FDS_MUS_BName_0, it_FX_inst_US_D_FD_FDS_MUS_BName_1;

	//1
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS & FX_inst_US_D_FD_FDS_MUS_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US_D_FD_FDS_MUS>();
	//2-2
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS::iterator it_FX_inst_US_D_FD_FDS_MUS_0 , it_FX_inst_US_D_FD_FDS_MUS_1, it_FX_inst_US_D_FD_FDS_MUS_update_original;
	boost::tie(it_FX_inst_US_D_FD_FDS_MUS_0, it_FX_inst_US_D_FD_FDS_MUS_1) = FX_inst_US_D_FD_FDS_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal));
	//////bool RCF_BAN{ false };
	//////bool ARF_BAN{ false };
	if (it_FX_inst_US_D_FD_FDS_MUS_0 == it_FX_inst_US_D_FD_FDS_MUS_1)
	{
		//error happens because there is no such US in the folder system so look at Modify_Unique_Signal
		throw;
	}
	else if (it_FX_inst_US_D_FD_FDS_MUS_0 != it_FX_inst_US_D_FD_FDS_MUS_1)
	{
		//5-7-2020 remove cout lines
		/*
		auto itx = it_FX_inst_US_D_FD_FDS_MUS_1;
		std::advance(itx, -1);
		*/
		//3
		for (auto it_FX_inst_US_D_FD_FDS_MUS_update = it_FX_inst_US_D_FD_FDS_MUS_0; it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1;)
		{
			//5-7-2020 remove cout lines
			/*
			std::cout << "\n" << std::endl;
			boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
			std::cout << FX_inst_US_D_FD_FDS_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
			boost::fusion::for_each(*itx, std::cout << arg1 << "\n");
			*/

			std::string ModifiedUniqueSignal{ "" };
			std::string ModifiedUniqueSignalCertainUniqueSignal{ "" };
			std::string ModifiedUniqueSignalCertainUniqueSignalCertainValue{ "" };
			ModifiedUniqueSignal = it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal;
			ModifiedUniqueSignalCertainUniqueSignal = it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignalCertainUniqueSignal;
			//will we need struct for each US value
			ModifiedUniqueSignalCertainUniqueSignalCertainValue = ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue;

			std::string FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal{ "" };
			std::string FolderDurationSpecefiedUniqueSignal{ "" };
			std::string FolderDurationSpecefied{ "" };
			std::string Duration{ "" };
			FolderDurationSpecefied = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied;
			FolderDurationSpecefiedUniqueSignal = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefiedUniqueSignal;
			FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal;
			Duration = it_FX_inst_US_D_FD_FDS_MUS_update->Duration;

			//here we wanna make rule to identify when to use ModifiedUniqueSignal value
			//BackendName = Duration + ModifiedUniqueSignalCertainUniqueSignal +- CertainUniqueSignalValue
			//make Backend requirements for testing then building
			std::string BackendName{ "" };
			std::string BackendFileName{ "" };
			std::string BackendFileNamePathString{ "" };
			std::string BackendFileNamePathString_parent{ "" };

			if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
			{
				BackendName = "backend_" + Duration + "_" + ModifiedUniqueSignalCertainUniqueSignal;
				//4-28-2020BackendFileName = "bF_" + FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal + ".log";
				BackendFileName = FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal + ".log";
				//4-26-2020
				BackendFileNamePathString_parent = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString;
				 BackendFileNamePathString = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString + "/" + BackendFileName;
				/*
				if (BackendFileNamePathString_parent.find("//?/") != BackendFileNamePathString_parent.npos)
				{
					//std::size_t pos = path.find("//?/");
					//std::string path_long = path.substr(pos + 4);
					replace(BackendFileNamePathString_parent, "//?/", "\\\\?\\");

				}
				if (BackendFileNamePathString.find("//?/") != BackendFileNamePathString.npos)
				{
					//std::size_t pos = path.find("//?/");
					//std::string path_long = path.substr(pos + 4);
					replace(BackendFileNamePathString, "//?/", "\\\\?\\");

				}
				*/
			}

			else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")//mLogBackendNameModifiedUniqueSignalCertainUniqueSignal_BannedMap???????????
			{
				BackendName = "backend_" + Duration + "_" + ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue;

				//4-28-2020BackendFileName = "bF_" + FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal + UniqueSignalValue + ".log";
				BackendFileName = FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal + UniqueSignalValue + ".log";

				BackendFileNamePathString_parent = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString;
				BackendFileNamePathString = it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString + "/" + BackendFileName;
				//4-26-2020
				/*
				if (BackendFileNamePathString_parent.find("//?/") != BackendFileNamePathString_parent.npos)
				{
					//std::size_t pos = path.find("//?/");
					//std::string path_long = path.substr(pos + 4);
					replace(BackendFileNamePathString_parent, "//?/", "\\\\?\\");

				}
				if (BackendFileNamePathString.find("//?/") != BackendFileNamePathString.npos)
				{
					//std::size_t pos = path.find("//?/");
					//std::string path_long = path.substr(pos + 4);
					replace(BackendFileNamePathString, "//?/", "\\\\?\\");

				}
				*/
			}
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//test the presence of backend in the forbidden list "for RCF_"
			//this should be the begining of the program because it prevents the formation of certain files which might prevent the formation of certain folders.So if done at the begining of program it will save us making the folders and structs then delete them
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////

			//6-2
			RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS & FX_inst_US_USvalue_D_MUS_index = RCF_Ban_Map.get<FX_inst_US_USvalue_D_MUS>();
			//4-29-2020
			////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;

			//6-3
			RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1;

			//6-4
			boost::tie(it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue));

			//5-7-2020 remove cout lines
			/*
			for (auto it_FX_inst_US_USvalue_D_MUS_update0 = it_FX_inst_US_USvalue_D_MUS_0; it_FX_inst_US_USvalue_D_MUS_update0 != it_FX_inst_US_USvalue_D_MUS_1; ++it_FX_inst_US_USvalue_D_MUS_update0)
			{

				std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
				boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_update0, std::cout << arg1 << "\n");

			}
			*/
			//6-5-1
			if (it_FX_inst_US_USvalue_D_MUS_0 == it_FX_inst_US_USvalue_D_MUS_1)
			{
				//there is no US USvalue and this should happen before CreateUpdateloggingStructure is called
				throw;
			}
			//6-5-2
			else if (it_FX_inst_US_USvalue_D_MUS_0 != it_FX_inst_US_USvalue_D_MUS_1)
			{
				//6-5-2-1
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0_0, it_FX_inst_US_USvalue_D_MUS_1_1;
				//6-5-2-2
				boost::tie(it_FX_inst_US_USvalue_D_MUS_0_0, it_FX_inst_US_USvalue_D_MUS_1_1) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration));

				//3
				//5-7-2020 remove cout lines
				/*
				for (auto it_FX_inst_US_USvalue_D_MUS_0_0_update3 = it_FX_inst_US_USvalue_D_MUS_0_0; it_FX_inst_US_USvalue_D_MUS_0_0_update3 != it_FX_inst_US_USvalue_D_MUS_1_1; ++it_FX_inst_US_USvalue_D_MUS_0_0_update3)
				{
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0_0_update3, std::cout << arg1 << "\n");

				}
				*/
				if (it_FX_inst_US_USvalue_D_MUS_0_0 == it_FX_inst_US_USvalue_D_MUS_1_1)
				{
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;

					//6-5-2-3-1
					if(it_FX_inst_US_USvalue_D_MUS_0->Duration !="")
					{
						//there is no US USvalue for this Duration so add them for this Duration
						//5-7-2020 remove cout lines
						/*
						std::cout << "it_FX_inst_US_USvalue_D_MUS_0 to  be copied to new_struct_r " <<  '\n';
						*/
						//it copies the struct

						RCF_Ban_Map_struct new_struct_r{ *it_FX_inst_US_USvalue_D_MUS_0 };

						change_D_RCF_Ban_Map_struct(Duration).operator()(new_struct_r);
						change_MUS_RCF_Ban_Map_struct("").operator()(new_struct_r);

						bool successful_insert_r = false;
						RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_new;

						boost::tie(it_FX_inst_US_USvalue_D_MUS_new, successful_insert_r) = FX_inst_US_USvalue_D_MUS_index.insert(new_struct_r);////,FolderDuration,FolderDurationSpecefied));
																														 //here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
						assert(successful_insert_r);
						//5-7-2020 remove cout lines
						/*
						if (it_FX_inst_US_USvalue_D_MUS_0 != it_FX_inst_US_USvalue_D_MUS_1)
						{
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0, std::cout << arg1 << "\n");
						}
						*/
						//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_new, std::cout << arg1 << "\n");
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					}
					else if (it_FX_inst_US_USvalue_D_MUS_0->Duration == "")
					{
						//new US value including program beginning
						assert(FX_inst_US_USvalue_D_MUS_index.modify(it_FX_inst_US_USvalue_D_MUS_0, change_D_RCF_Ban_Map_struct(Duration)));
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					}

					//make backend and log
					//during all main for loop iterations both will be false till the current iteration is RCF_ or ARF_ then they will enter the two if at end of iteration code and both will be true in next iteration except inside this if condition which indicate new MUS for the current iteration duration .of the MUS there is RCF_ and ARF_ which then become false to be logged
					//this work fine till new USvalue is found then it will not enter this condition
					//////RCF_BAN = false;
					//////ARF_BAN = false;

					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0, std::cout << arg1 << "\n");
					////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0, std::cout << arg1 << "\n");
				}
				else if (it_FX_inst_US_USvalue_D_MUS_0_0 != it_FX_inst_US_USvalue_D_MUS_1_1)
				{
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;

					//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0, std::cout << arg1 << "\n");
					//the following has error because it prevents making RCF_ log if RCF_ is not the first in order in each duration
					//6-5-2-3-2
					//this US USvalue is registered for this duration
					//do not use this US USvalue with RCF or ARF
					//this is similar to: if (mlogBNMUSCUS_BannedMap.left.find(BackendName) != mlogBNMUSCUS_BannedMap.left.end())
					//if we are in RCF struct or ARF struct then skip this struct

					//we comment next code because it skips ARF_ and RCF_ before their formation
					//this will make problem when day changes
					//i think of adding 4th field to RCFBan to include MUS
					////RCF_ARF_BAN = true;
					//RCF_BAN = true;//??????????????????????????????????????????????????
					//ARF_BAN = true;//???????????????????????????????????????????????????
				}
			}

	//7-1
			if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "ARF_")
			{
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS & FX_inst_US_USvalue_D_MUS_index = RCF_Ban_Map.get<FX_inst_US_USvalue_D_MUS>();
				//6-3
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1;

				//6-4
				boost::tie(it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, allUniqueSignalResponsesForFirstTimeTogether));
				if (it_FX_inst_US_USvalue_D_MUS_0 != it_FX_inst_US_USvalue_D_MUS_1)
				//if (ARF_BAN == true)
				{

					/*
					++it_FX_inst_US_D_FD_FDS_MUS_update;//4
					if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
					{
						boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
					}
					*/
					if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous == FolderDurationSpecefied)
					{
						//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_USvalue("USvalue")));//////////////1-17-2020
						it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
						++it_FX_inst_US_D_FD_FDS_MUS_update;//5
						//5-7-2020 remove cout lines
						/*
						if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
						{
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
						}
						if (it_FX_inst_US_D_FD_FDS_MUS_update_original != it_FX_inst_US_D_FD_FDS_MUS_1)
						{
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update_original, std::cout << arg1 << "\n");
						}
						*/
						////std::cout << "\n ARF_BAN1 == true" << std::endl;

						continue;//skip to next for iteration if we are in same duration VVVIP
								 //i shall make sure that skip will prevent logging of value in RCF or ARF ways
								 //i will make Backend items and Frontend and Logger items in struct empty for RCF and i will keep them for ARF_
								 //this should be made either here OR after making log in previous day>>>>>>>>>>>>>>i shall make it after logging>>>this happens at begining of CreateUpdateLoggingStructure

					}
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous != FolderDurationSpecefied)
					{
						//continue;//skip to next for iteration if we are in same duration VVVIP
								 //i shall make sure that skip will prevent logging of value in RCF or ARF ways
								 //i will make Backend items and Frontend and Logger items in struct empty for RCF and i will keep them for ARF_
								 //this should be made either here OR after making log in previous day>>>>>>>>>>>>>>i shall make it after logging
						////std::cout << "\n ARF_BAN2 == true and we changed duration so we need to rotate file" << std::endl;
						{
							if(it_FX_inst_US_D_FD_FDS_MUS_update->UniqueSignalvalue != "")//1-12-2020??????
							{
								// Break the feeding loop
								////it_FX_inst_US_MUS_update->FrontendSharedPointer->stop();

								// Flush all log records that may have left buffered
								it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->flush();

								if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "RCF_")
								{
									//it_FX_inst_US_MUS_update->FrontendSharedPointer->reset_filter();//????????????ARS_
									throw;//should not come here....if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName)
								}
								//else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
								////else if (it_FX_inst_US_MUS_update->ModifiedUniqueSignal == "RCF_")
								{
									//it_FX_inst_US_MUS_update->FrontendSharedPointer->locked_backend()->close_file();
									try
									{
										////std::cout << "second rotate:line 868" << "\n";
										it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->rotate_file();//???????
									}
									catch (const boost::filesystem::filesystem_error& e)
									{
										std::cout << e.what() << '\n';
									}

									it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->reset_filter();
									it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->reset_formatter();

									it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(
										keywords::target = ""));//< the target directory >

								}
								// Remove the sink from the core, so that no records are passed to it
								core->remove_sink(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer);


								if (it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer.unique() == true)
								{
									assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FSP_reset(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer)));

								}
								else if (it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer.unique() != true)
								{
									boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");

									throw;
								}
								if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.unique() == true)
								{
									//it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.get();
									assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BSP_reset(it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer)));

								}
								else if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.unique() != true)
								{
									throw;

								}


								if (it_FX_inst_US_D_FD_FDS_MUS_update->loggerChannelSharedPointer.unique() == true)
								{
									assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP_reset(it_FX_inst_US_D_FD_FDS_MUS_update->loggerChannelSharedPointer)));
								}
								else if (it_FX_inst_US_D_FD_FDS_MUS_update->loggerChannelSharedPointer.unique() != true)
								{
									throw;
								}


								//1-12-2020???????assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FolderDurationSpecefied_previous(FolderDurationSpecefied)));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_USvalue("")));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BName("")));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFName("")));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS("")));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS_parent("")));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCN("")));

								assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FName("")));

							}
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
							it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
							++it_FX_inst_US_D_FD_FDS_MUS_update;//5
							//5-7-2020 remove cout lines
							/*
							std::cout << "\n ++it_FX_inst_US_D_FD_FDS_MUS_update " << std::endl;

							if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
							{
								//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
							}
							if (it_FX_inst_US_D_FD_FDS_MUS_update_original != it_FX_inst_US_D_FD_FDS_MUS_1)
							{
								//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update_original, std::cout << arg1 << "\n");
							}
							*/
							////std::cout << "\n ARF_BAN == true" << std::endl;
							continue;//skip to next for iteration if we are in same duration VVVIP
									 //i shall make sure that skip will prevent logging of value in RCF or ARF ways
									 //i will make Backend items and Frontend and Logger items in struct empty for RCF and i will keep them for ARF_
									 //this should be made either here OR after making log in previous day>>>>>>>>>>>>>>i shall make it after logging

						}
					}
				}
				//7-1-2
				else if (it_FX_inst_US_USvalue_D_MUS_0 == it_FX_inst_US_USvalue_D_MUS_1)
				//else if (ARF_BAN == false)
				{
					//make logs because we are having new US USvalue
					////std::cout << "\n ARF_BAN == false" << std::endl;
				}
			}
			else if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "RCF_")
			{
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS & FX_inst_US_USvalue_D_MUS_index = RCF_Ban_Map.get<FX_inst_US_USvalue_D_MUS>();
				//6-3
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1;

				//6-4
				boost::tie(it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, UniqueSignalResponseOfCertainValueForFirstTime));
				//7-1-1
				//if (RCF_BAN == true)
				if (it_FX_inst_US_USvalue_D_MUS_0 != it_FX_inst_US_USvalue_D_MUS_1)
				{
					++it_FX_inst_US_D_FD_FDS_MUS_update;//4
					//5-7-2020 remove cout lines
					/*
					if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
					{
						//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
					}
					*/
					continue;//skip to next for iteration
					//i shall make sure that skip will prevent logging of value in RCF or ARF ways
					//i will make Backend items and Frontend and Logger items in struct empty for RCF and i will keep them for ARF_
					//this should be made either here OR after making log in previous day>>>>>>>>>>>>>>i shall make it after logging
				}
				//7-1-2
				//else if (RCF_BAN == false)
				else if(it_FX_inst_US_USvalue_D_MUS_0 == it_FX_inst_US_USvalue_D_MUS_1)
				{
					//make logs because we are having new US USvalue
					////std::cout << "\n RCF_BAN == false" << std::endl;
				}
			}
			//7-2
			else if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal != "RCF_" && it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal != "ARF_")
			{
				//make logs because ban list is not imporatant for other MUS
				////std::cout << "\n != \"RCF_\" && != \"ARF_\" " << std::endl;
			}

			//8
			//12-27-2019 now we go to create back end
			//here we need to modify struct OR copy struct to add new struct

			std::string FrontendName = "Frontend_" + BackendName;
			//create logger with UniqueSignal as channel
			std::string loggerChannelName{ "" };
			if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
			{
				loggerChannelName = "loggerChannel_" + ModifiedUniqueSignalCertainUniqueSignal;
			}
			else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
			{
				loggerChannelName = "loggerChannel_" + ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue;
			}

			//4-28-2020////std::cout << FX_inst_US_D_FD_FDS_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
			//5-7-2020 remove cout lines
			/*
			if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
			{

				boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
			}
			*/
			//the following means it is either the begining of program and BackendName is still empty OR we are updating previous struct which also has 2 options: either we are updating struct for previous USvalue which has changed in same duration OR we are updating struct of previous duration after duration has changed

			//test for change of duration
			////std::cout << "\n /////////////////////////////////////////////////////////////////////////////"<<it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous << std::endl;

			if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous == FolderDurationSpecefied)//case 1
			{
				//////we are in same duration????????????????????????????????
				//4-30-2020????????????????????????????? this happens with new USvalue in same US OR with new US ?????
				//5-1-2020 no ,i will make BackendName empty in ModifyUniqueSignal when it manipulates new US
				//1
				if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName)//case 1
				{
					//?????? with RCF_??????this happens with new USvalue with RCF which is being emptied at begin of CreateUpdateLoggingStructure "old USvalue is already skipped"  but we did not empty FolderDurationSpecefied_previous so it got here . OR
					//with new US when its BackendName is emptied in ModifyUniqueSignal>>>>this is wrong because we emptied FolderDurationSpecefied_previous in ModifyUniqueSignal so it will not get here but get to if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous != FolderDurationSpecefied)
					//1-1
					if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName == "")
					{
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_USvalue(UniqueSignalValue)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BName(BackendName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFName(BackendFileName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS(BackendFileNamePathString)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS_parent(BackendFileNamePathString_parent)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BSP(boost::make_shared< sinks::text_file_backend >(keywords::file_name = BackendFileNamePathString, keywords::open_mode = std::ios_base::out | std::ios_base::app))));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FName(FrontendName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FSP(boost::make_shared<file_sink>(it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer))));

						//5-2-2020
						/*
						if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
						{
							it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal);
						}
						*/
						//else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
						if (ModifiedUniqueSignal == "RCF_")
						{
							//5-2-2020 make sure we are in RCF
							it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue);
						}

						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_formatter(fmt);

						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(
							keywords::target = BackendFileNamePathString_parent));//< the target directory >

						core->add_sink(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer);

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCN(loggerChannelName)));

						//the next line might be changed so that channel=ModifiedUniqueSignalCertainUniqueSignal with AR_,ARF_,RCF_ and channel=ModifiedUniqueSignalCertainUniqueSignalCertainValue with ARS_
						//5-2-2020
						/*
						if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
						{
							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignal))));
						}
						*/
						//else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
						if ( ModifiedUniqueSignal == "RCF_")
						{
							//5-2-2020 make sure we are in RCF
							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignalCertainValue))));
						}

						it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
						++it_FX_inst_US_D_FD_FDS_MUS_update;//5
					}

					//this happens with ARS_>>>>//4-30-2020 OR with new US ?????5-2-2020 no it does not happen  with new US because new US will have FolderDurationSpecefied_previous empty so it will go to else if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous != FolderDurationSpecefied) and treated as program begin
					//the question is:is it new US value OR new US???????i think i will need to add new field to log struct named previous US which is set in ModifyUniqueSignal when making new structs for new US>>>>>5-1-2020 no ,i will make BackendName empty in ModifyUniqueSignal so that it enters  1-1 at line1115>>>>>5-2-2020 no i made FolderDurationSpecefied_previous empty so it will go to else if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous != FolderDurationSpecefied) and treated as program begin
					//1-2
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != "")
					{
						//confirm that current MUS is ARS_
						if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal != "ARS_")
						{
							throw;//this happen before RCF_ made empty
						}
						else if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "ARS_")
						{
							//ARS_ new .it must be the only choice because we are in same duration with MUS ==ARS_ with (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName) where BackendName contains USvalue so USvalue must be different
							//1-2-1
							if (FX_inst_US_D_FD_FDS_MUS_BName_index.find(boost::make_tuple(FX_inst,UniqueSignal, it_FX_inst_US_D_FD_FDS_MUS_update->Duration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDuration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied, it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal, BackendName)) == FX_inst_US_D_FD_FDS_MUS_BName_index.end())
							{
								//5-7-2020 remove cout lines
								/*
								if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
								{
									boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
								}
								*/
								////std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update to  be copied to new_struct.BackendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.use_count() << '\n';
								//it copies the struct including BSP FSP LCSP
								Log_file_Dur_Sig_F_Map_struct new_struct{ *it_FX_inst_US_D_FD_FDS_MUS_update };
								////std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update to  be copied to new_struct.BackendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.use_count() << '\n';
								////std::cout << "new_struct.BackendSharedPointer.use_count() == " << new_struct.BackendSharedPointer.use_count() << '\n';
								change_BName(BackendName).operator()(new_struct);
								change_BFName(BackendFileName).operator()(new_struct);
								change_BFNamePS(BackendFileNamePathString).operator()(new_struct);
								change_BFNamePS_parent(BackendFileNamePathString_parent).operator()(new_struct);
								change_USvalue(UniqueSignalValue).operator()(new_struct);
								//5-2-2020 struct is copied from another struct which has FolderDurationSpecefied_previous==FolderDurationSpecefied >>>so that we got here through if (FolderDurationSpecefied_previous == FolderDurationSpecefied)
								//change_FolderDurationSpecefied_previous(FolderDurationSpecefied).operator()(new_struct);
								change_BSP(boost::make_shared< sinks::text_file_backend >(keywords::file_name = BackendFileNamePathString, keywords::open_mode = std::ios_base::out | std::ios_base::app)).operator()(new_struct);
								////std::cout << "new_struct.BackendSharedPointer.use_count() == " << new_struct.BackendSharedPointer.use_count() << '\n';
								////std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update to  be copied to new_struct.BackendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.use_count() << '\n';
								change_LCN(loggerChannelName).operator()(new_struct);
								change_FName(FrontendName).operator()(new_struct);
								change_FSP(boost::make_shared<file_sink>(new_struct.BackendSharedPointer)).operator()(new_struct);

								new_struct.FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue);


								new_struct.FrontendSharedPointer->set_formatter(fmt);
								new_struct.FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(keywords::target = BackendFileNamePathString_parent));//< the target directory >
								//////init_file_collecting_path(new_struct.FrontendSharedPointer, BackendFileNamePathString_parent);

								core->add_sink(new_struct.FrontendSharedPointer);

								change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignalCertainValue)).operator()(new_struct);

								bool successful_insert = false;
								Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS::iterator it_FX_inst_US_D_FD_FDS_MUS_new;

								boost::tie(it_FX_inst_US_D_FD_FDS_MUS_new, successful_insert) = FX_inst_US_D_FD_FDS_MUS_index.insert(new_struct);////,FolderDuration,FolderDurationSpecefied));
																																 //here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
								assert(successful_insert);
								//5-7-2020 remove cout lines
								/*
								if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
								{
									boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
								}
								boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_new, std::cout << arg1 << "\n");
								std::cout << FX_inst_US_D_FD_FDS_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
								*/
								//1-2-1-3
								//we need to add new struct pointer"reference is forbidden in vector because reference is unassignable" to new structs vector
								vector_new_structs.push_back(&(*it_FX_inst_US_D_FD_FDS_MUS_new));
								it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
								++it_FX_inst_US_D_FD_FDS_MUS_update;//4
								//5-7-2020 remove cout lines
								/*
								if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
								{
									boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
								}
								*/
								while (std::find(vector_new_structs.begin(), vector_new_structs.end(), &(*it_FX_inst_US_D_FD_FDS_MUS_update)) != vector_new_structs.end())
								{
									//5-1-2020 this is place of error with 2 USvalues in same single first US.mostly it is due to invalid iterator looking to end and is being dereferenced.the following increment makes iterator invalid with yearly which is last in order in multiindex container but here it is well guarded with if condition with end iterator .so the error must be after line 1250 end if>>>>>>>>the error happens in while statement when we try to dereference invalid end iterator so i will get out of while just after the following if in the else if condition

									/* v contains x */
									++it_FX_inst_US_D_FD_FDS_MUS_update;//3

									if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
									{
										//5-7-2020 remove cout lines
										/*
										boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
										*/
									}

									else if (it_FX_inst_US_D_FD_FDS_MUS_update == it_FX_inst_US_D_FD_FDS_MUS_1)
									{
										break;
									}
									////continue;//this is put to avoid entering ARF_ OR RCF_ loops at end of for loop in case next ++it_FX_inst_US_D_FD_FDS_MUS_update is ARF_ OR RCF_
								}
								//VVVVVVVVVVVV................IIIIIIIIIIII..........PPPPPPPPPPP
								//5-4-2020 i will comment the next line because i use it_FX_inst_US_D_FD_FDS_MUS_update_original to test ARF RCF at end ot for loop
								////continue;//this is put to avoid entering ARF_ OR RCF_ loops at end of for loop at end of file in case next ++it_FX_inst_US_D_FD_FDS_MUS_update is ARF_ OR RCF_
								//no importance for continue and no harm of changing ARF_ or RCF_ at end file for loop because on next iteration they become false again before being effective
							}
							//ARS_ already present
							//1-2-2
							else if (FX_inst_US_D_FD_FDS_MUS_BName_index.find(boost::make_tuple(FX_inst, UniqueSignal, it_FX_inst_US_D_FD_FDS_MUS_update->Duration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDuration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied, it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal, BackendName)) != FX_inst_US_D_FD_FDS_MUS_BName_index.end())
							{
								///////throw;//this is error because we can not reach here with same ARS_ >>>>>same duration with (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName) >>>no this is not throw because we might be in same duration e.g AllTime with backendname of 01....>>> the error now is backendname="" ?????take care: when day changes construct function changes till backend items then
								//5-2-2020 i think i should throw here
								//5-4-2020 no do not throw because we come here when we have old struct with USvalue which is different thant USvalue passed to CreateUpdateLoggingStructure but in the same time the passed USvalue is not new but registered in another old struct ..this happens with ARS when we  say have old values 00 01 02 and we now are iterating old struct with 01 and USvalue passed to CreateUpdateLoggingStructure is 02 .so 02 is not new but it has different backendname  we do nothing and go to next forloop iteration
								////throw;//5-2-2020 test it???????????
								it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
								++it_FX_inst_US_D_FD_FDS_MUS_update;//2
								//5-7-2020 remove cout lines
								/*
								if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
								{
									boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
								}
								*/
								////continue;//continue the for loop of structs
							}
						}
					}
				}
				//2
				//4-30-2020 i think the following is related to AR_ and ARF_
				else if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName == BackendName)//case 2
				{
					//4-30-2020 i donot understand the next lines>>>>look at line 1279
					//the following lines explains what happens when in previous iteration i  made new struct and insert it in index with previousfolderdurationspecefied set with current folderdurationspecefied which happens with ARS new  at line 1399
					//5-4-2020 the following is very bad comment
					/*
					//here we compare UniqueSignalValue which has been changed by CreateUpdateLoggingStructure during a "previous" iteration of first value in       for (int hour = 0; hour < 2; hour++) and UniqueSignalValue which is passed  during current iteration of for (int hour = 0; hour < 2; hour++)
					*/
					if (it_FX_inst_US_D_FD_FDS_MUS_update->UniqueSignalvalue == UniqueSignalValue)
					{
						//we are in same duration.we change nothing
						////5-14-2020std::cout <<" we are in same duration.we change nothing" << "\n";
					}
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->UniqueSignalvalue != UniqueSignalValue)
					{
						//this happens with ARF_ with new USvalue so we need to change USvalue
						if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "ARF_" ||  it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "AR_")
						{
							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_USvalue(UniqueSignalValue)));
						}

					}
					it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
					//5-7-2020 remove cout lines
					/*
					if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
					{
						//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
					}
					*/
					++it_FX_inst_US_D_FD_FDS_MUS_update;//1
					//5-7-2020 remove cout lines
					/*
					if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
					{
						boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
					}
					*/
				}
				//5-2-2020 the following lines explains what happens when  i finish manipulating struct with ARS or AR then i increment the for loop iterator so that it points to struct with ARF or RCF .in the past this would have made error because this struct will be with backendname empty fields in case of RCF and bad USvalue in case of ARF ,But i check for RCF and ARF  before i get into next for loop iteration ,which would have made error.this is due to flow control of my design So to avoid entering the last ARF and RCF if conditions at end of for loop with unmade yet to be manipulated in next iteration struct,i made another iterator which keeps value before incrementing and use this other iterator to test ARF and RCF
				//error happens after ++it_FX_inst_US_D_FD_FDS_MUS_update because now it_FX_inst_US_D_FD_FDS_MUS_update point to un made RCF_ OR ARF_ but next if will make them appear done >>>i commented the ARF_ RCF_ if conditions at end of main for loop>>>i uncommented the ARF_ RCF_ if conditions at end of main for loop and i used  it_FX_inst_US_D_FD_FDS_MUS_update_original which points to it_FX_inst_US_D_FD_FDS_MUS_update before ++
			}
			else if (it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous != FolderDurationSpecefied)//case 1
			{
				//////we are in different duration????????????????????????????????including program begin
				//5-1-2020 now i am in different duration so we should be in old struct which needs to rotate its files due to change of duration
				//1
				if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName)//case 1
				{
					//5-1-2020 now i am in different duration with backendname different than backendname of current log with the new duration so we should be in old struct which needs to rotate its files due to change of duration>>>backendname is not affected by duration with AR or ARF >>>>>but with RCF backendname becomes "" and with ARS USvalue changes backendname >>>here i use duration in USvalue in f_aru_ARS US which makes backendname different>>>>>
					//A roman:1,2,3,5
					//begining of program and?????? with RCF_?????? old RCF_ already skipped ,now we have only new RCF_
					//1-1
					if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName == "")
					{
						std::cout << it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied_previous << std::endl;

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FolderDurationSpecefied_previous(FolderDurationSpecefied)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_USvalue(UniqueSignalValue)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BName(BackendName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFName(BackendFileName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS(BackendFileNamePathString)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS_parent(BackendFileNamePathString_parent)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BSP(boost::make_shared< sinks::text_file_backend >(keywords::file_name = BackendFileNamePathString, keywords::open_mode = std::ios_base::out | std::ios_base::app))));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FName(FrontendName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FSP(boost::make_shared<file_sink>(it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer))));

						if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
						{
							it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal);//????????????ARS_
						}
						else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
						{
							it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue);
						}

						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_formatter(fmt);


						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(
							keywords::target = BackendFileNamePathString_parent));//< the target directory >

						core->add_sink(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer);

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCN(loggerChannelName)));

						//5-2-2020 why the next lines???
						//the next line might be changed so that channel=ModifiedUniqueSignalCertainUniqueSignal with AR_,ARF_,RCF_ and channel=ModifiedUniqueSignalCertainUniqueSignalCertainValue with ARS_
						if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
						{
							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignal))));

						}
						else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
						{
							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignalCertainValue))));

						}

						it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
						++it_FX_inst_US_D_FD_FDS_MUS_update;//5
					}
					//5-2-2020 the next else if happens with any struct of previous duration having different USvalue"the Duration and MUS are taken from the previous struct so they must be equivalent" than current USvalue passed to CreateUpdateLoggingStructure and this affects only ARS .So the next else if occur with regard to ARS when the previous struct USvalue is different than current fresh USvalue"take care:this does not mean the current fresh USvalue is new,it might be present in another old struct..
					//5-4-2020 the next else if treat ARS with new US value only ,same US value should throw
					//roman:6-1
					//B
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != "")
					{
						//5-1-2020 now i am in different duration with backendname different than backendname of current log with the new duration so we should be in old struct which needs to rotate its files due to change of duration >>>>from line 1406 i here deal with ARS which need to rotate its files
						//i will not rotate files now and delay this till same USvalue come again leading to same backendname with ARS >>>>>>>
						//take care if you will not rotate files then you can not modify its struct and you have to make new struct
						//ARS_ new . new duration with (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName)
						//1-2-1

						if (FX_inst_US_D_FD_FDS_MUS_BName_index.find(boost::make_tuple(FX_inst, UniqueSignal, it_FX_inst_US_D_FD_FDS_MUS_update->Duration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDuration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied, it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal, BackendName)) == FX_inst_US_D_FD_FDS_MUS_BName_index.end())
						{
							//5-7-2020 remove cout lines
							/*
							if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
							{
								boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
							}
							*/
							Log_file_Dur_Sig_F_Map_struct new_struct{ *it_FX_inst_US_D_FD_FDS_MUS_update };

							change_BName(BackendName).operator()(new_struct);
							change_BFName(BackendFileName).operator()(new_struct);
							change_BFNamePS(BackendFileNamePathString).operator()(new_struct);
							change_BFNamePS_parent(BackendFileNamePathString_parent).operator()(new_struct);
							change_USvalue(UniqueSignalValue).operator()(new_struct);
							//5-1-2020 i removed comment of next line
							change_FolderDurationSpecefied_previous(FolderDurationSpecefied).operator()(new_struct);

							//?????????????????5-6-2020
							//5-7-2020 remove cout lines
							/*
							std::cout << "new_struct.BackendSharedPointer.use_count() == " << new_struct.BackendSharedPointer.use_count() << '\n';
							*/
							change_BSP(boost::make_shared< sinks::text_file_backend >(keywords::file_name = BackendFileNamePathString, keywords::open_mode = std::ios_base::out | std::ios_base::app)).operator()(new_struct);
							//5-7-2020 remove cout lines
							/*
							std::cout << "new_struct.BackendSharedPointer.use_count() == " << new_struct.BackendSharedPointer.use_count() << '\n';
							*/
							change_LCN(loggerChannelName).operator()(new_struct);
							change_FName(FrontendName).operator()(new_struct);
							change_FSP(boost::make_shared<file_sink>(new_struct.BackendSharedPointer)).operator()(new_struct);
							//5-7-2020 remove cout lines
							/*
							std::cout << "new_struct.BackendSharedPointer.use_count() == " << new_struct.BackendSharedPointer.use_count() << '\n';
							*/
							new_struct.FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue);


							new_struct.FrontendSharedPointer->set_formatter(fmt);
							new_struct.FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(keywords::target = BackendFileNamePathString_parent));//< the target directory >
																																													 //////init_file_collecting_path(new_struct.FrontendSharedPointer, BackendFileNamePathString_parent);

							core->add_sink(new_struct.FrontendSharedPointer);
							//5-7-2020 remove cout lines
							/*
							std::cout << "new_struct.BackendSharedPointer.use_count() == " << new_struct.BackendSharedPointer.use_count() << '\n';
							*/
							change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignalCertainValue)).operator()(new_struct);

							bool successful_insert = false;
							Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS::iterator it_FX_inst_US_D_FD_FDS_MUS_new;

							boost::tie(it_FX_inst_US_D_FD_FDS_MUS_new, successful_insert) = FX_inst_US_D_FD_FDS_MUS_index.insert(new_struct);////,FolderDuration,FolderDurationSpecefied));
																															 //here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
							assert(successful_insert);
							//5-7-2020 remove cout lines
							/*
							if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
							{
								boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
							}
							boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_new, std::cout << arg1 << "\n");
							*/
							//1-2-1-3
							//we need to add new struct pointer"reference is forbidden in vector because reference is unassignable" to new structs vector
							vector_new_structs.push_back(&(*it_FX_inst_US_D_FD_FDS_MUS_new));
							it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
							++it_FX_inst_US_D_FD_FDS_MUS_update;//4
							//5-7-2020 remove cout lines
							/*
							if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
							{
								boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
							}
							*/
							while (std::find(vector_new_structs.begin(), vector_new_structs.end(), &(*it_FX_inst_US_D_FD_FDS_MUS_update)) != vector_new_structs.end())
							{
								/* v contains x */
								++it_FX_inst_US_D_FD_FDS_MUS_update;//3
								if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
								{
									//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
								}
								else if (it_FX_inst_US_D_FD_FDS_MUS_update == it_FX_inst_US_D_FD_FDS_MUS_1)
								{
									break;
								}
								////continue;//this is put to avoid entering ARF_ OR RCF_ loops at end of for loop in case next ++it_FX_inst_US_D_FD_FDS_MUS_update is ARF_ OR RCF_
							}
							//VVVVVVVVVVVV................IIIIIIIIIIII..........PPPPPPPPPPP
							//5-4-2020 i will comment the next line because i use it_FX_inst_US_D_FD_FDS_MUS_update_original to test ARF RCF at end ot for loop
							////continue;//this is put to avoid entering ARF_ OR RCF_ loops at end of for loop at end of file in case next ++it_FX_inst_US_D_FD_FDS_MUS_update is ARF_ OR RCF_
							//5-4-2020 the next lines are so imporatant ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
							//no importance for continue and no harm of changing ARF_ or RCF_ at end file for loop because on next iteration they become false again before being effective
						}

						//AR_ ARS_ ARF_ have same back end name as previous duration But With ARS_ we might get ARS_ already present
						//5-2-2020 because we got here when backendname!=backendname so we can exclude AR or ARF.So we are in ARS with already present USvalue in another struct >>>i will wait till i iterate to old struct with this USvalue then rotate file there"this happens when backendname==backendname
						//5-4-2020 the previous lines are wrong.i should not get ARS already present here because its backendname ==backendname so in next if i should throw>>>>>no i should not throw but i should do nothing
						//ARS_ already present
						//1-2-2
						//5-4-2020 roman:2-6-2
						else if (FX_inst_US_D_FD_FDS_MUS_BName_index.find(boost::make_tuple(FX_inst, UniqueSignal, it_FX_inst_US_D_FD_FDS_MUS_update->Duration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDuration, it_FX_inst_US_D_FD_FDS_MUS_update->FolderDurationSpecefied, it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal, BackendName)) != FX_inst_US_D_FD_FDS_MUS_BName_index.end())
						{

							{
								//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
								it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
								++it_FX_inst_US_D_FD_FDS_MUS_update;//5
								////std::cout << "\n ++it_FX_inst_US_D_FD_FDS_MUS_update line1481 already present ARS_ but different USvalue with different duration " << std::endl;
								//5-7-2020 remove cout lines

							}//???????????>>>>>>>>>>>>>>>>>>>>>>>>>>>>??????????????5-1-2020
						}
						//5-1-2020 this is code to rotate files of previous duration
						//i need to rotate previous files

					}
				}
				else if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName == BackendName)//case 1
				{
					//5-1-2020 note that this happens with AR and ARF also note that i changed previousfolderdurationspecefied in new struct and modified struct of ARS to equal current folderdurationspecefied>>>>>will this affect AR ARF???????????????? i donot think so because this will make FDS_previous==FDS so it will not get here
					//AR_ ARS_ ARF_ have same back end name as previous duration
					//5-1-2020 here the struct with ARS of the new duration is rentered??????why????????
					//i need to rotate previous files

						// Flush all log records that may have left buffered
					it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->flush();

					if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "RCF_")
					{
						throw;//should not come here....if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendName != BackendName)
					}

					try
					{
						//5-1-2020 big error as this is not the previous struct ???????????????? i need to rotate previous duration struct file with same backend name as current struct "with regard to ARS"
						//i think i should not rotate file here and wait till i iterate to struct of previous duration with same ARS backendname>>>no this is place of rotating file and modifying struct

						////std::cout << "third rotate:line 1433" << "\n";
						//5-7-2020 remove cout lines
						/*
						if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
						{
							boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
						}
						*/
						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->rotate_file();//???????
					}
					catch (const boost::filesystem::filesystem_error& e)
					{
						std::cout << e.what() << '\n';
					}

					it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->reset_filter();
					it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->reset_formatter();

					it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(
						keywords::target = ""));//< the target directory >



				// Remove the sink from the core, so that no records are passed to it
					core->remove_sink(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer);

					if (it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer.unique() == true)
					{
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FSP_reset(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer)));

					}
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer.unique() != true)
					{
						boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");

						throw;
					}
					if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.unique() == true)
					{
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BSP_reset(it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer)));

					}
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.unique() != true)
					{
						throw;
					}


					if (it_FX_inst_US_D_FD_FDS_MUS_update->loggerChannelSharedPointer.unique() == true)
					{
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP_reset(it_FX_inst_US_D_FD_FDS_MUS_update->loggerChannelSharedPointer)));
					}
					else if (it_FX_inst_US_D_FD_FDS_MUS_update->loggerChannelSharedPointer.unique() != true)
					{
						throw;
					}

					//1-12-2020the following code works well when no new USvalue is introduced at begining of new duration But if new duration with new USvalue then we will miss it with else if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal == "ARF_") so we need to make if condition to test new US value >>>thus we transfer code to ARFBAN = true

					//if (it_FX_inst_US_D_FD_FDS_MUS_update->ModifiedUniqueSignal != "ARF_")
					{
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FolderDurationSpecefied_previous(FolderDurationSpecefied)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_USvalue(UniqueSignalValue)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BName(BackendName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFName(BackendFileName)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS(BackendFileNamePathString)));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BFNamePS_parent(BackendFileNamePathString_parent)));
						//5-7-2020
						//assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BSP(boost::make_shared< sinks::text_file_backend >(keywords::file_name = BackendFileNamePathString))));//, keywords::open_mode = std::ios_base::out | std::ios_base::app))));
						//std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update.BackendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.use_count() << '\n';

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_BSP(boost::make_shared< sinks::text_file_backend >(keywords::file_name = BackendFileNamePathString, keywords::open_mode = std::ios_base::out | std::ios_base::app))));

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FName(FrontendName)));
						//std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update.BackendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.use_count() << '\n';
						//std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update.FrontendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer.use_count() << '\n';
						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_FSP(boost::make_shared<file_sink>(it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer))));
						//std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update.BackendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->BackendSharedPointer.use_count() << '\n';
						//std::cout << "it_FX_inst_US_D_FD_FDS_MUS_update.FrontendSharedPointer.use_count() == " << it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer.use_count() << '\n';

						if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
						{
							it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal);//????????????ARS_
						}
						else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
						{
							//////1-11-2020throw;//????????????
							it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_filter(expr::attr< std::string >("Channel") == ModifiedUniqueSignalCertainUniqueSignal + "_" + UniqueSignalValue);
						}

						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->set_formatter(fmt);

						//////init_file_collecting_path(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer, BackendFileNamePathString_parent);
						it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer->locked_backend()->set_file_collector(sinks::file::make_collector(
							keywords::target = BackendFileNamePathString_parent));//< the target directory >

						core->add_sink(it_FX_inst_US_D_FD_FDS_MUS_update->FrontendSharedPointer);

						assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCN(loggerChannelName)));

						//the next line might be changed so that channel=ModifiedUniqueSignalCertainUniqueSignal with AR_,ARF_,RCF_ and channel=ModifiedUniqueSignalCertainUniqueSignalCertainValue with ARS_
						if (ModifiedUniqueSignal == "AR_" || ModifiedUniqueSignal == "ARF_")
						{

							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignal))));

						}
						else if (ModifiedUniqueSignal == "ARS_" || ModifiedUniqueSignal == "RCF_")
						{
							//////1-11-2020throw;//???????????????????

							assert(FX_inst_US_D_FD_FDS_MUS_index.modify(it_FX_inst_US_D_FD_FDS_MUS_update, change_LCSP(boost::make_shared<src::channel_logger_mt<>>(keywords::channel = ModifiedUniqueSignalCertainUniqueSignalCertainValue))));

						}


						//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
						it_FX_inst_US_D_FD_FDS_MUS_update_original = it_FX_inst_US_D_FD_FDS_MUS_update;
						++it_FX_inst_US_D_FD_FDS_MUS_update;//5
						////std::cout << "\n ++it_FX_inst_US_D_FD_FDS_MUS_update " << std::endl;
						//5-7-2020 remove cout lines
						/*
						if (it_FX_inst_US_D_FD_FDS_MUS_update != it_FX_inst_US_D_FD_FDS_MUS_1)
						{
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update, std::cout << arg1 << "\n");
						}
						if (it_FX_inst_US_D_FD_FDS_MUS_update_original != it_FX_inst_US_D_FD_FDS_MUS_1)
						{
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_MUS_update_original, std::cout << arg1 << "\n");
						}
						*/
					}
				}
			}

			if (it_FX_inst_US_D_FD_FDS_MUS_update_original->ModifiedUniqueSignal == "ARF_")
			{
				//////ARF_BAN = true;
				//
				//6-3
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0_x, it_FX_inst_US_USvalue_D_MUS_1_x;

				//6-4
				boost::tie(it_FX_inst_US_USvalue_D_MUS_0_x, it_FX_inst_US_USvalue_D_MUS_1_x) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration));

				auto it_FX_inst_US_USvalue_D_MUS_update = it_FX_inst_US_USvalue_D_MUS_0_x;
				//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
				//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0_x, std::cout << arg1 << "\n");

				for (auto it_FX_inst_US_USvalue_D_MUS_update0_x = it_FX_inst_US_USvalue_D_MUS_0_x; it_FX_inst_US_USvalue_D_MUS_update0_x != it_FX_inst_US_USvalue_D_MUS_1_x; ++it_FX_inst_US_USvalue_D_MUS_update0_x)
				{
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_update0_x, std::cout << arg1 << "\n");

				}

				//6-5-1
				if (it_FX_inst_US_USvalue_D_MUS_0_x == it_FX_inst_US_USvalue_D_MUS_1_x)
				{
					//there is no US USvalue duration and this should happen before logging at //7
					throw;
				}
				//6-5-2
				else if (it_FX_inst_US_USvalue_D_MUS_0_x != it_FX_inst_US_USvalue_D_MUS_1_x)
				{
					RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS & FX_inst_US_USvalue_D_MUS_index = RCF_Ban_Map.get<FX_inst_US_USvalue_D_MUS>();
					//6-3
					RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1;

					//6-4
					boost::tie(it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, allUniqueSignalResponsesForFirstTimeTogether));
					auto it_FX_inst_US_USvalue_D_MUS_update_20 = it_FX_inst_US_USvalue_D_MUS_0;
					if (it_FX_inst_US_USvalue_D_MUS_0 == it_FX_inst_US_USvalue_D_MUS_1)
					{
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, allUniqueSignalResponsesForFirstTimeTogether)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;

						if (it_FX_inst_US_USvalue_D_MUS_0_x->ModifiedUniqueSignal != "")
						{
							//there is no ARF_ for this US USvalue Duration so add them for this Duration but there might be RCF_
							////std::cout << "it_FX_inst_US_USvalue_D_MUS_update to  be copied to new_struct_r " << '\n';
							//it copies the struct

							RCF_Ban_Map_struct new_struct_r{ *it_FX_inst_US_USvalue_D_MUS_0_x };

							change_MUS_RCF_Ban_Map_struct(allUniqueSignalResponsesForFirstTimeTogether).operator()(new_struct_r);
							bool successful_insert_r = false;
							RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_new;

							boost::tie(it_FX_inst_US_USvalue_D_MUS_new, successful_insert_r) = FX_inst_US_USvalue_D_MUS_index.insert(new_struct_r);////,FolderDuration,FolderDurationSpecefied));
																																   //here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
							assert(successful_insert_r);

							if (it_FX_inst_US_USvalue_D_MUS_update_20 != it_FX_inst_US_USvalue_D_MUS_1)
							{
								//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0_x, std::cout << arg1 << "\n");
							}

							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_new, std::cout << arg1 << "\n");
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, allUniqueSignalResponsesForFirstTimeTogether)) << std::endl;
						}
						else if (it_FX_inst_US_USvalue_D_MUS_0_x->ModifiedUniqueSignal == "")
						{
							//new US value including program beginning
							assert(FX_inst_US_USvalue_D_MUS_index.modify(it_FX_inst_US_USvalue_D_MUS_0_x, change_MUS_RCF_Ban_Map_struct(ModifiedUniqueSignal)));
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, allUniqueSignalResponsesForFirstTimeTogether)) << std::endl;
						}
					}
					else if (it_FX_inst_US_USvalue_D_MUS_0 != it_FX_inst_US_USvalue_D_MUS_1)
					{
						//it is registerd against ARF_ so do nothing
					}
				}
			}
			if (it_FX_inst_US_D_FD_FDS_MUS_update_original->ModifiedUniqueSignal == "RCF_")
			{
				//////"RCF_"BAN = true;
				//
				//6-3
				RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0_x, it_FX_inst_US_USvalue_D_MUS_1_x;

				//6-4
				boost::tie(it_FX_inst_US_USvalue_D_MUS_0_x, it_FX_inst_US_USvalue_D_MUS_1_x) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration));

				auto it_FX_inst_US_USvalue_D_MUS_update = it_FX_inst_US_USvalue_D_MUS_0_x;
				//4-28-2020////std::cout << US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
				//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0_x, std::cout << arg1 << "\n");

				for (auto it_FX_inst_US_USvalue_D_MUS_update0_x = it_FX_inst_US_USvalue_D_MUS_0_x; it_FX_inst_US_USvalue_D_MUS_update0_x != it_FX_inst_US_USvalue_D_MUS_1_x; ++it_FX_inst_US_USvalue_D_MUS_update0_x)
				{
					//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
					//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_update0_x, std::cout << arg1 << "\n");

				}

				//6-5-1
				if (it_FX_inst_US_USvalue_D_MUS_0_x == it_FX_inst_US_USvalue_D_MUS_1_x)
				{
					//there is no US USvalue and this should happen before CreateUpdateloggingStructure is called
					throw;
				}
				//6-5-2
				else if (it_FX_inst_US_USvalue_D_MUS_0_x != it_FX_inst_US_USvalue_D_MUS_1_x)
				{
					RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS & FX_inst_US_USvalue_D_MUS_index = RCF_Ban_Map.get<FX_inst_US_USvalue_D_MUS>();
					//6-3
					RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1;

					//6-4
					boost::tie(it_FX_inst_US_USvalue_D_MUS_0, it_FX_inst_US_USvalue_D_MUS_1) = FX_inst_US_USvalue_D_MUS_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, UniqueSignalResponseOfCertainValueForFirstTime));
					auto it_FX_inst_US_USvalue_D_MUS_update_20 = it_FX_inst_US_USvalue_D_MUS_0;
					if (it_FX_inst_US_USvalue_D_MUS_0 == it_FX_inst_US_USvalue_D_MUS_1)
					{
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, UniqueSignalResponseOfCertainValueForFirstTime)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
						//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;

						if (it_FX_inst_US_USvalue_D_MUS_0_x->ModifiedUniqueSignal != "")
						{
							//there is no ModifiedUniqueSignal for this  US USvalue Duration so add them for this  US USvalue Duration
							////std::cout << "it_FX_inst_US_USvalue_D_MUS_0_x to  be copied to new_struct_r " << '\n';
							//it copies the struct

							RCF_Ban_Map_struct new_struct_r{ *it_FX_inst_US_USvalue_D_MUS_0_x };

							change_MUS_RCF_Ban_Map_struct(UniqueSignalResponseOfCertainValueForFirstTime).operator()(new_struct_r);
							bool successful_insert_r = false;
							RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS::iterator it_FX_inst_US_USvalue_D_MUS_new;

							boost::tie(it_FX_inst_US_USvalue_D_MUS_new, successful_insert_r) = FX_inst_US_USvalue_D_MUS_index.insert(new_struct_r);////,FolderDuration,FolderDurationSpecefied));
																																   //here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
							assert(successful_insert_r);
							//5-7-2020 remove cout lines
							/*
							if (it_FX_inst_US_USvalue_D_MUS_update_20 != it_FX_inst_US_USvalue_D_MUS_1)
							{
								//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_0_x, std::cout << arg1 << "\n");
							}
							*/
							//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_USvalue_D_MUS_new, std::cout << arg1 << "\n");
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration, UniqueSignalResponseOfCertainValueForFirstTime)) << std::endl;
						}
						else if (it_FX_inst_US_USvalue_D_MUS_0_x->ModifiedUniqueSignal == "")
						{
							//new US value including program beginning
							assert(FX_inst_US_USvalue_D_MUS_index.modify(it_FX_inst_US_USvalue_D_MUS_0_x, change_MUS_RCF_Ban_Map_struct(ModifiedUniqueSignal)));
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue, Duration)) << std::endl;
							//4-28-2020////std::cout << FX_inst_US_USvalue_D_MUS_index.count(boost::make_tuple(FX_instUniqueSignal, UniqueSignalValue, Duration, UniqueSignalResponseOfCertainValueForFirstTime)) << std::endl;
						}
					}
					else if (it_FX_inst_US_USvalue_D_MUS_0 != it_FX_inst_US_USvalue_D_MUS_1)
					{
						//it is registerd against RCF_ so do nothing
					}
				}
			}

		}
	}
}

