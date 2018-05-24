/* This file reimplements gmsh/tutorial/t1.geo in C.

   For all the elementary explanations about the general philosphy of entities
   in Gmsh, see the comments in the .geo file. Comments here focus on the
   specifics of the C API.

   The Gmsh API is entirely defined in the <gmsh.h> header. Read this file: it
   contains the documentation for all the functions in the API.
*/
#include <gmshc.h>

int main(int argc, char **argv)
{
  int ierr;
  double lc = 1e-2;
  int cl1[] = {4, 1, -2, 3}, ps1[] = {1};
  int pg1[] = {1, 2}, pg2[] = {1,2}, pg6[] = {1};

  /* Before using any functions in the C API, Gmsh must be initialized. In the C
     API the last argument of all functions return the error code, if any. */
  gmshInitialize(argc, argv, 1, &ierr);

  /* By default Gmsh will not print out any messages: in order to output
     messages on the terminal, just set the standard Gmsh option
     "General.Terminal" (same format and meaning as in .geo files) using
     gmshOptionSetNumber() */
  gmshOptionSetNumber("General.Terminal", 1, &ierr);

  /* This adds a new model, named "t1". If gmshModelAdd() is not called, a
     new default (unnamed) model will be created on the fly, if necessary. */
  gmshModelAdd("t1", &ierr);

  /* The C API provides direct access to the internal CAD kernels. The
     built-in CAD kernel was used in t1.geo: the corresponding API functions
     live in the "gmshModelGeo" namespace. To create geometrical points with
     the built-in CAD kernel, one thus uses gmshModelGeoAddPoint():

     - the first 3 arguments are the point coordinates (x, y, z)

     - the next argument is the target mesh size close to the point

     - the next argument is the point tag */
  gmshModelGeoAddPoint(0, 0, 0, lc, 1, &ierr);
  gmshModelGeoAddPoint(.1, 0,  0, lc, 2, &ierr);
  gmshModelGeoAddPoint(.1, .3, 0, lc, 3, &ierr);
  gmshModelGeoAddPoint(0,  .3, 0, lc, 4, &ierr);

  /* The API to create lines with the built-in kernel follows the same
     conventions: the first 2 arguments are point tags, the last (optional one)
     is the line tag. */
  gmshModelGeoAddLine(1, 2, 1, &ierr);
  gmshModelGeoAddLine(3, 2, 2, &ierr);
  gmshModelGeoAddLine(3, 4, 3, &ierr);
  gmshModelGeoAddLine(4, 1, 4, &ierr);

  /* The philosophy to construct curve loops and surfaces is similar: the first
     argument is now a vector of integers. */
  gmshModelGeoAddCurveLoop(cl1, sizeof(cl1)/sizeof(cl1[0]), 1, &ierr);
  gmshModelGeoAddPlaneSurface(ps1, sizeof(ps1)/sizeof(ps1[0]), 1, &ierr);

  /* Physical groups are defined by providing the dimension of the group (0 for
     physical points, 1 for physical curves, 2 for physical surfaces and 3 for
     phsyical volumes) followed by a vector of entity tags. The last (optional)
     argument is the tag of the new group to create. */
  gmshModelAddPhysicalGroup(0, pg1, sizeof(pg1)/sizeof(pg1[0]), 1, &ierr);
  gmshModelAddPhysicalGroup(1, pg2, sizeof(pg2)/sizeof(pg2[0]), 2, &ierr);
  gmshModelAddPhysicalGroup(2, pg6, sizeof(pg6)/sizeof(pg6[0]), 6, &ierr);

  /* Physical names are also defined by providing the dimension and tag of the
     entity. */
  gmshModelSetPhysicalName(2, 6, "My surface", &ierr);

  /* Before it can be meshed, the internal CAD representation must be
     synchronized with the Gmsh model, which will create the relevant Gmsh data
     structures. This is achieved by the gmsh::model::geo::synchronize() API
     call for the built-in CAD kernel. Synchronizations can be called at any
     time, but they involve a non trivial amount of processing; so while you
     could synchronize the internal CAD data after every CAD command, it is
     usually better to minimize the number of synchronization points. */
  gmshModelGeoSynchronize( &ierr);

  /* We can then generate a 2D mesh... */
  gmshModelMeshGenerate(2, &ierr);

  /* ... and save it to disk */
  gmshWrite("t1.msh", &ierr);

  /* This should be called at the end: */
  gmshFinalize(&ierr);
  return 0;
}
