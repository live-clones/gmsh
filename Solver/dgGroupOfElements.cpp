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
  int nbPsi = _fs.coefficients.size1();
  _redistributionFluxes[0] = new fullMatrix<double> (nbPsi,_integration->size1());
  _redistributionFluxes[1] = new fullMatrix<double> (nbPsi,_integration->size1());
  _redistributionFluxes[2] = new fullMatrix<double> (nbPsi,_integration->size1());
  _redistributionSource = new fullMatrix<double> (nbPsi,_integration->size1());
  _collocation = new fullMatrix<double> (_integration->size1(),nbPsi);
  _mapping = new fullMatrix<double> (e.size(), 10 * _integration->size1());
  _imass = new fullMatrix<double> (nbPsi,nbPsi*e.size()); 
  _dPsiDx = new fullMatrix<double> ( _integration->size1()*3,nbPsi*e.size());
  _elementVolume = new fullMatrix<double> (e.size(),1);
  _innerRadii = new fullMatrix<double> (e.size(),1);
  double g[256][3],f[256];
  
  for (int i=0;i<_elements.size();i++){
    MElement *e = _elements[i];
    element_to_index[e] = i;
    fullMatrix<double> imass(*_imass,nbPsi*i,nbPsi);
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
      for (int k=0;k<nbPsi;k++){ 
        for (int l=0;l<nbPsi;l++) { 
          imass(k,l) += f[k]*f[l]*weight*detjac;
        }
        // (iQP*3+iXYZ , iFace*NPsi+iPsi)
        (*_dPsiDx)(j*3  ,i*nbPsi+k) = g[k][0]*ijac[0][0]+g[k][1]*ijac[0][1]+g[k][2]*ijac[0][2];
        (*_dPsiDx)(j*3+1,i*nbPsi+k) = g[k][0]*ijac[1][0]+g[k][1]*ijac[1][1]+g[k][2]*ijac[1][2];
        (*_dPsiDx)(j*3+2,i*nbPsi+k) = g[k][0]*ijac[2][0]+g[k][1]*ijac[2][1]+g[k][2]*ijac[2][2];
      }
    }
    imass.invertInPlace();
  }
  // redistribution matrix
  // quadrature weight x parametric gradients in quadrature points

  for (int j=0;j<_integration->size1();j++) {
    _fs.df((*_integration)(j,0),
	   (*_integration)(j,1),
	   (*_integration)(j,2), g);
    _fs.f((*_integration)(j,0),
	   (*_integration)(j,1),
	   (*_integration)(j,2), f);
    const double weight = (*_integration)(j,3);
    for (int k=0;k<_fs.coefficients.size1();k++){ 
      (*_redistributionFluxes[0])(k,j) = g[k][0] * weight;
      (*_redistributionFluxes[1])(k,j) = g[k][1] * weight;
      (*_redistributionFluxes[2])(k,j) = g[k][2] * weight;
      (*_redistributionSource)(k,j) = f[k] * weight;
      (*_collocation)(j,k) = f[k];
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

void dgGroupOfConnections::addElement(int iElement, int iClosure) {
  _elementId.push_back(iElement);
  _closuresId.push_back(iClosure);
}


void dgGroupOfFaces::addFace(const MFace &topoFace, const std::vector<int> &iEls){
  if (iEls.size() != _connections.size())
    throw;

  std::vector<MVertex*> vertices;
  for (size_t i=0; i<iEls.size(); i++){
    int closureId;
    const MElement *el;
    int ithFace, sign, rot;
    el = _connections[i]->getGroupOfElements().getElement(iEls[i]);
    el->getFaceInfo(topoFace, ithFace, sign, rot);
    closureId = _connections[i]->getFunctionSpace()->getFaceClosureId(ithFace,sign,rot);
    _connections[i]->addElement(iEls[i], closureId);
    if (i==0) {
      const std::vector<int> & geomClosure = el->getFunctionSpace()->getFaceClosure(closureId);
      for (int j=0; j<geomClosure.size() ; j++)
        vertices.push_back( const_cast<MElement*>(el)->getVertex(geomClosure[j]) );
    }
  }

  if (topoFace.getNumVertices() == 3){
    switch(vertices.size()){
    case 3  : _faces.push_back(new MTriangle   (vertices) ); break;
    case 6  : _faces.push_back(new MTriangle6  (vertices) ); break;
    case 10  : _faces.push_back(new MTriangleN (vertices,3) ); break;
    case 15  : _faces.push_back(new MTriangleN (vertices,4) ); break;
    case 21  : _faces.push_back(new MTriangleN (vertices,5) ); break;
    default : throw;
    }
  } else if (topoFace.getNumVertices() == 4){
    switch(vertices.size()){
      case 4  : _faces.push_back(new MQuadrangle (vertices) ); break;
      case 8  : _faces.push_back(new MQuadrangle8 (vertices) ); break;
      case 9  : _faces.push_back(new MQuadrangle9 (vertices) ); break;
      case 16 : _faces.push_back(new MQuadrangleN (vertices, 4)); break;
      case 25 : _faces.push_back(new MQuadrangleN (vertices, 5)); break;
      default : throw;
    }
  }
  else {
    throw;
  }
}

void dgGroupOfFaces::addEdge(const MEdge &topoEdge, const std::vector<int> &iEls) 
{
  if (iEls.size() != _connections.size() )
    throw;

  std::vector<MVertex*> vertices;
  for (size_t i = 0; i<_connections.size(); i++) {
    const MElement *el ;
    int closureId;
    int ithFace, sign;
    el = _connections[i]->getGroupOfElements().getElement(iEls[i]);
    el->getEdgeInfo(topoEdge, ithFace, sign);
    closureId = _connections[i]->getFunctionSpace()->getEdgeClosureId(ithFace,sign);
    _connections[i]->addElement(iEls[i], closureId);
    if (i==0) {
      const std::vector<int> & geomClosure = el->getFunctionSpace()->getEdgeClosure(closureId);
      for (int j=0; j<geomClosure.size() ; j++)
        vertices.push_back( const_cast<MElement*>(el)->getVertex(geomClosure[j]) );
    }
  }

  switch(vertices.size()) {
    case 2  : _faces.push_back(new MLine (vertices) ); break;
    case 3  : _faces.push_back(new MLine3 (vertices) ); break;
    default : _faces.push_back(new MLineN (vertices) ); break;
  }
}

void dgGroupOfFaces::addVertex(MVertex *topoVertex, const std::vector<int> &iEls){
  if (iEls.size() != _connections.size() )
    throw;

  for (size_t i=0; i<iEls.size(); i++) {
    int ithVertex;
    _connections[i]->getGroupOfElements().getElement(iEls[i])->getVertexInfo(topoVertex, ithVertex);
    _connections[i]->addElement(iEls[i],ithVertex);
  }
  _faces.push_back(new MPoint(topoVertex) );
}


void dgGroupOfFaces::init(int pOrder) {
  if (!_faces.size())return;
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

dgGroupOfFaces::~dgGroupOfFaces()
{
  if (!_faces.size())return;
  delete _redistribution;
  delete _collocation;
  delete _detJac;
  delete _interfaceSurface;
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MVertex*> &boundaryVertices)
{
  _connections.push_back(new dgGroupOfConnections(elGroup, *this, pOrder));
  _boundaryTag=boundaryTag;
  if(boundaryTag==""){
    Msg::Warning ("empty boundary tag, group of boundary faces not created");
    return;
  }
  std::vector<int> iEls(1);
  for(int i=0; i<elGroup.getNbElements(); i++){
    MElement &el = *elGroup.getElement(i);
    for (int j=0; j<el.getNumVertices(); j++){
      MVertex* vertex = el.getVertex(j);
      if(boundaryVertices.find(vertex)!=boundaryVertices.end()){
        iEls[0] = i;
        addVertex(vertex,iEls);
      }
    }
  }
  init(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MEdge,Less_Edge> &boundaryEdges)
{
  _connections.push_back(new dgGroupOfConnections(elGroup,*this, pOrder));
  _boundaryTag=boundaryTag;
  if(boundaryTag==""){
    Msg::Warning ("empty boundary tag, group of boundary faces not created");
    return;
 }
 std::vector<int> iEls(1);
  for(int i=0; i<elGroup.getNbElements(); i++){
    MElement &el = *elGroup.getElement(i);
    for (int j=0; j<el.getNumEdges(); j++){
      MEdge edge = el.getEdge(j);
      if(boundaryEdges.find(edge)!=boundaryEdges.end()){
        iEls[0] = i;
        addEdge(edge, iEls);
      }
    }
  }
  init(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MFace,Less_Face> &boundaryFaces)
{
  _connections.push_back(new dgGroupOfConnections(elGroup, *this, pOrder));
  _boundaryTag=boundaryTag;
  if(boundaryTag=="")
    throw;
  std::vector<int> iEls(1);
  for(int i=0; i<elGroup.getNbElements(); i++){
    MElement &el = *elGroup.getElement(i);
    for (int j=0; j<el.getNumFaces(); j++){
      MFace face = el.getFace(j);
      if(boundaryFaces.find(face)!=boundaryFaces.end()) {
        iEls[0] = i;
        addFace(face, iEls);
      }
    }
  }
  init(pOrder);
}

dgGroupOfConnections::dgGroupOfConnections(const dgGroupOfElements &elementGroup, const dgGroupOfFaces &faceGroup, int pOrder) :
  _elementGroup(elementGroup),
  _faceGroup(faceGroup)
{
  _fs = _elementGroup.getElement(0)->getFunctionSpace(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, int pOrder, int numVertices)
{
  _connections.push_back(new dgGroupOfConnections(elGroup, *this, pOrder));
  _connections.push_back(new dgGroupOfConnections(elGroup, *this, pOrder));
  std::vector<int> iEls(2);
  switch (_connections[0]->getGroupOfElements().getElement(0)->getDim()) {
    case 1 : {
      std::map<MVertex*,int> vertexMap;
      for(int i=0; i<elGroup.getNbElements(); i++){
        MElement &el = *elGroup.getElement(i);
        for (int j=0; j<el.getNumVertices(); j++){
          MVertex* vertex = el.getVertex(j);
          if(vertexMap.find(vertex) == vertexMap.end()){
            vertexMap[vertex] = i;
          }else{
            iEls[0] = vertexMap[vertex];
            iEls[1] = i;
            addVertex(vertex,iEls);
          }
        }
      }
      break;
    }
    case 2 : {
      std::map<MEdge,int,Less_Edge> edgeMap;
      for(int i=0; i<elGroup.getNbElements(); i++){
        MElement &el = *elGroup.getElement(i);
        for (int j=0; j<el.getNumEdges(); j++){
          MEdge edge = el.getEdge(j);
          if(edgeMap.find(edge) == edgeMap.end()){
            edgeMap[edge] = i;
          }else{
            iEls[0] = edgeMap[edge];
            iEls[1] = i;
            addEdge(edge,iEls);
          }
        }
      }
      break;
    }
    case 3 : {
      std::map<MFace,int,Less_Face> faceMap;
      for(int i=0; i<elGroup.getNbElements(); i++){
        MElement &el = *elGroup.getElement(i);
        for (int j=0; j<el.getNumFaces(); j++){
          MFace face = el.getFace(j);
          if (numVertices < 0 || face.getNumVertices() == numVertices) {
            if(faceMap.find(face) == faceMap.end()){
              faceMap[face] = i;
            }else{
              iEls[0] = faceMap[face];
              iEls[1] = i;
              addFace(face,iEls);
            }
          }
        }
      }
      break;
    }
    default : throw;
  }
  init(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup1, const dgGroupOfElements &elGroup2, int pOrder, int numVertices)
{
  _connections.push_back(new dgGroupOfConnections(elGroup1, *this, pOrder));
  _connections.push_back(new dgGroupOfConnections(elGroup2, *this, pOrder));
  std::vector<int> iEls(2);
  switch (_connections[0]->getGroupOfElements().getElement(0)->getDim()) {
    case 1 : {
      std::map<MVertex*,int> vertexMap1;
      for(int i=0; i<elGroup1.getNbElements(); i++){
        MElement &el = *elGroup1.getElement(i);
        for (int j=0; j<el.getNumVertices(); j++){
          MVertex* vertex = el.getVertex(j);
          if(vertexMap1.find(vertex) == vertexMap1.end()){
            vertexMap1[vertex] = i;
          }else{
            vertexMap1.erase(vertex);
          }
        }
      }

      for(int i=0; i<elGroup2.getNbElements(); i++) {
        MElement &el = *elGroup2.getElement(i);
        for (int j=0; j<el.getNumVertices(); j++) {
          MVertex* vertex = el.getVertex(j);
          std::map<MVertex*,int>::iterator it = vertexMap1.find(vertex);
          if(it != vertexMap1.end()) {
            iEls[0] = it->second;
            iEls[1] = i;
            addVertex(vertex,iEls);
          }
        }
      }      
    }
    break;
    case 2 : {
      std::map<MEdge,int,Less_Edge> edgeMap;
      for(int i=0; i<elGroup1.getNbElements(); i++){
        MElement &el = *elGroup1.getElement(i);
        for (int j=0; j<el.getNumEdges(); j++){
          MEdge edge = el.getEdge(j);
          if(edgeMap.find(edge) == edgeMap.end()){
            edgeMap[edge] = i;
          }else{
            edgeMap.erase(edge);
          }
        }
      }
      for(int i=0; i<elGroup2.getNbElements(); i++){
        MElement &el = *elGroup2.getElement(i);
        for (int j=0; j<el.getNumEdges(); j++){
          MEdge edge = el.getEdge(j);
          std::map<MEdge,int,Less_Edge>::iterator it = edgeMap.find(edge);
          if(it != edgeMap.end()){
            iEls[0] = it->second;
            iEls[1] = i;
            addEdge(edge,iEls);
          }
        }
      }
      
      break;
    }
    case 3 : {
      std::map<MFace,int,Less_Face> faceMap;
      for(int i=0; i<elGroup1.getNbElements(); i++){
        MElement &el = *elGroup1.getElement(i);
        for (int j=0; j<el.getNumFaces(); j++){
          MFace face = el.getFace(j);
          if (numVertices < 0 || face.getNumVertices() == numVertices) {
            if(faceMap.find(face) == faceMap.end()){
              faceMap[face] = i;
            }else{
              faceMap.erase(face);
            }
          }
        }
      }
      for(int i=0; i<elGroup2.getNbElements(); i++){
        MElement &el = *elGroup2.getElement(i);
        for (int j=0; j<el.getNumFaces(); j++){
          MFace face = el.getFace(j);
          std::map<MFace,int,Less_Face>::iterator it = faceMap.find(face);
          if(it != faceMap.end()){
            iEls[0] = it->second;
            iEls[1] = i;
            addFace(face, iEls);
          }
        }
      }
      break;
    }
    default : throw;
  }
  init(pOrder);
}
void dgGroupOfFaces::mapToInterface ( int nFields,
    const fullMatrix<double> &vLeft,
    const fullMatrix<double> &vRight,
    fullMatrix<double> &v)
{
  if(isBoundary()){
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureLeft = getClosureLeft(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++){
          v(j, i*nFields + iField) = vLeft(closureLeft[j], _connections[0]->getElementId(i)*nFields + iField);
        }
      }
    }
    
  }else{
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureRight = getClosureRight(i);
      const std::vector<int> &closureLeft = getClosureLeft(i);
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
  if(isBoundary()){
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureLeft = getClosureLeft(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++)
          vLeft(closureLeft[j], _connections[0]->getElementId(i)*nFields + iField) += v(j, i*nFields + iField);
      }
    }
  }else{
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureRight = getClosureRight(i);
      const std::vector<int> &closureLeft = getClosureLeft(i);
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
  /*Msg::Info("Left for %p : gL %p %s %s %d, gR %p %s %s %d",
    this,
    &getGroupLeft(),
    getGroupLeft().getIsInnerMultirateBuffer()?"Inner":"",
    getGroupLeft().getIsOuterMultirateBuffer()?"Outer":"",
    getGroupLeft().getMultirateExponent(),
    &getGroupRight(),
    getGroupRight().getIsInnerMultirateBuffer()?"Inner":"",
    getGroupRight().getIsOuterMultirateBuffer()?"Outer":"",
    getGroupRight().getMultirateExponent()
    );*/
  for(int i=0; i<getNbElements(); i++) {
    const std::vector<int> &closureRight = getClosureRight(i);
    const std::vector<int> &closureLeft = getClosureLeft(i);
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
  /*Msg::Info("Right for %p : gL %p %s %s %d, gR %p %s %s %d",
    this,
    &getGroupLeft(),
    getGroupLeft().getIsInnerMultirateBuffer()?"Inner":"",
    getGroupLeft().getIsOuterMultirateBuffer()?"Outer":"",
    getGroupLeft().getMultirateExponent(),
    &getGroupRight(),
    getGroupRight().getIsInnerMultirateBuffer()?"Inner":"",
    getGroupRight().getIsOuterMultirateBuffer()?"Outer":"",
    getGroupRight().getMultirateExponent()
    );*/
  if(isBoundary())
    return;
  for(int i=0; i<getNbElements(); i++) {
    const std::vector<int> &closureRight = getClosureRight(i);
    const std::vector<int> &closureLeft = getClosureLeft(i);
    for (int iField=0; iField<nFields; iField++){
      for(size_t j =0; j < closureRight.size(); j++)
        vRight(closureRight[j], _connections[1]->getElementId(i)*nFields + iField) += v(j, (i*2+1)*nFields + iField);
    }
  }
}



void dgGroupOfConnections::init() {
  switch(getElement(0)->getDim()) {
    case 1 : _closures = _fs->vertexClosure; break;
    case 2 : _closures = _fs->edgeClosure; break;
    case 3 : _closures = _fs->faceClosure; break;
  }
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
  _dPsiDxOnQP = fullMatrix<double> ( nQP*3, nPsi*size);
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
        _dPsiDxOnQP(j*3  ,i*nPsi+iPsi) = g[iPsi][0]*ijac[0][0]+g[iPsi][1]*ijac[0][1]+g[iPsi][2]*ijac[0][2];
        _dPsiDxOnQP(j*3+1,i*nPsi+iPsi) = g[iPsi][0]*ijac[1][0]+g[iPsi][1]*ijac[1][1]+g[iPsi][2]*ijac[1][2];
        _dPsiDxOnQP(j*3+2,i*nPsi+iPsi) = g[iPsi][0]*ijac[2][0]+g[iPsi][1]*ijac[2][1]+g[iPsi][2]*ijac[2][2];
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
//  -) Finally, those groups are re-numbered 
 
void dgGroupCollection::buildGroupsOfElements(GModel *model, int dim, int order)
{
  if(_groupsOfElementsBuilt)
    return;
  _groupsOfElementsBuilt=true;
  _model = model;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::map<int, std::vector<MElement *> >localElements;
  int nlocal=0;
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    if(entity->dim() == dim){
      for (int iel=0; iel<entity->getNumMeshElements(); iel++){
        MElement *el=entity->getMeshElement(iel);
        if(el->getPartition()==Msg::GetCommRank()+1 || el->getPartition()==0){
          localElements[el->getType()].push_back(el);
          nlocal++;
          switch(dim) {
            case 1: {
              int interfaceType = 1; // number of vertices
              if(_interfaceTypes.find(interfaceType) == _interfaceTypes.end()) {
                _interfaceTypes.insert(interfaceType);
//                 printf("Inserted interfaceType: %d el: %d dim: %d\n",interfaceType,el->getType(),dim);
              }
              break;
            }
            case 2: {
              int interfaceType = 2; // number of vertices
              if(_interfaceTypes.find(interfaceType) == _interfaceTypes.end()) {
                _interfaceTypes.insert(interfaceType);
//                 printf("Inserted interfaceType: %d el: %d dim: %d\n",interfaceType,el->getType(),dim);
              }
              break;
            }
            case 3: {
              for(int iFace=0; iFace<el->getNumFaces(); iFace++) {
                MFace face = el->getFace(iFace);
                if(_interfaceTypes.find(face.getNumVertices()) == _interfaceTypes.end()) {
                  _interfaceTypes.insert(face.getNumVertices());
//                   printf("Inserted interfaceType: %d el: %d dim: %d\n",face.getNumVertices(),el->getType(),dim);
                }
              }
              break;
            }
            default :
            throw;
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
}

class dgMiniInterface {
  public:
  int physicalTag;
  std::vector<std::pair<int,int> > connectedElements; //Group, element
  dgMiniInterface() {
    physicalTag = -1;
  }
};

static std::vector<dgMiniInterface> *_createMiniInterfaces(dgGroupCollection &groups) {
  std::vector<GEntity*> entities;
  groups.getModel()->getEntities(entities);
  std::map<MVertex*, dgMiniInterface> vertexInterfaces;
  std::map<MEdge, dgMiniInterface, Less_Edge> edgeInterfaces;
  std::map<MFace, dgMiniInterface, Less_Face> faceInterfaces;
  // 1) create the topological interfaces
  int dim = groups.getElementGroup(0)->getElement(0)->getDim();
  // 1a) get tag of existing interfaces
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
  // 1b) build new interfaces
  for (size_t iGroup = 0; iGroup < groups.getNbElementGroups(); iGroup++) {
    dgGroupOfElements &group = *groups.getElementGroup(iGroup);
    for (size_t iElement = 0; iElement < group.getNbElements(); iElement++) {
      MElement &element = *group.getElement(iElement);
      switch(dim) {
        case 1: 
          for (int iVertex = 0; iVertex < element.getNumVertices(); iVertex++) {
            vertexInterfaces[element.getVertex(iVertex)].connectedElements.push_back(std::pair<int,int>(iGroup,iElement));
          }
          break;
        case 2:
          for (int iEdge = 0; iEdge < element.getNumEdges(); iEdge++) {
            edgeInterfaces[element.getEdge(iEdge)].connectedElements.push_back(std::pair<int,int>(iGroup,iElement));
          }
          break;
        case 3:
          for (int iFace = 0; iFace < element.getNumFaces(); iFace++) {
            faceInterfaces[element.getFace(iFace)].connectedElements.push_back(std::pair<int,int>(iGroup,iElement));
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
      for(std::map<MVertex*, dgMiniInterface>::iterator it = vertexInterfaces.begin(); it != vertexInterfaces.end(); it++)
        interfaces->push_back(it->second);
      break;
    case 2: 
      interfaces->reserve(edgeInterfaces.size());
      for(std::map<MEdge, dgMiniInterface, Less_Edge>::iterator it = edgeInterfaces.begin(); it != edgeInterfaces.end(); it++)
        interfaces->push_back(it->second);
      break;
    case 3: 
      interfaces->reserve(faceInterfaces.size());
      for(std::map<MFace, dgMiniInterface, Less_Face>::iterator it = faceInterfaces.begin(); it != faceInterfaces.end(); it++)
        interfaces->push_back(it->second);
      break;
  }
  return interfaces;
}

  // 2) group the faces by number of connected elements and by physical groups, destroy the actual faces
  // 3) send vector of elements,closures_id to one unique dgGroupOfFaces constructor

// Finally, group of interfaces are created
//  -) Groups of faces internal to a given group
//  -) Groups of faces between groups.
void dgGroupCollection::buildGroupsOfInterfaces()
{
  if(_groupsOfInterfacesBuilt)
    return;
  _groupsOfInterfacesBuilt=true;

  int dim = _elementGroups[0]->getElement(0)->getDim();
  int order = _elementGroups[0]->getOrder();

  std::map<const std::string,std::set<MVertex*> > boundaryVertices;
  std::map<const std::string,std::set<MEdge, Less_Edge> > boundaryEdges;
  std::map<const int,std::map<const std::string,std::set<MFace, Less_Face> > > boundaryFaces; // [elementType][bndString]

  std::vector<std::map<int, std::vector<MElement *> > >ghostElements(Msg::GetCommSize()); // [partition][elementType]
  int nghosts=0;
  std::multimap<MElement*, short> &ghostsCells = _model->getGhostCells();

  std::vector<GEntity*> entities;
  _model->getEntities(entities);


  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    if(entity->dim() == dim-1){
      for(unsigned int j = 0; j < entity->physicals.size(); j++){
        const std::string physicalName = _model->getPhysicalName(entity->dim(), entity->physicals[j]);
        for (int k = 0; k < entity->getNumMeshElements(); k++) {
          MElement *element = entity->getMeshElement(k);
          switch(dim) {
            case 1:
              boundaryVertices[physicalName].insert( element->getVertex(0) ); 
              break;
            case 2:
              boundaryEdges[physicalName].insert( element->getEdge(0) );
            break;
            case 3: {
              MFace face = element->getFace(0);
              boundaryFaces[element->getType()][physicalName].insert( face );
              break;
            }
            default :
            throw;
          }
        }
      }
    } else if(entity->dim() == dim){
      for (int iel=0; iel<entity->getNumMeshElements(); iel++){
        MElement *el=entity->getMeshElement(iel);
        if( ! (el->getPartition()==Msg::GetCommRank()+1 || el->getPartition()==0) ){
          std::multimap<MElement*, short>::iterator ghost=ghostsCells.lower_bound(el);
          while(ghost!= ghostsCells.end() && ghost->first==el){
            if(abs(ghost->second)-1==Msg::GetCommRank()){
              ghostElements[el->getPartition()-1][el->getType()].push_back(el);
              nghosts+=1;
            }
            ghost++;
          }
        }
      }
    }
  }


  for (int i=0;i<_elementGroups.size();i++){
    // create a group of faces on the boundary for every group of elements
    switch(dim) {
    case 1 : {
      std::map<const std::string, std::set<MVertex*> >::iterator mapIt;
      for(mapIt=boundaryVertices.begin(); mapIt!=boundaryVertices.end(); mapIt++) {
        dgGroupOfFaces *gof = new dgGroupOfFaces(*_elementGroups[i],mapIt->first,order,mapIt->second);
        if (gof->getNbElements())
          _boundaryGroups.push_back(gof);
        else
          delete gof;
        break;
      }
    }
    case 2 : {
      std::map<const std::string, std::set<MEdge, Less_Edge> >::iterator mapIt;
      for(mapIt=boundaryEdges.begin(); mapIt!=boundaryEdges.end(); mapIt++) {
      dgGroupOfFaces *gof=new dgGroupOfFaces(*_elementGroups[i],mapIt->first,order,mapIt->second);
        if(gof->getNbElements())
          _boundaryGroups.push_back(gof);
        else
          delete gof;
      }
      break;
    }
    case 3 : {
    std::map<const int,std::map<const std::string,std::set<MFace, Less_Face> > >::iterator elemTypeIt;
    std::map<const std::string, std::set<MFace, Less_Face> >::iterator mapIt;
      for(elemTypeIt=boundaryFaces.begin(); elemTypeIt!=boundaryFaces.end(); elemTypeIt++) {
        for(mapIt=elemTypeIt->second.begin(); mapIt!=elemTypeIt->second.end(); mapIt++) {
          dgGroupOfFaces *gof=new dgGroupOfFaces(*_elementGroups[i],mapIt->first,order,mapIt->second);
          if(gof->getNbElements())
            _boundaryGroups.push_back(gof);
          else
            delete gof;
        }
      }
      break;
    }
    }
    // create a group of faces for every face that is common to elements of the same group
    // create separate groups for each face type
    for(std::set<int>::iterator faceTypeIt=_interfaceTypes.begin(); faceTypeIt!=_interfaceTypes.end(); faceTypeIt++) {
      dgGroupOfFaces *gof = new dgGroupOfFaces(*_elementGroups[i],order,*faceTypeIt);
      if (gof->getNbElements())
        _faceGroups.push_back(gof);
      else
        delete gof;
//       create a groupe of d
      for (int j=i+1;j<_elementGroups.size();j++){
        dgGroupOfFaces *gof = new dgGroupOfFaces(*_elementGroups[i],*_elementGroups[j],order,*faceTypeIt);
        if (gof->getNbElements())
          _faceGroups.push_back(gof);
        else
          delete gof;
      }
    }
  }

/////////////////// GHOSTS
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
  //create face group for ghostGroups
  for (int i=0; i<_ghostGroups.size(); i++){
    for (int j=0;j<_elementGroups.size();j++){
      for(std::set<int>::iterator faceTypeIt=_interfaceTypes.begin(); faceTypeIt!=_interfaceTypes.end(); faceTypeIt++) {
        dgGroupOfFaces *gof = new dgGroupOfFaces(*_ghostGroups[i],*_elementGroups[j],order,*faceTypeIt);
        if (gof->getNbElements())
          _faceGroups.push_back(gof);
        else
          delete gof;
      }
    }
  }
  Msg::Info("%d groups of interfaces",_faceGroups.size());
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
double dgGroupCollection::splitGroupsForMultirate(int maxLevels,dgConservationLaw *claw, dgDofContainer *solution) {
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
    for(int iConn=0;iConn<interface.connectedElements.size();iConn++){
      int gIdi=interface.connectedElements[iConn].first;
      int eIdi=interface.connectedElements[iConn].second;
      for(int jConn=0;jConn<iConn;jConn++){
        int gIdj=interface.connectedElements[jConn].first;
        int eIdj=interface.connectedElements[jConn].second;
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
      int _lowerLevelGroupIdStart=lowerLevelGroupIdStart;
      int _lowerLevelGroupIdEnd=lowerLevelGroupIdEnd;
      lowerLevelGroupIdStart=lowerLevelGroupIdEnd;
      for(int iInterface=0;iInterface<miniInterfaceV->size();iInterface++){
        dgMiniInterface &interface=miniInterfaceV->at(iInterface);
        bool toAdd=false;
        // if one of the elements adjacent to the interface is mapped to the previous level
        // we check all elements adjacent to this interface, and add those that does not
        // already have a new group to the current new group
        for(int iConn=0;iConn<interface.connectedElements.size();iConn++){
          int gId=interface.connectedElements[iConn].first;
          int eId=interface.connectedElements[iConn].second;
          int newGroupId=newGroupIds[gId][eId];
          if(newGroupId >= _lowerLevelGroupIdStart && newGroupId<_lowerLevelGroupIdEnd){
            toAdd=true;
            continue;
          }
        }
        if(toAdd){
          for(int iConn=0;iConn<interface.connectedElements.size();iConn++){
            int gId=interface.connectedElements[iConn].first;
            int eId=interface.connectedElements[iConn].second;
            int newGroupId=newGroupIds[gId][eId];
            if(newGroupId==-1){
              mapNewGroups[gId].push_back(eId);
              newGroupIds[gId][eId]=-2;
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
      for (std::map<int, std::vector<int> >::iterator it = mapNewGroups.begin(); it !=mapNewGroups.end() ; ++it){
        if(!it->second.empty()){
          std::vector<int>forBulk;
          std::vector<int>forInnerBuffer;
          for(int i=0;i<it->second.size();i++){
            bool inInnerBuffer=false;
            int oldGId=it->first;
            int oldEId=it->second[i];
            for(int iNeighbor=0;iNeighbor<elementToNeighbors[oldGId][oldEId].size();iNeighbor++){
              std::pair<int,int> neighIds=elementToNeighbors[oldGId][oldEId][iNeighbor];
              if(newGroupIds[neighIds.first][neighIds.second]==-1){
                inInnerBuffer=true;
                continue;
              }
            }
            if(inInnerBuffer){
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
            newGroup=new dgGroupOfElements(forBulkV,oldGroup->getOrder(),oldGroup->getGhostPartition());
            newGroup->copyPrivateDataFrom(oldGroup);
            newGroup->_multirateExponent=currentExponent;
            newGroup->_multirateOuterBuffer=false;
            newGroup->_multirateInnerBuffer=false;
            newGroups.resize(currentNewGroupId+1);
            newGroups[currentNewGroupId]=newGroup;
            currentNewGroupId++;
          }

          if(!forInnerBuffer.empty()){
            std::vector<MElement*>forInnerBufferV;
            for(int i=0;i<forInnerBuffer.size();i++){
              forInnerBufferV.push_back(getElementGroup(it->first)->getElement(forInnerBuffer[i]));
            }
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
    Msg::Info("%d New group # %d has %d elements",newGroups[i]->getMultirateExponent(),i,newGroups[i]->getNbElements());
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


dgGroupCollection::dgGroupCollection()
{
  _groupsOfElementsBuilt=false;_groupsOfInterfacesBuilt=false;
}
dgGroupCollection::dgGroupCollection(GModel *model, int dimension, int order)
{
  _groupsOfElementsBuilt=false;_groupsOfInterfacesBuilt=false;
  buildGroupsOfElements(model,dimension,order);
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
  cm->setArgNames("maxLevels","claw","solution",NULL);
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
