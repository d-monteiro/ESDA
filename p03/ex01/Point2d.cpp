#include <cmath>
#include "Point2d.h"

using namespace std;

Point2d::Point2d()
{
  x = 0;
  y = 0;
}

Point2d::Point2d(const Point2d &p)
{
  x = p.x;
  y = p.y;
}

Point2d::Point2d(double a, double b)
{
  x = a;
  y = b;
}

double Point2d::get_x() const
{
  return x;
}

double Point2d::get_y() const
{
  return y;
}

void Point2d::set_x(double p)
{
  x = p;
}

void Point2d::set_y(double p)
{
  y = p;
}

void Point2d::translate(const Point2d &t)
{

}

double Point2d::distance_to(const Point2d &p) const
{

}