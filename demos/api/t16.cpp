// This file reimplements gmsh/tutorial/t16.geo in C++.

#include <gmsh.h>

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t16");

  std::vector<std::pair<int, int> > ov;
  std::vector<std::vector<std::pair<int, int> > > ovv;
  gmshModelOccAddBox(0,0,0, 1,1,1, 1);
  gmshModelOccAddBox(0,0,0, 0.5,0.5,0.5, 2);
  gmshModelOccBooleanDifference({{3,1}}, {{3,2}}, ov, ovv, 3);
  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  std::vector<std::pair<int, int> > holes;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    gmshModelOccAddSphere(x,y,z,r, 3 + t);
    holes.push_back({3, 3 + t});
  }
  gmshModelOccBooleanFragments({{3,3}}, holes, ov, ovv);

  gmshModelOccSynchronize();

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  gmshModelGetEntities(ov, 0);
  gmshModelSetMeshSize(ov, lcar1);

  gmshModelGetBoundary(holes, ov, false, false, true);
  gmshModelSetMeshSize(ov, lcar3);

  double eps = 1e-3;
  gmshModelGetEntitiesInBoundingBox(0.5-eps, 0.5-eps, 0.5-eps,
                                    0.5+eps, 0.5+eps, 0.5+eps, ov, 0);
  gmshModelSetMeshSize(ov, lcar2);

  gmshModelMesh(3);

  gmshExport("t16.msh");

  gmshFinalize();
  return 0;
}
