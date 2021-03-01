// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include "AnalyseMeshQuality.h"
#include "qualityMeasuresJacobian.h"
#include "OS.h"
#include "Context.h"
#include "PView.h"
#include "GModel.h"
#include "MElement.h"
#include "bezierBasis.h"
#include <sstream>
#include <fstream>
#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#if defined(HAVE_VISUDEV)
#include "BasisFactory.h"
#endif

StringXNumber CurvedMeshOptions_Number[] = {
  {GMSH_FULLRC, "JacobianDeterminant", nullptr, 0},
  {GMSH_FULLRC, "IGEMeasure", nullptr, 0},
  {GMSH_FULLRC, "ICNMeasure", nullptr, 0},
  {GMSH_FULLRC, "HidingThreshold", nullptr, 99},
  {GMSH_FULLRC, "ThresholdGreater", nullptr, 1},
  {GMSH_FULLRC, "CreateView", nullptr, 0},
  {GMSH_FULLRC, "Recompute", nullptr, 0},
  {GMSH_FULLRC, "DimensionOfElements", nullptr, -1}
#if defined(HAVE_VISUDEV)
  ,
  {GMSH_FULLRC, "Element to draw quality", nullptr, 0}
#endif
};

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQualityPlugin()
{
  return new GMSH_AnalyseMeshQualityPlugin();
}
}

int GMSH_AnalyseMeshQualityPlugin::getNbOptions() const
{
  return sizeof(CurvedMeshOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnalyseMeshQualityPlugin::getOption(int iopt)
{
  return &CurvedMeshOptions_Number[iopt];
}

std::string GMSH_AnalyseMeshQualityPlugin::getHelp() const
{
  return "Plugin(AnalyseMeshQuality) analyses the quality of the elements "
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

PView *GMSH_AnalyseMeshQualityPlugin::execute(PView *v)
{
  _m = GModel::current();
  int computeJac = static_cast<int>(CurvedMeshOptions_Number[0].def);
  int computeIGE = static_cast<int>(CurvedMeshOptions_Number[1].def);
  int computeICN = static_cast<int>(CurvedMeshOptions_Number[2].def);
  double threshold = CurvedMeshOptions_Number[3].def;
  bool thresholdGreater = static_cast<bool>(CurvedMeshOptions_Number[4].def);
  bool createView = static_cast<bool>(CurvedMeshOptions_Number[5].def);
  bool recompute = static_cast<bool>(CurvedMeshOptions_Number[6].def);
  int askedDim = static_cast<int>(CurvedMeshOptions_Number[7].def);

#if defined(HAVE_VISUDEV)
  _pwJac = computeJac / 2;
  _pwIGE = computeIGE / 2;
  _pwICN = computeICN / 2;

  _numElementToScan = static_cast<int>(CurvedMeshOptions_Number[8].def);
  _viewOrder = 0;
  _dataPViewJac.clear();
  _dataPViewIGE.clear();
  _dataPViewICN.clear();
#endif

  if(askedDim < 0 || askedDim > 4) askedDim = _m->getDim();

  if(recompute) _clear(askedDim);

  // Compute what have to
  bool printStatJ = false;
  bool printStatS = false;
  bool printStatI = false;
  for(int dim = 1; dim <= 3 && dim <= _m->getDim(); ++dim) {
    if((askedDim == 4 && dim > 1) || dim == askedDim) {
      if(!_computedJac[dim - 1]) {
        double time = Cpu(), w = TimeOfDay();
        Msg::StatusBar(true, "Computing Jacobian for %dD elements...", dim);
        _computeMinMaxJandValidity(dim);
        Msg::StatusBar(true,
                       "Done computing Jacobian for %dD elements (Wall %gs, "
                       "CPU %gs)",
                       dim, TimeOfDay() - w, Cpu() - time);
        printStatJ = true;
      }
      if(computeIGE && !_computedIGE[dim - 1]) {
        double time = Cpu(), w = TimeOfDay();
        Msg::StatusBar(true, "Computing IGE for %dD elements...", dim);
        _computeMinIGE(dim);
        Msg::StatusBar(true,
                       "Done computing IGE for %dD elements (Wall %gs, "
                       "CPU %gs)",
                       dim, TimeOfDay() - w, Cpu() - time);
        printStatS = true;
      }
      if(computeICN && !_computedICN[dim - 1]) {
        double time = Cpu(), w = TimeOfDay();
        Msg::StatusBar(true, "Computing ICN for %dD elements...", dim);
        _computeMinICN(dim);
        Msg::StatusBar(true,
                       "Done computing ICN for %dD elements (Wall %gs, "
                       "CPU %gs)",
                       dim, TimeOfDay() - w, Cpu() - time);
        printStatI = true;
      }
    }
  }
  if(printStatJ) _printStatJacobian();
  if(printStatS) _printStatIGE();
  if(printStatI) _printStatICN();

#if defined(HAVE_VISUDEV)
  _createPViewPointwise();
#endif

  // Create PView
  if(createView) {
    for(int dim = 1; dim <= 3; ++dim) {
      if((askedDim == 4 && dim > 1) || dim == askedDim) {
        if(!_pviewJac[dim - 1] && computeJac) {
          _pviewJac[dim - 1] = true;
          std::map<int, std::vector<double> > dataPV;
          for(std::size_t i = 0; i < _data.size(); ++i) {
            MElement *const el = _data[i].element();
            if(el->getDim() == dim) {
              double q = 0;
              if(_data[i].maxJ() > 0)
                q = _data[i].minJ() / _data[i].maxJ();
              else if(_data[i].maxJ() < 0)
                q = _data[i].maxJ() / _data[i].minJ();
              dataPV[el->getNum()].push_back(q);
            }
          }
          if(dataPV.size()) {
            std::stringstream name;
            name << "minJ/maxJ " << dim << "D";
            new PView(name.str().c_str(), "ElementData", _m, dataPV);
          }
        }
        if(!_pviewIGE[dim - 1] && computeIGE) {
          _pviewIGE[dim - 1] = true;
          std::map<int, std::vector<double> > dataPV;
          for(std::size_t i = 0; i < _data.size(); ++i) {
            MElement *const el = _data[i].element();
            if(el->getDim() == dim)
              dataPV[el->getNum()].push_back(_data[i].minS());
          }
          if(dataPV.size()) {
            std::stringstream name;
            name << "IGE " << dim << "D";
            new PView(name.str().c_str(), "ElementData", _m, dataPV);
          }
        }
        if(!_pviewICN[dim - 1] && computeICN) {
          _pviewICN[dim - 1] = true;
          std::map<int, std::vector<double> > dataPV;
          for(std::size_t i = 0; i < _data.size(); ++i) {
            MElement *const el = _data[i].element();
            if(el->getDim() == dim)
              dataPV[el->getNum()].push_back(_data[i].minI());
          }
          if(dataPV.size()) {
            std::stringstream name;
            name << "ICN " << dim << "D";
            new PView(name.str().c_str(), "ElementData", _m, dataPV);
          }
        }
      }
    }
  }

  // hide elements
  int whichMeasure = computeICN ? 2 : computeIGE ? 1 : computeJac ? 0 : -1;
  if(threshold < 99 && whichMeasure >= 0) {
    _hideWithThreshold(askedDim, whichMeasure, threshold, thresholdGreater);
    CTX::instance()->mesh.changed = ENT_ALL;
#if defined(HAVE_OPENGL)
    drawContext::global()->draw();
#endif
  }

  return nullptr;
}

void GMSH_AnalyseMeshQualityPlugin::_computeMinMaxJandValidity(int dim)
{
  if(_computedJac[dim - 1]) return;

  std::set<GEntity *, GEntityPtrFullLessThan> entities;
  switch(dim) {
  case 3:
    for(auto it = _m->firstRegion(); it != _m->lastRegion(); it++)
      entities.insert(*it);
    break;
  case 2:
    for(auto it = _m->firstFace(); it != _m->lastFace(); it++)
      entities.insert(*it);
    break;
  case 1:
    for(auto it = _m->firstEdge(); it != _m->lastEdge(); it++)
      entities.insert(*it);
    break;
  default: return;
  }

  int cntInverted = 0;
  for(auto it = entities.begin(); it != entities.end(); ++it) {
    GEntity *entity = *it;
    unsigned num = entity->getNumMeshElements();
    fullMatrix<double> *normals = nullptr;
    switch(dim) {
    case 3:
      Msg::StatusBar(true, "Volume %d: checking the Jacobian of %d elements",
                     entity->tag(), num);
      break;
    case 2:
      Msg::StatusBar(true, "Surface %d: checking the Jacobian of %d elements",
                     entity->tag(), num);
      // check the classical case of 2D planar meshes in the z=0 plane to issue
      // a warning of the mesh is oriented along -z
      if(entity->geomType() == GEntity::DiscreteSurface) {
        SBoundingBox3d bb = entity->bounds();
        if(!bb.empty() && bb.max().z() - bb.min().z() == .0) {
          normals = new fullMatrix<double>(1, 3);
          normals->set(0, 0, 0);
          normals->set(0, 1, 0);
          normals->set(0, 2, 1);
        }
      }
      break;
    case 1:
      Msg::StatusBar(true, "Line %d: checking the Jacobian of %d elements",
                     entity->tag(), num);
      break;
    default: break;
    }

    MsgProgressStatus progress(num);

    _data.reserve(_data.size() + num);
    for(unsigned i = 0; i < num; ++i) {
      MElement *el = entity->getMeshElement(i);
      double min, max;
      jacobianBasedQuality::minMaxJacobianDeterminant(el, min, max, normals);
      _data.push_back(data_elementMinMax(el, min, max));
      if(min < 0 && max < 0) ++cntInverted;
      progress.next();

#if defined(HAVE_VISUDEV)
      _computePointwiseQuantities(el, normals);
#endif
    }
    if(normals) delete normals;
  }
  if(cntInverted) {
    Msg::Warning("%d element%s completely inverted",
                 (cntInverted > 1) ? "s are" : " is");
  }
  _computedJac[dim - 1] = true;
  bezierCoeff::releasePools();
}

void GMSH_AnalyseMeshQualityPlugin::_computeMinIGE(int dim)
{
  if(_computedIGE[dim - 1]) return;

  MsgProgressStatus progress(_data.size());

  for(std::size_t i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    if(el->getDim() != dim) continue;
    if(_data[i].minJ() <= 0 && _data[i].maxJ() >= 0) { _data[i].setMinS(0); }
    else {
      _data[i].setMinS(jacobianBasedQuality::minIGEMeasure(el, true));
    }
    progress.next();
  }

  _computedIGE[dim - 1] = true;
}

void GMSH_AnalyseMeshQualityPlugin::_computeMinICN(int dim)
{
  if(_computedICN[dim - 1]) return;

  MsgProgressStatus progress(_data.size());

  for(std::size_t i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    if(el->getDim() != dim) continue;
    if(_data[i].minJ() <= 0 && _data[i].maxJ() >= 0) { _data[i].setMinI(0); }
    else {
      _data[i].setMinI(jacobianBasedQuality::minICNMeasure(el, true));
    }
    progress.next();
  }

  _computedICN[dim - 1] = true;
}

int GMSH_AnalyseMeshQualityPlugin::_hideWithThreshold(int askedDim,
                                                      int whichMeasure,
                                                      double threshold,
                                                      bool greater)
{
  int nHidden = 0;
  for(std::size_t i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    const int dim = el->getDim();
    if((askedDim == 4 && dim > 1) || dim == askedDim) {
      double q = 1.;
      switch(whichMeasure) {
      case 2: q = _data[i].minI(); break;
      case 1: q = _data[i].minS(); break;
      case 0:
        if(_data[i].maxJ() > 0)
          q = _data[i].minJ() / _data[i].maxJ();
        else if(_data[i].maxJ() < 0)
          q = _data[i].maxJ() / _data[i].minJ();
      }
      if((greater && q > threshold) || (!greater && q < threshold)) {
        el->setVisibility(0);
        ++nHidden;
      }
      else {
        el->setVisibility(1);
      }
    }
  }
  return nHidden;
}

void GMSH_AnalyseMeshQualityPlugin::_printStatJacobian()
{
  if(_data.empty()) {
    Msg::Info("No stat to print");
    return;
  }
  double infminJ, supminJ, avgminJ;
  double infratJ, supratJ, avgratJ;
  double avgratJc;
  int count = 0, countc = 0;

  infminJ = infratJ = 1e10;
  supminJ = supratJ = -1e10;
  avgminJ = avgratJ = avgratJc = 0;

  for(std::size_t i = 0; i < _data.size(); ++i) {
    infminJ = std::min(infminJ, _data[i].minJ());
    supminJ = std::max(supminJ, _data[i].minJ());
    avgminJ += _data[i].minJ();

    double q = 0;
    if(_data[i].maxJ() > 0)
      q = _data[i].minJ() / _data[i].maxJ();
    else if(_data[i].maxJ() < 0)
      q = _data[i].maxJ() / _data[i].minJ();
    infratJ = std::min(infratJ, q);
    supratJ = std::max(supratJ, q);
    avgratJ += q;
    if(q < 1 - 1e-5) {
      avgratJc += _data[i].minJ() / _data[i].maxJ();
      ++countc;
    }

    ++count;
  }
  avgminJ /= count;
  avgratJ /= count;
  avgratJc /= countc;

  Msg::Info("minJ      = %8.3g, %8.3g, %8.3g (min, avg, max)", infminJ, avgminJ,
            supminJ);
  if(countc && countc < count)
    Msg::Info("minJ/maxJ =           %8.3g           (avg on the %d "
              "non-constant elements)",
              avgratJc, countc);
  Msg::Info("minJ/maxJ = %8.3g, %8.3g, %8.3g (worst, avg, best)", infratJ,
            avgratJ, supratJ);
}

void GMSH_AnalyseMeshQualityPlugin::_printStatIGE()
{
  if(_data.empty()) {
    Msg::Info("No stat to print");
    return;
  }
  double infminS, supminS, avgminS;
  infminS = supminS = avgminS = _data[0].minS();

  for(std::size_t i = 1; i < _data.size(); ++i) {
    infminS = std::min(infminS, _data[i].minS());
    supminS = std::max(supminS, _data[i].minS());
    avgminS += _data[i].minS();
  }
  avgminS /= _data.size();

  Msg::Info("IGE       = %8.3g, %8.3g, %8.3g (worst, avg, best)", infminS,
            avgminS, supminS);
}

void GMSH_AnalyseMeshQualityPlugin::_printStatICN()
{
  if(_data.empty()) {
    Msg::Info("No stat to print");
    return;
  }
  double infminI, supminI, avgminI;
  infminI = supminI = avgminI = _data[0].minI();

  for(std::size_t i = 1; i < _data.size(); ++i) {
    infminI = std::min(infminI, _data[i].minI());
    supminI = std::max(supminI, _data[i].minI());
    avgminI += _data[i].minI();
  }
  avgminI /= _data.size();

  Msg::Info("ICN       = %8.3g, %8.3g, %8.3g (worst, avg, best)", infminI,
            avgminI, supminI);
}

void GMSH_AnalyseMeshQualityPlugin::_clear(int askedDim)
{
  _data.clear();
  if(askedDim < 4) {
    _computedJac[askedDim - 1] = false;
    _computedIGE[askedDim - 1] = false;
    _computedICN[askedDim - 1] = false;
    _pviewJac[askedDim - 1] = false;
    _pviewIGE[askedDim - 1] = false;
    _pviewICN[askedDim - 1] = false;
  }
  else {
    _computedJac[1] = _computedJac[2] = false;
    _computedIGE[1] = _computedIGE[2] = false;
    _computedICN[1] = _computedICN[2] = false;
    _pviewJac[1] = _pviewJac[2] = false;
    _pviewIGE[1] = _pviewIGE[2] = false;
    _pviewICN[1] = _pviewICN[2] = false;
  }
}

#if defined(HAVE_VISUDEV)

void GMSH_AnalyseMeshQualityPlugin::_computePointwiseQuantities(
  MElement *el, const fullMatrix<double> *normals)
{
  if(_numElementToScan != -1 && el->getNum() != _numElementToScan) return;

  if(!_type2tag[el->getType()])
    _type2tag[el->getType()] = el->getTypeForMSH();
  else
    // Skip if element tag is different from previous elements of same type
    if(_type2tag[el->getType()] != el->getTypeForMSH())
    return;

  static fullVector<double> tmpVector;
  int num = el->getNum();

  if(!_viewOrder) {
    //    _viewOrder = std::min(10, 2 * el->getPolynomialOrder());
    _viewOrder = 9;
  }

  if(_pwJac) {
    jacobianBasedQuality::sampleJacobianDeterminant(el, _viewOrder, tmpVector,
                                                    normals);
    std::vector<double> &vec = _dataPViewJac[num];
    for(int j = 0; j < tmpVector.size(); ++j) vec.push_back(tmpVector(j));
  }

  if(_pwIGE) {
    jacobianBasedQuality::sampleIGEMeasure(el, _viewOrder, tmpVector);
    std::vector<double> &vec = _dataPViewIGE[num];
    for(int j = 0; j < tmpVector.size(); ++j) vec.push_back(tmpVector(j));
  }

  if(_pwICN) {
    //    jacobianBasedQuality::sampleICNMeasure(el, _viewOrder, tmpVector);
    //    std::vector<double> &vec = _dataPViewICN[num];
    //    for (int j = 0; j < tmpVector.size(); ++j)
    //      vec.push_back(tmpVector(j));
  }
}

void GMSH_AnalyseMeshQualityPlugin::_setInterpolationMatrices(PView *view)
{
  PViewData *viewData = view->getData();
  for(int type = 0; type < 20; ++type) {
    if(!_type2tag[type]) continue;
    viewData->deleteInterpolationMatrices(type);
    const nodalBasis *fsE = BasisFactory::getNodalBasis(_type2tag[type]);
    const polynomialBasis *pfsE = dynamic_cast<const polynomialBasis *>(fsE);
    const int hoTag = ElementType::getType(type, _viewOrder);
    const nodalBasis *fsV = BasisFactory::getNodalBasis(hoTag);
    const polynomialBasis *pfsV = dynamic_cast<const polynomialBasis *>(fsV);
    viewData->setInterpolationMatrices(type, pfsV->coefficients,
                                       pfsV->monomials, pfsE->coefficients,
                                       pfsE->monomials);
  }
}

void GMSH_AnalyseMeshQualityPlugin::_createPViewPointwise()
{
  if(_pwJac) {
    _setInterpolationMatrices(new PView("Pointwise Jacobian", "ElementNodeData",
                                        _m, _dataPViewJac, 0, 1));
  }

  if(_pwIGE) {
    _setInterpolationMatrices(
      new PView("Pointwise IGE", "ElementNodeData", _m, _dataPViewIGE, 0, 1));
  }

  if(_pwICN) {
    _setInterpolationMatrices(
      new PView("Pointwise ICN", "ElementNodeData", _m, _dataPViewICN, 0, 1));
  }
}

#endif

#endif
