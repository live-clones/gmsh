// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// FLTK implementation of the toolkit-independent GUI interface declared in
// src/common/Gui.h. This is the only file of src/fltk that the rest of Gmsh
// links against; everything else in this directory is FLTK-specific and is
// reached exclusively through the functions below.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <FL/Fl.H>
#include <FL/fl_ask.H>

#include "Gui.h"
#include "FlGui.h"
#include <FL/fl_draw.H>
#include "extraDialogs.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "dialogFltk.h"
#include "onelabGroup.h"
#include "fileDialogs.h"
#include "Context.h"
#include "drawContext.h"
#include "PixelBuffer.h"
#include "OS.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

// defined in CreateFileFltk.cpp
PixelBuffer *GetCompositePixelBufferFltk(GLenum format, GLenum type);

namespace Gui {

  // --- life cycle

  bool available() { return FlGui::available(); }

  void create(int argc, char **argv, bool quitShouldExit,
              void (*errorHandler)(const char *fmt, ...))
  {
    if(!FlGui::available()) FlGui::instance(argc, argv, quitShouldExit, errorHandler);
  }

  void destroy() { FlGui::destroy(); }

  int run(const std::string &optionFileName)
  {
    return FlGui::instance()->run(optionFileName);
  }

  void copyText(const std::string &text)
  {
    // both of them: the selection buffer and the clipboard proper, as the
    // window this replaces does
    Fl::copy(text.c_str(), (int)text.size(), 0);
    Fl::copy(text.c_str(), (int)text.size(), 1);
  }

  std::string toolkitVersion()
  {
    char tmp[256];
    sprintf(tmp, "FLTK %d.%d.%d", FL_MAJOR_VERSION, FL_MINOR_VERSION,
            FL_PATCH_VERSION);
    return std::string(tmp);
  }

  // --- event pumping

  void check(bool rateLimited) { FlGui::check(rateLimited); }
  bool ready() { return Fl::ready() ? true : false; }
  void wait(bool force) { FlGui::wait(force); }
  void wait(double time, bool force) { FlGui::wait(time, force); }
  void lock() { FlGui::lock(); }
  void unlock() { FlGui::unlock(); }
  int locked() { return FlGui::locked(); }
  void awake(const std::string &action) { FlGui::awake(action); }

  // --- messages, status bar and modal dialogs

  static std::string _colorPrefix(int level)
  {
    // color codes understood by Fl_Browser; the dark color scheme needs
    // different (lighter) colors than the light one
    bool dark = CTX::instance()->guiColorScheme ? true : false;
    switch(level) {
    case MessageDirect: return dark ? "@B136@." : "@C4@.";
    case MessageWarning: return dark ? "@B152@." : "@C5@.";
    case MessageError: return dark ? "@B72@." : "@C1@.";
    default: return "";
    }
  }

  void addMessage(const std::string &msg, int level)
  {
    FlGui::instance()->addMessage((_colorPrefix(level) + msg).c_str());
  }

  void messageLines(std::vector<std::string> &lines)
  {
    lines.clear();
    if(available()) FlGui::instance()->messageLines(lines);
  }

  void setStatus(const std::string &msg, bool graphics)
  {
    FlGui::instance()->setStatus(msg, graphics);
  }

  void setLastStatus(int color)
  {
    // the colour it is worth, not the colour it is: which colour that comes
    // out as is the toolkit's, and mainWindowProgress::draw() chooses it
    FlGui::instance()->setLastStatus(color);
  }

  void setProgress(const std::string &msg, double val, double min, double max)
  {
    FlGui::instance()->setProgress(msg, val, min, max);
  }

  void setGraphicTitle(const std::string &title)
  {
    FlGui::instance()->setGraphicTitle(title);
  }

  void beep() { fl_beep(); }

  bool inputDialog(const std::string &question, std::string &value)
  {
    const char *ret = fl_input("%s", value.c_str(), question.c_str());
    if(!ret) return false;
    value = ret;
    return true;
  }

  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two)
  {
    return fl_choice("%s", zero.c_str(), one.c_str(),
                     two.empty() ? nullptr : two.c_str(), question.c_str());
  }

  // --- refreshing the GUI when the model changes

  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets)
  {
    FlGui::instance()->updateViews(numberOfViewsHasChanged, deleteWidgets);
  }

  void updateFields()
  {
    // the fields of the model have changed: the window that shows them has
    // one line more or one option fewer, which is a matter of shape
    dialogFltk *d = fltkDialog(Dialog::Fields, false);
    if(d && d->shown()) d->reshape();
  }


  void rebuildTree(bool deleteWidgets)
  {
    FlGui::instance()->rebuildTree(deleteWidgets);
  }

  void resetVisibility() { FlGui::instance()->resetVisibility(); }

  void applyColorScheme(bool redraw)
  {
    FlGui::instance()->applyColorScheme(redraw);
  }

  void storeCurrentWindowsInfo()
  {
    FlGui::instance()->storeCurrentWindowsInfo();
  }

  void fillRecentHistoryMenu()
  {
    FlGui::instance()->graph[0]->fillRecentHistoryMenu();
  }

  void watchFile() { file_watch_cb(nullptr, nullptr); }

  // --- modules, tree and context windows

  void openModule(const std::string &name)
  {
    FlGui::instance()->openModule(name);
  }

  void openTreeItem(const std::string &name)
  {
    FlGui::instance()->openTreeItem(name);
  }

  void closeTreeItem(const std::string &name)
  {
    FlGui::instance()->closeTreeItem(name);
  }

  void showContextWindow(int dim, int tag)
  {
    Dialog::showOnelabContext(dim, tag);
  }

  bool dialogVisible(int dialog)
  {
    // only if it is already there: asking is not a reason to build it
    dialogFltk *d = fltkDialog(dialog, false);
    return d && d->shown();
  }

  void refreshDialog(int dialog)
  {
    dialogFltk *d = fltkDialog(dialog, false);
    if(d && d->shown()) d->refresh();
  }

  void showDialog(int dialog, bool show)
  {
    dialogFltk *d = fltkDialog(dialog);
    if(!d) return;
    if(show)
      d->show();
    else
      d->hide();
  }

  static Fl_Window *_panelWindow(int panel)
  {
    FlGui *g = FlGui::instance();
    switch(panel) {
    default: return nullptr;
    }
  }

  bool panelVisible(int panel)
  {
    if(!available()) return false;
    if(panel == PanelMessageConsole) {
      graphicWindow *g = FlGui::instance()->graph[0];
      return g->getMessageHeight() >= FL_NORMAL_SIZE;
    }
    // the option and visibility windows are described like the other
    // dialogs now, so they are dialogs
    if(panel == PanelOptions) return dialogVisible(Dialog::Options);
    if(panel == PanelVisibility) return dialogVisible(Dialog::Visibility);
    if(panel == PanelPlugins) return dialogVisible(Dialog::Plugins);
    if(panel == PanelFields) return dialogVisible(Dialog::Fields);
    // and so are the three windows of the Help menu
    if(panel == PanelKeyboardAndMouse) return dialogVisible(Dialog::Shortcuts);
    if(panel == PanelCurrentOptions)
      return dialogVisible(Dialog::CurrentOptions);
    if(panel == PanelAbout) return dialogVisible(Dialog::About);
    if(panel == PanelClassify) return dialogVisible(Dialog::Classify);
    Fl_Window *w = _panelWindow(panel);
    return w ? (w->shown() ? true : false) : false;
  }

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    if(available()) fltkOrientViews(what, reverse, sync);
  }

  void setMouseSelection(bool on)
  {
    if(available()) fltkSetMouseSelection(on);
  }

  void toggleAnimation()
  {
    if(available()) fltkToggleAnimation();
  }

  bool animating() { return available() && fltkAnimating(); }

  bool exportOptionsDialog(int format, const std::string &fileName)
  {
    // this interface asks for them inside its export chooser, which offers the
    // formats as filters; there is nothing more to ask here
    return true;
  }

  void exportView(int index)
  {
#if defined(HAVE_POST)
    if(index < 0 || index >= (int)PView::list.size()) return;
    static const char *formats =
      "Gmsh Parsed\t*.pos\nGmsh Mesh-based\t*.pos\n"
      "Gmsh Legacy ASCII\t*.pos\nGmsh Legacy Binary\t*.pos\n"
      "MED\t*.rmed\nSTL Surface\t*.stl\nGeneric TXT\t*.txt\n";
    PView *view = PView::list[index];
  again:
    if(!fileChooser(FILE_CHOOSER_CREATE, "Export", formats,
                    view->getData()->getFileName().c_str()))
      return;
    std::string name = fileChooserGetName(1);
    bool confirmOverwrite = CTX::instance()->confirmOverwrite;
#if defined(__APPLE__)
    // handled directly by the native macOS file chooser
    if(CTX::instance()->nativeFileChooser) confirmOverwrite = false;
#endif
    if(confirmOverwrite && !StatFile(name)) {
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                    "Cancel", "Replace", nullptr, name.c_str()))
        goto again;
    }
    // the place of the filter in the list above, in the order PView::write()
    // numbers the formats
    static const int format[] = {2, 5, 0, 1, 6, 3, 4};
    int which = fileChooserGetFilter();
    view->write(name, (which >= 0 && which < 7) ? format[which] : 2);
#endif
  }

  void configureGamepad()
  {
    // described once, like every other dialog; show() raises it
    Dialog::show(Dialog::Gamepad, 0);
  }

  void showPanel(int panel, bool show)
  {
    if(!available()) return;
    if(panel == PanelMessageConsole) {
      graphicWindow *g = FlGui::instance()->graph[0];
      if(show)
        g->showMessages();
      else
        g->hideMessages();
      FlGui::check();
      return;
    }
    // the option window is described like the other dialogs now, so it is one
    if(panel == PanelOptions) {
      showDialog(Dialog::Options, show);
      return;
    }
    if(panel == PanelVisibility) {
      if(show)
        Dialog::show(Dialog::Visibility, -1);
      else
        showDialog(Dialog::Visibility, false);
      return;
    }
    if(panel == PanelPlugins) {
      if(show)
        Dialog::show(Dialog::Plugins, -1);
      else
        showDialog(Dialog::Plugins, false);
      return;
    }
    if(panel == PanelFields) {
      if(show)
        Dialog::show(Dialog::Fields, -1);
      else
        showDialog(Dialog::Fields, false);
      return;
    }
    {
      int dialog = (panel == PanelKeyboardAndMouse) ? Dialog::Shortcuts :
                   (panel == PanelCurrentOptions)   ? Dialog::CurrentOptions :
                   (panel == PanelAbout)            ? Dialog::About :
                                                      -1;
      if(dialog >= 0) {
        if(show)
          Dialog::show(dialog, -1);
        else
          showDialog(dialog, false);
        return;
      }
    }
    if(panel == PanelClassify) {
      if(show)
        Dialog::startClassify();
      else
        showDialog(Dialog::Classify, false);
      return;
    }
    Fl_Window *w = _panelWindow(panel);
    if(!w) return;
    if(!show) {
      w->hide();
      return;
    }
    w->show();
  }

  void windowAction(const std::string &what) { fltkWindowAction(what); }

  bool supportsWindowAction(const std::string &what)
  {
#if !defined(WIN32)
    // the FLTK interface only copies the view to the clipboard on Windows
    if(what == "copy") return false;
#endif
    return true;
  }

  void fileAction(const std::string &what) { fltkFileAction(what); }

  void abortSelection()
  {
    openglWindow *w = FlGui::instance()->getCurrentOpenglWindow();
    if(w) {
      w->quitSelection = 1;
      w->selectionMode = false;
    }
  }

  void setAddPointMode(bool on)
  {
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->addPointMode = on ? 1 : 0;
  }

  void onelabAction(const std::string &action)
  {
    onelab_cb(nullptr, (void *)action.c_str());
  }

  void drawTooltip(const std::string &text)
  {
    if(!available()) return;
    if(openglWindow *w = FlGui::instance()->getCurrentOpenglWindow())
      w->drawTooltip(text);
  }

  bool solverBusy()
  {
    return FlGui::instance()->onelab && FlGui::instance()->onelab->isBusy();
  }

  bool quitShouldExit() { return FlGui::instance()->quitShouldExit(); }

  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1)
  {
    if(FlGui::instance()->onelab)
      FlGui::instance()->onelab->setButtonMode(button0, button1);
  }

  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName)
  {
    if(!fileChooser(mode ? FILE_CHOOSER_CREATE : FILE_CHOOSER_SINGLE,
                    title.c_str(), filter.c_str(), fileName.c_str()))
      return false;
    fileName = fileChooserGetName(1);
    return true;
  }

  void startSolver(int index)
  {
    solver_cb(nullptr, (void *)(intptr_t)index);
  }

  // --- graphic windows

  drawContext *getCurrentDrawContext()
  {
    return FlGui::instance()->getCurrentDrawContext();
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    width = gl->pixel_w();
    height = gl->pixel_h();
  }

  void setCurrentOpenglWindow(int which)
  {
    FlGui::instance()->setCurrentOpenglWindow(which);
  }

  void showAllInEveryWindow()
  {
    if(!available()) return;
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

  // --- miscellaneous

  void setFinishedProcessingCommandLine()
  {
    FlGui::setFinishedProcessingCommandLine();
  }

  bool getFinishedProcessingCommandLine()
  {
    return FlGui::getFinishedProcessingCommandLine();
  }

  void setOpenedThroughMacFinder(const std::string &name)
  {
    FlGui::setOpenedThroughMacFinder(name);
  }

  std::string getOpenedThroughMacFinder()
  {
    return FlGui::getOpenedThroughMacFinder();
  }

} // namespace Gui

#endif
