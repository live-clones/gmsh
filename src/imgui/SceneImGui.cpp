// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Dear ImGui interface, see GuiScene.h

#include "GmshConfig.h"

#include <cstdio>
#include <set>
#include <string>

#include "imgui.h"
#include <GLFW/glfw3.h>

#include "Gui.h"
#include "appWindow.h"
#include "toolkit.h"
#include "menuActions.h"
#include "GuiMenus.h"
#include "sceneView.h"
#include "messageConsole.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "drawContext.h"
#include "GuiActions.h"
#include "PixelBuffer.h"
#include "OS.h"
#include "Options.h"
#include "CommandLine.h"
#include "StringUtils.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

namespace {

  // one warning per missing feature
  void _notImplemented(const char *what)
  {
    static std::set<std::string> warned;
    if(warned.insert(what).second)
      Msg::Info("'%s' is not implemented yet in the ImGui interface", what);
  }

  std::vector<GVertex *> _selectedVertices;
  std::vector<GEdge *> _selectedEdges;
  std::vector<GFace *> _selectedFaces;
  std::vector<GRegion *> _selectedRegions;
  std::vector<MElement *> _selectedElements;
  std::vector<SPoint2> _selectedPoints;
  std::vector<PView *> _selectedViews;

} // namespace

namespace ImGuiScene {

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
    if(!appWindow::available()) return false;
    bool taken = false;
    appWindow *app = appWindow::instance();
    for(int i = 0; i < app->numPanes(); i++)
      if(app->pane(i) && app->pane(i)->key(key)) taken = true;
    return taken;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    if(!appWindow::available()) return;
    sceneView *p = appWindow::instance()->currentPane();
    if(!p) return;
    p->screenMessage[0] = first;
    p->screenMessage[1] = second;
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
    appWindow *a = appWindow::instance();
    if(!a) return;
    a->orientPanes(what, reverse, sync);
  }

  // the panes have no pointer of their own to put back
  void setMouseSelection(bool on) {}

  void toggleAnimation()
  {
    if(appWindow::instance()) appWindow::instance()->toggleAnimation();
  }

  bool animating()
  {
    return appWindow::instance() && appWindow::instance()->animating();
  }

  void abortSelection()
  {
    if(!Gui::instance().available()) return;
    sceneView *p = appWindow::instance()->currentPane();
    if(p) {
      p->quitSelection = 1;
      p->selectionMode = false;
    }
  }

  void setAddPointMode(bool on)
  {
    if(!Gui::instance().available()) return;
    appWindow *app = appWindow::instance();
    for(int i = 0; i < app->numPanes(); i++)
      if(app->pane(i)) app->pane(i)->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(!Gui::instance().available()) return;
    if(what == "background_image") {
      appWindow *app = appWindow::instance();
      for(int i = 0; i < app->numPanes(); i++)
        if(app->pane(i) && app->pane(i)->getDrawContext())
          app->pane(i)->getDrawContext()->invalidateBgImageTexture();
    }
  }

  // --- graphic windows

  drawContext *getCurrentDrawContext()
  {
    if(!Gui::instance().available()) return nullptr;
    return appWindow::instance()->currentDrawContext();
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    if(Gui::instance().available()) appWindow::instance()->currentPixelSize(width, height);
  }

  void setCurrentOpenglWindow(int which)
  {
    if(Gui::instance().available()) appWindow::instance()->setCurrentPane(which);
  }

  void showAllInEveryWindow()
  {
    if(!Gui::instance().available()) return;
    for(int i = 0; i < appWindow::instance()->numPanes(); i++)
      if(sceneView *pane = appWindow::instance()->pane(i))
        if(drawContext *ctx = pane->getDrawContext()) ctx->showAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    if(Gui::instance().available()) appWindow::instance()->splitCurrentPane(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    _notImplemented("copy to clipboard");
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    if(!Gui::instance().available()) return nullptr;
    appWindow *app = appWindow::instance();

    int width = 0, height = 0;
    app->currentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;

    // the aspect ratio is kept when only one of General.PrintWidth and
    // PrintHeight is given
    if(CTX::instance()->print.width > 0 || CTX::instance()->print.height > 0) {
      if(CTX::instance()->print.width <= 0) {
        width = (int)(width * CTX::instance()->print.height / (double)height);
        height = CTX::instance()->print.height;
      }
      else if(CTX::instance()->print.height <= 0) {
        height = (int)(height * CTX::instance()->print.width / (double)width);
        width = CTX::instance()->print.width;
      }
      else {
        width = CTX::instance()->print.width;
        height = CTX::instance()->print.height;
      }
    }

    app->beginCapture(width, height,
                      CTX::instance()->print.compositeWindows ? true : false);
    PixelBuffer *buffer =
      new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    buffer->fill();
    app->endCapture();
    return buffer;
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    if(Gui::instance().available()) appWindow::instance()->beginCapture(width, height, composite);
  }

  void endGraphicCapture()
  {
    if(Gui::instance().available()) appWindow::instance()->endCapture();
  }

  // --- interactive selection

  char selectEntity(int type)
  {
    _selectedVertices.clear();
    _selectedEdges.clear();
    _selectedFaces.clear();
    _selectedRegions.clear();
    _selectedElements.clear();
    _selectedPoints.clear();
    _selectedViews.clear();
    if(!Gui::instance().available()) return 'q';
    sceneView *p = appWindow::instance()->currentPane();
    if(!p) return 'q';
    return p->selectEntity(type, _selectedVertices, _selectedEdges,
                           _selectedFaces, _selectedRegions, _selectedElements,
                           _selectedPoints, _selectedViews);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!Gui::instance().available()) return false;
    sceneView *p = appWindow::instance()->currentPane();
    if(!p) return false;
    return p->printTo(width, height, supersampling, format, type, pixels);
  }

  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    _selectedVertices.clear();
    _selectedEdges.clear();
    _selectedFaces.clear();
    _selectedRegions.clear();
    _selectedElements.clear();
    _selectedPoints.clear();
    _selectedViews.clear();
    if(!Gui::instance().available()) return false;
    sceneView *p = appWindow::instance()->currentPane();
    if(!p) return false;
    // the pane counts from its corner
    return p->pick(type, mesh, post, x - p->x(), y - p->y(), w, h,
                   _selectedVertices, _selectedEdges, _selectedFaces,
                   _selectedRegions, _selectedElements, _selectedPoints,
                   _selectedViews);
  }

  const std::vector<GVertex *> &selectedVertices() { return _selectedVertices; }
  const std::vector<GEdge *> &selectedEdges() { return _selectedEdges; }
  const std::vector<GFace *> &selectedFaces() { return _selectedFaces; }
  const std::vector<GRegion *> &selectedRegions() { return _selectedRegions; }
  const std::vector<MElement *> &selectedElements() { return _selectedElements; }
  const std::vector<SPoint2> &selectedPoints() { return _selectedPoints; }
  const std::vector<PView *> &selectedViews() { return _selectedViews; }


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
      Gui::offerScene("imgui", ops);
    }
  };
  offering _offering;
}
} // namespace ImGuiScene

// --- the two things the bar asks of the scene, which are the scene's: orienting the draw context of every pane, and stepping the animation

// the panes of the graphic window
void appWindow::orientPanes(const std::string &what, bool reverse, bool sync)
{
  std::vector<sceneView *> panes;
  for(auto *p : _panes)
    if(_isTiled(p)) panes.push_back(p);
  if(panes.empty()) {
    if(sceneView *p = currentPane()) panes.push_back(p);
  }
  Scene::orientViews(panes, what, reverse, sync);
}

// from the frame loop: a frame is not re-entrant; whether it is time is
// animationTick()'s
void appWindow::_stepAnimation()
{
  if(_animating) animationTick();
}
