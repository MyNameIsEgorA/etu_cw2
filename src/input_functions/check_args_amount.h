#include <getopt.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

#include "../consts.h"
#include "flag_utils.h"

std::unordered_map<std::string, std::string> getParams(int argc, char** argv);