#include "flag_utils.h"

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

void removeKeysFromVector(std::unordered_map<std::string, std::string>& argsMap, std::vector<std::string>& keys) {
    keys.erase(std::remove_if(keys.begin(), keys.end(),
        [&argsMap](const std::string& key) {
            return argsMap.find(key) != argsMap.end();
        }), keys.end());
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