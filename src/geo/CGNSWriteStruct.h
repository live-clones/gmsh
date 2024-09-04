// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef CGNS_WRITE_STRUCT_H
#define CGNS_WRITE_STRUCT_H

#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)

class GModel;

int writeZonesStruct(GModel *model, double scalingFactor, int cgIndexFile,
                     int cgIndexBase);

#endif

#endif
