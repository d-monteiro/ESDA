#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"
#include "graph.cpp"

using namespace std;

int main()
{
	int n = 9;
	Graph u_graph(n);

	// Testa a criação das listas de adjacências
	int cont = 0;
	if (u_graph.addEdgeUndirected(0, 4) == 0) cont ++;
	if (u_graph.addEdgeUndirected(0, 2) == 0) cont ++;
	if (u_graph.addEdgeUndirected(0, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(1, 3) == 0) cont ++;
	if (u_graph.addEdgeUndirected(1, 5) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 3) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 4) == 0) cont ++;
	if (u_graph.addEdgeUndirected(2, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(5, 6) == 0) cont ++;
	if (u_graph.addEdgeUndirected(5, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(6, 7) == 0) cont ++;
	if (u_graph.addEdgeUndirected(6, 8) == 0) cont ++;
	cout << "Grafo criado com " << n << " nos e " << cont << " arestas." << endl;
	u_graph.print();

	int overload = u_graph.identifyOverload();
	cout << "Subestacao: " << overload << endl;


	return 0;
}