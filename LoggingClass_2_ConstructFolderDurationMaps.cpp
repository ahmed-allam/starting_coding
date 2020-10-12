#include "my_logger_class_single_map.h"

void LoggingClass_2::ConstructFolderDurationMaps(const std::string FX_inst, const std::string FolderDurationSpecefied, std::string const FolderDurationSpecefiedPathString, const std::string Duration, const path FolderDurationSpecefiedPath, boost::mutex& mConstructFolderDurationMapsMutex)//20-9-2020 this mutex is not used inside this function //20-9-2020 Main_mBOOST_LOGMutex of main()
{
	const std::string FolderDuration{ FolderDurationSpecefiedPath.parent_path().filename().generic_string() };
	const std::string FolderDurationPathString{ FolderDurationSpecefiedPath.parent_path().generic_string() };

	//5-18-2020
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_D_FD_FDS & FX_inst_D_FD_FDS_index = Log_file_Dur_Sig_F_Map.get<FX_inst_D_FD_FDS>();
	Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_D_FD_FDS::iterator it_FX_inst_D_FD_FDS, it_FX_inst_D_FD_FDS_1;
	boost::tie(it_FX_inst_D_FD_FDS, it_FX_inst_D_FD_FDS_1) = FX_inst_D_FD_FDS_index.equal_range(boost::make_tuple(FX_inst,Duration));

	// i need to modify the structs not to replace them so that duration items are different than US items and this difference is used to update structs in Modify_Unique_Signal

	if (it_FX_inst_D_FD_FDS != it_FX_inst_D_FD_FDS_1)
	{
		auto itx = it_FX_inst_D_FD_FDS_1;
		std::advance(itx, -1);
		for (auto it_FX_inst_D_FD_FDS_construct = it_FX_inst_D_FD_FDS; it_FX_inst_D_FD_FDS_construct != it_FX_inst_D_FD_FDS_1;)
			{
				if (it_FX_inst_D_FD_FDS_construct->FolderDuration == FolderDuration)
				{
					if (it_FX_inst_D_FD_FDS_construct->FolderDurationSpecefied == FolderDurationSpecefied)
					{
						//we are in the same duration ....do nothing
					}
					else if (it_FX_inst_D_FD_FDS_construct->FolderDurationSpecefied != FolderDurationSpecefied)
					{
						//we are in different unit of same FolderDuration
						//change FolderDurationSpecefied

						auto it_FX_inst_D_FD_FDS_construct_modify = it_FX_inst_D_FD_FDS_construct;//this is important to avoid change of iterator position after replacement
						++it_FX_inst_D_FD_FDS_construct;

						//not replace but modify
						//here i should put code to catch error regarding replacement>>>>>>>>>>>>>>>>>>>>x2>>
						//try
						//{
							assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_D(Duration)));
							assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FD(FolderDuration)));
							assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FDPS(FolderDurationPathString)));
							assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FDSPS(FolderDurationSpecefiedPathString)));
							assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FDS(FolderDurationSpecefied)));
						//}
						//catch
						//{

						//}

						assert(FX_inst_D_FD_FDS_index.find(boost::make_tuple(FX_inst,Duration, FolderDuration, FolderDurationSpecefied)) != FX_inst_D_FD_FDS_index.end());
						if (it_FX_inst_D_FD_FDS_construct != it_FX_inst_D_FD_FDS_1)
						{
							if (it_FX_inst_D_FD_FDS_construct->FolderDurationSpecefied == FolderDurationSpecefied)
							{
								break;//this is to get out of for loop .this is used here so that when i am in the condition in which i changed FDS and looped in all FDS and changed them .then after changing, the new FDS structs will be ordered either before the looped range e.g when passing from 31 day to 1 day OR same position in range when no change happens to FDS "in this case we would have not entered this else if OR ordered after the looped range but before the element next to end of range ,then this makes infinite loop because it_FX_inst_D_FD_FDS_construct is not equal to it_FX_inst_D_FD_FDS_1 and in the same time it_FX_inst_D_FD_FDS_construct->FolderDurationSpecefied == FolderDurationSpecefied which makes it enter the  if (it_FX_inst_D_FD_FDS_construct->FolderDurationSpecefied == FolderDurationSpecefied) and make infinite loop. So we put this if condition to break loop if we hit the 3rd Or
							}
						}
					}
				}
				else if (it_FX_inst_D_FD_FDS_construct->FolderDuration != FolderDuration)
				{
					//5-17-2020 what is the meaning of different unit in next line???it means we are in different FolderDurationSpecefied"unit" e.g. y2020m00 and struct has y2019m11 so we must have  different folder duration y2020m and y2019m
					//we are in different unit in different FolderDuration
					//change FolderDuration and FolderDurationSpecefied

					auto it_FX_inst_D_FD_FDS_construct_modify = it_FX_inst_D_FD_FDS_construct;//this is important to avoid change of iterator position after replacement
					++it_FX_inst_D_FD_FDS_construct;

					//not replace but modify
					//here i should put code to catch error regarding replacement>>>>>>>>>>>>>>>>>>>>x2>>
					//try
					//{
						assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_D(Duration)));
						assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FD(FolderDuration)));
						assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FDPS(FolderDurationPathString)));
						assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FDSPS(FolderDurationSpecefiedPathString)));
						assert(FX_inst_D_FD_FDS_index.modify(it_FX_inst_D_FD_FDS_construct_modify, change_FDS(FolderDurationSpecefied)));
					//}
					//catch
					//{

					//}

					assert(FX_inst_D_FD_FDS_index.find(boost::make_tuple(FX_inst,Duration, FolderDuration, FolderDurationSpecefied)) != FX_inst_D_FD_FDS_index.end());
					if (it_FX_inst_D_FD_FDS_construct != it_FX_inst_D_FD_FDS_1)
					{
						if (it_FX_inst_D_FD_FDS_construct->FolderDuration == FolderDuration)
						{
							break;//this is to get out of for loop .this is used here so that when i am in the condition in which i changed FD and looped in all FD and changed them .then after changing, the new FD structs will be ordered either before the looped range e.g when passing from 10 month to 11 month OR same position in range when no change happens to FD "in this case we would have not entered this else if OR ordered after the looped range but before the element next to end of range ,then this makes infinite loop because it_FX_inst_D_FD_FDS_construct is not equal to it_FX_inst_D_FD_FDS_1 and in the same time it_FX_inst_D_FD_FDS_construct->FolderDuration == FolderDuration which makes it enter the  if (it_FX_inst_D_FD_FDS_construct->FolderDuration== FolderDuration) and make infinite loop. So we put this if condition to break loop if we hit the 3rd Or
						}
					}
				}
			}
	}

	else if (it_FX_inst_D_FD_FDS == it_FX_inst_D_FD_FDS_1)//this code only happens at beginning of program
	{
		bool successful_insert = std::get<1>(FX_inst_D_FD_FDS_index.insert(Log_file_Dur_Sig_F_Map_struct(FX_inst,Duration, FolderDurationSpecefied, FolderDurationSpecefiedPathString, FolderDurationSpecefiedPath)));//here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
		assert(successful_insert);
	}
}
