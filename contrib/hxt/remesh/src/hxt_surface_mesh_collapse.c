#include <math.h>
#include <time.h>
#include <float.h>

#include "hxt_surface_mesh_collapse.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_realloc.h"
#include "hxt_point_gen_optim.h"

#include "hxt_collapse_edge.h"
#include "hxt_swap_edge.h"
#include "hxt_point_gen_numerics.h"

#include "predicates.h"

#include "hxt_post_debugging.h"

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
// TODO delete, just for checking 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtCheckingParents(HXTMesh *tmesh, HXTPointGenParent *parent)
{
  //*****************************************************************************
  // Checking parents
  // TODO delete
  //*****************************************************************************
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (parent[i].type != 2) continue;
    uint64_t ct = parent[i].id;
    uint32_t *v = tmesh->triangles.node + 3*ct;
    if (v[0] != i && v[1] != i && v[2] != i) printf("PROBLEM\n");
    if (tmesh->triangles.colors[ct] == UINT16_MAX) 
      printf("GRAVE ERROR\n");
  }
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (parent[i].type != 1) continue;

    uint64_t cl = parent[i].id;
    uint32_t *v = tmesh->lines.node + 2*cl;
    if (v[0] != i && v[1] != i) printf("PROBLEM\n");

    if (tmesh->lines.colors[cl] == UINT16_MAX) 
      printf("GRAVE ERROR\n");
  }
  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    if (tmesh->triangles.colors[i] == UINT16_MAX) continue;
    uint32_t v0 = tmesh->triangles.node[3*i+0];
    uint32_t v1 = tmesh->triangles.node[3*i+1];
    uint32_t v2 = tmesh->triangles.node[3*i+2];

    if (parent[v0].type == 2){
      uint64_t ct = parent[v0].id;
      if (tmesh->triangles.colors[ct] == UINT16_MAX) printf("ERROR\n");
    }
    if (parent[v1].type == 2){
      uint64_t ct = parent[v1].id;
      if (tmesh->triangles.colors[ct] == UINT16_MAX) printf("ERROR\n");
    }
    if (parent[v2].type == 2){
      uint64_t ct = parent[v2].id;
      if (tmesh->triangles.colors[ct] == UINT16_MAX) printf("ERROR\n");
    }
  }

  return HXT_STATUS_OK;
}

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
// TODO delete, just for checking 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtCheckOrientation(HXTMesh *mesh, 
                              HXTEdges *edges,
                              uint64_t *edges2lines,
                              uint64_t maxNumTriToLine,
                              uint64_t *lines2triangles)
{

  FILE *out;
  hxtPosInit("checkOriented.pos","Triangles",&out);

  for (uint32_t i=0; i<edges->numEdges; i++){
    if (edges2lines[i] == UINT64_MAX) continue;

    for (uint64_t j=0; j<maxNumTriToLine; j++){
      uint64_t ct = lines2triangles[maxNumTriToLine*edges2lines[i]+j];
      if (ct == UINT64_MAX) continue;

      int is = isEdgeOrientedInTriangle(mesh,edges,ct,i);

      uint32_t *nod = mesh->triangles.node + 3*ct;
      if (is) hxtPosAddTriangle(out,&mesh->vertices.coord[4*nod[0]],&mesh->vertices.coord[4*nod[1]],&mesh->vertices.coord[4*nod[2]],0);
      

    }
  }


  hxtPosFinish(out);



  return HXT_STATUS_OK; 
}


//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtSurfaceMeshTransferToNewMesh(HXTMesh *tmesh,
                                          uint64_t *p2t,
                                          uint32_t *p2p,
                                          uint32_t *flagV,
                                          HXTMesh *nmesh)
{

  for (uint32_t i=0; i<tmesh->vertices.num; i++) flagV[i] = UINT32_MAX;

  int countDeletedTri = 0 ;
  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    if (tmesh->triangles.colors[i] == UINT16_MAX){
      countDeletedTri++;
      continue;
    }
    flagV[tmesh->triangles.node[3*i+0]] = 1;
    flagV[tmesh->triangles.node[3*i+1]] = 1;
    flagV[tmesh->triangles.node[3*i+2]] = 1;
  }


  uint32_t *node2node;
  HXT_CHECK(hxtMalloc(&node2node,tmesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<tmesh->vertices.num; i++) node2node[i] = UINT32_MAX;

  HXT_CHECK(hxtAlignedMalloc(&nmesh->vertices.coord,(4*tmesh->vertices.size)*sizeof(double)));
  nmesh->vertices.size = tmesh->vertices.size; //TODO what is a good estimation ???
  nmesh->vertices.num = 0;
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (flagV[i] == UINT32_MAX) continue;
    nmesh->vertices.coord[4*nmesh->vertices.num+0] = tmesh->vertices.coord[4*i+0];
    nmesh->vertices.coord[4*nmesh->vertices.num+1] = tmesh->vertices.coord[4*i+1];
    nmesh->vertices.coord[4*nmesh->vertices.num+2] = tmesh->vertices.coord[4*i+2];
    nmesh->vertices.coord[4*nmesh->vertices.num+3] = tmesh->vertices.coord[4*i+3];
    node2node[i] = nmesh->vertices.num;
    nmesh->vertices.num++;
  }

  nmesh->triangles.size = tmesh->triangles.num - countDeletedTri; //TODO what is a good estimation ???
  nmesh->triangles.num = nmesh->triangles.size;
  HXT_CHECK(hxtAlignedMalloc(&nmesh->triangles.node,(3*nmesh->triangles.size)*sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&nmesh->triangles.colors,(nmesh->triangles.size)*sizeof(uint16_t)));
  uint64_t cT = 0;
  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    if (tmesh->triangles.colors[i] == UINT16_MAX) continue;
    nmesh->triangles.node[3*cT+0] = node2node[tmesh->triangles.node[3*i+0]];
    nmesh->triangles.node[3*cT+1] = node2node[tmesh->triangles.node[3*i+1]];
    nmesh->triangles.node[3*cT+2] = node2node[tmesh->triangles.node[3*i+2]];
    nmesh->triangles.colors[cT] = tmesh->triangles.colors[i];
    cT++;
  }


  // Update p2t
  uint64_t *np2t;
  HXT_CHECK(hxtMalloc(&np2t,nmesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<nmesh->vertices.num; i++) np2t[i] = UINT64_MAX;

  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (flagV[i] == UINT32_MAX) continue;
    np2t[node2node[i]] = p2t[i];
  }

  for (uint32_t i=0; i<nmesh->vertices.num; i++){
    if (np2t[i] == UINT64_MAX) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Transfer p2t error\n");
    p2t[i] = np2t[i];
  }

  HXT_CHECK(hxtFree(&np2t));


  // Update p2p
  uint32_t *np2p;
  HXT_CHECK(hxtMalloc(&np2p,nmesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<nmesh->vertices.num; i++) np2p[i] = UINT32_MAX;

  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (flagV[i] == UINT32_MAX) continue;
    np2p[node2node[i]] = p2p[i];
  }
  for (uint32_t i=0; i<nmesh->vertices.num; i++){
    //if(np2p[i] == UINT32_MAX) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Transfer p2p error\n");
    p2p[i] = np2p[i];
  }
  HXT_CHECK(hxtFree(&np2p));



  HXT_CHECK(hxtFree(&node2node));

  return HXT_STATUS_OK;
}

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtSurfaceMeshCollapseSwap(const HXTMesh *mesh,
                                     const double *directions,
                                     const double *sizemap,
                                     HXTPointGenOptions *opt,
                                     HXTMesh *tmesh,
                                     HXTEdges *tedges,
                                     uint32_t *flagE,
                                     HXTPointGenParent *parent,
                                     uint64_t *edges2lines,
                                     uint64_t maxNumTriToLine,
                                     uint64_t *lines2triangles,
                                     int iter,
                                     int swapmax)
{
  HXT_UNUSED(opt);
  HXT_UNUSED(iter);

  int numSwapsOld = 0;
  for (int ii=0; ii<swapmax; ii++){
    int numSwaps = 0;
    for (uint32_t i = 0 ; i < tedges->numEdges ; i++ ) {

      if (flagE[i] == UINT32_MAX) continue; // Do not swap if edge is already collapsed
      if (edges2lines[i] != UINT64_MAX) continue; // Do not swap if it's boundary line

      if (tmesh->triangles.colors[tedges->edg2tri[2*i+0]] == opt->skipColor) continue;
      if (tmesh->triangles.colors[tedges->edg2tri[2*i+1]] == opt->skipColor) continue;

      //hxtTempPrintSwap(mesh,edges,i,0);

      //*************************************************************
      // Swapping
      //*************************************************************
      int swapped = 0 ;
      HXT_CHECK(hxtSwapEdge(tmesh, 
                            tedges, 
                            NULL, 
                            NULL,
                            edges2lines,
                            maxNumTriToLine,
                            lines2triangles,
                            0.0,
                            i,
                            &swapped));
      numSwaps += swapped;

      //if (swapped) hxtTempPrintSwap(mesh,edges,i,1);
      //printf("Swapped = %d \n", swapped);
      //printf("\n");
      

      //*************************************************************
      // Updating structures
      //*************************************************************
      // Do not rebuild structures if swap did not happen
      // Notice!
      //  in case we don't stop here if no swap maybe structures will change on the boundary!
      if (swapped == 0) continue;

      // Rebuilding edges2lines and lines2triangles
      uint64_t t0 = tedges->edg2tri[2*i+0];
      uint64_t t1 = tedges->edg2tri[2*i+1];
      if (t0 == UINT64_MAX || t1 == UINT64_MAX){ 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Collapse Swap edg2tri == UINT64_MAX");
      }
      if (t0 == t1) 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Insertion Swap same triangles for one edge");
 
      // TODO delete or debug mode
      if (tmesh->triangles.colors[t0] == UINT16_MAX){ 
        FILE *dd;
        hxtPosInit("cannotCollapseSwap.pos", "Check", &dd);
        double *v0 = tmesh->vertices.coord + 4*tedges->node[2*i+0];
        double *v1 = tmesh->vertices.coord + 4*tedges->node[2*i+1];
        hxtPosAddLine(dd,v0,v1,t0);
        hxtPosFinish(dd);
        HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESHcannotSwap.msh"));
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Collapse Swap color of t0 == UINT64_MAX");
      }
      if (tmesh->triangles.colors[t1] == UINT16_MAX){
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Collapse Swap color of t1 == UINT64_MAX");
      }

      for (uint32_t j=0; j<3; j++){
        uint32_t ce = tedges->tri2edg[3*t0+j];
        if (edges2lines[ce] == UINT64_MAX) continue;
        uint64_t cl = edges2lines[ce];
        for (uint64_t k=0; k<maxNumTriToLine; k++){
          uint64_t ct = lines2triangles[maxNumTriToLine*cl+k];
          if (ct == t1) lines2triangles[maxNumTriToLine*cl+k] = t0;
        }
      }
      for (uint32_t j=0; j<3; j++){
        uint32_t ce = tedges->tri2edg[3*t1+j];
        if (edges2lines[ce] == UINT64_MAX) continue;
        uint64_t cl = edges2lines[ce];
        for (uint64_t k=0; k<maxNumTriToLine; k++){
          uint64_t ct = lines2triangles[maxNumTriToLine*cl+k];
          if (ct == t0) lines2triangles[maxNumTriToLine*cl+k] = t1;
        }
      }

      // Updating parent
      for (uint32_t j=0; j<3; j++){
        uint32_t v0 = tmesh->triangles.node[3*t0+j];
        if (parent[v0].type == 2) parent[v0].id = t0;
        uint32_t v1 = tmesh->triangles.node[3*t1+j];
        if (parent[v1].type == 2) parent[v1].id = t1;
      }

    }

    HXT_INFO_COND(opt->verbosity>0,"%d - Number of swaps in collapsing %d", ii, numSwaps);
    if (numSwapsOld == numSwaps) break;
    numSwapsOld = numSwaps;
  }

  return HXT_STATUS_OK; 
}




//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtSurfaceMeshCollapse(const HXTMesh *mesh,
                                 const double *directions,
                                 const double *sizemap,
                                 HXTPointGenOptions *opt,
                                 HXTMesh *tmesh, // intermediate mesh with initial+generated points
                                 HXTEdges *tedges, 
                                 HXTPointGenParent *tparent,
                                 uint64_t *p2t,
                                 uint32_t *p2p,
                                 uint32_t *flagV,
                                 HXTMesh *nmesh) // to store final mesh 
{

  HXT_INFO("");
  HXT_INFO("========= Surface Remeshing - Removing Initial Vertices  ==========");
  HXT_INFO_COND(opt->verbosity>0,"");
   

  // TODO normally we could take the following structures as input from insertion step
  // check if they get correctly created there 

  //***********************************************************************************************
  // Create list of colors of triangles
  //***********************************************************************************************
  uint16_t *triColors;
  uint16_t numTriColors;
  HXT_CHECK(hxtGetTrianglesColorsList(tmesh,&numTriColors,&triColors));
  HXT_INFO_COND(opt->verbosity>0,"Number of colors:  %d", numTriColors);

  //***********************************************************************************************
  // Create lines to edges array; 
  //***********************************************************************************************
  uint32_t *lines2edges;
  HXT_CHECK(hxtMalloc(&lines2edges,tmesh->lines.size*sizeof(uint32_t)));
  for (uint32_t i=0; i<tmesh->lines.size; i++) lines2edges[i] = UINT32_MAX;
  HXT_CHECK(hxtGetLinesToEdges(tedges,lines2edges));

  //***********************************************************************************************
  // Create edges to lines array;
  //***********************************************************************************************
  uint64_t *edges2lines;
  HXT_CHECK(hxtMalloc(&edges2lines,tedges->numEdges*sizeof(uint64_t)));
  for (uint32_t i=0; i<tedges->numEdges; i++) edges2lines[i] = UINT64_MAX;
  HXT_CHECK(hxtGetEdgesToLines(tedges,lines2edges,edges2lines));

  //***********************************************************************************************
  // Create lines to triangles array
  // This is used to handle non-manifold triangulations
  // where mesh lines can have more than 2 triangles
  //***********************************************************************************************
  uint64_t maxNumTriToLine = 0; // maximum number of triangles adjacent to a line
  HXT_CHECK(hxtCountMaxNumberOfTrianglesToEdges(tedges,&maxNumTriToLine));
  HXT_INFO_COND(opt->verbosity>0,"Number of max tri to line:  %lu", maxNumTriToLine);
  uint64_t *lines2triangles;
  HXT_CHECK(hxtMalloc(&lines2triangles,maxNumTriToLine*tmesh->lines.size*sizeof(uint64_t)));
  for (uint64_t i=0; i<maxNumTriToLine*tmesh->lines.size; i++) lines2triangles[i] = UINT64_MAX;
  HXT_CHECK(hxtGetLinesToTriangles(tedges,maxNumTriToLine,edges2lines,lines2triangles));

  //***********************************************************************************************
  // Create vertices to lines array
  //***********************************************************************************************
  uint64_t maxNumLinesToVertex = 0;
  HXT_CHECK(hxtCountMaxNumberOfLinesToVertices(tmesh,&maxNumLinesToVertex));
  HXT_INFO_COND(opt->verbosity>0,"Number of max lines to vertex:  %lu", maxNumLinesToVertex);

  // TODO we do not really need maxNumLinesToVertex
  // since we are concerned only with boundary vertices that are not corners
  // these vertices have always 2 lines 
  uint64_t *vertices2lines;
  HXT_CHECK(hxtMalloc(&vertices2lines,maxNumLinesToVertex*tmesh->vertices.num*sizeof(uint64_t)));
  for (uint64_t i=0; i<maxNumLinesToVertex*tmesh->vertices.num; i++) vertices2lines[i] = UINT64_MAX;
  HXT_CHECK(hxtGetVerticesToLines(tmesh,maxNumLinesToVertex,vertices2lines));

  //***********************************************************************************************
  // Checking if vertices with more than 2 lines are corners 
  // TODO delete or debug mode  
  //***********************************************************************************************
  for (uint32_t i=0; i<tmesh->lines.num; i++){
    for (uint32_t j=0; j<2; j++){
      uint32_t v = tmesh->lines.node[2*i+j];
      uint64_t countLines = 0;
      for (uint64_t k=0; k<maxNumLinesToVertex; k++){
        if (vertices2lines[maxNumLinesToVertex*v+k] == UINT64_MAX) continue;
        countLines++;
      }
      if (countLines == 0) 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Could not find lines for this vertex");

      if (countLines>2 && tparent[v].type != 15){
        FILE *test;
        hxtPosInit("checkNonManifoldPoint.pos","point",&test);
        hxtPosAddPoint(test,&tmesh->vertices.coord[4*v],0);
        hxtPosFinish(test);
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Vertex with more than 2 lines is not a corner");
      }
    }
  }

  //**************************************************
  // Array to flag collapsed edges
  // Collapsed triangles are flagged through their color 
  //**************************************************
  uint32_t *flagE; // 0 to delete, 1 to insert
  HXT_CHECK(hxtMalloc(&flagE,tedges->numEdges*sizeof(uint32_t)));
  for (uint32_t i=0; i<tedges->numEdges; i++) flagE[i] = 1;

  //**************************************************
  //**************************************************
  uint32_t countPointsToDelete = 0;
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (tparent[i].type == 4) continue;
    if (flagV[i] == UINT32_MAX) countPointsToDelete++;
    if (flagV[i] != UINT32_MAX) flagV[i] = 2;
  }

  uint32_t countPointsCollapsed = 0;

for (uint32_t kkk=0; kkk<10; kkk++){

  //***********************************************************************************************
  //***********************************************************************************************
  // For interior vertices
  //***********************************************************************************************
  //***********************************************************************************************
  HXT_INFO("");
  HXT_INFO("--- Removing points on interior");

  uint32_t numCollapsedInteriorPoints = 0;
  uint32_t old = numCollapsedInteriorPoints;


for (uint32_t kk=0; kk<100; kk++){

  for (uint32_t i=0; i<tmesh->vertices.num; i++){

    uint32_t cv = i; 
    //cv = (rand()%(tmesh->vertices.num-0+1))+0;

    // Check if vertex is to be removed
    if (flagV[cv] != UINT32_MAX) continue;

    // Check if vertex is on the interior 
    if (tparent[cv].type != 2) continue;

    int collapsed = 0;
    HXT_CHECK(hxtRemoveInteriorVertex(tmesh, 
                                      tedges, 
                                      tparent,
                                      flagE, 
                                      lines2edges,
                                      edges2lines,
                                      lines2triangles,
                                      maxNumTriToLine,
                                      vertices2lines,
                                      maxNumLinesToVertex,
                                      cv, 
                                      &collapsed));

    if (collapsed == 1){
      flagV[cv] = 1;
      countPointsCollapsed ++;
      numCollapsedInteriorPoints++;
    }

    /*char buffer[32];*/
    /*snprintf(buffer,sizeof(char)*32,"tmeshes/fm_%02i_%06i_%06i.msh",(int)kk,(int)numCollapsedInteriorPoints,(int)cv);*/
    /*HXT_CHECK(hxtMeshWriteGmsh(tmesh, buffer));*/

  }

  HXT_INFO_COND(opt->verbosity>0,"Iteration %d collapsed = %d", kk, countPointsCollapsed);

  int finalSwaps = 1;
  HXT_CHECK(hxtSurfaceMeshCollapseSwap(mesh,
                                       directions,
                                       sizemap,
                                       opt,
                                       tmesh,
                                       tedges,
                                       flagE,
                                       tparent,
                                       edges2lines,
                                       maxNumTriToLine,
                                       lines2triangles,
                                       kk,
                                       finalSwaps));



  if (old == numCollapsedInteriorPoints) break;
  old = numCollapsedInteriorPoints;

}




  if (opt->verbosity == 2) HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH4interiorcollapse.msh"));
  
  //***********************************************************************************************
  // Swapping after collapse of points on interior   
  //***********************************************************************************************
  
  HXT_INFO("--- Swaps after removing points on interior");

  int numSwapsCollapseLines = 0;
  HXT_INFO_COND(opt->verbosity>0,"Number of swaps = %d ", numSwapsCollapseLines);
  HXT_CHECK(hxtSurfaceMeshCollapseSwap(mesh,
                                       directions,
                                       sizemap,
                                       opt,
                                       tmesh,
                                       tedges,
                                       flagE,
                                       tparent,
                                       edges2lines,
                                       maxNumTriToLine,
                                       lines2triangles,
                                       0,
                                       numSwapsCollapseLines));

  if (opt->verbosity == 2) HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH5interiorcollapseswap.msh"));





  //***********************************************************************************************
  //***********************************************************************************************
  // For vertices on Lines
  //***********************************************************************************************
  //***********************************************************************************************
  HXT_INFO("--- Collapsing points on lines");

  uint32_t numCollapsedLines=0;

  old = numCollapsedLines;

for (uint32_t kk=0; kk<10; kk++){
  for (uint32_t cv=0; cv<tmesh->vertices.num; cv++){

    // Check if vertex is to be removed
    if (flagV[cv] != UINT32_MAX) continue;

    // Check if vertex is on the boundary 
    if (tparent[cv].type != 1) continue;
    
    int collapsed = 0;
    HXT_CHECK(hxtRemoveBoundaryVertex(tmesh,
                                      tedges,
                                      tparent,
                                      flagE,
                                      lines2edges,
                                      edges2lines,
                                      lines2triangles,
                                      maxNumTriToLine,
                                      vertices2lines,
                                      maxNumLinesToVertex,
                                      cv,
                                      &collapsed));

    if (collapsed == 1){
      flagV[cv] = 1;
      countPointsCollapsed ++;
      numCollapsedLines++;
    }

    /*char buffer[32];*/
    /*snprintf(buffer,sizeof(char)*32,"tmeshes/fm_%06i_%06i.msh",(int)numCollapsedLines,(int)cv);*/
    /*HXT_CHECK(hxtMeshWriteGmsh(tmesh, buffer));*/

  }
  HXT_INFO_COND(opt->verbosity>0,"Iteration %d collapsed = %d", kk, countPointsCollapsed);

  int finalSwaps = 1;
  HXT_CHECK(hxtSurfaceMeshCollapseSwap(mesh,
                                       directions,
                                       sizemap,
                                       opt,
                                       tmesh,
                                       tedges,
                                       flagE,
                                       tparent,
                                       edges2lines,
                                       maxNumTriToLine,
                                       lines2triangles,
                                       kk,
                                       finalSwaps));



  if (old == numCollapsedLines) break;
  old = numCollapsedLines;

}


  if (opt->verbosity == 2) HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH6linecollapse.msh"));

  }

  //***********************************************************************************************
  // Final swapping after collapsing edges
  //***********************************************************************************************
  //  
  HXT_INFO("--- Swaps final");

  int finalSwaps = 50;
  HXT_CHECK(hxtSurfaceMeshCollapseSwap(mesh,
                                       directions,
                                       sizemap,
                                       opt,
                                       tmesh,
                                       tedges,
                                       flagE,
                                       tparent,
                                       edges2lines,
                                       maxNumTriToLine,
                                       lines2triangles,
                                       0,
                                       finalSwaps));

  if (opt->verbosity == 2) HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH7finalswaps.msh"));

  HXT_INFO("");
  HXT_INFO("Total Number of collapsed points       %d", countPointsCollapsed);
  HXT_INFO("Total Number of NOT Collapsed Points   %d", countPointsToDelete-countPointsCollapsed);



  if (countPointsToDelete-countPointsCollapsed != 0 && opt->quadSurfaces == 1){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Some points were not collapsed - converting to quads cannot work");
  }

  // TODO debug or delete
  uint32_t countNOT =0;
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (tparent[i].type == 4) continue;
    if (flagV[i] == UINT32_MAX) countNOT++;
  }
  if (countNOT != (countPointsToDelete-countPointsCollapsed))
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Problem in counting points not collapsed");

  // Write out not collapsed points
  if(countNOT!=0){
    FILE *nc;
    hxtPosInit("pointsNotCollapsed.pos","points",&nc);
    for (uint32_t i=0; i<tmesh->vertices.num; i++){
      if (tparent[i].type == 4) continue;
      if (flagV[i] == UINT32_MAX){
        hxtPosAddPoint(nc,&tmesh->vertices.coord[4*i],0);
      }
   
    }
    hxtPosFinish(nc);
  }

  //*************************************************
  // Transfer to new mesh 
  //*************************************************
  HXT_INFO("");
  HXT_INFO("Transfer to new mesh");

  HXT_CHECK(hxtSurfaceMeshTransferToNewMesh(tmesh, p2t, p2p, flagV, nmesh));


  //*************************************************
  // Cleaning up things
  //*************************************************
  HXT_CHECK(hxtFree(&flagE));
  HXT_CHECK(hxtFree(&vertices2lines));
  HXT_CHECK(hxtFree(&lines2edges));
  HXT_CHECK(hxtFree(&edges2lines));
  HXT_CHECK(hxtFree(&lines2triangles));
  HXT_CHECK(hxtFree(&triColors));

  return HXT_STATUS_OK; 
}

