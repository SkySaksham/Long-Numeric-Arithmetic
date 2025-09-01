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
        // with base 1e9 in reverse order 
        // Example : 12123456789 --> {1233456789 , 12 }  (reverse order)
       
       bool sign ;
       // 0 -> +ve  || 1 -> -ve
       
       int deci_1, deci_2 ;
       // For Decimal Precision
       // decimal point is in (num.size() - deci_1)th element in Nums 
       // at (deci_2)th index in that element
   
   
   
public:
       
      // Default constructor
      Number() ;
      
      Number(const vector<uint64_t>& num, bool sign = 0, int deci_1 = -1, int deci_2 = -1);
      // Constructor to initialize the number
       
       
       void clear() {
           num.clear();
           sign = 0;
           deci_1 = -1;
           deci_2 = -1;
       }
       // Function to clear the number


       //**GETTER FUNCTIONS**
       const vector<uint64_t>& getNum() const { 
       return num; 
       }
       
       bool getSign() const { return sign; }
       int getDeci1() const { return deci_1; }
       int getDeci2() const { return deci_2; }


        // friend relational operators
        friend bool operator==(const Number& lhs, const Number& rhs);
        friend bool operator!=(const Number& lhs, const Number& rhs);
        friend bool operator<(const Number& lhs, const Number& rhs);
        friend bool operator<=(const Number& lhs, const Number& rhs);
        friend bool operator>(const Number& lhs, const Number& rhs);
        friend bool operator>=(const Number& lhs, const Number& rhs);
    
    
} ;


#endif  //NUMBER_H

