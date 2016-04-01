// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _BEZIER_BASIS_H_
#define _BEZIER_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"
#include "FuncSpaceData.h"

class MElement;
class bezierBasisRaiser;

class bezierBasis {
 private :
  // the 'numLagCoeff' first exponents are related to 'real' values
  int _numLagCoeff;
  int _numDivisions, _dimSimplex;
  const FuncSpaceData _data;
  bezierBasisRaiser *_raiser;

  friend class MetricBasis;
  friend class bezierBasisRaiser;
  fullMatrix<double> _exponents;

 public :
  fullMatrix<double> matrixLag2Bez;
  fullMatrix<double> matrixBez2Lag;
  fullMatrix<double> subDivisor;

  // Constructors
  inline bezierBasis(FuncSpaceData data) : _data(data), _raiser(NULL) {
    if (_data.elementType() == TYPE_PYR)
      _constructPyr();
    else
      _construct();
  }

  // get methods
  inline int getDim() const {return _exponents.size2();}
  inline int getType() const {return _data.elementType();}
  inline int getOrder() const {return _data.spaceOrder();}
  inline int getDimSimplex() const {return _dimSimplex;}
  inline int getNumLagCoeff() const {return _numLagCoeff;}
  inline int getNumDivision() const {return _numDivisions;}
  inline int getNumSubNodes() const {return subDivisor.size1();}
  inline FuncSpaceData getFuncSpaceData() const {return _data;}
  bezierBasisRaiser* getRaiser() const;

  // generate Bezier points
  void generateBezierPoints(fullMatrix<double>&) const;

  // transform coeff Lagrange into Bezier coeff
  void lag2Bez(const fullMatrix<double> &lag, fullMatrix<double> &bez) const;

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

class bezierBasisRaiser {
  // Let f, g, h be three function whose Bezier coefficients are given.
  // This class allows to compute the Bezier coefficients of f*g and f*g*h.
private :
  class _Data {
    friend class bezierBasisRaiser;
  private:
    int i, j, k;
    double val;
  public:
    _Data(double vv, int ii, int jj = -1, int kk = -1) :
      i(ii), j(jj), k(kk), val(vv) {}
  };
  std::map<int, std::vector<_Data> > _raiser1, _raiser2, _raiser3;
  const bezierBasis *_bfs;

public:
  bezierBasisRaiser(const bezierBasis *bezier) : _bfs(bezier) {
    _fillRaiserData();
  };

  // Warning: Those method return a vector or a matrix of Bezier coefficients
  // that are not stocked in the same order than what is expected as input.
  void computeCoeff(const fullVector<double> &coeffA,
                    const fullVector<double> &coeffB,
                    fullVector<double> &coeffSquare);
  void computeCoeff(const fullMatrix<double> &coeffA,
                    const fullMatrix<double> &coeffB,
                    fullMatrix<double> &coeffSquare);
  void computeCoeff(const fullVector<double> &coeffA,
                    const fullVector<double> &coeffB,
                    const fullVector<double> &coeffC,
                    fullVector<double> &coeffCubic);
  void computeCoeff(const fullMatrix<double> &coeffA,
                    const fullMatrix<double> &coeffB,
                    const fullMatrix<double> &coeffC,
                    fullMatrix<double> &coeffCubic);

  // Method returning a vector/matrix whose coeff are in the order defined in
  // this class:
  void reorder(const fullVector<double> &orig,
               fullVector<double> &reordered);
  void reorder(const fullMatrix<double> &orig,
               fullMatrix<double> &reordered);

private:
  void _fillRaiserData();
  void _fillRaiserDataPyr();
};


#endif


