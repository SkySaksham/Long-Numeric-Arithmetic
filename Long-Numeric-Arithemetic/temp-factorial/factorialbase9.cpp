#include <iostream>
#include <cstdint>
#include <vector>

#include <chrono>

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

/*
int main () {
 
    auto start = high_resolution_clock::now();
    vector <uint64_t> a ;
    a.reserve(60000) ;
    a.push_back(1) ;
    int i=100000;  // CHANGE INPUT 
    int c = 1 ;
    for (int j = 1 ; j<=i ; j++) vec_multiply(a,j) ;
    cout << vec_str(a).size() << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " milliseconds" << endl;
    
    cout << "Factorial :"<<i<< endl ;
*/
/*
for (int j=0 ;j<5;++j){
auto start = high_resolution_clock::now();
    
    vector <uint64_t> a ;
    a.reserve(60000) ;
    a.push_back(1) ;
    
    for (uint64_t i=2;i<999;i+=3){
        int c = i*(i+1)*(i+2) ;
        vec_multiply(a,c) ;
    }
    for (uint64_t i = 1001;i<10000;i+=2){
        int c = i*(i+1) ;
        vec_multiply(a,c) ;
    }
    
    cout << vec_str(a).size() << endl;
    
    
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " milliseconds" << endl;
    
    cout << "Factorial :"<< 10000<< endl ;
}*/

int main () {
    cout << factorial(100000).size()<< endl; // CHANGE INPUT
    cout << factorial(2)<< endl;
    cout << factorial(3)<< endl;
    cout << factorial(4)<< endl;
    cout << factorial(5)<< endl;
    cout << factorial(6)<< endl;
    return 0;
}