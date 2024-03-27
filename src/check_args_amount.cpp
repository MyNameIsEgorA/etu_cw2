#include "check_args_amount.h"

struct option long_options[] = {
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"info", no_argument, 0, 'n'},
        {"help", no_argument, 0, 'h'},
        {"mirror", no_argument, 0, 'm'},
        {"axis", required_argument, 0, 'a'},
        {"left_up", required_argument, 0, 'l'},
        {"right_down", required_argument, 0, 'r'},
        {"copy", no_argument, 0, 0},
        {"dest_left_up", required_argument, 0, 0},
        {"color_replace", required_argument, 0, 0},
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
    std::unordered_map<std::string, std::string> options;

    int option_index = 0;
    bool exit_check = 0;
    opterr = 0;  // устанавливается, чтобы не было выводов в консоль при getopt_long

    while ((opt = getopt_long(argc, argv, "i:o:h", long_options, &option_index)) != -1) {

        if (opt == '?') {
            std::cerr << "Unknown argument: " << argv[optind - 1] << std::endl;
            exit_check = true;
            continue;
        }

        option_name = long_options[option_index].name;
        if (optarg) {
            options.insert(std::make_pair(option_name, optarg));
        } else {
            options.insert(std::make_pair(option_name, ""));
        }
    }

    if (exit_check) {
        std::cout << LOST_PARAMS;
        std::cout << USE_HELP;
        exit(0);
    }
    return options;
}

void removeKeysFromVector(std::unordered_map<std::string, std::string>& map, std::vector<std::string>& keys) {
    keys.erase(std::remove_if(keys.begin(), keys.end(),
        [&map](const std::string& key) {
            return map.find(key) != map.end();
        }), keys.end());
}

std::string findFlag(std::string firstFlag, std::unordered_map<std::string, std::string> flags) {

    std::vector<std::string> mirrorFlags  = {"mirror", "axis", "left_up", "right_down", "input", "output"};
    std::vector<std::string> copyFlags    = {"copy", "left_up", "right_down", "dest_left_up", "input", "output"};
    std::vector<std::string> replaceFlags = {"color_replace", "old_color", "new_color", "input", "output"};
    std::vector<std::string> splitFlags   = {"split", "number_x", "number_y", "thickness", "color", "input", "output"};

    if (firstFlag == "-help" or firstFlag == "-h") {
        return HELP;
    }
    if (firstFlag == "-info" or firstFlag == "-i") {
        return INFO;
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

std::vector<std::string> getExtraKeys(const std::unordered_map<std::string, std::string>& map, const std::vector<std::string>& keys) {
    std::vector<std::string> extraKeys;
    for (const auto& kv : map) {
        if (std::find(keys.begin(), keys.end(), kv.first) == keys.end()) {
            extraKeys.push_back(kv.first);
        }
    }
    return extraKeys;
}

bool isCorrect(std::vector<std::string>& flagsArr, std::unordered_map<std::string, std::string> flags) {

    bool isCorrect = true;

    std::vector<std::string> extraKeys = getExtraKeys(flags, flagsArr);

    if (extraKeys.size()) {
        isCorrect = false;
    }

    removeKeysFromVector(flags, flagsArr);
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