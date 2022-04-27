#pragma once

#include "BPScalar.hpp"

#include <map>
#include <functional>

namespace bigplus {

class BPOperator {
    public:
    using Unary = 
        std::function<
            BPScalar(const BPScalar&)>;
    using Binary = 
        std::function<
            BPScalar(const BPScalar&, const BPScalar&)>;
    using Ternary = 
        std::function<
            BPScalar(const BPScalar&, const BPScalar&, const BPScalar&)>;

    static BPScalar add(const BPScalar& x, const BPScalar& y);
    static BPScalar subtract(const BPScalar& x, const BPScalar& y);
    static BPScalar multiply(const BPScalar& x, const BPScalar& y);
    static BPScalar divide(const BPScalar& x, const BPScalar& y);
    static BPScalar quotient(const BPScalar& x, const BPScalar& y);
    static BPScalar modulo(const BPScalar& x, const BPScalar& y);
    static BPScalar power(const BPScalar& x, const BPScalar& y);
    
    static inline const std::map<std::string, Binary> binaries = {
        {"+", Binary(add)},
        {"add", Binary(add)},
        {"-", Binary(subtract)},
        {"subtract", Binary(subtract)},
        {"minus", Binary(subtract)},
        {"*", Binary(multiply)},
        {"x", Binary(multiply)},
        {"multiply", Binary(multiply)},
        {"times", Binary(multiply)},
        {"/", Binary(divide)},
        {"\\", Binary(quotient)},
        {"div", Binary(quotient)},
        {"%", Binary(modulo)},
        {"mod", Binary(modulo)},
        {"remainder", Binary(modulo)},
        {"^", Binary(power)},
        {"pow", Binary(power)},
    };
};

}