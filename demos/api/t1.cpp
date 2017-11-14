#include <gmsh.h>

// this reimplements gmsh/tutorial/t1.geo

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t1");

  double lc = 1e-2;
  int o;
  gmshModelGeoAddVertex(1, 0, 0, 0, o, lc);
  gmshModelGeoAddVertex(2, .1, 0,  0, o, lc);
  gmshModelGeoAddVertex(3, .1, .3, 0, o, lc);
  gmshModelGeoAddVertex(4, 0,  .3, 0, o, lc);

  gmshModelGeoAddLine(1, 1, 2, o);
  gmshModelGeoAddLine(2, 3, 2, o);
  gmshModelGeoAddLine(3, 3, 4, o);
  gmshModelGeoAddLine(4, 4, 1, o);

  gmshModelGeoAddLineLoop(1, {4, 1, -2, 3}, o);
  gmshModelGeoAddPlaneSurface(1, {1}, o);
  gmshModelAddPhysicalGroup(0, 1, {1, 2});
  gmshModelAddPhysicalGroup(1, 2, {1, 2});
  gmshModelAddPhysicalGroup(2, 6, {1});
  gmshModelSetPhysicalName(2, 6, "My surface");

  gmshModelGeoSynchronize();

  gmshModelMesh(2);

  gmshExport("t1.msh");

  gmshFinalize();
  return 0;
}
