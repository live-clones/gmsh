// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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

#define SQU(a)      ((a)*(a))

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
  while (1){
    int count1 = 0;
    int count2 = 0;

    // use a gauss-seidel iteration; iterate forward and then backward;
    // convergence is usually very fast
    for (unsigned int i = 1; i < Points.size(); i++){
      double dh = (Points[i].xp/Points[i].lc - Points[i-1].xp/Points[i-1].lc);
      double dt = Points[i].t - Points[i-1].t;
      double dhdt =  dh/dt;
      if (dhdt / Points[i].xp > (alpha - 1.)*1.01){
	double hnew = Points[i-1].xp / Points[i-1].lc + dt * (alpha-1) * Points[i].xp;
	Points[i].lc = Points[i].xp / hnew;
	count1++;
      }
    }

    for (int i = Points.size() - 1; i > 0; i--){
      double dh = (Points[i-1].xp/Points[i-1].lc - Points[i].xp/Points[i].lc);
      double dt = fabs(Points[i-1].t - Points[i].t);
      double dhdt =  dh/dt;
      if (dhdt / Points[i-1].xp > (alpha-1.)*1.01){
      	double hnew = Points[i].xp / Points[i].lc + dt * (alpha-1) * Points[i].xp;
      	Points[i-1].lc = Points[i-1].xp / hnew;
      	count2 ++;
      }
    }

    ++ITER;
    if (ITER > 2000) break;
    if (!(count1 + count2)) break;
  }

  // recompute the primitive
  for (int i = 1; i < (int)Points.size(); i++){
    IntPoint &pt2 = Points[i];
    IntPoint &pt1 = Points[i-1];
    pt2.p = pt1.p + (pt2.t - pt1.t) * 0.5 * (pt2.lc + pt1.lc);
  }
  return Points[Points.size() - 1].p;
}


static double F_LcB(GEdge *ge, double t)
{
  /*  BoundaryLayerField *blf = 0;
#if defined(HAVE_ANN)
  FieldManager *fields = ge->model()->getFields();
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  blf = dynamic_cast<BoundaryLayerField*> (bl_field);
#endif
  */
  GPoint p = ge->point(t);
  double lc = BGM_MeshSize(ge, t, 0, p.x(), p.y(), p.z());

  /*  if (blf){
    double lc2 = (*blf)( p.x(), p.y(), p.z() , ge);
    //    printf("p %g %g lc %g\n",p.x(),p.y(),lc2);
    lc = std::min(lc, lc2);
  }
  */

  return lc;
}

static double F_Lc(GEdge *ge, double t)
{
  /*
  BoundaryLayerField *blf = 0;
#if defined(HAVE_ANN)
  FieldManager *fields = ge->model()->getFields();
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  blf = dynamic_cast<BoundaryLayerField*> (bl_field);
#endif
  */
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
  /*
  if (blf){
    double lc2 = (*blf)( p.x(), p.y(), p.z() , ge);
    //    printf("p %g %g lc %g\n",p.x(),p.y(),lc2);
    lc_here = std::min(lc_here, lc2);
  }
  */
  SVector3 der = ge->firstDer(t);
  const double d = norm(der);

  return d / lc_here;
}

static double F_Lc_aniso(GEdge *ge, double t)
{
#if defined(HAVE_ANN)
  FieldManager *fields = ge->model()->getFields();
  BoundaryLayerField *blf = 0;
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  blf = dynamic_cast<BoundaryLayerField*> (bl_field);
#else
  bool blf = false;
#endif

  //printf("coucou\n");


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

#if defined(HAVE_ANN)
  if (blf && !blf->isEdgeBL(ge->tag())){
    SMetric3 lc_bgm;
    blf->computeFor1dMesh ( p.x(), p.y(), p.z() , lc_bgm );
    lc_here = intersection_conserveM1 (lc_here, lc_bgm );
  }
#endif

  SVector3 der = ge->firstDer(t);
  double lSquared = dot(der, lc_here, der);
  return sqrt(lSquared);
}

static double F_Transfinite(GEdge *ge, double t_)
{
  double length = ge->length();
  if(length == 0.0){
    Msg::Error("Zero-length curve %d in transfinite mesh", ge->tag());
    return 1.;
  }

  SVector3 der = ge->firstDer(t_) ;
  double d = norm(der);
  double coef = ge->meshAttributes.coeffTransfinite;
  int type = ge->meshAttributes.typeTransfinite;
  int nbpt = ge->meshAttributes.nbPointsTransfinite;

  if(CTX::instance()->mesh.flexibleTransfinite && CTX::instance()->mesh.lcFactor)
    nbpt /= CTX::instance()->mesh.lcFactor;

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
        double r = (gmsh_sign(type) >= 0) ? coef : 1. / coef;
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

void copyMesh(GEdge *from, GEdge *to, int direction)
{
  Range<double> u_bounds = from->parBounds(0);
  double u_min = u_bounds.low();
  double u_max = u_bounds.high();

  Range<double> to_u_bounds = to->parBounds(0);
  double to_u_min = to_u_bounds.low();

  // include begin and end point to avoid conflicts when realigning

  MVertex* vt0 = to->getBeginVertex()->mesh_vertices[0];
  MVertex* vt1 = to->getEndVertex()->mesh_vertices[0];

  MVertex* vs0 = from->getBeginVertex()->mesh_vertices[0];
  MVertex* vs1 = from->getEndVertex()->mesh_vertices[0];

  to->correspondingVertices[vt0] = direction > 0 ? vs0 : vs1;
  to->correspondingVertices[vt1] = direction > 0 ? vs1 : vs0;

  for(unsigned int i = 0; i < from->mesh_vertices.size(); i++){
    int index = (direction < 0) ? (from->mesh_vertices.size() - 1 - i) : i;
    MVertex *v = from->mesh_vertices[index];
    double u; v->getParameter(0, u);
    double newu = (direction > 0) ? (u-u_min+to_u_min) : (u_max-u+to_u_min);
    GPoint gp = to->point(newu);
    MEdgeVertex *vv = new MEdgeVertex(gp.x(), gp.y(), gp.z(), to, newu);
    to->mesh_vertices.push_back(vv);
    to->correspondingVertices[vv] = v;
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
  if(ge->geomType() == GEntity::DiscreteCurve && !CTX::instance()->meshDiscrete)
    return;
  ge->deleteMesh();
  ge->meshStatistics.status = GEdge::PENDING;
  ge->correspondingVertices.clear();
}

/*
static void printFandPrimitive(int tag, std::vector<IntPoint> &Points)
{
  char name[256];
  sprintf(name, "line%d.dat", tag);
  FILE *f = Fopen(name, "w");
  if(!f) return;
  double l = 0;
  for (unsigned int i = 0; i < Points.size(); i++){
    const IntPoint &P = Points[i];
    if (i) l +=(P.t - Points[i-1].t)*P.xp;
    fprintf(f, "%g %g %g %g %g\n", P.t, P.xp/P.lc, P.p,P.lc, l);
  }
  fclose(f);
}
*/

// new algo for recombining + splitting
static int increaseN (int N)
{
  if (((N+1)/2 - 1) % 2 != 0) return N+2;
  return N;
}

// ensure not to have points that are too close to each other.
// can be caused by a coarse 1D mesh or by a noisy curve
static void filterPoints(GEdge*ge, int nMinimumPoints)
{
  if(ge->mesh_vertices.empty()) return;
  if(ge->meshAttributes.method == MESH_TRANSFINITE) return;
  //if (ge->mesh_vertices.size() <=3)return;
  bool forceOdd = false;
  if((ge->meshAttributes.method != MESH_TRANSFINITE ||
      CTX::instance()->mesh.flexibleTransfinite) &&
     CTX::instance()->mesh.algoRecombine != 0){
    if(CTX::instance()->mesh.recombineAll){
      forceOdd = true;
    }
  }

  MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
  std::vector<std::pair<double, MVertex*> > lengths;
  for (unsigned int i=0;i<ge->mesh_vertices.size();i++){
    MEdgeVertex *v = dynamic_cast<MEdgeVertex*> (ge->mesh_vertices[i]);
    if (!v){
      Msg::Error("in 1D mesh filterPoints");
      return;
    }
    double d = distance (v,v0);
    double t;
    v->getParameter(0,t);
    if (i != 0){
      double t0;
      v0->getParameter(0,t0);
      t=0.5*(t+t0);
    }
    double lc = F_LcB(ge, t);
    // double lc = v->getLc();
    if (d < lc * .3) {
      lengths.push_back(std::make_pair(lc/d,v));
    }
    else
      v0=v;
  }
  std::sort(lengths.begin(),lengths.end());
  int last = lengths.size();
  if (forceOdd) {
    while (last %2 != 0)last--;
  }
  /*
    if (CTX::instance()->mesh.algoRecombine == 2){
    if (last < 4)last = 0;
      while (last %4 != 0)last--;
      }
    else {
      while (last %2 != 0)last--;
      }
    }
  */

  bool filteringObservesMinimumN = (((int)ge->mesh_vertices.size() - last) >= nMinimumPoints);
  if (filteringObservesMinimumN){
    for (int i = 0; i < last; i++){
      std::vector<MVertex*>::iterator it = std::find(ge->mesh_vertices.begin(),
                                                     ge->mesh_vertices.end(),
                                                     lengths[i].second);
      ge->mesh_vertices.erase(it);
      delete lengths[i].second;
    }
  }
}

static void createPoints ( GVertex *gv, GEdge *ge, BoundaryLayerField *blf ,
			   std::vector<MVertex*>& v, const SVector3 &dir){
  double L = blf->hwall_n;

  double LEdge = distance (ge->getBeginVertex()->mesh_vertices[0],
			   ge->getEndVertex()->mesh_vertices[0]);

  while (1){
    if (L > blf->thickness || L > LEdge * .4) break;
    SPoint3 p (gv->x() + dir.x() * L, gv->y() + dir.y() * L, 0.0);
    v.push_back(new MEdgeVertex (p.x(), p.y(), p.z(), ge,  ge->parFromPoint(p), blf->hfar));
    int ith = v.size() ;
    L+= blf->hwall_n * pow (blf->ratio, ith);
    //    printf("parameter %g length %g\n",ge->parFromPoint(p),L);
  }
}

void addBoundaryLayerPoints (GEdge *ge,
			     double &t_begin, // may change the left  parameter of the interval
			     double &t_end,   // may change the right parameter of the interval
			     std::vector<MVertex*> &_addBegin, // additional points @ left
			     std::vector<MVertex*> &_addEnd)   // additional points @ right
{
  BoundaryLayerField *blf = 0;
#if defined(HAVE_ANN)
  FieldManager *fields = ge->model()->getFields();
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  blf = dynamic_cast<BoundaryLayerField*> (bl_field);
  if (blf) blf->setupFor1d(ge->tag());
#endif
  if (!blf) return;
  if (blf->isEdgeBL(ge->tag()))return;
  SVector3 dir ( ge->getEndVertex()->x() - ge->getBeginVertex()->x(),
		 ge->getEndVertex()->y() - ge->getBeginVertex()->y(),
		 ge->getEndVertex()->z() - ge->getBeginVertex()->z());
  dir.normalize();
  GVertex *gvb = ge->getBeginVertex();
  GVertex *gve = ge->getEndVertex();
  if (blf->isEndNode(gvb->tag())){
    if (ge->geomType() != GEntity::Line){
      Msg::Error ("Boundary layer end point %d should lie on a straight line", gvb->tag());
      return;
    }
    createPoints (gvb, ge, blf, _addBegin, dir);
    if (!_addBegin.empty())_addBegin[_addBegin.size()-1]->getParameter(0,t_begin);
  }
  if (blf->isEndNode(gve->tag())){
    if (ge->geomType() != GEntity::Line){
      Msg::Error ("Boundary layer end point %d should lie on a straight line", gve->tag());
      return;
    }
    createPoints (gve, ge, blf, _addEnd, dir * -1.0);
    if (!_addEnd.empty())_addEnd[_addEnd.size()-1]->getParameter(0,t_end);
  }

  //  printf("Edge %d § %d %d points added (%g %g)-\n", ge->tag(), _addBegin.size(),_addEnd.size(),t_begin,t_end);
}

void meshGEdge::operator() (GEdge *ge)
{
  /*
  BoundaryLayerField *blf = 0;
#if defined(HAVE_ANN)
  FieldManager *fields = ge->model()->getFields();
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  blf = dynamic_cast<BoundaryLayerField*> (bl_field);
  if (blf) blf->setupFor1d(ge->tag());
#endif
  */

  ge->model()->setCurrentMeshEntity(ge);

  //  if(ge->geomType() == GEntity::DiscreteCurve) return;
  if(ge->geomType() == GEntity::BoundaryLayerCurve) return;
  if(ge->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !ge->getVisibility()) return;

  // look if we are doing the STL triangulation
  std::vector<MVertex*> &mesh_vertices = ge->mesh_vertices ;
  std::vector<MLine*> &lines = ge->lines ;

  deMeshGEdge dem;
  dem(ge);

  if(MeshExtrudedCurve(ge)) return;

  if (ge->meshMaster() != ge){
    GEdge *gef = dynamic_cast<GEdge*> (ge->meshMaster());
    if (gef->meshStatistics.status == GEdge::PENDING) return;
    Msg::Info("Meshing curve %d (%s) as a copy of %d", ge->tag(),
              ge->getTypeString().c_str(), ge->meshMaster()->tag());
    copyMesh(gef, ge, ge->masterOrientation);
    ge->meshStatistics.status = GEdge::DONE;
    return;
  }

  if (ge->model()->getNumEdges() > 1000){
    if (ge->tag() % 1000 == 1){
      Msg::Info("Meshing curve %d/%d (%s)", ge->tag(), ge->model()->getNumEdges(), ge->getTypeString().c_str());
      }
  }
  else {
    Msg::Info("Meshing curve %d (%s)", ge->tag(), ge->getTypeString().c_str());
  }
  // compute bounds
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  // if a BL is ending at one of the ends, then create specific points
  std::vector<MVertex*> _addBegin, _addEnd;
  addBoundaryLayerPoints (ge, t_begin, t_end, _addBegin, _addEnd);

  // first compute the length of the curve by integrating one
  double length;
  std::vector<IntPoint> Points;
  if(ge->geomType() == GEntity::Line &&
      ge->getBeginVertex() == ge->getEndVertex() &&
      //do not consider closed lines as degenerated
      (ge->position(0.5) - ge->getBeginVertex()->xyz()).norm() < CTX::instance()->geom.tolerance)
    length = 0.; // special case t avoid infinite loop in integration
  else
    length = Integration(ge, t_begin, t_end, F_One, Points, 1.e-8 * CTX::instance()->lc);
  ge->setLength(length);
  Points.clear();

  if(length < CTX::instance()->mesh.toleranceEdgeLength){
    ge->setTooSmall(true);
  }

  // Integrate detJ/lc du
  double a;
  int N;
  int filterMinimumN = 1;
  if(length == 0. && CTX::instance()->mesh.toleranceEdgeLength == 0.){
    Msg::Debug("Curve %d has a zero length", ge->tag());
    a = 0.;
    N = 1;
  }
  else if(ge->degenerate(0)){
    a = 0.;
    N = 1;
  }
  else if(ge->meshAttributes.method == MESH_TRANSFINITE){
    a = Integration(ge, t_begin, t_end, F_Transfinite, Points,
                    CTX::instance()->mesh.lcIntegrationPrecision);
    N = ge->meshAttributes.nbPointsTransfinite;
    if(CTX::instance()->mesh.flexibleTransfinite && CTX::instance()->mesh.lcFactor)
      N /= CTX::instance()->mesh.lcFactor;
  }
  else{
    if (CTX::instance()->mesh.algo2d == ALGO_2D_BAMG/* || blf*/){
      a = Integration(ge, t_begin, t_end, F_Lc_aniso, Points,
                      CTX::instance()->mesh.lcIntegrationPrecision);
    }
    else{
       a = Integration(ge, t_begin, t_end, F_Lc, Points,
                      CTX::instance()->mesh.lcIntegrationPrecision);
    }

    // we should maybe provide an option to disable the smoothing
    for (unsigned int i = 0; i < Points.size(); i++){
      IntPoint &pt = Points[i];
      SVector3 der = ge->firstDer(pt.t);
      pt.xp = der.norm();
    }
    a = smoothPrimitive(ge, sqrt(CTX::instance()->mesh.smoothRatio), Points);
    filterMinimumN = ge->minimumMeshSegments() + 1;
    N = std::max(filterMinimumN, (int)(a + 1.99));
  }

  // force odd number of points if blossom is used for recombination
  if((ge->meshAttributes.method != MESH_TRANSFINITE ||
      CTX::instance()->mesh.flexibleTransfinite) &&
     CTX::instance()->mesh.algoRecombine != 0){
    if(CTX::instance()->mesh.recombineAll){
      if (N % 2 == 0) N++;
      if (CTX::instance()->mesh.algoRecombine == 2)
	N = increaseN(N);
    }
    else{
      std::list<GFace*> faces = ge->faces();
      for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
        if((*it)->meshAttributes.recombine){
	  if (N % 2 == 0) N ++;
	  if (CTX::instance()->mesh.algoRecombine == 2)
	    N = increaseN(N);
          break;
        }
      }
    }
  }

  //printFandPrimitive(ge->tag(),Points);

  // if the curve is periodic and if the begin vertex is identical to
  // the end vertex and if this vertex has only one model curve
  // adjacent to it, then the vertex is not connecting any other
  // curve. So, the mesh vertex and its associated geom vertex are not
  // necessary at the same location
  GPoint beg_p, end_p;
  if(!ge->getBeginVertex() && !ge->getEndVertex()){
    Msg::Warning("Skipping curve with no begin nor end vertex");
    return;
  }
  else if(ge->getBeginVertex() == ge->getEndVertex() &&
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
	// printf("%d %g\n",NUMP-1,t);
        mesh_vertices[NUMP - 1] = new MEdgeVertex(V.x(), V.y(), V.z(), ge, t, lc);
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
    std::vector<MVertex*> vv;
    vv.insert(vv.end(), _addBegin.begin(), _addBegin.end());
    vv.insert(vv.end(), mesh_vertices.begin(), mesh_vertices.end());
    for (unsigned int i=0;i<_addEnd.size();i++)
      vv.push_back(_addEnd[_addEnd.size()-1-i]);
    //    vv.insert(vv.end(), _addEnd.rend(), _addEnd.rbegin());
    mesh_vertices = vv;
  }

  //  printf("%ld ----> ", ge->mesh_vertices.size());
  if (_addBegin.empty() && _addEnd.empty())
    filterPoints (ge, filterMinimumN - 2);
  //  printf("%ld \n", ge->mesh_vertices.size());

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

void orientMeshGEdge::operator()(GEdge *ge)
{
  // apply user-specified mesh orientation constraints
  if(ge->meshAttributes.reverseMesh)
    for(unsigned int k = 0; k < ge->getNumMeshElements(); k++)
      ge->getMeshElement(k)->reverse();
}
