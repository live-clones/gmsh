// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _FIND_LINKS_H_
#define _FIND_LINKS_H_

#include "ListUtils.h"

int allEdgesLinked(int ed, List_T *edges);
int allFacesLinked(int fac, List_T *faces);

#endif
