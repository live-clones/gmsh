#include "GmshConfig.h"
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

/* edge ordering convention in 2D */
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
		 const std::vector<double> &nodalSize,
     std::vector<size_t> &triangles, 
		 std::vector<std::vector<size_t> > &domains,
		 std::vector<std::vector<size_t> > &boundaries,
		 std::vector<size_t> &neigh){
  
  gmsh::model::mesh::triangulate(pts, triangles);
  const size_t numPts = (int)(pts.size()/2);
  std::vector<double> h(numPts); 
  double hMean;
  if (nodalSize.size() == 1) {
    if (nodalSize[0] < 0) hMean = meanEdgeLength2D(pts,triangles);
    else hMean = nodalSize[0];
    for (size_t i = 0; i < numPts; i++)
    {
      h[i] = hMean;
    }
  }
  else if (nodalSize.size() == numPts) {
    for (size_t i = 0; i < numPts; i++)
    {
      h[i] = nodalSize[i];
    }
  }

  for (size_t i = 0; i < triangles.size(); i++) triangles[i]--;

  //double hMean; 
  // if(meanValue < 0) hMean = meanEdgeLength2D(pts, triangles);
  // else hMean = meanValue;

  computeTriNeighbors_ (triangles, neigh);

  std::vector<bool> _touched;
  _touched.resize(triangles.size()/3);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;
  double hTriangle;
  for (size_t i = 0; i < triangles.size(); i+=3){
    size_t *t = &triangles[i];
    hTriangle = (h[t[0]] + h[t[1]] + h[t[2]])/3;
    if (alphaShape2D(t, pts, hTriangle) < threshold && _touched[i/3] == false){
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
            size_t *t_neigh = &triangles[3*tj]; 
            hTriangle = (h[t_neigh[0]] + h[t_neigh[1]] + h[t_neigh[2]])/3;
            if (alphaShape2D(t_neigh, pts, hTriangle) < threshold){
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
     const std::vector<double> &nodalSize,
		 std::vector<size_t> &tetrahedra, 
		 std::vector<std::vector<size_t> > &domains,
		 std::vector<std::vector<size_t> > &boundaries,
		 std::vector<size_t> &neigh) {
  
  gmsh::model::mesh::tetrahedralize(pts, tetrahedra);
  
  const size_t numPts = (int)(pts.size()/3);
  for (size_t i = 0; i < tetrahedra.size(); i++)tetrahedra[i]--;
  std::vector<double> h; 
  double hMean(numPts);
  if (nodalSize.size() == 1) {
    if (nodalSize[0] < 0) hMean = meanEdgeLength(pts,tetrahedra);
    else hMean = nodalSize[0];
    for (size_t i = 0; i < numPts; i++)
    {
      h[i] = hMean;
    }
  }
  else if (nodalSize.size() == numPts) {
    for (size_t i = 0; i < numPts; i++)
    {
      h[i] = nodalSize[i];
    }
  }
  // if (meanValue < 0) hMean = meanEdgeLength(pts,tetrahedra);
  // else hMean = meanValue;
  
  computeTetNeighbors_ (tetrahedra, neigh);

  std::vector<bool> _touched;
  _touched.resize(tetrahedra.size()/4);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;
  double hTet;
  for (size_t i = 0; i < tetrahedra.size(); i+=4){
      size_t *t = &tetrahedra[i];
      hTet = (h[t[0]] + h[t[1]] + h[t[2]] + h[t[3]])/4; 
      if (alphaShape(t, pts, hTet) < threshold && _touched[i/4] == false){
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
            if (tj*4 == tetrahedra.size()){
              _boundary.push_back(t);
              _boundary.push_back(j);
            }
            else if (!_touched[tj]){
              size_t *t_neigh = &tetrahedra[4*tj];
              hTet = (h[t_neigh[0]] + h[t_neigh[1]] + h[t_neigh[2]] + h[t_neigh[3]])/4; 
              if (alphaShape(t_neigh, pts, hTet) < threshold){
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
     const std::vector<double> &nodalSize,
		 std::vector<size_t> &elements, 
		 std::vector<std::vector<size_t> > &domains,
		 std::vector<std::vector<size_t> > &boundaries,
		 std::vector<size_t> &neigh){
  
  if (dim == 2){
    return alphaShapes2D_(threshold, pts, nodalSize, elements, domains, boundaries, neigh);
  }
  else if (dim == 3){
    return alphaShapes3D_(threshold, pts, nodalSize, elements, domains, boundaries, neigh);
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

bool checkBndColor(const size_t *t, std::vector<size_t> &bndColor, const std::vector<size_t> &controlNodeIndices){
  size_t nBnd = 0;
  for (size_t i = 0; i < 4; i++)
  {
    if (bndColor[t[i]])
      nBnd++;
  }
  return nBnd > 2;
  // if (nBnd > 2) {
  //   for (size_t i = 0; i < 4; i++){
  //     if (std::find(controlNodeIndices.begin(), controlNodeIndices.end(), t[i]) != controlNodeIndices.end()){
  //       return false;
  //     }
  //   }
  //   return true;
  // }
  // return false;
}

void constrainedAlphaShapes2D_(GModel* m, 
                            const int dim, 
                            const int tag,
                            const std::vector<double>& coord,
                            const std::vector<int>& nodeTags, 
                            const double alpha, 
                            const double meanValue,
                            std::vector<size_t> &triangles, 
                            std::vector<std::vector<size_t> > &domains,
                            std::vector<std::vector<size_t> > &boundaries,
                            std::vector<size_t> &neigh, 
                            double &hMean,
                            const std::vector<int> &controlNodes)
{
  
  
  std::map<int,int> g2i;
  int count = 0;
  for (size_t i=0; i<controlNodes.size(); i++){
    g2i.insert(std::pair<int,int>(controlNodes[i], count));
    count++;
  }
  std::vector<std::size_t> tags1D;
  std::vector<double> coord1D, pCoord1D;
  gmsh::model::mesh::getNodes(tags1D, coord1D,pCoord1D,1,-1,false,false);
  for (size_t i=0; i<tags1D.size(); i++){
    g2i.insert(std::pair<int,int>(tags1D[i], count));
    count++;
  }                           
  for (size_t i=0; i<nodeTags.size(); i++){
    g2i.insert(std::pair<int,int>(nodeTags[i], count));
    count++;
  }

  std::vector<int> elementTypes;
  std::vector<std::vector<std::size_t> > elementTags;
  std::vector<std::vector<std::size_t> > elementNodeTags;
  
  gmsh::model::mesh::getElements(elementTypes, elementTags, elementNodeTags, 2, tag);
  std::vector<size_t> tris;
  for (size_t i = 0; i < elementNodeTags[0].size(); i++)
  {
    triangles.push_back(elementNodeTags[0][i]);
    tris.push_back(g2i[elementNodeTags[0][i]]);
  }
  std::vector<double> allNodeCoords; 
  for (size_t i = 0; i < controlNodes.size(); i++)
  {
    std::vector<double> c, pc;
    int d0, t0;
    gmsh::model::mesh::getNode(controlNodes[i],c, pc,d0,t0);
    allNodeCoords.push_back(c[0]);
    allNodeCoords.push_back(c[1]);
  }
  for (size_t i = 0; i < coord1D.size()/3; i++)
  {
    allNodeCoords.push_back(coord1D[3*i+0]);
    allNodeCoords.push_back(coord1D[3*i+1]);
  }
  for (size_t i = 0; i < coord.size()/3; i++)
  {
    allNodeCoords.push_back(coord[3*i+0]);
    allNodeCoords.push_back(coord[3*i+1]);
  }

  //double hMean;
  if (meanValue < 0) hMean = meanEdgeLength2D(allNodeCoords,tris);
  else hMean = meanValue;
  computeTriNeighbors_ (tris, neigh);

  // The alpha-shape
  std::vector<bool> _touched;
  _touched.resize(tris.size()/3);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;
  for (size_t i = 0; i < tris.size(); i+=3){
    size_t *t = &tris[i];
    if (alphaShape2D(t, allNodeCoords, hMean) < alpha && _touched[i/3] == false){
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
          if (tj == tris.size()){
            _boundary.push_back(t);
            _boundary.push_back(j);
          }
          else if (!_touched[tj]){
            size_t *t_neigh = &tris[3*tj]; 
            if (alphaShape2D(t_neigh, allNodeCoords, hMean) < alpha){
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

}

void generateMesh3D_(const std::vector<double>& coord, const std::vector<int>& nodeTags){
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

  /* ------------------------------------------------------------------ */

  /* write back to gmsh format, and do not keep "external elements" */
  /*
  for (size_t i=0; i<mesh->tetrahedra.num; i++){
    for (size_t j = 0; j < 4; j++)
    {
      if (controlIndices.find(mesh->tetrahedra.node[4*i+j]) != controlIndices.end()){
        mesh->tetrahedra.color[i] = UINT64_MAX;
      }
    }
  }
  */
  Hxt2GmshAlpha(regions, mesh, v2c, c2v);

  /* reset the vertex indices */
  for (size_t i=nBndPts; i<mesh->vertices.num; i++){
    MVertex* oldv = c2v[i];
    if(nodeTags.size()){
      oldv->forceNum(nodeTags[i-nBndPts]);
    }
  }

  hxtMeshDelete(&mesh);

  // /* convert tetrahedra points to gmsh global identifier */
  // for (size_t i=0; i < mesh->tetrahedra.num; i++){
  //   if (mesh->tetrahedra.color[i] > mesh->brep.numVolumes)
  //     continue;
  //   for (size_t j = 0; j < 4; j++){
  //       tetrahedra.push_back(c2v[mesh->tetrahedra.node[4*i+j]]->getNum());
  //   }
  // }

 
  //int meshDim = m->getMeshStatus(false); 
}

void constrainedAlphaShapes3D_(GModel* m,  
                            const int dim,
                            const std::vector<double>& coord, 
                            const std::vector<int>& nodeTags,           
                            const double alpha, 
                            const double meanValue,
                            std::vector<size_t> &tetrahedra, 
                            std::vector<std::vector<size_t> > &domains,
                            std::vector<std::vector<size_t> > &boundaries,
                            std::vector<size_t> &neigh, 
                            double &hMean,
                            const std::vector<int> &controlNodes)
{  

 /* ------------------------alpha shapes of the newly generated mesh -----------------------------*/
  /*
  std::map<std::size_t,std::size_t> controlIndices;
  size_t count=0;
  for (size_t i = 0; i < mesh->lines.num; i++)
  {
    controlIndices[mesh->lines.node[2*i+0]] = count++;
    controlIndices[mesh->lines.node[2*i+1]] = count++;
  }
  */
  
  // setFlagsToProcessOnlyVolumesInBrep(mesh);
  // hxtOptimizeTetrahedra(mesh,&optiOptions);

   /* initialize hxt mesh */
  // HXTMesh *mesh;
  // hxtMeshCreate(&mesh);

  // /* set the gmsh surface mesh to hxt format */
  // std::map<MVertex *, uint32_t> v2c;
  // std::vector<MVertex *> c2v;
  // std::set<GRegion *, GEntityPtrLessThan> rs;
  // rs = m->getRegions();
  // std::vector<GRegion *> regions(rs.begin(), rs.end());
  // std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
  // Gmsh2HxtAlpha(regions, mesh, v2c, c2v);
  
  // uint32_t nBndPts = mesh->vertices.num;

  std::vector<size_t> elementsTags;
  std::vector<size_t> elementNodeTags;
  gmsh::model::mesh::getElementsByType(4, elementsTags, elementNodeTags);

  std::vector<size_t> nTags;
  std::vector<double> nCoords;
  std::vector<double> pCoords;
  gmsh::model::mesh::getNodes(nTags, nCoords, pCoords, -1, -2, true, false);

  std::map<size_t, uint32_t> g2i;
  for (size_t i=0; i<nTags.size(); i++){
    g2i[nTags[i]] = i;
  }
  
  for (size_t i=0; i<elementNodeTags.size(); i++){
    tetrahedra.push_back(g2i[elementNodeTags[i]]);
  }
  

  // std::vector<size_t> fluidTets;
  // for (size_t i=0; i<mesh->tetrahedra.num; i++){
  //   /*
  //   for (size_t j = 0; j < 4; j++)
  //   {
  //     if (controlIndices.find(mesh->tetrahedra.node[4*i+j]) != controlIndices.end()){
  //       flag = true; break;
  //     }
  //   }
  //   */
  //   if (mesh->tetrahedra.color[i] < mesh->brep.numVolumes){
  //     for (size_t j = 0; j < 4; j++){
  //       fluidTets.push_back(mesh->tetrahedra.node[4*i+j]); 
  //     }
  //   }
  // }
  
  computeTetNeighbors_ (tetrahedra, neigh);
  
  //double hMean;
  // std::vector<double> allMeshPoints;
  // for (size_t i=0; i<mesh->vertices.num; i++){
  //   for (size_t dim=0; dim<3; dim++){
  //     allMeshPoints.push_back(mesh->vertices.coord[4*i+dim]);
  //   }
  // }

  // std::vector<size_t> bndColor;
  // std::vector<size_t> controlNodeIndices;
  // for (size_t i=0; i<mesh->vertices.num; i++){
  //   bndColor.push_back(i<nBndPts && c2v[i]->getNum() > controlNodes.size());
  //   if (i<nBndPts && c2v[i]->getNum() <= controlNodes.size() ){
  //      controlNodeIndices.push_back(i);
  //   }
  // }

  if (meanValue < 0) hMean = meanEdgeLength(nCoords, tetrahedra);
  else hMean = meanValue;
  std::cout << "hMean = " << hMean << "\n";

  std::vector<bool> _touched;
  _touched.resize(tetrahedra.size()/4);
  for (size_t i=0;i<_touched.size();i++)_touched[i] = false;
  double alpha_test;
  for (size_t i = 0; i < tetrahedra.size(); i+=4){
      size_t *t = &tetrahedra[i];
      //if ((alphaShape(t, allMeshPoints, hMean) < alpha || checkBndColor(t, bndColor, controlNodeIndices)) && _touched[i/4] == false){
      // if (checkBndColor(t, bndColor, controlNodeIndices)) alpha_test = 1.5 * alpha;
      // else alpha_test = alpha;
      alpha_test = alpha;
      if (alphaShape(t, nCoords, hMean) < alpha_test && _touched[i/4] == false){
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
              //if (alphaShape(&tetrahedra[4*tj], allMeshPoints, hMean) < alpha || checkBndColor(&tetrahedra[4*tj], bndColor, controlNodeIndices)){
              // if (checkBndColor(&tetrahedra[4*tj], bndColor, controlNodeIndices)) alpha_test = 1.5 * alpha;
              // else alpha_test = alpha;
              alpha_test = alpha;
              if (alphaShape(&tetrahedra[4*tj], nCoords, hMean) < alpha_test){
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

}

void constrainedAlphaShapes_(GModel* m, 
                            const int dim, 
                            const int tag,
                            const std::vector<double>& coord,
                            const std::vector<int>& nodeTags, 
                            const double alpha, 
                            const double meanValue,
                            std::vector<size_t> &tetrahedra, 
                            std::vector<std::vector<size_t> > &domains,
                            std::vector<std::vector<size_t> > &boundaries,
                            std::vector<size_t> &neigh, 
                            double &hMean,
                            const std::vector<int> &controlNodes)
{
  std::set<GRegion *, GEntityPtrLessThan> rs;
  rs = m->getRegions();
  std::vector<GRegion *> regions(rs.begin(), rs.end());
  std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
  gmsh::model::mesh::generateMesh(dim, tag, 0, coord, nodeTags);
  if (dim == 2) constrainedAlphaShapes2D_(m, dim, tag, coord, nodeTags, alpha, meanValue, tetrahedra, domains, boundaries, neigh, hMean, controlNodes);
  else if (dim == 3) constrainedAlphaShapes3D_(m, dim, coord, nodeTags, alpha, meanValue, tetrahedra, domains, boundaries, neigh, hMean, controlNodes);
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
  std::vector<double> arr = coord;
  hxtAddNodes(mesh, &arr[0], coord.size()/3);

  /* generate and write the tet mesh */
  HXTTetMeshOptions options = {};
  options.verbosity=3;
  options.refine=1;
  options.optimize=1;
  options.quality.min=0.35;
  options.nodalSizes.factor=1.0;
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

void generateMesh_(const int dim, const int tag, const bool refine, const std::vector<double> &coord, const std::vector<int> &nodeTags){
  // -----------------  1D ------------------------------
  std::vector<double> pCoord;
  gmsh::model::getParametrization(dim, tag, coord, pCoord);
  
  if (dim == 1){
    Msg::Info("generating mesh for edge %d\n",tag);
    deMeshGEdge killer;
    GEdge *ge = GModel::current()->getEdgeByTag(tag);
    if (!ge)return;
    killer(ge);
    std::vector<int> index(pCoord.size(), 0);
    for (size_t i = 0 ; i != index.size() ; i++) {
      index[i] = i;
    }
    sort(index.begin(), index.end(), [&](const int& a, const int& b) { return (pCoord[a] < pCoord[b]);});
    for (auto t : index){
      GPoint gp = ge->point(pCoord[t]);
      MEdgeVertex *vv = new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, pCoord[t], nodeTags[t]);
      ge->mesh_vertices.push_back(vv);   
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
    Msg::Info("generating surface mesh for face %d\n",tag);
    deMeshGFace killer;
    GFace *gf = GModel::current()->getFaceByTag(tag);
    if (!gf)return;
    killer(gf);
    std::vector<double> cc = pCoord;
    PolyMesh *pm = GFaceInitialMesh(tag, 1, &cc);
    std::vector<GEdge*> ed = gf->edges();
    std::map<int,MVertex*> vs;
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
      PolyMesh::HalfEdge *he = pm->faces[i]->he;
      int a = he->v->data;
      int b = he->next->v->data;
      int c = he->next->next->v->data;
      if (a != -1 && b != -1 && c != -1){
        MVertex *va,*vb,*vc;
        std::map<int,MVertex*>::iterator ita = vs.find(a);
        std::map<int,MVertex*>::iterator itb = vs.find(b);
        std::map<int,MVertex*>::iterator itc = vs.find(c);
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
    // pm->print4debug(1);
    delete pm;
  }
  // -----------------  3D ------------------------------
  else if (dim == 3){
    generateMesh3D_(coord, nodeTags);
  }
}

static double faceQuality(PolyMesh::HalfEdge *he, GFace *gf)
{
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  // WRONG !!
  // double uv[2] = {0,0};
  // SPoint3 x0 = SPoint3(v0->position.x(), v0->position.y(), v0->position.z());
  // SPoint3 x1 = SPoint3(v1->position.x(), v1->position.y(), v1->position.z());
  // SPoint3 x2 = SPoint3(v2->position.x(), v2->position.y(), v2->position.z());
  // GPoint p0 = gf->closestPoint(x0,uv);
  // GPoint p1 = gf->closestPoint(x1,uv);
  // GPoint p2 = gf->closestPoint(x2,uv);
  GPoint p0 = gf->point(v0->position.x(), v0->position.y());
  GPoint p1 = gf->point(v1->position.x(), v1->position.y());
  GPoint p2 = gf->point(v2->position.x(), v2->position.y());
  return qmTriangle::gamma(p0.x(), p0.y(), p0.z(), p1.x(), p1.y(), p1.z(),
                           p2.x(), p2.y(), p2.z());
}

static void faceCircumCenter(PolyMesh::HalfEdge *he, GFace *gf, double *res,
                             double *uv, double* R)
{
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  // double uv2[2] = {0,0};
  // SPoint3 x0 = SPoint3(v0->position.x(), v0->position.y(), v0->position.z());
  // SPoint3 x1 = SPoint3(v1->position.x(), v1->position.y(), v1->position.z());
  // SPoint3 x2 = SPoint3(v2->position.x(), v2->position.y(), v2->position.z());
  // GPoint p0 = gf->closestPoint(x0,uv2);
  // GPoint p1 = gf->closestPoint(x1,uv2);
  // GPoint p2 = gf->closestPoint(x2,uv2);
  GPoint p0 = gf->point(v0->position.x(), v0->position.y());
  GPoint p1 = gf->point(v1->position.x(), v1->position.y());
  GPoint p2 = gf->point(v2->position.x(), v2->position.y());
  double q0[3] = {p0.x(), p0.y(), p0.z()};
  double q1[3] = {p1.x(), p1.y(), p1.z()};
  double q2[3] = {p2.x(), p2.y(), p2.z()};
  circumCenterXYZ(q0, q1, q2, res, uv);
  double v[3] = {q0[0] - res[0], q0[1] - res[1], q0[2] - res[2]};
  *R = norm3(v);
}

static double faceSize(PolyMesh::HalfEdge *he, GFace *gf, std::map<PolyMesh::Vertex*, double> v2sizeAtNodes){
  return 1./3.* (v2sizeAtNodes[he->v] + v2sizeAtNodes[he->next->v] + v2sizeAtNodes[he->next->next->v]);
}

PolyMesh::Vertex* findVertex(PolyMesh* pm, size_t num){
  size_t i = 0;
  while(i < pm->vertices.size()){
    if (pm->vertices[i]->data == num) return pm->vertices[i];
    i+=1;
  }
  return nullptr;
}

void Walk(PolyMesh::Face *f, double x, double y, PolyMesh::HalfEdge** heCandidate, bool* found)
{
  // heCandidate = nullptr;
  double POS[2] = {x, y};
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
      /* printf("Face %g %g %g / %g %g %g / %g %g %g \n",
                v0->position.x(), v0->position.y(), v0->position.z(),
                v1->position.x(), v1->position.y(), v1->position.z(),
                v2->position.x(), v2->position.y(), v2->position.z());
                printf("point %g %g CURRENT FACE %p %g %g %g\n", x,y,he->f,
                s0,s1,s2); */
      // getchar();
      *heCandidate = he;
      // printf("he iiii %d\n ",*heCandidate->data);
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
      // he = s0 > s2 ? he->opposite : he->next->next->opposite;
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
      // he = s1 > s2 ? he->next->opposite : he->next->next->opposite;
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
                 "(orientation tests %g %g %g)", x, y,
                 v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(),
                 s0, s1, s2);
    }
    if(he == nullptr) break;
  }
  // should only come here wether the triangulated domain is not convex
  if(he== nullptr) *found = false;
}

static int delaunayEdgeCriterionPlaneIsotropic(PolyMesh::HalfEdge *he, void *)
{
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

struct greater_than_key
{
  GFace* gf_;
  greater_than_key(GFace* gf){gf_ = gf;};
  inline bool operator() (PolyMesh::Face* f0, PolyMesh::Face* f1)
  {
    double uv[2];
    SPoint3 cc;
    double R0;
    double R1;
    faceCircumCenter(f0->he, gf_, cc, uv, &R0);
    faceCircumCenter(f1->he, gf_, cc, uv, &R1);
    return (R0 > R1);
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

 bool freeSurfaceCheck(PolyMesh* pm, PolyMesh::Vertex* v){
  PolyMesh::HalfEdge *he = v->he;
  do {
    he = he->opposite;
    if(he == NULL) return true;
    he = he->next;
    if(he->data == 0) return true;
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

 void print4debug(PolyMesh* pm, const int debugTag)
  {
    char name[256];
    sprintf(name, "polyMesh%d.pos", debugTag);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \" %s \"{\n", name);
    for(auto it : pm->faces) {
      PolyMesh::HalfEdge *he0 = it->he;
      PolyMesh::HalfEdge *he1 = it->he->next;
      PolyMesh::HalfEdge *he2 = it->he->next->next;
      if (it->he)
        fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%d,%d,%d};\n",
                he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
                he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
                it->data, it->data, it->data);
    }
    // for(auto it : pm->hedges) {
    //   PolyMesh::HalfEdge *he = it;
    //   if(he->opposite && he->f) {
    //     fprintf(f, "SL(%g,%g,0,%g,%g,0){%d,%d};\n", he->v->position.x(),
    //             he->v->position.y(), he->opposite->v->position.x(),
    //             he->opposite->v->position.y(), he->data, he->data);
    //   }
    // }

    fprintf(f, "};\n");
    fclose(f);
    printf("wrote mesh polyMesh%d.pos\n", debugTag);
  }

// Generate a mesh on entity of dimension dim and tag tag based on pre-defined locations of nodes, with possibly a size field on the nodes.
// The mesh will be refined if necessary, in order to respect the mesh size field.
// coord is a vector of size n*3 containing the coordinates of the nodes, nodeTags is a vector of size n containing the tags of the nodes, 
// and sizeAtNodes is a vector of size n containing the maximum size of elements allowed around this node.
// minRadius is the minimum allowed circumradius of elements in the mesh. An element that has a circumradius which is smaller than this value will 
// not be refined. constrainedEdges, if defined, is a list of edges that need to be in the mesh. It should be of size m*2, with an edge defined 
// by its two end nodes.
// Returns newly added nodes and corresponding size field
void constrainedDelaunayRefinement_(const int dim, const int tag,
                                    const std::vector<size_t> &elementTags,
                                    const std::vector<size_t> &constrainedEdges,
                                    const std::vector<size_t> &nodeTags,
                                    const std::vector<double> &sizeAtNodes, 
                                    const double minRadius, 
                                    std::vector<size_t> &newNodeTags, 
                                    std::vector<double>& newCoords, 
                                    std::vector<double>& newsizeAtNodes, 
                                    std::vector<std::vector<size_t>>& newConstrainedEdges, 
                                    std::vector<size_t>& newElementsInRefinement){
  // generateMesh_(dim, tag, 0, coord, nodeTags);
  // std::vector<double> pCoord;
  // gmsh::model::getParametrization(dim, tag, coord, pCoord);
  
  // GModel *m = GModel::current(); 
  // if (GModel::current()->getDim() >= dim){
  //   std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
  //   std::for_each(m->firstFace(), m->lastFace(), deMeshGFace());
  // }

  // DIM 1 : CHANGE!! NO DELETION OF THE MESH, ONLY REFINEMENT

  // if (dim==1){ 
  //   Msg::Info("generating mesh for edge %d\n",tag);
  //   deMeshGEdge killer;
  //   GEdge *ge = GModel::current()->getEdgeByTag(tag);
  //   if (!ge)return;
  //   killer(ge);
  //   std::vector<int> index(pCoord.size(), 0);
  //   for (size_t i = 0 ; i != index.size() ; i++) {
  //     index[i] = i;
  //   }
  //   sort(index.begin(), index.end(), [&](const int& a, const int& b) { return (pCoord[a] < pCoord[b]);});

  //   MVertex *vLast = ge->getEndVertex()->mesh_vertices[0];
  //   size_t maxTag = GModel::current()->getMaxVertexNumber();
  //   size_t i = 0;
  //   double current_sf = sizeAtNodes[0];
  //   MVertex *v_current = ge->getBeginVertex()->mesh_vertices[0];
  //   GPoint gp_next = ge->point(pCoord[index[0]]);
  //   size_t tag_new = nodeTags[index[1]];
  //   bool isFromInitialSet = true;
  //   MEdgeVertex *v_new;
  //   while(i <= index.size()){ // Get the length of the element; if larger than size field at node 0 or node 1, add a node in the middle
  //     double sf0 = current_sf;
  //     double dist = sqrt(pow(v_current->x()-gp_next.x(),2.) + pow(v_current->y()-gp_next.y(),2.) + pow(v_current->z()-gp_next.z(),2.));
  //     if (dist > sf0) { // this means the size field is larger than accepted value, we need to insert a node
  //       double xp0; v_current->getParameter(0, xp0);
  //       double xp1 = gp_next.u();
  //       gp_next = ge->point(0.5*(xp0+xp1));
  //       tag_new = maxTag+1;
  //       isFromInitialSet = false;
  //     }
  //     else {
  //       if(i == index.size() && isFromInitialSet) break;
  //       v_new = new MEdgeVertex(gp_next.x(), gp_next.y(), gp_next.z(), ge, gp_next.u(), tag_new);
  //       ge->mesh_vertices.push_back(v_new);  
  //       ge->lines.push_back(new MLine(v_current, v_new));
  //       v_current = v_new;
  //       if (isFromInitialSet) {
  //         current_sf = sizeAtNodes[i];
  //         i += 1;
  //       }
  //       else {
  //         maxTag +=1;
  //         newCoords.push_back(gp_next.x()); newCoords.push_back(gp_next.y()); newCoords.push_back(gp_next.z()); 
  //         newNodeTags.push_back(tag_new);
  //         newsizeAtNodes.push_back(current_sf);
  //       }
  //       gp_next = (i==index.size()) ? GPoint(vLast->point().x(), vLast->point().y(), vLast->point().z(), ge, ge->parFromPoint(vLast->point())) : ge->point(pCoord[index[i]]);
  //       tag_new = (i==index.size()) ? 0 : nodeTags[index[i]];
  //       isFromInitialSet = true;
  //       if (i > index.size()) break;
  //     }
  //   }
  //   MVertex *vFinal = ge->mesh_vertices[ge->mesh_vertices.size()-1];
  //   ge->lines.push_back(new MLine(vFinal, vLast));
  // }
  
  if (dim == 2){

    // std::vector<std::vector<size_t>> et;
    // std::vector<std::vector<size_t>> nt;
    // gmsh::model::mesh::getElements(elementTypes, et, nt, discreteDim, discreteTag);
    
    // elements of the full domain
    // std::vector<int> etypes;
    // std::vector<std::vector<size_t>> etFull;
    // std::vector<std::vector<size_t>> ntFull;
    // gmsh::model::mesh::getElements(etypes, etFull, ntFull, dim, tag);
    bool globalSize = sizeAtNodes.size() == 1;

    GModel* gm = GModel::current();

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
    for (size_t i=0; i<pm->faces.size(); i++){
      pm->faces[i]->data = -1;
    }

    // Recognise which are the faces to refine -> data at these faces is the gmsh face tag, else -1
    for (size_t n=0; n<elementTags.size(); n++){
      int etype, dd, tt;
      std::vector<size_t> nt;
      gmsh::model::mesh::getElement(elementTags[n], etype, nt, dd, tt); // note : not ideal...
      PolyMesh::Vertex* v0 = findVertex(pm, nt[0]);
      if (v0 == nullptr) Msg::Error("Invalid element tag %d\n", nt[0]);
      PolyMesh::Vertex* v1 = findVertex(pm, nt[1]);
      if (v1 == nullptr) Msg::Error("Invalid element tag %d\n", nt[1]);
      PolyMesh::HalfEdge* he0 = pm->getEdgeWithBnd(v0, v1);
      he0->f->data = 1;
    }
    // create a map from vertex to edge tag
    std::map <size_t, int> v2b;
    for (auto dt : bndDimTags){
      GEdge *ge = GModel::current()->getEdgeByTag(dt.second);
      v2b[ge->getBeginVertex()->mesh_vertices[0]->getNum()] = dt.second;
      for(std::size_t i = 0; i < ge->mesh_vertices.size(); i++) {
        v2b[ge->mesh_vertices[i]->getNum()] = dt.second;
      }
    }

    std::map<size_t, size_t> g2v;
    for (size_t i=0; i<pm->vertices.size(); i++){
      g2v[pm->vertices[i]->data] = i;
    }

    // Map from gmsh node num to size at this node --> to change?
    std::map<PolyMesh::Vertex*, double> v2sizeAtNodes;
    if (!globalSize){
      // std::vector<size_t> allNodeTags; std::vector<double> allNodeCoords; std::vector<double> allPNodeCoords;
      // gmsh::model::mesh::getNodes(allNodeTags, allNodeCoords, allPNodeCoords, dim, tag, true, false);
      for (size_t i=0; i<nodeTags.size(); i++){
        PolyMesh::Vertex* v0 = findVertex(pm, nodeTags[i]);
        v2sizeAtNodes[v0] = sizeAtNodes[i];
      }
    }

    // Get and color the constrained half edges : the ones inside the domain get data 0
    for (size_t ed=0; ed < constrainedEdges.size(); ed+=2){
        PolyMesh::Vertex* v0 = findVertex(pm, constrainedEdges[ed]);
        PolyMesh::Vertex* v1 = findVertex(pm, constrainedEdges[ed+1]);
        PolyMesh::HalfEdge* he = pm->getEdgeWithBnd(v0, v1);
        he->data = 0; //-> bug is here
    }
    // also constrain the boundary edges : they get the tag of the bounding edge they belong to
    for (auto he : pm->hedges){
      if (!he->opposite){
        std::map<size_t, int>::iterator it = v2b.find(he->v->data);
        if (it != v2b.end())
          he->data = it->second;
        else{
          printf("we may have a problem...\n");
          exit(0);
        }
      }
    }

    // The initial mesh has been created; now we need to insert nodes such that the size field is respected.
    
    // Step 2: coarsen the mesh -> remove nodes that are too small
    //                  ^
    //                  |
    // TODO !!! STEP 2 -|

    // Step 3: get the elements that do not respect the size or quality constraint
    std::vector<PolyMesh::Face *> _list;
    double _limit = 0.6; // Value to check!
    for(auto f : pm->faces) {
      if (f->data != -1){
        double q = faceQuality(f->he, gf);
        double uv[2];
        SPoint3 cc;
        double R;
        faceCircumCenter(f->he, gf, cc, uv, &R);
        double s;
        if (!globalSize)
          s = faceSize(f->he, gf, v2sizeAtNodes);
        else 
          s = sizeAtNodes[0];
        if((q < _limit || R > s) && R > minRadius) _list.push_back(f);
      }
    }

    size_t newIdx = gm->getMaxVertexNumber()+1;
    size_t addFrom = pm->vertices.size();
    
    // Step 4: loop over faces to insert nodes where necessary
    while (!_list.empty()){
      for(auto face_it = _list.begin() ; face_it != _list.end(); face_it++) {
        if (!(*face_it)->he) _list.erase(face_it--);
      }
      if (_list.empty()) continue;
      std::sort(_list.begin(), _list.end(), greater_than_key(gf));
      PolyMesh::Face *f = *_list.begin();
      _list.erase(_list.begin());
      if (f->he == nullptr) continue;
      double q = faceQuality(f->he, gf);
      double uv[2];
      SPoint3 cc;
      double R;
      faceCircumCenter(f->he, gf, cc, uv, &R);
      double s;
      if (!globalSize)
        s = faceSize(f->he, gf, v2sizeAtNodes);
      else 
        s = sizeAtNodes[0];
      if((q < _limit || R > s) && (R > minRadius && f->data != -1)){
        GPoint gp = gf->closestPoint(cc, uv);
        if(gp.succeeded()) { // we found it inside the geometrical domain
          PolyMesh::HalfEdge* heCandidate = nullptr;
          bool found; 
          Walk(f, gp.u(), gp.v(), &heCandidate, &found);
          // printf(" walk : %d\n", heCandidate->data);
          std::vector<PolyMesh::HalfEdge *> _touched;
          if (heCandidate && found){ // this means it is NOT a constrained edge
            pm->split_triangle(-1, gp.u(), gp.v(), 0, heCandidate->f, delaunayEdgeCriterionPlaneIsotropic, gf, &_touched);
            // printf("split triangle \n");
          }
          else if (heCandidate && !found && heCandidate->data>-1) {
            SVector3 p0 = heCandidate->v->position;
            SVector3 p1 = heCandidate->next->v->position;
            const SVector3 pos = (p0+p1)*0.5;
            if ( heCandidate->opposite){
              pm->split_edge(heCandidate, pos, -1);
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
              // printf("split edge %d -> %d\n", heCandidate->v->data, heCandidate->next->opposite->next->next->v->data);
            }
          // print4debug(pm, locali++);
            else { // the circumcenter is outside of the geometrical domain -> we need to add a node on the boundary
              std::vector<PolyMesh::HalfEdge *> new_bnd_hes;
              int bndTag = heCandidate->data;
              // print4debug(pm, newIdx+1000);
              pm->split_boundary_edge(heCandidate, pos, -1, &new_bnd_hes);
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
              // v2b[pm->vertices.back()] = 
              // printf("split boundary edge: %f, %f\n", pos.x(), pos.y());
            }
            SVector3 dist = pos-p0;
            std::vector<PolyMesh::Vertex *> closeVertices;
            getVerticesWithinRadius(pm, pm->vertices.back(), dist.norm(), &closeVertices);
            if (closeVertices.size() > 0){
              _touched.clear();
              for (auto vv : closeVertices){
                std::vector<PolyMesh::HalfEdge *> _nhes;
                if (pm->degree(vv) > 0 && !freeSurfaceCheck(pm, vv)) {
                  // int vIdx = vv->data;
                  pm->deleteVertex(vv, &_nhes);
                  // printf("deleted vertex %d, %d \n", vIdx, vv->he==nullptr);
                }
                delaunayCheck(pm, _nhes, &_touched);  
              }
            }
          }
          if (!globalSize)
            v2sizeAtNodes[pm->vertices.back()] = s;
          std::vector<PolyMesh::Face *> _newFaces;
          for(auto _h : _touched){
              if(_h->f && _h->f->he && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
                _newFaces.push_back(_h->f);
          }
          for(auto pf : _newFaces) {
              q = faceQuality(pf->he, gf);
              double uv[2];
              SPoint3 cc;
              double R;
              faceCircumCenter(pf->he, gf, cc, uv, &R);
              double s;
              if (!globalSize){
                s = faceSize(pf->he, gf, v2sizeAtNodes);
              }
              else 
                s = sizeAtNodes[0];
              if((q < _limit || R > s) && (R > minRadius && pf->data != -1)) _list.push_back(pf);
          }
          // printf("finished node insertion %d\n", pm->vertices.back()->data);
          newIdx++;
          // print4debug(pm, newIdx);
        }
      }
    }
    // print4debug(pm, 999);
    
    // Step 5: dump the updated mesh back into gmsh GFace;

    // delete faces
    for(auto t : gf->triangles) delete t;
    gf->triangles.clear();
    
    // delete bounding edges
    for (auto dt : bndDimTags){
      GEdge *ge = GModel::current()->getEdgeByTag(dt.second);
      for (auto l : ge->lines) delete l;
      ge->lines.clear();
      ge->mesh_vertices.clear();
    }

    // delete all internal mesh vertices
    for (auto mv : gf->mesh_vertices){
      delete mv;
    }
    gf->mesh_vertices.clear();

    std::unordered_map<int, MVertex *> news;

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
          if(v[i]->data != -1){
            auto it = news.find(v[i]->data);
            if(it == news.end()){
              if (v[i]->data == begin_v->getNum())
                v_gmsh[i] = begin_v;
              else if (v[i]->data == end_v->getNum())
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
              // v_gmsh[i] = GModel::current()->getMeshVertexByTag(v[i]->data);
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
    for(auto f : pm->faces) {
      // if (!f->he) continue;
      if (f->he) {
        PolyMesh::Vertex *v[3] = {f->he->v, f->he->next->v, f->he->next->next->v};
        MVertex *v_gmsh[3];
        // MVertex *v_gmsh_d[3];
        for(int i = 0; i < 3; i++) {
          if(v[i]->data != -1) {
            auto it = news.find(v[i]->data);
            if(it == news.end()){
              double uv[2] = {0, 0};
              GPoint gp = gf->closestPoint( SPoint3(v[i]->position.x(), v[i]->position.y(), v[i]->position.z()), uv);
              v_gmsh[i] = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v(), v[i]->data);
              // v_gmsh[i] = GModel::current()->getMeshVertexByTag(v[i]->data);
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
      if (!globalSize) newsizeAtNodes.push_back(v2sizeAtNodes[pm->vertices[i]]);
    }

    std::map<PolyMesh::HalfEdge*, bool> he_touched;
    std::vector<size_t> openLoop;
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

    CTX::instance()->mesh.changed = ENT_ALL;
    delete pm;
    gm->rebuildMeshVertexCache();
    gm->rebuildMeshElementCache();
  }
    
  // }
  // else if (dim == 3){
  //   // TODO
  //   int a = 0;
  // }
}

void alphaShape_entity(const int dim, const int tag, const double alpha, const std::vector<size_t>& nodeTags, const std::vector<double>& sizeAtNodes, std::vector<std::vector<size_t>>& elementTags, std::vector<std::vector<size_t>>& edges){
  // Currently only for 2D
  bool globalAlpha = sizeAtNodes.size() == 1;

  GModel* gm = GModel::current();
  GFace* gf = gm->getFaceByTag(tag);

  PolyMesh* pm;
  GFace2PolyMesh(tag, &pm);
  std::map<PolyMesh::Vertex*, double> v2sizeAtNodes;
  if (!globalAlpha){
    for (size_t i=0; i<nodeTags.size(); i++){
      PolyMesh::Vertex* v0 = findVertex(pm, nodeTags[i]);
      v2sizeAtNodes[v0] = sizeAtNodes[i];
    }
  }
  // Face data is the element tag -> note : dangerous but it works... (cfr GFace2PolyMesh function)
  std::vector<size_t> etFull;
  std::vector<size_t> ntFull;
  gmsh::model::mesh::getElementsByType(2, etFull, ntFull, tag);
  for (size_t i=0; i<pm->faces.size(); i++)
    pm->faces[i]->data = etFull[i];
  
  std::map<PolyMesh::Face*, bool> _touched;
  for (auto it : _touched)it.second = false;
  double hTriangle;
  double uv[2];
  SPoint3 cc;
  double R;
  for (size_t i = 0; i < pm->faces.size(); i++){
    PolyMesh::Face *f = pm->faces[i];
    if (!globalAlpha){
      PolyMesh::HalfEdge *h0 = f->he;
      PolyMesh::HalfEdge *h1 = f->he->next;
      PolyMesh::HalfEdge *h2 = f->he->next->next;
      hTriangle = (v2sizeAtNodes[h0->v] + v2sizeAtNodes[h1->v] + v2sizeAtNodes[h2->v])/3;
      // printf("size of triangle (%d, %d, %d) is %f\n", h0->v->data, h1->v->data, h2->v->data, hTriangle);
    }
    else
      hTriangle = sizeAtNodes[0];
    faceCircumCenter(f->he, gf, cc, uv, &R);
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
              PolyMesh::HalfEdge *_h0 = f_neigh->he;
              PolyMesh::HalfEdge *_h1 = f_neigh->he->next;
              PolyMesh::HalfEdge *_h2 = f_neigh->he->next->next;
              hTriangle = (v2sizeAtNodes[_h0->v] + v2sizeAtNodes[_h1->v] + v2sizeAtNodes[_h2->v])/3;
              // printf("size of triangle (%d, %d, %d) is %f\n", _h0->v->data, _h1->v->data, _h2->v->data, hTriangle);
            }
            else
              hTriangle = sizeAtNodes[0];
            faceCircumCenter(f_neigh->he, gf, cc, uv, &R);
            if (R/hTriangle < alpha){
              // printf("triangle is in alpha shape : R = %f, alpha = %f, h = %f\n", R, alpha, hTriangle);
              _s.push(f_neigh);
              _touched[f_neigh] = true;
              _domain.push_back(f_neigh->data);	    
            }	    
            else {
              _boundary.push_back(_he->v->data);
              _boundary.push_back(_he->next->v->data);	      
            }
          }
          _he = _he->next;
        }while (_he != _f->he);
      }
      edges.push_back(_boundary);
      elementTags.push_back(_domain); 
    }
  }
}



#endif