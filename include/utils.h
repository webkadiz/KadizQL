#pragma once

#include <fstream>
#include <string>
#include "KadizQLField.h"

using namespace std;

string repeat_string(string, int);
int getStartForErrorMsg(size_t, string);
int getEndForErrorMsg(size_t, string);
string getContextForErrorMsg(size_t, string);
string toUpperCase(string);
string readFile(ifstream &);
string readLine(ifstream &);
void testPassed(size_t &);
void testFailed(size_t &);
template<typename T> T std::get(KadizQL::Field *field) {
    return std::get<T>(field->data());
}
