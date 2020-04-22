#include "hxt_collapse_edge.h"

#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"


//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
// TODO delete or debug 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtTempPrintCavity (HXTMesh *mesh,
                              HXTEdges* edges,
                              uint64_t cavSize,
                              uint64_t *cavity,
                              uint64_t *neighs,
                              uint32_t vd,
                              uint64_t currentTri,
                              uint32_t ce)
{
  char buffer[32];
  snprintf(buffer,sizeof(char)*32,"tc/fm_%06i_%06i.pos",(int)vd,(int)currentTri);
  FILE *tc;
  hxtPosInit(buffer,"check",&tc);
  hxtPosAddLine(tc,&mesh->vertices.coord[4*edges->node[2*ce+0]],&mesh->vertices.coord[4*edges->node[2*ce+1]],0);
  hxtPosNewView(tc,"Cavity");

  for (uint64_t i=0; i<cavSize; i++){
    if (mesh->triangles.colors[cavity[i]] == UINT16_MAX) continue;
    uint64_t ct = cavity[i];
    uint32_t *n = &mesh->triangles.node[3*ct+0]; 
    hxtPosAddTriangle(tc,&mesh->vertices.coord[4*n[0]],&mesh->vertices.coord[4*n[1]],&mesh->vertices.coord[4*n[2]],0);
  }

  hxtPosNewView(tc,"neighs");
  for (uint64_t i=0; i<cavSize; i++){
    uint64_t neigh = neighs[i];
    uint32_t *n = &mesh->triangles.node[3*neigh+0]; 
    hxtPosAddTriangle(tc,&mesh->vertices.coord[4*n[0]],&mesh->vertices.coord[4*n[1]],&mesh->vertices.coord[4*n[2]],0);
    double normals1[3];
    normal2triangle(mesh,neigh,normals1);
    normalize(normals1);
  }
  hxtPosFinish(tc);

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION 
//
// Check if edge is oriented in this triangle
//
//*************************************************************************************************
//*************************************************************************************************
inline int isEdgeOrientedInTriangle (HXTMesh *mesh, 
                              HXTEdges *edges, 
                              uint64_t ct, 
                              uint32_t ce)
{
  int flag = 0;
  for (uint32_t i=0; i<3; i++){
    if (edges->tri2edg[3*ct+i] == ce){
      flag = 1;
      if(edges->node[2*ce+0] == mesh->triangles.node[3*ct+i] &&
         edges->node[2*ce+1] == mesh->triangles.node[3*ct+(i+1)%3]) return 1;
    }
  }
  if (flag == 0){
    printf("Edge %d not in triangle %lu\n", ce,ct);
    return -1;
  }

  return 0; 
}

//***************************************************************************************
//***************************************************************************************
//
// FUNCTION sort an array of edges by length
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtPointGenSort(HXTEdges *edges, uint32_t num, uint32_t *list, uint32_t *sortedList)
{
  struct str{
    double value;
    uint32_t index;
  };

  HXTMesh *mesh = edges->edg2mesh;

  struct str lengths[num];
  
  for (uint32_t i=0; i<num; i++){
    lengths[i].value = -1;
    lengths[i].index = UINT32_MAX;
  }

  for (uint32_t i=0; i<num; i++){
    uint32_t v0 = edges->node[2*list[i]+0];
    uint32_t v1 = edges->node[2*list[i]+1];
    lengths[i].value = distance(&mesh->vertices.coord[4*v0],&mesh->vertices.coord[4*v1]);
    lengths[i].index = list[i];
  }

  for (uint32_t i=0; i<num; i++){
    for (uint32_t j=0; j<num; j++){
      if (lengths[j].value < lengths[i].value){
        struct str tmp = lengths[i];
        lengths[i] = lengths[j];
        lengths[j] = tmp;
      }
    }
  }

  for (uint32_t i=0; i<num; i++){
    sortedList[i] = lengths[i].index;
  }

  return HXT_STATUS_OK;
}


//***************************************************************************************
//***************************************************************************************
static inline uint64_t cavMod(uint64_t a, uint64_t b) {
  if (a == UINT64_MAX) a = b-1;
  const uint64_t result = a % b;
  //return result >= 0 ? result : result + b;
  return result;
}


//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCanWeCollapseBoundaryCavity (HXTMesh *mesh, 
                                          HXTEdges *edges, 
                                          HXTPointGenParent *parent,
                                          uint32_t *lines2edges,
                                          uint64_t *edges2lines,
                                          uint64_t *lines2triangles,
                                          uint64_t maxNumTriToLine,
                                          uint64_t *vertices2lines,
                                          uint64_t maxNumLinesToVertex,
                                          uint64_t cavSize, 
                                          uint64_t *cavity, 
                                          uint32_t vd,     // node to be removed
                                          uint64_t currentTri, // triangle to be deleted
                                          uint32_t ce,     // edge to be collapsed
                                          int *canWeCollapse)
{
  HXT_UNUSED(lines2edges);
  HXT_UNUSED(vertices2lines);
  HXT_UNUSED(maxNumLinesToVertex);
  
  double dotThreshold = 0.5; // TODO attention 

  // The other node of the edge
  uint64_t vr = (edges->node[2*ce+0] == vd) ? edges->node[2*ce+1] : edges->node[2*ce+0];
  if (parent[vr].type != 1 && parent[vr].type != 15) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Vertex is not on boundary");

  //=====================================================================================
  // Create an array with the perimeter edges of the fan (cavity)
  //=====================================================================================
  uint32_t perimSize = 0;
  uint32_t perim[cavSize+2];
  HXT_CHECK(hxtBoundaryVertexFanPerimeter(mesh,edges,vd,currentTri,ce,edges2lines,&perimSize,perim));
  if (perimSize != cavSize+2) return HXT_STATUS_ERROR;
  if (currentTri != cavity[0]) return HXT_STATUS_ERROR;

  // Find remaining triangle in position of currentTri
  uint64_t rt = cavity[1];

  //=====================================================================================
  // Create an array with resulting triangles after collapse
  //=====================================================================================
  uint32_t cavityNew[3*cavSize];
  for (uint64_t i=0; i<cavSize; i++){
    uint64_t ct = cavity[i];
    // Replace deleted triangles
    if (ct == currentTri) ct = rt;
    uint32_t *nod = mesh->triangles.node +3*ct;
    cavityNew[3*i+0] = nod[0] == vd ? vr : nod[0];
    cavityNew[3*i+1] = nod[1] == vd ? vr : nod[1];
    cavityNew[3*i+2] = nod[2] == vd ? vr : nod[2];
  }

  //=====================================================================================
  // Loop over triangles and check
  //=====================================================================================
  for (uint64_t i=0; i<cavSize; i++){
    uint64_t ct = cavity[i];

    // Replace deleted triangles
    if (ct == currentTri) ct = rt;

    // Normal of original triangle
    double normal0area[3];
    normal2triangleArea(mesh,ct,normal0area);
    double normal0[3] = {normal0area[0],normal0area[1],normal0area[2]};
    normalize(normal0);

    // Create new triangle 
    uint32_t *nod = &cavityNew[3*i];

    // Normal of new triangle
    double normal1area[3];
    normal2triangleAreaV(&mesh->vertices.coord[4*nod[0]],
                         &mesh->vertices.coord[4*nod[1]],
                         &mesh->vertices.coord[4*nod[2]],normal1area);
    double normal1[3] = {normal1area[0],normal1area[1],normal1area[2]};
    normalize(normal1);

    //********************************************
    // Check if triangle is flipped
    if (myDot(normal0,normal1) < 0.0){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }

    //********************************************
    // Check area of triangle
    // TODO which threshold  
    //double area0 = norm(normal0area)/2.;
    double area1 = norm(normal1area)/2.;
    double areaThres = 10e-9;
    if (area1 < areaThres){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }


    //********************************************
    // Check normals between new triangles
    uint64_t next = (i+1)%cavSize;
    uint32_t *nodN = &cavityNew[3*next];
    double normal2[3];
    normal2triangleV(&mesh->vertices.coord[4*nodN[0]],
                     &mesh->vertices.coord[4*nodN[1]],
                     &mesh->vertices.coord[4*nodN[2]],normal2);
    if (myDot(normal1,normal2) < -dotThreshold && i != cavSize-1){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }


    //********************************************
    // Take neigh triangle(s) from corresponding perimeter edge
    //  A. Interior edge
    //  B. Boundary edge (line)
    
    uint32_t count = 1;
    uint32_t edg[2] = {perim[i+1],UINT32_MAX};

    // If it's one of the triangles adjacent to the boundary
    // they have two perimeter edges 
    if (i == 0){
      edg[0] = perim[0];
      edg[1] = perim[1];
      count = 2;
    }
    if (i == cavSize-1){
      edg[0] = perim[perimSize-1];
      edg[1] = perim[perimSize-2];
      count = 2;
    }

    for (uint32_t k=0; k<count; k++){
      uint32_t ce = edg[k];
      if (edges2lines[ce] == UINT64_MAX){
        uint64_t nt = edges->edg2tri[2*ce+0] == cavity[i] ? edges->edg2tri[2*ce+1] : edges->edg2tri[2*ce+0];
        double normal3[3];
        normal2triangle(mesh,nt,normal3);
        if (myDot(normal1,normal3) < -dotThreshold){
          *canWeCollapse = 0;
          return HXT_STATUS_OK;
        }
      }
      else if (edges2lines[ce] != UINT64_MAX){
        // Check for boundary edges (lines)
        uint64_t cl = edges2lines[ce];

        // Loop over neigh triangles
        for (uint64_t j=0; j<maxNumTriToLine; j++){
          uint64_t ct = lines2triangles[maxNumTriToLine*cl+j];
          if (ct == UINT64_MAX) continue;
          if (ct == cavity[i]) continue;

          double normal3[3];
          normal2triangle(mesh,ct,normal3);

          // Non-manifold case
          int is0 = isEdgeOrientedInTriangle(mesh,edges,cavity[i],ce);
          int is1 = isEdgeOrientedInTriangle(mesh,edges,ct,ce);
          if (is0 == -1 ){
            printf("%d %d \n", count, ce);
            return HXT_STATUS_ERROR;
          }

          if (is0 == is1 ){ 
            if (myDot(normal1,normal3) > dotThreshold){
              *canWeCollapse = 0;
              return HXT_STATUS_OK;
            }
          }
          else{
            if (myDot(normal1,normal3) < -dotThreshold){
              *canWeCollapse = 0;
              return HXT_STATUS_OK;
            }
          }
        }
      }
    }
  }

  return HXT_STATUS_OK;
}

//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCanWeCollapseBoundaryEdge (HXTMesh *mesh, 
                                        HXTEdges *edges, 
                                        HXTPointGenParent *parent,
                                        uint32_t *lines2edges,
                                        uint64_t *edges2lines,
                                        uint64_t *lines2triangles,
                                        uint64_t maxNumTriToLine,
                                        uint64_t *vertices2lines,
                                        uint64_t maxNumLinesToVertex,
                                        uint32_t vd,     // node to be removed
                                        uint32_t ce,     // edge to be collapsed
                                        uint64_t cl,     // corresponding line
                                        int *canWeCollapse)
{
  // Count adjacent triangles
  int countTri = 0;
  for (uint64_t j=0; j<maxNumTriToLine; j++){
    uint64_t ct = lines2triangles[maxNumTriToLine*cl+j];
    if (ct == UINT64_MAX) continue;
    countTri++;
  }

  uint64_t cavSize = 0;
  uint64_t cavity[1000];

  int collapse = 1;

  // For all adjacent triangles build corresponding "half"-cavity
  for (uint64_t k=0; k<maxNumTriToLine; k++){
    uint64_t ct = lines2triangles[maxNumTriToLine*cl+k];
    if (ct == UINT64_MAX) continue;

    // TODO delete or debug
    if (mesh->triangles.colors[ct] == UINT16_MAX){
      hxtMeshWriteGmsh(mesh,"checkDeletedTri.msh");
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Deleted tri %lu", ct+mesh->lines.num+mesh->points.num+1);
    }

    // Build cavity
    HXT_CHECK(hxtBoundaryVertexCavity(mesh, edges, vd, ct, ce, edges2lines, &cavSize, cavity));

 
    // TODO 
    // DO NOT collapse if one of 'half'cavities contain only one element (corner-type situation)
    // should be fixed with swaps
    if (cavSize == 1){
      *canWeCollapse = 0;
      return HXT_STATUS_OK; 
    }

    // Check if we can collapse cavity
    HXT_CHECK(hxtCanWeCollapseBoundaryCavity(mesh, 
                                             edges, 
                                             parent, 
                                             lines2edges,
                                             edges2lines,
                                             lines2triangles,
                                             maxNumTriToLine,
                                             vertices2lines,
                                             maxNumLinesToVertex,
                                             cavSize, 
                                             cavity, 
                                             vd, 
                                             ct,
                                             ce,
                                             &collapse));
    if (collapse == 0){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }
  }

  *canWeCollapse = 1;

 

  return HXT_STATUS_OK;
}


//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCanWeCollapseBoundaryVertex(HXTMesh *mesh,
                                         HXTEdges *edges,
                                         HXTPointGenParent *parent,
                                         uint32_t *lines2edges,
                                         uint64_t *edges2lines,
                                         uint64_t *lines2triangles,
                                         uint64_t maxNumTriToLine,
                                         uint64_t *vertices2lines,
                                         uint64_t maxNumLinesToVertex,
                                         uint32_t vd,  // vertex to be removed
                                         uint32_t *edgeToCollapse ) // return edge to be collapsed
{

  // Loop over the TWO adjacent boundary edges (lines)
  for (uint64_t i=0; i<maxNumLinesToVertex; i++){
    uint64_t cl = vertices2lines[maxNumLinesToVertex*vd+i];
    if (cl == UINT64_MAX) continue;
    if (i>1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Trying to collapse feature point");
    uint32_t ce = lines2edges[cl];

    // TODO debug mode assert 
    if (vd != edges->node[2*ce+0] && vd != edges->node[2*ce+1]){ 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Boundary vertex not on edge");
    }

    int canWeCollapse = 0;
    HXT_CHECK(hxtCanWeCollapseBoundaryEdge (mesh, 
                                            edges, 
                                            parent,
                                            lines2edges,
                                            edges2lines,
                                            lines2triangles,
                                            maxNumTriToLine,
                                            vertices2lines,
                                            maxNumLinesToVertex,
                                            vd,     // node to be removed
                                            ce,     // edge to be collapsed
                                            cl,     // corresponding line
                                            &canWeCollapse));

    if (canWeCollapse == 1){
      *edgeToCollapse = ce;
      return HXT_STATUS_OK;
    }
  }

  return HXT_STATUS_OK;
}


//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCanWeCollapseInteriorEdge(HXTMesh *mesh, 
                                       HXTEdges *edges, 
                                       HXTPointGenParent *parent,
                                       uint32_t *lines2edges,
                                       uint64_t *edges2lines,
                                       uint64_t *lines2triangles,
                                       uint64_t maxNumTriToLine,
                                       uint64_t *vertices2lines,
                                       uint64_t maxNumLinesToVertex,
                                       uint64_t cavSize, 
                                       uint64_t *cavity, 
                                       uint32_t vd,     // node to be removed
                                       uint64_t currentTri,     // current triangle
                                       uint32_t ce,     // edge to be collapsed
                                       int *canWeCollapse)
{
  HXT_UNUSED(parent);
  HXT_UNUSED(lines2edges);
  HXT_UNUSED(vertices2lines);
  HXT_UNUSED(maxNumLinesToVertex);

  double dotThreshold = 0.5; // TODO attention 
  
  // Triangles that will be deleted
  uint64_t t0 = edges->edg2tri[2*ce+0];
  uint64_t t1 = edges->edg2tri[2*ce+1];
  
  if (edges->node[2*ce+0] != vd && edges->node[2*ce+1] != vd) 
    return(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Node %d is not in edge %d ", vd,ce));
  
  // The vertex onto which vd will collapse
  uint64_t vr = (edges->node[2*ce+0] == vd) ? edges->node[2*ce+1] : edges->node[2*ce+0];

  //=====================================================================================
  // Create an array with the perimeter edges of the fan (cavity)
  //=====================================================================================
  uint32_t perimSize = 0;
  uint32_t perim[cavSize];
  HXT_CHECK(hxtVertexFanPerimeter(mesh,edges,vd,currentTri,&perimSize,perim));
  if (perimSize != cavSize) return HXT_STATUS_ERROR;
 
  /*int isBoundary =0;*/
  /*for (uint32_t i=0; i<perimSize; i++){*/
    /*if (edges2lines[perim[i]] != UINT64_MAX) isBoundary = 1;*/
  /*}*/


  //=====================================================================================
  // Find the corresponding remaining triangles
  //
  // Cavity: |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
  //                  tt0   t0    t1    tt1        
  //
  //    OR                       tt1    t1    t0    tt0    
  //
  //    ETC
  //=====================================================================================
  uint64_t tt0 = UINT64_MAX;
  uint64_t tt1 = UINT64_MAX;
  for (uint64_t i=0; i<cavSize; i++){
    uint64_t ct = cavity[i];
    if (ct == t0){
      uint64_t ind0 = cavMod(i-1,cavSize);
      uint64_t ind1 = (i+1)%cavSize;
      if      (t1 == cavity[ind0]){
        tt0 = cavity[(i+1)%cavSize];
        tt1 = cavity[cavMod(ind0-1,cavSize)];
      }
      else if (t1 == cavity[ind1]){
        tt0 = cavity[cavMod(i-1,cavSize)];
        tt1 = cavity[(ind1+1)%cavSize];
      }
      else{
        return HXT_STATUS_ERROR;
      }
    }
  }



  //=====================================================================================
  // PRINT TODO DELETE
  //=====================================================================================

if (0){

  // Create an array with the neigh triangles surrounding the caviy
  uint64_t neighs[cavSize];
  for (uint64_t i=0; i<cavSize; i++) neighs[i] = UINT64_MAX;
  uint64_t numNeighs = 0;

  // Find neighs from perimeter edges
  for (uint32_t i=0; i<perimSize; i++){
    uint32_t ce = perim[i];
    uint64_t *tt = &edges->edg2tri[2*ce];
    uint64_t neigh = tt[0] == cavity[i] ? tt[1] : tt[0];
    if (neigh == UINT64_MAX) neigh = cavity[i];
    neighs[numNeighs] = neigh;
    numNeighs++;
  }

  char buffer[32];
  snprintf(buffer,sizeof(char)*32,"tc1/fm_%06i_%06i.pos",(int)vd,(int)currentTri);
  FILE *tc;
  hxtPosInit(buffer,"check",&tc);
  hxtPosAddLine(tc,&mesh->vertices.coord[4*edges->node[2*ce+0]],&mesh->vertices.coord[4*edges->node[2*ce+1]],0);
  hxtPosNewView(tc,"Cavity");
  for (uint64_t i=0; i<cavSize; i++){
    uint64_t ct = cavity[i];
    // Replace deleted triangles
    if (ct == t0) continue;
    if (ct == t1) continue;
    // Create new triangle 
    uint32_t nod[3] = {UINT32_MAX}; 
    nod[0] = mesh->triangles.node[3*ct+0] == vd ? vr : mesh->triangles.node[3*ct+0];
    nod[1] = mesh->triangles.node[3*ct+1] == vd ? vr : mesh->triangles.node[3*ct+1];
    nod[2] = mesh->triangles.node[3*ct+2] == vd ? vr : mesh->triangles.node[3*ct+2];
    hxtPosAddTriangle(tc,&mesh->vertices.coord[4*nod[0]],&mesh->vertices.coord[4*nod[1]],&mesh->vertices.coord[4*nod[2]],0);
  }
  hxtPosFinish(tc);

  // Print out cavity 
  hxtTempPrintCavity (mesh,
                      edges,
                      cavSize,
                      cavity,
                      neighs,
                      vd,
                      currentTri,
                      ce);

}



  //=====================================================================================
  // Create an array with resulting triangles after collapse
  //=====================================================================================
  uint32_t cavityNew[3*cavSize];
  for (uint64_t i=0; i<cavSize; i++){

    uint64_t ct = cavity[i];

    // Replace deleted triangles
    if (ct == t0) ct = tt0;
    if (ct == t1) ct = tt1;

    uint32_t *nod = mesh->triangles.node +3*ct;
    cavityNew[3*i+0] = nod[0] == vd ? vr : nod[0];
    cavityNew[3*i+1] = nod[1] == vd ? vr : nod[1];
    cavityNew[3*i+2] = nod[2] == vd ? vr : nod[2];

  }

  //=====================================================================================
  // Loop over triangles and check
  //=====================================================================================
  for (uint64_t i=0; i<cavSize; i++){
    uint64_t ct = cavity[i];

    // Replace deleted triangles
    if (ct == t0) ct = tt0;
    if (ct == t1) ct = tt1;

    // Normal of original triangle
    double normal0area[3];
    normal2triangleArea(mesh,ct,normal0area);
    double normal0[3] = {normal0area[0],normal0area[1],normal0area[2]};
    normalize(normal0);

    // Create new triangle 
    uint32_t *nod = &cavityNew[3*i];

    // Normal of new triangle
    double normal1area[3];
    normal2triangleAreaV(&mesh->vertices.coord[4*nod[0]],
                         &mesh->vertices.coord[4*nod[1]],
                         &mesh->vertices.coord[4*nod[2]],normal1area);
    double normal1[3] = {normal1area[0],normal1area[1],normal1area[2]};
    normalize(normal1);

    //********************************************
    // Check if triangle is flipped
    if (myDot(normal0,normal1) < 0.0){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }

    //********************************************
    // Check area of triangle
    // TODO which threshold  
    //double area0 = norm(normal0area)/2.;
    double area1 = norm(normal1area)/2.;
    double areaThres = 10e-9;
    if (area1 < areaThres){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }


    //********************************************
    // Check normals between new triangles
    uint64_t next = (i+1)%cavSize;
    uint32_t *nodN = &cavityNew[3*next];
    double normal2[3];
    normal2triangleV(&mesh->vertices.coord[4*nodN[0]],&mesh->vertices.coord[4*nodN[1]],&mesh->vertices.coord[4*nodN[2]],normal2);
    if (myDot(normal1,normal2) < -dotThreshold){
      *canWeCollapse = 0;
      return HXT_STATUS_OK;
    }


    //********************************************
    // Take neigh triangle(s) from corresponding perimeter edge
    //  A. Interior edge
    //  B. Boundary edge (line)
    
    uint32_t ce = perim[i];
    if (edges2lines[ce] == UINT64_MAX){
      uint64_t nt = edges->edg2tri[2*ce+0] == cavity[i] ? edges->edg2tri[2*ce+1] : edges->edg2tri[2*ce+0];
      double normal3[3];
      normal2triangle(mesh,nt,normal3);
      if (myDot(normal1,normal3) < -dotThreshold){
        *canWeCollapse = 0;
        return HXT_STATUS_OK;
      }
    }
    // Check for boundary edges (lines)
    else{
      uint64_t cl = edges2lines[ce];

      // Loop over neigh triangles
      for (uint64_t j=0; j<maxNumTriToLine; j++){
        uint64_t ct = lines2triangles[maxNumTriToLine*cl+j];
        if (ct == UINT64_MAX) continue;
        if (ct == cavity[i]) continue;

        double normal3[3];
        normal2triangle(mesh,ct,normal3);

        // Non-manifold case
        int is0 = isEdgeOrientedInTriangle(mesh,edges,cavity[i],ce);
        int is1 = isEdgeOrientedInTriangle(mesh,edges,ct,ce);
        if (is0 == is1 ){ 
          if (myDot(normal1,normal3) > dotThreshold){
            *canWeCollapse = 0;
            return HXT_STATUS_OK;
          }
        }
        else{
          if (myDot(normal1,normal3) < -dotThreshold){
            *canWeCollapse = 0;
            return HXT_STATUS_OK;
          }
        }


      }
    }
  }

  return HXT_STATUS_OK;
}

//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCanWeCollapseInteriorVertex(HXTMesh *mesh,
                                         HXTEdges *edges,
                                         HXTPointGenParent *parent,
                                         uint32_t *lines2edges,
                                         uint64_t *edges2lines,
                                         uint64_t *lines2triangles,
                                         uint64_t maxNumTriToLine,
                                         uint64_t *vertices2lines,
                                         uint64_t maxNumLinesToVertex,
                                         uint64_t cavSize,
                                         uint64_t *cavity,
                                         uint32_t vd,  // vertex to be removed
                                         uint32_t *edgeToCollapse ) // return edge to be collapsed
{
  if (parent[vd].type != 2) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Point is not on triangle");
  uint64_t ct = parent[vd].id;

  // Build cavity of edges of that vertex
  uint32_t cavSizeEdges = 0;
  uint32_t cavityEdges[1000];
  HXT_CHECK(hxtVertexCavityEdges(mesh, edges, vd, ct, &cavSizeEdges, cavityEdges));

  // TODO sort edges in descending order by length
  uint32_t cavityEdgesSorted[cavSize];
  for (uint32_t i=0; i<cavSizeEdges; i++) cavityEdgesSorted[i] = cavityEdges[i];
  //hxtPointGenSort(edges,cavSizeEdges,cavityEdges,cavityEdgesSorted);

  // Loop over cavity edges to find one that we can collapse
  for (uint32_t k=0; k<cavSizeEdges; k++){
    uint32_t ce = cavityEdgesSorted[k];

    int canWeCollapse = 1;
    
    // TODO for now tests 
    HXT_CHECK(hxtCanWeCollapseInteriorEdge(mesh, 
                                           edges, 
                                           parent, 
                                           lines2edges,
                                           edges2lines,
                                           lines2triangles,
                                           maxNumTriToLine,
                                           vertices2lines,
                                           maxNumLinesToVertex,
                                           cavSize, 
                                           cavity, 
                                           vd, 
                                           ct, 
                                           ce, 
                                           &canWeCollapse));
 

    if (canWeCollapse == 1){
      *edgeToCollapse = ce;
      return HXT_STATUS_OK;
    }
  }


  return HXT_STATUS_OK;
}


//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCollapseBoundaryEdge (HXTMesh *mesh,
                                   HXTEdges *edges,
                                   HXTPointGenParent *parent,
                                   uint32_t *flagE,
                                   uint32_t *lines2edges,
                                   uint64_t *edges2lines,
                                   uint64_t *lines2triangles,
                                   uint64_t maxNumTriToLine,
                                   uint64_t *vertices2lines,
                                   uint64_t maxNumLinesToVertex,
                                   uint32_t vd,  // node to be removed
                                   uint32_t ce,  // edge to be collapsed
                                   int *collapsed)  {

  *collapsed = 0;

  // Check if edge to be collapsed contains the vertex vd 
  if (edges->node[2*ce+0] != vd && edges->node[2*ce+1] != vd) 
    return(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Node %d is not in edge %d ", vd,ce));

  // Check if corresponding line exists
  uint64_t cl = edges2lines[ce];
  if (cl == UINT64_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge does not have corresponding line - not on boundary");

  // Take remaining vertex of the edge ce 
  uint32_t vr = (edges->node[2*ce+0] == vd) ? edges->node[2*ce+1] : edges->node[2*ce+0];

  // Find the remaining boundary edge 
  uint64_t l0 = vertices2lines[maxNumLinesToVertex*vd+0];
  uint64_t l1 = vertices2lines[maxNumLinesToVertex*vd+1];
  if (l0 == UINT64_MAX || l1 == UINT64_MAX)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Could not find the other line");
  if (l0 != cl && l1 != cl)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Could not find the other line correctly");

  uint64_t ol = (l0 == cl) ? l1 : l0;   // the other line 
  uint32_t oe = lines2edges[ol];        // the other edge

  // For all adjacent triangles build corresponding "half"-cavity
  uint64_t cavSize = 0;
  uint64_t cavity[1000];

  for (uint64_t i=0; i<maxNumTriToLine; i++){
    uint64_t ct = lines2triangles[maxNumTriToLine*cl+i];
    if (ct == UINT64_MAX) continue;
    uint64_t dt = ct; // triangle to be deleted

    // Build cavity
    HXT_CHECK(hxtBoundaryVertexCavity(mesh,
                                      edges,
                                      vd,
                                      ct,
                                      ce,
                                      edges2lines,
                                      &cavSize,
                                      cavity));

    // Find other edge to be deleted for this cavity 
    uint32_t de = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      uint32_t edge = edges->tri2edg[3*dt+j];
      if (edge == ce) continue;
      if (edges->node[2*edge+0] == vd || edges->node[2*edge+1] == vd) de = edge;
    }
    if (de == UINT32_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cannot find edge de to be deleted");

    // TODO debug or delete
    // This can happen only in the case that vd is a corner point 
    // (has 3 or more boundary edges)
    if (edges2lines[de] != UINT64_MAX){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"FINALMESHedgeOnBoundary.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge to be deleted is on boundary");
    }

    // Find the remaining edges of triangle to be deleted dt
    // de will be replaced by re 
    uint32_t re = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      uint32_t edge = edges->tri2edg[3*dt+j];
      if (edge == ce) continue;
      if (edge == de) continue;
      re = edge;
    }
    if (re == UINT32_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cannot find edge re to remain");

    // Find remaining triangle
    uint64_t rt = (edges->edg2tri[2*de+0] == dt) ? edges->edg2tri[2*de+1] : edges->edg2tri[2*de+0];

    // Update lines2triangles in the case where the remaining edge is collapsed to a boundary edge 
    if (edges2lines[re] != UINT64_MAX){
      for (uint64_t j=0; j<maxNumTriToLine; j++){
        if (lines2triangles[maxNumTriToLine*edges2lines[re]+j] == dt){
          lines2triangles[maxNumTriToLine*edges2lines[re]+j] = rt;
        }
      }
    }

    for (uint32_t j=0; j<3; j++)
      if (edges->tri2edg[3*rt+j] == de) edges->tri2edg[3*rt+j] = re;

    if (edges->edg2tri[2*re+0] == dt) edges->edg2tri[2*re+0] = rt;
    if (edges->edg2tri[2*re+1] == dt) edges->edg2tri[2*re+1] = rt;
 

    for (uint64_t j=0; j<cavSize; j++){
      uint64_t t = cavity[j];
      if (t == dt) continue;
      for (uint64_t k=0; k<3; k++){
        if (mesh->triangles.node[3*t+k] == vd) mesh->triangles.node[3*t+k] = vr;

        // Update parent triangle
        if (parent[mesh->triangles.node[3*t+k]].type == 2)
          parent[mesh->triangles.node[3*t+k]].id = t;


        uint32_t edge = edges->tri2edg[3*t+k];
        if (edge == oe) continue;
        if (edge == ce) continue;
        if (edges->node[2*edge+0] == vd) edges->node[2*edge+0] = vr;
        if (edges->node[2*edge+1] == vd) edges->node[2*edge+1] = vr;
      }

    }
    mesh->triangles.colors[dt] = UINT16_MAX;

    flagE[de] = UINT32_MAX;
  }

  for (uint64_t i=0; i<maxNumLinesToVertex; i++){
    uint64_t line = vertices2lines[maxNumLinesToVertex*vr+i];
    if (line == cl) vertices2lines[maxNumLinesToVertex*vr+i] = ol;
  }

  if (edges->node[2*oe+0] == vd) edges->node[2*oe+0] = vr;
  if (edges->node[2*oe+1] == vd) edges->node[2*oe+1] = vr;

  if (mesh->lines.node[2*ol+0] == vd) mesh->lines.node[2*ol+0] = vr;
  if (mesh->lines.node[2*ol+1] == vd) mesh->lines.node[2*ol+1] = vr;

  mesh->lines.colors[cl] = UINT16_MAX;

  // Update parent 
  if (parent[vr].type == 1) parent[vr].id = ol;
  parent[vd].type = UINT8_MAX;
  parent[vd].id = UINT64_MAX;

  *collapsed = 1;

  return HXT_STATUS_OK;
}
























//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtCollapseInteriorEdge (HXTMesh *mesh, 
                                   HXTEdges *edges, 
                                   HXTPointGenParent *parent,
                                   uint32_t *flagE,
                                   uint32_t *lines2edges,
                                   uint64_t *edges2lines,
                                   uint64_t *lines2triangles,
                                   uint64_t maxNumTriToLine,
                                   uint64_t *vertices2lines,
                                   uint64_t maxNumLinesToVertex,
                                   uint64_t cavSize, 
                                   uint64_t *cavity, 
                                   uint32_t vd,  // node to be removed
                                   uint32_t ce,  // edge to be collapsed
                                   int *collapsed)
{
  HXT_UNUSED(lines2edges);
  HXT_UNUSED(vertices2lines);
  HXT_UNUSED(maxNumLinesToVertex);

  *collapsed = 0;

  // Adjacent triangles to be deleted
  uint64_t t0 = edges->edg2tri[2*ce+0];
  uint64_t t1 = edges->edg2tri[2*ce+1];
  
  // Check if the edge actually has the node vd
  if (edges->node[2*ce+0] != vd && edges->node[2*ce+1] != vd) 
    return(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Node %d is not in edge %d ", vd,ce));

  // Remaining vertex of the edge ce 
  uint64_t vr = (edges->node[2*ce+0] == vd) ? edges->node[2*ce+1] : edges->node[2*ce+0];

  // Find the two other edges that will be deleted
  uint32_t de0 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t edge = edges->tri2edg[3*t0+i];
    if (edge == ce) continue;
    if (edges->node[2*edge+0] == vd || edges->node[2*edge+1] == vd) de0 = edge;
  }
  uint32_t de1 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t edge = edges->tri2edg[3*t1+i];
    if (edge == ce) continue;
    if (edges->node[2*edge+0] == vd || edges->node[2*edge+1] == vd) de1 = edge;
  }
  if (de0 == UINT32_MAX || de1 == UINT32_MAX) 
    return(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Cannot find edges to delete"));

  
  // Find the two remaining edges of t0 and t1 respectively
  // de1 and de2 will be replaced by re1 and re2 respectively 
  uint32_t re0 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t edge = edges->tri2edg[3*t0+i];
    if (edge == ce) continue;
    if (edge == de0) continue;
    re0 = edge;
  }
  uint32_t re1 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t edge = edges->tri2edg[3*t1+i];
    if (edge == ce) continue;
    if (edge == de1) continue;
    re1 = edge;
  }
  if (re0 == UINT32_MAX || re1 == UINT32_MAX) 
    return(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Cannot find edges to remain"));

  uint64_t tt0 = (edges->edg2tri[2*de0+0] == t0) ? edges->edg2tri[2*de0+1] : edges->edg2tri[2*de0+0];
  uint64_t tt1 = (edges->edg2tri[2*de1+0] == t1) ? edges->edg2tri[2*de1+1] : edges->edg2tri[2*de1+0];

  for (uint32_t i=0; i<3; i++){
    if (edges->tri2edg[3*tt0+i] == de0) edges->tri2edg[3*tt0+i] = re0;
    if (edges->tri2edg[3*tt1+i] == de1) edges->tri2edg[3*tt1+i] = re1;
  }

  // Update edg2tri
  if (edges->edg2tri[2*re0+0] == t0) edges->edg2tri[2*re0+0] = tt0;
  if (edges->edg2tri[2*re0+1] == t0) edges->edg2tri[2*re0+1] = tt0;
  if (edges->edg2tri[2*re1+0] == t1) edges->edg2tri[2*re1+0] = tt1;
  if (edges->edg2tri[2*re1+1] == t1) edges->edg2tri[2*re1+1] = tt1;

  // Update lines2triangles
  if (edges2lines[re0] != UINT64_MAX){
    uint64_t cl = edges2lines[re0];
    for (uint64_t i=0; i<maxNumTriToLine; i++){
      uint64_t tri = lines2triangles[maxNumTriToLine*cl+i];
      if (tri == UINT64_MAX) continue;
      if (tri == t0) lines2triangles[maxNumTriToLine*cl+i] = tt0;
    }
  }
  if (edges2lines[re1] != UINT64_MAX){
    uint64_t cl = edges2lines[re1];
    for (uint64_t i=0; i<maxNumTriToLine; i++){
      uint64_t tri = lines2triangles[maxNumTriToLine*cl+i];
      if (tri == UINT64_MAX) continue;
      if (tri == t1) lines2triangles[maxNumTriToLine*cl+i] = tt1;
    }
  }

  for (uint64_t i=0; i<cavSize; i++){
    if (cavity[i] == t0 || cavity[i] == t1) continue;
    for (uint64_t j=0; j<3; j++){
      if (mesh->triangles.node[3*cavity[i]+j] == vd) mesh->triangles.node[3*cavity[i]+j] = vr;

      // Update parent triangle
      if (parent[mesh->triangles.node[3*cavity[i]+j]].type == 2)
        parent[mesh->triangles.node[3*cavity[i]+j]].id = cavity[i];

      uint32_t edge = edges->tri2edg[3*cavity[i]+j];
      if (edges->node[2*edge+0] == vd) edges->node[2*edge+0] = vr;
      if (edges->node[2*edge+1] == vd) edges->node[2*edge+1] = vr;
    }
  }

  parent[vd].type = UINT8_MAX;
  parent[vd].id = UINT64_MAX;

  mesh->triangles.colors[t0] = UINT16_MAX;
  mesh->triangles.colors[t1] = UINT16_MAX;

  flagE[ce] = UINT32_MAX;
  flagE[de0] = UINT32_MAX;
  flagE[de1] = UINT32_MAX;

  // TODO DELETE DEBUG
  
  /*for (uint64_t i=0; i<mesh->triangles.num; i++){*/
    /*if (mesh->triangles.colors[i] == UINT16_MAX) continue;*/
    /*for (uint32_t j=0; j<3; j++){*/
      /*uint32_t ee = edges->tri2edg[3*i+j];*/
      /*if (ee == ce) printf("ERROR1\n"); */
      /*if (ee == de1) printf("ERROR2\n"); */
      /*if (ee == de2) printf("ERROR3\n"); */
    /*}*/
  /*}*/

  *collapsed = 1;

  return HXT_STATUS_OK;
}





//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtRemoveBoundaryVertex(HXTMesh *mesh,
                                  HXTEdges *edges,
                                  HXTPointGenParent *parent,
                                  uint32_t *flagE,
                                  uint32_t *lines2edges,
                                  uint64_t *edges2lines,
                                  uint64_t *lines2triangles,
                                  uint64_t maxNumTriToLine,
                                  uint64_t *vertices2lines,
                                  uint64_t maxNumLinesToVertex,
                                  uint32_t vd,  // vertex to be removed
                                  int *collapsed ) 
{
 
  uint32_t edgeToCollapse = UINT32_MAX;

  HXT_CHECK(hxtCanWeCollapseBoundaryVertex(mesh,
                                           edges,
                                           parent,
                                           lines2edges,
                                           edges2lines,
                                           lines2triangles,
                                           maxNumTriToLine,
                                           vertices2lines,
                                           maxNumLinesToVertex,
                                           vd,
                                           &edgeToCollapse));
  

  if (edgeToCollapse == UINT32_MAX) return HXT_STATUS_OK;

  HXT_CHECK(hxtCollapseBoundaryEdge(mesh,
                                    edges,
                                    parent,
                                    flagE,
                                    lines2edges,
                                    edges2lines,
                                    lines2triangles,
                                    maxNumTriToLine,
                                    vertices2lines,
                                    maxNumLinesToVertex,
                                    vd,  
                                    edgeToCollapse,  
                                    collapsed));

  if (*collapsed != 1 ) return HXT_STATUS_ERROR;


 
  return HXT_STATUS_OK;
}

//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtRemoveInteriorVertex(HXTMesh *mesh,
                                  HXTEdges *edges,
                                  HXTPointGenParent *parent,
                                  uint32_t *flagE,
                                  uint32_t *lines2edges,
                                  uint64_t *edges2lines,
                                  uint64_t *lines2triangles,
                                  uint64_t maxNumTriToLine,
                                  uint64_t *vertices2lines,
                                  uint64_t maxNumLinesToVertex,
                                  uint32_t vd,  // vertex to be removed
                                  int *collapsed )
{

  uint64_t ct = parent[vd].id;
  if (mesh->triangles.colors[ct] == UINT16_MAX) return HXT_STATUS_OK;
 

  // Build cavity
  uint64_t cavSize = 0;
  uint64_t cavity[1000];
  cavSize = 0;
  HXT_CHECK(hxtVertexCavity(mesh, edges, vd, ct, &cavSize, cavity));


  uint32_t edgeToCollapse = UINT32_MAX;
  HXT_CHECK(hxtCanWeCollapseInteriorVertex(mesh,
                                           edges,
                                           parent,
                                           lines2edges,
                                           edges2lines,
                                           lines2triangles,
                                           maxNumTriToLine,
                                           vertices2lines,
                                           maxNumLinesToVertex,
                                           cavSize,
                                           cavity,
                                           vd,
                                           &edgeToCollapse));

  if (edgeToCollapse == UINT32_MAX) return HXT_STATUS_OK;
 
  HXT_CHECK(hxtCollapseInteriorEdge(mesh,
                                    edges,
                                    parent,
                                    flagE,
                                    lines2edges,
                                    edges2lines,
                                    lines2triangles,
                                    maxNumTriToLine,
                                    vertices2lines,
                                    maxNumLinesToVertex,
                                    cavSize,
                                    cavity,
                                    vd,  
                                    edgeToCollapse,  
                                    collapsed));

  if (*collapsed != 1 ) return HXT_STATUS_ERROR;

  return HXT_STATUS_OK;
}


//***************************************************************************************
//***************************************************************************************
//
// FUNCTION 
//
//***************************************************************************************
//***************************************************************************************
HXTStatus hxtRemoveVertex()
{



  return HXT_STATUS_OK;
}

