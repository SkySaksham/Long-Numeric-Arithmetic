#include <iostream>
#include <cstdint>
#include <vector>
#include "Number.h"
#include <chrono>

using namespace std;



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

string factorial_str(uint64_t n){
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

Number factorial(uint64_t n) {
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

        return Number(a);
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
        return Number(a);
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

    return Number(a) ;
}

