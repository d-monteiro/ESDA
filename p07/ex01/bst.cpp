// Arvore Binária em C++ usando Classe e Struct

#include <iostream>
#include <stdlib.h>
#include "bst.hpp"

using namespace std;

Tree::Tree()
{ // inicializa arvore
  root = NULL;
}

Node *Tree::getRoot()
{
  return this->root;
}

void Tree::setRoot(Node *newRoot)
{
  this->root = newRoot;
}

void Tree::insert(string v)
{
  insert(root, v);
}

void Tree::insert(Node *treeNode, string v)
{
  if (!treeNode)
  {
    treeNode = new Node();
    treeNode->item = v;
    root = treeNode;
  }
  else
  {
    if (v < treeNode->item)
    {
      if (!treeNode->left)
      {
        Node *treeTemp = new Node();
        treeTemp->item = v;
        treeNode->left = treeTemp;
      }
      else
        insert(treeNode->left, v);
    }
    else
    {
      if (!treeNode->right)
      {
        Node *treeTemp = new Node();
        treeTemp->item = v;
        treeNode->right = treeTemp;
      }
      else
        insert(treeNode->right, v);
    }
  }
}

Node *Tree::search_node(string key)
{
  if (root == NULL)
    return NULL;        // se arvore vazia
  Node *current = root; // começa a procurar desde raiz
  while (current->item != key)
  { // enquanto nao encontrou
    if (key < current->item)
    {
      current = current->left; // caminha para esquerda
    }
    else
    {
      current = current->right; // caminha para direita
    }
    if (current == NULL)
    {
      return NULL; // encontrou uma folha -> sai
    }
  }               // fim laço while
  return current; // terminou o laço while e chegou aqui é pq encontrou item
}

bool Tree::remove(string value)
{
  if (root == NULL)
    return false; // se arvore vazia
  Node *current = root;
  Node *father = root;
  bool left_child = true;
  // ****** Buscando o valor **********
  while (current->item != value)
  { // enquanto nao encontrou
    father = current;
    if (value < current->item)
    { // caminha para esquerda
      current = current->left;
      left_child = true; // é filho a esquerda? sim
    }
    else
    { // caminha para direita
      current = current->right;
      left_child = false; // é filho a esquerda? NAO
    }
    if (current == NULL)
      return false; // encontrou uma folha -> sai
  }                 // fim laço while de busca do valor

  // **************************************************************
  // se chegou aqui quer dizer que encontrou o valor (v)
  // "atual": contem a referencia ao No a ser eliminado
  // "pai": contem a referencia para o pai do No a ser eliminado
  // "filho_esq": é verdadeiro se atual é filho a esquerda do pai
  // **************************************************************

  // Se nao possui nenhum filho (é uma folha), elimine-o
  if (current->left == NULL && current->right == NULL)
  {
    if (current == root)
      root = NULL; // se raiz
    else if (left_child)
      father->left = NULL; // se for filho a esquerda do pai
    else
      father->right = NULL; // se for filho a direita do pai
  }

  // Se é pai e nao possui um filho a direita, substitui pela subarvore a direita
  else if (current->right == NULL)
  {
    if (current == root)
      root = current->left; // se raiz
    else if (left_child)
      father->left = current->left; // se for filho a esquerda do pai
    else
      father->right = current->left; // se for filho a direita do pai
  }

  // Se é pai e nao possui um filho a esquerda, substitui pela subarvore a esquerda
  else if (current->left == NULL)
  {
    if (current == root)
      root = current->right; // se raiz
    else if (left_child)
      father->left = current->right; // se for filho a esquerda do pai
    else
      father->right = current->right; // se for  filho a direita do pai
  }

  // Se possui mais de um filho, se for um avô ou outro grau maior de parentesco
  else
  {
    Node *sucessor = node_sucessor(current);
    // Usando sucessor que seria o Nó mais a esquerda da subarvore a direita do No que deseja-se remover
    if (current == root)
      root = sucessor; // se raiz
    else if (left_child)
      father->left = sucessor; // se for filho a esquerda do pai
    else
      father->right = sucessor;     // se for filho a direita do pai
    sucessor->left = current->left; // acertando o ponteiro a esquerda do sucessor agora que ele assumiu
                                    // a posição correta na arvore
  }
  return true;
}

/* Calcula a altura da árvore a partir de um nó */
int Tree::getHeight(Node *treeNode)
{
    if(treeNode == nullptr) return -1;
    
    int l = getHeight(treeNode->left);
    int r = getHeight(treeNode->right);
    
    return 1+max(l,r);
}

/* Caminha em pre-ordem */
void Tree::preOrder(Node *treeNode)
{
    if(treeNode != nullptr){
        cout<<treeNode->item<<" ";
        preOrder(treeNode->left);
        preOrder(treeNode->right);
    }
}

/* Caminha em pos-ordem */
void Tree::posOrder(Node *treeNode)
{
    if(treeNode != nullptr){
        posOrder(treeNode->left);
        posOrder(treeNode->right);
        cout<<treeNode->item<<" ";
    }
}

int Tree::getHeight()
{
  return getHeight(root);
}

/* Encontra o no de menor valor */
string Tree::getMinNode()
{
  Node *current = root;
  Node *previous = NULL;
  while (current != NULL)
  {
    previous = current;
    current = current->left;
  }
  return previous->item;
}

/* Encontra o nó de maior valor */
string Tree::getMaxNode()
{
  Node *current = root;
  Node *previous = NULL;
  while (current != NULL)
  {
    previous = current;
    current = current->right;
  }
  return previous->item;
}

/* O sucessor é o No mais a esquerda da subarvore a direita do No que foi passado como parametro do metodo */
Node *Tree::node_sucessor(Node *del)
{ // O parametro é a referencia para o No que deseja-se apagar
  Node *sucessor_father = del;
  Node *sucessor = del;
  Node *current = del->right; // vai para a subarvore a direita

  while (current != NULL)
  { // enquanto nao chegar no Nó mais a esquerda
    sucessor_father = sucessor;
    sucessor = current;
    current = current->left; // caminha para a esquerda
  }
  // *********************************************************************************
  // quando sair do while "sucessor" será o Nó mais a esquerda da subarvore a direita
  // "sucessor_father" será o o pai de sucessor e "del" o Nó que deverá ser eliminado
  // *********************************************************************************

  if (sucessor != del->right)
  {                                                 // se sucessor nao é o filho a direita do Nó que deverá ser eliminado
    sucessor_father->left = sucessor_father->right; // pai herda os filhos do sucessor que sempre serão a direita
    // lembre que o sucessor nunca poderá ter filhos a esquerda, pois, ele sempre será o
    // Nó mais a esquerda da subarvore a direita do Nó del.
    // lembrando também que sucessor sempre será o filho a esquerda do pai

    sucessor->right = del->right; // guardando a referencia a direita do sucessor para
                                  // quando ele assumir a posição correta na arvore
  }
  return sucessor;
}