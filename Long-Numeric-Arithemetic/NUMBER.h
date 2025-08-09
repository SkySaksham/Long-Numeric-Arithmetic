#ifndef NUMBER_H
#define NUMBER_H

#include <vector>
#include <iostream>
#include <cstdint>

using namespace std ;

class Number {
    

private  :
        vector <uint64_t> num ;
        // Stores the number as a vector of digits 
        // with base 1e8 in reverse order 
        // Example : 1212345678 --> {123345678 , 12 }  (reverse order)
       
       bool sign ;
       // 0 -> +ve  || 1 -> -ve
       
       int deci_1, deci_2 ;
       // For Decimal Precision
       // decimal point is in (num.size() - deci_1)th element in Nums 
       // at (deci_2)th index in that element
   
   
   
public:
       
      Number(const vector<uint64_t>& num, bool sign = 0, int deci_1 = -1, int deci_2 = -1);
       // Constructor to initialize the number
       
       
        
       
/*Number(const vector<int>& num, bool sign = 0, int deci_1 = -1, int deci_2 = -1) {
    this->num = num;
    this->sign = sign;
    this->deci_1 = deci_1;
    this->deci_2 = deci_2;
}*/
       //**GETTER FUNCTIONS**
       const vector<uint64_t>& getNum() const { 
       return num; 
       }
       
       bool getSign() const { return sign; }
       int getDeci1() const { return deci_1; }
       int getDeci2() const { return deci_2; }
    
    
} ;


#endif  //NUMBER_H

