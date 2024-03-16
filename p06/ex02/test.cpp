/*****************************************************************/
/*                       Queue | EDA | LEEC                      */
/*****************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include "queue.cpp"

using namespace std;

// Do not change

void printQueue(queue<char> queue_var)
{
    cout << "Queue: ";
    cout << "[";
	
	while (!queue_var.empty()) {
        cout << "   " << queue_var.front();
        queue_var.pop();
    }
    cout << "  ]" << endl;
}

void printLargestPos(int pos)
{ 
	if (pos == 0) cout << "Empty queue!\n" << endl;
    else cout << "The largest element in the queue is at position " << pos << ".\n" << endl; 
}

void printInsert(int res)
{ 
	if (res == -1) cout << "Insert returned an error!" << endl;  
    else if (res == 0) cout << "Insert successful!" << endl;
}


int main()
{
    queue<char> f1;
    queue<char> f2;
    queue<char> f3;

    f1.push('A');
    f1.push('B');
    f1.push('C');
    f1.push('D');
    f1.push('E');
    f1.push('F');
    f3.push('~');
    f3.push('.');
    f3.push(' ');
    f3.push('+');
    f3.push('y');
    f3.push('2');
    f3.push('f');
    f3.push('B');
    f3.push('<');
    f3.push('&');

    cout << "\nTesting function <posLargestElement>\n" << endl;
    int res;
    
    printQueue(f2);
    res = posLargestElement(f2);
    printLargestPos(res);
    
    printQueue(f1);
    res = posLargestElement(f1);
    printLargestPos(res);
    
    printQueue(f3);
    res = posLargestElement(f3);
    printLargestPos(res);
     
    cout << "\nTesting function <insertInPosition>\n";
    
    cout << endl;

    cout << "Queue: NULL" << endl;
    cout << "Insert element X at position 1: " << endl;
    res = insertInPosition(NULL, 'X', 1);
    printInsert(res);
    	
    cout << endl;

    printQueue(f1);
    cout << "Insert element H at position 8: " << endl;
    res = insertInPosition(&f1, 'H', 8);
    printInsert(res);
    printQueue(f1);
    cout << endl;
    
    printQueue(f1);
    cout << "Insert element G at position 7: " << endl;
    res = insertInPosition(&f1, 'G', 7);
    printInsert(res);
    printQueue(f1);
    cout << endl;
    
    printQueue(f1);
    cout << "Insert element Y at position 1: " << endl;
    res = insertInPosition(&f1, 'Y', 1);
    printInsert(res);
    printQueue(f1);
    cout << endl;
    
    printQueue(f1);
    cout << "Insert element Z at position 4: " << endl;
    res = insertInPosition(&f1, 'Z', 4);
    printInsert(res);
    printQueue(f1);
    cout << endl;
    
    return 0;
    
}