/* $Id: ColorTable.h,v 1.3 2000-11-26 15:43:46 geuzaine Exp $ */
#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_

#define COLORTABLE_NBMAX_PARAM 10
#define COLORTABLE_NBMAX_COLOR 255

typedef struct{
  unsigned int table[COLORTABLE_NBMAX_COLOR];
  int size;
  int ipar[COLORTABLE_NBMAX_PARAM];
  float fpar[COLORTABLE_NBMAX_PARAM];
}ColorTable;


/* COLORTABLE_MODE */

#define COLORTABLE_RGB  1
#define COLORTABLE_HSV  2


/* integrer parameters indices */

#define COLORTABLE_NUMBER    0  /* predefined curve index */
#define COLORTABLE_CHANGED   1  /* did the colortable change ? */
#define COLORTABLE_INVERT    2  /* invert (rbg<->255-rgb) */
#define COLORTABLE_SWAP      3  /* swap (min<->max) */
#define COLORTABLE_ROTATE    4  /* rotate */
#define COLORTABLE_MODE      5  /* mode (rgb, hsv) */

/* float parameters indices */

#define COLORTABLE_CURVE     0  /* curvature */
#define COLORTABLE_BIAS      1  /* offset */
#define COLORTABLE_ALPHAPOW  2  /* alpha channel power */
#define COLORTABLE_ALPHAVAL  3  /* alpha channel value */
#define COLORTABLE_BETA      4  /* beta coeff for brighten */

void ColorTable_InitParam (int number, ColorTable * ct, int rgb_flag, int alpha_flag);
void ColorTable_Recompute (ColorTable * ct, int rgb_flag, int alpha_flag);
void ColorTable_Copy(ColorTable *ct);
void ColorTable_Paste(ColorTable *ct);
void ColorTable_Load(FILE *fp, ColorTable *ct);
void ColorTable_Save(FILE *fp, ColorTable *ct) ;

#endif
