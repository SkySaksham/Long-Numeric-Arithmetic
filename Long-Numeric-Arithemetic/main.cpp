#include "NUMBER.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std ;


string numb_to_str (const Number & a ) {
     string result ="" ;
    
            
    
    const vector <uint64_t> &num= a.getNum() ;
    int size = num.size()-1 ;
    int deci_1 = a.getDeci1() ;
    int deci_2 = a.getDeci2() ;
    
    if (a.getSign()) { result = "-" ; }
    
    string digit = to_string(num[size]);
    
    if (deci_1==0) {
       digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,digit.size()-deci_2) ;
    }
    
    result+=digit ;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = to_string(num[i]) ;
        while (digit.size ()<8) {
            digit = "0"+digit ;
        }
        if (size-i==deci_1){
            if (deci_2==0&&deci_1==0) {result+="0" ;}
            digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,8-deci_2) ;
         }
     result += digit ;   
    } 
    
    return result ;
}

void numb_print(const Number & a) {
     const vector <uint64_t> &num= a.getNum() ;
    int size = num.size()-1 ;
    int deci_1 = a.getDeci1() ;
    int deci_2 = a.getDeci2() ;
    
    if (a.getSign()) {  cout << "-" ; }
    
    string digit = to_string(num[size]);
    
    if (deci_1==0) {
       digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,digit.size()-deci_2) ;
    }
    
    cout << digit ;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = to_string(num[i]) ;
        while (digit.size ()<8) {
            digit = "0"+digit ;
        }
        if (size-i==deci_1){
            if (deci_2==0&&deci_1==0) {cout <<"0" ;}
            digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,8-deci_2) ;
         }
     cout << digit ;   
    } 
    
}



int64_t str_int(string_view x) {
    
    // IM SAVING 10 NANO SECONDS FK READABILITY 
    
    int64_t result = 10000000*(x[0]-48)+ 1000000*(x[1]-48)  ;
    result += 100000*(x[2]-48) +10000*(x[3]-48) ;
    return result + 1000*(x[4]-48) + 100*(x[5]-48) + 10*(x[6]-48) + (x[7]-48) ;    
}

int64_t str_int1(string_view x) {
        int64_t result = x.back() -48 ;
        int64_t b=1 ;
        for (int i=x.size()-2;i>=0;--i){
            b*=10 ;
            result+=(x[i]-48)*b;
        }
        return result ;
}


int main () {
    
   string a = "-3333.333331111111122222222" ;
   bool sign = 0 ;
   bool check = 0 ;
   int deci_1=-1 ;
   int deci_2 = -1 ;
   if (a[0] == '-') { sign = 1 ; check = 1;}
   if (a[0] == '+'){check = 1 ;} 
   string_view sv(a);
   int ab = a.size()/8; 
   vector <uint64_t> data(ab) ;
   int i = 0 ;
   int p = a.size()-8 ;
   if (check) {

         while (p>0 ) {
         if (sv.substr(p,8).find('.')== std::string_view::npos){ 
         data[i] = str_int(sv.substr(p,8)) ;
         cout << data[i] << " " << i << endl ;
          p-=8 ;
          i++ ;
          continue ;
         }
         deci_2 = sv.substr(p,8).find('.') +1  ;
         cout << deci_2 << endl ;
         deci_1 = ab - i ;  
         string yelp = string(sv.substr(p-1,deci_2)) + string (sv.substr(p+deci_2,9-deci_2)) ;
         cout << yelp <<endl ;
         data[i] = str_int(yelp) ;
          cout << data[i] << " " << i << endl ;
         p-=9 ;
         i++ ;
         }
   if (p+8>1) {
       if (sv.substr(1,p+7).find('.')==string_view::npos){
       data.push_back(str_int1(sv.substr(1,p+7))) ;
       }
       else {
       deci_2 = sv.substr(1,p+8).find('.')   ;
       cout <<deci_2<<endl ;
       deci_1 = ab - i ;
       string yelp = string(sv.substr(1,deci_2)) + string(sv.substr(2+deci_2,p+6-deci_2)) ;
       cout <<yelp<<endl ;
       data.push_back(str_int1(yelp));
       }
        cout << data[data.size()-1] << data.size() -1 << i << endl ;
   }

   }
   
  else {       
   while (i<ab) {
        
         data[i] = str_int(sv.substr(p,8)) ;
         cout << data[i] << endl ;
          p-=8 ;
          i++ ;
   }
   if (p+8>1) {
       data.push_back(str_int1(sv.substr(0,p+8))) ;
   }
  
   
   }
   
    Number haha(data,sign,deci_1,deci_2) ;
    numb_print(haha) ;
   
  
    
    
  //  cout << str_int1(a);
   
}