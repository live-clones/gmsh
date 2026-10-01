#ifndef NGLIB_GMSH_H
#define NGLIB_GMSH_H

// Minimal C-style interface to the Netgen meshing kernel, modelled after
// Netgen's nglib.h, with only what Gmsh uses.

typedef void *Ng_Mesh;

enum Ng_Result { NG_OK = 0, NG_VOLUME_FAILURE = 1 };

void Ng_Init();
void Ng_Exit();
Ng_Mesh *Ng_NewMesh();
void Ng_DeleteMesh(Ng_Mesh *mesh);
void Ng_AddPoint(Ng_Mesh *mesh, double *x);
void Ng_AddSurfaceElement(Ng_Mesh *mesh, int *pi);
void Ng_AddVolumeElement(Ng_Mesh *mesh, int *pi);
int Ng_GetNP(Ng_Mesh *mesh);
int Ng_GetNE(Ng_Mesh *mesh);
void Ng_GetPoint(Ng_Mesh *mesh, int num, double *x);
void Ng_GetVolumeElement(Ng_Mesh *mesh, int num, int *pi);
Ng_Result Ng_GenerateVolumeMesh(Ng_Mesh *mesh, double maxh);
Ng_Result Ng_OptimizeVolumeMesh(Ng_Mesh *mesh, double maxh);

#endif
