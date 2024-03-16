/*****************************************************************/
/*                      Stack | EDA | LEEC                       */
/*****************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

/** 
 *  @brief  Decimal to binary converter.
 *  @param  n_decimal Integer to be converted.
 *  @return Binary number conversion.
 */
string dec2bin(int n_decimal)
{
    // Exercise b)

    return "";
}

// Do not change
int main()
{
    string n_dec;

    cout << "Enter an integer: ";
    getline(cin, n_dec);

    cerr << "Converted number in binary: " << dec2bin(stoi(n_dec)) << endl;

    return 0;
}
