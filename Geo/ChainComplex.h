// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.

#ifndef _CHAINCOMPLEX_H_
#define _CHAINCOMPLEX_H_

#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include "GmshConfig.h"
#include "MElement.h"
#include "GModel.h"
#include "GEntity.h"
#include "GRegion.h"
#include "GFace.h"
#include "GVertex.h"
#include "CellComplex.h"

#if defined(HAVE_KBIPACK)

#include "gmp.h"
extern "C" {
  #include "gmp_normal_form.h" // perhaps make c++ headers instead?
}

// A class representing a chain complex of a cell complex.
// This should only be constructed for a reduced cell complex because of
// dense matrix representations and great computational complexity in its methods.
class ChainComplex{
  private:
   // boundary operator matrices for this chain complex
   // h_k: C_k -> C_(k-1)
   gmp_matrix* _HMatrix[5];
   
   // Basis matrices for the kernels and codomains of the boundary operator matrices
   gmp_matrix* _kerH[5];
   gmp_matrix* _codH[5];
   
   gmp_matrix* _JMatrix[5];
   gmp_matrix* _QMatrix[5];
   std::vector<long int> _torsion[5];
   
   // bases for homology groups
   gmp_matrix* _Hbasis[5];
   
   int _dim;
   CellComplex* _cellComplex;
   
   // set the matrices
   virtual void setHMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5) _HMatrix[dim] = matrix;}
   virtual void setKerHMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _kerH[dim] = matrix;}
   virtual void setCodHMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _codH[dim] = matrix;}
   virtual void setJMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _JMatrix[dim] = matrix;}
   virtual void setQMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _QMatrix[dim] = matrix;}
   virtual void setHbasis(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5) _Hbasis[dim] = matrix;}
   
   
   
  public:
   
   ChainComplex(CellComplex* cellComplex);
      
   ChainComplex(){
     for(int i = 0; i < 5; i++){
       _HMatrix[i] = create_gmp_matrix_zero(1,1);
       _kerH[i] = NULL;
       _codH[i] = NULL;
       _JMatrix[i] = NULL;
       _QMatrix[i] = NULL;
       _Hbasis[i] = NULL;
     }
     _dim = 0;
   }
   virtual ~ChainComplex(){}
   
   virtual int getDim() { return _dim; }
   
   // get the boundary operator matrix dim->dim-1
   virtual gmp_matrix* getHMatrix(int dim) { if(dim > -1 && dim < 5) return _HMatrix[dim]; else return NULL;}
   virtual gmp_matrix* getKerHMatrix(int dim) { if(dim > -1 && dim < 5) return _kerH[dim]; else return NULL;}
   virtual gmp_matrix* getCodHMatrix(int dim) { if(dim > -1 && dim < 5) return _codH[dim]; else return NULL;}
   virtual gmp_matrix* getJMatrix(int dim) { if(dim > -1 && dim < 5) return _JMatrix[dim]; else return NULL;}
   virtual gmp_matrix* getQMatrix(int dim) { if(dim > -1 && dim < 5) return _QMatrix[dim]; else return NULL;}
   virtual gmp_matrix* getHbasis(int dim) { if(dim > -1 && dim < 5) return _Hbasis[dim]; else return NULL;}
   
   // Compute basis for kernel and codomain of boundary operator matrix of dimension dim (ie. ker(h_dim) and cod(h_dim) )
   virtual void KerCod(int dim);
   // Compute matrix representation J for inclusion relation from dim-cells who are boundary of dim+1-cells 
   // to cycles of dim-cells (ie. j: cod(h_(dim+1)) -> ker(h_dim) )
   virtual void Inclusion(int lowDim, int highDim);
   // Compute quotient problem for given inclusion relation j to find representatives of homology groups
   // and possible torsion coeffcients
   virtual void Quotient(int dim);
   
   // transpose the boundary operator matrices, these are boundary operator matrices for the dual mesh
   virtual void transposeHMatrices() { for(int i = 0; i < 5; i++) gmp_matrix_transp(_HMatrix[i]); }
   virtual void transposeHMatrix(int dim) { if(dim > -1 && dim < 5) gmp_matrix_transp(_HMatrix[dim]); }
   
   // Compute bases for the homology groups of this chain complex 
   virtual void computeHomology(bool dual=false);
   
   virtual std::vector<int> getCoeffVector(int dim, int chainNumber);
   virtual int getBasisSize(int dim) {  if(dim > -1 && dim < 5) return gmp_matrix_cols(_Hbasis[dim]); else return 0; } 
   
   virtual int printMatrix(gmp_matrix* matrix){ 
     printf("%d rows and %d columns\n", gmp_matrix_rows(matrix), gmp_matrix_cols(matrix)); 
     return gmp_matrix_printf(matrix); } 
     
   // debugging aid
   virtual void matrixTest();
};

// A class representing a chain.
// Used to visualize generators of the homology groups.
class Chain{
   
  private:
   // cells and their coefficients in this chain
   std::vector< std::pair <Cell*, int> > _cells;
   // name of the chain (optional)
   std::string _name;
   // cell complex this chain belongs to
   CellComplex* _cellComplex;
   
  public:
   Chain(){}
   Chain(std::set<Cell*, Less_Cell> cells, std::vector<int> coeffs, CellComplex* cellComplex, std::string name="Chain");
   ~Chain(){}
   
   // get i:th cell of this chain
   virtual Cell* getCell(int i) { return _cells.at(i).first; }
   // get coeffcient of i:th cell of this chain
   virtual int getCoeff(int i) { return _cells.at(i).second; }
   
   // number of cells in this chain 
   virtual int getSize() { return _cells.size(); }
   
   virtual int getNumCells() {
     int count = 0;
     for(std::vector< std::pair <Cell*, int> >::iterator it = _cells.begin(); it != _cells.end(); it++){
       Cell* cell = (*it).first;
       count = count + cell->getNumCells();
     }
     return count;
   }
   
   
   // get/set chain name
   virtual std::string getName() { return _name; }
   virtual void setName(std::string name) { _name=name; }

   // append this chain to a 2.0 MSH ASCII file as $ElementData
   virtual int writeChainMSH(const std::string &name);
   
   virtual void getData(std::map<int, std::vector<double> >& data);
   
};

#endif

#endif
