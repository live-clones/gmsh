// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include "AnalyseCurvedMesh.h"
#include "OS.h"
#include "Context.h"
#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#include "PView.h"
#include "GModel.h"
#include "MElement.h"
#include "MetricBasis.h"
#include <sstream>
#include <fstream>
#include "qualityMeasuresJacobian.h"

class bezierBasis;

StringXNumber CurvedMeshOptions_Number[] = {
  {GMSH_FULLRC, "Show: 0:J, 1:R, 2:J&&R", NULL, 1},
  {GMSH_FULLRC, "Draw PView", NULL, 1},
  {GMSH_FULLRC, "Hidding threshold", NULL, 10},
  {GMSH_FULLRC, "Dimension of elements", NULL, -1},
  {GMSH_FULLRC, "Recompute bounds", NULL, 0},
  {GMSH_FULLRC, "Tolerance", NULL, 1e-3}
  // tolerance: To be removed when MetricBasis => qualityMeasuresJacobian
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin()
  {
    return new GMSH_AnalyseCurvedMeshPlugin();
  }
}

int GMSH_AnalyseCurvedMeshPlugin::getNbOptions() const
{
  return sizeof(CurvedMeshOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnalyseCurvedMeshPlugin::getOption(int iopt)
{
  return &CurvedMeshOptions_Number[iopt];
}

std::string GMSH_AnalyseCurvedMeshPlugin::getHelp() const
{
  return "Plugin(AnalyseCurvedMesh) analyse all elements of a given dimension. "
    "It computes, min(J) where J is the Jacobian determinant and, if "
    "asked, min(R) where R is the ratio between the smaller and the greater "
    "of the eigenvalues of the metric. It creates a PView and hides "
    "elements for which min({J, R}) < 'Hidding threshold'.\n"
    "\n"
    "J is faster to compute but gives informations only on validity while R "
    "gives also informations on quality.\n"
    "\n"
    "Parameters:\n"
    "\n"
    "- Show [...] = {0, 1, 2}: If 0, computes Jacobian and shows min(J). If 1, "
    "computes Jacobian and metric and shows min(R). If 2, behaves as if it is "
    "1 but shows both min(J) and min(R).\n"
    "\n"
    "- Draw PView = {0, 1}: Creates a PView of min({J, R}) if it does not "
    "already exists. If 'Recompute' = 1, a new PView is redrawed.\n"
    "\n"
    "- Hidding threshold = [0,1]: Hides all element for which min(R) or min(J) "
    "is strictly greater than the threshold. If = 1, no effect, if = 0 hide "
    "all elements except invalid.\n"
    "\n"
    "- Dimension = {-1, 1, 2, 3, 4}: If = -1, analyse element of the greater "
    "dimension. If = 4, analyse 2D and 3D elements\n"
    "\n"
    "- Recompute = {0,1}: If the mesh has changed, set to 1 to recompute the "
    "bounds.\n"
    "\n"
    "- Tolerance = ]0, 1[: Tolerance on the computation of min({R, J}). "
    "It should be at most 0.01 but it can be set to 1 or greater to just check "
    "the validity of the mesh.";
}

PView *GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
  _m = GModel::current();
  _computeMetric = static_cast<int>(CurvedMeshOptions_Number[0].def);
  bool drawPView = static_cast<int>(CurvedMeshOptions_Number[1].def);
  _threshold     = static_cast<double>(CurvedMeshOptions_Number[2].def);
  int askedDim   = static_cast<int>(CurvedMeshOptions_Number[3].def);
  bool recompute = static_cast<bool>(CurvedMeshOptions_Number[4].def);
  _tol           = static_cast<double>(CurvedMeshOptions_Number[5].def);

  if (askedDim < 0 || askedDim > 4) askedDim = _m->getDim();

  if (recompute) {
    _data.clear();
    if (askedDim < 4) {
      _computedR[askedDim-1] = false;
      _computedJ[askedDim-1] = false;
      _PViewJ[askedDim-1] = false;
      _PViewR[askedDim-1] = false;
    }
    else {
      _computedR[1] = _computedR[2] = false;
      _computedJ[1] = _computedJ[2] = false;
      _PViewJ[1] = _PViewJ[2] = false;
      _PViewR[1] = _PViewR[2] = false;
    }
    _msgHide = true;
  }

  // Compute J and/or R
  for (int dim = 1; dim <= 3 && dim <= _m->getDim(); ++dim) {
    if ((askedDim == 4 && dim > 1) || dim == askedDim) {
      if (!_computedJ[dim-1]) {
        double time = Cpu();
        Msg::StatusBar(true, "Computing Jacobian for %dD elements...", dim);
        _computeMinMaxJandValidity(dim);
        Msg::StatusBar(true, "... Done computing Jacobian (%g seconds)", Cpu()-time);
        _printStatJacobian();
      }
      if (_computeMetric && !_computedR[dim-1]) {
        double time = Cpu();
        Msg::StatusBar(true, "Computing metric for %dD elements...", dim);
        _computeMinR(dim);
        Msg::StatusBar(true, "... Done computing metric (%g seconds)", Cpu()-time);
        _printStatMetric();
      }
    }
  }

  // Create PView
  if (drawPView)
  for (int dim = 1; dim <= 3; ++dim) {
    if ((askedDim == 4 && dim > 1) || dim == askedDim) {
      if (!_PViewJ[dim-1] && _computeMetric != 1) {
        _PViewJ[dim-1] = true;
        std::map<int, std::vector<double> > dataPV;
        for (unsigned int i = 0; i < _data.size(); ++i) {
          MElement *const el = _data[i].element();
          if (el->getDim() == dim) {
            double q = 0;
            if (_data[i].minJ() > 0) q = _data[i].minJ()/_data[i].maxJ();
            dataPV[el->getNum()].push_back(q);
          }
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "minJ/maxJ " << dim << "D";
          new PView(name.str().c_str(), "ElementData", _m, dataPV);
        }
      }
      if (!_PViewR[dim-1] && _computeMetric) {
        _PViewR[dim-1] = true;
        std::map<int, std::vector<double> > dataPV;
        for (unsigned int i = 0; i < _data.size(); ++i) {
          MElement *const el = _data[i].element();
          if (el->getDim() == dim)
            dataPV[el->getNum()].push_back(_data[i].minR());
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "min R " << dim << "D";
          new PView(name.str().c_str(), "ElementData", _m, dataPV);
        }

        /*std::map<int, std::vector<double> > dataPV2;
        for (unsigned int i = 0; i < _data.size(); ++i) {
          MElement *const el = _data[i].element();
          if (el->getDim() == dim)
            dataPV2[el->getNum()].push_back(_data[i].minR()/_data[i].minRR());
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "min RR " << dim << "D";
          new PView(name.str().c_str(), "ElementData", _m, dataPV2);
        }*/
      }
    }
  }

  // Hide elements
#if defined(HAVE_OPENGL)
  if (_hideWithThreshold(askedDim) && _msgHide) {
    _msgHide = false;
    Msg::Info("Note: Some elements have been hidden (param 'Hidding Threshold').");
    Msg::Info("      (To revert: set 'Hidding Threshold' to 1 and rerun");
    Msg::Info("                  or, Tools > Visibility > Interactive > Show All)");
  }
  CTX::instance()->mesh.changed = (ENT_ALL);
  drawContext::global()->draw();
#endif

  return 0;
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinMaxJandValidity(int dim)
{
  if (_computedJ[dim-1]) return;

  switch (dim) {
    case 3 :
      for (GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);

        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          _computeMinMaxJandValidity(el, numType[type]);
        }
      }
      break;

    case 2 :
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);

        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          _computeMinMaxJandValidity(el, numType[type]);
        }
      }
      break;

    case 1 :
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        _computeMinMaxJandValidity(el, numElement);
      }
      break;

    default :
      Msg::Fatal("This should not happen.");
      return;
  }

  _computedJ[dim-1] = true;
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinMaxJandValidity(MElement *const*el, int numEl)
{
  for (int k = 0; k < numEl; ++k) {
    double min, max;
    jacobianBasedQuality::minMaxJacobianDeterminant(el[k], min, max);
    _data.push_back(data_elementMinMax(el[k], min, max));
  }
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinR(int dim)
{
  if (_computedR[dim-1]) return;

  MetricBasis::setTol(_tol);

  double initial, time = initial = Cpu();
  unsigned int percentage = 0, nextCheck = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    //if (el->getNum() != 10535) continue;
    /*if (el->getNum() != 2712 &&
        el->getNum() != 3378 &&
        el->getNum() != 3997 &&
        el->getNum() != 4314) continue;*/
    if (el->getDim() == dim) {
      if (_data[i].minJ() <= 0)
        _data[i].setMinR(0);
      else {
        _data[i].setMinR(MetricBasis::getMinR(el));
        //_data[i].setMinR(jacobianBasedQuality::minScaledJacobian(el));
        //_data[i].setMinR(MetricBasis::getMinSampledR(el, 10));
      }
      //_data[i].setMinRR(MetricBasis::getMaxSampledR(el, 10));
    }
    if (i >= nextCheck) {
      nextCheck += _data.size() / 100;
      double curTime = Cpu();
      unsigned int curPercentage = i*100/_data.size();
      if ((curTime - time > 10. && curPercentage > percentage + 4) ||
          (curTime - time > 15. && curPercentage < 5)) {
        percentage = curPercentage;
        time = curTime;
        const double remaining = (time-initial) / (i+1) * (_data.size() - i-1);
        if (remaining < 300)
          Msg::StatusBar(true, "%d%% (remaining time ~%g seconds)",
              percentage, remaining);
        else if (remaining < 60*60*2)
          Msg::StatusBar(true, "%d%% (remaining time ~%g minutes)",
              percentage, remaining/60);
        else
          Msg::StatusBar(true, "%d%% (remaining time ~%g hours)",
              percentage, remaining/3600);
      }
    }
  }

  /*std::fstream file;
  file.open("comparisonMyMetric_and_Jacobian_vs_minr_maxr.txt", std::fstream::out);
  file << _data.size() << std::endl;

  int n = 0, next = _data.size()/100;
  double tm = Cpu();
  for (unsigned int i = 0; i < _data.size(); ++i) {
    if (++n > next) {
      Msg::Info("%d%% %g seconds", n*100/_data.size(), Cpu()-tm);
      next += _data.size()/100;
    }
    MElement *const el = _data[i].element();
    file << _data[i].minJ() << " ";
    file << _data[i].maxJ() << " ";
    file << _data[i].minR() << " ";
    file << MetricBasis::minSampledGlobalRatio(el, 7) << std::endl;
  }
  file.close();*/

  _computedR[dim-1] = true;
}

bool GMSH_AnalyseCurvedMeshPlugin::_hideWithThreshold(int askedDim)
{
  if (_threshold >= 1.) return false;

  bool ans = false;
  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    const int dim = el->getDim();
    if ((askedDim == 4 && dim > 1) || dim == askedDim) {
      if (( _computeMetric && _data[i].minR() > _threshold) ||
          (!_computeMetric && _data[i].minJ() > _threshold)   ) {
        el->setVisibility(0);
        ans = true;
      }
      else {
        el->setVisibility(1);
      }
    }
  }
  return ans;
}

void GMSH_AnalyseCurvedMeshPlugin::_printStatMetric()
{
  if (_data.empty()) {
    Msg::Info("No stat to print.");
    return;
  }
  double infminR, supminR, avgminR;
  infminR = supminR = avgminR = _data[0].minR();

  for (unsigned int i = 1; i < _data.size(); ++i) {
    infminR = std::min(infminR, _data[i].minR());
    supminR = std::max(supminR, _data[i].minR());
    avgminR += _data[i].minR();
  }
  avgminR /= _data.size();

  Msg::Info("Minimum of R: in [%g, %g], avg=%g (R ~= measure of anisotropy)",
      infminR, supminR, avgminR);
}

void GMSH_AnalyseCurvedMeshPlugin::_printStatJacobian()
{
  if (_data.empty()) {
    Msg::Info("No stat to print.");
    return;
  }
  double infminJ, supminJ, avgminJ;
  double infratJ, supratJ, avgratJ;
  int count = 0;

  infminJ = infratJ = 1e10;
  supminJ = supratJ = -1e10;
  avgminJ = avgratJ = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    double q = 0;
    if ( _data[i].minJ() > 0) q = _data[i].minJ() / _data[i].maxJ();
    if (q < 1-1e-3) {
      infminJ = std::min(infminJ, _data[i].minJ());
      supminJ = std::max(supminJ, _data[i].minJ());
      avgminJ += _data[i].minJ();
      infratJ = std::min(infratJ, _data[i].minJ()/_data[i].maxJ());
      supratJ = std::max(supratJ, _data[i].minJ()/_data[i].maxJ());
      avgratJ += _data[i].minJ()/_data[i].maxJ();
      ++count;
    }
  }
  avgminJ /= count;
  avgratJ /= count;

  Msg::Info("Minimum of Jacobian: in [%g, %g], avg=%g (only the %d curved elem.)",
      infminJ, supminJ, avgminJ, count);
  Msg::Info("Ratio minJ/maxJ    : in [%g, %g], avg=%g (only the %d curved elem.)",
      infratJ, supratJ, avgratJ, count);
}

// For testing
void GMSH_AnalyseCurvedMeshPlugin::computeMinR(MElement *const *el,
                                               int numEl,
                                               double *minR,
                                               bool *straight)
{
  _computedJ[el[0]->getDim()-1] = false;
  _computedR[el[0]->getDim()-1] = false;
  _data.clear();

  _computeMinMaxJandValidity(el, numEl);
  _computeMinR(el[0]->getDim());
  if (minR) {
    for (unsigned int i = 0; i < _data.size(); ++i) {
      minR[i] = _data[i].minR();
    }
  }
  if (straight) {
    for (unsigned int i = 0; i < _data.size(); ++i) {
      straight[i] = 0;
    }
  }
}

#endif
