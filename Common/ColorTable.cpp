// $Id: ColorTable.cpp,v 1.17 2003-03-21 00:52:34 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   David Colignon
//

// These routines are loosely based on the colortable routines from
// the Vis5d program for visualizing five dimensional gridded data
// sets Copyright (C) 1990 - 1995 Bill Hibbard, Brian Paul, Dave
// Santek, and Andre Battaiola.

#include "Gmsh.h"
#include "ColorTable.h"
#include "Context.h"

extern Context_T CTX;

void ColorTable_InitParam(int number, GmshColorTable * ct,
                          int rgb_flag, int alpha_flag)
{
  ct->ipar[COLORTABLE_NUMBER] = number;

  if(rgb_flag) {
    ct->ipar[COLORTABLE_INVERT] = 0;
    ct->ipar[COLORTABLE_SWAP] = 0;
    ct->ipar[COLORTABLE_ROTATE] = 0;

    ct->fpar[COLORTABLE_CURVE] = 0.0;
    ct->fpar[COLORTABLE_BIAS] = 0.0;
    ct->fpar[COLORTABLE_BETA] = 0.0;
  }
  if(alpha_flag) {
    ct->fpar[COLORTABLE_ALPHAPOW] = 1.;
    ct->fpar[COLORTABLE_ALPHAVAL] = 255.;
  }

}

void ColorTable_Recompute(GmshColorTable * ct, int rgb_flag, int alpha_flag)
{
  float curve, bias;
  double gamma;
  int i, r, g, b, a, rotate;
  float s, t;

  ct->ipar[COLORTABLE_CHANGED] = 1;

  bias = ct->fpar[COLORTABLE_BIAS];
  curve = ct->fpar[COLORTABLE_CURVE];
  rotate = ct->ipar[COLORTABLE_ROTATE];

  for(i = 0; i < ct->size; i++) {

    if(ct->size > 1) {
      if(i + rotate < 0)
        s = (float)(i + rotate + ct->size) / (float)(ct->size - 1);
      else if(i + rotate > ct->size - 1)
        s = (float)(i + rotate - ct->size) / (float)(ct->size - 1);
      else
        s = (float)(i + rotate) / (float)(ct->size - 1);
    }
    else
      s = 0.;

    if(ct->ipar[COLORTABLE_SWAP])
      s = 1.0 - s;

    if(rgb_flag) {

      switch (ct->ipar[COLORTABLE_NUMBER]) {
      case 1:  // vis5d
        t = (curve + 1.4) * (s - (1. + bias) / 2.);
        r = (int)(128.0 + 127.0 * atan(7.0 * t) / 1.57);
        g = (int)(128.0 + 127.0 * (2 * exp(-7 * t * t) - 1));
        b = (int)(128.0 + 127.0 * atan(-7.0 * t) / 1.57);
        break;
      case 2:  // samcef
        if(s - bias <= 0.00) {
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
        else if(s - bias <= 1.00) {
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
      case 3:  // rainbow (matlab, etc.)
        if(s - bias <= 0.00) {
          r = 0;
          g = 0;
          b = 255;
        }
        else if(s - bias <= 0.25 + curve) {
          curve = (curve == -0.25) ? -0.26 : curve;
          r = 0;
          g = (int)((s - bias) * (255. / (0.25 + curve)));
          b = 255;
        }
        else if(s - bias <= 0.50) {
          curve = (curve == 0.25) ? 0.26 : curve;
          r = 0;
          g = 255;
          b =
            (int)(255. - (255. / (0.25 - curve)) * (s - bias - 0.25 - curve));
        }
        else if(s - bias <= 0.75 - curve) {
          curve = (curve == 0.25) ? 0.26 : curve;
          r = (int)((s - bias - 0.5) * (255. / (0.25 - curve)));
          g = 255;
          b = 0;
        }
        else if(s - bias <= 1.00) {
          curve = (curve == -0.25) ? -0.26 : curve;
          r = 255;
          g =
            (int)(255. - (255. / (0.25 + curve)) * (s - bias - 0.75 + curve));
          b = 0;
        }
        else {
          r = 255;
          g = 0;
          b = 0;
        }
        break;
      case 4:  // darkblue-red-yellow-white
#define myfct(a,b,c,d) ((a)+\
                        (b)*(s-bias)+\
                        (c)*(s-bias)*(s-bias)+\
                        (d)*(s-bias)*(s-bias)*(s-bias))
#define clamp(x) x = (x)<0?0:((x)>255?255:(x))
        r = (int)(255. * myfct(-0.0506169, 2.81633, -1.87033, 0.0524573));
        g = (int)(255. * myfct(0.0485868, -1.26109, 6.3074, -4.12498));
        b = (int)(255. * myfct(0.364662, 1.50814, -7.36756, 6.51847));
        clamp(r);
        clamp(g);
        clamp(b);
#undef myfct
#undef clamp
        break;
      case 5:  // grayscale
        if(s - bias <= 0.00) {
          r = g = b = 0;
        }
        else if(s - bias <= 1.00) {
          r = g = b = (int)(255 * (s - bias));
        }
        else {
          r = g = b = 255;
        }
        break;
      case 6:  // monochrome
        r = g = b = 0;
        break;
      case 7:  // rainbow modified to add black and white , from EMC2000
        if(s - bias <= 0.00) {
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
          b =
            (int)(-3187.66 * (s - bias) * (s - bias) + 7012.76 * (s - bias) -
                  3570.61);
        }
        else {
          r = 255;
          g = 255;
          b = 255;
        }
        break;
      case 8:  // grayscale, without white
      default:
        if(s - bias <= 0.00) {
          r = g = b = 0;
        }
        else if(s - bias <= 1.00) {
          r = g = b = (int)(220 * (s - bias));
        }
        else {
          r = g = b = 220;
        }
        break;
      }

      if(ct->fpar[COLORTABLE_BETA]) {
        if(ct->fpar[COLORTABLE_BETA] > 0.0)
          gamma = 1. - ct->fpar[COLORTABLE_BETA];
        else
          gamma = 1. / (1.001 + ct->fpar[COLORTABLE_BETA]);     // beta is thresholded to [-1,1]
        r = (int)(255. * pow((double)r / 255., gamma));
        g = (int)(255. * pow((double)g / 255., gamma));
        b = (int)(255. * pow((double)b / 255., gamma));
      }

      if(ct->ipar[COLORTABLE_INVERT]) {
        r = 255 - r;
        g = 255 - g;
        b = 255 - b;
      }

    }
    else {
      r = UNPACK_RED(ct->table[i]);
      g = UNPACK_GREEN(ct->table[i]);
      b = UNPACK_BLUE(ct->table[i]);
    }

    if(alpha_flag) {
      a = (int)(ct->fpar[COLORTABLE_ALPHAVAL] *
                ct->fpar[COLORTABLE_ALPHAPOW]);
    }
    else {
      a = UNPACK_ALPHA(ct->table[i]);
    }

    ct->table[i] = PACK_COLOR(r, g, b, a);
  }

}

static GmshColorTable clip;

void ColorTable_Copy(GmshColorTable * ct)
{
  clip.size = ct->size;
  memcpy(clip.table, ct->table, ct->size * sizeof(unsigned int));
  memcpy(clip.ipar, ct->ipar, COLORTABLE_NBMAX_PARAM * sizeof(int));
  memcpy(clip.fpar, ct->fpar, COLORTABLE_NBMAX_PARAM * sizeof(float));
}

void ColorTable_Paste(GmshColorTable * ct)
{
  ct->size = clip.size;
  memcpy(ct->table, clip.table, clip.size * sizeof(unsigned int));
  memcpy(ct->ipar, clip.ipar, COLORTABLE_NBMAX_PARAM * sizeof(int));
  memcpy(ct->fpar, clip.fpar, COLORTABLE_NBMAX_PARAM * sizeof(float));
}


void ColorTable_Print(GmshColorTable * ct, FILE * fp)
{
  int i, r, g, b, a;
  char tmp1[1024], tmp2[1024];

  strcpy(tmp1, "");
  for(i = 0; i < ct->size; i++) {
    r = UNPACK_RED(ct->table[i]);
    g = UNPACK_GREEN(ct->table[i]);
    b = UNPACK_BLUE(ct->table[i]);
    a = UNPACK_ALPHA(ct->table[i]);
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
    a = UNPACK_ALPHA(ct->table[i]);
    if(a < 255)
      return 1;
  }
  return 0;
}
