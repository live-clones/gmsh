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

const vector<Dof*> FunctionSpace::getKeys(const MElement& elem) const{  
  // nTotVertex 
  int nTotVertex = goe->getNVertex();

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

  vector<Dof*> myDof(nDof);

  int it = 0;

  // Add Vertex Based Dof //
  for(int i = 0; i < nVertex; i++){
    // Get Id of Vertex
    const int id = vertex[i]->getNum();

    // New Dof
    for(int j = 0; j < nFVertex; j++){
      myDof[it] = new Dof(id, j);
      it++;
    }
  }

  // Add Edge Based Dof //
  for(int i = 0; i < nEdge; i++){
    // Get Id of Edge 
    MVertex* vEdge0 = edge[i].getSortedVertex(0);
    MVertex* vEdge1 = edge[i].getSortedVertex(1);

    const int id = 
      vEdge0->getNum() + 
      vEdge1->getNum() * nTotVertex;

    // Insert new Dof
    for(int j = 0; j < nFEdge; j++){
      myDof[it] = new Dof(id, j);
      it++;
    }
  }  

  // Add Cell Based Dof //
  // Get Id of Cell 
  const int id = element.getNum() * nTotVertex * nTotVertex;

  // Insert new Dof
  for(int j = 0; j < nFCell; j++){
    myDof[it] = new Dof(id, j);
    it++;
  }
  
  return myDof;
}

FunctionSpace::~FunctionSpace(void){
  delete basis;
}

