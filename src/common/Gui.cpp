// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>

#include "Backend.h"
#include "Gui.h"
#include "GmshGlobal.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "GModel.h"
#include "StringUtils.h"
#include "OS.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif
#include "GuiStatus.h"
#include "StringUtils.h"
#include "drawContext.h"
#include "GuiDialogs.h"
#include "GuiMenus.h"
#include "GuiModules.h"
#include "GuiActions.h"

// The graphical user interface, written once.
//
// There used to be two of these -- src/fltk/GuiFltk.cpp and src/imgui/Gui.cpp,
// six hundred lines each -- and the same work was written twice in them. This
// holds what is not a toolkit's to do; what is goes through Ui::Backend, of
// which exactly one is linked.
//
// It is filled a group at a time. What is here is what has moved; the rest is
// still answered by the adapters, which shrink as it moves.

namespace Gui {

  namespace {

    Ui::Backend *_backend = nullptr;
    bool _quitShouldExit = true;
    bool _finishedProcessingCommandLine = false;
    std::string _openedThroughMacFinder;
    std::string _solverButton0, _solverButton1 = "compute";

  } // namespace

  Ui::Backend *backend() { return _backend; }

  // --- life cycle

  bool available() { return _backend != nullptr; }

  void create(int argc, char **argv, bool quitShouldExit,
              void (*errorHandler)(const char *fmt, ...))
  {
    if(_backend) return;
    Ui::Backend *made = makeUiBackend();
    if(!made) return;

    // What the toolkit is to say when something inside it goes wrong, and
    // where the rest of what it reports goes. It is the whole of what it may
    // call back on, and it is set before it is asked to make a window.
    Ui::Backend::Host host;
    if(errorHandler)
      host.error = [errorHandler](const std::string &text) {
        errorHandler("%s", text.c_str());
      };
    else
      host.error = [](const std::string &text) {
        Msg::Error("%s (GUI internal error)", text.c_str());
      };
    made->setHost(host);

    // And everything it is allowed to know of Gmsh: the descriptions, asked
    // for again rather than handed over, since what they say is only true at
    // the moment they are drawn.
    Ui::Backend::Sources sources;
    sources.form = [](int form) { return Dialog::panel(form); };
    sources.numForms = []() { return (int)Dialog::NumDialogs; };
    sources.formPane = [](int form) { return Dialog::currentPane(form); };
    sources.setFormPane = [](int form, int pane) {
      Dialog::currentPane(form) = pane;
    };
    sources.menuBar = []() { return Menu::bar(); };
    sources.menuGeneration = []() { return Menu::generation(); };
    sources.tree = Modules::tree();
    sources.barButtons = []() { return StatusBar::bar(); };
    sources.barMessage = []() { return StatusBar::message(); };
    sources.barTooltip = []() { return StatusBar::messageTooltip(); };
    sources.barPressed = []() { StatusBar::messagePressed(); };
    made->setSources(sources);

    if(!made->create(argc, argv, quitShouldExit)) {
      delete made;
      return;
    }
    _backend = made;
    _quitShouldExit = quitShouldExit;

    // And the welcome, which is Gmsh's rather than the toolkit's. One of the
    // two interfaces did all of this and the other only the first line of it,
    // which is the kind of thing writing it twice does.
    InitOptionsGUI(0);
    Msg::ResetErrorCounter();
    Msg::StatusBar(false, "Gmsh %s", GetGmshVersion());
    Msg::Direct("-------------------------------------------------------");
    PrintBuildInfo();
    Msg::Direct("-------------------------------------------------------");
    // in case the interface is created after some data has been loaded
    updateViews(true, true);
    // so that there is a bounding box even with no model and no data
    SetBoundingBox();
  }

  void destroy()
  {
    if(!_backend) return;
    _backend->destroy();
    delete _backend;
    _backend = nullptr;
  }

  int run(const std::string &optionFileName)
  {
    if(!_backend) return 0;
    // The option file is merged before the loop and written after it, which is
    // Gmsh's business and not a toolkit's. Written twice it had come apart:
    // one interface wrote what differs from the defaults and saved the
    // visibilities, the other wrote the whole file and saved nothing.
    if(optionFileName.size()) MergeFile(optionFileName, false);
    int ret = _backend->runLoop();
    if(optionFileName.size()) {
      PrintOptions(0, GMSH_FULLRC, 1, 0, optionFileName.c_str());
      int was = CTX::instance()->expertMode;
      CTX::instance()->expertMode = 1; // no warning about a non-geo file
      visibility_save(optionFileName);
      CTX::instance()->expertMode = was;
    }
    return ret;
  }

  std::string toolkitVersion()
  {
    return _backend ? _backend->name() : "";
  }

  bool quitShouldExit() { return _quitShouldExit; }

  // --- the event loop

  void check(bool rateLimited)
  {
    if(_backend) _backend->check(rateLimited);
  }

  bool ready() { return _backend && _backend->ready(); }

  void wait(bool force)
  {
    if(_backend) _backend->wait(-1., force);
  }

  void wait(double time, bool force)
  {
    if(_backend) _backend->wait(time, force);
  }

  void lock()
  {
    if(_backend) _backend->lock();
  }

  void unlock()
  {
    if(_backend) _backend->unlock();
  }

  int locked() { return _backend ? _backend->locked() : 0; }

  void awake(const std::string &action)
  {
    if(!_backend) return;
    // It comes from a thread that is not the one drawing, so it is not done
    // here; and what it means is the same whichever interface is running.
    _backend->postFromThread([action]() {
      if(action.empty() || action == "update")
        updateViews(true, false);
      else
        Msg::Debug("Unknown awake action '%s'", action.c_str());
    });
  }

  void copyText(const std::string &text)
  {
    if(_backend) _backend->copyText(text);
  }

  void beep()
  {
    if(_backend) _backend->beep();
  }

  // --- messages, the bar, and the questions that stop everything
  //
  // What the bar says is worked out once in src/common/GuiStatus.cpp and read
  // by whichever bar is drawing it; all that is left here is to say that it
  // changed. It used to be written twice, and a message set from a child
  // thread was guarded against in two different ways.

  void addMessage(const std::string &msg, int level)
  {
    if(_backend) _backend->addMessage(msg, level);
  }

  void messageLines(std::vector<std::string> &lines)
  {
    lines.clear();
    if(_backend) _backend->messageLines(lines);
  }

  void setStatus(const std::string &msg, bool graphics)
  {
    if(!_backend || Msg::GetThreadNum() > 0) return;
    if(!graphics) {
      StatusBar::setMessage(msg);
      _backend->refreshBar();
      return;
    }
    // said over the view instead, on two lines: what to do, then which keys
    // end or abort it
    std::vector<std::string> m = SplitString(msg, '\n');
    if(m.size() > 2)
      Msg::Debug("Ignoring extra lines of status message: %s", msg.c_str());
    _backend->sceneMessage(m.size() > 0 ? m[0] : "",
                           m.size() > 1 ? m[1] : "");
    drawContext::global()->draw();
  }

  void setLastStatus(int color)
  {
    if(!_backend || Msg::GetThreadNum() > 0) return;
    // the colour it is worth, not the colour it is: which colour that comes
    // out as is the toolkit's
    StatusBar::setColour(color);
    _backend->refreshBar();
  }

  void setProgress(const std::string &msg, double val, double min, double max)
  {
    if(!_backend || Msg::GetThreadNum() > 0) return;
    StatusBar::setProgress(val, min, max);
    setStatus(msg);
  }

  void setGraphicTitle(const std::string &title)
  {
    if(!_backend) return;
    // The second window and the ones after it are numbered, and all of them
    // say what they are showing. The interface that has one window said only
    // the name, without even the "Gmsh - " in front of it.
    for(int i = 0; i < _backend->numWindows(); i++) {
      std::string say = "Gmsh";
      if(title.size()) {
        say += " - " + title;
        if(i) say += " [" + std::to_string(i) + "]";
      }
      _backend->setWindowTitle(i, say);
    }
  }

  bool inputDialog(const std::string &question, std::string &value,
                   const std::string &hint, bool readOnly)
  {
    return _backend ?
             _backend->inputDialog(question, value, hint, readOnly) :
             false;
  }

  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two)
  {
    return _backend ? _backend->questionDialog(question, zero, one, two) : 0;
  }

  bool fileDialog(int mode, const std::string &title,
                  const std::string &filter, std::string &fileName)
  {
    if(!_backend) return false;
    std::vector<Ui::Backend::FileFormat> formats;
    if(filter.size()) formats.push_back(Ui::Backend::FileFormat("", filter));
    return _backend->fileDialog(mode, title, formats, fileName, nullptr);
  }

  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::string &fileName, int &chosenFormat)
  {
    if(!_backend) return false;
    std::vector<Ui::Backend::FileFormat> say;
    for(const auto &f : formats)
      say.push_back(Ui::Backend::FileFormat(f.name, f.pattern));
    chosenFormat = -1;
    return _backend->fileDialog(mode, title, say, fileName, &chosenFormat);
  }

  bool exportOptionsDialog(int format, const std::string &fileName)
  {
    return _backend ? _backend->formatOptionsDialog(format, fileName) : false;
  }

  void applyColorScheme(bool redraw)
  {
    if(!_backend) return;
    // General.FltkColorScheme keeps its historical name, but what it says is
    // "use a dark interface"; which colours that means is the toolkit's.
    _backend->applyColorScheme(CTX::instance()->guiColorScheme ? true : false);
    if(redraw) drawContext::global()->draw();
  }

  // --- the things that are described
  //
  // A dialog is described once in GuiDialogs.h and built by whichever
  // interface is running; all that is left here is which one, and when.

  void showDialog(int dialog, bool show)
  {
    if(_backend) _backend->showForm(dialog, show);
  }

  bool dialogVisible(int dialog)
  {
    return _backend && _backend->formVisible(dialog);
  }

  void refreshDialog(int dialog)
  {
    if(_backend) _backend->refreshForm(dialog);
  }

  void showContextWindow(int dim, int tag) { Dialog::showOnelabContext(dim, tag); }

  void configureGamepad() { Dialog::show(Dialog::Gamepad, 0); }

  void updateFields()
  {
    // the fields of the model have changed: the window that shows them has one
    // line more or one option fewer, which is a matter of shape and not of
    // value
    if(_backend) _backend->rebuildForm(Dialog::Fields);
  }

  // The panels the menus show and hide. Every one of them is a described
  // dialog except the message console, which is a window in one interface and
  // a strip under the scene in the other; the table saying which was written
  // out twice, once per interface, and was the same table both times.

  namespace {

    int _panelDialog(int panel)
    {
      switch(panel) {
      case PanelOptions: return Dialog::Options;
      case PanelVisibility: return Dialog::Visibility;
      case PanelPlugins: return Dialog::Plugins;
      case PanelFields: return Dialog::Fields;
      case PanelKeyboardAndMouse: return Dialog::Shortcuts;
      case PanelCurrentOptions: return Dialog::CurrentOptions;
      case PanelAbout: return Dialog::About;
      case PanelClassify: return Dialog::Classify;
      default: return -1;
      }
    }

  } // namespace

  bool panelVisible(int panel)
  {
    if(!_backend) return false;
    if(panel == PanelMessageConsole) return _backend->consoleVisible();
    int dialog = _panelDialog(panel);
    return dialog >= 0 && dialogVisible(dialog);
  }

  void showPanel(int panel, bool show)
  {
    if(!_backend) return;
    if(panel == PanelMessageConsole) {
      _backend->showConsole(show);
      return;
    }
    int dialog = _panelDialog(panel);
    if(dialog < 0) return;
    if(!show) {
      showDialog(dialog, false);
      return;
    }
    // showing one is not only raising it: a dialog that works on something
    // takes it as it opens, which is what Dialog::show() is for. The one that
    // turns a triangulation into a model draws the edges it has detected as
    // well, which is why it has a call of its own.
    if(dialog == Dialog::Classify)
      Dialog::startClassify();
    else
      Dialog::show(dialog, -1);
  }

  // --- the modules tree, and what has to be looked at again

  void rebuildTree(bool deleteWidgets)
  {
    if(_backend) _backend->refreshTree(deleteWidgets);
  }

  void openModule(const std::string &name)
  {
    if(_backend) _backend->openTreeItem("0Modules/" + name, true);
  }

  void openTreeItem(const std::string &name)
  {
    if(_backend) _backend->openTreeItem(name, true);
  }

  void closeTreeItem(const std::string &name)
  {
    if(_backend) _backend->openTreeItem(name, false);
  }

  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets)
  {
    if(!_backend) return;
    // the bar has a button that only makes sense with a view that has several
    // time steps
    _backend->refreshBar();
    if(!numberOfViewsHasChanged) return;
    _backend->refreshTree(deleteWidgets);
    // The per-entity parameters are described once and read what the server
    // holds: a parameter a solver added is a field more, so the window may
    // have to be built again and not only read again.
    _backend->rebuildForm(Dialog::OnelabContext);
    // the option window reads what it shows, views included
    refreshDialog(Dialog::Options);
    // the size-field window offers the views a field may be drawn on
    updateFields();
    refreshDialog(Dialog::Clipping);
    statisticsRefresh(false);
  }

  void resetVisibility()
  {
    refreshDialog(Dialog::Visibility);
    refreshDialog(Dialog::CurrentOptions);
    statisticsRefresh(false);
  }

  void fillRecentHistoryMenu()
  {
    // the recent files are part of the menu description, so the menus simply
    // have to be built again
    Menu::invalidate();
    if(_backend) _backend->refreshMenus();
  }

  // --- the solver
  //
  // Both interfaces went through their own callback to reach what is already
  // written once in GuiActions.cpp, and added the same thing after it: the
  // modules tree is brought in front, since what it is about to say is there.
  // Only one of them added it.

  void onelabAction(const std::string &action)
  {
    if(!_backend) return;
    // A run cannot happen while a frame is being drawn: it meshes, it draws,
    // and it may ask a question. post() is what knows whether that matters.
    _backend->post([action]() {
      onelabRun(action);
      if(action != "initialize" && _backend) _backend->showTree();
    });
  }

  bool solverBusy() { return solverIsRunning(); }

  void startSolver(int index)
  {
    solverStart(index); // it compacts the solver list itself
    if(solverIsRunning() && _backend) _backend->showTree();
  }

  void exportView(int index)
  {
#if defined(HAVE_POST)
    if(index < 0 || index >= (int)PView::list.size()) return;
    PView *view = PView::list[index];
    // The seven the window this reproduces offers, and what PView::write()
    // numbers each of them. Four of them are ".pos": which one is meant is
    // what the chooser is asked, and is why it names its formats.
    static const struct {
      const char *name;
      const char *pattern;
      int format;
    } offered[] = {{"Gmsh Parsed", "*.pos", 2},
                   {"Gmsh Mesh-based", "*.pos", 5},
                   {"Gmsh Legacy ASCII", "*.pos", 0},
                   {"Gmsh Legacy Binary", "*.pos", 1},
                   {"MED", "*.rmed", 6},
                   {"STL Surface", "*.stl", 3},
                   {"Generic TXT", "*.txt", 4}};
    std::vector<FileFormat> formats;
    for(auto &o : offered) formats.push_back(FileFormat(o.name, o.pattern));

    std::string name = view->getData()->getFileName();
    while(true) {
      int which = -1;
      if(!fileDialog(1, "Export", formats, name, which)) return;
      bool confirm = CTX::instance()->confirmOverwrite;
#if defined(__APPLE__)
      // handled directly by the native macOS file chooser
      if(CTX::instance()->nativeFileChooser) confirm = false;
#endif
      if(confirm && !StatFile(name)) {
        std::string q = "File \'" + name +
                        "\' already exists.\n\nDo you want to replace it?";
        if(!Msg::GetAnswer(q.c_str(), 0, "Cancel", "Replace")) continue;
      }
      int format = 2;
      if(which >= 0 && which < (int)(sizeof(offered) / sizeof(offered[0])))
        format = offered[which].format;
      else {
        // a chooser that cannot say which was picked leaves the extension to
        // say it, and ".pos" means the parsed one
        std::string ext = SplitFileName(name)[2];
        format = (ext == ".rmed") ? 6 :
                 (ext == ".stl")  ? 3 :
                 (ext == ".txt")  ? 4 :
                                    2;
      }
      view->write(name, format);
      return;
    }
#endif
  }

  void watchFile()
  {
    // rescan General.WatchFilePattern and merge what it matches; one of the
    // two interfaces reached it through the callback of the menu entry that
    // asks for the pattern, which is why it looked like a toolkit's
    watchFiles();
  }

  void storeCurrentWindowsInfo()
  {
    if(_backend) _backend->storeWindowLayout();
  }

  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1)
  {
    // What they say is not a toolkit's to keep: the row of them under the
    // tree is described, and this is what the description reads.
    _solverButton0 = button0;
    _solverButton1 = button1;
    if(_backend) _backend->setSolverButtonMode(button0, button1);
  }

  void solverButtons(std::string &button0, std::string &button1)
  {
    button0 = _solverButton0;
    button1 = _solverButton1;
  }

  void drawTooltip(const std::string &text)
  {
    if(_backend) _backend->drawTooltip(text);
  }

  void windowAction(const std::string &what)
  {
    if(_backend) _backend->windowAction(what);
  }

  bool supportsWindowAction(const std::string &what)
  {
    return _backend && _backend->supports(what);
  }

  // --- what the interface remembers for the rest of Gmsh
  //
  // None of it is a toolkit's: it was held in FlGui on one side and in
  // appWindow on the other for no reason but that they were there.

  void setFinishedProcessingCommandLine()
  {
    _finishedProcessingCommandLine = true;
  }

  bool getFinishedProcessingCommandLine()
  {
    return _finishedProcessingCommandLine;
  }

  void setOpenedThroughMacFinder(const std::string &name)
  {
    _openedThroughMacFinder = name;
  }

  std::string getOpenedThroughMacFinder()
  {
    return _openedThroughMacFinder;
  }

} // namespace Gui

#endif
