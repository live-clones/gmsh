//
// contact base term
//
// Description: contact with a rigid cylinder
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef RIGIDCONTACTCYLINDER_H_
#define RIGIDCONTACTCYLINDER_H_
#include "contactTerms.h"
#include "contactFunctionSpace.h"
class rigidCylinderContactDomain;
class massRigidCylinder : public BilinearTermBase{
 protected:
  double _length, _radius, _thick, _rho;
  rigidContactSpaceBase *_spc;
  // Data for get function (Allocated once)
  mutable int nbdofs;
  mutable double masse;
  mutable double Rint;
 public:
  massRigidCylinder(rigidCylinderContactDomain *cdom,rigidContactSpaceBase *spc);
  massRigidCylinder(rigidContactSpaceBase *spc,double leng, double radius,
                    double thick,double rho) : _spc(spc), _length(leng), _radius(radius),_thick(thick), _rho(rho){}
  // Arguments are useless but it's allow to use classical assemble function
  void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const
  {
    Msg::Error("Define me get by integration point massRigidCylinder");
  }
  virtual BilinearTermBase* clone () const
  {
    return new massRigidCylinder(_spc,_length,_radius,_thick,_rho);
  }
};

class forceRigidCylinderContact : public rigidContactLinearTermBase<double>{
 protected:
  const rigidCylinderContactDomain *_cdom;
  double _fdgfactor, _facGC;
  const MVertex *_vergc;
  const SVector3* _axisDirector;
  const double _radius;
  const double _rcontact;
  const double _halflength;
  double _penalty;
  const SPoint3 _GC;
  // Data of get function (Allocated once)
  mutable SPoint3 B,Bdisp,A,Adisp,C;
  mutable double d,penetration,penpen;
  mutable SVector3 dirAC;
 public:
  forceRigidCylinderContact(const rigidCylinderContactDomain *cdom,
                            rigidContactSpaceBase *sp,const double thick,
                            const unknownField *ufield);
  ~forceRigidCylinderContact(){}
//  void get(MElement *ele,int npts, IntPt *GP,fullVector<double> &m);
  // specific function to this contact type ( put in rigidContactSpaceBase ??)
  // This one cannot be called by Assemble function
  void get(const MVertex *ver, const double disp[6],double mvalue[6]) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<double> > &vv) const
  {
    Msg::Error("define me get by gauss point forceRigidCylinderContact");
  }
  virtual LinearTermBase<double>* clone () const
  {
    return new forceRigidCylinderContact(_cdom,this->_spc,_rcontact-_radius,_ufield);
  }
};


class stiffnessRigidCylinderContact : public contactBilinearTermBase<double>{
 private:
  // can be applied only be applied by classical get function perturbation for 1 vertex
  void get(MElement *ele, const int verIndex, fullMatrix<double> &m) const;
 protected:
  const unknownField *_ufield;
  rigidContactSpaceBase *_spc;
  const double _perturbation; // numerical perturbation
  const double _doublepertexpm1;
  // Data for get function (Allocated Once)
  mutable double fp[6];
  mutable double fm[6];
  mutable int nbdofs;
  mutable MVertex *ver;
  mutable std::vector<Dof> R;
  mutable std::vector<double> disp;
  mutable double pertdisp[6];
 public:
  stiffnessRigidCylinderContact(rigidContactSpaceBase *space, contactLinearTermBase<double> *lterm, const unknownField *ufield) : contactBilinearTermBase(lterm),
                                                                                                _ufield(ufield),
                                                                                                _perturbation(1.e-10),
                                                                                                _doublepertexpm1(1./(2.e-10)),
                                                                                                _spc(space), nbdofs(0){}
  ~stiffnessRigidCylinderContact(){}
  void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const
  {
    Msg::Error("Define me get by integration point stiffnessRigidCylinderContact");
  }
  virtual BilinearTermBase* clone () const
  {
    return new stiffnessRigidCylinderContact(_spc,_lterm,_ufield);
  }
};


#endif // RIGIDCONTACTCYLINDER_H_

