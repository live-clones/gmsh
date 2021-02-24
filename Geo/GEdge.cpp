// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <algorithm>
#include <numeric>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GEdge.h"
#include "GFace.h"
#include "MLine.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "closestPoint.h"
#include "discreteEdge.h"
#include "ExtrudeParams.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#endif

GEdge::GEdge(GModel *model, int tag, GVertex *v0, GVertex *v1)
  : GEntity(model, tag), _length(0.), _tooSmall(false), _cp(nullptr), _v0(v0),
    _v1(v1), masterOrientation(0), compoundCurve(nullptr)
{
  if(_v0) _v0->addEdge(this);
  if(_v1 && _v1 != _v0) _v1->addEdge(this);
  meshStatistics.status = GEdge::PENDING;
  GEdge::resetMeshAttributes();
}

GEdge::GEdge(GModel *model, int tag)
  : GEntity(model, tag), _length(0.), _tooSmall(false), _cp(nullptr),
    _v0(nullptr), _v1(nullptr), masterOrientation(0), compoundCurve(nullptr)
{
  meshStatistics.status = GEdge::PENDING;
  GEdge::resetMeshAttributes();
}

GEdge::~GEdge()
{
  if(_v0) _v0->delEdge(this);
  if(_v1 && _v1 != _v0) _v1->delEdge(this);
  if(_cp) delete _cp;
  GEdge::deleteMesh();
}

void GEdge::deleteMesh()
{
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  for(std::size_t i = 0; i < lines.size(); i++) delete lines[i];
  lines.clear();
  correspondingVertices.clear();
  correspondingHighOrderVertices.clear();
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

void GEdge::setMeshMaster(GEdge *ge, int ori)
{
  // FIXME: missing computation of affine transformation during setMeshMaster
  GEntity::setMeshMaster(ge);
  masterOrientation = ori > 0 ? 1 : -1;

  if(!getBeginVertex() || !ge->getBeginVertex() || !getEndVertex() ||
     !ge->getEndVertex())
    return;

  if(ori < 0) {
    vertexCounterparts[getBeginVertex()] = ge->getEndVertex();
    vertexCounterparts[getEndVertex()] = ge->getBeginVertex();
    getBeginVertex()->setMeshMaster(ge->getEndVertex());
    getEndVertex()->setMeshMaster(ge->getBeginVertex());
  }
  else {
    vertexCounterparts[getBeginVertex()] = ge->getBeginVertex();
    vertexCounterparts[getEndVertex()] = ge->getEndVertex();
    getBeginVertex()->setMeshMaster(ge->getBeginVertex());
    getEndVertex()->setMeshMaster(ge->getEndVertex());
  }
}

void GEdge::setMeshMaster(GEdge *ge, const std::vector<double> &tfo)
{
  if(!getBeginVertex() || !ge->getBeginVertex() || !getEndVertex() ||
     !ge->getEndVertex())
    return;

  SPoint3 oriXYZ0 = ge->getBeginVertex()->xyz();
  SPoint3 oriXYZ1 = ge->getEndVertex()->xyz();

  SPoint3 tfoXYZ0(0, 0, 0);
  SPoint3 tfoXYZ1(0, 0, 0);

  int idx = 0;
  for(int i = 0; i < 3; i++, idx++) {
    for(int j = 0; j < 3; j++, idx++) {
      tfoXYZ0[i] += tfo[idx] * oriXYZ0[j];
      tfoXYZ1[i] += tfo[idx] * oriXYZ1[j];
    }
    tfoXYZ0[i] += tfo[idx];
    tfoXYZ1[i] += tfo[idx];
  }

  SPoint3 locXYZ0 = getBeginVertex()->xyz();
  SPoint3 locXYZ1 = getEndVertex()->xyz();

  SVector3 d00 = locXYZ0 - tfoXYZ0;
  SVector3 d10 = locXYZ1 - tfoXYZ0;
  SVector3 d01 = locXYZ0 - tfoXYZ1;
  SVector3 d11 = locXYZ1 - tfoXYZ1;

  double tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;

  bool fwd = (d00.norm() * d11.norm() < d01.norm() * d10.norm());

  if((d00.norm() < tol) && (d11.norm() < tol)) {
    GEntity::setMeshMaster(ge, tfo);
    masterOrientation = 1;
    vertexCounterparts[getBeginVertex()] = ge->getBeginVertex();
    vertexCounterparts[getEndVertex()] = ge->getEndVertex();
    getBeginVertex()->setMeshMaster(ge->getBeginVertex(), tfo);
    getEndVertex()->setMeshMaster(ge->getEndVertex(), tfo);
    return;
  }

  if((d01.norm() < tol) && (d10.norm() < tol)) {
    GEntity::setMeshMaster(ge, tfo);
    masterOrientation = -1;
    vertexCounterparts[getBeginVertex()] = ge->getEndVertex();
    vertexCounterparts[getEndVertex()] = ge->getBeginVertex();
    getBeginVertex()->setMeshMaster(ge->getEndVertex(), tfo);
    getEndVertex()->setMeshMaster(ge->getBeginVertex(), tfo);
    return;
  }

  Msg::Info("Error in transformation from curve %d (%d-%d) to %d (%d-%d) "
            "(minimal transformed node distances %g %g, tolerance %g)",
            ge->tag(), ge->getBeginVertex()->tag(), ge->getEndVertex()->tag(),
            this->tag(), this->getBeginVertex()->tag(),
            this->getEndVertex()->tag(), fwd ? d00.norm() : d01.norm(),
            fwd ? d11.norm() : d10.norm(), tol);
}

void GEdge::reverse()
{
  GVertex *tmp = _v0;
  _v0 = _v1;
  _v1 = tmp;
  for(auto it = lines.begin(); it != lines.end(); it++) (*it)->reverse();
}

std::size_t GEdge::getNumMeshElementsByType(const int familyType) const
{
  if(familyType == TYPE_LIN) return lines.size();

  return 0;
}

std::size_t GEdge::getNumMeshParentElements()
{
  return std::count_if(lines.begin(), lines.end(), [](const MLine *const line) {
    return line->ownsParent();
  });
}

void GEdge::getNumMeshElements(unsigned *const c) const
{
  c[0] += lines.size();
}

MElement *const *GEdge::getStartElementType(int type) const
{
  if(lines.empty()) return nullptr; // msvc would throw an exception
  return reinterpret_cast<MElement *const *>(&lines[0]);
}

MElement *GEdge::getMeshElement(std::size_t index) const
{
  if(index < lines.size()) return lines[index];
  return nullptr;
}

MElement *GEdge::getMeshElementByType(const int familyType,
                                      const std::size_t index) const
{
  if(familyType == TYPE_LIN) return lines[index];

  return nullptr;
}

void GEdge::resetMeshAttributes()
{
  meshAttributes.method = MESH_UNSTRUCTURED;
  meshAttributes.coeffTransfinite = 0.;
  meshAttributes.nbPointsTransfinite = 0;
  meshAttributes.typeTransfinite = 0;
  meshAttributes.extrude = nullptr;
  meshAttributes.meshSize = MAX_LC;
  meshAttributes.meshSizeFactor = 1.;
  meshAttributes.minimumMeshSegments = 1;
  meshAttributes.reverseMesh = false;
}

void GEdge::addFace(GFace *f)
{
  if(std::find(_faces.begin(), _faces.end(), f) == _faces.end())
    _faces.push_back(f);
}

void GEdge::delFace(GFace *f)
{
  auto it = std::find(_faces.begin(), _faces.end(), f);
  if(it != _faces.end()) _faces.erase(it);
}

SBoundingBox3d GEdge::bounds(bool fast)
{
  SBoundingBox3d bbox;
  if(geomType() != DiscreteCurve && geomType() != BoundaryLayerCurve &&
     geomType() != PartitionCurve) {
    Range<double> tr = parBounds(0);
    const int N = fast ? 3 : 10;
    for(int i = 0; i < N; i++) {
      double t =
        tr.low() + (double)i / (double)(N - 1) * (tr.high() - tr.low());
      GPoint p = point(t);
      bbox += SPoint3(p.x(), p.y(), p.z());
    }
  }
  else {
    for(std::size_t i = 0; i < getNumMeshElements(); i++)
      for(std::size_t j = 0; j < getMeshElement(i)->getNumVertices(); j++)
        bbox += getMeshElement(i)->getVertex(j)->point();
  }
  return bbox;
}

SOrientedBoundingBox GEdge::getOBB()
{
  if(!_obb) {
    std::vector<SPoint3> vertices;
    if(getNumMeshVertices() > 0) {
      int N = getNumMeshVertices();
      for(int i = 0; i < N; i++) {
        MVertex *mv = getMeshVertex(i);
        vertices.push_back(mv->point());
      }
      // Don't forget to add the first and last vertices...
      if(getBeginVertex()) {
        SPoint3 pt1(getBeginVertex()->x(), getBeginVertex()->y(),
                    getBeginVertex()->z());
        vertices.push_back(pt1);
      }
      if(getEndVertex()) {
        SPoint3 pt2(getEndVertex()->x(), getEndVertex()->y(),
                    getEndVertex()->z());
        vertices.push_back(pt2);
      }
    }
    else if(geomType() != DiscreteCurve && geomType() != BoundaryLayerCurve) {
      Range<double> tr = this->parBounds(0);
      // N can be choosen arbitrarily, but 10 points seems reasonable
      int N = 10;
      for(int i = 0; i < N; i++) {
        double t =
          tr.low() + (double)i / (double)(N - 1) * (tr.high() - tr.low());
        GPoint p = point(t);
        SPoint3 pt(p.x(), p.y(), p.z());
        vertices.push_back(pt);
      }
    }
    else {
      SPoint3 dummy(0, 0, 0);
      vertices.push_back(dummy);
    }
    _obb = SOrientedBoundingBox::buildOBB(vertices);
  }
  return SOrientedBoundingBox(_obb);
}

void GEdge::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive) {
    if(_v0) _v0->setVisibility(val);
    if(_v1) _v1->setVisibility(val);
  }
}

void GEdge::setColor(unsigned int val, bool recursive)
{
  GEntity::setColor(val);
  if(recursive) {
    if(_v0) _v0->setColor(val);
    if(_v1) _v1->setColor(val);
  }
}

std::string GEdge::getAdditionalInfoString(bool multline)
{
  std::ostringstream sstream;
  sstream.precision(12);

  if(_v0 && _v1) {
    sstream << "Boundary points: " << _v0->tag() << ", " << _v1->tag();
    GPoint p0 = _v0->point();
    GPoint p1 = _v1->point();
    sstream << " (distance = " << p0.distance(p1) << ")";
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(_faces.size()) {
    sstream << "On boundary of surfaces: ";
    for(auto it = _faces.begin(); it != _faces.end(); ++it) {
      if(it != _faces.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(meshAttributes.method == MESH_TRANSFINITE ||
     (meshAttributes.extrude && meshAttributes.extrude->mesh.ExtrudeMesh) ||
     meshAttributes.reverseMesh ||
     (getMeshMaster() && getMeshMaster() != this)) {
    sstream << "Mesh attributes:";
    if(meshAttributes.method == MESH_TRANSFINITE) {
      sstream << " transfinite " << meshAttributes.nbPointsTransfinite;
      int type = meshAttributes.typeTransfinite;
      if(std::abs(type) == 1)
        sstream << ", progression "
                << gmsh_sign(type) * meshAttributes.coeffTransfinite;
      else if(std::abs(type) == 2)
        sstream << ", bump " << meshAttributes.coeffTransfinite;
      else if(std::abs(type) == 3)
        sstream << ", beta " << meshAttributes.coeffTransfinite;
    }
    if(meshAttributes.extrude && meshAttributes.extrude->mesh.ExtrudeMesh)
      sstream << " extruded";
    if(meshAttributes.reverseMesh) sstream << " reversed";
    if(getMeshMaster() && getMeshMaster() != this)
      sstream << " periodic copy of curve " << getMeshMaster()->tag();
  }

  std::string str = sstream.str();
  if(str.size() && (str[str.size() - 1] == '\n' || str[str.size() - 1] == ' '))
    str.resize(str.size() - 1);
  return str;
}

void GEdge::writeGEO(FILE *fp)
{
  if(!getBeginVertex() || !getEndVertex() || geomType() == DiscreteCurve)
    return;

  if(geomType() == Line) {
    fprintf(fp, "Line(%d) = {%d, %d};\n", tag(), getBeginVertex()->tag(),
            getEndVertex()->tag());
  }
  else {
    // approximate other curves by splines
    Range<double> bounds = parBounds(0);
    double umin = bounds.low();
    double umax = bounds.high();
    fprintf(fp, "p%d = newp;\n", tag());
    int N = minimumDrawSegments();
    for(int i = 1; i < N; i++) {
      double u = umin + (double)i / N * (umax - umin);
      GPoint p = point(u);
      fprintf(fp, "Point(p%d + %d) = {%.16g, %.16g, %.16g};\n", tag(), i, p.x(),
              p.y(), p.z());
    }
    fprintf(fp, "Spline(%d) = {%d", tag(), getBeginVertex()->tag());
    for(int i = 1; i < N; i++) fprintf(fp, ", p%d + %d", tag(), i);
    fprintf(fp, ", %d};\n", getEndVertex()->tag());
  }

  if(meshAttributes.method == MESH_TRANSFINITE) {
    fprintf(fp, "Transfinite Line {%d} = %d",
            tag() * (meshAttributes.typeTransfinite > 0 ? 1 : -1),
            meshAttributes.nbPointsTransfinite);
    if(meshAttributes.typeTransfinite) {
      if(std::abs(meshAttributes.typeTransfinite) == 1)
        fprintf(fp, " Using Progression ");
      else if(std::abs(meshAttributes.typeTransfinite) == 2)
        fprintf(fp, " Using Bump ");
      else
        fprintf(fp, " Using Beta ");
      fprintf(fp, "%g", meshAttributes.coeffTransfinite);
    }
    fprintf(fp, ";\n");
  }

  if(meshAttributes.reverseMesh) fprintf(fp, "Reverse Line {%d};\n", tag());
}

bool GEdge::containsParam(double pt) const
{
  Range<double> rg = parBounds(0);
  return (pt >= rg.low() && pt <= rg.high());
}

SVector3 GEdge::secondDer(double par) const
{
  // use central differences
  const double eps = 1.e-3;
  Range<double> rg = parBounds(0);
  if(par - eps <= rg.low()) {
    SVector3 x1 = firstDer(par);
    SVector3 x2 = firstDer(par + eps);
    return 1000 * (x2 - x1);
  }
  else if(par + eps >= rg.high()) {
    SVector3 x1 = firstDer(par - eps);
    SVector3 x2 = firstDer(par);
    return 1000 * (x2 - x1);
  }
  SVector3 x1 = firstDer(par - eps);
  SVector3 x2 = firstDer(par + eps);
  return 500 * (x2 - x1);
}

SPoint2 GEdge::reparamOnFace(const GFace *face, double epar, int dir) const
{
  // reparametrize the point onto the given face.
  const GPoint p3 = point(epar);
  SPoint3 sp3(p3.x(), p3.y(), p3.z());
  return face->parFromPoint(sp3);
}

double GEdge::curvature(double par) const
{
  SVector3 const d1 = firstDer(par);
  return norm(crossprod(d1, secondDer(par))) * std::pow(1.0 / norm(d1), 3);
}

double GEdge::length(const double &u0, const double &u1, const int nbQuadPoints)
{
  double *t = nullptr, *w = nullptr;
  gmshGaussLegendre1D(nbQuadPoints, &t, &w);
  if(!t) {
    Msg::Error("Gauss-Legendre integration returned no points");
    return 0;
  }
  double L = 0.0;
  const double rapJ = (u1 - u0) * 0.5;
  for(int i = 0; i < nbQuadPoints; i++) {
    const double ui = u0 * 0.5 * (1. - t[i]) + u1 * 0.5 * (1. + t[i]);
    SVector3 der = firstDer(ui);
    const double d = norm(der);
    L += d * w[i] * rapJ;
  }
  return L;
}

/*
  consider a curve x(t) and a point y
  use a golden section algorithm that minimizes
  min_t \|x(t)-y\|
*/
const double GOLDEN = (1.0 + std::sqrt(5.0)) / 2.0;
const double GOLDEN2 = 2.0 - GOLDEN;

// x1 and x3 are the current bounds; the minimum is between them.
// x2 is the center point, which is closer to x1 than to x3

double goldenSectionSearch(const GEdge *ge, const SPoint3 &q, double x1,
                           double x2, double x3, double tau)
{
  // Create a new possible center in the area between x2 and x3, closer to x2
  double x4 = x2 + GOLDEN2 * (x3 - x2);

  // Evaluate termination criterion
  if(std::abs(x3 - x1) < tau * (std::abs(x2) + std::abs(x4)))
    return (x3 + x1) / 2;

  const SVector3 dp4 = q - ge->position(x4);
  const SVector3 dp2 = q - ge->position(x2);

  const double d4 = dp4.norm();
  const double d2 = dp2.norm();

  return d4 < d2 ? goldenSectionSearch(ge, q, x2, x4, x3, tau) :
                   goldenSectionSearch(ge, q, x4, x2, x1, tau);
}

GPoint GEdge::closestPoint(const SPoint3 &q, double &t) const
{
  // printf("looking for closest point in curve %d to point %g
  // %g\n",tag(),q.x(),q.y());

  const int nbSamples = 100;

  Range<double> interval = parBounds(0);

  double tMin = std::min(interval.high(), interval.low());
  double tMax = std::max(interval.high(), interval.low());

  double DMIN = 1.e22;
  double topt = tMin;
  const double DT = (tMax - tMin) / (nbSamples - 1.);
  for(int i = 0; i < nbSamples; i++) {
    t = tMin + i * DT;
    const SVector3 dp = q - position(t);
    const double D = dp.norm();
    if(D < DMIN) {
      topt = t;
      DMIN = D;
    }
  }

  // printf("parameter %g as an initial guess (dist = %g)\n",topt,DMIN);

  if(topt == tMin)
    t = goldenSectionSearch(this, q, topt, topt + DT / 2, topt + DT, 1.e-9);
  else if(topt == tMax)
    t = goldenSectionSearch(this, q, topt - DT, topt - DT / 2, topt, 1.e-9);
  else
    t = goldenSectionSearch(this, q, topt - DT, topt, topt + DT, 1.e-9);

  const SVector3 dp = q - position(t);
  // const double D = dp.norm();
  // printf("after golden section parameter %g  (dist = %g)\n",t,D);

  return point(t);
}

double GEdge::parFromPoint(const SPoint3 &P) const
{
  double t;
  XYZToU(P.x(), P.y(), P.z(), t);
  return t;
}

bool GEdge::refineProjection(const SVector3 &Q, double &u, int MaxIter,
                             double relax, double tol, double &err) const
{
  double maxDist = tol * CTX::instance()->lc;

  SVector3 P = position(u);
  SVector3 dPQ = P - Q;

  Range<double> uu = parBounds(0);
  double uMin = uu.low();
  double uMax = uu.high();
  err = dPQ.norm();

  int iter = 0;
  while(iter++ < MaxIter && err > maxDist) {
    SVector3 der = firstDer(u);
    double du = dot(dPQ, der) / dot(der, der);

    if(du < tol && dPQ.norm() > maxDist) du = 1;

    // if (fabs(du) < tol) break;

    double uNew = u - relax * du;
    uNew = std::min(uMax, std::max(uMin, uNew));
    P = position(uNew);

    dPQ = P - Q;
    err = dPQ.norm();
    // err2 = fabs(uNew - u);
    u = uNew;
  }
  return err <= maxDist;
}

bool GEdge::XYZToU(const double X, const double Y, const double Z, double &u,
                   const double relax, bool first) const
{
  const int MaxIter = 25;
  const int NumInitGuess = 21;

  std::map<double, double> errorVsParameter;

  double err;
  double tol = 1e-8;

  Range<double> uu = parBounds(0);
  double uMin = uu.low();
  double uMax = uu.high();

  const SVector3 Q(X, Y, Z);

  double uTry = uMin;

  for(int i = 0; i < NumInitGuess; i++) {
    uTry = uMin + (uMax - uMin) / (NumInitGuess - 1) * i;
    if(refineProjection(Q, uTry, MaxIter, relax, tol, err)) {
      u = uTry;
      return true;
    }
    errorVsParameter[err] = uTry;
  }

  if(relax > 1.e-1) {
    if(XYZToU(X, Y, Z, uTry, 0.75 * relax, false)) {
      u = uTry;
      return true;
    }
    SVector3 P = position(uTry);
    SVector3 dPQ = P - Q;
    errorVsParameter[dPQ.norm()] = uTry;
  }

  u = errorVsParameter.begin()->second;
  if(first) {
    Msg::Warning(
      "Could not converge parametrisation of (%g,%g,%g) on curve %d, "
      "taking parameter with lowest error",
      X, Y, Z, tag());
  }

  return false;
}

// regions that bound this entity or that this entity bounds.
std::list<GRegion *> GEdge::regions() const
{
  std::vector<GFace *> _faces = faces();
  std::set<GRegion *> _r;
  for(auto it = _faces.begin(); it != _faces.end(); ++it) {
    std::list<GRegion *> temp = (*it)->regions();
    _r.insert(temp.begin(), temp.end());
  }
  std::list<GRegion *> ret;
  ret.insert(ret.begin(), _r.begin(), _r.end());
  return ret;
}

void GEdge::relocateMeshVertices()
{
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) {
    MVertex *v = mesh_vertices[i];
    double u0 = 0;
    if(v->getParameter(0, u0)) {
      GPoint p = point(u0);
      v->x() = p.x();
      v->y() = p.y();
      v->z() = p.z();
    }
  }
}

SPoint3 GEdge::closestPointWithTol(SPoint3 &p, double tolerance)
{
  if(!_cp || _cp->tol() != tolerance) {
    if(_cp) delete _cp;
    _cp = new closestPointFinder(this, tolerance);
  }
  return (*_cp)(p);
}

typedef struct {
  SPoint3 p;
  double t;
  int next;
} sortedPoint;

static double sqDistPointSegment(const SPoint3 &p, const SPoint3 &s0,
                                 const SPoint3 &s1)
{
  SVector3 d(s1 - s0);
  SVector3 d0(p - s0);
  SVector3 d1(p - s1);
  double dn2 = crossprod(d, d0).normSq();
  double dt2 = std::max(0., std::max(-dot(d, d0), dot(d, d1)));
  dt2 *= dt2;
  return (dt2 + dn2) / d.normSq();
}

static void _discretize(double tol, GEdge *edge, std::vector<sortedPoint> &upts,
                        int pos0)
{
  const int pos1 = upts[pos0].next;
  const SPoint3 &p0 = upts[pos0].p;
  const double t0 = upts[pos0].t;
  const SPoint3 &p1 = upts[pos1].p;
  const double t1 = upts[pos1].t;
  const double tmid = 0.5 * (t0 + t1);
  const SPoint3 pmid(edge->position(tmid));
  const double d2 = sqDistPointSegment(pmid, p0, p1);
  if(d2 < tol * tol) return;
  sortedPoint pnt = {pmid, tmid, pos1};
  upts.push_back(pnt);
  const int posmid = upts.size() - 1;
  upts[pos0].next = posmid;
  _discretize(tol, edge, upts, pos0);
  _discretize(tol, edge, upts, posmid);
}

void GEdge::addElement(int type, MElement *e)
{
  switch(type) {
  case TYPE_LIN: addLine(reinterpret_cast<MLine *>(e)); break;
  default: Msg::Error("Trying to add unsupported element in curve %d", tag());
  }
}

void GEdge::removeElement(int type, MElement *e)
{
  switch(type) {
  case TYPE_LIN: {
    auto it =
      std::find(lines.begin(), lines.end(), reinterpret_cast<MLine *>(e));
    if(it != lines.end()) lines.erase(it);
  } break;
  default:
    Msg::Error("Trying to remove unsupported element in curve %d", tag());
  }
}

void GEdge::discretize(double tol, std::vector<SPoint3> &dpts,
                       std::vector<double> &ts)
{
  std::vector<sortedPoint> upts;
  if(getBeginVertex()) {
    sortedPoint pnt1 = {getBeginVertex()->xyz(), 0., 1};
    upts.push_back(pnt1);
  }
  if(getEndVertex()) {
    sortedPoint pnt2 = {getEndVertex()->xyz(), 1., -1};
    upts.push_back(pnt2);
  }
  _discretize(tol, this, upts, 0);
  dpts.clear();
  dpts.reserve(upts.size());
  ts.clear();
  ts.reserve(upts.size());
  for(int p = 0; p != -1; p = upts[p].next) {
    dpts.push_back(upts[p].p);
    ts.push_back(upts[p].t);
  }
}

#if defined(HAVE_MESH)

static bool recreateConsecutiveElements(GEdge *ge)
{
  std::size_t ss = ge->lines.size();
  if(!ss) return true;

  std::vector<MEdge> ed;
  std::vector<std::vector<MVertex *> > vs;
  for(std::size_t i = 0; i < ge->lines.size(); i++) {
    ed.push_back(MEdge(ge->lines[i]->getVertex(0), ge->lines[i]->getVertex(1)));
  }
  ge->lines.clear();

  if(!SortEdgeConsecutive(ed, vs))
    Msg::Warning("Line elements on curve %d cannot be ordered", ge->tag());

  if(vs.size() != 1)
    Msg::Warning("Mesh of curve %d is mutiply connected", ge->tag());

  std::size_t start = 0;
  for(; start < vs[0].size(); start++)
    if(vs[0][start]->onWhat()->dim() == 0) break;

  if(start == vs[0].size())
    Msg::Warning("Mesh topology of curve %d is wrong", ge->tag());

  std::size_t i = start;
  while(ge->lines.size() != ss) {
    if(vs[0][i % vs[0].size()] != vs[0][(i + 1) % vs[0].size()])
      ge->lines.push_back(
        new MLine(vs[0][i % vs[0].size()], vs[0][(i + 1) % vs[0].size()]));
    i++;
  }

  ge->mesh_vertices.clear();
  for(std::size_t i = 0; i < ge->lines.size() - 1; ++i) {
    MVertex *v11 = ge->lines[i]->getVertex(1);
    if(v11->onWhat() == ge || !v11->onWhat()) {
      v11->setEntity(ge);
      ge->mesh_vertices.push_back(v11);
    }
  }

  return true;
}

static void meshCompound(GEdge *ge)
{
  auto *de = new discreteEdge(ge->model(), ge->tag() + 100000);
  ge->model()->add(de);
  std::vector<int> phys;
  for(std::size_t i = 0; i < ge->compound.size(); i++) {
    auto *c = (GEdge *)ge->compound[i];
    de->lines.insert(de->lines.end(), c->lines.begin(), c->lines.end());
    c->compoundCurve = de;
    phys.insert(phys.end(), c->physicals.begin(), c->physicals.end());
    c->physicals.clear();
  }

  // recreate a 1D mesh with consecutive elements (this creates new MLines)
  recreateConsecutiveElements(de);
  // create the geometry
  de->createGeometry();
  // delete the MLines just created above
  for(std::size_t i = 0; i < de->lines.size(); i++) delete de->lines[i];
  de->lines.clear();
  de->mesh_vertices.clear();
  de->mesh(false);
  de->physicals = phys;
}

#endif

void GEdge::mesh(bool verbose)
{
#if defined(HAVE_MESH)
  if(compound.size())
    meshAttributes.meshSizeFactor = CTX::instance()->mesh.compoundLcFactor;

  meshGEdge mesher;
  mesher(this);

  if(compound.size()) { // Some edges are meshed together
    meshAttributes.meshSizeFactor = 1.0;

    if(compound[0] == this) { // I'm the one that makes the compound job
      bool ok = true;
      for(std::size_t i = 0; i < compound.size(); i++) {
        auto *ge = (GEdge *)compound[i];
        ok &= (ge->meshStatistics.status == GEdge::DONE);
      }
      if(!ok) { meshStatistics.status = GEdge::PENDING; }
      else {
        meshCompound(this);
        meshStatistics.status = GEdge::DONE;
        return;
      }
    }
  }
#endif
}

bool GEdge::reorder(const int elementType,
                    const std::vector<std::size_t> &ordering)
{
  if(lines.size() != 0) {
    if(lines.front()->getTypeForMSH() != elementType) { return false; }

    if(ordering.size() != lines.size()) return false;

    for(auto it = ordering.begin(); it != ordering.end(); ++it) {
      if(*it >= lines.size()) return false;
    }

    std::vector<MLine *> newLinesOrder(lines.size());
    for(std::size_t i = 0; i < ordering.size(); i++) {
      newLinesOrder[i] = lines[ordering[i]];
    }

    lines = std::move(newLinesOrder);
    return true;
  }

  return false;
}

std::vector<GVertex *> GEdge::vertices() const
{
  std::vector<GVertex *> res;
  if(getBeginVertex()) res.push_back(getBeginVertex());
  if(getEndVertex()) res.push_back(getEndVertex());
  return res;
}

double GEdge::prescribedMeshSizeAtParam(double u)
{
  if(_lc.empty()) { return MAX_LC; }
  const auto &it = std::lower_bound(_u_lc.begin(), _u_lc.end(), u);
  size_t i1 = std::min<size_t>(it - _u_lc.begin(), _u_lc.size() - 1);
  size_t i0 = std::max<size_t>(1, i1) - 1;
  double u0 = _u_lc[i0], u1 = _u_lc[i1];
  double l0 = _lc[i0], l1 = _lc[i1];
  if(i1 == i0 || u0 == u1) return l0;
  double alpha = (u - u0) / (u1 - u0);
  return l0 * (1 - alpha) + l1 * (alpha);
}

struct vindexsort {
  const std::vector<double> &v;
  vindexsort(const std::vector<double> &vp) : v(vp){};
  bool operator()(size_t i0, size_t i1) { return v[i0] < v[i1]; }
};

void GEdge::setMeshSizeParametric(const std::vector<double> u,
                                  const std::vector<double> lc)
{
  if(u.size() != lc.size()) {
    Msg::Error("setMeshSizeParametric : number of coordinates and number of "
               "mesh size do not match.");
  }
  std::vector<size_t> index(u.size());
  for(size_t i = 0; i < u.size(); ++i) index[i] = i;
  std::sort(index.begin(), index.end(), vindexsort(u));
  _u_lc.resize(u.size());
  _lc.resize(lc.size());
  for(size_t i = 0; i < u.size(); ++i) {
    _u_lc[i] = u[index[i]];
    _lc[i] = lc[index[i]];
  }
}
