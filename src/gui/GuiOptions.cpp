// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The option window. What an option looks like -- a switch, an enumeration
// and what its values mean, which options share a line, its human name --
// cannot be read off the option tables of DefaultOptions.h: the panels are
// laid out by hand in the tables below, and only the mechanism is generic.
// The help string of the tooltip does come from the option table.

#include "GmshConfig.h"

#include <cstring>
#include <string>
#include <vector>

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
      return Ui::Colour(
        (unsigned char)x->unpackRed(c), (unsigned char)x->unpackGreen(c),
        (unsigned char)x->unpackBlue(c), (unsigned char)x->unpackAlpha(c));
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
      add("Alpha", Ui::Shortcut('A', Ui::ModCommand), Ui::Shortcut('A'), 0., 1.,
          .05);
      add("Beta", Ui::Shortcut('B'), Ui::Shortcut('B', Ui::ModCommand), -1., 1.,
          .05);
      add("Alpha power", Ui::Shortcut('P'), Ui::Shortcut('P', Ui::ModCommand),
          0., 0., .05);
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

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    const char *const _c_axes[] = {
      "None", "Simple axes", "Box", "Full grid", "Open grid", "Ruler", nullptr};
    const char *const _c_orthographic[] = {"Orthographic", "Perspective",
                                           nullptr};
    const char *const _c_vectorType[] = {"Line", "Arrow", "Pyramid", "3D arrow",
                                         nullptr};
    const char *const _c_graphicsFontEngine[] = {"Native", "StringTexture",
                                                 "Embedded", nullptr};
    const char *const _c_graphicsFont[] = {"Times-Roman",
                                           "Times-Bold",
                                           "Times-Italic",
                                           "Times-BoldItalic",
                                           "Helvetica",
                                           "Helvetica-Bold",
                                           "Helvetica-Oblique",
                                           "Helvetica-BoldOblique",
                                           "Courier",
                                           "Courier-Bold",
                                           "Courier-Oblique",
                                           "Courier-BoldOblique",
                                           "Symbol",
                                           "Screen",
                                           nullptr};
    const char *const _c_colorScheme[] = {"Light", "Default", "Grayscale",
                                          "Dark", nullptr};
    const char *const _c_backgroundGradient[] = {
      "None", "Vertical", "Horizontal", "Radial", nullptr};
    const char *const _c_labelType[] = {
      "Node/element tag", "Elementary entity tag", "Physical group tag(s)",
      "Mesh partition",   "Coordinates",           nullptr};
    const char *const _c_geoLabelType[] = {"Description",
                                           "Elementary tag",
                                           "Physical tag(s)",
                                           "Elementary name",
                                           "Physical name(s)",
                                           "Coordinates",
                                           nullptr};
    const char *const _c_transform[] = {"None", "Scaling", nullptr};
    const char *const _c_pointType[] = {"Color dot", "3D sphere", nullptr};
    const char *const _c_curveType[] = {"Color segment", "3D cylinder",
                                        nullptr};
    const char *const _c_surfaceType[] = {"Cross", "Wireframe", "Solid",
                                          nullptr};
    const char *const _c_volumeType[] = {"Sphere", "Diamond", nullptr};
    const char *const _c_algorithm[] = {
      "Automatic",
      "MeshAdapt",
      "Delaunay",
      "Frontal-Delaunay",
      "BAMG (experimental)",
      "Frontal-Delaunay for Quads (experimental)",
      "Packing of parallelograms (experimental)",
      "Quasi-Structured Quad (experimental)",
      "Initial Mesh Only (no node insertion)",
      nullptr};
    const char *const _c_algorithm3D[] = {
      "Delaunay",
      "Frontal",
      "HXT (experimental)",
      "MMG3D (experimental, single volume only)",
      "Initial Mesh Only (no node insertion)",
      nullptr};
    const char *const _c_recombinationAlgorithm[] = {
      "Simple",
      "Blossom",
      "Simple Full-Quad",
      "Blossom Full-Quad",
      "Christos's bipartite labelling",
      nullptr};
    const char *const _c_subdivisionAlgorithm[] = {"None", "All Quads",
                                                   "All Hexas", nullptr};
    const char *const _c_qualityType[] = {"SICN", "SIGE", "Gamma", "Disto",
                                          nullptr};
    const char *const _c_lightLines[] = {"No", "Surface", "Volume and surface",
                                         nullptr};
    const char *const _c_colorCarousel[] = {
      "By element type", "By elementary entity", "By physical group",
      "By mesh partition", nullptr};
    const char *const _c_link[] = {"Apply next changes to selected views",
                                   "Force same options for selected views",
                                   nullptr};
    const char *const _c_type[] = {"3D", "2D space", "2D time", "2D", nullptr};
    const char *const _c_intervalsType[] = {"Iso-values", "Continuous map",
                                            "Filled iso-values",
                                            "Numeric values", nullptr};
    const char *const _c_scaleType[] = {"Linear", "Logarithmic",
                                        "Symmetric logarithmic", nullptr};
    const char *const _c_rangeType[] = {"Default", "Custom", "Per step",
                                        nullptr};
    const char *const _c_autoPosition[] = {"Manual",
                                           "Automatic",
                                           "Top left",
                                           "Top right",
                                           "Bottom left",
                                           "Bottom right",
                                           "Top",
                                           "Bottom",
                                           "Left",
                                           "Right",
                                           "Full",
                                           "Top third",
                                           "In model coordinates",
                                           nullptr};
    const char *const _c_showTime[] = {
      "None",      "Time series",     "Harmonic data",    "Automatic",
      "Step data", "Multi-step data", "Real eigenvalues", "Complex eigenvalues",
      nullptr};
    const char *const _c_boundary[] = {"None", "Dimension - 1", "Dimension - 2",
                                       "Dimension - 3", nullptr};
    const char *const _c_forceNumComponents[] = {"Original Field",
                                                 "Force Scalar", "Force Vector",
                                                 "Force Tensor", nullptr};
    const char *const _c_viewPointType[] = {
      "Color dot", "3D sphere", "Scaled dot", "Scaled sphere", nullptr};
    const char *const _c_lineType[] = {"Color segment", "3D cylinder",
                                       "Tapered cylinder", nullptr};
    const char *const _c_viewVectorType[] = {
      "Line", "Arrow", "Pyramid", "3D arrow", "Displacement", "Comet", nullptr};
    const char *const _c_glyphLocation[] = {"Barycenter", "Node", nullptr};
    const char *const _c_centerGlyphs[] = {"Left-aligned", "Centered",
                                           "Right-aligned", nullptr};
    const char *const _c_tensorType[] = {"Von-Mises",
                                         "Maximum eigenvalue",
                                         "Minimum eigenvalue",
                                         "Eigenvectors",
                                         "Ellipse",
                                         "Ellipsoid",
                                         "Frame (box)",
                                         "Frame (vectors)",
                                         nullptr};

    // the values an enumeration writes when they are not the indices of its
    // entries: Mesh.Algorithm is 2 for "Automatic" and 12 for the last entry
    const double _v_orthographic[] = {1., 0.};
    const double _v_scaleType[] = {1., 2., 3.};
    const double _v_algorithm[] = {2., 1., 5., 6., 7., 8., 9., 11., 3.};
    const double _v_algorithm3D[] = {1., 4., 10., 7., 3.};

    const char *const _m_meshElements[] = {
      "Triangles", "Quadrangles", "Tetrahedra", "Hexahedra", "Prisms",
      "Pyramids",  "Trihedra",    "Polygons",   "Polyhedra", nullptr};
    const char *const _m_viewElements[] = {
      "DrawPoints",     "DrawLines",     "DrawTriangles", "DrawQuadrangles",
      "DrawTetrahedra", "DrawHexahedra", "DrawPrisms",    "DrawPyramids",
      "DrawTrihedra",   "DrawPolygons",  "DrawPolyhedra", nullptr};
    const char *const _m_viewFields[] = {"DrawScalars", "DrawVectors",
                                         "DrawTensors", nullptr};
    const char *const _r_viewPosition[] = {"PositionX", "PositionY", nullptr};

    const char *const _r_rotationCenterX[] = {
      "RotationCenterX", "RotationCenterY", "RotationCenterZ", nullptr};
    const char *const _r_axesTicksX[] = {"AxesTicksX", "AxesTicksY",
                                         "AxesTicksZ", nullptr};
    const char *const _r_studio[] = {"StudioSamples", "StudioLightSpread",
                                     "StudioFloorOffset", nullptr};
    const char *const _c_shading[] = {"Classic", "Studio (X floor)",
                                      "Studio (Y floor)", "Studio (Z floor)",
                                      nullptr};
    const char *const _c_opacityMode[] = {"Surfaces", "Everything", nullptr};
    const char *const _c_meshSkin[] = {"Show interior faces",
                                       "Hide interior faces",
                                       "Hide partition faces", nullptr};
    const char *const _c_adaptSkin[] = {"Adapt everything", "Adapt skin only",
                                        "Skin w/o partitions", nullptr};
    const char *_c_colormap[64] = {nullptr};
    const char *const _r_axesFormatX[] = {"AxesFormatX", "AxesFormatY",
                                          "AxesFormatZ", nullptr};
    const char *const _r_axesLabelX[] = {"AxesLabelX", "AxesLabelY",
                                         "AxesLabelZ", nullptr};
    const char *const _r_axesMinX[] = {"AxesMinX", "AxesMinY", "AxesMinZ",
                                       nullptr};
    const char *const _r_axesMaxX[] = {"AxesMaxX", "AxesMaxY", "AxesMaxZ",
                                       nullptr};
    const char *const _r_smallAxesPositionX[] = {"SmallAxesPositionX",
                                                 "SmallAxesPositionY", nullptr};
    const char *const _r_polygonOffsetFactor[] = {
      "PolygonOffsetFactor", "PolygonOffsetUnits", nullptr};
    const char *const _r_light0X[] = {"Light0X", "Light0Y", "Light0Z", nullptr};
    const char *const _r_shininess[] = {"Shininess", "ShininessExponent",
                                        nullptr};
    const char *const _r_normals[] = {"Normals", "Tangents", nullptr};
    // a line of the transformation matrix: three coefficients and the offset
    const char *const _r_geoTransformX[] = {"TransformXX", "TransformXY",
                                            "TransformXZ", nullptr};
    const char *const _r_geoTransformY[] = {"TransformYX", "TransformYY",
                                            "TransformYZ", nullptr};
    const char *const _r_geoTransformZ[] = {"TransformZX", "TransformZY",
                                            "TransformZZ", nullptr};
    const char *const _r_meshSize[] = {"MeshSizeMin", "MeshSizeMax", nullptr};
    const char *const _r_quality[] = {"QualityInf", "QualitySup", nullptr};
    const char *const _r_radiusInf[] = {"RadiusInf", "RadiusSup", nullptr};
    const char *const _r_viewSize[] = {"Width", "Height", nullptr};
    const char *const _r_componentMap[] = {
      "ComponentMap0", "ComponentMap1", "ComponentMap2", "ComponentMap3",
      "ComponentMap4", "ComponentMap5", "ComponentMap6", "ComponentMap7",
      "ComponentMap8", nullptr};
    const char *const _r_arrowSizeMin[] = {"ArrowSizeMin", "ArrowSizeMax",
                                           nullptr};
    // the one tab three columns wide rather than two
    const char *const _r_transformX[] = {"TransformXX", "TransformXY",
                                         "TransformXZ", nullptr};
    const char *const _r_transformY[] = {"TransformYX", "TransformYY",
                                         "TransformYZ", nullptr};
    const char *const _r_transformZ[] = {"TransformZX", "TransformZY",
                                         "TransformZZ", nullptr};


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

    // five categories, then one line per view
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

    const char *_categoryName(int row)
    {
      if(row < 0) return _categories[0];
      return (row < _numCategories) ? _categories[row] : "View";
    }

    // the name and help string of the option table
    std::string _tooltipFor(const char *category, const char *name)
    {
      if(!name) return "";
      std::string tip = std::string(category) + "." + name;
      const char *help = nullptr;
      if(StringXNumber *n = _findNumber(category, name))
        help = n->help;
      else if(StringXString *t = _findString(category, name))
        help = t->help;
      else if(StringXColor *c = _findColor(category, name))
        help = c->help;
      if(help && help[0]) tip += "\n\n" + std::string(help);
      return tip;
    }

    void _redraw() { drawContext::global()->draw(); }

    // a field that only makes sense when another option is set is greyed
    // rather than hidden; a name ending in "*" stands for every option that
    // begins with it
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
      // or its accessor, for the few without an entry in the option table
      double (*fn)(int, int, double);
      // the values that option may have, for the few that are not switches
      const char *is;
    };

    const enableRule _rules[] = {
      {"General", "RotationCenter*", "RotationCenterGravity", true},
      {"General", "rotation_center_select", "RotationCenterGravity", true},
      {"General", "AxesTicks*", "Axes", false},
      // shader pipeline only
      {"General", "Shading", "Shaders", false},
      {"General", "Studio*", "Shaders", false},
      {"General", "Brightness", "Shaders", false},
      {"Geometry", "Opacity*", "Shaders", false},
      {"Mesh", "Opacity*", "Shaders", false},
      {"View", "Opacity", "Shaders", false},
      {"General", "Light0W", "Shading", false, nullptr, "0"},
      {"General", "AxesFormat*", "Axes", false},
      {"General", "AxesLabel*", "Axes", false},
      {"General", "AxesMin*", "AxesAutoPosition", true},
      {"General", "AxesMax*", "AxesAutoPosition", true},
      {"General", "axes_fit", "AxesAutoPosition", true},
      {"General", "SmallAxesPosition*", "SmallAxes", false},
      {"Geometry", "Transform*", "Transform", false},
      {"Geometry", "Offset*", "Transform", false},
      {"Mesh", "LightLines", "Light", false},
      {"Mesh", "LightTwoSide", "Light", false},
      {"Mesh", "SmoothNormals", "Light", false},
      {"View", "LightLines", "Light", false},
      {"View", "LightTwoSide", "Light", false},
      {"View", "SmoothNormals", "Light", false},
      // Default, Custom, Per step
      {"View", "CustomMin", "RangeType", false, nullptr, "2"},
      {"View", "CustomMax", "RangeType", false, nullptr, "2"},
      {"View", "view_range_min", "RangeType", false, nullptr, "2"},
      {"View", "view_range_max", "RangeType", false, nullptr, "2"},
      {"View", "SaturateValues", "RangeType", false, nullptr, "2"},
      {"View", "AxesTicks*", "Axes", false},
      {"View", "AxesFormat*", "Axes", false},
      {"View", "AxesLabel*", "Axes", false},
      {"View", "AxesMin*", "AxesAutoPosition", true},
      {"View", "AxesMax*", "AxesAutoPosition", true},
      // manual, or in the coordinates of the model
      {"View", "PositionX", "AutoPosition", false, nullptr, "0 12"},
      {"View", "PositionY", "AutoPosition", false, nullptr, "0 12"},
      {"View", "Width", "AutoPosition", false, nullptr, "0 12"},
      {"View", "Height", "AutoPosition", false, nullptr, "0 12"},

      {"View", "MaxRecursionLevel", "AdaptVisualizationGrid", false},
      {"View", "TargetError", "AdaptVisualizationGrid", false},
      {"View", "view_recursion_down", "AdaptVisualizationGrid", false},
      {"View", "view_recursion_up", "AdaptVisualizationGrid", false},
      {"View", "GeneralizedRaise*", "UseGeneralizedRaise", false},
      {"General", "CameraEyeSeparationRatio", "Stereo", false},
      {"General", "CameraFocalLengthRatio", "Camera", false},
      {"General", "CameraAperture", "Camera", false},
      {"General", "gamepad_configure", nullptr, false, opt_general_gamepad},
      {nullptr, nullptr, nullptr, false, nullptr}};

    // the step a value is slid by, which also sets how many decimals it shows
    struct stepRule {
      const char *category;
      const char *name;
      double step;
    };

    const stepRule _steps[] = {{"General", "AxesTicksX", 1.},
                               {"General", "AxesTicksY", 1.},
                               {"General", "AxesTicksZ", 1.},
                               {"General", "Brightness", .05},
                               {"General", "StudioSamples", 1.},
                               {"General", "StudioLightSpread", .1},
                               {"General", "StudioFloorOffset", .01},
                               {"Geometry", "Opacity", .01},
                               {"Mesh", "Opacity", .01},
                               {"View", "Opacity", .01},
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
                               {"View", "AxesTicksX", 1.},
                               {"View", "AxesTicksY", 1.},
                               {"View", "AxesTicksZ", 1.},
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

    double _stepOf(const char *category, const char *name)
    {
      if(!name) return 0.;
      for(int i = 0; _steps[i].category; i++)
        if(!strcmp(_steps[i].category, category) &&
           !strcmp(_steps[i].name, name))
          return _steps[i].step;
      return 0.;
    }

    std::function<bool()> _enabledBy(const char *category, const char *name,
                                     int num)
    {
      if(!name) return nullptr;
      // no option says how many steps a view has: the view itself does
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
        // the option a rule depends on is never greyed by that rule
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

    std::string _fullName(const char *category, const char *name, int num)
    {
      return std::string(category) +
             (num ? "[" + std::to_string(num) + "]" : "") + "." + name;
    }

    Field _fieldFor(Field f, const char *category, const char *name, int num)
    {
      return f.tip(_tooltipFor(category, name))
        .onChanged(_redraw)
        .enabledWhen(_enabledBy(category, name, num))
        .within(0., 0., _stepOf(category, name));
    }

    struct optionsOf {
      const char *category;
      int num;

      Field check(const char *name, const char *label) const
      {
        return _fieldFor(Declare::check(label, _fullName(category, name, num)),
                         category, name, num);
      }
      // a switch that decides whether another field is there at all: the window
      // is built again, not refreshed
      Field shows(const char *name, const char *label) const
      {
        return check(name, label).onChanged([]() {
          drawContext::global()->draw();
          Gui::instance().options.show();
        });
      }
      Field flag(const char *label, double (*fn)(int, int, double)) const
      {
        Field f = Declare::check(
          label, [fn]() { return fn(0, GMSH_GET, 0.) != 0.; },
          [fn](bool on) { fn(0, GMSH_SET | GMSH_GUI, on ? 1. : 0.); });
        f.changed = _redraw;
#if !defined(HAVE_VISUDEV)
        if(fn == opt_general_heavy_visualization)
          f.enabledWhen([]() { return false; });
#endif
        return f;
      }
      Field number(const char *name, const char *label) const
      {
        return _fieldFor(Declare::number(label, _fullName(category, name, num)),
                         category, name, num);
      }
      Field text(const char *name, const char *label) const
      {
        return _fieldFor(Declare::text(label, _fullName(category, name, num)),
                         category, name, num);
      }
      Field colour(const char *name, const char *label) const
      {
        return _fieldFor(Declare::colour(label, _fullName(category, name, num)),
                         category, name, num);
      }
      // the entries write first, first + step, ... or the values given
      Field combo(const char *name, const char *label,
                  const char *const *choices, double first = 0.,
                  double step = 1.) const
      {
        std::vector<std::pair<std::string, int>> pairs;
        for(int k = 0; choices && choices[k]; k++)
          pairs.push_back({choices[k], (int)(first + step * k)});
        return _fieldFor(choice(label, _fullName(category, name, num), pairs),
                         category, name, num);
      }
      Field combo(const char *name, const char *label,
                  const char *const *choices, const double *values) const
      {
        std::vector<std::pair<std::string, int>> pairs;
        for(int k = 0; choices && choices[k]; k++)
          pairs.push_back({choices[k], (int)values[k]});
        return _fieldFor(choice(label, _fullName(category, name, num), pairs),
                         category, name, num);
      }
      Field words(const char *name, const char *label,
                  const char *const *choices) const
      {
        std::vector<std::string> v;
        for(int k = 0; choices && choices[k]; k++) v.push_back(choices[k]);
        return _fieldFor(choice(label, _fullName(category, name, num), v),
                         category, name, num);
      }
      Field action(const char *id, const char *label) const
      {
        std::string what = id;
        return button(label, [what]() { optionsAction(what); })
          .enabledWhen(_enabledBy(category, id, num));
      }
      // several options on one line under one label, flush against one another;
      // an entry may carry a label of its own after a "|"
      Item row(const char *label, const std::vector<std::string> &names,
               double share = 1., bool strings = false) const
      {
        std::vector<Item> cells;
        for(std::size_t k = 0; k < names.size(); k++) {
          std::string name = names[k], said;
          std::size_t bar = name.find('|');
          if(bar != std::string::npos) {
            said = name.substr(bar + 1);
            name = name.substr(0, bar);
          }
          else if(k + 1 == names.size())
            said = label ? label : "";
          cells.push_back((strings ? text(name.c_str(), said.c_str()) :
                                     number(name.c_str(), said.c_str()))
                            .share(share / (double)names.size())
                            .tight());
        }
        return hbox(cells);
      }
      Item row(const char *label, const char *const *names,
               double share = 1.) const
      {
        std::vector<std::string> v;
        for(int k = 0; names && names[k]; k++) v.push_back(names[k]);
        return row(label, v, share);
      }
      Item vec(const char *name, const char *label, int n,
               bool strings = false) const
      {
        std::vector<std::string> v;
        for(int k = 0; k < n; k++)
          v.push_back(std::string(name) + (char)('X' + k));
        return row(label, v, 1., strings);
      }
      Field multi(const char *label, const char *const *names) const
      {
        std::vector<std::string> v;
        for(int k = 0; names && names[k]; k++) v.push_back(names[k]);
        std::string cat = category;
        int index = num;
        Field f;
        f.kind = Choice;
        f.label = label;
        f.multiple = true;
        f.dynamicChoices = [v](std::vector<std::string> &labels,
                               std::vector<int> &values) {
          for(std::size_t k = 0; k < v.size(); k++) {
            labels.push_back(v[k]);
            values.push_back((int)k);
          }
        };
        f.chosen = [v, cat, index](int i) {
          if(i < 0 || i >= (int)v.size()) return false;
          double on = 0.;
          NumberOption(GMSH_GET, cat.c_str(), index, v[i].c_str(), on, false);
          return on != 0.;
        };
        f.choose = [v, cat, index](int i, bool on) {
          if(i < 0 || i >= (int)v.size()) return;
          double value = on ? 1. : 0.;
          NumberOption(GMSH_SET | GMSH_GUI, cat.c_str(), index, v[i].c_str(),
                       value, false);
          drawContext::global()->draw();
        };
        f.changed = _redraw;
        return f;
      }
      // the disc writes the three options of the row above it and hangs over
      // the rows under it
      Field sphere(const char *const *names) const
      {
        std::vector<std::string> v;
        for(int k = 0; names && names[k]; k++) v.push_back(names[k]);
        std::string cat = category;
        int index = num;
        return direction(
                 [cat, v, index](double &x, double &y, double &z) {
                   double p[3] = {0., 0., 0.};
                   for(std::size_t k = 0; k < v.size() && k < 3; k++)
                     NumberOption(GMSH_GET, cat.c_str(), index, v[k].c_str(),
                                  p[k], false);
                   x = p[0];
                   y = p[1];
                   z = p[2];
                 },
                 [cat, v, index](double x, double y, double z) {
                   double p[3] = {x, y, z};
                   for(std::size_t k = 0; k < v.size() && k < 3; k++)
                     NumberOption(GMSH_SET | GMSH_GUI, cat.c_str(), index,
                                  v[k].c_str(), p[k], false);
                 })
          .onChanged(_redraw)
          .enabledWhen(_enabledBy(category, v.size() ? v[0].c_str() : "", num));
      }
      // "Self", then a line per view; the value is the index of the view, or -1
      // for itself
      Field views(const char *name, const char *label) const
      {
        return _fieldFor(choice(label, _fullName(category, name, num)),
                         category, name, num)
          .offering(
          [](std::vector<std::string> &labels, std::vector<int> &values) {
            labels.push_back("Self");
            values.push_back(-1);
#if defined(HAVE_POST)
            for(std::size_t i = 0; i < PView::list.size(); i++) {
              labels.push_back("View [" + std::to_string(i) + "]");
              values.push_back((int)i);
            }
#endif
          });
      }
      // the interfaces are given what to read and write, never the table, a
      // Gmsh type
      Field map() const
      {
        int index = num;
        Field f;
        f.kind = ColorMap;
        f.rows = 0;
        f.map = _colourMapOf(index);
        f.changed = [index]() {
#if defined(HAVE_POST)
          if(index >= 0 && index < (int)PView::list.size())
            PView::list[index]->setChanged(true);
#endif
          drawContext::global()->draw();
        };
        return f;
      }
      std::vector<Field> colours() const
      {
        std::vector<Field> out;
        StringXColor *o = GetColorOptionCategory(category);
        for(int k = 0; o && o[k].str; k++) {
          if(o[k].level & GMSH_DEPRECATED) continue;
          out.push_back(colour(o[k].str, o[k].str));
        }
        return out;
      }
      // a label after a field of several pieces, as live as the field
      Field after(const char *text, const char *of) const
      { return label(text).tight().enabledWhen(_enabledBy(category, of, num)); }
    };

    Item _generalGeneral(const optionsOf &o)
    {
      return grid(
        {o.check("FltkColorScheme", "Use dark interface"),
         o.check("Tooltips", "Show tooltips and hover information box"),
         hbox({o.check("MouseHoverHighlight", "Highlight hovered entity"),
               o.check("MouseHoverMeshes", "Hover mesh and views")}),
         o.check("DrawBoundingBoxes", "Show bounding boxes"),
         o.shows("FastRedraw", "Draw simplified model during user interaction"),
         o.check("Shaders", "Draw with the shader pipeline"),
         o.check("Antialiasing", "Enable antialiasing"),
         o.check("Trackball", "Use trackball rotation instead of Euler angles"),
         o.check("RotationCenterGravity",
                 "Rotate around pseudo center of mass"),
         hbox({o.row("Rotation center", _r_rotationCenterX),
               o.action("rotation_center_select", "Select")}),
         o.check("MouseInvertZoom", "Invert mouse wheel zoom direction")});
    }

    Item _generalAdvanced(const optionsOf &o)
    {
      return grid(
        {o.check("Terminal", "Print messages on terminal"),
         o.number("Verbosity", "Message verbosity"),
         o.text("TextEditor", "Text editor command"),
         o.text("DefaultFileName", "Default file name"),
         o.check("ConfirmOverwrite",
                 "Ask confirmation before overwriting files"),
         hbox({o.check("SaveSession", "Save session information on exit"),
               gap(1.),
               o.action("show_session_file", "Show file path").tight()}),
         hbox({o.check("SaveOptions", "Save options on exit"), gap(1.),
               o.action("show_options_file", "Show file path").tight()}),
         o.check("ExpertMode", "Enable expert mode"),
         o.number("NumThreads", "Maximum number of threads"),
         o.flag("Enable heavy visualization capabilities",
                opt_general_heavy_visualization),
         o.action("restoreDefaults", "Restore all options to default settings")
           .warns()});
    }

    Item _generalAxes(const optionsOf &o)
    {
      return grid({hbox({o.combo("Axes", "Axes mode", _c_axes), gap(1.),
                         o.check("AxesMikado", "Mikado style").tight()}),
                   o.row("Axes ticks", _r_axesTicksX),
                   o.vec("AxesFormat", "Axes format", 3, true),
                   o.vec("AxesLabel", "Axes labels", 3, true),
                   o.check("AxesAutoPosition",
                           "Set position and size of axes automatically"),
                   o.row("Axes minimum", _r_axesMinX),
                   o.row("Axes maximum", _r_axesMaxX),
                   o.action("axes_fit", "Fit to visible").share(1.),
                   o.check("SmallAxes", "Show small axes"),
                   o.row("Small axes position", _r_smallAxesPositionX)});
    }

    Item _generalAspect(const optionsOf &o)
    {
      return grid(
        {o.combo("Orthographic", "Projection mode", _c_orthographic,
                 _v_orthographic),
         o.number("ClipFactor", "Z-clipping distance factor"),
         o.row("Polygon offset factor/units", _r_polygonOffsetFactor),
         o.check("PolygonOffsetAlwaysOn", "Always apply polygon offset"),
         o.number("QuadricSubdivisions", "Quadric subdivisions"),
         o.number("PointSize", "Point size"),
         o.number("LineWidth", "Line width"),
         hbox({o.combo("VectorType", "Vector display", _c_vectorType, 1., 1.),
               o.action("arrow_edit", "Edit arrow")}),
         o.words("GraphicsFontEngine", "Font rendering engine",
                 _c_graphicsFontEngine),
         hbox(
           {o.words("GraphicsFont", "", _c_graphicsFont).share(4. / 5.).tight(),
            o.number("GraphicsFontSize", "Default font")
              .share(1. / 5.)
              .tight()}),
         hbox({o.words("GraphicsFontTitle", "", _c_graphicsFont)
                 .share(4. / 5.)
                 .tight(),
               o.number("GraphicsFontSizeTitle", "Title font")
                 .share(1. / 5.)
                 .tight()})});
    }

    Item _generalColor(const optionsOf &o)
    {
      std::vector<Item> rows = {
        hbox({o.row("Light position", _r_light0X), gap(1.),
              o.sphere(_r_light0X).tight()}),
        hbox({o.number("Light0W", "").share(.5),
              o.number("Brightness", "Light proximity and brightness")
                .share(.5)
                .tight()}),
        o.row("Material shininess and exponent", _r_shininess),
        o.combo("Shading", "Shading mode", _c_shading),
        o.row("Studio samples, spread and floor offset", _r_studio),
        o.combo("ColorScheme", "Predefined color scheme", _c_colorScheme),
        o.combo("BackgroundGradient", "Background gradient",
                _c_backgroundGradient)};
      for(const Field &c : o.colours()) rows.push_back(c);
      // each value one field wide: the names line up without a grid
      return vbox(rows).scrolls();
    }

    Item _generalCamera(const optionsOf &o)
    {
      return grid(
        {o.check("Camera", "Enable camera (experimental)"),
         o.check("Stereo", "Enable stereo rendering (experimental)"),
         o.number("CameraEyeSeparationRatio", "Eye separation ratio (%)"),
         o.number("CameraFocalLengthRatio", "Focal length ratio (%)"),
         o.number("CameraAperture", "Camera Aperture (degrees)"),
         o.flag("Enable gamepad (experimental)", opt_general_gamepad),
         o.action("gamepad_configure", "Configure Gamepad")});
    }

    Item _geometryGeneral(const optionsOf &o)
    {
      return grid(
        {o.number("Tolerance", "Geometry tolerance"),
         o.check("AutoCoherence",
                 "Remove duplicate entities in GEO model transforms"),
         rule(), label("Open CASCADE model healing options:"),
         o.check("OCCFixDegenerated", "Remove degenerated edges and faces"),
         o.check("OCCFixSmallEdges", "Remove small edges"),
         o.check("OCCFixSmallFaces", "Remove small faces"),
         o.check("OCCSewFaces", "Sew faces"),
         o.check("OCCMakeSolids", "Fix shells and make solids"),
         o.number("OCCScaling", "Global model scaling")});
    }

    Item _geometryVisibility(const optionsOf &o)
    {
      return grid({hbox({o.check("Points", "Points"),
                         o.check("PointLabels", "Point labels")}),
                   hbox({o.check("Curves", "Curves"),
                         o.check("CurveLabels", "Curve labels")}),
                   hbox({o.check("Surfaces", "Surfaces"),
                         o.check("SurfaceLabels", "Surface labels")}),
                   hbox({o.check("Volumes", "Volumes"),
                         o.check("VolumeLabels", "Volume labels")}),
                   o.combo("LabelType", "Label type", _c_geoLabelType),
                   o.row("Normals and tangents", _r_normals)});
    }

    Item _geometryTransfo(const optionsOf &o)
    {
      return grid({o.combo("Transform", "Main window transform", _c_transform),
                   hbox({o.row(" X", _r_geoTransformX, .75),
                         o.number("OffsetX", "").share(.7)}),
                   hbox({o.row(" Y +", _r_geoTransformY, .75),
                         o.number("OffsetY", "").share(.7)}),
                   hbox({o.row(" Z", _r_geoTransformZ, .75),
                         o.number("OffsetZ", "").share(.7)})});
    }

    Item _geometryAspect(const optionsOf &o)
    {
      return grid({o.combo("PointType", "Point display", _c_pointType),
                   o.number("PointSize", "Point size"),
                   o.number("PointSelectSize", "Selected point size"),
                   o.combo("CurveType", "Curve display", _c_curveType),
                   o.number("CurveWidth", "Curve width"),
                   o.number("CurveSelectWidth", "Selected curve width"),
                   o.number("NumSubEdges", "Curve subdivisions"),
                   o.combo("SurfaceType", "Surface display", _c_surfaceType),
                   o.combo("VolumeType", "Volume display", _c_volumeType)});
    }

    Item _geometryColor(const optionsOf &o)
    {
      std::vector<Item> rows = {
        o.check("Light", "Enable lighting"),
        o.check("LightTwoSide", "Use two-side lighting"),
        o.check("HighlightOrphans", "Highlight orphan and boundary entities"),
        hbox({o.number("Opacity", "").share(.25),
              o.combo("OpacityMode", "Opacity", _c_opacityMode)
                .share(.75)
                .tight()})};
      for(const Field &c : o.colours()) rows.push_back(c);
      return grid(rows).scrolls();
    }

    Item _meshGeneral(const optionsOf &o)
    {
      return grid(
        {o.combo("Algorithm", "2D algorithm", _c_algorithm, _v_algorithm),
         o.combo("Algorithm3D", "3D algorithm", _c_algorithm3D, _v_algorithm3D),
         o.combo("RecombinationAlgorithm", "2D recombination algorithm",
                 _c_recombinationAlgorithm),
         o.check("RecombineAll", "Recombine all triangular meshes"),
         o.combo("SubdivisionAlgorithm", "Subdivision algorithm",
                 _c_subdivisionAlgorithm),
         o.number("Smoothing", "Smoothing steps"),
         o.number("MeshSizeFactor", "Element size factor"),
         o.row("Min/Max element size", _r_meshSize),
         hbox({o.number("ElementOrder", "Element order").share(1. / 3.),
               o.check("SecondOrderIncomplete", "Use incomplete elements")})});
    }

    Item _meshAdvanced(const optionsOf &o)
    {
      return grid(
        {o.check("MeshSizeFromPoints",
                 "Compute element sizes using point values"),
         o.check("MeshSizeFromParametricPoints",
                 "Compute element sizes using parametric point values"),
         o.number("MeshSizeFromCurvature",
                  "Compute element sizes from curvature")
           .share(1. / 3.),
         o.check("MeshSizeExtendFromBoundary",
                 "Extend element sizes from boundary"),
         o.check("Optimize", "Optimize quality of tetrahedra"),
         o.check("OptimizeNetgen",
                 "Optimize quality of tetrahedra with Netgen"),
         o.check("HighOrderOptimize", "Optimize high-order meshes")});
    }

    Item _meshVisibility(const optionsOf &o)
    {
      return grid({hbox({o.check("Nodes", "Nodes"),
                         o.check("NodeLabels", "Node labels")}),
                   hbox({o.check("Lines", "1D elements"),
                         o.check("LineLabels", "1D element labels")}),
                   hbox({o.check("SurfaceEdges", "2D element edges"),
                         o.check("SurfaceLabels", "2D element labels")}),
                   hbox({o.check("SurfaceFaces", "2D element faces"),
                         o.check("VolumeLabels", "3D element labels")}),
                   hbox({o.check("VolumeEdges", "3D element edges"),
                         o.check("DrawSkinEdgesOnly", "Hide interior edges")}),
                   hbox({o.check("VolumeFaces", "3D element faces"),
                         o.combo("DrawSkinOnly", "", _c_meshSkin)}),
                   hbox({o.combo("LabelType", "Label type", _c_labelType),
                         o.number("LabelSampling", "Sampling").share(1. / 3.)}),
                   o.multi("Elements", _m_meshElements),
                   hbox({o.row("", _r_quality, .5),
                         o.combo("QualityType", "Quality range", _c_qualityType)
                           .share(.5)
                           .tight()}),
                   o.row("Size range", _r_radiusInf),
                   o.row("Normals and tangents", _r_normals)});
    }

    Item _meshAspect(const optionsOf &o)
    {
      return grid({o.number("Explode", "Element shrinking factor"),
                   o.combo("PointType", "Point display", _c_pointType),
                   o.number("PointSize", "Point size"),
                   o.number("LineWidth", "Line width"),
                   o.number("NumSubEdges", "High-order element subdivisions")});
    }

    Item _meshColor(const optionsOf &o)
    {
      std::vector<Item> rows = {
        o.check("Light", "Enable lighting"),
        o.combo("LightLines", "Edge lighting", _c_lightLines),
        o.check("LightTwoSide", "Use two-side lighting"),
        o.check("SmoothNormals", "Smooth normals"),
        o.number("AngleSmoothNormals", "Smoothing threshold angle"),
        hbox({o.number("Opacity", "").share(.25),
              o.combo("OpacityMode", "Opacity", _c_opacityMode)
                .share(.75)
                .tight()}),
        o.combo("ColorCarousel", "Coloring mode", _c_colorCarousel)};
      for(const Field &c : o.colours()) rows.push_back(c);
      return grid(rows).scrolls();
    }

    Item _solverGeneral(const optionsOf &o)
    {
      return grid({o.text("SocketName", "Base socket name"),
                   o.number("Timeout", "Timeout (in seconds)"),
                   o.check("AlwaysListen",
                           "Always listen to incoming connection requests"),
                   o.text("PythonInterpreter", "Python interpreter"),
                   o.text("OctaveInterpreter", "Octave interpreter")});
    }

    Item _postGeneral(const optionsOf &o)
    {
      return grid(
        {o.combo("Link", "View links", _c_link),
         o.number("AnimationDelay", "Frame duration (in seconds)"),
         o.number("AnimationStep", "Animation increment step"),
         o.check("AnimationCycle", "Cycle through views instead of steps"),
         o.check("CombineRemoveOriginal",
                 "Remove original views after combination"),
         o.check("HorizontalScales", "Draw value scales horizontally")});
    }

    Item _viewGeneral(const optionsOf &o)
    {
      return grid(
        {o.combo("Type", "Plot type", _c_type, 1., 1.),
         o.text("Name", "View name"),
         hbox({o.action("view_timestep_down", "-").share(.15).tight(),
               o.number("TimeStep", "").share(.7).tight(),
               o.action("view_timestep_up", "+").share(.15).tight(),
               o.after("Step", "view_timestep_up")}),
         hbox({o.number("NbIso", "Intervals"), gap(1.),
               o.text("Format", "Format").share(.425).tight()}),
         hbox({o.combo("IntervalsType", "Intervals type", _c_intervalsType, 1.,
                       1.),
               gap(1.),
               o.combo("ScaleType", "", _c_scaleType, _v_scaleType)
                 .share(.85)
                 .tight()}),
         hbox({o.combo("RangeType", "Range mode", _c_rangeType, 1., 1.),
               gap(1.), o.check("SaturateValues", "Saturate").tight(), gap(1.),
               o.number("ScaleThreshold", "Threshold").share(.425).tight()}),
         hbox({o.action("view_range_min", "Min").share(.25).tight(),
               o.number("CustomMin", "Custom min").share(.75).tight()}),
         hbox({o.action("view_range_max", "Max").share(.25).tight(),
               o.number("CustomMax", "Custom max").share(.75).tight()}),
         hbox({o.check("AdaptVisualizationGrid", "Adapt visualization grid"),
               gap(1.),
               o.combo("AdaptSkinOnly", "", _c_adaptSkin).share(.85).tight()}),
         hbox({o.action("view_recursion_down", "-").share(.15).tight(),
               o.number("MaxRecursionLevel", "").share(.7).tight(),
               o.action("view_recursion_up", "+").share(.15).tight(),
               o.after("Maximum recursion level", "view_recursion_up")}),
         o.number("TargetError", "Target visualization error")});
    }

    Item _viewAxes(const optionsOf &o)
    {
      return grid(
        {hbox({o.combo("Axes", "Axes mode", _c_axes), gap(1.),
               o.check("AxesMikado", "Mikado style").tight()}),
         o.row("Axes ticks", _r_axesTicksX),
         o.vec("AxesFormat", "Axes format", 3, true),
         o.vec("AxesLabel", "Axes labels", 3, true),
         o.check("AxesAutoPosition", "Position 3D axes automatically"),
         o.row("3D axes minimum", _r_axesMinX),
         o.row("3D axes maximum", _r_axesMaxX),
         o.combo("AutoPosition", "2D axes/value scale position",
                 _c_autoPosition),
         o.row("2D axes/value scale position", _r_viewPosition),
         o.row("2D axes/value scale size", _r_viewSize)});
    }

    Item _viewVisibility(const optionsOf &o)
    {
      return grid(
        {o.check("ShowScale", "Show value scale"),
         o.combo("ShowTime", "Time display", _c_showTime),
         o.check("DrawStrings", "Show annotations"),
         hbox({o.check("ShowElement", "Draw element outlines"),
               o.check("DrawSkinEdgesOnly", "Hide interior edges")}),
         hbox({label(""), o.check("DrawSkinOnly", "Hide interior faces")}),
         hbox({o.multi("Elements", _m_viewElements),
               o.number("Sampling", "Sampling").share(1. / 4.)}),
         o.combo("Boundary", "Element boundary mode", _c_boundary),
         o.row("Normals and tangents", _r_normals),
         o.multi("Fields", _m_viewFields),
         hbox({o.combo("ForceNumComponents", "", _c_forceNumComponents),
               o.row("", _r_componentMap, 1.2)})});
    }

    Item _viewTransfo(const optionsOf &o)
    {
      return grid({hbox({label("Coordinate transformation:"), label(""),
                         label("Raise:")}),
                   hbox({o.row(" X", _r_transformX, .75),
                         o.number("OffsetX", "").share(.7),
                         o.number("RaiseX", "").share(.7)}),
                   hbox({o.row(" Y +", _r_transformY, .75),
                         o.number("OffsetY", "").share(.7),
                         o.number("RaiseY", "").share(.7)}),
                   hbox({o.row(" Z", _r_transformZ, .75),
                         o.number("OffsetZ", "").share(.7),
                         o.number("RaiseZ", "").share(.7)}),
                   o.number("NormalRaise", "Normal raise").share(.75),
                   o.check("UseGeneralizedRaise",
                           "Use general transformation expressions"),
                   o.views("GeneralizedRaiseView", "Data source"),
                   o.number("GeneralizedRaiseFactor", "Factor"),
                   o.text("GeneralizedRaiseX", "X expression"),
                   o.text("GeneralizedRaiseY", "Y expression"),
                   o.text("GeneralizedRaiseZ", "Z expression")});
    }

    Item _viewAspect(const optionsOf &o)
    {
      return grid(
        {o.number("Explode", "Element shrinking factor"),
         o.combo("PointType", "Point display", _c_viewPointType),
         o.number("PointSize", "Point size"),
         hbox({o.combo("LineType", "Line display", _c_lineType), gap(1.),
               o.check("Stipple", "Stipple").tight()}),
         o.number("LineWidth", "Line width"),
         o.combo("VectorType", "Vector display", _c_viewVectorType, 1., 1.),
         o.row("Arrow size", _r_arrowSizeMin),
         o.number("DisplacementFactor", "Displacement factor"),
         o.views("ExternalView", "Data source for vector fields"),
         hbox(
           {o.combo("GlyphLocation", "Glyph location", _c_glyphLocation, 1.,
                    1.),
            gap(1.),
            o.combo("CenterGlyphs", "", _c_centerGlyphs).share(.85).tight()}),
         o.combo("TensorType", "Tensor display", _c_tensorType, 1., 1.)});
    }

    Item _viewColor(const optionsOf &o)
    {
      std::vector<Item> rows = {
        o.check("Light", "Enable lighting"),
        o.check("LightLines", "Enable lighting of lines"),
        o.check("LightTwoSide", "Use two-side lighting"),
        o.check("SmoothNormals", "Smooth normals"),
        o.number("AngleSmoothNormals", "Smoothing threshold angle"),
        o.number("Opacity", "Opacity")};
      for(const Field &c : o.colours()) rows.push_back(c);
      return grid(rows).scrolls();
    }

    // the map takes what is left of the pane
    Item _viewMap(const optionsOf &o)
    {
      return vbox(
        {o.combo("ColormapNumber", "Predefined colormap", _c_colormap),
         o.map()});
    }

    struct optionTab {
      const char *label;
      Item (*build)(const optionsOf &);
    };

    const optionTab _generalTabs[] = {{"General", _generalGeneral},
                                      {"Advanced", _generalAdvanced},
                                      {"Axes", _generalAxes},
                                      {"Aspect", _generalAspect},
                                      {"Color", _generalColor},
                                      {"Camera", _generalCamera},
                                      {nullptr, nullptr}};
    const optionTab _geometryTabs[] = {
      {"General", _geometryGeneral}, {"Visibility", _geometryVisibility},
      {"Transfo", _geometryTransfo}, {"Aspect", _geometryAspect},
      {"Color", _geometryColor},     {nullptr, nullptr}};
    const optionTab _meshTabs[] = {
      {"General", _meshGeneral},       {"Advanced", _meshAdvanced},
      {"Visibility", _meshVisibility}, {"Aspect", _meshAspect},
      {"Color", _meshColor},           {nullptr, nullptr}};
    const optionTab _solverTabs[] = {{"General", _solverGeneral},
                                     {nullptr, nullptr}};
    const optionTab _postTabs[] = {{"General", _postGeneral},
                                   {nullptr, nullptr}};
    const optionTab _viewTabs[] = {{"General", _viewGeneral},
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

  } // namespace

} // namespace

Ui::Form GuiOptions::build()
{
  if(!_c_colormap[0]) {
    int n = std::min(ColorTable_NumPredefined(), 63);
    for(int i = 0; i < n; i++) _c_colormap[i] = ColorTable_Name(i);
    _c_colormap[n] = nullptr;
  }
  // a view that has been closed falls back to the first line
  if(category >= _numCategories + _views()) category = 0;
  optionsOf of = {_categoryName(category),
                  category >= _numCategories ? view : 0};

  std::vector<std::pair<std::string, Item>> panes;
  const optionTab *tabs = _tabsForCategory(of.category);
  for(int i = 0; tabs && tabs[i].label; i++)
    panes.push_back({tabs[i].label, tabs[i].build(of)});
  Tabs pages;
  pages.tabs = panes;

  Form f = {
    "options",
    std::string("Options - ") +
      (category < _numCategories ?
         _categoryLabels[category] :
         ("View [" + std::to_string(category - _numCategories) + "]")),
    hbox(
      {vbox({chooseFrom(
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
               [this](int i) { return i == category; },
               [this](int i, bool on) {
                 if(!on) return;
                 category = i;
                 if(i >= _numCategories) view = i - _numCategories;
                 // another line is another set of tabs: built again, not
                 // refreshed
                 show();
               },
               false)
               .fills()
               .sized(8.),
             // Redraw only when the model drawn while one interacts is a
             // simplified one
             button("Redraw", _redraw).visibleWhen([]() {
               double v = 0.;
               NumberOption(GMSH_GET, "General", 0, "FastRedraw", v, false);
               return v != 0.;
             })}),
       pages})};
  // the fields read the options they name: changed from anywhere, read again
  // here
  f.refreshEvery = .25;
  // the same height whatever the category: twelve lines, the row of tabs one of
  // them
  f.leastRows = 11;
  return f;
}

void GuiOptions::showForView(int view_, const std::string &pane)
{
  if(view_ < 0) view_ = view;
  if(view_ < 0 || view_ >= _views()) view_ = 0;
  if(_views()) category = _numCategories + view_;
  // the colour map of a view is a tab of this window, not a window of its own
  show(pane);
}
