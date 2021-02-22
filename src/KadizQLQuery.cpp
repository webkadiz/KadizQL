#include <iostream>
#include "../include/KadizQLQuery.h"

using namespace std;
using namespace KadizQL;

void Query::insert(string tableName, vector<variant<int, float, string>> fields) {
    for (variant<int, float, string> field: fields) {
        // cout << field;
    }
}
