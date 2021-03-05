#include "KadizQLField.h"
#include "KadizQLFieldScheme.h"

namespace KadizQL {
    class FieldFabric {
    public:
        static Field *createField(string, FieldScheme *);
    };
}