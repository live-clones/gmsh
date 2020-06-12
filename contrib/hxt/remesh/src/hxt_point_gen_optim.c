#include "hxt_tools.h"
#include "hxt_edge.h"
#include "hxt_point_gen_utils.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"
#include "hxt_point_gen_2d.h"

//#include "hxt_point_gen_realloc.h"
//#include "hxt_split_edge.h"

#include "hxt_post_debugging.h"

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
    int pass =0;

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
 
