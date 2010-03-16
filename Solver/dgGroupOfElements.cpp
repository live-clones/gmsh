#include <algorithm>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "dgGroupOfElements.h"
#include "dgConservationLaw.h"
#include "dgDofContainer.h"
#include "dgAlgorithm.h"
#include "MElement.h"
#include "polynomialBasis.h"
#include "Numeric.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "MPoint.h"
#include "GModel.h"
#ifdef HAVE_MPI
#include "mpi.h"
#else
#include <string.h>
#endif
//#define TEST


static fullMatrix<double> * dgGetIntegrationRule (MElement *e, int p){
  int npts;
  IntPt *pts;
  e->getIntegrationPoints(2*p+1, &npts, &pts);
  fullMatrix<double> *m = new fullMatrix<double> (npts, 4);
  for (int i=0;i<npts;i++){
    (*m)(i,0) = pts[i].pt[0];
    (*m)(i,1) = pts[i].pt[1];
    (*m)(i,2) = pts[i].pt[2];
    (*m)(i,3) = pts[i].weight;
  }
  return m;
}

static fullMatrix<double> dgGetFaceIntegrationRuleOnElement (
      const polynomialBasis *fsFace,
      const fullMatrix<double> &intgFace,
      const polynomialBasis *fsElement,
      const std::vector <int> &closure) {
  int npts=intgFace.size1();
  fullMatrix<double> intgElement(npts, 4);
  double f[256];
  for (int i=0;i<npts;i++){
    fsFace->f(intgFace(i,0),intgFace(i,1),intgFace(i,2),f);
    for(size_t j=0; j<closure.size();j++){
      int jNod=closure[j];
      for(int k=0;k<fsElement->points.size2();k++)
        intgElement(i,k) += f[j] * fsElement->points(jNod,k);
      intgElement(i,3) = intgFace(i,3);
    }
  }
  return intgElement;
}

dgGroupOfElements::dgGroupOfElements(const std::vector<MElement*> &e, 
				     int polyOrder,
				     int ghostPartition)
  : _elements(e), 
   _fs(*_elements[0]->getFunctionSpace(polyOrder)),
   _integration(dgGetIntegrationRule (_elements[0], polyOrder)),
   _ghostPartition(ghostPartition)
{
  _order=polyOrder;
  _dimUVW = _dimXYZ = e[0]->getDim();
  // this is the biggest piece of data ... the mappings
  int nbNodes = _fs.coefficients.size1();
  int nbQP = _integration->size1();
  _redistributionFluxes[0] = new fullMatrix<double> (nbNodes, nbQP);
  _redistributionFluxes[1] = new fullMatrix<double> (nbNodes, nbQP);
  _redistributionFluxes[2] = new fullMatrix<double> (nbNodes, nbQP);
  _redistributionSource = new fullMatrix<double> (nbNodes, nbQP);
  _collocation = new fullMatrix<double> (nbQP, nbNodes);
  _mapping = new fullMatrix<double> (e.size(), 10 * nbQP);
  _imass = new fullMatrix<double> (nbNodes,nbNodes*e.size()); 
  _dPsiDx = new fullMatrix<double> ( nbQP*3,nbNodes*e.size());
  _elementVolume = new fullMatrix<double> (e.size(),1);
  _innerRadii = new fullMatrix<double> (e.size(),1);
  double g[256][3],f[256];
  
  for (int i=0;i<_elements.size();i++){
    MElement *e = _elements[i];
    element_to_index[e] = i;
    fullMatrix<double> imass(*_imass,nbNodes*i,nbNodes);
    (*_innerRadii)(i,0)=e->getInnerRadius();
    for (int j=0;j< _integration->size1() ; j++ ){
      _fs.f((*_integration)(j,0), (*_integration)(j,1), (*_integration)(j,2), f);
      _fs.df((*_integration)(j,0), (*_integration)(j,1), (*_integration)(j,2), g);
      double jac[3][3],ijac[3][3],detjac;
      (*_mapping)(i,10*j + 9) =  
        e->getJacobian ((*_integration)(j,0), (*_integration)(j,1), (*_integration)(j,2), jac);
      (*_elementVolume)(i,0) += (*_mapping)(i,10*j+9)*(*_integration)(j,3);
      const double weight = (*_integration)(j,3);
      detjac=inv3x3(jac,ijac);
      (*_mapping)(i,10*j + 0) = ijac[0][0];
      (*_mapping)(i,10*j + 1) = ijac[0][1];
      (*_mapping)(i,10*j + 2) = ijac[0][2];
      (*_mapping)(i,10*j + 3) = ijac[1][0];
      (*_mapping)(i,10*j + 4) = ijac[1][1];
      (*_mapping)(i,10*j + 5) = ijac[1][2];
      (*_mapping)(i,10*j + 6) = ijac[2][0];
      (*_mapping)(i,10*j + 7) = ijac[2][1];
      (*_mapping)(i,10*j + 8) = ijac[2][2];
      for (int k=0;k<nbNodes;k++){ 
        for (int l=0;l<nbNodes;l++) { 
          imass(k,l) += f[k]*f[l]*weight*detjac;
        }
        // (iQP*3+iXYZ , iFace*NPsi+iPsi)
        (*_dPsiDx)(j*3  ,i*nbNodes+k) = g[k][0]*ijac[0][0]+g[k][1]*ijac[0][1]+g[k][2]*ijac[0][2];
        (*_dPsiDx)(j*3+1,i*nbNodes+k) = g[k][0]*ijac[1][0]+g[k][1]*ijac[1][1]+g[k][2]*ijac[1][2];
        (*_dPsiDx)(j*3+2,i*nbNodes+k) = g[k][0]*ijac[2][0]+g[k][1]*ijac[2][1]+g[k][2]*ijac[2][2];
      }
    }
    imass.invertInPlace();
  }
  // redistribution matrix
  // quadrature weight x parametric gradients in quadrature points
  // redistribition Jacobian Matrix : quadrature weight x parametric gradients x shapefunctions

  _PsiDPsiDXi = fullMatrix<double> (_dimUVW*nbQP, nbNodes*nbNodes);
  //reditribution of the diffusive jacobian dimUVW*dimUVW*nbIntegrationPoints x nbNodes*nbNodes
  _dPsiDXDPsiDXi = fullMatrix<double> (_dimUVW*_dimUVW*nbQP, nbNodes*nbNodes);

  for (int xi=0;xi<nbQP; xi++) {
    _fs.df((*_integration)(xi,0),
	   (*_integration)(xi,1),
	   (*_integration)(xi,2), g);
    _fs.f((*_integration)(xi,0),
	   (*_integration)(xi,1),
	   (*_integration)(xi,2), f);
    const double weight = (*_integration)(xi,3);
    for (int k=0;k<nbNodes; k++){ 
      (*_redistributionFluxes[0])(k,xi) = g[k][0] * weight;
      (*_redistributionFluxes[1])(k,xi) = g[k][1] * weight;
      (*_redistributionFluxes[2])(k,xi) = g[k][2] * weight;
      (*_redistributionSource)(k,xi) = f[k] * weight;
      (*_collocation)(xi,k) = f[k];
      //      for (int l=0;l<_fs.coefficients.size1();l++){
      //	(*_redistributionJacobianOfFluxes[0])(l+_fs.coefficients.size1()*k,j) = g[k][0] * f[l] * weight;
      //	(*_redistributionJacobianOfFluxes[0])(l+_fs.coefficients.size1()*k,j) = g[k][1] * f[l] * weight;
      //	(*_redistributionJacobianOfFluxes[0])(l+_fs.coefficients.size1()*k,j) = g[k][2] * f[l] * weight;
      //      } 
    }
    for (int alpha=0; alpha<_dimUVW; alpha++) for (int beta=0; beta<_dimUVW; beta++) {
      for (int i=0; i<nbNodes; i++) for (int j=0; j<nbNodes; j++) {
        _dPsiDXDPsiDXi((alpha*_dimUVW+beta)*nbQP+xi, i*nbNodes+j) = g[i][alpha]*g[j][beta]*weight;
      }
    }
    for (int alpha=0; alpha<_dimUVW; alpha++){
      for (int i=0; i<nbNodes; i++) for (int j=0; j<nbNodes; j++) {
        _PsiDPsiDXi(alpha*nbQP+xi, i*nbNodes+j) = g[i][alpha]*f[j]*weight;
      }
    }
  }
}

void dgGroupOfElements::copyPrivateDataFrom(const dgGroupOfElements *from){
  _multirateExponent=from->getMultirateExponent();
  _multirateInnerBuffer=from->getIsInnerMultirateBuffer();
  _multirateOuterBuffer=from->getIsOuterMultirateBuffer();
}

dgGroupOfElements::~dgGroupOfElements(){
  delete _integration;
  //  delete _redistributionJacobianOfFluxes[0];
  //  delete _redistributionJacobianOfFluxes[1];
  //  delete _redistributionJacobianOfFluxes[2];
  delete _redistributionFluxes[0];
  delete _redistributionFluxes[1];
  delete _redistributionFluxes[2];
  delete _redistributionSource;
  delete _dPsiDx;
  delete _mapping;
  delete _collocation;
  delete _imass;
  delete _elementVolume;
}


dgGroupOfFaces::~dgGroupOfFaces()
{
  if (!_faces.size())return;
  delete _redistribution;
  delete _collocation;
  delete _detJac;
  delete _interfaceSurface;
}


dgGroupOfConnections::dgGroupOfConnections(const dgGroupOfElements &elementGroup, const dgGroupOfFaces &faceGroup, int pOrder) :
  _elementGroup(elementGroup),
  _faceGroup(faceGroup)
{
  _fs = _elementGroup.getElement(0)->getFunctionSpace(pOrder);
}

void dgGroupOfFaces::mapToInterface ( int nFields,
    const fullMatrix<double> &vLeft,
    const fullMatrix<double> &vRight,
    fullMatrix<double> &v)
{
  if(_connections.size()==1){
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureLeft = _connections[0]->getClosure(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++){
          v(j, i*nFields + iField) = vLeft(closureLeft[j], _connections[0]->getElementId(i)*nFields + iField);
        }
      }
    }
    
  }else{
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureLeft = _connections[0]->getClosure(i);
      const std::vector<int> &closureRight = _connections[1]->getClosure(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++){
          v(j, i*2*nFields + iField) = vLeft(closureLeft[j],_connections[0]->getElementId(i)*nFields + iField);
        }
        for(size_t j =0; j < closureRight.size(); j++)
          v(j, (i*2+1)*nFields + iField) = vRight(closureRight[j],_connections[1]->getElementId(i)*nFields + iField);
      }
    }
  }
}

void dgGroupOfFaces::mapFromInterface ( int nFields,
    const fullMatrix<double> &v,
    fullMatrix<double> &vLeft,
    fullMatrix<double> &vRight
    )
{
  if(_connections.size()==1){
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureLeft = _connections[0]->getClosure(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++)
          vLeft(closureLeft[j], _connections[0]->getElementId(i)*nFields + iField) += v(j, i*nFields + iField);
      }
    }
  }else{
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureLeft = _connections[0]->getClosure(i);
      const std::vector<int> &closureRight = _connections[1]->getClosure(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++)
          vLeft(closureLeft[j], _connections[0]->getElementId(i)*nFields + iField) += v(j, i*2*nFields + iField);
        for(size_t j =0; j < closureRight.size(); j++)
	  vRight(closureRight[j], _connections[1]->getElementId(i)*nFields + iField) += v(j, (i*2+1)*nFields + iField);
      }
    }
  }
}

void dgGroupOfFaces::mapLeftFromInterface ( int nFields,
    const fullMatrix<double> &v,
    fullMatrix<double> &vLeft
    )
{
  for(int i=0; i<getNbElements(); i++) {
    const std::vector<int> &closureLeft = _connections[0]->getClosure(i);
    for (int iField=0; iField<nFields; iField++){
      for(size_t j =0; j < closureLeft.size(); j++)
        vLeft(closureLeft[j], _connections[0]->getElementId(i)*nFields + iField) += v(j, i*2*nFields + iField);
    }
  }
}
void dgGroupOfFaces::mapRightFromInterface ( int nFields,
    const fullMatrix<double> &v,
    fullMatrix<double> &vRight
    )
{
  if(_connections.size()==1)
    return;
  for(int i=0; i<getNbElements(); i++) {
    const std::vector<int> &closureRight = _connections[1]->getClosure(i);
    for (int iField=0; iField<nFields; iField++){
      for(size_t j =0; j < closureRight.size(); j++)
        vRight(closureRight[j], _connections[1]->getElementId(i)*nFields + iField) += v(j, (i*2+1)*nFields + iField);
    }
  }
}

void dgGroupOfConnections::init() {
  _closures = _fs->closures;
  for (size_t i=0; i<_closures.size(); i++)
    _integrationPoints.push_back(dgGetFaceIntegrationRuleOnElement(
      _faceGroup.getPolynomialBasis(), _faceGroup.getIntegrationPointsMatrix(),
      _fs,_closures[i]));

  int nPsi = _fs->points.size1();
  int nQP = _integrationPoints[0].size1();
  int size = _elementId.size();
  // compute data on quadrature points : normals and dPsidX
  double g[256][3];
  _normals = fullMatrix<double> (3, nQP*size);
  _dPsiDx = fullMatrix<double> ( nQP*3, nPsi*size);
  int index = 0;
  for (size_t i=0; i<size;i++){
    const std::vector<int> &closure = getClosure(i);
    const fullMatrix<double> &integration = getIntegrationPointsOnElement(i);
    double jac[3][3],ijac[3][3];
    for (int j=0; j<integration.size1(); j++){
      _fs->df(integration(j,0), integration(j,1), integration(j,2),g);
      getElement(i)->getJacobian (integration(j,0), integration(j,1), integration(j,2), jac);
      inv3x3(jac,ijac);
      //compute dPsiDxOnQP
      // (iQP*3+iXYZ , iFace*NPsi+iPsi)
      for (int iPsi=0; iPsi< nPsi; iPsi++) {
        _dPsiDx(j*3  ,i*nPsi+iPsi) = g[iPsi][0]*ijac[0][0]+g[iPsi][1]*ijac[0][1]+g[iPsi][2]*ijac[0][2];
        _dPsiDx(j*3+1,i*nPsi+iPsi) = g[iPsi][0]*ijac[1][0]+g[iPsi][1]*ijac[1][1]+g[iPsi][2]*ijac[1][2];
        _dPsiDx(j*3+2,i*nPsi+iPsi) = g[iPsi][0]*ijac[2][0]+g[iPsi][1]*ijac[2][1]+g[iPsi][2]*ijac[2][2];
      }
      //compute face normals
      double &nx=_normals(0,index);
      double &ny=_normals(1,index);
      double &nz=_normals(2,index);
      double nu=0,nv=0,nw=0;
      for (size_t k=0; k<closure.size(); k++){
        int inode=closure[k];
        nu += g[inode][0];
        nv += g[inode][1];
        nw += g[inode][2];
      }
      nx = nu*ijac[0][0]+nv*ijac[0][1]+nw*ijac[0][2];
      ny = nu*ijac[1][0]+nv*ijac[1][1]+nw*ijac[1][2];
      nz = nu*ijac[2][0]+nv*ijac[2][1]+nw*ijac[2][2];
      double norm = sqrt(nx*nx+ny*ny+nz*nz);
      nx/=norm;
      ny/=norm;
      nz/=norm;
      index++;
    }
  }
}

// this function creates groups of elements
// First, groups of faces are created on every physical group
// of dimension equal to the dimension of the problem minus one
// Then, groups of elements are created 
//  -) Elements of different types are separated
//  -) Then those groups are split into partitions
 
void dgGroupCollection::buildGroupsOfElements(GModel *model, int dim, int order, std::vector<std::string>* physicalTags)
{
  if(_groupsOfElementsBuilt)
    return;
  _groupsOfElementsBuilt=true;
  _model = model;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::map<int, std::vector<MElement *> >localElements;
  std::vector<std::map<int, std::vector<MElement *> > >ghostElements(Msg::GetCommSize()); // [partition][elementType]
  std::multimap<MElement*, short> &ghostsCells = _model->getGhostCells();
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    bool correctPhysicalTag = false;
    if(physicalTags==NULL || physicalTags->size()==0)
      correctPhysicalTag = true;
    else
      for(unsigned int iPhy = 0; iPhy < entity->physicals.size(); iPhy++)
        for(unsigned int jPhy = 0; jPhy < physicalTags->size(); jPhy++)
          if (_model->getPhysicalName(dim,entity->physicals[iPhy]) == physicalTags->at(jPhy) )
            correctPhysicalTag = true;

    if(entity->dim() == dim && correctPhysicalTag){
      for (int iel=0; iel<entity->getNumMeshElements(); iel++){
        MElement *el=entity->getMeshElement(iel);
        if(el->getPartition()==Msg::GetCommRank()+1 || el->getPartition()==0){
          localElements[el->getType()].push_back(el);
        } else {
          std::multimap<MElement*, short>::iterator ghost=ghostsCells.lower_bound(el);
          while(ghost!= ghostsCells.end() && ghost->first==el){
            if(abs(ghost->second)-1==Msg::GetCommRank()){
              ghostElements[el->getPartition()-1][el->getType()].push_back(el);
            }
            ghost++;
          }
        }
      }
    }
  }
	
  // do a group of elements for every element type in the mesh
  int id=_elementGroups.size();
  for (std::map<int, std::vector<MElement *> >::iterator it = localElements.begin(); it !=localElements.end() ; ++it){
    dgGroupOfElements *newGroup=new dgGroupOfElements(it->second,order);
    _elementGroups.push_back(newGroup);
    id++;
  }

  //create ghost groups
  for(int i=0;i<Msg::GetCommSize();i++){
    for (std::map<int, std::vector<MElement *> >::iterator it = ghostElements[i].begin(); it !=ghostElements[i].end() ; ++it){
      dgGroupOfElements *gof=new dgGroupOfElements(it->second,order,i);
      if (gof->getNbElements())
        _ghostGroups.push_back(gof);
      else
        delete gof;
    }
  }
}

class dgMiniConnection 
{
  public:
  int iGroup, iElement, iClosure;
  dgMiniConnection (int iGroup_, int iElement_, int iClosure_)
  {
    iGroup = iGroup_;
    iElement = iElement_;
    iClosure = iClosure_;
  }
  bool operator < (const dgMiniConnection b) const 
  {
    if (iGroup < b.iGroup) return true;
    if (iGroup > b.iGroup) return false;
    if (iElement < b.iElement) return true;
    if (iElement > b.iElement) return false;
    if (iClosure < b.iClosure) return true;
    return false;
  }
};

class dgMiniInterface 
{
  public:
  int physicalTag;
  int numVertices;
  std::vector<dgMiniConnection> connections;
  dgMiniInterface()
  {
    physicalTag = -1;
  }
  bool isFullGhost(dgGroupCollection &groups)
  {
    bool fullGhost = true;
    for (size_t i = 0; i<connections.size(); i++) {
      fullGhost &= (connections[i].iGroup >= groups.getNbElementGroups());
    }
    return fullGhost;
  }
};

static std::vector<dgMiniInterface> *_createMiniInterfaces(dgGroupCollection &groups) 
{
  std::vector<GEntity*> entities;
  groups.getModel()->getEntities(entities);
  std::map<MVertex*, dgMiniInterface> vertexInterfaces;
  std::map<MEdge, dgMiniInterface, Less_Edge> edgeInterfaces;
  std::map<MFace, dgMiniInterface, Less_Face> faceInterfaces;
  int dim = groups.getElementGroup(0)->getElement(0)->getDim();
  // 1) get tag of existing interfaces
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    if(entity->dim() == dim-1){
      for(unsigned int j = 0; j < entity->physicals.size(); j++){
        int physicalTag = entity->physicals[j];
        for (int k = 0; k < entity->getNumMeshElements(); k++) {
          MElement *element = entity->getMeshElement(k);
          switch(dim) {
            case 1: vertexInterfaces[element->getVertex(0)].physicalTag = physicalTag; break;
            case 2: edgeInterfaces[element->getEdge(0)].physicalTag = physicalTag; break;
            case 3: faceInterfaces[element->getFace(0)].physicalTag = physicalTag; break;
            default : throw;
          }
        }
      }
    }
  }
  // 2) build new interfaces
  int iClosure;
  for (size_t iGroup = 0; iGroup < groups.getNbElementGroups()+groups.getNbGhostGroups(); iGroup++) {
    dgGroupOfElements &group = *groups.getElementGroup(iGroup);
    for (size_t iElement = 0; iElement < group.getNbElements(); iElement++) {
      MElement &element = *group.getElement(iElement);
      switch(dim) {
        case 1: 
          for (int iVertex = 0; iVertex < element.getNumVertices(); iVertex++) {
            iClosure = element.getFunctionSpace()->getClosureId(iVertex);
            vertexInterfaces[element.getVertex(iVertex)].connections.push_back(dgMiniConnection(iGroup,iElement,iClosure));
          }
          break;
        case 2:
          for (int iEdge = 0; iEdge < element.getNumEdges(); iEdge++) {
            std::map<MEdge,dgMiniInterface>::iterator it =
              edgeInterfaces.insert(std::pair<MEdge,dgMiniInterface>(element.getEdge(iEdge),dgMiniInterface())).first;
            int iEdge_, sign;
            element.getEdgeInfo(it->first, iEdge_, sign);
            iClosure = element.getFunctionSpace()->getClosureId(iEdge,sign);
            it->second.connections.push_back(dgMiniConnection(iGroup,iElement,iClosure));
          }
          break;
        case 3:
          for (int iFace = 0; iFace < element.getNumFaces(); iFace++) {
            std::map<MFace,dgMiniInterface>::iterator it =
             faceInterfaces.insert(std::pair<MFace,dgMiniInterface>(element.getFace(iFace),dgMiniInterface())).first;
            int iFace_, sign, rotation;
            element.getFaceInfo(it->first, iFace_, sign, rotation);
            iClosure = element.getFunctionSpace ()->getClosureId (iFace, sign, rotation);
            it->second.connections.push_back(dgMiniConnection(iGroup,iElement,iClosure));
          }
          break;
        default : throw;
      }
    }
  }
  std::vector<dgMiniInterface> *interfaces = new std::vector<dgMiniInterface>;
  switch(dim) {
    case 1: 
      interfaces->reserve(vertexInterfaces.size());
      for(std::map<MVertex*, dgMiniInterface>::iterator it = vertexInterfaces.begin(); it != vertexInterfaces.end(); it++) {
        it->second.numVertices = 1;
        interfaces->push_back(it->second);
      }
      break;
    case 2: 
      interfaces->reserve(edgeInterfaces.size());
      for(std::map<MEdge, dgMiniInterface, Less_Edge>::iterator it = edgeInterfaces.begin(); it != edgeInterfaces.end(); it++) {
        it->second.numVertices = it->first.getNumVertices();
        interfaces->push_back(it->second);
      }
      break;
    case 3: 
      interfaces->reserve(faceInterfaces.size());
      for(std::map<MFace, dgMiniInterface,Less_Face>::iterator it = faceInterfaces.begin(); it != faceInterfaces.end(); it++) {
        it->second.numVertices = it->first.getNumVertices();
        interfaces->push_back(it->second);
      }
      break;
  }
  for (size_t i = 0; i < interfaces->size(); i++) {
    std::sort((*interfaces)[i].connections.begin(), (*interfaces)[i].connections.end());
  }
  return interfaces;
}

class dgGroupKey : public std::binary_function<dgMiniInterface, dgMiniInterface, bool> {
  const dgGroupCollection &_groups;
  public:
  dgGroupKey (const dgGroupCollection &groups) : _groups(groups){};
  bool operator ()(const dgMiniInterface &i1, const dgMiniInterface &i2) const
  {
    // 1 sort by number of connections
    if (i1.connections.size() < i2.connections.size()) return true;
    if (i1.connections.size() > i2.connections.size()) return false;
    // 2 sort by physical tag
    if (i1.physicalTag < i2.physicalTag) return true;
    if (i1.physicalTag > i2.physicalTag) return false;
    // 3 sort by groups of elements
    for (size_t i = 0; i < i1.connections.size(); i++) {
      if (i1.connections[i].iGroup < i2.connections[i].iGroup) return true;
      if (i1.connections[i].iGroup > i2.connections[i].iGroup) return false;
    }
    // 4 sort by number of vertices in the interface
    if (i1.connections.size()>0) {
      const dgMiniConnection &c1 = i1.connections[0];
      const dgMiniConnection &c2 = i2.connections[0];
      int closureSize1 = _groups.getElementGroup(c1.iGroup)->getElement(c1.iElement)->getFunctionSpace()->getClosure(c1.iClosure).size();
      int closureSize2 = _groups.getElementGroup(c2.iGroup)->getElement(c2.iElement)->getFunctionSpace()->getClosure(c2.iClosure).size();
      if (closureSize1 < closureSize2) return true;
      if (closureSize1 > closureSize2) return false;
    }
    return false;
  }
};

void dgGroupCollection::buildGroupsOfInterfaces()
{
  if(_groupsOfInterfacesBuilt)
    Msg::Error("groups of interfaces already built");
  _groupsOfInterfacesBuilt=true;
  int pOrder = _elementGroups[0]->getOrder();
  std::vector<dgMiniInterface> *interfaces = _createMiniInterfaces(*this);
  dgGroupKey sortKey(*this);
  std::sort(interfaces->begin(), interfaces->end(), sortKey);
  std::vector<dgMiniInterface>::iterator groupStart = interfaces->begin(), groupEnd = groupStart;
  do {
    groupEnd++;
    if (groupEnd==interfaces->end() || sortKey(*groupStart, *groupEnd) || sortKey(*groupEnd, *groupStart)) {
      if (!groupStart->isFullGhost(*this)) {
        std::vector<dgMiniInterface> group(groupStart, groupEnd);
        if (groupStart->connections.size() == 1) {
          _boundaryGroups.push_back (new dgGroupOfFaces (*this, group, pOrder) );
        } else {
          _faceGroups.push_back (new dgGroupOfFaces (*this, group, pOrder) );
        }
      }
      groupStart = groupEnd;
    }
  } while (groupEnd != interfaces->end()) ;
  delete interfaces;
  buildParallelStructure();
}

void dgGroupOfConnections::addElement (int iElement, int iClosure) {
  _elementId.push_back(iElement);
  _closuresId.push_back(iClosure);
}

dgGroupOfFaces::dgGroupOfFaces (dgGroupCollection &groups, std::vector<dgMiniInterface> &interfaces, int pOrder)
{
  dgMiniInterface &first = interfaces.front();
  size_t nconnections = first.connections.size();
  int dim = groups.getElementGroup(first.connections[0].iGroup)->getElement(first.connections[0].iElement)->getDim()-1;
  _physicalTag.clear();
  if(first.physicalTag>=0)
    _physicalTag = groups.getModel()->getPhysicalName(dim, first.physicalTag);
  if(nconnections==1 && (_physicalTag.empty() || _physicalTag=="")) {
    /*Msg::Error("boundary face without tag in the mesh");
    throw;*/
    _physicalTag = "none";
  }
  for (size_t i=0; i<nconnections; i++) {
    _connections.push_back (new dgGroupOfConnections(*groups.getElementGroup(first.connections[i].iGroup), *this, pOrder));
  }
  for (size_t i=0; i<interfaces.size(); i++) {
    dgMiniInterface &interface = interfaces[i];
    for (size_t j=0; j<nconnections; j++)
      _connections[j]->addElement(interface.connections[j].iElement, interface.connections[j].iClosure);
    dgMiniConnection &connection = interface.connections[0];
    MElement *el = groups.getElementGroup(connection.iGroup)->getElement(connection.iElement);
    const std::vector<int> & geomClosure = el->getFunctionSpace()->getClosure(connection.iClosure);
    std::vector<MVertex *> vertices;
    for (int j=0; j<geomClosure.size() ; j++)
      vertices.push_back( const_cast<MElement*>(el)->getVertex(geomClosure[j]) );
    switch (el->getDim()) {
      case 1 :
        _faces.push_back (new MPoint (vertices[0]));
        break;
      case 2 :
        switch(vertices.size()) {
          case 2  : _faces.push_back (new MLine (vertices)); break;
          case 3  : _faces.push_back (new MLine3 (vertices)); break;
          default : _faces.push_back (new MLineN (vertices)); break;
        }
        break; 
      case 3 :
        if (interface.numVertices == 3) {
          switch(vertices.size()){
            case 3   : _faces.push_back (new MTriangle (vertices)); break;
            case 6   : _faces.push_back (new MTriangle6 (vertices)); break;
            case 10  : _faces.push_back (new MTriangleN (vertices, 3)); break;
            case 15  : _faces.push_back (new MTriangleN (vertices, 4)); break;
            case 21  : _faces.push_back (new MTriangleN (vertices, 5)); break;
            default : throw;
          }
        } else if (interface.numVertices == 4) {
          switch(vertices.size()){
            case 4  : _faces.push_back (new MQuadrangle (vertices)); break;
            case 8  : _faces.push_back (new MQuadrangle8 (vertices)); break;
            case 9  : _faces.push_back (new MQuadrangle9 (vertices)); break;
            case 16 : _faces.push_back (new MQuadrangleN (vertices, 4)); break;
            case 25 : _faces.push_back (new MQuadrangleN (vertices, 5)); break;
            default : throw;
          }
        } else {
          throw;
        }
        break;
      default :
        throw;
    }
  }
  _fsFace = _faces[0]->getFunctionSpace (pOrder);
  _integration = dgGetIntegrationRule (_faces[0],pOrder);
  _redistribution = new fullMatrix<double> (_fsFace->coefficients.size1(),_integration->size1());
  _collocation = new fullMatrix<double> (_integration->size1(), _fsFace->coefficients.size1());
  _detJac = new fullMatrix<double> (_integration->size1(), _faces.size());
  _interfaceSurface = new fullMatrix<double>(_faces.size(),1);
  for(int i=0; i<_connections.size(); i++) {
    _connections[i]->init();
  }
  double f[256];
  for (int j=0;j<_integration->size1();j++) {
    _fsFace->f((*_integration)(j,0), (*_integration)(j,1), (*_integration)(j,2), f);
    const double weight = (*_integration)(j,3);
    for (int k=0;k<_fsFace->coefficients.size1();k++){ 
      (*_redistribution)(k,j) = f[k] * weight;
      (*_collocation)(j,k) = f[k];
    }
  }
  for (int i=0;i<_faces.size();i++){
    MElement *f = _faces[i];
    for (int j=0;j< _integration->size1() ; j++ ){
      double jac[3][3];
      (*_detJac)(j,i) = f->getJacobian ((*_integration)(j,0), (*_integration)(j,1), (*_integration)(j,2), jac);
      (*_interfaceSurface)(i,0) += (*_integration)(j,3)*(*_detJac)(j,i);
    }
  }
}

void dgGroupCollection::buildParallelStructure()
{
  // build the ghosts structure
  int *nGhostElements = new int[Msg::GetCommSize()];
  int *nParentElements = new int[Msg::GetCommSize()];
  for (int i=0;i<Msg::GetCommSize();i++) {
    nGhostElements[i]=0;
  }
  for (size_t i = 0; i< getNbGhostGroups(); i++){
    dgGroupOfElements *group = getGhostGroup(i);
    nGhostElements[group->getGhostPartition()] += group->getNbElements();
  }
  #ifdef HAVE_MPI
  MPI_Alltoall(nGhostElements,1,MPI_INT,nParentElements,1,MPI_INT,MPI_COMM_WORLD); 
  #else
  nParentElements[0]=nGhostElements[0];
  #endif
  int *shiftSend = new int[Msg::GetCommSize()];
  int *shiftRecv = new int[Msg::GetCommSize()];
  int *curShiftSend = new int[Msg::GetCommSize()];
  int totalSend=0,totalRecv=0;
  for(int i= 0; i<Msg::GetCommSize();i++){
    shiftSend[i] = (i==0 ? 0 : shiftSend[i-1]+nGhostElements[i-1]);
    curShiftSend[i] = shiftSend[i];
    shiftRecv[i] = (i==0 ? 0 : shiftRecv[i-1]+nParentElements[i-1]);
    totalSend += nGhostElements[i];
    totalRecv += nParentElements[i];
  }

  int *idSend = new int[totalSend];
  int *idRecv = new int[totalRecv];
  for (int i = 0; i<getNbGhostGroups(); i++){
    dgGroupOfElements *group = getGhostGroup(i);
    int part = group->getGhostPartition();
    for (int j=0; j< group->getNbElements() ; j++){
      idSend[curShiftSend[part]++] = group->getElement(j)->getNum();
    }
  }
  #ifdef HAVE_MPI
  MPI_Alltoallv(idSend,nGhostElements,shiftSend,MPI_INT,idRecv,nParentElements,shiftRecv,MPI_INT,MPI_COMM_WORLD);
  #else
  memcpy(idRecv,idSend,nParentElements[0]*sizeof(int));
  #endif
  //create a Map elementNum :: group, position in group
  std::map<int, std::pair<int,int> > elementMap;
  for(size_t i = 0; i< getNbElementGroups(); i++) {
    dgGroupOfElements *group = getElementGroup(i);
    for(int j=0; j< group->getNbElements(); j++){
      elementMap[group->getElement(j)->getNum()]=std::pair<int,int>(i,j);
    }
  }
  _elementsToSend.resize(Msg::GetCommSize());
  for(int i = 0; i<Msg::GetCommSize();i++){
    _elementsToSend[i].resize(nParentElements[i]);
    for(int j=0;j<nParentElements[i];j++){
      int num = idRecv[shiftRecv[i]+j];
      _elementsToSend[i][j]=elementMap[num];
    }
  }
  delete []idRecv;
  delete []idSend;
  delete []curShiftSend;
  delete []shiftSend;
  delete []shiftRecv;
}

// Split the groups of elements depending on their local time step
double dgGroupCollection::splitGroupsForMultirate(int maxLevels,int innerBufferSize,int outerBufferSize,dgConservationLaw *claw, dgDofContainer *solution) {
  // What are the levels/layers:
  // bulk: elements that are time stepped using the "normal" 4 stage Runge-Kutta
  // innerBuffer: elements that use the small time step but talks to elements using the big time step
  // outerBuffer: elements that use the big time step but talks to elements using the small time step


  Msg::Info("Splitting Groups for multirate time stepping");
  maxLevels--;// Number becomes maximum id

  // Interfaces are not built yet, so we use a "mini" structure to deduce neighboring information
  std::vector<dgMiniInterface> *miniInterfaceV=_createMiniInterfaces(*this);
  // elementToNeighbors[oldGroupId][oldElementId][neighborId (i.e. 0 to 2 for triangles)]<neighborOldGroupId,neighborOldElementId>
  std::vector<std::vector<std::vector<std::pair<int,int> > > >elementToNeighbors;
  // id of the new group, indexed by [oldGroupId][oldElementId]
  // -1 if the element is not yet in a new group
  // -2 if the element is in a new group whose id is not determined yet
  std::vector<std::vector<int> >newGroupIds;
  std::vector< dgGroupOfElements* >newGroups;// indexed by newGroupId
  // localDt[oldGroupId][oldElementId]
  std::vector<std::vector<double> >localDt;


  std::vector<int>oldGroupIds;

  newGroupIds.resize(getNbElementGroups());
  elementToNeighbors.resize(getNbElementGroups());
  for(int iGroup=0;iGroup<getNbElementGroups();iGroup++){
    dgGroupOfElements *g=getElementGroup(iGroup); 
    elementToNeighbors[iGroup].resize(g->getNbElements());
    newGroupIds[iGroup].assign(g->getNbElements(),-1);
  }

  // Build elementToNeighbors table (needed to have random access to the neighbors)
  for(int iInterface=0;iInterface<miniInterfaceV->size();iInterface++){
    dgMiniInterface &interface=miniInterfaceV->at(iInterface);
    for(int iConn=0;iConn<interface.connections.size();iConn++){
      int gIdi=interface.connections[iConn].iGroup;
      int eIdi=interface.connections[iConn].iElement;
      for(int jConn=0;jConn<iConn;jConn++){
        int gIdj=interface.connections[jConn].iGroup;
        int eIdj=interface.connections[jConn].iElement;
        elementToNeighbors[gIdi][eIdi].push_back(std::pair<int,int>(gIdj,eIdj));
        elementToNeighbors[gIdj][eIdj].push_back(std::pair<int,int>(gIdi,eIdi));
      }
    }
  }

  // Compute the time step constrain per element
  double dtMin = DBL_MAX;
  double dtMax = 0;
  localDt.resize(getNbElementGroups());
  for (int i=0;i<getNbElementGroups();i++){
    dgAlgorithm::computeElementaryTimeSteps(*claw, *getElementGroup(i), solution->getGroupProxy(i), localDt[i]);
    for (int k=0;k<localDt[i].size();k++){
      dtMin = std::min(dtMin,localDt[i][k]);
      dtMax = std::max(dtMax,localDt[i][k]);
    }
  }
#ifdef HAVE_MPI
  double dtMin_min;
  MPI_Allreduce((void *)&dtMin, &dtMin_min, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
  dtMin=dtMin_min;
  double dtMax_max;
  MPI_Allreduce((void *)&dtMax, &dtMax_max, 1, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
  dtMax=dtMax_max;
#endif

  Msg::Info("Time step for standard RK should be %e",dtMin);
  Msg::Info("Multirate base time step should be %e",dtMax);



  // We take the base time step as 80% of the largest elementary time-step.
  // This is arbitrary and should be optimized (maybe on the fly...)
  double dtRef=dtMax*0.8;

  // time steps are dtRef*2^(-dtExponent), with dtExponent ranging in [0:dtMaxExponent]
  int dtMaxExponent=0;
  while(dtRef/pow(2.0,(double)dtMaxExponent)>dtMin)
    dtMaxExponent++;
  if(dtMaxExponent>maxLevels){
    dtRef*=1.0/pow(2.0,(double)(dtMaxExponent-maxLevels));
    dtMaxExponent=maxLevels;
  }
  _dtMaxExponent=dtMaxExponent;


  // Bounds to be able to access elements at the previous level (to add the neighbors in the current group)
  int lowerLevelGroupIdStart=-1;
  int lowerLevelGroupIdEnd=-1;

  bool isOuterBufferLayer=false;
  int currentNewGroupId=0;
  int loopId=0;

  // We pass two times by each exponent level: one for the normal(bulk) + innerBuffer groups, and one for the outerBuffer groups
  for(int currentExponent=dtMaxExponent;currentExponent>=0;(!isOuterBufferLayer)?currentExponent--:currentExponent=currentExponent){
    int currentBufferSize=isOuterBufferLayer?outerBufferSize:innerBufferSize;
    double currentDt=dtRef/pow(2.0,(double)currentExponent);
    // element for the new groups at this level:
    // mapNewGroups[oldGroupId][oldElementId]
    std::map<int,std::vector<int> >mapNewGroups;
    if(lowerLevelGroupIdStart==-1){
      lowerLevelGroupIdStart=0;
    }
    else{
      // Add the neighbors elements to the new groups
      // For buffer AND non buffer layers
      lowerLevelGroupIdStart=lowerLevelGroupIdEnd;
      // We add bufferSize elements (most of the time, bufferSize=1 is enough)
      for(int iLoop=0;iLoop<currentBufferSize;iLoop++){
        for(int iInterface=0;iInterface<miniInterfaceV->size();iInterface++){
          dgMiniInterface &interface=miniInterfaceV->at(iInterface);
          bool toAdd=false;
          // if one of the elements adjacent to the interface is mapped to the previous level
          // we check all elements adjacent to this interface, and add those that does not
          // already have a new group to the current new group
          for(int iConn=0;iConn<interface.connections.size();iConn++){
            int gId=interface.connections[iConn].iGroup;
            int eId=interface.connections[iConn].iElement;
            int newGroupId=newGroupIds[gId][eId];
            if(newGroupId>=0 || ( newGroupId>-2-iLoop && newGroupId<-1) ){
              toAdd=true;
              continue;
            }
          }
          if(toAdd){
            for(int iConn=0;iConn<interface.connections.size();iConn++){
              int gId=interface.connections[iConn].iGroup;
              int eId=interface.connections[iConn].iElement;
              int newGroupId=newGroupIds[gId][eId];
              if(newGroupId==-1){
                mapNewGroups[gId].push_back(eId);
                newGroupIds[gId][eId]=-2-iLoop;
              }
            }
          }
        }
      }
    }
    if(!isOuterBufferLayer){
      // We add all the elements that are stable with the current time step, but not with twice that time step
      for(int iGroup=0;iGroup<getNbElementGroups();iGroup++){
        dgGroupOfElements *elGroup=getElementGroup(iGroup);
        for(int iElement=0;iElement<elGroup->getNbElements();iElement++){
          if(localDt[iGroup][iElement]>=currentDt && (localDt[iGroup][iElement]<currentDt*2 || currentExponent==0)){
            if(newGroupIds[iGroup][iElement]==-1){
              mapNewGroups[iGroup].push_back(iElement);
              newGroupIds[iGroup][iElement]=-2;
            }
          }
        }
      }

      // We split those elements into bulk and innerBuffer (i.e. those who have a neighbor with a bigger time step)
      lowerLevelGroupIdStart=currentNewGroupId;

#define MAXBUFFERSIZE 100000
      if(currentExponent>0){
        for(int iLoop=0;iLoop<currentBufferSize;iLoop++){
          for (std::map<int, std::vector<int> >::iterator it = mapNewGroups.begin(); it !=mapNewGroups.end() ; ++it){
            for(int i=0;i<it->second.size();i++){
              bool inInnerBuffer=false;
              int oldGId=it->first;
              int oldEId=it->second[i];
              // We only consider elements in the map and not in the inner buffer for a different iLoop
              if(newGroupIds[oldGId][oldEId]>-2 || newGroupIds[oldGId][oldEId]<-(MAXBUFFERSIZE-1) )
                continue;
              for(int iNeighbor=0;iNeighbor<elementToNeighbors[oldGId][oldEId].size();iNeighbor++){
                std::pair<int,int> neighIds=elementToNeighbors[oldGId][oldEId][iNeighbor];
                if(newGroupIds[neighIds.first][neighIds.second]==-1-iLoop*MAXBUFFERSIZE){
                  inInnerBuffer=true;
                  continue;
                }
              }
              if(inInnerBuffer){
                newGroupIds[oldGId][oldEId]=-1-(iLoop+1)*MAXBUFFERSIZE;
              }
            }
          }
        }
      }

      for (std::map<int, std::vector<int> >::iterator it = mapNewGroups.begin(); it !=mapNewGroups.end() ; ++it){
        if(!it->second.empty()){
          std::vector<int>forBulk;
          std::vector<int>forInnerBuffer;
          for(int i=0;i<it->second.size();i++){
            int oldGId=it->first;
            int oldEId=it->second[i];
            if( newGroupIds[oldGId][oldEId]>-2 || newGroupIds[oldGId][oldEId]<-(MAXBUFFERSIZE-1) ){
              forInnerBuffer.push_back(oldEId);
            }
            else{
              forBulk.push_back(oldEId);
            }
          }
          for(int i=0;i<forBulk.size();i++){
            newGroupIds[it->first][forBulk[i]]=currentNewGroupId;
          }
          dgGroupOfElements *oldGroup=getElementGroup(it->first);
          dgGroupOfElements *newGroup;
          if(!forBulk.empty()){
            std::vector<MElement*>forBulkV;
            for(int i=0;i<forBulk.size();i++){
              forBulkV.push_back(getElementGroup(it->first)->getElement(forBulk[i]));
            }
            oldGroupIds.resize(currentNewGroupId+1);
            oldGroupIds[currentNewGroupId]=it->first;
            newGroup=new dgGroupOfElements(forBulkV,oldGroup->getOrder(),oldGroup->getGhostPartition());
            newGroup->copyPrivateDataFrom(oldGroup);
            #ifdef TEST
            if(currentExponent==0){
              newGroup->_multirateExponent=currentExponent+1;
              newGroup->_multirateOuterBuffer=true;
              newGroup->_multirateInnerBuffer=false;
            }
            else{
              newGroup->_multirateExponent=currentExponent;
              newGroup->_multirateOuterBuffer=false;
              newGroup->_multirateInnerBuffer=true;
            }
            #else
            newGroup->_multirateExponent=currentExponent;
            newGroup->_multirateOuterBuffer=false;
            newGroup->_multirateInnerBuffer=false;
            #endif
            newGroups.resize(currentNewGroupId+1);
            newGroups[currentNewGroupId]=newGroup;
            currentNewGroupId++;
          }

          for(int i=0;i<forInnerBuffer.size();i++){
            newGroupIds[it->first][forInnerBuffer[i]]=currentNewGroupId;
          }
          if(!forInnerBuffer.empty()){
            std::vector<MElement*>forInnerBufferV;
            for(int i=0;i<forInnerBuffer.size();i++){
              forInnerBufferV.push_back(getElementGroup(it->first)->getElement(forInnerBuffer[i]));
            }
            oldGroupIds.resize(currentNewGroupId+1);
            oldGroupIds[currentNewGroupId]=it->first;
            newGroup=new dgGroupOfElements(forInnerBufferV,oldGroup->getOrder(),oldGroup->getGhostPartition());
            newGroup->copyPrivateDataFrom(oldGroup);
            newGroup->_multirateExponent=currentExponent;
            newGroup->_multirateOuterBuffer=false;
            newGroup->_multirateInnerBuffer=true;
            newGroups.resize(currentNewGroupId+1);
            newGroups[currentNewGroupId]=newGroup;
            currentNewGroupId++;
          }
        }
        else
          Msg::Info("Empty Group !!!!!!!!!!!!!!!!!!");
      }
    }
    else{
      for (std::map<int, std::vector<int> >::iterator it = mapNewGroups.begin(); it !=mapNewGroups.end() ; ++it){
        if(!it->second.empty()){
          for(int i=0;i<it->second.size();i++){
            int oldGId=it->first;
            int oldEId=it->second[i];
            newGroupIds[oldGId][oldEId]=currentNewGroupId;
          }
          dgGroupOfElements *oldGroup=getElementGroup(it->first);
          std::vector<MElement *>newGroupV;
          for(int i=0;i<it->second.size();i++){
            newGroupV.push_back(getElementGroup(it->first)->getElement(it->second[i]));
          }
          oldGroupIds.resize(currentNewGroupId+1);
          oldGroupIds[currentNewGroupId]=it->first;
          dgGroupOfElements *newGroup=new dgGroupOfElements(newGroupV,oldGroup->getOrder(),oldGroup->getGhostPartition());
          newGroup->copyPrivateDataFrom(oldGroup);
          newGroup->_multirateExponent=currentExponent;
          newGroup->_multirateOuterBuffer=true;
          newGroup->_multirateInnerBuffer=false;
          newGroups.resize(currentNewGroupId+1);
          newGroups[currentNewGroupId]=newGroup;
          currentNewGroupId++;
        }
        else
          Msg::Info("Empty Group !!!!!!!!!!!!!!!!!!");
      }
    }
    lowerLevelGroupIdEnd=currentNewGroupId;
    isOuterBufferLayer=!isOuterBufferLayer;
  }
  // Some stats
  int count=0;
  for(int i=0;i<newGroups.size();i++){
    Msg::Info("Old group #%d, exponent %d, New group #%d has %d elements",oldGroupIds[i],newGroups[i]->getMultirateExponent(),i,newGroups[i]->getNbElements());
    if(newGroups[i]->getIsInnerMultirateBuffer())
      Msg::Info("InnerBuffer");
    else if(newGroups[i]->getIsOuterMultirateBuffer())
      Msg::Info("OuterBuffer");
    else
      Msg::Info("Not Buffer");
    count+=newGroups[i]->getNbElements();
  }
  Msg::Info("That makes a total of %d elements",count);
  _elementGroups.clear();
  _elementGroups=newGroups;
  delete miniInterfaceV;
  return dtRef;
}

// Split the groups of elements into vertical layers (only for primsatic 3D meshes)
void dgGroupCollection::splitGroupsByVerticalLayer(std::vector<std::string> topLevelTags) {

  Msg::Info("Splitting Groups per vertical layers");

  // Interfaces are not built yet, so we use a "mini" structure to deduce neighboring information
  std::vector<dgMiniInterface> *miniInterfaceV=_createMiniInterfaces(*this);
  // elementToNeighbors[oldGroupId][oldElementId][neighborId (i.e. 0 to 2 for triangles)]<neighborOldGroupId,neighborOldElementId>
  std::vector<std::vector<std::vector<std::pair<int,int> > > >elementToNeighbors;
  // id of the new group, indexed by [oldGroupId][oldElementId]
  // -1 if the element is not yet in a new group
  // -2 if the element is in a new group whose id is not determined yet
  std::vector< dgGroupOfElements* >newGroups;// indexed by newGroupId
  // isProcessed[oldGroupId][oldElementId]
  std::vector<std::vector<int> >isProcessed;

  isProcessed.resize(getNbElementGroups());
  elementToNeighbors.resize(getNbElementGroups());
  for(int iGroup=0;iGroup<getNbElementGroups();iGroup++){
    dgGroupOfElements *g=getElementGroup(iGroup); 
    elementToNeighbors[iGroup].resize(g->getNbElements());
    isProcessed[iGroup].assign(g->getNbElements(),0);
  }

  // Build elementToNeighbors table (needed to have random access to the neighbors)
  for(int iInterface=0;iInterface<miniInterfaceV->size();iInterface++){
    dgMiniInterface &interface=miniInterfaceV->at(iInterface);
    if (interface.numVertices == 3) { // only accept triangular interfaces
      for(int iConn=0;iConn<interface.connections.size();iConn++){
        int gIdi=interface.connections[iConn].iGroup;
        int eIdi=interface.connections[iConn].iElement;
        for(int jConn=0;jConn<iConn;jConn++){
          int gIdj=interface.connections[jConn].iGroup;
          int eIdj=interface.connections[jConn].iElement;
          elementToNeighbors[gIdi][eIdi].push_back(std::pair<int,int>(gIdj,eIdj));
          elementToNeighbors[gIdj][eIdj].push_back(std::pair<int,int>(gIdi,eIdi));
        }
      }
    }
  }

  std::vector< std::pair<int,int> > oldGroupElemIds;
  std::vector< std::pair<int,int> > newGroupElemIds;
  std::vector< std::vector< MElement* > > verticalGroupsVector;
  std::vector< MElement* > newGroupElems;
  int currentNewGroupId=0;
  bool finalLayer = false;

  do {
    newGroupElemIds.clear();
    newGroupElems.clear();
    if(currentNewGroupId==0) {
      // create first element groups
      for(int iInterface=0;iInterface<miniInterfaceV->size();iInterface++){
        dgMiniInterface &interface=miniInterfaceV->at(iInterface);
        for(int iConn=0;iConn<interface.connections.size();iConn++){
          int gId=interface.connections[iConn].iGroup;
          int eId=interface.connections[iConn].iElement;
          bool topLevelTagFound = false;
          for (int i = 0; i < topLevelTags.size(); i++)
            if (_model->getPhysicalName(2, interface.physicalTag) == topLevelTags.at(i) ) {
              topLevelTagFound = true;
              break;
            }
          if (topLevelTagFound) {
//             printf("Tag found: %d %d %s \n",gId,eId,_model->getPhysicalName(2, interface.physicalTag).c_str());
            newGroupElems.push_back(getElementGroup(gId)->getElement(eId));
            newGroupElemIds.push_back(std::pair<int,int>(gId,eId));
            isProcessed[gId][eId]=1;
          }
        }
      }
      if (newGroupElems.size() == 0) {
        std::string errMsg = "No triangular boundary faces found with the given physical tag(s): ";
        for (int i = 0; i < topLevelTags.size(); i++)
          errMsg += topLevelTags.at(i) += " ";
        Msg::Error(errMsg.c_str());
      }
    }
    else {
      // find neighbors in next level
      for (int iElems = 0; iElems<oldGroupElemIds.size();iElems++ ) {
        int gId = oldGroupElemIds.at(iElems).first;
        int eId = oldGroupElemIds.at(iElems).second;
        bool newNeighborFound = false;
        for (int iNeighbors = 0; iNeighbors < elementToNeighbors[gId][eId].size(); iNeighbors++) {
          int nGId = elementToNeighbors[gId][eId].at(iNeighbors).first;
          int nEId = elementToNeighbors[gId][eId].at(iNeighbors).second;
          if (!isProcessed[nGId][nEId]) {
            newGroupElemIds.push_back(std::pair<int,int>(nGId,nEId));
            newGroupElems.push_back(getElementGroup(nGId)->getElement(nEId));
            isProcessed[nGId][nEId]=1;
            newNeighborFound = true;
//             printf("adding neighbor eId: %d\n",nEId);
          } 
        }
        if (!newNeighborFound) {
          finalLayer = true;
          break;
        }
      }   
    }  

    
//     printf("new elems %d\n",newGroupElems.size());
    if (!finalLayer) {
      dgGroupOfElements* oldGroup = getElementGroup(0);
      dgGroupOfElements* newGroup=new dgGroupOfElements(newGroupElems,oldGroup->getOrder(),oldGroup->getGhostPartition());
      newGroup->copyPrivateDataFrom(oldGroup);
      newGroups.resize(currentNewGroupId+1);
      newGroups[currentNewGroupId]=newGroup;
      printf("Created a new group ID:%d with %d elements.\n",currentNewGroupId,newGroup->getNbElements());
      currentNewGroupId++;
    }
    oldGroupElemIds = newGroupElemIds;
  } while (!finalLayer);
  
  _elementGroups.clear();
  _elementGroups=newGroups;
  delete miniInterfaceV;

}

dgGroupCollection::dgGroupCollection()
{
  _groupsOfElementsBuilt=false;_groupsOfInterfacesBuilt=false;
}

dgGroupCollection::dgGroupCollection(GModel *model, int dimension, int order)
{
  _groupsOfElementsBuilt=false;_groupsOfInterfacesBuilt=false;
  buildGroupsOfElements(model,dimension,order, NULL);
}

dgGroupCollection::dgGroupCollection(GModel *model, int dimension, int order, std::vector<std::string>* physicalTags)
{
  _groupsOfElementsBuilt=false;_groupsOfInterfacesBuilt=false;
  buildGroupsOfElements(model,dimension,order,physicalTags);
}

dgGroupCollection* dgGroupCollection::newByTag(GModel *model, int dimension, int order, std::vector<std::string> tags){
  Msg::Info("Creating %dD groupCollection by tags.",dimension);
  dgGroupCollection* subCollection = new dgGroupCollection(model,dimension,order,&tags);
  if (subCollection->getNbElementGroups()==0)
    Msg::Warning("groupCollection is empty.");
  return subCollection;
}

dgGroupCollection::~dgGroupCollection() 
{
  for (int i=0; i< _elementGroups.size(); i++)
    delete _elementGroups[i];
  for (int i=0; i< _faceGroups.size(); i++)
    delete _faceGroups[i];
  for (int i=0; i< _boundaryGroups.size(); i++)
    delete _boundaryGroups[i];
  for (int i=0; i< _ghostGroups.size(); i++)
    delete _ghostGroups[i];
}

void dgGroupCollection::find (MElement*e, int &ig, int &index)
{
  for (ig=0;ig<_elementGroups.size();ig++) {
    index = _elementGroups[ig]->getIndexOfElement(e);
    if (index != -1)return;
  }
}

#include "LuaBindings.h"
void dgGroupCollection::registerBindings(binding *b)
{
  classBinding *cb;
  methodBinding *cm;
  cb = b->addClass<dgGroupOfElements>("dgGroupOfElements");
  cb->setDescription("a group of element sharing the same properties");
  cb = b->addClass<dgGroupOfFaces>("dgGroupOfFaces");
  cb->setDescription("a group of faces. All faces of this group are either interior of the same group of elements or at the boundary between two group of elements");
  cb = b->addClass<dgGroupCollection>("dgGroupCollection");
  cb->setDescription("The GroupCollection class let you access to group partitioning functions");
  cm = cb->setConstructor<dgGroupCollection,GModel*,int,int>();
  cm->setDescription("Build the group of elements, separated by element type and element order. Additional partitioning can be done using splitGroupsForXXX specific functions");
  cm->setArgNames("model","dimension","order",NULL);
  cm = cb->addMethod("buildGroupsOfInterfaces",&dgGroupCollection::buildGroupsOfInterfaces);
  cm->setDescription("Build the group of interfaces, i.e. boundary interfaces and inter-element interfaces");
  cm = cb->addMethod("splitGroupsForMultirate",&dgGroupCollection::splitGroupsForMultirate);
  cm->setDescription("Split the groups according to their own stable time step");
  cm->setArgNames("maxLevels","innerBufferSize","outerBufferSize","claw","solution",NULL);
  cm = cb->addMethod("splitGroupsByVerticalLayer",&dgGroupCollection::splitGroupsByVerticalLayer);
  cm->setDescription("Split the groups according vertical layer structure. The first is defined by the topLevelTags.");
  cm->setArgNames("topLevelTags",NULL);
  cm = cb->addMethod("newByTag",&dgGroupCollection::newByTag);
  cm->setDescription("Creates a group collection of elements associated with given physical tag(s).");
  cm->setArgNames("model","dimension","order","tags",NULL);
  cm = cb->addMethod("getNbElementGroups", &dgGroupCollection::getNbElementGroups);
  cm->setDescription("return the number of dgGroupOfElements");
  cm = cb->addMethod("getNbFaceGroups", &dgGroupCollection::getNbFaceGroups);
  cm->setDescription("return the number of dgGroupOfFaces (interior ones, not the domain boundaries)");
  cm = cb->addMethod("getNbBoundaryGroups", &dgGroupCollection::getNbBoundaryGroups);
  cm->setDescription("return the number of group of boundary faces");
  cm = cb->addMethod("getElementGroup", &dgGroupCollection::getElementGroup);
  cm->setDescription("get 1 group of elements");
  cm->setArgNames("id", NULL);
  cm = cb->addMethod("getFaceGroup", &dgGroupCollection::getFaceGroup);
  cm->setDescription("get 1 group of faces");
  cm->setArgNames("id", NULL);
  cm = cb->addMethod("getBoundaryGroup", &dgGroupCollection::getBoundaryGroup);
  cm->setDescription("get 1 group of boundary faces");
  cm->setArgNames("id", NULL);
}
