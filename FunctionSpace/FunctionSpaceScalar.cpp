#include "FunctionSpaceScalar.h"
#include "Exception.h"

using namespace std;

FunctionSpaceScalar::~FunctionSpaceScalar(void){
}

const vector<const Polynomial*> FunctionSpaceScalar::
getLocalFunctions(const MElement& element) const{
  
  // Get Basis //
  const BasisScalar&                        basis = getBasis(element);
  const vector       <const Polynomial*>&   node  = basis.getNodeFunctions();
  const vector<vector<const Polynomial*>*>& edge  = basis.getEdgeFunctions();
  const vector<vector<const Polynomial*>*>& face  = basis.getFaceFunctions();
  const vector       <const Polynomial*>&   cell  = basis.getCellFunctions();

  const unsigned int nFNode = basis.getNVertexBased();
  const unsigned int nFEdge = basis.getNEdgeBased();
  const unsigned int nFFace = basis.getNFaceBased();
  const unsigned int nFCell = basis.getNCellBased();

  // Get not const Element (gmsh problem, not mine !) //
  MElement& eelement = const_cast<MElement&>(element);


  // Get Edge Closure //
  const unsigned int nEdge = eelement.getNumEdges();
  vector<bool> edgeClosure(nEdge);

  // Look Edges 
  for(unsigned int i = 0; i < nEdge; i++){
    MEdge edge     = eelement.getEdge(i);
    edgeClosure[i] = 
      edge.getVertex(0)->getNum() < edge.getVertex(1)->getNum();
  }


  // Get Face Closure //
  const unsigned int nFace = eelement.getNumFaces();
  vector<int> faceClosure(nFace);
  
  // Look Faces 
  for(unsigned int i = 0; i < nFace; i++){
    MFace face = eelement.getFace(i);

    unsigned int v[3];
    v[0] = face.getVertex(0)->getNum();
    v[1] = face.getVertex(1)->getNum();
    v[2] = face.getVertex(2)->getNum();

    bool c[3];
    c[0] = v[0] < v[1];
    c[1] = v[1] < v[2];
    c[2] = v[2] < v[0];

    if(c[0])
      if(c[1])
	faceClosure[i] = 0;
    
      else
	if(c[2])
	  faceClosure[i] = 4;
    
	else
	  faceClosure[i] = 5;
    
    else
      if(c[1])
	if(c[2])
	  faceClosure[i] = 2;
    
	else
	  faceClosure[i] = 1;
    
      else
	faceClosure[i] = 3;
  }


  // Get Functions //
  vector<const Polynomial*> fun(basis.getSize());
  unsigned int i = 0;
  
  // Vertex Based
  for(unsigned int j = 0; j < nFNode; j++){
    fun[i] = node[j];
    i++;
  }

  // Edge Based
  // Number of basis function *per* edge
  //  --> should always be an integer !
  const unsigned int nFPerEdge = nFEdge / nEdge;
  unsigned int fEdge = 0;

  for(unsigned int j = 0; j < nFPerEdge; j++){
    for(unsigned int k = 0; k < nEdge; k++){
      if(edgeClosure[k])
	fun[i] = (*edge[0])[fEdge];
      
      else
	fun[i] = (*edge[1])[fEdge];
      
      fEdge++;
      i++;
    }
  }

  // Face Based
  // Number of basis function *per* face
  //  --> should always be an integer !
  const unsigned int nFPerFace = nFFace / nFace;
  unsigned int fFace = 0;

  for(unsigned int j = 0; j < nFPerFace; j++){
    for(unsigned int k = 0; k < nFace; k++){
      fun[i] = (*face[faceClosure[k]])[fFace];
      
      fFace++;
      i++;
    }
  }

  // Cell Based
  for(unsigned int j = 0; j < nFCell; j++){
    fun[i] = cell[j];
    i++;
  }


  // Return //
  return fun;
}
