// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
  // Number of corner coeff which are 'real' values of the expanded function
  int _numLagCoeff;
  int _dimSimplex;
  const FuncSpaceData _funcSpaceData;
  bezierBasisRaiser *_raiser;
  fullMatrix<double> _exponents;
  fullMatrix<double> matrixLag2Bez;
  fullVector<double> ordered1dBezPoints;

  friend class bezierBasisRaiser;
  friend class bezierCoeff;

public:
  // Constructors
  bezierBasis(FuncSpaceData data);
  ~bezierBasis();

  // get methods
  inline int getDim() const { return _exponents.size2(); }
  inline int getType() const { return _funcSpaceData.getType(); }
  inline int getOrder() const { return _funcSpaceData.getSpaceOrder(); }
  inline int getDimSimplex() const { return _dimSimplex; }
  inline int getNumLagCoeff() const { return _numLagCoeff; }
  inline FuncSpaceData getFuncSpaceData() const { return _funcSpaceData; }
  const bezierBasisRaiser *getRaiser() const;

private:
  void _construct();
  void _constructPyr();
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
                    fullVector<double> &coeffSquare) const;
  void computeCoeff(const fullVector<double> &coeffA,
                    const fullVector<double> &coeffB,
                    const fullVector<double> &coeffC,
                    fullVector<double> &coeffCubic) const;

private:
  void _fillRaiserData();
  void _fillRaiserDataPyr();
};

class bezierCoeffMemoryPool {
  // This class is to avoid multiple allocation / deallocation during
  // the subdivision algorithm.
private:
  std::vector<double> _memory;
  std::size_t _sizeBlocks;
  std::size_t _numUsedBlocks;
  std::size_t _currentIndexOfSearch;
  std::size_t _endOfSearch;
  // if a reallocation is performed, the pointers must be updated, we need to
  // know which bezierCoeff have to be updated:
  std::vector<bezierCoeff *> _bezierCoeff;

public:
  bezierCoeffMemoryPool();
  ~bezierCoeffMemoryPool() {}

  // before to be used, the size of the blocks has to be specified
  void setSizeBlocks(std::size_t size);

  double *giveBlock(bezierCoeff *bez); // gives a block of size _sizeBlocks[num]
  void releaseBlock(double *block, bezierCoeff *bez);
  void freeMemory();

private:
  void _checkEnoughMemory();
};

class bezierCoeff {
private:
  int _numPool;
  FuncSpaceData _funcSpaceData;
  const bezierBasis *_basis;
  int _r, _c; // size of the matrix
  double *_data; // pointer on the first element
  bool _ownData; // to know if data should be freed when object is deleted

  static bezierCoeffMemoryPool *_pool0;
  static bezierCoeffMemoryPool *_pool1;
  static fullMatrix<double> _sub;
  // FIXME: not thread safe. We shoud use one pool and one _sub per thread.
  //        The best would be to give the pool to the constructor.
  //        (the pools should be created and deleted e.g. by the plugin
  //        AnalyseMeshQuality)

public:
  bezierCoeff(){};
  bezierCoeff(const bezierCoeff &other, bool swap = false);
  // numOfPool is the number of the pool (0 or 1) that should be used. To use
  // this functionality, first call usePools(..) function.
  bezierCoeff(FuncSpaceData data, const fullVector<double> &lagCoeff,
              int numOfPool = -1);
  bezierCoeff(FuncSpaceData data, const fullMatrix<double> &lagCoeff,
              int numOfPool = -1);
  ~bezierCoeff();

  static void usePools(std::size_t size0, std::size_t size1);
  static void releasePools();
  void updateDataPtr(long diff);

  inline int getPolynomialOrder() const
  {
    return _funcSpaceData.getSpaceOrder();
  }
  inline int getNumCoeff() const { return _r; }
  inline int getNumColumns() const { return _c; }
  inline int getNumCornerCoeff() const { return _basis->getNumLagCoeff(); }
  int getIdxCornerCoeff(int i) const;
  inline double getCornerCoeff(int k) const
  {
    return _data[getIdxCornerCoeff(k)];
  }
  inline double getCornerCoeff(int k, int j) const
  {
    return _data[getIdxCornerCoeff(k) + _r * j];
  }
  void getCornerCoeffs(fullVector<double> &) const;
  void getCornerCoeffs(fullMatrix<double> &) const;
  inline double *getDataPtr() { return _data; }
  inline const bezierBasis *getBezierBasis() const { return _basis; }

  inline void setMatrixAsProxy(fullMatrix<double> &m) const
  {
    m.setAsProxy(_data, _r, _c);
  }
  inline void setVectorAsProxy(fullVector<double> &v) const
  {
    v.setAsProxy(_data, _r);
  }

  void subdivide(std::vector<bezierCoeff *> &subCoeff) const;

  inline double operator()(int i) const { return _data[i]; }
  inline double operator()(int i, int j) const { return _data[i + _r * j]; }

  inline double &operator()(int i) { return _data[i]; }
  inline double &operator()(int i, int j) { return _data[i + _r * j]; }

private:
  enum _SubdivisionTet {
    subdivU,
    subdivV,
    subdivW,
    node0CrossEdge12,
    node3CrossEdge12,
    node1CrossEdge03,
    node2CrossEdge03
  };
  static void _subdivideTet(_SubdivisionTet which, int n, bezierCoeff &coeff);

  static void _subdivide(fullMatrix<double> &coeff, int npts, int start);
  static void _subdivide(fullMatrix<double> &coeff, int npts, int start,
                         int inc);
  static void _subdivideTriangle(const bezierCoeff &coeff, int start,
                                 std::vector<bezierCoeff *> &subCoeff);
  static void _subdivideTetrahedron(const bezierCoeff &coeff,
                                    std::vector<bezierCoeff *> &vSubCoeff);
  static void _subdivideQuadrangle(const bezierCoeff &coeff,
                                   std::vector<bezierCoeff *> &subCoeff);
  static void _subdivideHexahedron(const bezierCoeff &coeff,
                                   std::vector<bezierCoeff *> &subCoeff);
  static void _subdividePrism(const bezierCoeff &coeff,
                              std::vector<bezierCoeff *> &subCoeff);
  static void _subdividePyramid(const bezierCoeff &coeff,
                                std::vector<bezierCoeff *> &subCoeff);
  static void _copy(const bezierCoeff &from, int start, int num,
                    bezierCoeff &to);
  static void _copyLine(const fullMatrix<double> &allSub, int n, int starti,
                        bezierCoeff &sub);
  static void _copyQuad(const fullMatrix<double> &allSub, int n, int starti,
                        int startj, bezierCoeff &sub);
  static void _copyHex(const fullMatrix<double> &allSub, int n, int starti,
                       int startj, int startk, bezierCoeff &sub);
  static void _copyPyr(const fullMatrix<double> &allSub, int nij, int nk,
                       int starti, int startj, int startk, bezierCoeff &sub);
  inline static int _ij2Index(int i, int j, int n)
  {
    return i + j * n - j * (j - 1) / 2;
  }
  inline static int _ijk2Index(int i, int j, int k, int n)
  {
    // the whole tet - the top tet + current triangle
    return (n + 2) * (n + 1) * n / 6 - (n - k + 2) * (n - k + 1) * (n - k) / 6 +
           j * (n - k) - j * (j - 1) / 2 + i;
  }
  void _computeCoefficients(const double *lagCoeffData);
};

#endif
