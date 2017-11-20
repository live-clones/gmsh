// This file reimplements gmsh/tutorial/t2.geo in C++. Comments focus on the new
// API functions used, compared to the ones introduced in t1.cpp.

#include <gmsh.h>

int main(int argc, char **argv)
{
  // If argc/argv are passed, Gmsh will parse the commandline in the same way as
  // the standalone Gmsh code.
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t2");

  // Copied from t1.cpp...
  double lc = 1e-2;
  gmshModelGeoAddPoint(0, 0, 0, lc, 1);
  gmshModelGeoAddPoint(.1, 0,  0, lc, 2);
  gmshModelGeoAddPoint(.1, .3, 0, lc, 3);
  gmshModelGeoAddPoint(0,  .3, 0, lc, 4);
  gmshModelGeoAddLine(1, 2, 1);
  gmshModelGeoAddLine(3, 2, 2);
  gmshModelGeoAddLine(3, 4, 3);
  gmshModelGeoAddLine(4, 1, 4);
  gmshModelGeoAddLineLoop({4, 1, -2, 3}, 1);
  gmshModelGeoAddPlaneSurface({1}, 1);
  gmshModelAddPhysicalGroup(0, {1, 2}, 1);
  gmshModelAddPhysicalGroup(1, {1, 2}, 2);
  gmshModelAddPhysicalGroup(2, {1}, 6);
  gmshModelSetPhysicalName(2, 6, "My surface");
  // ...end of copy

  gmshModelGeoAddPoint(0, .4, 0, lc, 5);
  gmshModelGeoAddLine(4, 5, 5);

  // Geometrical transformations take a vector of pairs of integers as first
  // argument, which contains the list of entities, represented by (dimension,
  // tag) pairs. Here we thus translate point 3 (dimension=0, tag=3), by
  // dx=-0.05, dy=0, dz=0.
  gmshModelGeoTranslate({{0, 3}}, -0.05, 0, 0);

  // The "Duplicata" functionality in .geo files is handled by
  // gmshModelGeoCopy(), which takes a vector of (dim, tag) pairs as input, and
  // returns another vector of (dim, tag) pairs.
  std::vector<std::pair<int, int> > ov;
  gmshModelGeoCopy({{0, 3}}, ov);
  gmshModelGeoTranslate(ov, 0, 0.1, 0);

  gmshModelGeoAddLine(3, ov[0].second, 7);
  gmshModelGeoAddLine(ov[0].second, 5, 8);
  gmshModelGeoAddLineLoop({5,-8,-7,3}, 10);
  gmshModelGeoAddPlaneSurface({10}, 11);

  gmshModelGeoCopy({{2, 1}, {2, 11}}, ov);
  gmshModelGeoTranslate(ov, 0.12, 0, 0);

  std::printf("New surfaces '%d' and '%d'\n", ov[0].second, ov[1].second);

  gmshModelGeoAddPoint(0., 0.3, 0.13, lc, 100);
  gmshModelGeoAddPoint(0.08, 0.3, 0.1, lc, 101);
  gmshModelGeoAddPoint(0.08, 0.4, 0.1, lc, 102);
  gmshModelGeoAddPoint(0., 0.4, 0.13, lc, 103);

  gmshModelGeoAddLine(4, 100, 110);
  gmshModelGeoAddLine(3, 101, 111);
  gmshModelGeoAddLine(6, 102, 112);
  gmshModelGeoAddLine(5, 103, 113);
  gmshModelGeoAddLine(103, 100, 114);
  gmshModelGeoAddLine(100, 101, 115);
  gmshModelGeoAddLine(101, 102, 116);
  gmshModelGeoAddLine(102, 103, 117);

  gmshModelGeoAddLineLoop({115, -111, 3, 110}, 118);
  gmshModelGeoAddPlaneSurface({118}, 119);
  gmshModelGeoAddLineLoop({111, 116, -112, -7}, 120);
  gmshModelGeoAddPlaneSurface({120}, 121);
  gmshModelGeoAddLineLoop({112, 117, -113, -8}, 122);
  gmshModelGeoAddPlaneSurface({122}, 123);
  gmshModelGeoAddLineLoop({114, -110, 5, 113}, 124);
  gmshModelGeoAddPlaneSurface({124}, 125);
  gmshModelGeoAddLineLoop({115, 116, 117, 114}, 126);
  gmshModelGeoAddPlaneSurface({126}, 127);

  // The API to create surface loops ("shells") and volumes is similar to the
  // one used to create line loops and surfaces.
  gmshModelGeoAddSurfaceLoop({127, 119, 121, 123, 125, 11}, 128);
  gmshModelGeoAddVolume({128}, 129);

  // Extrusion works as expected, by providing a vector of (dim, tag) pairs as
  // input, the translation vector, and a vector of (dim, tag) pairs as output.
  std::vector<std::pair<int, int> > ov2;
  gmshModelGeoExtrude({ov[1]}, 0, 0, 0.12, ov2);

  // Mesh sizes associated to geometrical points can be set by passing a vector
  // of (dim, tag) pairs for the corresponding points.
  gmshModelGeoSetMeshSize({{0,103}, {0,105}, {0,109}, {0,102}, {0,28},
                           {0, 24}, {0,6}, {0,5}}, lc * 3);

  gmshModelAddPhysicalGroup(3, {129,130}, 1);
  gmshModelSetPhysicalName(3, 1, "The volume");

  gmshModelGeoSynchronize();

  gmshModelMesh(3);

  gmshExport("t2.msh");

  gmshFinalize();
  return 0;
}
