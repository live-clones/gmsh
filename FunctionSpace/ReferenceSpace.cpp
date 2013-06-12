#include <algorithm>
#include <sstream>

#include "Exception.h"
#include "ReferenceSpace.h"

using namespace std;

ReferenceSpace::ReferenceSpace(void){
  // Init to NULL                  //
  nVertex    = 0;
  nextLeafId = 0;

  nPerm = 0;
  perm  = NULL;
  lPerm = NULL;

  pTreeRoot.depth    = 0;
  pTreeRoot.last     = NULL;
  pTreeRoot.number   = 0;
  pTreeRoot.possible = NULL;
  pTreeRoot.next     = NULL;

  nEdge           = 0;
  refEdge         = NULL;
  permutedRefEdge = NULL;
  edge            = NULL;

  nFace           = 0;
  nNodeInFace     = NULL;
  refFace         = NULL;
  permutedRefFace = NULL;
  face            = NULL;

  // Defining Ref Edge and Face in //
  // Dervived Class                //
}

ReferenceSpace::~ReferenceSpace(void){
  // Destroy Tree //
  destroy(&pTreeRoot);
  delete[] perm;

  // Delete Permutated Edge //
  for(unsigned int p = 0; p < nPerm; p++){
    for(unsigned int i = 0; i < nEdge; i++){
      delete[] permutedRefEdge[p][i];
      delete   (*(*edge)[p])[i];
    }

    delete[] permutedRefEdge[p];
    delete   (*edge)[p];
  }

  delete[] permutedRefEdge;
  delete   edge;

  // Delete Permutated Face //
  for(unsigned int p = 0; p < nPerm; p++){
    for(unsigned int i = 0; i < nFace; i++){
      delete[] permutedRefFace[p][i];
      delete (*(*face)[p])[i];
    }

    delete[] permutedRefFace[p];
    delete (*face)[p];
  }

  delete[] permutedRefFace;
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

  // Get Permutation //
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

  for(unsigned int p = 0; p < nPerm; p++){
    cout << "Permutation " << p << ":" << endl;

    for(unsigned int e = 0; e < nEdge; e++){
      cout << "  " << "Edge " << e << ": [";

      for(unsigned int n = 0; n < 2 - 1; n++)
        cout << permutedRefEdge[p][e][n] << ", ";

      cout << permutedRefEdge[p][e][2 - 1] << "]"
           << endl;
    }

    for(unsigned int f = 0; f < nFace; f++){
      cout << "  " << "Face " << f << ": [";

      for(unsigned int n = 0; n < nNodeInFace[f] - 1; n++)
        cout << permutedRefFace[p][f][n] << ", ";

      cout << permutedRefFace[p][f][nNodeInFace[f] - 1] << "]"
           << endl;
    }
  }
}

void ReferenceSpace::populate(node* pTreeRoot){
  // Get Some Data on this Root //
  const unsigned int number     = pTreeRoot->number;
  const unsigned int nextNumber = number - 1;
  const unsigned int depth      = pTreeRoot->depth;
  const unsigned int nextDepth  = depth + 1;

  // Temp Data //
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
      // Reset offset
      offset = 0;

      // Depth and Last Choices of child nodes
      pTreeRoot->next[i].depth       = nextDepth;
      pTreeRoot->next[i].last        = new unsigned int[nextDepth];
      pTreeRoot->next[i].last[depth] = pTreeRoot->possible[i];

      for(unsigned int j = 0; j < depth; j++)
        pTreeRoot->next[i].last[j] = pTreeRoot->last[j];

      // Possibilities of child node
      pTreeRoot->next[i].number   = nextNumber;
      pTreeRoot->next[i].possible = new unsigned int[nextNumber];

      for(unsigned int j = 0; j < nextNumber; j++){
        if(pTreeRoot->possible[j] == pTreeRoot->possible[i])
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
  // Alloc
  vector<const vector<unsigned int>*>* tmp;
  edge = new vector<const vector<const vector<unsigned int>*>*>(nPerm);

  // All Edges have two nodes
  unsigned int* nNodeInEdge = new unsigned int[nEdge];

  for(unsigned int e = 0; e < nEdge; e++)
    nNodeInEdge[e] = 2;

  // Get Edge nodes depending on the orientation
  //    (edge 1 = [1 2] for orientation 1)
  //    (       = [4 1] for orientation 2)
  getPermutedRefEntity(&permutedRefEdge,
                       refEdge,
                       nNodeInEdge,
                       nEdge);

  delete[] nNodeInEdge;

  // Populate Edge
  for(unsigned int p = 0; p < nPerm; p++){
    tmp = new vector<const vector<unsigned int>*>(nEdge);

    for(unsigned int e = 0; e < nEdge; e++)
      (*tmp)[e] = getOrderedEdge(p, e);

    (*edge)[p] = tmp;
  }
}

void ReferenceSpace::getFace(void){
  // Alloc
  vector<const vector<unsigned int>*>* tmp;
  face = new vector<const vector<const vector<unsigned int>*>*>(nPerm);

  // Get Face nodes depending on the orientation
  //    (face 1 = [1 2 3 4] for orientation 1)
  //    (       = [4 1 2 3] for orientation 2)
  getPermutedRefEntity(&permutedRefFace,
                       refFace,
                       nNodeInFace,
                       nFace);

  // Populate Face
  for(unsigned int p = 0; p < nPerm; p++){
    tmp = new vector<const vector<unsigned int>*>(nFace);

    for(unsigned int f = 0; f < nFace; f++){
      // Dending on the number of node per face
      // The ordering strategy is different

      switch(nNodeInFace[f]){
      case 3: (*tmp)[f] = getOrderedTriFace(p, f);  break;
      case 4: (*tmp)[f] = getOrderedQuadFace(p, f); break;

      default:
        throw Exception("I can handle face with %d nodes",
                        nNodeInFace[f]);
      }
    }

    (*face)[p] = tmp;
  }
}

void ReferenceSpace::getPermutedRefEntity(unsigned int**** permutedRefEntity,
                                          unsigned int**   refEntity,
                                          unsigned int*    nNodeInEntity,
                                          unsigned int     nEntity){
  // Alloc PermutedRefEntity
  (*permutedRefEntity) = new unsigned int**[nPerm];

  for(unsigned int p = 0; p < nPerm; p++){
    (*permutedRefEntity)[p] = new unsigned int*[nEntity];

    for(unsigned int e = 0; e < nEntity; e++)
      (*permutedRefEntity)[p][e] = new unsigned int[nNodeInEntity[e]];
  }

  // Alloc Idx
  unsigned int** idx = new unsigned int*[nEntity];

  for(unsigned int e = 0; e < nEntity; e++)
    idx[e] = new unsigned int[nNodeInEntity[e]];

  // Get Reference Index
  //  Use refEntity and perm[0] as reference element
  for(unsigned int e = 0; e < nEntity; e++)
    getIndex(nNodeInEntity[e], refEntity[e], nVertex, perm[0], &idx[e]);

  // Generate Permuted Ref Entity
  for(unsigned int p = 0; p < nPerm; p++){
    for(unsigned int e = 0; e < nEntity; e++){
      for(unsigned int n = 0; n < nNodeInEntity[e]; n++)
        (*permutedRefEntity)[p][e][n] = perm[p][idx[e][n]];
    }
  }

  // Delete Temp
  for(unsigned int e = 0; e < nEntity; e++)
    delete[] idx[e];

  delete[] idx;
}

const vector<unsigned int>* ReferenceSpace::
getOrderedEdge(unsigned int permutation,
               unsigned int edge){

  /*************************************************************************
   * Let say we have we have permutedRefEdge[4][2] = [0 1].                *
   * I want to get back to same node ID than refEdge[2] = [2 0].           *
   * That is, I want to return [0 2].                                      *
   *                                                                       *
   * I need to sort permutedRefEdge and keep the index swaping.            *
   * I can use this index swaping to get the right permutation of refEdge. *
   *************************************************************************/

  // Alloc
  vector<unsigned int>* ordered = new vector<unsigned int>(2);

  // Sort & Swap
  sortAndSwap(permutedRefEdge[permutation][edge],
              refEdge[edge],
              *ordered);

  // Return ordered
  return ordered;
}

const std::vector<unsigned int>* ReferenceSpace::
getOrderedTriFace(unsigned int permutation,
                  unsigned int face){

  /******************************************************
   * Same as getOrderedEdge, but I need to use 3 nodes. *
   ******************************************************/

  // Alloc
  vector<unsigned int>* ordered = new vector<unsigned int>(3);

  // Sort & Swap
  sortAndSwap(permutedRefFace[permutation][face],
              refFace[face],
              *ordered);

  // Return ordered
  return ordered;
}

const std::vector<unsigned int>* ReferenceSpace::
getOrderedQuadFace(unsigned int permutation,
                   unsigned int face){

  /*********************************************************************
   * Same as getOrderedEdge, but I need to use 4 nodes.                *
   *                                                                   *
   * Moreover,                                                         *
   * I need node at ordered[2] to be *opposite* to node at ordered[0]. *
   *  --> If not make a permutation such                               *
   *      that node opposite at ordered[2]                             *
   *      is at ordered[0]                                             *
   *********************************************************************/

  // Alloc
  vector<unsigned int>* ordered = new vector<unsigned int>(4);

  // Sort & Swap
  sortAndSwap(permutedRefFace[permutation][face],
              refFace[face],
              *ordered);

  // Get ordered[2] opposite to ordered[0]
  unsigned int opposite = ((*ordered)[0] + 2) % 4;

  if((*ordered)[2] != opposite){
    // Find opposite node index
    unsigned int tmp;
    unsigned int idx = 1;
    while((*ordered)[idx] != opposite)
      idx++;

    // Swap ordered[2] and ordered[idx]
    tmp = (*ordered)[2];
    (*ordered)[2]   = opposite;
    (*ordered)[idx] = tmp;
  }

  // Return
  return ordered;
}

void ReferenceSpace::sortAndSwap(unsigned int* srcSort,
                                 unsigned int* srcSwap,
                                 vector<unsigned int>& dest){
  // Get Size
  const unsigned int size = dest.size();

  // Copy srcSort in sorted
  vector<pair<unsigned int, unsigned int> > sorted(size);

  for(unsigned int i = 0; i < size; i++){
    sorted[i].first  = i;
    sorted[i].second = srcSort[i];
  }

  // Sort it with repsect to second entry
  std::sort(sorted.begin(), sorted.end(), sortPredicate);

  // Swap with respect to srcSwap
  for(unsigned int i = 0; i < size; i++)
    dest[i] = srcSwap[sorted[i].first];
}

unsigned int ReferenceSpace::getPermutation(const MElement& elem) const{
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Get Primary Vertices Global ID //
  const int nVertex = element.getNumPrimaryVertices();
  vector<pair<unsigned int, unsigned int> > vertexGlobalId(nVertex);

  for(int i = 0; i < nVertex; i++){
    vertexGlobalId[i].first  = i;
    vertexGlobalId[i].second = element.getVertex(i)->getNum();
  }

  // Sort Them with repsect to Vertex Global ID //
  //                 (vertex[i].second->getNum) //
  std::sort(vertexGlobalId.begin(), vertexGlobalId.end(), sortPredicate);

  // Reduce Vertex Global ID //
  vector<unsigned int> vertexReducedId(nVertex);

  for(int i = 0; i < nVertex; i++)
    vertexReducedId[vertexGlobalId[i].first] = i;

  // Tree Lookup //
  try{
    return treeLookup(&pTreeRoot, vertexReducedId);
  }

  catch(...){
    throw Exception("Cannot Find Reference Space for Element %d",
                    element.getNum());
  }
}

unsigned int ReferenceSpace::treeLookup(const node* node,
                                        vector<unsigned int>& vertexReducedId){
  // Temp Data //
  unsigned int choice;
  unsigned int i;

  // If Node is *not* a Leaf: Lookup //
  if(node->number){
    // Get This Choice
    choice = vertexReducedId[node->depth];

    // Look for next node corresponding to this Choice
    i = 0;
    while(node->possible[i] != choice)
      i++;

    // Look if a this Choice has been found
    if(i == node->number)
      throw Exception();

    // Go to next Node
    return treeLookup(&node->next[i], vertexReducedId);
  }

  // Else: Return Leaf ID //
  else
    return node->leafId;
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

string ReferenceSpace::toLatex(void) const{
  stringstream stream;

  stream << "\\documentclass{article}" << endl << endl
         << "\\begin{document}"        << endl

         << "\texttt{toLatex} not implemented" << endl

         << "\\end{document}"          << endl;

  return stream.str();
}
