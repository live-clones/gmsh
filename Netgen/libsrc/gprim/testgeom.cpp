#include <mystdlib.h>

#include <myadt.hpp>
#include <gprim.hpp>


Vec<2> func1 (const Point<2> & a, const Point<2> & b)
{
  return a-b;
}

void func2 (Point<3> & a, Vec<3> & v)
{
  a += 3.4 * v;
}

void func3 (const Mat<2,2> & m, const Vec<2> & vc, Vec<2> & res)
{
  res += Trans (m) * vc;
}
