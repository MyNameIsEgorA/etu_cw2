#include <unordered_map>
#include <string>

#include "check_args_amount.h"
#include "consts.h"
#include "validate_args.h"
#include "print_functions.h"
#include "getFileInfo.h"
#include "color_replace.h"
#include "imageStructs.h"
#include "new_file.h"

int main(int argc, char** argv) {
    std::unordered_map<std::string, std::string> argsMap = getParams(argc, argv);
    if (argc < 2) {
        std::cout << "Please enter flags\n";
        std::cout << USE_HELP;
        return 1;
    }
    std::string functionToCall = findFlag(argv[1], argsMap);
    if (functionToCall == "incorrect") {
        return 1;
    }

    if (functionToCall == HELP) {
        printHelp();
        return 0;
    }
    
    if (!validateArgs(functionToCall, argsMap)) {
        std::cout << "Please use flags correctly\n";
        return 1;
    }

    std::vector<std::vector<Pixel>> bitArr;

    BMPHeader header;
    BMPInfoHeader infoHeader;

    try {
        bitArr = readBMP(argsMap[INPUT], header, infoHeader);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what();
    }

    if (functionToCall == INFO) {
        printFileInfo(infoHeader);
        return 0;
    }

    if (functionToCall == COLOR_REPLACE) {
        changeColors(infoHeader, bitArr, argsMap);
    }

    writeBMP(argsMap["output"], header, infoHeader, bitArr);

    return 0;
}