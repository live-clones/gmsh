// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "meshGEdge.h"
#include "GEdge.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Context.h"

#define SQU(a)      ((a)*(a))

typedef struct {
  int Num;
  double t, lc, p;
} IntPoint;

struct xi2lc {
  double xi, lc;
  xi2lc(const double &_xi, const double _lc)
    : xi(_xi), lc(_lc)
  { 
  }
  bool operator < (const xi2lc &other) const
  {
    return xi < other.xi; 
  }
};

static std::vector<xi2lc> interpLc;

static void buildInterpLc(const std::vector<IntPoint> &lcPoints)
{
  IntPoint p;
  interpLc.clear();
  for(unsigned int i = 0; i < lcPoints.size(); i++){
    p = lcPoints[i];
    interpLc.push_back(xi2lc(p.t, p.lc));
  }
}

static double F_Lc_usingInterpLc(GEdge *ge, double t)
{
  std::vector<xi2lc>::iterator it = std::lower_bound(interpLc.begin(),
                                                     interpLc.end(), xi2lc(t, 0));
  double t1 = it->xi;
  double l1 = it->lc;
  it++;
  if(it == interpLc.end()) return l1;
  double t2 = it->xi;
  double l2 = it->lc;
  double l = l1 + ((t - t1) / (t2 - t1)) * (l2 - l1);
  return l;
}

static double F_Lc_usingInterpLcBis(GEdge *ge, double t)
{
  GPoint p = ge->point(t);
  double lc_here;

  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  SVector3 der = ge->firstDer(t);
  const double d = norm(der);

  if(t == t_begin)
    lc_here = BGM_MeshSize(ge->getBeginVertex(), t, 0, p.x(), p.y(), p.z());
  else if(t == t_end)
    lc_here = BGM_MeshSize(ge->getEndVertex(), t, 0, p.x(), p.y(), p.z());
  else
    lc_here = BGM_MeshSize(ge, t, 0, p.x(), p.y(), p.z());

  return d / lc_here;
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
}

static double F_Transfinite(GEdge *ge, double t)
{
  double length = ge->length();
  if(length == 0.0){
    Msg::Error("Zero-length curve in transfinite mesh");
    return 1.;
  }

  SVector3 der = ge->firstDer(t) ;
  double d = norm(der);
  double coef = ge->meshAttributes.coeffTransfinite;
  int type = ge->meshAttributes.typeTransfinite;
  int nbpt = ge->meshAttributes.nbPointsTransfinite;

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

void deMeshGEdge::operator() (GEdge *ge) 
{
  if(ge->geomType() == GEntity::DiscreteCurve) return;

  ge->deleteMesh();
  ge->deleteVertexArrays();
  ge->model()->destroyMeshCaches();
}

void meshGEdge::operator() (GEdge *ge) 
{  
  ge->model()->setCurrentMeshEntity(ge);

  if(ge->geomType() == GEntity::DiscreteCurve) return;
  if(ge->geomType() == GEntity::BoundaryLayerCurve) return;
  if(ge->meshAttributes.Method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) return;

  deMeshGEdge dem;
  dem(ge);

  if(MeshExtrudedCurve(ge)) return;

  Msg::Info("Meshing curve %d (%s)", ge->tag(), ge->getTypeString().c_str());

  // compute bounds
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();
  
  // first compute the length of the curve by integrating one
  std::vector<IntPoint> Points;
  double length = Integration(ge, t_begin, t_end, F_One, Points, 1.e-8 * CTX::instance()->lc);
  ge->setLength(length);
  Points.clear();

  if(length == 0.0)
    Msg::Debug("Curve %d has a zero length", ge->tag());

  // TEST
  if (length < CTX::instance()->mesh.toleranceEdgeLength) ge->setTooSmall(true);

  // Integrate detJ/lc du 
  double a;
  int N;
  if (ge->degenerate(0)){
    a = 0.;
    N = 1;
  }
  else if(ge->meshAttributes.Method == MESH_TRANSFINITE){
    a = Integration(ge, t_begin, t_end, F_Transfinite, Points, 1.e-8);
    N = ge->meshAttributes.nbPointsTransfinite;
  }
  else{
    if(CTX::instance()->mesh.lcIntegrationPrecision > 1.e-8){
      std::vector<IntPoint> lcPoints;
      Integration(ge, t_begin, t_end, F_Lc_usingInterpLcBis, lcPoints, 
                  CTX::instance()->mesh.lcIntegrationPrecision);
      buildInterpLc(lcPoints);
      a = Integration(ge, t_begin, t_end, F_Lc_usingInterpLc, Points, 1.e-8);
    }
    else{
      a = Integration(ge, t_begin, t_end, F_Lc, Points,
		      CTX::instance()->mesh.lcIntegrationPrecision);
    }
    N = std::max(ge->minimumMeshSegments() + 1, (int)(a + 1.));
  }
  
  // if the curve is periodic and if the begin vertex is identical to
  // the end vertex and if this vertex has only one model curve
  // adjacent to it, then the vertex is not connecting any other
  // curve. So, the mesh vertex and its associated geom vertex are not
  // necessary at the same location
  GPoint beg_p, end_p;
  if(ge->getBeginVertex() == ge->getEndVertex() && 
     ge->getBeginVertex()->edges().size() == 1){
    end_p = beg_p = ge->point(t_begin);
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
    ge->mesh_vertices.resize(N - 2);
    while(NUMP < N - 1) {
      P1 = Points[count-1];
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
        ge->mesh_vertices[NUMP - 1] = new MEdgeVertex(V.x(), V.y(), V.z(), ge, t, lc);
        // printf("lc = %12.5E %12.5E \n",lc,P1.lc,P2.lc);
        NUMP++;
      }
      else {
        count++;
      }
    }
    ge->mesh_vertices.resize(NUMP - 1);
  }

  for(unsigned int i = 0; i < ge->mesh_vertices.size() + 1; i++){
    MVertex *v0 = (i == 0) ? 
      ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices[i - 1];
    MVertex *v1 = (i == ge->mesh_vertices.size()) ? 
      ge->getEndVertex()->mesh_vertices[0] : ge->mesh_vertices[i];
    ge->lines.push_back(new MLine(v0, v1));
  }

  if(ge->getBeginVertex() == ge->getEndVertex() && 
     ge->getBeginVertex()->edges().size() == 1){
    MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
    v0->x() = beg_p.x();
    v0->y() = beg_p.y();
    v0->z() = beg_p.z();
  }
}
