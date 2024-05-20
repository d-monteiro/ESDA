#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <iomanip> 

using namespace std;

void makeList(list<int> *list_name, int n);
void printList(list<int> *list_name);
list<int> copyList(list<int> *list_name);

void printListfloat(list<float> list_name);

int removeElements(list<int> *list1, int n)
{
    
}



/* ----------------------------- */
/* -------- NÃO ALTERAR -------- */
/* ----------------------------- */

int main()
{
	

    /* ++ Exercício  3a) ++ */

    list<int> *ls1 = new list<int>;
    ls1->push_back(24);
    ls1->push_back(14);
    ls1->push_back(4);
    ls1->push_back(22);
    ls1->push_back(2);
    ls1->push_back(30);
    ls1->push_back(1);
    cout <<"original list: "<<endl;
    printList(ls1);
    
    cout <<"return value: "<<removeElements(ls1, 10)<<endl;
    cout <<"final list: "<<endl;
    printList(ls1);


    list<int> *ls2 = new list<int>;
    ls2->push_back(24);
    ls2->push_back(14);
    ls2->push_back(4);
    ls2->push_back(22);
    ls2->push_back(22);
    ls2->push_back(3);
    ls2->push_back(1);
    cout <<"original list: "<<endl;
    printList(ls2);
    
    cout <<"return value: "<<removeElements(ls2, 10)<<endl;
    cout <<"final list: "<<endl;
    printList(ls2);
   

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
    cout << setprecision(2);
    for (auto it = list_name->begin(); it != list_name->end(); it++) {
        if (it == list_name->begin()) cout << *it;
        else cout << " -> " << *it;
    }
    cout << endl;
}
void printListfloat(list<float> list_name)
{
    for (auto it = list_name.begin(); it != list_name.end(); it++) {
        if (it == list_name.begin()) cout << *it;
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
