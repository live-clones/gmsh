// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkStringTexture.h"
#include "FlGui.h"
#include "sceneViewFltk.h"
#include "glImmediate.h"
#include "glShader.h"
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

    // everything below is in true pixels, and the strings are drawn at that
    // scale so that they are sharp on a high resolution screen
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    double f = 1.;
    sceneViewFltk *gl = FlGui::available() ?
                         FlGui::instance()->getCurrentOpenglWindow() :
                         nullptr;
    if(gl)
      // the window's, or the picture's being printed
      f = gl->getDrawContext()->highResolutionPixelFactor();
    else if(Fl_Window::current() && Fl_Window::current()->w() > 0)
      f = vp[2] / (double)Fl_Window::current()->w();
    if(f <= 0.) f = 1.;

    // 1000 should be _totalWidth but it does not work
    int w = (int)(1000 * f), h = (int)(_maxHeight * f) + 1;
    Fl_Offscreen offscreen = fl_create_offscreen(w, h);
    fl_begin_offscreen(offscreen);
    fl_color(0, 0, 0);
    fl_rectf(0, 0, w, h);
    fl_color(255, 255, 255);
    int pos = 0;
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      fl_font(it->fontId, (int)(it->fontSize * f));
      fl_draw(it->text.c_str(), pos, (int)(it->height * f) - fl_descent());
      pos += (int)(it->width * f);
    }
    uchar *data = fl_read_image(nullptr, 0, 0, w, h);
    for(int i = 0; i < w * h; ++i) { data[i] = data[i * 3]; }
    fl_end_offscreen();
    fl_delete_offscreen(offscreen);

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
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, shaders ? GL_R8 : GL_ALPHA, w, h, 0,
                 shaders ? GL_RED : GL_ALPHA, GL_UNSIGNED_BYTE, data);
    // the filtering a rectangle texture had by default
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gmshTexture(textureId);

    pos = 0;
    for(auto it = _elements.begin(); it != _elements.end(); ++it) {
      gmshTranslate(it->x, it->y, it->z);
      gmshColor4f(it->r, it->g, it->b, it->alpha);
      int Lx = (int)(it->width * f);
      int Ly = (int)(it->height * f);
      // the coordinates are in [0, 1] across the picture, not in its pixels
      float s0 = pos / (float)w, s1 = (pos + Lx) / (float)w;
      float t0 = 0.f, t1 = Ly / (float)h;
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
    delete[] data;
  }
};

void drawContextFltkStringTexture::flushString() { _queue->flush(); }

// ensure the surface is large enough
void drawContextFltkStringTexture::drawString(const char *str)
{
  GLfloat pos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  double win[3] = {pos[0], pos[1], pos[2]};
  drawString(str, win);
}

// the position and colour are passed in, as a core profile has neither a
// raster position nor a current colour to query
void drawContextFltkStringTexture::drawString(const char *str,
                                              const double win[3])
{
  const unsigned char *c = gmshCurrentColor();
  GLfloat color[4] = {c[0] / 255.f, c[1] / 255.f, c[2] / 255.f, c[3] / 255.f};
  queueString::element elem = {str,
                               (GLfloat)win[0],
                               (GLfloat)win[1],
                               (GLfloat)win[2],
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
