// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the FLTK interface, see GuiPanes.h: each view an Fl_Gl_Window,
// tiled in the Fl_Tile of a graphic window; every graphic window, the main one
// and those "New Window" opens, a window of views of its own, which split and
// unsplit as the main one does

#include "GmshConfig.h"

#include <cstring>
#include <functional>

#include <FL/Fl.H>
#include <FL/Fl_Copy_Surface.H>
#include <FL/Fl_Image.H>
#if defined(WIN32)
#include <windows.h>
#endif

#include "Gui.h"
#include "GuiPanes.h"
#include "FlGui.h"
#include "graphicWindow.h"
#include "sceneViewFltk.h"
#include "Context.h"
#include "GmshMessage.h"
#include "drawContext.h"
#include "drawContextFltk.h"
#include "drawContextFltkStringTexture.h"
#include "drawContextFltkEmbedded.h"

namespace {

  GuiPanes &_all() { return GuiPanes::instance(); }

  sceneViewFltk *_view(GuiPanes::Pane *p)
  {
    return static_cast<sceneViewFltk *>(p);
  }

  graphicWindow *_holding(sceneViewFltk *g)
  {
    if(!FlGui::available()) return nullptr;
    for(graphicWindow *w : FlGui::instance()->graph)
      for(sceneViewFltk *one : w->gl)
        if(one == g) return w;
    return nullptr;
  }

  // the views of every window, the one full screen included
  void _everyView(const std::function<void(sceneViewFltk *)> &what)
  {
    for(GuiPanes::Pane *p : _all().panes()) what(_view(p));
    if(FlGui::available() && FlGui::instance()->fullscreen &&
       !_all().paneOf(FlGui::instance()->fullscreen->scene()))
      what(FlGui::instance()->fullscreen);
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
    // the views of a graphic window are made with it (see graphicWindow),
    // those of a split here, outside of any group
    t.makePane = [](GuiPanes::Pane *from) -> GuiPanes::Pane * {
      if(!from) return nullptr;
      Fl_Group *current = Fl_Group::current();
      Fl_Group::current(nullptr);
      sceneViewFltk *g = new sceneViewFltk(0, 0, 1, 1);
      g->end();
      g->mode(_view(from)->mode());
      Fl_Group::current(current);
      return g;
    };
    t.redraw = [](GuiPanes::Pane *p) { _view(p)->redraw(); };
    t.prepare = [](GuiPanes::Pane *p) { return _view(p)->prepare(); };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      w = _view(p)->w();
      h = _view(p)->h();
      f = _view(p)->pixelFactor();
    };
    // a view is a window of its own inside its graphic window
    t.origin = [](GuiPanes::Pane *p, int &x, int &y) {
      x = _view(p)->x();
      y = _view(p)->y();
    };
    t.drawNow = [](GuiPanes::Pane *p) {
      if(!_view(p)->prepare()) return;
      _view(p)->redraw();
      glFlush();
      FlGui::check();
    };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      if(graphicWindow *w = _holding(_view(was)))
        w->split(_view(was), _view(fresh), how, ratio);
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      std::vector<sceneViewFltk *> views;
      for(GuiPanes::Pane *p : gone) views.push_back(_view(p));
      if(graphicWindow *w = _holding(_view(keep)))
        w->unsplit(_view(keep), views);
    };
    t.splitsWindows = true;
    t.cursor = [](bool picking) {
      _everyView([picking](sceneViewFltk *g) {
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
    t.buttonDown = []() { return Fl::pushed() != nullptr; };
    t.context = []() -> void * {
      if(!FlGui::available()) return nullptr;
      sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
      return gl ? (void *)gl->context() : nullptr;
    };
    t.redrawAll = []() { drawContext::global()->draw(); };
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
      return new drawContextFltkEmbedded;
    };
    t.surfaceFonts = []() { return drawContext::global()->getName() == "Fltk"; };
    t.setting = [](const std::string &what) {
      if(what == "font_engine")
        fltkFontEngine();
      else if(what == "buffering" || what == "shaders") {
        int mode = sceneViewFltk::glMode();
        _everyView([mode](sceneViewFltk *g) { g->mode(mode); });
      }
    };
    t.statusChanged = []() {
      if(!FlGui::available()) return;
      for(graphicWindow *w : FlGui::instance()->graph)
        w->refreshStatusButtons();
    };
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("fltk"); }
  };
  offering _offering;

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
    else if(engine == "Embedded")
      drawContext::setGlobal(new drawContextFltkEmbedded);
    else
      drawContext::setGlobal(new drawContextFltk);
    if(old) delete old;
  }
}

// the scene is told who holds it before the first window is made
void fltkSceneStart() { _all().start(_toolkit()); }

void fltkSceneStop() { _all().stop(); }
