// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "GmshConfig.h"
#if defined(HAVE_KBIPACK)

#include "ChainComplex.h"

ChainComplex::ChainComplex(CellComplex* cellComplex, int domain)
{
  _dim = cellComplex->getDim();
  _cellComplex = cellComplex;

  for(int i = 0; i < 5; i++){
    _HMatrix[i] = NULL;
    _kerH[i] = NULL;
    _codH[i] = NULL;
    _JMatrix[i] = NULL;
    _QMatrix[i] = NULL;
    _Hbasis[i] = NULL;
  }

  int lastCols = 0;
  for(int dim = 0; dim < 4; dim++){
    unsigned int cols = cellComplex->getSize(dim);
    unsigned int rows = 0;

    int index = 1;
    // ignore cells depending on domain
    for(CellComplex::citer cit = cellComplex->firstCell(dim);
	cit != cellComplex->lastCell(dim); cit++){
      Cell* cell = *cit;
      cols--;
      if((domain == 0 && !cell->inSubdomain()) || domain == 1
	 || (domain == 2 && cell->inSubdomain()) ){
        cols++;
        _cellIndices[dim][cell] = index;
        index++;
      }
      else _cellIndices[dim][cell] = 0;
    }

    if(dim > 0) rows = lastCols;
    lastCols = cols;

    if(cols == 0){ // no dim-cells, no map
      //_HMatrix[dim] = create_gmp_matrix_zero(rows, 1);
      _HMatrix[dim] = NULL;
    }
    else if(rows == 0){ // no dim-1-cells, maps everything to zero
      _HMatrix[dim] = create_gmp_matrix_zero(1, cols);
      //_HMatrix[dim] = NULL;
    }
    else{
      mpz_t elem;
      mpz_init(elem);
      _HMatrix[dim] = create_gmp_matrix_zero(rows, cols);
      for( std::set<Cell*, Less_Cell>::iterator cit =
	     cellComplex->firstCell(dim);
	   cit != cellComplex->lastCell(dim); cit++){
        Cell* cell = *cit;
        if( (domain == 0 && !cell->inSubdomain()) || domain == 1
	    || (domain == 2 && cell->inSubdomain()) ){
          for(Cell::biter it = cell->firstBoundary();
	      it != cell->lastBoundary(); it++){
            Cell* bdCell = it->first;
	    if(it->second.get() == 0) continue;
            if((domain == 0 && !bdCell->inSubdomain()) || domain == 1
	       || (domain == 2 && cell->inSubdomain()) ){
              int old_elem = 0;
              int bdCellIndex = getCellIndex(bdCell);
              int cellIndex = getCellIndex(cell);
              if(bdCellIndex > (int)gmp_matrix_rows( _HMatrix[dim])
		 || bdCellIndex < 1
                 || cellIndex > (int)gmp_matrix_cols( _HMatrix[dim])
		 || cellIndex < 1){
                Msg::Debug("Index out of bound! HMatrix: %d", dim);
              }
              else{
                gmp_matrix_get_elem(elem, bdCellIndex,
				    cellIndex, _HMatrix[dim]);
                old_elem = mpz_get_si(elem);
                mpz_set_si(elem, old_elem + it->second.get());
                if( abs((old_elem + it->second.get())) > 1){
		  //printf("Incidence index: %d, in HMatrix: %d. \n", (old_elem + (*it).second), dim);
                }
                gmp_matrix_set_elem(elem, bdCellIndex,
                                    cellIndex, _HMatrix[dim]);
              }
            }
          }
        }
      }
      mpz_clear(elem);
    }
    _kerH[dim] = NULL;
    _codH[dim] = NULL;
    _JMatrix[dim] = NULL;
    _QMatrix[dim] = NULL;
    _Hbasis[dim] = NULL;
  }
}

ChainComplex::~ChainComplex()
{
  for(int i = 0; i < 5; i++){
    destroy_gmp_matrix(_HMatrix[i]);
    destroy_gmp_matrix(_kerH[i]);
    destroy_gmp_matrix(_codH[i]);
    destroy_gmp_matrix(_JMatrix[i]);
    destroy_gmp_matrix(_QMatrix[i]);
    destroy_gmp_matrix(_Hbasis[i]);
  }
}

void ChainComplex::transposeHMatrices()
{
  for(int i = 0; i < 5; i++)
    if(_HMatrix[i] != NULL) gmp_matrix_transp(_HMatrix[i]);
}
void ChainComplex::transposeHMatrix(int dim)
{
  if(dim > -1 && dim < 5 && _HMatrix[dim] != NULL)
    gmp_matrix_transp(_HMatrix[dim]);
}

void ChainComplex::KerCod(int dim)
{
  if(dim < 0 || dim > 3 || _HMatrix[dim] == NULL) return;

  gmp_matrix* HMatrix
    = copy_gmp_matrix(_HMatrix[dim], 1, 1,
		      gmp_matrix_rows(_HMatrix[dim]),
		      gmp_matrix_cols(_HMatrix[dim]));

  gmp_normal_form* normalForm
    = create_gmp_Hermite_normal_form(HMatrix, NOT_INVERTED, INVERTED);
  //printMatrix(normalForm->left);
  //printMatrix(normalForm->canonical);
  //printMatrix(normalForm->right);

  int minRowCol = std::min(gmp_matrix_rows(normalForm->canonical),
			   gmp_matrix_cols(normalForm->canonical));
  int rank = 0;
  mpz_t elem;
  mpz_init(elem);

  // find the rank
  while(rank < minRowCol){
    gmp_matrix_get_elem(elem, rank+1, rank+1, normalForm->canonical);
    if(mpz_cmp_si(elem,0) == 0) break;
    rank++;
  }

  if(rank != (int)gmp_matrix_cols(normalForm->canonical)){
    _kerH[dim]
      = copy_gmp_matrix(normalForm->right, 1, rank+1,
			gmp_matrix_rows(normalForm->right),
			gmp_matrix_cols(normalForm->right));
  }

  if(rank > 0){
     _codH[dim] =
       copy_gmp_matrix(normalForm->canonical, 1, 1,
		       gmp_matrix_rows(normalForm->canonical), rank);
     gmp_matrix_left_mult(normalForm->left, _codH[dim]);
  }

  mpz_clear(elem);
  destroy_gmp_normal_form(normalForm);

  return;
}

//j:B_k->Z_k
void ChainComplex::Inclusion(int lowDim, int highDim)
{
  if(getKerHMatrix(lowDim) == NULL
     || getCodHMatrix(highDim) == NULL
     || abs(lowDim-highDim) != 1) return;

  gmp_matrix* Zbasis =
    copy_gmp_matrix(_kerH[lowDim], 1, 1,
		    gmp_matrix_rows(_kerH[lowDim]),
		    gmp_matrix_cols(_kerH[lowDim]));
  gmp_matrix* Bbasis
    = copy_gmp_matrix(_codH[highDim], 1, 1,
		      gmp_matrix_rows(_codH[highDim]),
		      gmp_matrix_cols(_codH[highDim]));


  int rows = gmp_matrix_rows(Bbasis);
  int cols = gmp_matrix_cols(Bbasis);
  if(rows < cols) return;

  rows = gmp_matrix_rows(Zbasis);
  cols = gmp_matrix_cols(Zbasis);
  if(rows < cols) return;

  // inv(U)*A*inv(V) = S
  gmp_normal_form* normalForm
    = create_gmp_Smith_normal_form(Zbasis, INVERTED, INVERTED);

  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= cols; i++){

    gmp_matrix_get_elem(elem, i, i, normalForm->canonical);
    if(mpz_cmp_si(elem,0) == 0){
      destroy_gmp_normal_form(normalForm);
      return;
    }
  }

  gmp_matrix_left_mult(normalForm->left, Bbasis);

  gmp_matrix* LB = copy_gmp_matrix(Bbasis, 1, 1,
				   gmp_matrix_cols(Zbasis),
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

  for(int i = 1; i <= rows; i++){
    gmp_matrix_get_elem(divisor, i, i, normalForm->canonical);
    for(int j = 1; j <= cols; j++){
      gmp_matrix_get_elem(elem, i, j, LB);
      mpz_cdiv_qr(result, remainder, elem, divisor);
      if(mpz_cmp_si(remainder, 0) == 0){
        gmp_matrix_set_elem(result, i, j, LB);
      }
      else return;
    }
  }

  gmp_matrix_left_mult(normalForm->right, LB);

  setJMatrix(lowDim, LB);

  mpz_clear(elem);
  mpz_clear(divisor);
  mpz_clear(result);
  destroy_gmp_normal_form(normalForm);
}

void ChainComplex::Quotient(int dim)
{
  if(dim < 0 || dim > 4 || _JMatrix[dim] == NULL) return;

  gmp_matrix* JMatrix =
    copy_gmp_matrix(_JMatrix[dim], 1, 1,
		    gmp_matrix_rows(_JMatrix[dim]),
		    gmp_matrix_cols(_JMatrix[dim]));
  int rows = gmp_matrix_rows(JMatrix);
  int cols = gmp_matrix_cols(JMatrix);

  gmp_normal_form* normalForm =
    create_gmp_Smith_normal_form(JMatrix, NOT_INVERTED, NOT_INVERTED);

  //printMatrix(normalForm->left);
  //printMatrix(normalForm->canonical);
  //printMatrix(normalForm->right);

  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= cols; i++){
    gmp_matrix_get_elem(elem, i, i, normalForm->canonical);
    if(mpz_cmp_si(elem,0) == 0){
      destroy_gmp_normal_form(normalForm);
      return;
    }
    if(mpz_cmp_si(elem,1) > 0) _torsion[dim].push_back(mpz_get_si(elem));
  }

  int rank = cols - _torsion[dim].size();
  if(rows - rank > 0){
    gmp_matrix* Hbasis =
      copy_gmp_matrix(normalForm->left, 1, rank+1, rows, rows);
    _QMatrix[dim] = Hbasis;
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

  for(int i=-1; i < 4; i++){

    if(dual){
      lowDim = getDim()+1-i;
      highDim = getDim()+1-(i+1);
      setDim = highDim;
      //KerCod(lowDim);
    }
    else{
      lowDim = i;
      highDim = i+1;
      setDim = lowDim;
      //KerCod(highDim);
    }


    KerCod(highDim);

    // 1) no edges, but zero cells
    if(lowDim == 0 && !dual
       &&  gmp_matrix_cols(getHMatrix(lowDim)) > 0
       && getHMatrix(highDim) == NULL) {
      setHbasis( setDim,
		 create_gmp_matrix_identity(gmp_matrix_cols(getHMatrix(lowDim))) );
    }
    else if(highDim == 0 && dual
	    &&  gmp_matrix_rows(getHMatrix(highDim)) > 0
	    && getHMatrix(lowDim) == NULL) {
      setHbasis( setDim,
		 create_gmp_matrix_identity(gmp_matrix_rows(getHMatrix(highDim))) );
    }

    // 2) this dimension is empty
    else if(getHMatrix(lowDim) == NULL && getHMatrix(highDim) == NULL){
      setHbasis(setDim, NULL);
    }
    // 3) No higher dimension cells -> none of the cycles are boundaries
    else if(getHMatrix(highDim) == NULL){
      setHbasis( setDim,
		 copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
				 gmp_matrix_rows(getKerHMatrix(lowDim)),
				 gmp_matrix_cols(getKerHMatrix(lowDim))) );
    }


    // 5) General case:
    //   1) Find the bases of boundaries B and cycles Z
    //   2) find j: B -> Z and
    //   3) find quotient Z/j(B)
    else {

      // 4) No lower dimension cells -> all chains are cycles
      if(getHMatrix(lowDim) == NULL){
        setKerHMatrix(lowDim,
		      create_gmp_matrix_identity(gmp_matrix_rows(getHMatrix(highDim))) );
      }
      Inclusion(lowDim, highDim);
      Quotient(lowDim);

      if(getCodHMatrix(highDim) == NULL){
        setHbasis(setDim,
		  copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
				  gmp_matrix_rows(getKerHMatrix(lowDim)),
				  gmp_matrix_cols(getKerHMatrix(lowDim))) );
      }
      else if(getJMatrix(lowDim) == NULL || getQMatrix(lowDim) == NULL){
        setHbasis(setDim, NULL);
      }
      else{
        setHbasis(setDim,
		  copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
				  gmp_matrix_rows(getKerHMatrix(lowDim)),
				  gmp_matrix_cols(getKerHMatrix(lowDim))) );

        gmp_matrix_right_mult(getHbasis(setDim), getQMatrix(lowDim));
      }
    }

    //destroy_gmp_matrix(getKerHMatrix(lowDim));
    //destroy_gmp_matrix(getCodHMatrix(lowDim));
    destroy_gmp_matrix(getJMatrix(lowDim));
    destroy_gmp_matrix(getQMatrix(lowDim));

    //setKerHMatrix(lowDim, NULL);
    //setCodHMatrix(lowDim, NULL);
    setJMatrix(lowDim, NULL);
    setQMatrix(lowDim, NULL);
  }
  return;
}


void ChainComplex::matrixTest()
{
  const int rows = 3;
  const int cols = 6;

  long int elems[rows*cols];
  for(int i = 1; i<=rows*cols; i++) elems[i-1] = i;

  gmp_matrix* matrix = create_gmp_matrix_int(rows, cols, elems);

  gmp_matrix* copymatrix = copy_gmp_matrix(matrix, 3, 2, 3, 5);

  printMatrix(matrix);
  printMatrix(copymatrix);
}

std::vector<int> ChainComplex::getCoeffVector(int dim, int chainNumber)
{
  std::vector<int> coeffVector;

  if(dim < 0 || dim > 4) return coeffVector;
  if(_Hbasis[dim] == NULL
     || (int)gmp_matrix_cols(_Hbasis[dim]) < chainNumber) return coeffVector;

  int rows = gmp_matrix_rows(_Hbasis[dim]);

  int elemi;
  long int elemli;
  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= rows; i++){
    gmp_matrix_get_elem(elem, i, chainNumber, _Hbasis[dim]);
    elemli = mpz_get_si(elem);
    elemi = elemli;
    coeffVector.push_back(elemi);
    //printf("coeff: %d \n", coeffVector.at(i-1));
  }

  mpz_clear(elem);
  return coeffVector;
}

gmp_matrix* ChainComplex::getBasis(int dim, int basis)
{
  if(dim > -2 && dim < 5 && basis == 2) return _codH[dim+1];
  if(dim < 0 || dim > 4) return NULL;
  if(basis == 0) return create_gmp_matrix_identity(getBasisSize(dim, 0));
  else if(basis == 1) return _kerH[dim];
  else if(basis == 3) return _Hbasis[dim];
  else return NULL;
}

void ChainComplex::getBasisChain(std::map<Cell*, int, Less_Cell>& chain,
				 int num, int dim, int basis, bool deform)
{
  if(basis < 0 || basis > 3) return;
  gmp_matrix* basisMatrix = getBasis(dim, basis);

  chain.clear();
  if(dim < 0 || dim > 4) return;
  if(basisMatrix == NULL
     || (int)gmp_matrix_cols(basisMatrix) < num) return;

  //int rows = gmp_matrix_rows(basisMatrix);

  int elemi;
  long int elemli;
  mpz_t elem;
  mpz_init(elem);

  int torsion = 1;
  if(basis == 3) torsion = getTorsion(dim, num);

  for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
    Cell* cell = cit->first;
    int index = cit->second;
    gmp_matrix_get_elem(elem, index, num, basisMatrix);
    elemli = mpz_get_si(elem);
    elemi = elemli;
    if(elemli != 0){
      std::map<Cell*, int, Less_Cell > subCells;
      cell->getCells(subCells);
      for(Cell::citer it = subCells.begin(); it != subCells.end(); it++){
	Cell* subCell = it->first;
	int coeff = it->second*elemi*torsion;
        if(coeff == 0) continue;
	chain[subCell] = coeff;
      }
    }
  }
  mpz_clear(elem);

  if(deform && (dim == 1 || dim == 2) ) smoothenChain(chain);
}

int ChainComplex::getBasisSize(int dim, int basis)
{
    gmp_matrix* basisMatrix;
    if(basis == 0 && _HMatrix[dim] != NULL){
      return gmp_matrix_cols(_HMatrix[dim]);
    }
    else if(basis == 1) basisMatrix = getBasis(dim, 1);
    else if(basis == 2) basisMatrix = getBasis(dim, 2);
    else if(basis == 3) basisMatrix = getBasis(dim, 3);
    else return 0;

    if(basisMatrix != NULL) return gmp_matrix_cols(basisMatrix);
    else return 0;
}


int ChainComplex::getTorsion(int dim, int num)
{
  if(dim < 0 || dim > 4) return 0;
  if(_Hbasis[dim] == NULL
     || (int)gmp_matrix_cols(_Hbasis[dim]) < num) return 0;
  if(_torsion[dim].empty()
     || (int)_torsion[dim].size() < num) return 1;
  else return _torsion[dim].at(num-1);
}

bool ChainComplex::deform(std::map<Cell*, int, Less_Cell>& cells,
			  std::map<Cell*, int, Less_Cell>& cellsInChain,
			  std::map<Cell*, int, Less_Cell>& cellsNotInChain)
{
  std::vector<int> cc;
  std::vector<int> bc;

  for(citer cit = cellsInChain.begin(); cit != cellsInChain.end(); cit++){
    Cell* c = (*cit).first;
    c->setImmune(false);
    if(!c->inSubdomain()) {
      int coeff = 0;
      citer it = cells.find(c);
      if(it != cells.end()) coeff = it->second;
      cc.push_back(coeff);
      bc.push_back((*cit).second);
    }
  }

  if(cc.empty() || (getDim() == 2 && cc.size() < 2) ) return false;
  int inout = cc[0]*bc[0];
  for(unsigned int i = 0; i < cc.size(); i++){
    if(cc[i]*bc[i] != inout) return false;
  }

  for(citer cit = cellsInChain.begin(); cit != cellsInChain.end(); cit++){
    Cell* cell = cit->first;
    citer it = cells.find(cell);
    if(it != cells.end()) cells[cell] = 0;
  }

  int n = 1;
  for(citer cit = cellsNotInChain.begin(); cit != cellsNotInChain.end();
      cit++){
    Cell* cell = (*cit).first;
    if(n == 2) cell->setImmune(true);
    else cell->setImmune(false);
    int coeff = -1*inout*(*cit).second;

    std::pair<citer,bool> insert = cells.insert( std::make_pair( cell, coeff));
    if(!insert.second && (*insert.first).second == 0){
      (*insert.first).second = coeff;
    }
    else if (!insert.second && (*insert.first).second != 0){
      Msg::Error("Invalid chain smoothening add!");
    }
    n++;
  }
  return true;
}

bool ChainComplex::deformChain(std::map<Cell*, int, Less_Cell>& cells,
			       std::pair<Cell*, int> cell, bool bend)
{
  Cell* c1 = cell.first;
  int dim = c1->getDim();
  for(Cell::biter cit = c1->firstCoboundary(true); cit != c1->lastCoboundary();
      cit++){

    std::map<Cell*, int, Less_Cell> cellsInChain;
    std::map<Cell*, int, Less_Cell> cellsNotInChain;
    Cell* c1CbdCell = cit->first;

    for(Cell::biter cit2 = c1CbdCell->firstBoundary(true);
	cit2 != c1CbdCell->lastBoundary(); cit2++){
      Cell* c1CbdBdCell = cit2->first;
      int coeff = cit2->second.geto();
      if(coeff == 0) continue;
      if( (cells.find(c1CbdBdCell) != cells.end() && cells[c1CbdBdCell] != 0)
	  || c1CbdBdCell->inSubdomain()){
	cellsInChain.insert(std::make_pair(c1CbdBdCell, coeff));
      }
      else cellsNotInChain.insert(std::make_pair(c1CbdBdCell, coeff));
    }

    bool next = false;

    for(citer cit2 = cellsInChain.begin(); cit2 != cellsInChain.end(); cit2++){
      Cell* c = (*cit2).first;
      int coeff = 0;
      citer it = cells.find(c);
      if(it != cells.end()) coeff = it->second;
      if(c->getImmune()) next = true;
      if(c->inSubdomain()) bend = false;
      if(coeff > 1 || coeff < -1) next = true;
    }

    for(citer cit2 = cellsNotInChain.begin(); cit2 != cellsNotInChain.end();
	cit2++){
      Cell* c = (*cit2).first;
      if(c->inSubdomain()) next = true;
    }
    if(next) continue;

    if( (dim == 1 && cellsInChain.size() == 2
	 && cellsNotInChain.size() == 1) ||
	(dim == 2 && cellsInChain.size() == 3
	 && cellsNotInChain.size() == 1)){
      //printf("straighten \n");
      return deform(cells, cellsInChain, cellsNotInChain);
    }
    else if ( (dim == 1 && cellsInChain.size() == 1
	       && cellsNotInChain.size() == 2 && bend) ||
              (dim == 2 && cellsInChain.size() == 2
	       && cellsNotInChain.size() == 2 && bend)){
      //printf("bend \n");
      return deform(cells, cellsInChain, cellsNotInChain);
    }
    else if ((dim == 1 && cellsInChain.size() == 3
	      && cellsNotInChain.size() == 0) ||
             (dim == 2 && cellsInChain.size() == 4
	      && cellsNotInChain.size() == 0)){
      //printf("remove boundary \n");
      return deform(cells, cellsInChain, cellsNotInChain);
    }
  }

  return false;
}

void ChainComplex::smoothenChain(std::map<Cell*, int, Less_Cell>& cells)
{
  if(!_cellComplex->simplicial() || cells.empty()) return;
  int dim = cells.begin()->first->getDim();
  int start = cells.size();

  int useless = 0;
  for(int i = 0; i < 20; i++){
    int size = cells.size();
    for(citer cit = cells.begin(); cit != cells.end(); cit++){
      //if(!deformChain(*cit, false) && getDim() == 2) deformChain(*cit, true);
      if(dim == 2) deformChain(cells, *cit, true);
      deformChain(cells, *cit, false);

    }

    deImmuneCells(cells);
    eraseNullCells(cells);

    if (size >= (int)cells.size()) useless++;
    else useless = 0;
    if (useless > 5) break;
  }

  deImmuneCells(cells);
  for(citer cit = cells.begin(); cit != cells.end(); cit++){
    deformChain(cells, *cit, false);
  }
  eraseNullCells(cells);
  int size = cells.size();
  Msg::Info("Smoothened a %d-chain from %d cells to %d cells",
            dim, start, size);
}

void ChainComplex::eraseNullCells(std::map<Cell*, int, Less_Cell>& cells)
{
  std::vector<Cell*> toRemove;
  for(citer cit = cells.begin(); cit != cells.end(); cit++){
    if(cit->second == 0) toRemove.push_back(cit->first);
  }
  for(unsigned int i = 0; i < toRemove.size(); i++) cells.erase(toRemove[i]);
}

void ChainComplex::deImmuneCells(std::map<Cell*, int, Less_Cell>& cells)
{
  for(citer cit = cells.begin(); cit != cells.end(); cit++){
    Cell* cell = (*cit).first;
    cell->setImmune(false);
  }
}

HomologySequence::HomologySequence(ChainComplex* subcomplex,
				   ChainComplex* complex,
				   ChainComplex* relcomplex)
{
  _subcomplex = subcomplex;
  _complex = complex;
  _relcomplex = relcomplex;

  mpz_t elem;
  mpz_init_set_si(elem, -1);
  for(int i = 0; i < 4; i++){
    _Ic_sub[i] = NULL;
    _Ic_rel[i] = NULL;

    _Dh[i] = NULL;
    _invDh[i] = NULL;

    _Jh[i] = NULL;
    _Ih[i] = NULL;
    _invJh[i] = NULL;
    _invIh[i] = NULL;

  }

  findIcMaps();

  /*findDhMap(1);
  findInvIhMap(0);
  blockHBasis(_Dh[1], _invIh[0], _subcomplex, 0);*/

  /*findJhMap(1);
  findInvDhMap(1);
  blockHBasis(_Jh[1], _invDh[1], _relcomplex, 1);*/

}

HomologySequence::~HomologySequence()
{
  for(int i = 0; i < 4; i++){
    destroy_gmp_matrix(_Ic_sub[i]);
    destroy_gmp_matrix(_Ic_rel[i]);
    destroy_gmp_matrix(_Ih[i]);
    destroy_gmp_matrix(_Jh[i]);
    destroy_gmp_matrix(_invIh[i]);
    destroy_gmp_matrix(_invJh[i]);
    destroy_gmp_matrix(_Dh[i]);
    destroy_gmp_matrix(_invDh[i]);
  }
}

void HomologySequence::findIcMaps()
{
  for(int i = 0; i < 4; i++){
    mpz_t one;
    mpz_init_set_si(one, 1);
    if(_complex->getBasisSize(i, 0) > 0
       && _subcomplex->getBasisSize(i, 0) > 0){
      _Ic_sub[i] = create_gmp_matrix_zero(_complex->getBasisSize(i, 0),
					  _subcomplex->getBasisSize(i, 0));
      //printf("rows %d, cols %d. \n", _complex->getBasisSize(i, 0),
      //	     _subcomplex->getBasisSize(i, 0));
      for(ChainComplex::citer cit = _complex->firstCell(i);
	  cit != _complex->lastCell(i); cit++){
	Cell* cell = cit->first;
	int row = cit->second;
	int col = _subcomplex->getCellIndex(cell);
	//printf("row %d, col %d. \n", row, col);
	if(col != 0) gmp_matrix_set_elem(one, row, col, _Ic_sub[i]);
      }
    }

    if(_complex->getBasisSize(i, 0) > 0
       && _relcomplex->getBasisSize(i, 0) > 0){
      _Ic_rel[i] = create_gmp_matrix_zero(_complex->getBasisSize(i, 0),
					  _relcomplex->getBasisSize(i, 0));
      //printf("rows %d, cols %d. \n", _complex->getBasisSize(i, 0),
      for(ChainComplex::citer cit = _complex->firstCell(i);
	  cit != _complex->lastCell(i); cit++){
	Cell* cell = cit->first;
	int row = cit->second;
	int col = _relcomplex->getCellIndex(cell);
	//printf("row %d, col %d. \n", row, col);
	if(col != 0) gmp_matrix_set_elem(one, row, col, _Ic_rel[i]);
      }
    }
    mpz_clear(one);
  }
}

void HomologySequence::findIhMap(int i)
{
  if(_Ic_sub[i] != NULL
     && _complex->getBasisSize(i, 3) > 0
     && _subcomplex->getBasisSize(i, 3) > 0){
    gmp_matrix* IH = copy_gmp_matrix(_Ic_sub[i], 1, 1,
				     gmp_matrix_rows(_Ic_sub[i]),
				     gmp_matrix_cols(_Ic_sub[i]));
    gmp_matrix_right_mult(IH, _subcomplex->getBasis(i, 3));
    _Ih[i] = createIncMap(IH, _complex->getBasis(i, 3));
  }
}

void HomologySequence::findInvIhMap(int i)
{
  if(_Ic_sub[i] != NULL
     && _complex->getBasisSize(i, 3) > 0
     && _subcomplex->getBasisSize(i, 3) > 0){
    gmp_matrix* IH = copy_gmp_matrix(_Ic_sub[i], 1, 1,
				     gmp_matrix_rows(_Ic_sub[i]),
				     gmp_matrix_cols(_Ic_sub[i]));
    gmp_matrix_transp(IH);
    gmp_matrix_right_mult(IH, _complex->getBasis(i, 3));
    _invIh[i] = createIncMap(IH, _subcomplex->getBasis(i, 3));
  }
}

void HomologySequence::findJhMap(int i)
{
  if(_Ic_rel[i] != NULL
     && _complex->getBasisSize(i, 3) > 0
     && _relcomplex->getBasisSize(i, 3) > 0){
    gmp_matrix* JH = copy_gmp_matrix(_Ic_rel[i], 1, 1,
				     gmp_matrix_rows(_Ic_rel[i]),
				     gmp_matrix_cols(_Ic_rel[i]));
    gmp_matrix_transp(JH);
    gmp_matrix_right_mult(JH, _complex->getBasis(i, 3));
    _Jh[i] = createIncMap(JH, _relcomplex->getBasis(i, 3));
  }
}

void HomologySequence::findInvJhMap(int i)
{
  if(_Ic_rel[i] != NULL
   && _complex->getBasisSize(i, 3) > 0
     && _relcomplex->getBasisSize(i, 3) > 0){
    gmp_matrix* JH = copy_gmp_matrix(_Ic_rel[i], 1, 1,
				     gmp_matrix_rows(_Ic_rel[i]),
				     gmp_matrix_cols(_Ic_rel[i]));
    gmp_matrix_right_mult(JH, _relcomplex->getBasis(i, 3));
    _invJh[i] = createIncMap(JH, _complex->getBasis(i, 3));
  }
}

void HomologySequence::findDhMap(int i)
{
  if(i > 0 && _relcomplex->getBasisSize(i, 3) > 0
     && _subcomplex->getBasisSize(i-1, 3) > 0
     && _complex->getBoundaryOp(i) != NULL){
    gmp_matrix* JDIH = copy_gmp_matrix(_Ic_sub[i-1], 1, 1,
				       gmp_matrix_rows(_Ic_sub[i-1]),
				       gmp_matrix_cols(_Ic_sub[i-1]));
    gmp_matrix_transp(JDIH);
    gmp_matrix_right_mult(JDIH, _complex->getBoundaryOp(i));
    gmp_matrix_right_mult(JDIH, _Ic_rel[i]);
    gmp_matrix_right_mult(JDIH, _relcomplex->getBasis(i, 3));
    _Dh[i] = createIncMap(JDIH, _subcomplex->getBasis(i-1, 3));
  }
}

void HomologySequence::findInvDhMap(int i)
{
  if(i > 0 && _relcomplex->getBasisSize(i, 3) > 0
     && _subcomplex->getBasisSize(i-1, 3) > 0
     && _complex->getBoundaryOp(i) != NULL){
    gmp_matrix* JDIH = copy_gmp_matrix(_Ic_rel[i], 1, 1,
				       gmp_matrix_rows(_Ic_rel[i]),
				       gmp_matrix_cols(_Ic_rel[i]));
    gmp_matrix_transp(JDIH);
    gmp_matrix* bd = _complex->getBoundaryOp(i);
    gmp_matrix_transp(bd);
    gmp_matrix_right_mult(JDIH, bd);
    gmp_matrix_transp(bd);
    gmp_matrix_right_mult(JDIH, _Ic_sub[i-1]);
    gmp_matrix_right_mult(JDIH, _subcomplex->getBasis(i-1, 3));
    _invDh[i] = createIncMap(JDIH, _relcomplex->getBasis(i, 3));
  }
}

//i: a->b  : aBasis = bBasis*incMap
gmp_matrix* HomologySequence::createIncMap(gmp_matrix* domBasis,
					   gmp_matrix* codBasis)
{
  if(domBasis == NULL || codBasis == NULL){
    printf("ERROR: null matrix given. \n");
    return NULL;
  }

  int rows = gmp_matrix_rows(domBasis);
  int cols = gmp_matrix_cols(domBasis);
  if(rows < cols || rows == 0 || cols == 0) return NULL;

  rows = gmp_matrix_rows(codBasis);
  cols = gmp_matrix_cols(codBasis);
  if(rows < cols || rows == 0 || cols == 0) return NULL;

  gmp_matrix* temp = codBasis;
  codBasis = copy_gmp_matrix(temp, 1, 1,
			     gmp_matrix_rows(temp),
			     gmp_matrix_cols(temp));
  // inv(U)*A*inv(V) = S
  gmp_normal_form* normalForm
    = create_gmp_Smith_normal_form(codBasis, INVERTED, INVERTED);

  mpz_t elem;
  mpz_init(elem);

  for(int i = 1; i <= cols; i++){
    gmp_matrix_get_elem(elem, i, i, normalForm->canonical);
    if(mpz_cmp_si(elem,0) == 0){
      destroy_gmp_normal_form(normalForm);
      return NULL;
    }
  }

  gmp_matrix_left_mult(normalForm->left, domBasis);
  gmp_matrix* LB = copy_gmp_matrix(domBasis, 1, 1,
				   gmp_matrix_cols(codBasis),
				   gmp_matrix_cols(domBasis));
  destroy_gmp_matrix(domBasis);

  rows = gmp_matrix_rows(LB);
  cols = gmp_matrix_cols(LB);

  mpz_t divisor;
  mpz_init(divisor);
  mpz_t remainder;
  mpz_init(remainder);
  mpz_t result;
  mpz_init(result);

  for(int i = 1; i <= rows; i++){
    gmp_matrix_get_elem(divisor, i, i, normalForm->canonical);
    for(int j = 1; j <= cols; j++){
      gmp_matrix_get_elem(elem, i, j, LB);
      mpz_cdiv_qr(result, remainder, elem, divisor);
      if(mpz_cmp_si(remainder, 0) == 0){
        gmp_matrix_set_elem(result, i, j, LB);
      }
      else return NULL;
    }
  }

  gmp_matrix_left_mult(normalForm->right, LB);

  mpz_clear(elem);
  mpz_clear(divisor);
  mpz_clear(result);
  destroy_gmp_normal_form(normalForm);
  return LB;
}

gmp_matrix* HomologySequence::removeZeroCols(gmp_matrix* matrix)
{
  mpz_t elem;
  mpz_init(elem);

  int rows = gmp_matrix_rows(matrix);
  int cols = gmp_matrix_cols(matrix);
  //printMatrix(matrix);
  std::vector<int> zcols;

  for(int j = 1; j <= cols; j++){
    bool zcol = true;
    for(int i = 1; i <= rows; i++){
      gmp_matrix_get_elem(elem, i, j, matrix);
      if(mpz_cmp_si(elem, 0) != 0){
	zcol = false;
	break;
      }
    }
    if(zcol) zcols.push_back(j);
  }
  if(zcols.empty()) return matrix;

  gmp_matrix* newMatrix = create_gmp_matrix_zero(rows, cols-zcols.size());
  if(cols-zcols.size() == 0) return newMatrix;

  int k = 0;
  for(int j = 1; j <= cols; j++){
    if((int)zcols.size()-1 < k) break;
    if(zcols.at(k) == j) { k++; continue; }
    for(int i = 1; i <= rows; i++){
      gmp_matrix_get_elem(elem, i, j, matrix);
      gmp_matrix_set_elem(elem, i, j-k, newMatrix);
    }
  }
  //printMatrix(newMatrix);
  destroy_gmp_matrix(matrix);
  mpz_clear(elem);
  return newMatrix;
}

void HomologySequence::blockHBasis(gmp_matrix* block1T,
				   gmp_matrix* block2T,
				   ChainComplex* complex, int dim)
{
  printMatrix(block1T);
  printMatrix(block2T);

  if(block1T == NULL && block2T == NULL) return;

  gmp_matrix* Hbasis = complex->getBasis(dim, 3);

  if(block1T == NULL && block2T != NULL){
    gmp_matrix_right_mult(Hbasis, block2T);
    printMatrix(Hbasis);
    return;
  }
  if(block1T != NULL && block2T == NULL){
    gmp_matrix_right_mult(Hbasis, block1T);
    printMatrix(Hbasis);
    return;
  }

  int rows = gmp_matrix_rows(Hbasis);
  int cols = gmp_matrix_cols(Hbasis);
  gmp_matrix* temp1 = copy_gmp_matrix(Hbasis, 1, 1, rows, cols);
  gmp_matrix* temp2 = copy_gmp_matrix(Hbasis, 1, 1, rows, cols);

  printMatrix(temp1);
  printMatrix(temp2);

  gmp_matrix_right_mult(temp1, block1T);
  gmp_matrix_right_mult(temp2, block2T);

  printMatrix(temp1);
  printMatrix(temp2);
  temp1 = removeZeroCols(temp1);
  temp2 = removeZeroCols(temp2);
  printMatrix(temp1);
  printMatrix(temp2);

  int bcol = gmp_matrix_cols(temp1);

  mpz_t elem;
  mpz_init(elem);
  for(int i = 1; i <= rows; i++){
    for(int j = 1; j <= cols; j++){
      if(j <= bcol) gmp_matrix_get_elem(elem, i, j, temp1);
      else gmp_matrix_get_elem(elem, i, j-bcol, temp2);
      gmp_matrix_set_elem(elem, i, j, Hbasis);
    }
  }

  printMatrix(Hbasis);
  mpz_clear(elem);
  destroy_gmp_matrix(temp1);
  destroy_gmp_matrix(temp2);
}

#endif
