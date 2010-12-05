// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GENERATOR_H_
#define _GENERATOR_H_

class GModel;

void GetStatistics(double stat[50], double quality[4][100]=0);
void AdaptMesh(GModel *m);
void GenerateMesh(GModel *m, int dimension);
void OptimizeMesh(GModel *m);
void OptimizeMeshNetgen(GModel *m);
void RefineMesh(GModel *m, bool linear, bool splitIntoQuads=false,
                bool splitIntoHexas=false);
void RecombineMesh(GModel *m);

#endif
