#include <sstream>

#include "ReferenceSpaceManager.h"
#include "BasisGenerator.h"
#include "ElementType.h"
#include "Exception.h"

#include "FunctionSpace.h"

using namespace std;

FunctionSpace::FunctionSpace(void){
  // No Dof //
  dof    = NULL;
  group  = NULL;
  eToGod = NULL;
}

FunctionSpace::~FunctionSpace(void){
  // Delete Vector of Basis //
  //   (FunctionSpace is not responsible for
  //    'true' Basis Deletion)
  delete basis;

  // Dof //
  if(dof)
    delete dof;

  // Group //
  if(group){
    size_t nElement = group->size();

    for(size_t i = 0; i < nElement; i++)
      delete (*group)[i];
    delete group;
  }

  // Element To GoD //
  if(eToGod)
    delete eToGod;
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
  this->nBasis      = 1;
  this->basis       = new vector<const Basis*>(nBasis);
  (*this->basis)[0] = &basis;

  // Number of *Per* Entity functions //
  fPerVertex = (*this->basis)[0]->getNVertexBased() / nVertex;
  // NB: fPreVertex = 0 *or* 1

  if(nEdge)
    fPerEdge = (*this->basis)[0]->getNEdgeBased() / nEdge;
  else
    fPerEdge = 0;

  if(nFace)
    fPerFace = (*this->basis)[0]->getNFaceBased() / nFace;
  else
    fPerFace = 0;

  fPerCell = (*this->basis)[0]->getNCellBased();
  // We always got 1 cell

  // Build Dof //
  buildDof();
}

void FunctionSpace::buildDof(void){
  // Get Elements //
  const size_t nElement = goe->getNumber();
  const vector<const MElement*>& element = goe->getAll();

  // Init Struct //
  dof      = new set<Dof>;
  group    = new vector<GroupOfDof*>(nElement);
  eToGod   = new map<const MElement*,
                     const GroupOfDof*,
                     ElementComparator>;

  // Create Dofs //
  for(size_t i = 0; i < nElement; i++){
    // Get Dof for this Element
    vector<Dof> myDof = getKeys(*(element[i]));
    size_t nDof       = myDof.size();

    // Add Dof
    for(size_t j = 0; j < nDof; j++)
      dof->insert(myDof[j]);
    //vector<Dof> trueDof(nDof);

    //for(size_t j = 0; j < nDof; j++)
    //insertDof(myDof[j], trueDof, j);

    // Create new GroupOfDof
    GroupOfDof* god = new GroupOfDof(*(element[i]), myDof);
    (*group)[i]     = god;

    // Map GOD
    eToGod->insert(pair<const MElement*, const GroupOfDof*>
                   (element[i], god));
  }
}
/*
void FunctionSpace::insertDof(Dof& d,
                              vector<const Dof*>& trueDof,
                              size_t index){
  // Copy 'd'
  const Dof* tmp = new Dof(d);

  // Try to insert Dof //
  pair<set<const Dof*, DofComparator>::iterator, bool> p
    = dof->insert(tmp);

  // If insertion is OK (Dof 'd' didn't exist) //
  //   --> Add new Dof in GoD
  if(p.second)
    trueDof[index] = tmp;

  // If insertion failed (Dof 'd' already exists) //
  //   --> delete 'tmp' and add existing Dof in GoD
  else{
    delete tmp;
    trueDof[index] = *(p.first);
  }
}
*/

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


const GroupOfDof& FunctionSpace::
getGoDFromElement(const MElement& element) const{

  const map<const MElement*, const GroupOfDof*, ElementComparator>::iterator
    it = eToGod->find(&element);

  if(it == eToGod->end())
    throw
      Exception("Their is no GroupOfDof associated with the given MElement: %d",
                element.getNum());

  else
    return *(it->second);
}
