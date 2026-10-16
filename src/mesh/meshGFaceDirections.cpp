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
#include "GModel.h"
#include "Field.h"
#include "discreteFace.h"
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

// The directions and the size at a node from the scaled cross field that
// guided the surface mesh (PACK, QuadQS), as its 3D packing reads them: the
// field vector projected on the tangent plane, its normal rotation, its norm
static bool guidedDirections(GFace *gf, Field *crossField, MVertex *vertex,
                             SVector3 &v1, SVector3 &v2, double &size)
{
  SPoint2 uv;
  reparamMeshVertexOnFace(vertex, gf, uv);
  (*crossField)(vertex->x(), vertex->y(), vertex->z(), v1, gf);
  size = v1.norm();
  if(!(size > 0.) || !std::isfinite(size) || size > 1.e10) return false;
  SVector3 normal;
  if(gf->geomType() == GEntity::DiscreteSurface) {
    const double guess[2] = {uv.x(), uv.y()};
    if(!static_cast<discreteFace *>(gf)
          ->closestPoint(vertex->point(), guess, &normal)
          .succeeded())
      return false;
  }
  else {
    const std::pair<SVector3, SVector3> der = gf->firstDer(uv);
    normal = crossprod(der.first, der.second);
  }
  if(!(normal.norm() > 0.) || !std::isfinite(normal.norm())) return false;
  normal.normalize();
  v1 -= normal * dot(v1, normal);
  if(!(v1.norm() > 0.)) return false;
  v1.normalize();
  v2 = crossprod(v1, normal);
  if(!(v2.norm() > 0.)) return false;
  v2.normalize();
  return true;
}

void directions_storage(GFace *gf)
{
  // ordered by node number, not by address: the loop below fills
  // gf->storage1..4 in this order
  std::set<MVertex *, MVertexPtrLessThan> vertices;
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      vertices.insert(vertex);
    }
  }

  // the cross field that guided the mesh, if any: much cheaper than the
  // background mesh below (a cross field propagated by two linear solves on
  // the surface mesh and located node by node), and the directions of the
  // surface mesh itself
  if(Field *crossField = gf->model()->getFields()->getDirectionField()) {
    if(crossField->numComponents() == 3) {
      std::vector<SPoint3> s1;
      std::vector<SVector3> s2, s3;
      std::vector<double> s4;
      s1.reserve(vertices.size());
      s2.reserve(vertices.size());
      s3.reserve(vertices.size());
      s4.reserve(vertices.size());
      bool ok = true;
      for(MVertex *v : vertices) {
        SVector3 v1, v2;
        double size;
        if(!guidedDirections(gf, crossField, v, v1, v2, size)) {
          ok = false;
          break;
        }
        s1.push_back(v->point());
        s2.push_back(v1);
        s3.push_back(v2);
        s4.push_back(size);
      }
      if(ok) {
        gf->storage1.swap(s1);
        gf->storage2.swap(s2);
        gf->storage3.swap(s3);
        gf->storage4.swap(s4);
        return;
      }
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