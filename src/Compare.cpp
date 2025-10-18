#include "Number.h"
#include "NumberUtils.h"


const static uint64_t DIVS[9] = {1ULL, 10ULL, 100ULL, 1000ULL, 10000ULL, 100000ULL, 1000000ULL, 10000000ULL, 100000000ULL};

inline int total_digits_in_block (uint64_t x) ;
static int compare_equal_decimal_same_block (const std::vector<uint64_t> &num1digits,const std::vector <uint64_t> &num2digits , bool bothPositive) ;
static int compare_decimal_same_block (const std::vector<uint64_t> &num1digits,const std::vector<uint64_t> &num2digits,const int num1DecimalDigitIndex , const int num2DecimalDigitIndex , bool bothPositive) ;
static int compare_equal_decimal_diff_block(const std::vector<uint64_t>& num1Digits, const std::vector<uint64_t>& num2Digits,bool bothPositive) ;


int compare(const Number & num1 , const Number & num2) {

    const bool num1IsNegative = num1.getIsNegative() ;
    const bool num2IsNegative = num2.getIsNegative() ;

    if (num1IsNegative > num2IsNegative) return -1 ;
    else if (num1IsNegative < num2IsNegative) return 1 ;

    const bool bothPositive = ! num1IsNegative ;

    const std::vector <uint64_t>& num1Digits = num1.getDigits() ;        
    const std::vector <uint64_t>& num2Digits = num2.getDigits() ;

    const int  num1DecimalBlockIndex = num1.getDecimalBlockIndex() ;
    const int  num1DecimalDigitIndex = num1.getDecimalDigitIndex() ;

    const int  num2DecimalBlockIndex = num2.getDecimalBlockIndex() ;
    const int  num2DecimalDigitIndex = num2.getDecimalDigitIndex() ;

    const int decimalBlockIndexDiff = num1DecimalBlockIndex - num2DecimalBlockIndex ;

    // if decimalBlockIndex differs in position for more than 1 block ::
    // can easily decide which is larger since Decimal point is far apart

    if (decimalBlockIndexDiff > 1) return (bothPositive ? 1 : -1) ;
    else if (decimalBlockIndexDiff < -1 ) return  (bothPositive ? -1 : 1) ;

    // why not 1 ? 
    // {123465789, 12121.2} and {123456789,1,1.23} edge cases like this need to be handled
    // since , it may flip the comparison

    // if decimalBlockIndex in the same block  ;
    if (decimalBlockIndexDiff==0) {
        return compare_decimal_same_block(num1Digits,num2Digits,
            num1DecimalDigitIndex,num2DecimalDigitIndex,bothPositive) ;
    }

    // decimalBlockIndex differs by 1 ;

    int num1DigitsBeforeDecimal,num2DigitsBeforeDecimal ;

    num1DigitsBeforeDecimal = total_digits_in_block(num1Digits.back()) + 
        (num1DecimalBlockIndex > 0 ? (num1DecimalBlockIndex - 1) * 9 : 0) + num1DecimalDigitIndex ;

    num2DigitsBeforeDecimal = total_digits_in_block(num2Digits.back()) + 
        (num2DecimalBlockIndex > 0 ? (num2DecimalBlockIndex - 1) * 9 : 0) + num2DecimalDigitIndex;
    
    //  ternery operators r used since 
    //  block index 0 means decimal point is in the first block itself
    //  so , we dont wanna reduce degits from it since (index - 1) will be negative

    if (num1DigitsBeforeDecimal>num2DigitsBeforeDecimal) return (bothPositive ?1 : -1) ;
    if (num2DigitsBeforeDecimal>num1DigitsBeforeDecimal) return (bothPositive ? -1: 1) ;

    return compare_equal_decimal_diff_block(num1Digits,num2Digits,bothPositive) ;

}



inline int total_digits_in_block(uint64_t x) {
    if (x >= 100000000) return 9;
    if (x >= 10000000)  return 8;
    if (x >= 1000000)   return 7;
    if (x >= 100000)    return 6;
    if (x >= 10000)     return 5;
    if (x >= 1000)      return 4;
    if (x >= 100)       return 3;
    if (x >= 10)        return 2;
    return 1;
}

static int compare_equal_decimal_same_block ( const std::vector<uint64_t> &num1digits,
    const std::vector <uint64_t> &num2digits , bool bothPositive) {

    int size1 = num1digits.size() ;
    int size2 = num2digits.size() ;

    int minSize =  size1 < size2 ? size1 : size2 ;

    for (size_t i = 0 ; i<minSize; i++) {
        if (num1digits[size1-i -1]>num2digits[size2-i-1]) return (bothPositive ? 1 : -1) ;
        else if (num1digits[size1-i-1]<num2digits[size2-i-1]) return (bothPositive ? -1 : 1) ;
    }
    
    int diff = size1 - size2 ;
    
    if (diff==0) return 0 ;
    if (diff > 0 ) return (bothPositive ? 1:-1) ;

    return ( bothPositive ? -1 : 1 ) ;
}

static int compare_decimal_same_block (const std::vector<uint64_t> &num1digits,const std::vector<uint64_t> &num2digits,
    const int num1DecimalDigitIndex , const int num2DecimalDigitIndex , bool bothPositive) {

        const int num1EffectiveDigits = total_digits_in_block(num1digits.back()) + num1DecimalDigitIndex ;
        const int num2EffectiveDigits = total_digits_in_block(num2digits.back()) + num2DecimalDigitIndex ;

        if (num1EffectiveDigits > num2EffectiveDigits) return (bothPositive ? 1 : -1) ;
        else if (num2EffectiveDigits > num1EffectiveDigits) return (bothPositive ? -1 : 1) ;

        return compare_equal_decimal_same_block(num1digits,num2digits,bothPositive) ;
    }

static int compare_equal_decimal_diff_block(
    const std::vector<uint64_t>& num1Digits, const std::vector<uint64_t>& num2Digits,
    bool bothPositive) {
    int block1 = num1Digits.size() - 1;
    int block2 = num2Digits.size() - 1;

    while (block1 >= 0 && block2 >= 0)
    {
        uint64_t val1 = num1Digits[block1];
        uint64_t val2 = num2Digits[block2];

        int len1 = total_digits_in_block(val1);
        int len2 = total_digits_in_block(val2);

        // Use precomputed divisor
        uint64_t div1 = DIVS[len1 - 1];
        uint64_t div2 = DIVS[len2 - 1];

        // Compare digits one by one
        while (div1 > 0 && div2 > 0)
        {
            int d1 = val1 / div1;
            int d2 = val2 / div2;

            if (d1 > d2) return (bothPositive ? 1 : -1);
            else if (d1 < d2) return (bothPositive ? -1 : 1);

            val1 %= div1;
            val2 %= div2;

            div1 /= 10;
            div2 /= 10;
        }

        block1--;
        block2--;
    }

    if (block1 >= 0 && block2 < 0) return (bothPositive ? 1 : -1);
    if (block2 >= 0 && block1 < 0) return (bothPositive ? -1 : 1);

    return 0;
}




