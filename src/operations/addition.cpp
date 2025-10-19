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
    for (size_t i = 0 ; i < smaller.size() ; i++) { 
        uint64_t sum = carry + bigger[i] + smaller[i] ;
        result[i] = sum % 1000000000 ;
        carry = sum / 1000000000 ;
    }
    for (size_t i = smaller.size() ; i < bigger.size() ; i++) {
        uint64_t sum = carry + (    bigger)[i] ;
        result[i] = sum % 1000000000 ;
        carry = sum / 1000000000 ;
    }
    if (carry) result.push_back(carry)  ;

    return result ;
} 


Number add(const Number &A, const Number &B) {
    if (A.getIsNegative() == B.getIsNegative()) {
        // Both numbers have the same sign, perform addition
        vector<uint64_t> resultNum = sum1(A.getDigits(), B.getDigits());
        return Number(resultNum, A.getIsNegative(), -1, -1); // Decimal precision handling can be added
    } 

    // If signs are different, perform subtraction (not implemented here)
    else {
        cout << "Subtraction not implemented yet." << endl;
        return Number(); // Placeholder
    }

}

