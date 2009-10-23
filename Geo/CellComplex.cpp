// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.

#include "CellComplex.h"
#include "OS.h"

#if defined(HAVE_KBIPACK)

CellComplex::CellComplex( std::vector<GEntity*> domain, std::vector<GEntity*> subdomain ){
  
  _domain = domain;
  _subdomain = subdomain;
  
  _dim = 0;
  
  // determine mesh entities on boundary of the domain
  bool duplicate = false;
  for(unsigned int j=0; j < _domain.size(); j++){
    if(_domain.at(j)->dim() == 3){
      std::list<GFace*> faces = _domain.at(j)->faces();
      for(std::list<GFace*>::iterator it = faces.begin(); it !=  faces.end(); it++){  
        GFace* face = *it;
        duplicate = false;
        for(std::vector<GEntity*>::iterator itb = _boundary.begin(); itb != _boundary.end(); itb++){
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
      
      for(std::list<GEdge*>::iterator it = edges.begin(); it !=  edges.end(); it++){
        GEdge* edge = *it;
        duplicate = false;
        std::vector<GEntity*>::iterator erase;
        for(std::vector<GEntity*>::iterator itb = _boundary.begin(); itb != _boundary.end(); itb++){
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
      for(std::list<GVertex*>::iterator it = vertices.begin(); it !=  vertices.end(); it++){
        GVertex* vertex = *it;
        duplicate = false;
        for(std::vector<GEntity*>::iterator itb = _boundary.begin(); itb != _boundary.end(); itb++){
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
  // insert cells into cell complex
  // subdomain need to be inserted first!
  insert_cells(true, true);
  insert_cells(false, true);
  insert_cells(false, false);

  // find mesh vertices in the domain
  for(unsigned int j=0; j < domain.size(); j++) {  
    for(unsigned int i=0; i < domain.at(j)->getNumMeshElements(); i++){
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumVertices(); k++){
        MVertex* vertex = domain.at(j)->getMeshElement(i)->getVertex(k);
        _domainVertices.insert(vertex);
      }
    }
  }

  for(unsigned int j=0; j < subdomain.size(); j++) {
    for(unsigned int i=0; i < subdomain.at(j)->getNumMeshElements(); i++){
      for(int k=0; k < subdomain.at(j)->getMeshElement(i)->getNumVertices(); k++){
        MVertex* vertex = subdomain.at(j)->getMeshElement(i)->getVertex(k);
        _domainVertices.insert(vertex);
      }
    }
  }
  

  // attach individual tags to cells
  int tag = 1;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      //Cell* cell = *cit;
      //cell->setTag(tag);
      tag++;
    }
    _ocells[i] = _cells[i];
    _betti[i] = 0;
    if(getSize(i) > _dim) _dim = i;
  }
  
  
}

void CellComplex::insert_cells(bool subdomain, bool boundary){

  // works only for simplicial meshes at the moment!
  
  std::vector<GEntity*> domain;
  
  if(subdomain) domain = _subdomain;
  else if(boundary) domain = _boundary;
  else domain = _domain;
  
  std::vector<MVertex*> vertices;
  
  std::pair<citer, bool> insertInfo;
  int tag = 1;

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
      if(type == MSH_LIN_2 || type == MSH_TRI_3 || type == MSH_TET_4 || type == MSH_LIN_3 || type == MSH_TRI_6 || 
         type == MSH_TET_10 || type == MSH_PNT || type == MSH_TRI_9 || type == MSH_TRI_10 || type == MSH_TRI_12 || 
         type == MSH_TRI_15 || type == MSH_TRI_15I || type == MSH_TRI_21 || type == MSH_LIN_4 ||
         type == MSH_LIN_5 || type == MSH_LIN_6 || type == MSH_TET_20 || type == MSH_TET_35 || type == MSH_TET_56
         || type == MSH_TET_34 || type == MSH_TET_52 ){
        if(dim == 3) cell = new ThreeSimplex(vertices, tag, subdomain, boundary); 
        else if(dim == 2) cell = new TwoSimplex(vertices, tag, subdomain, boundary);
        else if(dim == 1) cell = new OneSimplex(vertices, tag, subdomain, boundary);
        else cell = new ZeroSimplex(vertices, tag, subdomain, boundary);
      }
      else if(type == MSH_QUA_4 || type == MSH_QUA_8 || type == MSH_QUA_9){
        cell = new CQuadrangle(vertices, tag, subdomain, boundary);
      }
      /*
      else if(type == MSH_HEX_8 || type == MSH_HEX_27 || type == MSH_HEX_20){
        cell = new CHexahedron(vertices, tag, subdomain, boundary);
      }
      else if(type == MSH_PRI_6 || type == MSH_PRI_18 || type == MSH_PRI_15){
        cell = new CPrism(vertices, tag, subdomain, boundary);
      }
      else if(type == MSH_PYR_5 || type == MSH_PYR_14 || type == MSH_PYR_13){
        cell = new CPyramid(vertices, tag, subdomain, boundary);
      }*/
      else printf("Error: mesh element %d not implemented yet! \n", type);
      tag++;
      //if(domain.at(j)->getMeshElement(i)->getNum() == 8196) cell->setImmune(true);
      //else 
      cell->setImmune(false);
      insertInfo = _cells[dim].insert(cell);
      if(!insertInfo.second) delete cell;
    }
  }

  // add lower dimensional cells recursively
  for (int dim = 3; dim > 0; dim--){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      std::vector<MVertex*> vertices;
      for(int i = 0; i < cell->getNumFacets(); i++){ 
        cell->getFacetVertices(i, vertices);
        Cell* newCell;
        if(dim == 3){
          if(vertices.size() == 3) newCell = new TwoSimplex(vertices, tag, subdomain, boundary);
          else if(vertices.size() == 4) newCell = new CQuadrangle(vertices, tag, subdomain, boundary);
          else printf("Error: invalid face! \n");
        }
        else if(dim == 2) newCell = new OneSimplex(vertices, tag, subdomain, boundary);
        else if(dim == 1) newCell = new ZeroSimplex(vertices, tag, subdomain, boundary);
        newCell->setImmune(cell->getImmune());
        tag++;
        insertInfo = _cells[dim-1].insert(newCell);
        if(!insertInfo.second){
          delete newCell;
          Cell* oldCell = *(insertInfo.first);
          if(!subdomain && !boundary){
            int ori = cell->kappa(oldCell);
            oldCell->addCoboundaryCell( ori, cell );
            oldCell->addOrgCbdCell( ori, cell );
            cell->addBoundaryCell( ori, oldCell);
            cell->addOrgBdCell( ori, oldCell);
          }
        }
        else if(!subdomain && !boundary) {
          int ori = cell->kappa(newCell);
          cell->addBoundaryCell( ori, newCell );
          cell->addOrgBdCell( ori, newCell );
          newCell->addCoboundaryCell( ori, cell);
          newCell->addOrgCbdCell( ori, cell);
        }
      }
    }
  }
  
}

void CellComplex::insertCell(Cell* cell){
  _ecells.insert(cell);
}

/*
int Simplex::kappa(Cell* tau) const{
  for(int i=0; i < tau->getNumVertices(); i++){
    if( !(this->hasVertex(tau->getVertex(i)->getNum())) ) return 0;
  }
  
  if(this->getDim() - tau->getDim() != 1) return 0;
  
  int value=1;
  for(int i=0; i < tau->getNumVertices(); i++){
    if(this->getSortedVertex(i) != tau->getSortedVertex(i)) return value;
    value = value*-1;
  }
  
  return value;  
}
*/

int Cell::kappa(Cell* tau) const{
  for(int i=0; i < tau->getNumVertices(); i++){
    if( !(this->hasVertex(tau->getVertex(i)->getNum())) ) return 0;
  }
  
  if(this->getDim() - tau->getDim() != 1) return 0;
  
  int value=1;
  
  for(int i = 0; i < this->getNumFacets(); i++){
    std::vector<MVertex*> vTau = tau->getVertexVector(); 
    std::vector<MVertex*> v;
    this->getFacetVertices(i, v);
    value = -1;
    
    if(v.size() != vTau.size()) printf("Error: invalid facet!");
    
    do {
      value = value*-1;
      if(v == vTau) return value;
    }
    while (std::next_permutation(vTau.begin(), vTau.end()) );
    
    vTau = tau->getVertexVector();
    value = -1;
    do {
      value = value*-1;
      if(v == vTau) return value;
    }
    while (std::prev_permutation(vTau.begin(), vTau.end()) );
    
    
  }
  
  return 0;
}


int OneSimplex::kappa(Cell* tau) const{
  
  for(int i=0; i < tau->getNumVertices(); i++){
    if( !(this->hasVertex(tau->getVertex(i)->getNum())) ) return 0;
  }
  
  if(tau->getDim() != 0) return 0;
  
  if(tau->getVertex(0) == this->getVertex(0)) return -1;
  else return 1;
    
}


void CellComplex::removeCell(Cell* cell, bool other){
  
  std::map<Cell*, int, Less_Cell > coboundary = cell->getOrientedCoboundary();
  std::map<Cell*, int, Less_Cell > boundary = cell->getOrientedBoundary();
  //std::list<Cell*> boundary = cell->getBoundary();
  //std::list<Cell*> coboundary = cell->getCoboundary();
  
  for(std::map<Cell*, int, Less_Cell>::iterator it = coboundary.begin(); it != coboundary.end(); it++){
  //for(std::list<Cell*>::iterator it = coboundary.begin(); it != coboundary.end(); it++){
    Cell* cbdCell = (*it).first;
    //Cell* cbdCell = *it;
    cbdCell->removeBoundaryCell(cell, other);
  }
  
  
  for(std::map<Cell*, int, Less_Cell>::iterator it = boundary.begin(); it != boundary.end(); it++){
  //for(std::list<Cell*>::iterator it = boundary.begin(); it != boundary.end(); it++){
    Cell* bdCell = (*it).first;
    //Cell* bdCell = *it;
    bdCell->removeCoboundaryCell(cell, other);
  }
  
  _cells[cell->getDim()].erase(cell);
  
}

void CellComplex::removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset){
   Qset.erase(cell);
}

void CellComplex::enqueueCells(std::list<Cell*>& cells, std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset){
  for(std::list<Cell*>::iterator cit = cells.begin(); cit != cells.end(); cit++){
    Cell* cell = *cit;
    citer it = Qset.find(cell);
    //citer it2 = _cells[cell->getDim()].find(cell);
    if(it == Qset.end()){// && it2 != _cells[cell->getDim()].end()){
      Qset.insert(cell);
      Q.push(cell);
    }
  }
}

int CellComplex::coreduction(Cell* generator, int omitted){
  
  int coreductions = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(generator);
  Qset.insert(generator);
  
  
  std::list<Cell*> bd_s;
  std::list<Cell*> cbd_c;
  Cell* s;
  int round = 0;
  while( !Q.empty() ){
    round++;
    //printf("%d ", round);
    
    s = Q.front();
    Q.pop();
    removeCellQset(s, Qset);
    bd_s = s->getBoundary();
    
    if( bd_s.size() == 1 && inSameDomain(s, bd_s.front()) ){
      removeCell(s);
      cbd_c = bd_s.front()->getCoboundary();
      enqueueCells(cbd_c, Q, Qset);
      removeCell(bd_s.front());
      if(bd_s.front()->getDim() == 0 && omitted > 0) _store.at(omitted-1).insert(bd_s.front());
      else _trash.push_back(bd_s.front());
      coreductions++;
      
      _trash.push_back(s);
      
    }
    else if(bd_s.empty()){
      cbd_c = s->getCoboundary();
      enqueueCells(cbd_c, Q, Qset);
    }
    
    
  }
  //printf("Coreduction: %d loops with %d coreductions\n", round, coreductions);
  return coreductions;
}

int CellComplex::reduction(int dim, int omitted){
  if(dim < 1 || dim > 3) return 0;
  std::list<Cell*> cbd_c;
  int count = 0;
  
  bool reduced = true;
  bool ignoreCells = true;
  while (reduced){

    reduced = false;
    citer cit = firstCell(dim-1);
    while(cit != lastCell(dim-1)){
      
      
      Cell* cell = *cit;
      cbd_c = cell->getCoboundary();
      if( cbd_c.size() == 1 && inSameDomain(cell, cbd_c.front())){
          //&& ( (!cell->getImmune() && !cbd_c.front()->getImmune() ) )){
        ++cit;
        removeCell(cbd_c.front());
        removeCell(cell);
        _trash.push_back(cell);
        if(dim == getDim() && omitted > 0) _store.at(omitted-1).insert(cbd_c.front());
        else _trash.push_back(cbd_c.front());
        
        
        count++;
        reduced = true;
        
      }
      if(getSize(dim) == 0 || getSize(dim-1) == 0) break;
      cit++;
      
    }
    //if(!reduced && ignoreCells) { ignoreCells = false; reduced = true;}
  
  }

  return count;
}
/*
int CellComplex::reduction(Cell* generator){
  
  int coreductions = 0;

  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(generator);
  Qset.insert(generator);
  
  
  std::list<Cell*> cbd_s;
  std::list<Cell*> bd_c;
  Cell* s;
  int round = 0;
  while( !Q.empty() ){
    round++;
    //printf("%d ", round);
    
    s = Q.front();
    Q.pop();
    removeCellQset(s, Qset);

    cbd_s = s->getCoboundary();
    if( cbd_s.size() == 1 && inSameDomain(s, cbd_s.front()) ){
      removeCell(s);
      bd_c = bd_s.front()->getBoundary();
      enqueueCells(cbd_c, Q, Qset);
      removeCell(cbd_s.front());
      reductions++;
    }
    else if(cbd_s.empty()){
      bd_c = s->getBoundary();
      enqueueCells(bd_c, Q, Qset);
    }
    
    
  }
  //printf("Coreduction: %d loops with %d coreductions\n", round, coreductions);
  return reductions;
}
*/
/*
int CellComplex::reduction(int dim){
  if(dim < 1 || dim > 3) return 0;
  std::list<Cell*> cbd_c;
  std::list<Cell*> bd_c;
  int count = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  
  for(citer cit = firstCell(dim-1); cit != lastCell(dim-1); cit++){
    
    Cell* cell = *cit;
    Q.push(cell);
    Qset.insert(cell);
    
    while(Q.size() != 0){
      
      Cell* s = Q.front();
      Q.pop();
      cbd_c = s->getCoboundary();
      if( cbd_c.size() == 1 && inSameDomain(s, cbd_c.front()) ){
        
        removeCell(cbd_c.front());
        removeCell(s);
        count++;
        bd_c = cbd_c.front()->getBoundary();
        enqueueCells(bd_c, Q, Qset);
        
        cit = firstCell(dim-1);
      }
      
      removeCellQset(s, Qset);
      
    }
  }
  
  return count;
}
*/
  
int CellComplex::reduceComplex(){
  
  double t1 = Cpu();
  
  printf("Cell complex before reduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  int count = 0;
  for(int i = 3; i > 0; i--) count = count + reduction(i);
    
  int omitted = 0;
  _store.clear();
  //if(omit > getDim()) omit = getDim();
  
    
  CellComplex::removeSubdomain();
  //std::set<Cell*, Less_Cell> generatorCells;
  
  while (getSize(getDim()) != 0){
    
    citer cit = firstCell(getDim());
    
    Cell* cell = *cit;
    //generatorCells.insert(cell);
    removeCell(cell);
    
    //makeDualComplex();
    //coreduction(cell);
    //makeDualComplex();
    omitted++;
    std::set< Cell*, Less_Cell > omittedCells;
    _store.push_back(omittedCells);
    _store.at(omitted-1).insert(cell);
    for(int j = 3; j > 0; j--) reduction(j, omitted);
      
    
  }
  
  /*
    for(citer cit = generatorCells.begin(); cit != generatorCells.end(); cit++){
      Cell* cell = *cit;
      cell->clearBoundary();
      cell->clearCoboundary();
      _cells[cell->getDim()].insert(cell);
    }*/
  
  
  double t2 = Cpu();
  printf("Cell complex after reduction: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
         getSize(3), getSize(2), getSize(1), getSize(0), t2 - t1);
  
  /*
  for(int i = 0; i < _store.size(); i++){
    printf("omitted generator %d: \n", i+1); 
    for(citer cit = _store.at(i).begin(); cit != _store.at(i).end(); cit++){
      (*cit)->printCell();
    }
  }*/
  
  return 0;
}


void CellComplex::removeSubdomain(){
  
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      if(cell->inSubdomain()) {
        removeCell(cell);
        ++cit;
        //cit = firstCell(i);
      }
    }
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      if(cell->inSubdomain()) {
        removeCell(cell);
        cit = firstCell(i);
      }
    }
  }
  return;
}


int CellComplex::coreduceComplex(){

  printf("Cell complex before coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  int count = 0;
  
  CellComplex::removeSubdomain();
  
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
  
  //std::set<Cell*, Less_Cell> generatorCells;
  while (getSize(0) != 0){
    citer cit = firstCell(0);
    Cell* cell = *cit;
    //generatorCells.insert(cell);
    removeCell(cell, false);
    std::set< Cell*, Less_Cell > omittedCells;
    omitted++;
    _store.push_back(omittedCells);
    _store.at(omitted-1).insert(cell);
    coreduction(cell, omitted);
    }
  /*
  for(citer cit = generatorCells.begin(); cit != generatorCells.end(); cit++){
    Cell* cell = *cit;
    cell->clearBoundary();
    cell->clearCoboundary();
    _cells[0].insert(cell);
  }
  */
  
    
  printf("Cell complex after coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  return omitted;
}

void CellComplex::computeBettiNumbers(){
  
  for(int i = 0; i < 4; i++){
    _betti[i] = 0;
    printf("Betti number computation process: step %d of 4 \n", i+1);

    while (getSize(i) != 0){
      citer cit = firstCell(i);
      Cell* cell = *cit;
      while(!cell->inSubdomain() && cit != lastCell(i)){
        cell = *cit;
        cit++;
      }
      if(!cell->inSubdomain()) _betti[i] = _betti[i] + 1;
      removeCell(cell, false);
      coreduction(cell);
    }
  }
  printf("Cell complex Betti numbers: \nH0 = %d \nH1 = %d \nH2 = %d \nH3 = %d \n",
         getBettiNumber(0), getBettiNumber(1), getBettiNumber(2), getBettiNumber(3));
  
  return;
}


int CellComplex::cocombine(int dim){
 
  double t1 = Cpu();
  printf("Cell complex before cocombining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 0 || dim > 2) return 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::list<Cell*> cbd_c;
  std::map<Cell*, int, Less_Cell > bd_c;
  int count = 0;
  
  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
  
    Cell* cell = *cit;
    cbd_c = cell->getCoboundary();
    enqueueCells(cbd_c, Q, Qset);
    while(Q.size() != 0){

      Cell* s = Q.front();
      Q.pop();
      
      bd_c = s->getOrientedBoundary();
      if(s->getBoundarySize() == 2){
      
        std::map<Cell*, int, Less_Cell>::iterator it = bd_c.begin();
        int or1 = (*it).second;
        Cell* c1 = (*it).first;
        it++;
        int or2 = (*it).second;
        Cell* c2 = (*it).first;
        
        if(!(*c1 == *c2) 
           && inSameDomain(s, c1) && inSameDomain(s, c2)
           && c1->getNumVertices() < getSize(dim) // heuristics for mammoth cell birth control
           && c2->getNumVertices() < getSize(dim)){
                  
          removeCell(s);
          _trash.push_back(s);
          
          cbd_c = c1->getCoboundary();
          enqueueCells(cbd_c, Q, Qset);
          cbd_c = c2->getCoboundary();
          enqueueCells(cbd_c, Q, Qset);
          
          CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2), true );
          removeCell(c1);
          removeCell(c2);
          _cells[dim].insert(newCell);
          
          cit = firstCell(dim);
          count++;
        }
      }
      removeCellQset(s, Qset);
      
    }
  }
  double t2 = Cpu();
  printf("Cell complex after cocombining: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
         getSize(3), getSize(2), getSize(1), getSize(0), t2-t1);
  
  return count;
}

int CellComplex::combine(int dim){
  
  double t1 = Cpu();
  printf("Cell complex before combining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 1 || dim > 3) return 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::map<Cell*, int, Less_Cell> cbd_c;
  std::list<Cell*> bd_c;
  int count = 0;
  
  
  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    bd_c = cell->getBoundary();
    enqueueCells(bd_c, Q, Qset);
    while(Q.size() != 0){

      Cell* s = Q.front();
      Q.pop(); 
      cbd_c = s->getOrientedCoboundary();

      if(s->getCoboundarySize() == 2){
        std::map<Cell*, int, Less_Cell>::iterator it = cbd_c.begin();
        int or1 = (*it).second;
        Cell* c1 = (*it).first;
        it++;
        int or2 = (*it).second;
        Cell* c2 = (*it).first;

        if(!(*c1 == *c2) 
           && inSameDomain(s, c1) && inSameDomain(s, c2)
           && c1->getNumVertices() < getSize(dim) // heuristics for mammoth cell birth control
           && c2->getNumVertices() < getSize(dim)){

          removeCell(s);
          _trash.push_back(s);
          
          bd_c = c1->getBoundary();
          enqueueCells(bd_c, Q, Qset);
          bd_c = c2->getBoundary();
          enqueueCells(bd_c, Q, Qset);
          
          CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2) );
          removeCell(c1);
          removeCell(c2);
          std::pair<citer, bool> insertInfo =  _cells[dim].insert(newCell);
          if(!insertInfo.second) printf("Warning: Combined cell not inserted! \n");
          cit = firstCell(dim);
          count++;
        }
      }
      removeCellQset(s, Qset);
      
    }
  }
  double t2 = Cpu();
  printf("Cell complex after combining: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
       getSize(3), getSize(2), getSize(1), getSize(0), t2 - t1);
  
  
  return count;
}

/*
int CellComplex::combine(int dim){
   double t1 = Cpu();
  printf("Cell complex before combining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 1 || dim > 3) return 0;
  
  std::list< std::pair<int, Cell*> > cbd_c;
  std::list<Cell*> bd_c;
  int count = 0;
  bool combined = true;
  while(combined){
    combined = false;
  for(citer cit = firstCell(dim-1); cit != lastCell(dim-1); cit++){
    Cell* s = *cit;
    cbd_c = s->getOrientedCoboundary();
        
    if(s->getCoboundarySize() == 2 && !(*(cbd_c.front().second) == *(cbd_c.back().second)) 
       && inSameDomain(s, cbd_c.front().second) && inSameDomain(s, cbd_c.back().second)
       && cbd_c.front().second->getNumVertices() < getSize(dim) // heuristics for mammoth cell birth control
       && cbd_c.back().second->getNumVertices() < getSize(dim)){
      int or1 = cbd_c.front().first;
      int or2 = cbd_c.back().first;
      Cell* c1 = cbd_c.front().second;
      Cell* c2 = cbd_c.back().second;
      
      removeCell(s);
      
      CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2) );
      removeCell(c1);
      removeCell(c2);
      std::pair<citer, bool> insertInfo =  _cells[dim].insert(newCell);
      if(!insertInfo.second) printf("Warning: Combined cell not inserted! \n");
      cit = firstCell(dim-1);
      count++;
      combined = true;
    }
  }
    
  }
  
   double t2 = Cpu();
  printf("Cell complex after combining: %d volumes, %d faces, %d edges and %d vertices (%g s).\n",
         getSize(3), getSize(2), getSize(1), getSize(0), t2 - t1);
  
  
  return count;
}
*/

void CellComplex::swapSubdomain(){
  
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      if(cell->onDomainBoundary() && cell->inSubdomain()) cell->setInSubdomain(false);
      else if(cell->onDomainBoundary() && !cell->inSubdomain()) cell->setInSubdomain(true);
    }
  }
  
  // make subdomain closed
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      if(cell->inSubdomain()){
        std::list<Cell*> boundary = cell->getBoundary();
        for(std::list<Cell*>::iterator it = boundary.begin(); it != boundary.end(); it++){
          Cell* bdCell = *it;
          bdCell->setInSubdomain(true);
        }
      }
    }
  }
  
  return;
}


int CellComplex::writeComplexMSH(const std::string &name){
  
    
  FILE *fp = fopen(name.c_str(), "w");
  
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    printf("Unable to open file.");
    return 0;
  }
  
  
  
  fprintf(fp, "$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");
  
  fprintf(fp, "$Nodes\n");
  
  fprintf(fp, "%d\n", (int)_domainVertices.size());
  
  for(std::set<MVertex*, Less_MVertex>::iterator vit = _domainVertices.begin(); vit != _domainVertices.end(); vit++){
    MVertex* vertex = *vit;
    fprintf(fp, "%d %.16g %.16g %.16g\n", vertex->getNum(), vertex->x(), vertex->y(), vertex->z() );
  }
  
      
  fprintf(fp, "$EndNodes\n");
  fprintf(fp, "$Elements\n");

  int count = 0;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      count = count + cell->getNumCells();
    }
  }
  for(int i = 0; i < _store.size(); i++){    
    count = count + _store.at(i).size();
  }
  count = count + _ecells.size();
  
  fprintf(fp, "%d\n", count);

  int partition = 0;
  
  for(citer cit = firstCell(0); cit != lastCell(0); cit++) {
    Cell* vertex = *cit;
    if(vertex->inSubdomain()) partition = 3;
    else if(vertex->onDomainBoundary()) partition = 2;
    else partition = 1;
    fprintf(fp, "%d %d %d %d %d %d %d\n", vertex->getNum(), 15, 3, 0, 0, partition, vertex->getVertex(0)->getNum());
  }
  
  std::list< std::pair<int, Cell*> > cells;
  for(citer cit = firstCell(1); cit != lastCell(1); cit++) {
    Cell* edge = *cit;
    if(edge->inSubdomain()) partition = 3;
    else if(edge->onDomainBoundary()) partition = 2;
    else partition = 1;
    cells = edge->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell = (*it).second;
      fprintf(fp, "%d %d %d %d %d %d %d %d\n", cell->getNum(), 1, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum());
    }
  }
  
  for(citer cit = firstCell(2); cit != lastCell(2); cit++) {
    Cell* face = *cit;
    if(face->inSubdomain()) partition = 3;
    else if(face->onDomainBoundary()) partition = 2;
    else partition = 1;
    cells = face->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell = (*it).second;
      if(cell->getNumVertices() == 3) fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", cell->getNum(), 2, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum());
      else if (cell->getNumVertices() == 4)  fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 3, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum());
    }
  }
  for(citer cit = firstCell(3); cit != lastCell(3); cit++) {
    Cell* volume = *cit;
    if(volume->inSubdomain()) partition = 3;
    else if(volume->onDomainBoundary()) partition = 2;
    else partition = 1;
    cells = volume->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell = (*it).second;
      if(cell->getNumVertices() == 4) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 4, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum());
      if(cell->getNumVertices() == 8) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 12, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(), cell->getVertex(4)->getNum(), cell->getVertex(5)->getNum(), cell->getVertex(6)->getNum(), cell->getVertex(7)->getNum() );
      if(cell->getNumVertices() == 6) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 13, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(),cell->getVertex(4)->getNum(), cell->getVertex(5)->getNum());
      if(cell->getNumVertices() == 5) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 14, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(), cell->getVertex(4)->getNum());      
    }
  }
  
  for(int i = 0; i < _store.size(); i++){
    for(citer cit = _store.at(i).begin(); cit != _store.at(i).end(); cit++){
      Cell* cell = *cit;
      if(cell->inSubdomain()) partition = 3;
      else if(cell->onDomainBoundary()) partition = 2;
      else partition = 1;
      if(cell->getDim() == 0) fprintf(fp, "%d %d %d %d %d %d %d\n", cell->getNum(), 15, 3, 0, 0, partition, cell->getVertex(0)->getNum());
      if(cell->getDim() == 1) fprintf(fp, "%d %d %d %d %d %d %d %d\n", cell->getNum(), 1, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum());
      if(cell->getDim() == 2){
        if(cell->getNumVertices() == 3) fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", cell->getNum(), 2, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum());
        else if (cell->getNumVertices() == 4)  fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 3, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum());
      }
      if(cell->getDim() == 3){
        if(cell->getNumVertices() == 4) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 4, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum());
        if(cell->getNumVertices() == 8) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 12, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(), cell->getVertex(4)->getNum(), cell->getVertex(5)->getNum(), cell->getVertex(6)->getNum(), cell->getVertex(7)->getNum() );
        if(cell->getNumVertices() == 6) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 13, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(),cell->getVertex(4)->getNum(), cell->getVertex(5)->getNum());
        if(cell->getNumVertices() == 5) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 14, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(), cell->getVertex(4)->getNum());
      }  
    }
  }
  
  for(citer cit = _ecells.begin(); cit != _ecells.end(); cit++){
    Cell* cell = *cit;
    if(cell->inSubdomain()) partition = 3;
    else if(cell->onDomainBoundary()) partition = 2;
    else partition = 1;
    if(cell->getDim() == 0) fprintf(fp, "%d %d %d %d %d %d %d\n", cell->getNum(), 15, 3, 0, 0, partition, cell->getVertex(0)->getNum());
    if(cell->getDim() == 1) fprintf(fp, "%d %d %d %d %d %d %d %d\n", cell->getNum(), 1, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum());
    if(cell->getDim() == 2){
      if(cell->getNumVertices() == 3) fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", cell->getNum(), 2, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum());
      else if (cell->getNumVertices() == 4)  fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 3, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum());
    }
    if(cell->getDim() == 3){
      if(cell->getNumVertices() == 4) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 4, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum());
      if(cell->getNumVertices() == 8) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 12, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(), cell->getVertex(4)->getNum(), cell->getVertex(5)->getNum(), cell->getVertex(6)->getNum(), cell->getVertex(7)->getNum() );
      if(cell->getNumVertices() == 6) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 13, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(),cell->getVertex(4)->getNum(), cell->getVertex(5)->getNum());
      if(cell->getNumVertices() == 5) fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d\n", cell->getNum(), 14, 3, 0, 0, partition, cell->getVertex(0)->getNum(), cell->getVertex(1)->getNum(), cell->getVertex(2)->getNum(), cell->getVertex(3)->getNum(), cell->getVertex(4)->getNum());
    }  
  }
  
  
  
  fprintf(fp, "$EndElements\n");
  
  fclose(fp);
  
  return 1;
}


void CellComplex::printComplex(int dim){
  for (citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    cell->printCell();
    cell->printBoundary();
    cell->printCoboundary();
    printf("--- \n");
  }
}

bool CellComplex::checkCoherence(){
  bool coherent = true;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      std::map<Cell*, int, Less_Cell> boundary = cell->getOrientedBoundary();
      for(std::map<Cell*, int, Less_Cell>::iterator it = boundary.begin(); it != boundary.end(); it++){
        Cell* bdCell = (*it).first;
        int ori = (*it).second;
        citer cit = _cells[bdCell->getDim()].find(bdCell);
        if(cit == lastCell(bdCell->getDim())){ 
          printf("Warning! Boundary cell not in cell complex! Boundary removed. \n");
          //printf(" "); cell->printCell();
          //printf(" "); bdCell->printCell();
          cell->removeBoundaryCell(bdCell);
          coherent = false;
        }
        if(!bdCell->hasCoboundary(cell)){
          printf("Warning! Incoherent boundary/coboundary pair! Fixed. \n");
          //printf(" "); cell->printCell();
          //printf(" "); cell->printBoundary();
          //printf(" "); bdCell->printCell();
          //printf(" "); bdCell->printCoboundary();
          bdCell->addCoboundaryCell(ori, cell);
          coherent = false;
        }
        
      }
      std::map<Cell*, int, Less_Cell> coboundary = cell->getOrientedCoboundary();
      for(std::map<Cell*, int, Less_Cell>::iterator it = coboundary.begin(); it != coboundary.end(); it++){
        Cell* cbdCell = (*it).first;
        int ori = (*it).second;
        citer cit = _cells[cbdCell->getDim()].find(cbdCell);
        if(cit == lastCell(cbdCell->getDim())){ 
          printf("Warning! Coboundary cell not in cell complex! Coboundary removed. \n");
          //printf(" "); cell->printCell();
          //printf(" "); cbdCell->printCell();
          cell->removeCoboundaryCell(cbdCell);
          coherent = false;
        }
        if(!cbdCell->hasBoundary(cell)){
          printf("Warning! Incoherent coboundary/boundary pair! Fixed. \n");
          //printf(" "); cell->printCell();
          //printf(" "); cell->printCoboundary();
          //printf(" "); cbdCell->printCell();
          //printf(" "); cbdCell->printBoundary();
          cbdCell->addBoundaryCell(ori, cell);
          coherent = false;
        }
        
      }
      
    }
  }
  return coherent;
}


bool Less_Cell::operator()(const Cell* c1, const Cell* c2) const {
  
  //cells with fever vertices first
    
  if(c1->getNumVertices() != c2->getNumVertices()){
    return (c1->getNumVertices() < c2->getNumVertices());
  }
  
  
  
  //"natural number" -like ordering (the number of a vertice corresponds a digit)
  
  for(int i=0; i < c1->getNumVertices();i++){
    if(c1->getSortedVertex(i) < c2->getSortedVertex(i)) return true;
    else if (c1->getSortedVertex(i) > c2->getSortedVertex(i)) return false;
  }
  
  return false;
}
#endif
