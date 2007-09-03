// $Id: HighOrder.cpp,v 1.14 2007-09-03 20:09:14 geuzaine Exp $
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

#include "HighOrder.h"
#include "MElement.h"
#include "MRep.h"
#include "Message.h"
#include "OS.h"

void computeMidPoints(const double *p1,
		      const double *p2, 
		      const double *t1, 
		      const double *t2, 
		      double *p3){
	// computes the mid point p3 of the second order parametric polynomial curve according to extreme points p1,p2 and tangents t1,t2
	// The tangent directions given in t1 and t2 are the outgoing normals !!! to the curve p1-p2
	double x0 = p1[0];
	double y0 = p1[1];
	double x1 = p2[0];
	double y1 = p2[1];
	double t0x = -t1[0];
	double t0y = -t1[1];
	double t1x = t2[0];
	double t1y = t2[1];

	//computation of the rotation parameters
	double delta_x = x1-x0;
	double delta_y = y1-y0;
	double L = sqrt(delta_x*delta_x+delta_y*delta_y);
	double theta = atan2(delta_y,delta_x);
	//	double theta = atan(delta_y/delta_x);
	//	if (delta_x<0)
	//	  theta += M_PI;
	double costheta = cos(theta);
	double sintheta = sin(theta);
	double theta0 = atan2(t0y,t0x)-theta;
	double theta1 = atan2(t1y,t1x)-theta;
	double tan0 = tan(theta0);
	double tan1 = tan(theta1);
	delta_x = L;
	delta_y = 0;


	//	printf("theta0 = %g theta1 = %g\n",theta0,theta1);

	// computes the 6 coefficients: solving the linear system
	// x(t) = a1 t^2 * b1 t + c1
	// y(t) = a2 t^2 * b2 t + c2
	// for t in [0,1]
	// with :
	// x(t), y(t) on pts 0 and 1 (4 conditions)
	// and dy/dx = dy/dt*dt/dx on those 2 pts (2 conditions)

	if (tan0 == tan1)
	  {
	    p3[0] = 0.5 * (p1[0]+p2[0]);
	    p3[1] = 0.5 * (p1[1]+p2[1]);
	  }
	else
	  {
	    double b1 = 2*(delta_y-delta_x*tan1)/(tan0-tan1);
	    double a1 = delta_x-b1;
	    double b2 = tan0 * b1;
	    double a2 = delta_y - b2;
	    double c1 = 0;// in general : x0... 
	    double c2 = 0;// in general : y0... but axis have changed...
	    
	    // back to the initial axis
	    double ax = costheta*a1 - sintheta*a2;
	    double bx = costheta*b1 - sintheta*b2;
	    double cx = x0;//costheta*c1 - sintheta*c2 + x0;
	    double ay = sintheta*a1 + costheta*a2;
	    double by = sintheta*b1 + costheta*b2;
	    double cy = y0;//sintheta*c1 + costheta*c2 + y0;
	    
	    // computes the mid point (x,y)
	    double t=0.5;
	    double tsquare=t*t;
	    p3[0] = ax*tsquare + bx*t + cx;
	    p3[1] = ay*tsquare + by*t + cy;
	  }
	return;
}

void Hermite2D_C1(SPoint3 &p1, SPoint3 &p2, SPoint3 &t1, SPoint3 &t2,
		  SPoint3 &one_third, SPoint3 &two_third)
{
   double L = sqrt((p1.x()-p2.x())*(p1.x()-p2.x()) + (p1.y()-p2.y()) * (p1.y()-p2.y()));
   SVector3 p1p2 (p2,p1);
   double theta  = atan2(p2.x()-p1.x(),p2.y()-p1.y());
   double theta1 = atan2(t1.x(),t1.y());
   double theta2 = atan2(t2.x(),t2.y());
   double rot[2][2] =
     {{cos(theta),-sin(theta)},
      {sin(theta),cos(theta)}};

   double ts[2] = {1./3.,2./3.};
   SPoint3 *pt[2] = {&one_third,&two_third};
   for (int i=0 ; i < 2; i++){
     const double t = ts[i];
     double H2 = L*t*(t-1)*(t-1);
     double H4 = -L*(1-t)*t*t;
     double x3 = t * L;
     double y3 = H2 * theta1 + H4 * theta2;     
     //     pt[i]->x() = p1.x() + x3 * rot[0][0] + y3 * rot[0][1]; 
     //     pt[i]->y() = p1.y() + x3 * rot[1][0] + y3 * rot[1][1]; 
   }

   

  // SVector3 tt1  (t1.x(),t1.y(),0);
  // SVector3 tt2  (t2.x(),t2.y(),0);
  // const double cost1 = p1p2 * tt1;
  // const double cost2 = p1p2 * tt2;
  // const double ts[2] = { 1./3.,2./3.};
  // for (int i=0 ; i < 2; i++){
  //   const double t = ts[i];
  //   const double H1 = (2*t+1)*(t-1)*(t-1);
  //   const double H2 = L*t*(t-1)*(t-1);
  //   const double H3 = t*t*(-2*t+3);
  //   const double H4 = -L*(1-t)*t*t;
  //   if (i == 0)one_third = p1*H1 + t1*H2 + p2*H3 + t2*H4;
  //   else two_third = p1*H1 + t1*H2 + p2*H3 + t2*H4;
  // }  
}

// for each pair of vertices (an edge), we build a list of vertices
// that are the high order representation of the edge. The ordering of
// vertices in the list is supposed to be (by construction) consistent
// with the ordering of the pair.
typedef std::map<std::pair<MVertex*,MVertex*>, std::vector<MVertex*> > edgeContainer;

// for each face (a list of vertices) we build a list of vertices that
// are the high order representation of the face
typedef std::map<std::vector<MVertex*>, std::vector<MVertex*> > faceContainer;

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

bool reparamOnEdge(MVertex *v, GEdge *ge, double &param)
{
  param = 1.e6;
  Range<double> bounds = ge->parBounds(0);
  if(ge->getBeginVertex() && ge->getBeginVertex()->mesh_vertices[0] == v) 
    param = bounds.low();
  else if(ge->getEndVertex() && ge->getEndVertex()->mesh_vertices[0] == v) 
    param = bounds.high();
  else 
    v->getParameter(0, param);

  if(param < 1.e6) return true;
  return false;
}

void getEdgeVertices(GEdge *ge, MElement *ele, std::vector<MVertex*> &ve,
		     edgeContainer &edgeVertices, bool linear, int nPts = 1)
{
  bool c1 = CTX.mesh.c1_continuity;

  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      if(edge.getVertex(0) == edge.getMinVertex())
	ve.insert(ve.end(), edgeVertices[p].begin(), edgeVertices[p].end());
      else
	ve.insert(ve.end(), edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else{
      MVertex *v0 = edge.getVertex(0), *v1 = edge.getVertex(1);            
      double u0 = 0., u1 = 0.;
      bool reparamOK = true;
      if(c1 || (!linear && 
		ge->geomType() != GEntity::DiscreteCurve &&
		ge->geomType() != GEntity::BoundaryLayerCurve)){
	reparamOK &= reparamOnEdge(v0, ge, u0);
	reparamOK &= reparamOnEdge(v1, ge, u1);
      }
      if(nPts == 1 && c1){
	SVector3 tv1 = ge->firstDer(u0);
	SVector3 tv2 = ge->firstDer(u1);
	double  t1[2] = {-tv1.x(),-tv1.y()};
	double  t2[2] = { tv2.x(), tv2.y()};	
	double  p1[2] = { v0->x(), v0->y()};
	double  p2[2] = { v1->x(), v1->y()};
	double  p3[2];
	computeMidPoints(p1,p2,t1,t2,p3);
	MVertex *hv = new MVertex(p3[0],p3[1],0);
	ge->mesh_vertices.push_back(hv);
	ve.push_back(hv);
	edgeVertices[p].push_back(hv);
      }
      else{
	std::vector<MVertex*> temp;
	for(int j = 0; j < nPts; j++){
	  const double t = (double)(j + 1)/(nPts + 1);
	  double uc = (1. - t) * u0 + t * u1;
	  MVertex *v;
	  if(!reparamOK || linear || ge->geomType() == GEntity::DiscreteCurve || 
	     uc < u0 || uc > u1){ // need to treat periodic curves properly!
	    SPoint3 pc = edge.interpolate(t);
	    v = new MVertex(pc.x(), pc.y(), pc.z(), ge);
	  }
	  else {
	    GPoint pc = ge->point(uc);
	    v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge, uc);
	  }
	  temp.push_back(v);
	  ge->mesh_vertices.push_back(v);
	  ve.push_back(v);
	}
	if(edge.getVertex(0) == edge.getMinVertex())
	  edgeVertices[p].insert(edgeVertices[p].end(), temp.begin(), temp.end());
	else
	  edgeVertices[p].insert(edgeVertices[p].end(), temp.rbegin(), temp.rend());
      }
    }
  }
}

void getEdgeVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &ve,
		     edgeContainer &edgeVertices, bool linear, int nPts = 1)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);    
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      if(edge.getVertex(0) == edge.getMinVertex())
	ve.insert(ve.end(), edgeVertices[p].begin(), edgeVertices[p].end());
      else
	ve.insert(ve.end(), edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else{
      MVertex *v0 = edge.getVertex(0), *v1 = edge.getVertex(1);
      SPoint2 p0, p1;
      bool reparamOK = true;
      if(!linear && 
	 gf->geomType() != GEntity::DiscreteSurface &&
	 gf->geomType() != GEntity::BoundaryLayerSurface){
	reparamOK &= reparamOnFace(v0, gf, p0);
	reparamOK &= reparamOnFace(v1, gf, p1);
      }
      std::vector<MVertex*> temp;
      for(int j = 0; j < nPts; j++){
	const double t = (double)(j + 1) / (nPts + 1);
	MVertex *v;
	if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
	  SPoint3 pc = edge.interpolate(t);
	  v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
	}
	else{
	  double uc = (1. - t) * p0[0] + t * p1[0];
	  double vc = (1. - t) * p0[1] + t * p1[1];
	  GPoint pc = gf->point(uc, vc);
	  v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
	}
	temp.push_back(v);
	gf->mesh_vertices.push_back(v);
	ve.push_back(v);
      }
      if(edge.getVertex(0) == edge.getMinVertex())
	edgeVertices[p].insert(edgeVertices[p].end(), temp.begin(), temp.end());
      else
	edgeVertices[p].insert(edgeVertices[p].end(), temp.rbegin(), temp.rend());
    }
  }
}

void getEdgeVertices(GRegion *gr, MElement *ele, std::vector<MVertex*> &ve,
		     edgeContainer &edgeVertices, bool linear, int nPts = 1)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      if(edge.getVertex(0) == edge.getMinVertex())
	ve.insert(ve.end(), edgeVertices[p].begin(), edgeVertices[p].end());
      else
	ve.insert(ve.end(), edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else{
      std::vector<MVertex*> temp;
      for(int j = 0; j < nPts; j++){
	double t = (double)(j + 1) / (nPts + 1);
	SPoint3 pc = edge.interpolate(t);
	MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
	temp.push_back(v);
	gr->mesh_vertices.push_back(v);
	ve.push_back(v);
      }
      if(edge.getVertex(0) == edge.getMinVertex())
	edgeVertices[p].insert(edgeVertices[p].end(), temp.begin(), temp.end());
      else
	edgeVertices[p].insert(edgeVertices[p].end(), temp.rbegin(), temp.rend());
    }
  }
}

void getFaceVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &vf,
		     faceContainer &faceVertices, bool linear, int nPts = 1)
{
  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);
    std::vector<MVertex*> p;
    face.getOrderedVertices(p);
    if(faceVertices.count(p)){
      vf.insert(vf.end(), faceVertices[p].begin(), faceVertices[p].end());
    }
    else{
      SPoint2 p0, p1, p2, p3;
      bool reparamOK = true;
      if(!linear && 
	 gf->geomType() != GEntity::DiscreteSurface &&
	 gf->geomType() != GEntity::BoundaryLayerSurface){
	reparamOK &= reparamOnFace(p[0], gf, p0);
	reparamOK &= reparamOnFace(p[1], gf, p1);
	reparamOK &= reparamOnFace(p[2], gf, p2);
	if(face.getNumVertices() == 4)
	  reparamOK &= reparamOnFace(p[3], gf, p3);
      }
      if(face.getNumVertices() == 3){ // triangles
	for(int j = 0; j < nPts; j++){
	  for(int k = 0 ; k < nPts - j - 1; k++){
	    MVertex *v;
	    double t1 = (double)(j + 1) / (nPts + 1);
	    double t2 = (double)(k + 1) / (nPts + 1);
	    if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
	      SPoint3 pc = face.interpolate(t1, t2);
	      v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
	    }
	    else{
	      double uc = (1. - t1 - t2) * p0[0] + t1 * p1[0] + t2 * p2[0];
	      double vc = (1. - t1 - t2) * p0[1] + t1 * p1[1] + t2 * p2[1];
	      GPoint pc = gf->point(uc, vc);
	      v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
	    }
	    faceVertices[p].push_back(v);
	    gf->mesh_vertices.push_back(v);
	    vf.push_back(v);
	  }
	}
      }
      else if(face.getNumVertices() == 4){ // quadrangles
	for(int j = 0; j < nPts; j++){
	  for(int k = 0; k < nPts; k++){
	    MVertex *v;
	    // parameters are between -1 and 1
	    double t1 = 2. * (double)(j + 1) / (nPts + 1) - 1.;
	    double t2 = 2. * (double)(k + 1) / (nPts + 1) - 1.;
	    if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
	      SPoint3 pc = face.interpolate(t1, t2);
	      v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
	    }
	    else{
	      double uc = 0.25 * ((1 - t1) * (1 - t2) * p0[0] + 
				  (1 + t1) * (1 - t2) * p1[0] + 
				  (1 + t1) * (1 + t2) * p2[0] + 
				  (1 - t1) * (1 + t2) * p3[0]); 
	      double vc = 0.25 * ((1 - t1) * (1 - t2) * p0[1] + 
				  (1 + t1) * (1 - t2) * p1[1] + 
				  (1 + t1) * (1 + t2) * p2[1] + 
				  (1 - t1) * (1 + t2) * p3[1]); 
	      GPoint pc = gf->point(uc, vc);
	      v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
	    }
	    faceVertices[p].push_back(v);
	    gf->mesh_vertices.push_back(v);
	    vf.push_back(v);
	  }
	}
      }
      else throw; // not tri or quad
    }
  }
}

void getFaceVertices(GRegion *gr, MElement *ele, std::vector<MVertex*> &vf,
		     faceContainer &faceVertices, bool linear, int nPts = 1)
{
  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);
    std::vector<MVertex*> p;
    face.getOrderedVertices(p);
    if(faceVertices.count(p)){
      vf.insert(vf.end(), faceVertices[p].begin(), faceVertices[p].end());
    }
    else{      
      if(face.getNumVertices() == 3){ // triangles
	for(int j = 0; j < nPts; j++){
	  for(int k = 0 ; k < nPts - j - 1; k++){
	    double t1 = (double)(j + 1) / (nPts + 1);
	    double t2 = (double)(k + 1) / (nPts + 1);
	    SPoint3 pc = face.interpolate(t1, t2);
	    MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
	    faceVertices[p].push_back(v);
	    gr->mesh_vertices.push_back(v);
	    vf.push_back(v);
	  }
	}
      }
      else if(face.getNumVertices() == 4){ // quadrangles
	for(int j = 0; j < nPts; j++){
	  for(int k = 0; k < nPts; k++){
	    // parameters are between -1 and 1
	    double t1 = 2. * (double)(j + 1) / (nPts + 1) - 1.;
	    double t2 = 2. * (double)(k + 1) / (nPts + 1) - 1.;
	    SPoint3 pc = face.interpolate(t1, t2);
	    MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
	    faceVertices[p].push_back(v);
	    gr->mesh_vertices.push_back(v);
	    vf.push_back(v);
	  }
	}
      }
      else throw; // not tri or quad
    }
  }
}

void setHighOrder(GEdge *ge, edgeContainer &edgeVertices, bool linear, 
		  int nbPts = 1)
{
  std::vector<MLine*> lines2;
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MLine *l = ge->lines[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(ge, l, ve, edgeVertices, linear, nbPts);
    if(nbPts == 1)
      lines2.push_back(new MLine3(l->getVertex(0), l->getVertex(1), ve[0]));
    else
      lines2.push_back(new MLineN(l->getVertex(0), l->getVertex(1), ve));      
    delete l;
  }
  ge->lines = lines2;

  if(ge->meshRep) ge->meshRep->destroy();
}

void setHighOrder(GFace *gf, edgeContainer &edgeVertices, 
		  faceContainer &faceVertices, bool linear, bool incomplete,
		  int nPts = 1)
{
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gf, t, ve, edgeVertices, linear, nPts);
    if(nPts == 1){
      triangles2.push_back
	(new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
			ve[0], ve[1], ve[2]));
    }
    else{
      if(incomplete){
	triangles2.push_back
	  (new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
			  ve, nPts + 1));
      }
      else{
	getFaceVertices(gf, t, vf, faceVertices, linear, nPts);
	ve.insert(ve.end(), vf.begin(), vf.end());
	triangles2.push_back
	  (new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
			  ve, nPts + 1));
      }
    }
    delete t;
  }
  gf->triangles = triangles2;
  
  std::vector<MQuadrangle*> quadrangles2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gf, q, ve, edgeVertices, linear, nPts);
    if(incomplete){
      quadrangles2.push_back
	(new MQuadrangle8(q->getVertex(0), q->getVertex(1), q->getVertex(2),
			  q->getVertex(3), ve[0], ve[1], ve[2], ve[3]));
    }
    else{
      getFaceVertices(gf, q, vf, faceVertices, linear, nPts);
      quadrangles2.push_back
	(new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
			  q->getVertex(3), ve[0], ve[1], ve[2], ve[3], vf[0]));
    }
    delete q;
  }
  gf->quadrangles = quadrangles2;
  
  if(gf->meshRep) gf->meshRep->destroy();
}

void setHighOrder(GRegion *gr, edgeContainer &edgeVertices, 
		  faceContainer &faceVertices, bool linear, bool incomplete,
		  int nPts = 1)
{
  std::vector<MTetrahedron*> tetrahedra2;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTetrahedron *t = gr->tetrahedra[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(gr, t, ve, edgeVertices, linear, nPts);
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
    getEdgeVertices(gr, h, ve, edgeVertices, linear, nPts);
    if(incomplete){
      hexahedra2.push_back
	(new MHexahedron20(h->getVertex(0), h->getVertex(1), h->getVertex(2), 
			   h->getVertex(3), h->getVertex(4), h->getVertex(5), 
			   h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2], 
			   ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10], 
			   ve[11]));
    }
    else{
      getFaceVertices(gr, h, vf, faceVertices, linear, nPts);
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
    getEdgeVertices(gr, p, ve, edgeVertices, linear, nPts);
    if(incomplete){
      prisms2.push_back
	(new MPrism15(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
		      p->getVertex(3), p->getVertex(4), p->getVertex(5), 
		      ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8]));
    }
    else{
      getFaceVertices(gr, p, vf, faceVertices, linear, nPts);
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
    getEdgeVertices(gr, p, ve, edgeVertices, linear, nPts);
    if(incomplete){
      pyramids2.push_back
	(new MPyramid13(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
			p->getVertex(3), p->getVertex(4), ve[0], ve[1], ve[2], 
			ve[3], ve[4], ve[5], ve[6], ve[7]));
    }
    else{
      getFaceVertices(gr, p, vf, faceVertices, linear, nPts);
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

void removeHighOrderVertices(GEntity *e)
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

void SetOrder1(GModel *m)
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
    removeHighOrderVertices(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    removeHighOrderVertices(*it);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    removeHighOrderVertices(*it);
}

bool straightLine(std::vector<MVertex*> &l, MVertex *n1, MVertex *n2)
{
  // x = a * t + b
  // x1 = b
  // x2 = a + b
  for(unsigned int i = 0; i < l.size(); i++){
    MVertex *v = l[i];
    double b = n1->x();
    double a = n2->x() - b;
    double t = (v->x() - b) / a;
    double by = n1->y();
    double ay = n2->y() - by;
    double y = ay * t + by;
    if(fabs(y-v->y()) > 1.e-11 * CTX.lc){
      return false;      
    }
  }
  return true;
}

void getMinMaxJac (MTriangle *t, double &minJ, double &maxJ)
{
  double j[2][2];  
  int n = 3;
  for(int i = 0; i < n; i++){
    for(int k = 0; k < n - i; k++){
      t->jac((double)i / (n - 1), (double)k / (n - 1), j);
      double det = det2x2(j);
      minJ = std::min(det, minJ);
      maxJ = std::max(det, maxJ);
    }
  }
}

void smoothInternalEdges(GFace *gf, edgeContainer &edgeVertices)
{
  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e1, e2, e3, e4, e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      MVertex *n1 = t1->getOtherVertex(n2, n4);
      MVertex *n3 = t2->getOtherVertex(n2, n4);
      if(n1 < n2)
	e1 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n1, n2)];
      else
	e1 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n2, n1)];
      if(n2 < n3)
	e2 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n2, n3)];
      else
	e2 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n3, n2)];
      if(n3 < n4)
	e3 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n3, n4)];
      else
	e3 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n4, n3)];
      if(n4 < n1)
	e4 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n4, n1)];
      else
	e4 = edgeVertices[std::make_pair<MVertex*, MVertex*> (n1, n4)];
      if(n2 < n4)
	e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n2, n4)];
      else
	e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n4, n2)];
      
      if((!straightLine(e1, n1, n2) || !straightLine(e2, n2, n3) ||
	  !straightLine(e3, n3, n4) || !straightLine(e4, n4, n1))){
	for(unsigned int i = 0; i < e.size(); i++){
	  double v = (double)(i + 1) / (e.size() + 1);
	  double u = 1. - v;
	  MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	  MVertex *vert1 = (n1 < n2) ? e1[e1.size() - i - 1] : e1[i];
	  MVertex *vert3 = (n3 < n4) ? e3[i] : e3[e3.size() - i - 1];
	  MVertex *vert4 = (n4 < n1) ? e4[e4.size() - i - 1] : e4[i];
	  MVertex *vert2 = (n2 < n3) ? e2[i] : e2[e2.size() - i - 1];
	  vert->x() = vert->x() + 0.05 * ( (1.-u) * vert4->x() + u * vert2->x() +
					   (1.-v) * vert1->x() + v * vert3->x() -
					   ( (1.-u)*(1.-v) * n1->x() 
					     + u * (1.-v) * n2->x() 
					     + u*v*n3->x() 
					     + (1.-u) * v * n4->x()) - vert->x());
	  vert->y() = vert->y() + 0.05 * ( (1.-u) * vert4->y() + u * vert2->y() +
					   (1.-v) * vert1->y() + v * vert3->y() -
					   ( (1.-u)*(1.-v) * n1->y() 
					     + u * (1.-v) * n2->y() 
					     + u*v*n3->y() 
					     + (1.-u) * v * n4->y()) - vert->y());
	}
      }
    }
  }    
}

void checkHighOrderTriangles(GModel *m)
{
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    bool twod = true;
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
      MTriangle *t = (*it)->triangles[i];
      if(t->getVertex(0)->z() != 0.0 || 
	 t->getVertex(1)->z() != 0.0 ||
	 t->getVertex(2)->z() != 0.0)
	twod = false;
    }      
    if(twod){ // only perform the test for 2D/plane faces for now
      double minJ = 1.e22;
      double maxJ = -1.e22;
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
	double minJloc = 1.e22;
	double maxJloc = -1.e22;	    
	MTriangle *t = (*it)->triangles[i];
	if(t->getPolynomialOrder() > 1 && t->getPolynomialOrder() < 6){
	  getMinMaxJac (t, minJloc, maxJloc);
	  minJ = std::min(minJ, minJloc);
	  maxJ = std::max(maxJ, maxJloc);
	  if(minJloc * maxJloc < 0)
	    Msg(WARNING, "Triangle %d (%d %d %d) has negative Jacobian", t->getNum(),
		t->getVertex(0)->getNum(), t->getVertex(1)->getNum(), t->getVertex(2)->getNum());
	}
      }
      if(minJ != 1.e22){
	if(minJ * maxJ < 0)
	  Msg(GERROR, "Some triangles have negative Jacobians in surface %d", (*it)->tag());
	else 
	  Msg(INFO, "No negative Jacobians detected on model face %d: range = (%g,%g)",
	      (*it)->tag(), minJ, maxJ);
      }
    }  
  }
}  

void SetOrderN(GModel *m, int order, bool linear, bool incomplete)
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

  int nPts = order - 1;

  Msg(STATUS1, "Meshing second order...");
  double t1 = Cpu();

  // first, make sure to remove any existsing second order vertices/elements
  SetOrder1(m);

  // then create new second order vertices/elements
  edgeContainer edgeVertices;
  faceContainer faceVertices;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    setHighOrder(*it, edgeVertices, linear, nPts);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    setHighOrder(*it, edgeVertices, faceVertices, linear, incomplete, nPts);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    setHighOrder(*it, edgeVertices, faceVertices, linear, incomplete, nPts);

  if(CTX.mesh.smooth_internal_edges){
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
      for (int i = 0; i < 10; i++) smoothInternalEdges(*it, edgeVertices);
    checkHighOrderTriangles(m);
  }
  
  double t2 = Cpu();
  Msg(INFO, "Mesh second order complete (%g s)", t2 - t1);
  Msg(STATUS1, "Mesh");
}
