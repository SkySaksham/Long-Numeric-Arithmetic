#include "Number.h"
#include "NumberUtils.h"
#include "operations/addition.h"
#include "special_ops/factorialbase9.h"


int main () {
    Number num1 ; 
    Number num2 ;

    /*str_to_numb("-11111111111111111111", num1);
    str_to_numb("-10000000000000000000",num2);

    Number result = add(num1, num2);
    numb_print(result);*/
    

    Number result ;
    
    str_to_numb("-12345678901234567890.123456789", result);   

    numb_print(result) ;

    std::cout << "\n\n" ;
    Number b = factorial(500);
    numb_print(b) ;
    return 0;
}