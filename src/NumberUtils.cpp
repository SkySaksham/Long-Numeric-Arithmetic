#include "NUMBER.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

int64_t str_int(std::string_view x) ;
int64_t str_int1(std::string_view x) ;
static constexpr int blockSize = 9 ; // Each block holds 9 digits (base 1e9)



std::string numb_to_str (const Number & numberObj ) {

    auto insert_decimal = [](const std::string s , const int digitIndex ){
        
        // decimalDigitIndex = 3 means after 3 digits from left
        // "123456789" --> "123.456789"
        return s.substr(0,digitIndex)+"."+s.substr(digitIndex);
    };
    
    std::string result ="";
    
    const std::vector<uint64_t> &num= numberObj.getDigits();
    int size = num.size()-1;
    int blockIndex = numberObj.getDecimalBlockIndex(); // Reverse indexed - 0th block is the rightmost block
    int digitIndex = numberObj.getDecimalDigitIndex(); // Normal indexed - 0th digit is the leftmost digit in a block
    
    if (numberObj.getIsNegative()) result = "-";
    
    std::string digit = std::to_string(num[size]);
    
    if (blockIndex==0) {
        //if (digitIndex==0&&blockIndex==0) result+="0." ;
        digit = insert_decimal(digit,digitIndex) ;
    }
    
    result+=digit;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = std::to_string(num[i]);

        // Pad leading zeros if necessary
        if (digit.size() < blockSize ) digit = std::string (blockSize-digit.size(),'0') + digit;

        // Check if decimal point is in this block
        if (size-i==blockIndex){
            if (digitIndex==0&&blockIndex==0) result+="0";

            // Insert decimal point
            digit = insert_decimal(digit,digitIndex) ;
        }
        
        result += digit;   
    } 
    
    return result;
}



void numb_print(const Number & numberObject,std::ostream &out) {
    
    auto insert_decimal = [](const std::string s , const int digitIndex ){
        
        // decimalDigitIndex = 3 means after 3 digits from left
        // "123456789" --> "123.456789"
        return s.substr(0,digitIndex)+"."+s.substr(digitIndex);
    };

    const std::vector <uint64_t> &num= numberObject.getDigits() ;
    int size = num.size()-1 ;
    int blockIndex = numberObject.getDecimalBlockIndex() ;
    int digitIndex = numberObject.getDecimalDigitIndex() ;
    
    if (numberObject.getIsNegative()) out<<"-";
    
    std::string digit = std::to_string(num[size]);
    
    if (blockIndex==0) {
        if (digitIndex==0&&blockIndex==0) out<<"0." ;
        else digit = insert_decimal(digit,digitIndex) ;
    }
    
    out<<digit;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = std::to_string(num[i]);

        // Pad leading zeros if necessary
        if (digit.size() < blockSize ) digit = std::string (blockSize-digit.size(),'0') + digit;

        // Check if decimal point is in this block
        if (size-i==blockIndex){
            if (digitIndex==0&&blockIndex==0) out << "0";

            // Insert decimal point
            digit = insert_decimal(digit,digitIndex) ;
        }
        
        out << digit;   
    } 
    
}



Number str_to_numb (const std::string &number) {

    // Currently we're assuming there aren't two decimal points or invalid characters

    bool isNegative = 0 ;
    bool isSignPresent = 0 ;
    int blockIndex=-1 ;
    int digitIndex = -1 ;


    if (number[0] == '-') { isNegative = 1 ; isSignPresent = 1;}
    if (number[0] == '+'){isSignPresent = 1 ;} 

    std::string_view chunk(number); 

    int chunk_size = number.size()/9; // number of full 8 digit parts 
    std::vector <uint64_t> data(chunk_size) ;
   
    int i = 0 ; // size for data vector
    int pointer = number.size()-blockSize ; // pointer for chunk string_view


    // we.re gonna iterate from the back of the string_view to the front
    // in 9 digit chunks , until we reach the start of the string_view
    // then we will handle the remaining digits (less than 9) separately

    // chechking for decimal point in each chunk
    // if found , we have to shift our pointer one to the left 
    //      - Note The BlockIndex and DigitIndex
    //      - Example :
    //      - 1"23.456789" --> "123456789" with digit index 3 , since in the modified chunk
    //        the decimal point is after 3 digits from left
    // if not found , we simply convert the chunk to integer and store it in data vector
    // we come out of the loop when pointer < 0 and upto 8 digits might be remaining
    // similarly we check for decimal point in the remaining digits

    while (pointer>0 ) {
            if (chunk.substr(pointer,blockSize).find('.')== std::string_view::npos){ 
                    data[i] = str_int(chunk.substr(pointer,blockSize)) ;
                    pointer-=blockSize ;
                    i++ ;
                    continue ;
            }

            // decimal point found 
            digitIndex = chunk.substr(pointer,blockSize).find('.') +1  ;
            blockIndex = chunk_size - i ;  
         
            std::string nineDigitChunk = std::string(chunk.substr(pointer-1,digitIndex)) + std::string (chunk.substr(pointer+digitIndex,10-digitIndex)) ;

            data[i] = str_int(nineDigitChunk) ;
            pointer-=10 ;
            i++ ;
        }
    
    if (isSignPresent) {
        if (pointer+blockSize>1) {
            // There are upto 7-8 remaining digits
            // we start from index 1 to skip the sign

            if (chunk.substr(1,pointer+blockSize-1).find('.')==std::string_view::npos){
                data.push_back(str_int1(chunk.substr(1,pointer+blockSize-1))) ;
        
            }
            else {
            digitIndex = chunk.substr(1,pointer+blockSize-1).find('.')   ;
            blockIndex = chunk_size - i ;
            std::string nineDigitChunk = std::string(chunk.substr(1,digitIndex)) + std::string(chunk.substr(2+digitIndex,pointer+7-digitIndex)) ;
            data.push_back(str_int1(nineDigitChunk));
            }
        }
    }
    else {
        if (pointer+9>0) {
            // no sign , we start from 0 index
            if (chunk.substr(0,pointer+blockSize).find('.')==std::string_view::npos){
                data.push_back(str_int1(chunk.substr(0,pointer+blockSize))) ;
            }
            else{
            // decimal point found
            digitIndex = chunk.substr(0,pointer+blockSize).find('.')   ;
            blockIndex = chunk_size - i ;
            std::string nineDigitChunk = std::string(chunk.substr(0,digitIndex)) + std::string(chunk.substr(1+digitIndex,pointer+8-digitIndex)) ;
            data.push_back(str_int1(nineDigitChunk));
            }
        }
    }

   
    return Number(std::move(data), isNegative, blockIndex, digitIndex);

}



int64_t str_int(std::string_view x) {
    return 100000000LL*(x[0]-'0') + 10000000LL*(x[1]-'0') + 1000000LL*(x[2]-'0') + 100000LL*(x[3]-'0') + 10000LL*(x[4]-'0') + 1000LL*(x[5]-'0') + 100LL*(x[6]-'0') + 10LL*(x[7]-'0') + (x[8]-'0');
}

int64_t str_int1(std::string_view x) {
        int64_t result = x.back() -'0' ;
        int64_t b=1 ;
        for (int i=x.size()-2;i>=0;--i){
            b*=10 ;
            result+=(x[i]-'0')*b;
        }
        return result ;
}
