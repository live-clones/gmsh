// $Id: GEdge.cpp,v 1.16 2006-10-12 01:35:32 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "GmshDefines.h"

GEdge::GEdge(GModel *model, int tag, GVertex *_v0, GVertex *_v1)
  : GEntity(model, tag), v0(_v0), v1(_v1)
{
  if(v0) v0->addEdge(this);
  if(v1) v1->addEdge(this);

  meshAttributes.Method = LIBRE; 
  meshAttributes.coeffTransfinite = 0.;
  meshAttributes.nbPointsTransfinite = 0;
  meshAttributes.typeTransfinite = 0;
  meshAttributes.extrude = 0;
}

GEdge::~GEdge() 
{
  if(v0) v0->delEdge(this);
  if(v1) v1->delEdge(this);

  for(unsigned int i = 0; i < mesh_vertices.size(); i++) 
    delete mesh_vertices[i];
  mesh_vertices.clear();

  for(unsigned int i = 0; i < lines.size(); i++) 
    delete lines[i];
  lines.clear();
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
  Range<double> tr = parBounds(0);
  SBoundingBox3d bbox;
  if(geomType() != DiscreteCurve){
    const int N = 10;
    for(int i = 0; i < N; i++){
      double t = tr.low() + (double)i/(double)(N - 1) * (tr.high() - tr.low());
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

SVector3 GEdge::secondDer(double par) const 
{
  // use central differences
  const double eps = 1.e-3;
  SVector3 x1 = firstDer(par-eps);
  SVector3 x2 = firstDer(par+eps);
  return 500*(x2-x1);
}
