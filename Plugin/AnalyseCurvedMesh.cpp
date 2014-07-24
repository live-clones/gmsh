// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "AnalyseCurvedMesh.h"
#include "GModel.h"
#include "OS.h"
#include "Context.h"

#include <cmath>
#include <queue>
#include <sstream>

#include "GmshMessage.h"
#include "PView.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

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
  const JacobianBasis *_jfs;

public:
  BezierJacobian(fullVector<double> &, const JacobianBasis *, int depth);
  void subDivisions(fullVector<double> &vect) const
    {_jfs->subdivideBezierCoeff(_jacBez, vect);}

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
  {GMSH_FULLRC, "Show: (0) Jacobian, (1) Metric", NULL, 1},
  {GMSH_FULLRC, "Number of PView", NULL, 2},
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
    "It computes, min(J) where J is the scaled Jacobian determinant. Eventually, "
    "it computes min(R) where R is the ratio between the smaller and the greater "
    "of the eigenvalues of the metric. It creates one or more PView and hides "
    "elements for which min({J, R}) < 'Hidding threshold'.\n"
    "\n"
    "Parameters:\n"
    "\n"
    "- Show [...] = {0, 1}: If 0, computes Jacobian and shows min(J). If 1, computes "
    "Jacobian and metric and shows min(R).\n"
    "\n"
    "- Number of PView = {0, 1, 2}: If 1, create one PView with all elements. If 2, create "
    "two PView, one with straight-sided elements and one with curved elements.\n"
    "\n"
    "- Hidding threshold = [0,1]: Hides all element for which min(R) or min(J) "
    "is strictly greater than the threshold. If = 1, no effect, if = 0 hide "
    "all elements except invalid.\n"
    "\n"
    "- Dimension = {-1, 1, 2, 3}: If = -1, analyse element of the greater dimension.\n"
    "\n"
    "- Recompute = {0,1}: If the mesh has changed, set to 1 to recompute the bounds.\n"
    "\n"
    "- Tolerance = ]0, 1[: Tolerance on the computation of min(R) or min(J). "
    "It should be at most 0.01 but it can be set to 1 to just check the validity of "
    "the mesh.";
}

// Execution
PView *GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
  _m = GModel::current();
  _computeMetric = static_cast<int>(CurvedMeshOptions_Number[0].def);
  _numPView      = static_cast<int>(CurvedMeshOptions_Number[1].def);
  _threshold     = static_cast<double>(CurvedMeshOptions_Number[2].def);
  _dim           = static_cast<int>(CurvedMeshOptions_Number[3].def);
  _recompute     = static_cast<bool>(CurvedMeshOptions_Number[4].def);
  _tol           = static_cast<double>(CurvedMeshOptions_Number[5].def);

  if (_dim < 0 || _dim > 3) _dim = _m->getDim();

  if (_recompute) {
    _data.clear();
    _computedJ3D = false;
    _computedJ2D = false;
    _computedJ1D = false;
    _computedR3D = false;
    _computedR2D = false;
    _msgHide = true;
    _1PViewJ = false;
    _2PViewJ = false;
    _1PViewR = false;
    _2PViewR = false;
  }

  if ((_dim == 1 && !_computedJ1D) ||
      (_dim == 2 && !_computedJ2D) ||
      (_dim == 3 && !_computedJ3D)   ) {
    double time = Cpu();
    Msg::StatusBar(true, "Computing Jacobian for %dD elements...", _dim);
    _computeMinMaxJandValidity();
    Msg::StatusBar(true, "... Done computing Jacobian (%g seconds)", Cpu()-time);
    _printStatJacobian();
  }

  if (_computeMetric &&
      ((_dim == 2 && !_computedR2D) ||
       (_dim == 3 && !_computedR3D)   )) {
    double time = Cpu();
    Msg::StatusBar(true, "Computing metric for %dD elements...", _dim);
    _computeMinR();
    Msg::StatusBar(true, "... Done computing metric (%g seconds)", Cpu()-time);
    _printStatMetric();
  }

  if (_computeMetric &&
      (_dim == 1 ||
       (_dim == 2 && !_computedR2D) ||
       (_dim == 3 && !_computedR3D))) {
    return 0;
  }

  // Create PView

  std::map<int, std::vector<double> > *dataPV1 = NULL;
  std::map<int, std::vector<double> > *dataPV2 = NULL;
  std::stringstream name1, name2;
  if (_numPView == 1 &&
      ((_computeMetric && !_1PViewR) || (!_computeMetric && !_1PViewJ))) {
    dataPV1 = new std::map<int, std::vector<double> >();
    if (_computeMetric) {
      name1 << "min R";
      _1PViewR = true;
    }
    else {
      name1 << "min J";
      _1PViewJ = true;
    }
    for (unsigned int i = 0; i < _data.size(); ++i) {
      MElement *const el = _data[i].element();
      if (el->getDim() == _dim) {
        double val = _computeMetric ? _data[i].minR() : _data[i].minJ();
        (*dataPV1)[el->getNum()].push_back(val);
      }
    }
  }
  else if (_numPView == 2 &&
      ((_computeMetric && !_2PViewR) || (!_computeMetric && !_2PViewJ))) {
    dataPV1 = new std::map<int, std::vector<double> >();
    dataPV2 = new std::map<int, std::vector<double> >();
    if (_computeMetric) {
      name1 << "min R straight";
      name2 << "min R curved";
      _2PViewR = true;
    }
    else {
      name1 << "min J straight";
      name2 << "min J curved";
      _2PViewJ = true;
    }
    for (unsigned int i = 0; i < _data.size(); ++i) {
      MElement *const el = _data[i].element();
      if (el->getDim() == _dim) {
        double val = _computeMetric ? _data[i].minR() : _data[i].minJ();
        if (_data[i].maxJ() - _data[i].minJ() < _tol * 1e-1)
          (*dataPV1)[el->getNum()].push_back(val);
        else
          (*dataPV2)[el->getNum()].push_back(val);
      }
    }
  }

  if (dataPV1) new PView(name1.str().c_str(), "ElementData", _m, *dataPV1);
  if (dataPV2) new PView(name2.str().c_str(), "ElementData", _m, *dataPV2);

  //

#if defined(HAVE_OPENGL)
  if (_hideWithThreshold() && _msgHide) {
    _msgHide = false;
    Msg::Info("Note: Some elements have been hidden (param 'Hidding Threshold').");
    Msg::Info("      (To revert visibility : Tools > Visibility > Interactive > Show All)");
  }
  CTX::instance()->mesh.changed = (ENT_ALL);
  drawContext::global()->draw();
#endif

  return 0;
}

void GMSH_AnalyseCurvedMeshPlugin::_computeMinMaxJandValidity()
{
  switch (_dim) {
    case 3 :
      if (_computedJ3D) break;
      for (GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);

        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          _computeMinMaxJandValidity(el, numType[type]);
        }
      }
      _computedJ3D = true;
      break;

    case 2 :
      if (_computedJ2D) break;
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);

        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          _computeMinMaxJandValidity(el, numType[type]);
        }
      }
      _computedJ2D = true;
      break;

    case 1 :
      if (_computedJ1D) break;
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        _computeMinMaxJandValidity(el, numElement);
      }
      _computedJ1D = true;
      break;

    default :
      Msg::Error("I can not analyse any element.");
      return;
  }
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

  _data.reserve(_data.size() + numEl);

  const int numSamplingPt = jfs->getNumJacNodes();
  const int numMapNodes = jfs->getNumMapNodes();
  fullVector<double> jacobian(numSamplingPt);
  fullVector<double> jacBez(numSamplingPt);
  fullVector<double> subJacBez(jfs->getNumSubNodes());

  for (int k = 0; k < numEl; ++k) {
    fullMatrix<double> nodesXYZ(numMapNodes,3);
    el[k]->getNodesCoord(nodesXYZ);
    jfs->getScaledJacobian(nodesXYZ,jacobian);
    jfs->lag2Bez(jacobian, jacBez);

    BezierJacobian *bj = new BezierJacobian(jacBez, jfs, 0);
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

      for (int i = 0; i < jfs->getNumDivisions(); i++) {
        jacBez.setAsProxy(subJacBez, i * numSamplingPt, numSamplingPt);
        BezierJacobian *newbj = new BezierJacobian(jacBez, jfs, currentDepth);
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

      for (int i = 0; i < jfs->getNumDivisions(); i++) {
        jacBez.setAsProxy(subJacBez, i * numSamplingPt, numSamplingPt);
        BezierJacobian *newbj = new BezierJacobian(jacBez, jfs, currentDepth);
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

void GMSH_AnalyseCurvedMeshPlugin::_computeMinR()
{
  if (_dim == 1 ||
      (_dim == 2 && _computedR2D) ||
      (_dim == 3 && _computedR3D)) {
    return;
  }

  MetricBasis::setTol(_tol);

  double initial, time = initial = Cpu();
  unsigned int percentage = 0, nextCheck = 0;

  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    if (el->getDim() == _dim) {
      if (_data[i].minJ() <= 0)
        _data[i].setMinR(0);
      else if (_data[i].maxJ() - _data[i].minJ() < _tol * 1e-2)
        _data[i].setMinR(MetricBasis::sampleR(el, 0));
      else
        _data[i].setMinR(MetricBasis::boundMinR(el));
    }
    if (i >= nextCheck) {
      nextCheck += _data.size() / 100;
      if (Cpu() - time > 10. && i*100/_data.size() > percentage + 4) {
        percentage = i*100/_data.size();
        time = Cpu();
        Msg::StatusBar(true, "%d%% (remaining time ~%g secondes)",
            percentage, (Cpu()-initial) / (i+1) * (_data.size() - i-1));
      }
    }
  }

  if (_dim == 2) _computedR2D = true;
  if (_dim == 3) _computedR3D = true;
}

bool GMSH_AnalyseCurvedMeshPlugin::_hideWithThreshold()
{
  if (_threshold >= 1.) return false;

  bool ans = false;
  for (unsigned int i = 0; i < _data.size(); ++i) {
    MElement *const el = _data[i].element();
    if (el->getDim() == _dim) {
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
    Msg::Info("No stat to print...");
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
    Msg::Info("No stat to print...");
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
    const JacobianBasis *jfs, int depth)
{
  _jacBez = v;
  _depthSub = depth;
  _jfs = jfs;

  _minL = _maxL = v(0);
  int i = 1;
  for (; i < jfs->getNumLagCoeff(); i++) {
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
