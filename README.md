# Long_Integer_Arithematic

READ ME ISNT UPDATED FOR THE LATEST VERSION !!

## Overview
This is a **C++** project that implements arithmetic operations on very large integers (beyond the range of built-in data types like `int` or `long long`) by using `std::vector<int>` to store digits in reverse order.

## Features

- Addition of large integers (`sum` function)
- Multiplication of large integers (`multiply` function)
- Exponentiation of large integers (`pow` function)
- Factorial of large integers (`factorial` function)
- Conversion between `string` and `vector<int>` representations

## How It Works

1. **Storage**:
   - Large integers are stored in reverse using vectors.
   - Example: `123` is stored as `{3, 2, 1}`.

2. **Addition**:
   - Simulates digit-wise addition from least to most significant digit.
   - Handles carry propagation.

3. **Multiplication**:
   - Uses long multiplication (similar to the manual method).
   - Includes handling of carries and alignment using zero-padding.

4. **Factorial and Power**:
   - `factorial(n)` returns `n!` as a string.
   - `pow(num, power)` returns `num^power` as a string.

## Functions

| Function          | Purpose                                      |
|-------------------|----------------------------------------------|
| `vector_print`    | Print a vector (in reversed digit order)     |
| `str_to_vector`   | Converts a number in string to vector format |
| `vector_to_str`   | Converts vector to string format             |
| `add_vectors`     | Adds two vectors of digits                   |
| `vector_product`  | Multiplies two vectors of digits             |
| `sum`             | Adds two string-represented integers         |
| `multiply`        | Multiplies two string-represented integers   |
| `factorial`       | Calculates factorial of a number             |
| `pow`             | Raises a string-represented number to power  |

## Sample Output

```
4
4
<huge number from factorial(120)^2>
1000
53600
```

## How to Compile

```bash
g++ main.cpp -o LongIntMath
./LongIntMath
```

## Future Improvements

- Implement subtraction and division.
- Add error handling for invalid inputs.
- Support negative numbers.
- Add unit tests.

## License

This project is open-source and free to use under the **MIT License**.
