/* $Id: 2D_DivAndConq.cpp,v 1.6 2000-11-28 11:28:31 geuzaine Exp $ */
/*

   A L G O R I T H M E    D I V I D E    A N D     C O N Q U E R   

   le noeud de cette methode est de pouvoir fusionner
   deux triangulations de Delaunay en une seule (routine merge)
   on procede alors recursivement en separant les points en deux
   groupes puis en separant les groupes en 2 ... jusqu'a n'obtenir
   que 1 2 ou 3 points (la triangulation est alors triviale)

   Dans le mailleur, on utilise cet algorithme pour construire 
   le maillage initial 

   !!! il faut PERTURBER les points d'une faible valeur aleatoire
   pour eviter d'avoir 3 points alignes ou 4 points cocycliques !!!

   doc : structure contenant la triangulation

*/

#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"
#include "2D_Mesh.h"

extern double LC2D;

PointRecord *pPointArray;
DocPeek      gDocTemp;

int Insert(PointNumero a,PointNumero b);
int Delete(PointNumero a,PointNumero b);

void PushgPointArray(PointRecord *ptr){
  pPointArray = ptr;
}

PointRecord *PopgPointArray(void){
  return(pPointArray) ;
}

PointNumero Predecessor(PointNumero a, PointNumero b){
  DListPeek     p;
  
  p = pPointArray[a].adjacent;
  if (p == NULL)
    return -1;        

  do {
    if (p->point_num == b) return (Pred(p)->point_num);
    p = Pred(p);
  } while (p != pPointArray[a].adjacent);

  return -1;        
  
}


PointNumero Successor(PointNumero a,PointNumero b){
  DListPeek     p;
  
  p = pPointArray[a].adjacent;
  if (p == NULL)
    return -1;

  do {
    if (p->point_num == b) return (Succ(p)->point_num);
    p = Succ(p);
  } while (p != pPointArray[a].adjacent);

  return -1;        
  
}

int FixFirst(PointNumero x,PointNumero f){
  DListPeek  p,copy;
  int    out = 0;
  
  p = pPointArray[x].adjacent;
  if (p == NULL)
    return(0);
  copy = p;
  do {
    if (p->point_num == f){
      pPointArray[x].adjacent = p;
      out = 1;
    }
    else
      p = p->next;
  } while ((p != copy) && !out);
  return out;
}

PointNumero First(PointNumero x){
  return (pPointArray[x].adjacent)->point_num;
}

Segment LowerCommonTangent(DT vl,DT vr){
  PointNumero   x,y,z,z1,z2,temp;
  Segment       s;
  
  x = vl.end;            /* vu le tri, c'est le point le + a droite     */
  y = vr.begin;          /* idem, le + a gauche     */
  z = First(y);
  z1 = First(x);
  z2 = Predecessor(x,z1);
  for (;;) {
    if (Is_right_of(x,y,z)){
      temp = z;
      z = Successor(z,y);
      y = temp;
    }
    else if (Is_right_of(x,y,z2)){
      temp = z2;
      z2 = Predecessor(z2,x);
      x = temp;
    }
    else {
      s.from = x;
      s.to = y;
      return s;
    }
  }
}


Segment UpperCommonTangent(DT vl,DT vr){
  PointNumero   x,y,z,z1,z2,temp;
  Segment       s;
  
  x = vl.end;            /* vu le tri, c'est le point le + a droite     */
  y = vr.begin;          /* idem, le + a gauche     */
  z = First(y);
  z1 = First(x);
  z2 = Predecessor(y,z);
  for (;;){
    if (Is_left_of(x,y,z2)){
      temp = z2;
      z2 = Predecessor(z2,y);
      y = temp;     
    }
    else if (Is_left_of(x,y,z1)){
      temp = z1;
      z1 = Successor(z1,x);
      x = temp;
    }
    else{
      s.from = x;
      s.to = y;
      return s;
    }
  }
}


/* return 1 if the point k is NOT in the circumcircle of
   triangle hij */

int Qtest(PointNumero h,PointNumero i,PointNumero j,PointNumero k){
  double xc,yc,rcarre,distca;
  
  if ((h == i) && (h == j) && (h == k)){
    Msg(ERROR, "3 Points Identical in Qtest"); 
    return(0);  /* returning 1 will cause looping for ever */
  }
  if (CircumCircle( (double) pPointArray[h].where.h,
                    (double) pPointArray[h].where.v,
                    (double) pPointArray[i].where.h,
                    (double) pPointArray[i].where.v,
                    (double) pPointArray[j].where.h,
                    (double) pPointArray[j].where.v,
                    &xc, &yc )){
    rcarre = square(xc - (double) pPointArray[i].where.h) +
      square(yc - (double) pPointArray[i].where.v);
    
    distca = square(xc - (double) pPointArray[k].where.h) +
      square(yc - (double) pPointArray[k].where.v);
    
    return (distca > rcarre);
  }
  else
      return(0);  /* point not in circle, because no circle !     */
}

int merge(DT vl,DT vr){
  Segment      bt,ut;
  int      a,b,out;
  PointNumero  r,r1,r2,l,l1,l2;
  
  bt = LowerCommonTangent(vl,vr);
  ut = UpperCommonTangent(vl,vr);
  l = bt.from;          /* left endpoint of BT     */
  r = bt.to;            /* right endpoint of BT     */
  
  while ((l != ut.from) || (r != ut.to)) {     
    a = b = 0;
    if (!Insert(l,r)) return(0);
    
    r1 = Predecessor(r,l);
    if (r1 == -1) return(0);
    if (Is_right_of(l,r,r1))
      a = 1;
    else{
      out = 0;
      while (!out){
        r2 = Predecessor(r,r1);
        if (r2 == -1) return(0);
        if (r2 < vr.begin)
          out = 1;
        else if (Qtest(l,r,r1,r2))
          out = 1;
        else{
          if (!Delete(r,r1)) return(0);
          r1 = r2;
          if (Is_right_of(l,r,r1)) out = a = 1;
        }
      }
    }
      
    l1 = Successor(l,r);
    if (l1 == -1) return(0);
    if (Is_left_of(r,l,l1))
      b = 1;
    else{
      out = 0;
      while (!out){
        l2 = Successor(l,l1);
        if (l2 == -1) return(0);
        if (l2 > vl.end)
          out = 1;
        else if (Qtest(r,l,l1,l2))
          out = 1;
        else{
          if (!Delete(l,l1)) return(0);
          l1 = l2;
          if (Is_left_of(r,l,l1)) out = b = 1;
        }     
      }
    }
    
    if (a)
      l = l1;
    else if (b)
      r = r1;
    else{
      if (Qtest(l,r,r1,l1))
        r = r1;
      else
        l = l1;
    }
  }
  if (!Insert(l,r)) return(0);
  
  if (!FixFirst(ut.to,ut.from)) return(0);
  if (!FixFirst(bt.from,bt.to)) return(0);
  return(1);
}


DT recur_trig(PointNumero left,PointNumero right){
  int  n,m;
  DT   dt;
     
  dt.begin = left;
  dt.end = right;
  n = right - left + 1;      /* nombre de points a triangulariser */
  switch (n){
  case 0:
  case 1:
    /* 0 ou 1 points -> rien a faire */
    break;
    
  case 2:          /* deux points : cas trivial     */
    Insert(left,right);
    FixFirst(left,right);
    FixFirst(right,left);
    break;
    
  case 3:          /* trois points : cas trivial     */
    Insert(left,right);
    Insert(left,left + 1);
    Insert(left + 1,right);
    if (Is_right_of(left,right,left + 1)){
      FixFirst(left,left + 1);
      FixFirst(left + 1,right);
      FixFirst(right,left);
    }
    else{
      FixFirst(left,right);
      FixFirst(left + 1,left);
      FixFirst(right,left + 1);
    }
    break;
    
  default:     /* plus de trois points : cas recursif     */
    m = (left + right) >> 1;
    if (!merge(recur_trig(left,m),recur_trig(m + 1,right)))
      
      break;
  }
  return dt;
}

int comparePoints(const void *i, const void *j){
  double x,y;
  
  x = ((PointRecord *)i)->where.h - ((PointRecord *)j)->where.h;
  if (x == 0.) {
    y = ((PointRecord *)i)->where.v - ((PointRecord *)j)->where.v;
    return ((y < 0.) ? -1 : 1);
  }
  else
    return ((x < 0.) ? -1 : 1);
}


/*  this fonction builds the delaunay triangulation and the voronoi for a
    window. All error handling is done here. */
  
int DelaunayAndVoronoi(DocPeek doc){     
  PushgPointArray(doc->points); 

  if (doc->numPoints < 2) return(1);

  qsort(doc->points,doc->numPoints,sizeof(PointRecord),comparePoints);
  gDocTemp = doc;
  recur_trig(0,doc->numPoints - 1);  

  return 1;        
}


/* this routine puts in xc and yc the coord of the center
   of the circumcircle of triangle (x1,y1),(x2,y2),(x3,y3)  */
  
int CircumCircle(double x1,double y1,double x2,double y2,double x3,double y3,
                     double *xc,double *yc){
  double d,a1,a2,a3;
  
  
  d = 2. * (double)(y1*(x2-x3)+y2*(x3-x1)+y3*(x1-x2));
  if (d == 0.0){
    Msg(WARNING, "Points Colinear in CircumCircle"); 
    *xc = *yc = -99999.;      
    return(0);
  }
    
  a1 = x1*x1 + y1*y1;
  a2 = x2*x2 + y2*y2;
  a3 = x3*x3 + y3*y3;
  *xc = (double) ((a1*(y3-y2) + a2*(y1-y3) + a3*(y2-y1)) / d);
  *yc = (double) ((a1*(x2-x3) + a2*(x3-x1) + a3*(x1-x2)) / d);
  
  if(fabs(d) < 1.e-12 * DSQR(LC2D))
    Msg(WARNING, "Points Almost Colinear in CircumCircle (d = %g)", d); 

  return(1);
}


int Is_right_of(PointNumero x,PointNumero y,PointNumero check){
  return Is_left_of(y,x,check);
}

int Is_left_of(PointNumero x,PointNumero y,PointNumero check){
  static double xx,yy,alpha,beta;
  
  yy = (double) (pPointArray[y].where.v - pPointArray[x].where.v);
  xx = (double) (pPointArray[y].where.h - pPointArray[x].where.h);
  alpha = atan2(yy,xx);
  
  yy = (double) (pPointArray[check].where.v - pPointArray[x].where.v);
  xx = (double) (pPointArray[check].where.h - pPointArray[x].where.h);
  beta = atan2(yy,xx) - alpha;
  if (beta <= 0) beta += Deux_Pi;
  
  return ((beta >= 0) && (beta <= Pi));
}

/* This routine insert the point 'newPoint' in the list dlist,
   respecting the clock-wise orientation.                              */
  
int DListInsert(DListRecord **dlist, MPoint center, PointNumero newPoint){
  DListRecord  *p, *newp;
  double        alpha1,alpha,beta,xx,yy;
  int           first;

  newp = (DListRecord*) Malloc(sizeof(DListRecord));
  newp->point_num = newPoint;

  if (*dlist == NULL){
    *dlist = newp;
    Pred(*dlist) = newp;
    Succ(*dlist) = newp;
    return(1);
  }
  if (Succ(*dlist) == *dlist){
    Pred(*dlist) = newp;
    Succ(*dlist) = newp;
    Pred(newp) = *dlist;
    Succ(newp) = *dlist;
    return(1);
  }
  /*  If we are here, the double-linked circular list has 2 or more
      elements, so we have to calculate where to put the new one.          */
  
  p = *dlist;
  first = p->point_num;
  
  /* first, compute polar coord. of the first point.     */
  yy = (double) (pPointArray[first].where.v - center.v);
  xx = (double) (pPointArray[first].where.h - center.h);
  alpha1 = atan2(yy,xx);
  
  /* compute polar coord of the point to insert. */
  yy = (double) (pPointArray[newPoint].where.v - center.v);
  xx = (double) (pPointArray[newPoint].where.h - center.h);
  beta = atan2(yy,xx) - alpha1;
  if (beta <= 0) beta += Deux_Pi;
  
  do{
    yy = (double) (pPointArray[Succ(p)->point_num].where.v - center.v);
    xx = (double) (pPointArray[Succ(p)->point_num].where.h - center.h);
    alpha = atan2(yy,xx) - alpha1;
    if (alpha <= 1.e-15) alpha += Deux_Pi;
    if (alpha >= beta){
      Succ(newp) = Succ(p);
      Succ(p) = newp;
      Pred(newp) = p;
      Pred(Succ(newp)) = newp;
      return(1);
    }
    p = Succ(p);
  } while (p != *dlist);
  
  /*** ON NE DOIT JAMAIS ARRIVER ICI ***/
  return(0);
} 

int Insert(PointNumero a,PointNumero b){
  int rslt;
  
  /* This routine inserts the point 'a' in the adjency list of 'b' and
     the point 'b' in the adjency list of 'a'.          */
  
  rslt = DListInsert(&pPointArray[a].adjacent,pPointArray[a].where,b);
  rslt &= DListInsert(&pPointArray[b].adjacent,pPointArray[b].where,a);

  return rslt;
}



int DListDelete(DListPeek *dlist,PointNumero oldPoint){
  DListPeek     p;
  
  if (*dlist == NULL)
    return(0);              
  if (Succ(*dlist) == *dlist){
    if ((*dlist)->point_num == oldPoint){
      Free(*dlist);
      *dlist = NULL;
      return(1);
    }
    else
      return(0); 
  }
  p = *dlist;
  do{
    if (p->point_num == oldPoint){
      Succ(Pred(p)) = Succ(p);
      Pred(Succ(p)) = Pred(p);
      if (p == *dlist){
        *dlist = Succ(p);
      }
      Free(p);
      return(1);
    }
    p = Succ(p);
  } while (p != *dlist);
  
  return(0);
}


/* This routine removes the point 'a' in the adjency list of 'b' and
   the point 'b' in the adjency list of 'a'.          */
  
int Delete(PointNumero a,PointNumero b){
  int  rslt;
  
  rslt = DListDelete(&pPointArray[a].adjacent,b);
  rslt &= DListDelete(&pPointArray[b].adjacent,a);

  return rslt;
}

/*  Cette routine efface toutes les listes d'adjacence du pPointArray. */

void remove_all_dlist(int n, PointRecord *pPointArray){
  int       i;
  DListPeek p,temp;
  
  for (i=0;i<n;i++)
    if (pPointArray[i].adjacent != NULL){
      p = pPointArray[i].adjacent;
      do{
        temp = p;
        p = Pred(p);
        Free(temp);          
      } while (p != pPointArray[i].adjacent);
      pPointArray[i].adjacent = NULL;     
    }
}

