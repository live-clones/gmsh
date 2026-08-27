// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The option editor.
//
// What an option looks like cannot be deduced from the option tables of
// DefaultOptions.h: they do not say which numbers are switches, which ones are
// enumerations and what their values mean, which ones belong together, or how
// to name them for a human ("General.FastRedraw" is really "draw a simplified
// model while the mouse is down"). The layout of the panels is therefore
// written by hand below, exactly as the FLTK option window does it, and only
// the *mechanism* is generic: a row says which option it edits and how, and the
// reading and writing go through NumberOption()/StringOption()/ColorOption(),
// so there is no per-option callback and no widget to keep in sync.
//
// The help string shown in the tooltip is still taken from the option table, so
// it never gets out of date.
//
// Whatever is not laid out by hand is still reachable: the "All" tab lists
// every option of the category, alphabetically and searchable.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstring>
#include <map>
#include <string>

#include "imgui.h"
#include "imgui_stdlib.h"

#include "appWindow.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "GuiActions.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

namespace {

  // ------------------------------------------------------------------ layout

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

  // ------------------------------------------------------------- the machinery

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

  // the tooltip always shows the fully qualified name and the help string of
  // the option table, so that it cannot drift from the actual option
  void _tooltip(const char *category, const char *name, const char *help)
  {
    if(!ImGui::BeginItemTooltip()) return;
    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 30.f);
    ImGui::Text("%s.%s", category, name);
    if(help && help[0]) {
      ImGui::Separator();
      ImGui::TextUnformatted(help);
    }
    ImGui::PopTextWrapPos();
    ImGui::EndTooltip();
  }

  void _missing(const char *category, const char *name)
  {
    ImGui::TextDisabled("%s.%s is not available in this build", category, name);
  }

  // buffers of the string fields being edited, so that typing is not fought by
  // the value being read back at every frame
  std::map<std::string, std::string> _stringEdits;

  bool _drawString(const char *category, StringXString *o, int num,
                   const char *label)
  {
    std::string current = o->function(num, GMSH_GET, "");
    std::string key = std::string(category) + "." + o->str;
    auto it = _stringEdits.find(key);
    if(it == _stringEdits.end())
      it = _stringEdits.insert(std::make_pair(key, current)).first;

    bool changed = false;
    ImGui::SetNextItemWidth(240.f);
    ImGui::InputText(label ? label : o->str, &it->second);
    if(ImGui::IsItemDeactivatedAfterEdit()) {
      o->function(num, GMSH_SET | GMSH_GUI, it->second);
      changed = true;
    }
    else if(!ImGui::IsItemActive() && it->second != current) {
      it->second = current;
    }
    _tooltip(category, o->str, o->help);
    return changed;
  }

  bool _drawColor(const char *category, StringXColor *o, int num,
                  const char *label)
  {
    unsigned int packed = o->function(num, GMSH_GET, 0);
    float col[4] = {CTX::instance()->unpackRed(packed) / 255.f,
                    CTX::instance()->unpackGreen(packed) / 255.f,
                    CTX::instance()->unpackBlue(packed) / 255.f,
                    CTX::instance()->unpackAlpha(packed) / 255.f};
    bool changed = false;
    if(ImGui::ColorEdit4(label ? label : o->str, col,
                         ImGuiColorEditFlags_NoInputs |
                           ImGuiColorEditFlags_AlphaPreviewHalf)) {
      o->function(num, GMSH_SET | GMSH_GUI,
                  CTX::instance()->packColor((int)(col[0] * 255.f + 0.5f),
                                             (int)(col[1] * 255.f + 0.5f),
                                             (int)(col[2] * 255.f + 0.5f),
                                             (int)(col[3] * 255.f + 0.5f)));
      changed = true;
    }
    _tooltip(category, o->str, o->help);
    return changed;
  }

  // draw one hand-written row
  bool _drawRow(const char *category, const optionRow &row, int num)
  {
    if(row.kind == RowHeading) {
      ImGui::SeparatorText(row.name);
      return false;
    }

    bool changed = false;
    ImGui::PushID(row.name);

    if(row.kind == RowString) {
      StringXString *o = _findString(category, row.name);
      if(!o)
        _missing(category, row.name);
      else
        changed = _drawString(category, o, num, row.label);
    }
    else if(row.kind == RowStringCombo) {
      StringXString *o = _findString(category, row.name);
      if(!o) { _missing(category, row.name); }
      else {
        std::string current = o->function(num, GMSH_GET, "");
        ImGui::SetNextItemWidth(240.f);
        if(ImGui::BeginCombo(row.label ? row.label : o->str, current.c_str())) {
          for(int k = 0; row.choices[k]; k++)
            if(ImGui::Selectable(row.choices[k], current == row.choices[k])) {
              o->function(num, GMSH_SET | GMSH_GUI, row.choices[k]);
              changed = true;
            }
          ImGui::EndCombo();
        }
        _tooltip(category, o->str, o->help);
      }
    }
    else if(row.kind == RowFont) {
      // the list of fonts is whatever the current graphics backend offers
      StringXString *o = _findString(category, row.name);
      if(!o) { _missing(category, row.name); }
      else {
        std::string current = o->function(num, GMSH_GET, "");
        ImGui::SetNextItemWidth(240.f);
        if(ImGui::BeginCombo(row.label ? row.label : o->str, current.c_str())) {
          int n = drawContext::global()->getNumFonts();
          for(int k = 0; k < n; k++) {
            const char *f = drawContext::global()->getFontName(k);
            if(ImGui::Selectable(f, current == f)) {
              o->function(num, GMSH_SET | GMSH_GUI, f);
              changed = true;
            }
          }
          ImGui::EndCombo();
        }
        _tooltip(category, o->str, o->help);
      }
    }
    else if(row.kind == RowAction) {
      if(ImGui::Button(row.label)) {
        if(!strcmp(row.name, "restoreDefaults"))
          appWindow::instance()->postAction(optionsRestoreDefaults);
      }
    }
    else if(row.kind == RowColor) {
      StringXColor *o = _findColor(category, row.name);
      if(!o)
        _missing(category, row.name);
      else
        changed = _drawColor(category, o, num, row.label);
    }
    else if(row.kind == RowVec3) {
      const char *suffix[3] = {"X", "Y", "Z"};
      StringXNumber *o[3];
      bool ok = true;
      for(int k = 0; k < 3; k++) {
        std::string n = std::string(row.name) + suffix[k];
        o[k] = _findNumber(category, n.c_str());
        if(!o[k]) ok = false;
      }
      if(!ok) { _missing(category, row.name); }
      else {
        double v[3];
        for(int k = 0; k < 3; k++) v[k] = o[k]->function(num, GMSH_GET, 0.);
        ImGui::SetNextItemWidth(240.f);
        if(ImGui::InputScalarN(row.label ? row.label : row.name,
                               ImGuiDataType_Double, v, 3, nullptr, nullptr,
                               "%g", ImGuiInputTextFlags_EnterReturnsTrue)) {
          for(int k = 0; k < 3; k++)
            o[k]->function(num, GMSH_SET | GMSH_GUI, v[k]);
          changed = true;
        }
        _tooltip(category, row.name, o[0]->help);
      }
    }
    else {
      StringXNumber *o = _findNumber(category, row.name);
      if(!o) { _missing(category, row.name); }
      else {
        double value = o->function(num, GMSH_GET, 0.);
        const char *label = row.label ? row.label : o->str;
        if(row.kind == RowCheck) {
          bool b = (value != 0.);
          if(ImGui::Checkbox(label, &b)) {
            o->function(num, GMSH_SET | GMSH_GUI, b ? 1. : 0.);
            changed = true;
          }
        }
        else if(row.kind == RowCombo) {
          int n = 0;
          while(row.choices[n]) n++;
          double first = row.vmin, step = (row.vmax != 0.) ? row.vmax : 1.;
          int index = -1;
          if(row.values) {
            for(int k = 0; k < n; k++)
              if(row.values[k] == value) { index = k; break; }
          }
          else {
            index = (int)((value - first) / step);
          }
          const char *preview =
            (index >= 0 && index < n) ? row.choices[index] : "?";
          ImGui::SetNextItemWidth(240.f);
          if(ImGui::BeginCombo(label, preview)) {
            for(int k = 0; k < n; k++)
              if(ImGui::Selectable(row.choices[k], k == index)) {
                o->function(num, GMSH_SET | GMSH_GUI,
                            row.values ? row.values[k] : (first + step * k));
                changed = true;
              }
            ImGui::EndCombo();
          }
        }
        else if(row.kind == RowSlider) {
          ImGui::SetNextItemWidth(240.f);
          if(ImGui::SliderScalar(label, ImGuiDataType_Double, &value, &row.vmin,
                                 &row.vmax, "%g")) {
            o->function(num, GMSH_SET | GMSH_GUI, value);
            changed = true;
          }
        }
        else {
          ImGui::SetNextItemWidth(240.f);
          if(ImGui::InputDouble(label, &value, 0., 0., "%g",
                                ImGuiInputTextFlags_EnterReturnsTrue)) {
            o->function(num, GMSH_SET | GMSH_GUI, value);
            changed = true;
          }
        }
        _tooltip(category, o->str, o->help);
      }
    }

    ImGui::PopID();
    return changed;
  }

  bool _drawTab(const char *category, const optionRow *rows, int num)
  {
    bool changed = false;
    for(int i = 0; rows[i].name || rows[i].kind != RowHeading; i++) {
      if(!rows[i].name && rows[i].kind == RowHeading) break;
      changed |= _drawRow(category, rows[i], num);
    }
    return changed;
  }

  // ------------------------------------------------- the generated "All" list

  bool _matchesFilter(const char *name, const char *help, const char *filter)
  {
    if(!filter || !filter[0]) return true;
    std::string f(filter), n(name ? name : ""), h(help ? help : "");
    auto lower = [](std::string &s) {
      for(auto &c : s) c = (char)tolower((unsigned char)c);
    };
    lower(f);
    lower(n);
    lower(h);
    return n.find(f) != std::string::npos || h.find(f) != std::string::npos;
  }

  bool _drawAll(const char *category, int num, const char *filter)
  {
    bool changed = false;
    StringXNumber *numbers = GetNumberOptionCategory(category);
    if(numbers) {
      bool any = false;
      for(int i = 0; numbers[i].str; i++) {
        if(numbers[i].level & GMSH_DEPRECATED) continue;
        if(!_matchesFilter(numbers[i].str, numbers[i].help, filter)) continue;
        if(!any) { ImGui::SeparatorText("Numbers"); any = true; }
        optionRow row = {RowNumber, numbers[i].str, nullptr, nullptr, nullptr, 0., 0.};
        changed |= _drawRow(category, row, num);
      }
    }
    StringXString *strings = GetStringOptionCategory(category);
    if(strings) {
      bool any = false;
      for(int i = 0; strings[i].str; i++) {
        if(strings[i].level & GMSH_DEPRECATED) continue;
        if(!_matchesFilter(strings[i].str, strings[i].help, filter)) continue;
        if(!any) { ImGui::SeparatorText("Strings"); any = true; }
        optionRow row = {RowString, strings[i].str, nullptr, nullptr, nullptr, 0., 0.};
        changed |= _drawRow(category, row, num);
      }
    }
    StringXColor *colors = GetColorOptionCategory(category);
    if(colors) {
      bool any = false;
      for(int i = 0; colors[i].str; i++) {
        if(colors[i].level & GMSH_DEPRECATED) continue;
        if(!_matchesFilter(colors[i].str, colors[i].help, filter)) continue;
        if(!any) { ImGui::SeparatorText("Colours"); any = true; }
        optionRow row = {RowColor, colors[i].str, nullptr, nullptr, nullptr, 0., 0.};
        changed |= _drawRow(category, row, num);
      }
    }
    return changed;
  }

} // namespace

void appWindow::_drawOptionsPanel()
{
  if(!_showOptions) return;

  ImGui::SetNextWindowSize(ImVec2(620, 660), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Options", &_showOptions)) {
    ImGui::End();
    return;
  }

  static char filter[128] = "";
  int &category = _optionsCategory; // the quick access menu may preselect it
  static int viewIndex = 0;
  const char **categories = GetOptionCategories();
  int numCategories = 0;
  while(categories[numCategories]) numCategories++;
  if(category >= numCategories) category = 0;

  ImGui::SetNextItemWidth(150.f);
  if(ImGui::BeginCombo("##category", categories[category])) {
    for(int i = 0; i < numCategories; i++)
      if(ImGui::Selectable(categories[i], category == i)) category = i;
    ImGui::EndCombo();
  }

  int num = 0;
  if(!strcmp(categories[category], "View")) {
#if defined(HAVE_POST)
    int numViews = (int)PView::list.size();
    if(!numViews) {
      ImGui::TextDisabled("No post-processing view loaded");
      ImGui::End();
      return;
    }
    if(viewIndex >= numViews) viewIndex = 0;
    ImGui::SameLine();
    ImGui::SetNextItemWidth(150.f);
    ImGui::SliderInt("View", &viewIndex, 0, numViews - 1);
    num = viewIndex;
#else
    ImGui::TextDisabled("Gmsh was compiled without post-processing support");
    ImGui::End();
    return;
#endif
  }

  bool changed = false;
  if(ImGui::BeginTabBar("##tabs")) {
    const optionTab *tabs = _tabsForCategory(categories[category]);
    for(int i = 0; tabs && tabs[i].label; i++) {
      if(ImGui::BeginTabItem(tabs[i].label)) {
        if(ImGui::BeginChild("##rows"))
          changed |= _drawTab(categories[category], tabs[i].rows, num);
        ImGui::EndChild();
        ImGui::EndTabItem();
      }
    }
    if(ImGui::BeginTabItem("All")) {
      ImGui::SetNextItemWidth(-1.f);
      ImGui::InputTextWithHint("##filter",
                               "Search an option by name or by help", filter,
                               sizeof(filter));
      if(!tabs)
        ImGui::TextDisabled("This category does not have hand-written panels "
                            "yet: every option is listed below.");
      if(ImGui::BeginChild("##allrows"))
        changed |= _drawAll(categories[category], num, filter);
      ImGui::EndChild();
      ImGui::EndTabItem();
    }
    ImGui::EndTabBar();
  }

  if(changed) drawContext::global()->draw();

  ImGui::End();
}

#endif
