
// BENCHMARK: 100k! -- C++ implementation
// This code calculates the factorial of 10,000 using a vector to handle large numbers.


#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <chrono>
#include <numeric>
#include <cmath>

using namespace std;
using namespace std::chrono;


void vec_multiply(vector<uint64_t> &num1,uint64_t x ) {
        
        uint64_t carry = 0;
        for (int j = 0; j < num1.size(); j++) {
            uint64_t product = x * num1[j] + carry;

            if (product >= 1000000000) {
                carry = product / 1000000000;
                product %= 1000000000;
            } else {
                carry = 0;
            }
            num1[j]= product ;
        }

        if (carry > 0) {
            num1.push_back(carry);
        }
        
}



string vec_str(const vector<uint64_t> &num) {
    string result = to_string(num.back());

    for (int i = num.size() - 2; i >= 0; --i) {
        string digits = to_string(num[i]);
        while (digits.size() < 9) {
            digits = "0" + digits;
        }
        result += digits;
    }

    return result;
}



string factorial(uint64_t n){
    vector <uint64_t> a ;
    a.push_back(1) ;

    if (n<=1000) {
        int i = 2 ;
        a.reserve(300) ;
        for (;i+3<n  ;i+=3){
        int c = i*(i+1)*(i+2) ;
        vec_multiply(a,c) ; ;
        }
        for (;i<=n;i++){ ;
            vec_multiply(a,i) ;
        }

        return vec_str(a);
    }
    else if (n<=10000) {
        a.reserve(4500) ;
        int i=2 ; 
        for (;i<999;i+=3){
        int c = i*(i+1)*(i+2) ;
        vec_multiply(a,c) ;
        }
        for (;i+2<n;i+=2){
            int c = i*(i+1) ;
            vec_multiply(a,c) ;
        }
        for (;i<=n;i++){ ;
            vec_multiply(a,i) ;
        }
        return vec_str(a);
    }
    
    a.reserve(60000) ;
    
    for (int i=2;i<999;i+=3){
        int c = i*(i+1)*(i+2) ;
        vec_multiply(a,c) ;
    }
    for (int i = 1001;i<10000;i+=2){
        int c = i*(i+1) ;
        vec_multiply(a,c) ;
    }  

    for (int j = 10001 ; j<=n ; j++) vec_multiply(a,j) ;

    return vec_str(a);

}


int main () {

    // Pre-Requisite Data
    // Total Digits: 456574
    // First 10 Digits: 2824229407

    int total_digits = 456574;;
    string first_ten_digits = "2824229407";

    // 3 WARM UP RUNS 
    string data;

    for (int i=0;i<3;i++) data = factorial(100000);

    if (data.size() != total_digits && data.substr(0, 10) != first_ten_digits) {
        cout << "Warm-up run failed: Incorrect number of digits or first ten digits." << endl;
        return 1;
    }

    cout << "Warm-up run successful: " << data.size() << " digits." << endl;
    cout << "First 10 digits: " << data.substr(0, 10) << endl;
    // TIMED RUN

    const int runs = 5;
    vector<long long> durations;

    for (int i = 0; i < runs; ++i) {
        cout << endl << "Run " << (i + 1) << ": " << endl;
        
        auto start = high_resolution_clock::now();
        string result = factorial(100000);
        auto end = high_resolution_clock::now();

        long long duration = duration_cast<milliseconds>(end - start).count();
        durations.push_back(duration);

        cout << "Time taken: " << duration << " millseconds" << endl;
        cout << "Total digits: " << result.size() << endl;
    }

    // Calculate average
    double average = accumulate(durations.begin(), durations.end(), 0.0) / runs;

    // Calculate standard deviation
    double variance = 0.0;
    for (auto d : durations) {
        variance += (d - average) * (d - average);
    }
    variance /= runs;
    double stddev = sqrt(variance);

    cout << "\nAverage time: " << average << " milliseconds" << endl;
    cout << "Standard deviation: " << stddev << " millioseconds" << endl;
  
    return 0 ;
}