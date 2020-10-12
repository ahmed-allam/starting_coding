#include "my_logger_class_single_map.h"

void LoggingClass_2::CreateUpdate_RCF_Ban_Map(std::string FX_inst,std::string UniqueSignal, std::string UniqueSignalValue)
{
	//1
	RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D & FX_inst_US_USvalue_D_index = RCF_Ban_Map.get<FX_inst_US_USvalue_D>();
	//4-29-2020
	//5-7-2020 remove cout lines
	/*
	std::cout << FX_inst_US_USvalue_D_index.count(boost::make_tuple(UniqueSignal)) << std::endl;
	*/
	//2-2
	RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D::iterator it_FX_inst_US_USvalue_D_0, it_FX_inst_US_USvalue_D_1;
	boost::tie(it_FX_inst_US_USvalue_D_0, it_FX_inst_US_USvalue_D_1) = FX_inst_US_USvalue_D_index.equal_range(boost::make_tuple(FX_inst,UniqueSignal, UniqueSignalValue));
	auto it_FX_inst_US_USvalue_D_update = it_FX_inst_US_USvalue_D_0;
	if (it_FX_inst_US_USvalue_D_0 == it_FX_inst_US_USvalue_D_1)
	{
		//boost::fusion::for_each(*it_FX_inst_US_USvalue_D_update, std::cout << arg1 << "\n");

		//RCF_Ban_Map_struct new_struct{ *it_FX_inst_US_USvalue_D_update };
		RCF_Ban_Map_struct new_struct{  };
		change_FX_inst_RCF_Ban_Map_struct(FX_inst).operator()(new_struct);
		change_US_RCF_Ban_Map_struct(UniqueSignal).operator()(new_struct);
		change_USvalue_RCF_Ban_Map_struct(UniqueSignalValue).operator()(new_struct);
		//change_D(Duration).operator()(new_struct);

		bool successful_insert = false;
		RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D::iterator it_FX_inst_US_USvalue_D_new;
		boost::tie(it_FX_inst_US_USvalue_D_new, successful_insert) = FX_inst_US_USvalue_D_index.insert(new_struct);////,FolderDuration,FolderDurationSpecefied));
																										 		//here i should put code to catch error regarding insert>>>>>>>>>>>>>>>>>>>>x2>>
		assert(successful_insert);
		//4-27-2020 this is inside CreateUpdate_RCF_Ban_Map
		//std::cout << "this is inside CreateUpdate_RCF_Ban_Map " << "\n";
		//boost::fusion::for_each(*it_FX_inst_US_USvalue_D_new, std::cout << arg1 << "\n");

	}
	else if (it_FX_inst_US_USvalue_D_0 != it_FX_inst_US_USvalue_D_1)
	{
		//do nothing because value is already registered for this UniqueSignal
	}
}





