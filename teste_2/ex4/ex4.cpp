#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "graph.cpp"

using namespace std;
void print_queue(queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}


int main()
{
	int n = 5;
	Graph d_graph(n);

	// Testa a criação das listas de adjacências
	int cont = 0;
	if (d_graph.addEdgeDirected(1, 0) == 0) cont ++;
	if (d_graph.addEdgeDirected(3, 1) == 0) cont ++;
	if (d_graph.addEdgeDirected(1, 3) == 0) cont ++;
	if (d_graph.addEdgeDirected(1, 2) == 0) cont ++;
	if (d_graph.addEdgeDirected(2, 4) == 0) cont ++;
	if (d_graph.addEdgeDirected(4, 2) == 0) cont ++;
	if (d_graph.addEdgeDirected(0, 1) == 0) cont ++;


	cout << "\n++ Exercício 4a) ++\n\n";
    //Testa BFS
    cout << "Breadth First Traversal from vertix 1" << endl; 
    print_queue(d_graph.BFS(1));
    
	
   

  return 0;
}