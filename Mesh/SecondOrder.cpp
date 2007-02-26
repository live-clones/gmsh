// $Id: SecondOrder.cpp,v 1.53 2007-02-26 08:25:39 geuzaine Exp $
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

#include "SecondOrder.h"
#include "MElement.h"
#include "MRep.h"
#include "Message.h"
#include "OS.h"

bool reparamOnFace(MVertex *v, GFace *gf, SPoint2 &param)
{
  if(v->onWhat()->dim() == 0){
    GVertex *gv = (GVertex*)v->onWhat();

    // abort if we could be on a seam
    std::list<GEdge*> ed = gv->edges();
    for(std::list<GEdge*>::iterator it = ed.begin(); it != ed.end(); it++)
      if((*it)->isSeam(gf)) return false;

    param = gv->reparamOnFace(gf, 1);
  }
  else if(v->onWhat()->dim() == 1){
    GEdge *ge = (GEdge*)v->onWhat();

    // abort if we are on a seam (todo: try dir=-1 and compare)
    if(ge->isSeam(gf)) return false;

    double UU;
    v->getParameter(0, UU);
    param = ge->reparamOnFace(gf, UU, 1);
  }
  else{
    double UU, VV;
    if(v->onWhat() == gf && v->getParameter(0, UU) && v->getParameter(1, VV))
      param = SPoint2(UU, VV);
    else
      param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
  }
  return true;
}

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
	double uc = 0.5 * (u0 + u1);
	if(u0 < 1e6 && u1 < 1e6 && uc > u0 && uc < u1){
	  GPoint pc = ge->point(uc);
	  v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge, uc);
	}
	else{
	  // normally never here, but we don't treat periodic curves
	  // properly, so we can get uc < u0 or uc > u1...
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
	SPoint2 p0, p1;
	if(reparamOnFace(v0, gf, p0) && reparamOnFace(v1, gf, p1)){
	  double uc = 0.5 * (p0[0] + p1[0]);
	  double vc = 0.5 * (p0[1] + p1[1]);
	  GPoint pc = gf->point(uc, vc);
	  v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
	}
	else{
	  // need to treat seams correctly!
	  SPoint3 pc = edge.barycenter();
	  v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
	}
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
	SPoint2 p0, p1, p2, p3;
	if(reparamOnFace(p[0], gf, p0) && reparamOnFace(p[1], gf, p1) &&
	   reparamOnFace(p[2], gf, p2) && reparamOnFace(p[3], gf, p3)){
	  double uc = 0.25 * (p0[0] + p1[0] + p2[0] + p3[0]);
	  double vc = 0.25 * (p0[1] + p1[1] + p2[1] + p3[1]);
	  GPoint pc = gf->point(uc, vc);
	  v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
	}
	else{
	  // need to treat seams correctly!
	  SPoint3 pc = face.barycenter();
	  v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
	}
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
  std::vector<MLine*> lines2;
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MLine *l = ge->lines[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(ge, l, ve, edgeVertices, linear);
    lines2.push_back(new MLine3(l->getVertex(0), l->getVertex(1), ve[0]));
    delete l;
  }
  ge->lines = lines2;

  if(ge->meshRep) ge->meshRep->destroy();
}

void setSecondOrder(GFace *gf,
		    std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		    std::map<std::vector<MVertex*>, MVertex* > &faceVertices,
		    bool linear, bool incomplete)
{
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(gf, t, ve, edgeVertices, linear);
    triangles2.push_back
      (new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
		      ve[0], ve[1], ve[2]));
    delete t;
  }
  gf->triangles = triangles2;

  std::vector<MQuadrangle*> quadrangles2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gf, q, ve, edgeVertices, linear);
    if(incomplete){
      quadrangles2.push_back
	(new MQuadrangle8(q->getVertex(0), q->getVertex(1), q->getVertex(2),
			  q->getVertex(3), ve[0], ve[1], ve[2], ve[3]));
    }
    else{
      getFaceVertices(gf, q, vf, faceVertices, linear);
      quadrangles2.push_back
	(new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
			  q->getVertex(3), ve[0], ve[1], ve[2], ve[3], vf[0]));
    }
    delete q;
  }
  gf->quadrangles = quadrangles2;
  
  if(gf->meshRep) gf->meshRep->destroy();
}

void setSecondOrder(GRegion *gr,
		    std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edgeVertices,
		    std::map<std::vector<MVertex*>, MVertex* > &faceVertices,
		    bool linear, bool incomplete)
{
  std::vector<MTetrahedron*> tetrahedra2;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTetrahedron *t = gr->tetrahedra[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(gr, t, ve, edgeVertices, linear);
    tetrahedra2.push_back
      (new MTetrahedron10(t->getVertex(0), t->getVertex(1), t->getVertex(2), 
			  t->getVertex(3), ve[0], ve[1], ve[2], ve[3], ve[4], ve[5]));
    delete t;
  }
  gr->tetrahedra = tetrahedra2;

  std::vector<MHexahedron*> hexahedra2;
  for(unsigned int i = 0; i < gr->hexahedra.size(); i++){
    MHexahedron *h = gr->hexahedra[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gr, h, ve, edgeVertices, linear);
    if(incomplete){
      hexahedra2.push_back
	(new MHexahedron20(h->getVertex(0), h->getVertex(1), h->getVertex(2), 
			   h->getVertex(3), h->getVertex(4), h->getVertex(5), 
			   h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2], 
			   ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10], 
			   ve[11]));
    }
    else{
      getFaceVertices(gr, h, vf, faceVertices, linear);
      SPoint3 pc = h->barycenter();
      MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
      gr->mesh_vertices.push_back(v);
      hexahedra2.push_back
	(new MHexahedron27(h->getVertex(0), h->getVertex(1), h->getVertex(2), 
			   h->getVertex(3), h->getVertex(4), h->getVertex(5), 
			   h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2], 
			   ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10], 
			   ve[11], vf[0], vf[1], vf[2], vf[3], vf[4], vf[5], v));
    }
    delete h;
  }
  gr->hexahedra = hexahedra2;

  std::vector<MPrism*> prisms2;
  for(unsigned int i = 0; i < gr->prisms.size(); i++){
    MPrism *p = gr->prisms[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gr, p, ve, edgeVertices, linear);
    if(incomplete){
      prisms2.push_back
	(new MPrism15(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
		      p->getVertex(3), p->getVertex(4), p->getVertex(5), 
		      ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8]));
    }
    else{
      getFaceVertices(gr, p, vf, faceVertices, linear);
      prisms2.push_back
	(new MPrism18(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
		      p->getVertex(3), p->getVertex(4), p->getVertex(5), 
		      ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8],
		      vf[0], vf[1], vf[2]));
    }
    delete p;
  }
  gr->prisms = prisms2;

  std::vector<MPyramid*> pyramids2;
  for(unsigned int i = 0; i < gr->pyramids.size(); i++){
    MPyramid *p = gr->pyramids[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gr, p, ve, edgeVertices, linear);
    if(incomplete){
      pyramids2.push_back
	(new MPyramid13(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
			p->getVertex(3), p->getVertex(4), ve[0], ve[1], ve[2], 
			ve[3], ve[4], ve[5], ve[6], ve[7]));
    }
    else{
      getFaceVertices(gr, p, vf, faceVertices, linear);
      pyramids2.push_back
	(new MPyramid14(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
			p->getVertex(3), p->getVertex(4), ve[0], ve[1], ve[2], 
			ve[3], ve[4], ve[5], ve[6], ve[7], vf[0]));
    }
    delete p;
  }
  gr->pyramids = pyramids2;

  if(gr->meshRep) gr->meshRep->destroy();
}

template<class T>
void setFirstOrder(GEntity *e, std::vector<T*> &elements)
{
  std::vector<T*> elements1;
  for(unsigned int i = 0; i < elements.size(); i++){
    T *ele = elements[i];
    int n = ele->getNumPrimaryVertices();
    std::vector<MVertex*> v1;
    for(int j = 0; j < n; j++)
      v1.push_back(ele->getVertex(j));
    for(int j = n; j < ele->getNumVertices(); j++)
      ele->getVertex(j)->setVisibility(-1);
    elements1.push_back(new T(v1));
    delete ele;
  }
  elements = elements1;
  
  if(e->meshRep) e->meshRep->destroy();
}

void removeSecondOrderVertices(GEntity *e)
{
  std::vector<MVertex*> v1;
  for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
    if(e->mesh_vertices[i]->getVisibility() < 0)
      delete e->mesh_vertices[i];
    else
      v1.push_back(e->mesh_vertices[i]);
  }
  e->mesh_vertices = v1;
}

void Degre1(GModel *m)
{
  // replace all elements with first order elements and mark all
  // unused vertices with a -1 visibility flag
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    setFirstOrder(*it, (*it)->lines);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    setFirstOrder(*it, (*it)->triangles);
    setFirstOrder(*it, (*it)->quadrangles);
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    setFirstOrder(*it, (*it)->tetrahedra);
    setFirstOrder(*it, (*it)->hexahedra);
    setFirstOrder(*it, (*it)->prisms);
    setFirstOrder(*it, (*it)->pyramids);
  }

  // remove all vertices with a -1 visibility flag
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    removeSecondOrderVertices(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    removeSecondOrderVertices(*it);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    removeSecondOrderVertices(*it);
}

void Degre2(GModel *m, bool linear, bool incomplete)
{
  // replace all the elements in the mesh with second order elements
  // by creating unique vertices on the edges/faces of the mesh:
  //
  // - if linear is set to true, new vertices are created by linear
  //   interpolation between existing ones. If not, new vertices are
  //   created on the exact geometry, provided that the geometrical
  //   edges/faces are discretized with 1D/2D elements. (I.e., if
  //   there are only 3D elements in the mesh then any new vertices on
  //   the boundary will always be created by linear interpolation,
  //   whether linear is set or not.)
  //
  // - if incomplete is set to true, we only create new vertices on 
  //   edges (creating 8-node quads, 20-node hexas, etc., instead of
  //   9-node quads, 27-node hexas, etc.)

  Msg(STATUS1, "Meshing second order...");
  double t1 = Cpu();

  // first, make sure to remove any existsing second order vertices/elements
  Degre1(m);

  // then create new second order vertices/elements
  std::map<std::pair<MVertex*,MVertex*>, MVertex* > edgeVertices;
  std::map<std::vector<MVertex*>, MVertex* > faceVertices;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    setSecondOrder(*it, edgeVertices, linear);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    setSecondOrder(*it, edgeVertices, faceVertices, linear, incomplete);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    setSecondOrder(*it, edgeVertices, faceVertices, linear, incomplete);

  double t2 = Cpu();
  Msg(INFO, "Mesh second order complete (%g s)", t2 - t1);
  Msg(STATUS1, "Mesh");
}
