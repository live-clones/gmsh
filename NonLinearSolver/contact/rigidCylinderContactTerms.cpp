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
#include "rigidCylinderContactTerms.h"
#include "contactDomain.h"
#include "unknownField.h"
massRigidCylinder::massRigidCylinder(rigidCylinderContact *cdom,
                                     rigidContactSpace *spc) : _length(cdom->getLength()),_radius(cdom->getRadius()),
                                                               _thick(cdom->getThickness()),_rho(cdom->getDensity()),
                                                               _spc(spc),nbdofs(0.), masse(0.),Rint(0.){}

void massRigidCylinder::get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m) const
{
  // get the number of cylinder component (same mass in all direction)
  int nbdofs = _spc->getNumKeysOfGravityCenter();
  m.resize(nbdofs,nbdofs,true); // true --> setAll(0.)
  if(_thick > _radius){ // full cylinder
    masse = _rho*M_PI*_radius*_radius*_length;
  }
  else{ // hollow cylinder
    Rint = _radius-_thick;
    masse = _rho*M_PI*_thick*(_radius*_radius-Rint*Rint);
  }
  for(int i=0;i<nbdofs;i++)
      m(i,i) = masse;
}

 forceRigidCylinderContact::forceRigidCylinderContact(const rigidCylinderContact *cdom,
                            rigidContactSpace *sp,const double thick,
                            const unknownField *ufield) : rigidContactLinearTermBase(sp,ufield), _cdom(cdom),
                                                                _vergc(cdom->getGC()),
                                                                _axisDirector(cdom->getAxisDirector()),
                                                                _radius(cdom->getRadius()),
                                                                _rcontact(cdom->getRadius() + 0.*thick),
                                                                _halflength(0.5*cdom->getLength()),
                                                                _GC(cdom->getGC()->point()), d(0.),
                                                                penetration(0.), penpen(0.)
{
  if(_cdom->getDomain()->IsInterfaceTerms()){
    partDomain *dom = dynamic_cast<partDomain*>(_cdom->getDomain());
    if(dom->getFormulation()){
      _fdgfactor = 1.;
      _facGC =0.5;
    }
    else{
      _fdgfactor = 0.5;
      _facGC =1.;
    }
  }
  else{
    _fdgfactor = 0.5;
    _facGC = 1.;
  }
  _penalty = _fdgfactor*_cdom->getPenalty();
}

void forceRigidCylinderContact::get(const MVertex *ver, const double disp[6],double mvalue[6]) const
{
  // B = axis' center
  // A = vertex for which we look for contact
  B = _GC;
  Bdisp.setPosition(disp[3],disp[4],disp[5]);
  B+=Bdisp;
  // Distance between vertex and cylinder axis
  // line BA
  A = ver->point();
  Adisp.setPosition(disp[0],disp[1],disp[2]);
  A+=Adisp;
  SVector3 BA(A,B);
  dirAC = crossprod(BA,*_axisDirector);
  double d = dirAC.norm();
  // test to know if contact
  if(d < _rcontact){
    // check if contact occur before end of cylinder
    dirAC.normalize();
    _lastNormalContact = crossprod(dirAC,*_axisDirector);
    _lastNormalContact.normalize();
    C.setPosition(A,_lastNormalContact.point(),-d);
      // check normal direction if C is further of B than A the direction is wrong
      if(C.distance(B) > A.distance(B)){
        _lastNormalContact.negate();
        _lastNormalContact.normalize();
        C.setPosition(A,_lastNormalContact.point(),-d);
      }
      if(C.distance(B) < _halflength){
        penetration = _rcontact-d;
        penpen = penetration*_penalty;
        for(int j=0;j<3;j++){
          mvalue[j]+= penpen*_lastNormalContact(j);
          mvalue[j+3] -=_facGC*penpen*_lastNormalContact(j); // count two times
        }
      }
    }
}

void stiffnessRigidCylinderContact::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const
{
  int nbdofs = _spc->getNumKeys(ele);
  m.resize(nbdofs,nbdofs,true); // true --> setAll(0.)
  // search the vertices for which the matrix has to be computed
  contactNodeStiffness * contactNodes = _lterm->getContactNode();
  for(contactNodeStiffness::nodeContainer::const_iterator itn = contactNodes->nBegin(); itn!= contactNodes->nEnd(); ++itn){
    if(itn->_ele == ele){ // contact
      this->get(ele,itn->_verIndex,m);
    }
  }
}

// Protected can only be called by stiffnessRigidCylinderContact::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m)
// NO RESIZE
void stiffnessRigidCylinderContact::get(MElement *ele, const int verIndex, fullMatrix<double> &m) const
{
  // perturbation numeric
  rigidContactLinearTermBase<double>* rlterm = dynamic_cast<rigidContactLinearTermBase<double>*>(_lterm);
  int nbdofselem = _spc->getNumKeys(ele) - _spc->getNumKeysOfGravityCenter();
  int nbFF = ele->getNumVertices();
  ver = ele->getVertex(verIndex);
  disp.clear(); R.clear();
  _spc->getKeys(ele,verIndex,R);
  _ufield->get(R,disp);
  for(int j=0;j<6;j++)
    pertdisp[j] = disp[j];

  // perturbation on each Dofs 3 for vertex and 3 for GC of cylinder
  for(int i=0;i<6;i++){
    // set force component to zero
    for(int j=0;j<6;j++)
      fp[j] = fm[j] = 0.;

    // Force -
    pertdisp[i] = disp[i] - _perturbation;
    rlterm->get(ver,pertdisp,fm);

    // Force +
    pertdisp[i] = disp[i] + _perturbation;
    rlterm->get(ver,pertdisp,fp);

    // Assembly in matrix
    if(i<3){ // perturbation on vertex
      for(int j=0; j<3; j++){
        m(verIndex+nbFF*j,verIndex+nbFF*i) -= (fp[j]-fm[j])*_doublepertexpm1;
        m(nbdofselem+j,verIndex+nbFF*i) -= (fp[j+3]-fm[j+3])*_doublepertexpm1;
      }
    }
    else{ // perturbation on gravity center
      for(int j=0; j<3; j++){
        m(verIndex+nbFF*j,nbdofselem+i-3) -= (fp[j]-fm[j])*_doublepertexpm1;
        m(nbdofselem+j,nbdofselem+i-3) -= (fp[j+3]-fm[j+3])*_doublepertexpm1;
      }
    }
    // virgin pertdisp
    pertdisp[i] = disp[i];
  }

  // ANALYTIC WAY MUST BE FIXED
/*  int nbdofs = _spc->getNumKeys(ele);
  int nbvertex = ele->getNumVertices();
  int nbdofGC = _spc->getNumKeysOfGravityCenter();
  int nbcomp = (nbdofs-nbdofGC)/nbvertex;
  int nbcompTimesnbVertex = nbcomp*nbvertex;
  m.resize(nbdofs,nbdofs);
  m.setAll(0.);
  double penalty = _fdgfactor*_cdom->getPenalty();
  for(int i=0;i<nbvertex;i++){
    SVector3 nor = _allcontactNode->getNormal(ele,i);
    if(nor.norm() != 0.){ // otherwise no contact
      double dianor[3][3];
      diaprod(nor,nor,dianor);
      for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
          dianor[j][k]*=penalty;
      for(int j=0;j<nbcomp;j++)
        for(int k=0;k<nbcomp;k++){
          m(i+j*nbvertex,i+k*nbvertex) -= dianor[j][k];
          m(nbcompTimesnbVertex+j,nbcompTimesnbVertex+k) -=0.5*dianor[j][k];
        }
    }
  }
  m.print("Contact Matrix");*/
}

