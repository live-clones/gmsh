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
  // Basis //
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

  // Build Dof //
  buildDof();
}

void FunctionSpace::buildDof(void){
  // Get Elements //
  unsigned int nElement                  = goe->getNumber();
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
    god->add(tmp);
  
  // If insertion failed (Dof 'd' already exists) //
  //   --> delete 'd' and add existing Dof in GoD
  else{
    delete tmp; 
    god->add(*(p.first));
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
  
  // Add Face Based Dof //
  for(int i = 0; i < nFFace; i++){
    for(int j = 0; j < nFace; j++){
      myDof[it].setDof(mesh->getGlobalId(face[j]), i);
      it++;
    }
  }
  
  // Add Cell Based Dof //
  for(int i = 0; i < nFCell; i++){
    myDof[it].setDof(mesh->getGlobalId(element), i);
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

string FunctionSpace::toString(void) const{
  return basis->toString();
}
