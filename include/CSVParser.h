#pragma once

#include <string>
#include <vector>

class CSVParser {
private:
    static const int WAS_WORK = 1;
    static const int NOT_WAS_WORK = 0;
    std::string parseText;
    std::string token;
    std::string tokenType;
    std::vector<std::string> row;
    std::vector<std::vector<std::string>> table;
    size_t pos;
    int processLoopState;
    
public:
    void prepare();
    std::vector<std::vector<std::string>> parse(std::string);
    int getPos();
    char getPrevChar();
    char getCurChar();
    char getNextChar();
    void incPos();
    void addCurCharToToken();
    bool tokenIsCommon();
    bool tokenIsString();
    void setTokenToCommon();
    void setTokenToString();
    void setWorkState();
    void setNotWorkState();

    void processStringTokenQuote();
    void processStringTokenComma();
    void processStringTokenNewline();
    void processCommonTokenQuote();
    void processCommonTokenComma();
    void processCommonTokenNewline();
    void processDefault();

    bool textEndIsNewline();

    std::string commonTokenQuoteError();
    std::string stringTokenQuoteError();
    std::string textEndNewlineError();
};