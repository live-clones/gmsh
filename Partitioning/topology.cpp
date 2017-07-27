#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <string>

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

#include "topology.h"

int SEQ::createPartitionBoundaries(GModel *model, std::vector<GModel*> models)
{
    unsigned int numElem[6];
    const int meshDim = model->getNumMeshElements(numElem);
    
    std::set<partitionFace*, Less_partitionFace> pfaces;
    std::set<partitionEdge*, Less_partitionEdge> pedges;
    std::set<partitionVertex*, Less_partitionVertex> pvertices;
    
    std::vector< std::set<partitionFace*, Less_partitionFace> > pfacesOfModels(models.size(), std::set<partitionFace*, Less_partitionFace>() );
    std::vector< std::set<partitionEdge*, Less_partitionEdge> > pedgesOfModels(models.size(), std::set<partitionEdge*, Less_partitionEdge>() );
    std::vector< std::set<partitionVertex*, Less_partitionVertex> > pverticesOfModels(models.size(), std::set<partitionVertex*, Less_partitionVertex>() );

    std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face> faceToElement;
    std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge> edgeToElement;
    std::unordered_map<MVertex*, std::vector<MElement*> > vertexToElement;
    
    //Create partition faces
    std::cout << "\tCreate partition faces... " << std::flush;
    if (meshDim == 3)
    {
        for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
        {
            fillit_(faceToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
            fillit_(faceToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
            fillit_(faceToElement, (*it)->prisms.begin(), (*it)->prisms.end());
            fillit_(faceToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
            fillit_(faceToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
            fillit_(faceToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
        }
        
        for(std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face>::const_iterator it = faceToElement.begin(); it != faceToElement.end(); ++it)
        {
            MFace f = it->first;
            std::vector<MElement*> voe = it->second;
            
            assignPartitionBoundary(model, f, pfaces, voe, models, pfacesOfModels);
        }
    }
    std::cout << "Done!" << std::endl;
    
    //Create partition edges
    std::cout << "\tCreate partition edges... " << std::flush;
    if (meshDim >= 2)
    {
        if (meshDim == 2)
        {
            for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
            {
                fillit_(edgeToElement, (*it)->triangles.begin(), (*it)->triangles.end());
                fillit_(edgeToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
                fillit_(edgeToElement, (*it)->polygons.begin(), (*it)->polygons.end());
            }
        }
        
        if (meshDim == 3)
        {
            for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
            {
                fillit_(edgeToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
                fillit_(edgeToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
                fillit_(edgeToElement, (*it)->prisms.begin(), (*it)->prisms.end());
                fillit_(edgeToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
                fillit_(edgeToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
                fillit_(edgeToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
            }
        }
        
        for(std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it)
        {
            MEdge e = it->first;
            
            std::vector<MElement*> voe = it->second;
            
            assignPartitionBoundary(model, e, pedges, voe, pfaces, models, pedgesOfModels);
        }
    }
    std::cout << "Done!" << std::endl;
    
    //Create partition vertices
    std::cout << "\tCreate partition vertices... "  << std::flush;
    if (meshDim >= 1)
    {
        if (meshDim == 1)
        {
            for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
            {
                fillit_(vertexToElement, (*it)->lines.begin(), (*it)->lines.end());
            }
        }
        
        if (meshDim == 2)
        {
            for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
            {
                fillit_(vertexToElement, (*it)->triangles.begin(), (*it)->triangles.end());
                fillit_(vertexToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
                fillit_(vertexToElement, (*it)->polygons.begin(), (*it)->polygons.end());
            }
        }
        
        if (meshDim == 3)
        {
            for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
            {
                fillit_(vertexToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
                fillit_(vertexToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
                fillit_(vertexToElement, (*it)->prisms.begin(), (*it)->prisms.end());
                fillit_(vertexToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
                fillit_(vertexToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
                fillit_(vertexToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
            }
        }
        
        for(std::unordered_map<MVertex*, std::vector<MElement*> >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
        {
            MVertex *v = it->first;
            std::vector<MElement*> voe = it->second;
            
            assignPartitionBoundary(model, v, pvertices, voe, pedges, pfaces, models, pverticesOfModels);
        }
    }
    std::cout << "Done!" << std::endl;
    
    return 0;
}

template <class ITERATOR>
void SEQ::fillit_(std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face> &faceToElement, ITERATOR it_beg, ITERATOR it_end)
{
    for (ITERATOR IT = it_beg; IT != it_end ; ++IT)
    {
        MElement *el = *IT;
        for(unsigned int j = 0; j < el->getNumFaces(); j++)
        {
            faceToElement[el->getFace(j)].push_back(el);
        }
    }
}

template <class ITERATOR>
void SEQ::fillit_(std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge> &edgeToElement, ITERATOR it_beg, ITERATOR it_end)
{
    for (ITERATOR IT = it_beg; IT != it_end; ++IT)
    {
        MElement *el = *IT;
        for(unsigned int j = 0; j < el->getNumEdges(); j++)
        {
            edgeToElement[el->getEdge(j)].push_back(el);
        }
    }
}

template <class ITERATOR>
void SEQ::fillit_(std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, ITERATOR it_beg, ITERATOR it_end)
{
    for (ITERATOR IT = it_beg; IT != it_end ; ++IT)
    {
        MElement *el = *IT;
        for(unsigned int j = 0; j < el->getNumVertices(); j++)
        {
            vertexToElement[el->getVertex(j)].push_back(el);
        }
    }
}

void SEQ::assignPartitionBoundary(GModel *model, MFace &me, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<MElement*> &v, std::vector<GModel*> models, std::vector< std::set<partitionFace*, Less_partitionFace> > &pfacesOfModels)
{
    std::vector<int> v2;
    v2.push_back(v[0]->getPartition());
    
    for (unsigned int i = 1; i < v.size(); i++)
    {
        bool found = false;
        for (unsigned int j = 0; j < v2.size(); j++)
        {
            if (v[i]->getPartition() == v2[j])
            {
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            v2.push_back(v[i]->getPartition());
        }
    }
    
    //If there is less than two partitions touching the face: stop
    if (v2.size() < 2)
    {
        return;
    }
    
    const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
    
    partitionFace pf(model, 1, v2);
    std::set<partitionFace*, Less_partitionFace>::iterator it = pfaces.find(&pf);
    
    partitionFace *ppf;
     //Create the new partition entity for the global mesh
    if (it == pfaces.end())
    {
        //Create new entity and add them to the global model
        ppf = new  partitionFace(model, -(int)pfaces.size()-1, v2);
        pfaces.insert(ppf);
        model->add(ppf);
        
        //Create its new physical name
        ppf->addPhysicalEntity(numPhysical);
        
        std::string name = "_sigma{";
        for(unsigned int j = 0; j < ppf->_partitions.size(); j++)
        {
            if(j > 0)
            {
                name += ",";
            }
            name += std::to_string(ppf->_partitions[j]);
        }
        name += "}";
        
        model->setPhysicalName(name, ppf->dim(), numPhysical);
    }
    else
    {
        ppf = *it;
    }
    
    int numFace = 0;
    for(unsigned int i = 0; i < v[0]->getNumFaces(); i++)
    {
        const MFace e = v[0]->getFace(i);
        if(e == me)
        {
            numFace = i;
            break;
        }
    }
    
    if(me.getNumVertices() == 3)
    {
        std::vector<MVertex*> verts;
        v[0]->getFaceVertices(numFace, verts);
        
        if(verts.size() == 3)
        {
            ppf->triangles.push_back(new MTriangle(verts));
        }
        else if(verts.size() == 6)
        {
            ppf->triangles.push_back(new MTriangle6(verts));
        }
        else
        {
            ppf->triangles.push_back(new MTriangleN(verts, verts[0]->getPolynomialOrder()));
        }
    }
    else if(me.getNumVertices() == 4)
    {
        std::vector<MVertex*> verts;
        v[0]->getFaceVertices(numFace, verts);
        
        if(verts.size() == 4)
        {
            ppf->quadrangles.push_back(new MQuadrangle(verts));
        }
        else if(verts.size() == 8)
        {
            ppf->quadrangles.push_back(new MQuadrangle8(verts));
        }
        else if(verts.size() == 9)
        {
            ppf->quadrangles.push_back(new MQuadrangle9(verts));
        }
        else
        {
            ppf->quadrangles.push_back(new MQuadrangleN(verts, verts[0]->getPolynomialOrder()));
        }
    }
    
    for(unsigned int i = 0; i < v2.size(); i++)
    {
        partitionFace pf(model, 1, v2);
        std::set<partitionFace*, Less_partitionFace>::iterator it = pfacesOfModels[v2[i]].find(&pf);
        
        //Create the new partition entity for partitioned meshes
        partitionFace *ppf;
        if (it == pfacesOfModels[v2[i]].end())
        {
            //Create new entity and add them to partitioned models
            ppf = new  partitionFace(models[v2[i]], -(int)pfacesOfModels[v2[i]].size()-1, v2);
            pfacesOfModels[v2[i]].insert(ppf);
            models[v2[i]]->add(ppf);
            
            //Create its new physical name
            ppf->addPhysicalEntity(numPhysical);
            
            std::string name = "_sigma{";
            for(unsigned int j = 0; j < ppf->_partitions.size(); j++)
            {
                if(j > 0)
                {
                    name += ",";
                }
                name += std::to_string(ppf->_partitions[j]);
            }
            name += "}";
            
            models[v2[i]]->setPhysicalName(name, ppf->dim(), numPhysical);
        }
        else
        {
            ppf = *it;
        }
        
        int numEdge = 0;
        int numElm = 0;
        for(unsigned int j = 0; j < v.size(); j++)
        {
            if(v[j]->getPartition() == v2[i])
            {
                numElm = j;
                for(unsigned int k = 0; k < v[j]->getNumFaces(); k++)
                {
                    const MFace e = v[j]->getFace(k);
                    if(e == me)
                    {
                        numFace = k;
                        break;
                    }
                }
                break;
            }
        }
        
        if(me.getNumVertices() == 3)
        {
            std::vector<MVertex*> verts;
            v[numElm]->getFaceVertices(numFace, verts);
            
            if(verts.size() == 3)
            {
                ppf->triangles.push_back(new MTriangle(verts));
            }
            else if(verts.size() == 6)
            {
                ppf->triangles.push_back(new MTriangle6(verts));
            }
            else
            {
                ppf->triangles.push_back(new MTriangleN(verts, verts[0]->getPolynomialOrder()));
            }
        }
        else if(me.getNumVertices() == 4)
        {
            std::vector<MVertex*> verts;
            v[numElm]->getFaceVertices(numFace, verts);
            
            if(verts.size() == 4)
            {
                ppf->quadrangles.push_back(new MQuadrangle(verts));
            }
            else if(verts.size() == 8)
            {
                ppf->quadrangles.push_back(new MQuadrangle8(verts));
            }
            else if(verts.size() == 9)
            {
                ppf->quadrangles.push_back(new MQuadrangle9(verts));
            }
            else
            {
                ppf->quadrangles.push_back(new MQuadrangleN(verts, verts[0]->getPolynomialOrder()));
            }
        }
    }
}

void SEQ::assignPartitionBoundary(GModel *model, MEdge &me, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::vector<MElement*> &v, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<GModel*> models, std::vector< std::set<partitionEdge*, Less_partitionEdge> > &pedgesOfModels)
{
    std::vector<int> v2;
    v2.push_back(v[0]->getPartition());
    
    for (unsigned int i = 1; i < v.size(); i++)
    {
        bool found = false;
        for (unsigned int j = 0; j < v2.size(); j++)
        {
            if (v[i]->getPartition() == v2[j])
            {
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            v2.push_back(v[i]->getPartition());
        }
    }
    
    //If there is less than two partitions touching the edge: stop
    if (v2.size() < 2)
    {
        return;
    }
    
    partitionFace pf(model, 1, v2);
    std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
    
    //If the edge is on a partitionFace
    if (itf != pfaces.end())
    {
        return;
    }
    
    const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
    
    partitionEdge pe(model, 1, nullptr, nullptr, v2);
    std::set<partitionEdge*, Less_partitionEdge>::iterator it = pedges.find(&pe);
    
    partitionEdge *ppe;
    //Create the new partition entity for the global mesh
    if (it == pedges.end())
    {
        //Create new entity and add them to the global model
        ppe = new  partitionEdge(model, -(int)pedges.size()-1, 0, 0, v2);
        pedges.insert(ppe);
        model->add(ppe);
        
        //Create its new physical name
        ppe->addPhysicalEntity(numPhysical);
        
        std::string name = "_sigma{";
        for(unsigned int j = 0; j < ppe->_partitions.size(); j++)
        {
            if(j > 0)
            {
                name += ",";
            }
            name += std::to_string(ppe->_partitions[j]);
        }
        name += "}";
        
        model->setPhysicalName(name, ppe->dim(), numPhysical);
    }
    else
    {
        ppe = *it;
    }
    
    int numEdge = 0;
    for(unsigned int i = 0; i < v[0]->getNumEdges(); i++)
    {
        const MEdge e = v[0]->getEdge(i);
        if(e == me)
        {
            numEdge = i;
            break;
        }
    }
    
    if(me.getNumVertices() == 2)
    {
        std::vector<MVertex*> verts;
        v[0]->getEdgeVertices(numEdge, verts);
        
        if(verts.size() == 2)
        {
            ppe->lines.push_back(new MLine(verts));
        }
        else if(verts.size() == 3)
        {
            ppe->lines.push_back(new MLine3(verts));
        }
        else
        {
            ppe->lines.push_back(new MLineN(verts));
        }
    }
    
    for(unsigned int i = 0; i < v2.size(); i++)
    {
        partitionEdge pe(models[v2[i]], 1, nullptr, nullptr, v2);
        std::set<partitionEdge*, Less_partitionEdge>::iterator it = pedgesOfModels[v2[i]].find(&pe);
        
        //Create the new partition entity for partitioned meshes
        partitionEdge *ppe;
        if (it == pedgesOfModels[v2[i]].end())
        {
            //Create new entity and add them to partitioned models
            ppe = new  partitionEdge(models[v2[i]], -(int)pedgesOfModels[v2[i]].size()-1, 0, 0, v2);
            pedgesOfModels[v2[i]].insert(ppe);
            models[v2[i]]->add(ppe);
            
            //Create its new physical name
            ppe->addPhysicalEntity(numPhysical);
            
            std::string name = "_sigma{";
            for(unsigned int j = 0; j < ppe->_partitions.size(); j++)
            {
                if(j > 0)
                {
                    name += ",";
                }
                name += std::to_string(ppe->_partitions[j]);
            }
            name += "}";
            
            models[v2[i]]->setPhysicalName(name, ppe->dim(), numPhysical);
        }
        else
        {
            ppe = *it;
        }
        
        int numEdge = 0;
        int numElm = 0;

        for(unsigned int j = 0; j < v.size(); j++)
        {
            if(v[j]->getPartition() == v2[i])
            {
                numElm = j;
                for(unsigned int k = 0; k < v[j]->getNumEdges(); k++)
                {
                    const MEdge e = v[j]->getEdge(k);
                    if(e == me)
                    {
                        numEdge = k;
                        break;
                    }
                }
                break;
            }
        }
        
        if(me.getNumVertices() == 2)
        {
            std::vector<MVertex*> verts;
            v[numElm]->getEdgeVertices(numEdge, verts);
            
            if(verts.size() == 2)
            {
                ppe->lines.push_back(new MLine(verts));
            }
            else if(verts.size() == 3)
            {
                ppe->lines.push_back(new MLine3(verts));
            }
            else
            {
                ppe->lines.push_back(new MLineN(verts));
            }
        }
    }
}

void SEQ::assignPartitionBoundary(GModel *model, MVertex *ve, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::vector<MElement*> &v, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<GModel*> models, std::vector< std::set<partitionVertex*, Less_partitionVertex> > &pverticesOfModels)
{
    std::vector<int> v2;
    v2.push_back(v[0]->getPartition());
    
    for (unsigned int i = 1; i < v.size(); i++)
    {
        bool found = false;
        for (unsigned int j = 0; j < v2.size(); j++)
        {
            if (v[i]->getPartition() == v2[j])
            {
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            v2.push_back(v[i]->getPartition());
        }
    }
    
    //If there is less than two partitions touching the vertex: stop
    if (v2.size() < 2)
    {
        return;
    }
    
    partitionFace pf(model, 1, v2);
    std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
    
    //If the vertex is on a partitionFace
    if (itf != pfaces.end())
    {
        return;
    }
    
    partitionEdge pe(model, 1, 0, 0, v2);
    std::set<partitionEdge*, Less_partitionEdge>::iterator ite = pedges.find(&pe);
    
    //If the vertex is on a partitionFace
    if (ite != pedges.end())
    {
        return;
    }

    const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
    
    partitionVertex pv(model, 1, v2);
    std::set<partitionVertex*, Less_partitionVertex>::iterator it = pvertices.find(&pv);
    
    partitionVertex *ppv;
    //Create the new partition entity for the global mesh
    if (it == pvertices.end())
    {
        ppv = new partitionVertex(model, -(int)pvertices.size()-1,v2);
        pvertices.insert (ppv);
        model->add(ppv);
        
        //Create its new physical name
        ppv->addPhysicalEntity(numPhysical);
        
        std::string name = "_sigma{";
        for(unsigned int j = 0; j < ppv->_partitions.size(); j++)
        {
            if(j > 0)
            {
                name += ",";
            }
            name += std::to_string(ppv->_partitions[j]);
        }
        name += "}";
        
        model->setPhysicalName(name, ppv->dim(), numPhysical);
    }
    else
    {
        ppv = *it;
    }
    
    ppv->points.push_back(new MPoint(ve));
    
    for(unsigned int i = 0; i < v2.size(); i++)
    {
        partitionVertex pv(model, 1, v2);
        std::set<partitionVertex*, Less_partitionVertex>::iterator it = pverticesOfModels[v2[i]].find(&pv);
        
        partitionVertex *ppv;
        //Create the new partition entity for the global mesh
        if (it == pverticesOfModels[v2[i]].end())
        {
            ppv = new partitionVertex(model, -(int)pverticesOfModels[v2[i]].size()-1,v2);
            pverticesOfModels[v2[i]].insert (ppv);
            models[v2[i]]->add(ppv);
            
            //Create its new physical name
            ppv->addPhysicalEntity(numPhysical);
            
            std::string name = "_sigma{";
            for(unsigned int j = 0; j < ppv->_partitions.size(); j++)
            {
                if(j > 0)
                {
                    name += ",";
                }
                name += std::to_string(ppv->_partitions[j]);
            }
            name += "}";
            
            models[v2[i]]->setPhysicalName(name, ppv->dim(), numPhysical);
        }
        else
        {
            ppv = *it;
        }
        
        ppv->points.push_back(new MPoint(ve));
    }
}

std::vector<GModel*> SEQ::createNewModels(GModel *gModel, GModel *global, int nparts)
{
    int maxDim = -1;
    std::vector<GModel*> newModels(nparts, nullptr);
    
    for (unsigned int i = 0; i < nparts; i++)
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
            if(!newModelHaveRegion[partition])
            {
                discreteRegion *dr = new discreteRegion(newModels[partition], newModels[partition]->getNumRegions()+1);
                newModels[partition]->add(dr);
                newModelHaveRegion[partition] = dr;
                
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(newModels[partition], dr, gModel, r, global, drGlobal, partition, maxDim);
            }
            
            newModelHaveRegion[partition]->tetrahedra.push_back(r->tetrahedra[i]);
            globalHaveRegion[partition]->tetrahedra.push_back(r->tetrahedra[i]);
        }
        

        //Hexahedra
        for(unsigned int i = 0; i < r->hexahedra.size(); i++)
        {
            const int partition = r->hexahedra[i]->getPartition();
            if(!newModelHaveRegion[partition])
            {
                discreteRegion *dr = new discreteRegion(newModels[partition], newModels[partition]->getNumRegions()+1);
                newModels[partition]->add(dr);
                newModelHaveRegion[partition] = dr;
                
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(newModels[partition], dr, gModel, r, global, drGlobal, partition, maxDim);
            }
            
            newModelHaveRegion[partition]->hexahedra.push_back(r->hexahedra[i]);
            globalHaveRegion[partition]->hexahedra.push_back(r->hexahedra[i]);
        }
        
        //Prisms
        for(unsigned int i = 0; i < r->prisms.size(); i++)
        {
            const int partition = r->prisms[i]->getPartition();
            if(!newModelHaveRegion[partition])
            {
                discreteRegion *dr = new discreteRegion(newModels[partition], newModels[partition]->getNumRegions()+1);
                newModels[partition]->add(dr);
                newModelHaveRegion[partition] = dr;
                
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(newModels[partition], dr, gModel, r, global, drGlobal, partition, maxDim);
            }
            
            newModelHaveRegion[partition]->prisms.push_back(r->prisms[i]);
            globalHaveRegion[partition]->prisms.push_back(r->prisms[i]);
        }
        
        //Pyramids
        for(unsigned int i = 0; i < r->pyramids.size(); i++)
        {
            const int partition = r->pyramids[i]->getPartition();
            if(!newModelHaveRegion[partition])
            {
                discreteRegion *dr = new discreteRegion(newModels[partition], newModels[partition]->getNumRegions()+1);
                newModels[partition]->add(dr);
                newModelHaveRegion[partition] = dr;
                
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(newModels[partition], dr, gModel, r, global, drGlobal, partition, maxDim);
            }
            
            newModelHaveRegion[partition]->pyramids.push_back(r->pyramids[i]);
            globalHaveRegion[partition]->pyramids.push_back(r->pyramids[i]);
        }
        
        //Trihedra
        for(unsigned int i = 0; i < r->trihedra.size(); i++)
        {
            const int partition = r->trihedra[i]->getPartition();
            if(!newModelHaveRegion[partition])
            {
                discreteRegion *dr = new discreteRegion(newModels[partition], newModels[partition]->getNumRegions()+1);
                newModels[partition]->add(dr);
                newModelHaveRegion[partition] = dr;
                
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(newModels[partition], dr, gModel, r, global, drGlobal, partition, maxDim);
            }
            
            newModelHaveRegion[partition]->trihedra.push_back(r->trihedra[i]);
            globalHaveRegion[partition]->trihedra.push_back(r->trihedra[i]);
        }
        
        //Polyhedra
        for(unsigned int i = 0; i < r->polyhedra.size(); i++)
        {
            const int partition = r->polyhedra[i]->getPartition();
            if(!newModelHaveRegion[partition])
            {
                discreteRegion *dr = new discreteRegion(newModels[partition], newModels[partition]->getNumRegions()+1);
                newModels[partition]->add(dr);
                newModelHaveRegion[partition] = dr;
                
                discreteRegion *drGlobal = new discreteRegion(global, global->getNumRegions()+1);
                global->add(drGlobal);
                globalHaveRegion[partition] = drGlobal;
                
                maxDim = 3;
                addPhysical(newModels[partition], dr, gModel, r, global, drGlobal, partition, maxDim);
            }
            
            newModelHaveRegion[partition]->polyhedra.push_back(r->polyhedra[i]);
            globalHaveRegion[partition]->polyhedra.push_back(r->polyhedra[i]);
        }
    }
    
    //Loop over faces
    for(GModel::fiter it = gModel->firstFace(); it != gModel->lastFace(); ++it)
    {
        GFace *f = *it;
        
        std::vector<GFace *> newModelHaveFace(nparts, nullptr);
        std::vector<GFace *> globalModelHaveFace(nparts, nullptr);
        
        //Triangles
        for(unsigned int i = 0; i < f->triangles.size(); i++)
        {
            const int partition = f->triangles[i]->getPartition();
            if(!newModelHaveFace[partition])
            {
                discreteFace *df = new discreteFace(newModels[partition], newModels[partition]->getNumFaces()+1);
                newModels[partition]->add(df);
                newModelHaveFace[partition] = df;
                
                discreteFace *dfGlobal = new discreteFace(global, global->getNumFaces()+1);
                global->add(dfGlobal);
                globalModelHaveFace[partition] = dfGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 2;
                }
                addPhysical(newModels[partition], df, gModel, f, global, dfGlobal, partition, maxDim);
            }
            
            newModelHaveFace[partition]->triangles.push_back(f->triangles[i]);
            globalModelHaveFace[partition]->triangles.push_back(f->triangles[i]);
        }
        
        //Quadrangles
        for(unsigned int i = 0; i < f->quadrangles.size(); i++)
        {
            const int partition = f->quadrangles[i]->getPartition();
            if(!newModelHaveFace[partition])
            {
                discreteFace *df = new discreteFace(newModels[partition], newModels[partition]->getNumFaces()+1);
                newModels[partition]->add(df);
                newModelHaveFace[partition] = df;
                
                discreteFace *dfGlobal = new discreteFace(global, global->getNumFaces()+1);
                global->add(dfGlobal);
                globalModelHaveFace[partition] = dfGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 2;
                }
                addPhysical(newModels[partition], df, gModel, f, global, dfGlobal, partition, maxDim);
            }
            
            newModelHaveFace[partition]->quadrangles.push_back(f->quadrangles[i]);
            globalModelHaveFace[partition]->quadrangles.push_back(f->quadrangles[i]);
        }
        
        //Polygons
        for(unsigned int i = 0; i < f->polygons.size(); i++)
        {
            const int partition = f->polygons[i]->getPartition();
            if(!newModelHaveFace[partition])
            {
                discreteFace *df = new discreteFace(newModels[partition], newModels[partition]->getNumFaces()+1);
                newModels[partition]->add(df);
                newModelHaveFace[partition] = df;
                
                discreteFace *dfGlobal = new discreteFace(global, global->getNumFaces()+1);
                global->add(dfGlobal);
                globalModelHaveFace[partition] = dfGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 2;
                }
                addPhysical(newModels[partition], df, gModel, f, global, dfGlobal, partition, maxDim);
            }
            
            newModelHaveFace[partition]->polygons.push_back(f->polygons[i]);
            globalModelHaveFace[partition]->quadrangles.push_back(f->quadrangles[i]);
        }
    }
    
    //Loop over edges
    for(GModel::eiter it = gModel->firstEdge(); it != gModel->lastEdge(); ++it)
    {
        GEdge *e = *it;
        
        std::vector<GEdge *> newModelHaveEdge(nparts, nullptr);
        std::vector<GEdge *> globalModelHaveEdge(nparts, nullptr);
        
        //Lines
        for(unsigned int i = 0; i < e->lines.size(); i++)
        {
            const int partition = e->lines[i]->getPartition();
            if(!newModelHaveEdge[partition])
            {
                discreteEdge *de = new discreteEdge(newModels[partition], newModels[partition]->getNumEdges()+1, nullptr, nullptr);
                newModels[partition]->add(de);
                newModelHaveEdge[partition] = de;
                
                discreteEdge *deGlobal = new discreteEdge(global, global->getNumEdges()+1, nullptr, nullptr);
                global->add(deGlobal);
                globalModelHaveEdge[partition] = deGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 1;
                }
                addPhysical(newModels[partition], de, gModel, e, global, deGlobal, partition, maxDim);
            }
            
            newModelHaveEdge[partition]->lines.push_back(e->lines[i]);
            globalModelHaveEdge[partition]->lines.push_back(e->lines[i]);
        }
    }
    
    //Loop over vertices
    for(GModel::viter it = gModel->firstVertex(); it != gModel->lastVertex(); ++it)
    {
        GVertex *v = *it;
        
        std::vector<GVertex *> newModelHaveVertex(nparts, nullptr);
        std::vector<GVertex *> globalModelHaveVertex(nparts, nullptr);
        
        for(unsigned int i = 0; i < v->points.size(); i++)
        {
            const int partition = v->points[i]->getPartition();
            if(!newModelHaveVertex[partition])
            {
                discreteVertex *dv = new discreteVertex(newModels[partition], newModels[partition]->getNumVertices()+1);
                newModels[partition]->add(dv);
                newModelHaveVertex[partition] = dv;
                
                discreteVertex *dvGlobal = new discreteVertex(global, global->getNumVertices()+1);
                global->add(dvGlobal);
                globalModelHaveVertex[partition] = dvGlobal;
                
                if(maxDim == -1)
                {
                    maxDim = 0;
                }
                addPhysical(newModels[partition], dv, gModel, v, global, dvGlobal, partition, maxDim);
            }
            
            newModelHaveVertex[partition]->points.push_back(v->points[i]);
            globalModelHaveVertex[partition]->points.push_back(v->points[i]);
        }
    }
    
    return newModels;
}

void SEQ::assignMeshVerticesToModel(GModel *gModel)
{
    std::unordered_map<MVertex*, GEntity*> vertexToEntity;
    
    //Loop over regions
    for(GModel::riter it = gModel->firstRegion(); it != gModel->lastRegion(); ++it)
    {
        GRegion *r = *it;
        
        fillVertexToEntity(vertexToEntity, r, r->tetrahedra.begin(), r->tetrahedra.end());
        fillVertexToEntity(vertexToEntity, r, r->hexahedra.begin(), r->hexahedra.end());
        fillVertexToEntity(vertexToEntity, r, r->prisms.begin(), r->prisms.end());
        fillVertexToEntity(vertexToEntity, r, r->pyramids.begin(), r->pyramids.end());
        fillVertexToEntity(vertexToEntity, r, r->trihedra.begin(), r->trihedra.end());
        fillVertexToEntity(vertexToEntity, r, r->polyhedra.begin(), r->polyhedra.end());
    }
    
    //Loop over faces
    for(GModel::fiter it = gModel->firstFace(); it != gModel->lastFace(); ++it)
    {
        GFace *f = *it;
        
        fillVertexToEntity(vertexToEntity, f, f->triangles.begin(), f->triangles.end());
        fillVertexToEntity(vertexToEntity, f, f->quadrangles.begin(), f->quadrangles.end());
        fillVertexToEntity(vertexToEntity, f, f->polygons.begin(), f->polygons.end());
    }
    
    //Loop over edges
    for(GModel::eiter it = gModel->firstEdge(); it != gModel->lastEdge(); ++it)
    {
        GEdge *e = *it;
        
        fillVertexToEntity(vertexToEntity, e, e->lines.begin(), e->lines.end());
    }
    
    //Loop over vertices
    for(GModel::viter it = gModel->firstVertex(); it != gModel->lastVertex(); ++it)
    {
        GVertex *v = *it;
        
        fillVertexToEntity(vertexToEntity, v, v->points.begin(), v->points.end());
    }
    
    //Fill the entities
    for(std::unordered_map<MVertex*, GEntity*>::iterator it = vertexToEntity.begin(); it != vertexToEntity.end(); ++it)
    {
        it->second->addMeshVertex(it->first);
    }
}

template <class ITERATOR>
void SEQ::fillVertexToEntity(std::unordered_map<MVertex*, GEntity*> &vertexToEntity, GEntity* entity, ITERATOR it_beg, ITERATOR it_end)
{
    for(ITERATOR it = it_beg; it != it_end; ++it)
    {
        const int numVertices = (*it)->getNumVertices();
        for(unsigned int j = 0; j < numVertices; j++)
        {
            if(vertexToEntity.find((*it)->getVertex(j)) != vertexToEntity.end())
            {
                if(vertexToEntity[(*it)->getVertex(j)]->dim() > entity->dim())
                {
                    vertexToEntity[(*it)->getVertex(j)] = entity;
                }
            }
            else
            {
                vertexToEntity[(*it)->getVertex(j)] = entity;
            }
        }
    }
}

void SEQ::freeModels(std::vector<GModel*> &models, GModel *global)
{
    for(unsigned int i = 0; i < models.size(); i++)
    {
        std::vector<GEntity*> entities;
        models[i]->getEntities(entities);
        
        for(unsigned int j = 0; j < entities.size(); j++)
        {            
            switch(entities[j]->dim())
            {
                case 3:
                    models[i]->remove(static_cast<GRegion*>(entities[j]));
                    break;
                case 2:
                    models[i]->remove(static_cast<GFace*>(entities[j]));
                    break;
                case 1:
                    models[i]->remove(static_cast<GEdge*>(entities[j]));
                    break;
                case 0:
                    models[i]->remove(static_cast<GVertex*>(entities[j]));
                    break;
                default:
                    break;
            }
        }
    }
    
    if(global == nullptr) return;
        
    std::vector<GEntity*> entities;
    global->getEntities(entities);
    
    for(unsigned int j = 0; j < entities.size(); j++)
    {
        switch(entities[j]->dim())
        {
            case 3:
                global->remove(static_cast<GRegion*>(entities[j]));
                break;
            case 2:
                global->remove(static_cast<GFace*>(entities[j]));
                break;
            case 1:
                global->remove(static_cast<GEdge*>(entities[j]));
                break;
            case 0:
                global->remove(static_cast<GVertex*>(entities[j]));
                break;
            default:
                break;
        }
    }
}

void SEQ::addPhysical(GModel *newModel, GEntity *newEntity, GModel *oldModel, GEntity *oldEntity, GModel *globalModel, GEntity *globalEntity, int partition, int maxDim)
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
        
        globalModel->setPhysicalName(name, globalEntity->dim(), number);
        globalEntity->addPhysicalEntity(number);
    }
    
    for(unsigned int i = 0; i < oldPhysical.size(); i++)
    {
        name = oldModel->getPhysicalName(oldEntity->dim(), oldPhysical[i]);
        
        if(name[0] != '_')
        {
            newModel->setPhysicalName(name, newEntity->dim(), oldPhysical[i]);
            newEntity->addPhysicalEntity(oldPhysical[i]);
            
            globalModel->setPhysicalName(name, globalEntity->dim(), oldPhysical[i]);
            globalEntity->addPhysicalEntity(oldPhysical[i]);
        }
    }
}







