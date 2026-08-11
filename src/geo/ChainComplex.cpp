// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#include <cstdlib>
#include <exception>
#include "ChainComplex.h"
#include "GmshMessage.h"

ChainComplex::ChainComplex(CellComplex *cellComplex, int domain)
{
  _dim = cellComplex->getDim();
  _cellComplex = cellComplex;

  int lastCols = 0;
  for(int dim = 0; dim < 4; dim++) {
    std::size_t cols = cellComplex->getSize(dim);
    std::size_t rows = 0;

    int index = 1;
    // ignore cells depending on domain
    for(auto cit = cellComplex->firstCell(dim);
        cit != cellComplex->lastCell(dim); cit++) {
      Cell *cell = *cit;
      cols--;
      if((domain == 0 && !cell->inSubdomain()) || domain == 1 ||
         (domain == 2 && cell->inSubdomain())) {
        cols++;
        _cellIndices[dim][cell] = index;
        index++;
      }
      else
        _cellIndices[dim][cell] = 0;
    }

    if(dim > 0) rows = lastCols;
    lastCols = cols;

    if(cols == 0) { // no dim-cells, no map
      // leave _hMatrix[dim] empty
    }
    else if(rows == 0) { // no dim-1-cells, maps everything to zero
      _hMatrix[dim] = IntegerMatrix(1, cols);
    }
    else {
      _hMatrix[dim] = IntegerMatrix(rows, cols);
      for(auto cit = cellComplex->firstCell(dim);
          cit != cellComplex->lastCell(dim); cit++) {
        Cell *cell = *cit;
        if((domain == 0 && !cell->inSubdomain()) || domain == 1 ||
           (domain == 2 && cell->inSubdomain())) {
          for(auto it = cell->firstBoundary(); it != cell->lastBoundary();
              it++) {
            Cell *bdCell = it->first;
            if(it->second.get() == 0) continue;
            if((domain == 0 && !bdCell->inSubdomain()) || domain == 1 ||
               (domain == 2 && cell->inSubdomain())) {
              int bdCellIndex = getCellIndex(bdCell);
              int cellIndex = getCellIndex(cell);
              if(bdCellIndex > (int)_hMatrix[dim].rows() || bdCellIndex < 1 ||
                 cellIndex > (int)_hMatrix[dim].cols() || cellIndex < 1) {
                Msg::Debug("Index out of bound! HMatrix: %d", dim);
              }
              else {
                _hMatrix[dim](bdCellIndex - 1, cellIndex - 1) +=
                  it->second.get();
              }
            }
          }
        }
      }
    }
  }
}

void ChainComplex::transposeHMatrices()
{
  for(int i = 0; i < 5; i++) _hMatrix[i].transposeInPlace();
}

void ChainComplex::transposeHMatrix(int dim)
{
  if(dim > -1 && dim < 5) _hMatrix[dim].transposeInPlace();
}

void ChainComplex::KerCod(int dim)
{
  if(dim < 0 || dim > 3 || _hMatrix[dim].empty()) return;

  HermiteForm normalForm = hermiteNormalForm(_hMatrix[dim]);

  std::size_t minRowCol =
    std::min(normalForm.canonical.rows(), normalForm.canonical.cols());
  std::size_t rank = 0;

  // find the rank
  while(rank < minRowCol && normalForm.canonical(rank, rank) != 0) rank++;

  if(rank != normalForm.canonical.cols()) {
    _kerH[dim] =
      normalForm.rightInverse.block(0, rank, normalForm.rightInverse.rows(),
                                    normalForm.rightInverse.cols() - rank);
  }
  // The right inverse is square in the number of columns and is not needed for
  // the cokernel below; release it before that allocates, so the two are never
  // resident together.
  normalForm.rightInverse = IntegerMatrix();

  if(rank > 0) {
    // block() followed by permuteRows() allocates the result twice, and it is
    // as large as the canonical form itself; do both in a single pass
    const std::size_t rows = normalForm.canonical.rows();
    IntegerMatrix cod(rows, rank);
    for(std::size_t j = 0; j < rank; j++)
      for(std::size_t i = 0; i < rows; i++)
        cod(normalForm.rowPermutation[i], j) = normalForm.canonical(i, j);
    _codH[dim] = std::move(cod);
  }
}

// j:B_k->Z_k
void ChainComplex::Inclusion(int lowDim, int highDim)
{
  if(getKerHMatrix(lowDim) == nullptr || getCodHMatrix(highDim) == nullptr ||
     abs(lowDim - highDim) != 1)
    return;

  IntegerMatrix &Zbasis = _kerH[lowDim];
  // referenced, not copied: the boundary basis is as large as the cycle basis,
  // and a copy of it would stay resident across the normal form below. It is
  // read but never written here, and remains available as basis 2.
  const IntegerMatrix &Bbasis = _codH[highDim];

  if(Bbasis.rows() < Bbasis.cols()) return;
  if(Zbasis.rows() < Zbasis.cols()) return;

  // inv(U)*A*inv(V) = S
  SmithForm normalForm = smithNormalForm(Zbasis, true);

  const std::size_t cols = Zbasis.cols();
  // Only the diagonal of the canonical form is used below, but it is stored
  // dense and is as large as the cycle basis; take the invariant factors and
  // release it before the two products below allocate.
  std::vector<std::int64_t> invariant(cols);
  for(std::size_t i = 0; i < cols; i++) {
    invariant[i] = normalForm.canonical(i, i);
    if(invariant[i] == 0) return;
  }
  normalForm.canonical = IntegerMatrix();

  IntegerMatrix LB;
  {
    IntegerMatrix left = normalForm.left * Bbasis;
    normalForm.left = IntegerMatrix(); // square in the number of cycles
    LB = left.block(0, 0, cols, left.cols());
  }

  for(std::size_t i = 0; i < LB.rows(); i++) {
    std::int64_t divisor = invariant[i];
    for(std::size_t j = 0; j < LB.cols(); j++) {
      std::int64_t elem = LB(i, j);
      if(elem % divisor != 0) return;
      LB(i, j) = elem / divisor;
    }
  }

  setJMatrix(lowDim, normalForm.right * LB);
}

void ChainComplex::Quotient(int dim, int setDim)
{
  if(dim < 0 || dim > 4 || _jMatrix[dim].empty()) return;
  if(setDim < 0 || setDim > 4) return;

  std::size_t rows = _jMatrix[dim].rows();
  std::size_t cols = _jMatrix[dim].cols();

  // The incidence matrix is square in the number of cycles and its only other
  // reader is the emptiness test computeHomology() makes before calling here,
  // so move it in rather than leaving a second copy resident.
  SmithForm normalForm = smithNormalForm(std::move(_jMatrix[dim]), false);

  for(std::size_t i = 0; i < cols; i++) {
    std::int64_t elem = normalForm.canonical(i, i);
    if(elem == 0) return;
    if(elem > 1) _torsion[setDim].push_back((long int)elem);
  }

  std::size_t rank = cols - _torsion[setDim].size();
  if(rows - rank > 0) {
    setQMatrix(dim, normalForm.left.block(0, rank, rows, rows - rank));
  }
}

void ChainComplex::computeHomology(bool dual)
{
  int lowDim = 0;
  int highDim = 0;
  int setDim = 0;

  try {
    if(dual) transposeHMatrices();

    for(int i = -1; i < 4; i++) {
      if(dual) {
        lowDim = getDim() + 1 - i;
        highDim = getDim() + 1 - (i + 1);
        setDim = highDim;
      }
      else {
        lowDim = i;
        highDim = i + 1;
        setDim = lowDim;
      }

      KerCod(highDim);

      // 1) no edges, but zero cells
      if(lowDim == 0 && !dual && getHMatrix(lowDim) != nullptr &&
         getHMatrix(lowDim)->cols() > 0 && getHMatrix(highDim) == nullptr) {
        setHbasis(setDim,
                  IntegerMatrix::identity(getHMatrix(lowDim)->cols()));
      }
      else if(highDim == 0 && dual && getHMatrix(highDim) != nullptr &&
              getHMatrix(highDim)->rows() > 0 &&
              getHMatrix(lowDim) == nullptr) {
        setHbasis(setDim,
                  IntegerMatrix::identity(getHMatrix(highDim)->rows()));
      }

      // 2) this dimension is empty
      else if(getHMatrix(setDim) == nullptr) {
        setHbasis(setDim, IntegerMatrix());
      }
      // 3) No higher dimension cells -> none of the cycles are boundaries
      else if(getHMatrix(highDim) == nullptr) {
        setHbasis(setDim, getKerHMatrix(lowDim) != nullptr ?
                            *getKerHMatrix(lowDim) :
                            IntegerMatrix());
      }

      // 5) General case:
      //   1) Find the bases of boundaries B and cycles Z
      //   2) find j: B -> Z and
      //   3) find quotient Z/j(B)
      else {
        // 4) No lower dimension cells -> all chains are cycles
        if(getHMatrix(lowDim) == nullptr) {
          setKerHMatrix(lowDim,
                        IntegerMatrix::identity(getHMatrix(highDim)->rows()));
        }
        Inclusion(lowDim, highDim);
        // Quotient() consumes the incidence matrix, so record whether there
        // was one before calling it; neither it nor Inclusion() alters the
        // cokernel, so testing that up front is equivalent too
        const bool haveJ = (getJMatrix(lowDim) != nullptr);
        Quotient(lowDim, setDim);

        if(getCodHMatrix(highDim) == nullptr) {
          setHbasis(setDim, getKerHMatrix(lowDim) != nullptr ?
                              *getKerHMatrix(lowDim) :
                              IntegerMatrix());
        }
        else if(!haveJ || getQMatrix(lowDim) == nullptr) {
          setHbasis(setDim, IntegerMatrix());
        }
        else {
          setHbasis(setDim, *getKerHMatrix(lowDim) * *getQMatrix(lowDim));
        }
      }

      setJMatrix(lowDim, IntegerMatrix());
      setQMatrix(lowDim, IntegerMatrix());
    }
  } catch(const std::exception &err) {
    // only thrown on 64-bit integer overflow, which cannot occur for the
    // (totally unimodular) matrices a cell complex gives rise to
    Msg::Error("Homology computation aborted: %s", err.what());
  }
}

IntegerMatrix *ChainComplex::getBasis(int dim, int basis)
{
  if(dim > -2 && dim < 4 && basis == 2) return getCodHMatrix(dim + 1);
  if(dim < 0 || dim > 4)
    return nullptr;
  else if(basis == 1)
    return getKerHMatrix(dim);
  else if(basis == 3)
    return getHbasis(dim);
  else
    return nullptr;
}

void ChainComplex::getBasisChain(std::map<Cell *, int, CellPtrLessThan> &chain,
                                 int num, int dim, int basis, bool deform)
{
  if(basis < 0 || basis > 3) return;
  IntegerMatrix *basisMatrix = getBasis(dim, basis);

  chain.clear();
  if(dim < 0 || dim > 3) return;
  if(basisMatrix == nullptr || (int)basisMatrix->cols() < num) {
    return;
  }

  int torsion = 1;
  if(basis == 3) torsion = getTorsion(dim, num);

  for(auto cit = this->firstCell(dim); cit != this->lastCell(dim); cit++) {
    Cell *cell = cit->first;
    int index = cit->second;
    if(index < 1) continue; // cell not in the domain of the chain space
    int elemi = (int)(*basisMatrix)(index - 1, num - 1);
    if(elemi != 0) {
      std::map<Cell *, int, CellPtrLessThan> subCells;
      cell->getCells(subCells);
      for(auto it = subCells.begin(); it != subCells.end(); it++) {
        Cell *subCell = it->first;
        int coeff = it->second * elemi * torsion;
        if(coeff == 0) continue;
        chain[subCell] = coeff;
      }
    }
  }

  if(deform && basis == 3 && (dim == 1 || dim == 2)) smoothenChain(chain);
}

int ChainComplex::getBasisSize(int dim, int basis)
{
  IntegerMatrix *basisMatrix = nullptr;
  if(basis == 0) {
    return getHMatrix(dim) != nullptr ? (int)getHMatrix(dim)->cols() : 0;
  }
  else if(basis > 0 && basis < 4)
    basisMatrix = getBasis(dim, basis);
  else
    return 0;

  if(basisMatrix != nullptr && basisMatrix->rows() != 0)
    return (int)basisMatrix->cols();
  else
    return 0;
}

int ChainComplex::getTorsion(int dim, int num)
{
  if(dim < 0 || dim > 4) return 0;
  if(_hbasis[dim].empty() || (int)_hbasis[dim].cols() < num) return 0;
  if(_torsion[dim].empty() || (int)_torsion[dim].size() < num)
    return 1;
  else
    return _torsion[dim].at(num - 1);
}

bool ChainComplex::deform(
  std::map<Cell *, int, CellPtrLessThan> &cells,
  std::map<Cell *, int, CellPtrLessThan> &cellsInChain,
  std::map<Cell *, int, CellPtrLessThan> &cellsNotInChain)
{
  std::vector<int> cc;
  std::vector<int> bc;

  for(auto cit = cellsInChain.begin(); cit != cellsInChain.end(); cit++) {
    Cell *c = (*cit).first;
    c->setImmune(false);
    if(!c->inSubdomain()) {
      int coeff = 0;
      auto it = cells.find(c);
      if(it != cells.end()) coeff = it->second;
      cc.push_back(coeff);
      bc.push_back((*cit).second);
    }
  }

  if(cc.empty() || (getDim() == 2 && cc.size() < 2)) return false;
  int inout = cc[0] * bc[0];
  for(std::size_t i = 0; i < cc.size(); i++) {
    if(cc[i] * bc[i] != inout) return false;
  }

  for(auto cit = cellsInChain.begin(); cit != cellsInChain.end(); cit++) {
    Cell *cell = cit->first;
    auto it = cells.find(cell);
    if(it != cells.end()) cells[cell] = 0;
  }

  int n = 1;
  for(auto cit = cellsNotInChain.begin(); cit != cellsNotInChain.end(); cit++) {
    Cell *cell = (*cit).first;
    if(n == 2)
      cell->setImmune(true);
    else
      cell->setImmune(false);
    int coeff = -1 * inout * (*cit).second;

    std::pair<citer, bool> insert = cells.insert(std::make_pair(cell, coeff));
    if(!insert.second && (*insert.first).second == 0) {
      (*insert.first).second = coeff;
    }
    else if(!insert.second && (*insert.first).second != 0) {
      Msg::Error("Invalid chain smoothening add!");
    }
    n++;
  }
  return true;
}

bool ChainComplex::deformChain(std::map<Cell *, int, CellPtrLessThan> &cells,
                               std::pair<Cell *, int> cell, bool bend)
{
  Cell *c1 = cell.first;
  int dim = c1->getDim();
  for(auto cit = c1->firstCoboundary(true); cit != c1->lastCoboundary();
      cit++) {
    std::map<Cell *, int, CellPtrLessThan> cellsInChain;
    std::map<Cell *, int, CellPtrLessThan> cellsNotInChain;
    Cell *c1CbdCell = cit->first;

    for(auto cit2 = c1CbdCell->firstBoundary(true);
        cit2 != c1CbdCell->lastBoundary(); cit2++) {
      Cell *c1CbdBdCell = cit2->first;
      int coeff = cit2->second.geto();
      if(coeff == 0) continue;
      if((cells.find(c1CbdBdCell) != cells.end() && cells[c1CbdBdCell] != 0) ||
         c1CbdBdCell->inSubdomain()) {
        cellsInChain.insert(std::make_pair(c1CbdBdCell, coeff));
      }
      else
        cellsNotInChain.insert(std::make_pair(c1CbdBdCell, coeff));
    }

    bool next = false;

    for(auto cit2 = cellsInChain.begin(); cit2 != cellsInChain.end(); cit2++) {
      Cell *c = (*cit2).first;
      int coeff = 0;
      auto it = cells.find(c);
      if(it != cells.end()) coeff = it->second;
      if(c->getImmune()) next = true;
      if(c->inSubdomain()) bend = false;
      if(coeff > 1 || coeff < -1) next = true;
    }

    for(auto cit2 = cellsNotInChain.begin(); cit2 != cellsNotInChain.end();
        cit2++) {
      Cell *c = (*cit2).first;
      if(c->inSubdomain()) next = true;
    }
    if(next) continue;

    if((dim == 1 && cellsInChain.size() == 2 && cellsNotInChain.size() == 1) ||
       (dim == 2 && cellsInChain.size() == 3 && cellsNotInChain.size() == 1)) {
      // straighten
      return deform(cells, cellsInChain, cellsNotInChain);
    }
    else if((dim == 1 && cellsInChain.size() == 1 &&
             cellsNotInChain.size() == 2 && bend) ||
            (dim == 2 && cellsInChain.size() == 2 &&
             cellsNotInChain.size() == 2 && bend)) {
      // bend
      return deform(cells, cellsInChain, cellsNotInChain);
    }
    else if((dim == 1 && cellsInChain.size() == 3 &&
             cellsNotInChain.size() == 0) ||
            (dim == 2 && cellsInChain.size() == 4 &&
             cellsNotInChain.size() == 0)) {
      // remove boundary
      return deform(cells, cellsInChain, cellsNotInChain);
    }
  }

  return false;
}

void ChainComplex::smoothenChain(std::map<Cell *, int, CellPtrLessThan> &cells)
{
  if(!_cellComplex->simplicial() || cells.size() < 2) return;
  int dim = cells.begin()->first->getDim();
  int start = cells.size();

  int useless = 0;
  for(int i = 0; i < 20; i++) {
    int size = cells.size();
    for(auto cit = cells.begin(); cit != cells.end(); cit++) {
      if(dim == 2) deformChain(cells, *cit, true);
      deformChain(cells, *cit, false);
    }

    deImmuneCells(cells);
    eraseNullCells(cells);

    if(size >= (int)cells.size())
      useless++;
    else
      useless = 0;
    if(useless > 5) break;
  }

  deImmuneCells(cells);
  for(auto cit = cells.begin(); cit != cells.end(); cit++) {
    deformChain(cells, *cit, false);
  }
  eraseNullCells(cells);
  int size = cells.size();
  Msg::Debug("Simplified a %d-chain from %d cells to %d cells", dim, start,
             size);
}

void ChainComplex::eraseNullCells(std::map<Cell *, int, CellPtrLessThan> &cells)
{
  std::vector<Cell *> toRemove;
  for(auto cit = cells.begin(); cit != cells.end(); cit++) {
    if(cit->second == 0) toRemove.push_back(cit->first);
  }
  for(std::size_t i = 0; i < toRemove.size(); i++) cells.erase(toRemove[i]);
}

void ChainComplex::deImmuneCells(std::map<Cell *, int, CellPtrLessThan> &cells)
{
  for(auto cit = cells.begin(); cit != cells.end(); cit++) {
    Cell *cell = (*cit).first;
    cell->setImmune(false);
  }
}
