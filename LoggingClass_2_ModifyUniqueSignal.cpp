#include "my_logger_class_single_map.h"

void LoggingClass_2::ModifyUniqueSignal(std::string FX_inst,std::string UniqueSignal)
{
	//2`1
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US & FX_inst_US_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US>();
	//2`2
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US::iterator it_FX_inst_US_0, it_FX_inst_US_1;
	boost::tie(it_FX_inst_US_0,it_FX_inst_US_1) = FX_inst_US_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal));
	//2`3
	//test presence of UniqueSignal
	if (it_FX_inst_US_0 == it_FX_inst_US_1)//this means US is not present
	{
		//2`3-1
		//we will make for loop using
		Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS & FX_inst_US_D_FD_FDS_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US_D_FD_FDS>();
		//2`3-2

		//5-22-2020 here i will make specefic range of FX_inst to for loop into
		Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_FX_inst_US_D_FD_FDS_0, it_FX_inst_US_D_FD_FDS_1;
		boost::tie(it_FX_inst_US_D_FD_FDS_0, it_FX_inst_US_D_FD_FDS_1) = FX_inst_US_D_FD_FDS_index.equal_range(boost::make_tuple(FX_inst));

		Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_FX_inst_US_D_FD_FDS_Modify;

		//5-1-2020 i will make the following iterator to use it when i have new US to delete all fields of the copied struct using same technique of iterator."avoiding changing syntax to use new struct class member dot notation"
		Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_new_copy_of_FX_inst_US_D_FD_FDS_Modify_struct;//it will point to struct copied from struct pointed to by it_FX_inst_US_D_FD_FDS_Modify,not copy of it_FX_inst_US_D_FD_FDS_Modify

		//2`3-3
		//this for loop is provided to add US to the struct and FDSUS and FDSUSPS
		for (it_FX_inst_US_D_FD_FDS_Modify = it_FX_inst_US_D_FD_FDS_0; it_FX_inst_US_D_FD_FDS_Modify != it_FX_inst_US_D_FD_FDS_1;)// ++it_FX_inst_US_D_FD_FDS_Modify)

		{
			std::string currentDuration{ it_FX_inst_US_D_FD_FDS_Modify->Duration };
			std::string currentFDS{ it_FX_inst_US_D_FD_FDS_Modify->FolderDurationSpecefied };
			std::string currentFDSPS{ it_FX_inst_US_D_FD_FDS_Modify->FolderDurationSpecefiedPathString };
			std::string currentUS{ it_FX_inst_US_D_FD_FDS_Modify->UniqueSignal };
			//4-27-2020 this is inside ModifyUniqueSignal 2`3-3 before adding US or modifying struct containing data for folder structure
			//std::cout << "this is inside ModifyUniqueSignal 2`3-3 before adding US or modifying struct containing data for folder structure" << "\n";
			//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_Modify, std::cout << arg1 << "\n");

			if (currentUS=="")//case 1
			{
				std::string FolderDurationSpecefiedUniqueSignalFolderName{ currentFDS + "_" + UniqueSignal };
				//make the folder itself by init_path
				path logFolderDurationSpecefiedUniqueSignalFolderPath = init_path(currentFDSPS + "/" + FolderDurationSpecefiedUniqueSignalFolderName);

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_Modify, change_FDSUS(FolderDurationSpecefiedUniqueSignalFolderName)));

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_Modify, change_FDSUSPS(logFolderDurationSpecefiedUniqueSignalFolderPath.generic_string())));

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_Modify, change_UniqueSignal(UniqueSignal)));
				//4-27-2020 this is inside ModifyUniqueSignal  2`3-3 case 1 after making FDSUS folder and modifying struct containing data of folder structure
				//std::cout << "this is inside ModifyUniqueSignal 2`3-3 case 1 after making FDSUS folder and modifying struct containing data of folder structure " << "\n";

				//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_Modify, std::cout << arg1 << "\n");

				//2`3-4
				//i need to make function to build the MUS folders and make 2 overloads of it ,one taking iterator to struct to be used in if condition case 1 and the other taking reference to struct to be used with else if condition case 2>>>i made changes in case 2 to provide iterator like case 1
				Build_MUS_Folders(it_FX_inst_US_D_FD_FDS_Modify);
				//2`3-5
				//this is for loop to show order of structs in container
				//4-27-2020 this is inside ModifyUniqueSignal  2`3-3 case 1 2`3-5 after Build_MUS_Folders
				//std::cout << "this is inside ModifyUniqueSignal 2`3-3 case 1 2`3-5 after Build_MUS_Folders " << "\n";
				//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_Modify, std::cout << arg1 << "\n");

				////i think the following code need revision because if changing US led to rearranging the element before US or after US or same place,what will happen?
				//4-27-2020 upper_bound returns element after its argument value or end if no element present
				////note that in following code we pass currentUS which is tested to be "" So we are jumping to next value with US="" which is the next duration in currentUS
				it_FX_inst_US_D_FD_FDS_Modify = FX_inst_US_D_FD_FDS_index.upper_bound(boost::make_tuple(FX_inst,currentUS, currentDuration, it_FX_inst_US_D_FD_FDS_Modify->FolderDuration, currentFDS));
				//4-27-2020 this is inside ModifyUniqueSignal  2`3-3 case 1 2`3-5 after incrementing iterator it_FX_inst_US_D_FD_FDS_Modify to point to next struct of currentUS
				//std::cout << "this is inside ModifyUniqueSignal  2`3-3 case 1 2`3-5 after incrementing iterator it_FX_inst_US_D_FD_FDS_Modify to point to next struct of currentUS" << "\n";
				//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_Modify, std::cout << arg1 << "\n");

				//2`3-6
				//this code at 81 is effective because it tests the stored US in struct after jumping to struct with next duration  with currentUS which is got from previous struct at begining of this iteration before jumping  to struct with next duration. So if true then the jumped-to struct is of differernt US so we should break because this function is based on using only one US to set up new structs and within this we use only one MUS to modify 1 and create the other 3 and also we jump over other MUS of same duration
				//4-30-2020 potential error :what if the upperbound got us to the end iterator which is invalid iterator??another question is :why do not hit the end iterator with begining of program and do this with new signal???i think because when we are in begining of program ,we change US from empty which is always at begining in order to US with string which is always next in order to empty
				//so after modification of new signal from empty"" to any letter ,when we reach last duration and jump to struct beyond it ,we hit the newly modified struct with US as letters So we never hit the invalid end iterator.
				//But in case we are changing US from letters to other letters ,the previous US"which is initializing currentUS" may have order as letters after the new US so when we jump from last duration of previous US we hit the invalid end iterator>>>>>how can we solve this?????????i will make if condition to exclude the end iterator
				//5-22-2020 changes for multi threaded it_FX_inst_US_D_FD_FDS_1
				//if (it_FX_inst_US_D_FD_FDS_Modify != FX_inst_US_D_FD_FDS_index.end())
				if (it_FX_inst_US_D_FD_FDS_Modify != it_FX_inst_US_D_FD_FDS_1)

				{
					if (it_FX_inst_US_D_FD_FDS_Modify->FX_inst == FX_inst)
					{
						if (it_FX_inst_US_D_FD_FDS_Modify->UniqueSignal != currentUS)
						{
							////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_Modify, std::cout << arg1 << "\n");

							break;
						}
					}
					else if (it_FX_inst_US_D_FD_FDS_Modify->FX_inst != FX_inst)
					{
						break;
					}

				}
				else if (it_FX_inst_US_D_FD_FDS_Modify == it_FX_inst_US_D_FD_FDS_1)
				{
					break;
				}
			}

			else if (currentUS != "")//case 2
			{
				Log_file_Dur_Sig_F_Map_struct new_struct{ *it_FX_inst_US_D_FD_FDS_Modify };
				change_MUS("").operator()(new_struct);
				change_UniqueSignal(UniqueSignal).operator()(new_struct);
				//new_struct.setUS(UniqueSignal);
				std::string FolderDurationSpecefiedUniqueSignalFolderName{ currentFDS + "_" + UniqueSignal };
				//make the folder itself by init_path
				path logFolderDurationSpecefiedUniqueSignalFolderPath = init_path(currentFDSPS + "/" + FolderDurationSpecefiedUniqueSignalFolderName);
				change_FDSUS(FolderDurationSpecefiedUniqueSignalFolderName).operator()(new_struct);
				change_FDSUSPS(logFolderDurationSpecefiedUniqueSignalFolderPath.generic_string()).operator()(new_struct);
				change_BName("").operator()(new_struct);
				change_BFName("").operator()(new_struct);
				change_BFNamePS("").operator()(new_struct);
				change_BFNamePS_parent("").operator()(new_struct);
				change_USvalue("").operator()(new_struct);
				change_FolderDurationSpecefied_previous("").operator()(new_struct);
				change_LCN("").operator()(new_struct);
				change_FName("").operator()(new_struct);
				change_FSP_reset(new_struct.FrontendSharedPointer).operator()(new_struct);
				change_BSP_reset(new_struct.BackendSharedPointer).operator()(new_struct);
				change_LCSP_reset(new_struct.loggerChannelSharedPointer).operator()(new_struct);

				bool successful_insert=false;
				Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_FX_inst_US_D_FD_FDS_new;
				boost::tie(it_FX_inst_US_D_FD_FDS_new, successful_insert) = FX_inst_US_D_FD_FDS_index.insert(new_struct);////,FolderDuration,FolderDurationSpecefied));
				assert(successful_insert);

				//2`3-4
				//i need to make function to build the MUS folders and make 2 overloads of it ,one taking iterator to struct to be used in if condition case 1 and the other taking reference to struct to be used with else if condition case 2>>>i made changes in case 2 to provide iterator like case 1
				Build_MUS_Folders(it_FX_inst_US_D_FD_FDS_new);
				//2`3-5
				it_FX_inst_US_D_FD_FDS_Modify = FX_inst_US_D_FD_FDS_index.upper_bound(boost::make_tuple(FX_inst,currentUS, currentDuration, it_FX_inst_US_D_FD_FDS_Modify->FolderDuration, currentFDS));
				//2`3-6
				//5-22-2020 changes for multi threaded it_FX_inst_US_D_FD_FDS_1
				//if (it_FX_inst_US_D_FD_FDS_Modify != FX_inst_US_D_FD_FDS_index.end())
				if (it_FX_inst_US_D_FD_FDS_Modify != it_FX_inst_US_D_FD_FDS_1)
				//if (it_FX_inst_US_D_FD_FDS_Modify != FX_inst_US_D_FD_FDS_index.end())
				{
					if (it_FX_inst_US_D_FD_FDS_Modify->FX_inst == FX_inst)
					{
						//5-1-2020 i might add more confirmation by testing against UniqueSignal which should be true in the following condition to go to break>>>>now the current iterator is at struct which is not equal to current struct and is not end iterator also ,so it must be struct of new US which is ordered after the previous "used to build new US structs" US structs
						if (it_FX_inst_US_D_FD_FDS_Modify->UniqueSignal != currentUS)
						{
							////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_Modify, std::cout << arg1 << "\n");
							break;
						}
					}
					else if (it_FX_inst_US_D_FD_FDS_Modify->FX_inst != FX_inst)
					{
						break;
					}

				}
				else if (it_FX_inst_US_D_FD_FDS_Modify == it_FX_inst_US_D_FD_FDS_1)
				{
					break;
				}
			}

		}

	}
	//2`4
	else if (it_FX_inst_US_0 != it_FX_inst_US_1)
	{
		//2`4-1
		//we take range of US structs aranged by FX_inst_US_D_FD_FDS
		Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS & FX_inst_US_D_FD_FDS_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US_D_FD_FDS>();
		Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_FX_inst_US_D_FD_FDS_0,it_FX_inst_US_D_FD_FDS_1;
		boost::tie(it_FX_inst_US_D_FD_FDS_0, it_FX_inst_US_D_FD_FDS_1) = FX_inst_US_D_FD_FDS_index.equal_range(boost::make_tuple(it_FX_inst_US_0->FX_inst,it_FX_inst_US_0->UniqueSignal));
		//4-28-2020////std::cout << FX_inst_US_D_FD_FDS_index.count(boost::make_tuple(it_FX_inst_US_0->UniqueSignal)) <<std::endl;
		//the previous line show very bad error happening due to ConstructFolderDurationMaps so we find only 12 structs with US not 16.So i ll remove part in ConstructFolderDurationMaps to keep US in structs >>>>to be tested in _10
		//4-30-2020////auto itx = it_FX_inst_US_D_FD_FDS_1;
		//4-30-2020////std::advance(itx, -1);

		//2`4-2
		//we loop in range of US structs
		for (auto it_FX_inst_US_D_FD_FDS_range = it_FX_inst_US_D_FD_FDS_0; it_FX_inst_US_D_FD_FDS_range != it_FX_inst_US_D_FD_FDS_1;++it_FX_inst_US_D_FD_FDS_range)
		{
			std::string currentDuration{ it_FX_inst_US_D_FD_FDS_range->Duration };
			std::string currentFDS{ it_FX_inst_US_D_FD_FDS_range->FolderDurationSpecefied };
			std::string currentFDSPS{ it_FX_inst_US_D_FD_FDS_range->FolderDurationSpecefiedPathString };
			std::string currentUS{ it_FX_inst_US_D_FD_FDS_range->UniqueSignal };
			std::string currentFDSUS{ it_FX_inst_US_D_FD_FDS_range->FolderDurationSpecefiedUniqueSignal };
			//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_0, std::cout << arg1 << "\n");
			//4-28-2020////boost::fusion::for_each(*itx, std::cout << arg1 << "\n");
			//4-28-2020////boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_range, std::cout << arg1 << "\n");

			//here we compare FDS which has been changed by ConstructFolderDurationMaps and FDSUS which has not been changed
			if (currentFDS + "_" + currentUS== currentFDSUS)
			{
				//5-7-2020 remove cout lines
				/*
				//we are in same duration.we do nothing
				std::cout << "we are in same duration.we do nothing" << "\n";
				*/
			}
			else if (currentFDS + "_" + currentUS != currentFDSUS)
			{
				std::string FolderDurationSpecefiedUniqueSignalFolderName{ currentFDS + "_" + currentUS };
				//make the folder itself by init_path
				path logFolderDurationSpecefiedUniqueSignalFolderPath = init_path(currentFDSPS + "/" + FolderDurationSpecefiedUniqueSignalFolderName);

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_range, change_FDSUS(FolderDurationSpecefiedUniqueSignalFolderName)));

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_range, change_FDSUSPS(logFolderDurationSpecefiedUniqueSignalFolderPath.generic_string())));

				std::string MUS = it_FX_inst_US_D_FD_FDS_range->ModifiedUniqueSignal;
				//make modifiedUniqueSignal folderNames which are the combination of modifiedUniqueSignal and folderDurationSpecefiedName
				std::string FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName{ it_FX_inst_US_D_FD_FDS_range->FolderDurationSpecefied + "_" + MUS + it_FX_inst_US_D_FD_FDS_range->UniqueSignal };// dereference()	};
																														//make the folder itself by init_path
				path logFolderDurationSpecefiedUniqueSignalModifiedUniqueSignalFolderPath = init_path(it_FX_inst_US_D_FD_FDS_range->FolderDurationSpecefiedUniqueSignalPathString + "/" + FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName);

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_range, change_FDSMUSCUS(FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName)));

				assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_range, change_FDSMUSCUSPS(logFolderDurationSpecefiedUniqueSignalModifiedUniqueSignalFolderPath.generic_string())));
				boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_range, std::cout << arg1 << "\n");

			}
		}

	}
}
//CreateFileBackEnd  >>>>>we should make back end for each file in each log folder
/*Very Important:
the following function which will build and update back ends gives me idea of why class is created>>>>>what is object oriented programming??
each ModifiedUniqueSignal has certain behaviour which determines how files will be formed for back ends.
it determines if we will be using the value of ModifiedUniqueSignal in file naming or not
also it determines if the file will rotate only based upon date change or also on the behaviour of the ModifiedUniqueSignaql related to its value
So, i think i should make class for each ModifiedUniqueSignal which describes its behaviour and how to fullfill requirements of previous explained points
But i shall first try to make it as function to avoid the complexity in using many classes related to static maps and making them during run time which will get me to template class arena........OUT OF FEAR

*/
