// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef QUALITY_MEASURES_JACOBIAN_H
#define QUALITY_MEASURES_JACOBIAN_H

#include <vector>
#include "fullMatrix.h"
#include "bezierBasis.h"

class GradientBasis;
// class bezierBasis;
// class bezierCoeff;
class MElement;

namespace jacobianBasedQuality {

  void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                                 const fullMatrix<double> *normals = NULL);
  double minIGEMeasure(MElement *el, bool knownValid = false,
                       bool reversedOk = false,
                       const fullMatrix<double> *normals = NULL);
  double minICNMeasure(MElement *el, bool knownValid = false,
                       bool reversedOk = false,
                       const fullMatrix<double> *normals = NULL);
  void sampleIGEMeasure(MElement *el, int order, double &min, double &max);
  void sampleICNMeasure(MElement *el, int order, double &min, double &max);
  void sampleJacobian(MElement *el, int order, fullVector<double> &jac,
                      const fullMatrix<double> *normals = NULL);
  void sampleIGEMeasure(MElement *el, int order, fullVector<double> &ige);
  void sampleICNMeasure(MElement *el, int order, fullVector<double> &icn);

  class _coefData {
  protected:
    double _minL, _maxL; // Extremum of Jac at corners
    double _minB, _maxB; // Extremum of bezier coefficients
    double _minL2, _maxL2; // Extremum of Jac at corners
    double _minB2, _maxB2; // Extremum of bezier coefficients
    const int _depth;

  public:
    _coefData(int depth)
      : _minL(0), _maxL(0), _minB(0), _maxB(0), _depth(depth)
    {
    }
    virtual ~_coefData() {}

    inline double minL() const { return _minL; }
    inline double maxL() const { return _maxL; }
    inline double minB() const { return _minB; }
    inline double maxB() const { return _maxB; }
    inline double minL2() const { return _minL2; }
    inline double maxL2() const { return _maxL2; }
    inline double minB2() const { return _minB2; }
    inline double maxB2() const { return _maxB2; }
    inline int depth() const { return _depth; }

    virtual bool boundsOk(double minL, double maxL) const = 0;
    virtual void getSubCoeff(std::vector<_coefData *> &) const = 0;
    virtual void deleteBezierCoeff() = 0;
    virtual int getNumMeasure() const { return 0; } // fordebug
  };

  struct _lessMinB {
    bool operator()(_coefData *, _coefData *) const;
  };
  struct _lessMaxB {
    bool operator()(_coefData *, _coefData *) const;
  };

  class _coefDataJac : public _coefData {
  private:
    const fullVector<double> _coeffs;
    const bezierBasis *_bfs;
    const bezierCoeff *_coeffs2;

  public:
    _coefDataJac(fullVector<double> &v, const bezierBasis *bfs, int depth,
                  const bezierCoeff *coeffs2 = NULL);
    ~_coefDataJac() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coefData *> &) const;
    void deleteBezierCoeff() { delete _coeffs2; }
    int getNumMeasure() const { return 1; } // fordebug
  };

  class _coefDataIGE : public _coefData {
  private:
    const fullVector<double> _coeffsJacDet;
    const fullMatrix<double> _coeffsJacMat;
    const bezierCoeff *_coeffDet2;
    const bezierCoeff *_coeffMat2;
    const bezierBasis *_bfsDet, *_bfsMat;
    const int _type;

  public:
    _coefDataIGE(fullVector<double> &det, fullMatrix<double> &mat,
                  const bezierBasis *bfsDet, const bezierBasis *bfsMat,
                  int depth, int type, const bezierCoeff *det2 = NULL,
                  const bezierCoeff *mat2 = NULL);
    ~_coefDataIGE() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coefData *> &) const;
    void deleteBezierCoeff()
    {
      delete _coeffDet2;
      delete _coeffMat2;
    }
    int getNumMeasure() const { return 2; } // fordebug

  private:
    void _computeAtCorner(double &min, double &max, double &min2,
                          double &max2) const;
    double _computeLowerBound() const;
    double _computeLowerBound2() const;
  };

  class _coefDataICN : public _coefData {
  private:
    const fullVector<double> _coeffsJacDet;
    const fullMatrix<double> _coeffsJacMat;
    const bezierCoeff *_coeffDet2;
    const bezierCoeff *_coeffMat2;
    const bezierBasis *_bfsDet, *_bfsMat;
    const int _dim;

  public:
    _coefDataICN(fullVector<double> &det, fullMatrix<double> &metric,
                  const bezierBasis *bfsDet, const bezierBasis *bfsMet,
                  int depth, int dim, const bezierCoeff *det2 = NULL,
                  const bezierCoeff *mat2 = NULL);
    ~_coefDataICN() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coefData *> &) const;
    void deleteBezierCoeff() {} // delete _coeffDet2; delete _coeffMat2;}
    int getNumMeasure() const { return 4; } // fordebug

  private:
    void _computeAtCorner(double &min, double &max, double &min2,
                          double &max2) const;
    double _computeLowerBound() const;
    double _computeLowerBound2() const;
  };

  double _computeBoundRational(const fullVector<double> &numerator,
                               const fullVector<double> &denominator,
                               bool lower, bool positiveDenom = true);

  void _subdivideDomains(std::vector<_coefData *> &domains);
  double _getMinAndDeleteDomains(std::vector<_coefData *> &domains);

} // namespace jacobianBasedQuality

#endif
