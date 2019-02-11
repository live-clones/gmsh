// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _GL2JPEG_H_
#define _GL2JPEG_H_

#include <stdio.h>
#include "PixelBuffer.h"

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality,
                 int smoothing);

#endif
