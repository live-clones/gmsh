// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_H_
#define _LINEAR_SYSTEM_H_
#include <map>
#include <string>

// A class that encapsulates a linear system solver interface :
// building a sparse matrix, solving a linear system
class binding;
class linearSystemBase {
  protected:
  std::map<std::string, std::string> _parameters;
  public :
  virtual bool isAllocated() const = 0;
  virtual void allocate(int nbRows) = 0;
  virtual void clear() = 0;
  virtual void zeroMatrix() = 0;
  virtual void zeroRightHandSide() = 0;
  virtual int systemSolve() = 0;
  void setParameter (std::string key, std::string value);
};

template <class scalar>
class linearSystem : public linearSystemBase {
 public :
  linearSystem (){}
  virtual ~linearSystem (){}
  virtual void addToMatrix(int _row, int _col, const scalar &val) = 0;
  virtual void getFromMatrix(int _row, int _col, scalar &val) const = 0;
  virtual void addToRightHandSide(int _row, const scalar &val) = 0;
  virtual void getFromRightHandSide(int _row, scalar &val) const = 0;
  virtual void getFromSolution(int _row, scalar &val) const = 0;
  static void registerBindings (binding*);
  virtual double normInfRightHandSide() const = 0;
};

#endif
