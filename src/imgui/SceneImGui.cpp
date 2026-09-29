// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Dear ImGui interface, see GuiPanes.h: the views tiled in
// the central node of the dock space, each drawn into a framebuffer of its
// own and put on the window as a texture; a new graphic window a GLFW window
// of its own, sharing the context of the main one, with no Dear ImGui in it --
// which is what works on Wayland, where Dear ImGui cannot place a viewport

#include "GmshConfig.h"

#include <algorithm>
#include <cfloat>
#include <cstdio>
#include <string>
#include <vector>

#include "imgui.h"
#include <GLFW/glfw3.h>

#include "appWindow.h"
#include "uiSources.h"
#include "GuiPanes.h"
#include "glfwScreen.h"
#include "sceneHost.h"
#include "glApi.h"
#include "glShader.h"
#include "GmshMessage.h"

namespace {

  // the framebuffer a view is drawn into: the texture shown, and the
  // multisampled buffer drawn into when there is antialiasing, resolved into
  // the texture
  struct target {
    unsigned int fbo = 0, colour = 0, depth = 0;
    unsigned int msFbo = 0, msColour = 0, msDepth = 0;
    int w = 0, h = 0, samples = 0;
  };

  struct pane : public GuiPanes::Pane {
    target t;
    // asked for since it was last drawn
    bool wanted = true;
    // where it is in the main window, in its logical pixels from the top left;
    // nothing while another fills the window
    int x = 0, y = 0, w = 0, h = 0;
    // the window of a graphic window of its own
    GLFWwindow *glfw = nullptr;
  };

  // how the tiled panes share the room
  struct node {
    pane *leaf = nullptr;
    char split = 0; // 'h' side by side, 'v' one above the other
    double ratio = .5;
    node *child[2] = {nullptr, nullptr};
  };

  GLFWwindow *_main = nullptr;
  node *_root = nullptr;
  // the pane a button went down in has the pointer until they are all up;
  // the one it was over last forgets it when it leaves
  pane *_grab = nullptr, *_over = nullptr;
  bool _picking = false;

  GuiPanes &_all() { return GuiPanes::instance(); }

  pane *_pane(GuiPanes::Pane *p) { return static_cast<pane *>(p); }

  node *_nodeOf(node *n, pane *p)
  {
    if(!n) return nullptr;
    if(n->leaf == p) return n;
    if(node *m = _nodeOf(n->child[0], p)) return m;
    return _nodeOf(n->child[1], p);
  }

  void _deleteNodes(node *n)
  {
    if(!n) return;
    _deleteNodes(n->child[0]);
    _deleteNodes(n->child[1]);
    delete n;
  }

  void _layout(node *n, int x, int y, int w, int h)
  {
    if(!n) return;
    if(n->leaf) {
      n->leaf->x = x;
      n->leaf->y = y;
      n->leaf->w = w;
      n->leaf->h = h;
      return;
    }
    double f = std::min(.99, std::max(.01, n->ratio));
    if(n->split == 'h') {
      int w1 = (int)(w * f);
      _layout(n->child[0], x, y, w1, h);
      _layout(n->child[1], x + w1, y, w - w1, h);
    }
    else {
      int h1 = (int)(h * f);
      _layout(n->child[0], x, y, w, h1);
      _layout(n->child[1], x, y + h1, w, h - h1);
    }
  }

  double _mainFactor()
  {
    int ww = 0, wh = 0, fw = 0, fh = 0;
    glfwGetWindowSize(_main, &ww, &wh);
    glfwGetFramebufferSize(_main, &fw, &fh);
    return (ww > 0) ? (double)fw / (double)ww : 1.;
  }

  // imgui_impl_opengl2 does not push GL_TEXTURE_BIT: the atlas stays bound
  // and the environment set to GL_MODULATE
  void _plainState()
  {
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_BLEND);
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_POLYGON_STIPPLE);
    glShadeModel(GL_SMOOTH);
    glColor4f(1.f, 1.f, 1.f, 1.f);
    glLineWidth(1.f);
    glPointSize(1.f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }

  void _unbind()
  {
    if(glApi::BindFramebuffer) glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
    glShader::setWindowFramebuffer(0);
  }

  // --- the framebuffer of a view

  void _drop(target &t)
  {
    if(t.fbo && glApi::DeleteFramebuffers) glApi::DeleteFramebuffers(1, &t.fbo);
    if(t.msFbo && glApi::DeleteFramebuffers)
      glApi::DeleteFramebuffers(1, &t.msFbo);
    if(t.colour) glDeleteTextures(1, &t.colour);
    if(glApi::DeleteRenderbuffers) {
      if(t.depth) glApi::DeleteRenderbuffers(1, &t.depth);
      if(t.msColour) glApi::DeleteRenderbuffers(1, &t.msColour);
      if(t.msDepth) glApi::DeleteRenderbuffers(1, &t.msDepth);
    }
    t = target();
  }

  // made or remade at that size in pixels, and bound as the window of the
  // scene; false when it cannot be
  bool _bind(target &t, int w, int h)
  {
    if(w < 1 || h < 1 || !glApi::GenFramebuffers || !glApi::BindFramebuffer ||
       !glApi::GenRenderbuffers || !glApi::RenderbufferStorage)
      return false;
    // what the window had through GLFW_SAMPLES, the framebuffer has
    int samples = (imguiSources().settings().antialiasing &&
                   glApi::RenderbufferStorageMultisample &&
                   glApi::BlitFramebuffer) ?
                    4 :
                    0;
    if(t.fbo && (t.w != w || t.h != h || t.samples != samples)) _drop(t);
    if(!t.fbo) {
      glGenTextures(1, &t.colour);
      glBindTexture(GL_TEXTURE_2D, t.colour);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, nullptr);
      glBindTexture(GL_TEXTURE_2D, 0);
      glApi::GenRenderbuffers(1, &t.depth);
      glApi::BindRenderbuffer(GL_RENDERBUFFER, t.depth);
      glApi::RenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, w, h);
      glApi::GenFramebuffers(1, &t.fbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, t.fbo);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                  GL_TEXTURE_2D, t.colour, 0);
      glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                                     GL_RENDERBUFFER, t.depth);
      bool ok = glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) ==
                GL_FRAMEBUFFER_COMPLETE;
      if(ok && samples) {
        glApi::GenRenderbuffers(1, &t.msColour);
        glApi::BindRenderbuffer(GL_RENDERBUFFER, t.msColour);
        glApi::RenderbufferStorageMultisample(GL_RENDERBUFFER, samples,
                                              GL_RGBA8, w, h);
        glApi::GenRenderbuffers(1, &t.msDepth);
        glApi::BindRenderbuffer(GL_RENDERBUFFER, t.msDepth);
        glApi::RenderbufferStorageMultisample(GL_RENDERBUFFER, samples,
                                              GL_DEPTH24_STENCIL8, w, h);
        glApi::GenFramebuffers(1, &t.msFbo);
        glApi::BindFramebuffer(GL_FRAMEBUFFER, t.msFbo);
        glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                       GL_RENDERBUFFER, t.msColour);
        glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER,
                                       GL_DEPTH_STENCIL_ATTACHMENT,
                                       GL_RENDERBUFFER, t.msDepth);
        // no multisampling rather than no picture
        if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
           GL_FRAMEBUFFER_COMPLETE) {
          glApi::DeleteFramebuffers(1, &t.msFbo);
          glApi::DeleteRenderbuffers(1, &t.msColour);
          glApi::DeleteRenderbuffers(1, &t.msDepth);
          t.msFbo = t.msColour = t.msDepth = 0;
          samples = 0;
        }
      }
      glApi::BindRenderbuffer(GL_RENDERBUFFER, 0);
      if(!ok) {
        glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
        _drop(t);
        return false;
      }
      t.w = w;
      t.h = h;
      t.samples = samples;
    }
    unsigned int into = t.msFbo ? t.msFbo : t.fbo;
    glApi::BindFramebuffer(GL_FRAMEBUFFER, into);
    glShader::setWindowFramebuffer(into);
    return true;
  }

  void _resolve(target &t)
  {
    if(!t.msFbo) return;
    glApi::BindFramebuffer(GL_READ_FRAMEBUFFER, t.msFbo);
    glApi::BindFramebuffer(GL_DRAW_FRAMEBUFFER, t.fbo);
    glApi::BlitFramebuffer(0, 0, t.w, t.h, 0, 0, t.w, t.h, GL_COLOR_BUFFER_BIT,
                           GL_NEAREST);
    glApi::BindFramebuffer(GL_FRAMEBUFFER, t.fbo);
  }

  // the texture of a view where the view is on the main window
  void _show(pane *p)
  {
    if(!p->t.colour) return;
    int fw = 0, fh = 0, ww = 0, wh = 0;
    glfwGetFramebufferSize(_main, &fw, &fh);
    glfwGetWindowSize(_main, &ww, &wh);
    double f = _mainFactor();
    float x0 = (float)(p->x * f), x1 = (float)((p->x + p->w) * f);
    float y0 = (float)((wh - p->y - p->h) * f), y1 = (float)((wh - p->y) * f);
    Scene::plainPipeline();
    glViewport(0, 0, fw, fh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0., fw, 0., fh, -1., 1.);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, p->t.colour);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor4f(1.f, 1.f, 1.f, 1.f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.f, 0.f);
    glVertex2f(x0, y0);
    glTexCoord2f(1.f, 0.f);
    glVertex2f(x1, y0);
    glTexCoord2f(1.f, 1.f);
    glVertex2f(x1, y1);
    glTexCoord2f(0.f, 1.f);
    glVertex2f(x0, y1);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
  }

  // --- the surface of a view: its framebuffer, or its window

  bool _prepare(pane *p)
  {
    if(p->glfw) {
      glfwMakeContextCurrent(p->glfw);
      glShader::setWindowFramebuffer(0);
      return true;
    }
    glfwMakeContextCurrent(_main);
    double f = _mainFactor();
    return _bind(p->t, (int)(p->w * f + 0.5), (int)(p->h * f + 0.5));
  }

  // drawn, and shown by the next frame for a tiled view
  void _drawNow(pane *p)
  {
    if(!_prepare(p)) return;
    _plainState();
    int w = p->t.w, h = p->t.h;
    if(p->glfw) glfwGetFramebufferSize(p->glfw, &w, &h);
    glDisable(GL_SCISSOR_TEST);
    glViewport(0, 0, w, h);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _all().draw(p);
    p->wanted = false;
    if(p->glfw)
      glfwSwapBuffers(p->glfw);
    else
      _resolve(p->t);
    glfwMakeContextCurrent(_main);
    _unbind();
  }

  void _destroy(pane *p)
  {
    if(p == _grab) _grab = nullptr;
    if(p == _over) _over = nullptr;
    GLFWwindow *w = p->glfw;
    glfwMakeContextCurrent(w ? w : _main);
    if(!w) _drop(p->t);
    delete p;
    if(w) glfwDestroyWindow(w);
    glfwMakeContextCurrent(_main);
  }

  // --- the pointer and the keys of a graphic window of its own

  pane *_paneOf(GLFWwindow *w)
  {
    for(GuiPanes::Pane *p : _all().panes())
      if(_pane(p)->glfw == w) return _pane(p);
    return nullptr;
  }

  void _modifiers(pane *p, int mods)
  {
    p->modifiers((mods & GLFW_MOD_SHIFT) != 0, (mods & GLFW_MOD_CONTROL) != 0,
                 (mods & GLFW_MOD_ALT) != 0, (mods & GLFW_MOD_SUPER) != 0);
  }

  void _windowMoved(GLFWwindow *w, double x, double y)
  {
    if(pane *p = _paneOf(w)) p->moved(x, y);
    glfwMakeContextCurrent(_main);
  }

  void _windowButton(GLFWwindow *w, int button, int action, int mods)
  {
    pane *p = _paneOf(w);
    int b = button == GLFW_MOUSE_BUTTON_LEFT   ? 0 :
            button == GLFW_MOUSE_BUTTON_RIGHT  ? 1 :
            button == GLFW_MOUSE_BUTTON_MIDDLE ? 2 :
                                                 -1;
    if(!p || b < 0) return;
    double x = 0., y = 0.;
    glfwGetCursorPos(w, &x, &y);
    _modifiers(p, mods);
    if(action == GLFW_PRESS)
      p->pressed(b, x, y, 0.25);
    else
      p->released(b, x, y);
    glfwMakeContextCurrent(_main);
  }

  void _windowScroll(GLFWwindow *w, double, double dy)
  {
    pane *p = _paneOf(w);
    if(!p) return;
    double x = 0., y = 0.;
    glfwGetCursorPos(w, &x, &y);
    p->wheel(dy, x, y);
    glfwMakeContextCurrent(_main);
  }

  void _windowEntered(GLFWwindow *w, int entered)
  {
    if(pane *p = _paneOf(w))
      if(!entered) p->left();
  }

  void _windowKey(GLFWwindow *w, int key, int, int action, int mods)
  {
    pane *p = _paneOf(w);
    if(action != GLFW_PRESS || !p) return;
    _modifiers(p, mods);
    sceneView *v = p->view;
    if(!v->selectionMode) return;
    switch(key) {
    case GLFW_KEY_E: v->endSelection = 1; break;
    case GLFW_KEY_U: v->undoSelection = 1; break;
    case GLFW_KEY_I:
    case GLFW_KEY_MINUS: v->invertSelection = 1; break;
    case GLFW_KEY_Q:
    case GLFW_KEY_ESCAPE: v->quitSelection = 1; break;
    default: break;
    }
    appWindow::wake();
  }

  void _windowFocus(GLFWwindow *w, int focused)
  {
    if(pane *p = _paneOf(w))
      if(focused) _all().setCurrent(p);
  }

  // --- what the interface does with its surfaces

  GuiPanes::Toolkit _toolkit()
  {
    GuiPanes::Toolkit t;
    t.makePane = [](GuiPanes::Pane *) -> GuiPanes::Pane * { return new pane; };
    t.redraw = [](GuiPanes::Pane *p) {
      _pane(p)->wanted = true;
      if(appWindow::available()) appWindow::instance()->requestFrame();
    };
    t.prepare = [](GuiPanes::Pane *p) { return _prepare(_pane(p)); };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      pane *q = _pane(p);
      if(q->glfw) {
        int fw = 0, fh = 0;
        glfwGetWindowSize(q->glfw, &w, &h);
        glfwGetFramebufferSize(q->glfw, &fw, &fh);
        f = (w > 0) ? (double)fw / w : 1.;
        return;
      }
      w = q->w;
      h = q->h;
      f = _mainFactor();
    };
    t.origin = [](GuiPanes::Pane *p, int &x, int &y) {
      x = _pane(p)->x;
      y = _pane(p)->y;
    };
    t.drawNow = [](GuiPanes::Pane *p) { _drawNow(_pane(p)); };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      node *n = _nodeOf(_root, _pane(was));
      if(!n) return;
      n->child[0] = new node;
      n->child[0]->leaf = n->leaf;
      n->child[1] = new node;
      n->child[1]->leaf = _pane(fresh);
      n->leaf = nullptr;
      n->split = how;
      n->ratio = ratio;
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      for(GuiPanes::Pane *p : gone) _destroy(_pane(p));
      _deleteNodes(_root);
      _root = new node;
      _root->leaf = _pane(keep);
    };
    t.newWindow = [](GuiPanes::Pane *fresh) {
      pane *p = _pane(fresh);
      // sharing the context: the same textures, the atlas in particular
      glfwDefaultWindowHints();
      p->glfw = glfwCreateWindow(600, 500, "Gmsh", nullptr, _main);
      if(!p->glfw) {
        Msg::Error("Could not open a new graphic window");
        _all().dropped(p);
        delete p;
        return;
      }
      char title[64];
      snprintf(title, sizeof(title), "Gmsh - Graphic window %d",
               (int)_all().panes().size());
      glfwSetWindowTitle(p->glfw, title);
      glfwSetCursorPosCallback(p->glfw, _windowMoved);
      glfwSetMouseButtonCallback(p->glfw, _windowButton);
      glfwSetScrollCallback(p->glfw, _windowScroll);
      glfwSetCursorEnterCallback(p->glfw, _windowEntered);
      glfwSetKeyCallback(p->glfw, _windowKey);
      glfwSetWindowFocusCallback(p->glfw, _windowFocus);
      glfwMakeContextCurrent(p->glfw);
      p->view->contextChanged();
      glfwMakeContextCurrent(_main);
    };
    t.cursor = [](bool picking) { _picking = picking; };
    t.clipboard = [](int, int, const std::vector<unsigned char> &) {
      // GLFW carries text, not pictures
      static bool said = false;
      if(!said)
        Msg::Info("'copy to clipboard' is not implemented yet in the ImGui "
                  "interface");
      said = true;
    };
    t.later = Scene::later;
    t.buttonDown = []() {
      return ImGui::GetCurrentContext() &&
             (ImGui::IsMouseDown(ImGuiMouseButton_Left) ||
              ImGui::IsMouseDown(ImGuiMouseButton_Right) ||
              ImGui::IsMouseDown(ImGuiMouseButton_Middle));
    };
    t.context = []() -> void * { return glfwGetCurrentContext(); };
    t.screen = glfwScreen;
    t.uiScale = []() {
      return appWindow::available() ? appWindow::instance()->uiScale() : 1.f;
    };
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("imgui"); }
  };
  offering _offering;

  // the views on the main window: the current one alone in full screen
  std::vector<pane *> _shown()
  {
    std::vector<pane *> shown;
    for(GuiPanes::Pane *p : _all().panes())
      if(!p->window && _pane(p)->w > 0 && _pane(p)->h > 0)
        shown.push_back(_pane(p));
    return shown;
  }

} // namespace

void imguiSceneStart(GLFWwindow *main)
{
  _main = main;
  _root = new node;
  _root->leaf = _pane(_all().start(_toolkit()));
  _root->leaf->view->contextChanged();
}

void imguiSceneStop()
{
  std::vector<GuiPanes::Pane *> panes = _all().panes();
  _all().stop();
  for(GuiPanes::Pane *p : panes) _destroy(_pane(p));
  _deleteNodes(_root);
  _root = nullptr;
  _grab = _over = nullptr;
  _main = nullptr;
}

void imguiScenePlace(int x, int y, int w, int h, bool fullscreen)
{
  if(!_root) return;
  if(!fullscreen) {
    _layout(_root, x, y, w, h);
    return;
  }
  // the current view, unless it is in a window of its own
  GuiPanes::Pane *current = _all().current();
  pane *alone = (current && !current->window) ? _pane(current) : nullptr;
  for(GuiPanes::Pane *p : _all().panes())
    if(!p->window) {
      if(!alone) alone = _pane(p);
      _pane(p)->w = _pane(p)->h = 0;
    }
  if(alone) {
    alone->x = x;
    alone->y = y;
    alone->w = w;
    alone->h = h;
  }
}

void imguiScenePointer(bool outside)
{
  ImGuiIO &io = ImGui::GetIO();
  // io.MousePos is on the screen when panels can be dragged out
  const ImGuiViewport *vp = ImGui::GetMainViewport();
  bool nowhere = io.MousePos.x == -FLT_MAX || io.MousePos.y == -FLT_MAX;
  double mx = io.MousePos.x - vp->Pos.x, my = io.MousePos.y - vp->Pos.y;
  pane *at = nullptr;
  if(!outside && !nowhere)
    for(pane *p : _shown())
      if(mx >= p->x && mx < p->x + p->w && my >= p->y && my < p->y + p->h)
        at = p;
  bool entered = false;
  if(!_grab && at != _over) {
    if(_over) _over->left();
    _over = at;
    entered = at != nullptr;
  }
  pane *to = _grab ? _grab : at;
  if(!to || nowhere) return;
  if(_picking && at) ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
  to->modifiers(io.KeyShift, io.KeyCtrl, io.KeyAlt, io.KeySuper);
  double x = mx - to->x, y = my - to->y;
  // the move into the view is one: from where the pointer was, outside
  if(entered && io.MousePosPrev.x != -FLT_MAX && io.MousePosPrev.y != -FLT_MAX)
    to->moved(io.MousePosPrev.x - vp->Pos.x - to->x,
              io.MousePosPrev.y - vp->Pos.y - to->y);
  if(io.MouseDelta.x != 0.f || io.MouseDelta.y != 0.f) to->moved(x, y);
  for(int b = 0; b < 3; b++)
    if(ImGui::IsMouseClicked(b) && to == at) {
      _grab = to;
      to->pressed(b, x, y, io.MouseDoubleClickTime);
    }
  if(io.MouseWheel != 0.f && to == at) to->wheel(io.MouseWheel, x, y);
  for(int b = 0; b < 3; b++)
    if(ImGui::IsMouseReleased(b)) to->released(b, x, y);
  if(!io.MouseDown[0] && !io.MouseDown[1] && !io.MouseDown[2])
    _grab = nullptr;
  // what the view did left its framebuffer bound
  glfwMakeContextCurrent(_main);
  _unbind();
}

void imguiSceneDraw()
{
  // drawn again when asked for, or when the view changed size; put back
  // otherwise
  double f = _mainFactor();
  std::vector<pane *> shown = _shown();
  for(pane *p : shown)
    if(p->wanted || p->t.w != (int)(p->w * f + 0.5) ||
       p->t.h != (int)(p->h * f + 0.5))
      _drawNow(p);
  glfwMakeContextCurrent(_main);
  _unbind();
  for(pane *p : shown) _show(p);
}

void imguiSceneWindows()
{
  std::vector<GuiPanes::Pane *> panes = _all().panes();
  for(GuiPanes::Pane *p : panes) {
    pane *q = _pane(p);
    if(!q->glfw) continue;
    if(glfwWindowShouldClose(q->glfw)) {
      _all().dropped(q);
      _destroy(q);
      continue;
    }
    // at every frame: a window of its own tells nobody when it is uncovered
    _drawNow(q);
  }
  glfwMakeContextCurrent(_main);
}

void imguiSceneRedraw() { _all().redrawAll(); }

sceneView *imguiSceneCurrent()
{
  GuiPanes::Pane *p = _all().current();
  return p ? p->view : nullptr;
}

void imguiSceneNewWindow() { _all().newWindow(); }
