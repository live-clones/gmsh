// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The option window, described the way the other dialogs are.
//
// What an option looks like cannot be deduced from the option tables of
// DefaultOptions.h: they do not say which numbers are switches, which ones are
// enumerations and what their values mean, which ones belong together, or how
// to name them for a human ("General.FastRedraw" is really "draw a simplified
// model while the mouse is down"). The panels are therefore laid out by hand,
// in the tables below, and only the mechanism is generic.
//
// The tables are their own little language -- CHECK(), COMBO(), COLOR() -- kept
// because 260 options in Dialog::Field form would be unreadable. They are not a
// second description of a dialog: _paneFor() turns a table into the panes and
// fields of GuiDialogs.h, which is what both interfaces build.
//
// The help string of the tooltip is taken from the option table, so it cannot
// drift from the option itself. Whatever is not laid out by hand is still
// reachable: the "All" pane lists every option of the category, searchable.

#include "GmshConfig.h"

#include <cstring>
#include <string>
#include <vector>

#include "GuiDialogs.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "Context.h"
#include "Options.h"
#include "GmshMessage.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

namespace Dialog {

  namespace {


  enum rowKind {
    RowCheck, // on/off switch
    RowNumber, // free numeric value
    RowSlider, // numeric value with bounds
    RowCombo, // enumeration, choices[] indexed by the value
    RowString,
    RowStringCombo, // string option taking one of a fixed set of values
    RowFont, // string option holding the name of a graphics font
    RowColor,
    RowAction, // not an option: a button running a GuiActions function
    RowVec3, // three numbers named <name>X, <name>Y and <name>Z, on one line
    RowHeading // not an option: a title inside the tab
  };

  struct optionRow {
    rowKind kind;
    const char *name; // option name, or the heading text for RowHeading
    const char *label; // written for a human; null to use the option name
    const char *const *choices; // RowCombo
    // RowCombo: the option value of each choice, when they are neither
    // contiguous nor ordered (Mesh.Algorithm goes 2, 1, 5, 6, 7, ...); null to
    // use vmin + vmax * index instead
    const double *values;
    // RowSlider: the bounds. RowCombo: the option value of the first choice and
    // the step between two choices, because the values of an enumeration do not
    // always start at 0 and do not always go up (General.Orthographic is 1 for
    // "Orthographic" and 0 for "Perspective").
    double vmin, vmax;
  };

#define HEADING(text) {RowHeading, text, nullptr, nullptr, nullptr, 0., 0.}
#define CHECK(name, label) {RowCheck, name, label, nullptr, nullptr, 0., 0.}
#define NUMBER(name, label) {RowNumber, name, label, nullptr, nullptr, 0., 0.}
#define SLIDER(name, label, a, b) {RowSlider, name, label, nullptr, nullptr, a, b}
#define COMBO(name, label, choices) {RowCombo, name, label, choices, nullptr, 0., 1.}
#define COMBOV(name, label, choices, first, step) \
  {RowCombo, name, label, choices, nullptr, first, step}
#define COMBOL(name, label, choices, values) \
  {RowCombo, name, label, choices, values, 0., 1.}
#define STRING(name, label) {RowString, name, label, nullptr, nullptr, 0., 0.}
#define STRCOMBO(name, label, choices) {RowStringCombo, name, label, choices, nullptr, 0., 0.}
#define FONT(name, label) {RowFont, name, label, nullptr, nullptr, 0., 0.}
#define ACTION(id, label) {RowAction, id, label, nullptr, nullptr, 0., 0.}
#define COLOR(name, label) {RowColor, name, label, nullptr, nullptr, 0., 0.}
#define VEC3(name, label) {RowVec3, name, label, nullptr, nullptr, 0., 0.}
#define END {RowHeading, nullptr, nullptr, nullptr, nullptr, 0., 0.}

  const char *const _axesModes[] = {"None",      "Simple axes", "Box",
                                    "Full grid", "Open grid",   "Ruler",
                                    nullptr};
  const char *const _projections[] = {"Orthographic", "Perspective", nullptr};
  const char *const _vectorTypes[] = {"Line", "Arrow", "Pyramid", "3D arrow",
                                      nullptr};
  const char *const _fontEngines[] = {"Native", "Cairo", "StringTexture",
                                      nullptr};
  const char *const _colorSchemes[] = {"Light", "Default", "Grayscale", "Dark",
                                       nullptr};
  const char *const _backgroundGradients[] = {"None", "Vertical", "Horizontal",
                                              "Radial", nullptr};

  // ---- General

  const optionRow _generalDisplay[] = {
    HEADING("Rendering"),
    CHECK("Antialiasing", "Enable antialiasing"),
    CHECK("AlphaBlending", "Enable alpha blending (transparency)"),
    CHECK("DoubleBuffer", "Enable double buffering"),
    CHECK("FastRedraw", "Draw a simplified model while interacting"),
    CHECK("DrawBoundingBoxes", "Show bounding boxes"),
    CHECK("HighResolutionGraphics", "Use the full resolution of the display"),
    HEADING("Geometry of the view"),
    COMBOV("Orthographic", "Projection", _projections, 1., -1.),
    NUMBER("ClipFactor", "Z-clipping distance factor"),
    SLIDER("QuadricSubdivisions", "Quadric subdivisions", 3., 30.),
    NUMBER("PointSize", "Point size"),
    NUMBER("LineWidth", "Line width"),
    COMBOV("VectorType", "Vector display", _vectorTypes, 1., 1.),
    HEADING("Polygon offset"),
    CHECK("PolygonOffsetAlwaysOn", "Always apply the polygon offset"),
    NUMBER("PolygonOffsetFactor", "Offset factor"),
    NUMBER("PolygonOffsetUnits", "Offset units"),
    END};

  const optionRow _generalInteraction[] = {
    HEADING("Mouse"),
    CHECK("MouseSelection", "Enable mouse selection"),
    CHECK("MouseHoverMeshes", "Enable mouse hover over meshes and views"),
    CHECK("MouseInvertZoom", "Invert the mouse wheel zoom direction"),
    NUMBER("ZoomFactor", "Zoom factor"),
    HEADING("Rotation"),
    CHECK("Trackball", "Use trackball rotation instead of Euler angles"),
    CHECK("TrackballHyperbolicSheet", "Use a hyperbolic sheet away from the "
                                      "trackball centre"),
    CHECK("RotationCenterGravity", "Rotate around the pseudo centre of mass"),
    VEC3("RotationCenter", "Rotation centre"),
    HEADING("Interface"),
    CHECK("FltkColorScheme", "Use a dark interface"),
    CHECK("Tooltips", "Show tooltips"),
    CHECK("ShowOptionsOnStartup", "Show this window on startup"),
    CHECK("ShowMessagesOnStartup", "Show the message console on startup"),
    NUMBER("FltkRefreshRate", "Refresh rate while meshing (frames per second)"),
    END};

  const optionRow _generalAxes[] = {
    HEADING("3D axes"),
    COMBO("Axes", "Axes mode", _axesModes),
    CHECK("AxesMikado", "Mikado style"),
    VEC3("AxesTics", "Number of tics"),
    STRING("AxesFormatX", "Format of the X values"),
    STRING("AxesFormatY", "Format of the Y values"),
    STRING("AxesFormatZ", "Format of the Z values"),
    STRING("AxesLabelX", "X label"),
    STRING("AxesLabelY", "Y label"),
    STRING("AxesLabelZ", "Z label"),
    CHECK("AxesAutoPosition", "Set the position and the size automatically"),
    VEC3("AxesMin", "Minimum"),
    VEC3("AxesMax", "Maximum"),
    CHECK("AxesForceValue", "Force the displayed values"),
    VEC3("AxesValueMin", "Minimum displayed value"),
    VEC3("AxesValueMax", "Maximum displayed value"),
    HEADING("Small axes"),
    CHECK("SmallAxes", "Show the small axes"),
    NUMBER("SmallAxesSize", "Size"),
    NUMBER("SmallAxesPositionX", "Horizontal position"),
    NUMBER("SmallAxesPositionY", "Vertical position"),
    END};

  const optionRow _generalColors[] = {
    HEADING("Scheme"),
    COMBO("ColorScheme", "Predefined colour scheme", _colorSchemes),
    COMBO("BackgroundGradient", "Background gradient", _backgroundGradients),
    HEADING("Colours"),
    COLOR("Background", "Background"),
    COLOR("BackgroundGradient", "Background gradient"),
    COLOR("Foreground", "Foreground"),
    COLOR("Text", "Text"),
    COLOR("Axes", "Axes"),
    COLOR("SmallAxes", "Small axes"),
    COLOR("AmbientLight", "Ambient light"),
    COLOR("DiffuseLight", "Diffuse light"),
    COLOR("SpecularLight", "Specular light"),
    HEADING("Light"),
    VEC3("Light0", "Position of light 0"),
    NUMBER("Light0W", "Divisor of the position (0 for a directional light)"),
    NUMBER("Shininess", "Material shininess"),
    NUMBER("ShininessExponent", "Shininess exponent"),
    END};

  const optionRow _generalFonts[] = {
    HEADING("Interface"),
    NUMBER("FontSize", "Interface font size (-1 to guess it)"),
    NUMBER("MessageFontSize", "Message console font size"),
    HEADING("Graphic window"),
    STRCOMBO("GraphicsFontEngine", "Rendering engine", _fontEngines),
    FONT("GraphicsFont", "Font"),
    NUMBER("GraphicsFontSize", "Size"),
    FONT("GraphicsFontTitle", "Title font"),
    NUMBER("GraphicsFontSizeTitle", "Title size"),
    END};

  const optionRow _generalCamera[] = {
    CHECK("Camera", "Enable the camera mode (experimental)"),
    NUMBER("CameraAperture", "Aperture (degrees)"),
    NUMBER("CameraFocalLengthRatio", "Focal length ratio (%)"),
    HEADING("Stereo"),
    CHECK("Stereo", "Enable stereo rendering (experimental)"),
    NUMBER("CameraEyeSeparationRatio", "Eye separation ratio (%)"),
    END};

  const optionRow _generalAdvanced[] = {
    HEADING("Messages"),
    CHECK("Terminal", "Print the messages on the terminal"),
    SLIDER("Verbosity", "Verbosity", 0., 99.),
    CHECK("NoPopup", "Never ask anything interactively"),
    HEADING("Files"),
    STRING("DefaultFileName", "Default file name"),
    STRING("TextEditor", "Text editor command"),
    STRING("WatchFilePattern", "Pattern of the files to watch"),
    CHECK("ConfirmOverwrite", "Ask before overwriting a file"),
    CHECK("SaveOptions", "Save the options on exit"),
    CHECK("SaveSession", "Save the session information on exit"),
    HEADING("Computation"),
    NUMBER("NumThreads", "Maximum number of threads (0 to guess it)"),
    CHECK("ExpertMode", "Enable expert mode (hides the warnings for experts)"),
    NUMBER("AbortOnError", "Abort on error (0: no, 1: warn, 2: abort, 3: throw, "
                           "4: exit)"),
    HEADING("Defaults"),
    ACTION("restoreDefaults", "Restore all the options to their default values"),
    END};

  struct optionTab {
    const char *label;
    const optionRow *rows;
  };

  // ---- Geometry

  const char *const _labelTypes[] = {"Description",     "Elementary tag",
                                     "Physical tag(s)", "Elementary name",
                                     "Physical name(s)", "Coordinates",
                                     nullptr};
  const char *const _geoTransforms[] = {"None", "Scaling", nullptr};
  const char *const _pointDisplay[] = {"Colour dot", "3D sphere", nullptr};
  const char *const _curveDisplay[] = {"Colour segment", "3D cylinder",
                                       nullptr};
  const char *const _surfaceDisplay[] = {"Cross", "Wireframe", "Solid",
                                         nullptr};
  const char *const _volumeDisplay[] = {"Sphere", "Diamond", nullptr};

  const optionRow _geometryGeneral[] = {
    HEADING("Tolerances"),
    NUMBER("Tolerance", "Geometrical tolerance"),
    NUMBER("ToleranceBoolean", "Tolerance of the boolean operations"),
    CHECK("AutoCoherence", "Remove the duplicate entities in the GEO transforms"),
    HEADING("OpenCASCADE import"),
    CHECK("OCCFixDegenerated", "Remove the degenerated edges and faces"),
    CHECK("OCCFixSmallEdges", "Remove the small edges"),
    CHECK("OCCFixSmallFaces", "Remove the small faces"),
    CHECK("OCCSewFaces", "Sew the faces"),
    CHECK("OCCMakeSolids", "Fix the shells and make solids"),
    CHECK("OCCImportLabels", "Import the labels and the colours"),
    NUMBER("OCCScaling", "Global scaling of the model"),
    CHECK("OCCParallel", "Use the parallel OpenCASCADE algorithms"),
    HEADING("Extrusion"),
    CHECK("ExactExtrusion", "Use the exact extrusion formula"),
    CHECK("ExtrudeReturnLateralEntities", "Return the lateral entities"),
    NUMBER("ExtrudeSplinePoints", "Number of points of an extruded spline"),
    END};

  const optionRow _geometryVisibility[] = {
    HEADING("Entities"),
    CHECK("Points", "Points"),
    CHECK("Curves", "Curves"),
    CHECK("Surfaces", "Surfaces"),
    CHECK("Volumes", "Volumes"),
    HEADING("Labels"),
    CHECK("PointLabels", "Point labels"),
    CHECK("CurveLabels", "Curve labels"),
    CHECK("SurfaceLabels", "Surface labels"),
    CHECK("VolumeLabels", "Volume labels"),
    COMBO("LabelType", "Label type", _labelTypes),
    HEADING("Normals and tangents"),
    NUMBER("Normals", "Size of the normals"),
    NUMBER("Tangents", "Size of the tangents"),
    CHECK("HighlightOrphans", "Highlight the orphan and boundary entities"),
    END};

  const optionRow _geometryAspect[] = {
    HEADING("Points"),
    COMBO("PointType", "Display", _pointDisplay),
    NUMBER("PointSize", "Size"),
    NUMBER("PointSelectSize", "Size when selected"),
    HEADING("Curves"),
    COMBO("CurveType", "Display", _curveDisplay),
    NUMBER("CurveWidth", "Width"),
    NUMBER("CurveSelectWidth", "Width when selected"),
    NUMBER("NumSubEdges", "Subdivisions used for the display"),
    HEADING("Surfaces and volumes"),
    COMBO("SurfaceType", "Surface display", _surfaceDisplay),
    COMBO("VolumeType", "Volume display", _volumeDisplay),
    HEADING("Lighting"),
    CHECK("Light", "Enable lighting"),
    CHECK("LightTwoSide", "Use two-side lighting"),
    END};

  const optionRow _geometryTransform[] = {
    COMBO("Transform", "Transformation of the main window", _geoTransforms),
    HEADING("Matrix"),
    VEC3("TransformX", "First row"),
    VEC3("TransformY", "Second row"),
    VEC3("TransformZ", "Third row"),
    HEADING("Offset"),
    VEC3("Offset", "Translation"),
    HEADING("Snapping"),
    VEC3("Snap", "Snapping grid"),
    END};

  const optionRow _geometryColours[] = {
    COLOR("Points", "Points"),
    COLOR("Curves", "Curves"),
    COLOR("Surfaces", "Surfaces"),
    COLOR("Volumes", "Volumes"),
    COLOR("Selection", "Selection"),
    COLOR("HighlightZero", "Highlight 0"),
    COLOR("HighlightOne", "Highlight 1"),
    COLOR("HighlightTwo", "Highlight 2"),
    COLOR("Tangents", "Tangents"),
    COLOR("Normals", "Normals"),
    COLOR("Projection", "Projection"),
    END};

  const optionTab _geometryTabs[] = {{"General", _geometryGeneral},
                                     {"Visibility", _geometryVisibility},
                                     {"Aspect", _geometryAspect},
                                     {"Transform", _geometryTransform},
                                     {"Colours", _geometryColours},
                                     {nullptr, nullptr}};

  // ---- Mesh

  const char *const _algo2d[] = {
    "Automatic",
    "MeshAdapt",
    "Delaunay",
    "Frontal-Delaunay",
    "BAMG (experimental)",
    "Frontal-Delaunay for quads (experimental)",
    "Packing of parallelograms (experimental)",
    "Quasi-structured quad (experimental)",
    "Initial mesh only (no node insertion)",
    "Frontal-Delaunay optimized (experimental)",
    nullptr};
  // ALGO_2D_* of GmshDefines.h: the values are neither contiguous nor ordered
  const double _algo2dValues[] = {2., 1., 5., 6., 7., 8., 9., 11., 3., 12.};

  const char *const _algo3d[] = {"Delaunay",
                                 "Frontal",
                                 "HXT (experimental)",
                                 "MMG3D (experimental, single volume only)",
                                 "Initial mesh only (no node insertion)",
                                 nullptr};
  const double _algo3dValues[] = {1., 4., 10., 7., 3.};

  const char *const _recombineAlgos[] = {"Simple", "Blossom",
                                         "Simple full-quad",
                                         "Blossom full-quad", nullptr};
  const char *const _subdivisionAlgos[] = {"None", "All quads", "All hexas",
                                           nullptr};
  const char *const _qualityTypes[] = {"SICN", "SIGE", "Gamma", "Disto",
                                       nullptr};
  const char *const _meshLightLines[] = {"No", "Surface", "Volume and surface",
                                         nullptr};
  const char *const _meshColouring[] = {"By element type", "By elementary entity",
                                        "By physical group",
                                        "By mesh partition", nullptr};

  const optionRow _meshGeneral[] = {
    HEADING("Algorithms"),
    COMBOL("Algorithm", "2D algorithm", _algo2d, _algo2dValues),
    COMBOL("Algorithm3D", "3D algorithm", _algo3d, _algo3dValues),
    COMBO("RecombinationAlgorithm", "2D recombination", _recombineAlgos),
    CHECK("RecombineAll", "Recombine all the triangular meshes"),
    COMBO("SubdivisionAlgorithm", "Subdivision", _subdivisionAlgos),
    HEADING("Element size"),
    NUMBER("MeshSizeMin", "Minimum size"),
    NUMBER("MeshSizeMax", "Maximum size"),
    NUMBER("MeshSizeFactor", "Global scaling factor"),
    CHECK("MeshSizeFromPoints", "Compute the sizes from the values at points"),
    CHECK("MeshSizeFromParametricPoints",
          "Compute the sizes from the values at parametric points"),
    NUMBER("MeshSizeFromCurvature",
           "Number of elements per 2 pi radians (0 to disable)"),
    CHECK("MeshSizeExtendFromBoundary", "Extend the sizes from the boundary"),
    HEADING("Element order"),
    NUMBER("ElementOrder", "Order"),
    CHECK("SecondOrderIncomplete", "Use incomplete elements"),
    CHECK("SecondOrderLinear",
          "Create the high order nodes by linear interpolation"),
    END};

  const optionRow _meshAdvanced[] = {
    HEADING("Optimization"),
    CHECK("Optimize", "Optimize the quality of the tetrahedra"),
    CHECK("OptimizeNetgen", "Optimize the quality of the tetrahedra with Netgen"),
    NUMBER("OptimizeThreshold", "Quality below which an element is optimized"),
    NUMBER("Smoothing", "Number of smoothing steps"),
    CHECK("HighOrderOptimize", "Optimize the high order meshes"),
    HEADING("Parallelism"),
    NUMBER("MaxNumThreads1D", "Threads for the 1D meshing (0 for the default)"),
    NUMBER("MaxNumThreads2D", "Threads for the 2D meshing (0 for the default)"),
    NUMBER("MaxNumThreads3D", "Threads for the 3D meshing (0 for the default)"),
    HEADING("Reproducibility"),
    NUMBER("RandomSeed", "Seed of the random number generator"),
    NUMBER("RandomFactor", "Random perturbation of the 2D meshing"),
    NUMBER("RandomFactor3D", "Random perturbation of the 3D meshing"),
    HEADING("Miscellaneous"),
    CHECK("MeshOnlyVisible", "Mesh only the visible entities"),
    CHECK("MeshOnlyEmpty", "Mesh only the entities that have no mesh"),
    CHECK("Renumber", "Renumber the nodes and the elements after meshing"),
    END};

  const optionRow _meshVisibility[] = {
    HEADING("Elements"),
    CHECK("Nodes", "Nodes"),
    CHECK("Lines", "1D elements"),
    CHECK("SurfaceEdges", "2D element edges"),
    CHECK("SurfaceFaces", "2D element faces"),
    CHECK("VolumeEdges", "3D element edges"),
    CHECK("VolumeFaces", "3D element faces"),
    HEADING("Labels"),
    CHECK("NodeLabels", "Node labels"),
    CHECK("LineLabels", "1D element labels"),
    CHECK("SurfaceLabels", "2D element labels"),
    CHECK("VolumeLabels", "3D element labels"),
    COMBO("LabelType", "Label type", _labelTypes),
    NUMBER("LabelSampling", "Draw one label out of"),
    HEADING("Filters"),
    COMBO("QualityType", "Quality measure", _qualityTypes),
    NUMBER("QualityInf", "Only draw the elements above this quality"),
    NUMBER("QualitySup", "Only draw the elements below this quality"),
    NUMBER("RadiusInf", "Only draw the elements above this size"),
    NUMBER("RadiusSup", "Only draw the elements below this size"),
    HEADING("Normals and tangents"),
    NUMBER("Normals", "Size of the normals"),
    NUMBER("Tangents", "Size of the tangents"),
    END};

  const optionRow _meshAspect[] = {
    NUMBER("Explode", "Element shrinking factor"),
    HEADING("Nodes"),
    COMBO("PointType", "Display", _pointDisplay),
    NUMBER("PointSize", "Size"),
    HEADING("Lines"),
    NUMBER("LineWidth", "Width"),
    NUMBER("NumSubEdges", "Subdivisions of the high order elements"),
    HEADING("Lighting"),
    CHECK("Light", "Enable lighting"),
    COMBO("LightLines", "Lighting of the edges", _meshLightLines),
    CHECK("LightTwoSide", "Use two-side lighting"),
    CHECK("SmoothNormals", "Smooth the normals"),
    NUMBER("AngleSmoothNormals", "Threshold angle of the smoothing"),
    END};

  const optionRow _meshColours[] = {
    COMBO("ColorCarousel", "Colouring mode", _meshColouring),
    HEADING("Colours"),
    COLOR("Nodes", "Nodes"),
    COLOR("NodesSup", "High order nodes"),
    COLOR("Lines", "Lines"),
    COLOR("Triangles", "Triangles"),
    COLOR("Quadrangles", "Quadrangles"),
    COLOR("Tetrahedra", "Tetrahedra"),
    COLOR("Hexahedra", "Hexahedra"),
    COLOR("Prisms", "Prisms"),
    COLOR("Pyramids", "Pyramids"),
    COLOR("Trihedra", "Trihedra"),
    COLOR("Tangents", "Tangents"),
    COLOR("Normals", "Normals"),
    END};

  const optionRow _meshFormats[] = {
    HEADING("MSH"),
    NUMBER("MshFileVersion", "Version of the .msh file"),
    CHECK("Binary", "Write the files in binary"),
    CHECK("SaveAll", "Save all the elements, ignoring the physical groups"),
    CHECK("SaveParametric", "Save the parametric coordinates"),
    CHECK("SaveTopology", "Save the topology of the model"),
    HEADING("STL"),
    CHECK("StlOneSolidPerSurface", "One solid per surface"),
    CHECK("StlRemoveDuplicateTriangles", "Remove the duplicate triangles"),
    HEADING("Miscellaneous"),
    NUMBER("Format", "Output format (0 for the one of the file extension)"),
    NUMBER("ScalingFactor", "Scaling applied to the coordinates"),
    END};

  const optionTab _meshTabs[] = {
    {"General", _meshGeneral},       {"Advanced", _meshAdvanced},
    {"Visibility", _meshVisibility}, {"Aspect", _meshAspect},
    {"Colours", _meshColours},       {"File formats", _meshFormats},
    {nullptr, nullptr}};

  // ---- Solver

  const optionRow _solverGeneral[] = {
    HEADING("Connection"),
    STRING("SocketName", "Base name of the socket"),
    NUMBER("Timeout", "Timeout (seconds)"),
    CHECK("AlwaysListen", "Always listen to the incoming connection requests"),
    CHECK("AutoLoadDatabase", "Load the database automatically"),
    CHECK("AutoSaveDatabase", "Save the database automatically"),
    HEADING("Interpreters"),
    STRING("PythonInterpreter", "Python"),
    STRING("OctaveInterpreter", "Octave"),
    HEADING("Behaviour"),
    CHECK("AutoMesh", "Mesh automatically before running the solver"),
    CHECK("AutoArchiveOutputFiles", "Archive the output files"),
    CHECK("AutoCheck", "Check the model automatically when a value changes"),
    CHECK("AutoShowViews", "Show the views created by the solver"),
    CHECK("ShowInvisibleParameters", "Show the invisible parameters"),
    END};

  const optionTab _solverTabs[] = {{"General", _solverGeneral},
                                   {nullptr, nullptr}};

  // ---- Post-processing

  const char *const _postLinks[] = {
    "Apply the next changes to the selected views",
    "Force the same options for the selected views", nullptr};

  const optionRow _postGeneral[] = {
    COMBO("Link", "Link between the views", _postLinks),
    HEADING("Animation"),
    NUMBER("AnimationDelay", "Duration of a frame (seconds)"),
    NUMBER("AnimationStep", "Increment of a step"),
    CHECK("AnimationCycle", "Cycle through the views instead of the steps"),
    HEADING("Miscellaneous"),
    CHECK("CombineRemoveOriginal", "Remove the original views after combining"),
    CHECK("HorizontalScales", "Draw the value scales horizontally"),
    CHECK("Binary", "Write the .pos files in binary"),
    CHECK("SaveMesh", "Save the mesh in the .pos files"),
    NUMBER("Format", "Output format"),
    END};

  const optionTab _postTabs[] = {{"General", _postGeneral},
                                 {nullptr, nullptr}};

  // ---- View

  const char *const _plotTypes[] = {"3D", "2D space", "2D time", "2D",
                                    nullptr};
  const char *const _intervalTypes[] = {"Iso-values", "Continuous map",
                                        "Filled iso-values", "Numeric values",
                                        nullptr};
  const char *const _scaleTypes[] = {"Linear", "Logarithmic",
                                     "Double logarithmic", nullptr};
  const char *const _rangeTypes[] = {"Default", "Custom", "Per step", nullptr};
  const char *const _boundaryModes[] = {"None", "Dimension - 1",
                                        "Dimension - 2", "Dimension - 3",
                                        nullptr};
  const char *const _positions[] = {
    "Manual",       "Automatic", "Top left", "Top right", "Bottom left",
    "Bottom right", "Top",       "Bottom",   "Left",      "Right",
    "Full",         "Top third", "In model coordinates", nullptr};
  const char *const _pointDisplayPost[] = {"Colour dot", "3D sphere",
                                           "Scaled dot", "Scaled sphere",
                                           nullptr};
  const char *const _lineDisplayPost[] = {"Colour segment", "3D cylinder",
                                          "Tapered cylinder", nullptr};
  const char *const _vectorTypesPost[] = {"Line",         "Arrow", "Pyramid",
                                          "3D arrow",     "Displacement",
                                          "Comet",        nullptr};
  const char *const _tensorTypes[] = {
    "Von Mises",     "Maximum eigenvalue", "Minimum eigenvalue",
    "Eigenvectors",  "Ellipse",            "Ellipsoid",
    "Frame (box)",   "Frame (vectors)",    nullptr};
  const char *const _fieldTypes[] = {"Original field", "Force scalar",
                                     "Force vector", "Force tensor", nullptr};

  const optionRow _viewGeneral[] = {
    COMBO("Type", "Plot type", _plotTypes),
    STRING("Name", "Name"),
    CHECK("Visible", "Visible"),
    HEADING("Values"),
    NUMBER("TimeStep", "Time step"),
    NUMBER("NbIso", "Number of intervals"),
    COMBO("IntervalsType", "Type of the intervals", _intervalTypes),
    COMBO("ScaleType", "Scale", _scaleTypes),
    COMBO("RangeType", "Range", _rangeTypes),
    CHECK("SaturateValues", "Saturate the values outside the range"),
    NUMBER("CustomMin", "Custom minimum"),
    NUMBER("CustomMax", "Custom maximum"),
    STRING("Format", "Format of the values"),
    HEADING("Adaptive visualization"),
    CHECK("AdaptVisualizationGrid", "Adapt the visualization grid"),
    NUMBER("MaxRecursionLevel", "Maximum recursion level"),
    NUMBER("TargetError", "Target error"),
    END};

  const optionRow _viewVisibility[] = {
    CHECK("ShowScale", "Show the value scale"),
    CHECK("ShowElement", "Draw the element outlines"),
    CHECK("DrawStrings", "Show the annotations"),
    CHECK("DrawSkinOnly", "Draw only the skin of the 3D views"),
    NUMBER("Sampling", "Draw one element out of"),
    COMBO("Boundary", "Element boundary", _boundaryModes),
    HEADING("Element types"),
    CHECK("DrawPoints", "Points"),
    CHECK("DrawLines", "Lines"),
    CHECK("DrawTriangles", "Triangles"),
    CHECK("DrawQuadrangles", "Quadrangles"),
    CHECK("DrawTetrahedra", "Tetrahedra"),
    CHECK("DrawHexahedra", "Hexahedra"),
    CHECK("DrawPrisms", "Prisms"),
    CHECK("DrawPyramids", "Pyramids"),
    HEADING("Field types"),
    CHECK("DrawScalars", "Scalars"),
    CHECK("DrawVectors", "Vectors"),
    CHECK("DrawTensors", "Tensors"),
    COMBO("ForceNumComponents", "Force the field type", _fieldTypes),
    HEADING("Normals and tangents"),
    NUMBER("Normals", "Size of the normals"),
    NUMBER("Tangents", "Size of the tangents"),
    END};

  const optionRow _viewAxes[] = {
    COMBO("Axes", "Axes mode", _axesModes),
    CHECK("AxesMikado", "Mikado style"),
    VEC3("AxesTics", "Number of tics"),
    STRING("AxesFormatX", "Format of the X values"),
    STRING("AxesFormatY", "Format of the Y values"),
    STRING("AxesFormatZ", "Format of the Z values"),
    STRING("AxesLabelX", "X label"),
    STRING("AxesLabelY", "Y label"),
    STRING("AxesLabelZ", "Z label"),
    CHECK("AxesAutoPosition", "Position the 3D axes automatically"),
    VEC3("AxesMin", "Minimum"),
    VEC3("AxesMax", "Maximum"),
    HEADING("2D axes and value scale"),
    COMBO("AutoPosition", "Position", _positions),
    NUMBER("PositionX", "Horizontal position"),
    NUMBER("PositionY", "Vertical position"),
    NUMBER("Width", "Width"),
    NUMBER("Height", "Height"),
    END};

  const optionRow _viewAspect[] = {
    NUMBER("Explode", "Element shrinking factor"),
    HEADING("Points"),
    COMBO("PointType", "Display", _pointDisplayPost),
    NUMBER("PointSize", "Size"),
    HEADING("Lines"),
    COMBO("LineType", "Display", _lineDisplayPost),
    NUMBER("LineWidth", "Width"),
    CHECK("Stipple", "Stipple"),
    HEADING("Vectors"),
    COMBO("VectorType", "Display", _vectorTypesPost),
    NUMBER("ArrowSizeMin", "Minimum arrow size"),
    NUMBER("ArrowSizeMax", "Maximum arrow size"),
    NUMBER("DisplacementFactor", "Displacement factor"),
    CHECK("CenterGlyphs", "Centre the glyphs on the elements"),
    HEADING("Tensors"),
    COMBO("TensorType", "Display", _tensorTypes),
    END};

  const optionRow _viewColours[] = {
    HEADING("Lighting"),
    CHECK("Light", "Enable lighting"),
    CHECK("LightLines", "Enable the lighting of the lines"),
    CHECK("LightTwoSide", "Use two-side lighting"),
    CHECK("SmoothNormals", "Smooth the normals"),
    NUMBER("AngleSmoothNormals", "Threshold angle of the smoothing"),
    CHECK("FakeTransparency", "Use the fake transparency mode"),
    HEADING("Colour map"),
    NUMBER("ColormapNumber", "Predefined colour map"),
    NUMBER("ColormapAlpha", "Alpha"),
    NUMBER("ColormapBias", "Bias"),
    NUMBER("ColormapCurvature", "Curvature"),
    CHECK("ColormapInvert", "Invert"),
    CHECK("ColormapSwap", "Swap"),
    HEADING("Colours"),
    COLOR("Points", "Points"),
    COLOR("Lines", "Lines"),
    COLOR("Triangles", "Triangles"),
    COLOR("Quadrangles", "Quadrangles"),
    COLOR("Tetrahedra", "Tetrahedra"),
    COLOR("Axes", "Axes"),
    COLOR("Text2D", "2D text"),
    COLOR("Text3D", "3D text"),
    END};

  const optionRow _viewTransform[] = {
    HEADING("Matrix"),
    VEC3("TransformX", "First row"),
    VEC3("TransformY", "Second row"),
    VEC3("TransformZ", "Third row"),
    HEADING("Offset and raise"),
    VEC3("Offset", "Offset"),
    VEC3("Raise", "Raise"),
    NUMBER("NormalRaise", "Raise along the normal"),
    HEADING("General raise"),
    CHECK("UseGeneralizedRaise", "Use the general transformation expressions"),
    STRING("GeneralizedRaiseX", "X expression"),
    STRING("GeneralizedRaiseY", "Y expression"),
    STRING("GeneralizedRaiseZ", "Z expression"),
    NUMBER("GeneralizedRaiseFactor", "Factor"),
    END};

  const optionTab _viewTabs[] = {
    {"General", _viewGeneral},   {"Visibility", _viewVisibility},
    {"Axes", _viewAxes},         {"Aspect", _viewAspect},
    {"Colours", _viewColours},   {"Transform", _viewTransform},
    {nullptr, nullptr}};

  // ---- Print

  const optionRow _printGeneral[] = {
    HEADING("Raster images"),
    NUMBER("Width", "Width in pixels (-1 for the size of the window)"),
    NUMBER("Height", "Height in pixels (-1 for the size of the window)"),
    CHECK("Background", "Print the background"),
    CHECK("CompositeWindows", "Composite all the graphic windows"),
    NUMBER("JpegQuality", "JPEG quality"),
    HEADING("Vector output"),
    NUMBER("EpsQuality", "Quality (0: raster, 1: simple sort, 2: BSP sort)"),
    CHECK("EpsBestRoot", "Optimize the BSP tree"),
    CHECK("EpsOcclusionCulling", "Cull the occluded primitives"),
    CHECK("EpsCompress", "Compress the output"),
    CHECK("Text", "Print the text"),
    NUMBER("TexWidthInMm", "Width of the TeX output (mm)"),
    HEADING("Parameter sweep"),
    NUMBER("ParameterFirst", "First value"),
    NUMBER("ParameterLast", "Last value"),
    NUMBER("ParameterSteps", "Number of steps"),
    STRING("ParameterCommand", "Command run at every step"),
    END};

  const optionTab _printTabs[] = {{"General", _printGeneral},
                                  {nullptr, nullptr}};

  const optionTab _generalTabs[] = {
    {"Display", _generalDisplay},   {"Interaction", _generalInteraction},
    {"Axes", _generalAxes},         {"Colours & light", _generalColors},
    {"Fonts", _generalFonts},       {"Camera", _generalCamera},
    {"Advanced", _generalAdvanced}, {nullptr, nullptr}};

  const optionTab *_tabsForCategory(const char *category)
  {
    if(!strcmp(category, "General")) return _generalTabs;
    if(!strcmp(category, "Geometry")) return _geometryTabs;
    if(!strcmp(category, "Mesh")) return _meshTabs;
    if(!strcmp(category, "Solver")) return _solverTabs;
    if(!strcmp(category, "PostProcessing")) return _postTabs;
    if(!strcmp(category, "View")) return _viewTabs;
    if(!strcmp(category, "Print")) return _printTabs;
    return nullptr;
  }
    // ---------------------------------------------------------- the option

    StringXNumber *_findNumber(const char *category, const char *name)
    {
      StringXNumber *o = GetNumberOptionCategory(category);
      if(!o) return nullptr;
      for(int i = 0; o[i].str; i++)
        if(!strcmp(o[i].str, name)) return &o[i];
      return nullptr;
    }

    StringXString *_findString(const char *category, const char *name)
    {
      StringXString *o = GetStringOptionCategory(category);
      if(!o) return nullptr;
      for(int i = 0; o[i].str; i++)
        if(!strcmp(o[i].str, name)) return &o[i];
      return nullptr;
    }

    StringXColor *_findColor(const char *category, const char *name)
    {
      StringXColor *o = GetColorOptionCategory(category);
      if(!o) return nullptr;
      for(int i = 0; o[i].str; i++)
        if(!strcmp(o[i].str, name)) return &o[i];
      return nullptr;
    }

    // What the option window is showing: which category, which view its View
    // options apply to. Kept here because nothing else has any use for it.
    struct optionsState {
      int category;
      int view;
      optionsState() : category(0), view(0) {}
    };

    optionsState &_state()
    {
      static optionsState s;
      return s;
    }

    const char *_categoryName(int i)
    {
      const char **all = GetOptionCategories();
      for(int k = 0; all[k]; k++)
        if(k == i) return all[k];
      return all[0];
    }

    int _categoryCount()
    {
      const char **all = GetOptionCategories();
      int n = 0;
      while(all[n]) n++;
      return n;
    }

    // the fully qualified name and the help string of the option table, so
    // that a tooltip cannot drift from the option it describes
    std::string _tooltipFor(const char *category, const optionRow &row)
    {
      std::string tip = std::string(category) + "." + row.name;
      const char *help = nullptr;
      if(StringXNumber *n = _findNumber(category, row.name)) help = n->help;
      else if(StringXString *t = _findString(category, row.name)) help = t->help;
      else if(StringXColor *c = _findColor(category, row.name)) help = c->help;
      if(help && help[0]) tip += "\n\n" + std::string(help);
      return tip;
    }

    // one row of a table, as a field bound to the option it edits
    Field _fieldFor(const optionRow &row, const char *category, int num)
    {
      Field f;
      f.optionCategory = category;
      f.optionName = row.name;
      f.optionIndex = num;
      f.label = row.label ? row.label : row.name;
      f.tooltip = _tooltipFor(category, row);
      f.changed = []() { drawContext::global()->draw(); };

      switch(row.kind) {
      case RowCheck: f.kind = Check; break;
      case RowNumber: f.kind = Number; break;
      case RowSlider:
        f.kind = Number;
        f.minimum = row.vmin;
        f.maximum = row.vmax;
        break;
      case RowString: f.kind = Text; break;
      case RowColor: f.kind = Color; break;
      case RowStringCombo:
        // a choice that stands for its own text
        f.kind = Choice;
        for(int k = 0; row.choices && row.choices[k]; k++)
          f.choices.push_back(row.choices[k]);
        break;
      case RowFont:
        // whatever the graphics backend offers, which is not known here
        f.kind = Choice;
        f.dynamicChoices = [](std::vector<std::string> &labels,
                              std::vector<int> &values) {
          (void)values;
          int n = drawContext::global()->getNumFonts();
          for(int k = 0; k < n; k++)
            labels.push_back(drawContext::global()->getFontName(k));
        };
        break;
      case RowCombo:
        // an enumeration: the value each choice stands for is either listed,
        // or counted from vmin by vmax -- the values of an enumeration do not
        // always start at zero and do not always go up
        f.kind = Choice;
        for(int k = 0; row.choices && row.choices[k]; k++) {
          f.choices.push_back(row.choices[k]);
          f.values.push_back(row.values ? (int)row.values[k] :
                                          (int)(row.vmin + row.vmax * k));
        }
        break;
      default: break;
      }
      return f;
    }

    // three numbers named <name>X, <name>Y and <name>Z, on one line under one
    // label, the way a point or a direction is given everywhere else
    void _addVector(std::vector<Field> &into, const optionRow &row,
                    const char *category, int num)
    {
      for(int k = 0; k < 3; k++) {
        optionRow one = row;
        std::string name = std::string(row.name) + (char)('X' + k);
        one.kind = RowNumber;
        one.name = name.c_str();
        Field f = _fieldFor(one, category, num);
        f.optionName = name;
        f.label = (k == 2) ? (row.label ? row.label : row.name) : "";
        f.widthShare = 1. / 3.;
        f.packed = true;
        if(k) f.sameRow = true;
        into.push_back(f);
      }
    }

    // A table, as a pane: the rows before the first heading are the pane's
    // own, and every heading opens a section under them.
    Pane _paneFor(const optionTab &tab, const char *category, int num)
    {
      Pane pane;
      pane.label = tab.label;
      pane.scrolling = true;
      std::vector<Field> *into = &pane.fields;
      for(int i = 0; tab.rows[i].name || tab.rows[i].kind != RowHeading; i++) {
        const optionRow &row = tab.rows[i];
        if(row.kind == RowHeading) {
          Pane section;
          section.label = row.name;
          pane.sections.push_back(section);
          into = &pane.sections.back().fields;
          continue;
        }
        if(row.kind == RowVec3) {
          _addVector(*into, row, category, num);
          continue;
        }
        if(row.kind == RowAction) {
          Field f;
          f.kind = Action;
          f.label = row.label ? row.label : row.name;
          f.changed = []() { optionsRestoreDefaults(); };
          into->push_back(f);
          continue;
        }
        into->push_back(_fieldFor(row, category, num));
      }
      return pane;
    }

    // Everything the category holds, laid out or not: what the hand-written
    // panes leave out has to stay reachable.
    Pane _everythingPane(const char *category, int num)
    {
      Pane pane;
      pane.label = "All";
      pane.scrolling = true;
      struct group {
        const char *label;
        rowKind kind;
      };
      const group groups[] = {{"Numbers", RowNumber},
                              {"Strings", RowString},
                              {"Colours", RowColor}};
      for(const auto &g : groups) {
        Pane section;
        section.label = g.label;
        if(g.kind == RowNumber) {
          StringXNumber *o = GetNumberOptionCategory(category);
          for(int i = 0; o && o[i].str; i++) {
            if(o[i].level & GMSH_DEPRECATED) continue;
            optionRow row = {g.kind, o[i].str, nullptr, nullptr, nullptr, 0., 0.};
            section.fields.push_back(_fieldFor(row, category, num));
          }
        }
        else if(g.kind == RowString) {
          StringXString *o = GetStringOptionCategory(category);
          for(int i = 0; o && o[i].str; i++) {
            if(o[i].level & GMSH_DEPRECATED) continue;
            optionRow row = {g.kind, o[i].str, nullptr, nullptr, nullptr, 0., 0.};
            section.fields.push_back(_fieldFor(row, category, num));
          }
        }
        else {
          StringXColor *o = GetColorOptionCategory(category);
          for(int i = 0; o && o[i].str; i++) {
            if(o[i].level & GMSH_DEPRECATED) continue;
            optionRow row = {g.kind, o[i].str, nullptr, nullptr, nullptr, 0., 0.};
            section.fields.push_back(_fieldFor(row, category, num));
          }
        }
        if(section.fields.size()) pane.sections.push_back(section);
      }
      return pane;
    }

  } // namespace

  int &optionsCategory() { return _state().category; }
  int &optionsView() { return _state().view; }

  Panel options()
  {
    Panel p;
    p.tabbed = true;

    const char *category = _categoryName(_state().category);
    // the window says which category it is showing, as the one it replaces does
    p.title = std::string("Options - ") + category;

    // which category is being edited, down the left side, as the window this
    // replaces has it
    p.side.push_back(chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        for(int i = 0; i < _categoryCount(); i++) {
          labels.push_back(_categoryName(i));
          values.push_back(i);
        }
      },
      [](int i) { return i == _state().category; },
      [](int i, bool on) {
        if(on) {
          _state().category = i;
          // a category has its own tabs: the window is not the same one any
          // more, and has to be built again rather than refreshed
          show(Options, -1);
        }
      },
      false));
    p.side.back().rows = 10;

    int num = 0;
#if defined(HAVE_POST)
    // the View options are those of one view; which one is chosen below the
    // panes, and only there, since the other categories have but one subject
    if(!strcmp(category, "View")) {
      int views = (int)PView::list.size();
      if(_state().view >= views) _state().view = 0;
      num = _state().view;
      Field which = choice("View", &_state().view, {}, {});
      which.dynamicChoices = [](std::vector<std::string> &labels,
                                std::vector<int> &values) {
        for(int i = 0; i < (int)PView::list.size(); i++) {
          labels.push_back("View [" + std::to_string(i) + "]");
          values.push_back(i);
        }
      };
      p.footer.push_back(which);
    }
#endif

    const optionTab *tabs = _tabsForCategory(category);
    for(int i = 0; tabs && tabs[i].label; i++)
      p.panes.push_back(_paneFor(tabs[i], category, num));
    p.panes.push_back(_everythingPane(category, num));

    Button defaults;
    defaults.label = "Defaults";
    defaults.apart = true;
    defaults.action = []() { optionsRestoreDefaults(); };
    p.buttons.push_back(defaults);

    Button redraw;
    redraw.label = "Redraw";
    redraw.isDefault = true;
    redraw.action = []() { drawContext::global()->draw(); };
    p.buttons.push_back(redraw);
    return p;
  }

} // namespace Dialog
