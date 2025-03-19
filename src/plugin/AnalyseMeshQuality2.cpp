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

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQuality2Plugin()
{
  return new GMSH_AnalyseMeshQuality2Plugin();
}
}

int GMSH_AnalyseMeshQuality2Plugin::getNbOptions() const
{
  return sizeof(MeshQuality2Options_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnalyseMeshQuality2Plugin::getOption(int iopt)
{
  return &MeshQuality2Options_Number[iopt];
}

std::string GMSH_AnalyseMeshQuality2Plugin::getHelp() const
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

PView *GMSH_AnalyseMeshQuality2Plugin::execute(PView *v)
{
  // Initialization

  _m = GModel::current();
  int checkValidity = static_cast<int>(MeshQuality2Options_Number[0].def);
  int computeDisto = static_cast<int>(MeshQuality2Options_Number[1].def);
  int computeAspect = static_cast<int>(MeshQuality2Options_Number[2].def);
  // int type is because of HAVE_VISUDEV

  // NOTE dimensionPolicy: highest dimension available -> 0, only 2D -> 1,
  //      2D and 3D : seperately -> 2, mixed -> 3
  int dimensionPolicy = static_cast<int>(MeshQuality2Options_Number[3].def);

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
  bool verbose = static_cast<bool>(MeshQuality2Options_Number[17].def);
  bool freeData = static_cast<bool>(MeshQuality2Options_Number[18].def);

  //
  if(dimensionPolicy < 0) dimensionPolicy = 0;
  else if(dimensionPolicy > 3) dimensionPolicy = 3;
  if(recomputePolicy < -2) recomputePolicy = -2;
  else if(recomputePolicy > 1) dimensionPolicy = 1;
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

  bool createTimeView = static_cast<bool>(MeshQuality2Options_Number[19].def);
  _createPwView = static_cast<bool>(MeshQuality2Options_Number[20].def);
  _elemNumForPwView = static_cast<int>(MeshQuality2Options_Number[21].def);
  _viewOrder = 0;
  _dataPViewJac.clear();
  _dataPViewIGE.clear();
  _dataPViewICN.clear();
#endif
}

#endif
