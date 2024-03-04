#include <iostream>
#include <vector>
#include <fstream> 
 #include <algorithm>



using namespace std;

int print_vec_componentes(vector<string> vec_comp)
{
    int size=vec_comp.size();
   
   for ( int i=0; i<size; i++ )
    {
        cout << vec_comp[i]<< endl;
    } 

    return 0;

}

int print_vec_custos(vector<float> vec_custos)
{
    int size=vec_custos.size();
   
   for ( int i=0; i<size; i++ )
    {
        cout << vec_custos[i]<< endl;
    } 

    return 0;

}

/*
 *Lê um ficheiro texto em que o parametro de entrada f é o nome do ficheiro
 * coloca informação referente aos nomes das peças num vetor.
**/

vector<string> cria_vet_componentes(string f)
{
  ifstream fin(f);

  int n = 0;
  string line;
  vector<string> vec; 
  while(getline(fin, line, '\n'))
  {
    line.erase(line.size() - 1);
    if(n % 2 == 0) vec.push_back(line);
    n+=1;
  }
  return vec;
}

/**
 * Lê um ficheiro texto em que o parametro de entrada f é o nome do ficheiro
 * coloca informação referente aos respectivos valores das peças noutro vetor.
**/

vector<float> cria_vet_custos(string f)
{
  ifstream fin(f);

  int n = 0;
  string line;
  vector<float> vec;
  while(getline(fin, line, '\n'))
  {
    //line.erase(line.size() - 1);
    if(line.find('.') && n % 2 == 1) vec.push_back(stof(line));
    n+=1;
  }
  return vec;
}

/**
 * Apresenta no ecran o preço da peça str_componente.
 * Retorna 0 se conseguiu ou -1 se não conseguiu.
**/

int custo_componente(string str_componente, vector<string> vec_componentes, vector<float> vec_custos)
{
  for(size_t i=0;i<vec_componentes.size();++i)
  {
    if(vec_componentes[i] == str_componente)
    {
      cout<<"O preço do componente "<<vec_componentes[i]<<" é: "<<vec_custos[i]<<endl;
      return 0;
    }
  }
  cout<<"Componente "<<str_componente<<" não encontrado."<<endl;
  return -1;
}

/**Test code. Do not change**/

int main() {

    vector<string> vec_compon;
    vector<float> vec_custos;
    int result;
   
    vec_compon = cria_vet_componentes("auto_price_table.txt");
    print_vec_componentes(vec_compon);
    vec_custos = cria_vet_custos("auto_price_table.txt");
    print_vec_custos(vec_custos);
    result = custo_componente("Jante", vec_compon, vec_custos);
    cout << "Return de Jante é: " << result << endl;
    result = custo_componente("Retrovisor", vec_compon, vec_custos);
    cout << "Return de Retrovisor é: " << result << endl;
    result = custo_componente("Roda", vec_compon, vec_custos);
    cout << "Return de Roda é: " << result << endl;
    result = custo_componente("Vidro traseiro", vec_compon, vec_custos);
    cout << "Return de Vidro traseiro é: " << result << endl; 
    
    return 0;
}