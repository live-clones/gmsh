// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkCairo.h"
#include "glImmediate.h"
#include "glShader.h"

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

    // everything below is in true pixels, and the strings are drawn at that
    // scale so that they are sharp on a high resolution screen
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    double f = 1.;
    if(Fl_Window::current() && Fl_Window::current()->w() > 0)
      f = vp[2] / (double)Fl_Window::current()->w();
    if(f <= 0.) f = 1.;

    cairo_surface_t *surface = cairo_image_surface_create(
      CAIRO_FORMAT_A8, (int)(_totalWidth * f) + 1, (int)(_maxHeight * f) + 1);
    cairo_t *cr = cairo_create(surface);
    double pos = 0.;
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
      cairo_move_to(cr, pos - it->xBearing * f, -it->yBearing * f);
      cairo_set_font_size(cr, it->fontSize * f);
      cairo_set_font_face(cr, it->fontFace);
      cairo_show_text(cr, it->text.c_str());
      cairo_font_face_destroy(it->fontFace);
      pos += it->width * f;
    }
    cairo_destroy(cr);
    // setup matrices
    int matrixMode;
    GLuint textureId;
    matrixMode = gmshMatrixMode();
    gmshMatrixMode(GMSH_PROJECTION);
    gmshPushMatrix();
    gmshLoadIdentity();
    gmshMatrixMode(GMSH_MODELVIEW);
    gmshPushMatrix();
    gmshLoadIdentity();
    // the whole window, in the true pixels the positions are given in
    gmshScale(2. / vp[2], 2. / vp[3], 1.);
    gmshTranslate(-vp[2] / 2., -vp[3] / 2., 0.);

    // a plain 2D texture with coordinates in [0, 1] (rectangle textures are
    // not in OpenGL ES), with one channel giving the alpha of the colour:
    // an alpha texture for the fixed function pipeline, a red one for the
    // shader
    bool shaders = gmshUseShaders();
    bool wasLit = gmshLightingEnabled();
    // the queue can be flushed in the middle of the scene, so the state
    // changed here is put back afterwards: through the attribute stack with
    // the fixed function pipeline, by hand with the shader one. The
    // transparency pass keeps its own blending.
    GLboolean wasDepth = glIsEnabled(GL_DEPTH_TEST);
    GLboolean wasBlend = glIsEnabled(GL_BLEND);
    bool ownBlend = !glShader::transparentPass();
    if(!shaders) {
      // glPopAttrib() does not restore the lighting we remember ourselves
      glPushAttrib(GL_ENABLE_BIT | GL_TEXTURE_BIT | GL_COLOR_BUFFER_BIT);
    }
    gmshLighting(false);
    glDisable(GL_DEPTH_TEST);
    if(ownBlend) {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    int tw = cairo_image_surface_get_width(surface);
    int th = cairo_image_surface_get_height(surface);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    // cairo pads the rows to a multiple of four bytes
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ROW_LENGTH,
                  cairo_image_surface_get_stride(surface));
    glTexImage2D(GL_TEXTURE_2D, 0, shaders ? GL_R8 : GL_ALPHA, tw, th, 0,
                 shaders ? GL_RED : GL_ALPHA, GL_UNSIGNED_BYTE,
                 cairo_image_surface_get_data(surface));
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    // the filtering a rectangle texture had by default
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gmshTexture(textureId);

    pos = 0.;
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      gmshTranslate(it->x, it->y, it->z);
      gmshColor4f(it->r, it->g, it->b, it->alpha);
      float Lx = (float)(it->width * f);
      float Ly = (float)(it->height * f);
      // the coordinates are in [0, 1] across the picture, not in its pixels
      float s0 = (float)(pos / tw), s1 = (float)((pos + Lx) / tw);
      float t0 = 0.f, t1 = Ly / (float)th;
      gmshBegin(GL_QUADS);
      gmshTexCoord2f(s0, t0);
      gmshVertex2f(0.0f, Ly);
      gmshTexCoord2f(s1, t0);
      gmshVertex2f(Lx, Ly);
      gmshTexCoord2f(s1, t1);
      gmshVertex2f(Lx, 0.0f);
      gmshTexCoord2f(s0, t1);
      gmshVertex2f(0.0f, 0.0f);
      gmshEnd();
      pos += Lx;
      gmshTranslate(-it->x, -it->y, -it->z);
    }
    // whatever is waiting was collected to be drawn through this texture
    gmshFlushImmediate();
    gmshTexture(0);
    glDeleteTextures(1, &textureId);

    if(!shaders)
      glPopAttrib();
    else {
      if(wasDepth) glEnable(GL_DEPTH_TEST);
      if(ownBlend && !wasBlend) glDisable(GL_BLEND);
    }
    gmshLighting(wasLit);

    // reset original matrices
    gmshPopMatrix(); // GL_MODELVIEW
    gmshMatrixMode(GMSH_PROJECTION);
    gmshPopMatrix();
    gmshMatrixMode(matrixMode);
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
  GLfloat pos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  double win[3] = {pos[0], pos[1], pos[2]};
  drawString(str, win);
}

// the position and colour are passed in, as a core profile has neither a
// raster position nor a current colour to query
void drawContextFltkCairo::drawString(const char *str, const double win[3])
{
  const unsigned char *c = gmshCurrentColor();
  GLfloat color[4] = {c[0] / 255.f, c[1] / 255.f, c[2] / 255.f, c[3] / 255.f};
  cairo_set_font_size(_cr, _currentFontSize);
  cairo_text_extents_t extent;
  cairo_text_extents(_cr, str, &extent);
  queueString::element elem = {str,
                               (GLfloat)win[0],
                               (GLfloat)win[1],
                               (GLfloat)win[2],
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
