// This file reimplements gmsh/tutorial/t5.geo in C++.

#include <gmsh.h>
#include <cstdio>

using namespace gmsh;

void cheeseHole(double x, double y, double z, double r, double lc,
                std::vector<int> &shells, std::vector<int> &volumes)
{
  // When the tag is not specified, a new one is automatically provided
  int p1 = model::geo::addPoint(x,  y,  z,  lc);
  int p2 = model::geo::addPoint(x+r,y,  z,   lc);
  int p3 = model::geo::addPoint(x,  y+r,z,   lc);
  int p4 = model::geo::addPoint(x,  y,  z+r, lc);
  int p5 = model::geo::addPoint(x-r,y,  z,   lc);
  int p6 = model::geo::addPoint(x,  y-r,z,   lc);
  int p7 = model::geo::addPoint(x,  y,  z-r, lc);

  int c1 = model::geo::addCircleArc(p2,p1,p7);
  int c2 = model::geo::addCircleArc(p7,p1,p5);
  int c3 = model::geo::addCircleArc(p5,p1,p4);
  int c4 = model::geo::addCircleArc(p4,p1,p2);
  int c5 = model::geo::addCircleArc(p2,p1,p3);
  int c6 = model::geo::addCircleArc(p3,p1,p5);
  int c7 = model::geo::addCircleArc(p5,p1,p6);
  int c8 = model::geo::addCircleArc(p6,p1,p2);
  int c9 = model::geo::addCircleArc(p7,p1,p3);
  int c10 = model::geo::addCircleArc(p3,p1,p4);
  int c11 = model::geo::addCircleArc(p4,p1,p6);
  int c12 = model::geo::addCircleArc(p6,p1,p7);

  int l1 = model::geo::addLineLoop({c5,c10,c4});
  int l2 = model::geo::addLineLoop({c9,-c5,c1});
  int l3 = model::geo::addLineLoop({c12,-c8,-c1});
  int l4 = model::geo::addLineLoop({c8,-c4,c11});
  int l5 = model::geo::addLineLoop({-c10,c6,c3});
  int l6 = model::geo::addLineLoop({-c11,-c3,c7});
  int l7 = model::geo::addLineLoop({-c2,-c7,-c12});
  int l8 = model::geo::addLineLoop({-c6,-c9,c2});

  int s1 = model::geo::addSurfaceFilling({l1});
  int s2 = model::geo::addSurfaceFilling({l2});
  int s3 = model::geo::addSurfaceFilling({l3});
  int s4 = model::geo::addSurfaceFilling({l4});
  int s5 = model::geo::addSurfaceFilling({l5});
  int s6 = model::geo::addSurfaceFilling({l6});
  int s7 = model::geo::addSurfaceFilling({l7});
  int s8 = model::geo::addSurfaceFilling({l8});

  int sl = model::geo::addSurfaceLoop({s1, s2, s3, s4, s5, s6, s7, s8});
  int v = model::geo::addVolume({sl});
  shells.push_back(sl);
  volumes.push_back(v);
}

int main(int argc, char **argv)
{
  initialize();
  option::setNumber("General.Terminal", 1);

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  model::geo::addPoint(0.5,0.5,0.5, lcar2, 1);
  model::geo::addPoint(0.5,0.5,0, lcar1, 2);
  model::geo::addPoint(0,0.5,0.5, lcar1, 3);
  model::geo::addPoint(0,0,0.5, lcar1, 4);
  model::geo::addPoint(0.5,0,0.5, lcar1, 5);
  model::geo::addPoint(0.5,0,0, lcar1, 6);
  model::geo::addPoint(0,0.5,0, lcar1, 7);
  model::geo::addPoint(0,1,0, lcar1, 8);
  model::geo::addPoint(1,1,0, lcar1, 9);
  model::geo::addPoint(0,0,1, lcar1, 10);
  model::geo::addPoint(0,1,1, lcar1, 11);
  model::geo::addPoint(1,1,1, lcar1, 12);
  model::geo::addPoint(1,0,1, lcar1, 13);
  model::geo::addPoint(1,0,0, lcar1, 14);

  model::geo::addLine(8,9, 1);
  model::geo::addLine(9,12, 2);
  model::geo::addLine(12,11, 3);
  model::geo::addLine(11,8, 4);
  model::geo::addLine(9,14, 5);
  model::geo::addLine(14,13, 6);
  model::geo::addLine(13,12, 7);
  model::geo::addLine(11,10, 8);
  model::geo::addLine(10,13, 9);
  model::geo::addLine(10,4, 10);
  model::geo::addLine(4,5, 11);
  model::geo::addLine(5,6, 12);
  model::geo::addLine(6,2, 13);
  model::geo::addLine(2,1, 14);
  model::geo::addLine(1,3, 15);
  model::geo::addLine(3,7, 16);
  model::geo::addLine(7,2, 17);
  model::geo::addLine(3,4, 18);
  model::geo::addLine(5,1, 19);
  model::geo::addLine(7,8, 20);
  model::geo::addLine(6,14, 21);

  model::geo::addLineLoop({-11,-19,-15,-18}, 22);
  model::geo::addPlaneSurface({22}, 23);
  model::geo::addLineLoop({16,17,14,15}, 24);
  model::geo::addPlaneSurface({24}, 25);
  model::geo::addLineLoop({-17,20,1,5,-21,13}, 26);
  model::geo::addPlaneSurface({26}, 27);
  model::geo::addLineLoop({-4,-1,-2,-3}, 28);
  model::geo::addPlaneSurface({28}, 29);
  model::geo::addLineLoop({-7,2,-5,-6}, 30);
  model::geo::addPlaneSurface({30}, 31);
  model::geo::addLineLoop({6,-9,10,11,12,21}, 32);
  model::geo::addPlaneSurface({32}, 33);
  model::geo::addLineLoop({7,3,8,9}, 34);
  model::geo::addPlaneSurface({34}, 35);
  model::geo::addLineLoop({-10,18,-16,-20,4,-8}, 36);
  model::geo::addPlaneSurface({36}, 37);
  model::geo::addLineLoop({-14,-13,-12,19}, 38);
  model::geo::addPlaneSurface({38}, 39);

  std::vector<int> shells, volumes;

  int sl = model::geo::addSurfaceLoop({35,31,29,37,33,23,39,25,27});
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

  model::geo::addVolume(shells, 186);

  model::addPhysicalGroup(3, {186}, 10);
  model::geo::synchronize();
  model::mesh::generate(3);
  write("t5.msh");
  return 0;
}
