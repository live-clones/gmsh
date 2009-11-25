#ifndef _FUNCTION_SPACE_H_
#define _FUNCTION_SPACE_H_

#include "SVector3.h"
#include <vector>


class STensor3{};
class SVoid{};

class basisFunction{
 public:
  virtual void f(MElement *ele, double u, double v, double w, double *s) = 0;
  virtual void df(MElement *ele, double u, double v, double w, double *s) = 0;
};

class scalarPolynomialBasisFunction : public basisFunction{
 private:
  polynomialBasis *_basis;
 public:
  virtual void f(MElement *ele, double u, double v, double w, double *s);
  virtual void df(MElement *ele, double u, double v, double w, double *s);
};

class vectorPolynomialBasisFunction : public basisFunction{
 private:
  polynomialBasis *_basis[3];
 public:
  virtual void f(MElement *ele, double u, double v, double w, double *s);
  virtual void df(MElement *ele, double u, double v, double w, double *s);
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
class FunctionSpace {
 protected:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
/*  typedef typename TensorialTraits<T>::HessType HessType;
  typedef typename TensorialTraits<T>::DivType DivType;
  typedef typename TensorialTraits<T>::CurlType CurlType;*/
 
 public:

  virtual int f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals)=0;
  virtual int gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads)=0;
//  virtual int gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads, STensor3 &invjac)=0;// on passe le jacobien que l'on veut ...
/* virtual int hessf(MElement *ele, double u, double v, double w,std::vector<HessType> &hesss);
  virtual int divf(MElement *ele, double u, double v, double w,std::vector<DivType> &divs);
  virtual int curlf(MElement *ele, double u, double v, double w,std::vector<CurlType> &curls);*/
  virtual int getNumKeys(MElement *ele)=0; // if one needs the number of dofs
  virtual int getKeys(MElement *ele, Dof *keys)=0; // may be faster once the number of dofs is known
  virtual int getKeys(MElement *ele, std::vector<Dof> &keys)=0; 
};




class ScalarLagrangeFunctionSpace : public FunctionSpace<double>
{
  
protected:
  typedef TensorialTraits<double>::ValType ValType;
  typedef TensorialTraits<double>::GradType GradType;
  typedef TensorialTraits<double>::HessType HessType;
  typedef TensorialTraits<double>::DivType DivType;
  typedef TensorialTraits<double>::CurlType CurlType;
  std::vector<basisFunction*> basisFunctions;

  int _iField; // field number (used to build dof keys)

  Dof getLocalDof(MElement *ele, int i) const
  {
//    int iComp = i / ele->getNumVertices();
//    int ithLocalVertex = i % ele->getNumVertices();
    return Dof(ele->getVertex(i)->getNum(),_iField);
  }


  public:
  ScalarLagrangeFunctionSpace(int i=0):_iField(i) {}
  virtual int getId(void) const {return _iField;};
  virtual int f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals)
  {
    int ndofs= ele->getNumVertices();
    int curpos=vals.size();
    vals.resize(vals.size()+ndofs);
    ele->getShapeFunctions(u, v, w, &(vals[curpos]));
  }; 
  virtual int gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads) {};
  virtual int getNumKeys(MElement *ele) {return ele->getNumVertices();}
  virtual int getKeys(MElement *ele, Dof *keys)
  {
      int ndofs= ele->getNumVertices();
      for (int i=0;i<ndofs;++i)
        keys[i]=getLocalDof(ele,i);
  }
  virtual int getKeys(MElement *ele, std::vector<Dof> &keys) // appends ...
  {
      int ndofs= ele->getNumVertices();
      keys.reserve(keys.size()+ndofs);
      for (int i=0;i<ndofs;++i)
        keys.push_back(getLocalDof(ele,i));
  }
};

template <class T> class ScalarToAnyFunctionSpace : public FunctionSpace<T> // scalarFS * const vector
{
public :
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;
  typedef typename TensorialTraits<T>::DivType DivType;
  typedef typename TensorialTraits<T>::CurlType CurlType;
protected :
  T multiplier;
  FunctionSpace<double> *ScalarFS;
public : 
  template <class T2> ScalarToAnyFunctionSpace(const T2 &SFS, const T& mult): multiplier(mult),ScalarFS(new T2(SFS)) {}
  virtual ~ScalarToAnyFunctionSpace() {delete ScalarFS;}

  virtual int f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals){}; 
  virtual int gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads){};
  virtual int getNumKeys(MElement *ele) {return ScalarFS->getNumKeys(ele);}
  virtual int getKeys(MElement *ele, Dof *keys){ ScalarFS->getKeys(ele,keys);}
  virtual int getKeys(MElement *ele, std::vector<Dof> &keys) {ScalarFS->getKeys(ele,keys);}
};


class VectorLagrangeFunctionSpace : public ScalarToAnyFunctionSpace<SVector3> // it is a scalar lagrange times a constant vector.
{
 public:
  enum Along { VECTOR_X=0, VECTOR_Y=1, VECTOR_Z=2 };
  typedef TensorialTraits<SVector3>::ValType ValType;
  typedef TensorialTraits<SVector3>::GradType GradType;
  typedef TensorialTraits<SVector3>::HessType HessType;
  typedef TensorialTraits<SVector3>::DivType DivType;
  typedef TensorialTraits<SVector3>::CurlType CurlType;
 protected:
  Along direction;
  public:
  VectorLagrangeFunctionSpace(int id,Along t) : ScalarToAnyFunctionSpace<SVector3>::ScalarToAnyFunctionSpace(ScalarLagrangeFunctionSpace(id),SVector3(0.,0.,0.) ),direction(t)
  { 
    multiplier[t]=1.;
  }
//   virtual int f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals);
//   virtual int gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads);
//   virtual int getNumKeys(MElement *ele);
//   virtual int getKeys(MElement *ele, Dof *keys);
//   virtual int getKeys(MElement *ele, std::vector<Dof> &keys);
};



template<class T>
class ProductFunctionSpace : public FunctionSpace<T>
{
 public: 
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;
  typedef typename TensorialTraits<T>::DivType DivType;
  typedef typename TensorialTraits<T>::CurlType CurlType;
  typedef typename std::vector<FunctionSpace<T>* >::iterator iterFS;
 protected: 
 
  std::vector<FunctionSpace<T>* > _spaces;
 public:
  template <class T1> ProductFunctionSpace(const T1& t) { _spaces.push_back(new T1(t));} 
  template <class T1, class T2> ProductFunctionSpace(const T1& t1, const T2& t2)   
  { _spaces.push_back(new T1(t1));
    _spaces.push_back(new T2(t2)); } 
  template <class T1, class T2, class T3> ProductFunctionSpace(const T1& t1, const T2& t2, const T3& t3)   
  { _spaces.push_back(new T1(t1));
    _spaces.push_back(new T2(t2)); 
    _spaces.push_back(new T3(t3)); } 
  template <class T1, class T2, class T3, class T4> ProductFunctionSpace(const T1& t1, const T2& t2, const T3& t3, const T4& t4)   
  { _spaces.push_back(new T1(t1));
    _spaces.push_back(new T2(t2)); 
    _spaces.push_back(new T3(t3)); 
    _spaces.push_back(new T4(t4)); } 
  template <class T1> void insert(const T1& t)   
  {
    _spaces.push_back(new T(t));
  } 
  virtual int f(MElement *ele, double u, double v, double w,std::vector<ValType> &vals) {}
  virtual int gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads) {}
  virtual int getNumKeys(MElement *ele)
  {
    int ndofs=0;
    for (iterFS it=_spaces.begin(); it!=_spaces.end();++it)
    {
      ndofs+=(*it)->getNumKeys(ele);
    }
    return ndofs;
  }
  virtual int getKeys(MElement *ele, Dof *keys)
  {
    Dof *kptr=keys;
    for (iterFS it=_spaces.begin(); it!=_spaces.end();++it)
    {
      (*it)->getKeys(ele,kptr);
      kptr+=(*it)->getNumKeys(ele);
    }
  }  
  virtual int getKeys(MElement *ele, std::vector<Dof> &keys)
  {
    for (iterFS it=_spaces.begin(); it!=_spaces.end();++it)
    {
      (*it)->getKeys(ele,keys);
    }
  }
};

template<class T>
class xFemFunctionSpace : public FunctionSpace<T>
{
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;
  typedef typename TensorialTraits<T>::DivType DivType;
  typedef typename TensorialTraits<T>::CurlType CurlType;
 private:
  FunctionSpace<T>* _spacebase;
//  Function<double>* enrichment;
 public:
  ValType f(MElement *ele, double u, double v, double w);
  GradType gradf(MElement *ele, double u, double v, double w);
  int getNumKeys(MElement *ele);
  void getKeys(MElement *ele, Dof *keys);
  void getKeys(MElement *ele, std::vector<Dof> &keys);
};


#endif
