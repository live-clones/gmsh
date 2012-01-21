// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Jonathan Lambrechts
//

#include "sparsityPattern.h"

#include<stdlib.h>
#include<string.h>

// this class has been optimized, please before changing anything, check twice :
// the impact on the performance to assemble typical High Order FE problems
// and the impact on the memory usage for this operation

sparsityPattern::~sparsityPattern() 
{
  clear();
}

void sparsityPattern::clear() 
{
  for(int i = 0; i <_nRows; i++) {
    if (_rowsj[i]) free(_rowsj[i]);
  }
  if (_nByRow) free(_nByRow);
  if (_nAllocByRow) free(_nAllocByRow);
  if (_rowsj) free(_rowsj);
  _nByRow = NULL;
  _rowsj = NULL;
  _nAllocByRow = NULL;
  _nRows = 0;
  _nRowsAlloc = 0;
}

void sparsityPattern::insertEntry (int i, int j) 
{
  if (i >= _nRows) {
    if (i >= _nRowsAlloc) {
      _nRowsAlloc = (i+1)*3/2;
      _rowsj = (int**)realloc (_rowsj, sizeof(int*)*_nRowsAlloc);
      _nByRow = (int*)realloc (_nByRow, sizeof(int)*_nRowsAlloc);
      _nAllocByRow = (int*)realloc(_nAllocByRow, sizeof(int)*_nRowsAlloc);
    }
    for (int k = _nRows; k <= i; k++) {
      _nByRow[k] = 0;
      _nAllocByRow[k] = 0;
      _rowsj[k] = NULL;
    }
    _nRows = i+1;
  }

  int n = _nByRow[i];
  int *rowj = _rowsj[i];
  int k = 0;
  int k0 = 0, k1 = n;
  if (n>20) {
    while (k1-k0 > 20) {
      int k2 = ((k0+k1)/2);
      if (rowj[k2] > j)
        k1 = k2;
      else if (rowj[k2] < j)
        k0 = k2+1;
      else
        return;
    }
    for (k = k0; k < k1; k++) {
      if (rowj[k] >= j) {
        if (rowj[k] == j) return;
        break;
      }
    }
  } else { // this "if() else" is not strictly necessary but with it, gcc unroll the for(k) loop
    for (k = 0; k < n; k++) {
      if (rowj[k] >= j) {
        if (rowj[k] == j) return;
        break;
      }
    }
  }
  _nByRow[i] = n+1;
  if (_nByRow[i]> _nAllocByRow[i]) {
    int na = (n+1)*3/2;
    _rowsj[i] = (int*)realloc(_rowsj[i], (na*sizeof(int)));
    _nAllocByRow[i] = na;
  }
  memmove(&_rowsj[i][k+1], &_rowsj[i][k], (n-k)*sizeof (int));
  _rowsj[i][k] = j;
}

sparsityPattern::sparsityPattern () 
{
  _nRows = 0;
  _nRowsAlloc = 0;
  _rowsj = NULL;
  _nByRow = NULL;
  _nAllocByRow = NULL;
}

const int *sparsityPattern::getRow (int i, int &size) const
{
  if (i >= _nRows){
    size = 0;
    return NULL;
  }
  size = _nByRow[i];
  return _rowsj[i];
}
