//
// contact base term
//
// Description: define contact terms
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef CONTACTTERMS_H_
#define CONTACTTERMS_H_
#include "terms.h"
#include "nodeStiffnessContact.h"
#include "contactFunctionSpace.h"
class unknownField;
template<class T1=double> class contactLinearTermBase : public LinearTermBase<T1>{
 protected:
  contactNodeStiffness *_allcontactNode; // need to compute BilinearTerm with more efficiency (compute only for nodes in contact)
 public:
  contactLinearTermBase(){
    _allcontactNode = new contactNodeStiffness();
  }
  contactLinearTermBase(const contactLinearTermBase &source){
    _allcontactNode = source._allcontactNode;
  }
  virtual ~contactLinearTermBase(){delete _allcontactNode;}
  contactNodeStiffness* getContactNode() const {return _allcontactNode;}
  void clearContactNodes(){_allcontactNode->clear();}
//  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<T1> &v)=0;
};

template <class T2=double>class  contactBilinearTermBase : public BilinearTermBase
{
 protected:
  contactLinearTermBase<T2> *_lterm; // because bilinear terms is compute only for nodes
                                 // in contact. These nodes are in the linear terms associated to bilinearTerm
 public:
  contactBilinearTermBase(contactLinearTermBase<T2> *lterm) : _lterm(lterm){}
  virtual ~contactBilinearTermBase(){}
//  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<T2> &m) const=0;
  // same for all contact
  contactLinearTermBase<T2>* getLterm() const{return _lterm;}
  contactNodeStiffness * getContactNodes() const{return _lterm->getContactNode();}
  void clearContactNodes(){_lterm->clearContactNodes();}
};

template<class T2=double> class rigidContactLinearTermBase : public contactLinearTermBase<T2>{
 protected:
  const unknownField *_ufield;
  rigidContactSpace *_spc;
  // data for get function (Allocated once)
  mutable SVector3 _lastNormalContact; // allow to use the normal in the 2 get functions not very elegant
  mutable int nbdofs,nbdofsGC, nbvertex,nbcomp,nbcomptimenbvertex;
  mutable std::vector<double> disp;
  mutable std::vector<Dof> R;
  mutable double verdisp[6];
  mutable double mvalue[6];
  mutable MVertex *ver;
 public:
  rigidContactLinearTermBase(rigidContactSpace *sp,
                             const unknownField *ufield) : contactLinearTermBase<T2>(),
                                                                 _ufield(ufield), _spc(sp), _lastNormalContact(0.,0.,0.),
                                                                 nbdofs(0), nbdofsGC(0), nbvertex(0), nbcomp(0), nbcomptimenbvertex(0)
  {

  }
  rigidContactLinearTermBase(const rigidContactLinearTermBase<T2> &source) : contactLinearTermBase<T2>(source){
    _ufield = source._ufield;
    _spc = source._spc;
  }
  ~rigidContactLinearTermBase(){}
//  virtual void get(MElement *ele, fullVector<double> &m);
  virtual void get(const MVertex *ver, const double disp[6],double mvalue[6]) const=0;
  // same for ALL RIGID CONTACT
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<T2> &v) const;
};
#endif // CONTACTTERMS_H_
