// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _BEZIER_BASIS_H_
#define _BEZIER_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"
#include "ElementType.h"

class MElement;

class bezierBasis {
 private :
  // the 'numLagCoeff' first exponents are related to 'Lagrangian' values
  int _numLagCoeff;
  int _type, _order;
  int _numDivisions, _dimSimplex;

  friend class MetricBasis;
  fullMatrix<double> _exponents;

 public :
  fullMatrix<double> matrixLag2Bez;
  fullMatrix<double> matrixBez2Lag;
  fullMatrix<double> subDivisor;

  // Constructors
  inline bezierBasis(int tag) {
    _construct(ElementType::ParentTypeFromTag(tag), ElementType::OrderFromTag(tag));
  }
  inline bezierBasis(int parendtType, int order) {
    _construct(parendtType, order);
  }

  // get methods
  inline int getDim() const {return _exponents.size2();}
  inline int getOrder() const {return _order;}
  inline int getDimSimplex() const {return _dimSimplex;}
  inline int getNumLagCoeff() const {return _numLagCoeff;}
  inline int getNumDivision() const {return _numDivisions;}
  inline int getNumSubNodes() const {return subDivisor.size1();}

  // Interpolation of n functions on N points :
  // coeffs(numCoeff, n) and uvw(N, dim)
  // => result(N, n)
  void interpolate(const fullMatrix<double> &coeffs,
                   const fullMatrix<double> &uvw,
                   fullMatrix<double> &result,
                   bool bezCoord = false) const;

 private :
  void _construct(int parendtType, int order);
};

#endif


