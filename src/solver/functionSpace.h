// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FUNCTION_SPACE_H
#define FUNCTION_SPACE_H

#include "SVector3.h"
#include "STensor3.h"
#include "STensor33.h"
#include "STensor43.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "Numeric.h"
#include "MElement.h"
#include "dofManager.h"
#include "simpleFunction.h"

// class SVoid{};
template <class T> struct TensorialTraits {
  typedef T ValType;
  typedef T GradType[3];
  typedef T HessType[3][3];
  typedef T ThirdDevType[3][3][3];
  /*  typedef SVoid DivType;
    typedef SVoid CurlType;*/
};

template <> struct TensorialTraits<double> {
  typedef double ValType;
  typedef SVector3 GradType;
  typedef STensor3 HessType;
  typedef double TensProdType;
  typedef STensor33 ThirdDevType;
  /*  typedef SVoid DivType;
    typedef SVoid CurlType;*/
};

template <> struct TensorialTraits<SVector3> {
  typedef SVector3 ValType;
  typedef STensor3 GradType;
  typedef STensor3 HessType;
  typedef STensor3 TensProdType;
  typedef STensor3 ThirdDevType;
  //  typedef double DivType;
  //  typedef SVector3 CurlType;
};

template <> struct TensorialTraits<STensor3> {
  typedef STensor3 ValType;
  //  typedef STensor3 GradType;
  //  typedef STensor3 HessType;
  //  typedef STensor3 TensProdType;
  typedef STensor43 TensProdType;
  //  typedef double DivType;
  //  typedef SVector3 CurlType;
};

class FunctionSpaceBase {
public:
  virtual ~FunctionSpaceBase() {}
  virtual int getId(void) const = 0;
  virtual int
  getNumKeys(MElement *ele) const = 0; // if one needs the number of dofs
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const = 0;
  virtual void getKeysOnVertex(MElement *ele, MVertex *v,
                               const std::vector<int> &comp,
                               std::vector<Dof> &keys) const
  {
    Msg::Warning(
      "this function is defined to get Dofs of vertex %d on element %d",
      v->getNum(), ele->getNum());
  }
  virtual FunctionSpaceBase *clone(const int id) const
  {
    return nullptr;
  }; // copy space with new Id
};

template <class T> class FunctionSpace : public FunctionSpaceBase {
protected:
  int _iField; // field number (used to build dof keys)
public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;
  typedef typename TensorialTraits<T>::ThirdDevType ThirdDevType;
  virtual int getId(void) const { return _iField; }
  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const = 0;
  virtual void fuvw(MElement *ele, double u, double v, double w,
                    std::vector<ValType> &vals) const
  {
  } // should return to pure virtual once all is done.
  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const = 0;
  virtual void gradfuvw(MElement *ele, double u, double v, double w,
                        std::vector<GradType> &grads) const
  {
  } // should return to pure virtual once all is done.
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const = 0;
  virtual void hessf(MElement *ele, double u, double v, double w,
                     std::vector<HessType> &hess) const
  {
  } // need to high order fem
  virtual void thirdDevfuvw(
    MElement *ele, double u, double v, double w,
    std::vector<ThirdDevType> &third) const {}; // need to high order fem
  virtual void thirdDevf(
    MElement *ele, double u, double v, double w,
    std::vector<ThirdDevType> &third) const {}; // need to high order fem

  virtual int
  getNumKeys(MElement *ele) const = 0; // if one needs the number of dofs
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const = 0;
};

class ScalarLagrangeFunctionSpaceOfElement : public FunctionSpace<double> {
public:
  typedef TensorialTraits<double>::ValType ValType;
  typedef TensorialTraits<double>::GradType GradType;
  typedef TensorialTraits<double>::HessType HessType;

private:
  virtual void getKeys(MVertex *ver, std::vector<Dof> &keys) const
  {
    keys.push_back(Dof(ver->getNum(), _iField));
  }

public:
  ScalarLagrangeFunctionSpaceOfElement(int i = 0) { _iField = i; }
  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const
  {
    if(ele->getParent()) {
      if(ele->getTypeForMSH() == MSH_LIN_B ||
         ele->getTypeForMSH() == MSH_TRI_B ||
         ele->getTypeForMSH() == MSH_POLYG_B) { // FIXME MPolygonBorders...
        ele->movePointFromParentSpaceToElementSpace(u, v, w);
      }
    }
    int ndofs = ele->getNumShapeFunctions();
    int curpos = vals.size();
    vals.resize(curpos + ndofs);
    ele->getShapeFunctions(u, v, w, &(vals[curpos]));
  }
  // Fonction renvoyant un vecteur contenant le grandient de chaque FF
  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const
  {
    if(ele->getParent()) {
      if(ele->getTypeForMSH() == MSH_LIN_B ||
         ele->getTypeForMSH() == MSH_TRI_B ||
         ele->getTypeForMSH() == MSH_POLYG_B) { // FIXME MPolygonBorders...
        ele->movePointFromParentSpaceToElementSpace(u, v, w);
      }
    }
    int ndofs = ele->getNumShapeFunctions();
    grads.reserve(grads.size() + ndofs);
    double gradsuvw[256][3];
    ele->getGradShapeFunctions(u, v, w, gradsuvw);
    double jac[3][3];
    double invjac[3][3];
    ele->getJacobian(u, v, w,
                     jac); // redondant : on fait cet appel a l'exterieur
    inv3x3(jac, invjac);
    for(int i = 0; i < ndofs; ++i)
      grads.push_back(
        GradType(invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] +
                   invjac[0][2] * gradsuvw[i][2],
                 invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] +
                   invjac[1][2] * gradsuvw[i][2],
                 invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] +
                   invjac[2][2] * gradsuvw[i][2]));
  }
  // Fonction renvoyant un vecteur contenant le hessien [][] de chaque FF dans
  // l'espace ISOPARAMETRIQUE
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
    if(ele->getParent()) {
      if(ele->getTypeForMSH() == MSH_LIN_B ||
         ele->getTypeForMSH() == MSH_TRI_B ||
         ele->getTypeForMSH() == MSH_POLYG_B) { // FIXME MPolygonBorders...
        ele->movePointFromParentSpaceToElementSpace(u, v, w);
      }
    }
    int ndofs = ele->getNumShapeFunctions();
    hess.reserve(hess.size() + ndofs); // permet de mettre les composantes
                                       // suivantes à la suite du vecteur
    double hessuvw[256][3][3];
    ele->getHessShapeFunctions(u, v, w, hessuvw);
    HessType hesst;
    for(int i = 0; i < ndofs; ++i) {
      hesst(0, 0) = hessuvw[i][0][0];
      hesst(0, 1) = hessuvw[i][0][1];
      hesst(0, 2) = hessuvw[i][0][2];
      hesst(1, 0) = hessuvw[i][1][0];
      hesst(1, 1) = hessuvw[i][1][1];
      hesst(1, 2) = hessuvw[i][1][2];
      hesst(2, 0) = hessuvw[i][2][0];
      hesst(2, 1) = hessuvw[i][2][1];
      hesst(2, 2) = hessuvw[i][2][2];
      hess.push_back(hesst);
    }
  }
  virtual void gradfuvw(MElement *ele, double u, double v, double w,
                        std::vector<GradType> &grads) const
  {
    if(ele->getParent()) {
      if(ele->getTypeForMSH() == MSH_LIN_B ||
         ele->getTypeForMSH() == MSH_TRI_B ||
         ele->getTypeForMSH() == MSH_POLYG_B) { // FIXME MPolygonBorders...
        ele->movePointFromParentSpaceToElementSpace(u, v, w);
      }
    }
    int ndofs = ele->getNumShapeFunctions();
    grads.reserve(grads.size() + ndofs);
    double gradsuvw[256][3];
    ele->getGradShapeFunctions(u, v, w, gradsuvw);
    for(int i = 0; i < ndofs; ++i)
      grads.push_back(GradType(gradsuvw[i][0], gradsuvw[i][1], gradsuvw[i][2]));
  }
  virtual int getNumKeys(MElement *ele) const
  {
    return ele->getNumShapeFunctions();
  }
  virtual void getKeys(MElement *ele,
                       std::vector<Dof> &keys) const // appends ...
  {
    int ndofs = ele->getNumShapeFunctions();
    keys.reserve(keys.size() + ndofs);
    for(int i = 0; i < ndofs; ++i) getKeys(ele->getShapeFunctionNode(i), keys);
  }
};

class ScalarLagrangeFunctionSpace : public FunctionSpace<double> {
public:
  typedef TensorialTraits<double>::ValType ValType;
  typedef TensorialTraits<double>::GradType GradType;
  typedef TensorialTraits<double>::HessType HessType;

private:
  virtual void getKeys(MVertex *ver, std::vector<Dof> &keys) const
  {
    keys.push_back(Dof(ver->getNum(), _iField));
  }

public:
  ScalarLagrangeFunctionSpace(int i = 0) { _iField = i; }
  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const
  {
    if(ele->getParent()) ele = ele->getParent();
    int ndofs = ele->getNumShapeFunctions();
    int curpos = vals.size();
    vals.resize(curpos + ndofs);
    ele->getShapeFunctions(u, v, w, &(vals[curpos]));
  }
  // Fonction renvoyant un vecteur contenant le grandient de chaque FF
  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const
  {
    if(ele->getParent()) ele = ele->getParent();
    int ndofs = ele->getNumShapeFunctions();
    grads.reserve(grads.size() + ndofs);
    double gradsuvw[256][3];
    ele->getGradShapeFunctions(u, v, w, gradsuvw);
    double jac[3][3];
    double invjac[3][3];
    ele->getJacobian(u, v, w,
                     jac); // redondant : on fait cet appel a l'exterieur
    inv3x3(jac, invjac);
    for(int i = 0; i < ndofs; ++i)
      grads.push_back(
        GradType(invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] +
                   invjac[0][2] * gradsuvw[i][2],
                 invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] +
                   invjac[1][2] * gradsuvw[i][2],
                 invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] +
                   invjac[2][2] * gradsuvw[i][2]));
  }
  // Fonction renvoyant un vecteur contenant le hessien [][] de chaque FF dans
  // l'espace ISOPARAMETRIQUE
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
    if(ele->getParent()) ele = ele->getParent();
    int ndofs = ele->getNumShapeFunctions();
    hess.reserve(hess.size() + ndofs); // permet de mettre les composantes
                                       // suivantes à la suite du vecteur
    double hessuvw[256][3][3];
    ele->getHessShapeFunctions(u, v, w, hessuvw);
    HessType hesst;
    for(int i = 0; i < ndofs; ++i) {
      hesst(0, 0) = hessuvw[i][0][0];
      hesst(0, 1) = hessuvw[i][0][1];
      hesst(0, 2) = hessuvw[i][0][2];
      hesst(1, 0) = hessuvw[i][1][0];
      hesst(1, 1) = hessuvw[i][1][1];
      hesst(1, 2) = hessuvw[i][1][2];
      hesst(2, 0) = hessuvw[i][2][0];
      hesst(2, 1) = hessuvw[i][2][1];
      hesst(2, 2) = hessuvw[i][2][2];
      hess.push_back(hesst);
    }
  }
  virtual void gradfuvw(MElement *ele, double u, double v, double w,
                        std::vector<GradType> &grads) const
  {
    if(ele->getParent()) ele = ele->getParent();
    int ndofs = ele->getNumShapeFunctions();
    grads.reserve(grads.size() + ndofs);
    double gradsuvw[256][3];
    ele->getGradShapeFunctions(u, v, w, gradsuvw);
    for(int i = 0; i < ndofs; ++i)
      grads.push_back(GradType(gradsuvw[i][0], gradsuvw[i][1], gradsuvw[i][2]));
  }
  virtual void fuvw(MElement *ele, double u, double v, double w,
                    std::vector<ValType> &vals) const
  {
    if(ele->getParent()) ele = ele->getParent();
    int ndofs = ele->getNumShapeFunctions();
    vals.reserve(vals.size() + ndofs);
    double valsuvw[1256];
    ele->getShapeFunctions(u, v, w, valsuvw);
    for(int i = 0; i < ndofs; ++i) vals.push_back(valsuvw[i]);
  }
  virtual int getNumKeys(MElement *ele) const
  {
    if(ele->getParent()) ele = ele->getParent();
    return ele->getNumShapeFunctions();
  }
  virtual void getKeys(MElement *ele,
                       std::vector<Dof> &keys) const // appends ...
  {
    if(ele->getParent()) ele = ele->getParent();
    int ndofs = ele->getNumShapeFunctions();
    keys.reserve(keys.size() + ndofs);
    for(int i = 0; i < ndofs; ++i) getKeys(ele->getShapeFunctionNode(i), keys);
  }
};

template <class T> class ScalarToAnyFunctionSpace : public FunctionSpace<T> {
public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;

protected:
  std::vector<T> multipliers;
  std::vector<int> comp;
  FunctionSpace<double> *ScalarFS;

public:
  template <class T2>
  ScalarToAnyFunctionSpace(const T2 &SFS, const T &mult, int comp_)
    : ScalarFS(new T2(SFS))
  {
    multipliers.push_back(mult);
    comp.push_back(comp_);
  }

  template <class T2>
  ScalarToAnyFunctionSpace(const T2 &SFS, const T &mult1, int comp1_,
                           const T &mult2, int comp2_)
    : ScalarFS(new T2(SFS))
  {
    multipliers.push_back(mult1);
    multipliers.push_back(mult2);
    comp.push_back(comp1_);
    comp.push_back(comp2_);
  }

  template <class T2>
  ScalarToAnyFunctionSpace(const T2 &SFS, const T &mult1, int comp1_,
                           const T &mult2, int comp2_, const T &mult3,
                           int comp3_)
    : ScalarFS(new T2(SFS))
  {
    multipliers.push_back(mult1);
    multipliers.push_back(mult2);
    multipliers.push_back(mult3);
    comp.push_back(comp1_);
    comp.push_back(comp2_);
    comp.push_back(comp3_);
  }

  virtual ~ScalarToAnyFunctionSpace() { delete ScalarFS; }

  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const
  {
    std::vector<double> valsd;
    ScalarFS->f(ele, u, v, w, valsd);
    int nbdofs = valsd.size();
    int nbcomp = comp.size();
    int curpos = vals.size();
    vals.reserve(curpos + nbcomp * nbdofs);
    for(int j = 0; j < nbcomp; ++j) {
      for(int i = 0; i < nbdofs; ++i) vals.push_back(multipliers[j] * valsd[i]);
    }
  }

  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const
  {
    std::vector<SVector3> gradsd;
    ScalarFS->gradf(ele, u, v, w, gradsd);
    int nbdofs = gradsd.size();
    int nbcomp = comp.size();
    int curpos = grads.size();
    grads.reserve(curpos + nbcomp * nbdofs);
    GradType val;
    for(int j = 0; j < nbcomp; ++j) {
      for(int i = 0; i < nbdofs; ++i) {
        tensprod(multipliers[j], gradsd[i], val);
        grads.push_back(val);
      }
    }
  }
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
    ScalarFS->hessfuvw(ele, u, v, w, hess);
  }
  virtual void gradfuvw(MElement *ele, double u, double v, double w,
                        std::vector<GradType> &grads) const
  {
    std::vector<SVector3> gradsd;
    ScalarFS->gradfuvw(ele, u, v, w, gradsd);
    int nbdofs = gradsd.size();
    int nbcomp = comp.size();
    int curpos = grads.size();
    grads.reserve(curpos + nbcomp * nbdofs);
    GradType val;
    for(int j = 0; j < nbcomp; ++j) {
      for(int i = 0; i < nbdofs; ++i) {
        tensprod(multipliers[j], gradsd[i], val);
        grads.push_back(val);
      }
    }
  }

  virtual int getNumKeys(MElement *ele) const
  {
    return ScalarFS->getNumKeys(ele) * comp.size();
  }

  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const
  {
    int nk = ScalarFS->getNumKeys(ele);
    std::vector<Dof> bufk;
    bufk.reserve(nk);
    ScalarFS->getKeys(ele, bufk);
    int nbdofs = bufk.size();
    int nbcomp = comp.size();
    int curpos = keys.size();
    keys.reserve(curpos + nbcomp * nbdofs);
    for(int j = 0; j < nbcomp; ++j) {
      for(int i = 0; i < nk; ++i) {
        int i1, i2;
        Dof::getTwoIntsFromType(bufk[i].getType(), i1, i2);
        keys.push_back(
          Dof(bufk[i].getEntity(), Dof::createTypeWithTwoInts(comp[j], i1)));
      }
    }
  }
};

class VectorLagrangeFunctionSpaceOfElement
  : public ScalarToAnyFunctionSpace<SVector3> {
protected:
  static const SVector3 BasisVectors[3];

public:
  enum Along { VECTOR_X = 0, VECTOR_Y = 1, VECTOR_Z = 2 };
  typedef TensorialTraits<SVector3>::ValType ValType;
  typedef TensorialTraits<SVector3>::GradType GradType;
  VectorLagrangeFunctionSpaceOfElement(int id)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpaceOfElement(id), SVector3(1., 0., 0.),
        VECTOR_X, SVector3(0., 1., 0.), VECTOR_Y, SVector3(0., 0., 1.),
        VECTOR_Z)
  {
  }
  VectorLagrangeFunctionSpaceOfElement(int id, Along comp1)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpaceOfElement(id), BasisVectors[comp1], comp1)
  {
  }
  VectorLagrangeFunctionSpaceOfElement(int id, Along comp1, Along comp2)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpaceOfElement(id), BasisVectors[comp1], comp1,
        BasisVectors[comp2], comp2)
  {
  }
  VectorLagrangeFunctionSpaceOfElement(int id, Along comp1, Along comp2,
                                       Along comp3)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpaceOfElement(id), BasisVectors[comp1], comp1,
        BasisVectors[comp2], comp2, BasisVectors[comp3], comp3)
  {
  }
};

class VectorLagrangeFunctionSpace : public ScalarToAnyFunctionSpace<SVector3> {
protected:
  static const SVector3 BasisVectors[3];

public:
  enum Along { VECTOR_X = 0, VECTOR_Y = 1, VECTOR_Z = 2 };
  typedef TensorialTraits<SVector3>::ValType ValType;
  typedef TensorialTraits<SVector3>::GradType GradType;
  VectorLagrangeFunctionSpace(int id)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpace(id), SVector3(1., 0., 0.), VECTOR_X,
        SVector3(0., 1., 0.), VECTOR_Y, SVector3(0., 0., 1.), VECTOR_Z)
  {
  }
  VectorLagrangeFunctionSpace(int id, Along comp1)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpace(id), BasisVectors[comp1], comp1)
  {
  }
  VectorLagrangeFunctionSpace(int id, Along comp1, Along comp2)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpace(id), BasisVectors[comp1], comp1,
        BasisVectors[comp2], comp2)
  {
  }
  VectorLagrangeFunctionSpace(int id, Along comp1, Along comp2, Along comp3)
    : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(
        ScalarLagrangeFunctionSpace(id), BasisVectors[comp1], comp1,
        BasisVectors[comp2], comp2, BasisVectors[comp3], comp3)
  {
  }
};

template <class T> class CompositeFunctionSpace : public FunctionSpace<T> {
public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;
  typedef typename std::vector<FunctionSpace<T> *>::iterator iterFS;

protected:
  std::vector<FunctionSpace<T> *> _spaces;

public:
  template <class T1> CompositeFunctionSpace(const T1 &t)
  {
    _spaces.push_back(new T1(t));
  }
  template <class T1, class T2>
  CompositeFunctionSpace(const T1 &t1, const T2 &t2)
  {
    _spaces.push_back(new T1(t1));
    _spaces.push_back(new T2(t2));
  }
  template <class T1, class T2, class T3>
  CompositeFunctionSpace(const T1 &t1, const T2 &t2, const T3 &t3)
  {
    _spaces.push_back(new T1(t1));
    _spaces.push_back(new T2(t2));
    _spaces.push_back(new T3(t3));
  }
  template <class T1, class T2, class T3, class T4>
  CompositeFunctionSpace(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4)
  {
    _spaces.push_back(new T1(t1));
    _spaces.push_back(new T2(t2));
    _spaces.push_back(new T3(t3));
    _spaces.push_back(new T4(t4));
  }
  template <class T1> void insert(const T1 &t) { _spaces.push_back(new T(t)); }
  ~CompositeFunctionSpace(void)
  {
    for(iterFS it = _spaces.begin(); it != _spaces.end(); ++it) delete(*it);
  }
  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const
  {
    for(iterFS it = _spaces.begin(); it != _spaces.end(); ++it)
      (*it)->f(ele, u, v, w, vals);
  }

  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const
  {
    for(iterFS it = _spaces.begin(); it != _spaces.end(); ++it)
      (*it)->gradf(ele, u, v, w, grads);
  }

  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
    for(iterFS it = _spaces.begin(); it != _spaces.end(); ++it)
      (*it)->hessfuvw(ele, u, v, w, hess);
  }

  virtual int getNumKeys(MElement *ele) const
  {
    int ndofs = 0;
    for(iterFS it = _spaces.begin(); it != _spaces.end(); ++it)
      ndofs += (*it)->getNumKeys(ele);
    return ndofs;
  }

  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const
  {
    for(iterFS it = _spaces.begin(); it != _spaces.end(); ++it)
      (*it)->getKeys(ele, keys);
  }
};

template <class T> class xFemFunctionSpace : public FunctionSpace<T> {
public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;

protected:
  FunctionSpace<T> *_spacebase;
  simpleFunctionOnElement<double> *_funcEnrichment;

public:
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
  }
  xFemFunctionSpace(FunctionSpace<T> *spacebase,
                    simpleFunctionOnElement<double> *funcEnrichment)
    : _spacebase(spacebase), _funcEnrichment(funcEnrichment)
  {
  }
  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const;
  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const;
  virtual int getNumKeys(MElement *ele) const;
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const;
};

template <class T, class F>
class FilteredFunctionSpace : public FunctionSpace<T> {
public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;

protected:
  FunctionSpace<T> *_spacebase;
  F *_filter;

public:
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
  }
  FilteredFunctionSpace<T, F>(FunctionSpace<T> *spacebase, F *filter)
    : _spacebase(spacebase), _filter(filter)
  {
  }
  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const;
  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const;
  virtual int getNumKeys(MElement *ele) const;
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const;
};

template <class T>
void xFemFunctionSpace<T>::f(MElement *ele, double u, double v, double w,
                             std::vector<ValType> &vals) const
{
  // We need parent parameters
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  // Get the spacebase valsd
  std::vector<ValType> valsd;
  xFemFunctionSpace<T>::_spacebase->f(elep, u, v, w, valsd);

  int nbdofs = valsd.size();
  int curpos = vals.size(); // if in composite function space
  vals.reserve(curpos + nbdofs);

  // then enriched dofs so the order is ex:(a2x,a2y,a3x,a3y)
  if(nbdofs > 0) { // if enriched
    // Enrichment function calcul
    SPoint3 p;
    elep->pnt(u, v, w, p); // parametric to cartesian coordinates
    double func;
    _funcEnrichment->setElement(elep);
    func = (*_funcEnrichment)(p.x(), p.y(), p.z());
    for(int i = 0; i < nbdofs; i++) {
      vals.push_back(valsd[i] * func);
    }
  }
}

template <class T>
void xFemFunctionSpace<T>::gradf(MElement *ele, double u, double v, double w,
                                 std::vector<GradType> &grads) const
{
  // We need parent parameters
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  // Get the spacebase gradsd
  std::vector<GradType> gradsd;
  xFemFunctionSpace<T>::_spacebase->gradf(elep, u, v, w, gradsd);

  int nbdofs = gradsd.size();

  // We need spacebase valsd to compute total gradient
  std::vector<ValType> valsd;
  xFemFunctionSpace<T>::_spacebase->f(elep, u, v, w, valsd);

  int curpos = grads.size(); // if in composite function space
  grads.reserve(curpos + nbdofs);

  // then enriched dofs so the order is ex:(a2x,a2y,a3x,a3y)
  if(nbdofs > 0) { // if enriched
    double df[3];
    SPoint3 p;
    elep->pnt(u, v, w, p);
    _funcEnrichment->setElement(elep);
    _funcEnrichment->gradient(p.x(), p.y(), p.z(), df[0], df[1], df[2]);
    ValType gradfuncenrich(df[0], df[1], df[2]);

    // Enrichment function calcul
    double func;
    _funcEnrichment->setElement(elep);
    func = (*_funcEnrichment)(p.x(), p.y(), p.z());

    for(int i = 0; i < nbdofs; i++) {
      GradType GradFunc;
      tensprod(valsd[i], gradfuncenrich, GradFunc);
      grads.push_back(gradsd[i] * func + GradFunc);
    }
  }
}

template <class T> int xFemFunctionSpace<T>::getNumKeys(MElement *ele) const
{
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;
  int nbdofs = xFemFunctionSpace<T>::_spacebase->getNumKeys(elep);
  return nbdofs;
}

template <class T>
void xFemFunctionSpace<T>::getKeys(MElement *ele, std::vector<Dof> &keys) const
{
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  int normalk = xFemFunctionSpace<T>::_spacebase->getNumKeys(elep);

  std::vector<Dof> bufk;
  bufk.reserve(normalk);
  xFemFunctionSpace<T>::_spacebase->getKeys(elep, bufk);
  int normaldofs = bufk.size();
  int nbdofs = normaldofs;

  int curpos = keys.size();
  keys.reserve(curpos + nbdofs);

  // get keys so the order is ex:(a2x,a2y,a3x,a3y)
  // enriched dof tagged with ( i2 -> i2 + 1 )
  for(int i = 0; i < nbdofs; i++) {
    int i1, i2;
    Dof::getTwoIntsFromType(bufk[i].getType(), i1, i2);
    keys.push_back(
      Dof(bufk[i].getEntity(), Dof::createTypeWithTwoInts(i1, i2 + 1)));
  }
}

// Filtered function space
//

template <class T, class F>
void FilteredFunctionSpace<T, F>::f(MElement *ele, double u, double v, double w,
                                    std::vector<ValType> &vals) const
{
  // We need parent parameters
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  std::vector<ValType> valsd;

  _spacebase->f(elep, u, v, w, valsd);

  int normalk = _spacebase->getNumKeys(elep);
  std::vector<Dof> bufk;
  bufk.reserve(normalk);
  _spacebase->getKeys(elep, bufk);

  for(int i = 0; i < bufk.size(); i++) {
    if((*_filter)(bufk[i])) vals.push_back(valsd[i]);
  }
}

template <class T, class F>
void FilteredFunctionSpace<T, F>::gradf(MElement *ele, double u, double v,
                                        double w,
                                        std::vector<GradType> &grads) const
{
  // We need parent parameters
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  // Get space base gradsd
  std::vector<GradType> gradsd;
  _spacebase->gradf(elep, u, v, w, gradsd);

  // Get numkeys
  int normalk = _spacebase->getNumKeys(elep);
  std::vector<Dof> bufk;
  bufk.reserve(normalk);
  _spacebase->getKeys(elep, bufk);

  for(int i = 0; i < bufk.size(); i++) {
    if((*_filter)(bufk[i])) grads.push_back(gradsd[i]);
  }
}

template <class T, class F>
int FilteredFunctionSpace<T, F>::getNumKeys(MElement *ele) const
{
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  int nbdofs = 0;

  int normalk = _spacebase->getNumKeys(elep);
  std::vector<Dof> bufk;
  bufk.reserve(normalk);
  _spacebase->getKeys(elep, bufk);

  for(int i = 0; i < bufk.size(); i++) {
    if((*_filter)(bufk[i])) nbdofs = nbdofs + 1;
  }
  return nbdofs;
}

template <class T, class F>
void FilteredFunctionSpace<T, F>::getKeys(MElement *ele,
                                          std::vector<Dof> &keys) const
{
  MElement *elep;
  if(ele->getParent())
    elep = ele->getParent();
  else
    elep = ele;

  int normalk = _spacebase->getNumKeys(elep);

  std::vector<Dof> bufk;
  bufk.reserve(normalk);
  _spacebase->getKeys(elep, bufk);

  for(int i = 0; i < bufk.size(); i++) {
    if((*_filter)(bufk[i])) keys.push_back(bufk[i]);
  }
}

#endif
