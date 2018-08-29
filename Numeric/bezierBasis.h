// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BEZIER_BASIS_H
#define BEZIER_BASIS_H

#include <set>
#include <map>
#include <vector>
#include "fullMatrix.h"
#include "FuncSpaceData.h"
#include "BasisFactory.h"

class MElement;
class bezierBasisRaiser;
class bezierCoeff;

class bezierBasis {
private:
  // the 'numLagCoeff' first exponents are related to 'real' values
  int _numLagCoeff;
  int _numDivisions, _dimSimplex;
  const FuncSpaceData _data;
  bezierBasisRaiser *_raiser;

  friend class bezierBasisRaiser;
  fullMatrix<double> _exponents;

public:
  fullMatrix<double> matrixLag2Bez;
  fullMatrix<double> matrixBez2Lag;
  fullMatrix<double> subDivisor;

  // Constructors
  bezierBasis(FuncSpaceData data);
  ~bezierBasis();

  // get methods
  inline int getDim() const { return _exponents.size2(); }
  inline int getType() const { return _data.elementType(); }
  inline int getOrder() const { return _data.spaceOrder(); }
  inline int getDimSimplex() const { return _dimSimplex; }
  inline int getNumCoeff() const { return _exponents.size1(); }
  inline int getNumLagCoeff() const { return _numLagCoeff; }
  inline int getNumDivision() const { return _numDivisions; }
  inline int getNumSubNodes() const { return subDivisor.size1(); }
  inline FuncSpaceData getFuncSpaceData() const { return _data; }
  bezierBasisRaiser *getRaiser() const;

  // Evaluate Bezier functions at the point (u, v, w)
  void f(double u, double v, double w, double *sf) const;

  // generate Bezier points
  void generateBezierPoints(fullMatrix<double> &) const;

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
                   const fullMatrix<double> &uvw, fullMatrix<double> &result,
                   bool bezCoord = false) const;
  void interpolate(const fullVector<double> &coeffs,
                   const fullMatrix<double> &uvw, fullVector<double> &result,
                   bool bezCoord = false) const
  {
    int size = uvw.size1();
    result.resize(size);
    fullMatrix<double> c(const_cast<double *>(coeffs.getDataPtr()), size, 1);
    fullMatrix<double> r(const_cast<double *>(result.getDataPtr()), size, 1);
    interpolate(c, uvw, r, bezCoord);
  }

private:
  void _construct();
  void _constructPyr();
  void _fePoints2BezPoints(fullMatrix<double> &) const;
};

class bezierBasisRaiser {
  // Let f, g, h be three function whose Bezier coefficients are given.
  // This class allows to compute the Bezier coefficients of f*g and f*g*h.
private:
  class _data {
    friend class bezierBasisRaiser;

  private:
    int i, j, k;
    double val;

  public:
    _data(double vv, int ii, int jj = -1, int kk = -1)
      : i(ii), j(jj), k(kk), val(vv)
    {
    }
  };
  std::vector<std::vector<_data> > _raiser2, _raiser3;
  const bezierBasis *_bfs;

public:
  bezierBasisRaiser(const bezierBasis *bezier) : _bfs(bezier)
  {
    _fillRaiserData();
  };

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
  void computeCoeff(const fullVector<double> &coeffA,
                    const fullMatrix<double> &coeffB,
                    const fullMatrix<double> &coeffC,
                    fullMatrix<double> &coeffCubic);

private:
  void _fillRaiserData();
  void _fillRaiserDataPyr();
};

//class bezierCoeffSubdivisor {
//  // Two type of operation are perform for subdividing simplices:
//  // 1) [ coeff(I) + coeff(Ib) ] / 2     :> coeff(I)
//  // 2) coeff(Ia) + coeff(Ib) - coeff(I) :> coeff(I)
//  typedef std::vector<std::pair<int, int> >  data1;
//  typedef std::vector<std::pair<int, std::pair<int, int> > >  data2;
//
//  struct {
//    data1 subdivideU;
//    data1 subdivideV;
//    data2 return2;
//  };
//
//private:
//  // mapTri (order) -> list (data1 or data2)
//
//
//  static std::map<int, data1> _triangleSubU;
//  static std::map<int, data1> _triangleSubV;
//  static std::map<int, data1> _triangleSubV;
//  static std::map<int, data1> _triangleSubV;
//  static std::map<int, data1> _triangleSubV;
//};

class bezierMemoryPool {
  // This class is to avoid multiple allocation / deallocation during
  // the subdivision algorithm.
private:
  std::vector<double> _memory;
  int _sizeBlocks;
  int _numUsedBlocks;
  unsigned int _currentIndexOfSearch;
  unsigned int _endOfSearch;
  // if a reallocation is performed, the pointers must be updated, we need to
  // know which bezierCoeff have to be updated:
  std::vector<bezierCoeff*> _bezierCoeff;

public:
  bezierMemoryPool();
  ~bezierMemoryPool() {}

  // before to be used, the size of the blocks has to be specified
  void setSizeBlocks(int size);

  double* giveBlock(bezierCoeff *bez); // gives a block of size _sizeBlocks[num]
  void releaseBlock(double *block, bezierCoeff *bez);
  void freeMemory();

private:
  void _checkEnoughMemory();
};

class bezierCoeff {
  // TODO: test if access would be faster if fullMatrix::operator(int r) was
  // implemented (for fullmatrix with only 1 column)
//  typedef std::vector<std::pair<int, int> >  data1;
//  typedef std::vector<std::pair<int, std::pair<int, int> > >  data2;
//  // map (type, order, num) -> (data1 or data2)
//  static std::map<int, data1> _triangleSubU;
//  static std::map<int, data1> _triangleSubV;

private :
  int _numPool;
  FuncSpaceData _funcSpaceData;
  const bezierBasis *_basis;
  bool _own_data; // should data be freed on delete ?
  int _r, _c; // size of the matrix
  double *_data; // pointer on the first element

  static bezierMemoryPool *_pool0;
  static bezierMemoryPool *_pool1;
  static fullMatrix<double> _sub;
  // FIXME: not thread safe. We shoud use one pool and one _sub per thread.
  //        The best would be to give the pool to the constructor.
  //        (the pools should be created and deleted e.g. by the plugin
  //        AnalyseCurvedMesh)

public:
  bezierCoeff() {};
  bezierCoeff(const bezierCoeff &other, bool swap = false);
  bezierCoeff(FuncSpaceData data, fullVector<double> &lagCoeff, int num = -1);
  bezierCoeff(FuncSpaceData data, fullMatrix<double> &lagCoeff, int num = -1);
  ~bezierCoeff();

  static void usePools(int size0, int size1);
  static void releasePools();
  void updateDataPtr(long diff);

  inline int getNumCoeff() {return _basis->getNumCoeff();}
  inline int getNumLagCoeff() {return _basis->getNumLagCoeff();}
//  inline double getLagCoeff(int i) {
//    switch (_funcSpaceData.elementType()) {
//
//    }
//  }

  void subdivide(std::vector<bezierCoeff> &subCoeff);

  inline double operator() (int i, int j) const
  {
    return _data[i + _r*j];
  }
  inline double &operator() (int i, int j)
  {
    return _data[i + _r*j];
  }

private:
  static void _subdivide(fullMatrix<double> &coeff, int n, int start);
  static void _subdivide(fullMatrix<double> &coeff, int n, int start, int inc);
  static void _subdivideTriangle(bezierCoeff &coeff, int n,
                                 int start,
                                 std::vector<bezierCoeff> &subCoeff);
  static void _subdivideTetrahedra(bezierCoeff &coeff, int n,
                                   int start,
                                   std::vector<fullMatrix<double> > &subCoeff);
  static void _subdivideQuadrangle(const bezierCoeff &coeff, int n,
                                   std::vector<bezierCoeff> &subCoeff);
  static void _copy(const bezierCoeff &from, int start, int num,
                    bezierCoeff &to);
  static void _copyQuad(const fullMatrix<double> &allSub, int starti,
                        int startj, int n, bezierCoeff &sub);
  inline static int _ij2Index(int i, int j, int n) {
    return i + j*n - j*(j-1)/2;
  }

};

#endif
