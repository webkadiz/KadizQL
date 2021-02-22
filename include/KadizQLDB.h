#pragma once
#include <string>
#include <iostream>
#include <filesystem>

using namespace std;

namespace KadizQL {
    class DB {
        static string usedDB;
    public:
        static bool createDBDir(string dirName);
        static bool createDB(string dbName);
    };
}
