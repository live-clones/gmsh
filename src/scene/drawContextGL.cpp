// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <cstring>
#include <algorithm>

#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>

#include "drawContextGL.h"
#include "sceneHost.h"
#include "GmshMessage.h"
#include "Context.h"

// The PostScript font names Gmsh has always exposed through
// General.GraphicsFont. Dear ImGui ships with a single embedded font, so they
// currently all resolve to it; the index is nevertheless kept and saved in the
// option files, so that .geo scripts and .gmsh-options written by the FLTK
// build keep working.
static const char *_fontNames[] = {
  "Times-Roman",  "Times-Bold",       "Times-Italic",      "Times-BoldItalic",
  "Helvetica",    "Helvetica-Bold",   "Helvetica-Oblique", "Helvetica-BoldOblique",
  "Courier",      "Courier-Bold",     "Courier-Oblique",   "Courier-BoldOblique",
  "Symbol",       "ZapfDingbats",     "Screen"};
static const int _numFonts = sizeof(_fontNames) / sizeof(_fontNames[0]);
static const int _defaultFont = 4; // Helvetica

drawContextGL::drawContextGL() : _fontIndex(_defaultFont), _fontSize(12)
{
}

void drawContextGL::draw(bool rateLimited)
{
  if(Scene::host().redraw) Scene::host().redraw();
  if(Scene::host().check) Scene::host().check(rateLimited);
}

void drawContextGL::drawCurrentOpenglWindow(bool make_current)
{
  if(Scene::host().drawCurrent) Scene::host().drawCurrent();
}

int drawContextGL::getFontIndex(const char *fontname)
{
  if(fontname) {
    for(int i = 0; i < _numFonts; i++)
      if(!strcmp(_fontNames[i], fontname)) return i;
  }
  Msg::Error("Unknown font \"%s\" (using \"Helvetica\" instead)", fontname);
  Msg::Info("Available fonts:");
  for(int i = 0; i < _numFonts; i++) Msg::Info("  \"%s\"", _fontNames[i]);
  return _defaultFont;
}

int drawContextGL::getFontEnum(int index)
{
  // there is no toolkit-level font enum here: the index is the enum
  if(index >= 0 && index < _numFonts) return index;
  return _defaultFont;
}

const char *drawContextGL::getFontName(int index)
{
  if(index >= 0 && index < _numFonts) return _fontNames[index];
  return _fontNames[_defaultFont];
}

int drawContextGL::getNumFonts() { return _numFonts; }

int drawContextGL::getFontSize()
{
  if(CTX::instance()->fontSize > 0) return CTX::instance()->fontSize;

  // same heuristic as the FLTK backend: pick a size from the height of the
  // primary monitor, falling back on its DPI
  int h = 0;
  if(GLFWmonitor *monitor = glfwGetPrimaryMonitor()) {
    if(const GLFWvidmode *mode = glfwGetVideoMode(monitor)) h = mode->height;
  }
  if(h > 0) {
    if(h < 800) return 11;
    else if(h < 1000) return 12;
    else if(h < 1200) return 13;
    else if(h < 1400) return 14;
    else if(h < 1600) return 15;
    else if(h < 1800) return 16;
  }
  float sx = 1.f, sy = 1.f;
  if(GLFWmonitor *monitor = glfwGetPrimaryMonitor())
    glfwGetMonitorContentScale(monitor, &sx, &sy);
  return std::max(16, (int)(96. * sx / 10.));
}

void drawContextGL::setFont(int fontid, int fontsize)
{
  _fontIndex = (fontid >= 0 && fontid < _numFonts) ? fontid : _defaultFont;
  int size = (fontsize > 0) ? fontsize : 12;
  // General.GraphicsFontSize is a size in points: turn it into pixels using the
  // scale factor of the display, so that the labels of the scene keep the same
  // physical size whatever the resolution
  if(Scene::host().uiScale) {
    float scale = Scene::host().uiScale();
    if(scale > 0.f) size = (int)(size * scale + 0.5f);
  }
  _fontSize = (size > 0) ? size : 12;
}

// Return the baked font matching the current font size, making sure the glyphs
// it needs are in the atlas. Null if Dear ImGui is not initialized yet.
static ImFontBaked *_baked(int fontSize)
{
  if(!ImGui::GetCurrentContext()) return nullptr;
  ImGuiIO &io = ImGui::GetIO();
  ImFont *font = io.FontDefault ? io.FontDefault :
                 (io.Fonts->Fonts.Size ? io.Fonts->Fonts[0] : nullptr);
  if(!font || !font->IsLoaded()) return nullptr;
  return font->GetFontBaked((float)fontSize);
}

double drawContextGL::getStringWidth(const char *str)
{
  ImFontBaked *baked = _baked(_fontSize);
  if(!baked || !str) return 1.;
  double w = 0.;
  for(const char *p = str; *p; p++) {
    ImFontGlyph *g = baked->FindGlyph((ImWchar)(unsigned char)*p);
    if(g) w += g->AdvanceX;
  }
  return w;
}

int drawContextGL::getStringHeight()
{
  ImFontBaked *baked = _baked(_fontSize);
  if(!baked) return _fontSize;
  return (int)(baked->Ascent - baked->Descent + 0.5f);
}

int drawContextGL::getStringDescent()
{
  ImFontBaked *baked = _baked(_fontSize);
  if(!baked) return _fontSize / 4;
  return (int)(-baked->Descent + 0.5f);
}

void drawContextGL::drawString(const char *str)
{
  if(!str || !*str) return;

  ImFontBaked *baked = _baked(_fontSize);
  if(!baked) return;

  // the raster position set by the caller through glRasterPos() gives us where
  // the string starts, in window coordinates; if it is outside the viewport the
  // position is invalid and nothing should be drawn (same behaviour as
  // gl_draw() on top of glRasterPos())
  GLboolean valid = GL_FALSE;
  glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &valid);
  if(!valid) return;
  GLfloat rpos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, rpos);

  GLfloat color[4];
  glGetFloatv(GL_CURRENT_COLOR, color);

  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  // asking for a glyph may have added it to the atlas: push the new pixels to
  // the GPU now, otherwise the string would only appear on the next frame
  if(ImGui::GetCurrentContext()) {
    for(ImTextureData *tex : ImGui::GetPlatformIO().Textures)
      if(tex->Status != ImTextureStatus_OK) ImGui_ImplOpenGL2_UpdateTexture(tex);
  }
  ImTextureID texId = ImGui::GetIO().Fonts->TexRef.GetTexID();
  if(texId == ImTextureID_Invalid) return;

  glPushAttrib(GL_ENABLE_BIT | GL_TEXTURE_BIT | GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(viewport[0], viewport[0] + viewport[2], viewport[1],
          viewport[1] + viewport[3], -1., 1.);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)texId);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glColor4fv(color);

  // the raster position is the baseline of the first character, with y pointing
  // up, while the glyph offsets are relative to the top of the line with y
  // pointing down
  float x = rpos[0];
  float y = rpos[1] + baked->Ascent;

  glBegin(GL_QUADS);
  for(const char *p = str; *p; p++) {
    ImFontGlyph *g = baked->FindGlyph((ImWchar)(unsigned char)*p);
    if(!g) continue;
    if(g->Visible) {
      float x0 = x + g->X0, x1 = x + g->X1;
      float y0 = y - g->Y0, y1 = y - g->Y1;
      glTexCoord2f(g->U0, g->V0); glVertex2f(x0, y0);
      glTexCoord2f(g->U1, g->V0); glVertex2f(x1, y0);
      glTexCoord2f(g->U1, g->V1); glVertex2f(x1, y1);
      glTexCoord2f(g->U0, g->V1); glVertex2f(x0, y1);
    }
    x += g->AdvanceX;
  }
  glEnd();

  glBindTexture(GL_TEXTURE_2D, 0);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}

void drawContextGL::resetFontTextures()
{
  // the Dear ImGui atlas rebuilds itself on demand: nothing to do
}

#endif
