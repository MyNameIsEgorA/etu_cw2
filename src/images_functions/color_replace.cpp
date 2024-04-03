#include "color_replace.h"

void changeColors(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap) {
    int width = infoHeader.width;
    int height = infoHeader.height;

    Pixel old_color_rgb = parsePixel(argsMap["old_color"]);
    Pixel new_color_rgb = parsePixel(argsMap["new_color"]);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (old_color_rgb == bytesARR[i][j]) {
                bytesARR[i][j] = new_color_rgb;
            } 
        }
    }
}