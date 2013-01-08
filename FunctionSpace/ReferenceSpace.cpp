#include <algorithm>
#include <sstream>

#include "Exception.h"
#include "ReferenceSpace.h"

using namespace std;

ReferenceSpace::ReferenceSpace(void){
  // Defining Ref Edge and Face in //
  // Dervived Class                //
  // And CALL INIT()               //
}

ReferenceSpace::~ReferenceSpace(void){
  // Destroy Tree //
  destroy(&pTreeRoot);
  delete[] perm;
 
  // Delete Permutated Edge //
  for(unsigned int p = 0; p < nPerm; p++){
    for(unsigned int i = 0; i < nEdge; i++)
      delete (*(*edge)[p])[i];      
    
    delete (*edge)[p];
  }
  
  delete edge;

  // Delete Permutated Face //
  for(unsigned int p = 0; p < nPerm; p++){
    for(unsigned int i = 0; i < nFace; i++)
      delete (*(*face)[p])[i];      
    
    delete (*face)[p];
  }
  
  delete face;
}

void ReferenceSpace::init(void){
  // Init Root //
  nPerm      = 0;
  nextLeafId = 0;

  pTreeRoot.depth    = 0;
  pTreeRoot.last     = NULL; 
  pTreeRoot.number   = nVertex;
  pTreeRoot.possible = new unsigned int[pTreeRoot.number];
  pTreeRoot.next     = NULL;
  
  for(unsigned int i = 0; i < pTreeRoot.number; i++)
    pTreeRoot.possible[i] = i;

  // Populate Tree //
  lPerm = new list<unsigned int*>;
  populate(&pTreeRoot);

  // Get Permutations //
  perm = new unsigned int*[nPerm];
  for(unsigned int i = 0; i < nPerm; i++){
    // Take Permutation for queue
    //             (AND IN ORDER)
    perm[i] = lPerm->front();
    lPerm->pop_front();
  }
  
  delete lPerm;

  // Get Edges & Faces //
  getEdge();
  getFace();
}

void ReferenceSpace::populate(node* pTreeRoot){
  // Get Some Data on this Root //
  const unsigned int number     = pTreeRoot->number;
  const unsigned int nextNumber = number - 1;
  const unsigned int depth      = pTreeRoot->depth;
  const unsigned int nextDepth  = pTreeRoot->depth + 1;

  // Temp Data //
  unsigned int nextLast;
  unsigned int offset;

  // If Leaf : a new permutation is found //
  if(!number){
    // Init Permutation
    pTreeRoot->next   = NULL;
    pTreeRoot->leafId = nextLeafId;
    
    // Value for Next Permutation
    nextLeafId++;
    nPerm++;
    
    // Put this Permutation in queue 
    //                (AND IN ORDER)
    lPerm->push_back(pTreeRoot->last);
  }

  // Else: continue to build the tree //
  else{
    // We got 'number' child nodes
    pTreeRoot->next = new node[number];

    // Init each child node 
    for(unsigned int i = 0; i < number; i++){
      nextLast = pTreeRoot->possible[i];
      offset   = 0;
      
      // Depth and Last Choices of child nodes
      pTreeRoot->next[i].depth       = nextDepth;
      pTreeRoot->next[i].last        = new unsigned int[nextDepth];
      pTreeRoot->next[i].last[depth] = nextLast;
      
      for(unsigned int j = 0; j < depth; j++)
	pTreeRoot->next[i].last[j] = pTreeRoot->last[j];

      // Possibilities of child node
      pTreeRoot->next[i].number   = nextNumber;
      pTreeRoot->next[i].possible = new unsigned int[nextNumber];
      
      for(unsigned int j = 0; j < nextNumber; j++){
	  if(pTreeRoot->possible[j] == nextLast)
	    offset = 1;
	  
	  pTreeRoot->next[i].possible[j] = pTreeRoot->possible[j + offset];
      }

      // Populate each child node (until a leaf is found)
      populate(&pTreeRoot->next[i]);
    }
  }
}

void ReferenceSpace::destroy(node* node){
  const unsigned int number = node->number;

  for(unsigned int i = 0; i < number; i++){
    destroy(&node->next[i]);
    node->number--;
  }
    
  delete[] node->possible;
  delete[] node->last;
  delete[] node->next;
}

void ReferenceSpace::getEdge(void){
  vector<const vector<unsigned int>*>* tmp;
  edge = new vector<const vector<const vector<unsigned int>*>*>(nPerm);

  for(unsigned int p = 0; p < nPerm; p++){
    tmp = new vector<const vector<unsigned int>*>(nEdge);

    for(unsigned int i = 0; i < nEdge; i++)
      (*tmp)[i] = inOrder(p, 
			  refEdge[i][0], 
			  refEdge[i][1]);   
    (*edge)[p] = tmp;
  }
}

void ReferenceSpace::getFace(void){
  vector<const vector<unsigned int>*>* tmp;
  face = new vector<const vector<const vector<unsigned int>*>*>(nPerm);

  for(unsigned int p = 0; p < nPerm; p++){
    tmp = new vector<const vector<unsigned int>*>(nFace);

    for(unsigned int i = 0; i < nFace; i++)
      (*tmp)[i] = inOrder(p, 
			  refFace[i][0], 
			  refFace[i][1],
			  refFace[i][2]);   
    (*face)[p] = tmp;
  }
}

const vector<unsigned int>* ReferenceSpace::
inOrder(unsigned int permutation, 
	unsigned int a, 
	unsigned int b){
  
  unsigned int v;
  unsigned int k = 0;
  vector<unsigned int>* inorder = 
    new vector<unsigned int>(2);

  for(unsigned int i = 0; i < nVertex; i++){
    v = perm[permutation][i];
    
    if(v == a || v == b){   
      (*inorder)[k] = v;
      k++;
    }
  }
  
  return inorder;
}

const std::vector<unsigned int>* ReferenceSpace::
inOrder(unsigned int permutation, 
	unsigned int a, 
	unsigned int b,
	unsigned int c){
  
  unsigned int v;
  unsigned int k = 0;
  vector<unsigned int>* inorder = 
    new vector<unsigned int>(3);

  for(unsigned int i = 0; i < nVertex; i++){
    v = perm[permutation][i];
    
    if(v == a || v == b || v == c){   
      (*inorder)[k] = v;
      k++;
    }
  }
  
  return inorder;  
}

unsigned int ReferenceSpace::getReferenceSpace(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Get Primary Vertices //
  const int nVertex = element.getNumPrimaryVertices();
  vector<pair<unsigned int, MVertex*> > vertex(nVertex);

  for(int i = 0; i < nVertex; i++){
    vertex[i].first  = i;
    vertex[i].second = element.getVertex(i);  
  }
  
  // Sort Them with repsect to Vertex Global ID // 
  //                 (vertex[i].second->getNum) //
  std::sort(vertex.begin(), vertex.end(), sortPredicate);  

  // Tree Lookup //
  try{
    return treeLookup(&pTreeRoot, vertex);
  }

  catch(...){
    throw Exception("Cannot Find Reference Space for Element %d",
		    element.getNum());
  }
}

unsigned int ReferenceSpace::treeLookup(const node* root,
					vector<pair<unsigned int, MVertex*> >& 
					sortedArray){
  // Temp Data //
  unsigned int choice;
  unsigned int i;

  // If Root is *not* a Leaf: Lookup //
  if(root->number){
    // Get This Choice
    choice = sortedArray[root->depth].first;

    // Look for next node corresponding to this Choice
    i = 0;
    while(root->possible[i] != choice)
      i++;

    // Look if a this Choice has been found
    if(i == root->number)
      throw Exception();

    // Go to next Node
    return treeLookup(&root->next[i], sortedArray);
  }

  // Else: Return Leaf ID //
  else
    return root->leafId; 
}

string ReferenceSpace::toString(void) const{
  stringstream  stream;
  
  // Tree //
  stream << "Tree:"              << endl;
  stream << toString(&pTreeRoot) << endl;

  // ReferenceSpaces //
  stream << "Reference Spaces:" << endl;
  
  for(unsigned int i = 0; i < nPerm; i++){
    stream << "  * ";
    
    for(unsigned int j = 0; j < nVertex; j++)
      stream << perm[i][j] << " ";

    stream << " (# " << i + 1 << ")" << endl;
  }

  stream << "Edges Permutations:" << endl;
  
  for(unsigned int i = 0; i < nPerm; i++){
    stream << "  * RefSpace #" << i + 1 << ":" << endl;
    
    for(unsigned int j = 0; j < nEdge; j++)
      stream << "      -- [" 
	     << edge->at(i)->at(j)->at(0) << ", "
	     << edge->at(i)->at(j)->at(1) << "]" << endl;
  }

  stream << "Faces Permutations:" << endl;
  
  for(unsigned int i = 0; i < nPerm; i++){
    stream << "  * RefSpace #" << i + 1 << ":" << endl;
    
    for(unsigned int j = 0; j < nFace; j++)
      stream << "      -- [" 
	     << face->at(i)->at(j)->at(0) << ", "
	     << face->at(i)->at(j)->at(1) << ", "
	     << face->at(i)->at(j)->at(2) << "]" << endl;
  }

  return stream.str();
}

string ReferenceSpace::toString(const node* node) const{
  const unsigned int number = node->number;
  stringstream       stream;

  if(node->last)
    stream << "(" << node->last[node->depth - 1] << " ";
  else
    stream << "(root ";

  for(unsigned int i = 0; i < number; i++)
    stream << toString(&node->next[i]);

  stream << ")";
  
  return stream.str();
}
