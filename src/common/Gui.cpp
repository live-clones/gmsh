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
