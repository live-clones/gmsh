// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _METRIC_BASIS_H_
#define _METRIC_BASIS_H_

#include "JacobianBasis.h"
#include "fullMatrix.h"
#include <fstream>
#include <cmath>
class MElement;

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

  static void setTol(double tol) {_tol = tol;}

  const JacobianBasis* getJacobianForMetric() const {return _jacobian;}
  const bezierBasis* getBezier() const {return _bezier;}
  int getNumMetricNodes() const {return _gradients->getNumSamplingPoints();}

  static double boundMinR(MElement *el);
  static double minSampledR(MElement *el, int order);
  double getBoundMinR(MElement*) const;
  double getMinSampledR(MElement*, int order) const;

  static double minRCorner(MElement *el);

  template<bool ideal>
  void getMetricCoeff(const fullMatrix<double> &nodes,
                            fullMatrix<double> &coeff) const {
    _fillCoeff<ideal>(_dim, _gradients, nodes, coeff);
  }
  void lag2Bez(const fullMatrix<double> &metCoeffLag,
                     fullMatrix<double> &metCoeffBez) const {
    _bezier->matrixLag2Bez.mult(metCoeffLag, metCoeffBez);
  }

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
  void interpolate(const MElement*, const MetricData*, const double *uvw, double *minmaxQ) const;
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

  void _computeRmin(const fullMatrix<double>&, const fullVector<double>&,
                    double &RminLag, double &RminBez) const;
  void _computeRmax(const fullMatrix<double>&, const fullVector<double>&,
                    double &RmaxLag) const;
  void _getMetricData(const MElement*, MetricData*&) const;

  double _subdivideForRmin(MetricData*, double RminLag, double tol, MElement *el=NULL) const;
  template<bool ideal>
  static void _fillCoeff(int dim, const GradientBasis*,
                  const fullMatrix<double> &nodes, fullMatrix<double> &coeff);
  static double _computeMinlagR(const fullVector<double> &jac,
                                const fullMatrix<double> &coeff, int num);

  void _minMaxA(const fullMatrix<double>&, double &min, double &max) const;
  void _minA(const fullMatrix<double>&, double &min) const;
  void _minK(const fullMatrix<double>&, const fullVector<double>&, double &min) const;
  void _computeTermBeta(double &a, double &K, double &dRda,
                        double &term1, double &phip) const;
  void _maxAstKpos(const fullMatrix<double>&, const fullVector<double>&,
                 double minK, double beta, double &maxa) const;
  void _maxAstKneg(const fullMatrix<double>&, const fullVector<double>&,
                 double minK, double beta, double &maxa) const;
  void _maxKstAfast(const fullMatrix<double>&, const fullVector<double>&,
                 double mina, double beta, double &maxK) const;
  void _maxKstAsharp(const fullMatrix<double>&, const fullVector<double>&,
                 double mina, double beta, double &maxK) const;

  static double _R3Dsafe(double a, double K);
  static double _R3Dsafe(double q, double p, double J);
  static double _R2Dsafe(double a);
  static double _R2Dsafe(double q, double p);

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
