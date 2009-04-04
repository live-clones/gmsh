// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <algorithm>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GEdge.h"
#include "GFace.h"
#include "MLine.h"

#if defined(HAVE_GMSH_EMBEDDED)
#include "GmshEmbedded.h"
#else
#include "GaussLegendre1D.h"
#include "Context.h"
#endif

GEdge::GEdge(GModel *model, int tag, GVertex *_v0, GVertex *_v1)
  : GEntity(model, tag), _tooSmall(false), v0(_v0), v1(_v1)
{
  if(v0) v0->addEdge(this);
  if(v1 && v1 != v0) v1->addEdge(this);
  resetMeshAttributes();
}

GEdge::~GEdge()
{
  if(v0) v0->delEdge(this);
  if(v1 && v1 != v0) v1->delEdge(this);

  deleteMesh();
}

void GEdge::deleteMesh()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  for(unsigned int i = 0; i < lines.size(); i++) delete lines[i];
  lines.clear();
}

unsigned int GEdge::getNumMeshElements()
{ 
  return lines.size();
}

void GEdge::getNumMeshElements(unsigned *const c) const
{
  c[0] += lines.size();
}

MElement *const *GEdge::getStartElementType(int type) const
{
  if(lines.empty()) return 0; // msvc would throw an exception
  return reinterpret_cast<MElement *const *>(&lines[0]);
}

MElement *GEdge::getMeshElement(unsigned int index)
{ 
  if(index < lines.size())
    return lines[index]; 
  return 0;
}

void GEdge::resetMeshAttributes()
{
  meshAttributes.Method = MESH_UNSTRUCTURED;
  meshAttributes.coeffTransfinite = 0.;
  meshAttributes.nbPointsTransfinite = 0;
  meshAttributes.typeTransfinite = 0;
  meshAttributes.extrude = 0;
  meshAttributes.meshSize = MAX_LC;
  meshAttributes.minimumMeshSegments = 1;
}

void GEdge::addFace(GFace *e)
{
  l_faces.push_back(e);
}

void GEdge::delFace(GFace *e)
{
  l_faces.erase(std::find(l_faces.begin(), l_faces.end(), e));
}

SBoundingBox3d GEdge::bounds() const
{
  SBoundingBox3d bbox;
  if(geomType() != DiscreteCurve && geomType() != BoundaryLayerCurve){
    Range<double> tr = parBounds(0);
    const int N = 10;
    for(int i = 0; i < N; i++){
      double t = tr.low() + (double)i / (double)(N - 1) * (tr.high() - tr.low());
      GPoint p = point(t);
      bbox += SPoint3(p.x(), p.y(), p.z());
    }
  }
  else{
    for(unsigned int i = 0; i < mesh_vertices.size(); i++)
      bbox += mesh_vertices[i]->point();
  }
  return bbox;
}

void GEdge::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    if(v0) v0->setVisibility(val);
    if(v1) v1->setVisibility(val);
  }
}

std::string GEdge::getAdditionalInfoString()
{
  std::ostringstream sstream;
  if(v0 && v1) sstream << "{" << v0->tag() << "," << v1->tag() << "}";
  return sstream.str();
}

void GEdge::writeGEO(FILE *fp)
{
  if(!getBeginVertex() || !getEndVertex() || geomType() == DiscreteCurve) return;

  if(geomType() == Line){
    fprintf(fp, "Line(%d) = {%d, %d};\n", 
            tag(), getBeginVertex()->tag(), getEndVertex()->tag());
  }
  else{
    // approximate other curves by splines
    Range<double> bounds = parBounds(0);
    double umin = bounds.low();
    double umax = bounds.high();
    fprintf(fp, "p%d = newp;\n", tag());
    for(int i = 1; i < minimumDrawSegments(); i++){
      double u = umin + (double)i / minimumDrawSegments() * (umax - umin);
      GPoint p = point(u);
      fprintf(fp, "Point(p%d + %d) = {%.16g, %.16g, %.16g};\n", 
              tag(), i, p.x(), p.y(), p.z());
    }
    fprintf(fp, "Spline(%d) = {%d", tag(), getBeginVertex()->tag());
    for(int i = 1; i < minimumDrawSegments(); i++)
      fprintf(fp, ", p%d + %d", tag(), i);
    fprintf(fp, ", %d};\n", getEndVertex()->tag());
  }
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
  SVector3 x1 = firstDer(par - eps);
  SVector3 x2 = firstDer(par + eps);
  return 500 * (x2 - x1);
}

SPoint2 GEdge::reparamOnFace(const GFace *face, double epar,int dir) const
{
  // reparmaterize the point onto the given face.
  const GPoint p3 = point(epar);
  SPoint3 sp3(p3.x(), p3.y(), p3.z());
  return face->parFromPoint(sp3);
}

double GEdge::curvature(double par) const
{
  double eps1 = 1.e-5;
  double eps2 = 1.e-5;

  Range<double> r = parBounds(0);
  if(r.low() == par) eps2 = 0;
  if(r.high() == par) eps1 = 0;

  SVector3 n1 = firstDer(par - eps1);
  SVector3 n2 = firstDer(par + eps2);

  GPoint P1 = point(par - eps1);
  GPoint P2 = point(par + eps2);

  double D = sqrt ((P1.x() - P2.x()) * (P1.x() - P2.x()) +
                   (P1.y() - P2.y()) * (P1.y() - P2.y()) +
                   (P1.z() - P2.z()) * (P1.z() - P2.z()));

  n1.normalize();
  n2.normalize();
  const double one_over_D = 1. / D;
  SVector3 d = one_over_D * (n2 - n1);
  return norm(d);
  
}

double GEdge::length(const double &u0, const double &u1, const int nbQuadPoints)
{
#if defined(HAVE_GMSH_EMBEDDED)
  return -1.;
#else
  double *t = 0, *w = 0;
  gmshGaussLegendre1D(nbQuadPoints, &t, &w);
  double L = 0.0;
  const double rapJ = (u1 - u0) * .5;
  for (int i = 0; i < nbQuadPoints; i++){
    const double ui = u0 * 0.5 * (1. - t[i]) + u1 * 0.5 * (1. + t[i]);
    SVector3 der = firstDer(ui);
    const double d = norm(der);
    L += d * w[i] * rapJ;
  }
  return L;
#endif
}

GPoint GEdge::closestPoint(const SPoint3 &q, double &t) const
{
  double tolerance = 1.e-12;
  double dist = 1.;

  Range<double> interval = parBounds(0);
  
  double tMin = std::min(interval.high(), interval.low());
  double tMax = std::max(interval.high(), interval.low());
  double relax = 1.;
  double dt, dt0, t0;
  int nb = 10;
  
  t = (tMin + tMax) * 0.5;
  
  while (relax > 0.1) {
    int i = 0;
    t = 0.5 * (tMin + tMax);
    dt0 = tMax - tMin;
    dt = dt0;
    while (dt > tolerance * dt0 && i++ < nb) {
      t0 = t;
      dt0 = dt;
      SVector3 dp = q - position(t);
      SVector3 derP = firstDer(t);
      double b = dot(derP, derP);
      double c = dot(derP, dp);
      dt = c / b;
      t = std::max(tMin, std::min(tMax, t0 + relax * dt));
      dt = fabs(t - t0);
    }
    if (i > nb)  relax *= 0.5;
  }
  return point(t);
}

double GEdge::parFromPoint(const SVector3 &Q) const
{
  double t;
  bool success = XYZToU(Q, t);
  return t;
}

bool GEdge::XYZToU(const SVector3 &Q, double &u, const double relax) const
{
  const double Precision = 1.e-8;
  const int MaxIter = 25;
  const int NumInitGuess = 11;

  double err, err2;
  int iter;

  Range<double> uu = parBounds(0);
  double uMin = uu.low();
  double uMax = uu.high();

  SVector3 P;
  
  double init[NumInitGuess];
  
  for (int i = 0; i < NumInitGuess; i++) 
    init[i] = uMin + (uMax - uMin) / (NumInitGuess - 1) * i;
  
  for(int i = 0; i < NumInitGuess; i++){
    u = init[i];
    double uNew = u;
    err = 1.0;
    iter = 1;

    SVector3 dPQ = P - Q;
    err2 = dPQ.norm();
    
    if (err2 < 1.e-8 * CTX::instance()->lc) return true;    
    
    while(iter++ < MaxIter && err2 > 1e-8 * CTX::instance()->lc) {
      SVector3 der = firstDer(u);
      uNew = u - relax * dot(dPQ,der) / dot(der,der);
      uNew = std::min(uMax,std::max(uMin,uNew));
      P = position(uNew);
      
      dPQ = P - Q;
      err2 = dPQ.norm();
      err = fabs(uNew - u);
      u = uNew;
    } 
  
    if (err2 < 1e-8 * CTX::instance()->lc) return true;
  }
  
  if(relax > 1.e-2) {
    Msg::Info("point %g %g %g on edge %d : Relaxation factor = %g", 
              Q.x(), Q.y(), Q.z(), 0.75 * relax);
    return XYZToU(Q, u, 0.75 * relax);
  }
  
  Msg::Error("Could not converge reparametrisation of point (%e,%e,%e) on edge %d",
             Q.x(), Q.y(), Q.z(), tag());
  return false;
}
