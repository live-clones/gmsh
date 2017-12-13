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
int getSizeOfEind(const GEntity *const entity);
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
void fillConnectedElements(std::vector< std::set<MElement*> > &connectedElements, Graph &graph);

void CreatePartitionBoundaries(GModel *const model, const std::vector< std::set<MElement*> > &boundaryElements);
void fillElementToEntity(GModel *const model, std::map<MElement*, GEntity*> &elmToEntity);
MElement* getReferenceElement(const std::vector< std::pair<MElement*, std::vector<unsigned int> > > &elementPairs);
void getPartitionInVector(std::vector<unsigned int> &partitions, const std::vector< std::pair<MElement*, std::vector<unsigned int> > > &boundaryPair);
template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Face, Equal_Face> &faceToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > > , Hash_Edge, Equal_Edge> &edgeToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > > &vertexToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end);
void assignPartitionBoundary(GModel *const model, MFace &me, MElement* reference, std::vector<unsigned int> partitions, std::multimap<partitionFace*, GEntity*, Less_partitionFace> &pfaces, std::map<MElement*, GEntity*> &elementToEntity);
void assignPartitionBoundary(GModel *const model, MEdge &me, MElement* reference, std::vector<unsigned int> partitions, std::multimap<partitionEdge*, GEntity*, Less_partitionEdge> &pedges, std::map<MElement*, GEntity*> &elementToEntity);
void assignPartitionBoundary(GModel *const model, MVertex *ve, MElement* reference, std::vector<unsigned int> partitions, std::multimap<partitionVertex*, GEntity*, Less_partitionVertex> &pvertices, std::map<MElement*, GEntity*> &elementToEntity);

void AssignMeshVertices(GModel *model, int dim = -1, bool inAllDim = false);
void AssignMeshVerticesToEntity(GEntity *entity, bool inAllDim = false);
template <class ITERATOR>
void setVerticesToEntity(GEntity *const entity, ITERATOR it_beg, ITERATOR it_end, bool inAllDim);

void BuildTopology(GModel *model);
void fillBoundaryFace(const GModel *const model, std::set<GFace*> &boundaryFace, partitionRegion* entity, bool full = false);
void fillBoundaryEdge(const GModel *const model, std::set<GEdge*> &boundaryEdge, partitionFace* entity, bool full = false);
void fillBoundaryVertex(const GModel *const model, std::set<GVertex*> &boundaryVertex, partitionEdge* entity, bool full = false);
void addPhysical(GModel *const model, partitionRegion *parentEntity, partitionFace *childEntity);
void addPhysical(GModel *const model, partitionFace *parentEntity, partitionEdge *childEntity);
void addPhysical(GModel *const model, partitionEdge *parentEntity, partitionVertex *childEntity);
int computeOrientation(GEntity *parent, GEntity *child);

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
