#include "meshIntrinsicTriangulation.h"
#include <set>
#include "SPoint2.h"
#include "Numeric.h"
#include "robustPredicates.h"
/*                ^ d2b
          d2     /   ^
           ^    +p3 /
	   |   / \ /        +p (x,y)
           |  /   \ theta           
           | /  /--\-----
           |/  _v   \
           +---------+---> d1
          p1         p2
    
    https://math.stackexchange.com/questions/256100/how-can-i-find-the-points-at-which-two-circles-intersect
    
*/

static int intersection_segments_(const SPoint2 &p1, const SPoint2 &p2,
				  const SPoint2 &q1, const SPoint2 &q2, double x[2])
{
  double A[2][2];
  A[0][0] = p2.x() - p1.x();
  A[0][1] = q1.x() - q2.x();
  A[1][0] = p2.y() - p1.y();
  A[1][1] = q1.y() - q2.y();
  double b[2] = {q1.x() - p1.x(), q1.y() - p1.y()};
  sys2x2(A, b, x);
  return (x[0] >= 0.0 && x[0] <= 1. && x[1] >= 0.0 && x[1] <= 1.);
}

static bool intersectTwoCircles ( SPoint2 &pA,
				  SPoint2 &pB,
				  double ra, double rb,
				  SPoint2 & p,
				  SPoint2 * _end = nullptr){

  // ** OK ** //
  double xa = pA.x();
  double xb = pB.x();
  double ya = pA.y();
  double yb = pB.y();

  if (fabs(xb-xa) < fabs(yb-ya)) {
    SPoint2 AA(pA.y(), pA.x());
    SPoint2 BB(pB.y(), pB.x());
    SPoint2 PP;
    if (_end){
      SPoint2 EE(_end->y(), _end->x());
      intersectTwoCircles(AA,BB,ra,rb,PP,&EE);
    }
    else{
      intersectTwoCircles(AA,BB,ra,rb,PP,nullptr);
    }
    p = SPoint2(PP.y(),PP.x());
    return true;
  }

  double A2 = ra*ra - xa*xa - ya*ya;
  double B2 = rb*rb - xb*xb - yb*yb;
  double a = (A2-B2)/(2*(xb-xa));
  double b = (yb-ya)/(xb-xa);

  double A = 1 + b*b;
  double B = -2*(a*b-b*xa+ya);
  double C = a*a - 2*a*xa - A2;

  double delta = B*B - 4*A*C;
  if (delta < 0) {
    printf("impossible %g %g %g %g %g %g %g\n",ra,rb,delta, pA.x(),pA.y(),pB.x(),pB.y());
    return false;
  }

  double yP = 0.5*(-B + sqrt(delta))/A;
  double yQ = 0.5*(-B - sqrt(delta))/A;
  double xP = a - b * yP;
  double xQ = a - b * yQ;

  //  double D2P = xP*xP + yP*yP;
  //  double D2Q = xQ*xQ + yQ*yQ;
  //  if (D2P < D2Q)p = SPoint2 (xP,yP);
  //  else p = SPoint2 (xQ,yQ);
  if (yP > 0 ) p = SPoint2 (xP,yP);
  else p = SPoint2 (xQ,yQ);
  return true;
  
  // ** OK ** //
  //  printf("--> %g %g -- %g %g -- %g %g %g\n",xP,yP,xQ,yQ, delta, ra, rb);

    //    printf("--> %g %g vs %g %g\n",ra,rb,pA.distance(SPoint2(xP,yP)),pB.distance(SPoint2(xP,yP)));
    //    printf("--> %g %g vs %g %g\n",ra,rb,pA.distance(SPoint2(xQ,yQ)),pB.distance(SPoint2(xQ,yQ)));
  if (_end){
    if (_end->distance (SPoint2 (xQ,yQ)) < _end->distance (SPoint2 (xP,yP))) 
      p = SPoint2 (xQ,yQ);
    else
      p = SPoint2 (xP,yP);
  }
  else{
      p = SPoint2 (xQ,yQ);
      printf("robustPredicates::orient2d (pA, pB, p) %g\n",robustPredicates::orient2d (pA, pB, p));
      if (robustPredicates::orient2d (pA, pB, p) < 0)return true; 
      p = SPoint2 (xP,yP);
  }
  return true;  
}


void IntrinsicTriangulation::test(){
  printf("triangulation with %lu faces %lu half edges %lu vertices\n",
	 extrinsic_->faces.size(),extrinsic_->hedges.size(),extrinsic_->vertices.size());

  PolyMesh::Vertex *vert = extrinsic_->vertices[extrinsic_->vertices.size()/2];
  continuousRienstra (vert, 0.0);
  return;
  
  PolyMesh::HalfEdge *he = extrinsic_->hedges[extrinsic_->hedges.size()/2];
  IntrinsicTriangulation::VertexOnFace _v;
  _v.he = he;
  _v.u = 0.2;
  _v.v = 0.3;
  for (int i=0;i<15;i++){
    double t = i*2.*M_PI/14;
    printf("t=%g\n",t);
    auto G = trace (_v, 1, t);
    G.print4debug(i);
  }
}

void IntrinsicTriangulation::Geodesic::print4debug (int id) {
  char name [245];
  sprintf(name,"Geodesic%d.pos",id);
  FILE *f = fopen (name, "w");
  fprintf(f,"View \"Geodesic %d\" {\n",id);
  SVector3 p = _start.point();
  fprintf(f,"SP(%g,%g,%g) {%d};\n",p.x(),p.y(),p.z(),id);  
  for (auto pt : _pts){
    SVector3 pp = pt.point();
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n",p.x(),p.y(),p.z(),pp.x(),pp.y(),pp.z(),id,id);  
    p = pp;
  }
  if (_end.he){
    SVector3 pp = _end.point();
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n",p.x(),p.y(),p.z(),pp.x(),pp.y(),pp.z(),id,id);  
    fprintf(f,"SP(%g,%g,%g) {%d};\n",pp.x(),pp.y(),pp.z(),id);
  }
  fprintf(f,"};\n");
  fclose(f);  
}


int IntrinsicTriangulation::continuousRienstra (PolyMesh::Vertex *v, double Lmax){

  std::set<IntrinsicTriangulation::Window> windows;
  PolyMesh::HalfEdge *he = v->he;

  FILE *f = fopen ("rienstra.pos", "w");
  fprintf(f,"View \"\"{\n");
  fprintf(f,"SP(%g,%g,%g){1};\n",v->position.x(),v->position.y(),v->position.z());
  fprintf(f,"SP(0,0,0){2};\n");
  
  // initialize with as much windows as there are triangles around vertex v
  do {
    IntrinsicTriangulation::Window w;
    SVector3 p_start = he->next->v->position;
    SVector3 p_end = he->next->next->v->position;
    SVector3 ppp = he->v->position;
    w.he = he->next;
    w.t1 = 0.65;
    w.t2 = 0.75;
    SVector3 p_w1 = p_start * (1.-w.t1) + p_end *w.t1;
    SVector3 p_w2 = p_start * (1.-w.t2) + p_end *w.t2;
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){0,0};\n",p_w1.x(),p_w1.y(),p_w1.z(),p_w2.x(),p_w2.y(),p_w2.z());
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){0,0};\n",p_w1.x(),p_w1.y(),p_w1.z(),v->position.x(),v->position.y(),v->position.z());
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){0,0};\n",p_w2.x(),p_w2.y(),p_w2.z(),v->position.x(),v->position.y(),v->position.z());
    SVector3 a1 = ppp - p_w1;
    SVector3 a2 = ppp - p_w2;    
    w.d1 = a1.norm();
    w.d2 = a2.norm();
    windows.insert(w);
    he = he->opposite;
    if(he == NULL) return -1;
    he = he->next;
    // TEST
    break;
  } while(he != v->he);

  int itx = 1;
  
  while (!windows.empty()){
    std::set<IntrinsicTriangulation::Window>::iterator it = windows.begin();
    he = it->he->opposite;
    if (he){
      SVector3 p_start = he->v->position;
      SVector3 p_end = he->next->v->position;
      SVector3 p_opposite = he->next->next->v->position;
      double d1 = it->d2;
      double d2 = it->d1;
      double t1 = 1.-it->t2;
      double t2 = 1.-it->t1;
      SVector3 p_w1 = p_start * (1.-t1) + p_end *t1;
      SVector3 p_w2 = p_start * (1.-t2) + p_end *t2;
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",p_w1.x(),p_w1.y(),p_w1.z(),p_w2.x(),p_w2.y(),p_w2.z());
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",p_w1.x(),p_w1.y(),p_w1.z(),v->position.x(),v->position.y(),v->position.z());
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",p_w2.x(),p_w2.y(),p_w2.z(),v->position.x(),v->position.y(),v->position.z());
      //      break;
      SVector3 diff = p_w2 - p_w1;
      double d3b = diff.norm();
      diff = p_start-p_end;
      double d3 = diff.norm();
      diff = p_start-p_w1;
      double d3c = diff.norm();
      double d3a = d3 - d3b - d3c;
      // DEBUG
      diff = p_end-p_w2;
      printf("%g %g -----------> %g vs %g\n",t1,t2,d3a,diff.norm());
      // DEBUG
      SPoint2 s (0,0) ;
      SPoint2 start (d1,0);
      SPoint2 p1 ;
      bool ok = intersectTwoCircles (s, start, d2, d3b, p1);
      double dir[2] = {p1.x() - start.x(), p1.y() - start.y()};
      double norm = sqrt(dir[0]*dir[0]+dir[1]*dir[1]);
      SPoint2 p2 (p1.x() + d3a*dir[0]/norm, p1.y() + d3a*dir[1]/norm);
      SPoint2 p3 (start.x() - d3c*dir[0]/norm, start.y() - d3c*dir[1]/norm);
      SPoint2 p4 ;
      double d4 = he->next->l();
      double d5 = he->next->next->l();
      //      printf("D's : %g %g %g %g %g %g %g %g\n",d1,d2,d3,d3a,d3b,d3c,d4, d5);
      ok = intersectTwoCircles (p3, p2, d5, d4, p4);      
      //      printf("p2 %g %g p3 %g %g p4 %g %g\n",p2.x(),p2.y(),p3.x(),p3.y(),p4.x(),p4.y());

      //      fprintf(f,"ST(%g,%g,0,%g,%g,0,%g,%g,0){2,3,4};\n",p2.x(),p2.y(),p3.x(),p3.y(),p4.x(),p4.y());
      //      fprintf(f,"SP(%g,%g,0){1};\n",p1.x(),p1.y());
      //      fprintf(f,"SP(%g,%g,0){0};\n",start.x(),start.y());
      
      double xi1[2];
      intersection_segments_(s, p1, p2, p4,xi1);
      double xi2[2];
      intersection_segments_(s, start, p2, p4,xi2);
      double xi3[2];
      intersection_segments_(s, p1, p4, p3,xi3);
      double xi4[2];
      intersection_segments_(s, start, p4, p3,xi4);      

      //      fprintf(f,"SP(%g,%g,0){2};\n",s.x()*(1.-xi1[0])+p1.x()*xi1[0],s.y()*(1.-xi1[0])+p1.y()*xi1[0]);
      //      fprintf(f,"SP(%g,%g,0){2};\n",s.x()*(1.-xi2[0])+start.x()*xi2[0],s.y()*(1.-xi2[0])+start.y()*xi2[0]);
      //      fprintf(f,"SP(%g,%g,0){2};\n",s.x()*(1.-xi3[0])+p1.x()*xi3[0],s.y()*(1.-xi3[0])+p1.y()*xi3[0]);
      //      fprintf(f,"SP(%g,%g,0){2};\n",s.x()*(1.-xi4[0])+start.x()*xi4[0],s.y()*(1.-xi4[0])+start.y()*xi4[0]);

      SPoint2 p11 = p1 * xi1[0];
      SPoint2 p22 = start * xi2[0];
      SPoint2 p33 = p1 * xi3[0];
      SPoint2 p44 = start * xi4[0];
      
      // create one new window on he->next
      printf("%g %g -- %g %g -- %g %g -- %g %g \n",
	     xi1[0],xi1[1],xi2[0],xi2[1],xi3[0],xi3[1],xi4[0],xi4[1]);
      if ((xi1[1] >=0 && xi1[1] <= 1)&&
	  (xi2[1] >=0 && xi2[1] <= 1)){	
	IntrinsicTriangulation::Window w;
	w.he = he->next;
	w.d1 = sqrt(p11.x()*p11.x() + p11.y()*p11.y());
	w.d2 = sqrt(p22.x()*p22.x() + p22.y()*p22.y());
	w.t1 = xi1[1];
	w.t2 = xi2[1];
	printf(" create one new window on he->next->next --> %g %g\n",w.t1,w.t2);
	windows.insert(w);
      }
      // create one new window on he->next->next
      else if ((xi3[1] >=0 && xi3[1] <= 1)&&
	       (xi4[1] >=0 && xi4[1] <= 1)){
	// OK VERIFIE
	IntrinsicTriangulation::Window w;
	w.he = he->next->next;
	w.d2 = sqrt(p44.x()*p44.x() + p44.y()*p44.y());//d1*xi4[0]
	w.d1 = sqrt(p33.x()*p33.x() + p33.y()*p33.y());//d2*xi3[0]
	//	printf("%g %g -- %g %g\n",w.d1,w.d2,d2*xi3[0],d2*xi4[0]);	       
	w.t2 = xi4[1];
	w.t1 = xi3[1];
	printf(" create one new window on he->next --> %g %g\n",w.t1,w.t2);
	windows.insert(w);
      }
      // create two windows
      // FIXME or more if point p4 is a saddle point
      else if ((xi1[1] >=0 && xi1[1] <= 1)&&
	       (xi4[1] >=0 && xi4[1] <= 1)){	
	double dd = sqrt (p4.x()*p4.x()+p4.y()*p4.y());
	printf("coucou dd %g\n",dd);
	IntrinsicTriangulation::Window w;
	w.he = he->next;
	w.d1 = sqrt(p11.x()*p11.x() + p11.y()*p11.y());
	w.d2 = dd;
	w.t1 = xi1[1];
	w.t2 = 1.0;
	windows.insert(w);
	w.he = he->next->next;
	w.d2 = sqrt(p44.x()*p44.x() + p44.y()*p44.y());
	w.d1 = dd;
	w.t1 = 0.0;
	w.t2 = xi4[1];
	windows.insert(w);
      }
    }    
    windows.erase(it);
    if (itx++ == 7) break;
  }
  fprintf(f,"};\n");
  fclose(f);
}


//#define _DEBUG___ 1

IntrinsicTriangulation::Geodesic IntrinsicTriangulation::trace (const IntrinsicTriangulation::VertexOnFace &_v,
								double L, double theta) {

  std::map<PolyMesh::Vertex*, SPoint2> P; 
  
  PolyMesh::HalfEdge *he_current = _v.he;
  SVector3 d1 = he_current->d()*he_current->l(); 
  SVector3 d2b = he_current->prev->d()*he_current->l() * -1.0; 
  SVector3  n = crossprod (d1,d2b);
  SVector3 d2 = crossprod(n,d1);
  SPoint2 p1 (0,0);
  SPoint2 p2 (d1.norm(),0);
  d1.normalize();
  d2.normalize();
  SPoint2 p3 (dot(d2b,d1),dot(d2b,d2));
  double U = _v.u;
  double V = _v.v;
  //  p1 = SPoint2(he_current->v->position.x(),he_current->v->position.y());
  //  p2 = SPoint2(he_current->next->v->position.x(),he_current->next->v->position.y());
  //  p3 = SPoint2(he_current->next->next->v->position.x(),he_current->next->next->v->position.y());
  SPoint2 _start   = p1*(1.- U - V) + p2*U + p3*V;  
  SPoint2 _end (_start.x() + L * cos(theta), _start.y() + L * sin(theta)); 
  P[he_current->v]  = p1;
  P[he_current->next->v]  = p2;
  P[he_current->next->next->v]  = p3;
  
#ifdef _DEBUG___
  FILE *f = fopen("trace.pos","w");
  fprintf(f,"View \"trace\"{\n");
  
  printf("starting with triangle %g %g , %g %g, %g %g\n",p1.x(),p1.y(),p2.x(),p2.y(),p3.x(),p3.y());
  printf("end point %g %g\n",_end.x(),_end.y());

  fprintf(f,"ST(%g,%g,0,%g,%g,0,%g,%g,0){1,1,1};\n",p1.x(),p1.y(),p2.x(),p2.y(),p3.x(),p3.y());
  fprintf(f,"SP(%g,%g,0){2};\n",_end.x(),_end.y());
  fprintf(f,"SL(%g,%g,0,%g,%g,0){3,3};\n",_start.x(),_start.y(), _end.x(),_end.y());
#endif //_DEBUG___
  
  
  double XI[2];
  if (intersection_segments_(p2, p1, _start,_end,XI)){
    he_current = he_current->opposite;
  }
  else if (intersection_segments_(p3, p2, _start,_end,XI)){
    he_current  = he_current->next->opposite;
  }
  else if (intersection_segments_(p1, p3, _start,_end,XI)){
    he_current  = he_current->next->next->opposite;
  }
  else {
    printf("strange\n");
    //    getchar();
  }

  
  IntrinsicTriangulation::Geodesic G;
  G._start = _v;
  G._end.he = nullptr;
  
  IntrinsicTriangulation::VertexOnEdge ve;
  ve.he = he_current;
  ve.t = XI[0];
  G._pts.push_back(ve);      
  
#ifdef _DEBUG___
  int iter = 0;
#endif

  while (1){
    std::map<PolyMesh::Vertex*, SPoint2>::iterator it1 = P.find(he_current->v);
    std::map<PolyMesh::Vertex*, SPoint2>::iterator it2 = P.find(he_current->next->v);
    if (it1 == P.end())printf("pas normal\n");
    if (it2 == P.end())printf("pas normal\n");
    p1 = P[he_current->v];
    p2 = P[he_current->next->v];
    SPoint2 ppp;
    double r1 = he_current->next->next->l();
    double r2 = he_current->next->l();
    bool ok = intersectTwoCircles ( p1, p2, r1, r2, ppp , &_end);
    if (!ok)return G; 
    P[he_current->next->next->v] = ppp;

    //    printf("%g %g -- %g %g \n", he_current->next->next->v->position.x(),he_current->next->next->v->position.y(),
    //	   ppp.x(),ppp.y());
    //    getchar();

    
    double a = robustPredicates::orient2d(p1, p2, _end);
    double b = robustPredicates::orient2d(p2, ppp, _end);
    double c = robustPredicates::orient2d(ppp, p1 , _end);
    if (a*c > 0 && b*c > 0){
      G._end.he = he_current;
      G._end.u = c/(a+b+c);
      G._end.v = a/(a+b+c);
#ifdef _DEBUG___
      fprintf(f,"};\n");
      fclose(f);
#endif
      return G;
    }

    if (intersection_segments_(p1, ppp,_start,_end,XI)){
      he_current = he_current->next->next->opposite;
    }
    else if (intersection_segments_(ppp, p2,_start,_end,XI)){
      he_current = he_current->next->opposite;
    }
    else {
      he_current = nullptr;
      printf("strange\n");
    }
    if (he_current == nullptr){
#ifdef _DEBUG___
      fprintf(f,"};\n");
      fclose(f);
#endif// _DEBUG___
      return G;
    }
    
    IntrinsicTriangulation::VertexOnEdge ve;
    ve.he = he_current;
    ve.t = XI[0];
    G._pts.push_back(ve);    
    
#ifdef _DEBUG___
    fprintf(f,"ST(%g,%g,0,%g,%g,0,%g,%g,0){%d,%d,%d};\n",p1.x(),p1.y(),p2.x(),p2.y(),ppp.x(),ppp.y(), iter,iter,iter++);
#endif// _DEBUG___
  }  
#ifdef _DEBUG___
  fprintf(f,"};\n");
  fclose(f);
#endif// _DEBUG___
  return G;
}
