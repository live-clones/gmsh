// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "Cell.h"

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

int Cell::_globalNum = 0;
Cell::Cell(int dim, std::vector<MVertex*>& v) 
{  
  _pnum = 0;
  _dim = dim;
  _domain = 0;
  _combined = false;
  _immune = false;
  _v = v;
  std::sort(_v.begin(), _v.end(), MVertexLessThanNum());

  //_num = ++_globalNum;
  _num = 0;
  _index = 0;
}
/*Cell::Cell(int num, int dim, int type, std::vector<int>& v, int domain) 
{  
  _num = num;
  _dim = dim;
  _domain = domain;
  _combined = false;
  _immune = false;
  _type = type;
  _v = v;
  _index = 0;
  }*/

Cell::Cell(MElement* element, int domain)
{  
  _pnum = element->getNum();
  _dim = element->getDim();
  _domain = domain;
  _combined = false;
  _immune = false;
  int type = element->getType();
  if(type != TYPE_PNT && type != TYPE_LIN && type != TYPE_TRI && type != TYPE_TET) _type = 2;
  else _type = 1;

  for(int i = 0; i < element->getNumPrimaryVertices(); i++){
    _v.push_back(element->getVertex(i));
  }
  std::sort(_v.begin(), _v.end(), MVertexLessThanNum());

  //_num = ++_globalNum;
  _num = 0;
  _index = 0;
  
}

Cell::Cell(Cell* parent, int i)
{  
  _pnum = parent->getParentNum();
  _dim = parent->getDim()-1;
  _domain = parent->getDomain();
  _combined = false;
  _immune = false;

  parent->findBdElement(i, _type, _v);
  std::sort(_v.begin(), _v.end(), MVertexLessThanNum());

  //_num = ++_globalNum;
  _num = 0;
  _index = 0;
  
}

void Cell::findBdElement(int i, int& type, std::vector<MVertex*>& vertices) const 
{
  vertices.clear();
  type = 0;
  if(_type == 1){ 
    if(_dim == 1){ // i = 0 -> ori = -1, i = 1 -> ori = 1
      type = 1;
      vertices.push_back(_v[i]);
    }
    else if(_dim == 2){
      type = 1;
      if(i == 0){ // ori = 1
	vertices.push_back(_v[0]);
	vertices.push_back(_v[1]);
      }
      else if(i == 1){ // ori = 1
	vertices.push_back(_v[1]);
	vertices.push_back(_v[2]);
      }
      else if(i == 2){ // ori = 1
	vertices.push_back(_v[2]);
	vertices.push_back(_v[0]);
      }
    }
    else if(_dim == 3){
      type = 1;
      if(i == 0){
	vertices.push_back(_v[0]);
	vertices.push_back(_v[2]);
	vertices.push_back(_v[1]);
      }
      else if(i == 1){
	vertices.push_back(_v[0]);
	vertices.push_back(_v[1]);
	vertices.push_back(_v[3]);
      }
      else if(i == 2){
	vertices.push_back(_v[0]);
	vertices.push_back(_v[3]);
	vertices.push_back(_v[2]);
      }
      else if(i == 3){
	vertices.push_back(_v[3]);
	vertices.push_back(_v[1]);
	vertices.push_back(_v[2]);
      }
    }
  }
}
int Cell::getNumBdElements() const 
{ 
  if(_dim == 0) return 0;
  else if(_dim == 1) return 2;
  else if(_dim == 2 && _type == 1) return 3;
  else if(_dim == 3 && _type == 1) return 4;
  else return 0;
}
int Cell::findBdCellOrientation(Cell* cell) const 
{ 
  std::vector<MVertex*> v;
  cell->getMeshVertices(v);
  if(_dim == 0) return 0;
  else if(_dim == 1){
    if(v[0]->getNum() == _v[0]->getNum()) return -1;
    else if(v[0]->getNum() == _v[1]->getNum()) return 1;
  }
  else if(_type == 1){
    if(_dim == 2){
      if     (v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[1]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[0]->getNum() ) return -1;
      
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[2]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[1]->getNum() ) return -1;
      
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[0]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[2]->getNum() ) return -1;
    } 
    else if(_dim == 3) {
      if     (v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[2]->getNum() && v[2]->getNum() == _v[1]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[1]->getNum() && v[2]->getNum() == _v[2]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[1]->getNum() && v[2]->getNum() == _v[0]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[0]->getNum() && v[2]->getNum() == _v[1]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[0]->getNum() && v[2]->getNum() == _v[2]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[2]->getNum() && v[2]->getNum() == _v[0]->getNum()) return -1;
      
      
      else if(v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[1]->getNum() && v[2]->getNum() == _v[3]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[1]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[0]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[0]->getNum() && v[2]->getNum() == _v[3]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[3]->getNum() && v[1]->getNum() == _v[0]->getNum() && v[2]->getNum() == _v[1]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[3]->getNum() && v[1]->getNum() == _v[1]->getNum() && v[2]->getNum() == _v[0]->getNum()) return -1;
      
      
      else if(v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[2]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[0]->getNum() && v[1]->getNum() == _v[2]->getNum() && v[2]->getNum() == _v[3]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[3]->getNum() && v[1]->getNum() == _v[2]->getNum() && v[2]->getNum() == _v[3]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[3]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[2]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[0]->getNum() && v[2]->getNum() == _v[3]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[0]->getNum()) return -1;
      

      else if(v[0]->getNum() == _v[3]->getNum() && v[1]->getNum() == _v[1]->getNum() && v[2]->getNum() == _v[2]->getNum() ) return 1;
      else if(v[0]->getNum() == _v[3]->getNum() && v[1]->getNum() == _v[2]->getNum() && v[2]->getNum() == _v[1]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[2]->getNum() && v[2]->getNum() == _v[3]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[1]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[2]->getNum()) return -1;
      
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[3]->getNum() && v[2]->getNum() == _v[1]->getNum()) return 1;    
      else if(v[0]->getNum() == _v[2]->getNum() && v[1]->getNum() == _v[1]->getNum() && v[2]->getNum() == _v[3]->getNum()) return -1;
    }
  }
  return 0;
}

int Cell::getTypeMSH() const 
{
  if(_type == 1){
    if(_dim == 0) return 15;
    else if(_dim == 1) return 1;
    else if(_dim == 2) return 2;
    else if(_dim == 3) return 4;
  }
  else return 0;
}

bool Cell::hasVertex(int vertex) const 
{
  //_vs
  std::vector<int> v;
  for(unsigned int i = 0; i < _v.size(); i++) {
    v.push_back(_v[i]->getNum());
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
    printf("%d ", this->getVertex(i));
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
  _index = 0;
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

CombinedCell::CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co) : Cell() 
{  
  // use "smaller" cell as c2
  if(c1->getNumCells() < c2->getNumCells()){
    Cell* temp = c1;
    c1 = c2;
    c2 = temp;
  }
  
  _num = ++_globalNum;
  _index = c1->getIndex();
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
  c1->clearBoundary();
  c2->clearBoundary();

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
  c1->clearCoboundary();
  c2->clearCoboundary();
  

}

CombinedCell::CombinedCell(std::vector<Cell*>& cells) : Cell() 
{  
  _num = ++_globalNum;
  _index = cells.at(0)->getIndex();
  _domain = cells.at(0)->getDomain();
  _combined = true;

  // cells
  for(unsigned int i = 0; i < cells.size(); i++){
    Cell* c = cells.at(i);
    _cells[c] = 1;
  }
}
