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
// COLOR() -- kept because 260 options in Ui::Field form would be
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
#include "ColorTable.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

namespace {

  // What a colour map field is bound to: the map of the view of that index.
  Ui::ColourMap _colourMapOf(int index)
  {
    Ui::ColourMap map;
#if defined(HAVE_POST)
    auto table = [index]() -> GmshColorTable * {
      if(index < 0 || index >= (int)PView::list.size()) return nullptr;
      return &PView::list[index]->getOptions()->colorTable;
    };
    map.about = [index](std::string &name, double &least, double &most) {
      if(index < 0 || index >= (int)PView::list.size()) return;
      PView *v = PView::list[index];
      name = v->getData()->getName();
      least = v->getData()->getMin();
      most = v->getData()->getMax();
    };
    map.size = [table]() {
      GmshColorTable *t = table();
      return t ? t->size : 0;
    };
    map.colour = [table](int i) {
      GmshColorTable *t = table();
      if(!t || i < 0 || i >= t->size) return Ui::Colour();
      unsigned int c = t->table[i];
      CTX *x = CTX::instance();
      return Ui::Colour((unsigned char)x->unpackRed(c),
                        (unsigned char)x->unpackGreen(c),
                        (unsigned char)x->unpackBlue(c),
                        (unsigned char)x->unpackAlpha(c));
    };
    map.setColour = [table](int i, const Ui::Colour &c) {
      GmshColorTable *t = table();
      if(!t || i < 0 || i >= t->size) return;
      t->table[i] = CTX::instance()->packColor(c.r, c.g, c.b, c.a);
    };
    map.numPresets = []() { return 25; };
    map.preset = [table]() {
      GmshColorTable *t = table();
      return t ? t->ipar[COLORTABLE_NUMBER] : 0;
    };
    map.choosePreset = [table](int preset) {
      GmshColorTable *t = table();
      if(!t) return;
      ColorTable_InitParam(preset, t);
      ColorTable_Recompute(t);
    };
    map.copy = [table]() {
      GmshColorTable *t = table();
      if(t) ColorTable_Copy(t);
    };
    map.paste = [table]() {
      GmshColorTable *t = table();
      if(t) ColorTable_Paste(t);
    };
    // The eight numbers the map is computed from, each with the keys the
    // window this reproduces changes it with. Which of ipar and dpar a
    // parameter lives in, and what its place in them is, stops here.
    map.parameters = [table]() {
      std::vector<Ui::ColourMap::Parameter> ps;
      GmshColorTable *t = table();
      int span = t ? t->size - 1 : 0;
      auto add = [&ps](const std::string &name, Ui::Shortcut up,
                       Ui::Shortcut down, double least, double most,
                       double step, double period = 0.) {
        Ui::ColourMap::Parameter p;
        p.name = name;
        p.up = up;
        p.down = down;
        p.least = least;
        p.most = most;
        p.step = step;
        p.wraps = period != 0.;
        p.period = period;
        p.toggle = down.empty() && step == 0.;
        ps.push_back(p);
      };
      add("Invert", Ui::Shortcut('I', Ui::ModCommand), Ui::Shortcut(), 0., 0.,
          0.);
      add("Swap", Ui::Shortcut('I'), Ui::Shortcut(), 0., 0., 0.);
      add("Rotation", Ui::Shortcut(Ui::KeyLeft, Ui::ModCommand),
          Ui::Shortcut(Ui::KeyRight, Ui::ModCommand), -span, span, 5., span);
      add("Curvature", Ui::Shortcut(Ui::KeyDown), Ui::Shortcut(Ui::KeyUp), 0.,
          0., .05);
      add("Offset", Ui::Shortcut(Ui::KeyRight), Ui::Shortcut(Ui::KeyLeft), 0.,
          0., .05);
      add("Alpha", Ui::Shortcut('A', Ui::ModCommand), Ui::Shortcut('A'), 0.,
          1., .05);
      add("Beta", Ui::Shortcut('B'), Ui::Shortcut('B', Ui::ModCommand), -1.,
          1., .05);
      add("Alpha power", Ui::Shortcut('P'),
          Ui::Shortcut('P', Ui::ModCommand), 0., 0., .05);
      return ps;
    };
    map.parameter = [table](const std::string &name) -> double {
      GmshColorTable *t = table();
      if(!t) return 0.;
      if(name == "Invert") return t->ipar[COLORTABLE_INVERT];
      if(name == "Swap") return t->ipar[COLORTABLE_SWAP];
      if(name == "Rotation") return t->ipar[COLORTABLE_ROTATION];
      if(name == "Curvature") return t->dpar[COLORTABLE_CURVATURE];
      if(name == "Offset") return t->dpar[COLORTABLE_BIAS];
      if(name == "Alpha") return t->dpar[COLORTABLE_ALPHA];
      if(name == "Beta") return t->dpar[COLORTABLE_BETA];
      if(name == "Alpha power") return t->dpar[COLORTABLE_ALPHAPOW];
      return 0.;
    };
    map.setParameter = [table](const std::string &name, double v) {
      GmshColorTable *t = table();
      if(!t) return;
      if(name == "Invert")
        t->ipar[COLORTABLE_INVERT] = (int)v;
      else if(name == "Swap")
        t->ipar[COLORTABLE_SWAP] = (int)v;
      else if(name == "Rotation")
        t->ipar[COLORTABLE_ROTATION] = (int)v;
      else if(name == "Curvature")
        t->dpar[COLORTABLE_CURVATURE] = v;
      else if(name == "Offset")
        t->dpar[COLORTABLE_BIAS] = v;
      else if(name == "Alpha")
        t->dpar[COLORTABLE_ALPHA] = v;
      else if(name == "Beta")
        t->dpar[COLORTABLE_BETA] = v;
      else if(name == "Alpha power")
        t->dpar[COLORTABLE_ALPHAPOW] = v;
      else
        return;
      ColorTable_Recompute(t);
    };
    map.hsv = [table]() {
      GmshColorTable *t = table();
      return t && t->ipar[COLORTABLE_MODE] == COLORTABLE_HSV;
    };
    map.setHsv = [table](bool on) {
      GmshColorTable *t = table();
      if(t) t->ipar[COLORTABLE_MODE] = on ? COLORTABLE_HSV : COLORTABLE_RGB;
    };
#else
    (void)index;
#endif
    return map;
  }

} // namespace

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
      RowSphere, // the disc one drags to give a direction, names[] naming the
                 // three options it writes
      RowRow, // several options on one line under one label, names[] naming them
      RowMulti, // several switches behind one button, names[] naming them
      RowFunction, // an option reached by its accessor, having no table entry
      RowViewList, // a choice of "Self" or one of the views there are
      RowColorMap, // the colour map of a view, which is a widget of its own
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
// a switch that decides whether another field is there at all, so that the
// window has to be built again rather than refreshed
#define CHECK_SHOWS(name, label) \
  {RowCheck, name, label, nullptr, nullptr, 2., 0., nullptr, false}
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
// one taking part of a field's width, the value after it filling the rest:
// the window this reproduces puts a font and its size inside one field
#define STRCOMBO_OF(name, label, choices, share) \
  {RowStringCombo, name, label, choices, nullptr, 1., 0., nullptr, false, share}
#define COLOR(name, label) {RowColor, name, label, nullptr, nullptr, 0., 0., nullptr, false}
#define COLORS {RowAllColors, nullptr, nullptr, nullptr, nullptr, 0., 0., nullptr, false}
#define ACTION(id, label) {RowAction, id, label, nullptr, nullptr, 0., 0., nullptr, false}
// a button one is meant to think twice about, drawn as the warning it is
#define ACTION_ALERT(id, label) \
  {RowAction, id, label, nullptr, nullptr, 2., 0., nullptr, false}
// the disc one drags to give a direction, at the right end of the line above
#define SPHERE(names) \
  {RowSphere, nullptr, nullptr, names, nullptr, 0., 0., nullptr, false}
#define ROW(label, names) {RowRow, nullptr, label, names, nullptr, 0., 0., nullptr, false}
#define VEC2(name, label) {RowRow, name, label, nullptr, nullptr, 2., 0., nullptr, false}
#define VEC3(name, label) {RowRow, name, label, nullptr, nullptr, 3., 0., nullptr, false}
#define VEC2S(name, label) {RowRow, name, label, nullptr, nullptr, 2., 1., nullptr, false}
#define VEC3S(name, label) {RowRow, name, label, nullptr, nullptr, 3., 1., nullptr, false}
#define MULTI(label, names) {RowMulti, nullptr, label, names, nullptr, 0., 0., nullptr, false}
#define CHECKFN(label, fn) {RowFunction, nullptr, label, nullptr, nullptr, 0., 0., fn, false}
#define CAPTION(text) {RowCaption, nullptr, text, nullptr, nullptr, 0., 0., nullptr, false}
// one with a rule over it: what follows it is a group of its own
#define SECTION(text) \
  {RowCaption, nullptr, text, nullptr, nullptr, 1., 0., nullptr, false}
// a button packed against what follows it, taking that share of a field's
// width: the little "-" and "+" of a stepper, and the "Min" and "Max" of a
// range, are drawn against their value there
#define ACTION_PACK(id, label, share) \
  {RowAction, id, label, nullptr, nullptr, 4., 0., nullptr, false, share}
// and the same, following the field before it on the line
#define ACTION_PACK_AFTER(id, label, share) \
  {RowAction, id, label, nullptr, nullptr, 4., 0., nullptr, true, share}
// a line of text beside the field before it, for a stepper whose label cannot
// sit on any one of its three pieces
#define LABEL_AFTER(text) \
  {RowCaption, nullptr, text, nullptr, nullptr, 2., 0., nullptr, false}
// and one that starts a column of its own, to head it
#define LABEL_COLUMN(text) \
  {RowCaption, nullptr, text, nullptr, nullptr, 3., 0., nullptr, false}
// a value, a word or a choice at the right end of the line above it
#define NUMBER_RIGHT(name, label, share) \
  {RowNumber, name, label, nullptr, nullptr, 2., 0., nullptr, true, share}
#define STRING_RIGHT(name, label, share) \
  {RowString, name, label, nullptr, nullptr, 2., 0., nullptr, true, share}
// the colour map of a view, filling its tab
#define COLORMAP \
  {RowColorMap, nullptr, nullptr, nullptr, nullptr, 0., 0., nullptr, false}
// a choice of which view a value is taken from: itself, or another
#define VIEWLIST(name, label) \
  {RowViewList, name, label, nullptr, nullptr, 0., 0., nullptr, false}
// a choice at the right end of the line above it, numbered from zero
#define COMBO_RIGHT(name, choices, share) \
  {RowCombo, name, "", choices, nullptr, 2., 1., nullptr, true, share}
#define COMBOL_RIGHT(name, choices, values, share) \
  {RowCombo, name, "", choices, values, 2., 1., nullptr, true, share}
// a button at the right end of the line above it
#define ACTION_RIGHT(id, label) \
  {RowAction, id, label, nullptr, nullptr, 1., 0., nullptr, false}
// one as wide as a field, which is how the window this reproduces draws the
// button that fits the axes to what is visible: it lines up with the values
// above it rather than being as wide as its own text
#define ACTION_OF(id, label, share) \
  {RowAction, id, label, nullptr, nullptr, 0., 0., nullptr, false, share}
// and one that starts the second column of that line rather than ending it,
// which is where the window this reproduces puts the two that pick something
#define ACTION_COLUMN(id, label) \
  {RowAction, id, label, nullptr, nullptr, 3., 0., nullptr, false}
// and a switch sharing that line
#define CHECK_RIGHT(name, label) \
  {RowCheck, name, label, nullptr, nullptr, 1., 0., nullptr, false}
// a row of values beside the field before them rather than on a line of their
// own: the nine components of a field follow the choice that maps them
#define ROW_BESIDE(names, share) \
  {RowRow, nullptr, "", names, nullptr, 0., 0., nullptr, true, share}
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
#define NUMBER_OF(name, label, share) \
  {RowNumber, name, label, nullptr, nullptr, 0., 0., nullptr, false, share}
// one that follows the field before it on the same line, inside its column
#define NUMBER_AFTER(name, label, share) \
  {RowNumber, name, label, nullptr, nullptr, 1., 0., nullptr, true, share}
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
  // what a geometrical entity can be labelled with, which is not what a mesh
  // entity can be labelled with
  const char *const _c_geoLabelType[] = {"Description", "Elementary tag", "Physical tag(s)", "Elementary name", "Physical name(s)", "Coordinates",  nullptr};
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
  // the scale of a view is one, two or three, not zero, one or two
  const double _v_scaleType[] = {1., 2., 3.};
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
  // a line of the matrix the main window is transformed by, the offset that
  // goes with it standing apart from the three, as that window has them
  const char *const _r_geoTransformX[] = {"TransformXX", "TransformXY", "TransformXZ",  nullptr};
  const char *const _r_geoTransformY[] = {"TransformYX", "TransformYY", "TransformYZ",  nullptr};
  const char *const _r_geoTransformZ[] = {"TransformZX", "TransformZY", "TransformZZ",  nullptr};
  const char *const _r_meshSize[] = {"MeshSizeMin", "MeshSizeMax", nullptr};
  const char *const _r_quality[] = {"QualityInf", "QualitySup", nullptr};
  const char *const _r_radiusInf[] = {"RadiusInf", "RadiusSup",  nullptr};
  const char *const _r_viewSize[] = {"Width", "Height", nullptr};
  // which component of a field goes where, nine boxes beside the choice that
  // says how many there are
  const char *const _r_componentMap[] = {
    "ComponentMap0", "ComponentMap1", "ComponentMap2", "ComponentMap3",
    "ComponentMap4", "ComponentMap5", "ComponentMap6", "ComponentMap7",
    "ComponentMap8", nullptr};
  const char *const _r_arrowSizeMin[] = {"ArrowSizeMin", "ArrowSizeMax",  nullptr};

  const optionRow _generalGeneral[] = {
    CHECK("FltkColorScheme", "Use dark interface"),
    CHECK("Tooltips", "Show tooltips"),
    CHECK("DrawBoundingBoxes", "Show bounding boxes"),
    CHECK_SHOWS("FastRedraw", "Draw simplified model during user interaction"),
    CHECK("MouseHoverMeshes", "Enable mouse hover over meshes and views"),
    CHECK("DoubleBuffer", "Enable double buffering"),
    CHECK("Antialiasing", "Enable antialiasing"),
    CHECK("Trackball", "Use trackball rotation instead of Euler angles"),
    CHECK("RotationCenterGravity", "Rotate around pseudo center of mass"),
    ROW("Rotation center", _r_rotationCenterX),
    ACTION_COLUMN("rotation_center_select", "Select"),
    CHECK("MouseInvertZoom", "Invert mouse wheel zoom direction"),
    END};

  const optionRow _generalAdvanced[] = {
    CHECK("Terminal", "Print messages on terminal"),
    NUMBER("Verbosity", "Message verbosity"),
    STRING("TextEditor", "Text editor command"),
    STRING("DefaultFileName", "Default file name"),
    CHECK("ConfirmOverwrite", "Ask confirmation before overwriting files"),
    CHECK("SaveSession", "Save session information on exit"),
    ACTION_RIGHT("show_session_file", "Show file path"),
    CHECK("SaveOptions", "Save options on exit"),
    ACTION_RIGHT("show_options_file", "Show file path"),
    CHECK("ExpertMode", "Enable expert mode"),
    NUMBER("NumThreads", "Maximum number of threads"),
    CHECKFN("Enable heavy visualization capabilities",
            opt_general_heavy_visualization),
    ACTION_ALERT("restoreDefaults", "Restore all options to default settings"),
    END};

  const optionRow _generalAxes[] = {
    COMBO("Axes", "Axes mode", _c_axes),
    CHECK_RIGHT("AxesMikado", "Mikado style"),
    ROW("Axes tics", _r_axesTicsX),
    VEC3S("AxesFormat", "Axes format"),
    VEC3S("AxesLabel", "Axes labels"),
    CHECK("AxesAutoPosition", "Set position and size of axes automatically"),
    ROW("Axes minimum", _r_axesMinX),
    ROW("Axes maximum", _r_axesMaxX),
    ACTION_OF("axes_fit", "Fit to visible", 1.),
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
    NUMBER("LineWidth", "Line width"),
    COMBOV("VectorType", "Vector display", _c_vectorType, 1., 1.),
    ACTION_COLUMN("arrow_edit", "Edit arrow"),
    STRCOMBO("GraphicsFontEngine", "Font rendering engine", _c_graphicsFontEngine),
    STRCOMBO_OF("GraphicsFont", "", _c_graphicsFont, 4. / 5.),
    NUMBER_AFTER("GraphicsFontSize", "Default font", 1. / 5.),
    STRCOMBO_OF("GraphicsFontTitle", "", _c_graphicsFont, 4. / 5.),
    NUMBER_AFTER("GraphicsFontSizeTitle", "Title font", 1. / 5.),
    END};

  const optionRow _generalColor[] = {
    ROW("Light position", _r_light0X),
    SPHERE(_r_light0X),
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
    ACTION("gamepad_configure", "Configure Gamepad"),
    END};

  const optionRow _geometryGeneral[] = {
    NUMBER("Tolerance", "Geometry tolerance"),
    CHECK("AutoCoherence", "Remove duplicate entities in GEO model transforms"),
    SECTION("Open CASCADE model healing options:"),
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
    COMBO("LabelType", "Label type", _c_geoLabelType),
    ROW("Normals and tangents", _r_normals),
    END};

  const optionRow _geometryTransfo[] = {
    COMBO("Transform", "Main window transform", _c_transform),
    ROW_OF(" X", _r_geoTransformX, .75),
    NUMBER_BESIDE_OF("OffsetX", "", .7),
    ROW_OF(" Y +", _r_geoTransformY, .75),
    NUMBER_BESIDE_OF("OffsetY", "", .7),
    ROW_OF(" Z", _r_geoTransformZ, .75),
    NUMBER_BESIDE_OF("OffsetZ", "", .7),
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
    NUMBER_OF("ElementOrder", "Element order", 1. / 3.),
    CHECK_BESIDE("SecondOrderIncomplete", "Use incomplete elements"),
    END};

  const optionRow _meshAdvanced[] = {
    CHECK("MeshSizeFromPoints", "Compute element sizes using point values"),
    CHECK("MeshSizeFromParametricPoints", "Compute element sizes using parametric point values"),
    // a third of a field: it holds a count of elements, and the half the
    // window this reproduces gives it reads wider than it needs to
    NUMBER_OF("MeshSizeFromCurvature", "Compute element sizes from curvature",
              1. / 3.),
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
    // the step one is looking at, between the two buttons that walk it
    ACTION_PACK("view_timestep_down", "-", .15),
    NUMBER_AFTER("TimeStep", "", .7),
    ACTION_PACK_AFTER("view_timestep_up", "+", .15),
    LABEL_AFTER("Step"),
    NUMBER("NbIso", "Intervals"),
    STRING_RIGHT("Format", "Format", .425),
    COMBOV("IntervalsType", "Intervals type", _c_intervalsType, 1., 1.),
    COMBOL_RIGHT("ScaleType", _c_scaleType, _v_scaleType, .85),
    COMBOV("RangeType", "Range mode", _c_rangeType, 1., 1.),
    CHECK_RIGHT("SaturateValues", "Saturate"),
    ACTION_PACK("view_range_min", "Min", .25),
    NUMBER_AFTER("CustomMin", "Custom min", .75),
    ACTION_PACK("view_range_max", "Max", .25),
    NUMBER_AFTER("CustomMax", "Custom max", .75),
    CHECK("AdaptVisualizationGrid", "Adapt visualization grid"),
    ACTION_PACK("view_recursion_down", "-", .15),
    NUMBER_AFTER("MaxRecursionLevel", "", .7),
    ACTION_PACK_AFTER("view_recursion_up", "+", .15),
    LABEL_AFTER("Maximum recursion level"),
    NUMBER("TargetError", "Target visualization error"),
    END};

  const optionRow _viewAxes[] = {
    COMBO("Axes", "Axes mode", _c_axes),
    CHECK_RIGHT("AxesMikado", "Mikado style"),
    ROW("Axes tics", _r_axesTicsX),
    VEC3S("AxesFormat", "Axes format"),
    VEC3S("AxesLabel", "Axes labels"),
    CHECK("AxesAutoPosition", "Position 3D axes automatically"),
    ROW("3D axes minimum", _r_axesMinX),
    ROW("3D axes maximum", _r_axesMaxX),
    COMBO("AutoPosition", "2D axes/value scale position", _c_autoPosition),
    ROW("2D axes/value scale position", _r_viewPosition),
    ROW("2D axes/value scale size", _r_viewSize),
    END};

  const optionRow _viewVisibility[] = {
    CHECK("ShowScale", "Show value scale"),
    COMBO("ShowTime", "Time display", _c_showTime),
    CHECK("DrawStrings", "Show annotations"),
    CHECK("ShowElement", "Draw element outlines"),
    CHECK("DrawSkinOnly", "Draw only skin of 3D views"),
    MULTI("Elements", _m_viewElements),
    NUMBER_BESIDE_OF("Sampling", "Sampling", 1. / 4.),
    COMBO("Boundary", "Element boundary mode", _c_boundary),
    ROW("Normals and tangents", _r_normals),
    MULTI("Fields", _m_viewFields),
    COMBO("ForceNumComponents", "", _c_forceNumComponents),
    ROW_BESIDE(_r_componentMap, 1.2),
    END};

  // Three rows of a matrix, each followed by an offset and a raise, under two
  // captions -- the one tab of the window this reproduces that is three
  // columns wide rather than two.
  const char *const _r_transformX[] = {"TransformXX", "TransformXY", "TransformXZ",  nullptr};
  const char *const _r_transformY[] = {"TransformYX", "TransformYY", "TransformYZ",  nullptr};
  const char *const _r_transformZ[] = {"TransformZX", "TransformZY", "TransformZZ",  nullptr};

  const optionRow _viewTransfo[] = {
    CAPTION("Coordinate transformation:"),
    LABEL_COLUMN(""),
    LABEL_COLUMN("Raise:"),
    ROW_OF(" X", _r_transformX, .75),
    NUMBER_BESIDE_OF("OffsetX", "", .7),
    NUMBER_BESIDE_OF("RaiseX", "", .7),
    ROW_OF(" Y +", _r_transformY, .75),
    NUMBER_BESIDE_OF("OffsetY", "", .7),
    NUMBER_BESIDE_OF("RaiseY", "", .7),
    ROW_OF(" Z", _r_transformZ, .75),
    NUMBER_BESIDE_OF("OffsetZ", "", .7),
    NUMBER_BESIDE_OF("RaiseZ", "", .7),
    NUMBER_OF("NormalRaise", "Normal raise", .75),
    CHECK("UseGeneralizedRaise", "Use general transformation expressions"),
    VIEWLIST("GeneralizedRaiseView", "Data source"),
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
    CHECK_RIGHT("Stipple", "Stipple"),
    NUMBER("LineWidth", "Line width"),
    COMBOV("VectorType", "Vector display", _c_viewVectorType, 1., 1.),
    ROW("Arrow size", _r_arrowSizeMin),
    NUMBER("DisplacementFactor", "Displacement factor"),
    VIEWLIST("ExternalView", "Data source for vector fields"),
    COMBOV("GlyphLocation", "Glyph location", _c_glyphLocation, 1., 1.),
    COMBO_RIGHT("CenterGlyphs", _c_centerGlyphs, .85),
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
    COLORMAP,
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
    // whether a view has more than one step, which is what decides whether one
    // can be stepped through
    bool _viewHasSteps(int num)
    {
#if defined(HAVE_POST)
      if(num >= 0 && num < (int)PView::list.size())
        return PView::list[num]->getData()->getNumTimeSteps() > 1;
#else
      (void)num;
#endif
      return false;
    }

    struct enableRule {
      const char *category;
      const char *name;
      const char *when; // the option it depends on
      bool whenOff; // the field is live when that option is off, not on
      // or its accessor, for the few that have no entry in the option table
      double (*fn)(int, int, double);
      // The values that option may have, for the few that are not switches:
      // the custom range of a view is live when its range mode is Custom, and
      // not when it is Default or Per step, and its two-dimensional axes are
      // live at two of the thirteen positions. Empty asks for on or off.
      const char *is;
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
      // custom_range: Default, Custom, Per step -- and Custom is the second
      {"View", "CustomMin", "RangeType", false, nullptr, "2"},
      {"View", "CustomMax", "RangeType", false, nullptr, "2"},
      {"View", "view_range_min", "RangeType", false, nullptr, "2"},
      {"View", "view_range_max", "RangeType", false, nullptr, "2"},
      {"View", "SaturateValues", "RangeType", false, nullptr, "2"},
      // view_axes
      {"View", "AxesTics*", "Axes", false},
      {"View", "AxesFormat*", "Axes", false},
      {"View", "AxesLabel*", "Axes", false},
      // view_axes_auto_3d
      {"View", "AxesMin*", "AxesAutoPosition", true},
      {"View", "AxesMax*", "AxesAutoPosition", true},
      // view_axes_auto_2d: manual, or in the coordinates of the model
      {"View", "PositionX", "AutoPosition", false, nullptr, "0 12"},
      {"View", "PositionY", "AutoPosition", false, nullptr, "0 12"},
      {"View", "Width", "AutoPosition", false, nullptr, "0 12"},
      {"View", "Height", "AutoPosition", false, nullptr, "0 12"},

      // view_adaptive
      {"View", "MaxRecursionLevel", "AdaptVisualizationGrid", false},
      {"View", "TargetError", "AdaptVisualizationGrid", false},
      {"View", "view_recursion_down", "AdaptVisualizationGrid", false},
      {"View", "view_recursion_up", "AdaptVisualizationGrid", false},
      // view_general_transform
      {"View", "GeneralizedRaise*", "UseGeneralizedRaise", false},
      // general_camera
      {"General", "CameraEyeSeparationRatio", "Stereo", false},
      {"General", "CameraFocalLengthRatio", "Camera", false},
      {"General", "CameraAperture", "Camera", false},
      {"General", "gamepad_configure", nullptr, false,
       opt_general_gamepad},
      {nullptr, nullptr, nullptr, false, nullptr}};

    // What each value may be dragged by, taken from the window this
    // reproduces: a step there means the value can be slid with the mouse, and
    // it is also what decides how many decimals it shows.
    struct stepRule {
      const char *category;
      const char *name;
      double step;
    };

    const stepRule _steps[] = {
      {"General", "AxesTicsX", 1.},
      {"General", "AxesTicsY", 1.},
      {"General", "AxesTicsZ", 1.},
      {"General", "CameraAperture", 1.},
      {"General", "CameraEyeSeparationRatio", .1},
      {"General", "CameraFocalLengthRatio", .1},
      {"General", "ClipFactor", 0.1},
      {"General", "GraphicsFontSize", 1.},
      {"General", "GraphicsFontSizeTitle", 1.},
      {"General", "Light0W", 0.01},
      {"General", "Light0X", 0.01},
      {"General", "Light0Y", 0.01},
      {"General", "Light0Z", 0.01},
      {"General", "NumThreads", 1.},
      {"General", "PointSize", 0.1},
      // the tooltips of that window name the wrong widget here, so these three
      // come from what its callbacks write rather than from what they say
      {"General", "LineWidth", 0.1},
      {"View", "Width", 0.5},
      {"View", "Height", 0.5},
      {"General", "PolygonOffsetFactor", 0.01},
      {"General", "PolygonOffsetUnits", 0.01},
      {"General", "QuadricSubdivisions", 1.},
      {"General", "Shininess", 0.1},
      {"General", "ShininessExponent", 1.},
      {"General", "SmallAxesPositionX", 1.},
      {"General", "SmallAxesPositionY", 1.},
      {"General", "Verbosity", 1.},
      {"Geometry", "CurveSelectWidth", 0.1},
      {"Geometry", "CurveWidth", 0.1},
      {"Geometry", "Normals", 1.},
      {"Geometry", "NumSubEdges", 1.},
      {"Geometry", "PointSelectSize", 0.1},
      {"Geometry", "PointSize", 0.1},
      {"Geometry", "Tangents", 1.},
      {"Mesh", "AngleSmoothNormals", 1.},
      {"Mesh", "ElementOrder", 1.},
      {"Mesh", "Explode", 0.01},
      {"Mesh", "LabelSampling", 1.},
      {"Mesh", "LineWidth", 0.1},
      {"Mesh", "MeshSizeFactor", 0.01},
      {"Mesh", "MeshSizeFromCurvature", 1.},
      {"Mesh", "Normals", 1.},
      {"Mesh", "NumSubEdges", 1.},
      {"Mesh", "PointSize", 0.1},
      {"Mesh", "QualityInf", 0.01},
      {"Mesh", "QualitySup", 0.01},
      {"Mesh", "Smoothing", 1.},
      {"Mesh", "Tangents", 1.0},
      {"PostProcessing", "AnimationDelay", 0.01},
      {"PostProcessing", "AnimationStep", 1.},
      {"View", "AngleSmoothNormals", 1.},
      {"View", "ArrowSizeMax", 1.},
      {"View", "ArrowSizeMin", 1.},
      {"View", "AxesTicsX", 1.},
      {"View", "AxesTicsY", 1.},
      {"View", "AxesTicsZ", 1.},
      {"View", "DisplacementFactor", 0.01},
      {"View", "Explode", 0.01},
      {"View", "LineWidth", 0.1},
      {"View", "MaxRecursionLevel", 1.},
      {"View", "NbIso", 1.},
      {"View", "Normals", 1.},
      {"View", "PointSize", 0.1},
      {"View", "PositionX", 0.5},
      {"View", "PositionY", 0.5},
      {"View", "Sampling", 1.},
      {"View", "Tangents", 1.},
      {"View", "TargetError", 1.e-4},
      {"View", "TimeStep", 1.},
      {nullptr, nullptr, 0.}};

    // what it may be dragged by, if anything
    double _stepOf(const char *category, const char *name)
    {
      if(!name) return 0.;
      for(int i = 0; _steps[i].category; i++)
        if(!strcmp(_steps[i].category, category) &&
           !strcmp(_steps[i].name, name))
          return _steps[i].step;
      return 0.;
    }

    // what makes this field live, if anything does
    std::function<bool()> _enabledBy(const char *category, const char *name,
                                     int num)
    {
      if(!name) return nullptr;
      // The step of a view can be walked only when it has more than one, and
      // no option says how many it has -- the view itself does.
      if(!strcmp(category, "View") &&
         (!strcmp(name, "TimeStep") || !strncmp(name, "view_timestep_", 14)))
        return [num]() { return _viewHasSteps(num); };
      for(int i = 0; _rules[i].category; i++) {
        const enableRule &r = _rules[i];
        if(strcmp(r.category, category)) continue;
        std::string want = r.name;
        if(r.fn) {
          double (*fn)(int, int, double) = r.fn;
          bool off = r.whenOff;
          if(strcmp(name, r.name)) continue;
          return [fn, off]() {
            double v = fn(0, GMSH_GET, 0.);
            return off ? (v == 0.) : (v != 0.);
          };
        }
        bool matches = (want.back() == '*') ?
                         !strncmp(name, want.c_str(), want.size() - 1) :
                         !strcmp(name, want.c_str());
        // the option a rule depends on is never greyed by that rule, however
        // its name reads: it is what decides
        if(r.when && !strcmp(name, r.when)) continue;
        if(!matches) continue;
        std::string cat = category, on = r.when;
        bool off = r.whenOff;
        std::string is = r.is ? r.is : "";
        return [cat, on, off, is, num]() {
          double v = 0.;
          NumberOption(GMSH_GET, cat.c_str(), num, on.c_str(), v, false);
          if(is.size()) {
            for(std::size_t at = 0; at < is.size();) {
              std::size_t end = is.find(' ', at);
              if(v == atof(is.substr(at, end - at).c_str())) return true;
              if(end == std::string::npos) break;
              at = end + 1;
            }
            return false;
          }
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
      f.storeCategory = category;
      f.storeName = name;
      f.storeIndex = num;
      f.label = label;
      f.tooltip = _tooltipFor(category, name);
      f.changed = _redraw;
      f.enabled = _enabledBy(category, name, num);
      f.step = _stepOf(category, name);

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
        // packed against one another, but the first of a row that follows
        // another field starts a column of its own rather than being packed
        // against what is there
        f.packed = (k > 0) || !row.beside;
        if(k || row.beside) f.sameRow = true;
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
      // The window this reproduces places its widgets on columns, the same
      // for every row of a tab: two of them, and three where a view has its
      // transformation matrix, its offsets and its raises side by side.
      pane.columns = 3;
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
          if(row.share > 0.) f.widthShare = row.share;
          if(row.vmin == 2.) f.alert = true;
          if(row.vmin == 3.) f.sameRow = true; // the next column of that line
          if(row.vmin == 4.) { // packed against what it belongs to
            f.packed = true;
            f.sameRow = row.beside;
          }
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
        case RowSphere: {
          // The one widget of the window this reproduces that is not a field:
          // a disc one drags to say where the light comes from. It writes the
          // same three options the row above it holds, and sits at the right
          // end of that row, hanging over the line under it.
          std::vector<std::string> names;
          for(int k = 0; row.choices && row.choices[k]; k++)
            names.push_back(row.choices[k]);
          std::string cat = category;
          Field f;
          f.kind = Direction;
          f.rows = 2;
          f.readVector = [cat, names, num](double &x, double &y, double &z) {
            double v[3] = {0., 0., 0.};
            for(std::size_t k = 0; k < names.size() && k < 3; k++)
              NumberOption(GMSH_GET, cat.c_str(), num, names[k].c_str(), v[k],
                           false);
            x = v[0];
            y = v[1];
            z = v[2];
          };
          f.writeVector = [cat, names, num](double x, double y, double z) {
            double v[3] = {x, y, z};
            for(std::size_t k = 0; k < names.size() && k < 3; k++)
              NumberOption(GMSH_SET | GMSH_GUI, cat.c_str(), num,
                           names[k].c_str(), v[k], false);
          };
          f.changed = _redraw;
          f.enabled = _enabledBy(category, names.size() ? names[0].c_str() : "",
                                 num);
          Field gap;
          gap.kind = Spacer;
          gap.widthEm = 1.;
          gap.sameRow = true;
          pane.fields.push_back(gap);
          f.sameRow = true;
          f.packed = true;
          pane.fields.push_back(f);
        } break;
        case RowColorMap: {
          // the map itself, filling the tab, as the window this reproduces
          // gives it the whole of one
          Field f;
          f.kind = ColorMap;
          f.rows = 0;
          int index = num;
          // The interfaces are given what to read and what to write, and
          // never the table: GmshColorTable is a Gmsh type, and handing it
          // over is how a widget toolkit starts calling ColorTable_Recompute()
          // for itself, which is what src/gui exists to prevent.
          f.map = _colourMapOf(index);
          f.changed = [index]() {
#if defined(HAVE_POST)
            if(index >= 0 && index < (int)PView::list.size())
              PView::list[index]->setChanged(true);
#endif
            drawContext::global()->draw();
          };
          pane.fields.push_back(f);
        } break;
        case RowViewList: {
          // "Self", then a line per view: which view a vector field or a
          // raise takes its values from. The list is not fixed, and the
          // value is the index of the view, or -1 for itself.
          Field f = _fieldFor(RowNumber, category, row.name,
                              row.label ? row.label : row.name, num, nullptr);
          f.kind = Choice;
          f.dynamicChoices = [](std::vector<std::string> &labels,
                                std::vector<int> &values) {
            labels.push_back("Self");
            values.push_back(-1);
#if defined(HAVE_POST)
            for(std::size_t i = 0; i < PView::list.size(); i++) {
              labels.push_back("View [" + std::to_string(i) + "]");
              values.push_back((int)i);
            }
#endif
          };
          pane.fields.push_back(f);
        } break;
        case RowCaption: {
          Field f;
          f.kind = Label;
          std::string text = row.label;
          f.readText = [text]() { return text; };
          if(row.vmin == 1.) f.rule = true;
          if(row.vmin == 3.) f.sameRow = true; // heading the next column
          if(row.vmin == 2.) {
            // beside the field before it, against it, and as live as it is:
            // it is that field's label, kept apart only because the field is
            // three pieces and the label belongs to none of them
            f.sameRow = true;
            f.packed = true;
            if(!pane.fields.empty()) f.enabled = pane.fields.back().enabled;
          }
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
#if !defined(HAVE_VISUDEV)
          // the heavy visualization is not in this build, as the window this
          // reproduces also says by greying it
          if(row.fn == opt_general_heavy_visualization)
            f.enabled = []() { return false; };
#endif
          pane.fields.push_back(f);
        } break;
        default: {
          Field f = _fieldFor(row.kind, category, row.name,
                              row.label ? row.label : row.name, num, &row);
          if(row.share > 0.) f.widthShare = row.share;
          // a choice sharing a field's width with the value after it stands
          // against it, so that the two together measure one field
          if(row.kind == RowStringCombo && row.vmin == 1.) f.packed = true;
          // what it decides is not only a value but what the window holds
          if(row.kind == RowCheck && row.vmin == 2.)
            f.changed = []() {
              drawContext::global()->draw();
              show(Options, -1);
            };
          if(row.beside) {
            f.sameRow = true;
            // vmin says it follows inside the same column rather than
            // starting the next one
            if(row.vmin == 1.) f.packed = true;
            // or that it is set apart at the right end of the line
            if(row.vmin == 2.) {
              Field gap;
              gap.kind = Spacer;
              gap.widthEm = 1.;
              gap.sameRow = true;
              pane.fields.push_back(gap);
              f.packed = true;
            }
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

  void showOptionsForView(int view, const std::string &pane)
  {
    if(view < 0) view = _state().view;
    if(view < 0 || view >= _views()) view = 0;
    if(_views()) _state().category = _numCategories + view;
    // the tab it is to open on, when the caller has one in mind: the colour
    // map of a view is a tab of this window, not a window of its own
    int which = -1;
    for(int i = 0; pane.size() && _viewTabs[i].label; i++)
      if(pane == _viewTabs[i].label) which = i;
    show(Options, which);
  }

  Form options()
  {
    Form p;
    p.tabbed = true;
    // An option can be changed from anywhere -- a shortcut, the tree, a
    // script -- and the window shows it. The window this reproduces had every
    // option accessor push its value into the right widget; here the fields
    // read the options they name, so all that is wanted is an excuse to read
    // them again. Dear ImGui reads them every frame and needs none.
    p.refreshEvery = .25;
    // The same height whatever category it is showing, as the window this
    // reproduces has: it is built once there, twelve lines tall, of which the
    // row of tabs is one -- and one that grew and shrank as one went down the
    // list would not sit still.
    p.leastRows = 11;

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
    p.side.back().rows = 0; // as tall as the window

    // the View options are those of the view whose line is picked
    int num = (_state().category >= _numCategories) ? _state().view : 0;

    const optionTab *tabs = _tabsForCategory(category);
    for(int i = 0; tabs && tabs[i].label; i++)
      p.panes.push_back(_paneFor(tabs[i], category, num));

    // Redraw sits under the list of categories, and only when the model drawn
    // while one interacts is a simplified one: there is nothing to redraw
    // otherwise, and the window this reproduces leaves it out then.
    // Restoring the defaults is not a button of the window at all -- it is the
    // last row of the general options, where that window keeps it.
    Field again;
    again.kind = Action;
    again.label = "Redraw";
    again.changed = _redraw;
    again.visible = []() {
      double v = 0.;
      NumberOption(GMSH_GET, "General", 0, "FastRedraw", v, false);
      return v != 0.;
    };
    p.side.push_back(again);
    return p;
  }

} // namespace Dialog
