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

  // --- life cycle

  bool available() { return appWindow::available(); }

  void create(int argc, char **argv, bool quitShouldExit,
              void (*errorHandler)(const char *fmt, ...))
  {
    if(!appWindow::available()) appWindow::instance(argc, argv, quitShouldExit);
  }

  void destroy() { appWindow::destroy(); }

  int run(const std::string &optionFileName)
  {
    if(!available()) return 0;
    return appWindow::instance()->run(optionFileName);
  }

  void copyText(const std::string &text)
  {
    ImGui::SetClipboardText(text.c_str());
  }

  std::string toolkitVersion()
  {
    std::string s = "Dear ImGui ";
    s += IMGUI_VERSION;
    s += ", GLFW ";
    s += glfwGetVersionString();
    return s;
  }

  // --- event pumping

  void check(bool rateLimited)
  {
    if(available()) appWindow::instance()->check(rateLimited);
  }

  bool ready() { return available() && appWindow::instance()->ready(); }

  void wait(bool force)
  {
    if(available()) appWindow::instance()->wait(force);
  }

  void wait(double time, bool force)
  {
    if(available()) appWindow::instance()->wait(time, force);
  }

  void lock() { appWindow::lock(); }
  void unlock() { appWindow::unlock(); }
  int locked() { return appWindow::locked(); }

  void awake(const std::string &action)
  {
    if(available()) appWindow::instance()->awake(action);
  }

  // --- messages, status bar and modal dialogs

  void addMessage(const std::string &msg, int level)
  {
    if(available()) appWindow::instance()->addMessage(msg, level);
  }

  void saveMessages(const std::string &fileName)
  {
    if(available()) appWindow::instance()->console()->save(fileName);
  }

  void setStatus(const std::string &msg, bool graphics)
  {
    if(available()) appWindow::instance()->setStatus(msg, graphics);
  }

  void setLastStatus(int color)
  {
    if(available()) appWindow::instance()->setLastStatus(color);
  }

  void setProgress(const std::string &msg, double val, double min, double max)
  {
    if(available()) appWindow::instance()->setProgress(msg, val, min, max);
  }

  void setGraphicTitle(const std::string &title)
  {
    if(available()) appWindow::instance()->setGraphicTitle(title);
  }

  void beep()
  {
    // no portable bell in GLFW; the terminal one is the best we can do
    fputc('\a', stderr);
    fflush(stderr);
  }

  bool inputDialog(const std::string &question, std::string &value)
  {
    if(!available()) return false;
    return appWindow::instance()->inputDialog(question, value);
  }

  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two)
  {
    if(!available()) return 0;
    return appWindow::instance()->questionDialog(question, zero, one, two);
  }

  // --- refreshing the GUI when the model changes

  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets)
  {
    // the panels are rebuilt from CTX and from the model at every frame, so
    // there is nothing to refresh; only a redraw is needed
    if(available()) appWindow::instance()->requestRedraw();
  }

  void updateFields()
  {
    if(available()) appWindow::instance()->requestRedraw();
  }


  void rebuildTree(bool deleteWidgets)
  {
    if(available()) appWindow::instance()->requestRedraw();
  }

  void resetVisibility() {}

  void applyColorScheme(bool redraw)
  {
    if(!available()) return;
    // General.FltkColorScheme keeps its historical name, but it is really "use
    // a dark interface", and it drives the Dear ImGui style here
    appWindow::instance()->applyStyle();
    if(redraw) drawContext::global()->draw();
  }

  void storeCurrentWindowsInfo()
  {
    // the layout is saved by Dear ImGui itself, in .gmsh-imgui.ini
  }

  void fillRecentHistoryMenu()
  {
    // the recent files are part of the menu description, so the menu simply
    // has to be built again
    Menu::invalidate();
  }

  void watchFile() { watchFiles(); }

  // --- modules, tree and context windows

  void drawTooltip(const std::string &text)
  {
    if(available()) appWindow::instance()->setTooltip(text);
  }

  void openModule(const std::string &name) {}
  void openTreeItem(const std::string &name)
  {
    if(appWindow *a = appWindow::instance()) a->openTreeItem(name);
  }
  void closeTreeItem(const std::string &name)
  {
    if(appWindow *a = appWindow::instance()) a->closeTreeItem(name);
  }

  void showContextWindow(int dim, int tag)
  {
    Dialog::showOnelabContext(dim, tag);
  }

  bool dialogVisible(int dialog)
  {
    appWindow *a = appWindow::instance();
    return a && a->dialogVisible(dialog);
  }

  // nothing to do: a dialog is drawn from the description at every frame
  void refreshDialog(int dialog) {}

  void showDialog(int dialog, bool show)
  {
    if(!available()) return;
    if(show)
      appWindow::instance()->showDialog(dialog);
    else
      appWindow::instance()->hideDialog(dialog);
  }

  bool panelVisible(int panel)
  {
    if(!available()) return false;
    return appWindow::instance()->panelVisible(panel);
  }

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

  void configureGamepad()
  {
    Dialog::show(Dialog::Gamepad, 0);
  }

  void showPanel(int panel, bool show)
  {
    if(available()) appWindow::instance()->showPanel(panel, show);
  }

  void windowAction(const std::string &what)
  {
    if(!available()) return;
    appWindow *app = appWindow::instance();
    if(what == "new")
      app->newGraphicWindow();
    else if(what == "split_h")
      app->splitCurrentPane('h', 0.5);
    else if(what == "split_v")
      app->splitCurrentPane('v', 0.5);
    else if(what == "split_u")
      app->splitCurrentPane('u', 0.);
    else
      app->windowAction(what);
  }

  bool supportsWindowAction(const std::string &what)
  {
    // Nothing to bring to the front, since the panels are not windows of their
    // own; no image clipboard in GLFW; nothing to attach or detach, since every
    // panel is already dragged in and out of the dock space by hand; and the
    // proprietary 3M extension only has a window in the FLTK interface.
    if(what == "front" || what == "copy" || what == "attach_detach" ||
       what == "3m")
      return false;
    return true;
  }

  void fileAction(const std::string &what)
  {
    if(!available()) return;
    appWindow *app = appWindow::instance();
    // they all open a dialog, so they run outside of the frame
    if(what == "new")
      app->postAction(menuNew);
    else if(what == "open")
      app->postAction(menuOpen);
    else if(what == "merge")
      app->postAction(menuMerge);
    else if(what == "rename")
      app->postAction(menuRename);
    else if(what == "export")
      app->postAction(menuExport);
    else if(what == "watch")
      app->postAction(menuWatchPattern);
#if defined(HAVE_ONELAB)
    else if(what.compare(0, 7, "remote_") == 0) {
      std::string arg = what.substr(7);
      app->postAction([arg]() { menuRemote(arg); });
    }
#endif
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

  void onelabAction(const std::string &action)
  {
    // A solver run cannot happen while a frame is being drawn: it meshes, it
    // draws, and it may ask a question, which would mean nesting frames.
    // Asked for from a widget -- a ONELAB parameter that has just changed --
    // it waits for the frame to be over; asked for from anywhere else it runs
    // at once, as it does in FLTK.
    appWindow *a = appWindow::instance();
    if(a && a->inFrame())
      a->postAction([action]() { onelabRun(action); });
    else
      onelabRun(action);
  }

  bool solverBusy() { return solverIsRunning(); }

  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1)
  {
    if(available()) appWindow::instance()->setSolverButtonMode(button0, button1);
  }

  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName)
  {
    if(!available()) return false;
    return appWindow::instance()->fileDialog(mode, title, filter, fileName);
  }

  bool quitShouldExit()
  {
    return available() ? appWindow::instance()->quitShouldExit() : true;
  }

  void startSolver(int index) { solverStart(index); }

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

  // --- miscellaneous

  void setFinishedProcessingCommandLine()
  {
    appWindow::setFinishedProcessingCommandLine();
  }

  bool getFinishedProcessingCommandLine()
  {
    return appWindow::getFinishedProcessingCommandLine();
  }

  void setOpenedThroughMacFinder(const std::string &name)
  {
    appWindow::setOpenedThroughMacFinder(name);
  }

  std::string getOpenedThroughMacFinder()
  {
    return appWindow::getOpenedThroughMacFinder();
  }

} // namespace Gui

#endif
