#pragma once

#include "BPScalar.hpp"

#include <map>
#include <functional>
#include <cmath>

namespace bigplus {

class BPOperator {
    public:
    using Constant = std::function<BPScalar()>;
    using Unary = 
        std::function<
            BPScalar(const BPScalar&)>;
    using Binary = 
        std::function<
            BPScalar(const BPScalar&, const BPScalar&)>;
    using Ternary = 
        std::function<
            BPScalar(const BPScalar&, const BPScalar&, const BPScalar&)>;

    // Constants
    static BPScalar pi() { return BPScalar(M_PI); }
    static BPScalar e() { return BPScalar(M_E); }

    // Unaries
    // static BPScalar inverse(const BPScalar& x);
    // static BPScalar sqrt(const BPScalar& x);
    
    // Binaries
    static BPScalar add(const BPScalar& x, const BPScalar& y);
    static BPScalar subtract(const BPScalar& x, const BPScalar& y);
    static BPScalar multiply(const BPScalar& x, const BPScalar& y);
    static BPScalar divide(const BPScalar& x, const BPScalar& y);
    static BPScalar quotient(const BPScalar& x, const BPScalar& y);
    static BPScalar modulo(const BPScalar& x, const BPScalar& y);
    static BPScalar power(const BPScalar& x, const BPScalar& y);
    
    static inline const std::map<std::string, Constant> constants = {
        {"pi", Constant(pi)},
        {"e", Constant(e)}
    };

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