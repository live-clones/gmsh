#include <sstream>
#include "FunctionSpace.h"
#include "BasisGenerator.h"
#include "Exception.h"

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
  if(dof){
    set<const Dof*>::iterator dStop = dof->end();
    set<const Dof*>::iterator dIt   = dof->begin();

    for(; dIt != dStop; dIt++)
      delete *dIt;
    delete dof;
  }

  // Group //
  if(group){
    unsigned int nElement = group->size();

    for(unsigned int i = 0; i < nElement; i++)
      delete (*group)[i];
    delete group;
  }

  // Element To GoD //
  if(eToGod)
    delete eToGod;

  // Unorient GroupOfElement //
  goe->unoriented();
}

void FunctionSpace::build(GroupOfElement& goe,
                          const Basis& basis){

  // Save GroupOfElement & Mesh //
  this->goe  = &goe;
  this->mesh = &(goe.getMesh());

  // Orient All Elements //
  goe.orientAllElements(basis); // NOT SEXY: TO BE REMOVED

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
  const unsigned int nElement = goe->getNumber();
  const vector<const MElement*>& element = goe->getAll();

  // Init Struct //
  dof      = new set<const Dof*, DofComparator>;
  group    = new vector<GroupOfDof*>(nElement);
  eToGod   = new map<const MElement*,
                     const GroupOfDof*,
                     ElementComparator>;

  // Create Dofs //
  for(unsigned int i = 0; i < nElement; i++){
    // Get Dof for this Element
    vector<Dof> myDof = getKeys(*(element[i]));
    unsigned int nDof = myDof.size();

    // Add Dof
    vector<const Dof*> trueDof(nDof);

    for(unsigned int j = 0; j < nDof; j++)
      insertDof(myDof[j], trueDof, j);

    // Create new GroupOfDof
    GroupOfDof* god = new GroupOfDof(*(element[i]), trueDof);
    (*group)[i]     = god;

    // Map GOD
    eToGod->insert(pair<const MElement*, const GroupOfDof*>
                   (element[i], god));
  }
}

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

vector<Dof> FunctionSpace::getKeys(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Create New Element With Permuted Vertices //
  // Permutation
  const vector<size_t>& vPerm =
    (*this->basis)[0]->getReferenceSpace().getNodeIndexFromABCtoUVW(elem);

  // Permuted Vertices
  const size_t nVertex = element.getNumPrimaryVertices();
  vector<MVertex*> vertex(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    vertex[i] = element.getVertex(vPerm[i]);

  // New Element
  MElementFactory factory;
  MElement* permElement = factory.create(elem.getTypeForMSH(), vertex);

  // Edge & Face from Permuted Element //
  const size_t nEdge = permElement->getNumEdges();
  const size_t nFace = permElement->getNumFaces();

  vector<MEdge> edge(nEdge);
  vector<MFace> face(nFace);

  for(size_t i = 0; i < nEdge; i++)
    edge[i] = permElement->getEdge(i);

  for(size_t i = 0; i < nFace; i++)
    face[i] = permElement->getFace(i);

  delete permElement;

  // Create Dof //
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
  for(size_t j = 0; j < fPerCell; j++){
    myDof[it].setDof(mesh->getGlobalId(element), j);
    it++;
  }

  return myDof;
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
