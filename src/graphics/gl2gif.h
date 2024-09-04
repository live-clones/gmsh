// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL2GIF_H
#define GL2GIF_H

#include <stdio.h>
#include "PixelBuffer.h"

#define MAX_GIFCOLORS 256

/* New types */

typedef unsigned int pixval;
typedef unsigned long pixel;
typedef int code_int;
typedef long int count_int;

/* PPM handling */

#define PPM_GETR(p) (((p)&0x3ff00000) >> 20)
#define PPM_GETG(p) (((p)&0xffc00) >> 10)
#define PPM_GETB(p) ((p)&0x3ff)
#define PPM_EQUAL(p, q) ((p) == (q))

#define PPM_ASSIGN(p, red, grn, blu)                                           \
  (p) = ((pixel)(red) << 20) | ((pixel)(grn) << 10) | (pixel)(blu)

#define PPM_LUMIN(p)                                                           \
  (0.299 * PPM_GETR(p) + 0.587 * PPM_GETG(p) + 0.114 * PPM_GETB(p))

#define PPM_DEPTH(newp, p, oldmaxval, newmaxval)                               \
  PPM_ASSIGN((newp),                                                           \
             ((int)PPM_GETR(p) * (newmaxval) + (oldmaxval) / 2) / (oldmaxval), \
             ((int)PPM_GETG(p) * (newmaxval) + (oldmaxval) / 2) / (oldmaxval), \
             ((int)PPM_GETB(p) * (newmaxval) + (oldmaxval) / 2) / (oldmaxval))

/* Public function */

void create_gif(FILE *outfile, PixelBuffer *buffer, int dither, int sort,
                int interlace, int transparency);

#endif
