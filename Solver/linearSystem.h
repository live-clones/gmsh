// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LINEAR_SYSTEM_H
#define LINEAR_SYSTEM_H

#include <map>
#include <string>

// A class that encapsulates a linear system solver interface :
// building a sparse matrix, solving a linear system
class linearSystemBase {
protected:
  std::map<std::string, std::string> _parameters;

public:
  virtual ~linearSystemBase() {}
  virtual bool isAllocated() const = 0;
  virtual void allocate(int nbRows) = 0;
  virtual void preAllocateEntries(){};
  virtual void clear() = 0;
  virtual void zeroMatrix() = 0;
  virtual void zeroRightHandSide() = 0;
  virtual void zeroSolution() = 0;
  virtual int systemSolve() = 0;
  // x = A*b
  virtual int matMult() { return 0; }

  void setParameter(const std::string &key, std::string value);
  std::string getParameter(const std::string &key) const;
  virtual void insertInSparsityPattern(int _row, int _col){};
  virtual double normInfRightHandSide() const = 0;
  virtual double normInfSolution() const { return 0; };
};

template <class scalar> class linearSystem : public linearSystemBase {
public:
  linearSystem() {}
  virtual ~linearSystem() {}
  virtual void addToMatrix(int _row, int _col, const scalar &val) = 0;
  virtual void getFromMatrix(int _row, int _col, scalar &val) const = 0;
  virtual void addToRightHandSide(int _row, const scalar &val, int ith = 0) = 0;
  virtual void getFromRightHandSide(int _row, scalar &val) const = 0;
  virtual void getFromSolution(int _row, scalar &val) const = 0;
  virtual void addToSolution(int _row, const scalar &val) = 0;
};

#endif
