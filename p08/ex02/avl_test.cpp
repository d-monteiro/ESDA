#include <string>
#include <vector>
#include "avl.hpp"


int main()
{
    AVL *avl = new AVL(); 
    Node* root = avl->getRoot();
    vector<string> vtr{"G", "C", "A", "F", "L", "J", "V", "M", "N", "O"};

    /* Constructing tree given in
    the above figure */
    for (int i = 0; i<vtr.size(); i++){
        root = avl->insert(root, vtr[i]);
    }
    cout << "Inorder transversal of the AVL tree is "<< endl;
    avl->inOrder(root);

    cout << endl;
    cout << "Preorder traversal of the AVL tree is " << endl;
    avl->preOrder(root);
     
    cout << endl; 
    cout << "Number of node starting with x letter is "<< endl;  
    avl->countItemsStartingWith(root);
    return 0;

    delete root;
}
