#include "FunctionSpace.h"
#include "BasisGenerator.h"

using namespace std;

FunctionSpace::FunctionSpace(const GroupOfElement& goe, int basisType, int order){
  // Save GroupOfElement //
  this->goe = &goe;  

  // Look for 1st element to get element type //
  // (We suppose only one type of Mesh !!) //
  int elementType = goe.get(0).getType();
  
  // Init Struct //
  basis  = BasisGenerator::generate(elementType, basisType, order);
  eToGoD = new map<const MElement*, const GroupOfDof*, ElementComparator>;

  // Count Function per Entity //
  int nVertex = goe.get(0).getNumVertices();
  int nEdge   = goe.get(0).getNumEdges();
  int nFace   = goe.get(0).getNumFaces();

  fPerVertex = basis->getNVertexBased() / nVertex;
  // NB: fPreVertex = 0 *or* 1

  if(nEdge)
    fPerEdge = basis->getNEdgeBased() / nEdge;
  else
    fPerEdge = 0;

  if(nFace)
    fPerFace = basis->getNFaceBased() / nFace;
  else
    fPerFace = 0;  
  
  fPerCell = basis->getNCellBased(); // We always got 1 cell 
}

FunctionSpace::~FunctionSpace(void){
  delete basis;
  delete eToGoD;
}

