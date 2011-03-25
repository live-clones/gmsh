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
                                     const int nc, std::vector<archiveDispNode> &archiving,
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
          if( (alfind[i] == false) and (ver->getNum() == archiving[i]._vernum)){
            FilterDof* filter = dom->createFilterDof(archiving[i]._comp);
            for(int j=0;j<R.size();j++){
              if(filter->operator()(R[j])){
                alfind[i] = true;
                varch.push_back(archiveNode(R[j],ver->getNum(),archiving[i]._comp,archiving[i]._wc));
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
            if((alfind[i] == false) and(ver->getNum() == archiving[i]._vernum)){
              // get the comp of the archiving node
              alfind[i] = true;
              int comp = archiving[i]._comp;
              varch.push_back(archiveNode(R[j+comp*nbvertex],ver->getNum(),comp,archiving[i]._wc));
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
          rigidContactSpaceBase *sp = dynamic_cast<rigidContactSpaceBase*>(cdom->getSpace());
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

// Add contact archiving
void unknownField::buildView(std::vector<partDomain*> &vdom,const double time,
                              const int nstep, const std::string &valuename, const int cc, const bool binary){
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
            rigidContactSpaceBase *spgc = dynamic_cast<rigidContactSpaceBase*>(cdom->getSpace());
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
