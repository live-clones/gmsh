// $Id: OctreePost.cpp,v 1.3 2008-02-17 08:48:08 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "PView.h"
#include "PViewDataList.h"
#include "Numeric.h"
#include "Message.h"
#include "ShapeFunctions.h"

static void minmax(int n, double *X, double *Y, double *Z,
		   double *min, double *max)
{
  min[0] = X[0];
  min[1] = Y[0];
  min[2] = Z[0];
  max[0] = X[0];
  max[1] = Y[0];
  max[2] = Z[0];

  for(int i = 1; i < n; i++) {
    min[0] = (X[i] < min[0]) ? X[i] : min[0];
    min[1] = (Y[i] < min[1]) ? Y[i] : min[1];
    min[2] = (Z[i] < min[2]) ? Z[i] : min[2];
    max[0] = (X[i] > max[0]) ? X[i] : max[0];
    max[1] = (Y[i] > max[1]) ? Y[i] : max[1];
    max[2] = (Z[i] > max[2]) ? Z[i] : max[2];
  }
}

static void centroid(int n, double *X, double *Y, double *Z, double *c)
{
  const double oc = 1./(double)n;
  c[0] = X[0];
  c[1] = Y[0];
  c[2] = Z[0];
  for(int i = 1; i < n; i++) {
    c[0] += X[i];
    c[1] += Y[i];
    c[2] += Z[i];
  }
  c[0] *= oc;
  c[1] *= oc;
  c[2] *= oc;
}

void linBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4];
  minmax(2, X, Y, Z, min, max);
}

void triBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6];
  minmax(3, X, Y, Z, min, max);
}

void quaBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

void tetBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  minmax(4, X, Y, Z, min, max);
}

void hexBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16];
  minmax(8, X, Y, Z, min, max);
}

void priBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12];
  minmax(6, X, Y, Z, min, max);
}

void pyrBB(void *a, double *min, double *max)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10];
  minmax(5, X, Y, Z, min, max);
}

int linInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4], uvw[3];
  line lin(X, Y, Z);
  lin.xyz2uvw(x, uvw);
  return lin.isInside(uvw[0], uvw[1], uvw[2]);
}

int triInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6], uvw[3];
  triangle tri(X, Y, Z);
  tri.xyz2uvw(x, uvw);
  return tri.isInside(uvw[0], uvw[1], uvw[2]);
}

int quaInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8], uvw[3];
  quadrangle qua(X, Y, Z);
  qua.xyz2uvw(x, uvw);
  return qua.isInside(uvw[0], uvw[1], uvw[2]);
}

int tetInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8], uvw[3];
  tetrahedron tet(X, Y, Z);
  tet.xyz2uvw(x, uvw);
  return tet.isInside(uvw[0], uvw[1], uvw[2]);
}

int hexInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16], uvw[3];
  hexahedron hex(X, Y, Z);
  hex.xyz2uvw(x, uvw);
  return hex.isInside(uvw[0], uvw[1], uvw[2]);
}

int priInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12], uvw[3];
  prism pri(X, Y, Z);
  pri.xyz2uvw(x, uvw);
  return pri.isInside(uvw[0], uvw[1], uvw[2]);
}

int pyrInEle(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10], uvw[3];
  pyramid pyr(X, Y, Z);
  pyr.xyz2uvw(x, uvw);
  return pyr.isInside(uvw[0], uvw[1], uvw[2]);
}

void linCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[2], *Z = &X[4];
  centroid(2, X, Y, Z, x);
}

void triCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[3], *Z = &X[6];
  centroid(3, X, Y, Z, x);
}

void quaCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

void tetCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[4], *Z = &X[8];
  centroid(4, X, Y, Z, x);
}

void hexCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[8], *Z = &X[16];
  centroid(8, X, Y, Z, x);
}

void priCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[6], *Z = &X[12];
  centroid(6, X, Y, Z, x);
}

void pyrCentroid(void *a, double *x)
{
  double *X = (double*) a, *Y = &X[5], *Z = &X[10];
  centroid(5, X, Y, Z, x);
}

static void addListOfStuff(Octree *o, List_T *l, int nbelm)
{
  if(!l) return;
 
  for(int i = 0; i < List_Nbr(l); i += nbelm){
    double * X = (double *)List_Pointer_Fast(l, i);
    Octree_Insert(X, o);
  }
}

OctreePost::~OctreePost() 
{
  Octree_Delete(ST); Octree_Delete(VT); Octree_Delete(TT);
  Octree_Delete(SQ); Octree_Delete(VQ); Octree_Delete(TQ);
  Octree_Delete(SS); Octree_Delete(VS); Octree_Delete(TS);
  Octree_Delete(SH); Octree_Delete(VH); Octree_Delete(TH);
  Octree_Delete(SI); Octree_Delete(VI); Octree_Delete(TI);
  Octree_Delete(SY); Octree_Delete(VY); Octree_Delete(TY);
}

OctreePost::OctreePost(PView *v) 
  : theView(v)
{
  PViewDataList *l = dynamic_cast<PViewDataList*>(theView->getData());

  if(!l){
    Msg(GERROR, "OctreePost only accepts list-based view data for now");
    return;
  }

  SBoundingBox3d bb = l->getBoundingBox();

  double min[3] = {bb.min().x(), bb.min().y(), bb.min().z()};

  double size[3] = {bb.max().x() - bb.min().x(),
		    bb.max().y() - bb.min().y(),
		    bb.max().z() - bb.min().z()};		    
  
  const int maxElePerBucket = 100; // memory vs. speed trade-off

  SL = Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
  addListOfStuff(SL, l->SL, 6 + 2 * l->getNumTimeSteps());
  Octree_Arrange(SL);
  VL = Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
  addListOfStuff(VL, l->VL, 6 + 6 * l->getNumTimeSteps());
  Octree_Arrange(VL);
  TL = Octree_Create(maxElePerBucket, min, size, linBB, linCentroid, linInEle);
  addListOfStuff(TL, l->TL, 6 + 18 * l->getNumTimeSteps());
  Octree_Arrange(TL);

  ST = Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
  addListOfStuff(ST, l->ST, 9 + 3 * l->getNumTimeSteps());
  Octree_Arrange(ST);
  VT = Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
  addListOfStuff(VT, l->VT, 9 + 9 * l->getNumTimeSteps());
  Octree_Arrange(VT);
  TT = Octree_Create(maxElePerBucket, min, size, triBB, triCentroid, triInEle);
  addListOfStuff(TT, l->TT, 9 + 27 * l->getNumTimeSteps());
  Octree_Arrange(TT);

  SQ = Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
  addListOfStuff(SQ, l->SQ, 12 + 4 * l->getNumTimeSteps());
  Octree_Arrange(SQ);
  VQ = Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
  addListOfStuff(VQ, l->VQ, 12 + 12 * l->getNumTimeSteps());
  Octree_Arrange(VQ);
  TQ = Octree_Create(maxElePerBucket, min, size, quaBB, quaCentroid, quaInEle);
  addListOfStuff(TQ, l->TQ, 12 + 36 * l->getNumTimeSteps());
  Octree_Arrange(TQ);

  SS = Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
  addListOfStuff(SS, l->SS, 12 + 4 * l->getNumTimeSteps());
  Octree_Arrange(SS);
  VS = Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
  addListOfStuff(VS, l->VS, 12 + 12 * l->getNumTimeSteps());
  Octree_Arrange(VS);
  TS = Octree_Create(maxElePerBucket, min, size, tetBB, tetCentroid, tetInEle);
  addListOfStuff(TS, l->TS, 12 + 36 * l->getNumTimeSteps());
  Octree_Arrange(TS);

  SH = Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
  addListOfStuff(SH, l->SH, 24 + 8 * l->getNumTimeSteps());
  Octree_Arrange(SH);
  VH = Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
  addListOfStuff(VH, l->VH, 24 + 24 * l->getNumTimeSteps());
  Octree_Arrange(VH);
  TH = Octree_Create(maxElePerBucket, min, size, hexBB, hexCentroid, hexInEle);
  addListOfStuff(TH, l->TH, 24 + 72 * l->getNumTimeSteps());
  Octree_Arrange(TH);

  SI = Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
  addListOfStuff(SI, l->SI, 18 + 6 * l->getNumTimeSteps());
  Octree_Arrange(SI);
  VI = Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
  addListOfStuff(VI, l->VI, 18 + 18 * l->getNumTimeSteps());
  Octree_Arrange(VI);
  TI = Octree_Create(maxElePerBucket, min, size, priBB, priCentroid, priInEle);
  addListOfStuff(TI, l->TI, 18 + 54 * l->getNumTimeSteps());
  Octree_Arrange(TI);

  SY = Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
  addListOfStuff(SY, l->SY, 15 + 5 * l->getNumTimeSteps());
  Octree_Arrange(SY);
  VY = Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
  addListOfStuff(VY, l->VY, 15 + 15 * l->getNumTimeSteps());
  Octree_Arrange(VY);
  TY = Octree_Create(maxElePerBucket, min, size, pyrBB, pyrCentroid, pyrInEle);
  addListOfStuff(TY, l->TY, 15 + 45 * l->getNumTimeSteps());
  Octree_Arrange(TY);
}

bool OctreePost::getValue(void *in, int dim, int nbNod, int nbComp, 
			  double P[3], int timestep, double *values, double *size_elem)
{
  if(!in) return false;

  double *X = (double*)in, *Y = &X[nbNod], *Z = &X[2*nbNod], *V = &X[3*nbNod], U[3];

  elementFactory factory;
  element *e = factory.create(nbNod, dim, X, Y, Z);
  if(!e) return false;

  e->xyz2uvw(P, U);
  if(timestep < 0){
    for(int i = 0; i < theView->getData()->getNumTimeSteps(); i++)
      for(int j = 0; j < nbComp; j++)
	values[nbComp * i + j] = e->interpolate(&V[nbNod * nbComp * i + j], 
						U[0], U[1], U[2], nbComp);
  }
  else{
    for(int j = 0; j < nbComp; j++)
      values[j] = e->interpolate(&V[nbNod * nbComp * timestep + j], 
				 U[0], U[1], U[2], nbComp);
  }

  if(size_elem)
    *size_elem = e->maxEdgeLength();

  delete e;
  return true;
} 

bool OctreePost::searchScalar(double x, double y, double z, double *values, 
			      int timestep, double *size_elem)
{
  double P[3] = {x, y, z};

  if(timestep < 0)
    for(int i = 0; i < theView->getData()->getNumTimeSteps(); i++)
      values[i] = 0.0; 
  else
    values[0] = 0.0;

  if(getValue(Octree_Search(P, SS), 3, 4, 1, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, SH), 3, 8, 1, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, SI), 3, 6, 1, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, SY), 3, 5, 1, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, ST), 2, 3, 1, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, SQ), 2, 4, 1, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, SL), 1, 2, 1, P, timestep, values, size_elem)) return true;

  return false;
}

bool OctreePost::searchVector(double x, double y, double z, double *values, 
			      int timestep, double *size_elem)
{
  double P[3] = {x, y, z};

  if(timestep < 0)
    for(int i = 0; i < 3 * theView->getData()->getNumTimeSteps(); i++)
      values[i] = 0.0; 
  else
    for(int i = 0; i < 3; i++)
      values[i] = 0.0;

  if(getValue(Octree_Search(P, VS), 3, 4, 3, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, VH), 3, 8, 3, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, VI), 3, 6, 3, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, VY), 3, 5, 3, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, VT), 2, 3, 3, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, VQ), 2, 4, 3, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, VL), 1, 2, 3, P, timestep, values, size_elem)) return true;

  return false;
}

bool OctreePost::searchTensor(double x, double y, double z, double *values, 
			      int timestep, double *size_elem)
{
  double P[3] = {x, y, z};

  if(timestep < 0)
    for(int i = 0; i < 9 * theView->getData()->getNumTimeSteps(); i++)
      values[i] = 0.0; 
  else
    for(int i = 0; i < 9; i++)
      values[i] = 0.0;

  if(getValue(Octree_Search(P, TS), 3, 4, 9, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, TH), 3, 8, 9, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, TI), 3, 6, 9, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, TY), 3, 5, 9, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, TT), 2, 3, 9, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, TQ), 2, 4, 9, P, timestep, values, size_elem)) return true;
  if(getValue(Octree_Search(P, TL), 1, 2, 9, P, timestep, values, size_elem)) return true;

  return false;
}
