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
#include <exception>

using namespace std;

int main(){

  cout << "INÍCIO DOS TESTES\n\n" << endl;

  UserManagement userMVector;
  UserManagementList userMList;
  UserManagementTree userMTree;
  HashTable hash(100000);
  
  string us="user";
  vector<int> num;
  int random;



  while (num.size()!=1000)
  {
      random = rand() % (10*1000);
  
      if (find(num.begin(),num.end(),random)==num.end()) num.push_back(random);
  }

  User* users;
  CountryStats* countries;
  long long beg, end;
  double total_time;

  cout << "INSERTION IN VECTOR (END)\n" << endl;

// Teste para inserir no fim do vetor (n=1000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<1000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in last position is "<< total_time/3 << " seconds. (n=1000)\n" << endl;
  total_time = 0;

// Teste para inserir no fim do vetor (n=5000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<5000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in last position is "<< total_time/3 << " seconds. (n=5000)\n" << endl;
  total_time = 0;
// Teste para inserir no fim do vetor (n=10000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<10000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in last position is "<< total_time/3 << " seconds. (n=10000)\n" << endl;
  total_time = 0;

// Teste para inserir no fim do vetor (n=50000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<50000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

cout << "Time for insertion in vector in last position is "<< total_time/3 << " seconds. (n=50000)\n" << endl;
  total_time = 0;



// Teste para inserir no fim do vetor (n=100000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<100000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in last position is "<< total_time/3 << " seconds. (n=100000)\n\n\n" << endl;
  total_time = 0;
for (User* user : userMVector.getVectorUsers()) {
  delete user;
}


  cout << "INSERTION IN VECTOR (BEGINNING)\n" << endl;

// Teste para inserir no início do vetor (n=1000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<1000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in vector in first position is "<< total_time/3 << " seconds. (n=1000)\n" << endl;
  total_time = 0;
// Teste para inserir no início do vetor (n=5000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<5000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in first position is "<< total_time/3 << " seconds. (n=5000)\n" << endl;
  total_time = 0;
// Teste para inserir no início do vetor (n=10000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<10000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in first position is "<< total_time/3 << " seconds. (n=10000)\n" << endl;
  total_time = 0;

// Teste para inserir no início do vetor (n=50000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<50000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMVector.addUserBegin(users);
  }

 
  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMVector.getVectorUsers().clear();
}

  cout << "Time for insertion in vector in first position is "<< total_time/3 << " seconds. (n=100000)\n\n\n" << endl;
  total_time = 0;


  cout << "INSERTION IN LIST (END)\n" << endl;

// Teste para inserir no fim da lista (n=1000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<1000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in list in last position is "<< total_time/3 << " seconds. (n=1000)\n" << endl;
  total_time = 0;
// Teste para inserir no fim da lista (n=5000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<5000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in list in last position is "<< total_time/3 << " seconds. (n=5000)\n" << endl;
  total_time = 0;
// Teste para inserir no fim da lista (n=10000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<10000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in list in last position is "<< total_time/3 << " seconds. (n=10000)\n" << endl;
  total_time = 0;

// Teste para inserir no fim da lista (n=50000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<50000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in list in last position is "<< total_time/3 << " seconds. (n=50000)\n" << endl;
  total_time = 0;
// Teste para inserir no fim da lista (n=100000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<100000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUser(users);
 }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in list in last position is "<< total_time/3 << " seconds. (n=100000)\n\n\n" << endl;
  total_time = 0;
for (User* user : userMList.getListUsers()) {
  delete user;
}


  cout << "INSERTION IN LIST (BEGINNING)\n" << endl;

// Teste para inserir no início da lista (n=1000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<1000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMList.getListUsers().clear();
}

  cout << "Time for insertion in list in first position is "<< total_time/3 << " seconds. (n=1000)\n" << endl;
  total_time = 0;
// Teste para inserir no início da lista (n=5000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<5000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMList.getListUsers().clear();
}

  cout << "Time for insertion in list in first position is "<< total_time/3 << " seconds. (n=5000)\n" << endl;
  total_time = 0;
// Teste para inserir no início da lista (n=10000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<10000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMList.getListUsers().clear();
}

  cout << "Time for insertion in list in first position is "<< total_time/3 << " seconds. (n=10000)\n" << endl;
  total_time = 0;

// Teste para inserir no início da lista (n=50000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<50000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMList.getListUsers().clear();
}

  cout << "Time for insertion in list in first position is "<< total_time/3 << " seconds. (n=50000)\n" << endl;
  total_time = 0;
// Teste para inserir no início da lista (n=100000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<100000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMList.addUserBegin(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  userMList.getListUsers().clear();
}

  cout << "Time for insertion in list in first position is "<< total_time/3 << " seconds. (n=100000)\n\n\n" << endl;
  total_time = 0;




  cout << "INSERTION IN TREE\n" << endl;

// Teste para inserir na árvore (n=1000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<1000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMTree.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in tree is "<< total_time/3 << " seconds. (n=1000)\n" << endl;
  total_time = 0;
// Teste para inserir na árvore (n=5000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<5000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMTree.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in tree is "<< total_time/3 << " seconds. (n=5000)\n" << endl;
  total_time = 0;
// Teste para inserir na árvore (n=10000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<10000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMTree.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in tree is "<< total_time/3 << " seconds. (n=10000)\n" << endl;
  total_time = 0;

// Teste para inserir na árvore (n=50000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<50000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMTree.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in tree is "<< total_time/3 << " seconds. (n=50000)\n" << endl;
  total_time = 0;
// Teste para inserir na árvore (n=100000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<100000;i++)
  {
    us="user"+to_string(num[i]);
    users = new User(us, us, "P", {});
    userMTree.addUser(users);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
}

  cout << "Time for insertion in tree is "<< total_time/3 << " seconds. (n=100000)\n\n\n" << endl;
  total_time = 0;



  cout << "INSERTION IN HASH TABLE\n" << endl;

// Teste para inserir na tabela de dispersão (n=1000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();

  for (int i=0;i<1000;i++)
  {
    us="user"+to_string(num[i]);
    countries = new CountryStats(us, 10, 10, 10.0, {});
    hash.insertCountryStats(*countries);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  hash.clear();
}

  cout << "Time for insertion in hash table is "<< total_time/3 << " seconds. (n=1000)\n" << endl;
  total_time = 0;
// Teste para inserir na tabela de dispersão (n=5000)
for(int iteration = 0; iteration < 3; ++iteration){
  beg = clock();
  for (int i=0;i<5000;i++)
  {
    us="user"+to_string(num[i]);
    countries = new CountryStats(us, 10, 10, 10.0, {});
    hash.insertCountryStats(*countries);
  }

  end = clock();
  total_time += (double)(end - beg) / CLOCKS_PER_SEC;
  hash.clear();
}

  cout << "Time for insertion in hash table is "<< total_time/3 << " seconds. (n=5000)\n" << endl;
  total_time = 0;

  return 0;
}