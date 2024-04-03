#include <fstream>
#include <vector>
#include "imageStructs.h" // Предполагается, что в этом файле определены структуры BMPHeader и BMPInfoHeader

void writeBMP(const std::string& filename, const BMPHeader& header, const BMPInfoHeader& infoHeader, const std::vector<std::vector<Pixel>>& bitArr);