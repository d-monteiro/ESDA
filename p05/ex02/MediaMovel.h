#ifndef _MEDIAMOVEL_H_
#define _MEDIAMOVEL_H_

#include <iostream>
#include <list>
using namespace std;

class MediaMovel
{
  public:
    MediaMovel(double n_elem);
    void update(double valor);
    double getMediaMovel() const;
  private:
    double n_elementos;
    list<double> valores;
};

#endif