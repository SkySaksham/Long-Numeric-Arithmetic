#ifndef NUMBER_H
#define NUMBER_H

#include <vector>
#include <iostream>
#include <cstdint>

class Number {
    private  :
        std::vector<uint64_t> digits;
        // with base 1e9 in reverse order 
        // Example : 12123456789 --> {1233456789 , 12 }  (reverse order)
       
        bool isNegative;
       
        int decimalBlockIndex, decimalDigitIndex;
        // Block Index is reverse indexed
        // DigitIndex is normal indexed
   
    public:
        Number() :
            isNegative(false),decimalBlockIndex(-1),decimalDigitIndex(-1),digits({0}) {}
      
        explicit Number(const std::vector<uint64_t>& digits, bool isNegative = false, int decimalBlockIndex= -1, int decimalDigitIndex = -1);
    
        void clear() {
            digits={0};
            isNegative = false;
            decimalBlockIndex = -1;
            decimalDigitIndex = -1;
        }

        const std::vector<uint64_t>& getDigits() const { 
            return digits; 
        }
       
        bool getIsNegative() const { return isNegative; }
        int getDecimalBlockIndex() const { return decimalBlockIndex; }
        int getDecimalDigitIndex() const { return decimalDigitIndex; }

        friend bool operator==(const Number& lhs, const Number& rhs);
        friend bool operator!=(const Number& lhs, const Number& rhs);
        friend bool operator<(const Number& lhs, const Number& rhs);
        friend bool operator<=(const Number& lhs, const Number& rhs);
        friend bool operator>(const Number& lhs, const Number& rhs);
        friend bool operator>=(const Number& lhs, const Number& rhs);  
};

#endif  

