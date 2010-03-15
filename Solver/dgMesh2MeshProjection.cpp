#include "dgMesh2MeshProjection.h"
#include "MElementOctree.h"
#include "Octree.h"

dgMesh2MeshProjection::dgMesh2MeshProjection()
{
  _projectionMatrixIsBuilt = false;
  _projectionMatrix = new linearSystemCSRGmm<double>;
  _numInDofs = _numOutDofs = _inMaxDim = _outMaxDim = 0;
  _inDofPattern = _outDofPattern = NULL;
  _useDofContainerOctree = true;
  _octree = NULL;
}

dgMesh2MeshProjection::dgMesh2MeshProjection(dgDofContainer* donor, dgDofContainer* receiver)
{
  _projectionMatrixIsBuilt = false;
  _projectionMatrix = new linearSystemCSRGmm<double>;
  _numInDofs = _numOutDofs = 0;
  _inDofPattern = _outDofPattern = NULL;
  _useDofContainerOctree = true;
  _octree = NULL;
  _buildProjectionMatrix(donor,receiver);
}

dgMesh2MeshProjection::dofStoragePattern::dofStoragePattern(dgDofContainer* dofContainer)
{
  _nbGroups = dofContainer->getGroups()->getNbElementGroups();
  _nbFields = dofContainer->getNbFields();
  _nbElems.resize(_nbGroups);
  _nbNodes.resize(_nbGroups);
  _groupFirstProjectionDofId.resize(_nbGroups);

  int offset = 0;
  for (int i = 0; i < _nbGroups; i++) {
    int nbElems = dofContainer->getGroups()->getElementGroup(i)->getNbElements();
    int nbNodes = dofContainer->getGroups()->getElementGroup(i)->getNbNodes();
    _nbElems[i] = nbElems;
    _nbNodes[i] = nbNodes;
    _groupFirstProjectionDofId[i] = offset;
    offset += nbElems*nbNodes;
  }
  _nbProjDofs = offset;
}

bool dgMesh2MeshProjection::dofStoragePattern::operator==(const dgMesh2MeshProjection::dofStoragePattern& other) const
{
  if(this->_nbGroups != other._nbGroups)
    return false;
  for (int i =0; i<this->_nbGroups; i++) {
    if(this->_nbElems[i] != other._nbElems[i])
      return false;
    if(this->_nbNodes[i] != other._nbNodes[i])
      return false;
  }
  return true;
}

bool dgMesh2MeshProjection::_checkTranspose(dgDofContainer* donor, dgDofContainer* receiver)
{
  // check if transpose is necessary
  dofStoragePattern* dDofPattern = new dofStoragePattern(donor);
  dofStoragePattern* rDofPattern = new dofStoragePattern(receiver);
  bool transpose;
  if (*dDofPattern == *_inDofPattern && *rDofPattern == *_outDofPattern)
    transpose = false;
  else if (*dDofPattern == *_outDofPattern && *rDofPattern == *_inDofPattern)
    transpose = true;
  else
    Msg::Fatal("the DOF storage patterns do not match the projection matrix.");
  return transpose;
}

void dgMesh2MeshProjection::projectFromTo(dgDofContainer* donor, dgDofContainer* receiver)
{
  if(!_projectionMatrixIsBuilt)
    _buildProjectionMatrix(donor,receiver);
  _applyProjection(donor,receiver,_checkTranspose(donor,receiver),0);
}

void dgMesh2MeshProjection::copyFromTo(dgDofContainer* donor, dgDofContainer* receiver)
{
  if(!_projectionMatrixIsBuilt)
    _buildProjectionMatrix(donor,receiver);
  _applyProjection(donor,receiver,_checkTranspose(donor,receiver),1);
}


void dgMesh2MeshProjection::_buildReceiverOctree(dgDofContainer* receiver)
{
  std::vector<MElement*> allElements;
  for (int i = 0; i < receiver->getGroups()->getNbElementGroups(); i++ ) {
    dgGroupOfElements* group = receiver->getGroups()->getElementGroup(i);
    for (int iElem = 0; iElem < group->getNbElements(); iElem++ ) {
      allElements.push_back(group->getElement(iElem));
    }
  }
  _octree = buildMElementOctree(allElements);
}

MElement* dgMesh2MeshProjection::_getReceiverElementByCoord(SPoint3 point)
{
  if (!_octree)
    Msg::Fatal("MElement Octree is not built");
  double P[3] = {point.x(), point.y(), point.z()};
  return (MElement*)Octree_Search(P, _octree);
}

void dgMesh2MeshProjection::_buildProjectionMatrix(dgDofContainer* donor, dgDofContainer* receiver)
{
  _inDofPattern = new dofStoragePattern(donor);
  _outDofPattern = new dofStoragePattern(receiver);
  _inMaxDim = donor->getGroups()->getElementGroup(0)->getDimUVW(); // not necessary max...
  _outMaxDim = receiver->getGroups()->getElementGroup(0)->getDimUVW();
  dgGroupCollection* dGroups = donor->getGroups();
  dgGroupCollection* rGroups = receiver->getGroups();
  if (_outMaxDim == 2, receiver->getGroups()->getModel()->getDim() == 3) {
    // need to find 2D elements in 3D geometry, build special octree
    _useDofContainerOctree = false;
    _buildReceiverOctree(receiver);
  }
  if (_outMaxDim > _inMaxDim)
    Msg::Fatal("Cannot build projection matrix from lower dim to higher dim. Swap donor and receiver.");
  
  int jProj = 0; // indices in projection matrix
  int totalNbOutDofs = 0;
  for (int i = 0; i<rGroups->getNbElementGroups(); i++)
    totalNbOutDofs += rGroups->getElementGroup(i)->getNbElements()*rGroups->getElementGroup(i)->getNbNodes();
  _projectionMatrix->allocate(totalNbOutDofs);
  
  // integration over donor function space
  for (int jGroup=0;jGroup<dGroups->getNbElementGroups();jGroup++) {// for donor groups
    const dgGroupOfElements &dGroup = *dGroups->getElementGroup(jGroup); 
    fullMatrix<double> iPtsMatrix = dGroup.getIntegrationPointsMatrix();
    for (int jElement=0 ; jElement<dGroup.getNbElements() ;++jElement) {// for elements
      double rShapeFun[256];
      double dShapeFun[256];
      GModel *rModel = rGroups->getModel();
      GModel *dModel = dGroups->getModel();
      MElement* dElem = dGroup.getElement(jElement);
      for (int iPt =0; iPt< iPtsMatrix.size1(); iPt++) {
        double x=0,y=0,z=0;
        dElem->getFunctionSpace()->f(iPtsMatrix(iPt,0),iPtsMatrix(iPt,1),iPtsMatrix(iPt,2),dShapeFun);      
        for (int iVer=0; iVer < dElem->getNumVertices(); iVer++) {
          x += dElem->getVertex(iVer)->x()*dShapeFun[iVer];
          y += dElem->getVertex(iVer)->y()*dShapeFun[iVer];
          z += dElem->getVertex(iVer)->z()*dShapeFun[iVer];
        }
        if (_inMaxDim==3 && _outMaxDim == 2) {
          z = 0; // dummy projection to 2d mesh
        }
        // find p in receiver mesh
        SPoint3 p(x,y,z);
        MElement *rElem;
        if (_useDofContainerOctree)
          rElem = rGroups->getModel()->getMeshElementByCoord(p);
        else
          rElem = _getReceiverElementByCoord(p);
          
        int iGroup,iElement;
        rGroups->find(rElem,iGroup,iElement);
        if (iElement == -1)
          Msg::Fatal("Integration point (%g,%g,%g) not found in receiver mesh",p.x(),p.y(),p.z()); 
        const dgGroupOfElements &rGroup = *rGroups->getElementGroup(iGroup);      
        double U[3],X[3]={x,y,z};
        rElem->xyz2uvw(X,U);
        dGroup.getFunctionSpace().f(iPtsMatrix(iPt,0),iPtsMatrix(iPt,1),iPtsMatrix(iPt,2),dShapeFun);
        rGroup.getFunctionSpace().f(U[0],U[1],U[2],rShapeFun);
        const double detJ = dGroup.getDetJ (jElement, iPt);
        int iProj = _outDofPattern->getProjDofId(iGroup,iElement,0);
        for (int jNode=0;jNode<dGroup.getNbNodes();jNode++){
          for (int iNode=0;iNode<rGroup.getNbNodes();iNode++){
            double val = rShapeFun[iNode]*dShapeFun[jNode]*iPtsMatrix(iPt,3)*detJ;
            _projectionMatrix->addToMatrix(iProj+iNode,jProj+jNode,val);
          }
        }
      }
      jProj += dGroup.getNbNodes();
    }
  }
  _multiplyByInverseMassMatrix(receiver);
  _projectionMatrixIsBuilt = true;
}

// could be improved by using a better matrix representation and an efficient M*P routine
void dgMesh2MeshProjection::_multiplyByInverseMassMatrix(dgDofContainer* donor)
{
  dgGroupCollection* rGroups = donor->getGroups();
  int *startIndex;
  int *columns;
  double *values;
  _projectionMatrix->getMatrix(startIndex,columns,values);

  int iProj = 0;
  for (int iGroup=0;iGroup<rGroups->getNbElementGroups();iGroup++) {
    const dgGroupOfElements &rGroup = *rGroups->getElementGroup(iGroup);
    for (int iElement=0 ; iElement<rGroup.getNbElements() ;++iElement) {
      fullMatrix<double> buffer = fullMatrix<double> (rGroup.getNbNodes(),startIndex[iProj+1]-startIndex[iProj]);
      fullMatrix<double> buffer2 = fullMatrix<double> (rGroup.getNbNodes(),startIndex[iProj+1]-startIndex[iProj]);
      fullMatrix<double> iMassEl;
      for (int iNode = 0 ; iNode<rGroup.getNbNodes() ;++iNode) {
        for (int i = startIndex[iProj+iNode]; i < startIndex[iProj+iNode+1] ; i++)
          buffer(iNode,i-startIndex[iProj+iNode]) = values[i];
      }
      iMassEl.setAsProxy(rGroup.getInverseMassMatrix(),iElement*rGroup.getNbNodes(),rGroup.getNbNodes());
      buffer2.gemm(iMassEl,buffer);
      for (int iNode = 0 ; iNode<rGroup.getNbNodes() ;++iNode) {
        for (int i = startIndex[iProj+iNode]; i < startIndex[iProj+iNode+1] ; i++)
          values[i] = buffer2(iNode,i-startIndex[iProj+iNode]);
      }
      iProj+=rGroup.getNbNodes();
    }
  }
}

// could be improved by using a better matrix representation and an efficient M*V routine
void dgMesh2MeshProjection::_applyProjection(dgDofContainer* donor, dgDofContainer* receiver, bool transpose, bool copy)
{
  dgDofContainer* dDof = donor;
  dgDofContainer* rDof = receiver;
  if (transpose) {
    rDof = donor;
    dDof = receiver;
  }
  receiver->setAll(0);

  dgGroupCollection* dGroups = dDof->getGroups();
  dgGroupCollection* rGroups = rDof->getGroups();
  std::vector<int> dGroupsStartIGlobal(dGroups->getNbElementGroups() + 1);
  int iProj = 0; // indices in projection matrix
  dGroupsStartIGlobal[0] = 0;
  for (int i = 1; i<dGroupsStartIGlobal.size(); i++)
    dGroupsStartIGlobal[i] = dGroupsStartIGlobal[i-1] + dGroups->getElementGroup(i-1)->getNbElements()*dGroups->getElementGroup(i-1)->getNbNodes();

  int *startIndex;
  int *columns;
  double *values;
  _projectionMatrix->getMatrix(startIndex,columns,values);

  int nbFields = receiver->getNbFields();
  if (nbFields != donor->getNbFields())
    Msg::Fatal("Number of fields in donor and receiver dofContainer must match (for now)");
  // full dofContainer data
//   fullVector<double>& rVector = receiver->getVector();
//   fullVector<double>& dVector = donor->getVector();
  
  for (int iGroup=0;iGroup<rGroups->getNbElementGroups();iGroup++) {
    const dgGroupOfElements &rGroup = *rGroups->getElementGroup(iGroup);
    for (int iElement=0 ; iElement<rGroup.getNbElements() ;++iElement) {
      for (int iNode = 0 ; iNode<rGroup.getNbNodes() ;++iNode) {
        int jGroup = 0;
        for (int i = startIndex[iProj++]; i < startIndex[iProj] ; i++){
          int jProj = columns[i];
          while (jProj > dGroupsStartIGlobal[jGroup+1]) {
            jGroup++;
          }
          int jElement = (jProj-dGroupsStartIGlobal[jGroup])/dGroups->getElementGroup(jGroup)->getNbNodes();
          int jNode = jProj-dGroupsStartIGlobal[jGroup]-jElement*dGroups->getElementGroup(jGroup)->getNbNodes();
          for (int m = 0; m < nbFields; m++){
            double val = values[i];
            if (copy) val = (fabs(values[i]) > 1e-8) ? 1 : 0;
            if (transpose)
              receiver->getGroupProxy(jGroup)(jNode,jElement*nbFields+m) += val*donor->getGroupProxy(iGroup)(iNode,iElement*nbFields+m);
//               rVector(jProj) += val*donor->getGroupProxy(iGroup)(iNode,iElement*nbFields+m); // only for one field
            else
              receiver->getGroupProxy(iGroup)(iNode,iElement*nbFields+m) += val*donor->getGroupProxy(jGroup)(jNode,jElement*nbFields+m);
//               receiver->getGroupProxy(iGroup)(iNode,iElement*nbFields+m) += val*dVector(jProj); // only for one field
          }
        }
      }
    }
  }
}

#include "LuaBindings.h"
void dgMesh2MeshProjection::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgMesh2MeshProjection>("dgMesh2MeshProjection");
  cb->setDescription("The dgMesh2MeshProjection class provides methods for projecting fields from one mesh on another.");
  methodBinding *cm;
  cm = cb->setConstructor<dgMesh2MeshProjection,dgDofContainer*,dgDofContainer*>();
  cm->setDescription("Build a projection instance between two dgDofContainers. Integration is performend in the donor Dof function space.");
  cm->setArgNames("donorDof","receiverDof",NULL);
  cm = cb->addMethod("projectFromTo",&dgMesh2MeshProjection::projectFromTo);
  cm->setDescription("Projects all the fields in one container to the other");
  cm->setArgNames("fromContainer","toContainer",NULL);
  cm = cb->addMethod("copyFromTo",&dgMesh2MeshProjection::copyFromTo);
  cm->setDescription("Copies all the fields on one container to the other (projection with binary projection matrix)");
  cm->setArgNames("fromContainer","toContainer",NULL);
}
