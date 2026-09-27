// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <cstring>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "drawContextOffscreen.h"
#include "offscreenContext.h"
#include "stbStrings.h"
#include "glImmediate.h"
#include "glShader.h"

drawContextOffscreen::drawContextOffscreen()
  : _ctx(nullptr), _strings(nullptr), _fontId(-1), _fontSize(12), _width(0),
    _height(0), _scale(1.), _previous(nullptr)
{
  _strings = new stbStrings;
  for(int i = 0; i < 16; i++) _frameView[i] = (i % 5) ? 0. : 1.;
}

drawContextOffscreen::~drawContextOffscreen()
{
  delete _ctx;
  delete _strings;
}

// the colour a frame starts from: white for a print without its background
static void setClearColor()
{
  CTX *ctx = CTX::instance();
  if(ctx->printing && !ctx->print.background)
    glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
  else
    glClearColor((GLclampf)(ctx->unpackRed(ctx->color.bg) / 255.),
                 (GLclampf)(ctx->unpackGreen(ctx->color.bg) / 255.),
                 (GLclampf)(ctx->unpackBlue(ctx->color.bg) / 255.), 0.0F);
}

bool drawContextOffscreen::begin(int width, int height, double scale)
{
  if(width < 1 || height < 1) return false;
  if(!offscreenContext::makeCurrent(CTX::instance()->shaders)) return false;
  if(CTX::instance()->shaders) glShader::available();
  if(!glShader::beginPrintTarget(width, height)) {
    Msg::Error("Could not draw a picture of %dx%d pixels without a window",
               width, height);
    return false;
  }
  _width = width;
  _height = height;
  _scale = scale;
  // the view of the options (a window takes it from them when it is made)
  delete _ctx;
  _ctx = new drawContext();
  glImmediate::pixelScale(scale);
  _previous = drawContext::global();
  drawContext::setGlobal(this);
  setPixelFactor(scale);
  // gl2ps takes the background of its page from the clear colour, before any
  // frame is drawn
  setClearColor();
  return true;
}

void drawContextOffscreen::read(GLenum format, GLenum type, void *pixels)
{
  glShader::readPrintTarget(_width, _height, format, type, pixels);
}

void drawContextOffscreen::end()
{
  glShader::endPrintTarget();
  glImmediate::pixelScale(1.);
  if(drawContext::global() == this) drawContext::setGlobal(_previous);
  _previous = nullptr;
}

// what openglWindow::draw() does for the whole scene
void drawContextOffscreen::drawCurrentOpenglWindow(bool make_current,
                                                  bool again)
{
  if(!_ctx) return;
  CTX *ctx = CTX::instance();
  _ctx->studioSample = 0;
  _ctx->invalidatePickCache();
  _ctx->viewport[0] = 0;
  _ctx->viewport[1] = 0;
  _ctx->viewport[2] = (int)(_width / _scale + 0.5);
  _ctx->viewport[3] = (int)(_height / _scale + 0.5);
  _ctx->setHighResolutionPixelFactor(_scale);
  glViewport(0, 0, _width, _height);
  setPixelFactor(_scale);

  setClearColor();
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  if(ctx->camera) {
    _ctx->initCameraMatrices(_frameView);
    _ctx->draw3d();
  }
  else {
    _ctx->draw3d();
    memcpy(_frameView, _ctx->model, sizeof(_frameView));
  }
  _ctx->draw2d();
  // all the frames of the studio shading, as a print of a window has them
  if(glShader::enabled() && ctx->shading >= 1 && ctx->studioSamples >= 2) {
    glImmediate::flush();
    flushString();
    _ctx->drawStudioFrames(1, _width, _height, _frameView);
    _ctx->studioSample = 0;
  }
  glImmediate::flush();
  flushString();
}

int drawContextOffscreen::getFontSize()
{
  return CTX::instance()->fontSize > 0 ? CTX::instance()->fontSize : 12;
}

void drawContextOffscreen::setFont(int fontid, int fontsize)
{
  _fontId = fontid;
  _fontSize = fontsize;
  _strings->setFont(fontid, fontsize);
}

double drawContextOffscreen::getStringWidth(const char *str)
{
  return _strings->width(str);
}

int drawContextOffscreen::getStringHeight()
{
  return (int)std::ceil(_strings->height());
}

int drawContextOffscreen::getStringDescent()
{
  return (int)std::ceil(_strings->descent());
}

void drawContextOffscreen::drawString(const char *str)
{
  GLfloat pos[4];
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  double win[3] = {pos[0], pos[1], pos[2]};
  drawString(str, win);
}

void drawContextOffscreen::drawString(const char *str, const double win[3])
{
  _strings->add(str, win, _fontId, _fontSize, stringHalo());
}

void drawContextOffscreen::flushString()
{
  _strings->flush(_scale);
}
