#include "copy_part.h"

void copyPartOfImage(BMPInfoHeader infoHeader, std::vector<std::vector<Pixel>> &bytesARR, std::unordered_map<std::string, std::string> argsMap) {
    int x_start;
    int x_end;
    int y_start;
    int y_end;
    int copy_x;
    int copy_y;

    try {
        getCoords(argsMap["left_up"], &x_start, &y_start);
        getCoords(argsMap["right_down"], &x_end, &y_end);
        getCoords(argsMap["dest_left_up"], &copy_x, &copy_y);
    } catch (const std::exception& e) {
        std::cerr << "Error while running programm:\n" << e.what() << std::endl;
    }

    makeCooler(x_start, y_start, x_end, y_end, infoHeader);

    std::vector<std::vector<Pixel>> copyedArr;

    for (int i = infoHeader.height - y_end; i < infoHeader.height - y_start; i++) {
        std::vector<Pixel> copyLine;
        for (int j = x_start; j < x_end; j++) {
            copyLine.push_back(bytesARR[i][j]);
        }
        copyedArr.push_back(copyLine);
    }

    for (int i = copy_y; i < copy_y + y_end - y_start; i++) {
        for (int j = copy_x; j < copy_x + x_end - x_start; j++) {
            if (i < bytesARR.size() and j < bytesARR[i].size()) {
                bytesARR[i][j] = copyedArr[i - copy_y][j - copy_x];
            }
        }
    }
}