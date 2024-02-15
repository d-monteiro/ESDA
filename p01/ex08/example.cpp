#include <iostream>
using namespace std;  

int division(int x1, int x2) 
{ 
   return x1 / x2; 
}     
int main() 
{ 
    int x = 10, y = 2, res;
    //float res; 
    res = division(x, y);
    cout << res << endl; 

    x = 7; y = 3; 
    res = division(x, y);
    cout << res << endl; 

    x = 3; y = 1; 
    res = division(x, y);
    cout << res << endl; 

    return 0; 
}  
