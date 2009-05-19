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
      Cell* cell = *cit;
      cell->setTag(tag);
      tag++;
    }
    _originalCells[i] = _cells[i];
  }
  
}

void CellComplex::insert_cells(bool subdomain, bool boundary){
  
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
      if(dim == 3) cell = new ThreeSimplex(vertices, 0, subdomain, boundary);
      else if(dim == 2) cell = new TwoSimplex(vertices, 0, subdomain, boundary);
      else if(dim == 1) cell = new OneSimplex(vertices, 0, subdomain, boundary);
      else cell = new ZeroSimplex(vertices.at(0), 0, subdomain, boundary);
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
        if(dim == 3) newCell = new TwoSimplex(vertices, 0, subdomain, boundary);
        else if(dim == 2) newCell = new OneSimplex(vertices, 0, subdomain, boundary);
        else if(dim == 1) newCell = new ZeroSimplex(vertices.at(0), 0, subdomain, boundary);
        insertInfo = _cells[dim-1].insert(newCell);
        if(!insertInfo.second){
          delete newCell;
          Cell* oldCell = *(insertInfo.first);
          if(!subdomain && !boundary){
            int ori = cell->kappa(oldCell);
            oldCell->addCoboundaryCell( ori, cell );
            cell->addBoundaryCell( ori, oldCell);
          }
        }
        else if(!subdomain && !boundary) {
          int ori = cell->kappa(newCell);
          cell->addBoundaryCell( ori, newCell );
          newCell->addCoboundaryCell( ori, cell);
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
    if(this->getSortedVertex(i) != tau->getSortedVertex(i)) return value;
    value = value*-1;
  }
  
  return value;  
}

/*
int Simplex::kappa(Cell* tau) const{
  for(int i=0; i < tau->getNumVertices(); i++){
    if( !(this->hasVertex(tau->getVertex(i))) ) return 0;
  }
  
  if(this->getDim() - tau->getDim() != 1) return 0;
  
  int value=1;
  
  for(int i = 0; i < this->getNumFacets(); i++){
    std::vector<int> vTau = tau->getVertexVector(); 
    std::vector<int> v;
    this->getFacetVertices(i, v);
    value = -1;
    
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
    if( !(this->hasVertex(tau->getVertex(i))) ) return 0;
  }
  
  if(tau->getDim() != 0) return 0;
  
  if(tau->getVertex(0) == this->getVertex(0)) return -1;
  else return 1;
    
}
*/

int Quadrangle::kappa(Cell* tau) const{
  for(int i=0; i < tau->getNumVertices(); i++){
    if( !(this->hasVertex(tau->getVertex(i))) ) return 0;
  }
  
  if(tau->getDim() != 1) return 0;
  
  int value=1;
  
  std::vector<int> vTau = tau->getVertexVector();
  
  for(int i = 0; i < this->getNumFacets(); i++){
    std::vector<int> v;
    this->getFacetVertices(i, v);
    value = -1;
    do {
      value = value*-1;
      if(v == vTau) return value;
    }
    while (std::next_permutation(v.begin(), v.end()) );
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

void CellComplex::removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset){
   Qset.erase(cell);
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

int CellComplex::coreductionMrozek(Cell* generator){
  
  int coreductions = 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  
  Q.push(generator);
  Qset.insert(generator);
  //removeCell(generator);
  
  std::list<Cell*> bd_s;
  //std::list< std::pair<int, Cell*> >bd_s;
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

int CellComplex::coreduction(int dim){
  
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
  reduction(3);
  reduction(2);
  reduction(1);
  printf("Cell complex after reduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
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

      //coreduction(0);
      //coreduction(1);
      //coreduction(2);
      coreductionMrozek(cell);
    }
    if(generatorDim == i) break;
    
  }
  /*
  for(int i = 0; i < 4; i++){
    for(citer cit = generatorCells[i].begin(); cit != generatorCells[i].end(); cit++){
      Cell* cell = *cit;
      if(!cell->inSubdomain()) _cells[i].insert(cell); 
    }
  }
  */
  printf("Cell complex after coreduction: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  return;
}


void CellComplex::replaceCells(Cell* c1, Cell* c2, Cell* newCell, bool orMatch, bool co){

  int dim = c1->getDim();
  
  std::list< std::pair<int, Cell*> > coboundary1 = c1->getOrientedCoboundary();
  std::list< std::pair<int, Cell*> > coboundary2 = c2->getOrientedCoboundary();
  std::list< std::pair<int, Cell*> > boundary1 = c1->getOrientedBoundary();
  std::list< std::pair<int, Cell*> > boundary2 = c2->getOrientedBoundary();
  
  
  for(std::list< std::pair<int, Cell*> >::iterator it = coboundary1.begin(); it != coboundary1.end(); it++){
    Cell* cbdCell = (*it).second;
    int ori = (*it).first;
    cbdCell->removeBoundaryCell(c1);
    cbdCell->addBoundaryCell(ori, newCell);
  }
  for(std::list< std::pair<int, Cell*> >::iterator it = coboundary2.begin(); it != coboundary2.end(); it++){
    Cell* cbdCell = (*it).second;
    int ori  = (*it).first;
    if(!orMatch) ori = -1*ori;
    cbdCell->removeBoundaryCell(c2);
    if(!co){
      bool old = false;
      for(std::list< std::pair<int, Cell* > >::iterator it2 = coboundary1.begin(); it2 != coboundary1.end(); it2++){
        Cell* cell2 = (*it2).second;
        if(*cell2 == *cbdCell) old = true;
      }
      if(!old) cbdCell->addBoundaryCell(ori, newCell);
    }
    else cbdCell->addBoundaryCell(ori, newCell);
  }
  
  for(std::list< std::pair<int, Cell* > >::iterator it = boundary1.begin(); it != boundary1.end(); it++){
    Cell* bdCell = (*it).second;
    int ori = (*it).first;
    bdCell->removeCoboundaryCell(c1);
    bdCell->addCoboundaryCell(ori, newCell);
  }
  for(std::list< std::pair<int, Cell* > >::iterator it = boundary2.begin(); it != boundary2.end(); it++){
    Cell* bdCell = (*it).second;
    int ori = (*it).first;
    if(!orMatch) ori = -1*ori;
    bdCell->removeCoboundaryCell(c2);
    if(co){
      bool old = false;
      for(std::list< std::pair<int, Cell* > >::iterator it2 = boundary1.begin(); it2 != boundary1.end(); it2++){
        Cell* cell2 = (*it2).second;
        if(*cell2 == *bdCell) old = true;
      }
      if(!old)  bdCell->addCoboundaryCell(ori, newCell);
    }
    else bdCell->addCoboundaryCell(ori, newCell);
    
  }
  
  _cells[dim].erase(c1);
  _cells[dim].erase(c2);
  _cells[dim].insert(newCell);
  
  
  
  return;
}

int CellComplex::cocombine(int dim){
 
  printf("Cell complex before cocombining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 1 || dim > 3) return 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::list<Cell*> cbd_c;
  std::list< std::pair< int, Cell*> > bd_c;
  int count = 0;
  
  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
  
    Cell* cell = *cit;
    cbd_c = cell->getCoboundary();
    enqueueCells(cbd_c, Q, Qset);
    while(Q.size() != 0){

      Cell* s = Q.front();
      Q.pop();
      
      bd_c = s->getOrientedBoundary();
      
      if(bd_c.size() == 2 && !(*(bd_c.front().second) == *(bd_c.back().second)) 
         && inSameDomain(s, bd_c.front().second) && inSameDomain(s, bd_c.back().second) ){
        
        Cell* c1 = bd_c.front().second;
        Cell* c2 = bd_c.back().second;
        
        cbd_c = c1->getCoboundary();
        enqueueCells(cbd_c, Q, Qset);
        cbd_c = c2->getCoboundary();
        enqueueCells(cbd_c, Q, Qset);
        
        int or1 = bd_c.front().first;
        int or2 = bd_c.back().first;
                
        removeCell(s);
        CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2), true );
        replaceCells(c1, c2, newCell, (or1 != or2), true);
        
        cit = firstCell(dim);
        count++;
      }
      removeCellQset(s, Qset);
      
    }
  }
  
  printf("Cell complex after cocombining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
  
  return count;
}

int CellComplex::combine(int dim){
  
  printf("Cell complex before combining: %d volumes, %d faces, %d edges and %d vertices.\n",
         getSize(3), getSize(2), getSize(1), getSize(0));
    
  if(dim < 1 || dim > 3) return 0;
  
  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::list< std::pair<int, Cell*> > cbd_c;
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
        
      if(cbd_c.size() == 2 && !(*(cbd_c.front().second) == *(cbd_c.back().second)) 
         && inSameDomain(s, cbd_c.front().second) && inSameDomain(s, cbd_c.back().second) ){
        
        Cell* c1 = cbd_c.front().second;
        Cell* c2 = cbd_c.back().second;
        
        bd_c = c1->getBoundary();
        enqueueCells(bd_c, Q, Qset);
        bd_c = c2->getBoundary();
        enqueueCells(bd_c, Q, Qset);
        
        int or1 = cbd_c.front().first;
        int or2 = cbd_c.back().first;
        
        removeCell(s);
        CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2) );
        replaceCells(c1, c2, newCell, (or1 != or2));
        
        cit = firstCell(dim);
        count++;
      }
      removeCellQset(s, Qset);
      
    }
  }
  
  printf("Cell complex after combining: %d volumes, %d faces, %d edges and %d vertices.\n",
          getSize(3), getSize(2), getSize(1), getSize(0));
  
  
  return count;
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
  
  
  
  fprintf(fp, "$MeshFormat\n2.0 0 8\n$EndMeshFormat\n");
  
  fprintf(fp, "$Nodes\n");
  
  fprintf(fp, "%d\n", _domainVertices.size());
  
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
      
  fprintf(fp, "%d\n", count);

  int physical = 0;
  
  for(citer cit = firstCell(0); cit != lastCell(0); cit++) {
    Cell* vertex = *cit;
    if(vertex->inSubdomain()) physical = 3;
    else if(vertex->onDomainBoundary()) physical = 2;
    else physical = 1;
     fprintf(fp, "%d %d %d %d %d %d %d\n", vertex->getTag(), 15, 3, 0, 0, physical, vertex->getVertex(0));
  }
  
  std::list< std::pair<int, Cell*> > cells;
  for(citer cit = firstCell(1); cit != lastCell(1); cit++) {
    Cell* edge = *cit;
    if(edge->inSubdomain()) physical = 3;
    else if(edge->onDomainBoundary()) physical = 2;
    else physical = 1;
    cells = edge->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell = (*it).second;
      fprintf(fp, "%d %d %d %d %d %d %d %d\n", cell->getTag(), 1, 3, 0, 0, physical, cell->getVertex(0), cell->getVertex(1));
    }
  }
  
  for(citer cit = firstCell(2); cit != lastCell(2); cit++) {
    Cell* face = *cit;
    if(face->inSubdomain()) physical = 3;
    else if(face->onDomainBoundary()) physical = 2;
    else physical = 1;
    cells = face->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell = (*it).second;
      fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", cell->getTag(), 2, 3, 0, 0, physical, cell->getVertex(0), cell->getVertex(1), cell->getVertex(2));
    }
  }
  for(citer cit = firstCell(3); cit != lastCell(3); cit++) {
    Cell* volume = *cit;
    if(volume->inSubdomain()) physical = 3;
    else if(volume->onDomainBoundary()) physical = 2;
    else physical = 1;
    cells = volume->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell = (*it).second;
      fprintf(fp, "%d %d %d %d %d %d %d %d %d %d\n", cell->getTag(), 4, 3, 0, 0, physical, cell->getVertex(0), cell->getVertex(1), cell->getVertex(2), cell->getVertex(3));
    }
  }
    
  fprintf(fp, "$EndElements\n");
  
  fclose(fp);
  
  return 1;
}


void CellComplex::printComplex(int dim){
  for (citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    for(int i = 0; i < cell->getNumVertices(); i++){
      printf("%d ", cell->getVertex(i));
    }
    printf("\n");
  }
}


  
