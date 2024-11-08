// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "meshSurfaceUntangling.h"
#include "winslowUntangler.h"

#include <math.h>
#include <iostream> // debugging

#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "MVertex.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "GFace.h"
#include "Numeric.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "arrayGeometry.h"

#include <functional>
using std::vector;
using namespace ArrayGeometry;

double lag2bez [10][10] = 
  {{ 1.00000000e+00 , 0.00000000e+00 , 0.00000000e+00  ,0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00  ,0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00},
   { 0.00000000e+00 , 1.00000000e+00 , 0.00000000e+00 , 0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00},
   { 0.00000000e+00 , 0.00000000e+00 , 1.00000000e+00 , 0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00},
   {-8.33333333e-01 , 3.33333333e-01 , 0.00000000e+00 , 3.00000000e+00,
    -1.50000000e+00 , 0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00,
    0.00000000e+00  , 0.00000000e+00},
   { 3.33333333e-01 ,-8.33333333e-01 , 0.00000000e+00 ,-1.50000000e+00,
     3.00000000e+00 , 0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00},
   {-4.16000868e-32 ,-8.33333333e-01 , 3.33333333e-01 , 2.49800181e-16,
    -4.99600361e-16 , 3.00000000e+00 ,-1.50000000e+00 , 4.99600361e-16,
    -2.49800181e-16 , 0.00000000e+00},
   {-2.49800181e-16 , 3.33333333e-01, -8.33333333e-01 , 2.49800181e-16,
    2.49800181e-16 ,-1.50000000e+00 , 3.00000000e+00 ,-9.99200722e-16,
    8.74300632e-16 ,-1.49880108e-15},
   { 3.33333333e-01 , 0.00000000e+00 ,-8.33333333e-01 , 0.00000000e+00,
     0.00000000e+00 , 0.00000000e+00 , 0.00000000e+00 , 3.00000000e+00,
     -1.50000000e+00,  0.00000000e+00},
   {-8.33333333e-01 , 0.00000000e+00 , 3.33333333e-01 , 0.00000000e+00,
    0.00000000e+00  ,0.00000000e+00 , 0.00000000e+00 ,-1.50000000e+00,
    3.00000000e+00 , 0.00000000e+00},
   { 3.33333333e-01 , 3.33333333e-01 , 3.33333333e-01 ,-7.50000000e-01,
     -7.50000000e-01, -7.50000000e-01, -7.50000000e-01, -7.50000000e-01,
     -7.50000000e-01, 4.50000000e+00}};

double bez2lag [10][10] = 
  {{1.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00},
   {0.00000000e+00, 1.00000000e+00, 0.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00},
   {0.00000000e+00, 0.00000000e+00, 1.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00},
   {2.96296296e-01, 3.70370370e-02, 0.00000000e+00, 4.44444444e-01,
    2.22222222e-01, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00},
   {3.70370370e-02, 2.96296296e-01, 0.00000000e+00, 2.22222222e-01,
    4.44444444e-01, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00},
   {1.71056941e-49, 2.96296296e-01, 3.70370370e-02, 6.16297582e-33,
    7.40148683e-17, 4.44444444e-01, 2.22222222e-01, 1.85037171e-17,
    3.08148791e-33, 7.40148683e-17},
   {1.36845553e-48, 3.70370370e-02, 2.96296296e-01, 1.23259516e-32,
    3.70074342e-17, 2.22222222e-01, 4.44444444e-01, 1.48029737e-16,
    2.46519033e-32, 1.48029737e-16},
   {3.70370370e-02, 0.00000000e+00, 2.96296296e-01, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 4.44444444e-01,
    2.22222222e-01, 0.00000000e+00},
   {2.96296296e-01, 0.00000000e+00, 3.70370370e-02, 0.00000000e+00,
    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 2.22222222e-01,
    4.44444444e-01, 0.00000000e+00},
   {3.70370370e-02, 3.70370370e-02, 3.70370370e-02, 1.11111111e-01,
    1.11111111e-01, 1.11111111e-01, 1.11111111e-01, 1.11111111e-01,
    1.11111111e-01, 2.22222222e-01}};



// create a triangle with a unit area ...
bool normalizeTargetArea(std::array<vec2, 3> &target)
{
  double area = triangleArea(target[0], target[1], target[2]);
  if(area <= 0.) { Msg::Warning("target triangle area: %f", area); }
  for(size_t lv = 0; lv < 3; ++lv) {
    target[lv] = (1. / std::pow(area, 1. / 2.)) * target[lv];
  }
  return true;
}

bool buildTrianglesAndTargetsFromElements(
  std::vector<std::array<double, 2> > &points,
  std::vector<std::array<uint32_t, 4> > &elements,
  std::vector<std::array<uint32_t, 3> > &triangles,
  std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes){
  std::vector<std::array<uint32_t, 10> > eb;
  eb.reserve(elements.size());
  for (auto e : elements){
    eb.push_back({e[0],e[1],e[2],e[3],uint32_t(-1),uint32_t(-1),uint32_t(-1),uint32_t(-1),uint32_t(-1),uint32_t(-1)});
  }
  return buildTrianglesAndTargetsFromElements(points, eb, triangles, triIdealShapes);
}

extern size_t perTriangleP2;

bool buildTrianglesAndTargetsFromElements(
  std::vector<std::array<double, 2> > &points,
  std::vector<std::array<uint32_t, 10> > &elements,
  std::vector<std::array<uint32_t, 3> > &triangles,
  std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes)
{
  const uint32_t NO_U32 = (uint32_t)-1;

  // Equilateral triangle centered in origin with unit area

  vec2 one = {1., 1.};
  
  std::array<vec2, 3> equi = {vec2{1., 0.},
                              vec2{cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
                              vec2{cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
  normalizeTargetArea(equi);

  const int quad_dcp[4][3] = {{0, 1, 2}, {0, 2, 3}, {1, 2, 3}, {1, 3, 0}};
  /*
          2
        /   \
       /     \
      5       4
     /         \
    0 --- 3 --- 1

*/
  int NUMT  = perTriangleP2;
  int NUMT2 = (NUMT-4)/3;

  const int p2_cp_19[19][3] = {{0, 3, 5}, {1, 4, 3}, {2, 5, 4}, {0, 1, 2},
			       {0, 1, 5}, {0, 1, 4}, {0, 1, 3}, {0, 3, 5}, {3, 1, 4},
			       {1, 2, 3}, {1, 2, 5}, {1, 2, 4}, {3, 1, 4}, {5, 4, 2},
			       {2, 0, 4}, {2, 0, 3}, {2, 0, 5}, {5, 4, 2}, {0, 3, 5}};

  triIdealShapes.clear();
  triangles.clear();

  // BEZIER POINTS
  std::vector<std::array<double, 2> > bez_points = points;
  
  for(size_t i = 0; i < elements.size(); ++i) {
    if(elements[i][0] == NO_U32) { continue; }
    else if(elements[i][3] == NO_U32) { /* already triangle */
      triangles.push_back({elements[i][0], elements[i][1], elements[i][2]});
      std::array<vec2, 3> perfect = equi;
      triIdealShapes.push_back(perfect);
    }
    else if(elements[i][4] == NO_U32) { /* quad */
      std::array<vec2, 4> qtarget = {vec2{0., 0.}, vec2{1., 0.}, vec2{1., 1.},
                                     vec2{0., 1.}};
      for(size_t k = 0; k < 4; ++k) {
        triangles.push_back({elements[i][quad_dcp[k][0]],
                             elements[i][quad_dcp[k][1]],
                             elements[i][quad_dcp[k][2]]});
        std::array<vec2, 3> target = {qtarget[quad_dcp[k][0]],
                                      qtarget[quad_dcp[k][1]],
                                      qtarget[quad_dcp[k][2]]};
        normalizeTargetArea(target);
        triIdealShapes.push_back(target);
      }
    }
    else if(elements[i][6] == NO_U32) { // P2 triangles -- 
      std::set<std::pair<uint32_t,uint32_t> > p2edges;
      // replace point positions by bezier polygons
      std::array<double, 2> p [6] = {points[elements[i][0]], points[elements[i][1]],
				     points[elements[i][2]], points[elements[i][3]],
				     points[elements[i][4]], points[elements[i][5]]};     
      for (size_t k = 0; k < 3 ; k++){
	std::pair<uint32_t,uint32_t> pair =
	  std::make_pair(std::min(elements[i][k],elements[i][(k+1)%3]),
			 std::max(elements[i][k],elements[i][(k+1)%3]));
	if (p2edges.find(pair) == p2edges.end()){
	  p2edges.insert(pair);
	  double xmid = 0.5*(p[k][0] + p[(k+1)%3][0]); 
	  double ymid = 0.5*(p[k][1] + p[(k+1)%3][1]);
	  double x2   = p[k+3][0]; 
	  double y2   = p[k+3][1];
	  points[elements[i][k+3]][0] = xmid + 2.0*(x2-xmid);
	  points[elements[i][k+3]][1] = ymid + 2.0*(y2-ymid);
	}	
      }

      std::array<vec2, 3> corners = {vec2{points[elements[i][0]][0], points[elements[i][0]][1]},
				     vec2{points[elements[i][1]][0], points[elements[i][1]][1]},
				     vec2{points[elements[i][2]][0], points[elements[i][2]][1]}};
      std::array<vec2, 6> straight = {corners[0],corners[1],corners[2],
				      (corners[0]+corners[1])*.5,
				      (corners[1]+corners[2])*.5,
				      (corners[2]+corners[0])*.5};	
      vec2 dx = (corners[0] + corners[1] + corners[2]) * (-1./3.);
      for (size_t k=0;k<6;k++)straight[k] = (straight[k] + dx);

      for(size_t k = 0; k < (NUMT == 3 ? 3:4) ; ++k) {
	triangles.push_back({elements[i][p2_cp_19[k][0]],
	      elements[i][p2_cp_19[k][1]],
	      elements[i][p2_cp_19[k][2]]});
	std::array<vec2, 3> target = {straight[p2_cp_19[k][0]],
				      straight[p2_cp_19[k][1]],
				      straight[p2_cp_19[k][2]]};
	triIdealShapes.push_back(target);
      }
      
      double signs[5] = {1,1,-1,-1,-1};
      for(size_t k = 4; k < NUMT; k+=NUMT2) {
	double a = 0.0;
	for (size_t l=0; l<NUMT2; l++){
	  triangles.push_back({elements[i][p2_cp_19[k+l][0]],
		elements[i][p2_cp_19[k+l][1]],
		elements[i][p2_cp_19[k+l][2]]});
	  std::array<vec2, 3> targetl = {straight[p2_cp_19[k+l][0]],
					 straight[p2_cp_19[k+l][1]],
					 straight[p2_cp_19[k+l][2]]};
	  a += signs[l]*triangleArea(straight[p2_cp_19[k+l][0]],straight[p2_cp_19[k+l][1]],straight[p2_cp_19[k+l][2]]);
	}
	double fact =sqrt(a);
	std::array<vec2, 3> target = {equi[0]*fact,equi[1]*fact,equi[2]*fact};
	for (size_t l=0; l<NUMT2; l++){	
	  triIdealShapes.push_back(target);
	}
      }
    }
    else if(elements[i][9] != NO_U32) { // P3 triangles -- 
      // replace point positions by bezier polygons
      std::array<double, 2> p [10] = {points[elements[i][0]], points[elements[i][1]],
				      points[elements[i][2]], points[elements[i][3]],
				      points[elements[i][4]], points[elements[i][5]],
				      points[elements[i][6]], points[elements[i][7]],
				      points[elements[i][8]], points[elements[i][9]]};


      for (size_t k = 0; k < 10 ; k++){
	std::array<double, 2> q = {0,0};
	for (size_t l = 0; l < 10 ; l++){
	  q = q + p[l] * lag2bez[k][l];
	}	
	bez_points[elements[i][k]] = q;
      }      
      
      std::array<vec2, 3> corners = {vec2{points[elements[i][0]][0], points[elements[i][0]][1]},
				     vec2{points[elements[i][1]][0], points[elements[i][1]][1]},
				     vec2{points[elements[i][2]][0], points[elements[i][2]][1]}};
      std::array<vec2, 10> straight = {(corners[0]+corners[0]+corners[0])*(1./3.),
				       (corners[1]+corners[1]+corners[1])*(1./3.),
				       (corners[2]+corners[2]+corners[2])*(1./3.),
				       (corners[0]+corners[0]+corners[1])*(1./3.),
				       (corners[0]+corners[1]+corners[1])*(1./3.),
				       (corners[1]+corners[1]+corners[2])*(1./3.),
				       (corners[1]+corners[2]+corners[2])*(1./3.),
				       (corners[2]+corners[2]+corners[0])*(1./3.),
				       (corners[2]+corners[0]+corners[0])*(1./3.),
				       (corners[0]+corners[1]+corners[2])*(1./3.)};
      
      vec2 dx = (corners[0] + corners[1] + corners[2]) * (-1./3.);
      for (size_t k=0;k<10;k++)straight[k] = (straight[k] + dx);

      //      printf(" \n ----------------- EL %lu --- \n",i);

      int counter = 0;
      for(size_t k = 0; k < NUMTCOMBILI_3 ; ++k) {
	double a = 0.0;
	for (size_t l=0; l<N_COMBILI_3[k]; l++){
	  int n0 = TRIANGLES_3[counter][0];
	  int n1 = TRIANGLES_3[counter][1];
	  int n2 = TRIANGLES_3[counter][2];
	  double coef = (double) TRIANGLES_3[counter][3];
	  counter ++;
	  triangles.push_back({elements[i][n0],elements[i][n1],elements[i][n2]});
	  a += coef * triangleArea(straight[n0],straight[n1],straight[n2]);
	  std::array<vec2, 3> target = {straight[n0],straight[n1],straight[n2]};
	  if (N_COMBILI_3[k] == 1)triIdealShapes.push_back(target);
	}
	if (N_COMBILI_3[k] > 1){
	  double fact =sqrt(a);
	  std::array<vec2, 3> target = {equi[0]*fact,equi[1]*fact,equi[2]*fact};
	  for (size_t l=0; l<N_COMBILI_3[k]; l++){	
	    triIdealShapes.push_back(target);
	  }
	}
      }
    }
  }
  if(elements[0][9] != NO_U32)  // P3 triangles -- 
    points =  bez_points;
  
  return true;
}

bool buildVerticesAndElements(GFace *gf, vector<MVertex *> &vertices,
                              vector<std::array<uint32_t, 10> > &elements)
{
  std::unordered_map<MVertex *, uint32_t> old2new;
  vector<uint32_t> fvert;
  for(size_t e = 0; e < gf->getNumMeshElements(); ++e) {
    MElement *elt = gf->getMeshElement(e);
    size_t n = elt->getNumVertices();
    fvert.resize(n);
    for(size_t lv = 0; lv < n; ++lv) {
      MVertex *v = elt->getVertex(lv);
      auto it = old2new.find(v);
      if(it == old2new.end()) {
        old2new[v] = vertices.size();
        fvert[lv] = vertices.size();
        vertices.push_back(v);
      }
      else {
        fvert[lv] = it->second;
      }
    }
    if(n == 3) {
      elements.push_back({fvert[0], fvert[1], fvert[2], uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1)});
    }
    else if (n== 4){
      elements.push_back({fvert[0], fvert[1], fvert[2], fvert[3], uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1)});
    }
    else if (n== 6){
      elements.push_back({fvert[0], fvert[1], fvert[2], fvert[3], fvert[4], fvert[5], uint32_t(-1), uint32_t(-1), uint32_t(-1), uint32_t(-1)});
    }
    else if (n== 10){
      elements.push_back({fvert[0], fvert[1], fvert[2], fvert[3], fvert[4], fvert[5],fvert[6], fvert[7], fvert[8], fvert[9] });
    }
  }

  return true;
}

// --> BL_ExtendHighOrderNodes BEG ----------------------------------------
// move the whole high order nodes column

void BL_ExtendHighOrderNodes (GFace *gf) {
  //  return;
  BoundaryLayerColumns *blc = gf->getColumns();
  if (!blc)return;
  //  printf("BL with %lu col\n",blc->_elemColumns.size());
  for (std::map<MElement *, std::vector<MElement *> >::iterator it = blc->_elemColumns.begin();
       it != blc->_elemColumns.end(); ++it){
    MElement *t0 = static_cast<MTriangle6*> (it->second[0]);
    MElement *t1 = static_cast<MTriangle6*> (it->second[1]);
    if (t0 && t1){
      MElement *t = t0;
      int id0 = 0;
      int id1 = 2;
      int id01 = 5;
      if (t0->getVertex(5)->onWhat()->dim() == 2){
	id0 = 1;
	id1 = 2;
	id01 = 4;
	t = t1;
      }
      
      MVertex *v1 = t->getVertex(id0);
      MVertex *v2 = t->getVertex(id1);
      MVertex *v12 = t->getVertex(id01);
      SVector3 disp_column (v12->x() - (v1->x()+v2->x())*.5,
			    v12->y() - (v1->y()+v2->y())*.5,
			    v12->z() - (v1->z()+v2->z())*.5);    
      
      /*
      printf("disp %12.5E %12.5E\n",disp_column.x(),disp_column.y());
            for (size_t i=0; i<it->second.size();i++){
      	MElement *ti = static_cast<MTriangle6*> (it->second[i]);
		printf("%lu %lu %lu (%lu %lu %lu) %lu %lu %lu (%lu %lu %lu)\n",ti->getVertex(0)->getNum(),ti->getVertex(1)->getNum(),ti->getVertex(2)->getNum(),
		       ti->getVertex(3)->getNum(),ti->getVertex(4)->getNum(),ti->getVertex(5)->getNum(),
		       ti->getVertex(0)->onWhat()->dim(),
		       ti->getVertex(1)->onWhat()->dim(),
		       ti->getVertex(2)->onWhat()->dim(),
		       ti->getVertex(3)->onWhat()->dim(),
		       ti->getVertex(4)->onWhat()->dim(),
		       ti->getVertex(5)->onWhat()->dim());
	      }      
      */
      for (size_t i=0; i<it->second.size();i+=2){
	MElement *ti = static_cast<MTriangle6*> (it->second[i]);
	double x = 1.;// - (double)(i) / (it->second.size()-1);
	if (ti){
	  MVertex *v01i = ti->getVertex(3);
	  MVertex *v20i = t == t0 ? ti->getVertex(5) : ti->getVertex(4);
	  if (v01i->onWhat()->dim() == 2) v01i->setXYZ(v01i->x() + x*disp_column.x(),
						       v01i->y() + x*disp_column.y(),
						       v01i->z() + x*disp_column.z());
	  if (v20i->onWhat()->dim() == 2)v20i->setXYZ(v20i->x() + x*disp_column.x(),
						      v20i->y() + x*disp_column.y(),
						      v20i->z() + x*disp_column.z());
	}
      }
    }
  }
}

// --> BL_ExtendHighOrderNodes END ----------------------------------------
// --> Extend to surfaces 

bool buildPlanarTriProblem(
  GFace *gf, vector<MVertex *> &vertices, vector<vec2> &points,
  std::vector<std::array<uint32_t, 10> > &elements,
  vector<bool> &locked, std::vector<std::array<uint32_t, 3> > &triangles,
  std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes)
{
  //  std::vector<std::array<uint32_t, 6> > elements;
  BL_ExtendHighOrderNodes (gf);
  buildVerticesAndElements(gf, vertices, elements);
  points.resize(vertices.size());
  locked.clear();
  locked.resize(vertices.size(), false);
  SPoint3 proj;
  for(size_t v = 0; v < points.size(); ++v) {
    SPoint3 p = vertices[v]->point();
    // use parametric coordinates instead ...
    // we should do it right for seams
    SPoint2 param;
    bool result = reparamMeshVertexOnFace(vertices[v], gf, param);    
    points[v] = {param.x(),param.y()};
    //    printf("%lu %g %g %g %g %d %d %d\n",vertices[v]->getNum(),param.x(),param.y(),p.x(),p.y(),result,vertices[v]->onWhat()->dim(),vertices[v]->onWhat()->tag());
    //    points[v] = {p.x(),p.y()};
    if(vertices[v]->onWhat()->dim() < 2) { locked[v] = true; }
  }
  return buildTrianglesAndTargetsFromElements(points, elements,
					      triangles, triIdealShapes);
}

double triangle_area_2d(vec2 a, vec2 b, vec2 c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

void _invertTrianglesIfNecessary(
  const std::vector<std::array<double, 2> > &points,
  std::vector<std::array<uint32_t, 3> > &tris)
{
  double area = 0.;
  for(size_t i = 0; i < tris.size(); ++i) {
    area += triangle_area_2d(points[tris[i][0]], points[tris[i][1]],
                             points[tris[i][2]]);
  }
  if(area < 0.) {
    Msg::Debug(
      "invert 2D triangle orientations (total area was %f for %li tris)", area,
      tris.size());
    for(size_t i = 0; i < tris.size(); ++i) {
      uint32_t v1 = tris[i][1];
      tris[i][1] = tris[i][2];
      tris[i][2] = v1;
    }
  }
}

// TEST -------------------------------------------------------------
static double myDensity (double x, double y){
  double r = sqrt(x*x+y*y);
  //  double theta = atan2(y,x);
  //  double a = 0.3;
  //  double d = a*(1+cos(theta));
  //  double density = 0.01 + 1./(.1+(d-r)*(d-r));
  double density = 1./(.01+2*fabs(r-.2));
  return density;
}

void myUpdateIdealShapes (const std::vector<std::array<double, 2> > &points,
			  const std::vector<std::array<uint32_t, 3> > &triangles,
			  std::vector<std::array<std::array<double, 2>, 3> > &triIdealShapes){
  triIdealShapes.clear();
  std::array<vec2, 3> equi = {vec2{1., 0.},
                              vec2{cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
                              vec2{cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
  normalizeTargetArea(equi);
  double areaEqui = triangleArea(equi[0], equi[1], equi[2]);
  //  printf("Updating %lu ideal shapes area %g\n",triangles.size(),areaEqui);
  double totArea = 0.0;
  double totOneOverWeight = 0.0;
  
  for (size_t i=0;i<triangles.size();i++){
    vec2 v0 = points[triangles[i][0]];
    vec2 v1 = points[triangles[i][1]];
    vec2 v2 = points[triangles[i][2]];
    double xc = (v0[0]+v1[0]+v2[0])/3.0;
    double yc = (v0[1]+v1[1]+v2[1])/3.0;
    double density = myDensity (xc,yc);
    double area = triangle_area_2d(v0,v1,v2);
    totArea += area;
    totOneOverWeight += 1./density;
  }
  double C = totArea/totOneOverWeight;  
  
  // \rho (x_i,y_i) * s_i = c --> s_i = c / \rho_i 
  // \sum_i s_i = S --> S = c \sum (1/\rho_i) 
  // 

  double newArea = 0;
  for (size_t i=0;i<triangles.size();i++){
    vec2 v0 = points[triangles[i][0]];
    vec2 v1 = points[triangles[i][1]];
    vec2 v2 = points[triangles[i][2]];
    double xc = (v0[0]+v1[0]+v2[0])/3.0;
    double yc = (v0[1]+v1[1]+v2[1])/3.0;
    double density = myDensity(xc,yc);
    double fact = sqrt(C/density);
    vec2 p0 = equi[0] * fact;
    vec2 p1 = equi[1] * fact;
    vec2 p2 = equi[2] * fact;
    std::array<vec2, 3> perfect = {p0,p1,p2};
    double area = triangle_area_2d(p0,p1,p2);
    newArea += area;
    triIdealShapes.push_back(perfect);
  }
  printf("%22.15E %22.15E \n",newArea,totArea);
}
// ENDTEST ---------------------------------------------------------


bool untangleGFaceMeshConstrained(GFace *gf, int iterMax, double timeMax)
{
  const uint32_t NO_U32 = (uint32_t)-1;
  // if(gf->geomType() != GFace::Plane) {
  //   Msg::Error("- Face %i: untangleGFaceMeshConstrained only implemented for "
  //              "planar faces",
  //              gf->tag());
  //   return false;
  // }

  if(gf->getNumMeshElements() == 0) {
    Msg::Debug("- Face %i: no elements", gf->tag());
    return false;
  }

  double t0 = Cpu();

  double sicnMinB, sicnAvgB;
  computeSICNquality(gf, sicnMinB, sicnAvgB);

  /* Build planar problem by projection on mean plane */
  vector<MVertex *> vertices;
  vector<vec2> points;
  vector<bool> locked;
  vector<std::array<uint32_t, 3> > triangles;
  std::vector<std::array<std::array<double, 2>, 3> > triIdealShapes;
  std::vector<std::array<uint32_t, 10> > elements;
  bool okb = buildPlanarTriProblem(gf, vertices,  points, elements,locked, triangles,
                                   triIdealShapes);
  if(!okb) {
    Msg::Error(
      "- Face %i: untangleGFaceMeshConstrained, failed to build planar problem",
      gf->tag());
    return false;
  }
  _invertTrianglesIfNecessary(points, triangles);

  /* Call Winslow untangler */
  int iterMaxInner = 1000;
  int iterFailMax = 10;
  double lambda = 1.0100;

#if 1
  {
    FILE *f = fopen("t.pos","w");
    fprintf(f,"View\"\"{\n");
    int count = 0;
    for (auto t : triangles){
      fprintf(f,"ST(%g,%g,0,%g,%g,0,%g,%g,0){%d,%d,%d};\n",
	      points[t[0]][0],points[t[0]][1],
	      points[t[1]][0],points[t[1]][1],
	      points[t[2]][0],points[t[2]][1],count,count,count++);
    }
    fprintf(f,"}\n;");
    fclose(f);
  }
#endif

  bool converged =
    untangle_triangles_2D(points, locked, triangles, triIdealShapes, lambda,
  			  iterMaxInner, iterMax, iterFailMax, timeMax,nullptr);
			  //  			  myUpdateIdealShapes);
#if 1
  {
    FILE *f = fopen("unt.pos","w");
    fprintf(f,"View\"\"{\n");
    for (auto t : triangles){
      fprintf(f,"ST(%g,%g,0,%g,%g,0,%g,%g,0){0,0,0};\n",
	      points[t[0]][0],points[t[0]][1],
	      points[t[1]][0],points[t[1]][1],
	      points[t[2]][0],points[t[2]][1]);
    }
    fprintf(f,"}\n;");
    fclose(f);
  }
#endif

  // p2 triangles are using bezier polygons --> back to non bezier ...
  {
    std::set<std::pair<uint32_t,uint32_t> > p2edges;
    std::vector<std::array<double, 2> > lag_points = points;
    for(size_t i = 0; i < elements.size(); ++i) {
      if(elements[i][5] != NO_U32 && elements[i][6] == NO_U32) { // P2 triangles --
	std::array<double, 2> p [6] = {points[elements[i][0]], points[elements[i][1]],
				       points[elements[i][2]], points[elements[i][3]],
				       points[elements[i][4]], points[elements[i][5]]};
	for (size_t k = 0; k < 3 ; k++){
	  std::pair<uint32_t,uint32_t> pair =
	    std::make_pair(std::min(elements[i][k],elements[i][(k+1)%3]),
			   std::max(elements[i][k],elements[i][(k+1)%3]));
	  if (p2edges.find(pair) == p2edges.end()){
	    p2edges.insert(pair);
	    double xmid = 0.5*(p[k][0] + p[(k+1)%3][0]); 
	    double ymid = 0.5*(p[k][1] + p[(k+1)%3][1]);
	    double xb   = p[k+3][0]; 
	    double yb   = p[k+3][1];
	    points[elements[i][k+3]][0] = 0.5*(xmid + xb);
	    points[elements[i][k+3]][1] = 0.5*(ymid + yb);
	  }
	}
      }
      if(elements[i][6] != NO_U32) { // P3 triangles --
	double bez2lag [10][10] = 
	  {{1.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00},
	   {0.00000000e+00, 1.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00},
	   {0.00000000e+00, 0.00000000e+00, 1.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00},
	   {2.96296296e-01, 3.70370370e-02, 0.00000000e+00, 4.44444444e-01,
	    2.22222222e-01, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00},
	   {3.70370370e-02, 2.96296296e-01, 0.00000000e+00, 2.22222222e-01,
	    4.44444444e-01, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00},
	   {1.71056941e-49, 2.96296296e-01, 3.70370370e-02, 6.16297582e-33,
	    7.40148683e-17, 4.44444444e-01, 2.22222222e-01, 1.85037171e-17,
	    3.08148791e-33, 7.40148683e-17},
	   {1.36845553e-48, 3.70370370e-02, 2.96296296e-01, 1.23259516e-32,
	    3.70074342e-17, 2.22222222e-01, 4.44444444e-01, 1.48029737e-16,
	    2.46519033e-32, 1.48029737e-16},
	   {3.70370370e-02, 0.00000000e+00, 2.96296296e-01, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 4.44444444e-01,
	    2.22222222e-01, 0.00000000e+00},
	   {2.96296296e-01, 0.00000000e+00, 3.70370370e-02, 0.00000000e+00,
	    0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 2.22222222e-01,
	    4.44444444e-01, 0.00000000e+00},
	   {3.70370370e-02, 3.70370370e-02, 3.70370370e-02, 1.11111111e-01,
	    1.11111111e-01, 1.11111111e-01, 1.11111111e-01, 1.11111111e-01,
	    1.11111111e-01, 2.22222222e-01}};
	
	std::array<double, 2> p [10] = {points[elements[i][0]], points[elements[i][1]],
					points[elements[i][2]], points[elements[i][3]],
					points[elements[i][4]], points[elements[i][5]],
					points[elements[i][6]], points[elements[i][7]],
					points[elements[i][8]], points[elements[i][9]]};

	for (size_t k = 0; k < 10 ; k++){
	  std::array<double, 2> q = {0,0};
	  for (size_t l = 0; l < 10 ; l++){
	    q = q + p[l] * bez2lag[k][l];
	  }	
	  lag_points[elements[i][k]] = q;
	}      
      }      
    }
    if(elements[0][6] != NO_U32)
      points = lag_points;
  }

  /* Project back on 3D plane, then CAD */
  for(size_t v = 0; v < points.size(); ++v)
    if(!locked[v]) {
      GPoint gp = gf->point(points[v][0], points[v][1]);
      //      SPoint3 onPlane = SPoint3(points[v][0],
      //                                points[v][1],0);
      //      
      //      double initGuess[2] = {0., 0.};
      //      GPoint proj = gf->closestPoint(onPlane, initGuess);
      //      if(proj.succeeded()) {
      //        vertices[v]->setXYZ(proj.x(), proj.y(), proj.z());
      //        vertices[v]->setParameter(0, proj.u());
      //        vertices[v]->setParameter(1, proj.v());
      //      }
      //      else {
      //      vertices[v]->setXYZ(onPlane.x(), onPlane.y(), onPlane.z());
	//      }
      vertices[v]->setXYZ(gp.x(),gp.y(),gp.z());
      if (vertices[v]->onWhat() == gf){
	vertices[v]->setParameter(0,points[v][0]);
	vertices[v]->setParameter(1,points[v][1]);
      }
    }

  double sicnMinA, sicnAvgA;
  computeSICNquality(gf, sicnMinA, sicnAvgA);

  Msg::Info("- Face %i: Winslow untangling, SICN min: %.3f -> %.3f, avg: %.3f "
            "-> %.3f (%li vertices, %.3f seconds)",
            gf->tag(), sicnMinB, sicnMinA, sicnAvgB, sicnAvgA, vertices.size(),
            Cpu() - t0);

  return true;
}

#else
bool untangleGFaceMeshConstrained(GFace *gf, int iterMax, double timeMax)
{
  Msg::Error(
    "Module QuadMeshingTools required for untangleGFaceMeshConstrained");
  return false;
}
#endif
