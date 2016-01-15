// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifdef _OPENMP
#include <omp.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include "SBoundingBox3d.h"
#include "OS.h"
#include "delaunay3d_private.h"
#include "delaunay3d.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MTetrahedron.h"

const int MEASURE_BARR = 0;

#ifdef _HAVE_NUMA
#include <numa.h>
#endif

//int Tet::in_sphere_counter = 0;


struct HilbertSortB
{
// The code for generating table transgc
// from: http://graphics.stanford.edu/~seander/bithacks.html.
  int transgc[8][3][8];
  int tsb1mod3[8];
  int maxDepth;
  int Limit;
  SBoundingBox3d bbox ;
  void ComputeGrayCode(int n);
  int Split(Vertex** vertices,
	    int arraysize,int GrayCode0,int GrayCode1,
	    double BoundingBoxXmin, double BoundingBoxXmax,
	    double BoundingBoxYmin, double BoundingBoxYmax,
	    double BoundingBoxZmin, double BoundingBoxZmax);
  void Sort(Vertex** vertices, int arraysize, int e, int d,
	   double BoundingBoxXmin, double BoundingBoxXmax,
            double BoundingBoxYmin, double BoundingBoxYmax,
	   double BoundingBoxZmin, double BoundingBoxZmax, int depth);
  HilbertSortB (int m = 0, int l=2) : maxDepth(m),Limit(l)
  {
    ComputeGrayCode(3);
  }
  void MultiscaleSortHilbert(Vertex** vertices, int arraysize,
			     int threshold, double ratio, int *depth, std::vector<int> &indices)
  {
    int middle;

    middle = 0;
    if (arraysize >= threshold) {
      (*depth)++;
      middle = (int)(arraysize * ratio);
      MultiscaleSortHilbert(vertices, middle, threshold, ratio, depth, indices);
    }
    indices.push_back(middle);
    //    printf("chunk starts at %d and size %d\n",middle, arraysize - middle);
    Sort (&(vertices[middle]),arraysize - middle,0,0,
	  bbox.min().x(),bbox.max().x(),
	  bbox.min().y(),bbox.max().y(),
	  bbox.min().z(),bbox.max().z(),0);
  }
  void Apply (std::vector<Vertex*> &v, std::vector<int> &indices)
  {
    for (size_t i=0;i<v.size();i++){
      Vertex *pv = v[i];
      bbox += SPoint3(pv->x(),pv->y(),pv->z());
    }
    bbox *= 1.01;
    Vertex**pv = &v[0];
    int depth;
    indices.clear();
    MultiscaleSortHilbert(pv, (int)v.size(), 64, .125,&depth,indices);
    indices.push_back(v.size());
    //    printf("depth = %d\n",depth);
  }
};

void HilbertSortB::ComputeGrayCode(int n)
{
  int gc[8], N, mask, travel_bit;
  int e, d, f, k, g;
  int v, c;
  int i;

  N = (n == 2) ? 4 : 8;
  mask = (n == 2) ? 3 : 7;

  // Generate the Gray code sequence.
  for (i = 0; i < N; i++) {
    gc[i] = i ^ (i >> 1);
  }

  for (e = 0; e < N; e++) {
    for (d = 0; d < n; d++) {
      // Calculate the end point (f).
      f = e ^ (1 << d);  // Toggle the d-th bit of 'e'.
      // travel_bit = 2**p, the bit we want to travel.
      travel_bit = e ^ f;
      for (i = 0; i < N; i++) {
        // // Rotate gc[i] left by (p + 1) % n bits.
        k = gc[i] * (travel_bit * 2);
        g = ((k | (k / N)) & mask);
        // Calculate the permuted Gray code by xor with the start point (e).
        transgc[e][d][i] = (g ^ e);
      }
      //      assert(transgc[e][d][0] == e);
      //      assert(transgc[e][d][N - 1] == f);
    } // d
  } // e

  // Count the consecutive '1' bits (trailing) on the right.
  tsb1mod3[0] = 0;
  for (i = 1; i < N; i++) {
    v = ~i; // Count the 0s.
    v = (v ^ (v - 1)) >> 1; // Set v's trailing 0s to 1s and zero rest
    for (c = 0; v; c++) {
      v >>= 1;
    }
    tsb1mod3[i] = c % n;
  }
}


int HilbertSortB::Split(Vertex** vertices,
		       int arraysize,int GrayCode0,int GrayCode1,
		       double BoundingBoxXmin, double BoundingBoxXmax,
                       double BoundingBoxYmin, double BoundingBoxYmax,
		       double BoundingBoxZmin, double BoundingBoxZmax)
{
  Vertex* swapvert;
  int axis, d;
  double split;
  int i, j;

  // Find the current splitting axis. 'axis' is a value 0, or 1, or 2, which
  //   correspoding to x-, or y- or z-axis.
  axis = (GrayCode0 ^ GrayCode1) >> 1;

  // Calulate the split position along the axis.
  if (axis == 0) {
    split = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
  } else if (axis == 1) {
    split = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
  } else { // == 2
    split = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
  }

  // Find the direction (+1 or -1) of the axis. If 'd' is +1, the direction
  //   of the axis is to the positive of the axis, otherwise, it is -1.
  d = ((GrayCode0 & (1<<axis)) == 0) ? 1 : -1;


  // Partition the vertices into left- and right-arrays such that left points
  //   have Hilbert indices lower than the right points.
  i = 0;
  j = arraysize - 1;

  // Partition the vertices into left- and right-arrays.
  if (d > 0) {
    do {
      for (; i < arraysize; i++) {
        if (vertices[i]->point()[axis] >= split) break;
      }
      for (; j >= 0; j--) {
        if (vertices[j]->point()[axis] < split) break;
      }
      // Is the partition finished?
      if (i == (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertices[i];
      vertices[i] = vertices[j];
      vertices[j] = swapvert;
      // Continue patitioning the array;
    } while (true);
  } else {
    do {
      for (; i < arraysize; i++) {
        if (vertices[i]->point()[axis] <= split) break;
      }
      for (; j >= 0; j--) {
        if (vertices[j]->point()[axis] > split) break;
      }
      // Is the partition finished?
      if (i == (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertices[i];
      vertices[i] = vertices[j];
      vertices[j] = swapvert;
      // Continue patitioning the array;
    } while (true);
  }

  return i;
}

// The sorting code is inspired by Tetgen 1.5

void HilbertSortB::Sort(Vertex** vertices, int arraysize, int e, int d,
		       double BoundingBoxXmin, double BoundingBoxXmax,
                       double BoundingBoxYmin, double BoundingBoxYmax,
		       double BoundingBoxZmin, double BoundingBoxZmax, int depth)
{
  double x1, x2, y1, y2, z1, z2;
  int p[9], w, e_w, d_w, k, ei, di;
  int n = 3, mask = 7;

  p[0] = 0;
  p[8] = arraysize;

  p[4] = Split(vertices, p[8], transgc[e][d][3], transgc[e][d][4],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax);
  p[2] = Split(vertices, p[4], transgc[e][d][1], transgc[e][d][2],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax);
  p[1] = Split(vertices, p[2], transgc[e][d][0], transgc[e][d][1],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax);
  p[3] = Split(&(vertices[p[2]]), p[4] - p[2],
	       transgc[e][d][2], transgc[e][d][3],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax) + p[2];
  p[6] = Split(&(vertices[p[4]]), p[8] - p[4],
	       transgc[e][d][5], transgc[e][d][6],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax) + p[4];
  p[5] = Split(&(vertices[p[4]]), p[6] - p[4],
	       transgc[e][d][4], transgc[e][d][5],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax) + p[4];
  p[7] = Split(&(vertices[p[6]]), p[8] - p[6],
	       transgc[e][d][6], transgc[e][d][7],
	       BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin,
               BoundingBoxYmax, BoundingBoxZmin, BoundingBoxZmax) + p[6];

  if (maxDepth > 0) {
    if ((depth + 1) == maxDepth) {
      printf("ARGH\n");
      return;
    }
  }

  // Recursively sort the points in sub-boxes.

  for (w = 0; w < 8; w++) {
    if ((p[w+1] - p[w]) > Limit) {
      if (w == 0) {
        e_w = 0;
      } else {
        k = 2 * ((w - 1) / 2);
        e_w = k ^ (k >> 1);
      }
      k = e_w;
      e_w = ((k << (d+1)) & mask) | ((k >> (n-d-1)) & mask);
      ei = e ^ e_w;
      if (w == 0) {
        d_w = 0;
      } else {
        d_w = ((w % 2) == 0) ? tsb1mod3[w - 1] : tsb1mod3[w];
      }
      di = (d + d_w + 1) % n;
      if (transgc[e][d][w] & 1) {
        x1 = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
        x2 = BoundingBoxXmax;
      } else {
        x1 = BoundingBoxXmin;
        x2 = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
      }
      if (transgc[e][d][w] & 2) { // y-axis
        y1 = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
        y2 = BoundingBoxYmax;
      } else {
        y1 = BoundingBoxYmin;
        y2 = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
      }
      if (transgc[e][d][w] & 4) { // z-axis
        z1 = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
        z2 = BoundingBoxZmax;
      } else {
        z1 = BoundingBoxZmin;
        z2 = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
      }
      Sort(&(vertices[p[w]]), p[w+1] - p[w], ei, di,
                    x1, x2, y1, y2, z1, z2, depth+1);
    }
  }
}

void SortHilbert (std::vector<Vertex*>& v, std::vector<int> &indices)
{
  HilbertSortB h(1000);
  h.Apply(v, indices);
}

void computeAdjacencies (Tet *t, int iFace, connContainer &faceToTet){
  conn c (t->getFace(iFace), iFace, t);
  connContainer::iterator it = std::find(faceToTet.begin(),faceToTet.end(),c);
  if (it == faceToTet.end()){
    faceToTet.push_back(c);
  }
  else{
    t->T[iFace] = it->t;
    it->t->T[it->i] =t;
    faceToTet.erase(it);
  }
}

static void delaunayCavity2 (Tet *t,
			    Tet *prev,
			    Vertex *v,
			    cavityContainer &cavity,
			    connContainer &bnd,
			    int thread, int iPnt){
  t->set(thread, iPnt); // Mark the triangle
  cavity.push_back(t);
  for (int iNeigh=0; iNeigh<4 ; iNeigh++){
    Tet *neigh = t->T[iNeigh];
    if (neigh == NULL){
      bnd.push_back(conn(t->getFace(iNeigh),iNeigh,NULL));
    }
    else if (neigh == prev){
    }
    else if (!neigh->inSphere(v,thread)){
      bnd.push_back(conn(t->getFace(iNeigh),iNeigh,neigh));
      neigh->set(thread, iPnt);
    }
    else if (!(neigh->isSet(thread, iPnt))) {
      delaunayCavity2 (neigh, t, v, cavity,bnd,thread, iPnt);
    }
  }
}

static void delaunayCavity (Tet *t,
			    Vertex *v,
			    cavityContainer &cavity,
			    connContainer &bnd,
			    int thread, int iPnt){

  t->set(thread, iPnt); // Mark the triangle
  cavity.push_back(t);
  for (int iNeigh=0; iNeigh<4 ; iNeigh++){
    Tet *neigh = t->T[iNeigh];
    if (neigh == NULL){
      bnd.push_back(conn(t->getFace(iNeigh),iNeigh,NULL));
    }
    else if (neigh->inSphere(v,thread)){
      if (!(neigh->isSet(thread, iPnt))) {
	delaunayCavity (neigh, v, cavity,bnd,thread, iPnt); 
      }
    }
    else {
      bnd.push_back(conn( t->getFace(iNeigh),iNeigh,neigh));
    }
  }
}

Tet* walk (Tet *t, Vertex *v, int maxx, double &totSearch, int thread){
  while (1){
    totSearch++;
    if (t == NULL) {
      return NULL; // we should NEVER return here
    }
    if (t->inSphere(v,thread)) {return t;}
    double _min = 0.0;
    int NEIGH = -1;
    for (int iNeigh=0; iNeigh<4; iNeigh++){
      Face f = t->getFace (iNeigh);
      double val =   robustPredicates::orient3d((double*)f.V[0],
						(double*)f.V[1],
						(double*)f.V[2],
						(double*)v);
      if (val < _min){
	NEIGH = iNeigh;
	_min = val;
      }
    }
    if (NEIGH >= 0){
      t = t->T[NEIGH];
    }
    else {
      Msg::Fatal("Jump-and-Walk Failed (No neighbor)");
    }
  }
  Msg::Fatal("Jump-and-Walk Failed (No neighbor)");
}


void __print (const char *name, connContainer &conn){
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"\"{\n");

  for (unsigned int i=0;i<conn.size();i++){
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	    conn[i].f.V[0]->x(),conn[i].f.V[0]->y(),conn[i].f.V[0]->z(),
	    conn[i].f.V[1]->x(),conn[i].f.V[1]->y(),conn[i].f.V[1]->z(),
	    conn[i].f.V[2]->x(),conn[i].f.V[2]->y(),conn[i].f.V[2]->z(),1.,1.,1.);
  }
  fprintf(f,"};\n");
  fclose(f);
}

void __print (const char *name, int thread, tetContainer &T, Vertex *v){
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"\"{\n");
  if (v)fprintf(f,"SP(%g,%g,%g){%d};\n",v->x(),v->y(),v->z(),v->getNum());

  for (unsigned int i=0;i<T.size(thread);i++){
    Tet *tt = T(thread,i);
    if (tt->V[0]){
      //      double val = robustPredicates::orient3d((double*)tt->V[0],(double*)tt->V[1],(double*)tt->V[2],(double*)tt->V[3]);
      if (!v){
	fprintf(f,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
		tt->V[0]->x(),tt->V[0]->y(),tt->V[0]->z(),
		tt->V[1]->x(),tt->V[1]->y(),tt->V[1]->z(),
		tt->V[2]->x(),tt->V[2]->y(),tt->V[2]->z(),
		tt->V[3]->x(),tt->V[3]->y(),tt->V[3]->z(),
		tt->V[0]->lc(),tt->V[1]->lc(),tt->V[2]->lc(),tt->V[3]->lc());
      }
      else{
	fprintf(f,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
		tt->V[0]->x(),tt->V[0]->y(),tt->V[0]->z(),
		tt->V[1]->x(),tt->V[1]->y(),tt->V[1]->z(),
		tt->V[2]->x(),tt->V[2]->y(),tt->V[2]->z(),
		tt->V[3]->x(),tt->V[3]->y(),tt->V[3]->z(),
		tt->V[0]->getNum(),tt->V[1]->getNum(),tt->V[2]->getNum(),tt->V[3]->getNum());
      }
    }
  }
  fprintf(f,"};\n");
  fclose(f);
}

void print (std::vector<Vertex*> &V, std::vector<Tet*> &T){
  std::map<Vertex*,int> nums;
  for (unsigned int i=0;i<V.size();i++){
    nums[V[i]] = i;
  }
  for (unsigned int i=0;i<T.size();i++){
    printf("%p\n",T[i]);
    printf("%d %d %d %d\n",nums[T[i]->V[0]],nums[T[i]->V[1]],nums[T[i]->V[2]],nums[T[i]->V[3]]);
    printf("%p %p %p %p\n",T[i]->T[0],T[i]->T[1],T[i]->T[2],T[i]->T[3]);
  }
}


void print (const char *name, std::vector<Vertex*> &T){
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"\"{\n");
  for (unsigned int i=0;i<T.size()-1;i++){
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",
	    T[i]->x(),T[i]->y(),T[i]->z(),
	    T[i+1]->x(),T[i+1]->y(),T[i+1]->z(),i,i+1);
  }
  fprintf(f,"};\n");
  fclose(f);
}

/*
xxx10000 ok if all bits on my right are 0
*/

bool canWeProcessCavity (cavityContainer &cavity, unsigned int myThread, unsigned int iPt) {
  unsigned int cSize = cavity.size();
  for (unsigned int j=0; j<cSize; j++) {
    Tet *f = cavity[j];
    for (unsigned int index = 0; index < myThread; index++) {
      if(f->_bitset [index]) return false;
    }
    if (iPt){
      if ( f->_bitset[myThread]  & ((1 << iPt)-1)) return false;
    }
  }
  return true;
}

bool checkLocalDelaunayness(Tet* t){
  if (t->V[0]){
    for (int i=0;i<4;i++){    
      Tet *n = t->T[i];
      if (n && n->inSphere(t->getOppositeVertex(i),0))return false;
    }
  }
  return true;
}

int checkLocalDelaunayness(tetContainer &c, int thread, char *msg){
  int nLoc = 0;
  for (unsigned int i=0; i<c.size(thread); i++) {
    if (!checkLocalDelaunayness(c(thread,i)))nLoc++;
  }
  if (nLoc != 0)Msg::Info ("%s --> %d tets are not locally delaunay",msg,nLoc);
  return nLoc ;
}

static Tet* randomTet (int thread,  tetContainer &allocator ){
  unsigned int N = allocator.size(thread);
  //  printf("coucou random TET %d %d\n",thread,N);
  while(1) {
    Tet *t = allocator(thread,rand()%N);
    if (t->V[0])return t;
  }
}


//#define _VERBOSE 1
void delaunayTrgl (const unsigned int numThreads, 
		   const unsigned int NPTS_AT_ONCE, 
		   unsigned int Npts, 
		   std::vector<Vertex*> assignTo[],
		   tetContainer &allocator){
#ifdef _VERBOSE
  double totSearchGlob=0;
  double totCavityGlob=0;
#endif

  //  double t1,t2=0,t3=0,t4=0;

  //  checkLocalDelaunayness(allocator, 0, "initial");

  std::vector<int> invalidCavities(numThreads);
  std::vector<int> cacheMisses(numThreads, 0);

  unsigned int maxLocSizeK = 0;
  for (unsigned int i = 0; i < numThreads * NPTS_AT_ONCE; i++){
    unsigned int s = assignTo[i].size();
    maxLocSizeK = std::max(maxLocSizeK, s);
  }

#pragma omp parallel num_threads(numThreads)
  {

#ifdef _OPENMP
    int  myThread = omp_get_thread_num();
#else
    int  myThread = 0;
#endif

    double totSearch=0;
    double totCavity=0;
    std::vector<cavityContainer> cavity(NPTS_AT_ONCE);
    std::vector<connContainer> bnd(NPTS_AT_ONCE);
    std::vector<bool> ok(NPTS_AT_ONCE);
    connContainer faceToTet;
    std::vector<Tet*> Choice(NPTS_AT_ONCE);
    for (unsigned int K=0;K<NPTS_AT_ONCE;K++)Choice[K] = randomTet (myThread, allocator);
    

    invalidCavities [myThread] = 0;
    unsigned int locSize=0;
    std::vector<unsigned int> locSizeK(NPTS_AT_ONCE);
    std::vector<Vertex*> allocatedVerts(NPTS_AT_ONCE);
    for (unsigned int K=0;K<NPTS_AT_ONCE;K++){
      locSizeK[K] = assignTo[K+myThread*NPTS_AT_ONCE].size();
      locSize += locSizeK[K];
#ifdef _HAVE_NUMA
      allocatedVerts [K] = (Vertex*)numa_alloc_local (locSizeK[K]*sizeof(Vertex));
#else
      //      allocatedVerts [K] = (Vertex*)calloc (locSizeK[K],sizeof(Vertex));
      allocatedVerts [K] = new Vertex [locSizeK[K]];
#endif
      for (unsigned int iP=0 ; iP < locSizeK[K] ; iP++){
	allocatedVerts[K][iP] = *(assignTo[K+myThread*NPTS_AT_ONCE][iP]);
	if (numThreads!=1) allocatedVerts[K][iP]._thread = myThread;
      }
    }

    std::vector<Vertex*> vToAdd(NPTS_AT_ONCE);

#pragma omp barrier
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////// M A I N   L O O P ///////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    for (unsigned int iPGlob=0 ; iPGlob < maxLocSizeK; iPGlob++){
#pragma omp barrier
      std::vector<Tet*> t(NPTS_AT_ONCE);
      //	  double c1 = Cpu();
      // FIND SEEDS
      //      t1 = Cpu();
      for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
	vToAdd[K] = iPGlob <  locSizeK[K] ? &allocatedVerts[K][iPGlob] : NULL;
	if(vToAdd[K]){
	  // In 3D, insertion of a point may lead to deletion of tets !!
	  if (!Choice[K]->V[0])Choice[K] = randomTet (myThread, allocator);
	  while(1){
	    t[K] = walk ( Choice[K] , vToAdd[K], Npts, totSearch, myThread);
	    if (t[K])break;
	    // the domain may not be convex. we then start from a random tet and
	    // walk from there
	    Choice[K] = randomTet(rand() % numThreads, allocator);
	  }
	}
      }
      //      t2+= Cpu() - t1;
      //      double c1 = Cpu();
      // BUILD CAVITIES
      //      t1 = Cpu();
      for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
	if(vToAdd[K]){
	  cavityContainer &cavityK = cavity[K];
	  connContainer   &bndK = bnd[K];
	  for (unsigned int i=0; i<cavityK.size(); i++)cavityK[i]->unset(myThread,K);
	  for (unsigned int i=0; i<bndK.size(); i++)if(bndK[i].t)bndK[i].t->unset(myThread,K);
	  cavityK.clear(); bndK.clear();
	  delaunayCavity2(t[K], NULL, vToAdd[K], cavityK, bndK, myThread, K);
	  //delaunayCavity(t[K], vToAdd[K], cavityK, bndK, myThread, K);
	  // verify the cavity
	  for (unsigned int i=0; i< bndK.size(); i++) {
	    const double val =   robustPredicates::orient3d((double*)bndK[i].f.V[0],
							    (double*)bndK[i].f.V[1],
							    (double*)bndK[i].f.V[2],
							    (double*)vToAdd[K]);
	    if (val <= 0 ) {
	      vToAdd[K] = NULL;
	      invalidCavities [myThread]++;
	      break;
	    }
	  }
	}
      }

      //      t3 += Cpu() - t1;

#pragma omp barrier

      for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
	if (!vToAdd[K])ok[K]=false;
	else ok[K] = canWeProcessCavity (cavity[K], myThread, K);
      }
      //      t1 = Cpu();

      for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
	if (ok[K]){
	  cavityContainer &cavityK = cavity[K];
	  connContainer   &bndK = bnd[K];
	  faceToTet.clear();
	  const unsigned int cSize = cavityK.size();
	  const unsigned int bSize = bndK.size();
	  totCavity+= cSize;
	  Choice[K] = cavityK[0];
	  for (unsigned int i=0; i<bSize; i++) {
	    // reuse memory slots of invalid elements
	    Tet *t = (i < cSize)? cavityK[i] :  allocator.newTet(myThread);
	    if (i < cSize && t->V[0]->_thread != myThread)cacheMisses[myThread]++;
	    t->setVerticesNoTest (bndK[i].f.V[0], bndK[i].f.V[1], bndK[i].f.V[2], vToAdd[K]);
	    Tet *neigh = bndK[i].t;
	    t->T[0] = neigh;
	    t->T[1] = t->T[2] = t->T[3] = NULL;
	    if (neigh){
	      if      (neigh->getFace(0) == bndK[i].f)neigh->T[0] = t;
	      else if (neigh->getFace(1) == bndK[i].f)neigh->T[1] = t;
	      else if (neigh->getFace(2) == bndK[i].f)neigh->T[2] = t;
	      else if (neigh->getFace(3) == bndK[i].f)neigh->T[3] = t;
	      else {Msg::Fatal("Datatrsucture Broken in Triangulation");}
	    }
	    computeAdjacencies (t,1,faceToTet);
	    computeAdjacencies (t,2,faceToTet);
	    computeAdjacencies (t,3,faceToTet);
	  }
	  for (unsigned int i=bSize; i<cSize; i++) {
	    cavityK[i]->V[0] = NULL;
	  }
	}
      }
      //      t4 += Cpu() - t1;
    }
#ifdef _VERBOSE
    #pragma omp critical
    {
      totCavityGlob+= totCavity;
      totSearchGlob+= totSearch;
    }
#endif
    #pragma omp barrier
    // clear last cavity
    for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
      for (unsigned int i=0; i<cavity[K].size(); i++)cavity[K][i]->unset(myThread,K);
      for (unsigned int i=0; i<bnd[K].size(); i++)if(bnd[K][i].t)bnd[K][i].t->unset(myThread,K);
    }
  }

  if (invalidCavities[0])Msg::Warning("%d invalid cavities",invalidCavities[0]);

  //checkLocalDelaunayness(T,"final");


  //  printf(" %12.5E %12.5E  %12.5E tot  %12.5E \n",t2,t3,t4,t2+t3+t4);

#ifdef _VERBOSE
  printf("average searches per point  %12.5E\n",totSearchGlob/Npts);
  printf("average size for del cavity %12.5E\n",totCavityGlob/Npts);
  printf("cache misses: ");
  for (unsigned int i=0;i<numThreads;i++){
    printf("%4ud ",(int)cacheMisses[i]);
  }
  printf("\n");

#endif

}


static void initialCube (std::vector<Vertex*> &v,
			 Vertex *box[8],
			 tetContainer & allocator){
  SBoundingBox3d bbox ;
  //  bbox += SPoint3(0,0,0);
  //  bbox += SPoint3(1,1,1);
  for (size_t i=0;i<v.size();i++){
    Vertex *pv = v[i];
    bbox += SPoint3(pv->x(),pv->y(),pv->z());
  }
  bbox *= 1.3;
  box[0] = new Vertex (bbox.min().x(),bbox.min().y(),bbox.min().z(),bbox.diag());
  box[1] = new Vertex (bbox.max().x(),bbox.min().y(),bbox.min().z(),bbox.diag());
  box[2] = new Vertex (bbox.max().x(),bbox.max().y(),bbox.min().z(),bbox.diag());
  box[3] = new Vertex (bbox.min().x(),bbox.max().y(),bbox.min().z(),bbox.diag());
  box[4] = new Vertex (bbox.min().x(),bbox.min().y(),bbox.max().z(),bbox.diag());
  box[5] = new Vertex (bbox.max().x(),bbox.min().y(),bbox.max().z(),bbox.diag());
  box[6] = new Vertex (bbox.max().x(),bbox.max().y(),bbox.max().z(),bbox.diag());
  box[7] = new Vertex (bbox.min().x(),bbox.max().y(),bbox.max().z(),bbox.diag());

  /*  Tet *t0 = new Tet (box[2],box[7],box[3],box[1]);
  Tet *t1 = new Tet (box[0],box[7],box[1],box[3]);
  Tet *t2 = new Tet (box[6],box[1],box[7],box[2]);
  Tet *t3 = new Tet (box[0],box[1],box[7],box[4]);
  Tet *t4 = new Tet (box[1],box[4],box[5],box[7]);
  Tet *t5 = new Tet (box[1],box[7],box[5],box[6]);*/

  Tet *t0 = allocator.newTet(0); t0->setVertices(box[7],box[2],box[3],box[1]);
  Tet *t1 = allocator.newTet(0); t1->setVertices(box[7],box[0],box[1],box[3]);
  Tet *t2 = allocator.newTet(0); t2->setVertices(box[1],box[6],box[7],box[2]);
  Tet *t3 = allocator.newTet(0); t3->setVertices(box[1],box[0],box[7],box[4]);
  Tet *t4 = allocator.newTet(0); t4->setVertices(box[4],box[1],box[5],box[7]);
  Tet *t5 = allocator.newTet(0); t5->setVertices(box[7],box[1],box[5],box[6]);

  connContainer ctnr;
  for (int i=0;i<4;i++){
    computeAdjacencies (t0,i,ctnr);
    computeAdjacencies (t1,i,ctnr);
    computeAdjacencies (t2,i,ctnr);
    computeAdjacencies (t3,i,ctnr);
    computeAdjacencies (t4,i,ctnr);
    computeAdjacencies (t5,i,ctnr);
  }
  //  printf("%d faces left\n",ctnr.size());
}

void delaunayTriangulation (const int numThreads,
			    const int nptsatonce,
			    std::vector<Vertex*> &S,
			    Vertex *box[8],
			    tetContainer & allocator){
  int N = S.size();

  std::vector<int> indices;
  SortHilbert(S, indices);
  if (!allocator.size(0)){
    initialCube (S,box,allocator);
  }

  int nbBlocks  = nptsatonce * numThreads;
  //  int blockSize = (nbBlocks * (N / nbBlocks))/nbBlocks;


  std::vector<Vertex*> assignTo0[1];
  std::vector<std::vector<Vertex*> > assignTo(nbBlocks);

  for (unsigned int i=1;i<indices.size();i++){
    int start = indices[i-1];
    int end = indices[i];
    int sizePerBlock = (nbBlocks*((end-start) / nbBlocks))/nbBlocks;
    //    printf("sizePerBlock[%3d] = %8d\n",i,sizePerBlock);
    int currentBlock = 0;
    int localCounter = 0;
    // FIXME : something's wrong here !!!
    if (i < 1){
      for (int jPt=start;jPt<end;jPt++){
	assignTo0[0].push_back(S[jPt]);
	S[jPt]->_thread = numThreads*(jPt-start)/(end-start);
      }
    }
    else {
      for (int jPt=start;jPt<end;jPt++){
	if (localCounter++ >= sizePerBlock && currentBlock != nbBlocks-1){
	  localCounter = 0;
	  currentBlock++;
	}
	assignTo[currentBlock].push_back(S[jPt]);
      }
    }
  }

  S.clear();
  delaunayTrgl(1,1, assignTo0[0].size(),assignTo0,allocator);
  delaunayTrgl(numThreads,nptsatonce, N,&assignTo[0], allocator);
  __print ("finalTetrahedrization.pos",0, allocator);
}


void delaunayTriangulation (const int numThreads,
			    const int nptsatonce,
			    std::vector<MVertex*> &S,
			    std::vector<MTetrahedron*> &T){
  std::vector<MVertex*> _temp;
  std::vector<Vertex*> _vertices;
  unsigned int N = S.size();
  _temp.resize(N+1+8);
  double maxx=0, maxy=0,maxz=0;
  for (unsigned int i=0;i<N;i++){
    MVertex *mv = S[i];
    maxx = std::max(maxx,fabs(mv->x()));
    maxy = std::max(maxy,fabs(mv->y()));
    maxz = std::max(maxz,fabs(mv->z()));
  }
  double d = 1*sqrt ( maxx*maxx + maxy*maxy + maxz*maxz );

  tetContainer allocator (1, S.size() * 10);

  for (unsigned int i=0;i<N;i++){
    MVertex *mv = S[i];
    // FIXME : should be zero !!!!
    double dx = d*1.e-14 * (double)rand() / RAND_MAX;
    double dy = d*1.e-14 * (double)rand() / RAND_MAX;
    double dz = d*1.e-14 * (double)rand() / RAND_MAX;
    mv->x() += dx;
    mv->y() += dy;
    mv->z() += dz;
    //    Vertex *v = new Vertex (mv->x(),mv->y(),mv->z(),1.e22,i+1);
    Vertex *v = new Vertex (mv->x(),mv->y(),mv->z(),1.e22,i+1);
    _vertices.push_back(v);
    _temp [v->getNum()] = mv;
  }

  robustPredicates::exactinit(1,maxx,maxy,maxz);

  // FIXME numThreads

  Vertex *box[8];
  delaunayTriangulation (numThreads, nptsatonce, _vertices, box, allocator);

  for (int i=0;i<8;i++){
    Vertex *v = box[i];
    v->setNum(N+i+1);
    MVertex *mv = new MVertex (v->x(),v->y(),v->z(),NULL,N+i+1);
    //    printf("%d %g %g %g\n",v->getNum(),v->x(),v->y(),v->z());
    _temp [v->getNum()] = mv;
    S.push_back(mv);
  }

  for (int myThread=0; myThread < numThreads; myThread++) {
    for (unsigned int i=0;i<allocator.size(myThread);i++){
      Tet *t =  allocator(myThread,i);
      if (t->V[0]){
	if (t->V[0]->getNum() &&
	    t->V[1]->getNum() &&
	    t->V[2]->getNum() &&
	    t->V[3]->getNum() ) {
	  MVertex *v1 = _temp[t->V[0]->getNum()];
	  MVertex *v2 = _temp[t->V[1]->getNum()];
	  MVertex *v3 = _temp[t->V[2]->getNum()];
	  MVertex *v4 = _temp[t->V[3]->getNum()];
	  MTetrahedron *tr = new MTetrahedron(v1,v2,v3,v4);
	  T.push_back(tr);
	}
	else {
	  Msg::Fatal("Error in triangulation");
	}
      }
    }
  }

  for (unsigned int i=0;i<_vertices.size();i++)delete _vertices[i];
}
