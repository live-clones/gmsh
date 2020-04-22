#include <limits.h>
#include <float.h>
#include "hxt_split_edge.h"

#include "hxt_triangle_quality.h"
#include "hxt_point_gen_numerics.h"

HXTStatus hxtSplitLongInteriorEdges (HXTMesh *mesh, 
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
  
  uint32_t initNumEdges = edges->numEdges;

  double *lengths;
  HXT_CHECK(hxtMalloc(&lengths,initNumEdges*sizeof(double)));
  double avgLength = 0.0;
  double minLength = DBL_MAX;
  for (uint32_t i = 0; i < initNumEdges; i++){
    double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
    lengths[i] = distance(v0,v1);

    avgLength += lengths[i];
    if (lengths[i]<minLength) minLength = lengths[i];
  }
  avgLength /= initNumEdges;

  for (uint32_t i = 0; i < initNumEdges; i++){
    double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
    double dist = distance(v0,v1);

    if (dist < 1*avgLength) continue;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;
 
    uint32_t ne = UINT32_MAX;
    HXT_CHECK(hxtSplitEdge(mesh,edges,i,&ne,0.5));
    *numSplits += 1;
  }

  HXT_CHECK(hxtFree(&lengths));


  return HXT_STATUS_OK;
}



HXTStatus hxtSplitLongBoundaryEdges(HXTMesh *mesh, 
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
  
  uint32_t initNumEdges = edges->numEdges;

  double *lengths;
  HXT_CHECK(hxtMalloc(&lengths,initNumEdges*sizeof(double)));
  double avgLength = 0.0;
  double minLength = DBL_MAX;
  for (uint32_t i = 0; i < initNumEdges; i++){
    double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
    lengths[i] = distance(v0,v1);

    avgLength += lengths[i];
    if (lengths[i]<minLength) minLength = lengths[i];
  }
  avgLength /= initNumEdges;

  for (uint32_t i = 0; i < initNumEdges; i++){
    double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
    double dist = distance(v0,v1);

    if (dist < 2*avgLength) continue;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (mesh->triangles.colors[t0] == mesh->triangles.colors[t1]) continue;

    // Get list of adjacent triangles for this line
    // TODO is the best option to allocate here every time ?
    uint64_t numAdjacentTriangles = 2;
    uint64_t adjacentTriangles[4];
    for (uint64_t i=0; i<2*numAdjacentTriangles; i++) 
      adjacentTriangles[i] = UINT64_MAX;
    adjacentTriangles[0] = t0;
    adjacentTriangles[1] = t1;

    double newpoint[3];
    for (uint32_t j=0; j<3; j++){
      newpoint[0] = (v0[0]+v1[0])/2.;
      newpoint[1] = (v0[1]+v1[1])/2.;
      newpoint[2] = (v0[2]+v1[2])/2.;
    }
    uint32_t ne = UINT32_MAX;

    hxtSplitBoundaryLine(mesh, 
                         edges, 
                         i,         // boundary edge to be splitted 
                         newpoint,    // coords of new point (instead of parameter)
                         numAdjacentTriangles,    // number of adjacent triangles
                         adjacentTriangles, // adjacent triangles
                         &ne         // new boundary edge (half line)
                         );

      *numSplits += 1;

  }


  HXT_CHECK(hxtFree(&lengths));


  return HXT_STATUS_OK;
}

HXTStatus hxtSplitAllEdges (HXTMesh *mesh, 
                            HXTEdges *edges, 
                            void (*metric)(double *x, void *data, double *m), 
                            void *dataForMetric, 
                            int *numSplits )
{
  HXT_UNUSED(metric);
  HXT_UNUSED(dataForMetric);

  *numSplits = 0;

  // Before everything, we should reallocate the mesh structure 
  // given an estimation about the total number of splits 
  //
  //   mesh->vertices.coord 
  //     increment vertices.num
  //
  //   mesh->triangles.node
  //   mesh->triangles.colors
  //     increment triangles.num
  //
  //   edges->tri2edg
  //   edges->edg2tri
  //   edges->node
  //   edges->color
  //     increment edges->numEdges
  //
  // Each edge split will create 
  //  - one new vertex
  //  - three new edges (1 new from split, 1 existing from split, one for each triangle of the current edge)
  //  - two new triangles (4 in total = 2 new + 2 existing)
  //
  
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
  
  uint32_t initNumEdges = edges->numEdges;

  // Let's split all original edges 
  for (uint32_t i = 0; i < initNumEdges; i++){
    //if (edges->edg2tri[2*i+0] == UINT64_MAX) continue;
    //if (edges->edg2tri[2*i+1] == UINT64_MAX) continue;
    
    //if (edges->edg2tri[2*i+0] != UINT64_MAX && edges->edg2tri[2*i+1] != UINT64_MAX) continue;
    
    
    uint32_t ne = UINT32_MAX;
    HXT_CHECK(hxtSplitEdge(mesh,edges,i,&ne,0.5));
    *numSplits += 1;
  }


  return HXT_STATUS_OK;
}



HXTStatus hxtSplitEdge  (HXTMesh *mesh, HXTEdges *edges, uint32_t ce, uint32_t *ne, double point )
{
  // TODO comment the code
  
  if (edges->edg2tri[2*ce+0] == UINT64_MAX) exit(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Wrong convention on boundary edge"));
  if (edges->edg2tri[2*ce+1] == UINT64_MAX){
    hxtSplitBoundaryEdge(mesh,edges,ce,point);
    return HXT_STATUS_OK; 
  }

  // nodes of current edge
  uint32_t ni = edges->node[2*ce+0];
  uint32_t nj = edges->node[2*ce+1]; 

  // triangles of current edge
  uint64_t ti = edges->edg2tri[2*ce+0];
  uint64_t tj = edges->edg2tri[2*ce+1];

  
  // Input is the edge ce and where to split it 
  // given by a parameter point[0,1] of where the point is in this current edge
  // First we identify the new point and add on mesh->vertices.coord
  mesh->vertices.num += 1;
  for (uint32_t i=0; i<3; i++){
    mesh->vertices.coord[4*(mesh->vertices.num-1)+i] =  (1-point) * mesh->vertices.coord[4*ni+i]
                                                       +   point  * mesh->vertices.coord[4*nj+i];
  }

  // Find orientation of new triangles
  //
  // Create new edges
  // 
  // Create new triangles
  //
  // Update edg2tri and tri2edg
  //
  // Update edges->node
  //
  // Update triangles->node and triangles->color
  //
  //
  // Treat separately boundary edge, it is a simpler case 

  mesh->triangles.num +=2;

  uint64_t tti = mesh->triangles.num-2, ttj = tti+1;
  uint32_t e0 = edges->numEdges, e1=e0+1, e2=e1+1;

  mesh->triangles.colors[tti] = mesh->triangles.colors[ti];
  mesh->triangles.colors[ttj] = mesh->triangles.colors[tj];

  for(uint32_t ic=0; ic<3; ic++){
    if(mesh->triangles.node[3*ti+ic]==ni && mesh->triangles.node[3*ti+(ic+1)%3]==nj){
      mesh->triangles.node[3*ti+(ic+1)%3] = mesh->vertices.num-1;

      mesh->triangles.node[3*tti+0] = mesh->vertices.num-1;
      mesh->triangles.node[3*tti+1] = nj;
      mesh->triangles.node[3*tti+2] = mesh->triangles.node[3*ti+(ic+2)%3];
      edges->tri2edg[3*tti+0] = e0;
      edges->tri2edg[3*tti+1] = edges->tri2edg[3*ti+(ic+1)%3];
      edges->tri2edg[3*tti+2] = e1;

      edges->tri2edg[3*ti+(ic+1)%3] = e1;

      uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*tti+1]];
      if(t_[0]==ti)
        t_[0] = tti;
      else
        t_[1] = tti;

    }
    else if (mesh->triangles.node[3*ti+ic]==nj && mesh->triangles.node[3*ti+(ic+1)%3]==ni) {
      mesh->triangles.node[3*ti+ic] = mesh->vertices.num-1;

      mesh->triangles.node[3*tti+0] = nj;
      mesh->triangles.node[3*tti+1] = mesh->vertices.num-1;
      mesh->triangles.node[3*tti+2] = mesh->triangles.node[3*ti+(ic+2)%3];
      edges->tri2edg[3*tti+0] = e0;
      edges->tri2edg[3*tti+1] = e1;
      edges->tri2edg[3*tti+2] = edges->tri2edg[3*ti+(ic+2)%3];

      edges->tri2edg[3*ti+(ic+2)%3] = e1;


      uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*tti+2]];
      if(t_[0]==ti)
        t_[0] = tti;
      else
        t_[1] = tti;

    }
    if(mesh->triangles.node[3*tj+ic]==nj && mesh->triangles.node[3*tj+(ic+1)%3]==ni){
      mesh->triangles.node[3*tj+(ic+1)%3] = mesh->vertices.num-1;

      mesh->triangles.node[3*ttj+0] = mesh->vertices.num-1;
      mesh->triangles.node[3*ttj+1] = ni;
      mesh->triangles.node[3*ttj+2] = mesh->triangles.node[3*tj+(ic+2)%3];
      edges->tri2edg[3*ttj+0] = ce;
      edges->tri2edg[3*ttj+1] = edges->tri2edg[3*tj+(ic+1)%3];
      edges->tri2edg[3*ttj+2] = e2;

      edges->tri2edg[3*tj+(ic+1)%3] = e2;
      edges->tri2edg[3*tj+ic] = e0;

      uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*ttj+1]];
      if(t_[0]==tj)
        t_[0] = ttj;
      else
        t_[1] = ttj;

    }
    else if (mesh->triangles.node[3*tj+ic]==ni && mesh->triangles.node[3*tj+(ic+1)%3]==nj){

      mesh->triangles.node[3*tj+ic] = mesh->vertices.num-1;

      mesh->triangles.node[3*ttj+0] = ni;
      mesh->triangles.node[3*ttj+1] = mesh->vertices.num-1;
      mesh->triangles.node[3*ttj+2] = mesh->triangles.node[3*tj+(ic+2)%3];
      edges->tri2edg[3*ttj+0] = ce;
      edges->tri2edg[3*ttj+1] = e2;
      edges->tri2edg[3*ttj+2] = edges->tri2edg[3*tj+(ic+2)%3];

      edges->tri2edg[3*tj+ic] = e0;
      edges->tri2edg[3*tj+(ic+2)%3] = e2;

      uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*ttj+2]];
      if(t_[0]==tj)
        t_[0] = ttj;
      else
        t_[1] = ttj;    

    }
  }//end for      

  edges->numEdges +=3;

  edges->node[2*ce+1] = mesh->vertices.num-1;
  edges->edg2tri[2*ce+0] = ti;
  edges->edg2tri[2*ce+1] = ttj;       
  edges->node[2*e0+0] = mesh->vertices.num-1;
  edges->node[2*e0+1] = nj;
  edges->edg2tri[2*e0+0] = tti;
  edges->edg2tri[2*e0+1] = tj;
  edges->node[2*e1+0] = mesh->vertices.num-1;
  edges->node[2*e1+1] = mesh->triangles.node[3*tti+2];
  edges->edg2tri[2*e1+0] = ti;
  edges->edg2tri[2*e1+1] = tti;
  edges->node[2*e2+0] = mesh->vertices.num-1;
  edges->node[2*e2+1] = mesh->triangles.node[3*ttj+2];
  edges->edg2tri[2*e2+0] = tj;
  edges->edg2tri[2*e2+1] = ttj;

  *ne = e0;

  return HXT_STATUS_OK;
}

HXTStatus hxtSplitBoundaryEdge  (HXTMesh *mesh, HXTEdges *edges, uint32_t ce, double point )
{

  // nodes of current edge
  uint32_t ni = edges->node[2*ce+0];
  uint32_t nj = edges->node[2*ce+1]; 

  // triangles of current edge
  uint64_t ti = edges->edg2tri[2*ce+0];
  if (edges->edg2tri[2*ce+1] != UINT64_MAX) exit(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Edge is not a boundary edge"));

  // Input is the edge ce and where to split it 
  // given by a parameter point[0,1] of where the point is in this current edge
  // First we identify the new point and add on mesh->vertices.coord
  mesh->vertices.num += 1;
  for (uint32_t i=0; i<3; i++){
    mesh->vertices.coord[4*(mesh->vertices.num-1)+i] =  (1-point) * mesh->vertices.coord[4*ni+i]
                                                       +   point  * mesh->vertices.coord[4*nj+i];
  }

  mesh->triangles.num +=1;

  uint64_t tti = mesh->triangles.num-1;
  uint32_t e0 = edges->numEdges, e1=e0+1;
  mesh->triangles.colors[tti] = mesh->triangles.colors[ti];

  for(uint32_t ic=0; ic<3; ic++){
    if(mesh->triangles.node[3*ti+ic]==ni && mesh->triangles.node[3*ti+(ic+1)%3]==nj){
      mesh->triangles.node[3*ti+(ic+1)%3] = mesh->vertices.num-1;

      mesh->triangles.node[3*tti+0] = mesh->vertices.num-1;
      mesh->triangles.node[3*tti+1] = nj;
      mesh->triangles.node[3*tti+2] = mesh->triangles.node[3*ti+(ic+2)%3];
      edges->tri2edg[3*tti+0] = e0;
      edges->tri2edg[3*tti+1] = edges->tri2edg[3*ti+(ic+1)%3];
      edges->tri2edg[3*tti+2] = e1;

      edges->tri2edg[3*ti+(ic+1)%3] = e1;

      uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*tti+1]];
      if(t_[0]==ti)
        t_[0] = tti;
      else
        t_[1] = tti;

    }
    else if (mesh->triangles.node[3*ti+ic]==nj && mesh->triangles.node[3*ti+(ic+1)%3]==ni) {
      mesh->triangles.node[3*ti+ic] = mesh->vertices.num-1;

      mesh->triangles.node[3*tti+0] = nj;
      mesh->triangles.node[3*tti+1] = mesh->vertices.num-1;
      mesh->triangles.node[3*tti+2] = mesh->triangles.node[3*ti+(ic+2)%3];
      edges->tri2edg[3*tti+0] = e0;
      edges->tri2edg[3*tti+1] = e1;
      edges->tri2edg[3*tti+2] = edges->tri2edg[3*ti+(ic+2)%3];

      edges->tri2edg[3*ti+(ic+2)%3] = e1;


      uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*tti+2]];
      if(t_[0]==ti)
        t_[0] = tti;
      else
        t_[1] = tti;

    }
  }//end for      

  edges->numEdges +=2;

  edges->node[2*ce+1] = mesh->vertices.num-1;
  edges->edg2tri[2*ce+0] = ti;
  edges->edg2tri[2*ce+1] = UINT64_MAX;       
  edges->node[2*e0+0] = mesh->vertices.num-1;
  edges->node[2*e0+1] = nj;
  edges->edg2tri[2*e0+0] = tti;
  edges->edg2tri[2*e0+1] = UINT64_MAX;
  edges->node[2*e1+0] = mesh->vertices.num-1;
  edges->node[2*e1+1] = mesh->triangles.node[3*tti+2];
  
  // TODO check this quick fix 
  for (uint32_t i=0; i<3; i++){
    if (edges->node[2*e1+0] == mesh->triangles.node[3*ti+i] && 
        edges->node[2*e1+1] == mesh->triangles.node[3*ti+(i+1)%3])   
    {
      edges->edg2tri[2*e1+1] = ti;
      edges->edg2tri[2*e1+0] = tti;
    }
  }


  return HXT_STATUS_OK;
}

HXTStatus hxtSplitBoundaryLine(HXTMesh *mesh, 
                               HXTEdges *edges, 
                               uint32_t ce,         // boundary edge to be splitted 
                               double *newpoint,    // coords of new point (instead of parameter)
                               uint64_t numTris,    // number of adjacent triangles
                               uint64_t *triangles, // adjacent triangles
                               uint32_t *ne         // new boundary edge (half line)
                               )
{
  // nodes of current edge
  uint32_t ni = edges->node[2*ce+0];
  uint32_t nj = edges->node[2*ce+1]; 

  // First we add the new point on mesh->vertices.coord
  for (uint32_t i=0; i<3; i++)
    mesh->vertices.coord[4*mesh->vertices.num+i] = newpoint[i];
  mesh->vertices.num += 1;

  // Create new triangles
  mesh->triangles.num += numTris;
  uint32_t e0 = edges->numEdges;

  for (uint64_t i=0; i<numTris; i++){
    uint64_t ti = triangles[i];
    uint64_t tti = mesh->triangles.num-numTris+i;
    triangles[numTris+i] = tti;
    uint32_t e1 = e0 + 1 + i; 

    mesh->triangles.colors[tti] = mesh->triangles.colors[ti];

    for(uint32_t ic=0; ic<3; ic++){
      if(mesh->triangles.node[3*ti+ic]==ni && mesh->triangles.node[3*ti+(ic+1)%3]==nj){
        mesh->triangles.node[3*ti+(ic+1)%3] = mesh->vertices.num-1;

        mesh->triangles.node[3*tti+0] = mesh->vertices.num-1;
        mesh->triangles.node[3*tti+1] = nj;
        mesh->triangles.node[3*tti+2] = mesh->triangles.node[3*ti+(ic+2)%3];
        edges->tri2edg[3*tti+0] = e0;
        edges->tri2edg[3*tti+1] = edges->tri2edg[3*ti+(ic+1)%3];
        edges->tri2edg[3*tti+2] = e1;

        edges->tri2edg[3*ti+(ic+1)%3] = e1;

        uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*tti+1]];
        if(t_[0]==ti)
          t_[0] = tti;
        else
          t_[1] = tti;

        edges->node[2*e1+0] = mesh->vertices.num-1;
        edges->node[2*e1+1] = mesh->triangles.node[3*tti+2];
        edges->edg2tri[2*e1+0] = tti;
        edges->edg2tri[2*e1+1] = ti;

      }
      else if (mesh->triangles.node[3*ti+ic]==nj && mesh->triangles.node[3*ti+(ic+1)%3]==ni) {
        mesh->triangles.node[3*ti+ic] = mesh->vertices.num-1;

        mesh->triangles.node[3*tti+0] = nj;
        mesh->triangles.node[3*tti+1] = mesh->vertices.num-1;
        mesh->triangles.node[3*tti+2] = mesh->triangles.node[3*ti+(ic+2)%3];
        edges->tri2edg[3*tti+0] = e0;
        edges->tri2edg[3*tti+1] = e1;
        edges->tri2edg[3*tti+2] = edges->tri2edg[3*ti+(ic+2)%3];

        edges->tri2edg[3*ti+(ic+2)%3] = e1;

        uint64_t *t_ = &edges->edg2tri[2*edges->tri2edg[3*tti+2]];
        if(t_[0]==ti)
          t_[0] = tti;
        else
          t_[1] = tti;

        edges->node[2*e1+0] = mesh->vertices.num-1;
        edges->node[2*e1+1] = mesh->triangles.node[3*tti+2];
        edges->edg2tri[2*e1+0] = ti;
        edges->edg2tri[2*e1+1] = tti;

      }

    }//end for      

  }

  edges->numEdges += numTris;
  edges->numEdges += 1;

  edges->node[2*ce+1] = mesh->vertices.num-1;
  edges->edg2tri[2*ce+0] = triangles[0];
  if (numTris != 1){
    edges->edg2tri[2*ce+1] = triangles[numTris-1];
  }
  else{
    if (edges->edg2tri[2*ce+1] != UINT64_MAX){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"FINALMESHwrongboundaryline.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Wrong boundary line adjacent triangle");
    }
    edges->edg2tri[2*ce+1] = UINT64_MAX;
  }

  edges->node[2*e0+0] = mesh->vertices.num-1;
  edges->node[2*e0+1] = nj;
  edges->edg2tri[2*e0+0] = triangles[numTris];
  if (numTris != 1){
    edges->edg2tri[2*e0+1] = triangles[numTris+1];
  }
  else{
    edges->edg2tri[2*e0+1] = UINT64_MAX;
  }

  *ne = e0;

  return HXT_STATUS_OK;
}
