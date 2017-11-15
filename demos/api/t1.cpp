// This file reimplements gmsh/tutorial/t1.geo in C++. For all the elementary
// explanations about the general philosphy of entities in Gmsh, see the
// comments in the .geo file. Comments here will focus on the specifics of the
// C++ API.

// The Gmsh API is entirely defined in the <gmsh.h> header:
#include <gmsh.h>

int main(int argc, char **argv)
{
  // Before using any functions in the C++ API, Gmsh must be initialized. If
  // argc/argv are passed, Gmsh will parse the commandline in the same way as
  // the standalone Gmsh code.
  gmshInitialize(argc, argv);

  // By default Gmsh will not print out any messages: in order to output
  // messages on the terminal, just set the standard Gmsh option
  // "General.Terminal" (same format and meaning as in .geo files) using
  // gmshOptionSetNumber():
  gmshOptionSetNumber("General.Terminal", 1);

  // This creates a new model, named "t1". If gmshModelCreate() is not called, a
  // new default (unnamed) model will be created on the fly, if necessary.
  gmshModelCreate("t1");

  // The C++ API provides direct access to the internal CAD kernels. The
  // built-in CAD kernel was used in t1.geo: the corresponding API functions
  // have the "gmshModeGeo" prefix. To create geometrical points with the
  // built-in CAD kernel, one thus uses gmshModelGeoAddPoint():
  //
  // - the first argument is the point tag ; if positive, the point is created
  //   with this tag ; if negative, a new (unused) tag will be assigned and
  //   returned (in the 5th argument)
  //
  // - the next 3 arguments are the point coordinates (x, y, z)
  //
  // - the fifth argument is the actual id of the point: equal to tag if tag >
  //   0, or a new one if tag < 0
  //
  // - the last (optional) argument is the target mesh size close to the point
  double lc = 1e-2;
  int o;
  gmshModelGeoAddPoint(1, 0, 0, 0, o, lc);
  gmshModelGeoAddPoint(2, .1, 0,  0, o, lc);
  gmshModelGeoAddPoint(3, .1, .3, 0, o, lc);
  gmshModelGeoAddPoint(4, 0,  .3, 0, o, lc);

  // The API to create lines with the built-in kernel follows the same
  // conventions: the first argument is a tag (here positive to force it),
  // followed by 2 point tags, followed by the actual (returned) tag.
  gmshModelGeoAddLine(1, 1, 2, o);
  gmshModelGeoAddLine(2, 3, 2, o);
  gmshModelGeoAddLine(3, 3, 4, o);
  gmshModelGeoAddLine(4, 4, 1, o);

  // The philosophy to construct line loops and surfaces is similar: the second
  // arguments are now vectors of integers.
  gmshModelGeoAddLineLoop(1, {4, 1, -2, 3}, o);
  gmshModelGeoAddPlaneSurface(1, {1}, o);

  // Physical groups are defined by providing the dimension of the group (0 for
  // physical points, 1 for physical lines, 2 for physical surfaces and 3 for
  // phsyical volumes) and its tag, followed by a vector of entity tags.
  gmshModelAddPhysicalGroup(0, 1, {1, 2});
  gmshModelAddPhysicalGroup(1, 2, {1, 2});
  gmshModelAddPhysicalGroup(2, 6, {1});

  // Physical names are also defined by providing the dimension and tag of the
  // entity.
  gmshModelSetPhysicalName(2, 6, "My surface");

  // Before it can be meshed, the internal CAD representation must be
  // synchronized with the Gmsh model, which will create the relevant Gmsh data
  // structures. This is achieved by the gmshModelGeoSynchronize() API call for
  // the built-in CAD kernel. Synchronizations can be called at any time, but
  // they involve a non trivial amount of processing; so while you could
  // synchronize the internal CAD data after every CAD command, it is usually
  // better to minimize the number of synchronization points.
  gmshModelGeoSynchronize();

  // We can then generate a 2D mesh...
  gmshModelMesh(2);

  // ... and save it to disk
  gmshExport("t1.msh");

  // This should be called at the end:
  gmshFinalize();
  return 0;
}
