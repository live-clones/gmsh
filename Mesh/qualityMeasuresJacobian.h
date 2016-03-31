// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _QUALITY_MEASURES_JACOBIAN_H_
#define _QUALITY_MEASURES_JACOBIAN_H_

#include <vector>
#include "fullMatrix.h"

class bezierBasis;
class MElement;

namespace jacobianBasedQuality {

void minMaxJacobianDeterminant(MElement *el, double &min, double &max);
void minScaledJacobian(MElement *el, double &min);
double minScaledJacobian(MElement *el);

class _CoeffData
{
protected:
  double _minL, _maxL; //Extremum of Jac at corners
  double _minB, _maxB; //Extremum of bezier coefficients
  int _depth;

public:
  _CoeffData(int depth) : _minL(0), _maxL(0), _minB(0), _maxB(0),
                         _depth(depth) {}
  virtual ~_CoeffData() {}

  //inline int depth() const {return _depthSub;}
  inline double minL() const {return _minL;}
  inline double maxL() const {return _maxL;}
  inline double minB() const {return _minB;}
  inline double maxB() const {return _maxB;}

  virtual bool boundsOk(double minL, double maxL) const = 0;
  virtual void getSubCoeff(std::vector<_CoeffData*>&) const = 0;
};

struct _lessMinB {
  bool operator()(_CoeffData*, _CoeffData*) const;
};
struct _lessMaxB {
  bool operator()(_CoeffData*, _CoeffData*) const;
};

class _CoeffDataJac: public _CoeffData
{
private:
  const fullVector<double> _coeffs;
  const bezierBasis *_bfs;

public:
  _CoeffDataJac(fullVector<double> &v, const bezierBasis *bfs, int depth);
  ~_CoeffDataJac() {}

  bool boundsOk(double minL, double maxL) const;
  void getSubCoeff(std::vector<_CoeffData*>&) const;
};

class _CoeffDataScaledJac: public _CoeffData
{
private:
  const fullVector<double> _coeffsJacDet;
  const fullMatrix<double> _coeffsJacMat;
  const bezierBasis *_bfsDet, *_bfsMat;

public:
  _CoeffDataScaledJac(fullVector<double> &det,
                     fullMatrix<double> &mat,
                     const bezierBasis *bfsDet,
                     const bezierBasis *bfsMat,
                     int depth);
  ~_CoeffDataScaledJac() {}

  bool boundsOk(double minL, double maxL) const;
  void getSubCoeff(std::vector<_CoeffData*>&) const;

private:
  void _computeAtCorner(double &min, double &max) const;
  double _computeLowerBound() const;
};

//inline bool isValid(MElement *el) {
//  double min, max;
//  minMaxJacobianDeterminant(el, min, max);
//  return min > 0;
//}

double _computeBoundRational(const fullVector<double> &numerator,
                             const fullVector<double> &denominator,
                             bool lower, bool positiveDenom = true);
}

#endif
