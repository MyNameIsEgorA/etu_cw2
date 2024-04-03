#include "parsing_fucntions.h"

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