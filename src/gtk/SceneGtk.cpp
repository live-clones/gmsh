// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the GTK interface, see GuiScene.h: each view in a GtkGLArea
// of its own, the areas of the main window split with GtkPaned, a new graphic
// window a GtkWindow holding one more

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <string>
#include <vector>

#include "glApi.h"
#include "gtkCommon.h"

#include "Gui.h"
#include "GuiScene.h"
#include "GuiActions.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "OS.h"

#if !defined(GL_FRAMEBUFFER_BINDING)
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#endif

namespace {

  struct pane {
    GtkWidget *area = nullptr;
    sceneView *view = nullptr;
    // a graphic window of its own, not tiled in the main one
    GtkWidget *window = nullptr;
    paneInput input;
    double lastX = 0., lastY = 0., lastPress = 0.;
    bool moved = false;
    // the framebuffer, in its pixels, as the area said when it was resized
    int fbW = 0, fbH = 0;
  };

  std::vector<pane *> _panes;
  pane *_current = nullptr;
  // the tiled panes of the main window are in this box
  GtkWidget *_root = nullptr;
  // the size of a picture being captured, in the pixels of the framebuffer
  int _captureW = 0, _captureH = 0;
  bool _captureComposite = false;
  bool _animating = false;
  bool _drawing = false;
  guint _animation = 0, _gamepad = 0;

  std::vector<GVertex *> _vertices;
  std::vector<GEdge *> _edges;
  std::vector<GFace *> _faces;
  std::vector<GRegion *> _regions;
  std::vector<MElement *> _elements;
  std::vector<SPoint2> _points;
  std::vector<PView *> _views;

  void _clearSelected()
  {
    _vertices.clear();
    _edges.clear();
    _faces.clear();
    _regions.clear();
    _elements.clear();
    _points.clear();
    _views.clear();
  }

  pane *_paneOf(sceneView *view)
  {
    for(pane *p : _panes)
      if(p->view == view) return p;
    return nullptr;
  }

  pane *_paneOf(GtkWidget *area)
  {
    for(pane *p : _panes)
      if(p->area == area) return p;
    return nullptr;
  }

  // framebuffer pixels per pixel of the widget
  double _factor(pane *p)
  {
    int w = gtk_widget_get_width(p->area);
    if(w > 0 && p->fbW > 0) return p->fbW / (double)w;
    return gtk_widget_get_scale_factor(p->area);
  }

  // the context of the area current, its framebuffer bound and made the
  // window's; false before it is realized
  bool _prepare(pane *p)
  {
    if(!p || !p->area || !gtk_widget_get_realized(p->area)) return false;
    GtkGLArea *a = GTK_GL_AREA(p->area);
    gtk_gl_area_make_current(a);
    if(gtk_gl_area_get_error(a)) return false;
    gtk_gl_area_attach_buffers(a);
    GLint fbo = 0;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo);
    glShader::setWindowFramebuffer((unsigned int)fbo);
    return true;
  }

  void _place(pane *p)
  {
    int w = gtk_widget_get_width(p->area), h = gtk_widget_get_height(p->area);
    p->view->setRect(0, 0, w, h);
    p->view->setOrigin(0., 0., h, _factor(p));
  }

  // what the scene leaves set is put back as GTK expects it: GTK reads the
  // picture back in this context when it cannot hand the texture over
  void _putBack()
  {
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glPixelStorei(GL_PACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    if(glApi::BindBuffer) {
      glApi::BindBuffer(0x88EB /* GL_PIXEL_PACK_BUFFER */, 0);
      glApi::BindBuffer(0x88EC /* GL_PIXEL_UNPACK_BUFFER */, 0);
      glApi::BindBuffer(0x8892 /* GL_ARRAY_BUFFER */, 0);
    }
    if(glApi::BindVertexArray) glApi::BindVertexArray(0);
    if(glApi::UseProgram) glApi::UseProgram(0);
    if(glApi::ActiveTexture) glApi::ActiveTexture(0x84C0 /* GL_TEXTURE0 */);
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
  }

  void _draw(pane *p)
  {
    int w = gtk_widget_get_width(p->area), h = gtk_widget_get_height(p->area);
    if(w < 1 || h < 1) return;
    double f = _factor(p);
    if(_captureW > 0 && _captureH > 0) {
      // in the bottom-left corner, where PixelBuffer::fill() reads, the rest
      // cleared
      int lw = (int)(_captureW / f + 0.5), lh = (int)(_captureH / f + 0.5);
      glDisable(GL_SCISSOR_TEST);
      glViewport(0, 0, p->fbW, p->fbH);
      glClearColor(0.f, 0.f, 0.f, 1.f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      p->view->setRect(0, h - lh, lw, lh);
      p->view->setOrigin(0., 0., h, f);
      p->view->draw(f, h);
      _place(p);
    }
    else {
      _place(p);
      p->view->draw(f, h);
    }
    glShader::release();
    _putBack();
  }

  // --- the area

  void _realize(GtkGLArea *a, gpointer)
  {
    pane *p = _paneOf(GTK_WIDGET(a));
    if(!p) return;
    gtk_gl_area_make_current(a);
    if(GError *e = gtk_gl_area_get_error(a)) {
      Msg::Warning("Could not have an OpenGL context: %s", e->message);
      return;
    }
    // what is kept per context is this one's before anything is built in it
    glShader::setContext(gdk_gl_context_get_current());
    p->view->contextChanged();
    // a new context has nothing drawn in it
    gtk_gl_area_queue_render(a);
  }

  gboolean _render(GtkGLArea *a, GdkGLContext *, gpointer)
  {
    pane *p = _paneOf(GTK_WIDGET(a));
    if(!p || gtk_gl_area_get_error(a)) return FALSE;
    GLint fbo = 0;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo);
    glShader::setWindowFramebuffer((unsigned int)fbo);
    _drawing = true;
    _draw(p);
    _drawing = false;
    return TRUE;
  }

  void _resize(GtkGLArea *a, int width, int height, gpointer)
  {
    pane *p = _paneOf(GTK_WIDGET(a));
    if(!p) return;
    p->fbW = width;
    p->fbH = height;
    gtk_gl_area_queue_render(a);
  }

  // where the pointer is in the area, from where the event says it is on the
  // surface
  void _where(GtkWidget *area, GdkEvent *e, double &x, double &y)
  {
    double sx = 0., sy = 0.;
    gdk_event_get_position(e, &sx, &sy);
    GtkNative *native = gtk_widget_get_native(area);
    double nx = 0., ny = 0.;
    gtk_native_get_surface_transform(native, &nx, &ny);
    graphene_point_t in = GRAPHENE_POINT_INIT((float)(sx - nx), (float)(sy - ny));
    graphene_point_t out;
    if(gtk_widget_compute_point(GTK_WIDGET(native), area, &in, &out)) {
      x = out.x;
      y = out.y;
    }
    else {
      x = sx;
      y = sy;
    }
  }

  void _handle(pane *p)
  {
    if(!_prepare(p)) return;
    _place(p);
    p->view->handleMouse(p->input);
    for(int b = 0; b < 3; b++)
      p->input.clicked[b] = p->input.released[b] = false;
    p->input.doubleClicked = false;
    p->input.wheel = 0.;
    p->input.dx = p->input.dy = 0.;
    gtk_gl_area_queue_render(GTK_GL_AREA(p->area));
  }

  gboolean _event(GtkEventControllerLegacy *c, GdkEvent *e, gpointer)
  {
    GtkWidget *area = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c));
    pane *p = _paneOf(area);
    if(!p) return FALSE;
    GdkEventType type = gdk_event_get_event_type(e);
    if(type != GDK_MOTION_NOTIFY && type != GDK_BUTTON_PRESS &&
       type != GDK_BUTTON_RELEASE && type != GDK_SCROLL)
      return FALSE;
    GdkModifierType state = gdk_event_get_modifier_state(e);
    paneInput &in = p->input;
    in.shift = (state & GDK_SHIFT_MASK) != 0;
    in.ctrl = (state & GDK_CONTROL_MASK) != 0;
    in.alt = (state & GDK_ALT_MASK) != 0;
    in.super = (state & (GDK_SUPER_MASK | GDK_META_MASK)) != 0;
    if(type != GDK_SCROLL) {
      double x = 0., y = 0.;
      _where(area, e, x, y);
      in.dx = p->moved ? x - p->lastX : 0.;
      in.dy = p->moved ? y - p->lastY : 0.;
      p->lastX = in.x = x;
      p->lastY = in.y = y;
      p->moved = true;
    }
    if(type == GDK_BUTTON_PRESS || type == GDK_BUTTON_RELEASE) {
      guint button = gdk_button_event_get_button(e);
      int b = button == 1 ? 0 : button == 3 ? 1 : button == 2 ? 2 : -1;
      if(b < 0) return FALSE;
      if(type == GDK_BUTTON_PRESS) {
        _current = p;
        gtk_widget_grab_focus(area);
        in.clicked[b] = in.dragging[b] = true;
        double now = TimeOfDay();
        int ms = 400;
        g_object_get(gtk_settings_get_default(), "gtk-double-click-time", &ms,
                     nullptr);
        in.doubleClicked = b == 0 && now - p->lastPress < ms / 1000.;
        if(b == 0) p->lastPress = in.doubleClicked ? 0. : now;
      }
      else {
        in.released[b] = true;
        in.dragging[b] = false;
      }
    }
    else if(type == GDK_SCROLL) {
      GdkScrollDirection d = gdk_scroll_event_get_direction(e);
      if(d == GDK_SCROLL_UP)
        in.wheel = 1.;
      else if(d == GDK_SCROLL_DOWN)
        in.wheel = -1.;
      else if(d == GDK_SCROLL_SMOOTH) {
        double dx = 0., dy = 0.;
        gdk_scroll_event_get_deltas(e, &dx, &dy);
        in.wheel = -dy;
      }
      if(in.wheel == 0.) return FALSE;
    }
    _handle(p);
    return type != GDK_MOTION_NOTIFY;
  }

  void _enter(GtkEventControllerMotion *c, double, double, gpointer)
  {
    pane *p =
      _paneOf(gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c)));
    if(p) _current = p;
  }

  void _leave(GtkEventControllerMotion *c, gpointer)
  {
    pane *p =
      _paneOf(gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c)));
    if(!p) return;
    p->moved = false;
    p->view->pointerLeft();
    gtk_gl_area_queue_render(GTK_GL_AREA(p->area));
  }

  // Alt and the arrows step through what is stacked under the pointer; the
  // other keys are the window's
  gboolean _key(GtkEventControllerKey *c, guint keyval, guint,
                GdkModifierType state, gpointer)
  {
    pane *p =
      _paneOf(gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c)));
    if(!p) return FALSE;
    if((state & GDK_ALT_MASK) && (keyval == GDK_KEY_Up || keyval == GDK_KEY_Down) &&
       CTX::instance()->mouseSelection && !p->view->lasso() &&
       !p->view->addPointMode) {
      if(_prepare(p)) p->view->stepPick(keyval == GDK_KEY_Down ? 1 : -1);
      gtk_gl_area_queue_render(GTK_GL_AREA(p->area));
      return TRUE;
    }
    return FALSE;
  }

  pane *_newPane(pane *from)
  {
    pane *p = new pane;
    p->view = new sceneView();
    if(from)
      p->view->getDrawContext()->copyViewAttributes(from->view->getDrawContext());
    p->area = gtk_gl_area_new();
    // the scene is drawn with the shader pipeline: OpenGL 3.2 and up
    gtk_gl_area_set_allowed_apis(GTK_GL_AREA(p->area), GDK_GL_API_GL);
    gtk_gl_area_set_required_version(GTK_GL_AREA(p->area), 3, 2);
    gtk_gl_area_set_has_depth_buffer(GTK_GL_AREA(p->area), TRUE);
    gtk_gl_area_set_has_stencil_buffer(GTK_GL_AREA(p->area), TRUE);
    gtk_gl_area_set_auto_render(GTK_GL_AREA(p->area), FALSE);
    gtk_widget_set_hexpand(p->area, TRUE);
    gtk_widget_set_vexpand(p->area, TRUE);
    gtk_widget_set_focusable(p->area, TRUE);
    gtk_widget_set_size_request(p->area, 100, 100);
    g_signal_connect(p->area, "realize", G_CALLBACK(_realize), nullptr);
    g_signal_connect(p->area, "render", G_CALLBACK(_render), nullptr);
    g_signal_connect(p->area, "resize", G_CALLBACK(_resize), nullptr);
    GtkEventController *legacy = gtk_event_controller_legacy_new();
    g_signal_connect(legacy, "event", G_CALLBACK(_event), nullptr);
    gtk_widget_add_controller(p->area, legacy);
    GtkEventController *motion = gtk_event_controller_motion_new();
    g_signal_connect(motion, "enter", G_CALLBACK(_enter), nullptr);
    g_signal_connect(motion, "leave", G_CALLBACK(_leave), nullptr);
    gtk_widget_add_controller(p->area, motion);
    GtkEventController *keys = gtk_event_controller_key_new();
    g_signal_connect(keys, "key-pressed", G_CALLBACK(_key), nullptr);
    gtk_widget_add_controller(p->area, keys);
    // a moved area is made again, and keeps its view
    g_object_ref(p->area);
    _panes.push_back(p);
    return p;
  }

  void _dropPane(pane *p)
  {
    _panes.erase(std::find(_panes.begin(), _panes.end(), p));
    if(_current == p) _current = _panes.empty() ? nullptr : _panes[0];
    if(p->window) gtk_window_destroy(GTK_WINDOW(p->window));
    if(GtkWidget *parent = gtk_widget_get_parent(p->area)) {
      if(GTK_IS_BOX(parent))
        gtk_box_remove(GTK_BOX(parent), p->area);
      else if(GTK_IS_PANED(parent)) {
        if(gtk_paned_get_start_child(GTK_PANED(parent)) == p->area)
          gtk_paned_set_start_child(GTK_PANED(parent), nullptr);
        else
          gtk_paned_set_end_child(GTK_PANED(parent), nullptr);
      }
    }
    g_object_unref(p->area);
    delete p->view;
    delete p;
  }

  // a window of its own closed: its view goes with it
  gboolean _windowClosed(GtkWindow *w, gpointer)
  {
    for(pane *p : _panes)
      if(p->window == (GtkWidget *)w) {
        p->window = nullptr;
        _dropPane(p);
        break;
      }
    return FALSE;
  }

  void _redrawAll()
  {
    for(pane *p : _panes) gtk_gl_area_queue_render(GTK_GL_AREA(p->area));
  }

  gboolean _laterFired(gpointer data)
  {
    std::function<void()> *what = (std::function<void()> *)data;
    if(*what) (*what)();
    return G_SOURCE_REMOVE;
  }

  void _laterDropped(gpointer data) { delete (std::function<void()> *)data; }

  gboolean _animationTick(gpointer)
  {
    if(!_animating) {
      _animation = 0;
      return G_SOURCE_REMOVE;
    }
    animationTick();
    return G_SOURCE_CONTINUE;
  }

  gboolean _gamepadTick(gpointer)
  {
    _gamepad = 0;
    if(_current && Scene::gamepadTurn(_current->view))
      gtk_gl_area_queue_render(GTK_GL_AREA(_current->area));
    gtkSceneStartTimers();
    return G_SOURCE_REMOVE;
  }

  void _setHost()
  {
    Scene::Host held;
    held.redraw = []() { _redrawAll(); };
    held.redrawView = [](sceneView *view) {
      if(pane *p = _paneOf(view)) gtk_gl_area_queue_render(GTK_GL_AREA(p->area));
    };
    held.check = [](bool rateLimited) { Gui::instance().check(rateLimited); };
    held.wait = [](double seconds, bool force) {
      if(seconds < 0.)
        Gui::instance().wait(force);
      else
        Gui::instance().wait(seconds, force);
    };
    held.drawCurrent = []() {
      if(_prepare(_current)) {
        _draw(_current);
        glFlush();
      }
    };
    held.uiScale = []() { return _current ? (float)_factor(_current) : 1.f; };
    held.numViews = []() { return (int)_panes.size(); };
    held.cursor = [](Scene::Cursor kind) {
      for(pane *p : _panes)
        gtk_widget_set_cursor_from_name(
          p->area, kind == Scene::Picking ? "pointer" : nullptr);
    };
    held.current = []() -> sceneView * {
      return _current ? _current->view : nullptr;
    };
    held.setCurrent = [](sceneView *view) {
      if(pane *p = _paneOf(view)) _current = p;
    };
    held.later = [](double seconds, std::function<void()> what) {
      g_timeout_add_full(G_PRIORITY_DEFAULT,
                         (guint)std::max(0., seconds * 1000.), _laterFired,
                         new std::function<void()>(what), _laterDropped);
    };
    held.buttonDown = []() { return gtkButtonDown(); };
    held.context = []() -> void * { return gdk_gl_context_get_current(); };
    held.makeCurrent = [](sceneView *view) { _prepare(_paneOf(view)); };
    held.screen = [](int &height, float &scale) {
      height = 0;
      scale = 1.f;
      GdkDisplay *display = gdk_display_get_default();
      GdkMonitor *monitor = nullptr;
      GtkWindow *main = gtkMainWindow();
      if(main && gtk_widget_get_realized(GTK_WIDGET(main)))
        monitor = gdk_display_get_monitor_at_surface(
          display, gtk_native_get_surface(GTK_NATIVE(main)));
      if(!monitor) {
        GListModel *all = gdk_display_get_monitors(display);
        if(g_list_model_get_n_items(all))
          monitor = GDK_MONITOR(g_list_model_get_item(all, 0));
        if(monitor) g_object_unref(monitor);
      }
      if(!monitor) return;
      GdkRectangle r;
      gdk_monitor_get_geometry(monitor, &r);
      scale = (float)gdk_monitor_get_scale_factor(monitor);
      height = (int)(r.height * scale);
    };
    Scene::setHost(held);
  }

} // namespace

// --- what the main window asks

GtkWidget *gtkSceneWidget()
{
  if(_root) return _root;
  _setHost();
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  _root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_hexpand(_root, TRUE);
  gtk_widget_set_vexpand(_root, TRUE);
  g_object_ref(_root);
  _current = _newPane(nullptr);
  gtk_box_append(GTK_BOX(_root), _current->area);
  return _root;
}

void gtkSceneRedraw() { _redrawAll(); }

bool gtkSceneDrawing() { return _drawing; }

namespace GtkScene {
  void copyCurrentOpenglWindowToClipboard();
}

void gtkSceneCopy() { GtkScene::copyCurrentOpenglWindowToClipboard(); }

void gtkSceneSize(int &width, int &height)
{
  width = height = 0;
  for(pane *p : _panes)
    if(!p->window) {
      // the whole of the tiled panes
      width = gtk_widget_get_width(_root);
      height = gtk_widget_get_height(_root);
      return;
    }
}

void gtkSceneSplit(char how, double ratio)
{
  if(!_current) return;
  if(how == 'u') {
    // the current view alone, or the first of the main window
    pane *keep = (_current && !_current->window) ? _current : nullptr;
    for(pane *p : _panes)
      if(!keep && !p->window) keep = p;
    if(!keep) return;
    std::vector<pane *> gone;
    for(pane *p : _panes)
      if(p != keep && !p->window) gone.push_back(p);
    for(pane *p : gone) _dropPane(p);
    if(GtkWidget *parent = gtk_widget_get_parent(keep->area)) {
      if(GTK_IS_PANED(parent)) {
        if(gtk_paned_get_start_child(GTK_PANED(parent)) == keep->area)
          gtk_paned_set_start_child(GTK_PANED(parent), nullptr);
        else
          gtk_paned_set_end_child(GTK_PANED(parent), nullptr);
      }
      else
        gtk_box_remove(GTK_BOX(parent), keep->area);
    }
    while(GtkWidget *c = gtk_widget_get_first_child(_root))
      gtk_box_remove(GTK_BOX(_root), c);
    gtk_box_append(GTK_BOX(_root), keep->area);
    _current = keep;
    _redrawAll();
    return;
  }
  if(how != 'h' && how != 'v') {
    Msg::Error("Unknown window splitting method '%c'", how);
    return;
  }
  if(_current->window) {
    Msg::Error("Only the graphic windows of the main window can be split");
    return;
  }
  pane *was = _current;
  pane *fresh = _newPane(was);
  GtkWidget *parent = gtk_widget_get_parent(was->area);
  GtkWidget *paned = gtk_paned_new(how == 'h' ? GTK_ORIENTATION_HORIZONTAL :
                                                GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle(GTK_PANED(paned), TRUE);
  bool start = false;
  if(GTK_IS_PANED(parent)) {
    start = gtk_paned_get_start_child(GTK_PANED(parent)) == was->area;
    if(start)
      gtk_paned_set_start_child(GTK_PANED(parent), nullptr);
    else
      gtk_paned_set_end_child(GTK_PANED(parent), nullptr);
  }
  else
    gtk_box_remove(GTK_BOX(parent), was->area);
  gtk_paned_set_start_child(GTK_PANED(paned), was->area);
  gtk_paned_set_end_child(GTK_PANED(paned), fresh->area);
  // at the ratio asked, once it has a size: half by default
  int size = how == 'h' ? gtk_widget_get_width(parent) :
                          gtk_widget_get_height(parent);
  if(ratio <= 0. || ratio >= 1.) ratio = .5;
  if(size > 0) gtk_paned_set_position(GTK_PANED(paned), (int)(size * ratio));
  if(GTK_IS_PANED(parent)) {
    if(start)
      gtk_paned_set_start_child(GTK_PANED(parent), paned);
    else
      gtk_paned_set_end_child(GTK_PANED(parent), paned);
  }
  else
    gtk_box_append(GTK_BOX(parent), paned);
  _current = fresh;
  _redrawAll();
}

void gtkSceneNewWindow()
{
  pane *fresh = _newPane(_current);
  GtkWidget *w = gtk_window_new();
  char title[64];
  snprintf(title, sizeof(title), "Gmsh - Graphic window %d",
           (int)_panes.size());
  gtk_window_set_title(GTK_WINDOW(w), title);
  gtk_window_set_default_size(GTK_WINDOW(w), 600, 500);
  gtk_window_set_child(GTK_WINDOW(w), fresh->area);
  g_signal_connect(w, "close-request", G_CALLBACK(_windowClosed), nullptr);
  gtkWatchButtons(w);
  // the keys the view does not take are Gmsh's
  GtkEventController *keys = gtk_event_controller_key_new();
  g_signal_connect(keys, "key-pressed",
                   G_CALLBACK(+[](GtkEventControllerKey *, guint keyval, guint,
                                  GdkModifierType state, gpointer) -> gboolean {
                     return gtkMainKey(keyval, state);
                   }),
                   nullptr);
  gtk_widget_add_controller(w, keys);
  fresh->window = w;
  _current = fresh;
  gtk_window_present(GTK_WINDOW(w));
}

void gtkSceneDestroy()
{
  if(_animation) g_source_remove(_animation);
  if(_gamepad) g_source_remove(_gamepad);
  _animation = _gamepad = 0;
  while(!_panes.empty()) _dropPane(_panes.back());
  _current = nullptr;
  if(_root) g_object_unref(_root);
  _root = nullptr;
}

void gtkSceneStartTimers()
{
  if(_animating && !_animation)
    _animation = g_timeout_add(10, _animationTick, nullptr);
  if(!_gamepad) {
    double period = Scene::gamepadPeriod();
    if(period > 0.)
      _gamepad = g_timeout_add((guint)(period * 1000.), _gamepadTick, nullptr);
    else
      // the option may be switched on: looked at again now and then
      _gamepad = g_timeout_add(3000, _gamepadTick, nullptr);
  }
}

namespace GtkScene {

  // the scene is in the interface's own windows: nothing to pump, nothing to
  // send
  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always) { return ""; }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
  }

  bool sceneKey(char key)
  {
    bool taken = false;
    for(pane *p : _panes)
      if(p->view->key(key)) {
        taken = true;
        gtk_gl_area_queue_render(GTK_GL_AREA(p->area));
      }
    return taken;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    if(!_current) return;
    _current->view->screenMessage[0] = first;
    _current->view->screenMessage[1] = second;
    gtk_gl_area_queue_render(GTK_GL_AREA(_current->area));
  }

  drawContext *getCurrentDrawContext()
  {
    return _current ? _current->view->getDrawContext() : nullptr;
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    if(!_current) return;
    double f = _factor(_current);
    width = (int)(gtk_widget_get_width(_current->area) * f + 0.5);
    height = (int)(gtk_widget_get_height(_current->area) * f + 0.5);
  }

  void setCurrentOpenglWindow(int which)
  {
    if(which >= 0 && which < (int)_panes.size()) _current = _panes[which];
  }

  void showAllInEveryWindow()
  {
    for(pane *p : _panes)
      if(drawContext *ctx = p->view->getDrawContext()) ctx->showAll();
    _redrawAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    gtkSceneSplit(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(w < 1 || h < 1 || !_prepare(_current)) return;
    std::vector<unsigned char> pixels((std::size_t)4 * w * h);
    _draw(_current);
    glFinish();
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);
    // the rows go bottom up
    std::vector<unsigned char> flipped(pixels.size());
    for(int y = 0; y < h; y++)
      memcpy(&flipped[(std::size_t)4 * w * y],
             &pixels[(std::size_t)4 * w * (h - 1 - y)], (std::size_t)4 * w);
    for(std::size_t i = 3; i < flipped.size(); i += 4) flipped[i] = 255;
    GBytes *bytes = g_bytes_new(flipped.data(), flipped.size());
    GdkTexture *texture = gdk_memory_texture_new(
      w, h, GDK_MEMORY_R8G8B8A8, bytes, (gsize)4 * w);
    g_bytes_unref(bytes);
    gdk_clipboard_set_texture(gdk_display_get_clipboard(gdk_display_get_default()),
                              texture);
    g_object_unref(texture);
    gtk_gl_area_queue_render(GTK_GL_AREA(_current->area));
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    _captureComposite = composite;
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(width > w || height > h) {
      Msg::Warning("The GTK interface cannot render a picture larger than the "
                   "graphic window (%d x %d): clamping", w, h);
      width = std::min(width, w);
      height = std::min(height, h);
    }
    if(width < 1) width = 1;
    if(height < 1) height = 1;
    _captureW = width;
    _captureH = height;
  }

  void endGraphicCapture()
  {
    _captureW = _captureH = 0;
    _captureComposite = false;
    _redrawAll();
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    int width = 0, height = 0;
    getCurrentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;
    // the aspect ratio is kept when only one of General.PrintWidth and
    // PrintHeight is given
    CTX *c = CTX::instance();
    if(c->print.width > 0 || c->print.height > 0) {
      if(c->print.width <= 0) {
        width = (int)(width * c->print.height / (double)height);
        height = c->print.height;
      }
      else if(c->print.height <= 0) {
        height = (int)(height * c->print.width / (double)width);
        width = c->print.width;
      }
      else {
        width = c->print.width;
        height = c->print.height;
      }
    }
    beginGraphicCapture(width, height, c->print.compositeWindows ? true : false);
    PixelBuffer *buffer =
      new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    buffer->fill();
    endGraphicCapture();
    return buffer;
  }

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    std::vector<sceneView *> views;
    for(pane *p : _panes)
      if(!p->window) views.push_back(p->view);
    if(views.empty() && _current) views.push_back(_current->view);
    Scene::orientViews(views, what, reverse, sync);
    _redrawAll();
  }

  void setMouseSelection(bool on) {}

  void toggleAnimation()
  {
    _animating = !_animating;
    gtkSceneStartTimers();
  }

  bool animating() { return _animating; }

  void abortSelection()
  {
    if(!_current) return;
    _current->view->quitSelection = 1;
    _current->view->selectionMode = false;
  }

  void setAddPointMode(bool on)
  {
    for(pane *p : _panes) p->view->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(what == "background_image")
      for(pane *p : _panes)
        if(p->view->getDrawContext())
          p->view->getDrawContext()->invalidateBgImageTexture();
    _redrawAll();
  }

  char selectEntity(int type)
  {
    _clearSelected();
    if(!_current) return 'q';
    return _current->view->selectEntity(type, _vertices, _edges, _faces,
                                        _regions, _elements, _points, _views);
  }

  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    _clearSelected();
    if(!_prepare(_current)) return false;
    _place(_current);
    return _current->view->pick(type, mesh, post, x, y, w, h, _vertices,
                                _edges, _faces, _regions, _elements, _points,
                                _views);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!_prepare(_current)) return false;
    bool ok = _current->view->printTo(width, height, supersampling, format,
                                      type, pixels);
    gtk_gl_area_queue_render(GTK_GL_AREA(_current->area));
    return ok;
  }

  const std::vector<GVertex *> &selectedVertices() { return _vertices; }
  const std::vector<GEdge *> &selectedEdges() { return _edges; }
  const std::vector<GFace *> &selectedFaces() { return _faces; }
  const std::vector<GRegion *> &selectedRegions() { return _regions; }
  const std::vector<MElement *> &selectedElements() { return _elements; }
  const std::vector<SPoint2> &selectedPoints() { return _points; }
  const std::vector<PView *> &selectedViews() { return _views; }

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
        Gui::offerScene("gtk", ops);
      }
    };
    offering _offering;
  } // namespace

} // namespace GtkScene
