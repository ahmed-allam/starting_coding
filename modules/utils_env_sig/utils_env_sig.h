#ifndef UTILS_ENV_SIG_H
#define UTILS_ENV_SIG_H

#include <boost/algorithm/string/case_conv.hpp>

#include <iostream>
#include <csignal>
#include <string>

//std::string getEnvVar(std::string const &);
std::string is_debug_mode();

void signal_handler(int);

void set_up_signals();




#endif // !UTILS_ENV_SIG_H
