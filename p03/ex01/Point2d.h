#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
using namespace std;

class Point2d
{
public:
  Point2d();
  Point2d(const Point2d &p);
  Point2d(double a, double b);
  double get_x() const;
  double get_y() const;
  void set_x(double p);
  void set_y(double p);
  void translate(const Point2d &t);
  double distance_to(const Point2d &p) const;

private:
  double x;
  double y;
};

#endif
