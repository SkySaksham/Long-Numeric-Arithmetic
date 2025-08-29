#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include "Number.h"

using namespace std;


vector <uint64_t> sum1(const vector <uint64_t> &a, const vector <uint64_t> &b) {
    int max_size = max(a.size(), b.size()) ;

    const vector <uint64_t>& bigger = (a.size()>= b.size()) ? a : b ;
    const vector <uint64_t>& smaller = (a.size()< b.size()) ? a : b ;

    vector <uint64_t> result(max_size ) ;

    uint64_t carry = 0 ;
    for (int i = 0 ; i < smaller.size() ; i++) { 
        uint64_t sum = carry + bigger[i] + smaller[i] ;
        result[i] = sum % 1000000000 ;
        carry = sum / 1000000000 ;
    }
    for (int i = smaller.size() ; i < bigger.size() ; i++) {
        uint64_t sum = carry + (    bigger)[i] ;
        result[i] = sum % 1000000000 ;
        carry = sum / 1000000000 ;
    }
    if (carry) result.push_back(carry)  ;

    return result ;
} 


Number add(const Number &A, const Number &B) {
    if (A.getSign() == B.getSign()) {
        // Both numbers have the same sign, perform addition
        vector<uint64_t> resultNum = sum1(A.getNum(), B.getNum());
        return Number(resultNum, A.getSign(), -1, -1); // Decimal precision handling can be added
    } 

    // If signs are different, perform subtraction (not implemented here)
    else {
        cout << "Subtraction not implemented yet." << endl;
        return Number(); // Placeholder
    }

}

