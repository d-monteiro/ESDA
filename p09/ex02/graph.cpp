/*****************************************************************/
/*   Grafo c/ lista de adjacencias | ESDA | LEEC | 2023/24      */      
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

int Graph::addEdgeUndirected(int v1, int v2)
{
    if(v1 < 0 || v2 < 0) return -1;
    
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);

    return 0;
}

int Graph::identifyOverload()
{
    int max = 0;
    int pos = 0;
    
    for(int i = 0; i < (int)adj.size(); ++i){
        if((int)adj[i].size() >= max){
            max = (int)adj[i].size();
            pos = i;
        }
    }
    
    return pos;
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

