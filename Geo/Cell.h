// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _CELL_H_
#define _CELL_H_

#include <map>
#include <vector>
#include "MElement.h"

class Cell;

class Less_Cell {
public:
  bool operator()(const Cell* c1, const Cell* c2) const;
};

// Class to save cell boundary orientation information
class BdInfo {
 private:
  signed char _ori;
  signed char _origOri;

 public:
  BdInfo(int ori) { _ori = ori; _origOri = 0; }

  int get() const { return _ori; }
  void reset() { _ori = _origOri; }
  void init() { _origOri = _ori; }
  void set(int ori) { _ori = ori; }
  int geto() const { return _origOri; }

};


// Class representing an elementary cell of a cell complex.
class Cell {

 protected:

  static int _globalNum;

  int _num;
  char _domain;

  // whether this cell a combinded cell of elementary cells
  bool _combined;
  // for some algorithms to omit this cell
  bool _immune;

  // list of cells on the boundary and on the coboundary of this cell
  std::map<Cell*, BdInfo, Less_Cell> _bd;
  std::map<Cell*, BdInfo, Less_Cell> _cbd;

 private:

  char _dim;
  std::vector<MVertex*> _v;
  // sorted vertices of this cell (used for ordering of the cells)
  std::vector<char> _si;

  inline void _sortVertexIndices();

 public:

  Cell() {}
  Cell(MElement* element, int domain);
  Cell(Cell* parent, int i);

  int getDomain() const { return _domain; }
  void setDomain(int domain) { _domain = domain; }
  int getNum() const { return _num; }
  void setNum(int num) { _num = num; };
  int getTypeMSH() const;
  virtual int getDim() const { return _dim; }
  bool inSubdomain() const { return _domain ? true : false; }
  void getMeshVertices(std::vector<MVertex*>& v) const { v = _v; }

  void setImmune(bool immune) { _immune = immune; };
  bool getImmune() const { return _immune; };

  int getNumSortedVertices() const { return _v.size(); }
  inline int getSortedVertex(int vertex) const;
  int getNumVertices() const { return _v.size(); }
  MVertex* getMeshVertex(int vertex) const { return _v.at(vertex); }

  void findBdElement(int i, std::vector<MVertex*>& vertices) const;
  int getNumBdElements() const;
  int findBdCellOrientation(Cell* cell, int i) const;

  void increaseGlobalNum() { _globalNum++; }

  // restores the cell information to its original state before reduction
  void restoreCell();

  // true if this cell has given vertex
  virtual bool hasVertex(int vertex) const;

  // (co)boundary cell iterator
  typedef std::map<Cell*, BdInfo, Less_Cell>::iterator biter;
  // iterators to (first/last (co)boundary cells of this cell
  // (orig: to original (co)boundary cells of this cell)
  biter firstBoundary(bool orig=false){
    biter it = _bd.begin();
    if(!orig) while(it->second.get() == 0 && it != _bd.end()) it++;
    else while(it->second.geto() == 0 && it != _bd.end()) it++;
    return it;
  }
  biter lastBoundary(){ return _bd.end(); }
  biter firstCoboundary(bool orig=false){
    biter it = _cbd.begin();
    if(!orig) while(it->second.get() == 0 && it != _cbd.end()) it++;
    else while(it->second.geto() == 0 && it != _cbd.end()) it++;
    return it;
  }
  biter lastCoboundary(){ return _cbd.end(); }

  int getBoundarySize(bool orig=false) {
    int size = 0;
    for(biter bit = _bd.begin(); bit != _bd.end(); bit++){
      if(!orig && bit->second.get() != 0) size++;
      else if(orig && bit->second.geto() != 0) size++;
    }
    return size; }
  int getCoboundarySize(bool orig=false) {
    int size = 0;
    for(biter bit = _cbd.begin(); bit != _cbd.end(); bit++){
      if(!orig && bit->second.get() != 0) size++;
      else if(orig && bit->second.geto() != 0) size++;
    }
    return size; }

  // get the (orig: original) cell boundary
  void getBoundary(std::map<Cell*, short int, Less_Cell>& boundary,
                   bool orig=false){
    boundary.clear();
    for(biter it = firstBoundary(); it != lastBoundary(); it++){
      Cell* cell = it->first;
      if(!orig && it->second.get() != 0) boundary[cell] = it->second.get();
      if(orig && it->second.geto() != 0) boundary[cell] = it->second.geto();
    }
  }
  void getCoboundary(std::map<Cell*, short int, Less_Cell>& coboundary,
                     bool orig=false){
    coboundary.clear();
    for(biter it = firstCoboundary(); it != lastCoboundary(); it++){
      Cell* cell = it->first;
      if(!orig && it->second.get() != 0) coboundary[cell] = it->second.get();
      if(orig && it->second.geto() != 0) coboundary[cell] = it->second.geto();
    }
  }


  // add (co)boundary cell
  // (other: reciprocally also add this cell from the other cell's (co)boundary)
  void addBoundaryCell(int orientation, Cell* cell, bool other);
  void addCoboundaryCell(int orientation, Cell* cell, bool other);

  void saveOriginalBd() {
    for(biter it = firstCoboundary(); it != lastCoboundary(); it++){
      it->second.init();
    }
    for(biter it = firstBoundary(); it != lastBoundary(); it++){
      it->second.init();
    }
  }

  // remove (co)boundary cell
  // (other: reciprocally also revove this cell from the other cell's (co)boundary)
  void removeBoundaryCell(Cell* cell, bool other);
  void removeCoboundaryCell(Cell* cell, bool other);

  // true if has given cell on (orig: original) (co)boundary
  bool hasBoundary(Cell* cell, bool orig=false);
  bool hasCoboundary(Cell* cell, bool orig=false);

  // print cell debug info
  virtual void printCell();
  //virtual void printBoundary(bool orig=false);
  //virtual void printCoboundary(bool orig=false);

  // tools for combined cells
  bool isCombined() const { return _combined; }

  typedef std::map<Cell*, int, Less_Cell>::iterator citer;
  virtual void getCells(std::map<Cell*, int, Less_Cell>& cells) {
    cells.clear();
    cells[this] = 1;
  }
  virtual int getNumCells() const { return 1; }

  bool operator==(const Cell& c2) const {
    return (this->getNum() == c2.getNum());
  }

};


// A cell that is a combination of cells of same dimension
class CombinedCell : public Cell{

 private:
  // list of cells this cell is a combination of
  std::map< Cell*, int, Less_Cell > _cells;

 public:

  CombinedCell(Cell* c1, Cell* c2, bool orMatch, bool co=false);
  CombinedCell(std::vector<Cell*>& cells);
  ~CombinedCell() {}

  int getDim() const { return _cells.begin()->first->getDim(); }
  void getCells(std::map< Cell*, int, Less_Cell >& cells) { cells = _cells; }
  int getNumCells() const {return _cells.size();}
  bool hasVertex(int vertex) const;

  bool operator==(const Cell& c2) const {
    return (this->getNum() == c2.getNum());
  }
};


#endif
