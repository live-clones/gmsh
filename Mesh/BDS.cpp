// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include <stdio.h>
#include "Numeric.h"
#include "BDS.h"
#include "Message.h"
#include "GFace.h"
#include "meshGFaceDelaunayInsertion.h"
#include "qualityMeasures.h"

bool test_move_point_parametric_triangle(BDS_Point *p, double u, double v, BDS_Face *t);
bool test_move_point_parametric_quad(BDS_Point *p, double u, double v, BDS_Face *t);

void outputScalarField(std::list<BDS_Face*> t, const char *iii, int param, GFace *gf)
{
  FILE *f = fopen(iii, "w");
  if(!f) return;
  fprintf(f, "View \"scalar\" {\n");
  std::list<BDS_Face*>::iterator tit = t.begin();
  std::list<BDS_Face*>::iterator tite = t.end();
  while(tit != tite) {
    BDS_Point *pts[4];
    if (!(*tit)->deleted){
      (*tit)->getNodes(pts);
      if(param)
	fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
		pts[0]->u, pts[0]->v, 0.0,
		pts[1]->u, pts[1]->v, 0.0,
		pts[2]->u, pts[2]->v, 0.0,
		pts[0]->iD, pts[1]->iD, pts[2]->iD);
      else{
	if(!gf){
	  if (pts[3]){
	    fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
		    pts[0]->X, pts[0]->Y, pts[0]->Z,
		    pts[1]->X, pts[1]->Y, pts[1]->Z,
		    pts[2]->X, pts[2]->Y, pts[2]->Z, 
		    pts[3]->X, pts[3]->Y, pts[3]->Z, 
		    pts[0]->iD, pts[1]->iD, pts[2]->iD, pts[3]->iD);
	  }
	  else{
	    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
		    pts[0]->X, pts[0]->Y, pts[0]->Z,
		    pts[1]->X, pts[1]->Y, pts[1]->Z,
		    pts[2]->X, pts[2]->Y, pts[2]->Z, 
		    pts[0]->iD, pts[1]->iD, pts[2]->iD);
	  }
	}
	else{
	  if (pts[3]){
	    fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
		    pts[0]->X, pts[0]->Y, pts[0]->Z,
		    pts[1]->X, pts[1]->Y, pts[1]->Z,
		    pts[2]->X, pts[2]->Y, pts[2]->Z,
		    pts[3]->X, pts[3]->Y, pts[3]->Z,
		    gf->curvature(SPoint2(pts[0]->u, pts[0]->v)),
		    gf->curvature(SPoint2(pts[1]->u, pts[1]->v)),	
		    gf->curvature(SPoint2(pts[2]->u, pts[2]->v)),
		    gf->curvature(SPoint2(pts[3]->u, pts[3]->v)));
	  }
	  else{
	    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
		    pts[0]->X, pts[0]->Y, pts[0]->Z,
		    pts[1]->X, pts[1]->Y, pts[1]->Z,
		    pts[2]->X, pts[2]->Y, pts[2]->Z,
		    gf->curvature(SPoint2(pts[0]->u, pts[0]->v)),
		    gf->curvature(SPoint2(pts[1]->u, pts[1]->v)),
		    gf->curvature(SPoint2(pts[2]->u, pts[2]->v)));
	  }
	}
      }
    }
    ++tit;
  }
  fprintf(f, "};\n");
  fclose(f);
}

BDS_Vector::BDS_Vector(const BDS_Point &p2, const BDS_Point &p1)
  :x(p2.X - p1.X), y(p2.Y - p1.Y), z(p2.Z - p1.Z)
{
}

void vector_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                     double c[3])
{
  double a[3] = {p1->X - p2->X, p1->Y - p2->Y, p1->Z - p2->Z};
  double b[3] = {p1->X - p3->X, p1->Y - p3->Y, p1->Z - p3->Z};
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

void vector_triangle_parametric(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                                double &c)
{
  double a[2] = {p1->u - p2->u, p1->v - p2->v};
  double b[2] = {p1->u - p3->u, p1->v - p3->v};
  c = a[0] * b[1] - a[1] * b[0];
}

void normal_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                     double c[3])
{
  vector_triangle(p1, p2, p3, c);
  norme(c);
}

double surface_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3)
{
  double c[3];
  vector_triangle(p1, p2, p3, c);
  return 0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
}

double surface_triangle_param(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3)
{
  double c;
  vector_triangle_parametric(p1, p2, p3, c);
  return (0.5 * c);
}

void BDS_Point::getTriangles(std::list<BDS_Face*> &t) const
{
  t.clear();
  std::list<BDS_Edge*>::const_iterator it = edges.begin();
  std::list<BDS_Edge*>::const_iterator ite = edges.end();
  while(it != ite) {
    int NF = (*it)->numfaces();
    for(int i = 0; i < NF; ++i) {
      BDS_Face *tt = (*it)->faces(i);
      if(tt) {
        std::list<BDS_Face*>::iterator tit = t.begin();
        std::list<BDS_Face*>::iterator tite = t.end();
        int found = 0;
        while(tit != tite) {
          if(tt == *tit)
            found = 1;
          ++tit;
        }
        if(!found)
          t.push_back(tt);
      }
    }
    ++it;
  }
}

BDS_Point *BDS_Mesh::add_point(int num, double x, double y, double z)
{
  BDS_Point *pp = new BDS_Point(num, x, y, z);
  points.insert(pp);
  MAXPOINTNUMBER = (MAXPOINTNUMBER < num) ? num : MAXPOINTNUMBER;
  return pp;
}

BDS_Point *BDS_Mesh::add_point(int num, double u, double v, GFace *gf)
{  
  GPoint gp = gf->point(u*scalingU,v*scalingV);  
  BDS_Point *pp = new BDS_Point(num, gp.x(), gp.y(), gp.z());
  pp->u = u;
  pp->v = v;
  points.insert(pp);
  MAXPOINTNUMBER = (MAXPOINTNUMBER < num) ? num : MAXPOINTNUMBER;
  return pp;
}

BDS_Point *BDS_Mesh::find_point(int p)
{
  BDS_Point P(p);
  std::set < BDS_Point *, PointLessThan >::iterator it = points.find(&P);
  if(it != points.end())
    return (BDS_Point*)(*it);
  else
    return 0;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p, int num2)
{
  std::list<BDS_Edge*>::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if((*eit)->p1 == p && (*eit)->p2->iD == num2)
      return (*eit);
    if((*eit)->p2 == p && (*eit)->p1->iD == num2)
      return (*eit);
    ++eit;
  }
  return 0;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p1, BDS_Point *p2)
{
  return find_edge(p1, p2->iD);
}

BDS_Edge *BDS_Mesh::find_edge(int num1, int num2)
{
  BDS_Point *p = find_point(num1);
  return find_edge(p, num2);
}

int Intersect_Edges_2d(double x1, double y1, double x2, double y2,
                       double x3, double y3, double x4, double y4,double x[2])
{

//   double p1[2] = {x1,y1};
//   double p2[2] = {x2,y2};
//   double q1[2] = {x3,y3};
//   double q2[2] = {x4,y4};
  
//   double rp1 = gmsh::orient2d(p1, p2, q1);
//   double rp2 = gmsh::orient2d(p1, p2, q2);
//   double rq1 = gmsh::orient2d(q1, q2, p1);
//   double rq2 = gmsh::orient2d(q1, q2, p2);

//   if(rp1*rp2<=0 && rq1*rq2<=0){
// //      printf("p1 %22.15E %22.15E %22.15E %22.15E \n",x1,y1,x2,y2);
// //      printf("p2 %22.15E %22.15E %22.15E %22.15E \n",x3,y3,x4,y4);
// //      printf("or %22.15E %22.15E %22.15E %22.15E\n",rp1,rp2,rq1,rq2);
//     return 1;
//   }
//   return 0;

  double mat[2][2];
  double rhs[2];
  mat[0][0] = (x2 - x1);
  mat[0][1] = -(x4 - x3);
  mat[1][0] = (y2 - y1);
  mat[1][1] = -(y4 - y3);
  rhs[0] = x3 - x1;
  rhs[1] = y3 - y1;
  if(!sys2x2(mat, rhs, x))
    return 0;
  if(x[0] >= 0.0 && x[0] <= 1.0 && x[1] >= 0.0 && x[1] <= 1.0)
    return 1;
  return 0;
}

BDS_Edge *BDS_Mesh::recover_edge_fast(BDS_Point *p1, BDS_Point *p2){
  
  std::list<BDS_Face*> ts;
  p1->getTriangles(ts);
  std::list<BDS_Face*>::iterator it = ts.begin();
  std::list<BDS_Face*>::iterator ite = ts.end();
  while(it != ite) {
    BDS_Face *t = *it;
    if (!t->e4){
      BDS_Edge *e= t->oppositeEdge (p1);
      BDS_Face *f= e->otherFace (t);
      if (!f->e4){
	BDS_Point *p2b = f->oppositeVertex(e);
	if (p2 == p2b){
	  if (swap_edge(e, BDS_SwapEdgeTestQuality(false,false))){
	    printf("coucou\n");
	    return find_edge (p1,p2->iD);
	  }
	}
      }
    }
    ++it;
  }
  return 0;
}

BDS_Edge *BDS_Mesh::recover_edge(int num1, int num2, std::set<EdgeToRecover> *e2r, 
                                 std::set<EdgeToRecover> *not_recovered)
{
  BDS_Edge *e = find_edge(num1, num2);

  if(e) return e;

  BDS_Point *p1 = find_point(num1);
  BDS_Point *p2 = find_point(num2);
  
  if(!p1 || !p2) {
    Msg::Fatal("Could not find points %d or %d in BDS mesh", num1, num2);
    return 0;
  }

  Msg::Debug("edge %d %d has to be recovered", num1, num2);
  
  int ix = 0;
  int ixMax = 300;
  double x[2];
  while(1){
    std::vector<BDS_Edge*> intersected;
    std::list<BDS_Edge*>::iterator it = edges.begin();

    bool selfIntersection = false;

    while(it != edges.end()){
      e = (*it);
      if(!e->deleted && e->p1 != p1 && e->p1 != p2 && e->p2 != p1 && e->p2 != p2)
	if(Intersect_Edges_2d(e->p1->u, e->p1->v,
			      e->p2->u, e->p2->v,
			      p1->u, p1->v,
			      p2->u, p2->v,x)){
	  // intersect
	  if(e2r && e2r->find(EdgeToRecover(e->p1->iD, e->p2->iD, 0)) != e2r->end()){
	    std::set<EdgeToRecover>::iterator itr1 = 
	      e2r->find(EdgeToRecover(e->p1->iD, e->p2->iD, 0));		    
	    std::set<EdgeToRecover>::iterator itr2 = 
	      e2r->find(EdgeToRecover(num1, num2, 0));
	    Msg::Debug("edge %d %d on model edge %d cannot be recovered because"
		" it intersects %d %d on model edge %d", num1, num2, itr2->ge->tag(),
		e->p1->iD, e->p2->iD, itr1->ge->tag());
	    // now throw a class that contains the diagnostic
	    not_recovered->insert(EdgeToRecover(num1, num2, itr2->ge));
	    not_recovered->insert(EdgeToRecover(e->p1->iD, e->p2->iD, itr1->ge));
	    selfIntersection = true;
	  }
	  if (e->numfaces() != e->numTriangles())return 0;
	  intersected.push_back(e);	  
	}
      ++it;
    }

    if (selfIntersection)return 0;

//   if(ix > 300){
//     Msg::Warning("edge %d %d cannot be recovered after %d iterations, trying again",
//        num1, num2, ix);      
//     ix = 0;
//   }
//   printf("%d %d\n",intersected.size(),ix);
      
    if(!intersected.size() || ix > 1000){
      BDS_Edge *eee = find_edge(num1, num2);
      if(!eee){
	outputScalarField(triangles, "debugp.pos", 1);
	outputScalarField(triangles, "debugr.pos", 0);
	Msg::Debug("edge %d %d cannot be recovered at all, look at debugp.pos "
	    "and debugr.pos", num1, num2);
	return 0;
      }
      return eee;
    }
    
    int ichoice = ix++ % intersected.size();
    bool success = swap_edge(intersected[ichoice], BDS_SwapEdgeTestQuality(false, false));
    // printf("trying to swop %d %d = %d (%d %d)\n", intersected[ichoice]->p1->iD,
    //        intersected[ichoice]->p2->iD, success, intersected[ichoice]->deleted,
    //        intersected[ichoice]->numfaces());
  }
  return 0;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p1, BDS_Point *p2, BDS_Face *t) const
{
  BDS_Point P1(p1->iD);
  BDS_Point P2(p2->iD);
  BDS_Edge E(&P1, &P2);
  if(t->e1->p1->iD == E.p1->iD && t->e1->p2->iD == E.p2->iD)
    return t->e1;
  if(t->e2->p1->iD == E.p1->iD && t->e2->p2->iD == E.p2->iD)
    return t->e2;
  if(t->e3->p1->iD == E.p1->iD && t->e3->p2->iD == E.p2->iD)
    return t->e3;
  return 0;
}

BDS_Face *BDS_Mesh::find_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3)
{
  int i;
  for(i = 0; i < e1->numfaces(); i++) {
    BDS_Face *t = e1->faces(i);
    BDS_Edge *o1 = t->e1;
    BDS_Edge *o2 = t->e2;
    BDS_Edge *o3 = t->e3;
    if((o1 == e1 && o2 == e2 && o3 == e3) ||
       (o1 == e1 && o2 == e3 && o3 == e2) ||
       (o1 == e2 && o2 == e1 && o3 == e3) ||
       (o1 == e2 && o2 == e3 && o3 == e1) ||
       (o1 == e3 && o2 == e1 && o3 == e2) ||
       (o1 == e3 && o2 == e2 && o3 == e1))
      return t;
  }
  for(i = 0; i < e2->numfaces(); i++) {
    BDS_Face *t = e2->faces(i);
    BDS_Edge *o1 = t->e1;
    BDS_Edge *o2 = t->e2;
    BDS_Edge *o3 = t->e3;
    if((o1 == e1 && o2 == e2 && o3 == e3) ||
       (o1 == e1 && o2 == e3 && o3 == e2) ||
       (o1 == e2 && o2 == e1 && o3 == e3) ||
       (o1 == e2 && o2 == e3 && o3 == e1) ||
       (o1 == e3 && o2 == e1 && o3 == e2) ||
       (o1 == e3 && o2 == e2 && o3 == e1))
      return t;
  }
  for(i = 0; i < e3->numfaces(); i++) {
    BDS_Face *t = e3->faces(i);
    BDS_Edge *o1 = t->e1;
    BDS_Edge *o2 = t->e2;
    BDS_Edge *o3 = t->e3;
    if((o1 == e1 && o2 == e2 && o3 == e3) ||
       (o1 == e1 && o2 == e3 && o3 == e2) ||
       (o1 == e2 && o2 == e1 && o3 == e3) ||
       (o1 == e2 && o2 == e3 && o3 == e1) ||
       (o1 == e3 && o2 == e1 && o3 == e2) ||
       (o1 == e3 && o2 == e2 && o3 == e1))
      return t;
  }
  return 0;
}

BDS_Edge *BDS_Mesh::add_edge(int p1, int p2)
{
  BDS_Edge *efound = find_edge(p1, p2);
  if(efound) return efound;

  BDS_Point *pp1 = find_point(p1);
  BDS_Point *pp2 = find_point(p2);
  if(!pp1 || !pp2){
    Msg::Fatal("Could not find points %d or %d in BDS mesh", p1, p2);
    return 0;
  }
  BDS_Edge *e = new BDS_Edge(pp1, pp2);
  edges.push_back(e);
  return e;
}

BDS_Face *BDS_Mesh::add_triangle(int p1, int p2, int p3)
{
  BDS_Edge *e1 = add_edge(p1, p2);
  BDS_Edge *e2 = add_edge(p2, p3);
  BDS_Edge *e3 = add_edge(p3, p1);
  return add_triangle(e1, e2, e3);
}

BDS_Face *BDS_Mesh::add_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3)
{
  // BDS_Face *tfound = find_triangle(e1, e2, e3);
  // if(tfound) return tfound;
  
  BDS_Face *t = new BDS_Face(e1, e2, e3);
  triangles.push_back(t);
  return t;
}

BDS_Face *BDS_Mesh::add_quadrangle(BDS_Edge *e1, BDS_Edge *e2,
                                   BDS_Edge *e3, BDS_Edge *e4)
{
  BDS_Face *t = new BDS_Face(e1, e2, e3, e4);
  triangles.push_back(t);
  return t;
}

void BDS_Mesh::del_face(BDS_Face *t)
{
  t->e1->del(t);
  t->e2->del(t);
  t->e3->del(t);
  if(t->e4) t->e4->del(t);
  t->deleted = true;
}

void BDS_Mesh::del_edge(BDS_Edge *e)
{
  e->p1->del(e);
  e->p2->del(e);
  e->deleted = true;
}

void BDS_Mesh::del_point(BDS_Point *p)
{
  points.erase(p);
  delete p;
}

void BDS_Mesh::add_geom(int p1, int p2)
{
  geom.insert(new BDS_GeomEntity(p1, p2));
}

void BDS_Edge::oppositeof(BDS_Point *oface[2]) const
{
  oface[0] = oface[1] = 0;
  if(faces(0)) {
    BDS_Point *pts[4];
    faces(0)->getNodes(pts);
    if(pts[0] != p1 && pts[0] != p2)
      oface[0] = pts[0];
    else if(pts[1] != p1 && pts[1] != p2)
      oface[0] = pts[1];
    else
      oface[0] = pts[2];
  }
  if(faces(1)) {
    BDS_Point *pts[4];
    faces(1)->getNodes(pts);
    if(pts[0] != p1 && pts[0] != p2)
      oface[1] = pts[0];
    else if(pts[1] != p1 && pts[1] != p2)
      oface[1] = pts[1];
    else
      oface[1] = pts[2];
  }
}

BDS_GeomEntity *BDS_Mesh::get_geom(int p1, int p2)
{
  BDS_GeomEntity ge(p1, p2);
  std::set < BDS_GeomEntity *, GeomLessThan >::iterator it = geom.find(&ge);
  if(it == geom.end()) return 0;
  return (BDS_GeomEntity*)(*it);
}

void recur_tag(BDS_Face *t, BDS_GeomEntity *g)
{
  if(!t->g) {
    t->g = g;
    // g->t.push_back(t);
    if(!t->e1->g && t->e1->numfaces() == 2) {
      recur_tag(t->e1->otherFace(t), g);
    }
    if(!t->e2->g && t->e2->numfaces() == 2) {
      recur_tag(t->e2->otherFace(t), g);
    }
    if(!t->e3->g && t->e3->numfaces() == 2) {
      recur_tag(t->e3->otherFace(t), g);
    }
  }
}

double PointLessThanLexicographic::t = 0;
double BDS_Vector::t = 0;

template < class IT > void DESTROOOY(IT beg, IT end)
{
  while(beg != end) {
    delete *beg;
    beg++;
  }
}

void BDS_Mesh::cleanup()
{
  {
    std::list<BDS_Face*>::iterator it = triangles.begin();
    while(it != triangles.end()){
      if((*it)->deleted){
        delete *it;
        it = triangles.erase(it);
      }
      else
        it++;
    }
  }
  { 
    std::list<BDS_Edge*>::iterator it = edges.begin();
    while(it != edges.end()){
      if((*it)->deleted){
        delete *it;
        it = edges.erase(it);
      } 
      else
        it++;
    }      
  } 
}

BDS_Mesh::~BDS_Mesh()
{
   DESTROOOY(geom.begin(), geom.end());
   DESTROOOY(points.begin(), points.end());
   cleanup();
   DESTROOOY(edges.begin(), edges.end());
   DESTROOOY(triangles.begin(), triangles.end());
}

bool BDS_Mesh::split_face(BDS_Face *f, BDS_Point *mid)
{
  BDS_Point *p1 = f->e1->commonvertex(f->e2); 
  BDS_Point *p2 = f->e3->commonvertex(f->e2); 
  BDS_Point *p3 = f->e1->commonvertex(f->e3); 
  BDS_Edge *p1_mid = new BDS_Edge(p1, mid);
  edges.push_back(p1_mid);
  BDS_Edge *p2_mid = new BDS_Edge(p2, mid);
  edges.push_back(p2_mid);
  BDS_Edge *p3_mid = new BDS_Edge(p3, mid);
  edges.push_back(p2_mid);
  BDS_Face *t1, *t2, *t3;
  t1 = new BDS_Face(f->e1, p1_mid, p3_mid);
  t2 = new BDS_Face(f->e2, p2_mid, p1_mid);
  t3 = new BDS_Face(f->e3, p3_mid, p2_mid);

  t1->g = f->g;
  t2->g = f->g;
  t3->g = f->g;

  p1_mid->g = f->g;
  p2_mid->g = f->g;
  p3_mid->g = f->g;

  mid->g = f->g;

  triangles.push_back(t1);
  triangles.push_back(t2);
  triangles.push_back(t3);

  // config has changed
  p1->config_modified = true;
  p2->config_modified = true;
  p3->config_modified = true;

  // delete the face
  del_face(f);

  return true;
}

bool BDS_Mesh::split_edge(BDS_Edge *e, BDS_Point *mid)
{
  /*
        p1
      / | \
     /  |  \
 op1/ 0mid1 \op2
    \   |   /
     \  |  /
      \ p2/

     //  p1,op1,mid -
     //  p2,op2,mid -
     //  p2,op1,mid +
     //  p1,op2,mid +
  */

  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;

  e->oppositeof(op);
  
  BDS_Point *pts1[4];
  e->faces(0)->getNodes(pts1);

  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      if(pts1[(i + 1) % 3] == p2)
        orientation = 1;
      else
        orientation = -1;
      break;
    }
  }

  // we should project 
  BDS_GeomEntity *g1 = 0, *g2 = 0, *ge = e->g;

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  if(e->faces(0)) {
    g1 = e->faces(0)->g;
    del_face(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    g2 = e->faces(0)->g;
    del_face(e->faces(0));
  }

  //  double t_l = e->target_length;

  del_edge(e);

  BDS_Edge *p1_mid = new BDS_Edge(p1, mid);
  edges.push_back(p1_mid);
  BDS_Edge *mid_p2 = new BDS_Edge(mid, p2);
  edges.push_back(mid_p2);
  BDS_Edge *op1_mid = new BDS_Edge(op[0], mid);
  edges.push_back(op1_mid);
  BDS_Edge *mid_op2 = new BDS_Edge(mid, op[1]);
  edges.push_back(mid_op2);

  BDS_Face *t1, *t2, *t3, *t4;
  if(orientation == 1) {
    t1 = new BDS_Face(op1_mid, p1_op1, p1_mid);
    t2 = new BDS_Face(mid_op2, op2_p2, mid_p2);
    t3 = new BDS_Face(op1_p2, op1_mid, mid_p2);
    t4 = new BDS_Face(p1_op2, mid_op2, p1_mid);
  }
  else {
    t1 = new BDS_Face(p1_op1, op1_mid, p1_mid);
    t2 = new BDS_Face(op2_p2, mid_op2, mid_p2);
    t3 = new BDS_Face(op1_mid, op1_p2, mid_p2);
    t4 = new BDS_Face(mid_op2, p1_op2, p1_mid);
  }
  t1->g = g1;
  t2->g = g2;
  t3->g = g1;
  t4->g = g2;

  p1_mid->g = ge;
  mid_p2->g = ge;
  op1_mid->g = g1;
  mid_op2->g = g2;

  mid->g = ge;

  triangles.push_back(t1);
  triangles.push_back(t2);
  triangles.push_back(t3);
  triangles.push_back(t4);

  // config has changed
  p1->config_modified = true;
  p2->config_modified = true;
  op[0]->config_modified = true;
  op[1]->config_modified = true;
  return true;
}

// This function does actually the swap without taking into account
// the feasability of the operation. Those conditions have to be
// taken into account before doing the edge swap

bool BDS_SwapEdgeTestQuality::operator () (BDS_Point *_p1, BDS_Point *_p2,
                                           BDS_Point *_q1, BDS_Point *_q2) const
{  
  if(!testSmallTriangles){
    double p1 [2] = {_p1->u,_p1->v};
    double p2 [2] = {_p2->u,_p2->v};
    double op1[2] = {_q1->u,_q1->v};
    double op2[2] = {_q2->u,_q2->v};
    
    double ori_t1 = gmsh::orient2d(op1, p1, op2);
    double ori_t2 = gmsh::orient2d(op1, op2, p2);
    
    // printf("%d %d %d %d %g %g\n",_p1->iD,_p2->iD,_q1->iD,_q2->iD,ori_t1,ori_t2);
    return (ori_t1 * ori_t2 > 0); // the quadrangle was strictly convex !
  }
  
  double s1 = fabs(surface_triangle_param(_p1, _p2, _q1)); 
  double s2 = fabs(surface_triangle_param(_p1, _p2, _q2)); 
  double s3 = fabs(surface_triangle_param(_p1, _q1, _q2)); 
  double s4 = fabs(surface_triangle_param(_p2, _q1, _q2)); 
  if(fabs(s1 + s2 - s3 - s4) > 1.e-12 * (s1 + s2)) return false;
  if(s3 < .02 * (s1 + s2) || s4 < .02 * (s1 + s2))
    return false;
  return true;
}

bool BDS_SwapEdgeTestQuality::operator () (BDS_Point *_p1, BDS_Point *_p2, BDS_Point *_p3,
                                           BDS_Point *_q1, BDS_Point *_q2, BDS_Point *_q3,
                                           BDS_Point *_op1, BDS_Point *_op2, BDS_Point *_op3,
                                           BDS_Point *_oq1, BDS_Point *_oq2, BDS_Point *_oq3) const
{
  if(!testQuality) return true;
  double n[3], q[3], on[3], oq[3];
  normal_triangle(_p1, _p2, _p3, n); 
  normal_triangle(_q1, _q2, _q3, q); 
  normal_triangle(_op1, _op2, _op3, on); 
  normal_triangle(_oq1, _oq2, _oq3, oq);

  double cosnq; prosca(n, q, &cosnq);
  double cosonq; prosca(on, oq, &cosonq);

  double qa1 = qmTriangle(_p1, _p2, _p3, QMTRI_RHO);
  double qa2 = qmTriangle(_q1, _q2, _q3, QMTRI_RHO);
  double qb1 = qmTriangle(_op1, _op2, _op3, QMTRI_RHO);
  double qb2 = qmTriangle(_oq1, _oq2, _oq3, QMTRI_RHO);

  // we swap for a better configuration 
  double mina = std::min(qa1,qa2);
  double minb = std::min(qb1,qb2);

  // if(cosnq < .3 && cosonq > .5 && minb > .1)
  //   printf("mina = %g minb = %g cos %g %g\n",mina,minb,cosnq,cosonq);
  
  if(cosnq < .3 && cosonq > .5 && minb > .1) return true;
  
  if(minb > mina) return true;
  //  if(mina > minb && cosnq <= cosonq)return true;
  return false;
}

void swap_config(BDS_Edge *e, 
                 BDS_Point **p11, BDS_Point **p12, BDS_Point **p13,
                 BDS_Point **p21, BDS_Point **p22, BDS_Point **p23,
                 BDS_Point **p31, BDS_Point **p32, BDS_Point **p33,
                 BDS_Point **p41, BDS_Point **p42, BDS_Point **p43)
{
  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  e->oppositeof(op);

  BDS_Point *pts1[4];
  e->faces(0)->getNodes(pts1);

  // compute the orientation of the face
  // with respect to the edge
  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      if(pts1[(i + 1) % 3] == p2)
        orientation = 1;
      else
        orientation = -1;
      break;
    }
  }
  
  if(orientation == 1) {
    *p11 = p1;
    *p12 = p2;
    *p13 = op[0];

    *p21 = p2;
    *p22 = p1;
    *p23 = op[1];

    *p31 = p1;
    *p32 = op[1];
    *p33 = op[0];

    *p41 = op[1];
    *p42 = p2;
    *p43 = op[0];
  }
  else{
    *p11 = p2;
    *p12 = p1;
    *p13 = op[0];
    *p21 = p1;
    *p22 = p2;
    *p23 = op[1];
    *p31 = p1;
    *p32 = op[0];
    *p33 = op[1];
    *p41 = op[1];
    *p42 = op[0];
    *p43 = p2;
  }
}

bool BDS_Mesh::swap_edge(BDS_Edge *e, const BDS_SwapEdgeTest &theTest)
{

  /*
        p1
      / | \
     /  |  \
 op1/ 0 | 1 \op2
    \   |   /
     \  |  /
      \ p2/

     // op1 p1 op2
     // op1 op2 p2
   */

  // we test if the edge is deleted
  //  return false;

  if(e->deleted)
    return false;
  
  int nbFaces = e->numfaces();
  if(nbFaces != 2)
    return false;

  if(e->g && e->g->classif_degree == 1)
    return false;

  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  e->oppositeof(op);

  BDS_GeomEntity *g1 = 0, *g2 = 0, *ge = e->g;

  BDS_Point *pts1[4];
  e->faces(0)->getNodes(pts1);

  // compute the orientation of the face
  // with respect to the edge
  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      if(pts1[(i + 1) % 3] == p2)
        orientation = 1;
      else
        orientation = -1;
      break;
    }
  }

  if(orientation == 1) {
    if(!theTest(p1, p2, op[0],
                p2, p1, op[1],
                p1, op[1], op[0],
                op[1], p2, op[0]))
      return false;
  }
  else{
    if(!theTest(p2, p1, op[0],
                p1, p2, op[1],
                p1, op[0], op[1],
                op[1], op[0], p2))
      return false;
  }
  
  if(!theTest(p1, p2, op[0], op[1]))
    return false;

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  if(e->faces(0)) {
    g1 = e->faces(0)->g;
    del_face(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    g2 = e->faces(0)->g;
    del_face(e->faces(0));
  }
  del_edge(e);

  BDS_Edge *op1_op2 = new BDS_Edge(op[0], op[1]);
  edges.push_back(op1_op2);

  BDS_Face *t1, *t2;
  if(orientation == 1) {
    t1 = new BDS_Face(p1_op1, p1_op2, op1_op2);
    t2 = new BDS_Face(op1_op2, op2_p2, op1_p2);
  }
  else {
    t1 = new BDS_Face(p1_op2, p1_op1, op1_op2);
    t2 = new BDS_Face(op2_p2, op1_op2, op1_p2);
  }

  t1->g = g1;
  t2->g = g2;

  op1_op2->g = ge;

  triangles.push_back(t1);
  triangles.push_back(t2);

  p1->config_modified = true;
  p2->config_modified = true;
  op[0]->config_modified = true;
  op[1]->config_modified = true;

  return true;
}

int BDS_Edge::numTriangles() const
{
  int NT = 0;
  for(unsigned int i = 0; i < _faces.size(); i++)
    if(faces(i)->numEdges() == 3) NT++;
  return NT;
}

// This function does actually the swap without taking into account
// the feasability of the operation. Those conditions have to be
// taken into account before doing the edge swap
bool BDS_Mesh::recombine_edge(BDS_Edge *e)
{
  /*
        p1
      / | \
     /  |  \
 op1/ 0 | 1 \op2
    \   |   /
     \  |  /
      \ p2/

     // op1 p1 op2
     // op1 op2 p2
   */

  // we test if the edge is deleted
  if(e->deleted)
    return false;
  if(e->numfaces() != 2 || e->numTriangles() != 2)
    return false;
  if(e->g && e->g->classif_degree == 1)
    return false;

  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  BDS_Point *op[2];
  e->oppositeof(op);

  BDS_Point *pts1[4];
  e->faces(0)->getNodes(pts1);

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  BDS_GeomEntity *g = 0;
  if(e->faces(0)){
    g = e->faces(0)->g;
    del_face(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    del_face(e->faces(0));
  }
  del_edge(e);

  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      if(pts1[(i + 1) % 3] == p2)
        orientation = 1;
      else
        orientation = -1;
      break;
    }
  }

  BDS_Face *f;
  if(orientation < 0)
    f = add_quadrangle(p1_op1, op1_p2, op2_p2, p1_op2);
  else
    f = add_quadrangle(p1_op1, p1_op2, op2_p2, op1_p2);
  f->g = g;
  
  p1->config_modified = true;
  p2->config_modified = true;
  op[0]->config_modified = true;
  op[1]->config_modified = true;

  return true;
}

bool BDS_Mesh::collapse_edge_parametric(BDS_Edge *e, BDS_Point *p)
{
  if(e->numfaces() != 2)
    return false;
  if(p->g && p->g->classif_degree == 0)
    return false;
  // not really ok but 'til now this is the best choice not to do collapses on model edges
  if(p->g && p->g->classif_degree == 1)
    return false;
  if(e->g && p->g) {
    if(e->g->classif_degree == 2 && p->g != e->g)
      return false;
  }

  std::list<BDS_Face*> t;
  BDS_Point *o = e->othervertex(p);

  //  if(o->g != p->g)
  //    return false;

  // printf("collapsing an edge :");
  // print_edge(e);

  static BDS_Point *pt[3][1024];
  static BDS_GeomEntity *gs[1024];
  static int ept[2][1024];
  static BDS_GeomEntity *egs[1024]; 
  int nt = 0;
  {
    p->getTriangles(t);
    std::list<BDS_Face*>::iterator it = t.begin();
    std::list<BDS_Face*>::iterator ite = t.end();
    while(it != ite) {
      BDS_Face *t = *it;
      if(t->e1 != e && t->e2 != e && t->e3 != e) {
        if(!test_move_point_parametric_triangle(p, o->u, o->v, t))
          return false;
        gs[nt] = t->g;
        BDS_Point *pts[4];
        t->getNodes(pts);
        pt[0][nt] = (pts[0] == p) ? o : pts[0];
        pt[1][nt] = (pts[1] == p) ? o : pts[1];
        pt[2][nt] = (pts[2] == p) ? o : pts[2];

//      double qnew = qmTriangle(pt[0][nt], pt[1][nt], pt[2][nt], QMTRI_RHO);
//      double qold = qmTriangle(pts[0], pts[1], pts[2], QMTRI_RHO);
//      if(qold > 1.e-4 && qnew < 1.e-4) return false;
        nt++;
//      pt[0][nt] = (pts[0] == p) ? o->iD : pts[0]->iD;
//      pt[1][nt] = (pts[1] == p) ? o->iD : pts[1]->iD;
//      pt[2][nt++] = (pts[2] == p) ? o->iD : pts[2]->iD;
      }
      ++it;
    }
  }

  {
    std::list<BDS_Face*>::iterator it = t.begin();
    std::list<BDS_Face*>::iterator ite = t.end();

    while(it != ite) {
      BDS_Face *t = *it;
      del_face(t);
      ++it;
    }
  }

  // printf("%d triangles 2 add\n",nt);

  int kk = 0;
  {
    std::list<BDS_Edge*> edges(p->edges);
    std::list<BDS_Edge*>::iterator eit = edges.begin();
    std::list<BDS_Edge*>::iterator eite = edges.end();
    while(eit != eite) {
      (*eit)->p1->config_modified = (*eit)->p2->config_modified = true;
      ept[0][kk] = ((*eit)->p1 == p) ? o->iD : (*eit)->p1->iD;
      ept[1][kk] = ((*eit)->p2 == p) ? o->iD : (*eit)->p2->iD;
      egs[kk++] = (*eit)->g;
      del_edge(*eit);
      ++eit;
    }
  }

  del_point(p);

  {
    for(int k = 0; k < nt; k++) {
      BDS_Face *t = add_triangle(pt[0][k]->iD, pt[1][k]->iD, pt[2][k]->iD);
      t->g = gs[k];
    }
  }

  for(int i = 0; i < kk; ++i) {
    BDS_Edge *e = find_edge(ept[0][i], ept[1][i]);
    if(e)
      e->g = egs[i];
  }

  return true;
}

// use robust predicates for not allowing to revert a triangle by
// moving one of its vertices

bool test_move_point_parametric_triangle(BDS_Point *p, double u, double v, BDS_Face *t)
{       
  if (t->e4)
    return test_move_point_parametric_quad(p,u,v,t);
  BDS_Point *pts[4];
  t->getNodes(pts);

  double pa[2] = {pts[0]->u, pts[0]->v};
  double pb[2] = {pts[1]->u, pts[1]->v};
  double pc[2] = {pts[2]->u, pts[2]->v};

  double a[2] = {pb[0] - pa[0], pb[1] - pa[1]};
  double b[2] = {pc[0] - pa[0], pc[1] - pa[1]};

  double area_init = fabs(a[0] * b[1] - a[1] * b[0]);

  if(area_init == 0.0) return true;

  double ori_init = gmsh::orient2d(pa, pb, pc);

  if(p == pts[0]){ 
    pa[0] = u; 
    pa[1] = v; 
  }
  else if(p == pts[1]){
    pb[0] = u;
    pb[1] = v;
  }
  else if(p == pts[2]){
    pc[0] = u;
    pc[1] = v;
  }
  else
    return false;
  
  double area_final = fabs(a[0] * b[1] - a[1] * b[0]);
  if(area_final < 0.1 * area_init) return false;
  double ori_final = gmsh::orient2d(pa, pb, pc);
  // allow to move a point when a triangle was flat
  return ori_init*ori_final > 0;
}

bool test_move_point_parametric_quad(BDS_Point *p, double u, double v, BDS_Face *t)
{       
  BDS_Point *pts[4];
  t->getNodes(pts);

  double pa[2] = {pts[0]->u, pts[0]->v};
  double pb[2] = {pts[1]->u, pts[1]->v};
  double pc[2] = {pts[2]->u, pts[2]->v};
  double pd[2] = {pts[3]->u, pts[3]->v};

  double ori_init1 = gmsh::orient2d(pa, pb, pc);
  double ori_init2 = gmsh::orient2d(pc, pd, pa);

  if(p == pts[0]){ 
    pa[0] = u; 
    pa[1] = v; 
  }
  else if(p == pts[1]){
    pb[0] = u;
    pb[1] = v;
  }
  else if(p == pts[2]){
    pc[0] = u;
    pc[1] = v;
  }
  else if(p == pts[3]){
    pd[0] = u;
    pd[1] = v;
  }
  else{
    Msg::Error("Something wrong in move_point_parametric_quad");
    return false;
  }
  
  double ori_final1 = gmsh::orient2d(pa, pb, pc);
  double ori_final2 = gmsh::orient2d(pc, pd, pa);
  // allow to move a point when a triangle was flat
  return ori_init1*ori_final1 > 0 && ori_init2*ori_final2 > 0 ;
}

// d^2_i = (x^2_i - x)^T M (x_i - x)  
//       = M11 (x_i - x)^2 + 2 M21 (x_i-x)(y_i-y) + M22 (y_i-y)^2        

struct smoothVertexData{
  BDS_Point *p;
  GFace *gf;
  double scalu, scalv;
  std::list<BDS_Face*> ts;
}; 

double smoothing_objective_function(double U, double V, BDS_Point *v, 
                                    std::list<BDS_Face*> &ts, double su, double sv,
                                    GFace *gf)
{
  GPoint gp = gf->point(U * su, V * sv);

  const double oldX = v->X;
  const double oldY = v->Y;
  const double oldZ = v->Z;
  v->X = gp.x();
  v->Y = gp.y();
  v->Z = gp.z();

  std::list<BDS_Face*>::iterator it = ts.begin();
  std::list<BDS_Face*>::iterator ite = ts.end();
  double qMin = 1.;
  while(it != ite) {
    BDS_Face *t = *it;
    qMin = std::min(qmTriangle(*it, QMTRI_RHO), qMin);
    ++it;
  }
  v->X = oldX;
  v->Y = oldY;
  v->Z = oldZ;
  return -qMin;  
}

void deriv_smoothing_objective_function(double U, double V, 
                                        double &F, double &dFdU, double &dFdV,
                                        void *data)
{
  smoothVertexData *svd = (smoothVertexData*)data;
  BDS_Point *v = svd->p;
  const double LARGE = 1.e5;
  const double SMALL = 1./LARGE;
  F = smoothing_objective_function(U, V, v, svd->ts, 
                                   svd->scalu, svd->scalv, svd->gf);
  double F_U = smoothing_objective_function(U + SMALL, V, v, svd->ts, 
                                            svd->scalu, svd->scalv, svd->gf);
  double F_V = smoothing_objective_function(U, V + SMALL, v, svd->ts,
                                            svd->scalu, svd->scalv, svd->gf);
  dFdU = (F_U - F) * LARGE;
  dFdV = (F_V - F) * LARGE;
}

double smooth_obj(double U, double V, void *data)
{
  smoothVertexData *svd = (smoothVertexData*)data;
  return smoothing_objective_function(U, V, svd->p, svd->ts,
                                      svd->scalu, svd->scalv, svd->gf); 
}

void optimize_vertex_position(GFace *GF, BDS_Point *data, double su, double sv)
{
#ifdef HAVE_GSL
  if(data->g && data->g->classif_degree <= 1) return;
  smoothVertexData vd;
  vd.p = data;
  vd.scalu = su;
  vd.scalv = sv;
  vd.gf = GF;
  data->getTriangles(vd.ts);
  double U = data->u, V = data->v, val;

  val = smooth_obj(U, V, &vd);
  if(val < -.90) return;

  minimize_2(smooth_obj, deriv_smoothing_objective_function, &vd, 5, U,V,val);
  std::list<BDS_Face*>::iterator it = vd.ts.begin();
  std::list<BDS_Face*>::iterator ite = vd.ts.end();
  while(it != ite) {
    BDS_Face *t = *it;
    if(!test_move_point_parametric_triangle(data, U, V, t)){
      return;          
    }
    ++it;
  }
  
  data->u = U;
  data->v = V;
  GPoint gp = GF->point(U * su, V * sv);
  data->X = gp.x();
  data->Y = gp.y();
  data->Z = gp.z();  
#endif
}

bool BDS_Mesh::smooth_point_centroid(BDS_Point *p, GFace *gf, bool test_quality)
{
  if(!p->config_modified) return false;
  if(p->g && p->g->classif_degree <= 1) return false;
  if(p->g && p->g->classif_tag < 0) {
    p->config_modified = true;
    return true;
  }
  std::list<BDS_Edge*>::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if((*eit)->numfaces() == 1) return false;
    eit++;
  }

  double U = 0;
  double V = 0;
  double LC = 0;
  double oldU = p->u;
  double oldV = p->v;

  std::list<BDS_Face*> ts;
  p->getTriangles(ts);
  std::list < BDS_Edge * >::iterator ited  = p->edges.begin();
  std::list < BDS_Edge * >::iterator itede = p->edges.end();

  double sTot = 0;
  while(ited != itede) {
    BDS_Edge  *e = *ited;
    BDS_Point *n = e->othervertex(p);
    double fact = 1.0;    
    sTot += fact;
    U  += n->u * fact;
    V  += n->v * fact;
    LC += n->lc() * fact;
    ++ited;
  }
  U /= (sTot); 
  V /= (sTot);
  LC /= (sTot);

  GPoint gp = gf->point(U * scalingU, V * scalingV);

  const double oldX = p->X;
  const double oldY = p->Y;
  const double oldZ = p->Z;

  std::list<BDS_Face*>::iterator it = ts.begin();
  std::list<BDS_Face*>::iterator ite = ts.end();
  double s1 = 0, s2 = 0;

  double newWorst = 1.0;
  double oldWorst = 1.0;
  while(it != ite) {
    BDS_Face *t = *it;   
    BDS_Point *n[4];
    t->getNodes(n);
    p->u = U;
    p->v = V;
    double snew = fabs(surface_triangle_param(n[0], n[1], n[2])); 
    s1 += snew;
    p->u = oldU;
    p->v = oldV;
    double sold = fabs(surface_triangle_param(n[0], n[1], n[2])); 
    s2 += sold;
    // printf("%22.15E %22.15E\n", snew, sold);
    if(snew < .1 * sold) return false;

    if(1 || test_quality){
      p->X = gp.x();
      p->Y = gp.y();
      p->Z = gp.z();
      newWorst = std::min(newWorst, qmTriangle(*it, QMTRI_RHO));
      double norm1[3],norm2[3];
      normal_triangle(n[0], n[1], n[2], norm1);
      p->X = oldX;
      p->Y = oldY;
      p->Z = oldZ;
      normal_triangle(n[0], n[1], n[2], norm2);
      oldWorst = std::min(oldWorst, qmTriangle(*it, QMTRI_RHO));
      double ps; 
      prosca(norm1, norm2, &ps);
      if(ps < .5) return false;
    }
    ++it;
  }
  
  // printf("%22.15E %22.15E %22.15E\n",s1,s2,fabs(s2-s1));
  if(fabs(s2-s1) > 1.e-14 * (s2 + s1)) return false;
  
  if(test_quality && newWorst < oldWorst){
    return false;
  }
  
  p->u = U;
  p->v = V;
  p->lc() = LC;
  p->X = gp.x();
  p->Y = gp.y();
  p->Z = gp.z();
  eit = p->edges.begin();
  while(eit != p->edges.end()) {
    (*eit)->update();
    ++eit;
  }  
  return true;
}

bool BDS_Mesh::smooth_point_parametric(BDS_Point *p, GFace *gf)
{

  if(!p->config_modified)return false;
  if(p->g && p->g->classif_degree <= 1)
    return false;
  
  double U = 0;
  double V = 0;
  double tot_length = 0; 
  double LC = 0;


  std::list<BDS_Face*> ts;
  p->getTriangles(ts);
  std::list<BDS_Face*>::iterator it = ts.begin();
  std::list<BDS_Face*>::iterator ite = ts.end();

  while(it != ite) {
    BDS_Face *t = *it;
    BDS_Point *n[4];
    t->getNodes(n);
    for (int i = 0; i<t->numEdges();i++){
      U += n[i]->u;
      V += n[i]->v;
      LC += n[i]->lc();
      tot_length += 1;      
    }
    ++it;
  }  
  U /= tot_length;
  V /= tot_length;
  LC /= p->edges.size();

  it = ts.begin();
  while(it != ite) {
    BDS_Face *t = *it;
    if(!test_move_point_parametric_triangle(p, U, V, t)){
      printf("coucou %g %g -> %g %g\n", p->u, p->v,U,V);
      return false;
    }
    ++it;
  }

  GPoint gp = gf->point(U * scalingU, V * scalingV);
  p->u = U;
  p->v = V;
  p->lc() = LC;
  p->X = gp.x();
  p->Y = gp.y();
  p->Z = gp.z();
  std::list<BDS_Edge*>::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    (*eit)->update();
    ++eit;
  }

  return true;
}

struct recombine_T
{
  const BDS_Edge *e;
  double angle;
  recombine_T(const BDS_Edge *_e); 
  bool operator < (const recombine_T &other) const
  {
    return angle < other.angle;
  }
};

recombine_T::recombine_T(const BDS_Edge *_e)
  : e(_e)
{
  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  e->oppositeof(op);
  BDS_Vector v1(*p1, *op[0]);
  BDS_Vector v2(*op[0], *p2);
  BDS_Vector v3(*p2, *op[1]);
  BDS_Vector v4(*op[1], *p1);
  angle = fabs(90. - v1.angle_deg(v2));
  angle = std::max(fabs(90. - v2.angle_deg(v3)), angle);
  angle = std::max(fabs(90. - v3.angle_deg(v4)), angle);
  angle = std::max(fabs(90. - v4.angle_deg(v1)), angle);
}

void BDS_Mesh::recombineIntoQuads(const double angle_limit, GFace *gf)
{
  Msg::Info("Recombining triangles for surface %d", gf->tag());  
  for(int i = 0; i < 5; i++){
    std::set<recombine_T> pairs;
    for(std::list<BDS_Edge*>::const_iterator it = edges.begin();
        it != edges.end(); ++it){
      if(!(*it)->deleted && (*it)->numfaces () == 2)
        pairs.insert(recombine_T(*it));
    }  

    bool rec = false;    
    std::set<recombine_T>::iterator itp = pairs.begin();
    while(itp != pairs.end()){
      // recombine if difference between max quad angle and right
      // angle is smaller than tol
      if(itp->angle < gf->meshAttributes.recombineAngle)
        rec |= recombine_edge((BDS_Edge*)itp->e);
      ++itp;
    }

    if(!rec) break;

    std::set<BDS_Point*, PointLessThan>::iterator itpt = points.begin();
    while(itpt != points.end()){
      smooth_point_parametric(*itpt, gf);
      ++itpt;
    }
  }
}

void FullQuadMesh()
{
}
