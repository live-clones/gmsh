// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef QUALITY_MEASURES_JACOBIAN_H
#define QUALITY_MEASURES_JACOBIAN_H

#include <vector>
#include "fullMatrix.h"

class GradientBasis;
class bezierBasis;
class bezierCoeff;
class MElement;

namespace jacobianBasedQuality {

  void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                                 const fullMatrix<double> *normals = NULL,
                                 bool debug = false);
  double minIGEMeasure(MElement *el, bool knownValid = false,
                       bool reversedOk = false,
                       const fullMatrix<double> *normals = NULL,
                       bool debug = false);
  double minICNMeasure(MElement *el, bool knownValid = false,
                       bool reversedOk = false,
                       const fullMatrix<double> *normals = NULL,
                       bool debug = false);
  void sampleJacobianDeterminant(MElement *el, int order, double &min,
                                 double &max,
                                 const fullMatrix<double> *normals = NULL);
  void sampleIGEMeasure(MElement *el, int order, double &min, double &max);
  void sampleICNMeasure(MElement *el, int order, double &min, double &max);
  void sampleJacobianDeterminant(MElement *el, int order,
                                 fullVector<double> &jac,
                                 const fullMatrix<double> *normals = NULL);
  void sampleIGEMeasure(MElement *el, int order, fullVector<double> &ige);
  void sampleICNMeasure(MElement *el, int order, fullVector<double> &icn);

  // For regression tests:
  void testAllMeasuresAllElements();
  void testAllMeasures(MElement *el, const fullMatrix<double> *normals = NULL);

  class _coeffData {
  protected:
    // FIXME renames
    double _minL2, _maxL2; // Extremum of measure at corners
    double _minB2, _maxB2; // Extremum of measure

  public:
    _coeffData() : _minL2(0), _maxL2(0), _minB2(0), _maxB2(0) {}
    virtual ~_coeffData() {}

    // FIXME renames
    inline double minL2() const { return _minL2; }
    inline double maxL2() const { return _maxL2; }
    inline double minB2() const { return _minB2; }
    inline double maxB2() const { return _maxB2; }

    virtual bool boundsOk(double minL, double maxL) const = 0;
    virtual void getSubCoeff(std::vector<_coeffData *> &) const = 0;
    virtual void deleteBezierCoeff() = 0;
  };

  struct _lessMinB {
    bool operator()(_coeffData *, _coeffData *) const;
  };
  struct _lessMaxB {
    bool operator()(_coeffData *, _coeffData *) const;
  };

  class _coeffDataJac : public _coeffData {
  private:
    // FIXME renames
    const bezierCoeff *_coeffs2;

  public:
    // FIXME renames
    _coeffDataJac(const bezierCoeff *coeffs2);
    ~_coeffDataJac() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coeffData *> &) const;
    void deleteBezierCoeff();
  };

  class _coeffDataIGE : public _coeffData {
  private:
    // FIXME renames
    const bezierCoeff *_coeffDet2;
    const bezierCoeff *_coeffMat2;
    const int _type;

  public:
    // FIXME renames
    _coeffDataIGE(int type, const bezierCoeff *det2, const bezierCoeff *mat2);
    ~_coeffDataIGE() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coeffData *> &) const;
    void deleteBezierCoeff();

  private:
    void _computeAtCorner(double &min, double &max) const;
    double _computeLowerBound2() const; // FIXME rename
  };

  class _coeffDataICN : public _coeffData {
  private:
    // FIXME renames
    const bezierCoeff *_coeffDet2;
    const bezierCoeff *_coeffMat2;
    const int _dim;

  public:
    // FIXME renames
    _coeffDataICN(int dim, const bezierCoeff *det2, const bezierCoeff *mat2);
    ~_coeffDataICN() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coeffData *> &) const;
    void deleteBezierCoeff();

  private:
    void _computeAtCorner(double &min, double &max) const;
    double _computeLowerBound2() const; // FIXME rename
  };

  double _computeBoundRational(const fullVector<double> &numerator,
                               const fullVector<double> &denominator,
                               bool lower, bool positiveDenom = true);

  void _subdivideDomains(std::vector<_coeffData *> &domains,
                         bool alsoMax = true, bool debug = false);
  double _getMinAndDeleteDomains(std::vector<_coeffData *> &domains);

} // namespace jacobianBasedQuality

#endif
