#include "split.h"

void split(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap) {
    int width = infoHeader.width;
    int height = infoHeader.height;
    
    int x_amount = std::stoi(argsMap["number_x"]);
    int y_amount = std::stoi(argsMap["number_y"]);
    int thickness = std::stoi(argsMap["thickness"]);
    Pixel color = parsePixel(argsMap["color"]);

    if (x_amount <= 0 || y_amount <= 0) {
        throw std::invalid_argument("Amounts must be greater than zero");
    }
    
    int part_width = (width + x_amount - 1) / x_amount;
    int part_height = (height + y_amount - 1) / y_amount;

    for (int i = 1; i < x_amount; ++i) {
        int x = i * part_width - thickness / 2;
        for (int t = 0; t < thickness; ++t) {
            for (int y = 0; y < height; ++y) {
                if (x - thickness / 2 + t >= 0 && x - thickness / 2 + t < width) {
                    bytesARR[y][x - thickness / 2 + t] = color;
                }
                if (x + thickness / 2 + t >= 0 && x + thickness / 2 + t < width) {
                    bytesARR[y][x + thickness / 2 + t] = color;
                }
            }
        }
    }

    for (int i = 1; i < y_amount; ++i) {
        int y = i * part_height - thickness / 2;
        for (int t = 0; t < thickness; ++t) {
            for (int x = 0; x < width; ++x) {
                if (y - thickness / 2 + t >= 0 && y - thickness / 2 + t < height) {
                    bytesARR[y - thickness / 2 + t][x] = color;
                }
                if (y + thickness / 2 + t >= 0 && y + thickness / 2 + t < height) {
                    bytesARR[y + thickness / 2 + t][x] = color;
                }
            }
        }
    }
}