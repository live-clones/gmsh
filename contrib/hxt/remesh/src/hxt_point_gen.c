#include <time.h>

#include "hxt_point_gen.h"
#include "hxt_point_gen_1d.h"
#include "hxt_point_gen_2d.h"
#include "hxt_point_gen_3d.h"
#include "hxt_surface_mesh.h"
#include "hxt_point_gen_realloc.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_io.h"
#include "hxt_surface_mesh_quad.h"
#include "hxt_surface_mesh_processing.h"

#include "hxt_bbox.h"
#include "hxt_edge.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"

HXTStatus hxtGeneratePointsMain(HXTMesh *mesh, 
                                HXTPointGenOptions *opt, 
                                double *sizemap, 
                                double *directions,
                                HXTMesh *nmesh)   
{


  clock_t time_start = clock();

  //*************************************************************************************
  //*************************************************************************************
  // Create a temp mesh to hold generated vertices
  HXTMesh *fmesh;
  HXT_CHECK(hxtMeshCreate(&fmesh));
 
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
  // TODO 
  if (0){
    HXT_CHECK(hxtPointGenGetSizesInputMesh(edges,1.0,sizemap));
    HXT_CHECK(hxtPointGenSizemapSmoothing(edges,1.5,sizemap));
    HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,sizemap,"sizesInput.msh"));
  }
  
  //*************************************************************************************
  //*************************************************************************************
  // Sizing from curvature
  // TODO 
  if(0){
    HXT_CHECK(hxtPointGenGetSizesCurvature(edges,100,0.8,0.1,sizemap));
    //HXT_CHECK(hxtPointGenSizemapSmoothing(edges,1.5,sizemap));
    HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,sizemap,"sizesCurvature.msh"));
  }



  //*************************************************************************************
  //*************************************************************************************
  // Extract mesh lines based on dihedral angle 
  // TODO rewrite this function
  if (0) HXT_CHECK(hxtPointGenClassifyDihedralLines(mesh,edges));



  //*************************************************************************************
  //*************************************************************************************
  // Boundary vertex connectivity 
  // TODO not used for now 
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
  // Create and allocate 
  //*************************************************************************************
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"Initial mesh num of vertices         %d",  mesh->vertices.num);
  HXT_INFO_COND(opt->verbosity>=1,"Initial mesh num of points           %d",  mesh->points.num);
  HXT_INFO_COND(opt->verbosity>=1,"Initial mesh num of lines            %lu",  mesh->lines.num);
  HXT_INFO_COND(opt->verbosity>=1,"Initial mesh num of triangles        %lu",  mesh->triangles.num);
  HXT_INFO_COND(opt->verbosity>=1,"Initial mesh num of quads            %lu",  mesh->quads.num);
  HXT_INFO_COND(opt->verbosity>=1,"Initial mesh num of tetrahedra       %lu",  mesh->tetrahedra.num);

  // Estimate number of generated vertices 
  uint32_t estNumVertices = 0;
  HXT_CHECK(hxtEstimateNumOfVerticesWithMesh(mesh,sizemap,&estNumVertices));
  if (estNumVertices < mesh->lines.num) estNumVertices += mesh->lines.num;
  estNumVertices = 10000000; // TODO good estimation ? 

  // Allocate final mesh vertices
  HXT_CHECK(hxtVerticesReserve(fmesh, estNumVertices));

  // Allocate final mesh 1-d point elements (corners)
  // TODO this is way too big - reallocate down
  if (mesh->points.num != 0){
    HXT_CHECK(hxtPointsReserve(fmesh,estNumVertices));
  }
  else{
    HXT_CHECK(hxtPointsReserve(fmesh,estNumVertices));   
  }

  // Allocate final mesh lines
  uint64_t estNumLines = estNumVertices; // TODO that is a big number for mesh lines! - reallocate down
  HXT_CHECK(hxtLinesReserve(fmesh, estNumLines));

  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"Allocated mesh num of vertices       %d",  fmesh->vertices.size); 
  HXT_INFO_COND(opt->verbosity>=1,"Allocated mesh num of points         %d",  fmesh->points.size); 
  HXT_INFO_COND(opt->verbosity>=1,"Allocated mesh num of lines          %lu", fmesh->lines.size); 
  
  // Create structure for parent elements of generated points 
  HXTPointGenParent *parent;
  HXT_CHECK(hxtMalloc(&parent, estNumVertices*sizeof(HXTPointGenParent)));
  for (uint32_t i=0; i<estNumVertices; i++) parent[i].type = UINT8_MAX;
  for (uint32_t i=0; i<estNumVertices; i++) parent[i].id = UINT64_MAX;


  //*************************************************************************************
  //*************************************************************************************
  // If mesh does not have lines start propagation from a random edge
  // TODO 
/*  if (mesh->lines.num == 0 && opt->generateSurfaces){*/
    /*HXT_INFO_COND(opt->verbosity>=1,"********** ATTENTION **********");*/
    /*HXT_INFO_COND(opt->verbosity>=1,"Mesh does not have lines - starting propagation from a random edge");*/
    /*// Create edges structure*/
    /*hxtLinesReserve(mesh,2);*/
    /*mesh->lines.color[0] = 0;*/
    /*mesh->lines.node[0] = edges->node[2*0+0];*/
    /*mesh->lines.node[1] = edges->node[2*0+1];*/
    /*mesh->lines.num++;*/

    /*for (uint64_t i=0; i<mesh->triangles.num; i++){*/
      /*mesh->triangles.color[i] = 1;*/
    /*}*/

    /*opt->generateLines = 0;*/

  /*}*/

 
  clock_t time_lines_start = clock();
  
  //**********************************************************************************************************
  //**********************************************************************************************************
  // GENERATE POINTS ON LINES 
  //**********************************************************************************************************
  //**********************************************************************************************************

  if (mesh->lines.num != 0 && opt->generateLines){
    HXT_CHECK(hxtGeneratePointsOnLines(mesh,opt,directions,sizemap,fmesh,parent));
  }
  else if (mesh->lines.num != 0 && opt->generateLines == 0 && opt->generateSurfaces == 1){
    HXT_CHECK(hxtGetPointsOnLinesFromInputMesh(mesh,opt,fmesh,parent));
  }
  else if (mesh->lines.num == 0 && opt->generateSurfaces){
    HXT_INFO_COND(opt->verbosity>=0,"********** ATTENTION **********");
    HXT_INFO_COND(opt->verbosity>=0,"Mesh does not have lines - starting propagation from a random point");

    uint32_t seedNode = mesh->triangles.node[3*0+0];

    hxtPointsReserve(mesh,1);
    mesh->points.node[0] = seedNode;
    mesh->points.num++;

    fmesh->vertices.coord[0] = mesh->vertices.coord[4*seedNode+0];
    fmesh->vertices.coord[1] = mesh->vertices.coord[4*seedNode+1];
    fmesh->vertices.coord[2] = mesh->vertices.coord[4*seedNode+2];
    fmesh->vertices.coord[3] = mesh->vertices.coord[4*seedNode+3];
    fmesh->vertices.num++;

    fmesh->points.node[0] = mesh->points.node[0];
    fmesh->points.num++;

    for (uint64_t i=0; i<mesh->triangles.num; i++){
      mesh->triangles.color[i] = 1;
    }

    parent[0].type = 15;
    parent[0].id = 0;



  }
    
  // Check if there is even number of points generated on lines 
  // TODO 
/*  if (fmesh->lines.num%2 != 0){*/
    /*printf("\n\nContinue with odd number of points? y/n \n\n");*/
    /*char ch = getchar();*/
    /*getchar();*/
    /*if ( ch == 'n') return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Number of points on lines not even");*/
  /*}*/

  // Checking correct number of 1d point elements (i.e. "corners")
  // TODO delete
  uint32_t countCorners = 0;
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 15) countCorners++;
  }
  if (countCorners != fmesh->points.num) 
    return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Corner problem %d %d", countCorners, fmesh->points.num);

  if (opt->verbosity > 1) HXT_CHECK(hxtMeshWriteGmsh(fmesh, "FINALMESHlines.msh"));

  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"Number of points generated on lines    = %d", fmesh->vertices.num);

  uint32_t numberOfPointsOnLines = fmesh->vertices.num;


  clock_t time_lines_end = clock();

  
  //**********************************************************************************************************
  // Create array with binary alternating indices 
  //**********************************************************************************************************
  uint32_t *bin;
  // Read bin file if we generate only volumes
  if (opt->generateLines == 0 && opt->generateSurfaces == 0 && opt->generateVolumes){
    uint32_t numVert = 0;
    //HXT_CHECK(hxtPointGenReadBinIndices("binInput.txt",fmesh->vertices.size,&numVert,&bin));

    // TODO ATTENTION HERE, IT WILL NOT GET INPUT BINARY INDICES FILE FOR 3D 
    HXT_CHECK(hxtMalloc(&bin,sizeof(uint32_t)*fmesh->vertices.size));
    for (uint32_t i=0; i<fmesh->vertices.size; i++) bin[i] = 0;


  }
  else if (opt->generateLines == 0 && opt->generateSurfaces == 1){
    // The input is given so we have to assign binary indices
    // to each discrete lineloop
        
    HXT_CHECK(hxtMalloc(&bin,sizeof(uint32_t)*fmesh->vertices.size));
    for (uint32_t i=0; i<fmesh->vertices.size; i++) bin[i] = UINT32_MAX;

    HXT_CHECK(hxtAssignLineBinIndices(fmesh,bin));
  }
  else{
    // Lines were discretized between feature points 
    // so we can assign binary indices on the corners and then on interior
    
    HXT_CHECK(hxtMalloc(&bin,sizeof(uint32_t)*fmesh->vertices.size));
    for (uint32_t i=0; i<fmesh->vertices.size; i++) bin[i] = UINT32_MAX;

    for (uint32_t i=0; i<fmesh->points.num; i++){
      bin[fmesh->points.node[i]] = 0;
    }

    for (uint32_t i=0; i<fmesh->lines.num; i++){
      uint32_t v0 = fmesh->lines.node[2*i+0];
      uint32_t v1 = fmesh->lines.node[2*i+1];
      if (bin[v0] != UINT32_MAX && bin[v1] != UINT32_MAX) continue;
      if (bin[v0] == UINT32_MAX)
        bin[v0] = bin[v1] == 0 ? 1:0;
      if (bin[v1] == UINT32_MAX)
        bin[v1] = bin[v0] == 0 ? 1:0;
    }
  }

    
  // TODO delete
  if(opt->verbosity == 2){
    FILE *test;
    hxtPosInit("binLines.pos","bin",&test);
    for (uint32_t i=0; i<fmesh->vertices.num; i++){
      hxtPosAddPoint(test,&fmesh->vertices.coord[4*i],bin[i]);
    }
    hxtPosFinish(test);
  }

 
  /*// Write out lines with same binary index */
  /*// TODO delete*/
  /*{*/
    /*FILE *test;*/
    /*hxtPosInit("checkBadLines.pos","edg",&test);*/
    /*for (uint32_t i=0; i<fmesh->lines.num; i++){*/
      /*uint32_t v0 = fmesh->lines.node[2*i+0];*/
      /*uint32_t v1 = fmesh->lines.node[2*i+1];*/
      /*if (bin[v0] == bin[v1]) */
        /*hxtPosAddLine(test,&fmesh->vertices.coord[4*v0],&fmesh->vertices.coord[4*v1],0);*/
    /*}*/
    /*hxtPosFinish(test);*/
  /*}*/

  // Check correct bipartite input of lines 
  for (uint32_t i=0; i<fmesh->lines.num; i++){
    uint32_t v0 = fmesh->lines.node[2*i+0];
    uint32_t v1 = fmesh->lines.node[2*i+1];
    if (bin[v0] == bin[v1] && bin[v0] != UINT32_MAX) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Boundary edge with same index");
    if (bin[v0] == UINT32_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Boundary point without binary index");
  }


  clock_t time_points_start = clock();

  //**********************************************************************************************************
  //**********************************************************************************************************
  // GENERATE POINTS ON SURFACES 
  //**********************************************************************************************************
  //**********************************************************************************************************

  if (opt->generateSurfaces){
    //HXT_CHECK(hxtGeneratePointsOnSurfacePropagate(opt,mesh,edges,sizemap,directions,parent,fmesh,bin));
    HXT_CHECK(hxtGeneratePointsOnSurface(opt,mesh,edges,sizemap,directions,parent,fmesh,bin));
  }
  else{
    HXT_CHECK(hxtGetPointsOnSurfacesFromInputMesh(mesh,opt,fmesh,parent));
  }

  if (opt->verbosity>=2) HXT_CHECK(hxtPointGenExportPointsToPos(fmesh,"pointsSurface.pos"));

  uint32_t numberOfPointsOnSurfaces = fmesh->vertices.num - numberOfPointsOnLines;

  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"Number of points generated on surfaces = %d", numberOfPointsOnSurfaces);
  HXT_INFO_COND(opt->verbosity>=1,"Number of points generated TOTAL       = %d", fmesh->vertices.num);

  clock_t time_points_end = clock();

  // TODO delete
  if(opt->verbosity>=2){
    FILE *test;
    hxtPosInit("binSurfaces.pos","bin",&test);
    for (uint32_t i=0; i<fmesh->vertices.num; i++){
      hxtPosAddPoint(test,&fmesh->vertices.coord[4*i],bin[i]);
    }
    hxtPosFinish(test);
  }



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
      uint64_t parentTriangle = parent[i].id;
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
  
    HXT_CHECK(hxtGeneratePointsOnVolumes(mesh,opt,sizemap,directions,parent,fmesh,bin));
  
    if (opt->verbosity>=2) HXT_CHECK(hxtPointGenExportPointsToPos(fmesh,"pointsVolume.pos"));

  }
  uint32_t numberOfPointsOnVolumes = fmesh->vertices.num - numberOfPointsOnLines - numberOfPointsOnSurfaces;
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"Number of points generated on volumes  = %d", numberOfPointsOnVolumes);
  HXT_INFO_COND(opt->verbosity>=0,"PointGen | Number of points generated TOTAL       = %d", fmesh->vertices.num);


  if(opt->verbosity >= 2){
    FILE *test;
    hxtPosInit("binVolumes.pos","bin",&test);
    for (uint32_t i=0; i<fmesh->vertices.num; i++){
      hxtPosAddText(test,&fmesh->vertices.coord[4*i],"%d",bin[i]);
    }
    hxtPosFinish(test);
  }







  //**********************************************************************************************************
  //**********************************************************************************************************
  // CREATE SURFACE MESH 
  //**********************************************************************************************************
  //**********************************************************************************************************
 

  //**********************************************************************************************************
  // To keep a global relation of vertices (initial+generated) with input mesh triangles
  uint64_t *p2t;
  uint64_t totalVertices = mesh->vertices.num + 2*fmesh->vertices.num;
  HXT_CHECK(hxtMalloc(&p2t,sizeof(uint64_t)*totalVertices));
  for (uint64_t i=0; i<totalVertices; i++) p2t[i] = UINT64_MAX;

  //**********************************************************************************************************
  // To keep a relation of generated vertices on the final mesh and the index of fmesh generated points  
  uint32_t *p2p;
  HXT_CHECK(hxtMalloc(&p2p,sizeof(uint32_t)*totalVertices));
  for (uint32_t i=0; i<totalVertices; i++) p2p[i] = UINT32_MAX ;



  clock_t time_surfaces_start = clock();
  
  if (opt->remeshSurfaces){
    // Find max length to create an area threshold 
    // TODO use that 
    double maxLength = 0;
    HXT_CHECK(hxtPointGenModelMaxLength(mesh->vertices.coord,mesh->vertices.num,&maxLength));
    opt->areaThreshold = maxLength*maxLength*10e-8;
    
    // Surface remesher
    HXT_CHECK(hxtSurfaceMesh(opt,mesh,edges,directions,sizemap,parent,p2t,p2p,fmesh,nmesh));
  }
  else{
    if (opt->generateLines==0 && opt->generateSurfaces==0){
      HXT_CHECK(hxtGetSurfaceMesh(opt,mesh,fmesh,nmesh));
    }
    else{
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"not working for now");
    }
  }


  clock_t time_surfaces_end = clock();

  //********************************************************
  // A LOT OF DIFFERENT MESH STRUCTURES 
  // -  mesh -> initial mesh 
  // - fmesh -> holds feature points, lines, and generated vertices 
  // - nmesh -> holds final mesh triangles and vertices (without lines and points)
 
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
  // TODO 
  //**********************************************************************************************************
  //**********************************************************************************************************
  if(0) HXT_CHECK(hxtSurfaceMeshExportTriangleQuality(nmesh,sizemap));

  //**********************************************************************************************************
  //**********************************************************************************************************
  // Constructing a quad mesh from binary indices 
  //**********************************************************************************************************
  //**********************************************************************************************************
  
  clock_t time_quads_start = clock();

  if (opt->verbosity>=1) HXT_CHECK(hxtMeshWriteGmsh(nmesh, "finalmeshTriangles.msh"));
  if (opt->quadSurfaces == 1){

    // Transfer binary indices to final surface mesh 
    uint32_t *tbin;
    HXT_CHECK(hxtMalloc(&tbin,sizeof(uint32_t)*fmesh->vertices.size));
    for (uint32_t i=0; i<fmesh->vertices.size; i++) tbin[i] = bin[i];
    for (uint32_t i=0; i<nmesh->vertices.num; i++){
      if (p2p[i] == UINT32_MAX){
        bin[i] = 1;
        continue;
      }
      bin[i] = tbin[p2p[i]];
    }
    for (uint32_t i=nmesh->vertices.num; i<fmesh->vertices.size; i++){
      bin[i] = UINT32_MAX;
    }
    HXT_CHECK(hxtFree(&tbin));

    // Output 
    // TODO delete
    if(opt->verbosity>=2){
      FILE *test;
      hxtPosInit("binIndices.pos","edges",&test);
      for (uint32_t i=0; i<nmesh->vertices.num; i++){
        hxtPosAddPoint(test,&nmesh->vertices.coord[4*i],bin[i]);
      }
      hxtPosFinish(test);
    }

    // Convert final mesh "nmesh" to a quad mesh "qmesh"
    // and then rewrite qmesh onto nmesh
    HXT_CHECK(hxtPointGenQuadConvert(opt,mesh,nmesh,p2t,bin));

    // Output 
    // TODO delete
    if(opt->verbosity>=2){
      FILE *test;
      hxtPosInit("binIndicesAfter.pos","edges",&test);
      for (uint32_t i=0; i<nmesh->vertices.num; i++){
        hxtPosAddPoint(test,&nmesh->vertices.coord[4*i],0);
        hxtPosAddText(test,&nmesh->vertices.coord[4*i],"%d",bin[i]);

      }
      hxtPosFinish(test);
    }
  }

  clock_t time_quads_end = clock();



  // Output binary indices for subsequent input to volume point generation
  if(opt->verbosity>=1){
    FILE *test = fopen("binInput.txt","w");
    fprintf(test,"%d\n",nmesh->vertices.num);
    for (uint32_t i=0; i<nmesh->vertices.num; i++){
      fprintf(test,"%d\n",bin[i]);
    }
    fprintf(test,"\n");
    fclose(test);

    FILE *out;
    hxtPosInit("bin3D.pos","bin",&out);
    for (uint32_t i=0; i<nmesh->vertices.num; i++){
      hxtPosAddPoint(out,&nmesh->vertices.coord[4*i],bin[i]);
    }
    hxtPosNewView(test,"labels");
    for (uint32_t i=0; i<nmesh->vertices.num; i++){
      hxtPosAddText(test,&nmesh->vertices.coord[4*i],"%d",bin[i]);
    }
    hxtPosFinish(out);
  }
 

  if(opt->quadSurfaces) HXT_INFO_COND(opt->verbosity>=0,"PointGen | Input: %lu triangles - Output: %lu quads",mesh->triangles.num, nmesh->quads.num);


  clock_t time_end = clock();

  //**********************************************************************************************************
  // Timings 
  //**********************************************************************************************************
  
  double time_lines =    (double)(time_lines_end - time_lines_start) / CLOCKS_PER_SEC;
  double time_points =   (double)(time_points_end - time_points_start) / CLOCKS_PER_SEC;
  double time_surfaces = (double)(time_surfaces_end - time_surfaces_start) / CLOCKS_PER_SEC;
  double time_quads =    (double)(time_quads_end - time_quads_start) / CLOCKS_PER_SEC;
  double time_total =    (double)(time_end - time_start) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>=0,"PointGen | Timings");
  HXT_INFO_COND(opt->verbosity>=0,"           Lines       %f", time_lines);
  HXT_INFO_COND(opt->verbosity>=0,"           Points      %f", time_points);
  HXT_INFO_COND(opt->verbosity>=0,"           Surfaces    %f", time_surfaces);
  HXT_INFO_COND(opt->verbosity>=0,"           Quads       %f", time_quads);
  HXT_INFO_COND(opt->verbosity>=0,"           Total       %f", time_total);
  HXT_INFO_COND(opt->verbosity>=0,"           Total-rest  %f", time_total - time_quads-time_surfaces-time_points-time_lines);


  FILE *outt;
  outt = fopen("outtimings.txt","w");
  fprintf(outt,"%f , %f , %f , %f , %f , ", time_lines, time_points, time_surfaces, time_quads, time_total);
  fclose(outt);


  //**********************************************************************************************************
  //**********************************************************************************************************
  // Clear things
  //**********************************************************************************************************
  //**********************************************************************************************************
  
  HXT_CHECK(hxtMeshDelete(&fmesh));
 

  HXT_CHECK(hxtFree(&parent));
  HXT_CHECK(hxtEdgesDelete(&edges));

  HXT_CHECK(hxtFree(&p2t));
  HXT_CHECK(hxtFree(&p2p));
  HXT_CHECK(hxtFree(&bin));

  return HXT_STATUS_OK; 
}

