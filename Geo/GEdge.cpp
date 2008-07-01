// $Id: GEdge.cpp,v 1.50 2008-07-01 14:24:07 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <algorithm>
#include "GModel.h"
#include "GEdge.h"
#include "GFace.h"
#include "MElement.h"
#include "GmshDefines.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Message.h"
#  include "GaussLegendre1D.h"
#endif

GEdge::GEdge(GModel *model, int tag, GVertex *_v0, GVertex *_v1)
  : GEntity(model, tag), v0(_v0), v1(_v1)
{
  if(v0) v0->addEdge(this);
  if(v1 && v1 != v0) v1->addEdge(this);
  resetMeshAttributes();
}

GEdge::~GEdge()
{
  if(v0) v0->delEdge(this);
  if(v1 && v1 != v0) v1->delEdge(this);

  for(unsigned int i = 0; i < mesh_vertices.size(); i++)
    delete mesh_vertices[i];

  for(unsigned int i = 0; i < lines.size(); i++)
    delete lines[i];
}

unsigned int GEdge::getNumMeshElements()
{ 
  return lines.size();
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
  meshAttributes.meshSize = 1.e22;
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

void GEdge::recomputeMeshPartitions()
{
  for(unsigned int i = 0; i < lines.size(); i++) {
    int part = lines[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
}

void GEdge::deleteMeshPartitions()
{
  for(unsigned int i = 0; i < lines.size(); i++)
    lines[i]->setPartition(0);
}

std::string GEdge::getAdditionalInfoString()
{
  if(!v0 || !v1) return std::string("");
  char tmp[256];
  sprintf(tmp, "{%d,%d}", v0->tag(), v1->tag());
  return std::string(tmp);
}

GPoint GEdge::closestPoint(const SPoint3 & queryPoint) const
{
  Msg::Error("Closet point not implemented for this type of edge");
  return GPoint(0, 0, 0);
}

int GEdge::containsParam(double pt) const
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

SPoint2 GEdge::reparamOnFace(GFace *face, double epar,int dir) const
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

