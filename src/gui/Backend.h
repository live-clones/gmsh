// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_BACKEND_H
#define UI_BACKEND_H

#include <functional>
#include <string>
#include <vector>

#include "Form.h"
#include "Menu.h"
#include "Bar.h"

// What a widget toolkit has to provide for Gmsh to have an interface, and
// nothing else.
//
// This directory is the vocabulary the two sides speak, and it belongs to
// neither of them: it includes nothing of Gmsh -- not GmshConfig.h, not
// ColorTable.h, no GModel, no drawContext -- and it names no toolkit. Form.h,
// Menu.h and Bar.h beside it say what a form, a menu and a bar are; this file
// says what one does with them.
//
// The two rules it exists to make checkable, one per side:
//
//   src/common/Gui*   describes and acts, and never knows which backend is
//                     running: it holds Ui::Backend *, and the only #if left
//                     is the one that decides which makeUiBackend() is linked.
//
//   src/fltk, src/imgui   build widgets, and never call Gmsh. They are handed
//                     what they need through Sources below, and everything
//                     that has to come back is a std::function that the
//                     description carries -- what a field does when it
//                     changes, what a menu entry runs, what a button is worth
//                     right now -- plus the four upcalls at the end of this
//                     file.
//
// The second rule has an allow list, and there is exactly one thing on it:
// OS.h, because it abstracts the operating system rather than Gmsh -- a clock
// and a stat are all the interfaces ask of it -- and there is nothing to be
// gained by every backend writing its own.
//
// Not GmshConfig.h, although every file of both interfaces includes it today.
// It carries the whole feature map of Gmsh -- HAVE_POST, HAVE_MESH,
// HAVE_ONELAB, HAVE_OPENCASCADE -- and having it at hand is how a backend
// starts knowing that post-processing exists, which is the leak this file is
// against. It is only there for the #if that guards each file, and that guard
// is redundant: CMake adds src/fltk and src/imgui to the build only under
// ENABLE_FLTK and ENABLE_IMGUI, so a file of an interface that was not asked
// for is never compiled in the first place. The guards go, and the rule
// becomes what one wants to be able to say in one breath: a file of the chrome
// includes nothing of Gmsh but OS.h.
//
// The granularity is deliberately the whole described thing -- a form, a menu,
// the row of buttons -- and never the single widget. Laying out a form is
// exactly what the two toolkits do differently: FLTK measures the labels with
// fl_width() and puts down coordinates once, Dear ImGui stacks them afresh at
// every frame. A factory of widgets would drag that difference into the
// shared side; a factory of forms leaves it where it belongs. This is why
// showForm() takes a number and not a list of widgets: the backend fetches
// the description itself, through Sources::form, as often as it needs it.
//
// What is NOT here: the 3D scene. Picking answers with model entities, the
// capture with a pixel buffer, and both are Gmsh through and through. It is
// its own chantier, to be started once the chrome is done and to be rewritten
// rather than adapted, so it stays in GuiScene.h on the Gmsh side with the
// signatures it has today. Putting it here now would mean a vocabulary born
// with a hole in it.

namespace Ui {

  class Backend {
  public:
    virtual ~Backend() {}

    // --- what the interface is given
    //
    // Everything the backend may know, handed to it once, before create(). A
    // description is asked for again rather than kept: the menus name the
    // files that were opened recently, a form says in a Label field what the
    // model is made of, and both are true only at the moment they are drawn.
    // Dear ImGui asks at every frame; FLTK asks when it is told something
    // changed, which is what the refresh calls below are for.

    struct Sources {
      // the description of one form, by the number the shared side gave it
      std::function<Form(int form)> form;
      // the menu bar, and a counter that changes when it would come out
      // different, so that an interface holding real menu widgets knows when
      // to build them again instead of doing it at every frame
      std::function<std::vector<MenuItem>()> menuBar;
      std::function<unsigned()> menuGeneration;
      // the modules tree: the entries down to where the parameters of the
      // solver begin, which are widgets and are described as a form
      std::function<std::vector<MenuItem>()> treeItems;
      // the row of little buttons along the bottom, and what fills the rest of
      // it: the last message and the progress of what is running
      std::function<std::vector<BarButton>()> barButtons;
      std::function<BarMessage()> barMessage;
      std::function<std::string()> barTooltip;
      std::function<void()> barPressed;
    };
    virtual void setSources(const Sources &sources) = 0;

    // --- what the toolkit is

    // name and version, for "gmsh -info"
    virtual std::string name() = 0;
    // Whether this interface has anything to do for that action, so that the
    // menus can leave out what would do nothing rather than grey it: an
    // interface with a single window has nothing to bring to the front, and
    // one that cannot reach the clipboard should not offer to. The words are
    // those of windowAction() below.
    virtual bool supports(const std::string &what) { return true; }

    // --- life cycle and the event loop

    virtual bool create(int argc, char **argv) = 0;
    virtual void destroy() = 0;
    // run until there is no window left; merging and saving the option file
    // around it is not the toolkit's business and is done by the caller
    virtual int run() = 0;

    // process the pending events, if any; rateLimited asks to do nothing when
    // a check was made less than one refresh period ago
    virtual void check(bool rateLimited) = 0;
    virtual bool ready() = 0;
    // wait for events and process them; seconds < 0 waits indefinitely
    virtual void wait(double seconds, bool force) = 0;
    // against child threads
    virtual void lock() {}
    virtual void unlock() {}
    virtual int locked() { return 0; }

    // Run this in the main loop rather than here and now. A toolkit that can
    // nest a modal window runs it at once, an immediate mode one waits for the
    // frame to be over, and neither the caller nor the shared side has to know
    // which it is dealing with. It is what postAction() is in the Dear ImGui
    // interface today, and it is the one place that difference should live.
    virtual void post(const std::function<void()> &what) { what(); }
    // and the same from another thread, which has to wake the loop up
    virtual void postFromThread(const std::function<void()> &what) = 0;

    // --- the things that are described
    //
    // One call per described thing. The backend builds it from Sources, keeps
    // whatever it has to keep, and is told when to look again.

    virtual void showForm(int form, bool show) = 0;
    virtual bool formVisible(int form) = 0;
    // Its values changed but not its shape: push them into the widgets. An
    // interface that draws the description afresh at every frame has nothing
    // to do here, which is why this is not pure.
    virtual void refreshForm(int form) {}
    // Its shape changed -- the plugin window is showing another plugin, the
    // size-field window another field -- so what was built for the old one is
    // no longer right.
    virtual void rebuildForm(int form) { refreshForm(form); }

    // the menu bar would come out different: read it again
    virtual void refreshMenus() {}
    // Drop a menu where the pointer is. `key` names the place it was dropped
    // from -- the quick access button, a view of the tree -- so that the
    // interface can reopen it under the entry that was picked last time,
    // which is what the popup menus of the bar do.
    virtual void popupMenu(const std::vector<MenuItem> &items,
                           const std::string &key) = 0;

    // the modules tree: what it says changed, or what it is made of did
    virtual void refreshTree(bool rebuild) = 0;
    virtual void openTreeItem(const std::string &name, bool open) = 0;
    // the two buttons under it, whose labels are ("check", "compute") when the
    // solver is idle and ("", "stop") while it runs
    virtual void setSolverButtonMode(const std::string &button0,
                                     const std::string &button1) = 0;

    // the last message or the progress changed: the bar is to draw again
    virtual void refreshBar() {}

    // The message console. It is the one part that is not a form: a window in
    // one interface and a strip under the scene in the other.
    virtual void showConsole(bool show) = 0;
    virtual bool consoleVisible() = 0;
    virtual void addMessage(const std::string &text, int level) = 0;
    // what it holds, in the order it holds it; writing it to a file is done
    // once, by the caller
    virtual void messageLines(std::vector<std::string> &lines) = 0;

    // --- asking the user
    //
    // Each of these runs a loop of its own until there is an answer, which is
    // why none of them can be shared: it is the toolkit that owns the loop.

    virtual bool inputDialog(const std::string &question,
                             std::string &value) = 0;
    // two or three answers, of which the last two may be empty; returns which
    virtual int questionDialog(const std::string &question,
                               const std::string &zero, const std::string &one,
                               const std::string &two) = 0;
    // Pick a file: mode is 0 to open an existing one and 1 to create one,
    // filter a space separated list of patterns. This is the poorest thing in
    // this file and it is known: naming the formats is what would let the
    // export of a view be written once instead of twice, since the four
    // flavours of ".pos" cannot be told apart by an extension. Making a good
    // chooser is a chantier of its own; the signature stays as it is until
    // then.
    virtual bool fileDialog(int mode, const std::string &title,
                            const std::string &filter,
                            std::string &fileName) = 0;
    // Ask for the options of an output format, if this interface asks for them
    // in a window of its own. The FLTK chooser offers them inside itself and
    // has nothing more to ask, which is what the default answers.
    virtual bool formatOptionsDialog(int format, const std::string &fileName)
    {
      return true;
    }

    virtual void beep() {}
    virtual void copyText(const std::string &text) {}

    // --- the interface as a whole

    // "new", "split_h", "split_v", "split_u", "minimize", "zoom",
    // "fullscreen", "front", "attach_detach", "copy": what supports() answers
    // about
    virtual void windowAction(const std::string &what) = 0;
    // where the windows are and how big they are, for the option file, in the
    // order the caller wrote them
    virtual void storeWindowLayout() {}
    virtual void applyColorScheme(bool dark, bool redraw) {}

    // --- what the backend may call back
    //
    // The whole of it. Anything else a toolkit wants to say belongs in a
    // std::function inside a description, where the thing it is about can put
    // it, rather than here. A fifth one appearing is the sign that a
    // description is missing.

    struct Host {
      // the user closed a form with the button of its frame rather than
      // through a menu, so that what the description says it undoes is undone
      // and the menu entry that raises it stops looking pressed
      std::function<void(int form)> formWasClosed;
      // and the same for the message console
      std::function<void()> consoleWasClosed;
      // an internal error of the toolkit, which goes to the message console
      // like any other
      std::function<void(const std::string &text)> error;
      // the last window is gone: run() is about to return
      std::function<void()> quitting;
    };
    virtual void setHost(const Host &host) = 0;
  };

} // namespace Ui

// The one that was compiled in. Exactly one GUI directory is built -- FLTK or
// Dear ImGui, never both -- and it defines this; there is no #if left in the
// shared side as a result. A build with no interface defines it to return
// null, which is what Gui::available() comes down to.
Ui::Backend *makeUiBackend();

#endif
