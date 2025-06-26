// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include <numeric>
#include <array>
#include <sstream>
#include <iomanip>
#include <string>
#include <functional>
#include "AnalyseMeshQuality2.h"
#include "OS.h"
#include "Context.h"
#include "PView.h"
#include "GModel.h"
#include "MElement.h"
#include "polynomialBasis.h"
#include "bezierBasis.h"
#include "qualityMeasuresJacobian.h"
#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#if defined(HAVE_VISUDEV)
// #include "BasisFactory.h"
#endif

// TODO:
//  1. add enableGeoFit option
//  2. add restrictToTypeOfElement option
//  x. Update Help message GUI (Explain what is smartrecompute)
//       Say in help that the plugin can be used to compute jacobian, hide best
//       elements, then compute quality (the gain is to compute quality of less
//       elements)
//  4. Test with ctest that everything works?
//  5. Add a method to set default value (that can be commented for
//     development purpose). But is it possible? It cannot be in the execution
//     of plugin, but at compilation

// TODO Later:
//  1. Add check + message after having fetched parameters
//     - If guidance = 1: output what will be done
//       if guidance = 0: output what will computed
//     - If guidance = 1: warn when parameters out of bound
//  2. Add validity for MLine on GEdge
//     - minJ/maxJ can be considered as a quality measure
//     - if dimension policy=-2?
//     - also GeoFit
//  3. Add more verbose messages?
//  4. Make option name starting with upper case because it is the convention

// TODO Maybe:
//  1. Intrinsic validity : smartreco777 for sharing element or 888 or 999
//  2. Check if surface is curved and count differently.
//     For now, let all 2D together.
//  3. Demo mode?
//  4. Disable keep data? (dataManagementPolicy=1)

// FIXME: PView are based on elements. If I remesh with a different mesh size
//  factor, data is still there but on wrong elements.

// NOTE What does the plugin
//  0. Free data and stop IF dataManagementPolicy = -1
//  1. Compute validity/quality IF usePreviousData = OFF
//   • Limit to GEntity in GModel::current()
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 meshes
//     - IF = 0 Limit to dimension 3 meshes IF there is any 3D mesh OTHERWISE
//              limit to dimension 2 meshes
//     - IF >= 1 do not limit (both dimension 2 and 3 meshes)
//   • Clear old entities IF dataManagementPolicy = 0
//   • Check if previous data can be reused IF smartRecomputation = ON
//   • Limit to visible elements IF restrictToVisibleElements = ON
//   • Limit to curved elements IF restrictToCurvedElements = ON
//   • Compute Validity IF skipValidity <= 0
//   • Compute Distortion IF enableDistortionQuality > 0
//   • Compute Aspect IF enableAspectQuality > 0
//   • Regularize Jacobian IF skipValidity <= 0 AND regularizeDeterminant = ON
//  2. Print statistics
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 data
//     - IF = 0 Limit to dimension 3 data IF there is any 3D mesh OTHERWISE
//              limit to dimension 2 data
//     - IF = 1 do not limit (dimension 2 and 3 data separately)
//     - IF = 2 combine dimension 2 and 3 data
//   • In columns: min, max and Worst Weighted Means of UNPACK(wmCutoffsForStats)
//   • Distortion IF enableDistortionQuality > 0
//   • Aspect IF enableAspectQuality > 0
//   • IF skipValidity <= 0:
//     - minJ/maxJ IF enableRatioJacDetAsAMetric > 0
//     - minJ IF enableMinJacDetAsAMetric > 0
//     - validity
//  3. Create PViewElementData IF createElementsView = ON
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 data
//     - IF = 0 Limit to dimension 3 data IF there is any 3D mesh OTHERWISE
//              limit to dimension 2 data
//     - IF >= 1 do not limit (dimension 2 and 3 data) (combined not possible)
//   • Let M = max(-skipValidity, enableDistortionQuality, enableAspectQuality, enableRatioJacDetAsAMetric, enableMinJacDetAsAMetric)
//   • Validity IF skipValidity = -M
//   • Distortion IF enableDistortionQuality = M
//   • Aspect IF enableAspectQuality = M
//   • minJ IF skipValidity <= 0 AND enableMinJacDetAsAMetric = M
//   • minJ/maxJ IF skipValidity <= 0 AND enableMinJacDetAsAMetric = M
//   • But: skip creation IF PView already exists and unchanged data
//  4. Create PView2D IF createPlotView = ON
//   • In function of dimensionPolicy, as for (point 2.)
//   • For metrics as for (point 3.).
//   • For Worst Weighted Means in function of UNPACK(wmCutoffsForPlots)
//   • But: skip creation IF PView already exists and unchanged data
//  5. Change visibility of elements IF adjustElementsVisibility >= 1
//   • In function of dimensionPolicy, as for (point 2.)
//   • In function of visibilityPolicy [here in the case hideWorstElements = OFF]:
//     - IF = -1 Limit to valid elements IF there are any invalid elements,
//               OTHERWISE skip hiding/making visible
//     - IF = 0 As "IF = 1" IF no invalid elements OTHERWISE as "IF = -1"
//     - IF = 1 As "IF = 2" IF there are multiple metric equal to M
//              OTHERWISE limit to elements that do not meet criterion
//                        for the metric == M
//     - IF = 2 Limit to elements that do not meet criterion for all metrics == M
//     - IF = 3 Limit to elements that do not meet criterion for any metrics == M
//   • In function of visibilityCriterion [in the case hideWorstElements = OFF]:
//     - IF = 0 Use "metricValue <= x" as criterion
//     - IF = 1 Use "x worst elements" as criterion
//     - IF = 2 Use "x% worst elements" as criterion
//     where x = visibilityThreshold
//   • Hide worst elements instead of best IF hideWorstElements = ON
//   • Unhide others IF doNoSetVisible = OFF
//   • In function of adjustElementsVisibility:
//     - IF = 1 Skip adjustment IF all elements are to be hidden
//     - IF >= 2 Hide/Set visible even if all elements are to be hidden

namespace {
  constexpr double UNTOUCHED = -987654321;
  constexpr double MP = 9;
}

StringXNumber MeshQuality2Options_Number[] = {
  // Quality metrics to include:
  {GMSH_FULLRC, "enableDistortionQuality", nullptr, 0, "OFF, (1+)=includeDistortionQuality"},
  {GMSH_FULLRC, "enableAspectQuality", nullptr, 0, "OFF, (1+)=includeAspectQuality"},
  // What to do:
  {GMSH_FULLRC, "createElementsView", nullptr, 1, "OFF, ON"},
  {GMSH_FULLRC, "createPlotView", nullptr, 1, "OFF, ON"},
  {GMSH_FULLRC, "adjustElementsVisibility", nullptr, 0, "OFF, 1=skipIfAllWouldBeHidden, 2=acceptAllHidden"}, //TODO updtate for geofit
  {GMSH_FULLRC, "guidanceLevel", nullptr, 1, "(-1)=minimalOutput, 0=verbose, 1=verboseAndExplanations"},
  // Elements Selection:
  {GMSH_FULLRC, "dimensionPolicy", nullptr, -1, "(-1)=force2D, 0=prioritize3D, 1=2D+3D, 2=combine2D+3D"},
  {GMSH_FULLRC, "restrictToVisibleElements", nullptr, 0, "OFF, ON=analyzeOnlyVisibleElements"},
  {GMSH_FULLRC, "restrictToCurvedElements", nullptr, 0, "OFF, ON=analyzeOnlyNonStraightElements"},
  // Hiding options:
  {GMSH_FULLRC, "visibilityPolicy", nullptr, 1, "(-1)=validity|skip, 0=validity|1, 1=qualOR, 2=qualAND"},
  {GMSH_FULLRC, "visibilityCriterion", nullptr, 0, "0=proportionVisibleElem, 1=numVisibleElem, 2=metricValue"},
  {GMSH_FULLRC, "visibilityThreshold", nullptr, 10, "DOUBLE (which meaning depends on visibilityCriterion)"},
  {GMSH_FULLRC, "hideWorstElements", nullptr, 0, "OFF=hideBestElements, ON"},
  {GMSH_FULLRC, "doNoSetVisible", nullptr, 0, "OFF=performHidingAndUnhiding, ON=justPerformHiding"},
  // Advanced computation options:
  {GMSH_FULLRC, "usePreviousData", nullptr, 0, "OFF, ON=skipComputationMetrics"},
  {GMSH_FULLRC, "dataManagementPolicy", nullptr, 0, "(-1)=skipExecutionJustFreeData, 0=freeOldDataIfMeshAbsent, 1=keepAllData"},
  {GMSH_FULLRC, "smartRecomputation", nullptr, 0, "OFF=alwaysRecompute, ON=avoidRecomputeIfUnchangedElementTags"},
  {GMSH_FULLRC, "skipValidity", nullptr, 0, "(0-)=includeValidity, ON=skipPreventiveValidityCheck"},
  // Advanced analysis options:
  {GMSH_FULLRC, "skipStatPrinting", nullptr, 0, "OFF, ON"},
  {GMSH_FULLRC, "enableRatioJacDetAsAMetric", nullptr, 0, "OFF, 1+ (require skipValidity=(0-))"},
  {GMSH_FULLRC, "enableMinJacDetAsAMetric", nullptr, 0, "OFF, 1+ (require skipValidity=(0-)"},
  {GMSH_FULLRC, "regularizeDeterminant", nullptr, 1, "OFF, ON=treatInvertedAsValid (NB: alter minJ and minJ/maxJ)"},
  {GMSH_FULLRC, "wmCutoffsForStats", nullptr, 10, "CUTOFFS (for stats weighted mean, see Help)"},
  {GMSH_FULLRC, "wmCutoffsForPlots", nullptr, 10, "CUTOFFS (for plots weighted mean, see Help)"},
  // Legacy options:
  {GMSH_FULLRC, "JacobianDeterminant", nullptr, UNTOUCHED, "[legacy] OFF, ON"},
  {GMSH_FULLRC, "IGEMeasure", nullptr, UNTOUCHED, "[legacy] OFF, ON"},
  {GMSH_FULLRC, "ICNMeasure", nullptr, UNTOUCHED, "[legacy] OFF, ON"},
  {GMSH_FULLRC, "HidingThreshold", nullptr, UNTOUCHED, "[legacy] DOUBLE"},
  {GMSH_FULLRC, "ThresholdGreater", nullptr, UNTOUCHED, "[legacy] OFF, ON"},
  {GMSH_FULLRC, "CreateView", nullptr, UNTOUCHED, "[legacy] OFF, ON"},
  {GMSH_FULLRC, "Recompute", nullptr, UNTOUCHED, "[legacy] OFF, ON"},
  {GMSH_FULLRC, "DimensionOfElements", nullptr, UNTOUCHED, "[legacy] -1, 2, 3, 4"}

#if defined(HAVE_VISUDEV)
  // {GMSH_FULLRC, "createTemporalView", nullptr, 0},
  // {GMSH_FULLRC, "createPointwiseView", nullptr, 0},
  // {GMSH_FULLRC, "elementIDForPwView", nullptr, 0}
#endif
};

constexpr int MeshQuality2Options_LegacyOptionsNumber = 8;

std::pair<int, std::string> MeshQuality2Options_Headers[] = {
  {0, "Quality metrics to include"},
  {2, "What to do"},
  {6, "Elements selection"},
  {9, "Visibility adjustment options"},
  {14, "Advanced computation options"},
  {18, "Advanced analysis options"},
  {24, "Legacy options"},
};

namespace JacQual = jacobianBasedQuality;
using Plug = GMSH_AnalyseMeshQuality2Plugin;
int Plug::_verbose = 0;
const std::array<std::string, 7> Plug::_metricNames = {
  "Validity", "Inversion", "GeoFit", "Disto", "Aspect", "MinJ/maxJ", "MinJac"
};

// ======== Plugin: Base class methods =========================================
// =============================================================================

extern "C" {
  GMSH_Plugin *GMSH_RegisterAnalyseMeshQuality2Plugin()
  {
    return new GMSH_AnalyseMeshQuality2Plugin();
  }
}

int Plug::getNbOptions(bool legacy) const
{
  return sizeof(MeshQuality2Options_Number) / sizeof(StringXNumber) -
    (legacy ? 0 : MeshQuality2Options_LegacyOptionsNumber);
}

StringXNumber *Plug::getOption(int iopt)
{
  return &MeshQuality2Options_Number[iopt];
}

std::string Plug::getOptionsSectionHeader(int iopt) const
{
  for(auto &header : MeshQuality2Options_Headers) {
    if(header.first == iopt) return header.second;
  }
  return "";
}

std::string Plug::getHelp() const
{
  // NOTE: &nbsp; can be used for forcing a space.
  return
    "INTRODUCTION\n"
    "Plugin(AnalyseMeshQuality) evaluates the validity and quality of mesh "
    "elements within the current model. The plugin allows users to compute "
    "various quality metrics such as Distortion, Aspect Ratio, and GeoFit, "
    "generating detailed statistics for each of them, create visualization views "
    "(element-based or plot-based), and adjust element visibility based on "
    "customizable criteria.\n"
    "\n"
    "GETTING STARTED\n"
    "The options provided in the plugin have been chosen to be "
    "intuitive and descriptive, making it easy for users to understand "
    "their functionality. "
    "Hovering over the input fields will display tooltips that provide "
    "accepted input values along with a concise explanation of their "
    "effects. "
    "Options requiring additional clarification are detailed further in "
    "subsequent sections.\n"
    "Additionally:\n"
    "• To get live, contextual explanations during execution, users can "
    "set `guidanceLevel' to 1.\n"
    "• A FAQ is available at the end of this help message.\n"
    "\n"
    "IMPORTANT NOTES\n"
    "• Input option values are designed to have a default effect when set to 0, "
    "allowing users to quickly identify modified options. "
    "For this reason, some options support negative values.\n"
    "• The advanced option `smartRecompute' can be very useful when running "
    "the plugin multiple times but must be used cautiously. "
    "See the 'OPTIONS CLARIFICATIONS' section for details.\n"
    "\n"
    "PLOTS\n"
    "The plugin creates a new type of plot, designed to improve readability and "
    "facilitate comparison. In these plots, the quality value is represented on "
    "the y-axis, while the x-axis shows the percentage of elements. Note that the "
    "x-axis is not linear but exponential, with the cutoff "
    "(see OPTIONS CLARIFICATIONS section) positioned at the middle of the axis. "
    "Each point (x, y) in the plot indicates that x% of the elements have a "
    "quality less than or equal to y. Conversely, (100-x)% of the elements have a "
    "quality greater than or equal to y. A window defined by (x0, y0) and (x1, y1) "
    "shows that (x1-x0)% of the elements have a quality between y0 and y1. "
    "These plots make it easy to visualize the minimum quality of the mesh. For small "
    "meshes, the plot exhibits abrupt jumps on the left side. This is normal "
    "and expected. The first jump corresponds to the transition from the worst "
    "value to the second worst value. It also indicates the number of "
    "analyzed elements, as it is located at x = 1 / nb.\n"
    "\n"
    "DEFINITION\n"
    "• `Visibility metrics': The plugin distinguishes between requested "
    "metrics, which are computed and displayed as statistics, and a "
    "subset of these called `Visibility metrics'. The Visibility metrics "
    "are used to determine "
    "visibility adjustment and visualization views. To obtain the subset, "
    " the plugin compute the maximum value among:\n"
    "-- enableDistortionQuality\n"
    "-- enableAspectQuality\n"
    "-- enableGeoFitQuality\n"
    "-- enableMinJacDetAsAMetric\n"
    "-- enableRatioJacDetAsAMetric\n"
    "The metrics matching this maximum value are in the set of Visibility metrics.\n"
    "\n"
    "VISIBILITY ADJUSTMENT\n"
    "• The plugin is able to hide and unhide elements based on specific criteria. "
    "Various options are available for fine-tuning the behavior of this feature.\n"
    "• Default behaviour: In the presence of invalid elements, the plugin will "
    "make them visible and hide the other. If all elements are valid, the plugin "
    "will select the 10% worst element according to the Visibility metrics and "
    "make them visible while hiding the others.\n"
    "Available options:\n"
    "• `adjustElementsVisibility': Enables the operation of hiding and unhiding elements. "
    "If set to `1', the plugin will abort if all analyzed elements meet the "
    "criterion to be hidden. To force the hiding in this case, set it to `2'.\n"
    "• `visibilityPolicy': Determines which metric(s) are used to decide which elements "
    "are hidden or made visible. The available settings and their behaviors are:\n"
    "-- `-1': The plugin first checks if there are invalid elements. "
    "If invalid elements exist, they are made visible while valid elements are hidden. "
    "If no invalid elements are present, the plugin will abort.\n"
    "-- `0': Similar to `-1', but in this case, the plugin does not abort when no invalid "
    "elements are present. Instead, it behaves as if the input value were set to `1'.\n"
    "-- `1': The plugin checks each Visibility metric. If any elements meet the criterion "
    "for being visible, they are made visible. Elements failing to meet the criterion "
    "across all metrics are hidden.\n"
    "-- `2': The behavior is the opposite of `1'. Elements that fail to meet the visibility "
    "criterion are made visible, while those that meet it are hidden.\n"
    "• `visibilityCriterion': Defines what the threshold is used. Available "
    "values are:\n"
    "-- `0': The threshold is the percentage of elements to make visible.\n"
    "-- `1': The threshold is the number of elements to make visible.\n"
    "-- `2': The threshold is the metric value.\n"
    "• `visibilityThreshold': Specifies the threshold value for visibility decisions.\n"
    "• `hideWorstElements': Reverses the hiding operation. If set to "
    "`1', the best-rated elements are made visible and worst-rated elements are hidden.\n"
    "• `doNoSetVisible': Controls whether elements are made visible or only hidden. "
    "If set to `0', the plugin performs both hiding and unhiding. If set to `1', the plugin "
    "only performs the hiding operation without making any elements visible.\n"
    "\n"
    "OPTIONS CLARIFICATIONS\n"
    "• `guidanceLevel': Determines the verbosity level of the plugin output:\n"
    "-- `-1': Typically used for scripting, where only the printed statistics are desired.\n"
    "-- `0': Prints an overview of what the plugin is doing but without details.\n"
    "-- `1': Prints detailed information about the plugin's operation, which may be "
    "useful for debugging. It also provides guidance for beginner users.\n"
    "• `dataManagementPolicy': Determines how data is managed by the plugin:\n"
    "-- `-1': Frees data, typically useful in scripting contexts.\n"
    "-- `0': Deletes data corresponding to geometry entities that are absent in the current model.\n"
    "-- `1': Keeps data corresponding to geometry entities that are absent in the current model. "
    "This is useful if the plugin may be run again with a previous model.\n"
    "• `smartRecomputation': Prevents unnecessary recomputation when the plugin is run again. "
    "If set to `0', the plugin will always recompute. If set to `1', for each geometrical entity, "
    "the plugin will decide to recompute only if the element tags have changed. "
    "This happens, for example, if the geometrical entity has been remeshed or "
    "if a topological operation has been performed. However, the plugin cannot "
    "detect if nodes have been moved, such as after an optimization. "
    "Use this option with caution!\n"
    "• `skipValidity': The plugin is designed to check the validity of elements before "
    "evaluating any quality metrics. This behavior ensures faster computation of quality metrics "
    "in the presence of invalid elements. The user can set `skipValidity' to `1' to disable validity "
    "checks. To include validity as part of the set of quality metrics, set its value "
    "to `-M', where `M' is the maximum value among all metrics.\n"
    "• `regularizeDeterminant': Disables inverted element detection. "
    "By default, the plugin detects "
    "inverted elements, which are elements with a negative area or volume, "
    "classifying elements into three categories: valid, invalid, and inverted. "
    "Inverted elements may be treated as valid or invalid depending on the solver. "
    "To treat inverted elements as valid, set this option to `1'. "
    "This also affects the metrics `minJ' and `minJ/maxJ'. "
    "Internally, the plugin compares the absolute values of both `minJ' and `maxJ', "
    "and if the absolute value of `maxJ' is smaller, the following changes "
    "are made: `new_minJ = -maxJ' and `new_maxJ = -minJ'.\n"
    "• `wmCutoffsForStats' and `wmCutoffsForPlots': Defines a list of cutoff values "
    "used for computing weighted mean-based statistics and generating plots."
    "The list of cutoff is specified as a sequence of two-digit values, "
    "e.g. 123456, which "
    "would result in extracted cutoffs: `12%', `34%' and `56%'. "
    "The default value is 10. A `10%' cutoff corresponds to a "
    "weighted mean where the worst 10% "
    "of the values influence equally with the rest. "
    "This technique highlights critical data subsets impacting the finite "
    "element solution.\n"
    "\n"
    "ADVANCED USE OF THE PLUGIN\n"
    "The plugin can be used to easily compute the quality of a subset of mesh "
    "elements by combining multiple runs. This is especially great in scripts."
    "A typical workflow may include the following steps:\n"
    "1. First, run the plugin to compute a specific metric (e.g., `minJ' or `minJ/maxJ') "
    "for all elements. Use the visibility adjustment options to make only a "
    "subset of elements visible. For example: Set `adjustElementsVisibility' "
    "to `1' and use `visibilityCriterion' "
    "and `visibilityThreshold' to select specific elements. For instance, "
    "making only the 20% smaller elements visible:\n"
    "-- `adjustElementsVisibility = 1'\n"
    "-- `visibilityPolicy = 1'\n"
    "-- `visibilityThreshold = 20'\n"
    "-- `enableMinJacDetAsAMetric = 1'\n"
    "2. In the second run, compute the quality metrics for the visible elements. "
    "This ensures focus on the subset of interest, avoiding computations on the "
    "entire mesh. Set `adjustElementsVisibility' to `0' to avoid further hiding.\n"
    "-- `enableDistortionQuality = 2'\n"
    "-- `enableAspectQuality = 1'\n"
    "-- `createElementsView = 1'\n"
    "-- `adjustElementsVisibility = 0'\n"
    "-- `restrictToVisibleElements = 1'\n"
  //FIXME: says that compute validity but should not
    "3. Optionally, in a final run, set back all elements to visible. "
    "This can be achieved by setting:\n"
    "-- `adjustElementsVisibility = 1'\n"
    "-- `visibilityThreshold = 101'\n"
    "-- `usePreviousData = 1'\n"
    "-- `skipStatPrinting = 1'\n"
  //FIXME: says that should compute but should not
  //FIXME: do not set back all element visible
    "\n"
    "This workflow allows users to filter and focus on subsets of the mesh for detailed quality analysis while maintaining flexibility to switch back to global computations when needed.\n"

    "FAQ\n"
    "• Q1: As the plugin has been rewritten, will my script that uses the "
    "old version fail to work?\n"
    "- A: No, although not available in the GUI, the old options have been "
    "kept as legacy options. However, it is recommended to update "
    "the script, as these legacy options may be removed in a future release.\n";
}

PView *Plug::execute(PView *v)
{
  _verbose = static_cast<int>(MeshQuality2Options_Number[5].def);

  _info(MP, "---------------------------------------------");
  _status(0, "Executing the plugin AnalyseMeshQuality...");

  _fetchParameters();

  _info(1, "-> <|>Option 'guidanceLevel' is 1. This makes the plugin to "
           "provide various explanations");

  // Handle cases where no computation is requested
  if(_param.freeData) {
    _info(-1, "-> Freeing data...");
    _info(1, "-> Freeing data... (because option 'dataManagePolicy' is -1)");
    _data2D->clear();
    _data3D->clear();
    MeshQuality2Options_Number[15].def = !_previousFreeOldData;
    _info(MP, "   Done. Option 'dataManagePolicy' has been reset");
    _info(1, "   Nothing else to do, re-run the plugin to compute something");
    return v;
  }

  Parameters::Computation &pc = _param.compute;
  if(!pc.jacobian && !pc.jacobianOnCurvedGeo && !pc.disto && !pc.aspect && !pc.geofit) {
    _warn(0, "-> Nothing to execute. Please adjust the following options:\n"
             "   - Turn ON at least one of the following metrics:\n"
             "     * enableDistortionQuality\n"
             "     * enableAspectQuality\n"
             "     * enableGeoFit\n"
             "   - OR turn OFF 'skipValidity'.");
    return v;
  }

  GModel *m = GModel::current();
  if(pc.freeOldData && _m && _m != m) {
    _info(0, "-> Detected a new Model, previous data will be cleared");
    // FIXME may not be the case (can we create a new model with exact same geometry and mesh?)
    // FIXME Do I really need this?
  }
  _m = m;

  // Check which dimension to compute/show, initialize data and counts elements
  bool check2D, check3D;
  _decideDimensionToCheck(check2D, check3D);

  Counts counts2D, counts3D;
  if(check2D) _data2D->initialize(_m, _param.compute, counts2D);
  if(check3D) _data3D->initialize(_m, _param.compute, counts3D);

  // Purge views just after initialization of _data2D and _data3D
  _purgeViews(check2D, check3D);

  // Count and compute if needed, otherwise check there is something to output
  std::size_t totalToCompute = _printElementToCompute(counts2D, counts3D);
  Counts countsTotal = counts2D + counts3D;
  if(!totalToCompute) {
    _guidanceNothingToCompute(countsTotal, check2D, check3D);
    if(!countsTotal.elToShow) return v;
  }
  else {
    if(!pc.jacobian && (countsTotal.elToCompute[2] || countsTotal.elToCompute[3])) {
      _warn(1, "-> <|>Option 'skipValidity' is ON, validity will not be "
               "computed. This may significantly slow down quality computation "
               "in the presence of invalid elements");
    }
    _computeRequestedData(countsTotal, check2D, check3D);
  }

  // Gather data
  std::vector<Measures> measures;
  if(check2D) {
    measures.emplace_back();
    _data2D->gatherValues(counts2D, measures.back());
    measures.back().dimStr = "dimension 2";
    measures.back().dimStrShort = "2D";
  }
  if(check3D) {
    measures.emplace_back();
    _data3D->gatherValues(counts3D, measures.back());
    measures.back().dimStr = "dimension 3";
    measures.back().dimStrShort = "3D";
  }
  _finalizeMeasuresData(measures);

  // Combine if necessary
  if(_dimensionPolicy == 2) {
    measures[0] = Measures::combine(measures[0], measures[1], "dimension 2 and 3 combined", "2D+3D");
    measures.erase(measures.begin() + 1);
  }

  //_updateWhatToShow(measures);

  _param.check2D = check2D;
  _param.check3D = check3D;
  _statGen->printStats(_param, measures);

  _createPlots(measures);
  _createElementViews(measures);
  if(_performHiding(measures)) {
    CTX::instance()->mesh.changed = ENT_ALL;
#if defined(HAVE_OPENGL)
    drawContext::global()->draw();
#endif
  }

  _info(0, "Done executing Plugin AnalyseMeshQuality");
  _info(1, "(Set guidanceLevel to 0 or -1 to reduce verbosity)");

  return v;
}

// ======== Plugin: private methods ============================================
// =============================================================================

void Plug::_fetchParameters()
{
  Parameters::Computation &pc = _param.compute;
  Parameters::Post &pp = _param.pview;
  Parameters::Hiding &ph = _param.hide;
  Parameters::MetricsToShow &ps = _param.show;

  double skipValidity, disto, aspect, geofit, minJ, ratioJ,
   dataManagePolicy;

  // Metrics to include:
  disto = MeshQuality2Options_Number[0].def;
  aspect = MeshQuality2Options_Number[1].def;
  geofit = 1; // FIXME
  // geofit = MeshQuality2Options_Number[2].def;

  // What to do:
  pp.createElemView = static_cast<bool>(MeshQuality2Options_Number[2].def);
  pp.createPlot = static_cast<bool>(MeshQuality2Options_Number[3].def);
  ph.todo = static_cast<int>(MeshQuality2Options_Number[4].def);

  // Elements Selection:
  _dimensionPolicy = static_cast<int>(MeshQuality2Options_Number[6].def);
  pc.onlyVisible = static_cast<bool>(MeshQuality2Options_Number[7].def);
  pc.onlyCurved = static_cast<bool>(MeshQuality2Options_Number[8].def);

  // Visibility options:
  ph.policy = static_cast<int>(MeshQuality2Options_Number[9].def);
  ph.criterion = static_cast<int>(MeshQuality2Options_Number[10].def);
  ph.threshold = MeshQuality2Options_Number[11].def;
  ph.worst = static_cast<bool>(MeshQuality2Options_Number[12].def);
  ph.unhideToo = !static_cast<bool>(MeshQuality2Options_Number[13].def);

  // Advanced computation options:
  pc.skip = static_cast<bool>(MeshQuality2Options_Number[14].def);
  dataManagePolicy = static_cast<int>(MeshQuality2Options_Number[15].def);
  pc.smartRecompute = static_cast<bool>(MeshQuality2Options_Number[16].def);
  skipValidity = MeshQuality2Options_Number[17].def;

  // Advanced analysis options:
  ps.skipStats = static_cast<bool>(MeshQuality2Options_Number[18].def);
  ratioJ = MeshQuality2Options_Number[19].def;
  minJ = MeshQuality2Options_Number[20].def;
  ps.regularizeJac = static_cast<bool>(MeshQuality2Options_Number[21].def);
  pp.statCutoffPack = MeshQuality2Options_Number[22].def;
  pp.plotCutoffPack = MeshQuality2Options_Number[23].def;

  // -> statsGenerator
  _statGen->setCutoffStats(pp.statCutoffPack);
  _statGen->setCutoffPlots(pp.plotCutoffPack);

  // -> dataManagePolicy
  _previousFreeOldData = pc.freeOldData;
  _param.freeData = dataManagePolicy == -1;
  pc.freeOldData = dataManagePolicy <= 0;

  // -> metrics to compute
  pc.jacobian = skipValidity <= 0;
  pc.jacobianOnCurvedGeo = ratioJ > 0 || minJ > 0;
  pc.disto = static_cast<bool>(disto);
  pc.aspect = static_cast<bool>(aspect);
  pc.geofit = static_cast<bool>(geofit);

  // -> metrics to show
  ps.which[VALIDITY] = skipValidity == 0 ? -1 : skipValidity > 0 ? 0 : -static_cast<int>(skipValidity);
  ps.which[DISTO] = static_cast<int>(disto);
  ps.which[ASPECT] = static_cast<int>(aspect);
  ps.which[MINJAC] = static_cast<int>(minJ);
  ps.which[RATIOJAC] = static_cast<int>(ratioJ);
  ps.which[GEOFIT] = static_cast<int>(geofit);
  ps.which[INVERSION] = !ps.regularizeJac;
  ps.M = *std::max_element(std::begin(ps.which), std::end(ps.which));
  if(ps.M == 0 && ps.which[VALIDITY] == -1) {
    ps.which[VALIDITY] = 1;
    ps.M = 1;
  }

  // Legacy options (must be last):
  _fetchLegacyParameters();

  // TODO: implement this and use p = std::clamp(p, 0, 3);
  // FIXME Warnings if verbose
  // if(_dimensionPolicy < 0)
  //   _dimensionPolicy = 0;
  // else if(_dimensionPolicy > 3)
  //   _dimensionPolicy = 3;
  //
  // if(pc.policy < -2)
  //   pc.policy = -2;
  // else if(pc.policy > 1)
  //   pc.policy = 1;
  //

#if defined(HAVE_VISUDEV)
  // // TODO come back later
  // _pwJac = checkValidity / 2;
  // _pwIGE = computeDisto / 2;
  // _pwICN = computeAspect / 2;
  //
  // // NOTE About createTimeView:
  // //  check if PView::_data::NbTimeStep if _data of type PViewDataList
  // //  check if PView::_options::vectorType == PViewOptions::Displacement (5),
  // //  or just consider that NbTimeStep is sufficient
  //
  // bool createTimeView = static_cast<bool>(MeshQuality2Options_Number[20].def);
  // _createPwView = static_cast<bool>(MeshQuality2Options_Number[21].def);
  // _elemNumForPwView = static_cast<int>(MeshQuality2Options_Number[22].def);
  // _viewOrder = 0;
  // _dataPViewJac.clear();
  // _dataPViewIGE.clear();
  // _dataPViewICN.clear();
#endif
}

void Plug::_fetchLegacyParameters()
{
  bool touched = false;
  for(int i = getNbOptions(false); i < getNbOptions(true); i++) {
    if(MeshQuality2Options_Number[i].def != UNTOUCHED) {
      touched = true;
      break;
    }
  }
  if(!touched) return;

  _verbose = 1;

  _error(MP, "-> <|>Deprecated options detected. The plugin will execute using "
             "the legacy configuration and ignore new options.");
  _warn(MP, "   <|>Please update the deprecated options to their modern "
            "counterparts.");
  _info(0, "-> <|>Use the following changes to map the options and achieve "
           "equivalent results:\n"
           " 1. Set 'skipComputationMetrics' to 1 IF '_Recompute' is 0\n"
           " 2. Set 'createElementsView' to '_CreateView'\n"
           " 3. Set 'enableDistortionQuality' to 1 IF '_ICNMeasure' is not 0\n"
           " 4. Set 'enableAspectQuality'' to 1 IF '_IGEMeasure' is not 0\n"
           " 5. Set 'dimensionPolicy' to -1 IF '_DimensionOfElements' is 2\n"
           "    OTHERWISE set 'dimensionPolicy' to 1 IF '_DimensionOfElements' "
           "is 4\n"
           " 6. Set 'visibilityThreshold' to '_HidingThreshold'\n"
           " 7. Set 'hideWorstElements' to 1 IF '_ThresholdGreater' is 0\n"
           " 8. Set 'skipValidity' to 1 if '_JacobianDeterminant' is 0\n"
           " 9. Set 'enableRatioJacDetAsAMetric' to 1\n"
           "10. Set 'enableMinJacDetAsAMetric' to 1\n"
           "11. Set 'wmCutoffsForStats' to 50\n"
           "12. IF '_HidingThreshold' is smaller than 99:\n"
           "    -  Set 'adjustElementsVisibility' to 1\n"
           "    -  Set 'visibilityPolicy' to 1\n"
           "    -  Set 'enableDistortionQuality' to 2 IF "
           "'enableDistortionQuality' is 1\n"
           "       OTHERWISE set 'enableAspectQuality' to 2 IF "
           "'enableAspectQuality' is 1\n"
           "       OTHERWISE set 'enableRatioJacDetAsAMetric' to 2");
  _info(0, "   Note: To disable this message, avoid modifying the "
            "deprecated options.");


  Parameters::Computation &pc = _param.compute;
  Parameters::Post &pp = _param.pview;
  Parameters::Hiding &ph = _param.hide;
  Parameters::MetricsToShow &ps = _param.show;

  pc.jacobianOnCurvedGeo = false;
  pc.onlyVisible = false;
  pc.onlyCurved = false;
  pp.statCutoffPack = 50;
  pp.createPlot = false;
  ps.which[INVERSION] = 0;
  ps.which[GEOFIT] = 0;
  ps.which[RATIOJAC] = 1;
  ps.which[MINJAC] = 1;
  ps.regularizeJac = false;
  _param.freeData = false;

  int k = getNbOptions();

  double val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) // JacDet
    ps.which[VALIDITY] = pc.jacobian = static_cast<bool>(val);
  else
    ps.which[VALIDITY] = pc.jacobian = false;

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) // IGEMeasure
    ps.which[ASPECT] = pc.aspect = static_cast<bool>(val);
  else
    ps.which[ASPECT] = pc.aspect = false;

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) // ICNMeasure
    ps.which[DISTO] = pc.disto = static_cast<bool>(val);
  else
    ps.which[DISTO] = pc.disto = false;

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) { // HidingThreshold
    ph.threshold = val;
    ph.todo = ph.threshold < 99;
    ph.policy = 1;
    ph.criterion = 2;
    ph.unhideToo = false;
    if(ps.which[DISTO])
      ps.which[DISTO] = 2;
    else if(ps.which[ASPECT])
      ps.which[ASPECT] = 2;
    else if(ps.which[VALIDITY])
      ps.which[RATIOJAC] = 2;
  }
  else {
    ph.threshold = false;
  }

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) // ThresholdGreater
    ph.worst = !static_cast<bool>(val);
  else
    ph.worst = false;

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) // CreateView
    pp.createElemView = static_cast<bool>(val);
  else
    pp.createElemView = false;

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) { // Recompute
    pc.skip = !static_cast<bool>(val);
    pc.smartRecompute = false;
    pc.freeOldData = true;
  }
  else {
    pc.skip = true;
  }

  val = MeshQuality2Options_Number[k++].def;
  if (val != UNTOUCHED) { // DimensionOfElements
    int dimPol = static_cast<int>(val);
    _param.dimPolicy = dimPol == 2 ? -1 : dimPol == 4 ? 1 : 0;
  }
  else {
    _param.dimPolicy = 0;
  }
}

void Plug::_purgeViews(bool purge2D, bool purge3D)
{
  // Remove deleted PViews
  std::set<PView *> existingViews(PView::list.begin(), PView::list.end());
  for (auto it = _pviews.begin(); it != _pviews.end(); ) {
    if (existingViews.find(it->second) == existingViews.end())
      it = _pviews.erase(it);
    else
      ++it;
  }

  // Remove PViews to forget
  if(purge2D && _data2D->getRequestedHasChanged()) {
    for (auto it = _pviews.begin(); it != _pviews.end(); ) {
      if(it->first.dim2Elem)
        it = _pviews.erase(it);
      else
        ++it;
    }
  }
  if(purge3D && _data3D->getRequestedHasChanged()) {
    for (auto it = _pviews.begin(); it != _pviews.end(); ) {
      if(it->first.dim3Elem)
        it = _pviews.erase(it);
      else
        ++it;
    }
  }
}

void Plug::_computeRequestedData(Counts counts, bool check2D, bool check3D) const
{
  std::vector<DataEntity*> allDataEntities;
  if(check2D)
    _data2D->getDataEntities(allDataEntities);
  if(check3D)
    _data3D->getDataEntities(allDataEntities);

  if(counts.elToCompute[0] > 0 || counts.elToCompute[1] > 0) {
    _status(0, "-> Computing Validity+...");
    MsgProgressStatus progress_status(static_cast<int>(counts.elToCompute[0] + counts.elToCompute[1]));
    for(auto data: allDataEntities) {
      data->computeJacDet(progress_status, counts.elToCompute[0], counts.elToCompute[1]);
    }
  }

  if(counts.elToCompute[2] > 0) {
    _status(0, "-> Computing Distortion quality...");
    MsgProgressStatus progress_status(static_cast<int>(counts.elToCompute[2]));
    for(auto data: allDataEntities) {
      data->computeDisto(progress_status, !_param.compute.jacobian);
    }
  }

  if(counts.elToCompute[3] > 0) {
    _status(0, "-> Computing Aspect quality...");
    MsgProgressStatus progress_status(static_cast<int>(counts.elToCompute[3]));
    for(auto data: allDataEntities) {
      data->computeAspect(progress_status, !_param.compute.jacobian);
    }
  }

  if(counts.elToCompute[4] > 0) {
    _status(0, "-> Computing GeoFit...");
    MsgProgressStatus progress_status(static_cast<int>(counts.elToCompute[4]));
    for(auto data: allDataEntities) {
      data->computeGeoFit(progress_status);
    }
  }

  _status(0, "Done computing data");
}

bool isValid(double minJ, double maxJ)
{
  // FIXME move to jacobianBasedQuality?
  if (minJ == 0.0 || maxJ == 0.0) return false;
  return std::signbit(minJ) == std::signbit(maxJ);
}

void Plug::_finalizeMeasuresData(std::vector<Measures> &measures) const
{
  Parameters::MetricsToShow ps = _param.show;

  for(auto &m: measures) {
    if(ps.regularizeJac) {
      for(std::size_t i = 0; i < m.minJ.size(); i++) {
        if(std::abs(m.minJ[i]) > std::abs(m.maxJ[i])) {
          std::swap(m.minJ[i], m.maxJ[i]);
          m.minJ[i] *= -1;
          m.maxJ[i] *= -1;
        }
      }
    }

    if(ps.which[VALIDITY] || ps.which[INVERSION]) {
      size_t num = m.elements.size()-m.elementsGFit.size();
      m.elementsStraightGeo.resize(num);
      if(ps.which[VALIDITY]) m.isValid.resize(num);
      if(ps.which[INVERSION]) m.isInverted.resize(num);

      size_t k = -1;
      for(std::size_t i = 0; i < m.minJ.size(); i++) {
        if(m.isOnCurvedGeo[i]) continue;
        m.elementsStraightGeo[++k] = m.elements[i];

        if(ps.which[VALIDITY]) {
          bool valid = isValid(m.minJ[i], m.maxJ[i]);
          m.isValid[k] = valid;
          if(!valid) ++m.numInvalidElements;
        }

        if(ps.which[INVERSION]) {
          bool inverted = m.maxJ[i] < 0;
          m.isInverted[i] = inverted;
          if(inverted) ++m.numInvertedElements;
        }
      }
    }

    if(_param.show.which[RATIOJAC]) {
      m.ratioJ.resize(m.minJ.size());
      for(std::size_t i = 0; i < m.minJ.size(); i++)
        m.ratioJ[i] = m.minJ[i] / m.maxJ[i];
    }

    if(!_param.show.which[MINJAC])
      m.minJ.clear();
    m.maxJ.clear();

    m.sizes[VALIDITY] = m.isValid.size();
    m.sizes[INVERSION] = m.isInverted.size();
    m.sizes[DISTO] = m.minDisto.size();
    m.sizes[ASPECT] = m.minAspect.size();
    m.sizes[GEOFIT] = m.minGFit.size();
    m.sizes[RATIOJAC] = m.ratioJ.size();
    m.sizes[INVERSION] = m.isInverted.size();
  }
}

void Plug::_updateWhatToShow(const std::vector<Measures> &m)
{
  bool allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].isValid.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[VALIDITY] = 0;

  allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].isInverted.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[INVERSION] = 0;

  allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].minJ.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[MINJAC] = 0;

  allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].ratioJ.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[RATIOJAC] = 0;

  allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].minGFit.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[GEOFIT] = 0;

  allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].minDisto.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[DISTO] = 0;

  allEmpty = true;
  for(size_t i = 0; i < m.size(); ++i)
    if(!m[i].minAspect.empty()) {allEmpty = false; break;}
  if(allEmpty) _param.show.which[ASPECT] = 0;

}

void Plug::_createPlots(const std::vector<Measures> &measures)
{
  if(!_param.pview.createPlot) return;
  Parameters::MetricsToShow &ps = _param.show;
  for(const auto &m: measures) {
    for(int i = VALIDITY; i <= MINJAC; i++) {
      if(ps.which[i] == ps.M)  _createPlotsOneMetric(m, static_cast<Metric>(i));
    }
  }
}

void Plug::_createPlotsOneMetric(const Measures &m, Metric metric)
{
  const std::vector<double> &values = m.getValues(metric);
  if(values.empty()) return;

  std::string s = _metricNames[metric];
  s += " ";
  s += m.dimStrShort;
  s += " (p)";

  constexpr double minMaxQuality[2] = {0, 1};
  constexpr double minMaxQualityNeg[2] = {-1, 1};
  const double *minMax = (metric == RATIOJAC || metric == MINJAC) ? nullptr :
  (metric == GEOFIT) ? minMaxQualityNeg : minMaxQuality;

  for(double cutoff: _statGen->getCutoffPlots()) {
    Key key(m.dim2Elem, m.dim3Elem, metric, Key::TypeView::PLOT, cutoff);
    if(_pviews.find(key) == _pviews.end()) {
      PView *p = new PView(s, cutoff, true, values, minMax);
      _pviews[key] = p;
    }
  }
}

void Plug::_createElementViews(const std::vector<Measures> &measures)
{
  if(!_param.pview.createElemView) return;

  Parameters::MetricsToShow &ps = _param.show;
  for(const auto &m: measures) {
    for(int i = VALIDITY; i <= MINJAC; i++) {
      if(ps.which[i] == ps.M)
        _createElementViewsOneMetric(m, static_cast<Metric>(i));
    }
  }
}

void Plug::_createElementViewsOneMetric(const Measures &m, Metric metric)
{
  const std::vector<double> &values = m.getValues(metric);
  const std::vector<MElement *> &elements = m.getElements(metric);
  if(values.empty()) return;

  std::string s = _metricNames[metric];
  s += " ";
  s += m.dimStrShort;
  s += " (e)";

  Key key(m.dim2Elem, m.dim3Elem, metric, Key::TypeView::ELEMENTS, 0);
  if(_pviews.find(key) == _pviews.end()) {
    std::map<int, std::vector<double> > dataPV;
    for(size_t i = 0; i < values.size(); i++) {
      dataPV[elements[i]->getNum()].push_back(values[i]);
    }
    PView *p = new PView(s, "ElementData", _m, dataPV);
    _pviews[key] = p;
  }
}

bool Plug::_performHiding(const std::vector<Measures> &measures)
{
  Parameters::Hiding &hide = _param.hide;
  Parameters::MetricsToShow &show = _param.show;
  if(!hide.todo) return false;

  size_t countHidden = 0, countMadeVisible = 0;

  for(auto &measure: measures) {
    std::vector<MElement *> toHide;

    // Hide in function of validity, if requested
    if(hide.policy <= 0) {
      // FIXME update
      for(size_t i = 0; i < measure.isValid.size(); i++) {
        bool val = static_cast<bool>(measure.isValid[i]);
        if(hide.worst ? !val : val)
          toHide.push_back(measure.elements[i]);
      }

      if(!toHide.empty() || hide.policy == -1) {
        _hideElements(measure, toHide, countHidden, countMadeVisible);
        continue;
      }
    }

    // Hide in function of quality-like metrics
    bool first = true;
    for (int i = DISTO; i <= MINJAC; ++i) {
      if(show.which[i] == show.M) {
        std::set<MElement *> tmp;
        _findElementsToHide(measure, static_cast<Metric>(i), tmp);
        if(first) {
          toHide.insert(toHide.end(), tmp.begin(), tmp.end());
          first = false;
          continue;
        }
        std::vector<MElement *> result;
        if(hide.policy <= 1) {
          // Keep element unhidden if any requested metric fall into the criterion
          result.resize(std::min(toHide.size(), tmp.size()));
          auto it = std::set_intersection(toHide.begin(), toHide.end(), tmp.begin(), tmp.end(), result.begin());
          result.resize(it - result.begin());
        }
        else {
          // Keep element unhidden only if all requested metric fall into the criterion
          result.resize(toHide.size() + tmp.size());
          auto it = std::set_union(toHide.begin(), toHide.end(), tmp.begin(), tmp.end(), result.begin());
          result.resize(it - result.begin());
        }
        toHide = std::move(result);
      }
    }
    _hideElements(measure, toHide, countHidden, countMadeVisible);
  }

  if(countHidden && countMadeVisible)
    _info(0, "-> %zu elements have been made visible, %zu have been hidden.", countMadeVisible, countHidden);
  else if (countHidden)
    _info(0, "-> %zu elements have been hidden.", countHidden);
  else if (countMadeVisible)
    _info(0, "-> %zu elements have been made visible.", countMadeVisible);

  return static_cast<bool>(countHidden + countMadeVisible);
}

template <typename T>
T clamp(T val, T lower, T upper)
{
  return std::min(upper, std::max(val, lower));
}

void Plug::_findElementsToHide(const Measures &measure,
  Metric metric, std::set<MElement *> &elementsToHide) const
{
  std::vector<double> values = measure.getValues(metric);

  double limitVal;
  size_t numVisibleElements = static_cast<size_t>(_param.hide.threshold);
  switch(_param.hide.criterion) {
  case 2:
  limitVal = _param.hide.threshold;
    break;

  case 0: {
    double tmp = clamp(_param.hide.threshold, 0., 100.) / 100.;
    tmp *= static_cast<double>(values.size() - 1);
    numVisibleElements = static_cast<size_t>(tmp);
  }
  case 1:
    numVisibleElements = clamp(numVisibleElements, size_t{0}, values.size() - 1);
    std::nth_element(values.begin(), values.begin() + static_cast<long>(numVisibleElements), values.end());
    limitVal = values[numVisibleElements];
    break;

  default:
    _error(0, "Invalid hiding criterion");
    return;
  }

  const std::vector<double> &val = measure.getValues(metric);
  const std::vector<MElement *> &elements = measure.getElements(metric);
  std::set<MElement *> onLimit;

  for(int i = 0; i < val.size(); i++) {
    if(_param.hide.worst ? val[i] < limitVal : val[i] > limitVal) {
      elementsToHide.insert(elements[i]);
    }
    else if(val[i] == limitVal) {
      onLimit.insert(elements[i]);
    }
  }

  // Add elements from onLimit to match numOfElements
  size_t numHiddenRequired = elements.size() - numVisibleElements;
  if (_param.hide.criterion < 2 && elementsToHide.size() < numHiddenRequired) {
    size_t remaining = std::min(numHiddenRequired - elementsToHide.size(), onLimit.size());
    auto it = onLimit.begin();
    for (size_t i = 0; i < remaining; i++, ++it) {
      elementsToHide.insert(*it);
    }
  }
}

bool Plug::_hideElements(const Measures &measure,
                         std::vector<MElement *> &elemToHide,
                         size_t &countHidden, size_t &countMadeVisible)
{
  if(_param.hide.todo < 2 && elemToHide.size() == measure.elements.size()) {
    _info(0, "Skipping hiding because all elements would be hidden.");
    _info(1, "To force hiding, set 'adjustElementsVisibility' to 2");
    return false;
  }

  if(!_param.hide.unhideToo) {
    for(auto el : elemToHide) el->setVisibility(false);
    countHidden += elemToHide.size();
    return true;
  }

  std::sort(elemToHide.begin(), elemToHide.end()); // for binary_search
  for(auto el : measure.elements) {
    if (std::binary_search(elemToHide.begin(), elemToHide.end(), el))
      el->setVisibility(false);
    else
      el->setVisibility(true);
  }
  countHidden += elemToHide.size();
  countMadeVisible += measure.elements.size() - elemToHide.size();
  return true;
}

void Plug::_decideDimensionToCheck(bool &check2D, bool &check3D) const
{
  std::size_t num3DElem = 0;

  // Iterate through regions to count 3D mesh elements
  for(auto it = _m->firstRegion(); it != _m->lastRegion(); ++it) {
    num3DElem += (*it)->getNumMeshElements();
  }

  // Apply policy logic
  check2D = true;
  check3D = true;
  if(_dimensionPolicy == 0 && num3DElem > 0)
    check2D = false;
  else if(_dimensionPolicy <= 0)
    check3D = false;
}

// ======== StatGenerator ======================================================
// =============================================================================

void Plug::StatGenerator::printStats(const Parameters &param,
                                     const std::vector<Measures> &measures)
{
  if(param.show.skipStats) return;

  size_t totalNumberToShow[7]{};
  for(auto m: measures) {
    for(int i = 0; i < 7; i++)
      totalNumberToShow[i] += m.sizes[i];
  }

  // const int *which = param.show.which;
  int cntQuality = 0;
  for (int i = DISTO; i <= MINJAC; ++i) {
    cntQuality += totalNumberToShow[i];
  }

  _info(1, "-> Printing statistics, here is what is important to know about "
  "them:");
  if(totalNumberToShow[VALIDITY])
  _info(1, "   *V<|>alidity*  provides information about the Jacobian "
           "determinant being strictly different from zero. "
           "A mesh containing invalid elements "
           "will usually result in incorrect Finite Element solutions. Each "
           "element is classified as either valid or invalid.");
  if(totalNumberToShow[INVERSION])
    _info(1, "   *I<|>nversion*  provides information about the Jacobian "
             "determinant being strictly negative. A mesh containing inverted "
             "elements may result in incorrect Finite Element solutions "
             "depending on the solver. Each valid element is classified as "
             "either inverted or not inverted.");
  if(totalNumberToShow[DISTO])
  _info(1, "   *D<|>istortion quality*  (previously ICN) is related to the "
           "condition number of the stiffness matrix. Low-Distortion elements "
           "may cause numerical roundoff errors or significantly reduce the "
           "convergence speed of iterative methods. Values "
           "range from 0 to 1.");
  if(totalNumberToShow[ASPECT])
  _info(1, "   *A<|>spect quality*  (previously IGE) is related to "
           "the gradient of the FE solution. Elements with poor aspect quality "
           "negatively affect errors in the gradient of the solution. Values "
           "range from 0 to 1.");
  if(totalNumberToShow[RATIOJAC])
    _info(1, "   *R<|>atio minJ/maxJ*  is the ratio between the minimum and "
             "maximum values of the Jacobian determinant. It is faster to "
             "compute than the distortion and aspect quality metrics and can "
             "be used to evaluate how much elements are deformed. However, "
             "note that it is not a true quality metric. Values range from "
             "-∞ to 1.");
  if(totalNumberToShow[MINJAC])
    _info(1, "   *m<|>inJ*  is the minimum of the Jacobian determinant computed "
             "in the reference space and can be used to check the element size. "
             "This metric is particularly relevant for iterative methods, "
             "where the time step may depend on the size of the smallest "
             "element. Values range from -∞ to +∞.");
  if(totalNumberToShow[GEOFIT])
    _info(1, "   *GeoFit*  is TODO. Values range from -1 to 1.");
  if(param.pview.statCutoffPack && cntQuality)
    _info(1, "   *W<|>orst-10%% Weighted Mean*  (Wm10) corresponds to a weighted "
             "mean where the worst 10%% of the values are assigned the same weight "
             "as the remaining values. This approach is preferable to the standard "
             "mean because it emphasizes the worst elements, which are critical "
             "as they can negatively impact the Finite Element solution. "
             "Note that the standard mean corresponds to Wm50.");
  for(auto &measure: measures) {
    _printStats(param.show, measure);
  }
}

/**
 * @brief Splits a double into two-digit chunks from its integer and fractional
 *        parts.
 * @param input The double value to decompose.
 * @param cutoffs Vector to store the resulting chunks.
 */
void Plug::StatGenerator::_unpackCutoff(double input,
  std::vector<double> &cutoffs) const
{
  cutoffs.clear();
  long long integerPart = static_cast<long long>(input);
  double fractionalPart = input - integerPart;

  while (integerPart > 0) {
    double twoDigitChunk = static_cast<double>(integerPart % 100);
    if(twoDigitChunk) cutoffs.push_back(integerPart % 100);
    integerPart /= 100;
  }

  while (fractionalPart > 0.0) {
    fractionalPart *= 100;
    int twoDigitChunk = static_cast<int>(std::round(fractionalPart));
    if(twoDigitChunk) cutoffs.push_back(twoDigitChunk / 100.0);
    fractionalPart -= twoDigitChunk;
    if (fractionalPart < 1e-10) break;
  }
  std::sort(cutoffs.begin(), cutoffs.end());
}

void Plug::StatGenerator::_printStats(const Parameters::MetricsToShow &show, const Measures &measure)
{
  _info(MP, "-> Statistics for %s:", measure.dimStr);

  // Header
  bool haveQualityToPrint = false;
  for(int i = GEOFIT; i <= MINJAC; ++i) {
    if(measure.sizes[i]) haveQualityToPrint = true;
  }
  if(haveQualityToPrint) {
    std::ostringstream columnNamesStream;
    columnNamesStream << "   | ";
    columnNamesStream << std::setw(_colWidth) << "";
    columnNamesStream << std::setw(_colWidth) << "Min";
    for (double c : _statCutoffs) {
      std::ostringstream formattedP;
      formattedP << std::setprecision(2) << c;
      columnNamesStream << std::setw(_colWidth) << "Wm" + formattedP.str();
    }
    columnNamesStream << std::setw(_colWidth) << "Max";
    _info(MP, "%s", columnNamesStream.str().c_str());
  }

  for(int i = GEOFIT; i <= MINJAC; i++) {
    if(measure.sizes[i])
      _printStatsOneMetric(measure, static_cast<Metric>(i));
  }

  // Validity
  if(!measure.sizes[VALIDITY] && !measure.sizes[INVERSION]) return;

  double numElement = static_cast<double>(measure.elements.size());
  double percentageInvalid = static_cast<double>(measure.numInvalidElements) / numElement * 100;
  double percentageInversed = static_cast<double>(measure.numInvertedElements) / numElement * 100;
  if(!(measure.numInvalidElements + measure.numInvertedElements))
    _status(MP, "   All elements are valid :-)");
  else if(!measure.numInvertedElements)
    _warn(MP, "   Found %zu invalid elements (~%.2g%%)",
      measure.numInvalidElements, percentageInvalid);
  else if(!measure.numInvalidElements)
    _warn(MP, "   <|>All elements are valid but %zu elements are inversed (~%.2g%%)",
      measure.numInvertedElements, percentageInversed);
  else
    _warn(MP, "   <|>Found %zu invalid elements (~%.2g%%) and %zu inversed "
              "elements (~%.2g%%)", measure.numInvalidElements,
              percentageInvalid, measure.numInvertedElements, percentageInversed);
}

void Plug::StatGenerator::_printStatsOneMetric(const Measures &measure, Metric metric)
{
  std::vector<double> values = measure.getValues(metric);
  if(values.empty()) return;

  size_t numElem = values.size();
  size_t numCutoff = _statCutoffs.size();
  auto minMax = std::minmax_element(values.begin(), values.end());
  double min = *minMax.first;
  double max = *minMax.second;

  std::vector<double> avg(numCutoff);
  std::sort(values.begin(), values.end());
  for(int i = 0; i < numCutoff; ++i) {
    const std::vector<double> &coeff = _getCoefficients(_statCutoffs[i], numElem);
    avg[i] = std::inner_product(values.begin(), values.end(), coeff.begin(), 0.0);
  }

  std::ostringstream valStream;
  valStream << "   |";
  valStream << std::setw(_colWidth) << _metricNames[metric] << ":";
  valStream << std::setprecision(3);
  if(metric == ASPECT || metric == DISTO) valStream << std::fixed;
  if(metric == MINJAC) valStream << std::defaultfloat; // could be std::scientific
  valStream << std::setw(_colWidth) << min;
  for(auto i = 0; i < numCutoff; ++i)
    valStream << std::setw(_colWidth) << avg[i];
  valStream << std::setw(_colWidth) << max;
  _info(MP, "%s", valStream.str().c_str());
}

const std::vector<double> &Plug::StatGenerator::_getCoefficients(double cutoff, size_t num)
{
  ++_idxCall;
  auto pairKey = std::make_pair(cutoff, num);
  auto it = _cutoffvsNumValues.find(pairKey);

  if (it != _cutoffvsNumValues.end()) {
    _idxLastCall[it->second] = _idxCall;
    return _coeff[it->second];
  }

  size_t idx = 0;
  if (_coeff.size() >= _N) {
    int minVal = _idxLastCall[0];
    for (size_t i = 1; i < _idxLastCall.size(); ++i) {
      if (_idxLastCall[i] < minVal) {
        idx = i;
        minVal = _idxLastCall[i];
      }
    }
    _coeff[idx].clear();
    _idxLastCall[idx] = _idxCall;
    _cutoffvsNumValues.erase(std::find_if(_cutoffvsNumValues.begin(), _cutoffvsNumValues.end(),
          [&](const auto& p) { return p.second == idx; }));
    _cutoffvsNumValues[pairKey] = idx;
  }
  else {
    idx = _coeff.size();
    _coeff.emplace_back();
    _idxLastCall.push_back(_idxCall);
    _cutoffvsNumValues.emplace(pairKey, idx);
  }

  _computeCoefficients(cutoff, num, _coeff[idx]);
  return _coeff[idx];
}

void Plug::StatGenerator::_computeCoefficients(double cutoff, size_t sz,
  std::vector<double> &coeff)
{
  coeff.resize(sz+1);
  double exp = std::log(2)/std::log(100/cutoff);
  coeff[0] = 0;
  for(auto i = 1; i < sz+1; ++i) {
    coeff[i] = std::pow(static_cast<double>(i)/(sz), exp);
    coeff[i-1] = coeff[i] - coeff[i-1];
  }
  coeff.resize(sz);
}

// ======== DataSingleDimension ================================================
// =============================================================================

void Plug::DataSingleDimension::initialize(GModel const *m,
                                           const Parameters::Computation &param,
                                           Counts &counts)
{
  _requestedListHasChanged = false;

  // Update list GEntities (thus _dataEntities) if needed
  std::set<GEntity *, GEntityPtrLessThan> entities;
  if(_dim == 2)
    entities.insert(m->firstFace(), m->lastFace());
  else if(_dim == 3)
    entities.insert(m->firstRegion(), m->lastRegion());
  _updateGEntities(entities, param.freeOldData);

  // Initialize all DataEntity and count elements
  for(auto &it : _dataEntities) {
    int numRequestedChanged = it.second.initialize(param);
    if(numRequestedChanged)
      _requestedListHasChanged = true;
    it.second.count(param, counts);
  }
}

void Plug::DataSingleDimension::_updateGEntities(
  std::set<GEntity *, GEntityPtrLessThan> &entities, bool freeNonExistent)
{
  // Get GEntities present in the current model, add new ones in _dataEntities
  for(const auto &ge: entities) {
    if(_dataEntities.find(ge) == _dataEntities.end())
      _dataEntities.emplace(ge, DataEntity(ge));
  }

  if(freeNonExistent) {
    // Remove GEntities from _dataEntities that are not existent in the current model
    for(auto it = _dataEntities.begin(); it != _dataEntities.end();) {
      if(entities.find(it->first) == entities.end()) {
        if(it->second.getNumRequested())
          _requestedListHasChanged = true;
        it = _dataEntities.erase(it);
      }
      else {
        ++it;
      }
    }
  }
}

void Plug::DataSingleDimension::gatherValues(const Counts &counts, Measures &measures)
{
  size_t sz = counts.elToShow;
  size_t szOri = counts.geoFitToShow;
  if(_dim == 2)
    measures.dim2Elem = true;
  else
    measures.dim3Elem = true;
  measures.minJ.reserve(sz);
  measures.maxJ.reserve(sz);
  measures.minDisto.reserve(sz);
  measures.minAspect.reserve(sz);
  measures.elements.reserve(sz);
  measures.isOnCurvedGeo.reserve(sz);
  measures.minGFit.reserve(szOri);
  measures.maxGFit.reserve(szOri);
  measures.elementsGFit.reserve(szOri);
  measures.numInvalidElements = 0;
  measures.numInvertedElements = 0;
  for(auto &it : _dataEntities) {
    it.second.addValues(measures);
  }
}

// ======== DataEntity =========================================================
// =============================================================================

constexpr int F_NOTJAC = 1 << 0;
constexpr int F_NOTDISTO = 1 << 1;
constexpr int F_NOTASPECT = 1 << 2;
constexpr int F_NOTORI = 1 << 3;
constexpr int F_VISBL = 1 << 4;
constexpr int F_CURVNOTCOMP = 1 << 5;
constexpr int F_CURVED = 1 << 6;
constexpr int F_REQU = 1 << 7;

inline bool areBitsSet(unsigned char value, int mask)
{
  return (value & mask) == mask;
}

inline bool isBitSet(unsigned char value, int maskOneBit)
{
  return value & maskOneBit;
}

inline bool isBitUnset(unsigned char value, int maskOneBit)
{
  return !(value & maskOneBit);
}

inline void setBit(unsigned char &value, int maskOneBit)
{
  value |= maskOneBit;
}

inline void unsetBit(unsigned char &value, int maskOneBit)
{
  value &= ~maskOneBit;
}

size_t Plug::DataEntity::initialize(const Parameters::Computation &param)
{
  size_t cntRequestedChanged = 0;
  std::size_t num = _ge->getNumMeshElements();

  if(num && _ge->dim() == 2) {
    GFace *gf = _ge->cast2Face();
    SVector3 normal;
    if(gf->normalToPlanarMesh(normal, true)) {
      _normals = new fullMatrix<double>(1, 3);
      _normals->set(0, 0, normal[0]);
      _normals->set(0, 1, normal[1]);
      _normals->set(0, 2, normal[2]);
    }
  }
  if(_normals) {
    _normalsToPrint = fullMatrix<double>(_normals->size1(), 3);
    const double eps = 1e-3;
    for(int i = 0; i < _normals->size1(); ++i){
      for(int j = 0; j < 3; ++j) {
        double val = _normals->get(i, j);
        val = std::round(val / eps) * eps;
        _normalsToPrint(i, j) = val == 0.0 ? 0.0 : val;
      }
    }
  }
  // FIXME: implement if dim==1

  switch(_ge->dim()) {
  case 3:
    _isCurvedGeo = false;
    break;
  case 2:
  case 1:
  default:
    _isCurvedGeo = !_normals;
  }

  // Step 1: Get all elements present in GEntity
  std::vector<MElement *> elements;
  elements.reserve(num);
  for(auto i = 0; i < num; ++i) {
    elements.push_back(_ge->getMeshElement(i));
  }

  // Step 2: Reset data if needed
  bool resetData = !param.smartRecompute;
  if(param.smartRecompute) {
    if(num != _mapElemToIndex.size()) {
      resetData = true;
    }
    else {
      for(auto i = 0; i < num; ++i) {
        if(_mapElemToIndex.find(elements[i]) == _mapElemToIndex.end()) {
          resetData = true;
          break;
        }
      }
    }
  }
  if(resetData) {
    cntRequestedChanged += _numRequested;
    reset(num);
    add(elements);
  }

  // Step 3: Update flag isVisible if necessary
  if(param.onlyVisible) {
    for(const auto &it : _mapElemToIndex) {
      if(it.first->getVisibility())
        setBit(_flags[it.second], F_VISBL);
      else
        unsetBit(_flags[it.second], F_VISBL);
    }
  }

  // Step 4: Update flag isCurved if necessary
  if(param.onlyCurved) {
    for(const auto &it : _mapElemToIndex) {
      const std::size_t index = it.second;
      if(isBitSet(_flags[index], F_CURVNOTCOMP)) {
        bool isCurved = it.first->getIsCurved();
        unsetBit(_flags[index], F_CURVNOTCOMP);
        if(isCurved)
          setBit(_flags[index], F_CURVED);
        else
          unsetBit(_flags[index], F_CURVED);
      }
    }
  }

  // Step 4: Update flag isRequested
  int maskRequested = 0;
  if(param.onlyVisible) maskRequested |= F_VISBL;
  if(param.onlyCurved) maskRequested |= F_CURVED;

  for(auto &flag : _flags) {
    if(areBitsSet(flag, maskRequested)) {
      if(isBitUnset(flag, F_REQU)) {
        ++cntRequestedChanged;
        setBit(flag, F_REQU);
      }
    }
    else if(isBitSet(flag, F_REQU)) {
      ++cntRequestedChanged;
      unsetBit(flag, F_REQU);
    }
  }
  return cntRequestedChanged;
}

void Plug::DataEntity::count(const Parameters::Computation &param, Counts &counts)
{
  // Reset intern data
  _numRequested = 0;
  constexpr int metricsCount = 5;
  for(int i = 0; i < metricsCount; ++i)
    _numToCompute[i] = 0;

  // Count number of elements to compute
  if (!_isCurvedGeo && param.jacobian)
    _count(F_REQU | F_NOTJAC, _numToCompute[0]);
  if (_isCurvedGeo && param.jacobianOnCurvedGeo)
    _count(F_REQU | F_NOTJAC, _numToCompute[1]);
  if (param.disto)
    _count(F_REQU | F_NOTDISTO, _numToCompute[2]);
  if (param.aspect)
    _count(F_REQU | F_NOTASPECT, _numToCompute[3]);
  if (param.geofit && _isCurvedGeo)
    _count(F_REQU | F_NOTORI, _numToCompute[4]);

  for(int i = 0; i < metricsCount; ++i) {
    counts.elToCompute[i] += _numToCompute[i];
  }

  // Count number of elements to show
  _count(F_REQU, _numRequested);
  counts.elToShow += _numRequested;
  if(param.geofit && _isCurvedGeo)
    counts.geoFitToShow += _numRequested;

  // Count total number, number of visible and curved elements
  counts.totalEl += _mapElemToIndex.size();
  for(const auto &flag : _flags) {
    if(isBitSet(flag, F_VISBL)) ++counts.visibleEl;
  }
  _countCurved(counts.elCurvedComputed, counts.curvedEl);
}

void Plug::DataEntity::_countCurved(std::size_t &known, std::size_t &curved)
{
  for(const auto &flag : _flags) {
    if(isBitUnset(flag, F_CURVNOTCOMP)) {
      ++known;
      if(isBitSet(flag, F_CURVED)) ++curved;
    }
  }
}

void Plug::DataEntity::_count(unsigned char mask, std::size_t &cnt)
{
  for(const auto &flag : _flags) {
    if(areBitsSet(flag, mask))
      ++cnt;
  }
}

void Plug::DataEntity::computeJacDet(MsgProgressStatus &progress_status,
                                     bool onPlanar, bool onCurved)
{
  if(!_isCurvedGeo && !onPlanar) return;
  if(_isCurvedGeo && !onCurved) return;

  if(_ge->dim() == 2) {
    if(_normals) {
      _info(1, "   Surface %d: <|>Computing validity of %d elements, normal (%.3g, %.3g, %.3g)",
            _ge->tag(), _numToCompute[0], _normalsToPrint(0, 0),
            _normalsToPrint(1, 0), _normalsToPrint(2, 0));
    }
    else {
      _info(1, "   Surface %d: Computing validity of %d elements",
            _ge->tag(), _numToCompute[1]);
    }
  }
  else
    _info(1, "   Volume %d: Computing validity of %d elements",
          _ge->tag(), _numToCompute[0]);

  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTJAC)) {
      MElement *el = it.first;
      JacQual::minMaxJacobianDeterminant(el, _minJ[idx], _maxJ[idx], _normals);
      unsetBit(_flags[idx], F_NOTJAC);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::computeDisto(MsgProgressStatus &progress_status, bool considerAsValid)
{
  // FIXME update
  if(_ge->dim() == 2)
    _info(1, "   Surface %d: Computing Distortion quality of %d elements",
          _ge->tag(), _numToCompute[2]);
  else
    _info(1, "   Volume %d: Computing Distortion quality of %d elements",
          _ge->tag(), _numToCompute[2]);

  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTDISTO)) {
      MElement *el = it.first;
      if(!considerAsValid  && _minJ[idx] <= 0 && _maxJ[idx] >= 0) {
        _minDisto[idx] = 0;
      }
      else {
      // TODO: give unique normal if planar surface
        _minDisto[idx] = JacQual::minICNMeasure(el, true);
      }
      unsetBit(_flags[idx], F_NOTDISTO);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::computeAspect(MsgProgressStatus &progress_status, bool considerAsValid)
{
  // FIXME update
  if(_ge->dim() == 2)
    _info(1, "   Surface %d: Computing Aspect quality of %d elements",
          _ge->tag(), _numToCompute[3]);
  else
    _info(1, "   Volume %d: Computing Aspect quality of %d elements",
          _ge->tag(), _numToCompute[3]);

  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTASPECT)) {
      MElement *el = it.first;
      if(!considerAsValid  && _minJ[idx] <= 0 && _maxJ[idx] >= 0) {
        _minAspect[idx] = 0;
      }
      else {
      // TODO: give unique normal if planar surface
        _minAspect[idx] = JacQual::minIGEMeasure(el, true);
      }
      unsetBit(_flags[idx], F_NOTASPECT);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::computeGeoFit(GFace *gf, MElement *el, double minmaxO[2]) const
{
  double minmaxAng[2] = {std::numeric_limits<double>::max(),
                         std::numeric_limits<double>::min()};
  for(int i = 0; i < el->getNumPrimaryVertices(); ++i) {
    MVertex *vert = el->getVertex(i);
    MFaceN face = el->getHighOrderFace(0, 0, 0);
    double uGF, vGF, uRef, vRef, dummy;
    if(vert->getParameter(1, vGF)) {
      vert->getParameter(0, uGF);
      SPoint2 p(uGF, vGF);
      SVector3 normalGFace = gf->normal(p);
      el->getNode(i, uRef, vRef, dummy);
      SVector3 normalElem = face.normal(uRef, vRef);
      double ang = angle(normalElem, normalGFace);
      minmaxAng[0] = std::min(minmaxAng[0], ang);
      minmaxAng[1] = std::max(minmaxAng[1], ang);
    }
    // else if(vert->getParameter(0, uGE)) {
    //   GEdge *ge = dynamic_cast<GEdge *>(vert->onWhat());
    //   GPoint p = ge->point(uGE);
    //   gf->XYZtoUV(p.x(), p.y(), p.z(), uGF, uGE);
    // }
    else {
      _error(MP, "Cannot compute GeoFit for vertex %d", vert->getNum());
    }

    // for(int i = 0; i < el->getNumPrimaryVertices(); ++i) {
    //   MVertex *vert = el->getVertex(i);
    //   MFaceN face = el->getHighOrderFace(0, 0, 0);
    //   double uGE, uGF, vGF, uRef, vRef, dummy;
    //   if(vert->getParameter(1, vGF))
    //     vert->getParameter(0, uGF);
    //   else
    //     gf->XYZtoUV(vert->x(), vert->y(), vert->z(), uGF, vGF, 1.0);
    //   SPoint2 p(uGF, vGF);
    //   SVector3 normalGFace = gf->normal(p);
    //   el->getNode(i, uRef, vRef, dummy);
    //   SVector3 normalElem = face.normal(uRef, vRef);
    //   double ang = angle(normalElem, normalGFace);
    //   minmaxAng[0] = std::min(minmaxAng[0], ang);
    //   minmaxAng[1] = std::max(minmaxAng[1], ang);
    //   // else {
    //   //   _error(MP, "Cannot compute GeoFit for vertex %d", vert->getNum());
    //   // }
    // }
  }
  minmaxO[0] = 1 - minmaxAng[1] / M_PI * 2;
  minmaxO[1] = 1 - minmaxAng[0] / M_PI * 2;
}

void Plug::DataEntity::computeGeoFit(MsgProgressStatus &progress_status)
{
  if(_ge->dim() != 2) return;
  // FIXME update for
  if(_ge->dim() == 2)
    _info(1, "   Surface %d: Computing GeoFit quality of %d elements",
          _ge->tag(), _numToCompute[4]);
  // else
  //   _info(1, "   Volume %d: Computing GeoFit quality of %d elements",
  //         _ge->tag(), _numToCompute[2]);

  double minmaxO[2];
  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTORI)) {
      MElement *el = it.first;
      // FIXME: cast GFace can be cast GEdge
      computeGeoFit((GFace*)_ge, el, minmaxO);
      _minGFit[idx] = minmaxO[0];
      _maxGFit[idx] = minmaxO[1];
      unsetBit(_flags[idx], F_NOTORI);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::reset(std::size_t num)
{
  _mapElemToIndex.clear();
  _minJ.clear();
  _maxJ.clear();
  _minGFit.clear();
  _maxGFit.clear();
  _minDisto.clear();
  _minAspect.clear();
  _flags.clear();
  _minJ.reserve(num);
  _maxJ.reserve(num);
  _minGFit.reserve(num);
  _maxGFit.reserve(num);
  _minDisto.reserve(num);
  _minAspect.reserve(num);
  _flags.reserve(num);
}

void Plug::DataEntity::add(MElement *el)
{
  _mapElemToIndex[el] = _minJ.size();
  _minJ.push_back(std::numeric_limits<double>::max());
  _maxJ.push_back(std::numeric_limits<double>::min());
  _minGFit.push_back(std::numeric_limits<double>::max());
  _maxGFit.push_back(std::numeric_limits<double>::min());
  _minDisto.push_back(std::numeric_limits<double>::max());
  _minAspect.push_back(std::numeric_limits<double>::max());
  unsigned char flag = F_NOTJAC | F_NOTDISTO | F_NOTASPECT | F_NOTORI | F_CURVNOTCOMP;
  if (el->getVisibility()) setBit(flag, F_VISBL);
  _flags.push_back(flag);
}

void Plug::DataEntity::addValues(Measures &measures)
{
  for(auto &it : _mapElemToIndex) {
    std::size_t idx = it.second;
    if(isBitSet(_flags[idx], F_REQU))
    {
      measures.elements.push_back(it.first);
      measures.isOnCurvedGeo.push_back(_isCurvedGeo);
      if(isBitUnset(_flags[idx], F_NOTJAC)) {
        measures.minJ.push_back(_minJ[idx]);
        measures.maxJ.push_back(_maxJ[idx]);
      }
      if(isBitUnset(_flags[idx], F_NOTORI)) {
        measures.minGFit.push_back(_minGFit[idx]);
        measures.maxGFit.push_back(_maxGFit[idx]);
        measures.elementsGFit.push_back(it.first);
      }
      if(isBitUnset(_flags[idx], F_NOTDISTO))
        measures.minDisto.push_back(_minDisto[idx]);
      if(isBitUnset(_flags[idx], F_NOTASPECT))
        measures.minAspect.push_back(_minAspect[idx]);
    }
  }
}

// ======== Plugin: User Messages ==============================================
// =============================================================================

std::string formatNumber(size_t value) {
  std::ostringstream formatted;
  if (value < 10000) {
    // Normal output if below 10,000
    formatted << value;
  }
  else if (value < 1000000) {
    formatted << std::setprecision(3) << (value / 1000.0) << "k";
  }
  else if (value < 1000000000) {
    formatted << std::setprecision(3) << (value / 1000000.0) << "M";
  }
  else {
    formatted << std::setprecision(3) << (value / 1000000000.0) << "B";
  }
  return formatted.str();
}

bool Plug::_okToPrint(int asked)
{
  //       | _verbose  |
  // asked |-1 | 0 | 1 |
  // -------------------
  //   MP  | x | x | x | -> mandatory
  //    1  |   |   | x | -> help
  //    0  |   | x | x | -> normal
  //   -1  |   | x |   | -> alternative to help
  //   -2  | x |   |   | -> minimal

  return (asked == MP) ||
         (_verbose == 1 && asked >= 0) ||
         (_verbose == 0 && (asked == 0 || asked == -1)) ||
         (_verbose == -1 && asked == -2);
}

void Plug::_printMessage(void (*func1)(const char *, ...),
                         void (*func2)(bool, const char *, ...),
                         const char *format, va_list args, bool logStatusBar)
{
  char str[5000];
  vsnprintf(str, sizeof(str), format, args);

  // Define the maximum allowable length for a single line
  const size_t maxChunkSize = 80;

  // Look for "<|>" in the first 30 characters
  const char *delimiter = "<|>";
  const size_t delimiterLen = strlen(delimiter);
  char prefix[31] = ""; // Temporary space for the prefix (max 30 characters + null-terminator)

  char *delimiterPos = strstr(str, delimiter);
  if (delimiterPos != nullptr && delimiterPos < str + 30) {
    // Extract the prefix from the start of the string up to the delimiter
    size_t prefixLen = delimiterPos - str;
    strncpy(prefix, str, prefixLen);
    prefix[prefixLen] = '\0'; // Null-terminate the prefix

    // Remove the prefix and delimiter from `str`, leaving only the format message
    memmove(str, delimiterPos + delimiterLen, strlen(delimiterPos + delimiterLen) + 1); // +1 to copy the null terminator
  }

  size_t prefixLen = strlen(prefix);       // Measure the length of the prefix
  std::string subsequentPrefix(prefixLen, ' '); // Create a string with spaces for subsequent lines
  const char *subsequentPrefixCStr = subsequentPrefix.c_str();

  size_t len = strlen(str); // Length of the formatted message
  size_t offset = 0;
  bool isFirstLine = true;

  while (offset < len) {
    size_t availableSize = maxChunkSize - prefixLen;
    size_t end = offset;

    // Find where to split based on available size, spaces, or newlines
    while (end < len && end - offset < availableSize) {
      if (str[end] == '\n') {
        break; // Split at newline
      }
      ++end;
    }

    // If no newline is found and we're splitting by size, backtrack to the last space
    if (end < len && str[end] != '\n') {
      size_t tempEnd = end;
      while (tempEnd > offset && str[tempEnd] != ' ' && str[tempEnd] != '\n') {
        --tempEnd;
      }
      if (tempEnd > offset) {
        end = tempEnd; // Split at the last space or newline
      }
    }

    // Determine the chunk size and handle prefix
    size_t chunkSize = end - offset;
    char chunk[maxChunkSize + 1]; // +1 for null-terminator
    if (isFirstLine) {
      strncpy(chunk, prefix, prefixLen); // Add the first-line prefix
      strncpy(chunk + prefixLen, str + offset, chunkSize);
      chunk[prefixLen + chunkSize] = '\0'; // Null-terminate the chunk
    } else {
      strncpy(chunk, subsequentPrefixCStr, prefixLen); // Add the subsequent-line prefix
      strncpy(chunk + prefixLen, str + offset, chunkSize);
      chunk[prefixLen + chunkSize] = '\0'; // Null-terminate the chunk
    }

    // Call the function
    if(func2)
      func2(logStatusBar, "%s", chunk);
    else if(func1)
      func1("%s", chunk);


    // Move the offset to process the next chunk
    offset = end;
    if (offset < len && (str[offset] == '\n' || str[offset] == ' ')) {
      ++offset; // Skip the newline character
    }

    isFirstLine = false;
  }
}

void Plug::_info(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Info, nullptr, format, args);
  va_end(args);
}

void Plug::_warn(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Warning, nullptr, format, args);
  va_end(args);
}

void Plug::_error(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Error, nullptr, format, args);
  va_end(args);
}

void Plug::_status(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(nullptr, Msg::StatusBar, format, args, true);
  va_end(args);
}

void Plug::_statusBar(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::StatusGl, nullptr, format, args, false);
  va_end(args);
}

std::size_t Plug::_printElementToCompute(const Counts &cnt2D,
                                         const Counts &cnt3D) const
{
  std::size_t sum2D = 0, sum3D = 0;
  for (std::size_t x : cnt2D.elToCompute) sum2D += x;
  for (std::size_t x : cnt3D.elToCompute) sum3D += x;

  if(sum2D + sum3D == 0) return 0;

  _info(0, "-> Number of evaluations to perform:\n");
  _info(0, "   | %5s%11s%11s%11s%11s", "", "Validity+", "Disto", "Aspect", "GeoFit");
  if(sum2D)
    _info(0, "   | %5s%11s%11s%11s%11s", "2D:",
              formatNumber(cnt2D.elToCompute[0]+cnt2D.elToCompute[1]).c_str(),
              formatNumber(cnt2D.elToCompute[2]).c_str(),
              formatNumber(cnt2D.elToCompute[3]).c_str(),
              formatNumber(cnt2D.elToCompute[4]).c_str());

  if(sum3D)
    _info(0, "   | %5s%11s%11s%11s%11s", "3D:",
              formatNumber(cnt3D.elToCompute[0]+cnt3D.elToCompute[1]).c_str(),
              formatNumber(cnt3D.elToCompute[2]).c_str(),
              formatNumber(cnt3D.elToCompute[3]).c_str(),
              formatNumber(cnt3D.elToCompute[4]).c_str());

  return sum2D + sum3D;
}

void Plug::_guidanceNothingToCompute(Counts counts, bool check2D,
                                     bool check3D) const
{
  _info(1, "-> No element to compute");

  if (!counts.elToShow) {
    _info(-1, "-> Nothing to compute, nothing to show");
    _info(1, "   Nothing to show neither");

    if (counts.totalEl) {
      if (_param.compute.onlyVisible && counts.visibleEl == 0) {
        _warn(1, "   Option 'restrictToVisibleElements' is ON but no visible elements found");
      }
      else if (_param.compute.onlyCurved && counts.curvedEl == 0) {
        _warn(1, "   Option 'restrictToCurvedElements' is ON but no curved elements found");
      }
      else {
        _error(1, "   Unexpected state: should not be here");
      }
    }
    else { // Case where no elements found
      if (_dimensionPolicy == 0) {
        if (check2D) {
          if (_m->getNumFaces())
            _warn(1, "   No mesh has been found (in current model)");
          else
            _warn(1, "   No geometry has been found (in current model)");
        }
        else if(check3D) {
          _error(1, "   Unexpected state: should not be here with check3D==true");
          // ...because if _dimensionPolicy == 0, then check3D==true only if there are elements
        }
        else {
          _error(1, "   Unexpected state: should not be here with check3D==false");
          // ...because at least check2D or check3D should be true
        }
      }
      else if (_dimensionPolicy == -1) {
        if (_m->getNumRegions()) {
          _warn(0, "   Planned to check 2D mesh as option 'dimensionPolicy' "
                   "is -1, but no 2D mesh found.");
          _warn(0, "   3D geometry found, consider setting 'dimensionPolicy' "
                   "to 0");
        }
        else {
          if (_m->getNumFaces())
            _warn(1, "   No mesh has been found (in current model)");
          else
            _warn(1, "   No geometry has been found (in current model)");
        }
      }
      else if (_dimensionPolicy >= 1) {
        if (_m->getNumFaces() + _m->getNumRegions())
          _warn(1, "   No mesh has been found (in current model)");
        else
          _warn(1, "   No geometry has been found (in current model)");
      }
      else {
        _error(1, "   Unexpected state: should not be here");
      }
    }
  }
}

// ======== struct Counts ======================================================
// =============================================================================

Plug::Counts Plug::Counts::operator+(const Counts &other) const
{
  Counts result;

  constexpr int metricsCount = 5;
  for (int i = 0; i < metricsCount; ++i) {
    result.elToCompute[i] = elToCompute[i] + other.elToCompute[i];
  }

  result.elToShow = elToShow + other.elToShow;
  result.geoFitToShow = geoFitToShow + other.geoFitToShow;
  result.totalEl = totalEl + other.totalEl;
  result.elCurvedComputed = elCurvedComputed + other.elCurvedComputed;
  result.curvedEl = curvedEl + other.curvedEl;
  result.visibleEl = visibleEl + other.visibleEl;

  return result;
}

// ======== struct Measures ====================================================
// =============================================================================

template <typename T>
static void combineVectors(std::vector<T> &result, const std::vector<T> &v1, const std::vector<T> &v2)
{
  result.clear();
  result.reserve(v1.size() + v2.size());
  result.insert(result.end(), v1.begin(), v1.end());
  result.insert(result.end(), v2.begin(), v2.end());
}

Plug::Measures Plug::Measures::combine(const Measures &m1, const Measures &m2, const char *name, const char *shortName)
{
  Measures result;
  combineVectors(result.minJ, m1.minJ, m2.minJ);
  combineVectors(result.maxJ, m1.maxJ, m2.maxJ);
  combineVectors(result.ratioJ, m1.ratioJ, m2.ratioJ);
  combineVectors(result.isValid, m1.isValid, m2.isValid);
  combineVectors(result.isInverted, m1.isInverted, m2.isInverted);
  combineVectors(result.isOnCurvedGeo, m1.isOnCurvedGeo, m2.isOnCurvedGeo);
  combineVectors(result.minDisto, m1.minDisto, m2.minDisto);
  combineVectors(result.minAspect, m1.minAspect, m2.minAspect);
  combineVectors(result.minGFit, m1.minGFit, m2.minGFit);
  combineVectors(result.maxGFit, m1.maxGFit, m2.maxGFit);
  combineVectors(result.elements, m1.elements, m2.elements);
  combineVectors(result.elementsGFit, m1.elementsGFit, m2.elementsGFit);
  combineVectors(result.elementsStraightGeo, m1.elementsStraightGeo, m2.elementsStraightGeo);
  result.dim2Elem = m1.dim2Elem || m2.dim2Elem;
  result.dim3Elem = m1.dim3Elem || m2.dim3Elem;
  result.dimStr = name;
  result.dimStrShort = shortName;
  result.numInvalidElements = m1.numInvalidElements + m2.numInvalidElements;
  result.numInvertedElements = m1.numInvertedElements + m2.numInvalidElements;
  for(int i = 0; i < 7; ++i) {
    result.sizes[i] = m1.sizes[i] + m2.sizes[i];
  }
  return result;
}

const std::vector<double> &Plug::Measures::getValues(Metric m) const
{
  switch(m) {
  case VALIDITY:
    return isValid;
  case INVERSION:
    return isInverted;
  case GEOFIT:
    return minGFit;
  case DISTO:
    return minDisto;
  case ASPECT:
    return minAspect;
  case MINJAC:
    return minJ;
  case RATIOJAC:
    return ratioJ;
  default:
    _error(0, "Invalid metric");
  }
  return maxJ; // to avoid compiler warning
}

const std::vector<MElement *> &Plug::Measures::getElements(Metric m) const
{
  if(m == GEOFIT)
    return elementsGFit;
  if(m == VALIDITY)
    return elementsStraightGeo;
  return elements;
}

#endif
