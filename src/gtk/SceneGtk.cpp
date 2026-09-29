// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the GTK interface, see GuiPanes.h: each view in a GtkGLArea of
// its own, the views of the main window split with GtkPaned, a new graphic
// window a GtkWindow holding one more

#include "GmshConfig.h"

#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#include "gtkCommon.h"

#include "Gui.h"
#include "GuiPanes.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"

#if !defined(GL_FRAMEBUFFER_BINDING)
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#endif

namespace {

  struct pane : public GuiPanes::Pane {
    GtkWidget *area = nullptr;
    // the window of a graphic window of its own
    GtkWidget *top = nullptr;
    // the framebuffer, in its pixels, as the area said when it was resized
    int fbW = 0, fbH = 0;
  };

  // the tiled panes of the main window are in this box
  GtkWidget *_root = nullptr;

  GuiPanes &_all() { return GuiPanes::instance(); }

  pane *_pane(GuiPanes::Pane *p) { return static_cast<pane *>(p); }

  pane *_paneOf(GtkWidget *area)
  {
    for(GuiPanes::Pane *p : _all().panes())
      if(_pane(p)->area == area) return _pane(p);
    return nullptr;
  }

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
    _all().draw(p);
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
    p->modifiers((state & GDK_SHIFT_MASK) != 0, (state & GDK_CONTROL_MASK) != 0,
                 (state & GDK_ALT_MASK) != 0,
                 (state & (GDK_SUPER_MASK | GDK_META_MASK)) != 0);
    double x = 0., y = 0.;
    _where(area, e, x, y);
    if(type == GDK_MOTION_NOTIFY) {
      p->moved(x, y);
      return FALSE;
    }
    if(type == GDK_SCROLL) {
      double wheel = 0.;
      GdkScrollDirection d = gdk_scroll_event_get_direction(e);
      if(d == GDK_SCROLL_UP)
        wheel = 1.;
      else if(d == GDK_SCROLL_DOWN)
        wheel = -1.;
      else if(d == GDK_SCROLL_SMOOTH) {
        double dx = 0., dy = 0.;
        gdk_scroll_event_get_deltas(e, &dx, &dy);
        wheel = -dy;
      }
      if(wheel == 0.) return FALSE;
      p->wheel(wheel, x, y);
      return TRUE;
    }
    guint button = gdk_button_event_get_button(e);
    int b = button == 1 ? 0 : button == 3 ? 1 : button == 2 ? 2 : -1;
    if(b < 0) return FALSE;
    if(type == GDK_BUTTON_PRESS) {
      gtk_widget_grab_focus(area);
      int ms = 400;
      g_object_get(gtk_settings_get_default(), "gtk-double-click-time", &ms,
                   nullptr);
      p->pressed(b, x, y, ms / 1000.);
    }
    else
      p->released(b, x, y);
    return TRUE;
  }

  void _enter(GtkEventControllerMotion *c, double, double, gpointer)
  {
    pane *p =
      _paneOf(gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c)));
    if(p) _all().setCurrent(p);
  }

  void _leave(GtkEventControllerMotion *c, gpointer)
  {
    pane *p =
      _paneOf(gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c)));
    if(p) p->left();
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
      return TRUE;
    }
    return FALSE;
  }

  pane *_newPane()
  {
    pane *p = new pane;
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
    return p;
  }

  // out of whatever holds it
  void _detach(pane *p)
  {
    GtkWidget *parent = gtk_widget_get_parent(p->area);
    if(!parent) return;
    if(GTK_IS_PANED(parent)) {
      if(gtk_paned_get_start_child(GTK_PANED(parent)) == p->area)
        gtk_paned_set_start_child(GTK_PANED(parent), nullptr);
      else
        gtk_paned_set_end_child(GTK_PANED(parent), nullptr);
    }
    else if(GTK_IS_BOX(parent))
      gtk_box_remove(GTK_BOX(parent), p->area);
    else if(GTK_IS_WINDOW(parent))
      gtk_window_set_child(GTK_WINDOW(parent), nullptr);
  }

  void _destroy(pane *p)
  {
    _detach(p);
    if(p->top) gtk_window_destroy(GTK_WINDOW(p->top));
    g_object_unref(p->area);
    delete p;
  }

  // a window of its own closed: its view goes with it
  gboolean _windowClosed(GtkWindow *w, gpointer)
  {
    for(GuiPanes::Pane *q : _all().panes())
      if(_pane(q)->top == (GtkWidget *)w) {
        pane *p = _pane(q);
        p->top = nullptr;
        _all().dropped(p);
        _destroy(p);
        break;
      }
    return FALSE;
  }

  gboolean _laterFired(gpointer data)
  {
    std::function<void()> *what = (std::function<void()> *)data;
    if(*what) (*what)();
    return G_SOURCE_REMOVE;
  }

  void _laterDropped(gpointer data) { delete (std::function<void()> *)data; }

  GuiPanes::Toolkit _toolkit()
  {
    GuiPanes::Toolkit t;
    t.makePane = [](GuiPanes::Pane *) -> GuiPanes::Pane * { return _newPane(); };
    t.redraw = [](GuiPanes::Pane *p) {
      gtk_gl_area_queue_render(GTK_GL_AREA(_pane(p)->area));
    };
    t.prepare = [](GuiPanes::Pane *p) { return _prepare(_pane(p)); };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      w = gtk_widget_get_width(_pane(p)->area);
      h = gtk_widget_get_height(_pane(p)->area);
      f = _factor(_pane(p));
    };
    t.origin = [](GuiPanes::Pane *p, int &x, int &y) {
      GtkWidget *area = _pane(p)->area;
      graphene_point_t in = GRAPHENE_POINT_INIT(0.f, 0.f), out;
      x = y = 0;
      if(gtk_widget_compute_point(area, GTK_WIDGET(gtk_widget_get_root(area)),
                                  &in, &out)) {
        x = (int)(out.x + 0.5f);
        y = (int)(out.y + 0.5f);
      }
    };
    t.drawNow = [](GuiPanes::Pane *p) {
      if(!_prepare(_pane(p))) return;
      _all().draw(p);
      glFlush();
    };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      GtkWidget *area = _pane(was)->area;
      GtkWidget *parent = gtk_widget_get_parent(area);
      GtkWidget *paned = gtk_paned_new(how == 'h' ? GTK_ORIENTATION_HORIZONTAL :
                                                    GTK_ORIENTATION_VERTICAL);
      gtk_paned_set_wide_handle(GTK_PANED(paned), TRUE);
      bool start = GTK_IS_PANED(parent) &&
                   gtk_paned_get_start_child(GTK_PANED(parent)) == area;
      _detach(_pane(was));
      gtk_paned_set_start_child(GTK_PANED(paned), area);
      gtk_paned_set_end_child(GTK_PANED(paned), _pane(fresh)->area);
      // at the ratio asked, once it has a size
      int size = how == 'h' ? gtk_widget_get_width(parent) :
                              gtk_widget_get_height(parent);
      if(size > 0) gtk_paned_set_position(GTK_PANED(paned), (int)(size * ratio));
      if(GTK_IS_PANED(parent)) {
        if(start)
          gtk_paned_set_start_child(GTK_PANED(parent), paned);
        else
          gtk_paned_set_end_child(GTK_PANED(parent), paned);
      }
      else
        gtk_box_append(GTK_BOX(parent), paned);
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      for(GuiPanes::Pane *p : gone) _destroy(_pane(p));
      _detach(_pane(keep));
      while(GtkWidget *c = gtk_widget_get_first_child(_root))
        gtk_box_remove(GTK_BOX(_root), c);
      gtk_box_append(GTK_BOX(_root), _pane(keep)->area);
    };
    t.newWindow = [](GuiPanes::Pane *fresh) {
      GtkWidget *w = gtk_window_new();
      char title[64];
      snprintf(title, sizeof(title), "Gmsh - Graphic window %d",
               (int)_all().panes().size());
      gtk_window_set_title(GTK_WINDOW(w), title);
      gtk_window_set_default_size(GTK_WINDOW(w), 600, 500);
      gtk_window_set_child(GTK_WINDOW(w), _pane(fresh)->area);
      g_signal_connect(w, "close-request", G_CALLBACK(_windowClosed), nullptr);
      gtkWatchButtons(w);
      // the keys the view does not take are Gmsh's
      GtkEventController *keys = gtk_event_controller_key_new();
      g_signal_connect(keys, "key-pressed",
                       G_CALLBACK(+[](GtkEventControllerKey *, guint keyval,
                                      guint, GdkModifierType state,
                                      gpointer) -> gboolean {
                         return gtkMainKey(keyval, state);
                       }),
                       nullptr);
      gtk_widget_add_controller(w, keys);
      _pane(fresh)->top = w;
      gtk_window_present(GTK_WINDOW(w));
    };
    t.cursor = [](bool picking) {
      for(GuiPanes::Pane *p : _all().panes())
        gtk_widget_set_cursor_from_name(_pane(p)->area,
                                        picking ? "pointer" : nullptr);
    };
    t.clipboard = [](int w, int h, const std::vector<unsigned char> &rgba) {
      // the rows go bottom up
      std::vector<unsigned char> flipped(rgba.size());
      for(int y = 0; y < h; y++)
        memcpy(&flipped[(std::size_t)4 * w * y],
               &rgba[(std::size_t)4 * w * (h - 1 - y)], (std::size_t)4 * w);
      for(std::size_t i = 3; i < flipped.size(); i += 4) flipped[i] = 255;
      GBytes *bytes = g_bytes_new(flipped.data(), flipped.size());
      GdkTexture *texture = gdk_memory_texture_new(
        w, h, GDK_MEMORY_R8G8B8A8, bytes, (gsize)4 * w);
      g_bytes_unref(bytes);
      gdk_clipboard_set_texture(
        gdk_display_get_clipboard(gdk_display_get_default()), texture);
      g_object_unref(texture);
    };
    t.later = [](double seconds, std::function<void()> what) {
      g_timeout_add_full(G_PRIORITY_DEFAULT,
                         (guint)std::max(0., seconds * 1000.), _laterFired,
                         new std::function<void()>(what), _laterDropped);
    };
    t.buttonDown = []() { return gtkButtonDown(); };
    t.context = []() -> void * { return gdk_gl_context_get_current(); };
    t.screen = [](int &height, float &scale) {
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
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("gtk"); }
  };
  offering _offering;

} // namespace

// --- what the main window asks

GtkWidget *gtkSceneWidget()
{
  if(_root) return _root;
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  _root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_hexpand(_root, TRUE);
  gtk_widget_set_vexpand(_root, TRUE);
  g_object_ref(_root);
  gtk_box_append(GTK_BOX(_root), _pane(_all().start(_toolkit()))->area);
  return _root;
}

void gtkSceneRedraw() { _all().redrawAll(); }

bool gtkSceneDrawing() { return _all().drawing(); }

void gtkSceneSize(int &width, int &height)
{
  width = height = 0;
  for(GuiPanes::Pane *p : _all().panes())
    if(!p->window) {
      // the whole of the tiled panes
      width = gtk_widget_get_width(_root);
      height = gtk_widget_get_height(_root);
      return;
    }
}

void gtkSceneNewWindow() { _all().newWindow(); }

void gtkSceneDestroy()
{
  std::vector<GuiPanes::Pane *> panes = _all().panes();
  _all().stop();
  for(GuiPanes::Pane *p : panes) _destroy(_pane(p));
  if(_root) g_object_unref(_root);
  _root = nullptr;
}

void gtkSceneStartTimers() { _all().startTimers(); }
