#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "graph.hpp"
#include "graph.cpp"

using namespace std;

int main()
{
	int n = 5;
	Graph d_graph(n);

	// Testa a criação das listas de adjacências
	int cont = 0;
	if (d_graph.addEdgeDirected(0, 2) == 0) cont ++;
	if (d_graph.addEdgeDirected(1, 3) == 0) cont ++;
	if (d_graph.addEdgeDirected(3, 0) == 0) cont ++;
	if (d_graph.addEdgeDirected(3, 2) == 0) cont ++;
	if (d_graph.addEdgeDirected(3, 4) == 0) cont ++;
	if (d_graph.addEdgeDirected(2, 1) == 0) cont ++;
	if (d_graph.addEdgeDirected(4, 0) == 0) cont ++;
	cout << "Grafo criado com " << n << " nos e " << cont << " arestas." << endl;
	d_graph.print();

	// Testa a remoção da aresta entre os nós 3 e 0
	int remove_edge = d_graph.removeEdge(3,0);
	if (remove_edge == 1) {
		cout << "Aresta removida com sucesso." << endl;
	} else if (remove_edge == 0) {
		cout << "Aresta nao encontrada." << endl; 
	} else {
		cout << "Erro ao remover aresta." << endl;
	}
	d_graph.print();

	// Testa se os nós são vizinhos
	bool test_neighbor = d_graph.existsNeighbor(2,1);
	bool test_neighbor2 = d_graph.existsNeighbor(0,1);
	if (test_neighbor) {
		cout << "Os nos 1 e 2 sao vizinhos" << endl;
	} else {
		cout << "Os nos 1 e 2 nao sao vizinhos" << endl;
	}
	if (test_neighbor2) {
		cout << "Os nos 0 e 1 sao vizinhos" << endl;
	} else {
		cout << "Os nos 0 e 1 nao sao vizinhos" << endl;
	}
	
	cout << endl;

	// Testa o grau de saída dos vertices
	cout <<  "Grau de saida do vertice 1: " << d_graph.outDegree(1) << endl;
	cout <<  "Grau de saida do vertice 3: " << d_graph.outDegree(3) << endl;

	cout << endl;

	// Testa a criação do grafo transposto
	cout << "Grafo transposto: " << endl;
	vector<list<int>> transpose = d_graph.transposeGraph();
	d_graph.print(transpose);

	return 0;
}