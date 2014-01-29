#include <sstream>

#include "ReferenceSpaceManager.h"
#include "BasisGenerator.h"
#include "ElementType.h"
#include "Exception.h"

#include "FunctionSpace.h"

using namespace std;

FunctionSpace::FunctionSpace(void){
}

FunctionSpace::~FunctionSpace(void){
  // Delete Vector of Basis
  //   (FunctionSpace is not responsible for 'true' Basis Deletion)
}

void FunctionSpace::build(GroupOfElement& goe,
                          const Basis& basis){

  // Save GroupOfElement & Mesh //
  this->goe  = &goe;
  this->mesh = &(goe.getMesh());

  // Get Geo Data (WARNING HOMOGENE MESH REQUIRED)//
  const MElement& element = goe.get(0);
  MElement& myElement =
    const_cast<MElement&>(element);

  int nVertex = myElement.getNumPrimaryVertices();
  int nEdge   = myElement.getNumEdges();
  int nFace   = myElement.getNumFaces();

  // Init Struct //
  this->basis.resize(1);
  this->basis[0] = &basis;

  // Number of *Per* Entity functions //
  // Init
  fPerVertex.resize(1);
  fPerEdge.resize(1);
  fPerFace.resize(1);
  fPerCell.resize(1);

  // Populate
  fPerVertex[0] = this->basis[0]->getNVertexBased() / nVertex;

  if(nEdge)
    fPerEdge[0] = this->basis[0]->getNEdgeBased() / nEdge;
  else
    fPerEdge[0] = 0;

  if(nFace)
    fPerFace[0] = this->basis[0]->getNFaceBased() / nFace;
  else
    fPerFace[0] = 0;

  fPerCell[0] = this->basis[0]->getNCellBased();

  // Build Dof //
  buildDof();
}

void FunctionSpace::buildDof(void){
  // Get Elements //
  const size_t nElement = goe->getNumber();
  const vector<const MElement*>& element = goe->getAll();

  // Init Struct //
  group.resize(nElement);

  // Create Dofs //
  for(size_t i = 0; i < nElement; i++){
    // Get Dof for this Element
    vector<Dof> myDof = getKeys(*(element[i]));
    size_t nDof       = myDof.size();

    // Add Dofs
    for(size_t j = 0; j < nDof; j++)
      dof.insert(myDof[j]);

    // Save vector
    group[i] = myDof;
  }
}

vector<Dof> FunctionSpace::getUnorderedKeys(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Vertex, Edge & Face //
  const size_t nVertex = element.getNumPrimaryVertices();
  const size_t nEdge   = element.getNumEdges();
  const size_t nFace   = element.getNumFaces();

  // Number of cells //
  size_t nCell;
  if(element.getDim() == 3) // Need to be 3D to have one Cell
    nCell = 1;
  else
    nCell = 0;

  vector<MVertex*> vertex(nVertex);
  vector<MEdge>    edge(nEdge);
  vector<MFace>    face(nFace);

  for(size_t i = 0; i < nVertex; i++)
    vertex[i] = element.getVertex(i);

  for(size_t i = 0; i < nEdge; i++)
    edge[i] = element.getEdge(i);

  for(size_t i = 0; i < nFace; i++)
    face[i] = element.getFace(i);

  // Create Dof //
  size_t nDof =
    fPerVertex[0] * nVertex +
    fPerEdge[0]   * nEdge   +
    fPerFace[0]   * nFace   +
    fPerCell[0]   * nCell;

  vector<Dof> myDof(nDof);

  size_t it = 0;

  // Add Vertex Based Dof //
  for(size_t i = 0; i < nVertex; i++){
    for(size_t j = 0; j < fPerVertex[0]; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[i]), j);
      it++;
    }
  }

  // Add Edge Based Dof //
  for(size_t i = 0; i < nEdge; i++){
    for(size_t j = 0; j < fPerEdge[0]; j++){
      myDof[it].setDof(mesh->getGlobalId(edge[i]), j);
      it++;
    }
  }

  // Add Face Based Dof //
  for(size_t i = 0; i < nFace; i++){
    for(size_t j = 0; j < fPerFace[0]; j++){
      myDof[it].setDof(mesh->getGlobalId(face[i]), j);
      it++;
    }
  }

  // Add Cell Based Dof //
  for(size_t i = 0; i < nCell; i++){
    for(size_t j = 0; j < fPerCell[0]; j++){
      myDof[it].setDof(mesh->getGlobalId(element), j);
      it++;
    }
  }

  return myDof;
}

vector<Dof> FunctionSpace::getKeys(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Create New Element With Permuted Vertices //
  // Permutation
  const vector<size_t>& vPerm =
    ReferenceSpaceManager::getNodeIndexFromABCtoUVW(elem);

  // Permuted Vertices
  const size_t nVertex = element.getNumPrimaryVertices();
  vector<MVertex*> vertex(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    vertex[i] = element.getVertex(vPerm[i]);

  // New Element
  MElementFactory factory;
  int parentTag   = ElementType::ParentTypeFromTag(elem.getTypeForMSH());
  int lowOrderTag = ElementType::getTag(parentTag, 1, false);

  MElement* permElement = factory.create(lowOrderTag, vertex, element.getNum());

  // Get Dofs from permuted Element //
  vector<Dof> myDofs = getUnorderedKeys(*permElement);

  // Free and Return //
  delete permElement;
  return myDofs;
}

void FunctionSpace::getKeys(const GroupOfElement& goe,
                            std::set<Dof>& dof) const{
  // Get Elements //
  const vector<const MElement*>& element = goe.getAll();
  const size_t nElement = element.size();

  // Loop on Elements //
  for(size_t e = 0; e < nElement; e++){
    // Get my Dofs
    vector<Dof>  myDof = getUnorderedKeys(*element[e]);
    const size_t nDof  = myDof.size();

    // Add my Dofs
    for(size_t d = 0; d < nDof; d++)
      dof.insert(myDof[d]);
  }
}
