// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#include "Chain.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MHexahedron.h"
#include "MPrism.h"

#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

#if defined(HAVE_KBIPACK)

void updateFltk()
{
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->updateViews(true, true);
#endif
}

std::string convertInt(int number)
{
  std::stringstream stream;
  stream << number;
  return stream.str();
}

std::map<GEntity *, std::set<MVertex *, MVertexPtrLessThan>, GEntityPtrLessThan>
  ElemChain::_vertexCache;

inline void ElemChain::_sortVertexIndices()
{
  std::map<MVertex *, int, MVertexPtrLessThan> si;

  for(std::size_t i = 0; i < _v.size(); i++) si[_v[i]] = i;

  for(auto it = si.begin(); it != si.end(); it++) _si.push_back(it->second);
}

void findEntitiesInPhysicalGroups(GModel *m,
                                  const std::vector<int> &physicalGroups,
                                  std::vector<GEntity *> &entities)
{
  std::map<int, std::vector<GEntity *> > groups[4];
  m->getPhysicalGroups(groups);
  for(std::size_t i = 0; i < physicalGroups.size(); i++) {
    bool found = false;
    for(int j = 0; j < 4; j++) {
      auto it = groups[j].find(physicalGroups.at(i));
      if(it != groups[j].end()) {
        found = true;
        std::vector<GEntity *> physicalGroup = it->second;
        for(std::size_t k = 0; k < physicalGroup.size(); k++) {
          entities.push_back(physicalGroup.at(k));
        }
      }
    }
    if(!found) {
      Msg::Error("Physical group %d does not exist", physicalGroups.at(i));
    }
  }
}

bool ElemChain::_equalVertices(const std::vector<MVertex *> &v2) const
{
  if(_v.size() != v2.size()) return false;
  for(std::size_t i = 0; i < _v.size(); i++)
    if(_v[i]->getNum() != v2[i]->getNum()) return false;
  return true;
}

ElemChain::ElemChain(MElement *e)
{
  _dim = e->getDim();
  for(std::size_t i = 0; i < e->getNumPrimaryVertices(); i++)
    _v.push_back(e->getVertex(i));
  _sortVertexIndices();
}

ElemChain::ElemChain(int dim, std::vector<MVertex *> &v) : _dim(dim), _v(v)
{
  _sortVertexIndices();
}

inline int ElemChain::getSortedVertex(int i) const
{
  return _v[(int)_si[i]]->getNum();
}

int ElemChain::getTypeMSH(int dim, int numVertices)
{
  switch(dim) {
  case 0: return MSH_PNT;
  case 1: return MSH_LIN_2;
  case 2:
    switch(numVertices) {
    case 3: return MSH_TRI_3;
    case 4: return MSH_QUA_4;
    default: return 0;
    }
  case 3:
    switch(numVertices) {
    case 4: return MSH_TET_4;
    case 5: return MSH_PYR_5;
    case 6: return MSH_PRI_6;
    case 8: return MSH_HEX_8;
    default: return 0;
    }
  default: return 0;
  }
}

int ElemChain::getTypeMSH() const
{
  return ElemChain::getTypeMSH(_dim, this->getNumVertices());
}

MElement *ElemChain::createMeshElement() const
{
  MElementFactory factory;
  std::vector<MVertex *> v(_v);
  return factory.create(this->getTypeMSH(), v);
}

int ElemChain::compareOrientation(const ElemChain &c2) const
{
  std::vector<MVertex *> v2;
  c2.getMeshVertices(v2);

  int perm = 1;
  if(this->_equalVertices(v2)) return perm;
  while(std::next_permutation(v2.begin(), v2.end(), MVertexPtrLessThan())) {
    perm *= -1;
    if(this->_equalVertices(v2)) return perm;
  }
  c2.getMeshVertices(v2);
  perm = 1;
  while(std::prev_permutation(v2.begin(), v2.end(), MVertexPtrLessThan())) {
    perm *= -1;
    if(this->_equalVertices(v2)) return perm;
  }
  return 0;
}

bool ElemChain::lessThan(const ElemChain &c2) const
{
  if(this->getNumSortedVertices() != c2.getNumSortedVertices())
    return (this->getNumSortedVertices() < c2.getNumSortedVertices());
  for(int i = 0; i < this->getNumSortedVertices(); i++) {
    if(this->getSortedVertex(i) < c2.getSortedVertex(i))
      return true;
    else if(this->getSortedVertex(i) > c2.getSortedVertex(i))
      return false;
  }
  return false;
}

int ElemChain::getNumBoundaries(int dim, int numVertices)
{
  switch(dim) {
  case 0: return 0;
  case 1: return 2;
  case 2:
    switch(numVertices) {
    case 3: return 3;
    case 4: return 4;
    default: return 0;
    }
  case 3:
    switch(numVertices) {
    case 4: return 4;
    case 5: return 5;
    case 6: return 5;
    case 8: return 6;
    default: return 0;
    }
  default: return 0;
  }
}

int ElemChain::getNumBoundaryElemChains() const
{
  return ElemChain::getNumBoundaries(_dim, this->getNumVertices());
}

void ElemChain::getBoundaryVertices(int i, int dim, int numVertices,
                                    const std::vector<MVertex *> &v,
                                    std::vector<MVertex *> &vertices)
{
  vertices.clear();
  switch(dim) {
  case 1: vertices.push_back(v[i]); return;
  case 2:
    switch(numVertices) {
    case 3:
      for(int j = 0; j < 2; j++)
        vertices.push_back(v[MTriangle::edges_tri(i, j)]);
      return;
    case 4:
      for(int j = 0; j < 2; j++)
        vertices.push_back(v[MQuadrangle::edges_quad(i, j)]);
      return;
    default: return;
    }
  case 3:
    switch(numVertices) {
    case 4:
      for(int j = 0; j < 3; j++)
        vertices.push_back(v[MTetrahedron::faces_tetra(i, j)]);
      return;
    case 5:
      if(i < 3)
        for(int j = 0; j < 3; j++)
          vertices.push_back(v[MPyramid::faces_pyramid(i, j)]);
      else
        for(int j = 0; j < 4; j++)
          vertices.push_back(v[MPyramid::faces_pyramid(i, j)]);
      return;
    case 6:
      if(i < 2)
        for(int j = 0; j < 3; j++)
          vertices.push_back(v[MPrism::faces_prism(i, j)]);
      else
        for(int j = 0; j < 4; j++)
          vertices.push_back(v[MPrism::faces_prism(i, j)]);
      return;
    case 8:
      for(int j = 0; j < 4; j++)
        vertices.push_back(v[MHexahedron::faces_hexa(i, j)]);
      return;
    default: return;
    }
  default: return;
  }
}

ElemChain ElemChain::getBoundaryElemChain(int i) const
{
  std::vector<MVertex *> vertices;
  ElemChain::getBoundaryVertices(i, _dim, this->getNumVertices(), _v, vertices);
  return ElemChain(_dim - 1, vertices);
}

bool ElemChain::inEntity(GEntity *e) const
{
  if(_vertexCache[e].empty()) {
    for(std::size_t i = 0; i < e->getNumMeshElements(); i++)
      for(std::size_t j = 0; j < e->getMeshElement(i)->getNumVertices(); j++)
        _vertexCache[e].insert(e->getMeshElement(i)->getVertex(j));
  }

  for(int i = 0; i < this->getNumVertices(); i++)
    if(!_vertexCache[e].count(this->getMeshVertex(i))) return false;
  return true;
}

#endif
