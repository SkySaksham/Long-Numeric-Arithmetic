#include "NUMBER.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std ;


string numb_to_str (const Number & numb ) {
    string result ="" ;
    
    const vector <uint64_t> &num= numb.getNum() ;
    int size = num.size()-1 ;
    int deci_1 = numb.getDeci1() ;
    int deci_2 = numb.getDeci2() ;
    
    if (numb.getSign()) { result = "-" ; }
    
    string digit = to_string(num[size]);
    
    if (deci_1==0) {
       digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,digit.size()-deci_2) ;
    }
    
    result+=digit ;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = to_string(num[i]) ;
        while (digit.size ()<9) {
            digit = "0"+digit ;
        }
        if (size-i==deci_1){
            if (deci_2==0&&deci_1==0) {result+="0" ;}
            digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,9-deci_2) ;
        }
     result += digit ;   
    } 
    
    return result ;
}



void numb_print(const Number & numb) {
     const vector <uint64_t> &num= numb.getNum() ;
    int size = num.size()-1 ;
    int deci_1 = numb.getDeci1() ;
    int deci_2 = numb.getDeci2() ;
    
    if (numb.getSign()) {  cout << "-" ; }
    
    string digit = to_string(num[size]);
    
    if (deci_1==0) {
       digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,digit.size()-deci_2) ;
    }
    
    cout << digit ;
    
    for (int i=size-1; i>=0 ; i-- ) {
        digit = to_string(num[i]) ;
        while (digit.size ()<9) {
            digit = "0"+digit ;
        }
        if (size-i==deci_1){
            if (deci_2==0&&deci_1==0) {cout <<"0" ;}
            digit = digit.substr(0,deci_2)+"."+digit.substr(deci_2,9-deci_2) ;
         }
     cout << digit ;   
    } 
    
}



int64_t str_int(string_view x) {
    
    // IM SAVING 10 NANO SECONDS FK READABILITY 
    
    int64_t result = 100000000*(x[0]-48)+ 10000000*(x[1]-48)  ;
    result += 1000000*(x[2]-48) +100000*(x[3]-48) ;
    return result + 10000*(x[4]-48) + 1000*(x[5]-48) + 100*(x[6]-48) + 10*(x[7]-48) + (x[8]-48) ;    
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

void str_to_numb (const string &numb , Number & haha) {
    haha.clear() ;

    bool sign = 0 ;
    bool check = 0 ; // to check if there is numb sign
    int deci_1=-1 ;
    int deci_2 = -1 ;

    // numb --> Number

    if (numb[0] == '-') { sign = 1 ; check = 1;}
    if (numb[0] == '+'){check = 1 ;} 

    string_view chunk(numb); 

    int chunk_size = numb.size()/9; // number of full 8 digit parts 
    vector <uint64_t> data(chunk_size) ;
   
    int i = 0 ; // index for data vector
    int pointer = numb.size()-9 ; // pointer for chunk string_view

    while (pointer>0 ) {
            if (chunk.substr(pointer,9).find('.')== std::string_view::npos){ 
                
                    data[i] = str_int(chunk.substr(pointer,9)) ;
                    pointer-=9 ;
                    i++ ;
                    continue ;
            }

            // decimal point found 
            deci_2 = chunk.substr(pointer,9).find('.') +1  ;
            deci_1 = chunk_size - i ;  
         
            string yelp = string(chunk.substr(pointer-1,deci_2)) + string (chunk.substr(pointer+deci_2,10-deci_2)) ;

            data[i] = str_int(yelp) ;
            pointer-=10 ;
            i++ ;
        }
    
    if (check) {
        if (pointer+9>1) {
            
            if (chunk.substr(1,pointer+8).find('.')==string_view::npos){
                data.push_back(str_int1(chunk.substr(1,pointer+8))) ;
        
            }
            else {
            // decimal point found
            deci_2 = chunk.substr(1,pointer+9).find('.')   ;
            deci_1 = chunk_size - i ;
            string yelp = string(chunk.substr(1,deci_2)) + string(chunk.substr(2+deci_2,pointer+7-deci_2)) ;
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
            deci_2 = chunk.substr(0,pointer+9).find('.')   ;
            deci_1 = chunk_size - i ;
            string yelp = string(chunk.substr(0,deci_2)) + string(chunk.substr(1+deci_2,pointer+8-deci_2)) ;
            data.push_back(str_int1(yelp));
            }
        }
    }

   
    haha = Number(data, sign, deci_1, deci_2);

}


int main () {
    
    string numb = "1.2345767453568567884567678901111111111" ;
    Number haha ;
    str_to_numb(numb,haha) ;
    numb_print(haha) ;
    return 0 ;
    
    /*
    vector <uint64_t> num = {12,12} ;
    Number a (num,0,0,1) ;
    cout << numb_to_str(a) << endl ;
    numb_print(a) ;
    */
    return 0 ;
}
