// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _CELLCOMPLEX_H_
#define _CELLCOMPLEX_H_

#include "GmshConfig.h"

#if defined(HAVE_KBIPACK)

#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include "Cell.h"
#include "MElement.h"
#include "GModel.h"
#include "GEntity.h"
#include "GRegion.h"
#include "GFace.h"
#include "GVertex.h"

class Cell;

// A class representing a cell complex made out of a finite element mesh.
class CellComplex
{
 private:
   
   // the domain in the model which this cell complex covers
   std::vector<GEntity*> _domain;
   // a subdomain of the given domain
   // used in relative homology computation, may be empty
   std::vector<GEntity*> _subdomain;
   
   // entities on the boundary of the homology computation domain
   std::vector<GEntity*> _boundary;
   
   // sorted containers of unique cells in this cell complex 
   // one for each dimension
   std::set<Cell*, Less_Cell>  _cells[4];
   
   // temporary store for omitted cells (generators of the highest dimension)
   std::vector< std::set<Cell*, Less_Cell> > _store;
   
   // original cells of this cell complex
   std::set<Cell*, Less_Cell>  _ocells[4];
   
   // Betti numbers of this cell complex (ranks of homology groups)
   int _betti[4];
   
   int _dim;
   
   // is the cell complex simplicial
   bool _simplicial;
   
   // enqueue cells in queue if they are not there already
   void enqueueCells(std::list<Cell*>& cells, 
                             std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset);
   // remove cell from the queue set
   void removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset);
      
   // for constructor 
   void insert_cells(bool subdomain, bool boundary);
   void find_boundary(std::vector<GEntity*>& domain, std::vector<GEntity*>& subdomain);
   
   // remove a cell from this cell complex
   void removeCell(Cell* cell, bool other=true);
   
   // queued coreduction presented in Mrozek's paper
   int coreduction(Cell* generator, int omitted=0);
   
  public: 
   
   CellComplex( std::vector<GEntity*> domain, std::vector<GEntity*> subdomain );
   //CellComplex(CellComplex* cellComplex)
   CellComplex(){}
   ~CellComplex();

   //void emptyTrash();
   
   // restore this cell complex to its original state
   void restoreComplex();
     
   // get the number of certain dimensional cells
   int getSize(int dim){ return _cells[dim].size(); }
   int getOrgSize(int dim){ return _ocells[dim].size(); }
   
   int getDim() {return _dim; } 
   
   bool simplicial() { return _simplicial; }
   
   std::set<Cell*, Less_Cell> getCells(int dim){ return _cells[dim]; }
   std::set<Cell*, Less_Cell> getOrgCells(int dim){ return _ocells[dim]; }
   
   // iterator for the cells of same dimension
   typedef std::set<Cell*, Less_Cell>::iterator citer;
   
   // iterators to the first and last cells of certain dimension
   citer firstCell(int dim) {return _cells[dim].begin(); }
   citer lastCell(int dim) {return _cells[dim].end(); }
   citer firstOrgCell(int dim) {return _ocells[dim].begin(); }
   citer lastOrgCell(int dim) {return _ocells[dim].end(); }
   
   
   // true if cell complex has given cell
   bool hasCell(Cell* cell, bool org=false); 
   
   // check whether two cells both belong to subdomain or if neither one does
   bool inSameDomain(Cell* c1, Cell* c2) const { return 
       ( (!c1->inSubdomain() && !c2->inSubdomain()) || (c1->inSubdomain() && c2->inSubdomain()) ); }
   
   // reduction of this cell complex
   // removes reduction pairs of cell of dimension dim and dim-1
   int reduction(int dim, int omitted=0);
     
   // useful functions for (co)reduction of cell complex
   int reduceComplex();
   int coreduceComplex();
   
   // remove cells in subdomain from this cell complex
   void removeSubdomain();
      
   // print the vertices of cells of certain dimension
   void printComplex(int dim);
   
   // write this cell complex in 2.0 MSH ASCII format
   // for debugging only
   //int writeComplexMSH(const std::string &name); 
   
   // Cell combining for reduction and coreduction
   int combine(int dim);
   int cocombine(int dim);
   
   // Compute betti numbers of this cell complex
   void computeBettiNumbers();
   int getBettiNumber(int i) { if(i > -1 && i < 4) return _betti[i]; else return 0; }
   
   // check whether all boundary cells of a cell has this cell as coboundary cell and vice versa
   // also check whether all (co)boundary cells of a cell belong to this cell complex
   bool checkCoherence();
   
   int eulerCharacteristic(){ return getSize(0) - getSize(1) + getSize(2) - getSize(3);}
   void printEuler(){ printf("Euler characteristic: %d. \n", eulerCharacteristic()); }
   
   int getNumOmitted() { return _store.size(); };
   std::set<Cell*, Less_Cell> getOmitted(int i) { return _store.at(i); }  
   
   // change roles of boundaries and coboundaries of the cells in this cell complex
   // equivalent to transposing boundary operator matrices
   void makeDualComplex();
};

#endif

#endif
