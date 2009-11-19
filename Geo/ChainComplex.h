// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
#include "MElement.h"
#include "GModel.h"
#include "GEntity.h"
#include "GRegion.h"
#include "GFace.h"
#include "GVertex.h"
#include "CellComplex.h"

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
   void setHMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5) _HMatrix[dim] = matrix;}
   void setKerHMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _kerH[dim] = matrix;}
   void setCodHMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _codH[dim] = matrix;}
   void setJMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _JMatrix[dim] = matrix;}
   void setQMatrix(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5)  _QMatrix[dim] = matrix;}
   void setHbasis(int dim, gmp_matrix* matrix) { if(dim > -1 && dim < 5) _Hbasis[dim] = matrix;}
   
   
   
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
   gmp_matrix* getHMatrix(int dim) { if(dim > -1 && dim < 5) return _HMatrix[dim]; else return NULL;}
   gmp_matrix* getKerHMatrix(int dim) { if(dim > -1 && dim < 5) return _kerH[dim]; else return NULL;}
   gmp_matrix* getCodHMatrix(int dim) { if(dim > -1 && dim < 5) return _codH[dim]; else return NULL;}
   gmp_matrix* getJMatrix(int dim) { if(dim > -1 && dim < 5) return _JMatrix[dim]; else return NULL;}
   gmp_matrix* getQMatrix(int dim) { if(dim > -1 && dim < 5) return _QMatrix[dim]; else return NULL;}
   gmp_matrix* getHbasis(int dim) { if(dim > -1 && dim < 5) return _Hbasis[dim]; else return NULL;}
   
   // Compute basis for kernel and codomain of boundary operator matrix of dimension dim (ie. ker(h_dim) and cod(h_dim) )
   void KerCod(int dim);
   // Compute matrix representation J for inclusion relation from dim-cells who are boundary of dim+1-cells 
   // to cycles of dim-cells (ie. j: cod(h_(dim+1)) -> ker(h_dim) )
   void Inclusion(int lowDim, int highDim);
   // Compute quotient problem for given inclusion relation j to find representatives of homology groups
   // and possible torsion coeffcients
   void Quotient(int dim);
   
   // transpose the boundary operator matrices, these are boundary operator matrices for the dual mesh
   void transposeHMatrices() { for(int i = 0; i < 5; i++) gmp_matrix_transp(_HMatrix[i]); }
   void transposeHMatrix(int dim) { if(dim > -1 && dim < 5) gmp_matrix_transp(_HMatrix[dim]); }
   
   // Compute bases for the homology groups of this chain complex 
   void computeHomology(bool dual=false);
   
   // get coefficient vector for dim-dimensional chain chainNumber 
   std::vector<int> getCoeffVector(int dim, int chainNumber);
   // torsion coefficient for dim-dimensional chain chainNumber 
   int getTorsion(int dim, int chainNumber);
   // get rank of homology group of dimension dim
   int getBasisSize(int dim) {  if(dim > -1 && dim < 5) return gmp_matrix_cols(_Hbasis[dim]); else return 0; } 
   
   int printMatrix(gmp_matrix* matrix){ 
     printf("%d rows and %d columns\n", (int)gmp_matrix_rows(matrix), (int)gmp_matrix_cols(matrix)); 
     return gmp_matrix_printf(matrix); } 
   
   // debugging aid
   void matrixTest();
};

// A class representing a chain.
// Used to visualize generators of the homology groups.
class Chain{
   
  private:
   // cells and their coefficients in this chain
   std::map< Cell*, int, Less_Cell > _cells;
   // name of the chain (optional)
   std::string _name;
   // cell complex this chain belongs to
   CellComplex* _cellComplex;
   
   // torsion coefficient
   int _torsion;
   
   int _dim;
   
   std::pair<Cell*, int> findRemainingBoundary(Cell* b, Cell* c1, Cell* c2, Cell* c3=NULL);
   Cell* findCommonCbdCell(Cell* c1, Cell* c2, Cell* c3=NULL);
   int findOrientation(Cell* b, Cell* c);
   bool straightenChain( std::pair<Cell*, int> cell);
   bool bendChain( std::pair<Cell*, int> cell);
   bool removeBoundary( std::pair<Cell*, int> cell);
   std::map<Cell*, int, Less_Cell>  getBdCellsInChain(Cell* cell);
   
  public:
   Chain(){}
   Chain(std::set<Cell*, Less_Cell> cells, std::vector<int> coeffs, CellComplex* cellComplex, std::string name="Chain", int torsion=0);
   Chain(Chain* chain){ 
     _cells = chain->getCells();
     _torsion = chain->getTorsion();
     _name = chain->getName();
     _cellComplex = chain->getCellComplex();
     _dim = chain->getDim();
   }
   ~Chain(){}
   
   typedef std::map<Cell*, int, Less_Cell>::iterator citer;
   
   // get i:th cell of this chain
   //Cell* getCell(int i) { return _cells.at(i).first; }
   // get coeffcient of i:th cell of this chain
   //int getCoeff(int i) { return _cells.at(i).second; }
   
   
   
   void removeCell(Cell* cell) {
     citer it = _cells.find(cell);
     if(it != _cells.end()){
       (*it).second = 0;
     }
     return;
   }
   void addCell(Cell* cell, int coeff) {
     std::pair<citer,bool> insert = _cells.insert( std::make_pair( cell, coeff));
     if(!insert.second && (*insert.first).second == 0) (*insert.first).second = coeff; 
     else if (!insert.second && (*insert.first).second != 0) printf("Error: invalid chain smoothening add! \n");
      
     if(!_cellComplex->hasCell(cell)){
       _cellComplex->insertCell(cell);
     }
     return;
   }
   /*
   void insertCells(){
     for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
       Cell* cell = (*cit).first;
       std::vector<Cell*> cells;
       if(!_cellComplex->hasCell(cell)){
         _cellComplex->insertCell(cell);
       }
       
     }
     return;
   }
   */
   
   bool hasCell(Cell* c){
     citer it = _cells.find(c);
     if(it != _cells.end() && (*it).second != 0) return true;
     return false;
   }
   
   Cell* findCell(Cell* c){
     citer it = _cells.find(c);
     if(it != _cells.end() && (*it).second != 0) return (*it).first;
     return NULL;
   }
   int getCoeff(Cell* c){
     citer it = _cells.find(c);
     if(it != _cells.end()) return (*it).second;
     return 0;
   }
     
   
   
   
   int getTorsion() {return _torsion;}
   int getDim() {return _dim;}
   CellComplex* getCellComplex() {return _cellComplex;}
   std::map<Cell*, int, Less_Cell>  getCells() {return _cells;}
   
   void eraseNullCells(){
     for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
       if( (*cit).second == 0){
         //cit++;
         //_cells.erase(--cit);
         _cells.erase(cit);
         ++cit;
       }
     }
     for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
       if( (*cit).second == 0){
         _cells.erase(cit);
         cit = _cells.begin(); 
       }
     }  
     return;
   }
   
   void deImmuneCells(){
     for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
       Cell* cell = (*cit).first;
       cell->setImmune(false);
     }
   }
   
   // number of cells in this chain 
   int getSize() { 
     //eraseNullCells();
     return _cells.size();
   }
   
   int getNumCells() {
     //int count = 0;
     //for(std::vector< std::pair <Cell*, int> >::iterator it = _cells.begin(); it != _cells.end(); it++){
     //  Cell* cell = (*it).first;
     //  count = count + cell->getNumCells();
     //}
     //return count;
     return _cells.size();
   }
   
   
   // get/set chain name
   std::string getName() { return _name; }
   void setName(std::string name) { _name=name; }

   void smoothenChain();
   
   // append this chain to a 2.1 MSH ASCII file as $ElementData
   int writeChainMSH(const std::string &name);
   
   //void getData(std::map<int, std::vector<double> >& data);
     
};
   
#endif
   
#endif
   
