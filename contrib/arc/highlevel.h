//
// C++ Interface: highlevel
//
// Description: 
//
//
// Author:  <Eric Bechet>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef highlevel_H
#define highlevel_H

#include <vector>
#include <complex>
#include <iostream>
//#include <tr1/memory>

#include "dofManager.h"
#include "SVector3.h"
#include "MElement.h"
#include "MVertex.h"
#include "functionSpace.h"



typedef SVector3 Vector;
class Tensor2{};
class Tensor4{};

/*
template<class T> struct TensorialTraits
{
  typedef T ValType;
  typedef T GradType[3];
  typedef T HessType[3][3];
  static const int nb_basis_vectors=1; // par défaut, considéré comme un scalaire
};

template<> struct TensorialTraits<double>
{
  typedef double ValType;
  typedef Vector GradType;
  typedef Tensor2 HessType;
  static const int nb_basis_vectors=1; // scalaire
};


// template<> struct TensorialTraits<Vector>
// {
//   typedef Vector ValType;
//   typedef Tensor2 GradType;
//   typedef Tensor3 HessType;
//   static const int nb_basis_vectors=3; // trois vecteurs de base linéairement indépendants.
// };
*/

template<class T> class Function  // Fonction au sens EF du terme.
                // renvoie valeur , gradient, hessien, etc...pour un element donné et un point donné
{
public:
// typedef std::tr1::shared_ptr<Function<T> > FunctionPtr;
   virtual ~Function(){}
  virtual void GetVal (double uvw[3],MElement *e, T& Val)const=0;
  virtual void GetGrad(double uvw[3],MElement *e,typename TensorialTraits<T>::GradType &Grad) const =0;
  virtual void GetHess(double uvw[3],MElement *e,typename TensorialTraits<T>::HessType &Hess)const =0;
  virtual void GetVal (double uvw[][3],MElement *e, T Val[],int n) { for (int i=0;i<n;++i) GetVal(uvw[i],e,Val[i]); } // par defaut
  virtual void GetGrad(double uvw[][3],MElement *e,typename TensorialTraits<T>::GradType Grad[],int n) const { for (int i=0;i<n;++i) GetGrad(uvw[i],e,Grad[i]); }
  virtual void GetHess(double uvw[][3],MElement *e,typename TensorialTraits<T>::HessType Hess[],int n)const { for (int i=0;i<n;++i) GetHess(uvw[i],e,Hess[i]); }
};


template<class T> class LagrangeShapeFunction: public Function<T>
{
  public:
  virtual void GetVal(double uvw[],MElement *e, T& Val)
  {
//    double s[100];
//    _e->getShapeFunctions(uvw[0], uvw[1], uvw[2], s);

  }
};





/*
class SpaceBase // renvoie des clefs des dofs
{
protected:
int _iField;
public:
  SpaceBase(int iField=0):_iField(iField){};
  virtual ~SpaceBase(){};
  virtual int getNumberDofs(MElement *e) const = 0 ; 
  virtual void getDofs(MElement *e,const Dof *vecD) const {} //=0;
  virtual int getId(void) const {return _iField;};
};

template<class T> class Space : public SpaceBase // renvoie des clefs de dofs et des fonctions de formes
{
 
public: 
  Space(int iField=0):SpaceBase(iField){};
  virtual ~Space(){};
  virtual void getDofsandSFs(MElement *e,const Dof *VecD, const Function<T>* vecDSF) {} //=0;
  virtual void getSFs(const Function<T>* vecDSF) {} //=0;
};


template<class T> class SpaceLagrange : public Space<T> //  Lagrange ... 1 dof / node / basis vector
{
private:
 
  Dof getLocalDof(MElement *e, int i) const
  {
    int iComp = i / e->getNumVertices();
    int ithLocalVertex = i % e->getNumVertices();
    return Dof(e->getVertex(ithLocalVertex)->getNum(),
                Dof::createTypeWithTwoInts(iComp,Space<T>::getId()));
  }

public: 
  SpaceLagrange(int iField=0):Space<T>(iField){};
  virtual ~SpaceLagrange(){};
  virtual void getDofsandSFs(MElement *e,std::vector<std::pair< Dof, Function<T>* > > &vecDFF){}
  virtual void getSFs(std::vector<std::pair< Dof, Function<T>* > > &vecDFF)
  {
    
  };
  virtual void getDofs(MElement *e,std::vector<Dof> &vecD) const
  {
    int ndofs= e->getNumVertices()*TensorialTraits<T>::nb_basis_vectors;
    for (int i=0;i<ndofs;++i)
    vecD.push_back(getLocalDof(e,i));
  }
  virtual int getNumberDofs(MElement *e) const {return 0;} 
};


template<class T> class SpaceXfem : public Space<T> //  approximation xfem (spacebase + enrich)
{
  int _iEnrich;
  Space<T> &_SpaceBase;
  Function<double> &enrich;
  std::unary_function<MVertex*,bool> &test;
  Dof getLocalDof(MElement *e, int i) const
  {
    int iComp = i / e->getNumVertices();
    int ithLocalVertex = i % e->getNumVertices();
    MVertex * v= e->getVertex(ithLocalVertex);
    if (test(v))
      return Dof(e->getVertex(ithLocalVertex)->getNum(),
                Dof::createTypeWithTwoInts(iComp, _iEnrich));
  } 
public: 
  SpaceXfem(int iEnrich,Space<T>& SpaceBase):_iEnrich(iEnrich), _SpaceBase(SpaceBase){};
  virtual void getDofsandSFs(MElement *e,std::vector<std::pair< Dof, Function<T>* > > &vecDFF){}
  virtual void getSFs(std::vector<std::pair< Dof, Function<T>* > > &vecDFF){};
  virtual void getDofs(MElement *e,std::vector<Dof> &vecD) const
  {
    _SpaceBase.getDofs(e,vecD);
  }
};

*/

/*
template<class T> class Field : public Function<T> // renvoie des valeurs de champ (ff*valeurs dofs), gradient , etc...
{
public: 
  Field(){};
  virtual ~Field(){};
};
*/


class FormBilinearBase
{
  public: 
  template <class T> void allocate(T *p) {p=new T[10];std::cout << "10" << std::endl;}
  template <class T> void get(T* tab, T *p, int ndx) {p=&tab[ndx];}
  virtual void getDofs(MElement *e)=0;
  virtual void getFuncs(MElement *e,const double uvw[3])=0;
  virtual void getGradFuncs(MElement *e,const double uvw[3])=0;
};

template <> void FormBilinearBase::allocate(void *p) {p=NULL; std::cout << "null" << std::endl;}
template <> void FormBilinearBase::get(void *tab,void *p, int ndx) {p=NULL;}

template <class Term,class SpaceL,class SpaceR> class FormBilinear : public FormBilinearBase
   // Renvoie des matrices élémentaires (ff) 
                  // Accessoirement stocke des pointeurs vers les termes pour chaque element
                  // Doit etre initialisée AVANT toute opération (pour l'allocation)
                  // en principe ce truc ne devrait pas ^etre reimplemente
                  // il devrait donc dependre d'un parametre template TermBilinear
                  // elle sait "integrer" dans un elemeent
{

  typedef typename Term::Stype Stype; // le truc a stocker
  typedef typename Term::Datamat Datamat; // type elementaire
  Term instance; // une instance du terme. E.g. utile pour toute initialisation (calcul tenseur materiel, etc...)
  Stype *p;
  MElement *e;
  Function<double> *a;
  Function<double> *b;
  double uvw[3];
  fullMatrix<Datamat> mat;
  SpaceL *_spacel;
  SpaceR *_spacer;
  std::vector<Dof> Dofsl;
  std::vector<Dof> Dofsr;
  std::vector<Datamat> Funcl;
  std::vector<Datamat> Funcr;

  public:
  FormBilinear(SpaceL &sl,SpaceR &sr) {}
  void getMatrix(fullMatrix<Datamat> *v) {v=&mat;}
  void func(void) { allocate(p);}
  void func2(void) { }
  void getDofs(MElement *e) 
  {
    _spacel->getKeys(e,Dofsl);
    _spacer->getKeys(e,Dofsr);
  };
  void getFuncs(MElement *e,const double uvw[3]) {};
  void getGradFuncs(MElement *e,const double uvw[3]) {};
  void Init(MElement *e) { getDofs(e);} // called once for each element
  void Accumulate(MElement *e,const double uvw[3]) // called for every GP
  {
//    for (int i)
//      for (int j) 
//        mat(i,j)+=instance.getTerm(uvw,*e,*a,*b,NULL,this);
    instance.Init(e,this); // called once for each GP 
    if (instance.NeedFuncs()) getFuncs(e,uvw);
    if (instance.NeedGradFuncs()) getGradFuncs(e,uvw);
    Datamat result;
    instance.getTerm(uvw,e,NULL,*a,*b,result); // called for every SF combination (times every GP, times every element)
  }
};

//template <class Term,class SpaceL,class datamat=double> class FormBilinear<Term,SpaceL,SpaceR> : public FormBilinearBase {}; cas symétrique


class FormLinear{}; // renvoie des vecteurs élémentaires
              // on devrait pouvoir construire une forme lin à partir d'une forme bilin pour les pb "matrix free"
              // idem FormBilin
 
class FormZero{}; // renvoie des scalaires  ex. resultat d'une integration

//algorithmes
/*void Construct(FormBilinear &B,Region &R,Integrator &I);
void Assemble(FormBilinear &B,Region &R,Assembler &A, Integrator &I);
void Construct(FormLinear &L,Region &R,Integrator &I);
void Assemble(FormLinear &L,Region &R,Assembler &A,Integrator &I);
void Construct(FormZero &Z,Region &R,Integrator &I);
void Assemble(FormZero &Z,Region &R,Assembler &A,Integrator &I);
*/

class TermBilinearBase
{
public:
  virtual void GetTerm(MElement *e) {}
};


template<class datamat, class T1,class T2> class TermBilinear : public TermBilinearBase  // terme associe a un "element" / pt de gauss (contribution élémentaire)
            // typiquement celui ci stoque ce qui doit etre stocke. C'est la base configurable du code
            // on doit associer cela a un allocateur qui renvoie un pointeur sur ce truc 
            // Soit tous les elements/pts de gauss ont le meme terme , allocateur unique (pas de stockage aux pts de
            // gauss par exemple
            // soit ils ont qqc a stockuer et sont tous distincts
            // on peut utiliser des membres statiques pour ce qui est constant pour tous les instances
{
public:
  typedef void Stype;
  typedef datamat Datamat;
//  TermBilinear(){};
  virtual void Init(MElement *e, FormBilinearBase * caller) //called once for every element
  {
  }
  virtual bool NeedGradFuncs(void) { return false ;}// Query if getTerm will use the gradient of the SF
  virtual bool NeedFuncs(void) { return false ;}// Query if it will need the value of the SF

  virtual void getTerm(const double uvw[],MElement *e,Stype* info, Function<T1> &SF,Function<T2> &TF, datamat &res ) // called for every gauss point
  {
  };
  virtual void Update(const double uvw[],MElement &e,Function<T1> &SF,Function<T2> &TF) {};
// toute fonctios utiles . prevoir un algorithme  ad hoc pour l'appliquer sur ts les pts de gauss ...
};


class TermBilinearMeca : public TermBilinear<double, double,double>
{
public:
  virtual bool NeedGradFuncs(void) { return true ;}// Query if getTerm will use the gradient of the SF
//  typedef Tensor Stype;
//  TermBilinear(){};
//  virtual double getTerm(double uvw[],MElement &e,Function<double> &SF,Function<double> &TF,Stype* info) {};
//  virtual void Update(double uvw[],MElement &e,Function<T1> &SF,Function<T2> &TF) {};
// toute fonctios utiles . prevoir un algorithme 
};


class TermBilinearMecaNL : public TermBilinearMeca
{
public:
  typedef Tensor2 Stype;
//  TermBilinear(){};
//  virtual double getTerm(double uvw[],MElement &e,Function<double> &SF,Function<double> &TF,Stype* info) {};
//  virtual void Update(double uvw[],MElement &e,Function<T1> &SF,Function<T2> &TF) {};
// toute fonctios utiles . prevoir un algorithme 
};



#endif // highlevel_H
