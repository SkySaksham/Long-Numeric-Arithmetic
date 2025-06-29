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



/* 
    Function --> vector_to_str
    ----------
    Converts a vector containing digit into a string in reverse order 
    eg. {1,2,3} --> "32"
    
    Parameters -->
        -    data --> Const reference to a vector
     
    Returns  -->
        -    result --> string containing digits of vector in reverse order 
*/          

string vector_to_str(const vector <int> data) {
        string result ;
        for (int i=data.size() -1 ; i>=0 ; i-- ){
            result += data[i] + '0' ;
        }
        return result ;
}


/*
    Function --> add_vectors 
    ------------
    Addition of two integer stored in reverse
    order in two Vectors
    eg . 123 --> {3,2,1}
    
    Parameters -->
        -    num1 --> Const reference to a vector
                      (contains Integer in reverse order)

        -    num2 --> Const referenve to a vector
                     (Contains Integer in reverse order)
                     
    Returns -->
        -    result_num --> Vector contains the resultant integer
        
    How it works -->      
    
    The Program Have Two steps (consist of two loops .)
     
     First loop --> adds the digits of both vectors and pushes it in result_vector , Runs size1 number times 
     ( size1 --> size of smaller vector)
     
     second loop --> pushes the resulting digits of larger vector in result_vector , runs size2 number of times 
     (size2 --> difference in sizes of vectors )

*/

vector <int> add_vectors( const vector<int> &num1 , const vector <int> &num2) {
                       
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


/*
    Function --> vector_product
    ----------
    Multiplies the integers stored in two vectors in reverse order
    Imitates the Manual Long Multiplication Method 
    
    Parameters -->
        -    num1 --> const reference to vector
                            (represents reverse ordered integer)
       -    num2 --> const referenve to a vector
                           (Represents reverse ordered integer)
     
     Returns -->
         -    result --> Vector contains the product of integers in reverse order
*/         
                          
vector <int> vector_product(const vector <int> &num1 , const vector <int> &num2) {
   
    vector <int> result ;
   
    for (int i = 0 ; i < num2.size() ; i++) {
        // To Multiply single element of num2
        // with all elements of num1

        
        
        vector <int> num ;
        // num --> vector to contains the SINGLE digit product in reverse order
        // eg. for 31*21 -->
        // for 31*1 --> num contains 31 as {1,3} 
        // for 31*2 --> num = 620 as {0,2,6}
                
        
        for (int k = 0 ; k < i ; k++) {
            num.push_back(0) ;
        } // add significant zeros in Num
            
        int carry =0 ;
        for (int j = 0 ; j<num1.size() ; j++ ) {
            // Single digit multiplication
            
            int product = (num2[i]*num1[j] )+ carry ;
        
            if (product >= 10) {
                carry =  (product - product%10)/10 ;
                product = product - carry*10 ;
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
        
        result = add_vectors(result,num) ;
    }
    return result ;
 }


/*
    Function --> sum
    ----------
    Adds two non negative integers , having no limitation of int data types
    
    Parameters -->
        -    num1 --> const reference to a string ,
                              contains non -ve integer
        -    num2 --> const reference to a string ,
                              contains non -ve integer 
    
    Returns -->>
        -    result --> string , contains the sum
 */                    

string sum(const string & num1, const string & num2 ) {
    vector <int> c , d ;
    c=str_to_vector(num1) ;
    d=str_to_vector(num2) ;
    string result = vector_to_str(add_vectors(c,d) );
    
    return result ;
}


/*
    Function --> multiply
    ----------
    Multiplies two non negative integers , having no limitation of int data types
    
    Parameters -->
        -    num1 --> const reference to a string ,
                              contains non -ve integer
        -    num2 --> const reference to a string ,
                              contains non -ve integer 
    
    Returns -->>
        -    result --> string , contains the product
 */

string multiply(const string & num1 , const string & num2 ) {
    vector <int> a,b ;
    a = str_to_vector(num1);
    b = str_to_vector(num2) ;
    string result ;
    result = vector_to_str(vector_product(a,b)) ;
    return result ;
}



string factorial (const int &num) {
    string result ="1" ;
    string count = "0" ;
    for (int i=0 ; i<num ;i++) {
        count = sum(count,"1") ;
        result= multiply(result,count) ;
    }
    return result ;
         
    }

string pow(const string &num,const int & power){
    string result = num ;
    for (int i = 1; i<power;i++ ){
        result = multiply(result,num) ;
    }
    return result ;
    
}


int main() {
    cout << sum ("2","2") << endl;
    cout << multiply("2","2") << endl ;
    cout << pow (factorial(120),2) << endl ;
    cout << sum ("999","1") << endl ;
    cout << multiply ("536","100") <<endl ;
   }