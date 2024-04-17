#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Graph
{
private:
	int v; 
	vector<list<int>> adj;

public:
    /* CONSTRUTOR */
    /** 
     *  @brief Construtor (parametrizado)
     *  @note  Inicializa os atributo v com o correspondente argumento.
     *  @note  Cria as listas de adjacências
     */
	Graph(int v);

	int addEdgeDirected(int v1, int v2);

    int removeEdge(int v1, int v2);

    bool existsNeighbor(int v1, int v2);

	int outDegree(int v);

    vector<list<int>> transposeGraph();
	
    void print();

    void print(vector<list<int>> vet);
    
};

#endif