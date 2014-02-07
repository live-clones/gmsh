// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//

#include "STensor3.h"
#include <vector>
class GFace;
class MVertex;
void packingOfParallelograms(GFace* gf, std::vector<MVertex*> &packed, std::vector<SMetric3> &metrics );
