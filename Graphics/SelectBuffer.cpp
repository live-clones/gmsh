// $Id: SelectBuffer.cpp,v 1.20 2008-02-22 21:09:00 geuzaine Exp $
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

#include "Message.h"
#include "GmshUI.h"
#include "GmshDefines.h"
#include "GModel.h"
#include "MElement.h"
#include "Draw.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "VertexArray.h"

extern Context_T CTX;

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

// returns the element at a given position in a vertex array (element
// pointers are not always stored: returning 0 is not an error)
MElement *getElement(GEntity *e, int va_type, int index)
{
  switch(va_type){
  case 2: 
    if(e->va_lines && index < e->va_lines->getNumElementPointers())
      return *e->va_lines->getElementPointerArray(index);
    break;
  case 3:
    if(e->va_triangles && index < e->va_triangles->getNumElementPointers())
      return *e->va_triangles->getElementPointerArray(index);
    break;
  }
  return 0;
}

bool ProcessSelectionBuffer(int entityType,
			    bool multipleSelection, bool meshSelection,
			    int x, int y, int w, int h,
			    std::vector<GVertex*> &vertices,
			    std::vector<GEdge*> &edges,
			    std::vector<GFace*> &faces,
			    std::vector<GRegion*> &regions,
			    std::vector<MElement*> &elements)
{
  vertices.clear();
  edges.clear();
  faces.clear();
  regions.clear();
  elements.clear();

  // In our case the selection buffer size is equal to between 5 and 7
  // times the maximum number of possible hits
  GModel *m = GModel::current();
  int eles = (meshSelection && CTX.pick_elements) ? 4 * m->getNumMeshElements() : 0;
  int size = 7 * (m->getNumVertices() + m->getNumEdges() + m->getNumFaces() + 
		  m->getNumRegions() + eles) + 1000 ;

  GLuint *selectionBuffer = new GLuint[size];
  glSelectBuffer(size, selectionBuffer);

  glRenderMode(GL_SELECT);
  CTX.render_mode = GMSH_SELECT;

  glInitNames();
  glPushMatrix();
  InitProjection(x, y, w, h);
  InitPosition();
  Draw_Geom();
  if(meshSelection) Draw_Mesh();
  glPopMatrix();

  GLint numhits = glRenderMode(GL_RENDER);
  CTX.render_mode = GMSH_RENDER;

  if(!numhits){ // no hits
    delete [] selectionBuffer;
    return false;
  }
  else if(numhits < 0){ // overflow
    delete [] selectionBuffer;
    Msg(WARNING, "Too many entities selected");
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
    *ptr++; // mindepth
    GLuint maxdepth = *ptr++;
    if(names == 2){
      GLuint depth = maxdepth;
      GLuint type = *ptr++; 
      GLuint ient = *ptr++;
      hits.push_back(hit(type, ient, depth));
    }
    else if(names == 4){
      GLuint depth = maxdepth;
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
	  GVertex *v = m->getVertexByTag(hits[i].ient);
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
	  GEdge *e = m->getEdgeByTag(hits[i].ient);
	  if(!e){
	    Msg(GERROR, "Problem in line selection processing");
	    return false;
	  }
	  if(hits[i].type2){
	    MElement *ele = getElement(e, hits[i].type2, hits[i].ient2);
	    if(ele) elements.push_back(ele);
	  }
	  edges.push_back(e);
	  if(!multipleSelection) return true;
	}
	break;
      case 2:
	{
	  GFace *f = m->getFaceByTag(hits[i].ient);
	  if(!f){
	    Msg(GERROR, "Problem in surface selection processing");
	    return false;
	  }
	  if(hits[i].type2){
	    MElement *ele = getElement(f, hits[i].type2, hits[i].ient2);
	    if(ele) elements.push_back(ele);
	  }
	  faces.push_back(f);
	  if(!multipleSelection) return true;
	}
	break;
      case 3:
	{
	  GRegion *r = m->getRegionByTag(hits[i].ient);
	  if(!r){
	    Msg(GERROR, "Problem in volume selection processing");
	    return false;
	  }
	  if(hits[i].type2){
	    MElement *ele = getElement(r, hits[i].type2, hits[i].ient2);
	    if(ele) elements.push_back(ele);
	  }
	  regions.push_back(r);
	  if(!multipleSelection) return true;
	}
	break;
      }
    }
  }

  if(vertices.size() || edges.size() || faces.size() || 
     regions.size() || elements.size()) 
    return true;
  return false;
}

void HighlightEntity(GEntity *e)
{
  e->setSelection(1);
}

void HighlightEntityNum(int v, int c, int s, int r)
{
  GModel *m = GModel::current();
  if(v) {
    GVertex *pv = m->getVertexByTag(v);
    if(pv) HighlightEntity(pv);
  }
  if(c) {
    GEdge *pc = m->getEdgeByTag(c);
    if(pc) HighlightEntity(pc);
  }
  if(s) {
    GFace *ps = m->getFaceByTag(s);
    if(ps) HighlightEntity(ps);
  }
  if(r) {
    GRegion *pr = m->getRegionByTag(r);
    if(pr) HighlightEntity(pr);
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

void ZeroHighlightEntityNum(int v, int c, int s, int r)
{
  GModel *m = GModel::current();
  if(v) {
    GVertex *pv = m->getVertexByTag(v);
    if(pv) ZeroHighlightEntity(pv);
  }
  if(c) {
    GEdge *pc = m->getEdgeByTag(c);
    if(pc) ZeroHighlightEntity(pc);
  }
  if(s) {
    GFace *ps = m->getFaceByTag(s);
    if(ps) ZeroHighlightEntity(ps);
  }
  if(r) {
    GRegion *pr = m->getRegionByTag(r);
    if(pr) ZeroHighlightEntity(pr);
  }
}

void ZeroHighlight()
{
  GModel *m = GModel::current();

  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
    ZeroHighlightEntity(*it);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
    ZeroHighlightEntity(*it);

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++){
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      if((*it)->lines[i]->getVisibility() == 2)
	(*it)->lines[i]->setVisibility(1);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      if((*it)->triangles[i]->getVisibility() == 2)
	(*it)->triangles[i]->setVisibility(1);
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      if((*it)->quadrangles[i]->getVisibility() == 2) 
	(*it)->quadrangles[i]->setVisibility(1);
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++){
    for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
      if((*it)->tetrahedra[i]->getVisibility() == 2)
	(*it)->tetrahedra[i]->setVisibility(1);
    for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
      if((*it)->hexahedra[i]->getVisibility() == 2)
	(*it)->hexahedra[i]->setVisibility(1);
    for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
      if((*it)->prisms[i]->getVisibility() == 2)
	(*it)->prisms[i]->setVisibility(1);
    for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
      if((*it)->pyramids[i]->getVisibility() == 2)
	(*it)->pyramids[i]->setVisibility(1);
  }
  
}
