#include "KadizQLField.h"

namespace KadizQL {
    class FieldInt: Field {
        int realFieldValue;
    public:
        FieldInt(string, FieldScheme);
        void processedValue();
        int getValue();
    };
}