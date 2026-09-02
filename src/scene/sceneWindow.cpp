// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE) && !defined(HAVE_GUI_SCENE)

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include <GLFW/glfw3.h>

#include "sceneView.h"
#include "sceneHost.h"
#include "drawContextGL.h"
#include "GuiScene.h"
#include "Context.h"
#include "Options.h"
#include "GmshDefines.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "OS.h"
#include "PixelBuffer.h"
#include "GuiScene.h"

// The 3D scene in a window of its own.
//
// It is what a chrome that does not hold a scene pairs with: a browser showing
// the panels of the interface over a socket, two interfaces teed together to
// be compared, anything being tried out. None of them knows about OpenGL, and
// none of them should have to draw a model before it can be looked at.
//
// It is the same sceneView the Dear ImGui interface puts in the panes of its
// dock space; only what holds it differs, which is the whole point of
// Scene::Host. What is here is the holding: a GLFW window, the events it
// reports, and the answers GuiScene.h asks for.
//
// The Dear ImGui context it makes holds no window at all. It is there for the
// font atlas the scene draws its text from -- the wooden leg written down in
// drawContextGL.h.

namespace {

  struct standalone {
    GLFWwindow *window = nullptr;
    ImGuiContext *fonts = nullptr;
    sceneView *view = nullptr;
    paneInput input;
    double lastX = 0., lastY = 0., lastPress = 0.;
    bool everMoved = false;
    bool tried = false;
    // someone else is showing the scene, from pictures of it: the window is
    // made all the same, since a picture has to be drawn somewhere, but it is
    // never put on the screen
    bool elsewhere = false;
    // How big the picture is wanted. A window nobody looks at cannot be
    // relied on to change size -- there is no compositor to ask -- so the
    // picture is drawn at the wanted size inside a window made large enough,
    // rather than by resizing the window.
    int wantW = 0, wantH = 0;
    // what is being picked, said over the view
    std::string tooltip;
    // and what the last picking answered
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

  // GLFW numbers the buttons left, right, middle, and so does paneInput
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

  void _mouseButton(GLFWwindow *, int button, int action, int mods)
  {
    standalone &it = _it();
    int b = _button(button);
    if(b < 0) return;
    _modifiers(it.input, mods);
    if(action == GLFW_PRESS) {
      it.input.clicked[b] = true;
      it.input.dragging[b] = true;
      // GLFW does not report double clicks, so they are timed here
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
    // the keys an interactive selection answers to, as in the interfaces that
    // hold the scene themselves
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

  // Bring it up, once. Failing is not fatal: a chrome that has no scene is
  // still a chrome, and it says so and carries on.
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
      // room for whatever size the picture is asked at, since the window
      // itself will not be resized
      wide = 2048;
      high = 1536;
    }
    it.window = glfwCreateWindow(wide, high, "Gmsh", nullptr, nullptr);
    if(!it.window) {
      Msg::Warning("Could not open a window: the model will not be shown");
      return false;
    }
    glfwMakeContextCurrent(it.window);
    glfwSwapInterval(1);

    // no window of its own is ever drawn in it: it is here for the atlas the
    // text of the scene comes from
    IMGUI_CHECKVERSION();
    it.fonts = ImGui::CreateContext();
    ImGui::SetCurrentContext(it.fonts);
    ImGui::GetIO().IniFilename = nullptr;
    ImGui_ImplOpenGL2_Init();

    it.view = new sceneView();
    if(!drawContext::global() ||
       drawContext::global()->getName() != "ImGui")
      drawContext::setGlobal(new drawContextGL);

    glfwSetCursorPosCallback(it.window, _cursorPos);
    glfwSetMouseButtonCallback(it.window, _mouseButton);
    glfwSetScrollCallback(it.window, _scroll);
    glfwSetKeyCallback(it.window, _key);

    // and what the scene needs of whoever holds it, which here is this file
    Scene::Host held;
    held.redraw = []() {};
    // A picking waits here, so this is what keeps the interface answering
    // while it does: the chrome is pumped, not the scene -- pumping the scene
    // would be pumping the loop one is already inside.
    held.check = [](bool rateLimited) { Gui::pumpChrome(rateLimited); };
    held.wait = [](double seconds, bool force) { Gui::pumpChrome(false); };
    // what a capture asks for: the scene drawn, and the buffers left alone,
    // since glReadPixels() reads the one a swap would have thrown away
    held.drawCurrent = []() { _drawFrame(false); };
    held.uiScale = []() { return 1.f; };
    held.numViews = []() { return 1; };
    held.tooltip = [](const std::string &text) { _it().tooltip = text; };
    held.current = []() { return _it().view; };
    held.setCurrent = [](sceneView *) {};
    Scene::setHost(held);
    return true;
  }

  // One frame: the size the window is, what the pointer did, and the scene.
  void _drawFrame(bool swap)
  {
    standalone &it = _it();
    if(!it.window || !it.view) return;
    glfwMakeContextCurrent(it.window);
    ImGui::SetCurrentContext(it.fonts);

    int ww = 0, wh = 0, fw = 0, fh = 0;
    glfwGetWindowSize(it.window, &ww, &wh);
    glfwGetFramebufferSize(it.window, &fw, &fh);
    if(ww <= 0 || wh <= 0) return;
    double f = (double)fw / (double)ww;
    // the picture is drawn at the size that was asked for, in the corner of a
    // window that is at least that big
    if(it.wantW > 0 && it.wantH > 0) {
      ww = it.wantW < ww ? it.wantW : ww;
      wh = it.wantH < wh ? it.wantH : wh;
    }

    // the atlas is dynamic: a frame has to be open for a glyph to be added
    ImGuiIO &io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)ww, (float)wh);
    io.DeltaTime = 1.f / 60.f;
    ImGui_ImplOpenGL2_NewFrame();
    ImGui::NewFrame();

    it.view->setRect(0, 0, ww, wh);
    it.view->setOrigin(0., 0., wh, f);
    it.view->handleMouse(it.input);
    // the events are one-shot: what has been acted on must not be seen again
    for(int b = 0; b < 3; b++)
      it.input.clicked[b] = it.input.released[b] = false;
    it.input.doubleClicked = false;
    it.input.wheel = 0.;
    it.input.dx = it.input.dy = 0.;

    it.view->draw(f, wh);

    ImGui::EndFrame();
    // a window nobody looks at is never swapped: what a picture is read from
    // is the buffer a swap would have thrown away
    if(swap && !it.elsewhere) glfwSwapBuffers(it.window);
  }

} // namespace

namespace Gui {

  void sceneShownElsewhere() { _it().elsewhere = true; }

  void pumpScene(bool rateLimited)
  {
    // nothing to pump when the scene is drawn into pictures: it is drawn when
    // one is asked for
    if(_it().elsewhere) return;
    if(!_open()) return;
    standalone &it = _it();
    if(glfwWindowShouldClose(it.window)) {
      // the window is gone; the chrome carries on without a scene
      glfwHideWindow(it.window);
      return;
    }
    glfwPollEvents();
    _drawFrame();
  }

  // --- what the scene answers, held in a window of its own

  drawContext *getCurrentDrawContext()
  {
    return _it().view ? _it().view->getDrawContext() : nullptr;
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    standalone &it = _it();
    if(!it.window) return;
    glfwGetFramebufferSize(it.window, &width, &height);
    // what is drawn is the size that was asked for, not the whole of a window
    // nobody looks at
    if(it.wantW > 0 && it.wantH > 0) {
      int ww = 0, wh = 0, fw = 0, fh = 0;
      glfwGetWindowSize(it.window, &ww, &wh);
      glfwGetFramebufferSize(it.window, &fw, &fh);
      double f = ww > 0 ? (double)fw / (double)ww : 1.;
      int wide = (int)(it.wantW * f), high = (int)(it.wantH * f);
      if(wide < width) width = wide;
      if(high < height) height = high;
    }
  }

  void setCurrentOpenglWindow(int which) {}

  // one window: there is nothing another could be hiding
  void showAllInEveryWindow() {}

  // one window, which is not split
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
    // it draws the scene itself, twice, and reads what it drew
    buffer->fill(0);
    return buffer;
  }

  // --- and the same picture, for a chrome that cannot draw one

  void sceneResize(int width, int height)
  {
    standalone &it = _it();
    if(width < 16 || height < 16) return;
    it.wantW = width;
    it.wantH = height;
    // a window one can see follows; one nobody looks at is left as it is and
    // the picture is drawn in a corner of it
    if(it.window && !it.elsewhere) glfwSetWindowSize(it.window, width, height);
  }

  // A bitmap, which needs nothing to write and nothing to read: the rows go
  // bottom up, which is the order glReadPixels() gives them in, so there is
  // nothing to turn over either. It is bigger on the wire than a PNG would be
  // and this is a local connection.
  std::string scenePicture(int &width, int &height)
  {
    if(!_open()) return "";
    PixelBuffer *shot = Gui::createCompositePixelBuffer(GL_RGB,
                                                        GL_UNSIGNED_BYTE);
    if(!shot) return "";
    width = shot->getWidth();
    height = shot->getHeight();
    const unsigned char *pixels = (const unsigned char *)shot->getPixels();
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
      const unsigned char *from = pixels + (std::size_t)width * 3 * y;
      for(int x = 0; x < width; x++) {
        // a bitmap says blue, green, red
        row[3 * x + 0] = (char)from[3 * x + 2];
        row[3 * x + 1] = (char)from[3 * x + 1];
        row[3 * x + 2] = (char)from[3 * x + 0];
      }
    }
    delete shot;
    return out;
  }

  void sceneKey(char key)
  {
    standalone &it = _it();
    if(!it.view || !it.view->selectionMode) return;
    switch(key) {
    case 'e': it.view->endSelection = 1; break;
    case 'u': it.view->undoSelection = 1; break;
    case 'i': it.view->invertSelection = 1; break;
    case 'q': it.view->quitSelection = 1; break;
    default: break;
    }
  }

  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
    standalone &it = _it();
    if(!_open() || !it.view) return;
    if(button < 0 || button > 2) button = 0;
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
    if(_it().view) viewSetOrientation(_it().view->getDrawContext(), what,
                                      reverse);
    pumpScene(false);
  }

  void setMouseSelection(bool on)
  {
    double v = on ? 1. : 0.;
    NumberOption(GMSH_SET | GMSH_GUI, "General", 0, "MouseSelection", v, false);
  }

  // one window that shows what it is told to: nothing plays here
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

  void abortSelection()
  {
    if(!_it().view) return;
    _it().view->quitSelection = 1;
    _it().view->selectionMode = false;
  }

  void setAddPointMode(bool on)
  {
    if(_it().view) _it().view->addPointMode = on;
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

} // namespace Gui

#endif
