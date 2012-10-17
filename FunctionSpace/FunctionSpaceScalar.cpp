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
  const vector       <const Polynomial*>&   cell  = basis.getCellFunctions();

  const unsigned int nFNode = basis.getNVertexBased();
  const unsigned int nFEdge = basis.getNEdgeBased();
  const unsigned int nFCell = basis.getNCellBased();


  // Get Edge Closure //
  MElement&          eelement = const_cast<MElement&>(element);
  const unsigned int nEdge    = eelement.getNumEdges();
  
  vector<bool> edgeClosure(nEdge);
  
  // Look Edges 
  for(unsigned int i = 0; i < nEdge; i++){
    MEdge edge     = eelement.getEdge(i);
    edgeClosure[i] = 
      edge.getVertex(0)->getNum() > edge.getVertex(1)->getNum();
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

  // Vertex Based
  for(unsigned int j = 0; j < nFCell; j++){
    fun[i] = cell[j];
    i++;
  }


  // Return //
  return fun;
}
