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
# ifndef _IPFIELD_H_
# define _IPFIELD_H_
#include<vector>
#include"quadratureRules.h"
#include "unknownField.h"
#include "elementField.h"
#include "GModel.h"
#include "ipstate.h"
#include "partDomain.h"
struct archiveIPVariable;
class IPField : public elementField {
  protected :
    // Struct for archiving
    struct ip2archive{
      MElement *ele; // element where the point is situated (if node is common to several element the first one met is chosen. Normally OK continuity)
      int numgauss; // local gauss num
      std::string fname; // file name where archive IP
      int comp;  // component to archive
      const partDomain *domain; // address of domain needed to access IP
      // constructor
      ip2archive(MElement *e, const partDomain *dom, const int nump, const int num, const int ipval) : ele(e),
                                                                                           domain(dom),numgauss(num), comp(ipval){
        // build file name
        std::ostringstream oss;
        oss << nump;
        std::string s = oss.str();
        oss.str("");
        oss << ipval;
        std::string s2 = oss.str();
        fname = "IP"+s+"val"+s2+".csv";
      }
      ip2archive(const ip2archive &source) : ele(source.ele), domain(source.domain){
        numgauss = source.numgauss;
        fname = source.fname;
        comp =source.comp;
      }
      ~ip2archive(){}
    };
    std::vector<partDomain*>* _efield;
    dofManager<double> *_dm;
    AllIPState *_AIPS;
    unknownField *_ufield;
    std::vector<ip2archive> viparch;
//    normalVariation _nvaripfield; // To avoid multiple allocation
 public :
  enum ElemValue{mean=10001, max=10002, min=10003}; // enum to select a particular value on element
  IPField(std::vector<partDomain*> *ef,dofManager<double>* pa,
          GModel *pmo, unknownField* uf, std::vector<archiveIPVariable> &vaip);
  void archive(const double time);

  AllIPState* getAips() const {return _AIPS;}
  ~IPField(){delete _AIPS;}
  void compute1state(IPStateBase::whichState ws);

  // On element only ?? Higher level to pass the associated element (pass edge num)
  // get value with a operation
  double getStress(const partDomain *ef,MElement *ele, const IPStateBase::whichState ws, const int num,
                   const int cmp) const;
  // function to archive
  virtual void get(partDomain *dom, MElement *ele, std::vector<double> &stress, const int cc=-1){
    switch(cc){
      case -1 :
        stress[0]= this->getStress(dom,ele,IPStateBase::current,mean,-1);
        break;
      case 0 :
        stress[0] = this->getStress(dom,ele,IPStateBase::current,mean,component::xx);
        break;
      case 1 :
        stress[0] = this->getStress(dom,ele,IPStateBase::current,mean,component::yy);
        break;
      case 2 :
        stress[0] = this->getStress(dom,ele,IPStateBase::current,mean,component::zz);
        break;
      case 3 :
        stress[0] = this->getStress(dom,ele,IPStateBase::current,mean,component::xy);
        break;
      case 4 :
        stress[0]= this->getStress(dom,ele,IPStateBase::current,max,-1);
    }
  }

  // Interaction with Aips
  void copy(IPStateBase::whichState source, IPStateBase::whichState dest){_AIPS->copy(source,dest);}
  void nextStep(const double time=0.){
    _AIPS->nextStep();
  }

  // initial broken
  void initialBroken(GModel* pModel, std::vector<int> &vnumphys);
  void initialBroken(MElement *iele, materialLaw *mlaw);

  template<class T> void getIPv(const MElement *ele,const T** vipv, const IPStateBase::whichState ws= IPStateBase::current) const
  {
    AllIPState::ipstateElementContainer* vips = _AIPS->getIPstate(ele->getNum());
    for(int i=0; i<vips->size(); i++){
      IPStateBase* ips = (*vips)[i];
      vipv[i] = dynamic_cast<const T*>(ips->getState(ws));
    }
  }
  template<class T> void getIPv(const MElement *ele,const T** vipv, const T** vipvprev) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(ele->getNum());
    for(int i=0; i<vips->size(); i++){
      IPStateBase* ips = (*vips)[i];
      vipv[i] = dynamic_cast<const T*>(ips->getState(IPStateBase::current));
      vipvprev[i] = dynamic_cast<const T*>(ips->getState(IPStateBase::previous));
    }
  }
  template<class T1,class T2> void getIPv(const MInterfaceElement *iele, const T1** vipv_m, const T2** vipv_p,
                                          const IPStateBase::whichState ws=IPStateBase::current) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    // SAME NUMBER OF GAUSS POINTS ON BOTH SIDES
    int npts = vips->size()/2;
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      IPStateBase *ipsp = (*vips)[i+npts];
      vipv_m[i] = dynamic_cast<const T1*>(ipsm->getState(ws));
      vipv_p[i] = dynamic_cast<const T2*>(ipsp->getState(ws));
    }
  }
  template<class T1,class T2> void getIPv(const MInterfaceElement *iele, const T1** vipv_m, const T1** vipvprev_m,
                                             const T2** vipv_p, const T2** vipvprev_p) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    // SAME NUMBER OF GAUSS POINTS ON BOTH SIDES
    int npts = vips->size()/2;
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      IPStateBase *ipsp = (*vips)[i+npts];
      vipv_m[i] = dynamic_cast<const T1*>(ipsm->getState(IPStateBase::current));
      vipv_p[i] = dynamic_cast<const T2*>(ipsp->getState(IPStateBase::current));
      vipvprev_m[i] = dynamic_cast<const T1*>(ipsm->getState(IPStateBase::previous));
      vipvprev_p[i] = dynamic_cast<const T2*>(ipsp->getState(IPStateBase::previous));
    }
  }
  template<class T1,class T2> void getIPv(const MInterfaceElement *iele, T1** vipv_m, T2** vipv_p,
                                             const IPStateBase::whichState ws=IPStateBase::current) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    // SAME NUMBER OF GAUSS POINTS ON BOTH SIDES
    int npts = vips->size()/2;
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      IPStateBase *ipsp = (*vips)[i+npts];
      vipv_m[i] = dynamic_cast<T1*>(ipsm->getState(ws));
      vipv_p[i] = dynamic_cast<T2*>(ipsp->getState(ws));
    }
  }
  template<class T1,class T2> void getIPv(const MInterfaceElement *iele, T1** vipv_m, T2** vipvprev_m,
                                             T2** vipv_p, T2** vipvprev_p) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    // SAME NUMBER OF GAUSS POINTS ON BOTH SIDES
    int npts = vips->size()/2;
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      IPStateBase *ipsp = (*vips)[i+npts];
      vipv_m[i] = dynamic_cast<T1*>(ipsm->getState(IPStateBase::current));
      vipv_p[i] = dynamic_cast<T2*>(ipsp->getState(IPStateBase::current));
      vipvprev_m[i] = dynamic_cast<T1*>(ipsm->getState(IPStateBase::previous));
      vipvprev_p[i] = dynamic_cast<T2*>(ipsp->getState(IPStateBase::previous));
    }
  }


  template<class T1> void getIPv(const MInterfaceElement *iele, const T1** vipv_m,
                                   const IPStateBase::whichState ws=IPStateBase::current) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    // SAME NUMBER OF GAUSS POINTS ON BOTH SIDES
    int npts = vips->size();
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      vipv_m[i] = dynamic_cast<const T1*>(ipsm->getState(ws));
    }
  }
  template<class T1> void getIPv(const MInterfaceElement *iele, const T1** vipv_m, const T1** vipvprev_m) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    // SAME NUMBER OF GAUSS POINTS ON BOTH SIDES
    int npts = vips->size();
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      vipv_m[i] = dynamic_cast<const T1*>(ipsm->getState(IPStateBase::current));
      vipvprev_m[i] = dynamic_cast<const T1*>(ipsm->getState(IPStateBase::previous));
    }
  }

  template<class T1> void getIPv(const MInterfaceElement *iele, T1** vipv_m,
                                   const IPStateBase::whichState ws=IPStateBase::current) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    int npts = vips->size();
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      vipv_m[i] = dynamic_cast<T1*>(ipsm->getState(ws));
    }
  }
  template<class T1> void getIPv(const MInterfaceElement *iele, T1** vipv_m, T1** vipvprev_m) const
  {
    AllIPState::ipstateElementContainer *vips = _AIPS->getIPstate(iele->getNumber());
    int npts = vips->size();
    for(int i=0;i<npts;i++){
      IPStateBase *ipsm = (*vips)[i];
      vipv_m[i] = dynamic_cast<T1*>(ipsm->getState(IPStateBase::current));
      vipvprev_m[i] = dynamic_cast<T1*>(ipsm->getState(IPStateBase::previous));
    }
  }
  double computeDeformationEnergy(MElement *ele, const partDomain *dom) const;
  double computeDeformationEnergy() const{
//    Msg::Error("Defo energy only for shell");
    double ener=0.;
    for(std::vector<partDomain*>::const_iterator itdom=_efield->begin(); itdom!=_efield->end(); ++itdom){
      partDomain *dom = *itdom;
      for(groupOfElements::elementContainer::const_iterator it=dom->g->begin(); it!=dom->g->end(); ++it){
        MElement *ele = *it;
        ener += this->computeDeformationEnergy(ele,dom);
      }
    }
    return ener;
  }
};
#endif // IPField

