#include <iostream>
#include <fstream>
#include <vector>

#include "imageStructs.h"

std::vector<std::vector<Pixel>> readBMP(const std::string& filename, BMPHeader &header, BMPInfoHeader &infoHeader);