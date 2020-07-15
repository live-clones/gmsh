#include <limits.h>
#include "hxt_swap_edge.h"
#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"

#include "predicates.h"

#include "hxt_post_debugging.h"

//*****************************************************************************
//*****************************************************************************
// 
//*****************************************************************************
//*****************************************************************************
int _check_triangle_validity_3d (HXTMesh *mesh,  
                                 uint32_t a, 
                                 uint32_t b, 
                                 uint32_t c, 
                                 double *n)
{
  double *xa = &mesh->vertices.coord[4*a];
  double *xb = &mesh->vertices.coord[4*b];
  double *xc = &mesh->vertices.coord[4*c];
  //return hxtValidityP1Triangle  (xa, xb, xc, n) > 0;
  
  //attention! swap the vertices xb with xc 
  //           to have the correct orientation of input tetrahedron
  return hxtValidityP1Triangle  (xa, xc, xb, n) > 0;
}

//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
// Check if the edge is oriented with respect to the triangle
int isEdgeOrientedInTriangle (HXTMesh *mesh, 
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
  if (flag == 0) return HXT_ERROR_MSG(HXT_STATUS_FAILED, "edge not in triangle");

  return 0; 
}



//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
int isTriangleOriented (HXTMesh *mesh, HXTEdges *edges, uint64_t ct){

  int prob = 0;

  uint32_t e0 = edges->tri2edg[3*ct+0];
  uint32_t e1 = edges->tri2edg[3*ct+1];
  uint32_t e2 = edges->tri2edg[3*ct+2];

  if (edges->edg2tri[2*e0+0] == edges->edg2tri[2*e0+1]){ 
    prob = 1; 
    printf("1 edge same neighbour\n");
  }
  if (edges->edg2tri[2*e1+0] == edges->edg2tri[2*e1+1]){
    prob = 1; 
    printf("2 edge same neighbour\n");
  }
  if (edges->edg2tri[2*e2+0] == edges->edg2tri[2*e2+1]){
    prob = 1; 
    printf("3 edge same neighbour\n");
  }

  for(uint32_t j=0; j<3; j++){
    e0 = edges->tri2edg[3*ct+j];
    for (uint32_t i=0; i<3; i++){
      if (edges->node[2*e0+0] == mesh->triangles.node[3*ct+i]){
        if (edges->edg2tri[2*e0+1] == UINT64_MAX){
          if (edges->edg2tri[2*e0+0] != ct){
            prob = 1;
            printf("boundary triangle problem\n");
          }
        }
        else if (edges->node[2*e0+1] == mesh->triangles.node[3*ct+(i+1)%3]){
          if (edges->edg2tri[2*e0+1] != ct){
            prob = 1; 
            printf("wrong convention");
          }
        }
      }
    }
  }


  return prob;
}

//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
HXTStatus hxtMeshValidity2d (HXTMesh *mesh, int *isValid ){
  *isValid = 1;

  for (uint32_t i=0; i < mesh->triangles.num ; i++){
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0],
                        mesh->triangles.node[3*i+1],
                        mesh->triangles.node[3*i+2]};
    double normal[3]; 
    normal2triangleV(&mesh->vertices.coord [4*vtri[0]],
                     &mesh->vertices.coord [4*vtri[1]],
                     &mesh->vertices.coord [4*vtri[2]], normal);
    int validity = 0;
    validity = _check_triangle_validity_3d (mesh, vtri[0], vtri[1], vtri[2], normal);
    if (validity == 0) isValid = 0;
  }

  return HXT_STATUS_OK;
}

//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
HXTStatus hxtSwapEdges (HXTMesh *mesh, 
                        HXTEdges *edges, 
                        void (*metric)(double *x, void *data, double *m), 
                        void *dataForMetric, 
                        uint64_t *edges2lines,
                        uint64_t maxNumTriToLine,
                        uint64_t *lines2triangles,
                        int *numSwaps ){
  *numSwaps = 0;

  for (uint32_t ce = 0 ; ce < edges->numEdges ; ce++ ) {
    int swapped ;
    HXT_CHECK(hxtSwapEdge(mesh, 
                          edges, 
                          metric, 
                          dataForMetric, 
                          edges2lines,
                          maxNumTriToLine,
                          lines2triangles,
                          0.90, 
                          ce,
                          &swapped));
    *numSwaps += swapped;
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
HXTStatus hxtTempPrintSwap(HXTMesh *mesh,
                           HXTEdges *edges,
                           uint32_t ce,
                           int when)
{

  char buffer[32];
  snprintf(buffer,sizeof(char)*32,"tswap/fm_%06i_%i.pos",(int)ce,when);
  FILE *tc;
  hxtPosInit(buffer,"Triangles",&tc);
  hxtPosAddLine(tc,&mesh->vertices.coord[4*edges->node[2*ce+0]],&mesh->vertices.coord[4*edges->node[2*ce+1]],0);

  uint64_t t0 = edges->edg2tri[2*ce+0];
  uint64_t t1 = edges->edg2tri[2*ce+1];

  uint32_t *n0 = &mesh->triangles.node[3*t0+0]; 
  hxtPosAddTriangle(tc,&mesh->vertices.coord[4*n0[0]],&mesh->vertices.coord[4*n0[1]],&mesh->vertices.coord[4*n0[2]],0);

  uint32_t *n1 = &mesh->triangles.node[3*t1+0]; 
  hxtPosAddTriangle(tc,&mesh->vertices.coord[4*n1[0]],&mesh->vertices.coord[4*n1[1]],&mesh->vertices.coord[4*n1[2]],0);

  // Build neighs
  uint64_t neigh[4] = {UINT64_MAX};
  uint64_t countNeigh = 0;
  // 2 neighs from t0
  for (uint32_t j=0; j<3; j++){
    uint32_t e0 = edges->tri2edg[3*t0+j];
    uint32_t e0t0 = edges->edg2tri[2*e0+0];
    uint32_t e0t1 = edges->edg2tri[2*e0+1];
    if (e0t0 != t0 && e0t0 != t1){
      neigh[countNeigh] = e0t0;
      countNeigh++;
      continue;
    }
    if (e0t1 != t0 && e0t1 != t1){
      neigh[countNeigh] = e0t1;
      countNeigh++;
      continue;
    }
  }

  if (countNeigh != 2) printf("ERROR edge %d \n",ce);

  // 2 neighs from t1
  for (uint32_t j=0; j<3; j++){
    uint32_t e1 = edges->tri2edg[3*t1+j];
    uint32_t e1t0 = edges->edg2tri[2*e1+0];
    uint32_t e1t1 = edges->edg2tri[2*e1+1];
    if (e1t0 != t0 && e1t0 != t1){
      neigh[countNeigh] = e1t0;
      countNeigh++;
      continue;
    }
    if (e1t1 != t0 && e1t1 != t1){
      neigh[countNeigh] = e1t1;
      countNeigh++;
      continue;
    }
  }

  // Normal of t0
  double normal0[3] = {0.};
  normal2triangleV(&mesh->vertices.coord [4*mesh->triangles.node[3*t0+0]],
                   &mesh->vertices.coord [4*mesh->triangles.node[3*t0+1]],
                   &mesh->vertices.coord [4*mesh->triangles.node[3*t0+2]], 
                   normal0);

  // Normal of t1
  double normal1[3] = {0.};
  normal2triangleV(&mesh->vertices.coord [4*mesh->triangles.node[3*t1+0]],
                   &mesh->vertices.coord [4*mesh->triangles.node[3*t1+1]],
                   &mesh->vertices.coord [4*mesh->triangles.node[3*t1+2]], 
                   normal1);

  printf("============================================================================\n");
  printf("============================================================================\n");
  printf("EDGE = %d \n", ce);
  if (myDot(normal0,normal1)<0.) printf("HERE negative \n");
  for (uint64_t i=0; i<2; i++){
    double normal[3] = {0.};
    uint64_t ct = neigh[i];
    normal2triangleV(&mesh->vertices.coord [4*mesh->triangles.node[3*ct+0]],
                     &mesh->vertices.coord [4*mesh->triangles.node[3*ct+1]],
                     &mesh->vertices.coord [4*mesh->triangles.node[3*ct+2]], 
                     normal);
 
    double dot = myDot(normal0,normal);
    double angle = hxtAngle_0_pi(normal0,normal);
    if (angle > M_PI/2){
      printf("HERE t0 %f %f \n", dot, angle);
    }
  }
  for (uint64_t i=2; i<4; i++){

    uint64_t ct = neigh[i];
    double normal[3] = {0.};
    normal2triangleV(&mesh->vertices.coord [4*mesh->triangles.node[3*ct+0]],
                     &mesh->vertices.coord [4*mesh->triangles.node[3*ct+1]],
                     &mesh->vertices.coord [4*mesh->triangles.node[3*ct+2]], 
                     normal);
    double dot = myDot(normal1,normal);
    double angle = hxtAngle_0_pi(normal1,normal);
    if (angle > M_PI/2){
      printf("HERE t1 %f %f \n", dot, angle);
    }
  }


  hxtPosNewView(tc,"Neighs t0");
  for (uint64_t i=0; i<2; i++){
    uint64_t ct = neigh[i];
    uint32_t *n = &mesh->triangles.node[3*ct+0]; 
    hxtPosAddTriangle(tc,&mesh->vertices.coord[4*n[0]],&mesh->vertices.coord[4*n[1]],&mesh->vertices.coord[4*n[2]],0);
  }
  hxtPosNewView(tc,"Neighs t1");
  for (uint64_t i=2; i<4; i++){
    uint64_t ct = neigh[i];
    uint32_t *n = &mesh->triangles.node[3*ct+0]; 
    hxtPosAddTriangle(tc,&mesh->vertices.coord[4*n[0]],&mesh->vertices.coord[4*n[1]],&mesh->vertices.coord[4*n[2]],0);
  }
  hxtPosFinish(tc);

  return HXT_STATUS_OK;
}

//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
HXTStatus hxtCanWeSwapEdge(HXTMesh *mesh,
                           HXTEdges *edges,
                           void (*metric)(double *x, void *data, double *m),
                           void *dataForMetric,
                           uint64_t *edges2lines,
                           uint64_t maxNumTriToLine,
                           uint64_t *lines2triangles,
                           double dotThreshold,
                           uint32_t ce,
                           int *canWeSwap)
{
  HXT_UNUSED(metric);
  HXT_UNUSED(dataForMetric);

  dotThreshold = 0.95; //TODO attention
  
  uint64_t t0 = edges->edg2tri[2*ce+0];
  uint64_t t1 = edges->edg2tri[2*ce+1];

  //*********************************************
  // If triangles are coplanar swap
  //*********************************************
  double Nt0[3]; 
  double Nt1[3]; 
  normal2triangle(mesh,t0,Nt0);
  normal2triangle(mesh,t1,Nt1);
  double d = myDot(Nt0,Nt1);
  if (d >= 1.0){
    *canWeSwap = 1;
    return HXT_STATUS_OK;
  }
 

  //*********************************************
  // Construct new triangles
  //*********************************************
  uint32_t n0 = edges->node[2*ce+0];
  uint32_t n1 = edges->node[2*ce+1];
  
  uint32_t *nodes_of_t0 = &mesh->triangles.node[3*t0];
  uint32_t *nodes_of_t1 = &mesh->triangles.node[3*t1];

  uint32_t nt0=-1, nt1=-1;
  int n0IndexInt0, n0IndexInt1;
  for (int j=0;j<3;j++){
    if (nodes_of_t0[j] == n0) n0IndexInt0 = j;
    if (nodes_of_t1[j] == n0) n0IndexInt1 = j;
  }
  nt0 = nodes_of_t0[(n0IndexInt0+1)%3];
  nt1 = nodes_of_t1[(n0IndexInt1+2)%3];

  uint32_t t0n[3] = {nt0,nt1,n0};
  uint32_t t1n[3] = {n1,nt1,nt0};


  //*********************************************
  // Perimeter edges of the two triangles 
  //*********************************************
  // First we find the index of edge to be swapped in each triangle
  uint32_t edgeIndexOft0 = UINT32_MAX;
  uint32_t edgeIndexOft1 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t e0 = edges->tri2edg[3*t0+i];
    if (e0 == ce) edgeIndexOft0 = i;
    uint32_t e1 = edges->tri2edg[3*t1+i];
    if (e1 == ce) edgeIndexOft1 = i;
  }
  
  // Original triangle t0 has perimeter edges 0 and 1 
  // Original triangle t1 has perimeter edges 2 and 3 
  //  Swapped triangle t0 has perimeter edges 1 and 2 
  //  Swapped triangle t1 has perimeter edges 3 and 0 
  uint32_t perimeterEdges[4];
  perimeterEdges[0] = edges->tri2edg[3*t0+(edgeIndexOft0+1)%3];
  perimeterEdges[1] = edges->tri2edg[3*t0+(edgeIndexOft0+2)%3];
  perimeterEdges[2] = edges->tri2edg[3*t1+(edgeIndexOft1+1)%3];
  perimeterEdges[3] = edges->tri2edg[3*t1+(edgeIndexOft1+2)%3];

  //*********************************************
  // Build neighs
  // General case, accounts for open or non-manifold feature lines 
  // TODO write description and put in different function 
  //*********************************************
  uint64_t neigh[4*maxNumTriToLine];
  for (uint64_t i=0; i<4*maxNumTriToLine; i++) neigh[i] = UINT64_MAX;

  for (uint64_t i=0; i<4; i++){
    uint32_t e = perimeterEdges[i];
    uint64_t countNeigh = 0;
    // If is a boundary edge (line)
    if (edges2lines[e] != UINT64_MAX){ 
      for (uint64_t j=0; j<maxNumTriToLine; j++){
        uint64_t ct = lines2triangles[maxNumTriToLine*edges2lines[e]+j];
        if (ct == UINT64_MAX)     continue;
        if (ct == t0 || ct == t1) continue;
        neigh[i*maxNumTriToLine+countNeigh] = ct;
        countNeigh++;
      }
    }
    else{
      uint64_t currentTri = UINT64_MAX;
      if (i==0 || i==1) currentTri = t0;
      if (i==2 || i==3) currentTri = t1;
      uint64_t *tt = edges->edg2tri + 2*e;
      uint64_t ct = tt[0] == currentTri ? tt[1] : tt[0];
      if (ct == UINT64_MAX) continue; // Open Boundary
      neigh[i*maxNumTriToLine+countNeigh] = ct;
      countNeigh++;
    }
  }

  //*********************************************
  // Topological check
  // Find if a neigh triangle is common
  //********************************************* 
  for (uint64_t i=0; i<2*maxNumTriToLine; i++){
    if (neigh[i] == UINT64_MAX) continue;
    for (uint64_t j=2*maxNumTriToLine; j<4*maxNumTriToLine; j++){
      if (neigh[j] == UINT64_MAX) continue;
      if (neigh[i] == neigh[j]){
        *canWeSwap = 0;
        return HXT_STATUS_OK;
      }
    }
  }


  //*********************************************
  // Check angles between new triangles
  // and corresponding neigh triangles
  //*********************************************
  // Normal of t0n
  double normal0n[3] = {0.};
  normal2triangleV(&mesh->vertices.coord [4*t0n[0]],
                   &mesh->vertices.coord [4*t0n[1]],
                   &mesh->vertices.coord [4*t0n[2]],
                   normal0n);
  // Normal of t1
  double normal1n[3] = {0.};
  normal2triangleV(&mesh->vertices.coord [4*t1n[0]],
                   &mesh->vertices.coord [4*t1n[1]],
                   &mesh->vertices.coord [4*t1n[2]],
                   normal1n);


  double normalN[3];
  // for t0n
  for (uint64_t j=0; j<2; j++){
    uint32_t i;
    uint64_t tt;
    if (j == 0) i=0;
    if (j == 1) i=3;
    if (j == 0) tt=t0;
    if (j == 1) tt=t1;
    uint32_t ee = perimeterEdges[i];

    if (edges2lines[ee] == UINT64_MAX){
      uint64_t nt = edges->edg2tri[2*ee+0]==tt ? edges->edg2tri[2*ee+1] : edges->edg2tri[2*ee+0];
      normal2triangle(mesh,nt,normalN);
      if (myDot(normal0n,normalN) < -dotThreshold){
        *canWeSwap = 0;
        return HXT_STATUS_OK;
      }
    }
    else{
      uint64_t cl = edges2lines[ee];

      // Loop over neigh triangles
      for (uint64_t k=0; k<maxNumTriToLine; k++){
        uint64_t nt = lines2triangles[maxNumTriToLine*cl+k];
        if (nt == UINT64_MAX) continue;
        if (nt == tt) continue;

        normal2triangle(mesh,nt,normalN);

        // Non-manifold case
        int is0 = isEdgeOrientedInTriangle(mesh,edges,tt,ee);
        int is1 = isEdgeOrientedInTriangle(mesh,edges,nt,ee);
        if (is0 == is1){
          if (myDot(normal0n,normalN) > dotThreshold){
            *canWeSwap = 0;
            return HXT_STATUS_OK;
          }
        }
        else{
          if (myDot(normal0n,normalN) < -dotThreshold){
            *canWeSwap = 0;
            return HXT_STATUS_OK;
          }
        }
      }
    }
  }
  // for t1n
  for (uint64_t j=2; j<4; j++){
    uint32_t i;
    uint64_t tt;
    if (j == 2) i=1;
    if (j == 3) i=2;
    if (j == 2) tt=t0;
    if (j == 3) tt=t1;
    uint32_t ee = perimeterEdges[i];

    if (edges2lines[ee] == UINT64_MAX){
      uint64_t nt = edges->edg2tri[2*ee+0]==tt ? edges->edg2tri[2*ee+1] : edges->edg2tri[2*ee+0];
      normal2triangle(mesh,nt,normalN);
      if (myDot(normal1n,normalN) < -dotThreshold){
        *canWeSwap = 0;
        return HXT_STATUS_OK;
      }
    }
    else{
      uint64_t cl = edges2lines[ee];

      // Loop over neigh triangles
      for (uint64_t k=0; k<maxNumTriToLine; k++){
        uint64_t nt = lines2triangles[maxNumTriToLine*cl+k];
        if (nt == UINT64_MAX) continue;
        if (nt == tt) continue;

        normal2triangle(mesh,nt,normalN);

        // Non-manifold case
        int is0 = isEdgeOrientedInTriangle(mesh,edges,tt,ee);
        int is1 = isEdgeOrientedInTriangle(mesh,edges,nt,ee);
        if (is0 == is1){
          if (myDot(normal1n,normalN) > dotThreshold){
            *canWeSwap = 0;
            return HXT_STATUS_OK;
          }
        }
        else{
          if (myDot(normal1n,normalN) < -dotThreshold){
            *canWeSwap = 0;
            return HXT_STATUS_OK;
          }
        }
      }
    }
  }



  return HXT_STATUS_OK;
}

//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
HXTStatus hxtSwapEdge (HXTMesh *mesh,  
                       HXTEdges *edges, 
                       void (*metric)(double *x, void *data, double *m), 
                       void *dataForMetric, 
                       uint64_t *edges2lines,
                       uint64_t maxNumTriToLine,
                       uint64_t *lines2triangles,
                       double angle,
                       uint32_t ce, // edge to be swapped
                       int *swapped)
 
{
  HXT_UNUSED(metric);
  HXT_UNUSED(dataForMetric);

  (*swapped)=0;

  uint32_t n0 = edges->node[2*ce+0];
  uint32_t n1 = edges->node[2*ce+1];
  
  uint64_t t0 = edges->edg2tri[2*ce+0];
  uint64_t t1 = edges->edg2tri[2*ce+1];

  // Ensure triangles t1 and t2 have the same color 
  if(mesh->triangles.colors[t0] != mesh->triangles.colors[t1]){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Swapping edge with different colors");
  }
  // Ensure that we are not dealing with a boundary edge
  if (t0 == UINT64_MAX || t1 == UINT64_MAX){ 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Swapping edge on open boundary");
  }
  if (edges2lines[ce] != UINT64_MAX){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Swapping boundary edge (line)");
  }

  uint32_t *nodes_of_t0 = &mesh->triangles.node[3*t0];
  uint32_t *nodes_of_t1 = &mesh->triangles.node[3*t1];

  //*************************
  // Find orientation 
  // and resulting triangles
  //*************************
  uint32_t nt0=-1, nt1=-1;
  int n0IndexInt0, n0IndexInt1;
  for (int j=0;j<3;j++){
    if (nodes_of_t0[j] == n0) n0IndexInt0 = j;
    if (nodes_of_t1[j] == n0) n0IndexInt1 = j;
  }
    
  int ori = 0;
  if (nodes_of_t0[(n0IndexInt0+1)%3] == n1){
    nt0 = nodes_of_t0[(n0IndexInt0+2)%3];
    nt1 = nodes_of_t1[(n0IndexInt1+1)%3];
    ori = 1;
    // TODO by definition it does not go here?
	  //return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Should not go here");
  }
  else{
    nt0 = nodes_of_t0[(n0IndexInt0+1)%3];
    nt1 = nodes_of_t1[(n0IndexInt1+2)%3];
    ori = -1;
  }      


  //*************************
  // Checking if we can swap
  //*************************
  int canWeSwap = 1;
  HXT_CHECK(hxtCanWeSwapEdge(mesh,
                             edges,
                             NULL,
                             NULL,
                             edges2lines,
                             maxNumTriToLine,
                             lines2triangles,
                             angle,
                             ce,
                             &canWeSwap));

  if (canWeSwap != 1) return HXT_STATUS_OK;

  //*************************
  // Normals
  //*************************
  double Nt0[3]; 
  double Nt1[3]; 
  normal2triangle(mesh,t0,Nt0);
  normal2triangle(mesh,t1,Nt1);

  double normal[3] = {Nt0[0]+Nt1[0],Nt0[1]+Nt1[1],Nt0[2]+Nt1[2]};
  
  int validity = 0;
  if (ori == 1){
    validity = _check_triangle_validity_3d (mesh, nt1, n1, nt0, normal)
	          && _check_triangle_validity_3d (mesh, nt1, nt0, n0, normal);
	  //return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Should not go here");
  }
  else {
    validity = _check_triangle_validity_3d (mesh, n1, nt1, nt0, normal)
	          && _check_triangle_validity_3d (mesh, nt0, nt1, n0, normal);
  }

  if (validity == 0) return HXT_STATUS_OK;

  //printf("swap can be done\n");
  
  //*************************
  // Checking angle improvement
  //*************************
  double normal_old0[3];
  normal2triangleV(&mesh->vertices.coord[4*n0],  
                   &mesh->vertices.coord[4*n1], 
                   &mesh->vertices.coord[4*nt0], normal_old0 );
  double normal_old1[3];
  normal2triangleV(&mesh->vertices.coord[4*n1],  
                   &mesh->vertices.coord[4*n0], 
                   &mesh->vertices.coord[4*nt1],normal_old1 );
  double normal_new0[3];
  normal2triangleV(&mesh->vertices.coord[4*n1],  
                   &mesh->vertices.coord[4*nt1], 
                   &mesh->vertices.coord[4*nt0], normal_new0 );
  double normal_new1[3];
  normal2triangleV(&mesh->vertices.coord[4*nt0], 
                   &mesh->vertices.coord[4*nt1],
                   &mesh->vertices.coord[4*n0], normal_new1 );
  double d_old = 0.;
  for (int i=0; i<3; i++) d_old += normal_old0[i]*normal_old1[i];
  double d_new = 0.;
  for (int i=0; i<3; i++) d_new += normal_new0[i]*normal_new1[i];
  
  double angle_old = hxtAngle_0_pi(normal_old0,normal_old1);
  double angle_new = hxtAngle_0_pi(normal_new0,normal_new1);

  /*printf("DOT CHANGE  %f %f \n", d_old,d_new);*/
  /*printf("ANG CHANGE  %f %f \n", angle_old, angle_new);*/
  /*if (angle_old > M_PI/2) printf("BIG ANGLE OLD\n");*/
  /*if (angle_new > M_PI/2) printf("BIG ANGLE NEW\n");*/
  //if (d_new < d_old) return HXT_STATUS_OK;
  if (angle_new - angle_old >= M_PI/100){
    //printf("angle_new > angle_old %lf %lf \n", angle_new, angle_old);
    return HXT_STATUS_OK;
  }
 

  //*************************
  // Checking quality 
  //*************************
  
  double quality_old0 = hxtQualityP1Triangle(&mesh->vertices.coord[4*n0], 
                                             &mesh->vertices.coord[4*n1], 
                                             &mesh->vertices.coord[4*nt0]);
  double quality_old1 = hxtQualityP1Triangle(&mesh->vertices.coord[4*n0], 
                                             &mesh->vertices.coord[4*n1], 
                                             &mesh->vertices.coord[4*nt1]);
  double quality_new0 = hxtQualityP1Triangle(&mesh->vertices.coord[4*n1], 
                                             &mesh->vertices.coord[4*nt1], 
                                             &mesh->vertices.coord [4*nt0]);
  double quality_new1 = hxtQualityP1Triangle(&mesh->vertices.coord[4*nt0], 
                                             &mesh->vertices.coord [4*nt1], 
                                             &mesh->vertices.coord [4*n0]);


  // WITH RIGHT-ANGLED QUALITY 
  
  /*double quality_old0 = hxtRightAngledQualitySimple(&mesh->vertices.coord[4*n0],  */
                                                    /*&mesh->vertices.coord[4*n1],  */
                                                    /*&mesh->vertices.coord[4*nt0]);*/
  /*double quality_old1 = hxtRightAngledQualitySimple(&mesh->vertices.coord[4*n0],  */
                                                    /*&mesh->vertices.coord[4*n1],  */
                                                    /*&mesh->vertices.coord[4*nt1]);*/
  /*double quality_new0 = hxtRightAngledQualitySimple(&mesh->vertices.coord[4*n1],  */
                                                    /*&mesh->vertices.coord[4*nt1], */
                                                    /*&mesh->vertices.coord[4*nt0]);*/
  /*double quality_new1 = hxtRightAngledQualitySimple(&mesh->vertices.coord[4*nt0], */
                                                    /*&mesh->vertices.coord[4*nt1], */
                                                    /*&mesh->vertices.coord[4*n0]);*/
      
  double quality_old = quality_old0 < quality_old1 ? quality_old0 : quality_old1;
  double quality_new = quality_new0 < quality_new1 ? quality_new0 : quality_new1;

  //printf("QUAL CHANGE %f %f \n", quality_old, quality_new);
      
  if (quality_new <= quality_old) return HXT_STATUS_OK; 


  // At this point we can actually swap
  
  // First we find the index of edge to be swapped in each triangle
  uint32_t edgeIndexOft0 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t e = edges->tri2edg[3*t0+i];
    if (e == ce) edgeIndexOft0 = i;
  }
  uint32_t edgeIndexOft1 = UINT32_MAX;
  for (uint32_t i=0; i<3; i++){
    uint32_t e = edges->tri2edg[3*t1+i];
    if (e == ce) edgeIndexOft1 = i;
  }

  // CONSTRUCT ORDERED SIGNED EDGES OF PERIMETER OF TWO TRIANGLES TOGETHER 
  
  int perimeterEdges[4];
  int orientEdges[4];

  perimeterEdges[0] = edges->tri2edg[3*t0+(edgeIndexOft0+1)%3];
  orientEdges[0] = isEdgeOrientedInTriangle(mesh,edges,t0,perimeterEdges[0]);
  //if (edges->edg2tri[2*perimeterEdges[0]+1] != t1 )  orientEdges[0] = 0;  

  perimeterEdges[1] = edges->tri2edg[3*t0+(edgeIndexOft0+2)%3];
  orientEdges[1] = isEdgeOrientedInTriangle(mesh,edges,t0,perimeterEdges[1]);
  //if (edges->edg2tri[2*perimeterEdges[1]+1] != t1 )  orientEdges[1] = 0;

  perimeterEdges[2] = edges->tri2edg[3*t1+(edgeIndexOft1+1)%3];
  orientEdges[2] = isEdgeOrientedInTriangle(mesh,edges,t1,perimeterEdges[2]);
  //if (edges->edg2tri[2*perimeterEdges[2]+1] != t2 )  orientEdges[2] = 0;

  perimeterEdges[3] = edges->tri2edg[3*t1+(edgeIndexOft1+2)%3];
  orientEdges[3] = isEdgeOrientedInTriangle(mesh,edges,t1,perimeterEdges[3]);
  //if (edges->edg2tri[2*perimeterEdges[3]+1] != t2 )  orientEdges[3] = 0; 
  

  // Original triangle t0 has perimeter edges 0 and 1 
  // Original triangle t1 has perimeter edges 2 and 3 
  //  Swapped triangle t0 has perimeter edges 1 and 2 
  //  Swapped triangle t1 has perimeter edges 3 and 0 
  
  uint32_t new_edges_t0[3];
  uint32_t new_edges_t1[3];

  new_edges_t0[0] = perimeterEdges[1];
  new_edges_t0[1] = perimeterEdges[2];
  new_edges_t0[2] = ce;

  new_edges_t1[0] = perimeterEdges[3];
  new_edges_t1[1] = perimeterEdges[0];
  new_edges_t1[2] = ce;

  // nt1 and nt2 are the nodes of swapped edge t1
  edges->node[2*ce+0] = nt0;
  edges->node[2*ce+1] = nt1;

  // Assign nodes of new triangles
  uint32_t new_nodes_t0[3];
  uint32_t new_nodes_t1[3];

  new_nodes_t0[0] = orientEdges[1] == 1 ? edges->node[2*perimeterEdges[1]+0] : edges->node[2*perimeterEdges[1]+1];
  new_nodes_t0[1] = orientEdges[2] == 1 ? edges->node[2*perimeterEdges[2]+0] : edges->node[2*perimeterEdges[2]+1];
  new_nodes_t0[2] = orientEdges[2] == 0 ? edges->node[2*perimeterEdges[2]+0] : edges->node[2*perimeterEdges[2]+1];

  new_nodes_t1[0] = orientEdges[3] == 1 ? edges->node[2*perimeterEdges[3]+0] : edges->node[2*perimeterEdges[3]+1];
  new_nodes_t1[1] = orientEdges[0] == 1 ? edges->node[2*perimeterEdges[0]+0] : edges->node[2*perimeterEdges[0]+1];
  new_nodes_t1[2] = orientEdges[0] == 0 ? edges->node[2*perimeterEdges[0]+0] : edges->node[2*perimeterEdges[0]+1];

  // Change adjacent triangles for perimeter edges
  // perimeter edges 1 and 3 will remain the same since they stay on t1 and 2 respectively
  // so we change only for perimeter edges 0 and 2 

  if (edges->edg2tri[2*perimeterEdges[2]+1] != UINT64_MAX){
    if (edges->edg2tri[2*perimeterEdges[2]+0] == t1) edges->edg2tri[2*perimeterEdges[2]+0] = t0;
    if (edges->edg2tri[2*perimeterEdges[2]+1] == t1) edges->edg2tri[2*perimeterEdges[2]+1] = t0;
  }
  else{
    edges->edg2tri[2*perimeterEdges[2]+0] = t0;
    edges->edg2tri[2*perimeterEdges[2]+1] = UINT64_MAX;
  }
  if (edges->edg2tri[2*perimeterEdges[0]+1] != UINT64_MAX){
    if (edges->edg2tri[2*perimeterEdges[0]+0] == t0) edges->edg2tri[2*perimeterEdges[0]+0] = t1;
    if (edges->edg2tri[2*perimeterEdges[0]+1] == t0) edges->edg2tri[2*perimeterEdges[0]+1] = t1;
  }
  else{
    edges->edg2tri[2*perimeterEdges[0]+0] = t1;
    edges->edg2tri[2*perimeterEdges[0]+1] = UINT64_MAX;
  }

  if (new_nodes_t0[2] == edges->node[2*ce+0]){
    edges->edg2tri[2*ce+1] = t0;
    edges->edg2tri[2*ce+0] = t1;
  }
  else{
    edges->edg2tri[2*ce+0] = t0;
    edges->edg2tri[2*ce+1] = t1;
  }

  // UPDATE ALL
  
  mesh->triangles.node[3*t0+0] = new_nodes_t0[0];
  mesh->triangles.node[3*t0+1] = new_nodes_t0[1];
  mesh->triangles.node[3*t0+2] = new_nodes_t0[2];
  mesh->triangles.node[3*t1+0] = new_nodes_t1[0];
  mesh->triangles.node[3*t1+1] = new_nodes_t1[1];
  mesh->triangles.node[3*t1+2] = new_nodes_t1[2];

  edges->tri2edg[3*t0+0] = new_edges_t0[0];
  edges->tri2edg[3*t0+1] = new_edges_t0[1];
  edges->tri2edg[3*t0+2] = new_edges_t0[2];
  edges->tri2edg[3*t1+0] = new_edges_t1[0];
  edges->tri2edg[3*t1+1] = new_edges_t1[1];
  edges->tri2edg[3*t1+2] = new_edges_t1[2];

	(*swapped)=1;

  return HXT_STATUS_OK;

};



//*****************************************************************************
//*****************************************************************************
//
//*****************************************************************************
//*****************************************************************************
HXTStatus hxtSwapEdge_old (HXTMesh *mesh, 
                           HXTEdges *edges, void (*metric)(double *x, void *data, double *m), 
                           void *dataForMetric, 
                           int *swapped, 
                           uint32_t i )
{

  HXT_UNUSED(metric);
  HXT_UNUSED(dataForMetric);

  (*swapped)=0;

  uint32_t n1 = edges->node[2*i];
  uint32_t n2 = edges->node[2*i+1];
  
  uint64_t t1 = edges->edg2tri[2*i];
  uint64_t t2 = edges->edg2tri[2*i+1];

  // ensure triangles t1 and t2 have the same color 
  if(mesh->triangles.colors[t1] != mesh->triangles.colors[t2]) return HXT_STATUS_OK;
  // FIXME TODO check also angle between triangles ??? 
  
  if (t1 != (uint64_t)-1 && t2 != (uint64_t)-1) {
    
    uint32_t *nodes_of_t1 = &mesh->triangles.node[3*t1];
    uint32_t *nodes_of_t2 = &mesh->triangles.node[3*t2];

    uint32_t nt1=-1, nt2=-1;
    int n1IndexInt1, n1IndexInt2;
    for (int j=0;j<3;j++){
      if (nodes_of_t1[j] == n1) n1IndexInt1 = j;
      if (nodes_of_t2[j] == n1) n1IndexInt2 = j;
    }
    
    int ori = 0;
    
    if (nodes_of_t1[(n1IndexInt1+1)%3] == n2){
      nt1 = nodes_of_t1[(n1IndexInt1+2)%3];
      nt2 = nodes_of_t2[(n1IndexInt2+1)%3];
      ori = 1;
    }
    else{
      nt1 = nodes_of_t1[(n1IndexInt1+1)%3];
      nt2 = nodes_of_t2[(n1IndexInt2+2)%3];
      ori = -1;
    }      

    double Nt1[3]; 
    normal2triangleV(&mesh->vertices.coord[4*nodes_of_t1[0]],
                     &mesh->vertices.coord[4*nodes_of_t1[1]],
                     &mesh->vertices.coord[4*nodes_of_t1[2]], 
                     Nt1);
    double Nt2[3]; 
    normal2triangleV(&mesh->vertices.coord[4*nodes_of_t2[0]],
                     &mesh->vertices.coord[4*nodes_of_t2[1]],
                     &mesh->vertices.coord[4*nodes_of_t2[2]], 
                     Nt2);
    double normal[3] = {Nt1[0]+Nt2[0],Nt1[1]+Nt2[1],Nt1[2]+Nt2[2]};
    
    int validity = 0;
    if (ori == 1){
      validity = _check_triangle_validity_3d(mesh, nt2, n2, nt1, normal)
	            && _check_triangle_validity_3d(mesh, nt2, nt1, n1, normal);
    }
    else {
      validity = _check_triangle_validity_3d(mesh, n2, nt2, nt1, normal)
	            && _check_triangle_validity_3d(mesh, nt1, nt2, n1, normal);
    }

    if (validity) {
      //      printf("swap can be done\n");
      //        double quality_old1 = triangle_quality_metric (mesh, metric, dataForMetric, n1, n2, nt1 );
      //        double quality_old2 = triangle_quality_metric (mesh, metric, dataForMetric, n1, n2, nt2 );
      //        double quality_new1 = triangle_quality_metric (mesh, metric, dataForMetric, n2, nt2, nt1 );
      //        double quality_new2 = triangle_quality_metric (mesh, metric, dataForMetric, nt1, nt2, n1 );
      double quality_old1 = hxtQualityP1Triangle(&mesh->vertices.coord [4*n1], &mesh->vertices.coord [4*n2], &mesh->vertices.coord [4*nt1] );
      double quality_old2 = hxtQualityP1Triangle(&mesh->vertices.coord [4*n1], &mesh->vertices.coord [4*n2], &mesh->vertices.coord [4*nt2] );
      double quality_new1 = hxtQualityP1Triangle(&mesh->vertices.coord [4*n2], &mesh->vertices.coord [4*nt2], &mesh->vertices.coord [4*nt1] );
      double quality_new2 = hxtQualityP1Triangle(&mesh->vertices.coord [4*nt1], &mesh->vertices.coord [4*nt2], &mesh->vertices.coord [4*n1] );
      
      double quality_old = quality_old1 < quality_old2 ? quality_old1 : quality_old2;
      double quality_new = quality_new1 < quality_new2 ? quality_new1 : quality_new2;
      
      if ( quality_new > quality_old ){

        //printf("swapped\n");
	      (*swapped)=1;
	      if (ori == 1){
	        nodes_of_t1 [0] = nt2; nodes_of_t2 [0] = nt2;
	        nodes_of_t1 [1] = n2 ; nodes_of_t2 [1] = nt1;
      	  nodes_of_t1 [2] = nt1; nodes_of_t2 [2] = n1;
      	}
      	else{
      	  nodes_of_t1 [0] = n2 ; nodes_of_t2 [0] = nt1;
      	  nodes_of_t1 [1] = nt2; nodes_of_t2 [1] = nt2;
      	  nodes_of_t1 [2] = nt1; nodes_of_t2 [2] = n1;
      	}
	
      	// update t1 & t2 info
      	uint32_t e_n2_nt2 = UINT32_MAX;
      	uint32_t e_n1_nt1 = UINT32_MAX;
      	int k1;
      	int k2;

      	for (int k=0;k<3;k++){

      	  uint32_t ek  = edges->tri2edg[3*t1+k];
      	  uint32_t nk1 = edges->node[2*ek+0];
      	  uint32_t nk2 = edges->node[2*ek+1];

      	  if ((nk1 == n1 && nk2 == nt1) || (nk1 == nt1 && nk2 == n1)){
	          e_n1_nt1 = ek;
      	    k1 = k;
      	    if (edges->edg2tri[2*ek+0] == t1)
      	      edges->edg2tri[2*ek+0] = t2;
      	    else if (edges->edg2tri[2*ek+1] == t1)
      	      edges->edg2tri[2*ek+1] = t2;
      	    else{
      	      printf("edge %d %d is not in %lu\n",n1,nt1,t1);
      	      return HXT_STATUS_ERROR;
      	    }
      	  }
	  
      	  ek  = edges->tri2edg[3*t2+k];
      	  nk1 = edges->node[2*ek+0];
      	  nk2 = edges->node[2*ek+1];

      	  if ((nk1 == n2 && nk2 == nt2) || (nk1 == nt2 && nk2 == n2)){
      	    e_n2_nt2 = ek;
      	    k2 = k;
      	    if (edges->edg2tri[2*ek+0] == t2)
      	      edges->edg2tri[2*ek+0] = t1;
      	    else if (edges->edg2tri[2*ek+1] == t2)
      	      edges->edg2tri[2*ek+1] = t1;
      	    else{
      	      printf("edge %d %d is not in %lu\n",n2,nt2,t2);
      	      return HXT_STATUS_ERROR;
      	    }
      	  }               
      	}

      	if ( e_n2_nt2 == UINT_MAX ) return HXT_STATUS_ERROR;
      	if ( e_n1_nt1 == UINT_MAX ) return HXT_STATUS_ERROR;
      	
      	// change nodes of the edge
      	edges->node[2*i+0] = nt1;
      	edges->node[2*i+1] = nt2;
	
      	edges->tri2edg[3*t2+k2] = e_n1_nt1;
      	edges->tri2edg[3*t1+k1] = e_n2_nt2;
      }
    }      

  }

  return HXT_STATUS_OK;
};

