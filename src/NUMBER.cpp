#include "Number.h"
#include "operator.h"

#include <vector>
#include <cstdint>
using namespace std ;


Number::Number(const vector<uint64_t>& inputNum, bool inputSign, int inputDeci1, int inputDeci2) {
    num = inputNum;     
    sign = inputSign;
    deci_1 = inputDeci1;
    deci_2 = inputDeci2;
}

Number::Number() {
    num = {};      // empty vector
    sign = true;   // default sign (+)
    deci_1 = 0;
    deci_2 = 0;
}

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