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
#include "GuiStatus.h"
#include "StringUtils.h"
#include "drawContext.h"

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

  bool inputDialog(const std::string &question, std::string &value)
  {
    return _backend ? _backend->inputDialog(question, value) : false;
  }

  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two)
  {
    return _backend ? _backend->questionDialog(question, zero, one, two) : 0;
  }

  bool fileDialog(int mode, const std::string &title,
                  const std::string &filter, std::string &fileName)
  {
    return _backend ? _backend->fileDialog(mode, title, filter, fileName) :
                      false;
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
