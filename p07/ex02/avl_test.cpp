#include <iostream>
#include <string>
#include <vector>
#include "avl.hpp"

using namespace std;

int main()
{
    AvlTree avl_tree;

    /* Alínea b */
    cout << "\n Inserir elementos na árvore: " << endl;
    vector<string> vtr{"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"};
    for (int i = 0; i < vtr.size(); i++)
    {
        avl_tree.insert(vtr[i]);
    }
    cout << "\n Elementos inseridos com sucesso" << endl;
    Node *root = avl_tree.getRoot();
    avl_tree.printTree(root);

    /* Alínea c */
    cout << "\nVerfificar se a arvore esta balanceada: " << endl;
    if (avl_tree.isBalanced(root))
    {
        cout << "A arvore esta balanceada:" << endl;
    }
    else
    {
        cout << "A arvore nao esta balanceada" << endl;
    }
}