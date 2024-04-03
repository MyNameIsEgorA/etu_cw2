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

Pixel parsePixel(const std::string& colorString) {
    std::istringstream iss(colorString);
    std::string token;
    Pixel pixel;

    if (std::getline(iss, token, '.')) {
        pixel.red = std::stoi(token);
    }

    if (std::getline(iss, token, '.')) {
        pixel.green = std::stoi(token);
    }

    if (std::getline(iss, token, '.')) {
        pixel.blue = std::stoi(token);
    }

    return pixel;
}

bool operator==(const Pixel& old_color, const Pixel& current_color) {
    return old_color.blue == current_color.blue and old_color.green == current_color.green and old_color.red == current_color.red;
}