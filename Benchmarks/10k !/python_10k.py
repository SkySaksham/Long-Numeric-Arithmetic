# BENCHMARK: 10k! -- Python implementation
# This code calculates the factorial of 10,000 using Python's built-in arbitrary precision integers.

import sys
sys.set_int_max_str_digits(500000)  # Increase limit for big integer to string conversion

import math
import time
import statistics

# Pre-Requisite Data
# Total Digits: 35660
# First 10 Digits: 2846259680

total_digits = 35660
first_ten_digits = "2846259680"

def factorial(n):
    return math.factorial(n)

# WARM UP RUNS (3 runs)
for _ in range(3):
    factorial(10000)

# Verify correctness after warm-up
data = str(factorial(10000))
if len(data) != total_digits or not data.startswith(first_ten_digits):
    print("Warm-up run failed: Incorrect number of digits or first ten digits.")
    exit()

print(f"Warm-up run successful: {len(data)} digits.")
print(f"First 10 digits: {data[:10]}")

# TIMED RUNS (5 runs)
runs = 5
durations = []

for i in range(runs):
    print(f"\nRun {i + 1}:")

    start = time.perf_counter()
    result = factorial(10000)
    end = time.perf_counter()

    duration_ms = (end - start) * 1000  # convert to milliseconds
    durations.append(duration_ms)

    print(f"Time taken: {duration_ms:.2f} milliseconds")
    print(f"Total digits: {len(str(result))}")

# Calculate average and standard deviation
average = statistics.mean(durations)
stddev = statistics.stdev(durations)

print(f"\nAverage time: {average:.2f} milliseconds")
print(f"Standard deviation: {stddev:.2f} milliseconds")

