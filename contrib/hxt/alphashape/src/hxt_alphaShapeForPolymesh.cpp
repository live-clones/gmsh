
#include <iostream>
#include <chrono>
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
    for(auto it : pm->vertices) {
        PolyMesh::Vertex *v = it;
        fprintf(f, "SP(%g,%g,%g){%d};\n", 
                v->position.x(), v->position.y(), v->position.z(),
                v->data);
      }

    fprintf(f, "};\n");
    fclose(f);
}

extern "C" void hxt2PolyMesh(HXTMesh* mesh, HXTAlphaShapeOptions* alphaShapeOptions, PolyMesh* pm)
{
    pm->vertices.resize(mesh->vertices.num);
    for (int i=0; i<mesh->vertices.num; i++){
        double *coord = &mesh->vertices.coord[i * 4];
        pm->vertices[i] = new PolyMesh::Vertex(coord[0], coord[1], coord[2], i);
    }
    size_t nNod = 3;
    PolyMesh::Vertex *v[3] = {nullptr, nullptr, nullptr};
    for(size_t i = 0; i < alphaShapeOptions->n_boundaryFacets; i++) {
        for(int j = 0; j < nNod; j++) {
            v[j] = pm->vertices[alphaShapeOptions->boundaryFacets[i * nNod + j]];
        }
        PolyMesh::HalfEdge *he[3];
        for(int j = 0; j < nNod; j++) {
            he[j] = new PolyMesh::HalfEdge(v[j]);
            pm->hedges.push_back(he[j]);
            v[j]->he = he[j];
        }

        PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
        pm->faces.push_back(ff);

        for(int j = 0; j < nNod; j++) {
        he[j]->next = he[(j + 1) % nNod];
        he[j]->prev = he[(j - 1 + nNod) % nNod];
        he[j]->f = ff;
        }
    }

    HalfEdgePtrLessThan compare;
    std::sort(pm->hedges.begin(), pm->hedges.end(), compare);

    HalfEdgePtrEqual equal;
    for(size_t i = 0; i < pm->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = pm->hedges[i];
    PolyMesh::HalfEdge *h1 = pm->hedges[i + 1];
    if(equal(h0, h1)) {
        h0->opposite = h1;
        h1->opposite = h0;
        i++;
    }
    }

}

// extern "C" int polyMesh2hxt(PolyMesh* pm, HXTMesh* mesh, HXTAlphaShapeOptions* alphaShapeOptions, HXTDelaunayOptions* delOptions, std::vector<double>& nodalSizes) 
// {
//     mesh->vertices.num = pm->vertices.size();
//     mesh->vertices.size = mesh->vertices.num;
//     HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord, 4 * pm->vertices.size() * sizeof(double)));
//     HXT_CHECK( hxtAlignedRealloc(&delOptions->nodalSizes->array, pm->vertices.size() * sizeof(double)));
//     for(size_t i=0; i < pm->vertices.size(); i++) {
//         PolyMesh::Vertex* v = pm->vertices[i];
//         mesh->vertices.coord[4 * i + 0] = v->position.x();
//         mesh->vertices.coord[4 * i + 1] = v->position.y();
//         mesh->vertices.coord[4 * i + 2] = v->position.z();
//         mesh->vertices.coord[4 * i + 3] = 0;
//         delOptions->nodalSizes->array[i] = nodalSizes[i];
//     }

//     alphaShapeOptions->n_boundaryFacets = pm->faces.size();
//     mesh->triangles.num = mesh->triangles.size = pm->faces.size();
//     HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.node, mesh->triangles.num * 3 * sizeof(uint32_t) ));
//     HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.color, mesh->triangles.num * sizeof(uint32_t) ));
//     HXT_CHECK( hxtAlignedRealloc(&alphaShapeOptions->boundaryFacets, alphaShapeOptions->n_boundaryFacets * 3 * sizeof(uint32_t) ));

//     for(size_t i = 0; i < pm->faces.size(); i++) {
//         PolyMesh::Face* f = pm->faces[i];
//         alphaShapeOptions->boundaryFacets[3 * i + 0] = f->he->v->data;
//         alphaShapeOptions->boundaryFacets[3 * i + 1] = f->he->next->v->data;
//         alphaShapeOptions->boundaryFacets[3 * i + 2] = f->he->next->next->v->data;
//         mesh->triangles.node[3 * i + 0] = f->he->v->data;
//         mesh->triangles.node[3 * i + 1] = f->he->next->v->data;
//         mesh->triangles.node[3 * i + 2] = f->he->next->next->v->data;
//         mesh->triangles.color[i] = alphaShapeOptions->colorBoundary;
//     }

//     return 0;
// }

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

double face_area_center_normal(PolyMesh::Face* f, SVector3& center, SVector3& normal){
    SVector3 v0 = f->he->v->position;
    SVector3 v1 = f->he->next->v->position;
    SVector3 v2 = f->he->next->next->v->position;
    center = (v0+v1+v2);
    center *= 1./3.;
    SVector3 v01 = v1 - v0;
    SVector3 v02 = v2 - v0;
    SVector3 n = crossprod(v01, v02);
    double area = n.norm()/2.;
    n.normalize();
    normal = n;
    return area;
}

extern "C" void _refineSurfaceTriangulation(HXTMesh** meshPtr, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions) 
{   
    HXTMesh* mesh = *meshPtr;

    // Define polymesh (2D mesh data structure)
    PolyMesh* pm = new PolyMesh;
    hxt2PolyMesh(mesh, alphaShapeOptions, pm);
    
    std::vector<int> onSurface(pm->vertices.size(), 0);
    for (auto f : pm->faces){
        onSurface[f->he->v->data] = 1;
        onSurface[f->he->next->v->data] = 1;
        onSurface[f->he->next->next->v->data] = 1;
    }
    // std::unordered_map<int, double[3]> internalNodes;
    // for (auto v : pm->vertices){
    //     if (onSurface[v->data] == 0){
    //         double coord[3] = {v->position.x(), v->position.y(), v->position.z()};
    //         internalNodes[v->data] = {coord[0], coord[1], coord[2]};
    //     }
    // }
    // TODO : store nodes that are not on surface in different mesh

    // printf("There are initially %lu facets and %d points in the triangulation\n", pm->faces.size(), pm->vertices.size());
    int ptIndex = mesh->vertices.num;
    // print4debug(pm, 0);

    std::vector<double> nodalSizes(mesh->vertices.num);
    for (int i=0; i<mesh->vertices.num; i++) nodalSizes[i] = delOptions->nodalSizes->array[i];

    for (auto he : pm->hedges){
        if (he->opposite == nullptr)
            printf("Error : surface triangulation contains holes ... \n");
    }

    // Step 1: make set of all faces
    double minQuality = alphaShapeOptions->minQuality;
    double _size = 1.;
    double dimensionFactor = 4/sqrt(6);
    double minRadius = alphaShapeOptions->minRadius;

    // Step 2a: coarsen --> decimation algorithm [Schroder1992]
    // print4debug(pm, 0);
    double thresholdDistance = .1*minRadius;
    // int nNodesDeleted = 0;

    /* TODO : instead of the current version of decimate, need a version that only removes nodes based on a size field */

    // nNodesDeleted = pm->decimate(thresholdDistance, NULL, NULL, true);
    // printf("going to decimate \n");
    int nNodesDeleted = 0;
    for (auto v : pm->vertices){
        if (v->he == nullptr) continue;
        // TODO : compute distance to check if node needs to be decimated (based on size field)
        std::vector<PolyMesh::Vertex*> neighs;
        bool onBnd;
        pm->vertexNeighbors(v, &neighs, &onBnd);
        if (onBnd || neighs.empty()) continue;
        double minDist = 1e10;
        PolyMesh::Vertex* closestNeigh = nullptr;
        for (auto n : neighs){
            double dist = norm(n->position - v->position);
            if (dist < minDist) {
                minDist = dist;
                closestNeigh = n;
            }
        }
        double s = 0.5*(nodalSizes[v->data] + nodalSizes[closestNeigh->data]);
        if (minDist < .5*s) {
            int deleted = pm->decimateOneNode(v, thresholdDistance, NULL, NULL);
            nNodesDeleted += deleted;
        }
    }
    // print4debug(pm, 1);
    // if (nNodesDeleted){
    //     printf("decimated some ! \n");
    //     // exit(0);
    // }
    // printf("decimated %d nodes! \n", nNodesDeleted);
    // int nNodesNullHe = 0;
    // for (auto v : pm->vertices){
    //     if (v->he == NULL) nNodesNullHe++;
    // }
    // printf("nNodesNullHe : %d \n", nNodesNullHe);
    
    // exit(0); // TODO : continue!!!!!!

    // for (auto v : pm->vertices){
    //     std::vector<PolyMesh::Face *> faces;
    //     if (v->he == NULL) continue;
    //     int n_faces = pm->vertex_faces(v, faces);
    //     SVector3 sum_normals(0.,0.,0.);
    //     SVector3 sum_positions(0.,0.,0.); 
    //     double sum_areas = 0.;
    //     for (auto f : faces){
    //         SVector3 n_i;
    //         SVector3 c_i;
    //         double A_i = face_area_center_normal(f, c_i, n_i);
    //         sum_normals += n_i*A_i;
    //         sum_positions += c_i*A_i;
    //         sum_areas += A_i;
    //     }
    //     SVector3 average_normal = sum_normals*(1./sum_areas);
    //     average_normal.normalize();
    //     SVector3 x = sum_positions*(1./sum_areas);
    //     double dist = abs(dot((v->position - x), average_normal));
    //     printf("distance : %f \n", dist);
    // }

    // Step 2b: refine the triangulation
    std::set<PolyMesh::HalfEdge *, heCompare> _heSet;
    for(auto he : pm->hedges) {
        if (he->v == nullptr) continue;
        _heSet.insert(he); // USE SET !!!!!!!!!!!!!!!!!!!!
    }
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
        if (l > dimensionFactor*(s0+s1)*0.5){
            polyMeshSplitHalfEdge(pm, heToSplit, midPoint, ptIndex++, newFaces);
            onSurface.push_back(1);
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
    auto tEnd = std::chrono::high_resolution_clock::now();
    duration<double, std::milli> time_total = tEnd - tStart;
    double durTotal = time_total.count();

    // printf("Time spent in sorting : %f \n", 100*timeInSort/durTotal);
    // printf("Surface triangulation done -- added %d new points, there are now %lu faces \n", iter, pm->faces.size());
    delOptions->insertionFirst = mesh->vertices.num;
    
    // Now, we discard the mesh, and create a new one in which the boundaries of the alpha shape are the boundaries of the mesh
    HXTMesh* newMesh;
    hxtMeshCreate(&newMesh);

    // TODO : the nodes that have been decimated get deleted... not ideal ; how to keep in memory which nodes are just internal nodes ? !!!!!!!!!!!!!!!!!!!!!!!!

    std::vector<int> touched(pm->vertices.size(),0);
    // print4debug(pm, 2);
    newMesh->vertices.num = newMesh->vertices.size = pm->vertices.size()-nNodesDeleted;
    hxtAlignedMalloc(&newMesh->vertices.coord, (newMesh->vertices.num) * 4 * sizeof(double));
    hxtAlignedRealloc(&delOptions->nodalSizes->array, newMesh->vertices.num * sizeof(double));
    int vertexIdxHxt = 0;
    std::unordered_map<int, int> Pom2Hxt;
    for (int i=0; i<pm->vertices.size(); i++){
        PolyMesh::Vertex* v = pm->vertices[i];
        int vertexIdxPM = v->data;
        if (onSurface[vertexIdxPM] && v->he == nullptr) {
            // printf("a decimated node... %d\n", i);
            continue;
        }
        double *coord = &newMesh->vertices.coord[vertexIdxHxt * 4];
        coord[0] = v->position.x();
        coord[1] = v->position.y();
        coord[2] = v->position.z();
        coord[3] = 0;
        delOptions->nodalSizes->array[vertexIdxHxt] = nodalSizes[vertexIdxPM];
        Pom2Hxt[vertexIdxPM] = vertexIdxHxt;
        vertexIdxHxt++;
    }
    // int nFaces = 0;
    // for (auto f : pm->faces){
    //     if (f->he == nullptr) continue;
    //     nFaces++;
    // }
    // newMesh->triangles.num = newMesh->triangles.size = pm->faces.size();
    newMesh->triangles.num = newMesh->triangles.size = pm->faces.size();
    hxtAlignedMalloc(&newMesh->triangles.node, (newMesh->triangles.num) * 3 * sizeof(uint32_t));
    hxtAlignedMalloc(&newMesh->triangles.color, (newMesh->triangles.num) * sizeof(uint32_t));
    for (int i=0; i<pm->faces.size(); i++){
        PolyMesh::Face* f = pm->faces[i];
        // if (f->he == nullptr) {
        //     printf("a decimated face... \n");
        //     exit(0);
        //     continue;
        // }
        newMesh->triangles.node[3*i+0] = Pom2Hxt[f->he->v->data];
        newMesh->triangles.node[3*i+1] = Pom2Hxt[f->he->next->v->data];
        newMesh->triangles.node[3*i+2] = Pom2Hxt[f->he->next->next->v->data];
        newMesh->triangles.color[i] = alphaShapeOptions->colorBoundary;
        touched[f->he->v->data] = 1;
        touched[f->he->next->v->data] = 1;
        touched[f->he->next->next->v->data] = 1;
        // printf("triangle PoM: %d, %d, %d \n", f->he->v->data, f->he->next->v->data, f->he->next->next->v->data);
        // printf("triangle HXT: %d, %d, %d \n", newMesh->triangles.node[3*i+0], newMesh->triangles.node[3*i+1], newMesh->triangles.node[3*i+2]);
    }

    HXTTetMeshOptions options = {
        .verbosity=2,
        .stat=1
    };
    hxtTetMesh(newMesh, &options);

    // hxtMeshWriteGmsh(newMesh, "newMeshEmpty.msh");

    std::vector<HXTNodeInfo> nodeInfo;
    for (int i=0; i<pm->vertices.size(); i++){
        // if (touched[i] == 0){
        if (onSurface[i] == 0){
            HXTNodeInfo ni;
            ni.node = Pom2Hxt[i];
            ni.status = HXT_STATUS_TRYAGAIN;
            nodeInfo.push_back(ni);
        }
    }
    int numNewPoints = nodeInfo.size();
    hxtDelaunaySteadyVertices(newMesh, delOptions, &nodeInfo[0], numNewPoints);
    uint64_t nInternalTets = 0;
    for (size_t i=0; i<newMesh->tetrahedra.num; i++){
        if (newMesh->tetrahedra.color[i] != HXT_COLOR_OUT){
            newMesh->tetrahedra.color[i] = alphaShapeOptions->colorIn;
            nInternalTets++;
        }
    }
    alphaShapeOptions->n_tetrahedra = nInternalTets;
    hxtAlignedRealloc(&alphaShapeOptions->tetrahedra, nInternalTets * sizeof(uint64_t));
    int tetIdx = 0;
    for (size_t i=0; i<newMesh->tetrahedra.num; i++){
        if (newMesh->tetrahedra.color[i] == alphaShapeOptions->colorIn){
            alphaShapeOptions->tetrahedra[tetIdx++] = i;
        }
    }

    // hxtMeshWriteGmsh(newMesh, "afterSurfaceRefinement.msh");
    hxtFree(&nodeInfo);
    hxtMeshDelete(&mesh);
    *meshPtr = newMesh;
    // pm->~PolyMesh();
    delete pm;
}
