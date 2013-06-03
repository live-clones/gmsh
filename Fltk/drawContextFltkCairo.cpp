// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkCairo.h"

#if defined(HAVE_CAIRO)
#include <cairo/cairo.h>

//mostly borrowed from fltk function gl_texture_fifo::display_texture
static void _data2gl (int width, int height, unsigned char *data,
                      int Lx, int Ly, unsigned int _textureId)
{
  //setup matrices
  GLint matrixMode;
  glGetIntegerv (GL_MATRIX_MODE, &matrixMode);
  glMatrixMode (GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity ();
  glMatrixMode (GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity ();
  float winw = Fl_Window::current()->w();
  float winh = Fl_Window::current()->h();
  glScalef (2.0f / winw, 2.0f /  winh, 1.0f);
  glTranslatef (-winw / 2.0f, -winh / 2.0f, 0.0f);
  //write the texture on screen
  GLfloat pos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);

  glEnable (GL_TEXTURE_RECTANGLE_ARB);
  glPushAttrib(GL_ENABLE_BIT | GL_TEXTURE_BIT | GL_COLOR_BUFFER_BIT);
  glDisable(GL_LIGHTING);
  glDisable (GL_DEPTH_TEST);
  glEnable (GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glBindTexture (GL_TEXTURE_RECTANGLE_ARB, _textureId);
  glTexImage2D (GL_TEXTURE_RECTANGLE_ARB, 0, GL_ALPHA, width, height, 0,
                GL_ALPHA, GL_UNSIGNED_BYTE, data);
  glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_SRC0_ALPHA);
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  glTranslatef(pos[0] /*+ rect->x_bearing*/, pos[1] /*+ rect->y_bearing*/, pos[2]);

  glBegin (GL_QUADS);
  glTexCoord2f (0, 0);
  glVertex2f (0.0f, Ly);
  glTexCoord2f (Lx, 0);
  glVertex2f (Lx, Ly);
  glTexCoord2f (Lx, Ly);
  glVertex2f (Lx, 0.0f);
  glTexCoord2f (0, Ly);
  glVertex2f (0.0f, 0.0f);
  glEnd ();

  glPopAttrib();

  // reset original matrices
  glPopMatrix(); // GL_MODELVIEW
  glMatrixMode (GL_PROJECTION);
  glPopMatrix();
  glMatrixMode (matrixMode);
}

double drawContextFltkCairo::getStringWidth(const char *str)
{
  cairo_text_extents_t e;
  cairo_text_extents(_cr, str, &e);
  return e.width;
}

void drawContextFltkCairo::draw()
{
  drawContextFltk::draw();
}

//ensure the surface is large enough
void drawContextFltkCairo::_resizeSurface(int w, int h)
{
  if (w > cairo_image_surface_get_width(_surface) ||
      h > cairo_image_surface_get_height(_surface)) {
    cairo_font_face_t *face = cairo_get_font_face(_cr);
    cairo_matrix_t matrix;
    cairo_get_font_matrix(_cr, &matrix);
    cairo_destroy(_cr);
    cairo_surface_destroy(_surface);
    _surface = cairo_image_surface_create(CAIRO_FORMAT_A8, w, h);
    _cr = cairo_create(_surface);
    cairo_set_font_face(_cr, face);
    cairo_set_font_matrix(_cr, &matrix);
  }
}

void drawContextFltkCairo::drawString(const char *str)
{
  cairo_text_extents_t extent;
  cairo_text_extents(_cr, str, &extent);
  _resizeSurface(extent.width + 2, extent.height + 2);
  cairo_surface_t *surface = _surface;
  cairo_t *cr = _cr;

  cairo_set_source_rgba (cr, 0., 0., 0., 0);
  cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
  cairo_paint(cr);
  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
  extent.width +=1;
  extent.height +=1;
  cairo_move_to(cr, 1-extent.x_bearing, 1-extent.y_bearing);
	cairo_set_source_rgba(cr, 1, 1, 1, 1);
  cairo_show_text(cr, str);
  _data2gl(cairo_image_surface_get_width(surface),
           cairo_image_surface_get_height(surface),
           cairo_image_surface_get_data(surface),
           extent.width + 1, extent.height + 1, _textureId);

  // fltk version (fl_read_image is too slow)
  /*Fl_Offscreen offscreen = fl_create_offscreen(100, 100);
  fl_begin_offscreen(offscreen);
  fl_color(0, 0, 0);
  fl_rectf(0, 0, 100, 100);
  fl_color(255, 255, 255);
  fl_draw(str, 10, 90);
  fl_read_image(data, 0, 0, 100, 100);

  CGContextRef src = (CGContextRef)fl_gc;   // get bitmap context

  uchar *base = (uchar *)CGBitmapContextGetData(src);  // get data
  for (int i = 0; i < 100 * 100; ++i) {
    data[i] = data[i * 3];
  }
  fl_end_offscreen();
  fl_delete_offscreen(offscreen);
  */
}

drawContextFltkCairo::~drawContextFltkCairo()
{
  cairo_destroy(_cr);
  cairo_surface_destroy(_surface);
  glDeleteTextures(1, &_textureId);
}

drawContextFltkCairo::drawContextFltkCairo()
{
  _surface = cairo_image_surface_create(CAIRO_FORMAT_A8, 100, 100);
  _cr = cairo_create(_surface);
  glGenTextures (1, &_textureId);
  _currentFontId = -1;
}

void drawContextFltkCairo::setFont(int fontid, int fontsize)
{
  if (_currentFontId != fontid) {
    switch (fontid) {
      case FL_HELVETICA :
      case FL_HELVETICA_BOLD :
      case FL_HELVETICA_BOLD_ITALIC :
      case FL_HELVETICA_ITALIC :
        cairo_select_font_face(_cr, "sans",
          fontid & FL_ITALIC ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
          fontid & FL_BOLD ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
        break;
      case FL_COURIER :
      case FL_COURIER_BOLD :
      case FL_COURIER_BOLD_ITALIC :
      case FL_COURIER_ITALIC :
        cairo_select_font_face(_cr, "courier",
          fontid & FL_ITALIC ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
          fontid & FL_BOLD ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
        break;
      case FL_TIMES :
      case FL_TIMES_BOLD :
      case FL_TIMES_BOLD_ITALIC :
      case FL_TIMES_ITALIC :
        cairo_select_font_face(_cr, "serif",
          fontid & FL_ITALIC ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
          fontid & FL_BOLD ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
        break;
      default :
        cairo_select_font_face(_cr, "sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    }
    _currentFontId = fontid;
  }
  cairo_set_font_size(_cr, fontsize);
}

#endif
