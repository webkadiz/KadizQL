#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace KadizQL {
    class RDBMS {
    public:
        static fs::path getBaseDir();
    };
}