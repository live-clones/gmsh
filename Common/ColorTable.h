#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_

// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#define COLORTABLE_NBMAX_PARAM 10
#define COLORTABLE_NBMAX_COLOR 255

typedef struct{
  unsigned int table[COLORTABLE_NBMAX_COLOR];
  int size; // must be >= 2
  int ipar[COLORTABLE_NBMAX_PARAM];
  float fpar[COLORTABLE_NBMAX_PARAM];
}GmshColorTable;


// COLORTABLE_MODE

#define COLORTABLE_RGB  1
#define COLORTABLE_HSV  2


// integrer parameters indices

#define COLORTABLE_NUMBER    0  // predefined curve index
#define COLORTABLE_CHANGED   1  // did the colortable change ?
#define COLORTABLE_INVERT    2  // invert (rbg<->255-rgb)
#define COLORTABLE_SWAP      3  // swap (min<->max)
#define COLORTABLE_ROTATE    4  // rotate
#define COLORTABLE_MODE      5  // mode (rgb, hsv)

// float parameters indices

#define COLORTABLE_CURVE     0  // curvature
#define COLORTABLE_BIAS      1  // offset
#define COLORTABLE_ALPHAPOW  2  // alpha channel power
#define COLORTABLE_ALPHAVAL  3  // alpha channel value
#define COLORTABLE_BETA      4  // beta coeff for brighten

void ColorTable_InitParam (int number, GmshColorTable * ct, int rgb_flag, int alpha_flag);
void ColorTable_Recompute (GmshColorTable * ct, int rgb_flag, int alpha_flag);
void ColorTable_Copy(GmshColorTable *ct);
void ColorTable_Paste(GmshColorTable *ct);
void ColorTable_Print(GmshColorTable *ct, FILE *fp) ;
int  ColorTable_IsAlpha(GmshColorTable *ct) ;

#endif
