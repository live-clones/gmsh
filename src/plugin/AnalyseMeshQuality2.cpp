// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include <numeric>
#include <sstream>
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
#include "BasisFactory.h"
#endif
// NOTE What does the plugin
//  0.Free data and stop IF freeData-nothingElse = ON
//  1.Compute validity/quality IF skipComputationMetrics = OFF
//   • Clear old data IF preserveOldMeshData = OFF
//   • Limit to GEntity in GModel::current()
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 meshes
//     - IF = 0 Limit to dimension 3 meshes if there is any 3D mesh otherwise
//              limit to dimension 2 meshes
//     - IF >= 1 do not limit (both dimension 2 and 3 meshes)
//   • Limit to visible elements IF restrictToVisibleElements = ON
//   • Limit to curved elements IF restrictToCurvedElements = ON
//   • Check if previous data can be reused IF smartRecomputation = ON
//   • Compute Validity IF skipValidity = OFF
//   • Compute Distortion IF enableDistortionQuality > 0
//   • Compute Aspect IF enableAspectQuality > 0
//   • Regularize Jacobian if skipValidity = OFF AND regularizeDeterminant = ON
//  2.Print statistics
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 data
//     - IF = 0 Limit to dimension 3 data if there is any 3D mesh otherwise
//              limit to dimension 2 data
//     - IF = 1 do not limit (dimension 2 and 3 data separately)
//     - IF = 2 combine dimension 2 and 3 data
//   • In columns: min, max and Worst Weighted Means of UNPACK(wmCutoffsForStats)
//   • Validity IF skipValidity = OFF
//   • Distortion IF enableDistortionQuality > 0
//   • Aspect IF enableAspectQuality > 0
//   • minJ IF skipValidity = OFF AND enableMinJacDetAsAMetric > 0
//   • minJ/maxJ IF skipValidity = OFF AND enableMinJacDetAsAMetric > 0
//  3.Create PViewElementData IF createElementsView = ON
//   • In function of dimensionPolicy:
//     - IF = -1 Limit to dimension 2 data
//     - IF = 0 Limit to dimension 3 data if there is any 3D mesh otherwise
//              limit to dimension 2 data
//     - IF >= 1 do not limit (dimension 2 and 3 data) (combined not possible)
//   • Let M = max(enableDistortionQuality, enableAspectQuality, enableRatioJacDetAsAMetric, enableMinJacDetAsAMetric)
//   • Validity IF skipValidity = -M
//   • Distortion IF enableDistortionQuality = M
//   • Aspect IF enableAspectQuality = M
//   • minJ IF skipValidity = OFF AND enableMinJacDetAsAMetric = M
//   • minJ/maxJ IF skipValidity = OFF AND enableMinJacDetAsAMetric = M
//   • But: skip creation if PView already exists and unchanged data
//  4.Create PView2D IF createPlotView = ON
//   • In function of dimensionPolicy, as for (2.Print statistics)
//   • For metrics as for (3.Create PViewElementData IF createElementsView = ON).
//   • For Worst Weighted Means in function of UNPACK(wmCutoffsForPlots)
//   • But: skip creation if PView already exists and unchanged data
//  5.Hide elements IF hideElements >= 1
//   • In function of dimensionPolicy, as for (2.Print statistics)
//   • In function of hidingPolicy in the case hideWorst = OFF:
//     - IF = -1 Limit to valid elements if there are any invalid elements,
//               OTHERWISE skip hiding
//     - IF = 0 as (IF = 1) if no invalid elements OTHERWISE as (IF = -1)
//     - IF = 1 Limit to elements that do not meet criterion for the metric==M
//              if there is only one metric that is equal to M
//              OTHERWISE as (IF = 2)
//     - IF = 2 Limit to that do not meet all criterion for metrics==M
//     - IF = 3 Limit to that do not meet any criterion for metrics==M
//   • In function of hidingCriterion in the case hideWorst = OFF:
//     - IF = 0 Use metricValue <= x as criterion
//     - IF = 1 Use x worst elements as criterion
//     - IF = 2 Use (100*x)% worst elements as criterion
//     where x = hidingThreshold
//   • Hide worst element instead of best IF hideWorst = ON
//   • Unhide others IF unhideOtherElements = ON
//   • In function of hideElements:
//     - IF = 1 Skip hiding if all elements are to be hidden
//     - IF >= 2 Hide even if all elements are to be hidden

namespace {
  constexpr double UNTOUCHED = -987654321;
}

StringXNumber MeshQuality2Options_Number[] = {
  // What to do:
  {GMSH_FULLRC, "skipComputationMetrics", nullptr, 0, "OFF, ON=usePreviousData"},
  {GMSH_FULLRC, "createElementsView", nullptr, 0, "0, 1"},
  {GMSH_FULLRC, "createPlotView", nullptr, 0, "0, 1"},
  {GMSH_FULLRC, "hideElements", nullptr, 0, "OFF, 1=skipHidingIfAllWouldBeHidden, 2=forceHiding"},
  {GMSH_FULLRC, "guidanceLevel", nullptr, 0, "-1=minimalOutput, 0=verbose, 1=verboseAndExplanations"},
  // Metrics to include:
  {GMSH_FULLRC, "enableDistortionQuality", nullptr, 1, "OFF, 1+=includeDistortionQuality"},
  {GMSH_FULLRC, "enableAspectQuality", nullptr, 1, "OFF, 1+=includeAspectQuality"},
  // Elements Selection:
  {GMSH_FULLRC, "dimensionPolicy", nullptr, 0, "-1=force2D, 0=prioritize3D, 1=2D+3D, 2=combine2D+3D"},
  {GMSH_FULLRC, "restrictToVisibleElements", nullptr, 0, "OFF, ON=analyzeOnlyVisibleElements"},
  {GMSH_FULLRC, "restrictToCurvedElements", nullptr, 0, "OFF, ON=analyzeOnlyNonStraightElements"},
  // Hiding options:
  {GMSH_FULLRC, "hidingPolicy", nullptr, 0, "-1=validity|skip, 0=validity|1, 1=oneQual|2, 2=qualOR, 3=qualAND"},
  {GMSH_FULLRC, "hidingCriterion", nullptr, 0, "0=qualValue, 1=numElem, 2=proportionElem"},
  {GMSH_FULLRC, "hidingThreshold", nullptr, .1, "DOUBLE"},
  {GMSH_FULLRC, "hideWorst", nullptr, 0, "OFF=hideBest, ON"},
  {GMSH_FULLRC, "unhideOtherElements", nullptr, 0, "OFF=justHide, ON=alsoUnhide"},
  // Advanced computation options:
  {GMSH_FULLRC, "smartRecomputation", nullptr, 0, "OFF=alwaysRecompute, ON=doNotRecomputeIfElementTagsUnchanged"},
  {GMSH_FULLRC, "dataManagementPolicy", nullptr, 0, "-1=skipExecutionJustFreeData, 0=freeOldData, 1=accumulateData"},
  {GMSH_FULLRC, "skipValidity", nullptr, 0, "OFF, ON=skipPreventiveValidityCheck"},
  // Advanced analysis options:
  {GMSH_FULLRC, "enableRatioJacDetAsAMetric", nullptr, 1, "OFF, 1+"},
  {GMSH_FULLRC, "enableMinJacDetAsAMetric", nullptr, 1, "OFF, 1+"},
  {GMSH_FULLRC, "regularizeDeterminant", nullptr, 1, "OFF, ON=inverseOrientationIfAbsMaxSmaller"},
  {GMSH_FULLRC, "wmCutoffsForStats", nullptr, 1025, "CUTOFFS (for stats weighted mean, see Help)"},
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
  // NOTE Proposition
  //  3. Clarify what I use: Disto and aspect are quality metrics.
  //                         Computing them is evaluating.
  //                         The resulting data are values or results (or measures?).
  //  4. Rename Disto->Distortion, Measures->Results
  //  5. Consider (and make sure) that the number of values in results are
  //     identical for each metric. This is for simplification.
  //  6. Add vector of pointers to MElement into Measures(Results) to be able to
  //     change visibility and create PViews without returning into DataGentities
  //  7. Store sorted vectors into Measures(Results)?
#if defined(HAVE_VISUDEV)
  ,
  {GMSH_FULLRC, "createTemporalView", nullptr, 0},
  {GMSH_FULLRC, "createPointwiseView", nullptr, 0},
  {GMSH_FULLRC, "elementIDForPwView", nullptr, 0}
#endif
};

const int MeshQuality2Options_LegacyOptionsNumber = 8;

std::pair<int, std::string> MeshQuality2Options_Headers[] = {
  {0, "What to do"},
  {5, "Metrics to include"},
  {7, "Elements Selection"},
  {10, "Hiding options"},
  {15, "Advanced computation options"},
  {18, "Advanced analysis options"},
  {23, "Legacy options"},
  };

// What to do:
// - skipComputationMetrics = 0
// - createElementsView = 0
// - createPlotView = 0
// - hideElements = 0
// - printGuidance = 0

// Metrics configuration:
// - enableDistortionQuality = 1
// - enableAspectQuality = 1

// Element Selection:
// - dimensionPolicy = 0
// - restrictToVisibleElements = 0
// - restrictToCurvedElements = 0

// Hiding options:
// - hidingPolicy = 0
// - hidingCriterion = 0
// - hidingThreshold = .5
// - hideWorst = 0
// - unhideOtherElements = 0

// Advanced computation options:
// - smartRecomputation = 0
// - preserveOldMeshData = 0
// - skipValidity = 0
// - freeData-NothingElse = 0

// Advanced analysis options
// - enableRatioJacDetAsAMetric = 0
// - enableMinJacDetAsAMetric = 0
// - regularizeDeterminant = 0
// - wmCutoffsForStats = 10
// - wmCutoffsForPlots = 10

// Legacy (do not modify, will be removed in the future):
// - JacobianDeterminant
// - IGEMeasure
// - ICNMeasure
// - HidingThreshold
// - ThresholdGreater
// - CreateView
// - Recompute
// - DimensionOfElements

// NOTE About legacy parameters:
//  They take a default value (e.g. -987654321) that is easily detectable
//  If a parameter is not at default value, then the plugin print an error
//  message, explain how to convert options, explian the changes and then
//  run the plugin with following change:
//  freeData-NothingElse = 0
//  computeMetrics = 1
//  createViews = CreateView
//  hideElements = HidingThreshold < 99
//  printGuidance = printGuidance==-1 ? 0 : 1
//  enableAspectQuality = IGEMeasure
//  enableDistortionQuality = ICNMeasure
//  dataClearancePolicy = Recompute ? 2 : 0
//  dimensionPolicy = Recompute==2 ? -1 :
//                    Recompute==4 ? 1 : 0
//  restrictToVisibleElements = 0
//  restrictToCurvedElements = 0
//  enableElementsView = 1
//  enablePlotView = 0
//  hidingPolicy = 1
//  hidingCriterion = 1
//  hidingThreshold = HidingThreshold
//  hideWorst = !ThresholdGreater
//  unhideOtherElements = 0
//  weightedMeanCutoffPackForStats = 50
//  enableRatioJacDetAsAMetric = 1
//  enableMinJacDetAsAMetric = 1
//  skipValidity = !JacobianDeterminant
//

using Plug = GMSH_AnalyseMeshQuality2Plugin;
namespace JacQual = jacobianBasedQuality;
int Plug::_verbose = 0;

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
  return "Plugin(AnalyseMeshQuality2) analyses the quality of the elements "
         "of a given dimension in the current model. Depending on the input "
         "options it computes the minimum of the Jacobian determinant (J), "
         "the IGE quality measure (Inverse Gradient Error) and/or the ICN "
         "quality measure (Condition Number). Statistics are printed and, "
         "if requested, a model-based post-processing view is created for each "
         "quality measure. The plugin can optionally hide elements by "
         "comparing the measure to a prescribed threshold.\n"
         "\n"
         "J is faster to compute but gives information only on element "
         "validity while the other measures also give information on element "
         "quality. The IGE measure is related to the error on the gradient of "
         "the finite element solution. It is the scaled Jacobian for quads and "
         "hexes and a new measure for triangles and tetrahedra. "
         "The ICN measure is related to the condition number of the stiffness "
         "matrix. (See the article \"Efficient computation of the minimum of "
         "shape quality measures on curvilinear finite elements\" for "
         "details.)\n"
         "\n"
         "Options:\n"
         "\n"
         "- `JacobianDeterminant': compute J?\n"
         "\n"
         "- `IGEMeasure': compute IGE?\n"
         "\n"
         "- `ICNMeasure': compute ICN?\n"
         "\n"
         "- `HidingThreshold': hide all elements for which min(mu) is "
         "strictly greater than (if `ThresholdGreater' == 1) or less than "
         "(if `ThresholdGreater' == 0) the threshold, where mu is ICN if "
         "`ICNMeasure' == 1, IGE if `IGEMeasure' == 1 or min(J)/max(J) if "
         "`JacobianDeterminant' == 1.\n"
         "\n"
         "- `CreateView': create a model-based view of min(J)/max(J), "
         "min(IGE) and/or min(ICN)?\n"
         "\n"
         "- `Recompute': force recomputation (set to 1 if the mesh has "
         "changed).\n"
         "\n"
         "- `DimensionOfElements': analyse elements of the given dimension if "
         "equal to 1, 2 or 3; analyse 2D and 3D elements if equal to 4; "
         "or analyse elements of the highest dimension if equal to -1.";
}

PView *Plug::execute(PView *v)
{
  _info(0, "----------------------------------------");
  _info(0, "=> Executing the plugin AnalyseMeshQuality...");

  _fetchParameters();

  _info(1, "=> Option 'printGuidance' is ON. ");
  _info(1, "   This makes the plugin to be verbose and to provide various explanations");

  // Handle cases where no computation is requested
  if(_param.freeData) {
    _info(-1, "=> Freeing data...");
    _info(1, "=> Freeing data... (because option 'freeData-NothingElse' is ON)");
    _data2D->clear();
    _data3D->clear();
    MeshQuality2Options_Number[18].def = 0;
    _info(0, "   Done. Option 'freeData-NothingElse' has been set to OFF");
    _info(1, "   Nothing else to do, rerun the plugin to compute something");
    return v;
  }

  Parameters::Computation &pc = _param.compute;
  if(!pc.validity && !pc.disto && !pc.aspect) {
    _warn(0, "=> Nothing to do because 'checkValidity', 'checkQualityDisto' and "
          "'checkQualityAspect' are all three OFF");
    return v;
  }

  GModel *m = GModel::current();
  if(pc.policy == 0 && _m && _m != m) {
    _info(1, "=> Detected a new Model, previous data will be cleared");
    // FIXME may not be the case (can we create a new model with exact same geometry and mesh?)
    // FIXME depend on clearancePolicy
  }
  _m = m;

  // Check which dimension to compute/show, initialize data and counts elements
  bool check2D, check3D;
  _decideDimensionToCheck(check2D, check3D);

  Counts counts2D, counts3D;
  if(check2D) _data2D->initialize(_m, _param.compute, counts2D);
  if(check3D) _data3D->initialize(_m, _param.compute, counts3D);

  // // TMP Dev
  // _devPrintCount(counts2D);
  // _devPrintCount(counts3D);

  // Computation
  std::size_t totalToCompute = _printElementToCompute(counts2D, counts3D);
  Counts countsTotal = counts2D + counts3D;
  if(!totalToCompute) {
    std::size_t totalToShow = _guidanceNothingToCompute(countsTotal,
      check2D, check3D);
    if(!totalToShow) return v;
  }
  else {
    if(!_param.checkValidity && countsTotal.elToCompute[0] > 0) {
      _info(1, "=> Validity will be computed even if not asked");
      _info(1, "   Reason is that validity is quite cheap in comparison to quality and can significantly ");
      _info(1, "   boost speed. This behaviour can be disabled by setting ON option ");
      _info(1, "   'skipPreventiveValidityCheck', which is a good idea if the elements are known to be valid.");
    }
    else if(pc.lazyValidity) {
      _warn(1, "=> Option 'skipPreventiveValidityCheck' is ON, validity will not be computed");
      _warn(1, "   This may significantly slow down quality computation in the presence of invalid elements");
    }
    _computeMissingData(countsTotal, check2D, check3D);
  }

  // Gather data
  Measures measures2D(_param.checkValidity, pc.disto, pc.aspect);
  Measures measures3D(_param.checkValidity, pc.disto, pc.aspect);
  if(check2D) _data2D->gatherValues(counts2D, measures2D);
  if(check3D) _data3D->gatherValues(counts3D, measures3D);

  _param.check2D = check2D;
  _param.check3D = check3D;
  _statGen->printStats(_param, measures2D, measures3D);


  // TODO compute show

  return v;
}

// ======== Plugin: private methods ============================================
// =============================================================================

void Plug::_fetchParameters()
{
  Parameters::Computation &pc = _param.compute;
  Parameters::Post &pp = _param.pview;
  Parameters::Hidding &ph = _param.hide;
  int checkValidity = static_cast<int>(MeshQuality2Options_Number[0].def);
  int checkDisto = static_cast<int>(MeshQuality2Options_Number[1].def);
  int checkAspect = static_cast<int>(MeshQuality2Options_Number[2].def);
  // NOTE dimensionPolicy: highest dimension available -> 0, only 2D -> 1,
  //      2D and 3D : seperately -> 2, mixed -> 3
  _dimensionPolicy = static_cast<int>(MeshQuality2Options_Number[3].def);
  _param.dimPolicy = _dimensionPolicy;

  // NOTE recomputePolicy:
  //      - delete nothing, compute nothing, output prevsly computed data -> -2
  //        which is useful for adding creation of pview (to check: hiding!)
  //      The other options provide an identical output, but differ how
  //      existent data are treated.
  //      NB: In what follows, the "asked elements" are the elements for which
  //      visibility is compatible with 'restrictToVisibleElements' parameter
  //      and similarly for 'restrictToCurvedElements'.
  //      - delete nothing, compute newly asked elements -> -1
  //      - delete GEntities that are not existent in current GModel,
  //        delete data in GEntities that have detected mesh modifications,
  //        (re)compute data for asked elements and newly asked elements -> 0
  //      - delete GEntities that are not existent in current GModel,
  //        delete data in all GEntities,
  //        compute asked elements -> 1
  // FIXME -1 is useful if it is possible to call the plugin with different
  //  geometries then call it again with previous one. The case I am thinking
  //  about is if the user can switch the current GModel and come back to the
  //  previous one, and in the GUI. Check that this is true.
  pc.policy = static_cast<int>(MeshQuality2Options_Number[4].def);
  pc.onlyVisible = static_cast<bool>(MeshQuality2Options_Number[5].def);
  pc.onlyCurved = static_cast<bool>(MeshQuality2Options_Number[6].def);
  bool lazyValidity = static_cast<bool>(MeshQuality2Options_Number[7].def);
  pc.disto = static_cast<bool>(checkDisto);
  pc.aspect = static_cast<bool>(checkAspect);
  pc.validity = checkValidity || (!lazyValidity && (pc.disto || pc.aspect));
  _param.checkValidity = static_cast<bool>(checkValidity);

  _param.statCutoffPack = MeshQuality2Options_Number[8].def;
  _param.printJac = static_cast<bool>(MeshQuality2Options_Number[9].def);
  pp.create3D = static_cast<bool>(MeshQuality2Options_Number[10].def);
  pp.create2D = static_cast<bool>(MeshQuality2Options_Number[11].def);
  pp.plotCutoffPack = MeshQuality2Options_Number[12].def;
  pp.forceNew = static_cast<bool>(MeshQuality2Options_Number[13].def);
  ph.yes = static_cast<bool>(MeshQuality2Options_Number[14].def);
  ph.worst = static_cast<bool>(MeshQuality2Options_Number[15].def);
  ph.criterion = static_cast<int>(MeshQuality2Options_Number[16].def);
  ph.threshold = MeshQuality2Options_Number[17].def;
  _myVerbose = static_cast<bool>(MeshQuality2Options_Number[18].def);
  _param.freeData = static_cast<bool>(MeshQuality2Options_Number[19].def);

  _statGen->setCutoffStats(_param.statCutoffPack);
  _statGen->setCutoffPlots(_param.statCutoffPack);
  _verbose = _myVerbose;

  //
  if(_dimensionPolicy < 0)
    _dimensionPolicy = 0;
  else if(_dimensionPolicy > 3)
    _dimensionPolicy = 3;

  if(pc.policy < -2)
    pc.policy = -2;
  else if(pc.policy > 1)
    pc.policy = 1;

  // FIXME Warnings if verbose

#if defined(HAVE_VISUDEV)
  // TODO come back later
  _pwJac = checkValidity / 2;
  _pwIGE = computeDisto / 2;
  _pwICN = computeAspect / 2;

  // NOTE About createTimeView:
  //  check if PView::_data::NbTimeStep if _data of type PViewDataList
  //  check if PView::_options::vectorType == PViewOptions::Displacement (5),
  //  or just consider that NbTimeStep is sufficient

  bool createTimeView = static_cast<bool>(MeshQuality2Options_Number[20].def);
  _createPwView = static_cast<bool>(MeshQuality2Options_Number[21].def);
  _elemNumForPwView = static_cast<int>(MeshQuality2Options_Number[22].def);
  _viewOrder = 0;
  _dataPViewJac.clear();
  _dataPViewIGE.clear();
  _dataPViewICN.clear();
#endif
}

void Plug::_computeMissingData(Counts counts, bool check2D, bool check3D) const
{
  std::vector<DataEntity*> allDataEntities;
  if(check2D)
    _data2D->getDataEntities(allDataEntities);
  if(check3D)
    _data3D->getDataEntities(allDataEntities);

  if(counts.elToCompute[0] > 0) {
    Msg::StatusBar(true, "   Computing Validity...");
    MsgProgressStatus progress_status(counts.elToCompute[0]);
    for(auto data: allDataEntities) {
      data->computeValidity(progress_status);
    }
  }

  if(counts.elToCompute[1] > 0) {
    Msg::StatusBar(true, "   Computing Distortion quality...");
    MsgProgressStatus progress_status(counts.elToCompute[1]);
    for(auto data: allDataEntities) {
      data->computeDisto(progress_status, _param.compute.lazyValidity);
    }
  }

  if(counts.elToCompute[2] > 0) {
    Msg::StatusBar(true, "   Computing Aspect quality...");
    MsgProgressStatus progress_status(counts.elToCompute[2]);
    for(auto data: allDataEntities) {
      data->computeAspect(progress_status, _param.compute.lazyValidity);
    }
  }

  Msg::StatusBar(true, "   Done computing quantities");
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
  else if(_dimensionPolicy < 2)
    check3D = false;
}

// ======== StatGenerator ======================================================
// =============================================================================

void Plug::StatGenerator::printStats(const Parameters &param,
                                     const Measures &m2,
                                     const Measures &m3)
{
  _info(1, "=> Printing statistics, here is what is important to know about "
           "them:");
  _info(1, "   - *Validity* give information about the strict positivity "
           "of the Jacobian determinant.");
  _info(1, "     A mesh containing invalid elements will usually lead to "
           "incorrect Finite Element solutions.");
  _info(1, "   - *Disto* quality (previously ICN) is related to the condition "
           "number of the stiffness matrix.");
  _info(1, "     Low-Disto elements can introduce roundoff errors, or "
           "significantly reduce the convergence");
  _info(1, "     speed of iterative methods. ");
  _info(1, "   - *Aspect* quality (previously IGE) is related to the gradient "
           "of the FE solution");
  _info(1, "     Low-IGE elements influence negatively the error on the "
           "gradient.");
  if(param.printJac) {
    _info(1, "   - Computing the Jacobian determinant (J) is required to "
             "assess elements validity.");
    _info(1, "     As it is readily available, three optional statistics can be calculated: ");
    _info(1, "     1. the minimal value, minJ, and");
    _info(1, "     2. the maximal value, maxJ, and");
    _info(1, "     3. the ration minJ/maxJ.");
    _info(1, "     Note that neither of these metrics provides any information "
             "about any kind of quality.");
  }
  _info(1, "   - *Worst-K%% Weighted Mean* (WmK) corresponds to a weighted mean "
           "where the worst K%% of values are assigned the same ");
  _info(1, "     weight as the other values. This approach is preferable to "
           "the standard mean because it emphasizes the worst ");
  _info(1, "     elements which are critical as they can negatively impact the "
           "Finite Element solution.");
  _info(1, "     Note that the standard mean corresponds to Wm50.");

  if(param.dimPolicy == 3) {
    Measures combined(m2.validity, m2.disto, m2.aspect);
    combined.minJ = m2.minJ;
    combined.minJ.insert(combined.minJ.end(), m3.minJ.begin(), m3.minJ.end());
    combined.maxJ = m2.maxJ;
    combined.maxJ.insert(combined.maxJ.end(), m3.maxJ.begin(), m3.maxJ.end());
    combined.minDisto = m2.minDisto;
    combined.minDisto.insert(combined.minDisto.end(), m3.minDisto.begin(), m3.minDisto.end());
    combined.minAspect = m2.minAspect;
    combined.minAspect.insert(combined.minAspect.end(), m3.minAspect.begin(), m3.minAspect.end());

    _printStats(combined, "2 and 3 combined", param.printJac);
    return;
  }

  if(param.check2D) _printStats(m2, "2", param.printJac);
  if(param.check3D) _printStats(m3, "3", param.printJac);
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

void Plug::StatGenerator::_printStats(const Measures &measure, const char* str_dim, bool printJac)
{
  // NOTE:
  //  1. Create a class for percentile? The idea is to have a black box for
  //     computing the Paverage. The coeff are stored for reuse. Say for
  //     10 different number of elements
  //  2. I will print the exact Paverage (on all elements) not some %. Because
  //     % depends on the min so it is hard to compare meshes with %. I was
  //     disturbed that the worst element count for so much but the whole point
  //     is that worst elements counts much more than the best.
  //  3. Add printStatJac with warning
  //  4. Potential name for the measure: WM10 (Worst-10% Weighted Mean)
  //  5. Potential name for the parameters: statsWeightedMeanCutoffPack, plotWeightedMeanCutoffPack
  //  6. Structure:
  //     • verbose => info("Here is what is important to know about the stats: )
  //       - Validity is for that
  //       - Disto = measures this
  //       - Aspect = measures that
  //       - Jmin = gives that information
  //       - Jmin/Jmax = gives that information
  //       - Worst-x% Weighted Mean: means that. Pure mean = WM50
  //     • separated by dimension
  //       - stats for dim x
  //       - headers
  //       - Disto
  //       - Aspect
  //       - Jmin
  //       - Jmin/Jmax
  //       - All valid/x invalid
  //     • verbose+Jac => warn Jacobian is not a quality
  //  6. Verbose => Add at the end of execute info(Done, you can disable verbose)
  //     OR => verbose off by default and end by saying that verbose can be set on

  // FIXME: dev
  // _info(0, "dev check values %d %d %d %d", measure.disto, measure.aspect, measure.minDisto.size(), measure.minAspect.size());
  _info(0, "=> Statistics for dimension %s:", str_dim);

  // Header
  if(measure.disto || measure.aspect || printJac) {
    std::ostringstream columnNamesStream;
    columnNamesStream << "    ";
    columnNamesStream << std::setw(_colWidth) << "";
    columnNamesStream << std::setw(_colWidth) << "Min";
    for (double c : _statCutoffs) {
      std::ostringstream formattedP;
      formattedP << std::setprecision(2) << c;
      columnNamesStream << std::setw(_colWidth) << "Wm" + formattedP.str();
    }
    columnNamesStream << std::setw(_colWidth) << "Max";
    _info(0, "%s", columnNamesStream.str().c_str());
  }

  // Disto
  if(measure.disto && measure.minDisto.size())
    _printStatsOneMeasure(measure.minDisto, "Disto");

  // Aspect
  if(measure.aspect && measure.minAspect.size())
    _printStatsOneMeasure(measure.minAspect, "Aspect");

  if(!!printJac && !measure.validity) return;

  // Jacobian
  std::vector<double> ratio(measure.minJ.size());
  for(std::size_t i = 0; i < measure.minJ.size(); ++i) {
    if (measure.maxJ[i] > 0)
      ratio[i] = measure.minJ[i] / measure.maxJ[i];
    else
      ratio[i] = measure.maxJ[i] / measure.minJ[i];
  }
  int numInvalid = std::count_if(ratio.begin(), ratio.end(), [](double value) {
      return value <= 0;
  });
  if(printJac && measure.minJ.size()) {
    _printStatsOneMeasure(ratio, "minJ/maxJ");
    _printStatsOneMeasure(measure.minJ, "minJ", true);
    _printStatsOneMeasure(measure.maxJ, "maxJ", true);
  }

  if(!measure.validity) return;

  // Validity
  if(numInvalid)
    _warn(0, "   Found %d invalid elements", numInvalid);
  else
    _info(0, "   All elements are valid :-)", numInvalid);
}

void Plug::StatGenerator::_printStatsOneMeasure(const std::vector<double> &measure, const char* str, bool useG)
{
  size_t numElem = measure.size();
  size_t numCutoff = _statCutoffs.size();
  std::vector<double> q = measure;
  double min = *std::min_element(q.begin(), q.end());
  double max = *std::max_element(q.begin(), q.end());

  std::vector<double> avg(numCutoff);
  std::sort(q.begin(), q.end());
  for(int i = 0; i < numCutoff; ++i) {
    const std::vector<double> &coeff = _getCoefficients(_statCutoffs[i], numElem);
    avg[i] = std::inner_product(q.begin(), q.end(), coeff.begin(), 0.0);
  }

  std::ostringstream valStream;
  valStream << "   ";
  valStream << std::setw(_colWidth) << str << ":";
  valStream << std::setprecision(3);
  if(useG) valStream << std::defaultfloat; // can also be std::scientific
  valStream << std::setw(_colWidth) << min;
  for(auto i = 0; i < numCutoff; ++i)
    valStream << std::setw(_colWidth) << avg[i];
  valStream << std::setw(_colWidth) << max;
  _info(0, "%s", valStream.str().c_str());
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
  // Update list GEntities (thus _dataEntities) if needed
  if(param.policy >= -1) {
    std::vector<GEntity *> entities;
    if(_dim == 2)
      entities.insert(entities.end(), m->firstFace(), m->lastFace());
    else if(_dim == 3)
      entities.insert(entities.end(), m->firstRegion(), m->lastRegion());
    _updateGEntities(entities, param.policy);
  }

  // Initialize all DataEntity and count elements
  for(auto &it : _dataEntities) {
    it.second.initialize(param);
    it.second.count(param, counts);
  }
}

void Plug::DataSingleDimension::_updateGEntities(
  std::vector<GEntity *> &entities, int recomputePolicy)
{
  // Get GEntities present in the current model, add new ones in _dataEntities
  std::set<GEntity *, GEntityPtrLessThan> existingInModel;
  for(const auto &ge: entities) {
    existingInModel.insert(ge);
    if(_dataEntities.find(ge) == _dataEntities.end())
      _dataEntities.emplace(ge, DataEntity(ge));
  }

  if(recomputePolicy >= 0) {
    // Remove GEntities from _dataEntities that are not existent in the current model
    for(auto it = _dataEntities.begin(); it != _dataEntities.end();) {
      if(existingInModel.find(it->first) == existingInModel.end()) {
        // it->second.clear(); // FIXME check that i don't need this
        std::size_t numShownElement[3];
        it->second.getNumShownElement(numShownElement);
        for(int i = 0; i < 3; ++i) {
          if(numShownElement[i] > 0) _changedSincePViewCreation[i] = true;
        }
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
  measures.minJ.reserve(counts.elToShow[0]);
  measures.maxJ.reserve(counts.elToShow[0]);
  measures.minDisto.reserve(counts.elToShow[1]);
  measures.minAspect.reserve(counts.elToShow[2]);
  for(auto &it : _dataEntities) {
    it.second.addValues(measures);
  }
}

// ======== DataEntity =========================================================
// =============================================================================

constexpr int F_NOTJAC = 1 << 0;
constexpr int F_NOTDISTO = 1 << 1;
constexpr int F_NOTASPECT = 1 << 2;
constexpr int F_EXIST = 1 << 3;
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

void Plug::DataEntity::initialize(const Parameters::Computation &param)
{
  // FIXME: if -2, still have to update F_REQU
  //  and count show if F_REQU and not F_NOT..
  if(param.policy == -2) return;

  // Step 0: Get all elements present in GEntity
  std::size_t num = _ge->getNumMeshElements();
  std::vector<MElement *> elements;
  elements.reserve(num);
  for(auto i = 0; i < num; ++i) {
    elements.push_back(_ge->getMeshElement(i));
  }

  // Step 1: Check if must reset data, and update flag "exist in GEntity"
  int policy = param.policy;
  if(policy == 1 || (policy == 0 && num != _mapElemToIndex.size())) {
    reset(num);
    add(elements);
  }
  else if(policy == 0) {
    // Reset if elements are different
    for(auto i = 0; i < num; ++i) {
      if(_mapElemToIndex.find(elements[i]) == _mapElemToIndex.end()) {
        reset(num);
        add(elements);
        break;
      }
    }
  }
  else {
    // Here, policy <= -1, and we want to keep data for elements that are gone
    // but we have to set the flag "exists in GEntity" accordingly
    for(auto &flag : _flags) {
      unsetBit(flag, F_EXIST);
    }
    for(const auto &el : elements) {
      auto it = _mapElemToIndex.find(el);
      if(it != _mapElemToIndex.end()) {
        setBit(_flags[it->second], F_EXIST);
      }
      else {
        add(el);
      }
    }
  }

  // Step 3: Update flag isCurved if necessary
  if(param.onlyCurved) {
    const int mask = F_EXIST | F_CURVNOTCOMP;
    for(const auto &it : _mapElemToIndex) {
      const std::size_t index = it.second;

      if(areBitsSet(_flags[index], mask)) {
        bool isCurved = true;
        // TODO implement: bool isCurved = el->isCurved();
        unsetBit(_flags[index], F_CURVNOTCOMP);
        if(isCurved)
          setBit(_flags[index], F_CURVED);
        else
          unsetBit(_flags[index], F_CURVED);
      }
    }
  }

  // Step 4: Update flag isRequested
  for(auto &flag : _flags) {
    unsetBit(flag, F_REQU);
  }

  int maskRequested = F_EXIST;
  if(param.onlyVisible) maskRequested |= F_VISBL;
  if(param.onlyCurved) maskRequested |= F_CURVED;

  for(auto &flag : _flags) {
    if(areBitsSet(flag, maskRequested))
      setBit(flag, F_REQU);
  }
}

void Plug::DataEntity::count(const Parameters::Computation &param, Counts &counts)
{
  // Reset
  for(int i = 0; i < 3; ++i) {
    _numToCompute[i] = 0;
    _numToShow[i] = 0;
  }

  // Count number of elements to compute and to show
  if (param.validity)
    _count(F_REQU | F_NOTJAC, _numToCompute[0], _numToShow[0]);
  if (param.disto)
    _count(F_REQU | F_NOTDISTO, _numToCompute[1], _numToShow[1]);
  if (param.aspect)
    _count(F_REQU | F_NOTASPECT, _numToCompute[2], _numToShow[2]);

  for(int i = 0; i < 3; ++i) {
    counts.elToCompute[i] += _numToCompute[i];
    counts.elToShow[i] += _numToShow[i];
  }

  // Count total number, still existing, visible and curved
  counts.totalEl += _mapElemToIndex.size();
  for(const auto &flag : _flags) {
    if(isBitSet(flag, F_EXIST)) ++counts.existingEl;
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

void Plug::DataEntity::_count(unsigned char mask, std::size_t &elToCompute,
                                std::size_t &elToShow)
{
  for(const auto &flag : _flags) {
    if(areBitsSet(flag, mask)) {
      ++elToCompute;
      ++elToShow;
    }
    else if(isBitSet(flag, F_REQU)) {
      ++elToShow;
    }
  }
}

void Plug::DataEntity::computeValidity(MsgProgressStatus &progress_status)
{
  if(_ge->dim() == 2)
    _info(1, "   Surface %d: Computing validity of %d elements",
          _ge->tag(), _numToCompute[0]);
  else
    _info(1, "   Volume %d: Computing validity of %d elements",
          _ge->tag(), _numToCompute[0]);

  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTJAC)) {
      MElement *el = it.first;
      // TODO: give unique normal if planar surface
      JacQual::minMaxJacobianDeterminant(el, _minJ[idx], _maxJ[idx]);//, normals);
      unsetBit(_flags[idx], F_NOTJAC);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::computeDisto(MsgProgressStatus &progress_status, bool considerAsValid)
{
  if(_ge->dim() == 2)
    _info(1, "   Surface %d: Computing Distortion quality of %d elements",
          _ge->tag(), _numToCompute[1]);
  else
    _info(1, "   Volume %d: Computing Distortion quality of %d elements",
          _ge->tag(), _numToCompute[1]);

  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTDISTO)) {
      MElement *el = it.first;
      if(!considerAsValid  && _minJ[idx] <= 0 && _maxJ[idx] >= 0) {
        _minDisto[idx] = 0;
      }
      else {
        _minDisto[idx] = JacQual::minICNMeasure(el, true);
      }
      unsetBit(_flags[idx], F_NOTDISTO);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::computeAspect(MsgProgressStatus &progress_status, bool considerAsValid)
{
  // FIXME inverse "->". Use it for "headers" not for "paragraph"
  if(_ge->dim() == 2)
    _info(1, "   Surface %d: Computing Aspect quality of %d elements",
          _ge->tag(), _numToCompute[2]);
  else
    _info(1, "   Volume %d: Computing Aspect quality of %d elements",
          _ge->tag(), _numToCompute[2]);

  for(const auto &it : _mapElemToIndex) {
    const std::size_t idx = it.second;
    if(areBitsSet(_flags[idx], F_REQU | F_NOTASPECT)) {
      MElement *el = it.first;
      if(!considerAsValid  && _minJ[idx] <= 0 && _maxJ[idx] >= 0) {
        _minAspect[idx] = 0;
      }
      else {
        _minAspect[idx] = JacQual::minIGEMeasure(el, true);
      }
      unsetBit(_flags[idx], F_NOTASPECT);
      progress_status.next();
    }
  }
}

void Plug::DataEntity::reset(std::size_t num)
{
  _mapElemToIndex.clear();
  _minJ.clear();
  _maxJ.clear();
  _minDisto.clear();
  _minAspect.clear();
  _flags.clear();
  _minJ.reserve(num);
  _maxJ.reserve(num);
  _minDisto.reserve(num);
  _minAspect.reserve(num);
  _flags.reserve(num);
}

void Plug::DataEntity::add(MElement *el)
{
  std::size_t index = _minJ.size();
  _mapElemToIndex[el] = index;
  _minJ.push_back(std::numeric_limits<double>::max());
  _maxJ.push_back(std::numeric_limits<double>::min());
  _minDisto.push_back(std::numeric_limits<double>::max());
  _minAspect.push_back(std::numeric_limits<double>::max());
  unsigned char flag = F_NOTJAC | F_NOTDISTO | F_NOTASPECT | F_EXIST
                       | F_CURVNOTCOMP;
  if (el->getVisibility()) setBit(flag, F_VISBL);
  _flags.push_back(flag);
}

void Plug::DataEntity::addValues(Measures &measures)
{
  for(auto &it : _mapElemToIndex) {
    std::size_t idx = it.second;
    if(isBitSet(_flags[idx], F_REQU))
    {
      if(isBitUnset(_flags[idx], F_NOTJAC)) {
        measures.minJ.push_back(_minJ[idx]);
        measures.maxJ.push_back(_maxJ[idx]);
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

void Plug::_printMessage(void (*func)(const char *, ...), const char *format,
                         va_list args)
{
  char str[5000];
  vsnprintf(str, sizeof(str), format, args);
  func("%s", str);
}

void Plug::_info(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Info, format, args);
  va_end(args);
}

void Plug::_warn(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Warning, format, args);
  va_end(args);
}

void Plug::_error(int verb, const char *format, ...)
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Error, format, args);
  va_end(args);
}

// FIXME Implement this?
// void Plug::_status(int verb, const char *format, ...)
// {
//   if(!_okToPrint(verb)) return;
//   va_list args;
//   va_start(args, format);
//   _printMessage(Msg::Error, format, args);
//   va_end(args);
// }

std::size_t Plug::_printElementToCompute(const Counts &cnt2D,
                                         const Counts &cnt3D) const
{
  std::size_t sum2D = 0, sum3D = 0;
  for (std::size_t x : cnt2D.elToCompute) sum2D += x;
  for (std::size_t x : cnt3D.elToCompute) sum3D += x;

  if(sum2D + sum3D == 0) return 0;

  _info(0, "=> Number of evaluations to perform:");
  _info(0, "   %5s%10s%10s%10s", "", "Validity", "Disto", "Aspect");
  if(sum2D)
    _info(0, "   %5s%10d%10d%10d", "2D:", cnt2D.elToCompute[0],
          cnt2D.elToCompute[1], cnt2D.elToCompute[2]);
  if(sum3D)
    _info(0, "   %5s%10d%10d%10d", "3D:", cnt3D.elToCompute[0],
          cnt3D.elToCompute[1], cnt3D.elToCompute[2]);

  return sum2D + sum3D;
}

std::size_t Plug::_guidanceNothingToCompute(Counts counts,
                                            bool check2D, bool check3D) const
{
  _info(1, "=> No element to compute");

  std::size_t sumToShow = 0;
  for (std::size_t x : counts.elToShow) sumToShow += x;

  if (!sumToShow) {
    _warn(-1, "   Nothing to compute, nothing to show.");
    _warn(1, "   Nothing to show neither.");

    if (counts.totalEl) {
      if (_param.compute.onlyVisible && counts.visibleEl == 0) {
        _warn(1, "   Option 'restrictToVisibleElements' is ON but no visible elements found.");
      }
      else if (_param.compute.onlyCurved && counts.curvedEl == 0) {
        _warn(1, "   Option 'restrictToCurvedElements' is ON but no curved elements found.");
      }
      else {
        _error(1, "   Unexpected state: should not be here.");
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
      else if (_dimensionPolicy == 1) {
        if (_m->getNumRegions()) {
          _warn(0, "   Planned to check 2D mesh as option 'dimensionPolicy' "
                   "is ON, but no 2D mesh found.");
          _warn(0, "   3D geometry found, maybe 'dimensionPolicy' "
                   "should be set to 0");
        }
        else {
          if (_m->getNumFaces())
            _warn(1, "   No mesh has been found (in current model)");
          else
            _warn(1, "   No geometry has been found (in current model)");
        }
      }
      else if (_dimensionPolicy == 2 || _dimensionPolicy == 3) {
        if (_m->getNumFaces() + _m->getNumRegions())
          _warn(1, "   No mesh has been found (in current model)");
        else
          _warn(1, "   No geometry has been found (in current model)");
      }
    }
  }
  return sumToShow;
}

void Plug::_devPrintCount(const Counts &counts) const
{
  _info(1, "DEV Elements to compute:");
  for (int i = 0; i < 3; ++i) {
    _info(1, "DEV  - Measure %d: %zu", i + 1, counts.elToCompute[i]);
  }

  _info(1, "DEV Elements to show:");
  for (int i = 0; i < 3; ++i) {
    _info(1, "DEV  - Measure %d: %zu", i + 1, counts.elToShow[i]);
  }

  _info(1, "DEV Total elements: %zu", counts.totalEl);
  _info(1, "DEV Curved elements computed: %zu", counts.elCurvedComputed);
  _info(1, "DEV Curved elements: %zu", counts.curvedEl);
  _info(1, "DEV Existing elements: %zu", counts.existingEl);
  _info(1, "DEV Visible elements: %zu", counts.visibleEl);
}

// ======== struct Counts ======================================================
// =============================================================================

Plug::Counts Plug::Counts::operator+(const Counts &other) const
{
  Counts result;

  for (int i = 0; i < 3; ++i) {
    result.elToCompute[i] = this->elToCompute[i] + other.elToCompute[i];
    result.elToShow[i] = this->elToShow[i] + other.elToShow[i];
  }

  result.totalEl = this->totalEl + other.totalEl;
  result.elCurvedComputed = this->elCurvedComputed + other.elCurvedComputed;
  result.curvedEl = this->curvedEl + other.curvedEl;
  result.existingEl = this->existingEl + other.existingEl;
  result.visibleEl = this->visibleEl + other.visibleEl;

  return result;
}



#endif
