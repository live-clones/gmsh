// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GUI_ACTIONS_H
#define GUI_ACTIONS_H

#include <functional>
#include <string>
#include <vector>

// an ONELAB client, without onelab.h
typedef void *onelabClientHandle;

class GEdge;
class drawContext;

// What the menus and buttons of an interface run, whatever the toolkit.
// Whatever they ask of the interface goes through Gui.h.

// --- project

void projectClear();
void projectReload();
void projectDelete();
// General.RecentFile<index>
void projectOpenRecent(int index);
void projectQuit();
// next to the project file, or into the per-user option file
void optionsSave(bool toProjectFile);

// --- the File menu (GuiFiles.cpp)

void fileOpen(bool merge);
void fileOpenRecent(int index);
void fileNew();
void fileRename();
void fileExport();
// see remoteAction()
void fileRemote(const std::string &what);

void messagesSave(const std::string &fileName);
void messagesSaveAs();

void optionsRestoreDefaults();
// the buttons of the option window: picking the rotation centre, fitting the
// axes, stepping a view
void optionsAction(const std::string &what);

// shown, the others hidden
void modelSetCurrent(int index);

// Query and measure wait for clicks, until they are asked again or 'q' is
// pressed: every click says what the model holds where it hit (the entity,
// the mesh element and the node there, and the value of every visible view),
// or two clicks the distance between the points they hit. Blocking loops,
// started from a deferred action; starting one stops the other.
void queryModel();
bool queryMode();
void measureModel();
bool measureMode();

// see Menu::quickAccess()
void quickAccessAction(const std::string &what);
bool quickAccessChecked(const std::string &what);

// --- solver / ONELAB

// "check", "check_always", "compute", "reset", "reload", "refresh", "stop",
// "kill", "save", "load" or "initialize"
void onelabRun(const std::string &action);
// a missing executable is looked for next to the Gmsh binary, then asked for
void solverAdd(const std::string &name, const std::string &executable,
               const std::string &remoteLogin, int index);
// a negative index refreshes the list
void solverStart(int index);
// close the gaps adding or removing a solver leaves in the Solver.* options
void solverListCompact();
void solverChooseExecutable(onelabClientHandle client);

// the ONELAB client "GmshRemote": "start" (arg: the command line), "merge"
// (arg: a file), "clear", "stop"
void remoteAction(const std::string &what, const std::string &arg = "");

// "rename", "executable" or "remove"; see Menu::solverActions()
void solverAction(const std::string &what, int index);

// see Menu::solverOptions(); the switches answer through solverOptionSet()
void solverOptionAction(const std::string &what);
bool solverOptionSet(const std::string &what);

bool solverIsRunning();
bool solverStopRequested();
void solverRequestStop(bool stop);
void solverCheckForErrors(const std::string &client);

// whether there are "ONELAB Context" parameters: a double click on an entity
// then opens the window editing the parameters linked to it
bool onelabHasContext();

// from the templates "ONELAB Context/<Dim> Template/...", with the template
// string replaced by the name of the entity; the names made are appended
void onelabContextInstantiate(int dim, int tag, bool physical, int physicalTag,
                              std::vector<std::string> &names);

// --- geometry

void geometryReload();
// appends a SetFactory() to the script
void geometrySetFactory(const std::string &factory);
void geometryEditInTextEditor();
void geometryRemoveLastCommand();
void geometryCoherence();

// --- mesh

void meshDimension(int dim);
void meshRefine();
// "" (the default optimizer), "Netgen", "Laplace2D", "UntangleMeshGeometry",
// "QuadQuasiStructured", ...
void meshOptimize(const std::string &how);
void meshSetOrder(int order);
void meshRecombine();
void meshComputeCrossField();
void meshUnpartition();
void meshConvertOldPartitioning();
// asks before overwriting
void meshSave();

// what the running action has picked so far, for the dialog to show and
// correct; kind is ENT_POINT, ENT_CURVE or ENT_SURFACE
struct pickedEntities {
  int kind;
  // "Point", "Curve loop", ...
  std::string what;
  // the loops of a surface are written to the script as they are closed: not
  // editable
  bool editable;
  std::vector<int> tags;
  // the curves of a loop; empty when the entries stand for themselves
  std::vector<std::vector<int> > members;
  std::string memberWhat;
  pickedEntities() : kind(0), editable(false) {}
};
pickedEntities &geometryPicked();

// the tool of one pane, then whichever pane is picked next: each tool is a
// loop of its own, and geometryElementaryRestart() ends it from inside
void geometryElementary(int pane);
void geometryElementaryRestart(int pane);
void geometryUnpick(int index);


// what is "elements", "curves", "surfaces" or "volumes", action "delete" or
// "reverse"; a blocking loop, started from a deferred action
void meshModifyParts(const std::string &what, const std::string &action);

// along the edges sharper than angleInDegrees, cut further so that each
// surface can be parametrized when ensureParametrizable; the edges found go
// into a temporary discrete curve, *selected, which may hold edges picked by
// hand already, and is null on return
void meshClassifySurfaces(double angleInDegrees, bool ensureParametrizable,
                          GEdge **selected = nullptr);

// --- interactive geometry and mesh definition: what is picked in the 3D
// view is written into the .geo script through scriptStringInterface.h.
// Blocking loops until 'q', started from a deferred action in an
// immediate-mode interface; their parameters are read at each 'e', as the
// panel they come from stays usable meanwhile

enum {
  GEO_ACTION_TRANSLATE = 0,
  GEO_ACTION_ROTATE,
  GEO_ACTION_SCALE,
  GEO_ACTION_SYMMETRY,
  GEO_ACTION_EXTRUDE_TRANSLATE,
  GEO_ACTION_EXTRUDE_ROTATE,
  GEO_ACTION_DELETE,
  GEO_ACTION_PHYSICAL_ADD,
  GEO_ACTION_MESH_SIZE,
  GEO_ACTION_RECOMBINE,
  GEO_ACTION_COMPOUND,
  GEO_ACTION_PHYSICAL_REMOVE,
  GEO_ACTION_PIPE
};

// what restricts the selection to "Point", "Curve", "Surface" or "Volume";
// empty, GuiTransform::selection says
void geometryActOnSelection(int action, const std::string &what);

// an expression in the symbols of the .geo file, or a number; false when
// neither
bool geometryEvaluate(const std::string &str, double &val);

// the "Add" button
void geometryAddElementary(int shape, const std::vector<std::string> &fields);

// the pointer drives the first three fields of the pane, Shift holds them, 'e'
// writes, 'q' leaves
void geometryAddPointBasedEntity(int pane);

// the preview of the shape the elementary dialog shows
void geometrySetTransientShape(bool on);

// unprojected into the plane through the centre of gravity, snapped to
// Geometry.Snap; frozen coordinates are left
void geometryPointUnderCursor(drawContext *ctx, int winX, int winY,
                              const bool frozen[3], double point[3]);

// "Line" (two points), "Spline", "Bezier" or "BSpline"
void geometryAddCurve(const std::string &type);
void geometryAddCircleArc();
void geometryAddEllipseArc();
// mode 0 plane surface, 1 filled surface, 2 volume; the first contour is the
// outer boundary
void geometryAddSurfaceVolume(int mode);
// "BooleanIntersection", "BooleanUnion", "BooleanDifference" or
// "BooleanFragments", the only one accepting an empty tool
void geometryBoolean(const std::string &op);
void geometryFillet();
void geometrySplitCurve();

// what is "Point", "Curve" or "Surface"
void meshDefineEmbedded(const std::string &what);
// in 2D and 3D the corners are picked after the entity; none lets Gmsh find
// them
void meshDefineTransfinite(int dim);

// --- 3D view

// the option, then the interface, which has pointers to put back
void pickWithMouse(bool on);

// "x", "y", "z", "r" (a quarter turn), "1:1" (no translation nor zoom) or
// "reset"; reverse is the opposite direction, or for "1:1" the bounding box
// of what is visible
void viewSetOrientation(drawContext *ctx, const std::string &what,
                        bool reverse);

// several time steps in a view, or cycling turned on
bool viewIsAnimatable();

// --- post-processing

// see Menu::viewActions()
void viewAction(const std::string &what, int index);

// --- post-processing animation

// by incr steps: through the time steps if time is set, through the views
// otherwise
void animationStep(int time, int incr, bool redraw = true);
// as the status bar and the arrow keys ask for it
void animationStepBy(bool forward, bool views = false);
// if it is time to
void animationTick();
void animationRewind();

// --- miscellaneous

void visibility_save(const std::string &fileName);

// "*" is every one; what: 0 nodes, 1 elements, 2-5 points to volumes, 6-9 their
// physical groups
void visibilityByNumber(int what, const std::string &value, bool show);
// "points to hide", "physical surfaces to show", "show all", ...
void visibilityInteractive(const std::string &what);
void watchFiles();
void openURL(const std::string &url);
void helpOnline();

#endif
