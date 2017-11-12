#include <iostream>
#include <gmsh.h>

// this reimplements gmsh/tutorial/t1.geo

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);
  gmshModelCreate("t1");

  double lc = 1e-2;
  int tag;
  tag = 1; gmshModelGeoAddVertex(tag, 0, 0, 0, lc);
  tag = 2; gmshModelGeoAddVertex(tag, .1, 0,  0, lc);
  tag = 3; gmshModelGeoAddVertex(tag, .1, .3, 0, lc);
  tag = 4; gmshModelGeoAddVertex(tag, 0,  .3, 0, lc);

  tag = 1; gmshModelGeoAddLine(tag, 1, 2);
  tag = 2; gmshModelGeoAddLine(tag, 3, 2);
  tag = 3; gmshModelGeoAddLine(tag, 3, 4);
  tag = 4; gmshModelGeoAddLine(tag, 4, 1);

  std::vector<int> l;
  l.push_back(4); l.push_back(1); l.push_back(-2); l.push_back(3);
  tag = 1; gmshModelGeoAddLineLoop(tag, l);

  std::vector<int> ll;
  ll.push_back(1);
  tag = 1; gmshModelGeoAddPlaneSurface(tag, ll);

  std::vector<int> p;
  p.push_back(1); p.push_back(2);
  gmshModelAddPhysicalGroup(0, 1, p);
  gmshModelAddPhysicalGroup(1, 2, p);
  p.clear(); p.push_back(1);
  gmshModelAddPhysicalGroup(2, 6, p);
  gmshModelSetPhysicalName(2, 6, "My surface");

  gmshModelGeoSynchronize();
  gmshModelMesh(2);

  gmshExport("t1.msh");
  gmshFinalize();
  return 0;
}
