/*****************************************************************/
/*                       Queue | EDA | LEEC                      */
/*****************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

/** 
 *  @brief  Find the position of the largest element in a queue.
 *  @param  queue_var Queue of char elements to be searched.
 *  @return Position of the largest element in the queue or 0 if the queue is empty.
 *  @note   The position of an element corresponds to its order, which means that the head element of the queue is at position 1.
 *  @note   If there are two or more elements with the same value (corresponding to the largest value), the position to be returned is the one of the first element that would leave the queue.
 */
int posLargestElement(queue<char> fila)
{
    char caracter, max;
    int index = 1;
    queue<char> filacopy = fila;
    
    if(fila.empty()) return 0;
    
    while(!fila.empty()){
        caracter = fila.front();
        fila.pop();
        if(caracter >= max) max = caracter;
    }
    
    while(!filacopy.empty()){
        if(filacopy.front() == max) break;
        index++;
        filacopy.pop();
    }

	return index;
}

/** 
 *  @brief  Insert a new element in a specified position of a queue.
 *  @param  queue_ptr Pointer to the queue of char elements.
 *  @param  elem New element to be inserted in the queue.
 *  @param  pos Position where the new element will be inserted.
 *  @return 0 if successful | -1 if an error occurs
 *  @note   The position of an element corresponds to its order, which means that the head element of the queue is at position 1.
 */
int insertInPosition(queue<char>* queue_ptr, char elem, unsigned int pos)
{ 
	// Exercise b)

	return 0;	
}