#ifndef NUMBERUTILS_H
#define NUMBERUTILS_H

#include "Number.h"
#include <string>
#include <vector>
#include <string_view>
#include <cstdint>

// Convert Number → string
std::string numb_to_str(const Number &numb);

// Print Number to stdout
void numb_print(const Number &numb);

// Fast string → int converters
int64_t str_int(std::string_view x);
int64_t str_int1(std::string_view x);

// Convert string → Number
void str_to_numb(const std::string &numb, Number &out);

#endif // NUMBERUTILS_H
