#include "hxt_tetDelaunay.h"
#include "hxt_alphaUtils.h"
#include "hxt_alphashape.h"
#include "hxt_tetFlag.h"
#include "hxt_tetNodalSize.h"

#include "hxt_alphaShapeForPolymesh.h"

/****************************************************************************************
 ********************************** Alpha shape *****************************************
 ****************************************************************************************/
HXTStatus hxtAlphaShape(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions){
    int numTets = mesh->tetrahedra.num;
    // for (int i=0; i<numTets; i++) printf("tet %d : %d, %d, %d, %d \n", i, mesh->tetrahedra.node[4*i+0], mesh->tetrahedra.node[4*i+1], mesh->tetrahedra.node[4*i+2], mesh->tetrahedra.node[4*i+3]);
    uint64_t* domainTetrahedra = malloc(sizeof(uint64_t)*numTets);
    uint64_t* boundaryFacets = malloc(sizeof(uint64_t)*numTets*2); // for each facet, store element + facet
    double hMean = alphaShapeOptions->hMean;
    double alpha = alphaShapeOptions->alpha;
    printf("here ... \n");
    if ( delOptions->nodalSizes == NULL && hMean <= 0) {
        HXT_ERROR_MSG(HXT_STATUS_FAILED, "Error in alpha shape : nodal sizes need to be defined, or hMean > 0.");
        exit(0);
    }
    int tetCount = 0, facetCount = 0;
    if (numTets==0)
        return HXT_ERROR_MSG(HXT_STATUS_FAILED, "The input mesh should contain tetrahedra.");
    int _touched[numTets];
    double h = hMean;
    for (int i=0; i<numTets; i++) _touched[i] = 0;
    for (uint64_t t=0; t<numTets; t++){
        uint32_t *tet = &mesh->tetrahedra.node[4*t];
        if (tet[3] == HXT_GHOST_VERTEX) continue;
        h = hMean <=0 ? computeTetMeshSize(mesh, delOptions, tet) : hMean;
        double aTest = tetAlphaShape(mesh, tet, h);
        if (tetAlphaShape(mesh, tet, h) < alpha && _touched[t] == 0){
            uint64_t _s[numTets];
            uint64_t _domain[numTets];
            uint64_t _boundary[2*numTets];
            int head = 0, _ssize = 0, _dsize = 0, _bsize = 0; 
            _domain[_dsize++] = t;
            _s[_ssize++] = t;
            _touched[t] = 1;
            while(head < _ssize){
                uint64_t _tet = _s[head++];
                for (int j=0; j<4; j++){ // going over neighbors
                    uint64_t _tetj = mesh->tetrahedra.neigh[4*_tet+j]/4;
                    uint32_t *tetj = &mesh->tetrahedra.node[4*_tetj];
                    if (tetj[3] == HXT_GHOST_VERTEX){
                        _boundary[_bsize++] = _tet;
                        _boundary[_bsize++] = (uint64_t)j;
                    }
                    else if (!_touched[_tetj]){
                        h = hMean <=0 ? computeTetMeshSize(mesh, delOptions, tetj) : hMean;
                        aTest = tetAlphaShape(mesh, tetj, h);
                        if (tetAlphaShape(mesh, tetj, h) < alpha){
                            _s[_ssize++] = _tetj;
                            _domain[_dsize++] = _tetj;
                            _touched[_tetj] = 1;
                        }
                        else {
                            _boundary[_bsize++] = _tet;
                            _boundary[_bsize++] = (uint64_t)j;
                        }
                    }
                }
            }
            for (int i=0; i<_dsize; i++){
                domainTetrahedra[i+tetCount] = _domain[i];
            }
            for (int i=0; i<_bsize; i++){
                boundaryFacets[i+facetCount] = _boundary[i];
            }
            tetCount  += _dsize;
            facetCount += _bsize;
        }
    }
    alphaShapeOptions->n_tetrahedra = tetCount;
    printf("finished loop \n");
    // color the tets inside the alpha shape
    for (int i=0; i<numTets; i++) {
        if (mesh->tetrahedra.node[4*i+3] == HXT_GHOST_VERTEX) 
            mesh->tetrahedra.color[i] = HXT_COLOR_OUT;
        else 
            mesh->tetrahedra.color[i] = alphaShapeOptions->colorOut;
    }
    printf("after if \n");
    HXT_CHECK( hxtMalloc(&alphaShapeOptions->tetrahedra, (tetCount)*sizeof(uint64_t)) );
    // HXT_CHECK( hxtAlignedRealloc(&alphaShapeOptions->tetrahedra, (tetCount)*sizeof(uint64_t)) );
    printf("realloc'd \n");
    for (int i=0; i<tetCount; i++){
        mesh->tetrahedra.color[domainTetrahedra[i]] = alphaShapeOptions->colorIn;
        alphaShapeOptions->tetrahedra[i] = domainTetrahedra[i];
    }
    printf("added tets \n");
    // add the facets to the mesh
    alphaShapeOptions->n_boundaryFacets = facetCount/2;
    // HXT_CHECK( hxtAlignedRealloc(&alphaShapeOptions->boundaryFacets, 3*alphaShapeOptions->n_boundaryFacets*sizeof(uint32_t)));
    HXT_CHECK( hxtMalloc(&alphaShapeOptions->boundaryFacets, 3*alphaShapeOptions->n_boundaryFacets*sizeof(uint32_t)));
    for (uint64_t i=0; i<alphaShapeOptions->n_boundaryFacets; i++){
        alphaShapeOptions->boundaryFacets[3*i+0] = mesh->tetrahedra.node[4*boundaryFacets[2*i]+getNode0FromFacet(boundaryFacets[2*i+1])];
        alphaShapeOptions->boundaryFacets[3*i+1] = mesh->tetrahedra.node[4*boundaryFacets[2*i]+getNode1FromFacet(boundaryFacets[2*i+1])];
        alphaShapeOptions->boundaryFacets[3*i+2] = mesh->tetrahedra.node[4*boundaryFacets[2*i]+getNode2FromFacet(boundaryFacets[2*i+1])];
    }
    free(domainTetrahedra);
    free(boundaryFacets);
    return HXT_STATUS_OK;
}


/****************************************************************************************
 **************** Refine surface triangulation of alpha shape ***************************
 ****************************************************************************************/
int hxtRefineSurfaceTriangulation(HXTMesh** mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions){
    _refineSurfaceTriangulation(mesh, delOptions, alphaShapeOptions);
    return 0;
}


/****************************************************************************************
 ***************** Refine tets in alpha shape *******************************************
 ****************************************************************************************/
int hxtAlphaShapeNodeInsertion(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions){
    
    for(int iter=0; iter<42; iter++) { // An arbitrary number of maximum refinements ? 

        // Allocations 
        delOptions->insertionFirst = mesh->vertices.num;
        uint32_t nTetrahedra = alphaShapeOptions->n_tetrahedra; // potentially this many points will be inserted at this step
        uint64_t* ptToTet;
        HXT_CHECK( hxtAlignedMalloc(&ptToTet, sizeof(uint64_t)*nTetrahedra) );
        double* newVertices;
        HXT_CHECK( hxtAlignedMalloc(&newVertices, sizeof(double)*4*nTetrahedra) );

        uint32_t ptIndex = 0;
        uint32_t numNewPts = 0;

        for(uint64_t t=0; t<nTetrahedra; t++) {

            // TODO : issue with slivers --> manage them differently ... 
            
            uint64_t tet = alphaShapeOptions->tetrahedra[t];
            
            if (mesh->tetrahedra.color[tet] != alphaShapeOptions->colorIn){
                printf("hold on...\n");
                exit(0);
            }

            double p[4][4], s[4];
            getTetCoordAndNodalSize(mesh, delOptions->nodalSizes->array, tet, p, s);

            // Using the best center approach of hxt
            // double bestC[4];
            // if(getBestCenter(p, s, bestC, delOptions->nodalSizes)){
            //     // printf("get best center removes the point\n");
            //     // printf("best center :      %f, %f, %f \n", bestC[0], bestC[1], bestC[2]);
            //     continue;
            // }
            // for (int i=0; i<4; i++) newVertices[4*ptIndex+i] = bestC[i];
            
            // Using the "classical" circumcenter approach
            double c[3], R, xi, eta, zeta;  
            R = tetrahedron_circumcenter(p[0], p[1], p[2], p[3], c, &xi, &eta, &zeta);
            if (R <= 0.) continue;
            
            // Test size and quality
            double s_mean = (s[0]+s[1]+s[2]+s[3])/4;
            if (R/s_mean < 1) continue; // it is small enough 
            // Find in which tet is the newly spawned point
            uint64_t pt2Tet = HXT_COLOR_OUT;
            if (pointInTetrahedron(p[0], p[1], p[2], p[3], c)==1){
                pt2Tet = tet;
            }
            else { 
                // If the point is not in its own tet, check in neighbors and neighs of neighs. (not perfect...)
                pt2Tet = findPointInNeighbouringTets(mesh, tet, c);
            }
            if (pt2Tet == -1 || mesh->tetrahedra.color[pt2Tet] != alphaShapeOptions->colorIn) { 
                // it is not in its neighbors, or it is outside of the alpha shape
                continue;
            }
            double pNeigh[4][4], sNeigh[4];
            getTetCoordAndNodalSize(mesh, delOptions->nodalSizes->array, pt2Tet, pNeigh, sNeigh);
            newVertices[4*ptIndex+3] = 0.;
            for (int i=0; i<3; i++) newVertices[4*ptIndex+i] = c[i];
            for (int i=0; i<4; i++) newVertices[4*ptIndex+3] += sNeigh[i]/4;
            ptToTet[ptIndex] = pt2Tet;
            
            numNewPts++;
            ptIndex++;
        }
        HXTStatus status;
        uint32_t oldNumVerticesInMesh = delOptions->numVerticesInMesh;

        HXT_INFO_COND(delOptions->verbosity>1, "Refinement adds %u points from %" HXTu64 " tetrahedra, of which %d are in the alpha shape", numNewPts, mesh->tetrahedra.num, alphaShapeOptions->n_tetrahedra);
        mesh->vertices.num += numNewPts;

        if(mesh->vertices.num > mesh->vertices.size){
            status=hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double)*4*mesh->vertices.num);
            if(status==HXT_STATUS_OK){
                status=hxtAlignedRealloc(&delOptions->nodalSizes->array, sizeof(double)*mesh->vertices.num);
                mesh->vertices.size = mesh->vertices.num;
            }
        }

        uint32_t v = delOptions->insertionFirst;

        if(delOptions->nodalSizes->callback!=NULL) {
            HXT_CHECK( delOptions->nodalSizes->callback(newVertices, NULL, numNewPts, delOptions->nodalSizes->userData) );
        }

        HXTNodeInfo* nodeInfo;
        if(status==HXT_STATUS_OK){
            HXT_CHECK( hxtAlignedMalloc(&nodeInfo, sizeof(HXTNodeInfo)*numNewPts));
            for (uint64_t i=0; i<numNewPts; i++){
                if(newVertices[4*i + 3] <= 0.0) continue; // Normally this doesn't happen ...
                mesh->vertices.coord[v*4+0] = newVertices[4*i + 0];
                mesh->vertices.coord[v*4+1] = newVertices[4*i + 1];
                mesh->vertices.coord[v*4+2] = newVertices[4*i + 2];
                delOptions->nodalSizes->array[v] = newVertices[4*i + 3];
                nodeInfo[i].node = v;
                nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
                v++;
            }
        }
        status = hxtAlignedFree(&ptToTet);

        if(status!=HXT_STATUS_OK){
            HXT_TRACE(status);
            return status;
        }
        HXT_CHECK(hxtAlignedFree(&newVertices));
        if(delOptions->insertionFirst == mesh->vertices.num)
            break;


        HXT_CHECK(hxtDelaunaySteadyVertices(mesh, delOptions, nodeInfo, numNewPts));
        hxtFree(&nodeInfo);
        
        uint64_t numNewTets = 0;
        for (uint64_t j=0; j<mesh->tetrahedra.num; j++) 
            if (mesh->tetrahedra.color[j] == alphaShapeOptions->colorIn) numNewTets++;
        
        alphaShapeOptions->n_tetrahedra = numNewTets;
        hxtAlignedRealloc(&alphaShapeOptions->tetrahedra, sizeof(uint64_t)*numNewTets);
        uint64_t tetIndex = 0;
        for (uint64_t j=0; j<mesh->tetrahedra.num; j++){
            if (mesh->tetrahedra.color[j] == alphaShapeOptions->colorIn){
                alphaShapeOptions->tetrahedra[tetIndex++] = j;
            }
        }

        if (delOptions->numVerticesInMesh == oldNumVerticesInMesh) break;
    }

    return HXT_STATUS_OK;

}


// int hxtRefineTetrahedraInAlphaShape(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions){
    
//     int maxThreads = omp_get_max_threads();
//     // printf("max threadssss : %d \n", maxThreads);
//     uint64_t* startTet; // see balanceRefineWork
//     HXT_CHECK( hxtMalloc(&startTet, (maxThreads+1)*sizeof(size_t)) );

//     uint32_t* startPt; // see balanceRefineWork
//     HXT_CHECK( hxtMalloc(&startPt, (maxThreads+1)*sizeof(uint32_t)) );

//     for(int iter=0; iter<42; iter++) {

//         // Allocations 
//         delOptions->insertionFirst = mesh->vertices.num;
//         HXT_CHECK( balanceRefineWorkInAlphaShape(mesh, alphaShapeOptions, startPt, startTet, maxThreads) );

//         uint32_t totNewPts = startPt[maxThreads];
//         // printf("tot new points : %d \n", totNewPts);
//         uint64_t* ptToTet;
//         HXT_CHECK( hxtAlignedMalloc(&ptToTet, sizeof(uint64_t)*startPt[maxThreads]) );

//         double* newVertices;
//         HXT_CHECK( hxtAlignedMalloc(&newVertices, sizeof(double)*4*totNewPts) );

//         #pragma omp parallel
//         {
//         int threadID = omp_get_thread_num();
//         uint32_t ptIndex = startPt[threadID];

//         for(uint64_t tet=startTet[threadID]; tet<startTet[threadID+1]; tet++) {
//             // printf("tet number : %d \n", tet);
//             if (getProcessedFlag(mesh, tet) || mesh->tetrahedra.color[tet] != alphaShapeOptions->colorIn)
//                 continue;

//             setProcessedFlag(mesh, tet); // we do not need to refine that tetrahedron anymore

//             double p[4][4];
//             double s[4];
//             getTetCoordAndNodalSize(mesh, delOptions->nodalSizes->array, tet, p, s);

//             // TODO: do a SIMD getBestCenter function if it gets slow
//             // if(getBestCenter(p, s, &newVertices[4*ptIndex], delOptions->nodalSizes) &&
//             //                     delOptions->nodalSizes->callback==NULL)
//             //     newVertices[4*ptIndex+3] = -DBL_MAX;
            
//             double C[3], xi, eta, zeta;
//             tetrahedron_circumcenter(p[0], p[1], p[2], p[3], &newVertices[4*ptIndex], &xi, &eta, &zeta);
//             newVertices[4*ptIndex+3]= 0;
//             for (int i=0; i<4; i++) newVertices[4*ptIndex+3] += s[i]/4;

//             // printf("tet circumcenter : %f, %f, %f; size : %f \n", newVertices[4*ptIndex+0], newVertices[4*ptIndex+1], newVertices[4*ptIndex+2], newVertices[4*ptIndex+3]);

//         #ifndef NDEBUG
//             if(insphere(p[0], p[1], p[2], p[3], &newVertices[4*ptIndex])>=0.0)
//                 HXT_WARNING("new point is not in the circumsphere of the tet that spawned it");
//         #endif
//             ptToTet[ptIndex] = tet;
//             ptIndex++;
//         }

//         }

//         HXTStatus status;
//         // third step (filter): verify if they are not too close from the tet corners
//         #pragma omp parallel
//         {
//         int threadID = omp_get_thread_num();

//         // we don't really need startPt and startTet anymore because points have been created
//         // we recycle startPt to count how many point will be kept for each thread after
//         // the filtering
//         startPt[threadID] = 0;

//         #pragma omp for schedule(static)
//         for(size_t i=0; i<totNewPts; i++) {
//             if(newVertices[4*i + 3] <= 0.0)
//             continue;

//             uint64_t tetID = ptToTet[i];
//             double p[4][4];
//             double s[4];
//             getTetCoordAndNodalSize(mesh, delOptions->nodalSizes->array, tetID, p, s);

//             double* vtaCoord = &newVertices[4*i];
//             double vtaSize = newVertices[4*i + 3];

//             if(isTooClose(s[0], vtaSize, squareDist(p[0], vtaCoord), delOptions->nodalSizes) ||
//                 isTooClose(s[1], vtaSize, squareDist(p[1], vtaCoord), delOptions->nodalSizes) ||
//                 isTooClose(s[2], vtaSize, squareDist(p[2], vtaCoord), delOptions->nodalSizes) ||
//                 isTooClose(s[3], vtaSize, squareDist(p[3], vtaCoord), delOptions->nodalSizes)){
//                 newVertices[4*i + 3] = -DBL_MAX;
//             }
//             else {
//                 startPt[threadID]++;
//             }
//         }

//         #pragma omp barrier
//         #pragma omp single
//         {
//         int nthreads = omp_get_num_threads();
//         uint32_t sum = 0;
//         for (int t=0; t<nthreads; t++) {
//             uint32_t tsum = sum + startPt[t];
//             startPt[t] = sum;
//             sum = tsum;
//         }

//         startPt[maxThreads] = sum;

//         HXT_INFO_COND(delOptions->verbosity>1, "Refinement adds %u points from %" HXTu64 " tetrahedra", sum, mesh->tetrahedra.num);
//         exit(0);
//         mesh->vertices.num += sum;

//         status = hxtAlignedFree(&ptToTet);
//         if(mesh->vertices.num > mesh->vertices.size){
//             status=hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double)*4*mesh->vertices.num);
//             if(status==HXT_STATUS_OK){
//                 status=hxtAlignedRealloc(&delOptions->nodalSizes->array, sizeof(double)*mesh->vertices.num);
//                 mesh->vertices.size = mesh->vertices.num;
//             }
//         }
//         }
//         size_t v = delOptions->insertionFirst + startPt[threadID];

//         if(status==HXT_STATUS_OK){
//             #pragma omp for schedule(static)
//             for (uint64_t i=0; i<totNewPts; i++){
//                 if(newVertices[4*i + 3] <= 0.0)
//                 continue;
//                 mesh->vertices.coord[v*4  ] = newVertices[4*i + 0];
//                 mesh->vertices.coord[v*4+1] = newVertices[4*i + 1];
//                 mesh->vertices.coord[v*4+2] = newVertices[4*i + 2];
//                 delOptions->nodalSizes->array[v] = newVertices[4*i + 3];
//                 v++;
//             }
//         }
//         }

//         if(status!=HXT_STATUS_OK){
//             HXT_TRACE(status);
//             return status;
//         }

//         HXT_CHECK(hxtAlignedFree(&newVertices));

//         if(delOptions->insertionFirst == mesh->vertices.num)
//             break;

//         delOptions->partitionability = 1.0 - pow(0.5, iter);
//         uint32_t oldNumVerticesInMesh = delOptions->numVerticesInMesh;

//         HXT_CHECK(hxtDelaunay(mesh, delOptions));

//         if (delOptions->numVerticesInMesh == oldNumVerticesInMesh) break;
//     }

//     HXT_CHECK( hxtFree(&startTet) );
//     HXT_CHECK( hxtFree(&startPt) );

//     return HXT_STATUS_OK;

// }