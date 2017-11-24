// This file reimplements gmsh/tutorial/t16.geo in C++.

#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t16");

  std::vector<std::pair<int, int> > ov;
  std::vector<std::vector<std::pair<int, int> > > ovv;
  gmsh::model::occ::addBox(0,0,0, 1,1,1, 1);
  gmsh::model::occ::addBox(0,0,0, 0.5,0.5,0.5, 2);
  gmsh::model::occ::booleanDifference({{3,1}}, {{3,2}}, ov, ovv, 3);
  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  std::vector<std::pair<int, int> > holes;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    gmsh::model::occ::addSphere(x,y,z,r, 3 + t);
    holes.push_back({3, 3 + t});
  }
  gmsh::model::occ::booleanFragments({{3,3}}, holes, ov, ovv);

  gmsh::model::occ::synchronize();

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  gmsh::model::getEntities(ov, 0);
  gmsh::model::mesh::setSize(ov, lcar1);

  gmsh::model::getBoundary(holes, ov, false, false, true);
  gmsh::model::mesh::setSize(ov, lcar3);

  double eps = 1e-3;
  gmsh::model::getEntitiesInBoundingBox(0.5-eps, 0.5-eps, 0.5-eps,
                                        0.5+eps, 0.5+eps, 0.5+eps, ov, 0);
  gmsh::model::mesh::setSize(ov, lcar2);

  gmsh::model::mesh::generate(3);

  gmsh::write("t16.msh");

  gmsh::finalize();
  return 0;
}
