// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "CellComplex.h"
#include "MElement.h"

CellComplex::CellComplex(GModel* model,
			 std::vector<MElement*>& domainElements,
			 std::vector<MElement*>& subdomainElements,
                         bool saveOriginalComplex) :
  _model(model), _dim(0), _simplicial(true), _saveorig(saveOriginalComplex)
{
  _deleteCount = 0;
  _insertCells(subdomainElements, 1);
  _insertCells(domainElements, 0);

  int num = 0;
  for(int dim = 0; dim < 4; dim++){
    if(getSize(dim) != 0) _dim = dim;
    if(_saveorig) _ocells[dim] = _cells[dim];
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      cell->setNum(++num);
      cell->increaseGlobalNum();
      cell->saveOriginalBd();
    }
  }
}

bool CellComplex::_insertCells(std::vector<MElement*>& elements,
			       int domain)
{
  for(unsigned int i=0; i < elements.size(); i++){
    MElement* element = elements.at(i);
    int type = element->getType();
    if(type == TYPE_PYR || type == TYPE_PRI ||
       type == TYPE_POLYG || type == TYPE_POLYH) {
      Msg::Error("Mesh element type %d not implemented in homology solver", type);
      return false;
    }
    if(type == TYPE_QUA || type == TYPE_HEX)
      _simplicial = false;
    Cell* cell = new Cell(element, domain);
    bool insert = _cells[cell->getDim()].insert(cell).second;
    if(!insert) delete cell;
  }

  for (int dim = 3; dim > 0; dim--){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      for(int i = 0; i < cell->getNumBdElements(); i++){
	Cell* newCell = new Cell(cell, i);
	std::pair<citer, bool> insert =
	  _cells[newCell->getDim()].insert(newCell);
	if(!insert.second) {
	  delete newCell;
	  newCell = *(insert.first);
	}
	if(domain == 0) {
	  int ori = cell->findBdCellOrientation(newCell, i);
	  cell->addBoundaryCell( ori, newCell, true);
	}
      }
    }
  }
  return true;
}

CellComplex::~CellComplex()
{
  for(int i = 0; i < 4; i++){
    if(_saveorig) {
      for(citer cit = _ocells[i].begin(); cit != _ocells[i].end(); cit++){
        Cell* cell = *cit;
        delete cell;
        _deleteCount++;
      }
    }
    else {
      for(citer cit = _cells[i].begin(); cit != _cells[i].end(); cit++){
        Cell* cell = *cit;
        delete cell;
        _deleteCount++;
      }
    }
  }
  for(unsigned int i = 0; i < _newcells.size(); i++) {
    delete _newcells.at(i);
    _deleteCount++;
  }
  for(unsigned int i = 0; i < _removedcells.size(); i++) {
    delete _removedcells.at(i);
    _deleteCount++;
  }
  Msg::Debug("Total number of cells created: %d", _deleteCount);
}

void CellComplex::insertCell(Cell* cell)
{
  if(_saveorig) _newcells.push_back(cell);
  std::pair<citer, bool> insertInfo = _cells[cell->getDim()].insert(cell);
  if(!insertInfo.second){
    Msg::Debug("Cell not inserted");
    Cell* oldCell = (*insertInfo.first);
    cell->printCell();
    oldCell->printCell();
  }
}

void CellComplex::removeCell(Cell* cell, bool other)
{
  std::map<Cell*, short int, Less_Cell > coboundary;
  cell->getCoboundary(coboundary);
  std::map<Cell*, short int, Less_Cell > boundary;
  cell->getBoundary(boundary);

  for(std::map<Cell*, short int, Less_Cell>::iterator it =
        coboundary.begin(); it != coboundary.end(); it++){
    Cell* cbdCell = (*it).first;
    cbdCell->removeBoundaryCell(cell, other);
  }

  for(std::map<Cell*, short int, Less_Cell>::iterator it =
        boundary.begin(); it != boundary.end(); it++){
    Cell* bdCell = (*it).first;
    bdCell->removeCoboundaryCell(cell, other);
  }

  int erased = _cells[cell->getDim()].erase(cell);
  if(!erased) Msg::Debug("Tried to remove a cell from the cell complex \n");
  if(!_saveorig) _removedcells.push_back(cell);
}

void CellComplex::enqueueCells(std::map<Cell*, short int, Less_Cell>& cells,
			       std::queue<Cell*>& Q,
			       std::set<Cell*, Less_Cell>& Qset)
{
  for(std::map<Cell*, short int, Less_Cell>::iterator cit = cells.begin();
      cit != cells.end(); cit++){
    Cell* cell = (*cit).first;
    citer it = Qset.find(cell);
    if(it == Qset.end()){
      Qset.insert(cell);
      Q.push(cell);
    }
  }
}

int CellComplex::coreduction(Cell* startCell, bool omit,
			     std::vector<Cell*>& omittedCells)
{
  int coreductions = 0;

  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;

  Q.push(startCell);
  Qset.insert(startCell);

  std::map<Cell*, short int, Less_Cell > bd_s;
  std::map<Cell*, short int, Less_Cell > cbd_c;

  Cell* s;
  while( !Q.empty() ){
    s = Q.front();
    Q.pop();
    Qset.erase(s);
    if(s->getBoundarySize() == 1
       && inSameDomain(s, s->firstBoundary()->first) ){
      s->getBoundary(bd_s);
      removeCell(s);
      bd_s.begin()->first->getCoboundary(cbd_c);
      enqueueCells(cbd_c, Q, Qset);
      removeCell(bd_s.begin()->first);
      if(bd_s.begin()->first->getDim() == 0 && omit){
	omittedCells.push_back(bd_s.begin()->first);
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

int CellComplex::reduction(int dim, bool omit,
			   std::vector<Cell*>& omittedCells)
{
  if(dim < 1 || dim > 3) return 0;

  int count = 0;

  bool reduced = true;
  while (reduced){

    reduced = false;
    citer cit = firstCell(dim-1);
    while(cit != lastCell(dim-1)){
      Cell* cell = *cit;
      if( cell->getCoboundarySize() == 1
	  && inSameDomain(cell, cell->firstCoboundary()->first)){
	cit++;
	if(dim == getDim() && omit){
	  omittedCells.push_back(cell->firstCoboundary()->first);
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

int CellComplex::coreduction(int dim, bool omit,
			     std::vector<Cell*>& omittedCells)
{
  if(dim < 1 || dim > 3) return 0;

  int count = 0;

  bool reduced = true;
  while (reduced){

    reduced = false;
    citer cit = firstCell(dim);
    while(cit != lastCell(dim)){
      Cell* cell = *cit;
      if( cell->getBoundarySize() == 1
          && inSameDomain(cell, cell->firstBoundary()->first)){
        ++cit;
	if(dim-1 == 0 && omit){
	  omittedCells.push_back(cell->firstBoundary()->first);
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

int CellComplex::reduceComplex(bool docombine, bool omit)
{
  Msg::Debug("Cell Complex reduction:");
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
            getSize(3), getSize(2), getSize(1), getSize(0));

  int count = 0;
  std::vector<Cell*> empty;
  for(int i = 3; i > 0; i--) count = count + reduction(i, false, empty);

  if(omit){

    removeSubdomain();
    std::vector<Cell*> newCells;

    while (getSize(getDim()) != 0){

      citer cit = firstCell(getDim());
      Cell* cell = *cit;

      removeCell(cell, false);
      std::vector<Cell*> omittedCells;
      omittedCells.push_back(cell);

      for(int j = 3; j > 0; j--) reduction(j, true, omittedCells);
      CombinedCell* newcell = new CombinedCell(omittedCells);
      newCells.push_back(newcell);
    }
    for(unsigned int i = 0; i < newCells.size(); i++){
      insertCell(newCells.at(i));
    }
  }

  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
            getSize(3), getSize(2), getSize(1), getSize(0));

  if(docombine) combine(3);
  reduction(2, false, empty);
  if(docombine) combine(2);
  reduction(1, false, empty);
  if(docombine) combine(1);

  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
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

int CellComplex::coreduceComplex(bool docombine, bool omit)
{
  Msg::Debug("Cell Complex coreduction:");
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
            getSize(3), getSize(2), getSize(1), getSize(0));

  int count = 0;
  removeSubdomain();
  std::vector<Cell*> empty;
  for(int dim = 0; dim < 4; dim++){
    citer cit = firstCell(dim);
    while(cit != lastCell(dim)){
      Cell* cell = *cit;
      count = count + coreduction(cell, false, empty);
      if(count != 0) break;
      cit++;
    }
  }

  if(omit){
    std::vector<Cell*> newCells;
    while (getSize(0) != 0){
      citer cit = firstCell(0);
      Cell* cell = *cit;

      removeCell(cell, false);
      std::vector<Cell*> omittedCells;
      omittedCells.push_back(cell);

      coreduction(cell, true, omittedCells);
      CombinedCell* newcell = new CombinedCell(omittedCells);
      newCells.push_back(newcell);
    }
    for(unsigned int i = 0; i < newCells.size(); i++){
      insertCell(newCells.at(i));
    }
  }

  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
            getSize(3), getSize(2), getSize(1), getSize(0));

  if(docombine) cocombine(0);
  coreduction(1, false, empty);
  if(docombine) cocombine(1);
  coreduction(2, false, empty);
  if(docombine) cocombine(2);
  coreduction(3, false, empty);
  coherent();
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
            getSize(3), getSize(2), getSize(1), getSize(0));

  return 0;
}

int CellComplex::combine(int dim)
{
  Msg::Debug("Cell complex before combining:");
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
             getSize(3), getSize(2), getSize(1), getSize(0));
  if(dim < 1 || dim > 3) return 0;

  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::map<Cell*, short int, Less_Cell> bd_c;
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
        int or1 = it->second.get();
        Cell* c1 = it->first;
	it++;
        while (it->second.get() == 0) it++;
        int or2 = it->second.get();
        Cell* c2 = it->first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2)
           && inSameDomain(s, c1) && inSameDomain(s, c2)){
          removeCell(s);

          c1->getBoundary(bd_c);
          enqueueCells(bd_c, Q, Qset);
          c2->getBoundary(bd_c);
          enqueueCells(bd_c, Q, Qset);

	  CombinedCell* newCell = new CombinedCell(c1, c2, (or1 != or2));
          removeCell(c1);
          removeCell(c2);
          insertCell(newCell);

          cit = firstCell(dim);
          count++;
        }
      }
      Qset.erase(s);
    }
  }

  Msg::Debug("Cell complex after combining:");
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
             getSize(3), getSize(2), getSize(1), getSize(0));

  return count;
}


int CellComplex::cocombine(int dim)
{
  Msg::Debug("Cell complex before cocombining:");
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
             getSize(3), getSize(2), getSize(1), getSize(0));

  if(dim < 0 || dim > 2) return 0;

  std::queue<Cell*> Q;
  std::set<Cell*, Less_Cell> Qset;
  std::map<Cell*, short int, Less_Cell> cbd_c;
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
        int or1 = it->second.get();
        Cell* c1 = it->first;
	it++;
        while (it->second.get() == 0) it++;
        int or2 = it->second.get();
        Cell* c2 = it->first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2)
           && inSameDomain(s, c1) && inSameDomain(s, c2)){
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
      Qset.erase(s);
    }
  }

  Msg::Debug("Cell complex after cocombining:");
  Msg::Debug(" %d volumes, %d faces, %d edges and %d vertices",
             getSize(3), getSize(2), getSize(1), getSize(0));

  return count;
}

bool CellComplex::coherent()
{
  bool coherent = true;
  for(int i = 0; i < 4; i++){
    for(citer cit = firstCell(i); cit != lastCell(i); cit++){
      Cell* cell = *cit;
      std::map<Cell*, short int, Less_Cell> boundary;
      cell->getBoundary(boundary);
      for(std::map<Cell*, short int, Less_Cell>::iterator it = boundary.begin();
	  it != boundary.end(); it++){
        Cell* bdCell = (*it).first;
        int ori = (*it).second;
        citer cit = _cells[bdCell->getDim()].find(bdCell);
        if(cit == lastCell(bdCell->getDim())){
          Msg::Debug("Boundary cell not in cell complex! Boundary removed");
          cell->removeBoundaryCell(bdCell, false);
          coherent = false;
        }
        if(!bdCell->hasCoboundary(cell)){
          Msg::Debug("Incoherent boundary/coboundary pair! Fixed");
	  bdCell->addCoboundaryCell(ori, cell, false);
          coherent = false;
        }

      }
      std::map<Cell*, short int, Less_Cell> coboundary;
      cell->getCoboundary(coboundary);
      for(std::map<Cell*, short int, Less_Cell>::iterator it = coboundary.begin();
	  it != coboundary.end(); it++){
        Cell* cbdCell = (*it).first;
        int ori = (*it).second;
        citer cit = _cells[cbdCell->getDim()].find(cbdCell);
        if(cit == lastCell(cbdCell->getDim())){
          Msg::Debug("Coboundary cell not in cell complex! Coboundary removed");
          cell->removeCoboundaryCell(cbdCell, false);
          coherent = false;
        }
        if(!cbdCell->hasBoundary(cell)){
          Msg::Debug("Incoherent coboundary/boundary pair! Fixed");
	  cbdCell->addBoundaryCell(ori, cell, false);
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

bool CellComplex::restoreComplex()
{
  if(_saveorig){
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
      _deleteCount++;
    }
    _newcells.clear();
    return true;
  }
  else {
    Msg::Error("Cannot restore cell complex");
    return false;
  }
}

void CellComplex::printComplex(int dim)
{
  if(getSize(dim) == 0)
    Msg::Info("Cell complex dimension %d is empty", dim);
  for (citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = *cit;
    cell->printCell();
    //cell->printBoundary();
    //cell->printCoboundary();
    //printf("--- \n");
  }
}

int CellComplex::saveComplex(std::string filename)
{
  /*FILE *fp = fopen (filename.c_str(), "w");
  if(!fp){
    printf("\nUnable to open file '%s' \n", filename.c_str());
    return 0;
  }
  printf("\nWriting file '%s' ... \n", filename.c_str());

  fprintf(fp, "$Cells\n");
  fprintf(fp, "%d\n", getSize(0)+getSize(1)+getSize(2)+getSize(3));
  for(int dim = 0; dim < 4; dim++){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      fprintf(fp, "%d %d %d %d %d", cell->getNum(), cell->getType(),
	      1, cell->getDomain(), cell->getNumVertices());
      for(int i = 0; i < cell->getNumVertices(); i++){
	fprintf(fp, " %d", cell->getVertex(i));
      }
      fprintf(fp, " %d", cell->getBoundarySize());
      for(Cell::biter bit = cell->firstBoundary();
	  bit != cell->lastBoundary(); bit++){
	fprintf(fp, " %d %d", bit->first->getNum(), bit->second);
      }
      fprintf(fp, " %d", cell->getCoboundarySize());
      for(Cell::biter bit = cell->firstCoboundary();
	  bit != cell->lastCoboundary(); bit++){
	fprintf(fp, " %d %d", bit->first->getNum(), bit->second);
      }
      fprintf(fp, "\n");
    }
  }

  fclose(fp);

  printf("Wrote %d cells to '%s' \n",
	 getSize(0)+getSize(1)+getSize(2)+getSize(3), filename.c_str());
  */
  return 1;
}

int CellComplex::loadComplex(std::string filename)
{
  /*  FILE *fp = fopen (filename.c_str(), "r");
  if(!fp){
    printf("\nUnable to open file '%s' \n", filename.c_str());
    return 0;
  }

  std::map<int, Cell*> numToCell;

  char str[256] = "XXX";
  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }

    if(feof(fp))
      break;

    if(!strncmp(&str[1], "Cells", 5)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numCells;
      sscanf(str, "%d", &numCells);
      for(int i = 0; i < numCells; i++) {
	int num, type, numTags;
	std::vector<int> domain;
	int tag;
	if(fscanf(fp, "%d %d %d", &num, &type, &numTags) != 3) return 0;
	for(int j = 0; j < numTags; j++){
	  if(fscanf(fp, "%d", &tag) != 1) return 0;
	  domain.push_back(tag);
	}

	std::vector<int> vertices;
	if(fscanf(fp, "%d", &numTags) != 1) return 0;
	for(int j = 0; j < numTags; j++){
	  if(fscanf(fp, "%d", &tag) != 1) return 0;
	  vertices.push_back(tag);
	}

	int dim = 0;
	if(type == 1){
	  if(vertices.size() == 2) dim = 1;
	  else if(vertices.size() == 3) dim = 2;
	  else if(vertices.size() == 4) dim = 3;
	}

	Cell* cell = new Cell(num, dim, type, domain, vertices);
	numToCell[num] = cell;


	int numCell;
	if(fscanf(fp, "%d", &numTags) != 1) return 0;
	for(int j = 0; j < numTags; j++){
	  if(fscanf(fp, "%d %d", &numCell, &tag) != 1) return 0;
	}
	if(fscanf(fp, "%d", &numTags) != 1) return 0;
	for(int j = 0; j < numTags; j++){
	  if(fscanf(fp, "%d %d", &numCell, &tag) != 1) return 0;
	}

      }
    }

  }

  fclose(fp);
*/
  return 1;
}
