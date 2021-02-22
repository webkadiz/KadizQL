#include <string>
#include <filesystem>
#include "../include/KadizQLRDBMS.h"

namespace fs = std::filesystem;
using namespace KadizQL;

fs::path RDBMS::getBaseDir() {
    fs::path baseDir = "/usr/share/kadizql/";

    return baseDir;
}