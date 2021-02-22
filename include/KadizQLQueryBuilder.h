#pragma once
#include <string>

using namespace std;

namespace KadizQL {
    class QueryBuilder {
        void createDB(string);
        void createTable(string);
        void select();
        void update();
        void insert();
        void remove();
        void where();
        void limit();
        void like();
        void offset();
        void orderBy();
        void groupBy();
        void one();
        void all();
        void column();
        void scalar();
        void count();
        void execute();
    };
}