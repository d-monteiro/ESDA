#include <iostream>
#include "MediaMovel.h"
using namespace std;

MediaMovel::MediaMovel(double n_elem) : n_elementos(n_elem) {}

// Alínea a)
void MediaMovel::update(double valor)
{
    if(valores.size() == n_elementos){
        valores.pop_front();
        valores.push_back(valor);
    }
    
    if(valores.empty() || valores.size() < n_elementos){
        valores.push_back(valor);
    }
}

// Alínea b)
double MediaMovel::getMediaMovel() const
{
    double media, sum;
    for(double valor : valores) sum+=valor;
    media = sum/n_elementos;
    return media;
}
