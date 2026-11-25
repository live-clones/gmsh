// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include "ColorContrast.h"
#include "Context.h"

static void channels(unsigned int rgb, int c[3])
{
  c[0] = (rgb >> 16) & 255;
  c[1] = (rgb >> 8) & 255;
  c[2] = rgb & 255;
}

static unsigned int pack(int r, int g, int b)
{ return (r << 16) | (g << 8) | b; }

double ColorLuminance(unsigned int rgb)
{
  int c[3];
  channels(rgb, c);
  double l[3];
  for(int i = 0; i < 3; i++) {
    double v = c[i] / 255.;
    l[i] = (v <= 0.04045) ? v / 12.92 : std::pow((v + 0.055) / 1.055, 2.4);
  }
  return 0.2126 * l[0] + 0.7152 * l[1] + 0.0722 * l[2];
}

double ColorContrast(unsigned int a, unsigned int b)
{
  double la = ColorLuminance(a), lb = ColorLuminance(b);
  return (std::max(la, lb) + 0.05) / (std::min(la, lb) + 0.05);
}

unsigned int ContrastingColor(unsigned int rgb)
{ return ColorContrast(rgb, 0) >= ColorContrast(rgb, 0xffffff) ? 0 : 0xffffff; }

// A colour chosen for a light interface (a pastel background, a vivid text)
// at another lightness, of the same hue, saturated as much as the colour was
// coloured, so that a pastel stays a tint and a vivid colour stays vivid,
// within a cap that keeps them from glaring
static unsigned int atLightness(unsigned int c, double lightness,
                                double maxSaturation)
{
  int ch[3];
  channels(c, ch);
  double rgb[3] = {ch[0] / 255., ch[1] / 255., ch[2] / 255.};
  double mx = std::max(rgb[0], std::max(rgb[1], rgb[2]));
  double mn = std::min(rgb[0], std::min(rgb[1], rgb[2]));
  double chroma = mx - mn, l = 0.5 * (mx + mn), hue = 0., s = 0.;
  if(chroma > 0.) {
    s = chroma / (1. - std::abs(2. * l - 1.));
    if(mx == rgb[0])
      hue = std::fmod((rgb[1] - rgb[2]) / chroma + 6., 6.);
    else if(mx == rgb[1])
      hue = (rgb[2] - rgb[0]) / chroma + 2.;
    else
      hue = (rgb[0] - rgb[1]) / chroma + 4.;
  }
  s = std::min(maxSaturation, s * std::min(1., 8. * chroma));
  // back from hue, saturation and lightness
  double c2 = (1. - std::abs(2. * lightness - 1.)) * s;
  double x = c2 * (1. - std::abs(std::fmod(hue, 2.) - 1.));
  double m = lightness - 0.5 * c2;
  double out[3] = {0., 0., 0.};
  int sector = (int)hue % 6;
  const int order[6][3] = {{0, 1, 2}, {1, 0, 2}, {2, 0, 1},
                           {2, 1, 0}, {1, 2, 0}, {0, 2, 1}};
  double v[3] = {c2, x, 0.};
  for(int i = 0; i < 3; i++) out[i] = v[order[sector][i]] + m;
  return pack((int)(255. * out[0] + 0.5), (int)(255. * out[1] + 0.5),
              (int)(255. * out[2] + 0.5));
}

// no brighter than the text, or else scaled down to it: the same hue and
// saturation, so that it is still the colour chosen, without the glare
unsigned int ReadableFillColor(unsigned int rgb, unsigned int fg, bool dark)
{
  if(!dark) return rgb;
  int c[3], f[3];
  channels(rgb, c);
  channels(fg, f);
  int mx = std::max(c[0], std::max(c[1], c[2]));
  int cap = std::max(f[0], std::max(f[1], f[2]));
  if(mx <= cap) return rgb;
  return pack(c[0] * cap / mx, c[1] * cap / mx, c[2] * cap / mx);
}

// a pastel or a near white chosen for a light interface is made darker
unsigned int ReadableTextColor(unsigned int rgb, unsigned int bg1,
                               unsigned int bg2, bool dark)
{
  auto reads = [&](unsigned int t) {
    return ColorContrast(t, bg1) >= 4.5 && ColorContrast(t, bg2) >= 4.5;
  };
  unsigned int t = dark ? atLightness(rgb, 0.72, 0.8) : rgb;
  int c[3];
  channels(rgb, c);
  double l = (std::max(c[0], std::max(c[1], c[2])) +
              std::min(c[0], std::min(c[1], c[2]))) /
             510.;
  for(int i = 1; i <= 20 && !reads(t); i++)
    t = dark ? atLightness(rgb, 0.72 + 0.28 * i / 20., 0.8) :
               atLightness(rgb, l * (1. - i / 20.), 0.7);
  return t;
}

// the paper of a note over a light picture, and the same note over a dark
// one, where the full colour would glare
unsigned int NotePaperColor(unsigned int mark, unsigned int bg, bool *dark)
{
  CTX *c = CTX::instance();
  double lum = 0.299 * c->unpackRed(bg) + 0.587 * c->unpackGreen(bg) +
               0.114 * c->unpackBlue(bg);
  bool d = (lum < 110.);
  if(dark) *dark = d;
  double paper = d ? 0. : 255., mix = d ? 0.32 : 0.45;
  return c->packColor((int)(paper * (1. - mix) + mix * c->unpackRed(mark)),
                      (int)(paper * (1. - mix) + mix * c->unpackGreen(mark)),
                      (int)(paper * (1. - mix) + mix * c->unpackBlue(mark)),
                      255);
}
