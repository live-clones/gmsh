// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkCairo.h"

#if defined(HAVE_CAIRO)
#include <cairo/cairo.h>

// FIXME: hack for current version of mingw
#if defined(WIN32) && !defined(GL_TEXTURE_RECTANGLE_ARB)
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#endif

class drawContextFltkCairo::queueString {
public:
  typedef struct {
    std::string text;
    GLfloat x, y, z;
    GLfloat r, g, b, alpha;
    int fontSize;
    cairo_font_face_t *fontFace;
    int width, height;
    double xBearing, yBearing;
  } element;

private:
  std::vector<element> _elements;
  int _totalWidth, _maxHeight;

public:
  queueString()
  {
    _totalWidth = 0;
    _maxHeight = 0;
  }

  ~queueString()
  {
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      cairo_font_face_destroy(it->fontFace);
    }
  }

  void append(const element &elem)
  {
    if(_totalWidth + elem.width > 1000) flush();
    _elements.push_back(elem);
    _totalWidth += elem.width;
    _maxHeight = std::max(_maxHeight, (int)elem.height + 1);
  }

  void flush()
  {
    if(_elements.empty()) return;
    cairo_surface_t *surface =
      cairo_image_surface_create(CAIRO_FORMAT_A8, _totalWidth, _maxHeight);
    cairo_t *cr = cairo_create(surface);
    int pos = 0;
    cairo_set_source_rgba(cr, 0., 0., 0., 0);
    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint(cr);
    cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
    cairo_font_options_t *fontOptions = cairo_font_options_create();
    cairo_get_font_options(cr, fontOptions);
    cairo_font_options_set_hint_style(fontOptions, CAIRO_HINT_STYLE_FULL);
    cairo_font_options_set_antialias(fontOptions, CAIRO_ANTIALIAS_GRAY);
    cairo_set_font_options(cr, fontOptions);
    cairo_font_options_destroy(fontOptions);

    cairo_set_source_rgba(cr, 1, 1, 1, 1);
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      cairo_move_to(cr, pos - it->xBearing, -it->yBearing);
      cairo_set_font_size(cr, it->fontSize);
      cairo_set_font_face(cr, it->fontFace);
      cairo_show_text(cr, it->text.c_str());
      cairo_font_face_destroy(it->fontFace);
      pos += it->width;
    }
    cairo_destroy(cr);
    // setup matrices
    GLint matrixMode;
    GLuint textureId;
    glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    float winw = Fl_Window::current()->w();
    float winh = Fl_Window::current()->h();
    glScalef(2.0f / winw, 2.0f / winh, 1.0f);
    glTranslatef(-winw / 2.0f, -winh / 2.0f, 0.0f);
    // write the texture on screen
    glEnable(GL_TEXTURE_RECTANGLE_ARB);
    glPushAttrib(GL_ENABLE_BIT | GL_TEXTURE_BIT | GL_COLOR_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, textureId);
    glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_ALPHA,
                 cairo_image_surface_get_width(surface),
                 cairo_image_surface_get_height(surface), 0, GL_ALPHA,
                 GL_UNSIGNED_BYTE, cairo_image_surface_get_data(surface));
    // glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_SRC0_ALPHA);
    // printf("error %i %s\n", __LINE__, gluErrorString(glGetError()));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    pos = 0;
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      glTranslatef(it->x, it->y, it->z);
      glColor4f(it->r, it->g, it->b, it->alpha);
      int Lx = it->width;
      int Ly = it->height;

      glBegin(GL_QUADS);
      glTexCoord2f(pos, 0);
      glVertex2f(0.0f, Ly);
      glTexCoord2f(pos + Lx, 0);
      glVertex2f(Lx, Ly);
      glTexCoord2f(pos + Lx, Ly);
      glVertex2f(Lx, 0.0f);
      glTexCoord2f(pos, Ly);
      glVertex2f(0.0f, 0.0f);
      glEnd();
      pos += Lx;
      glTranslatef(-it->x, -it->y, -it->z);
    }
    glDeleteTextures(1, &textureId);

    glPopAttrib();

    // reset original matrices
    glPopMatrix(); // GL_MODELVIEW
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(matrixMode);
    _elements.clear();
    _maxHeight = 0;
    _totalWidth = 0;
    cairo_surface_destroy(surface);
  }
};

double drawContextFltkCairo::getStringWidth(const char *str)
{
  cairo_text_extents_t e;
  cairo_text_extents(_cr, str, &e);
  return e.width;
}

void drawContextFltkCairo::flushString() { _queue->flush(); }

void drawContextFltkCairo::drawString(const char *str)
{
  GLfloat pos[4], color[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  glGetFloatv(GL_CURRENT_COLOR, color);
  cairo_set_font_size(_cr, _currentFontSize);
  cairo_text_extents_t extent;
  cairo_text_extents(_cr, str, &extent);
  queueString::element elem = {str,
                               pos[0],
                               pos[1],
                               pos[2],
                               color[0],
                               color[1],
                               color[2],
                               color[3],
                               _currentFontSize,
                               cairo_get_font_face(_cr),
                               (int)ceil(extent.width) + 2,
                               (int)ceil(extent.height) + 2,
                               extent.x_bearing - 1,
                               extent.y_bearing - 1};
  cairo_font_face_reference(elem.fontFace);
  _queue->append(elem);
}

drawContextFltkCairo::~drawContextFltkCairo()
{
  cairo_destroy(_cr);
  cairo_surface_destroy(_surface);
  delete _queue;
}

drawContextFltkCairo::drawContextFltkCairo()
{
  _surface = cairo_image_surface_create(CAIRO_FORMAT_A8, 1, 1);
  _queue = new queueString;
  _cr = cairo_create(_surface);
  cairo_font_options_t *fontOptions = cairo_font_options_create();
  cairo_get_font_options(_cr, fontOptions);
  cairo_font_options_set_hint_style(fontOptions, CAIRO_HINT_STYLE_FULL);
  cairo_font_options_set_antialias(fontOptions, CAIRO_ANTIALIAS_GRAY);
  cairo_set_font_options(_cr, fontOptions);
  cairo_font_options_destroy(fontOptions);
  _currentFontId = -1;
}

void drawContextFltkCairo::setFont(int fontid, int fontsize)
{
  if(_currentFontId != fontid) {
    switch(fontid) {
    case FL_HELVETICA:
    case FL_HELVETICA_BOLD:
    case FL_HELVETICA_BOLD_ITALIC:
    case FL_HELVETICA_ITALIC:
      cairo_select_font_face(
        _cr, "sans",
        fontid & FL_ITALIC ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
        fontid & FL_BOLD ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
      break;
    case FL_COURIER:
    case FL_COURIER_BOLD:
    case FL_COURIER_BOLD_ITALIC:
    case FL_COURIER_ITALIC:
      cairo_select_font_face(
        _cr, "courier",
        fontid & FL_ITALIC ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
        fontid & FL_BOLD ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
      break;
    case FL_TIMES:
    case FL_TIMES_BOLD:
    case FL_TIMES_BOLD_ITALIC:
    case FL_TIMES_ITALIC:
      cairo_select_font_face(
        _cr, "serif",
        fontid & FL_ITALIC ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
        fontid & FL_BOLD ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);
      break;
    default:
      cairo_select_font_face(_cr, "sans", CAIRO_FONT_SLANT_NORMAL,
                             CAIRO_FONT_WEIGHT_NORMAL);
    }
    _currentFontId = fontid;
  }
  cairo_set_font_size(_cr, fontsize);
  _currentFontSize = fontsize;
}

#endif
