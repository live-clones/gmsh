// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier Baudoin

#include <queue>
#include <cmath>
#include "GmshConfig.h"
#include "Context.h"
#include "surfaceFiller.h"
#include "Field.h"
#include "GModel.h"
#include "OS.h"
#include "rtree.h"
#include "MVertex.h"
#include "MElement.h"
#include "MLine.h"
#include "BackgroundMesh.h"

static bool inParametricDomain(GFace *gf, const SPoint2 &p)
{
  if(gf->getNativeType() == GEntity::GmshModel) {
    // The generic GFace::containsParam() only checks the rectangular UV
    // bounds. For built-in plane surfaces this includes holes and the parts of
    // the bounding rectangle outside trimmed loops, where PACK can otherwise
    // propagate indefinitely and sample unrelated values from a background
    // size field. gmshFace::containsPoint() performs the actual loop test.
    if(gf->geomType() == GEntity::Plane) {
      GPoint gp = gf->point(p);
      if(!gp.succeeded()) return false;
      return gf->containsPoint(SPoint3(gp.x(), gp.y(), gp.z()));
    }
    return true;
  }
  return gf->containsParam(p);
}

// Keep the historical packing clearance in each local cross-field direction.
// The oriented exclusion cube has half-width 0.7 h.
static const double exclusionCubeFactor3D = 0.7;

class surfacePointWithExclusionCube3D {
public:
  MVertex *_v;
  MVertex *_father;
  SPoint2 _uv;
  SVector3 _t1;
  SVector3 _t2;
  SVector3 _normal;
  double _size;
  SMetric3 _meshMetric;

  surfacePointWithExclusionCube3D(
    MVertex *v, const SPoint2 &uv, const SVector3 &t1,
    const SVector3 &t2, const SVector3 &normal, double size,
    const SMetric3 &meshMetric,
    surfacePointWithExclusionCube3D *father = nullptr)
    : _v(v), _father(father ? father->_v : nullptr), _uv(uv), _t1(t1),
      _t2(t2), _normal(normal), _size(size), _meshMetric(meshMetric)
  {
  }

  void minmax(double minimum[3], double maximum[3]) const
  {
    // The oriented cube is contained in this axis-aligned cube. Keeping the
    // exact region in the callback makes the R-tree conservative and cheap.
    const double radius = 1.73205081 * exclusionCubeFactor3D * _size;
    minimum[0] = _v->x() - radius;
    minimum[1] = _v->y() - radius;
    minimum[2] = _v->z() - radius;
    maximum[0] = _v->x() + radius;
    maximum[1] = _v->y() + radius;
    maximum[2] = _v->z() + radius;
  }

  bool contains(const SPoint3 &point, MVertex *parent) const
  {
    if(_father == parent) return false;
    const SVector3 delta = point - _v->point();
    const double halfWidth = exclusionCubeFactor3D * _size;
    return std::abs(dot(delta, _t1)) < halfWidth &&
           std::abs(dot(delta, _t2)) < halfWidth &&
           std::abs(dot(delta, _normal)) < halfWidth;
  }
};

class surfaceCubeQuery3D {
public:
  SPoint3 point;
  MVertex *parent;
  bool tooClose;

  surfaceCubeQuery3D(const SPoint3 &point_, MVertex *parent_)
    : point(point_), parent(parent_), tooClose(false)
  {
  }
};

static bool surfaceCubeCallback3D(surfacePointWithExclusionCube3D *neighbour,
                                  void *context)
{
  surfaceCubeQuery3D *query =
    static_cast<surfaceCubeQuery3D *>(context);
  if(neighbour->contains(query->point, query->parent)) {
    query->tooClose = true;
    return false;
  }
  return true;
}

static bool inExclusionCube3D(
  MVertex *parent, const SPoint3 &point,
  RTree<surfacePointWithExclusionCube3D *, double, 3, double> &rtree)
{
  surfaceCubeQuery3D query(point, parent);
  double minimum[3] = {point.x(), point.y(), point.z()};
  double maximum[3] = {point.x(), point.y(), point.z()};
  rtree.Search(minimum, maximum, surfaceCubeCallback3D, &query);
  return query.tooClose;
}

static surfacePointWithExclusionCube3D *makeSurfaceCubePoint3D(
  GFace *gf, MVertex *vertex, Field *crossField, double multiplier,
  surfacePointWithExclusionCube3D *father = nullptr)
{
  SPoint2 uv;
  reparamMeshVertexOnFace(vertex, gf, uv);

  SVector3 t1;
  (*crossField)(vertex->x(), vertex->y(), vertex->z(), t1, gf);
  const double size = multiplier * t1.norm();
  if(!(size > 0.0) || !std::isfinite(size) || size > 1.e10)
    return nullptr;

  const std::pair<SVector3, SVector3> derivatives = gf->firstDer(uv);
  SVector3 normal = crossprod(derivatives.first, derivatives.second);
  if(!(normal.norm() > 0.0)) return nullptr;
  normal.normalize();
  t1 -= normal * dot(t1, normal);
  if(!(t1.norm() > 0.0)) return nullptr;
  t1.normalize();
  SVector3 t2 = crossprod(normal, t1);
  if(!(t2.norm() > 0.0)) return nullptr;
  t2.normalize();

  const SMetric3 metric(1.0 / (size * size));
  return new surfacePointWithExclusionCube3D(
    vertex, uv, t1, t2, normal, size, metric, father);
}

static MFaceVertex *projectSurfaceCandidate3D(
  GFace *gf, const surfacePointWithExclusionCube3D *parent,
  const SVector3 &direction)
{
  const SPoint3 center = parent->_v->point();
  const SPoint3 target = center + direction * parent->_size;
  const double initialGuess[2] = {parent->_uv.x(), parent->_uv.y()};
  const GPoint projected =
    gf->closestPointFromTrustedGuess(target, initialGuess);
  if(!projected.succeeded()) return nullptr;

  const SPoint2 uv(projected.u(), projected.v());
  const SPoint3 point(projected.x(), projected.y(), projected.z());
  const SVector3 displacement = point - center;
  const double length = displacement.norm();
  if(!(length > 0.25 * parent->_size) ||
     length > 1.75 * parent->_size)
    return nullptr;
  if(dot(displacement, direction) <= 0.25 * length) return nullptr;

  return new MFaceVertex(point.x(), point.y(), point.z(), gf, uv.x(), uv.y());
}

static void packingOfOrientedCubes3D(GFace *gf,
                                     std::vector<MVertex *> &packed,
                                     std::vector<SMetric3> &metrics)
{
  FieldManager *fields = gf->model()->getFields();
  if(fields->getBackgroundField() <= 0) {
    Msg::Error("3D surface packing requires a scaled cross field");
    return;
  }
  Field *crossField = fields->get(fields->getBackgroundField());
  if(!crossField || crossField->numComponents() != 3) {
    Msg::Error("3D surface packing requires a three-component scaled cross "
               "field");
    return;
  }

  std::set<MVertex *, MVertexPtrLessThan> boundaryVertices;
  for(unsigned int i = 0; i < gf->getNumMeshElements(); ++i) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); ++j) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() < 2) boundaryVertices.insert(vertex);
    }
  }

  std::queue<surfacePointWithExclusionCube3D *> fifo;
  std::vector<surfacePointWithExclusionCube3D *> points;
  RTree<surfacePointWithExclusionCube3D *, double, 3, double> rtree;
  const double globalMultiplier = 1.0;
  for(MVertex *vertex : boundaryVertices) {
    surfacePointWithExclusionCube3D *point = makeSurfaceCubePoint3D(
      gf, vertex, crossField, globalMultiplier);
    if(!point) continue;
    points.push_back(point);
    fifo.push(point);
    double minimum[3], maximum[3];
    point->minmax(minimum, maximum);
    rtree.Insert(minimum, maximum, point);
  }

  while(!fifo.empty()) {
    surfacePointWithExclusionCube3D *parent = fifo.front();
    fifo.pop();
    const SVector3 directions[4] = {parent->_t1 * -1.0,
                                    parent->_t2 * -1.0,
                                    parent->_t1,
                                    parent->_t2};
    for(const SVector3 &direction : directions) {
      MFaceVertex *candidate =
        projectSurfaceCandidate3D(gf, parent, direction);
      if(!candidate) continue;
      const SPoint3 candidatePoint = candidate->point();
      if(inExclusionCube3D(parent->_v, candidatePoint, rtree)) {
        delete candidate;
        continue;
      }
      double u = 0., v = 0.;
      if(!candidate->getParameter(0, u) ||
         !candidate->getParameter(1, v) ||
         !inParametricDomain(gf, SPoint2(u, v))) {
        delete candidate;
        continue;
      }
      surfacePointWithExclusionCube3D *point = makeSurfaceCubePoint3D(
        gf, candidate, crossField, globalMultiplier, parent);
      if(!point) {
        delete candidate;
        continue;
      }
      points.push_back(point);
      fifo.push(point);
      double minimum[3], maximum[3];
      point->minmax(minimum, maximum);
      rtree.Insert(minimum, maximum, point);
    }
  }

  FILE *debug = nullptr;
  if(CTX::instance()->mesh.saveDebugFiles) {
    char filename[256];
    sprintf(filename, "points3d%d.pos", gf->tag());
    debug = Fopen(filename, "w");
    if(debug) fprintf(debug, "View \"3D packed points\"{\n");
  }
  for(surfacePointWithExclusionCube3D *point : points) {
    if(debug)
      fprintf(debug, "SP(%g,%g,%g){1};\n", point->_v->x(), point->_v->y(),
              point->_v->z());
    if(point->_v->onWhat() == gf) {
      packed.push_back(point->_v);
      metrics.push_back(point->_meshMetric);
    }
    delete point;
  }
  if(debug) {
    fprintf(debug, "};\n");
    fclose(debug);
  }
  Msg::Info("3D oriented-cube packing created %zu points on face %d",
            packed.size(), gf->tag());
}


void packingOfParallelograms(GFace *gf, std::vector<MVertex *> &packed,
                            std::vector<SMetric3> &metrics)
{
  // PACK has one placement/exclusion algorithm, in physical space.
  packingOfOrientedCubes3D(gf, packed, metrics);
}
