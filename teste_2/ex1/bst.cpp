#include <iostream>
#include "bst.hpp"

using namespace std;

/* ------------------------------ */
/* --------- CLASS Tree --------- */
/* ------------------------------ */

/* CONSTRUTOR */

Tree::Tree()
{
    root = nullptr;
}

/* DESTRUTOR */

Tree::~Tree()
{
    delete root;
}

/* MÉTODOS GET */

Node* Tree::getRoot()
{
    return root;
}

/* OUTROS MÉTODOS */

void Tree::preOrder(Node *tree_node)
{
    if (tree_node) {
        cout << tree_node->data << " ";
        preOrder(tree_node->left);
        preOrder(tree_node->right);
    }
}

Node* Tree::searchNode(uint data)
{
    if (!root) return nullptr;
    
    Node* current = root;
    while (current->data != data) {
        if (data < current->data) current = current->left;
        else current = current->right;
        if (!current) return nullptr;
    }
    return current;
}

void Tree::insert(Node *tree_node, uint data)
{
    if (!root) root = new Node(data);
    else {
        if (data > tree_node->data) {
            if (!tree_node->right) tree_node->right = new Node(data);
            insert(tree_node->right, data); // right subtree
        } else if (data < tree_node->data) {
            if (!tree_node->left) tree_node->left = new Node(data);
            insert(tree_node->left, data); // left subtree
        }
    }
}

int Tree::getHeight(Node *tree_node)
{
    if (!tree_node) return -1;
    else {
        int height_left = getHeight(tree_node->left);
        int height_right = getHeight(tree_node->right);
        // use larger value
        if (height_left > height_right) return height_left + 1;
        else return height_right + 1;
    }
}

int Tree::getLevel(Node *search_node, Node *tree_node, int level)
{
    if (!tree_node) return 0;
    if (tree_node->data == search_node->data) return level;
    
    int l = getLevel(search_node, tree_node->left, level + 1);
    if (l) return l;
    l = getLevel(search_node, tree_node->right, level + 1);
    return l;
}

uint Tree::prodReplace(Node *tree_node)
{
    /* Implementar 1a) */
}

void Tree::printSibling(Node *search_node, Node *tree_node)
{
    /* Implementar 1b) */
}

