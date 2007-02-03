// $Id: BDS.cpp,v 1.73 2007-02-03 15:40:06 geuzaine Exp $
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include <math.h>
#include <stdio.h>
#include "Numeric.h"
#include "GmshMatrix.h"
#include "BDS.h"
#include "Message.h"
#include "GFace.h"

bool test_move_point_parametric_triangle (BDS_Point * p, double u, double v, BDS_Face *t);

void outputScalarField(std::list < BDS_Face * >t, const char *iii, int param)
{
  FILE *f = fopen(iii, "w");
  if(!f) return;
  fprintf(f, "View \"scalar\" {\n");
  std::list < BDS_Face * >::iterator tit = t.begin();
  std::list < BDS_Face * >::iterator tite = t.end();
  while(tit != tite) {
    BDS_Point *pts[4];
    (*tit)->getNodes(pts);
    if (param)
      fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      pts[0]->u, pts[0]->v, 0.0,
	      pts[1]->u, pts[1]->v, 0.0,
	      pts[2]->u, pts[2]->v, 0.0,(double)pts[0]->iD,(double)pts[1]->iD,(double)pts[2]->iD);
    else
      fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      pts[0]->X, pts[0]->Y, pts[0]->Z,
	      pts[1]->X, pts[1]->Y, pts[1]->Z,
	      pts[2]->X, pts[2]->Y, pts[2]->Z,(double)pts[0]->iD,(double)pts[1]->iD,(double)pts[2]->iD);
    ++tit;
  }
  fprintf(f, "};\n");
  fclose(f);
}

BDS_Vector::BDS_Vector(const BDS_Point & p2, const BDS_Point & p1)
  :x(p2.X - p1.X), y(p2.Y - p1.Y), z(p2.Z - p1.Z)
{
}

void vector_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3,
                     double c[3])
{
  double a[3] = { p1->X - p2->X, p1->Y - p2->Y, p1->Z - p2->Z };
  double b[3] = { p1->X - p3->X, p1->Y - p3->Y, p1->Z - p3->Z };
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

void vector_triangle_parametric(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3,
				double &c)
{
  double a[2] = { p1->u - p2->u, p1->v - p2->v };
  double b[2] = { p1->u - p3->u, p1->v - p3->v };
  c = a[0] * b[1] - a[1] * b[0];
}

void normal_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3,
                     double c[3])
{
  vector_triangle(p1, p2, p3, c);
  double l = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
  if(l == 0)
    return;
  c[0] /= l;
  c[1] /= l;
  c[2] /= l;
}

double surface_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3)
{
  double c[3];
  vector_triangle(p1, p2, p3, c);
  return 0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
}

double surface_triangle_param(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3)
{
  double c;
  vector_triangle_parametric (p1, p2, p3, c);
  return (0.5 * c);
}

double quality_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3)
{
  double e12 = ((p1->X - p2->X) * (p1->X - p2->X) +
                (p1->Y - p2->Y) * (p1->Y - p2->Y) +
                (p1->Z - p2->Z) * (p1->Z - p2->Z));
  double e22 = ((p1->X - p3->X) * (p1->X - p3->X) +
                (p1->Y - p3->Y) * (p1->Y - p3->Y) +
                (p1->Z - p3->Z) * (p1->Z - p3->Z));
  double e32 = ((p3->X - p2->X) * (p3->X - p2->X) +
                (p3->Y - p2->Y) * (p3->Y - p2->Y) +
                (p3->Z - p2->Z) * (p3->Z - p2->Z));
  double a = surface_triangle(p1, p2, p3);
  return a / (e12 + e22 + e32);
}

void BDS_Point::getTriangles(std::list < BDS_Face * >&t) const
{
  t.clear();
  std::list < BDS_Edge * >::const_iterator it = edges.begin();
  std::list < BDS_Edge * >::const_iterator ite = edges.end();
  while(it != ite) {
    int NF = (*it)->numfaces();
    for(int i = 0; i < NF; ++i) {
      BDS_Face *tt = (*it)->faces(i);
      if(tt) {
        std::list < BDS_Face * >::iterator tit = t.begin();
        std::list < BDS_Face * >::iterator tite = t.end();
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
    return (BDS_Point *) (*it);
  else
    return 0;
}

BDS_Edge *BDS_Mesh::find_edge(int num1, int num2)
{
  BDS_Point *p = find_point(num1);
  std::list < BDS_Edge * >::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if((*eit)->p1 == p && (*eit)->p2->iD == num2)
      return (*eit);
    if((*eit)->p2 == p && (*eit)->p1->iD == num2)
      return (*eit);
    ++eit;
  }
  return 0;
}

int Intersect_Edges_2d(double x1, double y1, double x2, double y2,
		       double x3, double y3, double x4, double y4)
{
  double mat[2][2];
  double rhs[2], x[2];
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

BDS_Edge *BDS_Mesh::recover_edge(int num1, int num2)
{
  BDS_Edge *e = find_edge (num1, num2);

  if (e) return e;

  BDS_Point *p1 = find_point(num1);
  BDS_Point *p2 = find_point(num2);
  
  if (!p1 || !p2) throw;;

  Msg(INFO," edge %d %d has to be recovered",num1,num2);
  
  int ix = 0;
  while(1)
    {
      std::vector<BDS_Edge *> intersected;
      std::list<BDS_Edge *>::iterator it = edges.begin();
      while (it!=edges.end())
	{
	  e = (*it);
	  //	  if (e->p1->iD >= 0 && e->p2->iD >= 0)Msg(INFO," %d %d %g %g - %g %g",e->p1->iD,e->p2->iD,e->p1->u,e->p1->v,e->p2->u,e->p2->v);
	  if (!e->deleted && e->p1 != p1 && e->p1 != p2 && e->p2 != p1 && e->p2 != p2)
	    if(Intersect_Edges_2d(e->p1->u, e->p1->v,
				  e->p2->u, e->p2->v,
				  p1->u, p1->v,
				  p2->u, p2->v))
	      intersected.push_back(e);	  
	  ++it;
	}

      if (!intersected.size() || ix > 10000)
	{
	  BDS_Edge *eee = find_edge (num1, num2);
	  if (!eee)
	    {
	      outputScalarField(triangles, "debugp.pos",1);
	      outputScalarField(triangles, "debugr.pos",0);
	      return 0;
	    }
	  return eee;
	}
      
      int ichoice = ix++ % intersected.size();
      swap_edge ( intersected[ichoice] , BDS_SwapEdgeTestParametric () );	       
    }
  return 0;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point * p1, BDS_Point * p2,
                              BDS_Face * t) const
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

BDS_Face *BDS_Mesh::find_triangle(BDS_Edge * e1, BDS_Edge * e2,
                                      BDS_Edge * e3)
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
  if(efound)
    return efound;

  BDS_Point *pp1 = find_point(p1);
  BDS_Point *pp2 = find_point(p2);
  if(!pp1 || !pp2)
    throw;
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

BDS_Face *BDS_Mesh::add_triangle(BDS_Edge * e1, BDS_Edge * e2,
                                     BDS_Edge * e3)
{

  //BDS_Face *tfound = find_triangle(e1, e2, e3);
  //  if(tfound)
  //    return tfound;
  
  BDS_Face *t = new BDS_Face(e1, e2, e3);
  triangles.push_back(t);
  return t;
}

BDS_Face *BDS_Mesh::add_quadrangle(BDS_Edge * e1, BDS_Edge * e2,
				   BDS_Edge * e3,BDS_Edge * e4 )
{
  BDS_Face *t = new BDS_Face(e1, e2, e3, e4);
  triangles.push_back(t);
  return t;
}


// BDS_Tet *BDS_Mesh::add_tet(int p1, int p2, int p3, int p4)
// {
//   BDS_Edge *e1 = add_edge(p1, p2);
//   BDS_Edge *e2 = add_edge(p2, p3);
//   BDS_Edge *e3 = add_edge(p3, p1);
//   BDS_Edge *e4 = add_edge(p1, p4);
//   BDS_Edge *e5 = add_edge(p2, p4);
//   BDS_Edge *e6 = add_edge(p3, p4);
//   BDS_Face *t1 = add_triangle(e1, e2, e3);
//   BDS_Face *t2 = add_triangle(e1, e4, e5);
//   BDS_Face *t3 = add_triangle(e2, e6, e5);
//   BDS_Face *t4 = add_triangle(e3, e4, e6);
//   BDS_Tet *t = new BDS_Tet(t1, t2, t3, t4);
//   tets.push_back(t);
//   return t;
// }

void BDS_Mesh::del_face(BDS_Face * t)
{
  t->e1->del(t);
  t->e2->del(t);
  t->e3->del(t);
  if(t->e4)t->e4->del(t);
  t->deleted = true;
}

void BDS_Mesh::del_edge(BDS_Edge * e)
{
  // edges.erase(e);
  e->p1->del(e);
  e->p2->del(e);
  e->deleted = true;
  // edges_to_delete.insert(e);
}

void BDS_Mesh::del_point(BDS_Point * p)
{
  points.erase(p);
  delete p;
}

void BDS_Mesh::add_geom(int p1, int p2)
{
  geom.insert(new BDS_GeomEntity(p1, p2));
}

void BDS_Edge::oppositeof(BDS_Point * oface[2]) const
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
  if(it == geom.end())
    return 0;
  return (BDS_GeomEntity *) (*it);
}

void recur_tag(BDS_Face * t, BDS_GeomEntity * g)
{
  if(!t->g) {
    t->g = g;
    //    g->t.push_back(t);
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

bool BDS_Mesh::import_view(Post_View *view, const double tolerance)
{
  // imports all the tris+quads from a post-processing view

  Min[0] = view->BBox[0]; Max[0] = view->BBox[1];
  Min[1] = view->BBox[2]; Max[1] = view->BBox[3];
  Min[2] = view->BBox[4]; Max[2] = view->BBox[5];
  LC = sqrt((Min[0] - Max[0]) * (Min[0] - Max[0]) +
	    (Min[1] - Max[1]) * (Min[1] - Max[1]) +
	    (Min[2] - Max[2]) * (Min[2] - Max[2]));
  
  PointLessThanLexicographic::t = tolerance;
  std::set < BDS_Point *, PointLessThanLexicographic > pts;

  for(int type = 0; type < 6; type++){
    int nbList, nbNod;
    List_T *list;
    switch(type){
    case 0: list = view->ST; nbList = view->NbST; nbNod = 3; break;
    case 1: list = view->VT; nbList = view->NbVT; nbNod = 3; break;
    case 2: list = view->TT; nbList = view->NbTT; nbNod = 3; break;
    case 3: list = view->SQ; nbList = view->NbSQ; nbNod = 4; break;
    case 4: list = view->VQ; nbList = view->NbVQ; nbNod = 4; break;
    case 5: list = view->TQ; nbList = view->NbTQ; nbNod = 4; break;
    }
    if(nbList){
      int nb = List_Nbr(list) / nbList;
      for(int i = 0; i < List_Nbr(list); i += nb) {
	double *x = (double *)List_Pointer_Fast(list, i);
	double *y = (double *)List_Pointer_Fast(list, i + nbNod);
	double *z = (double *)List_Pointer_Fast(list, i + 2 * nbNod);
	BDS_Point *p[4];
	for(int j = 0; j < nbNod; j++){
	  BDS_Point P(0, x[j], y[j], z[j]);    
	  std::set < BDS_Point *, PointLessThanLexicographic >::iterator it = pts.find(&P);
	  if(it != pts.end()) {
	    p[j] = *it;
	  }
	  else {
	    MAXPOINTNUMBER++;
	    p[j] = add_point(MAXPOINTNUMBER, P.X, P.Y, P.Z);
	    pts.insert(p[j]);
	  }
	}
	if(nbNod == 3){
	  add_triangle(p[0]->iD, p[1]->iD, p[2]->iD);
	}
	else{
	  add_triangle(p[0]->iD, p[1]->iD, p[2]->iD);
	  add_triangle(p[0]->iD, p[2]->iD, p[3]->iD);
	}
      }
    }
  }
  return true;
}

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
    for (std::list<BDS_Face*> :: iterator it = triangles.begin();
	 it != triangles.end();
	 it++)
      {
	while (it != triangles.end() && (*it)->deleted)
	  {
	    delete *it;
	    it = triangles.erase (it);
	  }
      }	   
  }
  { 
    for (std::list<BDS_Edge*> :: iterator it = edges.begin();
	 it != edges.end();
	 it++)
      {
	while (it != edges.end() && (*it)->deleted)
	  {
	    delete *it;
	    it = edges.erase (it);
	  }	
      }	   
  } 
}

BDS_Mesh ::~ BDS_Mesh ()
{
   DESTROOOY ( geom.begin(),geom.end());
   DESTROOOY ( points.begin(),points.end());
   cleanup();
   DESTROOOY ( edges.begin(),edges.end());
   DESTROOOY ( triangles.begin(),triangles.end());
}


void BDS_Mesh::split_edge(BDS_Edge * e, BDS_Point *mid)
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
  e->oppositeof(op);
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

  //  p1_mid->target_length = t_l;
  //  op1_mid->target_length = t_l;
  //  mid_p2->target_length = t_l;
  //  mid_op2->target_length = t_l;

  // printf("split ends 1 %d (%d %d) %d %d \n",
  //         p1_op1->numfaces(), p1->iD, op[0]->iD, 
  //         op1_mid->numfaces(),p1_mid->numfaces());
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
}



// This function does actually the swap without taking into account
// the feasability of the operation. Those conditions have to be
// taken into account before doing the edge swap

bool BDS_SwapEdgeTestParametric::operator () (BDS_Point *_p1,BDS_Point *_p2,
					      BDS_Point *_q1,BDS_Point *_q2) const
{
  double p1[2] =  {_p1->u,_p1->v};
  double p2[2] =  {_p2->u,_p2->v};
  double op1[2] = {_q1->u,_q1->v};
  double op2[2] = {_q2->u,_q2->v};

  double ori_t1 = gmsh::orient2d(op1, p1, op2);
  double ori_t2 = gmsh::orient2d(op1,op2, p2);

  return (ori_t1 * ori_t2 > 0);
}

bool BDS_Mesh::swap_edge(BDS_Edge * e, const BDS_SwapEdgeTest &theTest)
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

  if (!theTest ( p1, p2, op[0],op[1]))
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

int BDS_Edge :: numTriangles() const 
{
  int NT = 0;
  for (unsigned int i=0;i<_faces.size();i++) 
    if (faces(i)->numEdges() == 3) NT++ ;
  return NT;
}

// This function does actually the swap without taking into account
// the feasability of the operation. Those conditions have to be
// taken into account before doing the edge swap
bool BDS_Mesh::recombine_edge(BDS_Edge * e)
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
  if(e->numfaces() != 2 || e->numTriangles() != 2)
    return false;
  if(e->g && e->g->classif_degree == 1)
    return false;

  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  e->oppositeof(op);

  BDS_Point *pts1[4];
  e->faces(0)->getNodes(pts1);

  //  FIXME  !!!!!!!!!!!!!!!!!
  //  should ensure that orientation is unchanged

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  BDS_GeomEntity *g=0;
  if(e->faces(0)) {
    g = e->faces(0)->g;
    del_face(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    del_face(e->faces(0));
  }
  del_edge(e);

  BDS_Face *f = add_quadrangle (p1_op1, op1_p2, op2_p2, p1_op2);
  f->g = g;

  p1->config_modified = true;
  p2->config_modified = true;
  op[0]->config_modified = true;
  op[1]->config_modified = true;

  return true;
}


bool BDS_Mesh::collapse_edge_parametric(BDS_Edge * e, BDS_Point * p)
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

  std::list < BDS_Face * >t;
  BDS_Point *o = e->othervertex(p);

  if(o->g != p->g)
    return false;

  // printf("collapsing an edge :");
  // print_edge(e);

  static int pt[3][1024];
  static BDS_GeomEntity *gs[1024];
  static int ept[2][1024];
  static BDS_GeomEntity *egs[1024]; 
  int nt = 0;
  {
    p->getTriangles(t);
    std::list < BDS_Face * >::iterator it = t.begin();
    std::list < BDS_Face * >::iterator ite = t.end();
    while(it != ite) {
      BDS_Face *t = *it;
      //          print_face(t);
      if(t->e1 != e && t->e2 != e && t->e3 != e) {
	if (!test_move_point_parametric_triangle ( p, o->u, o-> v, t))
	  return false;
        gs[nt] = t->g;
	BDS_Point *pts[4];
	t->getNodes(pts);
        pt[0][nt] = (pts[0] == p) ? o->iD : pts[0]->iD;
        pt[1][nt] = (pts[1] == p) ? o->iD : pts[1]->iD;
        pt[2][nt++] = (pts[2] == p) ? o->iD : pts[2]->iD;
      }
      ++it;
    }
  }


  {
    std::list < BDS_Face * >::iterator it = t.begin();
    std::list < BDS_Face * >::iterator ite = t.end();

    while(it != ite) {
      BDS_Face *t = *it;
      del_face(t);
      ++it;
    }
  }

  // printf("%d triangles 2 add\n",nt);

  int kk = 0;
  {
    std::list < BDS_Edge * >edges(p->edges);
    std::list < BDS_Edge * >::iterator eit = edges.begin();
    std::list < BDS_Edge * >::iterator eite = edges.end();
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
      BDS_Face *t = add_triangle(pt[0][k], pt[1][k], pt[2][k]);
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


// use robust predicates for not allowing to revert a triangle
// by moving one of its vertices 
bool test_move_point_parametric_triangle (BDS_Point * p, double u, double v, BDS_Face *t)
{       
  BDS_Point *pts[4];
  t->getNodes(pts);

  double pa[2] = { pts[0]->u,pts[0]->v};
  double pb[2] = { pts[1]->u,pts[1]->v};
  double pc[2] = { pts[2]->u,pts[2]->v};

  double a[2] = {pb[0]-pa[0],pb[1]-pa[1]};
  double b[2] = {pc[0]-pa[0],pc[1]-pa[1]};

  double area_init = fabs(a[1] * b[2] - a[2] * b[1]);

  if (area_init == 0.0) return true;

  double ori_init = gmsh::orient2d(pa, pb, pc);

  if (p == pts[0])
    {pa[0]=u;pa[1]=v;}
  else if (p == pts[1])
    {pb[0]=u;pb[1]=v;}
  else if (p == pts[2])
    {pc[0]=u;pc[1]=v;}
  else
    return false;

  double area_final = fabs(a[1] * b[2] - a[2] * b[1]);
  if (area_final < 0.1 * area_init)return false;
  double ori_final = gmsh::orient2d(pa, pb, pc);
  // allow to move a point when a triangle was flat
  return ori_init*ori_final > 0;
}

bool BDS_Mesh::smooth_point_parametric(BDS_Point * p, GFace *gf)
{

  if (!p->config_modified)return false;
  if(p->g && p->g->classif_degree <= 1)
    return false;

  double U = 0;
  double V = 0;
  //  double tot_length = 0;
  double LC = 0;

  std::list < BDS_Edge * >::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if ((*eit)->numfaces() == 1) return false;
    BDS_Point *op = ((*eit)->p1 == p) ? (*eit)->p2 : (*eit)->p1;
    //    const double l_e = (*eit)->length();     
    U += op->u; 
    V += op->v;
    //    tot_length += l_e;
    LC += op->lc();
    ++eit;
  }
  
  U /= (p->edges.size());
  V /= (p->edges.size());
  //  U /= tot_length;
  //  V /= tot_length;
  LC /= p->edges.size();

  std::list < BDS_Face * >ts;
  p->getTriangles(ts);
  std::list < BDS_Face * >::iterator it = ts.begin();
  std::list < BDS_Face * >::iterator ite = ts.end();
  while(it != ite) {
    BDS_Face *t = *it;
    if (!test_move_point_parametric_triangle ( p, U, V, t))
      return false;
    ++it;
  }


  GPoint gp = gf->point(U*scalingU,V*scalingV);
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


struct recombine_T
{
  const BDS_Edge *e  ;
  double angle ;
  recombine_T (const BDS_Edge *_e ); 
  bool operator < ( const recombine_T & other ) const
  {
    return angle < other.angle;
  }
};

recombine_T::recombine_T (const BDS_Edge *_e )
  : e(_e)
{
  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  e->oppositeof(op);
  BDS_Vector v1 (*p1,*op[0]);
  BDS_Vector v2 (*op[0],*p2);
  BDS_Vector v3 (*p2,*op[1]);
  BDS_Vector v4 (*op[1],*p1);
  angle = fabs(90.-v1.angle_deg(v2));
  angle = std::max(fabs(90.-v2.angle_deg(v3)),angle);
  angle = std::max(fabs(90.-v3.angle_deg(v4)),angle);
  angle = std::max(fabs(90.-v4.angle_deg(v1)),angle);
}

void BDS_Mesh::recombineIntoQuads (const double angle_limit, GFace *gf)
{
  
  Msg(INFO,"Recombining triangles for surface %d",gf->tag());  
  for (int i=0;i<5;i++)
  {
    bool rec = false;
    std::set<recombine_T> _pairs;
    
    for(std::list < BDS_Edge * >::const_iterator it = edges.begin();
	it != edges.end(); ++it) 
      {
	if (!(*it)->deleted && (*it)->numfaces () == 2)
	  _pairs.insert ( recombine_T ( *it ) );
      }  
    
    std::set<recombine_T>::iterator itp =  _pairs.begin();

    while (itp != _pairs.end())
      {
	rec |= recombine_edge ((BDS_Edge*)itp->e);
	++itp;
      }

    if (!rec) break;

    std::set<BDS_Point*,PointLessThan>::iterator itpt = points.begin();
    while (itpt != points.end())
      {
	
	smooth_point_parametric(*itpt,gf);
	++itpt;
      }


  }
}

