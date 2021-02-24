#include <fstream>
#include <string>
#include "../include/utils.h"

using namespace std;

string repeat_string(string str, int n) {
    string repeated_str;

    for (int i = 0; i < n; i++) {
        repeated_str += str;
    }

    return repeated_str;
}

int getStartForErrorMsg(int curPos, string parseText) {
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

int getEndForErrorMsg(int curPos, string parseText) {
	int end = curPos;
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

string getContextForErrorMsg(int curPos, string parseText) {
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
