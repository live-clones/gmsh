#include "hxt_edge.h"
#include "hxt_tools.h"

struct hxtLineLoopStruct{
  double length;
  int n;
  uint32_t *edges;
};

struct hxtBoundariesStruct{
  int nll;// number of line loops
  HXTLineLoop *lineLoop;
  int nbedg; // number of border edges
  int seamPoint;
};


double hxtEdgesLength(const HXTEdges *edges,uint32_t ie){

  HXTMesh* mesh = edges->edg2mesh;

  int i1 = edges->node[2*ie+0];
  int i2 = edges->node[2*ie+1];;

  double *x1 = mesh->vertices.coord+i1*4;
  double *x2 = mesh->vertices.coord+i2*4;
  double dx = x1[0]-x2[0];
  double dy = x1[1]-x2[1];
  double dz = x1[2]-x2[2];

  return sqrt(dx*dx+dy*dy+dz*dz);
}



static inline int halfedgecmp(const void *p0, const void *p1)
{
  const uint32_t *e0 = (const uint32_t*)p0;
  uint32_t es0[2] = {e0[0] < e0[1] ? e0[0] : e0[1], e0[0] < e0[1] ? e0[1] : e0[0]};
  const uint32_t *e1 = (const uint32_t*)p1;
  uint32_t es1[2] = {e1[0] < e1[1] ? e1[0] : e1[1], e1[0] < e1[1] ? e1[1] : e1[0]};

  if (es0[0] < es1[0]) return -1;
  if (es0[0] > es1[0]) return 1;
  if (es0[1] < es1[1]) return -1;
  if (es0[1] > es1[1]) return 1;
  return 0;
}

int hxtEdgesIsBoundary (HXTEdges *edges, uint32_t *e)
{
  void* found = bsearch(e, edges->bdryedges, edges->nEdgesBdry, 2*sizeof(uint32_t), halfedgecmp);
  if (found == NULL) return 0;
  return 1;
}

HXTStatus hxtLineLoopGetEdges(HXTLineLoop *loop, uint32_t **edges)
{
  *edges = loop->edges;

  return HXT_STATUS_OK;
}

HXTStatus hxtLineLoopGetNumberOfEdges(HXTLineLoop *loop, int *number)
{
  *number = loop->n;

  return HXT_STATUS_OK;
}

HXTStatus hxtLineLoopGetLength(HXTLineLoop *loop, double *length)
{

  *length = loop->length;

  return HXT_STATUS_OK;

}


HXTStatus hxtBoundariesGetNumberOfLineLoops(HXTBoundaries *boundaries, int *number)
{

  *number = boundaries->nll;

  return HXT_STATUS_OK;
}

HXTStatus hxtBoundariesGetNumberOfBorderEdges(HXTBoundaries *boundaries, int *number)
{

  *number = boundaries->nbedg;

  return HXT_STATUS_OK;
}

HXTStatus hxtBoundariesGetNumberOfEdgesOfLineLoop(HXTBoundaries *boundaries, int i, int *number)
{
  if (i<boundaries->nll)
    *number = boundaries->lineLoop[i].n;
  else
    return HXT_ERROR(HXT_STATUS_ERROR);

  return HXT_STATUS_OK;

}

HXTStatus hxtBoundariesGetLengthOfLineLoop(HXTBoundaries *boundaries, int i, double *length)
{

  if (i<boundaries->nll)
    *length = boundaries->lineLoop[i].length;
  else
    return HXT_ERROR(HXT_STATUS_ERROR);

  return HXT_STATUS_OK;
}


HXTStatus hxtBoundariesGetEdgesOfLineLoop(HXTBoundaries *boundaries, int i, uint32_t **edges)
{

  if (i<boundaries->nll)
    *edges = boundaries->lineLoop[i].edges;
  else
    return HXT_ERROR(HXT_STATUS_ERROR);

  return HXT_STATUS_OK;
}

HXTStatus hxtBoundariesGetLineLoop(HXTBoundaries *boundaries, int i, HXTLineLoop **lineLoop)
{

  if (i<boundaries->nll)
    *lineLoop = &(boundaries->lineLoop[i]);
  else
    return HXT_ERROR(HXT_STATUS_ERROR);

  return HXT_STATUS_OK;
}

HXTStatus hxtBoundariesGetSeamPoint(HXTBoundaries *boundaries, int *seamPoint)
{
  *seamPoint = boundaries->seamPoint;
  return HXT_STATUS_OK;
}

HXTStatus hxtEdgesSetBoundaries(HXTEdges *edges, HXTBoundaries **boundaries)
{

  HXTBoundaries* lineLoops;
  HXT_CHECK( hxtMalloc(&lineLoops,sizeof(HXTBoundaries)) );
  *boundaries = lineLoops;
  lineLoops->seamPoint = 0;
  /**/

  uint64_t* edg2tri = edges->edg2tri;
  uint32_t* tri2edg = edges->tri2edg;
  int nbBorder = 0;// number of edges which belong only (each) to one single triangle
  uint32_t *firstNode2Edge;
  HXT_CHECK(hxtMalloc(&firstNode2Edge,edges->numEdges*sizeof(uint32_t)));
  for(uint32_t i=0; i<(edges)->numEdges; i++)
    firstNode2Edge[i] = -1;
  uint32_t *idx;
  HXT_CHECK(hxtMalloc(&idx,(edges)->numEdges*sizeof(uint32_t)));
  int *invIdx;
  HXT_CHECK(hxtMalloc(&invIdx,(edges)->numEdges*sizeof(int)));
  for(uint32_t i=0; i<(edges)->numEdges; i++){
    if((edges)->edg2tri[2*i+1] == (uint64_t)-1 ){

      if(firstNode2Edge[edges->node[2*i+0]] == (uint32_t)-1 || firstNode2Edge[edges->node[2*i+0]]==i)
	firstNode2Edge[edges->node[2*i+0]] = i;
      else
	lineLoops->seamPoint = 1;

      idx[nbBorder] = i;
      invIdx[i] = nbBorder;
      nbBorder++;
    }
    else{
      idx[i] = -1;
      invIdx[i] = -1;
    }
  }
  HXT_CHECK(hxtFree(&firstNode2Edge));
  lineLoops->nbedg = nbBorder;
  if(0 && lineLoops->seamPoint==1){
    HXT_WARNING("SEAM POINT!!!!\n");
    lineLoops->nll=-1;
    lineLoops->lineLoop = NULL;
    return HXT_STATUS_OK;
  }

  uint32_t *border;
  HXT_CHECK(hxtMalloc(&border,nbBorder*sizeof(uint32_t)));
  int *flag;
  HXT_CHECK(hxtMalloc(&flag,nbBorder*sizeof(int)));
  for(int i=0; i<nbBorder; i++){
    border[i] = idx[i];
    flag[i] = 0;
  }

  uint32_t *edg;
  HXT_CHECK(hxtMalloc(&edg,nbBorder*sizeof(uint32_t)));
  uint32_t *nedges;
  HXT_CHECK(hxtMalloc(&nedges,nbBorder/3*sizeof(uint32_t)));
  double *lengths;
  HXT_CHECK(hxtMalloc(&lengths,nbBorder/3*sizeof(double)));


  int cf = 0;
  int cb = 0;

  uint32_t startEnd ;
  uint32_t current;

  for(int i=0; i<nbBorder; i++){
    // step forward if current edge has already been used to build a line loop
    while((i<nbBorder) && flag[i]==1)
      i++;
    if(!(i<nbBorder))
      break;

    startEnd = border[i];
    current = startEnd;

    uint32_t nEdges = 0;
    double ll = 0.;

    do{// build a line loop

      edg[cf++] = current;
      flag[invIdx[current]] = 1;

      ll += hxtEdgesLength(edges,current);

      uint64_t tri = edg2tri[2*current+0];
      do{
        for(int k=0; k<3; k++){
          if(tri2edg[3*tri+k]==current){
            current = tri2edg[3*tri+((k+1)%3)];
            break;
          }
        }
        if(edg2tri[2*current+0]==tri)
          tri = edg2tri[2*current+1];
        else
          tri = edg2tri[2*current+0];
      } while(invIdx[current] == -1);

      nEdges++;
    } while(current!=startEnd);

    lengths[cb] = ll;
    nedges[cb++] = nEdges;

  }// end for
  HXTLineLoop *loops;
  HXT_CHECK( hxtMalloc(&loops,cb*sizeof(HXTLineLoop)));
  lineLoops->nll = cb;


  int offset = 0;
  for(int i=0; i<cb; i++){
    loops[i].length = lengths[i];
    loops[i].n = nedges[i];
    loops[i].edges = edg + offset;
    offset +=  nedges[i];
  }

  lineLoops->lineLoop = loops;

  HXT_CHECK(hxtFree(&idx));
  HXT_CHECK(hxtFree(&invIdx));
  HXT_CHECK(hxtFree(&border));
  HXT_CHECK(hxtFree(&flag));
  HXT_CHECK(hxtFree(&nedges));
  HXT_CHECK(hxtFree(&lengths));


  return HXT_STATUS_OK;
}


HXTStatus hxtEdgesCreate(HXTMesh *mesh, HXTEdges** edges)
{

  uint64_t nTriangles  = mesh->triangles.num;

  HXT_CHECK( hxtMalloc (edges,sizeof(HXTEdges)) );

  // build edges of the boundary simply by copying the edges of the
  // mesh. We prefer to copy because they are sorted
  uint64_t nEdgesBdry = mesh->lines.num;
  uint32_t *bdryedges;
  HXT_CHECK(hxtMalloc(&bdryedges,2*(nEdgesBdry+1)*sizeof(uint32_t))); // allocate at least one :-)
  (*edges)->bdryedges = bdryedges;
  memcpy ( bdryedges, mesh->lines.node, 2*nEdgesBdry*sizeof(uint32_t));
  qsort(bdryedges,nEdgesBdry,2*sizeof(uint32_t),halfedgecmp);
  (*edges)->nEdgesBdry = nEdgesBdry;

  (*edges)->numEdges = 0;
  (*edges)->global    = NULL;
  (*edges)->node      = NULL;
  (*edges)->color     = NULL;
  (*edges)->edg2tri   = NULL;
  (*edges)->tri2edg   = NULL;

  (*edges)->edg2mesh = mesh;


  // build edge
  uint32_t *halfedges;
  HXT_CHECK(hxtMalloc(&halfedges,3*3*nTriangles*sizeof(uint32_t)));
  for(uint64_t i = 0; i<nTriangles; i++) {
    for(int j=0; j<3; j++){
      halfedges[i*9+j*3+0] = mesh->triangles.node[3*i+j];//first node of an edge
      halfedges[i*9+j*3+1] = mesh->triangles.node[3*i+(j+1)%3];//second node of an edge
      halfedges[i*9+j*3+2] = (uint32_t) i;//triangle having this edge
    }
  }
  qsort(halfedges,nTriangles*3,3*sizeof(uint32_t),halfedgecmp);
  uint32_t *tri2edg;
  HXT_CHECK(hxtMalloc(&tri2edg,3*nTriangles*sizeof(uint32_t)));
  uint32_t nEdges = 0;
  for(uint64_t i=0; i< nTriangles*3; i++){
    uint32_t *he = halfedges+i*3;
    for(int k=0; k<3; k++)
      if (mesh->triangles.node[he[2]*3+k] == he[0])
        tri2edg[he[2]*3+k] = nEdges;
    if (i+1 == nTriangles*3 || halfedgecmp(he,he+3) != 0)
      nEdges++;
  }
  (*edges)->numEdges = nEdges;
  (*edges)->tri2edg   = tri2edg;


  uint32_t *node;
  HXT_CHECK(hxtMalloc(&node,2*nEdges*sizeof(uint32_t)));
  int p=0;
  for(uint64_t i=0; i<nTriangles*3; i++){
    uint32_t *he = halfedges+i*3;
    if(i+1 == nTriangles*3 || halfedgecmp(he,he+3) != 0){
      node[p*2+0] = he[0];
      node[p*2+1] = he[1];
      p++;
    }
  }
  (*edges)->node = node;
  HXT_CHECK(hxtFree(&halfedges));
  uint64_t *edg2tri;
  HXT_CHECK(hxtMalloc(&edg2tri,2*nEdges*sizeof(uint64_t)));
  for(uint32_t i=0; i<nEdges*2; i++)
    edg2tri[i] = -1;

  for(uint64_t i=0; i<nTriangles; i++){
    for(uint64_t j=0; j<3; j++){
      uint32_t e = tri2edg[i*3+j];
      if(edg2tri[e*2+0] == (uint64_t)-1)
        edg2tri[e*2+0] = i;
      else
	if(edg2tri[e*2+1] == (uint64_t)-1)
	  edg2tri[e*2+1] = i;
	else
	  return HXT_ERROR_MSG( HXT_STATUS_ASSERTION_FAILED,"hxt_edge.c:\t topology is wrong for edge creation \n\t At least three triangles (%lu;%lu,%lu) share the same edge\n",i,edg2tri[e*2+0],edg2tri[e*2+1]);

    }
  }
  (*edges)->edg2tri = edg2tri;

  // compute the total number of boundary edges
  int edgesBdryTotal = 0;
  for(uint32_t i=0; i<(*edges)->numEdges; i++)
    if((*edges)->edg2tri[2*i+1] == (uint64_t)-1 ||
       hxtEdgesIsBoundary ((*edges), &((*edges)->node[2*i]) ))
      edgesBdryTotal++;
  (*edges)->edgesBdryTotal = edgesBdryTotal;

  return HXT_STATUS_OK;

}


HXTStatus hxtEdgesCreateNonManifold(HXTMesh *mesh, HXTEdges** edges)
{

  uint64_t nTriangles  = mesh->triangles.num;

  HXT_CHECK( hxtMalloc (edges,sizeof(HXTEdges)) );

  // build edges of the boundary simply by copying the edges of the
  // mesh. We prefer to copy because they are sorted
  uint64_t nEdgesBdry = mesh->lines.num;
  uint32_t *bdryedges;
  HXT_CHECK(hxtMalloc(&bdryedges,2*(nEdgesBdry+1)*sizeof(uint32_t))); // allocate at least one :-)
  (*edges)->bdryedges = bdryedges;
  memcpy ( bdryedges, mesh->lines.node, 2*nEdgesBdry*sizeof(uint32_t));
  qsort(bdryedges,nEdgesBdry,2*sizeof(uint32_t),halfedgecmp);
  (*edges)->nEdgesBdry = nEdgesBdry;

  (*edges)->numEdges = 0;
  (*edges)->global    = NULL;
  (*edges)->node      = NULL;
  (*edges)->color     = NULL;
  (*edges)->edg2tri   = NULL;
  (*edges)->tri2edg   = NULL;

  (*edges)->edg2mesh = mesh;


  // build edge
  uint32_t *halfedges;
  HXT_CHECK(hxtMalloc(&halfedges,3*3*nTriangles*sizeof(uint32_t)));
  for(uint64_t i = 0; i<nTriangles; i++) {
    for(int j=0; j<3; j++){
      halfedges[i*9+j*3+0] = mesh->triangles.node[3*i+j];//first node of an edge
      halfedges[i*9+j*3+1] = mesh->triangles.node[3*i+(j+1)%3];//second node of an edge
      halfedges[i*9+j*3+2] = (uint32_t) i;//triangle having this edge
    }
  }
  qsort(halfedges,nTriangles*3,3*sizeof(uint32_t),halfedgecmp);
  uint32_t *tri2edg;
  HXT_CHECK(hxtMalloc(&tri2edg,3*nTriangles*sizeof(uint32_t)));
  uint32_t nEdges = 0;
  for(uint64_t i=0; i< nTriangles*3; i++){
    uint32_t *he = halfedges+i*3;
    for(int k=0; k<3; k++)
      if (mesh->triangles.node[he[2]*3+k] == he[0])
        tri2edg[he[2]*3+k] = nEdges;
    if (i+1 == nTriangles*3 || halfedgecmp(he,he+3) != 0)
      nEdges++;
  }
  (*edges)->numEdges = nEdges;
  (*edges)->tri2edg   = tri2edg;


  uint32_t *node;
  HXT_CHECK(hxtMalloc(&node,2*nEdges*sizeof(uint32_t)));
  int p=0;
  for(uint64_t i=0; i<nTriangles*3; i++){
    uint32_t *he = halfedges+i*3;
    if(i+1 == nTriangles*3 || halfedgecmp(he,he+3) != 0){
      node[p*2+0] = he[0];
      node[p*2+1] = he[1];
      p++;
    }
  }
  (*edges)->node = node;
  HXT_CHECK(hxtFree(&halfedges));
  uint64_t *edg2tri;
  HXT_CHECK(hxtMalloc(&edg2tri,2*nEdges*sizeof(uint64_t)));
  for(uint32_t i=0; i<nEdges*2; i++)
    edg2tri[i] = -1;

  for(uint64_t i=0; i<nTriangles; i++){
    for(uint64_t j=0; j<3; j++){
      uint32_t e = tri2edg[i*3+j];

      if(edg2tri[e*2+0] == (uint64_t)-1)
        edg2tri[e*2+0] = i;
      else
        edg2tri[e*2+1] = i;

        // ATTENTION TODO non manifold case fix

        /*if(edg2tri[e*2+1] == (uint64_t)-1)*/
          /*edg2tri[e*2+1] = i;*/
        /*else{*/
          /*printf("%lu %lu %lu \n",i+mesh->points.num+mesh->lines.num+1,*/
                            /*edg2tri[e*2+0]+mesh->points.num+mesh->lines.num+1,*/
                            /*edg2tri[e*2+1]+mesh->points.num+mesh->lines.num+1);*/
          /*printf("%d %d %d \n", mesh->triangles.color[i],*/
                                /*mesh->triangles.color[edg2tri[e*2+0]],*/
                                /*mesh->triangles.color[edg2tri[e*2+1]]);*/
          /*uint64_t t1 = edg2tri[2*e+0];*/
          /*uint64_t t2 = edg2tri[2*e+1];*/
          /*printf("%d %d %d %d \n", tri2edg[3*i +0], tri2edg[3*i +1], tri2edg[3*i +2], mesh->triangles.color[i]);*/
          /*printf("%d %d %d %d \n", tri2edg[3*t1+0], tri2edg[3*t1+1], tri2edg[3*t1+2], mesh->triangles.color[t1]);*/
          /*printf("%d %d %d %d \n", tri2edg[3*t2+0], tri2edg[3*t2+1], tri2edg[3*t2+2], mesh->triangles.color[t2]);*/
          /*return HXT_ERROR_MSG( HXT_STATUS_ASSERTION_FAILED,*/
              /*"hxt_edge.c:\t topology is wrong for edge creation \n\t At least three triangles (%lu,%lu,%lu) share the same edge\n",i,edg2tri[e*2+0],edg2tri[e*2+1]);*/
        /*}*/

    }
  }
  (*edges)->edg2tri = edg2tri;

  // compute the total number of boundary edges
  int edgesBdryTotal = 0;
  for(uint32_t i=0; i<(*edges)->numEdges; i++)
    if((*edges)->edg2tri[2*i+1] == (uint64_t)-1 ||
       hxtEdgesIsBoundary ((*edges), &((*edges)->node[2*i]) ))
      edgesBdryTotal++;
  (*edges)->edgesBdryTotal = edgesBdryTotal;

  return HXT_STATUS_OK;

}

HXTStatus hxtEdgesDelete(HXTEdges** edgesp)
{
  HXTEdges *edges = *edgesp;
  HXT_CHECK(hxtFree(&edges->bdryedges));
  HXT_CHECK(hxtFree(&edges->node));
  HXT_CHECK(hxtFree(&edges->tri2edg));
  HXT_CHECK(hxtFree(&edges->edg2tri));
  HXT_CHECK(hxtFree(edgesp));
  return HXT_STATUS_OK;
}
