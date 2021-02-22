#include "../include/KadizQLQuery.h"

using namespace KadizQL;

int main() {
    Query *q = new Query();

    q->insert("test", {
        1,
        2,
        "test"
    });

}