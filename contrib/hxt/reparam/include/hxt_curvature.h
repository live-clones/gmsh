#ifndef HEXTREME_CURVATURE_H
#define HEXTREME_CURVATURE_H

#include "hxt_mesh.h"
#include "hxt_edge.h"

/// Estimating Curvatures and Their Derivatives on Triangle Meshes, Szymon Rusinkiewicz
HXTStatus hxtCurvatureRusinkiewicz (HXTMesh *mesh, double **nodalCurvatures, double **crossField, HXTEdges* edges, int debug);
void saveNodalField (HXTMesh *mesh, double *v, int ncomp, const char *fn);

#endif
