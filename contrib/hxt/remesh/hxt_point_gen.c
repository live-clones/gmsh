#include "hxt_point_gen.h"
#include "hxt_point_gen_1d.h"
#include "hxt_point_gen_2d.h"
#include "hxt_point_gen_3d.h"
#include "hxt_surface_mesh.h"
#include "hxt_point_gen_realloc.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_io.h"
#include "hxt_point_gen_optim.h"

#include "hxt_bbox.h"
#include "hxt_edge.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"

HXTStatus hxtGeneratePointsMain(HXTMesh *mesh, 
                                HXTPointGenOptions *opt, 
                                double *sizemap, 
                                const double *directions,
                                HXTMesh *fmesh)   
{
  //*************************************************************************************
  //*************************************************************************************
  // Create edges structure
  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));


  //*************************************************************************************
  //*************************************************************************************
  // Find max length to create an area threshold 
  double maxLength = 0;
  HXT_CHECK(hxtPointGenModelMaxLength(mesh->vertices.coord,mesh->vertices.num,&maxLength));
  printf("Max Length = %f \n", maxLength);
  opt->areaThreshold = maxLength*maxLength*10e-8;
  printf("Max Area   = %e \n", opt->areaThreshold);
  

  //*************************************************************************************
  //*************************************************************************************
  if (0) HXT_CHECK(hxtCheckZeroAreaTriangles(mesh,"FINALMESHtriangleWithZeroArea.msh"));


  //*************************************************************************************
  //*************************************************************************************
  // Sizing from input mesh 
  if (0){
    HXT_CHECK(hxtPointGenGetSizesInputMesh(edges,3.0,sizemap));
    HXT_CHECK(hxtPointGenSizemapSmoothing(edges,1.5,sizemap));
    HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,sizemap,"sizesInput.msh"));
  }
  
  //*************************************************************************************
  //*************************************************************************************
  // Sizing from curvature
  if(0){
    HXT_CHECK(hxtPointGenGetSizesCurvature(edges,30,0.8,0.1,sizemap));
    //HXT_CHECK(hxtPointGenSizemapSmoothing(edges,1.5,sizemap));
    HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,sizemap,"sizesInput.msh"));
  }

  //*************************************************************************************
  //*************************************************************************************
  // If mesh does not have lines start propagation from a random edge
  if (mesh->lines.num == 0){
    printf("ATTENTION !!!!!!!!!!!!!!!!! \n");
    printf("Mesh does not have lines - starting propagation from a random edge");
    // Create edges structure
    hxtLinesReserve(mesh,2);
    mesh->lines.colors[0] = 0;
    mesh->lines.node[0] = edges->node[0];
    mesh->lines.node[1] = edges->node[1];
    mesh->lines.num++;

    for (uint64_t i=0; i<mesh->triangles.num; i++){
      mesh->triangles.colors[i] = 1;
    }
  }

  //*************************************************************************************
  //*************************************************************************************
  // Extract mesh lines based on dihedral angle 
  // TODO rewrite this function
  if (0) HXT_CHECK(hxtPointGenDihedralLines(mesh,edges));




  //*************************************************************************************
  //*************************************************************************************
  // Boundary vertex connectivity 
  uint32_t *vert2vert;
  HXT_CHECK(hxtMalloc(&vert2vert, 2*mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<2*mesh->vertices.num; i++) vert2vert[i] = UINT32_MAX;

  for (uint64_t i=0; i<mesh->lines.num; i++){
    uint32_t v0 = mesh->lines.node[2*i+0];
    uint32_t v1 = mesh->lines.node[2*i+1];
    vert2vert[2*v0+1] = v1;
    vert2vert[2*v1+0] = v0;
  }
  HXT_CHECK(hxtFree(&vert2vert));


  printf("\n");
  printf("   Initial mesh num of vertices:  %d \n",  mesh->vertices.num);
  printf("    Initial mesh num of corners:  %d \n",  mesh->points.num);
  printf("      Initial mesh num of lines:  %lu \n", mesh->lines.num);
  printf("\n");

  // Estimate number of generated vertices 
  uint32_t estNumVertices = 0;
  HXT_CHECK(hxtEstimateNumOfVerticesWithMesh(mesh,sizemap,&estNumVertices));
  if (estNumVertices < mesh->lines.num) estNumVertices += mesh->lines.num;
  estNumVertices = 10000000; // TODO good estimation ? 

  // Allocate final mesh vertices
  HXT_CHECK(hxtVerticesReserve(fmesh, estNumVertices));

  // Allocate final mesh 1-d point elements (corners)
  if (mesh->points.num != 0){
    HXT_CHECK(hxtPointsReserve(fmesh,mesh->points.num));
  }
  else{
    HXT_CHECK(hxtPointsReserve(fmesh,estNumVertices)); // TODO this is way too big - reallocate down
  }

  // Allocate final mesh lines
  uint64_t estNumLines = estNumVertices; // TODO that is a big number for mesh lines! - reallocate down
  HXT_CHECK(hxtLinesReserve(fmesh, estNumLines));

  printf("     Final mesh num of vertices:  %d \n",  fmesh->vertices.num);
  printf(" Allocated mesh num of vertices:  %d \n",  fmesh->vertices.size);
  printf("        Final mesh num of lines:  %lu \n", fmesh->lines.num);
  printf("    Allocated mesh num of lines:  %lu \n", fmesh->lines.size);
  printf("        Final mesh num of points:  %d \n", fmesh->points.num);
  printf("    Allocated mesh num of points:  %d \n", fmesh->points.size);
  printf("\n");

  //**********************************************************************************************************
  //**********************************************************************************************************
  // GENERATE POINTS ON LINES 
  //**********************************************************************************************************
  //**********************************************************************************************************

  // Array to store point "parent" element 
  // - for corner points gives id of corner vertex of initial mesh
  // - for points on lines gives the id of line
  uint64_t *pointParent = NULL;
  HXT_CHECK(hxtMalloc(&pointParent,estNumVertices*sizeof(uint64_t)));
  for (uint32_t i=0; i<estNumVertices; i++) pointParent[i] = UINT64_MAX;

  HXT_CHECK(hxtGeneratePointsOnLines(mesh,directions,sizemap,fmesh,pointParent));

  // Check if there is even number of points generated on lines 
  // TODO 
  if (fmesh->lines.num%2 != 0){
    printf("\n\nContinue with odd number of points? y/n \n\n");
    char ch = getchar();
    getchar();
    if ( ch == 'n') return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Number of points on lines not even");
  }

  // Create structure for parent elements of generated points 
  HXTPointGenParent *parent;
  HXT_CHECK(hxtMalloc(&parent, estNumVertices*sizeof(HXTPointGenParent)));
  for (uint32_t i=0; i<estNumVertices; i++) parent[i].type = UINT8_MAX;
  for (uint32_t i=0; i<estNumVertices; i++) parent[i].id = UINT64_MAX;

  // Fill point gen parent struct with lines 
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (pointParent[i] == UINT64_MAX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Vertex %d does not have parent element",i);
    }
    parent[i].type = 1;
    parent[i].id = pointParent[i];
  }

  // Fill point gen parent struct with corner points 
  for (uint32_t i=0; i<fmesh->points.num; i++){
    uint32_t nodeID = fmesh->points.node[i];
    if (pointParent[nodeID] == UINT64_MAX){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Vertex %d does not have parent element",i);
    }
    parent[nodeID].type = 15;
    parent[nodeID].id = pointParent[nodeID];
  }
  HXT_CHECK(hxtFree(&pointParent));
  // Checking correct number of 1d point elements (i.e. "corners")
  // TODO delete
  uint32_t countCorners = 0;
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 15) countCorners++;
  }
  if (countCorners != fmesh->points.num) return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Corner problem");

  HXT_CHECK(hxtMeshWriteGmsh(fmesh, "FINALMESHlines.msh"));


  //**********************************************************************************************************
  //**********************************************************************************************************
  // GENERATE POINTS ON SURFACES 
  //**********************************************************************************************************
  //**********************************************************************************************************
  
  HXT_CHECK(hxtGeneratePointsOnSurface(opt,mesh,edges,sizemap,directions,parent,fmesh));

  // TODO just for checking, delete
  // Check if parent elements are correct
  double tol = 10e-7;
  double dist,t,closePt[3];
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 1){
    
      uint64_t parentLine = parent[i].id;
      double *p0 = mesh->vertices.coord + 4*mesh->lines.node[2*parentLine+0];
      double *p1 = mesh->vertices.coord + 4*mesh->lines.node[2*parentLine+1];
      double *pp = fmesh->vertices.coord + 4*i;
      HXT_CHECK(hxtSignedDistancePointEdge(p0,p1,pp,&dist,&t,closePt));
      if (fabs(dist)>tol) 
        return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Line parent wrong for %d, dist = %e",i,dist);
    }
    else if (parent[i].type == 15){
      uint32_t parentPoint = parent[i].id;
      double *p0 = mesh->vertices.coord + 4*parentPoint;
      double *p1 = fmesh->vertices.coord + 4*i;
      dist = distance(p0,p1);
      if (fabs(dist)>tol) 
        return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Point parent wrong for %d, dist = %e",i,dist);
    }
    else if (parent[i].type == 2){
      uint32_t parentTriangle = parent[i].id;
      double *p0 = mesh->vertices.coord + 4*mesh->triangles.node[3*parentTriangle+0];
      double *p1 = mesh->vertices.coord + 4*mesh->triangles.node[3*parentTriangle+1];
      double *p2 = mesh->vertices.coord + 4*mesh->triangles.node[3*parentTriangle+2];
      double *pp = fmesh->vertices.coord + 4*i;
      int inside = 0;
      HXT_CHECK(hxtSignedDistancePointTriangle(p0,p1,p2,pp,&dist,&inside,closePt));
      if (fabs(dist)>tol)
        return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Triangle parent wrong for %d, dist = %e",i,dist);
    }
  }


  //**********************************************************************************************************
  //**********************************************************************************************************
  // GENERATE POINTS ON VOLUMES 
  //**********************************************************************************************************
  //**********************************************************************************************************
  
  uint32_t numPointsOnSurfaces = fmesh->vertices.num;
  HXT_INFO("Number of points generated on surfaces = %d \n", numPointsOnSurfaces);
  
  HXTContext *ncontext;
  hxtContextCreate(&ncontext);
  HXTMesh *nmesh;
  HXT_CHECK(hxtMeshCreate(ncontext, &nmesh));

  HXT_CHECK(hxtPointsReserve(nmesh,fmesh->points.num));
  HXT_CHECK(hxtLinesReserve(nmesh,fmesh->lines.num));
  HXT_CHECK(hxtVerticesReserve(nmesh, estNumVertices));
  HXT_CHECK(hxtTrianglesReserve(nmesh,fmesh->triangles.num));

  if (opt->generateVolumes){
    nmesh->points.num = fmesh->points.num;
    nmesh->lines.num = fmesh->lines.num;
    nmesh->vertices.num = fmesh->vertices.num;
    nmesh->triangles.num = fmesh->triangles.num;
  
    // Transfer points to temp mesh
    for (uint32_t i=0; i<fmesh->points.num; i++) nmesh->points.node[i] = fmesh->points.node[i];
  
    // Transfer lines to temp mesh
    for (uint32_t i=0; i<fmesh->lines.num; i++){
      nmesh->lines.node[2*i+0] = fmesh->lines.node[2*i+0];
      nmesh->lines.node[2*i+1] = fmesh->lines.node[2*i+1];
      nmesh->lines.colors[i] = fmesh->lines.colors[i];
    }
  
    // Transfer triangles to temp mesh
    for (uint64_t i=0; i<fmesh->triangles.num; i++){
      nmesh->triangles.node[3*i+0] = fmesh->triangles.node[3*i+0];
      nmesh->triangles.node[3*i+1] = fmesh->triangles.node[3*i+1];
      nmesh->triangles.node[3*i+2] = fmesh->triangles.node[3*i+2];
      nmesh->triangles.colors[i] = fmesh->triangles.colors[i];
    }
    
    // Store vertices of initial mesh to temp mesh
    for (uint32_t i=0; i<fmesh->vertices.num; i++){
      nmesh->vertices.coord[4*i+0] = fmesh->vertices.coord[4*i+0];
      nmesh->vertices.coord[4*i+1] = fmesh->vertices.coord[4*i+1];
      nmesh->vertices.coord[4*i+2] = fmesh->vertices.coord[4*i+2];
    }
  
  
    HXT_CHECK(hxtGeneratePointsOnVolumes(mesh,sizemap,directions,parent,nmesh));
  
    HXT_CHECK(hxtMeshWriteGmsh(nmesh,"FINALMESHvolume.msh"));
    HXT_CHECK(hxtPointGenExportPointsToPos(nmesh,"pointsVolume.pos"));
  }


  //**********************************************************************************************************
  //**********************************************************************************************************
  // CREATE SURFACE MESH 
  //**********************************************************************************************************
  //**********************************************************************************************************

  HXTContext *ocontext;
  hxtContextCreate(&ocontext);
  HXTMesh *omesh;
  HXT_CHECK(hxtMeshCreate(ocontext,&omesh));
 
  HXT_CHECK(hxtSurfaceMesh(opt,mesh,edges,parent,fmesh,omesh));
 
  if(opt->generateVolumes){
    int countB = 0;
    int countI = 0;
    for (uint32_t i=0; i<nmesh->vertices.num; i++){
      if (parent[i].type != 4) countB++;
      if (parent[i].type == 4) countI++;
    } 
    HXT_CHECK(hxtVerticesReserve(omesh, nmesh->vertices.size));
    for (uint32_t i=0; i<nmesh->vertices.num; i++){
      if (parent[i].type == 4){
        omesh->vertices.coord[4*omesh->vertices.num+0] = nmesh->vertices.coord[4*i+0];
        omesh->vertices.coord[4*omesh->vertices.num+1] = nmesh->vertices.coord[4*i+1];
        omesh->vertices.coord[4*omesh->vertices.num+2] = nmesh->vertices.coord[4*i+2];
        omesh->vertices.num++;
      }
    }
  }



  //**********************************************************************************************************
  //**********************************************************************************************************
  // TEST 20/11/2019 
  // QUALITY COMPUTATION BASED ON DISTANCE FROM CIRCUMCIRCLE CENTER
  //
  //**********************************************************************************************************
  //**********************************************************************************************************
  if(0) HXT_CHECK(hxtPointGenOptim(mesh,directions,sizemap));
  



  HXT_CHECK(hxtMeshWriteGmsh(omesh, "FINALMESHcollapsed.msh"));
  HXT_CHECK(hxtMeshDelete(&omesh));
  HXT_CHECK(hxtContextDelete(&ocontext));
 

  HXT_CHECK(hxtFree(&parent));
  HXT_CHECK(hxtEdgesDelete(&edges));

  HXT_CHECK(hxtMeshDelete(&nmesh));
  HXT_CHECK(hxtContextDelete(&ncontext));

  return HXT_STATUS_OK; 
}


  
