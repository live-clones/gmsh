// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_H
#define GMSH_GUI_H

#include <string>
#include <vector>
#include "GmshConfig.h"
#include "SPoint2.h"
#include "GuiActions.h"

// Toolkit-independent interface to the graphical user interface. Everything
// outside of the GUI directories (src/fltk, src/imgui) should go through this
// namespace instead of talking to a specific widget toolkit: exactly one
// implementation is compiled in a given build, either src/fltk/GuiFltk.cpp when
// HAVE_FLTK is defined, or src/imgui/Gui.cpp when HAVE_IMGUI is defined. When
// neither is defined, HAVE_GUI is undefined and none of this is available.

class drawContext;
class PixelBuffer;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

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
  // save the contents of the message console
  void saveMessages(const std::string &fileName);
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
  // ask the user for a string; returns false if the dialog was cancelled
  bool inputDialog(const std::string &question, std::string &value);
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
  // stop the interactive selection that is running, as if the user had pressed
  // 'q'
  void abortSelection();
  // Turn the "add point mode" of the 3D views on or off: while it is on, the
  // pointer drives the coordinates of the entity being placed instead of
  // highlighting what it hovers.
  void setAddPointMode(bool on);
  // run one of the actions of the onelab tree: "check", "check_always",
  // "reload", "reset", "refresh", "compute" or "stop"
  void onelabAction(const std::string &action);
  // is a solver currently running?
  bool solverBusy();
  // set the labels of the two solver buttons ("" hides one); the usual pairs
  // are ("check", "compute") when idle and ("", "stop") while running
  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1);
  // show the file chooser and wait for the user: mode is 0 to open an existing
  // file and 1 to save one, filter is a space separated list of extensions
  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName);
  // start the solver with the given index (-1 for none)
  void startSolver(int index);
  // should quitting the application exit the process, or only close the
  // windows? (the API sets the latter)
  bool quitShouldExit();

  // --- graphic windows

  // draw context of the last graphic window that received an event
  drawContext *getCurrentDrawContext();
  // size in pixels (i.e. taking the high resolution factor into account) of the
  // last graphic window that received an event
  void getCurrentPixelSize(int &width, int &height);
  // override which graphic window should be considered as current, by giving an
  // absolute index amongst all the existing graphic windows
  void setCurrentOpenglWindow(int which);
  // split the current graphic window ('h', 'v' or 'u')
  void splitCurrentOpenglWindow(char how, double ratio = 0.5);
  // copy the current graphic window to the clipboard
  void copyCurrentOpenglWindowToClipboard();
  // create a pixel buffer with the contents of the current graphic window, or
  // of all the graphic windows composited together when
  // General.PrintCompositeWindows is set; the caller owns the returned buffer,
  // which is null if it could not be created
  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type);
  // Make the scene occupy the bottom-left corner of the frame buffer at the
  // given size, which is where glReadPixels() reads and where gl2ps expects the
  // viewport to be. width and height are updated with the size that could
  // actually be used. In the FLTK interface the graphic window is a window of
  // its own, so this does nothing; in the ImGui one the scene is only a part of
  // the frame buffer, so it has to be redrawn.
  void beginGraphicCapture(int &width, int &height, bool composite = false);
  void endGraphicCapture();

  // --- interactive selection

  // select entities of the given type (ENT_POINT, ENT_CURVE, ...) in the most
  // recent graphic window; returns 'q' (abort), 'l' (selected), 'r'
  // (deselected), 'u' (undone) or 'e' (ended)
  char selectEntity(int type);
  // results of the last selectEntity() call
  const std::vector<GVertex *> &selectedVertices();
  const std::vector<GEdge *> &selectedEdges();
  const std::vector<GFace *> &selectedFaces();
  const std::vector<GRegion *> &selectedRegions();
  const std::vector<MElement *> &selectedElements();
  const std::vector<SPoint2> &selectedPoints();
  const std::vector<PView *> &selectedViews();

  // --- small editors the interface owns

  // The three numbers that shape an arrow, edited in a window of the
  // interface's own: it draws the arrow it is describing, which no
  // description of fields could. Returns false when nothing was changed.
  bool editArrow(double &headRadius, double &stemLength, double &stemRadius);

  // --- miscellaneous

  void setFinishedProcessingCommandLine();
  bool getFinishedProcessingCommandLine();
  void setOpenedThroughMacFinder(const std::string &name);
  std::string getOpenedThroughMacFinder();

} // namespace Gui

#endif
