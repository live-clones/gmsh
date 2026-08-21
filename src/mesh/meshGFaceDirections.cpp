// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include <cmath>
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "Numeric.h"
#include "BackgroundMesh.h"
#include "meshGFaceDirections.h"

static bool improved_translate(GFace *gf, MVertex *vertex, SVector3 &v1,
                               SVector3 &v2)
{
  double x, y;
  double angle;
  SPoint2 point;
  SVector3 s1, s2;
  SVector3 normal;
  SVector3 basis_u, basis_v;
  std::pair<SVector3, SVector3> derivatives;

  reparamMeshVertexOnFace(vertex, gf, point);
  x = point.x();
  y = point.y();

  angle = backgroundMesh::current()->getAngle(x, y, 0.0);
  derivatives = gf->firstDer(point);

  s1 = derivatives.first;
  s2 = derivatives.second;
  normal = crossprod(s1, s2);

  basis_u = s1;
  basis_u.normalize();
  basis_v = crossprod(normal, basis_u);
  basis_v.normalize();

  v1 = basis_u * cos(angle) + basis_v * sin(angle);
  v2 = crossprod(v1, normal);
  v2.normalize();

  return 1;
}

void directions_storage(GFace *gf)
{
  std::set<MVertex *> vertices;
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      vertices.insert(vertex);
    }
  }

  backgroundMesh::set(gf);

  gf->storage1.clear();
  gf->storage2.clear();
  gf->storage3.clear();
  gf->storage4.clear();

  for(auto it = vertices.begin(); it != vertices.end(); it++) {
    SPoint2 point;
    SVector3 v1;
    SVector3 v2;
    bool ok = improved_translate(gf, *it, v1, v2);
    if(ok) {
      gf->storage1.push_back(SPoint3((*it)->x(), (*it)->y(), (*it)->z()));
      gf->storage2.push_back(v1);
      gf->storage3.push_back(v2);
      reparamMeshVertexOnFace(*it, gf, point);
      gf->storage4.push_back(
        backgroundMesh::current()->operator()(point.x(), point.y(), 0.0));
    }
  }

  backgroundMesh::unset();
}