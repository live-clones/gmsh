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
  size_t size;
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

  idx[0] = 0;
  for(int i=0; i<nVertex; i++){// triangle by triangle
    uint32_t *current = &tri2edg[3*i];
    int temp = 0;
    for(int j=0; j<3; j++){      
      uint64_t *local = &edg2tri[2*current[j]];
      if(local[1]==-1){}//printf("ele %d (s1)\n",i+1);}
      else{		
	nbh[idx[i]+temp] = i == (int) local[0] ? (int) local[1] : (int) local[0];
	temp++;
      }
    }
    
    idx[i+1] = idx[i] + temp;
  }

  
  //  int options[5];
  //  options[0] = 1;
  //  options[1] = 1;
  //  options[2] = 1;
  //  options[3] = 1;
  //  options[4] = 0;
  int wgtflag = 0;
  int numflag = 0;
  
  // only for k-way  
  idx_t options[METIS_NOPTIONS];
  METIS_SetDefaultOptions(options);
  options[METIS_OPTION_NCUTS] = nPartitions;
  options[METIS_OPTION_MINCONN] = 1;
  options[METIS_OPTION_CONTIG] = 1;  
  
  int edgeCut;
  int *part;
  HXT_CHECK(hxtMalloc(&part,nVertex*sizeof(int)));
  //int zero = 0;
  int one=1;
  //METIS_PartGraphRecursive(&nVertex,&one,idx,nbh,NULL,NULL,NULL,&nPartitions,NULL,NULL,NULL,&edgeCut,part);
  //  METIS_PartGraphKway(&nVertex,idx,nbh,NULL,NULL,&wgtflag, &numflag,&nPartitions,options,&edgeCut,part);
  //  METIS_PartGraphKway(&nVertex,&one,idx,nbh,NULL,NULL,weights,&nPartitions,NULL,NULL,options,&edgeCut,part);
  METIS_PartGraphKway(&nVertex,&one,idx,nbh,NULL,NULL,NULL,&nPartitions,NULL,NULL,options,&edgeCut,part);
  //  METIS_PartGraphKway(&nVertex,&one,idx,nbh,NULL,NULL,NULL,&nPartitions,NULL,NULL,options,&edgeCut,part);

  HXT_CHECK(hxtFree(&nbh));
  HXT_CHECK(hxtFree(&idx));
  
  
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
	  if(flagVertices[current] == -1)
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
      if(current==-1);
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
    //<    
    edg->global = global;
    //>
    HXT_CHECK(hxtVectorPushBack(partitions,edg));
  }
  return HXT_STATUS_OK;
}

static HXTStatus hxtCuttingProcess(HXTEdges *edges, int ar, int bool, HXTVector *toparam)
{

  HXTBoundaries *boundaries;
  HXT_CHECK(hxtEdgesSetBoundaries(edges, &boundaries));
  int nll;
  HXT_CHECK(hxtBoundariesGetNumberOfLineLoops(boundaries,&nll));
  int g = (edges->numEdges - edges->edg2mesh->vertices.num - edges->edg2mesh->triangles.num + 2 - nll)/2;
  
  HXTVector *toSplit;
  HXT_CHECK(hxtVectorInit(&toSplit));  
  if(ar==0 || g!=0 || nll == 0)
    HXT_CHECK(hxtVectorPushBack(toSplit,edges));
  else
    HXT_CHECK(hxtVectorPushBack(toparam,edges));
  for(int i=0; i<toSplit->last+1; i++){
    HXTVector *split=NULL;
    HXT_CHECK(hxtVectorInit(&split));
    HXTEdges *beingSplitted = (HXTEdges*) toSplit->ptr[i];
    HXT_CHECK(hxtSplitEdges(beingSplitted,2,split));
    if(bool==1){
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
      if(g!=0 || nll==0){
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

HXTStatus hxtParametrizationCreate(HXTMesh *mesh, HXTParametrization **parametrization)
{
  HXTParametrization* param;
  HXT_CHECK(hxtMalloc(&param,sizeof(HXTParametrization)));
  *parametrization = param;

  HXTMesh *initialMesh=NULL;
  HXT_CHECK(hxtMeshCreate(mesh->ctx,&initialMesh));
  *initialMesh = *mesh;
  HXT_CHECK(hxtEdgesCreate(initialMesh, &param->edges));
  
  HXTEdges *edges=NULL;
  HXT_CHECK(hxtEdgesCreate(initialMesh, &edges));
  uint64_t *global;
  HXT_CHECK(hxtMalloc(&global,edges->edg2mesh->triangles.num*sizeof(uint64_t)));
  for(uint64_t i=0; i<edges->edg2mesh->triangles.num; i++)
    global[i]= i;
  edges->global = global;
  param->edges->global = global;
  HXTVector *toparam;
  HXT_CHECK(hxtVectorInit(&toparam));
  HXT_CHECK(hxtCuttingProcess(edges,1,0,toparam));
  
  HXTVector *atlas;
  HXT_CHECK(hxtVectorInit(&atlas));
  for(int i=0; i<toparam->last+1; i++){
    HXTMeanValues *param;
    HXTEdges *current = (HXTEdges *)(toparam->ptr[i]);
    HXT_CHECK(hxtMeanValuesCreate(current,&param));
    HXT_CHECK(hxtMeanValuesCompute(param));
    int ar;
    HXT_CHECK(hxtMeanValueAspectRatio(param,&ar));
    
    if (ar==0){
      //printf("wrong aspect ratio!\n");
      HXT_CHECK(hxtCuttingProcess(current,ar,1,toparam));
      //printf("splitting process: ok\n");      
    }
    else
      HXT_CHECK(hxtVectorPushBack(atlas,param));
  }
  hxtVectorFree(&toparam);


  
  param->n = atlas->last+1;
  //printf("n=%d\n",param->n);
  HXT_CHECK(hxtMalloc(&param->maps,param->n*sizeof(HXTMeanValues*)));
  for(int i=0; i<param->n; i++){
    param->maps[i] = (HXTMeanValues *) atlas->ptr[i];
    //    char str0[64];
    //    sprintf(str0, "param_%d.msh",i);
    //    HXT_CHECK(hxtMeanValuesWrite(param->maps[i],str0));
    //    char str1[64];
    //    sprintf(str1, "paramMesh_%d.msh",i);
    //    HXT_CHECK(hxtMeanValuesWriteParamMesh(param->maps[i],str1));
    //printf("writing (%d/%d): ok\n",i,param->n-1);
  }
  HXT_CHECK(hxtVectorFree(&atlas));
  return HXT_STATUS_OK;
}



HXTStatus hxtParametrizationDelete(HXTParametrization **parametrization)
{

  return HXT_STATUS_OK;
}

HXTStatus hxtParametrizationCompute(HXTParametrization *parametrization, int **_colors_, int **_nNodes_, int **_nodes_, double **_uv_, int *nc)
{

  int *colors=NULL, *nNodes=NULL, *nodes=NULL;
  double *uv=NULL;
  
  int Ncolors = parametrization->n;
  *nc=Ncolors;
  int totalNtriangles = (int) parametrization->edges->edg2mesh->triangles.num;
  //int totalNvertices = parametrization->edges->edg2mesh->vertices.num;
  
  HXT_CHECK(hxtMalloc(&colors,totalNtriangles*sizeof(int)));
  HXT_CHECK(hxtMalloc(&nNodes,(Ncolors+1)*sizeof(int)));
  nNodes[0] = 0;
  for(int c=0; c<Ncolors; c++){

    uint64_t *global=NULL;
    int nv, ne;    
    HXT_CHECK(hxtMeanValuesGetData(parametrization->maps[c],&global, NULL, NULL, &nv,&ne));
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
    HXT_CHECK(hxtMeanValuesGetData(parametrization->maps[c],&global, &gn, &uvc, &nv,&ne));
    for(int iv=0; iv<2*nv; iv++)
      uv[2*nNodes[c]+iv] = uvc[iv];
    
    for(int ie=0; ie<ne; ie++){
      for(int kk=0; kk<3; kk++){
	//printf("c=%d, ie=%d, global[ie]=%lu, kk=%d \t %lu\n",c,ie,global[ie],kk,3*parametrization->edges->edg2mesh->triangles.num);
	int gvn = (int) parametrization->edges->edg2mesh->triangles.node[3*global[ie]+kk];
	nodes[nNodes[c]+gn[3*ie+kk]] = gvn;
      }
    }

    //printf("maybe not\n");
    HXT_CHECK(hxtFree(&global));
    //printf("-----------0\n");
    HXT_CHECK(hxtFree(&gn));
    //printf("-----------1\n");
    HXT_CHECK(hxtFree(&uvc));
    //printf("-----------2\n");
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
