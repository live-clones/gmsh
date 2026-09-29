// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


#include "GmshConfig.h"

#include <FL/Fl.H>
#include <FL/fl_ask.H>

#include "Gui.h"
#include "GuiActions.h"
#include "FlGui.h"
#include <FL/fl_draw.H>
#include "extraDialogs.h"
#include "graphicWindow.h"
#include "sceneViewFltk.h"
#include "dialogFltk.h"
#include "onelabGroup.h"
#include "fileDialogs.h"
#include "Context.h"
#include "GmshMessage.h"
#include "drawContext.h"
#include "drawContextFltk.h"
#include "drawContextFltkStringTexture.h"
#include "drawContextFltkEmbedded.h"
#include "PixelBuffer.h"
#include "OS.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

PixelBuffer *GetCompositePixelBufferFltk(GLenum format, GLenum type);

// the scene of the FLTK interface, see GuiScene.h

namespace FltkScene {

  // the scene is in the interface's own windows: nothing to pump, nothing to
  // send
  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always)
  {
    return "";
  }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  bool sceneKey(char key)
  {
    bool taken = false;
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        if(FlGui::instance()->graph[i]->gl[j]->scene()->key(key)) taken = true;
    return taken;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    if(!FlGui::available()) return;
    sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(!gl) return;
    gl->scene()->screenMessage[0] = first;
    gl->scene()->screenMessage[1] = second;
  }
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
  }


  // --- messages, status bar and modal dialogs

  // --- refreshing the GUI when the model changes

  // --- modules, tree and context windows

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    if(Gui::instance().available()) fltkOrientViews(what, reverse, sync);
  }

  void setMouseSelection(bool on)
  {
    if(Gui::instance().available()) fltkSetMouseSelection(on);
  }

  // the animation runs a loop of its own; whether it is time for the next step
  // is animationTick()'s
  bool _playing = false, _stop = false;

  bool animating() { return _playing; }

  void toggleAnimation()
  {
    if(!Gui::instance().available()) return;
    if(_playing) {
      _stop = true;
      return;
    }
    _playing = true;
    _stop = false;
    while(1) {
      if(!FlGui::available()) return;
      if(_stop) break;
      animationTick();
      FlGui::check();
    }
    _playing = false;
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->refreshStatusButtons();
  }

  void abortSelection()
  {
    sceneViewFltk *w = FlGui::instance()->getCurrentOpenglWindow();
    if(w) {
      w->scene()->quitSelection = 1;
      w->scene()->selectionMode = false;
    }
  }

  void setAddPointMode(bool on)
  {
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->scene()->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(what == "font_engine") {
      // the text engine, swapped under the draw context before the first window
      // is made; the native one draws at the raster position, which a core
      // profile has none of
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
      return;
    }
    if(!FlGui::available()) return;
    if(what == "background_image") {
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->getDrawContext()
            ->invalidateBgImageTexture();
    }
    else if(what == "buffering" || what == "shaders") {
      int mode = sceneViewFltk::glMode();
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->mode(mode);
      if(FlGui::instance()->fullscreen) FlGui::instance()->fullscreen->mode(mode);
    }
  }

  // --- graphic windows

  drawContext *getCurrentDrawContext()
  {
    return FlGui::instance()->getCurrentDrawContext();
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
    width = gl->pixel_w();
    height = gl->pixel_h();
  }

  void setCurrentOpenglWindow(int which)
  {
    FlGui::instance()->setCurrentOpenglWindow(which);
  }

  void showAllInEveryWindow()
  {
    if(!Gui::instance().available()) return;
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->getDrawContext()->showAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    FlGui::instance()->splitCurrentOpenglWindow(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    FlGui::instance()->copyCurrentOpenglWindowToClipboard();
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format, unsigned int type)
  {
    return GetCompositePixelBufferFltk((GLenum)format, (GLenum)type);
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    // making the window current puts its origin at (0, 0)
  }

  void endGraphicCapture() {}

  // --- interactive selection

  char selectEntity(int type) { return FlGui::instance()->selectEntity(type); }
  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    return FlGui::instance()->pickAt(type, mesh, post, x, y, w, h);
  }
  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(!gl || !gl->scene()) return false;
    return gl->scene()->printTo(width, height, supersampling, format, type,
                                pixels);
  }

  const std::vector<GVertex *> &selectedVertices()
  {
    return FlGui::instance()->selectedVertices;
  }
  const std::vector<GEdge *> &selectedEdges()
  {
    return FlGui::instance()->selectedEdges;
  }
  const std::vector<GFace *> &selectedFaces()
  {
    return FlGui::instance()->selectedFaces;
  }
  const std::vector<GRegion *> &selectedRegions()
  {
    return FlGui::instance()->selectedRegions;
  }
  const std::vector<MElement *> &selectedElements()
  {
    return FlGui::instance()->selectedElements;
  }
  const std::vector<SPoint2> &selectedPoints()
  {
    return FlGui::instance()->selectedPoints;
  }
  const std::vector<PView *> &selectedViews()
  {
    return FlGui::instance()->selectedViews;
  }


  // --- what the scene asks of whoever holds it: FLTK answering
  void installHost();

  void installHost()
  {
    Scene::Host held;
    held.redraw = []() { drawContext::global()->draw(); };
    held.check = [](bool rateLimited) { FlGui::check(rateLimited); };
    held.wait = [](double seconds, bool force) {
      if(seconds < 0.)
        FlGui::wait(force);
      else
        FlGui::wait(seconds, force);
    };
    held.drawCurrent = []() {
      drawContext::global()->drawCurrentOpenglWindow(true);
    };
    held.uiScale = []() -> float {
      if(!FlGui::available()) return 1.f;
      sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
      return gl ? (float)gl->pixelFactor() : 1.f;
    };
    held.numViews = []() {
      if(!FlGui::available()) return 0;
      int n = 0;
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        n += (int)FlGui::instance()->graph[i]->gl.size();
      return n;
    };
    held.cursor = [](Scene::Cursor kind) {
      if(!FlGui::available()) return;
      if(sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow())
        gl->setCursor(kind);
    };
    held.current = []() -> sceneView * {
      if(!FlGui::available()) return nullptr;
      sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
      return gl ? gl->scene() : nullptr;
    };
    held.setCurrent = [](sceneView *view) {
      if(sceneViewFltk *gl = sceneViewFltk::holding(view))
        sceneViewFltk::setLastHandled(gl);
    };
    held.redrawView = [](sceneView *view) {
      if(sceneViewFltk *gl = sceneViewFltk::holding(view)) gl->redraw();
    };
    held.later = [](double seconds, std::function<void()> what) {
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
    held.buttonDown = []() { return Fl::pushed() != nullptr; };
    held.context = []() -> void * {
      if(!FlGui::available()) return nullptr;
      sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow();
      return gl ? (void *)gl->context() : nullptr;
    };
    held.makeCurrent = [](sceneView *view) {
      if(sceneViewFltk *gl = sceneViewFltk::holding(view)) gl->make_current();
    };
    // the native font engine places its strings from the window's size and
    // scale, which the picture has neither of: the embedded fonts meanwhile
    held.printFonts = []() -> drawContextGlobal * {
      if(drawContext::global()->getName() != "Fltk") return nullptr;
      static bool warned = false;
      if(!warned)
        Msg::Warning("Font engine 'Native' cannot draw pictures of another "
                     "size than the window: using 'Embedded' for them");
      warned = true;
      return new drawContextFltkEmbedded;
    };
    Scene::setHost(held);
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
      Gui::offerScene("fltk", ops);
    }
  };
  offering _offering;
}
} // namespace FltkScene

// see FltkScene::installHost()
void fltkInstallSceneHost() { FltkScene::installHost(); }
