// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GENERATOR_H
#define GENERATOR_H

class GModel;
class GRegion;

void GetStatistics(double stat[50], double quality[4][100] = 0,
                   bool visibleOnly = false);
void AdaptMesh(GModel *m);
void GenerateMesh(GModel *m, int dimension);
void OptimizeMesh(GModel *m, bool force = false);
void OptimizeMeshNetgen(GModel *m, bool force = false);
void OptimizeHighOrderMesh(GModel *m);
void OptimizeHighOrderMeshElastic(GModel *m);
void SmoothMesh(GModel *m);
void RecombineMesh(GModel *m);

#endif
