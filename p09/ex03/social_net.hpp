#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

class SocialNetwork
{
    private:
        int V; // Number of vertices (people)
        vector<vector<bool>> adjacencyMatrix; // Adjacency matrix representing friendships

    public:
        // Initialize the adjacency matrix with all entries as false (no friendships)
        SocialNetwork(int V);

        void printSocialNetwork();
        
        void addFriendship(int u, int v); // For undirected graph
        
        void findMutualFriends(int person1, int person2);

        void DFSUtil(int v, vector<bool>& visited);
        
        void findConnectedGroups();

};

#endif