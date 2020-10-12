#include "stdafx.h"
#include "search_arg_map.h"

search_arg_map::search_arg_map(int argc_c1, char *argv_c1[])
{
	
}
for (int i = 1, i < argc_c1, i++)
{
	search_string_map[i] = argv_c1[i];
}
