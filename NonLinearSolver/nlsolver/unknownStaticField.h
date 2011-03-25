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

#ifndef UNKNOWNSTATICFIELD_H_
#define UNKNOWNSTATICFIELD_H_
#include "dofManager.h"
#include "PView.h"
#include "PViewData.h"
#include <stdint.h>
#include <stdlib.h>
#include "elementField.h"
#include "contactDomain.h"

class unknownStaticField : public unknownField{
  protected :
    std::map<Dof,double> umap; // One Entry by Dof allow to manage more than 1 domain
  public :
    unknownStaticField(dofManager<double> *pas, std::vector<partDomain*> &elas, std::set<contactDomain*> *acontact,
                      const int nc, std::vector<archiveDispNode> &archiving,
                      std::vector<archiveRigidContactDisp> &contactarch, const bool =true, const std::string="disp.msh"
                                                    ) ;
    // update all displacement value
    virtual void update();
    virtual void updateFixedDof();
    // get Operation
    virtual void get(Dof &D,double &udof) const;
    virtual void get(std::vector<Dof> &R, std::vector<double> &disp) const;
    virtual void get(std::vector<Dof> &R, fullVector<double> &disp) const;
//    virtual void get(MVertex *ver,std::vector<double> &udofs); // works only for cG/dG (TODO fullDg case)
    virtual void get(partDomain *dom, MElement *ele,std::vector<double> &udofs, const int=-1);
    virtual void get(partDomain *dom, MElement *ele,fullVector<double> &udofs, const int=-1);
    virtual void get(partDomain *dom, MInterfaceElement* iele, std::vector<double> &udofs);
    virtual void get(partDomain *dom1, partDomain*dom2, MInterfaceElement* iele, std::vector<double> &udofs);
    virtual void get(FunctionSpaceBase *sp1,FunctionSpaceBase *sp2, MInterfaceElement *iele,std::vector<double> &udofs);
    virtual void set(Dof &D, double &val){
      umap[D] += val;
    }
//    virtual void getForPerturbation(FunctionSpaceBase &sp,MInterfaceElement* iele, const bool minus, Dof &D, double pert, std::vector<double> &udofs);
    virtual void archiving(const double time);
    virtual void setInitial(const std::vector<Dof> &R,const std::vector<double> &disp);
//    virtual void buildView(std::vector<partDomain*> &vdom,const double time,
//                  const int nstep, const std::string &valuename, const int cc,const bool binary);
};
#endif // DISPLACEMENTFIELD_H_
