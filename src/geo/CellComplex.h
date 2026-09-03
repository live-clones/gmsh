// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Matti Pellikka (initial implementation), Bruno de Sousa Alves
// (periodicity)

#ifndef CELLCOMPLEX_H
#define CELLCOMPLEX_H

#include <map>
#include <string.h>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include "Cell.h"
#include "MElement.h"
#include "GModel.h"

class Cell;
class BdInfo;
class CellConstructionIndex;

class CellComplex {
private:
  std::pair<Cell *, double> _smallestCell;
  std::pair<Cell *, double> _biggestCell;

  GModel *_model;

  // sorted (by CellPtrLessThan) containers of unique cells in this cell
  // complex, one for each dimension. Removing a cell only clears its
  // in-complex flag (see Cell::inComplex()) and leaves a tombstone entry
  // behind, so removals during the reductions are constant time; tombstones
  // are skipped during iteration and reclaimed by _compactIfNeeded()
  std::vector<Cell *> _cells[4];

  // number of live (non-tombstone) cells in _cells, one per dimension
  int _numLiveCells[4];

  // original cells of this cell complex (always all live)
  std::vector<Cell *> _ocells[4];

  // original cells removed during reductions
  std::vector<Cell *> _removedcells;

  // storage of the elementary cells: a deque allocates them in chunks
  // without relocating (their addresses stay valid), and frees them
  // wholesale on destruction instead of one delete per cell. Combined
  // cells are few and are still allocated individually. One pool per
  // index shard, so the parallel construction can create cells
  // concurrently; the serial paths use the first pool.
  std::vector<std::deque<Cell> > _cellPool;

  // cell complex dimension
  int _dim;

  // cell are simplexes
  bool _simplicial;

  // save the original unreduced complex for another reduction run
  bool _saveorig;

  // has a relative subdomain
  bool _relative;

  int _deleteCount;
  int _createCount;

  // is the cell complex at reduced state
  bool _reduced;

  // have the periodically equivalent cells been identified
  bool _periodic;

  int _numRelativeCells[4];
  int _numSubdomainCells[4];

  // for constructor
  bool _insertCells(std::vector<MElement *> &elements, int domain,
                    CellConstructionIndex &index);

  // create the boundary cells of the given dim-dimensional cells and wire
  // up the boundary/coboundary links, in parallel (see the implementation
  // for the pipeline; the result is identical to the serial code path)
  void _insertBoundaryCells(std::vector<Cell *> &cells, int dim, int domain,
                            CellConstructionIndex &index, int nthreads);

  // create the cells of the given mesh elements in parallel (the parallel
  // counterpart of the first loop of _insertCells, with identical results)
  void _insertElementCells(std::vector<MElement *> &elements, int domain,
                           CellConstructionIndex &index, int nthreads,
                           std::pair<Cell *, double> *smallestElement,
                           std::pair<Cell *, double> *biggestElement);

  bool _removeCells(std::vector<MElement *> &elements, int domain);

  bool _immunizeCells(std::vector<MElement *> &elements);

  Cell *_omitCell(Cell *cell, bool dual);

  // enqueue the live boundary/coboundary neighbors of a cell that are not
  // already queued (tracked by the constant-time Cell::getQueued() flag,
  // which the queue consumer must clear when it takes a cell out)
  void enqueueBoundaryCells(Cell *cell, std::queue<Cell *> &Q);
  void enqueueCoboundaryCells(Cell *cell, std::queue<Cell *> &Q);

  // insert/remove a cell from this cell complex
  void removeCell(Cell *cell, bool other = true);
  void insertCell(Cell *cell);

  // reclaim the tombstones of dimension dim (unconditionally, or only if
  // they outnumber the live cells); must only be called when no cell
  // iterators are held
  void _compact(int dim);
  void _compactIfNeeded(int dim);

  // binary search in a sorted cell container
  static std::vector<Cell *>::const_iterator
  _findCell(const std::vector<Cell *> &cells, Cell *cell);

  // find the cell with the same vertices as the given (unnumbered) cell:
  // valid after construction, since the cells are numbered in sorted vertex
  // order and hence the number-sorted containers are also vertex-ordered
  Cell *_findCellVertexOrder(Cell *cell) const;

  // queued coreduction
  int coreduction(Cell *startCell, int omit, std::vector<Cell *> &omittedCells);

  static double _patience;

public:
  CellComplex(GModel *model, std::vector<MElement *> &domainElements,
              std::vector<MElement *> &subdomainElements,
              std::vector<MElement *> &nondomainElements,
              std::vector<MElement *> &nonsubdomainElements,
              std::vector<MElement *> &immuneElements,
              bool saveOriginalComplex = true);
  ~CellComplex();

  GModel *getModel() const { return _model; }
  int getDim() const { return _dim; }
  bool simplicial() const { return _simplicial; }
  bool relative() const { return _relative; }

  // get the number of certain dimensional cells
  // if dim = -1 return the number of all cells
  int getSize(int dim, bool orig = false);

  // get domain of a cell
  // cell in domain relative to subdomain  -> domain = 0
  // cell in domain                        -> domain = 1
  // cell in subdomain                     -> domain = 2
  int getDomain(Cell *cell, std::string &str);

  // get dim-dimensional cells
  // domain = 0: cells in domain relative to subdomain
  // domain = 1: cells in domain
  // domain = 2: cells in subdomain
  void getCells(std::set<Cell *, CellPtrLessThan> &cells, int dim,
                int domain = 0);
  int getNumCells(int dim, int domain = 0);
  Cell *getACell(int dim, int domain = 0);
  // std::set<Cell*, CellPtrLessThan> getOrigCells(int dim){ return
  // _ocells[dim]; }

  // iterator for the cells of same dimension: skips the tombstones of
  // removed cells that remain in the container until compaction
  class citer {
  private:
    const std::vector<Cell *> *_v;
    std::size_t _i;
    // dead cells are tombstones only in the current-cell containers; the
    // original-cell containers are always fully live
    bool _skip;
    void _skipDead()
    {
      if(_skip)
        while(_i < _v->size() && !(*_v)[_i]->inComplex()) _i++;
    }

  public:
    citer() : _v(nullptr), _i(0), _skip(false) {}
    citer(const std::vector<Cell *> *v, std::size_t i, bool skip)
      : _v(v), _i(i), _skip(skip)
    {
      _skipDead();
    }
    Cell *operator*() const { return (*_v)[_i]; }
    citer &operator++()
    {
      _i++;
      _skipDead();
      return *this;
    }
    citer operator++(int)
    {
      citer it = *this;
      ++(*this);
      return it;
    }
    bool operator==(const citer &other) const { return _i == other._i; }
    bool operator!=(const citer &other) const { return _i != other._i; }
  };

  // iterators to the first and last cells of certain dimension
  citer firstCell(int dim, bool orig = false)
  {
    return orig ? citer(&_ocells[dim], 0, false) :
                  citer(&_cells[dim], 0, true);
  }
  citer lastCell(int dim, bool orig = false)
  {
    return orig ? citer(&_ocells[dim], _ocells[dim].size(), false) :
                  citer(&_cells[dim], _cells[dim].size(), true);
  }

  // true if cell complex has given cell
  bool hasCell(Cell *cell, bool orig = false);

  // check whether two cells both belong to subdomain or if neither one does
  bool inSameDomain(Cell *c1, Cell *c2) const
  {
    return (c1->getDomain() == c2->getDomain());
  }

  // remove cells in subdomain from this cell complex
  void removeSubdomain();

  // remove dim-dimensional cells from this cell complex
  void removeCells(int dim);

  // (co)reduction of this cell complex
  // removes (co)reduction pairs of cell of dimension dim and dim-1
  int reduction(int dim, int omit, std::vector<Cell *> &omittedCells);
  int coreduction(int dim, int omit, std::vector<Cell *> &omittedCells);

  // Cell combining for reduction and coreduction
  int combine(int dim);
  int cocombine(int dim);

  // check whether all boundary cells of a cell has this cell
  // as coboundary cell and vice versa
  // also check whether all (co)boundary cells of a cell
  // belong to this cell complex
  bool coherent();

  // full (co)reduction of this cell complex (all dimensions)
  // (combine = 1 -> with combining)
  // (omit = true -> with highest dimensional cell omitting?)
  // (homseq = true -> homology sequence splitting possible after reduction)
  // (heuristic =  0 -> no heuristic, let mesh indexing determine
  //               1 -> omit 0-cell in biggest element
  //              -1 -> omit 0-cell in smallest element)
  int reduceComplex(int combine = 1, bool omit = true, bool homseq = false);
  int coreduceComplex(int combine = 1, bool omit = true, int heuristic = 0);

  // reduce cell complex for Betti number computation
  void bettiReduceComplex();

  bool isReduced() const { return _reduced; }

  int eulerCharacteristic()
  {
    return getSize(0) - getSize(1) + getSize(2) - getSize(3);
  }
  void printEuler()
  {
    printf("Euler characteristic: %d. \n", eulerCharacteristic());
  }

  // restore the cell complex to its original state before (co)reduction
  bool restoreComplex();

  // replace each pair of periodically equivalent cells by a single cell, so
  // that the complex becomes the periodic quotient of the domain. Must be
  // called on an unreduced complex, and is a no-op if already done.
  // Only the periodic links carried by the nodes in slaveNodes and pointing
  // to nodes in masterNodes are used; an empty set means no restriction on
  // that side, i.e. all the periodic links of the model are used
  void periodicComplex(const std::set<MVertex *> &slaveNodes,
                       const std::set<MVertex *> &masterNodes);

  // relabel the (restored) original cell complex for a new relative
  // subdomain, instead of constructing the same complex from scratch:
  // clears the domain and immunity markings, marks the closure of the given
  // subdomain elements and reapplies the immune elements. Returns false if
  // an element has no cell in this complex (the cell complexes of the two
  // subdomains differ): the caller then needs a full reconstruction.
  bool relabel(std::vector<MElement *> &subdomainElements,
               std::vector<MElement *> &immuneElements);

  // print the vertices of cells of certain dimension
  void printComplex(int dim);

  // experimental
  int saveComplex(const std::string &filename);
  int loadComplex(const std::string &filename);
};

#endif
