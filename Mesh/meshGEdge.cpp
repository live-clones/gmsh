// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "meshGEdge.h"
#include "GEdge.h"
#include "MElement.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "Message.h"
#include "ListUtils.h"
#include "Context.h"
#include "GModel.h"

#define SQU(a)      ((a)*(a))

extern Context_T CTX;

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

static void smoothInterpLc(int nbSmooth)
{
  for(int j = 0; j < nbSmooth; j++){
    for(int i = 0 ; i < (int)interpLc.size(); i++){               
      xi2lc &left = (i == 0) ? interpLc[0] : interpLc[i - 1];
      xi2lc &mid = interpLc[i];
      xi2lc &right = (i == (int)interpLc.size() - 1) ?
        interpLc[interpLc.size() - 1] : interpLc[i+1];
      if(1. / mid.lc > 1.1 * 1. / left.lc) mid.lc = left.lc / 1.1;
      if(1. / mid.lc > 1.1 * 1. / right.lc) mid.lc = right.lc / 1.1;
    }
  } 
}

static void printInterpLc(const char *name)
{
  FILE *f = fopen(name,"w");
  for(unsigned int i = 0; i < interpLc.size(); i++){              
    xi2lc &interp = interpLc[i];
    fprintf(f,"%12.5E %12.5E\n", interp.xi, 1 / interp.lc);
  }
  fclose(f);
}

static void buildInterpLc(List_T *lcPoints)
{
  IntPoint p;
  interpLc.clear();
  for(int i = 0; i < List_Nbr(lcPoints); i++){
    List_Read(lcPoints, i, &p);
    interpLc.push_back(xi2lc( p.t, p.lc));
  }
}

static double F_Lc_usingInterpLc(GEdge *ge, double t)
{
  std::vector<xi2lc>::iterator it = std::lower_bound(interpLc.begin(),
                                                     interpLc.end(), xi2lc(t, 0));
  double t1 = it->xi;
  double l1 = it->lc;
  it++;
  SVector3 der = ge->firstDer(t);
  const double d = norm(der);
  if(it == interpLc.end()) return d * l1;
  double t2 = it->xi;
  double l2 = it->lc;
  double l = l1 + ((t - t1) / (t2 - t1)) * (l2 - l1);
  return d * l;
}

static double F_Lc_usingInterpLcBis(GEdge *ge, double t)
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

  return 1 / lc_here;
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
  double val, r;

  SVector3 der = ge->firstDer(t) ;
  double d = norm(der);

  double coef = ge->meshAttributes.coeffTransfinite;
  int type = ge->meshAttributes.typeTransfinite;
  int nbpt = ge->meshAttributes.nbPointsTransfinite;

  if(coef <= 0.0 || coef == 1.0) {
    // coef < 0 should never happen
    val = d * coef / ge->length();
  }
  else {
    switch (abs(type)) {

    case 1: // Geometric progression ar^i; Sum of n terms = length = a (r^n-1)/(r-1)
      {
        if(sign(type) >= 0)
          r = coef;
        else
          r = 1. / coef;
        double a = ge->length() * (r - 1.) / (pow(r, nbpt - 1.) - 1.);
        int i = (int)(log(t * ge->length() / a * (r - 1.) + 1.) / log(r));
        val = d / (a * pow(r, (double)i));
      }
      break;
        
    case 2: // Bump
      {
        double a;
        if(coef > 1.0) {
          a = -4. * sqrt(coef - 1.) *
            atan2(1., sqrt(coef - 1.)) /
            ((double)nbpt *  ge->length());
        }
        else {
          a = 2. * sqrt(1. - coef) *
            log(fabs((1. + 1. / sqrt(1. - coef))
                     / (1. - 1. / sqrt(1. - coef))))
            / ((double)nbpt * ge->length());
        }
        double b = -a * ge->length() * ge->length() / (4. * (coef - 1.));
        val = d / (-a * SQU(t * ge->length() - (ge->length()) * 0.5) + b);
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

static void RecursiveIntegration(GEdge *ge, IntPoint * from, IntPoint * to,
				 double (*f) (GEdge *e, double X), List_T * pPoints,
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
    List_Read(pPoints, List_Nbr(pPoints) - 1, &p1);
    P.p = p1.p + val2;
    List_Add(pPoints, &P);

    List_Read(pPoints, List_Nbr(pPoints) - 1, &p1);
    to->p = p1.p + val3;
    List_Add(pPoints, to);
  }
  else {
    RecursiveIntegration(ge, from, &P, f, pPoints, Prec, depth);
    RecursiveIntegration(ge, &P, to, f, pPoints, Prec, depth);
  }

  (*depth)--;
}

static double Integration(GEdge *ge, double t1, double t2, 
			  double (*f) (GEdge *e, double X),
			  List_T * pPoints, double Prec)
{
  IntPoint from, to;

  int depth = 0;

  from.t = t1;
  from.lc = f(ge, from.t);
  from.p = 0.0;
  List_Add(pPoints, &from);

  to.t = t2;
  to.lc = f(ge, to.t);
  RecursiveIntegration(ge, &from, &to, f, pPoints, Prec, &depth);

  List_Read(pPoints, List_Nbr(pPoints) - 1, &to);
  return to.p;
}

void deMeshGEdge::operator() (GEdge *ge) 
{
  if(ge->geomType() == GEntity::DiscreteCurve) return;

  for (unsigned int i = 0; i < ge->mesh_vertices.size(); i++) 
    delete ge->mesh_vertices[i];
  ge->mesh_vertices.clear();
  for (unsigned int i = 0; i < ge->lines.size(); i++) 
    delete ge->lines[i];
  ge->lines.clear();
  ge->deleteVertexArrays();
  ge->model()->destroyMeshCaches();
}

void meshGEdge::operator() (GEdge *ge) 
{  
  ge->model()->setCurrentMeshEntity(ge);

  if(ge->geomType() == GEntity::DiscreteCurve) return;
  if(ge->geomType() == GEntity::BoundaryLayerCurve) return;
  if(ge->meshAttributes.Method == MESH_NONE) return;

  deMeshGEdge dem;
  dem(ge);

  if(MeshExtrudedCurve(ge)) return;

  Msg::Info("Meshing curve %d (%s)", ge->tag(), ge->getTypeString().c_str());

  // Create a list of integration points
  List_T *Points = List_Create(10, 10, sizeof(IntPoint));
  // Create a list of points for interpolating the LC Field
  List_T *lcPoints = List_Create(10, 10, sizeof(IntPoint));

  // compute bounds
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();
  
  // first compute the length of the curve by integrating one
  double length = Integration(ge, t_begin, t_end, F_One, Points, 1.e-8 * CTX.lc);
  ge->setLength(length);

  if(length == 0.0)
    Msg::Debug("Curve %d has a zero length", ge->tag());
  
  List_Reset(Points);

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
    if(CTX.mesh.lc_integration_precision > 1.e-8){
      Integration(ge, t_begin, t_end, F_Lc_usingInterpLcBis, lcPoints, 
                  CTX.mesh.lc_integration_precision);
      buildInterpLc(lcPoints);
      // printInterpLc("toto1.dat");
      // smoothInterpLc(20);
      // printInterpLc("toto2.dat");
      a = Integration(ge, t_begin, t_end, F_Lc_usingInterpLc, Points, 1.e-8);
    }
    else{
      a = Integration(ge, t_begin, t_end, F_Lc, Points, CTX.mesh.lc_integration_precision);
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
      List_Read(Points, count - 1, &P1);
      List_Read(Points, count, &P2);
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
  List_Delete(Points);
  List_Delete(lcPoints);

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
