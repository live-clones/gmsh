// This file reimplements gmsh/tutorial/t5.geo in C++.

#include <gmsh.h>
#include <cstdio>

void cheeseHole(double x, double y, double z, double r, double lc,
                std::vector<int> &shells, std::vector<int> &volumes)
{
  // When the tag is not specified, a new one is automatically provided
  int p1 = gmshModelGeoAddPoint(x,  y,  z,  lc);
  int p2 = gmshModelGeoAddPoint(x+r,y,  z,   lc);
  int p3 = gmshModelGeoAddPoint(x,  y+r,z,   lc);
  int p4 = gmshModelGeoAddPoint(x,  y,  z+r, lc);
  int p5 = gmshModelGeoAddPoint(x-r,y,  z,   lc);
  int p6 = gmshModelGeoAddPoint(x,  y-r,z,   lc);
  int p7 = gmshModelGeoAddPoint(x,  y,  z-r, lc);

  int c1 = gmshModelGeoAddCircleArc(p2,p1,p7);
  int c2 = gmshModelGeoAddCircleArc(p7,p1,p5);
  int c3 = gmshModelGeoAddCircleArc(p5,p1,p4);
  int c4 = gmshModelGeoAddCircleArc(p4,p1,p2);
  int c5 = gmshModelGeoAddCircleArc(p2,p1,p3);
  int c6 = gmshModelGeoAddCircleArc(p3,p1,p5);
  int c7 = gmshModelGeoAddCircleArc(p5,p1,p6);
  int c8 = gmshModelGeoAddCircleArc(p6,p1,p2);
  int c9 = gmshModelGeoAddCircleArc(p7,p1,p3);
  int c10 = gmshModelGeoAddCircleArc(p3,p1,p4);
  int c11 = gmshModelGeoAddCircleArc(p4,p1,p6);
  int c12 = gmshModelGeoAddCircleArc(p6,p1,p7);

  int l1 = gmshModelGeoAddLineLoop({c5,c10,c4});
  int l2 = gmshModelGeoAddLineLoop({c9,-c5,c1});
  int l3 = gmshModelGeoAddLineLoop({c12,-c8,-c1});
  int l4 = gmshModelGeoAddLineLoop({c8,-c4,c11});
  int l5 = gmshModelGeoAddLineLoop({-c10,c6,c3});
  int l6 = gmshModelGeoAddLineLoop({-c11,-c3,c7});
  int l7 = gmshModelGeoAddLineLoop({-c2,-c7,-c12});
  int l8 = gmshModelGeoAddLineLoop({-c6,-c9,c2});

  int s1 = gmshModelGeoAddSurfaceFilling({l1});
  int s2 = gmshModelGeoAddSurfaceFilling({l2});
  int s3 = gmshModelGeoAddSurfaceFilling({l3});
  int s4 = gmshModelGeoAddSurfaceFilling({l4});
  int s5 = gmshModelGeoAddSurfaceFilling({l5});
  int s6 = gmshModelGeoAddSurfaceFilling({l6});
  int s7 = gmshModelGeoAddSurfaceFilling({l7});
  int s8 = gmshModelGeoAddSurfaceFilling({l8});

  int sl = gmshModelGeoAddSurfaceLoop({s1, s2, s3, s4, s5, s6, s7, s8});
  int v = gmshModelGeoAddVolume({sl});
  shells.push_back(sl);
  volumes.push_back(v);
}

int main(int argc, char **argv)
{
  gmshInitialize();
  gmshOptionSetNumber("General.Terminal", 1);

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  gmshModelGeoAddPoint(0.5,0.5,0.5, lcar2, 1);
  gmshModelGeoAddPoint(0.5,0.5,0, lcar1, 2);
  gmshModelGeoAddPoint(0,0.5,0.5, lcar1, 3);
  gmshModelGeoAddPoint(0,0,0.5, lcar1, 4);
  gmshModelGeoAddPoint(0.5,0,0.5, lcar1, 5);
  gmshModelGeoAddPoint(0.5,0,0, lcar1, 6);
  gmshModelGeoAddPoint(0,0.5,0, lcar1, 7);
  gmshModelGeoAddPoint(0,1,0, lcar1, 8);
  gmshModelGeoAddPoint(1,1,0, lcar1, 9);
  gmshModelGeoAddPoint(0,0,1, lcar1, 10);
  gmshModelGeoAddPoint(0,1,1, lcar1, 11);
  gmshModelGeoAddPoint(1,1,1, lcar1, 12);
  gmshModelGeoAddPoint(1,0,1, lcar1, 13);
  gmshModelGeoAddPoint(1,0,0, lcar1, 14);

  gmshModelGeoAddLine(8,9, 1);
  gmshModelGeoAddLine(9,12, 2);
  gmshModelGeoAddLine(12,11, 3);
  gmshModelGeoAddLine(11,8, 4);
  gmshModelGeoAddLine(9,14, 5);
  gmshModelGeoAddLine(14,13, 6);
  gmshModelGeoAddLine(13,12, 7);
  gmshModelGeoAddLine(11,10, 8);
  gmshModelGeoAddLine(10,13, 9);
  gmshModelGeoAddLine(10,4, 10);
  gmshModelGeoAddLine(4,5, 11);
  gmshModelGeoAddLine(5,6, 12);
  gmshModelGeoAddLine(6,2, 13);
  gmshModelGeoAddLine(2,1, 14);
  gmshModelGeoAddLine(1,3, 15);
  gmshModelGeoAddLine(3,7, 16);
  gmshModelGeoAddLine(7,2, 17);
  gmshModelGeoAddLine(3,4, 18);
  gmshModelGeoAddLine(5,1, 19);
  gmshModelGeoAddLine(7,8, 20);
  gmshModelGeoAddLine(6,14, 21);

  gmshModelGeoAddLineLoop({-11,-19,-15,-18}, 22);
  gmshModelGeoAddPlaneSurface({22}, 23);
  gmshModelGeoAddLineLoop({16,17,14,15}, 24);
  gmshModelGeoAddPlaneSurface({24}, 25);
  gmshModelGeoAddLineLoop({-17,20,1,5,-21,13}, 26);
  gmshModelGeoAddPlaneSurface({26}, 27);
  gmshModelGeoAddLineLoop({-4,-1,-2,-3}, 28);
  gmshModelGeoAddPlaneSurface({28}, 29);
  gmshModelGeoAddLineLoop({-7,2,-5,-6}, 30);
  gmshModelGeoAddPlaneSurface({30}, 31);
  gmshModelGeoAddLineLoop({6,-9,10,11,12,21}, 32);
  gmshModelGeoAddPlaneSurface({32}, 33);
  gmshModelGeoAddLineLoop({7,3,8,9}, 34);
  gmshModelGeoAddPlaneSurface({34}, 35);
  gmshModelGeoAddLineLoop({-10,18,-16,-20,4,-8}, 36);
  gmshModelGeoAddPlaneSurface({36}, 37);
  gmshModelGeoAddLineLoop({-14,-13,-12,19}, 38);
  gmshModelGeoAddPlaneSurface({38}, 39);

  std::vector<int> shells, volumes;

  int sl = gmshModelGeoAddSurfaceLoop({35,31,29,37,33,23,39,25,27});
  shells.push_back(sl);

  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    cheeseHole(x, y, z, r, lcar3, shells, volumes);
    gmshModelAddPhysicalGroup(3, {volumes.back()}, t);
    std::printf("Hole %d (center = {%g,%g,%g}, radius = %g) has number %d!\n",
                t, x, y, z, r, volumes.back());
  }

  gmshModelGeoAddVolume(shells, 186);

  gmshModelAddPhysicalGroup(3, {186}, 10);
  gmshModelGeoSynchronize();
  gmshModelMesh(3);
  gmshExport("t5.msh");
  return 0;
}
