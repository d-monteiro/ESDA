#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;


int firstToLast(priority_queue<int> &pq)
{
    

    return 0;
}

 void printQueue(priority_queue<int> pq)
 {
    cout << "Queue:";
    while(!pq.empty())
    {
        cout<<" "<<pq.top();
        pq.pop();
    }
    cout <<endl;
 }
/* ----------------------------- */
/* -------- NÃO ALTERAR -------- */
/* ----------------------------- */

int main()
{

    int v_result;
    priority_queue<int> pq1;
    pq1.push(4);
    pq1.push(14);
    pq1.push(24);
    pq1.push(34);
    pq1.push(44);
    priority_queue<int> pq2;
    pq2.push(4);
  
 

    
  
    cout<<"Before ";
    printQueue(pq1);
    cout <<"Return: "<<firstToLast(pq1)<<endl; 
    cout<<"After ";
    printQueue(pq1);
    
    cout<<"Before ";
    printQueue(pq2);
    cout <<"Return: "<<firstToLast(pq2)<<endl; 
    cout<<"After ";
    printQueue(pq2);
    
    
  
  
   

    return 0;
}

