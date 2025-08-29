Long Numeric Arithmetic Library

A C++ library for handling very large numbers with support for basic arithmetic and factorial calculations.  
Currently supports integers, signs, and string conversion, with room for future expansion.

---

Current Features

- Representation of large numbers with:
  - Sign (positive/negative)
  - Length tracking
  - Optional decimals (storage ready, not yet used in operations)
- Arithmetic support:
  - Addition of two numbers with the same sign (integers only)
- Factorial calculation
- Utilities:
  - numb_print() – print the number
  - numb_to_str() – convert number to string

---

Example Usage

#include "Number.h"
#include "NumberUtils.h"
#include "operations/addition.h"
#include "special_ops/factorialbase9.h"

int main() {
    Number num;
    str_to_numb("12345678901234567890", num);
    numb_print(num); // prints the number

    Number fact = factorial(100);
    numb_print(fact);

    return 0;
}

---

Folder Structure

Long-Numeric-Arithmetic/
├─ src/
│  ├─ operations/       # Current: addition
│  ├─ special_ops/      # Current: factorial
│  ├─ Number.h          # Number class definition
│  └─ NumberUtils.h     # Helper functions (str_to_numb, numb_to_str)
├─ main.cpp             # Example usage
└─ CMakeLists.txt       # Build configuration

---

Future Plans

- Support addition and subtraction with different signs
- Decimal arithmetic
- Multiplication and division
- More optimized factorial algorithms for very large numbers
- Exponentiation and roots
- Make the library fully modular and ready for external use

---

License

MIT License – free to use, modify, and contribute.

