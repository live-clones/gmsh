// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _CHAINCOMPLEX_H_
#define _CHAINCOMPLEX_H_

#include "GmshConfig.h"

#if defined(HAVE_KBIPACK)

#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include "CellComplex.h"

#if defined(HAVE_GMP) 
  #include "gmp.h"
  #include "gmp_normal_form.h"
#else
  #include "mpz.h"
  #include "gmp_normal_form.h"
#endif

class CellComplex;

// A class representing a chain complex of a cell complex.
// This should only be constructed for a reduced cell complex because of
// dense matrix representations and great computational complexity in 
// its methods.
class ChainComplex
{
 private:
  // boundary operator matrices for this chain complex
  // h_k: C_k -> C_(k-1)
  gmp_matrix* _HMatrix[5];
  
  // Basis matrices for the kernels and codomains of the boundary operator
  // matrices
  gmp_matrix* _kerH[5];
  gmp_matrix* _codH[5];
  
  // matrix of the mapping B_k -> Z_k
  gmp_matrix* _JMatrix[5];
  // matrix of the mapping H_k -> Z_k
  gmp_matrix* _QMatrix[5];

  // bases for homology groups
  gmp_matrix* _Hbasis[5];
  // torsion coefficients of homology generators
  // corresponding the columns of _Hbasis
  std::vector<long int> _torsion[5];
  
  int _dim;
  CellComplex* _cellComplex;

  // index to cell map 
  // matrix indices correspond to these cells in _cellComplex
  std::map<Cell*, int, Less_Cell> _cellIndices[4];
  
  // set the matrices
  void setHMatrix(int dim, gmp_matrix* matrix) { 
    if(dim > -1 && dim < 5) _HMatrix[dim] = matrix;}
  void setKerHMatrix(int dim, gmp_matrix* matrix) { 
    if(dim > -1 && dim < 5)  _kerH[dim] = matrix;}
  void setCodHMatrix(int dim, gmp_matrix* matrix) { 
    if(dim > -1 && dim < 5)  _codH[dim] = matrix;}
  void setJMatrix(int dim, gmp_matrix* matrix) { 
    if(dim > -1 && dim < 5)  _JMatrix[dim] = matrix;}
  void setQMatrix(int dim, gmp_matrix* matrix) { 
    if(dim > -1 && dim < 5)  _QMatrix[dim] = matrix;}
  void setHbasis(int dim, gmp_matrix* matrix) { 
    if(dim > -1 && dim < 5) _Hbasis[dim] = matrix;}


  // get the boundary operator matrix dim->dim-1
  gmp_matrix* getHMatrix(int dim) const { 
    if(dim > -1 && dim < 5) return _HMatrix[dim]; else return NULL;}
  gmp_matrix* getKerHMatrix(int dim) const { 
    if(dim > -1 && dim < 5) return _kerH[dim]; else return NULL;}
  gmp_matrix* getCodHMatrix(int dim) const { 
    if(dim > -1 && dim < 5) return _codH[dim]; else return NULL;}
  gmp_matrix* getJMatrix(int dim) const { 
    if(dim > -1 && dim < 5) return _JMatrix[dim]; else return NULL;}
  gmp_matrix* getQMatrix(int dim) const { 
    if(dim > -1 && dim < 5) return _QMatrix[dim]; else return NULL;}
  gmp_matrix* getHbasis(int dim) const { 
    if(dim > -1 && dim < 5) return _Hbasis[dim]; else return NULL;}

  // local deformation tools for chains
  bool deformChain(std::map<Cell*, int, Less_Cell>& cells,
		   std::pair<Cell*, int> cell, bool bend);
  bool deform(std::map<Cell*, int, Less_Cell>& cells,
	      std::map<Cell*, int, Less_Cell>& cellsInChain, 
	      std::map<Cell*, int, Less_Cell>& cellsNotInChain);
  void smoothenChain(std::map<Cell*, int, Less_Cell>& cells);
  void eraseNullCells(std::map<Cell*, int, Less_Cell>& cells);
  void deImmuneCells(std::map<Cell*, int, Less_Cell>& cells);
    
 public:  
  // domain = 0 : relative chain space
  // domain = 1 : absolute chain space of all cells in cellComplex
  // domain = 2 : absolute chain space of cells in subdomain
  ChainComplex(CellComplex* cellComplex, int domain=0);  
  ~ChainComplex();
  
  int getDim() const { return _dim; }
  
  // 0 : C basis (chains)
  // 1 : Z basis (cycles)
  // 2 : B basis (boundaries)
  // 3 : H basis (homology)
  // get the bases for various spaces
  gmp_matrix* getBasis(int dim, int basis);  
  gmp_matrix* getBoundaryOp(int dim) {
    if(dim > -1 && dim < 5) return _HMatrix[dim]; else return NULL;}

  // compute basis for kernel and codomain of boundary operator matrix
  // of dimension dim (ie. ker(h_dim) and cod(h_dim) )
  void KerCod(int dim);
   // compute matrix representation J for inclusion relation from dim-cells
   // who are boundary of dim+1-cells to cycles of dim-cells 
   // (ie. j: cod(h_(dim+1)) -> ker(h_dim) )
  void Inclusion(int lowDim, int highDim);
  // compute quotient problem for given inclusion relation j to find
  // representatives of homology group generators and possible 
  // torsion coeffcients
  void Quotient(int dim);
  
  // transpose the boundary operator matrices, these are boundary operator 
  // matrices for the dual mesh
  void transposeHMatrices() { 
    for(int i = 0; i < 5; i++) gmp_matrix_transp(_HMatrix[i]); }
  void transposeHMatrix(int dim) { 
    if(dim > -1 && dim < 5) gmp_matrix_transp(_HMatrix[dim]); }
  
  // Compute bases for the homology groups of this chain complex 
  void computeHomology(bool dual=false);
  
  
  typedef std::map<Cell*, int, Less_Cell>::iterator citer;
  citer firstCell(int dim){ return _cellIndices[dim].begin(); } 
  citer lastCell(int dim){ return _cellIndices[dim].end(); } 
  // get the cell index
  int cellIndex(Cell* cell){
    citer cit = _cellIndices[cell->getDim()].find(cell);
    if(cit != lastCell(cell->getDim())) return cit->second;
    else return 0;
  }

  // get coefficient vector for dim-dimensional Hbasis chain chainNumber
  std::vector<int> getCoeffVector(int dim, int chainNumber);
  // get basis chain from a basis matrix
  // (deform: with local deformations to make chain smoother and to have
  // smaller support, deformed chain is homologous to the old one,
  // only works for chains of the primary chain complex)
  void getBasisChain(std::map<Cell*, int, Less_Cell>& chain, 
		     int num, int dim, int basis, bool deform=false);
  // get rank of a basis
  int getBasisSize(int dim, int basis);
  // homology torsion coefficient for dim-dimensional chain num 
  int getTorsion(int dim, int num);
  
  // apply a transformation T to a basis (T should be unimodular)
  void transformBasis(gmp_matrix* T, int dim, int basis){
    if(basis == 3 && _Hbasis[dim] != NULL) {
      gmp_matrix_right_mult(_Hbasis[dim], T);
    }
  }

  // debugging aid
  int printMatrix(gmp_matrix* matrix){ 
    printf("%d rows and %d columns\n", 
	   (int)gmp_matrix_rows(matrix), (int)gmp_matrix_cols(matrix)); 
    return gmp_matrix_printf(matrix); } 
  void matrixTest();
};


// An experimental class to modify computed bases for homnology spaces
// so that the basis chains are decomposed according to the long
// exact homology sequence.
class HomologySequence
{
 private:
  ChainComplex* _subcomplex;
  ChainComplex* _complex;
  ChainComplex* _relcomplex;
  
  gmp_matrix* _Ic_sub[4];
  gmp_matrix* _Ic_rel[4];

  gmp_matrix* _Ih[4];
  gmp_matrix* _Jh[4];
  gmp_matrix* _invIh[4];
  gmp_matrix* _invJh[4];
  

  gmp_matrix* _Dh[4];
  gmp_matrix* _invDh[4];

  void findIcMaps();
  void findIhMap(int i);
  void findInvIhMap(int i);
  void findJhMap(int i);
  void findInvJhMap(int i);
  void findDhMap(int i);
  void findInvDhMap(int i);

 public:
  
  HomologySequence(ChainComplex* subcomplex, ChainComplex* complex, 
		   ChainComplex* relcomplex);
  ~HomologySequence();

  // create an inclusion map from domBasis to codBasis
  // (deletes domBasis, leaves codBasis unaffected)
  gmp_matrix* createIncMap(gmp_matrix* domBasis, 
			   gmp_matrix* codBasis);


  gmp_matrix* removeZeroCols(gmp_matrix* matrix);
  void blockHBasis(gmp_matrix* block1T, gmp_matrix* block2T, 
		   ChainComplex* complex, int dim);
    
  int printMatrix(gmp_matrix* matrix){
    if(matrix == NULL){ printf("NULL matrix. \n"); return 0; }
    printf("%d rows and %d columns\n",
           (int)gmp_matrix_rows(matrix), (int)gmp_matrix_cols(matrix));
    return gmp_matrix_printf(matrix); }  
  
};

#endif
   
#endif
   
