// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DELAUNAY_REFINEMENT_H
#define _DELAUNAY_REFINEMENT_H

#include "SPoint3.h"
#include <vector>
class Tet;
class Vert;
void delaunayRefinement (const int numThreads,
			 const int nptsatonce,
			 std::vector<Vert*> &S,
			 std::vector<Tet*> &T,
			 double (*f)(const SPoint3 &p, void *),
			 void *data);

#endif
