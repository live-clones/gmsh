// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Matti Pellikka (initial implementation), Bruno de Sousa Alves
// (periodicity)

#ifndef CELL_H
#define CELL_H

#include <deque>
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
  // whether this cell is currently a live member of its cell complex
  // (removed cells stay in the complex's cell containers as tombstones
  // until compaction, so membership is tracked here in constant time)
  bool _inComplex = false;
  // whether this cell is currently in a reduction work queue (replaces the
  // tree-based queue dedup sets with a constant-time flag)
  bool _queued = false;

  // list of cells on the boundary and on the coboundary of this cell.
  // Cells typically have only a handful of (co)boundary neighbors, so a
  // vector kept sorted by CellPtrLessThan is faster and far more
  // memory-efficient (one heap block instead of a tree node per entry)
  // than a std::map for this size range.
  std::vector<std::pair<Cell *, BdInfo> > _bd;
  std::vector<std::pair<Cell *, BdInfo> > _cbd;

  // number of _bd/_cbd entries with a nonzero current orientation, kept in
  // sync incrementally so getBoundarySize()/getCoboundarySize() and
  // firstBoundary()/firstCoboundary() don't need to rescan entries left
  // behind (with zero current but nonzero original orientation) for restore
  int _bdSize = 0;
  int _cbdSize = 0;

  // find/locate cell in a sorted (co)boundary vector
  static std::vector<std::pair<Cell *, BdInfo> >::iterator
  _bdLowerBound(std::vector<std::pair<Cell *, BdInfo> > &v, Cell *cell);
  static std::vector<std::pair<Cell *, BdInfo> >::iterator
  _bdFind(std::vector<std::pair<Cell *, BdInfo> > &v, Cell *cell);

private:
  char _dim;
  // vertices and sorted vertex order, stored inline (a cell has at most 8
  // corner vertices): avoids two heap allocations per cell. _nsi is 0 when
  // the cell is degenerate (duplicate vertices).
  char _nv = 0;
  char _nsi = 0;
  MVertex *_v[8];
  // sorted vertices of this cell (used for ordering of the cells)
  char _si[8];

  bool _sortVertexIndices();

public:
  // the default constructor is public so that elementary cells can live in
  // a container owned by the cell complex instead of being allocated one
  // by one
  Cell() {}

  // create a cell in the pool container; the returned pointers stay valid
  // since std::deque never relocates its elements. The bool is false for a
  // degenerate cell: the caller should then discard it with pop_back().
  static std::pair<Cell *, bool>
  createCell(MElement *element, int domain, std::deque<Cell> &pool);
  static Cell *createCell(Cell *parent,
                          const std::vector<MVertex *> &vertices,
                          std::deque<Cell> &pool);

  Cell(MElement *element, int domain);
  Cell(Cell *parent, int i);
  // a cell of the given dimension with the given vertices, not tied to
  // any mesh element: used to look up a cell by its vertices
  Cell(int dim, const std::vector<MVertex *> &vertices);

  virtual ~Cell() {}

  int getDomain() const { return _domain; }
  void setDomain(int domain) { _domain = domain; }
  int getNum() const { return _num; }
  void setNum(int num) { _num = num; };
  int getTypeMSH() const;
  virtual int getDim() const { return _dim; }
  bool inSubdomain() const { return _domain ? true : false; }
  void getMeshVertices(std::vector<MVertex *> &v) const
  {
    v.assign(_v, _v + (int)_nv);
  }

  void setImmune(bool immune) { _immune = immune; };
  bool getImmune() const { return _immune; };

  void setInComplex(bool in) { _inComplex = in; }
  bool inComplex() const { return _inComplex; }
  void setQueued(bool queued) { _queued = queued; }
  bool getQueued() const { return _queued; }

  int getNumSortedVertices() const { return _nsi; }
  int getSortedVertex(int vertex) const
  {
    return _v[(int)_si[vertex]]->getNum();
  }
  int getNumVertices() const { return _nv; }
  MVertex *getMeshVertex(int vertex) const { return _v[vertex]; }

  void findBdElement(int i, std::vector<MVertex *> &vertices) const;
  int getNumBdElements() const;
  int findBdCellOrientation(Cell *cell, int i) const;

  void increaseGlobalNum() { _globalNum++; }

  // save/restore the original boundary information of the cell
  void saveCellBoundary();
  void restoreCellBoundary();

  // (co)boundary cell iterator
  typedef std::vector<std::pair<Cell *, BdInfo> >::iterator biter;

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
protected:
  // list of cells this cell is a combination of
  std::map<Cell *, int, CellPtrLessThan> _cells;
  // dimension of the combined cells: cached, since when this cell is
  // merged into another combined cell its list is stolen (small-to-large
  // merging), while the removed cell may still be asked for its dimension
  int _dim;

  // for derived cells that fill in the members themselves
  CombinedCell() {}

public:
  CombinedCell(Cell *c1, Cell *c2, bool orMatch, bool co = false);
  CombinedCell(std::vector<Cell *> &cells);
  ~CombinedCell() {}

  int getDim() const { return _dim; }
  void getCells(std::map<Cell *, int, CellPtrLessThan> &cells)
  {
    cells = _cells;
  }
  int getNumCells() const { return _cells.size(); }

  bool operator==(const Cell &c2) const
  {
    return (this->getNum() == c2.getNum());
  }
};

class PeriodicCell : public CombinedCell {
public:
  PeriodicCell(Cell *c1, Cell *c2, bool orMatch);
  ~PeriodicCell() {}
};

#endif
