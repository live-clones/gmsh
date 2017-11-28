// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_H_
#define _MESH_PARTITION_H_

#include <vector>
#include <unordered_map>

#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"

#include "GFaceCompound.h"
#include "GFace.h"

#include "MFaceHash.h"
#include "MEdgeHash.h"

class GModel;
class GFace;
class Graph;

int PartitionMesh(GModel *const model);

int UnpartitionMesh(GModel *const model);
template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionRegion *region, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionFace *face, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionEdge *edge, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionVertex *vertex, ITERATOR it_beg, ITERATOR it_end);

int CreatePartitionTopology(GModel *const model);

int MakeGraph(GModel *const model, Graph &graph);
template <class ITERATOR>
void fillElementsToNodesMap(Graph &graph, const GEntity *const entity, int &eptrIndex, int &eindIndex, int &numVertex, ITERATOR it_beg, ITERATOR it_end);
int getSizeOfEind(const GModel *const model);
bool isPeriodic(const GModel *const model);

int PartitionGraph(Graph &graph);
void createDualGraph(Graph &graph);

void CreateNewEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GRegion *> &newRegions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GFace *> &newFaces, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GEdge *> &newEdges, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GVertex *> &newVertices, ITERATOR it_beg, ITERATOR it_end);
void addPhysical(GModel *const model, GEntity *const entity, const unsigned int partition);

void CreatePartitionBoundaries(GModel *const model);
MElement* getReferenceElement(const std::vector< std::pair<MElement*, std::vector<unsigned int> > > &elementPairs, std::vector<unsigned int> &referencePartitions);
void getPartitionInVector(std::vector<unsigned int> &partitions, const std::vector< std::pair<MElement*, std::vector<unsigned int> > > &boundaryPair);
template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Face, Equal_Face> &faceToElement, std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > > , Hash_Edge, Equal_Edge> &edgeToElement, std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > > &vertexToElement, std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end);
void assignPartitionBoundary(GModel *const model, MFace &me, MElement* reference, std::vector<unsigned int> partitions, std::set<partitionFace*, Less_partitionFace> &pfaces);
void assignPartitionBoundary(GModel *const model, MEdge &me, MElement* reference, std::vector<unsigned int> partitions, std::set<partitionEdge*, Less_partitionEdge> &pedges);
void assignPartitionBoundary(GModel *const model, MVertex *ve, MElement* reference, std::vector<unsigned int> partitions, std::set<partitionVertex*, Less_partitionVertex> &pvertices);

void AssignMeshVertices(GModel *model, int dim = 4, bool inAllDim = false);
template <class ITERATOR>
void setVerticesToEntity(GEntity *const entity, ITERATOR it_beg, ITERATOR it_end, bool inAllDim);

void DivideNonConnectedEntities(GModel *model);
template <class ITERATOR>
void fillVertexToElement(std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, ITERATOR it_beg, ITERATOR it_end);
void fillConnectedElements(std::set<MElement*> &connectedElements, std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, MElement *element);
template <class ITERATOR>
void fillEdgeToElement(std::unordered_map<MEdge, std::vector<MElement*>, Hash_Edge, Equal_Edge> &edgeToElement, ITERATOR it_beg, ITERATOR it_end);
void fillConnectedElements(std::set<MElement*> &connectedElements, std::unordered_map<MEdge, std::vector<MElement*>, Hash_Edge, Equal_Edge> &edgeToElement, MElement *element);
template <class ITERATOR>
void fillFaceToElement(std::unordered_map<MFace, std::vector<MElement*>, Hash_Face, Equal_Face> &faceToElement, ITERATOR it_beg, ITERATOR it_end);
void fillConnectedElements(std::set<MElement*> &connectedElements, std::unordered_map<MFace, std::vector<MElement*>, Hash_Face, Equal_Face> &faceToElement, MElement *element);
void fillBoundaryFace(GModel *const model, std::vector<GFace*> &boundaryFace, partitionRegion* entity);
void fillBoundaryEdge(GModel *const model, std::vector<GEdge*> &boundaryEdge, partitionFace* entity);
void fillBoundaryVertex(GModel *const model, std::vector<GVertex*> &boundaryVertex, partitionEdge* entity);
template <class ITERATOR>
void fillElements(std::vector<MElement*> &elements, GEntity* entity, ITERATOR it_beg, ITERATOR it_end);

int CreateTopologyFile(GModel* model, std::string name);
int getTag(GModel* model, GEntity* entity);
std::string getSubstr(GModel* model, GEntity* entity);
std::vector<unsigned int> getPartition(GModel* model, GEntity* entity);


int PartitionMeshFace(std::list<GFace*> &cFaces);
int PartitionMeshElements(std::vector<MElement*> &elements);

void splitBoundaryEdges(GModel *model,
                        std::set<partitionEdge*, Less_partitionEdge> &newEdges);
void createPartitionFaces(GModel *model, std::vector<MElement *> &elements, int num_parts, std::vector<discreteFace*> &pFaces);

#endif
