// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _QUALITY_MEASURES_JACOBIAN_H_
#define _QUALITY_MEASURES_JACOBIAN_H_

#include <vector>
#include "fullMatrix.h"

class GradientBasis;
class bezierBasis;
class MElement;

namespace jacobianBasedQuality {

void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                               const fullMatrix<double> *normals = NULL);
double minIGEMeasure(MElement *el,
                     bool knownValid = false,
                     bool reversedOk = false);
double minICNMeasure(MElement *el,
                     bool knownValid = false,
                     bool reversedOk = false);
void sampleIGEMeasure(MElement *el, int order, double &min, double &max);
double minSampledICNMeasure(MElement *el, int order);//fordebug
double minSampledIGEMeasure(MElement *el, int order);//fordebug

class _CoeffData
{
protected:
  double _minL, _maxL; //Extremum of Jac at corners
  double _minB, _maxB; //Extremum of bezier coefficients
  const int _depth;

public:
  _CoeffData(int depth) : _minL(0), _maxL(0), _minB(0), _maxB(0),
                         _depth(depth) {}
  virtual ~_CoeffData() {}

  inline double minL() const {return _minL;}
  inline double maxL() const {return _maxL;}
  inline double minB() const {return _minB;}
  inline double maxB() const {return _maxB;}
  inline int depth() const {return _depth;}

  virtual bool boundsOk(double minL, double maxL) const = 0;
  virtual void getSubCoeff(std::vector<_CoeffData*>&) const = 0;
  virtual int getNumMeasure() const {return 0;}//fordebug
};

struct _lessMinB {
  bool operator()(_CoeffData*, _CoeffData*) const;
};
struct _lessMaxB {
  bool operator()(_CoeffData*, _CoeffData*) const;
};

class _CoeffDataJac: public _CoeffData
{
private:
  const fullVector<double> _coeffs;
  const bezierBasis *_bfs;

public:
  _CoeffDataJac(fullVector<double> &v, const bezierBasis *bfs, int depth);
  ~_CoeffDataJac() {}

  bool boundsOk(double minL, double maxL) const;
  void getSubCoeff(std::vector<_CoeffData*>&) const;
  int getNumMeasure() const {return 1;}//fordebug
};

class _CoeffDataIGE: public _CoeffData
{
private:
  const fullVector<double> _coeffsJacDet;
  const fullMatrix<double> _coeffsJacMat;
  const bezierBasis *_bfsDet, *_bfsMat;
  const int _type;

public:
  _CoeffDataIGE(fullVector<double> &det,
                     fullMatrix<double> &mat,
                     const bezierBasis *bfsDet,
                     const bezierBasis *bfsMat,
                     int depth, int type);
  ~_CoeffDataIGE() {}

  bool boundsOk(double minL, double maxL) const;
  void getSubCoeff(std::vector<_CoeffData*>&) const;
  int getNumMeasure() const {return 2;}//fordebug

private:
  void _computeAtCorner(double &min, double &max) const;
  double _computeLowerBound() const;
  void _getCoeffLengthVectors(fullMatrix<double> &, bool corners = false) const;
};

class _CoeffDataICN: public _CoeffData
{
private:
  const fullVector<double> _coeffsJacDet;
  const fullMatrix<double> _coeffsJacMat;
  const bezierBasis *_bfsDet, *_bfsMat;

public:
  _CoeffDataICN(fullVector<double> &det,
                     fullMatrix<double> &metric,
                     const bezierBasis *bfsDet,
                     const bezierBasis *bfsMet,
                     int depth);
  ~_CoeffDataICN() {}

  bool boundsOk(double minL, double maxL) const;
  void getSubCoeff(std::vector<_CoeffData*>&) const;
  int getNumMeasure() const {return 4;}//fordebug

private:
  void _computeAtCorner(double &min, double &max) const;
  double _computeLowerBound() const;
};

double _computeBoundRational(const fullVector<double> &numerator,
                             const fullVector<double> &denominator,
                             bool lower, bool positiveDenom = true);

void _subdivideDomains(std::vector<_CoeffData*> &domains);

}

#endif
