// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//

#ifndef _SURFACEFILLER_H_
#define _SURFACEFILLER_H_

#include <vector>
#include <set>
#include "STensor3.h"

class GFace;
class MVertex;

void packingOfParallelogramsSmoothness(GFace* gf, std::vector<MVertex*> &packed, std::vector<SMetric3> &metrics );
void packingOfParallelograms(GFace* gf, std::vector<MVertex*> &packed, std::vector<SMetric3> &metrics );
void packingOfParallelogramsConstrained(GFace* gf, std::set<MVertex*> constr_vertices, std::vector<MVertex*> &packed, std::vector<SMetric3> &metrics );



#endif
