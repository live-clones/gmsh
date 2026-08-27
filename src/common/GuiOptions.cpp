// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The option window, described the way the other dialogs are.
//
// What an option looks like cannot be deduced from the option tables of
// DefaultOptions.h: they do not say which numbers are switches, which ones are
// enumerations and what their values mean, which ones belong together on a
// line, or how to name them for a human. The panels are therefore laid out by
// hand, in the tables below, and only the mechanism is generic.
//
// The tables reproduce src/fltk/optionWindow.cpp: the same categories, the
// same tabs, the same rows in the same order, with the same labels. What a
// choice writes is what that window writes, which is not always the index of
// the entry picked. They are their own little language -- CHECK(), COMBO(),
// COLOR() -- kept because 260 options in Dialog::Field form would be
// unreadable, but they are not a second description of a dialog: _paneFor()
// turns a table into the panes and fields of GuiDialogs.h, which is what both
// interfaces build.
//
// The help string of the tooltip is taken from the option table, so it cannot
// drift from the option itself.

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
#include "GmshDefines.h"
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
      RowString,
      RowCombo, // enumeration, choices[] in the order the option numbers them
      RowStringCombo, // enumeration whose value is the text of the choice
      RowColor,
      RowAllColors, // every colour of the category, as the window this
                    // reproduces lists them in a scrolling pane
      RowAction, // not an option: a button running a GuiActions function
      RowRow, // several options on one line under one label, names[] naming them
      RowMulti, // several switches behind one button, names[] naming them
      RowFunction, // an option reached by its accessor, having no table entry
      RowCaption // not an option: a line of text over the rows under it
    };

    struct optionRow {
      rowKind kind;
      const char *name; // option name, or the action for RowAction
      const char *label; // written for a human; null to use the option name
      // RowCombo: the entries. RowRow and RowMulti: the options they hold.
      const char *const *choices;
      // RowCombo: what each entry writes, when it is neither the index nor
      // vmin + vmax * index
      const double *values;
      // RowCombo: the value of the first entry and the step between two, since
      // the values of an enumeration do not always start at zero
      double vmin, vmax;
      // RowFunction: the accessor, since the option has no name to reach it by
      double (*fn)(int, int, double);
      // it shares the line of the row before it, as its second column: the
      // window this reproduces puts the labels of an entity beside the entity
      bool beside;
      // How much of one field's width it takes, when it is not the whole of
      // it: the three boxes of a quality range are a quarter, a quarter and a
      // half there. Last, so that the rows that do not say leave it at zero.
      double share;
    };

#define CHECK(name, label) {RowCheck, name, label, nullptr, nullptr, 0., 0., nullptr, false}
#define NUMBER(name, label) {RowNumber, name, label, nullptr, nullptr, 0., 0., nullptr, false}
#define STRING(name, label) {RowString, name, label, nullptr, nullptr, 0., 0., nullptr, false}
#define COMBO(name, label, choices) \
  {RowCombo, name, label, choices, nullptr, 0., 1., nullptr, false}
#define COMBOV(name, label, choices, first, step) \
  {RowCombo, name, label, choices, nullptr, first, step, nullptr, false}
#define COMBOL(name, label, choices, values) \
  {RowCombo, name, label, choices, values, 0., 1., nullptr, false}
#define STRCOMBO(name, label, choices) \
  {RowStringCombo, name, label, choices, nullptr, 0., 0., nullptr, false}
#define COLOR(name, label) {RowColor, name, label, nullptr, nullptr, 0., 0., nullptr, false}
#define COLORS {RowAllColors, nullptr, nullptr, nullptr, nullptr, 0., 0., nullptr, false}
#define ACTION(id, label) {RowAction, id, label, nullptr, nullptr, 0., 0., nullptr, false}
#define ROW(label, names) {RowRow, nullptr, label, names, nullptr, 0., 0., nullptr, false}
#define VEC2(name, label) {RowRow, name, label, nullptr, nullptr, 2., 0., nullptr, false}
#define VEC3(name, label) {RowRow, name, label, nullptr, nullptr, 3., 0., nullptr, false}
#define VEC2S(name, label) {RowRow, name, label, nullptr, nullptr, 2., 1., nullptr, false}
#define VEC3S(name, label) {RowRow, name, label, nullptr, nullptr, 3., 1., nullptr, false}
#define MULTI(label, names) {RowMulti, nullptr, label, names, nullptr, 0., 0., nullptr, false}
#define CHECKFN(label, fn) {RowFunction, nullptr, label, nullptr, nullptr, 0., 0., fn, false}
#define CAPTION(text) {RowCaption, nullptr, text, nullptr, nullptr, 0., 0., nullptr, false}
// a button at the right end of the line above it
#define ACTION_RIGHT(id, label) \
  {RowAction, id, label, nullptr, nullptr, 1., 0., nullptr, false}
// and a switch sharing that line
#define CHECK_RIGHT(name, label) \
  {RowCheck, name, label, nullptr, nullptr, 1., 0., nullptr, false}
// how much of a field's width a row of values, or a choice after them, takes
#define ROW_OF(label, names, share) \
  {RowRow, nullptr, label, names, nullptr, 0., 0., nullptr, false, share}
#define COMBO_AFTER_OF(name, label, choices, share) \
  {RowCombo, name, label, choices, nullptr, 1., 1., nullptr, true, share}
// a second column on the line of the row before it
#define CHECK_BESIDE(name, label) \
  {RowCheck, name, label, nullptr, nullptr, 0., 0., nullptr, true}
#define NUMBER_BESIDE(name, label) \
  {RowNumber, name, label, nullptr, nullptr, 0., 0., nullptr, true}
// and one that takes only part of a field's width, as the sampling of a label
// takes a third of one there
#define NUMBER_BESIDE_OF(name, label, share) \
  {RowNumber, name, label, nullptr, nullptr, 0., 0., nullptr, true, share}
#define COMBO_BESIDE(name, label, choices) \
  {RowCombo, name, label, choices, nullptr, 0., 1., nullptr, true}
// and one that follows them inside the same column
#define COMBO_AFTER(name, label, choices) \
  {RowCombo, name, label, choices, nullptr, 1., 1., nullptr, true}
#define END {RowCheck, nullptr, nullptr, nullptr, nullptr, 0., 0., nullptr, false}

    struct optionTab {
      const char *label;
      const optionRow *rows;
    };

  // the lists a choice offers, in the order the option numbers them
  const char *const _c_axes[] = {"None", "Simple axes", "Box", "Full grid", "Open grid", "Ruler",  nullptr};
  const char *const _c_orthographic[] = {"Orthographic", "Perspective",  nullptr};
  const char *const _c_vectorType[] = {"Line", "Arrow", "Pyramid", "3D arrow",  nullptr};
  const char *const _c_graphicsFontEngine[] = {"Native", "Cairo", "StringTexture",  nullptr};
  const char *const _c_graphicsFont[] = {"Times-Roman", "Times-Bold", "Times-Italic", "Times-BoldItalic", "Helvetica", "Helvetica-Bold", "Helvetica-Oblique", "Helvetica-BoldOblique", "Courier", "Courier-Bold", "Courier-Oblique", "Courier-BoldOblique", "Symbol", "ZapfDingbats", "Screen",  nullptr};
  const char *const _c_colorScheme[] = {"Light", "Default", "Grayscale", "Dark",  nullptr};
  const char *const _c_backgroundGradient[] = {"None", "Vertical", "Horizontal", "Radial",  nullptr};
  const char *const _c_labelType[] = {"Node/element tag", "Elementary entity tag", "Physical group tag(s)", "Mesh partition", "Coordinates",  nullptr};
  const char *const _c_transform[] = {"None", "Scaling",  nullptr};
  const char *const _c_pointType[] = {"Color dot", "3D sphere",  nullptr};
  const char *const _c_curveType[] = {"Color segment", "3D cylinder",  nullptr};
  const char *const _c_surfaceType[] = {"Cross", "Wireframe", "Solid",  nullptr};
  const char *const _c_volumeType[] = {"Sphere", "Diamond",  nullptr};
  const char *const _c_algorithm[] = {"Automatic", "MeshAdapt", "Delaunay", "Frontal-Delaunay", "BAMG (experimental)", "Frontal-Delaunay for Quads (experimental)", "Packing of parallelograms (experimental)", "Quasi-Structured Quad (experimental)", "Initial Mesh Only (no node insertion)", "Frontal-Delaunay Optimized (experimental)",  nullptr};
  const char *const _c_algorithm3D[] = {"Delaunay", "Frontal", "HXT (experimental)", "MMG3D (experimental, single volume only)", "Initial Mesh Only (no node insertion)",  nullptr};
  const char *const _c_recombinationAlgorithm[] = {"Simple", "Blossom", "Simple Full-Quad", "Blossom Full-Quad", "Christos's bipartite labelling",  nullptr};
  const char *const _c_subdivisionAlgorithm[] = {"None", "All Quads", "All Hexas",  nullptr};
  const char *const _c_qualityType[] = {"SICN", "SIGE", "Gamma", "Disto",  nullptr};
  const char *const _c_lightLines[] = {"No", "Surface", "Volume and surface",  nullptr};
  const char *const _c_colorCarousel[] = {"By element type", "By elementary entity", "By physical group", "By mesh partition",  nullptr};
  const char *const _c_link[] = {"Apply next changes to selected views", "Force same options for selected views",  nullptr};
  const char *const _c_type[] = {"3D", "2D space", "2D time", "2D",  nullptr};
  const char *const _c_intervalsType[] = {"Iso-values", "Continuous map", "Filled iso-values", "Numeric values",  nullptr};
  const char *const _c_scaleType[] = {"Linear", "Logarithmic", "Double logarithmic",  nullptr};
  const char *const _c_rangeType[] = {"Default", "Custom", "Per step",  nullptr};
  const char *const _c_autoPosition[] = {"Manual", "Automatic", "Top left", "Top right", "Bottom left", "Bottom right", "Top", "Bottom", "Left", "Right", "Full", "Top third", "In model coordinates",  nullptr};
  const char *const _c_showTime[] = {
    "None",           "Time series",       "Harmonic data",
    "Automatic",      "Step data",         "Multi-step data",
    "Real eigenvalues", "Complex eigenvalues", nullptr};
  // the views a value or a raise takes its data from, which is not a fixed
  // list: "Self" is the view itself, then every view there is
  const char *const _c_generalizedRaiseView[] = {"Self", nullptr};
  const char *const _c_boundary[] = {"None", "Dimension - 1", "Dimension - 2", "Dimension - 3",  nullptr};
  const char *const _c_forceNumComponents[] = {"Original Field", "Force Scalar", "Force Vector", "Force Tensor",  nullptr};
  const char *const _c_viewPointType[] = {"Color dot", "3D sphere", "Scaled dot", "Scaled sphere",  nullptr};
  const char *const _c_lineType[] = {"Color segment", "3D cylinder", "Tapered cylinder",  nullptr};
  const char *const _c_viewVectorType[] = {"Line", "Arrow", "Pyramid", "3D arrow", "Displacement", "Comet",  nullptr};
  const char *const _c_glyphLocation[] = {"Barycenter", "Node",  nullptr};
  const char *const _c_centerGlyphs[] = {"Left-aligned", "Centered", "Right-aligned",  nullptr};
  const char *const _c_tensorType[] = {"Von-Mises", "Maximum eigenvalue", "Minimum eigenvalue", "Eigenvectors", "Ellipse", "Ellipsoid", "Frame (box)", "Frame (vectors)",  nullptr};

  // What a choice writes when it is not the index of the entry picked. The
  // window this reproduces works it out in its *_options_ok_cb functions, and
  // the values of an enumeration neither start at zero nor go up in order:
  // Mesh.Algorithm is 2 for "Automatic" and 12 for the last entry.
  const double _v_orthographic[] = {1., 0.};
  const double _v_algorithm[] = {2., 1., 5., 6., 7., 8., 9., 11., 3., 12.};
  const double _v_algorithm3D[] = {1., 4., 10., 7., 3.};

  // the switches a menu button gathers, as the window this reproduces does
  const char *const _m_meshElements[] = {"Triangles", "Quadrangles",
                                         "Tetrahedra", "Hexahedra", "Prisms",
                                         "Pyramids", "Trihedra", nullptr};
  const char *const _m_viewElements[] = {
    "DrawPoints", "DrawLines",      "DrawTriangles", "DrawQuadrangles",
    "DrawTetrahedra", "DrawHexahedra", "DrawPrisms", "DrawPyramids", nullptr};
  const char *const _m_viewFields[] = {"DrawScalars", "DrawVectors",
                                       "DrawTensors", nullptr};
  const char *const _r_viewPosition[] = {"PositionX", "PositionY", nullptr};

  // the rows several options share, under one label
  const char *const _r_rotationCenterX[] = {"RotationCenterX", "RotationCenterY", "RotationCenterZ",  nullptr};
  const char *const _r_axesTicsX[] = {"AxesTicsX", "AxesTicsY", "AxesTicsZ",  nullptr};
  const char *const _r_axesFormatX[] = {"AxesFormatX", "AxesFormatY", "AxesFormatZ",  nullptr};
  const char *const _r_axesLabelX[] = {"AxesLabelX", "AxesLabelY", "AxesLabelZ",  nullptr};
  const char *const _r_axesMinX[] = {"AxesMinX", "AxesMinY", "AxesMinZ",  nullptr};
  const char *const _r_axesMaxX[] = {"AxesMaxX", "AxesMaxY", "AxesMaxZ",  nullptr};
  const char *const _r_smallAxesPositionX[] = {"SmallAxesPositionX", "SmallAxesPositionY",  nullptr};
  const char *const _r_polygonOffsetFactor[] = {"PolygonOffsetFactor", "PolygonOffsetUnits",  nullptr};
  const char *const _r_light0X[] = {"Light0X", "Light0Y", "Light0Z",  nullptr};
  const char *const _r_shininess[] = {"Shininess", "ShininessExponent",  nullptr};
  const char *const _r_normals[] = {"Normals", "Tangents",  nullptr};
  const char *const _r_transformXX[] = {"TransformXX", "TransformXY", "TransformXZ",  nullptr};
  const char *const _r_offsetX[] = {"OffsetX", "TransformYX", "TransformYY", "TransformYZ",  nullptr};
  const char *const _r_offsetY[] = {"OffsetY", "TransformZX", "TransformZY", "TransformZZ",  nullptr};
  const char *const _r_meshSize[] = {"MeshSizeMin", "MeshSizeMax", nullptr};
  const char *const _r_quality[] = {"QualityInf", "QualitySup", nullptr};
  const char *const _r_radiusInf[] = {"RadiusInf", "RadiusSup",  nullptr};
  const char *const _r_timeStep[] = {"TimeStep", "NbIso",  nullptr};
  const char *const _r_maxRecursionLevel[] = {"MaxRecursionLevel", "TargetError",  nullptr};
  const char *const _r_positionX[] = {"PositionX", "PositionY",  nullptr};
  const char *const _r_arrowSizeMin[] = {"ArrowSizeMin", "ArrowSizeMax",  nullptr};

  const optionRow _generalGeneral[] = {
    CHECK("FltkColorScheme", "Use dark interface"),
    CHECK("Tooltips", "Show tooltips"),
    CHECK("DrawBoundingBoxes", "Show bounding boxes"),
    CHECK("FastRedraw", "Draw simplified model during user interaction"),
    CHECK("MouseHoverMeshes", "Enable mouse hover over meshes and views"),
    CHECK("DoubleBuffer", "Enable double buffering"),
    CHECK("Antialiasing", "Enable antialiasing"),
    CHECK("Trackball", "Use trackball rotation instead of Euler angles"),
    CHECK("RotationCenterGravity", "Rotate around pseudo center of mass"),
    ROW("Rotation center", _r_rotationCenterX),
    ACTION_RIGHT("rotation_center_select", "Select"),
    CHECK("MouseInvertZoom", "Invert mouse wheel zoom direction"),
    END};

  const optionRow _generalAdvanced[] = {
    CHECK("Terminal", "Print messages on terminal"),
    NUMBER("Verbosity", "Message verbosity"),
    STRING("TextEditor", "Text editor command"),
    STRING("DefaultFileName", "Default file name"),
    CHECK("ConfirmOverwrite", "Ask confirmation before overwriting files"),
    CHECK("SaveSession", "Save session information on exit"),
    CHECK("SaveOptions", "Save options on exit"),
    CHECK("ExpertMode", "Enable expert mode"),
    NUMBER("NumThreads", "Maximum number of threads"),
    CHECKFN("Enable heavy visualization capabilities",
            opt_general_heavy_visualization),
    END};

  const optionRow _generalAxes[] = {
    COMBO("Axes", "Axes mode", _c_axes),
    CHECK("AxesMikado", "Mikado style"),
    ROW("Axes tics", _r_axesTicsX),
    VEC3S("AxesFormat", "Axes format"),
    VEC3S("AxesLabel", "Axes labels"),
    CHECK("AxesAutoPosition", "Set position and size of axes automatically"),
    ROW("Axes minimum", _r_axesMinX),
    ROW("Axes maximum", _r_axesMaxX),
    ACTION_RIGHT("axes_fit", "Fit to visible"),
    CHECK("SmallAxes", "Show small axes"),
    ROW("Small axes position", _r_smallAxesPositionX),
    END};

  const optionRow _generalAspect[] = {
    COMBOL("Orthographic", "Projection mode", _c_orthographic, _v_orthographic),
    NUMBER("ClipFactor", "Z-clipping distance factor"),
    ROW("Polygon offset factor/units", _r_polygonOffsetFactor),
    CHECK("PolygonOffsetAlwaysOn", "Always apply polygon offset"),
    NUMBER("QuadricSubdivisions", "Quadric subdivisions"),
    NUMBER("PointSize", "Point size"),
    NUMBER("PointSize", "Line width"),
    COMBOV("VectorType", "Vector display", _c_vectorType, 1., 1.),
    ACTION_RIGHT("arrow_edit", "Edit arrow"),
    STRCOMBO("GraphicsFontEngine", "Font rendering engine", _c_graphicsFontEngine),
    STRCOMBO("GraphicsFont", "", _c_graphicsFont),
    NUMBER_BESIDE("GraphicsFontSize", "Default font"),
    STRCOMBO("GraphicsFontTitle", "", _c_graphicsFont),
    NUMBER_BESIDE("GraphicsFontSizeTitle", "Title font"),
    END};

  const optionRow _generalColor[] = {
    ROW("Light position", _r_light0X),
    NUMBER("Light0W", "Light position divisor"),
    ROW("Material shininess/exponent", _r_shininess),
    COMBO("ColorScheme", "Predefined color scheme", _c_colorScheme),
    COMBO("BackgroundGradient", "Background gradient", _c_backgroundGradient),
    COLORS,
    END};

  const optionRow _generalCamera[] = {
    CHECK("Camera", "Enable camera (experimental)"),
    CHECK("Stereo", "Enable stereo rendering (experimental)"),
    NUMBER("CameraEyeSeparationRatio", "Eye separation ratio (%)"),
    NUMBER("CameraFocalLengthRatio", "Focal length ratio (%)"),
    NUMBER("CameraAperture", "Camera Aperture (degrees)"),
    CHECKFN("Enable gamepad (experimental)", opt_general_gamepad),
    END};

  const optionRow _geometryGeneral[] = {
    NUMBER("Tolerance", "Geometry tolerance"),
    CHECK("AutoCoherence", "Remove duplicate entities in GEO model transforms"),
    CAPTION("Open CASCADE model healing options:"),
    CHECK("OCCFixDegenerated", "Remove degenerated edges and faces"),
    CHECK("OCCFixSmallEdges", "Remove small edges"),
    CHECK("OCCFixSmallFaces", "Remove small faces"),
    CHECK("OCCSewFaces", "Sew faces"),
    CHECK("OCCMakeSolids", "Fix shells and make solids"),
    NUMBER("OCCScaling", "Global model scaling"),
    END};

  const optionRow _geometryVisibility[] = {
    CHECK("Points", "Points"),
    CHECK_BESIDE("PointLabels", "Point labels"),
    CHECK("Curves", "Curves"),
    CHECK_BESIDE("CurveLabels", "Curve labels"),
    CHECK("Surfaces", "Surfaces"),
    CHECK_BESIDE("SurfaceLabels", "Surface labels"),
    CHECK("Volumes", "Volumes"),
    CHECK_BESIDE("VolumeLabels", "Volume labels"),
    COMBO("LabelType", "Label type", _c_labelType),
    ROW("Normals and tangents", _r_normals),
    END};

  const optionRow _geometryTransfo[] = {
    COMBO("Transform", "Main window transform", _c_transform),
    ROW("X", _r_transformXX),
    ROW("Y +", _r_offsetX),
    ROW("Z", _r_offsetY),
    NUMBER("OffsetZ", ""),
    END};

  const optionRow _geometryAspect[] = {
    COMBO("PointType", "Point display", _c_pointType),
    NUMBER("PointSize", "Point size"),
    NUMBER("PointSelectSize", "Selected point size"),
    COMBO("CurveType", "Curve display", _c_curveType),
    NUMBER("CurveWidth", "Curve width"),
    NUMBER("CurveSelectWidth", "Selected curve width"),
    NUMBER("NumSubEdges", "Curve subdivisions"),
    COMBO("SurfaceType", "Surface display", _c_surfaceType),
    COMBO("VolumeType", "Volume display", _c_volumeType),
    END};

  const optionRow _geometryColor[] = {
    CHECK("Light", "Enable lighting"),
    CHECK("LightTwoSide", "Use two-side lighting"),
    CHECK("HighlightOrphans", "Highlight orphan and boundary entities"),
    COLORS,
    END};

  const optionRow _meshGeneral[] = {
    COMBOL("Algorithm", "2D algorithm", _c_algorithm, _v_algorithm),
    COMBOL("Algorithm3D", "3D algorithm", _c_algorithm3D, _v_algorithm3D),
    COMBO("RecombinationAlgorithm", "2D recombination algorithm", _c_recombinationAlgorithm),
    CHECK("RecombineAll", "Recombine all triangular meshes"),
    COMBO("SubdivisionAlgorithm", "Subdivision algorithm", _c_subdivisionAlgorithm),
    NUMBER("Smoothing", "Smoothing steps"),
    NUMBER("MeshSizeFactor", "Element size factor"),
    ROW("Min/Max element size", _r_meshSize),
    NUMBER("ElementOrder", "Element order"),
    CHECK_RIGHT("SecondOrderIncomplete", "Use incomplete elements"),
    END};

  const optionRow _meshAdvanced[] = {
    CHECK("MeshSizeFromPoints", "Compute element sizes using point values"),
    CHECK("MeshSizeFromParametricPoints", "Compute element sizes using parametric point values"),
    NUMBER("MeshSizeExtendFromBoundary", "Compute element sizes from curvature"),
    CHECK("MeshSizeExtendFromBoundary", "Extend element sizes from boundary"),
    CHECK("Optimize", "Optimize quality of tetrahedra"),
    CHECK("OptimizeNetgen", "Optimize quality of tetrahedra with Netgen"),
    CHECK("HighOrderOptimize", "Optimize high-order meshes"),
    END};

  const optionRow _meshVisibility[] = {
    CHECK("Nodes", "Nodes"),
    CHECK_BESIDE("NodeLabels", "Node labels"),
    CHECK("Lines", "1D elements"),
    CHECK_BESIDE("LineLabels", "1D element labels"),
    CHECK("SurfaceEdges", "2D element edges"),
    CHECK_BESIDE("SurfaceLabels", "2D element labels"),
    CHECK("SurfaceFaces", "2D element faces"),
    CHECK_BESIDE("VolumeLabels", "3D element labels"),
    CHECK("VolumeEdges", "3D element edges"),
    CHECK("VolumeFaces", "3D element faces"),
    COMBO("LabelType", "Label type", _c_labelType),
    NUMBER_BESIDE_OF("LabelSampling", "Sampling", 1. / 3.),
    MULTI("Elements", _m_meshElements),
    ROW_OF("", _r_quality, .5),
    COMBO_AFTER_OF("QualityType", "Quality range", _c_qualityType, .5),
    ROW("Size range", _r_radiusInf),
    ROW("Normals and tangents", _r_normals),
    END};

  const optionRow _meshAspect[] = {
    NUMBER("Explode", "Element shrinking factor"),
    COMBO("PointType", "Point display", _c_pointType),
    NUMBER("PointSize", "Point size"),
    NUMBER("LineWidth", "Line width"),
    NUMBER("NumSubEdges", "High-order element subdivisions"),
    END};

  const optionRow _meshColor[] = {
    CHECK("Light", "Enable lighting"),
    COMBO("LightLines", "Edge lighting", _c_lightLines),
    CHECK("LightTwoSide", "Use two-side lighting"),
    CHECK("SmoothNormals", "Smooth normals"),
    NUMBER("AngleSmoothNormals", "Smoothing threshold angle"),
    COMBO("ColorCarousel", "Coloring mode", _c_colorCarousel),
    COLORS,
    END};

  const optionRow _solverGeneral[] = {
    STRING("SocketName", "Base socket name"),
    NUMBER("Timeout", "Timeout (in seconds)"),
    CHECK("AlwaysListen", "Always listen to incoming connection requests"),
    STRING("PythonInterpreter", "Python interpreter"),
    STRING("OctaveInterpreter", "Octave interpreter"),
    END};

  const optionRow _postGeneral[] = {
    COMBO("Link", "View links", _c_link),
    NUMBER("AnimationDelay", "Frame duration (in seconds)"),
    NUMBER("AnimationStep", "Animation increment step"),
    CHECK("AnimationCycle", "Cycle through views instead of steps"),
    CHECK("CombineRemoveOriginal", "Remove original views after combination"),
    CHECK("HorizontalScales", "Draw value scales horizontally"),
    END};

  const optionRow _viewGeneral[] = {
    COMBOV("Type", "Plot type", _c_type, 1., 1.),
    STRING("Name", "View name"),
    ACTION("view_timestep_down", "-"),
    ACTION("view_timestep_up", "+"),
    ROW("Intervals", _r_timeStep),
    STRING("Format", "Format"),
    COMBOV("IntervalsType", "Intervals type", _c_intervalsType, 1., 1.),
    COMBOV("ScaleType", "", _c_scaleType, 1., 1.),
    COMBOV("RangeType", "Range mode", _c_rangeType, 1., 1.),
    CHECK("SaturateValues", "Saturate"),
    ACTION("view_range_min", "Min"),
    NUMBER("CustomMin", "Custom min"),
    ACTION("view_range_max", "Max"),
    NUMBER("CustomMax", "Custom max"),
    CHECK("AdaptVisualizationGrid", "Adapt visualization grid"),
    ACTION("view_recursion_down", "-"),
    ACTION("view_recursion_up", "+"),
    ROW("Target visualization error", _r_maxRecursionLevel),
    END};

  const optionRow _viewAxes[] = {
    COMBO("Axes", "Axes mode", _c_axes),
    CHECK("AxesMikado", "Mikado style"),
    ROW("Axes tics", _r_axesTicsX),
    VEC3S("AxesFormat", "Axes format"),
    VEC3S("AxesLabel", "Axes labels"),
    CHECK("AxesAutoPosition", "Position 3D axes automatically"),
    ROW("3D axes minimum", _r_axesMinX),
    ROW("3D axes maximum", _r_axesMaxX),
    COMBO("AutoPosition", "2D axes/value scale position", _c_autoPosition),
    ROW("2D axes/value scale position", _r_viewPosition),
    ROW("2D axes/value scale size", _r_positionX),
    END};

  const optionRow _viewVisibility[] = {
    CHECK("ShowScale", "Show value scale"),
    COMBO("ShowTime", "Time display", _c_showTime),
    CHECK("DrawStrings", "Show annotations"),
    CHECK("ShowElement", "Draw element outlines"),
    CHECK("DrawSkinOnly", "Draw only skin of 3D views"),
    MULTI("Elements", _m_viewElements),
    NUMBER("Sampling", "Sampling"),
    COMBO("Boundary", "Element boundary mode", _c_boundary),
    ROW("Normals and tangents", _r_normals),
    // TODO no option: menu "Fields"
    COMBO("ForceNumComponents", "", _c_forceNumComponents),
    END};

  // Three rows of a matrix, each followed by an offset and a raise, under two
  // captions -- the one tab of the window this reproduces that is a grid
  // rather than a column.
  const char *const _r_transformX[] = {
    "TransformXX", "TransformXY", "TransformXZ| X", "OffsetX", "RaiseX",
    nullptr};
  const char *const _r_transformY[] = {
    "TransformYX", "TransformYY", "TransformYZ| Y +", "OffsetY", "RaiseY",
    nullptr};
  const char *const _r_transformZ[] = {
    "TransformZX", "TransformZY", "TransformZZ| Z", "OffsetZ", "RaiseZ",
    nullptr};

  const optionRow _viewTransfo[] = {
    CAPTION("Transform:                                        Raise:"),
    ROW("", _r_transformX),
    ROW("", _r_transformY),
    ROW("", _r_transformZ),
    NUMBER("NormalRaise", "Normal raise"),
    CHECK("UseGeneralizedRaise", "Use general transformation expressions"),
    COMBOV("GeneralizedRaiseView", "Data source", _c_generalizedRaiseView, -1., 1.),
    NUMBER("GeneralizedRaiseFactor", "Factor"),
    STRING("GeneralizedRaiseX", "X expression"),
    STRING("GeneralizedRaiseY", "Y expression"),
    STRING("GeneralizedRaiseZ", "Z expression"),
    END};

  const optionRow _viewAspect[] = {
    NUMBER("Explode", "Element shrinking factor"),
    COMBO("PointType", "Point display", _c_viewPointType),
    NUMBER("PointSize", "Point size"),
    COMBO("LineType", "Line display", _c_lineType),
    CHECK("Stipple", "Stipple"),
    NUMBER("LineWidth", "Line width"),
    COMBOV("VectorType", "Vector display", _c_viewVectorType, 1., 1.),
    ROW("Arrow size", _r_arrowSizeMin),
    NUMBER("DisplacementFactor", "Data source for vector fields"),
    COMBOV("ExternalView", "Data source for vector fields", _c_showTime, -1., 1.),
    COMBOV("GlyphLocation", "Glyph location", _c_glyphLocation, 1., 1.),
    COMBO("CenterGlyphs", "", _c_centerGlyphs),
    COMBOV("TensorType", "Tensor display", _c_tensorType, 1., 1.),
    END};

  const optionRow _viewColor[] = {
    CHECK("Light", "Enable lighting"),
    CHECK("LightLines", "Enable lighting of lines"),
    CHECK("LightTwoSide", "Use two-side lighting"),
    CHECK("SmoothNormals", "Smooth normals"),
    NUMBER("AngleSmoothNormals", "Smoothing threshold angle"),
    CHECK("FakeTransparency", "Use fake transparency mode"),
    COLORS,
    END};

  // The colour map editor is a widget of its own, which this does not have
  // yet; the tab is here so that the window keeps the shape of the one it
  // reproduces.
  const optionRow _viewMap[] = {
    END};

  const optionTab _generalTabs[] = {
    {"General", _generalGeneral},
    {"Advanced", _generalAdvanced},
    {"Axes", _generalAxes},
    {"Aspect", _generalAspect},
    {"Color", _generalColor},
    {"Camera", _generalCamera},
    {nullptr, nullptr}};

  const optionTab _geometryTabs[] = {
    {"General", _geometryGeneral},
    {"Visibility", _geometryVisibility},
    {"Transfo", _geometryTransfo},
    {"Aspect", _geometryAspect},
    {"Color", _geometryColor},
    {nullptr, nullptr}};

  const optionTab _meshTabs[] = {
    {"General", _meshGeneral},
    {"Advanced", _meshAdvanced},
    {"Visibility", _meshVisibility},
    {"Aspect", _meshAspect},
    {"Color", _meshColor},
    {nullptr, nullptr}};

  const optionTab _solverTabs[] = {
    {"General", _solverGeneral},
    {nullptr, nullptr}};

  const optionTab _postTabs[] = {
    {"General", _postGeneral},
    {nullptr, nullptr}};

  const optionTab _viewTabs[] = {
    {"General", _viewGeneral},
    {"Axes", _viewAxes},
    {"Visibility", _viewVisibility},
    {"Transfo", _viewTransfo},
    {"Aspect", _viewAspect},
    {"Color", _viewColor},
    {"Map", _viewMap},
    {nullptr, nullptr}};


    const optionTab *_tabsForCategory(const char *category)
    {
      if(!strcmp(category, "General")) return _generalTabs;
      if(!strcmp(category, "Geometry")) return _geometryTabs;
      if(!strcmp(category, "Mesh")) return _meshTabs;
      if(!strcmp(category, "Solver")) return _solverTabs;
      if(!strcmp(category, "PostProcessing")) return _postTabs;
      if(!strcmp(category, "View")) return _viewTabs;
      return nullptr;
    }

    // ------------------------------------------------------------ the option

    StringXNumber *_findNumber(const char *category, const char *name)
    {
      StringXNumber *o = GetNumberOptionCategory(category);
      for(int i = 0; o && o[i].str; i++)
        if(!strcmp(o[i].str, name)) return &o[i];
      return nullptr;
    }

    StringXString *_findString(const char *category, const char *name)
    {
      StringXString *o = GetStringOptionCategory(category);
      for(int i = 0; o && o[i].str; i++)
        if(!strcmp(o[i].str, name)) return &o[i];
      return nullptr;
    }

    StringXColor *_findColor(const char *category, const char *name)
    {
      StringXColor *o = GetColorOptionCategory(category);
      for(int i = 0; o && o[i].str; i++)
        if(!strcmp(o[i].str, name)) return &o[i];
      return nullptr;
    }

    // What the option window is showing: which category, and which view its
    // View options are editing. Nothing else has any use for it.
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

    // The list down the left of the window this reproduces: five categories
    // and then one line per view, since the View options are those of one
    // view and that is how one says which.
    const char *const _categories[] = {"General", "Geometry", "Mesh", "Solver",
                                       "PostProcessing"};
    const char *const _categoryLabels[] = {"General", "Geometry", "Mesh",
                                           "Solver", "Post-pro"};
    const int _numCategories = 5;

    int _views()
    {
#if defined(HAVE_POST)
      return (int)PView::list.size();
#else
      return 0;
#endif
    }

    // which line of that list is picked, and what it means
    const char *_categoryName(int row)
    {
      if(row < 0) return _categories[0];
      return (row < _numCategories) ? _categories[row] : "View";
    }

    // the fully qualified name and the help string of the option table, so that
    // a tooltip cannot drift from the option it describes
    std::string _tooltipFor(const char *category, const char *name)
    {
      if(!name) return "";
      std::string tip = std::string(category) + "." + name;
      const char *help = nullptr;
      if(StringXNumber *n = _findNumber(category, name)) help = n->help;
      else if(StringXString *t = _findString(category, name)) help = t->help;
      else if(StringXColor *c = _findColor(category, name)) help = c->help;
      if(help && help[0]) tip += "\n\n" + std::string(help);
      return tip;
    }

    void _redraw() { drawContext::global()->draw(); }

    // What the window this reproduces keeps in its activate(): a field that
    // only makes sense when another option is set is greyed rather than
    // hidden. A name ending in "*" stands for every option that begins with it.
    struct enableRule {
      const char *category;
      const char *name;
      const char *when; // the option it depends on
      bool whenOff; // the field is live when that option is off, not on
    };

    const enableRule _rules[] = {
      // rotation_center
      {"General", "RotationCenter*", "RotationCenterGravity", true},
      {"General", "rotation_center_select", "RotationCenterGravity", true},
      // general_axes
      {"General", "AxesTics*", "Axes", false},
      {"General", "AxesFormat*", "Axes", false},
      {"General", "AxesLabel*", "Axes", false},
      // general_axes_auto
      {"General", "AxesMin*", "AxesAutoPosition", true},
      {"General", "AxesMax*", "AxesAutoPosition", true},
      {"General", "axes_fit", "AxesAutoPosition", true},
      // general_small_axes
      {"General", "SmallAxesPosition*", "SmallAxes", false},
      // geo_transform
      {"Geometry", "Transform*", "Transform", false},
      {"Geometry", "Offset*", "Transform", false},
      // mesh_light and view_light
      {"Mesh", "LightLines", "Light", false},
      {"Mesh", "LightTwoSide", "Light", false},
      {"Mesh", "SmoothNormals", "Light", false},
      {"View", "LightLines", "Light", false},
      {"View", "LightTwoSide", "Light", false},
      {"View", "SmoothNormals", "Light", false},
      // custom_range
      {"View", "CustomMin", "RangeType", false},
      {"View", "CustomMax", "RangeType", false},
      {"View", "view_range_min", "RangeType", false},
      {"View", "view_range_max", "RangeType", false},
      // view_adaptive
      {"View", "MaxRecursionLevel", "AdaptVisualizationGrid", false},
      {"View", "TargetError", "AdaptVisualizationGrid", false},
      {"View", "view_recursion_down", "AdaptVisualizationGrid", false},
      {"View", "view_recursion_up", "AdaptVisualizationGrid", false},
      // view_general_transform
      {"View", "GeneralizedRaise*", "UseGeneralizedRaise", false},
      {nullptr, nullptr, nullptr, false}};

    // what makes this field live, if anything does
    std::function<bool()> _enabledBy(const char *category, const char *name,
                                     int num)
    {
      if(!name) return nullptr;
      for(int i = 0; _rules[i].category; i++) {
        const enableRule &r = _rules[i];
        if(strcmp(r.category, category)) continue;
        std::string want = r.name;
        bool matches = (want.back() == '*') ?
                         !strncmp(name, want.c_str(), want.size() - 1) :
                         !strcmp(name, want.c_str());
        if(!matches) continue;
        std::string cat = category, on = r.when;
        bool off = r.whenOff;
        return [cat, on, off, num]() {
          double v = 0.;
          NumberOption(GMSH_GET, cat.c_str(), num, on.c_str(), v, false);
          return off ? (v == 0.) : (v != 0.);
        };
      }
      return nullptr;
    }

    // one option, as the field that edits it
    Field _fieldFor(rowKind kind, const char *category, const char *name,
                    const std::string &label, int num, const optionRow *row)
    {
      Field f;
      f.optionCategory = category;
      f.optionName = name;
      f.optionIndex = num;
      f.label = label;
      f.tooltip = _tooltipFor(category, name);
      f.changed = _redraw;
      f.enabled = _enabledBy(category, name, num);

      switch(kind) {
      case RowCheck: f.kind = Check; break;
      case RowNumber: f.kind = Number; break;
      case RowString: f.kind = Text; break;
      case RowColor: f.kind = Color; break;
      case RowStringCombo:
        f.kind = Choice;
        for(int k = 0; row && row->choices && row->choices[k]; k++)
          f.choices.push_back(row->choices[k]);
        break;
      case RowCombo:
        f.kind = Choice;
        for(int k = 0; row && row->choices && row->choices[k]; k++) {
          f.choices.push_back(row->choices[k]);
          // beside() borrows vmin to say where the choice goes, not what it
          // writes: such a choice always writes the index of its entry
          double first = row->beside ? 0. : row->vmin;
          f.values.push_back(row->values ? (int)row->values[k] :
                                           (int)(first + row->vmax * k));
        }
        break;
      default: break;
      }
      return f;
    }

    // several options on one line under one label, as the window this
    // reproduces draws a point, a direction or a range
    void _addRow(std::vector<Field> &into, const optionRow &row,
                 const char *category, int num)
    {
      std::vector<std::string> names;
      if(row.choices) {
        for(int k = 0; row.choices[k]; k++) names.push_back(row.choices[k]);
      }
      else {
        // VEC2 and VEC3: <name>X, <name>Y and <name>Z
        for(int k = 0; k < (int)row.vmin; k++)
          names.push_back(std::string(row.name) + (char)('X' + k));
      }
      bool strings = (row.choices == nullptr) && (row.vmax == 1.);
      double whole = (row.share > 0.) ? row.share : 1.;
      for(std::size_t k = 0; k < names.size(); k++) {
        // an entry may carry a label of its own, written after a "|": the
        // matrix of a view has one in the middle of its rows
        std::string name = names[k], label;
        std::size_t bar = name.find('|');
        if(bar != std::string::npos) {
          label = name.substr(bar + 1);
          name = name.substr(0, bar);
        }
        else if(k + 1 == names.size())
          label = row.label ? row.label : "";
        Field f = _fieldFor(strings ? RowString : RowNumber, category,
                            name.c_str(), label, num, nullptr);
        f.widthShare = whole / (double)names.size();
        f.packed = true;
        if(k) f.sameRow = true;
        into.push_back(f);
      }
    }

    // several switches behind one button, which is how the window this
    // reproduces offers the element and field types
    Field _multiField(const optionRow &row, const char *category, int num)
    {
      std::vector<std::string> names;
      for(int k = 0; row.choices && row.choices[k]; k++)
        names.push_back(row.choices[k]);
      std::string cat = category;
      Field f;
      f.kind = Choice;
      f.label = row.label;
      f.multiple = true;
      f.dynamicChoices = [names](std::vector<std::string> &labels,
                                 std::vector<int> &values) {
        for(std::size_t k = 0; k < names.size(); k++) {
          labels.push_back(names[k]);
          values.push_back((int)k);
        }
      };
      f.chosen = [names, cat, num](int i) {
        if(i < 0 || i >= (int)names.size()) return false;
        double v = 0.;
        NumberOption(GMSH_GET, cat.c_str(), num, names[i].c_str(), v, false);
        return v != 0.;
      };
      f.choose = [names, cat, num](int i, bool on) {
        if(i < 0 || i >= (int)names.size()) return;
        double v = on ? 1. : 0.;
        NumberOption(GMSH_SET | GMSH_GUI, cat.c_str(), num, names[i].c_str(), v,
                     false);
        drawContext::global()->draw();
      };
      f.changed = _redraw;
      return f;
    }

    // A table, as a pane. The window this reproduces has no titled sections
    // inside a tab: a tab is one column of rows.
    Pane _paneFor(const optionTab &tab, const char *category, int num)
    {
      Pane pane;
      pane.label = tab.label;
      // the window this reproduces places its widgets on two columns, the
      // same for every row of a tab
      pane.columns = 2;
      for(int i = 0; tab.rows[i].name || tab.rows[i].label ||
                     tab.rows[i].kind != RowCheck;
          i++) {
        const optionRow &row = tab.rows[i];
        switch(row.kind) {
        case RowRow: _addRow(pane.fields, row, category, num); break;
        case RowMulti:
          pane.fields.push_back(_multiField(row, category, num));
          break;
        case RowAllColors: {
          // every colour of the category, which the window this reproduces
          // lists rather than naming one by one
          pane.scrolling = true;
          StringXColor *o = GetColorOptionCategory(category);
          for(int k = 0; o && o[k].str; k++) {
            if(o[k].level & GMSH_DEPRECATED) continue;
            pane.fields.push_back(
              _fieldFor(RowColor, category, o[k].str, o[k].str, num, nullptr));
          }
        } break;
        case RowAction: {
          Field f;
          f.kind = Action;
          f.label = row.label;
          std::string what = row.name;
          f.changed = [what]() { optionsAction(what); };
          f.enabled = _enabledBy(category, row.name, num);
          if(row.vmin == 1.) {
            // at the right end of the line above, where the window this
            // reproduces puts it
            Field gap;
            gap.kind = Spacer;
            gap.widthEm = 1.;
            gap.sameRow = true;
            pane.fields.push_back(gap);
            f.sameRow = true;
            f.packed = true;
          }
          pane.fields.push_back(f);
        } break;
        case RowCaption: {
          Field f;
          f.kind = Label;
          std::string text = row.label;
          f.readText = [text]() { return text; };
          pane.fields.push_back(f);
        } break;
        case RowFunction: {
          Field f;
          f.kind = Check;
          f.label = row.label;
          double (*fn)(int, int, double) = row.fn;
          f.readNumber = [fn]() { return fn(0, GMSH_GET, 0.); };
          f.writeNumber = [fn](double v) { fn(0, GMSH_SET | GMSH_GUI, v); };
          f.changed = _redraw;
          pane.fields.push_back(f);
        } break;
        default: {
          Field f = _fieldFor(row.kind, category, row.name,
                              row.label ? row.label : row.name, num, &row);
          if(row.share > 0.) f.widthShare = row.share;
          if(row.beside) {
            f.sameRow = true;
            // vmin says it follows inside the same column rather than
            // starting the next one
            if(row.kind == RowCombo && row.vmin == 1.) f.packed = true;
          }
          // a switch the window this reproduces puts at the right of the line
          // above rather than on one of its own
          if(row.kind == RowCheck && row.vmin == 1.) {
            Field gap;
            gap.kind = Spacer;
            gap.widthEm = 1.;
            gap.sameRow = true;
            pane.fields.push_back(gap);
            f.sameRow = true;
            f.packed = true;
          }
          pane.fields.push_back(f);
        } break;
        }
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

    // a line that is no longer there -- a view that has been closed -- falls
    // back to the first
    if(_state().category >= _numCategories + _views())
      _state().category = 0;
    const char *category = _categoryName(_state().category);
    // the window says which category it is showing, as the one it reproduces
    p.title = std::string("Options - ") +
              ((_state().category < _numCategories) ?
                 _categoryLabels[_state().category] :
                 ("View [" + std::to_string(_state().category - _numCategories) +
                  "]"));

    p.side.push_back(chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        for(int i = 0; i < _numCategories; i++) {
          labels.push_back(_categoryLabels[i]);
          values.push_back(i);
        }
        for(int i = 0; i < _views(); i++) {
          labels.push_back("View [" + std::to_string(i) + "]");
          values.push_back(_numCategories + i);
        }
      },
      [](int i) { return i == _state().category; },
      [](int i, bool on) {
        if(on) {
          _state().category = i;
          if(i >= _numCategories) _state().view = i - _numCategories;
          // another line is another set of tabs: the window is not the same
          // one any more, and has to be built again rather than refreshed
          show(Options, -1);
        }
      },
      false));
    p.side.back().rows = 10;

    // the View options are those of the view whose line is picked
    int num = (_state().category >= _numCategories) ? _state().view : 0;

    const optionTab *tabs = _tabsForCategory(category);
    for(int i = 0; tabs && tabs[i].label; i++)
      p.panes.push_back(_paneFor(tabs[i], category, num));

    // Redraw sits under the list of categories, and only when the model drawn
    // while one interacts is a simplified one: there is nothing to redraw
    // otherwise. The window this reproduces hides it then; here it is greyed.
    // Restoring the defaults is not a button of the window at all -- it is the
    // last row of the general options, where that window keeps it.
    Field again;
    again.kind = Action;
    again.label = "Redraw";
    again.changed = _redraw;
    again.enabled = []() {
      double v = 0.;
      NumberOption(GMSH_GET, "General", 0, "FastRedraw", v, false);
      return v != 0.;
    };
    p.side.push_back(again);
    return p;
  }

} // namespace Dialog
