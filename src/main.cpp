#include <unordered_map>
#include <string>

#include "input_functions/check_args_amount.h"
#include "input_functions/process_flags.h"
#include "input_functions/validate_args.h"
#include "print_functions.h"
#include "consts.h"
#include "images_functions/getFileInfo.h"
#include "images_functions/color_replace.h"
#include "images_functions/imageStructs.h"
#include "images_functions/new_file.h"
#include "images_functions/copy_part.h"
#include "images_functions/mirror.h"
#include "images_functions/split.h"

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << "Please enter flags\n";
        std::cout << USE_HELP;
        return 1;
    }

    std::unordered_map<std::string, std::string> argsMap = getParams(argc, argv);
    std::string functionToCall = findFunctionToRun(argv[1], argsMap);
    if (functionToCall == "incorrect") {
        return 1;
    }

    if (functionToCall == HELP) {
        printHelp();
        return 0;
    }
    
    if (!validateArgs(functionToCall, argsMap)) {
        return 1;
        std::cout << "Please use flags correctly\n";
    }

    std::vector<std::vector<Pixel>> bitArr;

    BMPHeader header;
    BMPInfoHeader infoHeader;

    try {
        bitArr = readBMP(argsMap[INPUT], header, infoHeader);
    } catch(const std::runtime_error& e) {
        std::cerr << e.what();
        return 0;
    }

    try {
        if (functionToCall == INFO) {
            printFileInfo(infoHeader);
            return 0;
        }

        if (functionToCall == COLOR_REPLACE) {
            changeColors(infoHeader, bitArr, argsMap);
        }

        if (functionToCall == COPY) {
            copyPartOfImage(infoHeader, bitArr, argsMap);
        }

        if (functionToCall == MIRROR) {
            mirror(infoHeader, bitArr, argsMap);       
        }

        if (functionToCall == SPLIT) {
            split(infoHeader, bitArr, argsMap);
        }

        writeBMP(argsMap["output"], header, infoHeader, bitArr);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::cout << "Program didn't finished successfully\n";
    }

    return 0;
}