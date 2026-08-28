// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GUI_ACTIONS_H
#define GUI_ACTIONS_H

#include <functional>
#include <string>
#include <vector>

// opaque handle to an ONELAB client, so that this header does not have to
// include onelab.h
typedef void *onelabClientHandle;

class GEdge;
class drawContext;

// Actions triggered by the graphical user interface that do not depend on the
// widget toolkit. They are shared by all the GUI implementations (src/fltk,
// src/imgui), so that the menus and buttons of a given frontend are only in
// charge of the presentation. Whatever interaction they need goes through the
// toolkit-independent interface of src/common/Gui.h, in particular
// Msg::GetAnswer() for the questions that must be confirmed by the user.

// --- project

// clear the project and reload the current file
void projectClear();
// reload the current file, keeping the solver state
void projectReload();
// delete the file of the current model, after confirmation
void projectDelete();
// open the file of index i in the General.RecentFile<i> options
void projectOpenRecent(int index);
// save the persistent information and leave
void projectQuit();
// write the current options either next to the project file (toProjectFile) or
// into the per-user option file
void optionsSave(bool toProjectFile);

// reset every option to its default value, after confirmation
void optionsRestoreDefaults();
// the buttons the option window holds, which do rather than set: picking the
// rotation centre, fitting the axes to what is visible, stepping a view
// through its time steps
void optionsAction(const std::string &what);

// --- solver / ONELAB

// Run one of the actions of the ONELAB tree: "check", "check_always",
// "compute", "reset", "reload", "refresh", "stop", "kill", "save", "load" or
// "initialize". This is the shared implementation of what the FLTK interface
// calls onelab_cb().
void onelabRun(const std::string &action);
// Register the solver of the given index (its name, executable and remote login
// come from the Solver.* options) and initialize it. If the executable is
// missing, one is looked for next to the Gmsh binary, and otherwise asked for.
void solverAdd(const std::string &name, const std::string &executable,
               const std::string &remoteLogin, int index);
// Start the solver of the given index, or refresh the list when index is
// negative. This is what General.LaunchSolverAtStartup triggers.
void solverStart(int index);
// Close the gaps in the Solver.Name<i>/Executable<i>/RemoteLogin<i> options,
// moving the solvers that are left into the first slots, and renumber the
// clients to match. Adding or removing a solver leaves holes otherwise, which
// end up written to the option file.
void solverListCompact();
// ask the user where the executable of a client is, and remember it
void solverChooseExecutable(onelabClientHandle client);

// Act on the second Gmsh instance that the "File > Remote" menu drives, which
// is a ONELAB client named "GmshRemote": "start" launches it (arg is the
// command line to run), "merge" makes it read a file (arg is its name),
// "clear" removes what it sent and "stop" disconnects it. Nothing happens,
// beyond an error message, when the client is not in the expected state.
void remoteAction(const std::string &what, const std::string &arg = "");

// is a solver currently running, and has the user asked it to stop?
bool solverIsRunning();
bool solverStopRequested();
void solverRequestStop(bool stop);
// if the client reported errors, ask the user whether to carry on
void solverCheckForErrors(const std::string &client);

// Instantiate the per-entity ONELAB parameters of an entity from the templates
// named "ONELAB Context/<Dim> Template/...": for each template, the parameter of
// the entity is created on the server if it does not exist yet, with the
// template string replaced by the name of the entity. The names of the
// resulting parameters are appended to names. physicalTag is the tag of the
// physical group when physical is set, and is ignored otherwise.
void onelabContextInstantiate(int dim, int tag, bool physical, int physicalTag,
                              std::vector<std::string> &names);

// --- geometry

void geometryReload();
// append a SetFactory() to the script, so that what follows is built with the
// built-in kernel or with OpenCASCADE
void geometrySetFactory(const std::string &factory);
// open the geometry file in the text editor of General.Editor
void geometryEditInTextEditor();
void geometryRemoveLastCommand();
void geometryCoherence();

// --- mesh

// generate the mesh up to the given dimension (1, 2 or 3)
void meshDimension(int dim);
void meshRefine();
// how is one of "" (the default optimizer), "Netgen", "Laplace2D",
// "UntangleMeshGeometry", "QuadQuasiStructured", ...
void meshOptimize(const std::string &how);
void meshSetOrder(int order);
void meshRecombine();
void meshComputeCrossField();
void meshUnpartition();
void meshConvertOldPartitioning();
// write the mesh to General.OutputFileName, or to the default name for the
// current Mesh.Format, asking before overwriting an existing file
void meshSave();

// The entities the action that is running has picked so far, so that the
// dialog can show them and let them be corrected instead of leaving the user
// to guess. `kind` is ENT_POINT, ENT_CURVE or ENT_SURFACE.
struct pickedEntities {
  int kind;
  // the word for one of them, as the dialog reads it out: "Point", "Curve
  // loop", ...
  std::string what;
  // whether one may be taken back. The loops of a surface are written to the
  // script as they are closed, so they cannot.
  bool editable;
  std::vector<int> tags;
  // What each of them is made of, when it is a loop rather than an entity: a
  // curve loop is worth more as the curves it closes than as its own number.
  // Empty when the entries stand for themselves.
  std::vector<std::vector<int> > members;
  // the word for one member, as the dialog reads it out
  std::string memberWhat;
  pickedEntities() : kind(0), editable(false) {}
};
pickedEntities &geometryPicked();

// Run the tool of one pane of the elementary dialog, and go on running
// whichever pane is picked afterwards. Each tool is a loop of its own that
// only ends when the user aborts it, so switching tool means ending the one
// that runs and starting the next: geometryElementaryRestart() asks for that
// from inside the loop, and this is where the change happens.
void geometryElementary(int pane);
void geometryElementaryRestart(int pane);
// forget the one at that place, and stop drawing it as selected
void geometryUnpick(int index);

// --- clipping

// The six clipping planes, and which of the things drawn each of them cuts.
// The dialog edits one plane at a time, or the box that six of them make; it
// works on a copy, read when it opens and written back on every change, as the
// partitioner does.
struct clippingParameters {
  // which of the six is being edited, and whether it is the box instead
  int plane;
  bool asBox;
  // the plane being edited: A * X + B * Y + C * Z + D = 0
  double coefficient[4];
  // the box, as a centre and a size
  double centre[3], size[3];
  bool wholeElements, onlyDrawIntersecting, onlyVolume;
  clippingParameters();
};
clippingParameters &clippingStore();

// what can be clipped, in the order the dialog lists it: the geometry, the
// mesh, then one entry per view
void clippingTargets(std::vector<std::string> &names);
// does the plane being edited cut that one, and make it so
bool clippingCuts(int index);
void clippingSetCuts(int index, bool on);

// fill the copy from the options, and push it back
void clippingRead();
void clippingWrite();
// turn the plane being edited the other way round
void clippingInvert();
// back to the six faces of the unit cube, cutting nothing
void clippingReset();

// --- statistics

// The numbers the statistics window shows. They are computed on demand, kept
// until asked for again, and read back one at a time: which index means what is
// the business of the description, not of the computing.
void statisticsCompute(bool elementQuality);
// count them again, but only if the window that shows them is up: the model
// changed under it
void statisticsRefresh(bool elementQuality = false);
double statisticsValue(int index);
// have the element quality measures been computed, or is the window still
// showing what it had before?
bool statisticsQuality();
// whether only the visible entities count
bool &statisticsVisibleOnly();
// Make a view of how one quality measure is spread: `which` is 0 for SICN, 1
// for Gamma and 2 for SIGE, and `threeD` asks for it on the mesh itself rather
// than as a curve.
void statisticsHistogram(int which, bool threeD);
// how much memory the process is using, or 0 when that cannot be told
double statisticsMemoryUsage();
// which of the three tabs has something to show: 1 for the mesh, 2 for the
// views, 0 for the geometry when neither has anything
int statisticsFullestPane();

// --- high order meshes

// Everything the high order tools need, so that the panels of the different
// interfaces only have to fill it in. The defaults come from the corresponding
// Mesh.HighOrder* options when there is one.
struct highOrderParameters {
  int order;
  bool linear, incomplete, onlyVisible;
  // 0: optimization, 1: elastic analogy, 2: fast curving,
  // 3: boundary layer curving
  int algorithm;
  double thresholdMin, thresholdMax;
  int numLayers, iterMax, passMax;
  double weight, distanceFactor;
  bool fixBoundaryNodes;
  // what the dialog offers instead: 0 fixed, 1 free. The window this replaces
  // reads fixBoundaryNodes from it and from whether a CAD model is there.
  int boundaryNodes;
  // 0: disjoint strong, 1: adaptive one-by-one, 2: disjoint weak
  int strategy;
  double maxAdaptBlob, adaptBlobDistFact;
  int adaptBlobLayerFact;
  // curve against the CAD rather than straight: the dialog asks it that way
  // round, and `linear` is filled from it when the order is set
  bool useCAD;
  // put the message console up before regularizing
  bool showLog;
  // whether the model still has a CAD to curve against, from the last
  // highOrderMeshInfo()
  bool cadAvailable;
  highOrderParameters();
};

// What the mesh is already: the order of its elements, whether they are
// complete, and whether the model they come from still has the CAD to curve
// them against. The dialog reads it when it opens.
void highOrderMeshInfo(int &order, bool &complete, bool &cad);

// The parameters the high order dialog holds, shared for the same reason as
// geometryStore(): the dialog is declared once and both interfaces bind to it.
highOrderParameters &highOrderStore();

// change the order of the mesh
void highOrderSetOrder(const highOrderParameters &p);
// run the chosen high order optimizer
void highOrderOptimize(const highOrderParameters &p);

// partition the mesh into Mesh.NbPartitions parts, and colour it by partition
void meshPartition();

// Let the user pick parts of the mesh in the 3D view and act on them until the
// selection is aborted. what is "elements", "curves", "surfaces" or "volumes",
// and action is "delete" or "reverse". Like meshInspectElements(), this is a
// blocking loop and must be started from a deferred action.
void meshModifyParts(const std::string &what, const std::string &action);

// Let the user pick elements in the 3D view and print what they are, until the
// selection is aborted. This is a blocking loop: in an immediate-mode interface
// it must be started from a deferred action.
void meshInspectElements();

// Reclassify the mesh into discrete surfaces separated by the sharp edges, i.e.
// those whose dihedral angle exceeds angleInDegrees. When ensureParametrizable
// is set, the surfaces are additionally cut so that each of them can be
// parametrized, and the geometry of the discrete entities is created.
// Reclassify the surfaces of the mesh, splitting them along the edges sharper
// than angleInDegrees. The edges found are gathered in a temporary discrete
// curve, which is removed afterwards without deleting its elements: pass the
// curve where the caller has already collected edges of its own -- an editor
// lets the user pick some by hand -- and they are taken into account too. It is
// created when *selected is null, and is always null on return.
void meshClassifySurfaces(double angleInDegrees, bool ensureParametrizable,
                          GEdge **selected = nullptr);

// --- interactive geometry and mesh definition
//
// These are the actions the modules tree starts: the user picks entities in the
// 3D view, and what they mean is written into the .geo script through
// scriptStringInterface.h, so that anything the interface does could also be
// typed by hand. They only return once the selection is aborted with 'q', so,
// like the other blocking loops, they must be started from a deferred action in
// an immediate-mode interface.
//
// Their parameters are not passed by value but read through a callback, because
// the panel they come from stays usable while the loop runs: the FLTK context
// windows have always let one change a value between two applications without
// starting the selection over, and reading the parameters again at each 'e'
// keeps that true whatever the interface.

struct geometryParameters {
  // what the selection is restricted to: ENT_ALL, ENT_POINT, ENT_CURVE,
  // ENT_SURFACE or ENT_VOLUME
  int selection;
  std::string tx, ty, tz; // translation, and extrusion along a line
  std::string ax, ay, az; // direction of the rotation axis
  std::string px, py, pz, angle; // point on the axis, and rotation angle
  std::string cx, cy, cz, sx, sy, sz; // centre and factors of the scaling
  std::string sa, sb, sc, sd; // symmetry plane, sa x + sb y + sc z + sd = 0
  bool duplicate; // act on a copy instead of on the entities themselves
  bool extrudeMesh; // extrude the mesh along with the geometry
  std::string layers; // how many mesh layers the extrusion has
  bool recombineMesh;
  bool recursive; // delete the entities on the boundary too
  std::string meshSize; // prescribed mesh size at points
  std::string transfinitePoints; // number of points on a transfinite curve
  std::string transfiniteType; // "Progression", "Bump" or "Beta"
  std::string transfiniteParameter;
  std::string transfiniteArrangement; // "Left", "Right" or "Alternated"
  std::string radius; // fillet
  bool deleteObject, deleteTool; // boolean operation
  std::string physicalName;
  int physicalTag; // 0 to let Gmsh choose
  bool physicalAppend; // add to the group of that name instead of replacing it
  std::string physicalMode; // "Add" or "Remove"
  bool physicalAutomatic; // let Gmsh choose the tag of the group
  geometryParameters();
};

// what geometryActOnSelection() does with the entities that were picked
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

// Let the user pick entities and apply the given action to them, over and over
// until the selection is aborted. what restricts the selection to "Point",
// "Curve", "Surface" or "Volume"; when it is empty the user chooses in the
// panel, through geometryParameters::selection.
void geometryActOnSelection(int action, const std::string &what);

// The fields of one pane of the "Elementary Entity Context", in the order the
// panel shows them: pane says which entity is being created, with the same
// numbering as the panes of the FLTK window (0 Parameter, 1 Point, 2 Circle,
// 3 Ellipse, 4 Disk, 5 Rectangle, 6 Sphere, 7 Cylinder, 8 Box, 9 Torus,
// 10 Cone, 11 Wedge). For every pane but the first, the first three fields are
// the X, Y and Z the mouse drives.
struct elementaryParameters {
  int pane;
  std::vector<std::string> value;
  elementaryParameters() : pane(0) {}
};

// The parameters the context dialogs hold. They live here, and not in each
// interface, so that the dialogs can be declared once -- see GuiDialogs.h --
// with both interfaces binding their widgets to the same variables. The
// interactive actions then read them live, which is what lets one change a
// value between two applications without starting the selection over.
geometryParameters &geometryStore();
// the fields of each pane of the elementary dialog, and which pane is shown
std::string &elementaryStore(int pane, int field);
// which of X, Y and Z the user has locked against the mouse
bool &elementaryFrozen(int coord);
int &elementaryPaneStore();
elementaryParameters elementaryStoreParameters();

// how many fields the given pane has
int geometryElementaryFieldCount(int pane);

// Evaluate what the user typed in one of those fields, which may be an
// expression in terms of the symbols of the .geo file rather than a plain
// number; false when it is neither.
bool geometryEvaluate(const std::string &str, double &val);

// Write the entity described by the given fields into the script. This is what
// the "Add" button of the context panel does.
void geometryAddElementary(const elementaryParameters &p);

// Place a new point-based entity with the mouse: while this runs, the pointer
// drives the first three fields of the pane, Shift holds them where they are,
// 'e' writes the entity into the script and 'q' leaves. The entity being built
// is previewed in the 3D view.
void geometryAddPointBasedEntity(int pane);

// Draw the entity described by the given fields in the 3D view, on top of the
// model, until the next call with an empty getter. This is what previews the
// circle or the box one is about to create.
// on turns the preview on for the pane the elementary dialog shows
void geometrySetTransientShape(bool on);

// Where a point placed with the mouse goes: unproject the cursor position of
// the given view into the plane through the centre of gravity of the model, and
// snap the result to Geometry.Snap. The coordinates whose frozen flag is set
// are left as they are.
void geometryPointUnderCursor(drawContext *ctx, int winX, int winY,
                              const bool frozen[3], double point[3]);

// Create a curve out of picked points. type is "Line" (two points), or
// "Spline", "Bezier" or "BSpline" (as many control points as wanted).
void geometryAddCurve(const std::string &type);
// create a circle arc out of its start, centre and end points
void geometryAddCircleArc();
// create an ellipse arc out of its start, centre, major axis and end points
void geometryAddEllipseArc();
// Create a surface out of picked curves, or a volume out of picked surfaces:
// mode is 0 for a plane surface, 1 for a filled surface and 2 for a volume. The
// first contour is the outer boundary, the ones picked afterwards are holes.
void geometryAddSurfaceVolume(int mode);
// Apply a boolean operation between an object and a tool, both picked in the
// view. op is "BooleanIntersection", "BooleanUnion", "BooleanDifference" or
// "BooleanFragments", which is the only one that accepts an empty tool.
void geometryBoolean(const std::string &op);
// round the picked curves of the picked volumes
void geometryFillet();
// split a picked curve at picked points
void geometrySplitCurve();

// Embed the picked points, curves or surfaces -- what is "Point", "Curve" or
// "Surface" -- into a surface or a volume picked afterwards.
void meshDefineEmbedded(const std::string &what);
// Make the picked entities of dimension dim transfinite. In 2D and 3D the
// corners are picked after the entity, and an empty list of corners lets Gmsh
// find them.
void meshDefineTransfinite(int dim);

// --- 3D view

// Orient or reset one view. what is "x", "y" or "z" to point that axis out of
// the screen, "r" to turn the view a quarter turn around the axis perpendicular
// to it, "1:1" to drop the translation and the zoom, or "reset" to drop the
// rotation as well. Set reverse for the variant the FLTK interface binds to
// Shift: the opposite axis direction, the opposite rotation, or, for "1:1",
// recomputing the bounding box around what is visible.
void viewSetOrientation(drawContext *ctx, const std::string &what,
                        bool reverse);

// Whether there is anything to animate: several time steps in a view, or
// General/View cycling turned on.
bool viewIsAnimatable();

// --- post-processing animation

// advance the animation by incr steps; if time is set the time steps of the
// visible views are cycled, otherwise the views themselves are
void animationStep(int time, int incr, bool redraw = true);
// rewind the animation to its first step (or first view)
void animationRewind();

// --- miscellaneous

// append the current visibility information, in .geo format, to the given file
void visibility_save(const std::string &fileName);

// Hide or show what carries the given number, or every one of them when the
// number is "*": 0 for nodes, 1 for elements, 2 to 5 for points, curves,
// surfaces and volumes, 6 to 9 for the physical groups of each.
void visibilityByNumber(int what, const std::string &value, bool show);
// Hide or show what one picks in the scene, until one presses 'q': "points to
// hide", "physical surfaces to show", "show all", and so on.
void visibilityInteractive(const std::string &what);
// merge the files matching General.WatchFilePattern that are not loaded yet
void watchFiles();
// open a URL in the web browser of the system
void openURL(const std::string &url);
// open the reference manual of this version of Gmsh
void helpOnline();

#endif
