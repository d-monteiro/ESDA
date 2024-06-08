#include <iostream>
#include <stack>
#include <vector>

using namespace std;
 
int removeElements(list<int> *list1, int n)
{
    if(!list1 || n > *max_element(list1->begin(), list1->end())) return -1;
    
    
    for(auto i = list1->begin(); i != list1->end(); ){
        if(*i > n) i = list1->erase(i);
        else i++;
    }
    
    //list1->remove_if([n](int val) { return val > n; });
    
    return 0;
}

void print(stack<string> s)
{
     int tam=(int)s.size()-1;
     cout<<"Stack depois de removidos os elementos: "<<endl;
        for ( int j=0; j<tam;j++)
        {
            cout << s.top()<<" - ";
            s.pop();
        }
         cout << s.top()<<endl;
         s.pop();
}

int main()
{
int res;

// Teste 1
stack<string> s1;
s1.push("João");
s1.push("Pedro");
s1.push("Francisco");
s1.push("Isabel");
s1.push("Luis");
s1.push("Teresa");
s1.push("Paulo");
s1.push("Gustavo");
s1.push("Ana");
s1.push("Filipe");

vector<string> v1{"Pedro","Francisco"};

res=removeElements(s1, v1);
print(s1);

// Teste 2
stack<string> s2;
s2.push("João");
s2.push("Pedro");
s2.push("Francisco");
s2.push("Isabel");
s2.push("Luis");
s2.push("Teresa");
s2.push("Paulo");
s2.push("Gustavo");
s2.push("Ana");
s2.push("Filipe");

vector<string> v2{"Pedro","Ana"};

res=removeElements(s2, v2);
cout <<" O return da função: "<<res <<endl;




// Teste 3
stack<string> s3;
s3.push("João");
s3.push("Pedro");
s3.push("Francisco");
s3.push("Isabel");
s3.push("Luis");
s3.push("Teresa");
s3.push("Paulo");
s3.push("Gustavo");
s3.push("Ana");
s3.push("Filipe");

vector<string> v3{"Pedro","Ana"};

res=removeElements(s3, v3);
print(s3);

// Teste 4
stack<string> s4;
s4.push("João");
s4.push("Pedro");
s4.push("Francisco");
s4.push("Isabel");
s4.push("Luis");
s4.push("Teresa");
s4.push("Paulo");
s4.push("Gustavo");
s4.push("Ana");
s4.push("Filipe");

vector<string> v4{"João","Filipe"};

res=removeElements(s4, v4);
print(s4);


}