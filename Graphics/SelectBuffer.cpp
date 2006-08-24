// $Id: SelectBuffer.cpp,v 1.2 2006-08-24 01:14:59 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "GmshDefines.h"
#include "Draw.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "GModel.h"
#include "Melement.h"
#include "MRep.h"

extern Context_T CTX;
extern GModel *GMODEL;

class hit{
public:
  GLuint type, ient, depth, type2, ient2;
  hit(GLuint t, GLuint i, GLuint d, GLuint t2=0, GLuint i2=0) 
    : type(t), ient(i), depth(d), type2(t2), ient2(i2) {}
};

class hitDepthLessThan{
 public:
  bool operator()(const hit &h1, const hit &h2) const
  {
    return h1.depth < h2.depth;
  }
};

bool ProcessSelectionBuffer(int entityType, bool multipleSelection, 
			    bool selectMesh, int x, int y, int w, int h,
			    std::vector<GVertex*> &vertices,
			    std::vector<GEdge*> &edges,
			    std::vector<GFace*> &faces,
			    std::vector<GRegion*> &regions)
{
  vertices.clear();
  edges.clear();
  faces.clear();
  regions.clear();

  // In our case the selection buffer size is equal to between 5 and 7
  // times the maximum number of possible hits
  int size = 5 * (GMODEL->numVertex() + GMODEL->numEdge() + 
		  GMODEL->numFace() + GMODEL->numRegion()) + 1000;
  GLuint *selectionBuffer = new GLuint[size];
  glSelectBuffer(size, selectionBuffer);

  glRenderMode(GL_SELECT);
  CTX.render_mode = GMSH_SELECT;

  glInitNames();
  glPushMatrix();
  InitProjection(x, y, w, h);
  InitPosition();
  Draw_Geom();
  if(selectMesh) Draw_Mesh();
  glPopMatrix();

  GLint numhits = glRenderMode(GL_RENDER);
  CTX.render_mode = GMSH_RENDER;

  if(!numhits){ // no hits
    delete [] selectionBuffer;
    return false;
  }
  else if(numhits < 0){ // overflow
    delete [] selectionBuffer;
    Msg(WARNING, "Selection buffer size exceeded");
    return false;
  }

  std::vector<hit> hits;
  GLuint *ptr = selectionBuffer;
  for(int i = 0; i < numhits; i++) {
    // in Gmsh 'names' should always be 0, 2 or 4:
    // * names == 0 means that there is nothing on the stack
    // * if names == 2, the first name is the type of the entity 
    //   (0 for point, 1 for edge, 2 for face or 3 for volume) and
    //   the second is the entity number;
    // * if names == 4, the first name is the type of the entity,
    //   the second is the entity number, the third is the type
    //   of vertex array (2 for line, 3 for triangle, 4 for quad)
    //   and the fourth is the index of the element in the vertex
    //   array
    GLuint names = *ptr++; 
    GLuint mindepth = *ptr++;
    *ptr++; // maxdepth
    if(names == 2){
      GLuint depth = mindepth;
      GLuint type = *ptr++; 
      GLuint ient = *ptr++;
      hits.push_back(hit(type, ient, depth));
    }
    else if(names == 4){
      GLuint depth = mindepth;
      GLuint type = *ptr++; 
      GLuint ient = *ptr++;
      GLuint type2 = *ptr++; 
      GLuint ient2 = *ptr++;
      hits.push_back(hit(type, ient, depth, type2, ient2));
    }
  }

  delete [] selectionBuffer;
  
  if(!hits.size()){ // no entities
    return false;
  }

  // sort hits to get closest entities first
  std::sort(hits.begin(), hits.end(), hitDepthLessThan());

  // filter result: if entityType == ENT_NONE, return the closest
  // entity of "lowest dimension" (point < line < surface <
  // volume). Otherwise, return the closest entity of type
  // "entityType"
  GLuint typmin = 10;
  for(unsigned int i = 0; i < hits.size(); i++)
    typmin = std::min(typmin, hits[i].type);

  for(unsigned int i = 0; i < hits.size(); i++) {
    if((entityType == ENT_ALL) ||
       (entityType == ENT_NONE && hits[i].type == typmin) ||
       (entityType == ENT_POINT && hits[i].type == 0) ||
       (entityType == ENT_LINE && hits[i].type == 1) ||
       (entityType == ENT_SURFACE && hits[i].type == 2) ||
       (entityType == ENT_VOLUME && hits[i].type == 3)){
      switch (hits[i].type) {
      case 0:
	{
	  GVertex *v = GMODEL->vertexByTag(hits[i].ient);
	  if(!v){
	    Msg(GERROR, "Problem in point selection processing");
	    return false;
	  }
	  vertices.push_back(v);
	  if(!multipleSelection) return true;
	}
	break;
      case 1:
	{
	  GEdge *e = GMODEL->edgeByTag(hits[i].ient);
	  if(!e){
	    Msg(GERROR, "Problem in line selection processing");
	    return false;
	  }
	  if(hits[i].type2 && e->meshRep){
	    MElement *ele = e->meshRep->getElement(hits[i].type2, hits[i].ient2);
	    if(ele) printf("element %d\n", ele->getNum());
	  }
	  edges.push_back(e);
	  if(!multipleSelection) return true;
	}
	break;
      case 2:
	{
	  GFace *f = GMODEL->faceByTag(hits[i].ient);
	  if(!f){
	    Msg(GERROR, "Problem in surface selection processing");
	    return false;
	  }
	  if(hits[i].type2 && f->meshRep){
	    MElement *ele = f->meshRep->getElement(hits[i].type2, hits[i].ient2);
	    if(ele) printf("element %d\n", ele->getNum());
	  }
	  faces.push_back(f);
	  if(!multipleSelection) return true;
	}
	break;
      case 3:
	{
	  GRegion *r = GMODEL->regionByTag(hits[i].ient);
	  if(!r){
	    Msg(GERROR, "Problem in volume selection processing");
	    return false;
	  }
	  if(hits[i].type2 && r->meshRep){
	    MElement *ele = r->meshRep->getElement(hits[i].type2, hits[i].ient2);
	    if(ele) printf("element %d\n", ele->getNum());
	  }
	  regions.push_back(r);
	  if(!multipleSelection) return true;
	}
	break;
      }
    }
  }
  return true;
}

void HighlightEntity(GEntity *e, bool permanent)
{
  if(permanent)
    e->setSelection(1);
  else
    Msg(STATUS2N, "%s", e->getInfoString().c_str());
}

void HighlightEntity(GVertex *v, GEdge *c, GFace *s, GRegion *r, bool permanent)
{
  if(v) HighlightEntity(v, permanent);
  else if(c) HighlightEntity(c, permanent);
  else if(s) HighlightEntity(s, permanent);
  else if(r) HighlightEntity(r, permanent);
  else if(!permanent) Msg(STATUS2N, " ");
}

void HighlightEntityNum(int v, int c, int s, int r, bool permanent)
{
  if(v) {
    GVertex *pv = GMODEL->vertexByTag(v);
    if(pv) HighlightEntity(pv, permanent);
  }
  if(c) {
    GEdge *pc = GMODEL->edgeByTag(c);
    if(pc) HighlightEntity(pc, permanent);
  }
  if(s) {
    GFace *ps = GMODEL->faceByTag(s);
    if(ps) HighlightEntity(ps, permanent);
  }
  if(r) {
    GRegion *pr = GMODEL->regionByTag(r);
    if(pr) HighlightEntity(pr, permanent);
  }
}

void ZeroHighlightEntity(GEntity *e)
{
  e->setSelection(0);
}

void ZeroHighlightEntity(GVertex *v, GEdge *c, GFace *s, GRegion *r)
{
  if(v) ZeroHighlightEntity(v);
  if(c) ZeroHighlightEntity(c);
  if(s) ZeroHighlightEntity(s);
  if(r) ZeroHighlightEntity(r);
}

void ZeroHighlight()
{
  for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
    ZeroHighlightEntity(*it);
}

void ZeroHighlightEntityNum(int v, int c, int s, int r)
{
  if(v) {
    GVertex *pv = GMODEL->vertexByTag(v);
    if(pv) ZeroHighlightEntity(pv);
  }
  if(c) {
    GEdge *pc = GMODEL->edgeByTag(c);
    if(pc) ZeroHighlightEntity(pc);
  }
  if(s) {
    GFace *ps = GMODEL->faceByTag(s);
    if(ps) ZeroHighlightEntity(ps);
  }
  if(r) {
    GRegion *pr = GMODEL->regionByTag(r);
    if(pr) ZeroHighlightEntity(pr);
  }
}
