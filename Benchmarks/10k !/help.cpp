#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
using namespace chrono;

const uint64_t BASE = 1000000000ULL;

// Ultra-optimized add_two with loop unrolling
inline void add_two(vector<uint64_t> &a, const vector<uint64_t> &b, size_t start) {
    uint64_t carry = 0;
    const size_t b_size = b.size();
    
    if (a.size() < start + b_size) {
        a.resize(start + b_size, 0);
    }

    size_t i = 0;
    // Process 4 elements at a time
    for (; i + 4 <= b_size; i += 4) {
        __uint128_t sum1 = (__uint128_t)a[start + i] + b[i] + carry;
        a[start + i] = (uint64_t)(sum1 % BASE);
        carry = (uint64_t)(sum1 / BASE);
        
        __uint128_t sum2 = (__uint128_t)a[start + i + 1] + b[i + 1] + carry;
        a[start + i + 1] = (uint64_t)(sum2 % BASE);
        carry = (uint64_t)(sum2 / BASE);
        
        __uint128_t sum3 = (__uint128_t)a[start + i + 2] + b[i + 2] + carry;
        a[start + i + 2] = (uint64_t)(sum3 % BASE);
        carry = (uint64_t)(sum3 / BASE);
        
        __uint128_t sum4 = (__uint128_t)a[start + i + 3] + b[i + 3] + carry;
        a[start + i + 3] = (uint64_t)(sum4 % BASE);
        carry = (uint64_t)(sum4 / BASE);
    }
    
    // Handle remaining elements
    for (; i < b_size; ++i) {
        __uint128_t sum = (__uint128_t)a[start + i] + b[i] + carry;
        a[start + i] = (uint64_t)(sum % BASE);
        carry = (uint64_t)(sum / BASE);
    }

    // Propagate carry
    if (carry > 0) {
        for (size_t idx = start + b_size; carry > 0; ++idx) {
            if (idx >= a.size()) {
                a.push_back(carry);
                break;
            }
            __uint128_t sum = (__uint128_t)a[idx] + carry;
            a[idx] = (uint64_t)(sum % BASE);
            carry = (uint64_t)(sum / BASE);
        }
    }
}

// Optimized string conversion
string vec_str(const vector<uint64_t> &num) {
    if (num.empty()) return "0";
    
    string result;
    // Pre-allocate memory (empirical sizing for 10000!)
    result.reserve(36000);
    result += to_string(num.back());
    
    for (int i = (int)num.size() - 2; i >= 0; --i) {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%09llu", (unsigned long long)num[i]);
        result.append(buffer, 9);
    }
    
    return result;
}

// Highly optimized multiplication with loop unrolling
void vec_product(vector<uint64_t> &result, const vector<uint64_t> &a, const vector<uint64_t> &b) {
    const size_t a_size = a.size();
    const size_t b_size = b.size();
    result.assign(a_size + b_size, 0ULL);
    
    for (size_t i = 0; i < b_size; ++i) {
        const uint64_t bi = b[i];
        if (bi == 0) continue; // Skip zero multiplication
        
        __uint128_t carry = 0;
        size_t j = 0;
        
        // Process 4 elements at a time
        for (; j + 4 <= a_size; j += 4) {
            __uint128_t prod1 = (__uint128_t)a[j] * bi + carry + result[i + j];
            result[i + j] = (uint64_t)(prod1 % BASE);
            carry = prod1 / BASE;
            
            __uint128_t prod2 = (__uint128_t)a[j + 1] * bi + carry + result[i + j + 1];
            result[i + j + 1] = (uint64_t)(prod2 % BASE);
            carry = prod2 / BASE;
            
            __uint128_t prod3 = (__uint128_t)a[j + 2] * bi + carry + result[i + j + 2];
            result[i + j + 2] = (uint64_t)(prod3 % BASE);
            carry = prod3 / BASE;
            
            __uint128_t prod4 = (__uint128_t)a[j + 3] * bi + carry + result[i + j + 3];
            result[i + j + 3] = (uint64_t)(prod4 % BASE);
            carry = prod4 / BASE;
        }
        
        // Handle remaining elements
        for (; j < a_size; ++j) {
            __uint128_t prod = (__uint128_t)a[j] * bi + carry + result[i + j];
            result[i + j] = (uint64_t)(prod % BASE);
            carry = prod / BASE;
        }
        
        // Propagate final carry
        size_t pos = i + a_size;
        while (carry > 0) {
            if (pos >= result.size()) {
                result.push_back((uint64_t)carry);
                break;
            }
            __uint128_t sum = (__uint128_t)result[pos] + carry;
            result[pos] = (uint64_t)(sum % BASE);
            carry = sum / BASE;
            ++pos;
        }
    }
    
    // Remove leading zeros
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
}

// Optimized multiplication with batched carry handling
inline void vec_multiply(vector<uint64_t> &num, uint64_t x) {
    __uint128_t carry = 0;
    size_t i = 0;
    const size_t num_size = num.size();
    
    // Process most elements
    for (; i < num_size; ++i) {
        __uint128_t product = (__uint128_t)num[i] * x + carry;
        num[i] = (uint64_t)(product % BASE);
        carry = product / BASE;
    }
    
    // Handle remaining carry
    while (carry > 0) {
        num.push_back((uint64_t)(carry % BASE));
        carry /= BASE;
    }
}

// Precomputed optimal batch sizes for different ranges
constexpr int get_batch_size(int n) {
    return (n < 100) ? 1 : 
           (n < 1000) ? 3 : 
           (n < 5000) ? 4 : 5;
}

// Ultra-optimized factorial with strategic batching
void factorial_batch(vector<uint64_t> &res, int start, int end) {
    // Empirical pre-allocation for 10000! (~35660 digits)
    if (end >= 10000) res.reserve(4000);
    else if (end >= 5000) res.reserve(2000);
    else res.reserve(1000);

    int i = start;
    const int batch_size = get_batch_size(end);
    
    // Process in optimal batches
    if (batch_size >= 5 && i + 4 <= end) {
        for (; i + 4 <= end; i += 5) {
            uint64_t mul = (uint64_t)i * (i + 1) * (i + 2);
            mul *= (i + 3) * (i + 4);
            vec_multiply(res, mul);
        }
    }
    
    if (batch_size >= 4 && i + 3 <= end) {
        for (; i + 3 <= end; i += 4) {
            uint64_t mul = (uint64_t)i * (i + 1) * (i + 2) * (i + 3);
            vec_multiply(res, mul);
        }
    }
    
    if (batch_size >= 3 && i + 2 <= end) {
        for (; i + 2 <= end; i += 3) {
            uint64_t mul = (uint64_t)i * (i + 1) * (i + 2);
            vec_multiply(res, mul);
        }
    }
    
    if (batch_size >= 2 && i + 1 <= end) {
        for (; i + 1 <= end; i += 2) {
            uint64_t mul = (uint64_t)i * (i + 1);
            vec_multiply(res, mul);
        }
    }
    
    // Single elements
    for (; i <= end; ++i) {
        vec_multiply(res, (uint64_t)i);
    }
}

int main() {
    // Warm up cache
    vector<uint64_t> warm{1};
    factorial_batch(warm, 1, 100);
    
    // SINGLE THREAD
    vector<uint64_t> single_res{1};
    auto start = high_resolution_clock::now();
    factorial_batch(single_res, 1, 10000);
    auto stop = high_resolution_clock::now();
    auto single_time = duration_cast<milliseconds>(stop - start).count();
    cout << "Single-thread done. Size: " << single_res.size()
         << ", Time: " << single_time << " ms" << endl;
    cout << "First 10 digits: " << vec_str(single_res).substr(0, 10) << endl;

    // MULTI THREAD with optimal split
    vector<uint64_t> res1{1}, res2{1}, res3{1};
    start = high_resolution_clock::now();

    // Optimal 3-way split for 4-core CPUs
    thread t1(factorial_batch, ref(res1), 1, 5000);
    thread t2(factorial_batch, ref(res2), 5001, 8000);
    thread t3(factorial_batch, ref(res3), 8001, 10000);

    t1.join();
    t2.join();
    t3.join();

    // Combine results: (1-5000! * 5001-8000!) * 8001-10000!
    vector<uint64_t> temp, merge;
    vec_product(temp, res1, res2);
    vec_product(merge, temp, res3);

    stop = high_resolution_clock::now();
    auto multi_time = duration_cast<milliseconds>(stop - start).count();
    
    cout << "Multi-thread done. Size: " << merge.size()
         << ", Time: " << multi_time << " ms" << endl;
    cout << "First 10 digits: " << vec_str(merge).substr(0, 10) << endl;
    cout << "Speedup: " << (double)single_time / multi_time << "x" << endl;

    // Verify results
    if (vec_str(single_res) == vec_str(merge)) {
        cout << "✓ Results match!" << endl;
    } else {
        cout << "✗ Results don't match!" << endl;
    }

    return 0;
}