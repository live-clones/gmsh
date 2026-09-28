// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE) && defined(HAVE_GLFW)

#include <cstring>
#include <algorithm>

#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>

#include "drawContextGL.h"
#include "glImmediate.h"
#include "sceneHost.h"
#include "sceneView.h"
#include "GmshMessage.h"
#include "Context.h"

drawContextGL::drawContextGL() : _fontIndex(fontEnum::helvetica), _fontSize(12)
{
}

void drawContextGL::draw(bool rateLimited)
{
  if(Scene::host().redraw) Scene::host().redraw();
  if(Scene::host().check) Scene::host().check(rateLimited);
}

void drawContextGL::drawCurrentOpenglWindow(bool make_current, bool again)
{
  sceneView *view = Scene::host().current ? Scene::host().current() : nullptr;
  if(view) view->setAgain(again);
  if(Scene::host().drawCurrent) Scene::host().drawCurrent();
  if(view) view->setAgain(false);
}

int drawContextGL::getFontSize()
{
  if(CTX::instance()->fontSize > 0) return CTX::instance()->fontSize;

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
  // one font for all: the index is kept for the option files
  _fontIndex = fontid;
  int size = (fontsize > 0) ? fontsize : 12;
  // points into pixels through the scale of the display
  if(Scene::host().uiScale) {
    float scale = Scene::host().uiScale();
    if(scale > 0.f) size = (int)(size * scale + 0.5f);
  }
  _fontSize = (size > 0) ? size : 12;
}

// null if Dear ImGui is not initialized yet
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
  // outside the viewport the raster position is invalid and nothing is drawn,
  // as gl_draw() does
  GLboolean valid = GL_FALSE;
  glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &valid);
  if(!valid) return;
  GLfloat rpos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, rpos);
  double win[3] = {rpos[0], rpos[1], rpos[2]};
  drawString(str, win);
}

void drawContextGL::drawString(const char *str, const double win[3])
{
  if(!str || !*str) return;
  ImFontBaked *baked = _baked(_fontSize);
  if(!baked) return;

  // a glyph just added to the atlas has to reach the GPU now
  if(ImGui::GetCurrentContext()) {
    for(ImTextureData *tex : ImGui::GetPlatformIO().Textures)
      if(tex->Status != ImTextureStatus_OK) ImGui_ImplOpenGL2_UpdateTexture(tex);
  }
  ImTextureID texId = ImGui::GetIO().Fonts->TexRef.GetTexID();
  if(texId == ImTextureID_Invalid) return;

  // through the wrappers, so that either pipeline draws them
  int matrixMode = gmshMatrixMode();
  gmshMatrixMode(GMSH_PROJECTION);
  gmshPushMatrix();
  gmshLoadIdentity();
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshPushMatrix();
  gmshLoadIdentity();
  GLint vp[4];
  glGetIntegerv(GL_VIEWPORT, vp);
  gmshScale(2. / vp[2], 2. / vp[3], 1.);
  gmshTranslate(-vp[2] / 2., -vp[3] / 2., 0.);

  bool wasLit = gmshLightingEnabled();
  GLboolean wasDepth = glIsEnabled(GL_DEPTH_TEST);
  GLboolean wasBlend = glIsEnabled(GL_BLEND);
  bool wasClip[6];
  for(int i = 0; i < 6; i++) {
    wasClip[i] = gmshClipPlaneEnabled(i);
    if(wasClip[i]) gmshClipPlaneOn(i, false);
  }
  gmshLighting(false);
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  gmshTexture((unsigned int)(intptr_t)texId, GMSH_TEXTURE_ATLAS);

  // the baseline with y up; the glyph offsets from the top of the line with y
  // down
  float x = (float)win[0] - vp[0];
  float y = (float)win[1] - vp[1] + baked->Ascent;
  gmshBegin(GL_QUADS);
  for(const char *p = str; *p; p++) {
    ImFontGlyph *g = baked->FindGlyph((ImWchar)(unsigned char)*p);
    if(!g) continue;
    if(g->Visible) {
      float x0 = x + g->X0, x1 = x + g->X1;
      float y0 = y - g->Y0, y1 = y - g->Y1;
      gmshTexCoord2f(g->U0, g->V0);
      gmshVertex2d(x0, y0);
      gmshTexCoord2f(g->U1, g->V0);
      gmshVertex2d(x1, y0);
      gmshTexCoord2f(g->U1, g->V1);
      gmshVertex2d(x1, y1);
      gmshTexCoord2f(g->U0, g->V1);
      gmshVertex2d(x0, y1);
    }
    x += g->AdvanceX;
  }
  gmshEnd();
  glImmediate::flush();

  gmshTexture(0);
  if(wasDepth) glEnable(GL_DEPTH_TEST);
  if(!wasBlend) glDisable(GL_BLEND);
  gmshLighting(wasLit);
  for(int i = 0; i < 6; i++)
    if(wasClip[i]) gmshClipPlaneOn(i, true);
  gmshPopMatrix();
  gmshMatrixMode(GMSH_PROJECTION);
  gmshPopMatrix();
  gmshMatrixMode(matrixMode);
}

void drawContextGL::resetFontTextures()
{
}

#endif
