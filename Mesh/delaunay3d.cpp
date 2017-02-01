// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#if defined(_OPENMP)
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
#include "meshGRegionLocalMeshMod.h"

#if defined(_HAVE_NUMA)
#include <numa.h>
#endif

//int Tet::in_sphere_counter = 0;

struct HilbertSortB
{
  // The code for generating table transgc from:
  // http://graphics.stanford.edu/~seander/bithacks.html.
  int transgc[8][3][8];
  int tsb1mod3[8];
  int maxDepth;
  int Limit;
  SBoundingBox3d bbox ;
  void ComputeGrayCode(int n);
  int Split(Vert** vertices,
	    int arraysize,int GrayCode0,int GrayCode1,
	    double BoundingBoxXmin, double BoundingBoxXmax,
	    double BoundingBoxYmin, double BoundingBoxYmax,
	    double BoundingBoxZmin, double BoundingBoxZmax);
  void Sort(Vert** vertices, int arraysize, int e, int d,
            double BoundingBoxXmin, double BoundingBoxXmax,
            double BoundingBoxYmin, double BoundingBoxYmax,
            double BoundingBoxZmin, double BoundingBoxZmax, int depth);
  HilbertSortB (int m = 0, int l=2) : maxDepth(m), Limit(l)
  {
    ComputeGrayCode(3);
  }
  void MultiscaleSortHilbert(Vert** vertices, int arraysize,
			     int threshold, double ratio, int *depth,
                             std::vector<int> &indices)
  {
    int middle = 0;
    if (arraysize >= threshold) {
      (*depth)++;
      middle = (int)(arraysize * ratio);
      MultiscaleSortHilbert(vertices, middle, threshold, ratio, depth, indices);
    }
    indices.push_back(middle);
    // printf("chunk starts at %d and size %d\n",middle, arraysize - middle);
    Sort(&(vertices[middle]),arraysize - middle,0,0,
         bbox.min().x(),bbox.max().x(),
         bbox.min().y(),bbox.max().y(),
         bbox.min().z(),bbox.max().z(),0);
  }
  void Apply(std::vector<Vert*> &v, std::vector<int> &indices)
  {
    indices.clear();
    if(v.empty()) return;
    for (size_t i = 0; i < v.size(); i++){
      Vert *pv = v[i];
      bbox += SPoint3(pv->x(), pv->y(), pv->z());
    }
    bbox *= 1.01;
    Vert **pv = &v[0];
    int depth;
    indices.clear();
    MultiscaleSortHilbert(pv, (int)v.size(), 64, .125, &depth, indices);
    indices.push_back(v.size());
    // printf("depth = %d\n",depth);
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

int HilbertSortB::Split(Vert** vertices,
		       int arraysize,int GrayCode0,int GrayCode1,
		       double BoundingBoxXmin, double BoundingBoxXmax,
                       double BoundingBoxYmin, double BoundingBoxYmax,
		       double BoundingBoxZmin, double BoundingBoxZmax)
{
  Vert* swapvert;
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
  }
  else {
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

void HilbertSortB::Sort(Vert** vertices, int arraysize, int e, int d,
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
      //      printf("ARGH max depth attained\n");
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

void SortHilbert (std::vector<Vert*>& v, std::vector<int> &indices)
{
  HilbertSortB h(1000);
  h.Apply(v, indices);
}

void computeAdjacencies (Tet *t, int iFace, connContainer &faceToTet)
{
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

/***********************************************************************
  Local mesh modifications

  edgeSwap , faceSwap ,

************************************************************************/

/***********************************************************************
  Compute all tets surrounding an edge
************************************************************************/

static int edges[6][2] =    {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
static int efaces[6][2] =   {{0,2},{0,1},{1,2},{0,3},{2,3},{1,3}};
static int faces[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};
//static int vnofaces[4] = {3,1,2,0};
//static int vFac[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};

static void computeNeighboringTetsOfACavity(const std::vector<Tet*> &cavity,
					    std::vector<Tet*> &outside)
{
  outside.clear();
  for (unsigned int i = 0; i < cavity.size(); i++){
    for (int j = 0; j < 4; j++){
      Tet * neigh = cavity[i]->T[j];
      if(neigh && std::find(cavity.begin(),cavity.end(),neigh) == cavity.end() &&
	 std::find(outside.begin(),outside.end(),neigh) == outside.end()){
	outside.push_back(neigh);
      }
    }
  }
}

static bool buildEdgeCavity(Tet *t, int iLocalEdge,
			    Vert **v1, Vert **v2,
			    std::vector<Tet*> &cavity,
			    std::vector<Tet*> &outside,
			    std::vector<Vert*> &ring)
{
  cavity.clear();
  ring.clear();

  *v1 = t->V[edges[iLocalEdge][0]];
  *v2 = t->V[edges[iLocalEdge][1]];

  // the 5 - i th edge contains the other 2 points of the tet
  Vert *lastinring = t->V[edges[5 - iLocalEdge][0]];
  ring.push_back(lastinring);
  cavity.push_back(t);

  while (1){
    Vert *ov1 = t->V[edges[5 - iLocalEdge][0]];
    Vert *ov2 = t->V[edges[5 - iLocalEdge][1]];
    int K = ov1 == lastinring ? 1 : 0;
    lastinring = ov1 == lastinring ? ov2 : ov1;
    // look in the 2 faces sharing this edge the one that has vertex
    // ov2 i.e. edges[5-iLocalEdge][1]
    int iFace;
    int iFace1 = efaces[iLocalEdge][0];
    int iFace2 = efaces[iLocalEdge][1];
    if (faces[iFace1][0] == edges[5-iLocalEdge][K] ||
        faces[iFace1][1] == edges[5-iLocalEdge][K] ||
        faces[iFace1][2] == edges[5-iLocalEdge][K] ) iFace = iFace1;
    else if (faces[iFace2][0] == edges[5-iLocalEdge][K] ||
             faces[iFace2][1] == edges[5-iLocalEdge][K] ||
             faces[iFace2][2] == edges[5-iLocalEdge][K] ) iFace = iFace2;
    else { Msg::Error("Error of connexion"); return false; }
    t=t->T[iFace];
    if (!t) return false;
    if (!t->V[0]){ Msg::Error("Weird!!"); return false; }
    if (t == cavity[0]) break;
    ring.push_back(lastinring);
    cavity.push_back(t);
    iLocalEdge = -1;
    for (int i = 0; i < 6; i++){
      Vert *a = t->V[edges[i][0]];
      Vert *b = t->V[edges[i][1]];
      if ((a == *v1 && b == *v2) || (a == *v2 && b == *v1)){
        iLocalEdge = i;
        break;
      }
    }
    if (iLocalEdge == -1){
      Msg::Error("loc = %d", iLocalEdge);
      return false;
    }
  }
  computeNeighboringTetsOfACavity (cavity,outside);
  return true;
}

#define SQR(X) (X)*(X)

bool edgeSwap(Tet *tet, int iLocalEdge,  tetContainer &T, int myThread)
{
  std::vector<Tet*> cavity;
  std::vector<Tet*> outside;
  std::vector<Vert*> ring;
  Vert *v1, *v2;

  bool closed = buildEdgeCavity(tet, iLocalEdge, &v1, &v2, cavity, outside, ring);

  if (!closed) return false;

  SwapPattern sp;
  switch (ring.size()){
  case 3 : BuildSwapPattern3(&sp); break;
  case 4 : BuildSwapPattern4(&sp); break;
  case 5 : BuildSwapPattern5(&sp); break;
  case 6 : BuildSwapPattern6(&sp); break;
  case 7 : BuildSwapPattern7(&sp); break;
  default : return false;
  }

  double tetQualityRef = 1.e22;
  for (unsigned int i = 0; i < cavity.size(); i++){
    Vert *vx0 = cavity[i]->V[0];
    Vert *vx1 = cavity[i]->V[1];
    Vert *vx2 = cavity[i]->V[2];
    Vert *vx3 = cavity[i]->V[3];
    double volume = robustPredicates::orient3d((double*)vx0, (double*)vx1, (double*)vx2, (double*)vx3);
    const double a  =
      SQR (vx0->x() - vx1->x()) + SQR (vx0->y() - vx1->y()) + SQR (vx0->z() - vx1->z()) +
      SQR (vx0->x() - vx2->x()) + SQR (vx0->y() - vx2->y()) + SQR (vx0->z() - vx2->z()) +
      SQR (vx0->x() - vx3->x()) + SQR (vx0->y() - vx3->y()) + SQR (vx0->z() - vx3->z()) +
      SQR (vx1->x() - vx2->x()) + SQR (vx1->y() - vx2->y()) + SQR (vx1->z() - vx2->z()) +
      SQR (vx1->x() - vx3->x()) + SQR (vx1->y() - vx3->y()) + SQR (vx1->z() - vx3->z()) +
      SQR (vx2->x() - vx3->x()) + SQR (vx2->y() - vx3->y()) + SQR (vx2->z() - vx3->z()) ;
    tetQualityRef = std::min(tetQualityRef, volume / a);
  }

  // compute qualities of all tets that appear in the patterns
  double tetQuality1[100], tetQuality2[100];
  for (int i = 0; i < sp.nbr_triangles; i++){
    // FIXME VERIFY ORIENTATION OF TRIANGULAR PATTERNS
    int p1 = sp.triangles[i][0];
    int p2 = sp.triangles[i][1];
    int p3 = sp.triangles[i][2];
    const double volume1 = robustPredicates::orient3d((double*)ring[p1], (double*)ring[p2], (double*)ring[p3], (double*) v1);
    const double volume2 = robustPredicates::orient3d((double*)ring[p1], (double*)ring[p2], (double*)ring[p3], (double*) v2);
    const double a12 = SQR (ring[p1]->x() - ring[p2]->x())+SQR (ring[p1]->y() - ring[p2]->y())+SQR (ring[p1]->z() - ring[p2]->z());
    const double a13 = SQR (ring[p1]->x() - ring[p3]->x())+SQR (ring[p1]->y() - ring[p3]->y())+SQR (ring[p1]->z() - ring[p3]->z());
    const double a23 = SQR (ring[p2]->x() - ring[p3]->x())+SQR (ring[p2]->y() - ring[p3]->y())+SQR (ring[p2]->z() - ring[p3]->z());
    const double a123 = a12 + a13 + a23;
    const double v11 = SQR (ring[p1]->x() - v1->x())+SQR (ring[p1]->y() - v1->y())+SQR (ring[p1]->z() - v1->z());
    const double v12 = SQR (ring[p2]->x() - v1->x())+SQR (ring[p2]->y() - v1->y())+SQR (ring[p2]->z() - v1->z());
    const double v13 = SQR (ring[p3]->x() - v1->x())+SQR (ring[p3]->y() - v1->y())+SQR (ring[p3]->z() - v1->z());
    const double v21 = SQR (ring[p1]->x() - v2->x())+SQR (ring[p1]->y() - v2->y())+SQR (ring[p1]->z() - v2->z());
    const double v22 = SQR (ring[p2]->x() - v2->x())+SQR (ring[p2]->y() - v2->y())+SQR (ring[p2]->z() - v2->z());
    const double v23 = SQR (ring[p3]->x() - v2->x())+SQR (ring[p3]->y() - v2->y())+SQR (ring[p3]->z() - v2->z());
    tetQuality1[i] = volume1 / (a123 + v11 + v12 + v13);
    tetQuality2[i] = volume2 / (a123 + v21 + v22 + v23);
  }

  // look for the best triangulation, i.e. the one that maximize the
  // minimum element quality
  double minQuality[100];
  // for all triangulations
  for (int i = 0; i < sp.nbr_trianguls; i++){
    // for all triangles in a triangulation
    minQuality[i] = 1.e22;
    for (int j = 0; j < sp.nbr_triangles_2; j++){
      int iT = sp.trianguls[i][j];
      minQuality[i] = std::min(minQuality[i], std::min (tetQuality1[iT],tetQuality2[iT]));
    }
  }

  int iBest = 0;
  double best = -1.0;
  for (int i = 0; i < sp.nbr_trianguls; i++){
    if(minQuality[i] > best){
      best = minQuality[i];
      iBest = i;
    }
  }

  if (best <= tetQualityRef) return false;

  unsigned int counter = 0;
  for (int j = 0; j < sp.nbr_triangles_2; j++){
    int iT = sp.trianguls[iBest][j];
    int p1 = sp.triangles[iT][0];
    int p2 = sp.triangles[iT][1];
    int p3 = sp.triangles[iT][2];
    Vert *pv1 = ring[p1];
    Vert *pv2 = ring[p2];
    Vert *pv3 = ring[p3];

    Tet *nt1,*nt2;
    if (counter < cavity.size()) nt1 = cavity[counter++];
    else nt1 = T.newTet(myThread);
    if (counter < cavity.size()) nt2 = cavity[counter++];
    else nt2 = T.newTet(myThread);

    nt1->setVertices(pv1, pv2, pv3, v1);
    nt2->setVertices(pv3, pv2, pv3, v1);

    outside.push_back(nt1);
    outside.push_back(nt2);
  }

  for(unsigned int i = counter; i < cavity.size(); i++) cavity[i]->V[0] = NULL;

  connContainer ctnr;
  for(unsigned int i = 0; i < outside.size(); i++)
    for (int j=0;j<4;j++)
      computeAdjacencies (outside[i],j,ctnr);

  return true;
}

/*
static void edgeSwapPass (tetContainer &T)
{
}
*/

/*
  Fixing a non star shaped cavity (non delaunay triangulations)
  See P.L. George's paper
  Improvements on Delaunay-based three-dimensional automatic mesh generator
  Finite Elements in Analysis and Design 25 (1997) 297-317
*/

static void starShapeness (Vert *v, connContainer &bndK,
			   std::vector<unsigned int> &_negatives)
{
  _negatives.clear();
  for (unsigned int i=0; i< bndK.size(); i++) {
    // no symbolic perturbation
    const double val =   robustPredicates::orient3d((double*)bndK[i].f.V[0],
						    (double*)bndK[i].f.V[1],
						    (double*)bndK[i].f.V[2],
						    (double*)v);
    if (val <= 0.0 ) {
      _negatives.push_back(i);
    }
  }
}

static Tet* tetContainsV (Vert *v, cavityContainer &cavity)
{
  for (unsigned int i=0; i< cavity.size(); i++) {
    unsigned int count = 0;
    for (unsigned int j=0;j<4;j++){
      Face f = cavity[i]->getFace(j);
      const double val =   robustPredicates::orient3d((double*)f.V[0],
						      (double*)f.V[1],
						      (double*)f.V[2],
						      (double*)v);
      if (val >= 0 ) {
	count++;
      }
    }
    if (count == 4)return cavity[i];
  }
  //  printf("AIE\n");
  return NULL;
}

static void buildDelaunayBall (cavityContainer &cavity, connContainer &faceToTet)
{
  faceToTet.clear();
  for (unsigned int i=0; i< cavity.size(); i++) {
    Tet *t = cavity[i];
    for (unsigned int iFace=0; iFace< 4; iFace++) {
      Tet *neigh = t->T[iFace];
      conn c (t->getFace(iFace), iFace, neigh);
      connContainer::iterator it = std::find(faceToTet.begin(),faceToTet.end(),c);
      if (it == faceToTet.end()){
	faceToTet.push_back(c);
      }
      else {
	faceToTet.erase(it);
      }
    }
  }
}

/*
static bool updateCavity(Tet *containsV,
			 cavityContainer &cavity,
			 connContainer &bndK,
			 int myThread, int K)
{
  bndK.clear();
  cavityContainer cc;
  cc.push_back(containsV);
  std::stack<Tet*> _stack;
  _stack.push(containsV);

  while (!_stack.empty()){
    Tet *t = _stack.top();
    _stack.pop();
    for (unsigned int i=0;i<4;i++){
      Tet *neigh = t->T[i];
      if (neigh == NULL){
	bndK.push_back(conn(t->getFace(i), i, neigh));
      }
      else if (std::find(cc.begin(),cc.end(),neigh) == cc.end()){
	if(std::find(cavity.begin(),cavity.end(),neigh) != cavity.end()){
	  cc.push_back(neigh);
	  _stack.push(neigh);
	}
	else {
	  bndK.push_back(conn(t->getFace(i), i, neigh));
	}
      }
    }
  }
  if (cc.size() == cavity.size())return false;
  cavity = cc;
  return true;
}
*/

static bool removeIsolatedTets(Tet *containsV,
			       cavityContainer &cavity,
			       connContainer &bndK,
			       int myThread, int K)
{
  cavityContainer cc;
  cc.push_back(containsV);
  std::stack<Tet*> _stack;
  _stack.push(containsV);

  while (!_stack.empty()){
    Tet *t = _stack.top();
    _stack.pop();
    for (int i=0;i<4;i++){
      Tet *neigh = t->T[i];
      if (neigh &&
	  (std::find(cc.begin(),cc.end(),neigh) == cc.end()) &&
	  (std::find(cavity.begin(),cavity.end(),neigh) != cavity.end())){
	cc.push_back(neigh);
	_stack.push(neigh);
      }
    }
  }
  if (cc.size() == cavity.size())return false;
  //  //  Msg::Info("   cavity updated (%3ld elements) %3ld isolated tet removed",cavity.size(),cavity.size()-cc.size());
  cavity = cc;
  return true;
}

static Tet *tetInsideCavityWithFAce (Face &f, cavityContainer &cavity)
{
  //  printf("size of cavity %ld\n",cavity.size());
  for (unsigned int i=0; i< cavity.size(); i++) {
    Tet *t = cavity[i];
    for (unsigned int iFace=0; iFace< 4; iFace++) {
      if (t->getFace(iFace) == f) {
	return t;
      }
    }
  }
  return NULL;
}

static bool fixDelaunayCavity (Vert *v,
			       cavityContainer &cavity,
			       connContainer &bndK,
			       int myThread, int K,
			       std::vector<unsigned int> & _negatives)
{
  starShapeness (v, bndK, _negatives);

  if (_negatives.empty())return false;
  //  return true;
  // unset all tets of the cavity
  for (unsigned int i=0; i< cavity.size(); i++)cavity[i]->unset(myThread,K);
  for (unsigned int i=0; i<bndK.size(); i++)if(bndK[i].t)bndK[i].t->unset(myThread,K);

  Msg::Debug("Fixing cavity (%3ld,%3ld) : %ld negatives",
	     cavity.size(),bndK.size(), _negatives.size());

  Tet *containsV = tetContainsV (v,cavity);

  if (! containsV) return true;

  while (!_negatives.empty()) {
    for (unsigned int i=0;i<_negatives.size();i++){
      conn &c = bndK[_negatives[i] ];
      Tet *toRemove = tetInsideCavityWithFAce (c.f, cavity);
      if (toRemove){
	std::vector<Tet*>::iterator it = std::find(cavity.begin(), cavity.end(), toRemove);
	if (it != cavity.end())
	  cavity.erase(it);
	else
	  Msg::Fatal("Datastructure Broken in %s line %5d",__FILE__,__LINE__);
      }
    }
    removeIsolatedTets(containsV, cavity,bndK,myThread,K);
    buildDelaunayBall (cavity,bndK);
    starShapeness (v, bndK, _negatives);
  }
  return false;
}

static void delaunayCavity2 (Tet *t,
			    Tet *prev,
			    Vert *v,
			    cavityContainer &cavity,
			    connContainer &bnd,
			    int thread, int iPnt)
{
  t->set(thread, iPnt); // Mark the triangle
  cavity.push_back(t);
  for (int iNeigh=0; iNeigh<4 ; iNeigh++){
    Tet *neigh = t->T[iNeigh];
    if (neigh == NULL){
      bnd.push_back(conn(t->getFace(iNeigh),iNeigh,neigh));
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

Tet* walk (Tet *t, Vert *v, int maxx, double &totSearch, int thread)
{
  while (1){
    totSearch++;
    if (t == NULL) {
      //      printf("in an embedded edge\n");
      return NULL; // we should NEVER return here
    }
    //    if (t->inSphere(v,thread)) {return t;}
    double _min = 0.0;
    int NEIGH = -1;
    int count = 0;
    for (int iNeigh=0; iNeigh<4; iNeigh++){
      Face f = t->getFace (iNeigh);
      double val =   robustPredicates::orient3d((double*)f.V[0],
						(double*)f.V[1],
						(double*)f.V[2],
						(double*)v);
      if (val >=-1.e-09) count++;
      if (val < _min){
	NEIGH = iNeigh;
	_min = val;
      }
    }
    if (count == 4  && t->inSphere(v,thread))return t;
    if (NEIGH >= 0){
      t = t->T[NEIGH];
    }
    else {
      Msg::Fatal("Jump-and-Walk Failed (No neighbor)");
    }
  }
  Msg::Fatal("Jump-and-Walk Failed (No neighbor)");
}

void __print (const char *name, connContainer &conn, Vert *v)
{
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"\"{\n");

  if (v)fprintf(f,"SP(%g,%g,%g){%d};\n",v->x(),v->y(),v->z(),v->getNum());

  for (unsigned int i=0;i<conn.size();i++){
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	    conn[i].f.V[0]->x(),conn[i].f.V[0]->y(),conn[i].f.V[0]->z(),
	    conn[i].f.V[1]->x(),conn[i].f.V[1]->y(),conn[i].f.V[1]->z(),
	    conn[i].f.V[2]->x(),conn[i].f.V[2]->y(),conn[i].f.V[2]->z(),1.,1.,1.);
  }
  fprintf(f,"};\n");
  fclose(f);
}

void __print (const char *name, int thread, tetContainer &T, Vert *v){
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

void print (std::vector<Vert*> &V, std::vector<Tet*> &T)
{
  std::map<Vert*,int> nums;
  for (unsigned int i=0;i<V.size();i++){
    nums[V[i]] = i;
  }
  for (unsigned int i=0;i<T.size();i++){
    printf("%p\n",T[i]);
    printf("%d %d %d %d\n",nums[T[i]->V[0]],nums[T[i]->V[1]],nums[T[i]->V[2]],nums[T[i]->V[3]]);
    printf("%p %p %p %p\n",T[i]->T[0],T[i]->T[1],T[i]->T[2],T[i]->T[3]);
  }
}

void print (const char *name, std::vector<Vert*> &T)
{
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

bool canWeProcessCavity (cavityContainer &cavity, unsigned int myThread, unsigned int iPt)
{
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

bool checkLocalDelaunayness(Tet* t)
{
  if (t->V[0]){
    for (int i=0;i<4;i++){
      Tet *n = t->T[i];
      if (n && n->inSphere(t->getOppositeVertex(i),0))return false;
    }
  }
  return true;
}

int checkLocalDelaunayness(tetContainer &c, int thread, char *msg)
{
  int nLoc = 0;
  for (unsigned int i=0; i<c.size(thread); i++) {
    if (!checkLocalDelaunayness(c(thread,i)))nLoc++;
  }
  if (nLoc != 0)Msg::Info ("%s --> %d tets are not locally delaunay",msg,nLoc);
  return nLoc ;
}

static Tet* randomTet (int thread,  tetContainer &allocator)
{
  unsigned int N = allocator.size(thread);
  //  printf("coucou random TET %d %d\n",thread,N);
  while(1) {
    Tet *t = allocator(thread,rand()%N);
    if (t->V[0])return t;
  }
}


int isCavityCompatibleWithEmbeddedEdges(cavityContainer &cavity, 
					connContainer &bndK,   
					edgeContainer &allEmbeddedEdges){
  
  const unsigned int bSize = bndK.size();
  std::vector<Edge> ed;
  for (unsigned int i=0; i<bSize; i++) {
    for (unsigned int j=0; j<3; j++) {
      if (bndK[i].f.V[j] > bndK[i].f.V[(j+1)%3]){
	ed.push_back(Edge(bndK[i].f.V[j], bndK[i].f.V[(j+1)%3]));
      }
    }
  }
  
  for (unsigned int i=0; i<cavity.size(); i++){
    for (int j=0;j<6;j++){
      Edge e = cavity[i]->getEdge(j);
      if (std::find(ed.begin(), ed.end(), e) == ed.end() && allEmbeddedEdges.find(e)){
	return 0;
      }
    }
  }
  return 1;
} 


//#define _VERBOSE 1
void delaunayTrgl (const unsigned int numThreads,
		   const unsigned int NPTS_AT_ONCE,
		   unsigned int Npts,
		   std::vector<Vert*> assignTo[],
		   tetContainer &allocator,
		   edgeContainer *embeddedEdges)
{
#if defined(_VERBOSE)
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

#if defined(_OPENMP)
#pragma omp parallel num_threads(numThreads)
#endif
  {

#if defined(_OPENMP)
    int  myThread = omp_get_thread_num();
#else
    int  myThread = 0;
#endif

    double totSearch=0;
    double totCavity=0;
    std::vector<unsigned int> _negatives;
    std::vector<cavityContainer> cavity(NPTS_AT_ONCE);
    std::vector<connContainer> bnd(NPTS_AT_ONCE);
    std::vector<bool> ok(NPTS_AT_ONCE);
    connContainer faceToTet;
    std::vector<Tet*> Choice(NPTS_AT_ONCE);
    for (unsigned int K=0;K<NPTS_AT_ONCE;K++)Choice[K] = randomTet (myThread, allocator);


    invalidCavities [myThread] = 0;
    unsigned int locSize=0;
    std::vector<unsigned int> locSizeK(NPTS_AT_ONCE);
    std::vector<Vert*> allocatedVerts(NPTS_AT_ONCE);
    for (unsigned int K=0;K<NPTS_AT_ONCE;K++){
      locSizeK[K] = assignTo[K+myThread*NPTS_AT_ONCE].size();
      locSize += locSizeK[K];
#if defined(_HAVE_NUMA)
      allocatedVerts [K] = (Vert*)numa_alloc_local (locSizeK[K]*sizeof(Vert));
#else
      //      allocatedVerts [K] = (Vert*)calloc (locSizeK[K],sizeof(Vert));
      allocatedVerts [K] = new Vert [locSizeK[K]];
#endif
      for (unsigned int iP=0 ; iP < locSizeK[K] ; iP++){
	allocatedVerts[K][iP] = *(assignTo[K+myThread*NPTS_AT_ONCE][iP]);
	if (numThreads!=1) allocatedVerts[K][iP]._thread = myThread;
      }
    }

    std::vector<Vert*> vToAdd(NPTS_AT_ONCE);

#if defined(_OPENMP)
#pragma omp barrier
#endif

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////// M A I N   L O O P ///////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    for (unsigned int iPGlob=0 ; iPGlob < maxLocSizeK; iPGlob++){
      //      printf("%d vs %d\n",iPGlob,maxLocSizeK);
#if defined(_OPENMP)
#pragma omp barrier
#endif
      std::vector<Tet*> t(NPTS_AT_ONCE);
      //	  double c1 = Cpu();
      // FIND SEEDS
      //      t1 = Cpu();
      for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
	vToAdd[K] = iPGlob <  locSizeK[K] ? &allocatedVerts[K][iPGlob] : NULL;
	if(vToAdd[K]){
	  // In 3D, insertion of a point may lead to deletion of tets !!
	  if (!Choice[K]->V[0])Choice[K] = randomTet (myThread, allocator);
	  //	  int nbCoucou=0;
	  while(1){
	    t[K] = walk ( Choice[K] , vToAdd[K], Npts, totSearch, myThread);
	    if (t[K])break;
	    //	    printf("coucou %d\n",nbCoucou++);
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
	  // verify the cavity
	  if (fixDelaunayCavity (vToAdd[K],  cavityK, bndK, myThread, K, _negatives)){
	    vToAdd[K] = NULL;
	    invalidCavities [myThread]++;
	  }
	  if (embeddedEdges && !isCavityCompatibleWithEmbeddedEdges(cavityK, bndK, *embeddedEdges)){
	    vToAdd[K] = NULL;
	    invalidCavities [myThread]++;
	  }
	}
      }

      //      t3 += Cpu() - t1;

#if defined(_OPENMP)
#pragma omp barrier
#endif
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
#if defined(_VERBOSE)
#if defined(_OPENMP)
    #pragma omp critical
#endif
    {
      totCavityGlob+= totCavity;
      totSearchGlob+= totSearch;
    }
#endif
#if defined(_OPENMP)
    #pragma omp barrier
#endif
    // clear last cavity
    for (unsigned int K=0; K< NPTS_AT_ONCE; K++) {
      for (unsigned int i=0; i<cavity[K].size(); i++)cavity[K][i]->unset(myThread,K);
      for (unsigned int i=0; i<bnd[K].size(); i++)if(bnd[K][i].t)bnd[K][i].t->unset(myThread,K);
    }
  }

  if (invalidCavities[0])Msg::Warning("%d invalid cavities",invalidCavities[0]);

  //checkLocalDelaunayness(T,"final");

  
  
  //  printf(" %12.5E %12.5E  %12.5E tot  %12.5E \n",t2,t3,t4,t2+t3+t4);

#if defined(_VERBOSE)
  printf("average searches per point  %12.5E\n",totSearchGlob/Npts);
  printf("average size for del cavity %12.5E\n",totCavityGlob/Npts);
  printf("cache misses: ");
  for (unsigned int i=0;i<numThreads;i++){
    printf("%4ud ",(int)cacheMisses[i]);
  }
  printf("\n");

#endif

}

static void initialCube (std::vector<Vert*> &v,
			 Vert *box[8],
			 tetContainer & allocator)
{
  SBoundingBox3d bbox ;
  //  bbox += SPoint3(0,0,0);
  //  bbox += SPoint3(1,1,1);
  for (size_t i=0;i<v.size();i++){
    Vert *pv = v[i];
    bbox += SPoint3(pv->x(),pv->y(),pv->z());
  }
  bbox *= 1.3;
  box[0] = new Vert (bbox.min().x(),bbox.min().y(),bbox.min().z(),bbox.diag());
  box[1] = new Vert (bbox.max().x(),bbox.min().y(),bbox.min().z(),bbox.diag());
  box[2] = new Vert (bbox.max().x(),bbox.max().y(),bbox.min().z(),bbox.diag());
  box[3] = new Vert (bbox.min().x(),bbox.max().y(),bbox.min().z(),bbox.diag());
  box[4] = new Vert (bbox.min().x(),bbox.min().y(),bbox.max().z(),bbox.diag());
  box[5] = new Vert (bbox.max().x(),bbox.min().y(),bbox.max().z(),bbox.diag());
  box[6] = new Vert (bbox.max().x(),bbox.max().y(),bbox.max().z(),bbox.diag());
  box[7] = new Vert (bbox.min().x(),bbox.max().y(),bbox.max().z(),bbox.diag());

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
			    std::vector<Vert*> &S,
			    Vert *box[8],
			    tetContainer & allocator)
{
  int N = S.size();

  std::vector<int> indices;
  SortHilbert(S, indices);
  if (!allocator.size(0)){
    initialCube (S,box,allocator);
  }

  int nbBlocks  = nptsatonce * numThreads;
  //  int blockSize = (nbBlocks * (N / nbBlocks))/nbBlocks;


  std::vector<Vert*> assignTo0[1];
  std::vector<std::vector<Vert*> > assignTo(nbBlocks);

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
  //  __print ("finalTetrahedrization.pos",0, allocator);
}


void delaunayTriangulation (const int numThreads,
			    const int nptsatonce,
			    std::vector<MVertex*> &S,
			    std::vector<MTetrahedron*> &T)
{
  std::vector<MVertex*> _temp;
  std::vector<Vert*> _vertices;
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
    //    Vert *v = new Vert (mv->x(),mv->y(),mv->z(),1.e22,i+1);
    Vert *v = new Vert (mv->x(),mv->y(),mv->z(),1.e22,i+1);
    _vertices.push_back(v);
    _temp [v->getNum()] = mv;
  }

  robustPredicates::exactinit(1,maxx,maxy,maxz);

  // FIXME numThreads

  Vert *box[8];
  delaunayTriangulation (numThreads, nptsatonce, _vertices, box, allocator);
  //__print ("finalTetrahedrization.pos",0, allocator);

  MVertex *VV[8];
  for (int i=0;i<8;i++){
    Vert *v = box[i];
    v->setNum(N+i+1);
    VV[i]= new MVertex (v->x(),v->y(),v->z(),NULL,N+(i+1));
    _temp [v->getNum()] = VV[i];
    S.push_back(VV[i]);
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
