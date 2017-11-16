// This file reimplements gmsh/tutorial/t6.geo in C++.

#include <gmsh.h>

int main(int argc, char **argv)
{
  gmshInitialize();
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t2");

  // Copied from t1.cpp...
  double lc = 1e-2;
  int o;
  gmshModelGeoAddPoint(1, 0, 0, 0, o, lc);
  gmshModelGeoAddPoint(2, .1, 0,  0, o, lc);
  gmshModelGeoAddPoint(3, .1, .3, 0, o, lc);
  gmshModelGeoAddPoint(4, 0,  .3, 0, o, lc);

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
  // ...end of copy

  // Delete surface 1 and left boundary (line 4)
  gmshModelGeoRemove({{2,1}, {1,4}});

  // Replace left boundary with 3 new lines
  int p1; gmshModelGeoAddPoint(-1, -0.05, 0.05, 0, p1, lc);
  int p2; gmshModelGeoAddPoint(-1, -0.05, 0.1, 0, p2, lc);
  int l1; gmshModelGeoAddLine(-1, 1, p1, l1);
  int l2; gmshModelGeoAddLine(-1, p1, p2, l2);
  int l3; gmshModelGeoAddLine(-1, p2, 4, l3);

  // Recreate surface
  gmshModelGeoAddLineLoop(2, {2, -1, l1, l2, l3, -3}, o);
  gmshModelGeoAddPlaneSurface(1, {-2}, o);

  // Put 20 points with a refinement toward the extremities on curve 2
  gmshModelGeoSetTransfiniteLine(2, 20, "Bump", 0.05);

  // Put 20 points total on combination of curves l1, l2 and l3 (beware that the
  // points p1 and p2 are shared by the curves, so we do not create 6 + 6 + 10 =
  // 22 points, but 20!)
  gmshModelGeoSetTransfiniteLine(l1, 6);
  gmshModelGeoSetTransfiniteLine(l2, 6);
  gmshModelGeoSetTransfiniteLine(l3, 10);

  // Put 30 points following a geometric progression on curve 1 (reversed) and
  // on curve 3
  gmshModelGeoSetTransfiniteLine(1, 30, "Progression", -1.2);
  gmshModelGeoSetTransfiniteLine(3, 30, "Progression", 1.2);

  // Define the Surface as transfinite, by specifying the four corners of the
  // transfinite interpolation
  gmshModelGeoSetTransfiniteSurface(1, "Left", {1,2,3,4});

  // Recombine the triangles into quads
  gmshModelGeoSetRecombine(2, 1);

  // Apply an elliptic smoother to the grid
  gmshOptionSetNumber("Mesh.Smoothing", 100);
  gmshModelAddPhysicalGroup(2, 1, {1});

  // When the surface has only 3 or 4 control points, the transfinite constraint
  // can be applied automatically (without specifying the corners explictly).
  gmshModelGeoAddPoint(7, 0.2, 0.2, 0, o, 1.0);
  gmshModelGeoAddPoint(8, 0.2, 0.1, 0, o, 1.0);
  gmshModelGeoAddPoint(9, 0, 0.3, 0, o, 1.0);
  gmshModelGeoAddPoint(10, 0.25, 0.2, 0, o, 1.0);
  gmshModelGeoAddPoint(11, 0.3, 0.1, 0, o, 1.0);
  gmshModelGeoAddLine(10, 8, 11, o);
  gmshModelGeoAddLine(11, 11, 10, o);
  gmshModelGeoAddLine(12, 10, 7, o);
  gmshModelGeoAddLine(13, 7, 8, o);
  gmshModelGeoAddLineLoop(14, {13, 10, 11, 12}, o);
  gmshModelGeoAddPlaneSurface(15, {14}, o);
  for(int i = 10; i <= 13; i++)
    gmshModelGeoSetTransfiniteLine(i, 10);
  gmshModelGeoSetTransfiniteSurface(15);
  gmshModelAddPhysicalGroup(2, 2, {15});

  gmshModelMesh(2);
  gmshExport("t6.msh");
  gmshFinalize();
  return 0;
}
