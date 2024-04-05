#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

#include "../consts.h"
#include "imageStructs.h"
#include "parsing_fucntions.h"


void copyPartOfImage(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap);