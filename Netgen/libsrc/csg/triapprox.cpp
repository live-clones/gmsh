#include <mystdlib.h>
#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>


namespace netgen
{

TriangleApproximation :: TriangleApproximation ()
{
  ;
}

int TriangleApproximation :: 
AddTriangle (const TATriangle & tri, bool invert)
{ 
  trias.Append (tri);
  if (invert)
    {
      trias.Last()[1] = tri[2];
      trias.Last()[2] = tri[1];
    }
  return trias.Size()-1;
}


void TriangleApproximation :: RemoveUnusedPoints ()
{
  BitArray used(GetNP());
  ARRAY<int> map (GetNP());
  int i, j;
  int cnt = 0;

  used.Clear();
  for (i = 0; i < GetNT(); i++)
    for (j = 0; j < 3; j++)
      used.Set (GetTriangle (i)[j]);

  for (i = 0; i < GetNP(); i++)
    if (used.Test(i))
      {
	map[i] = cnt;
	cnt++;
      }
  
  for (i = 0; i < GetNT(); i++)
    for (j = 0; j < 3; j++)
      trias[i][j] = map[trias[i][j]];

  for (i = 0; i < GetNP(); i++)
    if (used.Test(i))
      {
	points[map[i]] = points[i];
	normals[map[i]] = normals[i];
      }

  points.SetSize (cnt);
  normals.SetSize (cnt);
}
}
