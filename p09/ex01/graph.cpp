/*****************************************************************/
/*   Grafo c/ listas de adjacencias | ESDA | LEEC | 2023/24      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"

Graph::Graph(int v)
{
    if (v > 0) {
        this->v = v; // atribui o número de vértices
        this->adj.resize(v);
    }
}

int Graph::addEdgeDirected(int v1, int v2)
{
    if(v1 < 0 || v2 < 0) return -1;
    
    adj[v1].push_back(v2);

    return 0;
}

int Graph::removeEdge(int v1, int v2)
{
    if(v1 < 0 || v2 < 0) return -1;
    
    if(v1 > (int)adj.size()) return 0;
    
    adj[v1].remove(v2);
    
    return 1;
}

bool Graph::existsNeighbor(int v1, int v2)
{
    for(auto it : adj[v1]){
        if(it == v2) return 1;
    }
    
    for(auto it : adj[v2]){
        if(it == v1) return 1;
    }
    
    return 0;
}


int Graph::outDegree(int v)
{
    return adj[v].size();
}

vector<list<int>> Graph::transposeGraph()
{
    vector<list<int>> answer;
    
    answer.resize(adj.size());
    
    for(int i = 0; i < (int)adj.size(); i++){
    for(auto j : adj[i]){
        answer[j].push_back(i);
    }}
    
    return answer;
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

void Graph::print(vector<list<int>> vet)
{
    for(int i=0; i < vet.size(); i++){
        cout << i << " -> ";
        for(auto it : vet[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}


