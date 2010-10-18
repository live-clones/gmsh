// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
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
  for(int i = 0; i <_nRows; i++) {
    if (_rowsj[i]) free(_rowsj[i]);
  }
  free(_nByRow);
  free(_nAllocByRows);
  free(_rowsj);
}

void sparsityPattern::addEntry (int i, int j) 
{
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
  if (_nByRow[i]> _nAllocByRows[i]) {
    int na = (n+1)*3/2;
    _rowsj[i] = (int*)realloc(_rowsj[i], (na*sizeof(int)));
    _nAllocByRows[i] = na;
  }
  memmove(&_rowsj[i][k+1], &_rowsj[i][k], (n-k)*sizeof (int));
  _rowsj[i][k] = j;
}

sparsityPattern::sparsityPattern (int ni) 
{
  _nRows = ni;
  _rowsj = (int**)malloc (sizeof(int*)*ni);
  _nByRow = (int*)malloc(sizeof(int)*ni);
  _nAllocByRows = (int*)malloc(sizeof(int)*ni);
  for (int i = 0; i < ni; i++) {
    _nByRow[i] = 0;
    _nAllocByRows[i] = 0;
    _rowsj[i] = NULL;
  }
}

const int *sparsityPattern::getRow (int i, int &size) const
{
  size = _nByRow[i];
  return _rowsj[i];
}
