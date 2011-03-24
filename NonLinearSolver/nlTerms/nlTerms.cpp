//
// C++ Interface: terms
//
// Description: Basic term for non linear solver
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "nlTerms.h"
#include "MInterfaceElement.h"
#include "unknownField.h"
#include "ipField.h"
template<> void BilinearTermPerturbation<double>::get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m) const
{
  MInterfaceElement *iele = dynamic_cast<MInterfaceElement*>(ele);
  std::vector<Dof> R;
  if(_nlterm->isData())
    _nlterm->set(&disp);
  if(iele == NULL){ // compute on element
    int nbdof = space1.getNumKeys(ele);
    m.resize(nbdof,nbdof,false); // set operation after
    disp.resize(nbdof);
    space1.getKeys(ele,R);
    _ufield->get(R,disp);

    // Size of force vector
    fp.resize(nbdof);
    fm.resize(nbdof);

    for(int i=0;i<nbdof;i++){
      // pertubation +
      disp(i) += _eps;
      _dom->computeIpv(_ipf->getAips(),ele,IPStateBase::current,_dom->getMaterialLaw(),disp);

      _nlterm->get(ele,npts,GP,fp);
      // perturbation -
      disp(i) -=_twoeps;
      _dom->computeIpv(_ipf->getAips(),ele,IPStateBase::current,_dom->getMaterialLaw(),disp);
      _nlterm->get(ele,npts,GP,fm);
      // restore dof value
      disp(i) += _eps;
      fp.axpy(fm,-1);
      m.copyOneColumn(fp,i); // divide by 1/(2eps) at the end
    }
    _dom->computeIpv(_ipf->getAips(),ele,IPStateBase::current,_dom->getMaterialLaw(),disp);
  }
  else{
    // get displacement of element
    space1.getKeys(iele->getElem(0),R);
    if(iele->getElem(0) != iele->getElem(1))
      space2.getKeys(iele->getElem(1),R);
    disp.resize(R.size());
    _ufield->get(R,disp);
    dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(_dom);
    bool virt=false;
    if(iele->getElem(0) == iele->getElem(1)) virt = true;
    // store in dispm and dispp
    int nbdof_m = space1.getNumKeys(iele->getElem(0));
    int nbdof_p = 0;
    dispm.resize(nbdof_m);
    for(int i=0;i<nbdof_m;i++)
      dispm(i) = disp(i);
    if(!virt){
      nbdof_p = space2.getNumKeys(iele->getElem(1));
      dispp.resize(nbdof_p);
      for(int i=0;i<nbdof_p;i++)
        dispp(i) = disp(i+nbdof_m);
      m.resize(nbdof_m+nbdof_p,nbdof_m+nbdof_p);
    }
    else
      m.resize(nbdof_m,nbdof_m,false);
    fp.resize(disp.size()); // use disp size to know the number of dof (here unknow if interafce or virtual interface)
    fm.resize(disp.size());

    // Perturbation on minus element
    for(int i=0;i<nbdof_m;i++){
      // dof perturbation +
      disp(i)+=_eps;
      dispm(i)+=_eps;
      dgdom->computeIpv(_ipf->getAips(),iele,GP,IPStateBase::current,dgdom->getMinusDomain(),dgdom->getPlusDomain(),
                        dgdom->getMaterialLawMinus(),dgdom->getMaterialLawPlus(),dispm,dispp,virt,false); // 0 for - elem and npts for + elem
      _nlterm->get(ele,npts,GP,fp);
      // dof perturbation -
      disp(i)-=_twoeps;
      dispm(i)-=_twoeps;
      dgdom->computeIpv(_ipf->getAips(),iele,GP,IPStateBase::current,dgdom->getMinusDomain(),dgdom->getPlusDomain(),
                        dgdom->getMaterialLawMinus(),dgdom->getMaterialLawPlus(),dispm,dispp,virt,false); // 0 for - elem and npts for + elem
      _nlterm->get(ele,npts,GP,fm);
      disp(i)+=_eps;
      dispm(i)+=_eps;
      fp.axpy(fm,-1);
      m.copyOneColumn(fp,i); // divide by 1/(2eps) at the end
    }
    // restore ipv value
    dgdom->computeIpv(_ipf->getAips(),iele,GP,IPStateBase::current,dgdom->getMinusDomain(), dgdom->getPlusDomain(),
                      dgdom->getMaterialLawMinus(),dgdom->getMaterialLawPlus(),dispm,dispp,virt,false); // 0 for - elem and npts for + elem
    if(!virt){ // Otherwise virtual interface element
      // Perturbation on plus element
      for(int i=0;i<nbdof_p;i++){
        // dof perturbation +
        disp(i+nbdof_m)+=_eps;
        dispp(i)+=_eps;
        dgdom->computeIpv(_ipf->getAips(),iele,GP,IPStateBase::current,dgdom->getMinusDomain(),dgdom->getPlusDomain(),
                          dgdom->getMaterialLawMinus(),dgdom->getMaterialLawPlus(),dispm,dispp,virt,false); // 0 for - elem and npts for + elem
        _nlterm->get(ele,npts,GP,fp);
        // dof perturbation +
        disp(i+nbdof_m)-=_twoeps;
        dispp(i)-=_twoeps;
        dgdom->computeIpv(_ipf->getAips(),iele,GP,IPStateBase::current,dgdom->getMinusDomain(),dgdom->getPlusDomain(),
                          dgdom->getMaterialLawMinus(), dgdom->getMaterialLawPlus(),dispm,dispp,virt,false); // 0 for - elem and npts for + elem
        _nlterm->get(ele,npts,GP,fm);
        disp(i+nbdof_m)+=_eps;
        dispp(i)+=_eps;
        fp.axpy(fm,-1);
        m.copyOneColumn(fp,i+nbdof_m); // divide by 1/(2eps) at the end
      }
      // restore ipv values
      dgdom->computeIpv(_ipf->getAips(),iele,GP,IPStateBase::current,dgdom->getMinusDomain(),dgdom->getPlusDomain(),
                        dgdom->getMaterialLawMinus(),dgdom->getMaterialLawPlus(),dispm,dispp,virt,false);
    }
  }
  // divide all components by 1/2eps
  m.scale(_onedivtwoeps);
//  m.print("matrix by perturbation");

}

