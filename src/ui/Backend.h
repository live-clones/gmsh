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

// What a widget toolkit has to provide, and nothing else. This directory is
// the vocabulary the two sides speak and belongs to neither: it includes
// nothing of Gmsh and names no toolkit. src/gui describes and acts and never
// knows which backend runs; src/fltk, src/imgui and src/browser build
// widgets and never call Gmsh: they are handed what they need through
// Sources, and what comes back is a std::function the description carries,
// plus the upcalls of Host. The granularity is the whole described thing --
// a form, a menu, the bar -- never the single widget: laying out a form is
// what the toolkits do differently. The 3D scene is not here: see
// GuiScene.h.

namespace Ui {

  class Backend {
  public:
    virtual ~Backend() {}

    // only what to colour a message: the text already carries the prefix
    enum Level { Direct = 0, Info, Warning, Error, Debug };

    // --- what the interface is given, once, before create(); a description is asked for again rather than kept: an interface that draws afresh asks at every frame, one that holds widgets when told something changed

    // settings of the application, the same for every interface; the set...()
    // below are told when one changes
    struct Settings {
      // in points; 0 for the toolkit's own
      int fontSize;
      // in pixels
      int sceneX, sceneY, sceneWidth, sceneHeight, treeWidth, consoleHeight;
      int consoleFontSize;
      int sceneTiles;
      int treeX, treeY, treeHeight;
      int dialogX, dialogY;
      bool doubleBuffer, stereo;
      bool systemMenuBar;
      bool darkScheme;
      bool showModuleMenu;
      // points smaller than the rest
      int deltaFontSize;
      bool antialiasing;
      bool tooltips;
      bool detachedTree;
      // whether a value may be dragged, and how many decimals are shown
      bool inputScrolling;
      bool nonModalWindows;
      // for the one widget on the scene's own background, the colour map
      Colour background;
      // 0 for as often as it likes
      double refreshRate;
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

    // in pixels, -1 where the interface has nothing to say; the console and the
    // tree keep the height they had when last shown
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
      // a counter that changes when the bar would come out different
      std::function<std::vector<MenuItem>()> menuBar;
      std::function<unsigned()> menuGeneration;
      // in the order they are tried; asked on a key press, as what an entry
      // does may depend on what is loaded
      std::function<std::vector<KeyBinding>()> keys;
      Tree tree;
      std::function<std::vector<BarButton>()> barButtons;
      std::function<BarMessage()> barMessage;
      std::function<std::string()> barTooltip;
      std::function<void()> barPressed;
      std::function<void()> saveMessages;
    };
    virtual void setSources(const Sources &sources) = 0;

    // --- what the toolkit is

    virtual std::string name() = 0;
    // an interface showing pictures of the scene; one that does not gets a
    // window of its own
    virtual bool showsScene() { return false; }

    // the words are those of windowAction()
    virtual bool supports(const std::string &what) { return true; }

    // --- life cycle and the event loop

    // quitShouldExit: leave the process, or only close the windows (the API)
    virtual bool create(int argc, char **argv, bool quitShouldExit) = 0;
    virtual void destroy() = 0;
    // only the loop: the option file is merged and written by the caller
    virtual int runLoop() = 0;

    // rateLimited: nothing when a check was made less than one refresh period
    // ago
    virtual void check(bool rateLimited) = 0;
    virtual bool ready() = 0;
    // seconds < 0 waits indefinitely
    virtual void wait(double seconds, bool force) = 0;
    virtual void lock() {}
    virtual void unlock() {}
    virtual int locked() { return 0; }

    // a toolkit that can nest a modal window runs it at once, an immediate mode
    // one waits for the frame to be over
    virtual void post(const std::function<void()> &what) { what(); }
    virtual void postFromThread(const std::function<void()> &what) = 0;

    // --- the things that are described

    // the interface keeps what it builds for a form under its address, until
    // dropForm(); nothing is built until a form is shown; a pane is named by
    // its label
    virtual void showForm(const Form &form, bool show) = 0;
    virtual bool formVisible(const Form &form) = 0;
    // the interface's to keep: a click on a tab changes it
    virtual std::string formPane(const Form &form) = 0;
    virtual void setFormPane(const Form &form, const std::string &pane) = 0;
    // values changed, not the shape: nothing to do for an interface that draws
    // afresh
    virtual void reloadForm(const Form &form) {}
    virtual void rebuildForm(const Form &form) { reloadForm(form); }
    virtual void dropForm(const Form &form) = 0;
    // an interface that keeps widgets puts the value into whichever shows it
    // (Field::option)
    virtual void optionChanged(const std::string &name) {}

    virtual void refreshMenus() {}
    // `key` names the place, so that the menu reopens under the entry picked
    // last time
    virtual void popupMenu(const std::vector<MenuItem> &items,
                           const std::string &key) {}

    virtual void refreshTree(bool rebuild) = 0;
    virtual void openTreeItem(const std::string &name, bool open) = 0;
    // the interface's to know: a click changes it
    virtual bool treeItemOpen(const std::string &name) = 0;
    // closed by the user, as opposed to never opened
    virtual void showTree() {}
    // ("check", "compute") when idle, ("", "stop") while running
    virtual void setSolverButtonMode(const std::string &button0,
                                     const std::string &button1) = 0;

    virtual void refreshBar() = 0;
    virtual int numWindows() { return 1; }
    virtual void setWindowTitle(int which, const std::string &title) {}

    virtual void showConsole(bool show) = 0;
    virtual bool consoleVisible() = 0;
    virtual void addMessage(const std::string &text, int level) = 0;
    virtual void messageLines(std::vector<std::string> &lines) = 0;

    // --- asking the user: each runs a loop of its own until there is an answer

    // hint is a line under the question; readOnly shows the value
    virtual bool inputDialog(const std::string &question, std::string &value,
                             const std::string &hint, bool readOnly) = 0;
    // the last two may be empty; returns which
    virtual int questionDialog(const std::string &question,
                               const std::string &zero, const std::string &one,
                               const std::string &two) = 0;
    // several formats may share an extension, which is why they are named
    struct FileFormat {
      std::string name, pattern;
      FileFormat(const std::string &n = "", const std::string &p = "")
        : name(n), pattern(p)
      {
      }
      // the pattern as plain patterns, one per extension: "*.{geo,msh}" is
      // "*.geo", "*.msh"; "*.*" is "*"; separated by blanks or ';'
      std::vector<std::string> patterns() const;
    };
    // mode 0 opens, 1 creates, 2 opens several; names comes in with what to
    // start from; chosenFormat is the place in formats, -1 when the chooser
    // cannot say
    enum { Open = 0, Create, OpenSeveral };
    virtual bool fileDialog(int mode, const std::string &title,
                            const std::vector<FileFormat> &formats,
                            std::vector<std::string> &names,
                            int *chosenFormat) = 0;
    virtual void beep() {}
    virtual void copyText(const std::string &text) {}

    // --- the interface as a whole

    // "new", "split_h", "split_v", "split_u", "minimize", "zoom", "fullscreen",
    // "front", "attach_detach", "copy"
    virtual void windowAction(const std::string &what) = 0;
    // asked when the option file is about to be written; the empty Layout says
    // nothing
    virtual Layout windowLayout() { return Layout(); }
    // redrawing the scene afterwards is the caller's
    virtual void applyColorScheme(bool dark) {}

    // --- what the options that shape the main window push into it; -1 leaves a dimension as it is
    virtual void setSceneSize(int width, int height) {}
    virtual void setConsoleFontSize(int size) {}
    virtual void setTreeWidth(int width) {}
    virtual void detachTree(bool detached) {}
    virtual void enableTooltips(bool on) {}

    // --- what the backend may call back; anything else belongs in a std::function inside a description

    struct Host {
      // closed with the button of its frame
      std::function<void(const Form &form)> formWasClosed;
      std::function<void()> consoleWasClosed;
      std::function<void(const std::vector<std::string> &paths)> filesDropped;
      std::function<void(const std::string &text)> error;
      std::function<void()> quitting;
      // said as the interface is about to forget it; only the fields about to
      // be lost are filled
      std::function<void(const Layout &layout)> layoutChanged;
      // one turn of the loop: a scene in a window of its own is drawn here
      std::function<void()> tick;
      // --- for an interface that shows pictures of the scene rather than
      // the scene (showsScene()): what it is handed, and what it hands back
      // nothing comes back when the scene has not changed, unless always
      std::function<std::string(int &width, int &height, bool always)>
        sceneImage;
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

  // every interface compiled in offers itself at start-up under a name --
  // "fltk", "imgui", "browser" -- with a way of making one
  void offer(const char *name, Backend *(*make)());
  const std::vector<std::string> &offered();
  // an empty name means the first there is; a name never offered makes
  // nothing
  Backend *make(const std::string &name);
  // as it was offered rather than as it calls itself
  const std::string &chosen();
} // namespace Ui

#endif
