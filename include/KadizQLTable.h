#pragma once
#include <string>
#include <vector>

using namespace std;

namespace KadizQL {
    class Table {
    private:
        string tableName;
    public:
        Table(string);
        bool create(vector<vector<string>>);
        std::string readTableFromFile(std::string filename);
        void readTable();
        void writeTable();
        bool createScheme(vector<vector<string>>);
        bool createStorage();
        fs::path getTableDir();
    };
}

