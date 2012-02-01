// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GModel.h"
#include "meshGEdge.h"
#include "GEdge.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Context.h"
#include "STensor3.h"
#include "Field.h"

#define SQU(a)      ((a)*(a))

typedef struct {
  int Num;
  // t is the local coordinate of the point
  // lc is x'(t)/h((x(t))
  // p is the value of the primitive
  // xp is the norm of the tangent vector
  double t, lc, p, xp;
} IntPoint;


static double smoothPrimitive (GEdge *ge,
			       double alpha,
			       std::vector<IntPoint> &Points)
{
  for (int i=0; i< Points.size(); i++){
    IntPoint &pt = Points[i];
    SVector3 der = ge->firstDer(pt.t);
    pt.xp = der.norm();
  }
  int ITER = 0;
  while (1){
    int count1 = 0;
    int count2 = 0;

    // use a gauss-seidel iteration
    // iterate forward and then backward
    // convergence is usually very fast.
    for (int i=1; i< Points.size(); i++){
      double hprime;
      hprime =  ((Points[i].xp/Points[i].lc) - (Points[i-1].xp/Points[i-1].lc))/(Points[i].t - Points[i-1].t);
      if (hprime * Points[i].xp > alpha*1.01){
	double hnew = Points[i-1].xp / Points[i-1].lc + (Points[i].t - Points[i-1].t) * alpha / Points[i].xp;
	Points[i].lc = Points[i].xp / hnew;
	count1 ++;
      }
    }

    for (int i=Points.size()-1; i>0 ; i--){
      double hprime;
      hprime =  ((Points[i].xp/Points[i].lc) - (Points[i-1].xp/Points[i-1].lc))/(Points[i].t - Points[i-1].t);
      if (-hprime * Points[i].xp > alpha*1.01){
      	double hnew = Points[i].xp / Points[i].lc + (Points[i].t - Points[i-1].t) * alpha / Points[i-1].xp;
      	Points[i-1].lc = Points[i-1].xp / hnew;
      	count2 ++;
      }
    }

    
    ++ITER;
    if (ITER > 1000){printf("OUUUUUH\n");break;}
    if (!(count1+count2))break;
  }
  // recompute the primitive
  for (int i=1; i< Points.size(); i++){
    IntPoint &pt2 = Points[i];
    IntPoint &pt1 = Points[i-1];
    pt2.p = pt1.p + (pt2.t-pt1.t)*0.5*(pt2.lc+pt1.lc);
  }
  return Points[Points.size()-1].p;
}

static double F_Lc(GEdge *ge, double t)
{
  GPoint p = ge->point(t);
  double lc_here;

  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  if(t == t_begin)
    lc_here = BGM_MeshSize(ge->getBeginVertex(), t, 0, p.x(), p.y(), p.z());
  else if(t == t_end)
    lc_here = BGM_MeshSize(ge->getEndVertex(), t, 0, p.x(), p.y(), p.z());
  else
    lc_here = BGM_MeshSize(ge, t, 0, p.x(), p.y(), p.z()); 
 
  SVector3 der = ge->firstDer(t);
  const double d = norm(der);
  return d / lc_here; 

  //  SMetric3 metric(1. / (lc_here * lc_here));
  //  double lSquared = dot(der, metric, der);

  //  return sqrt(lSquared);
}

static double F_Lc_aniso(GEdge *ge, double t)
{
  GPoint p = ge->point(t);
  SMetric3 lc_here;

  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  if(t == t_begin)
    lc_here = BGM_MeshMetric(ge->getBeginVertex(), t, 0, p.x(), p.y(), p.z());
  else if(t == t_end)
    lc_here = BGM_MeshMetric(ge->getEndVertex(), t, 0, p.x(), p.y(), p.z());
  else
    lc_here = BGM_MeshMetric(ge, t, 0, p.x(), p.y(), p.z());

  SVector3 der = ge->firstDer(t);

  double lSquared = dot(der, lc_here, der);

  /*
  if (ge->tag() == 3){
    printf("%12.5E %12.5E\n",p.x(),1./sqrt(lSquared));
  }
  */
  //  der.normalize();
  //  printf("in the function %g n %g %g\n", sqrt(lSquared),der.x(),der.y());

  return sqrt(lSquared);
}

static double F_Transfinite(GEdge *ge, double t_)
{
  double length = ge->length();
  if(length == 0.0){
    Msg::Error("Zero-length curve in transfinite mesh");
    return 1.;
  }

  SVector3 der = ge->firstDer(t_) ;
  double d = norm(der);
  double coef = ge->meshAttributes.coeffTransfinite;
  int type = ge->meshAttributes.typeTransfinite;
  int nbpt = ge->meshAttributes.nbPointsTransfinite;

  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();
  double t = (t_ - t_begin)/(t_end-t_begin);

  double val;

  if(coef <= 0.0 || coef == 1.0) {
    // coef < 0 should never happen
    val = d * coef / ge->length();
  }
  else {
    switch (std::abs(type)) {

    case 1: // Geometric progression ar^i; Sum of n terms = length = a (r^n-1)/(r-1)
      {
        double r = (sign(type) >= 0) ? coef : 1. / coef;
        double a = length * (r - 1.) / (pow(r, nbpt - 1.) - 1.);
        int i = (int)(log(t * length / a * (r - 1.) + 1.) / log(r));
        val = d / (a * pow(r, (double)i));
      }
      break;
        
    case 2: // Bump
      {
        double a;
        if(coef > 1.0) {
          a = -4. * sqrt(coef - 1.) * atan2(1., sqrt(coef - 1.)) /
            ((double)nbpt *  length);
        }
        else {
          a = 2. * sqrt(1. - coef) * log(fabs((1. + 1. / sqrt(1. - coef)) /
                                              (1. - 1. / sqrt(1. - coef))))
            / ((double)nbpt * length);
        }
        double b = -a * length * length / (4. * (coef - 1.));
        val = d / (-a * SQU(t * length - (length) * 0.5) + b);
      }
      break;
      
    default:
      Msg::Warning("Unknown case in Transfinite Line mesh");
      val = 1.;
      break;
    }
  }
  return val;
}

static double F_One(GEdge *ge, double t)
{
  SVector3 der = ge->firstDer(t) ;
  return norm(der);
}

static double trapezoidal(IntPoint * P1, IntPoint * P2)
{
  return (0.5 * (P1->lc + P2->lc) * (P2->t - P1->t));
}

static void RecursiveIntegration(GEdge *ge, IntPoint *from, IntPoint *to,
                                 double (*f) (GEdge *e, double X), 
                                 std::vector<IntPoint> &Points,
                                 double Prec, int *depth)
{
  IntPoint P, p1;

  (*depth)++;

  P.t = 0.5 * (from->t + to->t);
  P.lc = f(ge, P.t);

  double val1 = trapezoidal(from, to);
  double val2 = trapezoidal(from, &P);
  double val3 = trapezoidal(&P, to);
  double err = fabs(val1 - val2 - val3);

  if(((err < Prec) && (*depth > 1)) || (*depth > 25)) {
    p1=Points.back();
    P.p = p1.p + val2;
    Points.push_back(P);

    p1=Points.back();
    to->p = p1.p + val3;
    Points.push_back(*to);
  }
  else {
    RecursiveIntegration(ge, from, &P, f, Points, Prec, depth);
    RecursiveIntegration(ge, &P, to, f, Points, Prec, depth);
  }

  (*depth)--;
}

static double Integration(GEdge *ge, double t1, double t2, 
                          double (*f) (GEdge *e, double X),
                          std::vector<IntPoint> &Points, double Prec)
{
  IntPoint from, to;

  int depth = 0;

  from.t = t1;
  from.lc = f(ge, from.t);
  from.p = 0.0;
  Points.push_back(from);
  
  to.t = t2;
  to.lc = f(ge, to.t);
  
  RecursiveIntegration(ge, &from, &to, f, Points, Prec, &depth);
  
  return Points.back().p;
}

static void copyMesh(GEdge *from, GEdge *to, int direction)
{
  Range<double> u_bounds = from->parBounds(0);
  double u_min = u_bounds.low();
  double u_max = u_bounds.high();

  for(unsigned int i = 0; i < from->mesh_vertices.size(); i++){
    int index = (direction < 0) ? (from->mesh_vertices.size() - 1 - i) : i;
    MVertex *v = from->mesh_vertices[index];
    double u; v->getParameter(0, u);
    double newu = (direction > 0) ? u : (u_max - u + u_min);
    GPoint gp = to->point(newu);
    to->mesh_vertices.push_back(new MEdgeVertex(gp.x(), gp.y(), gp.z(), to, newu));
  }
  for(unsigned int i = 0; i < to->mesh_vertices.size() + 1; i++){
    MVertex *v0 = (i == 0) ?
      to->getBeginVertex()->mesh_vertices[0] : to->mesh_vertices[i - 1];
    MVertex *v1 = (i == to->mesh_vertices.size()) ?
      to->getEndVertex()->mesh_vertices[0] : to->mesh_vertices[i];
    to->lines.push_back(new MLine(v0, v1));
  }
}

void deMeshGEdge::operator() (GEdge *ge) 
{
  if(ge->geomType() == GEntity::DiscreteCurve) return;
  ge->deleteMesh();
  ge->meshStatistics.status = GEdge::PENDING;
}

static void printFandPrimitive(int tag, std::vector<IntPoint> &Points)
{
  char name[256];
  sprintf(name, "line%d.dat", tag);
  FILE *f = fopen(name, "w");
  if(!f) return;
  for (unsigned int i = 0; i < Points.size(); i++){
    const IntPoint &P = Points[i];
    fprintf(f, "%g %g %g %g\n", P.t, 1./P.lc, P.p,P.lc);
  }
  fclose(f);
}

void meshGEdge::operator() (GEdge *ge) 
{  
#if defined(HAVE_ANN)
  FieldManager *fields = ge->model()->getFields();
  BoundaryLayerField *blf = 0;
  if(fields->background_field > 0){
    Field *bl_field = fields->get(fields->background_field);
    blf = dynamic_cast<BoundaryLayerField*> (bl_field);
  }
#else
  bool blf = false;
#endif

  ge->model()->setCurrentMeshEntity(ge);

  if(ge->geomType() == GEntity::DiscreteCurve) return;
  if(ge->geomType() == GEntity::BoundaryLayerCurve) return;
  if(ge->meshAttributes.Method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) return;

  // look if we are doing the STL triangulation
  std::vector<MVertex*> &mesh_vertices = ge->mesh_vertices ; 
  std::vector<MLine*> &lines = ge->lines ; 

  deMeshGEdge dem;
  dem(ge);

  if(MeshExtrudedCurve(ge)) return;

  if (ge->meshMaster() != ge->tag()){
    GEdge *gef = ge->model()->getEdgeByTag(abs(ge->meshMaster()));
    if (gef->meshStatistics.status == GEdge::PENDING) return;
    Msg::Info("Meshing curve %d (%s) as a copy of %d", ge->tag(),
              ge->getTypeString().c_str(), ge->meshMaster());
    copyMesh(gef, ge, ge->meshMaster());
    ge->meshStatistics.status = GEdge::DONE;
    return;
  }

  Msg::Info("Meshing curve %d (%s)", ge->tag(), ge->getTypeString().c_str());

  // compute bounds
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();
  
  // first compute the length of the curve by integrating one
  double length;
  std::vector<IntPoint> Points;
  if(ge->geomType() == GEntity::Line && ge->getBeginVertex() == ge->getEndVertex())
    length = 0.; // special case t avoid infinite loop in integration
  else
    length = Integration(ge, t_begin, t_end, F_One, Points, 1.e-8 * CTX::instance()->lc);
  ge->setLength(length);
  Points.clear();

  if(length < CTX::instance()->mesh.toleranceEdgeLength)
    ge->setTooSmall(true);

  // Integrate detJ/lc du 
  double a;
  int N;
  if(length == 0. && CTX::instance()->mesh.toleranceEdgeLength == 0.){
    Msg::Error("Curve %d has a zero length", ge->tag());
    a = 0;
    N = 1;
  }
  else if(ge->degenerate(0)){
    a = 0.;
    N = 1;
  }
  else if(ge->meshAttributes.Method == MESH_TRANSFINITE){
    a = Integration(ge, t_begin, t_end, F_Transfinite, Points, 
                    CTX::instance()->mesh.lcIntegrationPrecision);
    N = ge->meshAttributes.nbPointsTransfinite;
  }
  else{
    if (CTX::instance()->mesh.algo2d == ALGO_2D_BAMG || blf
        /* FIXME || CTX::instance()->mesh.algo2d == ALGO_2D_FRONTAL_QUAD */) {
      a = Integration(ge, t_begin, t_end, F_Lc_aniso, Points,
      			      CTX::instance()->mesh.lcIntegrationPrecision);
      //      printFandPrimitive(ge->tag()+10000, Points);
    }
    else
      a = Integration(ge, t_begin, t_end, F_Lc, Points,
                      CTX::instance()->mesh.lcIntegrationPrecision);
    
    // FIXME JF : MAYBE WE SHOULD NOT ALWAYS SMOOTH THE 1D MESH SIZE FIELD ??
    //printFandPrimitive(ge->tag(), Points);
    // a =  smoothPrimitive (ge,CTX::instance()->mesh.smoothRatio*CTX::instance()->mesh.smoothRatio,Points);
    //    printf(" coucou %g\n",a);
    //printFandPrimitive(ge->tag()+10000, Points);
    
    N = std::max(ge->minimumMeshSegments() + 1, (int)(a + 1.));
  }

  // force odd number of points for if blossom is used for
  // recombination
  if(ge->meshAttributes.Method != MESH_TRANSFINITE && 
     CTX::instance()->mesh.algoRecombine == 1 && N % 2 == 0) N++;

  // printFandPrimitive(ge->tag(),Points);

  // if the curve is periodic and if the begin vertex is identical to
  // the end vertex and if this vertex has only one model curve
  // adjacent to it, then the vertex is not connecting any other
  // curve. So, the mesh vertex and its associated geom vertex are not
  // necessary at the same location
  GPoint beg_p, end_p;
  if(ge->getBeginVertex() == ge->getEndVertex() && 
     ge->getBeginVertex()->edges().size() == 1){
    end_p = beg_p = ge->point(t_begin);
    Msg::Debug("Meshing periodic closed curve");
  }
  else{
    MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
    MVertex *v1 = ge->getEndVertex()->mesh_vertices[0];
    beg_p = GPoint(v0->x(), v0->y(), v0->z());
    end_p = GPoint(v1->x(), v1->y(), v1->z());
  }

  // do not consider the first and the last vertex (those are not
  // classified on this mesh edge)
  if(N > 1){
    const double b = a / (double)(N - 1);
    int count = 1, NUMP = 1;
    IntPoint P1, P2;
    mesh_vertices.resize(N - 2);
    while(NUMP < N - 1) {
      P1 = Points[count - 1];
      P2 = Points[count];
      const double d = (double)NUMP * b;
      if((fabs(P2.p) >= fabs(d)) && (fabs(P1.p) < fabs(d))) {
        double dt = P2.t - P1.t;
        double dlc = P2.lc - P1.lc;
        double dp = P2.p - P1.p;
        double t   = P1.t + dt / dp * (d - P1.p);
        SVector3 der = ge->firstDer(t);
        const double d = norm(der);  
        double lc  = d/(P1.lc + dlc / dp * (d - P1.p));
        GPoint V = ge->point(t);
        mesh_vertices[NUMP - 1] = new MEdgeVertex(V.x(), V.y(), V.z(), ge, t, lc);
        NUMP++;
      }
      else {
        count++;
      }
    }
    mesh_vertices.resize(NUMP - 1);
  }

  for(unsigned int i = 0; i < mesh_vertices.size() + 1; i++){
    MVertex *v0 = (i == 0) ?
      ge->getBeginVertex()->mesh_vertices[0] : mesh_vertices[i - 1];
    MVertex *v1 = (i == mesh_vertices.size()) ?
      ge->getEndVertex()->mesh_vertices[0] : mesh_vertices[i];
    lines.push_back(new MLine(v0, v1));
  }
  
  if(ge->getBeginVertex() == ge->getEndVertex() && 
     ge->getBeginVertex()->edges().size() == 1){
    MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
    v0->x() = beg_p.x();
    v0->y() = beg_p.y();
    v0->z() = beg_p.z();
  }

  ge->meshStatistics.status = GEdge::DONE;
}
