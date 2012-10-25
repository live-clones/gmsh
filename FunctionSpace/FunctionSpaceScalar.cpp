#include "FunctionSpaceScalar.h"
#include "Exception.h"

using namespace std;

FunctionSpaceScalar::FunctionSpaceScalar(void){
  hasGrad   = false;
  gradBasis = NULL;
}

FunctionSpaceScalar::~FunctionSpaceScalar(void){
  if(hasGrad)
    delete gradBasis;
}

const vector<const Polynomial*> FunctionSpaceScalar::
getLocalFunctions(const MElement& element) const{
  
  // Get Basis //
  const unsigned int nFNode = basisScalar->getNVertexBased();
  const unsigned int nFEdge = basisScalar->getNEdgeBased();
  const unsigned int nFFace = basisScalar->getNFaceBased();
  const unsigned int nFCell = basisScalar->getNCellBased();

  // Get Closure //
  vector<int> edgeClosure = getEdgeClosure(element);
  vector<int> faceClosure = getFaceClosure(element); 

  // Get Functions //
  vector<const Polynomial*> fun(basisScalar->getSize());
  unsigned int i = 0;
  
  // Vertex Based
  for(unsigned int j = 0; j < nFNode; j++){
    fun[i] = &basisScalar->getNodeFunction(j);
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
	&basisScalar->getEdgeFunction(edgeClosure[k], fEdge);
      
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
	&basisScalar->getFaceFunction(faceClosure[k], fFace);
      
      fFace++;
      i++;
    }
  }

  // Cell Based
  for(unsigned int j = 0; j < nFCell; j++){
    fun[i] = &basisScalar->getCellFunction(j);
    i++;
  }


  // Return //
  return fun;
}

const vector<const vector<Polynomial>*> FunctionSpaceScalar::
getGradLocalFunctions(const MElement& element) const{

  // Got Grad Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasGrad){
    gradBasis = new GradBasis(*basisScalar);
    hasGrad   = true;
  }

  // Get Basis //
  const unsigned int nFNode = gradBasis->getNVertexBased();
  const unsigned int nFEdge = gradBasis->getNEdgeBased();
  const unsigned int nFFace = gradBasis->getNFaceBased();
  const unsigned int nFCell = gradBasis->getNCellBased();

  // Get Closure //
  vector<int> edgeClosure = getEdgeClosure(element);
  vector<int> faceClosure = getFaceClosure(element); 

  // Get Functions //
  vector<const vector<Polynomial>*> fun(gradBasis->getSize());
  unsigned int i = 0;
  
  // Vertex Based
  for(unsigned int j = 0; j < nFNode; j++){
    fun[i] = &gradBasis->getNodeFunction(j);
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
	&gradBasis->getEdgeFunction(edgeClosure[k], fEdge);
      
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
	&gradBasis->getFaceFunction(faceClosure[k], fFace);
      
      fFace++;
      i++;
    }
  }

  // Cell Based
  for(unsigned int j = 0; j < nFCell; j++){
    fun[i] = &gradBasis->getCellFunction(j);
    i++;
  }


  // Return //
  return fun;  
}
