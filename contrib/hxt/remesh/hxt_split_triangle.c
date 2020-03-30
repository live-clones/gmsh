#include <limits.h>
#include <float.h>
#include "hxt_split_triangle.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"

FILE *nod;

int cmp(void *x, void *y)
{
  double xx = *(double*)x, yy = *(double*)y;
  if (xx < yy) return -1;
  if (xx > yy) return  1;
  return 0;
}

HXTStatus hxtSplitBadTriangles(HXTMesh *mesh, 
                               HXTEdges *edges, 
                               void (*metric)(double *x, void *data, double *m), 
                               void *dataForMetric, 
                               int *numSplits )
{
  HXT_UNUSED(metric);
  HXT_UNUSED(dataForMetric);

  *numSplits = 0;

  int maxSplits = 2*edges->numEdges;
  int maxVert   =   maxSplits;
  int maxTri    = 2*maxSplits;
  int maxEdg    = 3*maxSplits;
  
  HXT_CHECK(hxtAlignedRealloc(&mesh->vertices.coord,4*maxVert*sizeof(double)));
  HXT_CHECK(hxtAlignedRealloc(&mesh->triangles.node,3*maxTri*sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedRealloc(&mesh->triangles.colors,maxTri*sizeof(uint16_t)));
  HXT_CHECK(hxtRealloc(&edges->tri2edg,3*maxTri*sizeof(uint32_t)));
  HXT_CHECK(hxtRealloc(&edges->node,2*maxEdg*sizeof(uint32_t))); 
  //HXT_CHECK(hxtRealloc(&edges->color,maxEdg*sizeof(uint16_t))); 
  HXT_CHECK(hxtRealloc(&edges->edg2tri,2*maxEdg*sizeof(uint64_t))); 
  
  uint64_t initNumTriangles = mesh->triangles.num;
 
  double uv[2]={1./3.,1./3.};

  double *areas;
  HXT_CHECK(hxtMalloc(&areas, initNumTriangles*sizeof(double)));
  for (uint64_t i=0; i<initNumTriangles; i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    areas[i] = hxtTriangleArea3D (&mesh->vertices.coord [4*v[0]], &mesh->vertices.coord [4*v[1]], &mesh->vertices.coord [4*v[2]] );
  }
  //qsort(areas,initNumTriangles,sizeof(double),cmp);
  FILE *fp = fopen("sortAreas.txt","w");
  double total = 0.0;
  double minArea = DBL_MAX;
  for (uint64_t i=0; i<initNumTriangles; i++){
    fprintf(fp,"  %lu   %f \n", i, areas[i]);
    total += areas[i];
    if (areas[i]<minArea) minArea = areas[i];
  }

  double avgArea = total/initNumTriangles;
  printf(" Average area = %f \n", avgArea);
  fclose(fp);





  for (uint64_t i=0; i<initNumTriangles; i++){

    uint32_t *v = mesh->triangles.node + 3*i;
    //double quality = hxtGammaTriangleQuality (&mesh->vertices.coord [4*v[0]], &mesh->vertices.coord [4*v[1]], &mesh->vertices.coord [4*v[2]] );
    double quality = hxtQualityP1Triangle(&mesh->vertices.coord [4*v[0]], &mesh->vertices.coord [4*v[1]], &mesh->vertices.coord [4*v[2]] );

    
    if (quality < 0.5 && areas[i] > avgArea ){
      hxtSplitTriangle(mesh,edges,i,uv);
      *numSplits += 1;
    }
  }

  HXT_CHECK(hxtFree(&areas));

  return HXT_STATUS_OK;
}

HXTStatus hxtSplitAllTriangles(HXTMesh *mesh, 
                               HXTEdges *edges, 
                               void (*metric)(double *x, void *data, double *m), 
                               void *dataForMetric, 
                               int *numSplits )
{
  HXT_UNUSED(metric);
  HXT_UNUSED(dataForMetric);

  *numSplits = 0;

  int maxSplits = 2*edges->numEdges;
  int maxVert   =   maxSplits;
  int maxTri    = 2*maxSplits;
  int maxEdg    = 3*maxSplits;
  
  HXT_CHECK(hxtAlignedRealloc(&mesh->vertices.coord,4*maxVert*sizeof(double)));
  HXT_CHECK(hxtAlignedRealloc(&mesh->triangles.node,3*maxTri*sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedRealloc(&mesh->triangles.colors,maxTri*sizeof(uint16_t)));
  HXT_CHECK(hxtRealloc(&edges->tri2edg,3*maxTri*sizeof(uint32_t)));
  HXT_CHECK(hxtRealloc(&edges->node,2*maxEdg*sizeof(uint32_t))); 
  //HXT_CHECK(hxtRealloc(&edges->color,maxEdg*sizeof(uint16_t))); 
  HXT_CHECK(hxtRealloc(&edges->edg2tri,2*maxEdg*sizeof(uint64_t))); 
  
  uint64_t initNumTriangles = mesh->triangles.num;
 
  double uv[2]={1./3.,1./3.};


  for (uint64_t i=0; i<initNumTriangles; i++){
    //if (i%2 != 0)continue;
    hxtSplitTriangle(mesh,edges,i,uv);
    *numSplits += 1;
  }

  return HXT_STATUS_OK;
}

HXTStatus hxtSplitTriangle  (HXTMesh *mesh, HXTEdges *edges, uint64_t ct, double* bc)
{
  uint32_t *ctNodes = &mesh->triangles.node[3*ct];

  // The input is the barycentric coordinates of the new point inside the triangle
  mesh->vertices.num += 1;
  uint32_t newVertex = mesh->vertices.num-1;
  for (uint32_t i=0; i<3; i++){
    mesh->vertices.coord[4*newVertex+i] =  (1.-bc[0]-bc[1]) * mesh->vertices.coord[4*ctNodes[0]+i]
                                          +          bc[0]  * mesh->vertices.coord[4*ctNodes[1]+i]
                                          +          bc[1]  * mesh->vertices.coord[4*ctNodes[2]+i];
  }

  mesh->triangles.num += 2;
  uint64_t nt[3] = {mesh->triangles.num-2, mesh->triangles.num-1, ct};

  edges->numEdges += 3;
  uint32_t ne[3] = {edges->numEdges-3,edges->numEdges-2,edges->numEdges-1};

  // Loop over edges of triangle
  for (uint32_t i=0; i<3; i++){
    uint32_t ce = edges->tri2edg[3*ct+i];
    uint32_t n0 = edges->node[2*ce+0];
    uint32_t n1 = edges->node[2*ce+1];

    // Orientation of current edge
    for (uint32_t k=0; k<3; k++){
      if (n0 != ctNodes[k]) continue;
      if (n1 != ctNodes[(k+1)%3]){
        uint32_t temp = n1;
        n1 = n0;
        n0 = temp; 
        break;
      }
    }

    // Create triangle
    mesh->triangles.node[3*nt[i]+0] = n0;
    mesh->triangles.node[3*nt[i]+1] = n1;
    mesh->triangles.node[3*nt[i]+2] = newVertex;
    mesh->triangles.colors[nt[i]]   = mesh->triangles.colors[ct];

    // Create edge
    edges->node[2*ne[i]+0] = n1;
    edges->node[2*ne[i]+1] = newVertex;
    //edges->color[ne[i]] = edges->color[ce];

    // Triangles of current edge
    if (edges->edg2tri[2*ce+1] == UINT64_MAX){
      edges->edg2tri[2*ce+0] = nt[i];
    }
    else{
      if (edges->edg2tri[2*ce+0] == ct) edges->edg2tri[2*ce+0] = nt[i];
      if (edges->edg2tri[2*ce+1] == ct) edges->edg2tri[2*ce+1] = nt[i];
    }

    // Triangles of new edge 
    edges->edg2tri[2*ne[i]+0] = nt[(i+1)%3];
    edges->edg2tri[2*ne[i]+1] = nt[i];

    // Edges of new triangle
    edges->tri2edg[3*nt[i]+0] = ce;
    edges->tri2edg[3*nt[i]+1] = ne[i];
    edges->tri2edg[3*nt[i]+2] = ne[(i+2)%3];

  }

  return HXT_STATUS_OK;
}


