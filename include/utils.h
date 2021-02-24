#pragma once

#include <fstream>
#include <string>

using namespace std;

string repeat_string(string, int);
int getStartForErrorMsg(int, string);
int getEndForErrorMsg(int, string);
string getContextForErrorMsg(int, string);
string toUpperCase(string);
string readFile(ifstream &);
string readLine(ifstream &);