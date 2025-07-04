// Work Under Progress ... Fastest Version so far ..

#include <iostream>
#include <vector>
#include <string> 
#include <chrono>

using namespace std ;
using namespace std::chrono ;




vector <int> add_vector_base6(const vector <int> &num1 , const vector <int> &num2) {
  
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
      if ( sum >999999) {
           carry  =1 ;
           sum = sum%1000000;
           }
      else {
          carry =0 ;
          } 
      result_num.push_back(sum)  ;
      }

   // loop 2 -->
   
   for (int i= size1 ; i<size2 ; i++){
       int sum = (*bigger)[i]+carry ;
       if ( sum<1000000 ) {
           carry=0 ;
           }
       else {
           carry =1 ;
           sum -=1000000;
           }
       
       result_num.push_back(sum);
       }
         
  // if carry remains 
  if ( carry >0 ) {
      result_num.push_back (1) ;
      }
  
  return result_num ;
 
}


                          
vector <int> vector_product_base6(const vector <int> &num1 , const vector <int> &num2) {
   
    vector <int> result ;
   
    for (int i = 0 ; i < num2.size() ; i++) {
               
        vector <int> num ;                      
        for (int k = 0 ; k < i ; k++) {
            num.push_back(0) ;
        } // add significant zeros in Num
            
        int carry =0 ;
        for (int j = 0 ; j<num1.size() ; j++ ) {
            // Single digit multiplication
            
            int product = (num2[i]*num1[j] )+ carry ;
        
            if (product >= 1000000) {
                carry =  product/1000000 ;
                product = product - carry*1000000 ;
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
        
        result = add_vector_base6(result,num) ;
    }
    return result ;
 }  


string base6_vector_to_str (const vector <int> &num ) {
    
    string result = to_string(num.back());
    for (int i=num.size() -2 ; i>=0 ; --i){
        string digits = to_string(num[i]) ;
       while (digits.size() <6) {
        digits = "0"+digits ;
        
       }
        result = result + digits ;        
    }
    return result ;
   
}


string factorial (int num) {
    vector <int> result = {1} ;
    vector <int> count = {1} ;
    
    for (int i=1 ; i<=num ; ++i ) {
        
        result = vector_product_base6(result,count) ;
        count = add_vector_base6(count,{1}) ;  
    }
    
    return base6_vector_to_str(result) ;
    
    
}




int main () {
    
    int x = 10000;

    auto start = high_resolution_clock::now(); 

    cout << factorial(x) << endl; 

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " milliseconds" << endl;
                      
}