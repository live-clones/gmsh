// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The 3D scene of the FLTK interface: what draws the model, and what one
// picks in it.
//
// It is the whole of what is left outside src/common/Gui.cpp, and it is the
// only thing either interface still answers for itself. GuiScene.h says why:
// every one of these speaks Gmsh -- picking answers with model entities, the
// capture with a pixel buffer, the draw context is the drawing itself -- so
// none of it belongs in the toolkit contract of src/gui/Backend.h. It is a
// chantier of its own, to be rewritten rather than adapted, and until then it
// keeps the shape it has always had.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <FL/Fl.H>
#include <FL/fl_ask.H>

#include "Gui.h"
#include "FlGui.h"
#include <FL/fl_draw.H>
#include "extraDialogs.h"
#include "graphicWindow.h"
#include "sceneViewFltk.h"
#include "dialogFltk.h"
#include "onelabGroup.h"
#include "fileDialogs.h"
#include "Context.h"
#include "drawContext.h"
#include "drawContextFltk.h"
#include "drawContextFltkCairo.h"
#include "drawContextFltkStringTexture.h"
#include "PixelBuffer.h"
#include "OS.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

// defined in CreateFileFltk.cpp
PixelBuffer *GetCompositePixelBufferFltk(GLenum format, GLenum type);

// The 3D scene of the FLTK interface: what draws the model, and what one
// picks in it.
//
// It is the whole of what is left outside src/common/Gui.cpp, and it is the
// only thing either interface still answers for itself. GuiScene.h says why:
// every one of these speaks Gmsh -- picking answers with model entities, the
// capture with a pixel buffer, the draw context is the drawing itself -- so
// none of it belongs in the toolkit contract of src/gui/Backend.h. It is a
// chantier of its own, to be rewritten rather than adapted, and until then it
// keeps the shape it has always had.

namespace FltkScene {

  // this interface holds the scene inside its own windows and draws it in its
  // own loop; there is nothing to pump from outside, and nothing to send
  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always)
  {
    return "";
  }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  // every view hears it, as every view always has
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
    if(Gui::available()) fltkOrientViews(what, reverse, sync);
  }

  void setMouseSelection(bool on)
  {
    if(Gui::available()) fltkSetMouseSelection(on);
  }

  void toggleAnimation()
  {
    if(Gui::available()) fltkToggleAnimation();
  }

  bool animating() { return Gui::available() && fltkAnimating(); }

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
      // The engine that draws the text of the scene, swapped under the draw
      // context: FLTK's own, Cairo, or textures made of strings. It is done
      // whether or not a window is up yet, as it always was, since the
      // option is read before the first one is made.
      drawContextGlobal *old = drawContext::global();
      if(!old || old->getName() != CTX::instance()->glFontEngine) {
#if defined(HAVE_CAIRO)
        if(CTX::instance()->glFontEngine == "Cairo")
          drawContext::setGlobal(new drawContextFltkCairo);
        else
#endif
          if(CTX::instance()->glFontEngine == "StringTexture")
          drawContext::setGlobal(new drawContextFltkStringTexture);
        else
          drawContext::setGlobal(new drawContextFltk);
        if(old) delete old;
      }
      return;
    }
    if(!FlGui::available()) return;
    if(what == "background_image") {
      // the texture holding it is made from the file when it is next drawn
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->getDrawContext()
            ->invalidateBgImageTexture();
    }
    else if(what == "buffering") {
      int mode =
        FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
      if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->mode(mode);
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
    if(!Gui::available()) return;
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
    // the graphic window is a window of its own: making it current already puts
    // its origin at (0, 0)
  }

  void endGraphicCapture() {}

  // --- interactive selection

  char selectEntity(int type) { return FlGui::instance()->selectEntity(type); }

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


  // --- what the scene needs of whoever is holding it
  //
  // The other half of the port: the scene of src/scene is written to ask its
  // holder for the handful of things a window has and it has not, and this is
  // FLTK answering. Everything above is what the rest of Gmsh asks of the
  // scene; everything here is what the scene asks back.
  void installHost();

  void installHost()
  {
    Scene::Host held;
    // another picture is wanted: every window that shows one draws again,
    // which is what the draw context of this interface has always done
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
    held.tooltip = [](const std::string &text) {
      if(!FlGui::available()) return;
      if(sceneViewFltk *gl = FlGui::instance()->getCurrentOpenglWindow())
        gl->drawTooltip(text);
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
    Scene::setHost(held);
  }

// what this file answers for, said once and filled from the list in
// GuiSceneOps.h so that nothing here can be forgotten
namespace {
  struct offering {
    offering()
    {
      Gui::SceneOps ops;
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

// The scene is told who is holding it once the windows exist: see
// FltkScene::installHost().
void fltkInstallSceneHost() { FltkScene::installHost(); }


#endif
