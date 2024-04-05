#include <vector>
#include <unordered_map>
#include <string>

#include "imageStructs.h"
#include "parsing_fucntions.h"

void mirror(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap);

void reverseX(int width, int height, std::vector<std::vector<Pixel>> &bytesARR, int x_start, int y_start, int x_end, int y_end);
void reverseY(int width, int height, std::vector<std::vector<Pixel>> &bytesARR, int x_start, int y_start, int x_end, int y_end);