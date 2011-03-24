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

#include "unknownField.h"
#include "nonLinearMechSolver.h"
#include "nlsolAlgorithms.h"
#include "MPoint.h"
// constructor

unknownField::unknownField(dofManager<double> *pas, std::vector<partDomain*> &vdom, nonLinearMechSolver::contactContainer *acontact,
                                     const int nc, std::vector<std::pair<Dof,initialCondition::whichCondition> > &archiving,
                                     std::vector<archiveRigidContactDisp> &contactarch, const bool view_, const std::string filen): pAssembler(pas),
                                                                            domainVector(&vdom),
                                                                            _allContact(acontact),
                                                                            elementField(filen,100000000,nc,elementField::ElementNodeData,view_)
{


  pAssembler->getFixedDof(fixedDof);
  std::vector<bool> alfind;
  for(int i=0;i<archiving.size(); i++)
    alfind.push_back(false);
  long int totelem=0;
  for(std::vector<partDomain*>::iterator itdom=vdom.begin(); itdom!=vdom.end(); ++itdom){
    partDomain *dom = *itdom;
    bool fullDg = dom->getFormulation();
    FunctionSpaceBase *sp = dom->getFunctionSpace();
    std::vector<Dof> R;
    totelem += dom->g->size();
    if(!fullDg){
      for(groupOfElements::vertexContainer::iterator it=dom->g->vbegin(); it!=dom->g->vend(); ++it){
        MVertex *ver = *it;
        MPoint ele = MPoint(ver,-1); // We don't care about element number it is just to have the vertex keys;
        sp->getKeys(&ele,R);
        // make dof for archiving node
        for(int i=0;i<archiving.size();i++){
          if( (alfind[i] == false) and (ver->getNum() == archiving[i].first.getEntity())){
            // get the comp of the archiving node
            int comp,field,num;
            Dof3IntType::getThreeIntsFromType(archiving[i].first.getType(),comp,field,num);
            FilterDof* filter = dom->createFilterDof(comp);
            for(int j=0;j<R.size();j++){
              if(filter->operator()(R[j])){
                alfind[i] = true;
                varch.push_back(archiveNode(R[j],ver->getNum(),archiving[i].second));
              }
            }
          }
        }
        R.clear();
      }
    }
    else{
      // loop on element (entity of formulation)
      for(groupOfElements::elementContainer::iterator it=dom->g->begin(); it!=dom->g->end(); ++it){
        MElement *ele = *it;
        sp->getKeys(ele,R);
        // loop on vertex element (for archiving node)
        int nbvertex = ele->getNumVertices();
        for(int j=0;j<nbvertex;j++){
          MVertex *ver = ele->getVertex(j);
          for(int i=0; i<archiving.size(); i++){
            if((alfind[i] == false) and(ver->getNum() == archiving[i].first.getEntity())){
              // get the comp of the archiving node
              int comp,field,num;
              Dof3IntType::getThreeIntsFromType(archiving[i].first.getType(),comp,field,num);
              alfind[i] = true;
              varch.push_back(archiveNode(R[j+comp*nbvertex],ver->getNum(),archiving[i].second));
              break;
            }
          }
        }
        R.clear();
      }
    }
  }
  // increment the total element with rigid contact and add archiving if necessary

  for(nonLinearMechSolver::contactContainer::iterator it = _allContact->begin(); it!=_allContact->end(); ++it){
    contactDomain *cdom = *it;
    if(cdom->isRigid()){
      totelem += cdom->gMaster->size();
      int pMaster = cdom->getTag();
      for(int i=0;i<contactarch.size(); i++){
        if(contactarch[i]._physmaster == pMaster){
          rigidContactSpace *sp = dynamic_cast<rigidContactSpace*>(cdom->getSpace());
          std::vector<Dof> R;
          sp->getKeysOfGravityCenter(R);
          for(int j=0;j<R.size(); j++)
            if(contactarch[i]._fdof->operator()(R[j]))
              varch.push_back(archiveNode(R[j],pMaster,contactarch[i]._wc));
        }
      }
    }
  }
  this->setTotElem(totelem);
}
