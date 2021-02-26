#ifndef HXT_ORIENTATION3D_IO_H
#define HXT_ORIENTATION3D_IO_H

// #include "hxt_api.h"
#include "hxt_mesh.h"

#ifdef __cplusplus
extern "C" {
#endif

  /* !  trace streamlines in the 3D crossfield and write them in a ".pos" file to be visualised in GMSH software.

    size of field array is mesh->vertices.num*9.
    streamlines start at points (almost) placed in a regular grid associated to the bbox of the mesh
    streamlines stops when they are sufficiently long or when they enter a "singular" region
    initial lines of mesh are copied in the output for better visualization
   */
  HXTStatus hxtOr3DWriteStreamLines(HXTMesh* mesh, const double* field, const char* path, const char* viewName);
  HXTStatus hxtOr3DWriteSingularityFans(HXTMesh* mesh, const double* field, const char* path, const char* viewName, int traceStreamlines);

  /*! post treat values in double *frames to convert it in a 3D crossfield and write it in a ".pos" file to be visualised in GMSH software. 

    size of direction array is mesh->vertices.num*9.
    Data are stored following the pattern direction[9*currentVert + k], k=0..8 */
  HXTStatus hxtOr3DWritePosCrossesFromFrames(const HXTMesh *mesh, const double *frames, const char *fileName, const char* viewName); //hxtOr3DWritePosDirections
  HXTStatus hxtOr3DWritePosNormals(const HXTMesh *mesh, const double *normals, const char *fileName, const char* viewName);
  HXTStatus hxtOr3DWritePosCrossesFromDirections(const HXTMesh *mesh, double *directions, const char *fileName, const char* viewName);
  HXTStatus hxtOr3DWritePosCrossesFromDirectionsElem(const HXTMesh *mesh, double *directionsElem, const char *fileName, const char* viewName);
  HXTStatus hxtOr3DWritePosDirectionsTest(const HXTMesh *mesh, double *directions, const char *fileName, const char* viewName);
  HXTStatus hxtOr3DWriteBinaryFrames(const HXTMesh *mesh, double *frames, const char *filepath);
  /*! post treat values in double *directions to check which crosses are admissible and write it in a ".pos" file to be visualised in GMSH software. 

    size of direction array is mesh->numVertices*9.
    Data are stored following the pattern direction[9*currentVert + k], k=0..8 */
  HXTStatus hxtOr3DWritePosQuality(const HXTMesh *mesh, const double *frames, const char *fileName, const char* viewName);

  void write_vector(const char* filepath, size_t n, double* data);
  HXTStatus read_vector(const char* filepath, double** data);

  HXTStatus hxtOr3DWritePosScalarTet(HXTMesh *mesh, double *frames, double *scalarField, const char *fileName);
  HXTStatus hxtOr3DWritePosVectorTet(HXTMesh *mesh, double *vectorField, const char *fileName);
  HXTStatus hxtOr3DWritePosPotentials(HXTMesh *mesh, double *uvw, const char *fileName);
  HXTStatus hxtOr3DWritePosScalarTri(HXTMesh *mesh, double *scalarField, const char *fileName);
  HXTStatus hxtOr3dWritePosScalarNode(HXTMesh *mesh, double *scalarField, char *fileName);
  HXTStatus hxtOr3DdrawSkin(HXTMesh *mesh, const char *fileName);
  HXTStatus hxtOr3DwritePosTriMesh(HXTMesh *mesh, double *scalarField, const char *fileName);
#ifdef __cplusplus
}
#endif


#endif
