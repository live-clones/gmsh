//
// C++ Interface: terms
//
// Description: Class to store internal variables at gauss point
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "ipstate.h"
#include "partDomain.h"
#include "MInterfaceElement.h"
#include "MElement.h"
IP3State::~IP3State(){
  if(_initial) delete _initial;
  if(_step2) delete _step2;
  if(_step1) delete _step1;
}

IP3State::IP3State(const IP3State &source) : IPStateBase()
{
  _initial = source._initial;
  _step1 = source._step1;
  _step2 = source._step2;
  _st = source._st;
}

IP3State & IP3State::operator = (const IPStateBase &source){
  IPStateBase::operator=(source);
  const IP3State *src = dynamic_cast<const IP3State*>(&source);
  *_initial = *src->_initial;
  *_step1 = *src->_step1;
  *_step2 = *src->_step2;
  _st = src->_st;
  return *this;
}

IPVariable* IP3State::getState(const whichState wst) const
{
  switch(wst){
    case initial :
      return _initial;
      break;
    case previous :
      if(*_st) return _step1; else return _step2;
      break;
    case current :
      if(*_st) return _step2; else return _step1;
      break;
    default : Msg::Error("Impossible to select the desired state for internal variable \n");
  }
}

AllIPState::AllIPState(GModel *pModel, std::vector<partDomain*> &vdom)
{
  state = true; // at creation of object state is true
  IntPt *GP; // needed to know the number of gauss point
  for(std::vector<partDomain*>::iterator itdom=vdom.begin(); itdom!=vdom.end(); ++itdom){
    partDomain *dom = *itdom;
    if(dom->IsInterfaceTerms()){
      dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
      materialLaw *mlawMinus = dgdom->getMaterialLawMinus();
      materialLaw *mlawPlus = dgdom->getMaterialLawPlus();
      // loop
      for(groupOfElements::elementContainer::const_iterator it=dgdom->gi->begin(); it!=dgdom->gi->end();++it){
        MElement *ele = *it;
        MInterfaceElement* iele = dynamic_cast<MInterfaceElement*>(ele);
 	    // 2* because IP is duplicated for fullDg formulation
        int npts_inter=2*dgdom->getInterfaceGaussIntegrationRule()->getIntPoints(ele,&GP);
        ipstateElementContainer tp(npts_inter);
        for(int i=0;i<npts_inter/2;i++){
          mlawMinus->createIPState(tp[i],&state,ele,iele->getElem(0)->getNumVertices());
        }
        for(int i=npts_inter/2;i<npts_inter;i++){
          mlawPlus->createIPState(tp[i],&state,ele,iele->getElem(1)->getNumVertices());
        }
        _mapall.insert(ipstatePairType(iele->getNum(),tp));
      }
      // Virtual interface element (no duplication)
      materialLaw *mlaw = dgdom->getMaterialLaw();
      for(groupOfElements::elementContainer::const_iterator it=dgdom->gib->begin(); it!=dgdom->gib->end();++it){
        MElement *ele = *it;
        MInterfaceElement *iele = dynamic_cast<MInterfaceElement*>(ele);
        int npts_inter=dgdom->getInterfaceGaussIntegrationRule()->getIntPoints(ele,&GP);
        ipstateElementContainer tp(npts_inter);
        for(int i=0;i<npts_inter;i++){
          mlaw->createIPState(tp[i],&state,ele,iele->getElem(0)->getNumVertices());
        }
        _mapall.insert(ipstatePairType(iele->getNum(),tp));
      }
    }
    // bulk element
    materialLaw *mlaw = dom->getMaterialLaw();
    for (groupOfElements::elementContainer::const_iterator it = dom->g->begin(); it != dom->g->end(); ++it){
      MElement *ele = *it;
      int npts_bulk=dom->getBulkGaussIntegrationRule()->getIntPoints(ele,&GP);
      ipstateElementContainer tp(npts_bulk);
      for(int i=0;i<npts_bulk;i++){
        mlaw->createIPState(tp[i],&state,ele,ele->getNumVertices());
      }
      _mapall.insert(ipstatePairType(ele->getNum(),tp));
    }
  }
}
AllIPState::~AllIPState()
{
  for(ipstateContainer::iterator it=_mapall.begin();it!=_mapall.end();++it){
    ipstateElementContainer vips = (*it).second;
    for(int i=0;i<vips.size();i++)
	  delete vips[i];
  }
};

AllIPState::ipstateElementContainer* AllIPState::getIPstate(const long int num)
{
  return &(_mapall.find(num)->second);
}

AllIPState::ipstateElementContainer* AllIPState::operator[](const long int num)
{
  return &(_mapall.find(num)->second);
}
