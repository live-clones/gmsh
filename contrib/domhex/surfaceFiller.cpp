// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier Baudoin

#include <queue>
#include <stack>
#include "GmshConfig.h"
#include "surfaceFiller.h"
#include "Field.h"
#include "GModel.h"
#include "OS.h"
#include "rtree.h"
#include "MVertex.h"
#include "MElement.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "intersectCurveSurface.h"
#include "pointInsertionRTreeTools.h"

// Here, we aim at producing a set of points that enables to generate a nice
// quad mesh

// assume a point on the surface, compute the 4 possible neighbors.
//
//              ^ t2
//              |
//              |
//             v2
//              |
//              |
//       v1-----+------v3 -------> t1
//              |
//              |
//             v4
//
// we aim at generating a rectangle with sizes size_1 and size_2 along t1 and t2

bool compute4neighbors(
  GFace *gf, // the surface
  MVertex *v_center, // the wertex for which we wnt to generate 4 neighbors
  SPoint2 &midpoint,
  SPoint2 newP[4], // look into other directions
  SMetric3 &metricField,// the mesh metric
  Field *f,
  double du,
  double dv,
  double mult) 
{
  // we assume that v is on surface gf

  // get the parameter of the point on the surface
  reparamMeshVertexOnFace(v_center, gf, midpoint);

  midpoint = SPoint2(midpoint.x() + du,midpoint.y() + dv);
  
  SVector3 t1;
  (*f)(v_center->x(), v_center->y(), v_center->z(), t1, gf);
  double L = t1.norm()*mult;
  //      printf("L = %12.5E\n",L);
  metricField = SMetric3(1. / (L * L));

  // get the unit normal at that point
  Pair<SVector3, SVector3> der =
    gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
  SVector3 s1 = der.first();
  SVector3 s2 = der.second();
  SVector3 n = crossprod(s1, s2);
  n.normalize();
  t1 -= n*dot(t1,n);
  t1.normalize();
  
  double M = dot(s1, s1);
  double N = dot(s2, s2);
  double E = dot(s1, s2);

  // compute the first fundamental form i.e. the metric tensor at the point
  // M_{ij} = s_i \cdot s_j
  double metric[2][2] = {{M, E}, {E, N}};

  // compute the second direction t2 and normalize (t1,t2,n) is the tangent
  // frame
  SVector3 t2 = crossprod(n, t1);
  t2.normalize();

  // compute covariant coordinates of t1 and t2
  // t1 = a s1 + b s2 -->
  // t1 . s1 = a M + b E
  // t1 . s2 = a E + b N --> solve the 2 x 2 system
  // and get covariant coordinates a and b
  double rhs1[2] = {dot(t1, s1)*L, dot(t1, s2)*L}, covar1[2];
  bool singular = false;
  if(!sys2x2(metric, rhs1, covar1)) {
    covar1[1] = 1.0;
    covar1[0] = 0.0;
    singular = true;
  }
  double rhs2[2] = {dot(t2, s1)*L, dot(t2, s2)*L}, covar2[2];
  if(!sys2x2(metric, rhs2, covar2)) {
    covar2[0] = 1.0;
    covar2[1] = 0.0;
    singular = true;
  }
  double size_1 = sqrt (covar1[0]*covar1[0]+covar1[1]*covar1[1]);
  double size_2 = sqrt (covar2[0]*covar2[0]+covar2[1]*covar2[1]);

  //    double L1 = sqrt(covar1[0]*covar1[0]*M+2*covar1[1]*covar1[0]*E+covar1[1]*covar1[1]*N);
  //    double L2 = sqrt(covar2[0]*covar2[0]*M+2*covar2[1]*covar2[0]*E+covar2[1]*covar2[1]*N);

  //    printf("T(%g,%g,%g) N(%g,%g,%g) S1(%g,%g,%g) S2(%g,%g,%g) COVAR (%g %g) (%g %g) L %g %g %g\n",t1.x(),t1.y(),t1.z(),n.x(),n.y(),n.z(),
  //  	 s1.x(),s1.y(),s1.z(),s2.x(),s2.y(),s2.z(),covar1[0],covar1[1],covar2[0],covar2[1],L, L1, L2);

  if (singular){
    Msg::Error("CORONAVIRUS ALERT !!!!\n");
  }
  
  
  double newPoint[4][2] = {{midpoint[0] - covar1[0],
			    midpoint[1] - covar1[1]},
			   {midpoint[0] - covar2[0],
			    midpoint[1] - covar2[1]},
			   {midpoint[0] + covar1[0],
			    midpoint[1] + covar1[1]},
			   {midpoint[0] + covar2[0],
			    midpoint[1] + covar2[1]}};
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
  }

  return true;
}

void packingOfParallelograms(GFace *gf, std::vector<MVertex *> &packed,
                             std::vector<SMetric3> &metrics)
{


  char ccc[256];
  sprintf(ccc, "points%d.pos", gf->tag());
  FILE *f = NULL;
  f = Fopen(ccc, "w");
  sprintf(ccc, "e_points%d.pos", gf->tag());
  FILE *f2 = NULL;
  f2 = Fopen(ccc, "w");
  if(f) fprintf(f, "View \"\"{\n");
  if(f2) fprintf(f2, "View \"\"{\n");

  FieldManager *fields = gf->model()->getFields();
  Field *cross_field = NULL;
  SVector3 t1;
  double L;
  if(fields->getBackgroundField() > 0) {        
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) {// we hae a true scaled cross fields !!
      Msg::Error ("Packing of Parallelograms require a scaled cross field");
      Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
      Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
      return;
    }
  }
  else {
    Msg::Error ("Packing of Parallelograms require a scaled cross field");
    Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
    Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
    return;
  }

  const bool goNonLinear = true;
  
  // get all the boundary vertices
  std::set<MVertex *> bnd_vertices;
  for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() < 2) bnd_vertices.insert(vertex);
    }
  }

  // Renormalize size map taking into account quantization...
  double globalMult = 0.0;
  if (1){
    int count = 0;
    std::vector<GEdge *> edges = gf->edges();
    for(size_t i = 0; i < edges.size(); i++) {
      for(size_t j = 0; j < edges[i]->lines.size(); j++) {
	MVertex *v0 = edges[i]->lines[j]->getVertex(0);
	MVertex *v1 = edges[i]->lines[j]->getVertex(1);
	double L = v0->distance(v1);
	SVector3 vec;
	(*cross_field)(0.5*(v0->x()+v1->x()),0.5*(v0->y()+v1->y()),0.5*(v0->z()+v1->z()),vec);
	double L2 = vec.norm();
	double MULT = L/L2;
	globalMult += MULT;
	count ++;
      }
    }
    globalMult /= count;
  }

  printf("MULT %12.5E\n",globalMult);


  // put boundary vertices in a fifo queue
  std::queue<surfacePointWithExclusionRegion *> fifo;
  std::vector<surfacePointWithExclusionRegion *> vertices;
  // put the RTREE
  RTree<surfacePointWithExclusionRegion *, double, 2, double> rtree;
  SMetric3 metricField(1.0);
  SPoint2 newp[4];
  std::set<MVertex *>::iterator it = bnd_vertices.begin();

  for(; it != bnd_vertices.end(); ++it) {

    int NP = 1;
    SPoint2 midpoint;
    double du[4] = {0,0,0,0}, dv[4]= {0,0,0,0};
    
    for (int i=0;i<2;i++){
      if (gf->periodic(i)){
	reparamMeshVertexOnFace(*it, gf, midpoint);
	Range<double> bnds = gf->parBounds(i);      
	if (midpoint[i] == bnds.low()){
	  if (i == 0)
	    du[NP] =  bnds.high() -  bnds.low();
	  else
	    dv[NP] =  bnds.high() -  bnds.low();
	  NP++;
	}
	else if (midpoint[i] == bnds.high()){
	  if (i == 0)
	    du[NP] =  -(bnds.high() -  bnds.low());
	  else
	    dv[NP] =  -(bnds.high() -  bnds.low());
	  NP++;
	}
      }
    }
    for (int i=0;i<NP;i++){
      compute4neighbors(gf, *it, midpoint, newp, metricField, cross_field, du[i],dv[i],globalMult );
      surfacePointWithExclusionRegion *sp =
	new surfacePointWithExclusionRegion(*it, newp, midpoint, metricField);
      fifo.push(sp);
      vertices.push_back(sp);
      double _min[2], _max[2];
      sp->minmax(_min, _max);
      rtree.Insert(_min, _max, sp);
    }
  }

  //  printf("initially : %d vertices in the domain\n",vertices.size());

  while(!fifo.empty()) {
    //    printf("%d vertices in the domain\n",vertices.size());
    //    if (vertices.size() > 5000)break;
    surfacePointWithExclusionRegion *parent = fifo.front();
    fifo.pop();
    for(int i = 0; i < 4; i++) {
      if(!inExclusionZone(parent->_p[i], rtree, vertices) && gf->containsParam(parent->_p[i])) {
	GPoint gp = gf->point(parent->_p[i]);
	MFaceVertex *v =
	  new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	SPoint2 midpoint;
	compute4neighbors(gf, v, midpoint, newp, metricField, cross_field,0, 0, globalMult);
	surfacePointWithExclusionRegion *sp =
	  new surfacePointWithExclusionRegion(v, newp, midpoint, metricField,
					      parent);
	fifo.push(sp);
	vertices.push_back(sp);
	double _min[2], _max[2];
	sp->minmax(_min, _max);
	rtree.Insert(_min, _max, sp);
      }
      else{
	GPoint gp = gf->point(parent->_p[i]);
	MFaceVertex *v =
	  new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	SPoint2 midpoint;
	compute4neighbors(gf, v, midpoint, newp, metricField, cross_field, 0, 0 , globalMult);
	surfacePointWithExclusionRegion *sp =
	  new surfacePointWithExclusionRegion(v, newp, midpoint, metricField,
					      parent);
	sp->print(f2, i);
      }
    }
  }
  // add the vertices as additional vertices in the surface mesh
  for(unsigned int i = 0; i < vertices.size(); i++) {
    vertices[i]->print(f, i);
    if(vertices[i]->_v->onWhat() == gf) {
      packed.push_back(vertices[i]->_v);
      metrics.push_back(vertices[i]->_meshMetric);
      SPoint2 midpoint;
      reparamMeshVertexOnFace(vertices[i]->_v, gf, midpoint);
    }
    delete vertices[i];
  }
  fprintf(f2, "};");
  fclose(f2);
  fprintf(f, "};");
  fclose(f);
}

/* OLD STUFF 

  
  surfaceFunctorGFace ss(gf); //
  SVector3 dirs[4] = {t1 * (-1.0), t2 * (-1.0), t1 * (1.0), t2 * (1.0)}; //
  for(int i = 0; i < 4; i++) { //
    double uvt[3] = {newPoint[i][0], newPoint[i][1], 0.0}; //
    
    curveFunctorCircle cf(
			  dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()),
			  L);
    if(intersectCurveSurface(cf, ss, uvt, size_1 * 1.e-2)) { //
      GPoint pp = gf->point(SPoint2(uvt[0], uvt[1]));
      double D =
	sqrt((pp.x() - v_center->x()) * (pp.x() - v_center->x()) +
	     (pp.y() - v_center->y()) * (pp.y() - v_center->y()) +
	     (pp.z() - v_center->z()) * (pp.z() - v_center->z()));
      double DP =
	sqrt((newPoint[i][0] - uvt[0]) * (newPoint[i][0] - uvt[0]) +
	     (newPoint[i][1] - uvt[1]) * (newPoint[i][1] - uvt[1]));
      double newErr = 100 * fabs(D - L) / (D + L);
      if(newErr < 1 && DP < .1) {
	newPoint[i][0] = uvt[0];
	newPoint[i][1] = uvt[1];
      }
      else {      
	SPoint3 test (v_center->x() + dirs[i].x() * L,
		      v_center->y() + dirs[i].y() * L,
		      v_center->z() + dirs[i].z() * L);      
	
	
	GPoint pp = gf->closestPoint(test,uvt);
	if (pp.succeeded()){
	  newPoint[i][0] = pp.u();
	  newPoint[i][1] = pp.v();
	}
	else return false;
      }
    }
    else {      
      SPoint3 test (v_center->x() + dirs[i].x() * L,
		    v_center->y() + dirs[i].y() * L,
		    v_center->z() + dirs[i].z() * L);      
      
      
      GPoint pp = gf->closestPoint(test,uvt);
      if (pp.succeeded()){
	newPoint[i][0] = pp.u();
	newPoint[i][1] = pp.v();
      }
      else return false;
    }
  }

  
  // return the four new vertices
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
  }
  return true;

 */
