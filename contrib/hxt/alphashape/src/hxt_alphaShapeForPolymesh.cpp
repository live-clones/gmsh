
#include <iostream>
#include "hxt_alphaShapeForPolymesh.h"
#include "meshPolyMesh.h"
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


extern "C" void print4debug(PolyMesh* pm, int debugTag)
  {
    char name[256];
    sprintf(name, "polyMesh%d.pos", debugTag);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \" %s \"{\n", name);
    for(auto it : pm->faces) {
      PolyMesh::HalfEdge *he0 = it->he;
      PolyMesh::HalfEdge *he1 = it->he->next;
      PolyMesh::HalfEdge *he2 = it->he->next->next;
      fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
              he0->v->position.x(), he0->v->position.y(), he0->v->position.z(),
              he1->v->position.x(), he1->v->position.y(), he1->v->position.z(),
              he2->v->position.x(), he2->v->position.y(), he2->v->position.z(),
              it->data, it->data, it->data);
    }
    for(auto it : pm->hedges) {
      PolyMesh::HalfEdge *he = it;
      if(he->data >= 0) {
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", 
                he->v->position.x(), he->v->position.y(), he->v->position.z(),
                he->opposite->v->position.x(), he->opposite->v->position.y(), he->opposite->v->position.z(),
                he->data, he->data);
      }
    }

    fprintf(f, "};\n");
    fclose(f);
}

extern "C" void hxt2PolyMesh(HXTMesh* mesh, HXTAlphaShapeOptions* alphaShapeOptions, PolyMesh** pm)
{
    *pm = new PolyMesh();

    (*pm)->vertices.resize(mesh->vertices.num);
    for (int i=0; i<mesh->vertices.num; i++){
        double *coord = &mesh->vertices.coord[i * 4];
        (*pm)->vertices[i] = new PolyMesh::Vertex(coord[0], coord[1], coord[2], i);
    }
    size_t nNod = 3;
    PolyMesh::Vertex *v[3] = {nullptr, nullptr, nullptr};
    for(size_t i = 0; i < alphaShapeOptions->n_boundaryFacets; i++) {
        for(int j = 0; j < nNod; j++) {
            v[j] = (*pm)->vertices[alphaShapeOptions->boundaryFacets[i * nNod + j]];
        }
        PolyMesh::HalfEdge *he[3];
        for(int j = 0; j < nNod; j++) {
            he[j] = new PolyMesh::HalfEdge(v[j]);
            (*pm)->hedges.push_back(he[j]);
            v[j]->he = he[j];
        }

        PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
        (*pm)->faces.push_back(ff);

        for(int j = 0; j < nNod; j++) {
        he[j]->next = he[(j + 1) % nNod];
        he[j]->prev = he[(j - 1 + nNod) % nNod];
        he[j]->f = ff;
        }
    }

    HalfEdgePtrLessThan compare;
    std::sort((*pm)->hedges.begin(), (*pm)->hedges.end(), compare);

    HalfEdgePtrEqual equal;
    for(size_t i = 0; i < (*pm)->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = (*pm)->hedges[i];
    PolyMesh::HalfEdge *h1 = (*pm)->hedges[i + 1];
    if(equal(h0, h1)) {
        h0->opposite = h1;
        h1->opposite = h0;
        i++;
    }
    }

}

extern "C" int polyMesh2hxt(PolyMesh* pm, HXTMesh* mesh, HXTAlphaShapeOptions* alphaShapeOptions, HXTDelaunayOptions* delOptions, std::vector<double>& nodalSizes) 
{
    mesh->vertices.num = mesh->vertices.size = pm->vertices.size();
    HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord, 4 * pm->vertices.size() * sizeof(double)));
    HXT_CHECK( hxtAlignedRealloc(&delOptions->nodalSizes->array, pm->vertices.size() * sizeof(double)));
    for(size_t i=0; i < pm->vertices.size(); i++) {
        PolyMesh::Vertex* v = pm->vertices[i];
        mesh->vertices.coord[4 * i + 0] = v->position.x();
        mesh->vertices.coord[4 * i + 1] = v->position.y();
        mesh->vertices.coord[4 * i + 2] = v->position.z();
        mesh->vertices.coord[4 * i + 3] = 0;
        delOptions->nodalSizes->array[i] = nodalSizes[i];
    }

    // Find where the triangles of the boundary are --> these need to stay in the mesh! 
    // NOTE : this might not be ideal, because is there really a guarantee that all the boundary triangles are at the beginning..?
    uint32_t index_triangle = 0;
    for (uint32_t i=0; i<mesh->triangles.num; i++) {
        if (mesh->triangles.color[i] == alphaShapeOptions->colorBoundary) {
            index_triangle = i;
            break;
        }
    }

    alphaShapeOptions->n_boundaryFacets = pm->faces.size();
    mesh->triangles.num = mesh->triangles.size = index_triangle + pm->faces.size();
    HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.node, mesh->triangles.num * 3 * sizeof(uint32_t) ));
    HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.color, mesh->triangles.num * sizeof(uint32_t) ));
    HXT_CHECK( hxtAlignedRealloc(&alphaShapeOptions->boundaryFacets, alphaShapeOptions->n_boundaryFacets * 3 * sizeof(uint32_t) ));

    for(size_t i = 0; i < pm->faces.size(); i++) {
        PolyMesh::Face* f = pm->faces[i];
        alphaShapeOptions->boundaryFacets[3 * i + 0] = f->he->v->data;
        alphaShapeOptions->boundaryFacets[3 * i + 1] = f->he->next->v->data;
        alphaShapeOptions->boundaryFacets[3 * i + 2] = f->he->next->next->v->data;
        mesh->triangles.node[3 * index_triangle + 0] = f->he->v->data;
        mesh->triangles.node[3 * index_triangle + 1] = f->he->next->v->data;
        mesh->triangles.node[3 * index_triangle + 2] = f->he->next->next->v->data;
        mesh->triangles.color[index_triangle++] = alphaShapeOptions->colorBoundary;
    }

    return 0;
}

struct heCompare
{
    bool operator()(const void *a, const void *b) const
    {
        PolyMesh::HalfEdge *he0 = (PolyMesh::HalfEdge*)a;
        PolyMesh::HalfEdge *he1 = (PolyMesh::HalfEdge*)b;
        double l0 = norm(he0->v->position - he0->next->v->position);
        double l1 = norm(he1->v->position - he1->next->v->position);
        return l0 > l1;
    }
};
 
int polyMeshSplitHalfEdge(PolyMesh* pm, PolyMesh::HalfEdge* he, SVector3& position, int data, std::vector<PolyMesh::Face*>& newFaces){
    pm->split_edge(he, position, data);
    newFaces.push_back(he->f);
    newFaces.push_back(he->opposite->f);
    newFaces.push_back(he->next->opposite->f);
    newFaces.push_back(he->next->opposite->next->opposite->f);
    return 0;
}

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

double halfEdgeLength(PolyMesh::HalfEdge* he){
    return norm(he->v->position - he->next->v->position);
}   

extern "C" void _refineSurfaceTriangulation(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions) 
{
    // Define polymesh (2D mesh data structure)
    PolyMesh* pm;
    hxt2PolyMesh(mesh, alphaShapeOptions, &pm);
    printf("There are initially %lu facets and %d points in the triangulation\n", pm->faces.size(), pm->vertices.size());
    int ptIndex = mesh->vertices.num;
    // print4debug(pm, 0);
    // hxtMeshWriteGmsh(mesh, "hxtMeshBeforeRefinement.msh");

    std::vector<double> nodalSizes(mesh->vertices.num);
    for (int i=0; i<mesh->vertices.num; i++) nodalSizes[i] = delOptions->nodalSizes->array[i];

    // Refine triangulation
    for (auto he : pm->hedges){
        if (he->opposite == nullptr)
            printf("Error : surface triangulation contains holes ... \n");
    }
    // NB: as a first step, I am considering that there is are no constrained edges (will need to do this in the future, for example considering solid wall edges)

    // Step 1: make set of all faces
    double minQuality = alphaShapeOptions->minQuality;
    double _size = 1.;
    double minRadius = alphaShapeOptions->minRadius;
    std::set<PolyMesh::HalfEdge *, heCompare> _heSet;
    for(auto he : pm->hedges) {
        _heSet.insert(he); // USE SET !!!!!!!!!!!!!!!!!!!!
    }

    // Step 2: refine the triangulation
    int iter = 0;
    double timeInSort = 0.;
    double timeElse = 0.;
    auto tStart = std::chrono::high_resolution_clock::now();

    while (! _heSet.empty()){
        // auto t1 = std::chrono::high_resolution_clock::now();
        PolyMesh::HalfEdge *heToSplit = *_heSet.begin();
        
        std::vector<PolyMesh::Face*> newFaces;
        double l = halfEdgeLength(heToSplit);
        SVector3 midPoint = 0.5*(heToSplit->v->position + heToSplit->next->v->position);
        
        double s0 = nodalSizes[heToSplit->v->data];
        double s1 = nodalSizes[heToSplit->next->v->data];
        _heSet.erase(_heSet.begin());
        // if the edge is too big, split it
        double dimensionFactor = 4/sqrt(6);
        if (l > dimensionFactor*(s0+s1)*0.5){
            polyMeshSplitHalfEdge(pm, heToSplit, midPoint, ptIndex++, newFaces);
            nodalSizes.push_back(0.5*(s0+s1));
            for (auto nf : newFaces) {
                _heSet.insert(nf->he);
                _heSet.insert(nf->he->next);
                _heSet.insert(nf->he->next->next);
            }
            iter++;
        }
        // auto t2 = std::chrono::high_resolution_clock::now();
        // duration<double, std::milli> time_else = t2 - t1;
        // timeElse += (double)time_else.count();
        // print4debug(pm, iter);
    }
    auto tEnd = std::chrono::steady_clock::now();
    duration<double, std::milli> time_total = tEnd - tStart;
    double durTotal = time_total.count();

    // printf("Time spent in sorting : %f \n", 100*timeInSort/durTotal);
    // printf("Surface triangulation done -- added %d new points, there are now %lu faces \n", iter, pm->faces.size());
    delOptions->insertionFirst = mesh->vertices.num;
    polyMesh2hxt(pm, mesh, alphaShapeOptions, delOptions, nodalSizes);
    // printf("insertion first : %d \n", delOptions->insertionFirst);
    int numNewPoints = mesh->vertices.num - delOptions->insertionFirst;
    HXTNodeInfo* nodeInfo;
    hxtAlignedMalloc(&nodeInfo, sizeof(HXTNodeInfo)*numNewPoints);
    for (int i=0; i<numNewPoints; i++){
        nodeInfo[i].node = delOptions->insertionFirst + i;
        nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
    }


    // printf("before doing new delaunay; num vertices in mesh : %d \n", delOptions->numVerticesInMesh);
    hxtDelaunaySteadyVertices(mesh, delOptions, nodeInfo, numNewPoints);
    // hxtMeshWriteGmsh(mesh, "afterRefinement.msh");
    // printf("PolyMesh is back to hxt \n");
    
}