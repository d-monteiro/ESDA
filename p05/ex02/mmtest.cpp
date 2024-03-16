#include "MediaMovel.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Não modificar!
int main()
{

  {
    MediaMovel mm(1);
    const MediaMovel &r = mm;
    mm.update(1.0);
    cout << fixed << setprecision(2) << r.getMediaMovel() << '\n';
  } // 1

  {
    MediaMovel mm(1);
    double a[]{1.2, 3.4, 5.0};
    for (double x : a)
    {
      mm.update(x);
      cout << fixed << setprecision(2) << mm.getMediaMovel() << ' ';
    }
    cout << fixed << setprecision(2) << mm.getMediaMovel() << '\n';
  } // -> 1.20 3.40 5.00 5.00

  {
    MediaMovel mm(2);
    double a[]{1.2, 3.4, 5.0};
    for (double x : a)
    {
      mm.update(x);
    }
    int i = 0;

  for(auto it=lst_jogos.begin();it!=lst_jogos.end();++it) {
    if((*it).find("Mario Kart (Wii)") != string::npos)
    {
      lst_jogos.erase(it);
      break;
    }
}

cout<<"Lista sem o jogo Mario Kart (Wii):"<<endl;

for(auto it = lst_jogos.begin(); it != lst_jogos.end(); it++)
{
  cout <<"Pos "<<i<<" -> "<< *it << endl;
  i++;
}
    //cout << fixed << setprecision(2) << mm.getMediaMovel() << '\n';
  } // -> 1.2? 2.30 4.20 4.20

  {
    MediaMovel mm(3);
    double a[]{1.2, 3.4, 5.0};
    for (double x : a)
    {
      mm.update(x);
      cout << fixed << setprecision(2) << mm.getMediaMovel() << ' ';
    }
    cout << fixed << setprecision(2) << mm.getMediaMovel() << '\n';
  } // -> 1.20? 2.30? 3.20 3.20

  {
    MediaMovel mm(4);
    double a[]{0.1, 1.2, -1.2, 3.4, 5.6, -2.3, 3.7};
    for (double x : a)
      mm.update(x);
    cout << fixed << setprecision(2) << mm.getMediaMovel() << '\n';
  } // -> 2.60

  return 0;
}