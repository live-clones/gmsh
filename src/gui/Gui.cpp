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
#include "GuiExport.h"
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
#include "GuiMenus.h"
#include "GuiModules.h"
#include "GuiActions.h"
#include "GuiDeclare.h"

// The graphical user interface: what is not a toolkit's to do. What is goes
// through Ui::Backend, of which exactly one is linked.

namespace Declare {

  Ui::Field &bindOption(Ui::Field &f, const std::string &name)
  {
    std::string category, short_;
    int index = 0;
    SplitOptionName(name, category, short_, index);
    return bindOption(f, category, short_, index);
  }

  Ui::Field option(const std::string &label, const std::string &name)
  {
    std::string category, short_;
    int index = 0;
    SplitOptionName(name, category, short_, index);
    Ui::Field f;
    f.label = label;
    f.kind = Ui::Number;
    if(short_.compare(0, 6, "Color.") == 0)
      f.kind = Ui::Color;
    else if(StringXString *s = GetStringOptionCategory(category.c_str()))
      for(; s->str; s++)
        if(short_ == s->str) f.kind = Ui::Text;
    return bindOption(f, category, short_, index);
  }

  Ui::Field &bindOption(Ui::Field &f, const std::string &category,
                        const std::string &name_, int index)
  {
    // written "General.Color.Background" wherever an option is named in full
    std::string name = name_;
    if(f.kind == Ui::Color && name.compare(0, 6, "Color.") == 0)
      name = name.substr(6);
    f.option = Gui::optionName(category, name, index);
    if(f.kind == Ui::Color) {
      f.readColour = [=]() {
        unsigned int v = GmshGetColorOption(category, name, index);
        CTX *c = CTX::instance();
        return Ui::Colour((unsigned char)c->unpackRed(v),
                          (unsigned char)c->unpackGreen(v),
                          (unsigned char)c->unpackBlue(v),
                          (unsigned char)c->unpackAlpha(v));
      };
      f.writeColour = [=](Ui::Colour c) {
        GmshSetOption(category, name,
                      CTX::instance()->packColor(c.r, c.g, c.b, c.a), index);
      };
      return f;
    }
    // a Choice writes its text or one of its values, as the interface says
    if(f.kind == Ui::Text || f.kind == Ui::Output || f.kind == Ui::Choice) {
      f.readText = [=]() { return GmshGetStringOption(category, name, index); };
      f.writeText = [=](const std::string &v) {
        GmshSetOption(category, name, v, index);
      };
      if(f.kind != Ui::Choice) return f;
    }
    f.readNumber = [=]() { return GmshGetNumberOption(category, name, index); };
    f.writeNumber = [=](double v) { GmshSetOption(category, name, v, index); };
    return f;
  }

} // namespace Declare


  Gui &Gui::instance()
  {
    static Gui the;
    return the;
  }

  // --- life cycle

  bool Gui::available() { return _backend != nullptr; }

  void Gui::create(int argc, char **argv, bool quitShouldExit,
              void (*errorHandler)(const char *fmt, ...))
  {
    if(_backend) return;
    // which interface: what was asked for on the command line, then what the
    // environment says, then whichever was offered first; a name nobody
    // offered is an error rather than a silent fallback
    std::string want = CTX::instance()->guiToolkit;
    if(want.empty() && getenv("GMSH_GUI")) want = getenv("GMSH_GUI");
    delete _retired;
    _retired = nullptr;
    Ui::Backend *made = Ui::make(want);
    // and the scene that goes with it: the one offered under that name, or
    // the one in a window of its own for an interface that draws none
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

    // what the toolkit may call back on, set before it is asked to make a
    // window
    Ui::Backend::Host host;
    if(errorHandler)
      host.error = [errorHandler](const std::string &text) {
        errorHandler("%s", text.c_str());
      };
    else
      host.error = [this](const std::string &text) {
        Msg::Error("%s (GUI internal error)", text.c_str());
      };
    // files dropped on the interface: the first is opened, the rest merged
    host.filesDropped = [this](const std::vector<std::string> &paths) {
      for(std::size_t i = 0; i < paths.size(); i++) {
        if(i == 0)
          OpenProject(paths[i]);
        else
          MergeFile(paths[i]);
      }
      drawContext::global()->draw();
    };
    // the last window is gone
    host.quitting = [this]() { projectQuit(); };
    // draw the scene, if it is in a window of its own
    host.tick = [this]() { pumpScene(true); };
    host.sceneImage = [this](int &w, int &h, bool always) {
      return scenePicture(w, h, always);
    };
    host.sceneMoved = [this]() { return sceneMoved(); };
    host.layoutChanged = [this](const Ui::Backend::Layout &l) { _takeLayout(l); };
    host.sceneResize = [this](int w, int h) { sceneResize(w, h); };
    host.scenePointer = [this](double x, double y, int button, int what,
                           double wheel, bool shift, bool ctrl, bool alt) {
      scenePointer(x, y, button, what, wheel, shift, ctrl, alt);
    };
    made->setHost(host);

    // everything it is allowed to know of Gmsh: the descriptions, asked for
    // again rather than handed over
    Ui::Backend::Sources sources;
    // what the interface lays itself out from, read again every time it is
    // asked so that an interface which draws itself afresh follows an option
    // that has just been set
    sources.settings = [this]() {
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
      s.showModuleMenu = c->showModuleMenu ? true : false;
      s.deltaFontSize = c->deltaFontSize;
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
    sources.menuBar = [this]() { return Menu::bar(); };
    sources.menuGeneration = [this]() { return Menu::generation(); };
    sources.keys = [this]() { return Menu::keys(); };
    sources.tree = Modules::tree();
    sources.barButtons = [this]() { return StatusBar::bar(); };
    sources.saveMessages = [this]() { messagesSaveAs(); };
    sources.barMessage = [this]() { return StatusBar::message(); };
    sources.barTooltip = [this]() { return StatusBar::messageTooltip(); };
    sources.barPressed = [this]() { StatusBar::messagePressed(); };
    made->setSources(sources);

    if(!made->create(argc, argv, quitShouldExit)) {
      delete made;
      return;
    }
    _backend = made;
    _quitShouldExit = quitShouldExit;
    // whether this interface shows the scene itself has to be said before
    // anything else: a message reported while the options are being set
    // pumps the loop, and that is what puts a window up
    if(made->showsScene()) sceneShownElsewhere();

    // the welcome
    InitOptionsGUI(0);
    // the two fonts of the scene are named in the options and resolved by the
    // draw context; the options were read before it existed
    opt_general_graphics_font(0, GMSH_SET, CTX::instance()->glFont);
    opt_general_graphics_font_title(0, GMSH_SET, CTX::instance()->glFontTitle);
    Msg::ResetErrorCounter();
    Msg::StatusBar(false, "Gmsh %s", GetGmshVersion());
    Msg::Direct("-------------------------------------------------------");
    PrintBuildInfo();
    Msg::Direct("-------------------------------------------------------");
    // and a scene of its own, for an interface that holds none
    pumpScene(false);
    // in case the interface is created after some data has been loaded
    updateViews(true, true);
    setGraphicTitle(GModel::current()->getFileName());
    // so that there is a bounding box even with no model and no data
    SetBoundingBox();
  }

  void Gui::destroy()
  {
    if(!_backend) return;
    Ui::Backend *was = _backend;
    // nothing reaches it from here on, and it is deleted once its loop has
    // unwound: see _retired
    _backend = nullptr;
    was->destroy();
    delete _retired;
    _retired = was;
  }

  int Gui::run(const std::string &optionFileName)
  {
    if(!_backend) return 0;
    if(optionFileName.size()) MergeFile(optionFileName, false);
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

  std::string Gui::toolkitVersion()
  {
    return _backend ? _backend->name() : "";
  }

  bool Gui::quitShouldExit() { return _quitShouldExit; }

  // --- the event loop

  void Gui::check(bool rateLimited)
  {
    // only the thread that draws may pump: the mesher reports from its
    // OpenMP threads
    if(!_backend || Msg::GetThreadNum() > 0) return;
    for(const std::string &name : _changedOptions) _backend->optionChanged(name);
    _changedOptions.clear();
    _backend->check(rateLimited);
    // a scene in a window of its own is pumped from here
    pumpScene(rateLimited);
  }

  bool Gui::ready() { return _backend && _backend->ready(); }

  void Gui::wait(bool force)
  {
    if(!_backend) return;
    _backend->wait(-1., force);
    pumpScene(false);
  }

  void Gui::wait(double time, bool force)
  {
    if(_backend) _backend->wait(time, force);
  }

  void Gui::lock()
  {
    if(_backend) _backend->lock();
  }

  void Gui::unlock()
  {
    if(_backend) _backend->unlock();
  }

  int Gui::locked() { return _backend ? _backend->locked() : 0; }

  void Gui::awake(const std::string &action)
  {
    if(!_backend) return;
    // from a thread that is not the one drawing
    _backend->postFromThread([this, action]() {
      if(action.empty() || action == "update")
        updateViews(true, false);
      else
        Msg::Debug("Unknown awake action '%s'", action.c_str());
    });
  }

  void Gui::copyText(const std::string &text)
  {
    if(_backend) _backend->copyText(text);
  }

  void Gui::beep()
  {
    if(_backend) _backend->beep();
  }

  // --- messages, the bar, and the questions that stop everything
  //
  // What the bar says is worked out once in GuiStatus.cpp and read by
  // whichever bar is drawing it; all that is left here is to say that it
  // changed.

  void Gui::addMessage(const std::string &msg, int level)
  {
    if(_backend) _backend->addMessage(msg, level);
  }

  void Gui::messageLines(std::vector<std::string> &lines)
  {
    lines.clear();
    if(_backend) _backend->messageLines(lines);
  }

  void Gui::setStatus(const std::string &msg, bool graphics)
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

  void Gui::setLastStatus(int color)
  {
    if(!_backend || Msg::GetThreadNum() > 0) return;
    // the colour it is worth, not the colour it is
    StatusBar::setColour(color);
    _backend->refreshBar();
  }

  void Gui::setProgress(const std::string &msg, double val, double min, double max)
  {
    if(!_backend || Msg::GetThreadNum() > 0) return;
    StatusBar::setProgress(val, min, max);
    setStatus(msg);
  }

  void Gui::setGraphicTitle(const std::string &title)
  {
    if(!_backend) return;
    // the second window and the ones after it are numbered
    for(int i = 0; i < _backend->numWindows(); i++) {
      std::string say = "Gmsh";
      if(title.size()) {
        say += " - " + title;
        if(i) say += " [" + std::to_string(i) + "]";
      }
      _backend->setWindowTitle(i, say);
    }
  }

  bool Gui::inputDialog(const std::string &question, std::string &value,
                   const std::string &hint, bool readOnly)
  {
    return _backend ?
             _backend->inputDialog(question, value, hint, readOnly) :
             false;
  }

  int Gui::questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two)
  {
    return _backend ? _backend->questionDialog(question, zero, one, two) : 0;
  }

  bool Gui::fileDialog(int mode, const std::string &title,
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

  bool Gui::fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::string &fileName, int &chosenFormat)
  {
    std::vector<std::string> names(1, fileName);
    if(!fileDialog(mode, title, formats, names, chosenFormat)) return false;
    fileName = names.empty() ? "" : names[0];
    return true;
  }

  bool Gui::fileDialog(int mode, const std::string &title,
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

  int Gui::exportOptionsDialog(int format, const std::string &fileName,
                          const std::string &entry)
  {
    if(!_backend) return ExportCancelled;
    return Export::askOptions(format, fileName, entry);
  }

  void Gui::applyColorScheme(bool redraw)
  {
    if(!_backend) return;
    // General.FltkColorScheme says "use a dark interface"; which colours that
    // means is the toolkit's
    _backend->applyColorScheme(CTX::instance()->guiColorScheme ? true : false);
    if(redraw) drawContext::global()->draw();
  }

  void Gui::showContextWindow(int dim, int tag) { onelabContext.show(dim, tag); }

  void Gui::configureGamepad() { gamepad.show(); }

  void Gui::updateFields()
  {
    // the window has one line more or one option fewer: a matter of shape,
    // not of value
    fields.rebuild();
  }

  // the panels the menus show and hide: every one of them is a dialog except
  // the message console

  // --- what a GuiDialog asks of the interface

  void Gui::showForm(const Ui::Form &form, bool show)
  {
    if(_backend) _backend->showForm(form, show);
  }

  bool Gui::formVisible(const Ui::Form &form)
  {
    return _backend && _backend->formVisible(form);
  }

  std::string Gui::formPane(const Ui::Form &form)
  {
    return _backend ? _backend->formPane(form) : "";
  }

  void Gui::setFormPane(const Ui::Form &form, const std::string &pane)
  {
    if(_backend) _backend->setFormPane(form, pane);
  }

  void Gui::reloadForm(const Ui::Form &form)
  {
    if(_backend) _backend->reloadForm(form);
  }

  std::string Gui::optionName(const std::string &category,
                              const std::string &name, int index)
  {
    return category + (index ? "[" + std::to_string(index) + "]" : "") + "." +
           name;
  }

  void Gui::optionChanged(const std::string &category, const std::string &name,
                          int index)
  {
    if(!_backend) return;
    std::string full = optionName(category, name, index);
    // told from a thread that may not touch the interface: kept for check()
    if(Msg::GetThreadNum() > 0) {
      _changedOptions.insert(full);
      return;
    }
    _backend->optionChanged(full);
  }

  void Gui::rebuildForm(const Ui::Form &form)
  {
    if(_backend) _backend->rebuildForm(form);
  }

  void Gui::dropForm(const Ui::Form &form)
  {
    if(_backend) _backend->dropForm(form);
  }

  GuiDialog *Gui::_panelDialog(int panel)
  {
    switch(panel) {
    case PanelOptions: return &options;
    case PanelVisibility: return &visibility;
    case PanelPlugins: return &plugins;
    case PanelFields: return &fields;
    case PanelKeyboardAndMouse: return &shortcuts;
    case PanelCurrentOptions: return &currentOptions;
    case PanelAbout: return &about;
    case PanelClassify: return &classify;
    default: return nullptr;
    }
  }

  bool Gui::panelVisible(int panel)
  {
    if(!_backend) return false;
    if(panel == PanelMessageConsole) return _backend->consoleVisible();
    GuiDialog *d = _panelDialog(panel);
    return d && d->visible();
  }

  void Gui::showPanel(int panel, bool show)
  {
    if(!_backend) return;
    if(panel == PanelMessageConsole) {
      // the count of errors the bar shows is of those not yet looked at:
      // showing the console is looking at them
      if(show) Msg::ResetErrorCounter();
      _backend->showConsole(show);
      return;
    }
    GuiDialog *d = _panelDialog(panel);
    if(!d) return;
    if(show)
      d->show();
    else
      d->hide();
  }

  // --- the modules tree, and what has to be looked at again

  void Gui::rebuildTree(bool deleteWidgets)
  {
    // built again means its shape changed
    if(deleteWidgets) Modules::invalidate();
    if(_backend) _backend->refreshTree(deleteWidgets);
    // the per-entity parameters come from the same server: a parameter that
    // arrived is a field more
    if(onelabContext.visible()) onelabContext.rebuild();
  }

  void Gui::openModule(const std::string &name)
  {
    // a module is opened when what it is about happens -- a mesh was made,
    // so Mesh opens -- but not one the user folded away by hand
    if(!_backend) return;
    std::string path = "0Modules/" + name;
    Ui::Tree tree = Modules::tree();
    if(tree.closed && tree.closed(path)) return;
    _backend->openTreeItem(path, true);
  }

  void Gui::toggleModule(const std::string &name)
  {
    if(!_backend) return;
    std::string item = "0Modules/" + name;
    _backend->openTreeItem(item, !_backend->treeItemOpen(item));
  }

  void Gui::openTreeItem(const std::string &name)
  {
    if(_backend) _backend->openTreeItem(name, true);
  }

  void Gui::closeTreeItem(const std::string &name)
  {
    if(_backend) _backend->openTreeItem(name, false);
  }

  void Gui::updateViews(bool numberOfViewsHasChanged, bool deleteWidgets)
  {
    if(!_backend) return;
    // the bar has a button that only makes sense with a view that has several
    // time steps
    _backend->refreshBar();
    if(!numberOfViewsHasChanged) return;
    // the views are lines of the tree: one more, one less, or one renamed,
    // is a change of its shape
    Modules::invalidate();
    _backend->refreshTree(deleteWidgets);
    // a parameter a solver added is a field more: a matter of shape
    onelabContext.rebuild();
    // a view is a tab of the option window
    options.rebuild();
    // the size-field window offers the views a field may be drawn on
    updateFields();
    clipping.reload();
    statisticsRefresh(false);
  }

  void Gui::resetVisibility()
  {
    visibility.reload();
    currentOptions.reload();
    statisticsRefresh(false);
  }

  void Gui::fillRecentHistoryMenu()
  {
    // the recent files are part of the menu description, so the menus simply
    // have to be built again
    Menu::invalidate();
    if(_backend) _backend->refreshMenus();
  }

  // --- the solver

  void Gui::onelabAction(const std::string &action)
  {
    if(!_backend) return;
    // a run cannot happen while a frame is being drawn: it meshes, it draws,
    // and it may ask a question
    _backend->post([this, action]() {
      onelabRun(action);
      if(action != "initialize" && _backend) _backend->showTree();
    });
  }

  bool Gui::solverBusy() { return solverIsRunning(); }

  void Gui::startSolver(int index)
  {
    solverStart(index); // it compacts the solver list itself
    if(solverIsRunning() && _backend) _backend->showTree();
  }

  void Gui::exportView(int index)
  {
#if defined(HAVE_POST)
    if(index < 0 || index >= (int)PView::list.size()) return;
    PView *view = PView::list[index];
    // the formats a view may be written in, and what PView::write() numbers
    // each of them; four of them are ".pos", which is why the chooser names
    // its formats
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

  void Gui::fileAction(const std::string &what)
  {
    if(!_backend) return;
    // each of them opens a chooser, so none of them can run inside a frame
    // that is being drawn
    if(what == "new")
      _backend->post(fileNew);
    else if(what == "open")
      _backend->post([this]() { fileOpen(false); });
    else if(what == "merge")
      _backend->post([this]() { fileOpen(true); });
    else if(what == "rename")
      _backend->post(fileRename);
    else if(what == "watch")
      _backend->post([this]() { history.showWatchPattern(); });
    else if(what.compare(0, 7, "remote_") == 0) {
      std::string which = what.substr(7);
      _backend->post([which]() { fileRemote(which); });
    }
    else if(what == "export")
      _backend->post(fileExport);
    else
      Msg::Error("Unknown file action '%s'", what.c_str());
  }

  void Gui::pumpChrome(bool rateLimited)
  {
    if(_backend) _backend->check(rateLimited);
  }

  void Gui::watchFile()
  {
    watchFiles();
  }

  // where the interface left its windows, written where the option file
  // reads them; a value it has nothing to say about keeps what it was
  void Gui::_takeLayout(const Ui::Backend::Layout &l)
  {
    CTX *c = CTX::instance();
    auto take = [this](int &into, int value) {
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

  void Gui::storeCurrentWindowsInfo()
  {
    if(_backend) _takeLayout(_backend->windowLayout());
  }

  void Gui::setSolverButtonMode(const std::string &button0,
                           const std::string &button1)
  {
    _solverButton0 = button0;
    _solverButton1 = button1;
    if(_backend) _backend->setSolverButtonMode(button0, button1);
  }

  void Gui::solverButtons(std::string &button0, std::string &button1)
  {
    button0 = _solverButton0;
    button1 = _solverButton1;
  }

  void Gui::drawTooltip(const std::string &text)
  {
    if(_backend) _backend->drawTooltip(text);
  }

  void Gui::windowAction(const std::string &what)
  {
    if(_backend) _backend->windowAction(what);
  }

  void Gui::setSceneSize(int width, int height)
  {
    if(_backend) _backend->setSceneSize(width, height);
  }

  void Gui::setConsoleFontSize(int size)
  {
    if(_backend) _backend->setConsoleFontSize(size);
  }

  void Gui::setTreeWidth(int width)
  {
    if(_backend) _backend->setTreeWidth(width);
  }

  void Gui::detachTree(bool detached)
  {
    if(_backend) _backend->detachTree(detached);
  }

  void Gui::enableTooltips(bool on)
  {
    if(_backend) _backend->enableTooltips(on);
  }

  void Gui::refreshBar()
  {
    if(_backend) _backend->refreshBar();
  }

  bool Gui::supportsWindowAction(const std::string &what)
  {
    return _backend && _backend->supports(what);
  }

  // --- what the interface remembers for the rest of Gmsh

  void Gui::setFinishedProcessingCommandLine()
  {
    _finishedProcessingCommandLine = true;
  }

  bool Gui::getFinishedProcessingCommandLine()
  {
    return _finishedProcessingCommandLine;
  }

  void Gui::setOpenedThroughMacFinder(const std::string &name)
  {
    _openedThroughMacFinder = name;
  }

  std::string Gui::getOpenedThroughMacFinder()
  {
    return _openedThroughMacFinder;
  }


#endif
