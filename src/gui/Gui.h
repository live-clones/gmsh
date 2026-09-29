// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_H
#define GMSH_GUI_H

#include <functional>
#include <set>
#include <string>
#include <vector>
#include "GmshConfig.h"
#include "Form.h"
#include "Backend.h"
#include "GuiDialog.h"
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

class drawContext;
class GEdge;

// The interface as the rest of Gmsh sees it: one object, holding the dialogs
// and driving whichever Ui::Backend was linked. The 3D scene speaks Gmsh
// through and through and is written once per interface: see GuiScene.h.

class Gui {
public:
  static Gui &instance();

  // the level of a message, which colours it: the textual prefix is already
  // part of the message
  enum MessageLevel {
    MessageDirect = 0,
    MessageInfo,
    MessageWarning,
    MessageError,
    MessageDebug
  };

  enum StatusColor { StatusColorDefault = 0, StatusColorWarning, StatusColorError };

  // --- life cycle

  bool available();
  // quitShouldExit: whether quitting exits the process or only closes the
  // windows
  void create(int argc = 0, char **argv = nullptr, bool quitShouldExit = true,
              void (*errorHandler)(const char *fmt, ...) = nullptr);
  void destroy();
  // optionFileName is merged before the loop and saved after it
  int run(const std::string &optionFileName = "");
  std::string toolkitVersion();

  // --- event pumping (called from the mesher, through Msg::)

  // rateLimited: only if no check was made in the last 1 /
  // General.GuiRefreshRate seconds
  void check(bool rateLimited = false);
  bool ready();
  void wait(bool force = false);
  void wait(double time, bool force = false);
  void lock();
  void unlock();
  int locked();
  void awake(const std::string &action);

  // --- messages, status bar and modal dialogs

  void addMessage(const std::string &msg, int level = MessageDirect);
  void messageLines(std::vector<std::string> &lines);
  void copyText(const std::string &text);
  // graphics: in the graphic window rather than the status bar
  void setStatus(const std::string &msg, bool graphics = false);
  // the last message again, in the given colour
  void setLastStatus(int color = StatusColorDefault);

  void setProgress(const std::string &msg, double val, double min, double max);
  void setGraphicTitle(const std::string &title);
  void beep();
  // false when cancelled; hint is a line under the question, readOnly shows the
  // value
  bool inputDialog(const std::string &question, std::string &value,
                   const std::string &hint = "", bool readOnly = false);
  // the index of the answer chosen; two may be empty
  int questionDialog(const std::string &question, const std::string &zero,
                     const std::string &one, const std::string &two);

  // --- refreshing the GUI when the model changes

  void updateViews(bool numberOfViewsHasChanged, bool deleteWidgets = false);
  void updateFields();
  void rebuildTree(bool deleteWidgets);
  void resetVisibility();
  void applyColorScheme(bool redraw = false);
  void storeCurrentWindowsInfo();
  void fillRecentHistoryMenu();
  void watchFile();

  // --- panels and windows the menus drive

  enum Panel {
    PanelOptions = 0,
    PanelPlugins,
    PanelVisibility,
    PanelMessageConsole,
    PanelKeyboardAndMouse,
    PanelCurrentOptions,
    PanelAbout,
    // opened by the modules tree, not the menus
    PanelFields,
    PanelClassify
  };
  bool panelVisible(int panel);
  void showPanel(int panel, bool show);

  // -1 leaves a dimension as it is
  void setSceneSize(int width, int height);
  void setConsoleFontSize(int size);
  void setTreeWidth(int width);
  void detachTree(bool detached);
  void enableTooltips(bool on);
  void refreshBar();

  // "new", "split_h", "split_v", "split_u", "minimize", "zoom", "fullscreen",
  // "front", "attach_detach" or "copy"
  void windowAction(const std::string &what);
  // so that the menus leave out what would do nothing
  bool supportsWindowAction(const std::string &what);

  // "new", "open", "merge", "rename", "export", "watch", "remote_start",
  // "remote_merge", "remote_clear" or "remote_stop"
  void fileAction(const std::string &what);

  // --- modules, tree and context windows

  void openModule(const std::string &name);
  void toggleModule(const std::string &name);
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
  void showContextWindow(int dim, int tag);
  // --- the dialogs, each a GuiDialog described once in the file of its name; a description exists whether or not an interface does

  GuiElementary elementary;
  GuiPhysical physical;
  GuiTransform transform;
  GuiMeshContext mesh;
  GuiPartition partition;
  GuiHighOrder highOrder;
  GuiManipulator manipulator;
  GuiStatistics statistics;
  GuiClipping clipping;
  GuiGamepad gamepad;
  GuiOptions options;
  GuiVisibility visibility;
  GuiPlugins plugins;
  GuiFields fields;
  GuiClassify classify;
  GuiShortcuts shortcuts;
  GuiCurrentOptions currentOptions;
  GuiAbout about;
  GuiOnelabContext onelabContext;
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
  // the name as the option system writes it: "View[2].Visible"
  static std::string optionName(const std::string &category,
                                const std::string &name, int index);
  void optionChanged(const std::string &category, const std::string &name,
                     int index);
  void rebuildForm(const Ui::Form &form);
  void dropForm(const Ui::Form &form);
  // "check", "check_always", "reload", "reset", "refresh", "compute" or "stop"
  void onelabAction(const std::string &action);
  bool solverBusy();
  // "" hides a button; ("check", "compute") when idle, ("", "stop") while
  // running
  void setSolverButtonMode(const std::string &button0,
                           const std::string &button1);
  void solverButtons(std::string &button0, std::string &button1);
  // as "Gmsh Parsed" and "*.pos"
  struct FileFormat {
    std::string name, pattern;
    // -1 lets the name of the file decide
    int format;
    FileFormat(const std::string &n = "", const std::string &p = "")
      : name(n), pattern(p), format(-1)
    {
    }
  };
  enum { Open = 0, Create, OpenSeveral };
  std::vector<FileFormat> inputFormats();
  std::vector<FileFormat> outputFormats();
  // the second form names the formats and says which was used, -1 when the
  // chooser cannot say
  bool fileDialog(int mode, const std::string &title, const std::string &filter,
                  std::string &fileName);
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::string &fileName, int &chosenFormat);
  bool fileDialog(int mode, const std::string &title,
                  const std::vector<FileFormat> &formats,
                  std::vector<std::string> &names, int &chosenFormat);
  // a few formats write themselves, and say so with ExportDone; entry names the
  // line of the chooser picked (see GuiExport.h)
  enum { ExportCancelled = 0, ExportGoAhead, ExportDone };
  int exportOptionsDialog(int format, const std::string &fileName,
                          const std::string &entry = "");
  void exportView(int index);
  void startSolver(int index);
  bool quitShouldExit();

  // --- small editors
  void configureGamepad();

  // --- miscellaneous

  void setFinishedProcessingCommandLine();
  bool getFinishedProcessingCommandLine();
  void setOpenedThroughMacFinder(const std::string &name);
  std::string getOpenedThroughMacFinder();

  // --- the 3D scene

  static void offerScene(const char *name, const GuiSceneOps &ops);
  static void useScene(const std::string &name);

  // for a scene in a window of its own, pumped from the loop of the interface
  void pumpScene(bool rateLimited);

  // --- a picture of the scene, for an interface that cannot draw one; those that draw it themselves answer with nothing

  // a picking runs a loop of its own: whatever shows the panels has to keep
  // answering
  void pumpChrome(bool rateLimited);

  void sceneShownElsewhere();
  // empty when it has not changed since the last one, unless always
  std::string scenePicture(int &width, int &height, bool always = false);
  bool sceneMoved();
  void sceneResize(int width, int height);
  // what: 0 moved, 1 pressed, 2 released, 3 wheel, 4 left the picture;
  // button: 0 left, 1 right, 2 middle
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt);
  // 'q' gives up, 'e' ends, 'u' undoes, 'i' inverts; whether a picking was
  // there to take it
  bool sceneKey(char key);

  // two lines over the scene; an empty one goes away
  void sceneMessage(const std::string &first, const std::string &second);

  // --- the graphic windows

  drawContext *getCurrentDrawContext();
  // in pixels, high resolution factor included
  void getCurrentPixelSize(int &width, int &height);
  void setCurrentOpenglWindow(int which);
  void showAllInEveryWindow();
  void splitCurrentOpenglWindow(char how, double ratio = 0.5);
  void copyCurrentOpenglWindowToClipboard();
  // all the graphic windows composited when General.PrintCompositeWindows; the
  // caller owns the buffer, null if it could not be made
  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type);
  // the scene in the bottom-left corner of the frame buffer, where
  // glReadPixels() and gl2ps read; width and height are what could be had
  void beginGraphicCapture(int &width, int &height, bool composite = false);
  void endGraphicCapture();

  // --- what the views are showing

  // "x", "y", "z", "r" (a quarter turn) or "1:1"; reverse is Shift, sync
  // (Control) makes the other views follow the first
  void orientViews(const std::string &what, bool reverse, bool sync);
  void setMouseSelection(bool on);
  void toggleAnimation();
  bool animating();

  // --- interactive selection

  // returns 'q' (abort), 'l' (selected), 'r' (deselected), 'u' (undone) or 'e'
  // (ended)
  char selectEntity(int type);
  // without waiting for a click; the results are in the selected*() lists
  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h);
  // false if the interface cannot
  bool printView(int width, int height, int supersampling,
                 unsigned int format, unsigned int type, void *pixels);
  void abortSelection();
  // "background_image", "buffering" (double buffering and antialiasing) or
  // "font_engine"; the scene reads the option itself
  void sceneSettingChanged(const std::string &what);
  // the pointer drives the coordinates of the entity being placed instead of
  // highlighting
  void setAddPointMode(bool on);
  const std::vector<GVertex *> &selectedVertices();
  const std::vector<GEdge *> &selectedEdges();
  const std::vector<GFace *> &selectedFaces();
  const std::vector<GRegion *> &selectedRegions();
  const std::vector<MElement *> &selectedElements();
  const std::vector<SPoint2> &selectedPoints();
  const std::vector<PView *> &selectedViews();

private:
  Gui() {}
  // the dialogs must not reach a backend that is gone
  ~Gui() { _backend = nullptr; }
  Gui(const Gui &) = delete;
  Gui &operator=(const Gui &) = delete;

  Ui::Backend *_backend = nullptr;
  std::set<std::string> _changedOptions;

  // destroy() is reached from inside the backend's own loop, which has to
  // unwind through the object first
  Ui::Backend *_retired = nullptr;
  bool _quitShouldExit = true;
  bool _finishedProcessingCommandLine = false;
  std::string _openedThroughMacFinder;
  std::string _solverButton0, _solverButton1 = "compute";
  GuiDialog *_panelDialog(int panel);
  void _takeLayout(const Ui::Backend::Layout &l);
};

#endif
