#include <string>
#include <variant>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldInt: public Field {
        string binaryFieldValue;
        int intFieldValue;
    public:
        FieldInt(string);
        FieldInt(int);
        void decode();
        void encode();
        dataTypes data();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}