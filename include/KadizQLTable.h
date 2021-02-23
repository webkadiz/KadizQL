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
        void createScheme(vector<vector<string>>);
        void createStorage();
        fs::path getTableDir();
    };
}

