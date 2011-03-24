// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshConfig.h"
#include "nonLinearMechSolver.h"
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemGMM.h"
#include "Numeric.h"
#include "nlTerms.h"
#include "solverAlgorithms.h"
#include "quadratureRules.h"
#include "MPoint.h"
#include "ipstate.h"
#include "ipField.h"
#include "timeFunction.h"
#include "GModel.h"
#include "explicitHulbertChung.h"
#include "nlsolAlgorithms.h"
#include "nonLinearMechSolver.h"
#include "explicitDofManager.h"
#include "unknownDynamicField.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "energyField.h"
#include "nlsolAlgorithms.h"
#include "solverAlgorithms.h"
#include "quadratureRules.h"
#include "MPoint.h"
#include "timeFunction.h"
#include "unknownStaticField.h"
#include "staticDofManager.h"
#include "contactTerms.h"


#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

// nonLinearMechSolver
void nonLinearMechSolver::loadModel(const std::string meshFileName)
{
  pModel = new GModel();
  pModel->readMSH(meshFileName.c_str());
  _dim = pModel->getNumRegions() ? 3 : 2;
}

void nonLinearMechSolver::init(){

  // Set the material law for each domain and the gauss integration rule
  for(std::vector<partDomain*>::iterator it = domainVector.begin(); it!=domainVector.end(); ++it){
    partDomain *dom = *it;
    dom->setMaterialLaw(maplaw);
  }

  // create interfaceElement
  this->createInterfaceElement();

  for(std::vector<partDomain*>::iterator it = domainVector.begin(); it!=domainVector.end(); ++it){
    partDomain *dom = *it;
    dom->setGaussIntegrationRule();
  }

  // Split the BC between the different domain HAS TO BE AFTER DOMAIN INITIALIZATION
  this->splitBoundaryConditions();

  // initialisation of archiving force
  this->initArchiveForce();

  // find the domain associated to a physical slave number of a rigid contact interaction
  // WARNING a contact interaction cannot be defined on two domains in the same time
  // a physical group has to be define by domain
  this->initContactInteraction();
}

void nonLinearMechSolver::initContactInteraction(){
  // find a common element betwwen slave group of element and the group of element of partdomain
  bool flagfind;
  for(contactContainer::iterator it = _allContact.begin(); it!=_allContact.end(); ++it){
    contactDomain *cdom = *it;
    flagfind = false;
    // get first element
    MElement *elementcont = cdom->getFirstElement();
    for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom){
      partDomain *dom = *itdom;
      for(groupOfElements::elementContainer::iterator ite=dom->g->begin(); ite!=dom->g->end(); ++ite){
        MElement *ele = *ite;
        if(ele == elementcont){
          flagfind =true;
          cdom->setDomain(dom);
//          spaceManager->addSpace(cdom);
          break;
        }
      }
      if(flagfind) break;
    }
  }

  // now init the contact boundary conditions
  for(std::vector<rigidContactBC>::iterator it=allContactBC.begin(); it!=allContactBC.end(); ++it){
    rigidContactBC &diri = *it;
    if(diri.onWhat == nonLinearBoundaryCondition::RIGIDCONTACT){
      for(contactContainer::iterator itcdom = _allContact.begin(); itcdom!=_allContact.end(); ++itcdom){
        contactDomain *cdom = *itcdom;
        if(cdom->getPhys() == diri._tag){
          rigidContactSpace *sp = dynamic_cast<rigidContactSpace*>(cdom->getSpace());
          diri.setSpace(sp);
          break;
        }
      }
    }
  }
}

void nonLinearMechSolver::splitBoundaryConditions(){

  // loop on BC
   // BC which are prescribed weakly (the interfaceElement has to be finded in vinter)
   // to prescribed the BC

   // Theta
   for(std::vector<nonLinearNeumannBC>::iterator it=allTheta.begin(); it!=allTheta.end(); ++it){
     nonLinearNeumannBC &neu = *it;
     for(groupOfElements::elementContainer::iterator ite=neu.g->begin(); ite!=neu.g->end(); ++ite){
       MVertex *vv = (*ite)->getVertex(2);
       for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
         partDomain *dom = *itdom;
         if(dom->IsInterfaceTerms()){ // change this (virtual interface has to be defined on domain)
           // Ok because 2nd degree min BoundaryInterfaceElement is created only for this vertex
           dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
           groupOfElements *gvi = dgdom->giv;
           for(groupOfElements::elementContainer::const_iterator it_inter = gvi->begin(); it_inter!=gvi->end();++it_inter){
             MElement *minter = *it_inter;
             //loop on component of map_edge
             int numvertexminus1 = minter->getNumVertices()-1;
             if((vv == minter->getVertex(2)) or (vv == minter->getVertex(numvertexminus1))){
               dgdom->gib->insert(minter);
               break;
             }
           }
         }
       }
     }
   }

  //Dirichlet
  for(int i=0;i<allDirichlet.size();i++){
    // loop on element
    // map
    std::map<partDomain*,std::vector<MElement*> > mapfind;
    for(groupOfElements::elementContainer::iterator it=allDirichlet[i].g->begin(); it!=allDirichlet[i].g->end();++it){
      MElement *e = *it;
      // Loop on all Domain to find on which domain the BC is applied
      for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
        // if Dimensions are the same the element can be find with a comparison to element
        partDomain *dom = *itdom;
        // otherwise the vertex must be identified separately
        MElement *etest = *(dom->g->begin());
        if( (etest !=NULL) and (etest->getDim() == e->getDim())){
          for(groupOfElements::elementContainer::iterator it2=dom->g->begin(); it2!=dom->g->end(); ++it2){
            if(*it2 == e){ // The Element is contained in the domain
              mapfind[dom].push_back(e);
              break;
            }
          }
        }
        else{ // loop on Vertex identify the BC with first INTERIOR vertex of e degree 2 min OK ( border vertex are included in 2 elements)
               // an element is included in one domain --> one vertex of Element is OK
               // On interface the BC is put on the first met domain
          MVertex *ver = e->getVertex(2);
          for(groupOfElements::vertexContainer::iterator itv=dom->g->vbegin(); itv!=dom->g->vend(); ++itv){
            if((*itv) == ver){
              mapfind[(*itdom)].push_back(e);
              break;
            }
          }
        }
      }
    }
    // now One BC is created on domain
    for(std::map<partDomain*,std::vector<MElement*> >::iterator it=mapfind.begin(); it!=mapfind.end(); ++it){
      if(it->second.size() !=0){
        allDirichlet[i].g = new groupOfElements(it->second);
        nonLinearDirichletBC *diri = new nonLinearDirichletBC(allDirichlet[i]);
        it->first->addDirichletBC(diri);
      }
    }
  }

  // Idem for Neumann BC APPLY ON FIRST FOUNDED DOM
  for(int i=0;i<allNeumann.size();i++){
    // loop on element
    // map
    std::map<partDomain*,std::vector<MElement*> > mapfind;
    std::map<partDomain*,MElement*> mapelemtype; // need for gauss quadrature rule TODO Regroup with mapfind in a structure but no time benefit
    for(groupOfElements::elementContainer::iterator it=allNeumann[i].g->begin(); it!=allNeumann[i].g->end();++it){
      MElement *e = *it;
      // Loop on all Domain to find on which domain the BC is applied
      bool flagfind = false;
      for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
        // if Dimensions are the same the element can be find with a comparison to element
        partDomain *dom = *itdom;
        // otherwise the vertex must be identified separately
        MElement *etest = *(dom->g->begin());
        mapelemtype[dom] = etest;
        if( (etest != NULL) and (etest->getDim() == e->getDim())){
          for(groupOfElements::elementContainer::iterator it2=dom->g->begin(); it2!=dom->g->end(); ++it2){
            if(*it2 == e){ // The Element is contained in the domain
              mapfind[dom].push_back(e);
              flagfind = true;
              break;
            }
          }
        }
        else{ // loop on Vertex identify the BC with first vertex of e
               // an element is included in one domain --> one vertex of Element is OK
          MVertex *ver = e->getVertex(0);
          for(groupOfElements::vertexContainer::iterator itv=dom->g->vbegin(); itv!=dom->g->vend(); ++itv){
            if((*itv) == ver){
              mapfind[(*itdom)].push_back(e);
              flagfind = true;
              break;
            }
          }
        }
      if(flagfind)
        break;
      }
    }
    // now One BC is created on domain
    for(std::map<partDomain*,std::vector<MElement*> >::iterator it=mapfind.begin(); it!=mapfind.end(); ++it){
      nonLinearNeumannBC *neu = new nonLinearNeumannBC(allNeumann[i]);
      neu->g = new groupOfElements(it->second);
      it->first->addNeumannBC(neu);
    }
  }

  // Initial
  for(int i=0;i<allinitial.size();i++){
    // loop on element
    // map
    std::map<partDomain*,std::vector<MElement*> > mapfind;
    for(groupOfElements::elementContainer::iterator it=allinitial[i].g->begin(); it!=allinitial[i].g->end();++it){
      MElement *e = *it;
      // Loop on all Domain to find on which domain the BC is applied
      for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
        // if Dimensions are the same the element can be find with a comparison to element
        partDomain *dom = *itdom;
        // otherwise the vertex must be identified separately
        MElement *etest = *(dom->g->begin());
        if(etest->getDim() == e->getDim()){
          for(groupOfElements::elementContainer::iterator it2=dom->g->begin(); it2!=dom->g->end(); ++it2){
            if(*it2 == e){ // The Element is contained in the domain
              mapfind[dom].push_back(e);
              break;
            }
          }
        }
        else{ // loop on Vertex identify the BC with first vertex of e
               // an element is included in one domain --> one vertex of Element is OK
               // On interface the BC is put on the first met domain
          MVertex *ver = e->getVertex(0);
          for(groupOfElements::vertexContainer::iterator itv=dom->g->vbegin(); itv!=dom->g->vend(); ++itv){
            if((*itv) == ver){
              mapfind[(*itdom)].push_back(e);
              break;
            }
          }
        }
      }
    }
    // now One Initial Condition is created on domain
    for(std::map<partDomain*,std::vector<MElement*> >::iterator it=mapfind.begin(); it!=mapfind.end(); ++it){
      initialCondition *initC = new initialCondition(allinitial[i]);
      initC->g = new groupOfElements(it->second);
      it->first->addInitialCondition(initC);
    }
  }
  // At this stage the BC contains in allDirichlet and allNeumann are not used so
  // they can be deleted
  allNeumann.clear();
  allDirichlet.clear();
  allinitial.clear();
};

void nonLinearMechSolver::setTimeForBC(double time){
  for (std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    (*itdom)->setTimeBC(time);
  }

  // set time for rigid contact BC
  for(std::vector<rigidContactBC>::iterator it = allContactBC.begin(); it!=allContactBC.end(); ++it){
    (*it)._f.setTime(time);
  }
}

void nonLinearMechSolver::fixNodalDofs(){
  // Fixation (prescribed displacement)
  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    for(partDomain::diriContainer::iterator it=dom->diriBegin(); it!=dom->diriEnd(); ++it){
      nonLinearDirichletBC *diri = *it;
      FixNodalDofs(diri->_space,diri->g->begin(),diri->g->end(),*pAssembler,diri->_f,*diri->_filter,dom->getFormulation());
    }
  }

  // prescribed displacement of rigid bodies (CG)
  for(std::vector<rigidContactBC>::iterator it=allContactBC.begin(); it!=allContactBC.end(); ++it){
    rigidContactBC &rcbc = *it;
    int physMaster = rcbc._tag; // for rigid BC tag == physMaster;
    // Find the associated dom to create filter dof (Store in the BC to avoid search at each iteration !!)
    FilterDof *filter;
    bool ffind = false;
    for(contactContainer::const_iterator it=_allContact.begin(); it!=_allContact.end();++it){
      contactDomain *cdom = *it;
      if(cdom->getPhys() == physMaster){
        filter = cdom->getDomain()->createFilterDof(rcbc._comp);
        ffind = true;
        break;
      }
    }
    if(ffind)
      FixNodalDofs(rcbc.space,rcbc._f,*filter,*pAssembler);
    else
      Msg::Error("Impossible to fix dof for rigid contact BC %d",rcbc._tag);
  }
}

void nonLinearMechSolver::numberDofs(linearSystem<double> *lsys){
  // we number the dofs : when a dof is numbered, it cannot be numbered
  // again with another number.
  for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom)
  {
    partDomain *dom = *itdom;
    NumberDofs(*(dom->getFunctionSpace()), dom->g->begin(), dom->g->end(),*pAssembler);
  }
  // NumberDofs of Rigid Contact Entities (Dofs for GC)
  for(contactContainer::iterator it = _allContact.begin(); it!=_allContact.end(); ++it){
    contactDomain* cdom = *it;
    if(cdom->isRigid()){
      rigidContactSpace *rcspace = dynamic_cast<rigidContactSpace*>(cdom->getSpace());
      NumberDofs(*rcspace,*pAssembler);
    }
  }
  // total number of unkowns to allocate the system
  double nunk = pAssembler->sizeOfR();
  // allocate system
  lsys->allocate(nunk);
}

void nonLinearMechSolver::addDomain(partDomain* dom){
  // initialization of GroupOfElements
  int dim = dom->getDim();
  int phys = dom->getPhysical();
  dom->g = new groupOfElements(dim,phys);
  domainVector.push_back(dom);
}

void nonLinearMechSolver::addMaterialLaw(materialLaw* mlaw){
  maplaw.insert(std::pair<int,materialLaw*>(mlaw->getNum(),mlaw));
}

materialLaw* nonLinearMechSolver::getMaterialLaw(const int num){
  return (maplaw.find(num)->second);
}

void nonLinearMechSolver::thetaBC(const int numphys){
  groupOfElements *goe = new groupOfElements(1,numphys);
  this->insertTheta(numphys,goe);
}

void nonLinearMechSolver::setInitOrRestartFileName(const std::string fname){
  initOrResartfname =fname;
  _restart = true;
}

void nonLinearMechSolver::restart(unknownField *ufield){
  if(!_restart) // no file to restart
    return;
  // create a map between elem number and adress
  std::map<long int,std::pair<partDomain*,MElement*> > allelem;
  for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    for(groupOfElements::elementContainer::iterator ite = dom->g->begin(); ite!=dom->g->end(); ++ite){
      MElement *ele = *ite;
      std::pair<partDomain*,MElement*> pa(dom,ele);
      allelem.insert(std::pair<long int,std::pair<partDomain*,MElement*> >(ele->getNum(),pa));
    }
  }

  // read data in file
  FILE *f = fopen(initOrResartfname.c_str(), "r");
  char what[256];
  while(!feof(f)){
    fscanf(f, "%s", what);
    if(!strcmp(what,"$ElementNodeData")){
      int nstring;
      fscanf(f,"%d",&nstring);
      int i=0;
      char what2[256];
      while(i<nstring){
        fscanf(f,"%s",&what2);
        i++;
      }
      int nint, n;
      fscanf(f,"%d",&nint);
      i=0;
      while(i<nint){
        fscanf(f,"%d",&n);
        i++;
      }
      fscanf(f,"%d",&nint);
      i=0;
      while(i<nint){
        fscanf(f,"%d",&n);
        i++;
      }
      int elemnum,elemtype,ndofs,nvertex,ncomp;
      i = 0;
      int n2 = n; // because n is modified by fscanf(f,"%ld %d",&elemnum,&elemtype); WHY ??
      while(i<n2){
        fscanf(f,"%d %d",&elemnum,&elemtype);
        //MElement *ele = allelem[elemnum].second;
        //partDomain *dom = allelem[elem]
        std::map<long int,std::pair<partDomain*,MElement*> >::iterator it = allelem.find(elemnum);
        MElement *ele = (it->second).second;
        partDomain *dom = (it->second).first;
        FunctionSpaceBase *space = dom->getFunctionSpace();
        std::vector<Dof> R;
        space->getKeys(ele,R);
        ndofs = space->getNumKeys(ele);
        nvertex = ele->getNumVertices();
        ncomp = ndofs/nvertex;
        int j=0;
        std::vector<double> disp;
        disp.resize(ndofs);
        //double temp;
        while(j<nvertex){
          for(int k=0;k<ncomp;k++){
            fscanf(f,"%lf",&disp[j+k*nvertex]);
          }
          j++;
        }
        // set displacement in displacement field
        ufield->setInitial(R,disp);
        i++;
      }
    }
  }
  fclose(f);
  ufield->buildView(domainVector,0.0,0,"displacement",-1,false);
}

void nonLinearMechSolver::insertTheta(const int numphys, groupOfElements *goe){
  nonLinearNeumannBC neu;
  neu.g = goe;
  neu.onWhat = nonLinearBoundaryCondition::UNDEF;
  neu._tag = numphys;
  neu._f = new simpleFunctionTimeWithConstant<double>(0.);
  allTheta.push_back(neu);
}

void nonLinearMechSolver::physInitBroken(const int numphys){
  initbrokeninter.push_back(numphys);
}

void nonLinearMechSolver::createInterfaceElement(){
  // Compute and add interface element to the model
  // Loop on mesh element and store each edge (which will be distributed between InterfaceElement, Boundary InterfaceElement and VirtualInterfaceElement)
  // A tag including the vertex number is used to identified the edge common to two elements. In this case a interface element is created
  // manage creation of interface between 2 domains
  manageInterface maninter(&domainVector);
  // loop on element
  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom !=domainVector.end(); ++itdom)
  {
    partDomain *dom = *itdom;
    dom->createInterface(maninter);
/*    dgPartDomain* dom = dynamic_cast<dgPartDomain*>(*itdom);
    if(dom->IsInterfaceTerms()){
      for (groupOfElements::elementContainer::const_iterator it = dom->g->begin(); it != dom->g->end(); ++it)
      {
        MElement *e=*it;
        int nedge = e->getNumEdges();
        for(int j=0;j<nedge;j++){
          std::vector<MVertex*> vv;
          e->getEdgeVertices(j,vv);
          Iedge ie = Iedge(vv,e,dom->getPhysical());
          unsigned long int key = ie.getkey();
          const std::map<unsigned long int,Iedge>::iterator it_edge=map_edge.find(key);
          if(it_edge == map_edge.end()) // The edge doesn't exist -->inserted into the map
            map_edge.insert(std::pair<unsigned long int,Iedge>(key,ie));
          else{ // create an interface element and remove the entry in map_edge
            MInterfaceElement *interel =  new MInterfaceElement(vv, 0, 0, e, it_edge->second.getElement());
            // Two cases
            if(ie.getPhys() == it_edge->second.getPhys()) // Internal Interface
              dom->gi->insert(interel);
            else{ // Interface between 2 domains --> create a new domain if it doesn't exist
              // find the domain of itedge
              std::vector<partDomain*>::iterator itdom2;
              for(itdom2 = domainVector.begin(); itdom2!=domainVector.end(); ++itdom2)
                if((*itdom2)->getPhysical() == it_edge->second.getPhys()) break;
              manageDom->add(interel,dom,*itdom2,maplaw);
              this->addInterface(interel);
            }
            map_edge.erase(it_edge);
          }
        }
      }
    }*/
  }

  for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    int phys = dom->getPhysical();
    for(manageInterface::IelementContainer::iterator it=maninter.begin(); it!=maninter.end(); ++it){
      IElement *ie = it->second;
      if(ie->getPhys() == phys){
        dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
        MElement* interel = dom->createVirtualInterface(ie);
        dgdom->giv->insert(interel);
      }
    }
  }
}

void nonLinearMechSolver::createInterfaceElement_2()
{
  // The contructor of dgGroupCollection create automatically the GroupsOfElements
/*  _groups = dgGroupCollection(this->pModel,this->_dim,1); // TODO ?? Add parameter to model to store order
  _groups.buildGroupsOfInterfaces();
  // Affichage temporaire pour vérification
  int nn = _groups.getNbFaceGroups();
  printf("Number of group of faces : %d\n",nn);
  for(int i=0;i<nn;i++){
    printf("Group of face number %d\n",i);
    dgGroupOfFaces *inter = _groups.getFaceGroup(i);
    int nnn = inter->getNbGroupOfConnections();
    printf("Number of connection group %d \n",nnn);
    for(int j=0;j<nnn;j++){
      const dgGroupOfConnections connec = inter->getGroupOfConnections(j);
      printf("Connection's group number %d\n",j);
      int nnnn = connec.getNbClosures();
      printf("Number of closures %d\n",nnnn);
      for(int k=0;k<nnnn;k++){
        printf("Closure number %d\n",k);
        std::vector<int> vec = connec.getClosure(k);
        for(int kk=0;kk<vec.size();kk++){
          printf(" %d ",vec[kk]);
        }
        printf("\n");
      }
    }
  }*/
}

void nonLinearMechSolver::initTerms(unknownField *ufield, IPField *ipf){
  for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    dom->initializeTerms(ufield,ipf);
  }

  // contact domain
  for(contactContainer::iterator it = _allContact.begin(); it!=_allContact.end(); ++it){
    contactDomain *cdom = *it;
    if(cdom->getContactType() == contactDomain::rigidCylinder){
      rigidCylinderContact *rcc = dynamic_cast<rigidCylinderContact*>(cdom);
      rcc->initializeTerms(ufield);
    }
    else Msg::Error("Terms are not defined for contact type %d",cdom->getContactType());
  }

}

void nonLinearMechSolver::solveStaticLinar()
{
// init data
this->init();
linearSystem<double> *lsys;
if(nonLinearMechSolver::whatSolver == Taucs){
    #if defined(HAVE_TAUCS)
      lsys = new linearSystemCSRTaucs<double>;
      printf("Taucs is chosen to solve\n");
    #else
      lsys = new linearSystemGmm<double>;
      lsys = dynamic_cast<linearSystemGmm<double>*>(lsys);
      dynamic_cast<linearSystemGmm<double>*>(lsys)->setNoisy(2);
      printf("Taucs is not installed\n Gmm is chosen to solve\n");
    #endif
}
else if(nonLinearMechSolver::whatSolver == Petsc){
    #if defined(HAVE_PETSC)
      lsys = new linearSystemPETSc<double>;
      printf("PETSc is chosen to solve\n");
    #else
      lsys = new linearSystemGmm<double>;
      lsys = dynamic_cast<linearSystemGmm<double>*>(lsys);
      dynamic_cast<linearSystemGmm<double>*>(lsys)->setNoisy(2);
      printf("PETSc is not installed\n Gmm is chosen to solve\n");
    #endif
}
else{
  lsys = new linearSystemGmm<double>;
  dynamic_cast<linearSystemGmm<double>*>(lsys)->setNoisy(2);
  printf("Gmm is chosen to solve\n");
}

  if (pAssembler) delete pAssembler;
  pAssembler = new dofManager<double>(lsys);

  std::cout <<  "Dirichlet BC"<< std::endl;
  // we first do all fixations. the behavior of the dofManager is to
  // give priority to fixations : when a dof is fixed, it cannot be
  // numbered afterwards
  // Fix dof to allow the numbering of Dof by dofManager
  this->fixNodalDofs();
  this->numberDofs(lsys);

  // displacement field
  unknownField *ufield = new unknownStaticField(pAssembler,domainVector,&_allContact,3,anoded,varcd);
  this->restart(ufield); // CHANGE THIS
  // Store stress and deformation at each gauss point
  // IPState "declaration" reserve place for data
  IPField ipf(&domainVector,pAssembler, pModel, ufield, vaip); // Todo fix this
  ipf.compute1state(IPStateBase::initial);
  ipf.copy(IPStateBase::initial,IPStateBase::current); // initialization of Bvector and LocalBasis
  this->initTerms(ufield,&ipf);

  // Now we start the assembly process
  // First build the force vector
  std::cout <<  "Neumann BC"<< std::endl;
  this->computeExternalForces(&ipf,ufield);
  this->computeStiffMatrix(ufield);
  printf("-- done assembling!\n");
  lsys->systemSolve();
  printf("-- done solving!\n");

  // compute stress after solve
  ufield->update();
  ipf.compute1state(IPStateBase::current);
  // save solution (for visualisation)
  ipf.buildView(domainVector,0.,1,"VonMises",-1,false);
  ufield->buildView(domainVector,0.,1,"displacement",-1,false);
  ufield->archiving(1.);
  ipf.archive(1.);
  delete ufield;
}

void nonLinearMechSolver::computeExternalForces(IPField *ipf, const unknownField *ufield){
  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end();++itdom){
    partDomain *dom = *itdom;
    for(partDomain::neuContainer::iterator it=dom->neuBegin(); it!=dom->neuEnd();++it){
      nonLinearNeumannBC *neu = *it;
      Assemble(neu->_term,*(neu->_space),neu->g->begin(),neu->g->end(),*(neu->integ),ufield,*pAssembler);
    }
  }
}

void nonLinearMechSolver::snlData(const int ns, const double et, const double reltol){
  if(whatScheme==StaticNonLinear){
    numstep=ns;endtime=et;_tol=reltol;
  }
  else{
    Msg::Error("Impossible to set data for Static Non Linear scheme because another is chosen to solve the problem");
  }
}

void nonLinearMechSolver::explicitData(const double ftime, const double gams, const double beta, const double gamma, const double alpham){
  endtime = ftime;
  _beta=beta;
  _gamma=gamma;
  _alpham = alpham;
  // depends on numerical damping
  double omegas;
  _rhoinfty = (alpham+1.)/(2.-alpham);
  omegas = sqrt((12.*(1.+_rhoinfty)*(1.+_rhoinfty)*(1.+_rhoinfty)*(2.-_rhoinfty))/(10.+15.*_rhoinfty-_rhoinfty*_rhoinfty+_rhoinfty*_rhoinfty*_rhoinfty-_rhoinfty*_rhoinfty*_rhoinfty*_rhoinfty));
    _gammas = gams*omegas;
}

void nonLinearMechSolver::explicitSpectralRadius(const double ftime,const double gams, const double rho){
  endtime = ftime;
  _rhoinfty=rho;
  _beta = (5.-3.*_rhoinfty)/((1.+_rhoinfty)*(1.+_rhoinfty)*(2.-_rhoinfty));
  _alpham = (2.*_rhoinfty-1.)/(1.+_rhoinfty);
  _gamma = 1.5-_alpham;
  double omegas = sqrt((12.*(1.+_rhoinfty)*(1.+_rhoinfty)*(1.+_rhoinfty)*(2.-_rhoinfty))/(10.+15.*_rhoinfty-_rhoinfty*_rhoinfty+_rhoinfty*_rhoinfty*_rhoinfty-_rhoinfty*_rhoinfty*_rhoinfty*_rhoinfty));
    _gammas = gams*omegas;
}

void nonLinearMechSolver::explicitTimeStepEvaluation(const int nst){
  numstep = nst;
}

void nonLinearMechSolver::solve(){
  switch(whatScheme){
    case StaticLinear :
      this->solveStaticLinar();
      break;
    case StaticNonLinear :
      this->solveSNL();
      break;
    case Explicit:
      this->solveExplicit();
  }
}

void nonLinearMechSolver::displacementBC(std::string onwhat, const int numphys, const int comp, const double value){
  nonLinearDirichletBC diri;
  const std::string node("Node");
  const std::string edge("Edge");
  const std::string face("Face");
  if(onwhat==node){
    diri.g = new groupOfElements (0, numphys);
    diri.onWhat=nonLinearBoundaryCondition::ON_VERTEX;
  }
  else if(onwhat==edge){
    diri.g = new groupOfElements (1, numphys);
    diri.onWhat=nonLinearBoundaryCondition::ON_EDGE;
  }
  else if(onwhat==face){
    diri.g = new groupOfElements (2, numphys);
    diri.onWhat=nonLinearBoundaryCondition::ON_FACE;
  }
  else Msg::Error("Impossible to prescribe a displacement on a %s\n",onwhat.c_str());
  diri._f= simpleFunctionTime<double>(value);
  diri._comp=comp;
  diri._tag=numphys;
  allDirichlet.push_back(diri);
}

void nonLinearMechSolver::displacementRigidContactBC(const int numphys, const int comp_, const double value){
  rigidContactBC diri(numphys);
  diri.onWhat = nonLinearBoundaryCondition::RIGIDCONTACT;
  diri._comp = comp_;
  diri._f = simpleFunctionTime<double>(value);
  allContactBC.push_back(diri);
}

void nonLinearMechSolver::initialBC(std::string onwhat, std::string whichC, const int numphys,
                                          const int comp, const double value){

  const std::string node("Node");
  const std::string edge("Edge");
  const std::string face("Face");
  const std::string position("Position");
  const std::string velocity("Velocity");
  const std::string acceleration("Acceleration");

  nonLinearBoundaryCondition::location ow;
  groupOfElements *gr;
  if(onwhat == node){
    ow = nonLinearBoundaryCondition::ON_VERTEX;
    gr = new groupOfElements(0,numphys);
  }
  else if(onwhat == edge){
    ow = nonLinearBoundaryCondition::ON_EDGE;
    gr = new groupOfElements(1,numphys);
  }
  else if(onwhat == face){
    ow = nonLinearBoundaryCondition::ON_FACE;
    gr = new groupOfElements(2,numphys);
  }
  else{
    ow = nonLinearBoundaryCondition::UNDEF;
    gr = new groupOfElements(2,numphys);
  }

  initialCondition::whichCondition wc;
  if(whichC == position)
    wc = initialCondition::position;
  else if(whichC == velocity)
    wc = initialCondition::velocity;
  else if(whichC == acceleration)
    wc = initialCondition::acceleration;
  else{
    Msg::Warning("Impossible to prescribed an initial condition %d",numphys);
    //return;
  }
  initialCondition initc(value,comp,wc);
  initc.onWhat = ow;
  initc.g = gr;
  initc._tag = numphys;
  allinitial.push_back(initc);
}

void nonLinearMechSolver::independentDisplacementBC(std::string onwhat, const int numphys, const int comp, const double value){
  nonLinearDirichletBC diri;
  const std::string node("Node");
  const std::string edge("Edge");
  const std::string face("Face");
  if(onwhat==node){
    diri.g = new groupOfElements (0, numphys);
    diri.onWhat=nonLinearBoundaryCondition::ON_VERTEX;
  }
  else if(onwhat==edge){
    diri.g = new groupOfElements (1, numphys);
    diri.onWhat=nonLinearBoundaryCondition::ON_EDGE;
  }
  else if(onwhat==face){
    diri.g = new groupOfElements (2, numphys);
    diri.onWhat=nonLinearBoundaryCondition::ON_FACE;
  }
  else Msg::Error("Impossible to prescribe a displacement on a %s\n",onwhat.c_str());
  diri._f= simpleFunctionTime<double>(value,false);
  diri._comp=comp;
  diri._tag=numphys;
  allDirichlet.push_back(diri);
}

void nonLinearMechSolver::forceBC(std::string onwhat, const int numphys, const int comp, const double val){
  nonLinearNeumannBC neu;
  const std::string node("Node");
  const std::string edge("Edge");
  const std::string face("Face");
  const std::string volume("Volume");
  if(onwhat==node){
    neu.g = new groupOfElements (0, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_VERTEX;
  }
  else if(onwhat==edge){
    neu.g = new groupOfElements (1, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_EDGE;
  }
  else if(onwhat==face){
    neu.g = new groupOfElements (2, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_FACE;
  }
  else if(onwhat==volume){
    neu.g = new groupOfElements (3, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_VOLUME;
  }
  else  Msg::Error("Impossible to prescribe a force on a %s\n",onwhat.c_str());
  neu._f= new simpleFunctionTimeWithConstant<double>(val);
  neu._tag=numphys;
  neu._comp=comp;
  allNeumann.push_back(neu);
}

void nonLinearMechSolver::independentForceBC(std::string onwhat, const int numphys, const int comp, const double val){
  nonLinearNeumannBC neu;
  const std::string node("Node");
  const std::string edge("Edge");
  const std::string face("Face");
  const std::string volume("Volume");
  if(onwhat==node){
    neu.g = new groupOfElements (0, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_VERTEX;
  }
  else if(onwhat==edge){
    neu.g = new groupOfElements (1, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_EDGE;
  }
  else if(onwhat==face){
    neu.g = new groupOfElements (2, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_FACE;
  }
  else if(onwhat==volume){
    neu.g = new groupOfElements (3, numphys);
    neu.onWhat=nonLinearBoundaryCondition::ON_VOLUME;
  }
  else  Msg::Error("Impossible to prescribe a force on a %s\n",onwhat.c_str());
  neu._f= new simpleFunctionTimeWithConstant<double>(val,false);
  neu._tag=numphys;
  neu._comp = comp;
  allNeumann.push_back(neu);
}

void nonLinearMechSolver::pressureOnPhysicalGroupBC(const int numphys, const double press, const double p0){
  nonLinearNeumannBC neu;
  neu.g = new groupOfElements(2,numphys); // Always group of face ??
  neu.onWhat = nonLinearBoundaryCondition::PRESSURE;
  neu._f = new simpleFunctionTimeWithConstant<double>(press,true,1.,p0); // Use a SVector3 because it was defined like this in
  neu._tag=numphys;
  allNeumann.push_back(neu);
}

void nonLinearMechSolver::blastPressureBC(const int numphys,const double p0,const double p1, const double plexp,
                                       const double t0, const double t1){
  powerDecreasingFunctionTime *pdl = new powerDecreasingFunctionTime(p0,p1,plexp,t0,t1,this->endtime);
  nonLinearNeumannBC neu(numphys,5,pdl);
  allNeumann.push_back(neu);
}

void nonLinearMechSolver::archivingForceOnPhysicalGroup(const std::string onwhat, const int numphys, const int comp){
  // get the node of the edge
  std::string node("Node");
  std::string edge("Edge");
  std::string face("Face");
  std::string volu("Volume");
  int dim=0;
  if(onwhat == node )
    dim = 0;
  else if(onwhat == edge)
    dim = 1;
  else if(onwhat == face)
    dim = 2;
  else if(onwhat == volu)
    dim = 3;

  vaf.push_back(archiveForce(numphys,dim,comp));

  // remove old file (linux only ??)
  std::ostringstream oss;
  oss << numphys;
  std::string s = oss.str();
  oss.str("");
  oss << comp;
  std::string s2 = oss.str();
  std::string rfname = "rm force"+s+"comp"+s2+".csv";
  system(rfname.c_str());
}

void nonLinearMechSolver::initArchiveForce(){
  for(std::vector<archiveForce>::iterator itf=vaf.begin(); itf!=vaf.end(); ++itf){
    archiveForce &af = *itf;
    std::vector<MVertex*> vv;
    pModel->getMeshVerticesForPhysicalGroup(af.dim,af.numphys,vv);
    std::vector<Dof> vdof;// all dof include in the edge

    // shell element
    // loop on domain (to find the domain where the force is applied)
    for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
      partDomain *dom = *itdom;
      FunctionSpaceBase *sp = dom->getFunctionSpace();
      std::vector<Dof> R;
      FilterDof* filter = dom->createFilterDof(af.comp);
      if(!(dom->getFormulation())){  // Cg/Dg
        for(groupOfElements::vertexContainer::iterator itv=dom->g->vbegin(); itv!=dom->g->vend(); ++itv){
          MVertex *ver = *itv;
          for(std::vector<MVertex*>::iterator it=vv.begin(); it!=vv.end(); ++it){
            MVertex *vver = *it;
            if(ver == vver){
              MPoint ele = MPoint(ver,-1); // We don't care about element number it's just to have the vertex keys
              // build the dof
              sp->getKeys(&ele,R);
              for(int j=0;j<R.size(); j++)
                if(filter->operator()(R[j]))
                  vdof.push_back(R[j]);
              R.clear();
              break;
            }
          }
        }
      }
      else{ // full Dg
        for(groupOfElements::elementContainer::iterator ite = dom->g->begin(); ite!=dom->g->end(); ++ite){
          MElement *ele = *ite;
          int nbvertex = ele->getNumVertices();
          sp->getKeys(ele,R);
          for(std::vector<MVertex*>::iterator it=vv.begin(); it!=vv.end(); ++it){
            for(int j=0;j<nbvertex; j++){
              if(ele->getVertex(j) == *it){
                vdof.push_back(R[j+nbvertex*af.comp]);
                break;
              }
            }
          }
          R.clear();
        }
      }
    }
    // keys = 10*numphys + comp otherwise no way to archive different components
    int key = 10*af.numphys+af.comp;
    aef[key] = vdof;
    aefvalue[key] = 0.;
  }
  // force on prescribed displacement (needed to compute external work)
  for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!= domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    std::vector<Dof> R;
    bool flag;
    for(partDomain::diriContainer::iterator itd = dom->diriBegin(); itd!=dom->diriEnd(); ++itd){
      nonLinearDirichletBC *diri = *itd;
      if(diri->_f(0.,0.,0.) != 0.){ // f = simplke Function independant of position otherwise wext = 0
        FunctionSpaceBase *sp = diri->_space;
        for(groupOfElements::elementContainer::iterator it = diri->g->begin(); it!=diri->g->end(); ++it){
          MElement *ele = *it;
          sp->getKeys(ele,R);
          for(int i=0; i<R.size(); i++){
            flag = true;
            for(std::vector<fextPrescribedDisp>::iterator it2 = _allaef.begin(); it2 != _allaef.end(); ++it2){
              if(R[i] == (*it2).D){
                flag = false;
                break;
              }
            }
            if(flag)
            {
              fextPrescribedDisp fpd = fextPrescribedDisp(R[i]);
              _allaef.push_back(fpd);
            }
          }
          R.clear();
        }
      }
    }
  }
}

void nonLinearMechSolver::archivingNodeDisplacement(const int numphys, const int comp){
  this->archivingNode(numphys,comp,initialCondition::position);
}

void nonLinearMechSolver::archivingNodeVelocity(const int numphys, const int comp){
  this->archivingNode(numphys,comp,initialCondition::velocity);
}

void nonLinearMechSolver::archivingNodeAcceleration(const int numphys, const int comp){
  this->archivingNode(numphys,comp,initialCondition::acceleration);
}

void nonLinearMechSolver::archivingNode(const int numphys, const int comp, initialCondition::whichCondition wc){
  // no distinction between cG/dG and full Dg formulation. class Displacement Field manage it
  std::vector<MVertex*> vv;
  pModel->getMeshVerticesForPhysicalGroup(0,numphys,vv);

  if(vv.size() !=0){
    std::pair< Dof,initialCondition::whichCondition > pai(Dof(vv[0]->getNum(),Dof3IntType::createTypeWithThreeInts(comp,_tag)),wc);
    anoded.push_back(pai);
    // remove old file (linux only ??)
    std::ostringstream oss;
    oss << vv[0]->getNum(); // Change this
    std::string s = oss.str();
    oss.str("");
    oss << comp;
    std::string s2 = oss.str();
    std::string rfname;
    switch(wc){
     case initialCondition::position:
      rfname= "rm NodalDisplacement"+s+"comp"+s2+".csv";
      break;
     case initialCondition::velocity:
      rfname= "rm NodalVelocity"+s+"comp"+s2+".csv";
      break;
     case initialCondition::acceleration:
      rfname= "rm NodalAcceleration"+s+"comp"+s2+".csv";
      break;
    }
    system(rfname.c_str());
  }
  else{
    Msg::Warning("No physical group %d So it is impossible to archive nodal displacement",numphys);
  }
}

void nonLinearMechSolver::archivingRigidContact(const int numphys, const int comp, const int wc){
 initialCondition::whichCondition whc;
 switch(wc){
  case 0:
   whc = initialCondition::position;
   break;
  case 1:
   whc = initialCondition::velocity;
   break;
  case 2:
   whc = initialCondition::acceleration;
   break;
  default:
   whc = initialCondition::position;
 }
  // find domain
  partDomain *domf=NULL;
  for(contactContainer::const_iterator it = _allContact.begin(); it!=_allContact.end(); ++it){
    contactDomain *cdom = *it;
    if(cdom->getPhys() == numphys){
      int physDom = cdom->getPhysSlave();
      for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom!=domainVector.end(); ++itdom){
        partDomain *dom = *itdom;
        if(dom->getPhysical() == physDom){
          domf = dom;
          break;
        }
      }
      break;
    }
  }
  if(domf != NULL){
    archiveRigidContactDisp ar(numphys,comp,whc,domf);
    varcd.push_back(ar);

    // remove of csv file Linux only
    std::ostringstream oss;
    oss << numphys; // Change this
    std::string s = oss.str();
    oss.str("");
    oss << comp;
    std::string s2 = oss.str();
    std::string rfname;
    switch(whc){
     case initialCondition::position:
      rfname= "rm NodalDisplacement"+s+"comp"+s2+".csv";
      break;
     case initialCondition::velocity:
      rfname= "rm NodalVelocity"+s+"comp"+s2+".csv";
      break;
     case initialCondition::acceleration:
      rfname= "rm NodalAcceleration"+s+"comp"+s2+".csv";
      break;
    }
    system(rfname.c_str());
  }
  else{
    Msg::Error("Impossible to archive displacement for contact number %d",numphys);
  }
}

void nonLinearMechSolver::archivingNodeIP(const int numphys, const int ipval){
  vaip.push_back(archiveIPVariable(numphys,ipval));
}

void nonLinearMechSolver::contactInteraction(contactDomain *cdom){
  _allContact.insert(cdom);
}


//
// C++ Interface: terms explicit
//
// Description: Files with definition of function : nonLinearMechSolver::solveExplicit()
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

double distanceMin(const double x1, const double x2, const double x3,
                    const double y1, const double y2, const double y3,
                    const double z1, const double z2, const double z3){
  double dist1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
  double dist2 = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)+(z2-z3)*(z2-z3));
  if(dist1 > dist2)
    dist1 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1));
  else
    dist2 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1));
  if(dist1 > dist2)
    return dist2;
  else
    return dist1;
}
// PUT THIS IN MELEMENT ??
double triangleCharacteristicSize(MElement *ele, unknownField *ufield, std::vector<Dof> &R){
  std::vector<double> disp;
  ufield->get(R,disp);
  double x1 = ele->getVertex(0)->x() + disp[0];
  double x2 = ele->getVertex(1)->x() + disp[1];
  double x3 = ele->getVertex(2)->x() + disp[2];
  double y1 = ele->getVertex(0)->y() + disp[3];
  double y2 = ele->getVertex(1)->y() + disp[4];
  double y3 = ele->getVertex(2)->y() + disp[5];
  double z1 = ele->getVertex(0)->z() + disp[6];
  double z2 = ele->getVertex(1)->z() + disp[7];
  double z3 = ele->getVertex(2)->z() + disp[8];
  return distanceMin(x1,x2,x3,y1,y2,y3,z1,z2,z3);
/*  double dist1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
  double dist2 = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)+(z2-z3)*(z2-z3));
  if(dist1 > dist2)
    dist1 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1));
  else
    dist2 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1));
  if(dist1 > dist2)
    return dist2;
  else
    return dist1;*/
}

// For quadrangle make the search for 2 triangle
double quadrangleCharacteriticSize(MElement *ele,unknownField *ufield, std::vector<Dof> &R){
  double hmin1,hmin2;
  // first triangle node 1,2,3
  std::vector<Dof> R2;

  R2.push_back(R[0]); R2.push_back(R[1]); R2.push_back(R[2]);
  R2.push_back(R[4]); R2.push_back(R[5]); R2.push_back(R[6]);
  R2.push_back(R[8]); R2.push_back(R[9]); R2.push_back(R[10]);
  MTriangle etri = MTriangle(ele->getVertex(0),ele->getVertex(1),ele->getVertex(2),-1,0);
  hmin1 = triangleCharacteristicSize(&etri,ufield,R2);

  R2[0] = R[0]; R2[1] = R[2]; R2[2] = R[3];
  R2[3] = R[4]; R2[4] = R[6]; R2[5] = R[7];
  R2[6] = R[8]; R2[7] = R[10]; R2[8] = R[11];
  etri = MTriangle(ele->getVertex(0),ele->getVertex(2),ele->getVertex(3),-1,0);
  hmin2 = triangleCharacteristicSize(&etri,ufield,R2);

  if(hmin1 > hmin2) return hmin2;
  else return hmin1;
}

double quadrangle2orderCharacteristicSize(MElement *ele,unknownField *ufield, std::vector<Dof> &R){
  double hmin1, hmin2;
  // make 4 simple quadrangles
  std::vector<Dof> R2;

  R2.push_back(R[0]); R2.push_back(R[4]); R2.push_back(R[8]); R2.push_back(R[7]);
  R2.push_back(R[9]); R2.push_back(R[13]); R2.push_back(R[17]); R2.push_back(R[16]);
  R2.push_back(R[18]);R2.push_back(R[22]); R2.push_back(R[26]); R2.push_back(R[25]);
  MQuadrangle equad = MQuadrangle(ele->getVertex(0),ele->getVertex(4),ele->getVertex(8),ele->getVertex(7),-1,0);
  hmin1 = quadrangleCharacteriticSize(&equad,ufield,R2);

  R2[0] = R[4];  R2[1] = R[1];  R2[2] =  R[5];  R2[3] = R[8];
  R2[4] = R[13]; R2[5] = R[10]; R2[6] =  R[14]; R2[7] = R[17];
  R2[8] = R[22]; R2[9] = R[19]; R2[10] = R[23]; R2[11] = R[26];
  equad = MQuadrangle(ele->getVertex(4),ele->getVertex(1),ele->getVertex(5),ele->getVertex(8),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  R2[0] = R[8];  R2[1] = R[5];  R2[2] =  R[2];  R2[3] = R[6];
  R2[4] = R[17]; R2[5] = R[14]; R2[6] =  R[11]; R2[7] = R[15];
  R2[8] = R[26]; R2[9] = R[23]; R2[10] = R[20]; R2[11] = R[24];
  equad = MQuadrangle(ele->getVertex(8),ele->getVertex(5),ele->getVertex(1),ele->getVertex(6),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  R2[0] = R[8];  R2[1] = R[6];  R2[2] =  R[3];  R2[3] = R[7];
  R2[4] = R[17]; R2[5] = R[15]; R2[6] =  R[12]; R2[7] = R[16];
  R2[8] = R[26]; R2[9] = R[24]; R2[10] = R[21]; R2[11] = R[25];
  equad = MQuadrangle(ele->getVertex(8),ele->getVertex(6),ele->getVertex(3),ele->getVertex(7),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  return hmin1;
}

double quadrangle3orderCharacteristicSize(MElement *ele,unknownField *ufield, std::vector<Dof> &R){
  // 5 quadrangles of 1st order + One second order quadrangle
  double hmin1,hmin2;
  std::vector<Dof> R2;

  R2.push_back(R[0]);  R2.push_back(R[4]); R2.push_back(R[12]); R2.push_back(R[11]);
  R2.push_back(R[16]); R2.push_back(R[20]); R2.push_back(R[28]); R2.push_back(R[27]);
  R2.push_back(R[32]); R2.push_back(R[36]); R2.push_back(R[44]); R2.push_back(R[43]);
  MQuadrangle equad = MQuadrangle(ele->getVertex(0),ele->getVertex(4), ele->getVertex(12), ele->getVertex(11),-1,0);
  hmin1 = quadrangleCharacteriticSize(&equad,ufield,R2);

  R2[0] = R[4];  R2[1] = R[5];  R2[2] =  R[3];  R2[13] = R[12];
  R2[4] = R[20]; R2[5] = R[21]; R2[6] =  R[19]; R2[7] = R[28];
  R2[8] = R[36]; R2[9] = R[37]; R2[10] = R[35]; R2[11] = R[44];
  equad = MQuadrangle(ele->getVertex(4),ele->getVertex(5),ele->getVertex(13),ele->getVertex(12),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  R2[0] = R[5];  R2[1] = R[1];  R2[2] =  R[6];  R2[13] = R[13];
  R2[4] = R[21]; R2[5] = R[17]; R2[6] =  R[22]; R2[7] =  R[29];
  R2[8] = R[37]; R2[9] = R[33]; R2[10] = R[38]; R2[11] = R[45];
  equad = MQuadrangle(ele->getVertex(5),ele->getVertex(1),ele->getVertex(6),ele->getVertex(13),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  R2[0] = R[13];  R2[1] = R[6];  R2[2] =  R[7];  R2[13] = R[14];
  R2[4] = R[29]; R2[5] = R[22]; R2[6] =  R[23]; R2[7] = R[30];
  R2[8] = R[45]; R2[9] = R[38]; R2[10] = R[39]; R2[11] = R[46];
  equad = MQuadrangle(ele->getVertex(13),ele->getVertex(6),ele->getVertex(7),ele->getVertex(14),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  R2[0] = R[14];  R2[1] = R[7];  R2[2] =  R[2];  R2[13] = R[8];
  R2[4] = R[30]; R2[5] = R[23]; R2[6] =  R[18]; R2[7] = R[24];
  R2[8] = R[46]; R2[9] = R[39]; R2[10] = R[34]; R2[11] = R[40];
  equad = MQuadrangle(ele->getVertex(14),ele->getVertex(7),ele->getVertex(2),ele->getVertex(8),-1,0);
  hmin2 = quadrangleCharacteriticSize(&equad,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;

  // second order quadrangle
  R2.clear();

  R2.push_back(R[11]); R2.push_back(R[13]); R2.push_back(R[8]); R2.push_back(R[3]); R2.push_back(R[12]); R2.push_back(R[14]);    R2.push_back(R[9]);   R2.push_back(R[10]); R2.push_back(R[15]);
  R2.push_back(R[27]); R2.push_back(R[29]); R2.push_back(R[24]); R2.push_back(R[19]); R2.push_back(R[28]); R2.push_back(R[30]);  R2.push_back(R[25]);  R2.push_back(R[26]); R2.push_back(R[31]);
  R2.push_back(R[43]); R2.push_back(R[45]); R2.push_back(R[40]); R2.push_back(R[35]); R2.push_back(R[44]); R2.push_back(R[46]);  R2.push_back(R[41]);  R2.push_back(R[42]); R2.push_back(R[47]);

  MQuadrangle9 equad2 = MQuadrangle9(ele->getVertex(11),ele->getVertex(13),ele->getVertex(8),ele->getVertex(3),
                                     ele->getVertex(12),ele->getVertex(14),ele->getVertex(9),ele->getVertex(10),
                                     ele->getVertex(15),-1,0);
  hmin2 = quadrangle2orderCharacteristicSize(&equad2,ufield,R2);
  if(hmin1 > hmin2) hmin1 = hmin2;
  return hmin1;

}

// dont use previous function change this ?
double triangular3orderCharacteristicSize(MElement *ele,unknownField *ufield,std::vector<Dof> &R){
  std::vector<double> disp;
  ufield->get(R,disp);
  double x0 = ele->getVertex(0)->x() + disp[0];
  double x1 = ele->getVertex(1)->x() + disp[1];
  double x2 = ele->getVertex(2)->x() + disp[2];
  double x3 = ele->getVertex(3)->x() + disp[3];
  double x4 = ele->getVertex(4)->x() + disp[4];
  double x5 = ele->getVertex(5)->x() + disp[5];
  double x6 = ele->getVertex(6)->x() + disp[6];
  double x7 = ele->getVertex(7)->x() + disp[7];
  double x8 = ele->getVertex(8)->x() + disp[8];
  double x9 = ele->getVertex(9)->x() + disp[9];

  double y0 = ele->getVertex(0)->y() + disp[10];
  double y1 = ele->getVertex(1)->y() + disp[11];
  double y2 = ele->getVertex(2)->y() + disp[12];
  double y3 = ele->getVertex(3)->y() + disp[13];
  double y4 = ele->getVertex(4)->y() + disp[14];
  double y5 = ele->getVertex(5)->y() + disp[15];
  double y6 = ele->getVertex(6)->y() + disp[16];
  double y7 = ele->getVertex(7)->y() + disp[17];
  double y8 = ele->getVertex(8)->y() + disp[18];
  double y9 = ele->getVertex(9)->y() + disp[19];

  double z0 = ele->getVertex(0)->z() + disp[20];
  double z1 = ele->getVertex(1)->z() + disp[21];
  double z2 = ele->getVertex(2)->z() + disp[22];
  double z3 = ele->getVertex(3)->z() + disp[23];
  double z4 = ele->getVertex(4)->z() + disp[24];
  double z5 = ele->getVertex(5)->z() + disp[25];
  double z6 = ele->getVertex(6)->z() + disp[26];
  double z7 = ele->getVertex(7)->z() + disp[27];
  double z8 = ele->getVertex(8)->z() + disp[28];
  double z9 = ele->getVertex(9)->z() + disp[29];
  double dist, distmin;
  distmin = distanceMin(x0,x3,x8,y0,y3,y8,z0,z3,z8);
  dist = distanceMin(x3,x9,x8,y3,y9,y8,z3,z9,z8);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x9,x3,x4,y9,y3,y4,z9,z3,z4);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x4,x5,x9,y4,y5,y9,z4,z5,z9);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x4,x5,x1,y4,y5,y1,z4,z5,z1);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x5,x6,x9,y5,y6,y9,z5,z6,z9);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x6,x9,x7,y6,y9,y7,z6,z9,z7);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x7,x8,x9,y7,y8,y9,z7,z8,z9);
  if (dist < distmin) distmin = dist;
  dist = distanceMin(x7,x6,x2,y7,y6,y2,z7,z6,z2);
  if (dist < distmin) distmin = dist;
  return distmin;
}

double nonLinearMechSolver::criticalExplicitTimeStep(unknownField *ufield){
  // evaluate the critical time step carachteristic length = hs
  // criteria = distance min between 2 nodes
  double hs;
  double dtmin=1.e100; // Initialization to infinity
  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    double hsmin= 1.e100; // Initialization to infinity
    FunctionSpaceBase *spdom = dom->getFunctionSpace();
    std::vector<Dof> R;
    // As time step is compute on element the dom is not an "interface domain"
    // so getMaterialLawMinus() == getMaterialLawPlus()
    materialLaw *mlt = dom->getMaterialLaw();
    double celerity = mlt->soundSpeed();
    double scaleTimeStep = dom->scaleTimeStep();
    for(groupOfElements::elementContainer::iterator it=dom->g->begin(); it!=dom->g->end(); ++it){
      MElement *e = *it;
      // nodal displacement
      spdom->getKeys(e,R);

      // Unfortunally, computation of characteristic length depends on the element type
      // Element are cut in several triangles of degree one
      // ADD THIS FUNCTIONS directly in gmsh (method of MELEMENT)
      switch(e->getTypeForMSH()){
       case MSH_TRI_3:
        hs = triangleCharacteristicSize(e,ufield,R);
        break;
       case MSH_QUA_4:
        hs = quadrangleCharacteriticSize(e,ufield,R);
        break;
       case MSH_QUA_9 :
        hs = quadrangle2orderCharacteristicSize(e,ufield,R);
        break;
       case MSH_QUA_16:
        hs = quadrangle3orderCharacteristicSize(e,ufield,R);
        break;
       case MSH_TRI_10:
        hs = triangular3orderCharacteristicSize(e,ufield,R);
        break;
       default :
        // default criteria area/(degree*perimter);
        Msg::Warning("Use a invariant time step predictor because rule for time step computation is unknow for this element type");
        hs = MInterfaceElement::characSize(e);
        hs/= e->getPolynomialOrder();
      }

      if(hs<hsmin) hsmin = hs;
      R.clear();
    }
    double dt = 0.5*scaleTimeStep*hsmin/celerity;  // WHY 0.5 ??
    if(dt < dtmin ) dtmin = dt;
  }

  // Delta t of contact
/*  explicitHCDofManager<double>* dynass = dynamic_cast<explicitHCDofManager<double>*>(pAssembler);
  // filter because one component is needed (same mass in all direction)
  DgC0ShellFilterDofComponent filDof(0);
  for(nonLinearMechSolver::contactContainer::iterator itc = _allContact.begin(); itc!=_allContact.end(); ++itc){
    contactDomain *cdom = *itc;
    DgC0rigidContactSpace *csp = dynamic_cast<DgC0rigidContactSpace*>(spaceManager->get(cdom));
    double penalty = cdom->getPenalty();
    for(groupOfElements::elementContainer::iterator it = cdom->gSlave->begin(); it!=cdom->gSlave->end(); ++it){
      MElement *ele = *it;
      // get mass
//      int nbdofs = csp->getNumKeys(ele);
      int nbvertex = ele->getNumVertices();
//      int nbdofsGC = csp->getNumKeysOfGravityCenter();
//      int nbcomp = (nbdofs-nbdofsGC)/nbvertex;
      std::vector<Dof> R;
      std::vector<double> vmass;
      csp->getKeys(ele,R);
      std::vector<Dof> Rfilter;
      filDof.filter(R,Rfilter);
      dynass->getVertexMass(Rfilter,vmass);
      double Mmaster = vmass[nbvertex];
      for(int i=0; i<nbvertex; i++){
        double dt = 10000.*sqrt(0.5*Mmaster*vmass[i]/penalty/(Mmaster+vmass[i]));
        if(dt < dtmin ){
          dtmin = dt;
          Msg::Info("Dtc is fixed by contact");
        }
      }
    }
  }*/
  return dtmin;
}

void nonLinearMechSolver::setInitialCondition(){
  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom){
    partDomain *dom = *itdom;
    for(partDomain::initContainer::iterator it=dom->initCBegin(); it!=dom->initCEnd(); ++it){
      initialCondition *initC = *it;
      SetInitialDofs(initC->_space,initC->g->begin(),initC->g->end(),initC->_value,initC->_wc,*pAssembler,*initC->_filter,dom->getFormulation());
    }
  }
  // Eventually read file with initial position
/*  if(initOrResartfname != ""){
    // loop on all elements on all domain
    FunctionSpaceBase *sp; // to create the dofs
    std::vector<Dof> R;
    std::vector<double> val;
    for(std::vector<partDomain*>::iterator itdom = domainVector.begin(); itdom != domainVector.end(); ++itdom){
      partDomain *dom = *itdom;
      sp = spaceManager->get(dom);
      for(groupOfElements::elementContainer::iterator it = dom->g->begin(); it != dom->g->end(); ++it){
        MElement *ele = *it;
        // create dof of element
        sp->getKeys(ele,R);

        // clear
        R.clear();
      }

    }

  }*/
}

void nonLinearMechSolver::solveExplicit(){
#if defined(HAVE_PETSC)
  Msg::Info("Explicit Data: endtime = %lf beta=%f gamma=%f alpha_m=%f",this->getEndTime(), this->_beta, this->_gamma, this->_alpham);

  //init
  this->init();

  // Creation of system
  if(nonLinearMechSolver::whatSolver!= Petsc)
    Msg::Warning("Explicit scheme uses Petsc only!");

  explicitHulbertChung<double> *esys = new explicitHulbertChung<double>(_alpham,_beta,_gamma);

  // dof Manager
  if(pAssembler) delete pAssembler;
  pAssembler = new explicitHCDofManager<double>(esys);

  // time initialization
  double curtime = 0.;
  // Fix Dof
  this->setTimeForBC(curtime); // otherwise BC which depend on time are put to t=1; and initial value are wrong
  this->fixNodalDofs();
  this->numberDofs(esys);

  // System is allocated by numberDofs
  // so now initial condition can be given to system
  this->setInitialCondition();

  // definition of ufield and ipfield
  unknownField *ufield = new unknownDynamicField(pAssembler,domainVector,&_allContact,3,anoded,varcd); // 3 components by nodes User choice ??
  unknownDynamicField *dynufield = dynamic_cast<unknownDynamicField*>(ufield);
  this->restart(ufield); // CHANGE THIS
  IPField ipf(&domainVector,pAssembler,pModel,ufield,vaip); // Field for GaussPoint
  energeticField efield(esys,&ipf,ufield,pAssembler,domainVector,_allaef);
  ipf.compute1state(IPStateBase::initial);
  ipf.initialBroken(pModel, initbrokeninter);
  ipf.copy(IPStateBase::initial,IPStateBase::current);
  this->initTerms(ufield,&ipf);

  // compute mass Matrix (outside loop)
  for(std::vector<partDomain*>::iterator it = domainVector.begin(); it!=domainVector.end(); ++it){
    partDomain *dom = *it;
    AssembleMass(dom->getBilinearMassTerm(),*(dom->getFunctionSpace()),dom->g->begin(),dom->g->end(),
                 *(dom->getBulkGaussIntegrationRule()),*pAssembler);
  }

  for(nonLinearMechSolver::contactContainer::iterator itc = _allContact.begin(); itc!= _allContact.end(); ++itc){
    contactDomain *cdom = *itc;
    if(cdom->isRigid()){
      rigidContactSpace *rcsp = dynamic_cast<rigidContactSpace*>(cdom->getSpace());
      AssembleMass(cdom->getMassTerm(),rcsp,pAssembler);
    }
  }

  // masse OK
//  double mas = esys->getSystemMass();

  // initial forces
  this->computeRightHandSide(esys,pAssembler,ufield,&ipf);
  esys->nextStep();
  long int step=0;
  double timeStep;


  while(curtime<endtime){

    // compute time step and current time
    if(step%numstep ==0 ){
      timeStep = _gammas * this->criticalExplicitTimeStep(ufield);
      Msg::Info("time step value: %e",timeStep);
      esys->setTimeStep(timeStep);
    }
    curtime+=timeStep;
    if(curtime>endtime) curtime = endtime;
    esys->systemSolve();

  // new forces
    // Update Boundary Conditions
    this->setTimeForBC(curtime);
    this->fixNodalDofs();
    dynufield->updateFixedDof(timeStep);
    ipf.compute1state(IPStateBase::current);
    // eval fracture
//    ipf.evalFracture(IPState::current,curtime);
    this->computeRightHandSide(esys,pAssembler,ufield,&ipf);
  // Archiving
    if((step+1)%nsba == 0){
      Msg::Info("Archiving view at time %e",curtime);
      ufield->buildView(domainVector,curtime,step+1,"displacement",-1,false);
      ufield->buildView(domainVector,curtime,step+1,"velocity",1,false);
      ipf.buildView(domainVector,curtime,step+1,"VonMises",-1,false);
      ipf.buildView(domainVector,curtime,step+1,"sigmaxx",0,false);
      ipf.buildView(domainVector,curtime,step+1,"sigmayy",1,false);
      ipf.buildView(domainVector,curtime,step+1,"tauxy",3,false);
      ipf.buildView(domainVector,curtime,step+1,"VonMisesMax",4,false);
      efield.buildView(domainVector,curtime,step+1,"total",-1,false);
    }
    ufield->archiving(curtime);
    ipf.archive(curtime);
    efield.archive(curtime);
    // Edge force value;
    FILE *fp;
    for(std::map<int,double>::iterator it=aefvalue.begin(); it!=aefvalue.end(); ++it){
      std::ostringstream oss;
      oss << (it->first)/10;
      std::string s = oss.str();
      oss.str("");
      oss << (it->first)%10;
      std::string s2 = oss.str();
      std::string fname = "force"+s+"comp"+s2+".csv";
      fp = fopen(fname.c_str(),"a");
      fprintf(fp,"%e;%e\n",curtime,it->second);
      fclose(fp);
    }


    // next step
    ipf.nextStep(curtime);
    esys->nextStep();
    step++;
  }
  delete ufield;
  Msg::Info("Explicit OK");
#else
  Msg::Error("Petsc is not available and so it is impossible to solve the problem. Please install PETsc correctly");
#endif
}


//
// C++ Interface: terms Quasi Static
//
// Description: Files with definition of function : nonLinearMechSolver::solveSNL()
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

// Function to compute the initial norm
double nonLinearMechSolver::computeNorm0(linearSystem<double> *lsys, dofManager<double> *pAssembler,
                                     unknownField *ufield, IPField *ipf){
  double normFext,normFint;
  // Set all component of RightHandSide to zero (only RightHandSide is used to compute norm
  lsys->zeroRightHandSide();

  // fext norm
  // compute ext forces
  this->computeExternalForces(ipf,ufield);

  // Contact forces
  this->computeContactForces();

  // norm
  normFext = lsys->normInfRightHandSide();

  // Internal forces
  lsys->zeroRightHandSide();
  // compute internal forces
    this->computeInternalForces(ufield);
    //norm
    normFint = lsys->normInfRightHandSide();

    // archive
    return normFext+normFint;
}
// compute Fext-Fint
double nonLinearMechSolver::computeRightHandSide(linearSystem<double> *lsys, dofManager<double> *pAssembler,
                                    unknownField *ufield, IPField *ipf){
  lsys->zeroRightHandSide();
  staticDofManager<double> *pA2 = dynamic_cast<staticDofManager<double>*>(pAssembler);
  pA2->clearRHSfixed();
  this->computeInternalForces(ufield);
  // save Fint component to archive ( write in file when Fint = Fext)
  pA2->getForces(aef,aefvalue,_allaef);
  // compute ext forces
  this->computeExternalForces(ipf,ufield);
  // compute contact forces
  this->computeContactForces();
  return lsys->normInfRightHandSide();
}

void nonLinearMechSolver::computeInternalForces(unknownField *ufield){
  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end();++itdom)
  {
    partDomain *dom = *itdom;
    dom->inverseLinearTermSign(); // Because rightHandSide = Fext - Fint
    Assemble(dom->getLinearBulkTerm(),*(dom->getFunctionSpace()),dom->g->begin(),dom->g->end(),
             *(dom->getBulkGaussIntegrationRule()),ufield,*pAssembler);

    if(dom->IsInterfaceTerms()){
      dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
      // Assembling loop on elementary interface terms
      Assemble(dgdom->getLinearInterfaceTerm(),*(dgdom->getFunctionSpace()),dgdom->gi->begin(),dgdom->gi->end(),*(dgdom->getInterfaceGaussIntegrationRule()),
                        ufield,*pAssembler); // Use the same GaussQuadrature rule than on the boundary
      // Assembling loop on elementary boundary interface terms
      Assemble(dgdom->getLinearVirtualInterfaceTerm(),*(dgdom->getFunctionSpace()),dgdom->gib->begin(),dgdom->gib->end(),
                 *(dgdom->getInterfaceGaussIntegrationRule()),ufield,*pAssembler); // Use the same GaussQuadrature rule than on the boundary
    }
    dom->inverseLinearTermSign(); // Otherwise Fint has not the right sign
  }
}

void nonLinearMechSolver::computeContactForces(){
  for(contactContainer::iterator it = _allContact.begin(); it!=_allContact.end(); ++it){
    contactDomain *cdom = *it;
    Assemble(*(cdom->getForceTerm()),*(cdom->getSpace()),cdom->gSlave->begin(),
            cdom->gSlave->end(),*(cdom->getGaussIntegration()),*pAssembler);
  }
}

void nonLinearMechSolver::computeStiffMatrix(const unknownField *ufield){

  for(std::vector<partDomain*>::iterator itdom=domainVector.begin(); itdom!=domainVector.end(); ++itdom)
  {
    partDomain* dom = *itdom;
    // Assembling loop on Elementary terms
    Assemble(*(dom->getBilinearBulkTerm()),*(dom->getFunctionSpace()),dom->g->begin(),dom->g->end(),
             *(dom->getBulkGaussIntegrationRule()),*pAssembler);

    if(dom->IsInterfaceTerms()){
      dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
      // Assembling loop on elementary interface terms
      Assemble(*(dgdom->getBilinearInterfaceTerm()),*(dom->getFunctionSpace()),dgdom->gi->begin(),dgdom->gi->end(),
                 *(dgdom->getInterfaceGaussIntegrationRule()),*pAssembler);
      // Assembling loop on elementary boundary interface terms
      Assemble(*(dgdom->getBilinearVirtualInterfaceTerm()),*(dom->getFunctionSpace()),dgdom->gib->begin(),dgdom->gib->end(),
                 *(dgdom->getInterfaceGaussIntegrationRule()),*pAssembler);
    }
  }

  // Contact
  // little particular because it the term itself which know (via its linked linear term) the element
  // where there is contact and so a bilinearterm != 0 as to be computed
  for(contactContainer::iterator it = _allContact.begin(); it!=_allContact.end(); ++it){
    contactDomain *cdom = *it;
    contactBilinearTermBase<double> *sterm = dynamic_cast<contactBilinearTermBase<double>*>(cdom->getStiffnessTerm());
    Assemble(*sterm,*(cdom->getSpace()),sterm->getContactNodes()->elemBegin(),
                    sterm->getContactNodes()->elemEnd(),*(cdom->getGaussIntegration()),*pAssembler);
    sterm->clearContactNodes();
  }
}

// Newton Raphson scheme to solve one step
void nonLinearMechSolver::NewtonRaphson(linearSystem<double> *lsys, dofManager<double> *pAssembler,unknownField *ufield,
                                    IPField *ipf,const double Mtime){
  // compute ipvariable
  ipf->compute1state(IPStateBase::current);

  // Compute the norm0 : norm(Fint) + norm(Fext) for relative convergence
  double norm0 = this->computeNorm0(lsys,pAssembler,ufield,ipf);

  // Compute Right Hand Side (Fext-Fint)
  double normFinf = this->computeRightHandSide(lsys,pAssembler,ufield,ipf);

  // loop until convergence
  int iter=0;
  double relnorm = normFinf/norm0;
  printf("iteration n° %d : residu : %lf\n",iter,relnorm);
  while(relnorm>_tol){
    iter++;
    // Compute Stiffness Matrix
    this->computeStiffMatrix(ufield);

    // Solve KDu = Fext-Fint
    lsys->systemSolve();

    // update displacement
    ufield->update();

    // update ipvariable
    ipf->compute1state(IPStateBase::current);

    // new forces
    normFinf = this->computeRightHandSide(lsys,pAssembler,ufield,ipf);

    // Check of convergence
    relnorm = normFinf/norm0;
    printf("iteration n° %d : residu : %lf\n",iter,relnorm);
    lsys->zeroMatrix(); // here otherwise if it has been in computeMatrix the first iteration is very low HOW ??
  }
}

// For now no initial displacement
void nonLinearMechSolver::solveSNL()
{
  Msg::Info("SNL Data : nstep =%d endtime=%f",this->getNumStep(),this->getEndTime());
  // init
  this->init();
  // Select the solver for linear system Ax=b (KDeltau = Fext-Fint)
  linearSystem<double> *lsys;
  if(nonLinearMechSolver::whatSolver == Taucs){
    #if defined(HAVE_TAUCS)
      lsys = new linearSystemCSRTaucs<double>;
      Msg::Info("Taucs is chosen to solve\n");
    #else
      lsys = new linearSystemGmm<double>;
      lsys = dynamic_cast<linearSystemGmm<double>*>(lsys);
      dynamic_cast<linearSystemGmm<double>*>(lsys)->setNoisy(2);
      Msg::Error("Taucs is not installed\n Gmm is chosen to solve\n");
    #endif
  }
  else if(nonLinearMechSolver::whatSolver == Petsc){
    #if defined(HAVE_PETSC)
      lsys = new linearSystemPETSc<double>;
      Msg::Info("PETSc is chosen to solve\n");
    #else
      lsys = new linearSystemGmm<double>;
      lsys = dynamic_cast<linearSystemGmm<double>*>(lsys);
      dynamic_cast<linearSystemGmm<double>*>(lsys)->setNoisy(2);
      Msg::Error("PETSc is not installed\n Gmm is chosen to solve\n");
    #endif
  }
  else{
    lsys = new linearSystemGmm<double>;
    dynamic_cast<linearSystemGmm<double>*>(lsys)->setNoisy(2);
    Msg::Info("Gmm is chosen to solve\n");
  }

  // Creation of dof manager. The Dof where the displacement is prescribed are fixe to zero
  // for initialization and numerotation of Dof (t=0 at initialization --> prescribed displacement =0)

  if (pAssembler) delete pAssembler;
  pAssembler = new staticDofManager<double>(lsys);

  // we first do all fixations. the behavior of the dofManager is to
  // give priority to fixations : when a dof is fixed, it cannot be
  // numbered afterwards

  // ATTENTION The BC must be rewriten to take into account different fields (CG/DG and fullDG field for exemple)
  // Fix dof to allow the dofManager to number the dofs
  this->fixNodalDofs();
  this->numberDofs(lsys);

  // iterative scheme (loop on timestep)
  double curtime = 0.;
  double dt = double(endtime)/double(numstep);
  unknownField *ufield = new unknownStaticField(pAssembler,domainVector,&_allContact,3,anoded,varcd); // 3 components by nodes User choice ??
  this->restart(ufield); // CHANGE THIS
  IPField ipf(&domainVector,pAssembler,pModel,ufield,vaip); // Field for GaussPoint
  energeticField enerfield(lsys,&ipf,ufield,pAssembler,domainVector,_allaef);
  ipf.compute1state(IPStateBase::initial);
  ipf.initialBroken(pModel, initbrokeninter);
  ipf.copy(IPStateBase::initial,IPStateBase::previous); // if initial stress previous must be initialized before computation
  this->initTerms(ufield,&ipf);

  for(int ii=0;ii<numstep;ii++){
    curtime+=dt;
    printf("t= %lf on %lf\n",curtime,endtime);

    this->setTimeForBC(curtime);

    // Update prescribed Dof displacement
    this->fixNodalDofs();
    ufield->updateFixedDof();

    // Solve one step by NR scheme
    NewtonRaphson(lsys,pAssembler,ufield,&ipf,curtime);

    if((ii+1)%nsba == 0){
      ufield->buildView(domainVector,curtime,ii+1,"displacement",-1,false);
      ipf.buildView(domainVector,curtime,ii+1,"VonMises",-1,false);
      ipf.buildView(domainVector,curtime,ii+1,"sigmaxx",0,false);
      ipf.buildView(domainVector,curtime,ii+1,"sigmayy",1,false);
      ipf.buildView(domainVector,curtime,ii+1,"tauxy",3,false);
      enerfield.buildView(domainVector,curtime,ii+1,"total",-1,false);
    }

    // Archiving
    ufield->archiving(curtime);
    ipf.archive(curtime);
    enerfield.archive(curtime);
    // Edge force value;
    FILE *fp;
    for(std::map<int,double>::iterator it=aefvalue.begin(); it!=aefvalue.end(); ++it){
      std::ostringstream oss;
      oss << (it->first)/10;
      std::string s = oss.str();
      oss.str("");
      oss << (it->first)%10;
      std::string s2 = oss.str();
      std::string fname = "force"+s+"comp"+s2+".csv";
      fp = fopen(fname.c_str(),"a");
      fprintf(fp,"%lf;%lf\n",curtime,it->second);
      fclose(fp);
    }

    // next step for ipvariable
    ipf.nextStep(curtime);
  }
  delete ufield;
}

