#include <sstream>

#include "ReferenceSpaceManager.h"
#include "BasisGenerator.h"
#include "ElementType.h"
#include "Exception.h"

#include "FunctionSpace.h"

using namespace std;

const size_t FunctionSpace::nGeoType  = 9;
      size_t FunctionSpace::nxtOffset = 0;

FunctionSpace::FunctionSpace(void){
  // Alloc Basis Vector for all possible geomtrical types //
  basis.resize(nGeoType, NULL);

  // Alloc Function per Entity //
  fPerVertex.resize(nGeoType, 0);
  fPerEdge.resize(nGeoType  , 0);
  fPerFace.resize(nGeoType  , 0);
  fPerCell.resize(nGeoType  , 0);
}

FunctionSpace::~FunctionSpace(void){
  for(size_t i = 0; i < nGeoType; i++)
    if(basis[i])
      delete basis[i];
}

void FunctionSpace::build(const GroupOfElement& goe, string family){
  // Save Dof type offset //
  offset = nxtOffset;

  // Save Mesh //
  this->mesh = &(goe.getMesh());

  // Generate Bases //
  const vector<size_t>& geoTypeStat = goe.getTypeStats();
  const size_t             nGeoType = geoTypeStat.size();

  for(size_t i = 0; i < nGeoType; i++)
    if(geoTypeStat[i] != 0 && basis[i] == NULL)
      basis[i] = BasisGenerator::generate(i, form, order, family);

  // Get Number of Function per Entity //
  for(size_t i = 0; i < nGeoType; i++){
    if(geoTypeStat[i] != 0 && fPerVertex[i] == 0){
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
  }

  // Build Dof //
  buildDof(goe);
}

void FunctionSpace::buildDof(const GroupOfElement& goe){
  // Get Elements //
  const size_t                   nElement = goe.getNumber();
  const vector<const MElement*>&  element = goe.getAll();

  // Push GroupOfElement into map //
  pair<size_t, vector<vector<Dof> > >                      toInsert;
  pair<map<size_t, vector<vector<Dof> > >::iterator, bool> isInserted;

  toInsert.first  = goe.getId();
  toInsert.second = vector<vector<Dof> >(0);
  isInserted      = dof.insert(toInsert);

  if(!isInserted.second)
    throw Exception("FunctionSpace: cannot computed Dofs for GroupOfElement %d",
                    goe.getId());

  // Reference & Allocate //
  vector<vector<Dof> >& myDof = isInserted.first->second;
  myDof.resize(nElement);

  // Create Dofs //
  for(size_t i = 0; i < nElement; i++)
    getKeys(*(element[i]), myDof[i]);
}

size_t FunctionSpace::findMaxType(void){
  // Maximum type //
  size_t maxType = 0;

  // Iterate on GroupOfElement Id //
  map<size_t, vector<vector<Dof> > >::iterator it  = dof.begin();
  map<size_t, vector<vector<Dof> > >::iterator end = dof.end();

  size_t nElement;
  size_t nDof;
  size_t type;

  for(; it != end; it++){
    // Iterate on Elements of this GroupOfElement //
    nElement = it->second.size();

    for(size_t e = 0; e < nElement; e++){
      // Iterate on Dofs of this Element //
      nDof = it->second[e].size();

      for(size_t d = 0; d < nDof; d++){
        // This Dof Type
        type = it->second[e][d].getType();

        // If this Dof type is bigger, it becomes the new 'maxType'
        if(type > maxType)
          maxType = type;
      }
    }
  }

  // Return maxType //
  return maxType;
}

void FunctionSpace::getUnorderedKeys(const MElement& elem,
                                     std::vector<Dof>& dof) const{
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

  size_t   it = 0;
  size_t nDof =
    fPerVertex * nVertex +
    fPerEdge   * nEdge   +
    fPerFace   * nFace   +
    fPerCell;

  dof.resize(nDof);

  // Add Vertex Based Dof //
  for(size_t i = 0; i < nVertex; i++){
    for(size_t j = 0; j < fPerVertex; j++){
      dof[it].setDof(mesh->getGlobalId(*vertex[i]), j + offset);
      it++;
    }
  }

  // Add Edge Based Dof //
  for(size_t i = 0; i < nEdge; i++){
    for(size_t j = 0; j < fPerEdge; j++){
      dof[it].setDof(mesh->getGlobalId(edge[i]), j + offset);
      it++;
    }
  }

  // Add Face Based Dof //
  for(size_t i = 0; i < nFace; i++){
    for(size_t j = 0; j < fPerFace; j++){
      dof[it].setDof(mesh->getGlobalId(face[i]), j + offset);
      it++;
    }
  }

  // Add Cell Based Dof //
  for(size_t j = 0; j < fPerCell; j++){
    dof[it].setDof(mesh->getGlobalId(element), j + offset);
    it++;
  }
}

void FunctionSpace::getKeys(const MElement& elem, std::vector<Dof>& dof) const{
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
  getUnorderedKeys(*permElement, dof);

  // Free and Return //
  delete permElement;
}

void FunctionSpace::getKeys(const GroupOfElement& goe,
                            std::set<Dof>& dof) const{
  // Get Elements //
  const vector<const MElement*>& element = goe.getAll();
  const size_t nElement = element.size();

  // Dof Vector //
  vector<Dof> myDof;

  // Loop on Elements //
  for(size_t e = 0; e < nElement; e++){
    // Get my Dofs
    getUnorderedKeys(*element[e], myDof);

    // Add my Dofs
    const size_t nDof = myDof.size();

    for(size_t d = 0; d < nDof; d++)
      dof.insert(myDof[d]);
  }
}

const std::vector<std::vector<Dof> >&
FunctionSpace::getKeys(const GroupOfElement& goe) const{
  // Find vector of Dof from map //
  map<size_t, vector<vector<Dof> > >::const_iterator it = dof.find(goe.getId());

  if(it == dof.end())
    throw Exception("FunctionSpace: cannot find Dofs of GroupOfElement %d",
                    goe.getId());

  // Return vector //
  return it->second;
}
