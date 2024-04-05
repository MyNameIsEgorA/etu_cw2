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

    // Проверяем, есть ли флаг --input в argsMap
    if (argsMap.find("input") == argsMap.end()) {
        // Если нет, то добавляем последний элемент из argv как значение для --input
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

void removeKeysFromVector(std::unordered_map<std::string, std::string>& argsMap, std::vector<std::string>& keys) {
    keys.erase(std::remove_if(keys.begin(), keys.end(),
        [&argsMap](const std::string& key) {
            return argsMap.find(key) != argsMap.end();
        }), keys.end());
}

std::string findFunctionToRun(std::string firstFlag, std::unordered_map<std::string, std::string> flags) {

    std::vector<std::string> mirrorFlags  = {"mirror", "axis", "left_up", "right_down", "input", "output"};
    std::vector<std::string> copyFlags    = {"copy", "left_up", "right_down", "dest_left_up", "input", "output"};
    std::vector<std::string> replaceFlags = {"color_replace", "old_color", "new_color", "input", "output"};
    std::vector<std::string> splitFlags   = {"split", "number_x", "number_y", "thickness", "color", "input", "output"};
    std::vector<std::string> infoFlags    = {"info", "input"};

    if (firstFlag == "--help" or firstFlag == "-h") {
        return HELP;
    }
    if (firstFlag == "--info") {
        if (isCorrect(infoFlags, flags)) {
            return INFO;
        }
    }
    if (firstFlag == "--mirror") {
        if (isCorrect(mirrorFlags, flags)) {
            return MIRROR;
        }
    }
    if (firstFlag == "--copy") {
        if (isCorrect(copyFlags, flags)) {
            return COPY;
        }
    }
    if (firstFlag == "--color_replace") {
        if (isCorrect(replaceFlags, flags)) {
            return COLOR_REPLACE;
        }
    }
    if (firstFlag == "--split") {
        if (isCorrect(splitFlags, flags)) {
            return SPLIT;
        }
    }
    return INCORRECT;
}

std::vector<std::string> getExtraKeys(const std::unordered_map<std::string, std::string>& argsMap, const std::vector<std::string>& keys) {
    std::vector<std::string> extraKeys;
    for (const auto& kv : argsMap) {
        if (std::find(keys.begin(), keys.end(), kv.first) == keys.end()) {
            extraKeys.push_back(kv.first);
        }
    }
    return extraKeys;
}

bool isCorrect(std::vector<std::string>& flagsArr, std::unordered_map<std::string, std::string> argsMap) {

    bool isCorrect = true;

    std::vector<std::string> extraKeys = getExtraKeys(argsMap, flagsArr);

    if (extraKeys.size()) {
        isCorrect = false;
    }

    removeKeysFromVector(argsMap, flagsArr);
    if (flagsArr.size()) {
        isCorrect = false;
        for (const auto& item: extraKeys) {
            std::cout << "You have an extra flag <" << item << ">. This function doesn't use it" << std::endl;
        }
    }

    for (const auto& flag : flagsArr) {
        std::cout << "Your function must also have <--" << flag << "> flag" << std::endl;
    } 
    
    if (isCorrect) {
        return true;
    }

    std::cout << USE_HELP << std::endl;

    return false;
}