//
// C++ Interface: energetic field
//
// Description: Class derived from element field to manage energetic balance
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "energyField.h"
#include "explicitHulbertChung.h"
#include "explicitDofManager.h"
#include "ipField.h"
#include "SVector3.h"
#include "unknownField.h"
#include "unknownDynamicField.h"
double dot(const std::vector<double> &a, const fullVector<typename dofManager<double>::dataMat> &b){
  double c = 0.;
  for(int i =0; i<a.size(); i++){
    c += a[i]*b(i);
  }
  return c;
}

double dot(const std::vector<double> &a, const std::vector<double> &b){
  double c=0.;
  for(int i =0; i<a.size(); i++){
    c += a[i]*b[i];
  }
  return c;
}

double energeticField::kineticEnergy() const {
  explicitHCDofManager<double> *ddm = dynamic_cast<explicitHCDofManager<double>*>(_pAssembler);
  if(ddm == NULL)  return 0.; // system is not dynamic --> kinetic energy = 0
  else return ddm->getKineticEnergy();
}

double energeticField::kineticEnergy(MElement *ele, const partDomain *dom) const{
  explicitHulbertChung<double> * esys = dynamic_cast<explicitHulbertChung<double>*>(_lsys);
  explicitHCDofManager<double> *ddm = dynamic_cast<explicitHCDofManager<double>*>(_pAssembler);
  double ener=0.;
  if(ddm != NULL){
    // get Dof
    std::vector<Dof> R;
    std::vector<double> velocities;
    std::vector<double> vmass;
    FunctionSpaceBase *sp = dom->getFunctionSpace();
    sp->getKeys(ele,R);
    int nkeys = sp->getNumKeys(ele);
    ddm->getDofValue(R,velocities,initialCondition::velocity);
    ddm->getVertexMass(R,vmass);
    for(int i=0; i!=nkeys; i++)
      ener+=vmass[i]*velocities[i]*velocities[i];
    R.clear(); velocities.clear(); vmass.clear();
  }
  return ener;
}

double energeticField::deformationEnergy(MElement *ele, const partDomain *dom) const{
  return _ipf->computeDeformationEnergy(ele,dom);
}

double energeticField::deformationEnergy() const{
  return _ipf->computeDeformationEnergy();
}

double energeticField::externalWork(){
  double Deltawext=0.;
  for(std::vector<partDomain*>::iterator itdom=_domvec.begin(); itdom!=_domvec.end();++itdom){
    partDomain *dom = *itdom;
    for(partDomain::neuContainer::iterator itn=dom->neuBegin(); itn!=dom->neuEnd();++itn){
      nonLinearNeumannBC *neu = *itn;
      FunctionSpaceBase *neuspace = neu->_space;
      fullVector<typename dofManager<double>::dataMat> localVector;
      std::vector<Dof> R;
      std::vector<double> disp;
      std::vector<double> deltau;
      for(groupOfElements::elementContainer::const_iterator it = neu->g->begin(); it!=neu->g->end(); ++it){
        MElement *e = *it;
        R.clear(); disp.clear(); deltau.clear();
        IntPt *GP;
        //int npts=dom->getBulkGaussIntegrationRule()->getIntPoints(e,&GP); ?????????,
        int npts = neu->integ->getIntPoints(e,&GP);
        neu->_term->get(e,npts,GP,localVector);
        fullVector<typename dofManager<double>::dataMat> fextnp1(localVector);
        neuspace->getKeys(e,R);
        _ufield->get(R,disp);
        int ndofs = neuspace->getNumKeys(e);
        // DeltaWext = 0.5*(Fn+1+Fn)*(un+1-un)
        for(int i=0;i<ndofs;i++){
          _fextnp1[R[i]] = localVector(i);
          localVector(i) += _fextn[R[i]];
          deltau.push_back(disp[i] - _dispn[R[i]]);
          _dispnp1[R[i]] = disp[i];
        }
        Deltawext += dot(deltau,localVector);
      }
    }
 }

  // Now compute the work of external forces due to prescribed displacement (-Wint - Winertia)
  // ATTENTION _allaef containts -fint so no minus
  // Do the scalar product on vector (more efficient) TO DO THE SCALAR PRODUCT WITH BLAS HOW ??
  std::vector<double> disp;
  std::vector<double> acc;
  std::vector<double> _mass;
  std::vector<double> forceval;
//  std::vector<double> finertval;
  std::vector<Dof> R;
  for(int i=0; i<_allaef.size(); i++){
    R.push_back(_allaef[i].D);
    forceval.push_back(_allaef[i].val);
  }
  _ufield->get(R,disp);
  // Compute inertial forces if needed
  explicitHCDofManager<double> *ddm = dynamic_cast<explicitHCDofManager<double>*>(_pAssembler);
  if(ddm != NULL){ // otherwise static cases and no inertial forces
    unknownDynamicField *duf = dynamic_cast<unknownDynamicField*>(_ufield);
    duf->get(R,acc,initialCondition::acceleration);
    ddm->getVertexMass(R,_mass);
    for(int i=0; i<forceval.size(); i++)
      forceval[i] -= _mass[i]*acc[i];
  }
  for(int i=0;i<R.size(); i++){
    _fextnp1[R[i]] = forceval[i];
    forceval[i] += _fextn[R[i]];
    _dispnp1[R[i]] = disp[i];
    disp[i] -= _dispn[R[i]];
  }

  Deltawext += dot(forceval,disp);

  // swap value (next step)
  _fextn.swap(_fextnp1);
  _dispn.swap(_dispnp1);

  // New value of Wext W = 0.5*F*u
  _wext += 0.5*Deltawext;
  return _wext;
}

void energeticField::get(partDomain *dom,MElement *ele,std::vector<double> &ener, const int cc){
  switch(cc){
   //case 0:
   // ener[0] = this->kineticEnergy(ele,dom) + this->deformationEnergy(ele,dom);
   // break;
   case 1:
    ener[0] = this->kineticEnergy(ele,dom);
    break;
   case 2:
    ener[0] = this->deformationEnergy(ele,dom);
    break;
   case 3:
    ener[0] = this->externalWork();
   default:
    ener[0] = this->kineticEnergy(ele,dom) + this->deformationEnergy(ele,dom);
  }
}

void energeticField::archive(const double time){
  FILE *fp = fopen(_fname.c_str(),"a");
  double ekin,edefo,etot,wext;
  ekin = this->kineticEnergy();
  edefo= this->deformationEnergy();
  wext = this->externalWork();
  etot = ekin + edefo;
  fprintf(fp,"%e;%e;%e;%e;%e;\n",time,ekin,edefo,wext,etot);
  fclose(fp);
}

