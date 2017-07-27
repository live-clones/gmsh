#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <mpi.h>

#include "MElement.h"
#include "MElementCut.h"

#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"

#include "MTriangle.h"
#include "MQuadrangle.h"

#include "MPoint.h"

#include "MElementCut.h"

#include "discreteRegion.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"

#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"

#include "topology_mpi.h"
#include "topology.h"

std::vector<GModel*> PAR::createNewModels(GModel *gModel, GModel *global, int nparts, std::vector<int> myPart)
{
    int nbproc, myrank;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &nbproc);
    
    int maxDim = -1;
    std::vector<GModel*> newModels(myPart.size(), nullptr);
    
    for (unsigned int i = 0; i < myPart.size(); i++)
    {
        newModels[i] = new GModel();
    }
    
    //Loop over regions
    for(GModel::riter it = gModel->firstRegion(); it != gModel->lastRegion(); ++it)
    {
        GRegion *r = *it;
        
        std::vector<GRegion *> newModelHaveRegion(nparts, nullptr);
        std::vector<GRegion *> globalHaveRegion(nparts, nullptr);
        
        //Tetrahedra
        for(unsigned int i = 0; i < r->tetrahedra.size(); i++)
        {
            const int partition = r->tetrahedra[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveRegion[partition])
                {
                    discreteRegion *dr = new discreteRegion(newModels[position], newModels[position]->getNumRegions()+1);
                    newModels[position]->add(dr);
                    newModelHaveRegion[partition] = dr;
                
                    maxDim = 3;
                    addPhysical(newModels[position], dr, gModel, r, partition, maxDim);
                }
            
                newModelHaveRegion[partition]->tetrahedra.push_back(r->tetrahedra[i]);
            }
            if(!globalHaveRegion[partition] && global != nullptr)
            {
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(global, drGlobal, gModel, r, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveRegion[partition]->tetrahedra.push_back(r->tetrahedra[i]);
        }
        
        
        //Hexahedra
        for(unsigned int i = 0; i < r->hexahedra.size(); i++)
        {
            const int partition = r->hexahedra[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveRegion[partition])
                {
                    discreteRegion *dr = new discreteRegion(newModels[position], newModels[position]->getNumRegions()+1);
                    newModels[position]->add(dr);
                    newModelHaveRegion[partition] = dr;
                
                    maxDim = 3;
                    addPhysical(newModels[position], dr, gModel, r, partition, maxDim);
                }
            
                newModelHaveRegion[partition]->hexahedra.push_back(r->hexahedra[i]);
            }
            if(!globalHaveRegion[partition] && global != nullptr)
            {
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(global, drGlobal, gModel, r, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveRegion[partition]->hexahedra.push_back(r->hexahedra[i]);
        }
        
        //Prisms
        for(unsigned int i = 0; i < r->prisms.size(); i++)
        {
            const int partition = r->prisms[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveRegion[partition])
                {
                    discreteRegion *dr = new discreteRegion(newModels[position], newModels[position]->getNumRegions()+1);
                    newModels[position]->add(dr);
                    newModelHaveRegion[partition] = dr;

                    maxDim = 3;
                    addPhysical(newModels[position], dr, gModel, r, partition, maxDim);
                }
            
                newModelHaveRegion[partition]->prisms.push_back(r->prisms[i]);
            }
            if(!globalHaveRegion[partition] && global != nullptr)
            {
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(global, drGlobal, gModel, r, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveRegion[partition]->prisms.push_back(r->prisms[i]);
        }
        
        //Pyramids
        for(unsigned int i = 0; i < r->pyramids.size(); i++)
        {
            const int partition = r->pyramids[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveRegion[partition])
                {
                    discreteRegion *dr = new discreteRegion(newModels[position], newModels[position]->getNumRegions()+1);
                    newModels[position]->add(dr);
                    newModelHaveRegion[partition] = dr;
                
                    maxDim = 3;
                    addPhysical(newModels[position], dr, gModel, r, partition, maxDim);
                }
            
                newModelHaveRegion[partition]->pyramids.push_back(r->pyramids[i]);
            }
            if(!globalHaveRegion[partition] && global != nullptr)
            {
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(global, drGlobal, gModel, r, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveRegion[partition]->pyramids.push_back(r->pyramids[i]);
        }
        
        //Trihedra
        for(unsigned int i = 0; i < r->trihedra.size(); i++)
        {
            const int partition = r->trihedra[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveRegion[partition])
                {
                    discreteRegion *dr = new discreteRegion(newModels[position], newModels[position]->getNumRegions()+1);
                    newModels[position]->add(dr);
                    newModelHaveRegion[partition] = dr;
                
                    maxDim = 3;
                    addPhysical(newModels[position], dr, gModel, r, partition, maxDim);
                }
            
                newModelHaveRegion[partition]->trihedra.push_back(r->trihedra[i]);
            }
            if(!globalHaveRegion[partition] && global != nullptr)
            {
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(global, drGlobal, gModel, r, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveRegion[partition]->trihedra.push_back(r->trihedra[i]);
        }
        
        //Polyhedra
        for(unsigned int i = 0; i < r->polyhedra.size(); i++)
        {
            const int partition = r->polyhedra[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveRegion[partition])
                {
                    discreteRegion *dr = new discreteRegion(newModels[position], newModels[position]->getNumRegions()+1);
                    newModels[position]->add(dr);
                    newModelHaveRegion[partition] = dr;
                
                    maxDim = 3;
                    addPhysical(newModels[position], dr, gModel, r, partition, maxDim);
                }
            
                newModelHaveRegion[partition]->polyhedra.push_back(r->polyhedra[i]);
            }
            if(!globalHaveRegion[partition] && global != nullptr)
            {
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(global, drGlobal, gModel, r, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveRegion[partition]->polyhedra.push_back(r->polyhedra[i]);
        }
    }
    
    //Loop over faces
    for(GModel::fiter it = gModel->firstFace(); it != gModel->lastFace(); ++it)
    {
        GFace *f = *it;
        
        std::vector<GFace *> newModelHaveFace(nparts, nullptr);
        std::vector<GFace *> globalHaveFace(nparts, nullptr);
        
        //Triangles
        for(unsigned int i = 0; i < f->triangles.size(); i++)
        {
            const int partition = f->triangles[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveFace[partition])
                {
                    discreteFace *df = new discreteFace(newModels[position], newModels[position]->getNumFaces()+1);
                    newModels[position]->add(df);
                    newModelHaveFace[partition] = df;
                
                    if(maxDim == -1)
                    {
                        maxDim = 2;
                    }
                    addPhysical(newModels[position], df, gModel, f, partition, maxDim);
                }
            
                newModelHaveFace[partition]->triangles.push_back(f->triangles[i]);
            }
            if(!globalHaveFace[partition] && global != nullptr)
            {
                discreteFace *dfGlobal = new discreteFace(global, global->getNumFaces()+1);
                global->add(dfGlobal);
                globalHaveFace[partition] = dfGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 2;
                }
                addPhysical(global, dfGlobal, gModel, f, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveFace[partition]->triangles.push_back(f->triangles[i]);
        }
        
        //Quadrangles
        for(unsigned int i = 0; i < f->quadrangles.size(); i++)
        {
            const int partition = f->quadrangles[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveFace[partition])
                {
                    discreteFace *df = new discreteFace(newModels[position], newModels[position]->getNumFaces()+1);
                    newModels[position]->add(df);
                    newModelHaveFace[partition] = df;
                
                    if(maxDim == -1)
                    {
                        maxDim = 2;
                    }
                    addPhysical(newModels[position], df, gModel, f, partition, maxDim);
                }
            
                newModelHaveFace[partition]->quadrangles.push_back(f->quadrangles[i]);
            }
            if(!globalHaveFace[partition] && global != nullptr)
            {
                discreteFace *dfGlobal = new discreteFace(global, global->getNumFaces()+1);
                global->add(dfGlobal);
                globalHaveFace[partition] = dfGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 2;
                }
                addPhysical(global, dfGlobal, gModel, f, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveFace[partition]->quadrangles.push_back(f->quadrangles[i]);
        }
        
        //Polygons
        for(unsigned int i = 0; i < f->polygons.size(); i++)
        {
            const int partition = f->polygons[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveFace[partition])
                {
                    discreteFace *df = new discreteFace(newModels[position], newModels[position]->getNumFaces()+1);
                    newModels[position]->add(df);
                    newModelHaveFace[partition] = df;
                
                    if(maxDim == -1)
                    {
                        maxDim = 2;
                    }
                    addPhysical(newModels[position], df, gModel, f, partition, maxDim);
                }
            
                newModelHaveFace[partition]->polygons.push_back(f->polygons[i]);
            }
            if(!globalHaveFace[partition] && global != nullptr)
            {
                discreteFace *dfGlobal = new discreteFace(global, global->getNumFaces()+1);
                global->add(dfGlobal);
                globalHaveFace[partition] = dfGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 2;
                }
                addPhysical(global, dfGlobal, gModel, f, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveFace[partition]->polygons.push_back(f->polygons[i]);
        }
    }
    
    //Loop over edges
    for(GModel::eiter it = gModel->firstEdge(); it != gModel->lastEdge(); ++it)
    {
        GEdge *e = *it;
        
        std::vector<GEdge *> newModelHaveEdge(nparts, nullptr);
        std::vector<GEdge *> globalHaveEdge(nparts, nullptr);
        
        //Lines
        for(unsigned int i = 0; i < e->lines.size(); i++)
        {
            const int partition = e->lines[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveEdge[partition])
                {
                    discreteEdge *de = new discreteEdge(newModels[position], newModels[position]->getNumEdges()+1, nullptr, nullptr);
                    newModels[position]->add(de);
                    newModelHaveEdge[partition] = de;
                    
                    if(maxDim == -1)
                    {
                        maxDim = 1;
                    }
                    addPhysical(newModels[position], de, gModel, e, partition, maxDim);
                }
            
                newModelHaveEdge[partition]->lines.push_back(e->lines[i]);
            }
            if(!globalHaveEdge[partition] && global != nullptr)
            {
                discreteEdge *deGlobal = new discreteEdge(global, global->getNumEdges()+1, nullptr, nullptr);
                global->add(deGlobal);
                globalHaveEdge[partition] = deGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 1;
                }
                addPhysical(global, deGlobal, gModel, e, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveEdge[partition]->lines.push_back(e->lines[i]);
        }
    }
    
    //Loop over vertices
    for(GModel::viter it = gModel->firstVertex(); it != gModel->lastVertex(); ++it)
    {
        GVertex *v = *it;
        
        std::vector<GVertex *> newModelHaveVertex(nparts, nullptr);
        std::vector<GVertex *> globalHaveVertex(nparts, nullptr);
        
        for(unsigned int i = 0; i < v->points.size(); i++)
        {
            const int partition = v->points[i]->getPartition();
            if(std::find(myPart.begin(), myPart.end(), partition) != myPart.end())
            {
                int position = getPos(myPart, partition);
                if(!newModelHaveVertex[partition])
                {
                    discreteVertex *dv = new discreteVertex(newModels[position], newModels[position]->getNumVertices()+1);
                    newModels[position]->add(dv);
                    newModelHaveVertex[partition] = dv;
                
                    if(maxDim == -1)
                    {
                        maxDim = 0;
                    }
                    addPhysical(newModels[position], dv, gModel, v, partition, maxDim);
                }
            
                newModelHaveVertex[partition]->points.push_back(v->points[i]);
            }
            if(!globalHaveVertex[partition] && global != nullptr)
            {
                discreteVertex *dvGlobal = new discreteVertex(global, global->getNumVertices()+1);
                global->add(dvGlobal);
                globalHaveVertex[partition] = dvGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 0;
                }
                addPhysical(global, dvGlobal, gModel, v, partition, maxDim);
            }
            
            if(global != nullptr) globalHaveVertex[partition]->points.push_back(v->points[i]);
        }
    }
    
    return newModels;
}

void PAR::addPhysical(GModel *newModel, GEntity *newEntity, GModel *oldModel, GEntity *oldEntity, int partition, int maxDim)
{
    std::vector<int> oldPhysical = oldEntity->getPhysicalEntities();
    std::string name;
    
    if(maxDim == oldEntity->dim())
    {
        name = "_omega{";
        name += std::to_string(partition);
        name += "}";
        
        const int number = oldModel->getMaxPhysicalNumber(-1)+1+partition;
        
        newModel->setPhysicalName(name, newEntity->dim(), number);
        newEntity->addPhysicalEntity(number);
    }
    
    for(unsigned int i = 0; i < oldPhysical.size(); i++)
    {
        name = oldModel->getPhysicalName(oldEntity->dim(), oldPhysical[i]);
        
        if(name[0] != '_')
        {
            newModel->setPhysicalName(name, newEntity->dim(), oldPhysical[i]);
            newEntity->addPhysicalEntity(oldPhysical[i]);
        }
    }
}

int PAR::getPos(std::vector<int> myPart, int partition)
{
    for(unsigned int i = 0; i < myPart.size(); i++)
    {
        if(myPart[i] == partition) return i;
    }
    
    return -1;
}
