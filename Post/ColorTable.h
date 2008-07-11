// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_

#include <stdio.h>

#define COLORTABLE_NBMAX_PARAM 10
#define COLORTABLE_NBMAX_COLOR 1024

typedef struct{
  unsigned int table[COLORTABLE_NBMAX_COLOR];
  int size; // must be >= 2
  int ipar[COLORTABLE_NBMAX_PARAM];
  double dpar[COLORTABLE_NBMAX_PARAM];
}GmshColorTable;

// COLORTABLE_MODE

#define COLORTABLE_RGB  1
#define COLORTABLE_HSV  2

// integer parameters indices

#define COLORTABLE_NUMBER    0  // predefined curve index
#define COLORTABLE_INVERT    1  // invert (rbg<->255-rgb)
#define COLORTABLE_SWAP      2  // swap (min<->max)
#define COLORTABLE_ROTATION  3  // rotation
#define COLORTABLE_MODE      4  // mode (rgb, hsv)

// double parameters indices

#define COLORTABLE_CURVATURE 0  // curvature
#define COLORTABLE_BIAS      1  // offset
#define COLORTABLE_ALPHA     2  // alpha channel value
#define COLORTABLE_BETA      3  // beta coeff for brighten
#define COLORTABLE_ALPHAPOW  4  // alpha channel power value

void ColorTable_InitParam(int number, GmshColorTable *ct);
void ColorTable_Recompute(GmshColorTable *ct);
void ColorTable_Copy(GmshColorTable *ct);
void ColorTable_Paste(GmshColorTable *ct);
void ColorTable_Print(GmshColorTable *ct, FILE *fp) ;
int  ColorTable_IsAlpha(GmshColorTable *ct) ;
int  ColorTable_Diff(GmshColorTable *ct1, GmshColorTable *ct2);

void RGB_to_HSV(double R, double G, double B,
                double *H, double *S, double *V);
void HSV_to_RGB(double H, double S, double V,
                double *R, double *G, double *B);

#endif
