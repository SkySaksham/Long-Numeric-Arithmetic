#ifndef NUMBERUTILS_H
#define NUMBERUTILS_H

#include "Number.h"
#include <string>
#include <vector>
#include <string_view>
#include <cstdint>

// Converts a Number object to its string representation
std::string numb_to_str(const Number& numb);

// Prints a Number object to stdout
void numb_print(const Number& numb);

// Converts a string representation to a Number object
void str_to_numb(const std::string& numb, Number& out);

#endif // NUMBERUTILS_H
