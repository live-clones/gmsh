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

#include "dofManager.h"

class entity{};
class Vector{};
class Tensor2{};
class Tensor4{};

template<class T> struct TensorialTraits{};

template<> struct TensorialTraits<double>
{
  typedef double ValType;
  typedef Vector GradType;
  typedef Tensor2 HessType;
};

template<> struct TensorialTraits<Vector>
{
  typedef Vector ValType;
  typedef Tensor2 GradType;
  typedef Tensor4 HessType;
};


template<class T> class Function  // Fonction au sens EF du terme.
                // renvoie valeur , gradient, hessien, etc...pour un element donné et un point donné
{
public:
  virtual ~Function(){}
  virtual void GetVal (double uvw[],entity *e, T& Val)const =0;
  virtual void GetGrad(double uvw[],entity *e,typename TensorialTraits<T>::GradType &Grad) const =0;
  virtual void GetHess(double uvw[],entity *e,typename TensorialTraits<T>::HessType &Hess)const =0;
};

class SpaceBase // renvoie des clefs de dofs
{
public:
  virtual void getDofs(entity *e,std::vector<Dof> &vecD)=0;
};

template<class T> class Space : public SpaceBase // renvoie des clefs de dofs et des fonctions de formes
{
public: 
  Space(){};
  virtual ~Space(){};
  virtual void getDofsandSFs(entity *e,std::vector<std::pair< Dof, Function<T>* > > &vecDFF) {}
  virtual void getSFs(std::vector<std::pair< Dof, Function<T>* > > &vecDFF)=0;
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
  TermBilinear();
  virtual double getTerm(double uvw[],entity &e,Function<T1> &SF,Function<T2> &TF) = 0;
};


class FormBilinear {};   // Renvoie des matrices élémentaires (ff) 
                  // Accessoirement stocke des pointeurs vers les termes pour chaque element
                  // Doit etre initialisée AVANT toute opération (pour l'allocation)
                  // en principe ce truc ne devrait pas ^etre reimplemente
                  // il devrait donc dependre d'un parametre template TermBilinear

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
