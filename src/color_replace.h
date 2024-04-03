#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

#include "consts.h"
#include "imageStructs.h"

void changeColors(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap);
Pixel parsePixel(const std::string& colorString);
bool operator==(const Pixel& old_color, const Pixel& current_color);