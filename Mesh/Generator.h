// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _GENERATOR_H_
#define _GENERATOR_H_

class GModel;
class GRegion;
#include "fullMatrix.h"

void GetStatistics(double stat[50], double quality[4][100] = 0);
void AdaptMesh(GModel *m);
void GenerateMesh(GModel *m, int dimension);
void OptimizeMesh(GModel *m);
void OptimizeMeshNetgen(GModel *m);
void SmoothMesh(GModel *m);
void RefineMesh(GModel *m, bool linear, bool splitIntoQuads = false,
                bool splitIntoHexas = false);
void BarycentricRefineMesh(GModel *m);
void RecombineMesh(GModel *m);
GRegion *createTetrahedralMesh(GModel *gm, fullMatrix<double> &pts,
                               fullMatrix<int> &triangles,
                               bool all_tets = false);
// GRegion * createTetrahedralMesh ( GModel *gm, unsigned int nbPts , double
// *pts, unsigned int nbTriangles, int *triangles );

#endif
