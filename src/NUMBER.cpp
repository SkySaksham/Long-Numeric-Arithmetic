#include "Number.h"
#include "Compare.h"

#include <vector>
#include <cstdint>



Number::Number(const std::vector<uint64_t>& d, bool neg, int decBlock, int decDigit)
    : digits(d), isNegative(neg), decimalBlockIndex(decBlock), decimalDigitIndex(decDigit) {}

    
bool operator==(const Number& lhs, const Number& rhs) {
    return compare(lhs, rhs) == 0;
}

bool operator!=(const Number& lhs, const Number& rhs) {
    return compare(lhs, rhs) != 0;
}

bool operator<(const Number& lhs, const Number& rhs) {
    return compare(lhs, rhs) < 0;
}

bool operator<=(const Number& lhs, const Number& rhs) {
    return compare(lhs, rhs) <= 0;
}

bool operator>(const Number& lhs, const Number& rhs) {
    return compare(lhs, rhs) > 0;
}

bool operator>=(const Number& lhs, const Number& rhs) {
    return compare(lhs, rhs) >= 0;
}