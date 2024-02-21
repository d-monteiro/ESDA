#include <iostream>
using namespace std;



/*
 *  calculates de square of a variable
 *  parameter: int n - number to calculate the square of
 *  return: int - calculated square valkue of n
 */

int square_by_value(int n){

    // a) print the adress of n 

    // a) calculate the square of m
    
    // a) print the value of n

    return n;
}

/*
 *  calculates de square of a variable
 *  parameter: int *pN - pointer to the number to calculate the square of
 *  return: void
 */

void square_by_reference_point_args(int *pN){
    
    // b) print the adress of pN 

    // b) calculate the square of pN
    
    // b) print the value of pN
}


/*
 *  calculates de square of a variable
 *  parameter: int &rN - reference of the number to calculate the square of
 *  return: void
 */

void square_by_reference_ref_args(int &rN){
    // c) print the adress of prN 

    // c) calculate the square of rN
    
    // c) print the value of rN
}







/* ---------- Test Code. Do not change ---------- */ 
int main (){ 
    int number = 8;
    cout <<  "---------- Testing the square_by_value function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;
    square_by_value(number);
    cout << "Its value in main after calling square_by_value(number) is " << number <<  endl;

    number = 8;
    cout <<  "\n\n---------- Testing the square_by_reference_point_args function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;  
    square_by_reference_point_args(&number); // Explicit referencing to pass an address
    cout << "Its value in main after calling square_by_reference_point_args(&number) is " << number <<  endl;


    number = 8;
    cout <<  "\n\n---------- Testing the square_by_reference_ref_args function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;  
    square_by_reference_ref_args(number); // Implicit referencing (without '&')
    cout << "Its value in main after calling square_by_reference_ref_args(number) is " << number <<  endl;

}