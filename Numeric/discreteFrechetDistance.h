// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DISCRETE_FRECHET_DISTANCE_
#define _DISCRETE_FRECHET_DISTANCE_

#include <vector>
#include "SPoint3.h"

double discreteFrechetDistance (const std::vector<SPoint3> &P,
				const std::vector<SPoint3> &Q);

#endif
