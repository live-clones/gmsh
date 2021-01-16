// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkStringTexture.h"
#include <algorithm>

// FIXME: hack for current version of mingw
#if defined(WIN32) && !defined(GL_TEXTURE_RECTANGLE_ARB)
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#endif

class drawContextFltkStringTexture::queueString {
public:
  typedef struct {
    std::string text;
    GLfloat x, y, z;
    GLfloat r, g, b, alpha;
    int fontSize, fontId;
    int width;
    int height;
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
  void append(const element &elem)
  {
    if(_totalWidth + elem.width > 1000) flush();
    _elements.push_back(elem);
    _totalWidth += elem.width;
    _maxHeight = std::max(_maxHeight, elem.height);
  }
  void flush()
  {
    if(_elements.empty()) return;
    // 1000 should be _totalWidth but it does not work
    int w = 1000, h = _maxHeight;
    Fl_Offscreen offscreen = fl_create_offscreen(w, h);
    fl_begin_offscreen(offscreen);
    fl_color(0, 0, 0);
    fl_rectf(0, 0, w, h);
    fl_color(255, 255, 255);
    int pos = 0;
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      fl_font(it->fontId, it->fontSize);
      fl_draw(it->text.c_str(), pos, it->height - fl_descent());
      pos += it->width;
    }
    uchar *data = fl_read_image(nullptr, 0, 0, w, h);
    for(int i = 0; i < w * h; ++i) { data[i] = data[i * 3]; }
    fl_end_offscreen();
    fl_delete_offscreen(offscreen);

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

    // FIXME: this is not correct with high-resolution graphics, as w(), h() are
    // in FLTK coordinates, and glRasterPos uses true pixels.
    // The size of the QUAD needs to be changed, too.
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
    glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_ALPHA, w, h, 0, GL_ALPHA,
                 GL_UNSIGNED_BYTE, data);
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
    delete[] data;
  }
};

void drawContextFltkStringTexture::flushString() { _queue->flush(); }

// ensure the surface is large enough
void drawContextFltkStringTexture::drawString(const char *str)
{
  GLfloat pos[4], color[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  glGetFloatv(GL_CURRENT_COLOR, color);
  queueString::element elem = {str,
                               pos[0],
                               pos[1],
                               pos[2],
                               color[0],
                               color[1],
                               color[2],
                               color[3],
                               _currentFontSize,
                               _currentFontId,
                               (int)getStringWidth(str) + 1,
                               getStringHeight()};
  _queue->append(elem);
}

drawContextFltkStringTexture::~drawContextFltkStringTexture() { delete _queue; }

drawContextFltkStringTexture::drawContextFltkStringTexture()
{
  _queue = new queueString;
}

void drawContextFltkStringTexture::setFont(int fontid, int fontsize)
{
  drawContextFltk::setFont(fontid, fontsize);
  _currentFontId = fontid;
  _currentFontSize = fontsize;
}
