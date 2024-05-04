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

int main(){

int total=1000;
User* users;
User* userVet[total];
clock_t beg, end;
double time;
string us="user";

for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();
  for (int i=0;i<total;i++)
  {
    us="user"+i;
    users = new User(us, us, "P", {});
    for(int j=i-1;j>=0;j--)
    {
      userVet[j+1]=userVet[j];
    }
    userVet[i]=users;
  }
  end = clock();
  time += (double)(end - beg) / CLOCKS_PER_SEC;
}
cout << "Time for insertion in vector in last position is "<< time/3 << " seconds. (n=1000)\n" << endl;



for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();
  for (int i=0;i<5000;i++)
  {
    us="user"+i;
    users = new User(us, us, "P", {});
    for(int j=i-1;j>=0;j--)
    {
      userVet[j+1]=userVet[j];
    }
    userVet[i]=users;
  }
  end = clock();
  time += (double)(end - beg) / CLOCKS_PER_SEC;
}
cout << "Time for insertion in vector in last position is "<< time/3 << " seconds. (n=5000)\n" << endl;



for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();
  for (int i=0;i<10000;i++)
  {
    us="user"+i;
    users = new User(us, us, "P", {});
    for(int j=i-1;j>=0;j--)
    {
      userVet[j+1]=userVet[j];
    }
    userVet[i]=users;
  }
  end = clock();
  time += (double)(end - beg) / CLOCKS_PER_SEC;
}
cout << "Time for insertion in vector in last position is "<< time/3 << " seconds. (n=10000)\n" << endl;



for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();
  for (int i=0;i<50000;i++)
  {
    us="user"+i;
    users = new User(us, us, "P", {});
    for(int j=i-1;j>=0;j--)
    {
      userVet[j+1]=userVet[j];
    }
    userVet[i]=users;
  }
  end = clock();
  time += (double)(end - beg) / CLOCKS_PER_SEC;
}
cout << "Time for insertion in vector in last position is "<< time/3 << " seconds. (n=50000)\n" << endl;



for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();
  for (int i=0;i<100000;i++)
  {
    us="user"+i;
    users = new User(us, us, "P", {});
    for(int j=i-1;j>=0;j--)
    {
      userVet[j+1]=userVet[j];
    }
    userVet[i]=users;
  }
  end = clock();
  time += (double)(end - beg) / CLOCKS_PER_SEC;
}
cout << "Time for insertion in vector in last position is "<< time/3 << " seconds. (n=100000)\n" << endl;


return 0;
}