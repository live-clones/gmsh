#include "GmshConfig.h"
#include "dgGroupOfElements.h"
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


dgGroupOfElements::dgGroupOfElements(const std::vector<MElement*> &e, int polyOrder,int ghostPartition)
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
  int closureIdLeft = _fsLeft->getFaceClosureId(ithFace, sign, rot);
  _closuresIdLeft.push_back(closureIdLeft);
  if(iElRight>=0){
    _right.push_back(iElRight);
    MElement &elRight = *_groupRight.getElement(iElRight);
    elRight.getFaceInfo (topoFace, ithFace, sign, rot);
    _closuresIdRight.push_back(_fsRight->getFaceClosureId(ithFace, sign, rot));        
  }
  // compute the face element that correspond to the geometrical closure
  // get the vertices of the face
  std::vector<MVertex*> vertices;
  const std::vector<int> & geomClosure = elLeft.getFunctionSpace()->getFaceClosure(closureIdLeft);
  for (int j=0; j<geomClosure.size() ; j++)
    vertices.push_back( elLeft.getVertex(geomClosure[j]) );
  // triangular face
  if (topoFace.getNumVertices() == 3){
    switch(vertices.size()){
    case 3  : _faces.push_back(new MTriangle   (vertices) ); break;
    case 6  : _faces.push_back(new MTriangle6  (vertices) ); break;
    case 10  : _faces.push_back(new MTriangleN (vertices,3) ); break;
    case 15  : _faces.push_back(new MTriangleN (vertices,4) ); break;
    case 21  : _faces.push_back(new MTriangleN (vertices,5) ); break;
    default : throw;
    }
  }
  else if (topoFace.getNumVertices() == 4){
    switch(vertices.size()){
      case 4  : _faces.push_back(new MQuadrangle (vertices) ); break;
      case 8  : _faces.push_back(new MQuadrangle8 (vertices) ); break;
      case 9  : _faces.push_back(new MQuadrangle9 (vertices) ); break;
      case 16 : _faces.push_back(new MQuadrangleN (vertices, 4)); break;
      case 25 : _faces.push_back(new MQuadrangleN (vertices, 5)); break;
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
  switch(vertices.size())
    {
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
  if (!_faces.size())return;
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
  _normals = new fullMatrix<double> (3,_integration->size1()*_faces.size());
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
  // (iQP*3+iXYZ , iFace*NPsi+iPsi)
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
	  int inode=closureLeft[k];
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
  if (!_faces.size())return;
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

dgGroupOfFaces::dgGroupOfFaces (const dgGroupOfElements &elGroup1, const dgGroupOfElements &elGroup2, int pOrder):
  _groupLeft(elGroup1),_groupRight(elGroup2)
{
  _fsLeft=_groupLeft.getElement(0)->getFunctionSpace(pOrder);
  _fsRight=_groupRight.getElement(0)->getFunctionSpace(pOrder);
  switch (_groupLeft.getElement(0)->getDim()) {
    case 1 : {
      std::map<MVertex*,int> vertexMap1;
      _closuresLeft = _fsLeft->vertexClosure;
      _closuresRight = _fsRight->vertexClosure;
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

      for(int i=0; i<elGroup2.getNbElements(); i++){
        MElement &el = *elGroup2.getElement(i);
        for (int j=0; j<el.getNumVertices(); j++){
          MVertex* vertex = el.getVertex(j);
	  std::map<MVertex*,int>::iterator it = vertexMap1.find(vertex);
	  if(it != vertexMap1.end()){
	    addVertex(vertex,it->second,i);
	  }
        }
      }      
    }
    break;
    case 2 : {
      std::map<MEdge,int,Less_Edge> edgeMap;
      _closuresLeft = _fsLeft->edgeClosure;
      _closuresRight = _fsRight->edgeClosure;
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
// 	    MElement &el2 = *elGroup1.getElement(it->second);
// 	    printf("%d %d \n",edge.getVertex(0)->getNum(),edge.getVertex(1)->getNum());
// 	    for (int k=0;k<el.getNumVertices();k++)printf("%d ",el.getVertex(k)->getNum());
// 	    printf("\n");
// 	    for (int k=0;k<el2.getNumVertices();k++)printf("%d ",el2.getVertex(k)->getNum());
// 	    printf("\n");
	    addEdge(edge,it->second,i);
          }
        }
      }
      
      break;
    }
    case 3 : {
      std::map<MFace,int,Less_Face> faceMap;
      _closuresLeft = _fsLeft->faceClosure;
      _closuresRight = _fsRight->faceClosure;
      for(int i=0; i<elGroup1.getNbElements(); i++){
        MElement &el = *elGroup1.getElement(i);
        for (int j=0; j<el.getNumFaces(); j++){
          MFace face = el.getFace(j);
          if(faceMap.find(face) == faceMap.end()){
            faceMap[face] = i;
          }else{
            faceMap.erase(face);
          }
        }
      }
      for(int i=0; i<elGroup2.getNbElements(); i++){
        MElement &el = *elGroup2.getElement(i);
        for (int j=0; j<el.getNumFaces(); j++){
          MFace face = el.getFace(j);
	  std::map<MFace,int,Less_Face>::iterator it = faceMap.find(face);
	  if(it != faceMap.end()){
	    addFace(face,it->second,i);
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

/*
void dgAlgorithm::buildGroupsOfFaces(GModel *model, int dim, int order,
				     std::vector<dgGroupOfElements*> &eGroups,
				     std::vector<dgGroupOfFaces*> &fGroups,
				     std::vector<dgGroupOfFaces*> &bGroups){
}

void dgAlgorithm::buildMandatoryGroups(dgGroupOfElements &eGroup,
				       std::vector<dgGroupOfElements*> &partitionedGroups){
}

void dgAlgorithm::partitionGroup(dgGroupOfElements &eGroup,
				 std::vector<dgGroupOfElements*> &partitionedGroups){
}
*/

//static void partitionGroup (std::vector<MElement *>,){
//}

// this function creates groups of elements
// First, groups of faces are created on every physical group
// of dimension equal to the dimension of the problem minus one
// Then, groups of elements are created 
//  -) Elements of different types are separated
//  -) Then those groups are split into partitions
//  -) Finally, those groups are re-numbered 
// Finally, group of interfaces are created
//  -) Groups of faces internal to a given group
//  -) Groups of faces between groups.
 
void dgGroupCollection::buildGroups(GModel *model, int dim, int order)
{
  _model = model;
  std::map<const std::string,std::set<MVertex*> > boundaryVertices;
  std::map<const std::string,std::set<MEdge, Less_Edge> > boundaryEdges;
  std::map<const std::string,std::set<MFace, Less_Face> > boundaryFaces;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::map<int, std::vector<MElement *> >localElements;
  std::vector<std::map<int, std::vector<MElement *> > >ghostElements(Msg::GetCommSize()); // [partition][elementType]
  int nlocal=0;
  int nghosts=0;
  std::multimap<MElement*, short> &ghostsCells = model->getGhostCells();
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    if(entity->dim() == dim-1){
      for(unsigned int j = 0; j < entity->physicals.size(); j++){
        const std::string physicalName = model->getPhysicalName(entity->dim(), entity->physicals[j]);
        for (int k = 0; k < entity->getNumMeshElements(); k++) {
          MElement *element = entity->getMeshElement(k);
          switch(dim) {
            case 1:
              boundaryVertices[physicalName].insert( element->getVertex(0) ); 
              break;
            case 2:
              boundaryEdges[physicalName].insert( element->getEdge(0) );
            break;
            case 3:
              boundaryFaces[physicalName].insert( element->getFace(0));
            break;
            default :
            throw;
          }
        }
      }
    }else if(entity->dim() == dim){
      for (int iel=0; iel<entity->getNumMeshElements(); iel++){
        MElement *el=entity->getMeshElement(iel);
        if(el->getPartition()==Msg::GetCommRank()+1 || el->getPartition()==0){
          localElements[el->getType()].push_back(el);
          nlocal++;
        }else{
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


  Msg::Info("%d groups of elements",localElements.size());
  // do a group of elements for every element type in the mesh
  for (std::map<int, std::vector<MElement *> >::iterator it = localElements.begin(); it !=localElements.end() ; ++it){
    _elementGroups.push_back(new dgGroupOfElements(it->second,order));
  }


  for (int i=0;i<_elementGroups.size();i++){
    // create a group of faces on the boundary for every group ef elements
    switch(dim) {
    case 1 : {
      std::map<const std::string, std::set<MVertex*> >::iterator mapIt;
      for(mapIt=boundaryVertices.begin(); mapIt!=boundaryVertices.end(); mapIt++) {
        _boundaryGroups.push_back(new dgGroupOfFaces(*_elementGroups[i],mapIt->first,order,mapIt->second));
      }
      break;
    }
    case 2 : {
      std::map<const std::string, std::set<MEdge, Less_Edge> >::iterator mapIt;
      for(mapIt=boundaryEdges.begin(); mapIt!=boundaryEdges.end(); mapIt++) {
        _boundaryGroups.push_back(new dgGroupOfFaces(*_elementGroups[i],mapIt->first,order,mapIt->second));
      }
      break;
    }
    case 3 : {
      std::map<const std::string, std::set<MFace, Less_Face> >::iterator mapIt;
      for(mapIt=boundaryFaces.begin(); mapIt!=boundaryFaces.end(); mapIt++) {
        _boundaryGroups.push_back(new dgGroupOfFaces(*_elementGroups[i],mapIt->first,order,mapIt->second));
      }
      break;
    }
    }
    // create a group of faces for every face that is common to elements of the same group 
    _faceGroups.push_back(new dgGroupOfFaces(*_elementGroups[i],order));
    // create a groupe of d
    for (int j=i+1;j<_elementGroups.size();j++){
      dgGroupOfFaces *gof = new dgGroupOfFaces(*_elementGroups[i],*_elementGroups[j],order);
      if (gof->getNbElements())
        _faceGroups.push_back(gof);
      else
        delete gof;
    }
  }
  //create ghost groups
  for(int i=0;i<Msg::GetCommSize();i++){
    for (std::map<int, std::vector<MElement *> >::iterator it = ghostElements[i].begin(); it !=ghostElements[i].end() ; ++it){
      _ghostGroups.push_back(new dgGroupOfElements(it->second,order,i));
    }
  }
  //create face group for ghostGroups
  for (int i=0; i<_ghostGroups.size(); i++){
    for (int j=0;j<_elementGroups.size();j++){
      dgGroupOfFaces *gof = new dgGroupOfFaces(*_ghostGroups[i],*_elementGroups[j],order);
      if (gof->getNbElements())
        _faceGroups.push_back(gof);
      else
        delete gof;
    }
  }

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
  MPI_Alltoallv(idSend,nGhostElements,shiftSend,MPI_INT,idRecv,nParentElements,shiftRecv,MPI_INT,MPI_COMM_WORLD);
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

dgGroupCollection::~dgGroupCollection() {
  for (int i=0; i< _elementGroups.size(); i++)
    delete _elementGroups[i];
  for (int i=0; i< _faceGroups.size(); i++)
    delete _faceGroups[i];
  for (int i=0; i< _boundaryGroups.size(); i++)
    delete _boundaryGroups[i];
  for (int i=0; i< _ghostGroups.size(); i++)
    delete _ghostGroups[i];
}
