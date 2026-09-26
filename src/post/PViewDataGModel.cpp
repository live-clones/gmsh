// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "PView.h"
#include "PViewDataGModel.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Context.h"
#include <atomic>
#include "pyramidalBasis.h"

PViewDataGModel::PViewDataGModel(DataType type)
  : PViewData(), _min(VAL_INF), _max(-VAL_INF), _type(type)
{
}

PViewDataGModel::~PViewDataGModel()
{
  for(std::size_t i = 0; i < _steps.size(); i++) delete _steps[i];
}

static MElement *_getOneElementOfGivenType(GModel *m, int type)
{
  switch(type) {
  case TYPE_PNT:
    for(auto it = m->firstVertex(); it != m->lastVertex(); it++) {
      if((*it)->points.size()) return (*it)->points[0];
    }
    break;
  case TYPE_LIN:
    for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
      if((*it)->lines.size()) return (*it)->lines[0];
    }
    break;
  case TYPE_TRI:
    for(auto it = m->firstFace(); it != m->lastFace(); it++) {
      if((*it)->triangles.size()) return (*it)->triangles[0];
    }
    break;
  case TYPE_QUA:
    for(auto it = m->firstFace(); it != m->lastFace(); it++) {
      if((*it)->quadrangles.size()) return (*it)->quadrangles[0];
    }
    break;
  case TYPE_POLYG:
    for(auto it = m->firstFace(); it != m->lastFace(); it++) {
      if((*it)->polygons.size()) return (*it)->polygons[0];
    }
    break;
  case TYPE_TET:
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      if((*it)->tetrahedra.size()) return (*it)->tetrahedra[0];
    }
    break;
  case TYPE_HEX:
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      if((*it)->hexahedra.size()) return (*it)->hexahedra[0];
    }
    break;
  case TYPE_PRI:
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      if((*it)->prisms.size()) return (*it)->prisms[0];
    }
    break;
  case TYPE_PYR:
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      if((*it)->pyramids.size()) return (*it)->pyramids[0];
    }
    break;
  case TYPE_POLYH:
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
      if((*it)->polyhedra.size()) return (*it)->polyhedra[0];
    }
    break;
  }
  return nullptr;
}

void PViewDataGModel::_computeMinMax(int step)
{
  stepData<double> *s = _steps[step];
  double min = VAL_INF, max = -VAL_INF;
  int tensorRep = 0; // Von-Mises: we could/should be able to choose this
  if(_type == NodeData || _type == ElementData) {
    // treat these 2 special cases separately for maximum efficiency
    int numComp = s->getNumComponents();
    for(std::size_t i = 0; i < s->getNumData(); i++) {
      double *d = s->getData(i);
      if(!d) continue;
      double val =
        (numComp == 1) ? d[0] : ComputeScalarRep(numComp, d, tensorRep);
      min = std::min(min, val);
      max = std::max(max, val);
    }
  }
  else {
    // general case (slower)
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double val;
          getScalarValue(step, ent, ele, nod, val, tensorRep);
          min = std::min(min, val);
          max = std::max(max, val);
        }
      }
    }
  }
  s->setMin(min);
  s->setMax(max);
}

void PViewDataGModel::_finalizeStep(int step, bool computeMinMax)
{
  if(computeMinMax) {
    _computeMinMax(step);
    _min = VAL_INF;
    _max = -VAL_INF;
    for(auto s : _steps) {
      _min = std::min(_min, s->getMin());
      _max = std::max(_max, s->getMax());
    }
  }
  finalize(false);
}

bool PViewDataGModel::finalize(bool computeMinMax,
                               const std::string &interpolationScheme)
{
  if(computeMinMax) {
    _min = VAL_INF;
    _max = -VAL_INF;
    for(int step = 0; step < getNumTimeSteps(); step++) {
      _computeMinMax(step);
      _min = std::min(_min, _steps[step]->getMin());
      _max = std::max(_max, _steps[step]->getMax());
    }
  }

  // set up interpolation matrices
  if(!haveInterpolationMatrices()) {
    GModel *model = _steps[0]->getModel();

    // Required for ParaView plugin linked to GMSH as external library.
    setInterpolationSchemeName(interpolationScheme);

    // if an interpolation scheme is explicitly provided, use it
    if(interpolationScheme.size()) {
      interpolationMatrices m = _interpolationSchemes[interpolationScheme];
      if(m.size())
        Msg::Info("Setting interpolation matrices from scheme '%s'",
                  interpolationScheme.c_str());
      else
        Msg::Error("Could not find interpolation scheme '%s'",
                   interpolationScheme.c_str());
      for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second.size() == 2) {
          // use provided interpolation matrices for field interpolation and use
          // geometrical interpolation matrices from the mesh if the mesh is
          // curved
          MElement *e = _getOneElementOfGivenType(model, it->first);
          if(e && e->getPolynomialOrder() > 1 && e->getFunctionSpace()) {
            if(it->first ==
               TYPE_PYR) { // nasty fix since pyramids /= polynomial
              const pyramidalBasis *fs =
                (pyramidalBasis *)e->getFunctionSpace();
              setInterpolationMatrices(it->first, *(it->second[0]),
                                       *(it->second[1]), fs->coefficients,
                                       fs->monomials);
            }
            else {
              const polynomialBasis *fs =
                (polynomialBasis *)e->getFunctionSpace();
              setInterpolationMatrices(it->first, *(it->second[0]),
                                       *(it->second[1]), fs->coefficients,
                                       fs->monomials);
            }
          }
          else
            setInterpolationMatrices(it->first, *(it->second[0]),
                                     *(it->second[1]));
        }
        else if(it->second.size() == 4) {
          // use provided matrices for field and geometry
          Msg::Warning(
            "You should not specify the geometrical interpolation "
            "in ElementNodeData: the geometry is completely determined "
            "by the mesh element type. This feature will be removed");
          setInterpolationMatrices(it->first, *it->second[0], *it->second[1],
                                   *it->second[2], *it->second[3]);
        }
        else
          Msg::Error(
            "Wrong number of interpolation matrices (%d) for scheme '%s'",
            (int)it->second.size(), interpolationScheme.c_str());
      }
    }

    // if we don't have interpolation matrices for a given element type, assume
    // isoparametric elements (except for ElementData, for which we know the
    // interpolation: it's constant)
    int types[] = {TYPE_PNT, TYPE_LIN, TYPE_TRI, TYPE_QUA,   TYPE_TET,
                   TYPE_HEX, TYPE_PRI, TYPE_PYR, TYPE_POLYG, TYPE_POLYH};
    for(std::size_t i = 0; i < sizeof(types) / sizeof(types[0]); i++) {
      if(!haveInterpolationMatrices(types[i])) {
        MElement *e = _getOneElementOfGivenType(model, types[i]);
        if(e) {
          const polynomialBasis *fs =
            dynamic_cast<const polynomialBasis *>(e->getFunctionSpace());
          if(fs) {
            if(e->getPolynomialOrder() > 1) {
              if(_type == ElementData) {
                // data is constant per element: force the interpolation matrix
                fullMatrix<double> coef(1, 1);
                coef(0, 0) = 1.;
                fullMatrix<double> mono(1, 3);
                mono(0, 0) = 0.;
                mono(0, 1) = 0.;
                mono(0, 2) = 0.;
                setInterpolationMatrices(types[i], coef, mono, fs->coefficients,
                                         fs->monomials);
              }
              else
                setInterpolationMatrices(types[i], fs->coefficients,
                                         fs->monomials, fs->coefficients,
                                         fs->monomials);
            }
            else
              setInterpolationMatrices(types[i], fs->coefficients,
                                       fs->monomials);
          }
          else {
            const pyramidalBasis *fs =
              dynamic_cast<const pyramidalBasis *>(e->getFunctionSpace());
            if(fs) {
              if(e->getPolynomialOrder() > 1) {
                if(_type == ElementData) {
                  // data is constant per element: force the interpolation
                  // matrix
                  fullMatrix<double> coef(1, 1);
                  coef(0, 0) = 1.;
                  fullMatrix<double> mono(1, 3);
                  mono(0, 0) = 0.;
                  mono(0, 1) = 0.;
                  mono(0, 2) = 0.;
                  setInterpolationMatrices(types[i], coef, mono,
                                           fs->coefficients, fs->monomials);
                }
                else
                  setInterpolationMatrices(types[i], fs->coefficients,
                                           fs->monomials, fs->coefficients,
                                           fs->monomials);
              }
              else
                setInterpolationMatrices(types[i], fs->coefficients,
                                         fs->monomials);
            }
          }
        }
      }
    }
  }
  return PViewData::finalize();
}

MElement *PViewDataGModel::_getElement(int step, int ent, int ele)
{
  return _steps[step]->getEntity(ent)->getMeshElement(ele);
}

std::string PViewDataGModel::getFileName(int step)
{
  if(step < 0 || step > (int)_steps.size() - 1) return PViewData::getFileName();
  return _steps[step]->getFileName();
}

int PViewDataGModel::getNumTimeSteps() { return _steps.size(); }

int PViewDataGModel::getFirstNonEmptyTimeStep(int start)
{
  for(std::size_t i = start; i < _steps.size(); i++)
    if(_steps[i]->getNumData()) return i;
  return start;
}

double PViewDataGModel::getTime(int step)
{
  if(_steps.empty()) return 0.;
  return _steps[step]->getTime();
}

double PViewDataGModel::getMin(int step, bool onlyVisible, int tensorRep,
                               int forceNumComponents, int componentMap[9])
{
  if(_steps.empty()) return _min;

  if(onlyVisible || forceNumComponents || tensorRep) {
    double vmin = VAL_INF;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      if(onlyVisible && skipEntity(step, ent)) continue;
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele, onlyVisible)) continue;
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
  return _steps[step]->getMin();
}

double PViewDataGModel::getMax(int step, bool onlyVisible, int tensorRep,
                               int forceNumComponents, int componentMap[9])
{
  if(_steps.empty()) return _max;

  if(onlyVisible || forceNumComponents || tensorRep) {
    double vmax = -VAL_INF;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      if(onlyVisible && skipEntity(step, ent)) continue;
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele, onlyVisible)) continue;
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
  return _steps[step]->getMax();
}

SBoundingBox3d PViewDataGModel::getBoundingBox(int step)
{
  if(step < 0 || _steps.empty()) {
    SBoundingBox3d tmp;
    for(std::size_t i = 0; i < _steps.size(); i++) {
      if(!_steps[i]->getBoundingBox().empty())
        tmp += _steps[i]->getBoundingBox();
    }
    return tmp;
  }
  return _steps[step]->getBoundingBox();
}

int PViewDataGModel::getNumScalars(int step)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(_steps[0]->getNumComponents() == 1) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumVectors(int step)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(_steps[0]->getNumComponents() == 3) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumTensors(int step)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(_steps[0]->getNumComponents() == 9) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumPoints(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstVertex(); it != m->lastVertex(); ++it)
    n += (*it)->points.size();
  return n;
}

int PViewDataGModel::getNumLines(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it)
    n += (*it)->lines.size();
  return n;
}

int PViewDataGModel::getNumTriangles(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstFace(); it != m->lastFace(); ++it)
    n += (*it)->triangles.size();
  return n;
}

int PViewDataGModel::getNumQuadrangles(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstFace(); it != m->lastFace(); ++it)
    n += (*it)->quadrangles.size();
  return n;
}

int PViewDataGModel::getNumPolygons(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstFace(); it != m->lastFace(); ++it)
    n += (*it)->polygons.size();
  return n;
}

int PViewDataGModel::getNumTetrahedra(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->tetrahedra.size();
  return n;
}

int PViewDataGModel::getNumHexahedra(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->hexahedra.size();
  return n;
}

int PViewDataGModel::getNumPrisms(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->prisms.size();
  return n;
}

int PViewDataGModel::getNumPyramids(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->pyramids.size();
  return n;
}

int PViewDataGModel::getNumTrihedra(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->trihedra.size();
  return n;
}

int PViewDataGModel::getNumPolyhedra(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->polyhedra.size();
  return n;
}

int PViewDataGModel::getNumEntities(int step)
{
  if(_steps.empty()) return 0;
  // (step < 0: any step, the first with data, as the steps before it may be
  // placeholders without entities)
  if(step < 0) step = getFirstNonEmptyTimeStep();
  return _steps[step]->getNumEntities();
}

int PViewDataGModel::getNumElements(int step, int ent)
{
  if(_steps.empty()) return 0;
  if(step < 0) step = getFirstNonEmptyTimeStep(); // (see getNumEntities())
  if(ent < 0) return _steps[step]->getModel()->getNumMeshElements();
  return _steps[step]->getEntity(ent)->getNumMeshElements();
}

GEntity *PViewDataGModel::getEntity(int step, int ent)
{
  return _steps[step]->getEntity(ent);
}

MElement *PViewDataGModel::getElement(int step, int ent, int element)
{
  if(_steps.empty()) return nullptr;
  if(step < 0) step = getFirstNonEmptyTimeStep(); // (see getNumEntities())
  return _steps[step]->getEntity(ent)->getMeshElement(element);
}

int PViewDataGModel::getDimension(int step, int ent, int ele)
{
  return _getElement(step, ent, ele)->getDim();
}

int PViewDataGModel::getNumNodes(int step, int ent, int ele)
{ return _getNumNodes(step, _getElement(step, ent, ele)); }

int PViewDataGModel::_getNumNodes(int step, MElement *e)
{
  if(_type == GaussPointData) {
    return _steps[step]->getGaussPoints(e->getTypeForMSH()).size() / 3;
  }
  else {
    if(e->getNumChildren())
      return e->getNumChildren() * e->getChild(0)->getNumVertices();
    // polytopes need all their nodes, as their data is P1 on their
    // sub-simplices, whose nodes are not all primary
    if(getAdaptiveData() || e->getType() == TYPE_POLYG ||
       e->getType() == TYPE_POLYH)
      return e->getNumVertices();
    return (int)e->getNumPrimaryVertices();
  }
}

MVertex *PViewDataGModel::_getNode(MElement *e, int nod)
{
  MVertex *v;
  if(!e->getNumChildren())
    v = e->getVertex(nod);
  else {
    int nbV = e->getChild(0)->getNumVertices();
    v = e->getChild((int)(nod / nbV))->getVertex(nod % nbV);
  }
  return v;
}

std::size_t PViewDataGModel::getNodeId(int step, int ent, int ele, int nod)
{
  // the "nodes" of Gauss point data are not mesh vertices
  if(_type == GaussPointData) return 0;
  MElement *e = _getElement(step, ent, ele);
  if(!e) return 0;
  MVertex *v = _getNode(e, nod);
  return v ? v->getNum() : 0;
}

void PViewDataGModel::getSkinKeys(int step, bool partitionsTogether,
                                  std::vector<int> &keys)
{
  int n = getNumEntities(step);
  keys.resize(n);
  // (the parents numbered after the entities)
  std::map<GEntity *, int> parents;
  for(int ent = 0; ent < n; ent++) {
    keys[ent] = ent;
    GEntity *parent =
      partitionsTogether ? getEntity(step, ent)->getParentEntity() : nullptr;
    if(!parent) continue;
    auto it = parents.find(parent);
    if(it == parents.end())
      it = parents.emplace(parent, n + (int)parents.size()).first;
    keys[ent] = it->second;
  }
}

int PViewDataGModel::getNode(int step, int ent, int ele, int nod, double &x,
                             double &y, double &z)
{
  MElement *e = _getElement(step, ent, ele);
  MVertex *v = _getNode(e, nod);
  if(_type == GaussPointData) {
    std::vector<double> &p(_steps[step]->getGaussPoints(e->getTypeForMSH()));
    if(p[0] == 1.e22) {
      // hack: the points are the element vertices
      x = v->x();
      y = v->y();
      z = v->z();
    }
    else {
      double vx[8], vy[8], vz[8];
      for(std::size_t i = 0; i < e->getNumPrimaryVertices(); i++) {
        vx[i] = e->getVertex(i)->x();
        vy[i] = e->getVertex(i)->y();
        vz[i] = e->getVertex(i)->z();
      }
      x = e->interpolate(vx, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2], 1, 1);
      y = e->interpolate(vy, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2], 1, 1);
      z = e->interpolate(vz, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2], 1, 1);
    }
    return 0;
  }
  else {
    x = v->x();
    y = v->y();
    z = v->z();
    return v->getIndex();
  }
}

void PViewDataGModel::setNode(int step, int ent, int ele, int nod, double x,
                              double y, double z)
{
  MElement *e = _getElement(step, ent, ele);
  MVertex *v = _getNode(e, nod);
  v->x() = x;
  v->y() = y;
  v->z() = z;
}

int PViewDataGModel::getNumComponents(int step, int ent, int ele)
{
  return _steps[step]->getNumComponents();
}

int PViewDataGModel::getNumValues(int step, int ent, int ele)
{
  if(_type == ElementNodeData) {
    MElement *e = _getElement(step, ent, ele);
    return _steps[step]->getMult(e->getNum()) *
           getNumComponents(step, ent, ele);
  }
  else if(_type == NodeData) {
    return getNumNodes(step, ent, ele) * getNumComponents(step, ent, ele);
  }
  else if(_type == ElementData) {
    return getNumComponents(step, ent, ele);
  }
  else {
    Msg::Error("getNumValues() should not be used on this type of view");
    return getNumComponents(step, ent, ele);
  }
}

void PViewDataGModel::getValue(int step, int ent, int ele, int idx, double &val)
{
  MElement *e = _getElement(step, ent, ele);
  if(_type == ElementNodeData || _type == ElementData) {
    val = _steps[step]->getData(e->getNum())[idx];
  }
  else if(_type == NodeData) {
    int numcomp = _steps[step]->getNumComponents();
    int nod = idx / numcomp;
    int comp = idx % numcomp;
    int num = _getNode(e, nod)->getNum();
    val = _steps[step]->getData(num)[comp];
  }
  else {
    Msg::Error("getValue(index) should not be used on this type of view");
  }
}

// where the value of a component at a node of an element is (element-node and
// Gauss point data: as many values per element as it has, those of its first
// node for the nodes beyond them)
double *PViewDataGModel::_getValue(int step, MElement *e, int nod, int comp)
{
  stepData<double> *s = _steps[step];
  switch(_type) {
  case NodeData: return &s->getData(_getNode(e, nod)->getNum())[comp];
  case ElementNodeData:
  case GaussPointData:
    if(s->getMult(e->getNum()) < nod + 1) {
      nod = 0;
      static std::atomic<bool> warned(false);
      if(!warned.exchange(true))
        Msg::Warning("Some elements in ElementNodeData have less values than "
                     "number of nodes");
    }
    return &s->getData(e->getNum())[s->getNumComponents() * nod + comp];
  case ElementData:
  default: return &s->getData(e->getNum())[comp];
  }
}

void PViewDataGModel::getValue(int step, int ent, int ele, int nod, int comp,
                               double &val)
{ val = *_getValue(step, _getElement(step, ent, ele), nod, comp); }

void PViewDataGModel::setValue(int step, int ent, int ele, int nod, int comp,
                               double val)
{ *_getValue(step, _getElement(step, ent, ele), nod, comp) = val; }

void PViewDataGModel::getElementInfo(int step, int ent, int ele, int &type,
                                     int &dim, int &numNodes, int &numComp)
{
  MElement *e = _getElement(step, ent, ele);
  type = e->getType();
  dim = e->getDim();
  numNodes = _getNumNodes(step, e);
  numComp = _steps[step]->getNumComponents();
}

void PViewDataGModel::getNodesAndValues(int step, int ent, int ele,
                                        int numNodes, int numComp, double **xyz,
                                        double **val)
{
  // (the nodes of Gauss point data are interpolated: see getNode())
  if(_type == GaussPointData) {
    PViewData::getNodesAndValues(step, ent, ele, numNodes, numComp, xyz, val);
    return;
  }
  MElement *e = _getElement(step, ent, ele);
  for(int j = 0; j < numNodes; j++) {
    MVertex *v = _getNode(e, j);
    xyz[j][0] = v->x();
    xyz[j][1] = v->y();
    xyz[j][2] = v->z();
    if(!numComp) continue;
    double *d = _getValue(step, e, j, 0);
    for(int k = 0; k < numComp; k++) val[j][k] = d[k];
  }
}

int PViewDataGModel::getNumEdges(int step, int ent, int ele)
{
  return _getElement(step, ent, ele)->getNumEdges();
}

int PViewDataGModel::getType(int step, int ent, int ele)
{
  return _getElement(step, ent, ele)->getType();
}

void PViewDataGModel::reverseElement(int step, int ent, int ele)
{
  if(!step) _getElement(step, ent, ele)->reverse();
}

void PViewDataGModel::smooth()
{
  if(_type == NodeData || _type == GaussPointData) return;
  std::vector<stepData<double> *> _steps2;
  for(std::size_t step = 0; step < _steps.size(); step++) {
    GModel *m = _steps[step]->getModel();
    int numComp = _steps[step]->getNumComponents();
    _steps2.push_back(new stepData<double>(
      m, numComp, _steps[step]->getFileName(), _steps[step]->getTime()));
    _steps2.back()->fillEntities();
    _steps2.back()->computeBoundingBox();

    // the number of elements around each node (indexed by node tag)
    std::vector<int> nodeConnect(m->getMaxVertexNumber() + 1, 0);
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        MElement *e = _steps[step]->getEntity(ent)->getMeshElement(ele);
        double val;
        if(!getValueByIndex(step, e->getNum(), 0, 0, val)) continue;
        for(std::size_t nod = 0; nod < e->getNumVertices(); nod++) {
          MVertex *v = e->getVertex(nod);
          nodeConnect[v->getNum()]++;
          double *d = _steps2.back()->getData(v->getNum(), true);
          for(int j = 0; j < numComp; j++)
            if(getValueByIndex(step, e->getNum(), nod, j, val)) d[j] += val;
        }
      }
    }
    for(std::size_t i = 0; i < _steps2.back()->getNumData(); i++) {
      double *d = _steps2.back()->getData(i);
      if(d && i < nodeConnect.size() && nodeConnect[i])
        for(int j = 0; j < numComp; j++) d[j] /= nodeConnect[i];
    }
  }
  for(std::size_t i = 0; i < _steps.size(); i++) delete _steps[i];
  _steps = _steps2;
  _type = NodeData;
  finalize();
}

double PViewDataGModel::getMemoryInMB()
{
  double m = 0.;
  for(std::size_t i = 0; i < _steps.size(); i++)
    m += _steps[i]->getMemoryInMB();
  return m;
}

bool PViewDataGModel::combineTime(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  std::vector<PViewDataGModel *> data(nd.data.size());
  for(std::size_t i = 0; i < nd.data.size(); i++) {
    data[i] = dynamic_cast<PViewDataGModel *>(nd.data[i]);
    if(!data[i]) {
      Msg::Error("Cannot combine hybrid data");
      return false;
    }
  }

  // copy interpolation matrices
  for(auto it = data[0]->_interpolation.begin();
      it != data[0]->_interpolation.end(); it++)
    if(_interpolation[it->first].empty())
      for(std::size_t i = 0; i < it->second.size(); i++)
        _interpolation[it->first].push_back(
          new fullMatrix<double>(*it->second[i]));

  // (deep) copy step data
  for(std::size_t i = 0; i < data.size(); i++)
    for(std::size_t j = 0; j < data[i]->_steps.size(); j++)
      if(data[i]->hasTimeStep(j))
        _steps.push_back(new stepData<double>(*data[i]->_steps[j]));

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
  setFileName(std::string(name) + ".msh");
  return finalize();
}

bool PViewDataGModel::skipEntity(int step, int ent)
{
  if(step >= getNumTimeSteps()) return true;

  // this breaks common usage pattern of loading several model-based views and
  // expecting all the views to be visible: see #3085
  // if(!_steps[step]->getModel()->getVisibility()) return true;

  if(!_steps[step]->getEntity(ent)->getVisibility()) return true;
  return false;
}

bool PViewDataGModel::skipElement(int step, int ent, int ele,
                                  bool checkVisibility, int samplingRate)
{
  if(step >= getNumTimeSteps()) return true;
  stepData<double> *sd = _steps[step];
  if(!_steps[step]->getNumData()) return true;
  MElement *e = _getElement(step, ent, ele);
  if(checkVisibility && !e->getVisibility()) return true;
  if(_type == NodeData) {
    // not in the loop condition: getNumNodes() is expensive
    int numNodes = getNumNodes(step, ent, ele);
    for(int i = 0; i < numNodes; i++)
      if(!sd->getData(_getNode(e, i)->getNum())) return true;
  }
  else {
    if(!sd->getData(e->getNum())) return true;
  }
  return PViewData::skipElement(step, ent, ele, checkVisibility, samplingRate);
}

bool PViewDataGModel::forEachMesh(const std::function<bool(int)> &f)
{
  std::vector<stepData<double> *> all = _steps;
  bool ok = true;
  for(std::size_t first = 0; first < all.size();) {
    if(!all[first]->getNumData()) {
      first++;
      continue;
    }
    GModel *model = all[first]->getModel();
    std::size_t last = first + 1;
    while(last < all.size() && (all[last]->getModel() == model ||
                                !all[last]->getNumData()))
      last++;
    std::vector<stepData<double> *> empty;
    for(std::size_t step = 0; step < all.size(); step++) {
      if(step >= first && step < last) continue;
      empty.push_back(new stepData<double>(model, all[step]->getNumComponents(),
                                           "", all[step]->getTime()));
      _steps[step] = empty.back();
    }
    if(!f(first)) ok = false;
    for(auto e : empty) delete e;
    _steps = all;
    first = last;
  }
  return ok;
}

bool PViewDataGModel::hasTimeStep(int step)
{
  if(step >= 0 && step < getNumTimeSteps() && _steps[step]->getNumData())
    return true;
  return false;
}

stepData<double> *PViewDataGModel::_getStep(int step, GModel *model,
                                            int numComp)
{
  if(step < 0) return nullptr;
  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  if(_steps[step]->getNumComponents() != numComp ||
     _steps[step]->getModel() != model) {
    if(_steps[step]->getNumData()) {
      if(_steps[step]->getModel() != model)
        Msg::Error("Step %d of view '%s' is on another model", step,
                   getName().c_str());
      else
        Msg::Error("Step %d of view '%s' has %d components, not %d", step,
                   getName().c_str(), _steps[step]->getNumComponents(),
                   numComp);
      return nullptr;
    }
    delete _steps[step];
    _steps[step] = new stepData<double>(model, numComp);
  }
  // (the stamps of the changes to the mesh and the geometry, bumped once a file
  // is read or the model is changed, and the numbers of entities and the
  // largest node tag, that change as a file is read)
  GModel *m = _steps[step]->getModel();
  CTX *ctx = CTX::instance();
  std::vector<std::size_t> signature = {
    (std::size_t)ctx->meshContentStamp,
    (std::size_t)(ctx->geom.stamp[0] + ctx->geom.stamp[1] + ctx->geom.stamp[2] +
                  ctx->geom.stamp[3]),
    m->getNumRegions() + m->getNumFaces() + m->getNumEdges() +
      m->getNumVertices(),
    m->getMaxVertexNumber()};
  _steps[step]->updateModelInfo(_steps, signature);
  return _steps[step];
}

bool PViewDataGModel::readInView(
  const std::string &name, const std::string &fileName, DataType type,
  const std::function<bool(PViewDataGModel *)> &accept,
  const std::function<bool(PViewDataGModel *)> &read)
{
  PViewDataGModel *d = nullptr;
  for(int i = (int)PView::list.size() - 1; i >= 0 && !d; i--) {
    auto g = dynamic_cast<PViewDataGModel *>(PView::list[i]->getData());
    if(g && g->getName() == name && accept(g)) d = g;
  }
  bool create = !d;
  if(create) d = new PViewDataGModel(type);
  if(!read(d)) {
    if(create) delete d;
    return false;
  }
  d->setName(name);
  d->setFileName(fileName);
  if(create) new PView(d);
  return true;
}

bool PViewDataGModel::canAddData(DataType type, int step, int numComp)
{
  if(type != _type) return false;
  return !hasTimeStep(step) || _steps[step]->getNumComponents() == numComp;
}

bool PViewDataGModel::hasPartition(int step, int part)
{
  if(step < 0 || step >= getNumTimeSteps()) return false;
  return _steps[step]->getPartitions().find(part) !=
         _steps[step]->getPartitions().end();
}

bool PViewDataGModel::hasMultipleMeshes()
{
  if(_steps.size() <= 1) return false;
  GModel *m = _steps[0]->getModel();
  for(std::size_t i = 1; i < _steps.size(); i++)
    if(m != _steps[i]->getModel()) return true;
  return false;
}

bool PViewDataGModel::hasModel(GModel *model, int step)
{
  if(step < 0) {
    for(std::size_t i = 0; i < _steps.size(); i++)
      if(model == _steps[i]->getModel()) return true;
    return false;
  }
  return (model == _steps[step]->getModel());
}

bool PViewDataGModel::getValueByIndex(int step, std::size_t dataIndex, int nod,
                                      int comp, double &val)
{
  double *d = _steps[step]->getData(dataIndex);
  if(!d) return false;

  if(_type == NodeData || _type == ElementData)
    val = d[comp];
  else
    val = d[_steps[step]->getNumComponents() * nod + comp];
  return true;
}
