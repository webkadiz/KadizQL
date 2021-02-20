#pragma once

#include <string>

std::string repeat_string(std::string, int);
int getStartForErrorMsg(int, std::string);
int getEndForErrorMsg(int, std::string);
std::string getContextForErrorMsg(int, std::string);