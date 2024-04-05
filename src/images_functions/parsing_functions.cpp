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


void getCoords(const std::string& str, int* x, int* y) {
    if (x == nullptr || y == nullptr) {
        return;
    }

    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos) {
        throw std::invalid_argument(COORDS_EXCEPTION);
        return;
    }

    try {
        *x = std::stoi(str.substr(0, dotPos));
        *y = std::stoi(str.substr(dotPos + 1));
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument("Invalid format: unable to convert substrings to integers");
    } catch (const std::out_of_range&) {
        throw std::out_of_range("Integer value out of range");
    }
}

void makeCooler(int& x_start, int& y_start, int& x_end, int& y_end, BMPInfoHeader infoHeader) {
    if (x_start < 0) {
        x_start = 0;
    }
    if (y_start < 0) {
        y_start = 0;
    }
    if (x_end > infoHeader.width) {
        x_end = infoHeader.width;
    }
    if (y_end > infoHeader.height) {
        y_end = infoHeader.height;
    }
}