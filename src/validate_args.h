#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <regex>

#include "consts.h"

bool isValidCoords(const std::string& str);
bool isValidColor(const std::string& str);
bool isValidNumber(const std::string& str);
bool validateArgs(std::string functionName, std::unordered_map<std::string, std::string> argsMap);
bool mirrorValidation(std::unordered_map<std::string, std::string> argsMap);
bool copyValidation(std::unordered_map<std::string, std::string> argsMap);
bool replaceValidation(std::unordered_map<std::string, std::string> argsMap);
bool splitValidation(std::unordered_map<std::string, std::string> argsMap);