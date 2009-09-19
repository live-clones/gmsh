// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_H_
#define _LINEAR_SYSTEM_H_

// A class that encapsulates a linear system solver interface :
// building a sparse matrix, solving a linear system
template <class scalar>
class linearSystem {
 public :
  linearSystem (){}
  virtual ~linearSystem (){}
  virtual bool isAllocated() const = 0;
  virtual void allocate(int nbRows) = 0;
  virtual void clear() = 0;
  virtual void addToMatrix(int _row, int _col, scalar val) = 0;
  virtual scalar getFromMatrix(int _row, int _col) const = 0;
  virtual void addToRightHandSide(int _row, scalar val) = 0;
  virtual scalar getFromRightHandSide(int _row) const = 0;
  virtual scalar getFromSolution(int _row) const = 0;
  virtual void zeroMatrix() = 0;
  virtual void zeroRightHandSide() = 0;
  virtual int systemSolve() = 0;
};

#endif
