// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _CELL_H_
#define _CELL_H_

#include "GmshConfig.h"

#if defined(HAVE_KBIPACK)

#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include "CellComplex.h"
#include "MElement.h"
#include "MVertex.h"

class Cell;

// Ordering of the cells
class Less_Cell{
  public:
   bool operator()(const Cell* c1, const Cell* c2) const;
};

// Class representing an elementary cell of a cell complex.
class Cell
{  
 protected:
  
  // cell dimension
  int _dim;
   
  // whether this cell belongs to a subdomain
  // used in relative homology computation
  bool _subdomain;
  
  // whether this cell a combinded cell of elemetary cells
  bool _combined; 
  
  // mutable index for each cell (used to create boundary operator matrices)
  int _index; 
  
  // for some algorithms to omit this cell
  bool _immune;
  
  // mutable list of cells on the boundary and on the coboundary of this cell
  std::map< Cell*, int, Less_Cell > _bd;
  std::map< Cell*, int, Less_Cell > _cbd;
  // immutable original boundary and coboundary before the reduction of the
  // cell complex
  std::map<Cell*, int, Less_Cell > _obd;
  std::map<Cell*, int, Less_Cell > _ocbd;
  
  // sorted vertices of this cell (used for ordering of the cells)
  std::vector<int> _vs;

  
  
  // the mesh element that is the image of this cell
  MElement* _image;
  // whether to delete the mesh element when done
  // (set to true if created for homology computation only)
  bool _delimage;
  
  // get vertex 
  MVertex* getVertex(int vertex) const { 
    if(_image == NULL) printf("ERROR: No image mesh element for cell. \n");
    return _image->getVertex(vertex); }  
   // get the number of vertices this cell has
  int getNumVertices() const { 
    if(_image == NULL) printf("ERROR: No image mesh element for cell. \n");
    return _image->getNumPrimaryVertices(); }
  // get the number of facets of this cell
  int getNumFacets() const;
  // get the vertices on a facet of this cell
  void getFacetVertices(const int num, std::vector<MVertex*> &v) const;
  
 public:

 Cell() : _combined(false), _index(0), _immune(false), _image(NULL), 
    _delimage(false), _subdomain(false) {}
  Cell(MElement* image);
  ~Cell();

  // the mesh element this cell is represented by
  MElement* getImageMElement() const { 
    if(_image == NULL) printf("ERROR: No image mesh element for cell. \n");
    return _image; }
  // get/set whether the image mesh element should be deleted when
  // this cell gets deleted 
  // (was the mesh element in the original mesh,
  // is it needed after homology computation for visualization?) 
  void setDeleteImage(bool delimage) { _delimage = delimage; }
  bool getDeleteImage() const { return _delimage; }

  // find the cells on the boundary of this cell
  bool findBoundaryCells(std::vector<Cell*>& bdCells);
  // get boundary cell orientation
  int findBoundaryCellOrientation(Cell* cell);
  

  int getDim() const { return _dim; };
  int getIndex() const { return _index; };
  void setIndex(int index) { _index = index; };
  void setImmune(bool immune) { _immune = immune; };
  bool getImmune() const { return _immune; };
  bool inSubdomain() const { return _subdomain; }
  void setInSubdomain(bool subdomain)  { _subdomain = subdomain; }
  virtual int getNumSortedVertices() const { return _vs.size(); }
  virtual int getSortedVertex(int vertex) const { return _vs.at(vertex); }
  virtual int getNum() const { return 0; }

  // restores the cell information to its original state before reduction
  void restoreCell();
  
  // true if this cell has given vertex
  virtual bool hasVertex(int vertex) const;
  
  // (co)boundary cell iterator
  typedef std::map<Cell*, int, Less_Cell>::iterator biter;
  // iterators to (first/last (co)boundary cells of this cell
  // (orig: to original (co)boundary cells of this cell)
  biter firstBoundary(bool orig=false){ 
    return orig ? _obd.begin() : _bd.begin(); }
  biter lastBoundary(bool orig=false){ 
    return orig ? _obd.end() : _bd.end(); }
  biter firstCoboundary(bool orig=false){ 
    return orig ? _ocbd.begin() : _cbd.begin(); }
  biter lastCoboundary(bool orig=false){ 
    return orig ? _ocbd.end() : _cbd.end(); }

  int getBoundarySize() { return _bd.size(); }
  int getCoboundarySize() { return _cbd.size(); }
   
  // get the (orig: original) cell boundary
  void getBoundary(std::map<Cell*, int, Less_Cell >& boundary, 
		   bool orig=false){
    orig ? boundary = _obd : boundary =  _bd; }
  void getCoboundary(std::map<Cell*, int, Less_Cell >& coboundary,
		     bool orig=false){
    orig ? coboundary = _ocbd : coboundary = _cbd; }
  
  // add (co)boundary cell (orig: as original)
  // (other: reciprocally also add this cell from the other cell's (co)boundary)
  void addBoundaryCell(int orientation, Cell* cell, 
		       bool orig, bool other); 
  void addCoboundaryCell(int orientation, Cell* cell, 
			 bool orig, bool other);
  
  // remove (co)boundary cell 
  // (other: reciprocally also revove this cell from the other cell's (co)boundary)
  void removeBoundaryCell(Cell* cell, bool other);
  void removeCoboundaryCell(Cell* cell, bool other);
  
  // true if has given cell on (orig: original) (co)boundary
  bool hasBoundary(Cell* cell, bool orig=false);
  bool hasCoboundary(Cell* cell, bool orig=false);
  
  void clearBoundary() { _bd.clear(); }
  void clearCoboundary() { _cbd.clear(); }
  
  // print cell debug info
  virtual void printCell();
  virtual void printBoundary(bool orig=false);
  virtual void printCoboundary(bool orig=false);   
  
  // tools for combined cells
  bool isCombined() const { return _combined; }
  virtual void getCells( std::map< Cell*, int, Less_Cell >& cells) {  
    cells.clear();
    cells[this] = 1; 
    return;
  }
  virtual int getNumCells() const {return 1;}
  typedef std::map<Cell*, int, Less_Cell>::iterator citer;

  // equivalence
  virtual bool operator==(const Cell& c2) const {  
    if(this->isCombined() != c2.isCombined()) return false;
    
    if(this->getNumSortedVertices() != c2.getNumSortedVertices()){
      return false;
    }
    for(int i=0; i < this->getNumSortedVertices();i++){
      if(this->getSortedVertex(i) != c2.getSortedVertex(i)){
	return false;
      }
    }
    return true;
  }
};

// A cell that is a combination of cells of same dimension
class CombinedCell : public Cell{
  
 private:
  // list of cells this cell is a combination of
  std::map< Cell*, int, Less_Cell > _cells;

  // combined cell number, used for ordering
  int _num;
  static int _globalNum;

 public:
  
  CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co=false);
  ~CombinedCell() {}
  
  void getCells(std::map< Cell*, int, Less_Cell >& cells) { cells = _cells; }
  int getNumCells() const {return _cells.size();}  
  int getNum() const { return _num; }

  bool operator==(const Cell& c2) const {
    if(this->isCombined() != c2.isCombined()) return false;
    if(this->getNum() != c2.getNum()) return false;
    else return true;
  }
};
  
#endif

#endif
