// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.

#include "CellComplex.h"

CellComplex::CellComplex( std::vector<GEntity*> domain, std::vector<GEntity*> subdomain ){
  
  _domain = domain;
  _subdomain = subdomain;
  
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
  insert_cells2(true, true);
  insert_cells2(false, true);
  insert_cells2(false, false);
  
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
  
  
  // attach induvivial tags to cells
  int tag = 1;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      cell->setTag(tag);
      tag++;
      
      // make sure that boundary and coboundary information is coherent
      std::list<Cell*> boundary = cell->getBoundary();
      boundary.sort(Less_Cell());
      boundary.unique(Equal_Cell());
      cell->setBoundary(boundary);
      
      std::list<Cell*> coboundary = cell->getCoboundary();
      coboundary.sort(Less_Cell());
      coboundary.unique(Equal_Cell());
      cell->setCoboundary(coboundary);
      
      
    }
    
    
    _originalCells[i] = _cells[i];
  }
  
  
  _simplicial = true;
  
}
void CellComplex::insert_cells(bool subdomain, bool boundary){  
  
  std::vector<GEntity*> domain;
  
  if(subdomain) domain = _subdomain;
  else if(boundary) domain = _boundary;
  else domain = _domain;
  
  std::vector<int> vertices;
  int vertex = 0;
  
  std::pair<citer, bool> insertInfo;
  
  for(unsigned int j=0; j < domain.size(); j++) {  
    for(unsigned int i=0; i < domain.at(j)->getNumMeshElements(); i++){ 
      vertices.clear();
      
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumVertices(); k++){              
        MVertex* vertex = domain.at(j)->getMeshElement(i)->getVertex(k);
        vertices.push_back(vertex->getNum()); 
        //_cells[0].insert(new ZeroSimplex(vertex->getNum(), subdomain, vertex->x(), vertex->y(), vertex->z() )); // Add vertices
        Cell* cell = new ZeroSimplex(vertex->getNum(), subdomain, boundary);
        insertInfo = _cells[0].insert(cell);
        if(!insertInfo.second) delete cell;
      }
      if(domain.at(j)->getMeshElement(i)->getDim() == 3){
        Cell* cell = new ThreeSimplex(vertices, subdomain, boundary); // Add volumes
        insertInfo = _cells[3].insert(cell);
        if(!insertInfo.second) delete cell;
      }
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumFaces(); k++){
        vertices.clear();
        for(int l=0; l < domain.at(j)->getMeshElement(i)->getFace(k).getNumVertices(); l++){
          vertex = domain.at(j)->getMeshElement(i)->getFace(k).getVertex(l)->getNum();
          vertices.push_back(vertex); 
        } 
        Cell* cell = new TwoSimplex(vertices, subdomain, boundary); // Add faces
        insertInfo = _cells[2].insert(cell);
        if(!insertInfo.second) delete cell;
      }
      
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumEdges(); k++){
        vertices.clear();
        for(int l=0; l < domain.at(j)->getMeshElement(i)->getEdge(k).getNumVertices(); l++){
          vertex = domain.at(j)->getMeshElement(i)->getEdge(k).getVertex(l)->getNum();
          vertices.push_back(vertex); 
        }
        Cell* cell = new OneSimplex(vertices, subdomain, boundary); // Add edges
        insertInfo = _cells[1].insert(cell);
        if(!insertInfo.second) delete cell;
      }
            
    }               
  }
  
}

void CellComplex::insert_cells2(bool subdomain, bool boundary){
  
  // works only for simplcial meshes at the moment!
  
  std::vector<GEntity*> domain;
  
  if(subdomain) domain = _subdomain;
  else if(boundary) domain = _boundary;
  else domain = _domain;
  
  std::vector<int> vertices;
  int vertex = 0;
  
  std::pair<citer, bool> insertInfo;
  
  // add highest dimensional cells
  for(unsigned int j=0; j < domain.size(); j++) {
    for(unsigned int i=0; i < domain.at(j)->getNumMeshElements(); i++){
      vertices.clear();
      
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumVertices(); k++){
        MVertex* vertex = domain.at(j)->getMeshElement(i)->getVertex(k);
        vertices.push_back(vertex->getNum());
      }
      
      int dim = domain.at(j)->getMeshElement(i)->getDim();
      int type = domain.at(j)->getMeshElement(i)->getTypeForMSH();
      Cell* cell;
      if(dim == 3) cell = new ThreeSimplex(vertices, subdomain, boundary);
      else if(dim == 2) cell = new TwoSimplex(vertices, subdomain, boundary);
      else if(dim == 1) cell = new OneSimplex(vertices, subdomain, boundary);
      else cell = new ZeroSimplex(vertices.at(0), subdomain, boundary);
      insertInfo = _cells[dim].insert(cell);
      if(!insertInfo.second) delete cell;
    }
  }
  
  // add lower dimensional cells recursively
  for (int dim = 3; dim > 0; dim--){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      std::vector<int> vertices;
      for(int i = 0; i < cell->getNumFacets(); i++){ 
        cell->getFacetVertices(i, vertices);
        Cell* newCell;
        if(dim == 3) newCell = new TwoSimplex(vertices, subdomain, boundary);
        else if(dim == 2) newCell = new OneSimplex(vertices, subdomain, boundary);
        else if(dim == 1) newCell = new ZeroSimplex(vertices.at(0), subdomain, boundary);
        insertInfo = _cells[dim-1].insert(newCell);
        if(!insertInfo.second){
          delete newCell;
          Cell* oldCell = *(insertInfo.first);
          oldCell->addCoboundaryCell(cell);
          cell->addBoundaryCell(oldCell);
        }
        else{
          cell->addBoundaryCell(newCell);
          newCell->addCoboundaryCell(cell);
        }
      }
    }
  }
  
}

void CellComplex::insertCell(Cell* cell){
  _cells[cell->getDim()].insert(cell);
}

int Simplex::kappa(Cell* tau) const{
  for(int i=0; i < tau->getNumVertices(); i++){
    if( !(this->hasVertex(tau->getVertex(i))) ) return 0;
  }
  
  if(this->getDim() - tau->getDim() != 1) return 0;
  
  int value=1;
  for(int i=0; i < tau->getNumVertices(); i++){
    if(this->getVertex(i) != tau->getVertex(i)) return value;
    value = value*-1;
  }
  
  return value;  
}
std::set<Cell*, Less_Cell>::iterator CellComplex::findCell(int dim, std::vector<int>& vertices, bool original){
  Cell* cell;
  
  if(dim == 0) cell = new ZeroSimplex(vertices.at(0));
  else if(dim == 1) cell = new OneSimplex(vertices);
  else if(dim == 2) cell = new TwoSimplex(vertices);
  else cell = new ThreeSimplex(vertices);
  
  citer cit;
  if(!original) cit = _cells[dim].find(cell);
  else cit = _originalCells[dim].find(cell);

  delete cell;
  return cit;
}

std::set<Cell*, Less_Cell>::iterator CellComplex::findCell(int dim, int vertex, int dummy){
  Cell* cell;
  if(dim == 0) cell = new ZeroSimplex(vertex);
  else if(dim == 1) cell = new OneSimplex(vertex, dummy);
  else if(dim == 2) cell = new TwoSimplex(vertex, dummy);
  else cell = new ThreeSimplex(vertex, dummy);
  
  citer cit = _cells[dim].lower_bound(cell);
  
  delete cell;
  return cit;
}


std::vector<Cell*> CellComplex::bd(Cell* sigma){  
  std::vector<Cell*> boundary;
  int dim = sigma->getDim();
  if(dim < 1) return boundary;
  
  if(simplicial()){ // faster
    std::vector<int> vertices = sigma->getVertexVector();
    
    for(int j=0; j < vertices.size(); j++){
      std::vector<int> bVertices;
      
      // simplicial mesh assumed here!
      for(int k=0; k < vertices.size(); k++){
        if (k !=j ) bVertices.push_back(vertices.at(k));
      }
      citer cit2  = findCell(dim-1, bVertices);
      if(cit2 != lastCell(dim-1)){
        boundary.push_back(*cit2);
        if(boundary.size() == sigma->getBdMaxSize()){
          return boundary;
        }
      }
    }
    
  }
  else{
    citer start = findCell(dim-1, sigma->getVertex(0), 0);
    if(start == lastCell(dim-1)) return boundary;
    
    citer end = findCell(dim-1, sigma->getVertex(sigma->getNumVertices()-1), sigma->getVertex(sigma->getNumVertices()-1));
    if(end != lastCell(dim-1)) end++;
    
    //for(citer cit = firstCell(dim-1); cit != lastCell(dim-1); cit++){
    for(citer cit = start; cit != end; cit++){
      //if(kappa(sigma, *cit) != 0){
      if(sigma->kappa(*cit) != 0){
        boundary.push_back(*cit);
        if(boundary.size() == sigma->getBdMaxSize()){
          return boundary;
        }
      }
    }
  }
  return boundary;    
}
std::vector< std::set<Cell*, Less_Cell>::iterator > CellComplex::bdIt(Cell* sigma){
  
  int dim = sigma->getDim();  
  std::vector< std::set<Cell*, Less_Cell>::iterator >  boundary;
  if(dim < 1){
    return boundary;
  }
  
  citer start = findCell(dim-1, sigma->getVertex(0), 0);
  if(start == lastCell(dim-1)) return boundary;
  
  citer end = findCell(dim-1, sigma->getVertex(sigma->getNumVertices()-1), sigma->getVertex(sigma->getNumVertices()-1));
  if(end != lastCell(dim-1)) end++;
    
  for(citer cit = start; cit != end; cit++){
    if(kappa(sigma, *cit) != 0){
      boundary.push_back(cit);
      if(boundary.size() == sigma->getBdMaxSize()){
        return boundary;
      }
    }
  }
  
  return boundary;
}



std::vector<Cell*> CellComplex::cbd(Cell* tau){  
  std::vector<Cell*> coboundary;
  int dim = tau->getDim();
  if(dim > 2){
    return coboundary;
  }
  
  for(citer cit = firstCell(dim+1); cit != lastCell(dim+1); cit++){
    //if(kappa(*cit, tau) != 0){
    Cell* cell = *cit;
    if(cell->kappa(tau) != 0){
      coboundary.push_back(*cit);
      if(coboundary.size() == tau->getCbdMaxSize()){
        return coboundary;
      }
    }
  }
  
  return coboundary;    
}

std::vector< std::set<Cell*, Less_Cell>::iterator > CellComplex::cbdIt(Cell* tau){
  
  std::vector< std::set<Cell*, Less_Cell>::iterator >  coboundary;
  int dim = tau->getDim();
  if(dim > 2){
    return coboundary;
  }
  
  for(citer cit = firstCell(dim+1); cit != lastCell(dim+1); cit++){
    if(kappa(*cit, tau) != 0){
      coboundary.push_back(cit);
      if(coboundary.size() == tau->getCbdMaxSize()){
        return coboundary;
      }
    }
  }
  
  return coboundary;
}


void CellComplex::removeCell(Cell* cell){
  _cells[cell->getDim()].erase(cell);
  
  std::list<Cell*> coboundary = cell->getCoboundary();
  std::list<Cell*> boundary = cell->getBoundary();
  
  for(std::list<Cell*>::iterator it = coboundary.begin(); it != coboundary.end(); it++){ 
    Cell* cbdCell = *it;
    cbdCell->removeBoundaryCell(cell);
  }
  for(std::list<Cell*>::iterator it = boundary.begin(); it != boundary.end(); it++){
    Cell* bdCell = *it;
    bdCell->removeCoboundaryCell(cell);
  }
  
}
void CellComplex::removeCellIt(std::set<Cell*, Less_Cell>::iterator cell){
  Cell* c = *cell;
  int dim = c->getDim();
  _cells[dim].erase(cell);

}

void CellComplex::removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset){
   Qset.erase(cell);
}

void CellComplex::enqueueCellsIt(std::vector< std::set<Cell*, Less_Cell>::iterator >& cells, 
                               std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset){
  for(unsigned int i=0; i < cells.size(); i++){
    Cell* cell = *cells.at(i);
    citer cit = Qset.find(cell);
    if(cit == Qset.end()){
      Qset.insert(cell);
      Q.push(cell);
    } 
  }
}
void CellComplex::enqueueCells(std::list<Cell*>& cells, std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset){
  for(std::list<Cell*>::iterator cit = cells.begin(); cit != cells.end(); cit++){
    Cell* cell = *cit;
    citer it = Qset.find(cell);
    if(it == Qset.end()){
      Qset.insert(cell);
      Q.push(cell);
    }
  }
}

void CellComplex::enqueueCells(std::list<Cell*>& cells, std::list<Cell*>& Q){
  for(std::list<Cell*>::iterator cit = cells.begin(); cit != cells.end(); cit++){
    Cell* cell = *cit;
    std::list<Cell*>::iterator it = std::find(Q.begin(), Q.end(), cell);
    if(it == Q.end()){
      Q.push_back(cell);
    }
  }
}



int CellComplex::coreductionMrozek(Cell* generator){
  
  int coreductions = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(generator);
  Qset.insert(generator);
  //removeCell(generator);
  
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
      coreductions++;
    }
    else if(bd_s.empty()){
      cbd_c = s->getCoboundary();
      enqueueCells(cbd_c, Q, Qset);
    }
    
    
  }
  //printf("Coreduction: %d loops with %d coreductions\n", round, coreductions);
  return coreductions;
}

int CellComplex::coreductionMrozek2(Cell* generator){
  
  int coreductions = 0;
  
  std::list<Cell*> Q;
  
  Q.push_back(generator);
  
  std::list<Cell*> bd_s;
  std::list<Cell*> cbd_c;
  Cell* s;
  int round = 0;
  while( !Q.empty() ){
    round++;
    //printf("%d ", round);
    s = Q.front();
    Q.pop_front();
    bd_s = s->getBoundary();
    if( bd_s.size() == 1 && inSameDomain(s, bd_s.front()) ){
      removeCell(s);
      cbd_c = bd_s.front()->getCoboundary();
      enqueueCells(cbd_c, Q);
      removeCell(bd_s.front());
      coreductions++;
    }
    else if(bd_s.empty()){
      cbd_c = s->getCoboundary();
      enqueueCells(cbd_c, Q);
    }
    
    //Q.unique(Equal_Cell());
  
  }
  //printf("Coreduction: %d loops with %d coreductions\n", round, coreductions);
  return coreductions;
}

int CellComplex::coreductionMrozek3(Cell* generator){
  
  int coreductions = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(generator);
  Qset.insert(generator);
  
  std::vector< std::set<Cell*, Less_Cell>::iterator > bd_s;
  std::vector< std::set<Cell*, Less_Cell>::iterator > cbd_c;
  
  Cell* s;
  int round = 0;
  while( !Q.empty() ){
    round++;
    //printf("%d ", round);
    s = Q.front();
    Q.pop();
    removeCellQset(s, Qset);
    
    bd_s = bdIt(s);
    if( bd_s.size() == 1 && inSameDomain(s, *bd_s.at(0)) ){
      removeCell(s);
      cbd_c = cbdIt(*bd_s.at(0));
      enqueueCellsIt(cbd_c, Q, Qset);
      removeCellIt(bd_s.at(0));
      coreductions++;
    }
    else if(bd_s.empty()){
      cbd_c = cbdIt(s);
      enqueueCellsIt(cbd_c, Q, Qset);
    }
  }
  //printf("Coreduction: %d loops with %d coreductions\n", round, coreductions);
  return coreductions;
}
int CellComplex::coreduction(int dim){
  
  if(dim < 0 || dim > 2) return 0;
  
  std::vector<Cell*> bd_c;
  int count = 0;
  
  bool coreduced = true;
  while (coreduced){
    coreduced = false;
    for(citer cit = firstCell(dim+1); cit != lastCell(dim+1); cit++){
      Cell* cell = *cit;
      
      bd_c = bd(cell);
      if(bd_c.size() == 1 && inSameDomain(cell, bd_c.at(0)) ){
        removeCell(cell);
        removeCell(bd_c.at(0));
        count++;
        coreduced = true;
      }
      
    }
  }
  
  return count;
    
}

int CellComplex::coreduction(int dim, std::set<Cell*, Less_Cell>& removedCells){
  
  if(dim < 0 || dim > 2) return 0;
  
  std::vector<Cell*> bd_c;
  int count = 0;
  
  bool coreduced = true;
  while (coreduced){
    coreduced = false;
    for(citer cit = firstCell(dim+1); cit != lastCell(dim+1); cit++){
      Cell* cell = *cit;
      
      bd_c = bd(cell);
      if(bd_c.size() == 1 && inSameDomain(cell, bd_c.at(0)) ){
        removedCells.insert(cell);
        removedCells.insert(bd_c.at(0));
        removeCell(cell);
        removeCell(bd_c.at(0));
        count++;
        coreduced = true;
      }
      
    }
  }
  
  return count;
  
}

int CellComplex::coreduction2(int dim){

  if(dim < 0 || dim > 2) return 0;
  
  std::list<Cell*> bd_c;
  
  int count = 0;
  
  bool coreduced = true;
  while (coreduced){
    coreduced = false;
    for(citer cit = firstCell(dim+1); cit != lastCell(dim+1); cit++){
      Cell* cell = *cit;
      
      bd_c = cell->getBoundary();
      if(bd_c.size() == 1 && inSameDomain(cell, bd_c.front()) ){
        removeCell(cell);
        removeCell(bd_c.front());
        count++;
        coreduced = true;
      }
      
    }
  }
  return count;
}



int CellComplex::reduction(int dim){
  if(dim < 1 || dim > 3) return 0;
  
  std::vector<Cell*> cbd_c;
  std::vector<Cell*> bd_c;
  int count = 0;
  
  bool reduced = true;
  while (reduced){
    reduced = false;
    for(citer cit = firstCell(dim-1); cit != lastCell(dim-1); cit++){
      Cell* cell = *cit;
      cbd_c = cbd(cell);
      if(cbd_c.size() == 1 && inSameDomain(cell, cbd_c.at(0)) ){
        removeCell(cell);
        removeCell(cbd_c.at(0));
        count++;
        reduced = true;
      }
    }
  }
  return count;  
}


int CellComplex::reduction2(int dim){
    if(dim < 1 || dim > 3) return 0;
  
  std::list<Cell*> bd_c;
  std::list<Cell*> cbd_c;
  int count = 0;
  
  bool reduced = true;
  while (reduced){
    reduced = false;
    for(citer cit = firstCell(dim-1); cit != lastCell(dim-1); cit++){
      Cell* cell = *cit;
      cbd_c = cell->getCoboundary();
      if(cbd_c.size() == 1 && inSameDomain(cell, cbd_c.front()) ){
        removeCell(cell);
        removeCell(cbd_c.front());
        count++;
        reduced = true;
      }
    }
  }
  
  return count;
}

 
void CellComplex::reduceComplex(){
  printf("Cell complex before reduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  reduction2(3);
  reduction2(2);
  reduction2(1);
  printf("Cell complex after reduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
}

void CellComplex::coreduceComplex(int generatorDim, std::set<Cell*, Less_Cell>& removedCells){
  
  std::set<Cell*, Less_Cell> generatorCells[4];
  
  printf("Cell complex before coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  int i = generatorDim;
  while (getSize(i) != 0){
    citer cit = firstCell(i);
    Cell* cell = *cit;
    while(!cell->inSubdomain() && cit != lastCell(i)){
      cell = *cit;
      cit++;
    }
    generatorCells[i].insert(cell);
    removedCells.insert(cell);
    removeCell(cell);
    coreduction(0, removedCells);
    coreduction(1, removedCells);
    coreduction(2, removedCells);
  }
  
  
  for(citer cit = generatorCells[i].begin(); cit != generatorCells[i].end(); cit++){
    Cell* cell = *cit;
    if(!cell->inSubdomain()) _cells[i].insert(cell);
    if(!cell->inSubdomain()) removedCells.insert(cell);
  }
  printf("Cell complex after coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  return;
  
}
void CellComplex::coreduceComplex(int generatorDim){

  std::set<Cell*, Less_Cell> generatorCells[4];
  
  printf("Cell complex before coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  for(int i = 0; i < 4; i++){    
    while (getSize(i) != 0){
      //if(generatorDim == i || i == generatorDim+1) break;
      citer cit = firstCell(i);
      Cell* cell = *cit;
      while(!cell->inSubdomain() && cit != lastCell(i)){
        cell = *cit;
        cit++;
      }
      generatorCells[i].insert(cell);
      removeCell(cell);

      //coreduction2(0);
      //coreduction2(1);
      //coreduction2(2);
      coreductionMrozek(cell);
    }
    if(generatorDim == i) break;
    
  }
  for(int i = 0; i < 4; i++){
    for(citer cit = generatorCells[i].begin(); cit != generatorCells[i].end(); cit++){
      Cell* cell = *cit;
      //if(!cell->inSubdomain()) _cells[i].insert(cell); 
    }
  }
  printf("Cell complex after coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  return;
}

void CellComplex::repairComplex(int i){
  
  printf("Cell complex before repair: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  while(i > 0){
    
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      std::vector<int> vertices = cell->getVertexVector();
      
      for(int j=0; j < vertices.size(); j++){
        std::vector<int> bVertices;
        
        for(int k=0; k < vertices.size(); k++){
          if (k !=j ) bVertices.push_back(vertices.at(k));
        }
        citer cit2  = findCell(i-1, bVertices, true);
        Cell* cell2 = *cit2;
        _cells[i-1].insert(cell2);
        
      }
    }
  i--;
    
  }

  printf("Cell complex after repair: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  return;
}

void CellComplex::swapSubdomain(){
  
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      if(cell->onDomainBoundary() && cell->inSubdomain()) cell->setInSubdomain(false);
      else if(cell->onDomainBoundary() && !cell->inSubdomain()) cell->setInSubdomain(true);
    }
  }
  
  return;
}


void CellComplex::getDomainVertices(std::set<MVertex*, Less_MVertex>& domainVertices, bool subdomain){

  std::vector<GEntity*> domain;
  if(subdomain) domain = _subdomain;
  else domain = _domain;
  
  for(unsigned int j=0; j < domain.size(); j++) {
    for(unsigned int i=0; i < domain.at(j)->getNumMeshElements(); i++){
      for(int k=0; k < domain.at(j)->getMeshElement(i)->getNumVertices(); k++){
        MVertex* vertex = domain.at(j)->getMeshElement(i)->getVertex(k);
        domainVertices.insert(vertex);
      }
    }
  }
      
/*  for(unsigned int j=0; j < _domain.size(); j++) { 
    for(unsigned int i=0; i < _domain.at(j)->getNumMeshVertices(); i++){
      MVertex* vertex =  _domain.at(j)->getMeshVertex(i);
      domainVertices.insert(vertex);
    }
    
    std::list<GFace*> faces = _domain.at(j)->faces();
    for(std::list<GFace*>::iterator fit = faces.begin(); fit != faces.end(); fit++){
      GFace* face = *fit;
      for(unsigned int i=0; i < face->getNumMeshVertices(); i++){
        MVertex* vertex =  face->getMeshVertex(i);
        domainVertices.insert(vertex);
      }
    }
    std::list<GEdge*> edges = _domain.at(j)->edges();
    for(std::list<GEdge*>::iterator eit = edges.begin(); eit != edges.end(); eit++){
      GEdge* edge = *eit;
      for(unsigned int i=0; i < edge->getNumMeshVertices(); i++){
        MVertex* vertex =  edge->getMeshVertex(i);
        domainVertices.insert(vertex);
      }
    }
    std::list<GVertex*> vertices = _domain.at(j)->vertices();
    for(std::list<GVertex*>::iterator vit = vertices.begin(); vit != vertices.end(); vit++){
      GVertex* vertex = *vit;
      for(unsigned int i=0; i < vertex->getNumMeshVertices(); i++){
        MVertex* mvertex =  vertex->getMeshVertex(i);
        domainVertices.insert(mvertex);
      }
    }
    
  }
 */
  return;
}

int CellComplex::writeComplexMSH(const std::string &name){
  
    
  FILE *fp = fopen(name.c_str(), "w");
  
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    printf("Unable to open file.");
    return 0;
  }
  
  
  
  fprintf(fp, "$MeshFormat\n2.0 0 8\n$EndMeshFormat\n");
  
  fprintf(fp, "$Nodes\n");
  
  //std::set<MVertex*, Less_MVertex> domainVertices;
  //getDomainVertices(domainVertices, true);
  //getDomainVertices(domainVertices, false);
  
  fprintf(fp, "%d\n", _domainVertices.size());
  
  for(std::set<MVertex*, Less_MVertex>::iterator vit = _domainVertices.begin(); vit != _domainVertices.end(); vit++){
    MVertex* vertex = *vit;
    fprintf(fp, "%d %.16g %.16g %.16g\n", vertex->getNum(), vertex->x(), vertex->y(), vertex->z() );
  }
  
      
  fprintf(fp, "$EndNodes\n");
  fprintf(fp, "$Elements\n");

  fprintf(fp, "%d\n", _cells[0].size() + _cells[1].size() + _cells[2].size() + _cells[3].size());

  int physical = 0;
  
  for(citer cit = firstCell(0); cit != lastCell(0); cit++) {
    Cell* vertex = *cit;
    if(vertex->inSubdomain()) physical = 3;
    else if(vertex->onDomainBoundary()) physical = 2;
    else physical = 1;
     fprintf(fp, "%d %d %d %d %d %d %d\n", vertex->getTag(), 15, 3, 0, 0, physical, vertex->getVertex(0));
  }
  
  
  for(citer cit = firstCell(1); cit != lastCell(1); cit++) {
    Cell* edge = *cit;
    if(edge->inSubdomain()) physical = 3;
    else if(edge->onDomainBoundary()) physical = 2;
    else physical = 1;
    fprintf(fp, "%d %d %d %d %d %d %d %d\n", edge->getTag(), 1, 3, 0, 0, physical, edge->getVertex(0), edge->getVertex(1));
  }
  
  for(citer cit = firstCell(2); cit != lastCell(2); cit++) {
    Cell* face = *cit;
    if(face->inSubdomain()) physical = 3;
    else if(face->onDomainBoundary()) physical = 2;
    else physical = 1;
    fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", face->getTag(), 2, 3, 0, 0, physical, face->getVertex(0), face->getVertex(1), face->getVertex(2));
  }
  for(citer cit = firstCell(3); cit != lastCell(3); cit++) {
    Cell* volume = *cit;
    if(volume->inSubdomain()) physical = 3;
    else if(volume->onDomainBoundary()) physical = 2;
    else physical = 1;
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", volume->getTag(), 4, 3, 0, 0, physical, volume->getVertex(0), volume->getVertex(1), volume->getVertex(2), volume->getVertex(3));
  }
    
  fprintf(fp, "$EndElements\n");
  
  fclose(fp);
  
  return 1;
}


void CellComplex::printComplex(int dim, bool subcomplex){
  for (citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    for(int i = 0; i < cell->getNumVertices(); i++){
      if(!subcomplex && !cell->inSubdomain()) printf("%d ", cell->getVertex(i));
    }
    printf("\n");
  }
}


  
