// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include "AnalyseMeshQuality2.h"
#include "OS.h"
#include "Context.h"
#include "PView.h"
#include "GModel.h"
#include "MElement.h"
#include "polynomialBasis.h"
#include "bezierBasis.h"
#include "qualityMeasuresJacobian.h"
#include <sstream>
#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#if defined(HAVE_VISUDEV)
#include "BasisFactory.h"
#endif

StringXNumber MeshQuality2Options_Number[] = {
  {GMSH_FULLRC, "checkValidity", nullptr, 0},
  {GMSH_FULLRC, "checkQualityDisto", nullptr, 0},
  {GMSH_FULLRC, "checkQualityAspect", nullptr, 0},
  {GMSH_FULLRC, "dimensionPolicy", nullptr, 0},
  {GMSH_FULLRC, "recomputePolicy", nullptr, 0},
  {GMSH_FULLRC, "restrictToVisibleElements", nullptr, 0},
  {GMSH_FULLRC, "restrictToCurvedElements", nullptr, 0},
  {GMSH_FULLRC, "skipPreventiveValidityCheck", nullptr, 0},
  {GMSH_FULLRC, "$$$whichPercentileToCompute$$$", nullptr, 10},
  {GMSH_FULLRC, "createElementsView", nullptr, 0},
  {GMSH_FULLRC, "createPlotView", nullptr, 0},
  {GMSH_FULLRC, "$$$percentilePlot$$$", nullptr, 10},
  {GMSH_FULLRC, "forceNewPlotView", nullptr, 0},
  {GMSH_FULLRC, "hideElements", nullptr, 0},
  {GMSH_FULLRC, "hideWorst", nullptr, 0},
  {GMSH_FULLRC, "hidingCriterion", nullptr, 0},
  {GMSH_FULLRC, "hidingThreshold", nullptr, .5},
  {GMSH_FULLRC, "printGuidance", nullptr, 1},
  {GMSH_FULLRC, "freeData-NothingElse", nullptr, 0}
#if defined(HAVE_VISUDEV)
  ,
  {GMSH_FULLRC, "createTemporalView", nullptr, 0},
  {GMSH_FULLRC, "createPointwiseView", nullptr, 0},
  {GMSH_FULLRC, "elementIDForPwView", nullptr, 0}
#endif
};

using Plug = GMSH_AnalyseMeshQuality2Plugin;

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQuality2Plugin()
{
  return new GMSH_AnalyseMeshQuality2Plugin();
}
}

int Plug::getNbOptions() const
{
  return sizeof(MeshQuality2Options_Number) / sizeof(StringXNumber);
}

StringXNumber *Plug::getOption(int iopt)
{
  return &MeshQuality2Options_Number[iopt];
}

std::string Plug::getHelp() const
{
  return "Plugin(AnalyseMeshQuality2) analyses the quality of the elements "
         "of a given dimension in the current model. Depending on the input "
         "parameters it computes the minimum of the Jacobian determinant (J), "
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
         "Parameters:\n"
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

PView *Plug::execute(PView *v) {
  _info("Executing the plugin AnalyseMeshQuality...", 1);
  _info("Parameter 'printGuidance' is set to 1. This makes the plugin"
        "to be verbose and to provide various explanations", 1);

  // Initialization
  int checkValidity = static_cast<int>(MeshQuality2Options_Number[0].def);
  int computeDisto = static_cast<int>(MeshQuality2Options_Number[1].def);
  int computeAspect = static_cast<int>(MeshQuality2Options_Number[2].def);
  // int type is because of HAVE_VISUDEV

  // NOTE dimensionPolicy: highest dimension available -> 0, only 2D -> 1,
  //      2D and 3D : seperately -> 2, mixed -> 3
  int _dimensionPolicy = static_cast<int>(MeshQuality2Options_Number[3].def);

  // NOTE recomputePolicy:
  //      - (re)compute nothing, use existent data -> -2
  //      - do not recompute, just add new elements -> -1,
  //      - recompute if mesh modification detected -> 0,
  //      - always recompute -> 1
  int recomputePolicy = static_cast<int>(MeshQuality2Options_Number[4].def);
  bool onlyVisible = static_cast<bool>(MeshQuality2Options_Number[5].def);

  // FIXME 'restrictToCurvedElements' would be great, but how to implement?
  bool onlyCurved = static_cast<bool>(MeshQuality2Options_Number[6].def);
  bool lazyValidity = static_cast<bool>(MeshQuality2Options_Number[7].def);
  double percentileStat = MeshQuality2Options_Number[8].def;
  bool createView3D = static_cast<bool>(MeshQuality2Options_Number[9].def);
  bool createView2D = static_cast<bool>(MeshQuality2Options_Number[10].def);
  double percentilePlot = MeshQuality2Options_Number[11].def;
  bool newPlot = static_cast<bool>(MeshQuality2Options_Number[12].def);
  bool hideElements = static_cast<bool>(MeshQuality2Options_Number[13].def);
  bool hideWorst = static_cast<bool>(MeshQuality2Options_Number[14].def);

  // NOTE hideCriterion: hide in function of quality -> 0, %elm -> 1, #elm -> 2
  int hideCriterion = static_cast<int>(MeshQuality2Options_Number[15].def);
  double hideThreshold = MeshQuality2Options_Number[16].def;
  bool _verbose = static_cast<bool>(MeshQuality2Options_Number[17].def);
  bool freeData = static_cast<bool>(MeshQuality2Options_Number[18].def);

  //
  if(_dimensionPolicy < 0) _dimensionPolicy = 0;
  else if(_dimensionPolicy > 3) _dimensionPolicy = 3;
  if(recomputePolicy < -2) recomputePolicy = -2;
  else if(recomputePolicy > 1) recomputePolicy = 1;
  // FIXME Warnings if verbose

  GModel *m = GModel::current();
  if (_verbose && m != _m && recomputePolicy == 0) {
    _info("Detected a new Model, previous data will cleared", 1);
  }
  _m = m;

#if defined(HAVE_VISUDEV)
  // TODO come back later
  _pwJac = checkValidity / 2;
  _pwIGE = computeDisto / 2;
  _pwICN = computeAspect / 2;

  // NOTE About createTimeView:
  //  check if PView::_data::NbTimeStep if _data of type PViewDataList
  //  check if PView::_options::vectorType == PViewOptions::Displacement (5),
  //  or just consider that NbTimeStep is sufficient

  bool createTimeView = static_cast<bool>(MeshQuality2Options_Number[19].def);
  _createPwView = static_cast<bool>(MeshQuality2Options_Number[20].def);
  _elemNumForPwView = static_cast<int>(MeshQuality2Options_Number[21].def);
  _viewOrder = 0;
  _dataPViewJac.clear();
  _dataPViewIGE.clear();
  _dataPViewICN.clear();
#endif

  // Handle cases where no computation is requested
  if (freeData) {
    _info("Freeing data...", -1);
    _info("Freeing data... (because 'freeData-NothingElse' is set to 1)", 1);
    // FIXME: create method clear in dataSingleDimension
    _data2D->clear();
    _data3D->clear();
    MeshQuality2Options_Number[18].def = 0;
    _info("Done. 'freeData-NothingElse' has been set to 0");
    _info("Nothing else to do, rerun the plugin to compute something", 1);
    return v;
  }
  if (!checkValidity && !computeDisto && !computeAspect) {
    _warn("Nothing to do because checkValidity, checkQualityDisto and "
          "checkQualityAspect are all three set to 0");
    return v;
  }

  // Check which dimension to compute and get num of elements
  bool check2D, check3D;
  _decideDimensionToCheck(check2D, check3D);
  int numElementsToCompute[6]{};
  if (check2D) _data2D->initialize(_m, numElementsToCompute);
  if (check3D) _data3D->initialize(_m, &numElementsToCompute[3]);

  return v;
}

using dataSingDim = GMSH_AnalyseMeshQuality2Plugin::dataSingleDimension;

void dataSingDim::initialize(GModel *m, int countElementToCheck[3])
{
  if (_dim == 2) {
    std::set<GEntity*, GEntityPtrLessThan> entitySet(m->firstFace(), m->lastFace());
    _initialize(entitySet.begin(), entitySet.end(), countElementToCheck);
  }
  else if (_dim == 3) {
    std::set<GEntity*, GEntityPtrLessThan> entitySet(m->firstRegion(), m->lastRegion());
    _initialize(entitySet.begin(), entitySet.end(), countElementToCheck);
  }


}

void dataSingDim::_initialize(entiter first, entiter last, int countElementToCheck[3])
{
  std::set<GEntity *> existingInModel;

  // Add new GEntities to _data and update those already present
  for (auto it = first; it != last; ++it) {
    GEntity *ge = *it;
    existingInModel.insert(ge);
    if (_data.find(ge) == _data.end()) {
      _data[ge] = dataEntities(ge);
      int numElements = ge->getNumMeshElements();
      countElementToCheck[0] += numElements;
      countElementToCheck[1] += numElements;
      countElementToCheck[2] += numElements;
    }
    else {
      // f is already in _data, call countNewElement
      _data[ge].countNewElement(ge);
    }
  }

  // Remove GEntities from _data that are no more existent in the model
  for (auto it = _data.begin(); it != _data.end();) {
    if (existingInModel.find(it->first) == existingInModel.end()) {
      // it->second.clear(); // FIXME check that i don't need this
      // FIXME should check if DataEntities had element
      it = _data.erase(it);
    }
    else {
      ++it;
    }
  }
  for (int i =0; i < 3; ++i) {
    if(countElementToCompute[i]) _dataChangedSincePViewCreation[i] = true;
  }
}

void Plug::_decideDimensionToCheck(bool &check2D,
  bool &check3D) const
{
  int num3DElem = 0;

  // Iterate through regions to count 3D mesh elements
  for (auto it = _m->firstRegion(); it != _m->lastRegion(); ++it) {
    num3DElem += (*it)->getNumMeshElements();
  }

  // Apply policy logic
  check2D = true;
  check3D = true;
  if (_dimensionPolicy == 0 && num3DElem > 0) check2D = false;
  else if (_dimensionPolicy < 2) check3D = false;
}

#endif
