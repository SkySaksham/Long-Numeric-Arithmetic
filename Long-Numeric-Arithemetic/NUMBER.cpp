#include "Number.h"
#include <vector>
#include <cstdint>
using namespace std ;


Number::Number(const vector<uint64_t>& inputNum, bool inputSign, int inputDeci1, int inputDeci2) {
    num = inputNum;     
    sign = inputSign;
    deci_1 = inputDeci1;
    deci_2 = inputDeci2;
}
