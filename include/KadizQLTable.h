#pragma once
#include <string>
#include <vector>
#include "KadizQLFieldScheme.h"
#include "KadizQLField.h"
#include "KadizQLTableScheme.h"
#include "KadizQLResult.h"
#include "KadizQLRow.h"
#include "Condition.h"
#include "ConditionTrue.h"

using namespace std;
using namespace KadizQL;

namespace KadizQL {
    class Table {
    private:
        string tableName;
        TableScheme tableScheme;
        bool tableShemeLoaded;
    public:
        Table(string);
        bool create(vector<vector<string>>);
        void createScheme(vector<vector<string>>);
        void createStorage();
        fs::path getTableDir();
        string getTableDataBasename();
        void loadScheme();
        void clearData();
        size_t getRowsCount();
        Row readRow(size_t);
        Row selectFromRow(Row &, vector<string> &);
        Result select(vector<string>, Condition *cond = new ConditionTrue());
        Result insert(Row &);
        Result update(string, Field *, Condition *cond = new ConditionTrue());
        Result remove(Condition *cond = new ConditionTrue());
    };
}

