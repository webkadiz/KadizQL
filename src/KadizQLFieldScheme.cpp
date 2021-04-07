#include <iostream>
#include "../include/KadizQLFieldScheme.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

const vector<string> FieldScheme::TYPES = {"INT", "FLOAT", "TEXT", "DATE"};

FieldScheme::FieldScheme(vector<string> params) {
    this->_isNotNull = false;
    this->_isDefault = false;
    this->_isAutoIncrement = false;
    this->_isPrimaryKey = false;
    this->paramIter = 0;
    this->params = params;
    this->processParams();
}

size_t FieldScheme::getEncodedSize() {
    if (type == "INT") return 4;
    else if (type == "TEXT") return 255;
}

vector<string> FieldScheme::getParams() {
    return this->params;
}

vector<string> FieldScheme::getProcessedParams() {
    return this->processedParams;
}

void FieldScheme::processParams() {
    if (this->paramIter > this->params.size()) return;
    
    try {
        this->processName();
        this->processType();
        this->processNotNull();
        this->processDefault();
        this->processAutoIncrement();
        this->processPrimaryKey();
    } catch(std::out_of_range &e) {
        throw e;
    } catch(std::exception &e) {
        throw e;
    }
}

void FieldScheme::processName() {
    try {
        string param = this->params.at(this->paramIter);

        param = toUpperCase(param);
        this->processedParams.push_back(param);
        this->name = param;
        this->paramIter++;
    } catch(std::out_of_range &e) {
        cerr << "set name for column";

        throw e;
    }
}

void FieldScheme::processType() {
    try {
        string param = this->params.at(this->paramIter);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        for (string type: TYPES) {
            if (param.find(type) == 0) {
                this->type = type;
                break;
            }
        }

        if (this->type.empty()) {
            throw std::exception();
        }

        this->paramIter++;
    } catch(std::out_of_range &e) {
        cerr << "set type for column";

        throw e;
    } catch(std::exception &e) {
        cerr << "such type doesn't exists";

        throw e;
    }
}

void FieldScheme::processNotNull() {
    try {
        string param = this->params.at(this->paramIter);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param == "NOT NULL") {
            this->_isNotNull = true;
            this->paramIter++;
        }
    } catch(std::out_of_range &e) {}
}

void FieldScheme::processDefault() {
    try {
        string param = this->params.at(this->paramIter);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param.find("DEFAULT") == 0) {
            this->_isDefault = true;
            this->paramIter++;
        }
    } catch(std::out_of_range &e) {}
}

void FieldScheme::processAutoIncrement() {
    try {
        string param = this->params.at(this->paramIter);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param.find("AUTO INCREMENT") == 0) {
            this->_isAutoIncrement = true;
            this->paramIter++;
        }
    } catch(std::out_of_range &e) {}
}

void FieldScheme::processPrimaryKey() {
    try {
        string param = this->params.at(this->paramIter);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param.find("PRIMARY KEY") == 0) {
            this->_isPrimaryKey = true;
            this->paramIter++;
        }
    } catch(std::out_of_range &e) {}
}

string FieldScheme::getName() {
    return this->name;
}

string FieldScheme::getType() {
    return this->type;
}

bool FieldScheme::isNotNull() {
    return this->_isNotNull;
}

bool FieldScheme::isDefault() {
    return this->_isDefault;
}

bool FieldScheme::isAutoIncrement() {
    return this->_isAutoIncrement;
}

bool FieldScheme::isPrimaryKey() {
    return this->_isPrimaryKey;
}
