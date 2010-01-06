// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "ChainComplex.h"
#include "OS.h"
#include "PView.h"
#include "Options.h"

#if defined(HAVE_KBIPACK)

ChainComplex::ChainComplex(CellComplex* cellComplex){
  
  _dim = cellComplex->getDim();
  _cellComplex = cellComplex;
  
  _HMatrix[4] = NULL;
  _kerH[4] = NULL;
  _codH[4] = NULL;
  _JMatrix[4] = NULL;
  _QMatrix[4] = NULL;
  _Hbasis[4] = NULL;
  
    
  for(int dim = 0; dim < 4; dim++){
    unsigned int cols = cellComplex->getSize(dim);
    unsigned int rows = 0;
    if(dim > 0) rows = cellComplex->getSize(dim-1);
  
    
    int index = 1;
    // ignore subdomain cells
    for(std::set<Cell*, Less_Cell>::iterator cit = cellComplex->firstCell(dim); cit != cellComplex->lastCell(dim); cit++){
      Cell* cell = *cit;
      cell->setIndex(index);
      index++;
      if(cell->inSubdomain()){
        index--;
        cols--;
      }
    }
    index = 1;
    if(dim > 0){
      for(std::set<Cell*, Less_Cell>::iterator cit = cellComplex->firstCell(dim-1); cit != cellComplex->lastCell(dim-1); cit++){
        Cell* cell = *cit;
        cell->setIndex(index);
        index++;
        if(cell->inSubdomain()){
          index--;
          rows--;
        }
      }
    }
    
    if( cols == 0 ){
      //_HMatrix[dim] = create_gmp_matrix_zero(rows, 1);
      _HMatrix[dim] = NULL;
    }
    else if( rows == 0){
      _HMatrix[dim] = create_gmp_matrix_zero(1, cols);
      //_HMatrix[dim] = NULL;
    }
    
    else{
     
      mpz_t elem;
      mpz_init(elem);
      
      _HMatrix[dim] = create_gmp_matrix_zero(rows, cols);
      //printMatrix(_HMatrix[dim]);
      for( std::set<Cell*, Less_Cell>::iterator cit = cellComplex->firstCell(dim); cit != cellComplex->lastCell(dim); cit++){
        Cell* cell = *cit;
        if(!cell->inSubdomain()){
          std::map<Cell*, int, Less_Cell> bdCell = cell->getOrientedBoundary();
          for(std::map<Cell*, int, Less_Cell>::iterator it = bdCell.begin(); it != bdCell.end(); it++){
            Cell* bdCell = (*it).first;
            if(!bdCell->inSubdomain()){
              int old_elem = 0;
              //printf("cell1: %d, cell2: %d \n", bdCell->getIndex(), cell->getIndex());
              if(bdCell->getIndex() > (int)gmp_matrix_rows( _HMatrix[dim]) || bdCell->getIndex() < 1 
                 || cell->getIndex() > (int)gmp_matrix_cols( _HMatrix[dim]) || cell->getIndex() < 1){
                printf("Warning: Index out of bound! HMatrix: %d. \n", dim);
              }
              else{
                gmp_matrix_get_elem(elem, bdCell->getIndex(), cell->getIndex(), _HMatrix[dim]);
                old_elem = mpz_get_si(elem);
                mpz_set_si(elem, old_elem + (*it).second);
                if( (old_elem + (*it).second) > 1 || (old_elem + (*it).second) < -1 ){
                  printf("Warning: Invalid incidence index: %d! HMatrix: %d.", (old_elem + (*it).second), dim);
                  printf(" Set to %d. \n", (old_elem + (*it).second) % 2);
                  mpz_set_si(elem, (old_elem + (*it).second) % 2);
                }
                gmp_matrix_set_elem(elem, bdCell->getIndex(), cell->getIndex(), _HMatrix[dim]);
              }
            }
          }
        }
      }
      
      mpz_clear(elem);
      
    }
    
    /*
    else{
      
      long int elems[rows*cols];
      
      std::set<Cell*, Less_Cell>::iterator high = cellComplex->firstCell(dim);
      std::set<Cell*, Less_Cell>::iterator low = cellComplex->firstCell(dim-1);
      
      unsigned int i = 0;
      while(i < rows*cols){
        while(low != cellComplex->lastCell(dim-1)){
          Cell* lowcell = *low;
          Cell* highcell = *high;
          if(!(highcell->inSubdomain() || lowcell->inSubdomain())){
            
            
            std::list< std::pair<int, Cell*> >bdHigh = highcell->getBoundary();
            for(std::list< std::pair<int, Cell*> >::iterator it = bdHigh.begin(); it != bdHigh.end(); it++){
              Cell* bdCell = (*it).second;
              if(bdCell->getTag() == lowcell->getTag()) elems[i] = (*it).first;
              else elems[i] = 0;
            }
            
              
            elems[i] = cellComplex->kappa(*high, *low);
            i++;
          }
          low++;
        }
        low = cellComplex->firstCell(dim-1);
        high++;
      }
      _HMatrix[dim] = create_gmp_matrix_int(rows, cols, elems);      
    }
    */


    _kerH[dim] = NULL;
    _codH[dim] = NULL;
    _JMatrix[dim] = NULL;
    _QMatrix[dim] = NULL;
    _Hbasis[dim] = NULL; 
    
  }
  
  return;
}


void ChainComplex::KerCod(int dim){
  
  if(dim < 0 || dim > 3 || _HMatrix[dim] == NULL) return;
  
  gmp_matrix* HMatrix = copy_gmp_matrix(_HMatrix[dim], 1, 1, 
                                        gmp_matrix_rows(_HMatrix[dim]), gmp_matrix_cols(_HMatrix[dim]));
  
  gmp_normal_form* normalForm = create_gmp_Hermite_normal_form(HMatrix, NOT_INVERTED, INVERTED);
  //printMatrix(normalForm->left);
  //printMatrix(normalForm->canonical);
  //printMatrix(normalForm->right);
  
  int minRowCol = std::min(gmp_matrix_rows(normalForm->canonical), gmp_matrix_cols(normalForm->canonical));
  int rank = 0;
  mpz_t elem;
  mpz_init(elem);
  
  while(rank < minRowCol){
    gmp_matrix_get_elem(elem, rank+1, rank+1, normalForm->canonical);
    if(mpz_cmp_si(elem,0) == 0) break;
    rank++;
  }
  
  if(rank != (int)gmp_matrix_cols(normalForm->canonical)){
    _kerH[dim] = copy_gmp_matrix(normalForm->right, 1, rank+1, 
                                 gmp_matrix_rows(normalForm->right),  gmp_matrix_cols(normalForm->right));
  }
  
  if(rank > 0){
     _codH[dim] = copy_gmp_matrix(normalForm->canonical, 1, 1,
                                  gmp_matrix_rows(normalForm->canonical), rank);
    gmp_matrix_left_mult(normalForm->left, _codH[dim]);
  }
  
  mpz_clear(elem);
  destroy_gmp_normal_form(normalForm);
  
  return;
}

//j:B_(k+1)->Z_k
void ChainComplex::Inclusion(int lowDim, int highDim){
  
  if(getKerHMatrix(lowDim) == NULL || getCodHMatrix(highDim) == NULL || abs(lowDim-highDim) != 1) return;
  
  gmp_matrix* Zbasis = copy_gmp_matrix(_kerH[lowDim], 1, 1,
                                       gmp_matrix_rows(_kerH[lowDim]), gmp_matrix_cols(_kerH[lowDim]));
  gmp_matrix* Bbasis = copy_gmp_matrix(_codH[highDim], 1, 1,
                                       gmp_matrix_rows(_codH[highDim]), gmp_matrix_cols(_codH[highDim]));
  
  
  int rows = gmp_matrix_rows(Bbasis);
  int cols = gmp_matrix_cols(Bbasis);
  if(rows < cols) return;
  
  rows = gmp_matrix_rows(Zbasis);
  cols = gmp_matrix_cols(Zbasis);
  if(rows < cols) return;
  
  
  // A*inv(V) = U*S
  gmp_normal_form* normalForm = create_gmp_Smith_normal_form(Zbasis, INVERTED, INVERTED);
  
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
  
  
  
  gmp_matrix* LB = copy_gmp_matrix(Bbasis, 1, 1, gmp_matrix_cols(Zbasis), gmp_matrix_cols(Bbasis));
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
  
  return;
  
}

void ChainComplex::Quotient(int dim){
  
  if(dim < 0 || dim > 4 || _JMatrix[dim] == NULL) return;
  
  gmp_matrix* JMatrix = copy_gmp_matrix(_JMatrix[dim], 1, 1,
                                        gmp_matrix_rows(_JMatrix[dim]), gmp_matrix_cols(_JMatrix[dim]));
  int rows = gmp_matrix_rows(JMatrix);
  int cols = gmp_matrix_cols(JMatrix);
  
  gmp_normal_form* normalForm = create_gmp_Smith_normal_form(JMatrix, NOT_INVERTED, NOT_INVERTED);

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
    gmp_matrix* Hbasis = copy_gmp_matrix(normalForm->left, 1, rank+1, rows, rows);
    _QMatrix[dim] = Hbasis;
  }
  
  mpz_clear(elem);
  destroy_gmp_normal_form(normalForm);
  return; 
}

void ChainComplex::computeHomology(bool dual){
  
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
    
    printf("Homology computation process: step %d of 4 \n", i+1);
    
    KerCod(highDim);
    
    // 1) no edges, but zero cells
    if(lowDim == 0 && !dual &&  gmp_matrix_cols(getHMatrix(lowDim)) > 0 && getHMatrix(highDim) == NULL) {
      setHbasis( setDim, create_gmp_matrix_identity(gmp_matrix_cols(getHMatrix(lowDim))) );
    }
    else if(highDim == 0 && dual &&  gmp_matrix_rows(getHMatrix(highDim)) > 0 && getHMatrix(lowDim) == NULL) {
      setHbasis( setDim, create_gmp_matrix_identity(gmp_matrix_rows(getHMatrix(highDim))) );
    }
    
    // 2) this dimension is empty
    else if(getHMatrix(lowDim) == NULL && getHMatrix(highDim) == NULL){
      setHbasis(setDim, NULL);
    }
    // 3) No higher dimension cells -> none of the cycles are boundaries
    else if(getHMatrix(highDim) == NULL){
      setHbasis( setDim, copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
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
        setKerHMatrix(lowDim, create_gmp_matrix_identity(gmp_matrix_rows(getHMatrix(highDim))) );
      }
      Inclusion(lowDim, highDim);
      Quotient(lowDim);
      
      if(getCodHMatrix(highDim) == NULL){
        setHbasis(setDim, copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1,
                                          gmp_matrix_rows(getKerHMatrix(lowDim)), 
                                          gmp_matrix_cols(getKerHMatrix(lowDim))) );
      }  
      else if(getJMatrix(lowDim) == NULL || getQMatrix(lowDim) == NULL){
        setHbasis(setDim, NULL);
      } 
      else{
        setHbasis(setDim, copy_gmp_matrix(getKerHMatrix(lowDim), 1, 1, 
                                          gmp_matrix_rows(getKerHMatrix(lowDim)), 
                                          gmp_matrix_cols(getKerHMatrix(lowDim))) );
        
        gmp_matrix_right_mult(getHbasis(setDim), getQMatrix(lowDim));
      } 
      
    } 
    
    destroy_gmp_matrix(getKerHMatrix(lowDim));
    destroy_gmp_matrix(getCodHMatrix(lowDim));
    destroy_gmp_matrix(getJMatrix(lowDim));
    destroy_gmp_matrix(getQMatrix(lowDim));
    
    setKerHMatrix(lowDim, NULL);
    setCodHMatrix(lowDim, NULL);
    setJMatrix(lowDim, NULL);
    setQMatrix(lowDim, NULL);
     
  }
  
  
  return;
}


void ChainComplex::matrixTest(){
  
  int rows = 3;
  int cols = 6;
  
  long int elems[rows*cols];
  for(int i = 1; i<=rows*cols; i++) elems[i-1] = i;
  
  gmp_matrix* matrix = create_gmp_matrix_int(rows, cols, elems);
  
  gmp_matrix* copymatrix = copy_gmp_matrix(matrix, 3, 2, 3, 5);
  
  printMatrix(matrix);
  printMatrix(copymatrix);
  
  return; 
}

std::vector<int> ChainComplex::getCoeffVector(int dim, int chainNumber){
  
  std::vector<int> coeffVector;
  
  if(dim < 0 || dim > 4) return coeffVector;
  if(_Hbasis[dim] == NULL || (int)gmp_matrix_cols(_Hbasis[dim]) < chainNumber) return coeffVector;
  
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

int ChainComplex::getTorsion(int dim, int chainNumber){
  if(dim < 0 || dim > 4) return 0;
  if(_Hbasis[dim] == NULL || (int)gmp_matrix_cols(_Hbasis[dim]) < chainNumber) return 0;
  if(_torsion[dim].empty() || (int)_torsion[dim].size() < chainNumber) return 1;
  else return _torsion[dim].at(chainNumber-1);
  
}

Chain::Chain(std::set<Cell*, Less_Cell> cells, std::vector<int> coeffs, CellComplex* cellComplex, GModel* model, std::string name, int torsion){
  
  int i = 0;
  for(std::set<Cell*, Less_Cell>::iterator cit = cells.begin(); cit != cells.end(); cit++){
    Cell* cell = *cit;
    _dim = cell->getDim();
    if(!cell->inSubdomain() && (int)coeffs.size() > i){
      if(coeffs.at(i) != 0){
        std::list< std::pair<int, Cell*> > subCells = cell->getCells();
        for(std::list< std::pair<int, Cell*> >::iterator it = subCells.begin(); it != subCells.end(); it++){
          Cell* subCell = (*it).second;
          int coeff = (*it).first;
          _cells.insert( std::make_pair(subCell, coeffs.at(i)*coeff));
        }
      }
      i++;
    }
    
  }
  _name = name;
  _cellComplex = cellComplex;
  _torsion = torsion;
  _model = model;
  
}

bool Chain::deform(std::map<Cell*, int, Less_Cell> &cellsInChain, std::map<Cell*, int, Less_Cell> &cellsNotInChain){
  //printf("--- \n");
  std::vector<int> cc;
  std::vector<int> bc;
  
  for(citer cit = cellsInChain.begin(); cit != cellsInChain.end(); cit++){
    Cell* c = (*cit).first;
    c->setImmune(false);
    //c->printCell();
    if(!c->inSubdomain()) {
      cc.push_back(getCoeff(c));
      bc.push_back((*cit).second);
    }
    removeCell(c);
  }
  if(cc.empty()) return false;
  int inout = cc[0]*bc[0];
  for(int i = 0; i < cc.size(); i++){
    //printf("cc: %d, bc: %d \n", cc.at(i), bc.at(i));
    if(cc[i]*bc[i] != inout) printf("Error: Chain smoothening orientation mismatch! \n");
  }
  
  //for(citer cit = cellsInChain.begin(); cit != cellsInChain.end(); cit++) removeCell((*cit).first);
  
  int n = 1;
  for(citer cit = cellsNotInChain.begin(); cit != cellsNotInChain.end(); cit++){
    Cell* c = (*cit).first;
    if(n == 2) c->setImmune(true);
    else c->setImmune(false);
    int coeff = -1*inout*(*cit).second;
    addCell(c, coeff);
    //c->printCell();
    n++;
  }
  //printf("--- \n");
  
  return true;
}

bool Chain::deformChain(std::pair<Cell*, int> cell, bool bend){
  
  Cell* c1 = cell.first;
  std::map<Cell*, int, Less_Cell> c1Cbd = c1->getOrgCbd();
  for(citer cit = c1Cbd.begin(); cit != c1Cbd.end(); cit++){
    
    std::map<Cell*, int, Less_Cell> cellsInChain;
    std::map<Cell*, int, Less_Cell> cellsNotInChain;
    Cell* c1CbdCell = (*cit).first;
    //c1CbdCell->printCell();
    //c1CbdCell->printOrgBd();
    std::map<Cell*, int, Less_Cell> c1CbdBd = c1CbdCell->getOrgBd();
    for(citer cit2 = c1CbdBd.begin(); cit2 != c1CbdBd.end(); cit2++){
      Cell* c1CbdBdCell = (*cit2).first;
      int coeff = (*cit2).second;
      if( (hasCell(c1CbdBdCell) && getCoeff(c1CbdBdCell) != 0) || c1CbdBdCell->inSubdomain()) cellsInChain.insert(std::make_pair(c1CbdBdCell, coeff));
      else cellsNotInChain.insert(std::make_pair(c1CbdBdCell, coeff));
    }
    
    bool next = false;
    
    for(citer cit2 = cellsInChain.begin(); cit2 != cellsInChain.end(); cit2++){
      Cell* c = (*cit2).first;
      int coeff = getCoeff(c);
      if(c->getImmune()) next = true;
      if(c->inSubdomain()) bend = false;
      if(coeff > 1 || coeff < -1) next = true; 
    }
    
    for(citer cit2 = cellsNotInChain.begin(); cit2 != cellsNotInChain.end(); cit2++){
      Cell* c = (*cit2).first;
      if(c->inSubdomain()) next = true;
    }
    
    if(next) continue;
    
    if(getDim() != 2) bend = false;
    
    //printf("dim: %d, in chain: %d, not in chain: %d \n", getDim(), cellsInChain.size(), cellsNotInChain.size());
    
    if( (getDim() == 1 && cellsInChain.size() == 2 && cellsNotInChain.size() == 1) ||
        (getDim() == 2 && cellsInChain.size() == 3 && cellsNotInChain.size() == 1)){
      //printf("straighten \n");
      return deform(cellsInChain, cellsNotInChain);
    }
    else if ( (getDim() == 1 && cellsInChain.size() == 1 && cellsNotInChain.size() == 2 && bend) ||
              (getDim() == 2 && cellsInChain.size() == 2 && cellsNotInChain.size() == 2 && bend)){
      //printf("bend \n");
      return deform(cellsInChain, cellsNotInChain);
    }
    else if ((getDim() == 1 && cellsInChain.size() == 3 && cellsNotInChain.size() == 0) ||
             (getDim() == 2 && cellsInChain.size() == 4 && cellsNotInChain.size() == 0)){
      //printf("remove boundary \n");
      return deform(cellsInChain, cellsNotInChain);
    }
  }
  
  return false;
}

void Chain::smoothenChain(){

  if(!_cellComplex->simplicial()) return;
  
  int start = getSize();
  double t1 = Cpu();
  
  int useless = 0;
  for(int i = 0; i < 20; i++){
    int size = getSize();
    for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
      deformChain(*cit, true);
      deformChain(*cit, false);
    }
    deImmuneCells();
    eraseNullCells();
    if (size >= getSize()) useless++;
    else useless = 0;
    if (useless > 5) break;
  }
  
  deImmuneCells();
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++) deformChain(*cit, false);
  
  eraseNullCells();
  double t2 = Cpu();
  printf("Smoothened a %d-chain from %d cells to %d cells (%g s).\n", getDim(), start, getSize(), t2-t1);
  return;
}


int Chain::writeChainMSH(const std::string &name){
  
  //_cellComplex->writeComplexMSH(name);
  
  if(getSize() == 0) return 1;
  
  FILE *fp = fopen(name.c_str(), "a");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
        printf("Unable to open file.");
        return 0;
  }
 
  fprintf(fp, "\n$ElementData\n");
  
  fprintf(fp, "1 \n");
  fprintf(fp, "\"%s\" \n", getName().c_str());
  fprintf(fp, "1 \n");
  fprintf(fp, "0.0 \n");
  fprintf(fp, "4 \n");
  fprintf(fp, "0 \n");
  fprintf(fp, "1 \n");
  fprintf(fp, "%d \n", getSize());
  fprintf(fp, "0 \n");
  
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    Cell* cell = (*cit).first;
    int coeff = (*cit).second;
    fprintf(fp, "%d %d \n", cell->getNum(), coeff );
  }
  
  fprintf(fp, "$EndElementData\n");
  fclose(fp);
  
  return 1;
}

void Chain::createPView(){
  
  std::vector<MElement*> elements;
  MElementFactory factory;
  std::map<int, std::vector<double> > data;
  
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    Cell* cell = (*cit).first;
    int coeff = (*cit).second;
    std::vector<MVertex*> v = cell->getVertexVector();
    if(cell->getDim() > 0 && coeff < 0){ // flip orientation
      if(getDim() != 1){
        MVertex* temp = v[1];
        v[1] = v[v.size()-1];
        v[v.size()-1] = temp;
      }
      else{
        MVertex* temp = v[0];
        v[0] = v[1];
        v[1] = temp;
      }
    }
    MElement *e = factory.create(cell->getTypeForMSH(), v, cell->getNum(), cell->getPartition());
    for(int i = 0; i < abs(coeff); i++) elements.push_back(e);
    
    std::vector<double> coeffs (1,abs(coeff));
    data[e->getNum()] = coeffs;
  }
  
  int max[4];
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max,max+4) + 1;
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max,max+4) + 1;
  setNum(physicalNum);
  
  std::map<int, std::vector<MElement*> > entityMap;
  //int entityNum = _model->getMaxElementaryNumber(getDim())+1;
  entityMap[entityNum] = elements;
  std::map<int, std::map<int, std::string> > physicalMap;
  std::map<int, std::string> physicalInfo;
  //int physicalNum = _model->getMaxPhysicalNumber(getDim())+1; 
  physicalInfo[physicalNum]=getName();
  physicalMap[entityNum] = physicalInfo;
  
  // hide mesh
  opt_mesh_points(0, GMSH_SET, 0);
  opt_mesh_lines(0, GMSH_SET, 0);
  opt_mesh_triangles(0, GMSH_SET, 0);
  opt_mesh_quadrangles(0, GMSH_SET, 0);
  opt_mesh_tetrahedra(0, GMSH_SET, 0);
  opt_mesh_hexahedra(0, GMSH_SET, 0);
  opt_mesh_prisms(0, GMSH_SET, 0);
  opt_mesh_pyramids(0, GMSH_SET, 0);

  // show post-processing normals, tangents and element boundaries
  opt_view_normals(0, GMSH_SET, 20);
  opt_view_tangents(0, GMSH_SET, 20);
  opt_view_show_element(0, GMSH_SET, 1);
  
  if(!data.empty()){
    _model->storeChain(getDim(), entityMap, physicalMap);
    _model->setPhysicalName(getName(), getDim(), physicalNum);
    
    // only for visualization
    PView *chain = new PView(getName(), "ElementData", getGModel(), data, 0, 1);
  }
  
  return;
}


#endif
