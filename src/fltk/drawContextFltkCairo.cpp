// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkCairo.h"

#if defined(HAVE_CAIRO)
#include <algorithm>
#include <cairo/cairo.h>

static void setFontOptions(cairo_t *cr)
{
  cairo_font_options_t *fontOptions = cairo_font_options_create();
  cairo_get_font_options(cr, fontOptions);
  cairo_font_options_set_hint_style(fontOptions, CAIRO_HINT_STYLE_FULL);
  cairo_font_options_set_antialias(fontOptions, CAIRO_ANTIALIAS_GRAY);
  cairo_set_font_options(cr, fontOptions);
  cairo_font_options_destroy(fontOptions);
}

// the Cairo face of an FLTK font
static void selectFontFace(cairo_t *cr, int fontid)
{
  cairo_font_slant_t slant =
    (fontid & FL_ITALIC) ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL;
  cairo_font_weight_t weight =
    (fontid & FL_BOLD) ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL;
  switch(fontid) {
  case FL_HELVETICA:
  case FL_HELVETICA_BOLD:
  case FL_HELVETICA_BOLD_ITALIC:
  case FL_HELVETICA_ITALIC:
    cairo_select_font_face(cr, "sans", slant, weight);
    break;
  case FL_COURIER:
  case FL_COURIER_BOLD:
  case FL_COURIER_BOLD_ITALIC:
  case FL_COURIER_ITALIC:
    cairo_select_font_face(cr, "courier", slant, weight);
    break;
  case FL_TIMES:
  case FL_TIMES_BOLD:
  case FL_TIMES_BOLD_ITALIC:
  case FL_TIMES_ITALIC:
    cairo_select_font_face(cr, "serif", slant, weight);
    break;
  default:
    cairo_select_font_face(cr, "sans", CAIRO_FONT_SLANT_NORMAL,
                           CAIRO_FONT_WEIGHT_NORMAL);
  }
}

drawContextFltkCairo::drawContextFltkCairo()
{
  _surface = cairo_image_surface_create(CAIRO_FORMAT_A8, 1, 1);
  _cr = cairo_create(_surface);
  setFontOptions(_cr);
}

drawContextFltkCairo::~drawContextFltkCairo()
{
  cairo_destroy(_cr);
  cairo_surface_destroy(_surface);
}

void drawContextFltkCairo::setFont(int fontid, int fontsize)
{
  // the heights and descents are asked of FLTK, as the other engines do
  drawContextFltk::setFont(fontid, fontsize);
  if(_currentFontId != fontid) selectFontFace(_cr, fontid);
  cairo_set_font_size(_cr, fontsize);
  _currentFontId = fontid;
  _currentFontSize = fontsize;
}

double drawContextFltkCairo::getStringWidth(const char *str)
{
  cairo_text_extents_t e;
  cairo_text_extents(_cr, str, &e);
  return e.width;
}

// The width of the string and the height of its font, with a pixel of margin
// all around, at the size it is rasterised. The box is the font's, not the
// ink of this string: the baseline then falls on the anchor whatever the
// string is, as it does with the other engines.
drawContextFltkQueued::extent drawContextFltkCairo::measure(const element &e,
                                                            double f)
{
  setFont(e.fontId, e.fontSize);
  cairo_text_extents_t x;
  cairo_text_extents(_cr, e.text.c_str(), &x);
  cairo_font_extents_t fe;
  cairo_font_extents(_cr, &fe);
  // an italic or a swash can reach left of the pen and past the advance
  double left = std::min(0., x.x_bearing);
  double width = std::max(x.x_advance, x.x_bearing + x.width) - left + 2.;
  double height = fe.ascent + fe.descent + 2.;
  return {(int)ceil(width * f), (int)ceil(height * f),
          (int)ceil((fe.descent + 1.) * f), (1. - left) * f,
          (fe.ascent + 1.) * f};
}

void drawContextFltkCairo::rasterise(const std::vector<slot> &slots, double f,
                                     int w, int h, unsigned char *image)
{
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_A8, w, h);
  cairo_t *cr = cairo_create(surface);
  cairo_set_source_rgba(cr, 0., 0., 0., 0);
  cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
  cairo_paint(cr);
  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
  setFontOptions(cr);
  cairo_set_source_rgba(cr, 1, 1, 1, 1);
  int font = -1;
  for(const slot &s : slots) {
    if(s.e->fontId != font) selectFontFace(cr, font = s.e->fontId);
    cairo_set_font_size(cr, s.e->fontSize * f);
    cairo_save(cr);
    cairo_rectangle(cr, s.x, s.y, s.w, s.h);
    cairo_clip(cr);
    cairo_move_to(cr, s.x - s.shift + s.ext.penX, s.y + s.ext.penY);
    cairo_show_text(cr, s.e->text.c_str());
    cairo_restore(cr);
  }
  cairo_destroy(cr);
  cairo_surface_flush(surface);
  // cairo pads the rows to a multiple of four bytes
  const unsigned char *data = cairo_image_surface_get_data(surface);
  int stride = cairo_image_surface_get_stride(surface);
  for(int j = 0; j < h; j++) memcpy(image + j * w, data + j * stride, w);
  cairo_surface_destroy(surface);
}

#endif
