#ifndef _GL2GIF_H_
#define _GL2GIF_H_

/*
 * GL2GIF, an OpenGL to GIF Printing Library
 * Copyright (C) 1999-2002  Christophe Geuzaine 
 *
 * $Id: gl2gif.h,v 1.10 2002-05-25 19:17:45 geuzaine Exp $
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

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

void create_gif(FILE *outfile, int width, int height, 
		int dither, int sort, int interlace, 
		int transparency, int r, int g, int b);


#endif
