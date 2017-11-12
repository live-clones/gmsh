#include <gmsh.h>

// this reimplements gmsh/tutorial/t1.geo

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t1");

  double lc = 1e-2;

  std::vector<int> t = {1, 2, 3, 4};
  gmshModelGeoAddVertex(t[0], 0, 0, 0, lc);
  gmshModelGeoAddVertex(t[1], .1, 0,  0, lc);
  gmshModelGeoAddVertex(t[2], .1, .3, 0, lc);
  gmshModelGeoAddVertex(t[3], 0,  .3, 0, lc);

  gmshModelGeoAddLine(t[0], 1, 2);
  gmshModelGeoAddLine(t[1], 3, 2);
  gmshModelGeoAddLine(t[2], 3, 4);
  gmshModelGeoAddLine(t[3], 4, 1);

  std::vector<int> l = {4, 1, -2, 3};
  gmshModelGeoAddLineLoop(t[0], l);

  std::vector<int> ll = {1};
  gmshModelGeoAddPlaneSurface(t[0], ll);

  std::vector<int> p1 = {1, 2};
  gmshModelAddPhysicalGroup(0, 1, p1);

  std::vector<int> p2 = {1, 2};
  gmshModelAddPhysicalGroup(1, 2, p2);

  std::vector<int> p3 = {1};
  gmshModelAddPhysicalGroup(2, 6, p3);
  gmshModelSetPhysicalName(2, 6, "My surface");

  gmshModelGeoSynchronize();

  gmshModelMesh(2);

  gmshExport("t1.msh");

  gmshFinalize();
  return 0;
}
