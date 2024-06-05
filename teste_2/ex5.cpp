#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

void makeList(list<int> *list_name, int n);
void printList(list<int> *list_name);
list<int> copyList(list<int> *list_name);
int getLastElementFromList(list<int> *list_name);
void testSwapHeadAndTail(int value, list<int> *list_orig, list<int> *list_copy);
void testReverseLastElements(int value, list<int> *list_orig, list<int> *list_rev);

/** 
 *  @brief  Trocar, entre si, os elementos na cabeça e na cauda da lista.
 *  @param  list_name apontador para uma lista de inteiros
 *  @return -1 em caso de erro || 0 em caso de sucesso
 */
int swapHeadAndTail(list<int> *list_name)
{
    if(!list_name || list_name->empty()) return -1;
    
    if(list_name->size() == 1) return 0;
    
    iter_swap(list_name->begin(), prev(list_name->end()));
    /*
    int temp = list_name->front();
    list_name->front() = list_name->back();
    list_name->back() = temp;
    */
    return 0;
}

/** 
 *  @brief  Inverter os últimos k elementos de uma lista.
 *  @param  list_name apontador para uma lista de inteiros
 *  @param  k número de elementos a inverter
 *  @return -1 em caso de erro || 0 em caso de sucesso
 *  @note   k deve ser um número não negativo
 */
int reverseLastElements(list<int> *list_name, int k)
{
    if(list_name == nullptr || list_name->empty() || k <= 0 || k > (int)list_name->size()) return -1;
    
    vector<int> aux;
    
    for(int i = 0; i < k; i++){
        aux.push_back(list_name->back());
        list_name->pop_back();
    }
    
    for(auto i : aux){
        list_name->push_back(i);
    }
    
    return 0;
}

/* ----------------------------- */
/* -------- NÃO ALTERAR -------- */
/* ----------------------------- */

int main()
{
	srand((unsigned) time(NULL)); // Seed
    int result;
    
    list<int> *ls_n = nullptr;
    list<int> *ls_emp = new list<int>;

    list<int> *ls1 = new list<int>;
    makeList(ls1, 3);
    list<int> ls1_cpy = copyList(ls1);
    
    list<int> *ls2 = new list<int>;
    makeList(ls2, 8);
    list<int> ls2_cpy = copyList(ls2);

    list<int> *ls3 = new list<int>;
    makeList(ls3, 20);
    list<int> ls3_cpy = copyList(ls3);

    list<int> *ls4 = new list<int>;
	makeList(ls4, 5);
    list<int> ls4_cpy = copyList(ls4);

    list<int> *ls5 = new list<int>;
	makeList(ls5, 1);
    list<int> ls5_cpy = copyList(ls5);

    /* ++ Exercício  3a) ++ */
    
    /* Testes escondidos */
    result = swapHeadAndTail(ls_n); // null list
    testSwapHeadAndTail(result, ls_n, nullptr);

    result = swapHeadAndTail(ls_emp); // empty list
    testSwapHeadAndTail(result, ls_emp, nullptr);

    result = swapHeadAndTail(&ls1_cpy);
    testSwapHeadAndTail(result, ls1, &ls1_cpy);
    /* ----------------- */

    /* Testes visíveis */
    result = swapHeadAndTail(&ls2_cpy);
    testSwapHeadAndTail(result, ls2, &ls2_cpy);

    result = swapHeadAndTail(&ls3_cpy);
    testSwapHeadAndTail(result, ls3, &ls3_cpy);

    result = swapHeadAndTail(&ls4_cpy);
    testSwapHeadAndTail(result, ls4, &ls4_cpy);

    result = swapHeadAndTail(&ls5_cpy);
    testSwapHeadAndTail(result, ls5, &ls5_cpy);
    /* --------------- */

    /* ++ Exercício  3b) ++ */

    /* Testes escondidos */
    result = reverseLastElements(ls_emp, 0); // empty list
    testReverseLastElements(result, ls_emp, nullptr);

    *ls1 = copyList(&ls1_cpy);
    result = reverseLastElements(&ls1_cpy, ls1_cpy.size() + 1);
    testReverseLastElements(result, ls1, &ls1_cpy);

    result = reverseLastElements(&ls1_cpy, 2);
    testReverseLastElements(result, ls1, &ls1_cpy);
    /* ----------------- */

    /* Testes visíveis */
    result = reverseLastElements(ls_n, 0); // null list
    testReverseLastElements(result, ls_n, nullptr);

    *ls2 = copyList(&ls2_cpy);
    result = reverseLastElements(&ls2_cpy, -2);
    testReverseLastElements(result, ls2, &ls2_cpy);

    *ls3 = copyList(&ls3_cpy);
    result = reverseLastElements(&ls3_cpy, 6);
    testReverseLastElements(result, ls3, &ls3_cpy);

    *ls4 = copyList(&ls4_cpy);
    result = reverseLastElements(&ls4_cpy, 1);
    testReverseLastElements(result, ls4, &ls4_cpy);
    /* --------------- */

    delete ls_emp;
    delete ls1;
    delete ls2;
    delete ls3;
    delete ls4;
    delete ls5;

    return 0;
}

/* +++ Funções utilitárias +++ */

/** 
 *  @brief  Preencher uma lista de inteiros.
 *  @param  list_name apontador para uma lista de inteiros
 *  @param  n número de elementos a adicionar à lista
 *  @return void
 */
void makeList(list<int> *list_name, int n)
{
	for (int i = 0; i < n; i++)
        list_name->push_back(-100 + (rand() % 201)); // generate random number between -100 and 100 and insert in list
}

/** 
 *  @brief  Imprimir os elementos da lista.
 *  @param  list_name apontador para uma lista de inteiros
 *  @return void
 */
void printList(list<int> *list_name)
{
    for (auto it = list_name->begin(); it != list_name->end(); it++) {
        if (it == list_name->begin()) cout << *it;
        else cout << " -> " << *it;
    }
    cout << endl;
}

/** 
 *  @brief  Copiar os elementos de uma lista para outra.
 *  @param  list_name apontador para uma lista de inteiros
 *  @return Lista copiada da lista original
 */
list<int> copyList(list<int> *list_name)
{
    list<int> list_copy;
    for (auto it = list_name->begin(); it != list_name->end(); it++)
        list_copy.push_back(*it);
    return list_copy;
}

/** 
 *  @brief  Obter o último elemento de uma lista.
 *  @param  list_name apontador para uma lista de inteiros
 *  @return Valor do último elemento de uma lista.
 */
int getLastElementFromList(list<int> *list_name)
{
    auto it = list_name->begin();
    for (size_t i = 0; i < list_name->size() - 1; i++) it++;
    return *it;
}

/** 
 *  @brief  Função de teste da função 'swapHeadAndTail'.
 *  @param  value valor de retorno da função 'swapHeadAndTail'
 *  @param  list_orig lista com os elementos originais
 *  @param  list_swap lista com os elementos após a aplicação da função 'swapHeadAndTail'
 *  @return void
 */
void testSwapHeadAndTail(int value, list<int> *list_orig, list<int> *list_swap)
{
    if (value == -1) cout << "swapHeadAndTail(): ERRO\n\n";
    else if (value == 0) {
        cout << "swapHeadAndTail(): OK\n";
        
        if (*(list_orig->begin()) == getLastElementFromList(list_swap) && getLastElementFromList(list_orig) == *(list_swap->begin()))
            cout << "\tElementos da cabeça e da cauda nas posições corretas: OK\n";
        else return;
        
        if (list_orig->size() == list_swap->size()) cout << "\tTamanho igual: OK\n";
        else return;

        cout << "\tLista original: ";
        printList(list_orig);
        cout << "\tLista após troca: ";
        printList(list_swap);
        cout << endl;
    }
}

/** 
 *  @brief  Função de teste da função 'reverseLastElements'.
 *  @param  value valor de retorno da função 'reverseLastElements'
 *  @param  list_orig lista com os elementos originais
 *  @param  list_rev lista com os elementos após a aplicação da função 'reverseLastElements'
 *  @return void
 */
void testReverseLastElements(int value, list<int> *list_orig, list<int> *list_rev)
{
    if (value == -1) cout << "reverseLastElements(): ERRO\n\n";
    else if (value == 0) {
        cout << "reverseLastElements(): OK\n";
        
        if (list_orig->size() == list_rev->size()) cout << "\tTamanho igual: OK\n";
        else return;

        cout << "\tLista original: ";
        printList(list_orig);
        cout << "\tLista após inversão: ";
        printList(list_rev);
        cout << endl;
    }
}