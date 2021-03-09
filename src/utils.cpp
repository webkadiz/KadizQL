#include <fstream>
#include <string>
#include <iostream>
#include "../include/utils.h"
#include "../include/KadizQLField.h"

using namespace std;
using namespace KadizQL;

string repeat_string(string str, int n) {
    string repeated_str;

    for (int i = 0; i < n; i++) {
        repeated_str += str;
    }

    return repeated_str;
}

int getStartForErrorMsg(size_t curPos, string parseText) {
    int start = curPos;
	while(true) {
		if (
			start == 0 ||
			parseText[start] == '\n' ||
			curPos - start > 10
		) break;
		start--;
	}

    return start;
}

int getEndForErrorMsg(size_t curPos, string parseText) {
	size_t end = curPos;
	while(true) {
		if (
			end == parseText.size() ||
			parseText[end] == '\n' ||
			end - curPos > 10
		) break;
		end++;
	}
    
    return end;
}

string getContextForErrorMsg(size_t curPos, string parseText) {
    int start = getStartForErrorMsg(curPos, parseText);
    int end = getEndForErrorMsg(curPos, parseText);

    return parseText.substr(start, end);
}

string toUpperCase(string str) {
	string upperStr;

	for (char c: str) {
		upperStr += toupper(c);
	}

	return upperStr;
}


string readFile(ifstream &file) {
	string text;
	char c;

	while(file.get(c)) {
		text += c;
	}

	return text;
}

string readLine(ifstream &file) {
	string text;
	char c;

	while(file.get(c)) {
		text += c;
		if (c == '\n') break;
	}

	return text;
}

void testPassed(size_t &testCount) {
	testCount++;
	cout << "test " << testCount << " passed" << endl;
}

void testFailed(size_t &testCount) {
	testCount++;
	cout << "test " << testCount << " failed" << endl;
	exit(testCount);
}
