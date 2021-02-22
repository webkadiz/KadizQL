#pragma once
#include <string>
#include <iostream>
#include <filesystem>

using namespace std;

namespace KadizQL {
    class DB {
        static string usedDB;
    public:
        static int createDBDir(string dirName);
        static int createDB(string dbName);
    };
}
