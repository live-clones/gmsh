#ifndef TOPOLOGY_INCLUDED
#define TOPOLOGY_INCLUDED

#include <unordered_map>

#include "GModel.h"

#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"

#include "MFaceHash.h"
#include "MEdgeHash.h"

namespace SEQ {
    int createPartitionBoundaries(GModel *model, std::vector<GModel*> models);
    
    template <class ITERATOR>
    void fillit_(std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face> &faceToElement, ITERATOR it_beg, ITERATOR it_end);
    template <class ITERATOR>
    void fillit_(std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge> &edgeToElement, ITERATOR it_beg, ITERATOR it_end);
    template <class ITERATOR>
    void fillit_(std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, ITERATOR it_beg, ITERATOR it_end);
    
    void assignPartitionBoundary(GModel *model, MFace &me, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<MElement*> &v, std::vector<GModel*> models, std::vector< std::set<partitionFace*, Less_partitionFace> > &pfacesOfModels);
    void assignPartitionBoundary(GModel *model, MEdge &me, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::vector<MElement*> &v, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<GModel*> models, std::vector< std::set<partitionEdge*, Less_partitionEdge> > &pedgesOfModels);
    void assignPartitionBoundary(GModel *model, MVertex *ve, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::vector<MElement*> &v, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<GModel*> models, std::vector< std::set<partitionVertex*, Less_partitionVertex> > &pverticesOfModels);
    
    std::vector<GModel*> createNewModels(GModel *gModel, GModel *global, int nparts);
    
    void assignMeshVerticesToModel(GModel *gModel);
    template <class ITERATOR>
    void fillVertexToEntity(std::unordered_map<MVertex*, GEntity*> &vertexToEntity, GEntity* entity, ITERATOR it_beg, ITERATOR it_end);
        
    void freeModels(std::vector<GModel*> &models, GModel *global);
    
    void addPhysical(GModel *newModel, GEntity *newEntity, GModel *oldModel, GEntity *oldEntity, GModel *globalModel, GEntity *globalEntity, int partition, int maxDim);
}


#endif //TOPOLOGY_INCLUDED
