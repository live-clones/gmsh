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
                                HXTMesh *nmesh)   
{

  //*************************************************************************************
  //*************************************************************************************
  // Create a temp mesh to hold generated vertices
  HXTContext *fcontext;
  hxtContextCreate(&fcontext);
  HXTMesh *fmesh;
  HXT_CHECK(hxtMeshCreate(fcontext,&fmesh));
 
  //*************************************************************************************
  //*************************************************************************************
  // Create edges structure
  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));


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
    HXT_INFO("********** ATTENTION **********");
    HXT_INFO("Mesh does not have lines - starting propagation from a random edge");
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
  if (0) HXT_CHECK(hxtPointGenClassifyDihedralLines(mesh,edges));



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


  //*************************************************************************************
  //*************************************************************************************
  HXT_INFO("");
  HXT_INFO("Initial mesh num of vertices         %d",  mesh->vertices.num);
  HXT_INFO("Initial mesh num of points           %d",  mesh->points.num);
  HXT_INFO("Initial mesh num of lines            %lu",  mesh->lines.num);
  HXT_INFO("Initial mesh num of triangles        %lu",  mesh->triangles.num);
  HXT_INFO("Initial mesh num of tetrahedra       %lu",  mesh->tetrahedra.num);

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

  HXT_INFO("");
  HXT_INFO("Allocated mesh num of vertices       %d", fmesh->vertices.size); 
  HXT_INFO("Allocated mesh num of points         %d", fmesh->vertices.size); 
  HXT_INFO("Allocated mesh num of lines          %lu", fmesh->vertices.size); 

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

  HXT_CHECK(hxtGeneratePointsOnLines(mesh,opt,directions,sizemap,fmesh,pointParent));

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

  if (opt->verbosity == 2) HXT_CHECK(hxtMeshWriteGmsh(fmesh, "FINALMESHlines.msh"));

  HXT_INFO("");
  HXT_INFO("Number of points generated on lines = %d", fmesh->vertices.num);




  //**********************************************************************************************************
  //**********************************************************************************************************
  // GENERATE POINTS ON SURFACES 
  //**********************************************************************************************************
  //**********************************************************************************************************
  
  HXT_CHECK(hxtGeneratePointsOnSurface(opt,mesh,edges,sizemap,directions,parent,fmesh));

  if (opt->verbosity == 2) HXT_CHECK(hxtPointGenExportPointsToPos(fmesh,"pointsSurface.pos"));

  HXT_INFO("");
  HXT_INFO("Number of points generated on surfaces = %d", fmesh->vertices.num);


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
  
  

  if (opt->generateVolumes){
  
    HXT_CHECK(hxtGeneratePointsOnVolumes(mesh,opt,sizemap,directions,parent,fmesh));
  
    if (opt->verbosity == 2) HXT_CHECK(hxtPointGenExportPointsToPos(fmesh,"pointsVolume.pos"));

    HXT_INFO("");
    HXT_INFO("Number of points generated total = %d", fmesh->vertices.num);


  }


  //**********************************************************************************************************
  //**********************************************************************************************************
  // CREATE SURFACE MESH 
  //**********************************************************************************************************
  //**********************************************************************************************************
 
  // Find max length to create an area threshold 
  double maxLength = 0;
  HXT_CHECK(hxtPointGenModelMaxLength(mesh->vertices.coord,mesh->vertices.num,&maxLength));
  opt->areaThreshold = maxLength*maxLength*10e-8;
  

  // Surface remesher
  HXT_CHECK(hxtSurfaceMesh(opt,mesh,edges,parent,fmesh,nmesh));


  //********************************************************
  // A LOT OF DIFFERENT MESH STRUCTURES 
  // -  mesh -> initial mesh 
  // - fmesh -> holds feature points, lines, and generated vertices 
  // - omesh -> holds final mesh triangles and vertices (without lines and points)
 

  if (opt->generateVolumes){
    for (uint32_t i=0; i<fmesh->vertices.num; i++){
      if (parent[i].type != 4) continue;
      nmesh->vertices.coord[4*nmesh->vertices.num+0] = fmesh->vertices.coord[4*i+0];
      nmesh->vertices.coord[4*nmesh->vertices.num+1] = fmesh->vertices.coord[4*i+1];
      nmesh->vertices.coord[4*nmesh->vertices.num+2] = fmesh->vertices.coord[4*i+2];
      nmesh->vertices.num++;
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
  




  /*HXT_CHECK(hxtMeshDelete(&nmesh));*/
  /*HXT_CHECK(hxtContextDelete(&ncontext));*/

  HXT_CHECK(hxtMeshDelete(&fmesh));
  HXT_CHECK(hxtContextDelete(&fcontext));
 
 

  HXT_CHECK(hxtFree(&parent));
  HXT_CHECK(hxtEdgesDelete(&edges));


  return HXT_STATUS_OK; 
}


  
