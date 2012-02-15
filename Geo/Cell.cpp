// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "Cell.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MHexahedron.h"
#include "MPrism.h"

bool Less_Cell::operator()(const Cell* c1, const Cell* c2) const
{
  // If cell complex is done use enumeration (same as vertex order)
  if(c1->getNum() != 0) return (c1->getNum() < c2->getNum());

  // Otherwise order by vertex numbering (good heuristic for reduction)
  if(c1->getNumSortedVertices() != c2->getNumSortedVertices()){
    return (c1->getNumSortedVertices() < c2->getNumSortedVertices());
  }
  for(int i=0; i < c1->getNumSortedVertices();i++){
    if(c1->getSortedVertex(i) < c2->getSortedVertex(i)) return true;
    else if (c1->getSortedVertex(i) > c2->getSortedVertex(i)) return false;
  }
  return false;
}

bool Less_VertexNumIndex::operator()(const std::pair<MVertex*, int> v1,
                                     const std::pair<MVertex*, int> v2) const
{
  return (v1.first->getNum() < v2.first->getNum());
}

int Cell::_globalNum = 0;

Cell::Cell(MElement* element, int domain)
{
  _dim = element->getDim();
  _domain = domain;
  _combined = false;
  _immune = false;
  _num = 0;

  for(int i = 0; i < element->getNumPrimaryVertices(); i++)
    _v.push_back(element->getVertex(i));

  _sortVertexIndices();
}

Cell::Cell(Cell* parent, int i)
{
  _dim = parent->getDim()-1;
  _domain = parent->getDomain();
  _combined = false;
  _immune = false;
  _num = 0;

  parent->findBdElement(i, _v);
  _sortVertexIndices();
}

void Cell::_sortVertexIndices()
{
  std::vector< std::pair<MVertex*, int> > si;

  for(unsigned int i = 0; i < _v.size(); i++)
    si.push_back( std::make_pair(_v[i], i) );

  std::sort(si.begin(), si.end(), Less_VertexNumIndex());

  for(unsigned int i = 0; i < si.size(); i++)
    _si.push_back(si[i].second);
}

inline int Cell::getSortedVertex(int vertex) const
{
  return _v[(int)_si[vertex]]->getNum();
}

void Cell::findBdElement(int i, std::vector<MVertex*>& vertices) const
{
  vertices.clear();
  switch (_dim) {
  case 1:
    vertices.push_back(_v[i]);
    return;
  case 2:
    switch (getNumVertices()) {
    case 3:
      for(int j = 0; j < 2; j++)
        vertices.push_back(_v[MTriangle::edges_tri(i, j)]);
      return;
    case 4:
      for(int j = 0; j < 2; j++)
        vertices.push_back(_v[MQuadrangle::edges_quad(i, j)]);
      return;
    default: return;
    }
  case 3:
    switch (getNumVertices()) {
    case 4:
      for(int j = 0; j < 3; j++)
        vertices.push_back(_v[MTetrahedron::faces_tetra(i, j)]);
      return;
    case 5:
      if(i < 3) {
      for(int j = 0; j < 3; j++)
        vertices.push_back(_v[MPyramid::faces_pyramid(i, j)]);
      }
      else {
        vertices.push_back(_v[0]);
        vertices.push_back(_v[3]);
        vertices.push_back(_v[2]);
        vertices.push_back(_v[1]);
      }
      return;
    case 6:
      if(i < 2)
        for(int j = 0; j < 3; j++)
          vertices.push_back(_v[MPrism::faces_prism(i, j)]);
      else
        for(int j = 0; j < 4; j++)
          vertices.push_back(_v[MPrism::faces_prism(i, j)]);
      return;
    case 8:
      for(int j = 0; j < 4; j++)
        vertices.push_back(_v[MHexahedron::faces_hexa(i, j)]);
      return;
    default: return;
    }
  default: return;
  }
}

int Cell::getNumBdElements() const
{
  switch (_dim) {
  case 0: return 0;
  case 1: return 2;
  case 2:
    switch (getNumVertices()) {
    case 3: return 3;
    case 4: return 4;
    default: return 0;
    }
  case 3:
    switch (getNumVertices()) {
    case 4: return 4;
    case 5: return 5;
    case 6: return 5;
    case 8: return 6;
    default: return 0;
    }
  default: return 0;
  }
}

int Cell::findBdCellOrientation(Cell* cell, int i) const
{
  std::vector<MVertex*> v;
  cell->getMeshVertices(v);
  switch (_dim) {
  case 0: return 0;
  case 1:
    if(v[0]->getNum() == _v[0]->getNum()) return -1;
    else if(v[0]->getNum() == _v[1]->getNum()) return 1;
    return 0;
  case 2:
    switch (getNumVertices()) {
    case 3:
      if(_v[MTriangle::edges_tri(i, 0)]->getNum() == v[0]->getNum() &&
         _v[MTriangle::edges_tri(i, 1)]->getNum() == v[1]->getNum())
        return 1;
      if(_v[MTriangle::edges_tri(i, 1)]->getNum() == v[0]->getNum() &&
         _v[MTriangle::edges_tri(i, 0)]->getNum() == v[1]->getNum())
        return -1;
    case 4:
      if(_v[MQuadrangle::edges_quad(i, 0)]->getNum() == v[0]->getNum() &&
         _v[MQuadrangle::edges_quad(i, 1)]->getNum() == v[1]->getNum())
        return 1;
      if(_v[MQuadrangle::edges_quad(i, 0)]->getNum() == v[1]->getNum() &&
         _v[MQuadrangle::edges_quad(i, 1)]->getNum() == v[0]->getNum())
        return -1;
    default: return 0;
    }
  case 3:
    switch (getNumVertices()) {
    case 4:
      if(_v[MTetrahedron::faces_tetra(i, 0)]->getNum() == v[0]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 1)]->getNum() == v[1]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 2)]->getNum() == v[2]->getNum())
        return 1;
      if(_v[MTetrahedron::faces_tetra(i, 0)]->getNum() == v[1]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 1)]->getNum() == v[2]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 2)]->getNum() == v[0]->getNum())
        return 1;
      if(_v[MTetrahedron::faces_tetra(i, 0)]->getNum() == v[2]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 1)]->getNum() == v[0]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 2)]->getNum() == v[1]->getNum())
        return 1;
      if(_v[MTetrahedron::faces_tetra(i, 0)]->getNum() == v[0]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 1)]->getNum() == v[2]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 2)]->getNum() == v[1]->getNum())
        return -1;
      if(_v[MTetrahedron::faces_tetra(i, 0)]->getNum() == v[1]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 1)]->getNum() == v[0]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 2)]->getNum() == v[2]->getNum())
        return -1;
      if(_v[MTetrahedron::faces_tetra(i, 0)]->getNum() == v[2]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 1)]->getNum() == v[1]->getNum() &&
         _v[MTetrahedron::faces_tetra(i, 2)]->getNum() == v[0]->getNum())
        return -1;
    case 5: return 0;
    case 6: return 0;
    case 8:
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[0]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[1]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[2]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[3]->getNum())
        return 1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[1]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[2]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[3]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[0]->getNum())
        return 1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[2]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[3]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[0]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[1]->getNum())
        return 1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[3]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[0]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[1]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[2]->getNum())
        return 1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[0]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[3]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[2]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[1]->getNum())
        return -1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[3]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[2]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[1]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[0]->getNum())
        return -1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[2]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[1]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[0]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[3]->getNum())
        return -1;
      if(_v[MHexahedron::faces_hexa(i, 0)]->getNum() == v[1]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 1)]->getNum() == v[0]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 2)]->getNum() == v[3]->getNum() &&
         _v[MHexahedron::faces_hexa(i, 3)]->getNum() == v[2]->getNum())
        return -1;
    default: return 0;
    }
  default: return 0;
  }
}

int Cell::getTypeMSH() const
{
  switch (_dim) {
  case 0: return MSH_PNT;
  case 1: return MSH_LIN_2;
  case 2:
    switch (getNumVertices()) {
    case 3: return MSH_TRI_3;
    case 4: return MSH_QUA_4;
    default: return 0;
    }
  case 3:
    switch (getNumVertices()) {
    case 4: return MSH_TET_4;
    case 5: return MSH_PYR_5;
    case 6: return MSH_PRI_6;
    case 8: return MSH_HEX_8;
    default: return 0;
    }
  default: return 0;
  }
}

bool Cell::hasVertex(int vertex) const
{
  std::vector<int> v;
  for(unsigned int i = 0; i < _v.size(); i++) {
    v.push_back(_v[(int)_si[i]]->getNum());
  }
  std::vector<int>::const_iterator it = std::find(v.begin(), v.end(),
						  vertex);
  if (it != v.end()) return true;
  else return false;
}

bool CombinedCell::hasVertex(int vertex) const
{
  for(std::map<Cell*, int, Less_Cell>::const_iterator cit = _cells.begin();
      cit != _cells.end(); cit++){
    if(cit->first->hasVertex(vertex)) return true;
  }
  return false;
}

void Cell::printCell()
{
  printf("%d-cell %d: \n" , getDim(), getNum());
  printf("Vertices: ");
  for(int i = 0; i < this->getNumVertices(); i++){
    printf("%d ", this->getMeshVertex(i)->getNum());
  }
  printf(", in subdomain: %d, ", inSubdomain());
  printf("combined: %d. \n" , isCombined() );
};

void Cell::restoreCell(){
  std::vector<Cell*> toRemove;
  for(biter it = firstCoboundary(true); it != lastCoboundary(); it++){
    it->second.reset();
    if(it->second.get() == 0) toRemove.push_back(it->first);
  }
  for(unsigned int i = 0; i < toRemove.size(); i++) _cbd.erase(toRemove[i]);
  toRemove.clear();
  for(biter it = firstBoundary(true); it != lastBoundary(); it++){
    it->second.reset();
    if(it->second.get() == 0) toRemove.push_back(it->first);
  }
  for(unsigned int i = 0; i < toRemove.size(); i++) _bd.erase(toRemove[i]);
  _combined = false;
  _immune = false;
}

void Cell::addBoundaryCell(int orientation, Cell* cell, bool other)
{
  biter it = _bd.find(cell);
  if(it != _bd.end()){
    int newOrientation = it->second.get() + orientation;
    it->second.set(newOrientation);
    if(newOrientation == 0){
      it->first->removeCoboundaryCell(this, false);
      if(it->second.geto() == 0) {
	_bd.erase(it);
      }
      return;
    }
  }
  else _bd.insert( std::make_pair(cell, BdInfo(orientation) ) );
  if(other) cell->addCoboundaryCell(orientation, this, false);
}

void Cell::addCoboundaryCell(int orientation, Cell* cell, bool other)
{
  biter it = _cbd.find(cell);
  if(it != _cbd.end()){
    int newOrientation = it->second.get() + orientation;
    it->second.set(newOrientation);
    if(newOrientation == 0) {
      it->first->removeBoundaryCell(this, false);
      if(it->second.geto() == 0) {
	_cbd.erase(it);
      }
      return;
    }
  }
  else _cbd.insert( std::make_pair(cell, BdInfo(orientation) ) );
  if(other) cell->addBoundaryCell(orientation, this, false);
}

void Cell::removeBoundaryCell(Cell* cell, bool other)
{
  biter it = _bd.find(cell);
  if(it != _bd.end()){
    it->second.set(0);
    if(it->second.geto() == 0) _bd.erase(it);
    if(other) it->first->removeCoboundaryCell(this, false);
  }
}

void Cell::removeCoboundaryCell(Cell* cell, bool other)
{
  biter it = _cbd.find(cell);
  if(it != _cbd.end()){
    it->second.set(0);
    if(it->second.geto() == 0) _cbd.erase(it);
    if(other) it->first->removeBoundaryCell(this, false);
  }
}

bool Cell::hasBoundary(Cell* cell, bool orig)
{
  if(!orig){
    biter it = _bd.find(cell);
    if(it != _bd.end() && it->second.get() != 0) return true;
    return false;
  }
  else{
    biter it = _bd.find(cell);
    if(it != _bd.end() && it->second.geto() != 0) return true;
    return false;
  }
}

bool Cell::hasCoboundary(Cell* cell, bool orig)
{
  if(!orig){
    biter it = _cbd.find(cell);
    if(it != _cbd.end() && it->second.get() != 0) return true;
    return false;
  }
  else{
    biter it = _cbd.find(cell);
    if(it != _cbd.end() && it->second.geto() != 0) return true;
    return false;
  }
}
/*
void Cell::printBoundary(bool orig)
{
  for(biter it = firstBoundary(orig); it != lastBoundary(orig); it++){
    printf("Boundary cell orientation: %d ", (*it).second);
    Cell* cell2 = (*it).first;
    cell2->printCell();
  }
  if(firstBoundary(orig) == lastBoundary(orig)){
    printf("Cell boundary is empty. \n");
  }
}

void Cell::printCoboundary(bool orig)
{
  for(biter it = firstCoboundary(orig); it != lastCoboundary(orig); it++){
    printf("Coboundary cell orientation: %d, ", (*it).second);
    Cell* cell2 = (*it).first;
    cell2->printCell();
    if(firstCoboundary(orig) == lastCoboundary(orig)){
      printf("Cell coboundary is empty. \n");
    }
  }
  }*/

CombinedCell::CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co)
{
  // use "smaller" cell as c2
  if(c1->getNumCells() < c2->getNumCells()){
    Cell* temp = c1;
    c1 = c2;
    c2 = temp;
  }

  _num = ++_globalNum;
  _domain = c1->getDomain();
  _combined = true;
  _immune = false;

  // cells
  c1->getCells(_cells);
  std::map< Cell*, int, Less_Cell > c2Cells;
  c2->getCells(c2Cells);
  for(citer cit  = c2Cells.begin(); cit != c2Cells.end(); cit++){
    if(!orMatch) (*cit).second = -1*(*cit).second;
    _cells.insert(*cit);
  }

  // boundary cells
  for(biter it = c1->firstBoundary(); it != c1->lastBoundary(); it++){
    Cell* cell = it->first;
    int ori = it->second.get();
    if(ori == 0) continue;
    cell->removeCoboundaryCell(c1, false);
    this->addBoundaryCell(ori, cell, true);
  }
  for(biter it = c2->firstBoundary(); it != c2->lastBoundary(); it++){
    Cell* cell = it->first;
    if(!orMatch) it->second.set(-1*it->second.get());
    int ori = it->second.get();
    if(ori == 0) continue;
    cell->removeCoboundaryCell(c2, false);
    if(co && !c1->hasBoundary(cell)){
      this->addBoundaryCell(ori, cell, true);
    }
    else if(!co) this->addBoundaryCell(ori, cell, true);
  }

  // coboundary cells
  for(biter it = c1->firstCoboundary(); it != c1->lastCoboundary(); it++){
    Cell* cell = it->first;
    int ori = it->second.get();
    if(ori == 0) continue;
    cell->removeBoundaryCell(c1, false);
    this->addCoboundaryCell(ori, cell, true);
  }
  for(biter it = c2->firstCoboundary(); it != c2->lastCoboundary(); it++){
    Cell* cell = it->first;
    if(!orMatch) it->second.set(-1*it->second.get());
    int ori = it->second.get();
    if(ori == 0) continue;
    cell->removeBoundaryCell(c2, false);
    if(!co && !c1->hasCoboundary(cell)){
      this->addCoboundaryCell(ori, cell, true);
    }
    else if(co) this->addCoboundaryCell(ori, cell, true);
  }

}

CombinedCell::CombinedCell(std::vector<Cell*>& cells)
{
  _num = ++_globalNum;
  _domain = cells.at(0)->getDomain();
  _combined = true;
  _immune = false;

  // cells
  for(unsigned int i = 0; i < cells.size(); i++){
    Cell* c = cells.at(i);
    _cells[c] = 1;
  }
}
