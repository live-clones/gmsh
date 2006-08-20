// $Id: SecondOrder.cpp,v 1.42 2006-08-20 17:02:28 geuzaine Exp $
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

#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MElement.h"
#include "MRep.h"
#include "Message.h"
#include "OS.h"

extern GModel *GMODEL;

void getEdgeVertices(GEdge *ge, MElement *ele, std::vector<MVertex*> &ve,
		     std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		     bool linear)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      ve.push_back(edgeVertices[p]);
    }
    else{
      MVertex *v, *v0 = edge.getVertex(0), *v1 = edge.getVertex(1);
      if(linear || ge->geomType() == GEntity::DiscreteCurve){
	SPoint3 pc = edge.barycenter();
	v = new MVertex(pc.x(), pc.y(), pc.z(), ge);
      }
      else{
	double u0 = 1e6, u1 = 1e6;
	Range<double> bounds = ge->parBounds(0);
	if(ge->getBeginVertex() && ge->getBeginVertex()->mesh_vertices[0] == v0) 
	  u0 = bounds.low();
	else if(ge->getEndVertex() && ge->getEndVertex()->mesh_vertices[0] == v0) 
	  u0 = bounds.high();
	else 
	  v0->getParameter(0, u0);
	if(ge->getBeginVertex() && ge->getBeginVertex()->mesh_vertices[0] == v1) 
	  u1 = bounds.low();
	else if(ge->getEndVertex() && ge->getEndVertex()->mesh_vertices[0] == v1) 
	  u1 = bounds.high();
	else 
	  v1->getParameter(0, u1);
	if(u0 < 1e6 && u1 < 1e6){
	  double uc = 0.5 * (u0 + u1);
	  GPoint pc = ge->point(uc);
	  v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge, uc);
	}
	else{
	  // we should normally never end up here
	  SPoint3 pc = edge.barycenter();
	  v = new MVertex(pc.x(), pc.y(), pc.z(), ge);
	}
      }
      edgeVertices[p] = v;
      ge->mesh_vertices.push_back(v);
      ve.push_back(v);
    }
  }
}

void getEdgeVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &ve,
		     std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		     bool linear)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      ve.push_back(edgeVertices[p]);
    }
    else{
      MVertex *v, *v0 = edge.getVertex(0), *v1 = edge.getVertex(1);
      if(linear || gf->geomType() == GEntity::DiscreteSurface){
	SPoint3 pc = edge.barycenter();
	v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
      }
      else{
	SPoint2 p0 = gf->parFromPoint(SPoint3(v0->x(), v0->y(), v0->z()));
	SPoint2 p1 = gf->parFromPoint(SPoint3(v1->x(), v1->y(), v1->z()));
	double uc = 0.5 * (p0[0] + p1[0]);
	double vc = 0.5 * (p0[1] + p1[1]);
	GPoint pc = gf->point(uc, vc);
	v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
      }
      edgeVertices[p] = v;
      gf->mesh_vertices.push_back(v);
      ve.push_back(v);
    }
  }
}

void getEdgeVertices(GRegion *gr, MElement *ele, std::vector<MVertex*> &ve,
		     std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		     bool linear)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      ve.push_back(edgeVertices[p]);
    }
    else{
      SPoint3 pc = edge.barycenter();
      MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
      edgeVertices[p] = v;
      gr->mesh_vertices.push_back(v);
      ve.push_back(v);
    }
  }
}

void getFaceVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &vf,
		     std::map<std::vector<MVertex*>, MVertex* > &faceVertices,
		     bool linear)
{
  vf.clear();
  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);
    if(face.getNumVertices() != 4) continue;
    std::vector<MVertex*> p;
    face.getOrderedVertices(p);
    if(faceVertices.count(p)){
      vf.push_back(faceVertices[p]);
    }
    else{
      MVertex *v;
      if(linear || gf->geomType() == GEntity::DiscreteSurface){
	SPoint3 pc = face.barycenter();
	v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
      }
      else{
	SPoint2 p0 = gf->parFromPoint(SPoint3(p[0]->x(), p[0]->y(), p[0]->z()));
	SPoint2 p1 = gf->parFromPoint(SPoint3(p[1]->x(), p[1]->y(), p[1]->z()));
	SPoint2 p2 = gf->parFromPoint(SPoint3(p[2]->x(), p[2]->y(), p[2]->z()));
	SPoint2 p3 = gf->parFromPoint(SPoint3(p[3]->x(), p[3]->y(), p[3]->z()));
	double uc = 0.25 * (p0[0] + p1[0] + p2[0] + p3[0]);
	double vc = 0.25 * (p0[1] + p1[1] + p2[1] + p3[1]);
	GPoint pc = gf->point(uc, vc);
	v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
      }
      faceVertices[p] = v;
      gf->mesh_vertices.push_back(v);
      vf.push_back(v);
    }
  }
}

void getFaceVertices(GRegion *gr, MElement *ele, std::vector<MVertex*> &vf,
		     std::map<std::vector<MVertex*>, MVertex* > &faceVertices,
		     bool linear)
{
  vf.clear();
  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);
    if(face.getNumVertices() != 4) continue;
    std::vector<MVertex*> p;
    face.getOrderedVertices(p);
    if(faceVertices.count(p)){
      vf.push_back(faceVertices[p]);
    }
    else{
      SPoint3 pc = face.barycenter();
      MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
      faceVertices[p] = v;
      gr->mesh_vertices.push_back(v);
      vf.push_back(v);
    }
  }
}

void setSecondOrder(GEdge *ge,
		    std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		    bool linear)
{
  std::vector<MLine*> l2;
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MLine *l = ge->lines[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(ge, l, ve, edgeVertices, linear);
    l2.push_back(new MLine2(l->getVertex(0), l->getVertex(1), ve[0]));
    delete l;
  }
  ge->lines = l2;
  ge->meshRep->destroy();
}

void setSecondOrder(GFace *gf,
		    std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		    std::map<std::vector<MVertex*>, MVertex* > &faceVertices,
		    bool linear)
{
  std::vector<MTriangle*> t2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(gf, t, ve, edgeVertices, linear);
    t2.push_back(new MTriangle2(t->getVertex(0), t->getVertex(1), t->getVertex(2),
				ve[0], ve[1], ve[2]));
    delete t;
  }
  gf->triangles = t2;

  std::vector<MQuadrangle*> q2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gf, q, ve, edgeVertices, linear);
    getFaceVertices(gf, q, vf, faceVertices, linear);
    q2.push_back(new MQuadrangle2(q->getVertex(0), q->getVertex(1), q->getVertex(2),
				  q->getVertex(3), ve[0], ve[1], ve[2], ve[3], vf[0]));
    delete q;
  }
  gf->quadrangles = q2;
  
  gf->meshRep->destroy();
}

void setSecondOrder(GRegion *gr,
		    std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		    std::map<std::vector<MVertex*>, MVertex* > &faceVertices,
		    bool linear)
{
  std::vector<MTetrahedron*> t2;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTetrahedron *t = gr->tetrahedra[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(gr, t, ve, edgeVertices, linear);
    t2.push_back(new MTetrahedron2(t->getVertex(0), t->getVertex(1), t->getVertex(2), 
				   t->getVertex(3), 
				   ve[0], ve[1], ve[2], ve[3], ve[4], ve[5]));
    delete t;
  }
  gr->tetrahedra = t2;

  // hexa prisms pyr

  gr->meshRep->destroy();
}

// Main routines

void Degre1()
{
  // loop on all elements 
  // - if polynomialOrder() == 2
  // - get their edge/face/volume vertices mark them with setVisibility(-1);
  // - generate a first order element for each element
  // - swap lists at the end
  // loop on all vertices and delete all vertices marked (-1)
}

void Degre2(int dim)
{
  Msg(STATUS1, "Mesh second order...");
  double t1 = Cpu();

  bool linear = true;
  //bool linear = false;
  std::map<std::pair<MVertex*,MVertex*>, MVertex* > edgeVertices;
  std::map<std::vector<MVertex*>, MVertex* > faceVertices;

  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); ++it)
    setSecondOrder(*it, edgeVertices, linear);
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); ++it)
    setSecondOrder(*it, edgeVertices, faceVertices, linear);
  for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); ++it)
    setSecondOrder(*it, edgeVertices, faceVertices, linear);

  double t2 = Cpu();
  Msg(STATUS1, "Mesh second order complete (%g s)", t2 - t1);
}
