// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_H_
#define _MESH_PARTITION_H_

#include <vector>
#include <unordered_map>

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
class meshPartitionOptions;

int PartitionMesh(GModel *const model, meshPartitionOptions &options);

int MakeGraph(GModel *const model, Graph &graph);
template <class ITERATOR>
void fillElementsToNodesMap(Graph &graph, int &eptrIndex, int &eindIndex, ITERATOR it_beg, ITERATOR it_end);
int getSizeOfEind(GModel *const model);
int getNumVertices(MElement *const element);

int PartitionGraph(Graph &graph, meshPartitionOptions &options);

int RenumberMesh(GModel *const model, meshPartitionOptions &options);
int RenumberMeshElements(std::vector<MElement*> &elements, meshPartitionOptions &options);
int RenumberMesh(GModel *const model, meshPartitionOptions &options, std::vector<MElement*> &numbered);
int RenumberGraph(Graph &graph, meshPartitionOptions &options);

std::multimap<int, GEntity*> CreateNewEntities(GModel *model, meshPartitionOptions &options);
template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GRegion *> &newRegions, GRegion *region, std::vector<discreteRegion *> &dRegions, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GFace *> &newFaces, GFace *face, std::vector<discreteFace *> &dFaces, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GEdge *> &newEdges, GEdge *edge, std::vector<discreteEdge *> &dEdges, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GVertex *> &newVertices, GVertex *vertex, std::vector<discreteVertex *> &dVertices, ITERATOR it_beg, ITERATOR it_end);
void addPhysical(GModel *model, GEntity *newEntity, GEntity *oldEntity, int partition);

std::multimap<int, GEntity*> CreatePartitionBoundaries(GModel *model, bool createGhostCells);
template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face> &faceToElement, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge> &edgeToElement, ITERATOR it_beg, ITERATOR it_end);
template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, ITERATOR it_beg, ITERATOR it_end);
void assignPartitionBoundary(GModel *model, MFace &me, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<MElement*> &v);
void assignPartitionBoundary(GModel *model, MEdge &me, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::vector<MElement*> &v, std::set<partitionFace*, Less_partitionFace> &pfaces);
void assignPartitionBoundary(GModel *model, MVertex *ve, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::vector<MElement*> &v, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces);

void AssignMeshVertices(GModel *model);
template <class ITERATOR>
void setVerticesToEntity(std::set<MVertex *> &verts, ITERATOR it_beg, ITERATOR it_end);

void CreateTopologyFile(GModel* model, const int npart);
std::vector<int> getNumFromString(std::string name);
bool commonPhysicals(const std::vector<int> vec1, const std::vector<int> vec2, std::vector<int>* vecCommon);




int PartitionMeshFace(std::list<GFace*> &cFaces, meshPartitionOptions &options);
int PartitionMeshElements(std::vector<MElement*> &elements,
                          meshPartitionOptions &options);

void splitBoundaryEdges(GModel *model,
                        std::set<partitionEdge*, Less_partitionEdge> &newEdges);
void createPartitionFaces(GModel *model, std::vector<MElement *> &elements, int num_parts,
                          std::vector<discreteFace*> &pFaces);

#endif
