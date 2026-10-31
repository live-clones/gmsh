// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GENERATOR_H
#define GENERATOR_H

class GModel;
class GRegion;

// returns false if another operation holds the lock on the model, unless
// nested in the operation holding it (see modelLock)
bool GenerateMesh(GModel *m, int dimension, bool nested = false);
void OptimizeMesh(GModel *m, const std::string &how = "", bool force = false,
                  int niter = 1, double quality = 0.0);
void RecombineMesh(GModel *m);
void AdaptMesh(GModel *m);
void FixPeriodicMesh(GModel *m);
void GetStatistics(double stat[50], double quality[3][101] = 0,
                   bool visibleOnly = false);

#endif
