#ifndef BST_HPP
#define BST_HPP

using namespace std;

/**
 *  @brief Nó de uma BST.
 */
struct Node
{
    /**
     *  @brief Conteúdo do nó.
     */
    uint data;

    /**
     *  @brief Apontador para o filho esquerdo do nó.
     */
    Node *left;

    /**
     *  @brief Apontador para o filho direito do nó.
     */
    Node *right;
    
    /**
     *  @brief Construtor.
     */
    Node(uint data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
    
    /**
     *  @brief Destrutor.
     */
    ~Node()
    {
        delete left;
        delete right;
    }
};

/**
 *  @brief BST - Árvore binária de pesquisa.
 */
class Tree
{ 
    private:
        /**
         *  @brief Apontador para a raiz da árvore.
         */
        Node *root;

    public:
        /* CONSTRUTOR */

        /** 
         *  @brief Construtor default
         *  @note  A raiz é inicializada a 'nullptr'.
         */
        Tree();


        /* DESTRUTOR */

        /** 
         *  @brief Destrutor
         *  @note  Remove, em memória, a árvore (apagar a raiz).
         */
        ~Tree();


        /* MÉTODOS GET */

        /** 
         *  @brief  Obter a raiz da árvore.
         *  @param  none
         *  @return 'root'
         */
        Node* getRoot();
        
        
        /* OUTROS MÉTODOS */

        /** 
         *  @brief  Imprimir a árvore, em pré-ordem.
         *  @param  tree_node apontador para nó da árvore
         *  @return void
         */
        void preOrder(Node *tree_node);

        /** 
         *  @brief  Procurar determinado nó na árvore.
         *  @param  data conteúdo do nó que se pretende pesquisar
         *  @return apontador para o nó encontrado || nullptr caso não seja encontrado ou em caso de erro
         */
        Node* searchNode(uint data);

        /** 
         *  @brief  Adicionar à árvore um novo nó.
         *  @param  tree_node nó pai (tentativa) para inserção do novo nó
         *  @param  data conteúdo do nó a inserir
         *  @return void
         */
        void insert(Node *tree_node, uint data);

        /** 
         *  @brief  Calcular a altura de um nó da árvore.
         *  @param  tree_node apontador para nó da árvore
         *  @return altura do nó || -1 em caso de erro
         */
        int getHeight(Node *tree_node);

        /** 
         *  @brief  Calcular o nível de um nó da árvore.
         *  @param  search_node apontador para nó do qual se pretende conhecer o nível
         *  @param  tree_node apontador para nó da árvore
         *  @param  level nível do nó
         *  @return nível do nó || 0 em caso de erro
         *  @note   O nível da raiz é igual a um.
         */
        int getLevel(Node *search_node, Node *tree_node, int level);

        /** 
         *  @brief  Imprimir o irmão de determinado nó.
         *  @param  search_node apontador para nó do qual se pretende conhecer o irmão
         *  @param  tree_node apontador para nó da árvore
         *  @return void
         *  @note   A função é recursiva e percorre a árvore em pré-ordem.
         *  @note   Dois nós são irmãos caso estejam ao mesmo nível na árvore e tenham o mesmo pai.
         *  @note   Recorrer à função 'getLevel' (exemplo: nível de 'search_node' -> int lev = getLevel(search_node, root, 1);).
         */
        void printSibling(Node *search_node, Node *tree_node);

        /** 
         *  @brief  Transformar a árvore na correspondente árvore produto.
         *  @param  tree_node apontador para nó da árvore
         *  @return produto entre o novo conteúdo do nó e o antigo valor
         *  @note   A função é recursiva e percorre a árvore em pós-ordem.
         *  @note   Em cada nó, é guardado o produto dos valores dos nós das subárvores da esquerda e da direita.
         *  @note   O número de nós é mantido. Nós sem filhos têm um correspondente produto igual a um.
         */
        uint prodReplace(Node *tree_node);
};

#endif
