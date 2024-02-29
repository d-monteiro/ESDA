#include "Point2d.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  {
    Point2d a{1.0, 2.1};
    a.translate({-0.3, 0.5});
    cout << fixed << setprecision(2)
         << a.get_x() << ' ' << a.get_y() << '\n';
  } // -> 0.70 2.60
  {
    Point2d a{1.0, 2.1}, b{2.0, 3.1};
    cout << fixed << setprecision(2)
         << a.distance_to(b) << '\n';
  } // -> 1.41
  {
    Point2d a{0, 0};
    Point2d b = a;
    a.translate({0, 0});
    cout << fixed << setprecision(2)
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 0.00 0.00 0.00
  {
    Point2d a{0, 1};
    Point2d b = a;
    a.translate({1.5, 0});
    cout << fixed << setprecision(2)
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 1.50 1.00 1.50
  {
    Point2d a{1, 0};
    Point2d b = a;
    a.translate({-1, 2.5});
    cout << fixed << setprecision(2)
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 0.00 2.50 2.69

  cout << '\n';

  return 0;
}