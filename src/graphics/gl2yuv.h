// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL2YUV_H
#define GL2YUV_H

#include <stdio.h>
#include "PixelBuffer.h"

void create_yuv(FILE *outfile, PixelBuffer *buffer);

#endif
