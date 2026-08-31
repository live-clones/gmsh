// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_H
#define GMSH_GUI_H

#include <string>
#include <vector>
#include "GmshConfig.h"
#include "GuiActions.h"
#include "GuiScene.h"

// Toolkit-independent interface to the graphical user interface. Everything
// outside of the GUI directories (src/fltk, src/imgui) goes through this
// namespace instead of talking to a specific widget toolkit.
//
// It is implemented once, in src/common/Gui.cpp, which drives whichever
// Ui::Backend of src/gui/Backend.h was linked. What is not implemented there
// is declared in GuiScene.h, included below: the 3D scene, which speaks Gmsh
// and is a chantier of its own, and the two calls that wait on a file chooser
// able to name its formats. Those are still written once per interface.

namespace Gui {

  // level of a message added to the message console; the GUI uses it to
  // colorize the message (the textual prefix, e.g. "Error   : ", is already
  // part of the message)
  enum MessageLevel {
    MessageDirect = 0,
    MessageInfo,
    MessageWarning,
    MessageError,
    MessageDebug
  };

  // color of the status bar, set by the message system
  enum StatusColor { StatusColorDefault = 0, StatusColorWarning, StatusColorError };

  // --- life cycle

  // is the GUI available, i.e. has it been created and not destroyed?
  bool available();
  // create the GUI if it does not exist yet; quitShouldExit says whether the
  // quit callback should exit the application or simply close all the windows,
  // and errorHandler is an optional handler for internal toolkit errors
  void create(int argc = 0, char **argv = nullptr, bool quitShouldExit = true,
              void (*errorHandler)(const char *fmt, ...) = nullptr);
  // close all the windows and destroy the GUI
  void destroy();
  // run the GUI event loop until there is no window left; optionFileName, if
  // given, is merged before entering the loop and saved when leaving it
  int run(const std::string &optionFileName = "");
  // name and version of the underlying widget toolkit, for "gmsh -info"
  std::string toolkitVersion();

  // --- event pumping (called from the mesher, through Msg::)

  // process the pending events, if any; if rateLimited is set, only do so when
  // no check has been made in the last 1 / General.GuiRefreshRate seconds
  void check(bool rateLimited = false);
  // are there events ready to be processed?
  bool ready();
  // wait (possibly indefinitely) for events, then process them
  void wait(bool force = false);
  // wait at most time seconds for events, then process them
  void wait(double time, bool force = false);
  // lock/unlock the GUI against child threads
  void lock();
  void unlock();
  int locked();
  // ask the main thread to run the given action in its event loop
  void awake(const std::string &action);

  // --- messages, status bar and modal dialogs

  // add a line to the message console
  void addMessage(const std::string &msg, int level = MessageDirect);
  // What the message console holds, in the order it holds it. Writing it to a
  // file is done once, in messagesSave(), rather than by each console.
  void messageLines(std::vector<std::string> &lines);
  // put text on the clipboard: the listing of the current options is read by
  // picking lines in it and taking a copy of them
  void copyText(const std::string &text);
  // display a status message ("graphics" prints it in the graphic window
  // instead of the status bar)
  void setStatus(const std::string &msg, bool graphics = false);
  // redisplay the last status message, with the given status bar color
  void setLastStatus(int color = StatusColorDefault);

  // Show a transient tooltip next to the pointer, over the current 3D view; an
  // empty text hides it. Used while picking, to put what was picked where the
  // user is already looking.
  void drawTooltip(const std::string &text);
  // display a status message and update the progress bar
  void setProgress(const std::string &msg, double val, double min, double max);
  // set the title of the graphic windows
  void setGraphicTitle(const std::string &title);
  // emit an audible bell
  void beep();
  // Ask the user for a string; false if it was cancelled. `hint` is a line
  // under the question saying what shape the answer takes -- the range of a
  // parameter says "[min : max : step]" that way -- and `readOnly` shows the
  // value instead of asking for it.
  bool inputDialog(const std::string &question, std::string &value,
                   const std::string &hint = "", bool readOnly = false);
  // ask the user a question with 2 or 3 possible answers (two may be empty);
  // returns the index of the chosen answer
  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two);

  // --- refreshing the GUI when the model changes

  // update the GUI when views get modified, added or deleted
  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets = false);
  // update the GUI when mesh size fields change
  void updateFields();
  // rebuild the onelab tree
  void rebuildTree(bool deleteWidgets);
  // reset the visibility window
  void resetVisibility();
  // apply the current color scheme to the widgets
  void applyColorScheme(bool redraw = false);
  // store the current window positions and sizes in CTX
  void storeCurrentWindowsInfo();
  // refill the "recent files" menu from CTX::recentFiles
  void fillRecentHistoryMenu();
  // rescan General.WatchFilePattern and merge the files that match it
  void watchFile();

  // --- panels and windows the menus drive

  // The panels the menus show and hide. They are windows in the FLTK interface
  // and dockable panels in the ImGui one, which is exactly the kind of
  // difference the menu description must not have to know about.
  enum Panel {
    PanelOptions = 0,
    PanelPlugins,
    PanelVisibility,
    PanelMessageConsole,
    PanelKeyboardAndMouse,
    PanelCurrentOptions,
    PanelAbout,
    // these have no menu entry: the modules tree opens them
    PanelFields,
    PanelClassify
  };
  bool panelVisible(int panel);
  void showPanel(int panel, bool show);

  // Act on the windows of the interface: what is "new", "split_h", "split_v",
  // "split_u", "minimize", "zoom", "fullscreen", "front", "attach_detach" or
  // "copy", the vocabulary of the FLTK window_cb().
  void windowAction(const std::string &what);
  // Whether the running interface has anything to do for that action, so that
  // the menus can leave out what would do nothing.
  bool supportsWindowAction(const std::string &what);

  // Run one of the menu entries that need a file chooser, which is toolkit
  // business: what is "new", "open", "merge", "rename", "export", "watch", or
  // "remote_start", "remote_merge", "remote_clear", "remote_stop".
  void fileAction(const std::string &what);

  // --- modules, tree and context windows

  void openModule(const std::string &name);
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
  // show the onelab context window for the given entity
  void showContextWindow(int dim, int tag);
  // Raise one of the context dialogs of GuiDialogs.h, which says which pane it
  // shows and holds the values it edits: the interface only has to show the
  // window. Dialog::show() is what the modules tree calls.
  void showDialog(int dialog, bool show = true);
  // is it up? the menu entries that raise a dialog are toggles, like the ones
  // that raise a panel
  bool dialogVisible(int dialog);
  // Push the values into the widgets of a dialog that is already up. The Dear
  // ImGui interface draws them afresh at every frame and has nothing to do;
  // the FLTK one holds them in widgets, so a view rotated with the mouse has
  // to be told to the manipulator.
  void refreshDialog(int dialog);
  // run one of the actions of the onelab tree: "check", "check_always",
  // "reload", "reset", "refresh", "compute" or "stop"
  void onelabAction(const std::string &action);
  // is a solver currently running?
  bool solverBusy();
  // set the labels of the two solver buttons ("" hides one); the usual pairs
  // are ("check", "compute") when idle and ("", "stop") while running
  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1);
  // and what they say, which the description of the tree reads
  void solverButtons(std::string &button0, std::string &button1);
  // One of the formats the chooser offers: what it is called and what it
  // matches, as "Gmsh Parsed" and "*.pos".
  struct FileFormat {
    std::string name, pattern;
    FileFormat(const std::string &n = "", const std::string &p = "")
      : name(n), pattern(p)
    {
    }
  };
  // how the chooser is opened
  enum { Open = 0, Create, OpenSeveral };
  // what may be opened, by name; declared here rather than beside the actions
  // because that header is read before this one
  std::vector<FileFormat> inputFormats();
  // Show the file chooser and wait: mode is one of those. The second form names the formats and says which was used,
  // or -1 when the chooser cannot say -- which is what tells an exported view
  // which flavour of ".pos" was meant.
  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName);
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::string &fileName, int &chosenFormat);
  // and the same asking for several at once, which is what opening files does
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::vector<std::string> &names, int &chosenFormat);
  // Ask for the options of that output format, in a window of the interface's
  // own; false if the user gave up. The FLTK interface offers them inside its
  // export chooser instead, and answers true.
  bool exportOptionsDialog(int format, const std::string &fileName);
  // Write one post-processing view to a file the user picks. Which format it
  // is written in is read off the chooser, which is why this is the
  // interface's: the FLTK one offers the formats as filters and asks which
  // was used, the Dear ImGui one goes by the extension.
  void exportView(int index);
  // start the solver with the given index (-1 for none)
  void startSolver(int index);
  // should quitting the application exit the process, or only close the
  // windows? (the API sets the latter)
  bool quitShouldExit();

  // --- small editors the interface owns
  // the window that says what each button of a gamepad does, which the
  // interface owns for the same reason
  void configureGamepad();

  // --- miscellaneous

  void setFinishedProcessingCommandLine();
  bool getFinishedProcessingCommandLine();
  void setOpenedThroughMacFinder(const std::string &name);
  std::string getOpenedThroughMacFinder();

} // namespace Gui

#endif
