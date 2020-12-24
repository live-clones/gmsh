#include "hxt_surface_mesh_processing.h"

#include "hxt_point_gen_numerics.h"

#include "hxt_point_gen_realloc.h"
#include "hxt_point_gen_utils.h"

#include "hxt_triangle_quality.h"

#include "hxt_edge.h"
#include "predicates.h"
#include "hxt_sort.h"

#include "hxt_post_debugging.h"

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to split all quads of a full-quad mesh to triangles 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtSurfaceMeshSplitFullQuad(HXTMesh *mesh)
{

  //******************************************************************
  // Allocate triangles and split quads
  //******************************************************************
  HXT_CHECK(hxtTrianglesReserve(mesh,mesh->quads.num*2));

  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;

    mesh->triangles.node[3*mesh->triangles.num+0] = v[0];
    mesh->triangles.node[3*mesh->triangles.num+1] = v[1];
    mesh->triangles.node[3*mesh->triangles.num+2] = v[2];
    mesh->triangles.color[mesh->triangles.num] = mesh->quads.color[i];
    mesh->triangles.num++;

    double n1[3];
    HXT_CHECK(normal2triangle(mesh,mesh->triangles.num-1,n1));

    mesh->triangles.node[3*mesh->triangles.num+0] = v[0];
    mesh->triangles.node[3*mesh->triangles.num+1] = v[2];
    mesh->triangles.node[3*mesh->triangles.num+2] = v[3];
    mesh->triangles.color[mesh->triangles.num] =  mesh->quads.color[i];
    mesh->triangles.num++;

    double n2[3];
    HXT_CHECK(normal2triangle(mesh,mesh->triangles.num-1,n2));

/*    printf("%f %f %f \n", n1[0], n1[1], n1[2]);*/
    /*printf("%f %f %f \n", n2[0], n1[1], n2[2]);*/
    /*printf("%f \n", myDot(n1,n2));*/
    /*if (myDot(n1,n2)<0) printf("HERE\n");*/
    /*printf("\n");*/


    /*if (myDot(n1,n2)<0){*/
      /*FILE *out;*/
      /*hxtPosInit("badQuad.pos","points",&out);*/


      /*hxtPosAddPoint(out,&mesh->vertices.coord[4*v[0]],0);*/
      /*hxtPosAddPoint(out,&mesh->vertices.coord[4*v[1]],0);*/
      /*hxtPosAddPoint(out,&mesh->vertices.coord[4*v[2]],0);*/
      /*hxtPosAddPoint(out,&mesh->vertices.coord[4*v[3]],0);*/
      /*hxtPosAddText(out,&mesh->vertices.coord[4*v[0]],"%d",0);*/
      /*hxtPosAddText(out,&mesh->vertices.coord[4*v[1]],"%d",1);*/
      /*hxtPosAddText(out,&mesh->vertices.coord[4*v[2]],"%d",2);*/
      /*hxtPosAddText(out,&mesh->vertices.coord[4*v[3]],"%d",3);*/

      /*hxtPosAddLine(out,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],0);*/
      /*hxtPosAddLine(out,&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);*/
      /*hxtPosAddLine(out,&mesh->vertices.coord[4*v[2]],&mesh->vertices.coord[4*v[3]],0);*/
      /*hxtPosAddLine(out,&mesh->vertices.coord[4*v[3]],&mesh->vertices.coord[4*v[0]],0);*/

      /*hxtPosFinish(out);*/
    /*}*/

    if (myDot(n1,n2)<0){
      mesh->triangles.num -= 2;

      mesh->triangles.node[3*mesh->triangles.num+0] = v[0];
      mesh->triangles.node[3*mesh->triangles.num+1] = v[1];
      mesh->triangles.node[3*mesh->triangles.num+2] = v[3];
      mesh->triangles.color[mesh->triangles.num] = mesh->quads.color[i];
      mesh->triangles.num++;
  
      double n1[3];
      HXT_CHECK(normal2triangle(mesh,mesh->triangles.num-1,n1));
  
      mesh->triangles.node[3*mesh->triangles.num+0] = v[1];
      mesh->triangles.node[3*mesh->triangles.num+1] = v[2];
      mesh->triangles.node[3*mesh->triangles.num+2] = v[3];
      mesh->triangles.color[mesh->triangles.num] =  mesh->quads.color[i];
      mesh->triangles.num++;

    }

  }

  //******************************************************************
  // Save mesh points
  //******************************************************************
  uint64_t *counter;
  HXT_CHECK(hxtMalloc(&counter,sizeof(UINT64_MAX)*mesh->vertices.num));
  for (uint32_t i=0; i<mesh->vertices.num; i++) counter[i]=0;
  for (uint64_t i=0; i<mesh->lines.num; i++){
    counter[mesh->lines.node[2*i+0]]++;
    counter[mesh->lines.node[2*i+1]]++;
  }
  uint32_t countBP = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (counter[i]>2) countBP++;
  }
  HXT_CHECK(hxtPointsReserve(mesh,countBP));
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (counter[i]>2){
      mesh->points.node[mesh->points.num] = i;
      mesh->points.num++;
    }
  }
  HXT_CHECK(hxtFree(&counter));



  //******************************************************************
  // Delete quads
  //******************************************************************
  HXT_CHECK( hxtAlignedFree(&mesh->quads.node) );
  HXT_CHECK( hxtAlignedFree(&mesh->quads.color) );
  mesh->quads.num = 0 ;
  mesh->quads.size = 0 ;

  return HXT_STATUS_OK;
}




//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to split all quads of a mesh to triangles 
//          and assign them to a color 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtSurfaceMeshSplitQuads(HXTMesh *mesh, uint16_t *color)
{
  int verbosity = 0;

  //******************************************************************
  // Find a color that is not on the list of colors of the input mesh
  // This will be used to flag triangles splitted from quads 
  //******************************************************************
  uint16_t *triColors; 
  uint16_t numTriColors; 
  HXT_CHECK(hxtGetTrianglesColorList(mesh,&numTriColors,&triColors)); 
  HXT_INFO_COND(verbosity>=0,"Number of input mesh colors          %d", numTriColors); 
  for (uint16_t i=0; i<UINT16_MAX; i++){
    int found = 0;
    for (uint16_t j=0; j<numTriColors; j++){
      uint16_t cc = triColors[j];
      if (i == cc){
        found = 1;
        break;
      }
    }
    if (found == 0){
      *color = i;
      break;
    }
  }
  HXT_CHECK(hxtFree(&triColors));


  //******************************************************************
  // Allocate triangles and split quads
  //******************************************************************
  HXT_CHECK(hxtTrianglesReserve(mesh,mesh->quads.num*2));

  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;

    mesh->triangles.node[3*mesh->triangles.num+0] = v[0];
    mesh->triangles.node[3*mesh->triangles.num+1] = v[1];
    mesh->triangles.node[3*mesh->triangles.num+2] = v[2];
    mesh->triangles.color[mesh->triangles.num] = *color;
    mesh->triangles.num++;

    mesh->triangles.node[3*mesh->triangles.num+0] = v[0];
    mesh->triangles.node[3*mesh->triangles.num+1] = v[2];
    mesh->triangles.node[3*mesh->triangles.num+2] = v[3];
    mesh->triangles.color[mesh->triangles.num] = *color;
    mesh->triangles.num++;
  }

  //******************************************************************
  // Save mesh lines (interface edges between quads and triangles)
  //******************************************************************
  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));
  uint64_t countLines = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.color[i] == *color) continue;
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      uint16_t c0 = mesh->triangles.color[t0];
      uint16_t c1 = mesh->triangles.color[t1];
      if (c0 != *color && c1 != *color) continue;
      if(c0 != c1) countLines++;
    }
  }
  HXT_CHECK(hxtLinesReserve(mesh,countLines));
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.color[i] == *color) continue;
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];

      uint16_t c0 = mesh->triangles.color[t0];
      uint16_t c1 = mesh->triangles.color[t1];
      if (c0 != *color && c1 != *color) continue;
      if(c0 != c1){
        mesh->lines.node[2*mesh->lines.num+0] = edges->node[2*ce+0];
        mesh->lines.node[2*mesh->lines.num+1] = edges->node[2*ce+1];
        mesh->lines.color[mesh->lines.num] = 0;
        mesh->lines.num++;
      }
    }
  }
  HXT_CHECK(hxtEdgesDelete(&edges));

  //******************************************************************
  // Save mesh points
  //******************************************************************
  uint64_t *counter;
  HXT_CHECK(hxtMalloc(&counter,sizeof(UINT64_MAX)*mesh->vertices.num));
  for (uint32_t i=0; i<mesh->vertices.num; i++) counter[i]=0;
  for (uint64_t i=0; i<mesh->lines.num; i++){
    counter[mesh->lines.node[2*i+0]]++;
    counter[mesh->lines.node[2*i+1]]++;
  }
  uint32_t countBP = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (counter[i]>2) countBP++;
  }
  HXT_CHECK(hxtPointsReserve(mesh,countBP));
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (counter[i]>2){
      mesh->points.node[mesh->points.num] = i;
      mesh->points.num++;
    }
  }
  HXT_CHECK(hxtFree(&counter));



  //******************************************************************
  // Delete quads
  //******************************************************************
  HXT_CHECK( hxtAlignedFree(&mesh->quads.node) );
  HXT_CHECK( hxtAlignedFree(&mesh->quads.color) );
  mesh->quads.num = 0 ;
  mesh->quads.size = 0 ;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//*****************************************************************************************
//*****************************************************************************************
int cmpfunc(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

static int compare (const void * a, const void * b)
{
  if (*(double*)a > *(double*)b) return 1;
  else if (*(double*)a < *(double*)b) return -1;
  else return 0;  
}

HXTStatus hxtSurfaceQuadSize(HXTMesh *mesh)
{
  if (mesh->quads.num == 0 || mesh->triangles.num != 0) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Mesh should contain only quads");

  double *sizes;
  HXT_CHECK(hxtMalloc(&sizes,mesh->quads.num*4*sizeof(double)));
  for (uint64_t i=0; i<mesh->quads.num*4; i++) sizes[i] = 0;

  uint64_t countEdges = 0;
  double avg = 0;
  double min = 10e12;
  double max = -10e12;
  for (uint64_t i=0; i<mesh->quads.num; i++){

    double *p0 = mesh->vertices.coord + 4*mesh->quads.node[4*i+0];
    double *p1 = mesh->vertices.coord + 4*mesh->quads.node[4*i+1];
    double *p2 = mesh->vertices.coord + 4*mesh->quads.node[4*i+2];
    double *p3 = mesh->vertices.coord + 4*mesh->quads.node[4*i+3];

    double s[4] = {0,0,0,0};
    s[0] = distance(p0,p1);
    s[1] = distance(p1,p2);
    s[2] = distance(p2,p3);
    s[3] = distance(p3,p0);

    for (uint32_t j=0; j<4; j++){
      if (s[j] > max) max = s[j];
      if (s[j] < min) min = s[j];

      avg += s[j];
      sizes[countEdges] = s[j];
      countEdges++;
    }
  }

  avg /= countEdges;

  printf("\n");
  printf("minSize = %f \n", min);
  printf("maxSize = %f \n", max);
  printf("avgSize = %f \n", avg);


  qsort(sizes,countEdges,sizeof(sizes[0]),compare);

  uint64_t median = (countEdges+1)/2 - 1;

  printf("medSize = %f \n", sizes[median]);
  printf("\n");

  HXT_CHECK(hxtFree(&sizes));

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtHexMeshBoundary(HXTMesh *mesh)
{
  typedef struct{
    uint32_t v[4];
    uint32_t vs[4];
    int b;
  }quad;

  quad *quads;
  HXT_CHECK(hxtMalloc(&quads,mesh->hexahedra.num*6*sizeof(quad)));

  uint64_t countQuads = 0;
  for (uint64_t i=0; i<mesh->hexahedra.num; i++){

    quads[countQuads].v[0] = mesh->hexahedra.node[8*i+0];
    quads[countQuads].v[1] = mesh->hexahedra.node[8*i+1];
    quads[countQuads].v[2] = mesh->hexahedra.node[8*i+2];
    quads[countQuads].v[3] = mesh->hexahedra.node[8*i+3];
    quads[countQuads].b = -1;
    countQuads++;

    quads[countQuads].v[0] = mesh->hexahedra.node[8*i+2];
    quads[countQuads].v[1] = mesh->hexahedra.node[8*i+3];
    quads[countQuads].v[2] = mesh->hexahedra.node[8*i+7];
    quads[countQuads].v[3] = mesh->hexahedra.node[8*i+6];
    quads[countQuads].b = -1;
    countQuads++;


    quads[countQuads].v[0] = mesh->hexahedra.node[8*i+7];
    quads[countQuads].v[1] = mesh->hexahedra.node[8*i+4];
    quads[countQuads].v[2] = mesh->hexahedra.node[8*i+5];
    quads[countQuads].v[3] = mesh->hexahedra.node[8*i+6];
    quads[countQuads].b = -1;
    countQuads++;


    quads[countQuads].v[0] = mesh->hexahedra.node[8*i+4];
    quads[countQuads].v[1] = mesh->hexahedra.node[8*i+0];
    quads[countQuads].v[2] = mesh->hexahedra.node[8*i+1];
    quads[countQuads].v[3] = mesh->hexahedra.node[8*i+5];
    quads[countQuads].b = -1;
    countQuads++;


    quads[countQuads].v[0] = mesh->hexahedra.node[8*i+1];
    quads[countQuads].v[1] = mesh->hexahedra.node[8*i+2];
    quads[countQuads].v[2] = mesh->hexahedra.node[8*i+6];
    quads[countQuads].v[3] = mesh->hexahedra.node[8*i+5];
    quads[countQuads].b = -1;
    countQuads++;


    quads[countQuads].v[0] = mesh->hexahedra.node[8*i+0];
    quads[countQuads].v[1] = mesh->hexahedra.node[8*i+4];
    quads[countQuads].v[2] = mesh->hexahedra.node[8*i+7];
    quads[countQuads].v[3] = mesh->hexahedra.node[8*i+3];
    quads[countQuads].b = -1;
    countQuads++;
  }

  // Sort
  for (uint64_t i=0; i<countQuads; i++){
    uint32_t v[4] = {quads[i].v[0],quads[i].v[1],quads[i].v[2],quads[i].v[3]};
    qsort(v,4,sizeof(uint32_t),cmpfunc);
    quads[i].vs[0] = v[0];
    quads[i].vs[1] = v[1];
    quads[i].vs[2] = v[2];
    quads[i].vs[3] = v[3];
  }


  for (uint64_t i=0; i<countQuads; i++){

    uint32_t v[4] = {quads[i].vs[0],quads[i].vs[1],quads[i].vs[2],quads[i].vs[3]};

    int unique = 1;

    for (uint64_t j=0; j<countQuads; j++){

      if (j==i) continue;

      uint32_t n[4] = {quads[j].vs[0],quads[j].vs[1],quads[j].vs[2],quads[j].vs[3]};

      if (v[0] == n[0] && v[1] == n[1] && v[2] == n[2] && v[3] == n[3]){
        unique = 0;
        break;
      }

    }

    //if (unique == 1) printf("OPA %lu \n", i);
    if (unique == 1) quads[i].b=1;


  }


  FILE *test;
  hxtPosInit("quads.pos","quads",&test);

  uint64_t countBquads=0;
  for (uint64_t i=0; i<countQuads; i++){
    if (quads[i].b != 1) continue;
      hxtPosAddQuad(test,&mesh->vertices.coord[4*quads[i].v[0]],
                         &mesh->vertices.coord[4*quads[i].v[1]],
                         &mesh->vertices.coord[4*quads[i].v[2]],
                         &mesh->vertices.coord[4*quads[i].v[3]],0);
      countBquads++;
  }
  hxtPosFinish(test);

  HXT_CHECK(hxtQuadsReserve(mesh,countBquads));
  countBquads=0;
  for (uint64_t i=0; i<countQuads; i++){
    if (quads[i].b != 1) continue;
    mesh->quads.node[4*countBquads+0] = quads[i].v[0];
    mesh->quads.node[4*countBquads+1] = quads[i].v[1];
    mesh->quads.node[4*countBquads+2] = quads[i].v[2];
    mesh->quads.node[4*countBquads+3] = quads[i].v[3];
    countBquads++;
  }

  mesh->quads.num = countBquads;

  HXT_CHECK( hxtAlignedFree(&mesh->hexahedra.node) );
  HXT_CHECK( hxtAlignedFree(&mesh->hexahedra.color) );
  mesh->hexahedra.num = 0 ;
  mesh->hexahedra.size = 0 ;







  HXT_CHECK(hxtFree(&quads));

  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtSurfaceQuadColorBipartite(HXTMesh *mesh)
{
  if (mesh->quads.num == 0 || mesh->triangles.num != 0) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Mesh should contain only quads");

  int *bin;
  HXT_CHECK(hxtMalloc(&bin,mesh->vertices.num*sizeof(int)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) bin[i] = -1;


  while(1){
    for (uint64_t i=0; i<mesh->quads.num; i++){
      if (i==0){
        uint32_t *v = mesh->quads.node + 4*i;
        bin[v[0]] = 0;
        bin[v[1]] = 1;
        bin[v[2]] = 0;
        bin[v[3]] = 1;
        continue;
      }

      uint32_t *v = mesh->quads.node+4*i;

      for (uint32_t j=0; j<4; j++){
        if (bin[v[j]] == -1) continue;
        uint32_t j0 = j-1;
        uint32_t j1 = j+1;
        if (j==0) j0 = 3;
        if (j==3) j1 = 0;
        bin[v[j0]] = bin[v[j]] == 0 ? 1:0;
        bin[v[j1]] = bin[v[j]] == 0 ? 1:0;
      }
    }

    int still = 1;
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if(bin[i]==-1) still = 0;
    }
    if (still==1) break;
  }


  FILE *test = fopen("binInput.txt","w");
  fprintf(test,"%d\n",mesh->vertices.num);
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    fprintf(test,"%d\n",bin[i]);
  }
  fprintf(test,"\n");
  fclose(test);


  FILE *out;
  hxtPosInit("bin3Dout.pos","bin",&out);
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    hxtPosAddPoint(out,&mesh->vertices.coord[4*i],bin[i]);
  }
  hxtPosFinish(out);




  HXT_CHECK(hxtFree(&bin));
  return HXT_STATUS_OK;
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
    if (nmesh->triangles.color[i] == UINT16_MAX) continue;
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
    if (nmesh->triangles.color[i] == UINT16_MAX) continue;
    double *p0 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+0];
    double *p1 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+1];
    double *p2 = nmesh->vertices.coord + 4*nmesh->triangles.node[3*i+2];
    hxtPosAddTriangle2(out,p0,p1,p2,qual[i]);
  }
  
  HXT_CHECK(hxtFree(&qual));
  hxtPosFinish(out);
  
  return HXT_STATUS_OK;
}



