#include "FunctionSpaceVector.h"
#include "Exception.h"

using namespace std;

FunctionSpaceVector::~FunctionSpaceVector(void){
}

const vector<const vector<Polynomial>*> FunctionSpaceVector::
getLocalFunctions(const MElement& element) const{

  // Get Basis //
  const BasisVector&  basis = getBasis(element);

  const unsigned int nFNode = basis.getNVertexBased();
  const unsigned int nFEdge = basis.getNEdgeBased();
  const unsigned int nFFace = basis.getNFaceBased();
  const unsigned int nFCell = basis.getNCellBased();

  // Get Closure //
  vector<int> edgeClosure = getEdgeClosure(element);
  vector<int> faceClosure = getFaceClosure(element); 

  // Get Functions //
  vector<const vector<Polynomial>*> fun(basis.getSize());
  unsigned int i = 0;
  
  // Vertex Based
  for(unsigned int j = 0; j < nFNode; j++){
    fun[i] = &basis.getNodeFunction(j);
    i++;
  }

  // Edge Based
  // Number of basis function *per* edge
  //  --> should always be an integer !
  const unsigned int nEdge     = edgeClosure.size();
  const unsigned int nFPerEdge = nFEdge / nEdge;
  unsigned int fEdge = 0;

  for(unsigned int j = 0; j < nFPerEdge; j++){
    for(unsigned int k = 0; k < nEdge; k++){
      fun[i] = 
	&basis.getEdgeFunction(edgeClosure[k], fEdge);
      
      fEdge++;
      i++;
    }
  }

  // Face Based
  // Number of basis function *per* face
  //  --> should always be an integer !
  const unsigned int nFace     = faceClosure.size();
  const unsigned int nFPerFace = nFFace / nFace;
  unsigned int fFace = 0;

  for(unsigned int j = 0; j < nFPerFace; j++){
    for(unsigned int k = 0; k < nFace; k++){
      fun[i] = 
	&basis.getFaceFunction(faceClosure[k], fFace);
      
      fFace++;
      i++;
    }
  }

  // Cell Based
  for(unsigned int j = 0; j < nFCell; j++){
    fun[i] = &basis.getCellFunction(j);
    i++;
  }


  // Return //
  return fun;
}
