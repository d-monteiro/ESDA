/*****************************************************************/
/*                      Stack | EDA | LEEC                       */
/*****************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

/** 
 *  @brief  Binary to decimal converter.
 *  @param  n_binary Binary number to be converted.
 *  @return Decimal number conversion.
 */
int bin2dec(string n_binario)
{
    stack<int> stack;
    int i = 0;
    int sum = 0;
    
    for(char bit : n_binario) stack.push(stoi(&bit));
    
    while(!stack.empty()){
        sum += pow(2,i)*stack.top();
        stack.pop();
        i++;
    }
    
    return sum;
}

// Do not change
int main()
{
    string n_binario;

    cout << "Enter a binary number: ";
    getline(cin, n_binario);

    cerr << "Converted number in decimal: " << bin2dec(n_binario) << endl;

    return 0;
}
