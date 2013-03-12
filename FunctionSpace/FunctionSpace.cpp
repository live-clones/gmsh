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

    // Create new GroupOfDof
    GroupOfDof* god = new GroupOfDof(nDof, *(element[i]));
    (*group)[i]     = god;

    // Add Dof
    for(unsigned int j = 0; j < nDof; j++)
      insertDof(myDof[j], god);

    // Map GOD
    eToGod->insert(pair<const MElement*, const GroupOfDof*>
		   (element[i], god));
  }
}

void FunctionSpace::insertDof(Dof& d, GroupOfDof* god){
  // Copy 'd'
  const Dof* tmp = new Dof(d);

  // Try to insert Dof //
  pair<set<const Dof*, DofComparator>::iterator, bool> p
    = dof->insert(tmp);

  // If insertion is OK (Dof 'd' didn't exist) //
  //   --> Add new Dof in GoD
  if(p.second)
    god->add(*tmp);

  // If insertion failed (Dof 'd' already exists) //
  //   --> delete 'd' and add existing Dof in GoD
  else{
    delete tmp;
    god->add(*(*(p.first)));
  }
}

vector<Dof> FunctionSpace::getKeys(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Get Element Data //
  const unsigned int nVertex = element.getNumPrimaryVertices();
  const unsigned int nEdge   = element.getNumEdges();
  const unsigned int nFace   = element.getNumFaces();

  vector<MVertex*> vertex(nVertex);
  vector<MEdge> edge(nEdge);
  vector<MFace> face(nFace);

  for(unsigned int i = 0; i < nVertex; i++)
    vertex[i] = element.getVertex(i);

  for(unsigned int i = 0; i < nEdge; i++)
    edge[i] = element.getEdge(i);

  for(unsigned int i = 0; i < nFace; i++)
    face[i] = element.getFace(i);

  // Create Dof //
  unsigned int nDof =
    fPerVertex * nVertex +
    fPerEdge   * nEdge   +
    fPerFace   * nFace   +
    fPerCell;

  vector<Dof> myDof(nDof);

  unsigned int it = 0;

  // Add Vertex Based Dof //
  for(unsigned int i = 0; i < nVertex; i++){
    for(unsigned int j = 0; j < fPerVertex; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[i]), j);
      it++;
    }
  }

  // Add Edge Based Dof //
  for(unsigned int i = 0; i < nEdge; i++){
    for(unsigned int j = 0; j < fPerEdge; j++){
      myDof[it].setDof(mesh->getGlobalId(edge[i]), j);
      it++;
    }
  }

  // Add Face Based Dof //
  for(unsigned int i = 0; i < nFace; i++){
    for(unsigned int j = 0; j < fPerFace; j++){
      myDof[it].setDof(mesh->getGlobalId(face[i]), j);
      it++;
    }
  }

  // Add Cell Based Dof //
  for(unsigned int j = 0; j < fPerCell; j++){
    myDof[it].setDof(mesh->getGlobalId(element), j);
    it++;
  }

  return myDof;
}

const GroupOfDof& FunctionSpace::getGoDFromElement(const MElement& element) const{
  const map<const MElement*, const GroupOfDof*, ElementComparator>::iterator it =
    eToGod->find(&element);

  if(it == eToGod->end())
    throw
      Exception("Their is no GroupOfDof associated with the given MElement");

  else
    return *(it->second);
}
