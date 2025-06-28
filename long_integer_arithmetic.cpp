#include <iostream>
#include <vector>
#include <string>
using namespace std ;

// WORK IN PROGRESS 

/* 
    Function --> vector_print 
    -----------
    prints the digits stored in a vector
    in reverse order
    eg.  {3,2,1} --> 123
    
    Paramaters -->
         -   num1 --> const reference to a vector of integers 
     
    Returns -->
        -    Void           
 */
                             
void vector_print (const vector <int> &num1) { 
    for (int i=num1.size() -1 ; i>=0 ; i--) {
        cout << num1[i] ;
    }
}



/*
    Function --> str_to_vector 
    -----------
    inputs a STRING and converts it into a vector (in reverse order)
    eg. 123 ---> {3,2,1}
    
    Parameters -->
        -    data --> const reference to a string contains whole numbers [0,9] 
        
     Returns -->
         -    result_num --> a vector containing numeric digits 
 */   

vector <int> str_to_vector (const string & data ) {
    vector<int> result_num ;
    // Defining a Resultant Vector 
    
    int str_size = data.size () ;
    
    for (int i = str_size -1; i>=0 ; i--) {    
        int digit = data[i] - 48 ;
        // subtracting 48 to get the value of digit 
        // Ascii value of 0 to 9 --> 48 to 57
    
        result_num.push_back(digit) ;
    }
    
    return result_num ;
}



vector <int> add_vectors( const vector<int> &num1 , const vector <int> &num2) {
      
     // num1 & num2 are reverse ordered   
     /* 
     The Program Have Two steps (consist of two loops)
     
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
  // Size2 --> size of larger vector
  
  size1= data1.size() ;
  size2= data2.size() ;
  
  
  
  int carry =0 ;
  
  // loop 1 --> 
  
  for (int i = 0 ; i<size1  ; i++){
  int sum = data1[i] + data2[i] +  carry;
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
   for (int i= size1 ; i<size2 ; i++){
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