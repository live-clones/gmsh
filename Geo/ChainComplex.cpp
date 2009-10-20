// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.

#include "ChainComplex.h"
#include "OS.h"

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

Chain::Chain(std::set<Cell*, Less_Cell> cells, std::vector<int> coeffs, CellComplex* cellComplex, std::string name, int torsion){
  
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
        //_cells.push_back( std::make_pair(cell, coeffs.at(i)) );
      }
      i++;
    }
    
  }
  _name = name;
  _cellComplex = cellComplex;
  _torsion = torsion;
  
}

Cell* Chain::findCommonCbdCell(Cell* c1, Cell* c2, Cell* c3){
  /*
  c1->printCell();
  c1->printOrgCbd();
  c2->printOrgCbd();
  c2->printCell();
  printf("------ \n");
  */
  
  std::map< Cell*, int, Less_Cell > c1Cbd = c1->getOrgCbd();
  for(std::map< Cell*, int, Less_Cell >::iterator it = c1Cbd.begin(); it != c1Cbd.end(); it++){
    Cell* c1CbdCell = (*it).first;
    if(c3 == NULL){ 
      if(c2->hasCoboundary(c1CbdCell, true)) return c1CbdCell;
    }
    else{
      if(c2->hasCoboundary(c1CbdCell, true) && c3->hasCoboundary(c1CbdCell, true)) return c1CbdCell;
    }
  }
  
  return NULL;
   
}

std::pair<Cell*, int> Chain::findRemainingBoundary(Cell* b, Cell* c1, Cell* c2, Cell* c3){
  std::map<Cell*, int, Less_Cell> bBd = b->getOrgBd();
  for(std::map<Cell*, int, Less_Cell >::iterator it = bBd.begin(); it != bBd.end(); it++){
    Cell* bBdCell = (*it).first;
    if(c3 == NULL) {
      if( !(*bBdCell == *c1) && !(*bBdCell == *c2)) return *it;
    }
    else{
      if( !(*bBdCell == *c1) && !(*bBdCell == *c2) && !(*bBdCell == *c3) ) return *it;
    }
  }
  
  return std::make_pair(b, 0);
}

int Chain::findOrientation(Cell* b, Cell* c){
  std::map< Cell*, int, Less_Cell > bBd = b->getOrgBd();
  std::map< Cell*, int, Less_Cell >::iterator it = bBd.find(c);
  if(it != bBd.end()) return (*it).second;
  return 0;
}

void Chain::smoothenChain(){  
  
  int start = getSize();
  double t1 = Cpu();
  
  if(getDim() == 1){
    for(citer i = _cells.begin(); i != _cells.end(); i++){
      Cell* c1 = (*i).first;
      int c1c = (*i).second;
      
      for(citer j = _cells.begin(); j != _cells.end(); j++){
        Cell* c2 = (*j).first;
        int c2c = (*j).second;
        if ( !(*c2 == *c1) && (c1c == 1 || c1c == -1) && (c2c == 1 || c2c == -1)){
          
          Cell* b = findCommonCbdCell(c1, c2);
          if(b != NULL){
          
            std::pair<Cell*, int> c3p = std::make_pair(b, 0);
            c3p = findRemainingBoundary(b, c1, c2);
            int c1o = findOrientation(b, c1);
            int c2o = findOrientation(b, c2);
            
            int temp1 = c1c - c1o;
            int temp2 = c2c - c2o;
            
            if(c3p.second != 0 && !c3p.first->inSubdomain()) {
              
              Cell* c3 = c3p.first;
              int c3o = c3p.second;
              
              int c3c = -c3o;
              if(temp1 != 0) c3c= c3c*-1;
              
              this->removeCell(c1, c1c);
              this->removeCell(c2, c2c);
              this->addCell(c3, c3c);
              c1c = (*i).second;
              c2c = (*j).second;
              
            }
          }
        }
      }
    }
  }
  /*
  else if(getDim() == 2){
    for(citer i = _cells.begin(); i != _cells.end(); i++){
      Cell* c1 = (*i).first;
      int c1c = (*i).second;
      
      /*
      int c1o = 0;
      
      Cell* c2 = NULL;
      int c2c = 0;
      int c2o = 0;
      
      Cell* c3 = NULL;
      int c3c = 0;
      int c3o = 0;
      
      std::map<Cell*, int, Less_Cell> c1Cbd c1->getOrgCbd();
      for(citer cit = c1Cbd.begin(); cit != c1Cbd.end(); cit++){
        Cell* c1CbdCell = (*cit).first;
        std::map<Cell*, int, Less_Cell> c1CbdBd c1CbdCell->getOrgBd();
        
        for(citer cit2 = c1CbdBd.begin(); cit2 != c1CbdBd.end(); cit2++){
          Cell* c1CbdBdCell = (*cit2).first;
          int c1CbdBdCellc = (*cit2).first;
          int count = 0;
          int coeff = getCoeff(c1CbdBdCell);
          if(coeff != 0 && !(*c1CbdBdCell == *c1)){
            count++;
            if(count == 0) { c2 = coeff; c2o=c1CbdBdCellc; }
            if(count == 1) { c3 = coeff; c3o=c1CbdBdCellc; }
            if(count == 2) break;    
          }
        }
        
      }
      
      
      
      for(citer j = _cells.begin(); j != _cells.end(); j++){
        Cell* c2 = (*j).first;
        int c2c = (*j).second;
        
        for(citer k = _cells.begin(); k != _cells.end(); k++){
          Cell* c3 = (*k).first;
          int c3c = (*k).second;
          
          if ( !(*c2 == *c1) && !(*c1 == *c3) && !(*c2 == *c3) && (c1c == 1 || c1c == -1) && (c2c == 1 || c2c == -1) && (c3c == 1 || c3c == -1)){
            
            Cell* b = findCommonCbdCell(c1, c2, c3);
            if(b != NULL){
              
              std::pair<Cell*, int> c4p = std::make_pair(b, 0);
              c4p = findRemainingBoundary(b, c1, c2, c3);
              int c1o = findOrientation(b, c1);
              int c2o = findOrientation(b, c2);
              int c3o = findOrientation(b, c3);
              
              int temp1 = c1c - c1o;
              int temp2 = c2c - c2o;
              int temp3 = c3c - c3o;
              
              if(c4p.second != 0 && !c4p.first->inSubdomain()) {
                
                Cell* c4 = c4p.first;
                int c4o = c4p.second;
                
                int c4c = -c4o;
                if(temp1 != 0) c4c= c4c*-1;
                
                this->removeCell(c1, c1c);
                this->removeCell(c2, c2c);
                this->removeCell(c3, c3c);
                this->addCell(c4, c4c);
                c1c = (*i).second;
                c2c = (*j).second;
                c3c = (*k).second;
              }
            }
          }
        }
      }
      
    }
  }*/
  
  eraseNullCells();
  double t2 = Cpu();
  printf("Smoothened a %d-chain from %d cells to %d cells (%g s). \n", getDim(), start, getSize(), t2-t1);
  return;
}

  
int Chain::writeChainMSH(const std::string &name){
  
  //_cellComplex->writeComplexMSH(name);
  
  if(getSize() == 0) return 0;
  
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
  
  //std::list< std::pair<int, Cell*> > cells;
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    Cell* cell = (*cit).first;
    int coeff = (*cit).second;
    fprintf(fp, "%d %d \n", cell->getNum(), coeff );
    /*
    cells = cell->getCells();    
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell2 = (*it).second;
     fprintf(fp, "%d %d \n", cell2->getNum(), getCoeff(i)*(*it).first );
    }
    */
  }
  
  fprintf(fp, "$EndElementData\n");
  
  fclose(fp);
  
  return 1;
  
}

/*
void Chain::getData(std::map<int, std::vector<double> > & data){
  
  if(getSize() == 0) return;
  
  //std::list< std::pair<int, Cell*> > cells;
  for(int i = 0; i < getSize(); i++){
    Cell* cell = getCell(i);
    /*
    cells = cell->getCells();
    for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
      Cell* cell2 = (*it).second;
      std::vector<double> coeff;
      coeff.push_back(getCoeff(i)*(*it).first);
      std::pair<int, std::vector<double> >  dataPair = std::make_pair(cell2->getTag(), coeff);
      data.insert(dataPair);
      //printf("%d, %d, \n", cell2->getNum(), (int)coeff.at(0));
      
    }
    
    std::vector<double> coeff;
    coeff.push_back(getCoeff(i));
    std::pair<int, std::vector<double> >  dataPair = std::make_pair(cell->getTag(), coeff);
    data.insert(dataPair);
    
  }
  
  //for(std::map<int, std::vector<double> >::iterator it = data.begin(); it != data.end(); it++){
  //  printf("%d, %d, \n", (*it).first, (int)(*it).second.at(0));  
  //}
  
  return; 
}
*/

#endif
