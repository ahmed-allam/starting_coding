#include "my_logger_class_single_map.h"

void LoggingClass_2::Build_MUS_Folders(Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_FX_inst_US_D_FD_FDS_)
{

	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS & FX_inst_US_D_FD_FDS_index = Log_file_Dur_Sig_F_Map.get<FX_inst_US_D_FD_FDS>();
	//2`3-4
	for (auto it_mMUS_Map = mMUS_Map.begin(); it_mMUS_Map != mMUS_Map.end(); ++it_mMUS_Map)
	{
		std::string MUS = it_mMUS_Map->right;
		//make modifiedUniqueSignal folderNames which are the combination of modifiedUniqueSignal and folderDurationSpecefiedName
		std::string FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName{ it_FX_inst_US_D_FD_FDS_->FolderDurationSpecefied + "_" + it_mMUS_Map->right + it_FX_inst_US_D_FD_FDS_->UniqueSignal };// dereference()	};

		//make the folder itself by init_path
		path logFolderDurationSpecefiedUniqueSignalModifiedUniqueSignalFolderPath = init_path(it_FX_inst_US_D_FD_FDS_->FolderDurationSpecefiedUniqueSignalPathString + "/" + FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName);
		//4-27-2020 this is inside Build_MUS_Folders case 1 after making MUS folder
		//std::cout << "this is inside Build_MUS_Folders case 1 after making MUS folder and before adding this data to struct containing data about folder structure" << "\n";
		//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_, std::cout << arg1 << "\n");

		if (it_FX_inst_US_D_FD_FDS_->ModifiedUniqueSignal == "")//case 1
		{
			assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_, change_MUS(MUS)));

			assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_, change_MUSCUS(MUS + it_FX_inst_US_D_FD_FDS_->UniqueSignal)));

			assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_, change_FDSMUSCUS(FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName)));

			assert(FX_inst_US_D_FD_FDS_index.modify(it_FX_inst_US_D_FD_FDS_, change_FDSMUSCUSPS(logFolderDurationSpecefiedUniqueSignalModifiedUniqueSignalFolderPath.generic_string())));
			//4-27-2020 this is inside Build_MUS_Folders case 1 after adding data of MUS folders to struct containing data about folder structure
			//std::cout << "this is inside Build_MUS_Folders case 1 after adding data of MUS folders to struct containing data about folder structure" << "\n";
			//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_, std::cout << arg1 << "\n");

		}

		else if (it_FX_inst_US_D_FD_FDS_->ModifiedUniqueSignal != "")//case 2
		{
			//4-30-2020 here i have error because when i enter Build_MUS_Folders with iterator pointing to new struct copied from previous US struct ,with this new struct had changed its US field to new US but not its other fields including MUS so we must treat it as case 1 and modify this struct for its first MUS  not making new struct then make other  new structs >>>>>so i think i will just delete MUS field making it empty in ModifyUniqueSignal when i copy previous US struct to make the first new US struct then when it enter  Build_MUS_Folders it will just be with MUS=="" so it is treated as case 1 >>>>this is correct because here in Build_MUS_Folders in case 1 i change MUS from "" to MUS so on next iteration of it_mMUS_Map here in Build_MUS_Folders i will enter case 2 and continue my work to create new structs for the other MUSs left

			//4-30-2020 i think i used it_FX_inst_US_D_FD_FDS_->ModifiedUniqueSignal != "" as a flag to show if to modify struct or make new struct.i think this is based on fact of forlooping in ModifyUniqueSignal using upperbound to just get one struct for each duration
			//4-27-2020 this is inside Build_MUS_Folders case 2 after making MUS folder and before adding this data to struct containing data about folder structure
			//std::cout << "this is inside Build_MUS_Folders case 2 after making MUS folder and before adding this data to newly made struct containing data about folder structure" << "\n";
			//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_, std::cout << arg1 << "\n");

			Log_file_Dur_Sig_F_Map_struct new_struct{ *it_FX_inst_US_D_FD_FDS_ };
			change_MUS(MUS).operator()(new_struct);
			change_MUSCUS(MUS + it_FX_inst_US_D_FD_FDS_->UniqueSignal).operator()(new_struct);
			change_FDSMUSCUS(FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalFolderName).operator()(new_struct);
			change_FDSMUSCUSPS(logFolderDurationSpecefiedUniqueSignalModifiedUniqueSignalFolderPath.generic_string()).operator()(new_struct);

			bool successful_insert = false;
			Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator it_FX_inst_US_D_FD_FDS_new;
			boost::tie(it_FX_inst_US_D_FD_FDS_new, successful_insert) = FX_inst_US_D_FD_FDS_index.insert(new_struct);////,FolderDuration,FolderDurationSpecefied));
			//here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
			assert(successful_insert);
			//4-27-2020 the following fusion show the modified it_FX_inst_US_D_FD_FDS_ not the new it_FX_inst_US_D_FD_FDS_new which is unneeded repetition
			//4-27-2020 this is inside Build_MUS_Folders case 2 after making MUS folder and after adding this data to newly made struct containing data about folder structure
			//std::cout << "this is inside Build_MUS_Folders case 2 after making MUS folder and after adding this data to newly made struct containing data about folder structure" << "\n";
			//4-27-2020 the following fusion show the modified it_FX_inst_US_D_FD_FDS_ not the new it_FX_inst_US_D_FD_FDS_new which is unneeded repetition
			//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_, std::cout << arg1 << "\n");
			//boost::fusion::for_each(*it_FX_inst_US_D_FD_FDS_new, std::cout << arg1 << "\n");

		}
	}
}
