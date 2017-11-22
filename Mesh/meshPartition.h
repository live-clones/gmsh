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

int MakeGraph(GModel *const model, Graph &graph);
template <class ITERATOR>
void fillElementsToNodesMap(Graph &graph, const GEntity *const entity, int &eptrIndex, int &eindIndex, int &numVertex, ITERATOR it_beg, ITERATOR it_end);
int getSizeOfEind(const GModel *const model);
int getNumVertices(const MElement *const element);
bool isPeriodic(const GModel *const model);

int PartitionGraph(Graph &graph);
void createDualGraph(Graph &graph);

void CreateNewEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::multimap<unsigned short, GEntity*> &newPartitionEntities);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GRegion *> &newRegions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GFace *> &newFaces, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GEdge *> &newEdges, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GVertex *> &newVertices, ITERATOR it_beg, ITERATOR it_end);
void addPhysical(GModel *const model, GEntity *const entity, const unsigned short partition);

void CreatePartitionBoundaries(GModel *const model, std::multimap<unsigned short, GEntity*> &newPartitionBoundaries, std::multimap<unsigned short, GEntity*> &newBoundariesOfPartitionBoundaries);
MElement* getReferenceElement(const std::vector< std::pair<MElement*, std::vector<unsigned short> > > &elementPairs, std::vector<unsigned short> &referencePartitions);
void getPartitionInVector(std::vector<unsigned short> &partitions, const std::vector< std::pair<MElement*, std::vector<unsigned short> > > &boundaryPair);
template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Face, Equal_Face> &faceToElement, std::vector<unsigned short> &partitions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned short> > > , Hash_Edge, Equal_Edge> &edgeToElement, std::vector<unsigned short> &partitions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned short> > > > &vertexToElement, std::vector<unsigned short> &partitions, ITERATOR it_beg, ITERATOR it_end);
void assignPartitionBoundary(GModel *const model, MFace &me, MElement* reference, std::vector<unsigned short> partitions, std::set<partitionFace*, Less_partitionFace> &pfaces);
void assignPartitionBoundary(GModel *const model, MEdge &me, MElement* reference, std::vector<unsigned short> partitions, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::set<partitionEdge*, Less_partitionEdge> &bndedges);
void assignPartitionBoundary(GModel *const model, MVertex *ve, MElement* reference, std::vector<unsigned short> partitions, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::set<partitionEdge*, Less_partitionEdge> &bndedges, std::set<partitionVertex*, Less_partitionVertex> &bndvertices);

void AssignMeshVertices(GModel *model);
template <class ITERATOR>
void setVerticesToEntity(std::set<MVertex *> &verts, GEntity *const entity, ITERATOR it_beg, ITERATOR it_end);

int CreateTopologyFile(GModel* model, std::string name);
int getTag(GModel* model, GEntity* entity);
std::string getSubstr(GModel* model, GEntity* entity);
std::vector<unsigned short> getPartition(GModel* model, GEntity* entity);

void ComputePartitionedBREP(GModel* model, std::multimap<unsigned short, GEntity*> &newPartitionEntities, std::multimap<unsigned short, GEntity*> &newPartitionBoundaries, std::multimap<unsigned short, GEntity*> &newBoundariesOfPartitionBoundaries);


int PartitionMeshFace(std::list<GFace*> &cFaces);
int PartitionMeshElements(std::vector<MElement*> &elements);

void splitBoundaryEdges(GModel *model,
                        std::set<partitionEdge*, Less_partitionEdge> &newEdges);
void createPartitionFaces(GModel *model, std::vector<MElement *> &elements, int num_parts, std::vector<discreteFace*> &pFaces);

#endif
