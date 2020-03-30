#include <math.h>
#include <time.h>
#include <float.h>
#include "hxt_surface_mesh.h"
#include "hxt_surface_mesh_collapse.h"

#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_realloc.h"
#include "hxt_rtree_wrapper.h"

#include "hxt_collapse_edge.h"

#include "hxt_split_edge.h"
#include "hxt_split_triangle.h"
#include "hxt_swap_edge.h"
#include "hxt_point_gen_numerics.h"

#include "predicates.h"

#include "hxt_post_debugging.h"

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtTransferInitialMeshToTempMesh(HXTMesh *mesh, 
                                           uint32_t numInitialVertices,
                                           uint32_t maxNumVertices,
                                           uint64_t maxNumTriangles,
                                           uint32_t maxNumEdges,
                                           uint32_t maxNumLines,
                                           HXTMesh *tmesh,
                                           HXTEdges *edges)
{

  // We consider that all the generated points will either split a triangle 
  // or an edge, and thus each point will create at maximum
  // 1 new vertex, 2 new triangles, 3 new edges
  // In practice, generated points may just replace already existing ones
  // or be on a boundary edge and just create 1 new triangle and 2 new edges
  // We put the maximum possible to be on the safe side
  
  HXT_CHECK(hxtVerticesReserve(tmesh, maxNumVertices));
  HXT_CHECK(hxtTrianglesReserve(tmesh,maxNumTriangles));
  HXT_CHECK(hxtLinesReserve(tmesh,maxNumLines));
  HXT_CHECK(hxtPointsReserve(tmesh,mesh->points.num));
  tmesh->lines.num = mesh->lines.num;
  tmesh->points.num = mesh->points.num;
  tmesh->triangles.num = mesh->triangles.num;
  tmesh->vertices.num = mesh->vertices.num;

  // We keep the same edge structure that was created for the initial mesh
  HXT_CHECK(hxtRealloc(&edges->tri2edg,3*maxNumTriangles*sizeof(uint32_t)));
  HXT_CHECK(hxtRealloc(&edges->node,2*maxNumEdges*sizeof(uint32_t))); 
  HXT_CHECK(hxtRealloc(&edges->edg2tri,2*maxNumEdges*sizeof(uint64_t))); 
  edges->edg2mesh = tmesh; // change the mesh pointer that it refers to 

  // Transfer points to temp mesh
  for (uint32_t i=0; i<tmesh->points.num; i++){
    tmesh->points.node[i] = mesh->points.node[i];
  }

  // Transfer lines to temp mesh
  for (uint32_t i=0; i<tmesh->lines.num; i++){
    tmesh->lines.node[2*i+0] = mesh->lines.node[2*i+0];
    tmesh->lines.node[2*i+1] = mesh->lines.node[2*i+1];
    tmesh->lines.colors[i] = mesh->lines.colors[i];
  }

  // Transfer triangles to temp mesh
  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    tmesh->triangles.node[3*i+0] = mesh->triangles.node[3*i+0];
    tmesh->triangles.node[3*i+1] = mesh->triangles.node[3*i+1];
    tmesh->triangles.node[3*i+2] = mesh->triangles.node[3*i+2];
    tmesh->triangles.colors[i] = mesh->triangles.colors[i];
  }
  
  // Store vertices of initial mesh to temp mesh
  for (uint32_t i=0; i<numInitialVertices; i++){
    tmesh->vertices.coord[4*i+0] = mesh->vertices.coord[4*i+0];
    tmesh->vertices.coord[4*i+1] = mesh->vertices.coord[4*i+1];
    tmesh->vertices.coord[4*i+2] = mesh->vertices.coord[4*i+2];
  }

  // TODO 
  // Delete the interior (volume) mesh vertices from tmesh
  // We need to re-update points, lines and triangles
  // as well as the parent structure 

  return HXT_STATUS_OK;
}

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
// Creating new parent structure for intermediate mesh tmesh before collapsing edges 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus hxtCreateParentStructure(HXTMesh *mesh,
                                   HXTMesh *fmesh, 
                                   HXTMesh *tmesh,
                                   HXTPointGenParent *parent,
                                   HXTPointGenParent *tparent)
                                   
{
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
    for (uint32_t j=0; j<4; j++){
      uint32_t vertex = mesh->tetrahedra.node[4*i+j];
      tparent[vertex].type = 4;
      tparent[vertex].id = i;
    }
  }

  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    for (uint32_t j=0; j<3; j++){
      uint32_t vertex = tmesh->triangles.node[3*i+j];
      tparent[vertex].type = 2;
      tparent[vertex].id = i;
    }
  }
  for (uint64_t i=0; i<tmesh->lines.num; i++){
    for (uint32_t j=0; j<2; j++){
      uint32_t vertex = tmesh->lines.node[2*i+j];
      tparent[vertex].type = 1;
      tparent[vertex].id = i;
    }
  }
  uint32_t numCorners = 0;
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 15){
      uint32_t initialPoint = parent[i].id;
      tparent[initialPoint].type = 15;
      tparent[initialPoint].id = i;
      numCorners++;
    }
  }

  // TODO check
  if (numCorners != fmesh->points.num){
    printf("Number of corners in initial mesh and tmesh are different\n");
    printf("   mesh number of points = %d \n", mesh->points.num);
    printf("  tmesh number of points = %d \n",tmesh->points.num);
    printf("counted number of points = %d \n",numCorners);
    return HXT_STATUS_ERROR;
  }



  // TODO delete or debug
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (tparent[i].type == UINT8_MAX || tparent[i].id == UINT64_MAX){
      printf("%d \n", i);
      FILE *test;
      hxtPosInit("point.pos","point",&test);
      hxtPosAddPoint(test,&tmesh->vertices.coord[4*i],0);
      hxtPosFinish(test);
      for (uint64_t j=0; j<tmesh->triangles.num; j++){
        uint32_t *v = &tmesh->triangles.node[3*j];
        if (v[0] == i || v[1] == i || v[2] == i) printf("FOUND %lu \n", j);
      }
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Did not find parent for tmesh");
    }
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
HXTStatus hxtCheckEdgesAndMesh(HXTMesh *mesh, HXTEdges *edges)
{
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];
    uint32_t n0 = edges->node[2*i+0];
    uint32_t n1 = edges->node[2*i+1];
    if (t0 == t1) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge has same neighbours");

    uint32_t v0 = mesh->triangles.node[3*t0+0];
    uint32_t v1 = mesh->triangles.node[3*t0+1];
    uint32_t v2 = mesh->triangles.node[3*t0+2];
    if (n0 != v0 && n0 != v1 && n0 != v2) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge node not on triangle");
    if (n1 != v0 && n1 != v1 && n1 != v2) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge node not on triangle");
    if (v0 == v1 || v0 == v2 || v1 == v2) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Triangle has 2 same nodes");
    v0 = mesh->triangles.node[3*t1+0];
    v1 = mesh->triangles.node[3*t1+1];
    v2 = mesh->triangles.node[3*t1+2];
    if (n0 != v0 && n0 != v1 && n0 != v2) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge node not on triangle");
    if (n1 != v0 && n1 != v1 && n1 != v2) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge node not on triangle");
    if (v0 == v1 || v0 == v2 || v1 == v2) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Triangle has 2 same nodes");

    if (mesh->triangles.colors[t1] != mesh->triangles.colors[t0]) continue;
    for (uint32_t j=0; j<3; j++){
      if (n0 == mesh->triangles.node[3*t0+j]){
        if (n1 != mesh->triangles.node[3*t0+(j+2)%3]) 
          return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge not correctly oriented on triangle");
      }
      if (n0 == mesh->triangles.node[3*t1+j]){
        if (n1 != mesh->triangles.node[3*t1+(j+1)%3]) 
          return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge not correctly oriented on triangle");
      }
    }
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
HXTStatus findGeneratedVerticesOfOriginCoords(void *data,
                                              uint64_t *trilist,
                                              uint64_t numTri,
                                              HXTPointGenParent *parent,
                                              double *ppmin,
                                              double *ppmax,
                                              uint32_t *numVerticesOnTri,
                                              uint32_t **verticesOnTri)
                                                    
{

  int numClose = 0;
  int *idClose = NULL;
  HXT_CHECK(hxtRTreeSearch(ppmin,ppmax,&numClose,&idClose,data));

  if (numClose == 0){
    return HXT_STATUS_OK;
  }

  *numVerticesOnTri = 0;
  HXT_CHECK(hxtMalloc(verticesOnTri,numClose*sizeof(uint32_t)));
  for (int i=0; i<numClose; i++){
    uint32_t vertex = idClose[i];
    if (parent[vertex].type != 2) continue;
    for (uint64_t j=0; j<numTri; j++){
      if( parent[vertex].id == trilist[j]){
        (*verticesOnTri)[(*numVerticesOnTri)] = idClose[i];
        (*numVerticesOnTri)++;
      }
    }
  }

  HXT_CHECK(hxtFree(&idClose));

  return HXT_STATUS_OK;
}

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus reassignTriangleVertices(HXTMesh *tmesh,
                                   HXTMesh *fmesh,
                                   void *data,
                                   uint64_t *trilist,
                                   int numTri,
                                   double tolerance,
                                   HXTPointGenParent *parent)
{
  if (trilist[1] == UINT64_MAX) return HXT_STATUS_OK;

  uint32_t *verticesOnTri = NULL;
  uint32_t numVerticesOnTri = 0;

  double pmin[3] = {DBL_MAX,DBL_MAX,DBL_MAX};
  double pmax[3] = {-DBL_MAX,-DBL_MAX,-DBL_MAX};

  //clock_t time00 = clock();

  double maxLength = -DBL_MAX;
  for (int i=0; i<numTri; i++){
    for (uint32_t j=0; j<3; j++){
      double *v = tmesh->vertices.coord + 4*tmesh->triangles.node[3*trilist[i]+j];
      if (v[0] < pmin[0]) pmin[0] = v[0];
      if (v[1] < pmin[1]) pmin[1] = v[1];
      if (v[2] < pmin[2]) pmin[2] = v[2];
      if (v[0] > pmax[0]) pmax[0] = v[0];
      if (v[1] > pmax[1]) pmax[1] = v[1];
      if (v[2] > pmax[2]) pmax[2] = v[2];

      double *v0 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*trilist[i]+(j+1)%3];
      double dist = distance(v,v0);
      if (dist>maxLength) maxLength = dist;
    }
  }

  double margin = maxLength*tolerance; // TODO 
  margin = maxLength*0.3; //ATTENTION TODO  
  pmin[0]-=margin;
  pmin[1]-=margin;
  pmin[2]-=margin;
  pmax[0]+=margin;
  pmax[1]+=margin;
  pmax[2]+=margin;

  HXT_CHECK(findGeneratedVerticesOfOriginCoords(data,
                                                trilist,
                                                numTri,
                                                parent,
                                                pmin,
                                                pmax,
                                                &numVerticesOnTri,
                                                &verticesOnTri));


  // Check for all vertices 
  for (uint32_t j=0; j<numVerticesOnTri; j++){
    if (parent[verticesOnTri[j]].type != 2) continue;
    //if (parent[verticesOnTri[j]].id != trilist[0]) continue;
    
    double minDist = 1e12;
    for (int k=0; k<numTri; k++){
      double *p0 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*trilist[k]+0];
      double *p1 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*trilist[k]+1];
      double *p2 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*trilist[k]+2];
      double *p = fmesh->vertices.coord + 4*verticesOnTri[j];
      double dist;
      int inside;
      double closePt[3];
      HXT_CHECK(hxtSignedDistancePointTriangle(p0,p1,p2,p,&dist,&inside,closePt));

      if (fabs(dist) < minDist){
        minDist = fabs(dist);
        parent[verticesOnTri[j]].id = trilist[k];
      }
    }
    
  }

  HXT_CHECK(hxtFree(&verticesOnTri));

  return HXT_STATUS_OK;
}

//**************************************************************************************************
//**************************************************************************************************
//
// FUNCTION 
//
//**************************************************************************************************
//**************************************************************************************************
HXTStatus reassignLineVertices(HXTMesh *tmesh,
                               HXTMesh *fmesh,
                               uint64_t cl, // current line 
                               uint64_t nl, // newline
                               HXTPointGenParent *parent)
{

  // TODO this is slow 
  for (uint32_t cv=0; cv<fmesh->vertices.num; cv++){
    if (parent[cv].type != 1) continue;
    if (parent[cv].id != cl) continue;
    if (parent[cv].id == nl) return HXT_STATUS_ERROR;

    double distcl=-1;
    {
      double *p1 = tmesh->vertices.coord + 4*tmesh->lines.node[2*cl+0];
      double *p2 = tmesh->vertices.coord + 4*tmesh->lines.node[2*cl+1];
      double *pn = fmesh->vertices.coord + 4*cv;
      double alpha = -1.;
      double closePt[3] = {0.};
      HXT_CHECK(hxtSignedDistancePointEdge(p1,p2,pn,&distcl,&alpha,closePt));
    }
    double distnl=-1;
    {
      double *p1 = tmesh->vertices.coord + 4*tmesh->lines.node[2*nl+0];
      double *p2 = tmesh->vertices.coord + 4*tmesh->lines.node[2*nl+1];
      double *pn = fmesh->vertices.coord + 4*cv;
      double alpha = -1.;
      double closePt[3] = {0.};
      HXT_CHECK(hxtSignedDistancePointEdge(p1,p2,pn,&distnl,&alpha,closePt));
    }
    if (fabs(distnl)<fabs(distcl)) parent[cv].id = nl;
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
HXTStatus hxtSurfaceMeshInsertInteriorVertex(HXTMesh *tmesh,
                                             HXTMesh *fmesh,
                                             HXTEdges *edges,
                                             HXTPointGenParent *parent,
                                             void *data,
                                             double tolerance, 
                                             uint64_t *edges2lines,
                                             uint64_t maxNumTriToLine,
                                             uint64_t *lines2triangles,
                                             uint32_t cn, 
                                             uint32_t *flagV)
{

  // THREE CASES
  //
  // A. Interior vertex "purely" inside triangle
  //    - split triangle
  //    - flag it as 0 
  //    - reassign vertices (3 triangles)
  //
  // B. Interior vertex 'close' to initial vertex
  //    - flag it as 0 and the initial vertex as 1 
  //
  // C. Interior vertex 'close' to edge
  //    - split edge 
  //    - flag it as 0
  //    - reassign vertices (4 triangles)
  
  // Find if point is close to an edge of the triangle 
  double *pn = fmesh->vertices.coord + 4*cn;
  uint64_t ct = parent[cn].id;

  uint32_t minId = UINT32_MAX;
  double minDist = tolerance; 
  double minAlpha = -1.;

  for (uint32_t j=0; j<3; j++){
    uint32_t ce = edges->tri2edg[3*ct+j];
    double *p1 = tmesh->vertices.coord + 4*edges->node[2*ce+0];
    double *p2 = tmesh->vertices.coord + 4*edges->node[2*ce+1];
    double dist = -1.;
    double alpha = -1.;
    double closePt[3] = {0.};
    HXT_CHECK(hxtSignedDistancePointEdge(p1,p2,pn,&dist,&alpha,closePt));
    if (dist < minDist){
      minId = j;
      minDist = dist;
      minAlpha = alpha;
    }
  }

  // CASE A
  // Split triangle
  if (minId == UINT32_MAX){ 

    int isBoundary = hxtIsTriOnBoundary(edges,edges2lines,ct);

    double uv[2] = {0.};
    HXT_CHECK(hxtGetBarycentric(tmesh,ct,pn,uv));

    HXT_CHECK(hxtSplitTriangle(tmesh, edges, ct, uv));

    // Reassign vertices of triangle ct
    uint64_t trilist[3] = {ct, tmesh->triangles.num-2, tmesh->triangles.num-1};
    HXT_CHECK(reassignTriangleVertices(tmesh,
                                       fmesh,
                                       data,
                                       trilist,
                                       3,
                                       tolerance,
                                       parent));

    // Update lines2triangles if the triangle is on boundary
    if (isBoundary){
      for (uint32_t i=0; i<3; i++){
        uint64_t tri = trilist[i];
        for (uint32_t j=0; j<3; j++){
          uint32_t edge = edges->tri2edg[3*tri+j]; 
          if (edges2lines[edge] == UINT64_MAX) continue;
          uint64_t line = edges2lines[edge];
          for (uint64_t k=0; k<maxNumTriToLine; k++){
            if (lines2triangles[maxNumTriToLine*line+k] == ct)
              lines2triangles[maxNumTriToLine*line+k] = tri;
          }
        }
      }
    }


  }
  // CASE B
  // Generated point close to initial point
  else if (minAlpha >= 1.-tolerance){
    uint32_t ce = edges->tri2edg[3*ct+minId];
    flagV[edges->node[2*ce+1]] = cn;
    return HXT_STATUS_OK;
  }
  else if (minAlpha <= 0.+tolerance) {
    uint32_t ce = edges->tri2edg[3*ct+minId];
    flagV[edges->node[2*ce+0]] = cn;
    return HXT_STATUS_OK;
  }
  // CASE C
  // Split interior edge 
  else{ 

    uint32_t ce = edges->tri2edg[3*ct+minId];
    
    if (edges->edg2tri[2*ce+1] == UINT64_MAX) //(*type) = 4;
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"edg2tri[2*ce+1] == UINT64_MAX");

    uint64_t t0 = edges->edg2tri[2*ce+0];
    uint64_t t1 = edges->edg2tri[2*ce+1];

    int isBoundary0 = hxtIsTriOnBoundary(edges,edges2lines,t0);
    int isBoundary1 = hxtIsTriOnBoundary(edges,edges2lines,t1);

    // TODO delete or debug
    if (tmesh->triangles.colors[t0] != tmesh->triangles.colors[t1]){
      FILE *dd;
      hxtPosInit("insertproblem.pos", "Check", &dd); 
      uint64_t t = t0;
      double *v0 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*t+0];
      double *v1 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*t+1];
      double *v2 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*t+2];
      hxtPosAddTriangle(dd,v0,v1,v2,tmesh->triangles.colors[t]);
      hxtPosAddPoint(dd,pn,0);
      hxtPosFinish(dd);
      printf("%d %lu \n", parent[cn].type, parent[cn].id);
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Insert point different colors %d", cn);
    }
    
    uint32_t ne = UINT32_MAX;

    HXT_CHECK(hxtSplitEdge(tmesh,edges,ce,&ne,minAlpha));

    // Reassign vertices on pairs of two triangles
    {
      uint64_t trilist[2] = {edges->edg2tri[2*ce+0],edges->edg2tri[2*ne+0]};
      HXT_CHECK(reassignTriangleVertices(tmesh,
                                         fmesh,
                                         data,
                                         trilist,
                                         2,
                                         tolerance,
                                         parent));
    }
    {
      uint64_t trilist[2] = {edges->edg2tri[2*ne+1],edges->edg2tri[2*ce+1]};
      HXT_CHECK(reassignTriangleVertices(tmesh,
                                         fmesh,
                                         data,
                                         trilist,
                                         2,
                                         tolerance,
                                         parent));
    }


    // Update lines2triangles if one of the two original triangles is on boundary
    if (isBoundary0 || isBoundary1){
      uint64_t trilist[4] = {edges->edg2tri[2*ce+0],
                             edges->edg2tri[2*ne+0],
                             edges->edg2tri[2*ne+1],
                             edges->edg2tri[2*ce+1]};

      for (uint32_t i=0; i<4; i++){
        uint64_t tri = trilist[i];
        for (uint32_t j=0; j<3; j++){
          uint32_t edge = edges->tri2edg[3*tri+j]; 
          if (edges2lines[edge] == UINT64_MAX) continue;
          uint64_t line = edges2lines[edge];
          for (uint64_t k=0; k<maxNumTriToLine; k++){
            if (lines2triangles[maxNumTriToLine*line+k] == t0 || 
                lines2triangles[maxNumTriToLine*line+k] == t1) 
              lines2triangles[maxNumTriToLine*line+k] = tri;
          }
        }
      }
    }

    return HXT_STATUS_OK;
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
HXTStatus hxtSurfaceMeshInsertLineVertex(HXTMesh *tmesh,
                                         HXTMesh *fmesh,
                                         HXTEdges *edges,
                                         HXTPointGenParent *parent,
                                         void *data,
                                         double tolerance, 
                                         uint32_t *lines2edges,
                                         uint64_t *edges2lines,
                                         uint64_t maxNumTriToLine,
                                         uint64_t *lines2triangles,
                                         uint32_t cn,
                                         uint32_t *flagV) 
{

  // Given a point that lies on a line (boundary edge)
  // parent[cn].type == 1
  
  // Cases:
  // - open surface -> 1 triangle adjacent
  // - manifold -> 2 triangles adjacent
  // - non-manifold -> >3 triangles adjacent
  
  uint64_t cl = parent[cn].id;   // current line 
  uint32_t ce = lines2edges[cl]; // corresponding current edge

  uint32_t n1 = tmesh->lines.node[2*cl+0]; // first line node
  uint32_t n2 = tmesh->lines.node[2*cl+1]; // second line node

  // Check if point is close to one of the two line vertices 
  double *v1 = tmesh->vertices.coord + 4*n1;
  double *v2 = tmesh->vertices.coord + 4*n2;
  double *v0 = fmesh->vertices.coord + 4*cn;
  if (distance(v0,v1)<tolerance){
    flagV[n1] = cn;
    return HXT_STATUS_OK;
  }
  if (distance(v0,v2)<tolerance){
    flagV[n2] = cn;
    return HXT_STATUS_OK;
  }

  
  // Count number of adjacent triangles for this line
  uint64_t numAdjacentTriangles = 0;
  for (uint64_t i=0; i<maxNumTriToLine; i++){
    if (lines2triangles[maxNumTriToLine*cl+i] != UINT64_MAX)
      numAdjacentTriangles++;
  }

  // Get list of adjacent triangles for this line
  uint64_t adjacentTriangles[2*numAdjacentTriangles];
  for (uint64_t i=0; i<2*numAdjacentTriangles; i++) 
    adjacentTriangles[i] = UINT64_MAX;
  for (uint64_t i=0; i<numAdjacentTriangles; i++) 
    adjacentTriangles[i] = lines2triangles[maxNumTriToLine*cl+i];

  double *newpoint = fmesh->vertices.coord + 4*cn;
  uint32_t ne = UINT32_MAX;

  HXT_CHECK(hxtSplitBoundaryLine(tmesh, 
                                 edges, 
                                 ce,         // boundary edge to be splitted 
                                 newpoint,    // coords of new point (instead of parameter)
                                 numAdjacentTriangles,    // number of adjacent triangles
                                 adjacentTriangles, // adjacent triangles
                                 &ne         // new boundary edge (half line)
                                 ));


  // Change vertices of current line 
  tmesh->lines.node[2*cl+0] = edges->node[2*ce+0];
  tmesh->lines.node[2*cl+1] = edges->node[2*ce+1];

  // Create the new line
  tmesh->lines.node[2*tmesh->lines.num+0] = edges->node[2*ne+0];
  tmesh->lines.node[2*tmesh->lines.num+1] = edges->node[2*ne+1];
  tmesh->lines.colors[tmesh->lines.num] = tmesh->lines.colors[cl];
  uint64_t nl = tmesh->lines.num;
  tmesh->lines.num++;

  // Reassign vertices of current line 
  HXT_CHECK(reassignLineVertices(tmesh,
                                 fmesh,
                                 cl, 
                                 nl, // newline
                                 parent));

  // Reassign vertices of triangle pairs 
  for (uint64_t i=0; i<numAdjacentTriangles; i++){
    uint64_t trilist[2] = {adjacentTriangles[i], adjacentTriangles[i+numAdjacentTriangles]};
    HXT_CHECK(reassignTriangleVertices(tmesh,
                                       fmesh,
                                       data,
                                       trilist,
                                       2,
                                       tolerance,
                                       parent));
  }



  // Update edges2lines, lines2edges with new boundary edge
  edges2lines[ne] = nl;
  lines2edges[nl] = ne;

  // Update lines2triangles
  int counterCL = 0;
  int counterNL = 0;
  for (uint64_t i=0; i<2*numAdjacentTriangles; i++){
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*adjacentTriangles[i]+j];
      if (ce == lines2edges[cl]){
        lines2triangles[maxNumTriToLine*cl+counterCL] = adjacentTriangles[i];
        counterCL++;
        break;
      }
      if (ce == lines2edges[nl]){
        lines2triangles[maxNumTriToLine*nl+counterNL] = adjacentTriangles[i];
        counterNL++;
        break;
      }
    }
  }

  // TODO check this again
  // To fix lines2triangles for the case where we split a triangle with 2 adjacent lines
  // problem arised for example in: tet.msh - pyramide.msh - cube.msh (with only corners)
  for (uint64_t i=0; i<2*numAdjacentTriangles; i++){
    for (uint32_t j=0; j<3; j++){
      uint32_t e = edges->tri2edg[3*adjacentTriangles[i]+j];
      if (e == ce || e == ne) continue;
      if (edges2lines[e]==UINT64_MAX) continue;

      for (uint64_t k=0; k<maxNumTriToLine; k++){
        if (lines2triangles[maxNumTriToLine*edges2lines[e]+k] == UINT64_MAX) continue;
        if (lines2triangles[maxNumTriToLine*edges2lines[e]+k] == adjacentTriangles[(i+numAdjacentTriangles)%(2*numAdjacentTriangles)]){
          lines2triangles[maxNumTriToLine*edges2lines[e]+k] = adjacentTriangles[i];
        }
      }
      
    }
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
HXTStatus hxtSurfaceMeshInsertionSwap(HXTMesh *mesh,
                                      HXTMesh *fmesh,
                                      HXTEdges *edges,
                                      HXTPointGenParent *parent,
                                      uint64_t *edges2lines,
                                      uint64_t maxNumTriToLine,
                                      uint64_t *lines2triangles,
                                      void *data,
                                      double tolerance,
                                      double angle,
                                      int swapmax)
{

  int numSwapsOld = 0;
  for (int ii=0; ii<swapmax; ii++){
    int numSwaps = 0;
    for (uint32_t i = 0 ; i < edges->numEdges ; i++ ) {

      if (edges2lines[i] != UINT64_MAX) continue;

      //*************************************************************
      // TODO 
      // TO NOT COLLAPSE EDGES ADJACENT TO BOUNDARIES
      // QUICK FIX 
      // this is to not have a swap create a triangle that is 
      // onto or creates intersections with the adjacent triangles
      //*************************************************************
      {
        uint64_t t0 = edges->edg2tri[2*i+0];
        uint64_t t1 = edges->edg2tri[2*i+1];
        int b0 = 0;
        int b1 = 0;
        for (uint32_t k=0; k<3; k++){
          uint32_t e = edges->tri2edg[3*t0+k];
          if (edges2lines[e] != UINT64_MAX) b0 = 1;
        }
        if (t1 != UINT64_MAX){
          for (uint32_t k=0; k<3; k++){
            uint32_t e = edges->tri2edg[3*t1+k];
            if (edges2lines[e] != UINT64_MAX) b1 = 1;
          }
        }
        if (t1 == UINT64_MAX){
          b1 = 1;
        }
        if (b0 == 1 && b1 == 1) {
          continue;
        }
      }

      //*************************************************************
      // Swapping
      //*************************************************************
      int swapped = 0 ;
      HXT_CHECK(hxtSwapEdge(mesh, 
                            edges, 
                            NULL,
                            NULL, 
                            edges2lines,
                            maxNumTriToLine,
                            lines2triangles,
                            angle, 
                            i,
                            &swapped));
      numSwaps += swapped;

      //*************************************************************
      //*************************************************************
      // Do not rebuild structures if swap did not happen
      // Notice!
      //  in case we don't stop here if no swap maybe structures will change on the boundary!
      if (swapped == 0) continue;

      // Rebuilding edges2lines and lines2triangles
      uint64_t t0 = edges->edg2tri[2*i+0];
      uint64_t t1 = edges->edg2tri[2*i+1];
      if (t0 == UINT64_MAX || t1 == UINT64_MAX){ 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Insertion Swap edg2tri == UINT64_MAX");
      }
      if (t0 == t1) 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Insertion Swap same triangles for one edge");
      
      // TODO delete or debug mode
      if (mesh->triangles.colors[t0] == UINT16_MAX){ 
        FILE *dd;
        hxtPosInit("cannotCollapseSwap.pos", "Check", &dd);
        double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
        double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
        hxtPosAddLine(dd,v0,v1,t0);
        hxtPosFinish(dd);
        HXT_CHECK(hxtMeshWriteGmsh(mesh, "FINALMESHcannotSwap.msh"));
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Insertion Swap color of t0 == UINT64_MAX");
      }
      if (mesh->triangles.colors[t1] == UINT16_MAX){
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Insertion Swap color of t1 == UINT64_MAX");
      }

      for (uint32_t j=0; j<3; j++){
        uint32_t ce = edges->tri2edg[3*t0+j];
        if (edges2lines[ce] == UINT64_MAX) continue;
        uint64_t cl = edges2lines[ce];
        for (uint64_t k=0; k<maxNumTriToLine; k++){
          uint64_t ct = lines2triangles[maxNumTriToLine*cl+k];
          if (ct == t1) lines2triangles[maxNumTriToLine*cl+k] = t0;
        }
      }
      for (uint32_t j=0; j<3; j++){
        uint32_t ce = edges->tri2edg[3*t1+j];
        if (edges2lines[ce] == UINT64_MAX) continue;
        uint64_t cl = edges2lines[ce];
        for (uint64_t k=0; k<maxNumTriToLine; k++){
          uint64_t ct = lines2triangles[maxNumTriToLine*cl+k];
          if (ct == t0) lines2triangles[maxNumTriToLine*cl+k] = t1;
        }
      }

      //*************************************************************
      // Reassigning vertices contained on swapped triangles
      uint64_t trilist[2] = {t0,t1};
      HXT_CHECK(reassignTriangleVertices(mesh,
                                         fmesh,
                                         data,
                                         trilist,
                                         2,
                                         tolerance,
                                         parent));

    }

    /*char buffer[32];*/
    /*snprintf(buffer,sizeof(char)*32,"FINALMESH_%i.msh",(int)ii);*/
    /*HXT_CHECK(hxtMeshWriteGmsh(mesh, buffer));*/

    printf("%d - Number of swaps in insertion %d \n", ii, numSwaps);
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
HXTStatus hxtSurfaceMesh(HXTPointGenOptions *opt,
                         HXTMesh *mesh,
                         HXTEdges *edges,
                         HXTPointGenParent *parent,
                         HXTMesh *fmesh,
                         HXTMesh *nmesh)
{

  printf("\n===================================\n");
  printf("      SURFACE MESHING \n\n");

  uint32_t numInitialVertices   = mesh->vertices.num;
  uint32_t numGeneratedVertices = fmesh->vertices.num;
  uint32_t numTotalVertices     = numInitialVertices + numGeneratedVertices; 
  
  uint32_t numGeneratedVerticesOnCorners = 0;
  uint32_t numGeneratedVerticesOnLines   = 0;
  uint32_t numGeneratedVerticesInterior  = 0;

  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 15) numGeneratedVerticesOnCorners++;
    if (parent[i].type ==  1) numGeneratedVerticesOnLines++;
    if (parent[i].type ==  2) numGeneratedVerticesInterior++;
  }

  // We consider that all the generated points will either split a triangle 
  // or an edge, and thus each point will create at maximum:
  //    1 new vertex, 2 new triangles, 3 new edges
  // In practice, generated points may just replace already existing ones
  // or be on a boundary edge and just create 1 new triangle and 2 new edges
  // Furthermore, for non-manifold triangulations a boundary edge split 
  // can create more than 2 new triangles or 3 new edges
  // so weaccount for that by using maxNumTriToLine
  
  // Count maximum number of triangles adjacent to a line (i.e. boundary edge)
  uint64_t maxNumTriToLine = 0; // maximum number of triangles adjacent to a line
  HXT_CHECK(hxtCountMaxNumberOfTrianglesToEdges(edges,&maxNumTriToLine));
  
  uint32_t maxNumSplits    = numTotalVertices;
  uint32_t maxNumVertices  =   maxNumSplits;
  uint64_t maxNumTriangles = 2*maxNumSplits + maxNumTriToLine*numGeneratedVerticesOnLines;
  uint32_t maxNumEdges     = 3*maxNumSplits + maxNumTriToLine*numGeneratedVerticesOnLines;
  // The maximum number of new mesh lines can be estimated as:
  uint32_t maxNumLines = mesh->lines.num + numGeneratedVerticesOnLines;

  printf("  Number of initial mesh vertices:     %d  \n", numInitialVertices);
  printf("  Number of initial mesh triangles:    %lu \n", mesh->triangles.num);
  printf("  Number of initial mesh edges:        %d  \n", edges->numEdges);
  printf("  Number of initial boundary lines:    %lu \n", mesh->lines.num);
  printf("\n");
  printf("  Generated mesh vertices on lines:    %d  \n", numGeneratedVerticesOnLines);
  printf("  Generated mesh vertices on corners:  %d  \n", numGeneratedVerticesOnCorners);
  printf("  Generated mesh vertices interior:    %d  \n", numGeneratedVerticesInterior);
  printf("  Generated mesh vertices TOTAL:       %d  \n", numGeneratedVertices);
  printf("  Allocated final mesh vertices:       %d  \n", fmesh->vertices.size);
  printf("\n");
  printf("  Estimated total mesh vertices        %d  \n",  numTotalVertices);
  printf("  Estimated number of triangles        %lu \n",  2*(uint64_t)numTotalVertices);
  printf("  Estimated number of edges            %d  \n",  3*numTotalVertices);
  printf("\n");

  //***********************************************************************************************
  // Transfer triangles and vertices of initial mesh to intermediate mesh tmesh
  //***********************************************************************************************
  printf("- Transfering initial mesh to temp mesh \n");

  HXTContext *context;
  HXT_CHECK(hxtContextCreate(&context));
  HXTMesh *tmesh;
  HXT_CHECK(hxtMeshCreate(context,&tmesh));
  HXT_CHECK(hxtTransferInitialMeshToTempMesh(mesh,
                                             numInitialVertices,
                                             maxNumVertices,
                                             maxNumTriangles,
                                             maxNumEdges,
                                             maxNumLines,
                                             tmesh,
                                             edges));

  //***********************************************************************************************
  // Create list of colors of triangles
  //***********************************************************************************************
  // TODO not used - delete
  printf("- Create list of colors \n");

  uint16_t *triColors;
  uint16_t numTriColors;
  HXT_CHECK(hxtGetTrianglesColorsList(tmesh,&numTriColors,&triColors));
  printf("    Number of colors:  %d \n", numTriColors);

  //***********************************************************************************************
  // Create lines to edges array; 
  //***********************************************************************************************
  printf("- Create lines to edges \n");

  uint32_t *lines2edges;
  HXT_CHECK(hxtMalloc(&lines2edges,maxNumLines*sizeof(uint32_t)));
  for (uint32_t i=0; i<maxNumLines; i++) lines2edges[i] = UINT32_MAX;
  HXT_CHECK(hxtGetLinesToEdges(edges,lines2edges));

  //***********************************************************************************************
  // Create edges to lines array;
  //***********************************************************************************************
  printf("- Create edges to lines \n");

  uint64_t *edges2lines;
  HXT_CHECK(hxtMalloc(&edges2lines,maxNumEdges*sizeof(uint64_t)));
  for (uint32_t i=0; i<maxNumEdges; i++) edges2lines[i] = UINT64_MAX;
  HXT_CHECK(hxtGetEdgesToLines(edges,lines2edges,edges2lines));

  //***********************************************************************************************
  // Create lines to triangles array
  // This is used to handle non-manifold triangulations
  // where mesh lines can have more than 2 triangles
  //***********************************************************************************************
  printf("- Create lines to triangles \n");

  uint64_t *lines2triangles;
  HXT_CHECK(hxtMalloc(&lines2triangles,maxNumTriToLine*tmesh->lines.size*sizeof(uint64_t)));
  for (uint64_t i=0; i<maxNumTriToLine*tmesh->lines.size; i++) lines2triangles[i] = UINT64_MAX;
  HXT_CHECK(hxtGetLinesToTriangles(edges,maxNumTriToLine,edges2lines,lines2triangles));
  printf("    Number of max tri to line:  %lu \n", maxNumTriToLine);


  //***********************************************************************************************
  // Create RTree with all generated points
  // We use this to find the vertices that are contained in each triangle
  // It is not updated (no new vertices are inserted) 
  //***********************************************************************************************
  printf("- Create RTree \n");

  double boxSmall = 10e-16;
  void* data;
  HXT_CHECK(hxtRTreeCreate(&data));
  // Add line points in RTree
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == UINT8_MAX || parent[i].id == UINT64_MAX){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"No parent for generated point");
    }
    double *cp = fmesh->vertices.coord + 4*i; 
    double cpmin[3] = {cp[0]-boxSmall, cp[1]-boxSmall, cp[2]-boxSmall};
    double cpmax[3] = {cp[0]+boxSmall, cp[1]+boxSmall, cp[2]+boxSmall};
    hxtRTreeInsert(cpmin,cpmax,i,data); 
  }




  //***********************************************************************************************
  // Insert generated points in triangulation
  //***********************************************************************************************
 
  uint32_t countPointsOnCorners = 0;
  uint32_t countPointsOnLines = 0;
  uint32_t countPointsOnBoundaryVertices = 0;
  uint32_t countPointsOnLineVertices = 0;
  uint32_t countPointsOnTriangles = 0;
  uint32_t countPointsOnVerticesTotal = 0;
  uint32_t countPointsOnTriangleVertices = 0;

  double tolerance = 10e-6; // TODO add on options 

  // Create array to flag vertices to be inserted 
  //  size = mesh->vertices.num + fMesh->vertices.num
  // - UINT32_MAX to remove vertex
  // - num of vertex in fmesh to insert
  uint32_t *flagV; 
  HXT_CHECK(hxtMalloc(&flagV,numTotalVertices*sizeof(uint32_t)));
  for (uint32_t i=0; i<numInitialVertices; i++) flagV[i] = UINT32_MAX;
  for (uint32_t i=numInitialVertices; i<numTotalVertices; i++) flagV[i] = i-numInitialVertices;

  //***********************************
  // Loop over generate vertices
  // Insert points on corners
  // Insert points on lines 
  //***********************************
  printf("\n  -------------------------------------------------\n");
  printf(  "    Insert points on corners and lines \n");

  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 2) continue;

    //***********************************
    // Corner points
    //***********************************
    if (parent[i].type == 15){

      // Check if distance is correct
      // TODO delete or debug mode
      double *v0 = tmesh->vertices.coord + 4*parent[i].id;
      double *v1 = fmesh->vertices.coord + 4*i;
      double dist = distance(v0,v1);
      if (dist>tolerance) 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Point Distance = %e Tolerance = %e",dist,tolerance);

      // Flag the initial coinciding corner vertex
      uint32_t initialPoint = parent[i].id;
      flagV[initialPoint] = i;
      countPointsOnCorners++;
    }

    //***********************************
    // Line points
    //***********************************
    if (parent[i].type == 1){

      // Check if distance is correct
      // TODO delete or debug mode
      uint32_t cl = parent[i].id;
      double *p1 = tmesh->vertices.coord + 4*tmesh->lines.node[2*cl+0];
      double *p2 = tmesh->vertices.coord + 4*tmesh->lines.node[2*cl+1];
      double *pn = fmesh->vertices.coord + 4*i;
      double dist = -1.;
      double alpha = -1.;
      double closePt[3] = {0.};
      HXT_CHECK(hxtSignedDistancePointEdge(p1,p2,pn,&dist,&alpha,closePt));
      if (dist>tolerance) 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Point %d Line Distance = %e Tolerance = %e",i,dist,tolerance);


      // Insert point in triangulation
      HXT_CHECK(hxtSurfaceMeshInsertLineVertex(tmesh,
                                               fmesh,
                                               edges,
                                               parent,
                                               data,
                                               tolerance, 
                                               lines2edges,
                                               edges2lines,
                                               maxNumTriToLine,
                                               lines2triangles,
                                               i,
                                               flagV)); 
 
      countPointsOnLines++;

    }
  }


  // TODO delete or debug mode
  // check if flagV is correct
  for (uint32_t i=0; i<numInitialVertices; i++){
    if (flagV[i] == UINT32_MAX) continue;
    double *p0 = tmesh->vertices.coord + 4*i;
    double *p1 = fmesh->vertices.coord + 4*flagV[i];
    if (fabs(distance(p0,p1)) > tolerance) return HXT_STATUS_ERROR;
    countPointsOnBoundaryVertices++;
    if (parent[flagV[i]].type != 15) countPointsOnLineVertices++;
  }

  // TODO delete or debug
  // checking triangles area 
  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    double *v0 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*i+0];
    double *v1 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*i+1];
    double *v2 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*i+2];
    double normals[3];
    normal2triangleAreaV(v0,v1,v2,normals);
    double area  = norm(normals)/2.;
    if (area<10e-16){
      FILE *lt;
      hxtPosInit("triangleWithZeroArea.pos", "Check", &lt); 
      hxtPosAddTriangle(lt,v0,v1,v2,tmesh->triangles.colors[i]);
      hxtPosFinish(lt);
      HXT_CHECK(hxtMeshWriteGmsh(tmesh,"FINALMESHtriangleWithZeroArea.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Triangle with zero area %lu %lu - %.16f",i, i+tmesh->points.num+tmesh->lines.num+1,area);
    }
  }

  HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH0lines.msh"));

  //***********************************
  // Swapping after insertion 
  // of points on lines
  //***********************************
  printf("\n  -------------------------------------------------\n");
  printf(  "    Swaps after insertion on lines \n");

  HXT_CHECK(hxtSurfaceMeshInsertionSwap(tmesh,
                                        fmesh,
                                        edges,
                                        parent,
                                        edges2lines,
                                        maxNumTriToLine,
                                        lines2triangles,
                                        data,
                                        tolerance,
                                        0.99,
                                        0));


  HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH1lines_swap.msh"));

  //***********************************
  // Loop over generate vertices
  // Insert interior points
  //***********************************
  printf("\n  -------------------------------------------------\n");
  printf(  "    Insert points on interior \n");

  for (uint32_t i=0; i<fmesh->vertices.num; i++){

    if (parent[i].type == 1 || parent[i].type == 15) continue;

    // Insert point in triangulation
    HXT_CHECK(hxtSurfaceMeshInsertInteriorVertex(tmesh,
                                                 fmesh,
                                                 edges,
                                                 parent,
                                                 data,
                                                 tolerance,
                                                 edges2lines,
                                                 maxNumTriToLine,
                                                 lines2triangles,
                                                 i,
                                                 flagV));

    countPointsOnTriangles++;

  }
  HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH2interior.msh"));

  // TODO delete or debug
  // checking if initial points to remain are correct
  for (uint32_t i=0; i<numInitialVertices; i++){
    if (flagV[i] == UINT32_MAX) continue;
    double *p0 = tmesh->vertices.coord + 4*i;
    double *p1 = fmesh->vertices.coord + 4*flagV[i];
    if (fabs(distance(p0,p1)) > tolerance) return HXT_STATUS_ERROR;
    countPointsOnVerticesTotal++;
    if(parent[flagV[i]].type == 2) countPointsOnTriangleVertices++;
  }

  // TODO delete or debug
  // checking triangles area 
  for (uint64_t i=0; i<tmesh->triangles.num; i++){
    double *v0 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*i+0];
    double *v1 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*i+1];
    double *v2 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*i+2];
    double normals[3];
    normal2triangleAreaV(v0,v1,v2,normals);
    double area  = norm(normals)/2.;
    if (area<10e-12){
      FILE *lt;
      hxtPosInit("triangleWithZeroArea.pos", "Check", &lt); 
      hxtPosAddTriangle(lt,v0,v1,v2,tmesh->triangles.colors[i]);
      hxtPosFinish(lt);
      HXT_CHECK(hxtMeshWriteGmsh(tmesh,"FINALMESHtriangleWithZeroArea.msh"));
      //return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Triangle with zero area %lu %lu - %.16f",i, i+tmesh->points.num+tmesh->lines.num+1,area);
    }

  }

  // TODO check this problem
  // during insertions and swaps lines2triangles is not updated 
  if(0){
    FILE *lt;
    hxtPosInit("checkingLinesToTriangles.pos", "Check", &lt); 
    for (uint64_t i=0; i<tmesh->lines.num; i++){
      uint64_t cl = i;

      for (uint64_t j=0; j<maxNumTriToLine; j++){
        uint64_t ct = lines2triangles[maxNumTriToLine*cl+j];
        if (ct == UINT64_MAX) continue;

        double *v0 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*ct+0];
        double *v1 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*ct+1];
        double *v2 = tmesh->vertices.coord + 4*tmesh->triangles.node[3*ct+2];
        hxtPosAddTriangle(lt,v0,v1,v2,tmesh->triangles.colors[ct]);
      }
    }
    hxtPosFinish(lt);
  }

  //***********************************
  // Swapping
  //***********************************
  printf("\n  -------------------------------------------------\n");
  printf(  "    Swapping after insertion of points \n\n");



  HXT_CHECK(hxtSurfaceMeshInsertionSwap(tmesh,
                                        fmesh,
                                        edges,
                                        parent,
                                        edges2lines,
                                        maxNumTriToLine,
                                        lines2triangles,
                                        data,
                                        tolerance,
                                        0.99,
                                        100));


  HXT_CHECK(hxtMeshWriteGmsh(tmesh, "FINALMESH3interiorswap.msh"));

  //HXT_CHECK(hxtCheckEdgesAndMesh(tmesh,edges));

  //***********************************
  // COUNTING THINGS TODO delete
  //***********************************
  uint32_t countVerticesToRemove = 0;
  for (uint32_t i=0; i<numTotalVertices; i++){
    if (flagV[i] == UINT32_MAX) countVerticesToRemove++;
  }


  printf("\n");
  printf("  Generated mesh vertices:                    %d  \n", numGeneratedVertices);
  printf("  Generated mesh vertices on lines:           %d  \n", numGeneratedVerticesOnLines);
  printf("  Generated mesh vertices on corners:         %d  \n", numGeneratedVerticesOnCorners);
  printf("  Generated mesh vertices interior:           %d  \n", numGeneratedVerticesInterior);
  printf("  Vertices to be removed                      %d  \n", countVerticesToRemove);
  printf("\n");
  printf("  Number of corner points:                    %d \n", countPointsOnCorners);
  printf("  Number of points on line vertices:          %d \n", countPointsOnLineVertices);
  printf("  Number of all points on boundary vertices:  %d \n", countPointsOnBoundaryVertices);
  printf("  Number of line points (without corners):    %d \n", countPointsOnLines);
  printf("  Number of points on triangles:              %d \n", countPointsOnTriangles);
  printf("  Number of all points on vertices:           %d \n", countPointsOnVerticesTotal);
  printf("  Number of points on triangle vertices:      %d \n", countPointsOnTriangleVertices);
  printf("\n");
  printf("  Initial mesh lines:                         %lu \n", mesh->lines.num);
  printf("  Final mesh lines:                           %lu \n", fmesh->lines.num);
  printf("  Temp mesh lines:                            %lu \n", tmesh->lines.num);
  printf("  Edges num:                                  %d  \n", edges->numEdges);
  printf("\n");

  //***********************************************************************************************
  // COLLAPSE
  //***********************************************************************************************
  
  // Create the new parent structure
  HXTPointGenParent *tparent;
  HXT_CHECK(hxtMalloc(&tparent,tmesh->vertices.num*sizeof(HXTPointGenParent)));
  for (uint32_t i=0; i<tmesh->vertices.num; i++) tparent[i].type = UINT8_MAX;
  for (uint32_t i=0; i<tmesh->vertices.num; i++) tparent[i].id = UINT64_MAX;
  HXT_CHECK(hxtCreateParentStructure(mesh,fmesh,tmesh,parent,tparent));

  uint32_t countVolumeVerticesToRemove = 0;
  for (uint32_t i=0; i<tmesh->vertices.num; i++){
    if (tparent[i].type == 4) countVolumeVerticesToRemove++;
  }

  printf("  Total Vertices to be removed                %d  \n", countVerticesToRemove);
  printf("  Volume Vertices to be removed               %d  \n", countVolumeVerticesToRemove);
  printf("  Surface Vertices to be removed              %d  \n", countVerticesToRemove-countVolumeVerticesToRemove);

  clock_t time0 = clock();
  HXT_CHECK(hxtSurfaceMeshCollapse(opt,
                                   tmesh,
                                   nmesh,
                                   edges,
                                   tparent,
                                   flagV));

  clock_t time1 = clock();
  double time_estimate = (double)(time1-time0) / CLOCKS_PER_SEC;
  printf("TIME FOR COLLAPSE = %f \n", time_estimate);

  //***********************************************************************************************
  // Clear things 
  //***********************************************************************************************
  
  HXT_CHECK(hxtFree(&tparent));

  HXT_CHECK(hxtMeshDelete(&tmesh));
  HXT_CHECK(hxtContextDelete(&context));
  
  HXT_CHECK(hxtFree(&flagV));
  HXT_CHECK(hxtRTreeDelete(&data));


  // TODO free those before collapse since we recreate them anyway 
  HXT_CHECK(hxtFree(&lines2edges));
  HXT_CHECK(hxtFree(&edges2lines));
  HXT_CHECK(hxtFree(&lines2triangles));
  HXT_CHECK(hxtFree(&triColors));

  return HXT_STATUS_OK;
}


