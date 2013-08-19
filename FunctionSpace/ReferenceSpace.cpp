#include <algorithm>
#include <sstream>

#include "Exception.h"
#include "Numeric.h"
#include "ReferenceSpace.h"

using namespace std;

ReferenceSpace::ReferenceSpace(void){
  // Defining Ref Edge and Face in //
  // Derived Class                 //
}

ReferenceSpace::~ReferenceSpace(void){
  delete pTree;
}

void ReferenceSpace::init(void){
  // Tree //
  vector<size_t> vertexSeq(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    vertexSeq[i] = i;

  pTree = new PermutationTree(vertexSeq);

  // Cyclic Permutation //
  list<size_t>          listOfTrueReferenceSpace;
  list<vector<size_t> > listOfRefNodeIndexPermutation;
  list<vector<size_t> > listOfReverseNodeIndexPermutation;

  findCyclicPermutation(listOfTrueReferenceSpace,
                        listOfRefNodeIndexPermutation,
                        listOfReverseNodeIndexPermutation);

  // Iterators //
  list<size_t>::iterator refSpaceIt  = listOfTrueReferenceSpace.begin();

  // Reference Spaces Node Id //
  const size_t nRefSpace = listOfTrueReferenceSpace.size();
  refSpaceNodeId.resize(nRefSpace);

  for(size_t i = 0; i < nRefSpace; i++, refSpaceIt++){
    refSpaceNodeId[i].resize(nVertex);

    pTree->fillWithPermutation(*refSpaceIt, refSpaceNodeId[i]);
  }

  // ABC space to UVW space shape function index mapping //
  const size_t nPermutation = pTree->getNPermutation();
  ABCtoUVWIndex.resize(nPermutation);
  ABCtoUVWIndex.assign(listOfReverseNodeIndexPermutation.begin(),
                       listOfReverseNodeIndexPermutation.end());

  // UVW space to ABC space shape function index mapping //
  UVWtoABCIndex.resize(nPermutation);
  UVWtoABCIndex.assign(listOfRefNodeIndexPermutation.begin(),
                       listOfRefNodeIndexPermutation.end());

  // Ordered Edges & Faces Node Index//
  getOrderedEdge();
  getOrderedFace();
}

void ReferenceSpace::
findCyclicPermutation(list<size_t>&          listOfTrueReferenceSpace,
                      list<vector<size_t> >& listOfRefNodeIndexPermutation,
                      list<vector<size_t> >& listOfReverseNodeIndexPermutation){
  // Alloc Some Data //
  const size_t nPerm = pTree->getNPermutation();

  vector<size_t> pTest(nVertex);
  vector<size_t> pRef(nVertex);

  list<size_t>::iterator it;
  list<size_t>::iterator end;
  triplet match;

  // Values For unPermutedIndex //
  vector<size_t> unPermutedIndex(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    unPermutedIndex[i] = i;

  // Find Cyclic Permutation //
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

ReferenceSpace::triplet ReferenceSpace::
isCyclicPermutation(vector<size_t>& pTest,
                    vector<size_t>& pRef){

  // If no Face, we have no Cyclic Permutation
  if(!refFaceNodeIdx.size()){
    triplet tri = {
      false,
      vector<size_t>(0),
      vector<size_t>(0)
    };

    return tri;
  }

  // Node IDs of Reference Space first Face
  const size_t   nNodeInFaceZero = refFaceNodeIdx[0].size();
  vector<size_t> refNode(nNodeInFaceZero);

  for(size_t i = 0; i < nNodeInFaceZero; i++)
    refNode[i] = pRef[refFaceNodeIdx[0][i]];

  // Corresponding Face in Test Permutation
  size_t testFaceId = findCorrespondingFace(refNode, pTest);

  // If no corresponding face found, we have no Cyclic Permutation
  if(testFaceId == (size_t)(-1)){
    triplet tri = {
      false,
      vector<size_t>(0),
      vector<size_t>(0)
    };

    return tri;
  }

  // Node IDs of Test Permutation correspnding Face
  const size_t   nNodeInFaceTest = refFaceNodeIdx[testFaceId].size();
  vector<size_t> testNode(nNodeInFaceTest);

  for(size_t i = 0; i < nNodeInFaceTest; i++)
    testNode[i] = pTest[refFaceNodeIdx[testFaceId][i]];

  // Return Triplet
  triplet tri = {
    isFacePermutation(refNode, testNode),
    getRefIndexPermutation(pRef, pTest),
    getReverseIndexPermutation(pRef, pTest)
  };

  return tri;
}

size_t ReferenceSpace::findCorrespondingFace(vector<size_t>& face,
                                             vector<size_t>& node){
  // Init Stuff //
  const size_t nFace    = refFaceNodeIdx.size();
  const size_t faceSize = face.size();
  bool match = false;
  size_t f = 0;

  vector<size_t> testFace(faceSize);
  size_t         nNodeInFace;

  // Test All Face until match
  while(!match && f < nFace){
    nNodeInFace = refFaceNodeIdx[f].size();

    if(nNodeInFace == faceSize){
      // Get face f nodes
      for(size_t i = 0; i < faceSize; i++)
        testFace[i] = node[refFaceNodeIdx[f][i]];

      // Look if match
      match = haveSameNode(testFace, face);
    }

    if(!match)
      f++;
  }

  // If a valid face is found return it
  if(f < nFace)
    return f;

  // Else return (size_t)(-1)
  else
    return -1;
}

bool ReferenceSpace::isFacePermutation(vector<size_t>& refNode,
                                       vector<size_t>& testNode){
  // Check Size
  const size_t size = refNode.size();

  if(size != testNode.size())
    return false;

  // Find refNode[0] in testNode
  size_t offset = 0;

  while(refNode[0] != testNode[offset] && offset < size)
    offset++;

  // If refNode[0] not found in testNode, there is no face permutation
  if(offset == size)
    return false;

  // Check refNode[i] and testNode[(i + offset) % size]
  bool match = true;

  for(size_t i = 0; i < size && match; i++)
    match = (refNode[i] == testNode[(i + offset) % size]);

  return match;
}

vector<size_t> ReferenceSpace::getRefIndexPermutation(vector<size_t>& ref,
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

vector<size_t> ReferenceSpace::getReverseIndexPermutation(vector<size_t>& ref,
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

bool ReferenceSpace::haveSameNode(vector<size_t> face0,
                                  vector<size_t> face1){
  // Check Sizes
  const size_t size = face0.size();

  if(size != face1.size())
    return false;

  // Sort both vectors
  sort(face0.begin(), face0.end());
  sort(face1.begin(), face1.end());

  // Check if elements are the same and at same position
  bool match = true;

  for(size_t i = 0; i < size && match; i++)
    match = (face0[i] == face1[i]);

  return match;
}

void ReferenceSpace::getOrderedEdge(void){
  // Fill orderedEdgeNodeIdx[s][e]                         //
  // (for all reference space 's' and edge 'e') such that: //
  //                                                       //
  // refSpaceNodeId[s][orderedEdgeNodeIdx[s][e][0]] <      //
  // refSpaceNodeId[s][orderedEdgeNodeIdx[s][e][1]]        //

  // Alloc
  const size_t nEdge     = refEdgeNodeIdx.size();
  const size_t nRefSpace = refSpaceNodeId.size();

  orderedEdgeNodeIdx.resize(nRefSpace);

  // Populate Edge
  for(size_t s = 0; s < nRefSpace; s++){
    orderedEdgeNodeIdx[s].resize(nEdge);

    for(size_t e = 0; e < nEdge; e++){
      orderedEdgeNodeIdx[s][e].resize(2);

      orderRefEntityForGivenRefSpace(refEdgeNodeIdx[e],
                                     refSpaceNodeId[s],
                                     orderedEdgeNodeIdx[s][e]);
    }
  }
}

void ReferenceSpace::getOrderedFace(void){
  // Fill orderedEdgeNodeIdx[s][f]                                //
  // (for all reference space 's' and face 'f') such that:        //
  //                                                              //
  // refSpaceNodeId[s][orderedFaceNodeIdx[s][f][0]] <             //
  // refSpaceNodeId[s][orderedFaceNodeIdx[s][f][1]] <             //
  // refSpaceNodeId[s][orderedFaceNodeIdx[s][f][2]] <             //
  // (refSpaceNodeId[s][orderedFaceNodeIdx[s][f][3]]) (Quad Face) //
  //                                                              //
  // If we have a Quad face, a correction is needed such that:    //
  //                                                              //
  // orderedFaceNodeIdx[s][f][2]                                  //
  // is *opposite* to                                             //
  // orderedFaceNodeIdx[s][f][0]                                  //

  // Alloc
  const size_t nFace     = refFaceNodeIdx.size();
  const size_t nRefSpace = refSpaceNodeId.size();

  orderedFaceNodeIdx.resize(nRefSpace);

  // Populate Face
  for(size_t s = 0; s < nRefSpace; s++){
    orderedFaceNodeIdx[s].resize(nFace);

    for(size_t f = 0; f < nFace; f++){
      size_t nNodeInFace = refFaceNodeIdx[f].size();

      orderedFaceNodeIdx[s][f].resize(nNodeInFace);

      orderRefEntityForGivenRefSpace(refFaceNodeIdx[f],
                                     refSpaceNodeId[s],
                                     orderedFaceNodeIdx[s][f]);
      if(nNodeInFace == 4)
        correctQuadFaceNodeIdx(orderedFaceNodeIdx[s][f]);
    }
  }
}

void ReferenceSpace::
orderRefEntityForGivenRefSpace(vector<size_t>& refEntityNodeIdx,
                               vector<size_t>& refSpaceNodeId,
                               vector<size_t>& orderedEntityNodeIdx){
  // Get Size
  const size_t size = orderedEntityNodeIdx.size();

  // Ref Entity Node *ID*
  vector<pair<size_t, size_t> > refEntityNodeId(size);

  for(size_t i = 0; i < size; i++){
    refEntityNodeId[i].first  = i;                             // Node Id INDEX
    refEntityNodeId[i].second = refSpaceNodeId[refEntityNodeIdx[i]]; // Node Id
  }

  // Sort it with repsect to second entry (Node ID)
  std::sort(refEntityNodeId.begin(), refEntityNodeId.end(), sortPredicate);

  // Populate orderedEntityNodeIdx (Usign sorted Node ID old Index)
  for(size_t i = 0; i < size; i++)
    orderedEntityNodeIdx[i] = refEntityNodeIdx[refEntityNodeId[i].first];
}

void ReferenceSpace::
correctQuadFaceNodeIdx(vector<size_t>& correctedQuadFaceNodeIdx){

  // Get :                       //
  // correctedQuadFaceNodeIdx[2] //
  // is *opposite* to            //
  // correctedQuadFaceNodeIdx[0] //

  size_t opposite = (correctedQuadFaceNodeIdx[0] + 2) % 4;

  if(correctedQuadFaceNodeIdx[2] != opposite){
    // Find opposite node index
    size_t tmp;
    size_t idx = 1;

    while(correctedQuadFaceNodeIdx[idx] != opposite)
      idx++;

    // Swap correctedQuadFaceNodeIdx[2] and correctedQuadFaceNodeIdx[idx]
    tmp = correctedQuadFaceNodeIdx[2];
    correctedQuadFaceNodeIdx[2]   = opposite;
    correctedQuadFaceNodeIdx[idx] = tmp;
  }
}

size_t ReferenceSpace::getPermutationIdx(const MElement& element) const{
  // Get Primary Vertices Global ID //
  vector<pair<size_t, size_t> > vertexGlobalId(nVertex);

  for(size_t i = 0; i < nVertex; i++){
    vertexGlobalId[i].first  = i;
    vertexGlobalId[i].second = element.getVertex(i)->getNum();
  }

  // Sort Them with repsect to Vertex Global ID //
  //                 (vertex[i].second->getNum) //
  std::sort(vertexGlobalId.begin(), vertexGlobalId.end(), sortPredicate);

  // Reduce Vertex Global ID //
  vector<size_t> vertexReducedId(nVertex);

  for(size_t i = 0; i < nVertex; i++)
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

void ReferenceSpace::mapFromABCtoUVW(const MElement& element,
                                     double a, double b, double c,
                                     double uvw[3]) const{
 // Get Index Permutation
  const size_t permutationIdx = getPermutationIdx(element);

  // UVW node coordinate
  double** uvwNode = new double*[nVertex];

  for(size_t i = 0; i < nVertex; i++)
    uvwNode[i] = new double[3];

  for(size_t i = 0; i < nVertex; i++)
    element.getNode(i,
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][0],
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][1],
                    uvwNode[UVWtoABCIndex[permutationIdx][0]][2]);

  // ABC (order 1) grad shape functions
  double* phiABC = new double[nVertex];
  element.getShapeFunctions(a, b, c, phiABC, 1);

  // Map From UVW to UVW //
  uvw[0] = 0;
  for(size_t i = 0; i < nVertex; i++)
    uvw[0] += uvwNode[i][0] * phiABC[i];

  uvw[1] = 0;
  for(size_t i = 0; i < nVertex; i++)
    uvw[1] += uvwNode[i][1] * phiABC[i];

  uvw[2] = 0;
  for(size_t i = 0; i < nVertex; i++)
    uvw[2] += uvwNode[i][2] * phiABC[i];

  // Free //
  delete[] phiABC;

  for(size_t i = 0; i < nVertex; i++)
    delete[] uvwNode[i];

  delete[] uvwNode;
}

void ReferenceSpace::mapFromABCtoXYZ(const MElement& element,
                                     double a, double b, double c,
                                     double xyz[3]) const{
  // Map From ABC to UVW
  double uvw[3];
  mapFromABCtoUVW(element, a, b, c, uvw);

  // Map From UVW to XYZ
  SPoint3 pxyz;
  element.pnt(uvw[0], uvw[1], uvw[2], pxyz);

  xyz[0] = pxyz.x();
  xyz[1] = pxyz.y();
  xyz[2] = pxyz.z();
}

void ReferenceSpace::mapFromUVWtoABC(const MElement& element,
                                     double u, double v, double w,
                                     double abc[3]) const{
   // ABC node coordinate
  double** abcNode = new double*[nVertex];

  for(size_t i = 0; i < nVertex; i++)
    abcNode[i] = new double[3];

  for(size_t i = 0; i < nVertex; i++)
    element.getNode(i, abcNode[i][0], abcNode[i][1], abcNode[i][2]);

  // UVW (order 1) shape functions
  double* phiUVW = new double[nVertex];
  element.getShapeFunctions(u, v, w, phiUVW, 1);

  // Element Permutation Index
  const size_t permutationIdx = getPermutationIdx(element);

  // Map From UVW to ABC
  abc[0] = 0;
  for(size_t i = 0; i < nVertex; i++)
    abc[0] += abcNode[i][0] * phiUVW[ABCtoUVWIndex[permutationIdx][i]];

  abc[1] = 0;
  for(size_t i = 0; i < nVertex; i++)
    abc[1] += abcNode[i][1] * phiUVW[ABCtoUVWIndex[permutationIdx][i]];

  abc[2] = 0;
  for(size_t i = 0; i < nVertex; i++)
    abc[2] += abcNode[i][2] * phiUVW[ABCtoUVWIndex[permutationIdx][i]];

  // Free
  delete[] phiUVW;

  for(size_t i = 0; i < nVertex; i++)
    delete[] abcNode[i];

  delete[] abcNode;
}

void ReferenceSpace::mapFromXYZtoABC(const MElement& element,
                                     double x, double y, double z,
                                     double abc[3]) const{
  // Get UVW coordinate //
  double xyz[3] = {x, y, z};
  double uvw[3];

  element.xyz2uvw(xyz, uvw);

  // Get ABC coordinate //
  mapFromUVWtoABC(element, uvw[0], uvw[1], uvw[2], abc);
}

double ReferenceSpace::getJacobian(const MElement& element,
                                   double a, double b, double c,
                                   fullMatrix<double>& jac) const{
  // ABC to UVW Jacobian //
  // Get Index Permutation
  const size_t permutationIdx = getPermutationIdx(element);

  // UVW node coordinate
  double** uvwNode = new double*[nVertex];

  for(size_t i = 0; i < nVertex; i++)
    uvwNode[i] = new double[3];

  for(size_t i = 0; i < nVertex; i++)
    element.getNode(i,
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][0],
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][1],
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][2]);

  // ABC (order 1) grad shape functions
  double phiABC[1256][3]; // Cannot be dynamicaly allocated since
                          // GMSH wants a double[][3] for phiABC !!!

  element.getGradShapeFunctions(a, b, c, phiABC, 1);

  // Jacobian
  fullMatrix<double> jacABCtoUVW(3, 3);
  jacABCtoUVW.setAll(0);

  for(size_t i = 0; i < nVertex; i++){
    jacABCtoUVW(0, 0) += uvwNode[i][0] * phiABC[i][0];
    jacABCtoUVW(0, 1) += uvwNode[i][1] * phiABC[i][0];
    jacABCtoUVW(0, 2) += uvwNode[i][2] * phiABC[i][0];
  }

  for(size_t i = 0; i < nVertex; i++){
    jacABCtoUVW(1, 0) += uvwNode[i][0] * phiABC[i][1];
    jacABCtoUVW(1, 1) += uvwNode[i][1] * phiABC[i][1];
    jacABCtoUVW(1, 2) += uvwNode[i][2] * phiABC[i][1];
  }

  for(size_t i = 0; i < nVertex; i++){
    jacABCtoUVW(2, 0) += uvwNode[i][0] * phiABC[i][2];
    jacABCtoUVW(2, 1) += uvwNode[i][1] * phiABC[i][2];
    jacABCtoUVW(2, 2) += uvwNode[i][2] * phiABC[i][2];
  }

  // Regularize Jacobian
  regularize(element.getDim(), jacABCtoUVW);

  // Free
  for(size_t i = 0; i < nVertex; i++)
    delete[] uvwNode[i];

  delete[] uvwNode;

  // Map ABC coordinate to UVW point //
  double uvw[3];
  mapFromABCtoUVW(element, a, b, c, uvw);

  // UVW to XYZ Jacobian + Determinant                      //
  //  NB: Volume is not modified when we go from ABC to UVW //
  //       --> Determinant unchanged                        //
  fullMatrix<double> jacUVWtoXYZ(3, 3);
  double det = element.getJacobian(uvw[0], uvw[1], uvw[2], jacUVWtoXYZ);

  // Product of the two Jacobians & Return //
  jac.gemm(jacABCtoUVW, jacUVWtoXYZ, 1, 0);
  return det;
}

void ReferenceSpace::regularize(size_t dim, fullMatrix<double>& jac){
  double a[3];
  double b[3];
  double c[3];

  switch(dim){
  case 0:
    jac(0, 0) = jac(1, 1) = jac(2, 2) = 1.0;
    jac(0, 1) = jac(1, 0) = jac(2, 0) = 0.0;
    jac(0, 2) = jac(1, 2) = jac(2, 1) = 0.0;
    break;

  case 1:
    a[0] = jac(0, 0);
    a[1] = jac(0, 1);
    a[2] = jac(0, 2);

   if((fabs(a[0]) >= fabs(a[1]) && fabs(a[0]) >= fabs(a[2])) ||
       (fabs(a[1]) >= fabs(a[0]) && fabs(a[1]) >= fabs(a[2]))){
      b[0] =  a[1];
      b[1] = -a[0];
      b[2] =  0.;
    }

    else{
      b[0] =  0.;
      b[1] =  a[2];
      b[2] = -a[1];
    }

    norme(b);
    prodve(a, b, c);
    norme(c);

    jac(1, 0) = b[0]; jac(1, 1) = b[1]; jac(1, 2) = b[2];
    jac(2, 0) = c[0]; jac(2, 1) = c[1]; jac(2, 2) = c[2];
    break;

  case 2:
    a[0] = jac(0, 0);
    a[1] = jac(0, 1);
    a[2] = jac(0, 2);

    b[0] = jac(1, 0);
    b[1] = jac(1, 1);
    b[2] = jac(1, 2);

    prodve(a, b, c);
    norme(c);

    jac(2, 0) = c[0]; jac(2, 1) = c[1]; jac(2, 2) = c[2];
    break;

  case 3:
    break;
  }
}

string ReferenceSpace::toString(void) const{
  const size_t nRefSpace = refSpaceNodeId.size();
  const size_t nEdge     = refEdgeNodeIdx.size();
  const size_t nFace     = refFaceNodeIdx.size();
  stringstream stream;

  // Permutation Tree //
  stream << "Permutation Tree:" << endl
         << pTree->toString()   << endl;

  // Reference Space //
  stream << "Reference Space Node IDs:" << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "  ** Reference Space #" << s + 1 << ": [";

    for(size_t v = 0; v < nVertex - 1; v++)
      stream << refSpaceNodeId[s][v] << ", ";

    stream << refSpaceNodeId[s][nVertex - 1] << "]" << endl;
  }

  stream << endl << "Ordered Edge Node Index:" << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "  ** Reference Space #" << s + 1 << ":"
           << endl;

    for(size_t e = 0; e < nEdge; e++)
      stream << "      -- ["
             << orderedEdgeNodeIdx[s][e][0] << ", "
             << orderedEdgeNodeIdx[s][e][1] << "]"
             << endl;
  }

  stream << endl << "Ordered Face Node Index:" << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "  ** Reference Space #" << s + 1 << ":"
           << endl;

    for(size_t f = 0; f < nFace; f++){
      const size_t nNodeInFace = orderedFaceNodeIdx[s][f].size();
      stream << "      -- [";

      for(size_t n = 0; n < nNodeInFace - 1; n++)
        stream << orderedFaceNodeIdx[s][f][n] << ", ";

      stream << orderedFaceNodeIdx[s][f][nNodeInFace - 1] << "]"
             << endl;
    }
  }

  stream << endl;

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
