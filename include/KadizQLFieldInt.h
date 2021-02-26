#include "KadizQLField.h"

namespace KadizQL {
    class FieldInt: public Field {
        int realFieldValue;
    public:
        FieldInt(string, FieldScheme &);
        int processedValue();
        int data();
        operator int();
    };
}