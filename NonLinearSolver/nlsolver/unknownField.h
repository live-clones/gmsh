//
// C++ Interface: terms
//
// Description: Class with the displacement field
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef UNKNOWNFIELD_H_
#define UNKNOWNFIELD_H_
#include "dofManager.h"
#include "PView.h"
#include "PViewData.h"
#include <stdint.h>
#include <stdlib.h>
#include "elementField.h"
#include "nonLinearBC.h"
#include "MInterfaceElement.h"
class contactDomain;
class elementField;
struct archiveRigidContactDisp;
struct archiveNode{
  long int nodenum;
  Dof D;
  initialCondition::whichCondition wc;
  archiveNode(Dof R, int n, initialCondition::whichCondition wv=initialCondition::position) : nodenum(n), D(R), wc(wv){}
  ~archiveNode(){};

};

class unknownField : public elementField{
 protected:
  dofManager<double> *pAssembler; // To access to component of equation system template this
  std::vector<Dof> fixedDof;
  std::vector<archiveNode> varch;
  std::vector<partDomain*> *domainVector;
  std::set<contactDomain*> *_allContact;
 public:
  // update all displacement value
  unknownField(dofManager<double> *pas, std::vector<partDomain*> &elas, std::set<contactDomain*> *acontact,
                      const int nc, std::vector<std::pair<Dof,initialCondition::whichCondition> > &archiving,
                      std::vector<archiveRigidContactDisp> &contactarch, const bool =true, const std::string="disp.msh");
  ~unknownField(){}
  virtual void update()=0;
  virtual void updateFixedDof()=0;
  // get Operation
  virtual void get(Dof &D,double &udof) const=0;
  virtual void get(std::vector<Dof> &R, std::vector<double> &disp) const=0;
  virtual void get(std::vector<Dof> &R, fullVector<double> &disp) const=0;
  virtual void get(partDomain *dom, MElement *ele,std::vector<double> &udofs, const int=-1)=0;
  virtual void get(partDomain *dom, MElement *ele,fullVector<double> &udofs, const int=-1)=0;
  virtual void get(partDomain *dom, MInterfaceElement* iele, std::vector<double> &udofs)=0;
  virtual void get(partDomain *dom1, partDomain*dom2, MInterfaceElement* iele, std::vector<double> &udofs)=0;
  virtual void get(FunctionSpaceBase *sp1,FunctionSpaceBase *sp2, MInterfaceElement *iele,std::vector<double> &udofs)=0;
  virtual void archiving(const double time)=0;
  virtual void setInitial(const std::vector<Dof> &R,const std::vector<double> &disp)=0;
//  virtual void buildView(std::vector<partDomain*> &vdom,const double time,
//                const int nstep, const std::string &valuename, const int cc,const bool binary);
};
#endif // _UNKNOWNFIELD_H_
