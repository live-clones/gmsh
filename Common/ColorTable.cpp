// $Id: ColorTable.cpp,v 1.31 2006-01-06 00:34:20 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   David Colignon
//

// These colortable routines were inspired by those provided in Vis5d,
// a program for visualizing five dimensional gridded data sets
// Copyright (C) 1990 - 1995 Bill Hibbard, Brian Paul, Dave Santek,
// and Andre Battaiola.

#include "Gmsh.h"
#include "ColorTable.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

void ColorTable_InitParam(int number, GmshColorTable * ct)
{
  ct->size = 255;
  for(int i = 0; i < COLORTABLE_NBMAX_PARAM; i++){
    ct->ipar[i] = 0;
    ct->dpar[i] = 0.;
  }
  ct->ipar[COLORTABLE_MODE] = COLORTABLE_RGB;
  ct->ipar[COLORTABLE_NUMBER] = number;
  ct->dpar[COLORTABLE_ALPHA] = 1.0;
}

static double gray(double s)
{
  return s < 0. ? 0. : (s < 1. ? s : 1.);
}

static double hot_r(double s)
{
  return s < 0. ? 0. : (s < 3./8. ? 8./3. * s : 1.);
}

static double hot_g(double s)
{
  return s < 3./8. ? 0. : (s < 6./8. ? 8./3. * (s - 3./8.) : 1.);
}

static double hot_b(double s)
{
  return s < 6./8. ? 0. : (s < 1. ? 8./2. * (s - 6./8.) : 1.);
}

static double cubic(double a, double b, double c, double d, double x)
{
  return a + b * x + c * x * x + d * x * x * x;
}

void ColorTable_Recompute(GmshColorTable * ct)
{
  double s, t, gamma;
  int r, g, b, a;

  double bias = ct->dpar[COLORTABLE_BIAS];
  double curvature = ct->dpar[COLORTABLE_CURVATURE];
  int rotation = ct->ipar[COLORTABLE_ROTATION];

  for(int i = 0; i < ct->size; i++) {

    if(ct->size > 1) {
      if(i + rotation < 0)
        s = (double)(i + rotation + ct->size) / (double)(ct->size - 1);
      else if(i + rotation > ct->size - 1)
        s = (double)(i + rotation - ct->size) / (double)(ct->size - 1);
      else
        s = (double)(i + rotation) / (double)(ct->size - 1);
    }
    else
      s = 0.;

    if(ct->ipar[COLORTABLE_SWAP])
      s = 1.0 - s;

    switch (ct->ipar[COLORTABLE_NUMBER]) {
    case 0:  // all black
      r = g = b = 0;
      break;
    case 1:  // vis5d
      t = (curvature + 1.4) * (s - (1. + bias) / 2.);
      r = (int)(128.0 + 127.0 * atan(7.0 * t) / 1.57);
      g = (int)(128.0 + 127.0 * (2 * exp(-7 * t * t) - 1));
      b = (int)(128.0 + 127.0 * atan(-7.0 * t) / 1.57);
      break;
    case 2: // matlab "jet"
      {
	double ii = (double)(s-bias)*128.;
	if(ii < 0) ii = 0;
	if(ii > 128) ii = 128;
	double rr = 
	  ii <= 46 ? 0. : 
	  ii >= 111 ? -0.03125*(ii - 111) + 1. :
	  ii >= 78 ? 1. : 
	  0.03125*(ii - 46);
	double gg = 
	  ii <= 14 || ii >= 111 ? 0. : 
	  ii >= 79 ? -0.03125*(ii - 111) : 
	  ii <= 46 ? 0.03125*(ii - 14) : 
	  1.;
	double bb =
	  ii >= 79 ? 0. :
	  ii >= 47 ? -0.03125*(ii - 79) :
	  ii <= 14 ? 0.03125*(ii - 14) + 1.:
	  1.;
	r = (int)(rr*255.);
	g = (int)(gg*255.);
	b = (int)(bb*255.);
      }
      break;
    case 3: // lucie, samcef (?)
      if(s - bias <= 0.) {
	r = 0;
	g = 0;
	b = 255;
      }
      else if(s - bias <= 0.40) {
	r = 0;
	g = (int)((s - bias) * 637.5);
	b = (int)(255. - (s - bias) * 637.5);
      }
      else if(s - bias <= 0.60) {
	r = (int)(1275. * (s - bias - 0.4));
	g = 255;
	b = 0;
      }
      else if(s - bias <= 1.) {
	r = 255;
	g = (int)(255. - 637.5 * (s - bias - 0.6));
	b = 0;
      }
      else {
	r = 255;
	g = 0;
	b = 0;
      }
      break;
    case 4: // rainbow
      if(s - bias <= 0.) {
	r = 0;
	g = 0;
	b = 255;
      }
      else if(s - bias <= 0.25 + curvature) {
	curvature = (curvature == -0.25) ? -0.26 : curvature;
	r = 0;
	g = (int)((s - bias) * (255. / (0.25 + curvature)));
	b = 255;
      }
      else if(s - bias <= 0.50) {
	curvature = (curvature == 0.25) ? 0.26 : curvature;
	r = 0;
	g = 255;
	b = (int)(255. - (255. / (0.25 - curvature)) * (s - bias - 0.25 - curvature));
      }
      else if(s - bias <= 0.75 - curvature) {
	curvature = (curvature == 0.25) ? 0.26 : curvature;
	r = (int)((s - bias - 0.5) * (255. / (0.25 - curvature)));
	g = 255;
	b = 0;
      }
      else if(s - bias <= 1.) {
	curvature = (curvature == -0.25) ? -0.26 : curvature;
	r = 255;
	g = (int)(255. - (255. / (0.25 + curvature)) * (s - bias - 0.75 + curvature));
	b = 0;
      }
      else {
	r = 255;
	g = 0;
	b = 0;
      }
      break;
    case 5: // emc2000 (rainbow with black and white)
      if(s - bias <= 0.) {
	r = 0;
	g = 0;
	b = 0;
      }
      else if(s - bias <= 0.2) {
	r = (int)(57 * (1 - 100 * ((s - bias) - 0.1) * ((s - bias) - 0.1)));
	g = 0;
	b = (int)((s - bias) * (255. / 0.2));
      }
      else if(s - bias <= 0.3624) {
	r = 0;
	g = (int)((s - bias - 0.2) * (255. / 0.1624));
	b = 255;
      }
      else if(s - bias <= 0.50) {
	r = 0;
	g = 255;
	b = (int)(255. - (255. / 0.1376) * (s - bias - 0.3624));
      }
      else if(s - bias <= 0.6376) {
	r = (int)((s - bias - 0.5) * (255. / 0.1376));
	g = 255;
	b = 0;
      }
      else if(s - bias <= 0.8) {
	r = 255;
	g = (int)(255. - (255. / 0.1624) * (s - bias - 0.6376));
	b = 0;
      }
      else if(s - bias <= 1.0) {
	r = 255;
	g = (int)((255. / 0.2) * (s - bias - 0.8));
	b = (int)(-3187.66 * (s - bias) * (s - bias) + 7012.76 * (s - bias) - 3570.61);
      }
      else {
	r = 255;
	g = 255;
	b = 255;
      }
      break;
    case 6: // darkblue->red->yellow->white
      r = (int)(255. * cubic(-0.0506169, 2.81633, -1.87033, 0.0524573, s-bias));
      g = (int)(255. * cubic(0.0485868, -1.26109, 6.3074, -4.12498, s-bias));
      b = (int)(255. * cubic(0.364662, 1.50814, -7.36756, 6.51847, s-bias));
      break;
    case 7: // matlab "hot"
      r = (int)(255. * hot_r(s-bias));
      g = (int)(255. * hot_g(s-bias));
      b = (int)(255. * hot_b(s-bias));
      break;
    case 8: // matlab "pink"
      r = (int)(255. * sqrt((2.*gray(s-bias) + hot_r(s-bias))/3.));
      g = (int)(255. * sqrt((2.*gray(s-bias) + hot_g(s-bias))/3.));
      b = (int)(255. * sqrt((2.*gray(s-bias) + hot_b(s-bias))/3.));
      break;
    case 9: // grayscale
      if(s - bias <= 0.) {
	r = g = b = 0;
      }
      else if(s - bias <= 1.) {
	r = g = b = (int)(255 * (1. - curvature) * (s - bias));
      }
      else {
	r = g = b = (int)(255 * (1. - curvature));
      }
      break;
    case 10: // all white
      r = g = b = 255;
      break;
    case 11: // matlab "hsv"
      {
	double H = 6. * s + 1.e-10, R, G, B;
	HSV_to_RGB(H, 1., 1., &R, &G, &B);
	r = (int)(255 * R);
	g = (int)(255 * G);
	b = (int)(255 * B);
      }
      break;
    case 12: // spectrum (truncated hsv)
      {
	double H = 5. * s + 1.e-10, R, G, B;
	HSV_to_RGB(H, 1., 1., &R, &G, &B);
	r = (int)(255 * R);
	g = (int)(255 * G);
	b = (int)(255 * B);
      }
      break;
    case 13: // matlab "bone"
      r = (int)(255. * (7.*gray(s-bias) + hot_b(s-bias))/8.);
      g = (int)(255. * (7.*gray(s-bias) + hot_g(s-bias))/8.);
      b = (int)(255. * (7.*gray(s-bias) + hot_r(s-bias))/8.);
      break;
    case 14: // matlab "spring"
      r = (int)(255. * 1.);
      g = (int)(255. * gray(s-bias));
      b = (int)(255. * (1. - gray(s-bias)));
      break;
    case 15: // matlab "summer"
      r = (int)(255. * gray(s-bias));
      g = (int)(255. * (0.5+gray(s-bias)/2.));
      b = (int)(255. * 0.4);
      break;
    case 16: // matlab "autumn"
      r = (int)(255. * 1.);
      g = (int)(255. * gray(s-bias));
      b = (int)(255. * 0.);
      break;
    case 17: // matlab "winter"
      r = (int)(255. * 0.);
      g = (int)(255. * gray(s-bias));
      b = (int)(255. * (0.5+(1.-gray(s-bias))/2.));
      break;
    case 18: // matlab "cool"
      r = (int)(255. * gray(s-bias));
      g = (int)(255. * (1.-gray(s-bias)));
      b = (int)(255. * 1.);
      break;
    case 19: // matlab "copper"
      r = (int)(255. * DMIN(1., gray(s-bias) * 1.25));
      g = (int)(255. * DMIN(1., gray(s-bias) * 0.7812));
      b = (int)(255. * DMIN(1., gray(s-bias) * 0.4975));
      break;
    default:
      r = g = b = 0;
      break;
    }

    double aa = 1.0;
    if(ct->dpar[COLORTABLE_ALPHAPOW])
      aa = pow(s ? s : 1.e-10, ct->dpar[COLORTABLE_ALPHAPOW]);
    a = (int)(255. * aa * ct->dpar[COLORTABLE_ALPHA]);

    if(ct->dpar[COLORTABLE_BETA]) {
      if(ct->dpar[COLORTABLE_BETA] > 0.0)
	gamma = 1. - ct->dpar[COLORTABLE_BETA];
      else
	gamma = 1. / (1.001 + ct->dpar[COLORTABLE_BETA]); // beta is thresholded to [-1,1]
      r = (int)(255. * pow((double)r / 255., gamma));
      g = (int)(255. * pow((double)g / 255., gamma));
      b = (int)(255. * pow((double)b / 255., gamma));
    }
    
    if(ct->ipar[COLORTABLE_INVERT]) {
      r = 255 - r;
      g = 255 - g;
      b = 255 - b;
    }

    // clamp to [0,255]
    r = r < 0 ? 0 : (r > 255 ? 255 : r);
    g = g < 0 ? 0 : (g > 255 ? 255 : g);
    b = b < 0 ? 0 : (b > 255 ? 255 : b);
    a = a < 0 ? 0 : (a > 255 ? 255 : a);
    
    ct->table[i] = CTX.PACK_COLOR(r, g, b, a);
  }

}

static GmshColorTable clip;

void ColorTable_Copy(GmshColorTable * ct)
{
  clip.size = ct->size;
  memcpy(clip.table, ct->table, ct->size * sizeof(unsigned int));
  memcpy(clip.ipar, ct->ipar, COLORTABLE_NBMAX_PARAM * sizeof(int));
  memcpy(clip.dpar, ct->dpar, COLORTABLE_NBMAX_PARAM * sizeof(double));
}

void ColorTable_Paste(GmshColorTable * ct)
{
  ct->size = clip.size;
  memcpy(ct->table, clip.table, clip.size * sizeof(unsigned int));
  memcpy(ct->ipar, clip.ipar, COLORTABLE_NBMAX_PARAM * sizeof(int));
  memcpy(ct->dpar, clip.dpar, COLORTABLE_NBMAX_PARAM * sizeof(double));
}

int ColorTable_Diff(GmshColorTable * ct1, GmshColorTable * ct2)
{
  if(ct1->size != ct2->size) return 1;
  for(int i = 0; i < ct1->size; i++)
    if(ct1->table[i] != ct2->table[i]) return 1;
  return 0;
}

void ColorTable_Print(GmshColorTable * ct, FILE * fp)
{
  int i, r, g, b, a;
  char tmp1[1024], tmp2[1024];

  strcpy(tmp1, "");
  for(i = 0; i < ct->size; i++) {
    r = CTX.UNPACK_RED(ct->table[i]);
    g = CTX.UNPACK_GREEN(ct->table[i]);
    b = CTX.UNPACK_BLUE(ct->table[i]);
    a = CTX.UNPACK_ALPHA(ct->table[i]);
    if(i && !(i % 4)) {
      if(fp)
        fprintf(fp, "%s\n", tmp1);
      else
        Msg(DIRECT, tmp1);
      strcpy(tmp1, "");
    }
    sprintf(tmp2, "{%d, %d, %d, %d}", r, g, b, a);
    strcat(tmp1, tmp2);
    if(i != ct->size - 1)
      strcat(tmp1, ", ");
  }
  if(fp)
    fprintf(fp, "%s\n", tmp1);
  else
    Msg(DIRECT, tmp1);
}

int ColorTable_IsAlpha(GmshColorTable * ct)
{
  int i, a;
  for(i = 0; i < ct->size; i++) {
    a = CTX.UNPACK_ALPHA(ct->table[i]);
    if(a < 255)
      return 1;
  }
  return 0;
}

// HSV/RBG conversion routines

#define UNDEFINED   0

// rgb on [0, 1], sv returned on [0, 1] and h on [0, 6]. 
// Exception: h is returned UNDEFINED if S==0.

#define RETURN_HSV(h,s,v) {*H=h; *S=s; *V=v; return;}

void RGB_to_HSV(double R, double G, double B,
		double *H, double *S, double *V)
{
  double v, x, f;
  int i;

  x = DMIN(DMIN(R, G), B);
  v = DMAX(DMAX(R, G), B);
  if(v == x)
    RETURN_HSV(UNDEFINED, 0, v);
  f = (R == x) ? G - B : ((G == x) ? B - R : R - G);
  i = (R == x) ? 3 : ((G == x) ? 5 : 1);
  RETURN_HSV(i - f / (v - x), (v - x) / v, v);
}

// h given on [0, 6] or UNDEFINED. s and v given on [0, 1].      
// rgb each returned on [0, 1].

#define RETURN_RGB(r,g,b) {*R=r; *G=g; *B=b; return;}

void HSV_to_RGB(double H, double S, double V,
		double *R, double *G, double *B)
{
  double m, n, f;
  int i;

  if(H == UNDEFINED)
    RETURN_RGB(V, V, V);
  i = (int)floor(H);
  f = H - i;
  if(!(i & 1))
    f = 1 - f;  // if i is even
  m = V * (1 - S);
  n = V * (1 - S * f);

  switch (i) {
  case 6:
  case 0:
    RETURN_RGB(V, n, m);
  case 1:
    RETURN_RGB(n, V, m);
  case 2:
    RETURN_RGB(m, V, n);
  case 3:
    RETURN_RGB(m, n, V);
  case 4:
    RETURN_RGB(n, m, V);
  case 5:
    RETURN_RGB(V, m, n);
  }
}

