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

    int addEdgeUndirected(int v1, int v2);

    int identifyOverload();

    void print();  
};

#endif