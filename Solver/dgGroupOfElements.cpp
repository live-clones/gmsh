#include "dgGroupOfElements.h"
#include "MElement.h"
#include "functionSpace.h"


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


// _collocation(i,j) = fs(i)(point(j))
static fullMatrix<double> * dgGetCollocation (const functionSpace &fs, 
					      fullMatrix<double> *intg){
  fullMatrix<double> *m = new fullMatrix<double> (fs.coefficients.size1(), 
						  intg->size1());
  double *sf = new double [fs.coefficients.size1()];
  for (int i=0;i<intg->size1();i++){
    fs.f((*intg)(i,0),(*intg)(i,1),(*intg)(i,2),sf);
    for (int j=0;j<fs.coefficients.size1();j++){
      (*m)(j,i) = sf[j];
    }
  }  
  delete [] sf;
  return m;
}



dgGroupOfElements::dgGroupOfElements(const std::vector<MElement*> &e, int polyOrder)
  : _elements(e), 
    _fs(_elements[0]->getFunctionSpace(polyOrder)),
    _integration(dgGetIntegrationRule (_elements[0], polyOrder)),
    _collocation(dgGetCollocation(_fs,_integration))    
{
  // this is the biggest piece of data ... the mappings
  _mapping = new fullMatrix<double> (_elements.size(), 10 * _integration->size1());
  for (int i=0;i<_elements.size();i++){
    MElement *e = _elements[i];
    for (int j=0;j< _integration->size1() ; j++ ){
      double ijac[3][3];
      (*_mapping)(i,10*j + 9) =  
	e->getJacobian ((*_integration)(j,0),
			(*_integration)(j,1),
			(*_integration)(j,2),
			ijac);
      (*_mapping)(i,10*j + 0) = ijac[0][0]; 
      (*_mapping)(i,10*j + 1) = ijac[0][1]; 
      (*_mapping)(i,10*j + 2) = ijac[0][2]; 
      (*_mapping)(i,10*j + 3) = ijac[1][0]; 
      (*_mapping)(i,10*j + 4) = ijac[1][1]; 
      (*_mapping)(i,10*j + 5) = ijac[1][2]; 
      (*_mapping)(i,10*j + 6) = ijac[2][0]; 
      (*_mapping)(i,10*j + 7) = ijac[2][1]; 
      (*_mapping)(i,10*j + 8) = ijac[2][2]; 
    }
  }
  // redistribution matrix
  // quadrature weight x parametric gradients in quadrature points

  _redistribution[0] = new fullMatrix<double> (_fs.coefficients.size1(),_integration->size1());
  _redistribution[1] = new fullMatrix<double> (_fs.coefficients.size1(),_integration->size1());
  _redistribution[2] = new fullMatrix<double> (_fs.coefficients.size1(),_integration->size1());

  double g[256][3];
  
  for (int j=0;j<_integration->size1();j++) {
    _fs.df((*_integration)(j,0),
	   (*_integration)(j,1),
	   (*_integration)(j,2), g);
    const double weight = (*_integration)(j,3);
    for (int k=0;k<_fs.coefficients.size1();k++){ 
      (*_redistribution[0])(k,j) = g[j][0] * weight;
      (*_redistribution[1])(k,j) = g[j][1] * weight;
      (*_redistribution[2])(k,j) = g[j][2] * weight;
    }
  }
}

dgGroupOfElements::~dgGroupOfElements(){
  delete _integration;
  delete _redistribution[0];
  delete _redistribution[1];
  delete _redistribution[2];
  delete _mapping;
  delete _collocation;
}


// dgGroupOfFaces
void dgGroupOfFaces::dgCreateFaceElements (const std::vector<MFace> &topo_faces){
  
  _faces.resize(topo_faces.size());
  // compute all closures
  for (int i=0;i<topo_faces.size();i++){
    // compute closures for the interpolation
    int ithFace, sign, rot;
    _left[i]->getFaceInfo (topo_faces[i], ithFace, sign, rot);
    _closuresLeft.push_back(&(_fsLeft.getFaceClosure(ithFace, sign, rot)));
    _right[i]->getFaceInfo (topo_faces[i], ithFace, sign, rot);
    _closuresRight.push_back(&(_fsRight.getFaceClosure(ithFace, sign, rot)));        
    // compute the face element that correspond to the geometrical closure
    // get the vertices of the face
    std::vector<MVertex*> _vertices;
    std::vector<int> & geomClosure = _right[i]->getFunctionSpace().getFaceClosure(ithFace, sign, rot);
    for (int j=0; j<geomClosure.size() ; j++){
      int iNod = geomClosure[j];
      MVertex *v = _left[i]->getVertex(iNod);
      _vertices.push_back(v);
    }
    // triangular face
    if (topo_faces[i]->getNumVertices() == 3){
      switch(_vertices.size()){
      case 3  : _faces.push_back(new MTriangle (_vertices) ); break;
      case 6  : _faces.push_back(new MTriangle2 (_vertices) ); break;
      case 10 : _faces.push_back(new MTriangleN (_vertices, 3) ); break;
      case 15 : _faces.push_back(new MTriangleN (_vertices, 4) ); break;
      case 21 : _faces.push_back(new MTriangleN (_vertices, 5) ); break;
      default : throw;
      }
    }
    // quad face 2 do
    else throw;
  }  
}

// dgGroupOfFaces
void dgGroupOfFaces::dgCreateFaceElements (const std::vector<MEdge> &topo_edges){
  
  _faces.resize(topo_edges.size());
  // compute all closures
  for (int i=0;i<topo_edges.size();i++){
    int ithEdge, sign;
    _left[i]->getEdgeInfo (topo_edges[i], ithEdge, sign);
    _closuresLeft.push_back(&(_fsLeft->getEdgeClosure(ithEdge, sign)));
    _right[i]->getEdgeInfo (topo_edges[i], ithEdge, sign);
    _closuresRight.push_back(&(_fsRight->getEdgeClosure(ithEdge, sign)));    
    // get the vertices of the edge
    std::vector<int> & geomClosure = _right[i]->getFunctionSpace().getEdgeClosure(ithFace, sign);
    std::vector<MVertex*> _vertices;
    for (int j=0; j<geomClosure.size() ; j++){
      int iNod = geomClosure[j];
      MVertex *v = _left[i]->getVertex(iNod);
      _vertices.push_back(v);
    }
    switch(_vertices.size()){
    case 2  : _faces.push_back(new MLine (_vertices) ); break;
    case 3  : _faces.push_back(new MLine2 (_vertices) ); break;
    default : _faces.push_back(new MLineN (_vertices) ); break;
    }
    else throw;
  }
}


dgGroupOfFaces::dgGroupOfFaces (const std::vector<MFace> &topo_faces, 		  
				const std::vector<MElement*> &l, 
				const std::vector<MElement*> &r,
				int pOrder) : _left(l), _right(r) 
{
  _fsLeft  = _left[0]->getFunctionSpace (pOrder);
  _fsRight = _right[0]->getFunctionSpace (pOrder);
  dgCreateFaceElements (topo_faces);
}

dgGroupOfFaces::dgGroupOfFaces (const std::vector<MEdge> &topo_edges, 		  
				const std::vector<MElement*> &l, 
				const std::vector<MElement*> &r,
				int pOrder) : _left(l), _right(r) 
{
  _fsLeft  = _left[0]->getFunctionSpace (pOrder);
  _fsRight = _right[0]->getFunctionSpace (pOrder);
  dgCreateFaceElements (topo_edges);
}
