// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SPARSITY_PATTERN_H_
#define _SPARSITY_PATTERN_H_

// this class has been optimized, please before changing anything, check twice :
// - the impact on the performance to assemble typical High Order FE problems
// - the impact on the memory for this operation

class sparsityPattern {
  int *_nByRow, *_nAllocByRows;
  int **_rowsj;
  int _nRows;

 public :
  void addEntry (int i, int j);
  const int* getRow (int line, int &size) const;
  sparsityPattern (int nRows);
  ~sparsityPattern();
};

#endif
