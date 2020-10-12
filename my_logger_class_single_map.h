#ifndef MY_LOGGER_CLASS_SINGLE_MAP_O_H   // if my_logger_class_single_map_24.h hasn't been included yet...
#define MY_LOGGER_CLASS_SINGLE_MAP_O_H   //   #define this so the compiler knows it has been included

/*
0-first date with 404
1-first date with 200
2-dates with zero size after first date with 200
3-dates of saturday and sunday after first date with 200
4-dates not saturday or sunday after first date with 200 and having zero size
5-dates not saturday or sunday after first date with 200 and having 400
6-last date recieved and written to file
*/

#include <boost/config.hpp>

#if !defined(NDEBUG)
#define BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING
#define BOOST_MULTI_INDEX_ENABLE_SAFE_MODE
#endif

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

using boost::multi_index_container;
using namespace boost::multi_index;

#include <cstdlib> //this is to clear console?????consider changing this method when refactoring

#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/unlocked_frontend.hpp>
#include <boost/log/sinks/basic_sink_backend.hpp>
#include <boost/log/sinks/frontend_requirements.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
//for cout logger
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/core/null_deleter.hpp>

#include <boost/log/attributes.hpp> //for attr:
#include <boost/log/sources/logger.hpp> //for loggers
#include <boost/log/common.hpp> //for macros

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/support/date_time.hpp>

#include <boost/bimap.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/bimap/list_of.hpp>
using namespace boost::bimaps;

#include <boost/ref.hpp>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include <boost/date_time/gregorian/gregorian.hpp> //include all types plus i/o
using namespace boost::gregorian;

#include <boost/fusion/adapted/struct.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/phoenix/phoenix.hpp>
using boost::phoenix::arg_names::arg1;
#include <boost/enable_shared_from_this.hpp>  //this is for enable_shared_from_this

#include "boost_create_directory_3.h"
#include <boost/thread/mutex.hpp>

//??#include <record_ostream.hpp>
////#include "boost_asio_http_coroutine_class.h"


//??#include "BOOST_LOG_function.h"

namespace sinks = boost::log::sinks;
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;

// Complete sink type
typedef sinks::synchronous_sink< sinks::text_file_backend > file_sink;
//for cout logger
typedef sinks::synchronous_sink< sinks::text_ostream_backend > cout_sink;

//make the RCF ban map using US USvalue and duration
struct RCF_Ban_Map_struct   
{
	//5-18-2020??
	std::string FX_inst = "";
	std::string Duration = "";
	std::string UniqueSignal = "";
	std::string UniqueSignalvalue = "";
	std::string ModifiedUniqueSignal = "";

	RCF_Ban_Map_struct()
	{
	}
	//5-18-2020??
	RCF_Ban_Map_struct(const std::string& FX_inst, const std::string& duration, const std::string& UniqueSignal, std::string const& UniqueSignalvalue, std::string const& ModifiedUniqueSignal) :FX_inst(FX_inst), Duration(duration), UniqueSignal(UniqueSignal), UniqueSignalvalue(UniqueSignalvalue), ModifiedUniqueSignal(ModifiedUniqueSignal)
	{
	}

	//bool operator<(const Log_file_Dur_Sig_F_Map_struct& e)const { return Duration < e.Duration; }

};
struct change_FX_inst_RCF_Ban_Map_struct
{
	change_FX_inst_RCF_Ban_Map_struct(const std::string& new_FX_inst) :new_FX_inst_m(new_FX_inst) {}

	void operator()(RCF_Ban_Map_struct& e)
	{
		e.FX_inst = new_FX_inst_m;
	}

private:
	std::string new_FX_inst_m;
};
struct change_D_RCF_Ban_Map_struct
{
	change_D_RCF_Ban_Map_struct(const std::string& new_D) :new_D_m(new_D) {}

	void operator()(RCF_Ban_Map_struct& e)
	{
		e.Duration = new_D_m;
	}

private:
	std::string new_D_m;
};
struct change_US_RCF_Ban_Map_struct
{
	change_US_RCF_Ban_Map_struct(const std::string& new_US) :new_US_m(new_US) {}

	void operator()(RCF_Ban_Map_struct& e)
	{
		e.UniqueSignal = new_US_m;
	}

private:
	std::string new_US_m;
};
struct change_USvalue_RCF_Ban_Map_struct
{
	change_USvalue_RCF_Ban_Map_struct(const std::string& new_USvalue) :new_USvalue_m(new_USvalue) {}

	void operator()(RCF_Ban_Map_struct& e)
	{
		e.UniqueSignalvalue = new_USvalue_m;
	}

private:
	std::string new_USvalue_m;
};
struct change_MUS_RCF_Ban_Map_struct
{
	change_MUS_RCF_Ban_Map_struct(const std::string& new_MUS) :new_MUS_m(new_MUS) {}

	void operator()(RCF_Ban_Map_struct& e)
	{
		e.ModifiedUniqueSignal = new_MUS_m;
	}

private:
	std::string new_MUS_m;
};

// tags for accessing the corresponding indices of  //
//5-18-2020??
/*
struct US_USvalue_D {};
struct US_USvalue_D_MUS {};
struct D {};
struct US_USvalue {};
*/
//5-18-2020??
struct FX_inst_US_USvalue_D {};
struct FX_inst_US_USvalue_D_MUS {};
struct FX_inst_D {};
struct FX_inst_US_USvalue {};
/*
*NB: The use of derivation here instead of simple typedef is explained in
* Compiler specifics : type hiding.
*/
////check if we need to define composite_key_compare
/*
struct US_USvalue_D_key :composite_key <
	RCF_Ban_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignalvalue),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, Duration)
> {};
struct US_USvalue_D_MUS_key :composite_key <
	RCF_Ban_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignalvalue),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, ModifiedUniqueSignal)
> {};
*/
//5-18-2020??
struct FX_inst_US_USvalue_D_key :composite_key <
	RCF_Ban_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignalvalue),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, Duration)
> {};
struct FX_inst_US_USvalue_D_MUS_key :composite_key <
	RCF_Ban_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, UniqueSignalvalue),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(RCF_Ban_Map_struct, std::string, ModifiedUniqueSignal)
> {};
// reducing symbol names through type hiding
// type hide the index specifier list within employee_set_indices

struct RCF_Ban_Map_struct_set_indices :
	indexed_by <
	//5-18-2020
	/*
	ordered_non_unique<
	tag<US_USvalue_D>, US_USvalue_D_key >,
	ordered_non_unique<
	tag<US_USvalue_D_MUS>, US_USvalue_D_MUS_key >,
	*/
	ordered_non_unique<
	tag<FX_inst_US_USvalue_D>, FX_inst_US_USvalue_D_key >,
	ordered_non_unique<
	tag<FX_inst_US_USvalue_D_MUS>, FX_inst_US_USvalue_D_MUS_key >
	>
{};

typedef multi_index_container<
	RCF_Ban_Map_struct,
	RCF_Ban_Map_struct_set_indices
> RCF_Ban_Map_struct_set;
//5-18-2020
/*
typedef RCF_Ban_Map_struct_set::index<US_USvalue_D>::type RCF_Ban_Map_struct_set_by_US_USvalue_D;
typedef RCF_Ban_Map_struct_set::index<US_USvalue_D_MUS>::type RCF_Ban_Map_struct_set_by_US_USvalue_D_MUS;
*/
typedef RCF_Ban_Map_struct_set::index<FX_inst_US_USvalue_D>::type RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D;
typedef RCF_Ban_Map_struct_set::index<FX_inst_US_USvalue_D_MUS>::type RCF_Ban_Map_struct_set_by_FX_inst_US_USvalue_D_MUS;
BOOST_FUSION_ADAPT_STRUCT(RCF_Ban_Map_struct, (std::string, FX_inst), (std::string, UniqueSignal)(std::string, UniqueSignalvalue) (std::string, Duration)(std::string, ModifiedUniqueSignal));

struct Log_file_Dur_Sig_F_Map_struct   //Duration_Signal_Folder_Map_struct >>>log file destination
{	
	int         Id;
	std::string FX_inst = "";

	std::string Duration="";
	std::string FolderDuration="";//??
	std::string FolderDurationSpecefied="";
	std::string FolderDurationPathString="";//??
	std::string FolderDurationSpecefiedPathString="";

	//make fields for UniqueSignal and ModifiedUniqueSignal
	std::string UniqueSignal = "";
	std::string ModifiedUniqueSignal = "";
	std::string ModifiedUniqueSignalCertainUniqueSignal = "";

	std::string FolderDurationSpecefiedUniqueSignal="";
	std::string FolderDurationSpecefiedUniqueSignalPathString = "";
	std::string FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal="";
	std::string FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString = "";

	//make fields for Backend
	std::string UniqueSignalvalue = "";
	std::string FolderDurationSpecefied_previous{""};
	//bool begin_program{ false };
	std::string BackendName{ "" };
	std::string BackendFileName{ "" };
	std::string BackendFileNamePathString{ "" };
	std::string BackendFileNamePathString_parent{ "" };
	boost::shared_ptr<sinks::text_file_backend> BackendSharedPointer{ nullptr }; //default constructed empty
	
	//make fields for logger
	std::string loggerChannelName{""};
	boost::shared_ptr<src::channel_logger_mt<>> loggerChannelSharedPointer{ nullptr };//default constructed empty
	
	//make fields for FrontendName
	std::string FrontendName { "" };	
	boost::shared_ptr<file_sink> FrontendSharedPointer{ nullptr };//default constructed empty

	Log_file_Dur_Sig_F_Map_struct(const std::string& FX_inst,const std::string& duration, const std::string& folderdurationspecefied, std::string const& folderdurationspecefiedpathstring, const path folderdurationspecefiedpath) :FX_inst(FX_inst), Duration(duration), FolderDurationSpecefied(folderdurationspecefied), FolderDurationSpecefiedPathString(folderdurationspecefiedpathstring)
	{
		if (duration == "AllTime")
		{
			Id = 0;
		}
		else if (duration == "Yearly")
		{
			Id = 1;
		}
		else if (duration == "Monthly")
		{
			Id = 2;
		}
		else if (duration == "Daily")
		{
			Id = 3;
		}

		FolderDuration = folderdurationspecefiedpath.parent_path().filename().generic_string();//why i get Duration in arguments???>>>>>>>>>>>>>>>>>>>>x1>>because duration means the time duration and FolderDuration means the folder built for time duration which include certain time like 2019 or 00 month...
		FolderDurationPathString = folderdurationspecefiedpath.parent_path().generic_string() ;
	}

	bool operator<(const Log_file_Dur_Sig_F_Map_struct& e)const { return Id<e.Id; }
};

BOOST_FUSION_ADAPT_STRUCT(Log_file_Dur_Sig_F_Map_struct,
(int, Id)
(std::string, FX_inst)
(std::string, Duration)
(std::string, FolderDuration)
(std::string, FolderDurationSpecefied)
(std::string, FolderDurationPathString)
(std::string, FolderDurationSpecefiedPathString)
(std::string, UniqueSignal)
(std::string, ModifiedUniqueSignal)
(std::string, ModifiedUniqueSignalCertainUniqueSignal)
(std::string, FolderDurationSpecefiedUniqueSignal)
(std::string, FolderDurationSpecefiedUniqueSignalPathString)
(std::string, FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal)
(std::string, FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString)
(std::string ,UniqueSignalvalue)
(std::string ,FolderDurationSpecefied_previous)
(std::string, BackendName)
(std::string, BackendFileName)
(std::string, BackendFileNamePathString)
(std::string, BackendFileNamePathString_parent)
(std::string ,loggerChannelName)
(std::string ,FrontendName)
(boost::shared_ptr<sinks::text_file_backend>, BackendSharedPointer)
(boost::shared_ptr<src::channel_logger_mt<>>, loggerChannelSharedPointer)
(boost::shared_ptr<file_sink>, FrontendSharedPointer)
);
/*
(boost::shared_ptr<src::channel_logger_mt<>>, loggerChannelSharedPointer)
(boost::shared_ptr<file_sink>, FrontendSharedPointer)
*/
struct change_FX_inst
{
	change_FX_inst(const std::string& new_FX_inst) :new_FX_inst_m(new_FX_inst) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FX_inst = new_FX_inst_m;
	}

private:
	std::string new_FX_inst_m;
};
struct change_D
{
	change_D(const std::string& new_D) :new_D_m(new_D) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.Duration = new_D_m;
	}

private:
	std::string new_D_m;
};
struct change_FD
{
	change_FD(const std::string& new_FD) :new_FD_m(new_FD) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDuration = new_FD_m;
	}

private:
	std::string new_FD_m;
};

struct change_FDS
{
	change_FDS(const std::string& new_FDS) :new_FDS_m(new_FDS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefied = new_FDS_m;
	}

private:
	std::string new_FDS_m;
};

struct change_FDSPS
{
	change_FDSPS(const std::string& new_FDSPS) :new_FDSPS_m(new_FDSPS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefiedPathString = new_FDSPS_m;
	}

private:
	std::string new_FDSPS_m;
};

struct change_FDPS
{
	change_FDPS(const std::string& new_FDPS) :new_FDPS_m(new_FDPS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationPathString = new_FDPS_m;
	}

private:
	std::string new_FDPS_m;
};

struct change_UniqueSignal
{
	change_UniqueSignal(const std::string& new_UniqueSignal) :new_UniqueSignal_m(new_UniqueSignal) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.UniqueSignal = new_UniqueSignal_m;
	}

private:
	std::string new_UniqueSignal_m;
};

struct change_FDSUS
{
	change_FDSUS(const std::string& new_FDSUS) :new_FDSUS_m(new_FDSUS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefiedUniqueSignal = new_FDSUS_m;
	}

private:
	std::string new_FDSUS_m;
};

struct change_FDSUSPS
{
	change_FDSUSPS(const std::string& new_FDSUSPS) :new_FDSUSPS_m(new_FDSUSPS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefiedUniqueSignalPathString = new_FDSUSPS_m;
	}

private:
	std::string new_FDSUSPS_m;
};

struct change_MUS
{
	change_MUS(const std::string& new_MUS) :new_MUS_m(new_MUS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.ModifiedUniqueSignal = new_MUS_m;
	}

private:
	std::string new_MUS_m;
};

struct change_MUSCUS
{
	change_MUSCUS(const std::string& new_MUSCUS) :new_MUSCUS_m(new_MUSCUS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.ModifiedUniqueSignalCertainUniqueSignal = new_MUSCUS_m;
	}

private:
	std::string new_MUSCUS_m;
};

struct change_FDSMUSCUS
{
	change_FDSMUSCUS(const std::string& new_FDSMUSCUS) :new_FDSMUSCUS_m(new_FDSMUSCUS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignal = new_FDSMUSCUS_m;
	}

private:
	std::string new_FDSMUSCUS_m;
};

struct change_FDSMUSCUSPS
{
	change_FDSMUSCUSPS(const std::string& new_FDSMUSCUSPS) :new_FDSMUSCUSPS_m(new_FDSMUSCUSPS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefiedModifiedUniqueSignalCertainUniqueSignalPathString = new_FDSMUSCUSPS_m;
	}

private:
	std::string new_FDSMUSCUSPS_m;
};

struct change_USvalue
{
	change_USvalue(const std::string& new_USvalue) :new_USvalue_m(new_USvalue) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.UniqueSignalvalue = new_USvalue_m;
	}

private:
	std::string new_USvalue_m;
};

struct change_FolderDurationSpecefied_previous
{
	change_FolderDurationSpecefied_previous(const std::string& new_FolderDurationSpecefied_previous) :new_FolderDurationSpecefied_previous_m(new_FolderDurationSpecefied_previous) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FolderDurationSpecefied_previous = new_FolderDurationSpecefied_previous_m;
	}

private:
	std::string new_FolderDurationSpecefied_previous_m;
};

struct change_BName
{
	change_BName(const std::string& new_BName) :new_BName_m(new_BName) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.BackendName = new_BName_m;
	}

private:
	std::string new_BName_m;
};

struct change_BFName
{
	change_BFName(const std::string& new_BFName) :new_BFName_m(new_BFName) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.BackendFileName = new_BFName_m;
	}

private:
	std::string new_BFName_m;
};

struct change_BFNamePS
{
	change_BFNamePS(const std::string& new_BFNamePS) :new_BFNamePS_m(new_BFNamePS) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.BackendFileNamePathString = new_BFNamePS_m;
	}

private:
	std::string new_BFNamePS_m;
};

struct change_BFNamePS_parent
{
	change_BFNamePS_parent(const std::string& new_BFNamePS_parent) :new_BFNamePS_parent_m(new_BFNamePS_parent) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.BackendFileNamePathString_parent = new_BFNamePS_parent_m;
	}

private:
	std::string new_BFNamePS_parent_m;
};

struct change_BSP
{
	change_BSP(const boost::shared_ptr<sinks::text_file_backend> & new_BSP) :new_BSP_m(new_BSP) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		//std::cout << "e.BackendSharedPointer.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
		e.BackendSharedPointer = new_BSP_m;
		//std::cout << "e.BackendSharedPointer.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
	}
	void operator()(Log_file_Dur_Sig_F_Map_struct& e) const
	{
		//std::cout << "e.BackendSharedPointer.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
		e.BackendSharedPointer.reset();
		//std::cout << "e.BackendSharedPointer.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
	}

private:
	boost::shared_ptr<sinks::text_file_backend> new_BSP_m;//??????????????????????? &
};

struct change_BSP_reset
{
	change_BSP_reset(const boost::shared_ptr<sinks::text_file_backend> & new_BSP) :new_BSP_m(new_BSP) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		std::cout << "e.BackendSharedPointer.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
		e.BackendSharedPointer.reset();
		std::cout << "e.BackendSharedPointer.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
	}
	void operator()(Log_file_Dur_Sig_F_Map_struct& e) const
	{
		std::cout << "e.BackendSharedPointer_const.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
		e.BackendSharedPointer.reset();
		std::cout << "e.BackendSharedPointer_const.use_count() == " << e.BackendSharedPointer.use_count() << '\n';
	}

private:
	boost::shared_ptr<sinks::text_file_backend> new_BSP_m;//??????????????????????? &
};

struct change_LCN
{
	change_LCN(const std::string& new_LCN) :new_LCN_m(new_LCN) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.loggerChannelName = new_LCN_m;
	}

private:
	std::string new_LCN_m;
};

struct change_LCSP
{
	change_LCSP(const boost::shared_ptr<src::channel_logger_mt<>> &new_LCSP) :new_LCSP_m(new_LCSP) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		std::cout << "e.loggerChannelSharedPointer.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
		e.loggerChannelSharedPointer = new_LCSP_m;
		std::cout << "e.loggerChannelSharedPointer.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
	}
	void operator()(Log_file_Dur_Sig_F_Map_struct& e) const
	{
		std::cout << "e.loggerChannelSharedPointer.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
		e.loggerChannelSharedPointer.reset(); 
		std::cout << "e.loggerChannelSharedPointer.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
	}

private:
	boost::shared_ptr<src::channel_logger_mt<>>	new_LCSP_m;
};

struct change_LCSP_reset
{
	change_LCSP_reset(const boost::shared_ptr<src::channel_logger_mt<>> &new_LCSP) :new_LCSP_m(new_LCSP) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		//std::cout << "e.loggerChannelSharedPointer.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
		e.loggerChannelSharedPointer.reset();
		//std::cout << "e.loggerChannelSharedPointer.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
	}
	void operator()(Log_file_Dur_Sig_F_Map_struct& e) const
	{
		//std::cout << "e.loggerChannelSharedPointer_const.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
		e.loggerChannelSharedPointer.reset();
		//std::cout << "e.loggerChannelSharedPointer_const.use_count() == " << e.loggerChannelSharedPointer.use_count() << '\n';
	}

private:
	boost::shared_ptr<src::channel_logger_mt<>>	new_LCSP_m;
};

struct change_FName
{
	change_FName(const std::string& new_FName) :new_FName_m(new_FName) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		e.FrontendName = new_FName_m;
	}

private:
	std::string new_FName_m;
};

struct change_FSP
{
	change_FSP(const boost::shared_ptr<file_sink> &new_FSP) :new_FSP_m(new_FSP) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		//std::cout << "e.FrontendSharedPointer.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
		e.FrontendSharedPointer = new_FSP_m;
		//std::cout << "e.FrontendSharedPointer.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
	}
	void operator()(Log_file_Dur_Sig_F_Map_struct& e) const
	{
		//std::cout << "e.FrontendSharedPointer.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
		e.FrontendSharedPointer.reset();
		//std::cout << "e.FrontendSharedPointer.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
	}

private:
	boost::shared_ptr<file_sink>	new_FSP_m;
};

struct change_FSP_reset
{
	change_FSP_reset(const boost::shared_ptr<file_sink> &new_FSP) :new_FSP_m(new_FSP) {}

	void operator()(Log_file_Dur_Sig_F_Map_struct& e)
	{
		std::cout << "e.FrontendSharedPointer.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
		e.FrontendSharedPointer.reset();
		std::cout << "e.FrontendSharedPointer.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
	}
	void operator()(Log_file_Dur_Sig_F_Map_struct& e) const
	{
		std::cout << "e.FrontendSharedPointer_const.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
		e.FrontendSharedPointer.reset();
		std::cout << "e.FrontendSharedPointer_const.use_count() == " << e.FrontendSharedPointer.use_count() << '\n';
	}

private:
	boost::shared_ptr<file_sink>	new_FSP_m;
};

// tags for accessing the corresponding indices of Log_file_Dur_Sig_F_Map_struct_set //
/*
struct D_FD_FDS {};
struct US {};
struct MUS {};
struct US_D_FD_FDS {};
struct US_D_FD_FDS_MUS {};
struct US_D_FD_FDS_MUS_BName {};
struct US_MUS {};
struct US_LCN {};
*/
struct FX_inst_D_FD_FDS {};
struct FX_inst_US {};
struct FX_inst_US_D_FD_FDS {};
struct FX_inst_US_D_FD_FDS_MUS {};
struct FX_inst_US_D_FD_FDS_MUS_BName {};
struct FX_inst_US_MUS {};
struct FX_inst_US_LCN {};
/*
*NB: The use of derivation here instead of simple typedef is explained in
* Compiler specifics : type hiding.
*/
/*
////check if we need to define composite_key_compare
struct D_FD_FDS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied)
> {};

struct US_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal)	
> {};

struct US_D_FD_FDS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied)
> {};

struct US_D_FD_FDS_MUS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal)
> {};

struct US_D_FD_FDS_MUS_BName_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, BackendName)
> {};

struct US_MUS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),	
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal)
> {};

struct US_LCN_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, loggerChannelName)
> {};
*/
//5-18-2020
struct FX_inst_D_FD_FDS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied)
> {};

struct FX_inst_US_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal)
> {};

struct FX_inst_US_D_FD_FDS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct, 
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied)
> {};

struct FX_inst_US_D_FD_FDS_MUS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal)
> {};

struct FX_inst_US_D_FD_FDS_MUS_BName_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, Duration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDuration),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FolderDurationSpecefied),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, BackendName)
> {};

struct FX_inst_US_MUS_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, ModifiedUniqueSignal)
> {};

struct FX_inst_US_LCN_key :composite_key <
	Log_file_Dur_Sig_F_Map_struct,
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, FX_inst),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, UniqueSignal),
	BOOST_MULTI_INDEX_MEMBER(Log_file_Dur_Sig_F_Map_struct, std::string, loggerChannelName)
> {};

// reducing symbol names through type hiding
// type hide the index specifier list within employee_set_indices

struct Log_file_Dur_Sig_F_Map_struct_set_indices :
	indexed_by <
	/*
	ordered_non_unique<
	tag<D_FD_FDS>, D_FD_FDS_key >,
	ordered_non_unique<
	tag<US>, US_key >,
	ordered_non_unique<
	tag<US_D_FD_FDS>, US_D_FD_FDS_key >,
	ordered_non_unique<
	tag<US_D_FD_FDS_MUS>, US_D_FD_FDS_MUS_key >,
	ordered_non_unique<
	tag<US_D_FD_FDS_MUS_BName>, US_D_FD_FDS_MUS_BName_key >,
	ordered_non_unique<
	tag<US_MUS>, US_MUS_key >,
	ordered_non_unique<
	tag<US_LCN>, US_LCN_key >,
	*/
	//5-18-2020
	ordered_non_unique<
	tag<FX_inst_D_FD_FDS>, FX_inst_D_FD_FDS_key >,
	ordered_non_unique<
	tag<FX_inst_US>, FX_inst_US_key >,
	ordered_non_unique<
	tag<FX_inst_US_D_FD_FDS>, FX_inst_US_D_FD_FDS_key >,
	ordered_non_unique<
	tag<FX_inst_US_D_FD_FDS_MUS>, FX_inst_US_D_FD_FDS_MUS_key >,
	ordered_non_unique<
	tag<FX_inst_US_D_FD_FDS_MUS_BName>, FX_inst_US_D_FD_FDS_MUS_BName_key >,
	ordered_non_unique<
	tag<FX_inst_US_MUS>, FX_inst_US_MUS_key >,
	ordered_non_unique<
	tag<FX_inst_US_LCN>, FX_inst_US_LCN_key >
	>
{};

typedef multi_index_container<
	Log_file_Dur_Sig_F_Map_struct,
	Log_file_Dur_Sig_F_Map_struct_set_indices
> Log_file_Dur_Sig_F_Map_struct_set;

/*
typedef Log_file_Dur_Sig_F_Map_struct_set::index<D_FD_FDS>::type Log_file_Dur_Sig_F_Map_struct_set_by_D_FD_FDS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<US>::type Log_file_Dur_Sig_F_Map_struct_set_by_US;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<US_D_FD_FDS>::type Log_file_Dur_Sig_F_Map_struct_set_by_US_D_FD_FDS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<US_D_FD_FDS_MUS>::type Log_file_Dur_Sig_F_Map_struct_set_by_US_D_FD_FDS_MUS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<US_D_FD_FDS_MUS_BName>::type Log_file_Dur_Sig_F_Map_struct_set_by_US_D_FD_FDS_MUS_BName;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<US_MUS>::type Log_file_Dur_Sig_F_Map_struct_set_by_US_MUS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<US_LCN>::type Log_file_Dur_Sig_F_Map_struct_set_by_US_LCN;
*/
//5-18-2020
typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_D_FD_FDS>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_D_FD_FDS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_US>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_US_D_FD_FDS>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_US_D_FD_FDS_MUS>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_US_D_FD_FDS_MUS_BName>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS_MUS_BName;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_US_MUS>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_MUS;

typedef Log_file_Dur_Sig_F_Map_struct_set::index<FX_inst_US_LCN>::type Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_LCN;

class LoggingClass_2 :public boost::enable_shared_from_this<LoggingClass_2>
{
private:
	Log_file_Dur_Sig_F_Map_struct_set Log_file_Dur_Sig_F_Map;
	static boost::bimap<set_of<std::string>, set_of<std::string>> mMUS_Map;
	RCF_Ban_Map_struct_set RCF_Ban_Map;
	std::vector<const Log_file_Dur_Sig_F_Map_struct *> vector_new_structs;

	// create a cout backend
	boost::shared_ptr< sinks::text_ostream_backend > backendCout = boost::make_shared< sinks::text_ostream_backend >();
	
	// create a cout frontend	
	boost::shared_ptr< cout_sink > sink_cout = boost::make_shared<cout_sink>(backendCout);
	

	//30-9-2020
	//allUniqueSignalResponsesOfSameValue 00 00 00 Or 01 01 01 or 200 200 200 Or 404 404 404
	std::string allUniqueSignalResponsesOfSameValue{ "ARS_" };// AllRespSame_ = ARS_

	//allUniqueSignalResponses 00 01 02 01 19 or 200 200 200 400 404 404 >>>>>>>>>>>>>single file
	std::string allUniqueSignalResponsesTogether{ "AR_" };//AllResp_ = AR_

	//allUniqueSignalResponsesForFirstTime  00 01 02 04 22 or 200 300 500 400 404 >>>>>>>>>>>>>>>>>>>>single file
	std::string allUniqueSignalResponsesForFirstTimeTogether{ "ARF_" };// AllRespFirst_ = ARF_

	//UniqueSignalResponseOfCertainValueForFirstTime  00 Or 01 or 300 Or 200 Or 404
	std::string UniqueSignalResponseOfCertainValueForFirstTime{ "RCF_" };// RespCertainFirst_= RCF_
public:	

	LoggingClass_2();//it automatically defines where log files are stored
	LoggingClass_2(std::string, std::string);
	//5-18-2020
	LoggingClass_2(std::string );//it automatically defines where log files are stored
	//LoggingClass_2(std::string, std::string, std::string);
	//std::string m_LoggingClass_2FX_inst = "";

	//i construct folder maps based on folder duration where each element of folder duration has only one element of folder name and path
	void ConstructFolderDurationMaps(const std::string,const std::string,const std::string,const std::string,const path, boost::mutex &);

	//make UniqueSignal to modifiedUniqueSignal method to convert UniqueSignal to the preprogrammed modifiedUniqueSignal with certain typical folderBehaviour
	void ModifyUniqueSignal(const std::string, std::string);
	void Build_MUS_Folders(Log_file_Dur_Sig_F_Map_struct_set_by_FX_inst_US_D_FD_FDS::iterator);//this should be template function
	void CreateUpdateLoggingStructure(std::string, std::string, std::string);
	void CreateUpdate_RCF_Ban_Map(std::string,std::string, std::string);
	
	Log_file_Dur_Sig_F_Map_struct_set &  Get_Log_file_Dur_Sig_F_Map();
	
	//create main loggers not related to file names
	//this string will be used to determine channel,logger,back_end file name,front_end of previous back_end ,filter
	//src::channel_logger_mt<> lg0_first_date_with_404{ keywords::channel = "0" };
	src::channel_logger_mt<> mloggerCoutLog{ keywords::channel = "m_cout_log" };

	//=======================================================================
		
	//getting the instance of core singleton class
	boost::shared_ptr< logging::core > core = logging::core::get();
	//auto core = logging::core::get();

	//========================================================================
	// Setup the common formatter for all sinks
	logging::formatter fmt;

	////allam2020
	/*
public:
	std::string m_formatting_ostream_string{""};
	logging::formatting_ostream m_formatting_ostream{ m_formatting_ostream_string };
	*/
};

#endif//MY_LOGGER_CLASS_SINGLE_MAP_O_H
