#include <sstream>
#include "ReferenceSpace.h"

using namespace std;

ReferenceSpace::ReferenceSpace(void){
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
  nPerm = 0;

  pTreeRoot.depth    = 0;
  pTreeRoot.last     = NULL; 
  pTreeRoot.number   = nVertex;
  pTreeRoot.possible = new unsigned int[pTreeRoot.number];
  pTreeRoot.next     = NULL;
  
  for(unsigned int i = 0; i < pTreeRoot.number; i++)
    pTreeRoot.possible[i] = i;

  // Generate Tree //
  lPerm = new list<unsigned int*>;
  generate(&pTreeRoot);

  perm = new unsigned int*[nPerm];
  for(unsigned int i = 0; i < nPerm; i++){
    perm[i] = lPerm->front();
    lPerm->pop_front();
  }
  
  delete lPerm;

  // Get Edges & Faces //
  getEdge();
  getFace();
}

void ReferenceSpace::generate(node* pTreeRoot){
  const unsigned int number = pTreeRoot->number;
  const unsigned int depth  = pTreeRoot->depth;

  if(!number){
    pTreeRoot->next = NULL;
    nPerm++;
    lPerm->push_back(pTreeRoot->last);
  }

  else{
    pTreeRoot->next = new node[number];

    for(unsigned int i = 0; i < number; i++){
      unsigned int nextDepth  = pTreeRoot->depth + 1;
      unsigned int nextLast   = pTreeRoot->possible[i];
      unsigned int nextNumber = number - 1;
      unsigned int offset     = 0;
      
      pTreeRoot->next[i].depth       = nextDepth;
      pTreeRoot->next[i].last        = new unsigned int[nextDepth];
      pTreeRoot->next[i].last[depth] = nextLast;
      
      for(unsigned int j = 0; j < depth; j++)
	pTreeRoot->next[i].last[j] = pTreeRoot->last[j];

      pTreeRoot->next[i].number   = nextNumber;
      pTreeRoot->next[i].possible = new unsigned int[nextNumber];
      
      for(unsigned int j = 0; j < nextNumber; j++){
	  if(pTreeRoot->possible[j] == nextLast)
	    offset = 1;
	  
	  pTreeRoot->next[i].possible[j] = pTreeRoot->possible[j + offset];
      }

      generate(&pTreeRoot->next[i]);
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

string ReferenceSpace::toString(void) const{
  stringstream  stream;
  
  // Tree //
  stream << "Tree:"              << endl;
  stream << toString(&pTreeRoot) << endl;

  // ReferenceSpaces //
  stream << "ReferenceSpace:" << endl;
  
  for(unsigned int i = 0; i < nPerm; i++){
    stream << "  * ";
    
    for(unsigned int j = 0; j < nVertex; j++)
      stream << perm[i][j] << " ";

    stream << " (# " << i + 1 << ")" << endl;
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
