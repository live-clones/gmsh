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
#include "Tree.h"

// What a widget toolkit has to provide for the application to have an
// interface, and nothing else.
//
// This directory is the vocabulary the two sides speak, and belongs to
// neither: it includes nothing of Gmsh and names no toolkit. Form.h, Menu.h,
// Tree.h and Bar.h say what a form, a menu, a tree and a bar are; this file
// says what one does with them.
//
// Two rules, one per side. src/gui describes and acts, and never knows which
// backend is running. src/fltk, src/imgui and src/browser build widgets and
// never call Gmsh: they are handed what they need through Sources, and
// everything that has to come back is a std::function the description carries
// -- what a field does when it changes, what a menu entry runs -- plus the
// upcalls of Host. The one Gmsh header an interface may include is OS.h,
// which abstracts the operating system rather than Gmsh.
//
// The granularity is the whole described thing -- a form, a menu, the row of
// buttons -- never the single widget: laying out a form is exactly what the
// toolkits do differently, and a factory of forms leaves that difference where
// it belongs. A dialog is handed over as a way of describing it, and the
// backend fetches the description as often as it needs it.
//
// What is not here: the 3D scene. Picking answers with model entities, the
// capture with a pixel buffer, and both are Gmsh through and through; it stays
// in GuiScene.h on the Gmsh side.

namespace Ui {

  class Backend {
  public:
    virtual ~Backend() {}

    // how loud a message is, which is only what to colour it: the text already
    // carries the prefix
    enum Level { Direct = 0, Info, Warning, Error, Debug };

    // --- what the interface is given
    //
    // Everything the backend may know, handed to it once, before create(). A
    // description is asked for again rather than kept: what it says is true only
    // at the moment it is drawn. An interface that draws afresh asks at every
    // frame; one that holds widgets asks when it is told something changed, which
    // is what the refresh calls below are for.

    // What the interface lays itself out from: how big to draw, what the parts
    // of the window are worth, and the handful of behaviours a widget answers
    // to. Settings of the application, the same for every interface. The
    // set...() further down are the other half: an interface that holds widgets
    // is told when one of these changes.
    struct Settings {
      // how tall the interface font is, in points; 0 for the toolkit's own
      int fontSize;
      // what a window that has just come up is made of, in pixels; an interface
      // that lays itself out differently reads what it needs of this
      int sceneX, sceneY, sceneWidth, sceneHeight, treeWidth, consoleHeight;
      int consoleFontSize;
      // how many views the scene of a new window is cut into
      int sceneTiles;
      // the tree as a window of its own: where it opens, how tall it is
      int treeX, treeY, treeHeight;
      // where a dialog opens, for an interface that places its own windows
      int dialogX, dialogY;
      // what the scene asks of the windowing system, besides antialiasing
      bool doubleBuffer, stereo;
      // the menu bar is the system's rather than a widget, where there is one
      bool systemMenuBar;
      // a dark interface rather than a light one
      bool darkScheme;
      // the commands are shown in the tree, over what a solver publishes
      bool showModuleMenu;
      // how many points the lines of the tree are drawn smaller than the
      // rest, for an interface that draws them in the interface font
      int deltaFontSize;
      // ask the windowing system for a multisampled visual
      bool antialiasing;
      // little labels appear under the pointer
      bool tooltips;
      // the tree is a window of its own rather than standing beside the scene
      bool detachedTree;
      // the wheel over a value changes it: whether a value may be dragged at
      // all, and how many decimals one is shown to
      bool inputScrolling;
      // a dialog leaves the rest of the interface usable while it is up
      bool nonModalWindows;
      // what is behind the model, for the one widget that sits on the scene's
      // own background: the colour map of a view
      Colour background;
      // how many frames a second the interface may be pumped at; 0 for as
      // often as it likes
      double refreshRate;
      // where the user's own files are: what a chooser opens on
      std::string homeDir;
      Settings()
        : fontSize(0), sceneX(0), sceneY(0), sceneWidth(0), sceneHeight(0),
          treeWidth(0), consoleHeight(0), consoleFontSize(0), sceneTiles(1),
          treeX(0), treeY(0), treeHeight(0), dialogX(0), dialogY(0),
          doubleBuffer(true), stereo(false), systemMenuBar(false),
          darkScheme(false), showModuleMenu(true), deltaFontSize(0),
          antialiasing(false), tooltips(true),
          detachedTree(false), inputScrolling(true), nonModalWindows(false),
          refreshRate(0.)
      {
      }
    };

    // Where the windows ended up, in pixels, -1 where the interface has nothing
    // to say; the other half of Settings, going the other way. The console keeps
    // the height it had when it was last shown, even while hidden; so does the
    // tree as a window of its own, even while it stands beside the scene.
    struct Layout {
      int sceneX, sceneY, sceneWidth, sceneHeight;
      int consoleHeight;
      int treeWidth;
      int treeDetached; // 1, 0, or -1 for nothing to say
      int treeX, treeY, treeHeight;
      int dialogX, dialogY;
      int chooserX, chooserY;
      Layout()
        : sceneX(-1), sceneY(-1), sceneWidth(-1), sceneHeight(-1),
          consoleHeight(-1), treeWidth(-1), treeDetached(-1), treeX(-1),
          treeY(-1), treeHeight(-1), dialogX(-1), dialogY(-1), chooserX(-1),
          chooserY(-1)
      {
      }
    };

    struct Sources {
      std::function<Settings()> settings;
      // the menu bar, and a counter that changes when it would come out
      // different, for an interface that holds real menu widgets
      std::function<std::vector<MenuItem>()> menuBar;
      std::function<unsigned()> menuGeneration;
      // the keys that do something wherever the pointer is, in the order they
      // are to be tried; asked for on a key press, since what an entry does may
      // depend on what is loaded
      std::function<std::vector<KeyBinding>()> keys;
      // the tree down the left side, as one thing: the commands and, under
      // them, whatever a solver has published
      Tree tree;
      // the row of little buttons along the bottom, and what fills the rest of
      // it: the last message and the progress of what is running
      std::function<std::vector<BarButton>()> barButtons;
      std::function<BarMessage()> barMessage;
      std::function<std::string()> barTooltip;
      std::function<void()> barPressed;
      // what the save button of the console runs, chooser included
      std::function<void()> saveMessages;
    };
    virtual void setSources(const Sources &sources) = 0;

    // --- what the toolkit is

    // name and version, for "gmsh -info"
    virtual std::string name() = 0;
    // whether this interface shows the 3D scene itself, by asking for a
    // picture of it; one that does not gets a window of its own, put up by
    // whichever scene is linked
    virtual bool showsScene() { return false; }

    // whether this interface has anything to do for that action, so that the
    // menus can leave out what would do nothing; the words are those of
    // windowAction()
    virtual bool supports(const std::string &what) { return true; }

    // --- life cycle and the event loop

    // quitShouldExit says whether quitting is to leave the process or only to
    // close the windows, which is what the API wants
    virtual bool create(int argc, char **argv, bool quitShouldExit) = 0;
    virtual void destroy() = 0;
    // Run until there is no window left. Only the loop: merging the option
    // file before it and writing it after is done once, by the caller.
    virtual int runLoop() = 0;

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

    // Run this in the main loop rather than here and now: a toolkit that can
    // nest a modal window runs it at once, an immediate mode one waits for the
    // frame to be over.
    virtual void post(const std::function<void()> &what) { what(); }
    // and the same from another thread, which has to wake the loop up
    virtual void postFromThread(const std::function<void()> &what) = 0;

    // --- the things that are described

    // A form is an object of the application, and the interface keeps what
    // it builds for one under its address; the application says when one
    // goes with dropForm(). What a form holds is read from it: it is
    // rewritten in place when its structure changes, and rebuildForm() says
    // so. Nothing is built until a form is shown, and a pane is named by its
    // label.
    virtual void showForm(const Form &form, bool show) = 0;
    virtual bool formVisible(const Form &form) = 0;
    // which pane of it is showing, which is the interface's to keep since a
    // click on a tab is what changes it
    virtual std::string formPane(const Form &form) = 0;
    virtual void setFormPane(const Form &form, const std::string &pane) = 0;
    // its values changed but not its shape; nothing to do for an interface
    // that draws afresh, which is why this is not pure
    virtual void reloadForm(const Form &form) {}
    // its shape changed: what was built for it is no longer right
    virtual void rebuildForm(const Form &form) { reloadForm(form); }
    virtual void dropForm(const Form &form) = 0;

    // the menu bar would come out different: read it again
    virtual void refreshMenus() {}
    // drop a menu where the pointer is; `key` names the place it was dropped
    // from, so that it can reopen under the entry picked last time
    virtual void popupMenu(const std::vector<MenuItem> &items,
                           const std::string &key) {}

    // the modules tree: what it says changed, or what it is made of did
    virtual void refreshTree(bool rebuild) = 0;
    virtual void openTreeItem(const std::string &name, bool open) = 0;
    // whether a branch is unfolded, which is the interface's to know: a
    // click on it is what changes it
    virtual bool treeItemOpen(const std::string &name) = 0;
    // whether it is closed because the user closed it, as opposed to because
    // it has never been opened: a module opened by what happens is not one
    // the user folded away by hand
    virtual void showTree() {}
    // the two buttons under it: ("check", "compute") when the solver is idle,
    // ("", "stop") while it runs
    virtual void setSolverButtonMode(const std::string &button0,
                                     const std::string &button1) = 0;

    // the last message or the progress changed: the bar is to draw again
    virtual void refreshBar() = 0;
    // a transient note next to the pointer over the 3D view; an empty text
    // takes it away
    virtual void drawTooltip(const std::string &text) {}
    // the windows the interface has, and what each is called
    virtual int numWindows() { return 1; }
    virtual void setWindowTitle(int which, const std::string &title) {}

    // the message console, the one part that is not a form
    virtual void showConsole(bool show) = 0;
    virtual bool consoleVisible() = 0;
    virtual void addMessage(const std::string &text, int level) = 0;
    // what it holds, in the order it holds it
    virtual void messageLines(std::vector<std::string> &lines) = 0;

    // --- asking the user
    //
    // Each of these runs a loop of its own until there is an answer.

    // `hint` is a line under the question saying what shape the answer takes;
    // `readOnly` shows the value instead of asking for it
    virtual bool inputDialog(const std::string &question, std::string &value,
                             const std::string &hint, bool readOnly) = 0;
    // two or three answers, of which the last two may be empty; returns which
    virtual int questionDialog(const std::string &question,
                               const std::string &zero, const std::string &one,
                               const std::string &two) = 0;
    // one of the formats a chooser offers: what it is called, and what it
    // matches; several may share an extension, which is why they are named
    struct FileFormat {
      std::string name, pattern;
      FileFormat(const std::string &n = "", const std::string &p = "")
        : name(n), pattern(p)
      {
      }
    };
    // Pick a file: mode is 0 to open an existing one, 1 to create one, 2 to
    // open several at once. `names` comes in holding what to start from and
    // goes out holding what was picked. `chosenFormat`, when given, is set to
    // the place in `formats` of the one that was used, or to -1 by a chooser
    // that cannot say.
    enum { Open = 0, Create, OpenSeveral };
    virtual bool fileDialog(int mode, const std::string &title,
                            const std::vector<FileFormat> &formats,
                            std::vector<std::string> &names,
                            int *chosenFormat) = 0;
    virtual void beep() {}
    virtual void copyText(const std::string &text) {}

    // --- the interface as a whole

    // "new", "split_h", "split_v", "split_u", "minimize", "zoom",
    // "fullscreen", "front", "attach_detach", "copy": what supports() answers
    // about
    virtual void windowAction(const std::string &what) = 0;
    // where the windows are and how big they are, asked when the option file
    // is about to be written; an interface whose layout is its own to keep
    // answers with the empty Layout
    virtual Layout windowLayout() { return Layout(); }
    // dark or light; redrawing the scene afterwards is the caller's
    virtual void applyColorScheme(bool dark) {}

    // --- what the options that shape the main window push into it
    //
    // The other half of Sources::settings, for an interface that holds widgets
    // and has something to move when one of them changes; one whose layout is
    // its own to keep has nothing to do here. A dimension of -1 leaves that one
    // as it is.
    virtual void setSceneSize(int width, int height) {}
    virtual void setConsoleFontSize(int size) {}
    virtual void setTreeWidth(int width) {}
    virtual void detachTree(bool detached) {}
    virtual void enableTooltips(bool on) {}

    // --- what the backend may call back
    //
    // The whole of it: anything else belongs in a std::function inside a
    // description, where the thing it is about can put it.

    struct Host {
      // the user closed a form with the button of its frame rather than through
      // a menu
      std::function<void(const Form &form)> formWasClosed;
      // and the same for the message console
      std::function<void()> consoleWasClosed;
      // files were dropped on a window of the interface: what that means is the
      // application's
      std::function<void(const std::vector<std::string> &paths)> filesDropped;
      // an internal error of the toolkit, which goes to the message console
      // like any other
      std::function<void(const std::string &text)> error;
      // the last window was closed; what follows is the application's
      std::function<void()> quitting;
      // where a window stood, said as the interface is about to forget it: the
      // tree folded away or put back beside the scene, the console hidden; only
      // the fields about to be lost are filled, the rest is -1
      std::function<void(const Layout &layout)> layoutChanged;
      // one turn of the loop has come round: what the application has to do on
      // its own, such as drawing a scene that is in a window of its own
      std::function<void()> tick;
      // A picture of the 3D scene, for an interface that cannot draw one itself.
      // What comes back is an image and the size it was drawn at. Nothing comes
      // back when the scene has not changed since the last picture, unless
      // `always` asks for it.
      std::function<std::string(int &width, int &height, bool always)>
        sceneImage;
      // whether that picture has changed since the last one was taken, asked
      // without drawing anything
      std::function<bool()> sceneMoved;
      std::function<void(int width, int height)> sceneResize;
      std::function<void(double x, double y, int button, int what,
                         double wheel, bool shift, bool ctrl, bool alt)>
        scenePointer;
    };
    virtual void setHost(const Host &host) = 0;
  };

} // namespace Ui

namespace Ui {

  // Which interface, decided when it comes up rather than when the library
  // was built: every one that was compiled in says so at start-up, under a
  // name -- "fltk", "imgui", "browser" -- and hands over a way of making one.
  // A build with no interface at all offers nothing.
  void offer(const char *name, Backend *(*make)());
  // what there is, in the order it was offered
  const std::vector<std::string> &offered();
  // make one, by name; an empty name means the first there is, a name that
  // was never offered makes nothing
  Backend *make(const std::string &name);
  // which one that was, as it was offered rather than as it calls itself
  const std::string &chosen();
} // namespace Ui

namespace Ui {

  // Which interface, decided when it comes up rather than when the library
  // was built: every one that was compiled in says so at start-up, under a
  // name -- "fltk", "imgui", "browser" -- and hands over a way of making one.
  // A build with no interface at all offers nothing.
  void offer(const char *name, Backend *(*make)());
  // what there is, in the order it was offered
  const std::vector<std::string> &offered();
  // make one, by name; an empty name means the first there is, a name that
  // was never offered makes nothing
  Backend *make(const std::string &name);
  // which one that was, as it was offered rather than as it calls itself
  const std::string &chosen();
} // namespace Ui

#endif
