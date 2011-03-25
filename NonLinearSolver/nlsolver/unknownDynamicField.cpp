//
// C++ Interface: terms
//
// Description: Class with the displacement field for a dynamic system
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//

#include "unknownDynamicField.h"
#include "nlsolAlgorithms.h"
unknownDynamicField::unknownDynamicField(dofManager<double> *pas, std::vector<partDomain*> &vdom,
                                                   nonLinearMechSolver::contactContainer *acontact,
                                     const int nc, std::vector<archiveDispNode> &archiving,
                                     std::vector<archiveRigidContactDisp> &contactarch, const bool view_, const std::string filen) : unknownField(pas,vdom,acontact,nc,archiving,
                                                                                                                                                  contactarch,view_,filen)
{
  // to avoid constant dynamic cast
  dynassembler = dynamic_cast<explicitHCDofManager<double>*>(pAssembler);
}

void unknownDynamicField::update(){
  Msg::Warning("The update of displacement field is unnecessary for a dynamic scheme");
}

void unknownDynamicField::get(Dof &D,double &udof) const {
  this->get(D,udof,initialCondition::position);
}
void unknownDynamicField::get(Dof &D, double &udof, initialCondition::whichCondition wv) const {
  dynassembler->getDofValue(D,udof,wv);
}

void unknownDynamicField::get(std::vector<Dof> &R, std::vector<double> &udofs) const {
  this->get(R,udofs,initialCondition::position);
}

void unknownDynamicField::get(std::vector<Dof> &R, fullVector<double> &udofs) const {
  this->get(R,udofs,initialCondition::position);
}

void unknownDynamicField::get(std::vector<Dof> &R, std::vector<double> &udofs, initialCondition::whichCondition wv) const {
  double du;
  for(int i=0;i<R.size(); i++){
    this->get(R[i],du,wv);
    udofs.push_back(du);
  }
}
void unknownDynamicField::get(std::vector<Dof> &R, fullVector<double> &udofs, initialCondition::whichCondition wv) const {
  double du;
  for(int i=0;i<R.size(); i++){
    this->get(R[i],du,wv);
    udofs(i) = du;
  }
}

void unknownDynamicField::get(partDomain *dom,MElement *ele, std::vector<double> &udofs, const int cc){
  // -1 or 0 = position
  // 1 = velocity
  // 2 = acceleration
  initialCondition::whichCondition wv;
  if (cc==1)
    wv= initialCondition::velocity;
  else if(cc==2)
    wv= initialCondition::acceleration;
  else
    wv= initialCondition::position;
  FunctionSpaceBase *sp = dom->getFunctionSpace();
  std::vector<Dof> R;
  sp->getKeys(ele,R);
  this->get(R,udofs,wv);
}

void unknownDynamicField::get(partDomain *dom,MElement *ele, fullVector<double> &udofs, const int cc){
  // -1 or 0 = position
  // 1 = velocity
  // 2 = acceleration
  initialCondition::whichCondition wv;
  if (cc==1)
    wv= initialCondition::velocity;
  else if(cc==2)
    wv= initialCondition::acceleration;
  else
    wv= initialCondition::position;
  FunctionSpaceBase *sp = dom->getFunctionSpace();
  std::vector<Dof> R;
  sp->getKeys(ele,R);
  udofs.resize(sp->getNumKeys(ele));
  this->get(R,udofs,wv);
}

void unknownDynamicField::get(partDomain *dom,MInterfaceElement *iele, std::vector<double> &udofs){
  this->get(dom,iele,udofs,initialCondition::position);
}

void unknownDynamicField::get(partDomain *dom,MInterfaceElement *iele, std::vector<double> &udofs, initialCondition::whichCondition wv){
  this->get(dom,iele->getElem(0),udofs,wv);
  if(!(iele->getElem(0)==iele->getElem(1))){// Virtual interface element
    this->get(dom,iele->getElem(1),udofs,wv);
  }
}

void unknownDynamicField::get(partDomain *dom1, partDomain *dom2,
                                   MInterfaceElement *iele, std::vector<double> &udofs){
  this->get(dom1,dom2,iele,udofs,initialCondition::position);
}

void unknownDynamicField::get(FunctionSpaceBase*sp1, FunctionSpaceBase *sp2,
                                   MInterfaceElement *iele, std::vector<double> &udofs){
  this->get(sp1,sp2,iele,udofs,initialCondition::position);
}

void unknownDynamicField::get(partDomain *dom1, partDomain *dom2,
                                   MInterfaceElement *iele, std::vector<double> &udofs, initialCondition::whichCondition wv){
  this->get(dom1,iele->getElem(0),udofs,wv);
  if(!(iele->getElem(0)==iele->getElem(1))){// Virtual interface element
    this->get(dom2,iele->getElem(1),udofs,wv);
  }
}

void unknownDynamicField::get(FunctionSpaceBase *sp1, FunctionSpaceBase *sp2,
                                   MInterfaceElement *iele, std::vector<double> &udofs, initialCondition::whichCondition wv){
  std::vector<Dof> R;
  sp1->getKeys(iele->getElem(0),R);
  this->get(R,udofs,wv);
  if(!(iele->getElem(0)==iele->getElem(1))){// Virtual interface element
    R.clear();
    sp2->getKeys(iele->getElem(1),R);
    this->get(R,udofs,wv);
  }
}

void unknownDynamicField::updateFixedDof(){
  Msg::Warning("Impossible to update the fixed dof because the time step is not passed in argument");
}

void unknownDynamicField::updateFixedDof(const double timeStep){
  dynassembler->updateFixedDof(timeStep);
}

void unknownDynamicField::archiving(const double time){
  FILE *fp;
  double u;
  for(std::vector<archiveNode>::iterator it = varch.begin(); it!=varch.end();++it){
    Dof D = it->D;
    dynassembler->getDofValue(D,u,it->wc);
    // write in File
      std::ostringstream oss;
      oss << it->nodenum;
      std::string s = oss.str();
      // component of displacement
      int comp = it->_comp;
      oss.str("");
      oss << comp;
      std::string s2 = oss.str();
      std::string fname;
      switch(it->wc){
       case initialCondition::position:
        fname = "NodalDisplacement"+s+"comp"+s2+".csv";
        break;
       case initialCondition::velocity:
        fname = "NodalVelocity"+s+"comp"+s2+".csv";
        break;
       case initialCondition::acceleration:
        fname = "NodalAcceleration"+s+"comp"+s2+".csv";
        break;
      }
      fp = fopen(fname.c_str(),"a");
      fprintf(fp,"%e;%e\n",time,u);
      fclose(fp);
  }
}

void unknownDynamicField::setInitial(const std::vector<Dof> &R, const std::vector<double> &disp){
  for(int i=0;i<R.size();i++){
    dynassembler->setInitialCondition(R[i],disp[i],initialCondition::position);
  }
}
