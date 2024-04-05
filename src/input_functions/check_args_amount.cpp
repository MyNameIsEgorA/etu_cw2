#include "check_args_amount.h"

struct option long_options[] = {
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"info", no_argument, 0, 0},
        {"help", no_argument, 0, 'h'},
        {"mirror", no_argument, 0, 0},
        {"axis", required_argument, 0, 0},
        {"left_up", required_argument, 0, 0},
        {"right_down", required_argument, 0, 0},
        {"copy", no_argument, 0, 0},
        {"dest_left_up", required_argument, 0, 0},
        {"color_replace", no_argument, 0, 0},
        {"old_color", required_argument, 0, 0},
        {"new_color", required_argument, 0, 0},
        {"split", no_argument, 0, 0},
        {"number_x", required_argument, 0, 0},
        {"number_y", required_argument, 0, 0},
        {"thickness", required_argument, 0, 0},
        {"color", required_argument, 0, 0}, 
        {0, 0, 0, 0},
};

std::unordered_map<std::string, std::string> getParams(int argc, char** argv) {
    int opt;
    std::string option_name;
    std::unordered_map<std::string, std::string> argsMap;

    int option_index = 0;
    bool exit_check = 0;
    opterr = 0;  // устанавливается, чтобы не было выводов в консоль при getopt_long

    while ((opt = getopt_long(argc, argv, "i:o:h", long_options, &option_index)) != -1) {
        if (opt == '?') {
            std::cerr << "Unknown argument: " << argv[optind - 1] << std::endl;
            exit_check = true;
            continue;
        }

        if (opt == 'i') {
            option_name = "input";
        } else if (opt == 'o') {
            option_name = "output";
        } else {
            option_name = long_options[option_index].name;
        }

        if (optarg) {
            argsMap.insert(std::make_pair(option_name, optarg));
        } else {
            argsMap.insert(std::make_pair(option_name, ""));
        }
    }

    if (argsMap.find("input") == argsMap.end()) {
        if (optind < argc) {
            argsMap.insert(std::make_pair("input", argv[argc - 1]));
        } else {
            std::cerr << "Missing input file." << std::endl;
            exit_check = true;
        }
    }

    if (exit_check) {
        std::cout << LOST_PARAMS;
        std::cout << USE_HELP;
        exit(0);
    }
    return argsMap;
}