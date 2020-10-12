//#include "../../stdafx.h"
#include "utils_env_sig.h"
/*
std::string getEnvVar(std::string const & key)
{
	char * val = getenv(key.c_str());
	return val == NULL ? std::string("") : std::string(val);
}
*/
std::string is_debug_mode()
{
	std::string key = "LOG";
	char * log_env = getenv(key.c_str());
	//6-15-2020
	//if (*log_env != NULL)
	if (*log_env != 0)

	{
		//*log_env == "DEBUG";
		return  "DEBUG";
	}
	else
	{
		return "False";
	}

}

void signal_handler(int signum)
{
	std::cout << "Interrupt signal (" << signum << ") received.\n";

	// cleanup and close up stuff here  
	// terminate program  

	exit(signum);
}

void set_up_signals()
{
	// register signal SIGINT and signal handler  
	signal(SIGINT, signal_handler);
}

/*
def set_up_signals() :
def signal_handler(signal, frame) :
sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
*/

/*
def is_debug_mode() :
log_env = os.getenv('LOG', None)
if log_env is not None :
return log_env.upper() == 'DEBUG'
else :
return False
*/
