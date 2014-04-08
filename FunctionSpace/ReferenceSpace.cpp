#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <set>

#include "Exception.h"
#include "Numeric.h"
#include "ReferenceSpace.h"

using namespace std;

ReferenceSpace::ReferenceSpace(void){
  // Defining Ref Edge and Face in //
  // Derived Class                 //
}

ReferenceSpace::ReferenceSpace(const std::string& path){
  init(path);
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

  // Connectivity //
  list<size_t>          listOfTrueReferenceSpace;
  list<vector<size_t> > listOfRefNodeIndexPermutation;
  list<vector<size_t> > listOfReverseNodeIndexPermutation;

  findConnectivity(listOfTrueReferenceSpace,
                   listOfRefNodeIndexPermutation,
                   listOfReverseNodeIndexPermutation);

  // Iterators //
  list<size_t>::iterator refSpaceIt = listOfTrueReferenceSpace.begin();

  // Reference Spaces Node Id //
  const size_t nRefSpace = listOfTrueReferenceSpace.size();
  refSpaceNodeId.resize(nRefSpace);

  for(size_t i = 0; i < nRefSpace; i++, refSpaceIt++){
    refSpaceNodeId[i].resize(nVertex);

    pTree->fillWithPermutation(*refSpaceIt, refSpaceNodeId[i]);
  }

  // Compress Tag, so that they refer to refSpaceNodeId indices
  // insted of leafId of pTree.
  pTree->compressTag();

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

void ReferenceSpace::init(const char* stream){
  // nVector
  size_t offset = 0;

  memcpy(&nVertex, stream + offset, sizeof(size_t));
  offset += sizeof(size_t);

  // Fef {Edge, Face} Node Idx
  offset += unserialize(stream + offset, refEdgeNodeIdx);
  offset += unserialize(stream + offset, refFaceNodeIdx);

  // Permutation Tree
  size_t tSize; // Tree Size

  memcpy(&tSize, stream + offset, sizeof(size_t));
  offset += sizeof(size_t);

  pTree = new PermutationTree(stream + offset);
  offset += tSize;

  // RefSpace Node Id
  offset += unserialize(stream + offset, refSpaceNodeId);

  // Index mapping
  offset += unserialize(stream + offset, ABCtoUVWIndex);
  offset += unserialize(stream + offset, UVWtoABCIndex);

  // Oredered {Edge, Face} Node Idx
  offset += unserialize(stream + offset, orderedEdgeNodeIdx);
  offset += unserialize(stream + offset, orderedFaceNodeIdx);
}

void ReferenceSpace::init(const std::string& path){
  // Read file //
  // Open Stream
  ifstream input;
  input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  input.open(path.c_str(), std::ifstream::binary);

  // Get size of stream (go to stream end)
  input.seekg(0, std::ifstream::end);
  const size_t size = input.tellg();

  // Reset stream possition
  input.seekg(0, std::ifstream::beg);

  // Alloc byte stream & Read file
  char* stream = new char[size];
  input.read(stream, size);

  // Init from stream
  init(stream);

  // Free stream
  delete[] stream;
}

void ReferenceSpace::
findConnectivity(list<size_t>&          listOfTrueReferenceSpace,
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

  // Find Connectivity //
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

      // Look if it matches (do pTest and pRef have the same connectivity ?)
      match = isSameConnectivity(pTest, pRef);

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

    // If a ReferenceSpace is found, add the index permutations
    else{
      listOfRefNodeIndexPermutation.push_back(match.second);
      listOfReverseNodeIndexPermutation.push_back(match.third);

      pTree->addTagToPermutation(i, *it);
    }
  }
}

ReferenceSpace::triplet ReferenceSpace::
isSameConnectivity(const vector<size_t>& pTest,
                   const vector<size_t>& pRef) const{

  // Triplet to return
  triplet tri;

  // Test if we have the same connectivity (i.e. the same edges)
  bool haveSameEdge = isSameEdge(pTest, pRef);

  if(haveSameEdge){
    tri.first  = true;
    tri.second = getRefIndexPermutation(pRef, pTest);
    tri.third  = getReverseIndexPermutation(pRef, pTest);
  }

  else{
    tri.first  = false;
    tri.second = vector<size_t>(0);
    tri.third  = vector<size_t>(0);
  }

  return tri;
}

bool ReferenceSpace::isSameEdge(const std::vector<size_t>& pTest,
                                const std::vector<size_t>& pRef) const{
  // Set of Reference Edges
  const size_t nEdge = refEdgeNodeIdx.size();
  std::set<std::vector<size_t>, EdgeComparator> refEdge;
  std::vector<size_t> tmp(2);

  for(size_t e = 0; e < nEdge; e++){
    tmp[0] = pRef[refEdgeNodeIdx[e][0]];
    tmp[1] = pRef[refEdgeNodeIdx[e][1]];
    refEdge.insert(tmp);
  }

  // Compare Test Edges
  bool match = true;
  for(size_t e = 0; e < nEdge && match; e++){
    tmp[0] = pTest[refEdgeNodeIdx[e][0]];
    tmp[1] = pTest[refEdgeNodeIdx[e][1]];

    match = (refEdge.find(tmp) != refEdge.end());
  }

  return match;
}

bool ReferenceSpace::EdgeComparator::operator()(const std::vector<size_t>& a,
                                                const std::vector<size_t>& b){
  size_t maxA, minA;
  size_t maxB, minB;

  if(a[0] < a[1]){
    maxA = a[1];
    minA = a[0];
  }

  else{
    maxA = a[0];
    minA = a[1];
  }

  if(b[0] < b[1]){
    maxB = b[1];
    minB = b[0];
  }

  else{
    maxB = b[0];
    minB = b[1];
  }

  return
    ((minA != minB) && (minA < minB)) ||
    ((minA == minB) && (maxA < maxB));
}

vector<size_t>
ReferenceSpace::getRefIndexPermutation(const vector<size_t>& ref,
                                       const vector<size_t>& test) const{
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

vector<size_t>
ReferenceSpace::getReverseIndexPermutation(const vector<size_t>& ref,
                                           const vector<size_t>& test) const{
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
        correctQuadFaceNodeIdx(f, orderedFaceNodeIdx[s][f]);
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
correctQuadFaceNodeIdx(size_t faceId,
                       vector<size_t>& correctedQuadFaceNodeIdx){
  // Get :                       //
  // correctedQuadFaceNodeIdx[2] //
  // is *opposite* to            //
  // correctedQuadFaceNodeIdx[0] //

  // Get opposite Node //
  // Find node correctedQuadFaceNodeIdx[0] in refFaceNodeId[faceId]
  size_t refIdx = 0;

  while((refIdx < 4)
        &&
        (refFaceNodeIdx[faceId][refIdx] != correctedQuadFaceNodeIdx[0])){

    refIdx++;
  }

  if(refIdx == 4)
    throw Exception("Error in correctQuadFaceNodeIdx: vertex 0 not found");

  // Get opposite Node
  size_t opposite = refFaceNodeIdx[faceId][(refIdx + 2) % 4];

  // If correction needed, do it //
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

  // UVW node coordinate in ABC
  double** uvwNode = new double*[nVertex];

  for(size_t i = 0; i < nVertex; i++)
    uvwNode[i] = new double[3];

  for(size_t i = 0; i < nVertex; i++)
    element.getNode(i,
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][0],
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][1],
                    uvwNode[UVWtoABCIndex[permutationIdx][i]][2]);

  // ABC (order 1) grad shape functions
  double* phiABC = new double[nVertex];
  element.getShapeFunctions(a, b, c, phiABC, 1);

  // Map From ABC to UVW //
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
  // Element Permutation Index
  const size_t permutationIdx = getPermutationIdx(element);

  // ABC node coordinate in UVW
  double** abcNode = new double*[nVertex];

  for(size_t i = 0; i < nVertex; i++)
    abcNode[i] = new double[3];

  for(size_t i = 0; i < nVertex; i++)
    element.getNode(i,
                    abcNode[ABCtoUVWIndex[permutationIdx][i]][0],
                    abcNode[ABCtoUVWIndex[permutationIdx][i]][1],
                    abcNode[ABCtoUVWIndex[permutationIdx][i]][2]);

  // UVW (order 1) shape functions
  double* phiUVW = new double[nVertex];
  element.getShapeFunctions(u, v, w, phiUVW, 1);

  // Map From UVW to ABC
  abc[0] = 0;
  for(size_t i = 0; i < nVertex; i++)
    abc[0] += abcNode[i][0] * phiUVW[i];

  abc[1] = 0;
  for(size_t i = 0; i < nVertex; i++)
    abc[1] += abcNode[i][1] * phiUVW[i];

  abc[2] = 0;
  for(size_t i = 0; i < nVertex; i++)
    abc[2] += abcNode[i][2] * phiUVW[i];

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

  // UVW to XYZ Jacobian //
  fullMatrix<double> jacUVWtoXYZ(3, 3);
  element.getJacobian(uvw[0], uvw[1], uvw[2], jacUVWtoXYZ);

  // Product of the two Jacobians & Return //
  // Do a naive gemm, so that we do not encounter nested threads
  // (limitation of OpenBLAS)
  jac.gemm_naive(jacABCtoUVW, jacUVWtoXYZ, 1, 0);

  // New Jacobian determinant (same as jacUVWtoXYZ with maybe a SIGN CHANGE) //
  //   ---> Has to be recomputed!
  return
   jac(0, 0) * jac(1, 1) * jac(2, 2) +
   jac(0, 1) * jac(1, 2) * jac(2, 0) +
   jac(0, 2) * jac(1, 0) * jac(2, 1) -

   jac(0, 2) * jac(1, 1) * jac(2, 0) -
   jac(0, 1) * jac(1, 0) * jac(2, 2) -
   jac(0, 0) * jac(1, 2) * jac(2, 1);
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

  // Reference Space Node IDs //
  stream << "Reference Space Node IDs:" << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "  ** Reference Space #" << s << ": [";

    for(size_t v = 0; v < nVertex - 1; v++)
      stream << refSpaceNodeId[s][v] << ", ";

    stream << refSpaceNodeId[s][nVertex - 1] << "]" << endl;
  }

  // Oriented Edges Node Index //
  stream << endl << "Ordered Edge Node Index:" << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "  ** Reference Space #" << s << ":"
           << endl;

    for(size_t e = 0; e < nEdge; e++)
      stream << "      -- ["
             << orderedEdgeNodeIdx[s][e][0] << ", "
             << orderedEdgeNodeIdx[s][e][1] << "]"
             << endl;
  }

  // Oriented Faces Node Index //
  stream << endl << "Ordered Face Node Index:" << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "  ** Reference Space #" << s << ":"
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

std::pair<size_t, char*> ReferenceSpace::serialize(void) const{
  // Serialize //
  // refEdgeNodeIdx
  pair<size_t, char*> sRefEdgeIdx = serialize(refEdgeNodeIdx);

  // refFaceNodeIdx
  pair<size_t, char*> sRefFaceIdx = serialize(refFaceNodeIdx);

  // PermutationTree
  pair<size_t, char*> sPTree = pTree->serialize();

  // Reference Space
  pair<size_t, char*> sRSpace = serialize(refSpaceNodeId);

  // ABCtoUVW
  pair<size_t, char*> sABCtoUVW = serialize(ABCtoUVWIndex);

  // UVWtoUVW
  pair<size_t, char*> sUVWtoABC = serialize(UVWtoABCIndex);

  // orderedEdgeNodeIdx
  pair<size_t, char*> sEdgeIdx = serialize(orderedEdgeNodeIdx);

  // orderedEdgeNodeIdx
  pair<size_t, char*> sFaceIdx = serialize(orderedFaceNodeIdx);

  // Full Serialized Stream //
  // Alloc (+ 1 * sizeof(size_t) for nVertex)
  const size_t size = sizeof(size_t) + sRefEdgeIdx.first
                                     + sRefFaceIdx.first
                                     + sizeof(size_t) // pTree Size
                                     + sPTree.first   // pTree
                                     + sRSpace.first
                                     + sABCtoUVW.first
                                     + sUVWtoABC.first
                                     + sEdgeIdx.first
                                     + sFaceIdx.first;
  char* stream = new char[size];

  // Populate
  size_t offset = 0;

  memcpy(stream + offset, &nVertex, sizeof(size_t));
  offset += sizeof(size_t);

  memcpy(stream + offset, sRefEdgeIdx.second, sRefEdgeIdx.first);
  offset += sRefEdgeIdx.first;

  memcpy(stream + offset, sRefFaceIdx.second, sRefFaceIdx.first);
  offset += sRefFaceIdx.first;

  memcpy(stream + offset, &sPTree.first, sizeof(size_t)); // pTree size
  offset += sizeof(size_t);

  memcpy(stream + offset, sPTree.second, sPTree.first);   // pTree
  offset += sPTree.first;

  memcpy(stream + offset, sRSpace.second, sRSpace.first);
  offset += sRSpace.first;

  memcpy(stream + offset, sABCtoUVW.second, sABCtoUVW.first);
  offset += sABCtoUVW.first;

  memcpy(stream + offset, sUVWtoABC.second, sABCtoUVW.first);
  offset += sABCtoUVW.first;

  memcpy(stream + offset, sEdgeIdx.second, sEdgeIdx.first);
  offset += sEdgeIdx.first;

  memcpy(stream + offset, sFaceIdx.second, sFaceIdx.first);
  offset += sFaceIdx.first;

  // Free Temp
  delete[] sRefEdgeIdx.second;
  delete[] sRefFaceIdx.second;
  delete[] sPTree.second;
  delete[] sRSpace.second;
  delete[] sABCtoUVW.second;
  delete[] sUVWtoABC.second;
  delete[] sEdgeIdx.second;
  delete[] sFaceIdx.second;

  // Return
  return pair<size_t, char*>(size, stream);
}

void ReferenceSpace::serialize(const std::string& path) const{
  // Serialize into byte Stream
  std::pair<size_t, char*> stream  = serialize();

  // Write byte stream
  ofstream output;
  output.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  output.open(path.c_str(), std::ofstream::binary);
  output.write(stream.second, stream.first);
  output.close();

  // Free
  delete[] stream.second;
}

std::pair<size_t, char*> ReferenceSpace::
serialize(const std::vector<std::vector<size_t> >& source){
  // Vector & Stream size //
  size_t nVector   = source.size();
  size_t totalSize = sizeof(size_t); // Init to header size (nVector)

  for(size_t i = 0; i < nVector; i++)
    totalSize += (source[i].size() + 1) * sizeof(size_t);
                                // + 1 for subvector size header

  // Alloc Stream //
  char* stream = new char[totalSize];

  // Header (nVector) //
  memcpy(stream, &nVector, sizeof(size_t));

  // SubVectors //
  size_t tmpSize;
  size_t offset = sizeof(size_t);

  for(size_t i = 0; i < nVector; i++){
    // SubVector size
    tmpSize = source[i].size();
    memcpy(stream + offset, &tmpSize, sizeof(size_t));
    offset += sizeof(size_t);

    // SubVector stored values
    for(size_t j = 0; j < tmpSize; j++){
      memcpy(stream + offset, &source[i][j], sizeof(size_t));
      offset += sizeof(size_t);
    }
  }

  // Return //
  return pair<size_t, char*>(totalSize, stream);
}

std::pair<size_t, char*> ReferenceSpace::
serialize(const std::vector<std::vector<std::vector<size_t> > >& source){
  // Vector & Stream size //
  size_t nVector   = source.size();
  size_t totalSize = sizeof(size_t); // Init to header size (nVector)

  for(size_t i = 0; i < nVector; i++){
    totalSize += sizeof(size_t); // Subvector size header

    for(size_t j = 0; j < source[i].size(); j++)
      totalSize += (source[i][j].size() + 1) * sizeof(size_t);
                                     // + 1 for subsubvector size header
  }

  // Alloc Stream //
  char* stream = new char[totalSize];

  // Header (nVector) //
  memcpy(stream, &nVector, sizeof(size_t));

  // SubVectors //
  size_t tmpSize;
  size_t tmpSubSize;
  size_t offset = sizeof(size_t);

  for(size_t i = 0; i < nVector; i++){
    // SubVector size
    tmpSize = source[i].size();
    memcpy(stream + offset, &tmpSize, sizeof(size_t));
    offset += sizeof(size_t);

    for(size_t j = 0; j < tmpSize; j++){
      // SubSubVector size
      tmpSubSize = source[i][j].size();
      memcpy(stream + offset, &tmpSubSize, sizeof(size_t));
      offset += sizeof(size_t);

      // SubSubVector stored values
      for(size_t k = 0; k < tmpSubSize; k++){
        memcpy(stream + offset, &source[i][j][k], sizeof(size_t));
        offset += sizeof(size_t);
      }
    }
  }

  // Return //
  return pair<size_t, char*>(totalSize, stream);
}

size_t ReferenceSpace::
unserialize(const char* stream,
            std::vector<std::vector<size_t> >& dest){
  // Vector size //
  size_t nVector;
  size_t offset = 0;

  memcpy(&nVector, stream + offset, sizeof(size_t));
  offset += sizeof(size_t);

  // Alloc Vector //
  dest.resize(nVector);

  // Populate //
  size_t tmpSize;
  size_t tmpVal;

  for(size_t i = 0; i < nVector; i++){
    // Subvector size
    memcpy(&tmpSize, stream + offset, sizeof(size_t));
    offset += sizeof(size_t);

    // Alloc Subvector
    dest[i].resize(tmpSize);

    // Populate Subvector
    for(size_t j = 0; j < tmpSize; j++){
      memcpy(&tmpVal, stream + offset, sizeof(size_t));
      offset += sizeof(size_t);

      dest[i][j] = tmpVal;
    }
  }

  // Return size //
  return offset;
}

size_t ReferenceSpace::
    unserialize(const char* stream,
                std::vector<std::vector<std::vector<size_t> > >& dest){
  // Vector size //
  size_t nVector;
  size_t offset = 0;

  memcpy(&nVector, stream + offset, sizeof(size_t));
  offset += sizeof(size_t);

  // Alloc Vector //
  dest.resize(nVector);

  // Populate //
  size_t tmpSize;
  size_t tmpSubSize;
  size_t tmpVal;

  for(size_t i = 0; i < nVector; i++){
    // Subvector size
    memcpy(&tmpSize, stream + offset, sizeof(size_t));
    offset += sizeof(size_t);

    // Alloc Subvector
    dest[i].resize(tmpSize);

    // Populate Subvector
    for(size_t j = 0; j < tmpSize; j++){
      // Subsubvector size
      memcpy(&tmpSubSize, stream + offset, sizeof(size_t));
      offset += sizeof(size_t);

      // Alloc Subsubvector
      dest[i][j].resize(tmpSubSize);

      // Populate Subsubvector
      for(size_t k = 0; k < tmpSubSize; k++){
        memcpy(&tmpVal, stream + offset,sizeof(size_t));
        offset += sizeof(size_t);

        dest[i][j][k] = tmpVal; // AT LAST !! (-:
      }
    }
  }

  // Return size //
  return offset;
}
