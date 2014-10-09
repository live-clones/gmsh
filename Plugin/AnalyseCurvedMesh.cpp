// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "AnalyseCurvedMesh.h"
#include "OS.h"
#include "Context.h"
#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#include "PView.h"
#include "GModel.h"
#include "MElement.h"
#include "bezierBasis.h"
#include "MetricBasis.h"
#include <sstream>

namespace {

class BezierJacobian;
struct lessMinVal {
  bool operator()(BezierJacobian*, BezierJacobian*) const;
};
struct lessMax {
  bool operator()(BezierJacobian*, BezierJacobian*) const;
};

class BezierJacobian
{
private:
  fullVector<double> _jacBez;
  double _minL, _maxL, _minB, _maxB; //Extremum of Jac at corners and of bezier values
  int _depthSub;
  const bezierBasis *_bfs;

public:
  BezierJacobian(fullVector<double>&, const bezierBasis*, int depth);
  void subDivisions(fullVector<double> &vect) const
    {_bfs->subDivisor.mult(_jacBez, vect);}

  bool boundsOk(double tol, double minL, double maxL) {
    return (minL <= 0 || _minB > 0) &&
           minL - _minB <= tol &&
           _maxB - maxL <= tol;
  }

  inline int depth() const {return _depthSub;}
  inline double minL() const {return _minL;}
  inline double maxL() const {return _maxL;}
  inline double minB() const {return _minB;}
  inline double maxB() const {return _maxB;}
};

} // namespace

StringXNumber CurvedMeshOptions_Number[] = {
  {GMSH_FULLRC, "Show: 0:J, 1:R, 2:J&&R", NULL, 1},
  {GMSH_FULLRC, "Draw PView", NULL, 1},
  {GMSH_FULLRC, "Hidding threshold", NULL, .1},
  {GMSH_FULLRC, "Dimension of elements", NULL, -1},
  {GMSH_FULLRC, "Recompute bounds", NULL, 0},
  {GMSH_FULLRC, "Tolerance", NULL, 1e-3}
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
    "It computes, min(J) where J is the scaled Jacobian determinant and, if "
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
    "computes Jacobian and metric and shows min(R). If 2, behaves like it is 1 "
    "but draw the two min(J) and min(R) PView\n"
    "\n"
    "- Draw PView = {0, 1}: Creates a PView of min({J, R}) if it does not "
    "exist already. If 'Recompute' = 1, a new PView is redrawed.\n"
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

// Execution
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
  for (int dim = 1; dim <= 3; ++dim) {
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
            dataPV[el->getNum()].push_back(_data[i].minJ());
          }
        }
        if (dataPV.size()) {
          std::stringstream name;
          name << "min J " << dim << "D";
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
  if (numEl < 1)
    return;

  const JacobianBasis *jfs = el[0]->getJacobianFuncSpace();
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el[0]->getNum());
    return;
  }
  const bezierBasis *bfs = jfs->getBezier();

  _data.reserve(_data.size() + numEl);

  const int numSamplingPt = jfs->getNumJacNodes();
  const int numMapNodes = jfs->getNumMapNodes();
  fullVector<double> jacobian(numSamplingPt);
  fullVector<double> jacBez(numSamplingPt);
  fullVector<double> subJacBez(bfs->getNumSubNodes());

  for (int k = 0; k < numEl; ++k) {
    fullMatrix<double> nodesXYZ(numMapNodes,3);
    el[k]->getNodesCoord(nodesXYZ);
    jfs->getScaledJacobian(nodesXYZ,jacobian);
    jfs->lag2Bez(jacobian, jacBez);

    BezierJacobian *bj = new BezierJacobian(jacBez, bfs, 0);
    std::vector<BezierJacobian*> heap;
    heap.push_back(bj);

    double minL = bj->minL(), maxL = bj->maxL();
    int currentDepth = 0;

    while (!heap[0]->boundsOk(_tol, minL, maxL)) {
      bj = heap[0];
      pop_heap(heap.begin(), heap.end(), lessMinVal());
      heap.pop_back();

      bj->subDivisions(subJacBez);
      currentDepth = bj->depth() + 1;
      if (currentDepth > 20) {
        static int a = 0;
        if (++a == 1)
          Msg::Error("depth is too damn high ! elem type %d",
                     el[k]->getTypeForMSH());
      }

      for (int i = 0; i < bfs->getNumDivision(); i++) {
        jacBez.setAsProxy(subJacBez, i * numSamplingPt, numSamplingPt);
        BezierJacobian *newbj = new BezierJacobian(jacBez, bfs, currentDepth);
        minL = std::min(minL, newbj->minL());
        maxL = std::max(maxL, newbj->maxL());

        heap.push_back(newbj);
        push_heap(heap.begin(), heap.end(), lessMinVal());
      }
      delete bj;
    }

    make_heap(heap.begin(), heap.end(), lessMax());

    while (!heap[0]->boundsOk(_tol, minL, maxL)) {
      bj = heap[0];
      pop_heap(heap.begin(), heap.end(), lessMax());
      heap.pop_back();

      bj->subDivisions(subJacBez);
      currentDepth = bj->depth() + 1;
      if (currentDepth > 20) {
        static int a = 0;
        if (++a == 1)
          Msg::Error("depth is too damn high ! elem type %d",
                     el[k]->getTypeForMSH());
      }

      for (int i = 0; i < bfs->getNumDivision(); i++) {
        jacBez.setAsProxy(subJacBez, i * numSamplingPt, numSamplingPt);
        BezierJacobian *newbj = new BezierJacobian(jacBez, bfs, currentDepth);
        minL = std::min(minL, newbj->minL());
        maxL = std::max(maxL, newbj->maxL());

        heap.push_back(newbj);
        push_heap(heap.begin(), heap.end(), lessMax());
      }
      delete bj;
    }

    double minB = minL;
    double maxB = maxL;
    for (unsigned int i = 0; i < heap.size(); ++i) {
      minB = std::min(minB, heap[i]->minB());
      maxB = std::max(maxB, heap[i]->maxB());
      delete heap[i];
    }
    _data.push_back(CurvedMeshPluginData(el[k], minB, maxB));
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
    if (el->getDim() == dim) {
      if (_data[i].minJ() <= 0)
        _data[i].setMinR(0);
      else if (_data[i].maxJ() - _data[i].minJ() < _tol * 1e-2)
        _data[i].setMinR(MetricBasis::minSampledR(el, 0));
      else
        _data[i].setMinR(MetricBasis::boundMinR(el));
    }
    if (i >= nextCheck) {
      nextCheck += _data.size() / 100;
      double curTime = Cpu();
      unsigned int curPercentage = i*100/_data.size();
      if ((curTime - time > 10. && curPercentage > percentage + 4) ||
          (curTime - time > 15. && curPercentage < 5)) {
        percentage = curPercentage;
        time = curTime;
        Msg::StatusBar(true, "%d%% (remaining time ~%g secondes)",
            percentage, (time-initial) / (i+1) * (_data.size() - i-1));
      }
    }
  }

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
    if (_data[i].maxJ() - _data[i].minJ() > _tol * 1e-2) {
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

BezierJacobian::BezierJacobian(fullVector<double> &v,
    const bezierBasis *bfs, int depth)
{
  _jacBez = v;
  _depthSub = depth;
  _bfs = bfs;

  _minL = _maxL = v(0);
  int i = 1;
  for (; i < bfs->getNumLagCoeff(); i++) {
    if (_minL > v(i)) _minL = v(i);
    if (_maxL < v(i)) _maxL = v(i);
  }
  _minB = _minL;
  _maxB = _maxL;
  for (; i < v.size(); i++) {
    if (_minB > v(i)) _minB = v(i);
    if (_maxB < v(i)) _maxB = v(i);
  }
}

bool lessMinVal::operator()(BezierJacobian *bj1, BezierJacobian *bj2) const
{
  return bj1->minB() > bj2->minB();
}

bool lessMax::operator()(BezierJacobian *bj1, BezierJacobian *bj2) const
{
  return bj1->maxB() < bj2->maxB();
}
