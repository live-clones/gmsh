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

#include "unknownStaticField.h"
#include "nonLinearMechSolver.h"
#include "MPoint.h"
unknownStaticField::unknownStaticField(dofManager<double> *pas, std::vector<partDomain*> &vdom, nonLinearMechSolver::contactContainer *acontact,
                                     const int nc, std::vector<std::pair<Dof,initialCondition::whichCondition> > &archiving,
                                     std::vector<archiveRigidContactDisp> &contactarch, const bool view_, const std::string filen
                                                                         ) : unknownField(pas,vdom,acontact,nc,archiving,contactarch,view_,filen)
{
  // build umap
  for(std::vector<partDomain*>::iterator itdom=vdom.begin(); itdom!=vdom.end(); ++itdom){
    partDomain *dom = *itdom;
    FunctionSpaceBase *sp = dom->getFunctionSpace();
    std::vector<Dof> R;
    for(groupOfElements::elementContainer::iterator it=dom->g->begin(); it!=dom->g->end(); ++it){
      MElement *ele = *it;
      sp->getKeys(ele,R);
      for(int i=0;i<R.size(); i++)
        umap.insert(std::pair<Dof,double>(R[i],0.));
      R.clear();
    }
  }

  // insert rigid contact Dof in umap
  for(nonLinearMechSolver::contactContainer::iterator it = acontact->begin(); it!=acontact->end(); ++it){
    contactDomain *cdom = *it;
    if(cdom->isRigid()){
      std::vector<Dof> R;
      rigidContactSpace *sp = dynamic_cast<rigidContactSpace*>(cdom->getSpace());
      sp->getKeysOfGravityCenter(R);
      for(int i=0;i<R.size(); i++)
        umap.insert(std::pair<Dof,double>(R[i],0.));
    }
  }

  this->buildView(vdom,0.,0,"displacement",-1,false);
}

void unknownStaticField::update(){
  double du;
  for(std::vector<partDomain*>::iterator itdom = domainVector->begin(); itdom!=domainVector->end(); ++itdom){
    partDomain *dom = *itdom;
    FunctionSpaceBase *sp = dom->getFunctionSpace();
    std::vector<Dof> R;
    if(!(dom->getFormulation())){
      for(groupOfElements::vertexContainer::iterator it=dom->g->vbegin(); it!=dom->g->vend(); ++it){
        MVertex *ver = *it;
        MPoint ele = MPoint(ver,-1); // We don't care about element number it's just to have the vertex keys
        sp->getKeys(&ele,R);
        for(int i=0;i<R.size();i++){
          pAssembler->getDofValue(R[i],du);
          bool in=false;
          for(std::vector<Dof>::iterator itD=fixedDof.begin(); itD<fixedDof.end();++itD)
            if(*itD==R[i]){in=true;break;}
          if(in) umap[R[i]] = du;
          else   umap[R[i]] +=du;
        }
        R.clear();
      }
    }
    else{

      for(groupOfElements::elementContainer::iterator it=dom->g->begin(); it!=dom->g->end(); ++it){
        MElement *ele = *it;
        sp->getKeys(ele,R);
        for(int i=0;i<R.size();i++){
          pAssembler->getDofValue(R[i],du);
          bool in=false;
          for(std::vector<Dof>::iterator itD=fixedDof.begin(); itD<fixedDof.end();++itD)
            if(*itD==R[i]){in=true;break;}
          if(in) umap[R[i]] = du;
          else   umap[R[i]] +=du;
        }
        R.clear();
      }
    }
  }
}


void unknownStaticField::get(Dof &D,double &udof) const{
  udof = umap.find(D)->second;
}

void unknownStaticField::get(std::vector<Dof> &R, std::vector<double> &disp) const{
  double du;
  for(int i=0;i<R.size(); i++){
    this->get(R[i],du);
    disp.push_back(du);
  }
}

void unknownStaticField::get(std::vector<Dof> &R, fullVector<double> &disp) const{
  double du;
  for(int i=0;i<R.size(); i++){
    this->get(R[i],du);
    disp(i) = du;
  }
}

/*void unknownStaticField:get(MVertex *ver,std::vector<double> &udofs){
  long int ent;
  if(!fullDg){
    ent = ver->getNum();
    udofs = umap.find(ent)->second;
  }
  else{
    Msg::Error("Impossible to get displacement by vertex for full Dg formulation. Work only with MElement");
  }
}*/

void unknownStaticField::get(partDomain *dom, MElement *ele,std::vector<double> &udofs, const int cc){
  std::vector<Dof> R;
  FunctionSpaceBase *sp = dom->getFunctionSpace();
  sp->getKeys(ele,R);
  this->get(R,udofs);
}

void unknownStaticField::get(partDomain *dom, MElement *ele,fullVector<double> &udofs, const int cc){
  std::vector<Dof> R;
  FunctionSpaceBase *sp = dom->getFunctionSpace();
  udofs.resize(sp->getNumKeys(ele));
  sp->getKeys(ele,R);
  this->get(R,udofs);
}

void unknownStaticField::get(partDomain *dom,MInterfaceElement* iele, std::vector<double> &udofs){
  this->get(dom,iele->getElem(0),udofs);
  if(!(iele->getElem(0)==iele->getElem(1))){// Virtual interface element
    this->get(dom,iele->getElem(1),udofs);
  }
}

void unknownStaticField::get(partDomain *dom1, partDomain *dom2,MInterfaceElement* iele, std::vector<double> &udofs){
  this->get(dom1,iele->getElem(0),udofs);
  if(!(iele->getElem(0)==iele->getElem(1))){// Virtual interface element
    this->get(dom2,iele->getElem(1),udofs);
  }
}

void unknownStaticField::get(FunctionSpaceBase *sp1, FunctionSpaceBase *sp2,MInterfaceElement* iele, std::vector<double> &udofs){
  std::vector<Dof> R;
  sp1->getKeys(iele->getElem(0),R);
  this->get(R,udofs);
  if(!(iele->getElem(0)==iele->getElem(1))){// Virtual interface element
    R.clear();
    sp2->getKeys(iele->getElem(1),R);
    this->get(R,udofs);
  }
}

/*void unknownStaticField:getForPerturbation(FunctionSpaceBase &sp, MInterfaceElement* iele, const bool minus, Dof &D, double pert, std::vector<double> &udofs){
  double eps = -pert;
  std::vector<Dof> R;
  sp.getKeys(iele->getElem(0),R);
  if(!minus){
    this->set(D,eps);
    this->get(R,udofs);
    this->set(D,pert);
  }
  else{
    this->get(R,udofs);
    this->set(D,eps);
  }
  if(!(iele->getElem(0)==iele->getElem(1)))// Virtual interface element
    R.clear();
    sp.getKeys(iele->getElem(1),R);
    this->get(R,udofs);
  if(minus)
    this->set(D,pert);
}*/

void unknownStaticField::updateFixedDof(){
  double u;
  for(std::vector<Dof>::iterator itD=fixedDof.begin(); itD<fixedDof.end();++itD){
    pAssembler->getDofValue(*itD,u);
    umap.find(*itD)->second=u;
  }

}
void unknownStaticField::archiving(const double time){
  FILE *fp;
  double u;
  for(std::vector<archiveNode>::iterator it = varch.begin(); it!=varch.end();++it){
    Dof D = it->D;
    this->get(D,u);
    // write in File
      std::ostringstream oss;
      oss << it->nodenum;
      std::string s = oss.str();
      // component of displacement
      int field,comp,num;
      Dof3IntType::getThreeIntsFromType(it->D.getType(),comp,field,num);
      oss.str("");
      oss << comp;
      std::string s2 = oss.str();
      std::string fname = "NodalDisplacement"+s+"comp"+s2+".csv";
      fp = fopen(fname.c_str(),"a");
      fprintf(fp,"%e;%e\n",time,u);
      fclose(fp);
  }
}

void unknownStaticField::setInitial(const std::vector<Dof> &R, const std::vector<double> &disp){
  for(int i=0;i<R.size();i++){
    umap[R[i]] = disp[i];
  }
}

/*
void unknownField::buildView(std::vector<partDomain*> &vdom,const double time,
                              const int nstep, const std::string &valuename, const int cc=-1, const bool binary=false){
  if(view){
    // test file size (and create a new one if needed)
    uint32_t fileSize;
    FILE *fp = fopen(fileName.c_str(), "r");
    if(!fp){
      Msg::Error("Unable to open file '%s'", fileName.c_str());
      return;
    }
    fseek (fp, 0, SEEK_END);
    fileSize = (uint32_t) (ftell(fp));
    if(fileSize > fmaxsize) this->updateFileName();
    fclose(fp);
    fp = fopen(fileName.c_str(), "a");

    // compute the number of element
    if(binary) Msg::Warning("Binary write not implemented yet");
    fprintf(fp, "$%s\n",dataname.c_str());
    fprintf(fp, "1\n\"%s\"\n",valuename.c_str());
    fprintf(fp, "1\n%.16g\n", time);
    fprintf(fp, "3\n%d\n%d\n%d\n", nstep, numcomp, totelem);
    std::vector<double> fieldData;
    if(type == ElementNodeData){
      for(std::vector<partDomain*>::iterator itdom=vdom.begin(); itdom!=vdom.end(); ++itdom){
        partDomain *dom = *itdom;
        for (groupOfElements::elementContainer::const_iterator it = dom->g->begin(); it != dom->g->end(); ++it){
          MElement *ele = *it;
          int numv = ele->getNumVertices();
          this->get(dom,ele,fieldData,cc);
          fprintf(fp, "%d %d",ele->getNum(),numv);
          for(int i=0;i<numv;i++)
            for(int j=0;j<numcomp;j++)
              fprintf(fp, " %.16g",fieldData[i+j*numv]);
          fprintf(fp,"\n");
          fieldData.clear();
        }
      }
      // loop on contact domain
      for(nonLinearMechSolver::contactContainer::iterator it=_allContact->begin(); it!=_allContact->end(); ++it){
        contactDomain *cdom = *it;
        if(cdom->isRigid()){
          for (groupOfElements::elementContainer::const_iterator it = cdom->gMaster->begin(); it != cdom->gMaster->end(); ++it){
            MElement *ele = *it;
            int numv = ele->getNumVertices();
            rigidContactSpace *spgc = dynamic_cast<rigidContactSpace*>(cdom->getSpace());
            std::vector<Dof> R;
            spgc->getKeysOfGravityCenter(R);
            this->get(R,fieldData);
            fprintf(fp, "%d %d",ele->getNum(),numv);
            for(int i=0;i<numv;i++)
              for(int j=0;j<numcomp;j++)
                fprintf(fp, " %.16g",fieldData[j]);
            fprintf(fp,"\n");
            fieldData.clear();
          }
        }
      }
    }
    else if(type == ElementData){
      for (unsigned int i = 0; i < vdom.size(); ++i)
        for (groupOfElements::elementContainer::const_iterator it = vdom[i]->g->begin(); it != vdom[i]->g->end(); ++it){
          MElement *ele = *it;
          fieldData.resize(numcomp);
          this->get(vdom[i],ele,fieldData,cc);
          fprintf(fp, "%d",ele->getNum());
          for(int j=0;j<numcomp;j++)
            fprintf(fp, " %.16g",fieldData[j]);
          fprintf(fp,"\n");
        }
    }
    fprintf(fp, "$End%s\n",dataname.c_str());
    fclose(fp);
  }
  else Msg::Warning("No displacement view created because the variable view is set to false for this field\n");
}
*/
