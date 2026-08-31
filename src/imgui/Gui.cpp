// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Dear ImGui / GLFW implementation of the toolkit-independent GUI interface
// declared in src/common/Gui.h. This is the only file of src/imgui that the
// rest of Gmsh links against.
//
// Work in progress: see src/imgui/README.txt for what is implemented and what
// still falls back to a warning.

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
#include "scenePane.h"
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

// --- the panels the menus show and hide

bool appWindow::panelVisible(int panel) const
{
  switch(panel) {
  case Gui::PanelOptions: return _showDialog[Dialog::Options];
  case Gui::PanelPlugins: return dialogVisible(Dialog::Plugins);
  case Gui::PanelVisibility: return dialogVisible(Dialog::Visibility);
  case Gui::PanelMessageConsole: return _showConsole;
  // the three windows of the Help menu are described like the other dialogs
  case Gui::PanelKeyboardAndMouse: return dialogVisible(Dialog::Shortcuts);
  case Gui::PanelCurrentOptions: return dialogVisible(Dialog::CurrentOptions);
  case Gui::PanelAbout: return dialogVisible(Dialog::About);
  case Gui::PanelFields: return dialogVisible(Dialog::Fields);
  case Gui::PanelClassify: return dialogVisible(Dialog::Classify);
  default: return false;
  }
}

void appWindow::showPanel(int panel, bool show)
{
  switch(panel) {
  case Gui::PanelOptions: _showDialog[Dialog::Options] = show; break;
  case Gui::PanelPlugins:
    // described like the other dialogs now
    if(show)
      Dialog::show(Dialog::Plugins, -1);
    else
      hideDialog(Dialog::Plugins);
    break;
  case Gui::PanelVisibility:
    // described like the other dialogs now
    if(show)
      Dialog::show(Dialog::Visibility, -1);
    else
      hideDialog(Dialog::Visibility);
    break;
  case Gui::PanelMessageConsole: _showConsole = show; break;
  case Gui::PanelKeyboardAndMouse:
  case Gui::PanelCurrentOptions:
  case Gui::PanelAbout: {
    int dialog = (panel == Gui::PanelKeyboardAndMouse) ? Dialog::Shortcuts :
                 (panel == Gui::PanelCurrentOptions)   ? Dialog::CurrentOptions :
                                                         Dialog::About;
    if(show)
      Dialog::show(dialog, -1);
    else
      hideDialog(dialog);
  } break;
  case Gui::PanelFields:
    // described like the other dialogs now
    if(show)
      Dialog::show(Dialog::Fields, -1);
    else
      hideDialog(Dialog::Fields);
    break;
  case Gui::PanelClassify:
    // described like the other dialogs now
    if(show)
      Dialog::startClassify();
    else
      hideDialog(Dialog::Classify);
    break;
  default: break;
  }
}

// What is left of the Dear ImGui adapter.
//
// Everything that is not a toolkit's is in src/common/Gui.cpp now, and what
// is goes through Ui::Backend. Two things are still here:
//
//   the 3D scene -- picking, the draw context, the capture, the windows the
//   views are drawn in -- which speaks Gmsh and is a chantier of its own,
//   declared in GuiScene.h;
//
//   and the two calls that wait on a file chooser that can name its formats:
//   exporting a view has to know which of the four flavours of ".pos" was
//   picked, and the entries of the File menu each open a chooser of their
//   own. Until the chooser can answer, both are written twice.
//
// When those two are done this file goes.

namespace Gui {

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

  void exportView(int index)
  {
#if defined(HAVE_POST)
    if(index < 0 || index >= (int)PView::list.size()) return;
    PView *view = PView::list[index];
    std::string name = view->getData()->getFileName();
    if(!appWindow::instance()->fileDialog(1, "Export view",
                                          "*.pos *.rmed *.stl *.txt", name))
      return;
    if(CTX::instance()->confirmOverwrite && !StatFile(name)) {
      std::string q = "File '" + name + "' already exists.\n\nDo you want to "
                      "replace it?";
      if(!Msg::GetAnswer(q.c_str(), 0, "Cancel", "Replace")) return;
    }
    // What PView::write() numbers the formats as. The window this reproduces
    // offers the four flavours of ".pos" as separate filters and reads the
    // one that was used; the file chooser here answers with a name, so the
    // extension is what says the format, and ".pos" means the parsed one.
    std::string ext = SplitFileName(name)[2];
    int format = (ext == ".rmed") ? 6 : (ext == ".stl") ? 3 :
                 (ext == ".txt")  ? 4 : 2;
    view->write(name, format);
#endif
  }

  void fileAction(const std::string &what)
  {
    if(!available()) return;
    appWindow *app = appWindow::instance();
    // they all open a dialog, so they run outside of the frame
    if(what == "new")
      app->postAction(fileNew);
    else if(what == "open")
      app->postAction([]() { fileOpen(false); });
    else if(what == "merge")
      app->postAction([]() { fileOpen(true); });
    else if(what == "rename")
      app->postAction(fileRename);
    else if(what == "export")
      app->postAction(fileExport);
    else if(what == "watch")
      app->postAction(Dialog::showWatchPattern);
    else if(what.compare(0, 7, "remote_") == 0) {
      std::string arg = what.substr(7);
      app->postAction([arg]() { fileRemote(arg); });
    }
    else
      Msg::Error("Unknown file action '%s'", what.c_str());
  }

  void abortSelection()
  {
    if(!available()) return;
    scenePane *p = appWindow::instance()->currentPane();
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
      if(scenePane *pane = appWindow::instance()->pane(i))
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
    scenePane *p = appWindow::instance()->currentPane();
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
