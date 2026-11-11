// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "OptionPages.h"

optionEntry check(const std::string &option, const std::string &label,
                  int weight, int flags)
{ return {EntryCheck, option, label, weight, flags}; }

optionEntry number(const std::string &option, const std::string &label,
                   int weight, int flags)
{ return {EntryNumber, option, label, weight, flags}; }

optionEntry choice(const std::string &option, const std::string &label,
                   int weight, int flags)
{ return {EntryChoice, option, label, weight, flags}; }

optionEntry text(const std::string &option, const std::string &label,
                 int weight, int flags)
{ return {EntryText, option, label, weight, flags}; }

optionEntry heading(const std::string &title)
{ return {EntryHeading, title, "", 1, 0}; }

optionEntry custom(const std::string &name, int weight)
{ return {EntryCustom, name, "", weight, 0}; }

optionEntry space(int weight) { return {EntryCustom, "", "", weight, 0}; }

// a section, open or not when its page is first shown
static optionSection section(const std::string &name, bool open,
                             const std::vector<optionRow> &rows)
{ return {name, open, rows}; }

static optionPage generalPage()
{
  return {
    "General",
    {section(
       "General", true,
       {{choice("General.FltkColorScheme", "Interface")},
        {choice("General.ColorScheme", "Graphics")},
        {check("General.Tooltips", "Show tooltips and hover information box")},
        {check("General.MouseHoverHighlight", "Highlight hovered entity"),
         check("General.MouseHoverMeshes", "Hover mesh and views")},
        {check("General.DrawBoundingBoxes", "Show bounding boxes")},
        {check("General.FastRedraw",
               "Draw simplified model during user interaction")},
        {check("General.Shaders", "Draw with the shader pipeline")},
        {check("General.Antialiasing", "Enable antialiasing")},
        {check("General.Trackball",
               "Use trackball rotation instead of Euler angles")},
        {check("General.RotationCenterGravity",
               "Rotate around pseudo center of mass")},
        {number("General.RotationCenterX", ""),
         number("General.RotationCenterY", ""),
         number("General.RotationCenterZ", "Rotation center"),
         custom("Select rotation center")},
        {check("General.MouseInvertZoom",
               "Invert mouse wheel zoom direction")}}),
     section(
       "Advanced", false,
       {{check("General.Terminal", "Print messages on terminal")},
        {number("General.Verbosity", "Message verbosity")},
        {text("General.TextEditor", "Text editor command")},
        {text("General.DefaultFileName", "Default file name")},
        {check("General.ConfirmOverwrite",
               "Ask confirmation before overwriting files")},
        {check("General.SaveSession", "Save session information on exit", 2),
         custom("Show session file", 1)},
        {check("General.SaveOptions", "Save options on exit", 2),
         custom("Show option file", 1)},
        {check("General.ExpertMode", "Enable expert mode")},
        {number("General.NumThreads", "Maximum number of threads")},
        {check("General.HeavyVisualization",
               "Enable heavy visualization capabilities")},
        {custom("Restore default options")}}),
     section(
       "Axes", false,
       {{choice("General.Axes", "Axes mode"),
         check("General.AxesMikado", "Mikado style", 1, EntryColumn2)},
        {number("General.AxesTicksX", ""), number("General.AxesTicksY", ""),
         number("General.AxesTicksZ", "Axes ticks")},
        {text("General.AxesFormatX", ""), text("General.AxesFormatY", ""),
         text("General.AxesFormatZ", "Axes format")},
        {text("General.AxesLabelX", ""), text("General.AxesLabelY", ""),
         text("General.AxesLabelZ", "Axes labels")},
        {check("General.AxesAutoPosition",
               "Set position and size of axes automatically")},
        {number("General.AxesMinX", ""), number("General.AxesMinY", ""),
         number("General.AxesMinZ", "Axes minimum")},
        {number("General.AxesMaxX", ""), number("General.AxesMaxY", ""),
         number("General.AxesMaxZ", "Axes maximum")},
        {custom("Fit axes to visible")},
        {check("General.SmallAxes", "Show small axes")},
        {number("General.SmallAxesPositionX", ""),
         number("General.SmallAxesPositionY", "Small axes position")}}),
     section(
       "Aspect", false,
       {{choice("General.Orthographic", "Projection mode")},
        {number("General.ClipFactor", "Z-clipping distance factor")},
        {number("General.PolygonOffsetFactor", ""),
         number("General.PolygonOffsetUnits", "Polygon offset factor/units")},
        {check("General.PolygonOffsetAlwaysOn", "Always apply polygon offset")},
        {number("General.QuadricSubdivisions", "Quadric subdivisions")},
        {number("General.PointSize", "Point size")},
        {number("General.LineWidth", "Line width")},
        {choice("General.VectorType", "Vector display"), custom("Edit arrow")},
        {custom("Font engine")},
        {custom("Graphics font", 4),
         number("General.GraphicsFontSize", "Default font", 1)},
        {custom("Graphics font of titles", 4),
         number("General.GraphicsFontSizeTitle", "Title font", 1)}}),
     section("Color", false,
             {{number("General.Light0X", ""), number("General.Light0Y", ""),
               number("General.Light0Z", "Light position")},
              {number("General.Light0W", ""),
               number("General.Brightness", "Proximity and brightness"),
               custom("Light sphere")},
              {number("General.Shininess", ""),
               number("General.ShininessExponent",
                      "Material shininess and exponent")},
              {choice("General.Shading", "Shading mode")},
              {number("General.StudioSamples", ""),
               number("General.StudioLightSpread", ""),
               number("General.StudioFloorOffset",
                      "Studio samples, spread, floor offset")},
              {choice("General.BackgroundGradient", "Background gradient")},
              {custom("General colors")}}),
     section(
       "Camera", false,
       {{check("General.Camera", "Enable camera")},
        {check("General.Stereo", "Enable stereo rendering")},
        {number("General.CameraEyeSeparationRatio",
                "Eye separation ratio (%)")},
        {number("General.CameraFocalLengthRatio", "Focal length ratio (%)")},
        {number("General.CameraAperture", "Camera Aperture (degrees)")},
        {},
        {check("General.Gamepad", "Enable gamepad (experimental)")},
        {custom("Configure gamepad")}})}};
}

static optionPage geometryPage()
{
  return {
    "Geometry",
    {section("General", false,
             {{number("Geometry.Tolerance", "Geometry tolerance")},
              {check("Geometry.AutoCoherence",
                     "Remove duplicate entities in GEO model transforms")},
              {heading("Open CASCADE model healing options:")},
              {check("Geometry.OCCFixDegenerated",
                     "Remove degenerated edges and faces")},
              {check("Geometry.OCCFixSmallEdges", "Remove small edges")},
              {check("Geometry.OCCFixSmallFaces", "Remove small faces")},
              {check("Geometry.OCCSewFaces", "Sew faces")},
              {check("Geometry.OCCMakeSolids", "Fix shells and make solids")},
              {number("Geometry.OCCScaling", "Global model scaling")}}),
     section("Visibility", true,
             {{check("Geometry.Points", "Points"),
               check("Geometry.PointLabels", "Point labels")},
              {check("Geometry.Curves", "Curves"),
               check("Geometry.CurveLabels", "Curve labels")},
              {check("Geometry.Surfaces", "Surfaces"),
               check("Geometry.SurfaceLabels", "Surface labels")},
              {check("Geometry.Volumes", "Volumes"),
               check("Geometry.VolumeLabels", "Volume labels")},
              {choice("Geometry.LabelType", "Label type")},
              {number("Geometry.Normals", "", 1, EntryOnRelease),
               number("Geometry.Tangents", "Normals and tangents", 1,
                      EntryOnRelease)}}),
     section("Transfo", false,
             {{choice("Geometry.Transform", "Main window transform")},
              {custom("Geometry transformation")}}),
     section("Aspect", false,
             {{choice("Geometry.PointType", "Point display")},
              {number("Geometry.PointSize", "Point size")},
              {number("Geometry.PointSelectSize", "Selected point size")},
              {choice("Geometry.CurveType", "Curve display")},
              {number("Geometry.CurveWidth", "Curve width")},
              {number("Geometry.CurveSelectWidth", "Selected curve width")},
              {number("Geometry.NumSubEdges", "Curve subdivisions")},
              {choice("Geometry.SurfaceType", "Surface display")},
              {choice("Geometry.VolumeType", "Volume display")}}),
     section("Color", false,
             {{check("Geometry.Light", "Enable lighting")},
              {check("Geometry.LightTwoSide", "Use two-side lighting")},
              {check("Geometry.HighlightOrphans",
                     "Highlight orphan and boundary entities")},
              {number("Geometry.Opacity", "", 1),
               choice("Geometry.OpacityMode", "Opacity", 3)},
              {custom("Geometry colors")}})}};
}

static optionPage meshPage()
{
  return {
    "Mesh",
    {section(
       "General", false,
       {{choice("Mesh.Algorithm", "2D algorithm")},
        {choice("Mesh.Algorithm3D", "3D algorithm")},
        {choice("Mesh.RecombinationAlgorithm", "2D recombination algorithm")},
        {check("Mesh.RecombineAll", "Recombine all triangular meshes")},
        {choice("Mesh.SubdivisionAlgorithm", "Subdivision algorithm")},
        {number("Mesh.Smoothing", "Smoothing steps")},
        {number("Mesh.MeshSizeFactor", "Element size factor", 1, EntryFloat)},
        {number("Mesh.MeshSizeMin", ""),
         number("Mesh.MeshSizeMax", "Min/Max element size")},
        {number("Mesh.ElementOrder", "Element order"),
         check("Mesh.SecondOrderIncomplete", "Incomplete elements", 1,
               EntryColumn2)}}),
     section("Advanced", false,
             {{check("Mesh.MeshSizeFromPoints",
                     "Compute element sizes using point values")},
              {check("Mesh.MeshSizeFromParametricPoints",
                     "Compute element sizes using parametric point values")},
              {number("Mesh.MeshSizeFromCurvature",
                      "Compute element sizes from curvature")},
              {check("Mesh.MeshSizeExtendFromBoundary",
                     "Extend element sizes from boundary")},
              {check("Mesh.Optimize", "Optimize quality of tetrahedra")},
              {check("Mesh.OptimizeNetgen",
                     "Optimize quality of tetrahedra with Netgen")},
              {check("Mesh.HighOrderOptimize", "Optimize high-order meshes")}}),
     section(
       "Visibility", true,
       {{check("Mesh.Nodes", "Nodes"), check("Mesh.NodeLabels", "Node labels")},
        {check("Mesh.Lines", "1D elements"),
         check("Mesh.LineLabels", "1D element labels")},
        {check("Mesh.SurfaceEdges", "2D element edges"),
         check("Mesh.SurfaceLabels", "2D element labels")},
        {check("Mesh.SurfaceFaces", "2D element faces"),
         check("Mesh.VolumeLabels", "3D element labels")},
        {check("Mesh.VolumeEdges", "3D element edges"),
         check("Mesh.DrawSkinEdgesOnly", "Hide interior edges")},
        {check("Mesh.VolumeFaces", "3D element faces"),
         choice("Mesh.DrawSkinOnly", "")},
        {choice("Mesh.LabelType", "Label"),
         number("Mesh.LabelSampling", "Sampling", 1,
                EntryColumn2Half | EntryOnRelease)},
        {custom("Mesh element types")},
        {number("Mesh.QualityInf", "", 1, EntryOnRelease),
         number("Mesh.QualitySup", "", 1, EntryOnRelease),
         choice("Mesh.QualityType", "Quality range", 2)},
        {number("Mesh.RadiusInf", "", 1, EntryOnRelease),
         number("Mesh.RadiusSup", "Size range", 1, EntryOnRelease)},
        {number("Mesh.Normals", "", 1, EntryOnRelease),
         number("Mesh.Tangents", "Normals and tangents", 1, EntryOnRelease)}}),
     section(
       "Aspect", false,
       {{number("Mesh.Explode", "Element shrinking factor", 1, EntryOnRelease)},
        {choice("Mesh.NodeType", "Point display")},
        {number("Mesh.PointSize", "Point size")},
        {number("Mesh.LineWidth", "Line width")},
        {number("Mesh.NumSubEdges", "High-order element subdivisions", 1,
                EntryOnRelease)}}),
     section("Color", false,
             {{check("Mesh.Light", "Enable lighting")},
              {choice("Mesh.LightLines", "Edge lighting")},
              {check("Mesh.LightTwoSide", "Use two-side lighting")},
              {check("Mesh.SmoothNormals", "Smooth normals")},
              {number("Mesh.AngleSmoothNormals", "Smoothing threshold angle", 1,
                      EntryOnRelease)},
              {number("Mesh.Opacity", "", 1),
               choice("Mesh.OpacityMode", "Opacity", 3)},
              {choice("Mesh.ColorCarousel", "Coloring mode")},
              {custom("Mesh colors")}})}};
}

static optionPage solverPage()
{
  return {
    "Solver",
    {section("General", true,
             {{text("Solver.SocketName", "Base socket name")},
              {number("Solver.Timeout", "Timeout (in seconds)")},
              {check("Solver.AlwaysListen",
                     "Always listen to incoming connection requests")},
              {text("Solver.PythonInterpreter", "Python interpreter")},
              {text("Solver.OctaveInterpreter", "Octave interpreter")}})}};
}

static optionPage postPage()
{
  return {
    "Post-processing",
    {section(
      "General", true,
      {{choice("PostProcessing.Link", "View links")},
       {number("PostProcessing.AnimationDelay", "Frame duration (in seconds)")},
       {number("PostProcessing.AnimationStep", "Animation increment step")},
       {choice("PostProcessing.AnimationCycle", "Animation cycle")},
       {check("PostProcessing.CombineRemoveOriginal",
              "Remove original views after combination")},
       {check("PostProcessing.HorizontalScales",
              "Draw value scales horizontally")}})}};
}

static optionPage viewPage()
{
  return {
    "View",
    {section("General", true,
             {{choice("View.Type", "Plot type")},
              {text("View.Name", "View name")},
              {number("View.TimeStep", "Step", 1, EntryStepper)},
              {number("View.NbIso", "Intervals", 1, EntryOnRelease),
               text("View.NumberFormat", "Format", 1, EntryColumn2Half)},
              {choice("View.IntervalsType", "Intervals type"),
               choice("View.ScaleType", "", 1, EntryColumn2)},
              {choice("View.RangeType", "Range mode"),
               check("View.SaturateValues", "Saturate", 1, EntryColumn2)},
              {custom("Range minimum", 1),
               number("View.CustomMin", "Custom min", 3, EntryOnRelease),
               number("View.ScaleThreshold", "Threshold", 1,
                      EntryColumn2Half | EntryOnRelease)},
              {custom("Range maximum", 1),
               number("View.CustomMax", "Custom max", 3, EntryOnRelease)},
              {check("View.AdaptVisualizationGrid", "Adapt visualization grid"),
               choice("View.AdaptSkinOnly", "", 1, EntryColumn2)},
              {number("View.MaxRecursionLevel", "Maximum recursion level", 1,
                      EntryStepper | EntryOnRelease)},
              {number("View.TargetError", "Target visualization error", 1,
                      EntryFloat | EntryOnRelease)}}),
     section(
       "Axes", false,
       {{choice("View.Axes", "Axes mode"),
         check("View.AxesMikado", "Mikado style", 1, EntryColumn2)},
        {number("View.AxesTicksX", ""), number("View.AxesTicksY", ""),
         number("View.AxesTicksZ", "Axes ticks")},
        {text("View.AxesFormatX", ""), text("View.AxesFormatY", ""),
         text("View.AxesFormatZ", "Axes format")},
        {text("View.AxesLabelX", ""), text("View.AxesLabelY", ""),
         text("View.AxesLabelZ", "Axes labels")},
        {check("View.AxesAutoPosition", "Position 3D axes automatically")},
        {number("View.AxesMinX", ""), number("View.AxesMinY", ""),
         number("View.AxesMinZ", "3D axes minimum")},
        {number("View.AxesMaxX", ""), number("View.AxesMaxY", ""),
         number("View.AxesMaxZ", "3D axes maximum")},
        {choice("View.AutoPosition", "2D axes/value scale position")},
        {number("View.PositionX", ""),
         number("View.PositionY", "2D axes/value scale position")},
        {number("View.Width", ""),
         number("View.Height", "2D axes/value scale size")}}),
     section(
       "Visibility", false,
       {{check("View.ShowScale", "Show value scale")},
        {choice("View.ShowTime", "Time display")},
        {check("View.DrawStrings", "Show annotations")},
        {check("View.ShowElement", "Draw element outlines"),
         check("View.DrawSkinEdgesOnly", "Hide interior edges")},
        {space(), check("View.DrawSkinOnly", "Hide interior faces")},
        {custom("View element types"),
         number("View.Sampling", "Sampling", 1,
                EntryColumn2Half | EntryOnRelease)},
        {choice("View.Boundary", "Element boundary mode")},
        {number("View.Normals", "", 1, EntryOnRelease),
         number("View.Tangents", "Normals and tangents", 1, EntryOnRelease)},
        {custom("View entry types")},
        {choice("View.ForceNumComponents", ""), custom("Component map")}}),
     section("Transfo", false,
             {{custom("View transformation")},
              {number("View.NormalRaise", "Normal raise", 1,
                      EntryFloat | EntryOnRelease)},
              {check("View.UseGeneralizedRaise",
                     "Use general transformation expressions")},
              {custom("Generalized raise view")},
              {number("View.GeneralizedRaiseFactor", "Factor", 1,
                      EntryFloat | EntryOnRelease)},
              {text("View.GeneralizedRaiseX", "X expression")},
              {text("View.GeneralizedRaiseY", "Y expression")},
              {text("View.GeneralizedRaiseZ", "Z expression")}}),
     section(
       "Aspect", false,
       {{number("View.Explode", "Element shrinking factor", 1, EntryOnRelease)},
        {choice("View.PointType", "Point display")},
        {number("View.PointSize", "Point size")},
        {choice("View.LineType", "Line display"),
         check("View.Stipple", "Stipple", 1, EntryColumn2)},
        {number("View.LineWidth", ""),
         number("View.OutlineWidth", "Line / outline width")},
        {choice("View.VectorType", "Vector display")},
        {number("View.ArrowSizeMin", ""),
         number("View.ArrowSizeMax", "Arrow size")},
        {number("View.DisplacementFactor", "Displacement factor", 1,
                EntryFloat | EntryOnRelease)},
        {custom("External view")},
        {choice("View.GlyphLocation", "Glyph location"),
         choice("View.CenterGlyphs", "", 1, EntryColumn2)},
        {choice("View.TensorType", "Tensor display")}}),
     section("Color", false,
             {{check("View.Light", "Enable lighting")},
              {check("View.LightLines", "Enable lighting of lines")},
              {check("View.LightTwoSide", "Use two-side lighting")},
              {check("View.SmoothNormals", "Smooth normals")},
              {number("View.AngleSmoothNormals", "Smoothing threshold angle", 1,
                      EntryOnRelease)},
              {number("View.Opacity", "Opacity")},
              {custom("View colors")}}),
     section("Map", false, {{custom("Colormap")}, {custom("Colorbar")}})}};
}

const std::vector<optionPage> &OptionPages()
{
  static const std::vector<optionPage> pages = {generalPage(), geometryPage(),
                                                meshPage(),    solverPage(),
                                                postPage(),    viewPage()};
  return pages;
}

const optionPage *GetOptionPage(const std::string &name)
{
  for(const optionPage &p : OptionPages())
    if(p.name == name) return &p;
  return nullptr;
}
