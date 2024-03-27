#include <unordered_map>
#include <string>

#include "check_args_amount.h"
#include "consts.h"
#include "validate_args.h"
#include "print_functions.h"

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
    }

    if (functionToCall == INFO) {
        
    }
    
    if (!validateArgs(functionToCall, argsMap)) {
        std::cout << "Please use flags correctly\n";
        return 1;
    }

    return 0;
}