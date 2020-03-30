#include <math.h>
#include "hxt_edge.h"
#include "hxt_point_gen_utils.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"

//**********************************************************************************************************
//**********************************************************************************************************
//
// QUALITY COMPUTATION BASED ON DISTANCE FROM CIRCUMCIRCLE CENTER
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenOptim(HXTMesh *mesh, const double *directions, const double *sizemap)
{
  HXT_UNUSED(sizemap);
 
  // Compute quality for all triangles
  // TODO NORMALIZE THE QUALITY 
  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));
  FILE* out;
  hxtPosInit("checkQuality.pos","Scalar",&out);
  for (uint32_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] == UINT16_MAX) continue;
    double *p0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *p1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+1];
    double *p2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+2];
    double quality = hxtRightAngledQualitySimple(p0,p1,p2);
    hxtPosAddTriangle2(out,p0,p1,p2,quality);
  }
  hxtPosFinish(out);
  
  // Associate vertices of final mesh with triangles of initial
  uint64_t *parentTri;
  HXT_CHECK(hxtMalloc(&parentTri,mesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) parentTri[i] = UINT64_MAX;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    double *p = mesh->vertices.coord + 4*i;
    double uv[2];
    double uvlim = -1e-12;
    for (uint64_t ct=0; ct<mesh->triangles.num; ct++){
      HXT_CHECK(hxtGetBarycentric(mesh,ct,p,uv));
      if (uv[0] >= uvlim && uv[1] >= uvlim && (1.-uv[0]-uv[1])>=uvlim){
        parentTri[i] = ct;
        break;
      }
    }
    if (parentTri[i] == UINT64_MAX) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"DID NOT FOUND PARENT TRIANGLE");
  }
  

  // CHECK ALIGNED EDGES
  FILE* oct;
  hxtPosInit("checkQualityEdges.pos","Edges",&oct);
  for (uint32_t i=0; i<edges->numEdges; i++){
    double *p0 = mesh->vertices.coord + 4*edges->node[2*i+0];
    double *p1 = mesh->vertices.coord + 4*edges->node[2*i+1];

    double vec[3] = {p1[0]-p0[0],p1[1]-p0[1],p1[2]-p0[2]};
    normalize(vec);

    //double dist = distance(p0,p1);


    // TODO continue
    //
    // 1. measure difference from cross branches
    // 2. measure difference from prescribed size 
    //
    // Combine into a "quality"
    // 
    // associate omesh with initial mesh to get directions and sizes info 
    

    uint64_t t0 = parentTri[edges->node[2*i+0]];

    double dir1[3] = {directions[9*mesh->triangles.node[3*t0+0]+0],
                      directions[9*mesh->triangles.node[3*t0+0]+1],
                      directions[9*mesh->triangles.node[3*t0+0]+2]};
    double dir2[3] = {directions[9*mesh->triangles.node[3*t0+0]+3],
                      directions[9*mesh->triangles.node[3*t0+0]+4],
                      directions[9*mesh->triangles.node[3*t0+0]+5]};

    //double size1 = sizemap[3*mesh->triangles.node[3*t0+0]+0];
    //double size2 = sizemap[3*mesh->triangles.node[3*t0+0]+1];

    normalize(dir1);
    normalize(dir2);
    
    //double q1 = (1-fabs(dist-size1)/size1) * fabs(myDot(vec,dir1));
    //double q2 = (1-fabs(dist-size2)/size2) * fabs(myDot(vec,dir2));
    //double q = fmax(q1,q2);

    //double qsize = fmax(1-fabs(dist-size1)/size1,1-fabs(dist-size2)/size2);
    double qdir = fmax(fabs(myDot(vec,dir1)),fabs(myDot(vec,dir2)));

    if (qdir > 0.95 ) hxtPosAddLine(oct,p0,p1,0);
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
 
