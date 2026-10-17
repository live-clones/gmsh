// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>

class GModel;
class GRegion;

void GenerateMesh(GModel *m, int dimension);
void OptimizeMesh(GModel *m, const std::string &how = "", bool force = false,
                  int niter = 1, double quality = 0.0);
void RecombineMesh(GModel *m);
void AdaptMesh(GModel *m);
void FixPeriodicMesh(GModel *m);
void GetStatistics(double stat[50], double quality[3][101] = 0,
                   bool visibleOnly = false);
// the wall and CPU times of a stage of the current mesh generation (added to
// those of the same stage), reported with the summary of a hex-dominant mesh
void AddMeshStageTime(const std::string &stage, double wall, double cpu);

#endif
