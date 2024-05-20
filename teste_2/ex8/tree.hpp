#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

/* No da arvore
    item - conteúdo do nó
    left - apontador para o nó a esquerda
    right - apontador para o nó a direita
*/
struct Node
{
  int item;
  Node *left;
  Node *right;
};

class Tree{
private:
  Node *root;
  int  getHeight(Node *treeNode);
  Node * treeFromVector(int idx, vector <int> vecTree);

public:
  Tree();
  Tree(vector <int> vecTree);
  Node *getRoot();
  Node *getLeftTree();
  Node *getRightTree();
  int getItem();
};


/***************************************
  IMPLEMENTATION
**************************************/

// default Constructor
Tree::Tree(){ // inicializa arvore
  root = NULL;
}

// constructer with inital tree (stored in a vector)
Tree::Tree(vector <int> initVector){ // inicializa arvore usando um vector
  if (initVector.size() == 0){
    root =  NULL;
  }
  else
    root = treeFromVector(1, initVector);
}

// scan vector ... build tree
Node * Tree::treeFromVector(int idx, vector <int> vecTree){

  if (idx > vecTree.size() - 1 || vecTree[idx] == -1)
    return NULL;

  Node * Tnode = new Node();
  Tnode->item = vecTree[idx];
  int leftIdx = idx * 2;
  Tnode->left = treeFromVector(leftIdx, vecTree);
  int rightIdx = idx * 2 + 1;
  Tnode->right = treeFromVector(rightIdx, vecTree);

  return Tnode;
}

Node *Tree::getRoot()
{
  return this->root;
}
#endif
