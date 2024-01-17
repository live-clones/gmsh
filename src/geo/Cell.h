// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#ifndef CELL_H
#define CELL_H

#include <map>
#include <vector>
#include "MElement.h"

class Cell;

class CellPtrLessThan {
public:
  bool operator()(const Cell *c1, const Cell *c2) const;
};

// Class to save cell boundary orientation information
class BdInfo {
private:
  signed char _ori[2];

public:
  BdInfo(int ori)
  {
    _ori[0] = ori;
    _ori[1] = 0;
  }

  int get() const { return _ori[0]; }
  void reset() { _ori[0] = _ori[1]; }
  void init() { _ori[1] = _ori[0]; }
  void set(int ori) { _ori[0] = ori; }
  int geto() const { return _ori[1]; }
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
  std::map<Cell *, BdInfo, CellPtrLessThan> _bd;
  std::map<Cell *, BdInfo, CellPtrLessThan> _cbd;

  Cell() {}

private:
  char _dim;
  std::vector<MVertex *> _v;
  // sorted vertices of this cell (used for ordering of the cells)
  std::vector<char> _si;

  inline bool _sortVertexIndices();

public:
  static std::pair<Cell *, bool> createCell(MElement *element, int domain);
  static std::pair<Cell *, bool> createCell(Cell *parent, int i);

  Cell(MElement *element, int domain);
  Cell(Cell *parent, int i);

  virtual ~Cell() {}

  int getDomain() const { return _domain; }
  void setDomain(int domain) { _domain = domain; }
  int getNum() const { return _num; }
  void setNum(int num) { _num = num; };
  int getTypeMSH() const;
  virtual int getDim() const { return _dim; }
  bool inSubdomain() const { return _domain ? true : false; }
  void getMeshVertices(std::vector<MVertex *> &v) const { v = _v; }

  void setImmune(bool immune) { _immune = immune; };
  bool getImmune() const { return _immune; };

  int getNumSortedVertices() const { return _si.size(); }
  inline int getSortedVertex(int vertex) const;
  int getNumVertices() const { return _v.size(); }
  MVertex *getMeshVertex(int vertex) const { return _v.at(vertex); }

  void findBdElement(int i, std::vector<MVertex *> &vertices) const;
  int getNumBdElements() const;
  int findBdCellOrientation(Cell *cell, int i) const;

  void increaseGlobalNum() { _globalNum++; }

  // save/restore the original boundary information of the cell
  void saveCellBoundary();
  void restoreCellBoundary();

  // true if this cell has given vertex
  virtual bool hasVertex(int vertex) const;

  // (co)boundary cell iterator
  typedef std::map<Cell *, BdInfo, CellPtrLessThan>::iterator biter;

  // iterators to (first/last (co)boundary cells of this cell
  // (orig: to original (co)boundary cells of this cell)
  biter firstBoundary(bool orig = false);
  biter lastBoundary();
  biter firstCoboundary(bool orig = false);
  biter lastCoboundary();

  int getBoundarySize(bool orig = false);
  int getCoboundarySize(bool orig = false);

  // get the (orig: original) cell boundary
  void getBoundary(std::map<Cell *, short int, CellPtrLessThan> &boundary,
                   bool orig = false);
  void getCoboundary(std::map<Cell *, short int, CellPtrLessThan> &coboundary,
                     bool orig = false);

  // add (co)boundary cell
  // (other: reciprocally also add this cell from the other cell's (co)boundary)
  void addBoundaryCell(int orientation, Cell *cell, bool other);
  void addCoboundaryCell(int orientation, Cell *cell, bool other);

  // remove (co)boundary cell
  // (other: reciprocally also revove this cell from the other cell's
  // (co)boundary)
  void removeBoundaryCell(Cell *cell, bool other);
  void removeCoboundaryCell(Cell *cell, bool other);

  // true if has given cell on (orig: original) (co)boundary
  bool hasBoundary(Cell *cell, bool orig = false);
  bool hasCoboundary(Cell *cell, bool orig = false);

  // print cell debug info
  virtual void printCell();
  virtual void printBoundary();
  virtual void printCoboundary();

  // tools for combined cells
  bool isCombined() const { return _combined; }

  typedef std::map<Cell *, int, CellPtrLessThan>::iterator citer;
  virtual void getCells(std::map<Cell *, int, CellPtrLessThan> &cells)
  {
    cells.clear();
    cells[this] = 1;
  }
  virtual int getNumCells() const { return 1; }

  bool operator==(const Cell &c2) const
  {
    return (this->getNum() == c2.getNum());
  }
};

// A cell that is a combination of cells of same dimension
class CombinedCell : public Cell {
private:
  // list of cells this cell is a combination of
  std::map<Cell *, int, CellPtrLessThan> _cells;

public:
  CombinedCell(Cell *c1, Cell *c2, bool orMatch, bool co = false);
  CombinedCell(std::vector<Cell *> &cells);
  ~CombinedCell() {}

  int getDim() const { return _cells.begin()->first->getDim(); }
  void getCells(std::map<Cell *, int, CellPtrLessThan> &cells)
  {
    cells = _cells;
  }
  int getNumCells() const { return _cells.size(); }
  bool hasVertex(int vertex) const;

  bool operator==(const Cell &c2) const
  {
    return (this->getNum() == c2.getNum());
  }
};

#endif
