#include "hxt_parametrization.h"
#include "hxt_mean_values.h"
#include "hxt_edge.h"
#include "metis.h"


/*

// # O U T P U T

int* colors; //gives colors of elements: colors[i] = color of i-th element
int* nNodes; //gives  lower index of int* nodes for a color: nNodes[i] = first node index of i-th color
int* nodes; //gives the global index of initial 'mesh': nodes[i] = if i=nNodes[c]+k, gives the global index of k-th node of c-th color
double* uv; //give the uv param coordinates of a local node: uv[2*i+p] = u/v component of the global k-node of the c-th color

 */




struct HXTVectorStruct{
  void **ptr;
  int last;
  int length;
};


static HXTStatus hxtVectorInit(HXTVector **vecptr){


  HXT_CHECK(hxtMalloc(vecptr,sizeof(HXTVector)));

  HXTVector *new = *vecptr;

  new->ptr = NULL;
  new->last = -1;
  new->length = 0;

  return HXT_STATUS_OK;
}


static HXTStatus hxtVectorFree(HXTVector **vecptr){

  HXTVector *vector = *vecptr;

  HXT_CHECK(hxtFree(&vector->ptr));

  HXT_CHECK(hxtFree(vecptr));

  return HXT_STATUS_OK;

}

static HXTStatus hxtVectorPushBack(HXTVector *vector, void *object){

  int i = vector->last;
  int length = vector->length;

  if(i+1 >= length){
    if(length==0)
      length=1;
    HXT_CHECK(hxtRealloc(&vector->ptr,2*(length)*sizeof(void *)));
    vector->length = 2*length;
  }
  vector->ptr[i+1] = object;
  vector->last = i+1;

  return HXT_STATUS_OK;
}


/*---------------------------------------*/



struct HXTParametrizationStruct{
  HXTEdges *edges;
  int n;
  HXTMeanValues **maps;
};




static HXTStatus hxtDoubleLongestEdge(HXTEdges *e, int tri, double *l)
{
  uint32_t *ed = &e->tri2edg[3*tri];
  *l=0;

  for(int i=0; i<3; i++){
    uint64_t *tr= &e->edg2tri[2*ed[i]];

    if(tr[1]==(uint64_t)-1)
      continue;

    if(*l<hxtEdgesLength(e,ed[i]))
      *l=hxtEdgesLength(e,ed[i]);
  }
    return HXT_STATUS_OK;
}

static HXTStatus hxtLongestEdge(HXTEdges *edges, int tri,int *ie,int comp)
{
  uint32_t *ed = &edges->tri2edg[3*tri];
  double longest = hxtEdgesLength(edges,comp);
  *ie=comp;
  for(int i=0; i<3; i++){
    uint64_t *tr= &edges->edg2tri[2*ed[i]];

    if(tr[1]==(uint64_t)-1)
      continue;

    if(longest<hxtEdgesLength(edges,ed[i])){
      longest=hxtEdgesLength(edges,ed[i]);
      *ie = ed[i];
    }
  }
  return HXT_STATUS_OK;
}

static HXTStatus hxtLongestEdgeBisection(HXTEdges *edges,int nrefinements)
{
  double threshold = 0, counter=0;
  for(uint32_t ie=0; ie<edges->numEdges; ie++)
    if(edges->edg2tri[2*ie+1]==(uint64_t)-1){
      threshold+= hxtEdgesLength(edges,ie);
      counter++;
    }
  if (counter>0)
    threshold/=counter;

  // longest-edge bisection: boundary edges are not splitted
  for(int ir=0; ir<nrefinements; ir++){
    HXTEdges *e = edges;
    HXTMesh *m = edges->edg2mesh;



    uint64_t *flag=NULL;
    HXT_CHECK(hxtMalloc(&flag,m->triangles.num*sizeof(uint64_t)));
    for(uint64_t it=0; it<m->triangles.num; it++){
      double l;
      HXT_CHECK(hxtDoubleLongestEdge(e,it,&l));
      if(l>2*threshold)
        flag[it] = 0;
      else
        flag[it] = 1;
    }

    int maxVert = m->vertices.num;
    int maxTri = m->triangles.num;
    int maxEdg = e->numEdges;
    uint64_t initialNumberOfTriangles = m->triangles.num;
    for(uint64_t it=0; it<initialNumberOfTriangles; it++){
      if(flag[it] > 0)
        continue;

      while(flag[it]==0){
        int ti = (int) it, tj;
        int ei,ej;
        for(int ib=0; ib<3; ib++){
          if (e->edg2tri[2*e->tri2edg[3*it+ib]+1] == (uint64_t) -1)
            continue;
          else{
            hxtLongestEdge(e,it,&ej,e->tri2edg[3*it+ib]);
            break;
          }
        }
        do{
          HXT_CHECK(hxtLongestEdge(e,ti,&ei,ej));
          tj = e->edg2tri[2*ei+0]==ti ? e->edg2tri[2*ei+1] : e->edg2tri[2*ei+0];
          HXT_CHECK(hxtLongestEdge(e,tj,&ej,ei));
          ti =  e->edg2tri[2*ej+0]==tj ? e->edg2tri[2*ej+1] : e->edg2tri[2*ej+0];
        }while(ei!=ej);

        m->vertices.num += 1;
        if(m->vertices.num > maxVert){
          maxVert *= 2;
          HXT_CHECK(hxtAlignedRealloc(&m->vertices.coord,4*maxVert*sizeof(double)));
        }
        int ni = e->node[2*ei+0], nj = e->node[2*ei+1];

        for(int xj=0; xj<3; xj++)
          m->vertices.coord[4*(m->vertices.num-1)+xj] = ( m->vertices.coord[4*ni+xj] + m->vertices.coord[4*nj+xj] )/2.;

        m->triangles.num +=2;
        if(m->triangles.num > maxTri){
          maxTri *= 2;
          HXT_CHECK(hxtAlignedRealloc(&m->triangles.node,3*maxTri*sizeof(uint32_t)));
          HXT_CHECK(hxtAlignedRealloc(&m->triangles.colors,maxTri*sizeof(uint16_t)));
          HXT_CHECK(hxtRealloc(&e->tri2edg,3*maxTri*sizeof(uint32_t)));
        }
        int tti = m->triangles.num-2, ttj = tti+1;
        int e0 = e->numEdges, e1=e0+1, e2=e1+1;
        for(int ic=0; ic<3; ic++){
          if(m->triangles.node[3*ti+ic]==ni && m->triangles.node[3*ti+(ic+1)%3]==nj){
            m->triangles.node[3*ti+(ic+1)%3] = m->vertices.num-1;

            m->triangles.node[3*tti+0] = m->vertices.num-1;
            m->triangles.node[3*tti+1] = nj;
            m->triangles.node[3*tti+2] = m->triangles.node[3*ti+(ic+2)%3];
            e->tri2edg[3*tti+0] = e0;
            e->tri2edg[3*tti+1] = e->tri2edg[3*ti+(ic+1)%3];
            e->tri2edg[3*tti+2] = e1;

            e->tri2edg[3*ti+(ic+1)%3] = e1;

            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*tti+1]];
            if(t_[0]==ti)
              t_[0] = tti;
            else
              t_[1] = tti;

          }
          else if (m->triangles.node[3*ti+ic]==nj && m->triangles.node[3*ti+(ic+1)%3]==ni) {
            m->triangles.node[3*ti+ic] = m->vertices.num-1;

            m->triangles.node[3*tti+0] = nj;
            m->triangles.node[3*tti+1] = m->vertices.num-1;
            m->triangles.node[3*tti+2] = m->triangles.node[3*ti+(ic+2)%3];
            e->tri2edg[3*tti+0] = e0;
            e->tri2edg[3*tti+1] = e1;
            e->tri2edg[3*tti+2] = e->tri2edg[3*ti+(ic+2)%3];

            e->tri2edg[3*ti+(ic+2)%3] = e1;


            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*tti+2]];
            if(t_[0]==ti)
              t_[0] = tti;
            else
              t_[1] = tti;

          }
          if(m->triangles.node[3*tj+ic]==nj && m->triangles.node[3*tj+(ic+1)%3]==ni){
            m->triangles.node[3*tj+(ic+1)%3] = m->vertices.num-1;

            m->triangles.node[3*ttj+0] = m->vertices.num-1;
            m->triangles.node[3*ttj+1] = ni;
            m->triangles.node[3*ttj+2] = m->triangles.node[3*tj+(ic+2)%3];
            e->tri2edg[3*ttj+0] = ei;
            e->tri2edg[3*ttj+1] = e->tri2edg[3*tj+(ic+1)%3];
            e->tri2edg[3*ttj+2] = e2;

            e->tri2edg[3*tj+(ic+1)%3] = e2;
            e->tri2edg[3*tj+ic] = e0;

            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*ttj+1]];
            if(t_[0]==tj)
              t_[0] = ttj;
            else
              t_[1] = ttj;


          }
          else if (m->triangles.node[3*tj+ic]==ni && m->triangles.node[3*tj+(ic+1)%3]==nj){

            m->triangles.node[3*tj+ic] = m->vertices.num-1;

            m->triangles.node[3*ttj+0] = ni;
            m->triangles.node[3*ttj+1] = m->vertices.num-1;
            m->triangles.node[3*ttj+2] = m->triangles.node[3*tj+(ic+2)%3];
            e->tri2edg[3*ttj+0] = ei;
            e->tri2edg[3*ttj+1] = e2;
            e->tri2edg[3*ttj+2] = e->tri2edg[3*tj+(ic+2)%3];

            e->tri2edg[3*tj+ic] = e0;
            e->tri2edg[3*tj+(ic+2)%3] = e2;

            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*ttj+2]];
            if(t_[0]==tj)
              t_[0] = ttj;
            else
              t_[1] = ttj;

          }
        }//end for
        e->numEdges +=3;
        if(e->numEdges > maxEdg){
          maxEdg *= 2;
          HXT_CHECK(hxtRealloc(&e->node,2*maxEdg*sizeof(uint32_t)));
          HXT_CHECK(hxtRealloc(&e->color,maxEdg*sizeof(uint16_t)));
          HXT_CHECK(hxtRealloc(&e->edg2tri,2*maxEdg*sizeof(uint64_t)));
        }
        e->node[2*ei+1] = m->vertices.num-1;
        e->edg2tri[2*ei+0] = ti;
        e->edg2tri[2*ei+1] = ttj;
        e->node[2*e0+0] = m->vertices.num-1;
        e->node[2*e0+1] = nj;
        e->edg2tri[2*e0+0] = tti;
        e->edg2tri[2*e0+1] = tj;
        e->node[2*e1+0] = m->vertices.num-1;
        e->node[2*e1+1] = m->triangles.node[3*tti+2];
        e->edg2tri[2*e1+0] = ti;
        e->edg2tri[2*e1+1] = tti;
        e->node[2*e2+0] = m->vertices.num-1;
        e->node[2*e2+1] = m->triangles.node[3*ttj+2];
        e->edg2tri[2*e2+0] = tj;
        e->edg2tri[2*e2+1] = ttj;


        if (ti < initialNumberOfTriangles)
          flag[ti] = 1;
        if (tj < initialNumberOfTriangles)
          flag[tj] = 1;

      }// end while flag[it]==0
    }//end for it

    if(threshold>0)
      for(uint64_t it=0; it<m->triangles.num; it++){
        double l;
        HXT_CHECK(hxtDoubleLongestEdge(e,it,&l));
        if(l>2*threshold && nrefinements<10){
          nrefinements++;
          break;
        }
      }


  }//end refinement




  return HXT_STATUS_OK;
}

static HXTStatus hxtPartitioning(HXTEdges *edges,int *part, int nPartitions,HXTVector *partitions)
{

  HXTMesh *mesh = edges->edg2mesh;

  uint32_t *flagVertices;
  HXT_CHECK(hxtMalloc(&flagVertices,mesh->vertices.num*sizeof(uint32_t)));
  for(int p = 0; p<nPartitions; p++){
    HXTMesh *msh=NULL;
    HXT_CHECK(hxtMeshCreate(mesh->ctx,&msh));


    for(uint32_t iv=0; iv<mesh->vertices.num; iv++)
      flagVertices[iv] = -1;

    uint32_t cv = 0;
    uint64_t ce = 0;
    for(uint64_t ie=0; ie<mesh->triangles.num; ie++){
      if(part[ie]==p){
        for(int jv=0; jv<3; jv++){
          uint32_t current = mesh->triangles.node[3*ie+jv];
          if(flagVertices[current] == (uint32_t)-1)
            flagVertices[current] = cv++;
        }
        ce++;
      }
    }
    /*
      printf("------------stat \t part %d---------------\n",p);
      printf("\t number of vertices:%u\n",cv);
      printf("\t number of elements:%lu\n",ce);
    */
    msh->vertices.num = cv;
    HXT_CHECK(hxtAlignedMalloc(&msh->vertices.coord,4*cv*sizeof(double)));
    for(uint32_t iv=0; iv<mesh->vertices.num; iv++){
      uint32_t current = flagVertices[iv];
      if(current==(uint32_t)-1);
      else{
        msh->vertices.coord[4*current+0] = mesh->vertices.coord[4*iv+0];
        msh->vertices.coord[4*current+1] = mesh->vertices.coord[4*iv+1];
        msh->vertices.coord[4*current+2] = mesh->vertices.coord[4*iv+2];
        msh->vertices.coord[4*current+3] = mesh->vertices.coord[4*iv+3];
      }
    }

    msh->triangles.num = ce;
    //<
    uint64_t *global;
    HXT_CHECK(hxtMalloc(&global,ce*sizeof(uint64_t)));
    //>
    HXT_CHECK( hxtAlignedMalloc(&msh->triangles.node,ce*3*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedMalloc(&msh->triangles.colors,ce*sizeof(uint16_t)) );
    ce = 0;
    for(uint64_t ie=0; ie<mesh->triangles.num; ie++){
      if(part[ie]==p){
        global[ce] = edges->global[ie];
        msh->triangles.colors[ce] = mesh->triangles.colors[ie];
        for(int jv=0; jv<3; jv++){
          uint32_t current = flagVertices[mesh->triangles.node[3*ie+jv]];
          msh->triangles.node[3*ce+jv] = current;
        }
        ce++;
      }
    }
    HXTEdges* edg = NULL;
    HXT_CHECK(hxtEdgesCreate(msh,&edg));
    edg->global = global;
    HXT_CHECK(hxtVectorPushBack(partitions,edg));
  }

  return HXT_STATUS_OK;

}

static HXTStatus hxtCheckConnectivity(HXTEdges *e,HXTVector *partitions)
{

  HXTMesh *m = e->edg2mesh;

  int *flag = NULL;
  HXT_CHECK(hxtMalloc(&flag,m->triangles.num*sizeof(int)));
  for(uint64_t i=0; i<m->triangles.num; i++)
    flag[i] = -1;

  uint64_t *queue = NULL;
  HXT_CHECK(hxtMalloc(&queue,m->triangles.num*sizeof(uint64_t)));
  int last = 1;


  uint64_t *idx = NULL;
  HXT_CHECK(hxtMalloc(&idx,(m->triangles.num+1)*sizeof(uint64_t)));


  int count = 0;
  flag[0] = count;
  queue[0] = 0;
  int goOn = 1;
  int iq=0;
  idx[0] = 1;
  while(goOn){
    for(; iq<last; iq++){
      idx[iq+1] = idx[iq];
      uint64_t current = queue[iq];
      uint32_t *ed = &e->tri2edg[3*current];
      for(int j=0; j<3; j++){
        if (e->edg2tri[2*ed[j]+1] == (uint64_t) -1)
          continue;
        uint64_t next = e->edg2tri[2*ed[j]] == current ? e->edg2tri[2*ed[j]+1] : e->edg2tri[2*ed[j]];
        if (flag[next] == -1){
          queue[last]= next;
          last++;
          idx[iq+1]++;
          flag[next] = (int) count;
        }
      }
    }
    count++;
    goOn = 0;
    for(uint64_t i=0; i<m->triangles.num; i++)
      if (flag[i]== -1){
        goOn=1;
        iq=last;
        queue[last] = i;
        last++;
        flag[i] = count;
        break;
      }
  }

  //  printf("HXT_INFO \t There is/are %d connected part(s).\n",count);

  for(uint64_t i=0; i<m->triangles.num; i++){
    uint32_t *refVert = &m->triangles.node[3*queue[i]];
    for(uint64_t j=idx[i]+flag[queue[i]]; j<idx[i+1]+flag[queue[i]]; j++){

      int cond = 0;
      uint32_t *checkVert = &m->triangles.node[3*queue[j]];
      for(int ii=0; ii<3; ii++){
        for(int jj=0; jj<3; jj++){
          if(refVert[ii]==checkVert[(jj+1)%3] && refVert[(ii+1)%3]==checkVert[jj]){
            cond = 1;
            break;
          }
        }
        if(cond==1)
          break;
      }//end for ii
      if(cond==0){
        printf("Unconsistent orientation \t %lu (%u %u %u) ; (%u %u)-(%u %u)-(%u %u) [%d] ~ %lu (%u %u %u) ; (%u %u)-(%u %u)-(%u %u) [%d].\n",queue[i],refVert[0],refVert[1],refVert[2],e->node[2*e->tri2edg[3*queue[i]+0]+0],e->node[2*e->tri2edg[3*queue[i]+0]+1],e->node[2*e->tri2edg[3*queue[i]+1]+0],e->node[2*e->tri2edg[3*queue[i]+1]+1],e->node[2*e->tri2edg[3*queue[i]+2]+0],e->node[2*e->tri2edg[3*queue[i]+2]+1],flag[queue[i]],queue[j],checkVert[0],checkVert[1],checkVert[2],e->node[2*e->tri2edg[3*queue[j]+0]+0],e->node[2*e->tri2edg[3*queue[j]+0]+1],e->node[2*e->tri2edg[3*queue[j]+1]+0],e->node[2*e->tri2edg[3*queue[j]+1]+1],e->node[2*e->tri2edg[3*queue[j]+2]+0],e->node[2*e->tri2edg[3*queue[j]+2]+1],flag[queue[j]]);
        uint64_t temp = m->triangles.node[3*queue[j]+0];
        m->triangles.node[3*queue[j]+0] = m->triangles.node[3*queue[j]+1];
        m->triangles.node[3*queue[j]+1] = temp;
        uint32_t te = e->tri2edg[3*queue[j]+1];
        e->tri2edg[3*queue[j]+1] = e->tri2edg[3*queue[j]+2];
        e->tri2edg[3*queue[j]+2] = te;

        printf("Consistent (?) orientation \t %lu (%u %u %u) ; (%u %u)-(%u %u)-(%u %u) [%d] ~ %lu (%u %u %u) ; (%u %u)-(%u %u)-(%u %u) [%d].\n",queue[i],refVert[0],refVert[1],refVert[2],e->node[2*e->tri2edg[3*queue[i]+0]+0],e->node[2*e->tri2edg[3*queue[i]+0]+1],e->node[2*e->tri2edg[3*queue[i]+1]+0],e->node[2*e->tri2edg[3*queue[i]+1]+1],e->node[2*e->tri2edg[3*queue[i]+2]+0],e->node[2*e->tri2edg[3*queue[i]+2]+1],flag[queue[i]],queue[j],checkVert[0],checkVert[1],checkVert[2],e->node[2*e->tri2edg[3*queue[j]+0]+0],e->node[2*e->tri2edg[3*queue[j]+0]+1],e->node[2*e->tri2edg[3*queue[j]+1]+0],e->node[2*e->tri2edg[3*queue[j]+1]+1],e->node[2*e->tri2edg[3*queue[j]+2]+0],e->node[2*e->tri2edg[3*queue[j]+2]+1],flag[queue[j]]);

      }//end if cond==0
    }//end for j
  }//end for i

  if (partitions!=NULL)
    HXT_CHECK(hxtPartitioning(e,(int*)flag,count,partitions));

  return HXT_STATUS_OK;
}


static HXTStatus hxtSplitEdges(HXTEdges *edges,int nPartitions,HXTVector *partitions)
{

  HXTMesh *mesh = edges->edg2mesh;

  uint32_t *tri2edg = edges->tri2edg;
  uint64_t *edg2tri = edges->edg2tri;

  HXTBoundaries *boundaries;
  HXT_CHECK(hxtEdgesSetBoundaries(edges, &boundaries));
  int nbedg;
  HXT_CHECK(hxtBoundariesGetNumberOfBorderEdges(boundaries,&nbedg));

  int nVertex = (int) mesh->triangles.num;
  int nEdge = (int) (edges->numEdges) - nbedg;

  int *idx=NULL;
  HXT_CHECK(hxtMalloc(&idx,(nVertex+1)*sizeof(int)));
  int *nbh=NULL;
  HXT_CHECK(hxtMalloc(&nbh, 2*nEdge*sizeof(int)));
  int *weights=NULL;
  HXT_CHECK(hxtMalloc(&weights,2*nEdge*sizeof(int)));

  idx[0] = 0;
  for(int i=0; i<nVertex; i++){// triangle by triangle
    uint32_t *current = &tri2edg[3*i];
    int temp = 0;
    for(int j=0; j<3; j++){
      uint64_t *local = &edg2tri[2*current[j]];
      if(local[1]==(uint64_t)-1)
        continue;
      else{
        nbh[idx[i]+temp] = i == (int) local[0] ? (int) local[1] : (int) local[0];
        weights[idx[i]+temp] = (int) (hxtEdgesLength(edges,current[j])+1);
        temp++;
      }
    }

    idx[i+1] = idx[i] + temp;
  }


  // only for k-way
  idx_t options[METIS_NOPTIONS];
  METIS_SetDefaultOptions(options);
  options[METIS_OPTION_NCUTS] = nPartitions;
  //options[METIS_OPTION_MINCONN] = 1;
  //options[METIS_OPTION_CCORDER] = 1;
  options[METIS_OPTION_CONTIG] = 1;
  //options[METIS_OPTION_DBGLVL] = 1;

  int edgeCut;
  int *part;
  HXT_CHECK(hxtMalloc(&part,nVertex*sizeof(int)));
  //int zero = 0;
  int one=1;
  //METIS_PartGraphRecursive(&nVertex,&one,idx,nbh,NULL,NULL,NULL,&nPartitions,NULL,NULL,NULL,&edgeCut,part);
  METIS_PartGraphKway(&nVertex,&one,idx,nbh,NULL,NULL,weights,&nPartitions,NULL,NULL,options,&edgeCut,part);

  HXT_CHECK(hxtFree(&nbh));
  HXT_CHECK(hxtFree(&idx));

  HXT_CHECK(hxtPartitioning(edges,part,nPartitions,partitions));

  return HXT_STATUS_OK;
}

static HXTStatus hxtCuttingProcess(HXTEdges *edges, int ar, int bool, HXTVector *toparam)
{
  HXTBoundaries *boundaries;
  HXT_CHECK(hxtEdgesSetBoundaries(edges, &boundaries));
  int nll, seamPoint;
  HXT_CHECK(hxtBoundariesGetNumberOfLineLoops(boundaries,&nll));
  int g = (edges->numEdges - edges->edg2mesh->vertices.num - edges->edg2mesh->triangles.num + 2 - nll)/2;
  HXT_CHECK(hxtBoundariesGetSeamPoint(boundaries,&seamPoint));

  HXTVector *toSplit;
  HXT_CHECK(hxtVectorInit(&toSplit));
  if(seamPoint!=0 || ar==0 || g!=0 || nll == 0)
    HXT_CHECK(hxtVectorPushBack(toSplit,edges));
  else
    HXT_CHECK(hxtVectorPushBack(toparam,edges));
  for(int i=0; i<toSplit->last+1; i++){
    HXTVector *split=NULL;
    HXT_CHECK(hxtVectorInit(&split));
    HXTEdges *beingSplitted = (HXTEdges*) toSplit->ptr[i];
    HXT_CHECK(hxtSplitEdges(beingSplitted,2,split));
    if(bool>0){
      HXT_CHECK(hxtMeshDelete(&beingSplitted->edg2mesh));
      HXT_CHECK(hxtEdgesDelete(&beingSplitted));
    }
    else
      bool=1;
    for(int j=0; j<split->last+1; j++){
      HXTEdges* piece = (HXTEdges*) split->ptr[j];
      HXT_CHECK(hxtEdgesSetBoundaries(piece, &boundaries));
      HXT_CHECK(hxtBoundariesGetNumberOfLineLoops(boundaries,&nll));
      g = (piece->numEdges - piece->edg2mesh->vertices.num  - piece->edg2mesh->triangles.num + 2 - nll)/2;
      HXT_CHECK(hxtBoundariesGetSeamPoint(boundaries,&seamPoint));
      if(seamPoint !=0 || g != 0 || nll == 0){
        //printf("nl=%d\t g=%d\n",nll,g);
        HXT_CHECK(hxtVectorPushBack(toSplit,piece));
      }
      else
        HXT_CHECK(hxtVectorPushBack(toparam,piece));
    }
    HXT_CHECK(hxtVectorFree(&split));
  }
  HXT_CHECK(hxtVectorFree(&toSplit));
  // free boundaries

  return HXT_STATUS_OK;
}

HXTStatus hxtParametrizationCreate(HXTMesh *mesh, int nrefinements, HXTParametrization **parametrization)
{
  HXTParametrization* param0;
  HXT_CHECK(hxtMalloc(&param0,sizeof(HXTParametrization)));
  *parametrization = param0;

  HXTMesh *initialMesh=NULL;
  HXT_CHECK(hxtMeshCreate(mesh->ctx,&initialMesh));
  *initialMesh = *mesh;
  HXT_CHECK(hxtEdgesCreate(initialMesh, &param0->edges));

  //  printf("checking connectivity ...\n");
  HXT_CHECK(hxtCheckConnectivity(param0->edges,NULL));
  //  HXT_CHECK(hxtLongestEdgeBisection(param0->edges,nrefinements));

  HXTEdges *edges=NULL;
  HXT_CHECK(hxtEdgesCreate(initialMesh, &edges));
  uint64_t *global;
  HXT_CHECK(hxtMalloc(&global,edges->edg2mesh->triangles.num*sizeof(uint64_t)));
  for(uint64_t i=0; i<edges->edg2mesh->triangles.num; i++)
    global[i]= i;
  edges->global = global;
  param0->edges->global = global;

  HXTVector *connect;
  HXT_CHECK(hxtVectorInit(&connect));
  HXT_CHECK(hxtCheckConnectivity(edges,connect));

  //  printf("connectivity is done\n");

  HXTVector *toparam;
  HXT_CHECK(hxtVectorInit(&toparam));
  for(int i=0; i<connect->last+1; i++){
    HXT_CHECK(hxtCuttingProcess(connect->ptr[i],1,0,toparam));
  }
  //printf("initial cutting process is done, %d\n",  param0->n);
  //  return HXT_STATUS_OK;


  HXTVector *atlas;
  HXT_CHECK(hxtVectorInit(&atlas));
  for(int i=0; i<toparam->last+1; i++){
    HXTMeanValues *param;
    HXTEdges *current = (HXTEdges *)(toparam->ptr[i]);
    HXT_CHECK(hxtMeanValuesCreate(current,&param));
    HXT_CHECK(hxtMeanValuesCompute(param));
    int ar = 0;
    HXT_CHECK(hxtMeanValueAspectRatio(param,&ar));

    if (0 && ar==0)
      HXT_CHECK(hxtCuttingProcess(current,ar,toparam->last,toparam));
    else
      HXT_CHECK(hxtVectorPushBack(atlas,param));
  }
  hxtVectorFree(&toparam);

  param0->n = atlas->last+1;
  HXT_CHECK(hxtMalloc(&param0->maps,param0->n*sizeof(HXTMeanValues*)));
  for(int i=0; i<param0->n; i++)
    param0->maps[i] = (HXTMeanValues *) atlas->ptr[i];

  HXT_CHECK(hxtVectorFree(&atlas));
  return HXT_STATUS_OK;
}



HXTStatus hxtParametrizationDelete(HXTParametrization **parametrization)
{

  return HXT_STATUS_OK;
}

HXTStatus hxtParametrizationCompute(HXTParametrization *parametrization, int **_colors_, int **_nNodes_, int **_nodes_, double **_uv_, int *nc, HXTMesh **m)
{

  int *colors=NULL, *nNodes=NULL, *nodes=NULL;
  double *uv=NULL;

  *m = parametrization->edges->edg2mesh;
  int Ncolors = parametrization->n;
  *nc=Ncolors;
  int totalNtriangles = (int) parametrization->edges->edg2mesh->triangles.num;
  HXT_CHECK(hxtMalloc(&colors,totalNtriangles*sizeof(int)));
  HXT_CHECK(hxtMalloc(&nNodes,(Ncolors+1)*sizeof(int)));
  nNodes[0] = 0;
  for(int c=0; c<Ncolors; c++){

    uint64_t *global=NULL;
    int nv, ne;
    HXT_CHECK(hxtMeanValuesGetData(parametrization->maps[c],&global, NULL, NULL, &nv,&ne,0));
    nNodes[c+1] = nNodes[c]+nv;

    for(int ie=0; ie<ne; ie++)
      colors[global[ie]] = c;

    HXT_CHECK(hxtFree(&global));

  }


  HXT_CHECK(hxtMalloc(&uv,2*nNodes[Ncolors]*sizeof(double)));//
  HXT_CHECK(hxtMalloc(&nodes,nNodes[Ncolors]*sizeof(int)));
  for(int it=0; it<nNodes[Ncolors]; it++)
    nodes[it] = -1;

  for(int c=0; c<Ncolors; c++){

    uint64_t *global=NULL;
    uint32_t *gn=NULL;
    double *uvc=NULL;
    int nv, ne;
    HXT_CHECK(hxtMeanValuesGetData(parametrization->maps[c],&global, &gn, &uvc, &nv,&ne,0));
    for(int iv=0; iv<2*nv; iv++)
      uv[2*nNodes[c]+iv] = uvc[iv];

    for(int ie=0; ie<ne; ie++){
      for(int kk=0; kk<3; kk++){
        int gvn = (int) parametrization->edges->edg2mesh->triangles.node[3*global[ie]+kk];
        nodes[nNodes[c]+gn[3*ie+kk]] = gvn;
      }
    }

    HXT_CHECK(hxtFree(&global));
    HXT_CHECK(hxtFree(&gn));
    HXT_CHECK(hxtFree(&uvc));
  }


  *_colors_=colors;
  *_nNodes_=nNodes;
  *_nodes_=nodes;
  *_uv_=uv;

  return HXT_STATUS_OK;
}

HXTStatus hxtParametrizationWrite(HXTParametrization *parametrization, const char *filename)
{

  return HXT_STATUS_OK;
}
