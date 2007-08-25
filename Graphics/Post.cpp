// $Id: Post.cpp,v 1.116 2007-08-25 22:18:05 geuzaine Exp $
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

#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "Draw.h"
#include "Iso.h"
#include "PView.h"
#include "Context.h"
#include "gl2ps.h"

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

int cutTriangle(double xyz[NMAX][3], double val[NMAX][9], double vmin, double vmax,
		int i0=0, int i1=1, int i2=2)
{
  int id[3] = {i0, i1, i2}, np;
  double x[NMAX], y[NMAX], z[NMAX], xp[NMAX], yp[NMAX], zp[NMAX], v[NMAX], vp[NMAX];
  for(int i = 0; i < 3; i++){
    x[i] = xyz[id[i]][0];
    y[i] = xyz[id[i]][1];
    z[i] = xyz[id[i]][2];
    v[i] = val[id[i]][0];
  }
  CutTriangle(x, y, z, v, vmin, vmax, xp, yp, zp, &np, vp);
  for(int i = 0; i < np; i++){
    xyz[i][0] = xp[i];
    xyz[i][1] = yp[i];
    xyz[i][2] = zp[i];
    val[i][0] = vp[i];
  }
  return np;
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

void changeCoordinates(PView *p, int nbnod, int nbcomp, 
		       double xyz[NMAX][3], double val[NMAX][9],
		       bool offset, bool raise, bool transform)
{
  PViewOptions *opt = p->getOptions();

  if(opt->Explode != 1.) {
    double barycenter[3] = {0., 0., 0.};
    for(int i = 0; i < nbnod; i++)
      for(int j = 0; j < 3; j++)
	barycenter[j] += xyz[i][j];
    for(int j = 0; j < 3; j++)
      barycenter[j] /= (double)nbnod;
    for(int i = 0; i < nbnod; i++)
      for(int j = 0; j < 3; j++)
	xyz[i][j] = barycenter[j] + opt->Explode * (xyz[i][j] - barycenter[j]);
  }
  
  if(transform){
    for(int i = 0; i < nbnod; i++) {
      double old[3] = {xyz[i][0], xyz[i][1], xyz[i][2]};
      for(int j = 0; j < 3; j++){
	xyz[i][j] = 0.;
	for(int k = 0; k < 3; k++)
	  xyz[i][j] += opt->Transform[j][k] * old[k];
      }
    }
  }
  
  if(offset){
    for(int i = 0; i < nbnod; i++)
      for(int j = 0; j < 3; j++)
	xyz[i][j] += opt->Offset[j];
  }
  
  if(raise){
    for(int i = 0; i < nbnod; i++){
      double norm = 0.;
      if(nbcomp == 1)
	norm = val[i][0];
      else if(nbcomp == 3)
	norm = sqrt(val[i][0] * val[i][0] + 
		    val[i][1] * val[i][1] + 
		    val[i][2] * val[i][2]);
      else if(nbcomp == 9)
	norm = ComputeVonMises(val[i]);
      for(int j = 0; j < 3; j++)
	xyz[i][j] += opt->Raise[j] * norm;
    }
  }

  if(opt->UseGenRaise){
    /* FIXME
    int ext_nbcomp = nbcomp;
    double *ext_vals = vals;
    if(v->ViewIndexForGenRaise >= 0)
      GetValuesFromExternalView(v, type, nbcomp, &ext_nbcomp, &ext_vals, 
				v->ViewIndexForGenRaise);
    ApplyGeneralizedRaise(v, nbnod, ext_nbcomp, ext_vals, x2, y2, z2);
    */
  }

  for(int i = 0; i < nbnod; i++)
    opt->TmpBBox += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
}

void addOutlinePoint(PView *p, double xyz[NMAX][3], unsigned int color,
		     bool pre=false, int i0=0)
{
  if(!pre)
    p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], 0, &color, 0, true);
}

void addScalarPoint(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		    bool pre=false, int i0=0, bool unique=false)
{
  if(!pre){
    PViewOptions *opt = p->getOptions();
    double vmin = opt->TmpMin, vmax = opt->TmpMax;
    unsigned int col = opt->getColor(val[i0][0], vmin, vmax);
    p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], 0, &col, 0, unique);
  }
}

void addOutlineLine(PView *p, double xyz[NMAX][3], unsigned int color,
		    bool pre=false, int i0=0, int i1=1)
{
  if(!pre){
    const int in[3] = {i0, i1};
    unsigned int col[2];
    double x[2], y[2], z[2];
    for(int i = 0; i < 2; i++){
      x[i] = xyz[in[i]][0]; y[i] = xyz[in[i]][1]; z[i] = xyz[in[i]][2]; 
      col[i] = color;
    }
    p->va_lines->add(x, y, z, 0, col, 0, true);
  }
}

void addScalarLine(PView *p, double xyz[NMAX][3], double val[NMAX][9], 
		   bool pre=false, int i0=0, int i1=1, bool unique=false)
{
}

void addOutlineTriangle(PView *p, double xyz[NMAX][3], unsigned int color,
			bool pre=false, int i0=0, int i1=1, int i2=2)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  unsigned int col[2];
  SVector3 nfac = normal3(xyz, i0, i1, i2), n[2];
  double x[2], y[2], z[2];

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      x[j] = xyz[il[i][j]][0]; y[j] = xyz[il[i][j]][1]; z[j] = xyz[il[i][j]][2]; 
      n[j] = nfac;
      if(opt->SmoothNormals){
	if(pre) p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
	else p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
      col[j] = color;
    }
    if(!pre) p->va_lines->add(x, y, z, n, col, 0, true);
  }
}

void addScalarTriangle(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		       bool pre=false, int i0=0, int i1=1, int i2=2,
		       bool unique=false)
{
  PViewOptions *opt = p->getOptions();

  const int in[3] = {i0, i1, i2};
  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 3; i++)
      addScalarLine(p, xyz, val, il[i][0], il[i][1], true);
    opt->Boundary++;
    return;
  }

  unsigned int col[3];
  SVector3 nfac = normal3(xyz, i0, i1, i2), n[3];
  double vmin = opt->TmpMin, vmax = opt->TmpMax, x[3], y[3], z[3];

  if(opt->SaturateValues) saturate(3, val, vmin, vmax, i0, i1, i2);

  if(opt->IntervalsType == PViewOptions::Continuous){
    if(val[i0][0] >= vmin && val[i0][0] <= vmax &&
       val[i1][0] >= vmin && val[i1][0] <= vmax &&
       val[i2][0] >= vmin && val[i2][0] <= vmax){
      // full triangle
      for(int i = 0; i < 3; i++){
	x[i] = xyz[in[i]][0]; y[i] = xyz[in[i]][1]; z[i] = xyz[in[i]][2]; 
	n[i] = nfac;
	if(opt->SmoothNormals){
	  if(pre) p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	  else p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	}
	col[i] = opt->getColor(val[in[i]][0], vmin, vmax);
      }
      if(!pre) p->va_triangles->add(x, y, z, n, col, 0, unique);
    }
    else{
      // draw part of the triangle between vmin and vmax
      int nb = cutTriangle(xyz, val, vmin, vmax, i0, i1, i2);
      if(nb >= 3){
	for(int j = 2; j < nb; j++){
	  int id2[3] = {0, j - 1, j};
	  for(int i = 0; i < 3; i++){
	    x[i] = xyz[id2[i]][0]; y[i] = xyz[id2[i]][1]; z[i] = xyz[id2[i]][2];
	    n[i] = nfac;
	    if(opt->SmoothNormals){
	      if(pre) p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	      else p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	    }
	    col[i] = opt->getColor(val[id2[i]][0], vmin, vmax);
	  }
	  if(!pre) p->va_triangles->add(x, y, z, n, col, 0, unique);
	}
      }
    }
  }

  if(opt->IntervalsType == PViewOptions::Discrete){
    for(int k = 0; k < opt->NbIso; k++){
      if(vmin == vmax) k = opt->NbIso / 2;
      double min = 0.;//FIXME View->GVFI(vmin, vmax, p->NbIso + 1, k);
      double max = 0.;//FIXME View->GVFI(vmin, vmax, p->NbIso + 1, k + 1);
      int nb = cutTriangle(xyz, val, min, max, i0, i1, i2);
      if(nb >= 3){
	for(int j = 2; j < nb; j++){
	  int id2[3] = {0, j - 1, j};
	  for(int i = 0; i < 3; i++){
	    x[i] = xyz[id2[i]][0]; y[i] = xyz[id2[i]][1]; z[i] = xyz[id2[i]][2];
	    n[i] = nfac;
	    if(opt->SmoothNormals){
	      if(pre) p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	      else p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	    }
	    col[i] = opt->getColor(k, opt->NbIso);
	  }
	  if(!pre) p->va_triangles->add(x, y, z, n, col, 0, col);
	}
      }
      if(vmin == vmax) break;
    }
  }
  
  if(opt->IntervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->NbIso; k++) {
      if(vmin == vmax) k = opt->NbIso / 2;
      //unsigned int col = PaletteDiscrete(View, View->NbIso, k);
      //IsoTriangle(View, X, Y, Z, Val,
      //	  View->GVFI(ValMin, ValMax, View->NbIso, k), col);
      if(vmin == vmax) break;
    }
  }
}

void addOutlineQuadrangle(PView *p, double xyz[NMAX][3], unsigned int color,
			  bool pre=false, int i0=0, int i1=1, int i2=2, int i3=3)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};

  unsigned int col[2];
  SVector3 nfac = normal3(xyz, i0, i1, i2), n[2];
  double x[2], y[2], z[2];

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
      x[j] = xyz[il[i][j]][0]; y[j] = xyz[il[i][j]][1]; z[j] = xyz[il[i][j]][2]; 
      n[j] = nfac;
      if(opt->SmoothNormals){
	if(pre) p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
	else p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
      col[j] = color;
    }
    if(!pre) p->va_lines->add(x, y, z, n, col, 0, true);
  }
}

void addScalarQuadrangle(PView *p, double xyz[NMAX][3], double val[NMAX][9],
			 bool pre=false, int i0=0, int i1=1, int i2=2, int i3=3,
			 bool unique=false)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};
  const int it[2][3] = {{i0, i1, i2}, {i0, i2, i3}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 4; i++)
      addScalarLine(p, xyz, val, il[i][0], il[i][1], true);
    opt->Boundary++;
    return;
  }
  
  for(int i = 0; i < 2; i++)
    addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], unique);
}

void addOutlineTetrahedron(PView *p, double xyz[NMAX][3], unsigned int color,
			   bool pre=false)
{
  const int it[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

void addScalarTetrahedron(PView *p, double xyz[NMAX][3], double val[NMAX][9],
			  bool pre=false, int i0=0, int i1=1, int i2=2, int i3=3)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{i0, i2, i1}, {i0, i1, i3}, {i0, i3, i2}, {i3, i1, i2}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->Boundary++;
    return;
  }

  if(opt->IntervalsType == PViewOptions::Continuous ||
     opt->IntervalsType == PViewOptions::Discrete){
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
  }  
  
  // iso XXXXXXXXXXXX
}

void addOutlineHexahedron(PView *p, double xyz[NMAX][3], unsigned int color,
			  bool pre=false)
{
  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
			{1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  for(int i = 0; i < 6; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], 
			 iq[i][2], iq[i][3]);
}

void addScalarHexahedron(PView *p, double xyz[NMAX][3], double val[NMAX][9],
			 bool pre=false)
{
  PViewOptions *opt = p->getOptions();

  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
			{1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  // 6 tet subdivision with matching edges on opposite faces
  const int it[6][4] = {{0, 1, 3, 7}, {0, 4, 1, 7}, {1, 4, 5, 7},
			{1, 2, 3, 7}, {1, 6, 2, 7}, {1, 5, 6, 7}};

  if(opt->Boundary > 0){
    opt->Boundary--;
    for(int i = 0; i < 6; i++)
      addScalarQuadrangle(p, xyz, val, iq[i][0], iq[i][1], iq[i][2], iq[i][3], true);
    opt->Boundary++;
    return;
  }
  
  for(int i = 0; i < 6; i++)
    addScalarTetrahedron(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], it[i][3]);
}

void addOutlinePrism(PView *p, double xyz[NMAX][3], unsigned int color,
		     bool pre=false)
{
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};
  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  for(int i = 0; i < 2; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
  for(int i = 0; i < 3; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3]);
}

void addScalarPrism(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		    bool pre=false)
{
}

void addOutlinePyramid(PView *p, double xyz[NMAX][3], unsigned int color,
		       bool pre=false)
{
  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
  addOutlineQuadrangle(p, xyz, color, pre, 0, 3, 2, 1);
}

void addScalarPyramid(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		      bool pre=false)
{
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

void addVectorElement(PView *p, int numEdges, double xyz[NMAX][3],
		      double val[NMAX][9], bool pre)
{
  // if(displacement) change xyz then call addScalarElement()
  // ...
}

void addTensorElement(PView *p, int numEdges, double xyz[NMAX][3],
		      double val[NMAX][9], bool pre)
{
}

void addElementsInArrays(PView *p, bool preprocessNormalsOnly=false)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();
  
  int step = opt->TimeStep;
  int pre = preprocessNormalsOnly;

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

  // do we need to apply an offset?
  bool offset = (opt->Offset[0] || opt->Offset[1] || opt->Offset[2]);

  // do we need to apply a simple raise?
  bool raise = (opt->Raise[0] || opt->Raise[1] || opt->Raise[2]);

  // do we need to apply a general transformation?
  bool transform = (opt->Transform[0][0] != 1. || opt->Transform[0][1] != 0. || 
		    opt->Transform[0][2] != 0. || opt->Transform[1][0] != 0. || 
		    opt->Transform[1][1] != 1. || opt->Transform[1][2] != 0. ||
		    opt->Transform[2][0] != 0. || opt->Transform[2][1] != 0. || 
		    opt->Transform[2][2] != 1.);

  double xyz[NMAX][3], val[NMAX][9];

  for(int i = 0; i < data->getNumElements(); i++){
    int dim = data->getDimension(i);
    int numComp = data->getNumComponents(i);
    int numNodes = data->getNumNodes(i);
    int numEdges = data->getNumEdges(i);
    for(int j = 0; j < numNodes; j++){
      data->getNode(i, j, xyz[j][0], xyz[j][1], xyz[j][2]);
      for(int k = 0; k < numComp; k++)
	data->getValue(i, j, k, step, val[j][k]);
    }
    changeCoordinates(p, numNodes, numComp, xyz, val, offset, raise, transform);
    if(opt->ShowElement) 
      addOutlineElement(p, numEdges, xyz, pre);
    if(numComp == 1)
      addScalarElement(p, numEdges, xyz, val, pre);
    else if(numComp == 3)
      addVectorElement(p, numEdges, xyz, val, pre);
    else if(numComp == 9)
      addTensorElement(p, numEdges, xyz, val, pre);
  }
}

void drawArrays(PView *p, VertexArray *va, GLint type, bool useNormalArray)
{
  if(!va) return;

  PViewOptions *opt = p->getOptions();

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

  if(CTX.polygon_offset || opt->ShowElement)
    glEnable(GL_POLYGON_OFFSET_FILL);

  printf("%d verts in varray\n", va->getNumVertices());
  glDrawArrays(type, 0, va->getNumVertices());
  
  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
  
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

// We try to estimate how many primitives will end up in the vertex
// arrays, since reallocating the arrays takes a HUGE amount of time
// on Windows/Cygwin. A better way would be to slightly redesign the
// drawing routines so we can have different pre-processing steps
// (like the one we have for smooth normals right now), in order to
// count how many primitives we will have.

static int estimateNumPoints(PView *p)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  int heuristic = data->getNumPoints();
  return heuristic + 10000;
}

static int estimateNumLines(PView *p)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  int heuristic = data->getNumLines();
  return heuristic + 10000;
}

static int estimateNumTriangles(PView *p)
{
  PViewData *data = p->getData();
  PViewOptions *opt = p->getOptions();

  int tris = data->getNumTriangles();
  int quads = data->getNumQuadrangles();
  int tets = data->getNumTetrahedra();
  int prisms = data->getNumPrisms();
  int pyrs = data->getNumPyramids();
  int hexas = data->getNumHexahedra();

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

class initArraysPView {
 public :
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!p->getChanged() || data->getDirty() || !opt->Visible) return;

    if(p->va_points) delete p->va_points;
    p->va_points = new VertexArray(1, estimateNumPoints(p));
    if(p->va_lines) delete p->va_lines;
    p->va_lines = new VertexArray(2, estimateNumLines(p));
    if(p->va_triangles) delete p->va_triangles;
    p->va_triangles = new VertexArray(3, estimateNumTriangles(p));

    if(p->normals) delete p->normals;
    p->normals = new smooth_normals(opt->AngleSmoothNormals);

    if(opt->SmoothNormals) addElementsInArrays(p, true);
    addElementsInArrays(p);

    p->setChanged(false);
  }
};

static double eyeStored[3] = { 0., 0., 0. };

bool eyeChanged()
{
  double zeye = 100 * CTX.lc;
  double tmp[3] = {CTX.rot[2] * zeye, CTX.rot[6] * zeye, CTX.rot[10] * zeye};
  if(fabs(tmp[0] - eyeStored[0]) > 1.e-3 ||
     fabs(tmp[1] - eyeStored[1]) > 1.e-3 ||
     fabs(tmp[2] - eyeStored[2]) > 1.e-3) {
    eyeStored[0] = tmp[0];
    eyeStored[1] = tmp[1];
    eyeStored[2] = tmp[2];
    Msg(DEBUG, "New eye = (%g %g %g)", tmp[0], tmp[1], tmp[2]);
    return true;
  }
  return false;
}

class drawArraysPView {
 private:
  static double _storedEye[3];
 public:
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();
    
    if(!opt->Visible) return;
    
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
    
    if(CTX.alpha && ColorTable_IsAlpha(&opt->CT) && 
       !opt->FakeTransparency && (eyeChanged() || p->getChanged())){
      Msg(DEBUG, "Sorting View[%d] for transparency", p->getIndex());
      p->va_triangles->sort(eyeStored);
    }
    
    drawArrays(p, p->va_points, GL_POINTS, false);
    drawArrays(p, p->va_lines, GL_LINES, opt->Light && opt->LightLines);
    drawArrays(p, p->va_triangles, GL_TRIANGLES, opt->Light);

    // then draw everything we cannot put in the arrays: strings,
    // vectors (for now), ...
  }
};

class drawPViewBoundingBox {
 public :
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!opt->Visible || opt->Type != PViewOptions::Plot3D) return;

    glColor4ubv((GLubyte *) & CTX.color.fg);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);

    SBoundingBox3d bb = data->getBoundingBox();
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

  if(!CTX.threads_lock){
    CTX.threads_lock = 1;
    std::for_each(PView::list.begin(), PView::list.end(), initArraysPView());
    std::for_each(PView::list.begin(), PView::list.end(), drawArraysPView());
    CTX.threads_lock = 0;
  }
}
