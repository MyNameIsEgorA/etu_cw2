#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

#include "imageStructs.h"
#include "parsing_fucntions.h"

void split(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap);


