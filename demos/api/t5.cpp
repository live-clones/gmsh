// This file reimplements gmsh/tutorial/t5.geo in C++.

#include <gmsh.h>
#include <cstdio>

void cheeseHole(double x, double y, double z, double r, double lc,
                std::vector<int> &shells, std::vector<int> &volumes)
{
  // When the tag (first argument) is negative, the
  int p1; gmshModelGeoAddPoint(-1, x,  y,  z,  p1, lc);
  int p2; gmshModelGeoAddPoint(-1, x+r,y,  z,  p2, lc);
  int p3; gmshModelGeoAddPoint(-1, x,  y+r,z,  p3, lc);
  int p4; gmshModelGeoAddPoint(-1, x,  y,  z+r,p4, lc);
  int p5; gmshModelGeoAddPoint(-1, x-r,y,  z,  p5, lc);
  int p6; gmshModelGeoAddPoint(-1, x,  y-r,z,  p6, lc);
  int p7; gmshModelGeoAddPoint(-1, x,  y,  z-r,p7, lc);

  int c1; gmshModelGeoAddCircleArc(-1, p2,p1,p7, c1);
  int c2; gmshModelGeoAddCircleArc(-1, p7,p1,p5, c2);
  int c3; gmshModelGeoAddCircleArc(-1, p5,p1,p4, c3);
  int c4; gmshModelGeoAddCircleArc(-1, p4,p1,p2, c4);
  int c5; gmshModelGeoAddCircleArc(-1, p2,p1,p3, c5);
  int c6; gmshModelGeoAddCircleArc(-1, p3,p1,p5, c6);
  int c7; gmshModelGeoAddCircleArc(-1, p5,p1,p6, c7);
  int c8; gmshModelGeoAddCircleArc(-1, p6,p1,p2, c8);
  int c9; gmshModelGeoAddCircleArc(-1, p7,p1,p3, c9);
  int c10; gmshModelGeoAddCircleArc(-1, p3,p1,p4, c10);
  int c11; gmshModelGeoAddCircleArc(-1, p4,p1,p6, c11);
  int c12; gmshModelGeoAddCircleArc(-1, p6,p1,p7, c12);

  int l1; gmshModelGeoAddLineLoop(-1, {c5,c10,c4}, l1);
  int l2; gmshModelGeoAddLineLoop(-1, {c9,-c5,c1}, l2);
  int l3; gmshModelGeoAddLineLoop(-1, {c12,-c8,-c1}, l3);
  int l4; gmshModelGeoAddLineLoop(-1, {c8,-c4,c11}, l4);
  int l5; gmshModelGeoAddLineLoop(-1, {-c10,c6,c3}, l5);
  int l6; gmshModelGeoAddLineLoop(-1, {-c11,-c3,c7}, l6);
  int l7; gmshModelGeoAddLineLoop(-1, {-c2,-c7,-c12}, l7);
  int l8; gmshModelGeoAddLineLoop(-1, {-c6,-c9,c2}, l8);

  int s1; gmshModelGeoAddSurfaceFilling(-1, {l1}, s1);
  int s2; gmshModelGeoAddSurfaceFilling(-1, {l2}, s2);
  int s3; gmshModelGeoAddSurfaceFilling(-1, {l3}, s3);
  int s4; gmshModelGeoAddSurfaceFilling(-1, {l4}, s4);
  int s5; gmshModelGeoAddSurfaceFilling(-1, {l5}, s5);
  int s6; gmshModelGeoAddSurfaceFilling(-1, {l6}, s6);
  int s7; gmshModelGeoAddSurfaceFilling(-1, {l7}, s7);
  int s8; gmshModelGeoAddSurfaceFilling(-1, {l8}, s8);

  int sl; gmshModelGeoAddSurfaceLoop(-1, {s1, s2, s3, s4, s5, s6, s7, s8}, sl);
  int v; gmshModelGeoAddVolume(-1, {sl}, v);
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

  int o;
  gmshModelGeoAddPoint(1, 0.5,0.5,0.5, o, lcar2);
  gmshModelGeoAddPoint(2, 0.5,0.5,0, o, lcar1);
  gmshModelGeoAddPoint(3, 0,0.5,0.5, o, lcar1);
  gmshModelGeoAddPoint(4, 0,0,0.5, o, lcar1);
  gmshModelGeoAddPoint(5, 0.5,0,0.5, o, lcar1);
  gmshModelGeoAddPoint(6, 0.5,0,0, o, lcar1);
  gmshModelGeoAddPoint(7, 0,0.5,0, o, lcar1);
  gmshModelGeoAddPoint(8, 0,1,0, o, lcar1);
  gmshModelGeoAddPoint(9, 1,1,0, o, lcar1);
  gmshModelGeoAddPoint(10, 0,0,1, o, lcar1);
  gmshModelGeoAddPoint(11, 0,1,1, o, lcar1);
  gmshModelGeoAddPoint(12, 1,1,1, o, lcar1);
  gmshModelGeoAddPoint(13, 1,0,1, o, lcar1);
  gmshModelGeoAddPoint(14, 1,0,0, o, lcar1);

  gmshModelGeoAddLine(1, 8,9, o);
  gmshModelGeoAddLine(2, 9,12, o);
  gmshModelGeoAddLine(3, 12,11, o);
  gmshModelGeoAddLine(4, 11,8, o);
  gmshModelGeoAddLine(5, 9,14, o);
  gmshModelGeoAddLine(6, 14,13, o);
  gmshModelGeoAddLine(7, 13,12, o);
  gmshModelGeoAddLine(8, 11,10, o);
  gmshModelGeoAddLine(9, 10,13, o);
  gmshModelGeoAddLine(10, 10,4, o);
  gmshModelGeoAddLine(11, 4,5, o);
  gmshModelGeoAddLine(12, 5,6, o);
  gmshModelGeoAddLine(13, 6,2, o);
  gmshModelGeoAddLine(14, 2,1, o);
  gmshModelGeoAddLine(15, 1,3, o);
  gmshModelGeoAddLine(16, 3,7, o);
  gmshModelGeoAddLine(17, 7,2, o);
  gmshModelGeoAddLine(18, 3,4, o);
  gmshModelGeoAddLine(19, 5,1, o);
  gmshModelGeoAddLine(20, 7,8, o);
  gmshModelGeoAddLine(21, 6,14, o);

  gmshModelGeoAddLineLoop(22, {-11,-19,-15,-18}, o);
  gmshModelGeoAddPlaneSurface(23, {22}, o);
  gmshModelGeoAddLineLoop(24, {16,17,14,15}, o);
  gmshModelGeoAddPlaneSurface(25, {24}, o);
  gmshModelGeoAddLineLoop(26, {-17,20,1,5,-21,13}, o);
  gmshModelGeoAddPlaneSurface(27, {26}, o);
  gmshModelGeoAddLineLoop(28, {-4,-1,-2,-3}, o);
  gmshModelGeoAddPlaneSurface(29, {28}, o);
  gmshModelGeoAddLineLoop(30, {-7,2,-5,-6}, o);
  gmshModelGeoAddPlaneSurface(31, {30}, o);
  gmshModelGeoAddLineLoop(32, {6,-9,10,11,12,21}, o);
  gmshModelGeoAddPlaneSurface(33, {32}, o);
  gmshModelGeoAddLineLoop(34, {7,3,8,9}, o);
  gmshModelGeoAddPlaneSurface(35, {34}, o);
  gmshModelGeoAddLineLoop(36, {-10,18,-16,-20,4,-8}, o);
  gmshModelGeoAddPlaneSurface(37, {36}, o);
  gmshModelGeoAddLineLoop(38, {-14,-13,-12,19}, o);
  gmshModelGeoAddPlaneSurface(39, {38}, o);

  std::vector<int> shells, volumes;

  int sl; gmshModelGeoAddSurfaceLoop(-1, {35,31,29,37,33,23,39,25,27}, sl);
  shells.push_back(sl);

  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    cheeseHole(x, y, z, r, lcar3, shells, volumes);
    gmshModelAddPhysicalGroup(3, t, {volumes.back()});
    std::printf("Hole %d (center = {%g,%g,%g}, radius = %g) has number %d!\n",
                t, x, y, z, r, volumes.back());
  }

  int v; gmshModelGeoAddVolume(186, shells, v);

  gmshModelAddPhysicalGroup(3, 10, {186});
  gmshModelGeoSynchronize();
  gmshModelMesh(3);
  gmshExport("t5.msh");
  return 0;
}
