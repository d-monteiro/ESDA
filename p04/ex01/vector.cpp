#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


/**
 *  Imprime os elementos do vetor;
 *  Imprime o tamanho do vetor.
 */

int imprime_vetor(vector<int> vec){
  cout<<"Elementos do vetor: { ";
  for(size_t i=0;i<vec.size();++i)
  {
    cout<<vec[i]<<' ';
  }
  cout<<"}"<<endl;
  
  cout<<"Tamanho do vector: "<<vec.size()<<endl;
  
  return 0;
}

/**
 * Aceita a chave do euromilhões não ordenada em que os últimos dois números correspondem ao número de estrelas.
 * Ordena o vector, tendo em atenção que deverá aparecer primeiramente os números da chave e só depois os números das estrelas.
 * Exemplo: o vector com os elementos:
 *      43 | 3 | 27 | 33 | 15 | 5 | 2
 *          deverá tornar-se em
 *      3 | 15 | 27 | 33 | 43 | 2 | 5
 */

vector<int> ordena_euromilhoes(vector<int> vec){
  vector<int> numeros;
  vector<int> estrelas;
  
  for(size_t i=0;i<5;++i) numeros.push_back(vec[i]);
  for(size_t i=5;i<7;++i) estrelas.push_back(vec[i]);
  
  sort(numeros.begin(),numeros.end());
  sort(estrelas.begin(),estrelas.end());
  
  numeros.insert(numeros.end(), estrelas.begin(), estrelas.end());

  return numeros;
}

/**Test code. Do not change**/

int main() {

    vector<int> vec_euromilhoes_ord;
    
    vector<int> vec{1,99,37,40,11};
    imprime_vetor(vec);
    vector<int> vec_euromilhoes{2,13,7,26,15,20,10};
    cout << endl << "Chave 1 do Euromilhões: " << endl;
    imprime_vetor(vec_euromilhoes);
    vec_euromilhoes_ord = ordena_euromilhoes(vec_euromilhoes);
    cout << endl << "Chave 1 do Euromilhões ordenada: " << endl;
    imprime_vetor(vec_euromilhoes_ord);
    vector<int> vec_euromilhoes_2{14,5,33,21,2,44,20};
    cout << endl <<"Chave 2 do Euromilhões: " << endl;
    imprime_vetor(vec_euromilhoes_2);
    vec_euromilhoes_ord = ordena_euromilhoes(vec_euromilhoes_2);
    cout << endl << "Chave 2 do Euromilhões ordenada: " << endl;
    imprime_vetor(vec_euromilhoes_ord);

    return 0;
}