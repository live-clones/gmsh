// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <list>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "fourierVertex.h"
#include "fourierFace.h"

#if defined(HAVE_FOURIER_MODEL)

fourierFace::fourierFace(GModel *m, FM::TopoFace *face_, int tag,
                         std::list<GEdge*> l_edges_)
  : GFace(m,tag), face(face_)
{
  for (std::list<GEdge*>::iterator it = l_edges_.begin();
       it != l_edges_.end(); it++) {
    l_edges.push_back((*it));
    l_dirs.push_back(1);   
  }
  buildSTLTriangulation();
}

Range<double> fourierFace::parBounds(int i) const
{
  return Range<double>(0.,1.);
}

GPoint fourierFace::point(double par1, double par2) const
{
  double pp[2] = {par1,par2};
  double x,y,z;
  face->F(par1,par2,x,y,z);
  return GPoint(x, y, z, this, pp);
}

SPoint2 fourierFace::parFromPoint(const SPoint3 &p) const
{
  double u, v, x, y, z;
  x = p.x(); y = p.y(); z = p.z();
  face->Inverse(x,y,z,u,v);

  return SPoint2(u, v);
}

bool fourierFace::containsParam(const SPoint2 &pt) const
{
  const double tol = 1.e-6;
  if(pt[0] < 0. - tol || pt[0] > 1. + tol) return false;
  if(pt[1] < 0. - tol || pt[1] > 1. + tol) return false;
  return true;
}

SVector3 fourierFace::normal(const SPoint2 &param) const
{
  double x,y,z;
  face->GetUnitNormal(param[0],param[1],x,y,z);
  return SVector3(x, y, z); 
}

GEntity::GeomType fourierFace::geomType() const
{
  return  GEntity::ParametricSurface;
}

Pair<SVector3, SVector3> fourierFace::firstDer(const SPoint2 &param) const
{
  Msg::Error("First derivative not implemented for fourier face");
  return Pair<SVector3, SVector3>();
}

void fourierFace::secondDer(const SPoint2 &param, 
                            SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  Msg::Error("Computation of the second derivatives not implemented for fourier face");
}

#endif
