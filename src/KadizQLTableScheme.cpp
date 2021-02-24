#include "../include/KadizQLTableScheme.h"
using namespace std;
using namespace KadizQL;

void TableScheme::addFieldScheme(FieldScheme *fieldScheme) {
    this->fieldSchemes.push_back(fieldScheme);
}