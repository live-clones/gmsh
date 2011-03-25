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
#ifndef UNKNOWNDYNAMICFIELD_H_
#define UNKNOWNDYNAMICFIELD_H_
#include "unknownField.h"
#include "explicitDofManager.h"
#include "explicitHulbertChung.h"

class unknownDynamicField : public unknownField{
 protected:
  explicitHCDofManager<double> *dynassembler;

 public:
  unknownDynamicField(dofManager<double> *pas, std::vector<partDomain*> &vdom,
                           nonLinearMechSolver::contactContainer *acontact,
                                     const int nc, std::vector<archiveDispNode> &archiving,
                                     std::vector<archiveRigidContactDisp> &contactarch, const bool view_=true, const std::string filen="disp.msh");

  virtual void update();
  virtual void get(Dof &D, double &udof) const;
  virtual void get(Dof &D, double &udof, initialCondition::whichCondition wv) const ;
  virtual void get(std::vector<Dof> &R, std::vector<double> &disp) const;
  virtual void get(std::vector<Dof> &R, fullVector<double> &disp) const;
  virtual void get(std::vector<Dof> &R, std::vector<double> &disp,initialCondition::whichCondition wv) const ;
  virtual void get(std::vector<Dof> &R, fullVector<double> &disp,initialCondition::whichCondition wv) const ;
  virtual void get(partDomain *dom,MElement *ele, std::vector<double> &udofs, const int cc= -1);
  virtual void get(partDomain *dom,MElement *ele, fullVector<double> &udofs, const int cc= -1);
  virtual void get(partDomain *dom, MInterfaceElement *iele, std::vector<double> &udofs);

  virtual void get(partDomain *dom, MInterfaceElement *iele, std::vector<double> &udofs, initialCondition::whichCondition);
  virtual void get(partDomain *dom1, partDomain *dom2, MInterfaceElement *iele, std::vector<double> &udofs) ;
  virtual void get(FunctionSpaceBase *sp1, FunctionSpaceBase *sp2, MInterfaceElement *iele, std::vector<double> &udofs) ;
  virtual void get(partDomain *dom1, partDomain *dom2, MInterfaceElement *iele, std::vector<double> &udofs,
                   initialCondition::whichCondition wv= initialCondition::position) ;
  virtual void get(FunctionSpaceBase *sp1, FunctionSpaceBase *sp2, MInterfaceElement *iele, std::vector<double> &udofs,
                   initialCondition::whichCondition wv= initialCondition::position) ;
  virtual void updateFixedDof();
  virtual void updateFixedDof(const double timeStep);
  virtual void archiving(const double time);
  virtual void setInitial(const std::vector<Dof> &R, const std::vector<double> &disp);
};
#endif // UNKNOWNDYNAMICFIELD_H_

