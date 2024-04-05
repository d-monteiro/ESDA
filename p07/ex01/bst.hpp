#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <stdlib.h>

using namespace std;

/* No da arvore
    item - conteúdo do nó
    left - apontador para o nó a esquerda
    right - apontador para o nó a direita
*/
struct Node
{
    string item;
    Node *left;
    Node *right;
};

class Tree
{
    
private:
    /* ATRIBUTOS
        root - raiz da árvore
    */
    Node *root;
    void insert(Node *treeNode, string v);
    int  getHeight(Node *treeNode);

public:
    Tree();
    Node *getRoot();
    void setRoot(Node *newRoot);
    void insert(string v);
    Node *search_node(string key);
    bool remove(string value);
    void posOrder(Node *current);
    void preOrder(Node *current);
    int getHeight();
    string getMinNode();
    string getMaxNode();
    Node *node_sucessor(Node *del);
};

#endif