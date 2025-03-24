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

PView *Plug::execute(PView *v)
{
  _info("Executing the plugin AnalyseMeshQuality...", 1);
  _info("Parameter 'printGuidance' is set to 1. This makes the plugin"
        "to be verbose and to provide various explanations",
        1);

  // Initialization
  int checkValidity = static_cast<int>(MeshQuality2Options_Number[0].def);
  int computeDisto = static_cast<int>(MeshQuality2Options_Number[1].def);
  int computeAspect = static_cast<int>(MeshQuality2Options_Number[2].def);
  // int type is because of HAVE_VISUDEV

  // NOTE dimensionPolicy: highest dimension available -> 0, only 2D -> 1,
  //      2D and 3D : seperately -> 2, mixed -> 3
  _dimensionPolicy = static_cast<int>(MeshQuality2Options_Number[3].def);

  // NOTE recomputePolicy:
  //      - delete nothing, compute nothing, output prevsly computed data -> -2
  //      The other options provide an identical output, but differ how
  //      existent data are treated. What asked element means depends on the
  //      two parameters restrict[...]
  //      - delete nothing, compute newly asked elements -> -1
  //      - delete GEntities that are not existent in current GModel,
  //        delete data in GEntities that have detected mesh modifications,
  //        (re)compute data for asked elements and newly asked elements -> 0
  //      - delete GEntities that are not existent in current GModel,
  //        delete data in all GEntities,
  //        compute asked elements -> 1
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
  _verbose = static_cast<bool>(MeshQuality2Options_Number[17].def);
  bool freeData = static_cast<bool>(MeshQuality2Options_Number[18].def);

  //
  if(_dimensionPolicy < 0)
    _dimensionPolicy = 0;
  else if(_dimensionPolicy > 3)
    _dimensionPolicy = 3;
  if(recomputePolicy < -2)
    recomputePolicy = -2;
  else if(recomputePolicy > 1)
    recomputePolicy = 1;
  // FIXME Warnings if verbose

  GModel *m = GModel::current();
  if(_verbose && m != _m && recomputePolicy == 0) {
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
  if(freeData) {
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
  if(!checkValidity && !computeDisto && !computeAspect) {
    _warn("Nothing to do because checkValidity, checkQualityDisto and "
          "checkQualityAspect are all three set to 0");
    return v;
  }

  // Check which dimension to compute and get num of elements
  bool check2D, check3D;
  _decideDimensionToCheck(check2D, check3D);

  ComputeParameters param = {!lazyValidity,       (bool)computeDisto,
                             (bool)computeAspect, recomputePolicy,
                             onlyVisible,         onlyCurved};
  std::size_t nElToCompute[6]{};
  std::size_t nElToShow[6]{};
  if(check2D) _data2D->initialize(_m, param, nElToCompute, nElToShow);
  if(check3D) _data3D->initialize(_m, param, &nElToCompute[3], &nElToShow[3]);

  return v;
}

void Plug::DataSingleDimension::initialize(GModel *m, ComputeParameters param,
                                           std::size_t cntElToCompute[3],
                                           std::size_t cntElToShow[3])
{
  // Update list GEntities (thus _data) if needed
  if(param.recomputePolicy >= -1) {
    std::vector<GEntity *> entities;
    if(_dim == 2)
      entities.insert(entities.end(), m->firstFace(), m->lastFace());
    else if(_dim == 3)
      entities.insert(entities.end(), m->firstRegion(), m->lastRegion());
    _updateGEntities(entities, param.recomputePolicy);
  }

  // Initialize DataEntities and count
  for(auto & it : _data) {
    it.second.initialize(param);
    it.second.count(param, cntElToCompute, cntElToShow);
  }
}

void Plug::DataSingleDimension::_updateGEntities(
  std::vector<GEntity *> &entities, int recomputePolicy)
{
  // Get GEntities present in the current model, add new ones in _data
  std::set<GEntity *, GEntityPtrLessThan> existingInModel;
  for(auto ge: entities) {
    existingInModel.insert(ge);
    if(_data.find(ge) == _data.end()) _data[ge] = DataEntities(ge);
  }

  if(recomputePolicy >= 0) {
    // Remove GEntities from _data that are not existent in the current model
    for(auto it = _data.begin(); it != _data.end(); ++it) {
      if(existingInModel.find(it->first) == existingInModel.end()) {
        // it->second.clear(); // FIXME check that i don't need this
        std::size_t numShownElement[3];
        it->second.getNumShownElement(numShownElement);
        for(int i = 0; i < 3; ++i) {
          if(numShownElement[i] > 0) _changedSincePViewCreation[i] = true;
        }
        it = _data.erase(it);
      }
      else {
        ++it;
      }
    }
  }
}


inline bool isBitSet(unsigned char value, int mask) {
  return value & mask;
}
inline bool isBitUnset(unsigned char value, int mask) {
  return !(value & mask);
}
inline void setBit(unsigned char &value, int mask) {
  value |= mask;
}
inline void unsetBit(unsigned char &value, int mask) {
  value &= ~mask;
}
constexpr int F_JAC = 1 << 0;
constexpr int F_DISTO = 1 << 1;
constexpr int F_ASPECT = 1 << 2;
constexpr int F_EXIST = 1 << 3;
constexpr int F_VISBL = 1 << 4;
constexpr int F_P1COMP = 1 << 5;
constexpr int F_NOTP1 = 1 << 6;
constexpr int F_REQU = 1 << 7;


void Plug::DataEntities::initialize(ComputeParameters param)
{
  // Step 0: Get all elements present in GEntity
  std::size_t num = _ge->getNumMeshElements();
  std::vector<MElement *> elements;
  elements.reserve(num);
  for(auto i = 0; i < num; ++i) {
    elements.push_back(_ge->getMeshElement(i));
  }

  // Step 1: Check if must reset and update flag exist in GEntity
  int policy = param.recomputePolicy;
  if(policy == 0 && num != _mapElemToIndex.size() || policy == 1) {
    reset(num);
    add(elements);
  }
  else if(policy == 0) {
    for(auto i = 0; i < num; ++i) {
      MElement *el = elements[i];
      if(_mapElemToIndex.find(el) == _mapElemToIndex.end()) {
        reset(num);
        add(elements);
        break;
      }
    }
  }
  else {
    for(unsigned char &_flag : _flags) {
      unsetBit(_flag, F_EXIST);
    }
    for(auto el : elements) {
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
    for(auto it = _mapElemToIndex.begin(); it != _mapElemToIndex.end(); ++it) {
      MElement *el = it->first;
      std::size_t index = it->second;

      if((_flags[index] & 1 << 4) && !(_flags[index] & 1 << 6)) {
        bool isCurved = true; // TODO el->isCurved();
        // Assuming MElement has a method isCurved() to check if element is curved
        setBit(_flags[index], F_P1COMP);
        if(isCurved)
          setBit(_flags[index], F_NOTP1);
      }
    }
  }

  // Step 4: Update flag isRequested
  for(unsigned char &_flag : _flags) {
    unsetBit(_flag, F_REQU);
  }
  int requested = 0;
  if(param.onlyVisible)
    requested |= F_VISBL;
  if(param.onlyCurved)
    requested |= F_NOTP1;
  for(auto flag : _flags) {
    if((flag & requested) == requested)
      setBit(flag, F_REQU);
  }
}

void Plug::DataEntities::reset(std::size_t num)
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

void Plug::DataEntities::add(MElement *el)
{
  std::size_t index = _minJ.size();
  _mapElemToIndex[el] = index;
  _minJ.push_back(std::numeric_limits<double>::max());
  _maxJ.push_back(std::numeric_limits<double>::min());
  _minDisto.push_back(std::numeric_limits<double>::max());
  _minAspect.push_back(std::numeric_limits<double>::max());
  unsigned char flag = F_EXIST;
  if (el->getVisibility()) setBit(flag, F_VISBL);
  _flags.push_back(flag);
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

#endif
