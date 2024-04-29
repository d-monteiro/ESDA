#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include <queue>
#include <math.h> 
#include <ctime>
#include <cstdlib>
#include "TVseries.hpp"




using namespace std;



int main()
{



cout << "INICIO DOS TESTES\n\n" << endl;


// Testes para inserir no fim do vetor
UserManagement userMVector;
 
string us="user";
int total=1000;
vector<int> num;
int random;

while (num.size()!=total)
{
    random = rand() % (10*total);
 
    if (find(num.begin(),num.end(),random)==num.end())
    {
        num.push_back(random);
    }
}


User* users;
clock_t beg, end;
double time;
beg = clock();
for (int i=0;i<total;i++)
{
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUser(users);
}
end = clock();
time = (double)(end - beg) / CLOCKS_PER_SEC;
cout << "Time for insertion in vector in last position is "<< time << " seconds." << endl;




     return 0;
}