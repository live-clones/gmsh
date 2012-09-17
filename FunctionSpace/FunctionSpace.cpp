#include <sstream>
#include "FunctionSpace.h"
#include "BasisGenerator.h"

using namespace std;

FunctionSpace::FunctionSpace(void){
}

FunctionSpace::~FunctionSpace(void){
  map<const MElement*, vector<bool>*>::iterator it 
    = edgeClosure->begin();
  map<const MElement*, vector<bool>*>::iterator stop 
    = edgeClosure->end();
  
  for(; it != stop; it++)
    delete it->second;
  delete edgeClosure;

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

  // Build Closure
  edgeClosure = new map<const MElement*, vector<bool>*>;
  closure();
}

void FunctionSpace::closure(void){
  // Get Elements //
  const vector<const MElement*>& element = goe->getAll();
  const unsigned int             size    = element.size();    

  // Iterate on elements //
  for(unsigned int i = 0; i < size; i++){
    // Get Element data
    MElement& myElement =
      const_cast<MElement&>(*element[i]);

    const unsigned int nVertex = myElement.getNumVertices();
    const unsigned int nEdge   = myElement.getNumEdges();
    const unsigned int nFace   = myElement.getNumFaces();

    const unsigned int nTotVertex = nVertex * fPerVertex;
    const unsigned int nTotEdge   = nEdge   * fPerEdge;
    const unsigned int nTotFace   = nFace   * fPerFace;
    
    const unsigned int nTot    = nTotVertex + nTotEdge + nTotFace + fPerCell;

    // Closure
    vector<bool>* closure = new vector<bool>(nTot);
    unsigned int it = 0;

    // Closure for vertices
    for(unsigned int j = 0; j < nTotVertex; j++, it++)
      (*closure)[it] = true;

    // Closure for edges 
    for(unsigned int j = 0; j < fPerEdge; j++){
      for(unsigned int k = 0; k < nEdge; k++, it++){
	// Orientation 
	int orientation = mesh->getOrientation(myElement.getEdge(k));
	
	if(orientation == 1)
	  (*closure)[it] = true;
	
	else
	  (*closure)[it] = false;
      }
    }

    // Closure for faces
    // TODO

    // Closure for cells
    for(unsigned int j = 0; j < fPerCell; j++, it++)
      (*closure)[it] = true;    

    // Add Closure
    edgeClosure->insert
      (pair<const MElement*, vector<bool>*>(element[i], closure));
  }
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
  for(int i = 0; i < nFVertex; i++){
    for(int j = 0; j < nVertex; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[j]), i);
      it++;
    }
  }
  
  // Add Edge Based Dof //
  for(int i = 0; i < nFEdge; i++){
    for(int j = 0; j < nEdge; j++){
      myDof[it].setDof(mesh->getGlobalId(edge[j]), i);
      it++;
    }
  }
  /*
  // Add Face Based Dof //
  for(int i = 0; i < nFFace; i++){
    for(int j = 0; j < nFace; j++){
      myDof[it].setDof(mesh->getGlobalId(face[j]), i);
      it++;
    }
  }
  */
  // Add Cell Based Dof //
  for(int i = 0; i < nFCell; i++){
    myDof[it].setDof(mesh->getGlobalId(element), i);
    it++;
  }

  return myDof;
}

string FunctionSpace::toString(void) const{
  return basis->toString();
}
