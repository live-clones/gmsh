// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#ifndef CHAIN_H
#define CHAIN_H

#include <sstream>
#include "GModel.h"
#include "MElement.h"
#include "Context.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_KBIPACK)

void updateFltk();
std::string convertInt(int number);

// Class whose derivative classes are to have partial or total order
template <class Type> class PosetCat {
public:
  virtual ~PosetCat() {}
  /// instantiated in derived classes
  virtual bool lessThan(const Type &t2) const = 0;

  friend bool operator<(const Type &t1, const Type &t2)
  {
    return t1.lessThan(t2);
  }
  friend bool operator>(const Type &t1, const Type &t2)
  {
    return !t1.lessThan(t2);
  }
  friend bool operator==(const Type &t1, const Type &t2)
  {
    if(t1.lessThan(t2) && t2.lessThan(t1)) return true;
    return false;
  }
  friend bool operator!=(const Type &t1, const Type &t2)
  {
    if(t1.lessThan(t2) && t2.lessThan(t1)) return false;
    return true;
  }
  friend bool operator<=(const Type &t1, const Type &t2)
  {
    if(t1.lessThan(t2) || t1 == t2) return true;
    return false;
  }
  friend bool operator>=(const Type &t1, const Type &t2)
  {
    if(!t1.lessThan(t2) || t1 == t2) return true;
    return false;
  }
};

// Class whose derivative classes are to have vector space structure
template <class V, class S> class VectorSpaceCat {
public:
  virtual ~VectorSpaceCat() {}

  /// instantiated in derived classes
  virtual V &operator+=(const V &v) = 0;
  virtual V &operator*=(const S &s) = 0;
  // virtual V& zero() = 0;
  /// ---------------------

  friend V operator+(const V &v1, const V &v2)
  {
    V temp(v1);
    temp += v2;
    return temp;
  }
  friend V operator-(const V &v1, const V &v2)
  {
    V temp(v1);
    temp -= v2;
    return temp;
  }
  friend V operator*(const S &s, const V &v)
  {
    V temp(v);
    temp *= s;
    return temp;
  }
  friend V operator*(const V &v, const S &s) { return s * v; }
  friend V operator/(const V &v, const S &s)
  {
    S invs = 1. / s;
    return invs * v;
  }

  // Warning: assummes that the multiplicative
  // identity element of field S can be converted from double "1."
  // and that additive inverse of v in Abelian group V equals v*-1.
  // (true e.g. for double and std::complex<double>),
  // otherwise these need to be overridden by the user

  virtual V &operator-() { return (*this) *= (-1.); }
  virtual V &operator/=(const S &s)
  {
    S temp = 1. / s;
    return (*this *= temp);
  }
  virtual V &operator-=(const V &v)
  {
    V temp(v);
    temp = -temp;
    return (*this += temp);
  }
};

// Class to represent an 'elementary chain', a mesh cell
class ElemChain : public PosetCat<ElemChain> {
private:
  char _dim;
  std::vector<MVertex *> _v;
  std::vector<char> _si;
  inline void _sortVertexIndices();
  bool _equalVertices(const std::vector<MVertex *> &v2) const;

  static std::map<GEntity *, std::set<MVertex *, MVertexPtrLessThan>,
                  GEntityPtrLessThan>
    _vertexCache;

public:
  ElemChain(MElement *e);
  ElemChain(int dim, std::vector<MVertex *> &v);

  int getDim() const { return _dim; }
  int getNumVertices() const { return _v.size(); }
  MVertex *getMeshVertex(int i) const { return _v.at(i); }
  void getMeshVertices(std::vector<MVertex *> &v) const { v = _v; }
  int getNumSortedVertices() const { return _v.size(); }
  inline int getSortedVertex(int i) const;

  int getTypeMSH() const;
  MElement *createMeshElement() const;

  int compareOrientation(const ElemChain &c2) const;
  bool lessThan(const ElemChain &c2) const;

  int getNumBoundaryElemChains() const;
  ElemChain getBoundaryElemChain(int i) const;

  bool inEntity(GEntity *e) const;

  static void clearVertexCache() { _vertexCache.clear(); }
  static int getTypeMSH(int dim, int numVertices);
  static int getNumBoundaries(int dim, int numVertices);
  static void getBoundaryVertices(int i, int dim, int numVertices,
                                  const std::vector<MVertex *> &v,
                                  std::vector<MVertex *> &vertices);
};

void findEntitiesInPhysicalGroups(GModel *m,
                                  const std::vector<int> &physicalGroups,
                                  std::vector<GEntity *> &entities);

// Class to represent a chain, formal sum of elementary chains
template <class C> class Chain : public VectorSpaceCat<Chain<C>, C> {
private:
  // Dimension of the chain
  int _dim;
  // Elementary chains and their coefficients in the chain
  std::map<ElemChain, C> _elemChains;
  // A name for the chain
  std::string _name;

  Chain<C> _getTraceOrProject(const std::vector<GEntity *> &entities,
                              bool trace) const;

public:
  // Elementary chain iterators
  typedef typename std::map<ElemChain, C>::iterator ecit;
  typedef typename std::map<ElemChain, C>::const_iterator cecit;

  // Create zero chain
  Chain() : _dim(-1), _name("") {}

  // Create chain from Gmsh model physical group
  // (all mesh elements in the physical group are treated as
  //  elementary chains with coefficient 1)
  Chain(GModel *m, int physicalGroup);

  // Get/set the chain name
  std::string getName() const { return _name; }
  void setName(std::string name) { _name = name; }

  // Get chain dimension
  int getDim() const { return _dim; }

  // True if a zero element of a chain space
  bool isZero() const { return _elemChains.empty(); }

  // Iterators to elementrary chains in the chain
  cecit firstElemChain() const { return _elemChains.begin(); }
  cecit lastElemChain() const { return _elemChains.end(); }

  // Add mesh element or elementary chain with given coefficient to the chain
  void addMeshElement(MElement *e, C coeff = 1);
  void addElemChain(const ElemChain &c, C coeff = 1);

  // Vector space operations for chains (these two induce the rest)
  Chain<C> &operator+=(const Chain<C> &chain);
  Chain<C> &operator*=(const C &coeff);

  // Get elementary chain coefficient the chain
  C getCoefficient(const ElemChain &c2) const;

  // Get mesh element (or its indicated face, edge, or vertex)
  // coefficient in the chain, interpreted as a elementary chain
  C getCoefficient(MElement *e, int subElement = -1) const;

  // Get the boundary chain of this chain
  Chain<C> getBoundary() const;

  // Get a chain which contains elementary chains that are
  // in the given physical group or elementary entities
  Chain<C> getTrace(GModel *m, int physicalGroup) const;
  Chain<C> getTrace(GModel *m, const std::vector<int> &physicalGroups) const;
  Chain<C> getTrace(const std::vector<GEntity *> &entities) const;

  // Get a chain which contains elementary chains that are *not*
  // in the given physical group or elementary entities
  Chain<C> getProject(GModel *m, int physicalGroup) const;
  Chain<C> getProject(GModel *m, const std::vector<int> &physicalGroups) const;
  Chain<C> getProject(const std::vector<GEntity *> &entities) const;

  // The above two methods decompose a chain c so that
  // (c - c.getTrace(...) - c.getProject(...)).isZero() == true
  // holds

  // Add chain to Gmsh model as a physical group,
  // elementary chains are turned into mesh elements with
  // orientation and multiplicity given by elementary chain coefficient
  // (and create a post-processing view)
  // (and request a physical group number)
  // returns physical group number of the chain
  int addToModel(GModel *m, bool post = true,
                 int physicalNumRequest = -1) const;
};

template <class C> Chain<C>::Chain(GModel *m, int physicalGroup)
{
  _dim = 0;
  std::vector<int> groups(1, physicalGroup);
  std::vector<GEntity *> entities;
  findEntitiesInPhysicalGroups(m, groups, entities);

  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *e = entities.at(i);
    _dim = e->dim();
    for(std::size_t j = 0; j < e->getNumMeshElements(); j++) {
      this->addMeshElement(e->getMeshElement(j));
    }
    this->setName(m->getPhysicalName(this->getDim(), physicalGroup));
  }
}

template <class C> C Chain<C>::getCoefficient(const ElemChain &c2) const
{
  cecit it = _elemChains.find(c2);
  if(it != _elemChains.end())
    return it->second * c2.compareOrientation(it->first);
  else
    return 0;
}

template <class C> C Chain<C>::getCoefficient(MElement *e, int subElement) const
{
  if(this->getDim() == e->getDim()) {
    ElemChain ec(e);
    return this->getCoefficient(ec);
  }
  if(subElement == -1) return 0;
  std::vector<MVertex *> v;
  if(this->getDim() == 0) {
    if(subElement >= e->getNumVertices()) return 0;
    v = std::vector<MVertex *>(1, e->getVertex(subElement));
  }
  else if(this->getDim() == 1) {
    if(subElement >= e->getNumEdges()) return 0;
    e->getEdgeVertices(subElement, v);
    v.resize(2);
  }
  else if(this->getDim() == 2) {
    if(subElement >= e->getNumFaces()) return 0;
    e->getFaceVertices(subElement, v);
    if(e->getType() == TYPE_TET ||
       (e->getType() == TYPE_PRI && subElement < 4) ||
       (e->getType() == TYPE_PYR && subElement < 2))
      v.resize(3);
    else
      v.resize(4);
  }
  ElemChain ec(this->getDim(), v);
  return this->getCoefficient(ec);
}

template <class C> C incidence(const Chain<C> &c1, const Chain<C> &c2)
{
  C incidence = 0;
  if(c1.getDim() != c2.getDim()) return incidence;
  for(typename Chain<C>::cecit it = c1.firstElemChain();
      it != c1.lastElemChain(); it++) {
    incidence += it->second * c2.getCoefficient(it->first);
  }
  if(incidence != 0) {
    Msg::Debug("%d-chains \'%s\' and \'%s\' have incidence %d", c1.getDim(),
               c1.getName().c_str(), c2.getName().c_str(), incidence);
  }
  return incidence;
}

template <class C> Chain<C> boundary(const ElemChain &c)
{
  Chain<C> result;
  for(int i = 0; i < c.getNumBoundaryElemChains(); i++) {
    C coeff = 1;
    if(c.getDim() == 1 && i == 0) coeff = -1;
    result.addElemChain(c.getBoundaryElemChain(i), coeff);
  }
  return result;
}

template <class C> Chain<C> Chain<C>::getBoundary() const
{
  Chain<C> result;
  for(cecit it = _elemChains.begin(); it != _elemChains.end(); it++) {
    C coeff = it->second;
    result += boundary<C>(it->first) * coeff;
  }
  if(result.isZero())
    Msg::Info("The boundary chain is zero element in C%d", result.getDim());
  return result;
}

template <class C>
Chain<C> Chain<C>::getTrace(GModel *m, int physicalGroup) const
{
  std::vector<int> groups(1, physicalGroup);
  return this->getTrace(m, groups);
}

template <class C>
Chain<C> Chain<C>::getProject(GModel *m, int physicalGroup) const
{
  std::vector<int> groups(1, physicalGroup);
  return this->getProject(m, groups);
}

template <class C>
Chain<C> Chain<C>::getTrace(GModel *m,
                            const std::vector<int> &physicalGroups) const
{
  std::vector<GEntity *> entities;
  findEntitiesInPhysicalGroups(m, physicalGroups, entities);
  if(entities.empty()) return Chain<C>();
  return this->_getTraceOrProject(entities, true);
}

template <class C>
Chain<C> Chain<C>::getProject(GModel *m,
                              const std::vector<int> &physicalGroups) const
{
  std::vector<GEntity *> entities;
  findEntitiesInPhysicalGroups(m, physicalGroups, entities);
  if(entities.empty()) return Chain<C>();
  return this->_getTraceOrProject(entities, false);
}

template <class C>
Chain<C> Chain<C>::_getTraceOrProject(const std::vector<GEntity *> &entities,
                                      bool trace) const
{
  Chain<C> result;
  for(cecit it = _elemChains.begin(); it != _elemChains.end(); it++) {
    bool inDomain = false;
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(it->first.inEntity(entities.at(i))) {
        inDomain = true;
        break;
      }
    }
    if(inDomain && trace) result.addElemChain(it->first, it->second);
    if(!inDomain && !trace) result.addElemChain(it->first, it->second);
  }
  return result;
}

template <class C>
Chain<C> Chain<C>::getTrace(const std::vector<GEntity *> &entities) const
{
  return this->_getTraceOrProject(entities, true);
}

template <class C>
Chain<C> Chain<C>::getProject(const std::vector<GEntity *> &entities) const
{
  return this->_getTraceOrProject(entities, false);
}

template <class C> void Chain<C>::addMeshElement(MElement *e, C coeff)
{
  ElemChain ce(e);
  this->addElemChain(ce, coeff);
}

template <class C> void Chain<C>::addElemChain(const ElemChain &c, C coeff)
{
  if(coeff == 0) return;
  if(_dim != -1 && _dim != c.getDim()) {
    Msg::Error("Cannot add elementrary %d-chain to %d-chain", c.getDim(), _dim);
    return;
  }
  if(_dim == -1) _dim = c.getDim();
  std::pair<ecit, bool> ii = _elemChains.insert(std::make_pair(c, coeff));
  if(!ii.second) {
    ii.first->second += coeff * c.compareOrientation(ii.first->first);
    if(ii.first->second == 0) _elemChains.erase(ii.first);
  }
}

template <class C> Chain<C> &Chain<C>::operator+=(const Chain<C> &chain)
{
  for(cecit it = chain.firstElemChain(); it != chain.lastElemChain(); it++)
    this->addElemChain(it->first, it->second);
  return *this;
}

template <class C> Chain<C> &Chain<C>::operator*=(const C &coeff)
{
  if(coeff == 0)
    _elemChains.clear();
  else
    for(ecit it = _elemChains.begin(); it != _elemChains.end(); it++)
      it->second *= coeff;
  return *this;
}

template <class C>
int Chain<C>::addToModel(GModel *m, bool post, int physicalNumRequest) const
{
  if(this->isZero()) {
    Msg::Info("A chain is zero element of C%d, not added to the model",
              this->getDim());
    return -1;
  }

  std::string name = _name;
  // avoid too long names, which screw up the GUI and the msh file
  if(name.size() > 128) name.resize(128);

  std::vector<MElement *> elements;
  std::map<int, std::vector<double> > data;
  int dim = this->getDim();

  for(cecit it = this->firstElemChain(); it != this->lastElemChain(); it++) {
    MElement *e = it->first.createMeshElement();
    C coeff = it->second;
    elements.push_back(e);
    if(dim > 0 && coeff < 0) e->reverse();

    // if elementary chain coefficient is other than -1 or 1,
    // add multiple identical MElements to the physical group
    for(int i = 1; i < abs(coeff); i++) {
      MElement *ecopy = it->first.createMeshElement();
      if(dim > 0 && coeff < 0) ecopy->reverse();
      elements.push_back(ecopy);
    }
    if(dim > 0) coeff = abs(coeff);

    std::vector<double> coeffs(1, coeff);
    data[e->getNum()] = coeffs;
  }
  int max[4];
  for(int i = 0; i < 4; i++) max[i] = m->getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max, max + 4) + 1;
  for(int i = 0; i < 4; i++) max[i] = m->getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max, max + 4) + 1;
  if(physicalNumRequest > -1 && physicalNumRequest < physicalNum)
    Msg::Warning("Requested chain physical group number already taken. Using "
                 "next available.");
  else if(physicalNumRequest > -1 && physicalNumRequest >= physicalNum)
    physicalNum = physicalNumRequest;

  std::map<int, std::vector<MElement *> > entityMap;
  entityMap[entityNum] = elements;
  std::map<int, std::map<int, std::string> > physicalMap;
  std::map<int, std::string> physicalInfo;
  physicalInfo[physicalNum] = name;
  physicalMap[entityNum] = physicalInfo;
  m->storeChain(dim, entityMap, physicalMap);
  m->setPhysicalName(name, dim, physicalNum);

#if defined(HAVE_POST)
  if(post && CTX::instance()->batch == 0) {
    // create PView for instant visualization
    std::string pnum = convertInt(physicalNum);
    std::string postname = pnum + "=" + name;
    PView *view = new PView(postname, "ElementData", m, data, 0., 1);
    // the user should be interested about the orientations
    int size = 30;
    PViewOptions *opt = view->getOptions();
    opt->visible = 0;
    if(opt->tangents == 0) opt->tangents = size;
    if(opt->normals == 0) opt->normals = size;
    updateFltk();
  }
#endif

  return physicalNum;
}

#endif

#endif
