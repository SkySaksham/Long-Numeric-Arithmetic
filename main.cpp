#include "long_numeric_arithemetic.h"

using namespace std ;


int main () {
    Number fact = factorial(10000) ; // Faster Than Sequential Factorial calc in Big Int Java

    string data = numb_to_str(fact).substr(0,10) ;
    cout << data << endl ;

    Number a = str_to_numb("-.287567765346478236999999991") ; // bug
    cout << numb_to_str(a) << endl ;
    Number b = str_to_numb("+9993847893478932.374884329423999999999") ;

    numb_print(a,cout) ;
    cout << endl ;
    numb_print(b,cout) ;
    cout << endl ;

    if (b>a) cout << "b is greater than a" << endl ;

    else cout << "a is greater than b" << endl ;

    return 0;
}