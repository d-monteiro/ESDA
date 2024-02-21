#include <iostream>
using namespace std;



/*
 *  calculates de square of a variable
 *  parameter: int &rN - reference of the number to calculate the square of
 *  return: int& - reference of the calculated square value of n
 */

int & square_reference(int &rN){
    // a) print the adress of rN 

    // a) calculate the square of rN
    
    // a) print the value of rN
}

/*
 *  calculates de square of a variable
 *  parameter: int *pN - pointer to the number to calculate the square of
 *  return: int* - pointer to the calculated square value of n
 */
int * square_pointer(int *pN){
    // b) print the adress of pN 

    // b) calculate the square of pN
    
    // b) print the value of pN

}



/* ---------- Test Code. Do not change ---------- */ 
int main() {

    int number = 8;
    cout <<  "---------- Testing the square_reference function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;
    int & result = square_reference(number);
    cout << "The number value in main after calling square_reference(number) is " << number <<  endl;
    cout << "The result value in main after calling square_reference(number) is " << result <<  " and its address is " << &result << endl;
    
    
    
    number = 8;
    cout <<  "\n\n---------- Testing the square_pointer function ---------- " << endl; 
    cout <<  "In main(): the number value is " << number << " and its address is " << &number << endl;
    int * pResult = square_pointer(&number);
    cout << "The number value in main after calling square_pointer(&number) is " << number <<  endl;
    cout << "The pointer result value in main after calling square_pointer(&number) is " << *pResult <<  " and its address is " << pResult << endl;
}
