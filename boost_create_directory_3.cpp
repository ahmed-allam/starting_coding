
#include "boost_create_directory_3.h"
//6-11-2020
std::vector<std::string> GetListOfDrives()
{
#if BOOST_OS_WINDOWS
    std::vector<std::string> arrayOfDrives;
	#include <windows.h>//this is to get drives in windows

    char* szDrives = new char[MAX_PATH]();
    if (GetLogicalDriveStringsA(MAX_PATH, szDrives));

    for (int i = 0; i < 100; i += 4)
    {
        if (szDrives[i] != (char)0)
        {
            arrayOfDrives.push_back(std::string{szDrives[i],szDrives[i+1],szDrives[i+2]});
        }
    }
    delete[] szDrives;
    return arrayOfDrives;
#endif
}

std::string& replace(std::string &s, const std::string &from,
		const std::string &to) {
	if (!from.empty())
		for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos;
				pos += to.size())
			s.replace(pos, from.size(), to);
	return s;
}

path init_path_Main_begin(std::string localpath, std::string mRootPath)
{
	if (localpath.find("//?/") != localpath.npos)
	{
		replace(localpath, "//?/", "\\\\?\\");
	}

	////allam 2020 this might be relative path
	//4-8-2020 i want to add the local path to rootname e.g E: and rootdirectory /   "E:/"
	std::string LocalPathstring { "" };
	boost::filesystem::path root_path_var ;

	std::string default_answer { "default_answer" };
	if (mRootPath == default_answer)
	{
		root_path_var =boost::filesystem::current_path().root_path() ;
		if (root_path_var.has_root_name() && BOOST_OS_WINDOWS)	//windows system folder
		{
			if (root_path_var == "C:/")
			{
				std::vector<std::string> ListOfDrives = GetListOfDrives();
				if (ListOfDrives.size() <= 1)
				{
					LocalPathstring = root_path_var.generic_string()+ localpath;
				}
				else if (ListOfDrives.size() > 1)	//test that next drive is hdd not cd
				{
#if BOOST_OS_WINDOWS
	#include <windows.h>//this is to get drives in windows

					switch(GetDriveType(ListOfDrives[1]))
					{
						case DRIVE_FIXED:
						{
							cout<<"Fixed drive detected: "<<charDrv<<endl;
							LocalPathstring=ListOfDrives[1]+localpath;

							break;
						}
						case DRIVE_REMOVABLE:
						{
							cout<<"Removable drive detected: "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_NO_ROOT_DIR:
						{
							cout<<"There is no volume mounted at the specified path. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_REMOTE:
						{
							cout<<"The drive is a remote (network) drive. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_CDROM:
						{
							cout<<"The drive is a CD-ROM drive. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_RAMDISK:
						{
							cout<<"The drive is a RAM disk. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_UNKNOWN:
						{
							cout<<"The drive type cannot be determined. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
					}
#endif

				}
			}
			else if (root_path_var != "C:/")
			{
				LocalPathstring=root_path_var.generic_string()+localpath;
			}
		}
		else if ((!root_path_var.has_root_name()) && BOOST_OS_LINUX  )
		{
			auto me = getuid();
			auto myprivs = geteuid();
		    if (getuid())
		    {
		    	printf("%s", "ALLAM,You are not root!\n");
				//LocalPathstring="~/"+localpath;//there is nothing called "~/"but we can use fs::path(getenv("HOME"))
		    	LocalPathstring=boost::filesystem::path(getenv("HOME")).generic_string()+"/"+localpath;
		    }
		    else
		    {
		    	printf("%s", "ALLAM OK, you are root.\n");
				LocalPathstring=root_path_var.generic_string()+localpath;
		    }
		}

	// throw exception
	}
	else if (mRootPath != "default_answer")
	{
		root_path_var =boost::filesystem::path(localpath).root_path() ;

		if (root_path_var.has_root_name() && BOOST_OS_WINDOWS)	//windows system folder
				{
					if (root_path_var == "C:/")
					{
						std::vector<std::string> ListOfDrives = GetListOfDrives();
						if (ListOfDrives.size() <= 1) {
							LocalPathstring = root_path_var.generic_string()
									+ localpath;
						}
						else if (ListOfDrives.size() > 1)	//test that next drive is hdd not cd
						{
#if BOOST_OS_WINDOWS
	#include <windows.h>//this is to get drives in windows

					switch(GetDriveType(ListOfDrives[1]))
					{
						case DRIVE_FIXED:
						{
							cout<<"Fixed drive detected: "<<charDrv<<endl;
							LocalPathstring=ListOfDrives[1]+localpath;
							break;
						}
						case DRIVE_REMOVABLE:
						{
							cout<<"Removable drive detected: "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_NO_ROOT_DIR:
						{
							cout<<"There is no volume mounted at the specified path. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_REMOTE:
						{
							cout<<"The drive is a remote (network) drive. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_CDROM:
						{
							cout<<"The drive is a CD-ROM drive. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_RAMDISK:
						{
							cout<<"The drive is a RAM disk. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
						case DRIVE_UNKNOWN:
						{
							cout<<"The drive type cannot be determined. "<<charDrv<<endl;
							LocalPathstring=root_path_var.generic_string()+localpath;

							break;
						}
					}
#endif

						}
					}
					else if (root_path_var != "C:/")
					{
						LocalPathstring=root_path_var.generic_string()+localpath;
					}
				}
				else if ((!root_path_var.has_root_name()) && BOOST_OS_LINUX  )
				{
					auto me = getuid();
					auto myprivs = geteuid();
				    if (getuid())
				    {
				    	printf("%s", "You are not root!\n");
				    	//6-11-2020 the following line make log folders in the launching drive in the given path argument
						LocalPathstring=localpath;
				    }
				    else
				    {
				    	printf("%s", "OK, you are root.\n");

				    	//6-11-2020 the following line make log folders in the launching drive in the given path argument
						LocalPathstring=localpath;
				    }
				}
	}

	boost::filesystem::path path_argument(LocalPathstring);
	boost::filesystem::path path_native;
	path_native = path_argument.make_preferred();////allam 2020 this make the proposed path

	//20-9-2020
	/*
	if (!path_argument.has_root_path())

	{
		path_native = path_argument.make_preferred();////allam 2020 this make the proposed path
	}
	else if (path_argument.has_root_path())
	{
		path_native = path_argument.make_preferred();////allam 2020 this make the proposed path
	}
	 */

	//6-11-2020 linux
	boost::filesystem::path abs_localpath(absolute(path_native));
	boost::system::error_code ec;

	if (!exists(abs_localpath))
	{

		boost::filesystem::create_directories(abs_localpath, ec);
		if (ec.value() != boost::system::errc::errc_t::success)	//(ec.value()==0) //(ec.value() != 0))
		{
			std::cerr << ec.message() << '\n';
		}
		else
		{
			std::cout << "Success making new directories" << "\n";
			return abs_localpath;
		}
	}
	return abs_localpath;
}


path init_path(std::string path)
{

	if (path.find("//?/")!=path.npos)
	{
		replace(path, "//?/", "\\\\?\\");
	}

	std::string localpath = path;////allam 2020 this might be relative path
	//4-8-2020 i want to add the local path to rootname e.g E: and rootdirectory /   "E:/"


	boost::filesystem::path root_path_var { boost::filesystem::current_path().root_path()};
	boost::filesystem::path path_argument(localpath);
	boost::filesystem::path path_native;
	if (!path_argument.has_root_path())
	{
		path_native=root_path_var / path_argument.make_preferred();////allam 2020 this make the proposed path
	}
	else if (path_argument.has_root_path())
	{
		path_native = path_argument.make_preferred();////allam 2020 this make the proposed path
	}


	boost::filesystem::path abs_localpath(absolute(path_native));
	boost::system::error_code ec;
	if (!exists(abs_localpath))
	{
		boost::filesystem::create_directories(abs_localpath, ec);
		if (ec.value() != boost::system::errc::errc_t::success)//(ec.value()==0) //(ec.value() != 0))
		{
			std::cerr << ec.message() << '\n';
		}
		else
		{
			return abs_localpath;
		}
	}
	return abs_localpath;
}

