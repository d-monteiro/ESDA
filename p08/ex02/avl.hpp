#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <stdlib.h>
using namespace std;

/* Tree node
    item - node content
    left - left node pointer
    right - right node pointer
*/
class Node
{
    public:
        string item;
        Node *left;
        Node *right;
        int height;
        Node(string item);  // Constructor that creates a new node with the given item as its content, and initializes the left and right pointers to NULL
};


class AVL
{
    private:
        Node *root;
        int getBalance(Node *N); // A method to get the balance factor of a node (the difference between the heights of its left and right subtrees). If the node is NULL, it returns 0.
        Node* rightRotate(Node *node);  //A method that performs a right rotation on the node and returns a pointer to the new root.
        Node* leftRotate(Node *node); //A method that performs a left rotation on the node and returns a pointer to the new root.
        string maxString(string a, string b); //A utility function to get maximum of two strings
        void countItemsStartingWith(Node* node, char letter, int& count, vector<int>& letterCounts);  //A helper method that counts the number of nodes in the subtree rooted at the node that have an item starting with the given letter. Stores the count in the given count parameter, and updates the counts of each letter in the letterCounts vector.
    
    public: 
        int height(Node *node); //A method that returns the height of the node. If the node is NULL, it returns 0.
        Node* insert(Node* node, string item); //A  method that inserts a  new item into the AVL tree rooted at node.
        void inOrder(Node *root); //a recursive function that  takes a node as input and recursively call itself on the left of the node, prints the item of the node, and then recursively calls itself on the right of the node.
        void preOrder(Node *root); //A recursive function that takes a node as input and prints the item of the node, and then recursively calls itself on the left and right subtrees of the node.
        Node* getRoot(); //A getter method that returns a pointer to the root of the AVL tree.
        AVL(); //Constructor that initializes the root pointer to NULL
        void countItemsStartingWith(Node* node);//A method that counts the number of nodes in the AVL tree that have an item starting with each letter of the alphabet, and prints the counts and the total letter counts.
    /*public:
        void countItemsStartingWith(Node* node);//A method that counts the number of nodes in the AVL tree that have an item starting with each letter of the alphabet, and prints the counts and the total letter counts.
    */
};

#endif