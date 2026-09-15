// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_H
#define GMSH_GUI_H

#include <functional>
#include <string>
#include <vector>
#include "GmshConfig.h"
#include "Form.h"
#include "Backend.h"
#include "GuiDialog.h"
#include "GuiActions.h"
#include "GuiScene.h"
#include "GuiElementary.h"
#include "GuiPhysical.h"
#include "GuiTransform.h"
#include "GuiMeshContext.h"
#include "GuiPartition.h"
#include "GuiHighOrder.h"
#include "GuiManipulator.h"
#include "GuiStatistics.h"
#include "GuiClipping.h"
#include "GuiGamepad.h"
#include "GuiOptions.h"
#include "GuiVisibility.h"
#include "GuiPlugins.h"
#include "GuiFields.h"
#include "GuiClassify.h"
#include "GuiHelp.h"
#include "GuiOnelab.h"
#include "GuiPrompts.h"
#include "GuiExport.h"

// The graphical user interface, as the rest of Gmsh sees it: one object,
// holding the dialogs and driving whichever Ui::Backend was linked. Nothing
// outside of the interface directories talks to a widget toolkit.
//
// The 3D scene is the exception: it speaks Gmsh through and through, and is
// written once per interface; see GuiScene.h.

class Gui {
public:
  static Gui &instance();

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
  // what the message console holds, in the order it holds it
  void messageLines(std::vector<std::string> &lines);
  // put text on the clipboard
  void copyText(const std::string &text);
  // display a status message ("graphics" prints it in the graphic window
  // instead of the status bar)
  void setStatus(const std::string &msg, bool graphics = false);
  // redisplay the last status message, with the given status bar color
  void setLastStatus(int color = StatusColorDefault);

  // show a transient tooltip next to the pointer, over the current 3D view;
  // an empty text hides it
  void drawTooltip(const std::string &text);
  // display a status message and update the progress bar
  void setProgress(const std::string &msg, double val, double min, double max);
  // set the title of the graphic windows
  void setGraphicTitle(const std::string &title);
  // emit an audible bell
  void beep();
  // ask the user for a string, false if it was cancelled; `hint` is a line
  // under the question saying what shape the answer takes, `readOnly` shows
  // the value instead of asking for it
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

  // the panels the menus show and hide
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

  // the options that shape the main window, pushed into it when one is set
  // from a script or the option window; -1 leaves a dimension as it is
  void setSceneSize(int width, int height);
  void setConsoleFontSize(int size);
  void setTreeWidth(int width);
  void detachTree(bool detached);
  void enableTooltips(bool on);
  // the bar along the bottom is to be drawn again
  void refreshBar();

  // act on the windows of the interface: what is "new", "split_h",
  // "split_v", "split_u", "minimize", "zoom", "fullscreen", "front",
  // "attach_detach" or "copy"
  void windowAction(const std::string &what);
  // whether the running interface has anything to do for that action, so
  // that the menus can leave out what would do nothing
  bool supportsWindowAction(const std::string &what);

  // run one of the menu entries that need a file chooser: what is "new",
  // "open", "merge", "rename", "export", "watch", or "remote_start",
  // "remote_merge", "remote_clear", "remote_stop"
  void fileAction(const std::string &what);

  // --- modules, tree and context windows

  void openModule(const std::string &name);
  // fold it if it is unfolded, unfold it otherwise: what its key does
  void toggleModule(const std::string &name);
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
  // show the onelab context window for the given entity
  void showContextWindow(int dim, int tag);
  // --- the dialogs
  //
  // Each is a GuiDialog, described once in the file of its name and drawn
  // by whichever interface is up. A description exists whether or not an
  // interface does.

  // the four context dialogs of the geometry module
  GuiElementary elementary;
  GuiPhysical physical;
  GuiTransform transform;
  GuiMeshContext mesh;
  // the mesh partitioner, which is all options
  GuiPartition partition;
  // the high order tools, two sections one under the other
  GuiHighOrder highOrder;
  // the rotation, translation and scale of the view
  GuiManipulator manipulator;
  GuiStatistics statistics;
  // the six planes that cut what is drawn
  GuiClipping clipping;
  // what the gamepad is doing and what each of its buttons and axes is for
  GuiGamepad gamepad;
  // every option there is, a tab per category and one per view
  GuiOptions options;
  // what of the model is drawn: by number, by picking, per graphic window
  GuiVisibility visibility;
  // the plugins, what each of them takes, and what it is run on
  GuiPlugins plugins;
  // the mesh size fields, what each takes, and which is the background
  GuiFields fields;
  // turning a triangulation into a model
  GuiClassify classify;
  // what the keyboard and the mouse do, and what the command line takes
  GuiShortcuts shortcuts;
  // what every option is worth right now, and what one may change it to
  GuiCurrentOptions currentOptions;
  // what this Gmsh is
  GuiAbout about;
  // the parameters a solver attached to one entity
  GuiOnelabContext onelabContext;
  // one option asked for on its own, the arrow shape, a command with its
  // history, and what an output format asks before the file is written
  GuiOptionValue optionValue;
  GuiArrow arrow;
  GuiHistory history;
  GuiExport exportOptions;

  // --- what a GuiDialog asks of the interface

  void showForm(const Ui::Form &form, bool show = true);
  bool formVisible(const Ui::Form &form);
  std::string formPane(const Ui::Form &form);
  void setFormPane(const Ui::Form &form, const std::string &pane);
  void reloadForm(const Ui::Form &form);
  void rebuildForm(const Ui::Form &form);
  void dropForm(const Ui::Form &form);
  // run one of the actions of the onelab tree: "check", "check_always",
  // "reload", "reset", "refresh", "compute" or "stop"
  void onelabAction(const std::string &action);
  // is a solver currently running?
  bool solverBusy();
  // set the labels of the two solver buttons ("" hides one); the usual pairs
  // are ("check", "compute") when idle and ("", "stop") while running
  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1);
  // and what they say
  void solverButtons(std::string &button0, std::string &button1);
  // one of the formats the chooser offers: what it is called and what it
  // matches, as "Gmsh Parsed" and "*.pos"
  struct FileFormat {
    std::string name, pattern;
    // what it is written as, for the formats that are offered for writing;
    // -1 for the one that lets the name of the file decide
    int format;
    FileFormat(const std::string &n = "", const std::string &p = "")
      : name(n), pattern(p), format(-1)
    {
    }
  };
  // how the chooser is opened
  enum { Open = 0, Create, OpenSeveral };
  // what may be opened, by name
  std::vector<FileFormat> inputFormats();
  // and what it may be written as
  std::vector<FileFormat> outputFormats();
  // show the file chooser and wait; the second form names the formats and
  // says which was used, or -1 when the chooser cannot say
  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName);
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::string &fileName, int &chosenFormat);
  // and the same asking for several at once
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::vector<std::string> &names, int &chosenFormat);
  // What asking for the options of an output format came to. Three answers:
  // a few of the formats make a choice that is the writing -- which views,
  // in which flavour -- so they write and say so. `entry` names the line of
  // the chooser that was picked, for the pairs of lines that share a format
  // and not a question (see GuiExport.h).
  enum { ExportCancelled = 0, ExportGoAhead, ExportDone };
  int exportOptionsDialog(int format, const std::string &fileName,
                          const std::string &entry = "");
  // write one post-processing view to a file the user picks, in the format
  // read off the chooser
  void exportView(int index);
  // start the solver with the given index (-1 for none)
  void startSolver(int index);
  // should quitting the application exit the process, or only close the
  // windows? (the API sets the latter)
  bool quitShouldExit();

  // --- small editors
  void configureGamepad();

  // --- miscellaneous

  void setFinishedProcessingCommandLine();
  bool getFinishedProcessingCommandLine();
  void setOpenedThroughMacFinder(const std::string &name);
  std::string getOpenedThroughMacFinder();

  // --- the 3D scene

  static void offerScene(const char *interface, const GuiSceneOps &ops);
  // and this is which one runs, said once as the interface comes up
  static void useScene(const std::string &interface);

  // bring the scene up if it is not already, and give it a chance to draw
  // and to answer the pointer; for a scene in a window of its own, pumped
  // from whatever loop the interface is running
  void pumpScene(bool rateLimited);

  // --- a picture of the scene, for an interface that cannot draw one
  //
  // The scene is drawn here and the picture is sent, and what the pointer
  // did over that picture comes back. The interfaces that draw the scene
  // themselves answer with nothing.

  // give the interface a turn: a picking runs a loop of its own, and
  // whatever is showing the panels has to keep answering, or there is no
  // way left to give up
  void pumpChrome(bool rateLimited);

  // the interface draws the scene itself, from the pictures below: there
  // is to be no window of its own
  void sceneShownElsewhere();
  // the scene as a picture, and the size it was drawn at; empty when there
  // is none to send, or when it has not changed since the last one unless
  // `always` says to draw it anyway
  std::string scenePicture(int &width, int &height, bool always = false);
  // and the same question without the picture
  bool sceneMoved();
  // how big the picture is wanted
  void sceneResize(int width, int height);
  // What the pointer did over it. `what` is 0 moved, 1 pressed, 2 released,
  // 3 turned the wheel; `button` is 0 left, 1 right, 2 middle.
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt);
  // the keys a picking answers to: 'q' gives up, 'e' ends, 'u' undoes,
  // 'i' inverts; whether a picking was there to take it
  bool sceneKey(char key);

  // two lines said over the scene rather than in the bar: what to do, and
  // which keys end or abort it; a line that is empty is a line that goes
  // away
  void sceneMessage(const std::string &first, const std::string &second);

  // --- the graphic windows

  // draw context of the last graphic window that received an event
  drawContext *getCurrentDrawContext();
  // size in pixels (i.e. taking the high resolution factor into account) of the
  // last graphic window that received an event
  void getCurrentPixelSize(int &width, int &height);
  // override which graphic window should be considered as current, by giving an
  // absolute index amongst all the existing graphic windows
  void setCurrentOpenglWindow(int which);
  // show every model and every view in every graphic window, undoing what the
  // visibility panel hid in one of them
  void showAllInEveryWindow();
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
  // actually be used.
  void beginGraphicCapture(int &width, int &height, bool composite = false);
  void endGraphicCapture();

  // --- what the views are showing

  // Orient the views the status bar acts upon: "x", "y" or "z" to point that
  // axis out of the screen, "r" for a quarter turn, "1:1" to drop the
  // translation and the zoom. `reverse` is what Shift asks for and `sync` what
  // Control asks for: the other views follow the first instead of being
  // oriented themselves.
  void orientViews(const std::string &what, bool reverse, bool sync);
  // turn picking with the mouse on or off
  void setMouseSelection(bool on);
  // Play or pause the animation of the post-processing views, and say whether
  // it is running.
  void toggleAnimation();
  bool animating();

  // --- interactive selection

  // select entities of the given type (ENT_POINT, ENT_CURVE, ...) in the most
  // recent graphic window; returns 'q' (abort), 'l' (selected), 'r'
  // (deselected), 'u' (undone) or 'e' (ended)
  char selectEntity(int type);
  // stop the interactive selection that is running, as if the user had pressed
  // 'q'
  void abortSelection();
  // An option the scene draws from was set, from a script or the option
  // window, and the scene has to take it in: "background_image" for the
  // picture behind the model, "buffering" for double buffering and
  // antialiasing, "font_engine" for what draws the text of the scene. The
  // scene reads the option itself; this only says which.
  void sceneSettingChanged(const std::string &what);
  // Turn the "add point mode" of the 3D views on or off: while it is on, the
  // pointer drives the coordinates of the entity being placed instead of
  // highlighting what it hovers.
  void setAddPointMode(bool on);
  // results of the last selectEntity() call
  const std::vector<GVertex *> &selectedVertices();
  const std::vector<GEdge *> &selectedEdges();
  const std::vector<GFace *> &selectedFaces();
  const std::vector<GRegion *> &selectedRegions();
  const std::vector<MElement *> &selectedElements();
  const std::vector<SPoint2> &selectedPoints();
  const std::vector<PView *> &selectedViews();

private:
  Gui() {}
  // at the end of the process, once the interface is gone: the dialogs go
  // with this object and must not reach a backend that is no longer there
  ~Gui() { _backend = nullptr; }
  Gui(const Gui &) = delete;
  Gui &operator=(const Gui &) = delete;

  Ui::Backend *_backend = nullptr;
  // the one that was taken down, kept until the next is made: destroy() is
  // reached from inside the backend's own loop, which has to unwind through
  // the object before it may go
  Ui::Backend *_retired = nullptr;
  bool _quitShouldExit = true;
  bool _finishedProcessingCommandLine = false;
  std::string _openedThroughMacFinder;
  std::string _solverButton0, _solverButton1 = "compute";
  GuiDialog *_panelDialog(int panel);
  void _takeLayout(const Ui::Backend::Layout &l);
};

#endif
