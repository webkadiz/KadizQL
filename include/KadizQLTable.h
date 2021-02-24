#pragma once
#include <string>
#include <vector>
#include "KadizQLFieldScheme.h"
#include "KadizQLField.h"

using namespace std;
using namespace KadizQL;

namespace KadizQL {
    class Table {
    private:
        string tableName;
        vector<FieldScheme *> tableScheme;
    public:
        Table(string);
        bool create(vector<vector<string>>);
        void createScheme(vector<vector<string>>);
        void createStorage();
        fs::path getTableDir();
        void load();
        Field *select(vector<string>);
    };
}

