#ifndef _FUNCTION_SPACE_H_
#define _FUNCTION_SPACE_H_

#include "SVector3.h"

class STensor3{};
class SVoid{};

class basisFunction{
 public:
  void f(MElement *ele, double u, double v, double w, double *s) = 0;
  void df(MElement *ele, double u, double v, double w, double *s) = 0;
};

class scalarPolynomialBasisFunction : public basisFunction{
 private:
  polynomialBasis *_basis;
 public:
  void f(MElement *ele, double u, double v, double w, doble *s);
  void df(MElement *ele, double u, double v, double w, double *s);
};

class vectorPolynomialBasisFunction : public basisFunction{
 private:
  polynomialBasis *_basis[3];
 public:
  void f(MElement *ele, double u, double v, double w, doble *s);
  void df(MElement *ele, double u, double v, double w, double *s);
};

template<class T> struct TensorialTraits
{
  typedef T ValType;
  typedef T GradType[3];
  typedef T HessType[3][3];
  typedef SVoid DivType;
  typedef SVoid CurlType;
};

template<> struct TensorialTraits<double>
{
  typedef double ValType;
  typedef SVector3 GradType;
  typedef STensor3 HessType;
  typedef SVoid DivType;
  typedef SVoid CurlType;
};

template<> struct TensorialTraits<SVector3>
{
  typedef SVector3 ValType;
  typedef STensor3 GradType;
  typedef SVoid HessType;
  typedef double DivType;
  typedef SVector3 CurlType;
};

template<class T>
class functionSpace{
 protected:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  std::vector<basisFunction*> basisFunctions;
 public:
  ValType f(MElement *ele, double u, double v, double w);
  GradType gradf(MElement *ele, double u, double v, double w);
  int getNumKeys(MElement *ele);
  void getKeys(MElement *ele, Dof *keys);
};

template<class T>
class productFunctionSpace : public functionSpace {
 private:
  std::vector<functionSpace*> _spaces;
 public:
  ValType f(MElement *ele, double u, double v, double w);
  GradType gradf(MElement *ele, double u, double v, double w);
};

#endif
