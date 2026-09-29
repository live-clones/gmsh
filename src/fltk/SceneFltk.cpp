// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The scene of the FLTK interface, see GuiPanes.h: each view an Fl_Gl_Window,
// tiled in the Fl_Tile of the window it is in -- the main one, or a graphic
// window of its own with a bar of its own -- which split and unsplit alike;
// and the engines that write the strings of the scene.

#include "GmshConfig.h"

#include <algorithm>
#include <cstring>
#include <functional>
#include <map>

#include <FL/Fl.H>
#include <FL/Fl_Copy_Surface.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Tile.H>
#include <FL/fl_draw.H>
#include <FL/gl.h>
#if defined(WIN32)
#include <windows.h>
#endif

#include "fltkCommon.h"
#include "GuiPanes.h"
#include "sceneHost.h"
#include "sceneView.h"
#include "drawContext.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "stringQueue.h"
#include "Context.h"
#include "GmshMessage.h"

namespace {

  GuiPanes &_all() { return GuiPanes::instance(); }

  // --- a view: an Fl_Gl_Window, whose events are handed to it

  struct pane : public Fl_Gl_Window, public GuiPanes::Pane {
    // making an STL triangulation or a display list can pump the loop, which
    // would draw inside a draw; the same guard keeps GL_RENDER and GL_SELECT
    // apart
    bool drawing = false;
    Scene::Cursor cursorKind = Scene::Ordinary;

    pane(int x, int y, int w, int h) : Fl_Gl_Window(x, y, w, h, "gl")
    {
      end();
      mode(glMode());
    }
    ~pane() { _all().dropped(this); }

    // a core profile for the shader pipeline cannot share a context with the
    // fixed function one
    static int glMode()
    {
      int mode = FL_RGB | FL_DEPTH | FL_DOUBLE;
      if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
      if(CTX::instance()->stereo) mode |= FL_STEREO;
      if(CTX::instance()->shaders) mode |= FL_OPENGL3;
      return mode;
    }

    // in device pixels, not the logical ones w() and h() are in
    double factor() { return w() ? (double)pixel_w() / (double)w() : 1.; }

    void redraw()
    {
      view->redrawAsked();
      Fl_Gl_Window::redraw();
    }

    bool prepare()
    {
      if(!shown()) return false;
      make_current();
      glShader::setWindowFramebuffer(0);
      return true;
    }

    // not cursor(): Fl_Window has three, which an overload would hide
    void setCursor(Scene::Cursor kind)
    {
      if(kind == cursorKind) return;
      cursorKind = kind;
      // the hand says "this can be clicked"
      Fl_Gl_Window::cursor(kind == Scene::Picking ? FL_CURSOR_HAND :
                                                    FL_CURSOR_DEFAULT);
    }

    void draw() override
    {
      if(drawing) return;
      drawing = true;
      if(!context_valid()) view->contextChanged();
      _all().draw(this);
      drawing = false;
    }

    void keys()
    {
      modifiers(Fl::event_state(FL_SHIFT) ? true : false,
                Fl::event_state(FL_CTRL) ? true : false,
                Fl::event_state(FL_ALT) ? true : false,
                Fl::event_state(FL_META) ? true : false);
    }

    int handle(int event) override
    {
      // the scene numbers 0 left, 1 right, 2 middle; FLTK 1 left, 2 middle,
      // 3 right
      auto which = [](int button) {
        return button == 1 ? 0 : (button == 3 ? 1 : 2);
      };
      switch(event) {
      case FL_FOCUS: // accept the focus when asked whether it is wanted
      case FL_UNFOCUS: return 1;
      case FL_SHORTCUT:
      case FL_KEYBOARD:
        // as Alt and the wheel do: a trackpad has no notches
        if(Fl::event_state(FL_ALT) && CTX::instance()->mouseSelection &&
           !view->lasso() && !view->addPointMode &&
           (Fl::event_key() == FL_Up || Fl::event_key() == FL_Down)) {
          view->stepPick((Fl::event_key() == FL_Down) ? 1 : -1);
          return 1;
        }
        // before the widget navigation FLTK would do with the arrows
        if(fltkMainKey()) return 1;
        return Fl_Gl_Window::handle(event);
      case FL_LEAVE:
        left();
        return Fl_Gl_Window::handle(event);
      case FL_PUSH:
        take_focus(); // the keyboard follows the click
        keys();
        pressed(which(Fl::event_button()), Fl::event_x(), Fl::event_y(), 0.3);
        return 1;
      case FL_RELEASE:
        keys();
        released(which(Fl::event_button()), Fl::event_x(), Fl::event_y());
        return 1;
      case FL_DRAG:
      case FL_MOVE:
        keys();
        moved(Fl::event_x(), Fl::event_y());
        return 1;
      case FL_MOUSEWHEEL:
        keys();
        wheel(-Fl::event_dy(), Fl::event_x(), Fl::event_y());
        return 1;
      default: break;
      }
      return Fl_Gl_Window::handle(event);
    }
  };

  pane *_pane(GuiPanes::Pane *p) { return static_cast<pane *>(p); }

  // --- the windows of the views: the tile of each, and the graphic windows
  // of their own with their bar

  Fl_Tile *_main = nullptr;
  struct window {
    paletteWindow *win;
    Fl_Tile *tile;
    Fl_Group *bar;
  };
  std::vector<window> _windows;

  Fl_Tile *_tileOf(pane *p) { return p ? dynamic_cast<Fl_Tile *>(p->parent()) : nullptr; }

  void _closeWindow(Fl_Widget *w, void *)
  {
    for(std::size_t i = 0; i < _windows.size(); i++) {
      if(_windows[i].win != w) continue;
      window gone = _windows[i];
      _windows.erase(_windows.begin() + i);
      // the widgets are deleted later: the views go now
      for(int k = 0; k < gone.tile->children(); k++)
        if(pane *p = dynamic_cast<pane *>(gone.tile->child(k))) _all().dropped(p);
      fltkDropBar(gone.bar);
      gone.win->hide();
      Fl::delete_widget(gone.win);
      return;
    }
  }

  // every view, of every window
  void _everyView(const std::function<void(pane *)> &what)
  {
    for(GuiPanes::Pane *p : _all().panes()) what(_pane(p));
  }

  void _copy(int w, int h, const std::vector<unsigned char> &rgba)
  {
#if defined(WIN32)
    // a bitmap of Windows: bottom up, as the rows come, blue green red, each
    // row a multiple of 4 bytes
    int stride = (w * 3 + 3) & ~3;
    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE,
                              sizeof(BITMAPINFOHEADER) + (SIZE_T)stride * h);
    if(!mem) return;
    BITMAPINFOHEADER *bi = (BITMAPINFOHEADER *)GlobalLock(mem);
    memset(bi, 0, sizeof(*bi));
    bi->biSize = sizeof(*bi);
    bi->biWidth = w;
    bi->biHeight = h;
    bi->biPlanes = 1;
    bi->biBitCount = 24;
    bi->biCompression = BI_RGB;
    unsigned char *bits = (unsigned char *)(bi + 1);
    for(int y = 0; y < h; y++)
      for(int x = 0; x < w; x++) {
        const unsigned char *s = &rgba[((std::size_t)y * w + x) * 4];
        unsigned char *d = bits + (std::size_t)y * stride + 3 * x;
        d[0] = s[2];
        d[1] = s[1];
        d[2] = s[0];
      }
    GlobalUnlock(mem);
    if(OpenClipboard(nullptr)) {
      EmptyClipboard();
      SetClipboardData(CF_DIB, mem);
      CloseClipboard();
    }
    else
      GlobalFree(mem);
#elif FL_API_VERSION >= 10400
    // top down, red green blue
    std::vector<unsigned char> rgb((std::size_t)w * h * 3);
    for(int y = 0; y < h; y++)
      for(int x = 0; x < w; x++)
        for(int c = 0; c < 3; c++)
          rgb[((std::size_t)(h - 1 - y) * w + x) * 3 + c] =
            rgba[((std::size_t)y * w + x) * 4 + c];
    // drawn into the clipboard as into a window
    Fl_RGB_Image image(rgb.data(), w, h, 3);
    Fl_Copy_Surface *copy = new Fl_Copy_Surface(w, h);
    Fl_Surface_Device::push_current(copy);
    image.draw(0, 0);
    Fl_Surface_Device::pop_current();
    delete copy;
#else
    (void)w;
    (void)h;
    (void)rgba;
    Msg::Warning("Copying a picture needs FLTK 1.4 on this system");
#endif
  }

  GuiPanes::Toolkit _toolkit()
  {
    GuiPanes::Toolkit t;
    // the first view of a window is made with it; those of a split here,
    // outside of any group
    t.makePane = [](GuiPanes::Pane *from) -> GuiPanes::Pane * {
      if(!from) return nullptr;
      Fl_Group *current = Fl_Group::current();
      Fl_Group::current(nullptr);
      pane *p = new pane(0, 0, 1, 1);
      Fl_Group::current(current);
      return p;
    };
    t.redraw = [](GuiPanes::Pane *p) { _pane(p)->redraw(); };
    t.prepare = [](GuiPanes::Pane *p) { return _pane(p)->prepare(); };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      w = _pane(p)->w();
      h = _pane(p)->h();
      f = _pane(p)->factor();
    };
    // a view is a window of its own inside the window it is in
    t.origin = [](GuiPanes::Pane *p, int &x, int &y) {
      x = _pane(p)->x();
      y = _pane(p)->y();
    };
    t.drawNow = [](GuiPanes::Pane *p) {
      if(!_pane(p)->prepare()) return;
      _pane(p)->redraw();
      glFlush();
      fltkCheck();
    };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      pane *g = _pane(was);
      Fl_Tile *tile = _tileOf(g);
      if(!tile) return;
      double fact = std::min(.99, std::max(.01, ratio));
      int w1 = (how == 'h') ? (int)(g->w() * fact) : g->w();
      int h1 = (how == 'h') ? g->h() : (int)(g->h() * fact);
      int x2 = (how == 'h') ? (g->x() + w1) : g->x();
      int y2 = (how == 'h') ? g->y() : (g->y() + h1);
      int w2 = (how == 'h') ? (g->w() - w1) : g->w();
      int h2 = (how == 'h') ? g->h() : (g->h() - h1);
      g->resize(g->x(), g->y(), w1, h1);
      _pane(fresh)->resize(x2, y2, w2, h2);
      tile->add(_pane(fresh));
      tile->init_sizes();
      _pane(fresh)->show();
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      Fl_Tile *tile = _tileOf(_pane(keep));
      if(!tile) return;
      for(GuiPanes::Pane *p : gone) {
        tile->remove(_pane(p));
        Fl::delete_widget(_pane(p));
      }
      _pane(keep)->resize(tile->x(), tile->y(), tile->w(), tile->h());
      tile->init_sizes();
      tile->redraw();
    };
    t.newWindow = [](GuiPanes::Pane *fresh) {
      Fl_Window *main = fltkMainWindow();
      int w = main ? main->w() : 600, h = main ? main->h() : 500;
      int bh = fltkBarHeight();
      Fl_Group *current = Fl_Group::current();
      Fl_Group::current(nullptr);
      window made;
      made.win = new paletteWindow(w, h, false);
      made.tile = new Fl_Tile(0, 0, w, h - bh);
      made.tile->end();
      made.bar = fltkMakeBar(0, h - bh, w, bh);
      made.win->end();
      made.win->resizable(made.tile);
      made.win->callback(_closeWindow);
      Fl_Group::current(current);
      pane *p = _pane(fresh);
      p->resize(0, 0, w, h - bh);
      made.tile->add(p);
      made.tile->init_sizes();
      _windows.push_back(made);
      const char *first = main ? main->label() : nullptr;
      made.win->copy_label((std::string(first ? first : "Gmsh") + " [" +
                            std::to_string(_windows.size()) + "]")
                             .c_str());
      if(main) made.win->position(main->x() + 10 * (int)_windows.size(),
                                  main->y() + 10 * (int)_windows.size());
      made.win->show();
      // made outside of any group, it is a window of its own until shown in
      // the one it is in
      p->show();
    };
    t.splitsWindows = true;
    t.cursor = [](bool picking) {
      _everyView([picking](pane *g) {
        g->setCursor(picking ? Scene::Picking : Scene::Ordinary);
      });
    };
    t.clipboard = _copy;
    t.later = [](double seconds, std::function<void()> what) {
      std::function<void()> *kept = new std::function<void()>(what);
      Fl::add_timeout(
        seconds,
        [](void *data) {
          std::function<void()> *fn = (std::function<void()> *)data;
          (*fn)();
          delete fn;
        },
        kept);
    };
    t.buttonDown = []() { return fltkButtonDown(); };
    t.context = []() -> void * {
      GuiPanes::Pane *p = _all().current();
      return p ? (void *)_pane(p)->context() : nullptr;
    };
    // every view: drawn, and its camera said
    t.redrawAll = []() {
      _everyView([](pane *g) {
        if(!g->shown()) return;
        g->make_current();
        g->redraw();
        glFlush();
        // FIXME: I don't think this should be done here
        g->view->getDrawContext()->camera.update();
      });
    };
    t.screen = [](int &height, float &scale) {
      // the main (first) screen
      float dpih = 96.f, dpiv = 96.f;
      Fl::screen_dpi(dpih, dpiv);
      height = Fl::h();
      scale = dpih / 96.f;
    };
    // the native font engine places its strings from the window's size and
    // scale, which a picture of another size has neither of: the embedded
    // fonts meanwhile
    t.printFonts = []() -> drawContextGlobal * {
      if(drawContext::global()->getName() != "Fltk") return nullptr;
      static bool warned = false;
      if(!warned)
        Msg::Warning("Font engine 'Native' cannot draw pictures of another "
                     "size than the window: using 'Embedded' for them");
      warned = true;
      return new drawContextGL;
    };
    t.surfaceFonts = []() { return drawContext::global()->getName() == "Fltk"; };
    t.setting = [](const std::string &what) {
      if(what == "font_engine")
        fltkFontEngine();
      else if(what == "buffering" || what == "shaders") {
        int mode = pane::glMode();
        _everyView([mode](pane *g) { g->mode(mode); });
      }
    };
    t.statusChanged = []() { fltkRefreshBar(); };
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("fltk"); }
  };
  offering _offering;

  // --- the engines that write the strings of the scene

  // the Native engine: the strings drawn by FLTK at the raster position, which
  // only the fixed function pipeline has; what is drawn is the scene host's
  class drawContextFltk : public drawContextHosted {
  public:
    void setFont(int fontid, int fontsize) { gl_font(fontid, fontsize); }
    double getStringWidth(const char *str) { return gl_width(str); }
    int getStringHeight() { return gl_height(); }
    int getStringDescent() { return gl_descent(); }
    void drawString(const char *str)
    {
      if(!stringHalo()) {
        gl_draw(str);
        return;
      }
      // eight copies around it in the background colour first, the raster
      // position moved by a pixel each time (an empty bitmap moves it) and
      // brought back after each, as drawing advances it
      GLfloat pos[4], color[4];
      glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
      glGetFloatv(GL_CURRENT_COLOR, color);
      unsigned int bg = CTX::instance()->color.bg;
      glColor4ub(CTX::instance()->unpackRed(bg), CTX::instance()->unpackGreen(bg),
                 CTX::instance()->unpackBlue(bg), 255);
      for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
          if(!i && !j) continue;
          glBitmap(0, 0, 0.f, 0.f, (GLfloat)i, (GLfloat)j, nullptr);
          gl_draw(str);
          GLfloat now[4];
          glGetFloatv(GL_CURRENT_RASTER_POSITION, now);
          glBitmap(0, 0, 0.f, 0.f, pos[0] - now[0], pos[1] - now[1], nullptr);
        }
      glColor4fv(color);
      gl_draw(str);
    }
  // FLTK draws a string as a texture, kept in a pile of a fixed height, from
  // 1.4 on and on macOS before that; the pile is where the three calls below
  // go, and where they do nothing at all otherwise
#if((FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)) || defined(__APPLE__)
#define GMSH_FLTK_STRING_TEXTURES 1
#endif

    bool keepsStringTextures()
    {
#if defined(GMSH_FLTK_STRING_TEXTURES)
      return true;
#else
      return false;
#endif
    }
    void resetFontTextures()
    {
#if defined(GMSH_FLTK_STRING_TEXTURES)
      // the strings are drawn again: their textures are made again with them
      gl_texture_pile_height(gl_texture_pile_height());
#endif
    }
    void reserveStringTextures(std::size_t n)
    {
#if defined(GMSH_FLTK_STRING_TEXTURES)
      if(gl_texture_pile_height() < (int)n) gl_texture_pile_height((int)n);
#else
      (void)n;
#endif
    }
    std::string getName() { return "Fltk"; }
  };

  // The font engines that draw strings as textured quads, from the atlas of a
  // stringQueue given by the engine
  class drawContextFltkQueued : public drawContextFltk {
  protected:
    stringQueue *_strings;
    int _currentFontId = -1, _currentFontSize = 0;

  public:
    drawContextFltkQueued(stringQueue *strings) : _strings(strings) {}
    ~drawContextFltkQueued() { delete _strings; }
    void flushString()
    {
      // measuring the strings sets their fonts: the caller's comes back
      int fontId = _currentFontId, fontSize = _currentFontSize;
      _strings->flush(pixelFactor());
      if(fontId >= 0) {
        _currentFontId = -1;
        setFont(fontId, fontSize);
      }
    }
    void drawString(const char *str)
    {
      GLfloat pos[4];
      glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
      double win[3] = {pos[0], pos[1], pos[2]};
      drawString(str, win);
    }
    void drawString(const char *str, const double win[3])
    {
      _strings->add(str, win, _currentFontId, _currentFontSize, stringHalo());
    }
    void setFont(int fontid, int fontsize)
    {
      drawContextFltk::setFont(fontid, fontsize);
      _currentFontId = fontid;
      _currentFontSize = fontsize;
    }
    // The strings of this engine live in its own atlas, which grows as it
    // needs to: FLTK's pile of one texture per string is never used (they are
    // rasterised into an image), so there is nothing to size for the frame.
    // The atlas holds one channel and the colour is the quad's, so a colour
    // change costs it nothing either.
    bool keepsStringTextures() { return false; }
    void resetFontTextures() {}
    void reserveStringTextures(std::size_t n) {}
  };

  // the strings rasterised by FLTK in an offscreen image
  class fltkStrings : public stringQueue {
  protected:
    char engine() { return 'T'; }
    extent measure(const element &e, double f);
    void rasterise(const std::vector<slot> &slots, double f, int w, int h,
                   unsigned char *image);
  };

  class drawContextFltkStringTexture : public drawContextFltkQueued {
  public:
    drawContextFltkStringTexture() : drawContextFltkQueued(new fltkStrings) {}
    std::string getName() { return "StringTexture"; }
  };

  // the size of the string, measured at its size in the window's units as the
  // other engines do, and the baseline its descent (at the rasterised size)
  // above the bottom: the quad is lowered by as much, so that the anchor is on
  // the baseline
  stringQueue::extent fltkStrings::measure(const element &e, double f)
  {
    gl_font(e.fontId, e.fontSize);
    double width = gl_width(e.text.c_str()) + 1;
    int height = gl_height();
    fl_font(e.fontId, (int)(e.fontSize * f));
    int h = (int)(height * f);
    int descent = fl_descent();
    return {(int)(width * f), h, descent, 0., (double)(h - descent)};
  }

  void fltkStrings::rasterise(const std::vector<slot> &slots, double f, int w,
                              int h, unsigned char *image)
  {
    Fl_Offscreen offscreen = fl_create_offscreen(w, h);
    fl_begin_offscreen(offscreen);
    fl_color(0, 0, 0);
    fl_rectf(0, 0, w, h);
    fl_color(255, 255, 255);
    for(const slot &s : slots) {
      fl_push_clip(s.x, s.y, s.w, s.h);
      fl_font(s.e->fontId, (int)(s.e->fontSize * f));
      fl_draw(s.e->text.c_str(), (int)(s.x - s.shift + s.ext.penX),
              (int)(s.y + s.ext.penY));
      fl_pop_clip();
    }
    uchar *data = fl_read_image(nullptr, 0, 0, w, h);
    fl_end_offscreen();
    fl_delete_offscreen(offscreen);
    for(int i = 0; i < w * h; i++) image[i] = data[3 * i];
    delete[] data;
  }

} // namespace

// the text engine, swapped under the draw context before the first window is
// made; the native one draws at the raster position, which a core profile has
// none of
void fltkFontEngine()
{
  std::string engine = CTX::instance()->glFontEngine;
  if(CTX::instance()->shaders && engine == "Native") {
    Msg::Warning("Font engine 'Native' needs the fixed function pipeline "
                 "(General.Shaders = 0): using 'Embedded'");
    engine = "Embedded";
  }
  drawContextGlobal *old = drawContext::global();
  if(!old || old->getName() != engine) {
    if(engine == "StringTexture")
      drawContext::setGlobal(new drawContextFltkStringTexture);
    else if(engine == "Native")
      drawContext::setGlobal(new drawContextFltk);
    else
      drawContext::setGlobal(new drawContextGL);
    if(old) delete old;
  }
}

void fltkSceneStart() { _all().start(_toolkit()); }

void fltkSceneStop()
{
  std::vector<window> windows = _windows;
  for(const window &w : windows) _closeWindow(w.win, nullptr);
  _all().stop();
  _main = nullptr;
}

Fl_Group *fltkSceneBox(int x, int y, int w, int h)
{
  _main = new Fl_Tile(x, y, w, h);
  pane *first = new pane(x, y, w, h);
  _main->end();
  _all().adopt(first, nullptr);
  return _main;
}

void fltkSceneSize(int &width, int &height)
{
  width = _main ? _main->w() : 0;
  height = _main ? _main->h() : 0;
}

void fltkSceneFocus()
{
  if(GuiPanes::Pane *p = _all().current()) Fl::focus(_pane(p));
}

void fltkSceneNewWindow() { _all().newWindow(); }

void fltkSceneWindows(bool show)
{
  for(const window &w : _windows) {
    if(show)
      w.win->show();
    else
      w.win->iconize();
  }
}
