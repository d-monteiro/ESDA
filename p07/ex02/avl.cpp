#include <iostream>
#include <stdlib.h>
#include "avl.hpp"

using namespace std;

AvlTree::AvlTree()
{
    root = NULL;
}

Node *AvlTree::getRoot()
{
    return this->root;
}

void AvlTree::setRoot(Node *newRoot)
{
    this->root = newRoot;
}

void AvlTree::insert(string value)
{
    insert(root, value);
}

void AvlTree::insert(Node *treeNode, string value)
{
    /* Alinea b */

    if (!treeNode)
    {
        treeNode = new Node();
        treeNode->item = value;
        root = treeNode;
    }
    else
    {
        if (value < treeNode->item)
        {
            if (!treeNode->left)
            {
                Node *treeTemp = new Node();
                treeTemp->item = value;
                treeNode->left = treeTemp;
            }
            else
                insert(treeNode->left, value);
        }
        else
        {
            if (!treeNode->right)
            {
                Node *treeTemp = new Node();
                treeTemp->item = value;
                treeNode->right = treeTemp;
            }
            else
                insert(treeNode->right, value);
        }
    }
}

/* Calcula a altura da árvore a partir de um nó */
int AvlTree::getHeight(Node *current)
{
    if (current == NULL || (current->left == NULL && current->right == NULL))
        return 0;
    else
    {
        if (getHeight(current->left) > getHeight(current->right))
            return (1 + getHeight(current->left));
        else
            return (1 + getHeight(current->right));
    }
}

/* Imprime a arvore */
void AvlTree::printTree(Node *current)
{
    if (current != NULL)
    {
        cout << current->item << " " << current->height << endl;
        printTree(current->left);
        printTree(current->right);
    }
}

/* Testa se a arvore está balanceada */
bool AvlTree::isBalanced(Node *treeNode)
{
  /* Alinea c */
}
