// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "SBoundingBox3d.h"
#include "MVertex.h"

struct HilbertSort {
  // The code for generating table transgc
  // from: http://graphics.stanford.edu/~seander/bithacks.html.
  int transgc[8][3][8];
  int tsb1mod3[8];
  int maxDepth;
  int Limit;
  SBoundingBox3d bbox;
  void ComputeGrayCode(int n);
  int Split(MVertex **vertices, int arraysize, int GrayCode0, int GrayCode1,
            double BoundingBoxXmin, double BoundingBoxXmax,
            double BoundingBoxYmin, double BoundingBoxYmax,
            double BoundingBoxZmin, double BoundingBoxZmax);
  void Sort(MVertex **vertices, int arraysize, int e, int d,
            double BoundingBoxXmin, double BoundingBoxXmax,
            double BoundingBoxYmin, double BoundingBoxYmax,
            double BoundingBoxZmin, double BoundingBoxZmax, int depth);
  HilbertSort(int m = 0, int l = 2) : maxDepth(m), Limit(l)
  {
    ComputeGrayCode(3);
  }
  void MultiscaleSortHilbert(MVertex **vertices, int arraysize, int threshold,
                             double ratio, int *depth)
  {
    int middle;

    middle = 0;
    if(arraysize >= threshold) {
      (*depth)++;
      middle = (int)(arraysize * ratio);
      MultiscaleSortHilbert(vertices, middle, threshold, ratio, depth);
    }
    Sort(&(vertices[middle]), arraysize - middle, 0, 0, bbox.min().x(),
         bbox.max().x(), bbox.min().y(), bbox.max().y(), bbox.min().z(),
         bbox.max().z(), 0);
  }
  void Apply(std::vector<MVertex *> &v, int threshold = 10)
  {
    for(size_t i = 0; i < v.size(); i++) {
      MVertex *pv = v[i];
      bbox += SPoint3(pv->x(), pv->y(), pv->z());
    }
    bbox *= 1.01;
    MVertex **pv = &v[0];
    int depth = 0; 
    MultiscaleSortHilbert(pv, (int)v.size(), threshold, 0.125, &depth);
  }
};

void HilbertSort::ComputeGrayCode(int n)
{
  int gc[8], N, mask, travel_bit;
  int e, d, f, k, g;
  int v, c;
  int i;

  N = (n == 2) ? 4 : 8;
  mask = (n == 2) ? 3 : 7;

  // Generate the Gray code sequence.
  for(i = 0; i < N; i++) { gc[i] = i ^ (i >> 1); }

  for(e = 0; e < N; e++) {
    for(d = 0; d < n; d++) {
      // Calculate the end point (f).
      f = e ^ (1 << d); // Toggle the d-th bit of 'e'.
      // travel_bit = 2**p, the bit we want to travel.
      travel_bit = e ^ f;
      for(i = 0; i < N; i++) {
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
  for(i = 1; i < N; i++) {
    v = ~i; // Count the 0s.
    v = (v ^ (v - 1)) >> 1; // Set v's trailing 0s to 1s and zero rest
    for(c = 0; v; c++) { v >>= 1; }
    tsb1mod3[i] = c % n;
  }
}

int HilbertSort::Split(MVertex **vertices, int arraysize, int GrayCode0,
                       int GrayCode1, double BoundingBoxXmin,
                       double BoundingBoxXmax, double BoundingBoxYmin,
                       double BoundingBoxYmax, double BoundingBoxZmin,
                       double BoundingBoxZmax)
{
  MVertex *swapvert;
  int axis, d;
  double split;
  int i, j;

  // Find the current splitting axis. 'axis' is a value 0, or 1, or 2, which
  //   correspoding to x-, or y- or z-axis.
  axis = (GrayCode0 ^ GrayCode1) >> 1;

  // Calulate the split position along the axis.
  if(axis == 0) { split = 0.5 * (BoundingBoxXmin + BoundingBoxXmax); }
  else if(axis == 1) {
    split = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
  }
  else { // == 2
    split = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
  }

  // Find the direction (+1 or -1) of the axis. If 'd' is +1, the direction
  //   of the axis is to the positive of the axis, otherwise, it is -1.
  d = ((GrayCode0 & (1 << axis)) == 0) ? 1 : -1;

  // Partition the vertices into left- and right-arrays such that left points
  //   have Hilbert indices lower than the right points.
  i = 0;
  j = arraysize - 1;

  // Partition the vertices into left- and right-arrays.
  if(d > 0) {
    do {
      for(; i < arraysize; i++) {
        if(vertices[i]->point()[axis] >= split) break;
      }
      for(; j >= 0; j--) {
        if(vertices[j]->point()[axis] < split) break;
      }
      // Is the partition finished?
      if(i >= (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertices[i];
      vertices[i] = vertices[j];
      vertices[j] = swapvert;
      // Continue patitioning the array;
    } while(true);
  }
  else {
    do {
      for(; i < arraysize; i++) {
        if(vertices[i]->point()[axis] <= split) break;
      }
      for(; j >= 0; j--) {
        if(vertices[j]->point()[axis] > split) break;
      }
      // Is the partition finished?
      if(i >= (j + 1)) break;
      // Swap i-th and j-th vertices.
      swapvert = vertices[i];
      vertices[i] = vertices[j];
      vertices[j] = swapvert;
      // Continue patitioning the array;
    } while(true);
  }

  return i;
}

// The sorting code is inspired by Tetgen 1.5

void HilbertSort::Sort(MVertex **vertices, int arraysize, int e, int d,
                       double BoundingBoxXmin, double BoundingBoxXmax,
                       double BoundingBoxYmin, double BoundingBoxYmax,
                       double BoundingBoxZmin, double BoundingBoxZmax,
                       int depth)
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
  p[3] =
    Split(&(vertices[p[2]]), p[4] - p[2], transgc[e][d][2], transgc[e][d][3],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[2];
  p[6] =
    Split(&(vertices[p[4]]), p[8] - p[4], transgc[e][d][5], transgc[e][d][6],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[4];
  p[5] =
    Split(&(vertices[p[4]]), p[6] - p[4], transgc[e][d][4], transgc[e][d][5],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[4];
  p[7] =
    Split(&(vertices[p[6]]), p[8] - p[6], transgc[e][d][6], transgc[e][d][7],
          BoundingBoxXmin, BoundingBoxXmax, BoundingBoxYmin, BoundingBoxYmax,
          BoundingBoxZmin, BoundingBoxZmax) +
    p[6];

  if(maxDepth > 0) {
    if((depth + 1) == maxDepth) { return; }
  }

  // Recursively sort the points in sub-boxes.
  for(w = 0; w < 8; w++) {
    if((p[w + 1] - p[w]) > Limit) {
      if(w == 0) { e_w = 0; }
      else {
        k = 2 * ((w - 1) / 2);
        e_w = k ^ (k >> 1);
      }
      k = e_w;
      e_w = ((k << (d + 1)) & mask) | ((k >> (n - d - 1)) & mask);
      ei = e ^ e_w;
      if(w == 0) { d_w = 0; }
      else {
        d_w = ((w % 2) == 0) ? tsb1mod3[w - 1] : tsb1mod3[w];
      }
      di = (d + d_w + 1) % n;
      if(transgc[e][d][w] & 1) {
        x1 = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
        x2 = BoundingBoxXmax;
      }
      else {
        x1 = BoundingBoxXmin;
        x2 = 0.5 * (BoundingBoxXmin + BoundingBoxXmax);
      }
      if(transgc[e][d][w] & 2) { // y-axis
        y1 = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
        y2 = BoundingBoxYmax;
      }
      else {
        y1 = BoundingBoxYmin;
        y2 = 0.5 * (BoundingBoxYmin + BoundingBoxYmax);
      }
      if(transgc[e][d][w] & 4) { // z-axis
        z1 = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
        z2 = BoundingBoxZmax;
      }
      else {
        z1 = BoundingBoxZmin;
        z2 = 0.5 * (BoundingBoxZmin + BoundingBoxZmax);
      }
      Sort(&(vertices[p[w]]), p[w + 1] - p[w], ei, di, x1, x2, y1, y2, z1, z2,
           depth + 1);
    }
  }
}

void SortHilbert(std::vector<MVertex *> &v)
{
  HilbertSort h(1000);
  h.Apply(v);
}

void SortHilbert_Without_Brio(std::vector<MVertex *> &v){
  HilbertSort h(1000);
  h.Apply(v,v.size()+1);
}
