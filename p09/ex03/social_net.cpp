/*****************************************************************/
/*   Grafo c/ matriz de adjacencias | ESDA | LEEC | 2023/24      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include "social_net.hpp"

using namespace std;

SocialNetwork::SocialNetwork(int V) : V(V) {
    // Initialize the adjacency matrix with all entries as false (no friendships)
    adjacencyMatrix.resize(V, vector<bool>(V, false));
}

void SocialNetwork::printSocialNetwork() {
        cout << "Social Network Graph (Adjacency Matrix):" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Person " << i << ": ";
            for (int j = 0; j < V; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
}


void SocialNetwork::addFriendship(int u, int v) {
    // alínea a)
}

void SocialNetwork::findMutualFriends(int person1, int person2)
{
    // alínea b)
}

void SocialNetwork::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u = 0; u < V; ++u) {
        if (adjacencyMatrix[v][u] && !visited[u]) {
            DFSUtil(u, visited);
        }
    }
}

void SocialNetwork::findConnectedGroups() {
    
        // alínea c)

}