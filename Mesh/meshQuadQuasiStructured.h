// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_QUASI_STRUCTURED
#define MESH_QUAD_QUASI_STRUCTURED

class GModel;

int Mesh2DWithQuadQuasiStructured(GModel* gm);

/* visualization */
int showQuadMeshBaseComplex(GModel* gm);


class GFace;
class MVertex;
#include <unordered_map>
#include <vector>

namespace QSQ {
bool adaptSizeMapToSmallFeatures(
    const std::vector<GFace*>& faces, 
    std::unordered_map<MVertex*,double>& sizemap,
    double smallestMultiplier = 0.1,
    double gradientMax = 1.2);
}

#endif
