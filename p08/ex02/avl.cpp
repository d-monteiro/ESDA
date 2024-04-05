#include <string>
#include <vector>
#include "avl.hpp"

using namespace std;


string AVL::maxString(string a, string b)
{
    return (a > b)? a : b;
}


Node::Node(string item)
{
    this->item = item;
    left = NULL;
    right = NULL;
    height = 1; // new node is initially
                // added at leaf
}


AVL::AVL()
{ 
  this->root = NULL;
}

Node* AVL::getRoot(){
    return this->root;
}


int AVL::height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}


Node* AVL::rightRotate(Node *node)
{
    Node *temp = node->left;
    Node *temp2 = temp->right;
 
    // Perform rotation
    temp->right = node;
    node->left = temp2;
 
    // Update heights
    node->height = max(height(node->left),
                    height(node->right)) + 1;
    temp->height = max(height(temp->left),
                    height(temp->right)) + 1;
 
    // Return new root
    return temp;
}
 

Node* AVL::leftRotate(Node *node)
{
    Node *temp = node->right;
    Node *temp2 = temp->left;
 
    // Perform rotation
    temp->left = node;
    node->right = temp2;
 
    // Update heights
    node->height = max(height(node->left),   
                    height(node->right)) + 1;
    temp->height = max(height(temp->left),
                    height(temp->right)) + 1;
 
    // Return new root
    return temp;
}
 

int AVL::getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
 

Node* AVL::insert(Node* node, string item)
{
    // The insertion is the same we had with BST trees */
    if (node == NULL)
        return(node = new Node(item));
 
    if (item < node->item)
        node->left = insert(node->left, item);
    else if (item > node->item)
        node->right = insert(node->right, item);
    else // Equal items are not allowed in BST
        return node;
 
    // Update the height of the node
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    // Get the balance factor
    int balance = getBalance(node);
 
    // If unbalanced
 
    // Left Left Case
    if (balance > 1 && item < node->left->item)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && item > node->right->item)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && item > node->left->item)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && item < node->right->item)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    //If not unbalanced
    return node;
}
 

void AVL::inOrder(Node *root){
    //Alinea a
}


void AVL::preOrder(Node *root)
{
    //Alinea b
}

void AVL::countItemsStartingWith(Node* node, char letter, int& count, vector<int>& letterCounts) {
    //Alinea c
}

void AVL::countItemsStartingWith(Node* node) {
    vector<int> letterCounts(26, 0); // initialize counts for all letters to 0
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        int count = 0;
        countItemsStartingWith(node, letter, count, letterCounts); 
        if (count > 0) {
            cout << "Number of items starting with " << letter << ": " << count << endl;
        }
    }
    cout << "Letter counts: ";
    for (int count : letterCounts) {
        cout << count << " ";
    }
    cout << endl;
}
 

