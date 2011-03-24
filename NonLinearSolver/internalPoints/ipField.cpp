//
// C++ Interface: terms
//
// Description: Class to compute Internal point
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "ipField.h"
#include "mlaw.h"
#include "ipstate.h"
#include "nonLinearMechSolver.h"
void IPField::compute1state(IPStateBase::whichState ws){
  for(std::vector<partDomain*>::iterator itdom=_efield->begin(); itdom!=_efield->end(); ++itdom){
    partDomain *dom = *itdom;
    dom->computeIPVariable(_AIPS,_ufield,ws);
  }
}

void IPField::initialBroken(MElement *iele, materialLaw* mlaw ){
  Msg::Info("Interface element %d is broken at initialization",iele->getNum());
  materialLaw2LawsInitializer * mflaw = dynamic_cast<materialLaw2LawsInitializer*>(mlaw);
  // get ipstate
  AllIPState::ipstateElementContainer *vips;
  IPStateBase *ips;
  vips = _AIPS->getIPstate(iele->getNum());
  for(int i=0;i<vips->size();i++){
    ips = (*vips)[i];
    mflaw->initialBroken(ips);
  }
}

void IPField::initialBroken(GModel* pModel, std::vector<int> &vnumphys){
  std::vector<MVertex*> vv;
  for(int i=0;i<vnumphys.size();i++){
    // get the vertex associated to the physical entities
    pModel->getMeshVerticesForPhysicalGroup(1,vnumphys[i],vv);
    // find the InterfaceElement associated to these vertex (identify interior node as degree 2 min)
    for(std::vector<partDomain*>::iterator itfield = _efield->begin(); itfield != _efield->end(); ++itfield){
      dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(*itfield);
      for(groupOfElements::elementContainer::const_iterator it = dgdom->gi->begin(); it!=dgdom->gi->end(); ++it)
        for(int k=0;k<vv.size();k++)
          if(vv[k] == (*it)->getVertex(2) ) this->initialBroken(*it, dgdom->getMaterialLaw());
    }
    vv.clear();
  }
}

void IPField::archive(const double time){
  for(std::vector<ip2archive>::iterator it=viparch.begin(); it!=viparch.end(); ++it){
    ip2archive &ipa = *it;
    // get ip value
    double val;
    switch(ipa.comp){
      case -1 :
        val = this->getStress(ipa.domain,ipa.ele,IPStateBase::current,ipa.numgauss,-1);
        break;
      case 0 :
        val = this->getStress(ipa.domain,ipa.ele,IPStateBase::current,ipa.numgauss,component::xx);
        break;
      case 1 :
        val = this->getStress(ipa.domain,ipa.ele,IPStateBase::current,ipa.numgauss,component::yy);
        break;
      case 2 :
        val = this->getStress(ipa.domain,ipa.ele,IPStateBase::current,ipa.numgauss,component::zz);
        break;
      case 3 :
        val = this->getStress(ipa.domain,ipa.ele,IPStateBase::current,ipa.numgauss,component::xy);
        break;
      case 4 :
        val = this->getStress(ipa.domain,ipa.ele,IPStateBase::current,ipa.numgauss,-1);
    }
    FILE *fp = fopen(ipa.fname.c_str(),"a");
    fprintf(fp,"%e;%e\n",time,val);
    fclose(fp);
  }
}

double IPField::computeDeformationEnergy(MElement *ele, const partDomain *dom) const
{
  IntPt *GP;
  double jac[3][3];
  int npts = dom->getBulkGaussIntegrationRule()->getIntPoints(ele,&GP);
  AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(ele->getNum());
  double ener =0.;
  for(int i=0;i<npts;i++){
    IPStateBase* ips = (*vips)[i];
    IPVariableMechanics *ipv = dynamic_cast<IPVariableMechanics*>(ips->getState(IPStateBase::current));
    #ifdef DEBUG_
     if(ipv == NULL){
       Msg::Error("Compute defo energy on an non mechanics gauss' point");
       return 0.;
     }
    #endif
    double enerpt = ipv->defoEnergy();
    // gauss point weight
    double weight = GP[i].weight;
    // Shell Only compute detJ OK
//    IPVariableShell *ipvs = dynamic_cast<IPVariableShell*>(ipv);
//    double detJ2 = ipvs->getLocalBasis()->getJacobian();
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double detJ = ele->getJacobian(u, v, w, jac);
    ener += weight*detJ*enerpt;
  }
  return ener;
}

IPField::IPField(std::vector<partDomain*> *ef,dofManager<double>* pa,
          GModel *pmo, unknownField* uf, std::vector<archiveIPVariable> &vaip): _efield(ef), _dm(pa),
                                                                                     _ufield(uf),
                                                                                     elementField("stress.msh",100000000,1,
                                                                                                  elementField::ElementData,true){
  // Creation of storage for IP data
  _AIPS = new AllIPState(pmo, *_efield);
  // compute the number of element
  long int nelem=0;
  for(std::vector<partDomain*>::iterator itdom=_efield->begin(); itdom!=_efield->end(); ++itdom){
    partDomain *dom = *itdom;
    nelem+= dom->g->size();
  }
  this->setTotElem(nelem);
  this->buildView(*_efield,0.,0,"VonMises",-1,false);
  this->buildView(*_efield,0.,0,"sigmaxx",0,false);
  this->buildView(*_efield,0.,0,"sigmayy",1,false);
  this->buildView(*_efield,0.,0,"tauxy",3,false);

  // Initiate file
  FILE *fp = fopen("cohesiveLaw.csv","w");
  fprintf(fp,"time;inter num;gauss num;sc;deltac;delta;d_n;d_t;n22;m22;n21;m21\n");
  fclose(fp);
  fp = fopen("crackPath.csv","w");
  fprintf(fp,"time;inter num;x0;y0;z0;x1;y1;z1\n");
  fclose(fp);

  // Build the viparch vector (find the nearest ipvariable to each given vertex)
  for(std::vector<archiveIPVariable>::iterator ita=vaip.begin(); ita!=vaip.end(); ++ita){
    archiveIPVariable &aip = *ita;
    // get the vertex of the node
    groupOfElements g(0,aip.numphys);
    groupOfElements::vertexContainer::iterator itv = g.vbegin();
    MVertex *ver = *itv;
    bool flagfind=false;
    MElement *elefind = NULL;
    partDomain *domfind;
    dgPartDomain *dgdom;
    bool samedim = false;
    for(std::vector<partDomain*>::iterator itdom=_efield->begin(); itdom!=_efield->end(); ++itdom){
      partDomain *dom = *itdom;
      dgdom = dynamic_cast<dgPartDomain*>(dom);
      if(dgdom != NULL){ // otherwise the domain doesn't contain interface element
        for(groupOfElements::elementContainer::iterator it2 = dgdom->gi->begin(); it2 != dgdom->gi->end(); ++it2 ){
          MElement *iele = *it2; // two elements on interface
          int numv = iele->getNumVertices();
          for(int j=0;j<numv;j++){
            if(ver == iele->getVertex(j)){
              elefind = iele;
              domfind = dom;
              flagfind = true;
              break;
            }
          }
          if(flagfind) break;
        }
        if(!flagfind){ // the interface element are on boundary
          for(groupOfElements::elementContainer::iterator iti = dgdom->gib->begin(); iti!=dgdom->gib->end(); ++iti){
            MElement *ie = *iti;
            int numv = ie->getNumVertices();
            for(int j=0;j<numv;j++){
              if(ver == ie->getVertex(j)){
                elefind = ie;
                domfind = dom;
                flagfind = true;
                break;
              }
            }
            if(flagfind) break;
          }
        }
      }
      if(!flagfind){ // no interface element found (Can happend on boundary)
        for(groupOfElements::elementContainer::iterator it2 = dom->g->begin(); it2 != dom->g->end(); ++it2 ){
          MElement *ele = *it2;
          int numv = ele->getNumVertices();
          for(int j=0;j<numv;j++){
            if(ver == ele->getVertex(j)){
              elefind = ele;
              samedim = true;
              flagfind = true;
              domfind = dom;
              break;
            }
          }
          if(flagfind) break;
        }
      }
    }
    // Now the element where is situated the node is know find the nearest Gauss Point
    IntPt *GP;
    QuadratureBase *gq;
    if(samedim){ //bulk point
      gq = domfind->getBulkGaussIntegrationRule();
    }
    else{
      dgPartDomain *dgfind = dynamic_cast<dgPartDomain*>(domfind);
      gq = dgfind->getInterfaceGaussIntegrationRule();
    }
    int npts = gq->getIntPoints(elefind,&GP);
     // coordonate in uvw of vertex
    double uvw[3];
    double xyz[3];
    xyz[0] = ver->x(); xyz[1] = ver->y(); xyz[2] = ver->z();
    elefind->xyz2uvw(xyz,uvw);
    double distmin = 1.e100; // inf value at itnitialization
    double dist, u,v,w;
    int nummin;
    for(int i=0;i<npts;i++){
      u = GP[i].pt[0]; v = GP[i].pt[1]; w = GP[i].pt[2];
      dist = sqrt((u-uvw[0])*(u-uvw[0]) + (v-uvw[1])*(v-uvw[1]) + (w-uvw[2])*(w-uvw[2]));
      if(dist<distmin){
        distmin = dist;
        nummin = i;
      }
    }
    // Store information
    viparch.push_back(ip2archive(elefind,domfind,aip.numphys,nummin,aip.ipval));
    // remove file LINUX ONLY ??
    std::ostringstream oss;
    oss << aip.numphys;
    std::string s = oss.str();
    oss.str("");
    oss << aip.ipval;
    std::string s2 = oss.str();
    std::string rfname = "rm IP"+s+"val"+s2+".csv";
    system(rfname.c_str());
  }
}

double IPField::getStress(const partDomain *ef,MElement *ele, const IPStateBase::whichState ws,
                            const int num, const int cmp) const{
  double svm =0.;
  if(num<10000){ // value in a particular gauss point
    IPStateBase* ips = (*_AIPS->getIPstate(ele->getNum()))[num];
    IPVariableMechanics *ipv = dynamic_cast<IPVariableMechanics*>(ips->getState(ws));
    #ifdef DEBUG_
     if(ipv != NULL)
    #endif
      return ipv->stressComp(cmp);
    #ifdef DEBUG_
     else{
      Msg::Error("Compute Von Mises stress on a non mechanical element");
      return 0.;
     }
    #endif
  }
  else{ // loop on all IPVariable of an element and return a particular value (max, min, mean)
    double svmp;
    IntPt *GP;
    int npts = ef->getBulkGaussIntegrationRule()->getIntPoints(ele,&GP);
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(ele->getNum());
    for(int i=0;i<npts;i++){
      IPStateBase* ips = (*vips)[i];
      IPVariableMechanics *ipv = dynamic_cast<IPVariableMechanics*>(ips->getState(ws));
      #ifdef DEBUG_
      if(ipv == NULL){
        Msg::Error("Compute Von Mises stress on a non mechanical element");
        return 0.;
      }
      #endif
      svmp = ipv->stressComp(cmp);
      if(i==0)
        svm = svmp;
      else{
        switch(num){
          case IPField::max :
            if(svmp>svm) svm=svmp;
            break;
          case IPField::min :
            if(svmp<svm) svm=svmp;
            break;
          case IPField::mean :
            svm+=svmp;
            break;
        }
      }
    }
    if(num==IPField::mean) svm/=(double)npts;
  }
  return svm;
}

