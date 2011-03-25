//
// contact Domain
//
// Description: Domain to solve contact problem
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "contactDomain.h"
contactDomain::contactDomain(const contactDomain &source){
  _tag = source._tag;
  _phys = source._phys;
  _physSlave = source._physSlave;
  _penalty = source._penalty;
  gSlave = source.gSlave;
  gMaster = source.gMaster;
  _dom = source._dom;
  _bterm = source._bterm;
  _massterm = source._massterm;
  _lterm = source._lterm;
  _contype = source._contype;
  _rigid = source._rigid;
  _space = source._space;
  _integ = source._integ;
}

void contactDomain::setContactType(const int ct){
  switch(ct){
   case 0:
    _contype = rigidCylinder;
    _rigid = true;
    break;
   case 1:
    _contype = rigidSphere;
    _rigid = true;
    break;
   default:
    Msg::Error("No contact know for int %d",ct);
  }
}

MElement* contactDomain::getFirstElement() const {
  groupOfElements::elementContainer::const_iterator it = gSlave->begin();
  return (*it);
}

rigidCylinderContactDomain::rigidCylinderContactDomain(const int tag, const int physMaster, const int physSlave, const int physPt1,
                                           const int physPt2, const double penalty,
                                           const double h,const double rho) : contactDomain(tag,physMaster,physSlave,
                                                                           penalty,rigidCylinder,true),
                                                               _thick(h), _density(rho){

  // void gauss integration
  _integ = new QuadratureVoid();

  // creation of group of elements
  gMaster = new groupOfElements(2,physMaster);
  gSlave = new groupOfElements(2,physSlave);
  // use for build --> no save
  groupOfElements gpt1 = groupOfElements(0,physPt1);
  groupOfElements gpt2 = groupOfElements(0,physPt2);

  // find GC and dimension of cylinder
  // get vertex
  groupOfElements::vertexContainer::iterator itpt1 = gpt1.vbegin();
  groupOfElements::vertexContainer::iterator itpt2 = gpt2.vbegin();
  MVertex *ver1 = *itpt1;
  MVertex *ver2 = *itpt2;
  // Vertices coordinates
  double x1 = ver1->x(); double y1 = ver1->y(); double z1 = ver1->z();
  double x2 = ver2->x(); double y2 = ver2->y(); double z2 = ver2->z();
  //creation of GC vertex
  double xgc = 0.5*(x1+x2); double ygc = 0.5*(y1+y2); double zgc = 0.5*(z1+z2);
  _vergc = new MVertex(xgc,ygc,zgc);
  // dimension of cylinder
  _length = ver1->distance(ver2);
  // Radius search for an extreme pnt (ie the point with the most distance of gc)
  double dist=-1.; // initialization
  MVertex *vermax;
  for(groupOfElements::vertexContainer::iterator it=gMaster->vbegin(); it!=gMaster->vend();++it){
    MVertex *ver = *it;
    double d = ver->distance(_vergc);
    if(d > dist){
      vermax = ver;
      dist = d;
    }
  }
  // radius = smallest distance of extreme point and a center
  double r1 = vermax->distance(ver1);
  double r2 = vermax->distance(ver2);
  (r1>r2) ? _radius=r2 : _radius=r1;

  // vector director of cylinder's axis
  _axisDirector = new SVector3(ver1->point(),ver2->point());
  _axisDirector->normalize();
}

void rigidCylinderContactDomain::initializeTerms(const unknownField *ufield){
  rigidContactSpaceBase *sp = dynamic_cast<rigidContactSpaceBase*>(_space);
  _massterm = new massRigidCylinder(this,sp);
  _lterm = new forceRigidCylinderContact(this,sp,_thickContact,ufield);
  rigidContactLinearTermBase<double> *rlterm = dynamic_cast<rigidContactLinearTermBase<double>*>(_lterm);
  _bterm = new stiffnessRigidCylinderContact(sp,rlterm,ufield);
}
