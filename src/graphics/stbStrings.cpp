// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <cstring>
#include "stbStrings.h"
#include "drawContext.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "stb_truetype.h"
#include "fonts.h"
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

namespace {
  // the faces, by family (sans, serif, mono) and style (regular, bold,
  // italic, bold italic)
  const unsigned char *faces[12] = {
    gmshSansRegular,  gmshSansBold,  gmshSansItalic,  gmshSansBoldItalic,
    gmshSerifRegular, gmshSerifBold, gmshSerifItalic, gmshSerifBoldItalic,
    gmshMonoRegular,  gmshMonoBold,  gmshMonoItalic,  gmshMonoBoldItalic};

  // the face of a font (see fontEnum): Times and Symbol are the serif,
  // Courier and the screen font the mono, anything else the sans
  const stbtt_fontinfo *face(int fontid)
  {
    static stbtt_fontinfo info[12];
    static bool ready[12] = {false};
    int family = 0, style = 0;
    if(fontid == fontEnum::symbol)
      family = 1;
    else if(fontid >= fontEnum::helvetica && fontid < fontEnum::symbol) {
      family = (fontid & ~3) == fontEnum::times   ? 1 :
               (fontid & ~3) == fontEnum::courier ? 2 :
                                                    0;
      style = fontid & 3;
    }
    else if(fontid == fontEnum::screen || fontid == fontEnum::screenBold) {
      family = 2;
      style = (fontid == fontEnum::screenBold) ? 1 : 0;
    }
    int k = 4 * family + style;
    if(!ready[k]) {
      stbtt_InitFont(&info[k], faces[k], 0);
      ready[k] = true;
    }
    return &info[k];
  }

  // the next code point of a UTF-8 string, which p is moved past (a byte
  // that starts no valid sequence stands for itself, as in Latin-1)
  int nextCodePoint(const unsigned char *&p)
  {
    int c = *p++;
    int n = (c >= 0xf0 && c < 0xf8) ? 3 :
            (c >= 0xe0)             ? 2 :
            (c >= 0xc0)             ? 1 :
                                      0;
    if(!n || c >= 0xf8) return c;
    int cp = c & (0x3f >> n);
    for(int i = 0; i < n; i++) {
      if((p[i] & 0xc0) != 0x80) return c;
      cp = (cp << 6) | (p[i] & 0x3f);
    }
    p += n;
    return cp;
  }

  // What the characters 0x20 to 0x7e stand for in the Symbol font (Adobe's
  // encoding), which is how the Greek letters get into the PostScript and PDF
  // files of gl2ps: "a" is alpha. The signs the embedded fonts lack (for all,
  // there exists, ...) are left as they are.
  const int symbolCodes[95] = {
    0x20,   0x21,   0x2200, 0x23,   0x2203, 0x25,   0x26,   0x220b,
    0x28,   0x29,   0x2217, 0x2b,   0x2c,   0x2212, 0x2e,   0x2f,
    0x30,   0x31,   0x32,   0x33,   0x34,   0x35,   0x36,   0x37,
    0x38,   0x39,   0x3a,   0x3b,   0x3c,   0x3d,   0x3e,   0x3f,
    0x2245, 0x391,  0x392,  0x3a7,  0x394,  0x395,  0x3a6,  0x393,
    0x397,  0x399,  0x3d1,  0x39a,  0x39b,  0x39c,  0x39d,  0x39f,
    0x3a0,  0x398,  0x3a1,  0x3a3,  0x3a4,  0x3a5,  0x3c2,  0x3a9,
    0x39e,  0x3a8,  0x396,  0x5b,   0x2234, 0x5d,   0x22a5, 0x5f,
    0x203e, 0x3b1,  0x3b2,  0x3c7,  0x3b4,  0x3b5,  0x3c6,  0x3b3,
    0x3b7,  0x3b9,  0x3d5,  0x3ba,  0x3bb,  0x3bc,  0x3bd,  0x3bf,
    0x3c0,  0x3b8,  0x3c1,  0x3c3,  0x3c4,  0x3c5,  0x3d6,  0x3c9,
    0x3be,  0x3c8,  0x3b6,  0x7b,   0x7c,   0x7d,   0x223c};

  std::vector<int> codePoints(const char *str, int fontid,
                              const stbtt_fontinfo *font)
  {
    std::vector<int> cps;
    const unsigned char *p = (const unsigned char *)str;
    while(*p) {
      int cp = nextCodePoint(p);
      if(fontid == fontEnum::symbol && cp >= 0x20 && cp < 0x7f) {
        int s = symbolCodes[cp - 0x20];
        if(stbtt_FindGlyphIndex(font, s)) cp = s;
      }
      cps.push_back(cp);
    }
    return cps;
  }

  // the layout of a string at a size in pixels: where each glyph starts along
  // the baseline, where the pen ends, and how far the ink reaches left of
  // the start and right of the end
  struct layout {
    std::vector<int> glyphs;
    std::vector<double> x;
    double advance = 0., left = 0., right = 0.;
  };

  layout layOut(int fontid, const char *str, double size)
  {
    const stbtt_fontinfo *font = face(fontid);
    layout l;
    float scale = stbtt_ScaleForMappingEmToPixels(font, (float)size);
    double pen = 0.;
    int prev = 0;
    for(int cp : codePoints(str, fontid, font)) {
      int g = stbtt_FindGlyphIndex(font, cp);
      if(prev) pen += scale * stbtt_GetGlyphKernAdvance(font, prev, g);
      int adv, lsb, x0, y0, x1, y1;
      stbtt_GetGlyphHMetrics(font, g, &adv, &lsb);
      if(stbtt_GetGlyphBox(font, g, &x0, &y0, &x1, &y1)) {
        l.left = std::min(l.left, pen + scale * x0);
        l.right = std::max(l.right, pen + scale * x1);
      }
      l.glyphs.push_back(g);
      l.x.push_back(pen);
      pen += scale * adv;
      prev = g;
    }
    l.advance = pen;
    return l;
  }

  // the ascent and descent (positive, below the baseline) of a face at a size
  void lineMetrics(const stbtt_fontinfo *font, double size, double &ascent,
                   double &descent)
  {
    float scale = stbtt_ScaleForMappingEmToPixels(font, (float)size);
    int a, d, gap;
    stbtt_GetFontVMetrics(font, &a, &d, &gap);
    ascent = scale * a;
    descent = -scale * d;
  }
} // namespace

void stbStrings::setFont(int fontid, int fontsize)
{
  _fontId = fontid;
  _fontSize = fontsize;
}

// the width of the quad measure() asks for below: the advance, or the ink if
// it goes further
double stbStrings::width(const char *str)
{
  layout l = layOut(_fontId, str, _fontSize);
  return std::max(l.advance, l.right) - l.left;
}

double stbStrings::height()
{
  double a, d;
  lineMetrics(face(_fontId), _fontSize, a, d);
  return a + d;
}

double stbStrings::descent()
{
  double a, d;
  lineMetrics(face(_fontId), _fontSize, a, d);
  return d;
}

// The width of the string and the height of its font, with a pixel of margin
// all around, at the size it is rasterised. The box is the font's, not the
// ink of this string: the baseline then falls on the anchor whatever the
// string is, as it does with the other engines.
stringQueue::extent stbStrings::measure(const element &e, double f)
{
  const stbtt_fontinfo *font = face(e.fontId);
  layout l = layOut(e.fontId, e.text.c_str(), e.fontSize);
  double ascent, descent;
  lineMetrics(font, e.fontSize, ascent, descent);
  double width = std::max(l.advance, l.right) - l.left + 2.;
  double height = ascent + descent + 2.;
  return {(int)ceil(width * f), (int)ceil(height * f),
          (int)ceil((descent + 1.) * f), (1. - l.left) * f,
          (ascent + 1.) * f};
}

void stbStrings::rasterise(const std::vector<slot> &slots, double f, int w,
                           int h, unsigned char *image)
{
  std::vector<unsigned char> glyph;
  for(const slot &s : slots) {
    const stbtt_fontinfo *font = face(s.e->fontId);
    double size = s.e->fontSize * f;
    float scale = stbtt_ScaleForMappingEmToPixels(font, (float)size);
    layout l = layOut(s.e->fontId, s.e->text.c_str(), size);
    // the pen in the image, on the baseline
    double penX = s.x - s.shift + s.ext.penX;
    int baseline = (int)floor(s.y + s.ext.penY + 0.5);
    for(std::size_t i = 0; i < l.glyphs.size(); i++) {
      double x = penX + l.x[i];
      int ix = (int)floor(x);
      float shift = (float)(x - ix);
      int x0, y0, x1, y1;
      stbtt_GetGlyphBitmapBoxSubpixel(font, l.glyphs[i], scale, scale, shift,
                                      0.f, &x0, &y0, &x1, &y1);
      int gw = x1 - x0, gh = y1 - y0;
      if(gw <= 0 || gh <= 0) continue;
      glyph.assign(gw * gh, 0);
      stbtt_MakeGlyphBitmapSubpixel(font, glyph.data(), gw, gh, gw, scale,
                                    scale, shift, 0.f, l.glyphs[i]);
      // added to what is there (glyphs may overlap), within the slot
      for(int j = 0; j < gh; j++) {
        int y = baseline + y0 + j;
        if(y < s.y || y >= s.y + s.h || y < 0 || y >= h) continue;
        for(int k = 0; k < gw; k++) {
          int xx = ix + x0 + k;
          if(xx < s.x || xx >= s.x + s.w || xx < 0 || xx >= w) continue;
          unsigned char &p = image[y * w + xx];
          p = (unsigned char)std::min(255, p + glyph[j * gw + k]);
        }
      }
    }
  }
}
