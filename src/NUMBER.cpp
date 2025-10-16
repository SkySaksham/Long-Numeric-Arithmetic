#include "Number.h"
#include "operator.h"

#include <vector>
#include <cstdint>



Number::Number(const std::vector<uint64_t>& d, bool neg, int decBlock, int decDigit)
    : digits(d), isNegative(neg), decimalBlockIndex(decBlock), decimalDigitIndex(decDigit) {}

Number::Number()
    : digits({0}), isNegative(false), decimalBlockIndex(-1), decimalDigitIndex(-1) {}

    
bool operator==(const Number& lhs, const Number& rhs) {
    return operate(lhs, rhs,0) == 0;
}

bool operator!=(const Number& lhs, const Number& rhs) {
    return operate(lhs, rhs,0) != 0;
}

bool operator<(const Number& lhs, const Number& rhs) {
    return operate(lhs, rhs,0) < 0;
}

bool operator<=(const Number& lhs, const Number& rhs) {
    return operate(lhs, rhs,0) <= 0;
}

bool operator>(const Number& lhs, const Number& rhs) {
    return operate(lhs, rhs,0) > 0;
}

bool operator>=(const Number& lhs, const Number& rhs) {
    return operate(lhs, rhs,0) >= 0;
}