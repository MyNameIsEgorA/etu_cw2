#include <iostream>
#include <sstream>
#include <string>

#include "imageStructs.h"
#include "../consts.h"

bool operator==(const Pixel& old_color, const Pixel& current_color);
Pixel parsePixel(const std::string& colorString);
void getCoords(const std::string& str, int* x, int* y);
void makeCooler(int& x_start, int& y_start, int& x_end, int& y_end, BMPInfoHeader infoHeader);