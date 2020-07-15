#include "hxt_tools.h"
#include "hxt_edge.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_realloc.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"
#include "hxt_point_gen_2d.h"

#include "hxt_split_edge.h"

//#include "hxt_point_gen_realloc.h"
//#include "hxt_split_edge.h"

#include "hxt_post_debugging.h"

uint32_t hammingDistance(uint32_t n1, uint32_t n2)
{

  uint32_t x = n1^n2;
  int setBits = 0;
  
  while (x>0){
    setBits += x&1;
    x >>= 1;
  }
  return setBits;
}

//**********************************************************************************************************
//**********************************************************************************************************
// FUNCTION to export right-angles quality based on a 
//          simple calculation based on distance from the circumference
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtSurfaceMeshExportTriangleQuality(HXTMesh *nmesh, const double *sizemap)
{
  HXT_UNUSED(sizemap);

  //********************************************************************************
  // Compute quality for all triangles
  //********************************************************************************
  
  double *qual;
  HXT_CHECK(hxtMalloc(&qual,nmesh->triangles.num*sizeof(double)));
  for (uint64_t i=0; i<nmesh->triangles.num; i++) qual[i] = 0;

  FILE* out;
  hxtPosInit("checkQuality.pos","Scalar",&out);
  for (uint32_t i=0; i<nmesh->triangles.num; i++){
    if (nmesh->triangles.colors[i] == UINT16_MAX) continue;
    double *p0 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+0];
    double *p1 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+1];
    double *p2 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+2];
    qual[i] = hxtRightAngledQualitySimple(p0,p1,p2);
    //hxtPosAddTriangle2(out,p0,p1,p2,qual[i]);
  }

  // Normalize quality 
  double minQ = 1;
  double maxQ = 0;
  for (uint64_t i=0; i<nmesh->triangles.num; i++){
    if (qual[i]<minQ) minQ = qual[i];
    if (qual[i]>maxQ) maxQ = qual[i];
  }

  for (uint64_t i=0; i<nmesh->triangles.num; i++){
    qual[i] = (qual[i]-minQ)/(maxQ-minQ);
  }
  for (uint32_t i=0; i<nmesh->triangles.num; i++){
    if (nmesh->triangles.colors[i] == UINT16_MAX) continue;
    double *p0 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+0];
    double *p1 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+1];
    double *p2 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+2];
    hxtPosAddTriangle2(out,p0,p1,p2,qual[i]);
  }
  
  HXT_CHECK(hxtFree(&qual));
  hxtPosFinish(out);
  
  return HXT_STATUS_OK;
}

//**********************************************************************************************************
//**********************************************************************************************************
// EXPORT EDGES ALIGNED WITH CROSSFIELD
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtSurfaceMeshExportAlignedEdges(HXTMesh *mesh, 
                                           HXTMesh *nmesh, 
                                           uint64_t *p2t,
                                           const double *directions, 
                                           const double *sizemap)
{

  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(nmesh,&edges));
 
  //********************************************************************************
  // Associate vertices of final nmesh with triangles of initial
  //********************************************************************************
  
  // TODO delete, just for checking 
  for (uint32_t i=0; i<nmesh->vertices.num; i++){
    double *p = nmesh->vertices.coord + 4*i;
    double uv[2];
    double uvlim = -1e-12;
    uint64_t ct = p2t[i];
    uint64_t parent = UINT64_MAX;
    HXT_CHECK(hxtGetBarycentric(mesh,ct,p,uv));
    if (uv[0] >= uvlim && uv[1] >= uvlim && (1.-uv[0]-uv[1])>=uvlim){
      parent = ct;
    }
    if (parent == UINT64_MAX) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"DID NOT FOUND PARENT TRIANGLE");
  }
  
  //********************************************************************************
  // CHECK ALIGNED EDGES
  //********************************************************************************
  //
  // TODO continue
  //
  // 1. measure difference from cross branches
  // 2. measure difference from prescribed size 
  //
  // Combine into a "quality"
  // 
  // associate omesh with initial mesh to get directions and sizes info 
    
  FILE* oct;
  hxtPosInit("checkQualityEdges.pos","Edges",&oct);

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t *v = edges->node + 2*i;

    double *p0 = nmesh->vertices.coord + 4*v[0];
    double *p1 = nmesh->vertices.coord + 4*v[1];

    double vec[3] = {p1[0]-p0[0],p1[1]-p0[1],p1[2]-p0[2]};
    normalize(vec);


    // TODO ATTENTION
    // HERE WE TAKE THE DIRECTION FRAME FROM THE TWO ENDPOINTS OF THE EDGE 
    // AND THEN WE INTERPOLATE THEM
    //
    // TOO MUCH TROUBLE, INSTEAD JUST FIND THE MIDPOINT PAREN TRIANGLE 

    double uv0[2];
    HXT_CHECK(hxtGetBarycentric(mesh,p2t[v[0]],p0,uv0));
    // Compute normal to triangle
    double normal0[3];
    HXT_CHECK(normal2triangle(mesh,p2t[v[0]],normal0));
    // Get frame and sizes for candidate point 
    double sizes0[6] = {0.};
    double frame0[6*3] = {0.};
    HXT_CHECK(hxtGetDirections(mesh,directions,sizemap,p2t[v[0]],normal0,uv0,frame0,sizes0));


    double uv1[2];
    HXT_CHECK(hxtGetBarycentric(mesh,p2t[v[1]],p1,uv1));
    // Compute normal to triangle
    double normal1[3];
    HXT_CHECK(normal2triangle(mesh,p2t[v[1]],normal1));
    // Get frame and sizes for candidate point 
    double sizes1[6] = {0.};
    double frame1[6*3] = {0.};
    HXT_CHECK(hxtGetDirections(mesh,directions,sizemap,p2t[v[1]],normal1,uv1,frame1,sizes1));


    double dir0[3] = {0};
    double dir1[3] = {0};

    double dot0 = myDot(&frame0[0],&frame1[0]);
    double dot1 = myDot(&frame0[0],&frame1[3]);
    if (fabs(dot0) > fabs(dot1)){
      if (dot0>0){
        dir0[0] = (frame0[0] + frame1[0])/2.; 
        dir0[1] = (frame0[1] + frame1[1])/2.; 
        dir0[2] = (frame0[2] + frame1[2])/2.; 
      }else{
        dir0[0] = (frame0[0] - frame1[0])/2.; 
        dir0[1] = (frame0[1] - frame1[1])/2.; 
        dir0[2] = (frame0[2] - frame1[2])/2.; 
      }
    }else{
      if (dot1>0){
        dir0[0] = (frame0[0] + frame1[3])/2.; 
        dir0[1] = (frame0[1] + frame1[4])/2.; 
        dir0[2] = (frame0[2] + frame1[5])/2.; 
      }else{
        dir0[0] = (frame0[0] - frame1[3])/2.; 
        dir0[1] = (frame0[1] - frame1[4])/2.; 
        dir0[2] = (frame0[2] - frame1[5])/2.; 
      }
    }
    double normal[3] = {(normal0[0]+normal1[0])/2,(normal0[1]+normal1[1])/2,(normal0[2]+normal1[2])/2};
    myNormalizedCrossprod(normal,dir0,dir1);
    normalize(dir0);
    normalize(dir1);

    /*hxtPosAddVector(oct,p0,&frame0[0]);*/
    /*hxtPosAddVector(oct,p0,&frame0[3]);*/
    /*hxtPosAddVector(oct,p1,&frame1[0]);*/
    /*hxtPosAddVector(oct,p1,&frame1[3]);*/
    double pp[3] = {(p0[0]+p1[0])/2,(p0[1]+p1[1])/2,(p0[2]+p1[2])/2};
    hxtPosAddVector(oct,pp,dir0);
    hxtPosAddVector(oct,pp,dir1);

    double qdir = fmax(fabs(myDot(vec,dir0)),fabs(myDot(vec,dir1)));


    if (qdir > 0.985 ) hxtPosAddLine(oct,p0,p1,0);
  }
  hxtPosFinish(oct);


  HXT_CHECK(hxtEdgesDelete(&edges));

  return HXT_STATUS_OK;
}

//**********************************************************************************************************
//**********************************************************************************************************
//
// SIMPLE SMOOTHING
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenSmoothing(HXTMesh *mesh)
{

  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));

  for (uint64_t ct=0; ct<mesh->triangles.num; ct++){

    int bypass = 0;
    for (uint64_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*ct+j];
      uint64_t nt = edges->edg2tri[2*ce+0];
      if (nt == ct) nt = edges->edg2tri[2*ce+1];
      if (mesh->triangles.colors[ct] != mesh->triangles.colors[nt]) bypass = 1;
    }
    if (bypass == 1) continue;

    uint32_t cv = mesh->triangles.node[3*ct+0]; 
    int pass = 0;

    for (uint32_t k=0; k<edges->numEdges; k++){
      uint64_t t0 = edges->edg2tri[2*k+0];
      uint64_t t1 = edges->edg2tri[2*k+1];
      if (mesh->triangles.colors[t0] == mesh->triangles.colors[t1]) continue;
      uint32_t v0 = edges->node[2*k+0];
      uint32_t v1 = edges->node[2*k+1];
      if (cv == v0 || cv == v1){
        pass = 1; 
        break;
      }
    }
    if (pass == 1) continue;

    uint64_t cavSize = 0;
    uint64_t cavity[1000];
    HXT_CHECK(hxtVertexCavity(mesh, edges, cv, ct, &cavSize, cavity));

    // Build edges of that vertex
    uint32_t cavSizeEdges = 0;
    uint32_t cavityEdges[1000];
    HXT_CHECK(hxtVertexCavityEdges(mesh, edges, cv, ct, &cavSizeEdges, cavityEdges));

    double x = 0;
    double y = 0;
    double z = 0;
    int vertNum = 0;
    for (uint32_t kk =0 ;kk<cavSizeEdges; kk++){
      uint32_t ce = cavityEdges[kk];
      uint32_t v0 = edges->node[2*ce+0];
      uint32_t v1 = edges->node[2*ce+1];
      if (cv == v0){
        x += mesh->vertices.coord[4*v1+0];
        y += mesh->vertices.coord[4*v1+1];
        z += mesh->vertices.coord[4*v1+2];
      }else if (cv == v1){
        x += mesh->vertices.coord[4*v0+0];
        y += mesh->vertices.coord[4*v0+1];
        z += mesh->vertices.coord[4*v0+2];
      }else 
        return HXT_STATUS_ERROR;
      vertNum++;
    }
    mesh->vertices.coord[4*cv+0] = x/vertNum;
    mesh->vertices.coord[4*cv+1] = y/vertNum;
    mesh->vertices.coord[4*cv+2] = z/vertNum;

  }

  HXT_CHECK(hxtEdgesDelete(&edges));

  return HXT_STATUS_OK; 
}
 
//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION: projection of a point onto the original triangulation 
//
// TODO this is wrong, doesn't make sense to find the orthogonal projection to triangle 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenProjectSearchAllTriangles(HXTMesh *omesh, 
                                               HXTEdges *oedges,
                                               uint64_t ot,
                                               double *op,   
                                               uint64_t *nt,
                                               double *np)
{

  double tol = 10e-7;
  double dist,t,closePt[3];
  double minDist = 10e12;
  for (uint32_t i=0; i<omesh->triangles.num; i++){

    if (omesh->triangles.colors[i] != omesh->triangles.colors[ot]) continue;

      double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+0];
      double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+1];
      double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+2];
      int inside = 0;
      HXT_CHECK(hxtSignedDistancePointTriangle(p0,p1,p2,op,&dist,&inside,closePt));

      if (fabs(dist)<minDist && omesh->triangles.colors[ot] == omesh->triangles.colors[i]){
        minDist = fabs(dist);
        *nt = i;
        np[0] = closePt[0];
        np[1] = closePt[1];
        np[2] = closePt[2];
      }
  }

  return HXT_STATUS_OK; 
}
 

//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION: projection of a point onto the original triangulation 
//
// TODO this is wrong, doesn't make sense to find the orthogonal projection to triangle 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenProject(HXTMesh *omesh, 
                             HXTEdges *oedges,
                             uint64_t ot,
                             double *op,   
                             uint64_t *nt,
                             double *np)
{

  // Starting from original triangle ot 
  // - take its plane
  // - parallel from point op to the plane 
  // - if it's inside the triangle (barycentric check) OK 
  // - if not continue to next triangle (barycentric walk) 

  uint64_t ct = ot;
  int walkIter = 0;
  int walk = 0;

  while(walkIter<100){
    double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*ct+0];
    double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*ct+1];
    double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*ct+2];
    double dist;
    int inside;
    double closePt[3];
    HXT_CHECK(hxtSignedDistancePointTriangle(p0,p1,p2,op,&dist,&inside,closePt));

    double uv[2];
    HXT_CHECK(hxtGetBarycentric(omesh,ct,closePt,uv));

    walk = 0;
    if (fabs(dist)<10e-6 && uv[0] >= 0.0 && uv[1] >= 0.0 && 1.-uv[0]-uv[1] >= 0.0){
      *nt = ct;
      np[0] = closePt[0];
      np[1] = closePt[1];
      np[2] = closePt[2];

      walk = -1;
      break;
    }
    else{
      if (uv[0] < 0 ){
        walk=2;
      }else if (uv[1]<0){
        walk=0;
      }else{
        walk=1;
      }
    }

    // Find next triangle to search 
    uint64_t neigh;
    hxtGetNeighbourTriangle(oedges, ct, walk, &neigh);
    if (neigh == UINT64_MAX || omesh->triangles.colors[neigh] != omesh->triangles.colors[ot]){
      walk = -100;
      break;
    }
    else{
      ct = neigh;
    }
    walkIter ++;
  }

  /*printf("%d \n", walk);*/
  /*printf("%lu %lu \n", ot, *nt);*/
  /*if (ot != *nt) printf("here\n");*/
  /*printf("%f %f %f \n", op[0], op[1], op[2]);*/
  /*printf("%f %f %f \n", np[0], np[1], np[2]);*/
  /*if (1){ //ot != *nt){*/
    /*FILE *test;*/
    /*hxtPosInit("check.pos","points",&test);*/
    /*hxtPosAddPoint(test,op,0);*/
    /*hxtPosAddPoint(test,np,0);*/
    /*uint32_t *ov = omesh->triangles.node + 3*ot;*/
    /*uint32_t *nv = omesh->triangles.node + 3*(*nt);*/
    /*hxtPosAddTriangle(test,&omesh->vertices.coord[4*ov[0]],&omesh->vertices.coord[4*ov[1]],&omesh->vertices.coord[4*ov[2]],0);*/
    /*hxtPosAddTriangle(test,&omesh->vertices.coord[4*nv[0]],&omesh->vertices.coord[4*nv[1]],&omesh->vertices.coord[4*nv[2]],0);*/


    /*hxtPosFinish(test);*/
    /*//return HXT_STATUS_ERROR;*/
  /*}*/



  return HXT_STATUS_OK;
}

//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadCreateV2V(HXTEdges *edges,
                                   uint32_t *bin,
                                   uint32_t *v2v)
{

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    if (bin[v0] == bin[v1]) continue;

    int insert0 = 1;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*v0+j] == v1) insert0 = 0;
    }

    /*int full = 1;*/
    /*for (uint32_t j=0; j<5; j++){*/
      /*if (v2v[5*v0+j] == UINT32_MAX) full = 0;*/
    /*}*/
    /*if (full == 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"v2v is full for %d", v0);*/

    if (insert0 == 1){
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*v0+j] == UINT32_MAX){
          v2v[5*v0+j] = v1;
          break;
        }
      }
    }

    int insert1 = 1;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*v1+j] == v0) insert1 = 0;
    }
    if(insert1 == 1){
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*v1+j] == UINT32_MAX){
          v2v[5*v1+j] = v0;
          break;
        }
      }
    }
  }

  return HXT_STATUS_OK;
}



//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION to remove invalid quads (vertices with only two quad neighbours) 
//                and diamonds 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadRemoveDiamonds(HXTMesh *mesh,
                                        HXTEdges *edges,
                                        uint32_t *bin,
                                        uint32_t *isBoundary)
{

  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*10));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;

  HXT_CHECK(hxtPointGenQuadCreateV2V(edges,bin,v2v));


  uint32_t *adj;
  HXT_CHECK(hxtMalloc(&adj,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) adj[i] = 0;

  for (uint32_t i=0; i<mesh->vertices.num;i++){
    int count = 0;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*i+j] != UINT32_MAX) count++;
    }
    adj[i] = count;
    if (adj[i] < 2 && isBoundary[i] != 1) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"One quad only for vertex %d",i);
  }



  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (adj[i] >2) continue;

    double *p0 = mesh->vertices.coord + 4*i;

  }

  HXT_CHECK(hxtFree(&v2v));
  return HXT_STATUS_OK;

  uint16_t *flagTris;
  HXT_CHECK(hxtMalloc(&flagTris,mesh->triangles.num*sizeof(uint16_t)));
  for (uint64_t i=0; i<mesh->triangles.num; i++) flagTris[i] = UINT16_MAX;

  uint16_t *flagEdges;
  HXT_CHECK(hxtMalloc(&flagEdges,edges->numEdges*sizeof(uint16_t)));
  for (uint64_t i=0; i<edges->numEdges; i++) flagEdges[i] = UINT16_MAX;


  FILE *out;
  hxtPosInit("binEdgesRemove.pos","edges",&out);
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    if (isBoundary[v0] == 1 && isBoundary[v1] == 1) continue;
    if (bin[v0] != bin[v1]) continue;
    
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];
    if (t1 == UINT64_MAX) continue;
    if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;
    if (flagTris[t0] == 1 || flagTris[t1] == 1) continue;

    uint32_t ov0 = UINT32_MAX;
    uint32_t ov1 = UINT32_MAX;

    for (uint32_t k=0; k<3; k++){
      uint32_t vt1 = mesh->triangles.node[3*t0+k];
      if (vt1 != v0 && vt1 != v1) ov0 = vt1;
      uint32_t vt2 = mesh->triangles.node[3*t1+k];
      if (vt2 != v0 && vt2 != v1) ov1 = vt2;
    }


    if (isBoundary[ov0] == 1 || isBoundary[ov1] == 1) continue;
    if (bin[ov0] != bin[ov1]) continue;

    if (adj[v0] == 3 && adj[v1] == 3) hxtPosAddLine(out,&mesh->vertices.coord[4*v0],&mesh->vertices.coord[4*v1],0);
    if (adj[ov0] == 3 && adj[ov1] == 3) hxtPosAddLine(out,&mesh->vertices.coord[4*v0],&mesh->vertices.coord[4*v1],0);
  

    if ( (adj[v0] == 3 && adj[v1] == 3) || 
         (adj[ov0] == 3 && adj[ov1] == 3) ){ 
      for (uint32_t j=0; j<3; j++){
        uint64_t ct0 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+0];
        uint64_t ct1 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+1];
        uint64_t ct2 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+0];
        uint64_t ct3 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+1];
        if (ct0 != UINT64_MAX) flagTris[ct0] = 1;
        if (ct1 != UINT64_MAX) flagTris[ct1] = 1;
        if (ct2 != UINT64_MAX) flagTris[ct2] = 1;
        if (ct3 != UINT64_MAX) flagTris[ct3] = 1;
      }
      flagEdges[i] = 1;
    }


  }
  hxtPosFinish(out);


  // =================
  // REMOVAL 
  
  uint16_t *delTris;
  HXT_CHECK(hxtMalloc(&delTris,mesh->triangles.num*sizeof(uint16_t)));
  for (uint64_t i=0; i<mesh->triangles.num; i++) delTris[i] = UINT16_MAX;

  uint32_t *delVert;
  HXT_CHECK(hxtMalloc(&delVert,mesh->vertices.num*sizeof(uint32_t)));
  for (uint64_t i=0; i<mesh->vertices.num; i++) delVert[i] = i; 

  uint32_t numDelVert = 0;

  for (uint32_t i=0; i<edges->numEdges; i++){
    if (flagEdges[i] != 1) continue;
  

    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    uint32_t o0 = UINT32_MAX;
    uint32_t o1 = UINT32_MAX;

    for (uint32_t k=0; k<3; k++){
      uint32_t vt1 = mesh->triangles.node[3*t0+k];
      if (vt1 != v0 && vt1 != v1) o0 = vt1;
      uint32_t vt2 = mesh->triangles.node[3*t1+k];
      if (vt2 != v0 && vt2 != v1) o1 = vt2;
    }

    double dist0 = distance(&mesh->vertices.coord[4*v0],&mesh->vertices.coord[4*v1]);
    double dist1 = distance(&mesh->vertices.coord[4*o0],&mesh->vertices.coord[4*o1]);

    // Vertices to delete
    uint32_t dv0 = UINT32_MAX; 
    uint32_t dv1 = UINT32_MAX; 
    
    if (dist0<=dist1){
      dv0 = v0;
      dv1 = v1;
    }
    else{
      dv0 = o0;
      dv1 = o1;
    }




    delTris[t0] = 1;
    delTris[t1] = 1;
    delVert[dv0] = dv1;
    numDelVert ++;
    mesh->vertices.coord[4*dv1+0] = (mesh->vertices.coord[4*dv0+0]+mesh->vertices.coord[4*dv1+0])/2.;
    mesh->vertices.coord[4*dv1+1] = (mesh->vertices.coord[4*dv0+1]+mesh->vertices.coord[4*dv1+1])/2.;
    mesh->vertices.coord[4*dv1+2] = (mesh->vertices.coord[4*dv0+2]+mesh->vertices.coord[4*dv1+2])/2.;

  }



  //*************************************************************************************
  //*************************************************************************************
  // Create a temp mesh 
  HXTMesh *tmesh;
  HXT_CHECK(hxtMeshCreate(&tmesh));
 
  
  HXT_CHECK(hxtVerticesReserve(tmesh,mesh->vertices.num));
  HXT_CHECK(hxtTrianglesReserve(tmesh,mesh->triangles.num));


  tmesh->triangles.num = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (delTris[i] == 1) continue;

    tmesh->triangles.node[3*tmesh->triangles.num+0] = delVert[mesh->triangles.node[3*i+0]];
    tmesh->triangles.node[3*tmesh->triangles.num+1] = delVert[mesh->triangles.node[3*i+1]];
    tmesh->triangles.node[3*tmesh->triangles.num+2] = delVert[mesh->triangles.node[3*i+2]];

    tmesh->triangles.colors[tmesh->triangles.num] = mesh->triangles.colors[i];
    tmesh->triangles.num++;
  }

  tmesh->vertices.num = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    tmesh->vertices.coord[4*tmesh->vertices.num+0] = mesh->vertices.coord[4*i+0];
    tmesh->vertices.coord[4*tmesh->vertices.num+1] = mesh->vertices.coord[4*i+1];
    tmesh->vertices.coord[4*tmesh->vertices.num+2] = mesh->vertices.coord[4*i+2];
    tmesh->vertices.num++;
  }


  HXT_CHECK(hxtMeshWriteGmsh(tmesh,"finalmeshRemove.msh"));



  HXT_CHECK(hxtMeshDelete(&tmesh));


  HXT_CHECK(hxtFree(&delTris));
  HXT_CHECK(hxtFree(&delVert));

  HXT_CHECK(hxtFree(&flagEdges));
  HXT_CHECK(hxtFree(&flagTris));
  return HXT_STATUS_OK;
}


//**********************************************************************************************************
//**********************************************************************************************************
//
// NEW LABELING 
// 
// Objective:
// - quad edges should have a Hamming distance of 1 
// - diagonals should have a Hamming distance of 2+ 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadRelabel(HXTMesh *mesh, HXTEdges *edges, uint32_t *bin)
{

  //==================================================================================
  // Create vertex 2 vertex connectivity
  uint32_t *v2v;
  uint32_t maxv2v = 20;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*maxv2v));
  for (uint32_t i=0; i<maxv2v*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    int insert0 = 1;
    for (uint32_t j=0; j<maxv2v; j++){
      if (v2v[maxv2v*v0+j] == v1) insert0 = 0;
    }

    int full = 1;
    for (uint32_t j=0; j<maxv2v; j++){
      if (v2v[maxv2v*v0+j] == UINT32_MAX) full = 0;
    }
    if (full == 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"v2v is full for %d", v0);

    if (insert0 == 1){
      for (uint32_t j=0; j<maxv2v; j++){
        if (v2v[maxv2v*v0+j] == UINT32_MAX){
          v2v[maxv2v*v0+j] = v1;
          break;
        }
      }
    }

    int insert1 = 1;
    for (uint32_t j=0; j<maxv2v; j++){
      if (v2v[maxv2v*v1+j] == v0) insert1 = 0;
    }
    if(insert1 == 1){
      for (uint32_t j=0; j<maxv2v; j++){
        if (v2v[maxv2v*v1+j] == UINT32_MAX){
          v2v[maxv2v*v1+j] = v0;
          break;
        }
      }
    }
  }


  //***********************************************************************************************
  // Create new labeling array 
  uint32_t *bin3;
  HXT_CHECK(hxtMalloc(&bin3,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) bin3[i] = UINT32_MAX;


  //***********************************************************************************************
  // Assign parent triangles
  uint64_t *parentTri;
  HXT_CHECK(hxtMalloc(&parentTri,mesh->vertices.num*sizeof(uint64_t)));
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    parentTri[v[0]] = i;
    parentTri[v[1]] = i;
    parentTri[v[2]] = i;
  }

  //***********************************************************************************************
  // Create constraints array 
  uint32_t *constr;
  HXT_CHECK(hxtMalloc(&constr,8*mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<8*mesh->vertices.num; i++) constr[i] = 1;


  //***********************************************************************************************
  // Create propagate array 
  uint32_t *pointList;
  HXT_CHECK(hxtMalloc(&pointList,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) pointList[i] = UINT32_MAX;
  uint32_t pointListCount = 1;

  //***********************************************************************************************
  // Set starting point 
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    uint32_t cv = i;

    int count = 0;
    for (uint32_t j=0; j<maxv2v; j++){
      if (v2v[maxv2v*cv+j] == UINT32_MAX) continue;
      count++;
    }
    if (count >5){
      pointList[0] = i;
      for (uint32_t j=0; j<8; j++){
        if (bin[i] != j) constr[8*i+j] = 0;
      }
      break;
    }
  }



  //***********************************************************************************************
  // Propagate bin3 and constraints 
  
  uint32_t cavSize = 0;
  uint32_t cavity[maxv2v];

  for (uint32_t i=0; i<mesh->vertices.num; i++){

    uint32_t cv = pointList[i];
    if (cv == UINT32_MAX) break;


    // Set bin3 for current vertex 
    for (uint32_t j=0; j<8; j++){
      if (constr[8*cv+j] == 1){
        bin3[cv] = j;
        break;
      }
    }



    if (bin3[cv] == UINT32_MAX) continue;

    printf("\n");
    printf("First = %d - %d %d \n", cv, bin3[cv], bin[cv]);
    for (uint32_t j=0; j<8; j++){
      printf("  %d %d \n", j, constr[8*cv+j]);
    }
    
    cavSize = 0;
    for (uint32_t j=0; j<maxv2v; j++){
      uint32_t ov = v2v[maxv2v*cv+j];
      if (ov == UINT32_MAX) continue;

      printf("  %d %d %d \n", j, cavSize, ov);
      cavity[cavSize] = ov;
      cavSize++;
    }


    // Set constraints 
    for (uint32_t j=0; j<cavSize; j++){
      uint32_t ov = cavity[j];

      // Hamming distance of 2+
      if (bin[cv] == bin[ov]){
        for (uint32_t k=0; k<8; k++){
          uint32_t temp = hammingDistance(bin3[cv],k);
          if (temp == 0 || temp == 1) constr[8*ov+k] = 0;
        }
      }


      // Hamming distance of 1
      if (bin[cv] != bin[ov]){
        for (uint32_t k=0; k<8; k++){
          uint32_t temp = hammingDistance(bin3[cv],k);
          if (temp != 1) constr[8*ov+k] = 0;
        }
      }

    }


    // Add points to queue
    for (uint32_t j=0; j<cavSize; j++){
      uint32_t ov = cavity[j];

      int found = 1;
      for (uint32_t k=0; k<pointListCount; k++){
        if (pointList[k] == ov) found = 0;
      }
      if (found == 0) continue;

      pointList[pointListCount] = ov;
      pointListCount++;
    }


  }
      


  // Fill out the ones that were not assigned 
  for (uint32_t i=0; i<mesh->vertices.num; i++){

    uint32_t cv = i;

    if (bin3[cv] != UINT32_MAX) continue;

    bin3[cv] = bin[cv];
  }


        
  for (uint32_t i=0; i<mesh->vertices.num; i++){

    uint32_t cv = i;

    if (bin3[cv] != UINT32_MAX) continue;

    bin3[cv] = bin[cv];
  }



  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];


    if (bin[v0] == bin[v1]) continue;


    if (hammingDistance(bin3[v0],bin3[v1]) !=1){

      uint64_t t0 = edges->edg2tri[2*i+0];

      uint32_t ov0 = UINT32_MAX;
  
      for (uint32_t j=0; j<3; j++){
        uint32_t vt1 = mesh->triangles.node[3*t0+j];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
      }
    }
  }

  {
    FILE *test;
    hxtPosInit("hamming.pos","points",&test);

    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
      hxtPosAddText(test,&mesh->vertices.coord[4*i],"%d",bin3[i]);
    }
    hxtPosNewView(test,"labels");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
      hxtPosAddText(test,&mesh->vertices.coord[4*i],"%d",i);
    }
    hxtPosFinish(test);
  }

  HXT_CHECK(hxtFree(&bin3));
  HXT_CHECK(hxtFree(&constr));
  HXT_CHECK(hxtFree(&parentTri));
  HXT_CHECK(hxtFree(&pointList));
  HXT_CHECK(hxtFree(&v2v));





  return HXT_STATUS_OK; 
}


//**********************************************************************************************************
//**********************************************************************************************************
//
//**********************************************************************************************************
//**********************************************************************************************************
double hxtPointGenQuadQuality(double *p0, double *p1, double *p2, double *p3)
{

  double const a0 = 180 * hxtAngle3Vertices(p3,p0,p1) / M_PI;
  double const a1 = 180 * hxtAngle3Vertices(p2,p1,p0) / M_PI;
  double const a2 = 180 * hxtAngle3Vertices(p3,p2,p1) / M_PI;
  double const a3 = 180 * hxtAngle3Vertices(p0,p3,p2) / M_PI;

  double quality = fabs(90. - a0);
  quality = fmax(fabs(90. - a1), quality);
  quality = fmax(fabs(90. - a2), quality);
  quality = fmax(fabs(90. - a3), quality);

  quality = fmax( (1-2*quality/180),0);

  /*printf("%f %f %f %f \n", a0,a1,a2,a3);*/
  /*printf("%f %f %f \n", quality, 2/M_PI, 1-2*quality/180);*/
  /*printf("%f \n", quality);*/

  return quality;
}



//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION to remove degenerate quads on the boundary
//
// After smoothing 'flat' triangles on the boundary can remain since we cannot move 
// the boundary vertices
// 
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadRemoveBadBoundary(HXTPointGenOptions *opt,
                                           HXTMesh *omesh,
                                           HXTEdges *oedges,
                                           HXTMesh *mesh,
                                           HXTEdges *edges,
                                           uint32_t *isBoundary,
                                           uint64_t *p2t,
                                           uint32_t *bin)
{

  //============================================================
  // Flag edges to be splitted
  //============================================================
  uint16_t *flagEdg;
  HXT_CHECK(hxtMalloc(&flagEdg,2*edges->numEdges*sizeof(uint16_t)));
  for (uint64_t i=0; i<2*edges->numEdges; i++) flagEdg[i] = UINT16_MAX;

  for (uint32_t i=0; i<edges->numEdges; i++){

    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    if (bin[v0] != bin[v1]) continue;
    if (isBoundary[v0] != 1 && isBoundary[v1] != 1) continue;

    uint32_t ov0 = UINT32_MAX;
    uint32_t ov1 = UINT32_MAX;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];
  
    for (uint32_t k=0; k<3; k++){
      uint32_t vt1 = mesh->triangles.node[3*t0+k];
      if (vt1 != v0 && vt1 != v1) ov0 = vt1;
      uint32_t vt2 = mesh->triangles.node[3*t1+k];
      if (vt2 != v0 && vt2 != v1) ov1 = vt2;
    }

    double *p0 = mesh->vertices.coord + 4 * v0;
    double *p1 = mesh->vertices.coord + 4 *ov0;
    double *p2 = mesh->vertices.coord + 4 * v1;
    double *p3 = mesh->vertices.coord + 4 *ov1;

    double const a0 = 180 * hxtAngle3Vertices(p3,p0,p1) / M_PI;
    double const a1 = 180 * hxtAngle3Vertices(p3,p2,p1) / M_PI;

    //TODO correct way to do it is to choose the edge that 
    //are not boundary edges (lines) 
    //ENSURE THAT WE CAN CORRECTLY BUILD EDGES2LINES
    double lim = 160;
    if (isBoundary[v0] == 1 && a0>lim){
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.colors[tt0] != mesh->triangles.colors[tt1]) continue;

        flagEdg[edges->tri2edg[3*t0+j]] = bin[v0];
      }
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.colors[tt0] != mesh->triangles.colors[tt1]) continue;

        flagEdg[edges->tri2edg[3*t1+j]] = bin[v0];
      }
    }
    else if(isBoundary[v1] == 1 && a1 > lim){
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.colors[tt0] != mesh->triangles.colors[tt1]) continue;

        flagEdg[edges->tri2edg[3*t0+j]] = bin[v1];
      }
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.colors[tt0] != mesh->triangles.colors[tt1]) continue;

        flagEdg[edges->tri2edg[3*t1+j]] = bin[v1];
      }
    }
  }

  // Print out edges to be splitted
  // TODO delete
  if(opt->verbosity==2){
    FILE *test;
    hxtPosInit("splitEdgesBadBoundary.pos","edges",&test);
    for (uint32_t i=0; i<edges->numEdges; i++){

      if (flagEdg[i] == 1){

        uint32_t *v = edges->node + 2*i;
        hxtPosAddLine(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],0);
      }
    }
    hxtPosFinish(test);
  }

  //============================================================
  // Split the edges the were flagged
  //============================================================
  for (uint32_t i=0; i<edges->numEdges; i++){

    if (flagEdg[i] == UINT16_MAX) continue;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    uint32_t ov0 = edges->node[2*i+0];
    uint32_t ov1 = edges->node[2*i+1];

    if (t1 == UINT64_MAX) continue;
    if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,i,&newEdge));

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.colors[t0];
    if (omesh->triangles.colors[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else{
      // Search all triangles 
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.colors[j] == color) p2t[v0] = j;
      }
    }

    if (bin[ov0] == bin[ov1]){
      bin[v0] = bin[ov0] == 1 ? 0: 1;
    }
    else{
      bin[v0] = flagEdg[i];
    }
  }

  // Printing out 
  // TODO delete
  if(opt->verbosity==2){
    hxtMeshWriteGmsh(mesh,"splitted4.msh");
    FILE *test;
    hxtPosInit("binEdgesQuadSplit4.pos","edges",&test);
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      uint32_t *v = mesh->triangles.node + 3*i;
  
      if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
        hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);
      }

    }
    hxtPosFinish(test);
  }

  //==================================================================================
  // Split the rest of the triangles (split longest edge) 
  //==================================================================================
  for (uint64_t i=0; i<mesh->triangles.num; i++){

    uint32_t *v = mesh->triangles.node + 3*i;
    int fl = 0;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]) fl = 1;
    if (fl != 1) continue;

    uint32_t split[3] = {0,0,0};
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];

      uint32_t v0 = edges->node[2*ce+0];
      uint32_t v1 = edges->node[2*ce+1];
      
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      if (t1 == UINT64_MAX) continue;
      if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;

      //uint64_t ot = t0 == i ? t1:t0;
      //if (flagTris[ot] == 0) continue;

      uint32_t ov0 = UINT32_MAX;
      uint32_t ov1 = UINT32_MAX;

      for (uint32_t k=0; k<3; k++){
        uint32_t vt1 = mesh->triangles.node[3*t0+k];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
        uint32_t vt2 = mesh->triangles.node[3*t1+k];
        if (vt2 != v0 && vt2 != v1) ov1 = vt2;
      }

      if (bin[v0] == bin[v1] && (bin[ov0] == bin[v0] || bin[ov1] == bin[v0])){
        split[j] = 1;
      }
    }

    // Choose the longest edge 
    double distMax = -1;
    uint32_t indexEdge = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      if (split[j] == 0) continue;
      uint32_t ce = edges->tri2edg[3*i+j];
      double dist = distance(&mesh->vertices.coord[4*edges->node[2*ce+0]],&mesh->vertices.coord[4*edges->node[2*ce+1]]);
      if (dist > distMax){
        distMax = dist;
        indexEdge = ce;
      }
    }

    if (indexEdge == UINT32_MAX) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,indexEdge,&newEdge));

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.colors[i];
    if (omesh->triangles.colors[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else{
      // Search all triangles 
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.colors[j] == color) p2t[v0] = j;
      }
    }


    if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
    if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;

  }

  // Printing out 
  // TODO delete
  if(opt->verbosity==2){
    hxtMeshWriteGmsh(mesh,"splitted5.msh");
    FILE *test;
    hxtPosInit("binEdgesQuadSplit5.pos","edges",&test);
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      uint32_t *v = mesh->triangles.node + 3*i;
  
      if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
        hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);
      }

    }
    hxtPosFinish(test);
  }

  // Check for remaining topologically invalid triangle (3 indices same)
  for (uint32_t i=0; i<mesh->triangles.num;i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]] && bin[v[0]] == bin[v[2]]){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
  }


  //==================================================================================
  // Create vertex 2 vertex connectivity of opposites  
  //==================================================================================

  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*10));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;

  HXT_CHECK(hxtPointGenQuadCreateV2V(edges,bin,v2v));

  //==================================================================================
  // Smoothing2 
  //==================================================================================
  for (uint32_t ii=0; ii<1; ii++){
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      uint32_t cv = i;
      if (isBoundary[cv] == 1) continue;

      // ATTENTION 
      // TODO 
      // just for now for new points that were not correctly projected and assigned with a parent triangle
      if (p2t[i] == UINT64_MAX){
        printf("no parent for point %d \n", i);
        return HXT_STATUS_ERROR;
      }
  
      double x = 0;
      double y = 0;
      double z = 0;
      int vertNum = 0;
      for (uint32_t kk =0 ;kk<5; kk++){
        uint32_t v0 = v2v[5*cv+kk];
        if (v0 == UINT32_MAX) continue;
  
        x += mesh->vertices.coord[4*v0+0];
        y += mesh->vertices.coord[4*v0+1];
        z += mesh->vertices.coord[4*v0+2];
  
        vertNum++;
      }
      if (vertNum == 0) continue;
      mesh->vertices.coord[4*cv+0] = x/vertNum;
      mesh->vertices.coord[4*cv+1] = y/vertNum;
      mesh->vertices.coord[4*cv+2] = z/vertNum;



      // Project point back to initial triangulation 
      uint64_t nt = p2t[i];
      if (p2t[i] == UINT64_MAX) printf("ERROR %d %d \n", ii, i);
      if (p2t[i] == UINT64_MAX) return HXT_STATUS_ERROR;
      double np[3] = {mesh->vertices.coord[4*cv+0],mesh->vertices.coord[4*cv+1],mesh->vertices.coord[4*cv+2]};

      HXT_CHECK(hxtPointGenProjectSearchAllTriangles(omesh,oedges,p2t[i],&mesh->vertices.coord[4*cv],&nt,np));
      //HXT_CHECK(hxtPointGenProject(omesh,oedges,p2t[i],&mesh->vertices.coord[4*cv],&nt,np));



      p2t[i] = nt;
      mesh->vertices.coord[4*cv+0] = np[0];
      mesh->vertices.coord[4*cv+1] = np[1];
      mesh->vertices.coord[4*cv+2] = np[2];
  
    }
  }


  

  // Printing out 
  // TODO delete
  if(opt->verbosity==2){
    hxtMeshWriteGmsh(mesh,"splitted6.msh");
    FILE *test;
    hxtPosInit("binEdgesQuadSplit6.pos","edges",&test);
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      uint32_t *v = mesh->triangles.node + 3*i;
  
      if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
        hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);
      }

    }
    hxtPosFinish(test);
  }




  HXT_CHECK(hxtFree(&flagEdg));
  HXT_CHECK(hxtFree(&v2v));

  return HXT_STATUS_OK;
}



//**********************************************************************************************************
//**********************************************************************************************************
//
// Create final quad mesh 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadFinal(HXTMesh *mesh,
                               HXTEdges *edges,
                               uint32_t *isBoundary,
                               uint32_t *v2v,
                               uint32_t *bin,
                               HXTMesh *qmesh)
{
  HXT_CHECK(hxtVerticesReserve(qmesh, mesh->vertices.num));
  qmesh->vertices.num = mesh->vertices.num;
  qmesh->quads.num = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    if (bin[v0] == bin[v1]) qmesh->quads.num++;
  }
  HXT_CHECK(hxtQuadsReserve(qmesh,qmesh->quads.num));

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    qmesh->vertices.coord[4*i+0] = mesh->vertices.coord[4*i+0];
    qmesh->vertices.coord[4*i+1] = mesh->vertices.coord[4*i+1];
    qmesh->vertices.coord[4*i+2] = mesh->vertices.coord[4*i+2];
  }


  // Insert quads
  uint64_t cq = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){

    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    if (bin[v0] != bin[v1]) continue;


    uint32_t ov0 = UINT32_MAX;
    uint32_t ov1 = UINT32_MAX;
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];
  
    for (uint32_t k=0; k<3; k++){
      uint32_t vt1 = mesh->triangles.node[3*t0+k];
      if (vt1 != v0 && vt1 != v1) ov0 = vt1;
      uint32_t vt2 = mesh->triangles.node[3*t1+k];
      if (vt2 != v0 && vt2 != v1) ov1 = vt2;
    }

    qmesh->quads.node[4*cq+0] = v0;
    qmesh->quads.node[4*cq+1] = ov0;
    qmesh->quads.node[4*cq+2] = v1;
    qmesh->quads.node[4*cq+3] = ov1;
    qmesh->quads.colors[cq] = mesh->triangles.colors[t0];
    cq++;

  }


  //==================================================================================
  // Print out quad quality 
  //==================================================================================
  if(0){
    FILE *test;
    hxtPosInit("finalquads.pos","quads",&test);

    for (uint32_t i=0; i<edges->numEdges; i++){

      uint32_t v0 = edges->node[2*i+0];
      uint32_t v1 = edges->node[2*i+1];

      if (bin[v0] != bin[v1]) continue;

      uint32_t ov0 = UINT32_MAX;
      uint32_t ov1 = UINT32_MAX;

      uint64_t t0 = edges->edg2tri[2*i+0];
      uint64_t t1 = edges->edg2tri[2*i+1];
  
      for (uint32_t k=0; k<3; k++){
        uint32_t vt1 = mesh->triangles.node[3*t0+k];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
        uint32_t vt2 = mesh->triangles.node[3*t1+k];
        if (vt2 != v0 && vt2 != v1) ov1 = vt2;
      }

      double qual = hxtPointGenQuadQuality(&mesh->vertices.coord[4*v0],
                                           &mesh->vertices.coord[4*ov0],
                                           &mesh->vertices.coord[4*v1],
                                           &mesh->vertices.coord[4*ov1]);


      qual = (int)(qual*100);

      hxtPosAddQuad(test,&mesh->vertices.coord[4*v0],
                         &mesh->vertices.coord[4*ov0],
                         &mesh->vertices.coord[4*v1],
                         &mesh->vertices.coord[4*ov1],qual);

    }
    hxtPosFinish(test);
  }


  return HXT_STATUS_OK;
}
 
//**********************************************************************************************************
//**********************************************************************************************************
//
// Create and smooth a quad mesh template 
// 
// Input:
// 
//  - omesh: initial mesh (used for projection)
//  - mesh:  final mesh to be transformed to quad mesh
//  - p2t:   parent triangle on initial mesh for every vertex of mesh
//  - bin:   binary indices 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadSmoothing(HXTPointGenOptions *opt,
                                   HXTMesh *omesh,
                                   HXTMesh *mesh, 
                                   uint64_t *p2t,
                                   uint32_t *bin)
{

  HXT_INFO("");
  HXT_INFO("========= Generation of bipartite quad mesh  ==========");
  HXT_INFO("");


  // Create edges structure
  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));

  // Create edges structure for original mesh 
  HXTEdges* oedges;
  HXT_CHECK(hxtEdgesCreateNonManifold(omesh,&oedges));


  //==================================================================================
  // Flag boundary vertices
  //==================================================================================
  uint32_t *isBoundary;
  HXT_CHECK(hxtMalloc(&isBoundary,2*mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<2*mesh->vertices.num; i++) isBoundary[i] = UINT32_MAX;

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (t0 == UINT64_MAX || t1 == UINT64_MAX){
      isBoundary[v0] = 1;
      isBoundary[v1] = 1;
      continue;
    }
    if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]){
      isBoundary[v0] = 1;
      isBoundary[v1] = 1;
      continue;
    }
  }


  //==================================================================================
  // Flag triangles to be splitted (3 same indices) 
  //==================================================================================
 
  uint16_t *flagTris;
  HXT_CHECK(hxtMalloc(&flagTris,3*mesh->triangles.num*sizeof(uint16_t)));
  for (uint64_t i=0; i<3*mesh->triangles.num; i++) flagTris[i] = UINT16_MAX;

  for (uint64_t i=0; i<mesh->triangles.num; i++){

    uint32_t *v = mesh->triangles.node + 3*i;

    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
      flagTris[i] = 1;
    }
  }

  // Printing out 
  // TODO delete
  if(opt->verbosity==2){
    hxtMeshWriteGmsh(mesh,"splitted1.msh");
    FILE *test;
    hxtPosInit("binEdgesQuadSplit1.pos","edges",&test);
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      if (flagTris[i] == UINT16_MAX) continue;

      uint32_t *v = mesh->triangles.node + 3*i;

      hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
      hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
      hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
      hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);

    }
    hxtPosFinish(test);
  }


  //==================================================================================
  // Split edges with two flagged triangles 
  //==================================================================================
  for (uint32_t i=0; i<edges->numEdges; i++){

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (t1 == UINT64_MAX) continue;
    if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;

    if (flagTris[t0] == 1 && flagTris[t1] == 1){

      uint32_t newEdge = UINT32_MAX;
      HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,i,&newEdge));

      flagTris[t0] = 0;
      flagTris[t1] = 0;
      flagTris[edges->edg2tri[2*newEdge+0]] = 0;
      flagTris[edges->edg2tri[2*newEdge+1]] = 0;

      uint32_t v0 = edges->node[2*newEdge+0];
      uint32_t v1 = edges->node[2*newEdge+1];

      uint32_t v2 = edges->node[2*i+0] == v0 ? edges->node[2*i+1] : edges->node[2*i+0];

      // Find parent triangle on initial mesh for new point
      p2t[v0] = UINT64_MAX;
      uint16_t color = mesh->triangles.colors[t0];
      if (omesh->triangles.colors[p2t[v1]] == color){
        p2t[v0] = p2t[v1];
      }
      else if(omesh->triangles.colors[p2t[v2]]==color){
        p2t[v0] = p2t[v2];
      }
      else{
        // Search all triangles 
        for (uint64_t j=0; j<omesh->triangles.num; j++){
          if (omesh->triangles.colors[j] == color) p2t[v0] = j;
        }
      }

      if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
      if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;
    }
  }

  // Printing out 
  // TODO delete
  if(opt->verbosity==2){
    hxtMeshWriteGmsh(mesh,"splitted2.msh");
    FILE *test;
    hxtPosInit("binEdgesQuadSplit2.pos","edges",&test);
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      if (flagTris[i] == UINT16_MAX) continue;

      uint32_t *v = mesh->triangles.node + 3*i;

      hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
      hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
      hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
      hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);

    }
    hxtPosFinish(test);
  }

  //==================================================================================
  // Split the rest of the triangles (split longest edge)
  //==================================================================================
  for (uint64_t i=0; i<mesh->triangles.num; i++){

    if (flagTris[i] != 1) continue;

    uint32_t split[3] = {0,0,0};
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];

      uint32_t v0 = edges->node[2*ce+0];
      uint32_t v1 = edges->node[2*ce+1];
      
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      if (t1 == UINT64_MAX) continue;
      if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;

      //uint64_t ot = t0 == i ? t1:t0;
      //if (flagTris[ot] == 0) continue;

      uint32_t ov0 = UINT32_MAX;
      uint32_t ov1 = UINT32_MAX;

      for (uint32_t k=0; k<3; k++){
        uint32_t vt1 = mesh->triangles.node[3*t0+k];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
        uint32_t vt2 = mesh->triangles.node[3*t1+k];
        if (vt2 != v0 && vt2 != v1) ov1 = vt2;
      }

      if (bin[v0] == bin[v1] && (bin[ov0] == bin[v0] || bin[ov1] == bin[v0])){
        split[j] = 1;
      }
    }

    // Choose the longest edge 
    double distMax = -1;
    uint32_t indexEdge = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      if (split[j] == 0) continue;
      uint32_t ce = edges->tri2edg[3*i+j];
      double dist = distance(&mesh->vertices.coord[4*edges->node[2*ce+0]],
                             &mesh->vertices.coord[4*edges->node[2*ce+1]]);
      if (dist > distMax){
        distMax = dist;
        indexEdge = ce;
      }
    }

    if (indexEdge == UINT32_MAX) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,indexEdge,&newEdge));

    flagTris[i] = 0;

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    uint32_t v2 = edges->node[2*i+0] == v0 ? edges->node[2*i+1] : edges->node[2*i+0];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.colors[i];
    if (omesh->triangles.colors[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else if(omesh->triangles.colors[p2t[v2]]==color){
      p2t[v0] = p2t[v2];
    }
    else{
      // Search all triangles 
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.colors[j] == color) p2t[v0] = j;
      }
    }


    if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
    if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;

  }


  // Printing out 
  // TODO delete
  if(opt->verbosity==2){
    hxtMeshWriteGmsh(mesh,"splitted3.msh");
    FILE *test;
    hxtPosInit("binEdgesQuadSplit3.pos","edges",&test);
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      uint32_t *v = mesh->triangles.node + 3*i;
  
      if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
        hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
        hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);
      }

    }
    hxtPosFinish(test);
  }


  // Check for remaining topologically invalid triangle (3 indices same)
  for (uint32_t i=0; i<mesh->triangles.num;i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    if (flagTris[i] == 1){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]] && bin[v[0]] == bin[v[2]]){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
  }

  
  //==================================================================================
  // PRINT OUT 
  // TODO delete
  //==================================================================================
  if(opt->verbosity==2){
    FILE *test1;
    hxtPosInit("binEdgesAll.pos","edges",&test1);
    for (uint32_t i=0; i<edges->numEdges; i++){
      uint32_t v0 = edges->node[2*i+0];
      uint32_t v1 = edges->node[2*i+1];
      hxtPosAddLine(test1,&mesh->vertices.coord[4*v0],&mesh->vertices.coord[4*v1],0);
    }
    hxtPosNewView(test1,"points");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddPoint(test1,&mesh->vertices.coord[4*i],0);
      hxtPosAddText(test1,&mesh->vertices.coord[4*i],"%d",bin[i]);
    }
    hxtPosNewView(test1,"pointsLabel");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddText(test1,&mesh->vertices.coord[4*i],"%d",i);
    }
    hxtPosNewView(test1,"pointsBin");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddText(test1,&mesh->vertices.coord[4*i],"%d",bin[i]);
    }
    hxtPosNewView(test1,"badTris");
    for (uint32_t i=0; i<mesh->triangles.num;i++){
      uint32_t *v = mesh->triangles.node + 3*i;
      if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
        hxtPosAddLine(test1,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],0);
        hxtPosAddLine(test1,&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
        hxtPosAddLine(test1,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[2]],0);
      }
    }
    hxtPosFinish(test1);
  }

  //==================================================================================
  // Create vertex 2 vertex connectivity of opposites  
  //==================================================================================

  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*10));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;

  HXT_CHECK(hxtPointGenQuadCreateV2V(edges,bin,v2v));


  //==================================================================================
  // Smoothing 
  //==================================================================================
  for (uint32_t ii=0; ii<1; ii++){
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      uint32_t cv = i;
      if (isBoundary[cv] == 1) continue;

      // ATTENTION 
      // TODO 
      // just for now for new points that were not correctly projected and assigned with a parent triangle
      if (p2t[i] == UINT64_MAX){
        printf("no parent for point %d \n", i);
        return HXT_STATUS_ERROR;
      }
  
      double x = 0;
      double y = 0;
      double z = 0;
      int vertNum = 0;
      for (uint32_t kk =0 ;kk<5; kk++){
        uint32_t v0 = v2v[5*cv+kk];
        if (v0 == UINT32_MAX) continue;
  
        x += mesh->vertices.coord[4*v0+0];
        y += mesh->vertices.coord[4*v0+1];
        z += mesh->vertices.coord[4*v0+2];
  
        vertNum++;
      }
      if (vertNum == 0) continue;
      mesh->vertices.coord[4*cv+0] = x/vertNum;
      mesh->vertices.coord[4*cv+1] = y/vertNum;
      mesh->vertices.coord[4*cv+2] = z/vertNum;



      // Project point back to initial triangulation 
      uint64_t nt = p2t[i];
      if (p2t[i] == UINT64_MAX) printf("ERROR %d %d \n", ii, i);
      if (p2t[i] == UINT64_MAX) return HXT_STATUS_ERROR;
      double np[3] = {mesh->vertices.coord[4*cv+0],mesh->vertices.coord[4*cv+1],mesh->vertices.coord[4*cv+2]};

      HXT_CHECK(hxtPointGenProjectSearchAllTriangles(omesh,oedges,p2t[i],&mesh->vertices.coord[4*cv],&nt,np));
      //HXT_CHECK(hxtPointGenProject(omesh,oedges,p2t[i],&mesh->vertices.coord[4*cv],&nt,np));


      p2t[i] = nt;
      mesh->vertices.coord[4*cv+0] = np[0];
      mesh->vertices.coord[4*cv+1] = np[1];
      mesh->vertices.coord[4*cv+2] = np[2];
  
    }
  }

  //==================================================================================
  // Remove remaining bad triangles on the boundary
  //==================================================================================
  
  HXT_CHECK(hxtPointGenQuadRemoveBadBoundary(opt,omesh,oedges,mesh,edges,isBoundary,p2t,bin));


  //==================================================================================
  // PRINT OUT 
  // TODO delete
  //==================================================================================
  if(opt->verbosity==2){
    FILE *test;
    hxtPosInit("binEdgesAfter.pos","points",&test);
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
      hxtPosAddText(test,&mesh->vertices.coord[4*i],"%d",bin[i]);
    }
    hxtPosNewView(test,"label");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
      hxtPosAddText(test,&mesh->vertices.coord[4*i],"%d",i);
    }

    hxtPosNewView(test,"3");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      int count = 0;
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*i+j] != UINT32_MAX) count++;
      }
      if (count == 3 && isBoundary[i] != 1) hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
    }
    hxtPosNewView(test,"5");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      int count = 0;
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*i+j] != UINT32_MAX) count++;
      }
      if (count == 5) hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
    }
    hxtPosNewView(test,"6+");
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      int count = 0;
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*i+j] != UINT32_MAX) count++;
      }
      if (count == 5) hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
    }
    hxtPosNewView(test,"badTris");
    for (uint32_t i=0; i<mesh->triangles.num;i++){
      uint32_t *v = mesh->triangles.node + 3*i;

      if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
        hxtPosAddLine(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],0);
        hxtPosAddLine(test,&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
        hxtPosAddLine(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[2]],0);

      }
    }

    hxtPosFinish(test);
  } 


  if(opt->verbosity==2) HXT_CHECK(hxtMeshWriteGmsh(mesh,"finalmeshSmoothed.msh"));

  //==================================================================================
  // Remove invalid quads and diamonds
  //==================================================================================
  
  //HXT_CHECK(hxtPointGenQuadRemoveDiamonds(mesh,edges,bin,isBoundary));


  //==================================================================================
  // Relabel to use as seed for volume point generation 
  // TODO not used, not possible?
  //==================================================================================
  
  //HXT_CHECK(hxtPointGenQuadRelabel(mesh,edges,bin));
  
  //==================================================================================
  // Create final quad mesh
  //==================================================================================

  HXTMesh *qmesh;
  hxtMeshCreate(&qmesh);
  
  HXT_CHECK(hxtPointGenQuadFinal(mesh,edges,isBoundary,v2v,bin,qmesh));

  // Rewrite qmesh into nmesh
  {


    // Dummy export of lines based on color difference between triangles 
    uint64_t countLines = 0;
    for (uint32_t i=0; i<edges->numEdges; i++){
      uint64_t t0 = edges->edg2tri[2*i+0];
      uint64_t t1 = edges->edg2tri[2*i+1];
      if (t1 == UINT64_MAX){
        countLines++;
        continue;
      }
      if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) countLines++;
    }

    HXT_CHECK(hxtLinesReserve(qmesh,countLines));
    countLines = 0;
    for (uint32_t i=0; i<edges->numEdges; i++){
      uint32_t v0 = edges->node[2*i+0];
      uint32_t v1 = edges->node[2*i+1];

      uint64_t t0 = edges->edg2tri[2*i+0];
      uint64_t t1 = edges->edg2tri[2*i+1];

      int exists = 0;
      for (uint64_t j=0; j<countLines; j++){
        uint32_t *v = qmesh->lines.node + 2*j;
        if (v[0] == v0 && v[1] == v1) exists = 1;
        if (v[0] == v1 && v[1] == v0) exists = 1;
      }
      if (exists==1) continue;

      if (t1 == UINT64_MAX){
        qmesh->lines.node[2*countLines+0] = v0; 
        qmesh->lines.node[2*countLines+1] = v1; 
        qmesh->lines.colors[countLines] = mesh->triangles.colors[t0];
        countLines++;
        continue;
      }
      if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]){
        qmesh->lines.node[2*countLines+0] = v0; 
        qmesh->lines.node[2*countLines+1] = v1; 
        qmesh->lines.colors[countLines] = mesh->triangles.colors[t0]+mesh->triangles.colors[t1];
        countLines++;
      }
    }
    qmesh->lines.num = countLines;




    HXT_CHECK(hxtMeshClear(&mesh));
    HXT_CHECK(hxtVerticesReserve(mesh, qmesh->vertices.num));
    mesh->vertices.num = qmesh->vertices.num;
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      mesh->vertices.coord[4*i+0] = qmesh->vertices.coord[4*i+0];
      mesh->vertices.coord[4*i+1] = qmesh->vertices.coord[4*i+1];
      mesh->vertices.coord[4*i+2] = qmesh->vertices.coord[4*i+2];
    }
    HXT_CHECK(hxtQuadsReserve(mesh,qmesh->quads.num));
    mesh->quads.num = qmesh->quads.num;
    for (uint64_t i=0; i<qmesh->quads.num; i++){
      mesh->quads.node[4*i+0] = qmesh->quads.node[4*i+0]; 
      mesh->quads.node[4*i+1] = qmesh->quads.node[4*i+1]; 
      mesh->quads.node[4*i+2] = qmesh->quads.node[4*i+2]; 
      mesh->quads.node[4*i+3] = qmesh->quads.node[4*i+3]; 
      mesh->quads.colors[i] = qmesh->quads.colors[i];
    }
    HXT_CHECK(hxtLinesReserve(mesh,qmesh->lines.num));
    mesh->lines.num = qmesh->lines.num;
    for (uint64_t i=0; i<qmesh->lines.num; i++){
      mesh->lines.node[2*i+0] = qmesh->lines.node[2*i+0]; 
      mesh->lines.node[2*i+1] = qmesh->lines.node[2*i+1]; 
      mesh->lines.colors[i] = qmesh->lines.colors[i];
    }






  }


  



  HXT_CHECK(hxtMeshWriteGmsh(mesh,"quads.msh"));

  if(opt->verbosity==2) HXT_CHECK(hxtMeshWriteGmsh(qmesh,"quads.msh"));
  HXT_CHECK(hxtMeshDelete(&qmesh));


  //==================================================================================
  // Clear things 
  //==================================================================================


  HXT_CHECK(hxtFree(&flagTris));
  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtEdgesDelete(&oedges));
  HXT_CHECK(hxtFree(&v2v));
  HXT_CHECK(hxtFree(&isBoundary));

  return HXT_STATUS_OK; 
}
 
