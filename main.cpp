#include "long_numeric_arithemetic.h"

using namespace std ;


int main () {
    Number fact = factorial(10000) ; // Faster Than Sequential Factorial calc in Big Int Java

    string data = numb_to_str(fact).substr(0,10) ;
    cout << data << endl ;

    Number a ;
    Number b ;

    str_to_numb("123451.23499236325652399991",a) ;
    str_to_numb("67832678263123451.23499236325652399990",b) ;


    if (a<b) {
        cout << "a is smaller than b" << endl ;
    }


    
    return 0;
}
