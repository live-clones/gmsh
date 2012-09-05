#include "FunctionSpace.h"
#include "BasisGenerator.h"


using namespace std;

FunctionSpace::FunctionSpace(void){
}

FunctionSpace::~FunctionSpace(void){
  delete basis;
}

void FunctionSpace::build(const GroupOfElement& goe,
			  int basisType, int order){
  // Save GroupOfElement & Mesh //
  this->goe  = &goe;
  this->mesh = &(goe.getMesh());

  // Get Geo Data (WARNING HOMOGENE MESH REQUIRED)//
  const MElement& element = goe.get(0);
  MElement& myElement =
    const_cast<MElement&>(element);

  int elementType = myElement.getType();
  int nVertex     = myElement.getNumVertices();
  int nEdge       = myElement.getNumEdges();
  int nFace       = myElement.getNumFaces();
 
  // Init Struct //
  type  = basisType;
  basis = BasisGenerator::generate(elementType, 
				   basisType, 
				   order);
  
  // Number of *Per* Entity functions //
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

vector<Dof> FunctionSpace::getKeys(const MElement& elem) const{ 
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Get Element Data //
  const int nVertex = element.getNumVertices();
  const int nEdge   = element.getNumEdges();
  const int nFace   = element.getNumFaces(); 

  vector<MVertex*> vertex(nVertex);
  vector<MEdge> edge(nEdge);
  vector<MFace> face(nFace);

  for(int i = 0; i < nVertex; i++)
    vertex[i] = element.getVertex(i);

  for(int i = 0; i < nEdge; i++)    
    edge[i] = element.getEdge(i);
  
  for(int i = 0; i < nFace; i++)
    face[i] = element.getFace(i);
  
  // Get FunctionSpace Data for this Element //
  const int nFVertex = getNFunctionPerVertex(element);
  const int nFEdge   = getNFunctionPerEdge(element);
  const int nFFace   = getNFunctionPerFace(element);
  const int nFCell   = getNFunctionPerCell(element);

  // Create Dof //
  const int nDofVertex = nFVertex * nVertex; 
  const int nDofEdge   = nFEdge   * nEdge;
  const int nDofFace   = nFFace   * nFace;
  const int nDofCell   = nFCell;

  int nDof = 
    nDofVertex + nDofEdge + nDofFace + nDofCell;

  vector<Dof> myDof(nDof);

  int it = 0;

  // Add Vertex Based Dof //
  for(int i = 0; i < nVertex; i++){
    for(int j = 0; j < nFVertex; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[i]), j);
      it++;
    }
  }
  
  // Add Edge Based Dof //
  for(int i = 0; i < nEdge; i++){
    for(int j = 0; j < nFEdge; j++){
      myDof[it].setDof(mesh->getGlobalId(edge[i]), j);
      it++;
    }
  }
  /*
  // Add Face Based Dof //
  for(int i = 0; i < nFace; i++){
    for(int j = 0; j < nFFace; j++){
      myDof[it].setDof(mesh->getGlobalId(face[i]), j);
      it++;
    }
  }
  */
  // Add Cell Based Dof //
  for(int j = 0; j < nFCell; j++){
    myDof[it].setDof(mesh->getGlobalId(element), j);
    it++;
  }
  
  
  return myDof;
}

int FunctionSpace::getElementType(const Dof& dof) const{
  // Get Entity //
  const unsigned int entity = dof.getEntity();

  // Total Number of Entities //
  const unsigned int nVertex = mesh->getVertexNumber();
  const unsigned int nEdge   = mesh->getEdgeNumber();
  const unsigned int nFace   = mesh->getFaceNumber();
  
  // Vertex Based
  if(entity < nVertex)
    return 0; 

  // Edge Based
  else if(entity < nVertex + nEdge)
    return 1;

  // Face Based
  else if(entity < nVertex + nEdge + nFace)
    return 2;
  
  // Cell Based
  else
    return 3; 
}
