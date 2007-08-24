// $Id: Post.cpp,v 1.114 2007-08-24 20:14:18 geuzaine Exp $
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

void addScalarPoint(PView *p, double xyz[NMAX][3], double val[NMAX][9])
{
}

void addScalarLine(PView *p, double xyz[NMAX][3], double val[NMAX][9], 
		   int i0=0, int i1=1)
{
  // line is from xyz[i0][] to xyz[i1][]
}

void addScalarTriangle(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		       bool pre=false, int i0=0, int i1=1, int i2=2, bool unique=false)
{
  PViewOptions *opt = p->getOptions();

  if(!pre && opt->Boundary > 0){
    opt->Boundary--;
    addScalarLine(p, xyz, val, 0, 1);
    addScalarLine(p, xyz, val, 1, 2);
    addScalarLine(p, xyz, val, 2, 0);
    opt->Boundary++;
    return;
  }

  int id[3] = {i0, i1, i2};
  unsigned int col[3];
  SVector3 ntri = normal3(xyz), n[3];
  double vmin = opt->TmpMin, vmax = opt->TmpMax, x[3], y[3], z[3];

  if(opt->SaturateValues) saturate(3, val, vmin, vmax, i0, i1, i2);

  if(opt->IntervalsType == PViewOptions::Continuous){
    if(val[i0][0] >= vmin && val[i0][0] <= vmax &&
       val[i1][0] >= vmin && val[i1][0] <= vmax &&
       val[i2][0] >= vmin && val[i2][0] <= vmax){
      // full triangle
      for(int i = 0; i < 3; i++){
	x[i] = xyz[id[i]][0]; y[i] = xyz[id[i]][1]; z[i] = xyz[id[i]][2]; 
	n[i] = ntri;
	if(opt->SmoothNormals){
	  if(pre) p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	  else p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
	}
	col[i] = opt->getColor(val[id[i]][0], vmin, vmax);
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
	    n[i] = ntri;
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
      unsigned int col = opt->getColor(k, opt->NbIso);
      double min = 0.;//FIXME View->GVFI(vmin, vmax, p->NbIso + 1, k);
      double max = 0.;//FIXME View->GVFI(vmin, vmax, p->NbIso + 1, k + 1);
      int nb = cutTriangle(xyz, val, min, max, i0, i1, i2);
      if(nb >= 3){
	for(int j = 2; j < nb; j++){
	  int id2[3] = {0, j - 1, j};
	  for(int i = 0; i < 3; i++){
	    double x = xyz[id2[i]][0], y = xyz[id2[i]][1], z = xyz[id2[i]][2];
	    SVector3 n = ntri;
	    if(opt->SmoothNormals){
	      if(pre) p->normals->add(x, y, z, n[0], n[1], n[2]);
	      else p->normals->get(x, y, z, n[0], n[1], n[2]);
	    }
	    if(!pre)
	      p->va_triangles->add(x, y, z, n[0], n[1], n[2], col);
	  }
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

void addScalarQuadrangle(PView *p, double xyz[NMAX][3], double val[NMAX][9],
			 bool pre=false, int i0=0, int i1=1, int i2=2, int i3=3)
{
}

void addScalarTetrahedron(PView *p, double xyz[NMAX][3], double val[NMAX][9],
			  bool pre=false)
{
}

void addScalarHexahedron(PView *p, double xyz[NMAX][3], double val[NMAX][9],
			 bool pre=false)
{
}

void addScalarPrism(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		    bool pre=false)
{
}

void addScalarPyramid(PView *p, double xyz[NMAX][3], double val[NMAX][9],
		      bool pre=false)
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

  double xyz[NMAX][3], val[NMAX][9];

  for(int i = 0; i < data->getNumElements(); i++){
    int numcomp = data->getNumComponents(i);
    int dim = data->getDimension(i);
    int n = data->getNumNodes(i);
    for(int j = 0; j < n; j++){
      data->getNode(i, j, xyz[j][0], xyz[j][1], xyz[j][2]);
      for(int k = 0; k < numcomp; k++)
	data->getValue(i, j, k, step, val[j][k]);
    }
    if(numcomp == 1){
      switch(dim){
      case 0: addScalarPoint(p, xyz, val); break;
      case 1: addScalarLine(p, xyz, val); break;
      case 2: 
	if(n == 3) addScalarTriangle(p, xyz, val, pre);
	else addScalarQuadrangle(p, xyz, val, pre);
	break;
      case 3:
	if(n == 4) addScalarTetrahedron(p, xyz, val, pre);
	else if(n == 8) addScalarHexahedron(p, xyz, val, pre);
	else if(n == 6) addScalarPrism(p, xyz, val, pre);
	else if(n == 5) addScalarPyramid(p, xyz, val, pre);
	break;
      }
    }
  }
}

void drawArrays(PView *p, VertexArray *va, GLint type)
{
  if(!va) return;

  bool useNormalArray = true;

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
  
  //glEnable(GL_POLYGON_OFFSET_FILL);
  //if(drawOutline) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  
  glDrawArrays(type, 0, va->getNumVertices());
  
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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

    if(opt->SmoothNormals) addElementsInArrays(p, true);
    addElementsInArrays(p);

    p->setChanged(false);
  }
};

class drawArraysPView {
 public :
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
    
    drawArrays(p, p->va_points, GL_POINTS);
    drawArrays(p, p->va_lines, GL_LINES);
    drawArrays(p, p->va_triangles, GL_TRIANGLES);

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
