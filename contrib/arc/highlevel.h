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

#include "dofManager.h"
#include "SVector3.h"
#include "MElement.h"



typedef SVector3 Vector;
class Tensor2{};
class Tensor4{};

template<class T> struct TensorialTraits
{
  typedef T ValType;
  typedef T GradType[3];
  typedef T HessType[3][3];
};

/*template<> struct TensorialTraits<double>
{
  typedef double ValType;
  typedef Vector GradType;
  typedef Tensor2 HessType;
};

template<> struct TensorialTraits<Vector>
{
  typedef Vector ValType;
  typedef Tensor2 GradType;
  typedef Tensor3 HessType;
};
*/

template<class T> class Function  // Fonction au sens EF du terme.
                // renvoie valeur , gradient, hessien, etc...pour un element donné et un point donné
{
public:
  virtual ~Function(){}
  virtual void GetVal (double uvw[],MElement *e, T& Val)const{};// =0;
  virtual void GetGrad(double uvw[],MElement *e,typename TensorialTraits<T>::GradType &Grad) const {};//=0;
  virtual void GetHess(double uvw[],MElement *e,typename TensorialTraits<T>::HessType &Hess)const {};//=0;
};

class SpaceBase // renvoie des clefs de dofs
{
public:
  virtual void getDofs(MElement *e,std::vector<Dof> &vecD){};//=0;
};

template<class T> class Space : public SpaceBase // renvoie des clefs de dofs et des fonctions de formes
{
public: 
  Space(){};
  virtual ~Space(){};
  virtual void getDofsandSFs(MElement *e,std::vector<std::pair< Dof, Function<T>* > > &vecDFF) {}
  virtual void getSFs(std::vector<std::pair< Dof, Function<T>* > > &vecDFF){};//=0;
};


template<class T> class Field : public Function<T> // renvoie des valeurs de champ (ff*valeurs dofs), gradient , etc...
{
public: 
  Field(){};
  virtual ~Field(){};
};

template<class T1,class T2> class TermBilinear  // terme associe a un "element" / pt de gauss (contribution élémentaire)
            // typiquement celui ci stoque ce qui doit etre stocke. C'est la base configurable du code
            // on doit associer cela a un allocateur qui renvoie un pointeur sur ce truc 
            // Soit tous les elements/pts de gauss ont le meme terme , allocateur unique (pas de stockage aux pts de
            // gauss par exemple
            // soit ils ont qqc a stockuer et sont tous distincts
            // on peut utiliser des membres statiques pour ce qui est constant pour tous les instances
{
public:
  typedef void Stype;
//  TermBilinear(){};
  virtual double getTerm(double uvw[],MElement &e,Function<T1> &SF,Function<T2> &TF,Stype* info) {};
  virtual void Update(double uvw[],MElement &e,Function<T1> &SF,Function<T2> &TF) {};
// toute fonctios utiles . prevoir un algorithme  ad hoc pour l'appliquer sur ts les pts de gauss ...
};


class TermBilinearMeca : public TermBilinear<double,double>
{
public:
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



class FormBilinearBase
{
  public: 
  template <class T> void allocate(T *p) {p=new T[10];std::cout << "10" << std::endl;}
  template <class T> void get(T* tab, T *p, int ndx) {p=&tab[ndx];}
};

template <> void FormBilinearBase::allocate(void *p) {p=NULL; std::cout << "null" << std::endl;}
template <> void FormBilinearBase::get(void *tab,void *p, int ndx) {p=NULL;}

template <class Term> class FormBilinear : public FormBilinearBase
   // Renvoie des matrices élémentaires (ff) 
                  // Accessoirement stocke des pointeurs vers les termes pour chaque element
                  // Doit etre initialisée AVANT toute opération (pour l'allocation)
                  // en principe ce truc ne devrait pas ^etre reimplemente
                  // il devrait donc dependre d'un parametre template TermBilinear
                  // elle sait "integrer" dans un elemeent
{

  typedef typename Term::Stype Stype; // le truc a stocker
  Term instance; // une instance du terme. E.g. utile pour toute initialisation (calcul tenseur materiel, etc...)
  Stype *p;
  MElement *e;
  Function<double> *a;
  Function<double> *b;
  double uvw[3];
  public:
  void func(void) { allocate(p);}
  void func2(void) { instance.getTerm(uvw,*e,*a,*b,p); }
};


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


#endif // highlevel_H
