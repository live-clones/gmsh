#include <math.h>
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_realloc.h"
#include "hxt_bbox.h"

#include "hxt_curvature.h"
#include "hxt_point_gen_numerics.h"
#include "hxt_rtree_wrapper.h"

#include "hxt_post_debugging.h"

static double sign(double a){
  return a>=0 ? 1.:-1;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to split all quads of a mesh to triangles 
//          and assign them to a color 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenSplitQuads(HXTMesh *mesh, uint16_t *color)
{

  //******************************************************************
  // Find a color that is not on the list of colors of the input mesh
  // This will be used to flag triangles splitted from quads 
  //******************************************************************
  uint16_t *triColors; 
  uint16_t numTriColors; 
  HXT_CHECK(hxtGetTrianglesColorsList(mesh,&numTriColors,&triColors)); 
  HXT_INFO("Number of input mesh colors          %d", numTriColors); 
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
    mesh->triangles.colors[mesh->triangles.num] = *color;
    mesh->triangles.num++;

    mesh->triangles.node[3*mesh->triangles.num+0] = v[0];
    mesh->triangles.node[3*mesh->triangles.num+1] = v[2];
    mesh->triangles.node[3*mesh->triangles.num+2] = v[3];
    mesh->triangles.colors[mesh->triangles.num] = *color;
    mesh->triangles.num++;
  }

  //******************************************************************
  // Save mesh lines (interface edges between quads and triangles)
  //******************************************************************
  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));
  uint64_t countLines = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] == *color) continue;
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      uint16_t c0 = mesh->triangles.colors[t0];
      uint16_t c1 = mesh->triangles.colors[t1];
      if (c0 != *color && c1 != *color) continue;
      if(c0 != c1) countLines++;
    }
  }
  HXT_CHECK(hxtLinesReserve(mesh,countLines));
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] == *color) continue;
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];

      uint16_t c0 = mesh->triangles.colors[t0];
      uint16_t c1 = mesh->triangles.colors[t1];
      if (c0 != *color && c1 != *color) continue;
      if(c0 != c1){
        mesh->lines.node[2*mesh->lines.num+0] = edges->node[2*ce+0];
        mesh->lines.node[2*mesh->lines.num+1] = edges->node[2*ce+1];
        mesh->lines.colors[mesh->lines.num] = 0;
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
  HXT_CHECK( hxtAlignedFree(&mesh->quads.colors) );
  mesh->quads.num = 0 ;
  mesh->quads.size = 0 ;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to extract and write out a color 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtExtractColoredSurface(HXTMesh *mesh, uint16_t color)
{
  printf("Extracting and writng out colored surface %d\n", color);
  HXTMesh *omesh;
  HXT_CHECK(hxtMeshCreate(&omesh));

  uint64_t countTri = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] == color){
      countTri++;
    }
  }
  HXT_CHECK(hxtVerticesReserve(omesh, mesh->vertices.num));
  HXT_CHECK(hxtTrianglesReserve(omesh,countTri));
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    omesh->vertices.coord[i] = mesh->vertices.coord[i];
    omesh->vertices.num++;
  }
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] == color){
      omesh->triangles.colors[omesh->triangles.num] = mesh->triangles.colors[i];
      omesh->triangles.node[3*omesh->triangles.num+0] = mesh->triangles.node[3*i+0];
      omesh->triangles.node[3*omesh->triangles.num+1] = mesh->triangles.node[3*i+1];
      omesh->triangles.node[3*omesh->triangles.num+2] = mesh->triangles.node[3*i+2];
      omesh->triangles.num++;
    }
  }
  HXT_CHECK(hxtMeshWriteGmsh(omesh, "extractedColor.msh"));
  HXT_CHECK(hxtMeshDelete(&omesh));
  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to check if there are triangles with zero area 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtCheckZeroAreaTriangles(HXTMesh *mesh, const char *filename) 
{
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+1];
    double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+2];
    double normals[3];
    normal2triangleAreaV(v0,v1,v2,normals);
    double area  = norm(normals)/2.;
    if (area<10e-12){
      FILE *lt;
      hxtPosInit("triangleWithZeroArea.pos", "Check", &lt); 
      hxtPosAddTriangle(lt,v0,v1,v2,mesh->triangles.colors[i]);
      hxtPosNewView(lt,"Edge 0");
      hxtPosAddLine(lt,v0,v1,0);
      hxtPosNewView(lt,"Edge 1");
      hxtPosAddLine(lt,v1,v2,0);
      hxtPosNewView(lt,"Edge 2");
      hxtPosAddLine(lt,v2,v0,0);
      hxtPosFinish(lt);
      HXT_CHECK(hxtMeshWriteGmsh(mesh,filename));
      printf("Triangle with zero area %lu - %d %d %d \n", i, mesh->triangles.node[3*i+0], 
                                                             mesh->triangles.node[3*i+1], 
                                                             mesh->triangles.node[3*i+2]);
      //return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Triangle with zero area %lu %lu - %.16f",i, i+mesh->points.num+mesh->lines.num+1,area);
    }
  }

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to construct frame with 3 direction vectors
//
//  - INPUT is the array 'dirs' with one direction per edge
//  - OUTPUT is the array 'directions' with direction frame (3 vectors) per edge
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenConstructFrame(HXTMesh *mesh, double *dirs, double *dirsFrame)
{
  // The file gives only one direction per edge
  // Construct an array with the full frame by using the normal to each edge
  
  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));
  double normal[3];
  double normal0[3], normal1[3];
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    HXT_CHECK(normal2triangle(mesh,t0,normal0));
    if (t1 == UINT64_MAX){
      normal[0] = normal0[0];
      normal[1] = normal0[1];
      normal[2] = normal0[2];
    }
    else{
      HXT_CHECK(normal2triangle(mesh,t1,normal1));
      normal[0] = (normal0[0] + normal1[0])/2.;
      normal[1] = (normal0[1] + normal1[1])/2.;
      normal[2] = (normal0[2] + normal1[2])/2.;
      normalize(normal);
    }


    dirsFrame[9*i+0] = dirs[3*i+0];
    dirsFrame[9*i+1] = dirs[3*i+1];
    dirsFrame[9*i+2] = dirs[3*i+2];
    HXT_CHECK(myNormalizedCrossprod(&dirs[3*i+0],normal,&dirsFrame[9*i+3]));
    dirsFrame[9*i+6] = normal[0];
    dirsFrame[9*i+7] = normal[1];
    dirsFrame[9*i+8] = normal[2];
  }
  HXT_CHECK(hxtEdgesDelete(&edges));

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to get closest direction froma 3-vector frame input 
//
//*****************************************************************************************
//*****************************************************************************************
static HXTStatus getClosestDir(double *dir0, double *dirFrame, double *dir1)
{

  double maxDot = 0;
  for (int j=0; j<3; j++){
    if (fabs(myDot(dir0,&dirFrame[3*j]))>maxDot){
      maxDot = fabs(myDot(dir0,&dirFrame[3*j]));
      double s = sign(myDot(dir0,&dirFrame[3*j]));
      dir1[0] = s*dirFrame[3*j+0];
      dir1[1] = s*dirFrame[3*j+1];
      dir1[2] = s*dirFrame[3*j+2];
    }
  }

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to convert input directions from edges to vertices 
//
//  - INPUT is the array 'dirs' with direction frame (3 vectors) per edge
//  - OUTPUT is the array 'directions' with direction frame (3 vectors) per vertex
//
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenDirectionsEdgesToVertices(HXTMesh *mesh, double *dirs, double *directions)
{

  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));

  //***********************************************************************************************
  // Create vertices to lines array; 
  //***********************************************************************************************
  uint64_t maxNumLinesToVertex = 0;
  HXT_CHECK(hxtCountMaxNumberOfLinesToVertices(mesh,&maxNumLinesToVertex));
  
  uint64_t *vertices2lines;
  HXT_CHECK(hxtMalloc(&vertices2lines, maxNumLinesToVertex*mesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<maxNumLinesToVertex*mesh->vertices.num; i++) vertices2lines[i] = UINT64_MAX;
  HXT_CHECK(hxtGetVerticesToLines(mesh,maxNumLinesToVertex,vertices2lines));

  //***********************************************************************************************
  // Create vertices to triangles array; 
  //***********************************************************************************************
  uint64_t *vertices2triangles;
  HXT_CHECK(hxtMalloc(&vertices2triangles, mesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) vertices2triangles[i] = UINT64_MAX;
  HXT_CHECK(hxtGetVerticesToTriangles(mesh,vertices2triangles));

  //***********************************************************************************************
  // Create lines to edges array; 
  //***********************************************************************************************
  uint32_t *lines2edges;
  HXT_CHECK(hxtMalloc(&lines2edges,mesh->lines.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->lines.num; i++) lines2edges[i] = UINT32_MAX;
  HXT_CHECK(hxtGetLinesToEdges(edges,lines2edges));

  //***********************************************************************************************
  // Create edges to lines array;
  //***********************************************************************************************
  uint64_t *edges2lines;
  HXT_CHECK(hxtMalloc(&edges2lines,edges->numEdges*sizeof(uint64_t)));
  for (uint32_t i=0; i<edges->numEdges; i++) edges2lines[i] = UINT64_MAX;
  HXT_CHECK(hxtGetEdgesToLines(edges,lines2edges,edges2lines));

  uint8_t *isTriVertex;
  HXT_CHECK(hxtMalloc(&isTriVertex,mesh->vertices.num*sizeof(uint8_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) isTriVertex[i] = UINT8_MAX;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    isTriVertex[mesh->triangles.node[3*i+0]] = 1;
    isTriVertex[mesh->triangles.node[3*i+1]] = 1;
    isTriVertex[mesh->triangles.node[3*i+2]] = 1;
  }

  for (uint32_t i=0; i<mesh->vertices.num; i++){

    if (isTriVertex[i] == UINT8_MAX) continue; //disregard interior vertices for volume meshes

    double dirT[9] = {0.};
    int N = 0; 

    // For vertices on the boundary interpolate directions
    // from the two adjacent boundary edges (lines)
    if (vertices2lines[maxNumLinesToVertex*i+0] != UINT64_MAX){

      uint64_t countLines = 0;
      for (uint64_t j=0; j<maxNumLinesToVertex; j++){
        if (vertices2lines[maxNumLinesToVertex*i+j] == UINT64_MAX) break;
        countLines++;
      }

      // Take reference direction frame from first edge
      uint32_t edg0 = lines2edges[vertices2lines[maxNumLinesToVertex*i+0]];
      double *dir0 = &dirs[9*edg0];
      for (uint32_t j=0; j<9; j++) dirT[j] = dir0[j];

      for (uint64_t j=1; j<countLines; j++){
        uint32_t edg1 = lines2edges[vertices2lines[maxNumLinesToVertex*i+j]];
        for (uint32_t k=0; k<3; k++){
          double *dirR = &dirs[9*edg0+3*k];
          double dir1[3] = {0.};
          HXT_CHECK(getClosestDir(dirR,&dirs[9*edg1],dir1));

          dirT[3*k+0] += dir1[0];
          dirT[3*k+1] += dir1[1];
          dirT[3*k+2] += dir1[2];
        }
      }
      N = countLines;

    }
    else{
      uint32_t cavSize = 0;
      uint32_t cavity[100];
      HXT_CHECK(hxtVertexCavityEdges(mesh,edges,i,vertices2triangles[i],&cavSize,cavity));

      // Take reference direction frame from first edge
      uint32_t edg0 = cavity[0];
      double *dir0 = &dirs[9*edg0];
      for (uint32_t j=0; j<9; j++) dirT[j] = dir0[j];

      for (uint64_t j=1; j<cavSize; j++){
        uint32_t edg1 = cavity[j];
        for (uint32_t k=0; k<3; k++){
          double *dirR = &dirs[9*edg0+3*k];
          double dir1[3] = {0.};
          HXT_CHECK(getClosestDir(dirR,&dirs[9*edg1],dir1));

          dirT[3*k+0] += dir1[0];
          dirT[3*k+1] += dir1[1];
          dirT[3*k+2] += dir1[2];
        }
      }
      N = cavSize;
    }

    for (uint32_t j=0; j<9; j++) directions[9*i+j] = dirT[j]/N; 
    normalize(&directions[9*i+0]);
    normalize(&directions[9*i+3]);
    normalize(&directions[9*i+6]);

  }

  HXT_CHECK(hxtEdgesDelete(&edges));

  HXT_CHECK(hxtFree(&isTriVertex));

  HXT_CHECK(hxtFree(&vertices2lines));
  HXT_CHECK(hxtFree(&vertices2triangles));

  HXT_CHECK(hxtFree(&lines2edges));
  HXT_CHECK(hxtFree(&edges2lines));

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to convert input directions from triagles to edges 
//
//  - INPUT is the array with direction frame (3 vectors) per triangle
//  - OUTPUT is the array with direction frame (3 vectors) per edge
//
//*****************************************************************************************
//*****************************************************************************************
// TODO don't recreate the edges, pass it as an argument 
HXTStatus hxtPointGenDirectionsTrianglesToEdges(HXTMesh *mesh, double *dirs, double *directions)
{

  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (t1 == UINT64_MAX){
      for (uint32_t j=0; j<9; j++) directions[9*i+j] = dirs[9*t0+j];
      continue;
    }

    for (uint32_t j=0; j<3; j++){
      double *dir0 = &dirs[9*t0+3*j];
      double dir1[3] = {0.};
      HXT_CHECK(getClosestDir(dir0,&dirs[9*t1],dir1));

      directions[9*i+3*j+0] = ( dir0[0] + dir1[0] ) / 2.;
      directions[9*i+3*j+1] = ( dir0[1] + dir1[1] ) / 2.;
      directions[9*i+3*j+2] = ( dir0[2] + dir1[2] ) / 2.;
      normalize(&directions[9*i+3*j]);
    }
  }

  HXT_CHECK(hxtEdgesDelete(&edges));

  return HXT_STATUS_OK;
}



//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to get sizes from input mesh
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenGetSizesInputMesh(HXTEdges *edges, double factor, double *sizemap)
{
  HXTMesh *mesh = edges->edg2mesh;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t n0 = edges->node[2*i+0];
    uint32_t n1 = edges->node[2*i+1];
    double *v0 = mesh->vertices.coord + 4*n0;
    double *v1 = mesh->vertices.coord + 4*n1;
    double length = distance(v0,v1);
    if (length < sizemap[n0]) sizemap[n0] = length;
    if (length < sizemap[n1]) sizemap[n1] = length;
  }

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    sizemap[i] *= factor;
  }

  HXT_CHECK(hxtEdgesDelete(&edges));

  return HXT_STATUS_OK; 
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to roughly compute sizes from curvature
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenGetSizesCurvature(HXTEdges *edges, int N, double a, double minSize, double *sizemap)
{
  HXTMesh *mesh = edges->edg2mesh;
  
  double *nodalCurvatures;
  double *curvatureCrossfield;

  HXT_CHECK(hxtCurvatureRusinkiewicz(mesh,&nodalCurvatures,&curvatureCrossfield,edges,1));

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    double *v1 = nodalCurvatures + 6*i;
    double *v2 = nodalCurvatures + 6*i + 3;

    double k1 = norm(v1);
    double k2 = norm(v2);

    double K = fmax(k1,k2);

    double size = (2*M_PI)/(N*K);
    if (sizemap[3*i+0] > a*size)
      sizemap[3*i+0] = a*size;
    if (sizemap[3*i+0] < minSize)
      sizemap[3*i+0] = minSize;
  }

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    sizemap[3*i+1] = sizemap[3*i+0];
    sizemap[3*i+2] = sizemap[3*i+0];
  }

  HXT_CHECK(hxtFree(&nodalCurvatures));
  HXT_CHECK(hxtFree(&curvatureCrossfield));


  return HXT_STATUS_OK; 
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION for a simple smoothing of sizemap
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenSizemapSmoothing(HXTEdges *edges, double factor, double *sizemap)
{
  HXTMesh *mesh = edges->edg2mesh;

  for (int k=0; k<0; k++){
   for (uint32_t i=0; i<edges->numEdges; i++){
     uint32_t v0 = edges->node[2*i+0];
     uint32_t v1 = edges->node[2*i+1];
     double *p0 = mesh->vertices.coord + 4*v0;
     double *p1 = mesh->vertices.coord + 4*v1;
     double dist = distance2(p0,p1);
     double s0 = sizemap[v0];
     double s1 = sizemap[v1];

     if (s0<s1){
       sizemap[v1] = factor*dist+s0;
     }
     else{
       sizemap[v0] = factor*dist+s1;
     }
   }
  }

  return HXT_STATUS_OK; 
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to generate a sizemap from a desired number of elements
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenSizemapFromNelements(HXTMesh *mesh, uint64_t nelem, double *sizemap)
{

  double integral = 0;

  for (uint64_t i=0; i<mesh->triangles.num; i++){

    uint32_t *nod = mesh->triangles.node + 3*i;
    
    double *v0 = mesh->vertices.coord + 4*nod[0];
    double *v1 = mesh->vertices.coord + 4*nod[1];
    double *v2 = mesh->vertices.coord + 4*nod[2];

    double area = hxtTriangleArea3D(v0,v1,v2);
    
    integral += area * 1. / pow(1./3. * (sizemap[nod[0]]+sizemap[nod[1]]+sizemap[nod[2]]),2.);
  }

  integral *= 2;

  double FAC = (double)nelem/integral;
  double sf  = 1 / sqrt(FAC);

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    sizemap[3*i+0] *= sf;
    sizemap[3*i+1] *= sf;
    sizemap[3*i+2] *= sf;
  }

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to get feature lines of input open surface mesh with no lines 
//
//  TODO attention, are they oriented?
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenOpenLines(HXTMesh *mesh)
{
  // Create edges structure
  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));

  printf(" INSIDE OPEN LINES FUNCTION \n");

  int countBoundaryLines = 0 ;
  for (uint32_t i=0; i<edges->numEdges; i++){
    if (edges->edg2tri[2*i+1] == UINT64_MAX)
      countBoundaryLines ++;
  }

  hxtLinesReserve(mesh,countBoundaryLines);

  for (uint32_t i=0; i<edges->numEdges; i++){
    if (edges->edg2tri[2*i+1] == UINT64_MAX){
      mesh->lines.colors[mesh->lines.num] = 0;
      mesh->lines.node[2*mesh->lines.num+0] = edges->node[2*i+0];
      mesh->lines.node[2*mesh->lines.num+1] = edges->node[2*i+1];
      mesh->lines.num++;
    }
  }


  HXT_CHECK(hxtEdgesDelete(&edges));

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to get feature lines of input mesh based on dihedral angle
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenClassifyDihedralLines(HXTMesh *mesh, HXTEdges *edges)
{

  // TODO clean write this function
  // reclassification of gmsh should have this functionality???

  FILE *fp;
  hxtPosInit("edges.pos","edges",&fp);

  FILE *fd;
  hxtPosInit("edgesnonmanifold.pos","edges",&fd);

  uint32_t numHardEdges = 0;
  double angleThreshold = 0.4;

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;
   
//    uint32_t *nodes_of_t1 = &mesh->triangles.node[3*t0];
//    uint32_t *nodes_of_t2 = &mesh->triangles.node[3*t1];

    double Nt1[3];
    HXT_CHECK(normal2triangle(mesh,t0,Nt1));

    double Nt2[3]; 
    HXT_CHECK(normal2triangle(mesh,t1,Nt2));

    double d = 0.;
    for (int i=0; i<3; i++)
      d += Nt1[i]*Nt2[i];

    if (fabs(d) < angleThreshold){
      double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
      double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
      hxtPosAddLine(fp,v0,v1,0);
      numHardEdges++;
      continue;
    }

    // NON-MANIFOLD EDGES
    int counter = 0;
    for (uint64_t k=0; k<mesh->triangles.num; k++){
      uint32_t e0 = edges->tri2edg[3*k+0];
      uint32_t e1 = edges->tri2edg[3*k+1];
      uint32_t e2 = edges->tri2edg[3*k+2];
      if (e0 == i || e1 == i || e2 == i){
        counter++;
      }
    }
    if (counter == 3){
      double *v0 = mesh->vertices.coord + 4*edges->node[2*i+0];
      double *v1 = mesh->vertices.coord + 4*edges->node[2*i+1];
      hxtPosAddLine(fd,v0,v1,0);
      numHardEdges++;
      continue;
    }

  }

  hxtPosFinish(fp);
  hxtPosFinish(fd);



  if (mesh->lines.num != 0){

    printf("ATTENTION !!! mesh does not have lines \n");
    printf("MESH DOES NOT HAVE LINES !!!!!!!!!!!!!!!!! \n");
    printf("Number of hard edges = %d \n", numHardEdges);

    printf("Mesh lines num %lu \n", mesh->lines.num);
    printf("Mesh lines size %lu \n", mesh->lines.size);

    hxtLinesReserve(mesh,numHardEdges);
    hxtPointsReserve(mesh,2*numHardEdges);

    for (uint32_t i=0; i<edges->numEdges; i++){
      uint64_t t0 = edges->edg2tri[2*i+0];
      uint64_t t1 = edges->edg2tri[2*i+1];

      if (mesh->triangles.colors[t0] != mesh->triangles.colors[t1]) continue;

//      uint32_t *nodes_of_t1 = &mesh->triangles.node[3*t0];
//      uint32_t *nodes_of_t2 = &mesh->triangles.node[3*t1];

      double Nt1[3]; 
      HXT_CHECK(normal2triangle(mesh,t0,Nt1));
      double Nt2[3]; 
      HXT_CHECK(normal2triangle(mesh,t1,Nt2));

      double d = 0.;
      for (int i=0; i<3; i++)
        d += Nt1[i]*Nt2[i];
      if (fabs(d) < angleThreshold){
        mesh->lines.colors[mesh->lines.num] = 0;
        mesh->lines.node[2*mesh->lines.num+0] = edges->node[2*i+0];
        mesh->lines.node[2*mesh->lines.num+1] = edges->node[2*i+1];
        mesh->lines.num++;

        mesh->points.node[mesh->points.num] = edges->node[2*i+0];
        mesh->points.node[mesh->points.num+1] = edges->node[2*i+1];
        mesh->points.num+=2;
        continue;
      }

      // NON-MANIFOLD EDGES
      int counter = 0;
      for (uint64_t k=0; k<mesh->triangles.num; k++){
        uint32_t e0 = edges->tri2edg[3*k+0];
        uint32_t e1 = edges->tri2edg[3*k+1];
        uint32_t e2 = edges->tri2edg[3*k+2];
        if (e0 == i || e1 == i || e2 == i) counter++;
      }
      if (counter == 4){
        mesh->lines.colors[mesh->lines.num] = 0;
        mesh->lines.node[2*mesh->lines.num+0] = edges->node[2*i+0];
        mesh->lines.node[2*mesh->lines.num+1] = edges->node[2*i+1];
        mesh->lines.num++;

        mesh->points.node[mesh->points.num] = edges->node[2*i+0];
        mesh->points.node[mesh->points.num+1] = edges->node[2*i+1];
        mesh->points.num+=2;
        continue;
      }
    }
    printf("Mesh lines num %lu \n", mesh->lines.num);
    printf("Mesh lines size %lu \n", mesh->lines.size);
  }


  return HXT_STATUS_OK;
}



//*****************************************************************************************
//*****************************************************************************************
// Associate mesh lines with edges 
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGetLinesToEdges(HXTEdges *edges, uint32_t *lines2edges)
{
  HXTMesh *mesh = edges->edg2mesh;
  for (uint64_t i=0; i<mesh->lines.num; i++){
    // Find corresponding edge for this line 
    uint32_t v0 = mesh->lines.node[2*i+0];
    uint32_t v1 = mesh->lines.node[2*i+1];
    int found = 0;
    for (uint32_t j=0; j<edges->numEdges; j++){
      uint32_t n0 = edges->node[2*j+0];
      uint32_t n1 = edges->node[2*j+1];
      if ( (v0 == n0 && v1 == n1) ||
           (v1 == n0 && v0 == n1)){
        found = 1;
        lines2edges[i] = j;
        break;
      }
    }

    // TODO remove this 
    double *vv0 = mesh->vertices.coord + 4*v0;
    double *vv1 = mesh->vertices.coord + 4*v1;
    double dist = distance(vv0,vv1);
    if (found == 0){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Edge not found for this line %d %d %f",v0,v1,dist);
    }
  }
  return HXT_STATUS_OK;
}

// Associate edges with mesh lines 
HXTStatus hxtGetEdgesToLines(HXTEdges *edges, uint32_t *lines2edges, uint64_t *edges2lines)
{
  HXTMesh *mesh = edges->edg2mesh;

  for (uint64_t i=0; i<mesh->lines.num; i++){
    edges2lines[lines2edges[i]] = i;
  }

  return HXT_STATUS_OK;
}

HXTStatus hxtCountMaxNumberOfTrianglesToEdges(HXTEdges *edges, uint64_t *maxNumTri)
{
  HXTMesh *mesh = edges->edg2mesh;

  uint64_t *counter;
  HXT_CHECK(hxtMalloc(&counter,edges->numEdges*sizeof(uint64_t)));
  for (uint32_t i=0; i<edges->numEdges; i++)  counter[i] = 0;

  uint64_t maxCount = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    counter[edges->tri2edg[3*i+0]]++;
    counter[edges->tri2edg[3*i+1]]++;
    counter[edges->tri2edg[3*i+2]]++;
    if (counter[edges->tri2edg[3*i+0]]>maxCount) maxCount = counter[edges->tri2edg[3*i+0]];
    if (counter[edges->tri2edg[3*i+1]]>maxCount) maxCount = counter[edges->tri2edg[3*i+1]];
    if (counter[edges->tri2edg[3*i+2]]>maxCount) maxCount = counter[edges->tri2edg[3*i+2]];
  }


    FILE *nm;
    hxtPosInit("checkNonManifold.pos","lines",&nm);
    for (uint32_t i=0; i<edges->numEdges; i++){
      if (counter[i]<=2) continue;
      uint32_t *v = edges->node + 2*i;
      hxtPosAddLine(nm,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],0);
    }
    hxtPosFinish(nm);
  
  *maxNumTri = maxCount;
  HXT_CHECK(hxtFree(&counter));
  return HXT_STATUS_OK;
}

HXTStatus hxtGetLinesToTriangles(HXTEdges *edges, uint64_t maxLT, uint64_t *edges2lines, uint64_t *lines2triangles)
{
  HXTMesh *mesh = edges->edg2mesh;

  for (uint64_t i=0; i<mesh->triangles.num; i++){
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];
      uint64_t cl = edges2lines[ce];
      if (cl == UINT64_MAX) continue;
      if (cl >= mesh->lines.num) return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Problem in edges2lines");

      int inserted = 0;
      for (uint64_t k=0; k<maxLT; k++){
        if (lines2triangles[maxLT*cl+k] == i){
          // triangle already exists
          inserted = 1;
          break; 
        }
        // Insert triangle
        if (lines2triangles[maxLT*cl+k] == UINT64_MAX){
            inserted = 1;
            lines2triangles[maxLT*cl+k] = i;
            break;
        }
      }
      if (inserted == 0) return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Could not insert triangle for line");
    }
  }

  return HXT_STATUS_OK; 
}

HXTStatus hxtCountMaxNumberOfLinesToVertices(HXTMesh *mesh, uint64_t *maxNumLines)
{
  uint8_t *countLines;
  HXT_CHECK(hxtMalloc(&countLines,mesh->vertices.num*sizeof(uint8_t)));
  for (uint64_t i=0; i<mesh->vertices.num; i++) countLines[i] = 0;

  uint64_t maxNumLinesToVertex = 0;
  for (uint64_t i=0; i<mesh->lines.num; i++){
    uint32_t v0 = mesh->lines.node[2*i+0];
    uint32_t v1 = mesh->lines.node[2*i+1];
    countLines[v0]++;
    countLines[v1]++;
    if (countLines[v0]>maxNumLinesToVertex) maxNumLinesToVertex = countLines[v0];
    if (countLines[v1]>maxNumLinesToVertex) maxNumLinesToVertex = countLines[v1];
  }
  *maxNumLines = maxNumLinesToVertex;
  HXT_CHECK(hxtFree(&countLines));
  return HXT_STATUS_OK;
}

HXTStatus hxtGetVerticesToLines(HXTMesh *mesh, uint64_t maxVL, uint64_t *vertices2lines)
{
  for (uint64_t i=0; i<mesh->lines.num; i++){
    for (uint32_t j=0; j<2; j++){
      uint32_t cv = mesh->lines.node[2*i+j];

      int inserted = 0;
      for (uint64_t k=0; k<maxVL; k++){
        if (vertices2lines[maxVL*cv+k] == i){
          // line already exists
          inserted = 1;
          break; 
        }
        // Insert line
        if (vertices2lines[maxVL*cv+k] == UINT64_MAX){
            inserted = 1;
            vertices2lines[maxVL*cv+k] = i;
            break;
        }
      }
      if (inserted == 0) return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Could not insert line for vertex");
    }
  }
  return HXT_STATUS_OK; 
}

HXTStatus hxtGetVerticesToTriangles(HXTMesh *mesh, uint64_t *vertices2triangles)
{
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    vertices2triangles[mesh->triangles.node[3*i+0]] = i;
    vertices2triangles[mesh->triangles.node[3*i+1]] = i;
    vertices2triangles[mesh->triangles.node[3*i+2]] = i;
  }
  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to associate the trianges of the surface 
//           with the boundary tetrahedra they belong to
//           Attention: there is also the case we have a triangulate surface
//                      inside the volume
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGetTrianglesToTetrahedra(HXTMesh *mesh, 
                                      uint64_t *tri2tet, 
                                      uint64_t *lines2tet)
{

  // Count all boundary tetrahedra
  uint64_t countBT = 0;
  for (uint64_t i=0; i< mesh->tetrahedra.num; i++){
    for (int j=0; j<4; j++){
      if (mesh->tetrahedra.neigh[4*i+j] == HXT_NO_ADJACENT){
        countBT++;
        break;
      }
      // Count as well tetrahedra that are on color changes
      uint64_t neigh = mesh->tetrahedra.neigh[4*i+j]/4;
      if (mesh->tetrahedra.colors[i] != mesh->tetrahedra.colors[neigh]){
        countBT++;
        break;
      }
    }
  }

  // Store boundary tetrahedra 
  uint64_t *boundaryTetrahedra;
  HXT_CHECK(hxtMalloc(&boundaryTetrahedra,countBT*sizeof(uint64_t)));
  countBT = 0;
  for (uint64_t i=0; i< mesh->tetrahedra.num; i++){
    for (int j=0; j<4; j++){
      uint64_t neigh = mesh->tetrahedra.neigh[4*i+j];
      if (neigh == HXT_NO_ADJACENT){
        boundaryTetrahedra[countBT] = i;
        countBT++;
        break;
      }
      neigh = neigh/4;
      if (mesh->tetrahedra.colors[i] != mesh->tetrahedra.colors[neigh]){
        boundaryTetrahedra[countBT] = i;
        countBT++;
        break;
      }
    }
  }

  // Associate triangles by searching boundary tetrahedra 
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t vtri[3] = {mesh->triangles.node[3*i+0], mesh->triangles.node[3*i+1], mesh->triangles.node[3*i+2]}; 
    int found = 0;
    for (uint64_t j=0; j<countBT; j++){
      uint64_t k = boundaryTetrahedra[j];
      uint32_t vtet[4] = {mesh->tetrahedra.node[4*k+0],
                          mesh->tetrahedra.node[4*k+1],
                          mesh->tetrahedra.node[4*k+2],
                          mesh->tetrahedra.node[4*k+3]};

      if (( vtri[0] == vtet[0] || vtri[0] == vtet[1] || vtri[0] == vtet[2] || vtri[0] == vtet[3]) &&
          ( vtri[1] == vtet[0] || vtri[1] == vtet[1] || vtri[1] == vtet[2] || vtri[1] == vtet[3]) &&
          ( vtri[2] == vtet[0] || vtri[2] == vtet[1] || vtri[2] == vtet[2] || vtri[2] == vtet[3])){
        tri2tet[i] = k;
        found = 1 ;
        break;
      }
    }
    // If a corresponding tetrahedron is not found on the list of boundary tetrahedron
    // we could have a case of triangulated surface inside the volume without 
    // a corresponding volume color change (should be rare)
    // In that case search all tetrahedra
    if (found == 0){
      for (uint64_t j=0; j<mesh->tetrahedra.num; j++){
        uint32_t vtet[4] = {mesh->tetrahedra.node[4*j+0],
                            mesh->tetrahedra.node[4*j+1],
                            mesh->tetrahedra.node[4*j+2],
                            mesh->tetrahedra.node[4*j+3]};

        if (( vtri[0] == vtet[0] || vtri[0] == vtet[1] || vtri[0] == vtet[2] || vtri[0] == vtet[3]) &&
            ( vtri[1] == vtet[0] || vtri[1] == vtet[1] || vtri[1] == vtet[2] || vtri[1] == vtet[3]) &&
            ( vtri[2] == vtet[0] || vtri[2] == vtet[1] || vtri[2] == vtet[2] || vtri[2] == vtet[3])){
          tri2tet[i] = j;
          found = 1 ;
          break;
        }
      }
    }
    // If we still didn't find a corresponding tetrahedron there is a problem
    if (found == 0)
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "did not found tetrahedron for boundary triangle");
  }

  // Associate lines by searching boundary tetrahedra 
  for (uint64_t i=0; i<mesh->lines.num; i++){
    uint32_t vline[2] = {mesh->lines.node[2*i+0], mesh->lines.node[2*i+1]}; 
    
    // We search triangles to find corresponding line
    int found = 0;
    for (uint64_t j=0; j<mesh->triangles.num; j++){
      uint32_t vtri[3] = {mesh->triangles.node[3*j+0],
                          mesh->triangles.node[3*j+1],
                          mesh->triangles.node[3*j+2]};

      if (( vline[0] == vtri[0] || vline[0] == vtri[1] || vline[0] == vtri[2] ) &&
          ( vline[1] == vtri[0] || vline[1] == vtri[1] || vline[1] == vtri[2] )){
          lines2tet[i] = tri2tet[j];
          found = 1;
          break;
      }
    }
    // If we still didn't find a corresponding tetrahedron there is a problem
    if (found == 0)
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "did not found tetrahedron for boundary line");
  }

  HXT_CHECK(hxtFree(&boundaryTetrahedra));

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION to associate the boundary tetrahedra with surface triangles
//           returns an array tet2tri of size 4*numBoundaryTetrahedra
//           TODO not used 
//           
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGetBoundaryTetrahedraToTriangles(HXTMesh *mesh,
                                              uint64_t **tet2tri)
{

  // First 4 positions are the corresponding triangles
  // Next  6 are the corresponding boundary lines 
  HXT_CHECK(hxtMalloc(tet2tri,sizeof(uint64_t)*mesh->tetrahedra.num*4));
  for (uint64_t i=0; i<4*mesh->tetrahedra.num; i++) (*tet2tri)[i] = UINT64_MAX;

  for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
    uint32_t *vtet = mesh->tetrahedra.node + 4*i;

    int ctri= 0;

    for (uint64_t j=0; j<mesh->triangles.num; j++){
      uint64_t tri = j;
      uint32_t *vtri = mesh->triangles.node + 3*j;
      
      int count = 0;
      for (uint32_t k=0; k<4; k++){
        for (uint32_t l=0; l<3; l++){
          if (vtet[k] == vtri[l]) count++;
        }
      }

      if (count >= 1){
        for (uint32_t l=0; l<4; l++){
          if ((*tet2tri)[4*i+l] != UINT64_MAX) continue;
          if ((*tet2tri)[4*i+l] == tri) break;
          (*tet2tri)[4*i+l] = tri;
          ctri++;
          if (ctri>3) printf("ERROR %lu %d \n", i, ctri);
          break;
        }
      }
    }
  }

  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
//  FUNCTION 
//
//    Get list of colors of triangles
//    listColors array with size numColors is allocated inside the function 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGetLinesColorsList(HXTMesh *mesh, uint16_t *numColors, uint16_t **listColors)
{
  if(mesh->lines.colors == NULL) return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Mesh lines do not have colors");

  uint16_t *tempList;
  HXT_CHECK(hxtMalloc(&tempList,mesh->lines.num*sizeof(uint16_t)));

  uint16_t count = 0;

  for (uint64_t i=0; i<mesh->lines.num; i++){
    uint16_t currentColor = mesh->lines.colors[i];
    int found = 1;
    for (uint16_t j=0; j<count; j++){
      if (currentColor == tempList[j]){
        found = 0;
        break;
      }
    }
    if (found == 1){
      tempList[count] = currentColor;
      count++;
    }
  }

  *numColors = count;
  HXT_CHECK(hxtMalloc(listColors,count*sizeof(uint16_t)));
  for (uint16_t i=0; i<count; i++) (*listColors)[i] = tempList[i];

  HXT_CHECK(hxtFree(&tempList));

  return HXT_STATUS_OK; 
}

// Get list of colors of triangles
// listColors array with size numColors is allocated inside the function 
HXTStatus hxtGetTrianglesColorsList(HXTMesh *mesh, uint16_t *numColors, uint16_t **listColors)
{
  if(mesh->triangles.colors == NULL) return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Mesh triangles do not have colors");

  uint16_t *tempList;
  HXT_CHECK(hxtMalloc(&tempList,mesh->triangles.num*sizeof(uint16_t)));

  uint16_t count = 0;

  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint16_t currentColor = mesh->triangles.colors[i];
    int found = 1;
    for (uint16_t j=0; j<count; j++){
      if (currentColor == tempList[j]){
        found = 0;
        break;
      }
    }
    if (found == 1){
      tempList[count] = currentColor;
      count++;
    }
  }

  *numColors = count;
  HXT_CHECK(hxtMalloc(listColors,count*sizeof(uint16_t)));
  for (uint16_t i=0; i<count; i++) (*listColors)[i] = tempList[i];

  HXT_CHECK(hxtFree(&tempList));

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to filter  
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtPointGenFilter(double *coords,
                            double *pp, // candidate point
                            double size,
                            double threshold,
                            void *data,
                            int *pass)
{
  double box = 2*size;
  double filter = pow(threshold*size,2.);

  double ppmin[3] = {pp[0] - box, pp[1] - box, pp[2] - box};
  double ppmax[3] = {pp[0] + box, pp[1] + box, pp[2] + box};
 
  int numClose = 0;
  int *idClose = NULL;
  HXT_CHECK(hxtRTreeSearch(ppmin,ppmax,&numClose,&idClose,data));

  if (numClose == 0){
    *pass = 1 ;
    return HXT_STATUS_OK;
  }

  for (int i=0; i<numClose; i++){
    double *cp = coords + 4*idClose[i]; 
    if (distance2(cp,pp)<filter){
      *pass = 0;
      HXT_CHECK(hxtFree(&idClose));
      return HXT_STATUS_OK; 
    }
  }

  HXT_CHECK(hxtFree(&idClose));
  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION 
//
// Given a triangle return if it is on boundary 
// i.e. if one of its edges is a boundary line
//
//*************************************************************************************************
//*************************************************************************************************

int hxtIsTriOnBoundary(HXTEdges *edges, uint64_t *edges2lines, uint64_t ct){

  int isBoundary = 0;
  for (uint64_t i=0; i<3; i++){
    uint32_t ce = edges->tri2edg[3*ct+i];
    if (edges2lines[ce] != UINT64_MAX) isBoundary = 1;
  }

  return isBoundary;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION 
//
// Given the edges structure,the number of the triangle and the 
// number (1,2 or 3) of edge, returns the corresponding # of neighboor triangle
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetNeighbourTriangle(HXTEdges *edges, uint64_t ct, uint32_t side, uint64_t *neigh)
{
  uint32_t ce = edges->tri2edg[3*ct+side];
  uint64_t ct0 = edges->edg2tri[2*ce+0];
  uint64_t ct1 = edges->edg2tri[2*ce+1];
  *neigh = (ct0 == ct) ? ct1: ct0 ;
  return HXT_STATUS_OK;
}




//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to create vertex cavity of triangles
//          returns the indices of triangles and the size 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtVertexCavity(HXTMesh *mesh,
                          HXTEdges *edges, 
                          uint32_t cv, 
                          uint64_t ct, 
                          uint64_t *cavSize, 
                          uint64_t *cavity)
{
  uint16_t color = mesh->triangles.colors[ct];
  if (color == UINT16_MAX) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Color in cavity is UINT16_MAX");

  uint64_t cavSizeTemp = 0;
  uint64_t fstart = ct;
  cavity[cavSizeTemp] = fstart;
  cavSizeTemp ++;
  uint64_t f = fstart;
  uint64_t g = (uint64_t)-1;
  while(1){
    int otherEdge = -1;
    if ( cv == mesh->triangles.node[3*f+0] ) otherEdge = 1;
    else if ( cv == mesh->triangles.node[3*f+1] ) otherEdge = 2;
    else if ( cv == mesh->triangles.node[3*f+2] ) otherEdge = 0;
    else return 
      HXT_ERROR_MSG(HXT_STATUS_FAILED, "Triangle %lu does not contain vertex %d", ct, cv );
    uint64_t f1;
    hxtGetNeighbourTriangle(edges,f,(otherEdge+1)%3,&f1);
    if (f1 != g){
      g = f;
      f = f1;
    }
    else{
      uint64_t f2;
      hxtGetNeighbourTriangle(edges,f,(otherEdge+2)%3,&f2);
      g = f;
      f = f2;
    }
    if (f == UINT64_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Could not close cavity for point %d", cv );
    if (f == fstart) break;
    if (mesh->triangles.colors[f] != color){
      // TODO delete or debug
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"FINALMESHdifferentcolor.msh"));
      FILE *dd;
      hxtPosInit("triangleDifferentColors.pos", "Point", &dd); 
      double *p = mesh->vertices.coord + 4*cv;
      hxtPosAddPoint(dd,p,0);
      for (uint64_t k=0; k<cavSizeTemp; k++){
        hxtPosNewView(dd,"Triangle %lu %lu %d", k, cavity[k], mesh->triangles.colors[cavity[k]]);
        uint64_t t = cavity[k];
        double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*t+0];
        double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*t+1];
        double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*t+2];
        hxtPosAddTriangle(dd,v0,v1,v2,mesh->triangles.colors[t]);
        hxtPosAddLine(dd,v0,v1,mesh->triangles.colors[t]);
        hxtPosAddLine(dd,v0,v2,mesh->triangles.colors[t]);
      }
      hxtPosFinish(dd);
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Triangle of different color in cavity %lu %d", ct,mesh->triangles.colors[f]);
    }
    cavity[cavSizeTemp] = f;
    cavSizeTemp ++;
    if (cavSizeTemp > 999){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"checkCavSize.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cavity size exceeded 1000 !!! for point %d",cv);
    }
  
  }
  *cavSize = cavSizeTemp;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to create boundary "half" vertex cavity of triangles for a color
//          returns the indices of triangles and the size 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtBoundaryVertexCavity(HXTMesh *mesh,
                                  HXTEdges *edges, 
                                  uint32_t cv, 
                                  uint64_t ct, 
                                  uint32_t ce,
                                  uint64_t *edges2lines,
                                  uint64_t *cavSize, 
                                  uint64_t *cavity)
{ 
  // Checking 
  // TODO delete or put in debug mode
  int edgeExist = 0;
  for (uint32_t i=0; i<3; i++)
    if (edges->tri2edg[3*ct+i] == ce) edgeExist = 1;
  if (edgeExist != 1) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Edge %d is not on triangle %lu",ce,ct);
  if (edges2lines[ce] == UINT64_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Current edge not a line (edges2lines)");

  uint16_t color = mesh->triangles.colors[ct];
  if (color == UINT16_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Color in cavity is UINT16_MAX");

  uint64_t cavSizeTemp = 0;
  *cavSize = 0;
  uint64_t fstart = ct;
  cavity[cavSizeTemp] = fstart;
  cavSizeTemp ++;
  uint64_t f = fstart;
  uint64_t g = (uint64_t)-1;
  uint32_t fe = ce;
  uint32_t ge = UINT32_MAX;
  while(1){
    int otherEdge = -1;
    for (uint32_t i=0; i<3; i++){
      ge = edges->tri2edg[3*f+i];
      if (ge == fe) continue;
      uint32_t v0 = edges->node[2*ge+0];
      uint32_t v1 = edges->node[2*ge+1];
      if (v0 == cv || v1 == cv){
        otherEdge = i;
        break;
      }
    }
    if (otherEdge == -1) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "OtherEdge not found");

    // If the other end is found 
    if (edges2lines[ge] != UINT64_MAX){
      //uint64_t tri0 = edges->edg2tri[2*ge+0];
      //uint64_t tri1 = edges->edg2tri[2*ge+1];
      //if (mesh->triangles.colors[tri0] == mesh->triangles.colors[tri1]) 
        //return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Adjacent triangles have same color");
      break; 
    }

    uint64_t f1;
    hxtGetNeighbourTriangle(edges,f,otherEdge,&f1);
    if (f1 != g){
      g = f;
      f = f1;
      fe = ge;
    }
    if (f == UINT64_MAX) break;
    if (mesh->triangles.colors[f] != mesh->triangles.colors[g]) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Problem in building vertex cavity");
    if (f == fstart) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Vertex is not on boundary");
    if (mesh->triangles.colors[f] != color)
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Triangle of different color in cavity");
    cavity[cavSizeTemp] = f;
    cavSizeTemp ++;
    if (cavSizeTemp > 999){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"checkCavSize.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cavity size exceeded 1000 !!! for point %d",cv);
    }
  }
  *cavSize = cavSizeTemp;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to create vertex cavity of edges
//          returns the indices of edges and the size 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtVertexCavityEdges(HXTMesh *mesh,
                               HXTEdges *edges, 
                               uint32_t cv, 
                               uint64_t ct, 
                               uint32_t *cavSize, 
                               uint32_t *cavity)
{
  uint32_t cavSizeTemp = 0;
  uint64_t fstart = ct;
  //cavity[cavSizeTemp] = fstart;
  //cavSizeTemp ++;
  uint64_t f = fstart;
  uint64_t g = (uint64_t)-1;

  while(1){
    int otherEdge = -1;
    if ( cv == mesh->triangles.node[3*f+0] ) otherEdge = 1;
    else if ( cv == mesh->triangles.node[3*f+1] ) otherEdge = 2;
    else if ( cv == mesh->triangles.node[3*f+2] ) otherEdge = 0;
    else return HXT_ERROR_MSG(HXT_STATUS_FAILED, "triangle does not contain vertex");
    uint64_t f1;
    hxtGetNeighbourTriangle(edges,f,(otherEdge+1)%3,&f1);
    if (f1 != g){
      cavity[cavSizeTemp] = edges->tri2edg[3*f+(otherEdge+1)%3];
      cavSizeTemp ++;
      g = f;
      f = f1;
    }
    else{
      uint64_t f2;
      hxtGetNeighbourTriangle(edges,f,(otherEdge+2)%3,&f2);
      cavity[cavSizeTemp] = edges->tri2edg[3*f+(otherEdge+2)%3];
      cavSizeTemp ++;
      g = f;
      f = f2;
    }
    if (f == (uint64_t)-1) printf("PROBLEM IN CAVITY\n");
    if (f == fstart) break;
    //cavity[cavSizeTemp] = f;
    //cavSizeTemp ++;
    if (cavSizeTemp > 999){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"checkCavSize.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cavity size exceeded 1000 !!! for point %d",cv);
    }
  }
  *cavSize = cavSizeTemp;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to create boundary "half" vertex cavity of edges for a color
//          returns the indices of edges and the size 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtBoundaryVertexCavityEdges(HXTMesh *mesh,
                                       HXTEdges *edges, 
                                       uint32_t cv, 
                                       uint64_t ct, 
                                       uint32_t ce,
                                       uint64_t *edges2lines,
                                       uint32_t *cavSize, 
                                       uint32_t *cavity)
{ 
  // Checking 
  // TODO delete or put in debug mode
  int edgeExist = 0;
  for (uint32_t i=0; i<3; i++){
    if (edges->tri2edg[3*ct+i] == ce) edgeExist = 1;
  }
  if (edgeExist != 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Edge is not on triangle");
  if (edges2lines[ce] == UINT64_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Current edge not a line");
  if (mesh->triangles.colors[edges->edg2tri[2*ce+0]] ==
      mesh->triangles.colors[edges->edg2tri[2*ce+1]]) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Current edge not a line");


  uint32_t cavSizeTemp = 0;
  uint64_t fstart = ct;
  cavity[cavSizeTemp] = ce;
  cavSizeTemp ++;
  uint64_t f = fstart;
  uint64_t g = (uint64_t)-1;
  uint32_t fe = ce;
  uint32_t ge = UINT32_MAX;
  while(1){
    int otherEdge = -1;
    for (uint32_t i=0; i<3; i++){
      ge = edges->tri2edg[3*f+i];
      if (ge == fe) continue;
      uint32_t v0 = edges->node[2*ge+0];
      uint32_t v1 = edges->node[2*ge+1];
      if (v0 == cv || v1 == cv){
        otherEdge = i;
        break;
      }
    }
    if (otherEdge == -1) return HXT_ERROR_MSG(HXT_STATUS_ERROR, "OtherEdge not found");
    // If the other end is found 
    if (edges2lines[ge] != UINT64_MAX){
      uint64_t tri0 = edges->edg2tri[2*ge+0];
      uint64_t tri1 = edges->edg2tri[2*ge+1];
      if (mesh->triangles.colors[tri0] == mesh->triangles.colors[tri1]) 
        return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Adjacent triangles have same color");
      cavity[cavSizeTemp] = ge;
      cavSizeTemp ++;
      break; 
    }

    uint64_t f1;
    hxtGetNeighbourTriangle(edges,f,otherEdge,&f1);
    if (f1 != g){
      g = f;
      f = f1;
      cavity[cavSizeTemp] = ge;
      cavSizeTemp ++;
      fe = ge;
    }
    if (f == UINT64_MAX) break;
    if (mesh->triangles.colors[f] != mesh->triangles.colors[g]) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Problem in building vertex cavity");
    if (f == fstart) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Vertex is not on boundary");
    //cavity[cavSizeTemp] = fe;
    //cavSizeTemp ++;
    if (cavSizeTemp > 999){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"checkCavSize.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cavity size exceeded 1000 !!! for point %d",cv);
    }
  }
  *cavSize = cavSizeTemp;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to create the perimeter edges of cavity of triangles
//          returns the indices of triangles and the size 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtVertexFanPerimeter(HXTMesh *mesh,
                                HXTEdges *edges, 
                                uint32_t cv, 
                                uint64_t ct, 
                                uint32_t *cavSize, 
                                uint32_t *cavity)
{
  uint16_t color = mesh->triangles.colors[ct];
  if (color == UINT16_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Color in cavity is UINT16_MAX");

  uint64_t cavSizeTemp = 0;
  uint64_t fstart = ct;
  //cavity[cavSizeTemp] = fstart;
  //cavSizeTemp ++;
  uint64_t f = fstart;
  uint64_t g = (uint64_t)-1;

  while(1){
    int otherEdge = -1;
    if      ( cv == mesh->triangles.node[3*f+0] ) otherEdge = 1;
    else if ( cv == mesh->triangles.node[3*f+1] ) otherEdge = 2;
    else if ( cv == mesh->triangles.node[3*f+2] ) otherEdge = 0;
    else return 
      HXT_ERROR_MSG(HXT_STATUS_FAILED, "Triangle %lu does not contain vertex %d", ct, cv );
    uint64_t f1;
    hxtGetNeighbourTriangle(edges,f,(otherEdge+1)%3,&f1);
    if (f1 != g){
      cavity[cavSizeTemp] = edges->tri2edg[3*f+otherEdge];
      cavSizeTemp++;
      g = f;
      f = f1;
    }
    else{
      uint64_t f2;
      hxtGetNeighbourTriangle(edges,f,(otherEdge+2)%3,&f2);
      cavity[cavSizeTemp] = edges->tri2edg[3*f+otherEdge];
      cavSizeTemp++;
      g = f;
      f = f2;
    }
    if (f == UINT64_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Could not close cavity for point %d", cv );
    if (f == fstart) break;
    if (mesh->triangles.colors[f] != color){
      // TODO delete or debug
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"FINALMESHdifferentcolor.msh"));
      FILE *dd;
      hxtPosInit("triangleDifferentColors.pos", "Point", &dd); 
      double *p = mesh->vertices.coord + 4*cv;
      hxtPosAddPoint(dd,p,0);
      for (uint64_t k=0; k<cavSizeTemp; k++){
        hxtPosNewView(dd,"Triangle %lu %lu %d", k, cavity[k], mesh->triangles.colors[cavity[k]]);
        uint64_t t = cavity[k];
        double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*t+0];
        double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*t+1];
        double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*t+2];
        hxtPosAddTriangle(dd,v0,v1,v2,mesh->triangles.colors[t]);
        hxtPosAddLine(dd,v0,v1,mesh->triangles.colors[t]);
        hxtPosAddLine(dd,v0,v2,mesh->triangles.colors[t]);
      }
      hxtPosFinish(dd);
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Triangle of different color in cavity %lu %d", ct,mesh->triangles.colors[f]);
    }
    //cavity[cavSizeTemp] = f;
    //cavSizeTemp ++;
    if (cavSizeTemp > 999){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"checkCavSize.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cavity size exceeded 1000 !!! for point %d",cv);
    }
  
  }
  *cavSize = cavSizeTemp;

  return HXT_STATUS_OK;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to get the perimeter edges of boundary "half" vertex cavity 
//          returns the indices of edges and the size 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtBoundaryVertexFanPerimeter(HXTMesh *mesh,
                                        HXTEdges *edges, 
                                        uint32_t cv, 
                                        uint64_t ct, 
                                        uint32_t ce,
                                        uint64_t *edges2lines,
                                        uint32_t *cavSize, 
                                        uint32_t *cavity)
{ 
  if (edges2lines[ce] == UINT64_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Current edge not a line");

  uint16_t color = mesh->triangles.colors[ct];
  if (color == UINT16_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Color in cavity is UINT16_MAX");

  uint32_t cavSizeTemp = 0;
  uint64_t fstart = ct;
  cavity[cavSizeTemp] = ce;
  cavSizeTemp ++;
  uint64_t f = fstart;
  uint64_t g = (uint64_t)-1;
  uint32_t fe = ce;
  uint32_t ge = UINT32_MAX;
  while(1){
    int otherEdge = -1;
    for (uint32_t i=0; i<3; i++){
      ge = edges->tri2edg[3*f+i];
      if (ge == fe) continue;
      uint32_t v0 = edges->node[2*ge+0];
      uint32_t v1 = edges->node[2*ge+1];
      if (v0 == cv || v1 == cv){
        otherEdge = i;
        break;
      }
    }
    if (otherEdge == -1) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "OtherEdge not found");



    // Save perimeter edge
    for (uint32_t i=0; i<3; i++){
      uint32_t te = edges->tri2edg[3*f+i];
      if (te == ge || te == fe ) continue;
      cavity[cavSizeTemp] = te;
      cavSizeTemp++;
    }

    // If the other end is boundary
    if (edges2lines[ge] != UINT64_MAX){
      cavity[cavSizeTemp] = ge;
      cavSizeTemp ++;
      break; 
    }

    // Next triangle
    uint64_t f1;
    hxtGetNeighbourTriangle(edges,f,otherEdge,&f1);
    if (f1 != g){
      g = f;
      f = f1;
      fe = ge;
    }
 
    if (f == UINT64_MAX) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Problem in building vertex cavity");
    if (mesh->triangles.colors[f] != mesh->triangles.colors[g]) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Problem in building vertex cavity");
    if (f == fstart) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Vertex is not on boundary");
    if (cavSizeTemp > 999){
      HXT_CHECK(hxtMeshWriteGmsh(mesh,"checkCavSize.msh"));
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Cavity size exceeded 1000 !!! for point %d",cv);
    }
  }
  *cavSize = cavSizeTemp;

  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtEstimateNumOfVerticesWithMesh(HXTMesh *mesh, const double *sizemap, uint32_t *estNumVertices)
{
  // Given a mesh and its sizemap, estimate the number of vertices to be generated
  // For now take the minimum size of sizemap
  // TODO change to a more elaborate estimation
  //      OR make a more moderate estimation (i.e. with average size) plus reallocs during insertion
  
  // Minimum mesh size 
  double minSize = sizemap[0];
  for (uint32_t i=1; i<mesh->vertices.num; i++){
    if (sizemap[i] < minSize) minSize = sizemap[i];
  }

  // Bounding box 
  HXTBbox bbox;
  hxtBboxInit(&bbox);
  hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);

  //double estVol = (bbox.max[0]-bbox.min[0])*(bbox.max[1]-bbox.min[1])*(bbox.max[2]-bbox.min[2]);
  //*estNumVertices = estVol/(minSize*minSize*minSize)+100;
  
  uint32_t pointsX = ceil((bbox.max[0]-bbox.min[0])/minSize) + 1;
  uint32_t pointsY = ceil((bbox.max[1]-bbox.min[1])/minSize) + 1;
  uint32_t pointsZ = ceil((bbox.max[2]-bbox.min[2])/minSize) + 1;

  *estNumVertices = pointsX*pointsY*pointsZ ;
  *estNumVertices += 0.5*(*estNumVertices);

  return HXT_STATUS_OK;
}

HXTStatus hxtEstimateNumOfVerticesWithPoints(double *coords,   
                                             double *sizemap, 
                                             uint32_t numPoints,
                                             uint32_t *estNumVertices)
{
  // Minimum mesh size 
  double minSize = sizemap[0];
  for (uint32_t i=1; i<numPoints; i++){
    if (sizemap[i] < minSize) minSize = sizemap[i];
  }

  // Bounding box 
  HXTBbox bbox;
  hxtBboxInit(&bbox);
  hxtBboxAdd(&bbox, coords, numPoints);

  //double estVol = (bbox.max[0]-bbox.min[0])*(bbox.max[1]-bbox.min[1])*(bbox.max[2]-bbox.min[2]);
  //*estNumVertices = estVol/(minSize*minSize*minSize)+100;
  
  uint32_t pointsX = ceil((bbox.max[0]-bbox.min[0])/minSize) + 1;
  uint32_t pointsY = ceil((bbox.max[1]-bbox.min[1])/minSize) + 1;
  uint32_t pointsZ = ceil((bbox.max[2]-bbox.min[2])/minSize) + 1;

  *estNumVertices = pointsX*pointsY*pointsZ ;
  *estNumVertices += 0.5*(*estNumVertices);


  return HXT_STATUS_OK;
}

HXTStatus hxtPointGenModelMaxLength(double *coords,   
                                    uint32_t numPoints,
                                    double *maxL)
{
  // Bounding box 
  HXTBbox bbox;
  hxtBboxInit(&bbox);
  hxtBboxAdd(&bbox, coords, numPoints);

  double lenX = bbox.max[0] - bbox.min[0];
  double lenY = bbox.max[1] - bbox.min[1];
  double lenZ = bbox.max[2] - bbox.min[2];

  *maxL = 0.0;
  if (lenX> lenY) *maxL = lenX;
  if (lenZ>*maxL) *maxL = lenZ;



  return HXT_STATUS_OK;
}
