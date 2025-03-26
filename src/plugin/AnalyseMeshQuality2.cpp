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
#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#if defined(HAVE_VISUDEV)
#include "BasisFactory.h"
#endif

StringXNumber MeshQuality2Options_Number[] = {
  {GMSH_FULLRC, "checkValidity", nullptr, 0},
  {GMSH_FULLRC, "checkQualityDisto", nullptr, 1},
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

  _info(0, "----------------------------------------");
  _info(0, "Executing the plugin AnalyseMeshQuality...");
  _info(1, "Parameter 'printGuidance' is ON. This makes the plugin "
        "to be verbose and to provide various explanations");

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
  if(recomputePolicy == 0 && _m && _m != m) {
    _info(1, "Detected a new Model, previous data will cleared");
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
    _info(-1, "Freeing data...");
    _info(1, "Freeing data... (because parameter 'freeData-NothingElse' is ON)");
    // FIXME: create method clear in dataSingleDimension
    _data2D->clear();
    _data3D->clear();
    MeshQuality2Options_Number[18].def = 0;
    _info(0, "Done. Parameter 'freeData-NothingElse' has been set to OFF");
    _info(1, "Nothing else to do, rerun the plugin to compute something");
    return v;
  }
  if(!checkValidity && !computeDisto && !computeAspect) {
    _warn(0, "Nothing to do because 'checkValidity', 'checkQualityDisto' and "
          "'checkQualityAspect' are all three OFF");
    return v;
  }

  // Check which dimension to compute/show, initialize data and counts elements
  bool check2D, check3D;
  _decideDimensionToCheck(check2D, check3D);

  bool computeValidity = checkValidity ||
                         (!lazyValidity && (computeDisto || computeAspect));
  ComputeParameters param = {computeValidity, static_cast<bool>(computeDisto),
                             static_cast<bool>(computeAspect), recomputePolicy,
                             onlyVisible, onlyCurved};
  Counts counts2D, counts3D;
  if(check2D) _data2D->initialize(_m, param, counts2D);
  if(check3D) _data3D->initialize(_m, param, counts3D);

  // TMP Dev
  _devPrintCount(counts2D);
  _devPrintCount(counts3D);

  // Check that there is something to do
  std::size_t totalToCompute = _printElementToCompute(counts2D, counts3D);
  if(!totalToCompute) {
    std::size_t totalToShow = _guidanceNothingToCompute(param,
      counts2D + counts3D, check2D, check3D);
    if(!totalToShow) return v;
  }

  // TODO compute measures
  // If validity not asked : tell that compute it any way because it can speedup
  // say that only if verb 1


  // TODO compute show


  // TODO warning if no element to check (the case T8, maybe another gmodel?)

  return v;
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

void Plug::DataSingleDimension::initialize(GModel *m, ComputeParameters param,
                                           Counts &counts)
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
  for(auto &it : _data) {
    it.second.initialize(param);
    it.second.count(param, counts);
  }
}

void Plug::DataSingleDimension::_updateGEntities(
  std::vector<GEntity *> &entities, int recomputePolicy)
{
  // Get GEntities present in the current model, add new ones in _data
  std::set<GEntity *, GEntityPtrLessThan> existingInModel;
  for(const auto &ge: entities) {
    existingInModel.insert(ge);
    if(_data.find(ge) == _data.end()) _data.emplace(ge, DataEntities(ge));
  }

  if(recomputePolicy >= 0) {
    // Remove GEntities from _data that are not existent in the current model
    for(auto it = _data.begin(); it != _data.end();) {
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

constexpr int F_NOTJAC = 1 << 0;
constexpr int F_NOTDISTO = 1 << 1;
constexpr int F_NOTASPECT = 1 << 2;
constexpr int F_EXIST = 1 << 3;
constexpr int F_VISBL = 1 << 4;
constexpr int F_CURVNOTCOMP = 1 << 5;
constexpr int F_CURVED = 1 << 6;
constexpr int F_REQU = 1 << 7;


void Plug::DataEntities::initialize(ComputeParameters param)
{
  if(param.recomputePolicy == -2) return;

  // Step 0: Get all elements present in GEntity
  std::size_t num = _ge->getNumMeshElements();
  std::vector<MElement *> elements;
  elements.reserve(num);
  for(auto i = 0; i < num; ++i) {
    elements.push_back(_ge->getMeshElement(i));
  }

  // Step 1: Check if must reset data, and update flag "exist in GEntity"
  int policy = param.recomputePolicy;
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

void Plug::DataEntities::count(ComputeParameters param, Counts &counts)
{
  // Count num to compute and num to show
  for(int i = 0; i < 3; ++i) {
    _numToCompute[i] = 0;
    _numToShow[i] = 0;
  }

  if (param.computeValidity)
    _count(F_REQU | F_NOTJAC, _numToCompute[0], _numToShow[0]);
  if (param.computeDisto)
    _count(F_REQU | F_NOTDISTO, _numToCompute[1], _numToShow[1]);
  if (param.computeAspect)
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

void Plug::DataEntities::_countCurved(std::size_t &known, std::size_t &curved)
{
  for(const auto &flag : _flags) {
    if(isBitUnset(flag, F_CURVNOTCOMP)) {
      ++known;
      if(isBitSet(flag, F_CURVED)) ++curved;
    }
  }
}

void Plug::DataEntities::_count(unsigned char mask, std::size_t &elToCompute,
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
  unsigned char flag = F_NOTJAC | F_NOTDISTO | F_NOTASPECT | F_EXIST
                       | F_CURVNOTCOMP;
  if (el->getVisibility()) setBit(flag, F_VISBL);
  _flags.push_back(flag);
}

void Plug::_printMessage(void (*func)(const char *, ...), const char *format,
                         va_list args) const
{
  char str[5000];
  vsnprintf(str, sizeof(str), format, args);
  func("%s", str);
}

void Plug::_info(int verb, const char *format, ...) const
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Info, format, args);
  va_end(args);
}

void Plug::_warn(int verb, const char *format, ...) const
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Warning, format, args);
  va_end(args);
}

void Plug::_error(int verb, const char *format, ...) const
{
  if(!_okToPrint(verb)) return;
  va_list args;
  va_start(args, format);
  _printMessage(Msg::Error, format, args);
  va_end(args);
}

std::size_t Plug::_printElementToCompute(const Counts &cnt2D,
                                         const Counts &cnt3D) const
{
  std::size_t sum2D = 0, sum3D = 0;
  for (std::size_t x : cnt2D.elToCompute) sum2D += x;
  for (std::size_t x : cnt3D.elToCompute) sum3D += x;

  if(sum2D + sum3D == 0) return 0;

  // Print the table header using `_info`
  _info(0, "Number of quantities to compute:");
  _info(0, "%-10s%-10s%-10s%-10s", "", "Validity", "Disto", "Aspect");
  if(sum2D)
    _info(0, "%-10s%-10d%-10d%-10d", "2D:", cnt2D.elToCompute[0],
          cnt2D.elToCompute[1], cnt2D.elToCompute[2]);
  if(sum3D)
    _info(0, "%-10s%-10d%-10d%-10d", "3D:", cnt3D.elToCompute[0],
          cnt3D.elToCompute[1], cnt3D.elToCompute[2]);

  return sum2D + sum3D;
}

std::size_t Plug::_guidanceNothingToCompute(ComputeParameters param,
                                            Counts counts,
                                            bool check2D, bool check3D) const
{
  _info(1, "No element to compute");

  std::size_t sumToShow = 0;
  for (std::size_t x : counts.elToCompute) sumToShow += x;

  if (!sumToShow) {
    _warn(-1, "Nothing to compute, nothing to show.");
    _warn(1, "Nothing to show neither.");

    if (counts.totalEl) {
      if (param.onlyVisible && counts.visibleEl == 0) {
        _warn(1, "Parameter 'restrictToVisibleElements' is ON but no visible elements found.");
      }
      else if (param.onlyCurved && counts.curvedEl == 0) {
        _warn(1, "Parameter 'restrictToCurvedElements' is ON but no curved elements found.");
      }
      else {
        _error(1, "Unexpected state: should not be here.");
      }
    }
    else { // Case where no elements found
      if (_dimensionPolicy == 0) {
        if (check2D) {
          if (_m->getNumFaces())
            _warn(1, "No mesh has been found (in current model)");
          else
            _warn(1, "No geometry has been found (in current model)");
        }
        else if(check3D) {
          _error(1, "Unexpected state: should not be here with check3D==true");
          // ...because if _dimensionPolicy == 0, then check3D==true only if there are elements
          // _info(1, "Considered 3D as dimensionPolicy is 0 but no 3D mesh in current model.");
          // _info(1, "Maybe set dimensionPolicy to 1 to force 2D.");
        }
        else {
          _error(1, "Unexpected state: should not be here with check3D==false");
          // ...because if _dimensionPolicy == 0, then check3D==true only if there are elements
          // _info(1, "Considered 3D as dimensionPolicy is 0 but no 3D mesh in current model.");
          // _info(1, "Maybe set dimensionPolicy to 1 to force 2D.");
        }
      }
      else if (_dimensionPolicy == 1) {
        if (_m->getNumRegions()) {
          _warn(0, "Planned to check 2D mesh as parameter 'dimensionPolicy' "
                   "is ON, but no 2D mesh found.");
          _warn(0, " 3D geometry found, maybe 'dimensionPolicy' "
                   "should be set to 0");
        }
        else {
          if (_m->getNumFaces())
            _warn(1, "No mesh has been found (in current model)");
          else
            _warn(1, "No geometry has been found (in current model)");
        }
      }
      else if (_dimensionPolicy == 2 || _dimensionPolicy == 3) {
        if (_m->getNumFaces() + _m->getNumRegions())
          _warn(1, "No mesh has been found (in current model)");
        else
          _warn(1, "No geometry has been found (in current model)");
      }
    }
  }
  return sumToShow;
}

Plug::Counts Plug::Counts::operator+(const Counts &other) const {
  Counts result;

  // Summing up elToCompute arrays element-wise
  for (int i = 0; i < 3; ++i) {
    result.elToCompute[i] = this->elToCompute[i] + other.elToCompute[i];
    result.elToShow[i] = this->elToShow[i] + other.elToShow[i];
  }

  // Summing up individual scalar fields
  result.totalEl = this->totalEl + other.totalEl;
  result.elCurvedComputed = this->elCurvedComputed + other.elCurvedComputed;
  result.curvedEl = this->curvedEl + other.curvedEl;
  result.existingEl = this->existingEl + other.existingEl;
  result.visibleEl = this->visibleEl + other.visibleEl;

  return result; // Return the newly created Counts as the result
}



#endif
