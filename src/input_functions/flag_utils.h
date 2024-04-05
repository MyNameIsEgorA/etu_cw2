#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

#include "../consts.h"

std::string findFunctionToRun(std::string firstFlag, std::unordered_map<std::string, std::string> flags);
std::vector<std::string> getExtraKeys(const std::unordered_map<std::string, std::string>& argsMap, const std::vector<std::string>& keys);
void removeKeysFromVector(std::unordered_map<std::string, std::string>& argsMap, std::vector<std::string>& keys);
bool isCorrect(std::vector<std::string>& flagsArr, std::unordered_map<std::string, std::string> argsMap);