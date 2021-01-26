// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef QUALITY_MEASURES_JACOBIAN_H
#define QUALITY_MEASURES_JACOBIAN_H

#include <stdio.h>
#include <vector>

class bezierCoeff;
class MElement;
template <class scalar> class fullVector;
template <class scalar> class fullMatrix;

namespace jacobianBasedQuality {

  void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                                 const fullMatrix<double> *normals = nullptr,
                                 bool debug = false);
  double minIGEMeasure(MElement *el, bool knownValid = false,
                       bool reversedOk = false,
                       const fullMatrix<double> *normals = nullptr,
                       bool debug = false);
  double minICNMeasure(MElement *el, bool knownValid = false,
                       bool reversedOk = false,
                       const fullMatrix<double> *normals = nullptr,
                       bool debug = false);
  void sampleJacobianDeterminant(MElement *el, int order, double &min,
                                 double &max,
                                 const fullMatrix<double> *normals = nullptr);
  void sampleIGEMeasure(MElement *el, int order, double &min, double &max);
  void sampleICNMeasure(MElement *el, int order, double &min, double &max);
  void sampleJacobianDeterminant(MElement *el, int order,
                                 fullVector<double> &jac,
                                 const fullMatrix<double> *normals = nullptr);
  void sampleIGEMeasure(MElement *el, int order, fullVector<double> &ige);
  void sampleICNMeasure(MElement *el, int order, fullVector<double> &icn);

  // For regression tests:
  void testAllMeasuresAllElements();
  void testAllMeasures(MElement *el,
                       const fullMatrix<double> *normals = nullptr);

  class _coeffData {
  protected:
    double _minL, _maxL; // Extremum of measure at corners
    double _minB, _maxB; // Extremum of measure

  public:
    _coeffData() : _minL(0), _maxL(0), _minB(0), _maxB(0) {}
    virtual ~_coeffData() {}

    inline double minL() const { return _minL; }
    inline double maxL() const { return _maxL; }
    inline double minB() const { return _minB; }
    inline double maxB() const { return _maxB; }

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
    const bezierCoeff *_coeffs;

  public:
    _coeffDataJac(const bezierCoeff *coeffs);
    ~_coeffDataJac() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coeffData *> &) const;
    void deleteBezierCoeff();
  };

  class _coeffDataIGE : public _coeffData {
  private:
    const bezierCoeff *_coeffDet;
    const bezierCoeff *_coeffMat;
    const int _type;

  public:
    _coeffDataIGE(int type, const bezierCoeff *det, const bezierCoeff *mat);
    ~_coeffDataIGE() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coeffData *> &) const;
    void deleteBezierCoeff();

  private:
    void _computeAtCorner(double &min, double &max) const;
    double _computeLowerBound() const;
  };

  class _coeffDataICN : public _coeffData {
  private:
    const bezierCoeff *_coeffDet;
    const bezierCoeff *_coeffMat;
    const int _dim;

  public:
    _coeffDataICN(int dim, const bezierCoeff *det, const bezierCoeff *mat);
    ~_coeffDataICN() {}

    bool boundsOk(double minL, double maxL) const;
    void getSubCoeff(std::vector<_coeffData *> &) const;
    void deleteBezierCoeff();

  private:
    void _computeAtCorner(double &min, double &max) const;
    double _computeLowerBound() const;
  };

  double _computeBoundRational(const fullVector<double> &numerator,
                               const fullVector<double> &denominator,
                               bool lower, bool positiveDenom = true);

  void _subdivideDomains(std::vector<_coeffData *> &domains,
                         bool alsoMax = true, bool debug = false);
  double _getMinAndDeleteDomains(std::vector<_coeffData *> &domains);

} // namespace jacobianBasedQuality

#endif
