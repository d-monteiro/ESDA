
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "graph.hpp"
#define MAX_VERTICES 50

Graph::Graph(int v)
{
    if (v > 0) {
        this->v = v; // atribui o número de vértices
        this->adj.resize(v);
    }
}

int Graph::addEdgeDirected(int v1, int v2)
{

    if ((v1 >= 0 && v1 < this->v) && (v2 >= 0 && v2 < this->v)) {
        adj[v1].push_back(v2);
        return 0;
    } 
    return -1;
}

//alinea a
int Graph::removeEdge(int v1, int v2)
{
    auto it = find(adj[v1].begin(), adj[v1].end(), v2);
    if (it != adj[v1].end()) 
    {
        adj[v1].erase(it);
        return 1;
    } else {
        return 0;
    }
    return -1;
}


void Graph::print()
{
    for(int i=0; i < this->v; i++){
        cout << i << " -> ";
        for(auto it : this->adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}



queue<int> Graph::BFS(int s)
{
   /* Implementar 4a) */
}




