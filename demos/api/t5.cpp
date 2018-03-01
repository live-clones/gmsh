// This file reimplements gmsh/tutorial/t5.geo in C++.

// The same geometry created with the OpenCASCADE CAD kernel (instead of the
// built-in kernel) is avaiable in t16.cpp.

#include <gmsh.h>
#include <cstdio>

namespace model = gmsh::model;
namespace factory = gmsh::model::geo;

void cheeseHole(double x, double y, double z, double r, double lc,
                std::vector<int> &shells, std::vector<int> &volumes)
{
  // When the tag is not specified, a new one is automatically provided
  int p1 = factory::addPoint(x,  y,  z,  lc);
  int p2 = factory::addPoint(x+r,y,  z,   lc);
  int p3 = factory::addPoint(x,  y+r,z,   lc);
  int p4 = factory::addPoint(x,  y,  z+r, lc);
  int p5 = factory::addPoint(x-r,y,  z,   lc);
  int p6 = factory::addPoint(x,  y-r,z,   lc);
  int p7 = factory::addPoint(x,  y,  z-r, lc);

  int c1 = factory::addCircleArc(p2,p1,p7);
  int c2 = factory::addCircleArc(p7,p1,p5);
  int c3 = factory::addCircleArc(p5,p1,p4);
  int c4 = factory::addCircleArc(p4,p1,p2);
  int c5 = factory::addCircleArc(p2,p1,p3);
  int c6 = factory::addCircleArc(p3,p1,p5);
  int c7 = factory::addCircleArc(p5,p1,p6);
  int c8 = factory::addCircleArc(p6,p1,p2);
  int c9 = factory::addCircleArc(p7,p1,p3);
  int c10 = factory::addCircleArc(p3,p1,p4);
  int c11 = factory::addCircleArc(p4,p1,p6);
  int c12 = factory::addCircleArc(p6,p1,p7);

  int l1 = factory::addCurveLoop({c5,c10,c4});
  int l2 = factory::addCurveLoop({c9,-c5,c1});
  int l3 = factory::addCurveLoop({c12,-c8,-c1});
  int l4 = factory::addCurveLoop({c8,-c4,c11});
  int l5 = factory::addCurveLoop({-c10,c6,c3});
  int l6 = factory::addCurveLoop({-c11,-c3,c7});
  int l7 = factory::addCurveLoop({-c2,-c7,-c12});
  int l8 = factory::addCurveLoop({-c6,-c9,c2});

  int s1 = factory::addSurfaceFilling({l1});
  int s2 = factory::addSurfaceFilling({l2});
  int s3 = factory::addSurfaceFilling({l3});
  int s4 = factory::addSurfaceFilling({l4});
  int s5 = factory::addSurfaceFilling({l5});
  int s6 = factory::addSurfaceFilling({l6});
  int s7 = factory::addSurfaceFilling({l7});
  int s8 = factory::addSurfaceFilling({l8});

  int sl = factory::addSurfaceLoop({s1, s2, s3, s4, s5, s6, s7, s8});
  int v = factory::addVolume({sl});
  shells.push_back(sl);
  volumes.push_back(v);
}

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  factory::addPoint(0.5,0.5,0.5, lcar2, 1);
  factory::addPoint(0.5,0.5,0, lcar1, 2);
  factory::addPoint(0,0.5,0.5, lcar1, 3);
  factory::addPoint(0,0,0.5, lcar1, 4);
  factory::addPoint(0.5,0,0.5, lcar1, 5);
  factory::addPoint(0.5,0,0, lcar1, 6);
  factory::addPoint(0,0.5,0, lcar1, 7);
  factory::addPoint(0,1,0, lcar1, 8);
  factory::addPoint(1,1,0, lcar1, 9);
  factory::addPoint(0,0,1, lcar1, 10);
  factory::addPoint(0,1,1, lcar1, 11);
  factory::addPoint(1,1,1, lcar1, 12);
  factory::addPoint(1,0,1, lcar1, 13);
  factory::addPoint(1,0,0, lcar1, 14);

  factory::addLine(8,9, 1);
  factory::addLine(9,12, 2);
  factory::addLine(12,11, 3);
  factory::addLine(11,8, 4);
  factory::addLine(9,14, 5);
  factory::addLine(14,13, 6);
  factory::addLine(13,12, 7);
  factory::addLine(11,10, 8);
  factory::addLine(10,13, 9);
  factory::addLine(10,4, 10);
  factory::addLine(4,5, 11);
  factory::addLine(5,6, 12);
  factory::addLine(6,2, 13);
  factory::addLine(2,1, 14);
  factory::addLine(1,3, 15);
  factory::addLine(3,7, 16);
  factory::addLine(7,2, 17);
  factory::addLine(3,4, 18);
  factory::addLine(5,1, 19);
  factory::addLine(7,8, 20);
  factory::addLine(6,14, 21);

  factory::addCurveLoop({-11,-19,-15,-18}, 22);
  factory::addPlaneSurface({22}, 23);
  factory::addCurveLoop({16,17,14,15}, 24);
  factory::addPlaneSurface({24}, 25);
  factory::addCurveLoop({-17,20,1,5,-21,13}, 26);
  factory::addPlaneSurface({26}, 27);
  factory::addCurveLoop({-4,-1,-2,-3}, 28);
  factory::addPlaneSurface({28}, 29);
  factory::addCurveLoop({-7,2,-5,-6}, 30);
  factory::addPlaneSurface({30}, 31);
  factory::addCurveLoop({6,-9,10,11,12,21}, 32);
  factory::addPlaneSurface({32}, 33);
  factory::addCurveLoop({7,3,8,9}, 34);
  factory::addPlaneSurface({34}, 35);
  factory::addCurveLoop({-10,18,-16,-20,4,-8}, 36);
  factory::addPlaneSurface({36}, 37);
  factory::addCurveLoop({-14,-13,-12,19}, 38);
  factory::addPlaneSurface({38}, 39);

  std::vector<int> shells, volumes;

  int sl = factory::addSurfaceLoop({35,31,29,37,33,23,39,25,27});
  shells.push_back(sl);

  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    cheeseHole(x, y, z, r, lcar3, shells, volumes);
    model::addPhysicalGroup(3, {volumes.back()}, t);
    std::printf("Hole %d (center = {%g,%g,%g}, radius = %g) has number %d!\n",
                t, x, y, z, r, volumes.back());
  }

  factory::addVolume(shells, 186);

  model::addPhysicalGroup(3, {186}, 10);
  factory::synchronize();
  model::mesh::generate(3);
  gmsh::write("t5.msh");
  gmsh::finalize();

  return 0;
}
