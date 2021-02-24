#pragma once
#include <string>
#include <vector>
#include "KadizQLFieldScheme.h"

using namespace std;
using namespace KadizQL;

namespace KadizQL {
    class Table {
    private:
        string tableName;
        vector<FieldScheme *> schema;
    public:
        Table(string);
        bool create(vector<vector<string>>);
        void createScheme(vector<vector<string>>);
        void createStorage();
        fs::path getTableDir();
        void load();
        void select();
    };
}

