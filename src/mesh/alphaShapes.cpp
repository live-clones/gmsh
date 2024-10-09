#include "GmshConfig.h"
#include <cwchar>
#ifdef HAVE_HXT
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
#include "alphaShapes.h"
#include "gmsh.h"
#include "Context.h"
#include "GmshMessage.h"
#include "SPoint3.h"
#include "meshOctreeLibOL.h"

#ifdef _OPENMP
#include "omp.h"
#endif

#include <time.h>
#include <ctime>
#include <chrono>
#include <iostream>
#include <unordered_set>
#include "robin_hood.h"
#include "BackgroundMeshTools.h"
#include "Field.h"
#include "SPoint3KDTree.h"

extern "C" {
#include "libol1.h"
}
extern "C" {
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetOpti.h"
#include "hxt_tetColor.h"
#include "hxt_tetFlag.h"
#include "hxt_tetRefine.h"
#include "hxt_alphashape.h"
}

using namespace AlphaShape;

/* verify if circumscribed radius is smaller than alpha threshold -- 3D */
double alphaShape (const size_t *t, const std::vector<double> &p, const double hMean){
  double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
			 double circumcenter[3], double *xi, double *eta,
			 double *zeta);
  double C[3], xi, eta, zeta;
  const double *x = &p[3*t[0]];
  const double *y = &p[3*t[1]];
  const double *z = &p[3*t[2]];
  const double *w = &p[3*t[3]];
  double a[3] = {x[0], x[1], x[2]};
  double b[3] = {y[0], y[1], y[2]};
  double c[3] = {z[0], z[1], z[2]};
  double d[3] = {w[0], w[1], w[2]};
  tetcircumcenter(a,b,c,d,C, &xi, &eta, &zeta);
  double R = sqrt ((x[0]-C[0])*(x[0]-C[0])+(x[1]-C[1])*(x[1]-C[1])+(x[2]-C[2])*(x[2]-C[2]));
  return R/hMean;
}

/* face ordering convention */
static int _faces [4][3] = {{0,1,2}, {0,1,3}, {0,2,3}, {1,2,3}};
// static int _outwardFaces [4][3] = {{0,2,1}, {0,1,3}, {0,3,2}, {1,2,3}};

/* order the tet faces according to convention */
void getOrderedFace (const size_t *t, int i, size_t *f){
  size_t no1 = t[_faces[i][0]];
  size_t no2 = t[_faces[i][1]];
  size_t no3 = t[_faces[i][2]];
  size_t lo, hi, sto;
  
  if (no1>no2) {   
      sto=no1;    
      lo=no2;   
   } else {
      sto=no2;  
      lo=no1;  
   } 
   if (sto>no3) { 
      hi=sto;    
      if(lo>no3){         
	sto=lo;                
	lo=no3;
      }else {
	sto=no3;      
      }         
   }else hi=no3; 
   
   f[0] = lo;
   f[1] = sto;
   f[2] = hi;
}

int compareFourInt (const void *a , const void *b){
  const size_t *f0 = (size_t*)a;
  const size_t *f1 = (size_t*)b;
  if (f0[0] < f1[0])return 1; 
  if (f0[0] > f1[0])return -1; 
  if (f0[1] < f1[1])return 1; 
  if (f0[1] > f1[1])return -1; 
  if (f0[2] < f1[2])return 1; 
  if (f0[2] > f1[2])return -1;
  return 0;
}

/* compute the neighbors of all tets, returned as a list of neighbors for each tet 
 * if a face is a boundary face, the value there is tetrahedra.size()
 */
int computeTetNeighbors_ (const std::vector<size_t> &tetrahedra, std::vector<size_t> &neigh){
  neigh.resize(tetrahedra.size());
  for (size_t i=0;i<neigh.size();i++)neigh[i] = tetrahedra.size();
  
  size_t *temp = new size_t [5*tetrahedra.size()];
  size_t counter = 0;
  for (size_t i = 0; i < tetrahedra.size(); i+=4){
    const size_t *t = &tetrahedra[i];
    for (int j=0;j<4;j++){
      size_t f[3];
      getOrderedFace ( t, j, f);
      temp[counter++] = f[0];
      temp[counter++] = f[1];
      temp[counter++] = f[2];
      temp[counter++] = i/4;      
      temp[counter++] = j;
    }
  }  

  qsort(temp, tetrahedra.size(), 5*sizeof(size_t),compareFourInt);

  // loop over faces
  counter  = 0;
  while (1){
    if (counter == tetrahedra.size())break;
    size_t *ft0 = &temp[5*(counter++)];
    if (counter == tetrahedra.size())break;
    size_t *ft1 = &temp[5*counter];
    if (compareFourInt(ft0,ft1) == 0){
      neigh[4*ft0[3]+ft0[4]] = 4*ft1[3]+ ft1[4];
      neigh[4*ft1[3]+ft1[4]] = 4*ft0[3]+ ft0[4];
      counter++;
    }
  }

  delete [] temp;  
  return 0;
}

void generateMesh3D_(const std::vector<double>& coord, const std::vector<size_t>& nodeTags){
  GModel *m = GModel::current();
  
  /* initialize hxt mesh */
  HXTMesh *mesh;
  hxtMeshCreate(&mesh);

  /* set the gmsh surface mesh to hxt format */
  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  std::set<GRegion *, GEntityPtrLessThan> rs;
  rs = m->getRegions();
  std::vector<GRegion *> regions(rs.begin(), rs.end());
  std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
  Gmsh2HxtAlpha(regions, mesh, v2c, c2v);

  // all other fields of the options will be 0 or NULL (standard C behavior)
  HXTTetMeshOptions options = {};
  options.defaultThreads = 1;
  options.verbosity=2;
  options.stat=1;

	// create the empty mesh
	hxtTetMesh(mesh, &options);

  uint32_t nBndPts = mesh->vertices.num;

  // create the bounding box of the mesh
	HXTBbox bbox;
	hxtBboxInit(&bbox);
	hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);

  uint32_t numNewPts = coord.size()/3;
  std::vector<HXTNodeInfo> nodeInfo(numNewPts);

  /* add the internal nodes to the mesh */
  mesh->vertices.num += numNewPts;
	if (mesh->vertices.num > mesh->vertices.size) {
		hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double) * mesh->vertices.num * 4);
		mesh->vertices.size = mesh->vertices.num;
	}
  for (size_t p = 0; p < numNewPts; p++) {
    uint32_t nodeIndex = p + nBndPts;
    for (int dim = 0; dim < 3; dim++) {
      mesh->vertices.coord[4 * nodeIndex + dim] = coord[3*p+dim];
    }
    nodeInfo[p].node = nodeIndex;
    nodeInfo[p].status = HXT_STATUS_TRYAGAIN; // state that we want to insert this point
  }

  HXTDelaunayOptions delOptions = {};
  delOptions.bbox = &bbox;
  delOptions.numVerticesInMesh = nBndPts;
  delOptions.insertionFirst = nBndPts;
  delOptions.verbosity = 2;

  /* Generate the tet mesh */
  hxtDelaunaySteadyVertices(mesh, &delOptions, &nodeInfo[0], numNewPts);

  Hxt2GmshAlpha(regions, mesh, v2c, c2v);

  /* reset the vertex indices */
  for (size_t i=nBndPts; i<mesh->vertices.num; i++){
    MVertex* oldv = c2v[i];
    if(nodeTags.size()){
      oldv->forceNum(nodeTags[i-nBndPts]);
    }
  }

  hxtMeshDelete(&mesh);
}


HXTStatus gmsh2hxtCallback (double *coord, uint32_t* volume, size_t n, void* userData){
  auto cbGmsh = (std::function<double(int, int, double, double, double, double)>*)userData;
  for (size_t i=0; i<n; i++){
    double s = (*cbGmsh)(3, volume[i], coord[4*i+0], coord[4*i+1], coord[4*i+2], 0.);
    coord[4*i+3] = s;
  }
  return HXT_STATUS_OK;
}

double qualityFunForOptimize(double* p0, double* p1, double* p2, double* p3, void* qualityData){
  // compute cicrumradius
  double C[3], xi, eta, zeta;
  double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
			 double circumcenter[3], double *xi, double *eta, double *zeta);
  tetcircumcenter(p0,p1,p2,p3,C, &xi, &eta, &zeta);
  double R = sqrt ((p0[0]-C[0])*(p0[0]-C[0])+(p0[1]-C[1])*(p0[1]-C[1])+(p0[2]-C[2])*(p0[2]-C[2]));
  // compute alpha shape value
  auto cbGmsh = (std::function<double(int, int, double, double, double, double)>*)qualityData;
  double s0 = (*cbGmsh)(3, -1, p0[0], p0[1], p0[2], 0.);
  double s1 = (*cbGmsh)(3, -1, p1[0], p1[1], p1[2], 0.);
  double s2 = (*cbGmsh)(3, -1, p2[0], p2[1], p2[2], 0.);
  double s3 = (*cbGmsh)(3, -1, p3[0], p3[1], p3[2], 0.);
  double hMean = (s0+s1+s2+s3)/4.;
  return hMean/R;
}

void AlphaShape::_computeAlphaShape3D(const std::vector<int> & alphaShapeTags, const double alpha, const double hMean,
                        std::function<double(int, int, double, double, double, double)> sizeFieldCallback, 
                        const int triangulate, const int refine){
  
  auto t0 = std::chrono::steady_clock::now(); 
  auto t1 = std::chrono::steady_clock::now(); 
  auto t2 = std::chrono::steady_clock::now(); 
  auto t3 = std::chrono::steady_clock::now(); 
  auto t4 = std::chrono::steady_clock::now(); 
  auto t5 = std::chrono::steady_clock::now(); 
  auto t6 = std::chrono::steady_clock::now(); 
  auto t7 = std::chrono::steady_clock::now(); 

  GRegion* gr = GModel::current()->getRegionByTag(alphaShapeTags[0]);
  size_t nNodesInMesh = gr->mesh_vertices.size();
  std::vector<double> coordsInMesh(3*nNodesInMesh);
  std::vector<size_t> nodeTagsInMesh(nNodesInMesh);
  size_t maxNode = 0;
  for (size_t i=0; i<nNodesInMesh; i++){
    MVertex* v = gr->mesh_vertices[i];
    coordsInMesh[3*i+0] = v->x();
    coordsInMesh[3*i+1] = v->y();
    coordsInMesh[3*i+2] = v->z();
    nodeTagsInMesh[i] = v->getNum();
    maxNode = std::max(maxNode, nodeTagsInMesh[i]);
  }

  /* initialize hxt mesh */
  HXTMesh *mesh;
  hxtMeshCreate(&mesh);
  HXTTetMeshOptions options = {};
  // options.defaultThreads = 2;
  options.verbosity=2;
  options.stat=1;

  mesh->vertices.num += nNodesInMesh;
  hxtAlignedRealloc(&mesh->vertices.coord, sizeof(double) * mesh->vertices.num * 4);
  mesh->vertices.size = mesh->vertices.num;
  for (size_t p = 0; p < nNodesInMesh; p++) {
    uint32_t nodeIndex = p;
    for (int dim = 0; dim < 3; dim++) {
      mesh->vertices.coord[4 * nodeIndex + dim] = coordsInMesh[3*p+dim];
    }
  }
  
  // create the bounding box of the mesh
	HXTBbox bbox;
	hxtBboxInit(&bbox);
	hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);
  double center[3] = {(bbox.min[0]+bbox.max[0])*.5, (bbox.min[1]+bbox.max[1])*.5, (bbox.min[2]+bbox.max[2])*.5};
  double scale = 1.1;
  for (size_t i=0; i<3; i++){
    bbox.min[i] = center[i] + (bbox.min[i] - center[i])*scale;
    bbox.max[i] = center[i] + (bbox.max[i] - center[i])*scale;
  }

  HXTDelaunayOptions delOptions = {};
  delOptions.bbox = &bbox;
  delOptions.numVerticesInMesh = 0;
  delOptions.insertionFirst = 0;
  delOptions.verbosity = 2;
  delOptions.allowOuterInsertion = 0;

  t1 = std::chrono::steady_clock::now(); 

  /* Generate the tet mesh */
  hxtDelaunay(mesh, &delOptions);
  printf("initial delaunay done \n");
  mesh->tetrahedra.color = (uint32_t*) malloc(sizeof(uint32_t) * mesh->tetrahedra.num);

  
  t2 = std::chrono::steady_clock::now(); 
  
  HXTNodalSizes nodalSizes = {
      .array = NULL,
      .callback = gmsh2hxtCallback, 
      .userData = (void*)&sizeFieldCallback,
      // .callback = NULL, 
      // .userData = NULL,
      // .min = .2*.04, 
      // .max = ,  
      .factor = 1.,
      .enabled = 0  // only enabled for the refine step
  };
  hxtNodalSizesInit(mesh, &nodalSizes);
  
  double nodalSizeMin = 1e10;
  double nodalSizeMax = 0.;
  for (size_t i=0; i<mesh->vertices.num; i++){
    nodalSizes.array[i] = sizeFieldCallback(3, nodeTagsInMesh[i], mesh->vertices.coord[4*i+0], mesh->vertices.coord[4*i+1], mesh->vertices.coord[4*i+2], 0.);
    nodalSizeMin = std::min(nodalSizeMin, nodalSizes.array[i]);
    nodalSizeMax = std::max(nodalSizeMax, nodalSizes.array[i]);
  }
  nodalSizes.min = nodalSizeMin;
  nodalSizes.max = nodalSizeMax;
  delOptions.nodalSizes = &nodalSizes;
  printf("nodal sizes initialized \n");

  HXTAlphaShapeOptions alphaShapeOptions = {
      .colorIn = static_cast<uint32_t>(alphaShapeTags[0]),
      .colorOut = 1,
      .colorBoundary = static_cast<uint32_t>(alphaShapeTags[1]),
      .alpha = alpha,
      .hMean = hMean,
      .minQuality = .1, // TO CHECK !!!!!!!!!!!
      .minRadius = nodalSizeMin,
      .n_tetrahedra = 0,
      .tetrahedra = NULL,
      .n_boundaryFacets = 0,
      .boundaryFacets = NULL,    
  };
  
  // hxtMeshWriteGmsh(mesh, "convexHullMesh.msh");
  hxtAlphaShape(mesh, &delOptions, &alphaShapeOptions);
  printf("alpha shape done \n");

  t3 = std::chrono::steady_clock::now(); 


  if (alphaShapeOptions.n_tetrahedra == 0){
    HXT_ERROR_MSG(HXT_STATUS_FAILED, "No tetrahedra in alpha shape, exiting \n");
    return;
  }
  // Add alpha shape facets into the mesh
  mesh->triangles.num = alphaShapeOptions.n_boundaryFacets;
  if (mesh->triangles.num != mesh->triangles.size){
    hxtAlignedRealloc(&mesh->triangles.node, sizeof(uint32_t) * mesh->triangles.num * 3);
    hxtAlignedRealloc(&mesh->triangles.color, sizeof(uint32_t) * mesh->triangles.num);
    mesh->triangles.size = mesh->triangles.num;
  }
  for (u_int32_t i=0; i<alphaShapeOptions.n_boundaryFacets; i++){
    mesh->triangles.node[3*i+0] = alphaShapeOptions.boundaryFacets[3*i+0];
    mesh->triangles.node[3*i+1] = alphaShapeOptions.boundaryFacets[3*i+1];
    mesh->triangles.node[3*i+2] = alphaShapeOptions.boundaryFacets[3*i+2];
    mesh->triangles.color[i] = alphaShapeOptions.colorBoundary;
  }
  hxtMeshWriteGmsh(mesh, "alphaShape0Mesh.msh");
  if (refine == 1){

    hxtRefineSurfaceTriangulation(&mesh, &delOptions, &alphaShapeOptions);

    printf("done with surface triangulation refinement\n");
    
    // hxtMeshWriteGmsh(mesh, "afterSurfaceRefinement.msh");
    
    
    delOptions.nodalSizes->enabled = 1;
    delOptions.allowOuterInsertion = 0;
    
    
    // hxtAlphaShapeNodeInsertion(mesh, &delOptions, &alphaShapeOptions);

    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(mesh->tetrahedra.color[i]!=alphaShapeOptions.colorIn) {
        setProcessedFlag(mesh, i);
      }
      else {
        unsetProcessedFlag(mesh, i);
      }
    }
    t4 = std::chrono::steady_clock::now(); 
    hxtRefineTetrahedra(mesh, &delOptions);
    t5 = std::chrono::steady_clock::now(); 
    
    hxtMeshWriteGmsh(mesh, "afterNodeInsertion.msh");
    // printf("wrote mesh after node insertion\n");
    HXTOptimizeOptions optOptions = {
      .bbox = &bbox, 
      .qualityFun = NULL,
      // .qualityFun = qualityFunForOptimize,
      .qualityData = NULL,
      // .qualityData = (void*)&sizeFieldCallback,
      .qualityMin = .1,
      .numVerticesConstrained = mesh->vertices.num,
      .verbosity = 2,
      .reproducible = 0
    };
    #pragma omp parallel for
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(mesh->tetrahedra.color[i]!=alphaShapeOptions.colorIn) {
        setProcessedFlag(mesh, i);
      }
      else {
        unsetProcessedFlag(mesh, i);
      }
    }
    hxtOptimizeTetrahedra(mesh, &optOptions);
    t6 = std::chrono::steady_clock::now(); 
    // hxtMeshWriteGmsh(mesh, "afterOptimisation.msh");
    // printf("wrote mesh after second alpha shape\n");
  }
  else {
    // create a mesh with only the elements in the alpha shape
    for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
      if (mesh->tetrahedra.color[i] != alphaShapeOptions.colorIn){
        mesh->tetrahedra.color[i] = HXT_COLOR_OUT;
      }
    }
  }

  gmsh::vectorpair atags3D;
  atags3D.push_back(std::make_pair(3, alphaShapeTags[0]));
  gmsh::model::mesh::clear(atags3D);
  gmsh::vectorpair atags2D;
  atags2D.push_back(std::make_pair(2, alphaShapeTags[1]));
  gmsh::model::mesh::clear(atags2D);

  std::vector<size_t> nodeTags(mesh->vertices.num);
  std::vector<double> coords(3*mesh->vertices.num);
  size_t nNodes = 0;
  robin_hood::unordered_map<size_t, size_t> i2g;
  
  std::vector<size_t> alphaTriTags, alphaTriNodeTags, alphaTetTags, alphaTetNodeTags;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    alphaTriTags.push_back(i+1);
    for (int j=0; j<3; j++){
      size_t nodeIndex = mesh->triangles.node[3*i+j];
      auto it = i2g.find(nodeIndex);
      if (it == i2g.end()){
        coords[3*nNodes+0] = mesh->vertices.coord[4*nodeIndex+0];
        coords[3*nNodes+1] = mesh->vertices.coord[4*nodeIndex+1];
        coords[3*nNodes+2] = mesh->vertices.coord[4*nodeIndex+2];
        if (nodeIndex < nNodesInMesh) nodeTags[nNodes] = nodeTagsInMesh[nodeIndex];
        else nodeTags[nNodes] = ++maxNode;
        i2g[nodeIndex] = nodeTags[nNodes];
        alphaTriNodeTags.push_back(nodeTags[nNodes]);
        nNodes++;
      }
      else 
        alphaTriNodeTags.push_back(it->second);
    }
  }
  // for (int i=0; i<alphaShapeOptions.n_tetrahedra; i++){
  size_t tetTag = 1;
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++){
    uint32_t myColor = mesh->tetrahedra.color[i];
    if (myColor == HXT_COLOR_OUT) continue;
    alphaTetTags.push_back(tetTag++);
    // uint64_t tetIndex = alphaShapeOptions.tetrahedra[i];
    uint64_t tetIndex = i;
    for (int j=0; j<4; j++){
      size_t nodeIndex = mesh->tetrahedra.node[4*tetIndex+j];
      auto it = i2g.find(nodeIndex);
      if (it == i2g.end()){
        coords[3*nNodes+0] = mesh->vertices.coord[4*nodeIndex+0];
        coords[3*nNodes+1] = mesh->vertices.coord[4*nodeIndex+1];
        coords[3*nNodes+2] = mesh->vertices.coord[4*nodeIndex+2];
        if (nodeIndex < nNodesInMesh) nodeTags[nNodes] = nodeTagsInMesh[nodeIndex];
        else nodeTags[nNodes] = ++maxNode;
        i2g[nodeIndex] = nodeTags[nNodes];
        alphaTetNodeTags.push_back(nodeTags[nNodes]);
        nNodes++;
      }
      else 
        alphaTetNodeTags.push_back(it->second);
    }
  }
  
  nodeTags.resize(nNodes);
  coords.resize(3*nNodes);
  gmsh::model::mesh::addNodes(3, alphaShapeTags[0], nodeTags, coords);
  gmsh::model::mesh::addElementsByType(alphaShapeTags[1], 2, alphaTriTags, alphaTriNodeTags);
  gmsh::model::mesh::addElementsByType(alphaShapeTags[0],  4, alphaTetTags, alphaTetNodeTags);
  hxtMeshDelete(&mesh);
  t7 = std::chrono::steady_clock::now(); 
  
  auto dur1 = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
  auto dur2 = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1);
  auto dur3 = std::chrono::duration_cast<std::chrono::milliseconds>(t3-t2);
  auto dur4 = std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3);
  auto dur5 = std::chrono::duration_cast<std::chrono::milliseconds>(t5-t4);
  auto dur6 = std::chrono::duration_cast<std::chrono::milliseconds>(t6-t5);
  auto dur7 = std::chrono::duration_cast<std::chrono::milliseconds>(t7-t6);
  auto durTotal = std::chrono::duration_cast<std::chrono::milliseconds>(t7-t0);
  printf("initial      time : %f percent \n", 100*double(dur1.count())/double(durTotal.count()) );
  printf("delaunay     time : %f percent \n", 100*double(dur2.count())/double(durTotal.count()) );
  printf("alpha shape  time : %f percent \n", 100*double(dur3.count())/double(durTotal.count()) );
  printf("surface ref  time : %f percent \n", 100*double(dur4.count())/double(durTotal.count()) );
  printf("volume ref   time : %f percent \n", 100*double(dur5.count())/double(durTotal.count()) );
  printf("optimize     time : %f percent \n", 100*double(dur6.count())/double(durTotal.count()) );
  printf("finalize     time : %f percent \n", 100*double(dur7.count())/double(durTotal.count()) ); 
}

static void faceCircumCenter(PolyMesh::HalfEdge *he, double *res, double* R)
{
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  double q0[3] = {v0->position.x(), v0->position.y(), v0->position.z()};
  double q1[3] = {v1->position.x(), v1->position.y(), v1->position.z()};
  double q2[3] = {v2->position.x(), v2->position.y(), v2->position.z()};
  circumCenterXYZ(q0, q1, q2, res, NULL);
  double v[3] = {q0[0] - res[0], q0[1] - res[1], q0[2] - res[2]};
  *R = norm3(v);
}

// void print4debug(PolyMesh* pm, const int debugTag, std::unordered_map<int, double> &sizeAtNodes)
void print4debug(PolyMesh* pm, const int debugTag)
  {
    char name[256];
    sprintf(name, "polyMesh%d.pos", debugTag);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \" %s \"{\n", name);
    for(auto it : pm->faces) {
      // if (it->data == -2) continue;
      // if (it->he && (it->he->v->data == -1 || it->he->next->v->data == -1 || it->he->next->next->v->data == -1)) continue;
      if (it->he){
        
        PolyMesh::HalfEdge *he0 = it->he;
        PolyMesh::HalfEdge *he1 = it->he->next;
        PolyMesh::HalfEdge *he2 = it->he->next->next;
        // double cy[3], Ry;
        // double s[3];
        // if (sizeAtNodes != NULL){
          // double s0, s1, s2;
          // if (it->data < 0){
          //   s0 = 0.;
          //   s1 = 0.;
          //   s2 = 0.;
          // }
          // else {
          //   s0 = sizeAtNodes[he0->v->data];
          //   s1 = sizeAtNodes[he1->v->data];
          //   s2 = sizeAtNodes[he2->v->data];
          // }
          // fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%f,%f,%f};\n",
          //         he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
          //         he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
          //         s0, s1, s2);
        // }
        // else {
        // }
        fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%d,%d,%d};\n",
                he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
                he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
                it->data, it->data, it->data);
      }
        // else faceCircumCenter(it->he, cy, &Ry);
      //   fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%f,%f,%f};\n",
      //           he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
      //           he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
      //           Ry, Ry, Ry);
      // }
    }
    for(auto it : pm->hedges) {
      PolyMesh::HalfEdge *he = it;
      if(he->opposite && he->f) {
        fprintf(f, "SL(%g,%g,0,%g,%g,0){%d,%d};\n", he->v->position.x(),
                he->v->position.y(), he->opposite->v->position.x(),
                he->opposite->v->position.y(), he->data, he->data);
      }
      else if (he->f) {
        fprintf(f, "SL(%g,%g,0,%g,%g,0){%d,%d};\n", he->v->position.x(),
                he->v->position.y(), he->next->v->position.x(),
                he->next->v->position.y(), he->data, he->data);
      }
    }
    for (auto v : pm->vertices){
      fprintf(f, "SP(%g,%g,0){%d};\n", v->position.x(), v->position.y(), v->data);
    }

    fprintf(f, "};\n");
    fclose(f);
    printf("wrote mesh polyMesh%d.pos\n", debugTag);
  }

static void faceInfo(PolyMesh::HalfEdge *he, double *x_center, double *R, double *quality){
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  double q0[3] = {v0->position.x(), v0->position.y(), v0->position.z()};
  double q1[3] = {v1->position.x(), v1->position.y(), v1->position.z()};
  double q2[3] = {v2->position.x(), v2->position.y(), v2->position.z()};
  circumCenterXYZ(q0, q1, q2, x_center);
  double v[3] = {q0[0] - x_center[0], q0[1] - x_center[1], q0[2] - x_center[2]};
  *R = norm3(v);
  *quality = qmTriangle::gamma(q0[0], q0[1], q0[2], q1[0], q1[1], q1[2],
                               q2[0], q2[1], q2[2]);
}

struct he_size
{
  inline bool operator() (PolyMesh::HalfEdge* he0, PolyMesh::HalfEdge* he1)
  {
    double d0 = norm(he0->v->position - he0->next->v->position);
    double d1 = norm(he1->v->position - he1->next->v->position);
    return (d0 < d1);
  }
};

void getVerticesWithinRadius(PolyMesh* pm, PolyMesh::Vertex* v, double R, std::vector<PolyMesh::Vertex*> * closeVertices){
  // Neighbor to neighbor walk to check if nodes are within a distance R of v.
  std::vector<PolyMesh::Vertex*> _temp;
  std::vector<PolyMesh::Vertex*> _currNeighbors;
  std::vector<PolyMesh::Vertex*> close;
  SVector3 vPos = v->position;
  pm->vertexNeighbors(v, &_currNeighbors);
  for (auto vv : _currNeighbors) _temp.push_back(vv);
  while (!_temp.empty()){
    PolyMesh::Vertex* vtest = *_temp.begin();
    _temp.erase(_temp.begin());
    SVector3 vect = vtest->position - vPos;
    double dist = vect.norm();
    if (dist < R){
      close.push_back(vtest);
      pm->vertexNeighbors(vtest, &_currNeighbors);
      for (auto vv : _currNeighbors){
        if(vv != v &&
            std::find(close.begin(), close.end(), vv) == close.end() &&
            std::find(_temp.begin(), _temp.end(), vv) == _temp.end() )
            _temp.push_back(vv);
      }
    }
  }
  *closeVertices = close;
}
 
bool faceCompareFct(const void *a , const void *b){
  PolyMesh::Face *f0 = (PolyMesh::Face*) a;
  PolyMesh::Face *f1 = (PolyMesh::Face*) b;
  double R0, R1, cc[3];
  faceCircumCenter(f0->he, cc, &R0);
  faceCircumCenter(f1->he, cc, &R1);
  return R0 < R1;
}

bool heCompare(const void *a , const void *b){
  PolyMesh::HalfEdge *he0 = (PolyMesh::HalfEdge*) a;
  PolyMesh::HalfEdge *he1 = (PolyMesh::HalfEdge*) b;
  double l0 = norm(he0->v->position - he0->next->v->position);
  double l1 = norm(he1->v->position - he1->next->v->position);
  return l0 > l1;
}

template< typename T > typename std::vector<T>::iterator insert_sorted( std::vector<T> & vec, T const& item, bool (*compareFct)(const void *a , const void *b)){
    return vec.insert ( std::upper_bound( vec.begin(), vec.end(), item, compareFct), item );
}

static int delaunayCriterion(PolyMesh::HalfEdge *he, void* val)
{
  // if(he->f == nullptr) return -1;
  // if(he->opposite == nullptr) return -1;
  if(he->opposite == nullptr) return -1;
  if (val != nullptr){
    int bndTag = *(int*)val;
    if(he->data == bndTag) return 0;
    if(he->opposite->data == bndTag) return 0;
  }
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;
  // FIXME : should be oriented anyway !
  double result = robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);
  return (result > 0) ? 1 : 0;
}

inline int _deleteVertex(PolyMesh* pm, PolyMesh::Vertex *v, std::vector<PolyMesh::HalfEdge *> *_t = NULL)
  {
    std::vector<PolyMesh::HalfEdge *> _touched;
    if(pm->degree(v) == 3) {
      PolyMesh::HalfEdge *he = v->he;
      PolyMesh::HalfEdge *he0 = he->next;
      PolyMesh::HalfEdge *he1 = he0->next->opposite->next;
      PolyMesh::HalfEdge *he2 = he1->next->opposite->next;
      PolyMesh::Vertex *v0 = he0->v;
      PolyMesh::Vertex *v1 = he1->v;
      PolyMesh::Vertex *v2 = he2->v;
      do {
        he->f = nullptr;
        he->opposite->f = nullptr;
        he = he->next->next->opposite;
      } while(he != v->he);
      he0->next = he1;
      he1->next = he2;
      he2->next = he0;
      he1->f->he = nullptr; // to turn these faces off
      he2->f->he = nullptr; // to turn these faces off
      v->he = nullptr;
      he1->f = he0->f;
      he2->f = he0->f;
      pm->createFace(he0->f, v0, v1, v2, he0, he1, he2);
      if(_t) {
        // for(auto he : *_t) (*_t).push_back(he);
        (*_t).push_back(he0);
        (*_t).push_back(he1);
        (*_t).push_back(he2);
      }

    }
    else {
      PolyMesh::HalfEdge *he = v->he;
      bool deletion_accepted = false;
      bool corner = false;
      while(!deletion_accepted && !corner) {
        if(he->data != -1) return -1;
        PolyMesh::HalfEdge *_he = he->next->next->opposite;
        PolyMesh::Vertex *v0 = he->next->v;
        bool flipped = false;
        if(!_he) corner = true;
        while(!flipped && _he != he && !corner) {
          PolyMesh::Vertex *v1 = _he->next->v;
          PolyMesh::Vertex *v2 = _he->next->next->v;
          double s = robustPredicates::orient2d(v0->position, v1->position,
                                                v2->position);
          if(s < 0) flipped = true;
          _he = _he->next->next->opposite;
          if(_he == nullptr) corner = true;
        }
        if(flipped) { he = he->next->next->opposite; }
        else if(!flipped && !corner) {
          // we found a good edge! we can adapt the big mesh
          _he = he->next->next->opposite;
          while(pm->degree(v) > 3) {
            if (_t) (*_t).push_back(_he);
            PolyMesh::HalfEdge *_heNext = _he->next->next->opposite;
            pm->swap_edge(_he);
            _he = _heNext;
          }
          // if(_t) *_t = _touched;
          // if(_t) (*_t).insert((*_t).end(), _touched.begin(), _touched.end());
          deletion_accepted = true;
        }
      }
      _deleteVertex(pm, v, _t);
    }
    return 0;
  }

int checkColorHedge(PolyMesh::HalfEdge* he, int volTag, int bndTag){
  if (he->f == nullptr) return -1;
  if (he->opposite == nullptr) return -1;
  if (he->f->data == volTag && he->opposite->f->data != volTag) {
    he->data = bndTag;
    return 1;
  }
  if (he->f->data != volTag && he->opposite->f->data != volTag) {
    he->data = -1;
    return 0;
  }
  return 0;
}

void _vertexNeighbors(PolyMesh::Vertex* v, std::vector<PolyMesh::Vertex*>& vNeighbors){
  PolyMesh::HalfEdge* he = v->he;
  do {
    vNeighbors.push_back(he->next->v);
    he = he->next->next->opposite;
  } while (he != v->he);
}

void hedgeCollapseBoundaryEdge(PolyMesh* pm, PolyMesh::HalfEdge* he, int volTag, int bndTag, std::vector<PolyMesh::HalfEdge *> *_t = NULL){
  std::vector<PolyMesh::Vertex*> vCheck;
  _vertexNeighbors(he->v, vCheck);
  pm->hedgeCollapse(he, _t);
  size_t debug = 0;
  for (auto v : vCheck){
    if (v->data <= 0) {
      continue;
    }
    PolyMesh::HalfEdge* heTurn = v->he;
    do {
      if (debug++ > 1e4){
        printf("stuck in boundary check");
        print4debug(pm, 0);
        exit(0);
      }
      checkColorHedge(heTurn, volTag, bndTag);
      heTurn = heTurn->opposite->next;
    } while(heTurn != v->he);
  }
}

inline void initialize_rectangle(PolyMesh* pm, double xmin, double xmax, double ymin,
                                   double ymax)
  {
    pm->reset();
    PolyMesh::Vertex *v_mm = new PolyMesh::Vertex(xmin, ymin, 0);
    pm->vertices.push_back(v_mm);
    PolyMesh::Vertex *v_mM = new PolyMesh::Vertex(xmin, ymax, 0);
    pm->vertices.push_back(v_mM);
    PolyMesh::Vertex *v_MM = new PolyMesh::Vertex(xmax, ymax, 0);
    pm->vertices.push_back(v_MM);
    PolyMesh::Vertex *v_Mm = new PolyMesh::Vertex(xmax, ymin, 0);
    pm->vertices.push_back(v_Mm);
    PolyMesh::HalfEdge *mm_MM = new PolyMesh::HalfEdge(v_mm);
    PolyMesh::HalfEdge *MM_mM = new PolyMesh::HalfEdge(v_MM);
    PolyMesh::HalfEdge *mM_mm = new PolyMesh::HalfEdge(v_mM);
    pm->hedges.push_back(mm_MM);
    pm->hedges.push_back(MM_mM);
    pm->hedges.push_back(mM_mm);
    PolyMesh::Face *f0 = new PolyMesh::Face(mm_MM);
    pm->faces.push_back(f0);
    pm->createFace(f0, v_mm, v_MM, v_mM, mm_MM, MM_mM, mM_mm);

    PolyMesh::HalfEdge *MM_mm = new PolyMesh::HalfEdge(v_MM);
    PolyMesh::HalfEdge *mm_Mm = new PolyMesh::HalfEdge(v_mm);
    PolyMesh::HalfEdge *Mm_MM = new PolyMesh::HalfEdge(v_Mm);
    pm->hedges.push_back(MM_mm);
    pm->hedges.push_back(mm_Mm);
    pm->hedges.push_back(Mm_MM);
    PolyMesh::Face *f1 = new PolyMesh::Face(MM_mm);
    pm->faces.push_back(f1);
    pm->createFace(f1, v_mm, v_Mm, v_MM, mm_Mm, Mm_MM, MM_mm);

    MM_mm->opposite = mm_MM;
    mm_MM->opposite = MM_mm;
  }

inline bool checkVertexConnection(PolyMesh* pm, PolyMesh::Vertex* v, int volTag){
  std::vector<PolyMesh::Face*> vertexFaces;
  pm->vertex_faces(v, vertexFaces);
  for (auto f : vertexFaces){
    if (f->data == volTag) return true;
  }
  return false;
  // PolyMesh::HalfEdge* he = v->he;
  // size_t i_debug = 0;
  // do {
  //   if (!he) return false;
  //   if (!he->f) return false;
  //   if (he->f->data == volTag) return true;
  //   he = he->next->next->opposite;
  //   if (i_debug++ > 1000){
  //     printf("infite loop \n");
  //     return false;
  //   }
  // } while (he != v->he);
  // return false;
}

static PolyMesh::Face *WalkGeneral(PolyMesh::Face *f, double x, double y, PolyMesh::HalfEdge** heBnd = nullptr)
{
  double POS[2] = {x, y};
  PolyMesh::HalfEdge *he = f->he;

  while(1) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = robustPredicates::orient2d(v2->position, v0->position, POS);

    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      if (heBnd != nullptr && s0 < 1e-11) *heBnd = he;
      if (heBnd != nullptr && s1 < 1e-11) *heBnd = he->next;
      if (heBnd != nullptr && s2 < 1e-11) *heBnd = he->next->next;
      return he->f;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0)
      he = he->opposite;
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0)
      he = he->next->opposite;
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0)
      he = he->next->next->opposite;
    else if(s0 <= 0 && s1 <= 0)
      he = s0 > s1 ? he->opposite : he->next->opposite;
    else if(s0 <= 0 && s2 <= 0)
      he = s0 > s2 ? he->opposite : he->next->next->opposite;
    else if(s1 <= 0 && s2 <= 0)
      he = s1 > s2 ? he->next->opposite : he->next->next->opposite;
    else {
      Msg::Error("Could not find half-edge in walk for point %g %g on "
                 "face %g %g %g / %g %g %g / %g %g %g "
                 "(orientation tests %g %g %g)",
                 x, y, v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(), s0, s1,
                 s2);
    }
    if(he == nullptr) break;
  }
  // should only come here wether the triangulated domain is not convex
  return nullptr;
}

void AlphaShape::_decimateTriangulation(const int faceTag, const double thresholdDistance){
  PolyMesh* pm;
  GFace2PolyMesh(faceTag, &pm);
  pm->decimate(thresholdDistance);
  PolyMesh2GFace(pm, faceTag);
}

class AlphaShapeDistanceField : public Field {
  SPoint3Cloud _pc;
  SPoint3CloudAdaptor<SPoint3Cloud> _pc2kdtree;
  SPoint3KDTree *_kdtree;
  std::size_t _outIndex;

public:
  int tag;
  double sampling_length;

  AlphaShapeDistanceField() : _pc2kdtree(_pc), _kdtree(nullptr), _outIndex(0)
  {
    tag = -1;
    sampling_length = 0.;
    options["Tag"] = new FieldOptionInt(
      tag, "Tag of the discrete entity to which the distance is computed", &updateNeeded);
    options["SamplingLength"] = new FieldOptionDouble(
      sampling_length, "Distance between two sampling points. If 0, only use nodes of the edges", &updateNeeded);
  }
  ~AlphaShapeDistanceField()
  {
    if(_kdtree) delete _kdtree;
  }
  const char *getName() { return "AlphaShapeDistance"; }
  std::string getDescription()
  {
    return "Compute the distance curves. "
           "For efficiency, curves and surfaces are replaced by a set "
           "of points (sampled according to Sampling), to which the distance "
           "is actually computed."
           "Used only the alpha-shape algorithm.";
  }
  void set(std::vector<SPoint3> &pts)
  {
    if(_kdtree) delete _kdtree;
    _pc.pts = pts;
    _kdtree = new SPoint3KDTree(3, _pc2kdtree,
                                nanoflann::KDTreeSingleIndexAdaptorParams(10));
    _kdtree->buildIndex();
    updateNeeded = false;
  }
  void update()
  {
    if (updateNeeded == true)
      Msg::Error("Set must be called explicitly with AlphaShapeDistance field");
  }
  using Field::operator();
  virtual double operator()(double X, double Y, double Z, GEntity *ge = nullptr)
  {
    if(!_kdtree) return MAX_LC;
    double pt[3] = {X, Y, Z};
    nanoflann::KNNResultSet<double> res(1);
    double outDistSqr;
    res.init(&_outIndex, &outDistSqr);
    _kdtree->findNeighbors(res, &pt[0], nanoflann::SearchParams(10));
    return sqrt(outDistSqr);
  }
};
void AlphaShape::registerAlphaShapeField(FieldManager* fm)
{
  fm->mapTypeName["AlphaShapeDistance"] = new FieldFactoryT<AlphaShapeDistanceField>();
}

static double _faceSizeFromMap(PolyMesh::HalfEdge *he, std::unordered_map<int, double> & sizeAtNodes){
  return 1./3.* (sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data] + sizeAtNodes[he->next->next->v->data]);
}

PolyMesh* AlphaShape::_alphaShapeDelaunay2D(const int tag, const std::string boundaryModelName){
  GModel *current = GModel::current();
  GModel *model_boundary = GModel::findByName(boundaryModelName);
  if (model_boundary == nullptr) {
    Msg::Error("Model %s not found", boundaryModelName.c_str());
    return nullptr;
  }
  auto bb = model_boundary->bounds();
  current->setAsCurrent();
  GFace* gf = GModel::current()->getFaceByTag(tag);
  PolyMesh *pm = new PolyMesh;
  for (auto &ed : gf->edges()){
    for (auto &v : ed->mesh_vertices){
      bb += SPoint3(v->x(), v->y(), 0);
    }
  }
  for(auto &v : gf->mesh_vertices) {
    bb += SPoint3(v->x(), v->y(), 0);
  }
  bb *= 1.1;
  initialize_rectangle(pm, bb.min().x(), bb.max().x(), bb.min().y(),
                          bb.max().y());
  PolyMesh::Face* f = pm->faces[0];
  for (auto &ed : gf->edges()){
    for (auto &v : ed->mesh_vertices){
      f = WalkGeneral(f, v->x(), v->y());
      pm->split_triangle(0, v->x(), v->y(), 0, f, delaunayCriterion, nullptr);
      pm->vertices.back()->data = v->getNum();
    }
  }
  for(auto &v : gf->mesh_vertices) {
    f = WalkGeneral(f, v->x(), v->y());
    pm->split_triangle(0, v->x(), v->y(), 0, f, delaunayCriterion, nullptr);
    pm->vertices.back()->data = v->getNum();
  }
  return pm;
}

bool isInMesh(PolyMesh::Face* f, OctreeNode<2, 32, MElement*> &octree){
  BBox<2> bb;
  PolyMesh::HalfEdge* he = f->he;
  SVector3 p0 = he->v->position;
  SVector3 p1 = he->next->v->position;
  SVector3 p2 = he->next->next->v->position;
  SVector3 c = 1./3.*(p0+p1+p2);
  bb.extends({c.x(), c.y()});
  std::vector<MElement*> res;
  octree.search(bb, res);
  if (res.size() == 0) return false;
  for (auto e : res){
    // Check if point is in triangle
    auto v0 = e->getVertex(0)->point();
    auto v1 = e->getVertex(1)->point();
    auto v2 = e->getVertex(2)->point();
    if (robustPredicates::orient2d(v0.data(), v1.data(), c.data()) >= 0 &&
        robustPredicates::orient2d(v1.data(), v2.data(), c.data()) >= 0 &&
        robustPredicates::orient2d(v2.data(), v0.data(), c.data()) >= 0) {
      return true;
    }
    // IDEA : IF THE TRIANGLE THAT I FOUND IS TOO SMALL, WE CONSIDER THAT WE'RE OUT OF THE MESH
    SVector3 v0v1 = v1-v0;
    SVector3 v0v2 = v2-v0;
    double area = 0.5*norm(crossprod(v0v1, v0v2));
    // TODO : WHAT VALUE TO PICK? !
    if (area < 1e-10) return false;
  }
  // for (size_t i = 0; i < 3; i++){
  //   bb.extends({f->he->v->position.x(), f->he->v->position.y()});
  //   f->he = f->he->next;
  // }
  return false;
}

void AlphaShape::_createOctreeForFace(GFace* gf, ElementOctree &octree){
  auto gmsh_bb = gf->bounds();
  BBox<2> bb; 
  bb.extends({gmsh_bb.min().x(), gmsh_bb.min().y()});
  bb.extends({gmsh_bb.max().x(), gmsh_bb.max().y()});
  bb *= 1.1;
  octree.set_bbox(bb);
  size_t n_tri = gf->getNumMeshElementsByType(TYPE_TRI);
  for (size_t i=0; i<n_tri; i++){
    MElement* elem = gf->getMeshElementByType(TYPE_TRI, i);
    // check orientation of element
    SPoint3 p0 = elem->getVertex(0)->point();
    SPoint3 p1 = elem->getVertex(1)->point();
    SPoint3 p2 = elem->getVertex(2)->point();
    if (robustPredicates::orient2d(p0.data(), p1.data(), p2.data()) <= 0) continue;
    BBox<2> bb_tri;
    for (size_t i = 0; i < elem->getNumVertices(); i++){
      bb_tri.extends({elem->getVertex(i)->point().x(), elem->getVertex(i)->point().y()});
    }
    octree.add(elem, bb_tri);
  }
}

void AlphaShape::_alphaShape2D(PolyMesh* pm, const double alpha, const int faceTag, const int bndTag, const int sizeFieldTag, OctreeNode<2, 32, MElement*> *octree_prev){
  // Here, define an octree based on the previous, advected time step mesh, to check whether the triangle we are computing is in the mesh or not
  // printf("previous mesh octree created \n");
  Field* field = GModel::current()->getFields()->get(sizeFieldTag);
  if (field == nullptr) {
    Msg::Error("Field %d not found", sizeFieldTag);
    return;
  }
  for (auto f : pm->faces){
    int i0 = f->he->v->data;
    int i1 = f->he->next->v->data;
    int i2 = f->he->next->next->v->data;
    if(i0 < 0 || i1 < 0 || i2 < 0) 
      f->data = -2;
  }
  // compute size field at all the nodes
  // auto tic = std::chrono::high_resolution_clock::now();
  std::unordered_map<int, double> sizeAtNodes(pm->vertices.size());
  for (auto v : pm->vertices){
    if (v->data == -1) continue;
    sizeAtNodes[v->data] = field->operator()(v->position.x(), v->position.y(), 0, NULL);
  }
  // auto toc = std::chrono::high_resolution_clock::now();
  // std::cout << "Alpha shape size field : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;
  // // Get min size field
  double hMin = 1e10;
  for (auto ss : sizeAtNodes){
    hMin = std::min(hMin, ss.second);
  }
  double sizeLimit = 0.01;
  double constrainR = .1;
  double outsideLimit = 0.2;

  std::unordered_map<PolyMesh::Face*, bool> _touched;
  double hTriangle, R, q;
  SPoint3 cc;
  for (size_t i = 0; i < pm->faces.size(); i++){
    if (pm->faces[i]->data == -2) continue;
    PolyMesh::Face *f = pm->faces[i];
    hTriangle = _faceSizeFromMap(f->he, sizeAtNodes);
    // check if element is in the advected mesh
    bool is_in_mesh = (octree_prev != nullptr) ? isInMesh(f, *octree_prev) : true;
    hTriangle = is_in_mesh ? hTriangle : hTriangle*outsideLimit;
    // if (usePreviousMesh && is_in_mesh &&  abs(hTriangle-hMin)/hMin < 1e-2) hTriangle*=bndLimit;
    faceInfo(f->he, cc, &R, &q);
    if ((octree_prev != nullptr) && abs(hTriangle-hMin)/hMin < sizeLimit && R/hTriangle < constrainR) {
      // printf("yes, removing ! \n");
      // ce sont les plus petits éléments que je veux enlever, pas les grands... 
      R*=1000; //
    }
    if (R/hTriangle < alpha && !_touched[f]){
      std::stack<PolyMesh::Face *> _s;
      _s.push(f);
      _touched[f] = true;
      f->data = faceTag;
      while(!_s.empty()){
        PolyMesh::Face* _f = _s.top();
        _s.pop();
        PolyMesh::HalfEdge *_he = _f->he;
        do {
          if (_he->opposite == nullptr || _he->opposite->f->data < -1){
            _he->data = bndTag;      
            _he->opposite->data = bndTag;      
          }     
          else if (!_touched[_he->opposite->f]){
            PolyMesh::Face *f_neigh = _he->opposite->f;
            hTriangle = _faceSizeFromMap(f_neigh->he, sizeAtNodes);
            bool is_in_mesh = (octree_prev != nullptr) ? isInMesh(f_neigh, *octree_prev) : true;
            hTriangle = is_in_mesh ? hTriangle : hTriangle*outsideLimit;
            faceInfo(f_neigh->he, cc, &R, &q);
            if ((octree_prev != nullptr) && abs(hTriangle-hMin)/hMin < sizeLimit && R/hTriangle < constrainR) {
              // printf("yes, removing ! \n");
              // ce sont les plus petits éléments que je veux enlever, pas les grands... 
              R*=1000;
            }
            if (R/hTriangle < alpha){
              _s.push(f_neigh);
              _touched[f_neigh] = true;
              f_neigh->data = faceTag;    
            }	    
            else {
              _he->data = bndTag;
              _he->opposite->data = bndTag;
            }
          }
          _he = _he->next;
        }while (_he != _f->he);
      }
    }
  }
}

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2>& p) const
  {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);
    if (hash1 != hash2) {
        return hash1 ^ hash2;              
    }
    return hash1;
  }
};

// static std::vector<std::pair<PolyMesh::HalfEdge*,  SVector3> >
// walkWithIntersections(SVector3 pfrom, SVector3 pto, PolyMesh::HalfEdge *searchstart) {
//   std::vector<std::pair<PolyMesh::HalfEdge*,  SVector3> > res;
//   PolyMesh::HalfEdge *he = searchstart;
//   // search the starting triangle
//   while (true) {
//     auto s0 = robustPredicates::orient2d(*he->v, *he->next->v, pfrom);
//     auto s1 = robustPredicates::orient2d(*he->next->v, *he->next->next->v, pfrom);
//     auto s2 = robustPredicates::orient2d(*he->next->next->v, *he->v, pfrom);
//     if (s0 >= 0 && s1 >= 0 && s2 >= 0) {
//       break;
//     }
//     if (s0 < 0 && (s0 <= s1 || he->next->opposite == nullptr) && (s0 <= s2 || he->next->next->opposite == nullptr)) {
//       he = he->opposite;
//     } else if (s1 < 0 && (s1 <= s0 || he->opposite == nullptr) && (s1 <= s2 || he->next->next->opposite == nullptr)) {
//       he = he->next->opposite;
//     } else {
//       he = he->next->next->opposite;
//     }
//   }

//   // start with an he so that s0 >= 0
//   while (true) {
//     auto s0 = robustPredicates::orient2d(*he->v, *he->next->v, pto);
//     if (s0 >= 0) break;
//     he = he->next;
//   }

//   // walk to pto
//   SVector3 current = pfrom;
//   res.push_back({he, pfrom});
//   while (true) {
//     auto s0 = robustPredicates::orient2d(*he->v, *he->next->v, pto);
//     if (s0 < 0) {
//       printf("this should not happen.\n");
//       he = he->opposite;
//       continue;
//     }
//     double s1 = robustPredicates::orient2d(*he->next->v, *he->next->next->v, pto);
//     double s2 = robustPredicates::orient2d(*he->next->next->v, *he->v, pto);
//     double sto;

//     if (s1 >= 0 && s2 >= 0) {
//       //if (s0 != 0) {
//         res.push_back({he, pto});
//       //}
//       break;
//     }
//     if (s2 >= 0) { // s1 is negative
//       he = he->next->opposite;
//       sto = -s1;
//     }
//     else if (s1 >= 0) { // s2 is negative
//       he = he->next->next->opposite;
//       sto = -s2;
//     }
//     else {
//       auto s3 = robustPredicates::orient2d(current, pto, *he->next->next->v);
//       if (s3 < 0) {
//         he = he->next->next->opposite;
//         sto = -s2;
//       } else {
//         he = he->next->opposite;
//         sto = -s1;
//       }
//     }
//     // we know that (current, pto) intersects he
//     double sfrom = robustPredicates::orient2d(*he->v, *he->next->v, current);
//     if (sfrom == 0 && sto == 0) { // colinear
//       auto l = he->next->v->position-he->v->position;
//       double d = dot(pto-he->v->position, l)/dot(l, l);
//       if (d < 0) {
//         current = he->v->position;
//       }
//       else if (d > 1) {
//         current = he->next->v->position;
//       }
//       else {
//         current = he->v->position*(1-d) + he->next->v->position*d;
//       }
//     }
//     else {
//       double d = sto/(sto-sfrom);
//       current = pto*(1-d) + current*d;
//     }
//     res.push_back({he, current});
//   }
//   return res;
// }


template <>
struct std::hash<std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*>> {
    size_t operator() (const std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*>& m) const { 
      if (m.first->data < m.second->data)
        return m.second->data*m.second->data + m.first->data;
      return m.first->data*m.first->data + m.first->data + m.second->data;
    }
};

std::pair<int, SVector3> snapPoint(PolyMesh::HalfEdge *he, SVector3 p, double tol) {
  PolyMesh::HalfEdge *hes[3] = {he, he->next, he->next->next};
  int r = 0;
  for (int i = 0; i < 3; ++i) {
    auto h = hes[i];
    auto d = h->next->v->position - h->v->position;
    double a = dot(p - h->v->position, d)/dot(d, d);
    auto proj = (1-a) * h->v->position + a * h->next->v->position;
    if (norm(proj - p) < tol) {
      r = i+1;
      p = proj;
      break;
    }
  }
  for (int i = 0; i < 3; ++i) {
    auto h = hes[i];
    if (norm(h->v->position - p) < tol) {
      r = i+4;
      p = h->v->position;
      break;
    }
  }
  return {r, p};
}

 static int delaunayCriterionColors(PolyMesh::HalfEdge *he, void* val)
{
  // if(he->f == nullptr) return -1;
  // if(he->opposite == nullptr) return -1;
  if(he->opposite == nullptr) return -1;
  if(he->data > 0) return 0;
  if(he->opposite->data > 0) return 0;
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;
  // FIXME : should be oriented anyway !
  double result = robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);
  return (result >= 0) ? 1 : 0;
}

void _delaunayCheckColors(PolyMesh* pm, std::vector<PolyMesh::HalfEdge* > hes, std::vector<PolyMesh::HalfEdge* > *_t){
  std::stack<PolyMesh::HalfEdge *> _stack;
  for (auto he : hes) _stack.push(he);
  std::vector<PolyMesh::HalfEdge *> _touched;
  while(!_stack.empty()) {
    // if (debug++ > 1e4){
    //   printf("stuck in delaunay check colors \n");
    //   print4debug(pm, 0);
    //   exit(0);
    // }
    PolyMesh::HalfEdge *he = _stack.top();
    _touched.push_back(he);
    _stack.pop();
    if (!he->opposite || !he->f) continue;
    if(delaunayCriterionColors(he, nullptr) == 1) {
      pm->swap_edge(he);
      PolyMesh::HalfEdge *H[2] = {he, he->opposite};
      for(int k = 0; k < 2; k++) {
        if(H[k] == NULL) continue;
        PolyMesh::HalfEdge *heb = H[k]->next;
        PolyMesh::HalfEdge *hebo = heb->opposite;
        if(std::find(_touched.begin(), _touched.end(), heb) ==
              _touched.end() &&
            std::find(_touched.begin(), _touched.end(), hebo) ==
              _touched.end()) {
          _stack.push(heb);
        }

        PolyMesh::HalfEdge *hec = heb->next;
        PolyMesh::HalfEdge *heco = hec->opposite;
        if(std::find(_touched.begin(), _touched.end(), hec) ==
              _touched.end() &&
            std::find(_touched.begin(), _touched.end(), heco) ==
              _touched.end()) {
          _stack.push(hec);
        }
      }
    }
  }
  *_t = _touched;
}

double distPointSegment(SVector3 p, SVector3 a, SVector3 b) {
  SVector3 ab = b-a;
  double t = dot(p-a, ab)/dot(ab, ab);
  if (t < 0) return norm(p-a);
  if (t > 1) return norm(p-b);
  return norm(p-(a+t*ab));
}

bool bndIsStraight(GEntity* e){
  size_t n_elem = e->getNumMeshElements();
  for (size_t i_el = 0; i_el<n_elem-1; i_el++){
    MElement *elem0 = e->getMeshElement(i_el);
    MElement *elem1 = e->getMeshElement(i_el+1);
    SVector3 v0 = elem0->getVertex(1)->point() - elem0->getVertex(0)->point();
    SVector3 v1 = elem1->getVertex(1)->point() - elem1->getVertex(0)->point();
    if (crossprod(v0, v1).norm() > 1e-6) return false;
  }
  return true;
}

bool linelineIntersect(SVector3 p0, SVector3 p1, SVector3 p2, SVector3 p3){
  double o0 = robustPredicates::orient2d(p0, p1, p2);
  double o1 = robustPredicates::orient2d(p0, p1, p3);
  double o2 = robustPredicates::orient2d(p2, p3, p0);
  double o3 = robustPredicates::orient2d(p2, p3, p1);
  if (o0*o1 <= 0 && o2*o3 <= 0){
    return true;
  }
  // check if the lines are colinear
  if (o0 == 0 && o1 == 0 && o2 == 0 && o3 == 0){
    double d0 = dot(p2-p0, p1-p0);
    double d1 = dot(p3-p0, p1-p0);
    double d2 = dot(p0-p2, p3-p2);
    double d3 = dot(p1-p2, p3-p2);
    if (d0*d1 <= 0 && d2*d3 <= 0){
      return true;
    }
  }
  return false;

}

void AlphaShape::_edgeRecover(PolyMesh* pm, const int tag, const int bndTag, const std::string & boundaryModel, std::vector<PolyMesh::Vertex*> & controlNodes, OctreeNode<2, 32, alphaShapeBndEdge*> &bnd_octree, const double boundary_tol){
  GModel* gm_alphaShape = GModel::current();
  size_t newTag = gm_alphaShape->getMaxVertexNumber()+1;
  GModel* gm_boundary = GModel::findByName(boundaryModel);
  if (gm_boundary == nullptr) {
    Msg::Error("Boundary model not found");
    return;
  }

  std::vector<GEntity*> bndEntities;
  gm_boundary->getEntities(bndEntities, 1); 
  if (bndEntities.size() > 0 && bndEntities[0]->getNumMeshElements() == 0){
    Msg::Error("No mesh elements found for entity %d in Boundary Model", bndEntities[0]->tag());
  }
  // Insert control nodes (--> i.e., all the nodes of the boundary mesh)
  controlNodes.clear();
  // std::unordered_set<GVertex*> gVertices;
  std::unordered_set<MVertex*> gVertices;
  BBox<2> searchbox;
  // auto tic = std::chrono::high_resolution_clock::now();
  for (auto e : bndEntities){
    if (bndIsStraight(e)) { // only insert the first and last nodes of the entity
      GEdge* ge = dynamic_cast<GEdge*>(e);
      gVertices.insert(ge->getBeginVertex()->mesh_vertices[0]);
      gVertices.insert(ge->getEndVertex()->mesh_vertices[0]);
    }
    else {
      size_t n_elem = e->getNumMeshElements();
      for (size_t i_el = 0; i_el<n_elem; i_el++){
        MElement *elem = e->getMeshElement(i_el);
        if(elem->getDim() != 1) continue;
        gVertices.insert(elem->getVertex(0));
        gVertices.insert(elem->getVertex(1));
        // SPoint3 p[2] = {elem->getVertex(0)->point(), elem->getVertex(1)->point()};
      }
    }
  }
  for (auto gv : gVertices){
    SVector3 X(gv->x(), gv->y(), gv->z());
    PolyMesh::HalfEdge* heBnd = nullptr;
    PolyMesh::Face* f = WalkGeneral(pm->faces[0], X.x(), X.y(), &heBnd);
    // PolyMesh::Face* f = WalkGeneral(pm->faces[0], X.x(), X.y());
    if (heBnd != nullptr && (heBnd->data == bndTag || heBnd->opposite->data == bndTag)){
    // if (heBnd != nullptr && (heBnd->data == bndTag)){
      if (heBnd->data != bndTag) {
        heBnd = heBnd->opposite;
      }
      if (heBnd->f->data != tag) 
        continue;
      // double threshold = 1e-6;
      double threshold = boundary_tol;
      double d0 = norm(X - heBnd->v->position);
      if (d0 < threshold){
        controlNodes.push_back(heBnd->v);
        continue;
      }
      double d1 = norm(X - heBnd->next->v->position);
      if (d1 < threshold){
        controlNodes.push_back(heBnd->next->v);
        continue;
      }
      pm->split_edge(heBnd, X, -1);
      PolyMesh::Vertex* v = pm->vertices.back();
      v->data = newTag++;
      controlNodes.push_back(v);
      heBnd->next->opposite->f->data = heBnd->f->data;
      heBnd->opposite->f->data = heBnd->next->opposite->next->opposite->f->data;
      heBnd->data = bndTag; // constrain them again
      heBnd->opposite->data = bndTag; // constrain them again
      heBnd->next->opposite->next->data = bndTag; // constrain them again
      heBnd->next->opposite->next->opposite->data = bndTag; // constrain them again
    }
    else if (f != nullptr && f->data == tag){
      PolyMesh::HalfEdge* he = f->he;
      double d0 = norm(X - he->v->position);
      double d1 = norm(X - he->next->v->position);
      double d2 = norm(X - he->next->next->v->position);
      double threshold = boundary_tol;
      if (d0 < threshold){
        controlNodes.push_back(he->v);
        continue;
      }
      if (d1 < threshold){
        controlNodes.push_back(he->next->v);
        continue;
      }
      if (d2 < threshold){
        controlNodes.push_back(he->next->next->v);
        continue;
      }
      pm->split_triangle(-1, X.x(), X.y(), X.z(), f, delaunayCriterion, (void*)&bndTag);
      // printf("split triangle (%f,%f) ; (%f, %f) ; (%f, %f) at (%f, %f) \n", f->he->v->position.x(), f->he->v->position.y(), f->he->next->v->position.x(), f->he->next->v->position.y(), f->he->next->next->v->position.x(), f->he->next->next->v->position.y(), X.x(), X.y());
      PolyMesh::Vertex* v = pm->vertices.back();
      v->data = newTag++;
      controlNodes.push_back(v);
    }
  }

  // auto toc = std::chrono::high_resolution_clock::now();
  // std::cout << "    Init  : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;

  std::vector<alphaShapeBndEdge*> result;
  std::vector<PolyMesh::HalfEdge*> result_he;
  std::unordered_set<std::pair<int,int>, hash_pair> res_set;
  std::vector<PolyMesh::HalfEdge*> res_filtered;
  // double boundary_tol = 1e-5;
  // for (const auto &e : bndEntities) {
  std::vector<PolyMesh::HalfEdge*> allHedges;
  for (auto he : pm->hedges) allHedges.push_back(he);
  // while (!allHedges.empty()){
  for (auto he : pm->hedges){
    // auto he = allHedges.back();
    // allHedges.pop_back();
    if (he->f == nullptr || he->f->data != tag) continue;
    // if (he->f == nullptr || he->v->data < 0) continue;

    // size_t n_elem = e->getNumMeshElements();
    // for (size_t i_el = 0; i_el<n_elem; i_el++){
      // MElement *elem = e->getMeshElement(i_el);
      // if(elem->getDim() != 1) continue;
      // SPoint3 p[2] = {elem->getVertex(0)->point(), elem->getVertex(1)->point()};
      // double* a1 = p[0];
      // double* a2 = p[1];
    SVector3 p[2] = {he->v->position, he->next->v->position};
    double* a3 = p[0];
    double* a4 = p[1];
    BBox<2> searchbox;
    for (int i = 0; i < 2; ++i) {
      searchbox.extends({p[i].x(), p[i].y()});
    }
    // searchbox*=(1+boundary_tol);
    result.clear();
    // res_set.clear();
    // res_filtered.clear();
    bnd_octree.search(searchbox, result);
    // for (auto bndEd : result){
    //   int n0 = he->v->data;
    //   int n1 = he->next->v->data;
    //   auto edge = res_set.find(std::make_pair(std::min(n0, n1), std::max(n0, n1)));
    //   if (edge == res_set.end()){
    //     res_set.insert(std::make_pair(std::min(n0, n1), std::max(n0, n1)));
    //     res_filtered.push_back(he);
    //   }
    // }
    // for (auto he : res_filtered){
    for (auto bndEd : result){
      // double* a3 = &he->v->position[0];
      // double* a4 = &he->next->v->position[0];
      double a1[2] = {bndEd->x0, bndEd->y0};
      double a2[2] = {bndEd->x1, bndEd->y1};
      double a143 = robustPredicates::orient2d(a1,a4,a3);
      double a243 = robustPredicates::orient2d(a2,a4,a3);    
      double a123 = robustPredicates::orient2d(a1,a2,a3);
      double a124 = robustPredicates::orient2d(a1,a2,a4);
      if (fabs(a143) < 1e-10 || fabs(a243) < 1e-10 || fabs(a123) < 1e-10 || fabs(a124) < 1e-10) continue; // parallel ? 
      if (a143*a243 < 0 && a123*a124 < 0){
        double t = fabs(a143)/(fabs(a143)+fabs(a243));
        double vec[2] = {a2[0]-a1[0], a2[1]-a1[1]};
        SVector3 new_intersection(a1[0]+t*vec[0], a1[1]+t*vec[1], 0.);
        double d0 = norm(new_intersection - he->v->position);
        double d1 = norm(new_intersection - he->next->v->position);
        double d2 = norm(new_intersection - he->next->next->v->position);
        double d3 = norm(new_intersection - he->opposite->next->v->position);
        double threshold = 1e-6; // FIXME : doesn't work with smaller threshold ...
        if (d0 < threshold || d1 < threshold || d2 < threshold || d3 < threshold) continue;
        pm->split_edge(he, new_intersection, newTag++);
        he->f->data = tag;
        he->next->opposite->f->data = tag;
        if (he->data != bndTag){
          he->opposite->f->data = tag;
          he->opposite->next->next->opposite->f->data = tag;
        }
        else {
          he->next->opposite->f->data = he->f->data;
          he->opposite->f->data = he->next->opposite->next->opposite->f->data;
          he->data = bndTag; // constrain them again
          he->opposite->data = bndTag; // constrain them again
          he->next->opposite->next->data = bndTag; // constrain them again
          he->next->opposite->next->opposite->data = bndTag; // constrain them again
        }
      }
    }
  }
  // autotoc = std::chrono::high_resolution_clock::now();
  // std::cout << "    Octree search  : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;

  // check and remove elements that are outside the domain
  // auto tic = std::chrono::high_resolution_clock::now();
  BBox<2> bb_geo;
  for (auto e : bndEntities){
    size_t n_v = e->getNumMeshVertices();
    for (size_t i_v = 0; i_v<n_v; i_v++){
      MVertex *elem = e->getMeshVertex(i_v);
      bb_geo.extends({elem->point().x(), elem->point().y()});
    }
  }
  OctreeNode<2, 64, MElement*> octree_geo(bb_geo);
  for (auto face : gm_boundary->getFaces()){
    size_t n_elem = face->getNumMeshElements();
    for (size_t i_el = 0; i_el<n_elem; i_el++){
      MElement *elem = face->getMeshElement(i_el);
      if(elem->getDim() != 2) continue;
      BBox<2> bb_tri;
      for (size_t i = 0; i < elem->getNumVertices(); i++){
        bb_tri.extends({elem->getVertex(i)->point().x(), elem->getVertex(i)->point().y()});
      }
      octree_geo.add(elem, bb_tri);
    }
  }  
  // toc = std::chrono::high_resolution_clock::now();
  // std::cout << "    init geo octree : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;
  for (auto f : pm->faces){
    PolyMesh::Vertex* v0 = f->he->v;
    PolyMesh::Vertex* v1 = f->he->next->v;
    PolyMesh::Vertex* v2 = f->he->next->next->v;
    if (v0->data < 0 || v1->data < 0 || v2->data < 0){
      f->data = -1; continue;
    }
    SVector3 p0 = v0->position;
    SVector3 p1 = v1->position;
    SVector3 p2 = v2->position;
    SVector3 pc = 1./3.*(p0+p1+p2);
    BBox<2> bb_tri;
    bb_tri.extends({pc.x(), pc.y()});
    std::vector<MElement*> found;
    octree_geo.search(bb_tri, found);
    bool inside = false;
    for (auto elem : found){
      double uvw[3];
      elem->xyz2uvw(pc, uvw);
      if (elem->isInside(uvw[0], uvw[1], uvw[2])){
        inside = true;
        break;
      }
    }
    if (!inside) f->data = -1; 
  }
  // auto toc = std::chrono::high_resolution_clock::now();
  // std::cout << "    Remove outside  : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;

  // Other solution : ray trace the points to see if they are inside the domain using bnd_octree
  // auto tic = std::chrono::high_resolution_clock::now();
  // SVector3 P1_flat(bnd_octree.bbox_.min[0], bnd_octree.bbox_.max[1], 0);
  // double r = (bnd_octree.bbox_.max[0] - bnd_octree.bbox_.min[0]) + (bnd_octree.bbox_.max[1] - bnd_octree.bbox_.min[1]);
  // for (auto f : pm->faces){
  //   PolyMesh::Vertex* v0 = f->he->v;
  //   PolyMesh::Vertex* v1 = f->he->next->v;
  //   PolyMesh::Vertex* v2 = f->he->next->next->v;
  //   if (v0->data < 0 || v1->data < 0 || v2->data < 0){
  //     f->data = -1; continue;
  //   }
  //   SVector3 p0 = v0->position;
  //   SVector3 p1 = v1->position;
  //   SVector3 p2 = v2->position;
  //   SVector3 P0 = 1./3.*(p0+p1+p2);
  //   P1_flat[1] = P0.y();
  //   BBox<2> bb_ray_flat;
  //   bb_ray_flat.extends({P0.x(), P0.y()});
  //   bb_ray_flat.extends({P1_flat.x(), P1_flat.y()});
  //   std::vector<alphaShapeBndEdge*> found_flat;
  //   bnd_octree.search(bb_ray_flat, found_flat);
  //   // remove duplicates in found
  //   std::sort(found_flat.begin(), found_flat.end());
  //   found_flat.erase(std::unique(found_flat.begin(), found_flat.end()), found_flat.end());
  //   size_t n_intersect_flat = 0;
  //   for (auto bnd_edg : found_flat){
  //     SVector3 P2(bnd_edg->x0, bnd_edg->y0, 0);
  //     SVector3 P3(bnd_edg->x1, bnd_edg->y1, 0);
  //     // check ray - a intersection
  //     if (linelineIntersect(P0, P1_flat, P2, P3)){
  //         n_intersect_flat++;
  //     }
  //   }
    
  //   BBox<2> bb_ray;
  //   double theta = double(std::rand())/RAND_MAX;
  //   theta *= 2*M_PI;
  //   SVector3 P1(P0.x()+cos(theta)*r, P0.y()+sin(theta)*r, 0);
  //   bb_ray.extends({P0.x(), P0.y()});
  //   bb_ray.extends({P1.x(), P1.y()});
  //   std::vector<alphaShapeBndEdge*> found;
  //   bnd_octree.search(bb_ray, found);
  //   std::sort(found.begin(), found.end());
  //   found.erase(std::unique(found.begin(), found.end()), found.end());
  //   size_t n_intersect = 0;
  //   for (auto bnd_edg : found){
  //     SVector3 P2(bnd_edg->x0, bnd_edg->y0, 0);
  //     SVector3 P3(bnd_edg->x1, bnd_edg->y1, 0);
  //     // check ray - a intersection
  //     if (linelineIntersect(P0, P1, P2, P3)){
  //         n_intersect++;
  //     }
  //   }
    
  //   // if (n_intersect_flat%2 == 0){
  //   if (n_intersect%2 == 0 && n_intersect_flat%2 == 0){
  //     f->data = -1;
  //   }
  // }
  // auto toc = std::chrono::high_resolution_clock::now();
  // std::cout << "    Remove outside  : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;
  // print4debug(pm, 0);
  // Color boundary edges
  std::set<int> resultTags0;
  std::set<int> resultTags1;
  std::set<int> intersection;
  for (auto he : pm->hedges){
    if (he->f == nullptr || he->f->data != tag) continue;
    if (he->f->data == he->opposite->f->data){ // just to make sure it is a boundary edge
      he->data = -1; 
      continue;
    }
    BBox<2> search_bbox;
    search_bbox.extends({he->v->position.x()+boundary_tol, he->v->position.y()+boundary_tol});
    search_bbox.extends({he->v->position.x()-boundary_tol, he->v->position.y()-boundary_tol});
    result.clear();
    bnd_octree.search(search_bbox, result);
    if (result.size() == 0){  // free surface!!!
      he->data = bndTag;
      he->opposite->data = bndTag;
      continue;
    }
    resultTags0.clear();
    for (auto &ed : result){
      SVector3 a(ed->x0, ed->y0, 0);
      SVector3 b(ed->x1, ed->y1, 0);
      if (distPointSegment(he->v->position, a, b) < boundary_tol)
        resultTags0.insert(ed->tag);
    }
    BBox<2> search_bbox1;
    search_bbox1.extends({he->next->v->position.x()+boundary_tol, he->next->v->position.y()+boundary_tol});
    search_bbox1.extends({he->next->v->position.x()-boundary_tol, he->next->v->position.y()-boundary_tol});
    result.clear();
    bnd_octree.search(search_bbox1, result);
    if (result.size() == 0){ // free surface!!!
      he->data = bndTag;
      he->opposite->data = bndTag;
      continue; 
    }
    resultTags1.clear();
    for (auto &ed : result){
      SVector3 a(ed->x0, ed->y0, 0);
      SVector3 b(ed->x1, ed->y1, 0);
      if (distPointSegment(he->next->v->position, a, b) < boundary_tol)
        resultTags1.insert(ed->tag);
    }
    intersection.clear();
    std::set_intersection(resultTags0.begin(), resultTags0.end(), resultTags1.begin(), resultTags1.end(), std::inserter(intersection, intersection.begin()));
    if (intersection.size() == 1){
      he->data = *intersection.begin();
      he->opposite->data = *intersection.begin();
    }
    else {
      he->data = bndTag;
      he->opposite->data = bndTag;
    }
  }

  std::vector<PolyMesh::HalfEdge *> _touched;
  _delaunayCheckColors(pm, pm->hedges, &_touched);
  // toc = std::chrono::high_resolution_clock::now();
  // std::cout << "    Delaunay check  : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;
  // tic = std::chrono::high_resolution_clock::now();
  // std::cout << "    Color edges  : " << std::chrono::duration_cast<std::chrono::milliseconds>(tic - toc).count() << "ms" << std::endl;
}
  
bool boundaryCheck(PolyMesh* pm, PolyMesh::Vertex* v){
  PolyMesh::HalfEdge *he = v->he;
  size_t debug = 0;
  if(he->data > 0) return true;
  do {
    he = he->opposite;
    if(he == nullptr) return true;
    he = he->next;
    if(he->data > 0) return true;
    if (debug++ > 1e4){
      printf("stuck in boundary check");
      print4debug(pm, 0);
      exit(0);
    }
  } while(he != v->he);
  return false;
 }


void _WalkColors(PolyMesh::Face *f, double* cc, PolyMesh::HalfEdge** heCandidate, bool* found, int* onEdgeFlag)
{
  // heCandidate = nullptr;
  double POS[2] = {cc[0], cc[1]};
  PolyMesh::HalfEdge *he = f->he;
  bool cont = true;
  if (onEdgeFlag) *onEdgeFlag = -1;
  while(cont) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = robustPredicates::orient2d(v2->position, v0->position, POS);
    if (onEdgeFlag){
      if (s0 == 0) *onEdgeFlag = 0;
      if (s1 == 0) *onEdgeFlag = 1;
      if (s2 == 0) *onEdgeFlag = 2;
    }
    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      *heCandidate = he;
      *found = true;
      cont = false;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0){
      if (he->data > 0){
        *heCandidate = he;
        *found = false;
        cont = false;
      }
      else 
        he = he->opposite;
    }
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0){
      if (he->next->data > 0){
        *heCandidate = he->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->opposite;
    }
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0){
      if (he->next->next->data > 0){
        *heCandidate = he->next->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->next->opposite;
    }
    else if(s0 <= 0 && s1 <= 0){
      // he = s0 > s1 ? he->opposite : he->next->opposite;
      if (s0 < s1){
        if (he->data > 0){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else{
        if (he->next->data > 0){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
    }
    else if(s0 <= 0 && s2 <= 0){
      if (s0 < s2){
        if (he->data > 0){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else {
        if (he->next->next->data > 0){
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->next->opposite;
        }
      }
    }
    else if(s1 <= 0 && s2 <= 0){
      if (s1 < s2){
        if(he->next->data > 0){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
      else {
        if(he->next->next->data > 0){
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->next->opposite;
        }
      }
    }
    else {
      Msg::Error("Could not find half-edge in walk for point %g %g on "
                 "face %g %g %g / %g %g %g / %g %g %g "
                 "(orientation tests %g %g %g)", cc[0], cc[1],
                 v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(),
                 s0, s1, s2);
    }
    if(he == nullptr) break;
  }
  if(he== nullptr) *found = false;
}

bool _deletionAllowed(PolyMesh* pm, PolyMesh::HalfEdge* he_delete){
  PolyMesh::Vertex* v_del = he_delete->v;
  PolyMesh::Vertex* v_col = he_delete->next->v;
  std::vector<PolyMesh::Face*> _f;
  pm->vertex_faces(v_del, _f);
  for (auto f : _f){
    // if (f->data < 0) continue;
    auto v0 = f->he->v == v_del ? v_col : f->he->v;
    auto v1 = f->he->next->v == v_del ? v_col : f->he->next->v;
    auto v2 = f->he->next->next->v == v_del ? v_col : f->he->next->next->v;
    if (robustPredicates::orient2d(v0->position, v1->position, v2->position) < 0) return false;
  }
  return true;
}

void AlphaShape::_delaunayRefinement(PolyMesh* pm, const int tag, const int bndTag, const int sizeFieldTag, std::vector<PolyMesh::Vertex*> & controlNodes){
  for (auto it : *GModel::current()->getFields()){
    auto field = it.second;
    if (field->getName() == std::string("AlphaShapeDistance")){
      AlphaShapeDistanceField * asdf = dynamic_cast<AlphaShapeDistanceField*>(field);
      // for (auto i : list){
      std::vector<SPoint3> points;
      for (auto he : pm->hedges){
        if (he->f != nullptr && he->data == asdf->tag){
          SVector3 p0 = he->v->position;
          SVector3 p1 = he->next->v->position;
          double d = norm(p1-p0);
          int n = asdf->sampling_length == 0 ? 2 : std::max(2, int(d/asdf->sampling_length));
          for (int i = 0; i < n; i++){
            points.push_back((p0 + (p1-p0)*(i*1./(n-1))).point());
          }
        }
      }
      asdf->set(points);
    }
  }

  Field* field = GModel::current()->getFields()->get(sizeFieldTag);
  if (field == nullptr) {
    Msg::Error("Field %d not found", sizeFieldTag);
    return;
  }
  // Compute the size field at the nodes if it was not done in the alpha shape (because hMean was used)
  std::unordered_map<int, double> sizeAtNodes(pm->vertices.size());
  for (size_t i=0; i<pm->vertices.size(); i++){
    PolyMesh::Vertex* v = pm->vertices[i];
    sizeAtNodes[v->data] = field->operator()(v->position.x(), v->position.y(), 0);
    // sizeAtNodes[v->data] = BGM_MeshSize(gf, v->position.x(), v->position.y(), v->position.x(), v->position.y(), 0);
  }

  // print4debug(pm, 0, sizeAtNodes);

  // Coarsen
  std::vector<PolyMesh::HalfEdge *> heVector;
  double coarseFactor_bnd = 0.2;
  double coarseFactor_in = 0.2;
  for (auto he : pm->hedges){
    if (he->opposite == nullptr || he->opposite->f == nullptr || he->f == nullptr ) continue; 
    if ((he->data == -1 && !boundaryCheck(pm, he->v)) || he->data > 0){
      double d = norm(he->v->position - he->next->v->position);
      double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
      if (d < coarseFactor_in*size) {
        insert_sorted(heVector, he, heCompare);
      }
    }
  }
  std::unordered_set<PolyMesh::Vertex*> controlNodesSet(controlNodes.begin(), controlNodes.end());
  size_t debug = 0;
  size_t size_init = heVector.size();
  while (!heVector.empty()){
    if (debug++ > 10*size_init){
      printf("exceeded size in coarsening \n");
      print4debug(pm, 0);
      exit(0);
    }
    PolyMesh::HalfEdge *he = heVector.back();
    heVector.erase(heVector.end()-1);
    if (he->opposite == nullptr || he->opposite->f == nullptr || he->f == nullptr ) continue; 
    if (he->f->data != tag) continue;
    if (boundaryCheck(pm, he->v) && he->data == -1) continue; 
    bool control = false;
    if (controlNodesSet.find(he->v) != controlNodesSet.end()) control = true;
    double d = norm(he->v->position - he->next->v->position);
    double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
    if (d < coarseFactor_in*size){
      if (control && controlNodesSet.find(he->opposite->v) != controlNodesSet.end()) continue;
      std::vector<PolyMesh::HalfEdge *> _nhes;
      if (he->data > 0 && d <coarseFactor_bnd*size){
        auto he_collapse = control ? he->opposite : he;
        if (!_deletionAllowed(pm, he_collapse)) continue;
        hedgeCollapseBoundaryEdge(pm, he_collapse, tag, he->data, &_nhes);
      }
      else if (he->data < 0){
        auto he_collapse = control ? he->opposite : he;
        pm->hedgeCollapse(he_collapse, &_nhes);
      }
      auto it = std::find(heVector.begin(), heVector.end(), he->opposite);
      if (it != heVector.end()) heVector.erase(it);
      std::vector<PolyMesh::HalfEdge* > _t;
      _delaunayCheckColors(pm, _nhes, &_t);  
    }
  }
  for (auto f : pm->faces){
    if (f->data == -1 || f->he == nullptr) continue;
    if (f->he->data > 0 && f->he->next->data > 0 && f->he->next->next->data > 0){
      auto v0 = f->he->v;
      auto v1 = f->he->next->v;
      auto v2 = f->he->next->next->v;
      if (robustPredicates::orient2d(v0->position, v1->position, v2->position) <= 0){
        f->data = -1;
      }
    }
  }
  
  // Refine
  std::vector<PolyMesh::Face *> _badFaces;
  double _limit = .4;         // Values to discuss...
  double _size = 1.;          // Values to discuss...
  double _sizeMinFactor = .1; // Values to discuss...
  for(auto f : pm->faces) {
    if (f->he && f->data == tag){
      double q, R, s;
      SPoint3 cc;
      faceInfo(f->he, cc, &R, &q);
      s = _faceSizeFromMap(f->he, sizeAtNodes);
      if((q < _limit && R/s > _sizeMinFactor) || R/s > _size) insert_sorted(_badFaces, f, faceCompareFct);
    }
  }
  int newTag = 0;
  for (auto v : pm->vertices) if (v->data > newTag) newTag = v->data;
  newTag++;

  size_t n_faces_init = _badFaces.size();
  while (!_badFaces.empty()){
    if (_badFaces.size() > 100*n_faces_init){
      printf("too many faces in refine, most likely a bug in geometry \n");
      print4debug(pm, 0); 
      exit(0);
    }
    PolyMesh::Face *f = _badFaces.back();
    _badFaces.erase(_badFaces.end()-1);
    if (f->he == nullptr || f->data != tag) {
      continue;
    }
    double q, R, s;
    SPoint3 cc;
    faceInfo(f->he, cc, &R, &q); // NB : q = 2*rho / R
    s = _faceSizeFromMap(f->he, sizeAtNodes);
    if((q < _limit && R/s > _sizeMinFactor) || R/s > _size){
      PolyMesh::HalfEdge* heCandidate = nullptr;
      bool found;
      int onEdgeFlag=0;
      _WalkColors(f, cc, &heCandidate, &found, &onEdgeFlag);
      if (onEdgeFlag != -1){ // A sanity check... if we are splitting a triangle with a 90° angle, and the opposite edge happens to be a boundary edge, we must split the edge, not the triangle
        PolyMesh::HalfEdge *flaggedHe = nullptr; 
        if (onEdgeFlag == 0) flaggedHe = heCandidate;
        else if (onEdgeFlag == 1) flaggedHe = heCandidate->next;
        else if (onEdgeFlag == 2) flaggedHe = heCandidate->next->next;
        if (flaggedHe->data > 0) {
          found = false;
          heCandidate = flaggedHe;
        }
      }
      std::vector<PolyMesh::HalfEdge *> _touched;
      if (heCandidate && found){ // this means it is NOT a constrained edge
        pm->split_triangle(-1, cc[0], cc[1], cc[2], heCandidate->f, delaunayCriterionColors, nullptr, &_touched);
      }
      else { // this means it is a constrained edge
        SVector3 p = 0.5*(heCandidate->v->position + heCandidate->next->v->position);
        cc.setPosition(p.x(), p.y(), p.z());
        if ( heCandidate->opposite){
          pm->split_edge(heCandidate, cc, -1);
          // int heData = heCandidate->data;
          int heData = bndTag;
          heCandidate->next->opposite->f->data = heCandidate->f->data;
          heCandidate->opposite->f->data = heCandidate->next->opposite->next->opposite->f->data;
          heCandidate->data = heData; // constrain them again
          heCandidate->opposite->data = heData; // constrain them again
          heCandidate->next->opposite->next->data = heData; // constrain them again
          heCandidate->next->opposite->next->opposite->data = heData; // constrain them again
          std::vector<PolyMesh::HalfEdge *> new_hes;
          new_hes.push_back(heCandidate);
          new_hes.push_back(heCandidate->next);
          new_hes.push_back(heCandidate->next->next);
          new_hes.push_back(heCandidate->next->opposite);
          new_hes.push_back(heCandidate->next->opposite->next);
          new_hes.push_back(heCandidate->next->opposite->next->next);
          _delaunayCheckColors(pm, new_hes, &_touched);
        }
        SVector3 dist = cc-heCandidate->v->position;
        std::vector<PolyMesh::Vertex *> closeVertices;
        getVerticesWithinRadius(pm, pm->vertices.back(), dist.norm(), &closeVertices);
        if (closeVertices.size() > 0){
          _touched.clear();
          for (auto vv : closeVertices){
            std::vector<PolyMesh::HalfEdge *> _tlocal;
            std::vector<PolyMesh::HalfEdge *> _nhes;
            if (vv->he->f->data == tag && pm->degree(vv) > 0 && !boundaryCheck(pm, vv)) {
              _deleteVertex(pm, vv, &_nhes);
            }
            _delaunayCheckColors(pm, _nhes, &_tlocal);
            _touched.insert(_touched.end(), _tlocal.begin(), _tlocal.end());
          }
          for(auto face_it = _badFaces.begin() ; face_it != _badFaces.end(); face_it++)
            if (!(*face_it)->he) _badFaces.erase(face_it--);
        }
      }
      PolyMesh::Vertex* v = pm->vertices.back();
      v->data = newTag++;
      sizeAtNodes[v->data] = field->operator()(v->position.x(), v->position.y(), 0, NULL);
      std::vector<PolyMesh::Face *> _newFaces;
      for(auto _h : _touched){
          if(_h->f && _h->f->he != nullptr && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
            _newFaces.push_back(_h->f);
      }
      for(auto pf : _newFaces) {
        double q, R, s;
        SPoint3 cc;
        faceInfo(pf->he, cc, &R, &q);
        s = _faceSizeFromMap(pf->he, sizeAtNodes);
        auto it = std::find(_badFaces.begin(), _badFaces.end(), pf); 
        if(it != _badFaces.end()) { 
          _badFaces.erase(it);
        }
        if((q < _limit && R/s > _sizeMinFactor) || R/s > _size){
          insert_sorted(_badFaces, pf, faceCompareFct);
        }
      }
    }
  }
}

void AlphaShape::_createBoundaryOctree(const std::string & boundaryModel, const int bndTag, OctreeNode<2, 32, alphaShapeBndEdge*>& octree, std::vector<alphaShapeBndEdge>& bndEdges){
    GModel* gm_alphaShape = GModel::current();
    GModel* gm_boundary = GModel::findByName(boundaryModel);
    if (gm_boundary == nullptr) {
      Msg::Error("Boundary model not found");
      return;
    }
    BBox<2> bbox;
    std::vector<GEntity*> bndEntities;
    gm_boundary->getEntities(bndEntities, 1); 
    // std::unordered_set<MVertex*> gVertices;
    bndEdges.clear();
    for (auto e : bndEntities){
      size_t n_elem = e->getNumMeshElements();
      for (size_t i_el = 0; i_el<n_elem; i_el++){
        MElement *elem = e->getMeshElement(i_el);
        if(elem->getDim() != 1) continue;
        alphaShapeBndEdge bd = {elem->getVertex(0)->x(), elem->getVertex(0)->y(), elem->getVertex(1)->x(), elem->getVertex(1)->y(), e->tag()};
        bndEdges.push_back(bd);
        bbox.extends({bd.x0, bd.y0});
        bbox.extends({bd.x1, bd.y1});
      }
    }
    bbox*=1.1;
    octree.set_bbox(bbox);
    // OctreeNode<2, 32, alphaShapeBndEdge*> octree(bbox);
    for (auto &ed : bndEdges){
      BBox<2> ed_bbox;
      ed_bbox.extends({ed.x0, ed.y0});
      ed_bbox.extends({ed.x1, ed.y1});
      octree.add(&ed, ed_bbox);
    }
    gm_alphaShape->setAsCurrent();
    // return &octree;
}

void AlphaShape::filterNodes(PolyMesh *pm, const int tag) {
  for (auto v : pm->vertices){
    if (v->he == nullptr || !checkVertexConnection(pm, v, tag)) {
      v->data = -1;
    }
  }
}

static std::pair<double, double> projectPointOnSegment(SPoint2 p, SPoint2 a, SPoint2 b){
  SPoint2 ab = b-a;
  SPoint2 ap = p-a;
  double t = dot(ap, ab)/dot(ab, ab);
  if (t < 0) t = 0;
  if (t > 1) t = 1;
  SPoint2 proj(a.x() + t*ab.x(), a.y() + t*ab.y());
  double dist = hypot(p.x()-proj.x(), p.y()-proj.y());
  return std::make_pair(dist, t);
}

void AlphaShape::getNewNodesOnOldMesh(PolyMesh *pm, ElementOctree &octree_prev, std::vector<size_t> &newNodeTags, std::vector<size_t> &elementTags, std::vector<double> &parametricCoords) {
  std::vector<MElement*> candidates;
  double hmean = 0;
  size_t nh = 0;
  for (auto he : pm->hedges){
    if (he->data == -1) continue;
    double d = norm(he->v->position - he->next->v->position);
    hmean += d;
    nh ++;
  }
  hmean /= nh;
  for (auto v : pm->vertices) {
    if (v->data == -1) continue;
    newNodeTags.push_back(v->data);
    BBox<2> search_bbox;
    search_bbox.extends({v->position.x(), v->position.y()});
    candidates.clear();
    octree_prev.search(search_bbox, candidates);
    bool found = false;
    for (auto elem : candidates){
      double uvw[3];
      elem->xyz2uvw(v->position, uvw);
      if (elem->isInside(uvw[0], uvw[1], uvw[2])){
        found = true;
        elementTags.push_back(elem->getNum());
        parametricCoords.push_back(uvw[0]);
        parametricCoords.push_back(uvw[1]);
        parametricCoords.push_back(uvw[2]);
        break;
      }
    }
    double tol = hmean;
    while (!found) {
      candidates.clear();
      search_bbox.extends({v->position.x()+tol, v->position.y()+tol});
      search_bbox.extends({v->position.x()-tol, v->position.y()-tol});
      octree_prev.search(search_bbox, candidates);
      double dmin = std::numeric_limits<double>::max();
      size_t etag = 0;
      double xi, eta;
      for (auto elem : candidates) {
        for (int i = 0; i < 3; ++i) {
          SPoint2 a(elem->getVertex(i)->x(), elem->getVertex(i)->y());
          SPoint2 b(elem->getVertex((i+1)%3)->x(), elem->getVertex((i+1)%3)->y());
          SPoint2 p(v->position.x(), v->position.y());
          double d, t;
          std::tie(d, t) = projectPointOnSegment(p, a, b);
          if (d < dmin) {
            dmin = d;
            found = true;
            etag = elem->getNum();
            if (i == 0) {
              xi = t;
              eta = 0;
            }
            else if (i == 1) {
              xi = 1-t;
              eta = t;
            }
            else {
              xi = 0;
              eta = 1-t;
            }
          }
        }
      }
      if (found) {
        elementTags.push_back(etag);
        parametricCoords.push_back(xi);
        parametricCoords.push_back(eta);
        parametricCoords.push_back(0);
      }
      tol *= 2;
    }
  }
}

void AlphaShape::alphaShapePolyMesh2Gmsh(PolyMesh* pm, const int tag, const int bndTag, const std::string & boundaryModel, OctreeNode<2, 32, alphaShapeBndEdge*> &octree, const double boundary_tol){
  // std::vector<std::pair<int, int>> dimTag;
  // dimTag.push_back(std::make_pair(2, tag));

  // color the boundary edges with the solid geometry
  GModel* gm_alphaShape = GModel::current();
  GModel* gm_boundary = GModel::findByName(boundaryModel);
  if (gm_boundary == nullptr) {
    Msg::Error("Boundary model not found");
    return;
  }

  std::vector<alphaShapeBndEdge*> result;
  std::set<int> resultTags0;
  std::set<int> resultTags1;
  std::set<int> intersection;
  // double boundary_tol = 1e-5;
  std::unordered_map<int, std::vector<size_t>> bndMap;
  bndMap[bndTag] = std::vector<size_t>();
  for (auto he : pm->hedges){
    if (he->data < 0 || he->f == nullptr || he->f->data != tag) continue;
    if (he->f->data == tag && he->opposite->f->data == tag){
      he->data = -1;
      continue;
    }
    if (he->v->data == -1 || he->next->v->data == -1){
      printf("oh oh... data of v = -1 \n");
      //print4debug(pm, 10);
      exit(0);
    }
    // if (bndMap.find(he->data) == bndMap.end()) bndMap[he->data] = std::vector<size_t>();
    resultTags0.clear();
    resultTags1.clear();
    intersection.clear();
    BBox<2> search_bbox;
    // search_bbox.extends({he->v->position.x(), he->v->position.y()});
    search_bbox.extends({he->v->position.x()+boundary_tol, he->v->position.y()+boundary_tol});
    search_bbox.extends({he->v->position.x()-boundary_tol, he->v->position.y()-boundary_tol});
    // search_bbox*=(1+boundary_tol);
    result.clear();
    octree.search(search_bbox, result);
    if (result.size() == 0){  // free surface!!!
      bndMap[bndTag].push_back(he->v->data);
      bndMap[bndTag].push_back(he->next->v->data); 
      he->data = bndTag; 
      continue;
    }
    for (auto &ed : result){
      SVector3 a(ed->x0, ed->y0, 0);
      SVector3 b(ed->x1, ed->y1, 0);
      if (distPointSegment(he->v->position, a, b) < boundary_tol)
        resultTags0.insert(ed->tag);
    }
    BBox<2> search_bbox1;
    // search_bbox1.extends({he->next->v->position.x(), he->next->v->position.y()});
    search_bbox1.extends({he->next->v->position.x()+boundary_tol, he->next->v->position.y()+boundary_tol});
    search_bbox1.extends({he->next->v->position.x()-boundary_tol, he->next->v->position.y()-boundary_tol});
    // search_bbox1*=(1+boundary_tol);
    result.clear();
    octree.search(search_bbox1, result);
    if (result.size() == 0){ // free surface!!!
      bndMap[bndTag].push_back(he->v->data);
      bndMap[bndTag].push_back(he->next->v->data);
      he->data = bndTag; 
      continue; 
    }
    for (auto &ed : result){
      SVector3 a(ed->x0, ed->y0, 0);
      SVector3 b(ed->x1, ed->y1, 0);
      if (distPointSegment(he->next->v->position, a, b) < boundary_tol)
        resultTags1.insert(ed->tag);
    }
    std::set_intersection(resultTags0.begin(), resultTags0.end(), resultTags1.begin(), resultTags1.end(), std::inserter(intersection, intersection.begin()));
    if (intersection.size() == 1){
      bndMap[*intersection.begin()].push_back(he->v->data);
      bndMap[*intersection.begin()].push_back(he->next->v->data);
      he->data = *intersection.begin();
    }
    else {
      bndMap[bndTag].push_back(he->v->data);
      bndMap[bndTag].push_back(he->next->v->data); 
      he->data = bndTag; 
    }
  }

  gm_alphaShape->deleteMesh();
  std::vector<size_t> nodeTags;
  std::vector<double> coords;
  for (auto v : pm->vertices){
    if (v->data == -1) continue;
    coords.push_back(v->position.x());
    coords.push_back(v->position.y());
    coords.push_back(v->position.z());
    nodeTags.push_back(size_t(v->data));
  }
  gmsh::model::mesh::addNodes(2, tag, nodeTags, coords);
  // printf("nodes added to gsmh \n");
  std::vector<size_t> edTags;
  for (auto bnd : bndMap){
    gmsh::model::mesh::addElementsByType(bnd.first, 1, edTags, bnd.second);
  }
  // printf("boundary edges added to gsmh \n");

  std::vector<size_t> triangles, triangleTag;
  for (auto f : pm->faces){
    if (f->he == nullptr || f->data != tag) continue;
    int triangle[3] = {f->he->v->data, f->he->next->v->data, f->he->next->next->v->data};
    if (triangle[0] == -1 || triangle[1] == -1 || triangle[2] == -1) continue;
    for (auto n : triangle) triangles.push_back(size_t(n));
  }
  gmsh::model::mesh::addElementsByType(tag, 2, triangleTag, triangles);
  // printf("triangles added to gsmh \n");
  delete pm;
  gm_alphaShape->setAsCurrent();
}

void AlphaShape::_moveNodes(const int tag, const int freeSurfaceTag, const std::vector<size_t> & nodeTags, const std::vector<double> & nodesDx, OctreeNode<2, 32, alphaShapeBndEdge*> &bnd_octree, double boundary_tol){
  // check if size of nodesDx is the same as the number of nodes
  GModel* gm = GModel::current();
  GFace* gf = gm->getFaceByTag(tag);
  if (gf->getNumMeshVertices() != nodesDx.size()/3){
    Msg::Error("size of nodesDX does not match the number of nodes in the mesh");
    return;
  }

  // 1. keep boundary nodes on the boundary
  std::unordered_set<MVertex*> boundaryNodesSet;
  std::vector<GEntity*> bndEntities;
  gm->getEntities(bndEntities, 1);
  for (auto ge : bndEntities){
    if (ge->tag() == freeSurfaceTag) continue;
    std::vector<std::size_t> edges;
    std::vector<std::size_t> edgeTags;
    for (size_t i=0; i<ge->getNumMeshElements(); i++){
      MElement* elem = ge->getMeshElement(i);
      boundaryNodesSet.insert(elem->getVertex(0));
      boundaryNodesSet.insert(elem->getVertex(1));
    }
  }

  std::unordered_set<size_t> projectedControlNodes;
  for (size_t i=0; i<gf->getNumMeshVertices(); i++){
    // MVertex* v = gf->getMeshVertex(i);
    MVertex* v = gm->getMeshVertexByTag(nodeTags[i]);
    bool intersect = false;
    SVector3 x0(v->point());
    SVector3 dx(nodesDx[3*i], nodesDx[3*i+1], nodesDx[3*i+2]);
    SVector3 x1 = x0 + dx;
    // We check if it is a boundary node -> if yes, it is forced to stay on the boundary
    SVector3 x1_projected;
    if (boundaryNodesSet.find(v) != boundaryNodesSet.end()) {
      BBox<2> bbox;
      bbox.extends({x1[0]-1.5*dx[0]-boundary_tol, x1[1]-1.5*dx[1]-boundary_tol});
      bbox.extends({x1[0]+1.5*dx[0]+boundary_tol, x1[1]+1.5*dx[1]+boundary_tol});
      bbox.extends({x1[0]-1.5*dx[0]+boundary_tol, x1[1]-1.5*dx[1]+boundary_tol});
      bbox.extends({x1[0]+1.5*dx[0]-boundary_tol, x1[1]+1.5*dx[1]-boundary_tol});
      // std::vector<const Mesh::Vertex*> vertices;
      std::vector<alphaShapeBndEdge *> edges;
      double t=0.;
      
      // First, we test if the node is close to a control node, i.e. a geometric node
      // If this is the case, we move the node to the control node
      
      // TODO !!!
      
      // octree_nodes.search(bbox, vertices);
      // if (vertices.size() == 1){
      //     if (projectedControlNodes.find(vertices[0]->tag) == projectedControlNodes.end()){
      //         projectedControlNodes.insert(vertices[0]->tag);
      //         newCoords[3*i+0] = vertices[0]->x[0];
      //         newCoords[3*i+1] = vertices[0]->x[1];
      //         newCoords[3*i+2] = 0.;
      //         intersect = true;
      //     }
      // }

      if (!intersect){
        bnd_octree.search(bbox, edges);
        double minDist = 1e10;
        double norm;
        for (auto edge : edges) {
          double x2[2] = {edge->x0, edge->y0};
          double x3[2] = {edge->x1, edge->y1};
          double x2x1[2] = {x1[0]-x2[0], x1[1]-x2[1]};
          double x2x3[2] = {x3[0]-x2[0], x3[1]-x2[1]};
          double dot = x2x1[0]*x2x3[0] + x2x1[1]*x2x3[1];
          norm = x2x3[0]*x2x3[0] + x2x3[1]*x2x3[1];
          t = dot/norm;
          double nx[2];
          double dist;
          if(t > 0 && t < 1){
            nx[0] = x2[0]+t*x2x3[0];
            nx[1] = x2[1]+t*x2x3[1];
          }
          else if (t <= 0){
            nx[0] = x2[0];
            nx[1] = x2[1];
          }
          else if (t >= 1){
            nx[0] = x3[0];
            nx[1] = x3[1];
          }
          dist = (nx[0]-x1[0])*(nx[0]-x1[0]) + (nx[1]-x1[1])*(nx[1]-x1[1]);
          if (dist < minDist){
            x1_projected[0] = nx[0];
            x1_projected[1] = nx[1];
            x1_projected[2] = 0.;
            intersect = true;
            minDist = dist;
          }
        }
      }
      if (!intersect){
          Msg::Warning("No intersection found for boundary node %zu (%.15f, %.15f) -> (%.15f, %.15f) (norm = %.15e) (size of edges : %lu) (t = %.15f) \n", v->getNum(), x0[0], x0[1], x1[0], x1[1], sqrt((x1[0]-x0[0])*(x1[0]-x0[0]) + (x1[1]-x0[1])*(x1[1]-x0[1])), edges.size(), t);
      }
    }
    else {
      std::vector<alphaShapeBndEdge *> edges;
      BBox<2> bbox;
      bbox.extends({x0[0], x0[1]});
      bbox.extends({x1[0], x1[1]});
      bnd_octree.search(bbox, edges);
      for (auto edge : edges) {
        double a1[2] = {edge->x0, edge->y0};
        double a2[2] = {edge->x1, edge->y1};
        double a143 = robustPredicates::orient2d(a1,x1,x0);
        double a243 = robustPredicates::orient2d(a2,x1,x0);    
        double a123 = robustPredicates::orient2d(a1,a2,x0);
        double a124 = robustPredicates::orient2d(a1,a2,x1);
        if (a143*a243 < 0 && a123*a124 < 0){
          double t = fabs(a143)/(fabs(a143)+fabs(a243));
          double vec[2] = {a2[0]-a1[0], a2[1]-a1[1]};
          double new_intersection[2] = {a1[0]+t*vec[0], a1[1]+t*vec[1]};
          x1_projected[0] = new_intersection[0];
          x1_projected[1] = new_intersection[1];
          x1_projected[2] = 0.;
          intersect = true;
          // printf("node %zu intersects but is not boundary \n", v->getNum());
          break;
        }
      }
    }
    if (intersect) {
        x1 = x1_projected;
    }
    // printf("moving node %zu from (%.15f, %.15f) to (%.15f, %.15f) (dx was : %.15f, %.15f) \n", v->getNum(), x0[0], x0[1], x1[0], x1[1], dx[0], dx[1]);
    v->setXYZ(x1[0], x1[1], x1[2]);
  }
}


#endif
