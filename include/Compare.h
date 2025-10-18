#ifndef COMPARE_H
#define COMPARE_H

#include "Number.h"
#include "NumberUtils.h"
#include <vector>
#include <cstdint>

// Compares two Number objects
// Returns:
//   1 -->  if num1 > num2
//   0 -->  if num1 == num2
//  -1 -->  if num1 < num2

int compare(const Number& num1, const Number& num2);

#endif 
