#include "dgGroupOfElements.h"
#include "MElement.h"
#include "polynomialBasis.h"
#include "Numeric.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"
#include "GModel.h"

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


dgGroupOfElements::dgGroupOfElements(const std::vector<MElement*> &e, int polyOrder)
  : _elements(e), 
   _fs(*_elements[0]->getFunctionSpace(polyOrder)),
   _integration(dgGetIntegrationRule (_elements[0], polyOrder))
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
  double g[256][3],f[256];

  for (int i=0;i<_elements.size();i++){
    MElement *e = _elements[i];
    fullMatrix<double> imass(*_imass,nbPsi*i,nbPsi);
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


void dgGroupOfFaces::addFace(const MFace &topoFace, int iElLeft, int iElRight){
  // compute all closures
  // compute closures for the interpolation
  _left.push_back(iElLeft);
  MElement &elLeft = *_groupLeft.getElement(iElLeft);
  int ithFace, sign, rot;
  elLeft.getFaceInfo (topoFace, ithFace, sign, rot);
  _closuresIdLeft.push_back(_fsLeft->getFaceClosureId(ithFace, sign, rot));
  if(iElRight>=0){
    _right.push_back(iElRight);
    MElement &elRight = *_groupRight.getElement(iElRight);
    elRight.getFaceInfo (topoFace, ithFace, sign, rot);
    _closuresIdRight.push_back(_fsRight->getFaceClosureId(ithFace, sign, rot));        
  }
  // compute the face element that correspond to the geometrical closure
  // get the vertices of the face
  std::vector<MVertex*> vertices;
  const std::vector<int> & geomClosure = elLeft.getFunctionSpace()->getFaceClosure(_closuresIdLeft.back());
  for (int j=0; j<geomClosure.size() ; j++)
    vertices.push_back( elLeft.getVertex(geomClosure[j]) );
  // triangular face
  printf("the topological face has %d vertices and the geometrical %d\n",topoFace.getNumVertices(),vertices.size());
  if (topoFace.getNumVertices() == 3){
    switch(vertices.size()){
      case 3  : _faces.push_back(new MTriangle (vertices) ); break;
      case 6  : _faces.push_back(new MTriangle6 (vertices) ); break;
      case 10 : _faces.push_back(new MTriangleN (vertices, 3) ); break;
      case 15 : _faces.push_back(new MTriangleN (vertices, 4) ); break;
      case 21 : _faces.push_back(new MTriangleN (vertices, 5) ); break;
      default : throw;
    }
  }
  // quad face 2 do
  else {
    throw;
  }
}

void dgGroupOfFaces::addEdge(const MEdge &topoEdge, int iElLeft, int iElRight) {
  _left.push_back(iElLeft);
  MElement &elLeft = *_groupLeft.getElement(iElLeft);
  int ithEdge, sign;
  elLeft.getEdgeInfo (topoEdge, ithEdge, sign);
  _closuresIdLeft.push_back(_fsLeft->getEdgeClosureId(ithEdge, sign));
  if(iElRight>=0) {
    _right.push_back(iElRight);
    _groupRight.getElement(iElRight)->getEdgeInfo (topoEdge, ithEdge, sign);
    _closuresIdRight.push_back(_fsRight->getEdgeClosureId(ithEdge,sign));
  }
  std::vector<MVertex*> vertices;
  const std::vector<int> &geomClosure = elLeft.getFunctionSpace()->getEdgeClosure(_closuresIdLeft.back());
  for (int j=0; j<geomClosure.size() ; j++)
    vertices.push_back( elLeft.getVertex(geomClosure[j]) );
  switch(vertices.size()){
    case 2  : _faces.push_back(new MLine (vertices) ); break;
    case 3  : _faces.push_back(new MLine3 (vertices) ); break;
    default : _faces.push_back(new MLineN (vertices) ); break;
  }
}

void dgGroupOfFaces::addVertex(MVertex *topoVertex, int iElLeft, int iElRight){
  _left.push_back(iElLeft);
  MElement &elLeft = *_groupLeft.getElement(iElLeft);
  int ithVertex;
  elLeft.getVertexInfo (topoVertex, ithVertex);
  _closuresIdLeft.push_back(ithVertex);
  if(iElRight>=0){
    _right.push_back(iElRight);
    MElement &elRight = *_groupRight.getElement(iElRight);
    elRight.getVertexInfo (topoVertex, ithVertex);
    _closuresIdRight.push_back(ithVertex);
  }
  _faces.push_back(new MPoint(topoVertex) );
}

void dgGroupOfFaces::init(int pOrder) {
  _fsFace = _faces[0]->getFunctionSpace (pOrder);
  _integration = dgGetIntegrationRule (_faces[0],pOrder);
  _redistribution = new fullMatrix<double> (_fsFace->coefficients.size1(),_integration->size1());
  _collocation = new fullMatrix<double> (_integration->size1(), _fsFace->coefficients.size1());
  _detJac = new fullMatrix<double> (_integration->size1(), _faces.size());
  _interfaceSurface = new fullMatrix<double>(_faces.size(),1);
  for (size_t i=0; i<_closuresLeft.size(); i++)
    _integrationPointsLeft.push_back(dgGetFaceIntegrationRuleOnElement(_fsFace,*_integration,_fsLeft,_closuresLeft[i]));
  for (size_t i=0; i<_closuresRight.size(); i++)
    _integrationPointsRight.push_back(dgGetFaceIntegrationRuleOnElement(_fsFace,*_integration,_fsRight,_closuresRight[i]));
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

  // compute data on quadrature points : normals and dPsidX
  double g[256][3];
  _normals = new fullMatrix<double> (3,_fsFace->points.size1()*_faces.size());
  _dPsiLeftDxOnQP = new fullMatrix<double> ( _integration->size1()*3,_fsLeft->points.size1()*_faces.size());
  if(_fsRight){
    _dPsiRightDxOnQP = new fullMatrix<double> ( _integration->size1()*3,_fsRight->points.size1()*_faces.size());
  }
  int index = 0;
  for (size_t i=0; i<_faces.size();i++){
    const std::vector<int> &closureLeft=getClosureLeft(i);
    fullMatrix<double> &intLeft=_integrationPointsLeft[_closuresIdLeft[i]];
    double jac[3][3],ijac[3][3];
    for (int j=0; j<intLeft.size1(); j++){
      _fsLeft->df((intLeft)(j,0),(intLeft)(j,1),(intLeft)(j,2),g);
      getElementLeft(i)->getJacobian ((intLeft)(j,0), (intLeft)(j,1), (intLeft)(j,2), jac);
      inv3x3(jac,ijac);
      //compute dPsiLeftDxOnQP
      //(iPsi*3+iXYZ,iQP+iFace*NQP);
      int nPsi = _fsLeft->coefficients.size1();
      for (int iPsi=0; iPsi< nPsi; iPsi++) {
        (*_dPsiLeftDxOnQP)(j*3  ,i*nPsi+iPsi) = g[iPsi][0]*ijac[0][0]+g[iPsi][1]*ijac[0][1]+g[iPsi][2]*ijac[0][2];
        (*_dPsiLeftDxOnQP)(j*3+1,i*nPsi+iPsi) = g[iPsi][0]*ijac[1][0]+g[iPsi][1]*ijac[1][1]+g[iPsi][2]*ijac[1][2];
        (*_dPsiLeftDxOnQP)(j*3+2,i*nPsi+iPsi) = g[iPsi][0]*ijac[2][0]+g[iPsi][1]*ijac[2][1]+g[iPsi][2]*ijac[2][2];
      }
      //compute face normals
      double &nx=(*_normals)(0,index);
      double &ny=(*_normals)(1,index);
      double &nz=(*_normals)(2,index);
      double nu=0,nv=0,nw=0;
      for (size_t k=0; k<closureLeft.size(); k++){
        nu += g[closureLeft[k]][0];
        nv += g[closureLeft[k]][1];
        nw += g[closureLeft[k]][2];
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
    // there is nothing on the right for boundary groups
    if(_fsRight){
      fullMatrix<double> &intRight=_integrationPointsRight[_closuresIdRight[i]];
      for (int j=0; j<intRight.size1(); j++){
        _fsRight->df((intRight)(j,0),(intRight)(j,1),(intRight)(j,2),g);
        getElementRight(i)->getJacobian ((intRight)(j,0), (intRight)(j,1), (intRight)(j,2), jac);
        inv3x3(jac,ijac);
        //compute dPsiRightDxOnQP
        // (iQP*3+iXYZ , iFace*NPsi+iPsi)
        int nPsi = _fsRight->coefficients.size1();
        for (int iPsi=0; iPsi< nPsi; iPsi++) {
          (*_dPsiRightDxOnQP)(j*3  ,i*nPsi+iPsi) = g[iPsi][0]*ijac[0][0]+g[iPsi][1]*ijac[0][1]+g[iPsi][2]*ijac[0][2];
          (*_dPsiRightDxOnQP)(j*3+1,i*nPsi+iPsi) = g[iPsi][0]*ijac[1][0]+g[iPsi][1]*ijac[1][1]+g[iPsi][2]*ijac[1][2];
          (*_dPsiRightDxOnQP)(j*3+2,i*nPsi+iPsi) = g[iPsi][0]*ijac[2][0]+g[iPsi][1]*ijac[2][1]+g[iPsi][2]*ijac[2][2];
        }
      }
    }
  }
}

dgGroupOfFaces::~dgGroupOfFaces()
{
  delete _redistribution;
  delete _collocation;
  delete _detJac;
  delete _normals;
  delete _dPsiLeftDxOnQP;
  delete _dPsiRightDxOnQP;
  delete _interfaceSurface;
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MVertex*> &boundaryVertices):
  _groupLeft(elGroup),_groupRight(elGroup)
{
  _boundaryTag=boundaryTag;
  if(boundaryTag=="")
    throw;
  _fsLeft=_groupLeft.getElement(0)->getFunctionSpace(pOrder);
  _closuresLeft = _fsLeft->vertexClosure;
  _fsRight=NULL;
  for(int i=0; i<elGroup.getNbElements(); i++){
    MElement &el = *elGroup.getElement(i);
    for (int j=0; j<el.getNumVertices(); j++){
      MVertex* vertex = el.getVertex(j);
      if(boundaryVertices.find(vertex)!=boundaryVertices.end())
        addVertex(vertex,i,-1);
    }
  }
  init(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MEdge,Less_Edge> &boundaryEdges):
  _groupLeft(elGroup),_groupRight(elGroup)
{
  _boundaryTag=boundaryTag;
  if(boundaryTag=="")
    throw;
  _fsLeft=_groupLeft.getElement(0)->getFunctionSpace(pOrder);
  _closuresLeft = _fsLeft->edgeClosure;
  _fsRight=NULL;
  for(int i=0; i<elGroup.getNbElements(); i++){
    MElement &el = *elGroup.getElement(i);
    for (int j=0; j<el.getNumEdges(); j++){
      MEdge edge = el.getEdge(j);
      if(boundaryEdges.find(edge)!=boundaryEdges.end())
        addEdge(edge,i,-1);
    }
  }
  init(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MFace,Less_Face> &boundaryFaces):
  _groupLeft(elGroup),_groupRight(elGroup)
{
  _boundaryTag=boundaryTag;
  if(boundaryTag=="")
    throw;
  _fsLeft=_groupLeft.getElement(0)->getFunctionSpace(pOrder);
  _closuresLeft = _fsLeft->faceClosure;
  _fsRight=NULL;
  for(int i=0; i<elGroup.getNbElements(); i++){
    MElement &el = *elGroup.getElement(i);
    for (int j=0; j<el.getNumFaces(); j++){
      MFace face = el.getFace(j);
      if(boundaryFaces.find(face)!=boundaryFaces.end())
        addFace(face,i,-1);
    }
  }
  init(pOrder);
}

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup, int pOrder):
  _groupLeft(elGroup),_groupRight(elGroup)
{
  _fsLeft=_groupLeft.getElement(0)->getFunctionSpace(pOrder);
  _fsRight=_groupRight.getElement(0)->getFunctionSpace(pOrder);
  switch (_groupLeft.getElement(0)->getDim()) {
    case 1 : {
      std::map<MVertex*,int> vertexMap;
      _closuresLeft = _fsLeft->vertexClosure;
      _closuresRight = _fsRight->vertexClosure;
      for(int i=0; i<elGroup.getNbElements(); i++){
        MElement &el = *elGroup.getElement(i);
        for (int j=0; j<el.getNumVertices(); j++){
          MVertex* vertex = el.getVertex(j);
          if(vertexMap.find(vertex) == vertexMap.end()){
            vertexMap[vertex] = i;
          }else{
            addVertex(vertex,vertexMap[vertex],i);
          }
        }
      }
      break;
    }
    case 2 : {
      std::map<MEdge,int,Less_Edge> edgeMap;
      _closuresLeft = _fsLeft->edgeClosure;
      _closuresRight = _fsRight->edgeClosure;
      for(int i=0; i<elGroup.getNbElements(); i++){
        MElement &el = *elGroup.getElement(i);
        for (int j=0; j<el.getNumEdges(); j++){
          MEdge edge = el.getEdge(j);
          if(edgeMap.find(edge) == edgeMap.end()){
            edgeMap[edge] = i;
          }else{
            addEdge(edge,edgeMap[edge],i);
          }
        }
      }
      break;
    }
    case 3 : {
      std::map<MFace,int,Less_Face> faceMap;
      _closuresLeft = _fsLeft->faceClosure;
      _closuresRight = _fsRight->faceClosure;
      for(int i=0; i<elGroup.getNbElements(); i++){
        MElement &el = *elGroup.getElement(i);
        for (int j=0; j<el.getNumFaces(); j++){
          MFace face = el.getFace(j);
          if(faceMap.find(face) == faceMap.end()){
            faceMap[face] = i;
          }else{
            addFace(face,faceMap[face],i);
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
          v(j, i*nFields + iField) = vLeft(closureLeft[j], _left[i]*nFields + iField);
        }
      }
    }
    
  }else{
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureRight = getClosureRight(i);
      const std::vector<int> &closureLeft = getClosureLeft(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++){
          v(j, i*2*nFields + iField) = vLeft(closureLeft[j], _left[i]*nFields + iField);
        }
        for(size_t j =0; j < closureRight.size(); j++)
          v(j, (i*2+1)*nFields + iField) = vRight(closureRight[j], _right[i]*nFields + iField);
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
          vLeft(closureLeft[j], _left[i]*nFields + iField) += v(j, i*nFields + iField);
      }
    }
  }else{
    for(int i=0; i<getNbElements(); i++) {
      const std::vector<int> &closureRight = getClosureRight(i);
      const std::vector<int> &closureLeft = getClosureLeft(i);
      for (int iField=0; iField<nFields; iField++){
        for(size_t j =0; j < closureLeft.size(); j++)
          vLeft(closureLeft[j], _left[i]*nFields + iField) += v(j, i*2*nFields + iField);
        for(size_t j =0; j < closureRight.size(); j++)
          vRight(closureRight[j], _right[i]*nFields + iField) += v(j, (i*2+1)*nFields + iField);
      }
    }
  }
}

