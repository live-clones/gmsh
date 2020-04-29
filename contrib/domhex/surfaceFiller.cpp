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
  bool goNonLinear, // do we compute the position in the real surface which is
                    // nonlinear
  SPoint2 newP[4], // look into other directions
  SMetric3 &metricField) // the mesh metric
{
  // we assume that v is on surface gf

  // get the parameter of the point on the surface
  reparamMeshVertexOnFace(v_center, gf, midpoint);

  FieldManager *fields = gf->model()->getFields();
  Field *f = NULL;
  SVector3 t1;
  double L;
  if(fields->getBackgroundField() > 0) {        
    f = fields->get(fields->getBackgroundField());
    if(f->numComponents() == 3) {// we hae a true scaled cross fields !!
      (*f)(v_center->x(), v_center->y(), v_center->z(), t1, gf);
      L = t1.norm();
      //      printf("L = %12.5E\n",L);
      t1.normalize();
      metricField = SMetric3(1. / (L * L));
    }
    else {
      Msg::Error ("Packing of Parallelograms require a scaled cross field");
      Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
      Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
      return false;
    }
  }
  else {
    Msg::Error ("Packing of Parallelograms require a scaled cross field");
    Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
    Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
    return false;
  }
  
  // get the unit normal at that point
  Pair<SVector3, SVector3> der =
    gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
  SVector3 s1 = der.first();
  SVector3 s2 = der.second();
  SVector3 n = crossprod(s1, s2);
  n.normalize();
  
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
  double size_1 = sqrt(1. / dot(t1, metricField, t1));
  double size_2 = sqrt(1. / dot(t2, metricField, t2));

  // compute covariant coordinates of t1 and t2
  // t1 = a s1 + b s2 -->
  // t1 . s1 = a M + b E
  // t1 . s2 = a E + b N --> solve the 2 x 2 system
  // and get covariant coordinates a and b
  double rhs1[2] = {dot(t1, s1), dot(t1, s2)}, covar1[2];
  bool singular = false;
  if(!sys2x2(metric, rhs1, covar1)) {
    Msg::Info("Argh surface %d %g %g %g -- %g %g %g -- %g %g", gf->tag(),
	      s1.x(), s1.y(), s1.z(), s2.x(), s2.y(), s2.z(), size_1, size_2);
    covar1[1] = 1.0;
    covar1[0] = 0.0;
    singular = true;
  }
  double rhs2[2] = {dot(t2, s1), dot(t2, s2)}, covar2[2];
  if(!sys2x2(metric, rhs2, covar2)) {
    Msg::Info("Argh surface %d %g %g %g -- %g %g %g", gf->tag(), s1.x(),
	      s1.y(), s1.z(), s2.x(), s2.y(), s2.z());
    covar2[0] = 1.0;
    covar2[1] = 0.0;
    singular = true;
  }
  
  // transform the sizes with respect to the metric
  // consider a vector v of size 1 in the parameter plane
  // its length is sqrt (v^T M v) --> if I want a real size
  // of size1 in direction v, it should be sqrt(v^T M v) * size1
  double l1 = sqrt(covar1[0] * covar1[0] + covar1[1] * covar1[1]);
  double l2 = sqrt(covar2[0] * covar2[0] + covar2[1] * covar2[1]);
  
  covar1[0] /= l1;
  covar1[1] /= l1;
  covar2[0] /= l2;
  covar2[1] /= l2;
  
  double size_param_1 =
    size_1 / sqrt(M * covar1[0] * covar1[0] + 2 * E * covar1[1] * covar1[0] +
		  N * covar1[1] * covar1[1]);
  double size_param_2 =
    size_2 / sqrt(M * covar2[0] * covar2[0] + 2 * E * covar2[1] * covar2[0] +
		  N * covar2[1] * covar2[1]);
  if(singular) {
    size_param_1 = size_param_2 = std::min(size_param_1, size_param_2);
  }
  
  const double EPS = 1.e-7;
  double r1 = EPS * (double)rand() / RAND_MAX;
  double r2 = EPS * (double)rand() / RAND_MAX;
  double r3 = EPS * (double)rand() / RAND_MAX;
  double r4 = EPS * (double)rand() / RAND_MAX;
  double r5 = EPS * (double)rand() / RAND_MAX;
  double r6 = EPS * (double)rand() / RAND_MAX;
  double r7 = EPS * (double)rand() / RAND_MAX;
  double r8 = EPS * (double)rand() / RAND_MAX;
  double newPoint[4][2] = {{midpoint[0] - covar1[0] * size_param_1 + r1,
			    midpoint[1] - covar1[1] * size_param_1 + r2},
			   {midpoint[0] - covar2[0] * size_param_2 + r3,
			    midpoint[1] - covar2[1] * size_param_2 + r4},
			   {midpoint[0] + covar1[0] * size_param_1 + r5,
			    midpoint[1] + covar1[1] * size_param_1 + r6},
			   {midpoint[0] + covar2[0] * size_param_2 + r7,
			    midpoint[1] + covar2[1] * size_param_2 + r8}};
  // We could stop here. Yet, if the metric varies a lot, we can solve
  // a nonlinear problem in order to find a better approximation in the real
  // surface
  double ERR[4];
  for(int i = 0; i < 4; i++) {
    GPoint pp = gf->point(SPoint2(newPoint[i][0], newPoint[i][1]));
    double D = sqrt((pp.x() - v_center->x()) * (pp.x() - v_center->x()) +
		    (pp.y() - v_center->y()) * (pp.y() - v_center->y()) +
		    (pp.z() - v_center->z()) * (pp.z() - v_center->z()));
    ERR[i] = 100 * fabs(D - L) / (D + L);
  }
  
  if(goNonLinear) {
    surfaceFunctorGFace ss(gf); //
    SVector3 dirs[4] = {t1 * (-1.0), t2 * (-1.0), t1 * (1.0), t2 * (1.0)}; //
    for(int i = 0; i < 4; i++) { //
      if(1) {
	double uvt[3] = {newPoint[i][0], newPoint[i][1], 0.0}; //
	curveFunctorCircle cf(
			      dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()),
			      L);
	if(intersectCurveSurface(cf, ss, uvt, size_param_1 * 1.e-3)) { //
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
	}
	else {
	  Msg::Debug("Cannot put a new point on Surface %d", gf->tag());
	}
      }
    }
  }
  
  // return the four new vertices
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
  }
  return true;
}

void packingOfParallelograms(GFace *gf, std::vector<MVertex *> &packed,
                             std::vector<SMetric3> &metrics)
{
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

  // put boundary vertices in a fifo queue
  std::set<surfacePointWithExclusionRegion *,
           compareSurfacePointWithExclusionRegionPtr> fifo;
  std::vector<surfacePointWithExclusionRegion *> vertices;
  // put the RTREE
  RTree<surfacePointWithExclusionRegion *, double, 2, double> rtree;
  SMetric3 metricField(1.0);
  SPoint2 newp[4];
  std::set<MVertex *>::iterator it = bnd_vertices.begin();

  for(; it != bnd_vertices.end(); ++it) {
    SPoint2 midpoint;
    compute4neighbors(gf, *it, midpoint, goNonLinear, newp, metricField);
    surfacePointWithExclusionRegion *sp =
      new surfacePointWithExclusionRegion(*it, newp, midpoint, metricField);
    fifo.insert(sp);
    vertices.push_back(sp);
    double _min[2], _max[2];
    sp->minmax(_min, _max);
    rtree.Insert(_min, _max, sp);
  }

  //  printf("initially : %d vertices in the domain\n",vertices.size());

  while(!fifo.empty()) {
    surfacePointWithExclusionRegion *parent = *fifo.begin();
    fifo.erase(fifo.begin());
    for(int i = 0; i < 4; i++) {
      if(!inExclusionZone(parent->_p[i], rtree, vertices)) {
	GPoint gp = gf->point(parent->_p[i]);
	MFaceVertex *v =
	  new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	SPoint2 midpoint;
	compute4neighbors(gf, v, midpoint, goNonLinear, newp, metricField);
	surfacePointWithExclusionRegion *sp =
	  new surfacePointWithExclusionRegion(v, newp, midpoint, metricField,
					      parent);
	fifo.insert(sp);
	vertices.push_back(sp);
	double _min[2], _max[2];
	sp->minmax(_min, _max);
	rtree.Insert(_min, _max, sp);
      }
    }
  }
  // add the vertices as additional vertices in the surface mesh
  char ccc[256];
  sprintf(ccc, "points%d.pos", gf->tag());
  FILE *f = NULL;
  f = Fopen(ccc, "w");
  if(f) fprintf(f, "View \"\"{\n");
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
  fprintf(f, "};");
  fclose(f);
}

