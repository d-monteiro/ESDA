#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void imprime_lista(list<string> lst)
{
  list<string>::iterator it;

    for(it = lst.begin(); it != lst.end(); it++)
    {
      cout << *it << endl;
    }
}

int main()
{

  // a) criar a lista

  list <string> lst_jogos; 

  // b) inserir jogos na lista

  ifstream file_jogos("arquivo.txt");

  if (!file_jogos)
  {
    return -1;
  }
  string linha;

  while(getline(file_jogos, linha))
  {
    lst_jogos.push_back(linha);
  }

  file_jogos.close();

  // c) imprimir tamanho da lista

  cout << lst_jogos.size() << endl;

  // d) imprimir conteúdo da lista
  cout << "Conteúdo da Lista:" << endl;

  imprime_lista(lst_jogos);
  
    // e) ordenar lista e imprimir
  cout << "\nLista Ordenada:" << endl;

  lst_jogos.sort();
  
  imprime_lista(lst_jogos);
  
  // f) remover "Mario Kart (Wii)" e imprimir

  bool found = false;

  list<string>::iterator curr_jogo = lst_jogos.begin();

  while(!found && curr_jogo != lst_jogos.end())
  {
    if((*curr_jogo).find("Mario Kart") != string::npos)
    {
      lst_jogos.erase(curr_jogo);
      found = true;
    }
    curr_jogo++;
  }

  cout << "\nLista sem o jogo Mario Kart (Wii):" << endl;

  imprime_lista(lst_jogos);
  
  // g) remover jogos PS2 e imprimir

  curr_jogo = lst_jogos.begin();
  
  while(curr_jogo != lst_jogos.end())
  {
    if((*curr_jogo).find("PS2") != string::npos)
    {
      curr_jogo = lst_jogos.erase(curr_jogo);
    }
    else
    {
      curr_jogo++;
    }
  }

  cout << "\nLista sem jogos da PS2:" << endl;

  imprime_lista(lst_jogos);
  
  return 0;
}