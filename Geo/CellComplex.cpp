// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "CellComplex.h"

#if defined(HAVE_KBIPACK)

CellComplex::CellComplex( std::vector<MElement*>& domainElements, 
			  std::vector<MElement*>& subdomainElements)
{
  _dim = 0;
  _simplicial = true;

  // insert cells into cell complex
  // subdomain needs to be inserted first!
  if(!insert_cells(subdomainElements, true)){ panic_exit(); return; }
  if(!insert_cells(domainElements, false)) { panic_exit(); return; }

  for(int i = 0; i < 4; i++){
    _ocells[i] = _cells[i];
    if(getSize(i) > _dim) _dim = i;
  }  
}

void CellComplex::panic_exit(){
  for(int i = 0; i < 4; i++){
    _cells[i].clear();
    for(citer cit = _ocells[i].begin(); cit != _ocells[i].end(); cit++){
      Cell* cell = *cit;
      delete cell;
    }
    _ocells[i].clear();
  }
  for(unsigned int i = 0; i < _newcells.size(); i++) delete _newcells.at(i);
  _newcells.clear();
  printf("ERROR: No proper cell complex could be constructed!\n");
}

bool CellComplex::insert_cells(std::vector<MElement*>& elements,
			       bool subdomain)
{
  // add highest dimensional cells
  for(unsigned int i=0; i < elements.size(); i++){
    MElement* element = elements.at(i);    
    
    int type = element->getType();   
    if(_simplicial && !(type == TYPE_PNT || type == TYPE_LIN 
		     || type == TYPE_TRI || type == TYPE_TET) ){
      _simplicial = false;
    }
    //FIXME: no getFaceInfo methods for these MElements
    if(type == TYPE_PYR){
      printf("ERROR: mesh element %d not implemented! \n", type);
      return false;
    }
    Cell* cell = new Cell(element);
    cell->setInSubdomain(subdomain);
    std::pair<citer, bool> insertInfo = _cells[cell->getDim()].insert(cell);
    if(!insertInfo.second) delete cell;  
  }
  
  // add lower dimensional cells recursively
  for (int dim = 3; dim > 0; dim--){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      std::vector<Cell*> bdCells;
      if(!cell->findBoundaryCells(bdCells)) return false;
      for(unsigned int i = 0; i < bdCells.size(); i++){
	Cell* newCell = bdCells.at(i);
	newCell->setInSubdomain(subdomain);
	newCell->setDeleteImage(true);
	std::pair<citer, bool> insertInfo = 
	  _cells[newCell->getDim()].insert(newCell);
	if(!insertInfo.second){ // the cell was already in the cell complex
	  delete newCell; 
	  newCell = *(insertInfo.first); 
	}
	if(!subdomain) {
	  int ori = cell->getFacetOri(newCell);
	  cell->addBoundaryCell( ori, newCell, true, true);
	}
      }
    }
  }
  return true;
}

CellComplex::~CellComplex()
{
  for(int i = 0; i < 4; i++){
    _cells[i].clear();
    
    for(citer cit = _ocells[i].begin(); cit != _ocells[i].end(); cit++){
      Cell* cell = *cit;
      delete cell;
    }
    _ocells[i].clear();
    
  }
  for(unsigned int i = 0; i < _newcells.size(); i++) delete _newcells.at(i);
  _newcells.clear();
}

void CellComplex::insertCell(Cell* cell)
{
  _newcells.push_back(cell);      
  std::pair<citer, bool> insertInfo = _cells[cell->getDim()].insert(cell);
  if(!insertInfo.second) printf("Warning: Cell not inserted! \n");
}

void CellComplex::removeCell(Cell* cell, bool other)
{  
  std::map<Cell*, int, Less_Cell > coboundary;
  cell->getCoboundary(coboundary);
  std::map<Cell*, int, Less_Cell > boundary; 
  cell->getBoundary(boundary);
  
  for(Cell::biter it = coboundary.begin(); it != coboundary.end(); it++){
    Cell* cbdCell = (*it).first;
    cbdCell->removeBoundaryCell(cell, other);
  } 
  
  for(Cell::biter it = boundary.begin(); it != boundary.end(); it++){
    Cell* bdCell = (*it).first;
    bdCell->removeCoboundaryCell(cell, other);
  }
  
  _cells[cell->getDim()].erase(cell); 
}

void CellComplex::removeCellQset(Cell* cell, 
				 std::set<Cell*, Less_Cell>& Qset)
{
  Qset.erase(cell);
}

void CellComplex::enqueueCells(std::map<Cell*, int, Less_Cell>& cells, 
			       std::queue<Cell*>& Q,
			       std::set<Cell*, Less_Cell>& Qset)
{
  for(std::map<Cell*, int, Less_Cell>::iterator cit = cells.begin();
      cit != cells.end(); cit++){
    Cell* cell = (*cit).first;
    citer it = Qset.find(cell);
    if(it == Qset.end()){
      Qset.insert(cell);
      Q.push(cell);
    }
  }
}

int CellComplex::coreduction(Cell* startCell, int omitted)
{  
  int coreductions = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(startCell);
  Qset.insert(startCell);
  
  std::map<Cell*, int, Less_Cell > bd_s;
  std::map<Cell*, int, Less_Cell > cbd_c;

  Cell* s;
  int round = 0;
  while( !Q.empty() ){
    s = Q.front();
    Q.pop();
    removeCellQset(s, Qset);
    if(s->getBoundarySize() == 1 
       && inSameDomain(s, s->firstBoundary()->first) ){
      s->getBoundary(bd_s);
      removeCell(s);
      bd_s.begin()->first->getCoboundary(cbd_c);
      enqueueCells(cbd_c, Q, Qset);
      removeCell(bd_s.begin()->first);
      if(bd_s.begin()->first->getDim() == 0 && omitted > 0){
	_store.at(omitted-1).insert(bd_s.begin()->first);
      }
      coreductions++;
    }
    else if(s->getBoundarySize() == 0){
      s->getCoboundary(cbd_c);
      enqueueCells(cbd_c, Q, Qset);
    }
  }
  return coreductions;
}

int CellComplex::reduction(int dim, int omitted)
{
  if(dim < 1 || dim > 3) return 0;

  int count = 0;
  
  bool reduced = true;
  bool ignoreCells = true;
  while (reduced){

    reduced = false;
    citer cit = firstCell(dim-1);
    while(cit != lastCell(dim-1)){
      Cell* cell = *cit;
      if( cell->getCoboundarySize() == 1 
	  && inSameDomain(cell, cell->firstCoboundary()->first)){
	++cit;
	if(dim == getDim() && omitted > 0){
	  _store.at(omitted-1).insert(cell->firstCoboundary()->first);    
	}
	removeCell(cell->firstCoboundary()->first);
	removeCell(cell);
	count++;
	reduced = true;
      }
    
      if(getSize(dim) == 0 || getSize(dim-1) == 0) break;
      cit++;
    }
  }
  return count;
}

int CellComplex::coreduction(int dim, int omitted)
{
  if(dim < 1 || dim > 3) return 0;

  int count = 0;

  bool reduced = true;
  bool ignoreCells = true;
  while (reduced){

    reduced = false;
    citer cit = firstCell(dim);
    while(cit != lastCell(dim)){
      Cell* cell = *cit;
      if( cell->getBoundarySize() == 1
          && inSameDomain(cell, cell->firstBoundary()->first)){
        ++cit;
	if(dim-1 == 0 && omitted > 0){
	  _store.at(omitted-1).insert(cell->firstBoundary()->first);
	}
        removeCell(cell->firstBoundary()->first);
        removeCell(cell);
        count++;
        reduced = true;
      }

      if(getSize(dim) == 0 || getSize(dim-1) == 0) break;
      cit++;
    }
  }
  return count;
}
  
int CellComplex::reduceComplex(bool omit)
{  
  printf("Cell Complex: \n %d volumes, %d faces, %d edges and %d vertices. \n",
	 getSize(3), getSize(2), getSize(1), getSize(0));

  int count = 0;
  for(int i = 3; i > 0; i--) count = count + reduction(i);

  if(omit){
    int omitted = 0;
    _store.clear();
    
    removeSubdomain();
    
    while (getSize(getDim()) != 0){
      
      citer cit = firstCell(getDim());
      Cell* cell = *cit;
      removeCell(cell, false);
      
      omitted++;
      std::set< Cell*, Less_Cell > omittedCells;
      _store.push_back(omittedCells);
      _store.at(omitted-1).insert(cell);
      for(int j = 3; j > 0; j--) reduction(j, omitted);
    }
  }
  
  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
       getSize(3), getSize(2), getSize(1), getSize(0));

  combine(3);
  reduction(2);
  combine(2);
  reduction(1);
  combine(1);
  
  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
	 getSize(3), getSize(2), getSize(1), getSize(0));
  
  return 0;
}

void CellComplex::removeSubdomain()
{
  std::vector<Cell*> toRemove;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); ++cit){
      Cell *cell = *cit;
      if(cell->inSubdomain()) toRemove.push_back(cell);
    }
  }
  for(unsigned int i = 0; i < toRemove.size(); i++) removeCell(toRemove[i]);
}

int CellComplex::coreduceComplex(bool omit)
{
  printf("Cell Complex: \n %d volumes, %d faces, %d edges and %d vertices. \n",
	 getSize(3), getSize(2), getSize(1), getSize(0));
  
  int count = 0;
  removeSubdomain();
  
  for(int dim = 0; dim < 4; dim++){
    citer cit = firstCell(dim);
    while(cit != lastCell(dim)){
      Cell* cell = *cit;
      count = count + coreduction(cell);
      if(count != 0) break;
      cit++;
    }
  } 
  
  int omitted = 0;
  if(omit){
    _store.clear();
    
    while (getSize(0) != 0){
      citer cit = firstCell(0);
      Cell* cell = *cit;
      
      removeCell(cell, false);
      std::set< Cell*, Less_Cell > omittedCells;
      omitted++;
      _store.push_back(omittedCells);
      _store.at(omitted-1).insert(cell);
      coreduction(cell, omitted);
    }
  }

  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
	 getSize(3), getSize(2), getSize(1), getSize(0));
  
  cocombine(0);
  coreduction(1);
  cocombine(1);
  coreduction(2);
  cocombine(2);
  coreduction(3);
  coherent();

  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
	 getSize(3), getSize(2), getSize(1), getSize(0));

  return omitted;
}

int CellComplex::cocombine(int dim)
{ 
  //printf("Cell complex before cocombining: %d volumes, %d faces, %d edges and %d vertices.\n", getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 0 || dim > 2) return 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::map<Cell*, int, Less_Cell> cbd_c;
  int count = 0;
  
  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    cell->getCoboundary(cbd_c);
    enqueueCells(cbd_c, Q, Qset);

    while(Q.size() != 0){
      Cell* s = Q.front();
      Q.pop();
      if(s->getBoundarySize() == 2){
	Cell::biter it = s->firstBoundary();
        int or1 = (*it).second;
        Cell* c1 = (*it).first;
        it++;
        int or2 = (*it).second;
        Cell* c2 = (*it).first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2)
           && inSameDomain(s, c1) && inSameDomain(s, c2)
           && c1->getNumSortedVertices() < getSize(dim) 
	   // heuristics for mammoth cell birth control
           && c2->getNumSortedVertices() < getSize(dim)){

	  removeCell(s);
          
          c1->getCoboundary(cbd_c);
          enqueueCells(cbd_c, Q, Qset);
          c2->getCoboundary(cbd_c);
          enqueueCells(cbd_c, Q, Qset);
          
          CombinedCell* newCell = new CombinedCell(c1, c2, 
						   (or1 != or2), true );
          removeCell(c1);
          removeCell(c2);
          insertCell(newCell);
          
          cit = firstCell(dim);
          count++;
        }
      }
      removeCellQset(s, Qset);
      
    }
  }
  //printf("Cell complex after cocombining: %d volumes, %d faces, %d edges and %d vertices.\n", getSize(3), getSize(2), getSize(1), getSize(0));
  
  return count;
}

int CellComplex::combine(int dim)
{
  //printf("Cell complex before combining: %d volumes, %d faces, %d edges and %d vertices.\n",  getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 1 || dim > 3) return 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::map<Cell*, int, Less_Cell> bd_c;
  int count = 0;

  
  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    cell->getBoundary(bd_c);
    enqueueCells(bd_c, Q, Qset);

    while(Q.size() != 0){
      
      Cell* s = Q.front();
      Q.pop(); 

      if(s->getCoboundarySize() == 2){
	Cell::biter it = s->firstCoboundary();
        int or1 = (*it).second;
        Cell* c1 = (*it).first;
        it++;
        int or2 = (*it).second;
        Cell* c2 = (*it).first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2)
           && inSameDomain(s, c1) && inSameDomain(s, c2)
           && c1->getNumSortedVertices() < getSize(dim) 
	   // heuristics for mammoth cell birth control
           && c2->getNumSortedVertices() < getSize(dim)){

          removeCell(s);
          
          c1->getBoundary(bd_c);
          enqueueCells(bd_c, Q, Qset);
          c2->getBoundary(bd_c);
          enqueueCells(bd_c, Q, Qset);

          CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2) );
          removeCell(c1);
          removeCell(c2);
          insertCell(newCell);
	  
          cit = firstCell(dim);
          count++;
        }
      }
      removeCellQset(s, Qset);
      
    }
  }
  //printf("Cell complex after combining: %d volumes, %d faces, %d edges and %d vertices.\n", getSize(3), getSize(2), getSize(1), getSize(0));
  
  
  return count;
}

bool CellComplex::coherent()
{
  bool coherent = true;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      std::map<Cell*, int, Less_Cell> boundary;
      cell->getBoundary(boundary);
      for(Cell::biter it = boundary.begin();
	  it != boundary.end(); it++){
        Cell* bdCell = (*it).first;
        int ori = (*it).second;
        citer cit = _cells[bdCell->getDim()].find(bdCell);
        if(cit == lastCell(bdCell->getDim())){ 
	  printf("Warning! Boundary cell not in cell complex! Boundary removed. \n");
          cell->removeBoundaryCell(bdCell);
          coherent = false;
        }
        if(!bdCell->hasCoboundary(cell)){
          printf("Warning! Incoherent boundary/coboundary pair! Fixed. \n");
	  bdCell->addCoboundaryCell(ori, cell, false, false);
          coherent = false;
        }
        
      }
      std::map<Cell*, int, Less_Cell> coboundary;
      cell->getCoboundary(coboundary);
      for(Cell::biter it = coboundary.begin();
	  it != coboundary.end(); it++){
        Cell* cbdCell = (*it).first;
        int ori = (*it).second;
        citer cit = _cells[cbdCell->getDim()].find(cbdCell);
        if(cit == lastCell(cbdCell->getDim())){ 
          printf("Warning! Coboundary cell not in cell complex! Coboundary removed. \n");
	  cell->removeCoboundaryCell(cbdCell);
          coherent = false;
        }
        if(!cbdCell->hasBoundary(cell)){
          printf("Warning! Incoherent coboundary/boundary pair! Fixed. \n");
	  cbdCell->addBoundaryCell(ori, cell, false, false);
          coherent = false;
        }
        
      }
      
    }
  }
  return coherent;
}

bool CellComplex::hasCell(Cell* cell, bool orig)
{
  citer cit;
  if(!orig) cit = _cells[cell->getDim()].find(cell);
  else cit = _ocells[cell->getDim()].find(cell);
  if( cit == lastCell(cell->getDim(), orig) ) return false;
  else return true;
}

void  CellComplex::getCells(std::set<Cell*, Less_Cell>& cells, 
			    int dim, int domain){
  cells.clear();
  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    if( (domain == 0 && !cell->inSubdomain()) || domain == 1
	|| (domain == 2 && cell->inSubdomain()) ){
      cells.insert(cell);
    }
  }
}

void CellComplex::restoreComplex()
{
  for(int i = 0; i < 4; i++){
    _cells[i] = _ocells[i];
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      cell->restoreCell();
    }
  }
  for(unsigned int i = 0; i < _newcells.size(); i++){
    Cell* cell = _newcells.at(i);
    delete cell;
  }
  _newcells.clear();
  _store.clear();
}

void CellComplex::printComplex(int dim)
{
  for (citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    cell->printCell();
    cell->printBoundary();
    cell->printCoboundary();
    //printf("--- \n");
  }
}

#endif
