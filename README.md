#  Long Numeric Arithmetic Library

A C++ library for handling **very large numbers**, supporting basic arithmetic and factorial calculations.
Currently supports integers, signs, and string conversion, with room for future expansion.

---

##  Features

* Representation of large numbers:

  * Sign (positive / negative)
  * Length tracking
  * Optional decimals (storage ready, operations not implemented yet)
* Arithmetic support:

  * Addition of two numbers with the same sign (integers only)
* Factorial calculation
* Utility functions:

  * `numb_print()` – Print the number
  * `numb_to_str()` – Convert number to string

---

##  Example Usage

```cpp
#include "Number.h"
#include "NumberUtils.h"
#include "operations/addition.h"
#include "special_ops/factorialbase9.h"

int main() {
    Number num;
    str_to_numb("-12321234567.123456789012344334567890", num);
    numb_print(num); // prints the number

    Number fact = factorial(10000);
    numb_print(fact);

    return 0;
}
```

---

##  Folder Structure

```
Long-Numeric-Arithmetic/
├─ benchmarks           # Benchmarks with other libraries
├─ legacy-code          # Previous Implementations
├─ include/
|  ├─ operator.h      # relation ship operators for Number
|  ├─ operations/      # Current: addition
|  |  └─ addition.h
│  ├─ special_ops/      # Current: factorial
|  |  └─ factorialbase9.h 
│  ├─ Number.h          # Number class definition
│  └─ NumberUtils.h     # Helper functions (str_to_numb, numb_to_str)
├─ src /
|  ├─ operator.cpp     
│  ├─ operations/
|  |  └─ addition.h      
│  ├─ special_ops/
|  |  └─ factorialbase9.cpp      
│  ├─ Number.cpp    
│  └─ NumberUtils.cpp    
├─ main.cpp             # Example usage
└─ CMakeLists.txt       # Build configuration
```

---

## 🛠 Future Plans

* Support addition & subtraction with different signs
* Decimal arithmetic operations
* Multiplication & division
* Optimized factorial algorithms for very large numbers
* Exponentiation and roots
* Fully modular library ready for external use

---

##  License

MIT License – free to use, modify, and contribute.


