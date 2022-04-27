#pragma once

#include <cstdint>
#include <string>
#include <fmt/format.h>

namespace bigplus {

class BPScalar {
    public:

    int64_t intValue;
    double floatValue;
    bool isInt;

    BPScalar(int64_t value)
        : intValue(value),
          floatValue(static_cast<double>(value)),
          isInt(true) {}
    BPScalar(double value) 
        : intValue(static_cast<int64_t>(value)),
          floatValue(value),
          isInt(false) {}
    BPScalar(int64_t intValue, double floatValue, bool isInt)
        : intValue(intValue),
          floatValue(floatValue), 
          isInt(isInt) {}
    
    std::string to_string() {
        if (isInt) {
            return fmt::format("{} [int]", intValue);
        } else {
            return fmt::format("{} [float]", floatValue);
        }
    }
};

} // namespace bigplus