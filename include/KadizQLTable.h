#pragma once
#include <string>
#include <vector>
#include "KadizQLFieldScheme.h"
#include "KadizQLField.h"
#include "KadizQLTableScheme.h"
#include "KadizQLResult.h"
#include "KadizQLRow.h"

using namespace std;
using namespace KadizQL;

namespace KadizQL {
    class Table {
    private:
        string tableName;
        TableScheme tableScheme;
    public:
        Table(string);
        bool create(vector<vector<string>>);
        void createScheme(vector<vector<string>>);
        void createStorage();
        fs::path getTableDir();
        void loadScheme();
        Result select(vector<string>);
        Result insert(Row &);
    };
}

