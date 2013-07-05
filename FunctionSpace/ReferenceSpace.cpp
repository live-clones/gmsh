#include <algorithm>
#include <sstream>

#include "Exception.h"
#include "ReferenceSpace.h"

using namespace std;

ReferenceSpace::ReferenceSpace(void){
  // Init to NULL                  //
  nEdge           = 0;
  refEdge         = NULL;
  //permutedRefEdge = NULL;
  edge            = NULL;

  nFace           = 0;
  nNodeInFace     = NULL;
  refFace         = NULL;
  //permutedRefFace = NULL;
  face            = NULL;

  // Defining Ref Edge and Face in //
  // Derived Class                 //
}

ReferenceSpace::~ReferenceSpace(void){
  const size_t nPerm = pTree->getNPermutation();

  // Destroy Tree //
  delete pTree;

  // Delete Permutated Edge //
  for(size_t p = 0; p < nPerm; p++){
    for(size_t i = 0; i < nEdge; i++){
      //delete[] permutedRefEdge[p][i];
      delete   (*(*edge)[p])[i];
    }

    //delete[] permutedRefEdge[p];
    delete   (*edge)[p];
  }

  //delete[] permutedRefEdge;
  delete   edge;

  // Delete Permutated Face //
  for(size_t p = 0; p < nPerm; p++){
    for(size_t i = 0; i < nFace; i++){
      //delete[] permutedRefFace[p][i];
      delete (*(*face)[p])[i];
    }

    //delete[] permutedRefFace[p];
    delete (*face)[p];
  }

  //delete[] permutedRefFace;
  delete face;
}

void ReferenceSpace::init(void){
  // Tree //
  vector<size_t> vertexSeq(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    vertexSeq[i] = i;

  pTree = new PermutationTree(vertexSeq);

  // Edges & Faces //
  getEdge();
  getFace();

  // Cyclic Permutation //
  findCyclicPermutation();
}

void ReferenceSpace::findCyclicPermutation(void){
  // Alloc Some Data //
  const size_t nPerm = pTree->getNPermutation();

  list<size_t>          listOfTrueReferenceSpace;
  list<vector<size_t> > listOfRefNodeIndexPermutation;
  list<vector<size_t> > listOfReverseNodeIndexPermutation;

  vector<size_t> pTest(nVertex);
  vector<size_t> pRef(nVertex);

  list<size_t>::iterator it;
  list<size_t>::iterator end;
  triple match;

  vector<size_t> unPermutedIndex(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    unPermutedIndex[i] = i;

  // Find Cyclic Permutation
  for(size_t i = 0; i < nPerm; i++){
    // No match
    match.first = false;

    // Get Permutation 'i'
    pTree->fillWithPermutation(i, pTest);

    // Test it with already found Reference Space
    it  = listOfTrueReferenceSpace.begin();
    end = listOfTrueReferenceSpace.end();

    while(it != end && !match.first){
      // Take Reference Space 'it'
      pTree->fillWithPermutation(*it, pRef);

      // Look if it matches
      match = isCyclicPermutation(pTest, pRef);

      // If not, go to next Reference Space
      if(!match.first)
        it++;
    }

    // If no Reference Space is found
    //   --> this Permutation is a new Reference Space
    if(!match.first){
      listOfTrueReferenceSpace.push_back(i);
      listOfRefNodeIndexPermutation.push_back(unPermutedIndex);
      listOfReverseNodeIndexPermutation.push_back(unPermutedIndex);

      pTree->addTagToPermutation(i, i);
    }

    // If a ReferenceSpace is found, and the index permutations
    else{
      listOfRefNodeIndexPermutation.push_back(match.second);
      listOfReverseNodeIndexPermutation.push_back(match.third);
      pTree->addTagToPermutation(i, *it);
    }
  }
}

static bool isFacePermutation(vector<size_t>& refNode,
                              vector<size_t>& testNode){
  const size_t size = refNode.size();
  bool match = false;

  if(size != testNode.size())
    return false;

  for(size_t i = 0; i < size && !match; i++){
    bool submatch = true;

    for(size_t j = 0; j < size && submatch; j++)
      if(refNode[j] != testNode[j])
        submatch = false;

    if(!submatch){
      size_t tmp0 = testNode[0];
      size_t tmp1 = testNode[1];

      for(size_t k = 1; k < size + 1; k++){
        testNode[k % size] = tmp0;
        tmp0 = tmp1;
        tmp1 = testNode[(k + 1) % size];
      }
    }

    else
      match = true;
  }

  return match;
}

static bool haveSameNode(vector<size_t>& face0,
                         vector<size_t>& face1){
  const size_t size = face0.size();
  bool matchIsPossible = true;

  for(size_t i = 0; i < size && matchIsPossible; i++){
    bool submatch = false;

    for(size_t j = 0; j < size && !submatch; j++){
      if(face0[i] == face1[j])
        submatch = true;
    }

    matchIsPossible = submatch;
  }

  return matchIsPossible;
}

size_t ReferenceSpace::findCorrespondingFace(vector<size_t>& face,
                                             vector<size_t>& node){
  // Init Stuff //
  const size_t faceSize = face.size();
  bool match = false;
  size_t f = 0;

  vector<size_t> testFace(faceSize);

  // Test All Face until match
  while(!match && f < nFace){

    if(nNodeInFace[f] == faceSize){
      // Get face f nodes
      for(size_t i = 0; i < faceSize; i++)
        testFace[i] = node[refFace[f][i]];

      // Look if match
      match = haveSameNode(testFace, face);
    }

    if(!match)
      f++;
  }

  return f;
}

static vector<size_t> getRefIndexPermutation(vector<size_t>& ref,
                                             vector<size_t>& test){
  const size_t size = ref.size();
  vector<size_t> idxVec(ref.size());
  size_t idx;

  for(size_t i = 0; i < size; i++){
    idx = 0;

    while(test[i] != ref[idx])
      idx++;

    idxVec[i] = idx;
  }

  return idxVec;
}

static vector<size_t> getReverseIndexPermutation(vector<size_t>& ref,
                                                 vector<size_t>& test){
  const size_t size = ref.size();
  vector<size_t> idxVec(ref.size());
  size_t idx;

  for(size_t i = 0; i < size; i++){
    idx = 0;

    while(test[idx] != ref[i])
      idx++;

    idxVec[i] = idx;
  }

  return idxVec;
}

ReferenceSpace::triple ReferenceSpace::
isCyclicPermutation(vector<size_t>& pTest,
                    vector<size_t>& pRef){

  // Node IDs of Reference Space first Face
  vector<size_t> refNode(nNodeInFace[0]);

  for(size_t i = 0; i < nNodeInFace[0]; i++)
    refNode[i] = pRef[refFace[0][i]];

  // Corresponding Face in Test Permutation
  size_t testFaceId = findCorrespondingFace(refNode, pTest);

  // Node IDs of Test Permutation correspnding Face
  vector<size_t> testNode(nNodeInFace[testFaceId]);

  for(size_t i = 0; i < nNodeInFace[testFaceId]; i++)
    testNode[i] = pTest[refFace[testFaceId][i]];

  // Return Triple //
  triple tri = {
    isFacePermutation(refNode, testNode),
    getRefIndexPermutation(pRef, pTest),
    getReverseIndexPermutation(pRef, pTest)
  };

  return tri;
}

void ReferenceSpace::getEdge(void){
  const size_t nPerm = pTree->getNPermutation();

  // Alloc
  vector<const vector<unsigned int>*>* tmp;
  edge = new vector<const vector<const vector<unsigned int>*>*>(nPerm);
  /*
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
  */
  // Populate Edge
  for(size_t p = 0; p < nPerm; p++){
    tmp = new vector<const vector<unsigned int>*>(nEdge);

    for(size_t e = 0; e < nEdge; e++)
      (*tmp)[e] = getOrderedEdge(p, e);

    (*edge)[p] = tmp;
  }
}

void ReferenceSpace::getFace(void){
  const size_t nPerm = pTree->getNPermutation();

  // Alloc
  vector<const vector<unsigned int>*>* tmp;
  face = new vector<const vector<const vector<unsigned int>*>*>(nPerm);
  /*
  // Get Face nodes depending on the orientation
  //    (face 1 = [1 2 3 4] for orientation 1)
  //    (       = [4 1 2 3] for orientation 2)
  getPermutedRefEntity(&permutedRefFace,
                       refFace,
                       nNodeInFace,
                       nFace);
  */
  // Populate Face
  for(size_t p = 0; p < nPerm; p++){
    tmp = new vector<const vector<unsigned int>*>(nFace);

    for(size_t f = 0; f < nFace; f++){
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
/*
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

  // Generate Permuted Ref Entity
  for(unsigned int p = 0; p < nPerm; p++){
    for(unsigned int e = 0; e < nEntity; e++){
      for(unsigned int n = 0; n < nNodeInEntity[e]; n++)
        (*permutedRefEntity)[p][e][n] = perm[p][refEntity[e][n]];
    }
  }
}
*/
const vector<unsigned int>* ReferenceSpace::
getOrderedEdge(unsigned int permutation,
               unsigned int edge){

  /**************************************************************************
   * I want to know how I need to take the values of refEdge[edge]          *
   * (i.e the node *index* of a given edge) so that the corresponding       *
   * values in permutation (i.e perm[permutation][refEdge[edge]]) are going *
   * from the smallest value to the biggest.                                *
   **************************************************************************/

  // Alloc
  vector<unsigned int>* ordered = new vector<unsigned int>(2);

  // Permutation
  vector<size_t> perm(nVertex);
  pTree->fillWithPermutation(permutation, perm);

  // Order refEdge
  orderRefEntityForGivenPermutation(refEdge[edge],
                                    perm,
                                    *ordered);

  // Return ordered
  return ordered;
}

const std::vector<unsigned int>* ReferenceSpace::
getOrderedTriFace(unsigned int permutation,
                  unsigned int face){

  /***********************************************
   * Same as getOrderedEdge, but I with refFace. *
   ***********************************************/

  // Alloc
  vector<unsigned int>* ordered = new vector<unsigned int>(3);

  // Permutation
  vector<size_t> perm(nVertex);
  pTree->fillWithPermutation(permutation, perm);

  // Order refFace
  orderRefEntityForGivenPermutation(refFace[face],
                                    perm,
                                    *ordered);

  // Return ordered
  return ordered;
}

const std::vector<unsigned int>* ReferenceSpace::
getOrderedQuadFace(unsigned int permutation,
                   unsigned int face){

  /*********************************************************************
   * Same as getOrderedFace, but refFace has 4 nodes.                  *
   *                                                                   *
   * In that case,                                                     *
   * I need node at ordered[2] to be *opposite* to node at ordered[0]. *
   *  --> If not make a permutation such                               *
   *      that node opposite at ordered[2]                             *
   *      is at ordered[0]                                             *
   *********************************************************************/

  // Alloc
  vector<unsigned int>* ordered = new vector<unsigned int>(4);

  // Permutation
  vector<size_t> perm(nVertex);
  pTree->fillWithPermutation(permutation, perm);

  // Order refFace
  orderRefEntityForGivenPermutation(refFace[face],
                                    perm,
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

void ReferenceSpace::
orderRefEntityForGivenPermutation(size_t* refEntity,
                                  vector<size_t>& permutation,
                                  vector<unsigned int>& orderedEntity){
  // Get Size
  const unsigned int size = orderedEntity.size();

  // Copy srcSort in sorted
  vector<pair<unsigned int, unsigned int> > sorted(size);

  for(unsigned int i = 0; i < size; i++){
    sorted[i].first  = i;
    sorted[i].second = permutation[refEntity[i]];
  }

  // Sort it with repsect to second entry
  std::sort(sorted.begin(), sorted.end(), sortPredicate);

  // Swap with respect to srcSwap
  for(unsigned int i = 0; i < size; i++)
    orderedEntity[i] = refEntity[sorted[i].first];
}

size_t ReferenceSpace::getReferenceSpace(const MElement& elem) const{
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
  vector<size_t> vertexReducedId(nVertex);

  for(int i = 0; i < nVertex; i++)
    vertexReducedId[vertexGlobalId[i].first] = i;

  // Tree Lookup //
  try{
    return pTree->getPermutationId(vertexReducedId);
  }

  catch(...){
    throw Exception("Cannot Find Reference Space for Element %d",
                    element.getNum());
  }
}

string ReferenceSpace::toString(void) const{
  const size_t nPerm = pTree->getNPermutation();
  stringstream stream;

  // ReferenceSpaces //
  stream << "Reference Spaces:" << endl
         << pTree->toString()   << endl;

  stream << "Edges Permutations:" << endl;

  for(size_t i = 0; i < nPerm; i++){
    stream << "  * RefSpace #" << i + 1 << ":" << endl;

    for(size_t j = 0; j < nEdge; j++)
      stream << "      -- ["
             << edge->at(i)->at(j)->at(0) << ", "
             << edge->at(i)->at(j)->at(1) << "]" << endl;
  }

  stream << "Faces Permutations:" << endl;

  for(size_t i = 0; i < nPerm; i++){
    stream << "  * RefSpace #" << i + 1 << ":" << endl;

    for(size_t j = 0; j < nFace; j++)
      stream << "      -- ["
             << face->at(i)->at(j)->at(0) << ", "
             << face->at(i)->at(j)->at(1) << ", "
             << face->at(i)->at(j)->at(2) << "]" << endl;
  }

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
