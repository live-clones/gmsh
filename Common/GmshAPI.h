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

typedef struct gmshEntity{ int dim, tag; };
typedef struct gmshIntVector{ int n; int *v; };
typedef struct gmshDoubleVector{ int n; double *v; };
typedef struct gmshEntityVector{ int n; gmshEntity *v; };

// all functions return 0 on successful completion

extern "C"
{
  // initialize Gmsh (argc and argv are processed like command line arguments);
  // no other API function should be called before this one
  int gmshInitialize(int argc, char **argv);
  // finalize Gmsh; no other API function should be called after this one
  int gmshFinalize();

  // open a new project (same as File->Open in the interactive version)
  int gmshOpen(const char *fileName);
  // merge a file (same as File->Merge in the interactive version)
  int gmshMerge(const char *fileName);
  // export a file
  int gmshExport(const char *fileName);
  // clears everything (models, post-processing views)
  int gmshClear();

  int gmshOptionsSetNumber(const char *name, double value);
  int gmshOptionsGetNumber(const char *name, double *value);

  int gmshModelCreate(const char *name);
  int gmshModelSetCurrent(const char *name);
  int gmshModelDestroy();
  int gmshModelMesh(int dim);

  int gmshModelGeoCreate();
  int gmshModelGeoAddPoint(int *tag, double x, double y, double z, double lc);
  int gmshModelGeoAddLine(int *tag, int startVertexTag, int endVertexTag);
  int gmshModelGeoAddPolyLine(int *tag, const gmshIntVector *vertexTags);
  int gmshModelGeoExtrude(gmshEntityVector *in, double dx, double dy, double dz,
                          gmshEntityVector *out);
  int gmshModelGeoSynchronize();

  int gmshModelOCCCreate();
  int gmshModelOCCAddPoint(int *tag, double x, double y, double z, double lc);
  int gmshModelOCCAddLine(int *tag, int startVertexTag, int endVertexTag);
  int gmshModelOCCExtrude(const gmshEntityVector *in, double dx, double dy, double dz,
                          gmshEntityVector *out);
  int gmshModelOCCSynchronize();
}

#endif
