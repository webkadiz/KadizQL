#include "utils.h"

std::string repeat_string(std::string str, int n) {
    std::string repeated_str;

    for (int i = 0; i < n; i++) {
        repeated_str += str;
    }

    return repeated_str;
}

int getStartForErrorMsg(int curPos, std::string parseText) {
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

int getEndForErrorMsg(int curPos, std::string parseText) {
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

std::string getContextForErrorMsg(int curPos, std::string parseText) {
    int start = getStartForErrorMsg(curPos, parseText);
    int end = getEndForErrorMsg(curPos, parseText);

    return parseText.substr(start, end);
}
