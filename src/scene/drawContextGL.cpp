// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>

#include "drawContextGL.h"
#include "stbStrings.h"
#include "sceneHost.h"
#include "sceneView.h"
#include "Context.h"

drawContextGL::drawContextGL()
  : _strings(new stbStrings), _fontId(-1), _fontSize(12)
{
}

drawContextGL::~drawContextGL() { delete _strings; }

void drawContextHosted::draw(bool rateLimited)
{
  sceneView::changed();
  if(Scene::host().redraw) Scene::host().redraw();
  if(Scene::host().check) Scene::host().check(rateLimited);
}

void drawContextHosted::drawCurrentOpenglWindow(bool make_current,
                                                 bool again)
{
  sceneView::changed();
  sceneView *view = Scene::host().current ? Scene::host().current() : nullptr;
  if(view) view->setAgain(again);
  if(Scene::host().drawCurrent) Scene::host().drawCurrent();
  if(view) view->setAgain(false);
}

int drawContextHosted::getFontSize()
{
  if(CTX::instance()->fontSize > 0) return CTX::instance()->fontSize;

  // the screen as the holder sees it
  int h = 0;
  float sx = 1.f;
  if(Scene::host().screen) Scene::host().screen(h, sx);
  if(h > 0) {
    if(h < 800) return 11;
    else if(h < 1000) return 12;
    else if(h < 1200) return 13;
    else if(h < 1400) return 14;
    else if(h < 1600) return 15;
    else if(h < 1800) return 16;
  }
  return std::max(16, (int)(96. * sx / 10.));
}

// while dragging, the fast representation
bool drawContextHosted::mouseIsPressed()
{
  return Scene::host().buttonDown ? Scene::host().buttonDown() : false;
}

void drawContextGL::setFont(int fontid, int fontsize)
{
  // in the pixels of the scene, which the strings are rasterised at the pixel
  // factor of; an interface drawn larger than its framebuffer says (a scale
  // set by hand, or X11) has its strings follow it
  double size = (fontsize > 0) ? fontsize : 12;
  if(Scene::host().uiScale) {
    float scale = Scene::host().uiScale();
    if(scale > 0.f) size *= scale / pixelFactor();
  }
  _fontId = fontid;
  _fontSize = std::max(1, (int)(size + 0.5));
  _strings->setFont(_fontId, _fontSize);
}

double drawContextGL::getStringWidth(const char *str)
{
  return _strings->width(str);
}

int drawContextGL::getStringHeight()
{
  return (int)std::ceil(_strings->height());
}

int drawContextGL::getStringDescent()
{
  return (int)std::ceil(_strings->descent());
}

void drawContextGL::drawString(const char *str)
{
  GLfloat pos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  double win[3] = {pos[0], pos[1], pos[2]};
  drawString(str, win);
}

void drawContextGL::drawString(const char *str, const double win[3])
{
  _strings->add(str, win, _fontId, _fontSize, stringHalo());
}

void drawContextGL::flushString()
{
  // measuring the strings sets their fonts: the caller's comes back
  _strings->flush(pixelFactor());
  if(_fontId >= 0) _strings->setFont(_fontId, _fontSize);
}
