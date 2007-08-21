// $Id: Post_New.cpp,v 1.1 2007-08-21 19:05:39 geuzaine Exp $
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
#include "PView.h"
#include "Context.h"
#include "gl2ps.h"

void addElementsInArrays(PView *p)
{

}

void drawArrays(PView *p)
{
  /*
  double x[20], y[20], z[20];

  for(int i = 0; i < data->getNumElements(); i++){
    int n = data->getNumNodes(i);
    for(int j = 0; j < n; j++)
      data->getNode(i, j, x[j], y[j], z[j]);
    
    if(n == 3){
      glColor3d(1, 0, 0);
      glBegin(GL_TRIANGLES);
      glVertex3d(x[0], y[0], z[0]);
      glVertex3d(x[1], y[1], z[1]);
      glVertex3d(x[2], y[2], z[2]);
      glEnd();
    }

  }
  */

}

// We try to estimate how many primitives will end up in the vertex
// arrays, since reallocating the arrays takes a HUGE amount of time
// on Windows/Cygwin. A better way would be to slightly redesign the
// drawing routines so we can have different pre-processing steps
// (like the one we have for smooth normals right now), in order to
// count how many primitives we will have.

static int estimateNumTriangles(PView *p)
{
  PViewData *dat = p->getData();
  int tris = dat->getNumTriangles();
  int quads = dat->getNumQuadrangles();
  int tets = dat->getNumTetrahedra();
  int prisms = dat->getNumPrisms();
  int pyrs = dat->getNumPyramids();
  int hexas = dat->getNumHexahedra();

  PViewOptions *opt = p->getOptions();  
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

static int estimateNumLines(PView *p)
{
  return 10000;
}

class initPView {
 public :
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!p->getChanged() || p->getDirty() || !opt->Visible) return;

    if(p->va_lines) delete p->va_lines;
    p->va_lines = new VertexArray(2, estimateNumLines(p));
    if(p->va_triangles) delete p->va_triangles;
    p->va_lines = new VertexArray(3, estimateNumTriangles(p));

    addElementsInArrays(p);

    p->setChanged(false);
  }
};

class drawPView {
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
    
    drawArrays(p);
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

void Draw_Post_New()
{
  // draw any plugin-specific stuff
  if(CTX.post.plugin_draw_function)
    (*CTX.post.plugin_draw_function)();

  if(PView::list.empty()) return;

  if(CTX.draw_bbox || !CTX.post.draw)
    std::for_each(PView::list.begin(), PView::list.end(), drawPViewBoundingBox());

  if(!CTX.post.draw) return;

  if(!CTX.threads_lock){
    CTX.threads_lock = 1; 
    // recompute graphics data if we need to
    std::for_each(PView::list.begin(), PView::list.end(), initPView());
    std::for_each(PView::list.begin(), PView::list.end(), drawPView());
    CTX.threads_lock = 0;
  }

}
