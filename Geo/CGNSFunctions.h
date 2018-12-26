// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues
//
// Contributors:
//   S. Guzik, B. Gorissen, K. Hillewaert

#ifndef _CGNS_FUNCTIONS_H_
#define _CGNS_FUNCTIONS_H_

#include "GmshConfig.h"
#include "fullMatrix.h"

#if defined(HAVE_LIBCGNS)

namespace CGNS {
#include <cgnslib.h>
};

// get gmsh parent tag
int parentFromCGNSType(CGNS::ElementType_t cgnsType);

// get mapping order
int orderFromCGNSType(CGNS::ElementType_t cgnsType);

// is the element complete ?
bool completeCGNSType(CGNS::ElementType_t cgnsType);

// get the gmsh tag for this element type
int tagFromCGNSType(CGNS::ElementType_t cgnsType);

// get the dimension for a grid location
int gridLocationDimCGNS(CGNS::GridLocation_t location);

// get element location for a given dimension
CGNS::GridLocation_t unstructuredGridLocationCGNS(int d);

// generate the index renumbering from cgns to gmsh control points
// equidistant corresponds to gmsh/equidistant, else strict cgns standard
// will fail in case non-equidistant points are used (NULL pointer).
int *getRenumberingToGmsh(CGNS::ElementType_t);
fullMatrix<double> getTransformationToGmsh(CGNS::ElementType_t);

#endif

#endif
