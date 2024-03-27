#include "validate_args.h"


bool validateArgs(std::string functionName, std::unordered_map<std::string, std::string> argsMap) {
    if (functionName == MIRROR) {
        return mirrorValidation(argsMap);
    }
    if (functionName == COPY) {
        return copyValidation(argsMap);
    }
    if (functionName == COLOR_REPLACE) {
        return replaceValidation(argsMap);
    } 
    if (functionName == SPLIT) {
        return splitValidation(argsMap);
    }
    std::cerr << "Function validateArgs took unknown param. Egor, fix it\n";
    return false;
}

bool isValidCoords(const std::string& str) {
    std::regex pattern("^\\d+\\.\\d+$");

    return std::regex_match(str, pattern);
}

bool isValidColor(const std::string& str) {
    std::istringstream iss(str);
    std::string token;
    int count = 0;

    while (std::getline(iss, token, '.')) {
        if (!token.empty() && token.find_first_not_of("0123456789") == std::string::npos) {
            int value = std::stoi(token);
            if (value < 0 || value > 255) {
                return false;
            }
        } else {
            return false;
        }
        count++;
    }

    return count == 3;
}

bool isValidNumber(const std::string& str) {
    try {
        int value = std::stoi(str);
        return value >= 1;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

bool mirrorValidation(std::unordered_map<std::string, std::string> argsMap) {
    bool isCool = true;
    if (argsMap[AXIS] != "x" and argsMap[AXIS] != "y") {
        isCool = false;
        std::cout << "Axis must be 'x' or 'y'\n";
    }
    if (!isValidCoords(argsMap[LEFT_UP])) {
        isCool = false;
        std::cout << "left_up must be two int numbers in this form: X.Y\n";
    }
    if (!isValidCoords(argsMap[RIGHT_DOWN])) {
        isCool = false;
        std::cout << "right_down must be two int numbers in this form: X.Y\n";
    }
    return isCool;
}

bool copyValidation(std::unordered_map<std::string, std::string> argsMap) {
    bool isCool = true;
    if (!isValidCoords(argsMap[LEFT_UP])) {
        isCool = false;
        std::cout << "left_up must be two int numbers in this form: X.Y\n";
    }
    if (!isValidCoords(argsMap[RIGHT_DOWN])) {
        isCool = false;
        std::cout << "right_down must be two int numbers in this form: X.Y\n";
    }
    if (!isValidCoords(argsMap[RIGHT_DOWN])) {
        isCool = false;
        std::cout << "dest_left_up must be two int numbers in this form: X.Y\n";
    }
    return isCool;
}

bool replaceValidation(std::unordered_map<std::string, std::string> argsMap) {
    bool isCool = true;
    if (!isValidColor(argsMap[OLD_COLOR])) {
        isCool = false;
        std::cout << "old_color must be rrr.ggg.bbb format\n";
    }
    if (!isValidColor(argsMap[NEW_COLOR])) {
        isCool = false;
        std::cout << "new color myst be rrr.ggg.bbb format\n";
    }
    return isCool;
}

bool splitValidation(std::unordered_map<std::string, std::string> argsMap) {
    bool isCool = true;
    if (!isValidNumber(argsMap[NUMBER_X])) {
        isCool = false;
        std::cout << "number_x must be integer greater than 1\n";
    }
    if (!isValidNumber(argsMap[NUMBER_Y])) {
        isCool = false;
        std::cout << "number_y must be integer greater than 1\n";
    }
    if (!isValidNumber(argsMap[THICKNESS])) {
        isCool = false;
        std::cout << "thickness must be integer greater than 1\n";
    }
    if (!isValidColor(argsMap[COLOR])) {
        isCool = false;
        std::cout << "color must be rrr.ggg.bbb format";
    }
    return isCool;
}