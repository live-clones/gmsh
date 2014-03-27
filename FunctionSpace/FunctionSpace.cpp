#include <sstream>

#include "ReferenceSpaceManager.h"
#include "BasisGenerator.h"
#include "ElementType.h"
#include "Exception.h"

#include "FunctionSpace.h"

using namespace std;

const size_t FunctionSpace::nGeoType = 9;
size_t FunctionSpace::nxtOffset = 0;

FunctionSpace::FunctionSpace(void){
}

FunctionSpace::~FunctionSpace(void){
  for(size_t i = 0; i < nGeoType; i++)
    if(basis[i])
      delete basis[i];
}

void FunctionSpace::build(const GroupOfElement& goe, string family){
  // Save Dof type offset //
  offset = nxtOffset;

  // Save GroupOfElement & Mesh //
  this->goe  = &goe;
  this->mesh = &(goe.getMesh());

  // Alloc Basis Vector for all possible geomtrical types //
  basis.resize(nGeoType, NULL);

  // Generate Bases //

  // Get geomtrical type statistics
  const vector<size_t>& geoTypeStat = goe.getTypeStats();
  const size_t nGeoType = geoTypeStat.size();

  // Buils basis for existing geomtrical type
  for(size_t i = 0; i < nGeoType; i++)
    if(geoTypeStat[i])
      basis[i] = BasisGenerator::generate(i, form, order, family);

  // Get Number of Function per Entity //
  fPerVertex.resize(nGeoType);
  fPerEdge.resize(nGeoType);
  fPerFace.resize(nGeoType);
  fPerCell.resize(nGeoType);

  for(size_t i = 0; i < nGeoType; i++){
    if(geoTypeStat[i]){
      int nVertex = ReferenceSpaceManager::getNVertex(i);
      int nEdge   = ReferenceSpaceManager::getNEdge(i);
      int nFace   = ReferenceSpaceManager::getNFace(i);

      fPerVertex[i] = basis[i]->getNVertexBased() / nVertex;

      if(nEdge)
        fPerEdge[i] = this->basis[i]->getNEdgeBased() / nEdge;
      else
        fPerEdge[i] = 0;

      if(nFace)
        fPerFace[i] = this->basis[i]->getNFaceBased() / nFace;
      else
        fPerFace[i] = 0;

      fPerCell[i] = this->basis[i]->getNCellBased();
    }

    else{
      fPerVertex[i] = 0;
      fPerEdge[i]   = 0;
      fPerFace[i]   = 0;
      fPerCell[i]   = 0;
    }
  }

  // Build Dof //
  buildDof();

  // Find next offset //
  nxtOffset = findMaxType() + 1;
}

void FunctionSpace::buildDof(void){
  // Get Elements //
  const size_t nElement = goe->getNumber();
  const vector<const MElement*>& element = goe->getAll();

  // Create Dofs //
  for(size_t i = 0; i < nElement; i++){
    // Get Dof for this Element
    vector<Dof> myDof = getKeys(*(element[i]));
    size_t nDof       = myDof.size();

    // Add Dofs
    for(size_t j = 0; j < nDof; j++)
      dof.insert(myDof[j]);
  }
}

size_t FunctionSpace::findMaxType(void){
  // Maximum type //
  size_t maxType = 0;

  // Iterate for dof //
  const set<Dof>::iterator end = dof.end();
        set<Dof>::iterator it  = dof.begin();

  for(; it != end; it++)
    // If this type is bigger, it becomes the new 'maxType'
    if(it->getType() > maxType)
      maxType = it->getType();

  return maxType;
}

vector<Dof> FunctionSpace::getUnorderedKeys(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Vertex, Edge & Face //
  const size_t nVertex = element.getNumPrimaryVertices();
  const size_t nEdge   = element.getNumEdges();
  const size_t nFace   = element.getNumFaces();

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
  const size_t type       = element.getType();
  const size_t fPerVertex = this->fPerVertex[type];
  const size_t fPerEdge   = this->fPerEdge[type];
  const size_t fPerFace   = this->fPerFace[type];
  const size_t fPerCell   = this->fPerCell[type];

  size_t nDof =
    fPerVertex * nVertex +
    fPerEdge   * nEdge   +
    fPerFace   * nFace   +
    fPerCell;

  vector<Dof> myDof(nDof);

  size_t it = 0;

  // Add Vertex Based Dof //
  for(size_t i = 0; i < nVertex; i++){
    for(size_t j = 0; j < fPerVertex; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[i]), j + offset);
      it++;
    }
  }

  // Add Edge Based Dof //
  for(size_t i = 0; i < nEdge; i++){
    for(size_t j = 0; j < fPerEdge; j++){
      myDof[it].setDof(mesh->getGlobalId(edge[i]), j + offset);
      it++;
    }
  }

  // Add Face Based Dof //
  for(size_t i = 0; i < nFace; i++){
    for(size_t j = 0; j < fPerFace; j++){
      myDof[it].setDof(mesh->getGlobalId(face[i]), j + offset);
      it++;
    }
  }

  // Add Cell Based Dof //
  for(size_t j = 0; j < fPerCell; j++){
    myDof[it].setDof(mesh->getGlobalId(element), j + offset);
    it++;
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

void FunctionSpace::getKeys(const GroupOfElement& goe,
                            std::vector<std::vector<Dof> >& dof) const{
  // Get Elements //
  const size_t nElement = goe.getNumber();
  const vector<const MElement*>& element = goe.getAll();

  // Init Struct //
  dof.resize(nElement);

  // Create Dofs //
  for(size_t i = 0; i < nElement; i++)
    dof[i] = getKeys(*(element[i]));
}
