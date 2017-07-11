/* Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
 *
 * See the LICENSE.txt file for license information. Please report all
 * bugs and problems to the public mailing list <gmsh@onelab.info>.
 */

/*
  This is the embryo of what will become the Gmsh API.

  Don't use it, it's not ready :-) We plan to release a first version in Gmsh
  3.1, and something more complete in Gmsh 4.0.

  Your input is welcome: please contribute your ideas on
  http://gitlab.onelab.info/gmsh/gmsh/issues/188
 */

#include "Gmsh.h"

extern "C"
{
  /* Gmsh */
  int gmshInitialize(int argc, char **argv)
  {
    return !GmshInitialize(argc, argv);
  }

  int gmshFinalize()
  {
    return !GmshFinalize();
  }

  int gmshOpen(const char *fileName)
  {
    return !GmshOpenProject(fileName);
  }

  int gmshMerge(const char *fileName)
  {
    return !GmshMergeFile(fileName);
  }

  int gmshExport(const char *fileName)
  {
    return 1;
  }

  int gmshClear()
  {
    return 1;
  }

  /* Gmsh Options */
  int gmshOptionsSetNumber(const char *name, double value)
  {
    return 1;
  }

  int gmshOptionsGetNumber(const char *name, double *value)
  {
    return 1;
  }

  /* Gmsh Model */
  int gmshModelCreate(const char *name)
  {
    return 1;
  }

  int gmshModelSetCurrent(const char *name)
  {
    return 1;
  }

  int gmshModelDestroy()
  {
    return 1;
  }

  int gmshModelMesh(int dim)
  {
    return 1;
  }

  int gmshModelAddEmbeddedVertex(int tag, int inDim, int inTag)
  {
    return 1;
  }

  /* Gmsh Model Geo Internals */

  int gmshModelGeoAddPoint(int *tag, double x, double y, double z, double lc)
  {
    return 1;
  }

  int gmshModelGeoAddLine(int *tag, int startVertexTag, int endVertexTag)
  {
    return 1;
  }

  int gmshModelGeoSynchronize()
  {
    return 1;
  }

  /* Gmsh Model OCC Internals */

  int gmshModelOCCAddPoint(int *tag, double x, double y, double z, double lc)
  {
    return 1;
  }

  int gmshModelOCCSynchronize()
  {
    return 1;
  }

}
