#include <map>
#ifdef PARALLEL
    #include <mpi.h>
#endif

#include "MElementCut.h"

#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"

#include "MTriangle.h"
#include "MQuadrangle.h"

#include "MLine.h"

#include "MPoint.h"

#include "graph.h"

void SEQ::GModelToGraph(GModel* gModel, int* eptr, int** eind, int *metisToGmshIndex)
{
    std::multimap<int, int> elementsToNodes;

    //Loop over regions
    for(GModel::riter it = gModel->firstRegion(); it != gModel->lastRegion(); ++it)
    {
        GRegion *r = *it;
    
        fillElementsToNodes(elementsToNodes, r->tetrahedra.begin(), r->tetrahedra.end());
        fillElementsToNodes(elementsToNodes, r->hexahedra.begin(), r->hexahedra.end());
        fillElementsToNodes(elementsToNodes, r->prisms.begin(), r->prisms.end());
        fillElementsToNodes(elementsToNodes, r->pyramids.begin(), r->pyramids.end());
        fillElementsToNodes(elementsToNodes, r->trihedra.begin(), r->trihedra.end());
        fillElementsToNodes(elementsToNodes, r->polyhedra.begin(), r->polyhedra.end());
    }

    //Loop over faces
    for(GModel::fiter it = gModel->firstFace(); it != gModel->lastFace(); ++it)
    {
        GFace *f = *it;

        fillElementsToNodes(elementsToNodes, f->triangles.begin(), f->triangles.end());
        fillElementsToNodes(elementsToNodes, f->quadrangles.begin(), f->quadrangles.end());
        fillElementsToNodes(elementsToNodes, f->polygons.begin(), f->polygons.end());
    }

    //Loop over edges
    for(GModel::eiter it = gModel->firstEdge(); it != gModel->lastEdge(); ++it)
    {
        GEdge *e = *it;

        fillElementsToNodes(elementsToNodes, e->lines.begin(), e->lines.end());
    }

    //Loop over vertices
    for(GModel::viter it = gModel->firstVertex(); it != gModel->lastVertex(); ++it)
    {
        GVertex *v = *it;

        fillElementsToNodes(elementsToNodes, v->points.begin(), v->points.end());
    }

    //create mesh format for METIS
    unsigned int position = 0;
    eptr[0] = 0;
    unsigned int i = 0;
    int itFirstLast = 0;
    
    for(std::multimap<int, int>::const_iterator it = elementsToNodes.begin(); it != elementsToNodes.end(); ++it)
    {
        if(itFirstLast != it->first+1)
        {
            metisToGmshIndex[i] = it->first + 1;
            position += elementsToNodes.count(it->first);
            eptr[i+1] = position;
            i++;
            itFirstLast = it->first+1;
        }
    }

    (*eind) = new int[position];
    unsigned int positionInd = 0;
    for(std::multimap<int, int>::const_iterator it = elementsToNodes.begin(); it != elementsToNodes.end(); ++it)
    {
        int tag = it->second;
        (*eind)[positionInd] = tag;
        positionInd++;
    }
}

template <class ITERATOR>
void SEQ::fillElementsToNodes(std::multimap<int, int> &elementsToNodes, ITERATOR it_beg, ITERATOR it_end)
{
    for(ITERATOR it = it_beg; it != it_end; ++it)
    {
        const int tag = (*it)->getNum()-1;
        
        for(unsigned int j = 0; j < (*it)->getNumVertices(); j++)
        {
            elementsToNodes.insert(std::pair<int, int>(tag,(*it)->getVertex(j)->getNum()-1));
        }
    }
}

// Parallel

#ifdef PARALLEL
int PAR::GModelToGraph(GModel* gModel, int* eptr, int** eind, int *metisToGmshIndex, int* elmdist)
{
    int nbproc, myrank;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &nbproc);
    
    std::multimap<int, int> elementsToNodes;
    
    for(unsigned int i = elmdist[myrank]; i < elmdist[myrank+1]; i++)
    {
        MElement* elm = gModel->getMeshElementByTag(i+1);
        const int tag = i;
        
        for(unsigned int j = 0; j < elm->getNumVertices(); j++)
        {
            elementsToNodes.insert(std::pair<int, int>(tag,elm->getVertex(j)->getNum()-1));
        }
    }
    
    //create mesh format for METIS
    unsigned int position = 0;
    eptr[0] = 0;
    unsigned int i = 0;
    int itFirstLast = 0;
    
    for(std::multimap<int, int>::const_iterator it = elementsToNodes.begin(); it != elementsToNodes.end(); ++it)
    {
        if(itFirstLast != it->first+1)
        {
            metisToGmshIndex[i] = it->first + 1;
            position += elementsToNodes.count(it->first);
            eptr[i+1] = position;
            i++;
            itFirstLast = it->first+1;
        }
    }
    
    (*eind) = new int[position];
    unsigned int positionInd = 0;
    for(std::multimap<int, int>::const_iterator it = elementsToNodes.begin(); it != elementsToNodes.end(); ++it)
    {
        int tag = it->second;
        (*eind)[positionInd] = tag;
        positionInd++;
    }
    
    return position;
}
#endif

