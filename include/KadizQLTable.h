#pragma once
#include <string>
#include <vector>
#include "KadizQLColumnScheme.h"

using namespace std;
using namespace KadizQL;

namespace KadizQL {
    class Table {
    private:
        string tableName;
        // vector<ColumnScheme *> ;
    public:
        Table(string);
        bool create(vector<vector<string>>);
        std::string readTableFromFile(std::string filename);
        void createScheme(vector<vector<string>>);
        void createStorage();
        fs::path getTableDir();
        void load();
        void select();
    };
}

