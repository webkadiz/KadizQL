#include <string>
#include <variant>
#include "KadizQLField.h"

using namespace std;

namespace KadizQL {
    class FieldInt: public Field {
        char binaryFieldValue[4];
        int intFieldValue;
    public:
        FieldInt(const char *, FieldScheme *);
        FieldInt(int, FieldScheme *);
        void toInt();
        void decode();
        void encode();
        dataTypes data();
        char *getEncodedData();
        size_t getEncodedSize();
    };
}