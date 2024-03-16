/*****************************************************************/
/*                       Queue | EDA | LEEC                      */
/*****************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

/** 
 *  @brief  Reverse a queue (the front element becomes the back element and vice-versa).
 *  @param  queue_orig Queue to be reversed.
 *  @return Reversed queue.
 *  @note   Use a STACK to solve the problem.
 */
queue<string> reverseQueue(queue<string> queue_orig)
{
    // Implement here

    return {};
}

/* !!! Do not change !!! */

/** 
 *  @brief  Print the elements of a queue.
 *  @param  queue_orig Queue to be printed.
 *  @return void
 */
void printQueue(queue<string> queue_orig)
{
    if (!queue_orig.empty()) {
        cout << "[";
        while (!queue_orig.empty()) {
            cout << "  " << queue_orig.front();
            queue_orig.pop();
        }
        cout << "  ]\n";
    }
}

int main()
{
    queue<string> queue2reverse;

    queue2reverse.push("D8bMX%69");
    queue2reverse.push("=:w=I'GJ");
    queue2reverse.push("w=QT>(RT");
    queue2reverse.push("i^wyht-m");
    queue2reverse.push("{nKzc0@%");
    queue2reverse.push("5xSUeH\%C");
    queue2reverse.push("PBEygxs");

    cout << "--- Testing function <reverseQueue> ---\n\n";

    cout << "Original queue: ";
    printQueue(queue2reverse);
    cout << "Reversed queue: ";
    printQueue(reverseQueue(queue2reverse));

    cout << endl;
    
    return 0;
}