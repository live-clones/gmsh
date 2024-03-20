// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#include "CellComplex.h"
#include "MElement.h"
#include "OS.h"

double CellComplex::_patience = 10;

CellComplex::CellComplex(GModel *model, std::vector<MElement *> &domainElements,
                         std::vector<MElement *> &subdomainElements,
                         std::vector<MElement *> &nondomainElements,
                         std::vector<MElement *> &nonsubdomainElements,
                         std::vector<MElement *> &immuneElements,
                         bool saveOriginalComplex)
  : _model(model), _dim(0), _simplicial(true), _saveorig(saveOriginalComplex),
    _relative(false)
{
  _smallestCell.second = -1.;
  _biggestCell.second = -1.;
  _deleteCount = 0;
  _createCount = 0;
  _insertCells(subdomainElements, 1);
  if(getSize(0) > 0) _relative = true;
  for(int i = 0; i < 4; i++) _numSubdomainCells[i] = getSize(i);

  _insertCells(domainElements, 0);
  for(int i = 0; i < 4; i++)
    _numRelativeCells[i] = getSize(i) - _numSubdomainCells[i];

  _removeCells(nonsubdomainElements, 1);
  _removeCells(nondomainElements, 0);
  _immunizeCells(immuneElements);
  int num = 0;
  for(int dim = 0; dim < 4; dim++) {
    if(getSize(dim) != 0) _dim = dim;
    if(_saveorig) _ocells[dim] = _cells[dim];
    for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
      Cell *cell = *cit;
      cell->setNum(++num);
      cell->increaseGlobalNum();
      cell->saveCellBoundary();
    }
  }

  _reduced = false;

  Msg::Debug("Cells in domain:");
  Msg::Debug(" %d volumes, %d faces, %d edges, and %d vertices",
             getNumCells(3, 1), getNumCells(2, 1), getNumCells(1, 1),
             getNumCells(0, 1));
  Msg::Debug("Cells in subdomain:");
  Msg::Debug(" %d volumes, %d faces, %d edges, and %d vertices",
             getNumCells(3, 2), getNumCells(2, 2), getNumCells(1, 2),
             getNumCells(0, 2));
  Msg::Debug("Cells in relative domain:");
  Msg::Debug(" %d volumes, %d faces, %d edges, and %d vertices",
             getNumCells(3, 0), getNumCells(2, 0), getNumCells(1, 0),
             getNumCells(0, 0));
}

bool CellComplex::_insertCells(std::vector<MElement *> &elements, int domain)
{
  std::pair<Cell *, double> smallestElement[4];
  std::pair<Cell *, double> biggestElement[4];
  for(int i = 0; i < 4; i++) {
    smallestElement[i].second = -1.;
    biggestElement[i].second = -1.;
  }
  _dim = 0;

  double t1 = Cpu();

  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *element = elements.at(i);
    int dim = element->getDim();
    int type = element->getType();
    if(type == TYPE_POLYG || type == TYPE_POLYH) {
      Msg::Error("Mesh element type %d not implemented in homology solver",
                 type);
    }
    if(type == TYPE_QUA || type == TYPE_HEX || type == TYPE_PYR ||
       type == TYPE_PRI)
      _simplicial = false;
    std::pair<Cell *, bool> maybeCell = Cell::createCell(element, domain);
    if(!maybeCell.second) {
      delete maybeCell.first;
      continue;
    }

    if(_dim < dim) _dim = dim;
    Cell *cell = maybeCell.first;
    std::pair<citer, bool> insert = _cells[cell->getDim()].insert(cell);
    if(!insert.second) {
      delete cell;
      cell = *(insert.first);
      if(domain) cell->setDomain(domain);
    }
    else
      _createCount++;

    if(domain == 0) {
      double size = fabs(element->getVolume());
      if(smallestElement[dim].second < 0. || smallestElement[dim].second > size)
        smallestElement[dim] = std::make_pair(cell, size);
      if(biggestElement[dim].second < 0. || biggestElement[dim].second < size)
        biggestElement[dim] = std::make_pair(cell, size);
    }
  }
  _smallestCell = smallestElement[_dim];
  _biggestCell = biggestElement[_dim];

  for(int dim = 3; dim > 0; dim--) {
    double t2 = Cpu();
    if(t2 - t1 > CellComplex::_patience && dim > 1) {
      if(domain == 0)
        Msg::Info(" - Creating domain %d-cells", dim);
      else if(domain == 1)
        Msg::Info(" - Creating subdomain %d-cells", dim);
    }

    for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
      Cell *cell = *cit;
      for(int i = 0; i < cell->getNumBdElements(); i++) {
        std::pair<Cell *, bool> maybeCell = Cell::createCell(cell, i);
        if(!maybeCell.second) {
          delete maybeCell.first;
          continue;
        }
        Cell *newCell = maybeCell.first;
        std::pair<citer, bool> insert =
          _cells[newCell->getDim()].insert(newCell);
        if(!insert.second) {
          delete newCell;
          newCell = *(insert.first);
          if(domain) newCell->setDomain(domain);
        }
        else
          _createCount++;
        if(domain == 0) {
          int ori = cell->findBdCellOrientation(newCell, i);
          cell->addBoundaryCell(ori, newCell, true);
          if(_smallestCell.first == cell)
            _smallestCell = std::make_pair(newCell, _smallestCell.second);
          if(_biggestCell.first == cell)
            _biggestCell = std::make_pair(newCell, _biggestCell.second);
        }
      }
    }
  }
  return true;
}

bool CellComplex::_removeCells(std::vector<MElement *> &elements, int domain)
{
  if(elements.empty()) return true;
  Msg::Debug("Removing %d elements and their subcells from the cell complex.",
             (int)elements.size());
  std::set<Cell *, CellPtrLessThan> removed[4];

  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *element = elements.at(i);
    int type = element->getType();
    if(type == TYPE_PYR || type == TYPE_PRI || type == TYPE_POLYG ||
       type == TYPE_POLYH) {
      Msg::Error("Mesh element type %d not implemented in homology solver",
                 type);
      return false;
    }
    Cell *cell = new Cell(element, domain);
    int dim = cell->getDim();
    auto cit = _cells[dim].find(cell);
    if(cit != lastCell(dim)) {
      removeCell(*cit);
      removed[dim].insert(cell);
    }
    else
      delete cell;
  }

  for(int dim = 3; dim > 0; dim--) {
    for(auto cit = removed[dim].begin(); cit != removed[dim].end(); cit++) {
      Cell *cell = *cit;
      for(int i = 0; i < cell->getNumBdElements(); i++) {
        Cell *newCell = new Cell(cell, i);

        auto cit2 = _cells[dim - 1].find(newCell);
        if(cit2 != lastCell(dim - 1)) {
          removeCell(*cit2);
          removed[dim - 1].insert(newCell);
        }
        else
          delete newCell;
      }
    }
  }
  for(int dim = 3; dim >= 0; dim--) {
    for(auto cit = removed[dim].begin(); cit != removed[dim].end(); cit++) {
      delete *cit;
    }
  }
  Msg::Debug("Removed %d volumes, %d faces, %d edges, and %d vertices from the "
             "cell complex",
             (int)removed[3].size(), (int)removed[2].size(),
             (int)removed[1].size(), (int)removed[0].size());
  return true;
}

bool CellComplex::_immunizeCells(std::vector<MElement *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *element = elements.at(i);
    Cell *cell = new Cell(element, 0);
    int dim = cell->getDim();
    auto cit = _cells[dim].find(cell);
    if(cit != lastCell(dim)) (*cit)->setImmune(true);
    delete cell;
  }
  return true;
}

CellComplex::~CellComplex()
{
  for(int i = 0; i < 4; i++) {
    for(auto cit = _cells[i].begin(); cit != _cells[i].end(); cit++) {
      Cell *cell = *cit;
      delete cell;
      _deleteCount++;
    }
  }

  for(std::size_t i = 0; i < _removedcells.size(); i++) {
    delete _removedcells.at(i);
    _deleteCount++;
  }

  Msg::Debug("Total number of cells created: %d", _createCount);
  Msg::Debug("Total number of cells deleted: %d", _deleteCount);
}

void CellComplex::insertCell(Cell *cell)
{
  std::pair<citer, bool> insertInfo = _cells[cell->getDim()].insert(cell);
  if(!insertInfo.second) {
    Msg::Debug("Cell not inserted");
    Cell *oldCell = (*insertInfo.first);
    cell->printCell();
    oldCell->printCell();
  }
}

void CellComplex::removeCell(Cell *cell, bool other, bool del)
{
  std::map<Cell *, short int, CellPtrLessThan> coboundary;
  cell->getCoboundary(coboundary);
  std::map<Cell *, short int, CellPtrLessThan> boundary;
  cell->getBoundary(boundary);

  for(auto it = coboundary.begin(); it != coboundary.end(); it++) {
    Cell *cbdCell = (*it).first;
    cbdCell->removeBoundaryCell(cell, other);
  }

  for(auto it = boundary.begin(); it != boundary.end(); it++) {
    Cell *bdCell = (*it).first;
    bdCell->removeCoboundaryCell(cell, other);
  }

  int dim = cell->getDim();
  int erased = _cells[dim].erase(cell);
  if(relative()) {
    if(cell->inSubdomain())
      _numSubdomainCells[dim] -= 1;
    else
      _numRelativeCells[dim] -= 1;
  }
  if(!erased)
    Msg::Debug("Tried to remove a cell from the cell complex \n");
  else if(!del)
    _removedcells.push_back(cell);
}

void CellComplex::enqueueCells(
  std::map<Cell *, short int, CellPtrLessThan> &cells, std::queue<Cell *> &Q,
  std::set<Cell *, CellPtrLessThan> &Qset)
{
  for(auto cit = cells.begin(); cit != cells.end(); cit++) {
    Cell *cell = (*cit).first;
    auto it = Qset.find(cell);
    if(it == Qset.end()) {
      Qset.insert(cell);
      Q.push(cell);
    }
  }
}

int CellComplex::coreduction(Cell *startCell, int omit,
                             std::vector<Cell *> &omittedCells)
{
  int coreductions = 0;

  std::queue<Cell *> Q;
  std::set<Cell *, CellPtrLessThan> Qset;

  Q.push(startCell);
  Qset.insert(startCell);

  std::map<Cell *, short int, CellPtrLessThan> bd_s;
  std::map<Cell *, short int, CellPtrLessThan> cbd_c;

  Cell *s;
  while(!Q.empty()) {
    s = Q.front();
    Q.pop();
    Qset.erase(s);
    if(s->getBoundarySize() == 1 &&
       inSameDomain(s, s->firstBoundary()->first) && !s->getImmune() &&
       !s->firstBoundary()->first->getImmune() &&
       abs(s->firstBoundary()->second.get()) < 2) {
      s->getBoundary(bd_s);
      removeCell(s);
      bd_s.begin()->first->getCoboundary(cbd_c);
      enqueueCells(cbd_c, Q, Qset);
      removeCell(bd_s.begin()->first);
      if(bd_s.begin()->first->getDim() == omit) {
        omittedCells.push_back(bd_s.begin()->first);
      }
      coreductions++;
    }
    else if(s->getBoundarySize() == 0) {
      s->getCoboundary(cbd_c);
      enqueueCells(cbd_c, Q, Qset);
    }
  }
  _reduced = true;
  return coreductions;
}

int CellComplex::reduction(int dim, int omit, std::vector<Cell *> &omittedCells)
{
  if(dim < 1 || dim > 3) return 0;

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  int count = 0;

  bool reduced = true;
  while(reduced) {
    reduced = false;
    auto cit = firstCell(dim - 1);
    while(cit != lastCell(dim - 1)) {
      Cell *cell = *cit;
      if(cell->getCoboundarySize() == 1 &&
         inSameDomain(cell, cell->firstCoboundary()->first) &&
         !cell->getImmune() && !cell->firstCoboundary()->first->getImmune() &&
         !cell->firstCoboundary()->first->getImmune() &&
         abs(cell->firstCoboundary()->second.get()) < 2) {
        cit++;
        if(dim == omit) {
          omittedCells.push_back(cell->firstCoboundary()->first);
        }
        removeCell(cell->firstCoboundary()->first);
        removeCell(cell);
        count++;
        reduced = true;
      }

      if(getSize(dim) == 0 || getSize(dim - 1) == 0) break;
      if(cit != lastCell(dim - 1)) cit++;
    }
  }
  _reduced = true;
  Msg::Debug("Cell complex %d-reduction removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  return count;
}

int CellComplex::coreduction(int dim, int omit,
                             std::vector<Cell *> &omittedCells)
{
  if(dim < 1 || dim > 3) return 0;

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  int count = 0;

  bool reduced = true;
  while(reduced) {
    reduced = false;
    auto cit = firstCell(dim);
    while(cit != lastCell(dim)) {
      Cell *cell = *cit;
      if(cell->getBoundarySize() == 1 &&
         inSameDomain(cell, cell->firstBoundary()->first) &&
         !cell->getImmune() && !cell->firstBoundary()->first->getImmune() &&
         abs(cell->firstBoundary()->second.get()) < 2) {
        ++cit;
        if(dim - 1 == omit) {
          omittedCells.push_back(cell->firstBoundary()->first);
        }
        removeCell(cell->firstBoundary()->first);
        removeCell(cell);
        count++;
        reduced = true;
      }

      if(getSize(dim) == 0 || getSize(dim - 1) == 0) break;
      if(cit != lastCell(dim)) cit++;
    }
  }
  _reduced = true;
  Msg::Debug("Cell complex %d-coreduction removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  return count;
}

int CellComplex::getSize(int dim, bool orig)
{
  if(dim == -1) {
    std::size_t size = 0;
    if(!orig)
      for(int i = 0; i < 4; i++) size += _cells[i].size();
    else
      for(int i = 0; i < 4; i++) size += _ocells[i].size();
    return size;
  }
  if(!orig)
    return _cells[dim].size();
  else
    return _ocells[dim].size();
}

int CellComplex::getDomain(Cell *cell, std::string &str)
{
  int domain = 0;
  if(cell->inSubdomain()) {
    str = "subdomain";
    domain = 2;
  }
  if(!cell->inSubdomain()) {
    if(relative()) {
      str = "relative domain";
      domain = 0;
    }
    else {
      str = "domain";
      domain = 1;
    }
  }
  return domain;
}

Cell *CellComplex::_omitCell(Cell *cell, bool dual)
{
  Msg::Debug("Omitting %d-cell from the cell complex", cell->getDim());
  removeCell(cell, false);
  std::vector<Cell *> omittedCells;
  omittedCells.push_back(cell);
  int count = 0;

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  if(!dual) {
    for(int j = 3; j > 0; j--)
      count += reduction(j, cell->getDim(), omittedCells);
  }
  else {
    count += coreduction(cell, cell->getDim(), omittedCells);
    for(int j = 1; j <= getDim(); j++)
      count += coreduction(j, cell->getDim(), omittedCells);
  }

  CombinedCell *newcell = new CombinedCell(omittedCells);
  _createCount++;

  std::string domainstr = "";
  int domain = getDomain(cell, domainstr);

  Msg::Debug("Cell complex %d-omit removed %dv, %df, %de, %dn (total %d)",
             cell->getDim(),
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0),
             count);
  Msg::Debug(" - number of %d-cells left in %s: %d", cell->getDim(),
             domainstr.c_str(), getNumCells(cell->getDim(), domain));

  return newcell;
}

int CellComplex::reduceComplex(int combine, bool omit, bool homseq)
{
  if(!getSize(0)) return 0;

  double t1 = Cpu();
  int count = 0;
  if(relative() && !homseq) removeSubdomain();
  std::vector<Cell *> empty;
  for(int i = 3; i > 0; i--) count = count + reduction(i, -1, empty);

  if(omit && !homseq) {
    std::vector<Cell *> newCells;

    while(getSize(getDim()) != 0) {
      auto cit = firstCell(getDim());
      Cell *cell = *cit;

      newCells.push_back(_omitCell(cell, false));
    }

    for(std::size_t i = 0; i < newCells.size(); i++) {
      insertCell(newCells.at(i));
    }
  }

  double t2 = Cpu();
  if(t2 - t1 > CellComplex::_patience) {
    Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices", getSize(3),
              getSize(2), getSize(1), getSize(0));
  }

  if(combine > 0) this->combine(3);

  if(combine > 2)
    for(int i = 3; i > 0; i--) reduction(i, -1, empty);
  else if(combine > 1)
    reduction(2, -1, empty);

  if(combine > 0) this->combine(2);

  if(combine > 2)
    for(int i = 3; i > 0; i--) reduction(i, -1, empty);
  else if(combine > 1)
    reduction(1, -1, empty);

  if(combine > 0) this->combine(1);

  if(combine > 2)
    for(int i = 3; i > 0; i--) reduction(i, -1, empty);
  else if(combine > 1)
    reduction(0, -1, empty);

  _reduced = true;
  return count;
}

void CellComplex::removeSubdomain()
{
  std::vector<Cell *> toRemove;
  for(int i = 0; i < 4; i++) {
    for(auto cit = firstCell(i); cit != lastCell(i); ++cit) {
      Cell *cell = *cit;
      if(cell->inSubdomain()) toRemove.push_back(cell);
    }
  }
  for(std::size_t i = 0; i < toRemove.size(); i++) removeCell(toRemove[i]);
  _reduced = true;
}

void CellComplex::removeCells(int dim)
{
  if(dim < 0 || dim > 3) return;
  std::vector<Cell *> toRemove;
  for(auto cit = firstCell(dim); cit != lastCell(dim); ++cit) {
    toRemove.push_back(*cit);
  }
  for(std::size_t i = 0; i < toRemove.size(); i++) removeCell(toRemove[i]);
  _reduced = true;
}

int CellComplex::coreduceComplex(int combine, bool omit, int heuristic)
{
  if(!getSize(0)) return 0;

  double t1 = Cpu();

  int count = 0;
  if(relative()) removeSubdomain();
  std::vector<Cell *> empty;
  for(int dim = 0; dim < 4; dim++) {
    auto cit = firstCell(dim);
    while(cit != lastCell(dim)) {
      Cell *cell = *cit;
      int count = +coreduction(cell, -1, empty);
      if(count != 0) break;
      cit++;
    }
  }

  for(int j = 1; j <= getDim(); j++) count += coreduction(j, -1, empty);

  if(omit) {
    std::vector<Cell *> newCells;
    while(getSize(0) != 0) {
      auto cit = firstCell(0);
      Cell *cell = *cit;

      if(heuristic == -1 && _smallestCell.second != 0. &&
         hasCell(_smallestCell.first)) {
        Msg::Debug("Omitted a cell in the smallest mesh element with volume %g",
                   _smallestCell.second);
        cell = _smallestCell.first;
      }
      else if(heuristic == 1 && _biggestCell.second != 0. &&
              hasCell(_biggestCell.first)) {
        Msg::Debug("Omitted a cell in the biggest mesh element with volume %g",
                   _biggestCell.second);
        cell = _biggestCell.first;
      }

      newCells.push_back(_omitCell(cell, true));
    }
    for(std::size_t i = 0; i < newCells.size(); i++) {
      insertCell(newCells.at(i));
    }
  }

  double t2 = Cpu();
  if(t2 - t1 > CellComplex::_patience) {
    Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices", getSize(3),
              getSize(2), getSize(1), getSize(0));
  }

  if(combine > 0) this->cocombine(0);

  if(combine > 2)
    for(int i = 1; i < 4; i++) coreduction(i, -1, empty);
  else if(combine > 1)
    coreduction(1, -1, empty);

  if(combine > 0) this->cocombine(1);

  if(combine > 2)
    for(int i = 1; i < 4; i++) coreduction(i, -1, empty);
  else if(combine > 1)
    coreduction(2, -1, empty);

  if(combine > 0) this->cocombine(2);

  if(combine > 2)
    for(int i = 1; i < 4; i++) coreduction(i, -1, empty);
  else if(combine > 1)
    coreduction(3, -1, empty);

  coherent();

  _reduced = true;
  return count;
}

void CellComplex::bettiReduceComplex()
{
  reduceComplex(3, true);
  for(int i = 1; i <= 3; i++) cocombine(i - 1);
  return;
}

int CellComplex::combine(int dim)
{
  if(dim < 1 || dim > 3) return 0;

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  double t1 = Cpu();

  std::queue<Cell *> Q;
  std::set<Cell *, CellPtrLessThan> Qset;
  std::map<Cell *, short int, CellPtrLessThan> bd_c;
  int count = 0;

  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    double t2 = Cpu();
    if(t2 - t1 > CellComplex::_patience) {
      t1 = Cpu();
      Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices",
                getSize(3), getSize(2), getSize(1), getSize(0));
    }

    Cell *cell = *cit;
    cell->getBoundary(bd_c);
    enqueueCells(bd_c, Q, Qset);

    while(Q.size() != 0) {
      Cell *s = Q.front();
      Q.pop();

      if(s->getCoboundarySize() == 2 && !s->getImmune()) {
        auto it = s->firstCoboundary();
        int or1 = it->second.get();
        Cell *c1 = it->first;
        it++;
        while(it->second.get() == 0) it++;
        int or2 = it->second.get();
        Cell *c2 = it->first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2) && inSameDomain(s, c1) &&
           inSameDomain(s, c2) && c1->getImmune() == c2->getImmune()) {
          removeCell(s, true, false);

          c1->getBoundary(bd_c);
          enqueueCells(bd_c, Q, Qset);
          c2->getBoundary(bd_c);
          enqueueCells(bd_c, Q, Qset);

          CombinedCell *newCell = new CombinedCell(c1, c2, (or1 != or2));
          _createCount++;
          removeCell(c1, true, c1->isCombined());
          removeCell(c2, true, c2->isCombined());
          insertCell(newCell);

          cit = firstCell(dim);
          count++;

          if(c1->isCombined()) {
            delete c1;
            _deleteCount++;
          }
          if(c2->isCombined()) {
            delete c2;
            _deleteCount++;
          }
        }
      }
      Qset.erase(s);
    }
  }

  Msg::Debug("Cell complex %d-combine removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  _reduced = true;
  return count;
}

int CellComplex::cocombine(int dim)
{
  if(dim < 0 || dim > 2) return 0;

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  double t1 = Cpu();

  std::queue<Cell *> Q;
  std::set<Cell *, CellPtrLessThan> Qset;
  std::map<Cell *, short int, CellPtrLessThan> cbd_c;
  int count = 0;

  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    double t2 = Cpu();
    if(t2 - t1 > CellComplex::_patience) {
      t1 = Cpu();
      Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices",
                getSize(3), getSize(2), getSize(1), getSize(0));
    }

    Cell *cell = *cit;

    cell->getCoboundary(cbd_c);
    enqueueCells(cbd_c, Q, Qset);

    while(Q.size() != 0) {
      Cell *s = Q.front();
      Q.pop();
      if(s->getBoundarySize() == 2) {
        auto it = s->firstBoundary();
        int or1 = it->second.get();
        Cell *c1 = it->first;
        it++;
        while(it->second.get() == 0) it++;
        int or2 = it->second.get();
        Cell *c2 = it->first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2) && inSameDomain(s, c1) &&
           inSameDomain(s, c2) && c1->getImmune() == c2->getImmune()) {
          removeCell(s, true, false);

          c1->getCoboundary(cbd_c);
          enqueueCells(cbd_c, Q, Qset);
          c2->getCoboundary(cbd_c);
          enqueueCells(cbd_c, Q, Qset);

          CombinedCell *newCell = new CombinedCell(c1, c2, (or1 != or2), true);
          _createCount++;
          removeCell(c1, true, c1->isCombined());
          removeCell(c2, true, c2->isCombined());
          insertCell(newCell);

          cit = firstCell(dim);
          count++;

          if(c1->isCombined()) {
            delete c1;
            _deleteCount++;
          }
          if(c2->isCombined()) {
            delete c2;
            _deleteCount++;
          }
        }
      }
      Qset.erase(s);
    }
  }

  Msg::Debug("Cell complex %d-cocombine removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  _reduced = true;
  return count;
}

bool CellComplex::coherent()
{
  bool coherent = true;
  for(int i = 0; i < 4; i++) {
    for(auto cit = firstCell(i); cit != lastCell(i); cit++) {
      Cell *cell = *cit;
      std::map<Cell *, short int, CellPtrLessThan> boundary;
      cell->getBoundary(boundary);
      for(auto it = boundary.begin(); it != boundary.end(); it++) {
        Cell *bdCell = (*it).first;
        int ori = (*it).second;
        auto cit = _cells[bdCell->getDim()].find(bdCell);
        if(cit == lastCell(bdCell->getDim())) {
          Msg::Debug("Boundary cell not in cell complex! Boundary removed");
          cell->removeBoundaryCell(bdCell, false);
          coherent = false;
        }
        if(!bdCell->hasCoboundary(cell)) {
          Msg::Debug("Incoherent boundary/coboundary pair! Fixed");
          bdCell->addCoboundaryCell(ori, cell, false);
          coherent = false;
        }
      }
      std::map<Cell *, short int, CellPtrLessThan> coboundary;
      cell->getCoboundary(coboundary);
      for(auto it = coboundary.begin(); it != coboundary.end(); it++) {
        Cell *cbdCell = (*it).first;
        int ori = (*it).second;
        auto cit = _cells[cbdCell->getDim()].find(cbdCell);
        if(cit == lastCell(cbdCell->getDim())) {
          Msg::Debug("Coboundary cell not in cell complex! Coboundary removed");
          cell->removeCoboundaryCell(cbdCell, false);
          coherent = false;
        }
        if(!cbdCell->hasBoundary(cell)) {
          Msg::Debug("Incoherent coboundary/boundary pair! Fixed");
          cbdCell->addBoundaryCell(ori, cell, false);
          coherent = false;
        }
      }
    }
  }
  return coherent;
}

bool CellComplex::hasCell(Cell *cell, bool orig)
{
  citer cit;
  if(!orig)
    cit = _cells[cell->getDim()].find(cell);
  else
    cit = _ocells[cell->getDim()].find(cell);
  if(cit == lastCell(cell->getDim(), orig))
    return false;
  else
    return true;
}

void CellComplex::getCells(std::set<Cell *, CellPtrLessThan> &cells, int dim,
                           int domain)
{
  cells.clear();
  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    Cell *cell = *cit;
    if((domain == 0 && !cell->inSubdomain()) || domain == 1 ||
       (domain == 2 && cell->inSubdomain())) {
      cells.insert(cell);
    }
  }
}

int CellComplex::getNumCells(int dim, int domain)
{
  if(domain == 0)
    return _numRelativeCells[dim];
  else if(domain == 1)
    return getSize(dim);
  else if(domain == 2)
    return _numSubdomainCells[dim];
  return 0;
}

Cell *CellComplex::getACell(int dim, int domain)
{
  int num = getNumCells(dim, domain);
  if(num < 0) Msg::Debug("Domain cell counts not in sync.");

  if(num <= 0) {
    if(domain == 0)
      Msg::Warning("%d cells in relative domain", num);
    else if(domain == 1)
      Msg::Warning("%d cells in domain", num);
    else if(domain == 2)
      Msg::Warning("%d cells in subdomain", num);
    return nullptr;
  }

  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    Cell *cell = *cit;
    if((domain == 1) || (domain == 0 && !cell->inSubdomain()) ||
       (domain == 2 && cell->inSubdomain()))
      return cell;
  }
  Msg::Debug("Domain cell counts not in sync.");
  return nullptr;
}

bool CellComplex::restoreComplex()
{
  if(_saveorig) {
    for(std::size_t i = 0; i < _removedcells.size(); i++) {
      Cell *cell = _removedcells.at(i);
      if(cell->isCombined()) {
        delete cell;
        _deleteCount++;
      }
    }
    _removedcells.clear();

    for(int i = 0; i < 4; i++) {
      for(auto cit = _cells[i].begin(); cit != _cells[i].end(); cit++) {
        Cell *cell = *cit;
        if(cell->isCombined()) {
          delete cell;
          _deleteCount++;
        }
      }

      _cells[i] = _ocells[i];
      for(auto cit = firstCell(i); cit != lastCell(i); cit++) {
        Cell *cell = *cit;
        cell->restoreCellBoundary();
        if(relative()) {
          if(cell->inSubdomain())
            _numSubdomainCells[i] += 1;
          else
            _numRelativeCells[i] += 1;
        }
      }
    }

    Msg::Info("Restored Cell Complex:");
    Msg::Info("%d volumes, %d faces, %d edges, and %d vertices", getSize(3),
              getSize(2), getSize(1), getSize(0));
    _reduced = false;
    return true;
  }
  else {
    Msg::Error("Cannot restore cell complex");
    return false;
  }
}

void CellComplex::printComplex(int dim)
{
  if(getSize(dim) == 0) Msg::Info("Cell complex dimension %d is empty", dim);
  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    Cell *cell = *cit;
    cell->printCell();
    cell->printBoundary();
    cell->printCoboundary();
    printf("--- \n");
  }
}

int CellComplex::saveComplex(const std::string &filename)
{
  /*FILE *fp = Fopen (filename.c_str(), "w");
  if(!fp){
    printf("\nUnable to open file '%s' \n", filename.c_str());
    return 0;
  }
  printf("\nWriting file '%s'...\n", filename.c_str());

  fprintf(fp, "$Cells\n");
  fprintf(fp, "%d\n", getSize(0)+getSize(1)+getSize(2)+getSize(3));
  for(int dim = 0; dim < 4; dim++){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      fprintf(fp, "%d %d %d %d %lu", cell->getNum(), cell->getType(),
          1, cell->getDomain(), cell->getNumVertices());
      for(std::size_t i = 0; i < cell->getNumVertices(); i++){
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

int CellComplex::loadComplex(const std::string &filename)
{
  /*  FILE *fp = Fopen (filename.c_str(), "r");
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
