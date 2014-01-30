#include <sstream>

#include "ReferenceSpaceManager.h"
#include "BasisGenerator.h"
#include "ElementType.h"
#include "Exception.h"

#include "FunctionSpace.h"

using namespace std;

const size_t FunctionSpace::nGeoType = 9;

FunctionSpace::FunctionSpace(void){
}

FunctionSpace::~FunctionSpace(void){
  if(self)
    for(size_t i = 0; i < nGeoType; i++)
      if(basis[i])
        delete basis[i];
}

void FunctionSpace::build(GroupOfElement& goe,
                          const Basis& basis){

  // Save GroupOfElement & Mesh //
  this->goe  = &goe;
  this->mesh = &(goe.getMesh());

  // Check if homogene GoE and get geo type //
  const vector<size_t>& gType = goe.getTypeStats();
  const size_t nGType = gType.size();
  size_t eType = (size_t)(-1);

  for(size_t i = 0; i < nGType; i++)
    if((eType == (size_t)(-1)) && (gType[i] != 0))
      eType = i;
    else if((eType != (size_t)(-1)) && (gType[i] != 0))
      throw Exception("FunctionSpace needs a uniform mesh");

  // Check if basis is matching type //
  if(eType != basis.getType())
    throw Exception("FunctionSpace: Basis is not matching type");

  // Alloc Bases and save given Basis //
  this->self = false;
  this->basis.resize(nGeoType, NULL);
  this->basis[eType] = &basis;

  // Get Number of Function per Entity //
  // Same for all basis since we have a uniform order
  MElement& myElement = const_cast<MElement&>(goe.get(0));

  int nVertex = myElement.getNumPrimaryVertices();
  int nEdge   = myElement.getNumEdges();
  int nFace   = myElement.getNumFaces();

  // Number of *Per* Entity functions //
  fPerVertex = this->basis[eType]->getNVertexBased() / nVertex;

  if(nEdge)
    fPerEdge = this->basis[eType]->getNEdgeBased() / nEdge;
  else
    fPerEdge = 0;

  if(nFace)
    fPerFace = this->basis[eType]->getNFaceBased() / nFace;
  else
    fPerFace = 0;

  fPerCell = this->basis[eType]->getNCellBased();

  // Build Dof //
  buildDof();
}

void FunctionSpace::build(GroupOfElement& goe,
                          size_t order, size_t form, string family){

  // Save GroupOfElement & Mesh //
  this->goe  = &goe;
  this->mesh = &(goe.getMesh());

  // Alloc Basis Vector for all possible geomtrical types //
  self = true;
  basis.resize(nGeoType, NULL);

  // Generate Bases //
  const vector<const MElement*>& element = goe.getAll();

  // Get geomtrical type statistics
  const vector<size_t>& geoTypeStat = goe.getTypeStats();
  const size_t nGeoType = geoTypeStat.size();

  // Buils basis for existing geomtrical type
  for(size_t i = 0; i < nGeoType; i++)
    if(geoTypeStat[i])
      basis[i] = BasisGenerator::generate(i, form, order, family);

  // Get Number of Function per Entity //
  // Same for all basis since we have a uniform order
  MElement& myElement = const_cast<MElement&>(*element[0]);

  int nVertex = myElement.getNumPrimaryVertices();
  int nEdge   = myElement.getNumEdges();
  int nFace   = myElement.getNumFaces();
  int type    = myElement.getType();

  fPerVertex = basis[type]->getNVertexBased() / nVertex;

  if(nEdge)
    fPerEdge = this->basis[type]->getNEdgeBased() / nEdge;
  else
    fPerEdge = 0;

  if(nFace)
    fPerFace = this->basis[type]->getNFaceBased() / nFace;
  else
    fPerFace = 0;

  fPerCell = this->basis[type]->getNCellBased();

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
    fPerVertex * nVertex +
    fPerEdge   * nEdge   +
    fPerFace   * nFace   +
    fPerCell   * nCell;

  vector<Dof> myDof(nDof);

  size_t it = 0;

  // Add Vertex Based Dof //
  for(size_t i = 0; i < nVertex; i++){
    for(size_t j = 0; j < fPerVertex; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[i]), j);
      it++;
    }
  }

  // Add Edge Based Dof //
  for(size_t i = 0; i < nEdge; i++){
    for(size_t j = 0; j < fPerEdge; j++){
      myDof[it].setDof(mesh->getGlobalId(edge[i]), j);
      it++;
    }
  }

  // Add Face Based Dof //
  for(size_t i = 0; i < nFace; i++){
    for(size_t j = 0; j < fPerFace; j++){
      myDof[it].setDof(mesh->getGlobalId(face[i]), j);
      it++;
    }
  }

  // Add Cell Based Dof //
  for(size_t i = 0; i < nCell; i++){
    for(size_t j = 0; j < fPerCell; j++){
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
