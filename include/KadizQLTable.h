#pragma once
#include <string>

namespace KadizQL {
    class Table {
    public:
        std::string readTableFromFile(std::string filename);
        void readTable();
        void writeTable();
    };
}

