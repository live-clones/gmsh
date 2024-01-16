// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

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

class CellComplex {
private:
  std::pair<Cell *, double> _smallestCell;
  std::pair<Cell *, double> _biggestCell;

  GModel *_model;

  // sorted containers of unique cells in this cell complex
  // one for each dimension
  std::set<Cell *, CellPtrLessThan> _cells[4];

  // original cells of this cell complex
  std::set<Cell *, CellPtrLessThan> _ocells[4];

  // original cells removed during reductions
  std::vector<Cell *> _removedcells;

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

  int _numRelativeCells[4];
  int _numSubdomainCells[4];

  // for constructor
  bool _insertCells(std::vector<MElement *> &elements, int domain);
  bool _removeCells(std::vector<MElement *> &elements, int domain);

  bool _immunizeCells(std::vector<MElement *> &elements);

  Cell *_omitCell(Cell *cell, bool dual);

  // enqueue cells in queue if they are not there already
  void enqueueCells(std::map<Cell *, short int, CellPtrLessThan> &cells,
                    std::queue<Cell *> &Q,
                    std::set<Cell *, CellPtrLessThan> &Qset);

  // insert/remove a cell from this cell complex
  void removeCell(Cell *cell, bool other = true, bool del = false);
  void insertCell(Cell *cell);

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

  // iterator for the cells of same dimension
  typedef std::set<Cell *, CellPtrLessThan>::iterator citer;

  // iterators to the first and last cells of certain dimension
  citer firstCell(int dim, bool orig = false)
  {
    return orig ? _ocells[dim].begin() : _cells[dim].begin();
  }
  citer lastCell(int dim, bool orig = false)
  {
    return orig ? _ocells[dim].end() : _cells[dim].end();
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

  // print the vertices of cells of certain dimension
  void printComplex(int dim);

  // experimental
  int saveComplex(const std::string &filename);
  int loadComplex(const std::string &filename);
};

#endif
