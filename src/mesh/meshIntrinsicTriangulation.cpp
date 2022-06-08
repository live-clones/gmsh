#include "meshIntrinsicTriangulation.h"
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

// FIXME should be more robust
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

bool intersectTwoCircles ( SPoint2 &pA,
			   SPoint2 &pB,
			   double ra, double rb,
			   SPoint2 & p,
			   SPoint2 & q){
  double xa = pA.x();
  double xb = pB.x();
  double ya = pA.y();
  double yb = pB.y();

  // FIXME : should work
  if (fabs(xb-xa) < fabs(yb-ya)) {
    SPoint2 AA(pA.y(), pA.x());
    SPoint2 BB(pB.y(), pB.x());
    SPoint2 PP, QQ;
    intersectTwoCircles(AA,BB,ra,rb,PP,QQ);
    q = SPoint2(PP.y(),PP.x());
    p = SPoint2(QQ.y(),QQ.x());
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

  p = SPoint2 (xP,yP);
  q = SPoint2 (xQ,yQ);
  //  printf("robustPredicates::orient2d (pA, pB, p) %g\n",robustPredicates::orient2d (pA, pB, p));
  //  printf("robustPredicates::orient2d (pA, pB, q) %g\n",robustPredicates::orient2d (pA, pB, q));
  if (robustPredicates::orient2d (pA, pB, p) < 0)return true; 
  p = SPoint2 (xQ,yQ);
  q = SPoint2 (xP,yP);
  return true;  
}


void IntrinsicTriangulation::test(){
  printf("triangulation with %lu faces %lu half edges %lu vertices\n",
	 extrinsic_->faces.size(),extrinsic_->hedges.size(),extrinsic_->vertices.size());

  PolyMesh::Vertex *vert = extrinsic_->vertices[extrinsic_->vertices.size()-2];
  IntrinsicTriangulation::DistanceField df;
  continuousRienstra (vert, 0.0, df );
  df.print("distanceField.pos");
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


int IntrinsicTriangulation::continuousRienstra (PolyMesh::Vertex *v, double Lmax, IntrinsicTriangulation::DistanceField &df){

  std::set<IntrinsicTriangulation::Window> windows;
  PolyMesh::HalfEdge *he = v->he;

  //  printf("point %d\n",v->data);
  
  FILE *f = fopen ("rienstra.pos", "w");
  fprintf(f,"View \"\"{\n");
  fprintf(f,"SP(%g,%g,%g){1};\n",v->position.x(),v->position.y(),v->position.z());
  //  fprintf(f,"SP(0,0,0){2};\n");
  
  // initialize with as much windows as there are triangles around vertex v
  do {
    IntrinsicTriangulation::Window w;
    SVector3 p_start = he->next->v->position;
    SVector3 p_end = he->next->next->v->position;
    SVector3 ppp = he->v->position;
    w.he = he->next;
    w.t1 = 0.00000;
    w.t2 = 1.0;
    SVector3 p_w1 = p_start * (1.-w.t1) + p_end *w.t1;
    SVector3 p_w2 = p_start * (1.-w.t2) + p_end *w.t2;
    SVector3 a1 = ppp - p_w1;
    SVector3 a2 = ppp - p_w2;    
    w.d1 = a1.norm();
    w.d2 = a2.norm();
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",p_w1.x(),p_w1.y(),p_w1.z(),p_w2.x(),p_w2.y(),p_w2.z(),w.d1,w.d2);
    //    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){0,0};\n",p_w1.x(),p_w1.y(),p_w1.z(),v->position.x(),v->position.y(),v->position.z());
    //    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){0,0};\n",p_w2.x(),p_w2.y(),p_w2.z(),v->position.x(),v->position.y(),v->position.z());
    windows.insert(w);
    df.addWindow(w);
    he = he->opposite;
    if(he == NULL) return -1;
    he = he->next;
    // TEST
    //    break;
  } while(he != v->he);

  int itx = 1;
  
  while (!windows.empty()){
    std::set<IntrinsicTriangulation::Window>::iterator it = windows.begin();
    he = it->he->opposite;
    if (he){
      //      printf("half edge %d %d opposite %d\n",he->v->data,he->next->v->data,he->next->next->v->data);
      SVector3 p_start = he->v->position;
      SVector3 p_end = he->next->v->position;
      SVector3 p_opposite = he->next->next->v->position;
      double d1 = it->d2;
      double d2 = it->d1;
      double t1 = 1.-it->t2;
      double t2 = 1.-it->t1;
      //      printf("================> half edge %d %d (%g %g) (%g %g)\n",he->v->data,he->next->v->data,t1,t2,d1,d2);
      SVector3 p_w1 = p_start * (1.-t1) + p_end *t1;
      SVector3 p_w2 = p_start * (1.-t2) + p_end *t2;
      //      SVector3 xx1 = p_w1 - v->position;
      //      SVector3 xx2 = p_w2 - v->position;
      //      printf("%12.5E %12.5E and %12.5E %12.5E \n",d1,xx1.norm(),d2,xx2.norm());
      //      if (itx <= 11112){
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",p_w1.x(),p_w1.y(),p_w1.z(),p_w2.x(),p_w2.y(),p_w2.z(),d1,d2);
	//fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",p_w1.x(),p_w1.y(),p_w1.z(),v->position.x(),v->position.y(),v->position.z());
	//	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1,1};\n",p_w2.x(),p_w2.y(),p_w2.z(),v->position.x(),v->position.y(),v->position.z());
      //      }
      //      break;
      SVector3 diff = p_w2 - p_w1;
      double d3b = diff.norm();
      diff = p_start-p_end;
      double d3 = diff.norm();
      diff = p_start-p_w1;
      double d3c = diff.norm();
      double d3a = d3 - d3b - d3c;
      // DEBUG
      //      diff = p_end-p_w2;
      //      printf("%g %g -----------> %g vs %g\n",t1,t2,d3a,diff.norm());
      // DEBUG
      SPoint2 s (0,0) ;
      SPoint2 start (d1,0);
      SPoint2 p1 , wrong;
      bool ok = intersectTwoCircles (start, s, d3b, d2, p1, wrong);
      double dir[2] = {p1.x() - start.x(), p1.y() - start.y()};
      double norm = sqrt(dir[0]*dir[0]+dir[1]*dir[1]);
      SPoint2 p2 (p1.x() + d3a*dir[0]/norm, p1.y() + d3a*dir[1]/norm);
      SPoint2 p3 (start.x() - d3c*dir[0]/norm, start.y() - d3c*dir[1]/norm);
      SPoint2 p4 ;
      double d4 = he->next->l();
      double d5 = he->next->next->l();
      //      printf("D's : %g %g %g %g %g %g %g %g\n",d1,d2,d3,d3a,d3b,d3c,d4, d5);
      ok = intersectTwoCircles (p3, p2, d5, d4, p4, wrong);      
      //      printf("p2 %g %g p3 %g %g p4 %g %g\n",p2.x(),p2.y(),p3.x(),p3.y(),p4.x(),p4.y());
      SVector3 dd1 (p_w1.x() -v->position.x(),p_w1.y() -v->position.y(),0);dd1.normalize();
      SVector3 dd2 (-dd1.y(), dd1.x(), 0);
      /*      if (itx <= -1112){
	fprintf(f,"ST(%g,%g,0,%g,%g,0,%g,%g,0){2,3,4};\n",p_start.x(),p_start.y(),p_end.x(),p_end.y(),
	      v->position.x()+p4.x()*dd1.x()+p4.y()*dd2.x(),
	      v->position.y()+p4.x()*dd1.y()+p4.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){0};\n",
		v->position.x()+start.x()*dd1.x()+start.y()*dd2.x(),
		v->position.y()+start.x()*dd1.y()+start.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){-1};\n",
		v->position.x()+p1.x()*dd1.x()+p1.y()*dd2.x(),
		v->position.y()+p1.x()*dd1.y()+p1.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){-2};\n",
		v->position.x()+p2.x()*dd1.x()+p2.y()*dd2.x(),
		v->position.y()+p2.x()*dd1.y()+p2.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){-3};\n",
		v->position.x()+p3.x()*dd1.x()+p3.y()*dd2.x(),
		v->position.y()+p3.x()*dd1.y()+p3.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){-4};\n",
		v->position.x()+p4.x()*dd1.x()+p4.y()*dd2.x(),
		v->position.y()+p4.x()*dd1.y()+p4.y()*dd2.y());
	//	fprintf(f,"SP(%g,%g,0){-14};\n",
	//		v->position.x()+wrong.x()*dd1.x()+wrong.y()*dd2.x(),
	//		v->position.y()+wrong.x()*dd1.y()+wrong.y()*dd2.y());
      }
      //      fprintf(f,"SP(%g,%g,0){1};\n",p1.x(),p1.y());
      //      fprintf(f,"SP(%g,%g,0){0};\n",start.x(),start.y());
      */
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
      /*
      if (itx <= -1111112){
	fprintf(f,"SP(%g,%g,0){10};\n",
		v->position.x()+p11.x()*dd1.x()+p11.y()*dd2.x(),
		v->position.y()+p11.x()*dd1.y()+p11.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){11};\n",
		v->position.x()+p22.x()*dd1.x()+p22.y()*dd2.x(),
		v->position.y()+p22.x()*dd1.y()+p22.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){12};\n",
		v->position.x()+p33.x()*dd1.x()+p33.y()*dd2.x(),
		v->position.y()+p33.x()*dd1.y()+p33.y()*dd2.y());
	fprintf(f,"SP(%g,%g,0){13};\n",
		v->position.x()+p44.x()*dd1.x()+p44.y()*dd2.x(),
		v->position.y()+p44.x()*dd1.y()+p44.y()*dd2.y());
      }
      */
	// create one new window on he->next
      //      printf("%g %g -- %g %g -- %g %g -- %g %g \n",
      //	     xi1[0],xi1[1],xi2[0],xi2[1],xi3[0],xi3[1],xi4[0],xi4[1]);
      // create two windows
      // FIXME or more if point p4 is a saddle point
      if ((xi1[1] >=-IntrinsicTriangulation::EPS() && xi1[1] <= 1+IntrinsicTriangulation::EPS())&&
	  (xi2[1] >=-IntrinsicTriangulation::EPS() && xi2[1] <= 1+IntrinsicTriangulation::EPS())){	
	IntrinsicTriangulation::Window w;
	//	printf("ITXX %d -- CASE 0 \n",itx);
	w.he = he->next;
	w.d1 = sqrt(p11.x()*p11.x() + p11.y()*p11.y());
	w.d2 = sqrt(p22.x()*p22.x() + p22.y()*p22.y());
	w.t1 = xi1[1];
	w.t2 = xi2[1];
	//	if (w.he->v->data == 46 && w.he->next->v->data == 31)printf(" (CASE 0) create one new window (%lu) on %d %d lengths %g %g\n",windows.size(),w.he->v->data,w.he->next->v->data,w.d1,w.d2);
	df.addWindow(w);
	if (w.d1 >= -IntrinsicTriangulation::EPS())
	  windows.insert(w);
      }
      // create one new window on he->next->next
      else if ((xi3[1] >=-IntrinsicTriangulation::EPS() && xi3[1] <= 1+IntrinsicTriangulation::EPS())&&
	       (xi4[1] >=-IntrinsicTriangulation::EPS() && xi4[1] <= 1+IntrinsicTriangulation::EPS())){
	// OK VERIFIE
	//	printf("ITXX %d -- CASE 1 \n",itx);
	IntrinsicTriangulation::Window w;
	w.he = he->next->next;
	w.d2 = sqrt(p44.x()*p44.x() + p44.y()*p44.y());//d1*xi4[0]
	w.d1 = sqrt(p33.x()*p33.x() + p33.y()*p33.y());//d2*xi3[0]
	//	printf("%g %g -- %g %g\n",w.d1,w.d2,d2*xi3[0],d2*xi4[0]);	       
	w.t2 = xi4[1];
	w.t1 = xi3[1];
	//	if (w.he->v->data == 46 && w.he->next->v->data == 31)printf(" (CASE 1) create one new window on %d %d lengths %g %g t's %g %g\n",w.he->v->data,w.he->next->v->data,w.d1,w.d2,w.t1,w.t2 );
	df.addWindow(w);
	if (w.d1 >= -IntrinsicTriangulation::EPS())windows.insert(w);
      }
      else if ((xi1[1] >=-IntrinsicTriangulation::EPS() && xi1[1] <= 1+IntrinsicTriangulation::EPS())&&
	       (xi4[1] >=-IntrinsicTriangulation::EPS() && xi4[1] <= 1+IntrinsicTriangulation::EPS())){	
	double dd = sqrt (p4.x()*p4.x()+p4.y()*p4.y());
	//	printf("ITXX %d -- CASE 2 \n",itx);
	IntrinsicTriangulation::Window w;
	w.he = he->next;
	w.d1 = sqrt(p11.x()*p11.x() + p11.y()*p11.y());
	w.d2 = dd;
	w.t1 = xi1[1];
	w.t2 = 1.0;
	df.addWindow(w);
	if (w.d1 >= -IntrinsicTriangulation::EPS())windows.insert(w);
	w.he = he->next->next;
	w.d2 = sqrt(p44.x()*p44.x() + p44.y()*p44.y());
	w.d1 = dd;
	w.t1 = 0.0;
	w.t2 = xi4[1];
	df.addWindow(w);
	if (w.d1 >= -IntrinsicTriangulation::EPS())windows.insert(w);
      }
    }    
    windows.erase(it);
    if (itx++ == 400) break;
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
    SPoint2 ppp, qqq;
    double r1 = he_current->next->next->l();
    double r2 = he_current->next->l();
    bool ok = intersectTwoCircles ( p1, p2, r1, r2, ppp , qqq);
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
