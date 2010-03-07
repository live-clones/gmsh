// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "CellComplex.h"
#include "Cell.h"

#if defined(HAVE_KBIPACK)

bool Less_Cell::operator()(const Cell* c1, const Cell* c2) const 
{  
  //cells with fever vertices first
  
  if(c1->getNumVertices() != c2->getNumVertices()){
    return (c1->getNumVertices() < c2->getNumVertices());
  }

  // "natural number" -like ordering 
  // (the number of a vertice corresponds a digit)
  
  for(int i=0; i < c1->getNumVertices();i++){
    if(c1->getSortedVertex(i) < c2->getSortedVertex(i)) return true;
    else if (c1->getSortedVertex(i) > c2->getSortedVertex(i)) return false;
  }
  
  return false;
}


Cell::Cell(MElement* image) :  
  _combined(false), _index(0), _immune(false), _image(NULL), 
  _deleteImage(false), _inSubdomain(false) 
{
  _dim = image->getDim();
  _image = image;
  for(int i = 0; i < image->getNumVertices(); i++) 
    _vs.push_back(image->getVertex(i)->getNum()); 
  std::sort(_vs.begin(), _vs.end());
}

Cell::~Cell() 
{
  if(_deleteImage) delete _image; 
}

bool Cell::hasVertex(int vertex) const 
{
  std::vector<int>::const_iterator it = std::find(_vs.begin(), _vs.end(), 
						  vertex);
  if (it != _vs.end()) return true;
  else return false;
}

int Cell::getNumFacets() const 
{ 
  if(getDim() == 0) return 0;
  else if(getDim() == 1) return 2;
  else if(getDim() == 2) return _image->getNumEdges();
  else if(getDim() == 3) return _image->getNumFaces();
  else return 0;
}

void Cell::getFacetVertices(const int num, std::vector<MVertex*> &v) const 
{
  if(getDim() == 0) return;
  else if(getDim() == 1) { v.resize(1); v[0] = getVertex(num); }
  else if(getDim() == 2) _image->getEdgeVertices(num, v);
  else if(getDim() == 3) _image->getFaceVertices(num, v);
  return;
}

int Cell::getFacetOri(std::vector<MVertex*> &v) 
{
  if(getDim() == 0) return 0;
  else if(getDim() == 1){
    if(v.size() != 1) return 0;
    else if(v[0] == getVertex(0)) return -1;
    else if(v[0] == getVertex(1)) return 1;
    else return 0;
  }
  else if(getDim() == 2){
    if(v.size() != 2) return 0;
    MEdge facet = MEdge(v[0], v[1]);
    int ithFacet = 0;
    int sign = 0;
    _image->getEdgeInfo(facet, ithFacet, sign);
    return sign;
  }
  else if(getDim() == 3){
    if(v.size() != 3) return 0;
    MFace facet = MFace(v);
    int ithFacet = 0;
    int sign = 0;
    int rot = 0;
    _image->getFaceInfo(facet, ithFacet, sign, rot);
    return sign;
  }
  else return 0;
}  

void Cell::printCell() 
{
  printf("%d-cell: \n" , getDim());
  printf("Vertices: ");
  for(int i = 0; i < this->getNumVertices(); i++){
    printf("%d ", this->getSortedVertex(i));
  }
  printf(", in subdomain: %d\n", _inSubdomain);
  printf("Combined: %d \n" , isCombined() );
};

void Cell::restoreCell(){
  _boundary = _obd;
  _coboundary = _ocbd;
  _combined = false;
  _index = 0;
  _immune = false;   
}

bool Cell::addBoundaryCell(int orientation, Cell* cell, bool org) 
{
  if(org) _obd.insert( std::make_pair(cell, orientation ) );
  biter it = _boundary.find(cell);
  if(it != _boundary.end()){
    (*it).second = (*it).second + orientation;
    if((*it).second == 0) {
      _boundary.erase(it);
      (*it).first->removeCoboundaryCell(this,false);
      return false;
    }
    return true;
  }
  _boundary.insert( std::make_pair(cell, orientation ) );
  return true;
}

bool Cell::addCoboundaryCell(int orientation, Cell* cell, bool org) 
{
  if(org) _ocbd.insert( std::make_pair(cell, orientation ) );
  biter it = _coboundary.find(cell);
  if(it != _coboundary.end()){
    (*it).second = (*it).second + orientation;
    if((*it).second == 0) {
      _coboundary.erase(it);
      (*it).first->removeBoundaryCell(this,false);
      return false;
    }
    return true;
  }
  _coboundary.insert( std::make_pair(cell, orientation ) );
  return true;
}

int Cell::removeBoundaryCell(Cell* cell, bool other) 
{
  biter it = _boundary.find(cell);
  if(it != _boundary.end()){
    _boundary.erase(it);
    if(other) (*it).first->removeCoboundaryCell(this, false);
    return (*it).second;
  }
  
  return 0;
}
 
int Cell::removeCoboundaryCell(Cell* cell, bool other) 
{
  biter it = _coboundary.find(cell);
  if(it != _coboundary.end()){
    _coboundary.erase(it);
    if(other) (*it).first->removeBoundaryCell(this, false);
    return (*it).second;
  }
  return 0;
}
   
bool Cell::hasBoundary(Cell* cell, bool org)
{
  if(!org){
    biter it = _boundary.find(cell);
    if(it != _boundary.end()) return true;
    return false;
  }
  else{
    biter it = _obd.find(cell);
    if(it != _obd.end()) return true;
    return false;
  }
}

bool Cell::hasCoboundary(Cell* cell, bool org)
{
  if(!org){
    biter it = _coboundary.find(cell);
    if(it != _coboundary.end()) return true;
    return false;
  }
  else{
    biter it = _ocbd.find(cell);
    if(it != _ocbd.end()) return true;
    return false;
  } 
}

void Cell::printBoundary(bool org) 
{  
  for(biter it = firstBoundary(org); it != lastBoundary(org); it++){
    printf("Boundary cell orientation: %d ", (*it).second);
    Cell* cell2 = (*it).first;
    cell2->printCell();
  }
  if(firstBoundary(org) == lastBoundary(org)){
    printf("Cell boundary is empty. \n");
  }
}

void Cell::printCoboundary(bool org) 
{
  for(biter it = firstCoboundary(org); it != lastCoboundary(org); it++){
    printf("Coboundary cell orientation: %d, ", (*it).second);
    Cell* cell2 = (*it).first;
    cell2->printCell();
    if(firstCoboundary(org) == lastCoboundary(org)){
      printf("Cell coboundary is empty. \n");
    }
  }
}

CombinedCell::CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co) : Cell() 
{  
  // use "smaller" cell as c2
  if(c1->getNumVertices() < c2->getNumVertices()){
    Cell* temp = c1;
    c1 = c2;
    c2 = temp;
  }
  
  _index = c1->getIndex();
  _dim = c1->getDim();
  _inSubdomain = c1->inSubdomain();
  _combined = true;
  _image = NULL;

  // vertices
  _vs.reserve(c1->getNumVertices() + c2->getNumVertices());
  for(int i = 0; i < c1->getNumVertices(); i++){
    _vs.push_back(c1->getSortedVertex(i));
  }
  std::vector<int> v;
  for(int i = 0; i < c2->getNumVertices(); i++){
    if(!this->hasVertex(c2->getSortedVertex(i))){
      v.push_back(c2->getSortedVertex(i)); 
    }
  }
  for(unsigned int i = 0; i < v.size(); i++) _vs.push_back(v.at(i));
  std::sort(_vs.begin(), _vs.end());
 
  // cells
  c1->getCells(_cells);
  std::list< std::pair<int, Cell*> > c2Cells;
  c2->getCells(c2Cells);
  for(std::list< std::pair<int, Cell*> >::iterator it = c2Cells.begin();
      it != c2Cells.end(); it++){
    if(!orMatch) (*it).first = -1*(*it).first;
    _cells.push_back(*it);
  }

  // boundary cells
  std::map< Cell*, int, Less_Cell > c1Boundary;
  c1->getBoundary(c1Boundary);
  std::map< Cell*, int, Less_Cell > c2Boundary; 
  c2->getBoundary(c2Boundary);
  
  for(biter it = c1Boundary.begin(); it != c1Boundary.end(); it++){
    Cell* cell = (*it).first;
    int ori = (*it).second;
    cell->removeCoboundaryCell(c1); 
    if(this->addBoundaryCell(ori, cell)) cell->addCoboundaryCell(ori, this);
  }
  for(biter it = c2Boundary.begin(); it != c2Boundary.end(); it++){
    Cell* cell = (*it).first;
    if(!orMatch) (*it).second = -1*(*it).second;
    int ori = (*it).second;
    cell->removeCoboundaryCell(c2);    
    if(co){
      biter it2 = c1Boundary.find(cell);
      if(it2 == c1Boundary.end() && this->addBoundaryCell(ori, cell)) { 
	cell->addCoboundaryCell(ori, this);
      }
    }
    else{
      if(this->addBoundaryCell(ori, cell)) cell->addCoboundaryCell(ori, this);
    }
  }

  // coboundary cells
  std::map<Cell*, int, Less_Cell > c1Coboundary;
  c1->getCoboundary(c1Coboundary);
  std::map<Cell*, int, Less_Cell > c2Coboundary;
  c2->getCoboundary(c2Coboundary);
  
  for(biter it = c1Coboundary.begin(); it != c1Coboundary.end(); it++){
    Cell* cell = (*it).first;
    int ori = (*it).second;
    cell->removeBoundaryCell(c1); 
    if(this->addCoboundaryCell(ori, cell)) cell->addBoundaryCell(ori, this);
  }
  for(biter it = c2Coboundary.begin(); it != c2Coboundary.end(); it++){
    Cell* cell = (*it).first;
    if(!orMatch) (*it).second = -1*(*it).second;
    int ori = (*it).second;
    cell->removeBoundaryCell(c2);    
    if(!co){
      biter it2 = c1Coboundary.find(cell);
      if(it2 == c1Coboundary.end() && this->addCoboundaryCell(ori, cell)){
	cell->addBoundaryCell(ori, this); 
      }
    }
    else {
      if(this->addCoboundaryCell(ori, cell)) cell->addBoundaryCell(ori, this);
    }
  }

}

#endif
