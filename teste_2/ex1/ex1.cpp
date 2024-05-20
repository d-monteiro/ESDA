#include <iostream>
#include <vector>
#include "bst.hpp"
#include "bst.cpp"

using namespace std;

void createTree(Tree *tree, vector<uint> vec);
void testPrintSibling(Tree *tree, Node *node);
void testProdReplace(Tree *tree);

/* ----------------------------- */
/* -------- NÃO ALTERAR -------- */
/* ----------------------------- */

int main()
{
    Tree bst, bst1, bst2, bst3, bst4, bst5, bst6;
    vector<uint> v1, v2, v3;

    v1 = {10, 12, 5, 4, 20, 8, 7, 15, 13};
    v2 = {25, 36, 20, 22, 10, 12, 5, 8, 1, 15, 40, 30, 28, 38, 48, 50, 45};
    v3 = {2, 1, 4, 3, 5};

    createTree(&bst1, v1);
    createTree(&bst2, v2);
    createTree(&bst3, v3);
    createTree(&bst4, v1);
    createTree(&bst5, v2);
    createTree(&bst6, v3);

     cout << "\n++ Exercício 1a) ++\n\n";

    testProdReplace(&bst5);
    testProdReplace(&bst6);

    cout << "\n++ Exercício 1b) ++\n\n";

    testPrintSibling(&bst1, bst1.searchNode(1)); // non-existing node
    testPrintSibling(&bst1, bst1.searchNode(13)); // no sibling
    testPrintSibling(&bst1, bst1.searchNode(8));
    testPrintSibling(&bst2, bst2.searchNode(12));
    testPrintSibling(&bst2, bst2.searchNode(50));

   

    return 0;
}

/* +++ Funções utilitárias +++ */

/**
 *  @brief  Preencher uma BST.
 *  @param  tree apontador para a árvore
 *  @param  vec vetor com os valores dos nós a inserir na árvore 
 *  @return void
 */
void createTree(Tree *tree, vector<uint> vec)
{
    for (int i = 0; i < (int)vec.size(); i++) tree->insert(tree->getRoot(), vec[i]);
}

/**
 *  @brief  Função de teste da função 'printSibling'.
 *  @param  tree apontador para a árvore
 *  @param  node apontador para o nó
 *  @return void
 */
void testPrintSibling(Tree *tree, Node *node)
{
    cout << "printSibling():\n";
    cout << "   Irmão de ";
    if (node) cout << node->data;
    else cout << "?";
    cout << ": ";
    tree->printSibling(node, tree->getRoot());
    cout << endl << endl;
}

/**
 *  @brief  Função de teste da função 'prodReplace'.
 *  @param  tree apontador para a árvore
 *  @return void
 */
void testProdReplace(Tree *tree)
{
    cout << "prodReplace():\n";
    cout << "   Árvore original: ";
    tree->preOrder(tree->getRoot());
    cout << endl;
    tree->prodReplace(tree->getRoot());
    cout << "   Árvore produto: ";
    tree->preOrder(tree->getRoot());
    cout << endl << endl;
}