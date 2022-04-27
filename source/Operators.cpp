#include "bigplus/BPScalar.hpp"
#include "bigplus/BPOperator.hpp"
#include <math.h>

namespace bigplus {

BPScalar BPOperator::add(const BPScalar& x, const BPScalar& y) {
    return BPScalar(
        (x.intValue + y.intValue),
        (x.floatValue + y.floatValue),
        (x.isInt && y.isInt));
}

BPScalar BPOperator::subtract(const BPScalar& x, const BPScalar& y) {
    return BPScalar(
        (x.intValue - y.intValue),
        (x.floatValue - y.floatValue),
        (x.isInt && y.isInt));
}

BPScalar BPOperator::multiply(const BPScalar& x, const BPScalar& y) {
    return BPScalar(
        (x.intValue * y.intValue),
        (x.floatValue * y.floatValue),
        (x.isInt && y.isInt));
}

BPScalar BPOperator::divide(const BPScalar& x, const BPScalar& y) {
    if (x.isInt && y.isInt) {
        return BPScalar(
            (x.intValue / y.intValue),
            (x.floatValue / y.floatValue),
            ((x.intValue % y.intValue) == 0));
    }
    return BPScalar(
        (x.intValue / y.intValue),
        (x.floatValue / y.floatValue),
        false);
}

BPScalar BPOperator::quotient(const BPScalar& x, const BPScalar& y) {
    int64_t quotient = (x.intValue / y.intValue);
    return BPScalar(
        quotient,
        static_cast<double>(quotient),
        true);
}

BPScalar BPOperator::modulo(const BPScalar& x, const BPScalar& y) {
    if (x.isInt && y.isInt) {
        return BPScalar(
            (x.intValue % y.intValue),
            static_cast<double>(x.intValue % y.intValue),
            true);
    }
    throw std::runtime_error("Operation not valid on floating-point numbers");
}

BPScalar BPOperator::power(const BPScalar& x, const BPScalar& y) {
    return BPScalar(
        pow(x.intValue, y.intValue),
        pow(x.floatValue, y.floatValue),
        (x.isInt && y.isInt));
}

}