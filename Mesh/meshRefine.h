// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_REFINE_H
#define MESH_REFINE_H

class GModel;

void RefineMesh(GModel *m, bool linear, bool splitIntoQuads = false,
                bool splitIntoHexas = false);
void BarycentricRefineMesh(GModel *m);

#endif
