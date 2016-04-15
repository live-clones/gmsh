// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _METRIC_BASIS_H_
#define _METRIC_BASIS_H_

#include <fstream>
#include <cmath>
#include "fullMatrix.h"
class MElement;
class bezierBasis;
class JacobianBasis;
class GradientBasis;

class MetricBasis {
  friend class MetricCoefficient;
  friend class GMSH_AnalyseCurvedMeshPlugin;

private:
  const JacobianBasis *_jacobian;
  const GradientBasis *_gradients;
  const bezierBasis *_bezier;
  static double _tol;
  const int _type, _dim;

  std::fstream file;

  class IneqData {
  public:
    int i, j, k;
    double val;

  public:
    IneqData(double val, int i, int j, int k = -1) : i(i), j(j), k(k), val(val) {}
  };

  std::map<int, std::vector<IneqData> > _ineqJ2, _ineqP3, _ineqA;

  class MetricData {
   public:
    fullMatrix<double> *_metcoeffs;
    fullVector<double> *_jaccoeffs;
    double _RminBez;
    int _depth, _num;

   public:
    MetricData(fullMatrix<double> *m, fullVector<double> *j,
               double r = -1, int d = -1, int num = -1) :
      _metcoeffs(m), _jaccoeffs(j), _RminBez(r), _depth(d), _num(num) {}
    ~MetricData() {
      delete _metcoeffs;
      delete _jaccoeffs;
    }

    bool haveJac() {return _jaccoeffs != NULL;}
  };

public:
  MetricBasis(int elementTag);

  // Get & Set methods
  static void setTol(double tol) {_tol = tol;}
  const JacobianBasis* getJacobianForMetric() const {return _jacobian;}
  const bezierBasis* getBezier() const {return _bezier;}
  //int getNumMetricNodes() const {return _gradients->getNumSamplingPoints();}

  // Compute min(R) with given tolerance
  static double getMinR(MElement *el);
  double computeMinR(MElement*) const;

  // Sample R and return min
  static double getMinSampledR(MElement *el, int order);
  double computeMinSampledR(MElement*, int order) const;

  // Compute R on corners and return min
  static double getMinRCorner(MElement *el);

  // TEST : sample min(r_min) and max(r_max) and return ratio of the two
  static double getMinSampledGlobalRatio(MElement *el, int order);
  double computeMinSampledGlobalRatio(MElement*, int order) const;

  // TEST : sample R and return max
  static double getMaxSampledR(MElement *el, int order);
  double computeMaxSampledR(MElement*, int order) const;


  //
  template<bool ideal>
  void getMetricCoeff(const fullMatrix<double> &nodes,
                            fullMatrix<double> &coeff) const {
    _fillCoeff<ideal>(_dim, _gradients, nodes, coeff);
  }
//  void lag2Bez(const fullMatrix<double> &metCoeffLag,
//                     fullMatrix<double> &metCoeffBez) const {
//    _bezier->matrixLag2Bez.mult(metCoeffLag, metCoeffBez);
//  }
  void lag2Bez(const fullMatrix<double> &metCoeffLag,
               fullMatrix<double> &metCoeffBez) const;

  // Metric order
  static int metricOrder(int tag);

public:
  // Validation for computation of Bezier coefficients & subdivision
  // of Jacobian determinant and Metric stuffs
  static bool validateBezierForMetricAndJacobian();
  static int validateBezierForMetricAndJacobian(MElement *el,
                                                int numSampPnt,
                                                int numSubdiv,
                                                double toleranceTensor,
                                                double tolerance);
  void statsForMatlab(MElement *el, int deg, MetricData *md) const;
  void interpolate(const MElement*, const MetricData*,
                   const fullMatrix<double> &nodes, fullMatrix<double> &R) const;
  void interpolateAfterNSubdivisions(const MElement *el,
                                     int numSubdiv, int numPnt,
                                     fullVector<int> &isub,
                                     fullMatrix<double> &uvw,
                                     fullMatrix<double> &metric) const;

private:
  void _fillInequalities(int order);
  void _fillInequalitiesPyr(int order);
  void _lightenInequalities(int&, int&, int&); //TODO change

  void _computeBoundsRmin(const fullMatrix<double>&, const fullVector<double>&,
                    double &RminLag, double &RminBez) const;
  void _computeBoundsRmax(const fullMatrix<double>&, const fullVector<double>&,
                    double &RmaxLag) const;
  void _getMetricData(const MElement*, MetricData*&) const;

  double _subdivideForRmin(MetricData*, double &RminLag, double tol, MElement *el=NULL) const;
  template<bool ideal>
  static void _fillCoeff(int dim, const GradientBasis*,
                  const fullMatrix<double> &nodes, fullMatrix<double> &coeff);
  static double _computeMinlagR(const fullVector<double> &jac,
                                const fullMatrix<double> &coeff, int num);

  void _minMaxA(const fullMatrix<double>&, double &min, double &max) const;
  void _minAfast(const fullMatrix<double>&, double &min) const;
  void _minKfast(const fullMatrix<double>&, const fullVector<double>&, double &min) const;
  void _minKsharp(const fullMatrix<double>&, const fullVector<double>&, double &min) const;
  void _computeBoundingCurve(const fullMatrix<double>&,
                             const fullVector<double>&,
                             double &beta, double c, bool lowerBound) const;
  void _computeLowerBoundC(const fullMatrix<double>&,
                           const fullVector<double>&,
                           double beta, double &c) const;

  static bool _moveInsideDomain(double &a, double &K, bool bottomleftCorner);
  static void _computePseudoDerivatives(double a, double K,
                                        double &dRda, double &dRdK);
  static void _computeDerivatives(double a, double K,
                                  double &dRda, double &dRdK,
                                  double &dRdaa, double &dRdaK, double &dRdKK);
  static double _computeMinRAlongCurve(double beta, double c,
                                       double mina, double maxa);
  static bool _intersectionCurveLeftCorner(double beta, double c,
                                           double &mina, double &minK);
  static double _computeAbscissaMinR(double aStart, double K);

  static double _R3Dsafe(double a, double K);
  static double _R3Dsafe(double q, double p, double J);
  static double _R2Dsafe(double a);
  static double _R2Dsafe(double q, double p);
  static inline double _w(double a, double K) {
    return .5 * (K + (3-a*a)*a);
  }
  static inline double _wSafe(double a, double K) {
    const double w = _w(a, K);
    if (w > 1) {
      if (w < 1+_tol/10) return 1;
      else Msg::Error("outside the domain w(%g, %g) = %g", a, K, w);
    }
    else if (w < -1) {
      if (w > -1-_tol/10) return -1;
      else Msg::Error("outside the domain w(%g, %g) = %g", a, K, w);
    }
    return w;
  }

  static double _toleranceOnR(double R);

private:
  class gterIneq {
   public:
    bool operator()(const IneqData &id1, const IneqData &id2) const {
      return id1.val > id2.val;
    }
  };
  struct lessMinB {
    bool operator()(const MetricData *md1, const MetricData *md2) const {
      return md1->_RminBez > md2->_RminBez;
    }
  };
};

#endif
