// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.

#ifndef _CELLCOMPLEX_H_
#define _CELLCOMPLEX_H_

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

// Abstract class representing a cell of a cell complex.
class Cell
{  
  protected:
   
   // cell dimension
   int _dim;
   // maximum number of lower dimensional cells on the boundary of this cell
   int _bdMaxSize;
   // maximum number of higher dimensional cells on the coboundary of this cell
   int _cbdMaxSize;

   int _bdSize;
   int _cbdSize;
   
   // whether this cell belongs to a subdomain
   // used in relative homology computation
   bool _inSubdomain;
   
  public:
   Cell(){}
   virtual ~Cell(){}
   
   virtual int getDim() const { return _dim; };
   //virtual int getTag() const { return _tag; };
   
   // get the number of vertices this cell has
   virtual int getNumVertices() const = 0; //{return _vertices.size();}
   
   virtual int getVertex(int vertex) const = 0; //{return _vertices.at(vertex);}
   virtual std::vector<int> getVertexVector() const = 0;
   
   // returns 1 or -1 if lower dimensional cell tau is on the boundary of this cell
   // otherwise returns 0
   // implementation will vary depending on cell type
   virtual int kappa(Cell* tau) const = 0;
   
   // true if this cell has given vertex
   virtual bool hasVertex(int vertex) const = 0;
   
   virtual unsigned int getBdMaxSize() const { return _bdMaxSize; };
   virtual unsigned int getCbdMaxSize() const { return _cbdMaxSize; };

   virtual int getBdSize() { return _bdSize; }
   virtual void setBdSize(int size) { _bdSize = size; }
   virtual int getCbdSize() { return _cbdSize; }
   virtual void setCbdSize(int size) { _cbdSize = size; }
   
   virtual bool inSubdomain() const { return _inSubdomain; }
   
   // print cell vertices
   virtual void printCell() const = 0;
   
   // return the coordinates of this cell (only used on zero-cells if anywhere)
   virtual inline double x() const { return 0; }
   virtual inline double y() const { return 0; }
   virtual inline double z() const { return 0; }
   
   bool operator==(const Cell* c2){
     if(this->getNumVertices() != c2->getNumVertices()){
       return false;
     }
     for(int i=0; i < this->getNumVertices();i++){
       if(this->getVertex(i) != c2->getVertex(i)){
         return false;
       }
     }
     return true;
   }
   
   bool operator<(const Cell* c2) const {
     if(this->getNumVertices() != c2->getNumVertices()){
       return (this->getNumVertices() < c2->getNumVertices());
     }
     for(int i=0; i < this->getNumVertices();i++){
       if(this->getVertex(i) < c2->getVertex(i)){
         return true;
       }
     }
     return false;
   }
   
   
   
};

// Simplicial cell type.
class Simplex : public Cell
{ 
   
 public:
   Simplex(){
     _cbdSize = 1000; // big number
     _bdSize = 1000;
   }
   virtual ~Simplex(){}  
  
   // kappa for simplices
   // checks whether lower dimensional simplex tau is on the boundary of this cell
   virtual int kappa(Cell* tau) const; 
   
};

// Zero simplex cell type.
class ZeroSimplex : public Simplex
{
 private:
   // number of the vertex
   // same as the corresponding vertex in the finite element mesh
   int _v;
   // coordinates of this zero simplex, if needed
   double _x, _y, _z;
 public:
   
   ZeroSimplex(int vertex, bool subdomain=false, double x=0, double y=0, double z=0) : Simplex(){
     _v = vertex;
     _dim = 0;
     _bdMaxSize = 0;
     _cbdMaxSize = 1000; // big number
     _x = x;
     _y = y;
     _z = z;
     _inSubdomain = subdomain;
   }
   
   virtual ~ZeroSimplex(){}
   
   virtual int getDim() const { return 0; }
   virtual int getNumVertices() const { return 1; }
   virtual int getVertex(int vertex) const {return _v; }
   virtual bool hasVertex(int vertex) const {return (_v == vertex); }
   
   virtual std::vector<int> getVertexVector() const { return std::vector<int>(1,_v); }

   virtual inline double x() const { return _x; }
   virtual inline double y() const { return _y; }
   virtual inline double z() const { return _z; }
   
   virtual void printCell()const { printf("Vertices: %d\n", _v); }
   
};

// One simplex cell type.
class OneSimplex : public Simplex
{
  private:
   // numbers of the vertices of this simplex
   // same as the corresponding vertices in the finite element mesh
   int _v[2];
  public:
   
   OneSimplex(std::vector<int> vertices, bool subdomain=false) : Simplex(){
     sort(vertices.begin(), vertices.end());
     _v[0] = vertices.at(0);
     _v[1] = vertices.at(1);
     _dim = 1;
     _bdMaxSize = 2;
     _cbdMaxSize = 1000;
     _inSubdomain = subdomain;
   }
   
   // constructor for the dummy one simplex
   // used to find another definite one simplex from the cell complex
   // first vertex gives the lower bound from where to look
   OneSimplex(int vertex, int dummy){
     _v[0] = vertex;
     _v[1] = dummy;
   }
   
   virtual ~OneSimplex(){}
   
   virtual int getDim() const { return 1; }
   virtual int getNumVertices() const { return 2; }
   virtual int getVertex(int vertex) const {return _v[vertex]; }
   virtual bool hasVertex(int vertex) const {return (_v[0] == vertex || _v[1] == vertex); }
   
   virtual std::vector<int> getVertexVector() const { 
     return std::vector<int>(_v, _v + sizeof(_v)/sizeof(int) ); }
   
   virtual void printCell() const { printf("Vertices: %d %d\n", _v[0], _v[1]); }
};

// Two simplex cell type.
class TwoSimplex : public Simplex
{
  private:
   // numbers of the vertices of this simplex
   // same as the corresponding vertices in the finite element mesh
   int _v[3];
  public:
   
   TwoSimplex(std::vector<int> vertices, bool subdomain=false) : Simplex(){
     sort(vertices.begin(), vertices.end());
     _v[0] = vertices.at(0);
     _v[1] = vertices.at(1);
     _v[2] = vertices.at(2);
     _dim = 2;
     _bdMaxSize = 3;
     _cbdMaxSize = 2;
     _inSubdomain = subdomain;
   }
   // constructor for the dummy one simplex
   TwoSimplex(int vertex, int dummy){
     _v[0] = vertex;
     _v[1] = dummy;
     _v[2] = dummy;
   }
   
   virtual ~TwoSimplex(){}
   
   virtual int getDim() const { return 2; }
   virtual int getNumVertices() const { return 3; }
   virtual int getVertex(int vertex) const {return _v[vertex]; }
   virtual bool hasVertex(int vertex) const {return 
       (_v[0] == vertex || _v[1] == vertex || _v[2] == vertex); }
   virtual std::vector<int> getVertexVector() const { 
     return std::vector<int>(_v, _v + sizeof(_v)/sizeof(int) ); }
   
   virtual void printCell() const { printf("Vertices: %d %d %d\n", _v[0], _v[1], _v[2]); }
};

// Three simplex cell type.
class ThreeSimplex : public Simplex
{
  private:
   // numbers of the vertices of this simplex
   // same as the corresponding vertices in the finite element mesh
   int _v[4];
  public:
   
   ThreeSimplex(std::vector<int> vertices, bool subdomain=false) : Simplex(){
     sort(vertices.begin(), vertices.end());
     _v[0] = vertices.at(0);
     _v[1] = vertices.at(1);
     _v[2] = vertices.at(2);
     _v[3] = vertices.at(3);
     _dim = 3;
     _bdMaxSize = 4;
     _cbdMaxSize = 0;
     _inSubdomain = subdomain;
   }
   // constructor for the dummy one simplex
   ThreeSimplex(int vertex, int dummy){
     _v[0] = vertex;
     _v[1] = dummy;
     _v[2] = dummy;
     _v[3] = dummy;
   }
   
   virtual ~ThreeSimplex(){}
   
   virtual int getDim() const { return 3; }
   virtual int getNumVertices() const { return 4; }
   virtual int getVertex(int vertex) const {return _v[vertex]; }
   virtual bool hasVertex(int vertex) const {return 
       (_v[0] == vertex || _v[1] == vertex || _v[2] == vertex || _v[3] == vertex); }
   virtual std::vector<int> getVertexVector() const { 
     return std::vector<int>(_v, _v + sizeof(_v)/sizeof(int) ); }
   
   virtual void printCell() const { printf("Vertices: %d %d %d %d\n", _v[0], _v[1], _v[2], _v[3]); }
};

// Ordering for the cells.
class Less_Cell{
  public:
   bool operator()(const Cell* c1, const Cell* c2) const {
     
     // subcomplex cells in the end
     //if(c1->inSubdomain() != c2->inSubdomain()){
     //  if(c1->inSubdomain()) return false;
     //  else return true;
     //}
      
     // cells with fever vertices first
     if(c1->getNumVertices() != c2->getNumVertices()){
       return (c1->getNumVertices() < c2->getNumVertices());
     }
          
     // "natural number" -like ordering (the number of a vertice corresponds a digit)
     for(int i=0; i < c1->getNumVertices();i++){
       if(c1->getVertex(i) < c2->getVertex(i)) return true;
       else if (c1->getVertex(i) > c2->getVertex(i)) return false;
     }
     return false;
   }
};

// Ordering for the finite element mesh vertices.
class Less_MVertex{
  public:
   bool operator()(const MVertex* v1, const MVertex* v2) const {
     return (v1->getNum() < v2->getNum());
   }
};

// A class representing a cell complex made out of a finite element mesh.
class CellComplex
{
 private:
   
   // the domain in the model which this cell complex covers
   std::vector<GEntity*> _domain;
   // a subdomain of the given domain
   // used in relative homology computation, may be empty
   std::vector<GEntity*> _subdomain;
   
   // sorted containers of unique cells in this cell complex 
   // one for each dimension
   std::set<Cell*, Less_Cell>  _cells[4];
   
  public:
   // iterator for the cells of same dimension
   typedef std::set<Cell*, Less_Cell>::iterator citer;
   
  protected: 
   // enqueue cells in queue if they are not there already
   virtual void enqueueCells(std::vector<Cell*>& cells, 
                             std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset);
   virtual void enqueueCellsIt(std::vector< std::set<Cell*, Less_Cell>::iterator >& cells,
                               std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset);
     
   // remove cell from the queue set
   virtual void removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset);
   
   // get all the finite element mesh vertices in the domain of this cell complex
   virtual void getDomainVertices(std::set<MVertex*, Less_MVertex>& domainVertices, 
                                  bool subdomain);
   
   // insert cells into this cell complex
   virtual void insertCells(bool subdomain);
   
  public: 
   CellComplex(  std::vector<GEntity*> domain, std::vector<GEntity*> subdomain, std::set<Cell*, Less_Cell> cells ) {
     _domain = domain;
     _subdomain = subdomain;
     for(citer cit = cells.begin(); cit != cells.end(); cit++){
       Cell* cell = *cit;
       _cells[cell->getDim()].insert(cell);
     }
   }
   CellComplex( std::vector<GEntity*> domain, std::vector<GEntity*> subdomain );
   virtual ~CellComplex(){}
   
   // get the number of certain dimensional cells
   virtual int getSize(int dim){ return _cells[dim].size(); }
   
   virtual std::set<Cell*, Less_Cell> getCells(int dim){ return _cells[dim]; }
   
   // iterators to the first and last cells of certain dimension
   virtual citer firstCell(int dim) {return _cells[dim].begin(); }
   virtual citer lastCell(int dim) {return _cells[dim].end(); }
  
   // find a cell in this cell complex
   virtual std::set<Cell*, Less_Cell>::iterator findCell(int dim, std::vector<int>& vertices);
   virtual std::set<Cell*, Less_Cell>::iterator findCell(int dim, int vertex, int dummy=0);
   
   
   // kappa for two cells of this cell complex
   // implementation will vary depending on cell type
   virtual int kappa(Cell* sigma, Cell* tau) const { return sigma->kappa(tau); }
   
   // cells on the boundary of a cell
   virtual std::vector<Cell*> bd(Cell* sigma);
   virtual std::vector< std::set<Cell*, Less_Cell>::iterator > bdIt(Cell* sigma);
   // cells on the coboundary of a cell
   virtual std::vector<Cell*> cbd(Cell* tau);
   virtual std::vector< std::set<Cell*, Less_Cell>::iterator > cbdIt(Cell* tau);
   
   // remove a cell from this cell complex
   virtual void removeCell(Cell* cell, bool deleteCell=true);
   virtual void removeCellIt(std::set<Cell*, Less_Cell>::iterator cell);
   
   virtual void insertCell(Cell* cell);
   
   // check whether two cells both belong to subdomain or if neither one does
   virtual bool inSameDomain(Cell* c1, Cell* c2) const { return 
       ( (!c1->inSubdomain() && !c2->inSubdomain()) || (c1->inSubdomain() && c2->inSubdomain()) ); }
   
   // coreduction of this cell complex
   // removes corection pairs of cells of dimension dim and dim+1
   virtual int coreduction(int dim, bool deleteCells=true);
   // stores removed cells
   virtual int coreduction(int dim, std::set<Cell*, Less_Cell>& removedCells);
   // reduction of this cell complex
   // removes reduction pairs of cell of dimension dim and dim-1
   virtual int reduction(int dim, bool deleteCells=true);
   
   // useful functions for (co)reduction of cell complex
   virtual void reduceComplex();
   // coreduction up to generators of dimension generatorDim
   virtual void coreduceComplex(int generatorDim=3);
   
   // stores cells removed after removal of generatos of dimension generatorDim
   virtual void coreduceComplex(int generatorDim, std::set<Cell*, Less_Cell>& removedCells);
  
   
   // queued coreduction presented in Mrozek's paper
   // slower, but produces cleaner result
   virtual int coreductionMrozek(Cell* generator);
   
   // print the vertices of cells of certain dimension
   virtual void printComplex(int dim, bool subcomplex);
   
   // write this cell complex in legacy .msh format
   virtual int writeComplexMSH(const std::string &name); 
   
   
};

#endif
