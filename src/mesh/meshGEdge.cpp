// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GModel.h"
#include "discreteEdge.h"
#include "meshGEdge.h"
#include "GEdge.h"
#include "MLine.h"
#include "BackgroundMeshTools.h"
#include "boundaryLayersData.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Context.h"
#include "STensor3.h"
#include "Field.h"
#include "OS.h"

// for a beta law -- transform h_wall to beta
//

static double f_beta(double beta, double t, int n)
{
  double c = atanh(1 / beta);
  double f = n * (1 + atanh((t - 1) / beta) / c);
  return f;
}

double bissection_get_beta(double beta0, double hw, double length, int n)
{
  double t = hw / length;

  double beta1 = 1. + 1.e-8;
  double beta2 = 5;
  double f1 = f_beta(beta1, t, n);
  double f2 = f_beta(beta2, t, n);
  if(f1 > 1 && f2 < 1) {
    while(1) {
      double beta3 = (beta1 + beta2) * 0.5;
      double f3 = f_beta(beta3, t, n);
      //      printf("%12.5E %12.5E %12.5E\n",f1,f2,f3);
      if(fabs(f3 - 1) < 1.e-8) return beta3;
      if(f3 > 1)
        beta1 = beta3;
      else
        beta2 = beta3;
    }
  }
  return 100;
}

static double f_bump(double coef, double t, int n)
{
  double a;
  if(coef > 1.0) {
    a = std::atan2(1.0, std::sqrt(coef - 1.)) / std::sqrt(coef - 1.) / n;
    double A = (coef - 1);
    double f = (atan(sqrt(A)) - atan(sqrt(A) * (1 - 2 * t))) / 2 / sqrt(A) / a;
    return f;
  }
  else {
    a = std::atanh(std::sqrt(1. - coef)) / std::sqrt(1 - coef) / n;
    double A = (1 - coef);
    double f =
      (atanh(sqrt(A)) - atanh(sqrt(A) * (1 - 2 * t))) / 2 / sqrt(A) / a;
    return f;
  }
}

// hwall given for the bump
double bissection_get_a(double r0, double hw, double length, int n)
{
  double t = hw / length;

  double alpha1 = 1.e-8;
  double alpha2 = 100;
  double f1 = f_bump(alpha1, t, n);
  double f2 = f_bump(alpha2, t, n);
  if(f1 > 1 && f2 < 1) {
    while(1) {
      double alpha3 = (alpha1 + alpha2) * 0.5;
      double f3 = f_bump(alpha3, t, n);
      //      printf("%12.5E %12.5E %12.5E\n",f1,f2,f3);
      if(fabs(f3 - 1) < 1.e-8) return alpha3;
      if(f3 > 1)
        alpha1 = alpha3;
      else
        alpha2 = alpha3;
    }
  }
  return 1;
}

double f_prog(double r, double hw, double length, int n)
{
  if(r == 1) return (n * hw / length);
  double f = hw * (pow(r, n) - 1) / (r - 1) / length;
  return f;
}

// hwall given for the progression
double newton_get_r /*bissection_get_r*/ (double r0, double hw, double length,
                                          int n)
{
  n = n - 1;

  double r1 = 1;
  double r2 = 4;
  double f1 = f_prog(r1, hw, length, n);
  double f2 = f_prog(r2, hw, length, n);
  //  printf("%g %g\n",f1,f2);
  if(f1 < 1 && f2 > 1) {
    while(1) {
      double r3 = (r1 + r2) * 0.5;
      double f3 = f_prog(r3, hw, length, n);
      //      printf("%22.15E %12.5E %12.5E\n",r1,r2,r3);
      if(fabs(f3 - 1) < 1.e-12) return r3;
      if(f3 < 1)
        r1 = r3;
      else
        r2 = r3;
    }
  }
  return 1;
}

// for a progression -- transform h_wall to ratio
double newton_get_2r(double r0, double hw, double length, int n)
{
  n = n - 1;
  double r = r0;
  int it = 0;
  while(1) {
    double slope =
      ((n - 1) * pow(r, n + 1) - n * pow(r, n) + r) / ((r - 1) * (r - 1) * r);
    double f = (pow(r, n) - 1) / (r - 1) - length / hw;
    //    printf("%g %g\n",f,r);
    double dr = -f / slope;
    r = r + dr;
    if(fabs(f) < 1.e-12) { return r; }
    if(it++ > 100) {
      //      printf("convergence impossible %g\n",f);
      break;
    }
  }
  return r;
}

typedef struct {
  int Num;
  // t is the local coordinate of the point
  // lc is x'(t)/h(x(t))
  // p is the value of the primitive
  // xp is the norm of the tangent vector
  double t, lc, p, xp;
} IntPoint;

static double smoothPrimitive(GEdge *ge, double alpha,
                              std::vector<IntPoint> &Points)
{
  int ITER = 0;
  while(1) {
    int count1 = 0;
    int count2 = 0;

    // use a gauss-seidel iteration; iterate forward and then backward;
    // convergence is usually very fast
    for(std::size_t i = 1; i < Points.size(); i++) {
      double dh =
        (Points[i].xp / Points[i].lc - Points[i - 1].xp / Points[i - 1].lc);
      double dt = Points[i].t - Points[i - 1].t;
      double dhdt = dh / dt;
      if(dhdt / Points[i].xp > (alpha - 1.) * 1.01) {
        double hnew =
          Points[i - 1].xp / Points[i - 1].lc + dt * (alpha - 1) * Points[i].xp;
        Points[i].lc = Points[i].xp / hnew;
        count1++;
      }
    }

    for(int i = Points.size() - 1; i > 0; i--) {
      double dh =
        (Points[i - 1].xp / Points[i - 1].lc - Points[i].xp / Points[i].lc);
      double dt = std::abs(Points[i - 1].t - Points[i].t);
      double dhdt = dh / dt;
      if(dhdt / Points[i - 1].xp > (alpha - 1.) * 1.01) {
        double hnew =
          Points[i].xp / Points[i].lc + dt * (alpha - 1) * Points[i].xp;
        Points[i - 1].lc = Points[i - 1].xp / hnew;
        count2++;
      }
    }

    ++ITER;
    if(ITER > 2000) break;
    if(!(count1 + count2)) break;
  }

  // recompute the primitive
  for(std::size_t i = 1; i < Points.size(); i++) {
    IntPoint &pt2 = Points[i];
    IntPoint &pt1 = Points[i - 1];
    pt2.p = pt1.p + (pt2.t - pt1.t) * 0.5 * (pt2.lc + pt1.lc);
  }
  return Points[Points.size() - 1].p;
}

struct F_LcB {
  double operator()(GEdge *ge, double t)
  {
    GPoint p = ge->point(t);
    return BGM_MeshSize(ge, t, 0, p.x(), p.y(), p.z());
  }
};

struct F_Lc {
  double operator()(GEdge *ge, double t)
  {
    GPoint p = ge->point(t);
    Range<double> bounds = ge->parBounds(0);
    double t_begin = bounds.low();
    double t_end = bounds.high();
    double lc_here = 1.e22;
    if(t == t_begin && ge->getBeginVertex())
      lc_here = BGM_MeshSize(ge->getBeginVertex(), t, 0, p.x(), p.y(), p.z());
    else if(t == t_end && ge->getEndVertex())
      lc_here = BGM_MeshSize(ge->getEndVertex(), t, 0, p.x(), p.y(), p.z());

    lc_here = std::min(lc_here, BGM_MeshSize(ge, t, 0, p.x(), p.y(), p.z()));
    //    printf("LC HERE %g %g\n",t,lc_here);
    SVector3 der = ge->firstDer(t);
    return norm(der) / lc_here;
  }
};

struct F_Lc_aniso {
  double operator()(GEdge *ge, double t)
  {
    GPoint p = ge->point(t);
    SMetric3 lc_here;

    Range<double> bounds = ge->parBounds(0);
    double t_begin = bounds.low();
    double t_end = bounds.high();

    if(t == t_begin && ge->getBeginVertex())
      lc_here = BGM_MeshMetric(ge->getBeginVertex(), t, 0, p.x(), p.y(), p.z());
    else if(t == t_end && ge->getEndVertex())
      lc_here = BGM_MeshMetric(ge->getEndVertex(), t, 0, p.x(), p.y(), p.z());
    else
      lc_here = BGM_MeshMetric(ge, t, 0, p.x(), p.y(), p.z());

    FieldManager *fields = ge->model()->getFields();
    for(int i = 0; i < fields->getNumBoundaryLayerFields(); ++i) {
      Field *bl_field = fields->get(fields->getBoundaryLayerField(i));
      if(!bl_field) continue;
      BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField *>(bl_field);
      if(!blf) continue;
      if(blf->isEdgeBL(ge->tag())) break;
      SMetric3 lc_bgm;
      blf->computeFor1dMesh(p.x(), p.y(), p.z(), lc_bgm);
      lc_here = intersection_conserveM1(lc_here, lc_bgm);
    }

    SVector3 der = ge->firstDer(t);
    return std::sqrt(dot(der, lc_here, der));
  }
};

// static double dfbeta2 (double t, double beta){
//  double ratio = (1+beta)/(beta-1);
//  double zlog  = log(ratio);
//  return 1.-acosh(beta*zlog/t - 1.0)/zlog;
//  return beta*zlog / (1+cosh(zlog*(1-t)));
//}

static double dfbeta(double t, double beta)
{
  double ratio = (1 + beta) / (beta - 1);
  double zlog = log(ratio);
  return 2 * beta / ((1 + beta - t) * (-1 + beta + t) * zlog);
}

struct F_Transfinite {
  double operator()(GEdge *ge, double t_)
  {
    double length = ge->length();
    if(length == 0.0) {
      Msg::Error("Zero-length curve %d in transfinite mesh", ge->tag());
      return 1.;
    }

    SVector3 der = ge->firstDer(t_);
    double d = norm(der);
    double coef = ge->meshAttributes.coeffTransfinite;
    int type = ge->meshAttributes.typeTransfinite;
    int nbpt = ge->meshAttributes.nbPointsTransfinite;

    //    printf("type = %d coef %g\n",type, coef);

    // transform type = 5 onto type = 1
    if(type == 5) {
      // for a progression -- transform h_wall to ratio
      bool sgn = coef > 0;
      coef = newton_get_r(1.1, fabs(coef), length, nbpt);
      if(!sgn) coef = 1. / coef;
      type = 1;
      ge->meshAttributes.typeTransfinite = 1;
      ge->meshAttributes.coeffTransfinite = coef;
    }
    if(type == 6) {
      // for a bump -- transform h_wall to a
      coef = bissection_get_a(0.1, fabs(coef), length, nbpt);
      type = 2;
    }
    // transform type = 7 onto type = 3
    if(type == 7) {
      // for a progression -- transform h_wall to ratio
      bool sgn = coef > 0;
      coef = bissection_get_beta(2, fabs(coef), length, nbpt);
      type = 3 * (sgn ? 1 : -1);
    }

    int atype = std::abs(type);

    if(CTX::instance()->mesh.flexibleTransfinite &&
       CTX::instance()->mesh.lcFactor)
      nbpt /= CTX::instance()->mesh.lcFactor;

    Range<double> bounds = ge->parBounds(0);
    double t_begin = bounds.low();
    double t_end = bounds.high();
    double t = (t_ - t_begin) / (t_end - t_begin);

    double val;

    if(coef <= 0.0 || coef == 1.0 || (atype == 3 && coef < 1.)) {
      // coef < 0 should never happen
      val = d * coef / ge->length();
    }
    else {
      switch(atype) {
      case 1: {
        // geometric progression ar^i; Sum of n terms = length = a (r^n-1)/(r-1)
        double r = (gmsh_sign(type) >= 0) ? coef : 1. / coef;
        double a = length * (r - 1.) / (std::pow(r, nbpt - 1.) - 1.);
        int i = (int)(std::log(t * length / a * (r - 1.) + 1.) / std::log(r));
        val = d / (a * std::pow(r, (double)i));
      } break;

      case 2: {
        // "bump"
        double a;
        if(coef > 1.0) {
          a = -4. * std::sqrt(coef - 1.) *
              std::atan2(1.0, std::sqrt(coef - 1.)) / ((double)nbpt * length);
        }
        else {
          a = 2. * std::sqrt(1. - coef) *
              std::log(std::abs((1. + 1. / std::sqrt(1. - coef)) /
                                (1. - 1. / std::sqrt(1. - coef)))) /
              ((double)nbpt * length);
        }
        double b = -a * length * length / (4. * (coef - 1.));
        val = d / (-a * std::pow(t * length - (length) * 0.5, 2) + b);
        break;
      }
      case 3: {
        // "beta" law
        if(type < 0)
          val = dfbeta(1. - t, coef);
        else
          val = dfbeta(t, coef);
        break;
      }
      case 4: {
        // standard boundary layer progression: TODO
        val = d / (length * t);
        break;
      }
      default:
        Msg::Warning("Unknown case in Transfinite curve mesh");
        val = 1.;
        break;
      }
    }
    return val;
  }
};

struct F_One {
  double operator()(GEdge *ge, double t)
  {
    SVector3 der = ge->firstDer(t);
    return norm(der);
  }
};

static double trapezoidal(IntPoint *const P1, IntPoint *const P2)
{
  return 0.5 * (P1->lc + P2->lc) * (P2->t - P1->t);
}

template <typename function>
static void RecursiveIntegration(GEdge *ge, IntPoint *from, IntPoint *to,
                                 function f, std::vector<IntPoint> &Points,
                                 double Prec, int *depth)
{
  IntPoint P, p1;

  (*depth)++;

  P.t = 0.5 * (from->t + to->t);
  P.lc = f(ge, P.t);

  double const val1 = trapezoidal(from, to);
  double const val2 = trapezoidal(from, &P);
  double const val3 = trapezoidal(&P, to);
  double const err = std::abs(val1 - val2 - val3);

  if(((err < Prec) && (*depth > 6)) || (*depth > 25)) {
    p1 = Points.back();
    P.p = p1.p + val2;
    Points.push_back(P);

    p1 = Points.back();
    to->p = p1.p + val3;
    Points.push_back(*to);
  }
  else {
    RecursiveIntegration(ge, from, &P, f, Points, Prec, depth);
    RecursiveIntegration(ge, &P, to, f, Points, Prec, depth);
  }

  (*depth)--;
}

template <typename function>
static double Integration(GEdge *ge, double t1, double t2, function f,
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

static SPoint3 transform(MVertex *vsource, const std::vector<double> &tfo)
{
  double ps[4] = {vsource->x(), vsource->y(), vsource->z(), 1.};
  double res[4] = {0., 0., 0., 0.};
  int idx = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) res[i] += tfo[idx++] * ps[j];

  return SPoint3(res[0], res[1], res[2]);
}

static void copyMesh(GEdge *from, GEdge *to, int direction)
{
  if(!from->getBeginVertex() || !from->getEndVertex() ||
     !to->getBeginVertex() || !to->getEndVertex()) {
    Msg::Error("Cannot copy mesh on curves without begin/end points");
    return;
  }

  Range<double> u_bounds = from->parBounds(0);
  double u_min = u_bounds.low();
  double u_max = u_bounds.high();

  Range<double> to_u_bounds = to->parBounds(0);
  double to_u_min = to_u_bounds.low();

  // include begin and end point to avoid conflicts when realigning
  MVertex *vt0 = to->getBeginVertex()->mesh_vertices[0];
  MVertex *vt1 = to->getEndVertex()->mesh_vertices[0];
  MVertex *vs0 = from->getBeginVertex()->mesh_vertices[0];
  MVertex *vs1 = from->getEndVertex()->mesh_vertices[0];

  to->correspondingVertices[vt0] = direction > 0 ? vs0 : vs1;
  to->correspondingVertices[vt1] = direction > 0 ? vs1 : vs0;

  for(std::size_t i = 0; i < from->mesh_vertices.size(); i++) {
    int index = (direction < 0) ? (from->mesh_vertices.size() - 1 - i) : i;
    MVertex *v = from->mesh_vertices[index];
    GPoint gp;
    double newu;
    if(to->affineTransform.size() < 16) {
      // assume identical parametrisations (dangerous...)
      double u;
      v->getParameter(0, u);
      newu = (direction > 0) ? (u - u_min + to_u_min) : (u_max - u + to_u_min);
      gp = to->point(newu);
    }
    else {
      SPoint3 p = transform(v, to->affineTransform);
      // for non-exact periodic curves we could use closestPoint; just use
      // Mesh.HighOrderPeriodic=2, which will do that
      newu = to->parFromPoint(p);
      gp = to->point(newu);
      // gp = to->closestPoint(p, newu);
    }
    MEdgeVertex *vv = new MEdgeVertex(gp.x(), gp.y(), gp.z(), to, newu);
    to->mesh_vertices.push_back(vv);
    to->correspondingVertices[vv] = v;
  }
  for(std::size_t i = 0; i < to->mesh_vertices.size() + 1; i++) {
    MVertex *v0 = (i == 0) ? to->getBeginVertex()->mesh_vertices[0] :
                             to->mesh_vertices[i - 1];
    MVertex *v1 = (i == to->mesh_vertices.size()) ?
                    to->getEndVertex()->mesh_vertices[0] :
                    to->mesh_vertices[i];
    to->lines.push_back(new MLine(v0, v1));
  }
}

static void fillCorrespondingNodes(GEdge *from, GEdge *to, int direction)
{
  if(!from->getBeginVertex() || !from->getEndVertex() ||
     !to->getBeginVertex() || !to->getEndVertex()) {
    Msg::Error(
      "Cannot fill corresponding nodes on curves without begin/end points");
    return;
  }

  // include begin and end point to avoid conflicts when realigning
  MVertex *vt0 = to->getBeginVertex()->mesh_vertices[0];
  MVertex *vt1 = to->getEndVertex()->mesh_vertices[0];
  MVertex *vs0 = from->getBeginVertex()->mesh_vertices[0];
  MVertex *vs1 = from->getEndVertex()->mesh_vertices[0];

  to->correspondingVertices[vt0] = direction > 0 ? vs0 : vs1;
  to->correspondingVertices[vt1] = direction > 0 ? vs1 : vs0;

  if(to->mesh_vertices.size() != from->mesh_vertices.size()) {
    Msg::Error("Incompatible meshes to fill node correspondance");
    return;
  }

  for(std::size_t i = 0; i < from->mesh_vertices.size(); i++) {
    int index = (direction < 0) ? (from->mesh_vertices.size() - 1 - i) : i;
    MVertex *v = from->mesh_vertices[index];
    // FIXME: verify that the nodes follow the transformation!
    to->correspondingVertices[to->mesh_vertices[i]] = v;
  }
}

void deMeshGEdge::operator()(GEdge *ge)
{
  if(ge->isFullyDiscrete()) return;
  ge->deleteMesh();
  ge->meshStatistics.status = GEdge::PENDING;
}

/*
static void printFandPrimitive(int tag, std::vector<IntPoint> &Points)
{
  char name[256];
  sprintf(name, "line%d.dat", tag);
  FILE *f = Fopen(name, "w");
  if(!f) return;
  double l = 0;
  for (std::size_t i = 0; i < Points.size(); i++){
    const IntPoint &P = Points[i];
    if(i) l += (P.t - Points[i-1].t) * P.xp;
    fprintf(f, "%g %g %g %g %g\n", P.t, P.xp/P.lc, P.p, P.lc, l);
  }
  fclose(f);
}
*/

// new algo for recombining + splitting
static int increaseN(int N)
{
  //  if(((N + 1) / 2 - 1) % 2 != 0) return N + 2;
  return N;
}

// ensure not to have points that are too close to each other.
// can be caused by a coarse 1D mesh or by a noisy curve
static void filterPoints(GEdge *ge, int nMinimumPoints)
{
  if(ge->mesh_vertices.empty()) return;
  if(ge->meshAttributes.method == MESH_TRANSFINITE) return;

  bool forceOdd = false;
  if((ge->meshAttributes.method != MESH_TRANSFINITE ||
      CTX::instance()->mesh.flexibleTransfinite) &&
     CTX::instance()->mesh.algoRecombine != 0) {
    if(CTX::instance()->mesh.recombineAll) { forceOdd = true; }
  }

  if(!ge->getBeginVertex() || !ge->getEndVertex()) return;

  MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
  std::vector<std::pair<double, MVertex *>> lengths;
  for(std::size_t i = 0; i < ge->mesh_vertices.size(); i++) {
    MEdgeVertex *v = dynamic_cast<MEdgeVertex *>(ge->mesh_vertices[i]);
    if(!v) {
      Msg::Error("Node not classified on curve in 1D mesh filtering");
      return;
    }
    double d = distance(v, v0);
    double t;
    v->getParameter(0, t);
    if(i != 0) {
      double t0;
      if(v0->onWhat()->dim() == 0) {
        // Vertex is begin point
        t0 = ge->parFromPoint(SPoint3(v0->x(), v0->y(), v0->z()));
      }
      else
        v0->getParameter(0, t0);

      t = 0.5 * (t + t0);
    }
    double lc = F_LcB()(ge, t);
    // double lc = v->getLc();
    if(d < lc * .3) { lengths.push_back(std::make_pair(lc / d, v)); }
    else
      v0 = v;
  }
  std::sort(lengths.begin(), lengths.end());
  int last = lengths.size();
  if(forceOdd) {
    while(last % 2 != 0) last--;
  }
  /*
    if(CTX::instance()->mesh.algoRecombine == 2){
      if(last < 4) last = 0;
        while (last %4 != 0)last--;
      }
      else{
        while (last %2 != 0)last--;
      }
    }
  */

  bool filteringObservesMinimumN =
    (((int)ge->mesh_vertices.size() - last) >= nMinimumPoints);
  if(filteringObservesMinimumN) {
    for(int i = 0; i < last; i++) {
      auto it = std::find(ge->mesh_vertices.begin(), ge->mesh_vertices.end(),
                          lengths[i].second);

      if(it != ge->mesh_vertices.end()) { ge->mesh_vertices.erase(it); }
      delete lengths[i].second;
    }
  }
}

static void createPoints(GVertex *gv, GEdge *ge, BoundaryLayerField *blf,
                         std::vector<MVertex *> &v, const SVector3 &dir)
{
  if(!ge->getBeginVertex() || !ge->getEndVertex()) return;

  const double hWall = blf->hWall(gv->tag());
  double L = hWall;
  double LEdge = distance(ge->getBeginVertex()->mesh_vertices[0],
                          ge->getEndVertex()->mesh_vertices[0]);

  if(blf->betaLaw) {
    std::vector<double> t(blf->nb_divisions);
    double zlog = log((1 + blf->beta) / (blf->beta - 1));
    for(int i = 0; i < blf->nb_divisions; i++) {
      const double eta = (double)(i + 1) / blf->nb_divisions;
      const double power = exp(zlog * (1. - eta));
      const double ratio = (1. - power) / (1. + power);
      t[i] = 1.0 + blf->beta * ratio;
    }
    for(int i = 0; i < blf->nb_divisions; i++) {
      double L = hWall * t[i] / t[0];
      SPoint3 p(gv->x() + dir.x() * L, gv->y() + dir.y() * L, 0.0);
      v.push_back(new MEdgeVertex(p.x(), p.y(), p.z(), ge, ge->parFromPoint(p),
                                  0, blf->hFar));
    }
  }
  else {
    while(1) {
      if(L > blf->thickness || L > LEdge * .4) { break; }

      SPoint3 p(gv->x() + dir.x() * L, gv->y() + dir.y() * L, 0.0);
      v.push_back(new MEdgeVertex(p.x(), p.y(), p.z(), ge, ge->parFromPoint(p),
                                  0, blf->hFar));
      int ith = v.size();
      L += hWall * std::pow(blf->ratio, ith);
    }
  }
}

static void addBoundaryLayerPoints(GEdge *ge, double &t_begin, double &t_end,
                                   std::vector<MVertex *> &_addBegin,
                                   std::vector<MVertex *> &_addEnd)
{
  _addBegin.clear();
  _addEnd.clear();

  // t_begin/t_end may change the left/right parameter of the interval
  // _addBegin/_addEnd : additional points @ left/right
  FieldManager *fields = ge->model()->getFields();
  int n = fields->getNumBoundaryLayerFields();

  if(n == 0) return;

  if(!ge->getBeginVertex() || !ge->getEndVertex()) return;

  // Check if edge is a BL edge
  for(int i = 0; i < n; ++i) {
    Field *bl_field = fields->get(fields->getBoundaryLayerField(i));
    if(!bl_field) continue;
    BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField *>(bl_field);
    if(!blf) continue;
    if(blf->isEdgeBL(ge->tag())) return;
  }

  SVector3 dir(ge->getEndVertex()->x() - ge->getBeginVertex()->x(),
               ge->getEndVertex()->y() - ge->getBeginVertex()->y(),
               ge->getEndVertex()->z() - ge->getBeginVertex()->z());
  dir.normalize();
  GVertex *gvb = ge->getBeginVertex();
  GVertex *gve = ge->getEndVertex();

  // Check if extremity nodes are BL node
  for(int i = 0; i < n; ++i) {
    Field *bl_field = fields->get(fields->getBoundaryLayerField(i));
    if(!bl_field) continue;
    BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField *>(bl_field);
    if(!blf) continue;
    blf->setupFor1d(ge->tag());

    if(blf->isEndNode(gvb->tag())) {
      if(ge->geomType() != GEntity::Line) {
        Msg::Error("Boundary layer end point %d should lie on a straight line",
                   gvb->tag());
        return;
      }
      if(_addBegin.size()) {
        Msg::Error("Different boundary layers cannot touch each other");
        return;
      }
      createPoints(gvb, ge, blf, _addBegin, dir);
      if(!_addBegin.empty())
        _addBegin[_addBegin.size() - 1]->getParameter(0, t_begin);
    }
    if(blf->isEndNode(gve->tag())) {
      if(ge->geomType() != GEntity::Line) {
        Msg::Error("Boundary layer end point %d should lie on a straight line",
                   gve->tag());
        return;
      }
      if(_addEnd.size()) {
        Msg::Error("Different boundary layers cannot touch each other");
        return;
      }
      createPoints(gve, ge, blf, _addEnd, dir * -1.0);
      if(!_addEnd.empty()) _addEnd[_addEnd.size() - 1]->getParameter(0, t_end);
    }
  }
}

int meshGEdgeProcessing(GEdge *ge, const double t_begin, double t_end, int &N,
                        std::vector<IntPoint> &Points, double &a,
                        int &filterMinimumN)
{
  if(ge->geomType() == GEntity::BoundaryLayerCurve) return 0;
  if(ge->meshAttributes.method == MESH_NONE) return 0;
  if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) return 0;
  if(CTX::instance()->mesh.meshOnlyEmpty && ge->getNumMeshElements()) return 0;

  // first compute the length of the curve by integrating one
  double length;
  Points.clear();
  if(ge->geomType() == GEntity::Line && ge->getBeginVertex() &&
     ge->getBeginVertex() == ge->getEndVertex() &&
     // do not consider closed lines as degenerated
     (ge->position(0.5) - ge->getBeginVertex()->xyz()).norm() <
       CTX::instance()->geom.tolerance)
    length = 0.0; // special case to avoid infinite loop in integration
  else
    length = Integration(ge, t_begin, t_end, F_One(), Points,
                         CTX::instance()->mesh.lcIntegrationPrecision *
                           CTX::instance()->lc);
  ge->setLength(length);
  Points.clear();
  //  printf("length %12.5E\n",length);

  if(length < CTX::instance()->mesh.toleranceEdgeLength) {
    ge->setTooSmall(true);
  }

  // Integrate detJ/lc du
  filterMinimumN = 1;
  if(length == 0. && CTX::instance()->mesh.toleranceEdgeLength == 0.) {
    Msg::Debug("Curve %d has a zero length", ge->tag());
    a = 0.;
    N = 1;
  }
  else if(ge->degenerate(0)) {
    Msg::Debug("Curve %d is degenerated", ge->tag());
    a = 0.;
    N = 1;
  }
  else if(ge->meshAttributes.method == MESH_TRANSFINITE &&
          ge->meshAttributes.typeTransfinite == 4) {
    // Transfinite (prescribed number of edges) but the points are positioned
    // according to the standard size constraints (size map, etc)
    a = Integration(ge, t_begin, t_end, F_Lc(), Points,
                    CTX::instance()->mesh.lcIntegrationPrecision);
    N = ge->meshAttributes.nbPointsTransfinite;
  }
  else if(ge->meshAttributes.method == MESH_TRANSFINITE) {
    a = Integration(ge, t_begin, t_end, F_Transfinite(), Points,
                    CTX::instance()->mesh.lcIntegrationPrecision);
    N = ge->meshAttributes.nbPointsTransfinite;
    if(CTX::instance()->mesh.flexibleTransfinite &&
       CTX::instance()->mesh.lcFactor)
      N /= CTX::instance()->mesh.lcFactor;
  }
  else {
    if(CTX::instance()->mesh.algo2d == ALGO_2D_BAMG /* || blf*/) {
      a = Integration(ge, t_begin, t_end, F_Lc_aniso(), Points,
                      CTX::instance()->mesh.lcIntegrationPrecision);
    }
    else {
      a = Integration(ge, t_begin, t_end, F_Lc(), Points,
                      CTX::instance()->mesh.lcIntegrationPrecision);
    }

    // we should maybe provide an option to disable the smoothing
    for(std::size_t i = 0; i < Points.size(); i++) {
      IntPoint &pt = Points[i];
      SVector3 der = ge->firstDer(pt.t);
      pt.xp = der.norm();
    }
    if(CTX::instance()->mesh.algo2d != ALGO_2D_BAMG)
      a = smoothPrimitive(ge, std::sqrt(CTX::instance()->mesh.smoothRatio),
                          Points);
    filterMinimumN = ge->minimumMeshSegments() + 1;
    N = std::max(filterMinimumN, (int)(a + 1.99));
  }

  // force odd number of points if blossom is used for recombination
  if((ge->meshAttributes.method != MESH_TRANSFINITE ||
      CTX::instance()->mesh.flexibleTransfinite) &&
     CTX::instance()->mesh.algoRecombine != 0) {
    std::vector<GFace *> const &faces = ge->faces();
    if(CTX::instance()->mesh.recombineAll) {
      //      if(N == 2) N = 1;
      if(N % 2 == 0) N++;
      if(CTX::instance()->mesh.algoRecombine == 2 ||
         CTX::instance()->mesh.algoRecombine == 4)
        N = increaseN(N);
    }
    else {
      for(auto it = faces.begin(); it != faces.end(); it++) {
        if((*it)->meshAttributes.recombine) {
          if(N % 2 == 0) N++;
          if(CTX::instance()->mesh.algoRecombine == 2 ||
             CTX::instance()->mesh.algoRecombine == 4)
            N = increaseN(N);
          break;
        }
      }
    }
  }

  return N;
}

void meshGEdge::operator()(GEdge *ge)
{
  // debug stuff
  if(CTX::instance()->debugSurface > 0) {
    std::vector<GFace *> f = ge->faces();
    bool found = false;
    for(size_t i = 0; i < f.size(); i++) {
      if(f[i]->tag() == CTX::instance()->debugSurface) { found = true; }
    }
    if(!found) return;
  }

  ge->model()->setCurrentMeshEntity(ge);

  if(ge->degenerate(1)) {
    ge->meshStatistics.status = GEdge::DONE;
    return;
  }

  if(ge->geomType() == GEntity::BoundaryLayerCurve) return;
  if(ge->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) return;
  if(CTX::instance()->mesh.meshOnlyEmpty && ge->getNumMeshElements()) return;

  // destroy the mesh if it exists
  deMeshGEdge dem;
  dem(ge);

  if(MeshExtrudedCurve(ge)) {
    // if there is a periodic constraint, fill the corresponding node arrays
    if(ge->getMeshMaster() != ge) {
      GEdge *gef = dynamic_cast<GEdge *>(ge->getMeshMaster());
      fillCorrespondingNodes(gef, ge, ge->masterOrientation);
    }
    return;
  }

  if(ge->getMeshMaster() != ge) {
    GEdge *gef = dynamic_cast<GEdge *>(ge->getMeshMaster());
    if(gef->meshStatistics.status == GEdge::PENDING) return;
    Msg::Info("Meshing curve %d (%s) as a copy of curve %d", ge->tag(),
              ge->getTypeString().c_str(), ge->getMeshMaster()->tag());
    copyMesh(gef, ge, ge->masterOrientation);
    ge->meshStatistics.status = GEdge::DONE;
    return;
  }

  Msg::Info("Meshing curve %d (%s)", ge->tag(), ge->getTypeString().c_str());

  // compute bounds
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  // if a BL is ending at one of the ends, then create specific points
  std::vector<MVertex *> _addBegin, _addEnd;
  addBoundaryLayerPoints(ge, t_begin, t_end, _addBegin, _addEnd);

  // integration to get length, number of points, etc
  int N;
  std::vector<IntPoint> Points;
  double a;
  int filterMinimumN;
  meshGEdgeProcessing(ge, t_begin, t_end, N, Points, a, filterMinimumN);

  //  printFandPrimitive(ge->tag(),Points);

  // if the curve is periodic and if the begin vertex is identical to
  // the end vertex and if this vertex has only one model curve
  // adjacent to it, then the vertex is not connecting any other
  // curve. So, the mesh vertex and its associated geom vertex are not
  // necessary at the same location

  // look if we are doing the STL triangulation
  std::vector<MVertex *> &mesh_vertices = ge->mesh_vertices;

  GPoint beg_p, end_p;
  if(!ge->getBeginVertex() || !ge->getEndVertex()) {
    Msg::Warning("Skipping curve with no begin or end point");
    return;
  }
  else if(ge->getBeginVertex() == ge->getEndVertex() &&
          ge->getBeginVertex()->edges().size() == 1) {
    end_p = beg_p = ge->point(t_begin);
    Msg::Debug("Meshing periodic closed curve (tag %i, %i points)", ge->tag(),
               N);
  }
  else {
    MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
    MVertex *v1 = ge->getEndVertex()->mesh_vertices[0];
    beg_p = GPoint(v0->x(), v0->y(), v0->z());
    end_p = GPoint(v1->x(), v1->y(), v1->z());
  }

  // do not consider the first and the last vertex (those are not
  // classified on this mesh edge)
  if(N > 1) {
    const double b = a / static_cast<double>(N - 1);
    int count = 1, NUMP = 1;
    IntPoint P1, P2;
    mesh_vertices.resize(N - 2);

    while(NUMP < N - 1) {
      P1 = Points[count - 1];
      P2 = Points[count];
      const double d = (double)NUMP * b;
      if((std::abs(P2.p) >= std::abs(d)) && (std::abs(P1.p) < std::abs(d))) {
        double const dt = P2.t - P1.t;
        double const dlc = P2.lc - P1.lc;
        double const dp = P2.p - P1.p;
        double const t = P1.t + dt / dp * (d - P1.p);
        SVector3 der = ge->firstDer(t);
        const double d = norm(der);
        double lc = d / (P1.lc + dlc / dp * (d - P1.p));
        GPoint V = ge->point(t);
        mesh_vertices[NUMP - 1] =
          new MEdgeVertex(V.x(), V.y(), V.z(), ge, t, 0, lc);
        NUMP++;
      }
      else {
        count++;
      }
    }
    mesh_vertices.resize(NUMP - 1);
  }

  // Boundary Layer points are added
  {
    std::vector<MVertex *> vv;
    vv.insert(vv.end(), _addBegin.begin(), _addBegin.end());
    vv.insert(vv.end(), mesh_vertices.begin(), mesh_vertices.end());
    for(std::size_t i = 0; i < _addEnd.size(); i++)
      vv.push_back(_addEnd[_addEnd.size() - 1 - i]);
    mesh_vertices = vv;
  }

  if(CTX::instance()->mesh.algo2d != ALGO_2D_BAMG &&
     CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT &&
     CTX::instance()->mesh.algo2d != ALGO_2D_PACK_PRLGRMS)
    if(_addBegin.empty() && _addEnd.empty())
      filterPoints(ge, filterMinimumN - 2);

  std::vector<MLine *> &lines = ge->lines;

  for(std::size_t i = 0; i <= mesh_vertices.size(); i++) {
    MVertex *v0 =
      (i == 0) ? ge->getBeginVertex()->mesh_vertices[0] : mesh_vertices[i - 1];

    MVertex *v1 = (i == mesh_vertices.size()) ?
                    ge->getEndVertex()->mesh_vertices[0] :
                    mesh_vertices[i];
    lines.push_back(new MLine(v0, v1));
  }

  if(ge->getBeginVertex() == ge->getEndVertex() &&
     ge->getBeginVertex()->edges().size() == 1) {
    MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
    v0->x() = beg_p.x();
    v0->y() = beg_p.y();
    v0->z() = beg_p.z();
  }

  Msg::Debug("Meshing curve %d (%s): %li interior vertices", ge->tag(),
             ge->getTypeString().c_str(), ge->mesh_vertices.size());

  ge->meshStatistics.status = GEdge::DONE;
}

void orientMeshGEdge::operator()(GEdge *ge)
{
  // apply user-specified mesh orientation constraints
  if(ge->meshAttributes.reverseMesh)
    for(std::size_t k = 0; k < ge->getNumMeshElements(); k++)
      ge->getMeshElement(k)->reverse();
}

int meshGEdgeTargetNumberOfPoints(GEdge *ge)
{
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  int N = 0;
  std::vector<IntPoint> Points;
  double a = 0.;
  int filterMinimumN = 1;
  meshGEdgeProcessing(ge, t_begin, t_end, N, Points, a, filterMinimumN);
  return N;
}

static void assign(GEdge *ge, double t, MVertex *v)
{
  GPoint gp = ge->point(t);
  double p;
  v->getParameter(0, p);
  //  printf("FOUND --> vertex %d  = %g -> %g\n",v->getNum(),p,t);
  v->x() = gp.x();
  v->y() = gp.y();
  v->z() = gp.z();
  v->setParameter(0, gp.u());
}

int meshGEdgeInsertBoundaryLayer(GEdge *ge, double width)
{
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  double t_left = t_begin;
  double t_right = t_end;
  double dt = (t_end - t_begin) / 100;

  if(ge->lines.size() < 2) return 0;

  MLine *l0 = ge->lines.front();
  MLine *ln = ge->lines.back();

  double eps = width * 1.e-8;
  int diff = 0;

  size_t start = 0;
  size_t end = ge->mesh_vertices.size() - 1;

  if(l0->getLength() < 1.e-12) {
    //    printf("GEdge %d -- end line lengths %12.5E %12.5E
    //    \n",ge->tag(),l0->getLength(),ln->getLength());
    for(auto v : ge->mesh_vertices) {
      double p;
      v->getParameter(0, p);
      printf(" %12.5E ", p);
    }
    printf("\n");

    diff++;
    GPoint g_left = ge->point(t_left);
    SPoint3 p0(g_left.x(), g_left.y(), g_left.z());
    ;
    while(1) {
      t_left += dt;
      g_left = ge->point(t_left);
      SPoint3 p1(g_left.x(), g_left.y(), g_left.z());
      if(p1.distance(p0) > width) break;
    }

    double t0 = t_left - dt;
    double t1 = t_left;

    //    printf("--> first guess %12.5E %12.5E %12.5E\n",t_left,t0,t1);

    while(1) {
      double t_mid = (t0 + t1) * .5;
      g_left = ge->point(t_mid);
      SPoint3 p1(g_left.x(), g_left.y(), g_left.z());
      double d = p1.distance(p0);
      //      printf("%12.5E %12.5E %12.5E %12.5E %12.5E
      //      \n",t0,t1,t_mid,d,width);
      if(fabs(d - width) < eps) {
        t_left = t_mid;
        break;
      }
      if(d > width)
        t1 = t_mid;
      else
        t0 = t_mid;
    }
    assign(ge, t_left, ge->mesh_vertices[start]);
    start++;
  }

  if(ln->getLength() < 1.e-12) {
    //    printf("GEdge %d -- end line lengths %12.5E %12.5E
    //    \n",ge->tag(),l0->getLength(),ln->getLength());
    diff++;
    GPoint g_right = ge->point(t_right);
    SPoint3 p0(g_right.x(), g_right.y(), g_right.z());
    while(1) {
      t_right -= dt;
      g_right = ge->point(t_right);
      SPoint3 p1(g_right.x(), g_right.y(), g_right.z());
      if(p1.distance(p0) > width) break;
    }

    double t0 = t_right;
    double t1 = t_right + dt;
    while(1) {
      double t_mid = (t0 + t1) * .5;
      g_right = ge->point(t_mid);
      SPoint3 p1(g_right.x(), g_right.y(), g_right.z());
      double d = p1.distance(p0);
      if(fabs(d - width) < eps) {
        t_right = t_mid;
        break;
      }
      if(d > width)
        t0 = t_mid;
      else
        t1 = t_mid;
    }
    assign(ge, t_right, ge->mesh_vertices[end]);
    end--;
  }

  if(diff == 0) return 0;

  int N;
  std::vector<IntPoint> Points;
  double a = 0.;
  int filterMinimumN = 0;

  meshGEdgeProcessing(ge, t_left, t_right, N, Points, a, filterMinimumN);
  N = ge->mesh_vertices.size() - diff + 2;

  //  printf("--> (%12.5E %12.5E) a = %12.5E\n",t_left, t_right,a );

  {
    int count = 1, NUMP = 1;
    const double b = a / static_cast<double>(N - 1);
    while(NUMP < N - 1) {
      auto P1 = Points[count - 1];
      auto P2 = Points[count];
      //      printf("count %d %g -- (%12.5E %12.5E) (%12.5E %12.5E)
      //      \n",count,b,P1.p,P1.t,P2.p,P2.t);
      const double d = (double)NUMP * b;
      if((std::abs(P2.p) >= std::abs(d)) && (std::abs(P1.p) < std::abs(d))) {
        double const dt = P2.t - P1.t;
        double const dp = P2.p - P1.p;
        double const t = P1.t + dt / dp * (d - P1.p);
        assign(ge, t, ge->mesh_vertices[start++]);
        NUMP++;
      }
      else {
        count++;
      }
    }
  }
  return 0;
}
