#include <iostream>
#include <string>

using namespace std;
// Classe Car para representar os dados dos nós da árvore
class Car {
public:
    string brand;
    string model;
    int year;

    // Construtor
    Car(string brand, std::string model, int year) : brand(brand), model(model), year(year) {}
};

// Definição da classe Node
class Node {
public:
    Car* car;
    Node* left;
    Node* right;

    // Construtor
    Node(Car* car) : car(car), left(nullptr), right(nullptr) {}
};

// Definição da classe BST (Binary Search Tree)
class BST {
private:
    Node* root;

    // Função auxiliar para inserir um nó na árvore
    Node* insertNode(Node* root, Car* car) {
        // Se a árvore estiver vazia, cria um novo nó e o retorna
        if (root == nullptr) {
            return new Node(car);
        }

        // Compara os dados do carro para decidir onde inserir o nó
        if (car->brand < root->car->brand) {
            root->left = insertNode(root->left, car);
        } else if (car->brand > root->car->brand) {
            root->right = insertNode(root->right, car);
        } else if (car->model < root->car->model) { 
            root->left = insertNode(root->left, car);
           } else if (car->model > root->car->model) { 
            root->right = insertNode(root->right, car);
        }

        return root;
    }

    // Função auxiliar para encontrar o nó mínimo de uma subárvore
    Node* findMinNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Função auxiliar para excluir um nó da árvore
    Node* deleteNode(Node* root, string cbrand, string cmodel) {
        // Caso base: árvore vazia
        if (root == nullptr) {
            return root;
        }

        // Se a marca do carro a ser excluído for menor que a marca do nó atual, procura na subárvore esquerda
        if (cbrand < root->car->brand) {
            root->left = deleteNode(root->left, cbrand, cmodel);
        }
        // Se a marca do carro a ser excluído for maior que a marca do nó atual, procura na subárvore direita
        else if (cbrand > root->car->brand) {
            root->right = deleteNode(root->right, cbrand, cmodel);
        }
        // Se o modelo do carro a ser excluído for menor que o modelo do nó atual, procura na subárvore esquerda
        else if (cmodel < root->car->model) {
                root->left = deleteNode(root->left, cbrand, cmodel);
        }   
         // Se o modelo do carro a ser excluído for maior que o modelo do nó atual, procura na subárvore esquerda
        else if (cmodel > root->car->model) {
                root->right = deleteNode(root->right, cbrand , cmodel);
        }  
        // Se o ano for igual ao ano do nó atual, este é o nó a ser excluído
        else {
            // Caso 1: nó sem filhos ou com apenas um filho
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Caso 2: nó com dois filhos
            // Encontra o nó mínimo da subárvore direita (o sucessor)
            Node* temp = findMinNode(root->right);
            // Copia os dados do sucessor para este nó
            root->car = temp->car;

            // Exclui o sucessor
            root->right = deleteNode(root->right, temp->car->brand, temp->car->model);
        }
        return root;
    }

    // Função auxiliar para imprimir os nós em ordem
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->car->brand << " " << root->car->model << " " << root->car->year << endl;
            inorderTraversal(root->right);
        }
    }

public:
    // Construtor
    BST() : root(nullptr) {}

    Node* getRoot() {return root;}

    // Método público para inserir um carro na árvore
    void insert(Car* car) {
        root = insertNode(root, car);
    }

    // Método público para remover um carro da árvore com base no ano
    void remove(string cbrand,string cmodel) {
        root = deleteNode(root, cbrand, cmodel);
    }

    // Método público para imprimir os carros em ordem de ano
    void inorder() {
        inorderTraversal(root);
    }

    // pergunta a - Quantos carros existem num determinado ano
    int carsYear(Node* root,int cyear)
    {
        if (root == nullptr) return 0;
        
        int count = 0;
        
        if (root->car->year == cyear) count+=1;
            
        int leftCount = carsYear(root->left, cyear);
        int rightCount = carsYear(root->right, cyear);
        
        return count + leftCount + rightCount;
    }

    void printbrand(Node* root,string cbrand)
    {
        if (root == nullptr) return;
        
        if (root->car->brand == cbrand) cout<<root->car->model<<"\n";
        
        printbrand(root->left, cbrand);
        
        printbrand(root->right, cbrand);
    }

 
};

int main() {
    // Criando alguns carros
    Car* car1 = new Car("Toyota", "Corolla", 2018);
    Car* car2 = new Car("Honda", "Civic", 2019);
    Car* car3 = new Car("Ford", "Mustang", 2020);
    Car* car4 = new Car("Chevrolet", "Camaro", 2017);
    Car* car5 = new Car("BMW", "X5", 2021);
    Car* car6 = new Car("Toyota", "Yaris", 2016);
    Car* car7 = new Car("Toyota", "Argo", 2020);
    Car* car8 = new Car("Honda", "Cr-v", 2022);

    // Criando uma árvore BST e inserindo os carros
    BST bst;
    bst.insert(car1);
    bst.insert(car2);
    bst.insert(car3);
    bst.insert(car4);
    bst.insert(car5);
    bst.insert(car6);
    bst.insert(car7);
    bst.insert(car8);

    // Imprimir os carros em marca e modelo
    cout << "Carros em ordem de marca e modelo:\n"<<endl<<endl;
    bst.inorder();
    
    //teste à pergunta ab)
    // Quantidade de carros de um ano

    int cyear=2020;
    cout <<"Total de carro do ano "<<cyear<<":"<<bst.carsYear(bst.getRoot(),cyear)<<endl<<endl;



    //teste à pergunta b)
    // Imprimir modelos de uma determinada marca
    string cbrand="Toyota";
    cout <<cbrand<<":"<<endl;
    bst.printbrand(bst.getRoot(),cbrand);
    return 0;
}