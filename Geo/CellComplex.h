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
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "GModel.h"
#include "GEntity.h"
#include "GRegion.h"
#include "GFace.h"
#include "GVertex.h"

#if defined(HAVE_KBIPACK)

// Abstract class representing an elemtary cell of a cell complex.
class Cell
{  
  protected:
   
   // cell dimension
   int _dim;
   
   // whether this cell belongs to a subdomain
   // used in relative homology computation
   bool _inSubdomain;
   
   // whether this cell belongs to the boundary of a cell complex
   bool _onDomainBoundary;
   
   // whether this cell a combinded cell of elemetary cells
   bool _combined; 
   
   // unique tag for each cell
   int _tag;
   int _index; 
   
   // cells on the boundary and on the coboundary of thhis cell
   std::list< std::pair<int, Cell*> > _boundary;
   std::list< std::pair<int, Cell*> > _coboundary;
   
   
  public:
   Cell(){}
   virtual ~Cell(){}
   
   virtual int getDim() const { return _dim; };
   virtual int getTag() const { return _tag; };
   virtual void setTag(int tag) { _tag = tag; };
   virtual int getIndex() const { return _index; };
   virtual void setIndex(int index) { _index = index; };
   virtual int getNum() { return -1; }
   
   // get the number of vertices this cell has
   virtual int getNumVertices() const = 0;
   virtual MVertex* getVertex(int vertex) const = 0; //{return _vertices.at(vertex);}
   virtual int getSortedVertex(int vertex) const = 0; 
   virtual std::vector<MVertex*> getVertexVector() const = 0;
   
   // returns 1 or -1 if lower dimensional cell tau is on the boundary of this cell
   // otherwise returns 0
   // implementation will vary depending on cell type
   virtual int kappa(Cell* tau) const = 0;
   
   // true if this cell has given vertex
   virtual bool hasVertex(int vertex) const = 0;
  
   virtual int getBoundarySize() { return _boundary.size(); }
   virtual int getCoboundarySize() { return _coboundary.size(); }
   
   virtual std::list< std::pair<int, Cell*> > getOrientedBoundary() { return _boundary; }
   virtual std::list< Cell* > getBoundary() {
     std::list<Cell*> boundary;
     for( std::list< std::pair<int, Cell*> >::iterator it= _boundary.begin();it!= _boundary.end();it++){
       Cell* cell = (*it).second;
       boundary.push_back(cell);
     }
     return boundary;
   }
   virtual std::list<std::pair<int, Cell*> >getOrientedCoboundary() { return _coboundary; }
   virtual std::list< Cell* > getCoboundary() {
     std::list<Cell*> coboundary;
     for( std::list< std::pair<int, Cell*> >::iterator it= _coboundary.begin();it!= _coboundary.end();it++){
       Cell* cell = (*it).second;
       coboundary.push_back(cell);
     }
     return coboundary;
   }
   
   virtual void addBoundaryCell(int orientation, Cell* cell) { _boundary.push_back( std::make_pair(orientation, cell)); }
   virtual void addCoboundaryCell(int orientation, Cell* cell) { _coboundary.push_back( std::make_pair(orientation, cell)); }
   
   virtual void removeBoundaryCell(Cell* cell) {
     for(std::list< std::pair<int, Cell*> >::iterator it = _boundary.begin(); it != _boundary.end(); it++){
       Cell* cell2 = (*it).second;
       if(*cell2 == *cell) { _boundary.erase(it); break; }
     }
   }
   virtual void removeCoboundaryCell(Cell* cell) { 
     for(std::list< std::pair<int, Cell*> >::iterator it = _coboundary.begin(); it != _coboundary.end(); it++){
       Cell* cell2 = (*it).second;
       if(*cell2 == *cell) { _coboundary.erase(it); break; }
     }
   }
   
   virtual void clearBoundary() { _boundary.clear(); }
   virtual void clearCoboundary() { _coboundary.clear(); }
   
   virtual void makeDualCell(){ 
     std::list< std::pair<int, Cell*> > temp = _boundary;
     _boundary = _coboundary;
     _coboundary = temp;
     _dim = 3-_dim;
     
   }
   
   virtual void printBoundary() {  
     for(std::list< std::pair<int, Cell*> >::iterator it = _boundary.begin(); it != _boundary.end(); it++){
       printf("Boundary cell orientation: %d ", (*it).first);
       Cell* cell2 = (*it).second;
       cell2->printCell();
     }
   }
   
   
   virtual bool inSubdomain() const { return _inSubdomain; }
   virtual void setInSubdomain(bool subdomain)  { _inSubdomain = subdomain; }
   
   virtual bool onDomainBoundary() const { return _onDomainBoundary; }
   virtual void setOnDomainBoundary(bool domainboundary)  { _onDomainBoundary = domainboundary; }
   
   // print cell vertices
   virtual void printCell() const = 0;
   
   virtual int getNumFacets() const { return 0; }
   virtual void getFacetVertices(const int num, std::vector<MVertex*> &v) const {};
   
   virtual bool combined() { return _combined; }
   virtual std::list< std::pair<int, Cell*> > getCells() {  std::list< std::pair<int, Cell*> >cells; cells.push_back( std::make_pair(1, this)); return cells; }
   virtual int getNumCells() {return 1;}
   
   bool operator==(const Cell& c2){
     if(this->getNumVertices() != c2.getNumVertices()){
       return false;
     }
     for(int i=0; i < this->getNumVertices();i++){
       if(this->getSortedVertex(i) != c2.getSortedVertex(i)){
         return false;
       }
     }
     return true;
   }
   
   bool operator<(const Cell& c2) const {
     if(this->getNumVertices() != c2.getNumVertices()){
       return (this->getNumVertices() < c2.getNumVertices());
     }
     for(int i=0; i < this->getNumVertices();i++){
       if(this->getSortedVertex(i) < c2.getSortedVertex(i)) return true;
       else if (this->getSortedVertex(i) > c2.getSortedVertex(i)) return false;
     }
     return false;
   }
   
   
};


// Simplicial cell type.
class Simplex : public Cell
{ 
   
 public:
   Simplex() : Cell() {
     _combined = false;
   }
   ~Simplex(){}  
  
   // kappa for simplices
   // checks whether lower dimensional simplex tau is on the boundary of this cell
   virtual int kappa(Cell* tau) const; 
   
};

// Zero simplex cell type.
class ZeroSimplex : public Simplex, public MPoint
{
 private:

 public:
   
   ZeroSimplex(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MPoint(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
     }
   ~ZeroSimplex(){}
   
   int getDim() const { return 0; }
   int getNum() { return MPoint::getNum(); }
   int getNumVertices() const { return 1; }
   MVertex* getVertex(int vertex) const {return _v[0]; }
   int getSortedVertex(int vertex) const {return _v[0]->getNum(); }
   bool hasVertex(int vertex) const {return (_v[0]->getNum() == vertex); }
   
   std::vector<MVertex*> getVertexVector() const { std::vector<MVertex*> v; v.push_back(_v[0]); return v; }
   std::vector<int> getSortedVertexVector() const { return std::vector<int>(1,_v[0]->getNum()); }
   
   void printCell() const { printf("Vertices: %d, in subdomain: %d \n", _v[0]->getNum(), _inSubdomain); }
   
};

// One simplex cell type.
class OneSimplex : public Simplex, public MLine
{
  private:
   int _vs[2];
  public:
   

   OneSimplex(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MLine(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       std::sort(_vs, _vs+2);
     }
   
   ~OneSimplex(){}
   
   int getDim() const { return 1; }
   int getNum() { return MLine::getNum(); }
   int getNumVertices() const { return 2; }
   int getNumFacets() const {  return 2; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex); }
   
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); 
   }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     v.resize(1);
     v[0] = _v[num];
   }
   
   //int kappa(Cell* tau) const;
   
   void printCell() const { printf("Vertices: %d %d, in subdomain: %d \n", _v[0]->getNum(), _v[1]->getNum(), _inSubdomain); }
};

// Two simplex cell type.
class TwoSimplex : public Simplex, public MTriangle
{
  private:

   int _vs[3];
   
  public:

   TwoSimplex(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MTriangle(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       _vs[2] = v.at(2)->getNum();
       std::sort(_vs, _vs+3);
     }
   
   ~TwoSimplex(){}
   
   int getDim() const { return 2; }
   int getNum() { return MTriangle::getNum(); }
   int getNumVertices() const { return 3; }
   int getNumFacets() const { return 3; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return 
       (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex || _v[2]->getNum() == vertex); }
   
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); 
   }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     MTriangle::getEdgeVertices(num, v);
   }
   
   void printCell() const { printf("Vertices: %d %d %d, in subdomain: %d\n", _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _inSubdomain); }
};

// Three simplex cell type.
class ThreeSimplex : public Simplex, public MTetrahedron
{
  private:
   int _vs[4];
      
  public:
   ThreeSimplex(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MTetrahedron(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       _vs[2] = v.at(2)->getNum();
       _vs[3] = v.at(3)->getNum();
       std::sort(_vs, _vs+4);
     }
   
   ~ThreeSimplex(){}
   
   int getDim() const { return 3; }
   int getNum() { return MTetrahedron::getNum(); }
   int getNumVertices() const { return 4; }
   int getNumFacets() const { return 4; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return 
       (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex || _v[2]->getNum() == vertex || _v[3]->getNum() == vertex); }
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     MTetrahedron::getFaceVertices(num, v);
   }
   
   virtual void printCell() const { printf("Vertices: %d %d %d %d, in subdomain: %d \n", _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _v[3]->getNum(), _inSubdomain); }
};

// Ordering for the cells.
class Less_Cell{
  public:
   bool operator()(const Cell* c1, const Cell* c2) const {
     
     // cells with fever vertices first
     
     if(c1->getNumVertices() != c2->getNumVertices()){
       return (c1->getNumVertices() < c2->getNumVertices());
     }
     
     
     
     // "natural number" -like ordering (the number of a vertice corresponds a digit)
     
     for(int i=0; i < c1->getNumVertices();i++){
       if(c1->getSortedVertex(i) < c2->getSortedVertex(i)) return true;
       else if (c1->getSortedVertex(i) > c2->getSortedVertex(i)) return false;
     }
          
     return false;
   }
};


class Equal_Cell{
  public:
   bool operator ()(const Cell* c1, const Cell* c2){
     if(c1->getNumVertices() != c2->getNumVertices()){
       return false;
     }
     for(int i=0; i < c1->getNumVertices();i++){
       if(c1->getSortedVertex(i) != c2->getSortedVertex(i)){
         return false;
       }
     }
     return true;
   }
};


// Ordering for the finite element mesh vertices.
class Less_MVertex{
  public:
   bool operator()(const MVertex* v1, const MVertex* v2) const {
     return (v1->getNum() < v2->getNum());
   }
};

class CombinedCell : public Cell{
 
  private:
   std::vector<MVertex*> _v;
   std::vector<int> _vs;
   std::list< std::pair<int, Cell*> > _cells;
   
  public:
   
   CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co=false) : Cell(){
     _tag = c1->getTag();
     _dim = c1->getDim();
     _inSubdomain = c1->inSubdomain();
     _onDomainBoundary = c1->onDomainBoundary();
     _combined = true;
     
     _v = c1->getVertexVector();
     for(int i = 0; i < c2->getNumVertices(); i++){
       if(!this->hasVertex(c2->getVertex(i)->getNum())) _v.push_back(c2->getVertex(i));
     }
     
     for(int i = 0; i < _v.size(); i++) _vs.push_back(_v.at(i)->getNum());
     std::sort(_vs.begin(), _vs.end());
     
     _cells = c1->getCells();
     std::list< std::pair<int, Cell*> > c2Cells = c2->getCells();
     for(std::list< std::pair<int, Cell*> >::iterator it = c2Cells.begin(); it != c2Cells.end(); it++){
       if(!orMatch) (*it).first = -1*(*it).first;
       _cells.push_back(*it);
     }
     
     _boundary = c1->getOrientedBoundary();
     std::list< std::pair<int, Cell*> > c2Boundary = c2->getOrientedBoundary();
     for(std::list< std::pair<int, Cell*> >::iterator it = c2Boundary.begin(); it != c2Boundary.end(); it++){
       if(!orMatch) (*it).first = -1*(*it).first;
       Cell* cell = (*it).second;
       if(co){
         bool old = false;
         for(std::list< std::pair<int, Cell* > >::iterator it2 = _boundary.begin(); it2 != _boundary.end(); it2++){
           Cell* cell2 = (*it2).second;
           if(*cell2 == *cell) old = true;
         }
         if(!old) _boundary.push_back(*it);
       }
       else _boundary.push_back(*it);
     }
     
     _coboundary = c1->getOrientedCoboundary();
     std::list< std::pair<int, Cell*> > c2Coboundary = c2->getOrientedCoboundary();
     for(std::list< std::pair<int, Cell* > >::iterator it = c2Coboundary.begin(); it != c2Coboundary.end(); it++){
       if(!orMatch) (*it).first = -1*(*it).first;
       Cell* cell = (*it).second;
       if(!co){
         bool old = false;
         for(std::list< std::pair<int, Cell* > >::iterator it2 = _coboundary.begin(); it2 != _coboundary.end(); it2++){
           Cell* cell2 = (*it2).second;
           if(*cell2 == *cell) old = true;
         }
         if(!old) _coboundary.push_back(*it);
       }
       else _coboundary.push_back(*it);
     }
     
   }
  
   ~CombinedCell(){} 
   
   int getNumVertices() const { return _v.size(); } 
   MVertex* getVertex(int vertex) const { return _v.at(vertex); }
   int getSortedVertex(int vertex) const { return _vs.at(vertex); }
   std::vector<MVertex*> getVertexVector() const { return _v; }
   
   int kappa(Cell* tau) const { return 0; }
   
   // true if this cell has given vertex
   bool hasVertex(int vertex) const {
     for(int i = 0; i < _v.size(); i++){
       if(_v.at(i)->getNum() == vertex) return true;
     }
     return false;
   }
   
   virtual void printCell() const {
     printf("Vertices: ");
     for(int i = 0; i < this->getNumVertices(); i++){
       printf("%d ", this->getVertex(i)->getNum());
     }
     printf(", in subdomain: %d\n", _inSubdomain);
   }
   
   std::list< std::pair<int, Cell*> > getCells() { return _cells; }
   int getNumCells() {return _cells.size();}
      
   
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
   
   std::vector<GEntity*> _boundary;
   
   std::set<MVertex*, Less_MVertex> _domainVertices;
   
   // sorted containers of unique cells in this cell complex 
   // one for each dimension
   std::set<Cell*, Less_Cell>  _cells[4];
   
   std::vector<Cell*> _trash;
   
   //std::set<Cell*, Less_Cell>  _originalCells[4];
   
   // Betti numbers of this cell complex (ranks of homology groups)
   int _betti[4];
   
   int _dim;
   
  public:
   // iterator for the cells of same dimension
   typedef std::set<Cell*, Less_Cell>::iterator citer;
   
  protected: 
   // enqueue cells in queue if they are not there already
   void enqueueCells(std::list<Cell*>& cells, 
                             std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset);
   // remove cell from the queue set
   void removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset);
      
   // insert cells into this cell complex
   //virtual void insert_cells(bool subdomain, bool boundary);
   void insert_cells(bool subdomain, bool boundary);
   
  public: 
   CellComplex(  std::vector<GEntity*> domain, std::vector<GEntity*> subdomain, std::set<Cell*, Less_Cell> cells ) {
     _domain = domain;
     _subdomain = subdomain;
     for(citer cit = cells.begin(); cit != cells.end(); cit++){
       Cell* cell = *cit;
       _cells[cell->getDim()].insert(cell);
     }
   }
   /*
   CellComplex(CellComplex* cellComplex){
     
     _domain = cellComplex->_domain;
     _subdomain = cellComplex->_subdomain;
     _boundary = cellComplex->_boundary;
     _domainVertices = cellComplex->_domainVertices;
     
     for(int i = 0; i < 4; i++){
       _betti[i] = cellComplex->_betti[i];
       
       for(citer cit = cellComplex->_cells[i].begin(); cit != cellComplex->_cells[i].end(); cit++){
         Cell* cell = *cit;
         if(i == 0) _cells[i].insert(new ZeroSimplex(*cell));
         
       }
       
       _originalCells[i] = _cells[i];
     }
     
     _dim = cellComplex->_dim;
     
   }*/
   
   CellComplex( std::vector<GEntity*> domain, std::vector<GEntity*> subdomain );
   CellComplex(){}
   ~CellComplex(){ 
     for(int i = 0; i < _trash.size(); i++){
       Cell* cell = _trash.at(i);
       delete cell;
     }
   }

   
   // get the number of certain dimensional cells
   int getSize(int dim){ return _cells[dim].size(); }
   
   int getDim() {return _dim; } 
   
   std::set<Cell*, Less_Cell> getCells(int dim){ return _cells[dim]; }
      
   // iterators to the first and last cells of certain dimension
    citer firstCell(int dim) {return _cells[dim].begin(); }
    citer lastCell(int dim) {return _cells[dim].end(); }
  
   // kappa for two cells of this cell complex
   // implementation will vary depending on cell type
   inline int kappa(Cell* sigma, Cell* tau) const { return sigma->kappa(tau); }
   
   // remove a cell from this cell complex
   void removeCell(Cell* cell);
   void replaceCells(Cell* c1, Cell* c2, Cell* newCell, bool orMatch, bool co=false);
   
   
   void insertCell(Cell* cell);
   
   // check whether two cells both belong to subdomain or if neither one does
   bool inSameDomain(Cell* c1, Cell* c2) const { return 
       ( (!c1->inSubdomain() && !c2->inSubdomain()) || (c1->inSubdomain() && c2->inSubdomain()) ); }
   
   
   // reduction of this cell complex
   // removes reduction pairs of cell of dimension dim and dim-1
   int reduction(int dim);
   
   
   // useful functions for (co)reduction of cell complex
   int reduceComplex(bool omitHighdim = false);
   int coreduceComplex(bool omitlowDim = false);
   
   // queued coreduction presented in Mrozek's paper
   int coreduction(Cell* generator);
   
   // add every volume, face and edge its missing boundary cells
   // void repairComplex(int i=3);
   // change non-subdomain cells to be in subdomain, subdomain cells to not to be in subdomain
   void swapSubdomain();
   void removeSubdomain();
   
   
   // print the vertices of cells of certain dimension
   void printComplex(int dim);
   
   // write this cell complex in 2.0 MSH ASCII format
   int writeComplexMSH(const std::string &name); 
   
   int combine(int dim);
   int cocombine(int dim);
   
   void computeBettiNumbers();
   int getBettiNumber(int i) { if(i > -1 && i < 4) return _betti[i]; else return 0; }
   
   void makeDualComplex(){
     std::set<Cell*, Less_Cell> temp = _cells[0];
     _cells[0] = _cells[3];
     _cells[3] = temp;
     temp = _cells[1];
     _cells[1] = _cells[2];
     _cells[2] = temp;
     
     for(int i = 0; i < 4; i++){
       for(citer cit = firstCell(i); cit != lastCell(i); cit++){
         Cell* cell = *cit;
         cell->makeDualCell();
       }
     }
   }
   
};

#endif

#endif
