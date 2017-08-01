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

#ifndef _GMSH_API_H_
#define _GMSH_API_H_

#if defined(WIN32)
#define GMSH_API __declspec(dllexport) int
#else
#define GMSH_API int
#endif

typedef struct gmshEntity{ int dim, tag; };
typedef struct gmshIntVector{ int n; int *v; };
typedef struct gmshDoubleVector{ int n; double *v; };
typedef struct gmshEntityVector{ int n; gmshEntity *v; };

/* all functions return 0 on successful completion */

extern "C"
{
  /* Gmsh */
  GMSH_API gmshInitialize(int argc, char **argv);
  GMSH_API gmshFinalize();
  GMSH_API gmshOpen(const char *fileName);
  GMSH_API gmshMerge(const char *fileName);
  GMSH_API gmshExport(const char *fileName);
  GMSH_API gmshClear();

  /* Gmsh Options */
  GMSH_API gmshOptionsSetNumber(const char *name, double value);
  GMSH_API gmshOptionsGetNumber(const char *name, double *value);

  /* Gmsh Model */
  GMSH_API gmshModelCreate(const char *name);
  GMSH_API gmshModelSetCurrent(const char *name);
  GMSH_API gmshModelDestroy();
  GMSH_API gmshModelMesh(int dim);
  GMSH_API gmshModelAddEmbeddedVertex(int tag, int inDim, int inTag);

  /* Gmsh Model Geo Internals */
  GMSH_API gmshModelGeoAddVertex(int *tag, double x, double y, double z, double lc);
  GMSH_API gmshModelGeoAddLine(int *tag, int startVertexTag, int endVertexTag);
  GMSH_API gmshModelGeoAddPolyLine(int *tag, const gmshIntVector *vertexTags);
  GMSH_API gmshModelGeoExtrude(const gmshEntityVector *in, double dx, double dy,
                               double dz, gmshEntityVector *out);
  GMSH_API gmshModelGeoSynchronize();

  /* Gmsh Model OCC Internals */
  GMSH_API gmshModelOCCAddVertex(int *tag, double x, double y, double z, double lc);
  GMSH_API gmshModelOCCAddLine(int *tag, int startVertexTag, int endVertexTag);
  GMSH_API gmshModelOCCExtrude(const gmshEntityVector *in, double dx, double dy,
                               double dz, gmshEntityVector *out);
  GMSH_API gmshModelOCCSynchronize();
}

#endif
