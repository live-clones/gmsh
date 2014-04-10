// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _METRIC_BASIS_H_
#define _METRIC_BASIS_H_

#include "MElement.h"
#include "JacobianBasis.h"
#include "fullMatrix.h"

class MetricCoefficient {
private:
  class MetricData {
   public:
    fullMatrix<double> *_metcoeffs;
    fullVector<double> *_jaccoeffs;
    double _RminBez;
    int _depth;

   public:
    MetricData(fullMatrix<double> *m, fullVector<double> *j, double r, int d) :
      _metcoeffs(m), _jaccoeffs(j), _RminBez(r), _depth(d) {}
    ~MetricData() {
      delete _metcoeffs;
      delete _jaccoeffs;
    }
  };
  struct lessMinB {
    bool operator()(const MetricData *md1, const MetricData *md2) const {
      return md1->_RminBez > md2->_RminBez;
    }
  };

  class IneqData {
   public:
    int i, j, k;
    double val;

   public:
    IneqData(double val, int i, int j, int k = -1) : i(i), j(j), k(k), val(val) {}
  };
  class gterIneq {
   public:
    bool operator()(const IneqData &id1, const IneqData &id2) const {
      return id1.val > id2.val;
    }
  };

 private:
  MElement *_element;
  const JacobianBasis *_jacobian;
  const GradientBasis *_gradients;
  const bezierBasis *_bezier;
  fullMatrix<double> _coefficientsLag, _coefficientsBez;
  fullMatrix<double> _inequations;
  std::vector<std::map<std::pair<int, int>, double> > _ineq2; //TODO : pas top
  std::map<int, std::vector<IneqData> > _ineqJ2, _ineqP3;
  int __maxdepth, __numSubdivision;
  std::vector<int> __numSub;

 public:
  MetricCoefficient(MElement*);

  void getCoefficients(fullMatrix<double>&, bool bezier = true);
  void interpolate(const double *uvw, double *minmaxQ);
  double getBoundRmin(double tol, int which);

  static int metricOrder(int tag);

 private:
  void _computeBezCoeff();
  void _fillInequalities(int order);
  int _lightenInequalities(double, double, int&, int&); //TODO change
  void _interpolateBezierPyramid(const double *uvw, double *minmaxQ);
  void _computeRmin1(fullMatrix<double>&, fullVector<double>&,
                    double &RminLag, double &RminBez, int) const;
  void _computeRmin2(fullMatrix<double>&, fullVector<double>&,
                    double &RminLag, double &RminBez, int depth, int which) const;
  double _subdivideForRmin(MetricData*, double RminLag, double tol, int which) const;
  double _minp(const fullMatrix<double>&) const;
  double _minq(const fullMatrix<double>&) const;
  double _maxp(const fullMatrix<double>&) const;
  double _maxq(const fullMatrix<double>&) const;
  void _minMaxA(const fullMatrix<double>&, double &min, double &max) const;
  void _minMaxA2(const fullMatrix<double>&, double &min, double &max) const;
  void _minMaxJacobianSqr(const fullVector<double>&, double &min, double &max) const;
  void _minJ2P3(const fullMatrix<double>&, const fullVector<double>&, double &min) const;
};

#endif
