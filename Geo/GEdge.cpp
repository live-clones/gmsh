// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
#include "GaussLegendre1D.h"
#include "Context.h"

GEdge::GEdge(GModel *model, int tag, GVertex *_v0, GVertex *_v1)
  : GEntity(model, tag), _tooSmall(false), v0(_v0), v1(_v1), compound(0)
{
  if(v0) v0->addEdge(this);
  if(v1 && v1 != v0) v1->addEdge(this);
  meshStatistics.status = GEdge::PENDING;
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
  _normals.clear();
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

void GEdge::reverse()
{
  GVertex* tmp = v0;
  v0 = v1;
  v1 = tmp;
  for(std::vector<MLine*>::iterator line = lines.begin(); line != lines.end(); line++)
    (*line)->revert();
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

SOrientedBoundingBox GEdge::getOBB()
{
  if (!_obb) {
    std::vector<SPoint3> vertices;
    if(getNumMeshVertices() > 0) {
      int N = getNumMeshVertices();
      for (int i = 0; i < N; i++) {
        MVertex* mv = getMeshVertex(i);
        vertices.push_back(mv->point());
      }
      // Don't forget to add the first and last vertices...
      SPoint3 pt1(getBeginVertex()->x(), getBeginVertex()->y(), getBeginVertex()->z());
      SPoint3 pt2(getEndVertex()->x(), getEndVertex()->y(), getEndVertex()->z());
      vertices.push_back(pt1);
      vertices.push_back(pt2);
    } 
    else if(geomType() != DiscreteCurve && geomType() != BoundaryLayerCurve){
      Range<double> tr = this->parBounds(0);
      // N can be choosen arbitrarily, but 10 points seems reasonable
      int N = 10;
      for (int i = 0; i < N; i++) {
        double t = tr.low() + (double)i / (double)(N - 1) * (tr.high() - tr.low());
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
    int N = minimumDrawSegments();
    for(int i = 1; i < N; i++){
      double u = umin + (double)i / N * (umax - umin);
      GPoint p = point(u);
      fprintf(fp, "Point(p%d + %d) = {%.16g, %.16g, %.16g};\n", 
              tag(), i, p.x(), p.y(), p.z());
    }
    fprintf(fp, "Spline(%d) = {%d", tag(), getBeginVertex()->tag());
    for(int i = 1; i < N; i++)
      fprintf(fp, ", p%d + %d", tag(), i);
    fprintf(fp, ", %d};\n", getEndVertex()->tag());
  }

  if(meshAttributes.Method == MESH_TRANSFINITE){
    fprintf(fp, "Transfinite Line {%d} = %d", 
            tag() * (meshAttributes.typeTransfinite > 0 ? 1 : -1),
            meshAttributes.nbPointsTransfinite);
    if(meshAttributes.typeTransfinite){
      if(std::abs(meshAttributes.typeTransfinite) == 1)
        fprintf(fp, " Using Progression ");
      else
        fprintf(fp, " Using Bump ");
      fprintf(fp, "%g", meshAttributes.coeffTransfinite);
    }
    fprintf(fp, ";\n");
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
  // reparametrize the point onto the given face.
  const GPoint p3 = point(epar);
  SPoint3 sp3(p3.x(), p3.y(), p3.z());
  return face->parFromPoint(sp3);
}

double GEdge::curvature(double par) const
{
  SVector3 d1 = firstDer(par);
  SVector3 d2 = secondDer(par);
  
  double one_over_norm = 1. / norm(d1);

  SVector3 cross_prod = crossprod(d1,d2);
  
  return ( norm(cross_prod) * one_over_norm * one_over_norm * one_over_norm );
}

double GEdge::length(const double &u0, const double &u1, const int nbQuadPoints)
{
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
}

/*
  consider a curve x(t) and a point y
  
  use a golden section algorithm that minimizes 

  min_t \|x(t)-y\|   

*/

const double GOLDEN  = (1. + sqrt(5)) / 2.;
const double GOLDEN2 = 2 - GOLDEN;
 
// x1 and x3 are the current bounds; the minimum is between them.
// x2 is the center point, which is closer to x1 than to x3

double goldenSectionSearch(const GEdge *ge, const SPoint3 &q, double x1, double x2, double x3, double tau)
{ 
  // Create a new possible center in the area between x2 and x3, closer to x2
  double x4 = x2 + GOLDEN2 * (x3 - x2);
  
  // Evaluate termination criterion
  if (fabs(x3 - x1) < tau * (fabs(x2) + fabs(x4)))
    return (x3 + x1) / 2;
  
  const SVector3 dp4 = q - ge->position(x4);
  const SVector3 dp2 = q - ge->position(x2);
  
  const double d4 = dp4.norm();
  const double d2 = dp2.norm();
  
  if (d4 < d2)
    return goldenSectionSearch(ge, q, x2, x4, x3, tau);
  else
    return goldenSectionSearch(ge,q , x4, x2, x1, tau);
}

GPoint GEdge::closestPoint(const SPoint3 &q, double &t) const
{

  //  printf("looking for closest point in curve %d to point %g %g\n",tag(),q.x(),q.y());
  
  const int nbSamples = 100;
  
  double tolerance = 1.e-12;

  Range<double> interval = parBounds(0);
  
  double tMin = std::min(interval.high(), interval.low());
  double tMax = std::max(interval.high(), interval.low());

  double DMIN = 1.e22;
  double topt;
  const double DT = (tMax-tMin)/(nbSamples-1) ;
  for (int i=0;i<nbSamples;i++){
    t = tMin + i * DT;
    const SVector3 dp = q - position(t);
    const double D = dp.norm();
    if (D < DMIN) {
      topt = t;
      DMIN = D;
    }
  }
  
  //  printf("parameter %g as an initial guess (dist = %g)\n",topt,DMIN);

  if (topt == tMin)
    t = goldenSectionSearch (this, q, topt, topt + DT/2, topt + DT,  1.e-7);
  else if (topt == tMax)
    t = goldenSectionSearch (this, q, topt - DT, topt - DT/2 , topt, 1.e-7);
  else
    t = goldenSectionSearch (this, q, topt - DT, topt, topt + DT, 1.e-7);

  const SVector3 dp = q - position(t);
  const double D = dp.norm();

  //  printf("after golden section parameter %g  (dist = %g)\n",t,D);
  
  return point(t);
}

double GEdge::parFromPoint(const SPoint3 &P) const
{
  double t;
  XYZToU(P.x(), P.y(), P.z(), t);
  return t;
}

bool GEdge::XYZToU(const double X, const double Y, const double Z, 
                   double &u, const double relax) const
{
  const int MaxIter = 25;
  const int NumInitGuess = 11;

  double err, err2;
  int iter;

  Range<double> uu = parBounds(0);
  double uMin = uu.low();
  double uMax = uu.high();

  SVector3 Q(X, Y, Z), P;
  
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
    //    Msg::Info("point %g %g %g on edge %d : Relaxation factor = %g", 
    //              Q.x(), Q.y(), Q.z(), 0.75 * relax);
    return XYZToU(Q.x(), Q.y(), Q.z(), u, 0.75 * relax);
  }
  
  //  Msg::Error("Could not converge reparametrisation of point (%e,%e,%e) on edge %d",
  //             Q.x(), Q.y(), Q.z(), tag());
  return false;
}

void GEdge::replaceEndingPoints (GVertex *replOfv0, GVertex *replOfv1)
{
  replaceEndingPointsInternals (replOfv0, replOfv1);
  if (replOfv0 != v0){
    v0->delEdge(this);
    replOfv0->addEdge(this);
    v0 = replOfv0;
  }
  if (replOfv1 != v1){
    v1->delEdge(this);
    replOfv1->addEdge(this);
    v1 = replOfv1;
  }  
}

