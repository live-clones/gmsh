#include "GmshConfig.h"
#include "dgDofContainer.h"
#include "function.h"
#include "dgGroupOfElements.h"
#include "dgConservationLaw.h"
#include "dgAlgorithm.h"
#include "GModel.h"
#ifdef HAVE_MPI
#include "mpi.h"
#else
#include "string.h"
#endif
#include <sstream>
#include "MElement.h"
dgDofContainer::dgDofContainer (dgGroupCollection *groups, int nbFields):
  _groups(*groups), _mshStep(0)
{
  int _dataSize = 0;
  _dataSizeGhost=0;
  _totalNbElements = 0;
  _parallelStructureExists = false;
  _nbFields = nbFields;
  for (int i=0; i< _groups.getNbElementGroups();i++){
    int nbNodes    = _groups.getElementGroup(i)->getNbNodes();
    int nbElements = _groups.getElementGroup(i)->getNbElements();
    _totalNbElements +=nbElements;
    _dataSize += nbNodes*_nbFields*nbElements;
  }

  // allocate the big vectors
  _data      = new fullVector<double>(_dataSize);
  // create proxys for each group
  int offset = 0;
  _dataProxys.resize(_groups.getNbElementGroups()+_groups.getNbGhostGroups());
  for (int i=0;i<_groups.getNbElementGroups();i++){    
    dgGroupOfElements *group = _groups.getElementGroup(i);
    _groupId[group] = i;
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
    _dataProxys[i] = new fullMatrix<double> (&(*_data)(offset),nbNodes, _nbFields*nbElements);
    offset += nbNodes*_nbFields*nbElements;
  }  

  //ghosts
  
  int totalNbElementsGhost =0;
  for (int i=0; i<_groups.getNbGhostGroups(); i++){
    int nbNodes    = _groups.getGhostGroup(i)->getNbNodes();
    int nbElements = _groups.getGhostGroup(i)->getNbElements();
    totalNbElementsGhost +=nbElements;
    _dataSizeGhost += nbNodes*_nbFields*nbElements;
  }

  _dataProxys.resize(_groups.getNbElementGroups()+_groups.getNbGhostGroups());
  _ghostData = new fullVector<double>(_dataSizeGhost);
  offset=0;
  for (int i=0;i<_groups.getNbGhostGroups();i++){    
    dgGroupOfElements *group = _groups.getGhostGroup(i);
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
    _groupId[group] = i+_groups.getNbElementGroups();
    _dataProxys[i+_groups.getNbElementGroups()] = new fullMatrix<double> (&(*_ghostData)(offset),nbNodes, _nbFields*nbElements);
    offset += nbNodes*_nbFields*nbElements;
  }  

}

dgDofContainer::~dgDofContainer (){
  if(_parallelStructureExists) {
    delete []countSend;
    delete []countRecv;
    delete []shiftSend;
    delete []shiftRecv;
    delete []groupShiftRecv;
    delete []sendBuf;
    delete []recvBuf;
  }
  for (int i=0;i<_dataProxys.size();++i) delete _dataProxys[i];
  delete _data;
  delete _ghostData;
}

void dgDofContainer::buildParallelStructure(){
  if (_parallelStructureExists)
    return;

  // MPI all2all buffers
  countSend = new int[Msg::GetCommSize()];
  shiftSend = new int[Msg::GetCommSize()];
  countRecv = new int[Msg::GetCommSize()];
  shiftRecv = new int[Msg::GetCommSize()];
  groupShiftRecv = new int[_groups.getNbGhostGroups()];
  for(int i=0;i<Msg::GetCommSize();i++){
    countSend[i]=0;
    countRecv[i]=0;
    for(size_t j=0;j<_groups.getNbImageElementsOnPartition(i);j++){
      countSend[i] += _groups.getElementGroup(_groups.getImageElementGroup(i,j))->getNbNodes()*_nbFields;
    }
  }
  for(size_t i=0; i<_groups.getNbGhostGroups(); i++){
    dgGroupOfElements *group = _groups.getGhostGroup(i);
    groupShiftRecv[i] = countRecv[group->getGhostPartition()];
    countRecv[group->getGhostPartition()]+=group->getNbElements()*group->getNbNodes()*_nbFields;
  }
  shiftSend[0] = shiftRecv[0]=0;
  int totalSend = countSend[0];
  int totalRecv = countRecv[0];
  for(size_t i=1; i<Msg::GetCommSize(); i++){
    shiftSend[i] = shiftSend[i-1]+countSend[i-1];
    shiftRecv[i] = shiftRecv[i-1]+countRecv[i-1];
    totalSend += countSend[i];
    totalRecv += countRecv[i];
  }
  for(size_t i=0; i<_groups.getNbGhostGroups(); i++){
    dgGroupOfElements *group = _groups.getGhostGroup(i);
    groupShiftRecv[i] += shiftRecv[group->getGhostPartition()];
  }
  sendBuf = new double[totalSend];
  recvBuf = new double[totalRecv];

  _parallelStructureExists = true;
}

void dgDofContainer::scatter() {
  if(!_parallelStructureExists)
    buildParallelStructure();
  //1) fill
  int index=0;
  for(int i=0;i<Msg::GetCommSize();i++){
    for(size_t j=0;j<_groups.getNbImageElementsOnPartition(i);j++){
      fullMatrix<double> &sol = getGroupProxy(_groups.getImageElementGroup(i,j));
      int eid = _groups.getImageElementPositionInGroup(i,j);
      for(int l=0;l<_nbFields;l++) {
        for(int k=0;k<sol.size1();k++) {
          sendBuf[index++] = sol(k, eid *_nbFields+l);
        }
      }
    }
  }
  //2) send
  #ifdef HAVE_MPI
  MPI_Alltoallv(sendBuf,countSend,shiftSend,MPI_DOUBLE,recvBuf,countRecv,shiftRecv,MPI_DOUBLE,MPI_COMM_WORLD);
  #else
  memcpy(recvBuf,sendBuf,countSend[0]*sizeof(double));
  #endif
  //3) distribute
  for(int i=0; i< _groups.getNbGhostGroups();i++) {
    fullMatrix<double> &sol = getGroupProxy(i+_groups.getNbElementGroups());
    fullMatrix<double> recvProxy (recvBuf + groupShiftRecv[i], sol.size1(), sol.size2());
    sol.setAll(recvProxy);
  }
}
void dgDofContainer::setAll(double v) {
  for(int i=0;i<_data->size();i++)
    (*_data)(i)=v;
  for(int i=0;i<_ghostData->size();i++)
    (*_ghostData)(i)=v;
}
void dgDofContainer::scale(double f) 
{
  _data->scale(f);
  _ghostData->scale(f); 
}
void dgDofContainer::scale(std::vector<dgGroupOfElements*>groupsVector, double f){
  for(int i=0;i<groupsVector.size();i++){
    dgGroupOfElements *g=groupsVector[i];
    fullMatrix<double> &proxy=getGroupProxy(g);
    proxy.scale(f);
  }
}

void dgDofContainer::axpy(dgDofContainer &x, double a)
{
  _data->axpy(*x._data,a);
  _ghostData->axpy(*x._ghostData,a); 
}
void dgDofContainer::axpy(std::vector<dgGroupOfElements*>groupsVector,dgDofContainer &x, double a){
  for(int i=0;i<groupsVector.size();i++){
    dgGroupOfElements *g=groupsVector[i];
    fullMatrix<double> &proxy=getGroupProxy(g);
    fullMatrix<double> &xProxy=x.getGroupProxy(g);
    proxy.add(xProxy,a);
  }
}

double dgDofContainer::norm() {
  double localNorm = _data->norm();
  #ifdef HAVE_MPI
  double globalNorm;
  MPI_Allreduce(&localNorm, &globalNorm, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  return globalNorm;
  #else
  return localNorm;
  #endif
}
double dgDofContainer::norm(std::vector<dgGroupOfElements *>gV){
  double norm=0;
  for(int i=0;i<gV.size();i++){
    dgGroupOfElements* g=gV[i];
    fullMatrix<double>&groupData=getGroupProxy(g);
    for(int r=0;r<groupData.size1();r++){
      for(int c=0;c<groupData.size1();c++){
        norm+=groupData(r,c)*groupData(r,c);
      }
    }
  }
  return norm;
}
void dgDofContainer::save(const std::string name) {
  FILE *f = fopen (name.c_str(),"wb");
  _data->binarySave(f);
  fclose(f);
}
void dgDofContainer::load(const std::string name) {
  FILE *f = fopen (name.c_str(),"rb");
  _data->binaryLoad(f);
  fclose(f);
}

void dgDofContainer::L2Projection(std::string functionName){
  scale(0.);
  dgDofContainer rhs(&_groups, _nbFields);
  for (int iGroup=0;iGroup<_groups.getNbElementGroups();iGroup++) {
    const dgGroupOfElements &group = *_groups.getElementGroup(iGroup);
    fullMatrix<double> Source = fullMatrix<double> (group.getNbIntegrationPoints(),group.getNbElements() * _nbFields);
    dataCacheMap cacheMap;
    cacheMap.setNbEvaluationPoints(group.getNbIntegrationPoints());
    dataCacheElement &cacheElement = cacheMap.getElement();
    cacheMap.provideData("UVW",1,3).set(group.getIntegrationPointsMatrix());
    dataCacheDouble &sourceTerm = cacheMap.get(functionName);
    fullMatrix<double> source;
    for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
      cacheElement.set(group.getElement(iElement));
      source.setAsProxy(Source, iElement*_nbFields, _nbFields);
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<_nbFields;k++)
          source(iPt,k) = sourceTerm(iPt,k)*detJ;
      }
    }
    rhs.getGroupProxy(iGroup).gemm(group.getSourceRedistributionMatrix(), Source);
    dgAlgorithm::multAddInverseMassMatrix(group, rhs.getGroupProxy(iGroup), getGroupProxy(iGroup));
  }
}

void dgDofContainer::Mesh2Mesh_BuildL2Projection(linearSystemCSRGmm<double> &projector,dgDofContainer &donor){
// for basis function i
// for integration pts
// search for element in 2d mesh
// for basis function j
// evauate quad
// add to matrix correct indices

// For multigrid, the donor and receiver are inverted :S
  dgGroupCollection* dGroups = donor.getGroups();
  dgGroupCollection* rGroups = this->getGroups();
  std::vector<int> rGroupsStartIGlobal(rGroups->getNbElementGroups() + 1);
  int jGlobal = 0; // indices in global container
  rGroupsStartIGlobal[0] = 0;
  for (int i = 1; i<rGroupsStartIGlobal.size(); i++)
    rGroupsStartIGlobal[i] = rGroupsStartIGlobal[i-1] + rGroups->getElementGroup(i-1)->getNbElements()*rGroups->getElementGroup(i-1)->getNbNodes();
  
  projector.allocate(rGroupsStartIGlobal[rGroupsStartIGlobal.size()-1]);
//   fullMatrix<double> buffer = fullMatrix<double> (3,6);
  for (int jGroup=0;jGroup<dGroups->getNbElementGroups();jGroup++) {// for 3d.groups
    const dgGroupOfElements &dGroup = *dGroups->getElementGroup(jGroup);
    fullMatrix<double> iPtsMatrix = dGroup.getIntegrationPointsMatrix();
    for (int jElement=0 ; jElement<dGroup.getNbElements() ;++jElement) {// for elements
      double rShapeFun[256];
      double dShapeFun[256];
      GModel *rModel = rGroups->getModel();
      GModel *dModel = dGroups->getModel();
      MElement* dElem = dGroup.getElement(jElement);
      for (int iPt =0; iPt< dGroup.getNbIntegrationPoints(); iPt++) {
        double x=0,y=0,z=0;
        dElem->getFunctionSpace()->f(iPtsMatrix(iPt,0),iPtsMatrix(iPt,1),iPtsMatrix(iPt,2),dShapeFun);      
        for (int iVer=0; iVer < dElem->getNumVertices(); iVer++) {
          x += dElem->getVertex(iVer)->x()*dShapeFun[iVer];
          y += dElem->getVertex(iVer)->y()*dShapeFun[iVer];
          z += dElem->getVertex(iVer)->z()*dShapeFun[iVer];
        }
        z = 0; // dummy projection to 2d mesh
        SPoint3 p(x,y,z); // find p in 2D mesh
        MElement *rElem = rGroups->getModel()->getMeshElementByCoord(p);
        int iGroup,iElement;
        rGroups->find(rElem,iGroup,iElement);
        if (iElement == -1)
          Msg::Error("Integration point not found in receiver mesh.");
        const dgGroupOfElements &rGroup = *rGroups->getElementGroup(iGroup);      
        double U[3],X[3]={x,y,z};
        rElem->xyz2uvw(X,U);
        dGroup.getFunctionSpace().f(iPtsMatrix(iPt,0),iPtsMatrix(iPt,1),iPtsMatrix(iPt,2),dShapeFun);
        rGroup.getFunctionSpace().f(U[0],U[1],U[2],rShapeFun);
        const double detJ = dGroup.getDetJ (jElement, iPt);
        int iGlobal = rGroupsStartIGlobal[iGroup]+rGroup.getNbNodes()*iElement;
        for (int jNode=0;jNode<dGroup.getNbNodes();jNode++){
          for (int iNode=0;iNode<rGroup.getNbNodes();iNode++){
            double val = rShapeFun[iNode]*dShapeFun[jNode]*iPtsMatrix(iPt,3)*detJ;
            projector.addToMatrix(iGlobal+iNode,jGlobal+jNode,val);
//             buffer(iGlobal+iNode,jGlobal+jNode) += val;
          }
        }
      }
      jGlobal += dGroup.getNbNodes();
    }
  }
  multAddInverseMassMatrixL2Projection(projector);
//   buffer.print();
}

void dgDofContainer::multAddInverseMassMatrixL2Projection(linearSystemCSRGmm<double> &projector){
  dgGroupCollection* rGroups = this->getGroups();
  int *startIndex;
  int *columns;
  double *values;
  projector.getMatrix(startIndex,columns,values);

  int iGlobal = 0;
  for (int iGroup=0;iGroup<rGroups->getNbElementGroups();iGroup++) {// for 2d.groups
    const dgGroupOfElements &rGroup = *rGroups->getElementGroup(iGroup);
    for (int iElement=0 ; iElement<rGroup.getNbElements() ;++iElement) {// for elements
      fullMatrix<double> buffer = fullMatrix<double> (rGroup.getNbNodes(),startIndex[iGlobal+1]-startIndex[iGlobal]);
      fullMatrix<double> buffer2 = fullMatrix<double> (rGroup.getNbNodes(),startIndex[iGlobal+1]-startIndex[iGlobal]);
      fullMatrix<double> iMassEl;
      for (int iNode = 0 ; iNode<rGroup.getNbNodes() ;++iNode) {
        for (int i = startIndex[iGlobal+iNode]; i < startIndex[iGlobal+iNode+1] ; i++)
          buffer(iNode,i-startIndex[iGlobal+iNode]) = values[i];
      }
      iMassEl.setAsProxy(rGroup.getInverseMassMatrix(),iElement*rGroup.getNbNodes(),rGroup.getNbNodes());
      buffer2.gemm(iMassEl,buffer);
      for (int iNode = 0 ; iNode<rGroup.getNbNodes() ;++iNode) {
        for (int i = startIndex[iGlobal+iNode]; i < startIndex[iGlobal+iNode+1] ; i++)
          values[i] = buffer2(iNode,i-startIndex[iGlobal+iNode]);
      }
      iGlobal+=rGroup.getNbNodes();
    }
  }
}

void dgDofContainer::Mesh2Mesh_ApplyL2Projection(linearSystemCSRGmm<double> &projector,dgDofContainer &donor){
  scale(0.);

  dgGroupCollection* dGroups = donor.getGroups();
  dgGroupCollection* rGroups = this->getGroups();
  std::vector<int> dGroupsStartIGlobal(dGroups->getNbElementGroups() + 1);
  int iGlobal = 0; // indices in global container
  dGroupsStartIGlobal[0] = 0;
  for (int i = 1; i<dGroupsStartIGlobal.size(); i++)
    dGroupsStartIGlobal[i] = dGroupsStartIGlobal[i-1] + dGroups->getElementGroup(i-1)->getNbElements()*dGroups->getElementGroup(i-1)->getNbNodes();

  int *startIndex;
  int *columns;
  double *values;
  projector.getMatrix(startIndex,columns,values);

int nbFields = 1; // TO DEFINE !!!

  for (int iGroup=0;iGroup<rGroups->getNbElementGroups();iGroup++) {// for 2d.groups
    const dgGroupOfElements &rGroup = *rGroups->getElementGroup(iGroup);
//    fullMatrix<double> buffer = fullMatrix<double> (rGroup.getNbNodes(),rGroup.getNbElements() * _nbFields);
    this->getGroupProxy(iGroup).scale(0);
    for (int iElement=0 ; iElement<rGroup.getNbElements() ;++iElement) {// for elements
      for (int iNode = 0 ; iNode<rGroup.getNbNodes() ;++iNode) {
        int jGroup = 0;
        for (int i = startIndex[iGlobal++]; i < startIndex[iGlobal] ; i++){
          int jGlobal = columns[i];
          while (jGlobal > dGroupsStartIGlobal[jGroup+1]) {
            jGroup++;
          }
          int jElement = (jGlobal-dGroupsStartIGlobal[jGroup])/dGroups->getElementGroup(jGroup)->getNbNodes();
          int jNode = jGlobal-dGroupsStartIGlobal[jGroup]-jElement*dGroups->getElementGroup(jGroup)->getNbNodes();
          for (int m = 0; m < nbFields; m++){
            this->getGroupProxy(iGroup)(iNode,iElement*nbFields+m) += values[i]*(donor.getGroupProxy(jGroup))(jNode,jElement*nbFields+m);
//             printf("%d %d %d %f %f %f\n",iGlobal,jGlobal,i, buffer(iNode,iElement*nbFields+m),values[i],(donor.getGroupProxy(jGroup))(jNode,jElement*nbFields+m));
          }
        }
      }
    }//*/
//     buffer.print();
//    dgAlgorithm::multAddInverseMassMatrix(rGroup, buffer, this->getGroupProxy(iGroup));
//     this->getGroupProxy(iGroup).print();
  }
}

void dgDofContainer::exportGroupIdMsh(){
  // the elementnodedata::export does not work !!

  std::ostringstream name_oss;
  name_oss<<"groupsId.msh";
  if(Msg::GetCommSize()>1)
    name_oss<<"_"<<Msg::GetCommRank();
  FILE *f = fopen (name_oss.str().c_str(),"w");
  int COUNT = 0;
  for (int i=0;i < _groups.getNbElementGroups() ;i++){
    COUNT += _groups.getElementGroup(i)->getNbElements();
  }
  fprintf(f,"$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");  
  fprintf(f,"$ElementNodeData\n");
  fprintf(f,"1\n");
  fprintf(f,"\"%s\"\n","GroupsIds");
  fprintf(f,"1\n");
  fprintf(f,"0.0\n");
  fprintf(f,"%d\n", Msg::GetCommSize() > 1 ? 4 : 3);
  fprintf(f,"0\n 1\n %d\n",COUNT);
  if(Msg::GetCommSize() > 1) fprintf(f,"%d\n", Msg::GetCommRank());
  for (int i=0;i < _groups.getNbElementGroups()  ;i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
      MElement *e = group->getElement(iElement);
      int num = e->getNum();
      fullMatrix<double> sol(getGroupProxy(i), iElement*_nbFields,_nbFields);
      fprintf(f,"%d %d",num,sol.size1());
      for (int k=0;k<sol.size1();++k) {
        fprintf(f," %.16E ",i*1.0);
      }
      fprintf(f,"\n");
    }
  }
  fprintf(f,"$EndElementNodeData\n");
  fclose(f);
  return;
  // we should discuss that : we do a copy of the solution, this should
  // be avoided !

  /*std::map<int, std::vector<double> > data;
  
  for (int i=0;i < _groups.getNbElementGroups() ;i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
      MElement *e = group->getElement(iElement);
      int num = e->getNum();
      fullMatrix<double> sol(getGroupProxy(i), iElement*_nbFields,_nbFields);
      std::vector<double> val;
      //      val.resize(sol.size2()*sol.size1());
      val.resize(sol.size1());
      int counter = 0;
      //      for (int iC=0;iC<sol.size2();iC++)
      printf("%g %g %g\n",sol(0,0),sol(1,0),sol(2,0));
      for (int iR=0;iR<sol.size1();iR++)val[counter++] = sol(iR,0);
      data[num] = val;
    }
  }

  PView *pv = new PView (name, "ElementNodeData", _gm, data, 0.0, 1);
  pv->getData()->writeMSH(name+".msh", false); 
  delete pv;
  */
}

void dgDofContainer::exportMultirateGroupMsh(){
  // the elementnodedata::export does not work !!

  std::ostringstream name_oss;
  name_oss<<"groupsMultirateType.msh";
  if(Msg::GetCommSize()>1)
    name_oss<<"_"<<Msg::GetCommRank();
  FILE *f = fopen (name_oss.str().c_str(),"w");
  int COUNT = 0;
  for (int i=0;i < _groups.getNbElementGroups() ;i++){
    COUNT += _groups.getElementGroup(i)->getNbElements();
  }
  fprintf(f,"$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");  
  fprintf(f,"$ElementNodeData\n");
  fprintf(f,"1\n");
  fprintf(f,"\"%s\"\n","GroupsIds");
  fprintf(f,"1\n");
  fprintf(f,"0.0\n");
  fprintf(f,"%d\n", Msg::GetCommSize() > 1 ? 4 : 3);
  fprintf(f,"0\n 1\n %d\n",COUNT);
  if(Msg::GetCommSize() > 1) fprintf(f,"%d\n", Msg::GetCommRank());
  for (int i=0;i < _groups.getNbElementGroups()  ;i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    int groupType=0;//-3*group->getMultirateExponent();
    if(group->getIsInnerMultirateBuffer())
      groupType+=1;
    if(group->getIsOuterMultirateBuffer())
      groupType+=2;
    for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
      MElement *e = group->getElement(iElement);
      int num = e->getNum();
      fullMatrix<double> sol(getGroupProxy(i), iElement*_nbFields,_nbFields);
      fprintf(f,"%d %d",num,sol.size1());
      for (int k=0;k<sol.size1();++k) {
        fprintf(f," %.16E ",groupType*1.0);
      }
      fprintf(f,"\n");
    }
  }
  fprintf(f,"$EndElementNodeData\n");
  fclose(f);
  return;
  // we should discuss that : we do a copy of the solution, this should
  // be avoided !

  /*std::map<int, std::vector<double> > data;
  
  for (int i=0;i < _groups.getNbElementGroups() ;i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
      MElement *e = group->getElement(iElement);
      int num = e->getNum();
      fullMatrix<double> sol(getGroupProxy(i), iElement*_nbFields,_nbFields);
      std::vector<double> val;
      //      val.resize(sol.size2()*sol.size1());
      val.resize(sol.size1());
      int counter = 0;
      //      for (int iC=0;iC<sol.size2();iC++)
      printf("%g %g %g\n",sol(0,0),sol(1,0),sol(2,0));
      for (int iR=0;iR<sol.size1();iR++)val[counter++] = sol(iR,0);
      data[num] = val;
    }
  }

  PView *pv = new PView (name, "ElementNodeData", _gm, data, 0.0, 1);
  pv->getData()->writeMSH(name+".msh", false); 
  delete pv;
  */
}

void dgDofContainer::exportMsh(const std::string name)
{
  // the elementnodedata::export does not work !!

  for (int ICOMP = 0; ICOMP<_nbFields;++ICOMP){
    std::ostringstream name_oss, name_view;
    name_view<<"comp_"<<ICOMP;
    name_oss<<name<<"_COMP_"<<ICOMP<<".msh";
    if(Msg::GetCommSize()>1)
      name_oss<<"_"<<Msg::GetCommRank();
    FILE *f = fopen (name_oss.str().c_str(),"w");
    if(!f){
      Msg::Error("Unable to open export file '%s'", name.c_str());
    }

    int COUNT = 0;
    for (int i=0;i < _groups.getNbElementGroups() ;i++){
      COUNT += _groups.getElementGroup(i)->getNbElements();
    }
    fprintf(f,"$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");  
    fprintf(f,"$ElementNodeData\n");
    fprintf(f,"1\n");
    fprintf(f,"\"%s\"\n",name_view.str().c_str());
    fprintf(f,"1\n");
    fprintf(f,"%d\n", _mshStep); // should print actual time here
    fprintf(f,"%d\n", Msg::GetCommSize() > 1 ? 4 : 3);
    fprintf(f,"%d\n 1\n %d\n", _mshStep, COUNT);
    if(Msg::GetCommSize() > 1) fprintf(f,"%d\n", Msg::GetCommRank());
    for (int i=0;i < _groups.getNbElementGroups()  ;i++){
      dgGroupOfElements *group = _groups.getElementGroup(i);
      for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
        MElement *e = group->getElement(iElement);
        int num = e->getNum();
        fullMatrix<double> sol(getGroupProxy(i), iElement*_nbFields,_nbFields);
        fprintf(f,"%d %d",num,sol.size1());
        for (int k=0;k<sol.size1();++k) {
          fprintf(f," %.16E ",sol(k,ICOMP));
        }
        fprintf(f,"\n");
      }
    }
    fprintf(f,"$EndElementNodeData\n");
    fclose(f);
  }
  
  _mshStep++;

  // we should discuss that : we do a copy of the solution, this should
  // be avoided !

  /*std::map<int, std::vector<double> > data;
  
  for (int i=0;i < _groups.getNbElementGroups() ;i++){
    dgGroupOfElements *group = _groups.getElementGroup(i);
    for (int iElement=0 ; iElement< group->getNbElements() ;++iElement) {
      MElement *e = group->getElement(iElement);
      int num = e->getNum();
      fullMatrix<double> sol(getGroupProxy(i), iElement*_nbFields,_nbFields);
      std::vector<double> val;
      //      val.resize(sol.size2()*sol.size1());
      val.resize(sol.size1());
      int counter = 0;
      //      for (int iC=0;iC<sol.size2();iC++)
      printf("%g %g %g\n",sol(0,0),sol(1,0),sol(2,0));
      for (int iR=0;iR<sol.size1();iR++)val[counter++] = sol(iR,0);
      data[num] = val;
    }
  }

  PView *pv = new PView (name, "ElementNodeData", _gm, data, 0.0, 1);
  pv->getData()->writeMSH(name+".msh", false); 
  delete pv;
  */
}


#include "LuaBindings.h"
void dgDofContainer::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgDofContainer>("dgDofContainer");
  cb->setDescription("The DofContainer class provides a vector containing the degree of freedoms");
  methodBinding *cm;
  cm = cb->setConstructor<dgDofContainer,dgGroupCollection*,int>();
  cm->setDescription("Build a vector");
  cm->setArgNames("GroupCollection","nbFields",NULL);
  cm = cb->addMethod("L2Projection",&dgDofContainer::L2Projection);
  cm->setDescription("Project a function onto this vector");
  cm->setArgNames("functionName",NULL);
  cm = cb->addMethod("exportMsh",&dgDofContainer::exportMsh);
  cm->setDescription("Export the dof for gmsh visualization");
  cm->setArgNames("filename", NULL);
  cm = cb->addMethod("exportGroupIdMsh",&dgDofContainer::exportGroupIdMsh);
  cm->setDescription("Export the group ids for gmsh visualization");
  cm = cb->addMethod("exportMultirateGroupMsh",&dgDofContainer::exportMultirateGroupMsh);
  cm->setDescription("Export the group Multirate properties for gmsh visualization");
  cm = cb->addMethod("norm",(double (dgDofContainer::*)())&dgDofContainer::norm);
  cm->setDescription("Returns the norm of the vector");
  cm = cb->addMethod("scale",(void (dgDofContainer::*)(double))&dgDofContainer::scale);
  cm->setArgNames("factor",NULL);
  cm->setDescription("this=this*scale");
  cm = cb->addMethod("setAll",(void (dgDofContainer::*)(double))&dgDofContainer::setAll);
  cm->setArgNames("value",NULL);
  cm->setDescription("set same value to all DOFs");
  cm = cb->addMethod("axpy",(void (dgDofContainer::*)(dgDofContainer &,double)) &dgDofContainer::axpy);
  cm->setArgNames("dofContainer","a",NULL);
  cm->setDescription("this = this+a*dofContainer");
  cm = cb->addMethod("Mesh2Mesh_BuildL2Projection",&dgDofContainer::Mesh2Mesh_BuildL2Projection);
  cm->setDescription("Build L2 projection matrix between donor and this dofContainer.");
  cm->setArgNames("projector","donor",NULL);
  cm = cb->addMethod("Mesh2Mesh_ApplyL2Projection",&dgDofContainer::Mesh2Mesh_ApplyL2Projection);
  cm->setDescription("Apply L2 projection matrix from donor to this dofContainer.");
  cm->setArgNames("projector","donor",NULL);
}
