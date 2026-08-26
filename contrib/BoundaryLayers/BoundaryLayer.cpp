// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <set>
#include <map>
#include <array>
#include <cstdio>
#include <unordered_map>
#include "GModel.h"
#include "GRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "meshGEdge.h"
#include "BoundaryLayer.h"
#include "Context.h"
#include "OS.h"

#include "highOrderBoundaryLayerUntangler.h"
#include "meanPlaneSurfaceUntangler.h"
#include "winslowParametric.h"
#include "winslowUntanglerGMSH.h"

StringXNumber BoundaryLayerOptions_Number[] = {
  {GMSH_FULLRC, "Thickness", nullptr, 1.e-2},
  {GMSH_FULLRC, "Size", nullptr, 1.e-3},
  {GMSH_FULLRC, "Ratio", nullptr, 1.2},
  {GMSH_FULLRC, "SmoothingLayers", nullptr, 2.},
  {GMSH_FULLRC, "NumExactLayers", nullptr, -2.},
  {GMSH_FULLRC, "HighOrder", nullptr, 1.},
  {GMSH_FULLRC, "HighOrderStrategy", nullptr, 2.},
  {GMSH_FULLRC, "HighOrderPostSplitUntangle", nullptr, 0.},
  {GMSH_FULLRC, "HighOrderPostSplitSurfaceUntangle", nullptr, 0.},
  {GMSH_FULLRC, "SurfaceUntangler", nullptr, 1.},
  {GMSH_FULLRC, "MeanPlaneTolerance", nullptr, 5.e-2},
  {GMSH_FULLRC, "MeanPlaneExtensionTolerance", nullptr, 1.e-3},
  {GMSH_FULLRC, "MeanPlanePatchRings", nullptr, 2.},
  {GMSH_FULLRC, "MeanPlaneSweeps", nullptr, 100.},
  {GMSH_FULLRC, "MeanPlaneMoveTolerance", nullptr, 1.e-4},
  {GMSH_FULLRC, "MeanPlaneDebugPatches", nullptr, 0.},
  {GMSH_FULLRC, "ParametricQuadraturePoints", nullptr, 3.}};

StringXString BoundaryLayerOptions_String[] = {
  {GMSH_FULLRC, "Volumes", nullptr, ""},
  {GMSH_FULLRC, "Surfaces", nullptr, ""},
  {GMSH_FULLRC, "Curves", nullptr, ""},
  {GMSH_FULLRC, "Points", nullptr, ""},
  {GMSH_FULLRC, "IntersectPoints", nullptr, ""},
  {GMSH_FULLRC, "IntersectEdges", nullptr, ""},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin()
{
  return new GMSH_BoundaryLayerPlugin();
}
}

std::string GMSH_BoundaryLayerPlugin::getHelp() const
{
  return "Plugin(BoundaryLayer) performs magic.";
}

int GMSH_BoundaryLayerPlugin::getNbOptions() const
{
  return sizeof(BoundaryLayerOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_BoundaryLayerPlugin::getOption(int iopt)
{
  return &BoundaryLayerOptions_Number[iopt];
}

int GMSH_BoundaryLayerPlugin::getNbOptionsStr() const
{
  return sizeof(BoundaryLayerOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_BoundaryLayerPlugin::getOptionStr(int iopt)
{
  return &BoundaryLayerOptions_String[iopt];
}

static double triangle_area_2d(std::array<double, 2> a, std::array<double, 2> b,
                               std::array<double, 2> c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

inline double dot(const std::array<double, 3> &u,
                  const std::array<double, 3> &v)
{
  return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

static inline std::array<double, 3>
sub3(const std::array<double, 3> &u, const std::array<double, 3> &v)
{
  return {u[0] - v[0], u[1] - v[1], u[2] - v[2]};
}

static inline std::array<double, 3>
cross3(const std::array<double, 3> &u, const std::array<double, 3> &v)
{
  return {u[1] * v[2] - u[2] * v[1],
          u[2] * v[0] - u[0] * v[2],
          u[0] * v[1] - u[1] * v[0]};
}

static inline double tetVolume3(const std::array<double, 3> &a,
                                const std::array<double, 3> &b,
                                const std::array<double, 3> &c,
                                const std::array<double, 3> &d)
{
  return dot(sub3(a, d), cross3(sub3(b, d), sub3(c, d))) / 6.;
}

/*
    nodes at start (s) and end (e) of GEdge ge
    that does NOT belong tho the list of BL edges
    but is connected to a BL edge (vertical)

    Vertex a is inserted after s
    Vertex b is (possibly) inserted before e

    |
    |
    s--a---x(t(0))---x(t(1))--...--x(t(n-2))-----x(t(n-1))---e
*/

const int _debugBL3D = 0;

struct BoundaryLayerCornerQuad {
  GVertex *gv = nullptr;
  GFace *gf = nullptr;
  GEdge *edgeA = nullptr;
  GEdge *edgeB = nullptr;
  MVertex *p = nullptr;
  MVertex *a = nullptr;
  MVertex *s = nullptr;
  MVertex *b = nullptr;
};

struct BoundaryLayerIntersectEdgeHex {
  GEdge *ge = nullptr;
  GFace *faceA = nullptr;
  GFace *faceB = nullptr;
  GRegion *gr = nullptr;
  MVertex *p0 = nullptr;
  MVertex *p1 = nullptr;
  MVertex *a0 = nullptr;
  MVertex *a1 = nullptr;
  MVertex *s0 = nullptr;
  MVertex *s1 = nullptr;
  MVertex *b0 = nullptr;
  MVertex *b1 = nullptr;
};

struct BoundaryLayerIntersectCornerHex {
  GVertex *gv = nullptr;
  GRegion *gr = nullptr;
  GEdge *edge0 = nullptr;
  GEdge *edge1 = nullptr;
  GEdge *edge2 = nullptr;
  GFace *face01 = nullptr;
  GFace *face02 = nullptr;
  GFace *face12 = nullptr;
  MVertex *p = nullptr;
  MVertex *a = nullptr;
  MVertex *b = nullptr;
  MVertex *c = nullptr;
  MVertex *sab = nullptr;
  MVertex *sac = nullptr;
  MVertex *sbc = nullptr;
  MVertex *r = nullptr;
};

static void getEmbeddedStructure(GModel *m,
                                 std::map<GVertex *, std::vector<GFace *>> &v2f,
                                 std::map<GEdge *, std::vector<GFace *>> &e2f,
                                 std::map<GEdge *, std::vector<GRegion *>> &e2r,
                                 std::map<GFace *, std::vector<GRegion *>> &f2r)
{
  for(GModel::fiter fit = m->firstFace(); fit != m->lastFace(); ++fit) {
    auto ee = (*fit)->embeddedEdges();
    for(auto ge : ee) {
      if(_debugBL3D)
        printf(" --EMP  getEmbeddedStructure: Edge %d embedded in Face %d\n",
               ge->tag(), (*fit)->tag());
      v2f[ge->getBeginVertex()].push_back(*fit);
      v2f[ge->getEndVertex()].push_back(*fit);
      e2f[ge].push_back(*fit);
      if(_debugBL3D)
        printf(" --EMP  getEmbeddedStructure: endpoints %d/%d embedded in "
               "Face %d\n",
               ge->getBeginVertex()->tag(), ge->getEndVertex()->tag(),
               (*fit)->tag());
    }
  }
  for(GModel::riter rit = m->firstRegion(); rit != m->lastRegion(); ++rit) {
    auto ef = (*rit)->embeddedFaces();
    for(auto gf : ef) {
      if(_debugBL3D)
        printf(" --EMP  getEmbeddedStructure: Face %d embedded in Region %d\n",
               gf->tag(), (*rit)->tag());
      f2r[gf].push_back(*rit);
      auto ee = (gf)->embeddedEdges();
      for(auto ge : ee) {
        if(e2f.find(ge) == e2f.end()) {
          if(_debugBL3D)
            printf(" --EMP  getEmbeddedStructure: embedded Edge %d from Face "
                   "%d embedded in Region %d\n",
                   ge->tag(), gf->tag(), (*rit)->tag());
          e2r[ge].push_back(*rit);
        }
      }
      auto e = (gf)->edges();
      for(auto ge : e) {
        if(e2f.find(ge) == e2f.end()) {
          if(_debugBL3D)
            printf(" --EMP  getEmbeddedStructure: boundary Edge %d of Face %d "
                   "embedded in Region %d\n",
                   ge->tag(), gf->tag(), (*rit)->tag());
          e2r[ge].push_back(*rit);
        }
      }
    }
  }
  if(_debugBL3D)
    printf(" --EMP  getEmbeddedStructure: summary %zu vertices-in-faces, %zu "
           "edges-in-faces, %zu edges-in-regions, %zu faces-in-regions\n",
           v2f.size(), e2f.size(), e2r.size(), f2r.size());
}

namespace {

  // side[0] and side[1] store the elements adjacent to an embedded mesh vertex
  // with matching and opposite local orientation, respectively.
  struct EmbeddedElementSides {
    std::vector<MElement *> side[2];
  };

  struct EmbeddedElementSideData {
    std::map<std::pair<GEdge *, GFace *>,
             std::map<MVertex *, EmbeddedElementSides>>
      curvesInFaces;
    std::map<std::pair<GFace *, GRegion *>,
             std::map<MVertex *, EmbeddedElementSides>>
      facesInRegions;
  };

  struct EmbeddedVertexSpawns {
    MVertex *side[2] = {nullptr, nullptr};
  };

  struct EmbeddedCurveFaceSpawns {
    std::map<std::pair<GEdge *, GFace *>,
             std::map<MVertex *, EmbeddedVertexSpawns>>
      curvesInFaces;
    std::map<std::pair<GFace *, GRegion *>,
             std::map<MVertex *, EmbeddedVertexSpawns>>
      facesInRegions;
  };

  static void addEmbeddedSideElement(EmbeddedElementSides &sides, int side,
                                     MElement *element)
  {
    std::vector<MElement *> &elements = sides.side[side];
    if(std::find(elements.begin(), elements.end(), element) == elements.end())
      elements.push_back(element);
  }

  static void
  addEmbeddedSideElement(std::map<MVertex *, EmbeddedElementSides> &vertexSides,
                         MVertex *vertex, int side, MElement *element)
  {
    addEmbeddedSideElement(vertexSides[vertex], side, element);
  }

  static bool vectorContainsElement(const std::vector<MElement *> &elements,
                                    MElement *element)
  {
    return std::find(elements.begin(), elements.end(), element) !=
           elements.end();
  }

  static bool embeddedSidesContainElement(const EmbeddedElementSides &sides,
                                          MElement *element)
  {
    return vectorContainsElement(sides.side[0], element) ||
           vectorContainsElement(sides.side[1], element);
  }

  static bool elementHasVertex(MElement *element, MVertex *vertex)
  {
    for(std::size_t i = 0; i < element->getNumVertices(); i++)
      if(element->getVertex(i) == vertex) return true;
    return false;
  }

  static double elementSideInFace(GFace *gf, MLine *line, MElement *element)
  {
    SPoint2 p0, p1;
    if(!reparamMeshVertexOnFace(line->getVertex(0), gf, p0) ||
       !reparamMeshVertexOnFace(line->getVertex(1), gf, p1))
      return 0.;
    SPoint3 b = element->barycenter(true);
    SPoint2 pb = gf->parFromPoint(b, false);
    return (p1.x() - p0.x()) * (pb.y() - p0.y()) -
           (p1.y() - p0.y()) * (pb.x() - p0.x());
  }

  static bool
  classifyElementFromEmbeddedLine(GFace *gf, MLine *line,
                                  const EmbeddedElementSides &lineVertexSides,
                                  MElement *element, int &side)
  {
    for(int knownSide = 0; knownSide < 2; knownSide++) {
      if(lineVertexSides.side[knownSide].empty()) continue;
      double known =
        elementSideInFace(gf, line, lineVertexSides.side[knownSide][0]);
      double current = elementSideInFace(gf, line, element);
      if(std::abs(known) < 1.e-12 || std::abs(current) < 1.e-12) continue;
      side = (known * current > 0.) ? knownSide : 1 - knownSide;
      return true;
    }
    return false;
  }

  static MFaceVertex *createMFaceVertex(MVertex *v, GFace *gf)
  {
    SPoint2 param;
    if(!reparamMeshVertexOnFace(v, gf, param)) return nullptr;
    MFaceVertex *newv =
      new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
    gf->mesh_vertices.push_back(newv);
    return newv;
  }

  static MFaceVertex *createMFaceVertexAtPoint(const SPoint3 &p, GFace *gf)
  {
    if(!gf) return nullptr;
    SPoint2 guessParam = gf->parFromPoint(p, false);
    double guess[2] = {guessParam.x(), guessParam.y()};
    GPoint gp = gf->closestPoint(p, guess);
    MFaceVertex *newv =
      new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
    gf->mesh_vertices.push_back(newv);
    return newv;
  }

  static MVertex *findSpawnOnEntity(
    const std::map<MVertex *, std::vector<MVertex *>> &spawned, MVertex *v,
    GEntity *entity)
  {
    auto it = spawned.find(v);
    if(it == spawned.end()) return nullptr;
    for(auto sp : it->second)
      if(sp->onWhat() == entity) return sp;
    return nullptr;
  }

  static void pushUniqueSpawn(
    std::map<MVertex *, std::vector<MVertex *>> &spawned, MVertex *from,
    MVertex *to)
  {
    if(!from || !to) return;
    std::vector<MVertex *> &sp = spawned[from];
    if(std::find(sp.begin(), sp.end(), to) == sp.end()) sp.push_back(to);
  }

  static std::vector<GEdge *> boundaryLayerCurvesInFace(
    GVertex *gv, GFace *gf, const std::set<GEdge *> &onCurvesSet)
  {
    std::vector<GEdge *> result;
    if(!gv || !gf) return result;
    std::vector<GEdge *> faceEdges = gf->edges();
    for(auto ge : gv->edges()) {
      if(onCurvesSet.find(ge) == onCurvesSet.end()) continue;
      if(std::find(faceEdges.begin(), faceEdges.end(), ge) == faceEdges.end())
        continue;
      if(ge->getBeginVertex() == gv || ge->getEndVertex() == gv)
        result.push_back(ge);
    }
    return result;
  }

  static MVertex *insertCornerBoundaryLayerVertex(
    GVertex *gv, GEdge *ge, double distanceFromPoint,
    std::map<std::pair<GVertex *, GEdge *>, MVertex *> &inserted)
  {
    std::pair<GVertex *, GEdge *> key = std::make_pair(gv, ge);
    auto it = inserted.find(key);
    if(it != inserted.end()) return it->second;
    if(!gv || !ge || gv->mesh_vertices.empty() || ge->lines.empty()) return nullptr;

    MVertex *v = gv->mesh_vertices[0];
    bool atBegin = ge->getBeginVertex() == gv;
    bool atEnd = ge->getEndVertex() == gv;
    if(!atBegin && !atEnd) return nullptr;

    double param = 0.;
    if(!reparamMeshVertexOnEdge(v, ge, param)) {
      Msg::Warning("Could not compute parametric coordinates of point %d on "
                   "curve %d",
                   gv->tag(), ge->tag());
      return nullptr;
    }

    MVertex *next = nullptr;
    if(atBegin) {
      next = ge->lines.front()->getVertex(1);
      if(next == v && ge->lines.size() > 1)
        next = ge->lines[1]->getVertex(1);
    }
    else {
      next = ge->lines.back()->getVertex(0);
      if(next == v && ge->lines.size() > 1)
        next = ge->lines[ge->lines.size() - 2]->getVertex(0);
    }

    double newParam = param;
    double x = v->x(), y = v->y(), z = v->z();
    if(next && next != v) {
      double paramNext = param;
      bool haveParamNext = reparamMeshVertexOnEdge(next, ge, paramNext);
      double len = distance(v, next);
      double t = (len > 0. && distanceFromPoint > 0.) ?
                   std::min(distanceFromPoint / len, 0.5) :
                   0.5;
      if(haveParamNext) {
        newParam = param + t * (paramNext - param);
        GPoint gp = ge->point(newParam);
        x = gp.x();
        y = gp.y();
        z = gp.z();
      }
      else {
        x = (1. - t) * v->x() + t * next->x();
        y = (1. - t) * v->y() + t * next->y();
        z = (1. - t) * v->z() + t * next->z();
      }
    }

    double lc = 0.;
    if(!ge->mesh_vertices.empty()) {
      MEdgeVertex *ref = static_cast<MEdgeVertex *>(
        atEnd ? ge->mesh_vertices.back() : ge->mesh_vertices.front());
      lc = ref->getLc();
    }

    MVertex *newv =
      new MEdgeVertex(x, y, z, ge, newParam, 0, lc);
    if(atBegin) {
      ge->mesh_vertices.insert(ge->mesh_vertices.begin(), newv);
      ge->lines.front()->setVertex(0, newv);
      ge->lines.insert(ge->lines.begin(), new MLine(v, newv));
    }
    else {
      ge->mesh_vertices.push_back(newv);
      ge->lines.back()->setVertex(1, newv);
      ge->lines.push_back(new MLine(newv, v));
    }
    inserted[key] = newv;
    return newv;
  }

  static std::vector<GFace *> boundaryLayerFacesOnEdge(
    GEdge *ge, const std::set<GFace *> &onSurfacesSet)
  {
    std::vector<GFace *> result;
    if(!ge) return result;
    for(auto gf : ge->faces())
      if(onSurfacesSet.find(gf) != onSurfacesSet.end())
        result.push_back(gf);
    return result;
  }

  static std::vector<GRegion *> boundaryLayerVolumesOnEdgeFaces(
    GEdge *ge, GFace *faceA, GFace *faceB,
    const std::set<GRegion *> &inVolumesSet)
  {
    std::vector<GRegion *> result;
    if(!ge || !faceA || !faceB) return result;

    std::list<GRegion *> edgeRegions = ge->regions();
    for(auto gr : edgeRegions) {
      if(inVolumesSet.find(gr) == inVolumesSet.end()) continue;
      std::vector<GFace *> faces = gr->faces();
      if(std::find(faces.begin(), faces.end(), faceA) != faces.end() &&
         std::find(faces.begin(), faces.end(), faceB) != faces.end())
        result.push_back(gr);
    }

    if(result.empty()) {
      std::list<GRegion *> regionsA = faceA->regions();
      std::list<GRegion *> regionsB = faceB->regions();
      for(auto gr : regionsA) {
        if(inVolumesSet.find(gr) == inVolumesSet.end()) continue;
        if(std::find(regionsB.begin(), regionsB.end(), gr) != regionsB.end())
          result.push_back(gr);
      }
    }
    return result;
  }

  static bool edgeIsInRegion(GEdge *ge, GRegion *gr)
  {
    if(!ge || !gr) return false;
    std::list<GRegion *> edgeRegions = ge->regions();
    if(std::find(edgeRegions.begin(), edgeRegions.end(), gr) !=
       edgeRegions.end())
      return true;
    std::vector<GFace *> faces = gr->faces();
    for(auto gf : faces) {
      std::vector<GEdge *> edges = gf->edges();
      if(std::find(edges.begin(), edges.end(), ge) != edges.end())
        return true;
    }
    return false;
  }

  static GFace *boundaryLayerFaceOnEdgePair(
    GVertex *gv, GEdge *edgeA, GEdge *edgeB,
    const std::set<GFace *> &onSurfacesSet, GRegion *gr)
  {
    if(!gv || !edgeA || !edgeB) return nullptr;
    for(auto gf : gv->faces()) {
      if(onSurfacesSet.find(gf) == onSurfacesSet.end()) continue;
      if(gr) {
        std::list<GRegion *> regions = gf->regions();
        if(std::find(regions.begin(), regions.end(), gr) == regions.end())
          continue;
      }
      std::vector<GEdge *> edges = gf->edges();
      if(std::find(edges.begin(), edges.end(), edgeA) != edges.end() &&
         std::find(edges.begin(), edges.end(), edgeB) != edges.end())
        return gf;
    }
    return nullptr;
  }

  static MVertex *getOrCreateFaceSpawn(
    MVertex *v, GFace *gf,
    std::map<std::pair<GFace *, MVertex *>, MVertex *> &faceSpawns)
  {
    auto key = std::make_pair(gf, v);
    auto it = faceSpawns.find(key);
    if(it != faceSpawns.end()) return it->second;
    MVertex *newv = createMFaceVertex(v, gf);
    if(!newv && v)
      newv = createMFaceVertexAtPoint(SPoint3(v->x(), v->y(), v->z()), gf);
    if(newv) faceSpawns[key] = newv;
    return newv;
  }

  static MVertex *createMRegionVertex(MVertex *v, GRegion *gr);

  static MVertex *getOrCreateRegionSpawn(
    MVertex *v, GRegion *gr,
    std::map<std::pair<GRegion *, MVertex *>, MVertex *> &regionSpawns,
    std::map<MVertex *, std::vector<MVertex *>> *spawned = nullptr)
  {
    auto key = std::make_pair(gr, v);
    auto it = regionSpawns.find(key);
    if(it != regionSpawns.end()) return it->second;
    if(spawned) {
      MVertex *existing = findSpawnOnEntity(*spawned, v, gr);
      if(existing) {
        regionSpawns[key] = existing;
        return existing;
      }
    }
    MVertex *newv = createMRegionVertex(v, gr);
    regionSpawns[key] = newv;
    if(spawned) pushUniqueSpawn(*spawned, v, newv);
    return newv;
  }

  static MVertex *getOrCreateIntersectEdgeRegionSpawn(
    MVertex *v, GRegion *gr, GEdge *ge,
    std::map<std::pair<std::pair<GRegion *, GEdge *>, MVertex *>, MVertex *>
      &regionSpawns)
  {
    auto key = std::make_pair(std::make_pair(gr, ge), v);
    auto it = regionSpawns.find(key);
    if(it != regionSpawns.end()) return it->second;
    MVertex *newv = createMRegionVertex(v, gr);
    regionSpawns[key] = newv;
    return newv;
  }

  static void replaceFaceElementsAlongIntersectEdge(
    GFace *gf, GEdge *ge,
    const std::map<std::pair<GFace *, MVertex *>, MVertex *> &faceSpawns,
    const std::set<MEdge, MEdgeLessThan> *skipLines = nullptr,
    const std::map<MVertex *, MVertex *> *cornerOrigins = nullptr,
    const std::set<MElement *, MElementPtrLessThan> *skipElements = nullptr)
  {
    if(!gf || !ge) return;
    std::size_t numElements = gf->getNumMeshElements();
    for(std::size_t i = 0; i < numElements; ++i) {
      MElement *element = gf->getMeshElement(i);
      if(element->getDim() != 2) continue;
      if(skipElements && skipElements->find(element) != skipElements->end())
        continue;
      for(auto line : ge->lines) {
        MVertex *oldv0 = line->getVertex(0);
        MVertex *oldv1 = line->getVertex(1);
        if(skipLines && skipLines->find(MEdge(oldv0, oldv1)) !=
                          skipLines->end())
          continue;
        MVertex *origin0 = nullptr;
        MVertex *origin1 = nullptr;
        if(cornerOrigins) {
          auto ito0 = cornerOrigins->find(oldv0);
          auto ito1 = cornerOrigins->find(oldv1);
          if(ito0 != cornerOrigins->end()) origin0 = ito0->second;
          if(ito1 != cornerOrigins->end()) origin1 = ito1->second;
        }
        auto it0 = faceSpawns.find(std::make_pair(gf, oldv0));
        auto it1 = faceSpawns.find(std::make_pair(gf, oldv1));
        MVertex *newv0 = it0 == faceSpawns.end() ? nullptr : it0->second;
        MVertex *newv1 = it1 == faceSpawns.end() ? nullptr : it1->second;
        bool found = false;
        bool touches = false;
        for(int j = 0; j < element->getNumEdges(); ++j) {
          MEdge e = element->getEdge(j);
          MVertex *ev0 = e.getVertex(0);
          MVertex *ev1 = e.getVertex(1);
          bool ev0On0 = ev0 == oldv0 || ev0 == origin0 || ev0 == newv0;
          bool ev0On1 = ev0 == oldv1 || ev0 == origin1 || ev0 == newv1;
          bool ev1On0 = ev1 == oldv0 || ev1 == origin0 || ev1 == newv0;
          bool ev1On1 = ev1 == oldv1 || ev1 == origin1 || ev1 == newv1;
          if((ev0On0 && ev1On1) || (ev0On1 && ev1On0)) {
            found = true;
            break;
          }
        }
        for(std::size_t k = 0; k < element->getNumVertices(); ++k) {
          MVertex *ev = element->getVertex(k);
          if(ev == oldv0 || ev == origin0 || ev == oldv1 || ev == origin1) {
            touches = true;
            break;
          }
        }
        if(!found && !touches) continue;

        if(newv0) {
          for(std::size_t k = 0; k < element->getNumVertices(); ++k)
            if(element->getVertex(k) == oldv0 ||
               element->getVertex(k) == origin0)
              element->setVertex(k, newv0);
        }
        if(newv1) {
          for(std::size_t k = 0; k < element->getNumVertices(); ++k)
            if(element->getVertex(k) == oldv1 ||
               element->getVertex(k) == origin1)
              element->setVertex(k, newv1);
        }
      }
    }
  }

  static void addIntersectEdgeSurfaceQuads(
    GFace *gf, GEdge *ge,
    const std::map<std::pair<GFace *, MVertex *>, MVertex *> &faceSpawns,
    double thickness, std::map<MElement *, double> &layers,
    std::set<MElement *, MElementPtrLessThan> &skipSourceElements,
    const std::set<MEdge, MEdgeLessThan> *skipLines = nullptr)
  {
    if(!gf || !ge) return;

    std::set<MEdge, MEdgeLessThan> edgesOfElements;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); ++i) {
      MElement *e = gf->getMeshElement(i);
      if(e->getDim() != 2) continue;
      for(int j = 0; j < e->getNumEdges(); ++j)
        edgesOfElements.insert(e->getEdge(j));
    }

    for(auto line : ge->lines) {
      MVertex *v0 = line->getVertex(0);
      MVertex *v1 = line->getVertex(1);
      if(skipLines && skipLines->find(MEdge(v0, v1)) != skipLines->end())
        continue;
      auto it0 = faceSpawns.find(std::make_pair(gf, v0));
      auto it1 = faceSpawns.find(std::make_pair(gf, v1));
      if(it0 == faceSpawns.end() || it1 == faceSpawns.end()) continue;
      MVertex *sv0 = it0->second;
      MVertex *sv1 = it1->second;

      auto itEdge = edgesOfElements.find(MEdge(sv1, sv0));
      if(itEdge == edgesOfElements.end()) {
        Msg::Warning("BoundaryLayer IntersectEdge %d: could not find pushed "
                     "edge in face %d",
                     ge->tag(), gf->tag());
        continue;
      }

      MQuadrangle *q = nullptr;
      if(itEdge->getVertex(0) == sv0)
        q = new MQuadrangle(v0, v1, sv1, sv0);
      else
        q = new MQuadrangle(v1, v0, sv0, sv1);
      gf->quadrangles.push_back(q);
      layers[q] = thickness;
      skipSourceElements.insert(q);
    }
  }

  static MVertex *createMRegionVertex(MVertex *v, GRegion *gr)
  {
    MVertex *newv = new MVertex(v->x(), v->y(), v->z(), gr);
    gr->mesh_vertices.push_back(newv);
    return newv;
  }

  static void replaceEmbeddedCurveFaceVertices(
    GFace *gf, const std::map<MVertex *, EmbeddedElementSides> &vertexSides,
    const std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns)
  {
    std::size_t numElements = gf->getNumMeshElements();
    for(std::size_t i = 0; i < numElements; i++) {
      MElement *element = gf->getMeshElement(i);
      if(element->getDim() != 2) continue;

      int elementSide = -1;
      for(auto v2s : vertexSides) {
        for(int side = 0; side < 2; side++) {
          if(vectorContainsElement(v2s.second.side[side], element)) {
            elementSide = side;
            break;
          }
        }
        if(elementSide >= 0) break;
      }
      if(elementSide < 0) continue;

      std::vector<MVertex *> oldVertices;
      oldVertices.reserve(element->getNumVertices());
      for(std::size_t j = 0; j < element->getNumVertices(); j++)
        oldVertices.push_back(element->getVertex(j));

      for(std::size_t j = 0; j < oldVertices.size(); j++) {
        auto itSpawns = vertexSpawns.find(oldVertices[j]);
        if(itSpawns == vertexSpawns.end()) continue;
        MVertex *newv = itSpawns->second.side[elementSide];
        if(newv) element->setVertex(j, newv);
      }
    }
  }

  static void replaceEmbeddedFaceRegionVertices(
    GRegion *gr, const std::map<MVertex *, EmbeddedElementSides> &vertexSides,
    const std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns)
  {
    for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *element = gr->getMeshElement(i);
      if(element->getDim() != 3) continue;
      for(std::size_t j = 0; j < element->getNumVertices(); j++) {
        auto itSpawns = vertexSpawns.find(element->getVertex(j));
        if(itSpawns == vertexSpawns.end()) continue;
        auto itSides = vertexSides.find(itSpawns->first);
        if(itSides == vertexSides.end()) continue;
        for(int side = 0; side < 2; side++) {
          if(!itSpawns->second.side[side]) continue;
          if(vectorContainsElement(itSides->second.side[side], element)) {
            element->setVertex(j, itSpawns->second.side[side]);
            break;
          }
        }
      }
    }
  }

  static MEdge findElementEdge(MElement *element, MVertex *v0, MVertex *v1)
  {
    MEdge edge(v0, v1);
    for(int i = 0; i < element->getNumEdges(); i++) {
      MEdge elementEdge = element->getEdge(i);
      if(elementEdge == edge) return elementEdge;
    }
    return MEdge();
  }

  static MPrism *newBoundaryLayerPrism(MVertex *v0, MVertex *v1, MVertex *v2,
                                       MVertex *b0, MVertex *b1,
                                       MVertex *b2)
  {
    // The face shared with the modified original element must have the
    // opposite orientation. For an original face (v0,v1,v2), the prism top
    // face is thus (b0,b2,b1); the external boundary face remains
    // (v0,v1,v2), since MPrism face 0 is (0,2,1).
    return new MPrism(v0, v2, v1, b0, b2, b1);
  }

  static MHexahedron *newBoundaryLayerHex(MVertex *v0, MVertex *v1,
                                          MVertex *v2, MVertex *v3,
                                          MVertex *b0, MVertex *b1,
                                          MVertex *b2, MVertex *b3)
  {
    // Same convention for quads: MHexahedron face 0 is (0,3,2,1), so the
    // external boundary face is (v0,v1,v2,v3), while the shared inner face is
    // the odd permutation (b0,b3,b2,b1).
    return new MHexahedron(v0, v3, v2, v1, b0, b3, b2, b1);
  }

  typedef std::map<MFace, std::vector<MVertex *>, MFaceLessThan>
    OriginalVolumeFaceOrders;

  static MVertex *getOriginalVertex(
    MVertex *v, const std::map<MVertex *, MVertex *> *spawnOrigins)
  {
    if(!spawnOrigins) return v;
    MVertex *current = v;
    for(int i = 0; i < 16; ++i) {
      auto it = spawnOrigins->find(current);
      if(it == spawnOrigins->end() || it->second == current) break;
      current = it->second;
    }
    return current;
  }

  static MFace makeFaceKey(
    MElement *faceElement,
    const std::map<MVertex *, MVertex *> *spawnOrigins = nullptr)
  {
    if(!faceElement) return MFace();
    int type = faceElement->getTypeForMSH();
    if(type == MSH_TRI_3)
      return MFace(getOriginalVertex(faceElement->getVertex(0), spawnOrigins),
                   getOriginalVertex(faceElement->getVertex(1), spawnOrigins),
                   getOriginalVertex(faceElement->getVertex(2), spawnOrigins));
    if(type == MSH_QUA_4)
      return MFace(getOriginalVertex(faceElement->getVertex(0), spawnOrigins),
                   getOriginalVertex(faceElement->getVertex(1), spawnOrigins),
                   getOriginalVertex(faceElement->getVertex(2), spawnOrigins),
                   getOriginalVertex(faceElement->getVertex(3), spawnOrigins));
    return MFace();
  }

  static MFace makeFaceKey(
    const MFace &face,
    const std::map<MVertex *, MVertex *> *spawnOrigins = nullptr)
  {
    if(face.getNumVertices() == 3)
      return MFace(getOriginalVertex(face.getVertex(0), spawnOrigins),
                   getOriginalVertex(face.getVertex(1), spawnOrigins),
                   getOriginalVertex(face.getVertex(2), spawnOrigins));
    if(face.getNumVertices() == 4)
      return MFace(getOriginalVertex(face.getVertex(0), spawnOrigins),
                   getOriginalVertex(face.getVertex(1), spawnOrigins),
                   getOriginalVertex(face.getVertex(2), spawnOrigins),
                   getOriginalVertex(face.getVertex(3), spawnOrigins));
    return MFace();
  }

  static int faceOrientationSign(const std::vector<MVertex *> &reference,
                                 const std::vector<MVertex *> &candidate)
  {
    const std::size_t n = reference.size();
    if(n != candidate.size() || (n != 3 && n != 4)) return 0;

    for(std::size_t rot = 0; rot < n; ++rot) {
      std::size_t i = 0;
      for(; i < n; ++i)
        if(candidate[i] != reference[(i + rot) % n]) break;
      if(i == n) return 1;
    }

    for(std::size_t rot = 0; rot < n; ++rot) {
      std::size_t i = 0;
      for(; i < n; ++i)
        if(candidate[i] != reference[(n + rot - i) % n]) break;
      if(i == n) return -1;
    }

    return 0;
  }

  static bool vertexOnFaceClosure(MVertex *v, GFace *gf)
  {
    if(!v || !gf) return false;
    GEntity *ge = v->onWhat();
    if(ge == gf) return true;
    if(!ge) return false;
    if(ge->dim() == 1) {
      std::vector<GEdge *> edges = gf->edges();
      GEdge *gedge = static_cast<GEdge *>(ge);
      return std::find(edges.begin(), edges.end(), gedge) != edges.end();
    }
    if(ge->dim() == 0) {
      std::vector<GVertex *> vertices = gf->vertices();
      GVertex *gvertex = static_cast<GVertex *>(ge);
      return std::find(vertices.begin(), vertices.end(), gvertex) !=
             vertices.end();
    }
    return false;
  }

  static int edgeOrientationInFaceOrder(const std::vector<MVertex *> &order,
                                        MVertex *v0, MVertex *v1)
  {
    const std::size_t n = order.size();
    if(n < 3 || !v0 || !v1) return 0;
    for(std::size_t i = 0; i < n; ++i) {
      MVertex *a = order[i];
      MVertex *b = order[(i + 1) % n];
      if(a == v0 && b == v1) return 1;
      if(a == v1 && b == v0) return -1;
    }
    return 0;
  }

  static int originalVolumeFaceEdgeSignOnModelFace(
    const OriginalVolumeFaceOrders &orders, GFace *gf, MVertex *v0,
    MVertex *v1)
  {
    int result = 0;
    for(const auto &it : orders) {
      const std::vector<MVertex *> &order = it.second;
      bool has0 = false, has1 = false, onClosure = true;
      for(auto v : order) {
        if(v == v0) has0 = true;
        if(v == v1) has1 = true;
        if(!vertexOnFaceClosure(v, gf)) {
          onClosure = false;
          break;
        }
      }
      if(!has0 || !has1 || !onClosure) continue;
      int sign = edgeOrientationInFaceOrder(order, v0, v1);
      if(!sign) continue;
      if(result && result != sign) return 0;
      result = sign;
    }
    return result;
  }

  static MVertex *firstMeshVertexAwayFromModelCorner(GVertex *gv, GEdge *ge)
  {
    if(!gv || !ge || gv->mesh_vertices.empty()) return nullptr;
    MVertex *p = gv->mesh_vertices[0];
    if(ge->getBeginVertex() == gv) {
      for(auto line : ge->lines) {
        if(line->getVertex(0) == p) continue;
        if(line->getVertex(1) == p) continue;
        return line->getVertex(1);
      }
    }
    else if(ge->getEndVertex() == gv) {
      for(auto it = ge->lines.rbegin(); it != ge->lines.rend(); ++it) {
        MLine *line = *it;
        if(line->getVertex(0) == p) continue;
        if(line->getVertex(1) == p) continue;
        return line->getVertex(0);
      }
    }
    return nullptr;
  }

  static bool hasDistinctOriginalVertices(
    MElement *faceElement,
    const std::map<MVertex *, MVertex *> *spawnOrigins)
  {
    if(!faceElement) return false;
    std::set<MVertex *> vertices;
    for(std::size_t i = 0; i < faceElement->getNumVertices(); ++i)
      vertices.insert(getOriginalVertex(faceElement->getVertex(i),
                                        spawnOrigins));
    return vertices.size() == faceElement->getNumVertices();
  }

  static void cacheOriginalVolumeFaceOrders(
    GRegion *gr, const std::map<MElement *, double> &layers,
    OriginalVolumeFaceOrders &orders)
  {
    orders.clear();
    if(!gr) return;
    for(std::size_t i = 0; i < gr->getNumMeshElements(); ++i) {
      MElement *ve = gr->getMeshElement(i);
      if(!ve || ve->getDim() != 3) continue;
      if(layers.find(ve) != layers.end()) continue;
      for(int j = 0; j < ve->getNumFaces(); ++j) {
        MFace vf = ve->getFace(j);
        if(orders.find(vf) != orders.end()) continue;
        std::vector<MVertex *> order;
        for(std::size_t k = 0; k < vf.getNumVertices(); ++k)
          order.push_back(vf.getVertex(k));
        orders[vf] = order;
      }
    }
  }

  static bool findOriginalVolumeFaceOrder(
    const OriginalVolumeFaceOrders &orders, MElement *faceElement,
    const std::map<MVertex *, MVertex *> *spawnOrigins,
    std::vector<MVertex *> &order)
  {
    order.clear();
    MFace target = makeFaceKey(faceElement, spawnOrigins);
    if(!target.getNumVertices()) return false;
    auto it = orders.find(target);
    if(it == orders.end()) return false;
    order = it->second;
    return true;
  }

  static bool orientBoundaryLayerElementFromOriginalVolumeFaces(
    MElement *e, const OriginalVolumeFaceOrders &orders,
    const std::map<MVertex *, MVertex *> &spawnOrigins)
  {
    if(!e || e->getDim() != 3) return false;

    auto countSigns = [&]() {
      std::pair<int, int> signs(0, 0);
      for(int i = 0; i < e->getNumFaces(); ++i) {
        MFace face = e->getFace(i);
        MFace key = makeFaceKey(face, &spawnOrigins);
        if(!key.getNumVertices()) continue;
        auto it = orders.find(key);
        if(it == orders.end()) continue;

        std::vector<MVertex *> candidate;
        candidate.reserve(face.getNumVertices());
        for(std::size_t j = 0; j < face.getNumVertices(); ++j)
          candidate.push_back(getOriginalVertex(face.getVertex(j),
                                                &spawnOrigins));
        const int sign = faceOrientationSign(it->second, candidate);
        if(sign > 0)
          signs.first++;
        else if(sign < 0)
          signs.second++;
      }
      return signs;
    };

    std::pair<int, int> signs = countSigns();
    if(signs.first == 0) return signs.second > 0;
    if(signs.second == 0) {
      e->reverse();
      signs = countSigns();
      if(signs.first == 0) return signs.second > 0;
      e->reverse();
    }

    Msg::Warning("BoundaryLayer: inconsistent topological orientation for "
                 "boundary layer element %zu (%d matching faces with same "
                 "orientation, %d with opposite orientation)",
                 e->getNum(), signs.first, signs.second);
    return false;
  }

  static MEdge findSideElementEdge(
    const std::map<MVertex *, EmbeddedElementSides> &vertexSides, MVertex *v0,
    MVertex *v1, MVertex *sv0, MVertex *sv1, int side)
  {
    auto it = vertexSides.find(v0);
    if(it == vertexSides.end()) it = vertexSides.find(v1);
    if(it == vertexSides.end()) return MEdge();
    for(auto element : it->second.side[side]) {
      MEdge edge = findElementEdge(element, sv0, sv1);
      if(edge.getVertex(0)) return edge;
    }
    return MEdge();
  }

  static void addEmbeddedCurveFaceQuadrangle(
    GFace *gf, MLine *line, MVertex *sv0, MVertex *sv1, const MEdge &sideEdge,
    double thickness, std::map<MElement *, double> &layers)
  {
    if(sideEdge.getVertex(0) == sv0)
      gf->quadrangles.push_back(
        new MQuadrangle(line->getVertex(0), line->getVertex(1), sv1, sv0));
    else
      gf->quadrangles.push_back(
        new MQuadrangle(line->getVertex(1), line->getVertex(0), sv0, sv1));
    layers[gf->quadrangles.back()] = thickness;
  }

  static void addEmbeddedFaceRegionElement(
    GRegion *gr, MElement *embeddedElement,
    const std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns, int side,
    double thickness, std::map<MElement *, double> &layers,
    const OriginalVolumeFaceOrders &originalVolumeFaceOrders,
    const std::map<MVertex *, MVertex *> &spawnOrigins)
  {
    int type = embeddedElement->getTypeForMSH();
    if(type != MSH_TRI_3 && type != MSH_QUA_4) return;

    std::size_t n = (type == MSH_TRI_3) ? 3 : 4;
    MVertex *vs[4] = {nullptr, nullptr, nullptr, nullptr};
    MVertex *bs[4] = {nullptr, nullptr, nullptr, nullptr};
    for(std::size_t i = 0; i < n; i++) {
      vs[i] = embeddedElement->getVertex(i);
      auto it = vertexSpawns.find(vs[i]);
      if(it == vertexSpawns.end()) return;
      bs[i] = it->second.side[side];
      if(!bs[i]) return;
    }

    auto spawnFor = [&](MVertex *v) -> MVertex * {
      for(std::size_t i = 0; i < n; ++i)
        if(getOriginalVertex(vs[i], &spawnOrigins) == v) return bs[i];
      return nullptr;
    };
    auto currentFor = [&](MVertex *v) -> MVertex * {
      for(std::size_t i = 0; i < n; ++i)
        if(getOriginalVertex(vs[i], &spawnOrigins) == v) return vs[i];
      return nullptr;
    };
    std::vector<MVertex *> originalOrder;
    bool haveOriginalOrder =
      findOriginalVolumeFaceOrder(originalVolumeFaceOrders, embeddedElement,
                                  &spawnOrigins, originalOrder);

    if(type == MSH_TRI_3) {
      if(haveOriginalOrder && originalOrder.size() == 3) {
        MVertex *v0 = currentFor(originalOrder[0]);
        MVertex *v1 = currentFor(originalOrder[1]);
        MVertex *v2 = currentFor(originalOrder[2]);
        MVertex *b0 = spawnFor(originalOrder[0]);
        MVertex *b1 = spawnFor(originalOrder[1]);
        MVertex *b2 = spawnFor(originalOrder[2]);
        if(!v0 || !v1 || !v2 || !b0 || !b1 || !b2) return;
        gr->prisms.push_back(newBoundaryLayerPrism(
          v0, v1, v2, b0, b1, b2));
      }
      else {
        Msg::Warning("BoundaryLayer: could not find original volume face "
                     "orientation for triangle in region %d",
                     gr ? gr->tag() : 0);
        return;
      }
      layers[gr->prisms.back()] = thickness;
    }
    else {
      if(haveOriginalOrder && originalOrder.size() == 4) {
        MVertex *v0 = currentFor(originalOrder[0]);
        MVertex *v1 = currentFor(originalOrder[1]);
        MVertex *v2 = currentFor(originalOrder[2]);
        MVertex *v3 = currentFor(originalOrder[3]);
        MVertex *b0 = spawnFor(originalOrder[0]);
        MVertex *b1 = spawnFor(originalOrder[1]);
        MVertex *b2 = spawnFor(originalOrder[2]);
        MVertex *b3 = spawnFor(originalOrder[3]);
        if(!v0 || !v1 || !v2 || !v3 || !b0 || !b1 || !b2 || !b3) return;
        gr->hexahedra.push_back(newBoundaryLayerHex(
          v0, v1, v2, v3, b0, b1, b2, b3));
      }
      else {
        Msg::Warning("BoundaryLayer: could not find original volume face "
                     "orientation for quadrangle in region %d",
                     gr ? gr->tag() : 0);
        return;
      }
      layers[gr->hexahedra.back()] = thickness;
    }
  }

  static void buildEmbeddedElementSideData(
    const std::map<GEdge *, std::vector<GFace *>> &edgesEmbeddedInFaces,
    const std::map<GFace *, std::vector<GRegion *>> &facesEmbeddedInRegions,
    EmbeddedElementSideData &data)
  {
    for(auto e2f : edgesEmbeddedInFaces) {
      GEdge *ge = e2f.first;
      for(auto gf : e2f.second) {
        std::map<MVertex *, EmbeddedElementSides> &vertexSides =
          data.curvesInFaces[std::make_pair(ge, gf)];
        for(auto line : ge->lines) {
          MEdge embeddedEdge(line->getVertex(0), line->getVertex(1));
          for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
            MElement *element = gf->getMeshElement(i);
            if(element->getDim() != 2) continue;
            for(int j = 0; j < element->getNumEdges(); j++) {
              MEdge elementEdge = element->getEdge(j);
              if(elementEdge != embeddedEdge) continue;
              int side =
                (elementEdge.getVertex(0) == embeddedEdge.getVertex(0)) ? 0 : 1;
              addEmbeddedSideElement(vertexSides, embeddedEdge.getVertex(0),
                                     side, element);
              addEmbeddedSideElement(vertexSides, embeddedEdge.getVertex(1),
                                     side, element);
            }
          }
        }
        for(auto line : ge->lines) {
          for(int iVertex = 0; iVertex < 2; iVertex++) {
            MVertex *embeddedVertex = line->getVertex(iVertex);
            EmbeddedElementSides &sides = vertexSides[embeddedVertex];
            for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
              MElement *element = gf->getMeshElement(i);
              if(element->getDim() != 2) continue;
              if(!elementHasVertex(element, embeddedVertex)) continue;
              if(embeddedSidesContainElement(sides, element)) continue;
              int side = -1;
              if(classifyElementFromEmbeddedLine(gf, line, sides, element,
                                                 side))
                addEmbeddedSideElement(sides, side, element);
            }
          }
        }
      }
    }

    for(auto f2r : facesEmbeddedInRegions) {
      GFace *gf = f2r.first;
      for(auto gr : f2r.second) {
        std::map<MVertex *, EmbeddedElementSides> &vertexSides =
          data.facesInRegions[std::make_pair(gf, gr)];
        for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
          MElement *embeddedElement = gf->getMeshElement(i);
          if(embeddedElement->getDim() != 2) continue;
          MFace embeddedFace = embeddedElement->getFace(0);
          for(std::size_t j = 0; j < gr->getNumMeshElements(); j++) {
            MElement *element = gr->getMeshElement(j);
            if(element->getDim() != 3) continue;
            for(int k = 0; k < element->getNumFaces(); k++) {
              if(element->getFace(k) != embeddedFace) continue;
              int ithFace = 0, sign = 0, rot = 0;
              if(element->getFaceInfo(embeddedFace, ithFace, sign, rot)) {
                int side = sign > 0 ? 0 : 1;
                for(std::size_t l = 0; l < embeddedElement->getNumVertices();
                    l++)
                  addEmbeddedSideElement(
                    vertexSides, embeddedElement->getVertex(l), side, element);
              }
            }
          }
        }
      }
    }
  }

} // namespace

static void
classifyVertexOnFace(GFace *gf, MVertex *v)
{
  if(!gf || !v || !v->onWhat() || v->onWhat()->dim() <= 2) return;

  SPoint3 p = v->point();
  SPoint2 param = gf->parFromPoint(p);
  double guess[2] = {param.x(), param.y()};
  GPoint gp = gf->closestPoint(p, guess);
  v->x() = gp.x();
  v->y() = gp.y();
  v->z() = gp.z();
  v->setParameter(0, gp.u());
  v->setParameter(1, gp.v());
  v->setEntity(gf);
  gf->mesh_vertices.push_back(v);
}

static std::vector<MVertex *>
getOrientedSplit(
  const std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
  const MEdge &edge)
{
  auto it = split.find(edge);
  if(it == split.end()) return std::vector<MVertex *>();
  std::vector<MVertex *> vertices = it->second;
  if(!vertices.empty() && vertices.front() != edge.getVertex(0))
    std::reverse(vertices.begin(), vertices.end());
  return vertices;
}

static double
splitLayerWidth(const std::vector<double> &widths, std::size_t layer,
                double fallback)
{
  if(widths.empty()) return fallback;
  if(layer >= widths.size()) layer = widths.size() - 1;
  return widths[layer];
}

static SPoint3
bilinearPoint(const SPoint3 &p, const SPoint3 &a, const SPoint3 &s,
              const SPoint3 &b, double u, double v)
{
  return SPoint3((1. - u) * (1. - v) * p.x() + u * (1. - v) * a.x() +
                   u * v * s.x() + (1. - u) * v * b.x(),
                 (1. - u) * (1. - v) * p.y() + u * (1. - v) * a.y() +
                   u * v * s.y() + (1. - u) * v * b.y(),
                 (1. - u) * (1. - v) * p.z() + u * (1. - v) * a.z() +
                   u * v * s.z() + (1. - u) * v * b.z());
}

static MVertex *
getOrCreateMFaceVertexAtPoint(const SPoint3 &p, GFace *gf)
{
  if(!gf) return nullptr;
  const double eps2 = 1.e-24;
  for(auto v : gf->mesh_vertices) {
    const double dx = v->x() - p.x();
    const double dy = v->y() - p.y();
    const double dz = v->z() - p.z();
    if(dx * dx + dy * dy + dz * dz < eps2) return v;
  }
  return createMFaceVertexAtPoint(p, gf);
}

static void
replaceFaces(GModel *gm,
             std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
             std::map<MElement *, double> &layers,
             const std::vector<double> &widths)
{
  std::vector<double> fractions(1, 0.);
  double totalWidth = 0.;
  for(double w : widths) totalWidth += w;
  if(totalWidth > 0.) {
    double wloc = 0.;
    for(double w : widths) {
      wloc += w;
      fractions.push_back(wloc / totalWidth);
    }
  }

  for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); ++fit) {
    GFace *gf = (*fit);

    std::vector<MQuadrangle *> newVec;
    for(auto q : gf->quadrangles) {
      bool found = false;
      auto itLayer = layers.find(q);

      std::vector<MVertex *> e01 =
        getOrientedSplit(split, MEdge(q->getVertex(0), q->getVertex(1)));
      std::vector<MVertex *> e12 =
        getOrientedSplit(split, MEdge(q->getVertex(1), q->getVertex(2)));
      std::vector<MVertex *> e32 =
        getOrientedSplit(split, MEdge(q->getVertex(3), q->getVertex(2)));
      std::vector<MVertex *> e03 =
        getOrientedSplit(split, MEdge(q->getVertex(0), q->getVertex(3)));

      if(!e01.empty() && !e12.empty() && !e32.empty() && !e03.empty() &&
         e01.size() == e12.size() && e01.size() == e32.size() &&
         e01.size() == e03.size()) {
        const std::size_t n = e01.size() - 1;
        std::vector<std::vector<MVertex *> > grid(
          n + 1, std::vector<MVertex *>(n + 1, nullptr));
        for(std::size_t i = 0; i <= n; ++i) {
          grid[i][0] = e01[i];
          grid[i][n] = e32[i];
        }
        for(std::size_t j = 0; j <= n; ++j) {
          grid[0][j] = e03[j];
          grid[n][j] = e12[j];
        }

        SPoint3 p = q->getVertex(0)->point();
        SPoint3 a = q->getVertex(1)->point();
        SPoint3 s = q->getVertex(2)->point();
        SPoint3 b = q->getVertex(3)->point();
        for(std::size_t i = 1; i < n; ++i) {
          const double u =
            (fractions.size() == n + 1) ? fractions[i] :
                                          (double)i / (double)n;
          for(std::size_t j = 1; j < n; ++j) {
            const double v =
              (fractions.size() == n + 1) ? fractions[j] :
                                            (double)j / (double)n;
            grid[i][j] = getOrCreateMFaceVertexAtPoint(
              bilinearPoint(p, a, s, b, u, v), gf);
          }
        }

        for(std::size_t i = 0; i < n; ++i) {
          for(std::size_t j = 0; j < n; ++j) {
            MQuadrangle *nq =
              new MQuadrangle(grid[i][j], grid[i + 1][j],
                              grid[i + 1][j + 1], grid[i][j + 1]);
            newVec.push_back(nq);
            if(itLayer != layers.end())
              layers[nq] = splitLayerWidth(widths, std::max(i, j),
                                           itLayer->second);
          }
        }
        found = true;
      }

      if(found) {
        if(itLayer != layers.end()) layers.erase(itLayer);
        delete q;
        continue;
      }

      std::vector<MVertex *> strip0 =
        getOrientedSplit(split, MEdge(q->getVertex(0), q->getVertex(1)));
      std::vector<MVertex *> strip1 =
        getOrientedSplit(split, MEdge(q->getVertex(3), q->getVertex(2)));
      if(!strip0.empty() && strip0.size() == strip1.size()) {
        for(size_t j = 0; j < strip0.size() - 1; j++) {
          MQuadrangle *nq =
            new MQuadrangle(strip0[j], strip0[j + 1], strip1[j + 1],
                            strip1[j]);
          for(int k = 0; k < 4; ++k) classifyVertexOnFace(gf, nq->getVertex(k));
          newVec.push_back(nq);
          if(itLayer != layers.end())
            layers[nq] = j < widths.size() ? widths[j] : itLayer->second;
        }
        found = true;
      }
      else {
        strip0 =
          getOrientedSplit(split, MEdge(q->getVertex(1), q->getVertex(2)));
        strip1 =
          getOrientedSplit(split, MEdge(q->getVertex(0), q->getVertex(3)));
        if(!strip0.empty() && strip0.size() == strip1.size()) {
          for(size_t j = 0; j < strip0.size() - 1; j++) {
            MQuadrangle *nq =
              new MQuadrangle(strip1[j], strip0[j], strip0[j + 1],
                              strip1[j + 1]);
            for(int k = 0; k < 4; ++k)
              classifyVertexOnFace(gf, nq->getVertex(k));
            newVec.push_back(nq);
            if(itLayer != layers.end())
              layers[nq] = j < widths.size() ? widths[j] : itLayer->second;
          }
          found = true;
        }
      }
      if(found) {
        if(itLayer != layers.end()) layers.erase(itLayer);
        delete q;
      }
      else
        newVec.push_back(q);
    }
    gf->quadrangles = newVec;
  }
}

static void
replaceEdges(GModel *gm,
             std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split)
{
  for(GModel::eiter eit = gm->firstEdge(); eit != gm->lastEdge(); ++eit) {
    GEdge *ge = (*eit);
    if(ge->lines.empty()) continue;
    MLine *l0 = ge->lines.front();
    MLine *l1 = ge->lines.back();
    MEdge m0 = MEdge(l0->getVertex(0), l0->getVertex(1));
    MEdge m1 = MEdge(l1->getVertex(0), l1->getVertex(1));
    auto it0 = split.find(m0);
    auto it1 = split.find(m1);

    if(it0 != split.end()) {
      //      printf("coucou %d
      //      %d\n",ge->tag(),l0->getVertex(0)->onWhat()->dim());
      std::vector<MLine *> old = ge->lines;
      ge->lines.clear();
      for(size_t j = 0; j < it0->second.size() - 1; j++)
        ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
      for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
      delete old.front();
    }
    if(it1 != split.end()) {
      //      	printf("poucou %d
      //      %d\n",ge->tag(),l1->getVertex(0)->onWhat()->dim());
      size_t s = it1->second.size();
      ge->lines.back()->setVertex(0, it1->second[s - 2]);
      for(size_t j = 2; j < s; j++)
        ge->lines.push_back(
          new MLine(it1->second[s - j], it1->second[s - j - 1]));
    }
  }
}

bool bl3d(GModel *m, std::vector<GFace *> &onSurfaces,
          std::vector<GRegion *> &inVolumes, double thickness,
          std::map<MElement *, double> &layers, std::vector<GFace *> &toExpand,
          std::vector<GEdge *> &intersectEdges,
          std::map<MElement *, BoundaryLayerIntersectEdgeHex>
            *intersectEdgeHexes,
          std::map<MElement *, BoundaryLayerIntersectCornerHex>
            *intersectCornerHexes,
          std::map<MElement *, BoundaryLayerCornerQuad> *cornerBLQuads)
{
  // 3D case:
  // for each GVertex connected to the GFaces in inSurfaces:
  //   - if all adjacent GFaces to the GVertex are in inSurface, spawn 1 MVertex
  //     in each GRegion connected to the GVertex that are in inVolumes
  //   - if some adjacent GFaces are not in inSurfaces, spawn 1 MVertex in each
  //     connected GFace
  //   -
  // for each MVertex classified on a GEdge connected to the GFaces in
  // inSurfaces:
  //   -
  // for each MVertex classified on the GFaces in inSurfaces:
  //   -

  std::set<GFace *> onSurfacesSet;
  onSurfacesSet.insert(onSurfaces.begin(), onSurfaces.end());

  std::set<GRegion *> inVolumesSet;
  inVolumesSet.insert(inVolumes.begin(), inVolumes.end());

  std::map<MVertex *, std::vector<MVertex *>> spawned;
  std::set<GEdge *> intersectEdgesSet;
  intersectEdgesSet.insert(intersectEdges.begin(), intersectEdges.end());
  std::map<std::pair<GFace *, MVertex *>, MVertex *> intersectFaceSpawns;
  std::map<std::pair<std::pair<GRegion *, GEdge *>, MVertex *>, MVertex *>
    intersectRegionSpawns;
  std::map<std::pair<GRegion *, MVertex *>, MVertex *>
    intersectCornerRegionSpawns;
  std::map<std::pair<GVertex *, GEdge *>, MVertex *>
    intersectCornerVertices;
  std::map<MVertex *, MVertex *> intersectCornerOrigins;
  std::set<MEdge, MEdgeLessThan> skipIntersectSurfaceLines;
  std::vector<BoundaryLayerCornerQuad> pendingIntersectCornerQuads;
  std::set<MElement *, MElementPtrLessThan> skipSourceElements;
  std::set<MElement *, MElementPtrLessThan> skipVolumeReplacementElements;
  std::map<GRegion *, OriginalVolumeFaceOrders> originalVolumeFaceOrders;
  for(auto gr : inVolumes)
    cacheOriginalVolumeFaceOrders(gr, layers, originalVolumeFaceOrders[gr]);

  std::set<GVertex *> connectedPoints;
  for(auto gf : onSurfaces) {
    auto vs = gf->vertices();
    connectedPoints.insert(vs.begin(), vs.end());
  }

  ///// ----> TREAT POINTS
  ///---------------------------------------------------------
  // spawn nodes for model points

  // All model points that are corners of surfaces where
  // we want to create a layer.
  // Consider a point gv
  //   --> for all curves ge attached to gv
  //       if (ge) has more that one ajacent face that wants layers

  if(_debugBL3D) printf("connected points size %zu\n", connectedPoints.size());

  for(auto gv : connectedPoints) {
    if(gv->mesh_vertices.empty()) {
      Msg::Warning("No mesh node on model point %d - abort!", gv->tag());
      return false;
    }

    if(_debugBL3D) printf("connected point %d\n", gv->tag());

    auto connectedCurves = gv->edges();
    auto connectedSurfaces = gv->faces();
    auto connectedVolumes = gv->regions();

    std::vector<GEdge *> toinsert;

    std::size_t found = 0;

    std::set<GEdge *> curvesThatAreAdjacentToonSurfacesSet;
    for(auto gf : onSurfacesSet) {
      if(_debugBL3D) printf("onSurfacesSet %d\n", gf->tag());
      auto e = gf->edges();
      curvesThatAreAdjacentToonSurfacesSet.insert(e.begin(), e.end());
    }

    for(auto ge : connectedCurves) {
      if(_debugBL3D) printf("connectedCurve %d", ge->tag());
      if(curvesThatAreAdjacentToonSurfacesSet.find(ge) !=
         curvesThatAreAdjacentToonSurfacesSet.end()) {
        if(_debugBL3D) printf(" found\n");
        found++;
      }
      else {
        toinsert.push_back(ge);
        if(_debugBL3D) printf(" not found\n");
      }
    }

    for(auto ge : toinsert) {
      if(_debugBL3D) printf("   EDDD -- toinsert %d", ge->tag());
      MVertex *v = gv->mesh_vertices[0];
      double param;
      if(reparamMeshVertexOnEdge(v, ge, param)) {
        bool end = ge->getEndVertex() == gv;
        MVertex *newv;
        if(end) {
          MEdgeVertex *vend =
            static_cast<MEdgeVertex *>(ge->mesh_vertices.back());
          newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, 0,
                                 vend->getLc());
          ge->mesh_vertices.push_back(newv);
        }
        else {
          MEdgeVertex *vbeg =
            static_cast<MEdgeVertex *>(ge->mesh_vertices.front());
          newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, 0,
                                 vbeg->getLc());
          ge->mesh_vertices.insert(ge->mesh_vertices.begin(), newv);
        }

        spawned[v].push_back(newv);
        Msg::Debug(
          "inserted node %zu from point %d in curve %d -- %zu internal nodes",
          newv->getNum(), gv->tag(), ge->tag(), ge->mesh_vertices.size());
        if(end) {
          ge->lines.back()->setVertex(1, newv);
          ge->lines.push_back(new MLine(newv, v));
        }
        else
          ge->lines.insert(ge->lines.begin(), new MLine(newv, v));
      }
      else {
        Msg::Warning("Could not compute parametric coordinates of node on "
                     "curve %d",
                     ge->tag());
      }
    }

    // We insert mesh that is classified on a model vertex on a surface

    std::vector<GFace *> toinsert2;
    for(auto gf : connectedSurfaces) {
      if(_debugBL3D) printf(" --> connectedSurface %d\n", gf->tag());
      auto ed = gf->edges();
      bool edgeAlreadyDone = false;
      for(auto ge : ed)
        if(std::find(toinsert.begin(), toinsert.end(), ge) != toinsert.end()) {
          if(_debugBL3D) printf(" x-> edgeAlreadyDone %d\n", ge->tag());
          edgeAlreadyDone = true;
        }

      if(_debugBL3D) printf(" --> edgeAlreadyDone %d\n", edgeAlreadyDone);
      if(edgeAlreadyDone || onSurfacesSet.find(gf) != onSurfacesSet.end()) {
        found++;
      }
      else {
        toinsert2.push_back(gf);
      }
    }

    if(_debugBL3D) printf(" --> toInstert2 size %zu\n", toinsert2.size());
    for(auto gf : toinsert2) {
      MVertex *v = gv->mesh_vertices[0];
      SPoint2 param;
      if(reparamMeshVertexOnFace(v, gf, param)) {
        MFaceVertex *newv =
          new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
        gf->mesh_vertices.push_back(newv);
        spawned[v].push_back(newv);
      }
    }
  }
  ///// ----> END OF TREAT POINTS
  ///---------------------------------------------------------

  ///// ----> TREAT CURVES
  ///--------------------------------------------------------- / --> Spawn nodes
  /// on model curves

  std::set<GEdge *> connectedCurves;
  for(auto gf : onSurfaces) {
    auto es = gf->edges();
    connectedCurves.insert(es.begin(), es.end());
  }
  for(auto ge : connectedCurves) {
    if(_debugBL3D) printf(" XC-> connectedCurve %d\n", ge->tag());
    auto fs = ge->faces();

    // for all faces f2ge adjacent to ge
    for(auto f2ge : fs) {
      if(_debugBL3D)
        printf("  XC-> face adj %d onSurfacesSet %d\n", f2ge->tag(),
               onSurfacesSet.find(f2ge) != onSurfacesSet.end());
      // if f2ge is onSurfaces of f2ge continue
      if(onSurfacesSet.find(f2ge) != onSurfacesSet.end()) continue;
      auto vs = f2ge->regions();

      // for all volumes v adjacent to f2ge
      for(auto vol : vs) {
        if(inVolumesSet.find(vol) == inVolumesSet.end()) continue;
        auto facesOfvol = vol->faces();
        if(_debugBL3D)
          printf("  XC-> volume %d is a BL volume -- face belongs to it %d \n",
                 vol->tag(),
                 std::find(facesOfvol.begin(), facesOfvol.end(), f2ge) !=
                   facesOfvol.end());
        if(std::find(facesOfvol.begin(), facesOfvol.end(), f2ge) !=
           facesOfvol.end()) {
          if(_debugBL3D)
            printf("  XC-> edge %d onSurface %d\n", ge->tag(), f2ge->tag());

          for(auto ev : ge->mesh_vertices) {
            SPoint2 param;
            reparamMeshVertexOnFace(ev, f2ge, param);
            MFaceVertex *newv = new MFaceVertex(ev->x(), ev->y(), ev->z(), f2ge,
                                                param.x(), param.y());
            f2ge->mesh_vertices.push_back(newv);
            spawned[ev].push_back(newv);
          }
        }
        else {
          if(_debugBL3D)
            printf(" --> edge %d in volume %d\n", ge->tag(), vol->tag());
          for(auto ev : ge->mesh_vertices) {
            MVertex *newv = new MVertex(ev->x(), ev->y(), ev->z(), vol);
            vol->mesh_vertices.push_back(newv);
            spawned[ev].push_back(newv);
          }
        }
      }
    }
  }

  for(auto gf : onSurfaces) {
    std::map<MVertex *, MVertex *> v2v;
    auto eds = gf->edges();
    auto vol = gf->regions();
    for(auto gr : vol) {
      if(inVolumesSet.find(gr) == inVolumesSet.end()) continue;
      for(auto v : gf->mesh_vertices) {
        MVertex *newv = new MVertex(v->x(), v->y(), v->z(), gr);
        gr->mesh_vertices.push_back(newv);
        v2v[v] = newv;
        spawned[v].push_back(newv);
      }
      for(std::size_t j = 0; j < gf->getNumMeshElements(); j++) {
        MElement *e = gf->getMeshElement(j);
        int type = e->getTypeForMSH();
        if(type != MSH_TRI_3 && type != MSH_QUA_4) continue;
        std::size_t n = (type == MSH_TRI_3) ? 3 : 4;
        MVertex *vs[4] = {nullptr, nullptr, nullptr, nullptr};
        MVertex *bs[4] = {nullptr, nullptr, nullptr, nullptr};
        for(size_t i = 0; i < n; i++) {
          vs[i] = e->getVertex(i);
          std::map<MVertex *, MVertex *>::iterator it = v2v.find(vs[i]);
          std::map<MVertex *, std::vector<MVertex *>>::iterator its =
            spawned.find(vs[i]);
          if(it != v2v.end())
            bs[i] = it->second;
          else if(its != spawned.end() && its->second.size()) {
            // For a volume layer extruded from gf into gr, the top vertex must
            // be classified in the region. Face spawns are bottom/topology
            // helpers for surface closure; using them here creates flat hexes.
            for(auto vv : its->second) {
              if(vv->onWhat() == gr) {
                bs[i] = vv;
                break;
              }
            }
            if(!bs[i]) {
              for(auto vv : its->second) {
                if(vv->onWhat()->dim() == 3) {
                  bs[i] = vv;
                  break;
                }
              }
            }
          }
          if(!bs[i]) {
            bs[i] = new MVertex(vs[i]->x(), vs[i]->y(), vs[i]->z(), gr);
            gr->mesh_vertices.push_back(bs[i]);
            spawned[vs[i]].push_back(bs[i]);
            // Msg::Error("no counterpart vertex for %d",vs[i]->getNum());
          }
        }
      }
    }
  }

  for(auto gf : onSurfacesSet) {
    auto vs = gf->regions();
    for(auto vol : vs) {
      if(inVolumesSet.find(vol) != inVolumesSet.end()) {
        for(auto vv : gf->mesh_vertices) {
          MVertex *newv = new MVertex(vv->x(), vv->y(), vv->z(), vol);
          vol->mesh_vertices.push_back(newv);
          spawned[vv].push_back(newv);
          //  printf("Spawned node %zu in volume %d from surface %d\n",
          //                 newv->getNum(), vol->tag(), gf->tag());
        }
      }
    }
  }

  // Embedded Stuff
  // ------------------------------------------------------------------------
  std::map<GVertex *, std::vector<GFace *>>
    verticesEmbeddedInFacesAsCurveEndpoints;
  std::map<GEdge *, std::vector<GFace *>> edgesEmbeddedInFaces;
  std::map<GEdge *, std::vector<GRegion *>> edgesEmbeddedInRegions;
  std::map<GFace *, std::vector<GRegion *>> facesEmbeddedInRegions;
  getEmbeddedStructure(m, verticesEmbeddedInFacesAsCurveEndpoints,
                       edgesEmbeddedInFaces, edgesEmbeddedInRegions,
                       facesEmbeddedInRegions);

  EmbeddedElementSideData embeddedElementSideData;
  buildEmbeddedElementSideData(edgesEmbeddedInFaces, facesEmbeddedInRegions,
                               embeddedElementSideData);
  EmbeddedCurveFaceSpawns embeddedCurveFaceSpawns;
  if(_debugBL3D) {
    for(auto c2f : embeddedElementSideData.curvesInFaces)
      for(auto v2s : c2f.second)
        printf(" --EMP  Edge %d embedded in Face %d, vertex %zu: %zu/%zu "
               "elements\n",
               c2f.first.first->tag(), c2f.first.second->tag(),
               v2s.first->getNum(), v2s.second.side[0].size(),
               v2s.second.side[1].size());
    for(auto f2r : embeddedElementSideData.facesInRegions)
      for(auto v2s : f2r.second)
        printf(" --EMP  Face %d embedded in Region %d, vertex %zu: %zu/%zu "
               "elements\n",
               f2r.first.first->tag(), f2r.first.second->tag(),
               v2s.first->getNum(), v2s.second.side[0].size(),
               v2s.second.side[1].size());
  }

  for(auto v2f : verticesEmbeddedInFacesAsCurveEndpoints) {
    for(auto gf : v2f.second) {
      if(_debugBL3D)
        printf(" --EMP  Vertex %d embedded in Face %d\n", v2f.first->tag(),
               gf->tag());
      MVertex *v = v2f.first->mesh_vertices[0];
      SPoint2 param;
      if(reparamMeshVertexOnFace(v, gf, param)) {
        MFaceVertex *newv =
          new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
        gf->mesh_vertices.push_back(newv);
        spawned[v].push_back(newv);
      }
    }
  }

  for(auto e2f : edgesEmbeddedInFaces) {
    GEdge *emb = e2f.first;
    for(auto gf : e2f.second) {
      if(_debugBL3D)
        printf(" --EMP  Edge %d embedded in Face %d\n", emb->tag(), gf->tag());

      std::pair<GEdge *, GFace *> key = std::make_pair(emb, gf);
      std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns =
        embeddedCurveFaceSpawns.curvesInFaces[key];
      const std::map<MVertex *, EmbeddedElementSides> &vertexSides =
        embeddedElementSideData.curvesInFaces[key];

      MVertex *begin = emb->getBeginVertex()->mesh_vertices.empty() ?
                         nullptr :
                         emb->getBeginVertex()->mesh_vertices[0];
      MVertex *end = emb->getEndVertex()->mesh_vertices.empty() ?
                       nullptr :
                       emb->getEndVertex()->mesh_vertices[0];
      MVertex *endPoints[2] = {begin, end};
      for(int i = 0; i < 2; i++) {
        MVertex *v = endPoints[i];
        if(!v) continue;
        MVertex *newv = nullptr;
        auto it = spawned.find(v);
        if(it != spawned.end()) {
          for(auto sp : it->second) {
            if(sp->onWhat() == gf) {
              newv = sp;
              break;
            }
          }
        }
        if(!newv) {
          newv = createMFaceVertex(v, gf);
          if(newv) spawned[v].push_back(newv);
        }
        vertexSpawns[v].side[0] = newv;
        vertexSpawns[v].side[1] = newv;
      }

      for(auto v : emb->mesh_vertices) {
        for(int side = 0; side < 2; side++) {
          MFaceVertex *newv = createMFaceVertex(v, gf);
          if(newv) {
            spawned[v].push_back(newv);
            vertexSpawns[v].side[side] = newv;
          }
        }
      }

      replaceEmbeddedCurveFaceVertices(gf, vertexSides, vertexSpawns);
    }
  }

  for(auto e2r : edgesEmbeddedInRegions) {
    for(auto gr : e2r.second) {
      if(_debugBL3D)
        printf(" --EMP  Edge %d embedded in Region %d\n", e2r.first->tag(),
               gr->tag());
      for(auto v : e2r.first->mesh_vertices) {
        MVertex *newv = new MVertex(v->x(), v->y(), v->z(), gr);
        gr->mesh_vertices.push_back(newv);
        spawned[v].push_back(newv);
      }
    }
  }

  for(auto f2r : facesEmbeddedInRegions) {
    GFace *embeddedFace = f2r.first;
    for(auto gr : f2r.second) {
      if(_debugBL3D)
        printf(" --EMP  Face %d embedded in Region %d\n", embeddedFace->tag(),
               gr->tag());

      std::pair<GFace *, GRegion *> key = std::make_pair(embeddedFace, gr);
      std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns =
        embeddedCurveFaceSpawns.facesInRegions[key];
      const std::map<MVertex *, EmbeddedElementSides> &vertexSides =
        embeddedElementSideData.facesInRegions[key];

      auto embeddedEdges = embeddedFace->edges();
      for(auto ge : embeddedEdges) {
        for(auto v : ge->mesh_vertices) {
          MVertex *newv = nullptr;
          auto it = spawned.find(v);
          if(it != spawned.end()) {
            for(auto sp : it->second) {
              if(sp->onWhat() == gr) {
                newv = sp;
                break;
              }
            }
          }
          if(!newv) {
            newv = createMRegionVertex(v, gr);
            spawned[v].push_back(newv);
          }
          vertexSpawns[v].side[0] = newv;
          vertexSpawns[v].side[1] = newv;
        }
      }

      auto embeddedVertices = embeddedFace->vertices();
      for(auto gv : embeddedVertices) {
        if(gv->mesh_vertices.empty()) continue;
        MVertex *v = gv->mesh_vertices[0];
        MVertex *newv = nullptr;
        auto it = spawned.find(v);
        if(it != spawned.end()) {
          for(auto sp : it->second) {
            if(sp->onWhat() == gr) {
              newv = sp;
              break;
            }
          }
        }
        if(!newv) {
          newv = createMRegionVertex(v, gr);
          spawned[v].push_back(newv);
        }
        vertexSpawns[v].side[0] = newv;
        vertexSpawns[v].side[1] = newv;
      }

      for(auto v : embeddedFace->mesh_vertices) {
        for(int side = 0; side < 2; side++) {
          MVertex *newv = createMRegionVertex(v, gr);
          vertexSpawns[v].side[side] = newv;
        }
      }

      replaceEmbeddedFaceRegionVertices(gr, vertexSides, vertexSpawns);
    }
  }

  // Embedded Stuff
  // ------------------------------------------------------------------------

  // IntersectEdges: if a BL curve is shared by two BL faces, push the
  // neighboring surface elements on both faces and create the corner hexes
  // directly from the mesh segments of the curve.
  std::set<GVertex *> intersectEdgeVertices;
  for(auto ge : intersectEdgesSet) {
    if(!ge) continue;
    if(ge->getBeginVertex() == ge->getEndVertex()) continue;
    auto vs = ge->vertices();
    intersectEdgeVertices.insert(vs.begin(), vs.end());
  }
  for(auto gv : intersectEdgeVertices) {
    if(!gv || gv->mesh_vertices.empty()) continue;
    MVertex *p = gv->mesh_vertices[0];
    for(auto gf : gv->faces()) {
      if(onSurfacesSet.find(gf) == onSurfacesSet.end()) continue;
      std::vector<GEdge *> cornerEdges =
        boundaryLayerCurvesInFace(gv, gf, intersectEdgesSet);
      if(cornerEdges.size() != 2) {
        if(!cornerEdges.empty())
          Msg::Warning("BoundaryLayer IntersectEdge corner point %d on face "
                       "%d has %zu adjacent intersect edges; expected 2",
                       gv->tag(), gf->tag(), cornerEdges.size());
        continue;
      }

      MVertex *s = getOrCreateFaceSpawn(p, gf, intersectFaceSpawns);
      MVertex *a = insertCornerBoundaryLayerVertex(
        gv, cornerEdges[0], thickness, intersectCornerVertices);
      MVertex *b = insertCornerBoundaryLayerVertex(
        gv, cornerEdges[1], thickness, intersectCornerVertices);
      if(!s || !a || !b) continue;

      intersectFaceSpawns[std::make_pair(gf, a)] = s;
      intersectFaceSpawns[std::make_pair(gf, b)] = s;
      pushUniqueSpawn(spawned, a, s);
      pushUniqueSpawn(spawned, b, s);
      intersectCornerOrigins[a] = p;
      intersectCornerOrigins[b] = p;
      skipIntersectSurfaceLines.insert(MEdge(p, a));
      skipIntersectSurfaceLines.insert(MEdge(p, b));

      BoundaryLayerCornerQuad corner;
      corner.gv = gv;
      corner.gf = gf;
      corner.edgeA = cornerEdges[0];
      corner.edgeB = cornerEdges[1];
      corner.p = p;
      corner.a = a;
      corner.s = s;
      corner.b = b;
      pendingIntersectCornerQuads.push_back(corner);
    }
  }

  // The first edge hex next to an intersect corner must share the volume
  // corner node with the corner hex. Seed these aliases before constructing
  // the edge hexes: the region spawn of the first inserted point on each of
  // the 3 intersect edges is the same vertex as the region spawn of the model
  // corner.
  for(auto gv : intersectEdgeVertices) {
    if(!gv || gv->mesh_vertices.empty()) continue;
    MVertex *p = gv->mesh_vertices[0];
    for(auto gr : inVolumesSet) {
      std::vector<GEdge *> cornerEdges;
      for(auto ge : gv->edges()) {
        if(intersectEdgesSet.find(ge) == intersectEdgesSet.end()) continue;
        if(ge->getBeginVertex() != gv && ge->getEndVertex() != gv) continue;
        if(!edgeIsInRegion(ge, gr)) continue;
        cornerEdges.push_back(ge);
      }
      if(cornerEdges.size() != 3) continue;

      std::array<int, 3> perm = {0, 1, 2};
      const OriginalVolumeFaceOrders &orders = originalVolumeFaceOrders[gr];
      do {
        GEdge *e0 = cornerEdges[perm[0]];
        GEdge *e1 = cornerEdges[perm[1]];
        GEdge *e2 = cornerEdges[perm[2]];
        GFace *f01 =
          boundaryLayerFaceOnEdgePair(gv, e0, e1, onSurfacesSet, gr);
        GFace *f02 =
          boundaryLayerFaceOnEdgePair(gv, e0, e2, onSurfacesSet, gr);
        GFace *f12 =
          boundaryLayerFaceOnEdgePair(gv, e1, e2, onSurfacesSet, gr);
        if(!f01 || !f02 || !f12) continue;
        MVertex *a = intersectCornerVertices[std::make_pair(gv, e0)];
        MVertex *b = intersectCornerVertices[std::make_pair(gv, e1)];
        MVertex *c = intersectCornerVertices[std::make_pair(gv, e2)];
        if(!a || !b || !c) continue;
        MVertex *r0 = firstMeshVertexAwayFromModelCorner(gv, e0);
        MVertex *r1 = firstMeshVertexAwayFromModelCorner(gv, e1);
        MVertex *r2 = firstMeshVertexAwayFromModelCorner(gv, e2);
        if(!r0 || !r1 || !r2) continue;
        const int s01e0 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f01, p, r0);
        const int s01e1 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f01, p, r1);
        const int s02e0 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f02, p, r0);
        const int s02e2 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f02, p, r2);
        const int s12e1 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f12, p, r1);
        const int s12e2 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f12, p, r2);
        if(!(s01e0 < 0 && s01e1 > 0 && s02e0 > 0 && s02e2 < 0 &&
             s12e1 < 0 && s12e2 > 0))
          continue;

        MVertex *r =
          getOrCreateRegionSpawn(p, gr, intersectCornerRegionSpawns, &spawned);
        intersectRegionSpawns[std::make_pair(std::make_pair(gr, e0), a)] = r;
        intersectRegionSpawns[std::make_pair(std::make_pair(gr, e1), b)] = r;
        intersectRegionSpawns[std::make_pair(std::make_pair(gr, e2), c)] = r;
        break;
      } while(std::next_permutation(perm.begin(), perm.end()));
    }
  }

  for(auto ge : intersectEdgesSet) {
    std::vector<GFace *> faces =
      boundaryLayerFacesOnEdge(ge, onSurfacesSet);
    if(faces.size() != 2) {
      Msg::Warning("BoundaryLayer IntersectEdge %d has %zu adjacent boundary "
                   "layer faces; expected 2",
                   ge ? ge->tag() : 0, faces.size());
      continue;
    }

    GFace *faceA = faces[0];
    GFace *faceB = faces[1];
    std::vector<GRegion *> volumes =
      boundaryLayerVolumesOnEdgeFaces(ge, faceA, faceB, inVolumesSet);
    if(volumes.empty()) {
      Msg::Warning("BoundaryLayer IntersectEdge %d: could not find a boundary "
                   "layer volume adjacent to faces %d and %d",
                   ge->tag(), faceA->tag(), faceB->tag());
      continue;
    }

    for(auto line : ge->lines) {
      MVertex *v0 = line->getVertex(0);
      MVertex *v1 = line->getVertex(1);
      if(skipIntersectSurfaceLines.find(MEdge(v0, v1)) !=
         skipIntersectSurfaceLines.end())
        continue;
      MVertex *a0 =
        getOrCreateFaceSpawn(v0, faceA, intersectFaceSpawns);
      MVertex *a1 =
        getOrCreateFaceSpawn(v1, faceA, intersectFaceSpawns);
      MVertex *b0 =
        getOrCreateFaceSpawn(v0, faceB, intersectFaceSpawns);
      MVertex *b1 =
        getOrCreateFaceSpawn(v1, faceB, intersectFaceSpawns);
      if(!a0 || !a1 || !b0 || !b1) {
        Msg::Warning("BoundaryLayer IntersectEdge %d: could not create face "
                     "nodes on faces %d and %d",
                     ge->tag(), faceA->tag(), faceB->tag());
        continue;
      }

      for(auto gr : volumes) {
        GFace *hexFaceA = faceA;
        GFace *hexFaceB = faceB;
        MVertex *ha0 = a0;
        MVertex *ha1 = a1;
        MVertex *hb0 = b0;
        MVertex *hb1 = b1;

        const OriginalVolumeFaceOrders &orders =
          originalVolumeFaceOrders[gr];
        auto topoVertex = [&intersectCornerOrigins](MVertex *v) {
          auto it = intersectCornerOrigins.find(v);
          return it == intersectCornerOrigins.end() ? v : it->second;
        };
        MVertex *topoV0 = topoVertex(v0);
        MVertex *topoV1 = topoVertex(v1);
        int signA = originalVolumeFaceEdgeSignOnModelFace(
          orders, faceA, topoV0, topoV1);
        int signB = originalVolumeFaceEdgeSignOnModelFace(
          orders, faceB, topoV0, topoV1);
        if(signA > 0 && signB < 0) {
          std::swap(hexFaceA, hexFaceB);
          std::swap(ha0, hb0);
          std::swap(ha1, hb1);
          std::swap(signA, signB);
        }
        else if(!(signA < 0 && signB > 0)) {
          Msg::Warning("BoundaryLayer IntersectEdge %d in region %d: could "
                       "not orient adjacent faces topologically on segment "
                       "(%zu,%zu) (signs %d/%d)",
                       ge->tag(), gr->tag(), v0->getNum(), v1->getNum(),
                       signA, signB);
        }

        MVertex *s0 =
          getOrCreateIntersectEdgeRegionSpawn(v0, gr, ge,
                                              intersectRegionSpawns);
        MVertex *s1 =
          getOrCreateIntersectEdgeRegionSpawn(v1, gr, ge,
                                              intersectRegionSpawns);
        pushUniqueSpawn(spawned, v0, s0);
        pushUniqueSpawn(spawned, v1, s1);
        pushUniqueSpawn(spawned, ha0, s0);
        pushUniqueSpawn(spawned, ha1, s1);
        pushUniqueSpawn(spawned, hb0, s0);
        pushUniqueSpawn(spawned, hb1, s1);

        MHexahedron *h =
          new MHexahedron(v0, v1, ha1, ha0, hb0, hb1, s1, s0);
        gr->hexahedra.push_back(h);
        layers[h] = thickness;
        skipVolumeReplacementElements.insert(h);
        if(intersectEdgeHexes) {
          BoundaryLayerIntersectEdgeHex meta;
          meta.ge = ge;
          meta.faceA = hexFaceA;
          meta.faceB = hexFaceB;
          meta.gr = gr;
          meta.p0 = v0;
          meta.p1 = v1;
          meta.a0 = ha0;
          meta.a1 = ha1;
          meta.s0 = s0;
          meta.s1 = s1;
          meta.b0 = hb0;
          meta.b1 = hb1;
          (*intersectEdgeHexes)[h] = meta;
        }
      }
    }

    replaceFaceElementsAlongIntersectEdge(faceA, ge, intersectFaceSpawns,
                                          &skipIntersectSurfaceLines,
                                          &intersectCornerOrigins,
                                          &skipSourceElements);
    replaceFaceElementsAlongIntersectEdge(faceB, ge, intersectFaceSpawns,
                                          &skipIntersectSurfaceLines,
                                          &intersectCornerOrigins,
                                          &skipSourceElements);

    addIntersectEdgeSurfaceQuads(faceA, ge, intersectFaceSpawns, thickness,
                                 layers, skipSourceElements,
                                 &skipIntersectSurfaceLines);
    addIntersectEdgeSurfaceQuads(faceB, ge, intersectFaceSpawns, thickness,
                                 layers, skipSourceElements,
                                 &skipIntersectSurfaceLines);
    toExpand.push_back(faceA);
    toExpand.push_back(faceB);
  }

  for(auto &corner : pendingIntersectCornerQuads) {
    if(!corner.gf || !corner.p || !corner.a || !corner.s || !corner.b)
      continue;
    MQuadrangle *q = new MQuadrangle(corner.p, corner.a, corner.s, corner.b);
    corner.gf->quadrangles.push_back(q);
    layers[q] = thickness;
    skipSourceElements.insert(q);
    if(cornerBLQuads) (*cornerBLQuads)[q] = corner;
  }

  for(auto gv : intersectEdgeVertices) {
    if(!gv || gv->mesh_vertices.empty()) continue;
    MVertex *p = gv->mesh_vertices[0];
    for(auto gr : inVolumesSet) {
      std::vector<GEdge *> cornerEdges;
      for(auto ge : gv->edges()) {
        if(intersectEdgesSet.find(ge) == intersectEdgesSet.end()) continue;
        if(ge->getBeginVertex() != gv && ge->getEndVertex() != gv) continue;
        if(!edgeIsInRegion(ge, gr)) continue;
        cornerEdges.push_back(ge);
      }
      if(cornerEdges.empty()) continue;
      if(cornerEdges.size() != 3) {
        Msg::Warning("BoundaryLayer IntersectEdge corner point %d in region "
                     "%d has %zu adjacent intersect edges; expected 3",
                     gv->tag(), gr->tag(), cornerEdges.size());
        continue;
      }

      std::array<GEdge *, 3> selectedEdges = {nullptr, nullptr, nullptr};
      std::array<GFace *, 3> selectedFaces = {nullptr, nullptr, nullptr};
      std::array<MVertex *, 3> selectedEdgeVertices = {nullptr, nullptr,
                                                       nullptr};
      std::array<int, 3> perm = {0, 1, 2};
      bool foundCorner = false;
      const OriginalVolumeFaceOrders &orders = originalVolumeFaceOrders[gr];
      do {
        GEdge *e0 = cornerEdges[perm[0]];
        GEdge *e1 = cornerEdges[perm[1]];
        GEdge *e2 = cornerEdges[perm[2]];
        GFace *f01 =
          boundaryLayerFaceOnEdgePair(gv, e0, e1, onSurfacesSet, gr);
        GFace *f02 =
          boundaryLayerFaceOnEdgePair(gv, e0, e2, onSurfacesSet, gr);
        GFace *f12 =
          boundaryLayerFaceOnEdgePair(gv, e1, e2, onSurfacesSet, gr);
        if(!f01 || !f02 || !f12) continue;
        MVertex *a = intersectCornerVertices[std::make_pair(gv, e0)];
        MVertex *b = intersectCornerVertices[std::make_pair(gv, e1)];
        MVertex *c = intersectCornerVertices[std::make_pair(gv, e2)];
        if(!a || !b || !c) continue;
        MVertex *r0 = firstMeshVertexAwayFromModelCorner(gv, e0);
        MVertex *r1 = firstMeshVertexAwayFromModelCorner(gv, e1);
        MVertex *r2 = firstMeshVertexAwayFromModelCorner(gv, e2);
        if(!r0 || !r1 || !r2) continue;
        const int s01e0 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f01, p, r0);
        const int s01e1 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f01, p, r1);
        const int s02e0 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f02, p, r0);
        const int s02e2 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f02, p, r2);
        const int s12e1 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f12, p, r1);
        const int s12e2 =
          originalVolumeFaceEdgeSignOnModelFace(orders, f12, p, r2);
        if(!(s01e0 < 0 && s01e1 > 0 && s02e0 > 0 && s02e2 < 0 &&
             s12e1 < 0 && s12e2 > 0))
          continue;
        selectedEdges = {e0, e1, e2};
        selectedFaces = {f01, f02, f12};
        selectedEdgeVertices = {a, b, c};
        foundCorner = true;
        break;
      } while(std::next_permutation(perm.begin(), perm.end()));

      if(!foundCorner) {
        Msg::Warning("BoundaryLayer IntersectEdge corner point %d in region "
                     "%d: could not identify a topological corner hexahedron",
                     gv->tag(), gr->tag());
        continue;
      }

      GEdge *e0 = selectedEdges[0];
      GEdge *e1 = selectedEdges[1];
      GEdge *e2 = selectedEdges[2];
      GFace *f01 = selectedFaces[0];
      GFace *f02 = selectedFaces[1];
      GFace *f12 = selectedFaces[2];
      MVertex *a = selectedEdgeVertices[0];
      MVertex *b = selectedEdgeVertices[1];
      MVertex *c = selectedEdgeVertices[2];
      MVertex *sab = getOrCreateFaceSpawn(p, f01, intersectFaceSpawns);
      MVertex *sac = getOrCreateFaceSpawn(p, f02, intersectFaceSpawns);
      MVertex *sbc = getOrCreateFaceSpawn(p, f12, intersectFaceSpawns);
      MVertex *r =
        getOrCreateRegionSpawn(p, gr, intersectCornerRegionSpawns, &spawned);
      if(!a || !b || !c || !sab || !sac || !sbc || !r) continue;

      intersectRegionSpawns[std::make_pair(std::make_pair(gr, e0), a)] = r;
      intersectRegionSpawns[std::make_pair(std::make_pair(gr, e1), b)] = r;
      intersectRegionSpawns[std::make_pair(std::make_pair(gr, e2), c)] = r;

      pushUniqueSpawn(spawned, p, r);
      pushUniqueSpawn(spawned, sab, r);
      pushUniqueSpawn(spawned, sac, r);
      pushUniqueSpawn(spawned, sbc, r);

      MHexahedron *h = new MHexahedron(p, a, sab, b, c, sac, r, sbc);
      gr->hexahedra.push_back(h);
      layers[h] = thickness;
      skipVolumeReplacementElements.insert(h);
      if(intersectCornerHexes) {
        BoundaryLayerIntersectCornerHex meta;
        meta.gv = gv;
        meta.gr = gr;
        meta.edge0 = e0;
        meta.edge1 = e1;
        meta.edge2 = e2;
        meta.face01 = f01;
        meta.face02 = f02;
        meta.face12 = f12;
        meta.p = p;
        meta.a = a;
        meta.b = b;
        meta.c = c;
        meta.sab = sab;
        meta.sac = sac;
        meta.sbc = sbc;
        meta.r = r;
        (*intersectCornerHexes)[h] = meta;
      }
    }
  }

  std::map<MVertex *, MVertex *> spawnOrigins;
  for(const auto &it : spawned)
    for(auto v : it.second) spawnOrigins[v] = it.first;
  for(const auto &it : intersectFaceSpawns) spawnOrigins[it.second] = it.first.second;
  for(const auto &it : intersectRegionSpawns) spawnOrigins[it.second] = it.first.second;
  for(const auto &it : intersectCornerRegionSpawns)
    spawnOrigins[it.second] = it.first.second;
  for(const auto &it : intersectCornerOrigins) spawnOrigins[it.first] = it.second;

  for(auto gr : inVolumes) {
    const OriginalVolumeFaceOrders &orders = originalVolumeFaceOrders[gr];
    for(std::size_t i = 0; i < gr->getNumMeshElements(); ++i) {
      MElement *e = gr->getMeshElement(i);
      if(layers.find(e) == layers.end()) continue;
      if(e->getDim() != 3) continue;
      if(intersectEdgeHexes && intersectEdgeHexes->find(e) !=
                                intersectEdgeHexes->end())
        continue;
      if(intersectCornerHexes && intersectCornerHexes->find(e) !=
                                  intersectCornerHexes->end())
        continue;
      orientBoundaryLayerElementFromOriginalVolumeFaces(e, orders,
                                                        spawnOrigins);
    }
  }

  std::map<std::pair<GRegion *, MVertex *>, MVertex *> preferredRegionSpawns;
  for(const auto &it : intersectRegionSpawns)
    preferredRegionSpawns[std::make_pair(it.first.first.first,
                                         it.first.second)] = it.second;
  for(const auto &it : intersectCornerRegionSpawns)
    preferredRegionSpawns[it.first] = it.second;

  // Create Elements

  for(auto gr : inVolumes) {
    for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      if(skipVolumeReplacementElements.find(e) !=
         skipVolumeReplacementElements.end())
        continue;
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *source = e->getVertex(j);
        auto sp = spawned[source];
        MVertex *replacement = nullptr;
        auto itPreferred =
          preferredRegionSpawns.find(std::make_pair(gr, source));
        if(itPreferred != preferredRegionSpawns.end())
          replacement = itPreferred->second;
        for(auto v : sp) {
          if(replacement) break;
          if(v->onWhat() == gr) {
            replacement = v;
            break;
          }
        }
        if(!replacement) {
          for(auto v : sp) {
            if(v->onWhat()->dim() == 3) {
              replacement = v;
              break;
            }
          }
        }
        if(!replacement) {
          for(auto v : sp) {
            if(v->onWhat()->dim() < 3) {
              replacement = v;
              break;
            }
          }
        }
        if(replacement) e->setVertex(j, replacement);
      }
    }
  }

  for(auto f2r : facesEmbeddedInRegions) {
    GFace *embeddedFace = f2r.first;
    for(auto gr : f2r.second) {
      std::pair<GFace *, GRegion *> key = std::make_pair(embeddedFace, gr);
      const std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns =
        embeddedCurveFaceSpawns.facesInRegions[key];
      for(std::size_t i = 0; i < embeddedFace->getNumMeshElements(); i++) {
        MElement *element = embeddedFace->getMeshElement(i);
        if(element->getDim() != 2) continue;
        for(int side = 0; side < 2; side++)
          addEmbeddedFaceRegionElement(gr, element, vertexSpawns, side,
                                       thickness, layers,
                                       originalVolumeFaceOrders[gr],
                                       spawnOrigins);
      }
    }
  }

  std::set<GFace *> surfacesAdjacentToVolumesForBoundaryLayer;
  for(auto gr : inVolumes) {
    auto fs = gr->faces();
    surfacesAdjacentToVolumesForBoundaryLayer.insert(fs.begin(), fs.end());
  }

  for(auto gf : surfacesAdjacentToVolumesForBoundaryLayer) {
    if(onSurfacesSet.find(gf) != onSurfacesSet.end()) continue;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto sp = spawned[e->getVertex(j)];
        for(auto v : sp) {
          if(v->onWhat() == gf || v->onWhat()->dim() == 1) {
            e->setVertex(j, v);
          }
        }
      }
    }
  }

  for(auto e2f : edgesEmbeddedInFaces) {
    GEdge *emb = e2f.first;
    for(auto gf : e2f.second) {
      std::pair<GEdge *, GFace *> key = std::make_pair(emb, gf);
      const std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns =
        embeddedCurveFaceSpawns.curvesInFaces[key];
      const std::map<MVertex *, EmbeddedElementSides> &vertexSides =
        embeddedElementSideData.curvesInFaces[key];
      for(auto line : emb->lines) {
        MVertex *v0 = line->getVertex(0);
        MVertex *v1 = line->getVertex(1);
        auto it0 = vertexSpawns.find(v0);
        auto it1 = vertexSpawns.find(v1);
        if(it0 == vertexSpawns.end() || it1 == vertexSpawns.end()) {
          Msg::Warning("Could not find embedded boundary layer node for "
                       "node(s) %zu and/or %zu",
                       v0->getNum(), v1->getNum());
          continue;
        }
        for(int side = 0; side < 2; side++) {
          MVertex *sv0 = it0->second.side[side];
          MVertex *sv1 = it1->second.side[side];
          if(!sv0 || !sv1) continue;
          MEdge sideEdge =
            findSideElementEdge(vertexSides, v0, v1, sv0, sv1, side);
          if(!sideEdge.getVertex(0)) {
            Msg::Warning("Could not find side %d edge for embedded curve %d "
                         "in face %d",
                         side, emb->tag(), gf->tag());
            continue;
          }
          addEmbeddedCurveFaceQuadrangle(gf, line, sv0, sv1, sideEdge,
                                         thickness, layers);
        }
      }
    }
  }

  // create zero-sized elements in connected surfaces

  std::set<GEdge *> onCurves;
  for(auto gf : onSurfaces) {
    auto es = gf->edges();
    onCurves.insert(es.begin(), es.end());
  }

  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      std::set<MEdge, MEdgeLessThan> edges_of_elements;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumEdges(); j++)
          edges_of_elements.insert(e->getEdge(j));
      }

      if(onSurfacesSet.find(gf) != onSurfacesSet.end()) continue;
      if(surfacesAdjacentToVolumesForBoundaryLayer.find(gf) ==
         surfacesAdjacentToVolumesForBoundaryLayer.end())
        continue;

      toExpand.push_back(gf);

      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%zu and/or %zu",
                       l->getVertex(0)->getNum(), l->getVertex(1)->getNum());
        }
        else {
          std::vector<MVertex *> V0, V1;
          for(auto V : sp0)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V0.push_back(V);
            }
          for(auto V : sp1)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V1.push_back(V);
            }
          // There can be several vertices for the same face -- in case of
          // embedded edges. Assume that points are spawned on one side and then
          // on the other in the same order.
          if(V0.size() != V1.size())
            Msg::Error("Error Boundary Layer %zu %zu", V0.size(), V1.size());
          for(size_t j = 0; j < V0.size(); j++) {
            std::set<MEdge, MEdgeLessThan>::iterator it =
              edges_of_elements.find(MEdge(V1[j], V0[j]));
            if(it == edges_of_elements.end()) {
              Msg::Error("Edge not found in boundary layer");
            }
            else {
              // orientation matters !!!
              if(it->getVertex(0) == V0[j])
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(0), l->getVertex(1), V1[j], V0[j]));
              else
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(1), l->getVertex(0), V0[j], V1[j]));
              layers[gf->quadrangles.back()] = thickness;
            }
          }
        }
      }
    }
  }

  ///---------------------------------------------------------
  ///// ----> TREAT FACES -- creat prismatic layers
  ///---------------------------------------------------------

  for(auto gf : onSurfaces) {
    std::map<MVertex *, MVertex *> v2v;
    auto eds = gf->edges();
    auto vol = gf->regions();
    for(auto gr : vol) {
      if(inVolumesSet.find(gr) == inVolumesSet.end()) continue;
      for(std::size_t j = 0; j < gf->getNumMeshElements(); j++) {
        MElement *e = gf->getMeshElement(j);
        if(skipSourceElements.find(e) != skipSourceElements.end()) continue;
        if(layers.find(e) != layers.end()) continue;
        int type = e->getTypeForMSH();
        if(type != MSH_TRI_3 && type != MSH_QUA_4) continue;
        std::size_t n = (type == MSH_TRI_3) ? 3 : 4;
        MVertex *vs[4] = {nullptr, nullptr, nullptr, nullptr};
        MVertex *bs[4] = {nullptr, nullptr, nullptr, nullptr};
        for(size_t i = 0; i < n; i++) {
          vs[i] = e->getVertex(i);
          std::map<MVertex *, MVertex *>::iterator it = v2v.find(vs[i]);
          std::map<MVertex *, std::vector<MVertex *>>::iterator its =
            spawned.find(vs[i]);
          if(it != v2v.end())
            bs[i] = it->second;
          else if(its != spawned.end() && its->second.size()) {
            for(auto vv : its->second) {
              if(vv->onWhat() == gr) {
                bs[i] = vv;
                break;
              }
            }
            if(!bs[i]) {
              for(auto vv : its->second) {
                if(vv->onWhat()->dim() == 3) {
                  bs[i] = vv;
                  break;
                }
              }
            }
          }
        }

        auto spawnFor = [&](MVertex *v) -> MVertex * {
          for(std::size_t ii = 0; ii < n; ++ii)
            if(getOriginalVertex(vs[ii], &spawnOrigins) == v) return bs[ii];
          return nullptr;
        };
        auto currentFor = [&](MVertex *v) -> MVertex * {
          for(std::size_t ii = 0; ii < n; ++ii)
            if(getOriginalVertex(vs[ii], &spawnOrigins) == v) return vs[ii];
          return nullptr;
        };
        std::vector<MVertex *> originalOrder;
        bool haveOriginalOrder =
          findOriginalVolumeFaceOrder(originalVolumeFaceOrders[gr], e,
                                      &spawnOrigins, originalOrder);

        if(type == MSH_TRI_3 && bs[0] && bs[1] && bs[2]) {
          if(haveOriginalOrder && originalOrder.size() == 3) {
            MVertex *v0 = currentFor(originalOrder[0]);
            MVertex *v1 = currentFor(originalOrder[1]);
            MVertex *v2 = currentFor(originalOrder[2]);
            MVertex *b0 = spawnFor(originalOrder[0]);
            MVertex *b1 = spawnFor(originalOrder[1]);
            MVertex *b2 = spawnFor(originalOrder[2]);
            if(!v0 || !v1 || !v2 || !b0 || !b1 || !b2) continue;
            gr->prisms.push_back(newBoundaryLayerPrism(
              v0, v1, v2, b0, b1, b2));
          }
          else {
            if(!hasDistinctOriginalVertices(e, &spawnOrigins)) continue;
            Msg::Warning("BoundaryLayer: could not find original volume face "
                         "orientation for triangle on face %d in region %d",
                         gf ? gf->tag() : 0, gr ? gr->tag() : 0);
            continue;
          }
          layers[gr->prisms.back()] = thickness;
        }
        else if(type == MSH_QUA_4 && bs[0] && bs[1] && bs[2] && bs[3]) {
          if(haveOriginalOrder && originalOrder.size() == 4) {
            MVertex *v0 = currentFor(originalOrder[0]);
            MVertex *v1 = currentFor(originalOrder[1]);
            MVertex *v2 = currentFor(originalOrder[2]);
            MVertex *v3 = currentFor(originalOrder[3]);
            MVertex *b0 = spawnFor(originalOrder[0]);
            MVertex *b1 = spawnFor(originalOrder[1]);
            MVertex *b2 = spawnFor(originalOrder[2]);
            MVertex *b3 = spawnFor(originalOrder[3]);
            if(!v0 || !v1 || !v2 || !v3 || !b0 || !b1 || !b2 || !b3)
              continue;
            gr->hexahedra.push_back(newBoundaryLayerHex(
              v0, v1, v2, v3, b0, b1, b2, b3));
          }
          else {
            if(!hasDistinctOriginalVertices(e, &spawnOrigins)) continue;
            Msg::Warning("BoundaryLayer: could not find original volume face "
                         "orientation for quadrangle on face %d in region %d",
                         gf ? gf->tag() : 0, gr ? gr->tag() : 0);
            continue;
          }
          layers[gr->hexahedra.back()] = thickness;
        }
        else {
          Msg::Error("Impossible to create %zu-node element in BL (%d,%d) "
                     "(%d,%d) (%d,%d) (%d,%d) %p %p %p %p",
                     n, vs[0]->onWhat()->dim(), vs[0]->onWhat()->tag(),
                     vs[1]->onWhat()->dim(), vs[1]->onWhat()->tag(),
                     vs[2]->onWhat()->dim(), vs[2]->onWhat()->tag(),
                     n == 4 ? vs[3]->onWhat()->dim() : -1,
                     n == 4 ? vs[3]->onWhat()->tag() : -1, bs[0], bs[1], bs[2],
                     bs[3]);
        }
      }
    }
  }

  return true;
}

bool bl(GModel *m, std::vector<GVertex *> &onPoints,
        std::vector<GEdge *> &onCurves, std::vector<GFace *> &inSurfaces,
        double thickness, std::map<MElement *, double> &layers,
        std::map<MElement *, BoundaryLayerCornerQuad> *cornerBLQuads)
{
  // 2D case:
  // for each GVertex connected to the GEdges in onCurves:
  //   - if all adjacent GEdges to the GVertex are in onCurves, spawn 1 MVertex
  //     in each GFace connected to the GVertex that are in inSurfaces
  //   - if some adjacent GEdges are not in onCurves, spawn 1 MVertex on each
  //     connected GEdge
  // for each MVertex classified on the GEdges in onCurves:
  //   - spawn 1 MVertex in the connected GFaces that are in inSurfaces

  std::set<GEdge *> onCurvesSet;
  onCurvesSet.insert(onCurves.begin(), onCurves.end());

  std::set<GFace *> inSurfacesSet;
  inSurfacesSet.insert(inSurfaces.begin(), inSurfaces.end());

  std::map<MVertex *, std::vector<MVertex *>> spawned;
  std::set<GVertex *> intersectPoints(onPoints.begin(), onPoints.end());
  std::map<std::pair<GVertex *, GEdge *>, MVertex *> insertedCornerVertices;
  std::map<std::pair<GFace *, MVertex *>, MVertex *> forcedFaceSpawns;
  std::set<MEdge, MEdgeLessThan> skipBoundaryLayerLines;
  std::vector<BoundaryLayerCornerQuad> pendingCornerQuads;

  std::set<GVertex *> connectedPoints;
  for(auto ge : onCurves) {
    auto vs = ge->vertices();
    connectedPoints.insert(vs.begin(), vs.end());
  }

  // spawn nodes for model points
  for(auto gv : connectedPoints) {
    if(gv->mesh_vertices.empty()) {
      Msg::Error("No mesh node on model point %d - abort!", gv->tag());
      return false;
    }

    std::vector<GEdge *> connectedCurves = gv->edges();
    std::vector<GFace *> connectedSurfaces = gv->faces();
    std::vector<GEdge *> toinsert;
    std::size_t found = 0;
    for(auto ge : connectedCurves) {
      if(onCurvesSet.find(ge) != onCurvesSet.end()) { found++; }
      else {
        toinsert.push_back(ge);
      }
    }

    if(intersectPoints.find(gv) != intersectPoints.end()) {
      MVertex *v = gv->mesh_vertices[0];
      for(auto gf : connectedSurfaces) {
        if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
        std::vector<GEdge *> cornerEdges =
          boundaryLayerCurvesInFace(gv, gf, onCurvesSet);
        if(cornerEdges.size() != 2) {
          if(!cornerEdges.empty())
            Msg::Warning("BoundaryLayer IntersectPoint %d on face %d has "
                         "%zu adjacent boundary layer curves; expected 2",
                         gv->tag(), gf->tag(), cornerEdges.size());
          continue;
        }

        MVertex *faceSpawn = findSpawnOnEntity(spawned, v, gf);
        if(!faceSpawn) {
          SPoint2 param;
          if(reparamMeshVertexOnFace(v, gf, param)) {
            faceSpawn = new MFaceVertex(v->x(), v->y(), v->z(), gf,
                                        param.x(), param.y());
            gf->mesh_vertices.push_back(faceSpawn);
            pushUniqueSpawn(spawned, v, faceSpawn);
          }
          else {
            Msg::Warning("Could not compute parametric coordinates of "
                         "IntersectPoint %d on surface %d",
                         gv->tag(), gf->tag());
            continue;
          }
        }

        MVertex *a =
          insertCornerBoundaryLayerVertex(gv, cornerEdges[0],
                                          thickness,
                                          insertedCornerVertices);
        MVertex *b =
          insertCornerBoundaryLayerVertex(gv, cornerEdges[1],
                                          thickness,
                                          insertedCornerVertices);
        if(!a || !b) continue;

        forcedFaceSpawns[std::make_pair(gf, a)] = faceSpawn;
        forcedFaceSpawns[std::make_pair(gf, b)] = faceSpawn;
        skipBoundaryLayerLines.insert(MEdge(v, a));
        skipBoundaryLayerLines.insert(MEdge(v, b));

        BoundaryLayerCornerQuad corner;
        corner.gv = gv;
        corner.gf = gf;
        corner.edgeA = cornerEdges[0];
        corner.edgeB = cornerEdges[1];
        corner.p = v;
        corner.a = a;
        corner.s = faceSpawn;
        corner.b = b;
        pendingCornerQuads.push_back(corner);
      }
    }

    // All edges adjacent to this model edge are in the boundart layer
    // thus we only add one point on the face -- the strategy here is
    // to possibly add "fans" in a second stage as another "plugin"
    if(found == connectedCurves.size()) {
      for(auto gf : connectedSurfaces) {
        if(inSurfacesSet.find(gf) != inSurfacesSet.end()) {
          MVertex *v = gv->mesh_vertices[0];
          MVertex *newv = findSpawnOnEntity(spawned, v, gf);
          if(newv) {
            Msg::Debug("reusing node %zu from point %d in surface %d",
                       newv->getNum(), gv->tag(), gf->tag());
          }
          else {
            SPoint2 param;
            if(reparamMeshVertexOnFace(v, gf, param)) {
              newv =
                new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
              gf->mesh_vertices.push_back(newv);
              pushUniqueSpawn(spawned, v, newv);
              Msg::Debug("inserted node %zu from point %d in surface %d",
                         newv->getNum(), gv->tag(), gf->tag());
            }
            else {
              Msg::Warning("Could not compute parametric coordinates of node on "
                           "surface %d - maybe on seam?",
                           gf->tag());
            }
          }
        }
      }
    }
    // insert a boundary layer node in every connected edge that is NOT
    // on the boundary layer -- this includes "slip" walls and embedded edges
    else {
      for(auto ge : toinsert) {
        MVertex *v = gv->mesh_vertices[0];
        double param;
        if(reparamMeshVertexOnEdge(v, ge, param)) {
          bool end = ge->getEndVertex() == gv;
          MVertex *newv;
          if(end) {
            MEdgeVertex *vend =
              static_cast<MEdgeVertex *>(ge->mesh_vertices.back());
            newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, 0,
                                   vend->getLc());
            ge->mesh_vertices.push_back(newv);
          }
          else {
            MEdgeVertex *vbeg =
              static_cast<MEdgeVertex *>(ge->mesh_vertices.front());
            newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, 0,
                                   vbeg->getLc());
            ge->mesh_vertices.insert(ge->mesh_vertices.begin(), newv);
          }

          pushUniqueSpawn(spawned, v, newv);
          Msg::Debug(
            "inserted node %zu from point %d in curve %d -- %zu internal nodes",
            newv->getNum(), gv->tag(), ge->tag(), ge->mesh_vertices.size());
          if(end) {
            ge->lines.back()->setVertex(1, newv);
            ge->lines.push_back(new MLine(newv, v));
          }
          else
            ge->lines.insert(ge->lines.begin(), new MLine(newv, v));
        }
        else {
          Msg::Warning("Could not compute parametric coordinates of node on "
                       "curve %d",
                       ge->tag());
        }
      }
    }
  }

  // spawn nodes for model curves
  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(auto v : ge->mesh_vertices) {
        auto forced = forcedFaceSpawns.find(std::make_pair(gf, v));
        if(forced != forcedFaceSpawns.end()) {
          pushUniqueSpawn(spawned, v, forced->second);
          continue;
        }
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)) {
          MVertex *newv =
            new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
          gf->mesh_vertices.push_back(newv);
          pushUniqueSpawn(spawned, v, newv);
        }
      }
    }
  }

  // Embedded Stuff
  // ------------------------------------------------------------------------
  std::map<GVertex *, std::vector<GFace *>>
    verticesEmbeddedInFacesAsCurveEndpoints;
  std::map<GEdge *, std::vector<GFace *>> edgesEmbeddedInFaces;
  std::map<GEdge *, std::vector<GRegion *>> edgesEmbeddedInRegions;
  std::map<GFace *, std::vector<GRegion *>> facesEmbeddedInRegions;
  getEmbeddedStructure(m, verticesEmbeddedInFacesAsCurveEndpoints,
                       edgesEmbeddedInFaces, edgesEmbeddedInRegions,
                       facesEmbeddedInRegions);

  EmbeddedElementSideData embeddedElementSideData;
  buildEmbeddedElementSideData(edgesEmbeddedInFaces, facesEmbeddedInRegions,
                               embeddedElementSideData);
  EmbeddedCurveFaceSpawns embeddedCurveFaceSpawns;

  for(auto v2f : verticesEmbeddedInFacesAsCurveEndpoints) {
    for(auto gf : v2f.second) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      if(_debugBL3D)
        printf(" --EMP  Vertex %d embedded in Face %d\n", v2f.first->tag(),
               gf->tag());
    }
  }

  for(auto e2f : edgesEmbeddedInFaces) {
    GEdge *emb = e2f.first;
    for(auto gf : e2f.second) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      if(_debugBL3D)
        printf(" --EMP  Edge %d embedded in Face %d\n", emb->tag(), gf->tag());

      std::pair<GEdge *, GFace *> key = std::make_pair(emb, gf);
      std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns =
        embeddedCurveFaceSpawns.curvesInFaces[key];
      const std::map<MVertex *, EmbeddedElementSides> &vertexSides =
        embeddedElementSideData.curvesInFaces[key];

      MVertex *begin = emb->getBeginVertex()->mesh_vertices.empty() ?
                         nullptr :
                         emb->getBeginVertex()->mesh_vertices[0];
      MVertex *end = emb->getEndVertex()->mesh_vertices.empty() ?
                       nullptr :
                       emb->getEndVertex()->mesh_vertices[0];
      MVertex *endPoints[2] = {begin, end};
      for(int i = 0; i < 2; i++) {
        MVertex *v = endPoints[i];
        if(!v) continue;
        MVertex *newv = nullptr;
        auto it = spawned.find(v);
        if(it != spawned.end()) {
          for(auto sp : it->second) {
            if(sp->onWhat() == gf) {
              newv = sp;
              break;
            }
          }
        }
        if(!newv) {
          newv = createMFaceVertex(v, gf);
          if(newv) spawned[v].push_back(newv);
        }
        vertexSpawns[v].side[0] = newv;
        vertexSpawns[v].side[1] = newv;
      }

      for(auto v : emb->mesh_vertices) {
        for(int side = 0; side < 2; side++)
          vertexSpawns[v].side[side] = createMFaceVertex(v, gf);
      }

      replaceEmbeddedCurveFaceVertices(gf, vertexSides, vertexSpawns);
    }
  }
  // Embedded Stuff
  // ------------------------------------------------------------------------

  std::set<GEntity *> modified;
  for(auto vv : spawned)
    for(auto v : vv.second) modified.insert(v->onWhat());

  for(auto gf : inSurfaces) {
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto sp = spawned[e->getVertex(j)];
        for(auto v : sp) {
          if(v->onWhat() == gf || v->onWhat()->dim() == 1) {
            e->setVertex(j, v);
          }
        }
      }
    }
  }

  for(auto &corner : pendingCornerQuads) {
    if(!corner.gf || !corner.p || !corner.a || !corner.s || !corner.b)
      continue;
    MQuadrangle *q = new MQuadrangle(corner.p, corner.a, corner.s, corner.b);
    corner.gf->quadrangles.push_back(q);
    layers[q] = thickness;
    if(cornerBLQuads) (*cornerBLQuads)[q] = corner;
  }

  for(auto e2f : edgesEmbeddedInFaces) {
    GEdge *emb = e2f.first;
    for(auto gf : e2f.second) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      std::pair<GEdge *, GFace *> key = std::make_pair(emb, gf);
      const std::map<MVertex *, EmbeddedVertexSpawns> &vertexSpawns =
        embeddedCurveFaceSpawns.curvesInFaces[key];
      const std::map<MVertex *, EmbeddedElementSides> &vertexSides =
        embeddedElementSideData.curvesInFaces[key];
      for(auto line : emb->lines) {
        MVertex *v0 = line->getVertex(0);
        MVertex *v1 = line->getVertex(1);
        auto it0 = vertexSpawns.find(v0);
        auto it1 = vertexSpawns.find(v1);
        if(it0 == vertexSpawns.end() || it1 == vertexSpawns.end()) {
          Msg::Warning("Could not find embedded boundary layer node for "
                       "node(s) %zu and/or %zu",
                       v0->getNum(), v1->getNum());
          continue;
        }
        for(int side = 0; side < 2; side++) {
          MVertex *sv0 = it0->second.side[side];
          MVertex *sv1 = it1->second.side[side];
          if(!sv0 || !sv1) continue;
          MEdge sideEdge =
            findSideElementEdge(vertexSides, v0, v1, sv0, sv1, side);
          if(!sideEdge.getVertex(0)) {
            Msg::Warning("Could not find side %d edge for embedded curve %d "
                         "in face %d",
                         side, emb->tag(), gf->tag());
            continue;
          }
          addEmbeddedCurveFaceQuadrangle(gf, line, sv0, sv1, sideEdge,
                                         thickness, layers);
        }
      }
    }
  }

  // create zero-sized elements in connected surfaces
  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      std::set<MEdge, MEdgeLessThan> edges_of_elements;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumEdges(); j++)
          edges_of_elements.insert(e->getEdge(j));
      }

      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        if(skipBoundaryLayerLines.find(
             MEdge(l->getVertex(0), l->getVertex(1))) !=
           skipBoundaryLayerLines.end())
          continue;
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%zu and/or %zu",
                       l->getVertex(0)->getNum(), l->getVertex(1)->getNum());
        }
        else {
          std::vector<MVertex *> V0, V1;
          for(auto V : sp0)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V0.push_back(V);
            }
          for(auto V : sp1)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V1.push_back(V);
            }
          // There can be several vertices for the same face -- in case of
          // embedded edges. Assume that points are spawned on one side and then
          // on the other in the same order.
          if(V0.size() != V1.size())
            Msg::Error("Error Boundary Layer %zu %zu", V0.size(), V1.size());
          for(size_t j = 0; j < V0.size(); j++) {
            std::set<MEdge, MEdgeLessThan>::iterator it =
              edges_of_elements.find(MEdge(V1[j], V0[j]));
            if(it == edges_of_elements.end()) {
              Msg::Error("Edge not found in boundary layer");
            }
            else {
              // orientation matters !!!
              if(it->getVertex(0) == V0[j])
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(0), l->getVertex(1), V1[j], V0[j]));
              else
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(1), l->getVertex(0), V0[j], V1[j]));
              layers[gf->quadrangles.back()] = thickness;
            }
          }
        }
      }
    }
  }

  return true;
}

namespace {
  struct SurfaceUntanglerP1Stats {
    std::size_t empty = 0;
    std::size_t meanPlane = 0;
    std::size_t metricParametric = 0;
    std::size_t fallbackParametric = 0;
    std::size_t parametric = 0;
  };

  static void writeParametricTriangulationPos(
    GFace *gf, const char *stage, const std::vector<std::array<double, 2>> &points,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3>> &triangles)
  {
    char name[256];
    std::snprintf(name, sizeof(name), "boundaryLayer_parametric_face_%d_%s.pos",
                  gf ? gf->tag() : 0, stage ? stage : "mesh");
    FILE *fp = std::fopen(name, "w");
    if(!fp) return;

    std::fprintf(fp, "View \"Parametric triangles face %d %s\" {\n",
                 gf ? gf->tag() : 0, stage ? stage : "");
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      const auto &t = triangles[i];
      if(t[0] >= points.size() || t[1] >= points.size() ||
         t[2] >= points.size())
        continue;
      const double v0 = locked.size() > t[0] && locked[t[0]] ? 0. : 1.;
      const double v1 = locked.size() > t[1] && locked[t[1]] ? 0. : 1.;
      const double v2 = locked.size() > t[2] && locked[t[2]] ? 0. : 1.;
      std::fprintf(fp,
                   "ST(%g,%g,0,%g,%g,0,%g,%g,0){%g,%g,%g};\n",
                   points[t[0]][0], points[t[0]][1], points[t[1]][0],
                   points[t[1]][1], points[t[2]][0], points[t[2]][1], v0,
                   v1, v2);
    }
    std::fprintf(fp, "};\n");
    std::fclose(fp);
    Msg::Info("Wrote parametric triangulation '%s'", name);
  }

  static std::size_t countFaceP1Elements(
    GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess)
  {
    if(!gf) return 0;
    std::size_t n = 0;
    for(auto e : gf->triangles)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_TRI_3)
        n++;
    for(auto e : gf->quadrangles)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_QUA_4)
        n++;
    return n;
  }

  static std::array<std::array<double, 2>, 4>
  physicalPerfectShape2D(MElement *e)
  {
    std::array<std::array<double, 2>, 4> uv = {};
    if(!e || e->getNumVertices() < 3) return uv;

    SPoint3 p0 = e->getVertex(0)->point();
    SPoint3 p1 = e->getVertex(1)->point();
    SPoint3 p2 = e->getVertex(2)->point();

    SVector3 ex(p0, p1);
    double lx = ex.norm();
    if(lx <= 0.) return uv;
    ex.normalize();

    SVector3 v02(p0, p2);
    SVector3 n = crossprod(ex, v02);
    if(n.norm() <= 0. && e->getNumVertices() == 4) {
      SVector3 v03(p0, e->getVertex(3)->point());
      n = crossprod(ex, v03);
    }
    if(n.norm() <= 0.) {
      uv[1] = {lx, 0.};
      return uv;
    }
    n.normalize();
    SVector3 ey = crossprod(n, ex);
    ey.normalize();

    for(size_t j = 0; j < e->getNumVertices() && j < 4; ++j) {
      SVector3 d(p0, e->getVertex(j)->point());
      uv[j] = {dot(d, ex), dot(d, ey)};
    }
    return uv;
  }

  static bool findSurfaceOffsetParam(GFace *gf, const SPoint3 &base,
                                     const SPoint3 &other, double thickness,
                                     const SPoint2 &baseParam,
                                     std::array<double, 2> &offsetParam)
  {
    if(!gf || thickness <= 0.) return false;

    SVector3 edgeDirection(base, other);
    if(edgeDirection.norm() <= 0.) return false;
    edgeDirection.normalize();

    SVector3 normal = gf->normal(baseParam);
    if(normal.norm() <= 0.) return false;
    normal.normalize();

    SVector3 layerDirection = crossprod(normal, edgeDirection);
    if(layerDirection.norm() <= 0.) return false;
    layerDirection.normalize();

    auto solve = [&](const SVector3 &direction, std::array<double, 2> &uv) {
      SPoint3 query = base + direction * thickness;
      double guess[2] = {baseParam.x(), baseParam.y()};
      GPoint closest = gf->closestPoint(query, guess);
      uv = {closest.u(), closest.v()};

      for(int it = 0; it < 20; ++it) {
        GPoint gp = gf->point(uv[0], uv[1]);
        SPoint3 p(gp.x(), gp.y(), gp.z());
        SVector3 delta(base, p);

        const double f0 = dot(delta, edgeDirection);
        const double f1 = dot(delta, delta) - thickness * thickness;
        const double residual = std::sqrt(f0 * f0 + f1 * f1);
        if(residual < 1.e-10 * std::max(1., thickness)) return true;

        const auto der = gf->firstDer(SPoint2(uv[0], uv[1]));
        const double j00 = dot(der.first, edgeDirection);
        const double j01 = dot(der.second, edgeDirection);
        const double j10 = 2. * dot(delta, der.first);
        const double j11 = 2. * dot(delta, der.second);
        const double det = j00 * j11 - j01 * j10;
        if(std::abs(det) < 1.e-30) break;

        const double du = (-f0 * j11 + j01 * f1) / det;
        const double dv = (j10 * f0 - j00 * f1) / det;
        double alpha = 1.;
        for(int ls = 0; ls < 8; ++ls) {
          std::array<double, 2> trial = {uv[0] + alpha * du,
                                         uv[1] + alpha * dv};
          GPoint gpt = gf->point(trial[0], trial[1]);
          SPoint3 pt(gpt.x(), gpt.y(), gpt.z());
          SVector3 dt(base, pt);
          const double t0 = dot(dt, edgeDirection);
          const double t1 = dot(dt, dt) - thickness * thickness;
          const double trialResidual = std::sqrt(t0 * t0 + t1 * t1);
          if(std::isfinite(trialResidual) && trialResidual < residual) {
            uv = trial;
            break;
          }
          alpha *= 0.5;
        }
      }

      GPoint gp = gf->point(uv[0], uv[1]);
      SPoint3 p(gp.x(), gp.y(), gp.z());
      SVector3 delta(base, p);
      const double planeError = std::abs(dot(delta, edgeDirection));
      const double radiusError =
        std::abs(std::sqrt(std::max(0., dot(delta, delta))) - thickness);
      return planeError < 1.e-6 * std::max(1., thickness) &&
             radiusError < 1.e-6 * std::max(1., thickness) &&
             dot(delta, direction) > 0.;
    };

    std::array<double, 2> uvPlus, uvMinus;
    const bool okPlus = solve(layerDirection, uvPlus);
    const bool okMinus = solve(layerDirection * -1., uvMinus);
    if(okPlus) {
      offsetParam = uvPlus;
      return true;
    }
    if(okMinus) {
      offsetParam = uvMinus;
      return true;
    }

    SPoint3 query = base + layerDirection * thickness;
    double guess[2] = {baseParam.x(), baseParam.y()};
    GPoint closest = gf->closestPoint(query, guess);
    offsetParam = {closest.u(), closest.v()};
    return true;
  }

  inline bool
  elementTouchesVertexSet(MElement *e,
                          std::set<MVertex *, MVertexPtrLessThan> &touched)
  {
    for(size_t j = 0; j < e->getNumVertices(); ++j)
      if(touched.find(e->getVertex(j)) != touched.end()) return true;
    return false;
  }

  template <class GEntityT>
  static void
  buildUntangleSets(GEntityT *ge,
                    int targetDim, // 2 for faces, 3 for regions
                    const std::map<MElement *, double> &layers,
                    size_t nRings, // how many adjacency expansions
                    std::set<MElement *, MElementPtrLessThan> &toProcess,
                    std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    std::vector<MElement *> elements;
    elements.reserve(ge->getNumMeshElements());
    std::unordered_map<MVertex *, std::size_t> vertexIds;
    std::vector<MVertex *> vertices;
    std::vector<std::vector<std::size_t>> elementVertices;
    elementVertices.reserve(ge->getNumMeshElements());

    auto getVertexId = [&](MVertex *v) -> std::size_t {
      auto it = vertexIds.find(v);
      if(it != vertexIds.end()) return it->second;
      const std::size_t id = vertices.size();
      vertexIds[v] = id;
      vertices.push_back(v);
      return id;
    };

    for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
      MElement *e = ge->getMeshElement(i);
      elements.push_back(e);
      elementVertices.emplace_back();
      elementVertices.back().reserve(e->getNumVertices());
      for(std::size_t j = 0; j < e->getNumVertices(); ++j)
        elementVertices.back().push_back(getVertexId(e->getVertex(j)));
    }

    std::vector<unsigned char> touched(vertices.size(), 0);
    std::vector<unsigned char> newlyTouched(vertices.size(), 0);
    std::vector<unsigned char> processed(elements.size(), 0);

    // 1) seed touched with vertices of BL elements
    for(std::size_t i = 0; i < elements.size(); ++i) {
      MElement *e = elements[i];
      if(layers.find(e) == layers.end()) continue;
      for(std::size_t vId : elementVertices[i]) touched[vId] = 1;
    }

    // 2) expand neighborhood by nRings plus one guard ring. Vertices that
    // touch unprocessed elements are fixed below, so the outermost processed
    // ring mostly acts as a Dirichlet buffer. Without this guard ring,
    // SmoothingLayers=2 effectively leaves only one free smoothing layer.
    const size_t processRings = nRings + 1;
    for(size_t ring = 0; ring < processRings; ++ring) {
      std::fill(newlyTouched.begin(), newlyTouched.end(), 0);

      for(std::size_t i = 0; i < elements.size(); ++i) {
        bool touches = false;
        for(std::size_t vId : elementVertices[i]) {
          if(touched[vId]) {
            touches = true;
            break;
          }
        }
        if(!touches) continue;

        processed[i] = 1;
        for(std::size_t vId : elementVertices[i]) newlyTouched[vId] = 1;
      }

      for(std::size_t i = 0; i < touched.size(); ++i)
        touched[i] = touched[i] || newlyTouched[i];
    }

    // 3) build fixed = vertices of elements not processed + vertices not
    // classified on targetDim
    for(std::size_t i = 0; i < elements.size(); ++i) {
      MElement *e = elements[i];

      if(processed[i])
        toProcess.insert(e);
      else {
        for(std::size_t vId : elementVertices[i]) fixed.insert(vertices[vId]);
      }

      for(std::size_t vId : elementVertices[i])
        if(vertices[vId]->onWhat()->dim() != targetDim)
          fixed.insert(vertices[vId]);
    }
  }

} // namespace

static void expandBL(
  GFace *gf,
  std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes,
  std::map<MElement *, double> &layers, std::vector<GFace *> &inSurfaces,
  size_t nRings, int surfaceUntangler,
  double meanPlaneTolerance, double meanPlaneExtensionTolerance,
  int meanPlanePatchRings, int meanPlaneSweeps, double meanPlaneMoveTolerance,
  bool meanPlaneDebugPatches,
  int parametricQuadraturePoints,
  SurfaceUntanglerP1Stats *stats = nullptr)
{
  //  printf("layer size %zu\n",layers.size());
  //  std::vector<double> areas;
  (void)meanPlaneTolerance;
  (void)meanPlaneExtensionTolerance;
  (void)meanPlanePatchRings;
  (void)meanPlaneSweeps;
  (void)meanPlaneMoveTolerance;

  std::set<MElement *, MElementPtrLessThan> toProcess;
  std::set<MVertex *, MVertexPtrLessThan> fixed;
  buildUntangleSets(gf, /*targetDim=*/2, layers, nRings, toProcess, fixed);

  if(!countFaceP1Elements(gf, toProcess)) {
    if(stats) stats->empty++;
    return;
  }

  if(surfaceUntangler == 3) {
    MeanPlaneSurfaceUntanglerOptions options;
    options.distanceTolerance = meanPlaneTolerance;
    options.extensionDistanceTolerance = meanPlaneExtensionTolerance;
    options.maxPatchRings = meanPlanePatchRings;
    options.numSweeps = meanPlaneSweeps;
    options.moveTolerance = meanPlaneMoveTolerance;
    options.writePatchDebugPos = meanPlaneDebugPatches;
    bool ok = untangleSurfaceMeanPlanePatchesP1(gf, toProcess, fixed, layers,
                                                options);
    if(ok) {
      if(stats) stats->meanPlane++;
      return;
    }
    if(stats) stats->fallbackParametric++;
    Msg::Warning("Mean-plane P1 surface untangler failed on face %d; "
                 "falling back to standard parametric surface untangler",
                 gf ? gf->tag() : 0);
  }

  std::vector<std::array<std::array<double, 2>, 3>> sh;
  auto appendPositivePerfectTriangle =
    [&sh](std::array<double, 2> a, std::array<double, 2> b,
          std::array<double, 2> c) {
      if(triangle_area_2d(a, b, c) < 0.)
        sh.push_back({a, c, b});
      else
        sh.push_back({a, b, c});
    };
  for(auto e : toProcess) {
    //    printf("%zu %zu\n",i,gf->getNumMeshElements());
    //    MElement *e = gf->getMeshElement(i);

    std::array<std::array<double, 2>, 4> vs;

    auto it = layers.find(e);

    if(e->getNumVertices() == 3) {
      if(it != layers.end()) {
        double T = M_PI / 3.;
        double thickness = it->second;
        //	double fact = it->second/sqrt(3.0);
        vs[0] = {0, 0.};
        vs[1] = {thickness, 0.};
        vs[2] = {thickness * cos(T), thickness * sin(T)};
        //	vs[0] = {fact, 0.};
        //	vs[1] = {fact*cos(2. * M_PI / 3.), fact*sin(2 * M_PI / 3.)};
        //	vs[2] = {fact*cos(4. * M_PI / 3.), fact*sin(4 * M_PI / 3.)};
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh");
      }
      appendPositivePerfectTriangle(vs[0], vs[1], vs[2]);
    }
    else {
      if(it != layers.end()) {
        double thickness = it->second;
        // assume here zero size quads have been generated such as nodes 0 and 1
        // are along the curve ... nodes 1 and 2 are at the same position, same
        // for 0 and 3
        std::array<double, 2> perfectEdge0;
        std::array<double, 2> perfectEdge1;
        std::array<double, 2> perfectLayer1;
        std::array<double, 2> perfectLayer0;
        double dx = distance(e->getVertex(0), e->getVertex(1));
        perfectEdge0 = {0., 0.};
        perfectEdge1 = {dx, 0.};
        perfectLayer1 = {dx, thickness};
        perfectLayer0 = {0., thickness};

        if(gf->geomType() != GEntity::Plane) {
          SPoint2 paramEdge0, paramEdge1;
          bool haveParamEdge0 =
            reparamMeshVertexOnFace(e->getVertex(0), gf, paramEdge0);
          bool haveParamEdge1 =
            reparamMeshVertexOnFace(e->getVertex(1), gf, paramEdge1);
          if(haveParamEdge0 && haveParamEdge1) {
            SPoint3 pointEdge0 = e->getVertex(0)->point();
            SPoint3 pointEdge1 = e->getVertex(1)->point();
            SVector3 edgeDirection(pointEdge0, pointEdge1);
            double edgeLength = edgeDirection.norm();
            if(edgeLength > 0.) {
              edgeDirection.normalize();
              SVector3 normalAtEdge0 = gf->normal(paramEdge0);
              SVector3 normalAtEdge1 = gf->normal(paramEdge1);
              SVector3 layerDirection0 =
                crossprod(normalAtEdge0, edgeDirection);
              SVector3 layerDirection1 =
                crossprod(normalAtEdge1, edgeDirection);
              if(layerDirection0.norm() > 0. && layerDirection1.norm() > 0.) {
                layerDirection0.normalize();
                layerDirection1.normalize();
                SPoint3 queryLayer0 = pointEdge0 + layerDirection0 * thickness;
                SPoint3 queryLayer1 = pointEdge1 + layerDirection1 * thickness;
                double guess0[2] = {paramEdge0.x(), paramEdge0.y()};
                double guess1[2] = {paramEdge1.x(), paramEdge1.y()};
                GPoint closestLayer0 = gf->closestPoint(queryLayer0, guess0);
                GPoint closestLayer1 = gf->closestPoint(queryLayer1, guess1);
                perfectEdge0 = {paramEdge0.x(), paramEdge0.y()};
                perfectEdge1 = {paramEdge1.x(), paramEdge1.y()};
                perfectLayer1 = {closestLayer1.u(), closestLayer1.v()};
                perfectLayer0 = {closestLayer0.u(), closestLayer0.v()};
              }
            }
          }
        }

        if(surfaceUntangler != 2) {
          int numBoundaryVertices = 0;
          int freeVertex = -1;
          std::array<std::array<double, 2>, 4> boundaryParam;
          bool haveBoundaryParam[4] = {false, false, false, false};
          for(int j = 0; j < 4; j++) {
            if(e->getVertex(j)->onWhat()->dim() < 2) {
              SPoint2 param;
              if(reparamMeshVertexOnFace(e->getVertex(j), gf, param)) {
                boundaryParam[j] = {param.x(), param.y()};
                haveBoundaryParam[j] = true;
                numBoundaryVertices++;
              }
            }
            else
              freeVertex = j;
          }
          bool haveBoundaryParallelogram = false;
          if(numBoundaryVertices == 3 && freeVertex >= 0) {
            for(int j = 0; j < 4; j++) {
              if(haveBoundaryParam[j]) {
                if(j == 0)
                  perfectEdge0 = boundaryParam[j];
                else if(j == 1)
                  perfectEdge1 = boundaryParam[j];
                else if(j == 2)
                  perfectLayer1 = boundaryParam[j];
                else if(j == 3)
                  perfectLayer0 = boundaryParam[j];
              }
            }
            if(freeVertex == 0)
              perfectEdge0 = {
                perfectEdge1[0] + perfectLayer0[0] - perfectLayer1[0],
                perfectEdge1[1] + perfectLayer0[1] - perfectLayer1[1]};
            else if(freeVertex == 1)
              perfectEdge1 = {
                perfectEdge0[0] + perfectLayer1[0] - perfectLayer0[0],
                perfectEdge0[1] + perfectLayer1[1] - perfectLayer0[1]};
            else if(freeVertex == 2)
              perfectLayer1 = {
                perfectEdge1[0] + perfectLayer0[0] - perfectEdge0[0],
                perfectEdge1[1] + perfectLayer0[1] - perfectEdge0[1]};
            else
              perfectLayer0 = {
                perfectEdge0[0] + perfectLayer1[0] - perfectEdge1[0],
                perfectEdge0[1] + perfectLayer1[1] - perfectEdge1[1]};
            haveBoundaryParallelogram = true;
          }

          if(haveBoundaryParallelogram &&
             triangle_area_2d(perfectEdge0, perfectEdge1, perfectLayer1) <
               0.) {
            std::swap(perfectEdge0, perfectEdge1);
            std::swap(perfectLayer0, perfectLayer1);
          }
        }

        appendPositivePerfectTriangle(perfectEdge0, perfectEdge1,
                                      perfectLayer1);
        appendPositivePerfectTriangle(perfectLayer1, perfectLayer0,
                                      perfectEdge0);
        appendPositivePerfectTriangle(perfectEdge0, perfectEdge1,
                                      perfectLayer0);
        appendPositivePerfectTriangle(perfectEdge1, perfectLayer1,
                                      perfectLayer0);
        //	printf(" %g %g %g %g %g %g\n",dx,thickness, triangle_area_2d(p0, p1,
        // p2), triangle_area_2d(p2, p3, p0), 	       triangle_area_2d(p0, p1,
        // p3),triangle_area_2d(p1, p2, p3));
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh -- perfect shapes cannot be found ...");
        appendPositivePerfectTriangle(vs[0], vs[1], vs[2]);
        appendPositivePerfectTriangle(vs[2], vs[3], vs[0]);
        appendPositivePerfectTriangle(vs[0], vs[1], vs[3]);
        appendPositivePerfectTriangle(vs[1], vs[2], vs[3]);
      }
    }
  }

  std::vector<std::array<double, 2>> points;
  std::vector<std::array<uint32_t, 3>> triangles;
  std::vector<bool> locked;
  std::set<MVertex *> verts;

  for(auto e : toProcess) {
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }

  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    if(fixed.find(v) == fixed.end())
      locked.push_back(false);
    else
      locked.push_back(true);

    SPoint2 param;
    reparamMeshVertexOnFace(v, gf, param);
    points.push_back({param.x(), param.y()});
  }
  // int tricount = 0;
  double area = 0.0;
  for(auto e : toProcess) {
    uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
    uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
    uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
    std::array<double, 2> pa = points[a];
    std::array<double, 2> pb = points[b];
    std::array<double, 2> pc = points[c];
    area += triangle_area_2d(pa, pb, pc);
    if(e->getNumVertices() == 4) {
      uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
      std::array<double, 2> pd = points[d];
      area += triangle_area_2d(pa, pc, pd);
    }
  }
  //  printf("->area(%d) = %g\n",gf->tag(),area);

  for(auto e : toProcess) {
    uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
    uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
    uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
    if(e->getNumVertices() == 3) {
      if(area > 0)
        triangles.push_back({a, b, c});
      else
        triangles.push_back({b, a, c});
    }
    else {
      uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
      if(area > 0) {
        triangles.push_back({a, b, c});
        triangles.push_back({c, d, a});
        triangles.push_back({a, b, d});
        triangles.push_back({b, c, d});
      }
      else {
        triangles.push_back({b, a, d});
        triangles.push_back({d, c, b});
        triangles.push_back({b, a, c});
        triangles.push_back({a, d, c});
      }
    }
  }
  printf("face %d: %zu vertices, %zu triangles\n", gf->tag(), points.size(),
         triangles.size());
  if(meanPlaneDebugPatches)
    writeParametricTriangulationPos(gf, "before", points, locked, triangles);
  if(surfaceUntangler == 2) {
    bool ok =
      untangle_triangles_parametric_GMSH(gf, points, locked, triangles, sh,
                                         1.e+0, 300, 9999.,
                                         parametricQuadraturePoints);
    if(ok && stats) stats->metricParametric++;
    if(!ok) {
      if(stats) stats->fallbackParametric++;
      Msg::Warning("Metric-parametric P1 surface untangler failed on face %d; "
                   "falling back to standard parametric surface untangler",
                   gf ? gf->tag() : 0);
      untangle_triangles_2D_GMSH(points, locked, triangles, sh, 1.e+0);
    }
  }
  else {
    if(stats) stats->parametric++;
    untangle_triangles_2D_GMSH(points, locked, triangles, sh, 1.e+0);
  }
  if(meanPlaneDebugPatches)
    writeParametricTriangulationPos(gf, "after", points, locked, triangles);

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      GPoint gp = gf->point(points[i][0], points[i][1]);
      v->x() = gp.x();
      v->y() = gp.y();
      v->z() = gp.z();
      v->setParameter(0, gp.u());
      v->setParameter(1, gp.v());
    }
  }
}

static void expandBL3D(
  GRegion *gr,
  std::map<MElement *, std::array<std::array<double, 3>, 8>> &perfectShapes3D,
  std::map<MElement *, double> &layers, size_t nRings,
  const std::map<MElement *, BoundaryLayerIntersectEdgeHex> *intersectEdgeHexes =
    nullptr,
  const std::map<MElement *, BoundaryLayerIntersectCornerHex>
    *intersectCornerHexes =
    nullptr)
{
  auto setVertex = [](MVertex *v, const std::array<double, 3> &p) {
    if(!v) return;
    v->x() = p[0];
    v->y() = p[1];
    v->z() = p[2];
  };
  auto xyz = [](MVertex *v) {
    return std::array<double, 3>{v->x(), v->y(), v->z()};
  };
  auto add = [](const std::array<double, 3> &u,
                const std::array<double, 3> &v) {
    return std::array<double, 3>{u[0] + v[0], u[1] + v[1], u[2] + v[2]};
  };
  auto sub3 = [](const std::array<double, 3> &u,
                 const std::array<double, 3> &v) {
    return std::array<double, 3>{u[0] - v[0], u[1] - v[1], u[2] - v[2]};
  };

  if(intersectEdgeHexes) {
    for(const auto &it : *intersectEdgeHexes) {
      const BoundaryLayerIntersectEdgeHex &hex = it.second;
      if(hex.gr != gr) continue;
      std::array<double, 3> p0 = xyz(hex.p0);
      std::array<double, 3> p1 = xyz(hex.p1);
      setVertex(hex.s0, add(hex.a0 ? xyz(hex.a0) : p0,
                            sub3(hex.b0 ? xyz(hex.b0) : p0, p0)));
      setVertex(hex.s1, add(hex.a1 ? xyz(hex.a1) : p1,
                            sub3(hex.b1 ? xyz(hex.b1) : p1, p1)));
    }
  }
  if(intersectCornerHexes) {
    for(const auto &it : *intersectCornerHexes) {
      const BoundaryLayerIntersectCornerHex &hex = it.second;
      if(hex.gr != gr) continue;
      std::array<double, 3> p = xyz(hex.p);
      std::array<double, 3> a = xyz(hex.a);
      std::array<double, 3> b = xyz(hex.b);
      std::array<double, 3> c = xyz(hex.c);
      setVertex(hex.r, add(p, add(add(sub3(a, p), sub3(b, p)), sub3(c, p))));
    }
  }

  //  printf("layer size %zu\n",layers.size());
  //  std::vector<double> areas;

  double tStart = TimeOfDay();
  std::set<MElement *, MElementPtrLessThan> toProcess;
  std::set<MVertex *, MVertexPtrLessThan> fixed;
  buildUntangleSets(gr, /*targetDim=*/3, layers, nRings, toProcess, fixed);
  double tSets = TimeOfDay();

  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  if(nthreads < 1) nthreads = 1;

  std::vector<MElement *> elements(toProcess.begin(), toProcess.end());

  std::vector<std::array<std::array<double, 3>, 4>> sh;
  std::vector<std::vector<std::array<std::array<double, 3>, 4>>>
    shByElement(elements.size());

#if defined(_OPENMP)
#pragma omp parallel for schedule(static) num_threads(nthreads)
#endif
  for(std::size_t i = 0; i < elements.size(); ++i) {
    MElement *e = elements[i];
    std::array<std::array<double, 3>, 8> vs = {};

    auto it = layers.find(e);

    // TETRAHEDRA NOT IN BL !!
    int type = e->getTypeForMSH();
    if(type == MSH_TET_4) {
      auto it2 = perfectShapes3D.find(e);
      if(it2 != perfectShapes3D.end())
        vs = it2->second;
      else
        Msg::Error("Argh");
      shByElement[i].push_back({vs[1], vs[0], vs[2], vs[3]});
    }
    else if(type == MSH_PRI_6) {
      if(it != layers.end()) {
        double tk = it->second;
        //	printf("tk = %12.5E\n",tk);
        SVector3 t1 = e->getVertex(1)->point() - e->getVertex(0)->point();
        SVector3 t2 = e->getVertex(2)->point() - e->getVertex(0)->point();
        SVector3 n = crossprod(t1, t2);
        n.normalize();
        vs[0] = {e->getVertex(0)->x(), e->getVertex(0)->y(),
                 e->getVertex(0)->z()};
        vs[1] = {e->getVertex(1)->x(), e->getVertex(1)->y(),
                 e->getVertex(1)->z()};
        vs[2] = {e->getVertex(2)->x(), e->getVertex(2)->y(),
                 e->getVertex(2)->z()};
        vs[3] = {e->getVertex(0)->x() + n.x() * tk,
                 e->getVertex(0)->y() + n.y() * tk,
                 e->getVertex(0)->z() + n.z() * tk};
        vs[4] = {e->getVertex(1)->x() + n.x() * tk,
                 e->getVertex(1)->y() + n.y() * tk,
                 e->getVertex(1)->z() + n.z() * tk};
        vs[5] = {e->getVertex(2)->x() + n.x() * tk,
                 e->getVertex(2)->y() + n.y() * tk,
                 e->getVertex(2)->z() + n.z() * tk};
        int pp[6][4] = {{1, 0, 2, 3}, {1, 0, 2, 4}, {1, 0, 2, 5},
                        {3, 4, 5, 0}, {3, 4, 5, 1}, {3, 4, 5, 2}};
        for(size_t j = 0; j < 6; j++)
          shByElement[i].push_back(
            {vs[pp[j][0]], vs[pp[j][1]], vs[pp[j][2]], vs[pp[j][3]]});
      }
    }
    else if(type == MSH_HEX_8) {
      if(it != layers.end()) {
        auto itIntersect = intersectEdgeHexes ?
                             intersectEdgeHexes->find(e) :
                             std::map<MElement *, BoundaryLayerIntersectEdgeHex>::const_iterator();
        auto itCorner = intersectCornerHexes ?
                          intersectCornerHexes->find(e) :
                          std::map<MElement *, BoundaryLayerIntersectCornerHex>::const_iterator();
        if(intersectCornerHexes && itCorner != intersectCornerHexes->end()) {
          const BoundaryLayerIntersectCornerHex &hex = itCorner->second;
          auto xyz = [](MVertex *v) {
            return std::array<double, 3>{v->x(), v->y(), v->z()};
          };
          auto add = [](const std::array<double, 3> &u,
                        const std::array<double, 3> &v) {
            return std::array<double, 3>{u[0] + v[0], u[1] + v[1],
                                         u[2] + v[2]};
          };
          auto sub3 = [](const std::array<double, 3> &u,
                         const std::array<double, 3> &v) {
            return std::array<double, 3>{u[0] - v[0], u[1] - v[1],
                                         u[2] - v[2]};
          };
          std::array<double, 3> p = xyz(hex.p);
          std::array<double, 3> a = xyz(hex.a);
          std::array<double, 3> b = xyz(hex.b);
          std::array<double, 3> c = xyz(hex.c);
          std::array<double, 3> u = sub3(a, p);
          std::array<double, 3> v = sub3(b, p);
          std::array<double, 3> w = sub3(c, p);
          std::map<MVertex *, std::array<double, 3>> ideal;
          ideal[hex.p] = p;
          ideal[hex.a] = a;
          ideal[hex.b] = b;
          ideal[hex.c] = c;
          ideal[hex.sab] = add(p, add(u, v));
          ideal[hex.sac] = add(p, add(u, w));
          ideal[hex.sbc] = add(p, add(v, w));
          ideal[hex.r] = add(p, add(add(u, v), w));
          for(int j = 0; j < 8; ++j) {
            auto itIdeal = ideal.find(e->getVertex(j));
            if(itIdeal != ideal.end()) vs[j] = itIdeal->second;
          }
        }
        else if(intersectEdgeHexes && itIntersect != intersectEdgeHexes->end()) {
          const BoundaryLayerIntersectEdgeHex &hex = itIntersect->second;
          auto xyz = [](MVertex *v) {
            return std::array<double, 3>{v->x(), v->y(), v->z()};
          };
          std::array<double, 3> p0 = xyz(hex.p0);
          std::array<double, 3> p1 = xyz(hex.p1);
          std::array<double, 3> a0 = xyz(hex.a0);
          std::array<double, 3> a1 = xyz(hex.a1);
          std::array<double, 3> b0 = xyz(hex.b0);
          std::array<double, 3> b1 = xyz(hex.b1);
          std::map<MVertex *, std::array<double, 3>> ideal;
          ideal[hex.p0] = p0;
          ideal[hex.p1] = p1;
          ideal[hex.a0] = a0;
          ideal[hex.a1] = a1;
          ideal[hex.b0] = b0;
          ideal[hex.b1] = b1;
          ideal[hex.s0] = {a0[0] + b0[0] - p0[0],
                           a0[1] + b0[1] - p0[1],
                           a0[2] + b0[2] - p0[2]};
          ideal[hex.s1] = {a1[0] + b1[0] - p1[0],
                           a1[1] + b1[1] - p1[1],
                           a1[2] + b1[2] - p1[2]};
          for(int j = 0; j < 8; ++j) {
            auto itIdeal = ideal.find(e->getVertex(j));
            if(itIdeal != ideal.end()) vs[j] = itIdeal->second;
          }
        }
        else {
          double tk = it->second;
          SVector3 t1 = e->getVertex(1)->point() - e->getVertex(0)->point();
          SVector3 t2 = e->getVertex(3)->point() - e->getVertex(0)->point();
          SVector3 n = crossprod(t1, t2);
          n.normalize();
          for(size_t j = 0; j < 4; j++) {
            vs[j] = {e->getVertex(j)->x(), e->getVertex(j)->y(),
                     e->getVertex(j)->z()};
            vs[j + 4] = {e->getVertex(j)->x() + n.x() * tk,
                         e->getVertex(j)->y() + n.y() * tk,
                         e->getVertex(j)->z() + n.z() * tk};
          }
        }
      }
      else {
        auto it2 = perfectShapes3D.find(e);
        if(it2 != perfectShapes3D.end())
          vs = it2->second;
        else
          Msg::Error("Argh");
      }
      int pp[6][4] = {{1, 0, 2, 6}, {2, 0, 3, 6}, {3, 0, 7, 6},
                      {7, 0, 4, 6}, {4, 0, 5, 6}, {5, 0, 1, 6}};
      for(size_t j = 0; j < 6; j++)
        shByElement[i].push_back(
          {vs[pp[j][0]], vs[pp[j][1]], vs[pp[j][2]], vs[pp[j][3]]});
    }
    else if(type == MSH_PYR_5) {
      auto it2 = perfectShapes3D.find(e);
      if(it2 != perfectShapes3D.end())
        vs = it2->second;
      else
        Msg::Error("Argh");
      int pp[4][4] = {{1, 0, 2, 4}, {2, 0, 3, 4},
                      {1, 0, 3, 4}, {2, 1, 3, 4}};
      for(size_t j = 0; j < 4; j++)
        shByElement[i].push_back(
          {vs[pp[j][0]], vs[pp[j][1]], vs[pp[j][2]], vs[pp[j][3]]});
    }
  }
  std::size_t numIdeal = 0;
  for(const auto &local : shByElement) numIdeal += local.size();
  sh.reserve(numIdeal);
  for(const auto &local : shByElement)
    sh.insert(sh.end(), local.begin(), local.end());
  double tShapes = TimeOfDay();
  std::vector<std::array<double, 3>> points;
  std::vector<std::array<uint32_t, 4>> tets;
  std::vector<bool> locked;
  std::set<MVertex *> verts;

  for(auto e : elements) {
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }

  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    if(fixed.find(v) == fixed.end())
      locked.push_back(false);
    else
      locked.push_back(true);
    points.push_back({v->x(), v->y(), v->z()});
  }
  double tPoints = TimeOfDay();

  double tVolume = TimeOfDay();
  Msg::Info("Boundary layer 3D setup before Winslow: region %d, %zu elements, "
            "%zu points, %zu ideal tets "
            "(threads %d, sets %.3g s, ideal %.3g s, points %.3g s)",
            gr ? gr->tag() : 0, toProcess.size(), points.size(), sh.size(),
            nthreads, tSets - tStart, tShapes - tSets, tPoints - tShapes);

  std::vector<std::vector<std::array<uint32_t, 4>>> tetsByElement(elements.size());

#if defined(_OPENMP)
#pragma omp parallel for schedule(static) num_threads(nthreads)
#endif
  for(std::size_t i = 0; i < elements.size(); ++i) {
    MElement *e = elements[i];
    int type = e->getTypeForMSH();
    uint32_t nn[8] = {(uint32_t)e->getVertex(0)->getIndex(),
                      (uint32_t)e->getVertex(1)->getIndex(),
                      (uint32_t)e->getVertex(2)->getIndex(),
                      (uint32_t)e->getVertex(3)->getIndex(),
                      0,
                      0,
                      0,
                      0};
    if(type == MSH_TET_4) {
      tetsByElement[i].push_back({nn[1], nn[0], nn[2], nn[3]});
    }
    else if(type == MSH_PRI_6) {
      int pp[6][4] = {{1, 0, 2, 3}, {1, 0, 2, 4}, {1, 0, 2, 5},
                      {3, 4, 5, 0}, {3, 4, 5, 1}, {3, 4, 5, 2}};
      nn[4] = (uint32_t)e->getVertex(4)->getIndex();
      nn[5] = (uint32_t)e->getVertex(5)->getIndex();
      for(size_t j = 0; j < 6; j++)
        tetsByElement[i].push_back(
          {nn[pp[j][0]], nn[pp[j][1]], nn[pp[j][2]], nn[pp[j][3]]});
    }
    else if(type == MSH_HEX_8) {
      int pp[6][4] = {{1, 0, 2, 6}, {2, 0, 3, 6}, {3, 0, 7, 6},
                      {7, 0, 4, 6}, {4, 0, 5, 6}, {5, 0, 1, 6}};
      nn[4] = (uint32_t)e->getVertex(4)->getIndex();
      nn[5] = (uint32_t)e->getVertex(5)->getIndex();
      nn[6] = (uint32_t)e->getVertex(6)->getIndex();
      nn[7] = (uint32_t)e->getVertex(7)->getIndex();
      for(size_t j = 0; j < 6; j++)
        tetsByElement[i].push_back(
          {nn[pp[j][0]], nn[pp[j][1]], nn[pp[j][2]], nn[pp[j][3]]});
    }
    else if(type == MSH_PYR_5) {
      int pp[4][4] = {{1, 0, 2, 4}, {2, 0, 3, 4},
                      {1, 0, 3, 4}, {2, 1, 3, 4}};
      nn[4] = (uint32_t)e->getVertex(4)->getIndex();
      for(size_t j = 0; j < 4; j++)
        tetsByElement[i].push_back(
          {nn[pp[j][0]], nn[pp[j][1]], nn[pp[j][2]], nn[pp[j][3]]});
    }
  }
  std::size_t numTets = 0;
  for(const auto &local : tetsByElement) numTets += local.size();
  tets.reserve(numTets);
  for(const auto &local : tetsByElement)
    tets.insert(tets.end(), local.begin(), local.end());
  std::size_t reorientedIdealTets = 0;
  if(sh.size() == tets.size()) {
    for(std::size_t i = 0; i < sh.size(); ++i) {
      const double vol =
        tetVolume3(sh[i][0], sh[i][1], sh[i][2], sh[i][3]);
      if(vol < 0.) {
        std::swap(sh[i][0], sh[i][1]);
        std::swap(tets[i][0], tets[i][1]);
        reorientedIdealTets++;
      }
    }
  }
  double tTets = TimeOfDay();
  Msg::Info("Boundary layer 3D proxy tets before Winslow: %zu tets "
            "(build %.3g s, reoriented ideal %zu)",
            tets.size(), tTets - tVolume, reorientedIdealTets);
  double tUntangle = TimeOfDay();
#if 1
  untangle_tetrahedra_GMSH(points, locked, tets, sh, 1.e+0);
#else
  untangle_tetrahedra(points, locked, tets, sh, 1.e+0);
#endif
  Msg::Info("Boundary layer 3D untangling done in %g s",
            TimeOfDay() - tUntangle);

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      v->x() = points[i][0];
      v->y() = points[i][1];
      v->z() = points[i][2];
    }
  }

}

static std::vector<MVertex *>
splitedge(MEdge me,
          std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
          std::vector<double> &t_init, double hwall, double ratio,
          double numExactLayers)
{
  auto it = split.find(me);
  if(it != split.end()) {
    if(!it->second.empty() && it->second.front() != me.getVertex(0)) {
      std::vector<MVertex *> reversed = it->second;
      std::reverse(reversed.begin(), reversed.end());
      return reversed;
    }
    return it->second;
  }

  std::vector<double> t = t_init;
  int minPerfect = (numExactLayers > 0) ? (int)numExactLayers :
                                          (int)(t.size() / (-numExactLayers));
  int n = (int)t.size();
  if(minPerfect > n) {
    Msg::Warning("BoundaryLayer split edge: NumExactLayers=%d larger than "
                 "number of layers=%d; clamping",
                 minPerfect, n);
    minPerfect = n;
  }
  if(minPerfect < 0) minPerfect = 0;

  bool adjusted = true;
  int iter = 0;
  while(minPerfect >= 0 && 0) {
    t = t_init;
    double L = me.length();
    if(L <= 0. || !std::isfinite(L)) {
      Msg::Warning("BoundaryLayer split edge: invalid edge length %g for "
                   "vertices %zu %zu",
                   L, me.getVertex(0)->getNum(), me.getVertex(1)->getNum());
      break;
    }
    double hw0 = hwall / L;
    double hw = hw0;
    double tTOT = 0.0;

    for(int i = 0; i < minPerfect; ++i) {
      tTOT += hw;
      t[i] = tTOT;
      hw *= ratio;
    }
    double hw_last = hw / ratio;

    int m = n - minPerfect; // nb de couches à ajuster
    double target = 1.0 - tTOT; // ce qu'il reste à remplir (normalisé)

    if(m > 0 && target > 0.0) {
      auto sumTail = [&](double r) -> double {
        if(std::abs(r - 1.0) < 1e-14) return hw_last * m;
        return hw_last * r * (1.0 - std::pow(r, (double)m)) / (1.0 - r);
      };

      // bisection (monotone en r>0)
      double lo = 1e-12, hi = 2.0;
      int hiIter = 0;
      while(sumTail(hi) < target && hiIter++ < 80) hi *= 2.0;
      if(hiIter >= 80 || !std::isfinite(hi)) {
        Msg::Warning("BoundaryLayer split edge: cannot bracket ratio on edge "
                     "%zu-%zu (L=%g, target=%g, hw_last=%g, m=%d)",
                     me.getVertex(0)->getNum(), me.getVertex(1)->getNum(), L,
                     target, hw_last, m);
        break;
      }

      for(int it = 0; it < 80; ++it) {
        double mid = 0.5 * (lo + hi);
        if(sumTail(mid) >= target)
          hi = mid;
        else
          lo = mid;
      }
      double r_new = 0.5 * (lo + hi);

      if(r_new > 1) {
        double hw2 = hw_last;
        for(int i = minPerfect; i < n; ++i) {
          hw2 *= r_new;
          tTOT += hw2;
          t[i] = tTOT;
        }

        // 4) fermeture exacte (optionnel mais pratique)
        t.back() = 1.0;
        adjusted = true;
        break;
      }
    }
    if(iter++ > n + 2) {
      Msg::Warning("BoundaryLayer split edge: too many attempts on edge "
                   "%zu-%zu (n=%d, hwall=%g, ratio=%g, numExactLayers=%g)",
                   me.getVertex(0)->getNum(), me.getVertex(1)->getNum(), n,
                   hwall, ratio, numExactLayers);
      break;
    }
    minPerfect--;
  }
  if(!adjusted) {
    Msg::Warning("BoundaryLayer split edge: using original layer distribution "
                 "on edge %zu-%zu",
                 me.getVertex(0)->getNum(), me.getVertex(1)->getNum());
    t = t_init;
  }

  std::vector<MVertex *> vs;
  vs.push_back(me.getVertex(0));
  if(me.getVertex(1)->onWhat()->dim() == 3) {
    GRegion *gr = static_cast<GRegion *>(me.getVertex(1)->onWhat());
    SPoint3 p0 = me.getVertex(0)->point();
    SPoint3 p1 = me.getVertex(1)->point();
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint3 p = p0 + (p1 - p0) * t[i];
      vs.push_back(new MVertex(p.x(), p.y(), p.z(), gr));
      gr->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 2) {
    SPoint2 p0, p1;
    GFace *gf = static_cast<GFace *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnFace(me.getVertex(0), gf, p0);
    reparamMeshVertexOnFace(me.getVertex(1), gf, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint2 p = p0 + (p1 - p0) * t[i];
      GPoint gp = gf->point(p.x(), p.y());
      vs.push_back(new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, p.x(), p.y()));
      gf->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 1) {
    double p0, p1;
    GEdge *ge = static_cast<GEdge *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnEdge(me.getVertex(0), ge, p0);
    reparamMeshVertexOnEdge(me.getVertex(1), ge, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      double p = p0 + t[i] * (p1 - p0);
      GPoint gp = ge->point(p);
      vs.push_back(new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, p));
      ge->mesh_vertices.push_back(vs.back());
    }
  }
  vs.push_back(me.getVertex(1));
  split[me] = vs;
  return vs;
}

struct BoundaryLayerSplitFaceGridKey {
  GRegion *gr = nullptr;
  MVertex *p = nullptr;
  MVertex *a = nullptr;
  MVertex *s = nullptr;
  MVertex *b = nullptr;

  bool operator<(const BoundaryLayerSplitFaceGridKey &other) const
  {
    if(gr != other.gr) return gr < other.gr;
    if(p != other.p) return p < other.p;
    if(a != other.a) return a < other.a;
    if(s != other.s) return s < other.s;
    return b < other.b;
  }
};

static std::vector<std::vector<MVertex *> > &
splitIntersectFaceGrid(
  GRegion *gr, GFace *faceA, GFace *faceB, MVertex *p, MVertex *a,
  MVertex *s, MVertex *b,
  std::map<BoundaryLayerSplitFaceGridKey,
           std::vector<std::vector<MVertex *> > > &faceGrids,
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
  std::vector<double> &t, const std::vector<double> &fractions, double hwall,
  double ratio, double numExactLayers)
{
  BoundaryLayerSplitFaceGridKey key;
  key.gr = gr;
  key.p = p;
  key.a = a;
  key.s = s;
  key.b = b;
  auto itGrid = faceGrids.find(key);
  if(itGrid != faceGrids.end()) return itGrid->second;
  BoundaryLayerSplitFaceGridKey swappedKey;
  swappedKey.gr = gr;
  swappedKey.p = p;
  swappedKey.a = b;
  swappedKey.s = s;
  swappedKey.b = a;
  auto itSwapped = faceGrids.find(swappedKey);
  if(itSwapped != faceGrids.end()) {
    const std::size_t n = itSwapped->second.size();
    std::vector<std::vector<MVertex *> > transposed(
      n, std::vector<MVertex *>(n, nullptr));
    for(std::size_t i = 0; i < n; ++i)
      for(std::size_t j = 0; j < n; ++j)
        transposed[i][j] = itSwapped->second[j][i];
    faceGrids[key] = transposed;
    return faceGrids[key];
  }

  std::vector<MVertex *> pPA =
    splitedge(MEdge(p, a), split, t, hwall, ratio, numExactLayers);
  std::vector<MVertex *> pAS =
    splitedge(MEdge(a, s), split, t, hwall, ratio, numExactLayers);
  std::vector<MVertex *> pBS =
    splitedge(MEdge(b, s), split, t, hwall, ratio, numExactLayers);
  std::vector<MVertex *> pPB =
    splitedge(MEdge(p, b), split, t, hwall, ratio, numExactLayers);

  const std::size_t n = pPA.size() ? pPA.size() - 1 : 0;
  std::vector<std::vector<MVertex *> > grid(
    n + 1, std::vector<MVertex *>(n + 1, nullptr));
  if(!n || pAS.size() != n + 1 || pBS.size() != n + 1 ||
     pPB.size() != n + 1 || fractions.size() != n + 1) {
    Msg::Warning("BoundaryLayer splitounette3D: inconsistent intersect "
                 "face split at vertex %zu",
                 p ? p->getNum() : 0);
    faceGrids[key] = grid;
    return faceGrids[key];
  }

  for(std::size_t i = 0; i <= n; ++i) {
    grid[i][0] = pPA[i];
    grid[i][n] = pBS[i];
  }
  for(std::size_t j = 0; j <= n; ++j) {
    grid[0][j] = pPB[j];
    grid[n][j] = pAS[j];
  }

  SPoint3 P = p->point();
  SPoint3 A = a->point();
  SPoint3 S = s->point();
  SPoint3 B = b->point();
  for(std::size_t i = 1; i < n; ++i) {
    const double u = fractions[i];
    for(std::size_t j = 1; j < n; ++j) {
      const double v = fractions[j];
      SPoint3 pt = bilinearPoint(P, A, S, B, u, v);
      MVertex *newv = new MVertex(pt.x(), pt.y(), pt.z(), gr);
      gr->mesh_vertices.push_back(newv);
      grid[i][j] = newv;
    }
  }

  faceGrids[key] = grid;
  return faceGrids[key];
}

void splitounette3D(std::vector<GRegion *> &r,
                    std::map<MElement *, double> &layers,
                    std::vector<double> &widths, double hwall, double ratio,
                    double numExactLayers,
                    const std::map<MElement *, BoundaryLayerIntersectEdgeHex>
                      *intersectEdgeHexes = nullptr,
                    const std::map<MElement *, BoundaryLayerIntersectCornerHex>
                      *intersectCornerHexes = nullptr)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  std::map<BoundaryLayerSplitFaceGridKey,
           std::vector<std::vector<MVertex *> > >
    intersectFaceGrids;

  // Build normalized cumulative parameters t in (0,1)
  std::vector<double> t;
  double tot = 0.0;
  for(double w : widths) tot += w;

  double wloc = 0.0;
  for(double w : widths) {
    wloc += w;
    t.push_back(wloc / tot);
  }
  std::vector<double> fractions;
  fractions.push_back(0.);
  fractions.insert(fractions.end(), t.begin(), t.end());

  Msg::Info("BoundaryLayer splitounette3D: %zu regions, %zu layer widths",
            r.size(), widths.size());

  for(auto gr : r) {
    // Copy pointers first (like in splitounette) to avoid iterating on growing
    // vectors
    std::vector<MElement *> temp;
    for(size_t i = 0; i < gr->getNumMeshElements(); ++i)
      temp.push_back(gr->getMeshElement(i));

    Msg::Info("BoundaryLayer splitounette3D: region %d, %zu elements before "
              "splitting",
              gr->tag(), temp.size());
    for(size_t i = 0; i < temp.size(); ++i) {
      MElement *e = temp[i];
      auto itL = layers.find(e);
      if(itL == layers.end()) continue;

      const int type = e->getTypeForMSH();
      if((i % 1000) == 0)
        Msg::Info("BoundaryLayer splitounette3D: region %d element %zu/%zu "
                  "(type=%d, split edges=%zu)",
                  gr->tag(), i, temp.size(), type, split.size());

      if(type == MSH_HEX_8 && intersectCornerHexes) {
        auto itCorner = intersectCornerHexes->find(e);
        if(itCorner != intersectCornerHexes->end()) {
          const BoundaryLayerIntersectCornerHex &hex = itCorner->second;
          const std::size_t n = fractions.size() ? fractions.size() - 1 : 0;
          if(!n || !hex.gr || !hex.p || !hex.a || !hex.b || !hex.c ||
             !hex.sab || !hex.sac || !hex.sbc || !hex.r) {
            Msg::Warning("BoundaryLayer splitounette3D: invalid corner hex "
                         "metadata");
            continue;
          }

          std::vector<std::vector<std::vector<MVertex *> > > grid(
            n + 1, std::vector<std::vector<MVertex *> >(
                     n + 1, std::vector<MVertex *>(n + 1, nullptr)));

          auto assignEdge = [&](MVertex *v0, MVertex *v1, int axis,
                                std::size_t i0, std::size_t j0,
                                std::size_t k0) {
            std::vector<MVertex *> pv =
              splitedge(MEdge(v0, v1), split, t, hwall, ratio,
                        numExactLayers);
            if(pv.size() != n + 1) return;
            for(std::size_t l = 0; l <= n; ++l) {
              std::size_t ii = i0, jj = j0, kk = k0;
              if(axis == 0) ii = l;
              else if(axis == 1) jj = l;
              else kk = l;
              grid[ii][jj][kk] = pv[l];
            }
          };

          assignEdge(hex.p, hex.a, 0, 0, 0, 0);
          assignEdge(hex.b, hex.sab, 0, 0, n, 0);
          assignEdge(hex.c, hex.sac, 0, 0, 0, n);
          assignEdge(hex.sbc, hex.r, 0, 0, n, n);
          assignEdge(hex.p, hex.b, 1, 0, 0, 0);
          assignEdge(hex.a, hex.sab, 1, n, 0, 0);
          assignEdge(hex.c, hex.sbc, 1, 0, 0, n);
          assignEdge(hex.sac, hex.r, 1, n, 0, n);
          assignEdge(hex.p, hex.c, 2, 0, 0, 0);
          assignEdge(hex.a, hex.sac, 2, n, 0, 0);
          assignEdge(hex.b, hex.sbc, 2, 0, n, 0);
          assignEdge(hex.sab, hex.r, 2, n, n, 0);

          std::vector<std::vector<MVertex *> > &face0 =
            splitIntersectFaceGrid(hex.gr, hex.face01, hex.face02, hex.a,
                                   hex.sab, hex.r, hex.sac,
                                   intersectFaceGrids, split, t, fractions,
                                   hwall, ratio, numExactLayers);
          if(face0.size() == n + 1) {
            for(std::size_t j = 0; j <= n; ++j)
              for(std::size_t k = 0; k <= n; ++k)
                grid[n][j][k] = face0[j][k];
          }

          std::vector<std::vector<MVertex *> > &face1 =
            splitIntersectFaceGrid(hex.gr, hex.face12, hex.face01, hex.b,
                                   hex.sbc, hex.r, hex.sab,
                                   intersectFaceGrids, split, t, fractions,
                                   hwall, ratio, numExactLayers);
          if(face1.size() == n + 1) {
            for(std::size_t i0 = 0; i0 <= n; ++i0)
              for(std::size_t k = 0; k <= n; ++k)
                grid[i0][n][k] = face1[k][i0];
          }

          std::vector<std::vector<MVertex *> > &face2 =
            splitIntersectFaceGrid(hex.gr, hex.face02, hex.face12, hex.c,
                                   hex.sac, hex.r, hex.sbc,
                                   intersectFaceGrids, split, t, fractions,
                                   hwall, ratio, numExactLayers);
          if(face2.size() == n + 1) {
            for(std::size_t i0 = 0; i0 <= n; ++i0)
              for(std::size_t j = 0; j <= n; ++j)
                grid[i0][j][n] = face2[i0][j];
          }

          SPoint3 P = hex.p->point();
          SPoint3 A = hex.a->point();
          SPoint3 AB = hex.sab->point();
          SPoint3 B = hex.b->point();
          SPoint3 C = hex.c->point();
          SPoint3 AC = hex.sac->point();
          SPoint3 R = hex.r->point();
          SPoint3 BC = hex.sbc->point();
          auto trilinearPoint = [&](double u, double v, double w) {
            return SPoint3(
              (1. - u) * (1. - v) * (1. - w) * P.x() +
                u * (1. - v) * (1. - w) * A.x() +
                u * v * (1. - w) * AB.x() +
                (1. - u) * v * (1. - w) * B.x() +
                (1. - u) * (1. - v) * w * C.x() +
                u * (1. - v) * w * AC.x() + u * v * w * R.x() +
                (1. - u) * v * w * BC.x(),
              (1. - u) * (1. - v) * (1. - w) * P.y() +
                u * (1. - v) * (1. - w) * A.y() +
                u * v * (1. - w) * AB.y() +
                (1. - u) * v * (1. - w) * B.y() +
                (1. - u) * (1. - v) * w * C.y() +
                u * (1. - v) * w * AC.y() + u * v * w * R.y() +
                (1. - u) * v * w * BC.y(),
              (1. - u) * (1. - v) * (1. - w) * P.z() +
                u * (1. - v) * (1. - w) * A.z() +
                u * v * (1. - w) * AB.z() +
                (1. - u) * v * (1. - w) * B.z() +
                (1. - u) * (1. - v) * w * C.z() +
                u * (1. - v) * w * AC.z() + u * v * w * R.z() +
                (1. - u) * v * w * BC.z());
          };

          for(std::size_t i0 = 0; i0 <= n; ++i0) {
            const double u = fractions[i0];
            for(std::size_t j = 0; j <= n; ++j) {
              const double v = fractions[j];
              for(std::size_t k = 0; k <= n; ++k) {
                if(grid[i0][j][k]) continue;
                const double w = fractions[k];
                SPoint3 pt = trilinearPoint(u, v, w);
                if(k == 0 && hex.face01)
                  grid[i0][j][k] =
                    createMFaceVertexAtPoint(pt, hex.face01);
                else if(j == 0 && hex.face02)
                  grid[i0][j][k] =
                    createMFaceVertexAtPoint(pt, hex.face02);
                else if(i0 == 0 && hex.face12)
                  grid[i0][j][k] =
                    createMFaceVertexAtPoint(pt, hex.face12);
                else {
                  MVertex *newv =
                    new MVertex(pt.x(), pt.y(), pt.z(), hex.gr);
                  hex.gr->mesh_vertices.push_back(newv);
                  grid[i0][j][k] = newv;
                }
              }
            }
          }

          for(std::size_t i0 = 0; i0 < n; ++i0) {
            for(std::size_t j = 0; j < n; ++j) {
              for(std::size_t k = 0; k < n; ++k) {
                MVertex *v000 = grid[i0][j][k];
                MVertex *v100 = grid[i0 + 1][j][k];
                MVertex *v110 = grid[i0 + 1][j + 1][k];
                MVertex *v010 = grid[i0][j + 1][k];
                MVertex *v001 = grid[i0][j][k + 1];
                MVertex *v101 = grid[i0 + 1][j][k + 1];
                MVertex *v111 = grid[i0 + 1][j + 1][k + 1];
                MVertex *v011 = grid[i0][j + 1][k + 1];
                std::size_t layer = std::max(std::max(i0, j), k);
                if(i0 == 0 && j == 0 && k == 0) {
                  e->setVertex(0, v000);
                  e->setVertex(1, v100);
                  e->setVertex(2, v110);
                  e->setVertex(3, v010);
                  e->setVertex(4, v001);
                  e->setVertex(5, v101);
                  e->setVertex(6, v111);
                  e->setVertex(7, v011);
                  layers[e] = splitLayerWidth(widths, layer, itL->second);
                }
                else {
                  MHexahedron *h =
                    new MHexahedron(v000, v100, v110, v010, v001, v101,
                                    v111, v011);
                  gr->hexahedra.push_back(h);
                  layers[h] = splitLayerWidth(widths, layer, itL->second);
                }
              }
            }
          }
          continue;
        }
      }

      if(type == MSH_HEX_8 && intersectEdgeHexes) {
        auto itIntersect = intersectEdgeHexes->find(e);
        if(itIntersect != intersectEdgeHexes->end()) {
          const BoundaryLayerIntersectEdgeHex &hex = itIntersect->second;
          if(!hex.gr || !hex.p0 || !hex.p1 || !hex.a0 || !hex.a1 ||
             !hex.s0 || !hex.s1 || !hex.b0 || !hex.b1) {
            Msg::Warning("BoundaryLayer splitounette3D: invalid intersect "
                         "edge hex metadata");
            continue;
          }

          std::vector<std::vector<MVertex *> > &g0 =
            splitIntersectFaceGrid(hex.gr, hex.faceA, hex.faceB, hex.p0,
                                   hex.a0, hex.s0, hex.b0,
                                   intersectFaceGrids, split, t, fractions,
                                   hwall, ratio, numExactLayers);
          std::vector<std::vector<MVertex *> > &g1 =
            splitIntersectFaceGrid(hex.gr, hex.faceA, hex.faceB, hex.p1,
                                   hex.a1, hex.s1, hex.b1,
                                   intersectFaceGrids, split, t, fractions,
                                   hwall, ratio, numExactLayers);
          const std::size_t n = g0.size() ? g0.size() - 1 : 0;
          if(!n || g1.size() != n + 1) {
            Msg::Warning("BoundaryLayer splitounette3D: inconsistent "
                         "intersect edge hex split");
            continue;
          }

          for(std::size_t ii = 0; ii < n; ++ii) {
            for(std::size_t jj = 0; jj < n; ++jj) {
              MVertex *v000 = g0[ii][jj];
              MVertex *v100 = g1[ii][jj];
              MVertex *v110 = g1[ii + 1][jj];
              MVertex *v010 = g0[ii + 1][jj];
              MVertex *v001 = g0[ii][jj + 1];
              MVertex *v101 = g1[ii][jj + 1];
              MVertex *v111 = g1[ii + 1][jj + 1];
              MVertex *v011 = g0[ii + 1][jj + 1];
              std::size_t layer = std::max(ii, jj);
              if(ii == 0 && jj == 0) {
                e->setVertex(0, v000);
                e->setVertex(1, v100);
                e->setVertex(2, v110);
                e->setVertex(3, v010);
                e->setVertex(4, v001);
                e->setVertex(5, v101);
                e->setVertex(6, v111);
                e->setVertex(7, v011);
                layers[e] = splitLayerWidth(widths, layer, itL->second);
              }
              else {
                MHexahedron *h =
                  new MHexahedron(v000, v100, v110, v010, v001, v101,
                                  v111, v011);
                gr->hexahedra.push_back(h);
                layers[h] = splitLayerWidth(widths, layer, itL->second);
              }
            }
          }
          continue;
        }
      }

      // -----------------------------
      // PRISM: (0,1,2) bottom, (3,4,5) top
      // -----------------------------
      if(type == MSH_PRI_6) {
        MVertex *b0 = e->getVertex(0);
        MVertex *b1 = e->getVertex(1);
        MVertex *b2 = e->getVertex(2);
        MVertex *t0 = e->getVertex(3);
        MVertex *t1 = e->getVertex(4);
        MVertex *t2 = e->getVertex(5);

        //	printf("nv = 6 %d %d %d %d %d
        //%d\n",b0->getNum(),b1->getNum(),b2->getNum(),
        //	       t0->getNum(),t1->getNum(),t2->getNum())

        // split the 3 "vertical" edges
        std::vector<MVertex *> p0 =
          splitedge(MEdge(b0, t0), split, t, hwall, ratio, numExactLayers);
        Msg::Debug("BoundaryLayer splitounette3D: prism edge 0 split to %zu "
                   "vertices",
                   p0.size());
        std::vector<MVertex *> p1 =
          splitedge(MEdge(b1, t1), split, t, hwall, ratio, numExactLayers);
        std::vector<MVertex *> p2 =
          splitedge(MEdge(b2, t2), split, t, hwall, ratio, numExactLayers);

        // p?.size() should be widths.size()+1 (if splitedge returns both
        // endpoints) We create slabs between index j and j+1
        for(size_t j = 0; j < p0.size() - 1; ++j) {
          MVertex *vb0 = p0[j];
          MVertex *vb1 = p1[j];
          MVertex *vb2 = p2[j];
          MVertex *vt0 = p0[j + 1];
          MVertex *vt1 = p1[j + 1];
          MVertex *vt2 = p2[j + 1];

          if(j == 0) {
            // reuse original element as first layer
            e->setVertex(0, vb0);
            e->setVertex(1, vb1);
            e->setVertex(2, vb2);
            e->setVertex(3, vt0);
            e->setVertex(4, vt1);
            e->setVertex(5, vt2);
            layers[e] = widths[j];
          }
          else {
            MPrism *p = new MPrism(vb0, vb1, vb2, vt0, vt1, vt2);
            gr->prisms.push_back(p);
            layers[p] = widths[j];
          }
        }
      }

      // -----------------------------
      // HEX: (0,1,2,3) bottom, (4,5,6,7) top
      // -----------------------------
      else if(type == MSH_HEX_8) {
        MVertex *b0 = e->getVertex(0);
        MVertex *b1 = e->getVertex(1);
        MVertex *b2 = e->getVertex(2);
        MVertex *b3 = e->getVertex(3);
        MVertex *t0 = e->getVertex(4);
        MVertex *t1 = e->getVertex(5);
        MVertex *t2 = e->getVertex(6);
        MVertex *t3 = e->getVertex(7);

        std::vector<MVertex *> p0 =
          splitedge(MEdge(b0, t0), split, t, hwall, ratio, numExactLayers);
        Msg::Debug("BoundaryLayer splitounette3D: hex edge 0 split to %zu "
                   "vertices",
                   p0.size());
        std::vector<MVertex *> p1 =
          splitedge(MEdge(b1, t1), split, t, hwall, ratio, numExactLayers);
        std::vector<MVertex *> p2 =
          splitedge(MEdge(b2, t2), split, t, hwall, ratio, numExactLayers);
        std::vector<MVertex *> p3 =
          splitedge(MEdge(b3, t3), split, t, hwall, ratio, numExactLayers);

        for(size_t j = 0; j < p0.size() - 1; ++j) {
          MVertex *vb0 = p0[j];
          MVertex *vb1 = p1[j];
          MVertex *vb2 = p2[j];
          MVertex *vb3 = p3[j];
          MVertex *vt0 = p0[j + 1];
          MVertex *vt1 = p1[j + 1];
          MVertex *vt2 = p2[j + 1];
          MVertex *vt3 = p3[j + 1];

          if(j == 0) {
            e->setVertex(0, vb0);
            e->setVertex(1, vb1);
            e->setVertex(2, vb2);
            e->setVertex(3, vb3);
            e->setVertex(4, vt0);
            e->setVertex(5, vt1);
            e->setVertex(6, vt2);
            e->setVertex(7, vt3);
            layers[e] = widths[j];
          }
          else {
            MHexahedron *h =
              new MHexahedron(vb0, vb1, vb2, vb3, vt0, vt1, vt2, vt3);
            gr->hexahedra.push_back(h);
            layers[h] = widths[j];
          }
        }
      }
    }
    Msg::Info("BoundaryLayer splitounette3D: done region %d, split edges=%zu",
              gr->tag(), split.size());
  }

  Msg::Info("BoundaryLayer splitounette3D: replace edges");
  replaceEdges(r[0]->model(), split);
  Msg::Info("BoundaryLayer splitounette3D: replace faces");
  replaceFaces(r[0]->model(), split, layers, widths);
  Msg::Info("BoundaryLayer splitounette3D: done");
}

void splitounette(std::vector<GFace *> &f, std::map<MElement *, double> &layers,
                  std::vector<double> &widths, double hwall, double ratio,
                  double numExactLayers,
                  std::map<MElement *, BoundaryLayerCornerQuad> *cornerBLQuads =
                    nullptr)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  std::vector<double> t;
  double tot = 0.0;
  for(auto w : widths) tot += w;

  double wloc = 0.0;
  for(auto w : widths) {
    wloc += w;
    t.push_back(wloc / tot);
  }
  std::vector<double> fractions;
  fractions.push_back(0.);
  fractions.insert(fractions.end(), t.begin(), t.end());

  //  for (auto w : widths) printf("%12.5E\n",w);
  //  for (auto x : t) printf("%12.5E\n",x);

  for(auto gf : f) {
    std::vector<MElement *> temp;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++)
      temp.push_back(gf->getMeshElement(i));

    for(size_t i = 0; i < temp.size(); i++) {
      if(layers.find(temp[i]) != layers.end()) {
        if(cornerBLQuads) {
          auto itCorner = cornerBLQuads->find(temp[i]);
          if(itCorner != cornerBLQuads->end()) {
          BoundaryLayerCornerQuad &corner = itCorner->second;
          if(!corner.gf) corner.gf = gf;
          std::vector<MVertex *> pPA =
            splitedge(MEdge(corner.p, corner.a), split, t, hwall, ratio,
                      numExactLayers);
          std::vector<MVertex *> pAS =
            splitedge(MEdge(corner.a, corner.s), split, t, hwall, ratio,
                      numExactLayers);
          std::vector<MVertex *> pBS =
            splitedge(MEdge(corner.b, corner.s), split, t, hwall, ratio,
                      numExactLayers);
          std::vector<MVertex *> pPB =
            splitedge(MEdge(corner.p, corner.b), split, t, hwall, ratio,
                      numExactLayers);
          const std::size_t n = pPA.size() ? pPA.size() - 1 : 0;
          if(!n || pAS.size() != n + 1 || pBS.size() != n + 1 ||
             pPB.size() != n + 1 || fractions.size() != n + 1) {
            Msg::Warning("BoundaryLayer corner quad at point %d on face %d "
                         "could not be split consistently",
                         corner.gv ? corner.gv->tag() : 0,
                         corner.gf ? corner.gf->tag() : gf->tag());
            continue;
          }

          std::vector<std::vector<MVertex *> > grid(
            n + 1, std::vector<MVertex *>(n + 1, nullptr));
          for(std::size_t ie = 0; ie <= n; ++ie) {
            grid[ie][0] = pPA[ie];
            grid[ie][n] = pBS[ie];
          }
          for(std::size_t je = 0; je <= n; ++je) {
            grid[0][je] = pPB[je];
            grid[n][je] = pAS[je];
          }

          SPoint3 P = corner.p->point();
          SPoint3 A = corner.a->point();
          SPoint3 S = corner.s->point();
          SPoint3 B = corner.b->point();
          for(std::size_t ie = 1; ie < n; ++ie) {
            const double u = fractions[ie];
            for(std::size_t je = 1; je < n; ++je) {
              const double v = fractions[je];
              const double x = (1. - u) * (1. - v) * P.x() +
                               u * (1. - v) * A.x() + u * v * S.x() +
                               (1. - u) * v * B.x();
              const double y = (1. - u) * (1. - v) * P.y() +
                               u * (1. - v) * A.y() + u * v * S.y() +
                               (1. - u) * v * B.y();
              const double z = (1. - u) * (1. - v) * P.z() +
                               u * (1. - v) * A.z() + u * v * S.z() +
                               (1. - u) * v * B.z();
              grid[ie][je] =
                createMFaceVertexAtPoint(SPoint3(x, y, z), corner.gf);
            }
          }

          for(std::size_t ie = 0; ie < n; ++ie) {
            for(std::size_t je = 0; je < n; ++je) {
              MVertex *v0 = grid[ie][je];
              MVertex *v1 = grid[ie + 1][je];
              MVertex *v2 = grid[ie + 1][je + 1];
              MVertex *v3 = grid[ie][je + 1];
              std::size_t layer = std::max(ie, je);
              if(layer >= widths.size()) layer = widths.size() - 1;
              if(ie == 0 && je == 0) {
                temp[i]->setVertex(0, v0);
                temp[i]->setVertex(1, v1);
                temp[i]->setVertex(2, v2);
                temp[i]->setVertex(3, v3);
                layers[temp[i]] = widths[layer];
              }
              else {
                MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
                corner.gf->quadrangles.push_back(q);
                layers[q] = widths[layer];
              }
            }
          }
          continue;
        }
        }
        if(temp[i]->getNumEdges() == 3) {
          //	  printf("FAN %d %d
          //%d\n",temp[i]->getVertex(0)->getNum(),temp[i]->getVertex(1)->getNum(),temp[i]->getVertex(2)->getNum());
          MEdge m01 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(1));
          MEdge m02 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(2));
          std::vector<MVertex *> p01 =
            splitedge(m01, split, t, hwall, ratio, numExactLayers);
          std::vector<MVertex *> p02 =
            splitedge(m02, split, t, hwall, ratio, numExactLayers);
          temp[i]->setVertex(1, p01[1]);
          temp[i]->setVertex(2, p02[1]);
          layers[temp[i]] = widths[0];
          for(size_t j = 1; j < p01.size() - 1; j++) {
            MVertex *v0 = p01[j];
            MVertex *v1 = p01[j + 1];
            MVertex *v2 = p02[j + 1];
            MVertex *v3 = p02[j];
            MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
            gf->quadrangles.push_back(q);
            layers[q] = widths[j];
          }
        }
        else if(temp[i]->getNumEdges() == 4) {
          MEdge m03 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(3));
          MEdge m12 = MEdge(temp[i]->getVertex(1), temp[i]->getVertex(2));
          std::vector<MVertex *> p03 =
            splitedge(m03, split, t, hwall, ratio, numExactLayers);
          std::vector<MVertex *> p12 =
            splitedge(m12, split, t, hwall, ratio, numExactLayers);
          for(size_t j = 0; j < p03.size() - 1; j++) {
            MVertex *v0 = p03[j];
            MVertex *v1 = p12[j];
            MVertex *v2 = p12[j + 1];
            MVertex *v3 = p03[j + 1];
            if(j == 0) {
              temp[i]->setVertex(0, v0);
              temp[i]->setVertex(1, v1);
              temp[i]->setVertex(2, v2);
              temp[i]->setVertex(3, v3);
              layers[temp[i]] = widths[j];
            }
            else {
              MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
              gf->quadrangles.push_back(q);
              layers[q] = widths[j];
            }
          }
        }
      }
    }
    auto edges = gf->edges();
    for(auto ge : edges) {
      MLine *l0 = ge->lines.front();
      MLine *l1 = ge->lines.back();
      MEdge m0 = MEdge(l0->getVertex(0), l0->getVertex(1));
      MEdge m1 = MEdge(l1->getVertex(0), l1->getVertex(1));
      auto it0 = split.find(m0);
      auto it1 = split.find(m1);

      if(it0 != split.end()) {
        //	printf("coucou %d
        //%d\n",ge->tag(),l0->getVertex(0)->onWhat()->dim());
        std::vector<MLine *> old = ge->lines;
        ge->lines.clear();
        for(size_t j = 0; j < it0->second.size() - 1; j++)
          ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
        for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
        delete old.front();
      }
      if(it1 != split.end()) {
        //	printf("poucou %d
        //%d\n",ge->tag(),l1->getVertex(0)->onWhat()->dim());
        size_t s = it1->second.size();
        ge->lines.back()->setVertex(0, it1->second[s - 2]);
        for(size_t j = 2; j < s; j++)
          ge->lines.push_back(
            new MLine(it1->second[s - j], it1->second[s - j - 1]));
      }
    }
  }
}

std::string GMSH_BoundaryLayerPlugin::parse(std::string str,
                                            std::list<int> &physical)
{
  // Remove spaces
  str.erase(remove(str.begin(), str.end(), ' '), str.end());

  // Replace commas by spaces
  replace(str.begin(), str.end(), ',', ' ');

  // Init string stream
  std::stringstream stream;
  stream << str;

  // Parse stream for integers
  int tag;
  std::string tmp;
  while(!stream.eof()) {
    stream >> tmp; // Take next 'word'
    if(sscanf(tmp.c_str(), "%d", &tag) > 0) physical.push_back(tag);
  }

  // Return modified string
  return str;
}

template <class T>
static void removeDuplicatePointers(std::vector<T *> &entities,
                                    const char *what)
{
  std::set<T *> seen;
  std::vector<T *> unique;
  unique.reserve(entities.size());
  for(T *entity : entities) {
    if(!entity) continue;
    if(seen.insert(entity).second) unique.push_back(entity);
  }
  if(unique.size() != entities.size())
    Msg::Info("Boundary layer: removed %zu duplicate %s entr%s",
              entities.size() - unique.size(), what ? what : "entity",
              entities.size() - unique.size() == 1 ? "y" : "ies");
  entities.swap(unique);
}

void computePerfectShapes(
  std::vector<GFace *> &f,
  std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes,
  std::map<MElement *, BoundaryLayerCornerQuad> *cornerBLQuads = nullptr)
{
  // printf("COMPUTE PERFECT SHAPES for %lu\n", f.size());
  for(auto gf : f) {
    //      std::map<MVertex*,SPoint2> ivp;
    double area = 0.0;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
      std::vector<SPoint2> pts;
      for(size_t j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
        SPoint2 param;
        reparamMeshVertexOnFace(gf->getMeshElement(i)->getVertex(j), gf, param);
        pts.push_back(param);
      }
      if(pts.size() == 3) {
        std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
        std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
        std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
        area += triangle_area_2d(vs0, vs1, vs2);
      }
      else if(pts.size() == 4) {
        std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
        std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
        std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
        std::array<double, 2> vs3 = {pts[3].x(), pts[3].y()};
        area += triangle_area_2d(vs0, vs1, vs2);
        area += triangle_area_2d(vs0, vs2, vs3);
      }
    }

    printf("area (%d) = %g\n", gf->tag(), area);

    for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      if(cornerBLQuads) {
        auto itCorner = cornerBLQuads->find(e);
        if(itCorner != cornerBLQuads->end()) {
          BoundaryLayerCornerQuad &corner = itCorner->second;
          SPoint2 p, a, b;
          reparamMeshVertexOnFace(corner.p, gf, p);
          reparamMeshVertexOnFace(corner.a, gf, a);
          reparamMeshVertexOnFace(corner.b, gf, b);
          std::array<double, 2> vs0 = {p.x(), p.y()};
          std::array<double, 2> vs1 = {a.x(), a.y()};
          std::array<double, 2> vs3 = {b.x(), b.y()};
          std::array<double, 2> vs2 = {vs1[0] + vs3[0] - vs0[0],
                                       vs1[1] + vs3[1] - vs0[1]};
          double qArea = triangle_area_2d(vs0, vs1, vs2) +
                         triangle_area_2d(vs0, vs2, vs3);
          if((area > 0. && qArea < 0.) || (area < 0. && qArea > 0.)) {
            std::swap(corner.a, corner.b);
            std::swap(corner.edgeA, corner.edgeB);
            e->setVertex(1, corner.a);
            e->setVertex(3, corner.b);
            reparamMeshVertexOnFace(corner.a, gf, a);
            reparamMeshVertexOnFace(corner.b, gf, b);
            vs1 = {a.x(), a.y()};
            vs3 = {b.x(), b.y()};
            vs2 = {vs1[0] + vs3[0] - vs0[0],
                   vs1[1] + vs3[1] - vs0[1]};
          }
          perfectShapes[e] = {vs0, vs1, vs2, vs3};
          continue;
        }
      }
      std::vector<SPoint2> pts;
      for(size_t j = 0; j < e->getNumVertices(); j++) {
        SPoint2 param;
        reparamMeshVertexOnFace(e->getVertex(j), gf, param);
        pts.push_back(param);
      }
      std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
      std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
      std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
      if(pts.size() == 3) {
        if(area > 0)
          perfectShapes[e] = {vs0, vs1, vs2, vs2};
        else
          perfectShapes[e] = {vs1, vs0, vs2, vs2};
      }
      else {
        std::array<double, 2> vs3 = {pts[3].x(), pts[3].y()};
        if(area > 0)
          perfectShapes[e] = {vs0, vs1, vs2, vs3};
        else
          perfectShapes[e] = {vs1, vs0, vs3, vs2};
      }
    }
  }
}

void computePerfectShapes(
  std::vector<GRegion *> &r,
  std::map<MElement *, std::array<std::array<double, 3>, 8>> &perfectShapes)
{
  for(auto gr : r) {
    for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      std::array<std::array<double, 3>, 8> vs = {};
      for(size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = e->getVertex(j);
        vs[j] = {v->x(), v->y(), v->z()};
      }
      int type = e->getTypeForMSH();
      if(type != MSH_TET_4 && type != MSH_PRI_6 && type != MSH_HEX_8 &&
         type != MSH_PYR_5)
        continue;
      perfectShapes[e] = {vs[0], vs[1], vs[2], vs[3],
                          vs[4], vs[5], vs[6], vs[7]};
    }
  }
}

PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  std::string volume = BoundaryLayerOptions_String[0].def;
  std::string surface = BoundaryLayerOptions_String[1].def;
  std::string curve = BoundaryLayerOptions_String[2].def;
  std::string point = BoundaryLayerOptions_String[3].def;
  std::string intersectPoint = BoundaryLayerOptions_String[4].def;
  std::string intersectEdge = BoundaryLayerOptions_String[5].def;

  std::vector<std::list<int>> entities(6);
  point = parse(point, entities[0]);
  curve = parse(curve, entities[1]);
  surface = parse(surface, entities[2]);
  volume = parse(volume, entities[3]);
  intersectPoint = parse(intersectPoint, entities[4]);
  intersectEdge = parse(intersectEdge, entities[5]);

  std::vector<GVertex *> vv;
  for(auto v : entities[0]) {
    GVertex *gv = m->getVertexByTag(v);
    if(gv) vv.push_back(gv);
  }
  for(auto v : entities[4]) {
    GVertex *gv = m->getVertexByTag(v);
    if(gv) vv.push_back(gv);
  }
  std::vector<GEdge *> e;
  for(auto c : entities[1]) {
    GEdge *ge = m->getEdgeByTag(c);
    if(ge) e.push_back(ge);
  }
  std::vector<GEdge *> intersectEdges;
  for(auto c : entities[5]) {
    GEdge *ge = m->getEdgeByTag(c);
    if(ge) intersectEdges.push_back(ge);
  }
  std::vector<GFace *> f;
  for(auto s : entities[2]) {
    GFace *gf = m->getFaceByTag(s);
    if(gf) f.push_back(gf);
  }
  std::vector<GRegion *> r;
  for(auto e : entities[3]) {
    GRegion *gr = m->getRegionByTag(e);
    if(gr) r.push_back(gr);
  }
  removeDuplicatePointers(vv, "point");
  removeDuplicatePointers(e, "curve");
  removeDuplicatePointers(intersectEdges, "intersect-edge");
  removeDuplicatePointers(f, "surface");
  removeDuplicatePointers(r, "volume");

  double thickness = BoundaryLayerOptions_Number[0].def;
  double size = BoundaryLayerOptions_Number[1].def;
  double ratio = BoundaryLayerOptions_Number[2].def;
  int numLayers = (int)BoundaryLayerOptions_Number[3].def;
  double numExactLayers = BoundaryLayerOptions_Number[4].def;
  int highOrder = (int)BoundaryLayerOptions_Number[5].def;
  int highOrderStrategy = (int)BoundaryLayerOptions_Number[6].def;
  int highOrderPostSplitUntangle = (int)BoundaryLayerOptions_Number[7].def;
  int highOrderPostSplitSurfaceUntangle =
    (int)BoundaryLayerOptions_Number[8].def;
  int surfaceUntangler = (int)BoundaryLayerOptions_Number[9].def;
  double meanPlaneTolerance = BoundaryLayerOptions_Number[10].def;
  double meanPlaneExtensionTolerance = BoundaryLayerOptions_Number[11].def;
  int meanPlanePatchRings = (int)BoundaryLayerOptions_Number[12].def;
  int meanPlaneSweeps = (int)BoundaryLayerOptions_Number[13].def;
  double meanPlaneMoveTolerance = BoundaryLayerOptions_Number[14].def;
  bool meanPlaneDebugPatches =
    (int)BoundaryLayerOptions_Number[15].def != 0;
  int parametricQuadraturePoints = (int)BoundaryLayerOptions_Number[16].def;
  if(numLayers < 1) {
    Msg::Warning("Hey ! at least one smoothing layer dude ...");
    numLayers = 1;
  }
  if(highOrder < 1) highOrder = 1;
  if(highOrderStrategy < 0) highOrderStrategy = 0;
  if(surfaceUntangler < 1 || surfaceUntangler > 3) {
    Msg::Warning("Unknown BoundaryLayer SurfaceUntangler %d; using 1 "
                 "(standard parametric)",
                 surfaceUntangler);
    surfaceUntangler = 1;
  }
  if(meanPlanePatchRings < 0) meanPlanePatchRings = 0;
  if(meanPlaneSweeps < 1) meanPlaneSweeps = 1;
  if(meanPlaneMoveTolerance < 0.) meanPlaneMoveTolerance = 0.;
  if(parametricQuadraturePoints < 1) parametricQuadraturePoints = 1;

  std::map<MElement *, double> layers;
  std::map<MElement *, BoundaryLayerCornerQuad> cornerBLQuads;
  std::map<MElement *, BoundaryLayerIntersectEdgeHex> intersectEdgeHexes;
  std::map<MElement *, BoundaryLayerIntersectCornerHex> intersectCornerHexes;
  SurfaceUntanglerP1Stats p1FaceUntanglerStats;

  //  printf("perfectshapes = %zu\n",perfectShapes.size());

  double ww = 0.0;
  std::vector<double> ws;
  double hwall = size;
  while(1) {
    ws.push_back(hwall);
    ww += hwall;
    if(ww + hwall >= thickness) break;
    hwall *= ratio;
  }

  //  printf("ww = %12.5E\n",ww);
  //  double h = 0.;
  //  for (auto wid  : ws){
  //    h += wid;
  //    printf("h = %g y = %g\n",wid,h);
  //  }

  std::vector<GFace *> toExpand;

  if(r.empty())
    bl(m, vv, e, f, ww * 1.2, layers, &cornerBLQuads);
  else {
    bl3d(m, f, r, ww, layers, toExpand, intersectEdges,
         &intersectEdgeHexes, &intersectCornerHexes, &cornerBLQuads);
    removeDuplicatePointers(toExpand, "surface-to-expand");
  }

  std::map<MElement *, std::array<std::array<double, 2>, 4>> perfectShapes;
  std::map<MElement *, std::array<std::array<double, 3>, 8>> perfectShapes3D;
  if(!r.empty()) {
    computePerfectShapes(r, perfectShapes3D);
    computePerfectShapes(toExpand, perfectShapes, &cornerBLQuads);
  }

  for(GModel::eiter eit = m->firstEdge(); eit != m->lastEdge(); ++eit)
    meshGEdgeInsertBoundaryLayer(*eit, ww);

  if(r.empty()) { computePerfectShapes(f, perfectShapes, &cornerBLQuads); }

  if(r.empty()) {
    for(auto gf : f)
      expandBL(gf, perfectShapes, layers, f, numLayers,
               surfaceUntangler, meanPlaneTolerance,
               meanPlaneExtensionTolerance, meanPlanePatchRings,
               meanPlaneSweeps, meanPlaneMoveTolerance,
               meanPlaneDebugPatches,
               parametricQuadraturePoints,
               &p1FaceUntanglerStats);
  }
  else {
    for(auto gf : toExpand) {
      expandBL(gf, perfectShapes, layers, toExpand, numLayers,
               surfaceUntangler, meanPlaneTolerance,
               meanPlaneExtensionTolerance, meanPlanePatchRings,
               meanPlaneSweeps, meanPlaneMoveTolerance,
               meanPlaneDebugPatches,
               parametricQuadraturePoints,
               &p1FaceUntanglerStats);
    }
    for(auto gr : r) {
      expandBL3D(gr, perfectShapes3D, layers, numLayers, &intersectEdgeHexes,
                 &intersectCornerHexes);
    }
  }

  if(r.empty()) {
    if(highOrder <= 1 || highOrderStrategy == 1) {
      if(ws.size() > 1) {
        if(highOrder > 1)
          Msg::Info("Boundary layer high-order mode: splitting %zu low-order "
                    "layers before P%d untangling",
                    ws.size(), highOrder);
        splitounette(f, layers, ws, size, ratio, numExactLayers,
                     &cornerBLQuads);
      }
    }
    else if(ws.size() > 1) {
      Msg::Info("Boundary layer high-order mode: delaying layer splitting to "
                "high-order strategy %d",
                highOrderStrategy);
    }
  }
  else if(ws.size() > 1) {
    if(highOrder <= 1 || highOrderStrategy == 1) {
      if(highOrder > 1)
        Msg::Info("Boundary layer high-order mode: splitting %zu low-order "
                  "volume layers before P%d untangling",
                  ws.size(), highOrder);
      splitounette3D(r, layers, ws, size, ratio, numExactLayers,
                     &intersectEdgeHexes, &intersectCornerHexes);
      Msg::Info("Boundary layer: skipping post-3D-split 2D surface "
                "untangling");
    }
    else {
      Msg::Info("Boundary layer high-order mode: delaying volume layer "
                "splitting to high-order strategy %d",
                highOrderStrategy);
    }
  }

  Msg::Info("Boundary layer P1 face untangler summary: mean-plane %zu, "
            "metric-parametric %zu, fallback parametric %zu, parametric %zu, "
            "empty %zu",
            p1FaceUntanglerStats.meanPlane,
            p1FaceUntanglerStats.metricParametric,
            p1FaceUntanglerStats.fallbackParametric,
            p1FaceUntanglerStats.parametric, p1FaceUntanglerStats.empty);

  if(highOrder > 1) {
    std::set<MElement *, MElementPtrLessThan> toProcess;
    std::set<MVertex *, MVertexPtrLessThan> fixed;
    if(r.empty()) {
      for(auto gf : f)
        buildUntangleSets(gf, /*targetDim=*/2, layers, numLayers, toProcess,
                          fixed);
    }
    else {
      for(auto gf : toExpand)
        buildUntangleSets(gf, /*targetDim=*/2, layers, numLayers, toProcess,
                          fixed);
      for(auto gr : r)
        buildUntangleSets(gr, /*targetDim=*/3, layers, numLayers, toProcess,
                          fixed);
    }
    untangleHighOrderBoundaryLayerPN(m, toProcess, fixed, highOrder, &layers,
                                     &ws, highOrderStrategy,
                                     highOrderPostSplitUntangle != 0,
                                     highOrderPostSplitSurfaceUntangle != 0,
                                     surfaceUntangler,
                                     meanPlaneTolerance,
                                     meanPlaneExtensionTolerance,
                                     meanPlanePatchRings,
                                     meanPlaneSweeps,
                                     meanPlaneMoveTolerance,
                                     meanPlaneDebugPatches,
                                     parametricQuadraturePoints);
  }

  //  for (auto gf : f)
  //    expandL(gf, perfectShapes, layers, f);

  CTX::instance()->mesh.changed = ENT_ALL;

  return v;
}
