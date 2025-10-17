#include "NUMBER.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std ;


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
    
    std::string digit = to_string(num[size]);
    
    if (blockIndex==0) {
        if (digitIndex==0&&blockIndex==0) result+="0." ;
        else digit = insert_decimal(digit,digitIndex) ;
    }
    
    result+=digit;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = to_string(num[i]);

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

    const vector <uint64_t> &num= numberObject.getDigits() ;
    int size = num.size()-1 ;
    int blockIndex = numberObject.getDecimalBlockIndex() ;
    int digitIndex = numberObject.getDecimalDigitIndex() ;
    
    if (numberObject.getIsNegative()) out<<"-";
    
    std::string digit = to_string(num[size]);
    
    if (blockIndex==0) {
        if (digitIndex==0&&blockIndex==0) out<<"0." ;
        else digit = insert_decimal(digit,digitIndex) ;
    }
    
    out<<digit;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = to_string(num[i]);

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



void str_to_numb (const string &number , Number & numb) {
    numb.clear() ;

    bool isNegative = 0 ;
    bool isSignPresent = 0 ; //  Sign Present Flag
    int blockIndex=-1 ;
    int digitIndex = -1 ;

    // numberObject --> Number

    if (number[0] == '-') { isNegative = 1 ; isSignPresent = 1;}
    if (number[0] == '+'){isSignPresent = 1 ;} 

    string_view chunk(number); 

    int chunk_size = number.size()/9; // number of full 8 digit parts 
    vector <uint64_t> data(chunk_size) ;
   
    int i = 0 ; // size for data vector
    int pointer = number.size()-9 ; // pointer for chunk string_view

    while (pointer>0 ) {
            if (chunk.substr(pointer,9).find('.')== std::string_view::npos){ 
                
                    data[i] = str_int(chunk.substr(pointer,9)) ;
                    pointer-=9 ;
                    i++ ;
                    continue ;
            }

            // decimal point found 
            digitIndex = chunk.substr(pointer,9).find('.') +1  ;
            blockIndex = chunk_size - i ;  
         
            string yelp = string(chunk.substr(pointer-1,digitIndex)) + string (chunk.substr(pointer+digitIndex,10-digitIndex)) ;

            data[i] = str_int(yelp) ;
            pointer-=10 ;
            i++ ;
        }
    
    if (isSignPresent) {
        if (pointer+9>1) {
            
            if (chunk.substr(1,pointer+8).find('.')==string_view::npos){
                data.push_back(str_int1(chunk.substr(1,pointer+8))) ;
        
            }
            else {
            // decimal point found
            digitIndex = chunk.substr(1,pointer+9).find('.')   ;
            blockIndex = chunk_size - i ;
            string yelp = string(chunk.substr(1,digitIndex)) + string(chunk.substr(2+digitIndex,pointer+7-digitIndex)) ;
            data.push_back(str_int1(yelp));
            }
        }
    }
    else {
        if (pointer+9>0) {
            if (chunk.substr(0,pointer+9).find('.')==string_view::npos){
                data.push_back(str_int1(chunk.substr(0,pointer+9))) ;
            }
            else{
            // decimal point found
            digitIndex = chunk.substr(0,pointer+9).find('.')   ;
            blockIndex = chunk_size - i ;
            string yelp = string(chunk.substr(0,digitIndex)) + string(chunk.substr(1+digitIndex,pointer+8-digitIndex)) ;
            data.push_back(str_int1(yelp));
            }
        }
    }

   
    numb = Number(data, isNegative, blockIndex, digitIndex);

}



int64_t str_int(std::string_view x) {
    return 100000000LL*(x[0]-'0') + 10000000LL*(x[1]-'0') + 1000000LL*(x[2]-'0') + 100000LL*(x[3]-'0') + 10000LL*(x[4]-'0') + 1000LL*(x[5]-'0') + 100LL*(x[6]-'0') + 10LL*(x[7]-'0') + (x[8]-'0');
}

int64_t str_int1(string_view x) {
        int64_t result = x.back() -'0' ;
        int64_t b=1 ;
        for (int i=x.size()-2;i>=0;--i){
            b*=10 ;
            result+=(x[i]-'0')*b;
        }
        return result ;
}
