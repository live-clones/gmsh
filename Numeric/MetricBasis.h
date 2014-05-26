// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _METRIC_BASIS_H_
#define _METRIC_BASIS_H_

#include "MElement.h"
#include "JacobianBasis.h"
#include "fullMatrix.h"
#include <fstream>

class MetricBasis {
  friend class MetricCoefficient;
  friend class GMSH_AnalyseCurvedMeshPlugin;
private:
  const JacobianBasis *_jacobian;
  const GradientBasis *_gradients;
  const bezierBasis *_bezier;
  static double _tol;
  static int _which;

  int __maxdepth, __numSubdivision;
  std::vector<int> __numSub;
  MElement *__curElem;

  std::fstream file;

  class IneqData {
  public:
    int i, j, k;
    double val;

  public:
    IneqData(double val, int i, int j, int k = -1) : i(i), j(j), k(k), val(val) {}
  };

  class MetricData {
   public:
    fullMatrix<double> *_metcoeffs;
    fullVector<double> *_jaccoeffs;
    double _RminBez;
    int _depth, _num;

   public:
    MetricData(fullMatrix<double> *m, fullVector<double> *j, double r, int d, int num) :
      _metcoeffs(m), _jaccoeffs(j), _RminBez(r), _depth(d), _num(num) {}
    ~MetricData() {
      delete _metcoeffs;
      delete _jaccoeffs;
    }
  };

  std::map<int, std::vector<IneqData> > _ineqJ2, _ineqP3, _ineqA;

public:
  MetricBasis(int elementTag);

  static void setTol(double tol) {_tol = tol;}
  static double getTol() {return _tol;}
  static void setWhich(int which) {_which = which;}

  double getBoundRmin(const MElement*, MetricData*&, fullMatrix<double>&) const;
  double getMinR(const MElement*, MetricData*&, int) const;
  static double boundRmin(const MElement *el);
  //double getBoundRmin(int, MElement**, double*);
  //static double boundRmin(int, MElement**, double*, bool sameType = false);

  void interpolate(const MElement*, const MetricData*, const double *uvw, double *minmaxQ, bool write = false) const;

  static int metricOrder(int tag);

private:
  void _fillInequalities(int order);
  void _lightenInequalities(int&, int&, int&); //TODO change

  void _computeRmin1(const fullMatrix<double>&, const fullVector<double>&,
                    double &RminLag, double &RminBez, int) const;
  void _computeRmin2(const fullMatrix<double>&, const fullVector<double>&,
                    double &RminLag, double &RminBez, int depth, int which) const;
  void _computeRmin3(const fullMatrix<double>&, const fullVector<double>&,
                    double &RminLag, double &RminBez, int depth, bool debug = false) const;

  double _subdivideForRmin(MetricData*, double RminLag, double tol, int which) const;

  double _minp(const fullMatrix<double>&) const;
  double _minp2(const fullMatrix<double>&) const;
  double _minq(const fullMatrix<double>&) const;
  double _maxp(const fullMatrix<double>&) const;
  double _maxq(const fullMatrix<double>&) const;
  void _minMaxA2(const fullMatrix<double>&, double &min, double &max) const;
  void _minJ2P3(const fullMatrix<double>&, const fullVector<double>&, double &min) const;
  void _maxAstK(const fullMatrix<double>&, const fullVector<double>&,
                double minK, double a1, double &maxa) const;                    //wrong
  void _maxAstK2(const fullMatrix<double>&, const fullVector<double>&,
                 double minK, double beta, double &maxa) const;                 //wrong
  void _maxAstK3(const fullMatrix<double>&, const fullVector<double>&,
                 double minK, double beta, double &maxa) const;                 //poor bound
  void _maxAstK4(const fullMatrix<double>&, const fullVector<double>&,
                 double minK, double beta, double &maxa) const;                 //better bound, WI positive ?
  void _maxKstA(const fullMatrix<double>&, const fullVector<double>&,
                 double mina, double &maxK) const;                              //wrong
  void _maxKstA2(const fullMatrix<double>&, const fullVector<double>&,
                 double mina, double beta, double &maxK) const;                 //faster
  void _maxKstA3(const fullMatrix<double>&, const fullVector<double>&,
                 double mina, double beta, double &maxK) const;                 //better bound
  void _minMaxJacobianSqr(const fullVector<double>&, double &min, double &max) const;

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

 private:
  MElement *_element;
  const JacobianBasis *_jacobian;
  const GradientBasis *_gradients;
  const bezierBasis *_bezier;
  fullMatrix<double> _coefficientsLag, _coefficientsBez;
  int __maxdepth, __numSubdivision;
  std::vector<int> __numSub;
  MetricBasis *_basis;

 public:
  MetricCoefficient(MElement*);

  void getCoefficients(fullMatrix<double>&, bool bezier = true);
  void interpolate(const double *uvw, double *minmaxQ);
  double getBoundRmin(double tol, int which);

 private:
  void _computeBezCoeff();
  void _interpolateBezierPyramid(const double *uvw, double *minmaxQ);
};

#endif
