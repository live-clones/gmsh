// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.

#ifndef _CELLCOMPLEX_H_
#define _CELLCOMPLEX_H_

#include "GmshConfig.h"

#if defined(HAVE_KBIPACK)

#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include "MElement.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTetrahedron.h"
#include "GModel.h"
#include "GEntity.h"
#include "GRegion.h"
#include "GFace.h"
#include "GVertex.h"

class Cell;

// Ordering of the cells
class Less_Cell{
  public:
   bool operator()(const Cell* c1, const Cell* c2) const;
};

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
   
   bool _immune;
      
   // cells on the boundary and on the coboundary of this cell
   std::map< Cell*, int, Less_Cell > _boundary;
   std::map< Cell*, int, Less_Cell > _coboundary;
   int _bdSize;
   int _cbdSize;
   
   // original boundary and coboundary before the reduction of the cell complex
   std::map<Cell*, int, Less_Cell > _obd;
   std::map<Cell*, int, Less_Cell > _ocbd;
   
  public:
   Cell(){
     _bdSize = 0;
     _cbdSize = 0;
     _combined = false;
     _index = 0;
     _immune = false;
   }
   virtual ~Cell(){}
   
   virtual int getDim() const { return _dim; };
   virtual int getTag() const { return _tag; };
   virtual void setTag(int tag) { _tag = tag; };
   virtual int getIndex() const { return _index; };
   virtual void setIndex(int index) { _index = index; };
   virtual int getNum() { return -1; }
   virtual void setImmune(bool immune) { _immune = immune; };
   virtual bool getImmune() const { return _immune; };
   
   // get the number of vertices this cell has
   virtual int getNumVertices() const = 0;
   virtual MVertex* getVertex(int vertex) const = 0; //{return _vertices.at(vertex);}
   virtual int getSortedVertex(int vertex) const = 0; 
   virtual std::vector<MVertex*> getVertexVector() const = 0;
   
   virtual void restoreCell(){
     _boundary = _obd;
     _coboundary = _ocbd;
     _bdSize = _boundary.size();
     _cbdSize = _coboundary.size();
     _combined = false;
     _index = 0;
     _immune = false;
     
   }
   
   // returns 1 or -1 if lower dimensional cell tau is on the boundary of this cell
   // otherwise returns 0
   // implementation will vary depending on cell type
   //virtual int kappa(Cell* tau) const = 0;
   
   // true if this cell has given vertex
   virtual bool hasVertex(int vertex) const = 0;

   // (co)boundary cell iterator
   typedef std::map<Cell*, int, Less_Cell>::iterator biter;
   
   virtual int getBoundarySize() { return _bdSize; }
   virtual int getCoboundarySize() { return _cbdSize; }
   
   virtual std::map<Cell*, int, Less_Cell > getOrientedBoundary() { return _boundary; }
   virtual std::list< Cell* > getBoundary() {
     std::list<Cell*> boundary;
     for( biter it= _boundary.begin(); it != _boundary.end();it++){
       Cell* cell = (*it).first;
       boundary.push_back(cell);
     }
     return boundary;
   }
   virtual std::map<Cell*, int, Less_Cell > getOrientedCoboundary() { return _coboundary; }
   virtual std::list< Cell* > getCoboundary() {
     std::list<Cell*> coboundary;
     for( biter it= _coboundary.begin();it!= _coboundary.end();it++){
       Cell* cell = (*it).first;
       coboundary.push_back(cell);
     }
     return coboundary;
   }
   
   virtual bool addBoundaryCell(int orientation, Cell* cell) {
     _bdSize++;
     biter it = _boundary.find(cell);
     if(it != _boundary.end()){
       (*it).second = (*it).second + orientation;
       if((*it).second == 0) {
         _boundary.erase(it); _bdSize--;
         (*it).first->removeCoboundaryCell(this,false);
         return false;
       }
       return true;
     }
     _boundary.insert( std::make_pair(cell, orientation ) );
     /*
     for(std::list< std::pair<int, Cell*> >::iterator it = _boundary.begin(); it != _boundary.end(); it++){
       Cell* cell2 = (*it).second;
       if(*cell2 == *cell) {
         (*it).first = (*it).first + orientation;
         if((*it).first == 0) { 
           _boundary.erase(it); _bdSize--;
           cell2->removeCoboundaryCell(this,false);
           return false;
         }
         return true;
       }
     }
     _boundary.push_back( std::make_pair(orientation, cell ) );
     */
     return true;
   }
   
   virtual bool addCoboundaryCell(int orientation, Cell* cell) {
     _cbdSize++;
     biter it = _coboundary.find(cell);
     if(it != _coboundary.end()){
       (*it).second = (*it).second + orientation;
       if((*it).second == 0) {
         _coboundary.erase(it); _cbdSize--;
         (*it).first->removeBoundaryCell(this,false);
         return false;
       }
       return true;
     }
     _coboundary.insert( std::make_pair(cell, orientation ) );
     return true;
   }
   
   virtual int removeBoundaryCell(Cell* cell, bool other=true) {
     biter it = _boundary.find(cell);
     if(it != _boundary.end()){
       _boundary.erase(it);
       if(other) (*it).first->removeCoboundaryCell(this, false);
       _bdSize--;
       return (*it).second;
     }
       
     /*
     for(std::list< std::pair<int, Cell*> >::iterator it = _boundary.begin(); it != _boundary.end(); it++){
       Cell* cell2 = (*it).second;
       int ori = (*it).first;
       if(*cell2 == *cell) {
         _boundary.erase(it); 
         if(other) cell2->removeCoboundaryCell(this, false); 
         _bdSize--;
         return ori;
       }
     }
     */
      
     return 0;
   }
   virtual int removeCoboundaryCell(Cell* cell, bool other=true) {
     biter it = _coboundary.find(cell);
     if(it != _coboundary.end()){
       _coboundary.erase(it);
       if(other) (*it).first->removeBoundaryCell(this, false);
       _cbdSize--;
       return (*it).second;
     }
     return 0;
   }
   
   virtual bool hasBoundary(Cell* cell, bool org=false){
     if(!org){
       /*
       for(std::list< std::pair<int, Cell*> >::iterator it = _boundary.begin(); it != _boundary.end(); it++){
         Cell* cell2 = (*it).second;
         if(*cell2 == *cell) return true;
       }
       return false;
       */
       biter it = _boundary.find(cell);
       if(it != _boundary.end()) return true;
       return false;
     }
     else{
       biter it = _obd.find(cell);
       if(it != _obd.end()) return true;
       return false;
     }
   }
   virtual bool hasCoboundary(Cell* cell, bool org=false){
     if(!org){
       biter it = _coboundary.find(cell);
       if(it != _coboundary.end()) return true;
       return false;
     }
     else{
       biter it = _ocbd.find(cell);
       if(it != _ocbd.end()) return true;
       return false;
     } 
   }
   
   
   virtual void clearBoundary() { _boundary.clear(); }
   virtual void clearCoboundary() { _coboundary.clear(); }
   
   virtual void makeDualCell(){ 
     std::map<Cell*, int, Less_Cell > temp = _boundary;
     _boundary = _coboundary;
     _coboundary = temp;
     _dim = 3-_dim;
     
   }
   
   virtual void printBoundary() {  
     for(biter it = _boundary.begin(); it != _boundary.end(); it++){
       printf("Boundary cell orientation: %d ", (*it).second);
       Cell* cell2 = (*it).first;
       cell2->printCell();
     }
     if(_boundary.empty()) printf("Cell boundary is empty. \n");
   }
   virtual void printCoboundary() {
     for(biter it = _coboundary.begin(); it != _coboundary.end(); it++){
       printf("Coboundary cell orientation: %d, ", (*it).second);
       Cell* cell2 = (*it).first;
       cell2->printCell();
       if(_coboundary.empty()) printf("Cell coboundary is empty. \n");
     }
   }
   
   virtual void addOrgBdCell(int orientation, Cell* cell) { _obd.insert( std::make_pair(cell, orientation ) ); };
   virtual void addOrgCbdCell(int orientation, Cell* cell) { _ocbd.insert( std::make_pair(cell, orientation ) ); };
   virtual std::map<Cell*, int, Less_Cell > getOrgBd() { return _obd; }
   virtual std::map<Cell*, int, Less_Cell > getOrgCbd() { return _ocbd; }
   virtual void printOrgBd() {
     for(biter it = _obd.begin(); it != _obd.end(); it++){
       printf("Boundary cell orientation: %d ", (*it).second);
       Cell* cell2 = (*it).first;
       cell2->printCell();
     }
     if(_obd.empty()) printf("Cell boundary is empty. \n");
   }
   virtual void printOrgCbd() {
     for(biter it = _ocbd.begin(); it != _ocbd.end(); it++){
       printf("Coboundary cell orientation: %d, ", (*it).second);
       Cell* cell2 = (*it).first;
       cell2->printCell();
       if(_ocbd.empty()) printf("Cell coboundary is empty. \n");
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
   
   virtual bool isCombined() { return _combined; }
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
     
     //return (this->getTag() == c2.getTag());
     
     
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
     
     //return (this->getTag() < c2.getTag());
   }
   
   virtual int kappa(Cell* tau) const;
   
};


// Simplicial cell type.
class Simplex : public Cell
{ 
   
 public:
   Simplex() : Cell() {}
   ~Simplex(){}  
  
   // kappa for simplices
   // checks whether lower dimensional simplex tau is on the boundary of this cell
   //virtual int kappa(Cell* tau) const; 
   
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
   
   void printCell() const { printf("Cell dimension: %d, Vertices: %d, in subdomain: %d \n", getDim(), _v[0]->getNum(), _inSubdomain); }
   
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
   
   int kappa(Cell* tau) const;
   
   void printCell() const { printf("Cell dimension: %d, Vertices: %d %d, in subdomain: %d \n", getDim(), _v[0]->getNum(), _v[1]->getNum(), _inSubdomain); }
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
   
   void printCell() const { printf("Cell dimension: %d, Vertices: %d %d %d, in subdomain: %d\n", getDim(), _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _inSubdomain); }
};

// Quadrangle cell type.
class CQuadrangle : public Cell, public MQuadrangle
{
  private:

   int _vs[4];
   
  public:

   CQuadrangle(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MQuadrangle(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       _vs[2] = v.at(2)->getNum();
       _vs[3] = v.at(3)->getNum();
       std::sort(_vs, _vs+3);
     }
   
   ~CQuadrangle(){}
   
   int getDim() const { return 2; }
   int getNum() { return MQuadrangle::getNum(); }
   int getNumVertices() const { return 4; }
   int getNumFacets() const { return 4; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return 
       (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex || _v[2]->getNum() == vertex || _v[3]->getNum() == vertex); } 
   
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); 
   }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     MQuadrangle::getEdgeVertices(num, v);
   }
   
   void printCell() const { printf("Cell dimension: %d, Vertices: %d %d %d %d, in subdomain: %d\n", 
                                    getDim(), _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), 
                                    _v[3]->getNum(), _inSubdomain); }
};


// ThreeSimplex cell type.
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
   
   virtual void printCell() const { printf("Cell dimension: %d, Vertices: %d %d %d %d, in subdomain: %d \n", getDim(), _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _v[3]->getNum(), _inSubdomain); }
};

// Hexahedron cell type.
class CHexahedron : public Cell, public MHexahedron
{
  private:
   int _vs[8];
      
  public:
   CHexahedron(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MHexahedron(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       _vs[2] = v.at(2)->getNum();
       _vs[3] = v.at(3)->getNum();
       _vs[4] = v.at(4)->getNum();
       _vs[5] = v.at(5)->getNum();
       _vs[6] = v.at(6)->getNum();
       _vs[7] = v.at(7)->getNum();
       std::sort(_vs, _vs+8);
     }
   
   ~CHexahedron(){}
   
   int getDim() const { return 3; }
   int getNum() { return MHexahedron::getNum(); }
   int getNumVertices() const { return 8; }
   int getNumFacets() const { return 6; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return 
       (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex || _v[2]->getNum() == vertex || _v[3]->getNum() == vertex ||
        _v[4]->getNum() == vertex || _v[5]->getNum() == vertex || _v[6]->getNum() == vertex || _v[7]->getNum() == vertex ); }
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     MHexahedron::getFaceVertices(num, v);
   }
   
   virtual void printCell() const { printf("Cell dimension: %d, Vertices: %d %d %d %d %d %d %d %d, in subdomain: %d \n", getDim(), _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _v[3]->getNum(), _v[4]->getNum(), _v[5]->getNum(), _v[6]->getNum(), _v[7]->getNum(), _inSubdomain); }
};


// Prism cell type.
class CPrism : public Cell, public MPrism
{
  private:
   int _vs[6];
      
  public:
   CPrism(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MPrism(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       _vs[2] = v.at(2)->getNum();
       _vs[3] = v.at(3)->getNum();
       _vs[4] = v.at(4)->getNum();
       _vs[5] = v.at(5)->getNum();
       std::sort(_vs, _vs+6);
     }
   
   ~CPrism(){}
   
   int getDim() const { return 3; }
   int getNum() { return MPrism::getNum(); }
   int getNumVertices() const { return 6; }
   int getNumFacets() const { return 5; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return 
       (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex || _v[2]->getNum() == vertex || _v[3]->getNum() == vertex ||
       _v[4]->getNum() == vertex || _v[5]->getNum() == vertex); }
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     MPrism::getFaceVertices(num, v);
   }
   
   virtual void printCell() const { printf("Cell dimension: %d, Vertices: %d %d %d %d %d %d, in subdomain: %d \n", getDim(), _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _v[3]->getNum(), _v[4]->getNum(), _v[5]->getNum(),  _inSubdomain); }
};


// Pyramid cell type.
class CPyramid : public Cell, public MPyramid
{
  private:
   int _vs[5];
      
  public:
   CPyramid(std::vector<MVertex*> v, int tag=0, bool subdomain=false, bool boundary=false, int num=0, int part=0)
     : MPyramid(v, num, part){
       _tag = tag;
       _inSubdomain = subdomain;
       _onDomainBoundary = boundary;
       _vs[0] = v.at(0)->getNum();
       _vs[1] = v.at(1)->getNum();
       _vs[2] = v.at(2)->getNum();
       _vs[3] = v.at(3)->getNum();
       _vs[4] = v.at(4)->getNum();
       std::sort(_vs, _vs+5);
     }
   
   ~CPyramid(){}
   
   int getDim() const { return 3; }
   int getNum() { return MPyramid::getNum(); }
   int getNumVertices() const { return 5; }
   int getNumFacets() const { return 5; }
   MVertex* getVertex(int vertex) const {return _v[vertex]; }
   int getSortedVertex(int vertex) const {return _vs[vertex]; }
   bool hasVertex(int vertex) const {return 
       (_v[0]->getNum() == vertex || _v[1]->getNum() == vertex || _v[2]->getNum() == vertex || _v[3]->getNum() == vertex ||
        _v[4]->getNum() == vertex); }
   std::vector<MVertex*> getVertexVector() const { 
     return std::vector<MVertex*>(_v, _v + sizeof(_v)/sizeof(MVertex*) ); }
   std::vector<int> getSortedVertexVector() const {
     return std::vector<int>(_vs, _vs + sizeof(_vs)/sizeof(int) ); }
   
   void getFacetVertices(const int num, std::vector<MVertex*> &v) const {
     MPyramid::getFaceVertices(num, v);
   }
   
   virtual void printCell() const { printf("Cell dimension: %d, Vertices: %d %d %d %d %d, in subdomain: %d \n", getDim(), _v[0]->getNum(), _v[1]->getNum(), _v[2]->getNum(), _v[3]->getNum(), _v[4]->getNum(), _inSubdomain); }
};
/*
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
     
     
     //return (c1->getTag() < c2->getTag());
     
   }
};
*/


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
     
     //return (c1->getTag() == c2->getTag());
      
   }
};


// Ordering for the finite element mesh vertices.
class Less_MVertex{
  public:
   bool operator()(const MVertex* v1, const MVertex* v2) const {
     return (v1->getNum() < v2->getNum());
   }
};

// A cell that is a combination of cells of same dimension
class CombinedCell : public Cell{
 
  private:
   std::vector<MVertex*> _v;
   std::vector<int> _vs;
   std::list< std::pair<int, Cell*> > _cells;
   int _num;
   
  public:
   
   CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co=false) : Cell(){
     
     // use "smaller" cell as c2
     if(c1->getNumVertices() < c2->getNumVertices()){
       Cell* temp = c1;
       c1 = c2;
       c2 = temp;
     }
     
     _index = c1->getIndex();
     _tag = c1->getTag();
     _dim = c1->getDim();
     _num = c1->getNum();
     _inSubdomain = c1->inSubdomain();
     _onDomainBoundary = c1->onDomainBoundary();
     _combined = true;
     
     _v.reserve(c1->getNumVertices() + c2->getNumVertices());
     _vs.reserve(c1->getNumVertices() + c2->getNumVertices());
            
     
     _v = c1->getVertexVector();
     for(int i = 0; i < c2->getNumVertices(); i++){
       if(!this->hasVertex(c2->getVertex(i)->getNum())) _v.push_back(c2->getVertex(i));
     }
     
     for(unsigned int i = 0; i < _v.size(); i++) _vs.push_back(_v.at(i)->getNum());
     std::sort(_vs.begin(), _vs.end());
     
     _cells = c1->getCells();
     std::list< std::pair<int, Cell*> > c2Cells = c2->getCells();
     for(std::list< std::pair<int, Cell*> >::iterator it = c2Cells.begin(); it != c2Cells.end(); it++){
       if(!orMatch) (*it).first = -1*(*it).first;
       _cells.push_back(*it);
     }
     
     
     //_boundary = c1->getOrientedBoundary();
     std::map< Cell*, int, Less_Cell > c1Boundary = c1->getOrientedBoundary();
     std::map< Cell*, int, Less_Cell > c2Boundary = c2->getOrientedBoundary();
     
     
     for(std::map<Cell*, int, Less_Cell>::iterator it = c1Boundary.begin(); it != c1Boundary.end(); it++){
       Cell* cell = (*it).first;
       int ori = (*it).second;
       cell->removeCoboundaryCell(c1); 
       if(this->addBoundaryCell(ori, cell)) cell->addCoboundaryCell(ori, this);
     }
     for(std::map<Cell*, int, Less_Cell >::iterator it = c2Boundary.begin(); it != c2Boundary.end(); it++){
       Cell* cell = (*it).first;
       if(!orMatch) (*it).second = -1*(*it).second;
       int ori = (*it).second;
       cell->removeCoboundaryCell(c2);
       //if(this->addBoundaryCell(ori, cell)) cell->addCoboundaryCell(ori, this);       
       if(co){
         std::map<Cell*, int, Less_Cell >::iterator it2 = c1Boundary.find(cell);
         bool old = false;
         if(it2 != c1Boundary.end()) old = true;
         /*
         for(std::list< std::pair<int, Cell* > >::iterator it2 = c1Boundary.begin(); it2 != c1Boundary.end(); it2++){
           Cell* cell2 = (*it2).second;
           if(*cell2 == *cell) old = true;
         }
         */
         if(!old){  if(this->addBoundaryCell(ori, cell)) cell->addCoboundaryCell(ori, this); }
       }
       else{
         if(this->addBoundaryCell(ori, cell)) cell->addCoboundaryCell(ori, this);
       }
     }
     
     //_coboundary = c1->getOrientedCoboundary();
     std::map<Cell*, int, Less_Cell > c1Coboundary = c1->getOrientedCoboundary();
     std::map<Cell*, int, Less_Cell > c2Coboundary = c2->getOrientedCoboundary();
     
     for(std::map<Cell*, int, Less_Cell>::iterator it = c1Coboundary.begin(); it != c1Coboundary.end(); it++){
       Cell* cell = (*it).first;
       int ori = (*it).second;
       cell->removeBoundaryCell(c1); 
       if(this->addCoboundaryCell(ori, cell)) cell->addBoundaryCell(ori, this);
     }
     for(std::map<Cell*, int, Less_Cell>::iterator it = c2Coboundary.begin(); it != c2Coboundary.end(); it++){
       Cell* cell = (*it).first;
       if(!orMatch) (*it).second = -1*(*it).second;
       int ori = (*it).second;
       cell->removeBoundaryCell(c2);
       //if(this->addCoboundaryCell(ori, cell)) cell->addBoundaryCell(ori, this);       
       if(!co){
         std::map<Cell*, int, Less_Cell >::iterator it2 = c1Coboundary.find(cell);
         bool old = false;
         if(it2 != c1Coboundary.end()) old = true;
         /*
         for(std::list< std::pair<int, Cell* > >::iterator it2 = c1Coboundary.begin(); it2 != c1Coboundary.end(); it2++){
           Cell* cell2 = (*it2).second;
           if(*cell2 == *cell) old = true;
         }
         */
         if(!old) { if(this->addCoboundaryCell(ori, cell)) cell->addBoundaryCell(ori, this); }
       }
       else {
         if(this->addCoboundaryCell(ori, cell)) cell->addBoundaryCell(ori, this);
       }
     }

   }
  
   ~CombinedCell(){
     std::list< std::pair<int, Cell*> > cells = getCells();
     for(std::list< std::pair<int, Cell*> >::iterator it = cells.begin(); it != cells.end(); it++){
       Cell* cell2 = (*it).second;
       delete cell2;
     }
   } 
   
   int getNum() { return _num; }
   int getNumVertices() const { return _v.size(); } 
   MVertex* getVertex(int vertex) const { return _v.at(vertex); }
   int getSortedVertex(int vertex) const { return _vs.at(vertex); }
   std::vector<MVertex*> getVertexVector() const { return _v; }
   
   int kappa(Cell* tau) const { return 0; }
   
   // true if this cell has given vertex
   bool hasVertex(int vertex) const {
     //std::vector<int>::iterator it = std::find(_vs.begin(), _vs.end(), vertex);
     //if (it == _vs.end()) return false;
     //else return true;
     for(unsigned int i = 0; i < _v.size(); i++){
       if(_v.at(i)->getNum() == vertex) return true;
     }
     return false;
   }
   
   virtual void printCell() const {
     printf("Cell dimension: %d, ", getDim() ); 
     printf("Vertices: ");
     for(int i = 0; i < this->getNumVertices(); i++){
       printf("%d ", this->getSortedVertex(i));
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
   
   // storage for cell pointers to delete them
   //std::set<Cell*, Less_Cell>  _cells2[4];
   std::list<Cell*> _trash;
   
   std::vector< std::set<Cell*, Less_Cell> > _store;
   std::set<Cell*, Less_Cell> _ecells;
   
   
   std::set<Cell*, Less_Cell>  _ocells[4];
   
   // Betti numbers of this cell complex (ranks of homology groups)
   int _betti[4];
   
   int _dim;
   
  public:
   // iterator for the cells of same dimension
   typedef std::set<Cell*, Less_Cell>::iterator citer;
   
  private: 
   // enqueue cells in queue if they are not there already
   void enqueueCells(std::list<Cell*>& cells, 
                             std::queue<Cell*>& Q, std::set<Cell*, Less_Cell>& Qset);
   // remove cell from the queue set
   void removeCellQset(Cell*& cell, std::set<Cell*, Less_Cell>& Qset);
      
   // insert cells into this cell complex
   //virtual void insert_cells(bool subdomain, bool boundary);
   void insert_cells(bool subdomain, bool boundary);
   
   // remove a cell from this cell complex
   void removeCell(Cell* cell, bool other=true);
  public: 
   void insertCell(Cell* cell);
   
   // reduction of this cell complex
   // removes reduction pairs of cell of dimension dim and dim-1
   int reduction(int dim, int omitted=0);
  private:
   // queued coreduction presented in Mrozek's paper
   int coreduction(Cell* generator, int omitted=0);
 
   
  public: 
   /*
   CellComplex(  std::vector<GEntity*> domain, std::vector<GEntity*> subdomain, std::set<Cell*, Less_Cell> cells ) {
     _domain = domain;
     _subdomain = subdomain;
     for(citer cit = cells.begin(); cit != cells.end(); cit++){
       Cell* cell = *cit;
       _cells[cell->getDim()].insert(cell);
     }
   }
   
   
   CellComplex(CellComplex* cellComplex){
     
     _domain = cellComplex->getDomain();
     _subdomain = cellComplex->getSubdomain;
     _boundary = cellComplex->getBoundary;
     _domainVertices = cellComplex->getDomainVertices;
     
     for(int i = 0; i < 4; i++){
       _betti[i] = cellComplex->getBetti(i);
       _cells[i] = ocells[i];
       _ocells[i] = ocells[i];
     }
     
     _dim = cellComplex->getDim();
   }
   */
   
   CellComplex( std::vector<GEntity*> domain, std::vector<GEntity*> subdomain );
   CellComplex(){}
   ~CellComplex(){
     for(int i = 0; i < 4; i++){
       _cells[i].clear();
       
       for(citer cit = _ocells[i].begin(); cit != _ocells[i].end(); cit++){
         Cell* cell = *cit;
         delete cell;
       }
        _ocells[i].clear();
       
     }
     //emptyTrash();
   }

   
   void emptyTrash(){
     for(std::list<Cell*>::iterator cit  = _trash.begin(); cit != _trash.end(); cit++){
       Cell* cell = *cit;
       delete cell;
     }
     _trash.clear();
   }
   
   void restoreComplex(){
     for(int i = 0; i < 4; i++){
       _betti[i] = 0;
       _cells[i] = _ocells[i];
       for(citer cit = firstCell(i); cit != lastCell(i); cit++){
         Cell* cell = *cit;
         cell->restoreCell();
       }
     }
     _store.clear();
     _ecells.clear();
     _trash.clear();
   }
     
   // get the number of certain dimensional cells
   int getSize(int dim){ return _cells[dim].size(); }
   int getOrgSize(int dim){ return _ocells[dim].size(); }
   
   int getDim() {return _dim; } 
   
   std::set<Cell*, Less_Cell> getCells(int dim){ return _cells[dim]; }
   std::set<Cell*, Less_Cell> getOrgCells(int dim){ return _ocells[dim]; }
   
   // iterators to the first and last cells of certain dimension
   citer firstCell(int dim) {return _cells[dim].begin(); }
   citer lastCell(int dim) {return _cells[dim].end(); }
   citer firstOrgCell(int dim) {return _ocells[dim].begin(); }
   citer lastOrgCell(int dim) {return _ocells[dim].end(); }
   
   
   // true if cell complex has given cell
   bool hasCell(Cell* cell, bool org=false){
     if(!org){
       citer cit = _cells[cell->getDim()].find(cell);
       if( cit == lastCell(cell->getDim()) ) return false;
       else return true;
     }
     else{
       citer cit = _ocells[cell->getDim()].find(cell);
       if( cit == lastOrgCell(cell->getDim()) ) return false;
       else return true;
     }
   }
     

   // kappa for two cells of this cell complex
   // implementation will vary depending on cell type
   inline int kappa(Cell* sigma, Cell* tau) const { return sigma->kappa(tau); }
   
   
   // check whether two cells both belong to subdomain or if neither one does
   bool inSameDomain(Cell* c1, Cell* c2) const { return 
       ( (!c1->inSubdomain() && !c2->inSubdomain()) || (c1->inSubdomain() && c2->inSubdomain()) ); }
     

   // useful functions for (co)reduction of cell complex
   int reduceComplex();
   int coreduceComplex();
   
   
   // add every volume, face and edge its missing boundary cells
   // void repairComplex(int i=3);
   // change non-subdomain cells to be in subdomain, subdomain cells to not to be in subdomain
   void swapSubdomain();
   void removeSubdomain();
   
   
   // print the vertices of cells of certain dimension
   void printComplex(int dim);
   
   // write this cell complex in 2.0 MSH ASCII format
   int writeComplexMSH(const std::string &name); 
   
   // Cell combining for reduction and coreduction
   int combine(int dim);
   int cocombine(int dim);
   
   
   void computeBettiNumbers();
   int getBettiNumber(int i) { if(i > -1 && i < 4) return _betti[i]; else return 0; }
   
   // check whether all boundary cells of a cell has this cell as coboundary cell and vice versa
   // also check whether all (co)boundary cells of a cell belong to this cell complex
   bool checkCoherence();
   
   int eulerCharacteristic(){
     return getSize(0) - getSize(1) + getSize(2) - getSize(3);
   }
   void printEuler(){ printf("Euler characteristic: %d. \n", eulerCharacteristic()); }
   
   int getNumOmitted() { return _store.size(); };
   std::set<Cell*, Less_Cell> getOmitted(int i) { return _store.at(i); }
   
   void setImmuneCell(int num){
     for(int i = 0; i < 4; i++){
       for(citer cit = firstCell(i); cit != lastCell(i); cit++){
         Cell* cell = *cit;
         if(cell->getNum() == num) cell->setImmune(true);
       }
     }
     
   }
     
   
   // change roles of boundaries and coboundaries of the cells in this cell complex
   // equivalent to transposing boundary operator matrices
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
