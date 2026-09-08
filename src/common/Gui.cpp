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

  // where the interface says its windows are, written into the options
  static void _takeLayout(const Ui::Backend::Layout &l);

  namespace {

    Ui::Backend *_backend = nullptr;
    // The one that was taken down, kept until the next is made. destroy()
    // is reached from inside the backend's own loop -- the close button of
    // its window -- and that loop has to unwind through the object before
    // it may go.
    Ui::Backend *_retired = nullptr;
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
    // Which interface. Every one that was built says so at start-up; this
    // says which of them to use -- what was asked for on the command line,
    // then what the environment says, then whichever was offered first. A
    // name nobody offered is worth a word rather than a silent fallback:
    // asking for an interface that is not there is a mistake, not a wish.
    std::string want = CTX::instance()->guiToolkit;
    if(want.empty() && getenv("GMSH_GUI")) want = getenv("GMSH_GUI");
    delete _retired;
    _retired = nullptr;
    Ui::Backend *made = Ui::make(want);
    // and the scene that goes with it: the one offered under that name, or
    // the one in a window of its own for a chrome that draws none
    if(made) useScene(Ui::chosen());
    if(!made && want.size()) {
      std::string said;
      for(const auto &name : Ui::offered()) said += (said.size() ? ", " : "") + name;
      Msg::Error("No interface called '%s'%s%s", want.c_str(),
                 said.size() ? "; this build has " : " in this build",
                 said.c_str());
      return;
    }
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
    // What files dropped on the interface mean: the first is what one is
    // now working on, the rest are merged into it. Both interfaces had it,
    // and only one of them redrew afterwards.
    host.filesDropped = [](const std::vector<std::string> &paths) {
      for(std::size_t i = 0; i < paths.size(); i++) {
        if(i == 0)
          OpenProject(paths[i]);
        else
          MergeFile(paths[i]);
      }
      drawContext::global()->draw();
    };
    // the last window is gone: the interface was the process, so the process
    // goes with it
    host.quitting = []() { projectQuit(); };
    // what the application does when the loop comes round: draw the scene, if
    // it is in a window of its own
    host.tick = []() { pumpScene(true); };
    host.sceneImage = [](int &w, int &h, bool always) {
      return scenePicture(w, h, always);
    };
    host.sceneMoved = []() { return sceneMoved(); };
    host.layoutChanged = [](const Ui::Backend::Layout &l) { _takeLayout(l); };
    host.sceneResize = [](int w, int h) { sceneResize(w, h); };
    host.scenePointer = [](double x, double y, int button, int what,
                           double wheel, bool shift, bool ctrl, bool alt) {
      scenePointer(x, y, button, what, wheel, shift, ctrl, alt);
    };
    made->setHost(host);

    // And everything it is allowed to know of Gmsh: the descriptions, asked
    // for again rather than handed over, since what they say is only true at
    // the moment they are drawn.
    Ui::Backend::Sources sources;
    // What the interface lays itself out from. Read again every time it is
    // asked rather than handed over once, so that an interface which draws
    // itself afresh follows an option that has just been set without having
    // to be told; the set...() of the backend are for the one that does not.
    sources.settings = []() {
      Ui::Backend::Settings s;
      CTX *c = CTX::instance();
      s.fontSize = c->fontSize;
      s.sceneX = c->glPosition[0];
      s.sceneY = c->glPosition[1];
      s.sceneWidth = c->glSize[0];
      s.sceneHeight = c->glSize[1];
      s.sceneTiles = c->numTiles;
      s.treeWidth = c->menuSize[0];
      s.treeX = c->menuPosition[0];
      s.treeY = c->menuPosition[1];
      s.treeHeight = c->menuSize[1];
      s.consoleHeight = c->msgSize;
      s.consoleFontSize = c->msgFontSize;
      s.dialogX = c->ctxPosition[0];
      s.dialogY = c->ctxPosition[1];
      s.doubleBuffer = c->db ? true : false;
      s.stereo = c->stereo ? true : false;
      s.systemMenuBar = c->systemMenuBar ? true : false;
      s.darkScheme = c->guiColorScheme ? true : false;
      s.antialiasing = c->antialiasing ? true : false;
      s.tooltips = c->tooltips ? true : false;
      s.detachedTree = c->detachedMenu ? true : false;
      s.inputScrolling = c->inputScrolling ? true : false;
      s.nonModalWindows = c->nonModalWindows ? true : false;
      s.background = Ui::Colour((unsigned char)c->unpackRed(c->color.bg),
                                (unsigned char)c->unpackGreen(c->color.bg),
                                (unsigned char)c->unpackBlue(c->color.bg),
                                (unsigned char)c->unpackAlpha(c->color.bg));
      s.refreshRate = c->guiRefreshRate;
      s.homeDir = c->homeDir;
      return s;
    };
    sources.menuBar = []() { return Menu::bar(); };
    sources.menuGeneration = []() { return Menu::generation(); };
    sources.keys = []() { return Menu::keys(); };
    sources.tree = Modules::tree();
    sources.barButtons = []() { return StatusBar::bar(); };
    sources.saveMessages = []() { messagesSaveAs(); };
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
    // Whether this chrome shows the scene itself has to be said before
    // anything else: what puts a window up is the loop being pumped, and a
    // message reported while the options are being set pumps it.
    if(made->showsScene()) sceneShownElsewhere();

    // And the welcome, which is Gmsh's rather than the toolkit's. One of the
    // two interfaces did all of this and the other only the first line of it,
    // which is the kind of thing writing it twice does.
    InitOptionsGUI(0);
    Msg::ResetErrorCounter();
    Msg::StatusBar(false, "Gmsh %s", GetGmshVersion());
    Msg::Direct("-------------------------------------------------------");
    PrintBuildInfo();
    Msg::Direct("-------------------------------------------------------");
    // and a scene of its own, for a chrome that holds none
    pumpScene(false);
    // in case the interface is created after some data has been loaded
    updateViews(true, true);
    // so that there is a bounding box even with no model and no data
    SetBoundingBox();
  }

  void destroy()
  {
    if(!_backend) return;
    // the forms go with the interface that handed them out
    Dialog::forgetForms();
    Ui::Backend *was = _backend;
    // nothing reaches it from here on, and it is deleted once its loop has
    // unwound: see _retired
    _backend = nullptr;
    was->destroy();
    delete _retired;
    _retired = was;
  }

  int run(const std::string &optionFileName)
  {
    if(!_backend) return 0;
    // The option file is merged before the loop and written after it, which is
    // Gmsh's business and not a toolkit's. Written twice it had come apart:
    // one interface wrote what differs from the defaults and saved the
    // visibilities, the other wrote the whole file and saved nothing.
    if(optionFileName.size()) MergeFile(optionFileName, false);
    // What a window shows before anything has happened. Both interfaces drew
    // it from inside their loop, which is the application asking itself for
    // something through a toolkit.
    drawContext::global()->draw(false);
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
    if(!_backend) return;
    _backend->check(rateLimited);
    // a scene in a window of its own is pumped from here, since the loop
    // belongs to the chrome
    pumpScene(rateLimited);
  }

  bool ready() { return _backend && _backend->ready(); }

  void wait(bool force)
  {
    if(!_backend) return;
    _backend->wait(-1., force);
    pumpScene(false);
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
    sceneMessage(m.size() > 0 ? m[0] : "", m.size() > 1 ? m[1] : "");
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
    std::vector<std::string> names(1, fileName);
    if(!_backend->fileDialog(mode, title, formats, names, nullptr))
      return false;
    fileName = names.empty() ? "" : names[0];
    return true;
  }

  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::string &fileName, int &chosenFormat)
  {
    std::vector<std::string> names(1, fileName);
    if(!fileDialog(mode, title, formats, names, chosenFormat)) return false;
    fileName = names.empty() ? "" : names[0];
    return true;
  }

  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::vector<std::string> &names, int &chosenFormat)
  {
    if(!_backend) return false;
    std::vector<Ui::Backend::FileFormat> say;
    for(const auto &f : formats)
      say.push_back(Ui::Backend::FileFormat(f.name, f.pattern));
    chosenFormat = -1;
    return _backend->fileDialog(mode, title, say, names, &chosenFormat);
  }

  int exportOptionsDialog(int format, const std::string &fileName)
  {
    return _backend ? _backend->formatOptionsDialog(format, fileName) :
                      ExportCancelled;
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

  Ui::FormRef createForm(const std::string &name,
                         const std::function<Ui::Form()> &describe)
  {
    return _backend ? _backend->createForm(name, describe) : Ui::FormRef();
  }

  void destroyForm(Ui::FormRef form)
  {
    if(_backend && form.valid()) _backend->destroyForm(form);
  }

  void showForm(Ui::FormRef form, bool show)
  {
    if(_backend && form.valid()) _backend->showForm(form, show);
  }

  bool formVisible(Ui::FormRef form)
  {
    return _backend && form.valid() && _backend->formVisible(form);
  }

  int formPane(Ui::FormRef form)
  {
    return (_backend && form.valid()) ? _backend->formPane(form) : 0;
  }

  void setFormPane(Ui::FormRef form, int pane)
  {
    if(_backend && form.valid()) _backend->setFormPane(form, pane);
  }

  void refreshForm(Ui::FormRef form)
  {
    if(_backend && form.valid()) _backend->refreshForm(form);
  }

  void rebuildForm(Ui::FormRef form)
  {
    if(_backend && form.valid()) _backend->rebuildForm(form);
  }

  void showContextWindow(int dim, int tag) { Dialog::showOnelabContext(dim, tag); }

  void configureGamepad() { Dialog::show(Dialog::gamepad(), 0); }

  void updateFields()
  {
    // the fields of the model have changed: the window that shows them has one
    // line more or one option fewer, which is a matter of shape and not of
    // value
    rebuildForm(Dialog::fields());
  }

  // The panels the menus show and hide. Every one of them is a described
  // dialog except the message console, which is a window in one interface and
  // a strip under the scene in the other; the table saying which was written
  // out twice, once per interface, and was the same table both times.

  namespace {

    Ui::FormRef _panelForm(int panel)
    {
      switch(panel) {
      case PanelOptions: return Dialog::options();
      case PanelVisibility: return Dialog::visibility();
      case PanelPlugins: return Dialog::plugins();
      case PanelFields: return Dialog::fields();
      case PanelKeyboardAndMouse: return Dialog::shortcuts();
      case PanelCurrentOptions: return Dialog::currentOptions();
      case PanelAbout: return Dialog::about();
      case PanelClassify: return Dialog::classify();
      default: return Ui::FormRef();
      }
    }

  } // namespace

  bool panelVisible(int panel)
  {
    if(!_backend) return false;
    if(panel == PanelMessageConsole) return _backend->consoleVisible();
    return formVisible(_panelForm(panel));
  }

  void showPanel(int panel, bool show)
  {
    if(!_backend) return;
    if(panel == PanelMessageConsole) {
      // the count of errors the bar shows is of those not yet looked at:
      // showing the console is looking at them
      if(show) Msg::ResetErrorCounter();
      _backend->showConsole(show);
      return;
    }
    Ui::FormRef form = _panelForm(panel);
    if(!form.valid()) return;
    if(!show) {
      showForm(form, false);
      return;
    }
    // showing one is not only raising it: a dialog that works on something
    // takes it as it opens, which is what Dialog::show() is for. The one that
    // turns a triangulation into a model draws the edges it has detected as
    // well, which is why it has a call of its own.
    if(panel == PanelClassify)
      Dialog::startClassify();
    else
      Dialog::show(form, -1);
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

  void toggleModule(const std::string &name)
  {
    if(!_backend) return;
    std::string item = "0Modules/" + name;
    _backend->openTreeItem(item, !_backend->treeItemOpen(item));
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
    rebuildForm(Dialog::onelabContext());
    // the option window reads what it shows, views included
    refreshForm(Dialog::options());
    // the size-field window offers the views a field may be drawn on
    updateFields();
    refreshForm(Dialog::clipping());
    statisticsRefresh(false);
  }

  void resetVisibility()
  {
    refreshForm(Dialog::visibility());
    refreshForm(Dialog::currentOptions());
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

  void fileAction(const std::string &what)
  {
    if(!_backend) return;
    // Each of them opens a chooser, so none of them can run inside a frame
    // that is being drawn; post() is what knows whether that matters.
    if(what == "new")
      _backend->post(fileNew);
    else if(what == "open")
      _backend->post([]() { fileOpen(false); });
    else if(what == "merge")
      _backend->post([]() { fileOpen(true); });
    else if(what == "rename")
      _backend->post(fileRename);
    else if(what == "watch")
      _backend->post(Dialog::showWatchPattern);
    else if(what.compare(0, 7, "remote_") == 0) {
      std::string which = what.substr(7);
      _backend->post([which]() { fileRemote(which); });
    }
    else if(what == "export")
      _backend->post(fileExport);
    else
      Msg::Error("Unknown file action '%s'", what.c_str());
  }

  void pumpChrome(bool rateLimited)
  {
    if(_backend) _backend->check(rateLimited);
  }

  void watchFile()
  {
    // rescan General.WatchFilePattern and merge what it matches; one of the
    // two interfaces reached it through the callback of the menu entry that
    // asks for the pattern, which is why it looked like a toolkit's
    watchFiles();
  }

  // Where the interface left its windows, written where the option file
  // reads them. The interface says what it knows and nothing else: a value
  // it has nothing to say about keeps what it was.
  static void _takeLayout(const Ui::Backend::Layout &l)
  {
    CTX *c = CTX::instance();
    auto take = [](int &into, int value) {
      if(value >= 0) into = value;
    };
    take(c->glPosition[0], l.sceneX);
    take(c->glPosition[1], l.sceneY);
    take(c->glSize[0], l.sceneWidth);
    take(c->glSize[1], l.sceneHeight);
    take(c->msgSize, l.consoleHeight);
    take(c->menuSize[0], l.treeWidth);
    take(c->detachedMenu, l.treeDetached);
    take(c->menuPosition[0], l.treeX);
    take(c->menuPosition[1], l.treeY);
    take(c->menuSize[1], l.treeHeight);
    take(c->ctxPosition[0], l.dialogX);
    take(c->ctxPosition[1], l.dialogY);
    take(c->fileChooserPosition[0], l.chooserX);
    take(c->fileChooserPosition[1], l.chooserY);
  }

  void storeCurrentWindowsInfo()
  {
    if(_backend) _takeLayout(_backend->windowLayout());
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

  void setSceneSize(int width, int height)
  {
    if(_backend) _backend->setSceneSize(width, height);
  }

  void setConsoleFontSize(int size)
  {
    if(_backend) _backend->setConsoleFontSize(size);
  }

  void setTreeWidth(int width)
  {
    if(_backend) _backend->setTreeWidth(width);
  }

  void detachTree(bool detached)
  {
    if(_backend) _backend->detachTree(detached);
  }

  void enableTooltips(bool on)
  {
    if(_backend) _backend->enableTooltips(on);
  }

  void refreshBar()
  {
    if(_backend) _backend->refreshBar();
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
