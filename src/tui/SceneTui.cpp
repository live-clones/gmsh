// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the terminal interface, see GuiScene.h: a sceneView drawn off
// screen -- a context of offscreenContext, a framebuffer of the size the
// terminal has room for -- and handed over as pictures, as the browser
// interface is; nothing needs a display server

#include "GmshConfig.h"

#if defined(HAVE_TUI) && defined(HAVE_GL_SCENE)

#include <algorithm>
#include <string>
#include <vector>

#include "glApi.h"
#include "glShader.h"
#include "offscreenContext.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "drawContextGL.h"
#include "GuiScene.h"
#include "Gui.h"
#include "GuiActions.h"
#include "Context.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "OS.h"

namespace {

  float _uiScale = .6f;
  int _screenHeight = 700;

  struct offscreen {
    bool tried = false, ok = false;
    sceneView *view = nullptr;
    paneInput input;
    double lastX = 0., lastY = 0.;
    bool everMoved = false;
    // the size asked for, and the framebuffer made for it
    int wantW = 160, wantH = 96;
    unsigned int fbo = 0, colour = 0, depth = 0;
    int fbW = 0, fbH = 0;
    // a picture is only read back when the scene changed
    bool changed = true, frameWanted = false, fresh = false;
    std::vector<unsigned char> picture;
    int pictureW = 0, pictureH = 0;
    int captureW = 0, captureH = 0;
    bool animating = false;
    std::vector<GVertex *> vertices;
    std::vector<GEdge *> edges;
    std::vector<GFace *> faces;
    std::vector<GRegion *> regions;
    std::vector<MElement *> elements;
    std::vector<SPoint2> points;
    std::vector<PView *> views;
  };

  offscreen &_it()
  {
    static offscreen it;
    return it;
  }

  void _changed()
  {
    _it().changed = true;
    _it().fresh = false;
  }

  // the framebuffer at the size asked for, bound and made the window's
  bool _bind()
  {
    offscreen &it = _it();
    if(!offscreenContext::makeCurrent(true)) return false;
    glShader::setContext(offscreenContext::id());
    if(!glApi::haveFramebufferObjects()) return false;
    if(it.fbo && (it.fbW != it.wantW || it.fbH != it.wantH)) {
      glApi::DeleteFramebuffers(1, &it.fbo);
      glApi::DeleteRenderbuffers(1, &it.colour);
      glApi::DeleteRenderbuffers(1, &it.depth);
      it.fbo = it.colour = it.depth = 0;
    }
    if(!it.fbo) {
      glApi::GenFramebuffers(1, &it.fbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, it.fbo);
      glApi::GenRenderbuffers(1, &it.colour);
      glApi::BindRenderbuffer(GL_RENDERBUFFER, it.colour);
      glApi::RenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, it.wantW, it.wantH);
      glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                     GL_RENDERBUFFER, it.colour);
      glApi::GenRenderbuffers(1, &it.depth);
      glApi::BindRenderbuffer(GL_RENDERBUFFER, it.depth);
      glApi::RenderbufferStorage(GL_RENDERBUFFER, 0x88F0 /* DEPTH24_STENCIL8 */,
                                 it.wantW, it.wantH);
      glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, 0x821A /* DEPTH_STENCIL */,
                                     GL_RENDERBUFFER, it.depth);
      const GLenum buf = GL_COLOR_ATTACHMENT0;
      glApi::DrawBuffers(1, &buf);
      if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
         GL_FRAMEBUFFER_COMPLETE) {
        Msg::Warning("Could not make a buffer of %dx%d pixels to draw the "
                     "scene into", it.wantW, it.wantH);
        return false;
      }
      it.fbW = it.wantW;
      it.fbH = it.wantH;
    }
    glApi::BindFramebuffer(GL_FRAMEBUFFER, it.fbo);
    glShader::setWindowFramebuffer(it.fbo);
    return true;
  }

  // failing is not fatal: the interface carries on without a scene
  bool _open()
  {
    offscreen &it = _it();
    if(it.ok) return true;
    if(it.tried) return false;
    it.tried = true;
    if(!offscreenContext::makeCurrent(true)) {
      Msg::Warning("Could not have an OpenGL context off screen: the model "
                   "will not be shown");
      return false;
    }
    glShader::setContext(offscreenContext::id());
    it.view = new sceneView();
    it.view->contextChanged();
    if(!dynamic_cast<drawContextGL *>(drawContext::global()))
      drawContext::setGlobal(new drawContextGL);

    Scene::Host held;
    held.redraw = []() { _changed(); };
    held.redrawView = [](sceneView *) { _it().frameWanted = true; };
    // the interface is pumped, not the scene, which would be pumping the loop
    // one is inside
    held.check = [](bool rateLimited) { Gui::instance().pumpChrome(rateLimited); };
    held.wait = [](double, bool) { Gui::instance().pumpChrome(false); };
    held.drawCurrent = []() {
      offscreen &one = _it();
      if(!_bind()) return;
      int w = one.fbW, h = one.fbH;
      if(one.captureW > 0 && one.captureH > 0) {
        // in the bottom-left corner, where PixelBuffer::fill() reads
        glDisable(GL_SCISSOR_TEST);
        glViewport(0, 0, w, h);
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        one.view->setRect(0, h - one.captureH, one.captureW, one.captureH);
      }
      else
        one.view->setRect(0, 0, w, h);
      one.view->setOrigin(0., 0., h, 1.);
      one.view->draw(1., h);
      one.view->setRect(0, 0, w, h);
      glFlush();
    };
    // a pixel of the picture is a quarter of a character: the text is drawn
    // as small as it can be read
    held.uiScale = []() { return _uiScale; };
    held.numViews = []() { return 1; };
    held.cursor = [](Scene::Cursor) {};
    held.current = []() { return _it().view; };
    held.setCurrent = [](sceneView *) {};
    held.later = Scene::later;
    held.buttonDown = []() {
      const paneInput &in = _it().input;
      return in.dragging[0] || in.dragging[1] || in.dragging[2];
    };
    held.context = []() -> void * { return (void *)offscreenContext::id(); };
    held.makeCurrent = [](sceneView *) { _bind(); };
    held.screen = [](int &height, float &scale) {
      // what matters is the picture the terminal shows, which is small: the
      // fonts are those of a small screen
      height = _screenHeight;
      scale = 1.f;
    };
    Scene::setHost(held);
    it.ok = true;
    return true;
  }

  void _handleInput()
  {
    offscreen &it = _it();
    if(!it.view || !_bind()) return;
    it.view->setRect(0, 0, it.fbW, it.fbH);
    it.view->setOrigin(0., 0., it.fbH, 1.);
    it.view->handleMouse(it.input);
    for(int b = 0; b < 3; b++) it.input.clicked[b] = it.input.released[b] = false;
    it.input.doubleClicked = false;
    it.input.wheel = 0.;
    it.input.dx = it.input.dy = 0.;
  }

  void _drawFrame()
  {
    offscreen &it = _it();
    if(!it.view || !_bind()) return;
    it.view->setRect(0, 0, it.fbW, it.fbH);
    it.view->setOrigin(0., 0., it.fbH, 1.);
    it.view->draw(1., it.fbH);
    glShader::release();
  }

} // namespace

void tuiSceneScale(float uiScale, int screenHeight)
{
  _uiScale = uiScale;
  _screenHeight = screenHeight;
}

namespace TuiScene {

  void sceneShownElsewhere() {}

  // the studio frames the timers ask for are drawn here, and a picture sent
  // only once they are all in
  void pumpScene(bool rateLimited)
  {
    offscreen &it = _it();
    if(!_open()) return;
    Scene::fireTimers();
    if(it.frameWanted) {
      it.frameWanted = false;
      _drawFrame();
      it.fresh = true;
      if(!it.view->accumulating()) it.changed = true;
    }
  }

  drawContext *getCurrentDrawContext()
  {
    if(!_open()) return nullptr;
    return _it().view ? _it().view->getDrawContext() : nullptr;
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = _it().wantW;
    height = _it().wantH;
  }

  void setCurrentOpenglWindow(int which) {}
  void showAllInEveryWindow()
  {
    if(_open() && _it().view) _it().view->getDrawContext()->showAll();
    _changed();
  }
  void splitCurrentOpenglWindow(char how, double ratio) {}
  void copyCurrentOpenglWindowToClipboard() {}

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    if(!_open()) return nullptr;
    int w = _it().wantW, h = _it().wantH;
    if(!_bind()) return nullptr;
    PixelBuffer *buffer = new PixelBuffer(w, h, format, type);
    buffer->fill();
    return buffer;
  }

  void sceneResize(int width, int height)
  {
    offscreen &it = _it();
    if(width < 4 || height < 4) return;
    if(width == it.wantW && height == it.wantH) return;
    it.wantW = width;
    it.wantH = height;
    _changed();
  }

  // RGB, the rows bottom up as glReadPixels() gives them, in a bitmap
  std::string scenePicture(int &width, int &height, bool always)
  {
    if(!_open()) return "";
    offscreen &it = _it();
    if(!always && !it.changed) return "";
    if(it.changed || it.picture.empty()) {
      it.changed = false;
      if(!it.fresh) _drawFrame();
      it.fresh = false;
      if(!_bind()) return "";
      it.pictureW = it.fbW;
      it.pictureH = it.fbH;
      it.picture.resize((std::size_t)4 * it.pictureW * it.pictureH);
      glFinish();
      glPixelStorei(GL_PACK_ALIGNMENT, 1);
      glReadPixels(0, 0, it.pictureW, it.pictureH, GL_RGBA, GL_UNSIGNED_BYTE,
                   &it.picture[0]);
    }
    width = it.pictureW;
    height = it.pictureH;
    int stride = (width * 3 + 3) & ~3;
    unsigned int bytes = 54 + (unsigned int)stride * height;
    std::string out(bytes, '\0');
    char *at = &out[0];
    auto put16 = [](char *where, unsigned int v) {
      where[0] = (char)(v & 0xff);
      where[1] = (char)((v >> 8) & 0xff);
    };
    auto put32 = [](char *where, unsigned int v) {
      for(int i = 0; i < 4; i++) where[i] = (char)((v >> (8 * i)) & 0xff);
    };
    at[0] = 'B';
    at[1] = 'M';
    put32(at + 2, bytes);
    put32(at + 10, 54);
    put32(at + 14, 40);
    put32(at + 18, (unsigned int)width);
    put32(at + 22, (unsigned int)height);
    put16(at + 26, 1);
    put16(at + 28, 24);
    put32(at + 34, bytes - 54);
    for(int y = 0; y < height; y++) {
      char *row = at + 54 + (std::size_t)stride * y;
      const unsigned char *from = &it.picture[(std::size_t)width * 4 * y];
      for(int x = 0; x < width; x++) {
        row[3 * x + 0] = (char)from[4 * x + 2];
        row[3 * x + 1] = (char)from[4 * x + 1];
        row[3 * x + 2] = (char)from[4 * x + 0];
      }
    }
    return out;
  }

  bool sceneMoved() { return _it().changed; }

  bool sceneKey(char key)
  {
    offscreen &it = _it();
    if(!_open() || !it.view || !it.view->key(key)) return false;
    _changed();
    return true;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    offscreen &it = _it();
    if(!_open() || !it.view) return;
    it.view->screenMessage[0] = first;
    it.view->screenMessage[1] = second;
    _changed();
  }

  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
    offscreen &it = _it();
    if(!_open() || !it.view) return;
    if(what == 4) {
      it.view->pointerLeft();
      _changed();
      return;
    }
    if(button < 0 || button > 2) button = 0;
    it.input.dx = it.everMoved ? x - it.lastX : 0.;
    it.input.dy = it.everMoved ? y - it.lastY : 0.;
    it.lastX = it.input.x = x;
    it.lastY = it.input.y = y;
    it.everMoved = true;
    it.input.shift = shift;
    it.input.ctrl = ctrl;
    it.input.alt = alt;
    switch(what) {
    case 1:
      it.input.clicked[button] = it.input.dragging[button] = true;
      break;
    case 2:
      it.input.released[button] = true;
      it.input.dragging[button] = false;
      break;
    case 3: it.input.wheel = wheel; break;
    default: break;
    }
    _handleInput();
    _changed();
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    width = std::min(width, _it().wantW);
    height = std::min(height, _it().wantH);
    _it().captureW = width;
    _it().captureH = height;
  }

  void endGraphicCapture()
  {
    _it().captureW = _it().captureH = 0;
    _changed();
  }

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    if(_open() && _it().view)
      viewSetOrientation(_it().view->getDrawContext(), what, reverse);
    _changed();
  }

  void setMouseSelection(bool on) {}
  void toggleAnimation() { _it().animating = !_it().animating; }
  bool animating() { return _it().animating; }

  char selectEntity(int type)
  {
    offscreen &it = _it();
    it.vertices.clear();
    it.edges.clear();
    it.faces.clear();
    it.regions.clear();
    it.elements.clear();
    it.points.clear();
    it.views.clear();
    if(!_open() || !it.view) return 'q';
    return it.view->selectEntity(type, it.vertices, it.edges, it.faces,
                                 it.regions, it.elements, it.points, it.views);
  }

  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    offscreen &it = _it();
    it.vertices.clear();
    it.edges.clear();
    it.faces.clear();
    it.regions.clear();
    it.elements.clear();
    it.points.clear();
    it.views.clear();
    if(!_open() || !it.view || !_bind()) return false;
    return it.view->pick(type, mesh, post, x, y, w, h, it.vertices, it.edges,
                         it.faces, it.regions, it.elements, it.points,
                         it.views);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!_open() || !_it().view || !_bind()) return false;
    bool ok = _it().view->printTo(width, height, supersampling, format, type,
                                  pixels);
    _changed();
    return ok;
  }

  void abortSelection()
  {
    if(!_open() || !_it().view) return;
    _it().view->quitSelection = 1;
    _it().view->selectionMode = false;
  }

  void setAddPointMode(bool on)
  {
    if(_open() && _it().view) _it().view->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(what == "background_image" && _open() && _it().view)
      _it().view->getDrawContext()->invalidateBgImageTexture();
    _changed();
  }

  const std::vector<GVertex *> &selectedVertices() { return _it().vertices; }
  const std::vector<GEdge *> &selectedEdges() { return _it().edges; }
  const std::vector<GFace *> &selectedFaces() { return _it().faces; }
  const std::vector<GRegion *> &selectedRegions() { return _it().regions; }
  const std::vector<MElement *> &selectedElements() { return _it().elements; }
  const std::vector<SPoint2> &selectedPoints() { return _it().points; }
  const std::vector<PView *> &selectedViews() { return _it().views; }

  // filled from the list in GuiSceneOps.h
  namespace {
    struct offering {
      offering()
      {
        GuiSceneOps ops;
#define GUI_SCENE_TAKE(name, args, call) ops.name = name;
        GUI_SCENE_VOID(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(ret, name, args, call, none) ops.name = name;
        GUI_SCENE_VALUE(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(type, name) ops.name = name;
        GUI_SCENE_LIST(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
        Gui::offerScene("tui", ops);
      }
    };
    offering _offering;
  } // namespace

} // namespace TuiScene

#endif
