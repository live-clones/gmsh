// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_INTRINSIC_H
#define MESH_INTRINSIC_H

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
#include "SPoint2.h"
#include "meshPolyMesh.h"

bool intersectTwoCircles ( SPoint2 &pA,  SPoint2 &pB,  double ra, double rb,  SPoint2 & p,  SPoint2 & q);

class IntrinsicTriangulation {
  PolyMesh *extrinsic_;
  PolyMesh *intrinsic_;
 public:
  static double EPS() {return 1.e-09;}
  struct VertexOnEdge {
    PolyMesh::HalfEdge *he; // he in the extrinsic_ mesh
    double t; // local coordinates of the vertex in that edge
    SVector3 point  ()const{
      return he->v->position*(1.-t)+
	he->next->v->position*t;
    }
  };

  struct VertexOnFace {
    PolyMesh::HalfEdge *he; // he->f in the extrinsic_ mesh
    double u,v; // local coordinates of the vertex in that face
    SVector3 point () const {
      return he->v->position*(1.-u-v)+
	he->next->v->position*u+
	he->next->next->v->position*v;
    }
  };

  struct Geodesic {
    VertexOnFace _start;
    VertexOnFace _end;
    std::vector<VertexOnEdge> _pts;
    void print4debug (int id);
  };

  struct Window {
    PolyMesh::HalfEdge *he;
    double d1, d2;
    double t1, t2;
    bool operator < (const Window &w) const{
      if (d1+d2 < w.d1+w.d2)return true;
      if (d1+d2 > w.d1+w.d2)return false;
      //      if (std::min(d1,d2) < std::min(w.d1,w.d2))return true;
      //      if (std::min(d1,d2) > std::min(w.d1,w.d2))return false;
      return he < w.he;
    }
    void reverse() {
      he = he->opposite;
      double T = t2; t2 = 1.-t1 ; t1 = 1.-T;
      double D = d2; d2 = d1 ; d1 = D;
    }
  };

  struct DistanceFieldOnEdge {
    std::vector<double> d, t;
    void intersect (Window & w){
      double L = w.he->l();
      SPoint2 p1 (w.t1*L,0);
      SPoint2 p2 (w.t2*L,0);
      SPoint2 p3 , p3_neg;
      intersectTwoCircles (p1,p2,w.d1,w.d2,p3,p3_neg);

      int N = t.size();

      if (t[0] >= w.t2-IntrinsicTriangulation::EPS()){
	t.insert(t.begin(), w.t1);
	t.insert(t.begin(), w.t2);
	d.insert(d.begin(), w.d1);
	d.insert(d.begin(), w.d2);
      }
      else if (t[N-1] <= w.t1+IntrinsicTriangulation::EPS()){
	t.push_back(w.t1);
	t.push_back(w.t2);
	d.push_back(w.d1);
	d.push_back(w.d2);
      }
      else {
	//	printf("MUST INTERSECT : %g %g %g %gwith (",w.t1, w.t2,w.d1, w.d2);
	//	std::vector<double>::iterator M = std::max_element(d.begin(), d.end());
	//	if (*M < std::min(w.d1,w.d2)){
	//	  w.d1 = -1000;
	//	  w.d2 = -1000;
	//	  return;
	//	}
	std::vector<double> T=t,D=d;
	t.clear(); d.clear();
	for (size_t i = 0; i< T.size() ; i+=2){
	  double t1 = T[i];
	  double t2 = T[i+1];
	  double d1 = D[i];
	  double d2 = D[i+1];
	  if (t1 <= w.t1+IntrinsicTriangulation::EPS() && w.t1 <= t2+IntrinsicTriangulation::EPS() && t2 <= w.t2+IntrinsicTriangulation::EPS()){
	    SPoint2 q1 (t1*L,0);
	    SPoint2 q2 (t2*L,0);
	    SPoint2 q3 , q3_neg;
	    intersectTwoCircles (q1,q2,d1,d2,q3,q3_neg);
	    double tt = (q3.x()*q3.x()+q3.y()*q3.y()-p3.x()*p3.x()-p3.y()*p3.y())/(2*L*(q3.x()-p3.x()));
	    double dd = sqrt ((p3.x()-tt*L)*(p3.x()-tt*L) + p3.y()*p3.y());
	    t.push_back(t1);t.push_back(tt);t.push_back(tt);t.push_back(w.t2);
	    d.push_back(d1);d.push_back(dd);d.push_back(dd);d.push_back(w.d2);
	    printf("OVERLAP (%d %d) (%g,%g,%g,%g) ",w.he->v->data,w.he->next->v->data,t1,t2,w.t1,w.t2);
	    printf("(%g,%g,%g,%g) (%g %g)\n",d1,d2,w.d1,w.d2,tt,dd);
	  }
	  else if (w.t1 <= t1+IntrinsicTriangulation::EPS() && t1 <= w.t2+IntrinsicTriangulation::EPS() && w.t2 <= t2+IntrinsicTriangulation::EPS()){
	    SPoint2 q1 (t1*L,0);
	    SPoint2 q2 (t2*L,0);
	    SPoint2 q3 , q3_neg;
	    intersectTwoCircles (q1,q2,d1,d2,q3,q3_neg);
	    double tt = (p3.x()*p3.x()+p3.y()*p3.y()-q3.x()*q3.x()-q3.y()*q3.y())/(2*L*(p3.x()-q3.x()));
	    double dd = sqrt ((q3.x()-tt*L)*(q3.x()-tt*L) + q3.y()*q3.y());
	    t.push_back(w.t1);/*t.push_back(tt);t.push_back(tt);*/t.push_back(t2);
	    d.push_back(w.d1);/*d.push_back(dd);d.push_back(dd);*/d.push_back(d2);
	    //	    printf("OVERLAP BIS(%d %d) (%g,%g,%g,%g) ",w.he->v->data,w.he->next->v->data,t1,t2,w.t1,w.t2);
	    //	    printf("(%g,%g,%g,%g) (%g %g)\n",d1,d2,w.d1,w.d2,tt,dd);
	  }
	  // it encloses
	  else if (t1 <= w.t1 && t2 >= w.t2){
	    if (std::min(w.d1,w.d2) > std::max(d1,d2)){
	      w.d1 = -1000;
	      w.d2 = -1000;
	      //	      return;
	    }
	    printf("ENCLOSING (%d %d) (%g,%g,%g,%g) ",w.he->v->data,w.he->next->v->data,t1,t2,w.t1,w.t2);
	    printf("(%g,%g,%g,%g) \n",d1,d2,w.d1,w.d2);
	  }
	}
	//	printf(")\n");
      }
    }
  };
  
  struct DistanceField {
    std::map <PolyMesh::HalfEdge *, DistanceFieldOnEdge> d;
    void addWindow (Window &w){
      std::map <PolyMesh::HalfEdge *, DistanceFieldOnEdge>::iterator it  = d.find(w.he);
      std::map <PolyMesh::HalfEdge *, DistanceFieldOnEdge>::iterator ito = d.find(w.he->opposite);
      if (it != d.end()){
	it->second.intersect (w);
      }      
      else if (w.he->opposite && ito != d.end()){
	w.reverse();
	ito->second.intersect (w);
	w.reverse();
      }      
      else{
	DistanceFieldOnEdge doe;
	doe.t.push_back(w.t1);
	doe.t.push_back(w.t2);
	doe.d.push_back(w.d1);
	doe.d.push_back(w.d2);
	d[w.he] = doe;
      }
    }
    void print(const char *fn){
      FILE *f = fopen (fn,"w");
      fprintf(f,"View \" \"{\n");
      for (auto it : d){
	const PolyMesh::HalfEdge *he = it.first;
	DistanceFieldOnEdge &doe = it.second;
	for (size_t i=0;i<doe.t.size();i+=2){
	  double t1 = doe.t[i];
	  double t2 = doe.t[i+1];
	  double d1 = doe.d[i];
	  double d2 = doe.d[i+1];
	  SVector3 P1 = (1.-t1)*he->v->position + t1*he->next->v->position; 
	  SVector3 P2 = (1.-t2)*he->v->position + t2*he->next->v->position;
	  fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",P1.x(),P1.y(),P1.z(),P2.x(),P2.y(),P2.z(),d1,d2);
	}
      }
      fprintf(f,"};\n");
      fclose(f);
    }
  };
  
  
  Geodesic trace (const VertexOnFace &start, double L, double theta);
  int continuousRienstra (PolyMesh::Vertex *v, double Lmax, DistanceField &d);
  
  IntrinsicTriangulation (PolyMesh *extr) : extrinsic_ (extr), intrinsic_ (nullptr)
  {
    // initialize the intrinsic triangulation as the extrinsic one and initialize
    // hedges and vertices
    intrinsic_ = new PolyMesh (*extrinsic_);
  }

  void test();
  
};


#endif
