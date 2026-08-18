// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_MMG_H
#define MESH_GREGION_MMG_H

#include <vector>

class GRegion;
class GFace;

void refineMeshMMG(GRegion *gr);
// Mesh a whole connected group of regions with a single combined MMG3D call:
// tetrahedra get a per-region reference so the result can be demultiplexed
// back to regions[i]->tetrahedra, and allFaces (the union of the group's
// boundary faces, including any interface shared between two of the
// regions) is preserved via MMG3D_IPARAM_nosurf.
void refineMeshMMGGroup(std::vector<GRegion *> &regions,
                        std::vector<GFace *> &allFaces);

#endif
