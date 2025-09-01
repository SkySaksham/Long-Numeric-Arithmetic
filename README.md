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
#include "long_numeric_arithemetic.h"

using namespace std ;


int main () {
    Number fact = factorial(10000) ; // Faster Than Sequential Factorial calc in Big Int Java

    string data = numb_to_str(fact).substr(0,10) ;
    cout << data << endl ;

    Number a ;
    Number b ;

    str_to_numb("-123451.23499236325652399991",a) ;
    str_to_numb("-67832678263123451.23499236325652399990",b) ;


    if (a>b) {
        cout << "a is greater than b" << endl ;
    }

    cout << operate(a,b,1) << endl ; // compares the absolute value of a & b ;
    cout << operate(a,b) << endl ;   // compares the value of a & b ;

    Number num1 ;
    Number num2 ;

    str_to_numb("125273763217384",num1) ;
    str_to_numb("26167328162783",num2) ;

    numb_print(add(num1,num2)) ; // add works for only same signed integers atm 


    
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
|  ├─ long_numeric_arithemetic.h     # Main Header File
|  ├─ operator.h        # relation ship operators for Number
|  ├─ operations/       # Current: addition
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


