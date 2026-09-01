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

  void _drawFrame();

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
    it.window = glfwCreateWindow(CTX::instance()->glSize[0] > 0 ?
                                   CTX::instance()->glSize[0] : 800,
                                 CTX::instance()->glSize[1] > 0 ?
                                   CTX::instance()->glSize[1] : 600,
                                 "Gmsh", nullptr, nullptr);
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
    held.check = [](bool rateLimited) { Gui::pumpScene(rateLimited); };
    held.wait = [](double seconds, bool force) { Gui::pumpScene(false); };
    held.drawCurrent = []() { _drawFrame(); };
    held.uiScale = []() { return 1.f; };
    held.numViews = []() { return 1; };
    held.tooltip = [](const std::string &text) { _it().tooltip = text; };
    held.current = []() { return _it().view; };
    held.setCurrent = [](sceneView *) {};
    Scene::setHost(held);
    return true;
  }

  // One frame: the size the window is, what the pointer did, and the scene.
  void _drawFrame()
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
    glfwSwapBuffers(it.window);
  }

} // namespace

namespace Gui {

  void pumpScene(bool rateLimited)
  {
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
    if(!_it().window) return;
    glfwGetFramebufferSize(_it().window, &width, &height);
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
    PixelBuffer *buffer = new PixelBuffer(w, h, format, type);
    buffer->fill(0);
    return buffer;
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
