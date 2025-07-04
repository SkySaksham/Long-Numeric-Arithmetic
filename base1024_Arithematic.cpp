/* It's a Failed attempt to make my base 10 Arithematic faster 

It's way too slower than decimal version due to slow conversation of 1024 base number o decimal one ...

 Check Out 10^6 base version ..

*/

#include <iostream>
#include <string>
#include <vector> 

using namespace std ;

vector<int> add_vectors(const vector<int>& num1, const vector<int>& num2) {
    vector<int> result_num;
    const vector<int>* bigger;
    const vector<int>* smaller;

    int size_num1 = num1.size();
    int size_num2 = num2.size();

    int size1, size2;

    if (size_num1 >= size_num2) {
        size1 = size_num2;
        size2 = size_num1;
        bigger = &num1;
        smaller = &num2;
    }
    else {
        size1 = size_num1;
        size2 = size_num2;
        bigger = &num2;
        smaller = &num1;
    }

    int carry = 0;

    for (int i = 0; i < size1; i++) {
        int sum = (*bigger)[i] + (*smaller)[i] + carry;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        }
        else {
            carry = 0;
        }
        result_num.push_back(sum);
    }

    for (int i = size1; i < size2; i++) {
        int sum = (*bigger)[i] + carry;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        }
        else {
            carry = 0;
        }

        result_num.push_back(sum);
    }

    if (carry > 0) {
        result_num.push_back(1);
    }

    return result_num;
}





vector<int> vector_product(const vector<int>& num1, const vector<int>& num2) {
    vector<int> result;

    for (int i = 0; i < num2.size(); i++) {
        vector<int> num;

        for (int k = 0; k < i; k++) {
            num.push_back(0);
        }

        int carry = 0;
        for (int j = 0; j < num1.size(); j++) {
            int product = (num2[i] * num1[j]) + carry;
            carry = product / 10;
            num.push_back(product % 10);
        }

        if (carry > 0) {
            num.push_back(carry);
        }

        result = add_vectors(result, num);
    }

    return result;
}





vector<int> int_to_vector(long long int num) {
    vector<int> reversed_digits;

    if (num == 0) {
        reversed_digits.push_back(0);
        return reversed_digits;
    }

    while (num > 0) {
        int digit = num % 10;
        reversed_digits.push_back(digit);
        num /= 10;
    }

    return reversed_digits;
}





vector <int> add_106_vector(const vector <int> &num1 , const vector <int> &num2) {
  
  vector <int> result_num ;
  
  const vector <int>* bigger ;
  const vector <int>* smaller ;
      
  int size_num1 , size_num2  ;   
  size_num1= num1.size () ;
  size_num2 = num2.size () ;
  
  int size1 , size2 ;
  // Size1 --> size of smaller vector
  // Size2 --> size of larger vector
  
   if (size_num1 >= size_num2) {
      size1= size_num2 ;
      size2 = size_num1 ;
      bigger = &num1 ;
      smaller = &num2 ;
  }
  else {
      size1= size_num1 ;
      size2 = size_num2 ;
      bigger = &num2 ;
      smaller =& num1 ;
  }
         
  int carry =0 ;
  
  // loop 1 --> 
  
  for (int i = 0 ; i<size1 ; i++){
  int sum = (*bigger)[i] + (*smaller)[i] +  carry;
      if ( sum >) {
           carry  =1 ;
           sum = sum%1024 ;
           }
      else {
          carry =0 ;
          } 
      result_num.push_back(sum)  ;
      }

   // loop 2 -->
   
   for (int i= size1 ; i<size2 ; i++){
       int sum = (*bigger)[i]+carry ;
       if ( sum<1024 ) {
           carry=0 ;
           }
       else {
           carry =1 ;
           sum -=1024;
           }
       
       result_num.push_back(sum);
       }         
  // if carry remains 
  if ( carry >0 ) {
      result_num.push_back (1) ;
      }
  
  return result_num ;
 
}





vector <int> vector_1024_product(const vector <int> &num1 , const vector <int> &num2) {
   
    vector <int> result ;
   
    for (int i = 0 ; i < num2.size() ; i++) {    
        vector <int> num ;
        
        for (int k = 0 ; k < i ; k++) {
            num.push_back(0) ;
        } // add significant zeros 
            
        int carry =0 ;
        for (int j = 0 ; j<num1.size() ; j++ ) {
            // Single digit multiplication
            
            int product = (num2[i]*num1[j] )+ carry ;
        
            if (product >= 1024) {
                carry =  (product)/1024 ;
                product = product - carry*1024 ;
            }
            else {
                carry = 0 ;
            }            
            num.push_back(product) ;
        }
        // If carry remains
        if (carry>0) {
            num.push_back (carry);
        }
        
        result = add_1024_vector(result,num) ;
    }
    return result ;
 }  




vector<int> vector1024_to_vector(const vector<int>& num) {
    
    int size = num.size() ;
    if ( size <6) {
        long long int result = num [0] ;
        long long int a = 1024 ;
        for (int i =1 ; i<size ;++i) {
            result += (a*num[i]) ;
            a*=1024 ;          
        }
        return int_to_vector( result)  ;     
    }
    else {
        
        long long int result_num = num [0] ;
        long long int a = 1024 ;
        for (int i =1 ; i<6 ;++i) {
            result_num += (a*num[i]) ;
            a*=1024 ;          
        }
    
        vector<int> result = int_to_vector(result_num);   
    
    vector<int> power = int_to_vector(a);
    for (int i = 8; i < size; i++) {
        vector<int> c = int_to_vector(num[i]);
        result = add_vectors(result , vector_product(power, c));
        power = vector_product(power,{4,2,0,1}) ;
    }
    return result;
    }
}



string vector_to_str(const vector <int> &data) {
        string result ;
        for (int i=data.size() -1 ; i>=0 ; i-- ){
            result += data[i] + '0' ;
        }
        return result ;
}



int main () {
    int x = 2000;
    vector <int> result = {1} ;
    vector <int> count = {1} ;
    
    for (int i=1 ; i<=x ; ++i) {
        result = vector_1024_product(result,count) ;
        count = add_1024_vector({1},count) ;
        
    }
    
    result = vector1024_to_vector(result) ;
    
    for (int i= result.size() -1  ; i>=0 ; i--) {
        cout << result [i] ;  
    }
    
    
return 0   ; 
}