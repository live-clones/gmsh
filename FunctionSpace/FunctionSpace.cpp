#include <limits.h>
#include <sstream>

#include "ReferenceSpaceManager.h"
#include "BasisGenerator.h"
#include "ElementType.h"

#include "FunctionSpace.h"

using namespace std;

const Dof    FunctionSpace::rejectedDof(INT_MAX, INT_MAX);
const size_t FunctionSpace::nGeoType  = 9;
      size_t FunctionSpace::nxtOffset = 0;

FunctionSpace::FunctionSpace(void){
  // Clear //
  dof.clear();
  rejected.clear();

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

void FunctionSpace::build(const vector<const GroupOfElement*>& goe,
                          const vector<const GroupOfElement*>& exl,
                          string family){
  // Save Dof type offset //
  offset = nxtOffset;

  // Save Mesh & Get number of GoE//
  const size_t nGoe = goe.size();
  const size_t nExl = exl.size();
  this->mesh        = &(goe[0]->getMesh());

  // Build Bases //
  for(size_t i = 0; i < nGoe; i++)
    getBases(*goe[i], family);

  // Build Dof to reject //
  for(size_t i = 0; i < nExl; i++)
    getRejec(*exl[i]);

  // Build Dof //
  for(size_t i = 0; i < nGoe; i++)
    getMyDof(*goe[i]);

  // Next Offset for next FunctionSpace
  nxtOffset = findMaxType() + 1;
}

void FunctionSpace::getBases(const GroupOfElement& goe, string family){
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
}

void FunctionSpace::getMyDof(const GroupOfElement& goe){
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

void FunctionSpace::getRejec(const GroupOfElement& goe){
  // Get Elements //
  const size_t                   nElement = goe.getNumber();
  const vector<const MElement*>&  element = goe.getAll();

  // Allocate //
  vector<vector<Dof> > myDof(nElement);

  // Create Dofs //
  for(size_t i = 0; i < nElement; i++)
    getKeys(*(element[i]), myDof[i]);

  // Push in rejection map //
  for(size_t i = 0; i < nElement; i++){
    size_t nDof = myDof[i].size();

    for(size_t j = 0; j < nDof; j++)
      rejected.insert(myDof[i][j]);
  }
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
                                     std::vector<Dof>& dof, bool full) const{
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

  // Reject Keys or mark them rejected //
  if(full)
    markMyKeys(dof);
  else
    rejectKeys(dof);
}

void FunctionSpace::rejectKeys(vector<Dof>& dof) const{
  // Temp list
  list<Dof> tmp(dof.begin(), dof.end());

  // Look in rejection map
  list<Dof>::iterator end = tmp.end();
  list<Dof>::iterator  it = tmp.begin();

  while(it != end)
    if(rejected.count(*it) == 1)
      it = tmp.erase(it);
    else
      it++;

  // Rebuild dof vector (if needed)
  if(tmp.size() != dof.size()){
    dof.clear();
    dof.assign(tmp.begin(), tmp.end());
  }
}

void FunctionSpace::markMyKeys(vector<Dof>& dof) const{
  const size_t nDof = dof.size();

  for(size_t i = 0; i < nDof; i++)
    if(rejected.count(dof[i]) == 1)
      dof[i] = rejectedDof;
}

void FunctionSpace::getKeys(const MElement& elem, std::vector<Dof>& dof,
                            bool full) const{
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
  getUnorderedKeys(*permElement, dof, full);

  // Free and Return //
  delete permElement;
}

void FunctionSpace::getKeys(const GroupOfElement& goe,
                            std::set<Dof>& dof) const{
  // Get Dofs //
  const vector<vector<Dof> >& allDofs = getKeys(goe);

  // Add them into map //
  const size_t size = allDofs.size();
        size_t nDof;

  for(size_t i = 0; i < size; i++){
    nDof = allDofs[i].size();

    for(size_t j = 0; j < nDof; j++)
      dof.insert(allDofs[i][j]);
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

void FunctionSpace::delKeys(const GroupOfElement& goe,
                            std::set<Dof>& dof) const{
  // Get Dofs //
  const vector<vector<Dof> >& allDofs = getKeys(goe);

  // Remove them from map //
  const size_t size = allDofs.size();

  set<Dof>::iterator end;
  set<Dof>::iterator it;
  size_t           nDof;

  for(size_t i = 0; i < size; i++){
    nDof = allDofs[i].size();

    for(size_t j = 0; j < nDof; j++){
      end = dof.end();
      it  = dof.find(allDofs[i][j]);

      if(it != end)
        dof.erase(it);
    }
  }
}
