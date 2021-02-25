#include <iostream>
#include <string>
#include <vector>
#include "../include/CSVParser.h"
#include "../include/utils.h"

void CSVParser::prepare() {
	this->table.clear();
	this->row.clear();
	this->token.clear();
	this->tokenType = "common";
	this->pos = 0;
	this->processLoopState = CSVParser::NOT_WAS_WORK;
}

std::vector<std::vector<std::string>>
CSVParser::parse(std::string parseText) {
	this->prepare();
	this->parseText = parseText;
	std::size_t parseTextLen = parseText.size();

	while(this->pos < parseTextLen) {
		try {
			this->processStringTokenQuote();
		} catch(std::exception& e) {
			std::cerr << this->stringTokenQuoteError();
			throw std::exception();
		}
		this->processStringTokenComma();
		this->processStringTokenNewline();
		try {
			this->processCommonTokenQuote();
		} catch(std::exception& e) {
			std::cerr << this->commonTokenQuoteError();
			throw std::exception();
		}
		this->processCommonTokenComma();
		this->processCommonTokenNewline();
		this->processDefault();
		this->setNotWorkState();
	}

	if (this->textEndIsNewline() == false) {
		std::cerr << this->textEndNewlineError();
		throw std::exception();
	}

	return this->table;
}

int CSVParser::getPos() {
	return this->pos;
}

char CSVParser::getPrevChar() {
	return this->parseText[this->pos - 1];
}

char CSVParser::getCurChar() {
	return this->parseText[this->pos];
}

char CSVParser::getNextChar() {
	return this->parseText[this->pos + 1];
}

void CSVParser::incPos() {
	this->pos++;
}

void CSVParser::addCurCharToToken() {
	this->token += this->getCurChar();
}

bool CSVParser::tokenIsCommon() {
	if (this->tokenType == "common") return true;
	else return false;
}

bool CSVParser::tokenIsString() {
	if (this->tokenType == "string") return true;
	else return false;
}

void CSVParser::setTokenToCommon() {
	this->tokenType = "common";
}

void CSVParser::setTokenToString() {
	this->tokenType = "string";
}

void CSVParser::setWorkState() {
	this->processLoopState = CSVParser::WAS_WORK;
}

void CSVParser::setNotWorkState() {
	this->processLoopState = CSVParser::NOT_WAS_WORK;
}

void CSVParser::processStringTokenQuote() {
	if (this->tokenIsString() && this->getCurChar() == '"') {
		this->setWorkState();

		if (this->getNextChar() == ',') {
			this->setTokenToCommon();
			this->row.push_back(this->token);
			this->token.clear();
			this->incPos();
			this->incPos();
		} else if (this->getNextChar() == '\n') { 
			this->setTokenToCommon();
			this->row.push_back(this->token);
			this->table.push_back(this->row);
			this->row.clear();
			this->token.clear();
			this->incPos();
			this->incPos();
		} else if (this->getNextChar() == '"') {
			this->addCurCharToToken();
			this->incPos();
			this->incPos();
		} else {
			throw std::exception();
		}
	}
}

void CSVParser::processStringTokenComma() {
	if (this->tokenIsString() && this->getCurChar() == ',') {
		this->setWorkState();
		this->addCurCharToToken();
		this->incPos();
	}
}

void CSVParser::processStringTokenNewline() {
	if (this->tokenIsString() && this->getCurChar() == '\n') {
		this->setWorkState();
		this->addCurCharToToken();
		this->incPos();
	}
}

void CSVParser::processCommonTokenQuote() {
	if (this->tokenIsCommon() && this->getCurChar() == '"') {	
		this->setWorkState();
		if (
			this->pos == 0 ||
			this->getPrevChar() == ',' ||
			this->getPrevChar() == '\n'
		) {
			this->setTokenToString();
			this->incPos();
		} else {
			throw std::exception();
		}
	}
}

void CSVParser::processCommonTokenComma() {
	if (this->tokenIsCommon() && this->getCurChar() == ',') {
		this->setWorkState();
		this->row.push_back(this->token);
		this->token.clear();
		this->incPos();
	}
}

void CSVParser::processCommonTokenNewline() {
	if (this->tokenIsCommon() && this->getCurChar() == '\n') {
		this->setWorkState();
		this->row.push_back(this->token);
		this->table.push_back(row);
		this->token.clear();
		this->row.clear();
		this->incPos();
	}
}

void CSVParser::processDefault() {
	if (this->processLoopState == CSVParser::NOT_WAS_WORK) {
		this->addCurCharToToken();
		this->incPos();
	}
}

bool CSVParser::textEndIsNewline() {
	if (this->parseText[this->parseText.size() - 1] == '\n')
		return true;
	else return false;
}

std::string CSVParser::commonTokenQuoteError() {
	std::string error;
	std::string caretShift;
	
	error += getContextForErrorMsg(this->pos, this->parseText);
	error += "\n";

	caretShift = repeat_string(" ", pos - 1);

	error += caretShift;
	error += "^\n";
	error += "CSV Syntax Error: here must be ',' or newline\n";

	return error;
}

std::string CSVParser::stringTokenQuoteError() {
	std::string error;
	std::string caretShift;
			
	error += getContextForErrorMsg(this->pos, this->parseText);
	error += "\n";

	caretShift = repeat_string(" ", pos + 1);

	error += caretShift; 
	error += "^\n";
	error += "CSV Syntax Error: here must be ',' or newline\n";

	return error;
}

std::string CSVParser::textEndNewlineError() {
	std::string error;
	std::string caretShift;

	error += getContextForErrorMsg(this->pos, this->parseText);			
	error += "\n";

	caretShift = repeat_string(" ", pos);

	error += caretShift; 
	error += "^\n";
	error += "CSV Syntax Error: text must be ended on newline\n";

	return error;
}
