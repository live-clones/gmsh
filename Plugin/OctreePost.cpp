// $Id: OctreePost.cpp,v 1.10 2004-10-25 00:45:47 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Octree.h"
#include "OctreePost.h"
#include "List.h"
#include "Views.h"
#include "Numeric.h"
#include "Message.h"

static double computeBarycentricTriangle(double *X, double *Y, double *Z, 
					 double *P, double *U)
{
  double mat[2][2], b[2];
  U[2] = 0.0;
  mat[0][0] = X[1]-X[0];
  mat[0][1] = X[2]-X[0];
  mat[1][0] = Y[1]-Y[0];
  mat[1][1] = Y[2]-Y[0];
  b[0] = P[0] -X[0];
  b[1] = P[1] -Y[0];
  //  Msg(WARNING, "louloutte %lf %lf %lf %lf %lf",P[0],P[1],X[0],Y[0]);

  sys2x2(mat, b, U);
  return 0.5 * ( mat[0][0] * mat[1][1] - mat[1][0] *mat[0][1]);
}

static void computeBarycentricSimplex(double *X, double *Y, double *Z, 
				      double *P, double *U)
{
  double mat[3][3], b[3];

  mat[0][0] = X[1]-X[0];
  mat[0][1] = X[2]-X[0];
  mat[0][2] = X[3]-X[0];
  mat[1][0] = Y[1]-Y[0];
  mat[1][1] = Y[2]-Y[0];
  mat[1][2] = Y[3]-Y[0];
  mat[2][0] = Z[1]-Z[0];
  mat[2][1] = Z[2]-Z[0];
  mat[2][2] = Z[3]-Z[0];
  b[0] = P[0] - X[0];
  b[1] = P[1] - Y[0];
  b[2] = P[2] - Z[0];
  double det;
  sys3x3(mat, b, U, &det);
}

static void minmax(int n,
		   double *X, 
		   double *Y, 
		   double *Z,
		   double *min,
		   double *max)
{
  min[0] = X[0];
  min[1] = Y[0];
  min[2] = Z[0];
  max[0] = X[0];
  max[1] = Y[0];
  max[2] = Z[0];

  for (int i = 1; i < n; ++i) {
    min[0] = (X[i] < min[0]) ? X[i]:min[0];
    min[1] = (Y[i] < min[1]) ? Y[i]:min[1];
    min[2] = (Z[i] < min[2]) ? Z[i]:min[2];
    max[0] = (X[i] > max[0]) ? X[i]:max[0];
    max[1] = (Y[i] > max[1]) ? Y[i]:max[1];
    max[2] = (Z[i] > max[2]) ? Z[i]:max[2];
  }
}

static void centroid(int n, 
		     double *X,
		     double *Y,
		     double *Z,
		     double *c)
{
  const double oc = 1./(double)n;
  c[0] = X[0];
  c[1] = Y[0];
  c[2] = Z[0];
  for (int i = 1; i < n; ++i) {
    c[0] += X[i];
    c[1] += Y[i];
    c[2] += Z[i];
  }
  c[0] *= oc;
  c[1] *= oc;
  c[2] *= oc;
}

void PostTriangleBB(void *a, double *min, double *max)
{
  double *X = (double*) a;
  double *Y = &X[3];
  double *Z = &X[6];

  minmax(3, X, Y, Z, min, max);

  min[2] = -1;
  max[2] =  1;
}

int PostTriangleInEle(void *a, double *x)
{
  const double eps = 1.e-3;
  double U[3];
  double *X = (double*) a;
  double *Y = &X[3];
  double *Z = &X[6];
  computeBarycentricTriangle(X, Y, Z, x, U);
  double W = 1.-U[0]-U[1];
  if (U[0] < -eps || U[0] > 1+eps || 
      U[1] < -eps || U[1] > 1+eps ||
      W    < -eps || W    > 1+eps) return 0;
  return 1;
}

void PostTriangleCentroid(void *a, double *x)
{
  double *X = (double*) a;
  double *Y = &X[3];
  double *Z = &X[6];
  centroid(3, X, Y, Z, x);
}

void PostSimplexBB(void *a, double *min, double *max)
{
  double *X = (double*) a;
  double *Y = &X[4];
  double *Z = &X[8];

  minmax(4, X, Y, Z, min, max);
}

int PostSimplexInEle(void *a, double *x)
{
  const double eps = 1.e-5;
  double U[3];
  double *X = (double*) a;
  double *Y = &X[4];
  double *Z = &X[8];
  computeBarycentricSimplex(X, Y, Z, x, U);
  double W = 1.-U[0]-U[1]-U[2];

  if(U[0] < -eps || U[0] > 1+eps || 
     U[1] < -eps || U[1] > 1+eps ||
     U[2] < -eps || U[2] > 1+eps ||
     W    < -eps || W    > 1+eps) return 0;
  return 1;
}

void PostSimplexCentroid(void *a, double *x)
{
  double *X = (double*) a;
  double *Y = &X[4];
  double *Z = &X[8];
  centroid (4, X, Y, Z, x);
}

static void addListOfStuff(Octree *o, 
			   List_T *l, 
			   int nbelm)
{
  if(!l) return;
 
  for(int i = 0; i < List_Nbr(l); i += nbelm){
    double * X = (double *)List_Pointer_Fast(l, i);
    // Msg(WARNING, "Add in view : %lf %lf %lf %d %d %d", X[0],X[1],X[2],i,List_Nbr(l),nbelm);
    Octree_Insert(X, o);
  }
}

OctreePost::~OctreePost() 
{
  Octree_Delete(ST);
  Octree_Delete(VT);
  Octree_Delete(TT);
  Octree_Delete(SS);
  Octree_Delete(VS);
  Octree_Delete(TS);
}

OctreePost::OctreePost(Post_View *v) 
  : theView(v)
{
  double min [3] = {v->BBox[0],v->BBox[2],v->BBox[4]};

  double size[3] = {v->BBox[1]-v->BBox[0],
		    v->BBox[3]-v->BBox[2],
		    v->BBox[5]-v->BBox[4]};		    
  
  const int maxElePerBucket = 100; // memory vs. speed trade-off

  ST = Octree_Create(maxElePerBucket, min, size, 
		     PostTriangleBB,
		     PostTriangleCentroid,
		     PostTriangleInEle);
  addListOfStuff(ST, v->ST, 9 + 3 * v->NbTimeStep);

  VT = Octree_Create(maxElePerBucket, min, size, 
		     PostTriangleBB,
		     PostTriangleCentroid,
		     PostTriangleInEle);
  addListOfStuff(VT, v->VT, 9 + 9 * v->NbTimeStep);

  TT = Octree_Create(maxElePerBucket, min, size, 
		     PostTriangleBB,
		     PostTriangleCentroid,
		     PostTriangleInEle);
  addListOfStuff(TT, v->TT, 9 + 27 * v->NbTimeStep);

  SS = Octree_Create(maxElePerBucket, min, size, 
		     PostSimplexBB,
		     PostSimplexCentroid,
		     PostSimplexInEle);
  addListOfStuff(SS, v->SS, 12 + 4 * v->NbTimeStep);

  VS = Octree_Create(maxElePerBucket, min, size, 
		     PostSimplexBB,
		     PostSimplexCentroid,
		     PostSimplexInEle);
  addListOfStuff(VS, v->VS, 12 + 12 * v->NbTimeStep);

  TS = Octree_Create(maxElePerBucket, min, size, 
		     PostSimplexBB,
		     PostSimplexCentroid,
		     PostSimplexInEle);
  addListOfStuff(TS, v->TS, 12 + 36 * v->NbTimeStep);
  
  Octree_Arrange(ST);
  Octree_Arrange(VT);
  Octree_Arrange(TT);
  Octree_Arrange(SS);
  Octree_Arrange(VS);
  Octree_Arrange(TS);
}

bool OctreePost::searchVector(double x, 
			      double y, 
			      double z,
			      double * values,
			      double * size_elem,
			      int timestep)
{
  double P[3] = {x,y,z};

  if(timestep < 0)
    for (int i = 0; i < 3*theView->NbTimeStep; ++i)
      values[i] = 0.0; 
  else
    values[0] = values[1] = values[2] = 0.0;
  
  void * inVT = Octree_Search(P, VT);

  // values[0] = -0.5*y;
  // values[1] = 0.5*x;
  // values[2] = 1;
  // return true;

  if(inVT){
    double U[3];
    double *X = (double*) inVT;
    double *Y = &X[3];
    double *Z = &X[6];
    double *V = &X[9];
    *size_elem = fabs(computeBarycentricTriangle(X, Y, Z, P, U));
    // bof
    *size_elem = sqrt(*size_elem);
    if(timestep < 0){
      for (int i = 0; i < theView->NbTimeStep; ++i){
	values[3*i] = 
	  V[9*i+3] * U[0] + 
	  V[9*i+6] * U[1] + 
	  V[9*i+0] * (1-U[0]-U[1]); 
	values[3*i+1] = 
	  V[9*i+4] * U[0] + 
	  V[9*i+7] * U[1] + 
	  V[9*i+1] * (1-U[0]-U[1]); 
	values[3*i+2] = 
	  V[9*i+5] * U[0] + 
	  V[9*i+8] * U[1] + 
	  V[9*i+2] * (1-U[0]-U[1]); 
      }
    }
    else{
      values[0] = 
	V[9*timestep+3] * U[0] + 
	V[9*timestep+6] * U[1] + 
	V[9*timestep+0] * (1-U[0]-U[1]); 
      values[1] = 
	V[9*timestep+4] * U[0] + 
	V[9*timestep+7] * U[1] + 
	V[9*timestep+1] * (1-U[0]-U[1]); 
      values[2] = 
	V[9*timestep+5] * U[0] + 
	V[9*timestep+8] * U[1] + 
	V[9*timestep+2] * (1-U[0]-U[1]); 
      /* Msg(WARNING, "found %lf %lf %lf %lf  %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
	  values[0],values[1],values[2],
	  U[0],U[1],
	  X[0],X[1],X[2],
	  Y[0],Y[1],Y[2],
	  Z[0],Z[1],Z[2]); */
    }
    return true;
  } 

  void * inVS = Octree_Search(P, VS);

  if(inVS){
    double U[3];
    double *X = (double*) inVS;
    double *Y = &X[4];
    double *Z = &X[8];
    double *V = &X[12];
    computeBarycentricSimplex(X, Y, Z, P, U);
    // bof
    *size_elem = .1;
    if(timestep < 0){
      for (int i=0;i<theView->NbTimeStep;++i){
	values[3*i] = 
	  V[12*i+3]  * U[0] + 
	  V[12*i+6]  * U[1] + 
	  V[12*i+9]  * U[2] + 
	  V[12*i+0]  * (1-U[0]-U[1]-U[2]); 
	values[3*i+1] = 
	  V[12*i+4]  * U[0] + 
	  V[12*i+9]  * U[1] + 
	  V[12*i+10] * U[2] + 
	  V[12*i+1]  * (1-U[0]-U[1]-U[2]); 
	values[3*i+2] = 
	  V[12*i+5]  * U[0] + 
	  V[12*i+7]  * U[1] + 
	  V[12*i+11] * U[2] + 
	  V[12*i+2]  * (1-U[0]-U[1]-U[2]); 
      }
    }
    else{
      values[0] = 
	V[12*timestep+3]  * U[0] + 
	V[12*timestep+6]  * U[1] + 
	V[12*timestep+9]  * U[2] + 
	V[12*timestep+0]  * (1-U[0]-U[1]-U[2]); 
      values[1] = 
	V[12*timestep+4]  * U[0] + 
	V[12*timestep+7]  * U[1] + 
	V[12*timestep+10] * U[2] + 
	V[12*timestep+1 ] * (1-U[0]-U[1]-U[2]); 
      values[2] = 
	V[12*timestep+5 ] * U[0] + 
	V[12*timestep+8 ] * U[1] + 
	V[12*timestep+11] * U[2] + 
	V[12*timestep+2 ] * (1-U[0]-U[1]-U[2]); 
    }
    return true;
  } 
  return false;
}

bool OctreePost::searchScalar(double x,
			      double y, 
			      double z,
			      double * values,
			      int timestep)
{
  double P[3] = {x,y,z};
  void * inST = Octree_Search(P, ST);

  if(timestep < 0)
    for(int i = 0; i <theView->NbTimeStep; ++i)
      values[i] = 0.0; 
  else
    values[0] = 0.0;

  if(inST){
    double U[3];
    double *X = (double*) inST;
    double *Y = &X[3];
    double *Z = &X[6];
    double *V = &X[9];
    computeBarycentricTriangle(X, Y, Z, P, U);
    if(timestep < 0){
      for (int i = 0; i < theView->NbTimeStep; ++i){
	values[i] = 
	  V[3*i+1] * U[0] + 
	  V[3*i+2] * U[1] + 
	  V[3*i+0] * (1-U[0]-U[1]); 
      }
    }
    else{
      values[0] = 
	V[3*timestep+1] * U[0] + 
	V[3*timestep+2] * U[1] + 
	V[3*timestep+0] * (1-U[0]-U[1]); 
    }
    return true;
  } 
  
  void * inSS = Octree_Search(P, SS);
  
  if(inSS){
    double U[3];
    double *X = (double*) inSS;
    double *Y = &X[4];
    double *Z = &X[8];
    double *V = &X[12];
    computeBarycentricSimplex(X, Y, Z, P, U);      
    if(timestep < 0){
      for (int i = 0; i < theView->NbTimeStep; ++i){
	values[i] = 
	  V[3*i+1] * U[0] + 
	  V[3*i+2] * U[1] + 
	  V[3*i+3] * U[2] + 
	  V[3*i+0] * (1.-U[0]-U[1]-U[2]); 
      }
    }
    else{
      values[0] = 
	V[3*timestep+1] * U[0] + 
	V[3*timestep+2] * U[1] + 
	V[3*timestep+3] * U[2] + 
	V[3*timestep  ] * (1-U[0]-U[1]-U[2]); 
    }
    return true;
  } 
  
  return false;
}
