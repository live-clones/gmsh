#ifndef _GL2GIF_H_
#define _GL2GIF_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include "PixelBuffer.h"

#define MAX_GIFCOLORS  256

/* New types */

typedef unsigned int   pixval;
typedef unsigned long  pixel;
typedef int            code_int;
typedef long int       count_int;

/* PPM handling */

#define PPM_GETR(p)    (((p) & 0x3ff00000) >> 20)
#define PPM_GETG(p)    (((p) & 0xffc00) >> 10)
#define PPM_GETB(p)    ((p) & 0x3ff)
#define PPM_EQUAL(p,q) ((p) == (q))

#define PPM_ASSIGN(p,red,grn,blu) \
  (p) = ((pixel) (red) << 20) | ((pixel) (grn) << 10) | (pixel) (blu)

#define PPM_LUMIN(p) ( 0.299 * PPM_GETR(p) + 0.587 * PPM_GETG(p) + 0.114 * PPM_GETB(p) )

#define PPM_DEPTH(newp,p,oldmaxval,newmaxval) \
  PPM_ASSIGN( (newp), \
    ( (int) PPM_GETR(p) * (newmaxval) + (oldmaxval) / 2 ) / (oldmaxval), \
    ( (int) PPM_GETG(p) * (newmaxval) + (oldmaxval) / 2 ) / (oldmaxval), \
    ( (int) PPM_GETB(p) * (newmaxval) + (oldmaxval) / 2 ) / (oldmaxval) )

/* Color histogram stuff */

typedef struct colorhist_item* colorhist_vector;
struct colorhist_item {
  pixel color;
  int value;
};

typedef struct colorhist_list_item* colorhist_list;
struct colorhist_list_item {
  struct colorhist_item ch;
  colorhist_list next;
};

/* Color hash table stuff */

typedef colorhist_list* colorhash_table;

/* Public function */

void create_gif(FILE *outfile, PixelBuffer *buffer, 
                int dither, int sort, int interlace, 
                int transparency, int r, int g, int b);


#endif
