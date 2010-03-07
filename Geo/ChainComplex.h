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
class ChainComplex{
 private:
  // boundary operator matrices for this chain complex
  // h_k: C_k -> C_(k-1)
  gmp_matrix* _HMatrix[5];
  
  // Basis matrices for the kernels and codomains of the boundary operator
  // matrices
  gmp_matrix* _kerH[5];
  gmp_matrix* _codH[5];
  
  gmp_matrix* _JMatrix[5];
  gmp_matrix* _QMatrix[5];
  std::vector<long int> _torsion[5];
  
  // bases for homology groups
  gmp_matrix* _Hbasis[5];
  
  int _dim;
  CellComplex* _cellComplex;

  std::map<int, Cell*> _cellIndices[4];
  
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
  
 public:
  
  // domain = 0 : relative chain space
  // domain = 1 : absolute chain space of all cells in cellComplex
  // domain = 2 : absolute chain space of cells in subdomain
  ChainComplex(CellComplex* cellComplex, int domain=0);  
  ~ChainComplex(){
    for(int i = 0; i < 5; i++){
      destroy_gmp_matrix(_HMatrix[i]);
      destroy_gmp_matrix(_kerH[i]);
      destroy_gmp_matrix(_codH[i]);
      destroy_gmp_matrix(_JMatrix[i]);
      destroy_gmp_matrix(_QMatrix[i]);
      destroy_gmp_matrix(_Hbasis[i]);
    }
  }
  
  int getDim() { return _dim; }
  
  // get the boundary operator matrix dim->dim-1
  gmp_matrix* getHMatrix(int dim) { 
    if(dim > -1 && dim < 5) return _HMatrix[dim]; else return NULL;}
  gmp_matrix* getKerHMatrix(int dim) { 
    if(dim > -1 && dim < 5) return _kerH[dim]; else return NULL;}
  gmp_matrix* getCodHMatrix(int dim) { 
    if(dim > -1 && dim < 5) return _codH[dim]; else return NULL;}
  gmp_matrix* getJMatrix(int dim) { 
    if(dim > -1 && dim < 5) return _JMatrix[dim]; else return NULL;}
  gmp_matrix* getQMatrix(int dim) { 
    if(dim > -1 && dim < 5) return _QMatrix[dim]; else return NULL;}
  gmp_matrix* getHbasis(int dim) { 
    if(dim > -1 && dim < 5) return _Hbasis[dim]; else return NULL;}
  
  // Compute basis for kernel and codomain of boundary operator matrix
  // of dimension dim (ie. ker(h_dim) and cod(h_dim) )
  void KerCod(int dim);
   // Compute matrix representation J for inclusion relation from dim-cells
   // who are boundary of dim+1-cells to cycles of dim-cells 
   // (ie. j: cod(h_(dim+1)) -> ker(h_dim) )
  void Inclusion(int lowDim, int highDim);
  // Compute quotient problem for given inclusion relation j to find
  //representatives of homology groups and possible torsion coeffcients
  void Quotient(int dim);
  
  // transpose the boundary operator matrices, these are boundary operator 
  // matrices for the dual mesh
  void transposeHMatrices() { 
    for(int i = 0; i < 5; i++) gmp_matrix_transp(_HMatrix[i]); }
  void transposeHMatrix(int dim) { 
    if(dim > -1 && dim < 5) gmp_matrix_transp(_HMatrix[dim]); }
  
  // Compute bases for the homology groups of this chain complex 
  void computeHomology(bool dual=false);
  
  // get coefficient vector for dim-dimensional chain chainNumber 
  // (columns of _Hbasis[dim]) 
  std::vector<int> getCoeffVector(int dim, int chainNumber);
  void getChain(std::map<Cell*, int, Less_Cell>& chain, int dim, int chainNumber);
  // torsion coefficient for dim-dimensional chain chainNumber 
  int getTorsion(int dim, int chainNumber);
  // get rank of homology group of dimension dim
  int getBasisSize(int dim) { 
    if(dim > -1 && dim < 5) return gmp_matrix_cols(_Hbasis[dim]);
    else return 0; } 
  
  int printMatrix(gmp_matrix* matrix){ 
    printf("%d rows and %d columns\n", 
	   (int)gmp_matrix_rows(matrix), (int)gmp_matrix_cols(matrix)); 
    return gmp_matrix_printf(matrix); } 
  
  // debugging aid
  void matrixTest();
};

#endif
   
#endif
   
