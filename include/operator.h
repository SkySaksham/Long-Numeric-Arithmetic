#ifndef OPERATOR_H
#define OPERATOR_H

#include "Number.h"
#include "NumberUtils.h"


// Flag != 0 , implies comparison for absolute values of num1 and num2 ;;
// Compare two Number objects
// return  1 if num1 > num2
// return  0 if num1 == num2
// return -1 if num1 < num2
int operate(const Number& num1, const Number& num2, int flag = 0);

#endif // OPERATOR_H


