// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GENERATOR_H
#define GENERATOR_H

class GModel;
class GRegion;

void GenerateMesh(GModel *m, int dimension);
void OptimizeMesh(GModel *m, const std::string &how = "", bool force = false,
                  int niter = 1);
void RecombineMesh(GModel *m);
void AdaptMesh(GModel *m);
void FixPeriodicMesh(GModel *m);
void GetStatistics(double stat[50], double quality[4][100] = 0,
                   bool visibleOnly = false);

#endif
