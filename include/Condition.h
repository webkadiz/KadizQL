#pragma once

namespace KadizQL {
    class Condition {
    public:
        virtual bool exec(Row &) = 0;
    };
}