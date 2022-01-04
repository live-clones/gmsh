#include <time.h>

#include "hxt_quad_mesh.h"
#include "hxt_mesh.h"
#include "hxt_message.h"
#include "hxt_tools.h"
#include "hxt_post_debugging.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_numerics.h"
#include "hxt_rtree_wrapper.h"

//**********************************************************************************************************
//**********************************************************************************************************
//
//**********************************************************************************************************
//**********************************************************************************************************
double hxtPointGenQuadScaledJacobian(double *p0, double *p1, double *p2, double *p3, int *badNode)
{

  double L0[3] = {p1[0]-p0[0],p1[1]-p0[1],p1[2]-p0[2]};
  double L1[3] = {p2[0]-p1[0],p2[1]-p1[1],p2[2]-p1[2]};
  double L2[3] = {p3[0]-p2[0],p3[1]-p2[1],p3[2]-p2[2]};
  double L3[3] = {p0[0]-p3[0],p0[1]-p3[1],p0[2]-p3[2]};

  double X1[3] = {(p1[0]-p0[0]) + (p2[0]-p3[0]), 
                  (p1[1]-p0[1]) + (p2[1]-p3[1]), 
                  (p1[2]-p0[2]) + (p2[2]-p3[2])}; 

  double X2[3] = {(p2[0]-p1[0]) + (p3[0]-p0[0]), 
                  (p2[1]-p1[1]) + (p3[1]-p0[1]), 
                  (p2[2]-p1[2]) + (p3[2]-p0[2])}; 

  double N0[3];
  HXT_CHECK(myCrossprod(L3,L0,N0));
  double N1[3];
  HXT_CHECK(myCrossprod(L0,L1,N1));
  double N2[3];
  HXT_CHECK(myCrossprod(L1,L2,N2));
  double N3[3];
  HXT_CHECK(myCrossprod(L2,L3,N3));
  double Nc[3];
  HXT_CHECK(myCrossprod(X1,X2,Nc));
  if (norm(Nc) < 1.e-10){
    return 0.;
  }


  HXT_CHECK(normalize(Nc));
  double a0 = myDot(Nc,N0);
  double a1 = myDot(Nc,N1);
  double a2 = myDot(Nc,N2);
  double a3 = myDot(Nc,N3);
  double len0 = norm(L0);
  double len1 = norm(L1);
  double len2 = norm(L2);
  double len3 = norm(L3);

  double sjac = a0/(len0*len3) < a1/(len0*len1) ? a0/(len0*len3) : a1/(len0*len1);

  sjac = sjac < a2/(len1*len2) ? sjac : a2/(len1*len2) ;
  sjac = sjac < a3/(len2*len3) ? sjac : a3/(len2*len3) ;

  //TODO delete except of index 
  double sjacN = 1;
  uint32_t index = UINT32_MAX;

  if (a0/(len0*len3) < a1/(len0*len1)){
    sjacN = a0/(len0*len3);
    index = 0;
  }
  else{
    sjacN = a1/(len0*len1);
    index = 1;
  }

  if (sjacN < (a2/(len1*len2)) ){
  }
  else{
    sjacN = a2/(len1*len2);
    index = 2;
  }

  if (sjacN < (a3/(len2*len3)) ){
  }
  else{
    sjacN = a3/(len2*len3);
    index = 3;
  }

  *badNode = index;



  return sjac;

  /*double quad_scaled_jacobian(const std::array<vec3,4>& pts) {*/
    /*//  Based on Sandia Verdict document */
    /*const vec3 L0 = pts[1] - pts[0];*/
    /*const vec3 L1 = pts[2] - pts[1];*/
    /*const vec3 L2 = pts[3] - pts[2];*/
    /*const vec3 L3 = pts[0] - pts[3];*/
    /*const vec3 X1 = (pts[1]-pts[0]) + (pts[2] - pts[3]);*/
    /*const vec3 X2 = (pts[2]-pts[1]) + (pts[3] - pts[0]);*/
    /*const vec3 N0 = cross(L3,L0);*/
    /*const vec3 N1 = cross(L0,L1);*/
    /*const vec3 N2 = cross(L1,L2);*/
    /*const vec3 N3 = cross(L2,L3);*/
    /*const vec3 Nc = cross(X1,X2);*/
    /*if (length(Nc) < 1.e-10) {*/
      /*return 0.;*/
    /*}*/
    /*const vec3 nc = normalize(Nc);*/
    /*const double a0 = dot(nc,N0);*/
    /*const double a1 = dot(nc,N1);*/
    /*const double a2 = dot(nc,N2);*/
    /*const double a3 = dot(nc,N3);*/
    /*const double len0 = length(L0);*/
    /*const double len1 = length(L1);*/
    /*const double len2 = length(L2);*/
    /*const double len3 = length(L3);*/
    /*double sjac = std::min(a0/(len0*len3),a1/(len0*len1));*/
    /*sjac = std::min(sjac,a2/(len1*len2));*/
    /*sjac = std::min(sjac,a3/(len2*len3));*/
    /*return sjac;*/
  /*}*/

}


//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION: find closest triangle from rtree 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenProjectCloseRTree(HXTMesh *omesh, 
                                      void *dataTri,
                                      uint64_t ot,   // assigned triangle
                                      double *pp,
                                      uint64_t *nt,
                                      double *np)
{
  //============================================================================
  // Define a box size to search 
  // taking into account the lenghts of the original triangle
  double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*ot+0];
  double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*ot+1];
  double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*ot+2];
  double size = distance(p0,p1);

  size = 0;
  double s[3] = {0,0,0};
  s[0] = distance(pp,p0);
  s[1] = distance(pp,p1);
  s[2] = distance(pp,p2);

  for (uint32_t i=0; i<3; i++)
    if (s[i]>size) size = s[i];

  double box = 1*size;
  

  double ppmin[3] = {pp[0] - box, pp[1] - box, pp[2] - box};
  double ppmax[3] = {pp[0] + box, pp[1] + box, pp[2] + box};
 
  //============================================================================
  // Find close triangles from RTree of triangles  
  uint64_t numCloseTris = 0;
  uint64_t *idCloseTris = NULL;
  HXT_CHECK(hxtRTreeSearch64(ppmin,ppmax,&numCloseTris,&idCloseTris,dataTri));

  //printf("%lu %f %f \n", numCloseTris, size, distance(p0,pp));

  if (numCloseTris == 0){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Did not find close triangle, fix it !!!");
    // SEARCH ALL TRIANGLES
    //double tol = 10e-7;
    //double dist,t,closePt[3];
    double dist,closePt[3];
    double minDist = 10e12;
    for (uint32_t i=0; i<omesh->triangles.num; i++){
  
      if (omesh->triangles.color[i] != omesh->triangles.color[ot]) continue;
  
        double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+0];
        double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+1];
        double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+2];
        int inside = 0;
        HXT_CHECK(hxtSignedDistancePointTriangle(p0,p1,p2,pp,&dist,&inside,closePt));
  
        if (fabs(dist)<minDist && omesh->triangles.color[ot] == omesh->triangles.color[i]){
          minDist = fabs(dist);
          *nt = i;
          np[0] = closePt[0];
          np[1] = closePt[1];
          np[2] = closePt[2];
        }
    }
  }
  else{

    double minDist = 10e12;

    for (uint64_t i=0; i<numCloseTris; i++){
      uint64_t tri = idCloseTris[i];
      double dist, closePt[3];
      int in = 0;
      HXT_CHECK(hxtSignedDistancePointTriangle(&omesh->vertices.coord[4*omesh->triangles.node[3*tri+0]],
                                               &omesh->vertices.coord[4*omesh->triangles.node[3*tri+1]],
                                               &omesh->vertices.coord[4*omesh->triangles.node[3*tri+2]],
                                               pp,
                                               &dist,
                                               &in,
                                               closePt));

      if (fabs(dist)<minDist && omesh->triangles.color[ot] == omesh->triangles.color[tri]){
        minDist = fabs(dist);
        *nt = tri;
        np[0] = closePt[0];
        np[1] = closePt[1];
        np[2] = closePt[2];
      }

    }

  }

  HXT_CHECK(hxtFree(&idCloseTris));

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
// TODO 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshRemoveDoublets(HXTPointGenOptions *opt, 
                                    HXTMesh *omesh,
                                    void *dataTri,
                                    uint64_t *p2t,
                                    HXTMesh *mesh, 
                                    uint64_t *v2q,
                                    uint64_t maxValence,
                                    uint32_t *isBoundary)
{
  //===========================================================================
  // Count valence of each vertex 

  uint64_t *vertexValence;
  HXT_CHECK(hxtMalloc(&vertexValence,mesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) vertexValence[i] = 0;

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    for (uint64_t j=0; j<maxValence; j++){
      if (v2q[maxValence*i+j] == UINT64_MAX) break;
      vertexValence[i]++;
    }
  }

  //===========================================================================
  // Check if there are doublets to be removed
  int countDoublets = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (isBoundary[i] == 1) continue;
    if (vertexValence[i] == 2) countDoublets++;
    if (vertexValence[i] == 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Vertex with only one quad!");
  }
  HXT_INFO_COND(opt->verbosity>=2,"    - %d doublets to be removed",countDoublets);
  if(countDoublets==0){
    HXT_CHECK(hxtFree(&vertexValence));
    return HXT_STATUS_OK;
  }



  //===========================================================================
  // Remove doublets and diamonds 
  
  typedef struct vert{
    double v[3];
    uint64_t p2t;
    uint32_t isBoundary;
    uint32_t newInd;
  }Vert;

  // Filling structure of vertices
  Vert *vInfo;
  HXT_CHECK(hxtMalloc(&vInfo,sizeof(Vert)*mesh->vertices.num));
  
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    vInfo[i].v[0] = mesh->vertices.coord[4*i+0];
    vInfo[i].v[1] = mesh->vertices.coord[4*i+1];
    vInfo[i].v[2] = mesh->vertices.coord[4*i+2];
    vInfo[i].p2t = p2t[i];
    vInfo[i].isBoundary = isBoundary[i];
    vInfo[i].newInd = i;
  } 



  /*FILE *test;*/
  /*hxtPosInit("diamonds.pos","diamonds",&test);*/
    
  uint64_t countDeletedQuads = 0;
  for (uint64_t i=0; i<mesh->quads.num; i++){

    int doNot = 0;
    for (uint32_t j=0; j<4; j++){
      if (vertexValence[mesh->quads.node[4*i+j]]==0) doNot = 1;
      if (vertexValence[mesh->quads.node[4*i+j]]==UINT64_MAX) doNot = 1;
    }
    if (doNot) continue;


    int isDiamond = 0;
    for (uint32_t j=0; j<4; j++){

      uint32_t index0 = j;
      uint32_t index1 = (j+2)%4;

      uint32_t v0 = mesh->quads.node[4*i+index0];
      uint32_t v1 = mesh->quads.node[4*i+index1];

      if (isBoundary[v0] == 1 && isBoundary[v1] == 1) continue;

      // check if the other two vertices are on the boundary as well
      uint32_t index3 = (j+1)%4;
      uint32_t index4 = (j+3)%4;
      uint32_t ov0 = mesh->quads.node[4*i+index3];
      uint32_t ov1 = mesh->quads.node[4*i+index4];

      if (isBoundary[v0] != 1 && isBoundary[v1] != 1){
      }
      else{
        if (isBoundary[ov0] == 1 || isBoundary[ov1] == 1) continue;
      }



      if (vertexValence[v0] == 3 && vertexValence[v1] == 3){
        isDiamond = 1;
        uint32_t *v = mesh->quads.node + 4*i;
        for (uint32_t j=0; j<4; j++) vertexValence[v[j]] = 0;

        if (isBoundary[v0] == 1){
          vInfo[v1].newInd = v0;
          mesh->quads.color[i] = UINT16_MAX;
          vertexValence[v1] = UINT64_MAX;
        }
        else if (isBoundary[v1] == 1){
          vInfo[v0].newInd = v1;
          mesh->quads.color[i] = UINT16_MAX;
          vertexValence[v0] = UINT64_MAX;
        }
        else{
          vInfo[v0].newInd = v1;
          mesh->quads.color[i] = UINT16_MAX;
          vertexValence[v0] = UINT64_MAX;
        }

        countDeletedQuads++;

        break;
      }
    }

/*    if (isDiamond){*/
      /*uint32_t *v = mesh->quads.node + 4*i;*/
      /*double *p0 = mesh->vertices.coord + 4*v[0];*/
      /*double *p1 = mesh->vertices.coord + 4*v[1];*/
      /*double *p2 = mesh->vertices.coord + 4*v[2];*/
      /*double *p3 = mesh->vertices.coord + 4*v[3];*/

      /*hxtPosAddQuad(test,p0,p1,p2,p3,0);*/
/*    }*/
  }

  /*hxtPosNewView(test,"doublets");*/

  for (uint64_t i=0; i<mesh->quads.num; i++){

    int doNot = 0;
    for (uint32_t j=0; j<4; j++){
      if (vertexValence[mesh->quads.node[4*i+j]]==0) doNot = 1;
      if (vertexValence[mesh->quads.node[4*i+j]]==UINT64_MAX) doNot = 1;
    }
    if (doNot) continue;

    int isDoublet = 0;
    for (uint32_t j=0; j<4; j++){

      uint32_t index0 = j;
      uint32_t index1 = (j+2)%4;

      uint32_t v0 = mesh->quads.node[4*i+index0];
      uint32_t v1 = mesh->quads.node[4*i+index1];

      if (vertexValence[v0] == 2 && isBoundary[v0] != 1){
        isDoublet = 1;
        uint32_t *v = mesh->quads.node + 4*i;
        for (uint32_t j=0; j<4; j++) vertexValence[v[j]] = 0;

        vInfo[v0].newInd = v1;
        mesh->quads.color[i] = UINT16_MAX;
        vertexValence[v0] = UINT64_MAX;

        countDeletedQuads++;

        break;
      }
    }

    /*if (isDoublet){*/
      /*uint32_t *v = mesh->quads.node + 4*i;*/
      /*double *p0 = mesh->vertices.coord + 4*v[0];*/
      /*double *p1 = mesh->vertices.coord + 4*v[1];*/
      /*double *p2 = mesh->vertices.coord + 4*v[2];*/
      /*double *p3 = mesh->vertices.coord + 4*v[3];*/

      /*hxtPosAddQuad(test,p0,p1,p2,p3,0);*/
    /*}*/
  }
  /*hxtPosFinish(test);*/


  //===========================================================================
  // New index of vertices on quads
  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;
    v[0] = vInfo[v[0]].newInd;
    v[1] = vInfo[v[1]].newInd;
    v[2] = vInfo[v[2]].newInd;
    v[3] = vInfo[v[3]].newInd;

  }


  //===========================================================================
  // Create quads
  uint32_t *quads;
  uint16_t *col;
  HXT_CHECK(hxtMalloc(&quads,(4*mesh->quads.size)*sizeof(uint32_t)));
  HXT_CHECK(hxtMalloc(&col,(1*mesh->quads.size)*sizeof(uint16_t)));

  uint64_t cQ = 0;
  for (uint64_t i=0; i<mesh->quads.num; i++){
    if (mesh->quads.color[i] == UINT16_MAX) continue;
    quads[4*cQ+0] = mesh->quads.node[4*i+0];
    quads[4*cQ+1] = mesh->quads.node[4*i+1];
    quads[4*cQ+2] = mesh->quads.node[4*i+2];
    quads[4*cQ+3] = mesh->quads.node[4*i+3];
    col[cQ] = mesh->quads.color[i];
    cQ++;
  }

  for (uint64_t i=0; i<cQ; i++){
    mesh->quads.node[4*i+0] = quads[4*i+0];
    mesh->quads.node[4*i+1] = quads[4*i+1];
    mesh->quads.node[4*i+2] = quads[4*i+2];
    mesh->quads.node[4*i+3] = quads[4*i+3];
    mesh->quads.color[i] = col[i];
  }
  mesh->quads.num = cQ;

  HXT_CHECK(hxtFree(&quads));
  HXT_CHECK(hxtFree(&col));


  //===========================================================================
  // New vertices 
  uint32_t countVertices = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (vertexValence[i] == UINT64_MAX) continue;

    mesh->vertices.coord[4*countVertices+0] = vInfo[i].v[0];
    mesh->vertices.coord[4*countVertices+1] = vInfo[i].v[1];
    mesh->vertices.coord[4*countVertices+2] = vInfo[i].v[2];
    p2t[countVertices] = vInfo[i].p2t;
    isBoundary[countVertices] = vInfo[i].isBoundary;
    vInfo[i].newInd = countVertices;
    countVertices++;
  }

  mesh->vertices.num = countVertices;


  if(opt->verbosity>=2) HXT_CHECK(hxtMeshWriteGmsh(mesh,"beforeDoubletsQuads.msh"));
 
  //===========================================================================
  // Relabel quad vertices
  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;
    v[0] = vInfo[v[0]].newInd;
    v[1] = vInfo[v[1]].newInd;
    v[2] = vInfo[v[2]].newInd;
    v[3] = vInfo[v[3]].newInd;
  }

  //===========================================================================
  // Relabel lines vertices
  for (uint64_t i=0; i<mesh->lines.num; i++){
    uint32_t *v = mesh->lines.node + 2*i;
    v[0] = vInfo[v[0]].newInd;
    v[1] = vInfo[v[1]].newInd;
  }
 
  //===========================================================================
  // Relabel points vertices
  for (uint64_t i=0; i<mesh->points.num; i++){
    mesh->points.node[i] = vInfo[mesh->points.node[i]].newInd;
  }



  if(opt->verbosity>=2) HXT_CHECK(hxtMeshWriteGmsh(mesh,"afterDoubletsQuads.msh"));


  return HXT_STATUS_OK; 

}
 

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshBuildV2Q(HXTPointGenOptions *opt, 
                              HXTMesh *mesh, 
                              uint64_t **v2q_out, 
                              uint64_t *maxValence_out)
{

  uint64_t *cv2q;
  HXT_CHECK(hxtMalloc(&cv2q, mesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) cv2q[i] = 0;

  uint32_t maxValence = 0;
  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;

    for (uint32_t j=0; j<4; j++){
      cv2q[v[j]]++;
      if (cv2q[v[j]] > maxValence) maxValence = cv2q[v[j]];
    }
  }
  HXT_INFO_COND(opt->verbosity>=2,"    - Max valence = %d", maxValence); 
  HXT_CHECK(hxtFree(&cv2q));

  uint64_t *v2q;
  HXT_CHECK(hxtMalloc(&v2q, maxValence*mesh->vertices.num*sizeof(uint64_t)));
  for (uint64_t i=0; i<maxValence*mesh->vertices.num; i++) v2q[i] = UINT64_MAX;


  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;

    for (uint32_t j=0; j<4; j++){
      for (uint32_t k=0; k<maxValence; k++){
        if (v2q[maxValence*v[j]+k] == UINT64_MAX){
          v2q[maxValence*v[j]+k] = i;
           break;
        }
      }
    }
  }

  *v2q_out = v2q;
  *maxValence_out = maxValence;


  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION TODO delete, not used  
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshFans(HXTPointGenOptions *opt, 
                         HXTMesh *mesh, 
                         uint64_t *v2q,
                         uint64_t maxValence,
                         uint32_t *isBoundary,
                         uint32_t vertex)
{


  {
    FILE *test;
    hxtPosInit("checkBoundary.pos","quads",&test);

    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] != 1) continue;
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
    }

    hxtPosFinish(test);
  }

  FILE *test;
  hxtPosInit("checkQuadFan.pos","quads",&test);

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    uint64_t countQuads = 0; 
    for (uint64_t j=0; j<maxValence; j++){
      if (v2q[maxValence*i+j] == UINT64_MAX) break;
      countQuads++;
    }

    if (isBoundary[i] != 1){

      hxtPosNewView(test,"vert %d",i);
      for (uint64_t j=0; j<countQuads; j++){
        hxtPosNewView(test,"  quad %d",j);
        uint32_t *v = mesh->quads.node + 4*v2q[maxValence*i+j];
        double *p0 = mesh->vertices.coord + 4*v[0];
        double *p1 = mesh->vertices.coord + 4*v[1];
        double *p2 = mesh->vertices.coord + 4*v[2];
        double *p3 = mesh->vertices.coord + 4*v[3];
        hxtPosAddQuad(test,p0,p1,p2,p3,0);
        hxtPosAddText(test,p0,"0");
        hxtPosAddText(test,p1,"1");
        hxtPosAddText(test,p2,"2");
        hxtPosAddText(test,p3,"3");

        hxtPosNewView(test,"  q nodes");
        hxtPosAddText(test,p0,"%d",v[0]);
        hxtPosAddText(test,p1,"%d",v[1]);
        hxtPosAddText(test,p2,"%d",v[2]);
        hxtPosAddText(test,p3,"%d",v[3]);
      }
      break;
    }
  }
  hxtPosFinish(test);



  // TODO this can be outside the function 
  uint64_t *fanQuads;
  uint32_t *fanNodes;
  HXT_CHECK(hxtMalloc(&fanQuads,maxValence*sizeof(uint64_t)));
  HXT_CHECK(hxtMalloc(&fanNodes,2*maxValence*sizeof(uint32_t)));


  for (uint32_t i=0; i<mesh->vertices.num; i++){

    if (isBoundary[i] == 1) continue;

    for (uint64_t k=0; k<maxValence; k++) fanQuads[k] = UINT64_MAX;
    for (uint64_t k=0; k<2*maxValence; k++) fanNodes[k] = UINT32_MAX;

    uint64_t countQuads = 0; 
    for (uint64_t j=0; j<maxValence; j++){
      if (v2q[maxValence*i+j] == UINT64_MAX) break;
      countQuads++;
    }

    printf("%d\n",i);

    uint64_t firstQuad = v2q[maxValence*i+0];

    uint32_t nodeIndex = UINT32_MAX;
    for (uint32_t j=0; j<4; j++)
      if (mesh->quads.node[4*firstQuad+j] == i) nodeIndex = j;

    uint32_t firstNode = mesh->quads.node[4*firstQuad+(nodeIndex+3)%4];
    uint32_t lastNode =  mesh->quads.node[4*firstQuad+(nodeIndex+1)%4];
    uint32_t medNode =  mesh->quads.node[4*firstQuad+(nodeIndex+2)%4];

    uint64_t currQuad = firstQuad;
    uint32_t currNode = firstNode;

    uint64_t qcounter = 0;
    fanQuads[countQuads-1] = currQuad;
    fanNodes[2*qcounter+0] = currNode;
    fanNodes[2*(countQuads-1)+1] = medNode;
    qcounter++;

    
    printf("   %d %d\n", firstNode, lastNode);

    while(1){

      for (uint64_t j=1; j<countQuads; j++){
        uint64_t cq = v2q[maxValence*i+j];
        if (cq == currQuad)continue;

        for (uint32_t k=0; k<4; k++){

          uint32_t cn = mesh->quads.node[4*cq+k];

          if (cn != currNode) continue;

          uint32_t nextNode1 = mesh->quads.node[4*cq+(k+1)%4];
          uint32_t nextNode2 = mesh->quads.node[4*cq+(k+2)%4];

          printf("   %d %d \n", nextNode1, nextNode2); 

          currQuad = cq;
          currNode = nextNode2;

          fanQuads[qcounter-1] = currQuad;
          fanNodes[2*qcounter-1] = nextNode1;
          fanNodes[2*qcounter+0] = nextNode2;
          qcounter++;
          break;

        }

      }
      if (currNode == lastNode){
        break;
      }

    }

    for (uint64_t k=0; k<countQuads; k++){
      printf("%d %d \n", fanNodes[2*k+0], fanNodes[2*k+1]);
    }

  }


  HXT_CHECK(hxtFree(&fanQuads));
  HXT_CHECK(hxtFree(&fanNodes));

  return HXT_STATUS_OK; 
  
}


//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshFan(HXTPointGenOptions *opt, 
                         HXTMesh *mesh, 
                         uint64_t *v2q,
                         uint64_t maxValence,
                         uint32_t *isBoundary,
                         uint32_t v,
                         uint64_t *numQuads,
                         uint64_t *fanQuads,
                         uint32_t *fanNodes)
{

  *numQuads = 0;
  for (uint64_t k=0; k<maxValence; k++) fanQuads[k] = UINT64_MAX;
  for (uint64_t k=0; k<2*maxValence; k++) fanNodes[k] = UINT32_MAX;

  uint64_t countQuads = 0; 
  for (uint64_t j=0; j<maxValence; j++){
    if (v2q[maxValence*v+j] == UINT64_MAX) break;
    countQuads++;
  }

  uint64_t firstQuad = v2q[maxValence*v+0];

  uint32_t nodeIndex = UINT32_MAX;
  for (uint32_t j=0; j<4; j++)
    if (mesh->quads.node[4*firstQuad+j] == v) nodeIndex = j;

  uint32_t firstNode = mesh->quads.node[4*firstQuad+(nodeIndex+3)%4];
  uint32_t lastNode =  mesh->quads.node[4*firstQuad+(nodeIndex+1)%4];
  uint32_t medNode =  mesh->quads.node[4*firstQuad+(nodeIndex+2)%4];

  uint64_t currQuad = firstQuad;
  uint32_t currNode = firstNode;

  uint64_t qcounter = 0;
  fanQuads[countQuads-1] = currQuad;
  fanNodes[2*qcounter+0] = currNode;
  fanNodes[2*(countQuads-1)+1] = medNode;
  qcounter++;

  
  int iter = 0;
  while(1){

    for (uint64_t j=1; j<countQuads; j++){
      uint64_t cq = v2q[maxValence*v+j];
      if (cq == currQuad)continue;

      for (uint32_t k=0; k<4; k++){

        uint32_t cn = mesh->quads.node[4*cq+k];

        if (cn != currNode) continue;

        uint32_t nextNode1 = mesh->quads.node[4*cq+(k+1)%4];
        uint32_t nextNode2 = mesh->quads.node[4*cq+(k+2)%4];

        currQuad = cq;
        currNode = nextNode2;

        fanQuads[qcounter-1] = currQuad;
        fanNodes[2*qcounter-1] = nextNode1;
        fanNodes[2*qcounter+0] = nextNode2;
        qcounter++;
        break;

      }

    }
    if (currNode == lastNode){
      break;
    }

    iter++;
    if (iter>maxValence){
      printf("here\n");
      FILE *test;
      hxtPosInit("badVertex.pos","vertex",&test);
      hxtPosAddPoint(test,&mesh->vertices.coord[4*v],0);
      hxtPosFinish(test);
      return HXT_STATUS_ERROR;
    }

  }


  *numQuads = countQuads;

  return HXT_STATUS_OK; 
  
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshSmoothConcave(HXTPointGenOptions *opt, 
                                   HXTMesh *omesh,
                                   void *dataTri,
                                   uint64_t *p2t,
                                   HXTMesh *mesh, 
                                   uint32_t *isBoundary,
                                   uint64_t numQuads,
                                   uint64_t *fanQuads,
                                   uint32_t *fanNodes,
                                   uint32_t concaveVertex,
                                   uint32_t v)
{

  HXT_INFO_COND(opt->verbosity>=2,"      - Smoothing of concave vertex %d", v);

  char buf[40];
  snprintf(buf, 40, "checkConcave_%d.msh", v); // puts string into buffer
 
  FILE *test;
  hxtPosInit(buf,"quads",&test);
  hxtPosAddPoint(test,&mesh->vertices.coord[4*concaveVertex],0);
  for (uint64_t j=0; j<numQuads; j++){
    uint64_t cq = fanQuads[j];

    uint32_t *v = mesh->quads.node + 4*cq;

    double *p0 = mesh->vertices.coord + 4*v[0];
    double *p1 = mesh->vertices.coord + 4*v[1];
    double *p2 = mesh->vertices.coord + 4*v[2];
    double *p3 = mesh->vertices.coord + 4*v[3];

    hxtPosAddQuad(test,p0,p1,p2,p3,0);
  }
  hxtPosFinish(test);



  int negative = 0;

  for (uint64_t j=0; j<numQuads; j++){
    uint64_t cq = fanQuads[j];

    uint32_t *v = mesh->quads.node + 4*cq;

    double *p0 = mesh->vertices.coord + 4*v[0];
    double *p1 = mesh->vertices.coord + 4*v[1];
    double *p2 = mesh->vertices.coord + 4*v[2];
    double *p3 = mesh->vertices.coord + 4*v[3];

    int temp = UINT32_MAX;
    double qual = hxtPointGenQuadScaledJacobian(p0,p1,p2,p3,&temp);

    if (qual<=0.0) negative = 1;

  }

  if (negative == 0){
    return HXT_STATUS_OK; 
  }


  // Get average normal of quad fan
  double n[3] = {0,0,0}; 
  for (uint64_t j=0; j<numQuads; j++){
    uint64_t cq = fanQuads[j];
    uint32_t *v = mesh->quads.node + 4*cq;
    double *p0 = mesh->vertices.coord + 4*v[0];
    double *p1 = mesh->vertices.coord + 4*v[1];
    double *p2 = mesh->vertices.coord + 4*v[2];
    double *p3 = mesh->vertices.coord + 4*v[3];

    double n0[3] = {0,0,0};
    double n1[3] = {0,0,0};
    normal2triangleV(p0,p1,p2,n0);
    normal2triangleV(p2,p3,p0,n1);

    double nt[3] = {(n0[0]+n1[0])/2,(n0[1]+n1[1])/2,(n0[2]+n1[2])/2};
    normalize(nt);

    n[0]+=nt[0];
    n[1]+=nt[1];
    n[2]+=nt[2];
  }
  n[0]/=numQuads;
  n[1]/=numQuads;
  n[2]/=numQuads;


  // Compute boundary angles
  uint32_t badVertex = UINT32_MAX;

  for (uint64_t j=0; j<numQuads; j++){
    
    uint32_t index = 2*j+0; 

    uint32_t prev = (index-1)%(2*numQuads);
    uint32_t next = (index+1)%(2*numQuads);

    double *p0 = mesh->vertices.coord + 4*fanNodes[prev];
    double *p1 = mesh->vertices.coord + 4*fanNodes[index];
    double *p2 = mesh->vertices.coord + 4*fanNodes[next];

    double vec0[3] ={0,0,0};
    double vec1[3] ={0,0,0};
    hxtVector(p1,p0,vec0);
    hxtVector(p1,p2,vec1);

    double angle = 180 * hxtAngle_0_2pi(vec0, vec1, n) / M_PI;

    int countBoundary = isBoundary[fanNodes[prev]]+isBoundary[fanNodes[index]]+isBoundary[fanNodes[next]];

    if (angle<100 && countBoundary>=2 && isBoundary[fanNodes[index]]==1 ){

      badVertex = index;
    }
  }

  if (badVertex == UINT32_MAX){ 
    return HXT_STATUS_OK; 
  }


  // Comute bad vertex edges vectors 
  uint32_t prev = (badVertex-1)%(2*numQuads);
  uint32_t next = (badVertex+1)%(2*numQuads);

  double *p0 = mesh->vertices.coord + 4*fanNodes[prev];
  double *p1 = mesh->vertices.coord + 4*fanNodes[badVertex];
  double *p2 = mesh->vertices.coord + 4*fanNodes[next];

  double vec0[3] ={0,0,0};
  double vec1[3] ={0,0,0};
  hxtVector(p0,p1,vec0);
  hxtVector(p2,p1,vec1);

  double vec[3] = {0,0,0};

  vec[0] = (vec0[0]+vec1[0])/2;
  vec[1] = (vec0[1]+vec1[1])/2;
  vec[2] = (vec0[2]+vec1[2])/2;
  normalize(vec);

  // Find minimum distance of edges of the quad fan 
  double minDist = 10e12;
  for (uint64_t j=0; j<numQuads; j++){

    uint32_t v0 = j;
    uint32_t v1 = (j+1)%(2*numQuads);

    double *p0 = mesh->vertices.coord + 4*fanNodes[v0];
    double *p1 = mesh->vertices.coord + 4*fanNodes[v1];

    double dist = distance(p0,p1);

    if (dist < minDist) minDist = dist;
 
  }
  minDist = minDist*0.1;


  double newpoint[3];

  newpoint[0] = mesh->vertices.coord[4*fanNodes[badVertex]+0] + vec[0]*minDist;
  newpoint[1] = mesh->vertices.coord[4*fanNodes[badVertex]+1] + vec[1]*minDist;
  newpoint[2] = mesh->vertices.coord[4*fanNodes[badVertex]+2] + vec[2]*minDist;


  mesh->vertices.coord[4*v+0] = newpoint[0];
  mesh->vertices.coord[4*v+1] = newpoint[1];
  mesh->vertices.coord[4*v+2] = newpoint[2];
     

  // Project point back to initial triangulation 
  uint64_t nt = p2t[v];
  if (p2t[v] == UINT64_MAX) return HXT_STATUS_ERROR;
  double np[3] = {mesh->vertices.coord[4*v+0],mesh->vertices.coord[4*v+1],mesh->vertices.coord[4*v+2]};

  HXT_CHECK(hxtPointGenProjectCloseRTree(omesh,dataTri,p2t[v],&mesh->vertices.coord[4*v],&nt,np));

  p2t[v] = nt;
  mesh->vertices.coord[4*v+0] = np[0];
  mesh->vertices.coord[4*v+1] = np[1];
  mesh->vertices.coord[4*v+2] = np[2];


  negative = 0;
  for (uint64_t i=0; i<numQuads; i++){
    uint64_t cq = fanQuads[i];

    uint32_t *v = mesh->quads.node + 4*cq;

    double *p0 = mesh->vertices.coord + 4*v[0];
    double *p1 = mesh->vertices.coord + 4*v[1];
    double *p2 = mesh->vertices.coord + 4*v[2];
    double *p3 = mesh->vertices.coord + 4*v[3];

    int temp = UINT32_MAX;
    double qual = hxtPointGenQuadScaledJacobian(p0,p1,p2,p3,&temp);

    if (qual<=0.0) negative = 1;
  }
  if (negative == 0){
    return HXT_STATUS_OK; 
  }
  
  {

    newpoint[0] = mesh->vertices.coord[4*fanNodes[badVertex]+0] + vec0[0]*minDist;
    newpoint[1] = mesh->vertices.coord[4*fanNodes[badVertex]+1] + vec0[1]*minDist;
    newpoint[2] = mesh->vertices.coord[4*fanNodes[badVertex]+2] + vec0[2]*minDist;


    mesh->vertices.coord[4*v+0] = newpoint[0];
    mesh->vertices.coord[4*v+1] = newpoint[1];
    mesh->vertices.coord[4*v+2] = newpoint[2];
       

    // Project point back to initial triangulation 
    uint64_t nt = p2t[v];
    if (p2t[v] == UINT64_MAX) return HXT_STATUS_ERROR;
    double np[3] = {mesh->vertices.coord[4*v+0],mesh->vertices.coord[4*v+1],mesh->vertices.coord[4*v+2]};

    HXT_CHECK(hxtPointGenProjectCloseRTree(omesh,dataTri,p2t[v],&mesh->vertices.coord[4*v],&nt,np));

    p2t[v] = nt;
    mesh->vertices.coord[4*v+0] = np[0];
    mesh->vertices.coord[4*v+1] = np[1];
    mesh->vertices.coord[4*v+2] = np[2];
  }

  negative = 0;
  for (uint64_t i=0; i<numQuads; i++){
    uint64_t cq = fanQuads[i];

    uint32_t *v = mesh->quads.node + 4*cq;

    double *p0 = mesh->vertices.coord + 4*v[0];
    double *p1 = mesh->vertices.coord + 4*v[1];
    double *p2 = mesh->vertices.coord + 4*v[2];
    double *p3 = mesh->vertices.coord + 4*v[3];

    int temp = UINT32_MAX;
    double qual = hxtPointGenQuadScaledJacobian(p0,p1,p2,p3,&temp);

    if (qual<=0.0) negative = 1;
  }
  if (negative == 0){
    return HXT_STATUS_OK; 
  }

  {

    newpoint[0] = mesh->vertices.coord[4*fanNodes[badVertex]+0] + vec1[0]*minDist;
    newpoint[1] = mesh->vertices.coord[4*fanNodes[badVertex]+1] + vec1[1]*minDist;
    newpoint[2] = mesh->vertices.coord[4*fanNodes[badVertex]+2] + vec1[2]*minDist;


    mesh->vertices.coord[4*v+0] = newpoint[0];
    mesh->vertices.coord[4*v+1] = newpoint[1];
    mesh->vertices.coord[4*v+2] = newpoint[2];
       
    // Project point back to initial triangulation 
    uint64_t nt = p2t[v];
    if (p2t[v] == UINT64_MAX) return HXT_STATUS_ERROR;
    double np[3] = {mesh->vertices.coord[4*v+0],mesh->vertices.coord[4*v+1],mesh->vertices.coord[4*v+2]};

    HXT_CHECK(hxtPointGenProjectCloseRTree(omesh,dataTri,p2t[v],&mesh->vertices.coord[4*v],&nt,np));

    p2t[v] = nt;
    mesh->vertices.coord[4*v+0] = np[0];
    mesh->vertices.coord[4*v+1] = np[1];
    mesh->vertices.coord[4*v+2] = np[2];
  }





  return HXT_STATUS_OK; 
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshSmoothing(HXTPointGenOptions *opt, 
                               HXTMesh *omesh,
                               void *dataTri,
                               uint64_t *p2t,
                               HXTMesh *mesh, 
                               uint64_t *v2q,
                               uint64_t maxValence,
                               uint32_t *isBoundary)
{

  HXT_INFO_COND(opt->verbosity>=2,"    - Smoothing");

  
  uint64_t numQuads = 0;
  uint64_t *fanQuads;
  uint32_t *fanNodes;
  HXT_CHECK(hxtMalloc(&fanQuads,maxValence*sizeof(uint64_t)));
  HXT_CHECK(hxtMalloc(&fanNodes,2*maxValence*sizeof(uint32_t)));

  for (uint32_t i=0; i<mesh->vertices.num; i++){

    if (isBoundary[i] == 1) continue;

    HXT_CHECK(hxtQuadMeshFan(opt, mesh, v2q, maxValence, isBoundary, i, &numQuads, fanQuads, fanNodes));

    // Get average normal of quad fan
    double n[3] = {0,0,0}; 
    for (uint64_t j=0; j<numQuads; j++){
      uint64_t cq = fanQuads[j];
      uint32_t *v = mesh->quads.node + 4*cq;
      double *p0 = mesh->vertices.coord + 4*v[0];
      double *p1 = mesh->vertices.coord + 4*v[1];
      double *p2 = mesh->vertices.coord + 4*v[2];
      double *p3 = mesh->vertices.coord + 4*v[3];

      double n0[3] = {0,0,0};
      double n1[3] = {0,0,0};
      normal2triangleV(p0,p1,p2,n0);
      normal2triangleV(p2,p3,p0,n1);

      double nt[3] = {(n0[0]+n1[0])/2,(n0[1]+n1[1])/2,(n0[2]+n1[2])/2};
      normalize(nt);

      n[0]+=nt[0];
      n[1]+=nt[1];
      n[2]+=nt[2];
    }
    n[0]/=numQuads;
    n[1]/=numQuads;
    n[2]/=numQuads;

    // Compute boundary angles
    uint32_t concaveVertex = UINT32_MAX;

    for (uint64_t j=0; j<numQuads; j++){
      
      uint32_t index = 2*j+0; 

      uint32_t prev = (index-1)%(2*numQuads);
      uint32_t next = (index+1)%(2*numQuads);

      double *p0 = mesh->vertices.coord + 4*fanNodes[prev];
      double *p1 = mesh->vertices.coord + 4*fanNodes[index];
      double *p2 = mesh->vertices.coord + 4*fanNodes[next];

      double vec0[3] ={0,0,0};
      double vec1[3] ={0,0,0};
      hxtVector(p1,p0,vec0);
      hxtVector(p1,p2,vec1);

      double angle = 180 * hxtAngle_0_2pi(vec0, vec1, n) / M_PI;

      int countBoundary = isBoundary[fanNodes[prev]]+isBoundary[fanNodes[index]]+isBoundary[fanNodes[next]];

      if (angle<120 && countBoundary>=2 && isBoundary[fanNodes[index]]==1 ){

        concaveVertex = fanNodes[index];


      }
  
    }

    // SMOOTHING 
    // If it is concave on the boundary we use a heuristic method to try to not get element crossing
    // TODO would winslow smoothing fix these cases? 
    //
    // Otherwise, simple laplacian smoothing 
    
    if (concaveVertex != UINT32_MAX ){

      uint32_t vertex = i ;
      HXT_CHECK(hxtQuadMeshSmoothConcave(opt,
                                         omesh,
                                         dataTri,
                                         p2t,
                                         mesh,
                                         isBoundary,
                                         numQuads,
                                         fanQuads,
                                         fanNodes,
                                         concaveVertex,
                                         vertex));

    }
    else{

      uint32_t cv = i;
      double x = 0;
      double y = 0;
      double z = 0;

      for (uint64_t j=0; j<numQuads; j++){
        
        uint32_t v0 = fanNodes[2*j+0];
        x+= mesh->vertices.coord[4*v0+0];
        y+= mesh->vertices.coord[4*v0+1];
        z+= mesh->vertices.coord[4*v0+2];
      }

      mesh->vertices.coord[4*cv+0] = x/numQuads;
      mesh->vertices.coord[4*cv+1] = y/numQuads;
      mesh->vertices.coord[4*cv+2] = z/numQuads;
      

      // Project point back to initial triangulation 
      uint64_t nt = p2t[i];
      if (p2t[i] == UINT64_MAX) return HXT_STATUS_ERROR;
      double np[3] = {mesh->vertices.coord[4*cv+0],mesh->vertices.coord[4*cv+1],mesh->vertices.coord[4*cv+2]};

      HXT_CHECK(hxtPointGenProjectCloseRTree(omesh,dataTri,p2t[i],&mesh->vertices.coord[4*cv],&nt,np));

      p2t[i] = nt;
      mesh->vertices.coord[4*cv+0] = np[0];
      mesh->vertices.coord[4*cv+1] = np[1];
      mesh->vertices.coord[4*cv+2] = np[2];
    }
  
  }


  HXT_CHECK(hxtFree(&fanQuads));
  HXT_CHECK(hxtFree(&fanNodes));

  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtQuadMeshOptimize(HXTPointGenOptions *opt, 
                              HXTMesh *omesh,
                              void *dataTri,
                              uint64_t *p2t,
                              HXTMesh *mesh)
{
  HXT_INFO_COND(opt->verbosity>=2,"");
  HXT_INFO_COND(opt->verbosity>=2,"--- Quad mesh optimization ");
  HXT_INFO_COND(opt->verbosity>=2,"");

  clock_t time_pre_start = clock();

  uint64_t *v2q;
  uint64_t maxValence;

  HXT_CHECK(hxtQuadMeshBuildV2Q(opt, mesh, &v2q, &maxValence));


  uint32_t *isBoundary;
  HXT_CHECK(hxtMalloc(&isBoundary,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) isBoundary[i] = 0;
  for (uint64_t i=0; i<mesh->lines.num; i++){
    isBoundary[mesh->lines.node[2*i+0]] = 1;
    isBoundary[mesh->lines.node[2*i+1]] = 1;
  }

  clock_t time_pre_end = clock();


  //===========================================================================
  // Remove doublets 

 
  clock_t time_remove_start = clock();

  uint32_t numberIter = 10;
  for (uint32_t iter = 0; iter<numberIter; iter++){

    HXT_INFO_COND(opt->verbosity>=2,"");
    HXT_INFO_COND(opt->verbosity>=2,"    Removing doublets and diamonds - Iteration %d",iter);

    /*if (opt->verbosity>=2){*/
      /*char buf[20];*/
      /*snprintf(buf, 20, "mesh_%d.msh", iter); // puts string into buffer*/
      /*HXT_CHECK(hxtMeshWriteGmsh(mesh,buf));*/
    /*}*/

    HXT_INFO_COND(opt->verbosity>=2,"    - Build v2v");
    HXT_CHECK(hxtQuadMeshBuildV2Q(opt, mesh, &v2q, &maxValence));

    HXT_INFO_COND(opt->verbosity>=2,"    - Remove doublets and diamonds");
    HXT_CHECK(hxtQuadMeshRemoveDoublets(opt,omesh, dataTri, p2t, mesh,v2q,maxValence,isBoundary));

  }

  clock_t time_remove_end = clock();

  clock_t time_smooth_final_start = clock();

  HXT_INFO_COND(opt->verbosity>=2,"");
  HXT_INFO_COND(opt->verbosity>=2,"    Final Smoothing");
  HXT_INFO_COND(opt->verbosity>=2,"    - Build v2v");
  HXT_CHECK(hxtQuadMeshBuildV2Q(opt, mesh, &v2q, &maxValence));

  HXT_CHECK(hxtQuadMeshSmoothing(opt,omesh, dataTri, p2t, mesh,v2q,maxValence,isBoundary));
  /*HXT_CHECK(hxtQuadMeshSmoothing(opt,omesh, dataTri, p2t, mesh,v2q,maxValence,isBoundary));*/
  HXT_INFO_COND(opt->verbosity>=2,"");

  clock_t time_smooth_final_end = clock();


  double time_pre          =    (double)(time_pre_end          - time_pre_start)          / CLOCKS_PER_SEC;
  double time_remove       =    (double)(time_remove_end       - time_remove_start)       / CLOCKS_PER_SEC;
  double time_smooth_final =    (double)(time_smooth_final_end - time_smooth_final_start) / CLOCKS_PER_SEC;
  double time_total        =    (double)(time_smooth_final_end - time_pre_start)          / CLOCKS_PER_SEC;

  HXT_INFO_COND(opt->verbosity>=0,"PointGen | Optimization Timings");
  HXT_INFO_COND(opt->verbosity>=0,"           Pre            %f", time_pre);
  HXT_INFO_COND(opt->verbosity>=0,"           Remove         %f", time_remove);
  HXT_INFO_COND(opt->verbosity>=0,"           Smooth final   %f", time_smooth_final);
  HXT_INFO_COND(opt->verbosity>=0,"           Total          %f", time_total);



  HXT_CHECK(hxtFree(&isBoundary));
  HXT_CHECK(hxtFree(&v2q));

  return HXT_STATUS_OK;
}
