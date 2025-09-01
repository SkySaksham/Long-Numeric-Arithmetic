#include "Number.h"
#include "NumberUtils.h"

using namespace std ;


int total_digits (int x) {
    if (x<10) return 1 ;
    else if (x<100) return 2 ;
    else if (x<1000) return 3 ;
    else if (x<10000) return 4 ;
    else if (x<100000) return 5 ;
    else if (x<1000000) return 6 ;
    else if (x<10000000) return 7 ;
    else if (x<100000000) return 8 ;
    else if (x<1000000000) return 9 ;

    return 10 ;

}



int compare(const vector <uint64_t> &a,const vector <uint64_t> &b,bool flag2) {

    int size1 = a.size() ;
    int size2 = b.size() ;

    int size = min(size1,size2) ;

    for (size_t i = 0 ; i<size; i++) {
        if (a[size1-i -1]>b[size2-i-1]) return (flag2 ? 1 : -1) ;
        else if (a[size1-i-1]<b[size2-i-1]) return (flag2 ? -1 : 1) ;
    }
    
    int diff = size1 - size2 ;
    
    if (diff==0) return 0 ;
    if (diff > 0 ) return (flag2 ? 1:-1) ;
    return ( flag2 ? -1 : 1 ) ;
}

int compare2(const vector <uint64_t> a , const vector <uint64_t> b,bool flag2) {
    
    // Pointer pointing at ) indexed atm
    int p1 , p2 ;
    p1=0 ; 
    p2=0 ;

    string s1 , s2 ;

    s1 = to_string(a.back()) ;
    s2 = to_string(b.back()) ;

    //chunk counter 
    int c1 , c2 ;
    c1=a.size()-1 ;
    c2=b.size() -1 ;
    
    while (true) {

        int d1,d2 ;

        d1 = s1[p1] - '0' ;
        d2 = s2[p2] - '0' ;

        if (d1>d2) return (flag2 ? 1:-1) ;
        else if (d2>d1) return (flag2 ? -1:1) ;

        p1++ , p2++ ;

        if (p1>=s1.size()) {
            c1-- ;

            if (c1==-1) break ;  // if c1 ends

            s1=to_string(a[c1]) ;
            p1=0 ;
        } 
        if (p2>=s2.size()) {
            c2-- ;

            if (c1==0) break ; // if c2 ends 

            s2=to_string(b[c2]) ;
            p2=0 ;
        }
    }

        // c2 ends first ;
        if (c1>0) return (flag2 ?1 :-1) ;
        
        // c1 end first ;
        if (c2>0) return (flag2 ? -1:1) ;

        // both are at 0th chunk 
        if (p1==s1.size()) {

            // both ends simultaneously 
            if (p2==s2.size()) return 0 ;

            // p1 ends first
            return (flag2 ?-1 :1) ;
        }

        // p2 ends first 
        return (flag2 ? 1 : -1) ;    
}



/*
Function : operate (const Number & num1 , const Number & num2 )
_____________________

    num1 ---> const reference to a Number num1
    num2 ---> const reference to a Number num2


    if (num1 > num2)  return 1
    if (num1 == num2) return 0
    if (num1 < num2) return -1  

*/

int operate (const Number & num1 ,const Number & num2,int flag = 0) {

    // (flag2 = 1) implies both positive else both negative ;
    bool flag2 =1 ;

    // Flag != 1 implies operate on absolute values of a and b

    if (!flag) {

        bool sign1 , sign2 ;
        sign1 = num1.getSign() ;
        sign2 = num2.getSign() ;

        if (sign1 > sign2) return -1 ;
        else if (sign1 < sign2 ) return 1 ;

        else if (sign1) flag2=0 ;
    } 

    const vector <uint64_t>& veca = num1.getNum() ;        
    const vector <uint64_t>& vecb = num2.getNum() ;

    int  d1 = num1.getDeci1() ;
    int dd1 = num1.getDeci2() ;

    int  d2 = num2.getDeci1() ;
    int dd2 = num2.getDeci2() ;
    
    int diff = d1-d2 ;
    
    // if deci_1 chunk differs in position for more than 1 chunk ::
    if (diff > 1) return (flag2 ? 1 : -1) ;
    else if (diff < -1 ) return  (flag2 ? -1 : 1) ;

    // if deci_1 in the same chunk  ;

    else if (diff==0) {
        // digits in chunk 0 and chunk deci_1
        int t1 , t2 ;  
        
        t1 = total_digits(veca.back()) + dd1 ;
        t2 = total_digits(vecb.back()) + dd2 ;

        if (t1>t2) return (flag2 ? 1 : -1) ;
        else if (t2>t1) return (flag2 ? -1 : 1) ;

        else return compare (veca,vecb,flag2) ;

    }

    
    // total digits on the left side of decimal
    int t1,t2 ;

    t1= total_digits(veca.back()) + (d1 > 0 ? (d1 - 1) * 8 : 0) + dd1 ;
    t2= total_digits(vecb.back()) + (d2 > 0 ? (d2 - 1) * 8 : 0) + dd2 ;
        
    if (t1>t2) return (flag2 ?1 : -1) ;
    if (t2>t1) return (flag2 ? -1: 1) ;
    return compare2(veca,vecb,flag2) ;
    
}
