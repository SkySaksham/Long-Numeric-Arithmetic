# Benchmarks

This folder contains benchmarking results and scripts comparing the performance of the Long-Numeric-Arithemetic library with other libraries.

## Hardware Used

- **Laptop**: HP Omen
- **CPU**: AMD Ryzen 7 7840HS
- **RAM**: 16 GB DDR5 5600 MT/s (Dual Channel)
- **OS**: Windows 11 (High Performance Mode)
- **Compiler**: MinGW64
- **Other Languages**: Latest versions of Python and Java (used for comparison)

## Compiler Flags (C++)

All C++ benchmarks were compiled with the following flags for maximum optimization:  

- -O3 -march=native -mtune=native

## Benchmark Process

1. **Warm-Up**  
   - Run 3 warm-up rounds before measurements.  
   - Each warm-up verifies:
     - The total number of digits in the result
     - The first 10 digits of the result

2. **Timed Runs**  
   - Perform 5 timed runs.
   - Record the time taken for each run.
   - Calculate and report:
     - Average execution time
     - Standard deviation

## Notes

- Warm-ups help eliminate startup or JIT compilation overhead.
- Comparisons are made under identical conditions to ensure fairness.
- All results are reproducible with the provided scripts.


