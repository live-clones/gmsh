// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

// Triangulation using a divide and conquer algorithm
//
// The main idea is to be able to merge two Delaunay triangulations
// into a single one (see the 'Merge' function). Points are then
// separated into two groups, then each group into two, ... until
// having 1, 2 or 3 points (the triangulation is then trivial).
//
// This is used to contruct the initial mesh.
//
// Warning: point positions must be PERTURBED by a small random
// value to avoid 3 aligned points or 4 cocyclical points!

#include "GmshMessage.h"
#include "DivideAndConquer.h"
#include "Numeric.h"
#include "robustPredicates.h"

#define Pred(x) ((x)->prev)
#define Succ(x) ((x)->next)

PointNumero DocRecord::Predecessor(PointNumero a, PointNumero b)
{
  DListPeek p = points[a].adjacent;
  if(p == NULL)
    return -1;

  do {
    if(p->point_num == b)
      return Pred(p)->point_num;
    p = Pred(p);
  } while(p != points[a].adjacent);

  return -1;
}

PointNumero DocRecord::Successor(PointNumero a, PointNumero b)
{
  DListPeek p = points[a].adjacent;
  if(p == NULL)
    return -1;

  do {
    if(p->point_num == b)
      return Succ(p)->point_num;
    p = Succ(p);
  } while(p != points[a].adjacent);

  return -1;
}

int DocRecord::FixFirst(PointNumero x, PointNumero f)
{
  DListPeek p = points[x].adjacent;
  if(p == NULL)
    return 0;

  int out = 0;
  DListPeek copy = p;
  do {
    if(p->point_num == f) {
      points[x].adjacent = p;
      out = 1;
    }
    else
      p = p->next;
  } while((p != copy) && !out);
  return out;
}

PointNumero DocRecord::First(PointNumero x)
{
  return (points[x].adjacent)->point_num;
}

int DocRecord::IsLeftOf(PointNumero x, PointNumero y, PointNumero check)
{
  double pa[2] = {(double)points[x].where.h, (double)points[x].where.v};
  double pb[2] = {(double)points[y].where.h, (double)points[y].where.v};
  double pc[2] = {(double)points[check].where.h, (double)points[check].where.v};

  // we use robust predicates here
  double result = robustPredicates::orient2d(pa, pb, pc);

  return result > 0;
}

int DocRecord::IsRightOf(PointNumero x, PointNumero y, PointNumero check)
{
  return IsLeftOf(y, x, check);
}

Segment DocRecord::LowerCommonTangent(DT vl, DT vr)
{
  PointNumero x, y, z, z1, z2, temp;
  Segment s;

  x = vl.end;   // vu le tri, c'est le point le + a droite
  y = vr.begin; // idem, le + a gauche
  z = First(y);
  z1 = First(x);
  z2 = Predecessor(x, z1);
  for(;;) {
    if(IsRightOf(x, y, z)) {
      temp = z;
      z = Successor(z, y);
      y = temp;
    }
    else if(IsRightOf(x, y, z2)) {
      temp = z2;
      z2 = Predecessor(z2, x);
      x = temp;
    }
    else {
      s.from = x;
      s.to = y;
      return s;
    }
  }
}

Segment DocRecord::UpperCommonTangent(DT vl, DT vr)
{
  PointNumero x, y, z, z1, z2, temp;
  Segment s;

  x = vl.end;   // vu le tri, c'est le point le + a droite
  y = vr.begin; // idem, le + a gauche
  z = First(y);
  z1 = First(x);
  z2 = Predecessor(y, z);
  for(;;) {
    if(IsLeftOf(x, y, z2)) {
      temp = z2;
      z2 = Predecessor(z2, y);
      y = temp;
    }
    else if(IsLeftOf(x, y, z1)) {
      temp = z1;
      z1 = Successor(z1, x);
      x = temp;
    }
    else {
      s.from = x;
      s.to = y;
      return s;
    }
  }
}

// return 1 if the point k is NOT in the circumcircle of triangle  hij
int DocRecord::Qtest(PointNumero h, PointNumero i, PointNumero j, PointNumero k)
{
  if((h == i) && (h == j) && (h == k)) {
    Msg::Error("Identical points in triangulation: increase element size "
               "or Mesh.RandomFactor");
    return 0;
  }
  
  double pa[2] = {(double)points[h].where.h, (double)points[h].where.v};
  double pb[2] = {(double)points[i].where.h, (double)points[i].where.v};
  double pc[2] = {(double)points[j].where.h, (double)points[j].where.v};
  double pd[2] = {(double)points[k].where.h, (double)points[k].where.v};

  // we use robust predicates here  
  double result = robustPredicates::incircle(pa, pb, pc, pd) * 
    robustPredicates::orient2d(pa, pb, pc);
  
  return (result < 0) ? 1 : 0;
}

int DocRecord::Merge(DT vl, DT vr)
{
  Segment bt, ut;
  int a, b, out;
  PointNumero r, r1, r2, l, l1, l2;

  bt = LowerCommonTangent(vl, vr);
  ut = UpperCommonTangent(vl, vr);
  l = bt.from;  // left endpoint of BT
  r = bt.to;    // right endpoint of BT

  while((l != ut.from) || (r != ut.to)) {
    a = b = 0;
    if(!Insert(l, r))
      return 0;

    r1 = Predecessor(r, l);
    if(r1 == -1)
      return 0;
    if(IsRightOf(l, r, r1))
      a = 1;
    else {
      out = 0;
      while(!out) {
        r2 = Predecessor(r, r1);
        if(r2 == -1)
          return 0;
        if(r2 < vr.begin)
          out = 1;
        else if(Qtest(l, r, r1, r2))
          out = 1;
        else {
          if(!Delete(r, r1))
            return 0;
          r1 = r2;
          if(IsRightOf(l, r, r1))
            out = a = 1;
        }
      }
    }

    l1 = Successor(l, r);
    if(l1 == -1)
      return 0;
    if(IsLeftOf(r, l, l1))
      b = 1;
    else {
      out = 0;
      while(!out) {
        l2 = Successor(l, l1);
        if(l2 == -1)
          return 0;
        if(l2 > vl.end)
          out = 1;
        else if(Qtest(r, l, l1, l2))
          out = 1;
        else {
          if(!Delete(l, l1))
            return 0;
          l1 = l2;
          if(IsLeftOf(r, l, l1))
            out = b = 1;
        }
      }
    }

    if(a)
      l = l1;
    else if(b)
      r = r1;
    else {
      if(Qtest(l, r, r1, l1))
        r = r1;
      else
        l = l1;
    }
  }
  if(!Insert(l, r))
    return 0;

  if(!FixFirst(ut.to, ut.from))
    return 0;
  if(!FixFirst(bt.from, bt.to))
    return 0;
  return 1;
}

DT DocRecord::RecurTrig(PointNumero left, PointNumero right)
{
  int n, m;
  DT dt;

  dt.begin = left;
  dt.end = right;
  n = right - left + 1; // nombre de points a triangulariser
  switch (n) {
  case 0:
  case 1:
    // 0 ou 1 points -> rien a faire
    break;

  case 2: // deux points : cas trivial
    Insert(left, right);
    FixFirst(left, right);
    FixFirst(right, left);
    break;

  case 3: // trois points : cas trivial
    Insert(left, right);
    Insert(left, left + 1);
    Insert(left + 1, right);
    if(IsRightOf(left, right, left + 1)) {
      FixFirst(left, left + 1);
      FixFirst(left + 1, right);
      FixFirst(right, left);
    }
    else {
      FixFirst(left, right);
      FixFirst(left + 1, left);
      FixFirst(right, left + 1);
    }
    break;

  default: // plus de trois points : cas recursif
    m = (left + right) >> 1;
    if(!Merge(RecurTrig(left, m), RecurTrig(m + 1, right)))
      break;
  }
  return dt;
}

static int comparePoints(const void *i, const void *j)
{
  double x, y;

  x = ((PointRecord *) i)->where.h - ((PointRecord *) j)->where.h;
  if(x == 0.) {
    y = ((PointRecord *) i)->where.v - ((PointRecord *) j)->where.v;
    return (y < 0.) ? -1 : 1;
  }
  else
    return (x < 0.) ? -1 : 1;
}

// this fonction builds the delaunay triangulation for a window
int DocRecord::BuildDelaunay()
{
  qsort(points, numPoints, sizeof(PointRecord), comparePoints);
  RecurTrig(0, numPoints - 1);
  return 1;
}

// This routine insert the point 'newPoint' in the list dlist,
// respecting the clock-wise orientation
int DocRecord::DListInsert(DListRecord **dlist, DPoint center, PointNumero newPoint)
{
  DListRecord *p, *newp;
  double alpha1, alpha, beta, xx, yy;
  int first;

  newp = new DListRecord;
  newp->point_num = newPoint;

  if(*dlist == NULL) {
    *dlist = newp;
    Pred(*dlist) = newp;
    Succ(*dlist) = newp;
    return 1;
  }
  if(Succ(*dlist) == *dlist) {
    Pred(*dlist) = newp;
    Succ(*dlist) = newp;
    Pred(newp) = *dlist;
    Succ(newp) = *dlist;
    return 1;
  }

  // If we are here, the double-linked circular list has 2 or more
  // elements, so we have to calculate where to put the new one

  p = *dlist;
  first = p->point_num;

  // first, compute polar coord. of the first point
  yy = (double)(points[first].where.v - center.v);
  xx = (double)(points[first].where.h - center.h);
  alpha1 = atan2(yy, xx);

  // compute polar coord of the point to insert
  yy = (double)(points[newPoint].where.v - center.v);
  xx = (double)(points[newPoint].where.h - center.h);
  beta = atan2(yy, xx) - alpha1;
  if(beta <= 0)
    beta += 2. * M_PI;

  do {
    yy = (double)(points[Succ(p)->point_num].where.v - center.v);
    xx = (double)(points[Succ(p)->point_num].where.h - center.h);
    alpha = atan2(yy, xx) - alpha1;
    if(alpha <= 1.e-15)
      alpha += 2. * M_PI;
    if(alpha >= beta) {
      Succ(newp) = Succ(p);
      Succ(p) = newp;
      Pred(newp) = p;
      Pred(Succ(newp)) = newp;
      return 1;
    }
    p = Succ(p);
  } while(p != *dlist);

  // never here!
  return 0;
}

// This routine inserts the point 'a' in the adjency list of 'b' and
// the point 'b' in the adjency list of 'a'
int DocRecord::Insert(PointNumero a, PointNumero b)
{
  int rslt = DListInsert(&points[a].adjacent, points[a].where, b);
  rslt &= DListInsert(&points[b].adjacent, points[b].where, a);
  return rslt;
}

int DocRecord::DListDelete(DListPeek *dlist, PointNumero oldPoint)
{
  DListPeek p;

  if(*dlist == NULL)
    return 0;
  if(Succ(*dlist) == *dlist) {
    if((*dlist)->point_num == oldPoint) {
      delete *dlist;
      *dlist = NULL;
      return 1;
    }
    else
      return 0;
  }
  p = *dlist;
  do {
    if(p->point_num == oldPoint) {
      Succ(Pred(p)) = Succ(p);
      Pred(Succ(p)) = Pred(p);
      if(p == *dlist) {
        *dlist = Succ(p);
      }
      delete p;
      return 1;
    }
    p = Succ(p);
  } while(p != *dlist);

  return 0;
}

// This routine removes the point 'a' in the adjency list of 'b' and
// the point 'b' in the adjency list of 'a'
int DocRecord::Delete(PointNumero a, PointNumero b)
{
  int rslt = DListDelete(&points[a].adjacent, b);
  rslt &= DListDelete(&points[b].adjacent, a);
  return rslt;
}

// compte les points sur le polygone convexe
int DocRecord::CountPointsOnHull()
{
  PointNumero p, p2, temp;
  int i, n=numPoints;

  if(points[0].adjacent == NULL)
    return 0;
  i = 1;
  p = 0;
  p2 = First(0);
  while((p2 != 0) && (i < n)) {
    i++;
    temp = p2;
    p2 = Successor(p2, p);
    p = temp;
  }
  return (i <= n) ? i : -1;
}

// compte les points sur le polygone convexe
void DocRecord::ConvexHull()
{
  PointNumero p, p2, temp;

  if(points[0].adjacent == NULL)
    return;
  int count = 0;
  p = 0;
  _hull[count++] = p;
  p2 = First(0);
  while((p2 != 0) && (count < numPoints)) {
    temp = p2;
    p2 = Successor(p2, p);
    p = temp;
    _hull[count++] = p;
  }
}

PointNumero *DocRecord::ConvertDlistToArray(DListPeek *dlist, int *n)
{
  DListPeek p, temp;
  int i, max = 0;
  PointNumero *ptr;

  p = *dlist;
  do {
    max++;
    p = Pred(p);
  } while(p != *dlist);
  ptr = new PointNumero[max + 1];
  if(ptr == NULL)
    return NULL;
  p = *dlist;
  for(i = 0; i < max; i++) {
    ptr[i] = p->point_num;
    temp = p;
    p = Pred(p);
    delete temp;
  }
  ptr[max] = ptr[0];
  *dlist = NULL;
  *n = max;
  return ptr;
}

// build ready to use voronoi datas
void DocRecord::ConvertDListToVoronoiData()
{
  if (_adjacencies){
    for(int i = 0; i < numPoints; i++)
      if (_adjacencies[i].t) 
        delete [] _adjacencies[i].t;
    delete [] _adjacencies;
  }  
  if (_hull)delete [] _hull;
  _hullSize = CountPointsOnHull ();
  _hull = new PointNumero[_hullSize];
  ConvexHull();
  std::sort(_hull, _hull+_hullSize);
  _adjacencies = new STriangle[numPoints];
  
  for(PointNumero i = 0; i < numPoints; i++) 
    _adjacencies[i].t = ConvertDlistToArray(&points[i].adjacent,
                                            &_adjacencies[i].t_length);    
}

void DocRecord::voronoiCell(PointNumero pt, std::vector<SPoint2> &pts) const
{
  if (!_adjacencies){
    printf("no adjacencies were created\n");
    throw;
  }
  const int n = _adjacencies[pt].t_length;
  for(int j = 0; j < n; j++) {
    PointNumero a = _adjacencies[pt].t[j];
    PointNumero b = _adjacencies[pt].t[(j+1) %n];
    double pa[2] = {(double)points[a].where.h, (double)points[a].where.v};
    double pb[2] = {(double)points[b].where.h, (double)points[b].where.v};
    double pc[2] = {(double)points[pt].where.h, (double)points[pt].where.v};
    double center[2];
    circumCenterXY (pa,pb,pc,center);
    pts.push_back(SPoint2(center[0],center[1]));
  }
}

/*
  Consider N points {X_1, \dots, X_N}
  We want to find the point X_P that verifies
  
  min max | X_i - X_P | , i=1,\dots,N

  L2 norm

  min \int_V || X - X_P||^2 dv 

  =>  2 \int_V || X - X_P|| dv = 0 => X_P is the centroid 

  min \int_V || X - X_P||^{2m} dv 

  =>  2 \int_V || X - X_P||^{2m-1} dv = 0 => X_P is somewhere ...

  now in infinite norm, how to find X_P ?

*/

void DocRecord::makePosView(std::string fileName)
{
  FILE *f = fopen(fileName.c_str(),"w");
   if (_adjacencies){
    fprintf(f,"View \"voronoi\" {\n");
    for(PointNumero i = 0; i < numPoints; i++) {
      std::vector<SPoint2> pts;
      double pc[2] = {(double)points[i].where.h, (double)points[i].where.v};
      if (!onHull(i)){
        fprintf(f,"SP(%g,%g,%g)  {%g};\n",pc[0],pc[1],0.0,(double)i);
        voronoiCell (i,pts);
        for (unsigned int j = 0; j < pts.size(); j++){
          fprintf(f,"SL(%g,%g,%g,%g,%g,%g)  {%g,%g};\n",
                  pts[j].x(),pts[j].y(),0.0,
                  pts[(j+1)%pts.size()].x(),pts[(j+1)%pts.size()].y(),0.0,
                  (double)i,(double)i);
        }
      }
      else {
        fprintf(f,"SP(%g,%g,%g)  {%g};\n",pc[0],pc[1],0.0,-(double)i);
      }
    }
    fprintf(f,"};\n");    
  }
  fclose(f);
}

void centroidOfOrientedBox(std::vector<SPoint2> &pts, const double &angle,
                           double &xc, double &yc, double &inertia, double &area)
{
  const int N = pts.size();
  
  double sina = sin(angle);
  double cosa = cos(angle);
  
  double xmin = cosa* pts[0].x()+ sina*pts[0].y();
  double xmax = cosa* pts[0].x()+ sina*pts[0].y();
  double ymin = -sina* pts[0].x()+ cosa*pts[0].y();
  double ymax = -sina* pts[0].x()+ cosa*pts[0].y();
  for (int j=1;j<N;j++){
    xmin = std::min(cosa* pts[j].x()+ sina*pts[j].y(),xmin);
    ymin = std::min(-sina* pts[j].x()+ cosa*pts[j].y(),ymin);
    xmax = std::max(cosa* pts[j].x()+ sina*pts[j].y(),xmax);
    ymax = std::max(-sina* pts[j].x()+ cosa*pts[j].y(),ymax);
  }
  double XC = 0.5*(xmax+xmin);
  double YC = 0.5*(ymax+ymin);
  xc = XC*cosa - YC *sina;
  yc = XC*sina + YC *cosa;
  inertia = std::max(xmax-xmin,ymax-ymin);
  area = (xmax-xmin) * (ymax-ymin);
}

void centroidOfPolygon(SPoint2 &pc, std::vector<SPoint2> &pts,
                       double &xc, double &yc, double &inertia, double &areaCell,
                       simpleFunction<double> *bgm)
{
  double area_tot = 0;
  areaCell = 0.0;
  SPoint2 center(0,0);
  for (unsigned int j = 0; j < pts.size(); j++){
    SPoint2 &pa = pts[j];
    SPoint2 &pb = pts[(j+1)%pts.size()];
    const double area  = triangle_area2d(pa,pb,pc);         
    const double lc = bgm ? (*bgm)((pa.x()+pb.x()+pc.x())/3.0,
                                   (pa.y()+pb.y()+pc.y())/3.0,
                                   0.0) : 1.0;
    const double fact = 1./(lc*lc*lc*lc);//rho = 1/lc^4 (emi)
    areaCell += area;
    area_tot += area*fact;
    center += ((pa+pb+pc) * (area*fact/3.0));
  }
  SPoint2 x = center * (1.0/area_tot);
  inertia = 0;
  for (unsigned int j = 0; j < pts.size(); j++){
    SPoint2 &pa = pts[j];
    SPoint2 &pb = pts[(j+1)%pts.size()];
    const double area  = triangle_area2d(pa,pb,pc);     
    
    const double b = sqrt (  (pa.x()-pb.x())*(pa.x()-pb.x()) + 
                             (pa.y()-pb.y())*(pa.y()-pb.y()) );
    const double h = 2.0 * area / b;
    const double a = fabs((pb.x()-pa.x())*(pc.x()-pa.x())*
                          (pb.y()-pa.y())*(pc.y()-pa.y()))/b;
    
    const double j2 = (h*b*b*b + h*a*b*b + h*a*a*b + b*h*h*h) / 12.0;
    
    center = (pa+pb+pc) * (1.0/3.0);
    const SPoint2 dx = x - center;
    inertia += j2 + area*area*(dx.x()+dx.x()+dx.y()*dx.y());
  }
  xc = x.x();
  yc = x.y();
}

double DocRecord::Lloyd(int type)
{
  fullMatrix<double> cgs(numPoints,2);
  double inertia_tot = 0.;
  for(PointNumero i = 0; i < numPoints; i++) {
    PointRecord &pt = points[i];
    std::vector<SPoint2> pts;
    voronoiCell (i,pts); 
    double E, A;
    
    if (!points[i].data){
      SPoint2 p (pt.where.h,pt.where.v);
      if (type == 0)    
        centroidOfPolygon (p,pts, cgs(i,0), cgs(i,1),E, A);              
      else 
        centroidOfOrientedBox (pts, 0.0, cgs(i,0),cgs(i,1),E, A);    
    }
    inertia_tot += E;
  } 
  
  for(PointNumero i = 0; i < numPoints; i++) {
    if (!points[i].data){
      points[i].where.h = cgs(i,0);
      points[i].where.v = cgs(i,1);
    }
  }
  return inertia_tot;
}

// Convertir les listes d'adjacence en triangles
int DocRecord::ConvertDListToTriangles()
{
  // on suppose que n >= 3. points est suppose OK.

  int n = numPoints, i, j;
  int count = 0, count2 = 0;
  PointNumero aa, bb, cc;

  STriangle *striangle = new STriangle[n];

  count2 = CountPointsOnHull();

  // nombre de triangles que l'on doit obtenir
  count2 = 2 * (n - 1) - count2;

  // FIXME ::: WHY 2 * ???????????????????
  triangles = new Triangle[2 * count2];

  for(i = 0; i < n; i++) {
    // on cree une liste de points connectes au point i (t) + nombre
    // de points (t_length)
    striangle[i].t = ConvertDlistToArray(&points[i].adjacent,
                                         &striangle[i].t_length);
  }

  // on balaye les noeuds de gauche a droite -> on cree les triangles
  count = 0;
  for(i = 0; i < n; i++) {
    for(j = 0; j < striangle[i].t_length; j++) {
      if((striangle[i].t[j] > i) && (striangle[i].t[j + 1] > i) &&
         (IsRightOf(i, striangle[i].t[j], striangle[i].t[j + 1]))) {
        aa = i;
        bb = striangle[i].t[j];
        cc = striangle[i].t[j + 1];
        triangles[count].a = aa;
        triangles[count].b = bb;
        triangles[count].c = cc;
        count++;
      }
    }
  }
  numTriangles = count2;

  for(int i = 0; i < n; i++)
    delete [] striangle[i].t;
  delete []striangle;

  return 1;
}

//  Cette routine efface toutes les listes d'adjacence de points
void DocRecord::RemoveAllDList()
{
  int i;
  DListPeek p, temp;

  for(i = 0; i < numPoints; i++)
    if(points[i].adjacent != NULL) {
      p = points[i].adjacent;
      do {
        temp = p;
        p = Pred(p);
        delete temp;
      } while(p != points[i].adjacent);
      points[i].adjacent = NULL;
    }
}

DocRecord::DocRecord(int n) 
  : _hullSize(0), _hull(NULL), _adjacencies(NULL),
    numPoints(n), points(NULL), numTriangles(0), triangles(NULL)
{
  if(numPoints)
    points = new PointRecord[numPoints];
}

DocRecord::~DocRecord()
{
  if(points) delete [] points;
  if(triangles) delete []triangles;
  if(_hull) delete [] _hull;
  if (_adjacencies){
    for(int i = 0; i < numPoints; i++)
      delete [] _adjacencies[i].t;
    delete _adjacencies;
  }
}

void DocRecord::MakeMeshWithPoints()
{
  if(numPoints < 3) return;
  BuildDelaunay();
  ConvertDListToTriangles();
  RemoveAllDList();
}

void DocRecord::Voronoi()
{
  if(numPoints < 3) return;
  BuildDelaunay();
  ConvertDListToVoronoiData();
}

void DocRecord::setPoints(fullMatrix<double> *p)
{ 
  if (numPoints != p->size1())throw;
  for (int i = 0; i < p->size1(); i++){
    x(i) = (*p)(i, 0);
    y(i) = (*p)(i, 1);
    data(i) = (*p)(i, 2) < 0  ? (void *) 1 : NULL;
  }
} 

#include "Bindings.h"

void DocRecord::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<DocRecord>("Triangulator");
  cb->setDescription("A class that does 2D delaunay triangulation "
                     "(JF's SANDBOX for the moment)");
  methodBinding *cm;

  cm = cb->addMethod("setPoints", &DocRecord::setPoints);
  cm->setDescription("Set the NumPoints points of the triangulation (x,y,fixed)");
  cm->setArgNames("points",NULL);
  cm = cb->addMethod("Triangulate", &DocRecord::MakeMeshWithPoints);
  cm->setDescription("Compute the Delaunay triangulation");
  cm = cb->addMethod("Voronoi", &DocRecord::Voronoi);
  cm->setDescription("Compute the Voronoi cells");
  cm = cb->addMethod("hullSize", &DocRecord::hullSize);
  cm->setDescription("returns the size of the hull");
  cm = cb->addMethod("makePosView", &DocRecord::makePosView);
  cm->setDescription("save a .pos file with the voronoi");
  cm->setArgNames("FileName",NULL);
  cm = cb->addMethod("Lloyd", &DocRecord::Lloyd);
  cm->setDescription("do one iteration of Lloyd's algorithm");
  cm->setArgNames("Type",NULL);
  cm = cb->setConstructor<DocRecord,int>();
  cm->setDescription ("A Triangulator");
  cm->setArgNames("NumPoints",NULL);
}
