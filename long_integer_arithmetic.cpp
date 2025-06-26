#include <iostream>
#include <vector>
using namespace std ;

// WORK IN PROGRESS 

vector <int> add_vectors( const vector<int> &num1 , const vector <int> &num2) {
        
     /* The Program Have Two steps (consist of two loops .)
     
     first loop --> adds the digits of both vectors and pushes it in result_vector , Runs size1 number times 
     ( size1 --> size of smaller vector)
     
     second loop --> pushes the resulting digits of larger vector in result_vector , runs size2 number of times 
     (size2 --> difference in sizes of vectors )
     */   
                 
  vector <int> result_num ; 
  // Stores Integer In reverse Order 
  // eg. 123 --> 321 
      
  int size_num1 , size_num2  ;   
  size_num1= num1.size () ;
  size_num2 = num2.size () ;
  
 
  vector <int> data1 , data2 ;
  // data1 --> smaller vector
  // data2 --> larger vector
  
   if (size_num1 >= size_num2) {
      data1= num2 ;
      data2 = num1 ;
  }
  else {
      data1= num1 ;
      data2 = num2 ;
  }
  
    
  int size1 , size2  ;
  // Size1 --> size of smaller vector
  // Size2 --> difference in sizes of vectors
  
  size1= data1.size() ;
  size2= data2.size() - data1.size() ;
  
  
  
  int carry =0 ;
  
  // loop 1 --> 
  
  for (int i = size1-1 ; i>=0  ; i--){
  int sum = data1[i] + data2[i+size2] +  carry;
      if ( sum >9 ) {
           carry  =1 ;
           sum-=10 ;
           }
      else {
          carry =0 ;
          } 
      result_num.push_back(sum)  ;
      }

   // loop 2 -->
   for (int i= size2-1 ; i>=0 ; i--){
       int sum = data2[i]+carry ;
       if ( sum<10 ) {
           carry=0 ;
           }
       
       else {
           carry =1 ;
           sum -=10 ;
           }
       
       result_num.push_back(sum);
       }
         
  // if carry remains 
  if ( carry >0 ) {
      result_num.push_back (1) ;
      }
  
  return result_num ;
  }