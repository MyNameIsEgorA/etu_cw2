#include <getopt.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

#include "../consts.h"

std::unordered_map<std::string, std::string> getParams(int argc, char** argv);
std::string findFunctionToRun(std::string firstFlag, std::unordered_map<std::string, std::string> flags);
bool isCorrect(std::vector<std::string>& flagsArr, std::unordered_map<std::string, std::string> flags);
void removeKeysFromVector(std::unordered_map<std::string, std::string>& map, std::vector<std::string>& keys);
std::vector<std::string> getExtraKeys(const std::unordered_map<std::string, std::string>& map, const std::vector<std::string>& keys);