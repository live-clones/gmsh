#include <sstream>
#include "ReferenceSpaceLagrange.h"

using namespace std;

ReferenceSpaceLagrange::ReferenceSpaceLagrange(void){
  // Init to NULL //
  node = NULL;
}

ReferenceSpaceLagrange::~ReferenceSpaceLagrange(void){
  const size_t nPerm = pTree->getNPermutation();

  // If 'node' allocated //
  if(node){
    for(size_t p = 0; p < nPerm; p++)
      delete (*node)[p];

    delete node;
  }
}

void ReferenceSpaceLagrange::getLagrangeNode(void){
  const size_t nPerm = pTree->getNPermutation();

  // Alloc //
  vector<unsigned int>* tmp;
  node = new vector<const vector<unsigned int>*>(nPerm);

  // Populate //
  for(unsigned int p = 0; p < nPerm; p++){
    // Alloc Temp //
    tmp = new vector<unsigned int>(nNode);

    // Vertex based node
    for(unsigned int i = 0; i < nVertex; i++)
      (*tmp)[i] = i;

    // Edge based node
    for(unsigned int e = 0; e < nEdge; e++)
      edgeSeq(*tmp,
              nVertex + nNodePerEdge *  e,
              nVertex + nNodePerEdge *  e,
              nVertex + nNodePerEdge * (e + 1),
              refEdge[e],
              *(*(*edge)[p])[e]);

    // Face based node
    for(unsigned int f = 0; f < nFace; f++)
      faceSeq(*tmp,
              nVertex + nNodePerEdge * nEdge + nNodePerFace *  f,
              nVertex + nNodePerEdge * nEdge + nNodePerFace *  f,
              nVertex + nNodePerEdge * nEdge + nNodePerFace * (f + 1),
              refFace[f],
              *(*(*face)[p])[f],
              nNodePerEdge);

    // Insert in node
    (*node)[p] = tmp;
  }
}

void ReferenceSpaceLagrange::edgeSeq(vector<unsigned int>& vec,
                                     unsigned int  startIdx,
                                     unsigned int  startVal,
                                     unsigned int  stopVal,
                                     size_t* refEdge,
                                     const vector<unsigned int>& edge){

  // Is reverted ? //
  const bool isRevert = (edge[0] != refEdge[0]);

  // Index //
  unsigned int val = startVal;
  unsigned int idx;

  // Depending if edge is reverted ...
  if(isRevert)
    idx = startIdx + stopVal - startVal - 1;

  else
    idx = startIdx;

  // Populate //
  for(; val < stopVal; val++){
    vec[idx] = val;

    if(isRevert)
      idx--;

    else
      idx++;
  }
}

void ReferenceSpaceLagrange::faceSeq(vector<unsigned int>& vec,
                                     unsigned int  startIdx,
                                     unsigned int  startVal,
                                     unsigned int  stopVal,
                                     size_t*       refFace,
                                     const vector<unsigned int>& face,
                                     unsigned int  nNodePerEdge){
  // Index //
  unsigned int val = startVal;
  unsigned int idx = startIdx;

  // Populate //
  for(; val < stopVal; val++){
    vec[idx] = val;
    idx++;
  }
}

string ReferenceSpaceLagrange::toString(void) const{
  const size_t       nPerm      = pTree->getNPermutation();
  const unsigned int nNodeMinus = nNode - 1;
  stringstream       stream;

  stream << ReferenceSpace::toString();

  stream << "Lagrange Nodes Permutations:" << endl;

  for(unsigned int i = 0; i < nPerm; i++){
    stream << "  * RefSpace #" << i + 1 << ":" << endl
           << "      -- [";

    for(unsigned int j = 0; j < nNodeMinus; j++)
      stream << node->at(i)->at(j) << ", ";

    stream << node->at(i)->at(nNodeMinus) << "]" << endl;
  }

  return stream.str();
}
