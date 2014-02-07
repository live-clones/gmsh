// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GL2PPM_H_
#define _GL2PPM_H_

#include <stdio.h>
#include "PixelBuffer.h"

void create_ppm(FILE *outfile, PixelBuffer *buffer);

#endif
