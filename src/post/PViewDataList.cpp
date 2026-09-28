// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstring>
#include <unordered_map>
#include "PView.h"
#include "PViewDataList.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "BasisFactory.h"
#include "Numeric.h"
#include "Context.h"
#include "polynomialBasis.h"
#include "OS.h"

// a number for a state of the lists of a view, none of which has another
static std::size_t newState()
{
  static std::atomic<std::size_t> last(0);
  return ++last;
}

const PViewDataList::listKind PViewDataList::listKinds[27] = {
  {"SP", TYPE_PNT, 0, 1, 0, 1, &PViewDataList::_sp, &PViewDataList::_nbSP},
  {"VP", TYPE_PNT, 0, 1, 0, 3, &PViewDataList::_vp, &PViewDataList::_nbVP},
  {"TP", TYPE_PNT, 0, 1, 0, 9, &PViewDataList::_tp, &PViewDataList::_nbTP},
  {"SL", TYPE_LIN, 1, 2, 1, 1, &PViewDataList::_sl, &PViewDataList::_nbSL},
  {"VL", TYPE_LIN, 1, 2, 1, 3, &PViewDataList::_vl, &PViewDataList::_nbVL},
  {"TL", TYPE_LIN, 1, 2, 1, 9, &PViewDataList::_tl, &PViewDataList::_nbTL},
  {"ST", TYPE_TRI, 2, 3, 3, 1, &PViewDataList::_st, &PViewDataList::_nbST},
  {"VT", TYPE_TRI, 2, 3, 3, 3, &PViewDataList::_vt, &PViewDataList::_nbVT},
  {"TT", TYPE_TRI, 2, 3, 3, 9, &PViewDataList::_tt, &PViewDataList::_nbTT},
  {"SQ", TYPE_QUA, 2, 4, 4, 1, &PViewDataList::_sq, &PViewDataList::_nbSQ},
  {"VQ", TYPE_QUA, 2, 4, 4, 3, &PViewDataList::_vq, &PViewDataList::_nbVQ},
  {"TQ", TYPE_QUA, 2, 4, 4, 9, &PViewDataList::_tq, &PViewDataList::_nbTQ},
  {"SS", TYPE_TET, 3, 4, 6, 1, &PViewDataList::_ss, &PViewDataList::_nbSS},
  {"VS", TYPE_TET, 3, 4, 6, 3, &PViewDataList::_vs, &PViewDataList::_nbVS},
  {"TS", TYPE_TET, 3, 4, 6, 9, &PViewDataList::_ts, &PViewDataList::_nbTS},
  {"SH", TYPE_HEX, 3, 8, 12, 1, &PViewDataList::_sh, &PViewDataList::_nbSH},
  {"VH", TYPE_HEX, 3, 8, 12, 3, &PViewDataList::_vh, &PViewDataList::_nbVH},
  {"TH", TYPE_HEX, 3, 8, 12, 9, &PViewDataList::_th, &PViewDataList::_nbTH},
  {"SI", TYPE_PRI, 3, 6, 9, 1, &PViewDataList::_si, &PViewDataList::_nbSI},
  {"VI", TYPE_PRI, 3, 6, 9, 3, &PViewDataList::_vi, &PViewDataList::_nbVI},
  {"TI", TYPE_PRI, 3, 6, 9, 9, &PViewDataList::_ti, &PViewDataList::_nbTI},
  {"SY", TYPE_PYR, 3, 5, 8, 1, &PViewDataList::_sy, &PViewDataList::_nbSY},
  {"VY", TYPE_PYR, 3, 5, 8, 3, &PViewDataList::_vy, &PViewDataList::_nbVY},
  {"TY", TYPE_PYR, 3, 5, 8, 9, &PViewDataList::_ty, &PViewDataList::_nbTY},
  {"SR", TYPE_TRIH, 3, 4, 5, 1, &PViewDataList::_sr, &PViewDataList::_nbSR},
  {"VR", TYPE_TRIH, 3, 4, 5, 3, &PViewDataList::_vr, &PViewDataList::_nbVR},
  {"TR", TYPE_TRIH, 3, 4, 5, 9, &PViewDataList::_tr, &PViewDataList::_nbTR},
};

PViewDataList::PViewDataList(bool isAdapted)
  : PViewData(), _nbTimeStep(0), _min(VAL_INF), _max(-VAL_INF), _nbT2(0),
    _nbT3(0), _nodeIndexStatus(0), _state(newState()), _isAdapted(isAdapted),
    _smoothing(false)
{
  for(auto &k : listKinds) this->*k.num = 0;
  for(int i = 0; i < 27; i++) _index[i] = 0;
}

void PViewDataList::setXY(std::vector<double> &x, std::vector<double> &y)
{
  _nbSP = 0;
  _sp.clear();
  for(std::size_t i = 0; i < std::min(x.size(), y.size()); i++) {
    _sp.push_back(x[i]);
    _sp.push_back(0.);
    _sp.push_back(0.);
    _sp.push_back(y[i]);
    _nbSP++;
  }
  finalize();
}

void PViewDataList::setXYZV(std::vector<double> &x, std::vector<double> &y,
                            std::vector<double> &z, std::vector<double> &v)
{
  _nbSP = 0;
  _sp.clear();
  int n = std::min(std::min(std::min(x.size(), y.size()), z.size()), v.size());
  for(int i = 0; i < n; i++) {
    _sp.push_back(x[i]);
    _sp.push_back(y[i]);
    _sp.push_back(z[i]);
    _sp.push_back(v[i]);
    _nbSP++;
  }
  finalize();
}

void PViewDataList::addStep(std::vector<double> &y)
{
  if(_nbSP != (int)y.size()) {
    Msg::Error("Wrong number of values while adding step in list-based view");
    return;
  }
  // (each point gets its value of the new step after those it has)
  std::vector<double> tmp;
  tmp.reserve(_sp.size() + _nbSP);
  int stride = _sp.size() / _nbSP;
  for(int i = 0; i < _nbSP; i++) {
    for(int j = 0; j < stride; j++) tmp.push_back(_sp[i * stride + j]);
    tmp.push_back(y[i]);
  }
  _sp = tmp;
  finalize();
}

bool PViewDataList::finalize(bool computeMinMax,
                             const std::string &interpolationScheme)
{
  _skinMasks.clear(); // (whoever knows them gives them again)
  // what the threads last read comes from lists that may have changed
  _state = newState();
  // the lists may have changed: the nodes recreated from them are not theirs
  // any more
  _nodeIndexStatus = 0;
  _nodeId.clear();
  _nodeOffset.clear();

  _bbox.reset();
  _min = VAL_INF;
  _max = -VAL_INF;

  // finalize text strings first, to get the max value of _nbTimeStep
  // for strings-only views (strings are designed to degrade
  // gracefully when some have fewer time steps than others). If there
  // are any elements in the view, this value will be replaced by the
  // minimum number of time steps common to all elements.
  _stat(_t2d, _t2c, 4);
  _stat(_t3d, _t3c, 5);

  // compute min/max and other statistics for all element lists
  for(auto &k : listKinds)
    _stat(this->*k.list, k.numComp, this->*k.num, k.numNodes, k.type);

  // add dummy time values if none (or too few) time values are
  // provided (e.g. using the old parsed format)
  if((int)_time.size() < _nbTimeStep) {
    for(int i = _time.size(); i < _nbTimeStep; i++) _time.push_back(i);
  }

  // compute starting element indices
  for(int i = 0; i < 27; i++)
    _index[i] = (i ? _index[i - 1] : 0) + this->*listKinds[i].num;

  if(CTX::instance()->post.smooth && !_smoothing) smooth();

  return PViewData::finalize();
}

int PViewDataList::getNumScalars(int step)
{
  int n = 0;
  for(auto &k : listKinds)
    if(k.numComp == 1) n += this->*k.num;
  return n;
}

int PViewDataList::getNumVectors(int step)
{
  int n = 0;
  for(auto &k : listKinds)
    if(k.numComp == 3) n += this->*k.num;
  return n;
}

int PViewDataList::getNumTensors(int step)
{
  int n = 0;
  for(auto &k : listKinds)
    if(k.numComp == 9) n += this->*k.num;
  return n;
}

int PViewDataList::getNumElements(int step, int ent)
{
  int n = 0;
  for(auto &k : listKinds) n += this->*k.num;
  return n;
}

double PViewDataList::getTime(int step)
{
  if(step < 0 || step >= (int)_time.size()) return 0.;
  return _time[step];
}

double PViewDataList::getMin(int step, bool onlyVisible, int tensorRep,
                             int forceNumComponents, int componentMap[9])
{
  if(step >= (int)_timeStepMin.size()) return _min;

  if(forceNumComponents || tensorRep) {
    double vmin = VAL_INF;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double val;
          getScalarValue(step, ent, ele, nod, val, tensorRep,
                         forceNumComponents, componentMap);
          vmin = std::min(vmin, val);
        }
      }
    }
    return vmin;
  }

  if(step < 0) return _min;
  return _timeStepMin[step];
}

double PViewDataList::getMax(int step, bool onlyVisible, int tensorRep,
                             int forceNumComponents, int componentMap[9])
{
  if(step >= (int)_timeStepMax.size()) return _max;

  if(forceNumComponents || tensorRep) {
    double vmax = -VAL_INF;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double val;
          getScalarValue(step, ent, ele, nod, val, tensorRep,
                         forceNumComponents, componentMap);
          vmax = std::max(vmax, val);
        }
      }
    }
    return vmax;
  }

  if(step < 0) return _max;
  return _timeStepMax[step];
}

void PViewDataList::_stat(std::vector<double> &D, std::vector<char> &C, int nb)
{
  // compute statistics for text lists
  for(std::size_t i = 0; i < D.size(); i += nb) {
    std::size_t beg, end;
    _stringSpan(D, C, i, nb, beg, end);
    int nbtime = 0;
    for(std::size_t j = beg; j < end; j++)
      if(C[j] == '\0') nbtime++;
    if(nbtime > _nbTimeStep) _nbTimeStep = nbtime;
  }
  if(nb == 5) {
    for(std::size_t i = 0; i < D.size(); i += nb)
      _bbox += SPoint3(D[i], D[i + 1], D[i + 2]);
  }
}

void PViewDataList::_stat(std::vector<double> &list, int nbcomp, int nbelm,
                          int nbnod, int type)
{
  // compute statistics for element lists
  if(!nbelm) return;

  int nbval = nbcomp * nbnod;

  if(haveInterpolationMatrices()) {
    std::vector<fullMatrix<double> *> im;
    int nim = getInterpolationMatrices(type, im);
    if(nim == 4) nbnod = im[2]->size1();
    if(nim) nbval = nbcomp * im[0]->size1();
  }

  // all the elements of a list have the same size: as many steps each
  int nb = list.size() / nbelm;
  int N = nb - 3 * nbnod;
  int numSteps = N / nbval;
  if(_min == VAL_INF || _max == -VAL_INF) {
    _nbTimeStep = numSteps;
    _timeStepMin.assign(_nbTimeStep, VAL_INF);
    _timeStepMax.assign(_nbTimeStep, -VAL_INF);
  }
  else if(numSteps < _nbTimeStep) {
    // if some elts have less steps, reduce the total number!
    _nbTimeStep = numSteps;
  }

  // the bounding box and the range of each step, found by each thread for its
  // share of the elements (a view with millions of elements spends its time
  // here), then put together
  int nthreads = CTX::instance()->numThreadsFor(nbelm, 100000);
  int numRanges = (N + nbval - 1) / nbval; // (the last one may be partial)
  std::vector<SBoundingBox3d> bbox(nthreads);
  std::vector<std::vector<double> > min(nthreads), max(nthreads);
#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    min[t].assign(numRanges, VAL_INF);
    max[t].assign(numRanges, -VAL_INF);
    int tensorRep = 0; // Von-Mises: we could/should be able to choose this
    for(int ele = (int)((std::size_t)nbelm * t / nthreads);
        ele < (int)((std::size_t)nbelm * (t + 1) / nthreads); ele++) {
      double *X = &list[(std::size_t)ele * nb];
      double *Y = X + nbnod, *Z = X + 2 * nbnod, *V = X + 3 * nbnod;
      for(int j = 0; j < nbnod; j++) bbox[t] += SPoint3(X[j], Y[j], Z[j]);
      for(int ts = 0; ts < numRanges; ts++) {
        double &mi = min[t][ts], &ma = max[t][ts];
        for(int j = ts * nbval; j < std::min((ts + 1) * nbval, N); j += nbcomp) {
          double l0 =
            (nbcomp == 1) ? V[j] : ComputeScalarRep(nbcomp, &V[j], tensorRep);
          mi = std::min(l0, mi);
          ma = std::max(l0, ma);
        }
      }
    }
  }
  for(int t = 0; t < nthreads; t++) {
    if(!bbox[t].empty()) _bbox += bbox[t];
    for(int ts = 0; ts < numRanges; ts++) {
      _min = std::min(min[t][ts], _min);
      _max = std::max(max[t][ts], _max);
      if(ts < _nbTimeStep) { // security
        _timeStepMin[ts] = std::min(min[t][ts], _timeStepMin[ts]);
        _timeStepMax[ts] = std::max(max[t][ts], _timeStepMax[ts]);
      }
    }
  }
}

void PViewDataList::_setLast(lastElement &l, int ele)
{
  l.state = _state;
  l.ele = ele;
  // the list of the element: the first whose elements end after it
  int k = std::upper_bound(_index, _index + 27, ele) - _index;
  if(k >= 27) { // (no such element)
    l = lastElement();
    l.state = _state;
    l.ele = ele;
    return;
  }
  const listKind &kind = listKinds[k];
  std::vector<double> &list = this->*kind.list;
  int i = ele - (k ? _index[k - 1] : 0), nbnod = kind.numNodes;
  // (with interpolation matrices: as many values as functions, and with 4 of
  // them as many nodes as geometric functions)
  auto im = _interpolation.find(kind.type);
  if(im != _interpolation.end() && im->second.size() == 4)
    nbnod = im->second[2]->size1();
  l.dim = kind.dim;
  l.numNodes = nbnod;
  l.numComponents = kind.numComp;
  l.numEdges = kind.numEdges;
  l.type = kind.type;
  // the numbers of coordinates and values of an element, and before it; the
  // values of a step, unless the element has fewer (lists may have more
  // steps than the view)
  std::size_t nb = list.size() / (this->*kind.num),
              before = (std::size_t)i * nb;
  int numValues =
    kind.numComp * ((im != _interpolation.end() && im->second.size()) ?
                      im->second[0]->size1() :
                      nbnod);
  if(numValues * _nbTimeStep > (int)(nb - 3 * nbnod))
    numValues = (int)((nb - 3 * nbnod) / _nbTimeStep);
  l.numValues = numValues;
  l.xyz = &list[before];
  l.val = &list[before + 3 * l.numNodes];
}

thread_local PViewDataList::lastElement PViewDataList::_lastRead[4];

int PViewDataList::getDimension(int step, int ent, int ele)
{
  lastElement &l = _last(ele);
  return l.dim;
}

int PViewDataList::getNumNodes(int step, int ent, int ele)
{
  lastElement &l = _last(ele);
  return l.numNodes;
}

// list-based data has no topology: recreate one by merging the nodes with
// the same coordinates, cached
namespace {
  struct NodeKey {
    double x, y, z;
  };
  struct NodeKeyHash {
    std::size_t operator()(const NodeKey &k) const
    {
      const unsigned char *p = (const unsigned char *)&k;
      std::size_t h = 14695981039346656037ULL;
      for(std::size_t i = 0; i < sizeof(NodeKey); i++) {
        h ^= p[i];
        h *= 1099511628211ULL;
      }
      return h;
    }
  };
  struct NodeKeyEqual {
    bool operator()(const NodeKey &a, const NodeKey &b) const
    {
      return !memcmp(&a, &b, sizeof(NodeKey));
    }
  };
} // namespace

void PViewDataList::_buildNodeIndex()
{
  if(_nodeIndexStatus) return;

  int numEle = getNumElements(0, 0);
  if(numEle <= 0) {
    _nodeIndexStatus = -1;
    return;
  }

  double t1 = TimeOfDay();

  // one identifier per (element, node): bail out instead of allocating an
  // unreasonable amount of memory on very large list-based views
  const std::size_t maxNodes = 100000000;
  std::size_t total = 0;
  _nodeOffset.resize(numEle + 1);
  _nodeOffset[0] = 0;
  for(int i = 0; i < numEle; i++) {
    total += getNumNodes(0, 0, i);
    if(total > maxNodes) {
      Msg::Info("Too many list-based nodes (> %lu) to recreate a topology",
                (unsigned long)maxNodes);
      _nodeOffset.clear();
      _nodeIndexStatus = -1;
      return;
    }
    _nodeOffset[i + 1] = (unsigned int)total;
  }

  _nodeId.resize(total);
  std::unordered_map<NodeKey, unsigned int, NodeKeyHash, NodeKeyEqual> map;
  map.reserve(total / 4 + 1);
  unsigned int next = 0;
  for(int i = 0; i < numEle; i++) {
    int n = getNumNodes(0, 0, i);
    for(int j = 0; j < n; j++) {
      NodeKey k;
      getNode(0, 0, i, j, k.x, k.y, k.z);
      auto it = map.find(k);
      if(it == map.end()) {
        map[k] = next;
        _nodeId[_nodeOffset[i] + j] = next++;
      }
      else
        _nodeId[_nodeOffset[i] + j] = it->second;
    }
  }

  _nodeIndexStatus = 1;
  Msg::Debug("Recreated %u nodes out of %lu list-based coordinates in %g s",
             next, (unsigned long)total, TimeOfDay() - t1);
}

std::size_t PViewDataList::getNodeId(int step, int ent, int ele, int nod)
{
  if(!_nodeIndexStatus) {
    // (by the first thread that asks)
#pragma omp critical(PViewDataList_buildNodeIndex)
    _buildNodeIndex();
  }
  if(_nodeIndexStatus != 1) return 0;
  if(ele < 0 || ele + 1 >= (int)_nodeOffset.size()) return 0;
  std::size_t k = (std::size_t)_nodeOffset[ele] + nod;
  if(k >= _nodeId.size()) return 0;
  // 0 means "no topology", so shift the identifiers by one
  return (std::size_t)_nodeId[k] + 1;
}

int PViewDataList::getNode(int step, int ent, int ele, int nod, double &x,
                           double &y, double &z)
{
  lastElement &l = _last(ele);
  x = l.xyz[nod];
  y = l.xyz[l.numNodes + nod];
  z = l.xyz[2 * l.numNodes + nod];
  return 0;
}

void PViewDataList::getNodesAndValues(int step, int ent, int ele, int numNodes,
                                      int numComp, double **xyz, double **val)
{
  lastElement &l = _last(ele);
  if(step >= _nbTimeStep) step = 0;
  const double *v = l.val + step * l.numValues;
  for(int j = 0; j < numNodes; j++) {
    xyz[j][0] = l.xyz[j];
    xyz[j][1] = l.xyz[l.numNodes + j];
    xyz[j][2] = l.xyz[2 * l.numNodes + j];
    for(int k = 0; k < numComp; k++) val[j][k] = v[j * l.numComponents + k];
  }
}

void PViewDataList::setNode(int step, int ent, int ele, int nod, double x,
                            double y, double z)
{
  if(step) return;
  // the coordinates change: the recreated topology is no longer valid
  _nodeIndexStatus = 0;
  _nodeId.clear();
  _nodeOffset.clear();
  lastElement &l = _last(ele);
  l.xyz[nod] = x;
  l.xyz[l.numNodes + nod] = y;
  l.xyz[2 * l.numNodes + nod] = z;
}

int PViewDataList::getNumComponents(int step, int ent, int ele)
{
  lastElement &l = _last(ele);
  return l.numComponents;
}

int PViewDataList::getNumValues(int step, int ent, int ele)
{
  lastElement &l = _last(ele);
  return l.numValues;
}

void PViewDataList::getValue(int step, int ent, int ele, int idx, double &val)
{
  lastElement &l = _last(ele);
  if(step >= _nbTimeStep) step = 0;
  val = l.val[step * l.numValues + idx];
}

void PViewDataList::getValue(int step, int ent, int ele, int nod, int comp,
                             double &val)
{
  lastElement &l = _last(ele);
  if(step >= _nbTimeStep) step = 0;
  val = l.val[step * l.numValues + nod * l.numComponents + comp];
}

void PViewDataList::setValue(int step, int ent, int ele, int nod, int comp,
                             double val)
{
  lastElement &l = _last(ele);
  if(step >= _nbTimeStep) step = 0;
  l.val[step * l.numValues + nod * l.numComponents + comp] = val;
}

int PViewDataList::getNumEdges(int step, int ent, int ele)
{
  lastElement &l = _last(ele);
  return l.numEdges;
}

int PViewDataList::getType(int step, int ent, int ele)
{
  lastElement &l = _last(ele);
  return l.type;
}

void PViewDataList::_getString(int dim, int i, int step, std::string &str,
                               double &x, double &y, double &z, double &style)
{
  // 3D: _t3d is a list of double: x,y,z,style,index,x,y,z,style,index,...
  //     _t3c is a list of chars: string\0,string\0,string\0,string\0,...
  //     Parser format is: T3(x,y,z,style){"str","str",...};
  // 2D: _t2d is a list of double: x,y,style,index,x,y,style,index,...
  //     _t2c is a list of chars: string\0,string\0,string\0,string\0,...
  //     Parser format is: T2(x,y,style){"str","str",...};

  std::vector<double> &td = (dim == 2) ? _t2d : _t3d;
  std::vector<char> &tc = (dim == 2) ? _t2c : _t3c;
  int nbd = (dim == 2) ? 4 : 5;

  int index, nbchar;
  double *d1 = &td[i * nbd];
  double *d2 = ((i + 1) * nbd < (int)td.size()) ? &td[(i + 1) * nbd] : nullptr;

  if(dim == 2) {
    x = d1[0];
    y = d1[1];
    z = 0.;
    style = d1[2];
    index = (int)d1[3];
    if(d2)
      nbchar = (int)d2[3] - index;
    else
      nbchar = tc.size() - index;
  }
  else {
    x = d1[0];
    y = d1[1];
    z = d1[2];
    style = d1[3];
    index = (int)d1[4];
    if(d2)
      nbchar = (int)d2[4] - index;
    else
      nbchar = tc.size() - index;
  }

  char *c = &tc[index];
  int k = 0, l = 0;
  while(k < nbchar && l != step) {
    if(c[k++] == '\0') l++;
  }
  if(k < nbchar && l == step)
    str = std::string(&c[k]);
  else
    str = std::string(c);
}

void PViewDataList::getString2D(int i, int step, std::string &str, double &x,
                                double &y, double &style)
{
  double z;
  _getString(2, i, step, str, x, y, z, style);
}

void PViewDataList::getString3D(int i, int step, std::string &str, double &x,
                                double &y, double &z, double &style)
{
  _getString(3, i, step, str, x, y, z, style);
}

void PViewDataList::reverseElement(int step, int ent, int ele)
{
  if(step) return;
  lastElement &l = _last(ele);

  // copy data
  std::vector<double> XYZ(3 * l.numNodes);
  for(std::size_t i = 0; i < XYZ.size(); i++) XYZ[i] = l.xyz[i];

  std::vector<double> V(l.numValues * getNumTimeSteps());
  for(std::size_t i = 0; i < V.size(); i++) V[i] = l.val[i];

  // reverse node order
  for(int i = 0; i < l.numNodes; i++) {
    l.xyz[i] = XYZ[l.numNodes - i - 1];
    l.xyz[l.numNodes + i] = XYZ[2 * l.numNodes - i - 1];
    l.xyz[2 * l.numNodes + i] = XYZ[3 * l.numNodes - i - 1];
  }

  for(int step = 0; step < getNumTimeSteps(); step++)
    for(int i = 0; i < l.numNodes; i++)
      for(int k = 0; k < l.numComponents; k++)
        l.val[l.numValues * step + l.numComponents * i + k] =
          V[l.numValues * step + l.numComponents * (l.numNodes - i - 1) + k];
}

void PViewDataList::smooth()
{
  // the nodes of all the elements (but points), in the order of the lists
  struct node {
    double *v; // the values of the first step
    int stride, n; // between steps, and per step
  };
  std::vector<node> nodes;
  std::vector<double> xyz;
  std::vector<double> *list = nullptr;
  int *nbe = nullptr, nbc, nbn;
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    if(nbn < 2 || !*nbe) continue;
    std::size_t nb = list->size() / *nbe;
    for(std::size_t e = 0; e < list->size(); e += nb) {
      double *x = &(*list)[e], *y = x + nbn, *z = y + nbn, *v = z + nbn;
      for(int j = 0; j < nbn; j++) {
        nodes.push_back({v + nbc * j, nbn * nbc, nbc});
        xyz.insert(xyz.end(), {x[j], y[j], z[j]});
      }
    }
  }

  // the nodes at the same place (within eps), together, in the order of the
  // lists: their values are averaged in that order, as they always were
  std::size_t num = 0;
  std::vector<std::size_t> merged =
    _mergePoints(xyz, CTX::instance()->lc * 1.e-8, num);
  std::vector<std::size_t> first(num + 1, 0), order(nodes.size());
  for(auto m : merged) first[m + 1]++;
  for(std::size_t m = 0; m < num; m++) first[m + 1] += first[m];
  std::vector<std::size_t> next(first.begin(), first.end() - 1);
  for(std::size_t k = 0; k < nodes.size(); k++) order[next[merged[k]]++] = k;

  int numSteps = _nbTimeStep;
  std::vector<double> mean;
  for(std::size_t m = 0; m < num; m++) {
    std::size_t beg = first[m], end = first[m + 1];
    if(end - beg < 2) continue;
    // the running mean of the nodes with as many values as the first
    int n = nodes[order[beg]].n, count = 0;
    mean.assign(n * numSteps, 0.);
    for(std::size_t k = beg; k < end; k++) {
      const node &p = nodes[order[k]];
      if(p.n != n) continue;
      double x1 = (double)count / (double)(count + 1);
      double x2 = 1. / (double)(count + 1);
      for(int ts = 0; ts < numSteps; ts++)
        for(int c = 0; c < n; c++)
          mean[n * ts + c] =
            x1 * mean[n * ts + c] + x2 * p.v[p.stride * ts + c];
      count++;
    }
    for(std::size_t k = beg; k < end; k++) {
      const node &p = nodes[order[k]];
      if(p.n != n) continue;
      for(int ts = 0; ts < numSteps; ts++)
        for(int c = 0; c < n; c++) p.v[p.stride * ts + c] = mean[n * ts + c];
    }
  }
  _smoothing = true;
  finalize();
  _smoothing = false;
}

double PViewDataList::getMemoryInMB()
{
  double b = 0.;
  b +=
    (_timeStepMin.size() + _timeStepMax.size() + _time.size()) * sizeof(double);
  b += (_sp.size() + _vp.size() + _tp.size()) * sizeof(double);
  b += (_sl.size() + _vl.size() + _tl.size()) * sizeof(double);
  b += (_st.size() + _vt.size() + _tt.size()) * sizeof(double);
  b += (_sq.size() + _vq.size() + _tq.size()) * sizeof(double);
  b += (_ss.size() + _vs.size() + _ts.size()) * sizeof(double);
  b += (_sh.size() + _vh.size() + _th.size()) * sizeof(double);
  b += (_si.size() + _vi.size() + _ti.size()) * sizeof(double);
  b += (_sy.size() + _vy.size() + _ty.size()) * sizeof(double);
  b += (_sr.size() + _vr.size() + _tr.size()) * sizeof(double);
  b += (_t2d.size() + _t3d.size()) * sizeof(double);
  return b / 1024. / 1024.;
}

static void dVecMerge(std::vector<double> &v, std::vector<double> &dest)
{
  for(std::size_t i = 0; i < v.size(); i++) dest.push_back(v[i]);
}

bool PViewDataList::combineSpace(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  int ts = nd.data[0]->getNumTimeSteps();
  for(std::size_t i = 1; i < nd.data.size(); i++) {
    if(!nd.data[i]->empty() && nd.data[i]->getNumTimeSteps() != ts) {
      Msg::Error("Cannot combine views having different number of time steps");
      return false;
    }
  }

  for(std::size_t i = 0; i < nd.data.size(); i++) {
    PViewDataList *l = dynamic_cast<PViewDataList *>(nd.data[i]);
    if(!l) {
      Msg::Error("Cannot combine hybrid data");
      return false;
    }

    // copy interpolation matrices
    for(auto it = l->_interpolation.begin(); it != l->_interpolation.end();
        it++)
      if(_interpolation[it->first].empty())
        for(std::size_t i = 0; i < it->second.size(); i++)
          _interpolation[it->first].push_back(
            new fullMatrix<double>(*it->second[i]));

    // copy time values

    if(!i) _time = l->_time;

    // merge elements
    for(auto &k : listKinds) {
      dVecMerge(l->*k.list, this->*k.list);
      this->*k.num += l->*k.num;
    }

    // merge strings
    for(std::size_t i = 0; i < l->_t2d.size(); i += 4) {
      _t2d.push_back(l->_t2d[i]);
      _t2d.push_back(l->_t2d[i + 1]);
      _t2d.push_back(l->_t2d[i + 2]);
      _t2d.push_back(_t2c.size());
      std::size_t beg, end;
      _stringSpan(l->_t2d, l->_t2c, i, 4, beg, end);
      _t2c.insert(_t2c.end(), l->_t2c.begin() + beg, l->_t2c.begin() + end);
      _nbT2++;
    }
    for(std::size_t i = 0; i < l->_t3d.size(); i += 5) {
      _t3d.push_back(l->_t3d[i]);
      _t3d.push_back(l->_t3d[i + 1]);
      _t3d.push_back(l->_t3d[i + 2]);
      _t3d.push_back(l->_t3d[i + 3]);
      _t3d.push_back(_t3c.size());
      std::size_t beg, end;
      _stringSpan(l->_t3d, l->_t3c, i, 5, beg, end);
      _t3c.insert(_t3c.end(), l->_t3c.begin() + beg, l->_t3c.begin() + end);
      _nbT3++;
    }
  }

  std::string tmp;
  if(nd.name == "__all__")
    tmp = "all";
  else if(nd.name == "__vis__")
    tmp = "visible";
  else
    tmp = nd.name;
  char name[256];
  sprintf(name, "%s_Combine", tmp.c_str());
  setName(name);
  setFileName(std::string(name) + ".pos");

  return finalize();
}

bool PViewDataList::combineTime(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  std::vector<PViewDataList *> data(nd.data.size());
  for(std::size_t i = 0; i < nd.data.size(); i++) {
    data[i] = dynamic_cast<PViewDataList *>(nd.data[i]);
    if(!data[i]) {
      Msg::Error("Cannot combine hybrid data");
      return false;
    }
  }

  int *nbe = nullptr, *nbe2 = nullptr, nbn, nbn2, nbc, nbc2;
  std::vector<double> *list = nullptr, *list2 = nullptr;

  // use the first data set as the reference
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    data[0]->_getRawData(i, &list2, &nbe2, &nbc2, &nbn2);
    *nbe = *nbe2;
  }
  _nbT2 = data[0]->_nbT2;
  _nbT3 = data[0]->_nbT3;
  for(auto it = data[0]->_interpolation.begin();
      it != data[0]->_interpolation.end(); it++)
    if(_interpolation[it->first].empty())
      for(std::size_t i = 0; i < it->second.size(); i++)
        _interpolation[it->first].push_back(
          new fullMatrix<double>(*it->second[i]));

  // merge values for all element types
  for(int i = 0; i < 27; i++) {
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    for(int j = 0; j < *nbe; j++) {
      for(std::size_t k = 0; k < data.size(); k++) {
        data[k]->_getRawData(i, &list2, &nbe2, &nbc2, &nbn2);
        if(*nbe && *nbe == *nbe2) {
          int nb2 = list2->size() / *nbe2;
          if(!k) {
            // copy coordinates of elm j (we are always here as
            // expected, since the ref view is the first one)
            for(int l = 0; l < 3 * nbn2; l++)
              list->push_back((*list2)[j * nb2 + l]);
          }
          // copy values of elm j
          for(int l = 0; l < nb2 - 3 * nbn2; l++)
            list->push_back((*list2)[j * nb2 + 3 * nbn2 + l]);
        }
      }
    }
  }

  // merge 2d strings
  for(int j = 0; j < _nbT2; j++) {
    for(std::size_t k = 0; k < data.size(); k++) {
      if(_nbT2 == data[k]->_nbT2) {
        if(!k) {
          // copy coordinates
          _t2d.push_back(data[k]->_t2d[j * 4]);
          _t2d.push_back(data[k]->_t2d[j * 4 + 1]);
          _t2d.push_back(data[k]->_t2d[j * 4 + 2]);
          // index
          _t2d.push_back(_t2c.size());
        }
        // copy char values
        std::size_t beg, end;
        _stringSpan(data[k]->_t2d, data[k]->_t2c, j * 4, 4, beg, end);
        _t2c.insert(_t2c.end(), data[k]->_t2c.begin() + beg,
                    data[k]->_t2c.begin() + end);
      }
    }
  }

  // merge 3d strings
  for(int j = 0; j < _nbT3; j++) {
    for(std::size_t k = 0; k < data.size(); k++) {
      if(_nbT3 == data[k]->_nbT3) {
        if(!k) {
          // copy coordinates
          _t3d.push_back(data[k]->_t3d[j * 5]);
          _t3d.push_back(data[k]->_t3d[j * 5 + 1]);
          _t3d.push_back(data[k]->_t3d[j * 5 + 2]);
          _t3d.push_back(data[k]->_t3d[j * 5 + 3]);
          // index
          _t3d.push_back(_t3c.size());
        }
        // copy char values
        std::size_t beg, end;
        _stringSpan(data[k]->_t3d, data[k]->_t3c, j * 5, 5, beg, end);
        _t3c.insert(_t3c.end(), data[k]->_t3c.begin() + beg,
                    data[k]->_t3c.begin() + end);
      }
    }
  }

  // create the time data
  for(std::size_t i = 0; i < data.size(); i++) dVecMerge(data[i]->_time, _time);

  // if all the time values are the same, it probably means that the
  // original views didn't have any time data: then we'll just use
  // time step values
  if(_time.size()) {
    double t0 = _time[0], ti;
    bool allTheSame = true;
    for(std::size_t i = 1; i < _time.size(); i++) {
      ti = _time[i];
      if(ti != t0) {
        allTheSame = false;
        break;
      }
    }
    if(allTheSame) _time.clear();
  }

  std::string tmp;
  if(nd.name == "__all__")
    tmp = "all";
  else if(nd.name == "__vis__")
    tmp = "visible";
  else
    tmp = nd.name;
  char name[256];
  sprintf(name, "%s_Combine", tmp.c_str());

  setName(name);
  setFileName(std::string(name) + ".pos");
  return finalize();
}

int PViewDataList::_getRawData(int idxtype, std::vector<double> **l, int **ne,
                               int *nc, int *nn)
{
  if(idxtype < 0 || idxtype >= 27) {
    Msg::Error("Wrong type in PViewDataList");
    return 0;
  }
  const listKind &k = listKinds[idxtype];
  *l = &(this->*k.list);
  *ne = &(this->*k.num);
  *nc = k.numComp;
  *nn = k.numNodes;
  if(haveInterpolationMatrices()) {
    std::vector<fullMatrix<double> *> im;
    int nim = getInterpolationMatrices(k.type, im);
    if(nim == 4) *nn = im[2]->size1();
  }
  return k.type;
}

void PViewDataList::setOrder2(int type)
{
  int typeMSH = 0;
  switch(type) {
  case TYPE_LIN: typeMSH = MSH_LIN_3; break;
  case TYPE_TRI: typeMSH = MSH_TRI_6; break;
  case TYPE_QUA: typeMSH = MSH_QUA_9; break;
  case TYPE_TET: typeMSH = MSH_TET_10; break;
  case TYPE_HEX: typeMSH = MSH_HEX_27; break;
  case TYPE_PRI: typeMSH = MSH_PRI_18; break;
  case TYPE_PYR: typeMSH = MSH_PYR_14; break;
  }
  const polynomialBasis *fs =
    (polynomialBasis *)BasisFactory::getNodalBasis(typeMSH);
  if(!fs) {
    Msg::Error("Could not find polynomial function space for element type %d",
               typeMSH);
    return;
  }
  setInterpolationMatrices(type, fs->coefficients, fs->monomials,
                           fs->coefficients, fs->monomials);
}

const PViewDataList::listKind *PViewDataList::_kind(int numComp, int type)
{
  for(auto &k : listKinds)
    if(k.type == type && k.numComp == numComp) return &k;
  return nullptr;
}

std::vector<double> *PViewDataList::incrementList(int numComp, int type,
                                                  int numNodes)
{
  if(type == TYPE_POLYG || type == TYPE_POLYH) {
    // the lists cannot hold the faces of polyhedra nor a variable number of
    // nodes: polytopes only exist in model-based views
    static bool warned = false;
    if(!warned)
      Msg::Warning("Polygons and polyhedra are skipped in list-based views");
    warned = true;
    return nullptr;
  }
  const listKind *k = _kind(numComp, type);
  if(!k) return nullptr;
  this->*k->num += 1;
  return &(this->*k->list);
}

void PViewDataList::appendList(int numComp, int type, int numElements,
                               const std::vector<double> &values)
{
  const listKind *k = _kind(numComp, type);
  if(!k || !numElements) return;
  this->*k->num += numElements;
  (this->*k->list).insert((this->*k->list).end(), values.begin(), values.end());
}

void PViewDataList::addString2D(double x, double y, double style,
                                const std::vector<std::string> &values)
{
  _t2d.push_back(x);
  _t2d.push_back(y);
  _t2d.push_back(style);
  _t2d.push_back(_t2c.size());
  for(auto &v : values)
    _t2c.insert(_t2c.end(), v.c_str(), v.c_str() + v.size() + 1);
  _nbT2++;
}

void PViewDataList::addString3D(double x, double y, double z, double style,
                                const std::vector<std::string> &values)
{
  _t3d.push_back(x);
  _t3d.push_back(y);
  _t3d.push_back(z);
  _t3d.push_back(style);
  _t3d.push_back(_t3c.size());
  for(auto &v : values)
    _t3c.insert(_t3c.end(), v.c_str(), v.c_str() + v.size() + 1);
  _nbT3++;
}

void PViewDataList::clearList(int numComp, int type)
{
  const listKind *k = _kind(numComp, type);
  if(!k) return;
  this->*k->num = 0;
  (this->*k->list).clear();
}

void PViewDataList::clearStrings(int dim)
{
  if(dim == 2) {
    _nbT2 = 0;
    _t2d.clear();
    _t2c.clear();
  }
  else {
    _nbT3 = 0;
    _t3d.clear();
    _t3c.clear();
  }
}
