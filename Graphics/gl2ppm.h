// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL2PPM_H
#define GL2PPM_H

#include <stdio.h>
#include "PixelBuffer.h"

void create_ppm(FILE *outfile, PixelBuffer *buffer);

#endif
