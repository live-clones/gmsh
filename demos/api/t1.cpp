
// This reimplements gmsh/tutorial/t1.geo in C++. For all the elementary
// explanations about the general philosphy of entities in Gmsh, see the
// comments in the .geo file. Comments here will focus on the specifics of the
// C++ API.

// The Gmsh API is entirely defined in the <gmsh.h> header:
#include <gmsh.h>

int main(int argc, char **argv)
{
  // Before using any functions in the C++ API, Gmsh must be initialized. If
  // argc/argv are passed, Gmsh will parse the commandline, in the same way as
  // the standalone Gmsh code.
  gmshInitialize(argc, argv);

  // By default Gmsh will not print out any messages: in order to output
  // messages on the terminal, just set the standard Gmsh option (with the same
  // format and meaning as in .geo files) using gmshOptionSetNumber():
  gmshOptionSetNumber("General.Terminal", 1);

  // This creates a new model, named "t1". If gmshModelCreate() is not called, a
  // new default (unnamed) model will be created.
  gmshModelCreate("t1");

  // The C++ API provides direct access the internal CAD kernels. The built-in
  // CAD kernel was used in t1.geo. To create geometrical points with the
  // built-in CAD kernel, use gmshModelGeoAddPoint():
  // - the first argument is the point id (or "tag") ; if positive, the point
  //   is created with this tag ; if negative, a new tag will be returned
  //   (in the 5th argument)
  // - the next 3 arguments are the point coordinates (x, y, z)
  // - the fifth argument is the actual id of the point: equal to tag if tag >
  //   0, or a new id if tag < 0
  // - the last (optional) argument is the target mesh size close to the point
  double lc = 1e-2;
  int o;
  gmshModelGeoAddPoint(1, 0, 0, 0, o, lc);
  gmshModelGeoAddPoint(2, .1, 0,  0, o, lc);
  gmshModelGeoAddPoint(3, .1, .3, 0, o, lc);
  gmshModelGeoAddPoint(4, 0,  .3, 0, o, lc);

  // The API to create lines with the built-in kernel follows the same
  // conventions: first argument is a tag (here positive to force the id),
  // followed by 2 point ids, followed by the actual (returned) id.
  gmshModelGeoAddLine(1, 1, 2, o);
  gmshModelGeoAddLine(2, 3, 2, o);
  gmshModelGeoAddLine(3, 3, 4, o);
  gmshModelGeoAddLine(4, 4, 1, o);

  // The philosophy to construct line loops and surfaces is similar: the second
  // arguments are now std::vectors of integers.
  gmshModelGeoAddLineLoop(1, {4, 1, -2, 3}, o);
  gmshModelGeoAddPlaneSurface(1, {1}, o);

  // Physical groups ae defined by providing the dimension of the group (0 for
  // physical points, 1 for physical lines, 2 for physical surfaces and 3 for
  // phsyical volumes) and its tag, folllowed by a std::vector of entitiy ids.
  gmshModelAddPhysicalGroup(0, 1, {1, 2});
  gmshModelAddPhysicalGroup(1, 2, {1, 2});
  gmshModelAddPhysicalGroup(2, 6, {1});

  // Physical names are also defined by providing the dimension and tag of the
  // entity.
  gmshModelSetPhysicalName(2, 6, "My surface");

  gmshModelGeoSynchronize();

  gmshModelMesh(2);

  gmshExport("t1.msh");

  gmshFinalize();
  return 0;
}
