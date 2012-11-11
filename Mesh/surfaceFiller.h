// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//

#include <vector>
class GFace;
class MVertex;
void packingOfParallelograms(GFace* gf, std::vector<MVertex*> &packed);
