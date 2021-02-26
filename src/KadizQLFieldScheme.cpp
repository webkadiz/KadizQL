#include <iostream>
#include "../include/KadizQLFieldScheme.h"
#include "../include/utils.h"

using namespace std;
using namespace KadizQL;

const vector<string> FieldScheme::TYPES = {"INT", "FLOAT", "VARCHAR", "TEXT", "DATE"};

FieldScheme::FieldScheme() {
    this->_isNotNull = false;
    this->_isDefault = false;
    this->_isAutoIncrement = false;
    this->_isPrimaryKey = false;
}

FieldScheme::FieldScheme(vector<string> params) : FieldScheme() {
    this->params = params;
}

vector<string> FieldScheme::getParams() {
    return this->params;
}

vector<string> FieldScheme::getProcessedParams() {
    return this->processedParams;
}

void FieldScheme::processParams() {
    int paramIdx = 0;

    try {
        this->processName(paramIdx);
        this->processType(paramIdx);
        this->processNotNull(paramIdx);
        this->processDefault(paramIdx);
        this->processAutoIncrement(paramIdx);
        this->processPrimaryKey(paramIdx);
    } catch(std::out_of_range &e) {
        throw e;
    } catch(std::exception &e) {
        throw e;
    }
}

void FieldScheme::processName(int &idx) {
    try {
        string param = this->params.at(idx);

        param = toUpperCase(param);
        this->processedParams.push_back(param);
        this->name = param;
        idx++;
    } catch(std::out_of_range &e) {
        cerr << "set name for column";

        throw e;
    }
}

void FieldScheme::processType(int &idx) {
    try {
        string param = this->params.at(idx);

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

        idx++;
    } catch(std::out_of_range &e) {
        cerr << "set type for column";

        throw e;
    } catch(std::exception &e) {
        cerr << "such type doesn't exists";

        throw e;
    }
}

void FieldScheme::processNotNull(int &idx) {
    try {
        string param = this->params.at(idx);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param == "NOT NULL") {
            this->_isNotNull = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}

void FieldScheme::processDefault(int &idx) {
    try {
        string param = this->params.at(idx);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param.find("DEFAULT") == 0) {
            this->_isDefault = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}

void FieldScheme::processAutoIncrement(int &idx) {
    try {
        string param = this->params.at(idx);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param.find("AUTO INCREMENT") == 0) {
            this->_isAutoIncrement = true;
            idx++;
        }
    } catch(std::out_of_range &e) {}
}

void FieldScheme::processPrimaryKey(int &idx) {
    try {
        string param = this->params.at(idx);

        param = toUpperCase(param);
        this->processedParams.push_back(param);

        if (param.find("PRIMARY KEY") == 0) {
            this->_isPrimaryKey = true;
            idx++;
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
