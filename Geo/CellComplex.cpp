// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "CellComplex.h"
#include "OS.h"

#if defined(HAVE_KBIPACK)

CellComplex::CellComplex( std::vector<GEntity*> domain, 
			  std::vector<GEntity*> subdomain )
{
  
  _domain = domain;
  _subdomain = subdomain;
  
  _dim = 0;
  _simplicial = true;
  
  _multidim = false;
  int dim = 0;
  for(int i = 0; i < domain.size(); i++){
    GEntity* entity = domain.at(i);
    if(i == 0) dim = entity->dim();
    if(dim != entity->dim()){
      _multidim = true;
      Msg::Warning("Domain is not a manifold.");
    }
  }
  
  // find boundary entities
  if(!_multidim) find_boundary(domain, subdomain);

  // insert cells into cell complex
  // subdomain need to be inserted first!
  insert_cells(true, true);
  insert_cells(false, true);
  insert_cells(false, false);
  

  for(int i = 0; i < 4; i++){
    _ocells[i] = _cells[i];
    _betti[i] = 0;
    if(getSize(i) > _dim) _dim = i;
  }
  
}

void CellComplex::find_boundary(std::vector<GEntity*>& domain, 
				std::vector<GEntity*>& subdomain)
{  
  // determine mesh entities on boundary of the domain
  bool duplicate = false;
  for(unsigned int j=0; j < _domain.size(); j++){
    if(_domain.at(j)->dim() == 3){
      std::list<GFace*> faces = _domain.at(j)->faces();
      for(std::list<GFace*>::iterator it = faces.begin(); it !=  faces.end();
	  it++){  
        GFace* face = *it;
        duplicate = false;
        for(std::vector<GEntity*>::iterator itb = _boundary.begin();
	    itb != _boundary.end(); itb++){
          GEntity* entity = *itb;
          if(face->tag() == entity->tag()){
            _boundary.erase(itb);
            duplicate = true;
            break;
          }
        }
        if(!duplicate) _boundary.push_back(face);
      }
    }
    else if(_domain.at(j)->dim() == 2){
      std::list<GEdge*> edges = _domain.at(j)->edges();
      
      for(std::list<GEdge*>::iterator it = edges.begin(); it !=  edges.end();
	  it++){
        GEdge* edge = *it;
        duplicate = false;
        std::vector<GEntity*>::iterator erase;
        for(std::vector<GEntity*>::iterator itb = _boundary.begin(); 
	    itb != _boundary.end(); itb++){
          GEntity* entity = *itb; 
          if(edge->tag() == entity->tag()){
            _boundary.erase(itb);
            duplicate = true;
            break;
          } 
        } 
        if(!duplicate) _boundary.push_back(edge); 
      }  
    }
    else if(_domain.at(j)->dim() == 1){
      std::list<GVertex*> vertices = _domain.at(j)->vertices();
      for(std::list<GVertex*>::iterator it = vertices.begin(); 
	  it !=  vertices.end(); it++){
        GVertex* vertex = *it;
        duplicate = false;
        for(std::vector<GEntity*>::iterator itb = _boundary.begin(); 
	    itb != _boundary.end(); itb++){
          GEntity* entity = *itb;
          if(vertex->tag() == entity->tag()){
            _boundary.erase(itb);
            duplicate = true;
            break;
          }
        }
        
        if(!duplicate) _boundary.push_back(vertex);
      }
    }
  }
}

void CellComplex::insert_cells(bool subdomain, bool boundary)
{  
  std::vector<GEntity*> domain;
  
  if(subdomain) domain = _subdomain;
  else if(boundary) domain = _boundary;
  else domain = _domain;
  
  std::vector<MVertex*> vertices;
  
  std::pair<citer, bool> insertInfo;

  // add highest dimensional cells
  for(unsigned int j=0; j < domain.size(); j++) {
    for(unsigned int i=0; i < domain.at(j)->getNumMeshElements(); i++){
      vertices.clear();
      
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumVertices(); k++){
        MVertex* vertex = domain.at(j)->getMeshElement(i)->getVertex(k);
        vertices.push_back(vertex);
      }
      
      int dim = domain.at(j)->getMeshElement(i)->getDim();
      int type = domain.at(j)->getMeshElement(i)->getTypeForMSH();
      Cell* cell;
      // simplex types
      if(type == MSH_LIN_2 || type == MSH_TRI_3 || type == MSH_TET_4
	 || type == MSH_LIN_3 || type == MSH_TRI_6 || type == MSH_TET_10 
	 || type == MSH_PNT || type == MSH_TRI_9 || type == MSH_TRI_10 
	 || type == MSH_TRI_12 || type == MSH_TRI_15 || type == MSH_TRI_15I 
	 || type == MSH_TRI_21 || type == MSH_LIN_4 || type == MSH_LIN_5 
	 || type == MSH_LIN_6 || type == MSH_TET_20 || type == MSH_TET_35 
	 || type == MSH_TET_56
         || type == MSH_TET_34 || type == MSH_TET_52 ){
        cell = new Cell(domain.at(j)->getMeshElement(i), subdomain, boundary);
      }
      else if(type == MSH_QUA_4 || type == MSH_QUA_8 || type == MSH_QUA_9){
        cell = new Cell(domain.at(j)->getMeshElement(i), subdomain, boundary);
        _simplicial = false;
      }     
      else if(type == MSH_HEX_8 || type == MSH_HEX_27 || type == MSH_HEX_20){
        cell = new Cell(domain.at(j)->getMeshElement(i), subdomain, boundary);
        _simplicial = false;
      }/* FIXME: no getFaceInfo methods for these MElements
      else if(type == MSH_PRI_6 || type == MSH_PRI_18 || type == MSH_PRI_15){
        cell = new Cell(domain.at(j)->getMeshElement(i), subdomain, boundary);
        _simplicial = false;
      }
      else if(type == MSH_PYR_5 || type == MSH_PYR_14 || type == MSH_PYR_13){
        cell = new Cell(domain.at(j)->getMeshElement(i), subdomain, boundary);
        _simplicial = false;
      }*/
      else Msg::Error("Error: mesh element %d not implemented yet! \n", type); 
      cell->setImmune(false);
      insertInfo = _cells[dim].insert(cell);
      if(!insertInfo.second) delete cell;
    }
  }

  // add lower dimensional cells recursively
  MElementFactory factory;
  for (int dim = 3; dim > 0; dim--){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      std::vector<MVertex*> vertices;
      for(int i = 0; i < cell->getNumFacets(); i++){ 
        cell->getFacetVertices(i, vertices);
        int type = cell->getTypeForMSH();
        int newtype = 0;
        //FIXME: add missing boundary cell type relations
        //FIXME: high order meshes don't work
        if(dim == 3){
          if(type == MSH_TET_4) newtype = MSH_TRI_3;
          /*else if(type == MSH_TET_10) newtype = MSH_TRI_6;
          else if(type == MSH_TET_20) newtype = MSH_TRI_9;*/
          else if(type == MSH_HEX_8) newtype = MSH_QUA_4;
          /*else if(type == MSH_HEX_20) newtype = MSH_QUA_8;
          else if(type == MSH_HEX_27) newtype = MSH_QUA_9;*/
        }
        else if(dim == 2){
           if(type == MSH_TRI_3 || type == MSH_QUA_4) newtype = MSH_LIN_2;
           /*else if(type == MSH_TRI_6 || type == MSH_QUA_8) newtype = MSH_LIN_3;
           else if(type == MSH_TRI_9) newtype = MSH_LIN_4;
           else if(type == MSH_QUA_9) newtype = MSH_LIN_3;*/
        }
        else if(dim == 1){
           if(type == MSH_LIN_2) newtype = MSH_PNT;
           /*else if(type == MSH_LIN_3 || type == MSH_LIN_4 ||
                   type == MSH_LIN_5 || type == MSH_LIN_6) newtype = MSH_PNT;*/
        }  
        if(newtype == 0){
	  Msg::Error("Error: mesh element %d not implemented yet! \n", type); }
	
	MElement* element = factory.create(newtype, vertices, 0, 
					   cell->getPartition());
        Cell* newCell = new Cell(element, subdomain, boundary);
        newCell->setImmune(cell->getImmune());
        newCell->setDeleteImage(true);
        insertInfo = _cells[dim-1].insert(newCell);
        if(!insertInfo.second){
          delete newCell; 
          Cell* oldCell = *(insertInfo.first);
          if(!subdomain && !boundary){
            int ori = cell->getFacetOri(oldCell);
            oldCell->addCoboundaryCell( ori, cell, true);
            cell->addBoundaryCell( ori, oldCell, true);
          }
        }
        else if(!subdomain && !boundary) {
          int ori = cell->getFacetOri(vertices);
          cell->addBoundaryCell( ori, newCell, true);
	  newCell->addCoboundaryCell( ori, cell, true);
	}
      }
    }
  }
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
  for(int i = 0; i < _newcells.size(); i++) delete _newcells.at(i);
  _newcells.clear();
}

/*
CellComplex::CellComplex(CellComplex* cellComplex)
{
  _domain = cellComplex->getDomain();
  _subdomain = cellComplex->getSubdomain();
  _boundary = cellComplex->getBoundary();

  for(int i = 0; i < 4; i++){
    _betti[i] = cellComplex->getBetti(i);
    _ocells[i] = cellComplex->getOcells(i);
  }
  _dim = cellComplex->getDim();
  restoreComplex();
  }*/

void CellComplex::insertCell(Cell* cell)
{
  _newcells.push_back(cell);      
  std::pair<citer, bool> insertInfo = _cells[cell->getDim()].insert(cell);
  if(!insertInfo.second) Msg::Debug("Warning: Cell not inserted! \n");
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

int CellComplex::coreduction(Cell* generator, int omitted)
{  
  int coreductions = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(generator);
  Qset.insert(generator);
  
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
  
int CellComplex::reduceComplex()
{  
  double t1 = Cpu();
  
  Msg::Debug("Cell complex before reduction: %d volumes, %d faces, %d edges and %d vertices.\n",
	     getSize(3), getSize(2), getSize(1), getSize(0));
  
  int count = 0;
  for(int i = 3; i > 0; i--) count = count + reduction(i);
    
  int omitted = 0;
  _store.clear();
    
  removeSubdomain();
  
  while (getSize(getDim()) != 0){
    
    citer cit = firstCell(getDim());
    Cell* cell = *cit;
    removeCell(cell);
    
    omitted++;
    std::set< Cell*, Less_Cell > omittedCells;
    _store.push_back(omittedCells);
    _store.at(omitted-1).insert(cell);
    for(int j = 3; j > 0; j--) reduction(j, omitted);
  }
    
  double t2 = Cpu();
  Msg::Debug("Cell complex after reduction: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
         getSize(3), getSize(2), getSize(1), getSize(0), t2 - t1);
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

int CellComplex::coreduceComplex()
{

  Msg::Debug("Cell complex before coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
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
  
  Msg::Debug("Cell complex after coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
	     getSize(3), getSize(2), getSize(1), getSize(0));
  
  return omitted;
}

void CellComplex::computeBettiNumbers()
{  
  removeSubdomain();

  for(int i = 0; i < 4; i++){
    if (getSize(i) != 0) _betti[i] = -1;
    else _betti[i] = 0;

    Msg::Debug("Betti number computation process: step %d of 4 \n", i+1);
    while (getSize(i) != 0){
      citer cit = firstCell(i);
      Cell* cell = *cit;
      /*while(!cell->inSubdomain() && cit != lastCell(i)){
        cell = *cit;
        cit++;
      }
      if(!cell->inSubdomain())*/ _betti[i] = _betti[i] + 1;
      removeCell(cell, false);
      coreduction(cell);
    }
  }
  Msg::Debug("Cell complex Betti numbers: \nH0 = %d \nH1 = %d \nH2 = %d \nH3 = %d \n",
	     getBettiNumber(0), getBettiNumber(1), 
	     getBettiNumber(2), getBettiNumber(3));
  return;
}


int CellComplex::cocombine(int dim)
{ 
  double t1 = Cpu();
  Msg::Debug("Cell complex before cocombining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
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
           && c1->getNumVertices() < getSize(dim) 
	   // heuristics for mammoth cell birth control
           && c2->getNumVertices() < getSize(dim)){
	  
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
  double t2 = Cpu();
  Msg::Debug("Cell complex after cocombining: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
         getSize(3), getSize(2), getSize(1), getSize(0), t2-t1);
  
  return count;
}

int CellComplex::combine(int dim)
{
  double t1 = Cpu();
  Msg::Debug("Cell complex before combining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
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
           && c1->getNumVertices() < getSize(dim) 
	   // heuristics for mammoth cell birth control
           && c2->getNumVertices() < getSize(dim)){

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
  double t2 = Cpu();
  Msg::Debug("Cell complex after combining: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
       getSize(3), getSize(2), getSize(1), getSize(0), t2 - t1);
  
  
  return count;
}

void CellComplex::printComplex(int dim)
{
  for (citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    cell->printCell();
    cell->printBoundary();
    cell->printCoboundary();
    printf("--- \n");
  }
}

bool CellComplex::checkCoherence()
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
          Msg::Debug("Warning! Boundary cell not in cell complex! Boundary removed. \n");
	  //cell->printCell();
          //bdCell->printCell();
          cell->removeBoundaryCell(bdCell);
          coherent = false;
        }
        if(!bdCell->hasCoboundary(cell)){
          Msg::Debug("Warning! Incoherent boundary/coboundary pair! Fixed. \n");
          /*cell->printCell();
          cell->printBoundary();
          bdCell->printCell();
          bdCell->printCoboundary();*/
          bdCell->addCoboundaryCell(ori, cell);
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
          Msg::Debug("Warning! Coboundary cell not in cell complex! Coboundary removed. \n");
          cell->printCell();
	  cbdCell->printCell();
          cell->removeCoboundaryCell(cbdCell);
          coherent = false;
        }
        if(!cbdCell->hasBoundary(cell)){
          Msg::Debug("Warning! Incoherent coboundary/boundary pair! Fixed. \n");
          cell->printCell();
          cell->printCoboundary();
          cbdCell->printCell();
          cbdCell->printBoundary();
          cbdCell->addBoundaryCell(ori, cell);
          coherent = false;
        }
        
      }
      
    }
  }
  return coherent;
}

void CellComplex::restoreComplex()
{
  for(int i = 0; i < 4; i++){
    _betti[i] = 0;
    _cells[i] = _ocells[i];
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      cell->restoreCell();
    }
  }
  _store.clear();
}

bool CellComplex::hasCell(Cell* cell, bool org)
{
  if(!org){
    citer cit = _cells[cell->getDim()].find(cell);
    if( cit == lastCell(cell->getDim()) ) return false;
    else return true;
  }
  else{
    citer cit = _ocells[cell->getDim()].find(cell);
    if( cit == lastOrgCell(cell->getDim()) ) return false;
    else return true;
  }
}

bool CellComplex::swapSubdomain()
{
  if(_multidim) return false;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      if(cell->onDomainBoundary() 
	 && cell->inSubdomain()) cell->setInSubdomain(false);
      else if(cell->onDomainBoundary() 
	      && !cell->inSubdomain()) cell->setInSubdomain(true);
    }
  }
  return true;
}

void CellComplex::makeDualComplex()
{
  std::set<Cell*, Less_Cell> temp = _cells[0];
  _cells[0] = _cells[3];
  _cells[3] = temp;
  temp = _cells[1];
  _cells[1] = _cells[2];
  _cells[2] = temp;
  
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      cell->makeDualCell();
    }
  }
}

#endif
