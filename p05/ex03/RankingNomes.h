#ifndef _RANKINGNOMES_H_
#define _RANKINGNOMES_H_

#include <iostream>
#include <list>

using namespace std;

class RankingNomes
{
  public:
    RankingNomes(string ficheiro, int num_pos);
    int Insere(string nome, int posicao);
    int Remove(int posicao);
    int Promove(int pos, int numero_pos);
    int Despromove(int pos, int numero_pos);
    void Imprime() const;
  private:
    int max_pos;
    list<string> nomes;
};

#endif
