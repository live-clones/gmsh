// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
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
#include <sstream>
#include <fstream>
#include "qualityMeasuresJacobian.h"

class bezierBasis;

StringXNumber CurvedMeshOptions_Number[] = {
  {GMSH_FULLRC, "Jacobian determinant", NULL, 1},
  {GMSH_FULLRC, "Scaled Jacobian", NULL, 0},
  {GMSH_FULLRC, "Isotropy", NULL, 1},
  {GMSH_FULLRC, "Hidding threshold", NULL, 9},
  {GMSH_FULLRC, "Draw PView", NULL, 0},
  {GMSH_FULLRC, "Recompute", NULL, 0},
  {GMSH_FULLRC, "Dimension of elements", NULL, -1}
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
    "According to what is asked, it computes the minimum of the Jacobian "
    "determinant (J), of the scaled Jacobian and/or of the isotropy measure. "
    "Statistics are printed and if asked a Pview is created for each measure. "
    "The plugin hides elements for which the measure mu > 'Hidding threshold', "
    "where mu is the isotropy measure if asked otherwise the scaled Jacobian if "
    "asked otherwise the Jacobian determinant.\n"
    "\n"
    "J is faster to compute but gives informations only on validity while the "
    "other measure gives also informations on quality.\n"
    "Warning: the scaled Jacobian is experimental for triangles, tetrahedra, "
    "prisms and pyramids. Computation may take a lot of time for those "
    "elements!\n"
    "\n"
    "Parameters:\n"
    "\n"
    "- Jacobian determinant = {0, 1}\n"
    "- Scaled Jacobian = {0, 1}\n"
    "- Isotropy = {0, 1}\n"
    "\n"
    "- Hidding threshold = [0, 1]: Does nothing if Isotropy == 0 and Scaled "
    "Jacobian == 0. Otherwise, hides all element for which min(mu) is "
    "strictly greater than the threshold, where mu is the isotropy if Isotropy "
    "== 1, otherwise it is the Scaled Jacobian. If threshold == 1, no effect, "
    "if == 0 hide all elements except invalid.\n"
    "\n"
    "- Draw PView = {0, 1}: Creates a PView of min(J)/max(J), min(scaled Jac) "
    "and/or min(isotropy) according to what is asked. If 'Recompute' = 1, a "
    "new PView is redrawed.\n"
    "\n"
    "- Recompute = {0,1}: If the mesh has changed, set to 1 to recompute the "
    "bounds.\n"
    "\n"
    "- Dimension = {-1, 1, 2, 3, 4}: If == -1, analyse element of the greater "
    "dimension. If == 4, analyse 2D and 3D elements.";
}

PView* GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
  _m = GModel::current();
  bool computeJac       = static_cast<int>(CurvedMeshOptions_Number[0].def);
  bool computeScaledJac = static_cast<int>(CurvedMeshOptions_Number[1].def);
  bool computeIsotropy  = static_cast<int>(CurvedMeshOptions_Number[2].def);
  _threshold     = static_cast<double>(CurvedMeshOptions_Number[3].def);
  bool drawPView = static_cast<int>(CurvedMeshOptions_Number[4].def);
  bool recompute = static_cast<bool>(CurvedMeshOptions_Number[5].def);
  int askedDim   = static_cast<int>(CurvedMeshOptions_Number[6].def);

  if (askedDim < 0 || askedDim > 4) askedDim = _m->getDim();

  if (recompute) {
    _data.clear();
    if (askedDim < 4) {
      _computedJ[askedDim-1] = false;
      _computedS[askedDim-1] = false;
      _computedI[askedDim-1] = false;
      _PViewJ[askedDim-1] = false;
      _PViewS[askedDim-1] = false;
      _PViewI[askedDim-1] = false;
    }
    else {
      _computedJ[1] = _computedJ[2] = false;
      _computedS[1] = _computedS[2] = false;
      _computedI[1] = _computedI[2] = false;
      _PViewJ[1] = _PViewJ[2] = false;
      _PViewS[1] = _PViewS[2] = false;
      _PViewI[1] = _PViewI[2] = false;
    }
  }

  // Compute what have to
  bool printStatJ = false;
  bool printStatS = false;
  bool printStatI = false;
  for (int dim = 1; dim <= 3 && dim <= _m->getDim(); ++dim) {
    if ((askedDim == 4 && dim > 1) || dim == askedDim) {
      if (!_computedJ[dim-1]) {
        double time = Cpu();
        Msg::StatusBar(true, "Computing Jacobian for %dD elements...", dim);
        _computeMinMaxJandValidity(dim);
        Msg::StatusBar(true, "Done computing Jacobian for %dD elements (%g s)",
                       dim, Cpu()-time);
        printStatJ = true;
      }
      if (computeScaledJac && !_computedS[dim-1]) {
        double time = Cpu();
        Msg::StatusBar(true, "Computing scaled Jacobian for %dD elements...", dim);
        _computeMinScaledJac(dim);
        Msg::StatusBar(true, "Done computing scaled Jacobian for %dD elements (%g s)",
                       dim, Cpu()-time);
        printStatS = true;
      }
      if (computeIsotropy && !_computedI[dim-1]) {
        double time = Cpu();
        Msg::StatusBar(true, "Computing isotropy for %dD elements...", dim);
        _computeMinIsotropy(dim);
        Msg::StatusBar(true, "Done computing isotropy for %dD elements (%g s)",
                       dim, Cpu()-time);
        printStatI = true;
      }
    }
  }
  if (printStatJ) _printStatJacobian();
  if (printStatS) _printStatScaledJac();
  if (printStatI) _printStatIsotropy();

  // Create PView
  if (drawPView)
  for (int dim = 1; dim <= 3; ++dim) {
    if ((askedDim == 4 && dim > 1) || dim == askedDim) {
      if (!_PViewJ[dim-1] && computeJac) {
        _PViewJ[dim-1] = true;
        std::map<int, std::vector<double> > dataPV;
        for (unsigned int i = 0; i < _data.size(); ++i) {
          MElement *const el = _data[i].element();
          if (el->getDim() == dim)
            dataPV[el->getNum()].push_back(_data[i].minJ()/_data[i].maxJ());
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "minJ/maxJ " << dim << "D";
          new PView(name.str().c_str(), "ElementData", _m, dataPV);
        }
      }
      if (!_PViewS[dim-1] && computeScaledJac) {
        _PViewS[dim-1] = true;
        std::map<int, std::vector<double> > dataPV;
        for (unsigned int i = 0; i < _data.size(); ++i) {
          MElement *const el = _data[i].element();
          if (el->getDim() == dim)
            dataPV[el->getNum()].push_back(_data[i].minS());
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "Scaled Jacobian " << dim << "D";
          new PView(name.str().c_str(), "ElementData", _m, dataPV);
        }
      }
      if (!_PViewI[dim-1] && computeIsotropy) {
        _PViewI[dim-1] = true;
        std::map<int, std::vector<double> > dataPV;
        for (unsigned int i = 0; i < _data.size(); ++i) {
          MElement *const el = _data[i].element();
          if (el->getDim() == dim)
            dataPV[el->getNum()].push_back(_data[i].minI());
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "Isotropy " << dim << "D";
          new PView(name.str().c_str(), "ElementData", _m, dataPV);
        }
      }
    }
  }

  // Hide elements
#if defined(HAVE_OPENGL)
  _hideWithThreshold(askedDim,
      computeIsotropy ? 2 :
          computeScaledJac ? 1 :
              computeJac ? 0 : -1);
  CTX::instance()->mesh.changed = (ENT_ALL);
  drawContext::global()->draw();
#endif

  return NULL;
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinMaxJandValidity(int dim)
{
  if (_computedJ[dim-1]) return;

  std::set<GEntity*, GEntityLessThan> entities;
  switch (dim) {
    case 3:
      for (GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++)
        entities.insert(*it);
      break;
    case 2:
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++)
        entities.insert(*it);
      break;
    case 1:
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++)
        entities.insert(*it);
      break;
    default:
      Msg::Fatal("This should not happen.");
      return;
  }

  std::set<GEntity*, GEntityLessThan>::iterator it;
  for (it = entities.begin(); it != entities.end(); ++it) {
    GEntity *entity = *it;
    unsigned num = entity->getNumMeshElements();
    fullMatrix<double> *normals = NULL;
    switch (dim) {
      case 3:
        Msg::StatusBar(true, "Volume %d: checking the Jacobian of %d elements",
            entity->tag(), num);
        break;
      case 2:
        Msg::StatusBar(true, "Surface %d: checking the Jacobian of %d elements",
            entity->tag(), num);
        if (entity->geomType() == GEntity::Plane &&
            entity->haveParametrization()) {
          double u = entity->parBounds(0).low();
          double v = entity->parBounds(1).low();
          SVector3 n = dynamic_cast<GFace*>(entity)->normal(SPoint2(u, v));
          normals = new fullMatrix<double>(1, 3);
          normals->set(0, 0, n[0]);
          normals->set(0, 1, n[1]);
          normals->set(0, 2, n[2]);
        }
        else if (entity->geomType() == GEntity::DiscreteSurface) {
          SBoundingBox3d bb = entity->bounds();
          // If we don't have the CAD, check if the mesh is 2D:
          if (!bb.empty() && bb.max().z() - bb.min().z() == .0) {
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
        if (entity->geomType() == GEntity::Line &&
            entity->haveParametrization()) {
          double u = entity->parBounds(0).low();
          SVector3 t = dynamic_cast<GEdge*>(entity)->firstDer(u);
          SVector3 dum = SVector3(0, 0, 0);
          if(t[0] == 0.)
            dum[0] = 1;
          else if(t[1] == 0.)
            dum[1] = 1;
          else
            dum[2] = 1;
          SVector3 n1, n2;
          n1 = crossprod(t, dum);
          n1.normalize();
          n2 = crossprod(t, n1);
          n2.normalize();
          normals = new fullMatrix<double>(2, 3);
          normals->set(0, 0, n1[0]);
          normals->set(0, 1, n1[1]);
          normals->set(0, 2, n1[2]);
          normals->set(1, 0, n2[0]);
          normals->set(1, 1, n2[1]);
          normals->set(1, 2, n2[2]);
        }
        else if (entity->geomType() == GEntity::DiscreteCurve) {
          SBoundingBox3d bb = entity->bounds();
          // If we don't have the CAD, check if the mesh is 1D:
          if (!bb.empty() && bb.max().y() - bb.min().y() == .0 &&
                             bb.max().z() - bb.min().z() == .0) {
            normals = new fullMatrix<double>(2, 3);
            normals->set(0, 0, 0);
            normals->set(0, 1, 1);
            normals->set(0, 2, 0);
            normals->set(1, 0, 0);
            normals->set(1, 1, 0);
            normals->set(1, 2, 1);
          }
        }
        break;
      default: break;
    }

    double initial, time = initial = Cpu();
    unsigned int percentage = 0, nextCheck = 0;

    for (unsigned i = 0; i < num; ++i) {
      MElement *el = entity->getMeshElement(i);
      double min, max;
      jacobianBasedQuality::minMaxJacobianDeterminant(el, min, max, normals);
      _data.push_back(data_elementMinMax(el, min, max));
      if (min < 0 && max < 0) {
        Msg::Warning("Element %d is completely inverted", el->getNum());
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
          if (remaining < 60*2)
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
    delete normals;
  }
  _computedJ[dim-1] = true;
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinMaxJandValidity(MElement *const*el, int numEl)
{
  for (int k = 0; k < numEl; ++k) {
    double min, max;
    jacobianBasedQuality::minMaxJacobianDeterminant(el[k], min, max);
    _data.push_back(data_elementMinMax(el[k], min, max));
    if (min < 0 && max < 0) {
      Msg::Warning("Element %d is completely inverted", el[k]->getNum());
    }
  }
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinScaledJac(int dim)
{
  if (_computedS[dim-1]) return;

  double initial, time = initial = Cpu();
  unsigned int percentage = 0, nextCheck = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    if (el->getDim() != dim) continue;
    if (_data[i].minJ() <= 0) {
      _data[i].setMinS(0);
    }
    else {
      _data[i].setMinS(jacobianBasedQuality::minScaledJacobian(el, true));
    }
//    Msg::Info("Scaled Jac");
//    Msg::Info("==========");
//    for (int k = 1; k < 30; ++k) {
//      Msg::Info("%.10g", jacobianBasedQuality::minSampledScaledJacobian(el, k));
//    }
//    Msg::Info(" ");
    if (i >= nextCheck) {
      nextCheck += _data.size() / 100;
      double curTime = Cpu();
      unsigned int curPercentage = i*100/_data.size();
      if ((curTime - time > 10. && curPercentage > percentage + 4) ||
          (curTime - time > 15. && curPercentage < 5)) {
        percentage = curPercentage;
        time = curTime;
        const double remaining = (time-initial) / (i+1) * (_data.size() - i-1);
        if (remaining < 60*2)
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

  _computedS[dim-1] = true;
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinIsotropy(int dim)
{
  if (_computedI[dim-1]) return;

  double initial, time = initial = Cpu();
  unsigned int percentage = 0, nextCheck = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    if (el->getDim() != dim) continue;
    if (_data[i].minJ() <= 0) {
      _data[i].setMinI(0);
    }
    else {
      _data[i].setMinI(jacobianBasedQuality::minIsotropyMeasure(el, true));
    }
//    Msg::Info("Isotropy");
//    Msg::Info("========");
//    for (int k = 1; k < 30; ++k) {
//      Msg::Info("%.10g", jacobianBasedQuality::minSampledIsotropyMeasure(el, k));
//    }
//    Msg::Info(" ");
    if (i >= nextCheck) {
      nextCheck += _data.size() / 100;
      double curTime = Cpu();
      unsigned int curPercentage = i*100/_data.size();
      if ((curTime - time > 10. && curPercentage > percentage + 4) ||
          (curTime - time > 15. && curPercentage < 5)) {
        percentage = curPercentage;
        time = curTime;
        const double remaining = (time-initial) / (i+1) * (_data.size() - i-1);
        if (remaining < 60*2)
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

  _computedI[dim-1] = true;
}

int GMSH_AnalyseCurvedMeshPlugin::_hideWithThreshold(int askedDim, int whichMeasure)
{
  // only hide for quality measures
  if (_threshold > 1 || whichMeasure == 0) return 0;

  int nHidden = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    const int dim = el->getDim();
    if ((askedDim == 4 && dim > 1) || dim == askedDim) {
      bool toHide = false;
      switch (whichMeasure) {
      case 2:
        toHide = _data[i].minI() > _threshold;
        break;
      case 1:
        toHide = _data[i].minS() > _threshold;
        break;
      case 0:
        toHide = _data[i].minJ() > _threshold;
        break;
      }
      if (toHide) {
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

void GMSH_AnalyseCurvedMeshPlugin::_printStatJacobian()
{
  if (_data.empty()) {
    Msg::Info("No stat to print.");
    return;
  }
  double infminJ, supminJ, avgminJ;
  double infratJ, supratJ, avgratJ;
  double avgratJc;
  int count = 0, countc = 0;

  infminJ = infratJ = 1e10;
  supminJ = supratJ = -1e10;
  avgminJ = avgratJ = avgratJc = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    double q = 0;
    if ( _data[i].minJ() > 0) q = _data[i].minJ() / _data[i].maxJ();
    infminJ = std::min(infminJ, _data[i].minJ());
    supminJ = std::max(supminJ, _data[i].minJ());
    avgminJ += _data[i].minJ();
    infratJ = std::min(infratJ, _data[i].minJ()/_data[i].maxJ());
    supratJ = std::max(supratJ, _data[i].minJ()/_data[i].maxJ());
    avgratJ += _data[i].minJ()/_data[i].maxJ();
    ++count;
    if (q < 1-1e-5) {
      avgratJc += _data[i].minJ()/_data[i].maxJ();
      ++countc;
    }
  }
  avgminJ /= count;
  avgratJ /= count;
  avgratJc /= countc;

  Msg::Info("Min Jac. det. (minJ): %6.3g, %6.3g, %6.3g (= min, avg, max)",
            infminJ, avgminJ, supminJ);
  Msg::Info("Ratio minJ/maxJ     : %6.3f, %6.3f, %6.3f (= worst, avg, best)",
            infratJ, avgratJ, supratJ);
  if (countc && countc < count)
    Msg::Info("                      (avg = %.3f"
              " on the %d non-constant elements)",
              avgratJc, countc);
}

void GMSH_AnalyseCurvedMeshPlugin::_printStatScaledJac()
{
  if (_data.empty()) {
    Msg::Info("No stat to print.");
    return;
  }
  double infminS, supminS, avgminS;
  infminS = supminS = avgminS = _data[0].minS();

  for (unsigned int i = 1; i < _data.size(); ++i) {
    infminS = std::min(infminS, _data[i].minS());
    supminS = std::max(supminS, _data[i].minS());
    avgminS += _data[i].minS();
  }
  avgminS /= _data.size();

  Msg::Info("Scaled Jacobian     : %6.3f, %6.3f, %6.3f (= worst, avg, best)",
      infminS, avgminS, supminS);
}

void GMSH_AnalyseCurvedMeshPlugin::_printStatIsotropy()
{
  if (_data.empty()) {
    Msg::Info("No stat to print.");
    return;
  }
  double infminI, supminI, avgminI;
  infminI = supminI = avgminI = _data[0].minI();

  for (unsigned int i = 1; i < _data.size(); ++i) {
    infminI = std::min(infminI, _data[i].minI());
    supminI = std::max(supminI, _data[i].minI());
    avgminI += _data[i].minI();
  }
  avgminI /= _data.size();

  Msg::Info("Isotropy            : %6.3f, %6.3f, %6.3f (= worst, avg, best)",
      infminI, avgminI, supminI);
}

// For testing
void GMSH_AnalyseCurvedMeshPlugin::computeMinR(MElement *const *el,
                                               int numEl,
                                               double *minR,
                                               bool *straight)
{
  _computedJ[el[0]->getDim()-1] = false;
  _computedI[el[0]->getDim()-1] = false;
  _data.clear();

  _computeMinMaxJandValidity(el, numEl);
  _computeMinIsotropy(el[0]->getDim());
  if (minR) {
    for (unsigned int i = 0; i < _data.size(); ++i) {
      minR[i] = _data[i].minI();
    }
  }
  if (straight) {
    for (unsigned int i = 0; i < _data.size(); ++i) {
      straight[i] = 0;
    }
  }
}

#endif
