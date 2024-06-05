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
#include "omp.h"

#include <time.h>
#include <ctime>
#include <chrono>
#include <iostream>
#include <unordered_set>
#include "robin_hood.h"
#include "BackgroundMeshTools.h"
#include "alphaShape_ocTree2.h"
#include "Field.h"
#include "SPoint3KDTree.h"

extern "C" {
#include "libol1.h"
}

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
static int _outwardFaces [4][3] = {{0,2,1}, {0,1,3}, {0,3,2}, {1,2,3}};

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
  // printf("in qualityFunForOptimize\n");
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
  // printf("broke here ? %f\n", hMean/R);
  return hMean/R;
}



void _computeAlphaShape3D(const std::vector<int> & alphaShapeTags, const double alpha, const double hMean,
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
      .colorIn = alphaShapeTags[0],
      .colorOut = 1,
      .colorBoundary = alphaShapeTags[1],
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
  for (int i=0; i<alphaShapeOptions.n_boundaryFacets; i++){
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
    printf("here0000 \n");
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
    for (int i=0; i<mesh->tetrahedra.num; i++){
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
  for (int i=0; i<mesh->triangles.num; i++){
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
  for (int i=0; i<mesh->tetrahedra.num; i++){
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


void generateMesh_(const int dim, const int tag, const bool refine, const std::vector<double> &coord, const std::vector<size_t> &nodeTags){
  // -----------------  1D ------------------------------
  std::vector<double> pCoord;
  gmsh::model::getParametrization(dim, tag, coord, pCoord);
  if (dim == 1){
    Msg::Info("generating mesh for edge %d\n",tag);
    std::for_each(GModel::current()->firstRegion(), GModel::current()->lastRegion(), deMeshGRegion());
    std::for_each(GModel::current()->firstFace(), GModel::current()->lastFace(), deMeshGFace());
    deMeshGEdge killer;
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if (!ge)return;
    killer(ge);
    std::vector<int> index(pCoord.size(), 0);
    for (size_t i = 0 ; i != index.size() ; i++) {
      index[i] = i;
    }
    sort(index.begin(), index.end(), [&](const int& a, const int& b) { return (pCoord[a] < pCoord[b]);});
    MVertex *vBegin = ge->getBeginVertex()->mesh_vertices[0];
    MVertex *vEnd = ge->getEndVertex()->mesh_vertices[0];
    int numInsertions = 0;
    for (auto t : index){
      GPoint gp = ge->point(pCoord[t]);
      MVertex *vPrev = (numInsertions == 0) ? ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices.back();
      MEdgeVertex *vv = new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, pCoord[t], nodeTags[t]);
      if (vv->point().distance(vPrev->point()) < 1e-6 || vv->point().distance(vEnd->point()) < 1e-6 || vv->point().distance(vBegin->point()) < 1e-6) {
        Msg::Warning("ignoring insertion of node %d too close to another node \n", nodeTags[t]);
        continue;
      }
      ge->mesh_vertices.push_back(vv);   
      numInsertions++;
    }
    int lineCount = 1;
    for(std::size_t i = 0; i < ge->mesh_vertices.size() + 1; i++) {
      MVertex *v0 = (i == 0) ? ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices[i - 1];
      MVertex *v1 = (i == ge->mesh_vertices.size()) ? ge->getEndVertex()->mesh_vertices[0] : ge->mesh_vertices[i];
      ge->lines.push_back(new MLine(v0, v1));
      lineCount++;
    }
  }
  // -----------------  2D ------------------------------
  else if (dim == 2){
    // Msg::Info("generating surface mesh for face %d\n",tag);
    deMeshGFace killer;
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if (!gf)return;
    killer(gf);

    std::vector<double> cc = pCoord;
    PolyMesh *pm = GFaceInitialMesh(tag, 1, &cc);
    // //print4debug(pm, 1000);
    std::vector<GEdge*> ed = gf->edges();
    std::unordered_map<int,MVertex*> vs;
    size_t vmax = 0;
    
    for (auto e : ed){
      for (auto l : e->lines){
        vs[l->getVertex(0)->getNum()] = l->getVertex(0);
        vs[l->getVertex(1)->getNum()] = l->getVertex(1);
        if (l->getVertex(0)->getNum() > vmax) vmax=l->getVertex(0)->getNum();
        if (l->getVertex(1)->getNum() > vmax) vmax=l->getVertex(1)->getNum();
      }
    }

    size_t idx = 0;
    for(size_t i = 4; i < pm->vertices.size() ; i++) {
      PolyMesh::Vertex *v = pm->vertices[i];
      if (v->data == -1){
	      //v->data = ++vmax;
        v->data = nodeTags[idx];
        idx++;
      }
    }
    int triCount = 1;
    for(size_t i = 0; i < pm->faces.size(); i++) {
      if (pm->faces[i]->data != tag) continue;
      PolyMesh::HalfEdge *he = pm->faces[i]->he;
      int a = he->v->data;
      int b = he->next->v->data;
      int c = he->next->next->v->data;
      if (a != -1 && b != -1 && c != -1){
        MVertex *va,*vb,*vc;
        std::unordered_map<int,MVertex*>::iterator ita = vs.find(a);
        std::unordered_map<int,MVertex*>::iterator itb = vs.find(b);
        std::unordered_map<int,MVertex*>::iterator itc = vs.find(c);
        if (ita != vs.end())va = ita->second;
        else{
          GPoint gp = gf->point(he->v->position.x(),he->v->position.y());
          va = new MFaceVertex (gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v(),he->v->data);
          gf->mesh_vertices.push_back(va);
          vs[a] = va;
        }
        if (itb != vs.end())vb = itb->second;
        else{
          GPoint gp = gf->point(he->next->v->position.x(),he->next->v->position.y());
          vb = new MFaceVertex (gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v(),he->next->v->data);
          gf->mesh_vertices.push_back(vb);
          vs[b] = vb;
        }
        if (itc != vs.end())vc = itc->second;
        else{
          GPoint gp = gf->point(he->next->next->v->position.x(),he->next->next->v->position.y());
          vc = new MFaceVertex (gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v(),he->next->next->v->data);
          gf->mesh_vertices.push_back(vc);
          vs[c] = vc;
        }
	      gf->triangles.push_back(new MTriangle(va,vb,vc));
        triCount++;
      }
    }
    // gmsh::fltk::run();
    // pm->print4debug(tag);
    delete pm;
  }
  // -----------------  3D ------------------------------
  else if (dim == 3){
    generateMesh3D_(coord, nodeTags);
  }
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

void print4debug(PolyMesh* pm, const int debugTag)
  {
    char name[256];
    sprintf(name, "polyMesh%d.pos", debugTag);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \" %s \"{\n", name);
    for(auto it : pm->faces) {
      if (it->data == -2) continue;
      if (it->he){
        PolyMesh::HalfEdge *he0 = it->he;
        PolyMesh::HalfEdge *he1 = it->he->next;
        PolyMesh::HalfEdge *he2 = it->he->next->next;
        // double cy[3], Ry;
        // faceCircumCenter(it->he, cy, &Ry);
        fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%d,%d,%d};\n",
                he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
                he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
                it->data, it->data, it->data);
        // fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%f,%f,%f};\n",
        //         he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
        //         he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
        //         Ry, Ry, Ry);
      }
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

static double faceSize(PolyMesh::HalfEdge *he, std::vector<double>& i2Size){
  return 1./3.* (i2Size[abs(he->v->data)] + i2Size[abs(he->next->v->data)] + i2Size[abs(he->next->next->v->data)]);
}

PolyMesh::Vertex* findVertex(PolyMesh* pm, size_t num){
  size_t i = 0;
  while(i < pm->vertices.size()){
    if (pm->vertices[i]->data == (int)num) return pm->vertices[i];
    i+=1;
  }
  return nullptr;
}

void Walk(PolyMesh::Face *f, double* cc, PolyMesh::HalfEdge** heCandidate, bool* found)
{
  // heCandidate = nullptr;
  double POS[2] = {cc[0], cc[1]};
  PolyMesh::HalfEdge *he = f->he;
  bool cont = true;
  while(cont) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = robustPredicates::orient2d(v2->position, v0->position, POS);

    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      *heCandidate = he;
      *found = true;
      cont = false;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0){
      if (he->data < 0)
        he = he->opposite;
      else {
        *heCandidate = he;
        *found = false;
        cont = false;
      }
    }
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0){
      if (he->next->data < 0)
        he = he->next->opposite;
      else {
        *heCandidate = he->next;
        *found = false;
        cont = false;
      }
    }
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0){
      if (he->next->next->data < 0)
        he = he->next->next->opposite;
      else {
        *heCandidate = he->next->next;
        *found = false;
        cont = false;
      }
    }
    else if(s0 <= 0 && s1 <= 0){
      // he = s0 > s1 ? he->opposite : he->next->opposite;
      if (s0 > s1){
        if (he->data < 0)
          he = he->opposite;
        else {
          *heCandidate = he;
          *found = false;
          cont = false;
        }
      }
      else{
        if (he->next->data < 0)
          he = he->next->opposite;
        else {
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
      }
    }
    else if(s0 <= 0 && s2 <= 0){
      if (s0 > s2){
        if (he->data < 0)
          he = he->opposite;
        else {
          *heCandidate = he;
          *found = false;
          cont = false;
        }
      }
      else {
        if (he->next->next->data < 0)
          he = he->next->next->opposite;
        else {
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
      }
    }
    else if(s1 <= 0 && s2 <= 0){
      if (s1 > s2){
        if(he->next->data < 0)
          he = he->next->opposite;
        else {
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
      }
      else {
        if(he->next->next->data < 0)
          he = he->next->next->opposite;
        else {
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
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

static int delaunayEdgeCriterionPlaneIsotropic(PolyMesh::HalfEdge *he, void *)
{
  if(he->f == nullptr) return -1;
  if(he->opposite == nullptr) return -1;
  if(he->data > -1) return 0;
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;
  // FIXME : should be oriented anyway !
  double result = robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);
  return (result > 0) ? 1 : 0;
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

void delaunayCheck(PolyMesh* pm, std::vector<PolyMesh::HalfEdge* > hes, std::vector<PolyMesh::HalfEdge* > *_t){
  std::stack<PolyMesh::HalfEdge *> _stack;
  for (auto he : hes) _stack.push(he);
  std::vector<PolyMesh::HalfEdge *> _touched;
  while(!_stack.empty()) {
    PolyMesh::HalfEdge *he = _stack.top();
    _touched.push_back(he);
    _stack.pop();
    if(delaunayEdgeCriterionPlaneIsotropic(he, NULL) == 1) {
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

 bool freeSurfaceCheck(PolyMesh* pm, PolyMesh::Vertex* v, int tag){
  PolyMesh::HalfEdge *he = v->he;
  if(he->data == tag) return true;
  do {
    he = he->opposite;
    if(he == nullptr) return true;
    he = he->next;
    if(he->data == tag) return true;
  } while(he != v->he);
  return false;
 }
 PolyMesh::HalfEdge* getNextEdgeOnFreeSurface(PolyMesh::HalfEdge* he){
  if (he->data != 0) return nullptr;
  if (he->next->data == 0) return he->next;
  PolyMesh::HalfEdge* _he = he->next;
  do {
    if (_he->opposite) _he = _he->opposite->next;
    else return nullptr;
    if (_he->data == 0) return _he;
  } while (_he != he);
  return nullptr;
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


// typename std::vector<PolyMesh::Face *>::iterator insert_sorted( std::vector<PolyMesh::Face *> & vec, PolyMesh::Face* item){
//     return vec.insert(std::upper_bound( vec.begin(), vec.end(), item, faceCompareFct), item);
// }

void constrainedDelaunayRefinement_(const int dim, const int tag,
                                    const std::vector<size_t> &elementTags,
                                    const std::vector<size_t> &constrainedEdges,
                                    const std::vector<size_t> &nodeTags,
                                    const std::vector<double> &sizeAtNodes, 
                                    const double minRadius, 
                                    const double minQuality,
                                    std::vector<size_t> &newNodeTags, 
                                    std::vector<double>& newCoords, 
                                    std::vector<double>& newsizeAtNodes, 
                                    std::vector<std::vector<size_t>>& newConstrainedEdges, 
                                    std::vector<size_t>& newElementsInRefinement){
  if (dim == 2){
    // auto t0 = std::chrono::steady_clock::now(); 
    bool globalSize = sizeAtNodes.size() == 1;
    GModel* gm = GModel::current();
    double surfaceConstraint = 0.5;
    GFace* gf = gm->getFaceByTag(tag);
    std::vector<std::pair<int, int> > bndDimTags;
    std::pair<int, int> dimTag = {dim, tag};
    std::vector<std::pair<int,int>> dimTags;
    dimTags.push_back(dimTag);
    gm->getBoundaryTags(dimTags, bndDimTags, true);

    std::vector<double> cc;
    std::vector<size_t> vTags;
    PolyMesh* pm;
    GFace2PolyMesh(tag, &pm);
    // Set the data of faces to -1 (is changed afterwards for the faces that we want to be improved.)
    // Recognise which are the faces to refine -> data at these faces is the gmsh face tag, else -1
    // auto t0p = std::chrono::steady_clock::now(); 
    std::vector<size_t> allElements;
    std::vector<size_t> allElementNodeTags;
    gmsh::model::mesh::getElementsByType(2, allElements, allElementNodeTags, tag);
    std::set<size_t> elsSet(elementTags.begin(), elementTags.end());
    for (size_t i=0; i<pm->faces.size(); i++){
      if (elsSet.find(allElements[i]) != elsSet.end())
        pm->faces[i]->data = 1;
      else
        pm->faces[i]->data = -1;
    }

    // auto t00p = std::chrono::steady_clock::now(); 
    // create a map from vertex to edge tag
    std::unordered_map <size_t, int> v2b;
    for (auto dt : bndDimTags){
      GEdge *ge = GModel::current()->getEdgeByTag(dt.second);
      v2b[ge->getBeginVertex()->mesh_vertices[0]->getNum()] = dt.second;
      for(std::size_t i = 0; i < ge->mesh_vertices.size(); i++) {
        v2b[ge->mesh_vertices[i]->getNum()] = dt.second;
      }
    }
    // auto t0pp = std::chrono::steady_clock::now(); 

    // Get and color the constrained half edges : the ones inside the domain get data 0
    for (size_t ed=0; ed < constrainedEdges.size(); ed+=2){
        PolyMesh::Vertex* v0 = findVertex(pm, constrainedEdges[ed]);
        PolyMesh::Vertex* v1 = findVertex(pm, constrainedEdges[ed+1]);
        PolyMesh::HalfEdge* he = pm->getEdgeWithBnd(v0, v1);
        he->data = 0; 
    }

    // also constrain the boundary edges : they get the tag of the bounding edge they belong to
    for (auto he : pm->hedges){
      if (!he->opposite){
        std::unordered_map<size_t, int>::iterator it = v2b.find(he->v->data);
        if (it != v2b.end())
          he->data = it->second;
        else{
          Msg::Error("There is an issue with a boundary edge");
        }
      }
    }
    // auto t0ppp = std::chrono::steady_clock::now(); 
    // Change the data of each vertex to its index in the list, and keep track of the nodetags 
    std::unordered_map<int, double> v2sizeAtNodes;
    std::vector<int> i2g;
    std::vector<double> i2Size;
    for (size_t i=0; i<nodeTags.size(); i++){
      v2sizeAtNodes[nodeTags[i]] = (globalSize == 1) ? sizeAtNodes[0] : sizeAtNodes[i];
    }
    for (size_t i=0; i<pm->vertices.size(); i++){
      PolyMesh::Vertex* v = pm->vertices[i];
      i2g.push_back(v->data);
      i2Size.push_back(v2sizeAtNodes[v->data]);
      v->data = i;
    }
    // auto t1 = std::chrono::steady_clock::now(); 
    // Step 2: coarsen the mesh -> collapse edges that are too small
    std::vector<PolyMesh::HalfEdge *> heVector;
    for (auto he : pm->hedges) heVector.push_back(he);
    int i_delete = 0;
    std::sort(heVector.begin(), heVector.end(), he_size());
    std::deque<PolyMesh::HalfEdge *> heQue(heVector.begin(), heVector.end());
    // double t_ifCheck=0;
    // double t_if2Check=0;
    // double t_emptyCheck=0;
    // auto t2 = std::chrono::steady_clock::now(); 
    while (!heQue.empty()){
      PolyMesh::HalfEdge *he = *heQue.begin();
      heQue.pop_front();
      if (he == nullptr || he->v == nullptr || he->f == nullptr || he->f->data == -1 || he->data > -1 || pm->degree(he->v) < 0 || freeSurfaceCheck(pm, he->v, 0)) continue;
      double d = norm(he->v->position - he->next->v->position);
      double size = (globalSize == 1) ? sizeAtNodes[0] : 0.5*(i2Size[abs(he->v->data)] + i2Size[abs(he->next->v->data)]);
      // MVertex *vPrev = (numInsertions == 0) ? ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices.back();
      
      if (d < 0.5*size){
        std::vector<PolyMesh::HalfEdge *> _nhes;
        std::vector<PolyMesh::HalfEdge* > _t;
        if (pm->checkHedgeCompatibility(he)){
          pm->hedgeCollapse(he, &_nhes);
          delaunayCheck(pm, _nhes, &_t);  
          for (auto _he : _t) heQue.push_back(_he);
          i_delete++;
        }
      }
    }
    
    std::vector<PolyMesh::HalfEdge* > hes;
    for (auto he : pm->hedges){
      if (he->f)
        hes.push_back(he);
    }

    auto it_min = min_element(sizeAtNodes.begin(), sizeAtNodes.end()); // to restrict elements even more if all the nodes have minimum size field
    double minSize = *it_min;

    // auto t3 = std::chrono::steady_clock::now(); 
    // The initial mesh has been created; now we need to insert nodes such that the size field is respected.
    // Step 3: get the elements that do not respect the size or quality constraint
    std::vector<PolyMesh::Face *> _badFaces;
    double _limit = minQuality;
    double _size = 1.;
    for(auto f : pm->faces) {
      if (f->he && f->data != -1){
        double q;
        SPoint3 cc;
        double R;
        faceInfo(f->he, cc, &R, &q);
        double s;
        if (!globalSize){
          s = faceSize(f->he, i2Size);
          if (abs(s-minSize)/minSize < 1e-2){
            s *= surfaceConstraint;
          }
        }
        else 
          s = sizeAtNodes[0];
        if((q < _limit || R/s > _size) && R > minRadius) insert_sorted(_badFaces, f, faceCompareFct);
      }
    }
    size_t newIdx = gm->getMaxVertexNumber()+1;
    size_t addFrom = pm->vertices.size();

    // Step 4: loop over faces to insert nodes where necessary
    while (!_badFaces.empty()){
      PolyMesh::Face *f = _badFaces.back();
      if (f->he == nullptr) {
        _badFaces.erase(_badFaces.end()-1);
        continue;
      }
      double q;
      SPoint3 cc;
      double R;
      faceInfo(f->he, cc, &R, &q); // NB : q = 2*rho / R
      double s;
      _badFaces.erase(_badFaces.end()-1);
      if (!globalSize){
        s = faceSize(f->he, i2Size);
        if (abs(s-minSize)/minSize < 1e-2){
          s *= surfaceConstraint;
        }
      }
      else 
        s = sizeAtNodes[0];
      if((q < _limit || R/s > _size) && (R > minRadius && f->data != -1)){
          PolyMesh::HalfEdge* heCandidate = nullptr;
          bool found;
          // print4debug(pm, newIdx+1000);
          Walk(f, cc, &heCandidate, &found);
          std::vector<PolyMesh::HalfEdge *> _touched;
          if (heCandidate && found){ // this means it is NOT a constrained edge
            pm->split_triangle(-1, cc[0], cc[1], cc[2], heCandidate->f, delaunayEdgeCriterionPlaneIsotropic, NULL, &_touched);
            pm->vertices.back()->data = -pm->vertices.size()+1;
          }
          else if (heCandidate && !found && heCandidate->data>-1) {
            SVector3 p0 = heCandidate->v->position;
            SVector3 p1 = heCandidate->next->v->position;
            const SVector3 pos = (p0+p1)*0.5;
            if ( heCandidate->opposite){
              pm->split_edge(heCandidate, pos, -1);
              pm->vertices.back()->data = -pm->vertices.size()+1;
              heCandidate->next->opposite->f->data = heCandidate->f->data;
              heCandidate->data = 0; // constrain them again
              heCandidate->next->opposite->next->data = 0; // constrain them again
              std::vector<PolyMesh::HalfEdge *> new_hes;
              new_hes.push_back(heCandidate);
              new_hes.push_back(heCandidate->next);
              new_hes.push_back(heCandidate->next->next);
              new_hes.push_back(heCandidate->next->opposite);
              new_hes.push_back(heCandidate->next->opposite->next);
              new_hes.push_back(heCandidate->next->opposite->next->next);
              delaunayCheck(pm, new_hes, &_touched);
            }
            else { // the circumcenter is outside of the geometrical domain -> we need to add a node on the boundary
              std::vector<PolyMesh::HalfEdge *> new_bnd_hes;
              int bndTag = heCandidate->data;
              // print4debug(pm, newIdx+1000);
              pm->split_boundary_edge(heCandidate, pos, -1, &new_bnd_hes);
              pm->vertices.back()->data = -pm->vertices.size()+1;
              for (auto bnd_he : new_bnd_hes)
                bnd_he->data = bndTag;
              std::vector<PolyMesh::HalfEdge *> new_hes;
              new_hes.push_back(new_bnd_hes[0]);
              new_hes.push_back(new_bnd_hes[0]->next);
              new_hes.push_back(new_bnd_hes[0]->next->next);
              new_hes.push_back(new_bnd_hes[1]);
              new_hes.push_back(new_bnd_hes[1]->next);
              new_hes.push_back(new_bnd_hes[1]->next->next);
              delaunayCheck(pm, new_hes, &_touched);
            }
            SVector3 dist = pos-p0;
            std::vector<PolyMesh::Vertex *> closeVertices;
            getVerticesWithinRadius(pm, pm->vertices.back(), dist.norm(), &closeVertices);
            if (closeVertices.size() > 0){
              _touched.clear();
              for (auto vv : closeVertices){
                std::vector<PolyMesh::HalfEdge *> _tlocal;
                std::vector<PolyMesh::HalfEdge *> _nhes;
                if (pm->degree(vv) > 0 && !freeSurfaceCheck(pm, vv, 0)) {
                  pm->deleteVertex(vv, &_nhes);
                }
                delaunayCheck(pm, _nhes, &_tlocal);
                _touched.insert(_touched.end(), _tlocal.begin(), _tlocal.end());
                // _touched = _nhes;  
                // _touched = _tlocal;
              }
              for(auto face_it = _badFaces.begin() ; face_it != _badFaces.end(); face_it++)
                if (!(*face_it)->he) _badFaces.erase(face_it--);
            }
          }
          if (!globalSize)
            i2Size.push_back(s);
          std::vector<PolyMesh::Face *> _newFaces;
          for(auto _h : _touched){
              if(_h->f && _h->f->he != nullptr && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
                _newFaces.push_back(_h->f);
          }
          for(auto pf : _newFaces) {
              double q;
              SPoint3 cc;
              double R;
              faceInfo(pf->he, cc, &R, &q);
              double s;
              if (!globalSize){
                s = faceSize(pf->he, i2Size);
                if (abs(s-minSize)/minSize < 1e-2){
                  s *= surfaceConstraint;
                }
              }
              else 
                s = sizeAtNodes[0];
              auto it = std::find(_badFaces.begin(), _badFaces.end(), pf); 
              if(it != _badFaces.end()) { 
                _badFaces.erase(it);
              }
              if((q < _limit || R/s > _size) && (R > minRadius && pf->data != -1)) {
                insert_sorted(_badFaces, pf, faceCompareFct);
              }
          }
          newIdx++;
      }
    }
    // auto t4 = std::chrono::steady_clock::now(); 
    
    // print4debug(pm, newIdx+1000);

    // Step 5: dump the updated mesh back into gmsh GFace;
    // delete faces
    for(auto t : gf->triangles) delete t;
    gf->triangles.clear();
    gf->deleteMesh();
    // delete bounding edges
    for (auto dt : bndDimTags){
      GEdge *ge = GModel::current()->getEdgeByTag(dt.second);
      for (auto l : ge->lines) delete l;
      for (auto v : ge->mesh_vertices) delete v;
      ge->lines.clear();
      ge->mesh_vertices.clear();
    }
    // delete all internal mesh vertices
    for (auto mv : gf->mesh_vertices){
      delete mv;
    }
    gf->mesh_vertices.clear();


    // Give back the tag of the nodes that were already in the domain at the beginning

    std::unordered_map<int, MVertex *> news;
    for (size_t i=0; i<addFrom; i++){
      pm->vertices[i]->data = i2g[i];

    }
    

    // 1 -> add bounding edges
    for (auto he : pm->hedges){
      if (!he->f) continue;
      if (he->data > 0){
        PolyMesh::Vertex *v[2] = {he->v, he->next->v};
        MVertex *v_gmsh[2];
        GEdge *ge = GModel::current()->getEdgeByTag(he->data);
        MVertex *begin_v = ge->getBeginVertex()->mesh_vertices[0];
        MVertex *end_v = ge->getEndVertex()->mesh_vertices[0];
        for (int i=0; i<2; i++){
          if(v[i]->data > 0){
            auto it = news.find(v[i]->data);
            if(it == news.end()){
              if (v[i]->data == (int)begin_v->getNum())
                v_gmsh[i] = begin_v;
              else if (v[i]->data == (int)end_v->getNum())
                v_gmsh[i] = end_v;
              else {
                double u = 0;
                GPoint gp = ge->closestPoint(SPoint3(v[i]->position.x(), v[i]->position.y(), v[i]->position.z()), u);
                if(gp.succeeded()){
                  v_gmsh[i] = new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, gp.u(), v[i]->data);
                }
                else {
                  v_gmsh[i] = new MEdgeVertex(v[i]->position.x(), v[i]->position.y(),
                                              v[i]->position.z(), ge,
                                              v[i]->position.x());
                }
                ge->mesh_vertices.push_back(v_gmsh[i]);
              }
              news[v[i]->data] = v_gmsh[i];
            }
            else
              v_gmsh[i] = it->second;
          }
          else {
            double u = 0;
            GPoint gp = ge->closestPoint(SPoint3(v[i]->position.x(), v[i]->position.y(), v[i]->position.z()), u);
            if(gp.succeeded()){
              v_gmsh[i] = new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, gp.u());
            }
            else{
              v_gmsh[i] = new MEdgeVertex(v[i]->position.x(), v[i]->position.y(),
                                        v[i]->position.z(), ge,
                                        v[i]->position.x());
            }

            ge->mesh_vertices.push_back(v_gmsh[i]);
            v[i]->data = v_gmsh[i]->getNum();
            news[v[i]->data] = v_gmsh[i];
          }
        }
        ge->lines.push_back(new MLine(v_gmsh[0], v_gmsh[1]));
      }
    } 

    // 2 -> add the faces
    newElementsInRefinement.clear();
    for(auto f : pm->faces) {
      if (f->he) {
        PolyMesh::Vertex *v[3] = {f->he->v, f->he->next->v, f->he->next->next->v};
        MVertex *v_gmsh[3];
        for(int i = 0; i < 3; i++) {
          if(v[i]->data > 0) {
            auto it = news.find(v[i]->data);
            if(it == news.end()){
              double uv[2] = {0, 0};
              GPoint gp = gf->closestPoint( SPoint3(v[i]->position.x(), v[i]->position.y(), v[i]->position.z()), uv);
              v_gmsh[i] = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v(), v[i]->data);
              gf->mesh_vertices.push_back(v_gmsh[i]);
              news[v[i]->data] = v_gmsh[i];
            }
            else
              v_gmsh[i] = it->second;
          }
          else {
            double uv[2] = {0, 0};
            GPoint gp = gf->closestPoint( SPoint3(v[i]->position.x(), v[i]->position.y(), v[i]->position.z()), uv);
            if(gp.succeeded()){
              v_gmsh[i] = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
            }
            else {
              v_gmsh[i] = new MFaceVertex(v[i]->position.x(), v[i]->position.y(),
                                          v[i]->position.z(), gf,
                                          v[i]->position.x(), v[i]->position.y());
            }
            
            gf->mesh_vertices.push_back(v_gmsh[i]);
            v[i]->data = v_gmsh[i]->getNum();
            news[v[i]->data] = v_gmsh[i];
          }
        }
        gf->triangles.push_back(new MTriangle(v_gmsh[0], v_gmsh[1], v_gmsh[2]));
        if (f->data != -1){
          newElementsInRefinement.push_back(gf->triangles.back()->getNum());
        }
      }
    }
    for (size_t i=addFrom; i<pm->vertices.size(); i++){
      newNodeTags.push_back(pm->vertices[i]->data);
      newCoords.push_back(pm->vertices[i]->position.x());
      newCoords.push_back(pm->vertices[i]->position.y());
      newCoords.push_back(pm->vertices[i]->position.z());
      if (!globalSize) newsizeAtNodes.push_back(v2sizeAtNodes[pm->vertices[i]->data]);
    }

    std::unordered_map<PolyMesh::HalfEdge*, bool> he_touched;
    std::vector<size_t> openLoop;
    newConstrainedEdges.clear();
    for (auto he : pm->hedges){
      if (he->f && he->data == 0 && !he_touched[he]){
        std::vector<size_t> loop;
        PolyMesh::HalfEdge* _he = he;
        do {
          he_touched[_he] = true;
          loop.push_back(_he->v->data);
          loop.push_back(_he->next->v->data);
          _he = getNextEdgeOnFreeSurface(_he);
        } while (_he != nullptr && !he_touched[_he] && _he != he);
        if (_he == he)
          newConstrainedEdges.push_back(loop);
        else {
          size_t nf = loop.back();
          std::vector<size_t>::iterator n_insert;
          n_insert = find(openLoop.begin(), openLoop.end(), nf);
          openLoop.insert(n_insert, loop.begin(), loop.end());
        }
      }
    }
    newConstrainedEdges.push_back(openLoop);
    // auto t5 = std::chrono::steady_clock::now(); 
    
    // auto durInit1 = std::chrono::duration_cast<std::chrono::milliseconds>(t0p-t0);
    // auto durInit2 = std::chrono::duration_cast<std::chrono::milliseconds>(t00p-t0p);
    // auto durInit2p = std::chrono::duration_cast<std::chrono::milliseconds>(t0pp-t00p);
    // auto durInit3 = std::chrono::duration_cast<std::chrono::milliseconds>(t0ppp-t0pp);
    // auto durInit4 = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0ppp);
    // auto durBefCoar = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1);
    // auto durCoar = std::chrono::duration_cast<std::chrono::milliseconds>(t3-t2);
    // auto durMain = std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3);
    // auto durRegen = std::chrono::duration_cast<std::chrono::milliseconds>(t5-t4);
    // auto durTotal = std::chrono::duration_cast<std::chrono::milliseconds>(t5-t0);
    // printf("initial 1  time : %f percent \n", 100*double(durInit1.count())/double(durTotal.count()) );
    // printf("initial 2  time : %f percent \n", 100*double(durInit2.count())/double(durTotal.count()) );
    // printf("initial 2p time : %f percent \n", 100*double(durInit2p.count())/double(durTotal.count()) );
    // printf("initial 3  time : %f percent \n", 100*double(durInit3.count())/double(durTotal.count()) );
    // printf("initial 4  time : %f percent \n", 100*double(durInit4.count())/double(durTotal.count()) );
    // printf("bef coar   time : %f percent \n", 100*double(durBefCoar.count())/double(durTotal.count()) );
    // printf("coarse     time : %f percent \n", 100*double(durCoar.count())/double(durTotal.count()) );
    // printf("main       time : %f percent \n", 100*double(durMain.count())/double(durTotal.count()) );
    // printf("regen      time : %f percent \n", 100*double(durRegen.count())/double(durTotal.count()) );

    CTX::instance()->mesh.changed = ENT_ALL;
    pm->clean();
    delete pm;
  }
}

void alphaShape_entity(const int dim, const int tag, const double alpha, const std::vector<size_t>& nodeTags, const std::vector<double>& sizeAtNodes, std::vector<std::vector<size_t>>& elementTags, std::vector<std::vector<size_t>>& edges){
  if (dim == 2){
    bool globalAlpha = sizeAtNodes.size() == 1;
    auto it_min = min_element(sizeAtNodes.begin(), sizeAtNodes.end()); // to restrict elements even more if all the nodes have minimum size field
    double minSize = *it_min;

    double surfaceConstraint = 0.5;

    PolyMesh* pm;
    GFace2PolyMesh(tag, &pm);
    std::unordered_map<int, double> v2sizeAtNodes;
    std::vector<int> i2g;
    std::vector<double> i2Size;
    for (size_t i=0; i<pm->vertices.size(); i++){
      PolyMesh::Vertex* v = pm->vertices[i];
      i2g.push_back(v->data);
      v->data = i;
    }
    if (!globalAlpha){
      for (size_t i=0; i<nodeTags.size(); i++){
        v2sizeAtNodes[nodeTags[i]] = sizeAtNodes[i];
      }
      for (size_t i=0; i<pm->vertices.size(); i++){
        PolyMesh::Vertex* v = pm->vertices[i];
        i2Size.push_back(v2sizeAtNodes[i2g[v->data]]);
      }
    }
    // Face data is the element tag -> note : dangerous but it works... (cfr GFace2PolyMesh function)
    std::vector<size_t> etFull;
    std::vector<size_t> ntFull;
    gmsh::model::mesh::getElementsByType(2, etFull, ntFull, tag);
    for (size_t i=0; i<pm->faces.size(); i++)
      pm->faces[i]->data = etFull[i];
    std::unordered_map<PolyMesh::Face*, bool> _touched;
    double hTriangle = sizeAtNodes[0];
    SPoint3 cc;
    double R;
    for (size_t i = 0; i < pm->faces.size(); i++){
      PolyMesh::Face *f = pm->faces[i];
      if (!globalAlpha){
        hTriangle = faceSize(f->he, i2Size);
        if (abs(hTriangle-minSize)/minSize < 1e-2){
          hTriangle *= surfaceConstraint;
        }
      }
      faceCircumCenter(f->he, cc, &R);
      if (R/hTriangle < alpha && !_touched[f]){
        // printf("triangle is in alpha shape : R = %f, alpha = %f, h = %f\n", R, alpha, hTriangle);
        std::stack<PolyMesh::Face *> _s;
        std::vector<size_t> _domain;
        std::vector<size_t> _boundary;
        _s.push(f);
        _touched[f] = true;
        _domain.push_back(f->data);
        while(!_s.empty()){
          PolyMesh::Face* _f = _s.top();
          _s.pop();
          PolyMesh::HalfEdge *_he = _f->he;
          do {
            if (_he->opposite == nullptr){
              // _boundary.push_back(_he->v->data);
              // _boundary.push_back(_he->next->v->data);
            }
            else if (!_touched[_he->opposite->f]){
              PolyMesh::Face *f_neigh = _he->opposite->f;
              if (!globalAlpha){
                hTriangle = faceSize(f_neigh->he, i2Size);
                if (abs(hTriangle-minSize)/minSize<1e-2){ 
                  hTriangle *= surfaceConstraint;
                }
              }
              faceCircumCenter(f_neigh->he, cc, &R);
              if (R/hTriangle < alpha){
                // printf("triangle is in alpha shape : R = %f, alpha = %f, h = %f\n", R, alpha, hTriangle);
                _s.push(f_neigh);
                _touched[f_neigh] = true;
                _domain.push_back(f_neigh->data);	    
              }	    
              else {
                _boundary.push_back(i2g[abs(_he->v->data)]);
                _boundary.push_back(i2g[abs(_he->next->v->data)]);	      
              }
            }
            _he = _he->next;
          }while (_he != _f->he);
        }
        edges.push_back(_boundary);
        elementTags.push_back(_domain); 
      }
    }
    pm->clean();
    delete pm;
  }
  else if (dim == 3){
    bool globalAlpha = sizeAtNodes.size() == 1;
    // GModel* gm = GModel::current();
    // GRegion* gr = gm->getRegionByTag(tag);

    std::vector<size_t> etFull, ntFull, nTags;
    std::vector<double> coords, pCoords;
    gmsh::model::mesh::getElementsByType(4, etFull, ntFull, tag);
    gmsh::model::mesh::getNodes(nTags, coords, pCoords, dim, tag, true, false);
    std::unordered_map<size_t, size_t> t2i;
    std::vector<double> nodeSize(nodeTags.size());
    size_t i=0;
    for (auto t : nTags) t2i[t] = i++;
    i=0;
    for (auto t : nodeTags) nodeSize[t2i[t]] = sizeAtNodes[i++];
    double hTet = sizeAtNodes[0];
    SPoint3 cc;
    // double R;
    std::vector<size_t> neigh;
    std::vector<size_t> tetrahedra(ntFull.size());
    i=0;
    for (auto n : ntFull) tetrahedra[i++] = t2i[n];
    computeTetNeighbors_ (tetrahedra, neigh);
    std::vector<bool> _touched;
    _touched.resize(tetrahedra.size()/4);
    for (size_t i=0;i<_touched.size();i++)_touched[i] = false;
    std::vector<std::vector<size_t>> boundaries;
    for (size_t i = 0; i < tetrahedra.size(); i+=4){
      size_t *t = &tetrahedra[i];
      if (!globalAlpha) hTet = (nodeSize[t[0]] + nodeSize[t[1]] + nodeSize[t[2]] + nodeSize[t[3]])/4; 
      if (alphaShape(t, coords, hTet) < alpha && _touched[i/4] == false){
        std::stack<size_t> _s;
        std::vector<size_t> _domain;
        std::vector<size_t> _boundary;
        _s.push(i/4);
        _touched[i/4] = true;
        _domain.push_back(etFull[i/4]);
        while(!_s.empty()){
          size_t t = _s.top();
          _s.pop();
          for (int j=0;j<4;j++){
            size_t tj = neigh[(4*t+j)]/4;
            if (tj*4 == tetrahedra.size()){
              _boundary.push_back(t);
              _boundary.push_back(j);
            }
            else if (!_touched[tj]){
              size_t *t_neigh = &tetrahedra[4*tj];
              if (!globalAlpha) hTet = (nodeSize[t_neigh[0]] + nodeSize[t_neigh[1]] + nodeSize[t_neigh[2]] + nodeSize[t_neigh[3]])/4; 
              if (alphaShape(t_neigh, coords, hTet) < alpha){
                _s.push(tj);
                _touched[tj] = true;
                _domain.push_back(etFull[tj]);	    
              }	    
              else {
                _boundary.push_back(nTags[tetrahedra[4*t+_outwardFaces[j][0]]]);
                _boundary.push_back(nTags[tetrahedra[4*t+_outwardFaces[j][1]]]);
                _boundary.push_back(nTags[tetrahedra[4*t+_outwardFaces[j][2]]]);
              }
            }
          }	  
        }
        edges.push_back(_boundary);
        elementTags.push_back(_domain);
      }
    }
  }
  else
    Msg::Error("Dimension error.");
}

static double _faceSize(PolyMesh::HalfEdge *he, std::vector<double> & sizeAtNodes){
  return 1./3.* (sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data] + sizeAtNodes[he->next->next->v->data]);
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

void _delaunayCheck(PolyMesh* pm, std::vector<PolyMesh::HalfEdge* > hes, std::vector<PolyMesh::HalfEdge* > *_t, int bndTag){
  std::stack<PolyMesh::HalfEdge *> _stack;
  for (auto he : hes) _stack.push(he);
  std::vector<PolyMesh::HalfEdge *> _touched;
  while(!_stack.empty()) {
    PolyMesh::HalfEdge *he = _stack.top();
    _touched.push_back(he);
    _stack.pop();
    if(delaunayCriterion(he, &bndTag) == 1) {
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

void _Walk(PolyMesh::Face *f, double* cc, PolyMesh::HalfEdge** heCandidate, bool* found, int bndTag, int* onEdgeFlag)
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
      if (he->data == bndTag){
        *heCandidate = he;
        *found = false;
        cont = false;
      }
      else 
        he = he->opposite;
    }
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0){
      if (he->next->data == bndTag){
        *heCandidate = he->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->opposite;
    }
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0){
      if (he->next->next->data == bndTag){
        *heCandidate = he->next->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->next->opposite;
    }
    else if(s0 <= 0 && s1 <= 0){
      // he = s0 > s1 ? he->opposite : he->next->opposite;
      if (s0 > s1){
        if (he->data == bndTag){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else{
        if (he->next->data == bndTag){
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
      if (s0 > s2){
        if (he->data == bndTag){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else {
        if (he->next->next->data == bndTag){
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
      if (s1 > s2){
        if(he->next->data == bndTag){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
      else {
        if(he->next->next->data == bndTag){
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

  for (auto v : vCheck){
    if (v->data <= 0) {
      continue;
    }
    PolyMesh::HalfEdge* heTurn = v->he;
    do {
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

inline bool checkVertexConnection(PolyMesh::Vertex* v, int volTag){
  PolyMesh::HalfEdge* he = v->he;
  do {
    if (!he) return false;
    if (!he->f) return false;
    if (he->f->data == volTag) return true;
    he = he->next->next->opposite;
  } while (he != v->he);
  return false;
}

void polyMeshFromExistingElements(PolyMesh* pm, int faceTag, int bndTag){
  GFace* gf = GModel::current()->getFaceByTag(faceTag);
  size_t nNodesInMesh = gf->mesh_vertices.size();
  std::vector<double> coordsInMesh(2*nNodesInMesh);
  std::unordered_map<size_t, size_t> nodeTagsInMesh;
  for (size_t i=0; i<nNodesInMesh; i++){
    MVertex* v = gf->mesh_vertices[i];
    coordsInMesh[2*i+0] = v->x();
    coordsInMesh[2*i+1] = v->y();
  }
  SBoundingBox3d bb;
  for(size_t i = 0; i < coordsInMesh.size(); i += 2) {
    bb += SPoint3(coordsInMesh[i], coordsInMesh[i + 1], 0);
  }
  bb *= 1.1;
  initialize_rectangle(pm, bb.min().x(), bb.max().x(), bb.min().y(),
                          bb.max().y());
  std::vector<MTriangle *> elementsInMesh = gf->triangles;
  if (elementsInMesh.size() == 0) Msg::Error("No elements in mesh. Set triangulate option to 1.\n");
  MVertex* vert;
  PolyMesh::Face *f = pm->faces[0];
  PolyMesh::HalfEdge* he;
  for(size_t i = 0; i < elementsInMesh.size(); i++) {
    for(int j = 0; j < 3; j++) {
      vert = elementsInMesh[i]->getVertex(j);
      auto it = nodeTagsInMesh.find(vert->getNum());
      if(it == nodeTagsInMesh.end()) {
        bool found;
        double x[2] = {vert->x(), vert->y()};
        _Walk(f, x, &he, &found, 10, nullptr);
        f = he->f;
        pm->split_triangle(-1, x[0], x[1], 0, f, delaunayCriterion, nullptr);
        pm->vertices[pm->vertices.size() - 1]->data = vert->getNum();
        nodeTagsInMesh[vert->getNum()] = pm->vertices.size()-1;
      }
    }
  }
  // recover boundary edges
  GEdge* ge = GModel::current()->getEdgeByTag(bndTag);
  std::vector<MLine *> edges = ge->lines;
  // printf("edges size : %lu \n", edges.size());
  
  for (auto ed : edges){
    MVertex* gv0 = ed->getVertex(0);
    MVertex* gv1 = ed->getVertex(1);
    size_t idx0 = nodeTagsInMesh[gv0->getNum()];
    size_t idx1 = nodeTagsInMesh[gv1->getNum()];
    // printf("recovering edge %d->%d ...\n", gv0->getNum(), gv1->getNum());
    PolyMesh::Vertex *v0 = pm->vertices[idx0];
    PolyMesh::Vertex *v1 = pm->vertices[idx1];
    int result = recover_edge(pm, v0, v1);
    if(result < 0) {
      Msg::Warning("Impossible to recover edge %lu %lu (error tag %d)",
                    gv0->getNum(), gv1->getNum(), result);
    }
    else {
      PolyMesh::HalfEdge *he = pm->getEdge(v0, v1);
      if(he) {
        if(he->opposite) he->opposite->data = -1;
        he->data = bndTag;
      }
    }
  }
}

static PolyMesh::Face *WalkGeneral(PolyMesh::Face *f, double x, double y)
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
      /* printf("Face %g %g %g / %g %g %g / %g %g %g \n",
                v0->position.x(), v0->position.y(), v0->position.z(),
                v1->position.x(), v1->position.y(), v1->position.z(),
                v2->position.x(), v2->position.y(), v2->position.z());
                printf("point %g %g CURRENT FACE %p %g %g %g\n", x,y,he->f,
                s0,s1,s2); */
      // getchar();
      return he->f;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0)
      he = he->opposite;
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0)
      he = he->next->opposite;
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0)
      he = he->next->next->opposite;
    else if(s0 <= 0 && s1 <= 0)
      he = s0 < s1 ? he->opposite : he->next->opposite;
    else if(s0 <= 0 && s2 <= 0)
      he = s0 < s2 ? he->opposite : he->next->next->opposite;
    else if(s1 <= 0 && s2 <= 0)
      he = s1 < s2 ? he->next->opposite : he->next->next->opposite;
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

void recoverEdgesOfPolyMesh(PolyMesh** pm, int faceTag, int bndTag){
  PolyMesh* pm_old = *pm;
  SBoundingBox3d bb;
  for(auto v : pm_old->vertices) {
    bb += SPoint3(v->position.x(), v->position.y(), 0);
  }
  bb *= 1.1;
  PolyMesh* pm_new = new PolyMesh;
  initialize_rectangle(pm_new, bb.min().x(), bb.max().x(), bb.min().y(),
                          bb.max().y());
  PolyMesh::Face *f = pm_new->faces[0];
  std::unordered_map<PolyMesh::Vertex*, PolyMesh::Vertex*> old2new;
  for(auto v : pm_old->vertices) {
    double x[2] = {v->position.x(), v->position.y()};
    // _Walk(pm_new->faces.back(), x, &he, &found, 10, nullptr);
    // f = he->f;
    f = WalkGeneral(pm_new->faces.back(), x[0], x[1]);
    pm_new->split_triangle(-1, x[0], x[1], 0, f, delaunayCriterion, nullptr);
    pm_new->vertices[pm_new->vertices.size() - 1]->data = v->data;
    old2new[v] = pm_new->vertices[pm_new->vertices.size() - 1];
  }
  std::vector<PolyMesh::HalfEdge*> _t;
  // delaunayCheck(pm_new, pm_new->hedges, &_t);
  // print4debug(pm_new, 100);
  // recover boundary edges
  for (auto he : pm_old->hedges){
    if (he->data != bndTag) continue;
    // print4debug(pm_new, ndebug++);
    PolyMesh::Vertex *v0 = old2new[he->v];
    PolyMesh::Vertex *v1 = old2new[he->next->v];
    PolyMesh::HalfEdge* heBnd = pm_new->getEdge(v0, v1);
    if ( heBnd == nullptr) {
      int result = recover_edge(pm_new, v0, v1);
      if(result < 0) {
        Msg::Warning("Impossible to recover boundary edge %lu %lu (%f,%f)->(%f,%f) (error tag %d)",
                      v0->data, v1->data, v0->position.x(), v0->position.y(), v1->position.x(), v1->position.y(), result);
      }
      else {
        PolyMesh::HalfEdge *heBnd = pm_new->getEdge(v0, v1);
        if(heBnd) {
          if(heBnd->opposite) heBnd->opposite->data = -1;
          heBnd->data = bndTag;
        }
      }
    }
    else {
      if(heBnd->opposite) heBnd->opposite->data = -1;
      heBnd->data = bndTag;
    }
  }

  // color internal faces :)
  std::unordered_set<PolyMesh::Face*> touched;
  for (auto f : pm_new->faces){
    PolyMesh::HalfEdge* he = f->he;
    bool inside = false;
    do {
      if (he->data == bndTag) { // we're inside :)
        inside = true;
        break;
      }
      he = he->next;
    } while (he != f->he);
    if (inside) {
      std::stack<PolyMesh::Face *> _s;
      _s.push(f);
      while(!_s.empty()){
        PolyMesh::Face* _f = _s.top();
        _f->data = faceTag;
        touched.insert(_f);
        _s.pop();
        PolyMesh::HalfEdge *_he = _f->he;
        do {
          if (_he->opposite != nullptr){
            if (_he->data != bndTag && touched.find(_he->opposite->f) == touched.end()){
              _s.push(_he->opposite->f);
            }
          }
          _he = _he->next;
        }while (_he != _f->he);
      }
    }
  }

  *pm = pm_new;
  delete pm_old;
}

PolyMesh::HalfEdge* getNextEdgeOnBoundary(PolyMesh::HalfEdge* he, const int bndTag){
  if (he->data != bndTag) {
    printf("edge is not boundary...\n");
    return nullptr;
  }
  if (he->next->data == bndTag) return he->next;
  PolyMesh::HalfEdge* _he = he->next;
  do {
    if (_he->opposite) _he = _he->opposite->next;
    else return nullptr;
    if (_he->data == bndTag) return _he;
  } while (_he != he);
  return nullptr;
}

void _computeAlphaShape(const std::vector<int> & alphaShapeTags, const double alpha, const double hMean,
                        std::function<double(int, int, double, double, double, double)> sizeFieldCallback, 
                        const int triangulate, const int refine){

// #pragma omp parallel
// {
//     printf("number of threads : %d \n", omp_get_num_threads());
// }
// exit(0);
  

  // 1. generate mesh 
  // auto t0 = std::chrono::high_resolution_clock::now();

  // Msg::Info("generating mesh...\n");
  GFace* gf = GModel::current()->getFaceByTag(alphaShapeTags[0]);
  size_t nNodesInMesh = gf->mesh_vertices.size();
  std::vector<double> coordsInMesh(2*nNodesInMesh);
  std::vector<size_t> nodeTagsInMesh(nNodesInMesh);
  for (size_t i=0; i<nNodesInMesh; i++){
    MVertex* v = gf->mesh_vertices[i];
    coordsInMesh[2*i+0] = v->x();
    coordsInMesh[2*i+1] = v->y();
    nodeTagsInMesh[i] = v->getNum();
  }
  PolyMesh *pm = new PolyMesh;
  if (triangulate){
    SBoundingBox3d bb;
    for(size_t i = 0; i < coordsInMesh.size(); i += 2) {
      bb += SPoint3(coordsInMesh[i], coordsInMesh[i + 1], 0);
    }
    bb *= 1.1;
    initialize_rectangle(pm, bb.min().x(), bb.max().x(), bb.min().y(),
                            bb.max().y());
    PolyMesh::Face *f = pm->faces[0];
    for(size_t i = 0; i < coordsInMesh.size(); i += 2) {
      double x[2] = {coordsInMesh[i], coordsInMesh[i + 1]};
      f = WalkGeneral(f, x[0], x[1]);
      // f = he->f;
      pm->split_triangle(-1, x[0], x[1], 0, f, delaunayCriterion, nullptr);
      pm->vertices[pm->vertices.size() - 1]->data = nodeTagsInMesh[i/2];
    }
  }
  else {
    // polyMeshFromExistingElements(pm, alphaShapeTags[0], alphaShapeTags[1]);
    GFace2PolyMesh(alphaShapeTags[0], &pm);
  }
  // print4debug(pm, -99);

  for (auto f : pm->faces){
    int i0 = f->he->v->data;
    int i1 = f->he->next->v->data;
    int i2 = f->he->next->next->v->data;
    if(i0 < 0 || i1 < 0 || i2 < 0) 
      f->data = -2;
  }
  
  std::unordered_map<PolyMesh::Vertex*, size_t> vertex2Tag;
  std::vector<double> sizeAtNodes(pm->vertices.size());
  std::vector<size_t> gNodeTags(pm->vertices.size(), 0);
  for (size_t i=0; i<4; i++) sizeAtNodes[i] = DBL_MAX;
  for (size_t i= triangulate? 4 : 0; i<pm->vertices.size(); i++){ // we're skipping the 4 vertices of the bounding box
    PolyMesh::Vertex* v = pm->vertices[i];
    vertex2Tag[v] = v->data;
    gNodeTags[i] = v->data;
    sizeAtNodes[i] = hMean > 0 ? hMean : sizeFieldCallback(2, v->data, v->position.x(), v->position.y(), v->position.z(), 0);
    v->data = i;
  }

  auto it_min = min_element(sizeAtNodes.begin(), sizeAtNodes.end()); // to restrict elements even more if all the nodes have minimum size field
  double minSize = *it_min;
  double surfaceConstraint = hMean == -20 ? 0.5 : 1.;
  // double surfaceConstraint = 1.;


  // 2. compute alpha shape
  // auto t1 = std::chrono::high_resolution_clock::now(); 
  std::unordered_map<PolyMesh::Face*, bool> _touched;
  // std::vector<std::vector<size_t>> edges;
  double hTriangle, R, q;
  double qualityThreshold = 0.;
  SPoint3 cc;
  for (size_t i = 0; i < pm->faces.size(); i++){
    if (pm->faces[i]->data == -2) continue;
    PolyMesh::Face *f = pm->faces[i];
    hTriangle = _faceSize(f->he, sizeAtNodes);
    if (abs(hTriangle-minSize)/minSize < 1e-2){
      hTriangle *= surfaceConstraint;
    }
    // faceCircumCenter(f->he, cc, &R);
    faceInfo(f->he, cc, &R, &q);
    if (R/hTriangle < alpha && !_touched[f] && q > qualityThreshold){
      std::stack<PolyMesh::Face *> _s;
      // std::vector<size_t> _boundary;
      _s.push(f);
      _touched[f] = true;
      f->data = alphaShapeTags[0];
      while(!_s.empty()){
        PolyMesh::Face* _f = _s.top();
        _s.pop();
        PolyMesh::HalfEdge *_he = _f->he;
        do {
          if (_he->opposite == nullptr || _he->opposite->f->data < -1){
            _he->data = alphaShapeTags[1];      
            // _he->opposite->data = alphaShapeTags[1]; 
          }     
          else if (!_touched[_he->opposite->f]){
            PolyMesh::Face *f_neigh = _he->opposite->f;
            hTriangle = _faceSize(f_neigh->he, sizeAtNodes);
            if (abs(hTriangle-minSize)/minSize < 1e-2){
              hTriangle *= surfaceConstraint;
            }
            // faceCircumCenter(f_neigh->he, cc, &R);
            faceInfo(f_neigh->he, cc, &R, &q);
            if (R/hTriangle < alpha && q > qualityThreshold){
              _s.push(f_neigh);
              _touched[f_neigh] = true;
              f_neigh->data = alphaShapeTags[0];    
            }	    
            else {
              _he->data = alphaShapeTags[1];
              // _boundary.push_back(_he);
                // _boundary.push_back(i2g[abs(_he->next->v->data)]);
              // _he->opposite->data = alphaShapeTags[1];
            }
          }
          _he = _he->next;
        }while (_he != _f->he);
      }
      // edges.push_back(_boundary);
    }
  }

  if (triangulate == 0 && refine == 1){ // we need to create a bounding boxed mesh, but with constrained edges
    recoverEdgesOfPolyMesh(&pm, alphaShapeTags[0], alphaShapeTags[1]);
    vertex2Tag.clear();
    sizeAtNodes.clear();
    sizeAtNodes.resize(pm->vertices.size());
    for (size_t i=4 ; i<pm->vertices.size(); i++){ // we're skipping the 4 vertices of the bounding box
      PolyMesh::Vertex* v = pm->vertices[i];
      vertex2Tag[v] = gNodeTags[i-4];
      sizeAtNodes[i] = hMean > 0 ? hMean : sizeFieldCallback(2, gNodeTags[i-4], v->position.x(), v->position.y(), v->position.z(), 0);
      v->data = i;
    }
  }
  // exit(0);
  // print4debug(pm, 1);
  for (auto f : pm->faces) if (f->data == -2) f->data = -1;
  // 3. if requested, refine  
  // auto t2 = std::chrono::high_resolution_clock::now(); 
  if (refine){
    // Msg::Info("constrained Delaunay...\n");

    // Compute the size field at the nodes if it was not done in the alpha shape (because hMean was used)
    if (hMean > 0){
    for (int i=0; i<pm->vertices.size(); i++){
      PolyMesh::Vertex* v = pm->vertices[i];
      sizeAtNodes[i] = sizeFieldCallback(2, vertex2Tag[v], v->position.x(), v->position.y(), v->position.z(), 0);
    }}

    // TODO : collapse boundary edges
    
    // Msg::Info("--> coarsening...\n");
    // First, coarsen...
    std::vector<PolyMesh::HalfEdge *> heVector;
    double coarseFactor_bnd = 0.3;
    double coarseFactor_in = 0.3;
    for (auto he : pm->hedges){
      if ((he->data == -1 && !freeSurfaceCheck(pm, he->v, alphaShapeTags[1])) || he->data == alphaShapeTags[1]){
        double d = norm(he->v->position - he->next->v->position);
        double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
        if (d < coarseFactor_in*size) {
          insert_sorted(heVector, he, heCompare);
        }
      }
    }
    while (!heVector.empty()){
      PolyMesh::HalfEdge *he = heVector.back();
      heVector.erase(heVector.end()-1);
      if (he->opposite == nullptr || he->opposite->f == nullptr || he->f == nullptr ) continue; 
      if (he->f->data != alphaShapeTags[0]) continue;
      if (freeSurfaceCheck(pm, he->v, alphaShapeTags[1]) && he->data == -1) continue; 
      double d = norm(he->v->position - he->next->v->position);
      double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
      if (d < coarseFactor_in*size){
        // print4debug(pm, n_delete++);
        std::vector<PolyMesh::HalfEdge *> _nhes;
        if (he->data == alphaShapeTags[1] && d <coarseFactor_bnd*size){
          hedgeCollapseBoundaryEdge(pm, he, alphaShapeTags[0], alphaShapeTags[1], &_nhes);
        }
        else if (he->data != alphaShapeTags[1]){
          pm->hedgeCollapse(he, &_nhes);
        }
        auto it = std::find(heVector.begin(), heVector.end(), he->opposite);
        if (it != heVector.end()) heVector.erase(it);
        std::vector<PolyMesh::HalfEdge* > _t;
        _delaunayCheck(pm, _nhes, &_t, alphaShapeTags[1]);  
      }
    }

    // print4debug(pm, 0);
    // exit(0);
    // Then, refine...
    // Msg::Info("--> refining...\n");
    std::vector<PolyMesh::Face *> _badFaces;
    double _limit = .4;         // Values to discuss...
    double _size = 1.;          // Values to discuss...
    double _sizeMinFactor = .5; // Values to discuss...
    for(auto f : pm->faces) {
      if (f->he && f->data == alphaShapeTags[0]){
        double q, R, s;
        SPoint3 cc;
        faceInfo(f->he, cc, &R, &q);
        s = _faceSize(f->he, sizeAtNodes);
        if((q < _limit && R/s > _sizeMinFactor) || R/s > _size) insert_sorted(_badFaces, f, faceCompareFct);
      }
    }
    size_t newTag;
    gmsh::model::mesh::getMaxNodeTag(newTag);
    newTag++;
    while (!_badFaces.empty()){
      // exit(0);
      PolyMesh::Face *f = _badFaces.back();
      _badFaces.erase(_badFaces.end()-1);
      if (f->he == nullptr || f->data != alphaShapeTags[0]) {
        continue;
      }
      double q, R, s;
      SPoint3 cc;
      faceInfo(f->he, cc, &R, &q); // NB : q = 2*rho / R
      s = _faceSize(f->he, sizeAtNodes);
      if((q < _limit && R/s > _sizeMinFactor) || R/s > _size){
          PolyMesh::HalfEdge* heCandidate = nullptr;
          bool found;
          int onEdgeFlag;
          _Walk(f, cc, &heCandidate, &found, alphaShapeTags[1], &onEdgeFlag);
          if (onEdgeFlag != -1){ // A sanity check... if we are splitting a triangle with a 90° angle, and the opposite edge happens to be a boundary edge, we must split the edge, not the triangle
            PolyMesh::HalfEdge *flaggedHe = nullptr; 
            if (onEdgeFlag == 0) flaggedHe = heCandidate;
            else if (onEdgeFlag == 1) flaggedHe = heCandidate->next;
            else if (onEdgeFlag == 2) flaggedHe = heCandidate->next->next;
            if (flaggedHe->data == alphaShapeTags[1]) {
              found = false;
              heCandidate = flaggedHe;
            }
          }
          std::vector<PolyMesh::HalfEdge *> _touched;
          if (heCandidate && found){ // this means it is NOT a constrained edge
            int bndTag = alphaShapeTags[1];
            pm->split_triangle(-1, cc[0], cc[1], cc[2], heCandidate->f, delaunayCriterion, &bndTag, &_touched);
          }
          else { // this means it is a constrained edge
            SVector3 p = 0.5*(heCandidate->v->position + heCandidate->next->v->position);
            cc.setPosition(p.x(), p.y(), p.z());
            if ( heCandidate->opposite){
              pm->split_edge(heCandidate, cc, -1);
              heCandidate->next->opposite->f->data = heCandidate->f->data;
              heCandidate->opposite->f->data = heCandidate->next->opposite->next->opposite->f->data;
              heCandidate->data = alphaShapeTags[1]; // constrain them again
              heCandidate->opposite->data = alphaShapeTags[1]; // constrain them again
              heCandidate->next->opposite->next->data = alphaShapeTags[1]; // constrain them again
              heCandidate->next->opposite->next->opposite->data = alphaShapeTags[1]; // constrain them again
              std::vector<PolyMesh::HalfEdge *> new_hes;
              new_hes.push_back(heCandidate);
              new_hes.push_back(heCandidate->next);
              new_hes.push_back(heCandidate->next->next);
              new_hes.push_back(heCandidate->next->opposite);
              new_hes.push_back(heCandidate->next->opposite->next);
              new_hes.push_back(heCandidate->next->opposite->next->next);
              _delaunayCheck(pm, new_hes, &_touched, alphaShapeTags[1]);
            }
            SVector3 dist = cc-heCandidate->v->position;
            std::vector<PolyMesh::Vertex *> closeVertices;
            getVerticesWithinRadius(pm, pm->vertices.back(), dist.norm(), &closeVertices);
            if (closeVertices.size() > 0){
              _touched.clear();
              for (auto vv : closeVertices){
                std::vector<PolyMesh::HalfEdge *> _tlocal;
                std::vector<PolyMesh::HalfEdge *> _nhes;
                if (vv->he->f->data == alphaShapeTags[0] && pm->degree(vv) > 0 && !freeSurfaceCheck(pm, vv, alphaShapeTags[1])) {
                  _deleteVertex(pm, vv, &_nhes);
                  // pm->deleteVertex(vv, &_nhes);
                }
                _delaunayCheck(pm, _nhes, &_tlocal, alphaShapeTags[1]);
                _touched.insert(_touched.end(), _tlocal.begin(), _tlocal.end());
              }
              for(auto face_it = _badFaces.begin() ; face_it != _badFaces.end(); face_it++)
                if (!(*face_it)->he) _badFaces.erase(face_it--);
            }
          }
          pm->vertices.back()->data = pm->vertices.size()-1;
          vertex2Tag[pm->vertices.back()] = newTag++;
          sizeAtNodes.push_back(sizeFieldCallback(2, -1, cc[0], cc[1], cc[2], 0));
          std::vector<PolyMesh::Face *> _newFaces;
          for(auto _h : _touched){
              if(_h->f && _h->f->he != nullptr && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
                _newFaces.push_back(_h->f);
          }
          for(auto pf : _newFaces) {
              double q, R, s;
              SPoint3 cc;
              faceInfo(pf->he, cc, &R, &q);
              s = _faceSize(pf->he, sizeAtNodes);
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

  // 4. store in discrete entities
  // auto t3 = std::chrono::high_resolution_clock::now();
  // auto dur1 = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0);
  // auto dur2 = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
  // auto dur3 = std::chrono::duration_cast<std::chrono::microseconds>(t3-t2);
  // auto durTotal = std::chrono::duration_cast<std::chrono::microseconds>(t3-t0);
  // printf("triangulate time : %f percent \n", 100*double(dur1.count())/double(durTotal.count()) );
  // printf("alpha shape time : %f percent \n", 100*double(dur2.count())/double(durTotal.count()) );
  // printf("refine      time : %f percent \n", 100*double(dur3.count())/double(durTotal.count()) );


  // print4debug(pm, 1);
  std::vector<size_t> nodeTags(pm->vertices.size());
  std::vector<double> coords(3*pm->vertices.size());
  size_t nNodes = 0;
  for (size_t i=0; i<pm->vertices.size(); i++){
    PolyMesh::Vertex* v = pm->vertices[i];
    size_t gmshTag = vertex2Tag[v];
    if (!v->he || gmshTag == -1 || !checkVertexConnection(v, alphaShapeTags[0])) continue;
    coords[3*nNodes+0] = v->position.x();
    coords[3*nNodes+1] = v->position.y();
    coords[3*nNodes+2] = v->position.z();
    nodeTags[nNodes++] = gmshTag;
  }
  nodeTags.resize(nNodes);
  coords.resize(3*nNodes);
  gmsh::vectorpair atags2D;
  atags2D.push_back(std::make_pair(2, alphaShapeTags[0]));
  gmsh::model::mesh::clear(atags2D);
  gmsh::vectorpair atags1D;
  atags1D.push_back(std::make_pair(1, alphaShapeTags[1]));
  gmsh::model::mesh::clear(atags1D);

  gmsh::model::mesh::addNodes(2, alphaShapeTags[0], nodeTags, coords);
  std::vector<size_t> triangles, trash;
  for (auto f : pm->faces){
    if (f->he == nullptr || f->data != alphaShapeTags[0]) continue;
    triangles.push_back(vertex2Tag[f->he->v]);
    triangles.push_back(vertex2Tag[f->he->next->v]);
    triangles.push_back(vertex2Tag[f->he->next->next->v]);
  }
  gmsh::model::mesh::addElementsByType(alphaShapeTags[0], 2, trash, triangles);
  
  // Create chained list of edges
  // std::vector< std::vector< PolyMesh::HalfEdge* >> edgeLoops;
  // std::unordered_set< PolyMesh::HalfEdge* > he_touched; 
  // std::vector<size_t> edges;
  // for (auto he : pm->hedges){
  //   if (he_touched.find(he) != he_touched.end()) continue;
  //   if (he->f == nullptr || he->f->data != alphaShapeTags[0]) continue;
  //   if (he->f->data == alphaShapeTags[0] && he->data == alphaShapeTags[1]){
  //     he_touched.insert(he);
  //     std::vector< PolyMesh::HalfEdge* > loop;
  //     PolyMesh::HalfEdge* he_loop = he;
  //     do {
  //       loop.push_back(he_loop);
  //       he_loop = getNextEdgeOnBoundary(he_loop, alphaShapeTags[1]);
  //       he_touched.insert(he_loop);
  //     } while(he_loop != he);
  //     edgeLoops.push_back(loop);
  //   }
  // }
  // for (auto lo : edgeLoops){
  //   for (auto he : lo){
  //     if (he->data != alphaShapeTags[1]) printf("woups..\n");
  //     edges.push_back(vertex2Tag[he->v]);
  //     edges.push_back(vertex2Tag[he->next->v]);
  //   }
  // }
  
  std::vector<size_t> edges;
  for (auto he : pm->hedges){
    if (he->data == alphaShapeTags[1] && he->f != nullptr && he->f->data == alphaShapeTags[0]) {
      edges.push_back(vertex2Tag[he->v]);
      edges.push_back(vertex2Tag[he->next->v]);
    }
  }
  gmsh::model::mesh::addElementsByType(alphaShapeTags[1], 1, trash, edges);
  delete pm;
}


void _decimateTriangulation(const int faceTag, const double thresholdDistance){
  PolyMesh* pm;
  GFace2PolyMesh(faceTag, &pm);
  // print4debug(pm, 1);
  pm->decimate(thresholdDistance);
  PolyMesh2GFace(pm, faceTag);
}

void getEdgesForEntities(const std::vector<int> &entities, std::vector<SPoint3>& allEdges, std::vector<size_t> &allEdgeNodes){
    for (size_t i=0; i<entities.size(); i++){
        std::vector<size_t> et, ent;
        GEdge* ge = GModel::current()->getEdgeByTag(entities[i]);
        for (auto l : ge->lines){
            allEdges.push_back(l->getVertex(0)->point());
            allEdges.push_back(l->getVertex(1)->point());
            allEdgeNodes.push_back(l->getVertex(0)->getNum());
            allEdgeNodes.push_back(l->getVertex(1)->getNum());
        }
    }
}

int whatIsTheColorOf2d (const SVector3 &P, const std::vector<SPoint3>& bndEdges){
  // compute winding number -- fast
  std::set<int> cs;
  // std::vector<int> cols;
  double pp[2] = {P.x(),P.y()};
  // for (auto c : colors){
  // if(c<0) continue;
  // if (cs.find(c) == cs.end()){
  //   cs.insert(c);
  int wn = 0;
  for (size_t i=0 ; i< bndEdges.size()/2 ; i++){
    // if (colors[i/2] == c){
    // double bb[2] = {pos[3*lines[i+1]],pos[3*lines[i+1]+1]};
    double aa[2] = {bndEdges[2*i].x(),bndEdges[2*i].y()};
    double bb[2] = {bndEdges[2*i+1].x(),bndEdges[2*i+1].y()};
    double area = robustPredicates::orient2d(aa,bb,pp); 
    if(aa[1]<= P.y()){
      if (bb[1] > P.y() && area < 0)wn++;
    }
    else if(bb[1]<= P.y()){
      if (area > 0)wn--;
    }
    // }
  }
  return wn;
    // if (wn != 0)cols.push_back(c);
  // }
  // }
  // if (cols.empty())return -1;
  // if (cols.size() == 1)return cols[0];
  // if (cols.size() == 2){
  //   return -10*std::max(cols[0],cols[1]) - std::min(cols[0],cols[1]);
  // }
  // return cols[0];
}

void PolyMeshDebugCheck(PolyMesh* pm){
  for (auto f : pm->faces){
    if (f->he == nullptr) continue;
    PolyMesh::HalfEdge* he = f->he;
    if (he->opposite == nullptr) continue;
    if (he->f == he->opposite->opposite->f) continue;
    printf("problem with face %d \n", f->data);
  }
}

void _conformAlphaShapeToBoundary(const std::vector<int> & alphaShapeTags, 
                                  const std::vector<int> & internalBoundaryTags, 
                                  const std::vector<int> & externalBoundaryTags,
                                  std::function<double(int, int, double, double, double, double)> sizeFieldCallback){
  // printf("starting conforming \n");
  // 1. create polymesh
  // GFace *gf = GModel::current()->getFaceByTag(alphaShapeTags[0]);
  PolyMesh *pm;
  GFace2PolyMesh(alphaShapeTags[0], &pm);
  // print4debug(pm, 0);
  for (auto f : pm->faces) f->data = alphaShapeTags[0];
  for (auto he : pm->hedges) if (he->opposite == nullptr) he->data = alphaShapeTags[1];
  // print4debug(pm, 1);
  recoverEdgesOfPolyMesh(&pm, alphaShapeTags[0], alphaShapeTags[1]);
  // print4debug(pm, 2);

  size_t newTag;
  gmsh::model::mesh::getMaxNodeTag(newTag);
  newTag++;
  // print4debug(pm, 2);

  // first we do the external boundaries
  // std::vector<SPoint3> extBndEdgeCoords;
  // std::vector<size_t> extBndEdgeNodes;
  // getEdgesForEntities(externalBoundaryTags, extBndEdgeCoords, extBndEdgeNodes);
  // size_t n_extBndEdges = extBndEdgeCoords.size()/2;

  // int n_debug = 10;
  // for (size_t i=0; i<n_extBndEdges; i++){
  //   double* a1 = &extBndEdgeCoords[2*i][0];
  //   double* a2 = &extBndEdgeCoords[2*i+1][0];
  //   std::stack<PolyMesh::HalfEdge*> allEdges;
  //   for (auto he : pm->hedges) allEdges.push(he);
  //   while (!allEdges.empty()){
  //     PolyMesh::HalfEdge* he = allEdges.top();
  //     allEdges.pop();
  //     if (he->f == nullptr) continue; 
  //     if (he->f->data != alphaShapeTags[0]) continue; 
  //     double* a3 = &he->v->position[0];
  //     double* a4 = &he->next->v->position[0];
  //     double a143 = robustPredicates::orient2d(a1,a4,a3);
  //     double a243 = robustPredicates::orient2d(a2,a4,a3);    
  //     double a123 = robustPredicates::orient2d(a1,a2,a3);
  //     double a124 = robustPredicates::orient2d(a1,a2,a4);
  //     if (fabs(a143) < 1e-16 || fabs(a243) < 1e-16 || fabs(a123) < 1e-16 || fabs(a124) < 1e-16) continue; // parallel ? 
  //     if (a143*a243 < 0 && a123*a124 < 0){
  //       double t = fabs(a143)/(fabs(a143)+fabs(a243));
  //       double vec[3] = {a2[0]-a1[0], a2[1]-a1[1], a2[2]-a1[2]};
  //       SVector3 new_intersection(a1[0]+t*vec[0], a1[1]+t*vec[1], a1[2]+t*vec[2]);
  //       double d0 = norm(new_intersection - he->v->position);
  //       double d1 = norm(new_intersection - he->next->v->position);
  //       double d2 = norm(new_intersection - he->next->next->v->position);
  //       double d3 = norm(new_intersection - he->opposite->next->v->position);
  //       double threshold = 1e-6; // FIXME : doesn't work with smaller threshold ...
  //       if (d0 < threshold || d1 < threshold || d2 < threshold || d3 < threshold) continue;
  //       pm->split_edge(he, new_intersection, newTag++);
  //       he->f->data = alphaShapeTags[0];
  //       he->next->opposite->f->data = alphaShapeTags[0];
  //       if (he->data != alphaShapeTags[1]){
  //         he->opposite->f->data = alphaShapeTags[0];
  //         he->opposite->next->next->opposite->f->data = alphaShapeTags[0];
  //       }
  //       else {
  //         he->next->opposite->f->data = he->f->data;
  //         he->opposite->f->data = he->next->opposite->next->opposite->f->data;
  //         he->data = alphaShapeTags[1]; // constrain them again
  //         he->next->opposite->next->data = alphaShapeTags[1]; // constrain them again
  //       }
  //     }
  //   }
  // }


  // PART 2 : Intersection of edges with the alpha shape edges
  std::vector<SPoint3> bndEdgeCoords;
  std::vector<size_t> bndEdgeNodes;
  std::vector<SPoint3> innerBndEdgeCoords;
  std::vector<size_t> innerBndEdgeNodes;
  std::vector<int> allBoundaryTags;
  allBoundaryTags.insert(allBoundaryTags.end(), externalBoundaryTags.begin(), externalBoundaryTags.end());
  allBoundaryTags.insert(allBoundaryTags.end(), internalBoundaryTags.begin(), internalBoundaryTags.end());
  
  getEdgesForEntities(internalBoundaryTags, innerBndEdgeCoords, innerBndEdgeNodes);
  getEdgesForEntities(allBoundaryTags, bndEdgeCoords, bndEdgeNodes);
  size_t n_bndEdges = bndEdgeCoords.size()/2;
  std::unordered_set<PolyMesh::Vertex*> controlNodes;

  // second we do the internal boundaries
  for (auto b : allBoundaryTags){
    GEdge* ge = GModel::current()->getEdgeByTag(b);
    GVertex* gv = ge->getBeginVertex();
    SVector3 X(gv->x(), gv->y(), gv->z());
    // printf("vertex at : %f, %f\n", X.x(), X.y());
    PolyMesh::Face* f = WalkGeneral(pm->faces[0], X.x(), X.y());
    if (f != nullptr && f->data == alphaShapeTags[0]){
      PolyMesh::HalfEdge* he = f->he;
      double d0 = norm(X - he->v->position);
      double d1 = norm(X - he->next->v->position);
      double d2 = norm(X - he->next->next->v->position);
      double threshold = 1e-6;
      if (d0 < threshold || d1 < threshold || d2 < threshold) {
        continue;
      }
      // printf("dmin = %.10f\n", std::min(d0, std::min(d1, d2)));
      // printf("adding a control node at position %g %g %g\n", X.x(), X.y(), X.z());
      pm->split_triangle(-1, X.x(), X.y(), X.z(), f, delaunayCriterion, nullptr);
      PolyMesh::Vertex* v = pm->vertices.back();
      controlNodes.insert(v);
      v->data = newTag++;
    }
  }

  // printf("control nodes added \n");

  // print4debug(pm, 3);
  for (size_t i=0; i<n_bndEdges; i++){
    double* a1 = &bndEdgeCoords[2*i][0];
    double* a2 = &bndEdgeCoords[2*i+1][0];
    // printf("edge coords done \n");
    std::stack<PolyMesh::HalfEdge*> allEdges;
    for (auto he : pm->hedges) allEdges.push(he);
    // printf("stack done \n");
    while (!allEdges.empty()){
      // printf("or here ? \n");
      PolyMesh::HalfEdge* he = allEdges.top();
      // if (he == nullptr) {
      //   printf("he is null \n");
      //   allEdges.pop();
      //   continue;
      // }
      allEdges.pop();
      if (he->f == nullptr) continue; 
      if (he->f->data != alphaShapeTags[0]) continue; 
      double* a3 = &he->v->position[0];
      double* a4 = &he->next->v->position[0];
      double a143 = robustPredicates::orient2d(a1,a4,a3);
      double a243 = robustPredicates::orient2d(a2,a4,a3);    
      double a123 = robustPredicates::orient2d(a1,a2,a3);
      double a124 = robustPredicates::orient2d(a1,a2,a4);
      // printf("if0 \n");
      if (fabs(a143) < 1e-16 || fabs(a243) < 1e-16 || fabs(a123) < 1e-16 || fabs(a124) < 1e-16) continue; // parallel ? 
      // printf("if1 \n");
      if (a143*a243 < 0 && a123*a124 < 0){
        // printf("in if1 \n");
        double t = fabs(a143)/(fabs(a143)+fabs(a243));
        double vec[3] = {a2[0]-a1[0], a2[1]-a1[1], a2[2]-a1[2]};
        SVector3 new_intersection(a1[0]+t*vec[0], a1[1]+t*vec[1], a1[2]+t*vec[2]);
        double d0 = norm(new_intersection - he->v->position);
        double d1 = norm(new_intersection - he->next->v->position);
        double d2 = norm(new_intersection - he->next->next->v->position);
        double d3 = norm(new_intersection - he->opposite->next->v->position);
        double threshold = 1e-6; // FIXME : doesn't work with smaller threshold ...
        if (d0 < threshold || d1 < threshold || d2 < threshold || d3 < threshold) continue;
        // printf("going to split edge \n");
        pm->split_edge(he, new_intersection, newTag++);
        // printf("split edge \n");
        he->f->data = alphaShapeTags[0];
        he->next->opposite->f->data = alphaShapeTags[0];
        // printf("if2 \n");
        if (he->data != alphaShapeTags[1]){
          // printf("in if if2 \n");
          he->opposite->f->data = alphaShapeTags[0];
          he->opposite->next->next->opposite->f->data = alphaShapeTags[0];
        }
        else {
          // printf("in else if2 \n");
          he->next->opposite->f->data = he->f->data;
          he->opposite->f->data = he->next->opposite->next->opposite->f->data;
          he->data = alphaShapeTags[1]; // constrain them again
          he->next->opposite->next->data = alphaShapeTags[1]; // constrain them again
        }
        // printf("finish\n");
      }
    }
  }

  // printf("finished splitting \n");
  
  // check and remove elements that are outside the domain
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
    SVector3 cc = 1./3.*(p0+p1+p2);
    int wn = whatIsTheColorOf2d(cc, innerBndEdgeCoords);
    if (wn != 0){
      f->data = -1;
    }
  }
  // now also color boundary half edges
  for (auto he : pm->hedges) he->data = -1;
  for (auto f : pm->faces){
    if (f->data == alphaShapeTags[0]) continue;
    PolyMesh::HalfEdge* he = f->he;
    do {
      if (he->opposite && he->opposite->f->data == alphaShapeTags[0]){
        he->data = alphaShapeTags[1];
        he->opposite->data = alphaShapeTags[1];
      }
      // else {
      //   he->data = -1;
      //   he->opposite->data = -1;
      // }
      he = he->next;
    } while (he != f->he);
  }
  PolyMeshDebugCheck(pm);
  // print4debug(pm, 4);
  // PolyMeshDebugCheck(pm);
  std::vector<PolyMesh::HalfEdge *> _touched;
  _delaunayCheck(pm, pm->hedges, &_touched, alphaShapeTags[1]);
  // print4debug(pm, 5);
  // printf("finished conforming \n");
  // 3. Delaunay refinement :)

  std::vector<double> sizeAtNodes(pm->vertices.size());
  std::unordered_map<PolyMesh::Vertex*, int> vertex2Tag;
  for (size_t i=4; i<pm->vertices.size(); i++){ // we're skipping the 4 vertices of the bounding box
    PolyMesh::Vertex* v = pm->vertices[i];
    vertex2Tag[v] = v->data;
    // printf("vertex tag : %d\n", v->data);
    sizeAtNodes[i] = sizeFieldCallback(2, v->data, v->position.x(), v->position.y(), v->position.z(), 0);
    // sizeAtNodes[i] = hMean > 0 ? hMean : sizeFieldCallback(2, v->data, v->position.x(), v->position.y(), v->position.z(), 0);
    v->data = i;
  }
  
  std::vector<PolyMesh::HalfEdge *> heVector;
  double coarseFactor_bnd = 0.3;
  double coarseFactor_in = 0.3;
  for (auto he : pm->hedges){
    if ((he->data == -1 && !freeSurfaceCheck(pm, he->v, alphaShapeTags[1])) || he->data == alphaShapeTags[1]){
      double d = norm(he->v->position - he->next->v->position);
      double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
      if (d < coarseFactor_in*size) {
        insert_sorted(heVector, he, heCompare);
      }
    }
  }
  while (!heVector.empty()){
    PolyMesh::HalfEdge *he = heVector.back();
    heVector.erase(heVector.end()-1);
    if (he->opposite == nullptr || he->opposite->f == nullptr || he->f == nullptr ) continue; 
    if (he->f->data != alphaShapeTags[0]) continue;
    if (freeSurfaceCheck(pm, he->v, alphaShapeTags[1]) && he->data == -1) continue; 
    bool control = false;
    if (controlNodes.find(he->v) != controlNodes.end()) control = true;
    double d = norm(he->v->position - he->next->v->position);
    double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
    if (d < coarseFactor_in*size){
      if (control) he = he->opposite;
      std::vector<PolyMesh::HalfEdge *> _nhes;
      if (he->data == alphaShapeTags[1] && d <coarseFactor_bnd*size){
        hedgeCollapseBoundaryEdge(pm, he, alphaShapeTags[0], alphaShapeTags[1], &_nhes);
      }
      else if (he->data != alphaShapeTags[1]){
        pm->hedgeCollapse(he, &_nhes);
      }
      auto it = std::find(heVector.begin(), heVector.end(), he->opposite);
      if (it != heVector.end()) heVector.erase(it);
      std::vector<PolyMesh::HalfEdge* > _t;
      _delaunayCheck(pm, _nhes, &_t, alphaShapeTags[1]);  
    }
  }

  // printf("coarsen done \n");
  // print4debug(pm, 6);

  std::vector<PolyMesh::Face *> _badFaces;
  double _limit = .4;         // Values to discuss...
  double _size = 1.;          // Values to discuss...
  double _sizeMinFactor = .5; // Values to discuss...
  for(auto f : pm->faces) {
    if (f->he && f->data == alphaShapeTags[0]){
      double q, R, s;
      SPoint3 cc;
      faceInfo(f->he, cc, &R, &q);
      s = _faceSize(f->he, sizeAtNodes);
      if((q < _limit && R/s > _sizeMinFactor) || R/s > _size) insert_sorted(_badFaces, f, faceCompareFct);
    }
  }
  while (!_badFaces.empty()){
    // exit(0);
    PolyMesh::Face *f = _badFaces.back();
    _badFaces.erase(_badFaces.end()-1);
    if (f->he == nullptr || f->data != alphaShapeTags[0]) {
      continue;
    }
    double q, R, s;
    SPoint3 cc;
    faceInfo(f->he, cc, &R, &q); // NB : q = 2*rho / R
    s = _faceSize(f->he, sizeAtNodes);
    if((q < _limit && R/s > _sizeMinFactor) || R/s > _size){
        PolyMesh::HalfEdge* heCandidate = nullptr;
        bool found;
        int onEdgeFlag;
        _Walk(f, cc, &heCandidate, &found, alphaShapeTags[1], &onEdgeFlag);
        if (onEdgeFlag != -1){ // A sanity check... if we are splitting a triangle with a 90° angle, and the opposite edge happens to be a boundary edge, we must split the edge, not the triangle
          PolyMesh::HalfEdge *flaggedHe = nullptr; 
          if (onEdgeFlag == 0) flaggedHe = heCandidate;
          else if (onEdgeFlag == 1) flaggedHe = heCandidate->next;
          else if (onEdgeFlag == 2) flaggedHe = heCandidate->next->next;
          if (flaggedHe->data == alphaShapeTags[1]) {
            found = false;
            heCandidate = flaggedHe;
          }
        }
        std::vector<PolyMesh::HalfEdge *> _touched;
        if (heCandidate && found){ // this means it is NOT a constrained edge
          int bndTag = alphaShapeTags[1];
          pm->split_triangle(-1, cc[0], cc[1], cc[2], heCandidate->f, delaunayCriterion, &bndTag, &_touched);
        }
        else { // this means it is a constrained edge
          SVector3 p = 0.5*(heCandidate->v->position + heCandidate->next->v->position);
          cc.setPosition(p.x(), p.y(), p.z());
          if ( heCandidate->opposite){
            pm->split_edge(heCandidate, cc, -1);
            heCandidate->next->opposite->f->data = heCandidate->f->data;
            heCandidate->opposite->f->data = heCandidate->next->opposite->next->opposite->f->data;
            heCandidate->data = alphaShapeTags[1]; // constrain them again
            heCandidate->opposite->data = alphaShapeTags[1]; // constrain them again
            heCandidate->next->opposite->next->data = alphaShapeTags[1]; // constrain them again
            heCandidate->next->opposite->next->opposite->data = alphaShapeTags[1]; // constrain them again
            std::vector<PolyMesh::HalfEdge *> new_hes;
            new_hes.push_back(heCandidate);
            new_hes.push_back(heCandidate->next);
            new_hes.push_back(heCandidate->next->next);
            new_hes.push_back(heCandidate->next->opposite);
            new_hes.push_back(heCandidate->next->opposite->next);
            new_hes.push_back(heCandidate->next->opposite->next->next);
            _delaunayCheck(pm, new_hes, &_touched, alphaShapeTags[1]);
          }
          SVector3 dist = cc-heCandidate->v->position;
          std::vector<PolyMesh::Vertex *> closeVertices;
          getVerticesWithinRadius(pm, pm->vertices.back(), dist.norm(), &closeVertices);
          if (closeVertices.size() > 0){
            _touched.clear();
            for (auto vv : closeVertices){
              std::vector<PolyMesh::HalfEdge *> _tlocal;
              std::vector<PolyMesh::HalfEdge *> _nhes;
              if (vv->he->f->data == alphaShapeTags[0] && pm->degree(vv) > 0 && !freeSurfaceCheck(pm, vv, alphaShapeTags[1])) {
                _deleteVertex(pm, vv, &_nhes);
              }
              _delaunayCheck(pm, _nhes, &_tlocal, alphaShapeTags[1]);
              _touched.insert(_touched.end(), _tlocal.begin(), _tlocal.end());
            }
            for(auto face_it = _badFaces.begin() ; face_it != _badFaces.end(); face_it++)
              if (!(*face_it)->he) _badFaces.erase(face_it--);
          }
        }
        pm->vertices.back()->data = pm->vertices.size()-1;
        vertex2Tag[pm->vertices.back()] = newTag++;
        sizeAtNodes.push_back(sizeFieldCallback(2, -1, cc[0], cc[1], cc[2], 0));
        std::vector<PolyMesh::Face *> _newFaces;
        for(auto _h : _touched){
            if(_h->f && _h->f->he != nullptr && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
              _newFaces.push_back(_h->f);
        }
        for(auto pf : _newFaces) {
            double q, R, s;
            SPoint3 cc;
            faceInfo(pf->he, cc, &R, &q);
            s = _faceSize(pf->he, sizeAtNodes);
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
  // printf("refine done \n");

  // Create chained list of edges
  // std::vector< std::vector< PolyMesh::HalfEdge* >> edgeLoops;
  // std::unordered_set< PolyMesh::HalfEdge* > he_touched; 
  // for (auto he : pm->hedges){
  //   if (he_touched.find(he) != he_touched.end()) continue;
  //   if (he->f == nullptr || he->f->data != alphaShapeTags[0]) continue;
  //   if (he->f->data == alphaShapeTags[0] && he->data == alphaShapeTags[1]){
  //     he_touched.insert(he);
  //     std::vector< PolyMesh::HalfEdge* > loop;
  //     PolyMesh::HalfEdge* he_loop = he;
  //     do {
  //       loop.push_back(he_loop);
  //       he_loop = getNextEdgeOnBoundary(he_loop, alphaShapeTags[1]);
  //       he_touched.insert(he_loop);
  //     } while(he_loop != he);
  //     edgeLoops.push_back(loop);
  //   }
  // }

  // print4debug(pm, 7);

  // 4. store in discrete entities
  // Msg::Info("saving back to gmsh...\n");
  // //print4debug(pm, 1);
  // exit(0);
  std::vector<size_t> nodeTags(pm->vertices.size());
  std::vector<double> coords(3*pm->vertices.size());
  size_t nNodes = 0;
  // printf("for loop start \n");
  for (size_t i=0; i<pm->vertices.size(); i++){
    PolyMesh::Vertex* v = pm->vertices[i];
    size_t gmshTag = vertex2Tag[v];
    // printf("before check \n");
    if (!v->he || gmshTag == -1 || !checkVertexConnection(v, alphaShapeTags[0])) continue;
    // printf("after check \n");
    coords[3*nNodes+0] = v->position.x();
    coords[3*nNodes+1] = v->position.y();
    coords[3*nNodes+2] = v->position.z();
    nodeTags[nNodes++] = gmshTag;
  }
  // printf("for loop start \n");
  nodeTags.resize(nNodes);
  coords.resize(3*nNodes);
  gmsh::vectorpair atags2D;
  atags2D.push_back(std::make_pair(2, alphaShapeTags[0]));
  gmsh::model::mesh::clear(atags2D);
  gmsh::vectorpair atags1D;
  atags1D.push_back(std::make_pair(1, alphaShapeTags[1]));
  gmsh::model::mesh::clear(atags1D);

  // printf("added nodes \n");

  gmsh::model::mesh::addNodes(2, alphaShapeTags[0], nodeTags, coords);
  std::vector<size_t> triangles, trash;
  for (auto f : pm->faces){
    // printf("f->data = %d \n", f->data);
    if (f->he == nullptr || f->data != alphaShapeTags[0]) continue;
    // printf("test node %d at position %g %g \n", f->he->v->data, f->he->v->position.x(), f->he->v->position.y());
    // printf("test node %d at position %g %g \n", f->he->next->v->data, f->he->next->v->position.x(), f->he->next->v->position.y());
    // printf("test node %d at position %g %g \n", f->he->next->next->v->data, f->he->next->next->v->position.x(), f->he->next->next->v->position.y());
    triangles.push_back(vertex2Tag[f->he->v]);
    if (triangles.back() == -1) printf("vertex tag is -1\n");
    triangles.push_back(vertex2Tag[f->he->next->v]);
    if (triangles.back() == -1) printf("vertex tag is -1\n");
    triangles.push_back(vertex2Tag[f->he->next->next->v]);
    if (triangles.back() == -1) printf("vertex tag is -1\n");
  }
  gmsh::model::mesh::addElementsByType(alphaShapeTags[0], 2, trash, triangles);
  // printf("added triangles \n");
  // printf("added triangles\n");
  std::vector<size_t> edges;
  for (auto he : pm->hedges){
    if (he->data == alphaShapeTags[1] && he->f != nullptr && he->f->data == alphaShapeTags[0]) {
      edges.push_back(vertex2Tag[he->v]);
      edges.push_back(vertex2Tag[he->next->v]);
    }
  }
  // for (auto lo : edgeLoops){
  //   for (auto he : lo){
  //     if (he->data != alphaShapeTags[1]) printf("woups..\n");
  //     edges.push_back(vertex2Tag[he->v]);
  //     edges.push_back(vertex2Tag[he->next->v]);
  //   }
  // }
  // printf("number of boundary edges : %lu\n", edges.size()/2);
  gmsh::model::mesh::addElementsByType(alphaShapeTags[1], 1, trash, edges);
  // printf("added edges \n");
  // printf("added edges\n");
  // gmsh::model::mesh::reclassifyNodes();
  // pm->reset();
  delete pm;

}


// ------------------------------ NEW FUNCTIONS -----------------------------

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
void registerAlphaShapeField(FieldManager* fm)
{
  fm->mapTypeName["AlphaShapeDistance"] = new FieldFactoryT<AlphaShapeDistanceField>();
}

static double _faceSizeFromMap(PolyMesh::HalfEdge *he, std::unordered_map<int, double> & sizeAtNodes){
  return 1./3.* (sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data] + sizeAtNodes[he->next->next->v->data]);
}

PolyMesh* _alphaShapeDelaunay2D(const int tag, const std::string boundaryModelName){
  GModel *current = GModel::current();
  GModel *model_boundary = GModel::findByName(boundaryModelName);
  auto bb = model_boundary->bounds();
  current->setAsCurrent();
  GFace* gf = GModel::current()->getFaceByTag(tag);
  PolyMesh *pm = new PolyMesh;
  for(auto &v : gf->mesh_vertices) {
    bb += SPoint3(v->x(), v->y(), 0);
  }
  bb *= 1.1;
  initialize_rectangle(pm, bb.min().x(), bb.max().x(), bb.min().y(),
                          bb.max().y());
  PolyMesh::Face* f = pm->faces[0];
  for(auto &v : gf->mesh_vertices) {
    f = WalkGeneral(f, v->x(), v->y());
    pm->split_triangle(0, v->x(), v->y(), 0, f, delaunayCriterion, nullptr);
    pm->vertices.back()->data = v->getNum();
  }
  return pm;
}

void _alphaShape2D(PolyMesh* pm, const double alpha, const int faceTag, const int bndTag, const int sizeFieldTag){
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
  std::unordered_map<int, double> sizeAtNodes(pm->vertices.size());
  for (auto v : pm->vertices){
    if (v->data == -1) continue;
    sizeAtNodes[v->data] = field->operator()(v->position.x(), v->position.y(), 0, NULL);
  }
  std::unordered_map<PolyMesh::Face*, bool> _touched;
  double hTriangle, R, q;
  double qualityThreshold = 0.;
  SPoint3 cc;
  for (size_t i = 0; i < pm->faces.size(); i++){
    if (pm->faces[i]->data == -2) continue;
    PolyMesh::Face *f = pm->faces[i];
    hTriangle = _faceSizeFromMap(f->he, sizeAtNodes);
    faceInfo(f->he, cc, &R, &q);
    if (R/hTriangle < alpha && !_touched[f] && q > qualityThreshold){
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
            // if (abs(hTriangle-minSize)/minSize < 1e-2){
            //   hTriangle *= surfaceConstraint;
            // }
            faceInfo(f_neigh->he, cc, &R, &q);
            if (R/hTriangle < alpha && q > qualityThreshold){
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


// static bool hedgeIntersect(PolyMesh::HalfEdge* he, const Coord<2> &bbmin, const Coord<2> &bbmax) {
//   BBox<2> bbox_he;
//   bbox_he.extends({he->v->position.x(), he->v->position.y()});
//   bbox_he.extends({he->next->v->position.x(), he->next->v->position.y()});
//   BBox<2> bbox_search;
//   bbox_search.extends(bbmin);
//   bbox_search.extends(bbmax);
//   return bbox_he.intersects(bbox_search);
// }



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

static std::vector<std::pair<PolyMesh::HalfEdge*,  SVector3> >
walkWithIntersections(SVector3 pfrom, SVector3 pto, PolyMesh::HalfEdge *searchstart) {
  std::vector<std::pair<PolyMesh::HalfEdge*,  SVector3> > res;
  PolyMesh::HalfEdge *he = searchstart;
  // search the starting triangle
  while (true) {
    auto s0 = robustPredicates::orient2d(*he->v, *he->next->v, pfrom);
    auto s1 = robustPredicates::orient2d(*he->next->v, *he->next->next->v, pfrom);
    auto s2 = robustPredicates::orient2d(*he->next->next->v, *he->v, pfrom);
    if (s0 >= 0 && s1 >= 0 && s2 >= 0) {
      break;
    }
    if (s0 < 0 && (s0 <= s1 || he->next->opposite == nullptr) && (s0 <= s2 || he->next->next->opposite == nullptr)) {
      he = he->opposite;
    } else if (s1 < 0 && (s1 <= s0 || he->opposite == nullptr) && (s1 <= s2 || he->next->next->opposite == nullptr)) {
      he = he->next->opposite;
    } else {
      he = he->next->next->opposite;
    }
  }

  // start with an he so that s0 >= 0
  while (true) {
    auto s0 = robustPredicates::orient2d(*he->v, *he->next->v, pto);
    if (s0 >= 0) break;
    he = he->next;
  }

  // walk to pto
  SVector3 current = pfrom;
  res.push_back({he, pfrom});
  while (true) {
    auto s0 = robustPredicates::orient2d(*he->v, *he->next->v, pto);
    if (s0 < 0) {
      printf("this should not happen.\n");
      he = he->opposite;
      continue;
    }
    double s1 = robustPredicates::orient2d(*he->next->v, *he->next->next->v, pto);
    double s2 = robustPredicates::orient2d(*he->next->next->v, *he->v, pto);
    double sto;

    if (s1 >= 0 && s2 >= 0) {
      //if (s0 != 0) {
        res.push_back({he, pto});
      //}
      break;
    }
    if (s2 >= 0) { // s1 is negative
      he = he->next->opposite;
      sto = -s1;
    }
    else if (s1 >= 0) { // s2 is negative
      he = he->next->next->opposite;
      sto = -s2;
    }
    else {
      auto s3 = robustPredicates::orient2d(current, pto, *he->next->next->v);
      if (s3 < 0) {
        he = he->next->next->opposite;
        sto = -s2;
      } else {
        he = he->next->opposite;
        sto = -s1;
      }
    }
    // we know that (current, pto) intersects he
    double sfrom = robustPredicates::orient2d(*he->v, *he->next->v, current);
    if (sfrom == 0 && sto == 0) { // colinear
      auto l = he->next->v->position-he->v->position;
      double d = dot(pto-he->v->position, l)/dot(l, l);
      if (d < 0) {
        current = he->v->position;
      }
      else if (d > 1) {
        current = he->next->v->position;
      }
      else {
        current = he->v->position*(1-d) + he->next->v->position*d;
      }
    }
    else {
      double d = sto/(sto-sfrom);
      current = pto*(1-d) + current*d;
    }
    res.push_back({he, current});
  }
  return res;
}


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
    PolyMesh::HalfEdge *he = _stack.top();
    _touched.push_back(he);
    _stack.pop();
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

void _edgeRecover(PolyMesh* pm, const int tag, const int bndTag, const std::string & boundaryModel, std::vector<PolyMesh::Vertex*> & controlNodes){
  GModel* gm_alphaShape = GModel::current();
  size_t newTag = gm_alphaShape->getMaxVertexNumber()+1;
  GModel* gm_boundary = GModel::findByName(boundaryModel);
  if (gm_boundary == nullptr) {
    Msg::Error("Boundary model not found");
    return;
  }
  std::vector<GEntity*> bndEntities;
  gm_boundary->getEntities(bndEntities, 1); 

  // Insert control nodes (--> i.e., all the nodes of the boundary mesh)
  controlNodes.clear();
  // std::unordered_set<GVertex*> gVertices;
  std::unordered_set<MVertex*> gVertices;
  BBox<2> searchbox;
  auto tic = std::chrono::high_resolution_clock::now();
  for (auto e : bndEntities){
    size_t n_elem = e->getNumMeshElements();
    for (size_t i_el = 0; i_el<n_elem; i_el++){
      MElement *elem = e->getMeshElement(i_el);
      if(elem->getDim() != 1) continue;
      gVertices.insert(elem->getVertex(0));
      gVertices.insert(elem->getVertex(1));
    }
  }
  double threshold = 1e-6;
  for (auto gv : gVertices){
    SVector3 X(gv->x(), gv->y(), gv->z());
    PolyMesh::Face* f = WalkGeneral(pm->faces[0], X.x(), X.y());
    if (f != nullptr/* && f->data == tag*/){
      PolyMesh::HalfEdge* he = f->he;
      int rsnap;
      std::tie(rsnap, X) = snapPoint(he, X, threshold);
      switch(rsnap) {
        case 0:
          {
            bool inside = f->data > 0;
            if (inside) {
              pm->split_triangle(-1, X.x(), X.y(), X.z(), f, delaunayCriterion, (void*)&bndTag);
              PolyMesh::Vertex* v = pm->vertices.back();
              v->data = newTag++;
              controlNodes.push_back(v);
            }
          }
          break;
        case 3:
          he = he->next;
        case 2:
          he = he->next;
        case 1:
          {
            bool inside = he->f->data > 0 || he->opposite->f->data > 0;
            if (inside) {
              pm->split_edge(he, X, -1);
              he->next->opposite->f->data = he->f->data;
              he->opposite->f->data = he->next->opposite->next->opposite->f->data;
              he->next->opposite->next->data = he->data;
              he->opposite->data = he->data;
              pm->vertices.back()->data = newTag++;
              controlNodes.push_back(pm->vertices.back());
            }
          }
          break;
        case 6:
          he = he->next;
        case 5:
          he = he->next;
        case 4:
          {
            bool inside = false;
            auto he0 = he;
            do {
              inside |= he->f->data > 0;
              he = he->opposite->next;
            }while (he != he0);
            if (inside) {
              controlNodes.push_back(he->v);
            }
          }
          break;
      }
    }
  }
  // print4debug(pm, 0);
  std::vector<std::pair<PolyMesh::HalfEdge*, SVector3>> crossed;
  auto *guess = pm->faces[0]->he;
  int cc = 0;
  for (const auto &e : bndEntities) {
    size_t n_elem = e->getNumMeshElements();
    for (size_t i_el = 0; i_el<n_elem; i_el++){
      cc++;
      MElement *elem = e->getMeshElement(i_el);
      if(elem->getDim() != 1) continue;
      SVector3 curpoint = elem->getVertex(0)->point();
      SVector3 destpoint = elem->getVertex(1)->point();
      auto inter = walkWithIntersections(curpoint, destpoint, guess);
      if (inter.size() != 0) {
        guess = inter.back().first;
      }
      PolyMesh::Vertex *lastv = nullptr;
      for (size_t i = 0; i < inter.size(); ++i) {
        // we know that the node belong to the hedge because contole points have been inserted previously
        auto point = inter[i].second;
        auto he = inter[i].first;
        PolyMesh::Vertex *newv = nullptr;
        // we are on the first vertex -> no split
        if ((he->v->position-point).norm() < threshold) {
          newv = he->v;
        }
        // we are on second vertex -> no split
        else if ((he->next->v->position-point).norm() < threshold) {
          newv = he->next->v;
        }
        // we are on second vertex -> no split
        else if ((he->next->next->v->position-point).norm() < threshold) {
          newv = he->next->next->v;
        }
        // split if the edge is inside the domain and we are not on a control point
        else if (i != inter.size()-1 && i != 0)  {
          if (he->f->data >= 0 || he->opposite->f->data >= 0) {
            pm->split_edge(he, point, -1);
            he->next->opposite->f->data = he->f->data;
            he->opposite->f->data = he->next->opposite->next->opposite->f->data;
            he->next->opposite->next->data = he->data;
            he->opposite->data = he->data;
            pm->vertices.back()->data = newTag++;
            newv = pm->vertices.back();
          }
          else {
            newv = nullptr;
          }
        }
        if (newv != nullptr && lastv != nullptr && newv != lastv) {
          pm->getEdge(lastv, newv)->data = e->tag();
          pm->getEdge(newv, lastv)->data = e->tag();
        }
        lastv = newv;
      }
    }
  }
  // print4debug(pm, 1);
  auto toc = std::chrono::high_resolution_clock::now();
  std::cout << "    Recover edges : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;


  // check and remove elements that are outside the domain
  
  tic = std::chrono::high_resolution_clock::now();
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
  toc = std::chrono::high_resolution_clock::now();

  std::cout << "    init geo octree : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;
  
  
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
  tic = std::chrono::high_resolution_clock::now();
  std::cout << "    Remove outside  : " << std::chrono::duration_cast<std::chrono::milliseconds>(tic - toc).count() << "ms" << std::endl;

  std::vector<PolyMesh::HalfEdge *> _touched;
  _delaunayCheckColors(pm, pm->hedges, &_touched);
  toc = std::chrono::high_resolution_clock::now();
  std::cout << "    Delaunay check  : " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << "ms" << std::endl;
}

bool boundaryCheck(PolyMesh* pm, PolyMesh::Vertex* v){
  PolyMesh::HalfEdge *he = v->he;
  if(he->data > 0) return true;
  do {
    he = he->opposite;
    if(he == nullptr) return true;
    he = he->next;
    if(he->data > 0) return true;
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

void _delaunayRefinement(PolyMesh* pm, const int tag, const int bndTag, const int sizeFieldTag, std::vector<PolyMesh::Vertex*> & controlNodes){
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
          printf("n = %d; sampling lenght : %f; %d \n", n, asdf->sampling_length, int(d/asdf->sampling_length));
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
  for (int i=0; i<pm->vertices.size(); i++){
    PolyMesh::Vertex* v = pm->vertices[i];
    sizeAtNodes[v->data] = field->operator()(v->position.x(), v->position.y(), 0);
    // printf("sizeAtNodes[%d] = %g\n", v->data, sizeAtNodes[v->data]);
    // sizeAtNodes[v->data] = BGM_MeshSize(gf, v->position.x(), v->position.y(), v->position.x(), v->position.y(), 0);
  }

  // print4debug(pm, 0);

  // Coarsen
  std::vector<PolyMesh::HalfEdge *> heVector;
  double coarseFactor_bnd = 0.3;
  double coarseFactor_in = 0.3;
  for (auto he : pm->hedges){
    if ((he->data == -1 && !boundaryCheck(pm, he->v)) || he->data > 0){
      double d = norm(he->v->position - he->next->v->position);
      double size = 0.5*(sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data]);
      if (d < coarseFactor_in*size) {
        insert_sorted(heVector, he, heCompare);
      }
    }
  }

  std::unordered_set<PolyMesh::Vertex*> controlNodesSet(controlNodes.begin(), controlNodes.end());
  while (!heVector.empty()){
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
      if (control) he = he->opposite;
      if (control && controlNodesSet.find(he->v) != controlNodesSet.end()) continue;
      std::vector<PolyMesh::HalfEdge *> _nhes;
      if (he->data > 0 && d <coarseFactor_bnd*size){
        continue;
        // hedgeCollapseBoundaryEdge(pm, he, tag, bndTag, &_nhes);
      }
      else if (he->data < 0){
        pm->hedgeCollapse(he, &_nhes);
      }
      auto it = std::find(heVector.begin(), heVector.end(), he->opposite);
      if (it != heVector.end()) heVector.erase(it);
      std::vector<PolyMesh::HalfEdge* > _t;
      _delaunayCheckColors(pm, _nhes, &_t);  
    }
  }
  
  // Refine
  std::vector<PolyMesh::Face *> _badFaces;
  double _limit = .4;         // Values to discuss...
  double _size = 1.;          // Values to discuss...
  double _sizeMinFactor = .5; // Values to discuss...
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


  while (!_badFaces.empty()){
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
      int onEdgeFlag;
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
          int heData = heCandidate->data;
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
      // sizeAtNodes[v->data] = BGM_MeshSize(gf, v->position.x(), v->position.y(), v->position.x(), v->position.y(), 0);
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

struct bndEdge {
  double x0, y0, x1, y1;
  int tag;
};

// static bool edgeIntersect(bndEdge* edge, const Coord<2> &bbmin, const Coord<2> &bbmax) {
//   BBox<2> bbox_ed;
//   bbox_ed.extends({edge->x0, edge->y0});
//   bbox_ed.extends({edge->x1, edge->y1});
//   BBox<2> bbox_search;
//   bbox_search.extends(bbmin);
//   bbox_search.extends(bbmax);
//   return bbox_ed.intersects(bbox_search);
// }

void alphaShapePolyMesh2Gmsh(PolyMesh* pm, const int tag, const int bndTag, const std::string & boundaryModel){
  // std::vector<std::pair<int, int>> dimTag;
  // dimTag.push_back(std::make_pair(2, tag));

  // color the boundary edges with the solid geometry
  GModel* gm_boundary = GModel::findByName(boundaryModel);
  GModel* gm_alphaShape = GModel::current();
  if (gm_boundary == nullptr) {
    Msg::Error("Boundary model not found");
    return;
  }
  std::vector<GEntity*> bndEntities;
  gm_boundary->getEntities(bndEntities, 1); 

  BBox<2> bbox;
  // std::unordered_set<MVertex*> gVertices;
  std::vector<bndEdge> bndEdges;
  std::unordered_map<int, std::vector<size_t>> bndMap;
  bndMap[bndTag] = std::vector<size_t>();
  for (auto e : bndEntities){
    bndMap[e->tag()] = std::vector<size_t>();
  }
  for (auto he : pm->hedges){
    if (he->data < 0 || he->f == nullptr || he->f->data != tag) continue;
    bndMap[he->data].push_back(he->v->data);
    bndMap[he->data].push_back(he->next->v->data); 
  }
  gm_alphaShape->deleteMesh();
  // gm_alphaShape->destroy(true);
  // gmsh::model::addDiscreteEntity(2, tag);

  std::vector<size_t> nodeTags;
  std::vector<double> coords;
  for (auto v : pm->vertices){
    if (v->data == -1 || v->he == nullptr || !checkVertexConnection(v, tag)) continue;
    coords.push_back(v->position.x());
    coords.push_back(v->position.y());
    coords.push_back(v->position.z());
    nodeTags.push_back(size_t(v->data));
  }
  gmsh::model::mesh::addNodes(2, tag, nodeTags, coords);
  
  std::vector<size_t> edTags;
  for (auto bnd : bndMap){
    // gmsh::model::addDiscreteEntity(1, bnd.first);
    gmsh::model::mesh::addElementsByType(bnd.first, 1, edTags, bnd.second);
  }

  std::vector<size_t> triangles, triangleTag;
  for (auto f : pm->faces){
    if (f->he == nullptr || f->data != tag) continue;
    int triangle[3] = {f->he->v->data, f->he->next->v->data, f->he->next->next->v->data};
    if (triangle[0] == -1 || triangle[1] == -1 || triangle[2] == -1) continue;
    for (auto n : triangle) triangles.push_back(size_t(n));
  }
  gmsh::model::mesh::addElementsByType(tag, 2, triangleTag, triangles);
  delete pm;
}

#endif
