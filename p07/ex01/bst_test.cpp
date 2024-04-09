#include <iostream>
#include <string>
#include <vector>
#include "bst.hpp"

using namespace std;

int main()
{
    Tree obj_tree;

    int option;
    cout << ("\n Programa Arvore binaria de string");
    do
    {
        cout << "\n***********************************";
        cout << "\nEntre com a opcao:";
        cout << "\n ----1: Inserir";
        cout << "\n ----2: Calcular altura";
        cout << "\n ----3: Caminhar em pre-ordem";
        cout << "\n ----4: Caminhar em pos-ordem";
        cout << "\n ----5: Remover";
        cout << "\n ----6: Sair do programa";
        cout << "\n***********************************";
        cout << "\n-> ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            /* Alínea a */
            vector<string> vtr{"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"};

            Node F = {vtr[3], nullptr, nullptr};
            Node A = {vtr[2], nullptr, nullptr};
            Node C = {vtr[1], &A, &F};

            Node O = {vtr[9], nullptr, nullptr};
            Node N = {vtr[8], nullptr, &O};
            Node M = {vtr[7], nullptr, &N};
            Node V = {vtr[6], &M, nullptr};
            Node J = {vtr[5], nullptr, nullptr};
            Node L = {vtr[4], &J, &V};

            Node root = {vtr[0], &C, &L};

            obj_tree.setRoot(&root);
            
            cout << "\n Elementos inseridos com sucesso" << endl;
            break;
        }
        case 2:
        {
            Node *root = obj_tree.getRoot();
            cout << "\n\n Altura da árvore: " << obj_tree.getHeight() << endl;
            break;
        }
        case 3:
        {
            cout << "\n\n Exibindo em pré-ordem: ";
            Node *root = obj_tree.getRoot();
            obj_tree.preOrder(root);
            delete root;
            break;
        }
        case 4:
        {
            cout << "\n\n Exibindo em pos-ordem: ";
            Node *root = obj_tree.getRoot();
            obj_tree.posOrder(root);
            delete root;
            break;
        }
        case 5:
        {
            cout << "\n Informe o valor (string) -> " << endl;
            string value = "N";
            obj_tree.remove(value);
            break;
        }
        }
    } while (option != 6);

    return 0;
}