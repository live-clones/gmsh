// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Matti Pellikka (initial implementation)

#ifndef CHAINCOMPLEX_H
#define CHAINCOMPLEX_H

#include <map>
#include <vector>
#include "CellComplex.h"
#include "SmithNormalForm.h"

class CellComplex;

// A class representing a chain complex of a cell complex.
// This should only be constructed for a reduced cell complex because of
// dense matrix representations and great computational complexity in
// its methods.
class ChainComplex {
private:
  // boundary operator matrices for this chain complex
  // h_k: C_k -> C_(k-1); an empty matrix means "no matrix"
  IntegerMatrix _hMatrix[5];

  // basis matrices for the kernels and codomains of the boundary operator
  // matrices
  IntegerMatrix _kerH[5];
  IntegerMatrix _codH[5];

  // matrix of the mapping B_k -> Z_k
  IntegerMatrix _jMatrix[5];
  // matrix of the mapping H_k -> Z_k
  IntegerMatrix _qMatrix[5];

  // bases for homology groups
  IntegerMatrix _hbasis[5];
  // torsion coefficients of homology generators
  // corresponding the columns of _hbasis
  std::vector<long int> _torsion[5];

  int _dim;
  CellComplex *_cellComplex;

  // index to cell map
  // matrix indices correspond to these cells in _cellComplex
  std::map<Cell *, int, CellPtrLessThan> _cellIndices[4];

  // set the matrices
  void setKerHMatrix(int dim, IntegerMatrix matrix)
  {
    if(dim > -1 && dim < 5) _kerH[dim] = std::move(matrix);
  }
  void setCodHMatrix(int dim, IntegerMatrix matrix)
  {
    if(dim > -1 && dim < 5) _codH[dim] = std::move(matrix);
  }
  void setJMatrix(int dim, IntegerMatrix matrix)
  {
    if(dim > -1 && dim < 5) _jMatrix[dim] = std::move(matrix);
  }
  void setQMatrix(int dim, IntegerMatrix matrix)
  {
    if(dim > -1 && dim < 5) _qMatrix[dim] = std::move(matrix);
  }
  void setHbasis(int dim, IntegerMatrix matrix)
  {
    if(dim > -1 && dim < 5) _hbasis[dim] = std::move(matrix);
  }

  // get the matrices; nullptr when out of range or not present
  IntegerMatrix *getHMatrix(int dim)
  {
    return (dim > -1 && dim < 5 && !_hMatrix[dim].empty()) ? &_hMatrix[dim] :
                                                             nullptr;
  }
  IntegerMatrix *getKerHMatrix(int dim)
  {
    return (dim > -1 && dim < 5 && !_kerH[dim].empty()) ? &_kerH[dim] :
                                                          nullptr;
  }
  IntegerMatrix *getCodHMatrix(int dim)
  {
    return (dim > -1 && dim < 5 && !_codH[dim].empty()) ? &_codH[dim] :
                                                          nullptr;
  }
  IntegerMatrix *getJMatrix(int dim)
  {
    return (dim > -1 && dim < 5 && !_jMatrix[dim].empty()) ? &_jMatrix[dim] :
                                                             nullptr;
  }
  IntegerMatrix *getQMatrix(int dim)
  {
    return (dim > -1 && dim < 5 && !_qMatrix[dim].empty()) ? &_qMatrix[dim] :
                                                             nullptr;
  }
  IntegerMatrix *getHbasis(int dim)
  {
    return (dim > -1 && dim < 5 && !_hbasis[dim].empty()) ? &_hbasis[dim] :
                                                            nullptr;
  }

  // local deformation tools for chains
  bool deformChain(std::map<Cell *, int, CellPtrLessThan> &cells,
                   std::pair<Cell *, int> cell, bool bend);
  bool deform(std::map<Cell *, int, CellPtrLessThan> &cells,
              std::map<Cell *, int, CellPtrLessThan> &cellsInChain,
              std::map<Cell *, int, CellPtrLessThan> &cellsNotInChain);
  void smoothenChain(std::map<Cell *, int, CellPtrLessThan> &cells);
  void eraseNullCells(std::map<Cell *, int, CellPtrLessThan> &cells);
  void deImmuneCells(std::map<Cell *, int, CellPtrLessThan> &cells);

public:
  // domain = 0 : relative chain space
  // domain = 1 : absolute chain space of all cells in cellComplex
  // domain = 2 : absolute chain space of cells in subdomain
  ChainComplex(CellComplex *cellComplex, int domain = 0);

  int getDim() const { return _dim; }

  // 1 : Z basis (cycles)
  // 2 : B basis (boundaries)
  // 3 : H basis (homology)
  // get the bases for various spaces; nullptr when not present
  IntegerMatrix *getBasis(int dim, int basis);

  // compute basis for kernel and codomain of boundary operator matrix
  // of dimension dim (ie. ker(h_dim) and cod(h_dim) )
  void KerCod(int dim);
  // compute matrix representation J for inclusion relation from dim-cells
  // who are boundary of dim+1-cells to cycles of dim-cells
  // (ie. j: cod(h_(dim+1)) -> ker(h_dim) )
  void Inclusion(int lowDim, int highDim);
  // compute quotient problem for given inclusion relation j to find
  // representatives of homology group generators and possible
  // torsion coeffcients
  void Quotient(int dim, int setDim);

  // transpose the boundary operator matrices, these are boundary operator
  // matrices for the dual mesh
  void transposeHMatrices();
  void transposeHMatrix(int dim);

  // Compute bases for the homology groups of this chain complex
  void computeHomology(bool dual = false);

  typedef std::map<Cell *, int, CellPtrLessThan>::iterator citer;
  citer firstCell(int dim) { return _cellIndices[dim].begin(); }
  citer lastCell(int dim) { return _cellIndices[dim].end(); }
  // get the cell index
  int getCellIndex(Cell *cell)
  {
    auto cit = _cellIndices[cell->getDim()].find(cell);
    if(cit != lastCell(cell->getDim()))
      return cit->second;
    else
      return 0;
  }

  // get basis chain from a basis matrix
  // (deform: with local deformations to make chain smoother and to have
  // smaller support, deformed chain is homologous to the old one,
  // only works for chains of the primary chain complex)
  void getBasisChain(std::map<Cell *, int, CellPtrLessThan> &chain, int num,
                     int dim, int basis, bool deform = false);
  // get rank of a basis
  int getBasisSize(int dim, int basis);
  // homology torsion coefficient for dim-dimensional chain num
  int getTorsion(int dim, int num);
};

#endif
