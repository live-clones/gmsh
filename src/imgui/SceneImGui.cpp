// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The 3D scene of the Dear ImGui interface: what draws the model, and what one
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

#if defined(HAVE_IMGUI)

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

  // one warning per missing feature, so that a mesher loop cannot flood the
  // console
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

namespace Gui {

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
  void sceneKey(char key) {}

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

  void setMouseSelection(bool on)
  {
    double v = on ? 1. : 0.;
    NumberOption(GMSH_SET | GMSH_GUI, "General", 0, "MouseSelection", v, false);
  }

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
    if(!available()) return;
    sceneView *p = appWindow::instance()->currentPane();
    if(p) {
      p->quitSelection = 1;
      p->selectionMode = false;
    }
  }

  void setAddPointMode(bool on)
  {
    if(!available()) return;
    appWindow *app = appWindow::instance();
    for(int i = 0; i < app->numPanes(); i++)
      if(app->pane(i)) app->pane(i)->addPointMode = on;
  }

  // --- graphic windows

  drawContext *getCurrentDrawContext()
  {
    if(!available()) return nullptr;
    return appWindow::instance()->currentDrawContext();
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    if(available()) appWindow::instance()->currentPixelSize(width, height);
  }

  void setCurrentOpenglWindow(int which)
  {
    if(available()) appWindow::instance()->setCurrentPane(which);
  }

  void showAllInEveryWindow()
  {
    if(!available()) return;
    for(int i = 0; i < appWindow::instance()->numPanes(); i++)
      if(sceneView *pane = appWindow::instance()->pane(i))
        if(drawContext *ctx = pane->getDrawContext()) ctx->showAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    if(available()) appWindow::instance()->splitCurrentPane(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    _notImplemented("copy to clipboard");
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    if(!available()) return nullptr;
    appWindow *app = appWindow::instance();

    int width = 0, height = 0;
    app->currentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;

    // General.PrintWidth / General.PrintHeight override the size of the picture,
    // keeping the aspect ratio when only one of them is given
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
    buffer->fill(CTX::instance()->batch);
    app->endCapture();
    return buffer;
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    if(available()) appWindow::instance()->beginCapture(width, height, composite);
  }

  void endGraphicCapture()
  {
    if(available()) appWindow::instance()->endCapture();
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
    if(!available()) return 'q';
    sceneView *p = appWindow::instance()->currentPane();
    if(!p) return 'q';
    return p->selectEntity(type, _selectedVertices, _selectedEdges,
                           _selectedFaces, _selectedRegions, _selectedElements,
                           _selectedPoints, _selectedViews);
  }

  const std::vector<GVertex *> &selectedVertices() { return _selectedVertices; }
  const std::vector<GEdge *> &selectedEdges() { return _selectedEdges; }
  const std::vector<GFace *> &selectedFaces() { return _selectedFaces; }
  const std::vector<GRegion *> &selectedRegions() { return _selectedRegions; }
  const std::vector<MElement *> &selectedElements() { return _selectedElements; }
  const std::vector<SPoint2> &selectedPoints() { return _selectedPoints; }
  const std::vector<PView *> &selectedViews() { return _selectedViews; }

} // namespace Gui

#endif
