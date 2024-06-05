/***************************
Considere a representação de àrvores binárias BST dada nas aulas TPs. Implemente uma função booleana bool isBST(Node * root) que recebe a raíz de uma árvore binária com a estrutura de uma BST e verifica se é uma árvore binária de pesquisa (devolve true) ou não (devolve false).

***************************/

  
#include <iostream>
#include <stdlib.h>
#include "tree.hpp"


using namespace std;

bool isBST(Node * root)
{
    if(root == NULL) return true;
    if(root == nullptr) return false;
    
    
  if (root->left){
    if (root->item < root->left->item) return false;
    
    return isBST(root->left);
  }

  if (root->right){
    if (root->item > root->right->item) return false;
    
    return isBST(root->right);
  }
    
    return true;
}


// Driver code
int main()
{
  vector<int> vecTree1 = {-1, 3, 5, 2, 20,-1, 0, -1, 9, -1, -1, -1, -1, 14, -1, -1};  // NO
  vector<int> vecTree2 = {-1, 10, 5, 20, 2, 6, 15, 23};  // YES
  vector<int> vecTree3;  // YES


  Tree t1(vecTree1);
  cout << "Tree 1 " << std::boolalpha << isBST(t1.getRoot()) << endl;
  Tree t2(vecTree2);
  cout << "Tree 2 " << std::boolalpha << isBST(t2.getRoot()) << endl;
  Tree t3(vecTree3);
  cout << "Tree 3 " << std::boolalpha << isBST(t3.getRoot()) << endl;
 
  return 0;
}
