#pragma once
#include <variant>
#include <string>
#include <vector>

using namespace std;

namespace KadizQL {
    class Query {
    public:
        void select();
        void insert(string, vector<variant<int, float, string>>);
        void update();
        void remove();
    };
}