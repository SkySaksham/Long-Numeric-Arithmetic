#ifndef FACTORIALBASE9_H
#define FACTORIALBASE9_H

#include <string>
#include <vector>
#include <cstdint>
#include "Number.h"

// Multiply a big integer (stored as vector of base 1e9 chunks) with x
void vec_multiply(std::vector<uint64_t> &num1, uint64_t x);

// Convert a big integer vector (base 1e9 chunks) to string
std::string vec_str(const std::vector<uint64_t> &num);

// Compute factorial of n and return as string
std::string factorial_str(uint64_t n);

// Compute factorial of n and return as Number object
Number factorial(uint64_t n);

#endif // FACTORIALBASE9_H
