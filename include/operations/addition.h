#ifndef ADDITION_H
#define ADDITION_H

#include <vector>
#include <cstdint>
#include "Number.h"

// Low-level vector-based addition (base 10^9)
std::vector<uint64_t> sum1(const std::vector<uint64_t> &a, const std::vector<uint64_t> &b);

// High-level Number addition
Number add(const Number &A, const Number &B);

#endif // ADDITION_H
