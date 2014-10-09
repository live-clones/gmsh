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
#include "FuncSpaceData.h"

class MElement;

class bezierBasis {
 private :
  // the 'numLagCoeff' first exponents are related to 'Lagrangian' values
  int _numLagCoeff;
  int _numDivisions, _dimSimplex;
  const FuncSpaceData _data;

  friend class MetricBasis;
  fullMatrix<double> _exponents;

 public :
  fullMatrix<double> matrixLag2Bez;
  fullMatrix<double> matrixBez2Lag;
  fullMatrix<double> subDivisor;

  void printTag() const {Msg::Info("tagBezier is %d", _data.elementTag());}
  void printFuncSpace() const {_data.print();}

  // Constructors
  inline bezierBasis(FuncSpaceData data) : _data(data) {
    if (_data.elementType() == TYPE_PYR)
      _constructPyr();
    else
      _construct();
  }

  // get methods
  inline int getDim() const {return _exponents.size2();}
  inline int getOrder() const {return _data.spaceOrder();}
  inline int getDimSimplex() const {return _dimSimplex;}
  inline int getNumLagCoeff() const {return _numLagCoeff;}
  inline int getNumDivision() const {return _numDivisions;}
  inline int getNumSubNodes() const {return subDivisor.size1();}

  // generate Bezier points
  void generateBezierPoints(fullMatrix<double>&) const;

  // Subdivide Bezier coefficients
  void subdivideBezCoeff(const fullMatrix<double> &coeff,
                         fullMatrix<double> &subCoeff) const;
  void subdivideBezCoeff(const fullVector<double> &coeff,
                         fullVector<double> &subCoeff) const;

  // Interpolation of n functions on N points :
  // coeffs(numCoeff, n) and uvw(N, dim)
  // => result(N, n)
  void interpolate(const fullMatrix<double> &coeffs,
                   const fullMatrix<double> &uvw,
                   fullMatrix<double> &result,
                   bool bezCoord = false) const;
  void interpolate(const fullVector<double> &coeffs,
                   const fullMatrix<double> &uvw,
                   fullVector<double> &result,
                   bool bezCoord = false) const {
    int size = uvw.size1();
    result.resize(size);
    fullMatrix<double> c(const_cast<double*>(coeffs.getDataPtr()), size, 1);
    fullMatrix<double> r(const_cast<double*>(result.getDataPtr()), size, 1);
    interpolate(c, uvw, r, bezCoord);
  }

 private :
  void _construct();
  void _constructPyr();
  void _FEpoints2BezPoints(fullMatrix<double>&) const;
};

#endif


