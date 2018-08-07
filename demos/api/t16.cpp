// This file reimplements gmsh/tutorial/t16.geo in C++.

#include <iostream>
#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::occ;

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("t16");

  std::vector<std::string> log;
  gmsh::logger::start(log);

  std::vector<std::pair<int, int> > ov;
  std::vector<std::vector<std::pair<int, int> > > ovv;
  factory::addBox(0,0,0, 1,1,1, 1);
  factory::addBox(0,0,0, 0.5,0.5,0.5, 2);
  factory::cut({{3,1}}, {{3,2}}, ov, ovv, 3);
  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  std::vector<std::pair<int, int> > holes;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    factory::addSphere(x,y,z,r, 3 + t);
    holes.push_back({3, 3 + t});
  }
  factory::fragment({{3,3}}, holes, ov, ovv);

  factory::synchronize();

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  model::getEntities(ov, 0);
  model::mesh::setSize(ov, lcar1);

  model::getBoundary(holes, ov, false, false, true);
  model::mesh::setSize(ov, lcar3);

  double eps = 1e-3;
  model::getEntitiesInBoundingBox(0.5-eps, 0.5-eps, 0.5-eps,
                                  0.5+eps, 0.5+eps, 0.5+eps, ov, 0);
  model::mesh::setSize(ov, lcar2);

  model::mesh::generate(3);

  gmsh::write("t16.msh");

  gmsh::logger::stop();
  std::cout << "Logger has recorded " << log.size() << " lines" << std::endl;

  gmsh::finalize();
  return 0;
}
