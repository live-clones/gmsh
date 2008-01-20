// $Id: Post.cpp,v 1.147 2008-01-20 12:21:30 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include <algorithm>
#include "Message.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "Draw.h"
#include "Iso.h"
#include "PView.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "Context.h"
#include "gl2ps.h"


#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

extern Context_T CTX;

#define NMAX 20

void saturate(int nb, double val[NMAX][9], double vmin, double vmax, 
	      int i0=0, int i1=1, int i2=2, int i3=3, 
	      int i4=4, int i5=5, int i6=6, int i7=7)
{
  int id[8] = {i0, i1, i2, i3, i4, i5, i6, i7};
  for(int i = 0; i < nb; i++){
    if(val[id[i]][0] > vmax)      val[id[i]][0] = vmax;
    else if(val[id[i]][0] < vmin) val[id[i]][0] = vmin;
  }
}

SVector3 normal3(double xyz[NMAX][3], int i0=0, int i1=1, int i2=2)
{
  SVector3 t1(xyz[i1][0] - xyz[i0][0], 
	      xyz[i1][1] - xyz[i0][1],
	      xyz[i1][2] - xyz[i0][2]);
  SVector3 t2(xyz[i2][0] - xyz[i0][0], 
	      xyz[i2][1] - xyz[i0][1],
	      xyz[i2][2] - xyz[i0][2]);
  SVector3 n = crossprod(t1, t2);
  n.normalize();
  return n;
}

SVector3 getPointNormal(PView *p, double v)
{
  PViewOptions *opt = p->getOptions();
  SVector3 n(0., 0., 0.);
  if(opt->PointType > 0){
    // when we draw spheres, we use the normalized value (between 0
    // and 1) stored in the first component of the normal to modulate
    // the radius
    double d = opt->TmpMax - opt->TmpMin;
    n[0] = (v - opt->TmpMin) / (d ? d : 1.);
  }
  return n;
}

void getLineNormal(PView *p, double x[2], double y[2], double z[2],
		   double *v, SVector3 n[2], bool computeNormal)
{
  PViewOptions *opt = p->getOptions();

  if(opt->LineType > 0){
    if(v){
      // when we draw tapered cylinders, we use the normalized values
      // (between 0 and 1) stored in the first component of the
      // normals to modulate the width
      double d = opt->TmpMax - opt->TmpMin;
      n[0][0] = (v[0] - opt->TmpMin) / (d ? d : 1.);
      n[1][0] = (v[1] - opt->TmpMin) / (d ? d : 1.);
    }
    else{
      // when we don't have values we use maximum width cylinders
      n[0][0] = n[1][0] = 1.;
    }
  }
  else if(computeNormal){
    SBoundingBox3d bb = p->getData()->getBoundingBox();
    if(bb.min().z() == bb.max().z())
      n[0] = n[1] = SVector3(0., 0., 1.);
    else if(bb.min().y() == bb.max().y())
      n[0] = n[1] = SVector3(0., 1., 0.);
    else if(bb.min().x() == bb.max().x())
      n[0] = n[1] = SVector3(1., 0., 0.);
    else{
      // we don't have any info about the normal, just pick one
      SVector3 t(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
      SVector3 ex(0., 0., 0.);
      if(t[0] == 0.)
	ex[0] = 1.;
      else if(t[1] == 0.)
	ex[1] = 1.;
      else
	ex[2] = 1.;
      n[0] = crossprod(t, ex);
      n[0].normalize();
      n[1] = n[0];
    }
  }
}

bool getExternalValues(PView *p, int index, int iele, int numNodes,
		       int numComp, double val[NMAX][9], 
		       int &numComp2, double val2[NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  // use self by default
  numComp2 = numComp;
  for(int i = 0; i < numNodes; i++)
    for(int j = 0; j < numComp; j++)
      val2[i][j] = val[i][j];
  opt->ExternalMin = opt->TmpMin;
  opt->ExternalMax = opt->TmpMax;

  if(index < 0 || index >= (int)PView::list.size()) return false;

  PView *p2 = PView::list[index];
  PViewData *data2 = p2->getData();

  if(opt->TimeStep < data2->getNumTimeSteps() && iele < data2->getNumElements()){
    if(data2->getNumNodes(iele) == numNodes){
      numComp2 = data2->getNumComponents(iele);
      for(int i = 0; i < numNodes; i++)
	for(int j = 0; j < numComp2; j++)
	  data2->getValue(iele, i, j, opt->TimeStep, val2[i][j]);
      if(opt->RangeType == PViewOptions::Custom){
	opt->ExternalMin = opt->CustomMin;
	opt->ExternalMax = opt->CustomMax;
      }
      else if(opt->RangeType == PViewOptions::PerTimeStep){
	opt->ExternalMin = data2->getMin(opt->TimeStep);
	opt->ExternalMax = data2->getMax(opt->TimeStep);
      }
      else{
	opt->ExternalMin = data2->getMin();
	opt->ExternalMax = data2->getMax();
      }
      return true;
    }
  }
  return false;
}

void applyGeneralRaise(PView *p, int numNodes, int numComp, 
		       double vals[NMAX][9], double xyz[NMAX][3])
{
  PViewOptions *opt = p->getOptions();

  for(int k = 0; k < numNodes; k++) {
    double d[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
    for(int l = 0; l < numComp; l++) d[l] = vals[k][l];
#if defined(HAVE_MATH_EVAL)
    char *names[] = { "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8" ,
		      "x", "y", "z" };
    double values[] = { d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8],
			xyz[k][0], xyz[k][1], xyz[k][2] };
    for(int i = 0; i < 3; i++) {
      if(opt->GenRaise_f[i])
        xyz[k][i] += opt->GenRaiseFactor * evaluator_evaluate
	  (opt->GenRaise_f[i], sizeof(names) / sizeof(names[0]), names, values);
    }
#else
    for(int i = 0; i < 3; i++){
      int comp = (int)opt->GenRaise_f[i];
      if(comp >= 0)
	xyz[k][i] += opt->GenRaiseFactor * d[comp];
    }
#endif
  }
}

void changeCoordinates(PView *p, int iele, int numNodes, int numEdges, 
		       int numComp, double xyz[NMAX][3], double val[NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  if(opt->Explode != 1.) {
    double barycenter[3] = {0., 0., 0.};
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
	barycenter[j] += xyz[i][j];
    for(int j = 0; j < 3; j++)
      barycenter[j] /= (double)numNodes;
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
	xyz[i][j] = barycenter[j] + opt->Explode * (xyz[i][j] - barycenter[j]);
  }
  
  if(opt->Transform[0][0] != 1. || opt->Transform[0][1] != 0. || 
     opt->Transform[0][2] != 0. || opt->Transform[1][0] != 0. || 
     opt->Transform[1][1] != 1. || opt->Transform[1][2] != 0. ||
     opt->Transform[2][0] != 0. || opt->Transform[2][1] != 0. || 
     opt->Transform[2][2] != 1.){
    for(int i = 0; i < numNodes; i++) {
      double old[3] = {xyz[i][0], xyz[i][1], xyz[i][2]};
      for(int j = 0; j < 3; j++){
	xyz[i][j] = 0.;
	for(int k = 0; k < 3; k++)
	  xyz[i][j] += opt->Transform[j][k] * old[k];
      }
    }
  }
  
  if(opt->Offset[0] || opt->Offset[1] || opt->Offset[2]){
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
	xyz[i][j] += opt->Offset[j];
  }
  
  if(opt->Raise[0] || opt->Raise[1] || opt->Raise[2]){
    for(int i = 0; i < numNodes; i++){
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++)
	xyz[i][j] += opt->Raise[j] * v;
    }
  }

  if(opt->NormalRaise && numEdges >= 1 && numEdges <= 4){
    SVector3 n;
    if(numEdges == 1){
      // assumes lines in z=const plane, and raises in that plane
      double x[2] = {xyz[0][0], xyz[1][0]};
      double y[2] = {xyz[0][1], xyz[1][1]};
      double z[2] = {xyz[0][2], xyz[1][2]};
      SVector3 p(0, 0, 1.);
      SVector3 t(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
      n = crossprod(t, p);
      n.normalize();
    }
    else
      n = normal3(xyz);
    for(int i = 0; i < numNodes; i++){
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++)
	xyz[i][j] += n[j] * opt->NormalRaise * v;
    }
  }

  if(numComp == 3 && opt->VectorType == PViewOptions::Displacement){
    for(int i = 0; i < numNodes; i++){
      for(int j = 0; j < 3; j++)
	xyz[i][j] += opt->DisplacementFactor * val[i][j];
    }
  }

  if(opt->UseGenRaise){
    int numComp2;
    double val2[NMAX][9];
    getExternalValues(p, opt->ViewIndexForGenRaise, iele, numNodes, 
		      numComp, val, numComp2, val2);
    applyGeneralRaise(p, numNodes, numComp2, val2, xyz);
  }
}

void addOutlinePoint(PView *p, double xyz[NMAX][3], unsigned int color, bool pre,
		     int i0=0)
{
  if(pre) return;
  SVector3 n = getPointNormal(p, 1.);
  p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &color, 0, true);
}

void addScalarPoint(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre,
		    int i0=0, bool unique=false)
{
  if(pre) return;

  PViewOptions *opt = p->getOptions();

  double vmin = opt->TmpMin, vmax = opt->TmpMax;
  if(opt->SaturateValues) saturate(1, val, vmin, vmax, i0);

  if(val[i0][0] >= vmin && val[i0][0] <= vmax){
    unsigned int col = opt->getColor(val[i0][0], vmin, vmax);
    SVector3 n = getPointNormal(p, val[i0][0]);
    p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &col, 0, unique);
  }
}

void addOutlineLine(PView *p, double xyz[NMAX][3], unsigned int color, bool pre,
		    int i0=0, int i1=1)
{
  if(pre) return;

  const int in[3] = {i0, i1};
  unsigned int col[2];
  double x[2], y[2], z[2];
  for(int i = 0; i < 2; i++){
    x[i] = xyz[in[i]][0]; y[i] = xyz[in[i]][1]; z[i] = xyz[in[i]][2]; 
    col[i] = color;
  }
  SVector3 n[2];
  getLineNormal(p, x, y, z, 0, n, true);
  p->va_lines->add(x, y, z, n, col, 0, true);
}

void addScalarLine(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre,
		   int i0=0, int i1=1, bool unique=false)
{
  if(pre) return;

  PViewOptions *opt = p->getOptions();

  if(opt->Boundary > 0){
    opt->Boundary--;
    addScalarPoint(p, xyz, val, pre, i0, true);
    addScalarPoint(p, xyz, val, pre, i1, true);
    opt->Boundary++;
    return;
  }

  double vmin = opt->TmpMin, vmax = opt->TmpMax;
  if(opt->SaturateValues) saturate(2, val, vmin, vmax, i0, i1);

  double x[2] = {xyz[i0][0], xyz[i1][0]};
  double y[2] = {xyz[i0][1], xyz[i1][1]};
  double z[2] = {xyz[i0][2], xyz[i1][2]};
  double v[2] = {val[i0][0], val[i1][0]};

  if(opt->IntervalsType == PViewOptions::Continuous){
    SVector3 n[2];
    getLineNormal(p, x, y, z, v, n, true);
    if(val[i0][0] >= vmin && val[i0][0] <= vmax &&
       val[i1][0] >= vmin && val[i1][0] <= vmax){
      unsigned int col[2];
      for(int i = 0; i < 2; i++)
	col[i] = opt->getColor(v[i], vmin, vmax);
      p->va_lines->add(x, y, z, n, col, 0, unique);
    }
    else{
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb == 2){
	unsigned int col[2];
	for(int i = 0; i < 2; i++)
	  col[i] = opt->getColor(v2[i], vmin, vmax);
	p->va_lines->add(x2, y2, z2, n, col, 0, unique);
      }
    }
  }

  if(opt->IntervalsType == PViewOptions::Discrete){
    for(int k = 0; k < opt->NbIso; k++){
      if(vmin == vmax) k = opt->NbIso / 2;
      double min = opt->getScaleValue(k, opt->NbIso + 1, vmin, vmax);
      double max = opt->getScaleValue(k + 1, opt->NbIso + 1, vmin, vmax);
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb == 2){
	unsigned color = opt->getColor(k, opt->NbIso);
	unsigned int col[2] = {color, color};
	SVector3 n[2];
	getLineNormal(p, x2, y2, z2, v2, n, true);
	p->va_lines->add(x2, y2, z2, n, col, 0, unique);
      }
      if(vmin == vmax) break;
    }
  }
  
  if(opt->IntervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->NbIso; k++) {
      if(vmin == vmax) k = opt->NbIso / 2;
      double iso = opt->getScaleValue(k, opt->NbIso, vmin, vmax);
      double x2[1], y2[1], z2[1];
      int nb = IsoLine(x, y, z, v, iso, x2, y2, z2);
      if(nb == 1){
	unsigned int color = opt->getColor(k, opt->NbIso);
	SVector3 n = getPointNormal(p, iso);
	p->va_points->add(x2, y2, z2, &n, &color, 0, unique);
      }
      if(vmin == vmax) break;
    }
  }
}

void addOutlineTriangle(PView *p, double xyz[NMAX][3], unsigned int color, bool pre,
			int i0=0, int i1=1, int i2=2)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  for(int i = 0; i < 3; i++){
    double x[2] = {xyz[il[i][0]][0], xyz[il[i][1]][0]};
    double y[2] = {xyz[il[i][0]][1], xyz[il[i][1]][1]};
    double z[2] = {xyz[il[i][0]][2], xyz[il[i][1]][2]};
    SVector3 n[2] = {nfac, nfac};
    unsigned int col[2] = {color, color};
    if(opt->SmoothNormals){
      for(int j = 0; j < 2; j++){
	if(pre) p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
	else p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
    }
    getLineNormal(p, x, y, z, 0, n, false);
    if(!pre) p->va_lines->add(x, y, z, n, col, 0, true);
  }
}

void addScalarTriangle(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre,
		       int i0=0, int i1=1, int i2=2, bool unique=false, bool skin=false)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 3; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->Boundary++;
    return;
  }

  double vmin = opt->TmpMin, vmax = opt->TmpMax;
  if(opt->SaturateValues) saturate(3, val, vmin, vmax, i0, i1, i2);

  double x[3] = {xyz[i0][0], xyz[i1][0], xyz[i2][0]};
  double y[3] = {xyz[i0][1], xyz[i1][1], xyz[i2][1]};
  double z[3] = {xyz[i0][2], xyz[i1][2], xyz[i2][2]};
  double v[3] = {val[i0][0], val[i1][0], val[i2][0]};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  if(opt->IntervalsType == PViewOptions::Continuous){
    if(val[i0][0] >= vmin && val[i0][0] <= vmax &&
       val[i1][0] >= vmin && val[i1][0] <= vmax &&
       val[i2][0] >= vmin && val[i2][0] <= vmax){
      SVector3 n[3] = {nfac, nfac, nfac};
      unsigned int col[3];
      for(int i = 0; i < 3; i++){
	if(opt->SmoothNormals){
	  if(pre) p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	  else p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	}
	col[i] = opt->getColor(v[i], vmin, vmax);
      }
      if(!pre) p->va_triangles->add(x, y, z, n, col, 0, unique, skin);
    }
    else{
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb >= 3){
	for(int j = 2; j < nb; j++){
	  double x3[3] = {x2[0], x2[j - 1], x2[j]};
	  double y3[3] = {y2[0], y2[j - 1], y2[j]};
	  double z3[3] = {z2[0], z2[j - 1], z2[j]};
	  double v3[3] = {v2[0], v2[j - 1], v2[j]};
	  SVector3 n[3] = {nfac, nfac, nfac};
	  unsigned int col[3];
	  for(int i = 0; i < 3; i++){
	    if(opt->SmoothNormals){
	      if(pre) p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
	      else p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
	    }
	    col[i] = opt->getColor(v3[i], vmin, vmax);
	  }
	  if(!pre) p->va_triangles->add(x3, y3, z3, n, col, 0, unique, skin);
	}
      }
    }
  }

  if(opt->IntervalsType == PViewOptions::Discrete){
    for(int k = 0; k < opt->NbIso; k++){
      if(vmin == vmax) k = opt->NbIso / 2;
      double min = opt->getScaleValue(k, opt->NbIso + 1, vmin, vmax);
      double max = opt->getScaleValue(k + 1, opt->NbIso + 1, vmin, vmax);
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb >= 3){
	unsigned color = opt->getColor(k, opt->NbIso);
	unsigned int col[3] = {color, color, color};
	for(int j = 2; j < nb; j++){
	  double x3[3] = {x2[0], x2[j - 1], x2[j]};
	  double y3[3] = {y2[0], y2[j - 1], y2[j]};
	  double z3[3] = {z2[0], z2[j - 1], z2[j]};
	  SVector3 n[3] = {nfac, nfac, nfac};
	  if(opt->SmoothNormals){
	    for(int i = 0; i < 3; i++){
	      if(pre) p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
	      else p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
	    }
	  }
	  if(!pre) p->va_triangles->add(x3, y3, z3, n, col, 0, unique, skin);
	}
      }
      if(vmin == vmax) break;
    }
  }
  
  if(opt->IntervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->NbIso; k++) {
      if(vmin == vmax) k = opt->NbIso / 2;
      double iso = opt->getScaleValue(k, opt->NbIso, vmin, vmax);
      double x2[3], y2[3], z2[3];
      int nb = IsoTriangle(x, y, z, v, iso, x2, y2, z2);
      if(nb == 2){
	unsigned int color = opt->getColor(k, opt->NbIso);
	unsigned int col[2] = {color, color};
	SVector3 n[2] = {nfac, nfac};
	if(opt->SmoothNormals){
	  for(int i = 0; i < 2; i++){
	    if(pre) p->normals->add(x2[i], y2[i], z2[i], n[i][0], n[i][1], n[i][2]);
	    else p->normals->get(x2[i], y2[i], z2[i], n[i][0], n[i][1], n[i][2]);
	  }
	}
	double v[2] = {iso, iso};
	getLineNormal(p, x, y, z, v, n, false);
	if(!pre) p->va_lines->add(x2, y2, z2, n, col, 0, unique);
      }
      if(vmin == vmax) break;
    }
  }
}

void addOutlineQuadrangle(PView *p, double xyz[NMAX][3], unsigned int color, bool pre,
			  int i0=0, int i1=1, int i2=2, int i3=3)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  for(int i = 0; i < 4; i++){
    double x[2] = {xyz[il[i][0]][0], xyz[il[i][1]][0]};
    double y[2] = {xyz[il[i][0]][1], xyz[il[i][1]][1]};
    double z[2] = {xyz[il[i][0]][2], xyz[il[i][1]][2]};
    SVector3 n[2] = {nfac, nfac};
    unsigned int col[2] = {color, color};
    if(opt->SmoothNormals){
      for(int j = 0; j < 2; j++){
	if(pre) p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
	else p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
    }
    getLineNormal(p, x, y, z, 0, n, false);
    if(!pre) p->va_lines->add(x, y, z, n, col, 0, true);
  }
}

void addScalarQuadrangle(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre,
			 int i0=0, int i1=1, int i2=2, int i3=3, bool unique=false)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};
  const int it[2][3] = {{i0, i1, i2}, {i0, i2, i3}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 4; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->Boundary++;
    return;
  }
  
  for(int i = 0; i < 2; i++)
    addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], unique);
}

void addOutlineTetrahedron(PView *p, double xyz[NMAX][3], unsigned int color, bool pre)
{
  const int it[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

void addScalarTetrahedron(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre,
			  int i0=0, int i1=1, int i2=2, int i3=3)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{i0, i2, i1}, {i0, i1, i3}, {i0, i3, i2}, {i3, i1, i2}};

  if(opt->Boundary > 0 ||
     opt->IntervalsType == PViewOptions::Continuous ||
     opt->IntervalsType == PViewOptions::Discrete){
    bool skin = (opt->Boundary > 0) ? false : opt->DrawSkinOnly;
    opt->Boundary--;
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true, skin);
    opt->Boundary++;
    return;
  }

  double vmin = opt->TmpMin, vmax = opt->TmpMax;
  if(opt->SaturateValues) saturate(4, val, vmin, vmax, i0, i1, i2, i3);

  double x[4] = {xyz[i0][0], xyz[i1][0], xyz[i2][0], xyz[i3][0]};
  double y[4] = {xyz[i0][1], xyz[i1][1], xyz[i2][1], xyz[i3][1]};
  double z[4] = {xyz[i0][2], xyz[i1][2], xyz[i2][2], xyz[i3][2]};
  double v[4] = {val[i0][0], val[i1][0], val[i2][0], val[i3][0]};

  if(opt->IntervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->NbIso; k++) {
      if(vmin == vmax) k = opt->NbIso / 2;
      double iso = opt->getScaleValue(k, opt->NbIso, vmin, vmax);
      double x2[NMAX], y2[NMAX], z2[NMAX], nn[3];
      int nb = IsoSimplex(x, y, z, v, iso, x2, y2, z2, nn);
      if(nb >= 3){
	unsigned int color = opt->getColor(k, opt->NbIso);
	unsigned int col[3] = {color, color, color};
	for(int j = 2; j < nb; j++){
	  double x3[3] = {x2[0], x2[j - 1], x2[j]};
	  double y3[3] = {y2[0], y2[j - 1], y2[j]};
	  double z3[3] = {z2[0], z2[j - 1], z2[j]};
	  SVector3 n[3];
	  for(int i = 0; i < 3; i++){
	    n[i][0] = nn[0]; n[i][1] = nn[1]; n[i][2] = nn[2];
	    if(opt->SmoothNormals){
	      if(pre) p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
	      else p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
	    }
	  }
	  if(!pre) p->va_triangles->add(x3, y3, z3, n, col, 0, false, false);
	}
      }
      if(vmin == vmax) break;
    }
  }
}

void addOutlineHexahedron(PView *p, double xyz[NMAX][3], unsigned int color, bool pre)
{
  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
			{1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};

  for(int i = 0; i < 6; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], 
			 iq[i][2], iq[i][3]);
}

void addScalarHexahedron(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
			{1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  const int is[6][4] = {{0, 1, 3, 7}, {0, 4, 1, 7}, {1, 4, 5, 7},
			{1, 2, 3, 7}, {1, 6, 2, 7}, {1, 5, 6, 7}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 6; i++)
      addScalarQuadrangle(p, xyz, val, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3], true);
    opt->Boundary++;
    return;
  }
  
  for(int i = 0; i < 6; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2], is[i][3]);
}

void addOutlinePrism(PView *p, double xyz[NMAX][3], unsigned int color, bool pre)
{
  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};

  for(int i = 0; i < 3; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3]);
  for(int i = 0; i < 2; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

void addScalarPrism(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};
  const int is[3][4] = {{0, 1, 2, 3}, {3, 4, 5, 2}, {1, 2, 4, 3}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 3; i++)
      addScalarQuadrangle(p, xyz, val, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3], true);
    for(int i = 0; i < 2; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->Boundary++;
    return;
  }
  
  for(int i = 0; i < 3; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2], is[i][3]);
}

void addOutlinePyramid(PView *p, double xyz[NMAX][3], unsigned int color, bool pre)
{
  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};

  addOutlineQuadrangle(p, xyz, color, pre, 0, 3, 2, 1);
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

void addScalarPyramid(PView *p, double xyz[NMAX][3], double val[NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};
  const int is[2][4] = {{0, 1, 2, 4}, {2, 3, 0, 4}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    addScalarQuadrangle(p, xyz, val, pre, 0, 3, 2, 1, true);
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->Boundary++;
    return;
  }

  for(int i = 0; i < 2; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2], is[i][3]);
}

void addOutlineElement(PView *p, int numEdges, double xyz[NMAX][3], bool pre)
{
  PViewOptions *opt = p->getOptions();
  switch(numEdges){
  case 0: addOutlinePoint(p, xyz, opt->color.point, pre); break;
  case 1: addOutlineLine(p, xyz, opt->color.line, pre); break;
  case 3: addOutlineTriangle(p, xyz, opt->color.triangle, pre); break;
  case 4: addOutlineQuadrangle(p, xyz, opt->color.quadrangle, pre); break;
  case 6: addOutlineTetrahedron(p, xyz, opt->color.tetrahedron, pre); break;
  case 12: addOutlineHexahedron(p, xyz, opt->color.hexahedron, pre); break;
  case 9: addOutlinePrism(p, xyz, opt->color.prism, pre); break;
  case 8: addOutlinePyramid(p, xyz, opt->color.pyramid, pre); break;
  }
}

void addScalarElement(PView *p, int numEdges, double xyz[NMAX][3],
		      double val[NMAX][9], bool pre)
{
  switch(numEdges){
  case 0: addScalarPoint(p, xyz, val, pre); break;
  case 1: addScalarLine(p, xyz, val, pre); break;
  case 3: addScalarTriangle(p, xyz, val, pre); break;
  case 4: addScalarQuadrangle(p, xyz, val, pre); break;
  case 6: addScalarTetrahedron(p, xyz, val, pre); break;
  case 12: addScalarHexahedron(p, xyz, val, pre); break;
  case 9: addScalarPrism(p, xyz, val, pre); break;
  case 8: addScalarPyramid(p, xyz, val, pre); break;
  }
}

void addVectorElement(PView *p, int iele, int numNodes, int numEdges, 
		      double xyz[NMAX][3], double val[NMAX][9], bool pre)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  int numComp2;
  double val2[NMAX][9];
  getExternalValues(p, opt->ExternalViewIndex, iele, numNodes, 
		    3, val, numComp2, val2);

  if(opt->VectorType == PViewOptions::Displacement){
    for(int i = 0; i < numNodes; i++)
      val2[i][0] = ComputeScalarRep(numComp2, val2[i]);

    // add scalar element with correct min/max
    double min = opt->TmpMin, max = opt->TmpMax;
    opt->TmpMin = opt->ExternalMin;
    opt->TmpMax = opt->ExternalMax;
    addScalarElement(p, numEdges, xyz, val2, pre);
    opt->TmpMin = min;
    opt->TmpMax = max;

    // add point trajectories
    if(!pre && numNodes == 1 && opt->TimeStep > 0 && opt->LineWidth){
      for(int ts = 0; ts < opt->TimeStep; ts++){
	double xyz0[3], dxyz[3][2];
	for(int j = 0; j < 3; j++){
	  data->getNode(iele, 0, xyz0[0], xyz0[1], xyz0[2]);
	  data->getValue(iele, 0, j, ts, dxyz[j][0]);
	  data->getValue(iele, 0, j, ts + 1, dxyz[j][1]);
	}
	unsigned int col[2];
	double norm[2];
	for(int i = 0; i < 2; i++){
	  norm[i] = sqrt(dxyz[0][i] * dxyz[0][i] + 
			 dxyz[1][i] * dxyz[1][i] + 
			 dxyz[2][i] * dxyz[2][i]);
	  col[i] = opt->getColor(norm[i], opt->TmpMin, opt->TmpMax);
	}
	for(int j = 0; j < 3; j++){	
	  dxyz[j][0] = xyz0[j] + dxyz[j][0] * opt->DisplacementFactor;
	  dxyz[j][1] = xyz0[j] + dxyz[j][1] * opt->DisplacementFactor;
	}
	SVector3 n[2];
	getLineNormal(p, dxyz[0], dxyz[1], dxyz[2], norm, n, true);
	p->va_lines->add(dxyz[0], dxyz[1], dxyz[2], n, col, 0, false);
      }
    }
    return;
  }

  if(pre) return;

  if(opt->GlyphLocation == PViewOptions::Vertex){
    for(int i = 0; i < numNodes; i++){
      double v2 = ComputeScalarRep(numComp2, val2[i]);
      if(v2 >= opt->ExternalMin && v2 <= opt->ExternalMax){
	unsigned int color = opt->getColor(v2, opt->ExternalMin, opt->ExternalMax);
	unsigned int col[2] = {color, color};
	double dxyz[3][2];
	for(int j = 0; j < 3; j++){
	  dxyz[j][0] = xyz[i][j];
	  dxyz[j][1] = val[i][j];
	}
	p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], 0, col, 0, false);
      }
    }
  }

  if(opt->GlyphLocation == PViewOptions::COG){
    SPoint3 pc(0., 0., 0.);
    double d[3] = {0., 0., 0.};
    double d2[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};

    for(int i = 0; i < numNodes; i++){
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      for(int j = 0; j < 3; j++) d[j] += val[i][j];
      for(int j = 0; j < numComp2; j++) d2[j] += val2[i][j];
    }
    pc /= (double)numNodes;
    for(int j = 0; j < 3; j++) d[j] /= (double)numNodes;
    for(int j = 0; j < numComp2; j++) d2[j] /= (double)numNodes;

    // need tolerance since we compare computed results (the average)
    // instead of the raw data used to compute bounds
    double v2 = ComputeScalarRep(numComp2, d2);
    if(v2 >= opt->ExternalMin * (1. - 1.e-15) &&
       v2 <= opt->ExternalMax * (1. + 1.e-15)){
      unsigned int color = opt->getColor(v2, opt->ExternalMin, opt->ExternalMax);
      unsigned int col[2] = {color, color};
      double dxyz[3][2];
      for(int i = 0; i < 3; i++){
	dxyz[i][0] = pc[i];
	dxyz[i][1] = d[i];
      }
      p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], 0, col, 0, false);
    }
  }
}

void addTensorElement(PView *p, int numNodes, int numEdges, double xyz[NMAX][3],
		      double val[NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();

  if(opt->TensorType == PViewOptions::VonMises){
    for(int i = 0; i < numNodes; i++)
      val[i][0] = ComputeVonMises(val[i]);
    addScalarElement(p, numEdges, xyz, val, pre);
  }
}

bool skipElement(PView *p, int numEdges)
{
  PViewOptions *opt = p->getOptions();
  switch(numEdges){
  case 0: return !opt->DrawPoints;
  case 1: return !opt->DrawLines;
  case 3: return !opt->DrawTriangles;
  case 4: return !opt->DrawQuadrangles;
  case 6: return !opt->DrawTetrahedra;
  case 12: return !opt->DrawHexahedra;
  case 9: return !opt->DrawPrisms;
  case 8: return !opt->DrawPyramids;
  default: return true;
  }
}

void addElementsInArrays(PView *p, bool preprocessNormalsOnly)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();
  
  opt->TmpBBox.reset();

  double xyz[NMAX][3], val[NMAX][9];
  for(int i = 0; i < data->getNumElements(); i++){
    int numEdges = data->getNumEdges(i);
    if(skipElement(p, numEdges)) continue;
    int numComp = data->getNumComponents(i);
    int numNodes = data->getNumNodes(i);
    for(int j = 0; j < numNodes; j++){
      data->getNode(i, j, xyz[j][0], xyz[j][1], xyz[j][2]);
      for(int k = 0; k < numComp; k++)
	data->getValue(i, j, k, opt->TimeStep, val[j][k]);
    }
    changeCoordinates(p, i, numNodes, numEdges, numComp, xyz, val);

    for(int j = 0; j < numNodes; j++)
      opt->TmpBBox += SPoint3(xyz[j][0], xyz[j][1], xyz[j][2]);

    if(opt->ShowElement) 
      addOutlineElement(p, numEdges, xyz, preprocessNormalsOnly);

    if(opt->IntervalsType != PViewOptions::Numeric){
      if(numComp == 1 && opt->DrawScalars)
	addScalarElement(p, numEdges, xyz, val, preprocessNormalsOnly);
      else if(numComp == 3 && opt->DrawVectors)
	addVectorElement(p, i, numNodes, numEdges, xyz, val, preprocessNormalsOnly);
      else if(numComp == 9 && opt->DrawTensors)
	addTensorElement(p, numNodes, numEdges, xyz, val, preprocessNormalsOnly);
    }
  }
}

void drawArrays(PView *p, VertexArray *va, GLint type, bool useNormalArray)
{
  if(!va) return;

  PViewOptions *opt = p->getOptions();

  if(CTX.polygon_offset || opt->ShowElement)
    glEnable(GL_POLYGON_OFFSET_FILL);

  if(type == GL_POINTS && opt->PointType > 0){
    for(int i = 0; i < va->getNumVertices(); i++){
      float *p = va->getVertexArray(3 * i);
      glColor4ubv((GLubyte *)va->getColorArray(4 * i));
      double f = 1.;
      if(opt->PointType == 2){
	char *n = va->getNormalArray(3 * i);
	f = char2float(*n);
      }
      Draw_Sphere(opt->PointSize * f, p[0], p[1], p[2], opt->Light);
    }
  }
  else if(type == GL_LINES && opt->LineType > 0){
    for(int i = 0; i < va->getNumVertices(); i += 2){
      float *p0 = va->getVertexArray(3 * i);
      float *p1 = va->getVertexArray(3 * (i + 1));
      double x[2] = {p0[0], p1[0]}, y[2] = {p0[1], p1[1]}, z[2] = {p0[2], p1[2]};
      glColor4ubv((GLubyte *)va->getColorArray(4 * i));
      if(opt->LineType == 2){
	char *n0 = va->getNormalArray(3 * i);
	char *n1 = va->getNormalArray(3 * (i + 1));
	double v0 = char2float(*n0), v1 = char2float(*n1);
	Draw_TapCylinder(opt->LineWidth, v0, v1, 0., 1., x, y, z, opt->Light);
      }
      else
	Draw_Cylinder(opt->LineWidth, x, y, z, opt->Light);
    }
  }
  else{
    glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
    glNormalPointer(GL_BYTE, 0, va->getNormalArray());
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
    glEnableClientState(GL_VERTEX_ARRAY);
    if(useNormalArray){
      glEnable(GL_LIGHTING);
      glEnableClientState(GL_NORMAL_ARRAY);
    }
    else
      glDisableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(type, 0, va->getNumVertices());
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }

  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
}

void drawVectorArray(PView *p, VertexArray *va)
{
  if(!va || va->getNumVerticesPerElement() != 2) return;

  PViewOptions *opt = p->getOptions();
  
  for(int i = 0; i < va->getNumVertices(); i += 2){
    float *s = va->getVertexArray(3 * i);
    float *v = va->getVertexArray(3 * (i + 1));
    glColor4ubv((GLubyte *)va->getColorArray(4 * i));
    double max;
    if(opt->ArrowSizeProportional)
      max = opt->TmpMax;
    else
      max = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if(max){
      double scale = opt->ArrowSize / max;
      double px = v[0] * scale, py = v[1] * scale, pz = v[2] * scale;
      // only draw vectors larger than 1 pixel on screen
      if(fabs(px) > 1. || fabs(py) > 1. || fabs(pz) > 1.){
	double d = CTX.pixel_equiv_x / CTX.s[0];
	double dx = px * d, dy = py * d, dz = pz * d;
	double x = s[0], y = s[1], z = s[2];
	if(opt->CenterGlyphs){
	  x -= 0.5 * dx;
	  y -= 0.5 * dy;
	  z -= 0.5 * dz;
	}
	Draw_Vector(opt->VectorType, opt->IntervalsType != PViewOptions::Iso,
		    opt->ArrowRelHeadRadius, opt->ArrowRelStemLength,
		    opt->ArrowRelStemRadius, x, y, z, dx, dy, dz, opt->Light);
      }
    }
  }
}

std::string stringValue(int numComp, double d[9], double norm, char *format)
{
  char label[100];
  if(numComp == 1)
    sprintf(label, format, d[0]);
  else if(numComp == 3){
    char str[3][32];
    sprintf(str[0], format, d[0]);
    sprintf(str[1], format, d[1]);
    sprintf(str[2], format, d[2]);
    sprintf(label, "(%s,%s,%s)", str[0], str[1], str[2]);
  }
  else if(numComp == 9)
    sprintf(label, format, norm);
  return std::string(label);
}

void drawNumberGlyphs(PView *p, int numNodes, int numComp, 
		      double xyz[NMAX][3], double val[NMAX][9])
{
  PViewOptions *opt = p->getOptions();
  double d[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};

  double vmin = opt->TmpMin, vmax = opt->TmpMax;

  if(opt->GlyphLocation == PViewOptions::COG){
    SPoint3 pc(0., 0., 0.);
    for(int i = 0; i < numNodes; i++){
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      for(int j = 0; j < numComp; j++) d[j] += val[i][j];
    }
    pc /= (double)numNodes;
    for(int j = 0; j < numComp; j++) d[j] /= (double)numNodes;
    double v = ComputeScalarRep(numComp, d);
    if(v >= vmin && v <= vmax){
      unsigned int col = opt->getColor(v, vmin, vmax);
      glColor4ubv((GLubyte *) & col);
      glRasterPos3d(pc.x(), pc.y(), pc.z());
      char *txt = (char*)stringValue(numComp, d, v, opt->Format).c_str();
      if(opt->CenterGlyphs)
	Draw_String_Center(txt);
      else
	Draw_String(txt);
    }
  }
  else if(opt->GlyphLocation == PViewOptions::Vertex){
    for(int i = 0; i < numNodes; i++){
      double v = ComputeScalarRep(numComp, val[i]);
      if(v >= vmin && v <= vmax){
	unsigned int col = opt->getColor(v, vmin, vmax);
	glColor4ubv((GLubyte *) & col);
	glRasterPos3d(xyz[i][0], xyz[i][1], xyz[i][2]);
	char *txt = (char*)stringValue(numComp, val[i], v, opt->Format).c_str();
	if(opt->CenterGlyphs)
	  Draw_String_Center(txt);
	else
	  Draw_String(txt);
      }
    }
  }
}

void drawNormalVectorGlyphs(PView *p, int numNodes, double xyz[NMAX][3],
			    double val[NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  SPoint3 pc(0., 0., 0.);
  for(int i = 0; i < numNodes; i++)
    pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
  pc /= (double)numNodes;

  SVector3 n = normal3(xyz);
  n.normalize();
  for(int i = 0; i < 3; i++)
    n[i] *= opt->Normals * CTX.pixel_equiv_x / CTX.s[i];
  glColor4ubv((GLubyte *) & opt->color.normals);
  Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
	      CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
	      pc[0], pc[1], pc[2], n[0], n[1], n[2], opt->Light);
}

void drawTangentVectorGlyphs(PView *p, int numNodes, double xyz[NMAX][3],
			     double val[NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  SPoint3 p0(xyz[0][0], xyz[0][1], xyz[0][2]);
  SPoint3 p1(xyz[1][0], xyz[1][1], xyz[1][2]);
  SVector3 pc = 0.5 * (p0 + p1);
  SVector3 t(p0, p1);
  t.normalize();
  for(int i = 0; i < 3; i++)
    t[i] *= opt->Tangents * CTX.pixel_equiv_x / CTX.s[i];
  glColor4ubv((GLubyte *) & opt->color.tangents);
  Draw_Vector(CTX.vector_type, 0, CTX.arrow_rel_head_radius, 
	      CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius, 
	      pc[0], pc[1], pc[2], t[0], t[1], t[2], opt->Light);
}

void drawGlyphs(PView *p)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  if(!opt->Normals && !opt->Tangents && opt->IntervalsType != PViewOptions::Numeric)
    return;

  Msg(DEBUG, "drawing extra glyphs (this is slow...)");

  double xyz[NMAX][3], val[NMAX][9];

  for(int i = 0; i < data->getNumElements(); i++){
    int numEdges = data->getNumEdges(i);
    if(skipElement(p, numEdges)) continue;
    int dim = data->getDimension(i);
    int numComp = data->getNumComponents(i);
    int numNodes = data->getNumNodes(i);
    for(int j = 0; j < numNodes; j++){
      data->getNode(i, j, xyz[j][0], xyz[j][1], xyz[j][2]);
      for(int k = 0; k < numComp; k++)
	data->getValue(i, j, k, opt->TimeStep, val[j][k]);
    }
    changeCoordinates(p, i, numNodes, numEdges, numComp, xyz, val);
    if(opt->IntervalsType == PViewOptions::Numeric)
      drawNumberGlyphs(p, numNodes, numComp, xyz, val);
    if(dim == 2 && opt->Normals)
      drawNormalVectorGlyphs(p, numNodes, xyz, val);
    else if(dim == 1 && opt->Tangents)
      drawTangentVectorGlyphs(p, numNodes, xyz, val);  
  }
}

class initPView {
 private:
  // we try to estimate how many primitives will end up in the vertex
  // arrays, since reallocating the arrays takes a huge amount of time
  // on Windows/Cygwin
  int _estimateNumPoints(PView *p)
  {
    PViewData *data = p->getData();
    int heuristic = data->getNumElements(PViewData::Point);
    return heuristic + 10000;
  }
  int _estimateNumLines(PView *p)
  {
    PViewData *data = p->getData();
    int heuristic = data->getNumElements(PViewData::Line);
    return heuristic + 10000;
  }
  int _estimateNumTriangles(PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();
    int tris = data->getNumElements(PViewData::Triangle);
    int quads = data->getNumElements(PViewData::Quadrangle);
    int tets = data->getNumElements(PViewData::Tetrahedron);
    int prisms = data->getNumElements(PViewData::Prism);
    int pyrs = data->getNumElements(PViewData::Pyramid);
    int hexas = data->getNumElements(PViewData::Hexahedron);
    int heuristic = 0;
    if(opt->IntervalsType == PViewOptions::Iso)
      heuristic = (tets + prisms + pyrs + hexas) / 10;
    else if(opt->IntervalsType == PViewOptions::Continuous)
      heuristic = (tris + 2 * quads + 6 * tets + 
		   8 * prisms + 6 * pyrs + 12 * hexas);
    else if(opt->IntervalsType == PViewOptions::Discrete)
      heuristic = (tris + 2 * quads + 6 * tets + 
		   8 * prisms + 6 * pyrs + 12 * hexas) * 2;
    return heuristic + 10000;
  }
  int _estimateNumVectors(PView *p)
  {
    PViewData *data = p->getData();
    int heuristic = data->getNumVectors();
    return heuristic + 1000;
  }
 public :
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(data->getDirty() || !p->getChanged()) return;

    if(!opt->Visible || opt->Type != PViewOptions::Plot3D) return;

    if(opt->UseGenRaise) opt->createGeneralRaise();

    if(opt->RangeType == PViewOptions::Custom){
      opt->TmpMin = opt->CustomMin;
      opt->TmpMax = opt->CustomMax;
    }
    else if(opt->RangeType == PViewOptions::PerTimeStep){
      opt->TmpMin = data->getMin(opt->TimeStep);
      opt->TmpMax = data->getMax(opt->TimeStep);
    }
    else{
      opt->TmpMin = data->getMin();
      opt->TmpMax = data->getMax();
    }

    p->deleteVertexArrays();
    p->va_points = new VertexArray(1, _estimateNumPoints(p));
    p->va_lines = new VertexArray(2, _estimateNumLines(p));
    p->va_triangles = new VertexArray(3, _estimateNumTriangles(p));
    p->va_vectors = new VertexArray(2, _estimateNumVectors(p));

    if(p->normals) delete p->normals;
    p->normals = new smooth_normals(opt->AngleSmoothNormals);

    if(opt->SmoothNormals) addElementsInArrays(p, true);
    addElementsInArrays(p, false);

    p->va_points->finalize();
    p->va_lines->finalize();
    p->va_triangles->finalize();
    p->va_vectors->finalize();

    Msg(INFO, "Rendering %d vertices", p->va_points->getNumVertices() + 
	p->va_lines->getNumVertices() + p->va_triangles->getNumVertices() + 
	p->va_vectors->getNumVertices());

    p->setChanged(false);
  }
};

bool eyeChanged(PView *p)
{
  double zeye = 100 * CTX.lc;
  SPoint3 tmp(CTX.rot[2] * zeye, CTX.rot[6] * zeye, CTX.rot[10] * zeye);
  if(tmp.distance(p->getEye()) > 1.e-3){
    p->setEye(tmp);
    return true;
  }
  return false;
}

class drawPView {
 public:
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();
    
    if(!opt->Visible || opt->Type != PViewOptions::Plot3D) return;
    
    glPointSize(opt->PointSize);
    gl2psPointSize(opt->PointSize * CTX.print.eps_point_size_factor);
    
    glLineWidth(opt->LineWidth);
    gl2psLineWidth(opt->LineWidth * CTX.print.eps_line_width_factor);
    
    if(opt->LightTwoSide)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    
    for(int i = 0; i < 6; i++)
      if(CTX.clip[i] & (1 << (2 + p->getIndex()))) 
	glEnable((GLenum)(GL_CLIP_PLANE0 + i));
      else
	glDisable((GLenum)(GL_CLIP_PLANE0 + i));
    
    if(CTX.alpha && ColorTable_IsAlpha(&opt->CT)){
      if(opt->FakeTransparency){
	// simple additive blending "a la xpost":
	glBlendFunc(GL_SRC_ALPHA, GL_ONE); // glBlendEquation(GL_FUNC_ADD);
	// maximum intensity projection "a la volsuite":
	// glBlendFunc(GL_ONE, GL_ONE); // glBlendEquation(GL_MAX);
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
      }
      else{
	// real translucent blending (requires back-to-front traversal)
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glBlendEquation(GL_FUNC_ADD);
	glEnable(GL_BLEND);
	if(eyeChanged(p)){
	  Msg(DEBUG, "Sorting View[%d] for transparency", p->getIndex());
	  p->va_triangles->sort(p->getEye().x(), p->getEye().y(), p->getEye().z());
	}
      }
    }

    if(opt->RangeType == PViewOptions::Custom){
      opt->TmpMin = opt->CustomMin;
      opt->TmpMax = opt->CustomMax;
    }
    else if(opt->RangeType == PViewOptions::PerTimeStep){
      opt->TmpMin = data->getMin(opt->TimeStep);
      opt->TmpMax = data->getMax(opt->TimeStep);
    }
    else{
      opt->TmpMin = data->getMin();
      opt->TmpMax = data->getMax();
    }

    // draw all the vertex arrays
    drawArrays(p, p->va_points, GL_POINTS, false);
    drawArrays(p, p->va_lines, GL_LINES, opt->Light && opt->LightLines);
    drawArrays(p, p->va_triangles, GL_TRIANGLES, opt->Light);

    // draw the "pseudo" vertex arrays for vectors
    drawVectorArray(p, p->va_vectors);

    // to avoid looping over elements we should also store these
    // glyphs in "pseudo" vertex arrays
    drawGlyphs(p);

    // draw the 3D strings
    if(opt->DrawStrings){
      glColor4ubv((GLubyte *) & opt->color.text3d);
      for(int i = 0; i < data->getNumStrings3D(); i++){
	double x, y, z, style;
	std::string str;
	data->getString3D(i, opt->TimeStep, str, x, y, z, style);
	glRasterPos3d(x, y, z);
	Draw_String((char*)str.c_str(), style);
      }
    }
    
    if(CTX.alpha){
      glDisable(GL_BLEND);
      glEnable(GL_DEPTH_TEST);
    }

    for(int i = 0; i < 6; i++)
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));

    if(opt->Axes && opt->Type == PViewOptions::Plot3D){
      glColor4ubv((GLubyte *) & opt->color.axes);
      glLineWidth(CTX.line_width);
      gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
      if(!opt->AxesAutoPosition)
	Draw_Axes(opt->Axes, opt->AxesTics, opt->AxesFormat, opt->AxesLabel,
		  opt->AxesPosition,opt->AxesMikado);
      else if(!opt->TmpBBox.empty())
	Draw_Axes(opt->Axes, opt->AxesTics, opt->AxesFormat, opt->AxesLabel,
		  opt->TmpBBox,opt->AxesMikado);
    }
    
  }
};

class drawPViewBoundingBox {
 public :
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!opt->Visible || opt->Type != PViewOptions::Plot3D) return;

    SBoundingBox3d bb = data->getBoundingBox();
    if(bb.empty()) return;

    glColor4ubv((GLubyte *) & CTX.color.fg);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);

    Draw_Box(bb.min().x(), bb.min().y(), bb.min().z(),
	     bb.max().x(), bb.max().y(), bb.max().z());
    glColor3d(1., 0., 0.);
    for(int i = 0; i < 6; i++)
      if(CTX.clip[i] & (1 << (2 + p->getIndex())))
	Draw_PlaneInBoundingBox(bb.min().x(), bb.min().y(), bb.min().z(),
				bb.max().x(), bb.max().y(), bb.max().z(),
				CTX.clip_plane[i][0], CTX.clip_plane[i][1], 
				CTX.clip_plane[i][2], CTX.clip_plane[i][3]);
  }
};

void Draw_Post()
{
  // draw any plugin-specific stuff
  if(CTX.post.plugin_draw_function) (*CTX.post.plugin_draw_function)();

  if(PView::list.empty()) return;

  if(CTX.draw_bbox || !CTX.post.draw)
    std::for_each(PView::list.begin(), PView::list.end(), drawPViewBoundingBox());

  if(!CTX.post.draw) return;

  static bool busy = false;
  if(!busy){
    busy = true;
    std::for_each(PView::list.begin(), PView::list.end(), initPView());
    std::for_each(PView::list.begin(), PView::list.end(), drawPView());
    busy = false;
  }
}
