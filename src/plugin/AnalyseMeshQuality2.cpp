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
#include <cmath>
#include "AnalyseMeshQuality2.h"
#include "OS.h"
#include "Context.h"
#include "PView.h"
#include "PViewOptions.h"
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
//  xx Small changes:
//     x distortion -> disto
//     x requested element -> selected elements
//  xx Test plot such that first element take same place, like 1/50
//     -> If choose to stay at fixed cutoff determine which cutoff to choose for
//        which number of element
//  xx Move info how to read plot at execution. Say in important notes that
//     Help does not cover all information and it is adviced to set
//     guidanceLevel=1 at the beginning to have contextual more complete info
//  xx Update metrics info
//  5. Make option name starting with upper case because it is the convention
//  6. Choose what to do with WW-G/M. Options are:
//     - As current: user choose and can have multiple cutoff. Adviced 25, 10, 2
//     - As current: plugin choose, user can give preference between 25, 10, 2
//                   so that the plugin can decide when superposition.
//     - As current: plugin choose if user set wwmCutOff to 0 (which made
//                   the default).
//     - Fixed weigth worst: the idea is that the worst value count for the
//                           same weight whatever the number of values.
//                           This weight can be a parameter
//                           The cutoff depend on the number of values.
//                Advantage: On graph, this is comfortable for looking at
//                           minimum value (with 3~5% worst-weight).
//                           Easier for the user, he do not have to choose.
//                           Can still change parameter if not happy.
//             Disadvantage: The x-axis of graph is changing for every value
//                           count, which is a bit anoying visually.
//      Unresolved question: How comparison between mesh of different element
//                           count is affected?
//             Idea to test: compare 3~4 simulated mesh of different size.
//                           Values are 1 except N that are 0. N is either
//                           certain percentage of total value count or a
//                           certain number of element. Look at graph and wwm.

// TODO Finalization:
//  1. Check fixmes, todos, etc.
//  2. Check english
//  3. Merge master + Clang format
//  4. Test with ctest that everything works?
//  5. Update `What does the plugin'


// TODO Later:
//  1. Add check + message after having fetched parameters
//     - If guidance = 1: output what will be done
//       if guidance = 0: output what will computed
//     - If guidance = 1: warn when parameters out of bound
//  2. Add validity for MLine on GEdge
//     - minJ/maxJ can be considered as a quality measure
//     - if dimension policy=-2?
//     - also GeoFit
//  3. Add after computation metrics "(Wall %gs, CPU %gs)" (like in first version)
//  4. Option to add data as time step in plots (and element view?)

// TODO Maybe:
//  1. Intrinsic validity : smartreco777 for sharing element or 888 or 999
//  2. Demo mode?
//  3. Disable keep data? (dataReleasePolicy=1)
//  4. If computed from scripts, we have `Running Plugin(AnalyseMeshQuality)...'
//     then `Executing the plugin AnalyseMeshQuality...'.
//     -> If it is possible to know that in script or from GUI, then have
//     print _info(Executing the plugin AnalyseMeshQuality... conditionnally
//  6. A tuto? (with at the end the list of options and tooltips as comment)
//     -> in which case say in getting started that this exists
//     -> a ball with a hole and BL would be perfectly fine: element touching
//        inner boundary being much more curved than element touching external
//        boundary
//  7. Add after validity, in presence of curved geometry entities:
//     "Among curved surfaces/edges, there are x potentially invalid elements,
//     and y flipped elements?
//  8. Set plot color to loop over different set of uniform colormap
//     (same color for each value)?
//  9. Print info "why no view" when no view created (if verbose)?
//  10. Revise tooltips as \n can be used?
//  11. Add option to limit views to subset of element?
//      -> using new options or hiding options
//      -> or not, can be done by running the plugin multiple time!
//      -> tuto with geofit?
//  12. Print different info at execution for GeoFit (and JacDet) in function of
//      regularization or not
//      -> If regu: then GeoFit >= a means valid, [-a, a] invalid
//      -> If notRegu: then GeoFit >= a means valid, [-a, a] invalid, <a flipped
//  13. Add to FAQ?:
//      - How the plugin decide to create views or not
//  14. Add verbose message for stats on selected elements if verbose==1?



// FIXME: PView are based on elements. If I remesh with a different mesh size
//  factor, data is still there but on wrong elements.

// NOTE What does the plugin
//  0. Free data and stop IF dataReleasePolicy = -1
//  TODO:
//   Split step 1 into two steps:
//    1a. Set selected element, determine requested metrics, Prominent metrics
//    1b. Compute missing data
//    2. Print stats for available metrics on selected elements
//  1. Compute validity/quality IF omitMetricsComputation = OFF
//   • Limit to GEntity in GModel::current()
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 meshes
//     - IF = 0 Limit to dimension 3 meshes IF there is any 3D mesh OTHERWISE
//              limit to dimension 2 meshes
//     - IF >= 1 do not limit (both dimension 2 and 3 meshes)
//   • Clear old entities IF dataReleasePolicy = 0
//   • Check if previous data can be reused IF smartRecomputation = ON
//   • Limit to visible elements IF restrictToVisibleElements = ON
//   • Limit to curved elements IF restrictToCurvedElements = ON
//   • Compute Validity IF skipValidity <= 0
//   • Compute Disto IF enableDistoQuality > 0
//   • Compute Aspect IF enableAspectQuality > 0
//   • Regularize Jacobian IF skipValidity <= 0 AND treatFlippedAsValid = ON
//  2. Print statistics
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 data
//     - IF = 0 Limit to dimension 3 data IF there is any 3D mesh OTHERWISE
//              limit to dimension 2 data
//     - IF = 1 do not limit (dimension 2 and 3 data separately)
//     - IF = 2 combine dimension 2 and 3 data
//   • In columns: min, max and Worst Weighted Means of UNPACK(wmCutoffsForStats)
//   • Disto IF enableDistoQuality > 0
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
//   • Let M = max(-skipValidity, enableDistoQuality, enableAspectQuality, enableRatioJacDetAsAMetric, enableMinJacDetAsAMetric)
//   • Validity IF skipValidity = -M
//   • Disto IF enableDistoQuality = M
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
  constexpr double MP = 9; // mandatory print
  constexpr double NOTCOMPUTED = -987654321;
}

StringXNumber MeshQuality2Options_Number[] = {
  // Quality metrics to include:
  {GMSH_FULLRC, "enableDistoQuality", nullptr, 2, "OFF, (1+)=includeDistoQuality"},
  {GMSH_FULLRC, "enableAspectQuality", nullptr, 0, "OFF, (1+)=includeAspectQuality"},
  {GMSH_FULLRC, "enableGeoFitQuality", nullptr, 1, "OFF, (1+)=includeGeofitQuality (experimental)"},
  // What to do:
  {GMSH_FULLRC, "createElementsView", nullptr, 0, "OFF, ON"},
  {GMSH_FULLRC, "createPlotView", nullptr, 1, "OFF, ON"},
  {GMSH_FULLRC, "adjustElementsVisibility", nullptr, 0, "OFF, 1=skipIfAllWouldBeHidden, 2=acceptAllHidden"}, //TODO updtate for geofit
  {GMSH_FULLRC, "guidanceLevel", nullptr, 2, "(-1)=minimalOutput, 0=verbose, 1=verboseAndExplanations, 2=printDetailsOnMetricsAndSkipExecution"},
  // Elements Selection:
  {GMSH_FULLRC, "dimensionPolicy", nullptr, 0, "(-2)=force2D, (-1)=force1D, 0=prioritize3D, 1=2D+3D, 2=combine2D+3D"},
  {GMSH_FULLRC, "restrictToElementType", nullptr, 0, "OFF, 1=Tri/Tet, 2=Quad/Hex, 3=Prism/Pyr"},
  {GMSH_FULLRC, "restrictToVisibleElements", nullptr, 0, "OFF, ON=analyzeOnlyVisibleElements"},
  {GMSH_FULLRC, "restrictToCurvedElements", nullptr, 0, "OFF, ON=analyzeOnlyNonStraightElements"},
  // Hiding options:
  {GMSH_FULLRC, "visibilityPolicy", nullptr, 0, "(-1)=validity|skip, 0=validity|1, 1=qualOR, 2=qualAND"},
  {GMSH_FULLRC, "visibilityCriterion", nullptr, 0, "0=proportionVisibleElem, 1=numVisibleElem, 2=metricValue"},
  {GMSH_FULLRC, "visibilityThreshold", nullptr, 10, "DOUBLE (which meaning depends on visibilityCriterion)"},
  {GMSH_FULLRC, "hideWorstElements", nullptr, 0, "OFF=hideBestElements, ON"},
  {GMSH_FULLRC, "doNoSetVisible", nullptr, 0, "OFF=performHidingAndUnhiding, ON=justPerformHiding"},
  // Advanced computation options:
  {GMSH_FULLRC, "dataReleasePolicy ", nullptr, 0, "(-1)=freeDataAndSkipExecution, 0=freeOldDataIfGeoEntityAbsent, 1=keepAllData"},
  {GMSH_FULLRC, "omitMetricsComputation", nullptr, 0, "OFF, ON=usePreviousData"},
  {GMSH_FULLRC, "smartRecomputation", nullptr, 0, "OFF=alwaysRecompute, ON=avoidRecomputeIfUnchangedElementTags"},
  {GMSH_FULLRC, "skipValidity", nullptr, 0, "(0-)=includeValidity, (1+)=skipPreventiveValidityCheck"},
  // Advanced analysis options:
  {GMSH_FULLRC, "treatFlippedAsValid", nullptr, 0, "(-1)=never, 0=forCurvedGeo (alter GeoFit), 1=always (also alter minJ and minJ/maxJ)"},
  {GMSH_FULLRC, "enableMinJacDetAsAMetric", nullptr, 0, "OFF, 1+ (Validity must be computed)"},
  {GMSH_FULLRC, "enableRatioJacDetAsAMetric", nullptr, 0, "OFF, 1+ (Validity must be computed)"},
  {GMSH_FULLRC, "skipStatPrinting", nullptr, 0, "OFF, ON"},
  {GMSH_FULLRC, "wmCutoffsForStats", nullptr, 21025, "CUTOFFS (for stats weighted mean, see Help)"},
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
  {3, "What to do"},
  {7, "Elements selection"},
  {11, "Visibility adjustment options"},
  {16, "Advanced computation options"},
  {20, "Advanced analysis options"},
  {26, "Legacy options"},
};

namespace JacQual = jacobianBasedQuality;
using Plug = GMSH_AnalyseMeshQuality2Plugin;
int Plug::_verbose = 0;
const std::array<std::string, 7> Plug::_metricNames = {
  "Validity", "Unflip", "GeoFit", "Disto", "Aspect", "MinJ/maxJ", "MinJac"
};

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
  return
    _getHelpIntro() + "\n" +
    _getHelpMetrics() + "\n" +
    _getHelpWWM() + "\n" +
    _getHelpOptionsClarification() + "\n" +
    _getHelpVisibility() + "\n" +
    _getHelpFAQ();
}

PView *Plug::execute(PView *v)
{
  // Fetch verbose option and display the plugin introduction
  _verbose = static_cast<int>(MeshQuality2Options_Number[6].def);
  _info(MP, "---------------------------------------------");
  _status(0, "Executing the plugin AnalyseMeshQuality...");

  // std::vector<double> values;
  // const int num = 6;
  // const int listN[num] = {100, static_cast<int>(1e4), static_cast<int>(2e3), static_cast<int>(5e6), static_cast<int>(5e5), static_cast<int>(1e8)};
  // const double listC[num] = {25, 25, 10, 10, 2, 2};
  // int num2 = 6;
  //
  // for(int k = 0; k < num2; k++) {
  //   const int N = listN[k];
  //   const double cutoff = listC[k];
  //   values.clear();
  //   values.reserve(N);
  //   for(int i = 0; i < N; i++)
  //     values.push_back(static_cast<double>(i) / static_cast<double>(N-1));
  //   values[0] = -1;
  //   PView *p = new PView("Test", cutoff, true, values);
  // }
  //
  // return v;

  //
  // // Option 1: Fixed
  //
  // std::vector<double> values;
  // const int num = 4;
  // const int listN[num] = {static_cast<int>(1e2), static_cast<int>(1e4), static_cast<int>(1e6), static_cast<int>(1e8)};
  // const double listC[num] = {25, 10, 10, 2};
  // int num2 = 4;
  //
  // for(int k = 0; k < num2; k++) {
  //   const int N = listN[k];
  //   const double cutoff = listC[k];
  //   values.clear();
  //   values.reserve(N);
  //   for(int i = 0; i < N; i++)
  //     values.push_back(static_cast<double>(i) / static_cast<double>(N-1));
  //   values[0] = -1;
  //   PView *p = new PView("Test", cutoff, true, values);
  // }
  //
  // // Option 2: Width 1st element = 5 %
  //
  // // const int listN[num] = {static_cast<int>(1e3), static_cast<int>(1e4), static_cast<int>(1e5), static_cast<int>(1e6)};
  // // const double listC2[num] = {20.22, 11.87, 6.97, 4.09};
  // // const int listN[num] = {static_cast<int>(1e2), static_cast<int>(1e4), static_cast<int>(1e6), static_cast<int>(1e7)};
  // // const double listC2[num] = {34.45, 11.87, 4.09, 2.40};
  // // const int listN[num] = {static_cast<int>(1e2), static_cast<int>(1e4), static_cast<int>(1e6), static_cast<int>(1e8)};
  // const double listC2[num] = {34.45, 11.87, 4.09, 1.40};
  //
  // for(int k = 0; k < num2; k++) {
  //   const int N = listN[k];
  //   const double cutoff = listC2[k];
  //   values.clear();
  //   values.reserve(N);
  //   for(int i = 0; i < N; i++)
  //     values.push_back(static_cast<double>(i) / static_cast<double>(N-1));
  //   values[0] = -1;
  //   PView *p = new PView("Test", cutoff, true, values);
  // }
  //
  // return v;

  // Fetch the other parameters and check options that may cause an early exit
  bool unhandledOptions= !_fetchParameters();
  bool earlyExit = _checkEarlyExitOptions();
  if (unhandledOptions || earlyExit) {
    _info(MP, "Nothing (else) to do, re-run the plugin to analyze a mesh");
    return v;
  }

  // Check if this is a new model and warn about clearing data
  GModel *m = GModel::current();
  Parameters::Computation &pc = _param.compute;
  if(pc.freeOldData && _m && _m != m) {
    _warn(1, "-> <|>Detected a new model. Previous data will be cleared "
             "(set 'dataReleasePolicy' to 1 to prevent this)");
    _info(-1, "-> <|>Detected a new model. Previous data will be cleared "
              "(set 'dataReleasePolicy' to 1 to prevent this)");
    // FIXME may not be the case (can we create a new model with exact same geometry and mesh?)
    // FIXME Do I really need this?
  }
  _m = m;

  // Check which dimension to compute/show
  bool check2D, check3D;
  _decideDimensionToCheck(check2D, check3D);

  // Update selected element list and counts elements
  Counts counts2D, counts3D;
  if(check2D) _data2D->syncWithModel(_m, _param.compute, counts2D);
  if(check3D) _data3D->syncWithModel(_m, _param.compute, counts3D);
  Counts countsTotal = counts2D + counts3D;

  // Purge views after calling syncWithModel and before the plugin exits
  _purgeViews(check2D, check3D);

  // Handle the case where there are no selected elements or print number
  if(!countsTotal.reqElem) {
    _guidanceNoSelectedElem(countsTotal, check2D, check3D);
    return v;
  }
  _info(MP, "-> Selected %s elements for analysis",
    formatNumber(countsTotal.reqElem).c_str());

  // Print the number of value to compute
  // - If nothing to compute, check data availability for output.
  // - Otherwise, warn about computing quality without validity checks.
  std::size_t totalToCompute = _printElementToCompute(counts2D, counts3D);
  if(!totalToCompute) {
    if(!_checkAndGuideNoDataToShow(countsTotal, check2D, check3D))
      return v;
  }
  else if(!pc.jacobian && countsTotal.distoOrAspectToComputeButUnknownValidity){
    _warn(1, "-> <|>Validity computation is disabled (option 'skipValidity' "
             "is ON). This may significantly slow down quality computation "
             "in the presence of invalid elements");
    _warn(-1, "-> <|>There are quality metrics to compute without in the "
              "absence of preventive validity check");
  }

  // Launch computation
  _computeRequestedData(countsTotal, check2D, check3D);

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

  // Output 1: Print statistics
  _param.check2D = check2D;
  _param.check3D = check3D;
  _statGen->printStats(_param, measures);

  // Output 2: Create plots
  _createPlots(measures);

  // Output 3: Create Element views
  _createElementViews(measures);

  // Output 4: Hide elements
  if(_performHiding(measures)) {
    CTX::instance()->mesh.changed = ENT_ALL;
#if defined(HAVE_OPENGL)
    drawContext::global()->draw();
#endif
  }

  // Say goodbye
  _info(0, "Done executing Plugin AnalyseMeshQuality");
  _info(1, "(Set guidanceLevel to 0 or -1 to reduce verbosity)");
  return v;
}

// ======== Plugin: private methods ============================================
// =============================================================================

bool Plug::_fetchParameters()
{
  Parameters::Computation &pc = _param.compute;
  Parameters::Post &pp = _param.pview;
  Parameters::Hiding &ph = _param.hide;
  Parameters::MetricsToShow &ps = _param.show;

  double skipValidity, disto, aspect, geofit, minJ, ratioJ, elementType,
   dataReleasePolicy;

  // Metrics to include:
  disto = MeshQuality2Options_Number[0].def;
  aspect = MeshQuality2Options_Number[1].def;
  geofit = MeshQuality2Options_Number[2].def;

  // What to do:
  pp.createElemView = static_cast<bool>(MeshQuality2Options_Number[3].def);
  pp.createPlot = static_cast<bool>(MeshQuality2Options_Number[4].def);
  ph.todo = static_cast<int>(MeshQuality2Options_Number[5].def);
  // Change also 'Plug::_verbose = ..._Number[6].def' in execute method
  // and all other occurrences of MeshQuality2Options_Number

  // Elements Selection:
  _dimensionPolicy = static_cast<int>(MeshQuality2Options_Number[7].def);
  if(_dimensionPolicy == -1) {
    _error(MP, "   <|>Option 'dimensionPolicy' is set to -1 (force1D) but "
              "1D metrics are not yet implemented. Aborting. Please set "
              "'dimensionPolicy' to another value");
    return false;
  }
  elementType = MeshQuality2Options_Number[8].def;
  pc.onlyVisible = static_cast<bool>(MeshQuality2Options_Number[9].def);
  pc.onlyCurved = static_cast<bool>(MeshQuality2Options_Number[10].def);

  // Visibility options:
  ph.policy = static_cast<int>(MeshQuality2Options_Number[11].def);
  ph.criterion = static_cast<int>(MeshQuality2Options_Number[12].def);
  ph.threshold = MeshQuality2Options_Number[13].def;
  ph.worst = static_cast<bool>(MeshQuality2Options_Number[14].def);
  ph.unhideToo = !static_cast<bool>(MeshQuality2Options_Number[15].def);

  // Advanced computation options:
  dataReleasePolicy = static_cast<int>(MeshQuality2Options_Number[16].def);
  pc.skip = static_cast<bool>(MeshQuality2Options_Number[17].def);
  pc.smartRecompute = static_cast<bool>(MeshQuality2Options_Number[18].def);
  skipValidity = MeshQuality2Options_Number[19].def;

  // Advanced analysis options:
  ps.regularizeJac = MeshQuality2Options_Number[20].def > 0;
  ps.regularizeGFit = MeshQuality2Options_Number[20].def > -1;
  minJ = MeshQuality2Options_Number[21].def;
  ratioJ = MeshQuality2Options_Number[22].def;
  ps.skipStats = static_cast<bool>(MeshQuality2Options_Number[23].def);
  pp.statCutoffPack = MeshQuality2Options_Number[24].def;
  pp.plotCutoffPack = MeshQuality2Options_Number[25].def;

  // -> statsGenerator
  _statGen->setCutoffStats(pp.statCutoffPack);
  _statGen->setCutoffPlots(pp.plotCutoffPack);

  // -> data management
  _previousFreeOldData = pc.freeOldData;
  _param.freeData = dataReleasePolicy == -1;
  pc.freeOldData = dataReleasePolicy <= 0;

  // -> metrics to compute
  pc.jacobian = skipValidity <= 0;
  pc.jacobianOnCurvedGeo = ratioJ > 0 || minJ > 0;
  pc.disto = static_cast<bool>(disto);
  pc.aspect = static_cast<bool>(aspect);
  pc.geofit = static_cast<bool>(geofit);

  // -> elementType
  pc.onlyGivenElemType = false;
  if(elementType > 0) {
    pc.onlyGivenElemType = true;
    int elemType = static_cast<int>(elementType);
    for(int i = 0; i < TYPE_MAX_NUM; ++i) pc.acceptedElemType[i] = 0;
    switch(elemType) {
    case 1:
      pc.acceptedElemType[TYPE_TRI] = pc.acceptedElemType[TYPE_TET] = true;
      break;
    case 2:
      pc.acceptedElemType[TYPE_QUA] = pc.acceptedElemType[TYPE_HEX] = true;
      break;
    case 3:
      pc.acceptedElemType[TYPE_PYR] = pc.acceptedElemType[TYPE_PRI] = true;
      break;
    default:
      _error(MP, "   <|>Option 'elementType' is set to %d but this value does "
      "not correspond to an accepted element type", elemType);
      pc.onlyGivenElemType = false;
      return false;
    }
  }

  // -> metrics to show
  ps.which[VALIDITY] = skipValidity == 0 ? -1 : skipValidity > 0 ? 0 : -static_cast<int>(skipValidity);
  ps.which[DISTO] = static_cast<int>(disto);
  ps.which[ASPECT] = static_cast<int>(aspect);
  ps.which[MINJAC] = static_cast<int>(minJ);
  ps.which[RATIOJAC] = static_cast<int>(ratioJ);
  ps.which[GEOFIT] = static_cast<int>(geofit);
  ps.which[UNFLIP] = ps.which[VALIDITY] && !ps.regularizeJac;
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

  return true;
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

  _warn(MP, "-> <|>Deprecated options detected. The plugin will execute using "
             "the legacy configuration and ignore new options.");
  _warn(MP, "   <|>Please update the deprecated options to their modern "
            "counterparts.");
  _info(0, "-> <|>Use the following changes to map the options and achieve "
           "equivalent results:\n"
           " 1. Set 'skipComputationMetrics' to 1 IF '_Recompute' is 0\n"
           " 2. Set 'createElementsView' to '_CreateView'\n"
           " 3. Set 'enableDistoQuality' to 1 IF '_ICNMeasure' is not 0\n"
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
           "    -  Set 'enableDistoQuality' to 2 IF "
           "'enableDistoQuality' is 1\n"
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
  pc.onlyGivenElemType = false;
  pc.onlyVisible = false;
  pc.onlyCurved = false;
  pp.statCutoffPack = 50;
  pp.createPlot = false;
  ps.which[UNFLIP] = 0;
  ps.which[GEOFIT] = 0;
  ps.which[RATIOJAC] = 1;
  ps.which[MINJAC] = 1;
  ps.regularizeJac = false;
  ps.regularizeGFit = false;
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

bool Plug::_checkEarlyExitOptions()
{
  bool exit = false;

  // Print detailed metrics if requested
  if(_verbose == 2) {
    size_t which[METRIC_COUNT];
    std::fill(std::begin(which), std::end(which), 1);
    _printDetailsMetrics(which, true);
    MeshQuality2Options_Number[6].def = 1;
    _info(MP, "-> Option 'guidanceLevel' has been set to 1");
    exit = true;
  }

  // Free allocated data if requested
  if(_param.freeData) {
    _info(-2, "-> Freeing data...");
    _info(-1, "-> Freeing data...");
    _info(1, "-> Freeing data... (because option 'dataReleasePolicy' is -1)");
    _data2D->clear();
    _data3D->clear();
    MeshQuality2Options_Number[16].def = !_previousFreeOldData;
    _info(0, "   Done.");
    _info(MP, "-> Option 'dataReleasePolicy' has been reset");
    exit = true;
  }

  // Check if at least one metric is requested
  Parameters::MetricsToShow ps = _param.show;
  int sum = 0;
  for(int i = 0; i < METRIC_COUNT; i++) {
    sum += std::abs(ps.which[i]);
  }
  if(!sum) {
    _error(MP, "-> No metric to analyze. Please adjust the following options:\n");
    _info(MP, "   <|>"
              "- Turn ON at least one of the following metrics:\n"
              "  * enableDistoQuality\n"
              "  * enableAspectQuality\n"
              "  * enableGeoFit\n"
              "  * enableMinJacDetAsAMetric\n"
              "  * enableRatioJacDetAsAMetric\n"
              "- OR set 'skipValidity' to 0");
    exit = true;
  }

  return exit;
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
  if(purge2D && _data2D->getSelectedListHasChanged()) {
    for (auto it = _pviews.begin(); it != _pviews.end(); ) {
      if(it->first.dim2Elem)
        it = _pviews.erase(it);
      else
        ++it;
    }
  }
  if(purge3D && _data3D->getSelectedListHasChanged()) {
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
  if(check2D) _data2D->getDataEntities(allDataEntities);
  if(check3D) _data3D->getDataEntities(allDataEntities);

  if(counts.metricValsToCompute[0] > 0 || counts.metricValsToCompute[1] > 0) {
    _status(0, "-> Computing Validity+...");
    MsgProgressStatus progress_status(static_cast<int>(counts.metricValsToCompute[0] + counts.metricValsToCompute[1]));
    for(auto data: allDataEntities) {
      data->computeJacDet(progress_status, counts.metricValsToCompute[0], counts.metricValsToCompute[1]);
    }
  }

  if(counts.metricValsToCompute[2] > 0) {
    _status(0, "-> Computing GeoFit...");
    MsgProgressStatus progress_status(static_cast<int>(counts.metricValsToCompute[2]));
    for(auto data: allDataEntities) {
      data->computeGeoFit(progress_status);
    }
  }

  if(counts.metricValsToCompute[3] > 0) {
    _status(0, "-> Computing Disto quality...");
    MsgProgressStatus progress_status(static_cast<int>(counts.metricValsToCompute[3]));
    for(auto data: allDataEntities) {
      data->computeDisto(progress_status, !_param.compute.jacobian);
    }
  }

  if(counts.metricValsToCompute[4] > 0) {
    _status(0, "-> Computing Aspect quality...");
    MsgProgressStatus progress_status(static_cast<int>(counts.metricValsToCompute[4]));
    for(auto data: allDataEntities) {
      data->computeAspect(progress_status, !_param.compute.jacobian);
    }
  }

  _status(0, "-> Done computing data");
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
    for(int i = 0; i < METRIC_COUNT; ++i) m.numToShow[i] = 0;

    if(ps.regularizeJac) {
      for(std::size_t i = 0; i < m.minJ.size(); i++) {
        if(m.maxJ[i] != NOTCOMPUTED && std::abs(m.minJ[i]) > std::abs(m.maxJ[i])) {
          std::swap(m.minJ[i], m.maxJ[i]);
          m.minJ[i] *= -1;
          m.maxJ[i] *= -1;
        }
      }
    }

    if(ps.regularizeGFit) {
      for(std::size_t i = 0; i < m.minGFit.size(); i++) {
        if(m.maxGFit[i] != NOTCOMPUTED && std::abs(m.minGFit[i]) > std::abs(m.maxGFit[i])) {
          std::swap(m.minGFit[i], m.maxGFit[i]);
          m.minGFit[i] *= -1;
          m.maxGFit[i] *= -1;
        }
      }
    }

    if(ps.which[VALIDITY] || ps.which[UNFLIP]) {
      size_t num = m.elements.size()-m.elementsGFit.size();
      m.elementsStraightGeo.resize(num);
      if(ps.which[VALIDITY]) m.isValid.resize(num);
      if(ps.which[UNFLIP]) m.isNotFlipped.resize(num);

      size_t k = -1;
      for(std::size_t i = 0; i < m.minJ.size(); i++) {
        if(m.isOnCurvedGeo[i]) continue;

        m.elementsStraightGeo[++k] = m.elements[i];

        if(m.maxJ[i] == NOTCOMPUTED) {
          if(ps.which[VALIDITY]) m.isValid[k] = NOTCOMPUTED;
          if(ps.which[UNFLIP]) m.isNotFlipped[k] = NOTCOMPUTED;
          continue;
        }

        if(ps.which[VALIDITY]) {
          bool valid = isValid(m.minJ[i], m.maxJ[i]);
          m.isValid[k] = valid;
          ++m.numToShow[VALIDITY];
          if(!valid) ++m.numInvalidElements;
        }

        if(ps.which[UNFLIP]) {
          bool flipped = m.maxJ[i] < 0;
          m.isNotFlipped[i] = !flipped;
          ++m.numToShow[UNFLIP];
          if(flipped) ++m.numFlippedElements;
        }
      }
    }

    if(_param.show.which[RATIOJAC]) {
      m.ratioJ.resize(m.minJ.size());
      for(std::size_t i = 0; i < m.minJ.size(); i++) {
        if(m.maxJ[i] != NOTCOMPUTED) {
          m.ratioJ[i] = m.minJ[i] / m.maxJ[i];
          ++m.numToShow[RATIOJAC];
        }
        else
          m.ratioJ[i] = NOTCOMPUTED;
      }
    }

    if(_param.show.which[MINJAC]) {
      for(size_t i = 0; i < m.minJ.size(); i++) {
        if(m.minJ[i] != NOTCOMPUTED) ++m.numToShow[MINJAC];
      }
    }
    else
      m.minJ.clear();
    m.maxJ.clear();

    if(_param.show.which[DISTO]) {
      for(size_t i = 0; i < m.minDisto.size(); i++) {
        if(m.minDisto[i] != NOTCOMPUTED) ++m.numToShow[DISTO];
      }
    }

    if(_param.show.which[ASPECT]) {
      for(size_t i = 0; i < m.minAspect.size(); i++) {
        if(m.minAspect[i] != NOTCOMPUTED) ++m.numToShow[ASPECT];
      }
    }

    if(_param.show.which[GEOFIT]) {
      for(size_t i = 0; i < m.minGFit.size(); i++) {
        if(m.minGFit[i] != NOTCOMPUTED) ++m.numToShow[GEOFIT];
      }
    }
    m.maxGFit.clear();
  }
}

void Plug::_createPlots(const std::vector<Measures> &measures)
{
  if(!_param.pview.createPlot) return;

  int numPlots = 0;
  Parameters::MetricsToShow &ps = _param.show;
  for(const auto &m: measures) {
    for(int i = VALIDITY; i <= ASPECT; i++) {
      if(ps.which[i] == ps.M) {
        if(_createPlotsOneMetric(m, static_cast<Metric>(i)))
          ++numPlots;
      }
    }
  }

  if(numPlots) {
    _info(MP, "-> Created %d plots", numPlots);
    _info(1, "   <|>Here is how to interpret them. First, note that the "
             "quality value is represented on the y-axis, while the x-axis "
             "shows the percentage of elements. "
             "The x-axis uses an exponential scale, with the cutoff "
             "positioned in the middle. "
             "Each point (x, y) in the plot indicates that x%% of the elements "
             "have a quality less than or equal to y, "
             "while (100 - x)%% of the elements have a quality greater "
             "than or equal to y. "
             "This means that a window defined by (x0, y0) and (x1, y1) "
             "represents the portion (x1 - x0)%% of the elements with a quality "
             "between y0 and y1. One advantage of this type of plot is "
             "that the worst value is always clearly visible. For small meshes, "
             "the plot may display abrupt jumps on the left-hand side, "
             "which is normal and expected. "
             "The first jump corresponds to the transition from the worst "
             "value to the second worst value. It also indicates the number of "
             "analyzed elements, as it occurs at x = 1 / nb.\n");
  }
}

bool Plug::_createPlotsOneMetric(const Measures &m, Metric metric)
{
  std::vector<double> values;
  m.getValues(metric, values);
  if(values.empty()) return false;

  std::string s = _metricNames[metric];
  s += " ";
  s += m.dimStrShort;
  s += " (p)";

  for(double cutoff: _statGen->getCutoffPlots()) {
    Key key(m.dim2Elem, m.dim3Elem, metric, Key::TypeView::PLOT, cutoff);
    if(_pviews.find(key) == _pviews.end()) {
      PView *p = new PView(s, cutoff, true, values);
      _pviews[key] = p;
      p->getOptions()->colorTable.ipar[COLORTABLE_NUMBER] = 0;
      ColorTable_Recompute(&p->getOptions()->colorTable);
      if(metric != RATIOJAC && metric != MINJAC) {
        p->getOptions()->rangeType = PViewOptions::Custom;
        p->getOptions()->customMin = 0;
        p->getOptions()->customMax = 1;
        if(metric == GEOFIT) {
          p->getOptions()->customMin = -1;
        }
      }
      return true;
    }
  }
  return false;
}

void Plug::_createElementViews(const std::vector<Measures> &measures)
{
  if(!_param.pview.createElemView) return;

  int numViews = 0;
  Parameters::MetricsToShow &ps = _param.show;
  for(const auto &m: measures) {
    for(int i = VALIDITY; i <= ASPECT; i++) {
      if(ps.which[i] == ps.M) {
        if (_createElementViewsOneMetric(m, static_cast<Metric>(i)))
          ++numViews;
      }
    }
  }

  if(numViews) _info(MP, "-> Created %d elements views", numViews);
}

bool Plug::_createElementViewsOneMetric(const Measures &m, Metric metric)
{
  std::vector<double> values;
  std::vector<MElement *> elements;
  m.getValues(metric, values, &elements);
  if(values.empty()) return false;

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
    if(metric != RATIOJAC && metric != MINJAC) {
      // Preset customMin and Max but let rangeType be Default
      p->getOptions()->customMin = 0;
      p->getOptions()->customMax = 1;
      if(metric == GEOFIT) {
        p->getOptions()->customMin = -1;
      }
      return true;
    }
  }
  return false;
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
    for (int i = MINJAC; i <= ASPECT; ++i) {
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
    _info(MP, "-> %s elements have been made visible, %s have been hidden",
      formatNumber(countMadeVisible).c_str(), formatNumber(countHidden).c_str());
  else if (countHidden)
    _info(MP, "-> %s elements have been hidden", formatNumber(countHidden).c_str());
  else if (countMadeVisible)
    _info(MP, "-> %s elements have been made visible", formatNumber(countMadeVisible).c_str());

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
  std::vector<double> values;
  measure.getValues(metric, values);

  double limitVal;
  size_t numVisibleElements = static_cast<size_t>(_param.hide.threshold);
  switch(_param.hide.criterion) {
  case 2:
  limitVal = _param.hide.threshold;
    break;

  case 0: {
    double tmp = clamp(_param.hide.threshold, 0., 100.) / 100.;
    tmp *= static_cast<double>(values.size());
    numVisibleElements = static_cast<size_t>(std::round(tmp));
  }
  case 1: {
    numVisibleElements = clamp(numVisibleElements, size_t{0}, values.size());
    size_t numElementOnLimit = clamp(numVisibleElements, size_t{0}, values.size()-1);
    std::nth_element(values.begin(), values.begin() + static_cast<long>(numElementOnLimit), values.end());
    limitVal = values[numElementOnLimit];
  }
    break;

  default:
    _error(0, "Invalid hiding criterion");
    return;
  }

  std::vector<double> val;
  std::vector<MElement *> elements;
  measure.getValues(metric, val, &elements);
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
    _info(0, "Skipping hiding because all elements would be hidden");
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

  size_t totalNumberToShow[METRIC_COUNT]{};
  for(auto m: measures) {
    for(int i = 0; i < METRIC_COUNT; i++)
      totalNumberToShow[i] += m.numToShow[i];
  }

  _printDetailsMetrics(totalNumberToShow);

  int cntQuality = 0;
  for (int i = MINJAC; i <= ASPECT; ++i) {
    cntQuality += totalNumberToShow[i];
  }

  if(param.pview.statCutoffPack && cntQuality)
    _info(1, "   *W<|>orst-10%% Weighted Mean*  (Wm10) corresponds to a weighted "
             "mean where the worst 10%% of the values are assigned the same weight "
             "as the remaining values. This approach is preferable to the standard "
             "mean because it emphasizes the worst elements, which are critical "
             "as they can negatively impact the Finite Element solution. "
             "Note that the standard mean corresponds to Wm50.");

  for(auto &measure: measures) {
    _printStats(measure);
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

void Plug::StatGenerator::_printStats(const Measures &measure)
{
  size_t numReqElem = measure.elements.size();
  _info(MP, "-> Statistics summary for %s:", measure.dimStr);
  _info(MP, "   Number of requested elements: %s", formatNumber(numReqElem).c_str());

  // 1. Print header table if necessary
  bool haveQualityToPrint = false;
  bool showColumnPercentElem = false;

  for(int i = MINJAC; i <= ASPECT; ++i) {
    if(measure.numToShow[i]) {
      haveQualityToPrint = true;
      // Check if not all elements are analyzed for this metric
      if (0 < measure.numToShow[i] && measure.numToShow[i] < numReqElem) {
        showColumnPercentElem = true;
      }
    }
  }

  if(showColumnPercentElem)
    _warn(1, "   Not all the selected elements have metric computed");

  if(haveQualityToPrint) {
    std::ostringstream columnNamesStream;
    columnNamesStream << "   | ";
    columnNamesStream << std::setw(_colWidth) << "";
    if (showColumnPercentElem) {
      columnNamesStream << std::setw(7) << "%Elem";
    }
    columnNamesStream << std::setw(_colWidth) << "Min";
    for (double c : _statCutoffs) {
      std::ostringstream formattedP;
      formattedP << std::setprecision(2) << c;
      columnNamesStream << std::setw(_colWidth) << "Wm" + formattedP.str();
    }
    columnNamesStream << std::setw(_colWidth) << "Max";
    _info(MP, "%s", columnNamesStream.str().c_str());
  }

  // 2. Print values for requested quality metrics
  for(int i = MINJAC; i <= ASPECT; i++) {
    if(measure.numToShow[i])
      _printStatsOneMetric(measure, static_cast<Metric>(i), showColumnPercentElem);
  }

  // 3. Print info about validity and flipping
  if(!measure.numToShow[VALIDITY] && !measure.numToShow[UNFLIP]) return;

  double numElement = static_cast<double>(measure.elements.size());
  double percentageInvalid = static_cast<double>(measure.numInvalidElements) / numElement * 100;
  double percentageFlipped = static_cast<double>(measure.numFlippedElements) / numElement * 100;
  if(!(measure.numInvalidElements + measure.numFlippedElements))
    _status(MP, "   All elements are valid :-)");
  else if(!measure.numFlippedElements)
    _warn(MP, "   Found %zu invalid elements (~%.2g%%)",
      measure.numInvalidElements, percentageInvalid);
  //// It cannot happen since Unflip is currently not computed without validity
  // else if(!measure.numToShow[VALIDITY])
  //   _warn(MP, "   Found %zu flipped elements (~%.2g%%)",
  //     measure.numFlippedElements, percentageFlipped);
  else if(!measure.numInvalidElements)
    _warn(MP, "   <|>All elements are valid but %zu elements are flipped (~%.2g%%)",
      measure.numFlippedElements, percentageFlipped);
  else
    _warn(MP, "   <|>Found %zu invalid elements (~%.2g%%) and %zu flipped "
              "elements (~%.2g%%)", measure.numInvalidElements,
              percentageInvalid, measure.numFlippedElements, percentageFlipped);

  if (measure.numToShow[VALIDITY] < numReqElem) {
    double percentage = static_cast<double>(measure.numToShow[VALIDITY]) / numReqElem * 100;
    _status(MP, "   Among the %.2g%% of the selected elements that were analyzed", percentage);
  }
}

void Plug::StatGenerator::_printStatsOneMetric(const Measures &measure, Metric metric, bool showPercentElem)
{
  std::vector<double> values;
  measure.getValues(metric, values);

  if(values.empty()) return;

  size_t numElem = values.size();
  size_t numTotalElem = measure.elements.size();
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
  if (showPercentElem) {
    double percentElem = static_cast<double>(numElem) / static_cast<double>(numTotalElem) * 100.0;
    valStream << std::setw(7) << percentElem;
  }
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

void Plug::DataSingleDimension::syncWithModel(GModel const *m,
                                              const Parameters::Computation &param,
                                              Counts &counts)
{
  _selectedListHasChanged = false;

  // Update list GEntities (thus _dataEntities) if needed
  std::set<GEntity *, GEntityPtrLessThan> entities;
  if(_dim == 2) entities.insert(m->firstFace(), m->lastFace());
  else if(_dim == 3) entities.insert(m->firstRegion(), m->lastRegion());
  _updateGEntitiesList(entities, param.freeOldData);

  // Initialize all DataEntity and count elements
  for(auto &it : _dataEntities) {
    int numSelectedChanged = it.second.updateElementsAndFlags(param);
    if(numSelectedChanged) _selectedListHasChanged = true;
    it.second.count(param, counts);
  }
}

void Plug::DataSingleDimension::_updateGEntitiesList(
  std::set<GEntity *, GEntityPtrLessThan> &entities, bool freeNonExistent)
{
  // Add new GEntities present in the current model to _dataEntities
  for(const auto &ge: entities) {
    if(_dataEntities.find(ge) == _dataEntities.end())
      _dataEntities.emplace(ge, DataEntity(ge));
  }

  if(freeNonExistent) {
    // GEntityPtrLessThan cannot be called on deleted GEntity
    std::set<GEntity *> entities2;
    for (auto ge : entities) {
      entities2.insert(ge);
    }

    // Remove GEntities from _dataEntities that are not existent in the current model
    for(auto it = _dataEntities.begin(); it != _dataEntities.end();) {
      if(entities2.find(it->first) == entities2.end()) {
        if(it->second.getNumSelected()) _selectedListHasChanged = true;
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
  size_t sz = counts.reqElem;
  size_t szCurvGeo = counts.reqElemOkGeoFit;
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
  measures.minGFit.reserve(szCurvGeo);
  measures.maxGFit.reserve(szCurvGeo);
  measures.elementsGFit.reserve(szCurvGeo);
  measures.numInvalidElements = 0;
  measures.numFlippedElements = 0;
  for(auto &it : _dataEntities) {
    it.second.addValues(measures);
  }
}

bool Plug::DataSingleDimension::hasDataToShow() const
{
  bool hasData = false;
  for(auto &it : _dataEntities) {
    if(it.second.hasDataToShow()) {
      hasData = true;
      break;
    }
  }
  return hasData;
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

size_t Plug::DataEntity::updateElementsAndFlags(const Parameters::Computation &param)
{
  size_t cntSelectedChanged = 0;
  std::size_t num = _ge->getNumMeshElements();

  // Step 0: Update normals in case it was not computed previously (this can
  //         happen because normals are computed from mesh and if the plugin
  //         is run with GEntity free of mesh and run later with that
  //         GEntity containing a mesh)
  _computeNormals();

  // Step 1: Get all elements present in GEntity
  std::vector<MElement *> elements;
  elements.reserve(num);
  for(auto i = 0; i < num; ++i) {
    elements.push_back(_ge->getMeshElement(i));
  }

  // Step 2: Reset data if needed
  if(!param.skip) {
    bool resetData = !param.smartRecompute;
    if(param.smartRecompute) {
      bool sizeMismatch = (num != _mapElemToIndex.size());
      bool elementListMismatch = false;
      if(!sizeMismatch) {
        for(auto i = 0; i < num; ++i) {
          if(_mapElemToIndex.find(elements[i]) == _mapElemToIndex.end()) {
            elementListMismatch = true;
            break;
          }
        }
      }
      resetData = sizeMismatch || elementListMismatch;
    }
    if(resetData) {
      cntSelectedChanged += _numSelected;
      reset(num);
      add(elements);
    }
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

  // Step 5: Update flag 'isRequested'
  int maskRequested = 0;
  if(param.onlyVisible) maskRequested |= F_VISBL;
  if(param.onlyCurved) maskRequested |= F_CURVED;

  for(auto it: _mapElemToIndex) {
    auto &flag = _flags[it.second];
    bool typeMismatch = param.onlyGivenElemType && !param.acceptedElemType[it.first->getType()];
    if(!typeMismatch && areBitsSet(flag, maskRequested)) {
      if(isBitUnset(flag, F_REQU)) {
        ++cntSelectedChanged;
        setBit(flag, F_REQU);
      }
    }
    else {
      if(isBitSet(flag, F_REQU)) {
        ++cntSelectedChanged;
        unsetBit(flag, F_REQU);
      }
    }
  }
  return cntSelectedChanged;
}

void Plug::DataEntity::count(const Parameters::Computation &param, Counts &counts)
{
  if(_curvingIsKnown) {
    if(_isCurvedGeo)
      ++counts.geoEntCurved[_ge->dim() - 1];
    else
      ++counts.geoEntFlat[_ge->dim() - 1];
  }

  // Reset intern data
  _numSelected = 0;
  constexpr int metricsCount = 5;
  for(int i = 0; i < metricsCount; ++i) _numToCompute[i] = 0;

  // Count number of selected elements
  _count(F_REQU, _numSelected);
  counts.reqElem += _numSelected;
  if(_isCurvedGeo)
    counts.reqElemOnCurvGeo += _numSelected;
  if(param.geofit && _isCurvedGeo)
    counts.reqElemOkGeoFit += _numSelected;

  // Count number of elements to compute
  if(!param.skip) {
    std::size_t numJacToCompute = 0;
    _count(F_REQU | F_NOTJAC, numJacToCompute);
    if (param.jacobian && !_isCurvedGeo) _numToCompute[0] += numJacToCompute;
    if (param.jacobianOnCurvedGeo && _isCurvedGeo) _numToCompute[1] += numJacToCompute;
    if (param.geofit && _isCurvedGeo) _count(F_REQU | F_NOTORI, _numToCompute[2]);
    if (param.disto) _count(F_REQU | F_NOTDISTO, _numToCompute[3]);
    if (param.aspect) _count(F_REQU | F_NOTASPECT, _numToCompute[4]);

    for(int i = 0; i < metricsCount; ++i) {
      counts.metricValsToCompute[i] += _numToCompute[i];
    }
  }

  // Count available values for selected elements
  _countAvailableValues(param, counts.metricValsAvailOnSelectedElem,
    counts.distoOrAspectToComputeButUnknownValidity);

  // Count total number, number of visible and curved elements
  counts.elem += _mapElemToIndex.size();
  if(_isCurvedGeo)
    counts.elemOnCurvGeo += _mapElemToIndex.size();
  for(const auto &flag : _flags) {
    if(isBitSet(flag, F_VISBL)) ++counts.elemVisible;
  }
  _countCurved(counts.elemWithKnownCurving, counts.elemCurved);

  // Count number of element by type
  for(int i = 0; i < TYPE_MAX_NUM; ++i) {
    counts.elem_byType[i] += _ge->getNumMeshElementsByType(i);
  }
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

void Plug::DataEntity::_countAvailableValues(const Parameters::Computation &param,
  size_t cnt[5], size_t &numForWarningNotValidity)
{
  size_t numJacComputed = 0;
  for (const auto &flag : _flags) {
    if (isBitSet(flag, F_REQU)) {
      if(isBitUnset(flag, F_NOTJAC)) ++numJacComputed;
      if(isBitUnset(flag, F_NOTORI)) ++cnt[2];
      if(isBitUnset(flag, F_NOTDISTO)) ++cnt[3];
      if(isBitUnset(flag, F_NOTASPECT)) ++cnt[4];
    }
  }
  if (_isCurvedGeo) cnt[1] += numJacComputed;
  else cnt[0] += numJacComputed;


  if((param.disto || param.aspect) && !param.jacobian) {
    int maskJacToCompute = F_REQU | F_NOTJAC;

    for (const auto &flag : _flags) {
      if(areBitsSet(flag, maskJacToCompute)) {
        if ((param.disto && isBitSet(flag, F_NOTDISTO)) ||
            (param.aspect && isBitSet(flag, F_NOTASPECT)))
          ++numForWarningNotValidity;
      }
    }
  }
}

void Plug::DataEntity::_computeNormals()
{
  // FIXME If no mesh, then cannot say if curved geo or not.
  // And mesh can come later...
  // -> by default, consider flat, knowCurving=false
  //    if mesh, then knowCurving = true, isCurved = !normal
  std::size_t num = _ge->getNumMeshElements();

  if(!num || _curvingIsKnown) return;
  _curvingIsKnown = true;

  if(_ge->dim() == 2) {
    GFace *gf = _ge->cast2Face();
    SVector3 normal;
    if(gf->normalToPlanarMesh(normal, true)) {
      _normals = new fullMatrix<double>(1, 3);
      _normals->set(0, 0, normal[0]);
      _normals->set(0, 1, normal[1]);
      _normals->set(0, 2, normal[2]);
    }
  }
  // FIXME: implement if dim==1

  _updateNormalsToPrint();

  switch(_ge->dim()) {
  case 3:
    _isCurvedGeo = false;
    break;
  case 2:
  case 1:
  default:
    _isCurvedGeo = !_normals;
  }
}

void Plug::DataEntity::_updateNormalsToPrint()
{
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
    _info(1, "   Surface %d: Computing Disto quality of %d elements",
          _ge->tag(), _numToCompute[3]);
  else
    _info(1, "   Volume %d: Computing Disto quality of %d elements",
          _ge->tag(), _numToCompute[3]);

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
          _ge->tag(), _numToCompute[4]);
  else
    _info(1, "   Volume %d: Computing Aspect quality of %d elements",
          _ge->tag(), _numToCompute[4]);

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
      _info(1, "   Cannot compute GeoFit for vertex %d (this "
               "is normal as GeoFit is still experimental)", vert->getNum());
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
          _ge->tag(), _numToCompute[2]);
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
      else {
        measures.minJ.push_back(NOTCOMPUTED);
        measures.maxJ.push_back(NOTCOMPUTED);
      }
      if(isBitUnset(_flags[idx], F_NOTORI)) {
        measures.minGFit.push_back(_minGFit[idx]);
        measures.maxGFit.push_back(_maxGFit[idx]);
        measures.elementsGFit.push_back(it.first);
      }
      if(isBitUnset(_flags[idx], F_NOTDISTO))
        measures.minDisto.push_back(_minDisto[idx]);
      else
        measures.minDisto.push_back(NOTCOMPUTED);
      if(isBitUnset(_flags[idx], F_NOTASPECT))
        measures.minAspect.push_back(_minAspect[idx]);
      else
        measures.minAspect.push_back(NOTCOMPUTED);
    }
  }
}

bool Plug::DataEntity::hasDataToShow() const
{
  bool hasData = false;

  for(const auto jac: _minJ) {
    if(jac != NOTCOMPUTED) {
      hasData = true;
      break;
    }
  }
  if(hasData) return true;

  for(const auto geoFit: _minGFit) {
    if(geoFit != NOTCOMPUTED) {
      hasData = true;
      break;
    }
  }
  if(hasData) return true;

  for(auto disto: _minDisto) {
    if(disto != NOTCOMPUTED) {
      hasData = true;
      break;
    }
  }
  if(hasData) return true;

  for(auto aspect: _minAspect) {
    if(aspect != NOTCOMPUTED) {
      hasData = true;
      break;
    }
  }

  return hasData;
}

// ======== Plugin: User Messages ==============================================
// =============================================================================

// NOTE: Different options to force spaces at beginning of lines, from
//       narrowest to widest:
//         - "\u2009" (Thin space - Smaller than a standard space)
//         - "&nbsp;" (Non-breakable space character)
//         - "\u2002" (En Space - Half the width of Em Space
//         - "\u2003" (Em Space - Wider than a standard space)
//         - "\u3000" (Ideographic Space)
//       But these one doesn't work:
//         - "\t" (Tab)
//         - "\x20" (Non-breakable space character)
//         - "\u00A0" (Non-breaking space)
#define SPACE "\u2002"
#define BULLET "\u2002• "
#define BULLET2 "\u2002\u2002- "
#define ANSWER "\u2002\u2002  "

std::string Plug::_getHelpIntro()
{
  return
    "INTRODUCTION\n"
    "Plugin(AnalyseMeshQuality) evaluates the validity and quality of mesh "
    "elements within the current model. The plugin allows users to compute "
    "various quality metrics such as Disto, Aspect, and GeoFit, "
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
    BULLET"To get live, contextual explanations during execution, "
          "users can set `guidanceLevel' to 1.\n"
    BULLET"A FAQ is available at the end of this help message.\n"
    "\n"
    "IMPORTANT NOTES\n"
    BULLET"Input option values are designed to have a default effect when "
          "set to 0, allowing users to quickly identify modified options. "
          "For this reason, some options support negative values.\n"
    BULLET"The advanced option `smartRecompute' can be very useful when "
          "running the plugin multiple times but must be used cautiously. "
          "See the 'OPTIONS CLARIFICATIONS' section for details.\n"
    BULLET"This help message does not cover all of the available information. "
          "Users who are not familiar with this plugin (or its new version) "
          "should set the `guidanceLevel' option to 1 to receive "
          "additional assistance.\n";
}

std::string Plug::_getHelpDefinitions()
{
  return
    "DEFINITIONS\n"
    BULLET"`Natural Dimension elements' (ND elements): Elements that are "
          "represented in their natural spatial dimension, e.g., "
          "2D elements on flat surfaces or 3D elements in volumes.\n"
    BULLET"`Curved Geometry elements' (CG elements): Elements that are "
          "defined along curved geometrical features, such as 1D elements "
          "on curved edges or 2D elements on curved surfaces.\n"
    BULLET"`Prominent metrics': The plugin distinguishes between requested "
          "metrics, which are computed and displayed as statistics, and a "
          "subset of these called `Prominent metrics'. "
          "The Prominent metrics are used to determine visibility "
          "adjustment and visualization views. To obtain the subset, "
          "the plugin compute the maximum value among:\n"
    BULLET2"enableDistoQuality\n"
    BULLET2"enableAspectQuality\n"
    BULLET2"enableGeoFitQuality\n"
    BULLET2"enableMinJacDetAsAMetric\n"
    BULLET2"enableRatioJacDetAsAMetric\n"
    "The metrics matching this maximum value are in the set of Prominent metrics.\n";
}

std::string Plug::_getHelpMetrics()
{
  return
    "METRICS\n"
    "By default, the plugin computes validity and flipping for ND elements. "
    "The metric associated with flipping is called Unflip, adhering to the same logic as "
    "the other metrics: higher is better. "
    "Validity and flipping are not as well-defined for CG elements as they are for ND elements. "
    "For such elements, GeoFit (an experimental metric) provides a natural alternative. "
    "The plugin can also compute two shape quality metrics that are well-defined "
    "for 2D and 3D, ND and CG elements. "
    "The first metric is called Disto (short for distortion), which measures how close "
    "elements are to their ideal shape "
    "(e.g., a square for a quadrangular element). The second metric, called Aspect, "
    "primarily emphasizes that large angles are undesirable (e.g., rectangular "
    "shapes remain excellent for the quadrangular element). "
    "In addition, the plugin can derive two metrics from the Jacobian determinant: "
    "its minimum value (minJ) and the ratio of minJ to maxJ. "
    "These two metrics are obtained at no additional computational cost since the "
    "Jacobian determinant is already calculated for validity and flipping. "
    "The minJ metric helps determine the element size. " // FIXME ratio for HO elements
    "The minJ/maxJ ratio, while not a true quality metric, can serve as an indicator "
    "for detecting distorted elements. Be cautious, as there is no guarantee "
    "that an element with a good minJ/maxJ ratio has a good shape. "
    "For additional details about the metrics in use during execution, set guidanceLevel to ‘1’. "
    "Alternatively, set guidanceLevel to ‘2’ to instruct the plugin to print detailed "
    "information for all metrics and then stop.\n";
//
// // "Those two metrics are derived through the computation of the Jacobian determinant. "
//   "They are free to obtain because the Jacobian determinant is already "
//   "computed for validity and flipping. The minJ allow to determine the size "
//   "of element. "
//   // "and can be useful in two situations: the mesh is curved "
//   // "high-order mesh that is uniform in size, in which case minJ allows to detect "
//   // "element that diverge from the other, or the mesh is non-uniform but the size "
//   // "of the smallest elements is critical and. "
//   "Ratio minJ/maxJ, while not a "
//   "true quality metric, allow to fastly detect distorted elements. Be cautious as there is "
//   "no guarantee that an element with a good minJ/maxJ have a good shape. "
//   "For more details on metrics you are using during execution, set guidanceLevel to "
//   "`1', or set guidanceLevel to `2' to make the plugin printing those details "
//   "for all metrics and stop. "
//   // ""
//   // "The plugin evaluates several metrics to analyze the validity and quality of mesh elements. "
//   // "`Validity' and `Unflip' assess whether elements are valid (Jacobian determinant ≠ 0) or inverted "
//   // "(Jacobian determinant < 0), as such elements can significantly affect the Finite Element solution. "
//   // "`MinJ' and `Ratio minJ/maxJ' provide insights into element sizes and deformation, with the latter being "
//   // "a quick, albeit approximate, quality indicator. For numerical performance, `Disto quality' (related "
//   // "to stiffness matrix conditioning) and `Aspect quality' (impacting solution gradients) range from 0 to 1, "
//   // "where higher values indicate better quality. For CG elements, `GeoFit' measures alignment with the "
//   // "geometry, ranging from -1 (flipped) to 1 (perfect alignment).\n"
}

std::string Plug::_getHelpWWM()
{
  // // Recommended cutoffs in function of element count:
  // 100 ~ 10k -> 25
  // 2k ~ 4M -> 10
  // 500k ~ 10+B -> 2

  return
    "WORST-WEIGHTED MEAN\n"
    "The plugin computes an alternative mean value, called the "
    "worst-weighted mean, for inclusion in the statistics. "
    "This mean is designed to give more weight to the worst values compared to "
    "the best values. "
    "The rationale is that, in the finite element method, critical issues are "
    "often caused by the worst values. "
    "This metric is parameterized by a single value: the cutoff. "
    "For applications involving between 2k and 4M elements, a cutoff value of 10% "
    "is recommended. "
    "A 10% cutoff means that the worst 10% of values contribute equally "
    "to the mean as the remaining 90%. "
    "For small meshes with 100 to 10k elements, a higher cutoff of 25% is "
    "better suited. "
    "In contrast, for large meshes starting around 500k elements, a cutoff "
    "of 2% is more appropriate. "
    "The worst-weighted mean is computed as the integral of the "
    "worst-weighted graph; refer to the next section for a presentation of "
    "those graphs.\n"
    "\n"
    "PLOTS\n"
    "The plugin generates a new type of plot to enhance readability and "
    "facilitate comparisons. "
    "In these plots, the quality value is represented on the y-axis, "
    "while the x-axis displays the percentage of elements. "
    "Note that the x-axis uses an exponential rather than linear scale, "
    "with the cutoff (see the OPTIONS CLARIFICATIONS section) positioned "
    "in the middle of the axis. "
    "Each point (x, y) on the plot indicates that x% of the elements have a "
    "quality less than or equal to y. "
    "These plots also provide a clear visualization of the minimum values.\n";
}

std::string Plug::_getHelpOptionsClarification()
{
  return
    "OPTIONS CLARIFICATIONS\n"
    "For clarification about visibility options, see next section.\n"
    BULLET"`guidanceLevel': Determines the verbosity level of the plugin output:\n"
    BULLET2"`-1': Typically used for scripting, where only the printed "
           "statistics are desired.\n"
    BULLET2"`0': Prints an overview of what the plugin is doing but "
           "without details.\n"
    BULLET2"`1': Prints detailed information about the plugin's operation, "
           "which may be useful for debugging. "
           "It also provides guidance for beginner users.\n"
    BULLET"`dataReleasePolicy': Determines how data is managed by "
          "the plugin:\n"
    BULLET2"`-1': Frees data and stops the plugin immediately, preventing any "
           "further actions. This is typically useful in scripting contexts.\n"
    BULLET2"`0': Deletes data corresponding to geometry entities "
           "that are absent in the current model.\n"
    BULLET2"`1': Keeps data corresponding to geometry entities that are "
           "absent in the current model. This is useful if the plugin may "
           "be run again with a previous model.\n"
    BULLET"`smartRecomputation': Prevents unnecessary recomputation when "
          "the plugin is run again and prevent recreating exact same views. "
          "If set to `0', the plugin will always recompute. If set to `1', "
          "for each geometrical entity, the plugin will decide to recompute "
          "only if the list of elements has changed. This happens, "
          "for example, if the geometrical entity has been remeshed or "
          "if a topological operation has been performed. "
          "However, the plugin cannot detect if nodes have been moved, "
          "such as after an optimization. Use this option with caution!\n"
    BULLET"`skipValidity': The plugin is designed to check the validity "
          "of elements before evaluating any quality metrics. "
          "This behavior ensures faster computation of quality metrics "
          "in the presence of invalid elements. The user can set "
          "`skipValidity' to `1' to disable validity checks. "
          "To include validity as part of Prominent metrics, set its "
          "value to `-M', where `M' is the maximum value among all metrics.\n"
    // FIXME move some of this info in the new section on metrics
    BULLET"`treatFlippedAsValid': By default, the plugin detects flipped "
          "ND elements, i.e. ND elements with a negative area or volume, "
          "and classifies those elements into three categories: valid, "
          "invalid, and flipped. Whether flipped elements are problematic "
          "or not depends on the solver being used. "
          "To treat flipped ND elements as valid, set this option to `1'. "
          "For CG elements, although they are not classified in terms "
          "of flipping, the GeoFit metric provides an indirect indication "
          "of this. An element with a `maxGeoFit' value close to -1 can be "
          "considered as flipped. However, flipped CG elements rarely cause "
          "issues, so the plugin consider them as valid by default. "
          "To override this behavior, set this option to `-1'. "
          "Internally, if requested, the plugin `regularize' the Jacobian "
          "determinant or the GeoFit measure. In the case of the Jacobian "
          "determinant, regularization involves comparing the absolute "
          "values of both `minJ' and `maxJ'. If `|maxJ| < |minJ|', the "
          "following adjustments are made: `new_minJ = -maxJ', and "
          "`new_maxJ = -minJ'. The same logic applies to the GeoFit metric. "
          "This process implies that regularizing the Jacobian "
          "determinant also affects other metrics derived from it: "
          "`minJ' and `minJ/maxJ'.\n"
    BULLET"`wmCutoffsForStats' and `wmCutoffsForPlots': Defines a list "
          "of cutoff values used for computing weighted mean-based "
          "statistics and generating plots. The list of cutoff is specified "
          "as a sequence of two-digit values, e.g. 123456, which would "
          "result in extracted cutoffs: `12%', `34%' and `56%'. "
          "The default value is 10. A `10%' cutoff corresponds to a "
          "weighted mean where the worst 10% of the values influence "
          "equally with the rest. This technique highlights critical data "
          "subsets generally impacting the finite element solution.\n";
}

std::string Plug::_getHelpVisibility()
{
  return
    "VISIBILITY ADJUSTMENT\n"
    BULLET"The plugin is able to hide and unhide elements based on specific "
          "criteria. Various options are available for fine-tuning the "
          "behavior of this feature.\n"
    BULLET"Default behaviour: In the presence of invalid elements, "
          "the plugin will make them visible and hide the other. "
          "If all elements are valid, the plugin will select the 10% worst "
          "element according to the Prominent metrics and make them visible "
          "while hiding the others.\nAvailable options:\n"
    BULLET"`adjustElementsVisibility': Enables the operation of hiding "
          "and unhiding elements. If set to `1', the plugin will abort if "
          "all analyzed elements meet the criterion to be hidden. "
          "To force the hiding in this case, set it to `2'.\n"
    BULLET"`visibilityPolicy': Determines which metric(s) are used to "
          "decide which elements are hidden or made visible. "
          "The available settings and their behaviors are:\n"
    BULLET2"`-1': The plugin first checks if there are invalid elements. "
           "If invalid elements exist, they are made visible while valid "
           "elements are hidden. If no invalid elements are present, "
           "the plugin will abort.\n"
    BULLET2"`0': Similar to `-1', but in this case, the plugin does not "
           "abort when no invalid elements are present. Instead, it "
           "behaves as if the input value were set to `1'.\n"
    BULLET2"`1': The plugin checks each Prominent metric. "
           "If any elements meet the criterion for being visible, "
           "they are made visible. Elements failing to meet the "
           "criterion across all metrics are hidden.\n"
    BULLET2"`2': The behavior is the opposite of `1'. Elements that fail "
           "to meet the visibility criterion are made visible, while those "
           "that meet it are hidden.\n"
    BULLET"`visibilityCriterion': Defines the purpose of the threshold. "
          "Available values are:\n"
    BULLET2"`0': The threshold is the percentage of elements to make visible.\n"
    BULLET2"`1': The threshold is the number of elements to make visible.\n"
    BULLET2"`2': The threshold is the metric value.\n"
    BULLET"`visibilityThreshold': Specifies the threshold value used for "
          "`visibilityCriterion'.\n"
    BULLET"`hideWorstElements': Reverses the hiding operation. "
          "If set to `1', the best-rated elements are made visible "
          "and worst-rated elements are hidden.\n"
    BULLET"`doNoSetVisible': Controls whether elements are made visible or "
          "only hidden. If set to `0', the plugin performs both hiding and "
          "unhiding. If set to `1', the plugin only performs the hiding "
          "operation without making any elements visible.\n";
}

std::string Plug::_getHelpAdvancedUse()
{
  return
    "ADVANCED USE CASE: COMPUTING QUALITY OF SUBSET MESH ELEMENTS\n"
    "The plugin can be used to compute the quality of a subset of mesh "
    "elements easily, by combining multiple runs. This is especially "
    "useful in scripts.\n"
    "A typical workflow may include the following steps:\n"
    SPACE"1. Initial run: Compute a specific metric (e.g., `minJ' or "
         "`minJ/maxJ') for all elements and use the visibility adjustment "
         "options to make only a subset of elements visible. For instance, "
         "to make only the 20% smallest elements visible:\n"
    BULLET2"`adjustElementsVisibility = 1'\n"
    BULLET2"`visibilityPolicy = 1'\n"
    BULLET2"`visibilityThreshold = 20'\n"
    BULLET2"`enableMinJacDetAsAMetric = 1'\n"
    SPACE"2. Second run: Compute quality metrics for the visible elements. "
         "This focuses computations only on the subset of interest and "
         "avoids analyzing the entire mesh. Set `adjustElementsVisibility' "
         "to `0' to prevent further changes to visibility. In this example, "
         "Aspect quality and Disto quality are computed, but only "
         "Disto quality is visualized:\n"
    BULLET2"`enableDistoQuality = 2'\n"
    BULLET2"`enableAspectQuality = 1'\n"
    BULLET2"`createElementsView = 1'\n"
    BULLET2"`adjustElementsVisibility = 0'\n"
    BULLET2"`restrictToVisibleElements = 1'\n"
    BULLET2"`smartRecomputation = 1'\n"
    //BULLET2"`enableMinJacDetAsAMetric = 0'\n"
    SPACE"3. Optional final run: Use the plugin to make all elements "
         "visible again. This can be achieved by setting:\n"
    BULLET2"`createElementsView = 0'\n"
    BULLET2"`adjustElementsVisibility = 1'\n"
    BULLET2"`restrictToVisibleElements = 0'\n"
    BULLET2"`visibilityThreshold = 100'\n"
    BULLET2"`omitMetricsComputation = 1'\n"
    BULLET2"`skipStatPrinting = 1'\n"
    BULLET2"`enableMinJacDetAsAMetric = 3'\n"
    "NB: This last operation can also be performed using built-in Gmsh functions.\n";
}

std::string Plug::_getHelpFAQ()
{
  return
    "FAQ\n"
    BULLET"Q1: As the plugin has been rewritten, will my script that uses the "
          "old version fail to work?\n"
    ANSWER"A: No, although not available in the GUI, the old options have been "
          "kept as legacy options. However, it is recommended to update "
          "the script, as these legacy options may be removed in a future release.\n"
    BULLET"Q2: Why is there a metric for the alignment of elements with curved "
          "edges/surfaces of the geometry (GeoFit) but not a metric for "
          "distance to the geometry?\n"
    ANSWER"A: The plugin assumes that the element nodes are "
          "exactly on the geometry, that the geometry is continuous, and "
          "that the parameterization is correct. "
          "Under these assumptions, it can be shown that a mesh which "
          "aligns well with the geometry in terms of orientation will also have "
          "a small distance to the geometry. In other words, as the GeoFit value "
          "tends to 1, the distance tends to zero. Conversely, it is possible "
          "to create situations where the orientation alignment remains poor "
          "while the distance to the geometry tends to zero. "
          "This is why the focus is on alignment rather than distance.\n"
    BULLET"Q3: Why are CG elements not classified in terms of validity and "
          "flipping like ND elements?\n"
    ANSWER"A: For simplicity, this answer will focus on 2D meshes on curved "
          "surfaces, but it is also applicable to 1D meshes on curved edges. "
          "There are two possible uses for surface meshes in the finite element "
          "method: either as the boundary of a volume mesh or for computing "
          "a finite element solution directly on it. In the first case, "
          "what is important is that the surface mesh does not interfere with "
          "the generation of a good volume mesh. In that context, "
          "validity/non-flipping is required only for the volume mesh. "
          "GeoFit allows users to verify that the surface mesh is "
          "suitable for generating a high-quality volume mesh. "
          "In the second case, the validity and quality requirements of the "
          "mesh depend on its specific application, and the plugin cannot "
          "account for all possible situations. "
          "GeoFit is still useful for checking whether the "
          "mesh accurately represents the surface.\n" //TODO improve
    BULLET"Q4: What is the difference between the three options concerning "
          "data management: `dataReleasePolicy', `omitMetricsComputation', "
          "and `smartRecomputation'?\n"
    ANSWER"A: First, note that the plugin stores computed data to avoid "
          "unnecessary recomputation if run again. By default, however, "
          "the plugin releases data related to previously analyzed geometry "
          "entities that are absent in the current model. "
          "Setting `dataReleasePolicy' to 1 causes the plugin to retain all data, "
          "which is useful when switching between different models. " //FIXME really useful?
          "In contrast, launching the plugin with `dataReleasePolicy' set to "
          "-1 causes it to release all memory and stop immediately. "
          "When `omitMetricsComputation' is enabled, the plugin skips computing "
          "missing metrics and relies only on previously computed data for the output. "
          "This is especially useful for generating output for a subset of elements. "
          "Note that the plugin will still release data according to the `dataReleasePolicy' "
          "option. If `omitMetricsComputation' is disabled, two scenarios arise: "
          "If `smartRecomputation' is disabled, metrics are recomputed for all "
          "selected elements. If `smartRecomputation' is enabled, "
          "the plugin compares the current list of elements with stored data. "
          "If they match exactly, only the missing metrics are computed. "
          "Otherwise, metrics are recomputed for all the selected elements "
          "on that geometry entity. "
          "Note: Use `smartRecomputation' with caution, as the plugin cannot "
          "detect meshes where only node positions have been modified "
          "(typically after optimization)."
          " \n"
    BULLET"Q5: Why are OFF and ON used in certain tooltips?\n"
    ANSWER"A: While most of the options function as on/off parameters, the "
          "input fields are uniform and expect a double-precision input. "
          "For this reason, OFF always corresponds to 0, while ON can be any "
          "value different from 0. "
          "In some cases, numbers are specifically listed instead of ON or OFF, "
          "which means that the option is a selection parameter.\n"
    BULLET"Q6: Why is there a `+' after Validity when the plugin says it computes that?\n"
    ANSWER"A: The plugin actually does not compute validity exactly but "
          "instead calculates the minimum and maximum of the Jacobian "
          "determinant. From that, it derives four quantities: validity, "
          "element flipping, and minJ and minJ/maxJ.\n"
    BULLET"Q7: What should I do if I find a bug, have a question, or want "
          "to propose a suggestion for the plugin?\n"
    ANSWER"A: To report a bug or make a suggestion, please create an issue "
          "on Gmsh's GitLab: https://gitlab.onelab.info/gmsh/gmsh/-/issues/new. "
          "Be sure to provide sufficient details about the issue or suggestion "
          "to help with clarification. For additional inquiries, you may contact "
          "the plugin author at amaury.johnen@uclouvain.be.\n";
}

#undef SPACE
#undef BULLET
#undef BULLET2
#undef ANSWER

bool Plug::_okToPrint(int asked)
{
  //       | _verbose  |
  // asked |-1 | 0 | 1+|
  // -------------------
  //   MP  | x | x | x | -> mandatory
  //    1  |   |   | x | -> help
  //    0  |   | x | x | -> normal
  //   -1  |   | x |   | -> alternative to help
  //   -2  | x |   |   | -> minimal

  return (asked == MP) ||
         (_verbose >= 1 && asked >= 0) ||
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

void Plug::_printDetailsMetrics(size_t which[METRIC_COUNT], bool verbose2)
{
  if(verbose2)
    _info(1, "-> Here are all available metrics described in details:");
  else
    _info(1, "-> <|>Printing statistics\nHere is the important information to know about them:"
    "them:");

  if(which[VALIDITY]) {
    _info(1, "   *V<|>alidity*  provides information about whether the Jacobian "
             "determinant is strictly non-zero. "
             "This ensures that the Jacobian determinant remains strictly non-zero "
             "at any Gaussian point, which is crucial for ensuring a valid mesh. "
             "A mesh containing invalid elements typically results in incorrect "
             "Finite Element solutions. "
             "Each element is classified as either valid or invalid.");
    if(verbose2)
      _info(1, "     <|>Validity is only defined for flat geometry entities, "
               "i.e., straight edges, planar faces, and volumes. "
               "For curved geometry entities, GeoFit can provide the necessary data. "
               "In views, Validity takes the values 0 (invalid) or 1 (valid).\n"
               "-> Disable Validity by setting 'skipValidity' to 1 (not recommended).");
  }
  if(which[UNFLIP]) {
    _info(1, "   *F<|>lipping*  provides information about whether the Jacobian "
             "determinant is strictly negative. A mesh containing flipped "
             "(inverted) elements can result in incorrect Finite Element solutions, "
             "depending on the solver. Each valid element is classified as "
             "either flipped or not flipped.");
    if(verbose2)
      _info(1, "     <|>As with validity, flipping is only defined for flat "
               "geometries. GeoFit can compensate for this limitation. "
               "In views, the metric is called Unflip, harmonizing the "
               "logic with other metrics: a bad element takes the value 0 "
               "(flipped), while a good element takes the value 1 (not flipped).\n"
               "-> Disable flipping/Unflip by setting 'treatFlippedAsValid' to 1.");
  }
  if(which[MINJAC]) {
    _info(1, "   *m<|>inJ*  is the minimum of the Jacobian determinant computed "
             "in the reference space and is used to check element size. "
             "This metric is especially relevant for iterative methods, "
             "where the time step may depend on the size of the smallest "
             "element. Values range from -∞ to +∞.");
    if(verbose2)
      _info(1, "     -> Enable minJ by setting 'enableMinJacDetAsAMetric' to 1.");
  }
  if(which[RATIOJAC]) {
    _info(1, "   *R<|>atio minJ/maxJ*  is the ratio between the minimum and "
             "maximum values of the Jacobian determinant. This metric is "
             "particularly relevant for high-order meshes, as it is faster to "
             "compute than Disto or Aspect quality metrics. It can be used to "
             "evaluate element deformation. "
             "However, it is important to note that it is not a true "
             "quality metric and cannot replace shape quality metrics. "
             "Values range from -∞ to 1.");
    if(verbose2)
      _info(1, "     -> Enable minJ/maxJ by setting 'enableRatioJacDetAsAMetric' to 1.");
  }
  if(which[DISTO]) {
    _info(1, "   *D<|>isto quality*  (short for distortion, previously ICN) "
             "is a shape quality metric related to the condition number of the "
             "stiffness matrix. "
             "Elements with low distortion may cause numerical roundoff errors or "
             "significantly slow the convergence of iterative methods. "
             "Values range from 0 to 1.");
    if(verbose2)
      _info(1, "     -> Enable Disto by setting 'enableDistoQuality' to 1.");
  }
  if(which[ASPECT]) {
    _info(1, "   *A<|>spect quality* (previously IGE) is a shape quality metric "
             "related to the gradient of the Finite Element solution. "
             "Elements with poor aspect quality negatively impact errors in the "
             "solution's gradient. Values range from 0 to 1.");
    if(verbose2)
      _info(1, "     -> Enable Aspect by setting 'enableAspectQuality' to 1.");
  }
  if(which[GEOFIT]) {
    _info(1, "   *G<|>eoFit (experimental)*  is defined for curved edges "
             "and curved surfaces in the geometry and measures how well "
             "element orientations align with the underlying geometry. "
             "For such configurations, validity is not defined, and GeoFit "
             "acts as a natural alternative for assessing whether the mesh is "
             "suitable as a boundary for the interior mesh. "
             "GeoFit can be interpreted as a 'normalized Jacobian determinant'. "
             "GeoFit values range from -1 (completely flipped) to 1 (perfectly "
             "aligned). "
             "A negative value may indicate an inappropriate (invalid-like) "
             "element, while a small positive value suggests poor "
             "geometry representation (and possibly high oscillations "
             "for high-order elements). Such values may indicate "
             "potential difficulties during interior mesh generation.");
    if(verbose2)
      _info(1, "     <|>By default, flipped elements are treated as if they add "
               "the opposite orientation. This is ideal for boundary meshes "
               "since element orientation does not affect the finite element "
               "solution. This behavior can be disabled by setting "
               "`treatFlippedAsValid` to -1.\n"
               "-> Enable GeoFit by setting 'enableGeoFitQuality' to 1.");
  }

  if(verbose2)
    _info(1, "   *P<|>rominent metrics*  are the metrics selected by "
             "the plugin for visualization. Specifically, these metrics have "
             "the corresponding option set to 'M,' where 'M' represents the "
             "maximum value among all metrics. To include Validity and "
             "Unflip as prominent metrics, set 'skipValidity' to '-M'.");
}

std::size_t Plug::_printElementToCompute(const Counts &cnt2D,
                                         const Counts &cnt3D) const
{
  std::size_t sum2D = 0, sum3D = 0;
  for (std::size_t x : cnt2D.metricValsToCompute) sum2D += x;
  for (std::size_t x : cnt3D.metricValsToCompute) sum3D += x;

  if(sum2D + sum3D == 0) {
    _info(1, "-> No element to compute");
    return 0;
  }

  _info(0, "-> Number of evaluations to perform:\n");
  _info(0, "   | %5s%11s%11s%11s%11s", "", "Validity+", "GeoFit", "Disto", "Aspect");
  if(sum2D)
    _info(0, "   | %5s%11s%11s%11s%11s", "2D:",
              formatNumber(cnt2D.metricValsToCompute[0]+cnt2D.metricValsToCompute[1]).c_str(),
              formatNumber(cnt2D.metricValsToCompute[2]).c_str(),
              formatNumber(cnt2D.metricValsToCompute[3]).c_str(),
              formatNumber(cnt2D.metricValsToCompute[4]).c_str());

  if(sum3D)
    _info(0, "   | %5s%11s%11s%11s%11s", "3D:",
              formatNumber(cnt3D.metricValsToCompute[0]+cnt3D.metricValsToCompute[1]).c_str(),
              formatNumber(cnt3D.metricValsToCompute[2]).c_str(),
              formatNumber(cnt3D.metricValsToCompute[3]).c_str(),
              formatNumber(cnt3D.metricValsToCompute[4]).c_str());

  return sum2D + sum3D;
}

void Plug::_guidanceNoSelectedElem(Counts counts, bool check2D,
                                     bool check3D) const
{
  if(counts.reqElem) return;

  _error(MP, "-> No element selected for analysis");

  if(counts.elem) {
    // Case where elements are found
    // This must be due to one of the three 'restrictTo...' options, or...
    bool found = false;
    if(_param.compute.onlyVisible && counts.elemVisible == 0) {
      _warn(0, "   <|>Option 'restrictToVisibleElements' is ON, but no visible elements were found");
      found = true;
    }
    if(_param.compute.onlyCurved && counts.elemCurved == 0) {
      _warn(0, "   <|>Option 'restrictToCurvedElements' is ON, but no curved elements were found");
      found = true;
    }
    size_t countType = 0;
    if(_param.compute.onlyGivenElemType) {
      for(int i = 0; i < TYPE_MAX_NUM; ++i) {
        if(_param.compute.acceptedElemType[i])
          countType += counts.elem_byType[i];
      }
      if(!countType) {
        _warn(0, "   <|>Option 'restrictToElementType' is ON, but no elements of the requested type were found");
        found = true;
      }
    }

    // ... due to a combination of those restrictions
    if(!found) {
      _info(0, "   The mesh contains:");
      int numCrit = 0;
      double percentage, numElement = counts.elem;
      if(_param.compute.onlyVisible) {
        percentage = static_cast<double>(counts.elemVisible) / numElement * 100;
        _info(0, "   * %s visible elements (~%.2g%% of the total)", formatNumber(counts.elemVisible).c_str(), percentage);
        ++numCrit;
      }
      if(_param.compute.onlyCurved) {
        percentage = static_cast<double>(counts.elemCurved) / numElement * 100;
        _info(0, "   * %s curved elements (~%.2g%% of the total)", formatNumber(counts.elemCurved).c_str(), percentage);
        ++numCrit;
      }
      if(_param.compute.onlyGivenElemType) {
        percentage = static_cast<double>(countType) / numElement * 100;
        _info(0, "   * %s elements of the requested type (~%.2g%% of the total)", formatNumber(countType).c_str(), percentage);
        ++numCrit;
      }
      if(numCrit == 2)
        _warn(0, "   No elements satisfy both criteria");
      else if(numCrit == 3)
        _warn(0, "   No elements satisfy all three criteria");
      else
        _error(0, "   Unexpected state: this case should not occur");
    }
  }
  else {
    // Case where no elements are found
    if(!_m->getNumFaces() && !_m->getNumRegions()) {
      _warn(0, "   No geometry was found in the current model");
    }
    else if(_dimensionPolicy == -2 && !_m->getNumFaces() && _m->getNumRegions()) {
      // NOTE: This actually never happen because a GRegion always require
      //       a GFace as boundary
      _warn(0, "   Planned to check the 2D meshes as 'dimensionPolicy' is set to -2, but no mesh was found");
      _warn(0, "   3D geometry was found instead. Consider setting 'dimensionPolicy' to 0");
    }
    else {
      _warn(0, "   No mesh was found in the current model");
    }
  }
}

bool Plug::_checkAndGuideNoDataToShow(Counts counts, bool check2D, bool check3D) const
{
  const int *which = _param.show.which;

  // Step 1: Calculate number of desired and undesired metric values
  size_t numDesiredVals = 0, numUndesiredVals = 0;
  std::size_t *available = counts.metricValsAvailOnSelectedElem;

  auto addMetricValues = [&](int metricFlag, std::size_t metricVal)
  {
    if(which[metricFlag])
      numDesiredVals += metricVal;
    else
      numUndesiredVals += metricVal;
  };

  addMetricValues(VALIDITY, available[0]);
  addMetricValues(UNFLIP, available[0]);
  addMetricValues(MINJAC, available[0] + available[1]);
  addMetricValues(RATIOJAC, available[0] + available[1]);
  addMetricValues(GEOFIT, available[2]);
  addMetricValues(DISTO, available[3]);
  addMetricValues(ASPECT, available[4]);

  // Step 2: Check if there are available computed values for desired metrics
  if(numDesiredVals > 0)
    return true; // Metrics available -> Continue processing
  _error(MP, "-> No data to output");

  // Step 3: Case 1 - 'omitMetricComputation' is activated
  if(_param.compute.skip) {
    _warn(MP, "   <|>Option 'omitMetricComputation' is ON but there are no "
               "previously computed data corresponding to desired metrics for "
               "the selected elements");

    if(numUndesiredVals > 0) {
      _info(0, "   The following metrics are available for the selected elements:");
      if(!which[VALIDITY] && available[0]) _info(0, "   * Validity");
      // if(!which[UNFLIP] && available[0]) _info(0, "   * Unflip");
      if(!which[DISTO] && available[3]) _info(0, "   * Disto");
      if(!which[ASPECT] && available[4]) _info(0, "   * Aspect");
      if(!which[GEOFIT] && available[2]) _info(0, "   * GeoFit");
      if(!which[MINJAC] && available[0]+available[1]) _info(0, "   * minJ");
      if(!which[RATIOJAC] && available[0]+available[1]) _info(0, "   * minJ/maxJ");
    }
  }

  // Step 4: Case 2 - Check compatibility of requested metrics with geometry
  bool wantValidity = std::abs(which[VALIDITY]) + std::abs(which[UNFLIP]);
  bool wantGeoFit = std::abs(which[GEOFIT]);
  bool wantOther = std::abs(which[MINJAC]) + std::abs(which[RATIOJAC]) + std::abs(which[DISTO]) + std::abs(which[ASPECT]);

  bool wantValidityOnly = wantValidity && !wantGeoFit && !wantOther;
  bool wantGeoFitOnly = !wantValidity && wantGeoFit && !wantOther;

  size_t numReqElemOnCurvGeo = counts.reqElemOnCurvGeo;
  size_t numReqElemOnFlatGeo = counts.reqElem - counts.reqElemOnCurvGeo;
  size_t numElemOnCurvGeo = counts.elemOnCurvGeo;
  size_t numElemOnFlatGeo = counts.elem - counts.elemOnCurvGeo;

  bool hasCurvGeo = false;
  bool hasFlatGeo = false;

  if(check2D) {
    hasCurvGeo |= counts.geoEntCurved[1];
    hasFlatGeo |= counts.geoEntFlat[1];
  }
  if(check3D) {
    hasFlatGeo |= counts.geoEntFlat[2];
  }

  if(wantValidityOnly && numReqElemOnFlatGeo == 0) {
    if(!hasFlatGeo) {
      _warn(MP, "   <|>Validity is the only requested metric, but all geometry entities are curved");
      _info(0, "   <|>Validity is not defined on curved geometry entities. Please enable another metric");
    }
    else {
      _warn(MP, "   <|>Validity is the only requested metric, but all selected elements are on curved geometry entities");
      if(numElemOnFlatGeo > 0)
        _info(0, "   <|>The model contains %s unselected elements on flat geometry entities",
              formatNumber(numElemOnFlatGeo).c_str());
      else
        _info(0, "   <|>The model does not contain elements on flat geometry entities");
    }
  }

  if(wantGeoFitOnly && numReqElemOnCurvGeo == 0) {
    if(!hasCurvGeo) {
      _warn(MP, "   <|>GeoFit is the only requested metric, but all geometry entities are flat");
      _info(0, "   <|>GeoFit is not defined on flat geometry entities. Please enable another metric");
    }
    else {
      _warn(MP, "   <|>GeoFit is the only requested metric, but all selected elements are on flat geometry entities");
      if(numElemOnCurvGeo > 0)
        _info(0, "   <|>The model contains %s unselected elements on curved geometry entities",
          formatNumber(numElemOnCurvGeo).c_str());
      else
        _info(0, "   <|>The model does not contain elements on curved geometry entities");
    }
  }

  return false;
}

// ======== struct Counts ======================================================
// =============================================================================

Plug::Counts Plug::Counts::operator+(const Counts &other) const
{
  Counts result;

  constexpr int metricsCount = 5;
  for (int i = 0; i < metricsCount; ++i) {
    result.metricValsToCompute[i] = metricValsToCompute[i] + other.metricValsToCompute[i];
    result.metricValsAvailOnSelectedElem[i] = metricValsAvailOnSelectedElem[i] + other.metricValsAvailOnSelectedElem[i];
  }

  result.reqElem = reqElem + other.reqElem;
  result.reqElemOkGeoFit = reqElemOkGeoFit + other.reqElemOkGeoFit;
  result.reqElemOnCurvGeo = reqElemOnCurvGeo + other.reqElemOnCurvGeo;

  result.distoOrAspectToComputeButUnknownValidity =
    distoOrAspectToComputeButUnknownValidity
  + other.distoOrAspectToComputeButUnknownValidity;

  result.elem = elem + other.elem;
  result.elemOnCurvGeo = elemOnCurvGeo + other.elemOnCurvGeo;
  result.elemVisible = elemVisible + other.elemVisible;
  result.elemCurved = elemCurved + other.elemCurved;
  result.elemWithKnownCurving = elemWithKnownCurving + other.elemWithKnownCurving;

  for (int i = 0; i < TYPE_MAX_NUM; ++i) {
    result.elem_byType[i] = elem_byType[i] + other.elem_byType[i];
  }
  for(int i = 0; i < 3; ++i) {
    result.geoEntFlat[i] = geoEntFlat[i] + other.geoEntFlat[i];
    result.geoEntCurved[i] = geoEntCurved[i] + other.geoEntCurved[i];
  }
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
  combineVectors(result.isNotFlipped, m1.isNotFlipped, m2.isNotFlipped);
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
  result.numFlippedElements = m1.numFlippedElements + m2.numInvalidElements;
  for(int i = 0; i < METRIC_COUNT; ++i) {
    result.numToShow[i] = m1.numToShow[i] + m2.numToShow[i];
  }
  return result;
}

void Plug::Measures::getValues(Metric m, std::vector<double> &values, std::vector<MElement *> *elements) const
{
  const std::vector<double> &val = _getValues(m);
  const std::vector<MElement *> &elem = _getElements(m);

  if(numToShow[m] == val.size()) {
    values = val;
    if(elements) *elements = elem;
    return;
  }

  // Filter the values
  values.resize(numToShow[m]);
  if(elements) elements->resize(numToShow[m]);

  int k = 0;
  for (size_t i = 0; i < val.size(); ++i) {
    if (val[i] != NOTCOMPUTED) {
      values[k] = val[i];
      if (elements) (*elements)[k] = elem[i];
      ++k;
    }
  }

  if(k != numToShow[m])
    _error(0, "Internal error: not all values have been computed");
}

const std::vector<double> &Plug::Measures::_getValues(Metric m) const
{
  switch(m) {
  case VALIDITY:
    return isValid;
  case UNFLIP:
    return isNotFlipped;
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

const std::vector<MElement *> &Plug::Measures::_getElements(Metric m) const
{
  if(m == GEOFIT)
    return elementsGFit;
  if(m == VALIDITY)
    return elementsStraightGeo;
  return elements;
}

#endif
