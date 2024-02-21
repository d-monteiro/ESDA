#include <iostream>
using namespace std;
struct Person {
    string name;
    int age;
};


/* function to modify a Person using a pointer
* @return 0 se a importação teve sucesso
* @return -1 se ocorrer um erro 
*/
int modifyByPointer(Person* person,string name, int age) {
   
    //4.a) answer here
}


/* function to modify a Person using a reference
* @return 0 se a importação teve sucesso
* @return -1 se ocorrer um erro 
*/
int modifyByReference(Person& person,string name, int age) {
    
    //4.b) answer here
}

int main() {
   Person person1, person2;
    string name1="João", name2="Pedro";
    int age1=22, age2=34;
    int result;
    
    result=modifyByPointer(&person1,name1,age1);
    if (result==0)
    {
        cout << "Name: " << person1.name << ", Age: " << person1.age << endl;
    } else {
        cout << "return: "<<result<< endl;
    } 
    result=modifyByReference(person2,name2,age2);
    if (result==0)
    {
    cout << "Name: " << person2.name << ", Age: " << person2.age << endl;
    } else {
        cout << "return: "<<result<< endl;
    } 
    result=modifyByReference(person2,name2,-5);
    if (result==0)
    {
    cout << "Name: " << person2.name << ", Age: " << person2.age << endl;
    } else {
        cout << "return: "<<result<< endl;
    } 
   return 0;
}


