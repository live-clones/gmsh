#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
#include "alphaShapes.h"
#include "gmsh.h"
#include "GmshMessage.h"

#include <iostream>



/* compute distance between 2 points -- 3D */
double twoPointsDistance(const double *p0, const double *p1){
  return sqrt( (p0[0]-p1[0])*(p0[0]-p1[0]) + (p0[1]-p1[1])*(p0[1]-p1[1]) + (p0[2]-p1[2])*(p0[2]-p1[2]));
}

/* compute distance between 2 points -- 2D */
double twoPointsDistance2D(const double *p0, const double *p1){
  return sqrt( (p0[0]-p1[0])*(p0[0]-p1[0]) + (p0[1]-p1[1])*(p0[1]-p1[1]));
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

/* verify if circumscribed radius is smaller than alpha threshold -- 2D */
double alphaShape2D(const size_t *t, const std::vector<double> &p, const double hMean){
  const double *p0 = &p[2*t[0]];
  const double *p1 = &p[2*t[1]];
  const double *p2 = &p[2*t[2]];
  const double a = twoPointsDistance2D(p0,p1);
  const double b = twoPointsDistance2D(p0,p2);
  const double c = twoPointsDistance2D(p1,p2);
  double s = (a+b+c)/2;
  double den = 4*sqrt(s*(s-a)*(s-b)*(s-c));
  double R = a*b*c / den;
  return R/hMean;
}

/* commpute the mean minimum edge length of all elements -- 3D */
double meanEdgeLength (const std::vector<double> &p, const std::vector<size_t> &tetrahedra){
  double hMean = 0;
  for (size_t i=0; i<tetrahedra.size(); i+=4){
    const double *p0 = &p[3*tetrahedra[i+0]];
    const double *p1 = &p[3*tetrahedra[i+1]];
    const double *p2 = &p[3*tetrahedra[i+2]];
    const double *p3 = &p[3*tetrahedra[i+3]];
    double d0 = twoPointsDistance(p0, p1);
    double d1 = twoPointsDistance(p0, p2);
    double hMin = std::min(d0, d1);
    double d2 = twoPointsDistance(p0, p3);
    hMin = std::min(hMin, d2);
    double d3 = twoPointsDistance(p1, p2);
    hMin = std::min(hMin, d3);
    double d4 = twoPointsDistance(p1, p3);
    hMin = std::min(hMin, d4);
    double d5 = twoPointsDistance(p2, p3);
    hMin = std::min(hMin, d5);
    hMean += hMin;
  }
  hMean = hMean / (tetrahedra.size()/4);
  return hMean;
}

/* commpute the mean minimum edge length of all elements -- 2D */
double meanEdgeLength2D (const std::vector<double> &p, const std::vector<size_t> &triangles){
  double hMean = 0;
  for (size_t i=0; i<triangles.size(); i+=3){
    const double *p0 = &p[2*triangles[i+0]];
    const double *p1 = &p[2*triangles[i+1]];
    const double *p2 = &p[2*triangles[i+2]];
    double d0 = twoPointsDistance2D(p0, p1);
    double d1 = twoPointsDistance2D(p0, p2);
    double hMin = std::min(d0, d1);
    double d2 = twoPointsDistance2D(p1, p2);
    hMin = std::min(hMin, d2);
    hMean += hMin;
  }
  hMean = hMean / (triangles.size()/3);
  return hMean;
}

/* face ordering convention */
static int _faces [4][3] = {{0,1,2}, {0,1,3}, {0,2,3}, {1,2,3}};

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

/* edge ordereing convetion */
static int _edges [3][2] = {{0,1}, {0,2}, {1,2}};

/* order the element edges according to convention */
void getOrderedEdge (const size_t *t, int i, size_t *e){
  size_t no1 = t[_edges[i][0]];
  size_t no2 = t[_edges[i][1]];
  if (no1 < no2){
    e[0] = no1;
    e[1] = no2;
  }
  else {
    e[0] = no2;
    e[1] = no1;
  }
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


int compareTwoInt (const void *a , const void *b){
  const size_t *e0 = (size_t*)a;
  const size_t *e1 = (size_t*)b;
  if (e0[0] < e1[0])return 1; 
  if (e0[0] > e1[0])return -1; 
  if (e0[1] < e1[1])return 1; 
  if (e0[1] > e1[1])return -1; 
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

/* compute the neighbors of all triangles, returned as a list of neighbors for each triangle
 * if a face is a boundary face, the value there is triangles.size()
 */
int computeTriNeighbors_ (const std::vector<size_t> &triangles, std::vector<size_t> &neigh){
  neigh.resize(triangles.size());
  for (size_t i=0;i<neigh.size();i++)neigh[i] = triangles.size();
  
  size_t *temp = new size_t [4*triangles.size()];
  size_t counter = 0;
  for (size_t i = 0; i < triangles.size(); i+=3){
    const size_t *t = &triangles[i];
    for (int j=0;j<3;j++){
      size_t e[2];
      getOrderedEdge (t, j, e);
      temp[counter++] = e[0];
      temp[counter++] = e[1];
      temp[counter++] = i/3;      
      temp[counter++] = j;
    }
  }
  qsort(temp, triangles.size(), 4*sizeof(size_t),compareTwoInt);

  // loop over edges
  counter  = 0;
  while (1){
    if (counter == triangles.size())break;
    size_t *et0 = &temp[4*(counter++)];
    if (counter == triangles.size())break;
    size_t *et1 = &temp[4*counter];

    if (compareTwoInt(et0,et1) == 0){
      neigh[3*et0[2]+et0[3]] = et1[2];
      neigh[3*et1[2]+et1[3]] = et0[2];
      counter++;
    }
  }

  delete [] temp;  
  return 0;  
}

/* return the alphashape of the delaunay triangulation of a cloud of points, with alpha = threshold. -- 2D */ 
int alphaShapes2D_(const double threshold,
		 const std::vector<double> &pts,
		 std::vector<size_t> &triangles, 
		 std::vector<std::vector<size_t> > &domains,
		 std::vector<std::vector<size_t> > &boundaries,
		 std::vector<size_t> &neigh, 
     const double meanValue){
  
  
  gmsh::model::mesh::triangulate(pts, triangles);

  for (size_t i = 0; i < triangles.size(); i++) triangles[i]--;
  double hMean; 
  if(meanValue < 0) hMean = meanEdgeLength2D(pts, triangles);
  else hMean = meanValue;

  computeTriNeighbors_ (triangles, neigh);

  std::vector<bool> _touched;
  _touched.resize(triangles.size()/3);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;

  for (size_t i = 0; i < triangles.size(); i+=3){
    size_t *t = &triangles[i];
    if (alphaShape2D(t, pts, hMean) < threshold && _touched[i/3] == false){
      std::stack<size_t> _s;
      std::vector<size_t> _domain;
      std::vector<size_t> _boundary;
      _s.push(i/3);
      _touched[i/3] = true;
      _domain.push_back(i/3);
      while(!_s.empty()){
        size_t t = _s.top();
        _s.pop();
        for (int j=0;j<3;j++){
          size_t tj = neigh[3*t+j];
          if (tj == triangles.size()){
            _boundary.push_back(t);
            _boundary.push_back(j);
          }
          else if (!_touched[tj]){
            if (alphaShape2D(&triangles[3*tj], pts, hMean) < threshold){
              _s.push(tj);
              _touched[tj] = true;
              _domain.push_back(tj);	    
            }	    
            else {
              _boundary.push_back(t);
              _boundary.push_back(j);	      
            }
          }
        }	  
      }
      boundaries.push_back(_boundary);
      domains.push_back(_domain); 
    }
  }

  for (size_t i = 0; i < triangles.size(); i++)triangles[i]++;
  return 0;
}

/* return the alphashape of the delaunay triangulation of a cloud of points, with alpha = threshold. -- 3D */
int alphaShapes3D_ (const double threshold,
		 const std::vector<double> &pts,
		 std::vector<size_t> &tetrahedra, 
		 std::vector<std::vector<size_t> > &domains,
		 std::vector<std::vector<size_t> > &boundaries,
		 std::vector<size_t> &neigh, 
     const double meanValue) {
  
  gmsh::model::mesh::tetrahedralize(pts, tetrahedra);
  

  for (size_t i = 0; i < tetrahedra.size(); i++)tetrahedra[i]--;
  double hMean;
  if (meanValue < 0) hMean = meanEdgeLength(pts,tetrahedra);
  else hMean = meanValue;
  
  computeTetNeighbors_ (tetrahedra, neigh);

  std::vector<bool> _touched;
  _touched.resize(tetrahedra.size()/4);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;

  for (size_t i = 0; i < tetrahedra.size(); i+=4){
      size_t *t = &tetrahedra[i];
      if (alphaShape(t, pts, hMean) < threshold && _touched[i/4] == false){
        std::stack<size_t> _s;
        std::vector<size_t> _domain;
        std::vector<size_t> _boundary;
        _s.push(i/4);
        _touched[i/4] = true;
        _domain.push_back(i/4);
        while(!_s.empty()){
          size_t t = _s.top();
          _s.pop();
          for (int j=0;j<4;j++){
            size_t tj = neigh[(4*t+j)]/4;
            if (tj == tetrahedra.size()){
              _boundary.push_back(t);
              _boundary.push_back(j);
            }
            else if (!_touched[tj]){
              if (alphaShape(&tetrahedra[4*tj], pts, hMean) < threshold){
                _s.push(tj);
                _touched[tj] = true;
                _domain.push_back(tj);	    
              }	    
              else {
                _boundary.push_back(t);
                _boundary.push_back(j);	      
              }
            }
          }	  
        }
        boundaries.push_back(_boundary);
        domains.push_back(_domain);
      }
  }
  for (size_t i = 0; i < tetrahedra.size(); i++)tetrahedra[i]++;
  return 0;
}

int alphaShapes_ (const double threshold,
     const int dim,
		 const std::vector<double> &pts,
		 std::vector<size_t> &elements, 
		 std::vector<std::vector<size_t> > &domains,
		 std::vector<std::vector<size_t> > &boundaries,
		 std::vector<size_t> &neigh, 
     const double meanValue){
  
  if (dim == 2){
    return alphaShapes2D_(threshold, pts, elements, domains, boundaries, neigh, meanValue);
  }
  else if (dim == 3){
    return alphaShapes3D_(threshold, pts, elements, domains, boundaries, neigh, meanValue);
  }
  else {
    Msg::Error("Invalid dimension");
  }
  return 0;
}

bool onlyBnd(std::vector<std::size_t> tet, size_t nBndPts){
  for (size_t i = 0; i < 4; i++)
  {
    if (tet[i] >= nBndPts) {return false;}
  }
  return true;
}

void constrainedAlphaShapes_(GModel* m, 
                            const int dim, 
                            const std::vector<double>& coord, 
                            const double alpha, 
                            const double meanValue,
                            std::vector<size_t> &tetrahedra, 
                            std::vector<std::vector<size_t> > &domains,
                            std::vector<std::vector<size_t> > &boundaries,
                            std::vector<size_t> &neigh)
{  
  int meshDim = m->getMeshStatus(false); 
  std::cout << "mesh Dim : " << meshDim << "\n";
  
  if (meshDim < dim-1){ // if no 1D boundary mesh for a 2D domain, if no 2D boundary mesh for a 3D domain --> so generate one
    GenerateMesh(m, dim-1);
  }
  else if (meshDim == dim)
  {
    GenerateMesh(m, dim-1);
  }
  
  
  /* initialize hxt mesh */
  HXTMesh *mesh;
  hxtMeshCreate(&mesh);

  /* set the gmsh surface mesh to hxt format */
  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  std::set<GRegion *, GEntityPtrLessThan> rs;
  rs = m->getRegions();
  std::vector<GRegion *> regions(rs.begin(), rs.end());
  Gmsh2HxtAlpha(regions, mesh, v2c, c2v);

  // all other fields of the options will be 0 or NULL (standard C behavior)
	HXTTetMeshOptions options = {
		.verbosity=2,
		.stat=1
	};
	// create the empty mesh
	hxtTetMesh(mesh, &options);

  uint32_t nBndPts = mesh->vertices.num;

  // create the bounding box of the mesh
	HXTBbox bbox;
	hxtBboxInit(&bbox);
	hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);

  uint32_t numNewPts = coord.size()/3;
  HXTNodeInfo nodeInfo[numNewPts];

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

  HXTDelaunayOptions delOptions = {
    .bbox = &bbox,
    .numVerticesInMesh = nBndPts,
    .insertionFirst = nBndPts,
    .allowOuterInsertion = 0, // if you set this to one, even vertices that are outside will be inserted
    .verbosity = 1,
  };

  /* Generate the tet mesh */
  hxtDelaunaySteadyVertices(mesh, &delOptions, nodeInfo, numNewPts);

 /* ------------------------alpha shapes of the newly generated mesh -----------------------------*/
  std::map<size_t, size_t> hxt2my;
  size_t count = 0;
  for (size_t i=0; i<mesh->tetrahedra.num; i++){
    if (mesh->tetrahedra.color[i] < UINT32_MAX)
    {
      hxt2my[i] = count;
      count++;
      std::vector<size_t> tet;
      for (size_t j = 0; j < 4; j++)
      {
        tet.push_back(mesh->tetrahedra.node[4*i+j]);
      }
      //if(!onlyBnd(tet, nBndPts)){
      tetrahedra.insert(tetrahedra.end(), tet.begin(), tet.end());
      //}
    }
  }
  
  computeTetNeighbors_ (tetrahedra, neigh);
  
  double hMean;
  std::vector<double> allMeshPoints;
  for (size_t i=0; i<mesh->vertices.num; i++){
    for (size_t dim=0; dim<3; dim++){
      allMeshPoints.push_back(mesh->vertices.coord[4*i+dim]);
    }
  }
  
  if (meanValue < 0) hMean = meanEdgeLength(allMeshPoints,tetrahedra);
  else hMean = meanValue;
  std::vector<bool> _touched;
  _touched.resize(tetrahedra.size()/4);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;
  for (size_t i = 0; i < tetrahedra.size(); i+=4){
      size_t *t = &tetrahedra[i];
      if (alphaShape(t, allMeshPoints, hMean) < alpha && _touched[i/4] == false){
        std::stack<size_t> _s;
        std::vector<size_t> _domain;
        std::vector<size_t> _boundary;
        _s.push(i/4);
        _touched[i/4] = true;
        _domain.push_back(i/4);
        while(!_s.empty()){
          size_t t = _s.top();
          _s.pop();
          for (int j=0;j<4;j++){
            size_t tj = neigh[4*t+j]/4;
            if (tj*4 == tetrahedra.size()){
              _boundary.push_back(t);
              _boundary.push_back(j);
            }
            else if (!_touched[tj]){
              if (alphaShape(&tetrahedra[4*tj], allMeshPoints, hMean) < alpha){
                _s.push(tj);
                _touched[tj] = true;
                _domain.push_back(tj);	    
              }	    
              else {
                _boundary.push_back(t);
                _boundary.push_back(j);	      
              }
            }
          }	  
        }
        boundaries.push_back(_boundary);
        domains.push_back(_domain);
      }
  }
  /* ------------------------------------------------------------------ */

  /* write back to gmsh format */
  Hxt2GmshAlpha(regions, mesh, v2c, c2v);
  m->renumberMeshVertices();
  m->renumberMeshElements();

  /* convert tetrahedra points to gmsh global identifier */
  for (size_t i = 0; i < tetrahedra.size(); i++)
  { 
    tetrahedra[i] = c2v[tetrahedra[i]]->getNum();
  }

  hxtMeshDelete(&mesh);
}

/*
 * filename : the 2D boundary mesh
 * coord : vector of 3D coords of the nodes
 */
void createHxtMesh_(const std::string &inputMesh, const std::vector<double>& coord, const std::string& outputMesh, std::vector<double> &pts, std::vector<std::size_t> &tets){
  /* NB : filename should be a 2D surface mesh */
  
  /* create the hxt mesh data struct */
  const char *cstr = &inputMesh[0];
  HXTMesh* mesh;
  hxtMeshCreate(&mesh);
  
  /* read the gmsh 2D surface mesh */
  hxtMeshReadGmsh(mesh, cstr); // faire une autre avec géométrie deja loadée (gmsh2hxt) --> GModel::current() if (pas de triangles) : générer maillage 2D

  /* add the internal nodes from vector coord */
  double arr[coord.size()];
  std::copy(coord.begin(),coord.end(),arr);
  hxtAddNodes(mesh, arr, coord.size()/3);

  /* generate and write the tet mesh */
  HXTTetMeshOptions options = {.verbosity=2, .refine=0, .optimize=0, .quality={.min=0.35}, .nodalSizes={.factor=1.0}};
  hxtTetMesh(mesh, &options);
  hxtMeshWriteGmsh( mesh, &outputMesh[0]); // enlever

  // hxt2gmsh

  for (size_t i=0; i<mesh->vertices.num; i++){
    for (size_t j=0; j<3; j++){
      pts.push_back(mesh->vertices.coord[4*i+j]);
    }
  }

  for (size_t i=0; i<mesh->tetrahedra.num; i++){
    for (size_t j=0; j<4; j++){
      tets.push_back(mesh->tetrahedra.node[4*i+j]);
    }
  }


}
