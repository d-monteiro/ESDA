#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Person {
private:
    string name;
      int age;
public:
       Person(string nam,int ag) {
        name=nam;
        age=ag;
       }
       void setName(string nam)  { name=nam;}
       void setAge(int ag)  {age=ag;} 
       string getName() const {return name;}
       int getAge() const {return age;}
};


/**
 *  Imprime os elementos do vetor;
 */

int imprime_vetor(vector<Person*> vec){

    if (vec.empty()) {
        cout << "vector vazio"<< endl;
        return -1;
    }
    cout << "[ ";
    for (Person* v:vec)
    {
        cout << v->getName() << " - "<< v->getAge()<<" ; ";
    }
    cout << "]"<<endl;
    return 0;
}

vector<Person*> findperson(vector<Person>& vperson, int min, int max) 
{
  vector<Person*> vector;
  
  for(size_t i=0;i<vperson.size();++i)
  {
    if(vperson[i].getAge() >= min && vperson[i].getAge() <= max)
    {
      vector.push_back(&vperson[i]);
    }
  }
  
  return vector;
}


int main()
{
    vector<Person> vp1;
    Person p1("Pedro",23);
    vp1.push_back(p1);
    Person p2("Ana",41);
    vp1.push_back(p2);
    Person p3("João",52);
    vp1.push_back(p3);
    Person p4("Tiago",40);
    vp1.push_back(p4);
    Person p5("Susana",22);
    vp1.push_back(p5);
    Person p6("Teresa",22);
    vp1.push_back(p6);
    Person p7("Ferando",44);
    vp1.push_back(p7);
    vector<Person*> vresultado;

    vresultado=findperson(vp1,30,50);
 
    cout << "Vresultado=";
    imprime_vetor(vresultado);

   vresultado=findperson(vp1,10,25);
 
    cout << "Vresultado=";
    imprime_vetor(vresultado);
}