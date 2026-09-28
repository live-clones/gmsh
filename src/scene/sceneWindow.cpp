// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE) && defined(HAVE_GLFW)

#include <string>
#include <vector>

#include <GLFW/glfw3.h>

// GLFW 3.3, that of Emscripten, names the hand after itself
#if !defined(GLFW_POINTING_HAND_CURSOR)
#define GLFW_POINTING_HAND_CURSOR GLFW_HAND_CURSOR
#endif

#include "sceneView.h"
#include "sceneHost.h"
#include "drawContextGL.h"
#include "GuiScene.h"
#include "Gui.h"
#include "Context.h"
#include "Options.h"
#include "GmshDefines.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "OS.h"
#include "PixelBuffer.h"
#include "glShader.h"

// The scene in a window of its own, for an interface that holds none: the
// same sceneView, held by a GLFW window -- compiled to WebAssembly, a canvas
// of the page.

namespace {

  struct standalone {
    GLFWwindow *window = nullptr;
    sceneView *view = nullptr;
    paneInput input;
    double lastX = 0., lastY = 0., lastPress = 0.;
    bool everMoved = false;
    bool tried = false;
    // someone else shows the scene from pictures: the window is made, since a
    // picture has to be drawn somewhere, but never put on the screen
    bool elsewhere = false;
    // reading a framebuffer back and making a bitmap of it is by far the most
    // expensive thing here
    bool changed = true;
    // whether the timer or the highlight asked for a frame, which the pump
    // draws; and whether the window holds a frame newer than the picture
    bool frameWanted = false, fresh = false;
    std::vector<unsigned char> picture;
    int pictureW = 0, pictureH = 0;
    // a window nobody looks at cannot be relied on to change size: the picture
    // is drawn at the wanted size in the corner of a window made large enough
    int wantW = 0, wantH = 0;
    // the hand, put on the window while the pointer is over something clickable
    GLFWcursor *hand = nullptr;
    bool handOn = false;
    std::vector<GVertex *> vertices;
    std::vector<GEdge *> edges;
    std::vector<GFace *> faces;
    std::vector<GRegion *> regions;
    std::vector<MElement *> elements;
    std::vector<SPoint2> points;
    std::vector<PView *> views;
  };

  standalone &_it()
  {
    static standalone it;
    return it;
  }

  void _modifiers(paneInput &in, int mods)
  {
    in.shift = (mods & GLFW_MOD_SHIFT) != 0;
    in.ctrl = (mods & GLFW_MOD_CONTROL) != 0;
    in.alt = (mods & GLFW_MOD_ALT) != 0;
    in.super = (mods & GLFW_MOD_SUPER) != 0;
  }

  int _button(int glfwButton)
  {
    switch(glfwButton) {
    case GLFW_MOUSE_BUTTON_LEFT: return 0;
    case GLFW_MOUSE_BUTTON_RIGHT: return 1;
    case GLFW_MOUSE_BUTTON_MIDDLE: return 2;
    default: return -1;
    }
  }

  void _cursorPos(GLFWwindow *, double x, double y)
  {
    standalone &it = _it();
    it.input.dx = it.everMoved ? x - it.lastX : 0.;
    it.input.dy = it.everMoved ? y - it.lastY : 0.;
    it.lastX = x;
    it.lastY = y;
    it.everMoved = true;
    it.input.x = x;
    it.input.y = y;
  }

  void _cursorEnter(GLFWwindow *, int entered)
  {
    standalone &it = _it();
    if(!entered && it.view) it.view->pointerLeft();
  }

  void _mouseButton(GLFWwindow *, int button, int action, int mods)
  {
    standalone &it = _it();
    int b = _button(button);
    if(b < 0) return;
    _modifiers(it.input, mods);
    if(action == GLFW_PRESS) {
      it.input.clicked[b] = true;
      it.input.dragging[b] = true;
      double now = TimeOfDay();
      it.input.doubleClicked = (b == 0 && now - it.lastPress < 0.25);
      it.lastPress = now;
    }
    else {
      it.input.released[b] = true;
      it.input.dragging[b] = false;
    }
  }

  void _scroll(GLFWwindow *, double, double dy) { _it().input.wheel = dy; }

  void _key(GLFWwindow *, int key, int, int action, int mods)
  {
    standalone &it = _it();
    if(action != GLFW_PRESS || !it.view) return;
    _modifiers(it.input, mods);
    if((mods & GLFW_MOD_ALT) && (key == GLFW_KEY_UP || key == GLFW_KEY_DOWN) &&
       CTX::instance()->mouseSelection && !it.view->lasso() &&
       !it.view->addPointMode) {
      it.view->stepPick(key == GLFW_KEY_DOWN ? 1 : -1);
      return;
    }
    if(!it.view->selectionMode) return;
    switch(key) {
    case GLFW_KEY_E: it.view->endSelection = 1; break;
    case GLFW_KEY_U: it.view->undoSelection = 1; break;
    case GLFW_KEY_I:
    case GLFW_KEY_MINUS: it.view->invertSelection = 1; break;
    case GLFW_KEY_Q:
    case GLFW_KEY_ESCAPE: it.view->quitSelection = 1; break;
    default: break;
    }
  }

  void _drawFrame(bool swap = true);
  void _changed();

  // what is asked beyond the window is drawn smaller, both sides by the same
  // amount, and the pointer brought back through the same number
  double _drawnSize(int &w, int &h)
  {
    standalone &it = _it();
    int ww = 0, wh = 0;
    glfwGetWindowSize(it.window, &ww, &wh);
    if(ww <= 0 || wh <= 0) { w = h = 0; return 1.; }
    w = it.wantW > 0 ? it.wantW : ww;
    h = it.wantH > 0 ? it.wantH : wh;
    double k = 1.;
    if(w > ww) k = ww / (double)w;
    if(h > wh && wh / (double)h < k) k = wh / (double)h;
    w = (int)(w * k);
    h = (int)(h * k);
    if(w < 1) w = 1;
    if(h < 1) h = 1;
    return k;
  }

  // failing is not fatal: the interface carries on without a scene
  bool _open()
  {
    standalone &it = _it();
    if(it.window) return true;
    if(it.tried) return false;
    it.tried = true;

    if(!glfwInit()) {
      Msg::Warning("Could not start GLFW: the model will not be shown");
      return false;
    }
    glfwDefaultWindowHints();
    int wide = CTX::instance()->glSize[0] > 0 ? CTX::instance()->glSize[0] : 800;
    int high = CTX::instance()->glSize[1] > 0 ? CTX::instance()->glSize[1] : 600;
    if(it.elsewhere) {
      glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
      // as big as the screen, up to what is reasonable to read back
      wide = 2048;
      high = 1536;
      GLFWmonitor *screen = glfwGetPrimaryMonitor();
      const GLFWvidmode *mode = screen ? glfwGetVideoMode(screen) : nullptr;
      if(mode) {
        if(mode->width > wide) wide = mode->width;
        if(mode->height > high) high = mode->height;
      }
      if(wide > 4096) wide = 4096;
      if(high > 3072) high = 3072;
    }
    it.window = glfwCreateWindow(wide, high, "Gmsh", nullptr, nullptr);
    if(!it.window) {
      Msg::Warning("Could not open a window: the model will not be shown");
      return false;
    }
    glfwMakeContextCurrent(it.window);
    glfwSwapInterval(1);

    it.view = new sceneView();
    it.view->contextChanged();
    if(!dynamic_cast<drawContextGL *>(drawContext::global()))
      drawContext::setGlobal(new drawContextGL);

    glfwSetCursorPosCallback(it.window, _cursorPos);
    glfwSetCursorEnterCallback(it.window, _cursorEnter);
    glfwSetMouseButtonCallback(it.window, _mouseButton);
    glfwSetScrollCallback(it.window, _scroll);
    glfwSetKeyCallback(it.window, _key);

    Scene::Host held;
    held.redraw = []() { _changed(); };
    held.redrawView = [](sceneView *) { _it().frameWanted = true; };
    // the interface is pumped, not the scene, which would be pumping the loop
    // one is inside
    held.check = [](bool rateLimited) { Gui::instance().pumpChrome(rateLimited); };
    held.wait = [](double seconds, bool force) { Gui::instance().pumpChrome(false); };
    // the buffers left alone: glReadPixels() reads the one a swap would throw
    // away
    held.drawCurrent = []() { _drawFrame(false); };
    held.uiScale = []() { return 1.f; };
    held.numViews = []() { return 1; };
    held.cursor = [](Scene::Cursor kind) {
      standalone &one = _it();
      if(!one.window) return;
      bool want = (kind == Scene::Picking);
      if(want == one.handOn) return;
      if(want && !one.hand)
        one.hand = glfwCreateStandardCursor(GLFW_POINTING_HAND_CURSOR);
      glfwSetCursor(one.window, want ? one.hand : nullptr);
      one.handOn = want;
    };
    held.current = []() { return _it().view; };
    held.setCurrent = [](sceneView *) {};
    held.later = Scene::later;
    held.buttonDown = []() {
      GLFWwindow *w = _it().window;
      if(!w) return false;
      for(int b = 0; b < 3; b++)
        if(glfwGetMouseButton(w, b) == GLFW_PRESS) return true;
      return false;
    };
    held.context = []() -> void * { return _it().window; };
    held.makeCurrent = [](sceneView *) {
      if(_it().window) glfwMakeContextCurrent(_it().window);
    };
    Scene::setHost(held);
    return true;
  }

  void _changed()
  {
    _it().changed = true;
    _it().fresh = false;
  }

  // the picture is drawn at the size asked for, in the corner of a window at
  // least that big
  bool _frameSize(int &ww, int &wh, double &f)
  {
    standalone &it = _it();
    int fw = 0, fh = 0;
    glfwGetWindowSize(it.window, &ww, &wh);
    glfwGetFramebufferSize(it.window, &fw, &fh);
    if(ww <= 0 || wh <= 0) return false;
    f = (double)fw / (double)ww;
    _drawnSize(ww, wh);
    return ww > 0 && wh > 0;
  }

  void _handleInput()
  {
    standalone &it = _it();
    if(!it.window || !it.view) return;
    glfwMakeContextCurrent(it.window);
    int ww = 0, wh = 0;
    double f = 1.;
    if(!_frameSize(ww, wh, f)) return;
    it.view->setRect(0, 0, ww, wh);
    it.view->setOrigin(0., 0., wh, f);
    it.view->handleMouse(it.input);
    for(int b = 0; b < 3; b++)
      it.input.clicked[b] = it.input.released[b] = false;
    it.input.doubleClicked = false;
    it.input.wheel = 0.;
    it.input.dx = it.input.dy = 0.;
  }

  void _drawFrame(bool swap)
  {
    standalone &it = _it();
    if(!it.window || !it.view) return;
    _handleInput();
    int ww = 0, wh = 0;
    double f = 1.;
    if(!_frameSize(ww, wh, f)) return;

    it.view->draw(f, wh);
    glShader::release();

    // never swapped: the picture is read from the buffer a swap would throw
    // away
    if(swap && !it.elsewhere) glfwSwapBuffers(it.window);
  }

} // namespace

namespace WindowScene {

  void sceneShownElsewhere() { _it().elsewhere = true; }

  void pumpScene(bool rateLimited)
  {
    // the studio frames the timers ask for are drawn here, into the window
    // nobody sees, and a picture sent only once they are all in
    if(_it().elsewhere) {
      standalone &it = _it();
      if(!it.window) return;
      Scene::fireTimers();
      if(it.frameWanted) {
        it.frameWanted = false;
        _drawFrame(false);
        it.fresh = true;
        if(!it.view->accumulating()) it.changed = true;
      }
      return;
    }
    if(!_open()) return;
    standalone &it = _it();
    if(glfwWindowShouldClose(it.window)) {
      glfwHideWindow(it.window);
      return;
    }
    glfwPollEvents();
    Scene::fireTimers();
    _drawFrame();
  }

  // --- what the scene answers, held in a window of its own

  drawContext *getCurrentDrawContext()
  {
    // a mode set on a scene that does not exist yet would be lost
    if(!_open()) return nullptr;
    return _it().view ? _it().view->getDrawContext() : nullptr;
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    standalone &it = _it();
    if(!it.window) return;
    int ww = 0, wh = 0, fw = 0, fh = 0;
    glfwGetWindowSize(it.window, &ww, &wh);
    glfwGetFramebufferSize(it.window, &fw, &fh);
    double f = ww > 0 ? (double)fw / (double)ww : 1.;
    int wide = 0, high = 0;
    _drawnSize(wide, high);
    width = (int)(wide * f);
    height = (int)(high * f);
  }

  void setCurrentOpenglWindow(int which) {}

  void showAllInEveryWindow() {}

  void splitCurrentOpenglWindow(char how, double ratio) {}

  void copyCurrentOpenglWindowToClipboard() {}

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(w <= 0 || h <= 0) return nullptr;
    if(_it().window) glfwMakeContextCurrent(_it().window);
    PixelBuffer *buffer = new PixelBuffer(w, h, format, type);
    buffer->fill();
    return buffer;
  }

  // --- and the same picture, for an interface that cannot draw one

  void sceneResize(int width, int height)
  {
    standalone &it = _it();
    if(width < 16 || height < 16) return;
    if(width == it.wantW && height == it.wantH) return;
    it.wantW = width;
    it.wantH = height;
    _changed();
    // a window nobody looks at is left as it is
    if(it.window && !it.elsewhere) glfwSetWindowSize(it.window, width, height);
    // a pointer arriving before the first frame of a new size would be answered
    // with the matrices of the old one
    if(it.window && it.elsewhere) _drawFrame(false);
  }

  // a bitmap: the rows go bottom up, as glReadPixels() gives them; bigger than
  // a PNG on a local connection
  std::string scenePicture(int &width, int &height, bool always)
  {
    if(!_open()) return "";
    standalone &it = _it();
    if(!always && !it.changed) return "";
    // a frame nobody asked for starts the studio accumulation over
    if(it.changed || it.picture.empty()) {
      it.changed = false;
      if(!it.fresh) _drawFrame(false);
      it.fresh = false;
      getCurrentPixelSize(it.pictureW, it.pictureH);
      if(it.pictureW < 1 || it.pictureH < 1) return "";
      glfwMakeContextCurrent(it.window);
      // RGBA: the one format every implementation reads back, WebGL included
      it.picture.resize((std::size_t)4 * it.pictureW * it.pictureH);
      glFinish();
      glPixelStorei(GL_PACK_ALIGNMENT, 1);
      glReadPixels(0, 0, it.pictureW, it.pictureH, GL_RGBA, GL_UNSIGNED_BYTE,
                   &it.picture[0]);
    }
    width = it.pictureW;
    height = it.pictureH;
    const unsigned char *pixels = &it.picture[0];
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
      const unsigned char *from = pixels + (std::size_t)width * 4 * y;
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
    standalone &it = _it();
    if(!_open() || !it.view) return false;
    if(!it.view->key(key)) return false;
    _changed();
    return true;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    standalone &it = _it();
    if(!_open() || !it.view) return;
    _changed();
    it.view->screenMessage[0] = first;
    it.view->screenMessage[1] = second;
  }

  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
    standalone &it = _it();
    if(!_open() || !it.view) return;
    if(what == 4) {
      it.view->pointerLeft();
      return;
    }
    if(button < 0 || button > 2) button = 0;
    // the pointer comes in the picture as it was asked for; the scene works in
    // the picture as it could be drawn
    {
      int wide = 0, high = 0;
      double k = _drawnSize(wide, high);
      if(k != 1.) { x *= k; y *= k; }
    }
    it.input.dx = it.everMoved ? x - it.lastX : 0.;
    it.input.dy = it.everMoved ? y - it.lastY : 0.;
    it.lastX = x;
    it.lastY = y;
    it.everMoved = true;
    it.input.x = x;
    it.input.y = y;
    it.input.shift = shift;
    it.input.ctrl = ctrl;
    it.input.alt = alt;
    switch(what) {
    case 1:
      it.input.clicked[button] = true;
      it.input.dragging[button] = true;
      break;
    case 2:
      it.input.released[button] = true;
      it.input.dragging[button] = false;
      break;
    case 3: it.input.wheel = wheel; break;
    default: break;
    }
    // a move is the view's to answer: a frame drawn for it would start the
    // studio accumulation over
    if(it.elsewhere) {
      _handleInput();
      if(what != 0) _changed();
    }
    else
      _drawFrame();
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(w > 0 && w < width) width = w;
    if(h > 0 && h < height) height = h;
  }

  void endGraphicCapture() {}

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    if(_open() && _it().view) viewSetOrientation(_it().view->getDrawContext(), what,
                                      reverse);
    pumpScene(false);
  }

  void setMouseSelection(bool on) {}

  void toggleAnimation() {}
  bool animating() { return false; }

  char selectEntity(int type)
  {
    standalone &it = _it();
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
    standalone &it = _it();
    it.vertices.clear();
    it.edges.clear();
    it.faces.clear();
    it.regions.clear();
    it.elements.clear();
    it.points.clear();
    it.views.clear();
    if(!_open() || !it.view) return false;
    return it.view->pick(type, mesh, post, x, y, w, h, it.vertices, it.edges,
                         it.faces, it.regions, it.elements, it.points,
                         it.views);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!_open() || !_it().view) return false;
    return _it().view->printTo(width, height, supersampling, format, type,
                               pixels);
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
    if(what == "background_image" && _open() && _it().view &&
       _it().view->getDrawContext())
      _it().view->getDrawContext()->invalidateBgImageTexture();
  }

  const std::vector<GVertex *> &selectedVertices()
  {
    return _it().vertices;
  }

  const std::vector<GEdge *> &selectedEdges()
  {
    return _it().edges;
  }

  const std::vector<GFace *> &selectedFaces()
  {
    return _it().faces;
  }

  const std::vector<GRegion *> &selectedRegions()
  {
    return _it().regions;
  }

  const std::vector<MElement *> &selectedElements()
  {
    return _it().elements;
  }

  const std::vector<SPoint2> &selectedPoints()
  {
    return _it().points;
  }

  const std::vector<PView *> &selectedViews()
  {
    return _it().views;
  }


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
      Gui::offerScene("*", ops);
    }
  };
  offering _offering;
}
} // namespace WindowScene


#endif
