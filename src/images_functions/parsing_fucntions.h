#include <iostream>
#include <sstream>
#include <string>

#include "imageStructs.h"

bool operator==(const Pixel& old_color, const Pixel& current_color);
Pixel parsePixel(const std::string& colorString);