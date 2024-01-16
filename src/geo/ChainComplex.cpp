// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#include "GmshConfig.h"
#if defined(HAVE_KBIPACK)

#include "ChainComplex.h"

ChainComplex::ChainComplex(CellComplex *cellComplex, int domain)
{
  _dim = cellComplex->getDim();
  _cellComplex = cellComplex;

  for(int i = 0; i < 5; i++) {
    _hMatrix[i] = nullptr;
    _kerH[i] = nullptr;
    _codH[i] = nullptr;
    _jMatrix[i] = nullptr;
    _qMatrix[i] = nullptr;
    _hbasis[i] = nullptr;
  }

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
      _hMatrix[dim] = nullptr;
    }
    else if(rows == 0) { // no dim-1-cells, maps everything to zero
      _hMatrix[dim] = create_gmp_matrix_zero(1, cols);
    }
    else {
      mpz_t elem;
      mpz_init(elem);
      _hMatrix[dim] = create_gmp_matrix_zero(rows, cols);
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
              int old_elem = 0;
              int bdCellIndex = getCellIndex(bdCell);
              int cellIndex = getCellIndex(cell);
              if(bdCellIndex > (int)gmp_matrix_rows(_hMatrix[dim]) ||
                 bdCellIndex < 1 ||
                 cellIndex > (int)gmp_matrix_cols(_hMatrix[dim]) ||
                 cellIndex < 1) {
                Msg::Debug("Index out of bound! HMatrix: %d", dim);
              }
              else {
                gmp_matrix_get_elem(elem, bdCellIndex, cellIndex,
                                    _hMatrix[dim]);
                old_elem = mpz_get_si(elem);
                mpz_set_si(elem, old_elem + it->second.get());
                if(abs((old_elem + it->second.get())) > 1) {
                  // printf("Incidence index: %d, in HMatrix: %d. \n", (old_elem
                  // + (*it).second), dim);
                }
                gmp_matrix_set_elem(elem, bdCellIndex, cellIndex,
                                    _hMatrix[dim]);
              }
            }
          }
        }
      }
      mpz_clear(elem);
    }
    _kerH[dim] = nullptr;
    _codH[dim] = nullptr;
    _jMatrix[dim] = nullptr;
    _qMatrix[dim] = nullptr;
    _hbasis[dim] = nullptr;
  }
}

ChainComplex::~ChainComplex()
{
  for(int i = 0; i < 5; i++) {
    destroy_gmp_matrix(_hMatrix[i]);
    destroy_gmp_matrix(_kerH[i]);
    destroy_gmp_matrix(_codH[i]);
    destroy_gmp_matrix(_jMatrix[i]);
    destroy_gmp_matrix(_qMatrix[i]);
    destroy_gmp_matrix(_hbasis[i]);
  }
}

void ChainComplex::transposeHMatrices()
{
  for(int i = 0; i < 5; i++)
    if(_hMatrix[i] != nullptr) gmp_matrix_transp(_hMatrix[i]);
}
void ChainComplex::transposeHMatrix(int dim)
{
  if(dim > -1 && dim < 5 && _hMatrix[dim] != nullptr)
    gmp_matrix_transp(_hMatrix[dim]);
}

void ChainComplex::KerCod(int dim)
{
  if(dim < 0 || dim > 3 || _hMatrix[dim] == nullptr) return;

  gmp_matrix *HMatrix =
    copy_gmp_matrix(_hMatrix[dim], 1, 1, gmp_matrix_rows(_hMatrix[dim]),
                    gmp_matrix_cols(_hMatrix[dim]));

  gmp_normal_form *normalForm =
    create_gmp_Hermite_normal_form(HMatrix, NOT_INVERTED, INVERTED);
  // printMatrix(normalForm->left);
  // printMatrix(normalForm->canonical);
  // printMatrix(normalForm->right);

  int minRowCol = std::min(gmp_matrix_rows(normalForm->canonical),
                           gmp_matrix_cols(normalForm->canonical));
  int rank = 0;
  mpz_t elem;
  mpz_init(elem);

  // find the rank
  while(rank < minRowCol) {
    gmp_matrix_get_elem(elem, rank + 1, rank + 1, normalForm->canonical);
    if(mpz_cmp_si(elem, 0) == 0) break;
    rank++;
  }

  if(rank != (int)gmp_matrix_cols(normalForm->canonical)) {
    _kerH[dim] = copy_gmp_matrix(normalForm->right, 1, rank + 1,
                                 gmp_matrix_rows(normalForm->right),
                                 gmp_matrix_cols(normalForm->right));
  }

  if(rank > 0) {
    _codH[dim] = copy_gmp_matrix(normalForm->canonical, 1, 1,
                                 gmp_matrix_rows(normalForm->canonical), rank);
    gmp_matrix_left_mult(normalForm->left, _codH[dim]);
  }

  mpz_clear(elem);
  destroy_gmp_normal_form(normalForm);

  return;
}

// j:B_k->Z_k
void ChainComplex::Inclusion(int lowDim, int highDim)
{
  if(getKerHMatrix(lowDim) == nullptr || getCodHMatrix(highDim) == nullptr ||
     abs(lowDim - highDim) != 1)
    return;

  gmp_matrix *Zbasis =
    copy_gmp_matrix(_kerH[lowDim], 1, 1, gmp_matrix_rows(_kerH[lowDim]),
                    gmp_matrix_cols(_kerH[lowDim]));
  gmp_matrix *Bbasis =
    copy_gmp_matrix(_codH[highDim], 1, 1, gmp_matrix_rows(_codH[highDim]),
                    gmp_matrix_cols(_codH[highDim]));

  int rows = gmp_matrix_rows(Bbasis);
  int cols = gmp_matrix_cols(Bbasis);
  if(rows < cols) {
    destroy_gmp_matrix(Zbasis);
    destroy_gmp_matrix(Bbasis);
    return;
  }

  rows = gmp_matrix_rows(Zbasis);
  cols = gmp_matrix_cols(Zbasis);
  if(rows < cols) {
    destroy_gmp_matrix(Zbasis);
    destroy_gmp_matrix(Bbasis);
    return;
  }

  // inv(U)*A*inv(V) = S
  gmp_normal_form *normalForm =
    create_gmp_Smith_normal_form(Zbasis, INVERTED, INVERTED);

  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= cols; i++) {
    gmp_matrix_get_elem(elem, i, i, normalForm->canonical);
    if(mpz_cmp_si(elem, 0) == 0) {
      destroy_gmp_matrix(Bbasis);
      destroy_gmp_normal_form(normalForm);
      return;
    }
  }

  gmp_matrix_left_mult(normalForm->left, Bbasis);

  gmp_matrix *LB = copy_gmp_matrix(Bbasis, 1, 1, gmp_matrix_cols(Zbasis),
                                   gmp_matrix_cols(Bbasis));
  destroy_gmp_matrix(Bbasis);

  rows = gmp_matrix_rows(LB);
  cols = gmp_matrix_cols(LB);

  mpz_t divisor;
  mpz_init(divisor);
  mpz_t remainder;
  mpz_init(remainder);
  mpz_t result;
  mpz_init(result);

  for(int i = 1; i <= rows; i++) {
    gmp_matrix_get_elem(divisor, i, i, normalForm->canonical);
    for(int j = 1; j <= cols; j++) {
      gmp_matrix_get_elem(elem, i, j, LB);
      mpz_cdiv_qr(result, remainder, elem, divisor);
      if(mpz_cmp_si(remainder, 0) == 0) {
        gmp_matrix_set_elem(result, i, j, LB);
      }
      else {
        destroy_gmp_matrix(Zbasis);
        destroy_gmp_matrix(LB);
        destroy_gmp_normal_form(normalForm);
        return;
      }
    }
  }

  gmp_matrix_left_mult(normalForm->right, LB);

  setJMatrix(lowDim, LB);

  mpz_clear(elem);
  mpz_clear(divisor);
  mpz_clear(result);
  destroy_gmp_normal_form(normalForm);
}

void ChainComplex::Quotient(int dim, int setDim)
{
  if(dim < 0 || dim > 4 || _jMatrix[dim] == nullptr) return;
  if(setDim < 0 || setDim > 4) return;

  gmp_matrix *JMatrix =
    copy_gmp_matrix(_jMatrix[dim], 1, 1, gmp_matrix_rows(_jMatrix[dim]),
                    gmp_matrix_cols(_jMatrix[dim]));
  int rows = gmp_matrix_rows(JMatrix);
  int cols = gmp_matrix_cols(JMatrix);

  gmp_normal_form *normalForm =
    create_gmp_Smith_normal_form(JMatrix, NOT_INVERTED, NOT_INVERTED);

  // printMatrix(normalForm->left);
  // printMatrix(normalForm->canonical);
  // printMatrix(normalForm->right);

  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= cols; i++) {
    gmp_matrix_get_elem(elem, i, i, normalForm->canonical);
    if(mpz_cmp_si(elem, 0) == 0) {
      destroy_gmp_normal_form(normalForm);
      return;
    }
    if(mpz_cmp_si(elem, 1) > 0) {
      _torsion[setDim].push_back(mpz_get_si(elem));
    }
  }

  int rank = cols - _torsion[setDim].size();
  if(rows - rank > 0) {
    gmp_matrix *Hbasis =
      copy_gmp_matrix(normalForm->left, 1, rank + 1, rows, rows);
    _qMatrix[dim] = Hbasis;
  }

  mpz_clear(elem);
  destroy_gmp_normal_form(normalForm);
  return;
}

void ChainComplex::computeHomology(bool dual)
{
  int lowDim = 0;
  int highDim = 0;
  int setDim = 0;

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
    if(lowDim == 0 && !dual && gmp_matrix_cols(getHMatrix(lowDim)) > 0 &&
       getHMatrix(highDim) == nullptr) {
      setHbasis(setDim, create_gmp_matrix_identity(
                          gmp_matrix_cols(getHMatrix(lowDim))));
    }
    else if(highDim == 0 && dual && gmp_matrix_rows(getHMatrix(highDim)) > 0 &&
            getHMatrix(lowDim) == nullptr) {
      setHbasis(setDim, create_gmp_matrix_identity(
                          gmp_matrix_rows(getHMatrix(highDim))));
    }

    // 2) this dimension is empty
    else if(getHMatrix(setDim) == nullptr) {
      setHbasis(setDim, nullptr);
    }
    // 3) No higher dimension cells -> none of the cycles are boundaries
    else if(getHMatrix(highDim) == nullptr) {
      setHbasis(setDim,
                copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
                                gmp_matrix_rows(getKerHMatrix(lowDim)),
                                gmp_matrix_cols(getKerHMatrix(lowDim))));
    }

    // 5) General case:
    //   1) Find the bases of boundaries B and cycles Z
    //   2) find j: B -> Z and
    //   3) find quotient Z/j(B)
    else {
      // 4) No lower dimension cells -> all chains are cycles
      if(getHMatrix(lowDim) == nullptr) {
        setKerHMatrix(lowDim, create_gmp_matrix_identity(
                                gmp_matrix_rows(getHMatrix(highDim))));
      }
      Inclusion(lowDim, highDim);
      Quotient(lowDim, setDim);

      if(getCodHMatrix(highDim) == nullptr) {
        setHbasis(setDim,
                  copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
                                  gmp_matrix_rows(getKerHMatrix(lowDim)),
                                  gmp_matrix_cols(getKerHMatrix(lowDim))));
      }
      else if(getJMatrix(lowDim) == nullptr || getQMatrix(lowDim) == nullptr) {
        setHbasis(setDim, nullptr);
      }
      else {
        setHbasis(setDim,
                  copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
                                  gmp_matrix_rows(getKerHMatrix(lowDim)),
                                  gmp_matrix_cols(getKerHMatrix(lowDim))));

        gmp_matrix_right_mult(getHbasis(setDim), getQMatrix(lowDim));
      }
    }

    destroy_gmp_matrix(getJMatrix(lowDim));
    destroy_gmp_matrix(getQMatrix(lowDim));

    setJMatrix(lowDim, nullptr);
    setQMatrix(lowDim, nullptr);
  }
  return;
}

void ChainComplex::matrixTest()
{
  const int rows = 3;
  const int cols = 6;

  long int elems[rows * cols];
  for(int i = 1; i <= rows * cols; i++) elems[i - 1] = i;

  gmp_matrix *matrix = create_gmp_matrix_int(rows, cols, elems);
  gmp_matrix *copymatrix = copy_gmp_matrix(matrix, 3, 2, 3, 5);
  printMatrix(matrix);
  printMatrix(copymatrix);
  destroy_gmp_matrix(matrix);
  destroy_gmp_matrix(copymatrix);
}

std::vector<int> ChainComplex::getCoeffVector(int dim, int chainNumber)
{
  std::vector<int> coeffVector;

  if(dim < 0 || dim > 4) return coeffVector;
  if(_hbasis[dim] == nullptr ||
     (int)gmp_matrix_cols(_hbasis[dim]) < chainNumber)
    return coeffVector;

  int rows = gmp_matrix_rows(_hbasis[dim]);

  int elemi;
  long int elemli;
  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= rows; i++) {
    gmp_matrix_get_elem(elem, i, chainNumber, _hbasis[dim]);
    elemli = mpz_get_si(elem);
    elemi = elemli;
    coeffVector.push_back(elemi);
    // printf("coeff: %d \n", coeffVector.at(i-1));
  }

  mpz_clear(elem);
  return coeffVector;
}

gmp_matrix *ChainComplex::getBasis(int dim, int basis)
{
  if(dim > -2 && dim < 4 && basis == 2) return _codH[dim + 1];
  if(dim < 0 || dim > 4)
    return nullptr;
  else if(basis == 1)
    return _kerH[dim];
  else if(basis == 3)
    return _hbasis[dim];
  else
    return nullptr;
}

void ChainComplex::getBasisChain(std::map<Cell *, int, CellPtrLessThan> &chain,
                                 int num, int dim, int basis, bool deform)
{
  if(basis < 0 || basis > 3) return;
  gmp_matrix *basisMatrix = getBasis(dim, basis);

  chain.clear();
  if(dim < 0 || dim > 3) return;
  if(basisMatrix == nullptr || (int)gmp_matrix_cols(basisMatrix) < num) {
    return;
  }

  int elemi;
  long int elemli;
  mpz_t elem;
  mpz_init(elem);

  int torsion = 1;
  if(basis == 3) torsion = getTorsion(dim, num);

  for(auto cit = this->firstCell(dim); cit != this->lastCell(dim); cit++) {
    Cell *cell = cit->first;
    int index = cit->second;
    gmp_matrix_get_elem(elem, index, num, basisMatrix);
    elemli = mpz_get_si(elem);
    elemi = elemli;
    if(elemli != 0) {
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
  mpz_clear(elem);

  if(deform && basis == 3 && (dim == 1 || dim == 2)) smoothenChain(chain);
}

int ChainComplex::getBasisSize(int dim, int basis)
{
  gmp_matrix *basisMatrix;
  if(basis == 0 && _hMatrix[dim] != nullptr) {
    return gmp_matrix_cols(_hMatrix[dim]);
  }
  else if(basis == 1)
    basisMatrix = getBasis(dim, 1);
  else if(basis == 2)
    basisMatrix = getBasis(dim, 2);
  else if(basis == 3)
    basisMatrix = getBasis(dim, 3);
  else
    return 0;

  if(basisMatrix != nullptr && gmp_matrix_rows(basisMatrix) != 0)
    return gmp_matrix_cols(basisMatrix);
  else
    return 0;
}

int ChainComplex::getTorsion(int dim, int num)
{
  if(dim < 0 || dim > 4) return 0;
  if(_hbasis[dim] == nullptr || (int)gmp_matrix_cols(_hbasis[dim]) < num)
    return 0;
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
      // printf("straighten \n");
      return deform(cells, cellsInChain, cellsNotInChain);
    }
    else if((dim == 1 && cellsInChain.size() == 1 &&
             cellsNotInChain.size() == 2 && bend) ||
            (dim == 2 && cellsInChain.size() == 2 &&
             cellsNotInChain.size() == 2 && bend)) {
      // printf("bend \n");
      return deform(cells, cellsInChain, cellsNotInChain);
    }
    else if((dim == 1 && cellsInChain.size() == 3 &&
             cellsNotInChain.size() == 0) ||
            (dim == 2 && cellsInChain.size() == 4 &&
             cellsNotInChain.size() == 0)) {
      // printf("remove boundary \n");
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

#endif
