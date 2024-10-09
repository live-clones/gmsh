#include "GmshConfig.h"
#include "OS.h"
#include "Context.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertexRTree.h"
#include "Numeric.h"
#include "robustPredicates.h"
#include "gmsh.h"

#include "meshGFaceGeodesic.h"

#if defined(HAVE_MESH) && defined(HAVE_GEODESIC)

#include "qualityMeasures.h"
#include "GModelParametrize.h"
#include "geodesic_algorithm_exact.h"
#include "geodesic_mesh_elements.h"


#define EPS 1e-16

static int getNumThreads();

template <typename T>
T interpolate(std::vector<T> & values, geodesic::SurfacePoint & sp) {
  if (values.empty()) Msg::Error("values not defined");
  if (sp.type() == geodesic::VERTEX) {
    geodesic::Vertex *v = (geodesic::Vertex *) sp.base_element();

    if (values.size()-1 < v->id()) Msg::Error("Value not defined for vertex");
    return values[v->id()];
  }

  if (sp.type() == geodesic::EDGE) {
    geodesic::Edge *e = (geodesic::Edge *) sp.base_element();
    geodesic::Vertex *v0 = e->v0();
    geodesic::Vertex *v1 = e->v1();

    SVector3 d = SVector3(sp.x() - v0->x(), sp.y() - v0->y(), sp.z() - v0->z());
    SVector3 d1 = SVector3(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    double t = dot(d1, d) / dot(d1, d1);

    if (values.size()-1 < v0->id() || values.size()-1 < v1->id()) Msg::Error("Value not defined for vertex");
    T p0 = values[v0->id()];
    T p1 = values[v1->id()];
    T p = ((1-t) * p0 + t * p1);
    return p;
  }

  if (sp.type() == geodesic::FACE) {
    geodesic::Face *f = (geodesic::Face *) sp.base_element();
    auto & v0 = f->adjacent_vertices()[0];
    auto & v1 = f->adjacent_vertices()[1];
    auto & v2 = f->adjacent_vertices()[2];

    SVector3 d = SVector3(sp.x() - v0->x(), sp.y() - v0->y(), sp.z() - v0->z());
    SVector3 d1 = SVector3(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    SVector3 d2 = SVector3(v2->x() - v0->x(), v2->y() - v0->y(), v2->z() - v0->z());
    double a = crossprod(d1, d2).norm();
    double v = crossprod(d1, d).norm() / a;
    double u = crossprod(d, d2).norm() / a;

    if (values.size()-1 < v0->id() || values.size()-1 < v1->id() || values.size()-1 < v2->id()) Msg::Error("Value not defined for vertex");
    T p0 = values[v0->id()];
    T p1 = values[v1->id()];
    T p2 = values[v2->id()];
    T p = ((1-u-v) * p0 + u * p1 + v * p2);
    return p;
  }

  Msg::Error("SurfacePoint type unknown");
  return T();
}

SPoint3 highOrderPolyMesh::getTrueCoords(geodesic::SurfacePoint &sp)
{
  SVector3 p = interpolate<SVector3>(trueCoord, sp);
  return SPoint3(p);
}

double highOrderPolyMesh::cl(geodesic::SurfacePoint &sp)
{
  double p = interpolate<double>(characLength, sp);
  return p;
}


PolyMesh *createPolyMesh(const std::vector<double> &p,
                         const std::vector<size_t> &t,
                         const std::vector<size_t> &e,
                         const std::vector<size_t> &vertexNum)
{
  PolyMesh *pm_new = new PolyMesh;

  //int cc = 0;
  for(size_t i = 0; i < p.size(); i += 3) {
    int tag = vertexNum.empty() ? i/3 : vertexNum[i/3];
    pm_new->vertices.push_back(
      new PolyMesh::Vertex(p[i], p[i + 1], p[i + 2], tag));
  }

  for(size_t i = 0; i < t.size(); i += 3) {
    PolyMesh::HalfEdge *he[3];
    for(std::size_t j = 0; j < 3; j++) {
      PolyMesh::Vertex *vv = pm_new->vertices[t[i + j]];
      he[j] = new PolyMesh::HalfEdge(vv);
      pm_new->hedges.push_back(he[j]);
      vv->he = he[j];
    }
    PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
    ff->data = pm_new->faces.size();
    pm_new->faces.push_back(ff);
    for(int j = 0; j < 3; j++) {
      he[j]->next = he[(j + 1) % 3];
      he[j]->prev = he[(j - 1 + 3) % 3];
      he[j]->f = ff;
    }
  }

  HalfEdgePtrLessThan compare;
  std::sort(pm_new->hedges.begin(), pm_new->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(size_t i = 0; i + 1 < pm_new->hedges.size(); i++) {
    PolyMesh::HalfEdge *h0 = pm_new->hedges[i];
    PolyMesh::HalfEdge *h1 = pm_new->hedges[i + 1];
    if(equal(h0, h1)) {
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
    }
  }

  if (e.size() == 0)
    return pm_new;

  FILE *f = fopen("test.pos", "w");
  fprintf(f, "View\"\"{\n");

  for(size_t i = 0; i < e.size(); i += 3) {
    PolyMesh::Vertex *v0 = pm_new->vertices[e[i]];
    PolyMesh::Vertex *v1 = pm_new->vertices[e[i + 1]];
    PolyMesh::HalfEdge *he01 = pm_new->getEdge(v0, v1);
    PolyMesh::HalfEdge *he10 = pm_new->getEdge(v1, v0);
    if(he01) {
      fprintf(f, "SL(%12.5E,%12.5E,%12.5E,%12.5E, %12.5E, %12.5E){%lu,%lu};\n",
              v0->position.x(), v0->position.y(), v0->position.z(),
              v1->position.x(), v1->position.y(), v1->position.z(), e[i + 2],
              e[i + 2]);
      he01->data = e[i + 2];
    }
    else
      Msg::Debug("Non existing edge -- %d %d", e[i], e[i + 1]);
    if(he10) {
      fprintf(f, "SL(%12.5E,%12.5E,%12.5E,%12.5E, %12.5E, %12.5E){%lu,%lu};\n",
              v0->position.x(), v0->position.y(), v0->position.z(),
              v1->position.x(), v1->position.y(), v1->position.z(),
              e[i + 2] + 1, e[i + 2] + 1);
      he10->data = e[i + 2];
    }
    else
      Msg::Debug("Non existing edge -- %d %d", e[i], e[i + 1]);
  }
  fprintf(f, "};\n");
  fclose(f);

  for(auto f : pm_new->faces) f->data = -1;
  int faceTag = 1;
  for(auto f : pm_new->faces) {
    if(f->data == -1) {
      std::stack<PolyMesh::Face *> _s;
      _s.push(f);
      int count = 1;
      f->data = faceTag;
      while(!_s.empty()) {
        PolyMesh::Face *_f = _s.top();
        _s.pop();
        PolyMesh::HalfEdge *he = _f->he;
        do {
          if(he->data == -1 && he->opposite && he->opposite->f->data == -1) {
            he->opposite->f->data = faceTag;
            count++;
            _s.push(he->opposite->f);
          }
          he = he->next;
        } while(he != _f->he);
      }
      faceTag++;
    }
  }

  // Msg::Info("%d isogeometric triangles were generated", faceTag - 1);

  return pm_new;
}

static PolyMesh *createPolyMesh(PolyMesh *pm, const std::vector<size_t> &t,
                                const std::vector<size_t> &e)
{
  int cc = 0;
  std::vector<double> pos;
  for(auto vv : pm->vertices) {
    if(cc++ != vv->data) Msg::Warning("Wrong numbering %d %d", cc, vv->data);
    pos.push_back(vv->position.x());
    pos.push_back(vv->position.y());
    pos.push_back(vv->position.z());
  }

  PolyMesh *pm_new = createPolyMesh(pos, t, e);

  return pm_new;
}

struct VertexOnEdge {
  VertexOnEdge() : v(nullptr) {}
  PolyMesh::HalfEdge *he; // he in the extrinsic_ mesh
  double t; // local coordinates of the vertex in that edge
  size_t tag;
  MVertex *v;
  SVector3 point() const
  {
    return he->v->position * (1. - t) + he->next->v->position * t;
  }
};

// static PolyMesh *
// createPolyMesh(GModel *gm,
//                std::map<MVertex *, int, MVertexPtrLessThan> &trianglePositions)
// {
//   const double eps = 1.e-8; // FIXME
//   MVertexRTree pos(eps);
//   PolyMesh *pm = new PolyMesh;

//   int counter = 0;
//   for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
//     discreteFace *df = static_cast<discreteFace *>(*fit);
//     if(!df) continue;
//     for(std::size_t i = 0; i < df->_param.v3d.size(); i++)
//       df->_param.v3d[i].setIndex(-1);
//   }

//   size_t faceCounter = 0;

//   for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
//     std::set<MVertex *> vs;
//     for(auto t : (*fit)->triangles) {
//       vs.insert(t->getVertex(0));
//       vs.insert(t->getVertex(1));
//       vs.insert(t->getVertex(2));
//     }
//     discreteFace *df = static_cast<discreteFace *>(*fit);
//     //-------------------------------------------------------------
//     for(auto _v : vs) {
//       MFaceVertex *vk = dynamic_cast<MFaceVertex *>(_v);
//       if(vk) {
//         double u, v, uloc, vloc;
//         vk->getParameter(0, u);
//         vk->getParameter(1, v);
//         int tp = df->trianglePosition(u, v, uloc, vloc);
//         //	printf("face %d vertex %d param %g %g triangle position %d
//         //parametric ? %d\n",
//         //	       df->tag(),vk->getNum(),u,v,tp,vk->getParameter(0,u));
//         trianglePositions[vk] = tp + faceCounter;
//       }
//       MEdgeVertex *ve = dynamic_cast<MEdgeVertex *>(_v);
//       if(ve) {
//         GEdge *ge = dynamic_cast<GEdge *>(ve->onWhat());
//         if(ge) {
//           double epar;
//           ve->getParameter(0, epar);
//           SPoint2 p2 = ge->reparamOnFace(df, epar, 0);
//           double uloc, vloc;
//           int tp = df->trianglePosition(p2.x(), p2.y(), uloc, vloc);
//           trianglePositions[ve] = tp + faceCounter;
//         }
//       }
//       if(!ve && !vk) { trianglePositions[_v] = -1; }
//     }
//     //-------------------------------------------------------------
//     for(std::size_t i = 0; i < df->_param.t3d.size(); i++) {
//       for(std::size_t j = 0; j < 3; j++) {
//         MVertex *vv = pos.insert(df->_param.t3d[i].getVertex(j));
//         if(!vv)
//           vv = df->_param.t3d[i].getVertex(j);
//         else
//           df->_param.t3d[i].getVertex(j)->setIndex(vv->getIndex());
//         //	else   printf("FOUND face %d t %lu v %lu %p\n",df->tag(),i,j,vv);
//         if(vv->getIndex() == -1) {
//           pm->vertices.push_back(
//             new PolyMesh::Vertex(vv->x(), vv->y(), vv->z(), counter));
//           vv->setIndex(counter++);
//         }
//       }
//     }
//     faceCounter += df->_param.t3d.size();
//   }

//   for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
//     discreteFace *df = static_cast<discreteFace *>(*fit);
//     if(!df) continue;
//     for(std::size_t i = 0; i < df->_param.t3d.size(); i++) {
//       PolyMesh::HalfEdge *he[3];
//       for(std::size_t j = 0; j < 3; j++) {
//         PolyMesh::Vertex *vv =
//           pm->vertices[df->_param.t3d[i].getVertex(j)->getIndex()];
//         he[j] = new PolyMesh::HalfEdge(vv);
//         pm->hedges.push_back(he[j]);
//         vv->he = he[j];
//       }
//       PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
//       pm->faces.push_back(ff);
//       for(int j = 0; j < 3; j++) {
//         he[j]->next = he[(j + 1) % 3];
//         he[j]->prev = he[(j - 1 + 3) % 3];
//         he[j]->f = ff;
//       }
//     }
//   }

//   HalfEdgePtrLessThan compare;
//   std::sort(pm->hedges.begin(), pm->hedges.end(), compare);

//   HalfEdgePtrEqual equal;
//   for(size_t i = 0; i < pm->hedges.size() - 1; i++) {
//     PolyMesh::HalfEdge *h0 = pm->hedges[i];
//     PolyMesh::HalfEdge *h1 = pm->hedges[i + 1];
//     if(equal(h0, h1)) {
//       h0->opposite = h1;
//       h1->opposite = h0;
//       i++;
//     }
//   }
//   return pm;
// }

static int onBoundary(PolyMesh::VertexOnSurface &vof, double eps,
                      int expectedDim)
{
  double u = vof.u;
  double v = vof.v;
  if(sqrt(u * u + v * v) < eps) { vof.dim = 0; }
  else if(sqrt((u - 1) * (u - 1) + v * v) < eps) {
    vof.dim = 0;
    vof.he = vof.he->next;
  }
  else if(sqrt(u * u + (v - 1) * (v - 1)) < eps) {
    vof.dim = 0;
    vof.he = vof.he->next->next;
  }
  else if(v < eps) {
    vof.dim = 1;
    vof.u = u;
  }
  else if(1 - u - v < eps) {
    vof.dim = 1;
    vof.he = vof.he->next;
    vof.u = v;
  }
  else if(u < eps) {
    vof.dim = 1;
    vof.he = vof.he->next->next;
    vof.u = 1. - v;
  }
  if(vof.dim == expectedDim) {
    if(expectedDim != 2)
      Msg::Debug("expected dim %d dim %d\b", expectedDim, vof.dim);
    return 0;
  }
  Msg::Warning("Expected a surface point classified on dimension %d but "
               "dimension is %d local coord (%22.15E,%22.15E,%22.15E)",
               expectedDim, vof.dim, u, v, 1 - u - v);

  return -1;
}

static PolyMesh::VertexOnSurface findVertexOnSurface(PolyMesh *pm, MVertex *v,
                                                     int pos, bool deb = false)
{
  SVector3 P(v->x(), v->y(), v->z());
  PolyMesh::VertexOnSurface vof;
  double minvol = 1.e22, _u = 1.e22, _v = 1.e22;
  const double eps = 1.e-11;
  vof.he = nullptr;

  size_t SIZE = pm->faces.size();
  if(pos < 0) pos = 0;
  for(size_t cc = 0; cc < SIZE; cc++) {
    PolyMesh::Face *f = pm->faces[(cc + pos) % SIZE];
    auto he = f->he;
    auto v0 = he->v;
    auto v1 = he->next->v;
    auto v2 = he->next->next->v;
    auto d1 = v1->position - v0->position;
    auto d2 = v2->position - v0->position;
    auto d = P - v0->position;
    auto pv12 = crossprod(d1, d2);
    double vol = dot(pv12, d);
    minvol = std::min(minvol, fabs(vol));
    if(fabs(vol) < eps) {
      double surf = pv12.norm();
      auto pv1 = crossprod(d, d1);
      auto pv2 = crossprod(d, d2);
      double surf1 = pv1.norm();
      double surf2 = pv2.norm();
      _u = surf2 / surf;
      _v = surf1 / surf;
      if(_u >= -eps && _v >= -eps && 1 - _u - _v >= -eps) {
        double x = (1 - _u - _v) * v0->position.x() + _u * v1->position.x() +
                   _v * v2->position.x();
        double y = (1 - _u - _v) * v0->position.y() + _u * v1->position.y() +
                   _v * v2->position.y();
        double z = (1 - _u - _v) * v0->position.z() + _u * v1->position.z() +
                   _v * v2->position.z();
        double dd =
          sqrt((x - v->x()) * (x - v->x()) + (y - v->y()) * (y - v->y()) +
               (z - v->z()) * (z - v->z()));

        if(dd < eps) {
          vof.he = he;
          vof.u = _u;
          vof.v = _v;
          if(he) return vof;
        }
      }
    }
  }
  return vof;
}

static geodesic::SurfacePoint getSP(const PolyMesh::VertexOnSurface &_start,
                                    geodesic::face_pointer fp)
{
  SVector3 p_start = _start.point();
  if(_start.dim == 0) {
    for(int i = 0; i < 3; i++) {
      geodesic::vertex_pointer v0 = fp->adjacent_vertices()[i];
      double dx = sqrt((v0->x() - p_start.x()) * (v0->x() - p_start.x()) +
                       (v0->y() - p_start.y()) * (v0->y() - p_start.y()) +
                       (v0->z() - p_start.z()) * (v0->z() - p_start.z()));
      if(dx < 1.e-10) {
        geodesic::SurfacePoint sp(v0, p_start.x(), p_start.y(), p_start.z(),
                                  geodesic::VERTEX);
        return sp;
      }
    }
  }
  if(_start.dim == 1) {
    for(int i = 0; i < 3; i++) {
      geodesic::edge_pointer edge = fp->adjacent_edges()[i];
      geodesic::vertex_pointer v0 = edge->adjacent_vertices()[0];
      geodesic::vertex_pointer v1 = edge->adjacent_vertices()[1];
      double dx = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) +
                       (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                       (v0->z() - v1->z()) * (v0->z() - v1->z()));
      double dx1 = sqrt((v0->x() - p_start.x()) * (v0->x() - p_start.x()) +
                        (v0->y() - p_start.y()) * (v0->y() - p_start.y()) +
                        (v0->z() - p_start.z()) * (v0->z() - p_start.z()));
      double dx2 = sqrt((v1->x() - p_start.x()) * (v1->x() - p_start.x()) +
                        (v1->y() - p_start.y()) * (v1->y() - p_start.y()) +
                        (v1->z() - p_start.z()) * (v1->z() - p_start.z()));
      if(fabs(dx - dx1 - dx2) < 1.e-10 * dx) {
        geodesic::SurfacePoint sp(edge, p_start.x(), p_start.y(), p_start.z(),
                                  geodesic::EDGE);
        return sp;
      }
    }
  }
  geodesic::SurfacePoint sp(fp, p_start.x(), p_start.y(), p_start.z(),
                            geodesic::FACE);
  return sp;
}

static void filterPath(std::vector<geodesic::SurfacePoint> &path, double eps)
{
  for(size_t i = 1; i+1 < path.size(); i++) {
    if (path[i].type() == geodesic::VERTEX) continue;
    for (auto v: path[i].base_element()->adjacent_vertices()) {
      SVector3 dx(v->x() - path[i].x(), v->y() - path[i].y(), v->z() - path[i].z());
      if(dx.norm() < eps) {
        path[i] = geodesic::SurfacePoint(v, v->x(), v->y(), v->z(), geodesic::VERTEX);
        break;
      }
    }
  }
  std::vector<geodesic::SurfacePoint> filtered_path;
  filtered_path.push_back(path[0]);
  for(size_t i = 1; i < path.size(); i++) {
    if (path[i].base_element() == filtered_path[filtered_path.size() - 1].base_element())
      continue;
    filtered_path.push_back(path[i]);
  }
  filtered_path[filtered_path.size() - 1] = path[path.size() - 1];

  path = filtered_path;
}

bool compareVertexOnEdge(const VertexOnEdge &v0, const VertexOnEdge &v1)
{
  return v0.t < v1.t;
}

static void polyMeshToGeodesicMesh(PolyMesh *pm, geodesic::Mesh &mesh,
                                   std::map<PolyMesh::Face *, int> &f2n)
{
  std::vector<double> _points;
  std::vector<unsigned> _faces;
  int num = 0;
  for(auto v : pm->vertices) {
    _points.push_back(v->position.x());
    _points.push_back(v->position.y());
    _points.push_back(v->position.z());
    v->data = num++;
  }
  int nnn = 0;
  for(auto f : pm->faces) {
    _faces.push_back(f->he->v->data);
    _faces.push_back(f->he->next->v->data);
    _faces.push_back(f->he->next->next->v->data);
    f2n[f] = nnn++;
  }
  // printf("coucou1 %lu %lu\n", _faces.size() / 3, _points.size() / 3);
  mesh.initialize_mesh_data(_points, _faces);
  // printf("coucou2\n");
}

geodesic::SurfacePoint
MVertexToGeodesicSurfacePoint(MVertex *v, PolyMesh *pm, geodesic::Mesh &mesh,
                              std::map<PolyMesh::Face *, int> &f2n, int pos)
{
  //  printf("----> > %lu %d %lu %g %g
  //  %g\n",f2n.size(),pos,pm->faces.size(),v->x(),v->y(),v->z());

  PolyMesh::VertexOnSurface vof = findVertexOnSurface(pm, v, pos, true);
  if(v->onWhat()) onBoundary(vof, 1.e-10, v->onWhat()->dim());
  //  vof.dim = v->onWhat()->dim();
  //  printf("UV = %12.5E %12.5E -- %12.5E %12.5E %12.5E -- %12.5E %12.5E %12.5E
  //  -- \n",vof.u,vof.v,
  //	 vof.he->v->position.x(),vof.he->v->position.y(),vof.he->v->position.z(),
  //	 vof.he->next->v->position.x(),vof.he->next->v->position.y(),vof.he->next->v->position.z());
  geodesic::SurfacePoint spe = getSP(vof, &mesh.faces()[f2n[vof.he->f]]);
  //  printf("----> > %lu\n",f2n.size());
  return spe;
}

// FOR ARTHUR !!! ------------------------------------------------------------

bool compareVertexOnHalfEdge(const PolyMesh::Vertex *v0,
                             const PolyMesh::Vertex *v1)
{
  SVector3 d0 = v0->position;
  SVector3 d1 = v1->position;
  return d0.norm() < d1.norm();
};

// -- M A I N    C L A S S

  int highOrderPolyMesh::getTag(const std::pair<int, int> &e2)
  {
    std::pair<int, int> e = std::make_pair(std::min(e2.first, e2.second),
                                           std::max(e2.first, e2.second));
    auto it = tags.find(e);
    if(it == tags.end()) { tags[e] = maxTag++; }
    return tags[e];
  }

  SVector3 highOrderPolyMesh::normal(geodesic::base_pointer b)
  {
    SVector3 n(0, 0, 0);
    if (b->type() == geodesic::VERTEX || b->type() == geodesic::EDGE) {
      for (int i = 0; i < b->adjacent_faces().size(); ++i)
        n += normal(b->adjacent_faces()[i]);
    }
    else if (b->type() == geodesic::FACE) {
      SVector3 p0 = trueCoord[b->adjacent_vertices()[0]->id()];
      SVector3 p1 = trueCoord[b->adjacent_vertices()[1]->id()];
      SVector3 p2 = trueCoord[b->adjacent_vertices()[2]->id()];
      SVector3 t0(p2 - p0);
      SVector3 t1(p1 - p0);
      n = crossprod(t1, t0);
    }
    else
      Msg::Error("Unknown type");
    if (norm(n) < 1e-12) Msg::Error("norm(n) is null");
    n.normalize();
    return n;
  }

  SVector3 highOrderPolyMesh::normal(int p)
  {
    return normal(points[p].base_element());
  }

  double highOrderPolyMesh::computeAngle(int p0, int p1, int p2)
  {
    std::vector<geodesic::SurfacePoint> p10, p12;
    getGeodesicPath(p1, p0, p10);
    getGeodesicPath(p1, p2, p12);
    SVector3 v10(getTrueCoords(p10[1]), getTrueCoords(p10[0]));
    SVector3 v12(getTrueCoords(p12[1]), getTrueCoords(p12[0]));
    return angle(v10, v12);
  }

  double highOrderPolyMesh::computeAngle(SVector3 v01, SVector3 v02, SVector3 n)
  {
    double cos = dot(v01, v02);
    SVector3 cp = crossprod(v01, v02);
    double sin = norm(cp);
    if (dot(cp, n) < 0) sin = -sin;
    return atan2(sin, cos);
  }

  double highOrderPolyMesh::computeAngle(std::vector<geodesic::SurfacePoint> & p01,
                                         std::vector<geodesic::SurfacePoint> & p20, SVector3 n)
  {
    SVector3 v01(getTrueCoords(p01[0]), getTrueCoords(p01[1]));
    SVector3 v02(getTrueCoords(p20[p20.size()-1]), getTrueCoords(p20[p20.size()-2]));
    return computeAngle(v01, v02, n);
  }

  /*
    p0            p2
     \           /
       \ <---- /
         \   /
           p1
  */
  double highOrderPolyMesh::computeAngle(int p0, int p1, int p2, SVector3 n,
                                         int boundary10, int boundary12)
  {
    std::vector<geodesic::SurfacePoint> p10, p12;
    getPath({p1, p0}, boundary10, p10);
    getPath({p1, p2}, boundary12, p12);
    SVector3 v10(getTrueCoords(p10[1]), getTrueCoords(p10[0]));
    SVector3 v12(getTrueCoords(p12[1]), getTrueCoords(p12[0]));

    return computeAngle(v10, v12, n);
  }

  /*
               p2
             /    \
    path2  /   a2   \  path1
         /            \
       /  a0        a1  \
     p0 ---------------- p1
              path0
  */
  void highOrderPolyMesh::computeAngles(int ps[3], double angles[3], int boundaryOrients[3])
  {
    std::vector<geodesic::SurfacePoint> paths[3];
    for (int j = 0; j < 3; ++j)
      getPath({ps[j], ps[(j+1)%3]}, boundaryOrients[j], paths[j]);
    for (int j = 0; j < 3; ++j) {
      std::vector<geodesic::SurfacePoint> & path0 = paths[j];
      std::vector<geodesic::SurfacePoint> & path1 = paths[(j + 2) % 3];
      SVector3 v0(getTrueCoords(path0[1]), getTrueCoords(path0[0]));
      SVector3 v1(getTrueCoords(path1[path1.size()-2]), getTrueCoords(path1[path1.size()-1]));
      angles[j] = computeAngle(v0, v1, normal(ps[j]));
    }
  }


  bool highOrderPolyMesh::edgeValid(int p0, int p1, int p2, int p3)
  {
    /*
             2
        / \
       /   \
      /     \
         0--->---1
      \     /
       \   /
        \ /
             3
     */

    double a1 = computeAngleTrue(p2, p0, p1);
    double a2 = computeAngleTrue(p2, p0, p3);
    if(a1 < 0) a1 += 2 * M_PI;
    if(a2 < 0) a2 += 2 * M_PI;
    //double a3 = computeAngleTrue(p0, p1, p2);
    //double a4 = computeAngleTrue(p3, p1, p2);
    //    printf("%12.5E %12.5E -- %12.5E %12.5E
    //    \n",a1*180/M_PI,a2*180/M_PI,a1,a2-a1); if (a3 < 0) a3 += 2*M_PI; if
    //    (a4 < 0) a4 += 2*M_PI;

    if(a1 < a2) return true; // edge valid
    return false;
  }

bool highOrderPolyMesh::doWeSwap(int p0, int p1, int p2, int p3, int onlyMisoriented)
{
  double ori012 = computeBoxProduct(p0, p1, p2);
  double ori103 = computeBoxProduct(p1, p0, p3);

  const double eps = 1e-12; // FIXME

  if(ori012 > eps && ori103 > eps && onlyMisoriented) return false;

  double ori032 = computeBoxProduct(p0, p3, p2);
  double ori231 = computeBoxProduct(p2, p3, p1);
  if(ori012 < -eps || ori103 < -eps) {
    if(ori032 > eps && ori231 > eps) {
      printf("FORCING SWAP (creating 2 positive elements) %d %d %d %d : %g "
              "%g --> %g %g\n",
              p0, p1, p2, p3, ori012, ori103, ori032, ori231);
      return true;
    }
  }
  if(ori032 < -eps || ori231 < -eps) return false;
  if(onlyMisoriented) return false;

  double a1 = computeAngle(p1, p0, p3); // OK
  double a2 = computeAngle(p2, p0, p1); // OK
  double a3 = computeAngle(p3, p2, p0); // OK
  double a4 = computeAngle(p1, p2, p3); // OK
  double a5 = computeAngle(p0, p1, p2); // OK
  double a6 = computeAngle(p3, p1, p0); // OK
  double a7 = computeAngle(p2, p3, p1); // OK
  double a8 = computeAngle(p0, p3, p2); // OK

  std::vector<double> A_before = {a1, a3 + a4, a5, a6, a7 + a8, a2};
  std::vector<double> A_after = {a1 + a2, a3, a8, a4, a5 + a6, a7};

  std::sort(A_before.begin(), A_before.end());
  std::sort(A_after.begin(), A_after.end());

  return A_after[0] > A_before[0];
}

void highOrderPolyMesh::addVertexOnSurface(PolyMesh::Face *f, int v)
{
  std::map<PolyMesh::Face *, std::vector<int>>::iterator it = fvs.find(f);
  if(it != fvs.end())
    it->second.push_back(v);
  else {
    std::vector<int> cut = {v};
    fvs[f] = cut;
  }
}

void highOrderPolyMesh::addVertexOnEdge(PolyMesh::HalfEdge *e, int v)
{
  std::map<PolyMesh::HalfEdge *, std::vector<int>>::iterator it = evs.find(e);
  if(it != evs.end()) {
    for (auto w: it->second) {
      if (norm(pm->vertices[v]->position - pm->vertices[w]->position) < 1e-6) {
        std::cout << pm->vertices[w]->position.x() << " " << pm->vertices[w]->position.y() << " " << pm->vertices[w]->position.z() << std::endl;
        std::cout << pm->vertices[v]->position.x() << " " << pm->vertices[v]->position.y() << " " << pm->vertices[v]->position.z() << std::endl;
        Msg::Error("Vertex already exists in evs");
      }
    }
    it->second.push_back(v);
  }
  else {
    std::vector<int> cut = {v};
    evs[e] = cut;
  }
}

void highOrderPolyMesh::addPolyMeshVertexTag(PolyMesh::Vertex *v, int tag)
{
  std::map<PolyMesh::Vertex *, std::vector<int>>::iterator it =
    pvtags.find(v);
  if(it != pvtags.end())
    it->second.push_back(tag);
  else {
    std::vector<int> tmp = {tag};
    pvtags[v] = tmp;
  }
}

void highOrderPolyMesh::classifyGeodesic(std::pair<int, int> pair,
                      const std::vector<geodesic::SurfacePoint> &p)
{
  int tag = getTag(pair);
  //    printf("----> classifying a geodesic %d %d %d\n",pair.first,
  //    pair.second, tag);
  for(size_t i = 1; i < p.size() - 1; i++) {
    geodesic::SurfacePoint _s = p[i];
    if(_s.type() == geodesic::VERTEX) { // saddle vertex
      // no new point needed
      geodesic::Vertex *pv =
        static_cast<geodesic::Vertex *>(_s.base_element());
      //	printf("point %lu geodesic vertex %d - %g %g
      //%g\n",i,pv->id(),_s.x(),_s.y(),_s.z());
      addPolyMeshVertexTag(pm->vertices[pv->id()], tag);
      auto it = _saddle.find(pv->id());
      if(it != _saddle.end()) {
        printf("geodesics %d and %d intersect at saddle point %d\n", tag,
                it->second, pv->id());
      }
      _saddle[pv->id()] = tag;
    }
    else if(_s.type() == geodesic::EDGE) { // usual vertex on an edge
      // point will be created later by splitting
      geodesic::Edge *pe = static_cast<geodesic::Edge *>(_s.base_element());
      geodesic::vertex_pointer v0 = pe->v0();
      geodesic::vertex_pointer v1 = pe->v1();
      PolyMesh::HalfEdge *he =
        pm->getEdge(pm->vertices[std::min(v0->id(), v1->id())],
                    pm->vertices[std::max(v0->id(), v1->id())]);
      if(!he)
        he = pm->getEdge(pm->vertices[std::max(v0->id(), v1->id())],
                          pm->vertices[std::min(v0->id(), v1->id())]);
      if(!he) Msg::Error("%s %d -- FAILURE", __FILE__, __LINE__);
      /*	if (pm->vertices.size() == 664 || pm->vertices.size() == 655 ||
        pm->vertices.size() == 644 || pm->vertices.size() == 634){
        geodesic::SurfacePoint _ss = p[0];
        printf("we are on geodesic %d %d and point %lu is on position %lu (%g
        %g %g) vs (%g %g %g) -- %d vs %d size = %lu\n",
            pair.first,pair.second,pm->vertices.size(),i,_s.x(),_s.y(),_s.z(),_ss.x(),_ss.y(),_ss.z(),_s.type(),_ss.type(),p.size());
            }*/
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      addVertexOnEdge(he, pm->vertices.size());
      pm->vertices.push_back(newv);
      addPolyMeshVertexTag(newv, tag);
    }
    else if(_s.type() ==
            geodesic::FACE) { // point on a face (start of geodesic)
      geodesic::Face *pf = static_cast<geodesic::Face *>(_s.base_element());
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      //	printf("point %lu geodesic face %d \n",i,pf->id());
      addVertexOnSurface(pm->faces[pf->id()], pm->vertices.size());
      pm->vertices.push_back(newv);
      addPolyMeshVertexTag(newv, tag);
    }
  }
}

void highOrderPolyMesh::classifyGeodesicVertices(std::vector<PolyMesh::Vertex *> & pointVertices)
{
  // std::set<int> pts;
  // for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
  //   auto ite = edges.find(it->first);
  //   if(ite != edges.end() && ite->second.size()) {
  //     pts.insert(it->first.first);
  //     pts.insert(it->first.second);
  //   }
  // }
  // for (size_t i = 0; i < triangles.size(); i++) {
  //   pts.insert(triangles[i]);
  // }

  // std::map<int, PolyMesh::Vertex *> i2pts;
  pointVertices.resize(points.size());
  for(size_t i = 0; i < points.size(); ++i) {
    geodesic::SurfacePoint _s = points[i];
    //      printf("end point %lu geodesic vertex - %g %g %g - type
    //      %d\n",i,_s.x(),_s.y(),_s.z(),_s.type());
    if(_s.type() == geodesic::VERTEX) { // saddle vertex
      geodesic::Vertex *pv =
        static_cast<geodesic::Vertex *>(_s.base_element());
      sp2pv[&(points[i])] = pm->vertices[pv->id()];
      pointVertices[i] = pm->vertices[pv->id()];
    }
    else if(_s.type() == geodesic::FACE) {
      geodesic::Face *pf = static_cast<geodesic::Face *>(_s.base_element());
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      addVertexOnSurface(pm->faces[pf->id()], pm->vertices.size());
      pm->vertices.push_back(newv);
      sp2pv[&(points[i])] = newv;
      pointVertices[i] = newv;
    }
    else if(_s.type() == geodesic::EDGE) {
      geodesic::Edge *pe = static_cast<geodesic::Edge *>(_s.base_element());
      geodesic::vertex_pointer v0 = pe->v0();
      geodesic::vertex_pointer v1 = pe->v1();
      PolyMesh::HalfEdge *he =
        pm->getEdge(pm->vertices[std::min(v0->id(), v1->id())],
                    pm->vertices[std::max(v0->id(), v1->id())]);
      if(!he)
        he = pm->getEdge(pm->vertices[std::max(v0->id(), v1->id())],
                          pm->vertices[std::min(v0->id(), v1->id())]);
      if(!he) Msg::Error("%s %d -- FAILURE", __FILE__, __LINE__);
      if(pm->vertices.size() == 664 || pm->vertices.size() == 655 ||
          pm->vertices.size() == 644 || pm->vertices.size() == 634) {
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  argh : %lu --- %g %g %g --> "
                "%g %g %g\n",
                i, he->v->position.x(), he->v->position.y(),
                he->v->position.z(), he->next->v->position.x(),
                he->next->v->position.y(), he->next->v->position.z());
      }
      PolyMesh::Vertex *newv =
        new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
      addVertexOnEdge(he, pm->vertices.size());
      pm->vertices.push_back(newv);
      sp2pv[&(points[i])] = newv;
      pointVertices[i] = newv;
    }
  }

  // for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
  //   auto ite = edges.find(it->first);
  //   if(ite != edges.end() && ite->second.size()) {
  //     PolyMesh::Vertex *v0 = i2pts[it->first.first];
  //     PolyMesh::Vertex *v1 = i2pts[it->first.second];
  //     int tag = getTag(it->first);
  //     addPolyMeshVertexTag(v0, tag);
  //     addPolyMeshVertexTag(v1, tag);
  //   }
  // }
  for (size_t i = 0; i < triangles.size()/3; ++i) {
    PolyMesh::Vertex *vs[3] = {pointVertices[triangles[3*i]], 
                                pointVertices[triangles[3*i+1]],
                                pointVertices[triangles[3*i+2]]};
    for (int j = 0; j < 3; ++j) {
      auto i0 = triangles[3*i+j];
      auto i1 = triangles[3*i+(j+1)%3];
      int tag = getTag({i0, i1});
      addPolyMeshVertexTag(vs[j], tag);
      addPolyMeshVertexTag(vs[(j+1)%3], tag);
    }
  }

  //    for (auto it : pvtags){
  //      printf("vertex %d -- tags",it.first->data);
  //      for (auto i : it.second)printf ("%d ",i);
  //      printf("\n");
  //    }

  // for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
  //   auto ite = edges.find(it->first);
  //   if(ite != edges.end() && ite->second.size()) {
  //     classifyGeodesic(it->first, it->second);
  //   }
  // }
  std::map<std::pair<int, int>, bool> done;
  for (size_t i = 0; i < triangles.size()/3; ++i) {
    for (int j = 0; j < 3; ++j) {
      auto i0 = triangles[3*i+j];
      auto i1 = triangles[3*i+(j+1)%3];
      // if (geodesics.find({i0, i1}) == geodesics.end()) {
      //   std::vector<geodesic::SurfacePoint> p;
      //   getGeodesicPath(i0, i1, p);
      //   geodesics[{i0, i1}] = p;
      // }
      if (done.find({std::min(i0,i1), std::max(i0,i1)}) == done.end()) {
        classifyGeodesic({i0, i1}, geodesics[{i0, i1}]);
        done[{std::min(i0,i1), std::max(i0,i1)}] = true;
      }
    }
  }

}

//public
void highOrderPolyMesh::printGeodesics(const char *fn)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View \"\"{\n");
  int count = 1;
  for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
    auto ite = edges.find(it->first);
    if(ite != edges.end() && ite->second.size()) {
      const size_t last = it->second.size() - 1;
      fprintf(f, "SP(%g,%g,%g){%d};\n", it->second[0].x(), it->second[0].y(),
              it->second[0].z(), count);
      fprintf(f, "SP(%g,%g,%g){%d};\n", it->second[last].x(),
              it->second[last].y(), it->second[last].z(), count);
      for(size_t i = 1; i < it->second.size(); ++i) {
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%ld,%ld};\n", it->second[i - 1].x(),
                it->second[i - 1].y(), it->second[i - 1].z(),
                it->second[i].x(), it->second[i].y(), it->second[i].z(),
                ite->second[0], ite->second[0]);
      }
      if(ite->second.size() == 2) {
        for(size_t i = 1; i < it->second.size(); ++i) {
          fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%ld,%ld};\n", it->second[i - 1].x(),
                  it->second[i - 1].y(), it->second[i - 1].z(),
                  it->second[i].x(), it->second[i].y(), it->second[i].z(),
                  ite->second[1], ite->second[1]);
        }
      }
      count++;
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

void highOrderPolyMesh::enforceBoundary() {
  for (size_t i = 0; i < triangles.size()/3; ++i) {
    for (int j = 0; j < 3; ++j) {
      auto i0 = triangles[3*i+j];
      auto i1 = triangles[3*i+(j+1)%3];
      std::pair<int,int> edge = {std::min(i0,i1), std::max(i0,i1)};
      if (edges[edge].size() != 1) continue;

      std::vector<geodesic::SurfacePoint> path;
      getBoundaryPath(i0, i1, path);
      if (path.size() < 2) Msg::Error("Unable to get boundary path");
      geodesics[edge] = path;
      std::swap(edge.first, edge.second);
      std::reverse(path.begin(), path.end());
      geodesics[edge] = path;
    }
  }
}

  // Parallelizing edge swapping should be done
  // The only thiong to parallelize is to

int highOrderPolyMesh::swapEdges(int niter, int onlyMisoriented)
{
  int countTot = 0;
  int iter = 0;

  while(1) {
    int count = 0;
    std::vector<std::pair<int, int>> eds;
    std::set<std::pair<int, int>> eds_o;
    int nbInValid = 0;
    for(auto it : edges) {
      std::pair<int, int> opposite = std::make_pair(-1, -1);
      swapEdge(it.first, onlyMisoriented, &opposite);
      if(opposite.second >= 0) {
        std::pair<int, int> opp =
          std::make_pair(std::min(opposite.first, opposite.second),
                          std::max(opposite.first, opposite.second));
        bool v = edgeValid(it.first.first, it.first.second, opposite.first,
                            opposite.second);
        if(!onlyMisoriented || !v) {
          eds_o.insert(opp);
          eds.push_back(it.first);
        }
        if(!v) nbInValid++;
      }
    }

    // std::sort(eds_o.begin(), eds_o.end());
    Msg::Info("%d invalid edges among %lu (%lu geodesics to be computed)",
              nbInValid, edges.size(), eds_o.size());

    createGeodesicsInParallel(eds_o);

    for(auto it : eds)
      count += (swapEdge(it, onlyMisoriented, nullptr) == 0 ? 1 : 0);
    if(count == 0) break;
    if(++iter >= niter) break;
    countTot += count;
  }
  Msg::Info("Swapping Edges -- %d iterations needed", iter);
  return countTot;
}


int highOrderPolyMesh::splitEdges(double L)
{
  int count = 0;
  std::vector<std::pair<int, int>> eds;
  for(auto it : edges) eds.push_back(it.first);
  for(auto it : eds) count += (splitEdge(it, L) == 0 ? 1 : 0);
  return count;
}

double highOrderPolyMesh::computeAngleTrue(int p0, int p1, int p2)
{
  std::vector<geodesic::SurfacePoint> p10, p12;
  getGeodesicPath(p1, p0, p10);
  getGeodesicPath(p1, p2, p12);
  SVector3 v10(p10[1].x() - p10[0].x(), p10[1].y() - p10[0].y(),
                p10[1].z() - p10[0].z());
  SVector3 v12(p12[1].x() - p12[0].x(), p12[1].y() - p12[0].y(),
                p12[1].z() - p12[0].z());
  v10.normalize();
  v12.normalize();
  SVector3 n = normal(p1);
  double s = dot(n, crossprod(v12, v10));
  double c = dot(v12, v10);
  return atan2(s, c);
}

double highOrderPolyMesh::computeBoxProduct(int p0, int p1, int p2)
{
  std::vector<geodesic::SurfacePoint> p10, p12;
  getGeodesicPath(p1, p0, p10);
  getGeodesicPath(p1, p2, p12);
  SVector3 v10(p10[1].x() - p10[0].x(), p10[1].y() - p10[0].y(),
                p10[1].z() - p10[0].z());
  SVector3 v12(p12[1].x() - p12[0].x(), p12[1].y() - p12[0].y(),
                p12[1].z() - p12[0].z());
  v10.normalize();
  v12.normalize();
  SVector3 n = normal(p1);
  return dot(n, crossprod(v12, v10));
}


// CONSTRUCTORS
highOrderPolyMesh::highOrderPolyMesh(PolyMesh *polyMesh, std::vector<size_t> & tris) : maxTag(1)
{
  pm = polyMesh;
  polyMeshToGeodesicMesh(pm, geoMesh, f2n);
  algorithms = std::vector<geodesic::GeodesicAlgorithmExact>(getNumThreads(), geodesic::GeodesicAlgorithmExact(&geoMesh));

  auto vertices = pm->vertices;
  std::map<int, int> v2n;
  for (auto i: tris) {
    auto v = vertices[i];
    if (!v2n.count(i)) {
      geodesic::SurfacePoint gv = geodesic::SurfacePoint(&geoMesh.vertices()[v->data],
                                                          v->position.x(), v->position.y(),
                                                          v->position.z(), geodesic::VERTEX);
      v2n[i] = points.size();
      points.push_back(gv);
    }
  }
  for (size_t i = 0; i < tris.size()/3; ++i) {
    PolyMesh::Vertex *vs[3];
    for (int j = 0; j < 3; ++j)
      vs[j] = vertices[tris[3*i+j]];
    for(size_t i = 0; i < 3; i++) {
      int i0 = v2n[vs[i]->data];
      int i1 = v2n[vs[(i + 1) % 3]->data];
      std::pair<int, int> p =
        std::make_pair(std::min(i0, i1), std::max(i0, i1));
      std::map<std::pair<int, int>, std::vector<size_t>>::iterator it =
        edges.find(p);
      if(it == edges.end()) {
        std::vector<size_t> tmp = {triangles.size() / 3};
        edges[p] = tmp;
      }
      else
        it->second.push_back(triangles.size() / 3);
    }
    triangles.push_back(v2n[vs[0]->data]);
    triangles.push_back(v2n[vs[1]->data]);
    triangles.push_back(v2n[vs[2]->data]);
  }

}

highOrderPolyMesh::highOrderPolyMesh(PolyMesh *polyMesh) : maxTag(1)
{
  pm = polyMesh;
  polyMeshToGeodesicMesh(pm, geoMesh, f2n);
  algorithms = std::vector<geodesic::GeodesicAlgorithmExact>(getNumThreads(), geodesic::GeodesicAlgorithmExact(&geoMesh));
}

// END CONSTRUCTORS



static int getNumThreads()
{
  int nthreads = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    nthreads = CTX::instance()->mesh.maxNumThreads3D;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  return nthreads;
}

// static void getRestrictedMesh(PolyMesh *pm,
//                               std::vector<geodesic::SurfacePoint> &pts_start,
//                               std::vector<geodesic::SurfacePoint> &pts_end,
//                               geodesic::Mesh &restrictedGeoMesh,
//                               std::unordered_map<int, int> &index2Vertex,
//                               std::unordered_map<int, int> &index2Face)
// {
//   std::unordered_set<PolyMesh::Vertex *> seeds;
//   for (size_t i = 0; i < pts_start.size(); ++i) {
//     geodesic::SurfacePoint & p = pts_start[i];
//     if (p.type() == geodesic::VERTEX)
//       seeds.insert(pm->vertices[static_cast<geodesic::Vertex *>(p.base_element())->id()]);
//     else if (p.type() == geodesic::EDGE) {
//       seeds.insert(pm->vertices[static_cast<geodesic::Edge *>(p.base_element())->v0()->id()]);
//       seeds.insert(pm->vertices[static_cast<geodesic::Edge *>(p.base_element())->v1()->id()]);
//     }
//     else if (p.type() == geodesic::FACE) {
//       seeds.insert(pm->vertices[static_cast<geodesic::Face *>(p.base_element())->adjacent_vertices()[0]->id()]);
//       seeds.insert(pm->vertices[static_cast<geodesic::Face *>(p.base_element())->adjacent_vertices()[1]->id()]);
//       seeds.insert(pm->vertices[static_cast<geodesic::Face *>(p.base_element())->adjacent_vertices()[2]->id()]);
//     }
//   }
//   std::unordered_set<PolyMesh::Vertex *> destinations;
//   for (size_t i = 0; i < pts_end.size(); ++i) {
//     geodesic::SurfacePoint & p = pts_end[i];
//     if (p.type() == geodesic::VERTEX)
//       destinations.insert(pm->vertices[static_cast<geodesic::Vertex *>(p.base_element())->id()]);
//     else if (p.type() == geodesic::EDGE) {
//       destinations.insert(pm->vertices[static_cast<geodesic::Edge *>(p.base_element())->v0()->id()]);
//       destinations.insert(pm->vertices[static_cast<geodesic::Edge *>(p.base_element())->v1()->id()]);
//     }
//     else if (p.type() == geodesic::FACE) {
//       destinations.insert(pm->vertices[static_cast<geodesic::Face *>(p.base_element())->adjacent_vertices()[0]->id()]);
//       destinations.insert(pm->vertices[static_cast<geodesic::Face *>(p.base_element())->adjacent_vertices()[1]->id()]);
//       destinations.insert(pm->vertices[static_cast<geodesic::Face *>(p.base_element())->adjacent_vertices()[2]->id()]);
//     }
//   };
//   std::unordered_map<PolyMesh::Vertex *, double> d;
//   pm->fastMarching(seeds, d, destinations);
//   // std::map<PolyMesh::Vertex *, double> d_;
//   // for (auto it : d) d_[it.first] = it.second;
//   // print__("fastMarching.pos", pm, d_);
//   // Msg::Error("Force quit");

//   std::vector<double> points;
//   std::unordered_map<int, int> vertex2Index;
//   std::vector<size_t> faces;
//   std::unordered_map<int, int> face2Index;

//   // for (size_t i = 0; i < pm->faces.size(); ++i) {
//   //   PolyMesh::HalfEdge *he = pm->faces[i]->he;
//   //   if (d[he->v] >= 1.e22 && d[he->next->v] >= 1.e22 && d[he->next->next->v] >= 1.e22)
//   //     continue;

//   //   index2Face[faces.size() / 3] = i;
//   //   face2Index[i] = faces.size() / 3;
//   //   for (int j = 0; j < 3; ++j) {
//   //     if (vertex2Index.find(he->v->data) == vertex2Index.end()) {
//   //       index2Vertex[points.size() / 3] = he->v->data;
//   //       vertex2Index[he->v->data] = points.size() / 3;
//   //       points.push_back(he->v->position.x());
//   //       points.push_back(he->v->position.y());
//   //       points.push_back(he->v->position.z());
//   //     }
//   //     faces.push_back(vertex2Index[he->v->data]);
//   //     he = he->next;
//   //   }
//   // }

//   points.reserve(d.size() * 3);
//   faces.reserve(d.size() * 3 * 2);
//   int vIndex = 0, fIndex = 0;
//   for (const auto& [v, _]: d) {
//     PolyMesh::HalfEdge *he = v->he;
//     do {
//       int face = he->f->data;
//       if (face2Index.find(face) == face2Index.end()) {
//         index2Face[fIndex] = face;
//         face2Index[face] = fIndex;
//         fIndex++;
//         for (int j = 0; j < 3; ++j) {
//           int vertex = he->v->data;
//           if (vertex2Index.find(vertex) == vertex2Index.end()) {
//             index2Vertex[vIndex] = vertex;
//             vertex2Index[vertex] = vIndex;
//             vIndex++;
//             points.push_back(he->v->position.x());
//             points.push_back(he->v->position.y());
//             points.push_back(he->v->position.z());
//           }
//           faces.push_back(vertex2Index[vertex]);
//           he = he->next;
//         }
//       }

//       if (he->opposite == nullptr) {
//         he = he->prev;
//         while (he->opposite != nullptr) he = he->opposite->prev;
//         he = he->next;
//       }
//       else
//         he = he->opposite->next;
//     } while (he != v->he);
//   }

//   restrictedGeoMesh.initialize_mesh_data(points, faces);
//   // PolyMesh *pm_new = createPolyMesh(points, faces, {}, {});
//   // // std::cout << "points.size() = " << pm_new->vertices.size() << " faces.size() = " << pm_new->faces.size() << std::endl;
//   // std::map<PolyMesh::Vertex *, double> nothing;
//   // print__("restrictedMesh.pos", pm_new, nothing);



//   for (int i = 0; i < 2; ++i) {
//     std::vector<geodesic::SurfacePoint> pts = (i == 0) ? pts_start : pts_end;

//     std::vector<geodesic::SurfacePoint> newPts(pts.size());
//     for (size_t j = 0; j < pts.size(); ++j) {
//         geodesic::SurfacePoint& p = pts[j];

//         // Ensure base_element pointer is valid before accessing it
//         if (p.base_element() == nullptr) {
//             Msg::Error("Invalid base element in SurfacePoint at index %zu", j);
//             continue;  // Skip to the next point to avoid crashes
//         }

//         if (p.type() == geodesic::VERTEX) {
//             int index = ((geodesic::Vertex*)p.base_element())->id();
//             if (index < 0 || vertex2Index.find(index) == vertex2Index.end()) {
//                 Msg::Error("Vertex index out of bounds: %d", index);
//                 continue;
//             }

//             newPts[j] = geodesic::SurfacePoint(
//                 &restrictedGeoMesh.vertices()[vertex2Index[index]], p.x(), p.y(), p.z(), geodesic::VERTEX
//             );
//         } 
//         else if (p.type() == geodesic::EDGE) {
//             int index0 = ((geodesic::Edge*)p.base_element())->v0()->id();
//             int index1 = ((geodesic::Edge*)p.base_element())->v1()->id();
//             if (index0 < 0 || vertex2Index.find(index0) == vertex2Index.end() ||
//                 index1 < 0 || vertex2Index.find(index1) == vertex2Index.end()) {
//                 Msg::Error("Edge vertex indices out of bounds: %d, %d", index0, index1);
//                 continue;
//             }

//             if (vertex2Index[index0] == vertex2Index[index1]) {
//                 Msg::Error("Vertex not found: %d %d to %d", index0, index1, vertex2Index[index0], vertex2Index[index1]);
//                 continue;
//             }

//             geodesic::Vertex* v0 = &restrictedGeoMesh.vertices()[vertex2Index[index0]];
//             geodesic::Vertex* v1 = &restrictedGeoMesh.vertices()[vertex2Index[index1]];
//             geodesic::Edge* e = nullptr;

//             for (auto* adjEdge : v0->adjacent_edges()) {
//                 if ((adjEdge->v0() == v1 && adjEdge->v1() == v0) ||
//                     (adjEdge->v0() == v0 && adjEdge->v1() == v1)) {
//                     e = adjEdge;
//                     break;
//                 }
//             }

//             if (!e || ((e->v0() != v0 || e->v1() != v1) && (e->v0() != v1 || e->v1() != v0))) {
//                 Msg::Error("Edge not found between vertices %d and %d", index0, index1);
//                 continue;
//             }

//             newPts[j] = geodesic::SurfacePoint(e, p.x(), p.y(), p.z(), geodesic::EDGE);
//         } 
//         else if (p.type() == geodesic::FACE) {
//             int index = ((geodesic::Face*)p.base_element())->id();
//             if (index < 0 || face2Index.find(index) == face2Index.end()) {
//                 Msg::Error("Face index out of bounds: %d", index);
//                 continue;
//             }

//             newPts[j] = geodesic::SurfacePoint(
//                 &restrictedGeoMesh.faces()[face2Index[index]], p.x(), p.y(), p.z(), geodesic::FACE
//             );
//         }
//     }

//     if (i == 0) {
//         pts_start = newPts;
//     } else {
//         pts_end = newPts;
//     }
//   }
// }

// static void getPathOnGeoMesh(
//   std::vector<geodesic::SurfacePoint> & path,
//   std::unordered_map<int, int> &index2Vertex,
//   std::unordered_map<int, int> &index2Face,
//   geodesic::Mesh & geoMesh
// )
// {
//   std::vector<geodesic::SurfacePoint> newPath;
//   for (auto & sp: path) {
//     if (sp.type() == geodesic::VERTEX) {
//       int index = ((geodesic::Vertex*) sp.base_element())->id();
//       newPath.push_back(&geoMesh.vertices()[index2Vertex[index]]);
//     }
//     else if (sp.type() == geodesic::EDGE) {
//       int index0 = ((geodesic::Edge*) sp.base_element())->v0()->id();
//       int index1 = ((geodesic::Edge*) sp.base_element())->v1()->id();
//       if (index2Vertex[index0] == index2Vertex[index1])
//         Msg::Error("Vertex not found: %d %d tooo %d %d", index0, index1, index2Vertex[index0], index2Vertex[index1]);
//       geodesic::Vertex * v0 = &geoMesh.vertices()[index2Vertex[index0]];
//       geodesic::Vertex * v1 = &geoMesh.vertices()[index2Vertex[index1]];
//       geodesic::Edge * e = nullptr;
//       for (size_t j = 0; j < v0->adjacent_edges().size(); ++j) {
//         e = v0->adjacent_edges()[j];
//         if ((e->v0() == v0 && e->v1() == v1) ||
//             (e->v0() == v1 && e->v1() == v0))
//           break;
//       }
//       if (e==nullptr || (e->v0() != v0 && e->v1() != v1) &&
//                         (e->v0() != v1 && e->v1() != v0)) {
//         std::cout << "v0 = " << v0->id() << " v1 = " << v1->id() << std::endl;
//         for (size_t j = 0; j < v0->adjacent_edges().size(); ++j) {
//           e = v0->adjacent_edges()[j];
//           if (e && e->v0() && e->v1()) {
//               std::cout << e->v0()->id() << " " << e->v1()->id() << std::endl;
//           } else {
//               std::cout << "Invalid edge or vertices!" << std::endl;
//           }
//         }
//         Msg::Error("Edge not found2");
//       }
//       newPath.push_back(geodesic::SurfacePoint(e, sp.x(), sp.y(), sp.z(), geodesic::EDGE));
//     }
//     else if (sp.type() == geodesic::FACE) {
//       int i = ((geodesic::Face*) sp.base_element())->id();
//       geodesic::Face * f = &geoMesh.faces()[index2Face[i]];
//       newPath.push_back(geodesic::SurfacePoint(f, sp.x(), sp.y(), sp.z(), geodesic::FACE));
//     }
//   }
//   path = newPath;
// }

void highOrderPolyMesh::createGeodesic(std::vector<geodesic::SurfacePoint> & pts_start,
                                       std::vector<geodesic::SurfacePoint> & pts_end,
                                       std::vector<std::vector<geodesic::SurfacePoint>> & paths)
                                      //  std::vector<std::vector<geodesic::SurfacePoint>> & paths,
                                      //  geodesic::Mesh *restrictedGeoMesh)
{
  if (pts_end.size() == 0) return;

  // if (restrictedGeoMesh == nullptr)
  //   restrictedGeoMesh = &geoMesh;

  // geodesic::Mesh rGeoMesh;
  // std::unordered_map<int,int> index2Vertex, index2Face;
  // bool restricted = false;
  // // bool restricted = true;
  // if (restricted)
  //   getRestrictedMesh(pm, pts_start, pts_end, rGeoMesh, index2Vertex, index2Face);
  // else
  //   rGeoMesh = geoMesh;

  // geodesic::GeodesicAlgorithmExact algorithm(&rGeoMesh);
  // geodesic::GeodesicAlgorithmExact algorithm(&geoMesh);
  // geodesic::GeodesicAlgorithmExact *alg = algorithm.get();
  algorithms[Msg::GetThreadNum()].propagate(pts_start, 0, &pts_end);
  for(size_t j = 0; j < pts_end.size(); j++) {
    std::vector<geodesic::SurfacePoint> path;
    algorithms[Msg::GetThreadNum()].trace_back(pts_end[j], path);
    if(path.empty()) {
      Msg::Info("propagation did not go far enough, widening the search");
      algorithms[Msg::GetThreadNum()].propagate(pts_start, 1.e22, &pts_end);
      algorithms[Msg::GetThreadNum()].trace_back(pts_end[j], path);
    }
    if (path.empty())
      Msg::Error("Error: geodesic path is empty");
    filterPath(path, 1.e-6); // fixme use relative error
    paths.push_back(path);
  }
  // for (auto p: paths)
  //   std::cout << p.size() << std::endl;

  // if (restricted) {
  //   for (auto & path: paths)
  //     getPathOnGeoMesh(path, index2Vertex, index2Face, geoMesh);
  // }
}

void highOrderPolyMesh::createGeodesicsInParallel(std::set<std::pair<int,int>> edges)
{
  // double t1 = TimeOfDay();

  int nthreads = getNumThreads();
  // Msg::Info("Computing geodesics using %d threads", nthreads);

  std::set<std::pair<int,int>> eds;
  for (auto it = edges.begin(); it != edges.end(); ++it) {
    std::pair<int,int> e = *it;
    if (e.first > e.second) std::swap(e.first, e.second);
    eds.insert(e);
  }

  std::vector<int> __rows, __columns, __starts;
  for(auto it = eds.begin(); it != eds.end(); ++it) {
    if (geodesics.find(*it) != geodesics.end()) continue;
    if (geodesics.find({it->second, it->first}) != geodesics.end()) continue;
    int row = it->first;
    int column = it->second;
    if(__rows.empty() || __rows[__rows.size() - 1] != row) {
      __starts.push_back(__columns.size());
      __rows.push_back(row);
    }
    __columns.push_back(column);
  }
  __starts.push_back(__columns.size());

  std::vector<
    std::map<std::pair<int, int>, std::vector<geodesic::SurfacePoint>>>
    __geodesics(nthreads);

#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(dynamic)
#endif

  for(size_t i = 0; i < __rows.size(); i++) {
    int start = __starts[i];
    int end = __starts[i + 1];

    Msg::Debug("Computing geodesics for vertex %d on thread %d ", __rows[i],
               Msg::GetThreadNum());

    std::vector<geodesic::SurfacePoint> pts_start = {points[__rows[i]]};
    std::vector<geodesic::SurfacePoint> pts_end;
    std::vector<std::pair<int, int>> pairs;
    for(int j = start; j < end; j++) {
      pts_end.push_back(points[__columns[j]]);
      pairs.push_back(std::make_pair(__rows[i], __columns[j]));
    }
    std::vector<std::vector<geodesic::SurfacePoint>> paths;
    createGeodesic(pts_start, pts_end, paths);
    for(int j = 0; j < pts_end.size(); j++) {
      auto path = paths[j];
      std::pair<int, int> inv = pairs[j];
      __geodesics[Msg::GetThreadNum()][std::make_pair(inv.second, inv.first)] =
        path;
      std::reverse(path.begin(), path.end());
      __geodesics[Msg::GetThreadNum()][pairs[j]] = path;
    }
  }

  for(auto g : __geodesics) geodesics.insert(g.begin(), g.end());

  // double t2 = TimeOfDay();

  // Msg::Info("Time for computing Geodesics : %12.5E sec", t2 - t1);
}

void highOrderPolyMesh::createGeodesics()
{
  std::set<std::pair<int,int>> eds;
  for (auto e: edges) {
    if (e.second.size() > 0)
      eds.insert(e.first);
  }
  createGeodesicsInParallel(eds);
}


// CREATE GEODESIC PATH
void highOrderPolyMesh::getGeodesicPath(
  int p0, int p1, std::vector<geodesic::SurfacePoint> &path)
{
  std::pair<int, int> p = std::make_pair(p0, p1);
  std::pair<int, int> pinv = std::make_pair(p1, p0);
  auto it = geodesics.find(p);
  auto itinv = geodesics.find(pinv);
  if(it != geodesics.end())
    path = it->second;
  else if(itinv != geodesics.end()) {
    path = itinv->second;
    std::reverse(path.begin(), path.end());
    geodesics[p] = path;
  }
  else {
    std::vector<geodesic::SurfacePoint> pts0 = {points[p0]};
    std::vector<geodesic::SurfacePoint> pts1 = {points[p1]};
    std::vector<std::vector<geodesic::SurfacePoint>> paths;
    createGeodesic(pts0, pts1, paths);
    path = paths[0];
    geodesics[pinv] = path;
    std::reverse(path.begin(), path.end());
    geodesics[p] = path;
  }

  if (path.size() < 2)
    Msg::Error("Error: geodesic path for %lu %lu has size %d", p0, p1, path.size());

  if (path.front().x() != points[p0].x() || path.front().y() != points[p0].y() || path.front().z() != points[p0].z())
    Msg::Error("Error: geodesic path does not start at the right point");

  if (path.back().x() != points[p1].x() || path.back().y() != points[p1].y() || path.back().z() != points[p1].z())
    Msg::Error("Error: geodesic path does not end at the right point");
}
// END CREATE GEODESIC PATH

// GET BOUNDARY PATH
void highOrderPolyMesh::getBoundaryPath(int p0, int p1, std::vector<geodesic::SurfacePoint> &path)
{
  path.clear();
  geodesic::SurfacePoint sp[2] = {points[p0], points[p1]};
  PolyMesh::HalfEdge *he[2];
  for (int i = 0; i < 2; ++i) {
    if (sp[i].base_element()->type() == geodesic::VERTEX) {
      he[i] = pm->vertices[sp[i].base_element()->id()]->he;
      while (he[i]->opposite != nullptr) he[i] = he[i]->opposite->next;
    }
    else if (sp[i].base_element()->type() == geodesic::EDGE) {
      PolyMesh::Vertex *v0 = pm->vertices[sp[i].base_element()->adjacent_vertices()[0]->id()];
      PolyMesh::Vertex *v1 = pm->vertices[sp[i].base_element()->adjacent_vertices()[1]->id()];
      he[i] = pm->getEdge(v0, v1);
      if (he[i] == nullptr)
        he[i] = pm->getEdge(v1, v0);
    }
    else
      Msg::Error("Error in getBoundaryPath: sp is not a vertex or an edge");
    if (he[i] == nullptr) Msg::Error("Error in getBoundaryPath: he is nullptr");
  }

  path.push_back(sp[0]);
  while (he[0] != he[1]) {
    he[0] = he[0]->next;
    while (he[0]->opposite != nullptr) he[0] = he[0]->opposite->next;
    auto sp = geodesic::SurfacePoint(&geoMesh.vertices()[he[0]->v->data]);
    path.push_back(sp);
  }
  if (sp[1].base_element()->type() == geodesic::EDGE)
    path.push_back(points[p1]);
}
// END GET BOUNDARY PATH

// GET PATH
void highOrderPolyMesh::getPath(std::pair<int,int> edge, int boundaryOrientation, std::vector<geodesic::SurfacePoint> &path)
{
  if (boundaryOrientation == 0) {
    getGeodesicPath(edge.first, edge.second, path);
    return;
  }
  if (boundaryOrientation == 1) {
    getBoundaryPath(edge.first, edge.second, path);
    return;
  }
  if (boundaryOrientation == -1) {
    getBoundaryPath(edge.second, edge.first, path);
    std::reverse(path.begin(), path.end());
    return;
  }
  Msg::Error("Error: boundaryOrientation = %d", boundaryOrientation);
}

int highOrderPolyMesh::getBoundaryOrientation(std::pair<int,int> edge)
{
  int i0 = edge.first, i1 = edge.second;
  std::pair<int,int> e = {i0, i1};
  if (e.first > e.second) std::swap(e.first, e.second);

  auto it = edges.find(e);
  if (it == edges.end()) {
    // Msg::Error("Error: edge has 0 triangles");
    // return -2;
    return 0;
  }

  if (it->second.size() == 2 || it->second.size() == 0)
    return 0;

  if (it->second.size() == 1) {
    for (int j = 0;j < 3; ++j) {
      if (triangles[3*edges[e][0]+j] == i0 && triangles[3*edges[e][0]+(j+1)%3] == i1)
        return 1;
      if (triangles[3*edges[e][0]+j] == i1 && triangles[3*edges[e][0]+(j+1)%3] == i0)
        return -1;
    }
    Msg::Error("Error: edge not found in triangle");
  }

  Msg::Error("Error: edge has %d triangles", it->second.size());
  return -2;
}

void highOrderPolyMesh::getPath(std::pair<int,int> edge, std::vector<geodesic::SurfacePoint> &path)
{
  int boundaryOrientation = getBoundaryOrientation(edge);
  getPath(edge, boundaryOrientation, path);

  // int i0 = edge.first, i1 = edge.second;

  // if (edges[edge].size() == 2) {
  //   getGeodesicPath(i0, i1, path);
  //   return;
  // }

  // if (edges[edge].size() == 1) {
  //   int j = 0;
  //   for (;j < 3; ++j) {
  //     if (triangles[3*edges[edge][0]+j] == i0 && triangles[3*edges[edge][0]+(j+1)%3] == i1)
  //       break;
  //   }
  //   if (j == 3) {
  //     getBoundaryPath(i1, i0, path);
  //     std::reverse(path.begin(), path.end());
  //   }
  //   else
  //     getBoundaryPath(i0, i1, path);
  //   return;
  // }

  // Msg::Error("Error: edge has %d triangles", edges[edge].size());
}
// END GET GEODESIC PATH

// INTERSECT GEODESIC PATH
bool highOrderPolyMesh::intersectGeodesicPath(
  std::vector<geodesic::SurfacePoint> &p0,
  std::vector<geodesic::SurfacePoint> &p1, SVector3 &intersection)
{
  for(size_t i = 1; i < p0.size(); i++) {
    SVector3 v0(p0[i - 1].x(), p0[i - 1].y(), p0[i - 1].z());
    SVector3 v1(p0[i].x(), p0[i].y(), p0[i].z());
    for(size_t j = 1; j < p1.size(); j++) {
      SVector3 w0(p1[j - 1].x(), p1[j - 1].y(), p1[j - 1].z());
      SVector3 w1(p1[j].x(), p1[j].y(), p1[j].z());
      if (i == 1 && (norm(v0 - w0) < 1e-6 || norm(v0 - w1) < 1e-6)) continue;
      if (i == p0.size()-1 && (norm(v1 - w0) < 1e-6 || norm(v1 - w1) < 1e-6)) continue;
      // if (j == 1 && (norm(v0 - w0) < 1e-6 || norm(v1 - w0) < 1e-6)) continue;
      // if (j == p1.size()-1 && (norm(v0 - w1) < 1e-6 || norm(v1 - w1) < 1e-6)) continue;
      double ori = robustPredicates::orient3d(v0, v1, w0, w1);
      SVector3 d1 = v1 - v0;
      SVector3 d2 = w1 - w0;
      SVector3 n = crossprod(d1, d2);
      if(n.norm() == 0.0) continue;
      n.normalize();
      SVector3 A = w0 - v0;
      // FIXME TOLERANCE
      if(fabs(ori) < 1.e-12) {
        SVector3 n1 = crossprod(n, d2);
        double lambda = dot(A, n1) / dot(d1, n1);
        if(lambda >= 0 && lambda <= 1) {
          intersection = v0 + lambda * d1;
         
          double mu = dot(intersection - w0, d2) / dot(d2, d2);
          if(mu >= 0 && mu <= 1) {
              return true;
          }
        }
      }
    }
  }
  return false;
}
// END INTERSECT GEODESIC PATH

// SPLIT TRIANGLE
int highOrderPolyMesh::splitTriangle(size_t iTriangle,
                                     geodesic::SurfacePoint &sp)
{
  if(sp.x() > 1.e10) return -2;
  int p3 = (int)points.size();

  points.push_back(sp);

  int p0 = triangles[3 * iTriangle + 0];
  int p1 = triangles[3 * iTriangle + 1];
  int p2 = triangles[3 * iTriangle + 2];

  std::vector<geodesic::SurfacePoint> p01, p12, p20;

  getGeodesicPath(p0, p1, p01);
  getGeodesicPath(p1, p2, p12);
  getGeodesicPath(p2, p0, p20);

  std::vector<geodesic::SurfacePoint> p03, p13, p23;

  getGeodesicPath(p0, p3, p03);
  getGeodesicPath(p1, p3, p13);
  getGeodesicPath(p2, p3, p23);

  double ori0 = computeBoxProduct(p1, p2, p3);
  double ori1 = computeBoxProduct(p2, p0, p3);
  double ori2 = computeBoxProduct(p0, p1, p3);

  //  SVector3 intersection;

  //  bool inters_0 = intersectGeodesicPath (p01,p23,intersection);
  //  bool inters_1 = intersectGeodesicPath (p12,p03,intersection);
  //  bool inters_2 = intersectGeodesicPath (p20,p13,intersection);

  // printf("%12.5E %12.5E %12.5E\n",ori0,ori1,ori2);

  if(ori0 > 0 && ori1 > 0 && ori2 > 0) {
    std::pair<int, int> e12 =
      std::make_pair(std::min(p1, p2), std::max(p1, p2));
    std::pair<int, int> e20 =
      std::make_pair(std::min(p2, p0), std::max(p2, p0));
    std::pair<int, int> e03 =
      std::make_pair(std::min(p0, p3), std::max(p0, p3));
    std::pair<int, int> e13 =
      std::make_pair(std::min(p1, p3), std::max(p1, p3));
    std::pair<int, int> e23 =
      std::make_pair(std::min(p2, p3), std::max(p2, p3));
    triangles[3 * iTriangle + 2] = p3;
    size_t iTriangle2 = triangles.size() / 3;
    triangles.push_back(p1);
    triangles.push_back(p2);
    triangles.push_back(p3);
    size_t iTriangle3 = triangles.size() / 3;
    triangles.push_back(p2);
    triangles.push_back(p0);
    triangles.push_back(p3);
    std::vector<size_t> e03_t = {iTriangle, iTriangle3};
    std::vector<size_t> e13_t = {iTriangle, iTriangle2};
    std::vector<size_t> e23_t = {iTriangle2, iTriangle3};
    edges[e03] = e03_t;
    edges[e13] = e13_t;
    edges[e23] = e23_t;
    auto e12_t = edges.find(e12);
    auto e20_t = edges.find(e20);
    e12_t->second.erase(
      std::remove(e12_t->second.begin(), e12_t->second.end(), iTriangle),
      e12_t->second.end());
    e12_t->second.push_back(iTriangle2);
    e20_t->second.erase(
      std::remove(e20_t->second.begin(), e20_t->second.end(), iTriangle),
      e20_t->second.end());
    e20_t->second.push_back(iTriangle3);
    return 0;
  }
  else {
    return -1;
  }
}
// END SPLIT TRIANGLE

// SWAP EDGE

int highOrderPolyMesh::swapEdge(const std::pair<int, int> &p01,
                                const int onlyMisoriented,
                                std::pair<int, int> *p23)
{ // force an edge swap (2 geodesics to compute)
  auto it01 = edges.find(p01);
  if(it01 == edges.end()) { return -2; }
  if(it01->second.size() != 2) { return -3; }
  size_t t0 = it01->second[0];
  size_t t1 = it01->second[1];
  int p0 = p01.first;
  int p1 = p01.second;
  int p2 = -1, p3 = -1;

  bool positive = false;
  for(int i = 0; i < 3; i++) {
    if(triangles[3 * t0 + i] == p0 && triangles[3 * t0 + (i + 1) % 3] == p1)
      positive = true;
  }
  if(!positive) {
    int temp = p0;
    p0 = p1;
    p1 = temp;
  }

  //  printf("swop %d %d (%d,%d,%d) (%d,%d,%d)\n",p0,p1,
  //	 triangles [3*t0 + 0],triangles [3*t0 + 1],triangles [3*t0 + 2],
  //	 triangles [3*t1 + 0],triangles [3*t1 + 1],triangles [3*t1 + 2]);

  for(int i = 0; i < 3; i++) {
    if(triangles[3 * t0 + i] != p0 && triangles[3 * t0 + i] != p1) {
      p2 = triangles[3 * t0 + i];
    }
    if(triangles[3 * t1 + i] != p0 && triangles[3 * t1 + i] != p1) {
      p3 = triangles[3 * t1 + i];
    }
  }

  if(p0 == p1 || p0 == p2 || p0 == p3 || p1 == p2 || p1 == p3 || p2 == p3)
    return -2;

  if(p23) {
    p23->first = positive ? p2 : p3;
    p23->second = positive ? p3 : p2;
    return 0;
  }

  {
    std::pair<int, int> p23 =
      std::make_pair(std::min(p2, p3), std::max(p2, p3));
    auto it23 = edges.find(p23);
    if(it23 != edges.end()) {
      Msg::Debug("Topological Obstruction in an Edge Swap (%d %d)", p2, p3);
      return -11;
    }
  }

  std::vector<geodesic::SurfacePoint> oldPath, newPath;
  getGeodesicPath(p0, p1, oldPath);
  getGeodesicPath(p2, p3, newPath);
  SVector3 intersection;
  if (  doWeSwap ( p0, p1, p2, p3, onlyMisoriented)/* && intersectGeodesicPath (oldPath, newPath,intersection)*/){
    std::pair<int, int> p12 =
      std::make_pair(std::min(p1, p2), std::max(p1, p2));
    std::pair<int, int> p03 =
      std::make_pair(std::min(p0, p3), std::max(p0, p3));
    std::pair<int, int> p23 =
      std::make_pair(std::min(p2, p3), std::max(p2, p3));
    auto it12 = edges.find(p12);
    auto it03 = edges.find(p03);
    if(it12 == edges.end()) Msg::Error("%d %s", __LINE__, __FILE__);
    if(it03 == edges.end()) Msg::Error("%d %s", __LINE__, __FILE__);
    it01->second.clear();
    // change triangle nodes
    triangles[3 * t0 + 0] = p0;
    triangles[3 * t0 + 1] = p3;
    triangles[3 * t0 + 2] = p2;
    triangles[3 * t1 + 0] = p3;
    triangles[3 * t1 + 1] = p1;
    triangles[3 * t1 + 2] = p2;
    if(it03->second[0] == t1)
      it03->second[0] = t0;
    else if(it03->second[1] == t1)
      it03->second[1] = t0;
    else {
      Msg::Warning("edge %d %d is not in triangle %d %d %d", it03->first.first,
                   it03->first.second, p0, p2, p3);
      return -2;
    }
    if(it12->second[0] == t0)
      it12->second[0] = t1;
    else if(it12->second[1] == t0)
      it12->second[1] = t1;
    else {
      Msg::Warning("edge %d %d is not in triangle %d %d %d", it12->first.first,
                   it12->first.second, p3, p2, p1);
      return -2;
    }
    std::vector<size_t> ts = {t0, t1};
    edges[p23] = ts;
  }
  else
    return -1;
  return 0;
}
// END SWAP EDGE

// CIRCUMCENTER
std::vector<geodesic::SurfacePoint>
highOrderPolyMesh::circumCenter(int iTriangle, double dist_max)
{
  int P[3] = {triangles[3 * iTriangle], triangles[3 * iTriangle + 1],
              triangles[3 * iTriangle + 2]};

  std::map<PolyMesh::Vertex *, double> dist[3];

  std::vector<geodesic::SurfacePoint> _END;
  for(int i = 0; i < 3; i++) {
    int p1 = P[i];
    int p2 = P[(i + 1) % 3];
    std::pair<int, int> p = std::make_pair(p1, p2);
    _END.insert(_END.end(), geodesics[p].begin(), geodesics[p].end());
  }

  for(int i = 0; i < 3; i++) {
    std::vector<geodesic::SurfacePoint> _start = {points[P[i]]};
    // geodesic::GeodesicAlgorithmExact algorithm(&geoMesh);
    algorithms[Msg::GetThreadNum()].propagate(_start, dist_max, &_END);
    // algorithms[Msg::GetThreadNum()].propagate(_start);

    for(size_t k = 0; k < geoMesh.vertices().size(); k++) {
      double d;
      geodesic::Vertex *v = &geoMesh.vertices()[k];
      geodesic::SurfacePoint sp(v);
      algorithms[Msg::GetThreadNum()].best_source(sp, d);
      if(d < 1.e10) dist[i][pm->vertices[k]] = d;
      //      if (fabs(v->x()-pm->vertices[k]->position.x()) > 1.e-10)
      //	printf("%12.5E %12.5E %12.5E
      //\n",v->x()-pm->vertices[k]->position.x(),
      //	       v->y()-pm->vertices[k]->position.y(),
      //	       v->z()-pm->vertices[k]->position.z());
    }
  }

  std::vector<geodesic::SurfacePoint> results;

  double dMin = 1.e33;
  for(size_t k = 0; k < pm->faces.size(); k++) {
    PolyMesh::Vertex *a = pm->faces[k]->he->v;
    PolyMesh::Vertex *b = pm->faces[k]->he->next->v;
    PolyMesh::Vertex *c = pm->faces[k]->he->next->next->v;
    if(dist[0].find(a) != dist[0].end() && dist[0].find(b) != dist[0].end() &&
       dist[0].find(c) != dist[0].end() && dist[1].find(a) != dist[1].end() &&
       dist[1].find(b) != dist[1].end() && dist[1].find(c) != dist[1].end() &&
       dist[2].find(a) != dist[2].end() && dist[2].find(b) != dist[2].end() &&
       dist[2].find(c) != dist[2].end()) {
      double d0a = dist[0][a];
      double d0b = dist[0][b];
      double d0c = dist[0][c];
      double d1a = dist[1][a];
      double d1b = dist[1][b];
      double d1c = dist[1][c];
      double d2a = dist[2][a];
      double d2b = dist[2][b];
      double d2c = dist[2][c];
      double mat[3][3] = {{d0a - d0b, d0a - d0c, 1},
                          {d1a - d1b, d1a - d1c, 1},
                          {d2a - d2b, d2a - d2c, 1}};
      double rhs[3] = {d0a, d1a, d2a}, uvd[3], det;
      sys3x3(mat, rhs, uvd, &det);
      //      if (iTriangle == 22)if (uvd[0] > -1 && uvd[0] < 2)printf("%12.5E
      //      %12.5E %12.5E %12.5E\n",uvd[0],uvd[1],1-uvd[1]-uvd[0],uvd[2]);
      if(fabs(det) > 1.e-8 && /*fabs(uvd[2]) < dMin && */ uvd[0] >= 0 &&
         uvd[1] >= 0 && 1. - uvd[0] - uvd[1] >= 0) {
        if(iTriangle == 37) printf("det %12.5E\n", det);
        double x = a->position.x() * (1. - uvd[0] - uvd[1]) +
                   b->position.x() * uvd[0] + c->position.x() * uvd[1];
        double y = a->position.y() * (1. - uvd[0] - uvd[1]) +
                   b->position.y() * uvd[0] + c->position.y() * uvd[1];
        double z = a->position.z() * (1. - uvd[0] - uvd[1]) +
                   b->position.z() * uvd[0] + c->position.z() * uvd[1];
        geodesic::SurfacePoint result =
          geodesic::SurfacePoint(&geoMesh.faces()[k], x, y, z, geodesic::FACE);
        results.push_back(result);
        dMin = fabs(uvd[2]);
      }
    }
  }

  if(!results.empty()) {
    char name[256];
    sprintf(name, "triangle%d.pos", iTriangle);
    //     print__ (name, pm, dist_);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \"P\"{\n");
    for(auto result : results)
      fprintf(f, "SP(%g,%g,%g){%d};\n", result.x(), result.y(), result.z(),
              iTriangle);
    fprintf(f, "};\n");
    fclose(f);
  }
  if(iTriangle == 37) {
    char name[256];
    sprintf(name, "no_triangle%d.pos", iTriangle);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \"P\"{\n");

    if(iTriangle == 37) {
      char _name[256];
      sprintf(_name, "distanceToVertex%d.pos", P[0]);
      print__(_name, pm, dist[0]);
      sprintf(_name, "distanceToVertex%d.pos", P[1]);
      print__(_name, pm, dist[1]);
      sprintf(_name, "distanceToVertex%d.pos", P[2]);
      print__(_name, pm, dist[2]);
    }

    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n", points[P[0]].x(),
            points[P[0]].y(), points[P[0]].z(), points[P[1]].x(),
            points[P[1]].y(), points[P[1]].z(), points[P[2]].x(),
            points[P[2]].y(), points[P[2]].z(), iTriangle, iTriangle,
            iTriangle);
    fprintf(f, "};\n");
    fclose(f);
  }
  return results;
}
// END CIRCUMCENTER

// PATH LENGTH
double highOrderPolyMesh::pathLength(const std::pair<int, int> &p01)
{
  auto it01 = edges.find(p01);
  if(it01 == edges.end()) { return -1.0; }
  int p0 = p01.first;
  int p1 = p01.second;
  std::vector<geodesic::SurfacePoint> oldPath;
  getGeodesicPath(p0, p1, oldPath);
  double l = 0;
  for(size_t i = 1; i < oldPath.size(); i++) {
    SPoint3 vi(oldPath[i - 1].x(), oldPath[i - 1].y(), oldPath[i - 1].z());
    SPoint3 vj(oldPath[i].x(), oldPath[i].y(), oldPath[i].z());
    SVector3 d = vj - vi;
    l += d.norm();
  }
  return l;
}
// END PATH LENGTH

// SPLIT EDGE
int highOrderPolyMesh::splitEdge(const std::pair<int, int> &p01, double lTarget,
                                 double adimMin, double adimMax)
{ // force an edge split (2 geodesics to compute)

  //  printf("coucou1 %d %d\n",p01.first,p01.second);
  auto it01 = edges.find(p01);
  if(it01 == edges.end()) { return -2; }
  if(it01->second.size() != 2) { return -3; }
  size_t t0 = it01->second[0];
  size_t t1 = it01->second[1];
  int p0 = p01.first;
  int p1 = p01.second;
  //    printf("split %d %d\n",p0,p1);
  int p2 = -1, p3 = -1;
  bool positive = false;
  for(int i = 0; i < 3; i++) {
    if(triangles[3 * t0 + i] == p0 && triangles[3 * t0 + (i + 1) % 3] == p1)
      positive = true;
  }
  if(!positive) {
    int temp = p0;
    p0 = p1;
    p1 = temp;
  }

  for(int i = 0; i < 3; i++) {
    if(triangles[3 * t0 + i] != p0 && triangles[3 * t0 + i] != p1) {
      p2 = triangles[3 * t0 + i];
    }
    if(triangles[3 * t1 + i] != p0 && triangles[3 * t1 + i] != p1) {
      p3 = triangles[3 * t1 + i];
    }
  }
  //    printf("other is %d %d\n",p2,p3);
  std::vector<geodesic::SurfacePoint> oldPath;
  std::vector<geodesic::SurfacePoint> path0mid;
  std::vector<geodesic::SurfacePoint> pathmid1;
  getGeodesicPath(p0, p1, oldPath);
  double lCurrent = pathLength(p01);
  //    printf("lCurrent = %12.5E\n",lCurrent);
  if(lTarget > 0 && lCurrent / lTarget < adimMax)
    return -1; // edge is not too long

  //  printf("coucou2 %d %d\n",p01.first,p01.second);

  it01->second.clear();

  double l = 0;
  geodesic::SurfacePoint sp;
  SPoint3 target(1.e22, 1.e22, 1.e22);
  for(size_t i = 1; i < oldPath.size(); i++) {
    SPoint3 vi(oldPath[i - 1].x(), oldPath[i - 1].y(), oldPath[i - 1].z());
    SPoint3 vj(oldPath[i].x(), oldPath[i].y(), oldPath[i].z());
    SVector3 d = vj - vi;
    double dl = d.norm();
    path0mid.push_back(oldPath[i - 1]);
    if(dl + l > lCurrent / 2) {
      //      printf("%g %g %g\n",l,l+dl,lCurrent/2);
      double alpha = (lCurrent / 2 - l) / dl;
      target = vi + (vj - vi) * alpha;
      MVertex v(target.x(), target.y(), target.z());
      sp = MVertexToGeodesicSurfacePoint(&v, pm, geoMesh, f2n, -1);
      //  printf("gaspologyblabla\n");
      path0mid.push_back(sp);
      pathmid1.push_back(sp);
      for(size_t j = i + 1; j < oldPath.size(); j++)
        pathmid1.push_back(oldPath[j]);
      break;
    }
    l += dl;
  }
  if(target.x() > 1.e21) return -2;
  int pmid = (int)points.size();
  points.push_back(sp);
  std::vector<geodesic::SurfacePoint> p0mid, pmid1;

  //  printf("coucou2 %d \n",pmid);

  std::pair<int, int> e0mid =
    std::make_pair(std::min(p0, pmid), std::max(p0, pmid));
  std::pair<int, int> e1mid =
    std::make_pair(std::min(p1, pmid), std::max(p1, pmid));
  std::pair<int, int> e2mid =
    std::make_pair(std::min(p2, pmid), std::max(p2, pmid));
  std::pair<int, int> e3mid =
    std::make_pair(std::min(p3, pmid), std::max(p3, pmid));
  std::pair<int, int> e12 = std::make_pair(std::min(p1, p2), std::max(p1, p2));
  std::pair<int, int> e13 = std::make_pair(std::min(p1, p3), std::max(p1, p3));

  std::vector<geodesic::SurfacePoint> p2mid, pmid3;
  getGeodesicPath(p2, pmid, p2mid);
  //    double l2mid = pathLength (e2mid);
  // if (l2mid/lTarget < adimMin) return -3
  getGeodesicPath(pmid, p3, pmid3);
  //    double lmid3 = pathLength (e3mid);
  // if (lmid3/lTarget < adimMin) return -3

  // FIXME I have them already ...
  getGeodesicPath(p0, pmid, p0mid);
  getGeodesicPath(pmid, p1, pmid1);

  triangles[3 * t0 + 0] = p0;
  triangles[3 * t0 + 1] = pmid;
  triangles[3 * t0 + 2] = p2;

  triangles[3 * t1 + 0] = p0;
  triangles[3 * t1 + 1] = p3;
  triangles[3 * t1 + 2] = pmid;

  size_t t2 = triangles.size() / 3;
  triangles.push_back(p1);
  triangles.push_back(p2);
  triangles.push_back(pmid);
  size_t t3 = triangles.size() / 3;
  triangles.push_back(p3);
  triangles.push_back(p1);
  triangles.push_back(pmid);

  std::vector<size_t> e0mid_t = {t0, t1};
  std::vector<size_t> e1mid_t = {t2, t3};
  std::vector<size_t> e2mid_t = {t0, t2};
  std::vector<size_t> e3mid_t = {t1, t3};
  edges[e0mid] = e0mid_t;
  edges[e1mid] = e1mid_t;
  edges[e2mid] = e2mid_t;
  edges[e3mid] = e3mid_t;

  auto e12_t = edges.find(e12);
  auto e13_t = edges.find(e13);

  e12_t->second.erase(
    std::remove(e12_t->second.begin(), e12_t->second.end(), t0),
    e12_t->second.end());
  e12_t->second.push_back(t2);
  e13_t->second.erase(
    std::remove(e13_t->second.begin(), e13_t->second.end(), t1),
    e13_t->second.end());
  e13_t->second.push_back(t3);
  return 0;
}





































// TIM'S IMPLEMENTATIONS:

double highOrderPolyMesh::adimLength(std::vector<geodesic::SurfacePoint> & path)
{
  if (path.size() < 2) Msg::Error("Path smaller than 2");
  double adimentionalLength = 0;
  double cl0, cl1 = cl(path[0]);
  for (size_t i = 0; i < path.size()-1; ++i) {
    SVector3 dl(getTrueCoords(path[i]), getTrueCoords(path[i+1]));
    cl0 = cl1;
    cl1 = cl(path[i+1]);
    adimentionalLength += dl.norm() * 2 / (cl0 + cl1);
  }
  if (adimentionalLength <= 0) Msg::Error("Negative or null adimentional length in computation: %g", adimentionalLength);
  return adimentionalLength;
}

double highOrderPolyMesh::adimLength(const std::pair<int,int> edge)
{
  auto it = lengths.find(edge);
  if (it != lengths.end()){
    if (it->second <= 0) Msg::Error("Negative or null adimentional length: %g", it->second);
    return it->second;
  }

  std::vector<geodesic::SurfacePoint> path;
  getPath(edge, path);
  lengths[edge] = adimLength(path);
  return lengths[edge];
}

std::vector<size_t>& highOrderPolyMesh::adjacentTriangles(std::pair<int,int> edge)
{
  if (edge.first > edge.second) std::swap(edge.first, edge.second);
  auto it = edges.find(edge);
  static std::vector<size_t> empty;
  return it == edges.end() ? empty : it->second;
}


// SWAP EDGE
/*
          p2                            p2
        /    \                        / | \
      /        \                    /   |   \
    /     t0     \                /     |     \
  p0 ------------ p1     =>     p0   t0 | t1   p1
    \     t1     /                \     |     /
      \        /                    \   |   /
        \    /                        \ | /
          p3                            p3
*/
bool highOrderPolyMesh::swapEdge(const std::pair<int, int> &edge,
                                 std::vector<std::pair<int,int>> & adjacentEdges)
{
  std::vector<size_t> ts = adjacentTriangles(edge);
  if (ts.size() != 2)
    Msg::Error("In swapEdge: edge %d %d has %d triangles", edge.first, edge.second, ts.size());

  std::pair<int,int> oppEdge;
  getOppEdge(edge, oppEdge);
  std::vector<size_t> tsOpp = adjacentTriangles(oppEdge);
  if (tsOpp.size() != 0) {
    Msg::Warning("Could not swap edge %d %d: opposite edge %d %d has %d adjacent triangles", edge.first, edge.second, oppEdge.first, oppEdge.second, tsOpp.size());
    return false;
  }

  std::vector<geodesic::SurfacePoint> p01, p23;
  getPath(edge, p01);
  getPath(oppEdge, p23);
  SVector3 intersection;
  if (!intersectGeodesicPath(p01, p23, intersection)) {
    Msg::Warning("Could not swap edge %d %d: geodesics do not intersect", edge.first, edge.second);
    return false;
  }


  edges.erase(edge);
  edges[{std::min(oppEdge.first,oppEdge.second), std::max(oppEdge.first,oppEdge.second)}] = {};
  adjacentEdges.resize(4);
  for (size_t i = 0; i < 2; ++i) {
    auto beginTriangle = triangles.begin() + 3*ts[0], endTriangle = beginTriangle + 3;
    int ps[4] = {edge.first, edge.second, oppEdge.first, oppEdge.second};
    auto p2 = std::find(beginTriangle, endTriangle, ps[2]);
    if (p2 == endTriangle) {
      std::swap(ps[0], ps[1]);
      std::swap(ps[2], ps[3]);
      p2 = std::find(beginTriangle, endTriangle, ps[2]);
      if (p2 == endTriangle)
        Msg::Error("In swapEdge: could not find vertex %d or %d in triangle %d", oppEdge.first, oppEdge.second, ts[0]);
    }

    auto p1 = (p2 == beginTriangle ? endTriangle : p2) - 1;
    *p1 = ps[3];

    std::vector<size_t>& ts23 = adjacentTriangles({ps[2], ps[3]});
    ts23.push_back(ts[0]);

    std::vector<size_t>& ts03 = adjacentTriangles({ps[0], ps[3]});
    auto t1 = std::find(ts03.begin(), ts03.end(), ts[1]);
    if (t1 == ts03.end())
      Msg::Error("In swapEdge: could not find triangle %d adjacent to edge %d %d", ts[1], ps[0], ps[3]);
    *t1 = ts[0];

    adjacentEdges[2*i] = {std::min(ps[0],ps[3]), std::max(ps[0],ps[3])};
    adjacentEdges[2*i+1] = {std::min(ps[0],ps[2]), std::max(ps[0],ps[2])};

    std::swap(ts[0], ts[1]);
  }

  return true;
}

void highOrderPolyMesh::getOppEdge(const std::pair<int, int> &p01, std::pair<int, int> &p23)
{
  p23 = {-1, -1};
  for (auto t: adjacentTriangles(p01)) {
    auto is = triangles.begin() + 3*t;
    for (int j = 0; j < 3; ++j) {
      if (is[j] == p01.first && is[(j+1)%3] == p01.second) {
        p23.first = is[(j+2)%3];
        break;
      }
      if (is[j] == p01.second && is[(j+1)%3] == p01.first) {
        p23.second = is[(j+2)%3];
        break;
      }
    }
  }
  if (p23.first == -1 || p23.second == -1)
    Msg::Error("Could not find opposite edge of %d %d: %d %d", p01.first, p01.second, p23.first, p23.second);
}

bool highOrderPolyMesh::doWeSwap(const std::pair<int,int> & edge)
{
  std::pair<int,int> oppEdge;
  getOppEdge(edge, oppEdge);

  int ps[12] = {edge.first, edge.second, oppEdge.first, oppEdge.second,
                edge.second, edge.first, oppEdge.second, oppEdge.first,
                edge.first, oppEdge.second, edge.second, oppEdge.first};
  double as[12];
  for (int i = 0; i < 12; ++i) {
    std::vector<geodesic::SurfacePoint> p01, p20;
    getPath({ps[i], ps[(i+1)%12]}, p01);
    getPath({ps[(i+11)%12], ps[i]}, p20);
    SVector3 n = normal(ps[i]);
    as[i] = computeAngle(p01, p20, n);
  }

  std::vector<double> A_before = {as[0], as[1], as[11], as[4], as[5], as[9]};
  std::vector<double> A_after = {as[2], as[3], as[10], as[6], as[7], as[8]};
  std::sort(A_before.begin(), A_before.end());
  std::sort(A_after.begin(), A_after.end());

  // if (edge.first == 128 || edge.second == 128 || oppEdge.first == 128 || oppEdge.second == 128) {
  //   if (edge.first == 124 || edge.second == 124 || oppEdge.first == 124 || oppEdge.second == 124) {
  //     if (edge.first == 123 || edge.second == 123 || oppEdge.first == 123 || oppEdge.second == 123) {
  //       std::cout << "n(124):" << normal(124).x() << " " << normal(124).y() << " " << normal(124).z() << std::endl;
  //       std::vector<geodesic::SurfacePoint> p01, p20;
  //       getPath({124,128}, p01);
  //       getPath({123,124}, p20);
  //       SVector3 v01(getTrueCoords(p01[0]), getTrueCoords(p01[1]));
  //       SVector3 v02(getTrueCoords(p20[p20.size()-1]), getTrueCoords(p20[p20.size()-2]));
  //       std::cout << "p01: " << v01.x() << " " << v01.y() << " " << v01.z() << std::endl;
  //       std::cout << "p02: " << v02.x() << " " << v02.y() << " " << v02.z() << std::endl;

  //       std::cout << "edge: " << edge.first << " " << edge.second << std::endl;
  //       std::cout << "oppEdge: " << oppEdge.first << " " << oppEdge.second << std::endl;
  //       std::cout << adjacentTriangles(edge).size() << " " << adjacentTriangles(oppEdge).size() << std::endl;
  //       std::cout << adjacentTriangles({edge.first, oppEdge.first}).size() << " " << adjacentTriangles({edge.second, oppEdge.first}).size() << std::endl;
  //       std::cout << adjacentTriangles({edge.first, oppEdge.second}).size() << " " << adjacentTriangles({edge.second, oppEdge.second}).size() << std::endl;
  //       std::cout << "as: ";
  //       for (int i = 0; i < 12; ++i) std::cout << as[i] << " ";
  //       std::cout << std::endl;
  //     A_before = {as[0], as[1], as[11], as[4], as[5], as[9]};
  //     A_after = {as[2], as[3], as[10], as[6], as[7], as[8]};
  //       std::cout << "A_before: ";
  //       for (auto a: A_before) std::cout << a << " ";
  //       std::cout << std::endl;
  //       std::cout << "A_after: ";
  //       for (auto a: A_after) std::cout << a << " ";
  //       std::cout << std::endl;
  //       std::cout << std::endl;
  //     std::sort(A_before.begin(), A_before.end());
  //     std::sort(A_after.begin(), A_after.end());
  //     }
  //   }
  // }

  if (A_after[0] <= A_before[0] || A_after[0] <= 1e-6)
    return false;

  return true;
}

int highOrderPolyMesh::swapEdges()
{
  int count = 0;
  std::set<std::pair<int,int>> set;
  for (auto it : edges) {
    if (it.second.size() != 2) continue;
    set.insert(it.first);
  }

  std::set<std::pair<int,int>> nextSet;
  while (!set.empty()) {
    nextSet.clear();

    // Pre-compute
    std::set<std::pair<int,int>> oppEdges;
    for (auto e: set) {
      std::pair<int,int> o;
      getOppEdge(e, o);
      oppEdges.insert(o);
    }
    createGeodesicsInParallel(oppEdges);

    while (!set.empty()) {
      std::pair<int,int> edge = *(set.begin());
      set.erase(set.begin());

      if (!doWeSwap(edge)) continue;

    // //
    //   std::pair<int,int> oppEdge;
    //   getOppEdge(edge, oppEdge);
    // //


      std::vector<std::pair<int,int>> adjacentEdges;
      if (!swapEdge(edge, adjacentEdges)) continue;
      ++count;

    // //
    //   doWeSwap({std::min(oppEdge.first,oppEdge.second), std::max(oppEdge.first,oppEdge.second)});
    // //


      for (auto e : adjacentEdges) {
        if (edges[e].size() != 2) continue;
        auto it = set.find(e);
        if (it != set.end()) set.erase(it);
        nextSet.insert(e);
      }
    }

    set = nextSet;
  }

  return count;
}
// END SWAP EDGE

// SPLIT EDGE
/*
            p2                             p2
          /   \                          / | \
        /       \        =>            /   |   \
      /     t     \                  /     |     \
    /               \              /   t   | newT  \
  p0 --------------- p1          p0 ----- mid ------ p1
*/
bool highOrderPolyMesh::splitEdge(const std::pair<int, int> & edge,
                                 std::vector<std::pair<int,int>> & adjacentEdges)
{
  std::vector<size_t> ts = adjacentTriangles(edge);
  if (ts.size() == 0 || ts.size() > 2)
    Msg::Error("In splitEdge: edge has %d triangles", ts.size());


  std::vector<geodesic::SurfacePoint> path, firstHalf, secondHalf;
  getPath(edge, path);
  splitPath(path, .5 * adimLength(path), firstHalf, secondHalf);


  std::vector<int> oppositeVertices(ts.size(), -1);
  for (int i = 0; i < ts.size(); ++i) {
    auto ps = triangles.begin() + 3*ts[i];
    for (int j = 0; j < 3; ++j) {
      if (ps[j] != edge.first && ps[j] != edge.second) {
        oppositeVertices[i] = ps[j];
        break;
      }
    }
    if (oppositeVertices[i] == -1)
      Msg::Error("In splitEdge: edge %d %d not found in triangle %d", edge.first, edge.second, ts[i]);
  }

  std::vector<geodesic::SurfacePoint> pts_start = {firstHalf.back()};
  std::vector<geodesic::SurfacePoint> pts_end;
  for (auto i: oppositeVertices)
    pts_end.push_back(points[i]);
  std::vector<std::vector<geodesic::SurfacePoint>> newPaths;
  createGeodesic(pts_start, pts_end, newPaths);

  SVector3 intersection;
  std::vector<geodesic::SurfacePoint> borderEdge[2];
  for (int i = 0; i < newPaths.size(); ++i) {
    getPath({oppositeVertices[1-i], edge.first}, borderEdge[0]);
    getPath({oppositeVertices[1-i], edge.second}, borderEdge[1]);
    if (!intersectGeodesicPath(newPaths[i], borderEdge[0], intersection) &&
        !intersectGeodesicPath(newPaths[i], borderEdge[1], intersection)) continue;
    Msg::Warning("Could not split edge %d %d: new geodesics intersect opposite border", edge.first, edge.second);
    return false;
  }

  std::vector<double> newLengths(newPaths.size());
  for (int i = 0; i < newPaths.size(); ++i) {
    newLengths[i] = adimLength(newPaths[i]);
    if (newLengths[i] > 0.9 * adimLength(edge)) {
      Msg::Warning("Could not split edge %d %d: new edge %d %d is too long (%g) w.r.t. the edge to split (%g)", edge.first, edge.second, edge.first, oppositeVertices[i], newLengths[i], adimLength(edge));
      return false;
    }
  }


  int mid = points.size();
  points.push_back(firstHalf.back());

  edges.erase(edge);
  edges[{std::min(edge.first,mid), std::max(edge.first,mid)}] = {};
  edges[{std::min(mid,edge.second), std::max(mid,edge.second)}] = {};
  for (auto i: oppositeVertices)
    edges[{std::min(mid,i), std::max(mid,i)}] = {};
  adjacentEdges.resize(3*ts.size() + 2);
  for (int i = 0; i < ts.size(); ++i) {
    int t = ts[i];
    auto beginTriangles = triangles.begin() + 3*t, endTriangles = beginTriangles + 3;
    auto p2 = std::find(beginTriangles, endTriangles, oppositeVertices[i]);
    auto p1 = (p2 == beginTriangles ? endTriangles : p2) - 1;
    int ps[3] = {p2 == endTriangles - 1 ? *beginTriangles : *(p2+1), *p1, *p2};

    *p1 = mid;
    std::vector<size_t>& ts0mid = adjacentTriangles({ps[0], mid});
    ts0mid.push_back(t);
    std::vector<size_t>& ts2mid = adjacentTriangles({ps[2], mid});
    ts2mid.push_back(t);

    int newT = triangles.size() / 3;
    triangles.push_back(mid);
    triangles.push_back(ps[1]);
    triangles.push_back(ps[2]);
    ts2mid.push_back(newT);
    std::vector<size_t>& ts1mid = adjacentTriangles({ps[1], mid});
    ts1mid.push_back(newT);
    std::vector<size_t>& ts12 = adjacentTriangles({ps[1], ps[2]});
    auto it = std::find(ts12.begin(), ts12.end(), t);
    if (it == ts12.end())
      Msg::Error("In splitEdge: could not find triangle %d adjacent to edge %d %d", t, ps[1], ps[2]);
    *it = newT;


    adjacentEdges[3*i] = {std::min(ps[2],ps[0]), std::max(ps[2],ps[0])};
    adjacentEdges[3*i + 1] = {std::min(ps[2],mid), std::max(ps[2],mid)};
    adjacentEdges[3*i + 2] = {std::min(ps[2],ps[1]), std::max(ps[2],ps[1])};
  }
  adjacentEdges[3*ts.size()] = {std::min(edge.first,mid), std::max(edge.first,mid)};
  adjacentEdges[3*ts.size()+1] = {std::min(mid,edge.second), std::max(mid,edge.second)};

  geodesics[{edge.first, mid}] = firstHalf;
  geodesics[{mid, edge.second}] = secondHalf;
  for (int i = 0; i < newPaths.size(); ++i) {
    std::pair<int,int> e = {oppositeVertices[i],mid};
    geodesics[e] = newPaths[i];
    if (e.first > e.second) std::swap(e.first, e.second);
    lengths[e] = newLengths[i];
  }

  return true;
}

void highOrderPolyMesh::splitPath(std::vector<geodesic::SurfacePoint> & path, const double length,
                                  std::vector<geodesic::SurfacePoint> & firstHalf,
                                  std::vector<geodesic::SurfacePoint> & secondHalf)
{
  if (length < 0) Msg::Error("In splitPath: length is negative");
  if (path.size() < 2) Msg::Error("In splitPath: path only made of %d points", path.size());
  firstHalf.clear();
  secondHalf.clear();

  double L = length, dL;
  SVector3 v0 = getTrueCoords(path[0]), v1;
  double cl0 = cl(path[0]), cl1;
  int i = 0;
  for (; i+1 < path.size(); ++i) {
    firstHalf.push_back(path[i]);
    v1 = getTrueCoords(path[i+1]);
    cl1 = cl(path[i+1]);
    dL = norm(v1 - v0) * 2 / (cl0 + cl1);
    if (dL >= L)
      break;
    L -= dL;
    v0 = v1;
    cl0 = cl1;
  }
  if (i+1 >= path.size())
    Msg::Error("In splitPath: trying to split a path of length %lu at %lu", length-L, length);

  double tLocal = L / dL;
  if (tLocal < 1e-2) {
    secondHalf.push_back(path[i]);
  }
  else if (1 - tLocal < 1e-2) {
    firstHalf.push_back(path[i+1]);
  }
  else {
    geodesic::SurfacePoint sp(nullptr, (1 - tLocal) * path[i].x() + tLocal * path[i+1].x(),
                                       (1 - tLocal) * path[i].y() + tLocal * path[i+1].y(),
                                       (1 - tLocal) * path[i].z() + tLocal * path[i+1].z(), geodesic::UNDEFINED_POINT);

    std::set<geodesic::Vertex *> adjacent_vertices;
    for (int j = 0; j < 2; ++j) {
      geodesic::base_pointer be = path[i+j].base_element();
      if (be->type() == geodesic::VERTEX)
        adjacent_vertices.insert((geodesic::Vertex *) be);
      else {
        for (auto v : be->adjacent_vertices())
          adjacent_vertices.insert(v);
      }
    }

    if (adjacent_vertices.size() == 2) { // New point on an edge
      geodesic::Vertex *v0 = *adjacent_vertices.begin();
      geodesic::Vertex *v1 = *adjacent_vertices.rbegin();
      geodesic::Edge *e = nullptr;
      for (auto ae: v0->adjacent_edges()) {
        if (ae->v0() != v1 && ae->v1() != v1)
          continue;
        e = ae;
        break;
      }
      if (e == nullptr) Msg::Error("In splitPath: vertices %d and %a are not connected", v0->id(), v1->id());
      sp = geodesic::SurfacePoint(e, sp.x(), sp.y(), sp.z(), geodesic::EDGE);
    }
    else if (adjacent_vertices.size() == 3) { // New point on a face
      auto it = adjacent_vertices.begin();
      geodesic::Vertex *v0 = *it++, *v1 = *it++, *v2 = *it++;
      geodesic::Face *f = nullptr;
      for (auto af: v0->adjacent_faces()) {
        auto vs = af->adjacent_vertices();
        if (vs[0] != v1 && vs[1] != v1 && vs[2] != v1) continue;
        if (vs[0] != v2 && vs[1] != v2 && vs[2] != v2) continue;
        f = af;
        break;
      }
      if (f == nullptr) Msg::Error("Error in splitPath: vertices are not on the same face");
      sp = geodesic::SurfacePoint(f, sp.x(), sp.y(), sp.z(), geodesic::FACE);
    }
    else
      Msg::Error("In splitPath: can not find a SurfacePoint configuration with %d adjacent vertices", adjacent_vertices.size());

    firstHalf.push_back(sp);
    secondHalf.push_back(sp);
  }

  i++;
  for (; i < path.size(); ++i)
    secondHalf.push_back(path[i]);

  if (firstHalf.size() < 2 || secondHalf.size() < 2)
    Msg::Error("In splitPath: could not split path in two paths (%d points and %d points)", firstHalf.size(), secondHalf.size());
}


int highOrderPolyMesh::splitEdges(const double MAXE, double MINA)
{
  int count = 0;
  auto compare = [this](std::pair<int, int> a, std::pair<int, int> b) { return adimLength(a) > adimLength(b); };
  std::set<std::pair<int, int>, decltype(compare)> queue(compare);

  for (auto it : edges) {
    if (it.second.size() != 1 && it.second.size() != 2)
      Msg::Error("In splitEdges: edge %d %d has %d triangles", it.first.first, it.first.second, it.second.size());
    queue.insert(it.first);
  }

  while (!queue.empty()) {
    std::pair<int,int> edge = *queue.begin();
    queue.erase(queue.begin());

    if (adimLength(edge) <= MAXE) break;

    std::vector<std::pair<int,int>> adjacentEdges;
    if (!splitEdge(edge, adjacentEdges)) continue;
    ++count;

    for (auto e: adjacentEdges)
      queue.insert(e);
  }

  return count;
}
// END SPLIT EDGE

// COLLAPSE EDGE
/*
      pA ------ pB                  pA ------ pB
      / \  tA  / \                  /  tA   /  \
     /   \    /   \                /    /       \
    /  t  \  /  tB \              / /      tB    \
  p0 ----- p1 ----- pC    =>    p0 -------------- pC
             \  tC /                \      tC    /
              \   /                     \       /
               \ /                          \  /
                pD                            pD
*/
bool highOrderPolyMesh::collapseEdge(std::pair<int,int> edge, 
                                    std::set<size_t> & keep,
                                    std::vector<std::pair<int,int>> &adjacentEdges,
                                    std::vector<std::pair<int,int>> &removedEdges,
                                    double MINA)
{
  std::vector<size_t> ts = adjacentTriangles(edge);
  if (ts.size() != 1 && ts.size() != 2)
    Msg::Error("In collapseEdge: edge %d %d has %d triangles", edge.first, edge.second, ts.size());

  std::vector<int> iXstmp;
  adjacentVertices(edge, iXstmp);
  for (int i = 1; i+1 < iXstmp.size(); ++i) {
    if (adjacentTriangles({iXstmp[i], edge.first}).size() != 0) {
      Msg::Warning("Could not collapse edge %d %d: the edge %d %d already exists.", edge.first, edge.second, iXstmp[i], edge.first);
      return false;
    }
  }

  if (ts.size() == 1) {
    if (adjacentTriangles({iXstmp.front(), edge.first}).size() != 0 &&
        adjacentTriangles({iXstmp.back(), edge.first}).size() != 0) {
      Msg::Warning("Could not collapse edge %d %d: the boundary edge %d %d or %d %d already exists.", edge.first, edge.second, iXstmp.front(), edge.first, iXstmp.back(), edge.first);
      return false;
    }
  }



  // size_t i0 = edge.first;
  // size_t i1 = edge.second;

  // double tmpmaxLs[2] = {0, 0};
  // if (points[i1].base_element()->type() == geodesic::VERTEX && 
  //     keep.find(points[i1].base_element()->id()) != keep.end())
  //   tmpmaxLs[0] = std::numeric_limits<double>::max();
  // if (points[i0].base_element()->type() == geodesic::VERTEX && 
  //     keep.find(points[i0].base_element()->id()) != keep.end())
  //   tmpmaxLs[1] = std::numeric_limits<double>::max();


  // std::pair<int,int> eds[2] = {{i0,i1}, {i1,i0}};
  // std::vector<int> iXss[2];
  // for (size_t i = 0; i < 2; ++i) {
  //   auto ed = eds[i];
  //   std::vector<int> & iXs = iXss[i];
  //   adjacentVertices(ed, iXs);

  //   // Topology check: do not collapse a boundary triangle
  //   if (edges[{std::min(ed.first,ed.second),std::max(ed.first,ed.second)}].size() == 1 &&
  //       ((edges[{std::min(ed.first,iXs.front()),std::max(ed.first,iXs.front())}].size() == 1 &&
  //         edges[{std::min(ed.second,iXs.front()),std::max(ed.second,iXs.front())}].size() == 1)
  //        ||
  //        (edges[{std::min(ed.first,iXs.back()),std::max(ed.first,iXs.back())}].size() == 1 &&
  //         edges[{std::min(ed.second,iXs.back()),std::max(ed.second,iXs.back())}].size() == 1))) {
  //     // std::cout << "Boundary edge " << ed.first << " " << ed.second << " with " << iXs.size() << " vertices" << std::endl;
  //     iXs.clear();
  //   }

  //   // if (ed.first == 241 || ed.first == 242 || ed.first == 293) {
  //   //   std::cout << "Not Boundary Edge " << ed.first << " " << ed.second << " has " << iXs.size() << " vertices" << std::endl;
  //   //   std::cout << edges[{std::min(ed.first,ed.second),std::max(ed.first,ed.second)}].size() << " " << edges[{std::min(ed.first,iXs.back()),std::max(ed.first,iXs.back())}].size() << std::endl;
  //   //   std::cout << "iXs.back()=" << iXs.back() << std::endl;
  //   // }

  //   std::vector<int> iDests;
  //   for (auto iX: iXs) {
  //     if (geodesics.find({ed.first,iX}) != geodesics.end()) continue;
  //     if (geodesics.find({iX,ed.first}) != geodesics.end()) continue;
  //     iDests.push_back(iX);
  //   }
  //   std::vector<geodesic::SurfacePoint> starts = {points[ed.first]};
  //   std::vector<geodesic::SurfacePoint> dests;
  //   for (auto iD: iDests) dests.push_back(points[iD]);
  //   std::vector<std::vector<geodesic::SurfacePoint>> paths;
  //   createGeodesic(starts, dests, paths);
  //   for (size_t j = 0; j < iDests.size(); ++j)
  //     geodesics[{iDests[j], ed.first}] = paths[j];


  //   for (size_t j = 1; j+1 < iXs.size(); ++j) {
  //     std::vector<geodesic::SurfacePoint> path;
  //     auto it = geodesics.find({iXs[j], ed.first});
  //     if (it == geodesics.end())
  //       it = geodesics.find({ed.first, iXs[j]});
  //     if (it == geodesics.end())
  //       Msg::Error("Error: geodesic not found !");
  //     path = it->second;
  //     tmpmaxLs[i] = std::max(tmpmaxLs[i], adimLength(path));
  //   }
  // }

  // std::pair<int,int> p01 = eds[0];
  // std::vector<int> iXs = iXss[0];
  // double maxL = tmpmaxLs[0];
  // if (tmpmaxLs[1] < tmpmaxLs[0]) {
  //   p01 = eds[1];
  //   iXs = iXss[1];
  //   maxL = tmpmaxLs[1];
  // }
  // if (maxL == std::numeric_limits<double>::max())
  //   return false;

  // do {
  //   std::swap(eds[0], eds[1]);
  //   std::swap(iXss[0], iXss[1]);
  //   std::swap(tmpmaxLs[0], tmpmaxLs[1]);

  //   if (!canWeCollapse(eds[0], iXss[0], MINA)) {
  //     // std::cout << "Can not collapse edge " << eds[0].first << " " << eds[0].second << std::endl;
  //     tmpmaxLs[0] = std::numeric_limits<double>::max();
  //   }
  // } while (tmpmaxLs[1] < tmpmaxLs[0]);

  std::pair<int,int> p01 = edge;
  std::vector<int> iXs = iXstmp;
  // double maxL = tmpmaxLs[0];

  // if (maxL == std::numeric_limits<double>::max())
  //   return false;

  // int p = p01.second, opp = p01.first;




  // auto it = edges.find(edge);
  for (auto iT: ts) {
    for (int j = 0; j < 3; ++j) {
      size_t i0 = triangles[3*iT + j];
      size_t i1 = triangles[3*iT + (j+1)%3];
      std::pair<int,int> e = {std::min(i0,i1), std::max(i0,i1)};
      auto it = std::find(edges[e].begin(), edges[e].end(), iT);
      if (it == edges[e].end())
        Msg::Error("Error: edge not found !");
      edges[e].erase(it);
    }
    for (int j = 0; j < 3; ++j) {
      triangles[3*iT + j] = -1;
    }
  }
  // edges.erase(it);
  edges.erase(edge);
  lengths.erase(edge);

  removedEdges.clear();
  adjacentEdges.clear();
  for (size_t i = 0; i < iXs.size(); ++i) {
    std::pair<int,int> e = {std::min(p01.second,iXs[i]), std::max(p01.second,iXs[i])};
    removedEdges.push_back(e);
    auto it = edges.find(e);
    e = {std::min(p01.first,iXs[i]), std::max(p01.first,iXs[i])};
    adjacentEdges.push_back(e);
    for (auto iT: it->second) {
      edges[e].push_back(iT);
      for (int j = 0; j < 3; ++j) {
        if (triangles[3*iT + j] == p01.second)
          triangles[3*iT + j] = p01.first;
      }
    }
    edges.erase(it);
  }

  return true;
}

void highOrderPolyMesh::adjacentVertices(std::pair<int,int> p01, std::vector<int> & iXs)
{
  bool reverse = false;
  size_t t = adjacentTriangles(p01)[0];
  auto beginTriangle = triangles.begin() + 3*t, endTriangle = beginTriangle + 3;
  auto p1 = std::find(beginTriangle, endTriangle, p01.second);
  int pX = *(p1 == endTriangle-1 ? beginTriangle : p1+1);
  if (pX == p01.first) {
    reverse = true;
    pX = *(p1 == beginTriangle ? endTriangle-1 : p1-1);
  }

  iXs.clear();
  while (pX != p01.first) {
    iXs.push_back(pX);
    auto ts = adjacentTriangles({pX, p01.second});
    if (ts.size() != 2) break;
    t = ts[0] == t ? ts[1] : ts[0];
    auto p = triangles.begin() + 3*t;
    while (*p == pX || *p == p01.second) ++p;
    pX = *p;
  }

  // Check topology when a boundary is reached
  if (adjacentTriangles({pX, p01.second}).size() != 2 && adjacentTriangles(p01).size() != 1)
    iXs.clear();

  if (reverse)
    std::reverse(iXs.begin(), iXs.end());
}

bool highOrderPolyMesh::canWeCollapse(std::pair<int,int> p01, std::vector<int> & iXs,
                                      double MINA)
{
  if (iXs.size() < 1)
    return false;

  double minA = std::numeric_limits<double>::max();
  int i0 = p01.first, i1 = p01.second;
  for (size_t i = 0; i+1 < iXs.size(); ++i) {
    int iBefore[3] = {i1, iXs[i+1], iXs[i]};
    int iAfter[3] = {i0, iXs[i+1], iXs[i]};

    int boundaryOrients[3] = {getBoundaryOrientation({iBefore[0], iBefore[1]}),
                              getBoundaryOrientation({iBefore[1], iBefore[2]}),
                              getBoundaryOrientation({iBefore[2], iBefore[0]})};
    double angles[3];
    computeAngles(iBefore, angles, boundaryOrients);
    for (int j = 0; j < 3; ++j)
      MINA = std::min(MINA, angles[j]);

    computeAngles(iAfter, angles, boundaryOrients);
    for (int j = 0; j < 3; ++j)
      minA = std::min(minA, angles[j]);
  }
  // if (minA < MINA + 1e-6)
  if (minA < MINA)
    return false;


  // std::cout << "Checking " << i0 << " "<< i1 << ": ";
  // for (auto iX: iXs)
  //   std::cout << iX << " ";
  // std::cout << std::endl;

  if (edges[{std::min(i0,i1), std::max(i0,i1)}].size() == 1) {
    int iT = edges[{std::min(i0,i1), std::max(i0,i1)}][0];
    int iX = iXs.front();
    std::pair<int,int> e = {std::min(iX,i0), std::max(iX,i0)};
    if (edges[e].size() > 0 && (edges[e][0] == iT || (edges[e].size() == 2 && edges[e][1] == iT))) {
      iX = iXs.back();
      e = {std::min(iX,i0), std::max(iX,i0)};
    }

    if (edges[e].size() != 0)
      return false;
  }

  for (size_t i = 1; i+1 < iXs.size(); ++i) {
    std::pair<int,int> e = {std::min(i0, iXs[i]), std::max(i0, iXs[i])};
    if (edges[e].size() != 0)
      return false;
    // std::cout << i0 << " " << iXs[i] << " ok ("<< edges[e].size() <<")" << std::endl;
  }

  return true;
}

//  void highOrderPolyMesh::preComputeForCollapse(std::set<int> & allVertices)
// {
//   // Pre-compute geodesics
//   std::map<int, std::vector<int>> star;
//   for (size_t i = 0; i < triangles.size()/3; ++i) {
//     for (int j = 0; j < 3; ++j) {
//       int i0 = triangles[3*i + j];
//       int i1 = triangles[3*i + (j+1)%3];
//       star[i0].push_back(i1);
//       star[i1].push_back(i0);
//     }
//   }
//   std::set<std::pair<int,int>> allEdges;
//   for (auto i: allVertices) {
//     for (auto j: star[i]) {
//       for (auto k: star[j]) {
//         if (k == i) continue;
//         allEdges.insert({std::min(i,k), std::max(i,k)});
//       }
//     }
//   }
//   createGeodesicsInParallel(allEdges);
// }

std::pair<bool,bool> highOrderPolyMesh::doWeCollapse(std::pair<int,int> & edge, std::set<size_t> & keep)
{
  std::pair<bool,bool> collapse = {true, true};

  std::pair<int,int> es[2] = {edge, {edge.second, edge.first}};
  double maxLengths[2] = {0, 0};
  for (int i = 0; i < 2; ++i) {
    std::vector<int> iXs;
    adjacentVertices(es[i], iXs);
  //
  if (iXs.size() < 1) {
    if (i == 0) collapse.first = false;
    else collapse.second = false;
    continue;
  }
  //

    for (int j = 0; j < iXs.size(); ++j) {
      if (j == 0 && adjacentTriangles(es[i]).size() == 1) continue;
      if (j == iXs.size()-1 && adjacentTriangles(es[i]).size() == 1) continue;
      if (adjacentTriangles({iXs[j], es[i].second}).size() == 1) {
        if (i == 0) collapse.first = false;
        else collapse.second = false;
        break;
      }
    }
    if (adjacentTriangles(es[i]).size() == 1 && 
        adjacentTriangles({iXs.front(), es[i].second}).size() == 1 && 
        adjacentTriangles({iXs.back(), es[i].second}).size() == 1) {
      if (i == 0) collapse.first = false;
      else collapse.second = false;
    }
    if (i == 0 && !collapse.first) continue;
    if (i == 1 && !collapse.second) continue;


    
    std::vector<geodesic::SurfacePoint> pts_start = {points[es[i].first]}, pts_end;
    std::vector<int> dests;
    for (auto iX: iXs) {
      if (geodesics.find({es[i].first, iX}) != geodesics.end()) continue;
      if (geodesics.find({iX, es[i].first}) != geodesics.end()) continue;
      if (adjacentTriangles({es[i].second, iX}).size() == 1) continue;
      dests.push_back(iX);
    }
    for (auto iX: dests) pts_end.push_back(points[iX]);
    std::vector<std::vector<geodesic::SurfacePoint>> newPaths;
    createGeodesic(pts_start, pts_end, newPaths);
    for (auto j = 0; j < dests.size(); ++j) geodesics[{dests[j], es[i].first}] = newPaths[j];

//     std::vector<size_t> ts = adjacentTriangles(es[i]);
//     std::vector<size_t> tXs;
//     for (auto iX: iXs) {
//       for (auto tX: adjacentTriangles({es[i].second, iX})) {
//         if (std::find(ts.begin(), ts.end(), tX) != ts.end()) continue;
//         tXs.push_back(tX);
//       }
//     }
//     for (auto tX: tXs) {
//       int is[3] = {triangles[3*tX], triangles[3*tX+1], triangles[3*tX+2]};
//       if (is[1] == es[i].second) {std::swap(is[0], is[1]); std::swap(is[1], is[2]);}
//       if (is[2] == es[i].second) {std::swap(is[0], is[2]); std::swap(is[1], is[2]);}
//       std::vector<std::vector<geodesic::SurfacePoint>> paths(3);
//       std::vector<geodesic::SurfacePoint> tmp;
//       if (adjacentTriangles({is[0], is[1]}).size() == 1) {
//         getPath(es[i], paths[0]);
//         getPath({is[0], is[1]}, tmp);
//         paths[0].insert(paths[0].end(), tmp.begin(), tmp.end());
//       }
//       else
//         getPath({es[i].first, is[1]}, paths[0]);

//       getPath({is[1], is[2]}, paths[1]);

//       if (adjacentTriangles({is[2], is[0]}).size() == 1) {
//         getPath({is[2], is[0]}, paths[2]);
//         getPath({es[i].second, es[i].first}, tmp);
//         paths[2].insert(paths[2].end(), tmp.begin(), tmp.end());
//       }
//       else
//         getPath({is[2], es[i].first}, paths[2]);

//       maxLengths[i] = std::max(maxLengths[i], adimLength(paths[0]));
//       maxLengths[i] = std::max(maxLengths[i], adimLength(paths[2]));

//       // for (int j = 0; j < 3; ++j) {
//       //   std::vector<geodesic::SurfacePoint> & p01 = paths[j], & p20 = paths[(j+2)%3];
//       //   SVector3 n = normal(is[j]);
//       //   double angle = computeAngle(p01, p20, n);
//       //   minAngles[i] = std::min(minAngles[i], angle);
//       // }
// // which one ??
//       std::vector<geodesic::SurfacePoint> & p01 = paths[0], & p20 = paths[2];
//       SVector3 n = normal(is[0]);
//       double angle = computeAngle(p01, p20, n);
//       minAngles[i] = std::min(minAngles[i], angle);

//     }
    // if (minAngles[i] < 1e-6) {
    //   if (i == 0) collapse.first = false;
    //   else collapse.second = false;
    // }

    std::vector<geodesic::SurfacePoint> oldPaths[2], path, tmp;
    if (adjacentTriangles({iXs.front(), es[i].second}).size() == 2)
      getPath({iXs.front(), es[i].second}, oldPaths[0]);
    else {
      getBoundaryPath(iXs.front(), es[i].first, path);
      maxLengths[i] = std::max(maxLengths[i], adimLength(path));
    }

    if (adjacentTriangles({es[i].second, iXs.back()}).size() == 2)
      getPath({es[i].second, iXs.back()}, oldPaths[1]);
    else {
      getBoundaryPath(es[i].first, iXs.back(), path);
      maxLengths[i] = std::max(maxLengths[i], adimLength(path));
    }

    SVector3 intersection;
    for (int j = 1; j+1 < iXs.size(); ++j) {
      getPath({es[i].first, iXs[j]}, tmp);
      path = tmp;
      maxLengths[i] = std::max(maxLengths[i], adimLength(path));
      // path.erase(path.begin());
      // path.pop_back();
      if (intersectGeodesicPath(path, oldPaths[0], intersection)) continue;
      if (intersectGeodesicPath(path, oldPaths[1], intersection)) continue;
      if (i == 0) collapse.first = false;
      else collapse.second = false;
      break;
    }

  }

  if (abs(1 - maxLengths[0]) > abs(1 - maxLengths[1]) && collapse.second) {
    std::swap(edge.first, edge.second);
    std::swap(collapse.first, collapse.second);
  }

  // if (minAngles[0] > minAngles[1] && collapse.second) {
  //   std::swap(edge.first, edge.second);
  //   std::swap(collapse.first, collapse.second);
  // }

  return collapse;
}

int highOrderPolyMesh::collapseEdges(const double MINE, double MINA, std::set<size_t> & keep)
{
  int count = 0;
  auto compare = [this](std::pair<int, int> a, std::pair<int, int> b) { return adimLength(a) < adimLength(b); };
  std::set<std::pair<int, int>, decltype(compare)> queue(compare);

  for (auto it : edges) {
    if (it.second.size() != 1 && it.second.size() != 2)
      Msg::Error("In collapseEdges: edge %d %d has %d triangles", it.first.first, it.first.second, it.second.size());
    queue.insert(it.first);
  }


  // std::set<int> allVertices;
  // for (auto it = queue.begin(); it != queue.end(); ++it) {
  //   if (adimLength(*it) > MINE)
  //     break;
  //   allVertices.insert(it->first);
  //   allVertices.insert(it->second);
  // }
  // preComputeForCollapse(allVertices);


  while (queue.size()) {
    std::pair<int,int> edge = *queue.begin();
    queue.erase(queue.begin());

    if (adimLength(edge) >= MINE) break;

    std::pair<bool,bool> collapse = doWeCollapse(edge, keep);
    if (!collapse.first)
      continue;

    std::vector<std::pair<int,int>> adjacentEdges;
    std::vector<std::pair<int,int>> removedEdges;
    if (!collapseEdge(edge, keep, adjacentEdges, removedEdges, MINA)) {
      if (!collapse.second)
        continue;
      if (!collapseEdge({edge.second, edge.first}, keep, adjacentEdges, removedEdges, MINA))
        continue;
    }

    ++count;
    for (auto e: removedEdges)
      queue.erase(e);
    for (auto e: adjacentEdges)
      queue.insert(e);
  }



  // Removing points, edges and triangles not connected to the mesh
  std::vector<int> newTriangles;
  std::map<int,int> old2New;
  std::map<int,int> old2NewTriangle;
  std::map<std::pair<int,int>, std::vector<size_t>> newEdges;
  for (size_t i = 0; i < triangles.size()/3; ++i) {
    if (triangles[3*i] == -1) continue;
    old2NewTriangle[i] = old2NewTriangle.size();
    for (int j = 0; j < 3; ++j) {
      auto it = old2New.find(triangles[3*i+j]);
      if (it == old2New.end())
        old2New[triangles[3*i+j]] = old2New.size();
      newTriangles.push_back(old2New[triangles[3*i+j]]);
    }
    for (int j = 0; j < 3; ++j) {
      int i0 = old2New[triangles[3*i+j]];
      int i1 = old2New[triangles[3*i+(j+1)%3]];
      if (i0 > i1) std::swap(i0, i1);
      std::pair<int,int> e = {i0, i1};
      newEdges[e].push_back(old2NewTriangle[i]);
    }
  }

  std::vector<geodesic::SurfacePoint> newPoints(old2New.size());
  // std::vector<double> newLcs(old2New.size());
  for (auto kv: old2New) {
    newPoints[kv.second] = points[kv.first];
    // newLcs[kv.second] = lcs[kv.first];
  }

  // for (auto kv: edges) {
  //   std::pair<int,int> edge = kv.first;
  //   if (old2New.find(edge.first) == old2New.end() || 
  //       old2New.find(edge.second) == old2New.end())
  //     continue;
  //   std::pair<int,int> newEdge = {old2New[edge.first], old2New[edge.second]};
  //   if (newEdge.first > newEdge.second) std::swap(newEdge.first, newEdge.second);
  //   for (auto iT: kv.second) {
  //     auto it = old2NewTriangle.find(iT);
  //     if (it == old2NewTriangle.end())
  //       Msg::Error("Error while add collapsing edges1 ! (%d triangles)", old2NewTriangle.size());
  //     newEdges[newEdge].push_back(old2NewTriangle[iT]);
  //   }
  // }

  std::map<std::pair<int,int>, std::vector<geodesic::SurfacePoint>> newGeodesics;
  for (auto kv: geodesics) {
    std::pair<int,int> edge = kv.first;
    if (old2New.find(edge.first) == old2New.end() || 
        old2New.find(edge.second) == old2New.end())
      continue;
    std::pair<int,int> newEdge = {old2New[edge.first], old2New[edge.second]};
    newGeodesics[newEdge] = kv.second;
  }

  std::map<std::pair<int,int>, double> newLengths;
  for (auto kv: lengths) {
    std::pair<int,int> edge = kv.first;
    if (old2New.find(edge.first) == old2New.end() || 
        old2New.find(edge.second) == old2New.end())
      continue;
    std::pair<int,int> newEdge = {old2New[edge.first], old2New[edge.second]};
    if (newEdge.first > newEdge.second) std::swap(newEdge.first, newEdge.second);
    newLengths[newEdge] = kv.second;
  }


  triangles.clear();
  points.clear();
  // lcs.clear();
  edges.clear();
  geodesics.clear();
  lengths.clear();

  triangles = newTriangles;
  points = newPoints;
  // lcs = newLcs;
  edges = newEdges;
  geodesics = newGeodesics;
  lengths = newLengths;



  return count;
}


// int highOrderPolyMesh::intrinsicCollapseEdges(const double MINE, double MINA, std::set<size_t> & keep)
// {
//   int count = 0;
//   auto compare = [this](std::pair<int, int> a, std::pair<int, int> b) { return adimLength(a) < adimLength(b); };
//   std::set<std::pair<int, int>, decltype(compare)> queue(compare);

//   for (auto it : edges) {
//     if (it.second.size() > 2)
//       Msg::Error("Error while add collapsing edges ! (%d triangles)", it.second.size());
//     if (it.second.size() == 0) continue;
//     adimLength(it.first);
//     queue.insert(it.first);
//   }


//   // std::set<int> allVertices;
//   // for (auto it = queue.begin(); it != queue.end(); ++it) {
//   //   if (adimLength(*it) > MINE)
//   //     break;
//   //   allVertices.insert(it->first);
//   //   allVertices.insert(it->second);
//   // }
//   // preComputeForCollapse(allVertices);


//   while (queue.size()) {
//     std::pair<int,int> edge = *queue.begin();
//     queue.erase(queue.begin());
//     double length = adimLength(edge);
//     if (length > MINE)
//       break;

//     std::vector<std::pair<int,int>> adjacentEdges;
//     std::vector<std::pair<int,int>> removedEdges;
//     if (intrinsicCollapseEdge(edge, keep, adjacentEdges, removedEdges, MINA)) {
//       continue;
//     }

//     ++count;

//     for (auto kv: edges) {
//       if (kv.second.size() > 2)
//         Msg::Error("Error while add collapsing edges1 ! (%d triangles)", kv.second.size());
//     }

//     // std::cout << "remove " << removedEdges.size() << std::endl;
//     for (auto e: removedEdges) {
//       auto it = queue.find(e);
//       if (it != queue.end())
//         queue.erase(it);
//     }
//     for (auto e: adjacentEdges) {
//       auto it = queue.find(e);
//       if (it != queue.end())
//         queue.erase(it);
//       adimLength(e);
//       queue.insert(e);
//     }
//   }



//   // Removing points, edges and triangles not connected to the mesh
//   std::vector<int> newTriangles;
//   std::map<int,int> old2New;
//   std::map<int,int> old2NewTriangle;
//   std::map<std::pair<int,int>, std::vector<size_t>> newEdges;
//   for (size_t i = 0; i < triangles.size()/3; ++i) {
//     if (triangles[3*i] == -1) continue;
//     old2NewTriangle[i] = old2NewTriangle.size();
//     for (int j = 0; j < 3; ++j) {
//       auto it = old2New.find(triangles[3*i+j]);
//       if (it == old2New.end())
//         old2New[triangles[3*i+j]] = old2New.size();
//       newTriangles.push_back(old2New[triangles[3*i+j]]);
//     }
//     for (int j = 0; j < 3; ++j) {
//       int i0 = old2New[triangles[3*i+j]];
//       int i1 = old2New[triangles[3*i+(j+1)%3]];
//       if (i0 > i1) std::swap(i0, i1);
//       std::pair<int,int> e = {i0, i1};
//       newEdges[e].push_back(old2NewTriangle[i]);
//     }
//   }

//   std::vector<geodesic::SurfacePoint> newPoints(old2New.size());
//   // std::vector<double> newLcs(old2New.size());
//   for (auto kv: old2New) {
//     newPoints[kv.second] = points[kv.first];
//     // newLcs[kv.second] = lcs[kv.first];
//   }

//   // for (auto kv: edges) {
//   //   std::pair<int,int> edge = kv.first;
//   //   if (old2New.find(edge.first) == old2New.end() || 
//   //       old2New.find(edge.second) == old2New.end())
//   //     continue;
//   //   std::pair<int,int> newEdge = {old2New[edge.first], old2New[edge.second]};
//   //   if (newEdge.first > newEdge.second) std::swap(newEdge.first, newEdge.second);
//   //   for (auto iT: kv.second) {
//   //     auto it = old2NewTriangle.find(iT);
//   //     if (it == old2NewTriangle.end())
//   //       Msg::Error("Error while add collapsing edges1 ! (%d triangles)", old2NewTriangle.size());
//   //     newEdges[newEdge].push_back(old2NewTriangle[iT]);
//   //   }
//   // }

//   std::map<std::pair<int,int>, std::vector<geodesic::SurfacePoint>> newGeodesics;
//   for (auto kv: geodesics) {
//     std::pair<int,int> edge = kv.first;
//     if (old2New.find(edge.first) == old2New.end() || 
//         old2New.find(edge.second) == old2New.end())
//       continue;
//     std::pair<int,int> newEdge = {old2New[edge.first], old2New[edge.second]};
//     newGeodesics[newEdge] = kv.second;
//   }

//   std::map<std::pair<int,int>, double> newLengths;
//   for (auto kv: lengths) {
//     std::pair<int,int> edge = kv.first;
//     if (old2New.find(edge.first) == old2New.end() || 
//         old2New.find(edge.second) == old2New.end())
//       continue;
//     std::pair<int,int> newEdge = {old2New[edge.first], old2New[edge.second]};
//     if (newEdge.first > newEdge.second) std::swap(newEdge.first, newEdge.second);
//     newLengths[newEdge] = kv.second;
//   }


//   triangles.clear();
//   points.clear();
//   // lcs.clear();
//   edges.clear();
//   geodesics.clear();
//   lengths.clear();

//   triangles = newTriangles;
//   points = newPoints;
//   // lcs = newLcs;
//   edges = newEdges;
//   geodesics = newGeodesics;
//   lengths = newLengths;



//   return count;
// }

// END COLLAPSE EDGE




















// CUT MESH
PolyMesh *highOrderPolyMesh::cutMesh(std::vector<PolyMesh::Vertex *> & pointVertices)
{
  size_t nbFaces = pm->faces.size();
  std::vector<SVector3> p0;
  std::vector<SVector3> t1;
  std::vector<SVector3> t2;
  std::vector<SVector3> ns;

  for(size_t i = 0; i < nbFaces; i++) {
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    p0.push_back(he->v->position);
    SVector3 _t1 = he->d();
    SVector3 _t2 = he->next->d();
    _t1.normalize();
    SVector3 _n = crossprod(_t1, _t2);
    _t2 = crossprod(_n, _t1);
    _t2.normalize();
    p0.push_back(he->v->position);
    t1.push_back(_t1);
    t2.push_back(_t2);
    _n.normalize();
    ns.push_back(_n);
  }

  {
    std::map<PolyMesh::Vertex *, double> nothing;
    print__("spliut.pos", pm, nothing);
  }

  FILE *f = fopen("triangulate.pos", "w");
  fprintf(f, "View \"\"{\n");

  FILE *f2 = fopen("tags.pos", "w");
  fprintf(f2, "View \"\"{\n");

  // ---  Cut every mesh edge with eventual additional points

  printf("Classifying Geodesic Vertices\n");
  classifyGeodesicVertices(pointVertices);
  printf("Classifying Geodesic Vertices Done\n");

  printf("Spliting original mesh using geodesics\n");
  for(auto it : evs) {
    PolyMesh::HalfEdge *he = it.first;
    std::vector<PolyMesh::Vertex *> vv;
    for(auto i : it.second) {
      vv.push_back(pm->vertices[i]);
      pm->vertices[i]->position = pm->vertices[i]->position - he->v->position;
    }
    std::sort(vv.begin(), vv.end(), compareVertexOnHalfEdge);
    for(auto i : it.second) {
      pm->vertices[i]->position = pm->vertices[i]->position + he->v->position;
    }
    for(size_t k = 0; k < vv.size(); k++) {
      pm->split_edge_general(he, vv[k]);
      he = he->next;
    }
  }
  printf("Spliting original mesh using geodesics Done\n");

  // ---  Split every face taking into account constrained edges
  // ---  that belong to geodesic lines

  std::vector<size_t> tris;
  std::vector<size_t> bnds;

  for(size_t i = 0; i < nbFaces; i++) {
    //    if (i == 9) printf("face %d\n",i);

    std::vector<double> coord;
    std::vector<PolyMesh::Vertex *> pp;
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    do {
      SVector3 pos = he->v->position;
      double x = dot(pos - p0[i], t1[i]);
      double y = dot(pos - p0[i], t2[i]);
      //      if (i == 9)printf("point %d %12.5E %12.5E %12.5E --> %12.5E
      //      %12.5E\n",he->v->data,pos.x(),pos.y(),pos.z(),x,y);
      coord.push_back(x);
      coord.push_back(y);
      pp.push_back(he->v);
      he = he->next;
    } while(he != pm->faces[i]->he);

    // Want to recover the boundary of the triangle
    std::vector<size_t> recover_all;
    for(size_t j = 0; j < pp.size(); j++) {
      recover_all.push_back(j);
      recover_all.push_back((j + 1) % pp.size());
    }

    // There exist internal points on the triangle

    std::map<PolyMesh::Face *, std::vector<int>>::iterator it =
      fvs.find(pm->faces[i]);
    FILE *deb = nullptr;
    //    if (i == 9) {
    //      char name [256];
    //      sprintf(name,"2d%d.pos",i);
    //      deb = fopen (name,"w");
    //      fprintf(deb,"View \"\"{\n");
    //    }
    if(it != fvs.end()) {
      for(size_t j = 0; j < it->second.size(); j++) {
        //	if (i == 9)printf("%lu vertices -- internal point %lu = %d\n",
        //	       pm->vertices.size(), j, it->second[j]);
        PolyMesh::Vertex *newv = pm->vertices[it->second[j]];
        SVector3 pos = newv->position;
        double x = dot(pos - p0[i], t1[i]);
        double y = dot(pos - p0[i], t2[i]);
        coord.push_back(x);
        coord.push_back(y);
        pp.push_back(newv);
      }
    }
    for(size_t j = 0; j < coord.size(); j += 2) {
      if(deb)
        fprintf(deb, "SP(%g,%g,%g){1,1,1};\n", coord[2 * j], coord[2 * j + 1],
                0.0);
    }

    // Some other edges should be recovered because they belong to geodesics

    std::vector<size_t> recover;

    for(size_t j = 0; j < pp.size(); j++) {
      PolyMesh::Vertex *vj = pp[j];
      std::map<PolyMesh::Vertex *, std::vector<int>>::iterator itj =
        pvtags.find(vj);
      if(itj != pvtags.end()) {
        for(size_t k = j + 1; k < pp.size(); k++) {
          PolyMesh::Vertex *vk = pp[k];
          std::map<PolyMesh::Vertex *, std::vector<int>>::iterator itk =
            pvtags.find(vk);
          if(itk != pvtags.end()) {
            for(auto tagj : itj->second) {
              if(tagj != -1 && std::find(itk->second.begin(), itk->second.end(),
                                         tagj) != itk->second.end()) {
                recover.push_back(j);
                recover.push_back(k);
                recover_all.push_back(j);
                recover_all.push_back(k);
                bnds.push_back(vj->data);
                bnds.push_back(vk->data);
                bnds.push_back(tagj);

                fprintf(f2,
                        "SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E){%"
                        "d,%d};\n",
                        vj->position.x(), vj->position.y(), vj->position.z(),
                        vk->position.x(), vk->position.y(), vk->position.z(),
                        tagj, tagj);
              }
            }
          }
        }
      }
    }

    if(pp.size() >= 3) {
      std::vector<size_t> tri;
      //      if (i == 9)printf("%lu points recovering %lu edges on triangle
      //      %lu\n",pp.size(),recover_all.size(),i);
      meshTriangulate2d(coord, tri,
                        recover_all.empty() ? nullptr : &recover_all);

      // verify if orientation is ok (it should be thet case ...)
      if(1) {
        for(size_t j = 0; j < tri.size(); j += 3) {
          int n0 = tri[j] - 1;
          int n1 = tri[j + 1] - 1;
          int n2 = tri[j + 2] - 1;
          PolyMesh::Vertex *j0 = pp[n0];
          PolyMesh::Vertex *j1 = pp[n1];
          PolyMesh::Vertex *j2 = pp[n2];
          SVector3 _t1 = j1->position - j0->position;
          SVector3 _t2 = j2->position - j0->position;
          SVector3 _n = crossprod(_t1, _t2);
          double area = _n.norm();
          _n.normalize();
          double ps = dot(_n, ns[i]);
          if(area < 1.e-12) {
            Msg::Warning("prodsca %22.15E %lu area %22.15E", ps, i, area);
            for(size_t k = 0; k < pp.size(); k++) {
              Msg::Warning("pt %lu %d %22.15E %22.15E %22.15E", k, pp[k]->data,
                           pp[k]->position.x(), pp[k]->position.y(),
                           pp[k]->position.z());
            }
          }
          if(ps < 0) {
            size_t tmp = tri[j];
            tri[j] = tri[j + 2];
            tri[j + 2] = tmp;
          }
        }
      }

      for(size_t j = 0; j < tri.size(); j += 3) {
        int n0 = tri[j] - 1;
        int n1 = tri[j + 1] - 1;
        int n2 = tri[j + 2] - 1;
        PolyMesh::Vertex *j0 = pp[n0];
        PolyMesh::Vertex *j1 = pp[n1];
        PolyMesh::Vertex *j2 = pp[n2];
        tris.push_back(j0->data);
        tris.push_back(j1->data);
        tris.push_back(j2->data);

        if(deb)
          fprintf(deb, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                  coord[2 * n0], coord[2 * n0 + 1], 0.0, coord[2 * n1],
                  coord[2 * n1 + 1], 0.0, coord[2 * n2], coord[2 * n2 + 1], 0.0,
                  j0->data, j1->data, j2->data);

        fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%lu,%lu,%lu};\n",
                j0->position.x(), j0->position.y(), j0->position.z(),
                j1->position.x(), j1->position.y(), j1->position.z(),
                j2->position.x(), j2->position.y(), j2->position.z(), i, i, i);
        //		j0->data,j1->data,j2->data);
      }
    }
    if(deb) {
      fprintf(deb, "};\n");
      fclose(deb);
    }
  }
  fprintf(f, "};\n");
  fclose(f);
  fprintf(f2, "};\n");
  fclose(f2);

  PolyMesh *pm_new = createPolyMesh(pm, tris, bnds);

  return pm_new;
}
// END CUT MESH

// WRITE
void highOrderPolyMesh::write(const PolyMesh *pm_new, std::vector<PolyMesh::Vertex *> & pointVertices)
{
  //
  // All points
  //
  // std::string currentModel;
  // gmsh::model::getCurrent(currentModel);
  // gmsh::model::add("points");

  Msg::Info("%lu points", pm_new->vertices.size());
  std::map<int, MVertex*> index2MVertex;
  std::map<int, char> pointAssigned;
  Msg::Info("Writing 'points.csv'...");
  std::ofstream outputPoints("points.csv");
  outputPoints << "pointTag,x,y,z\n";
  for (size_t i = 0; i < pm_new->vertices.size(); ++i) {
    auto v = pm_new->vertices[i];
    SVector3 pos = v->position;
    int index = v->data;
    // gmsh::model::geo::addPoint(pos.x(), pos.y(), pos.z(), 1., index);
    outputPoints << index << "," << pos.x() << "," << pos.y() << "," << pos.z() << "\n";
    auto mv = new MVertex(pos.x(), pos.y(), pos.z());
    mv->setIndex(index);
    index2MVertex[index] = mv;
    pointAssigned[index] = 0;
  }
  outputPoints.close();
  // gmsh::model::geo::synchronize();
  // gmsh::write("points.msh");
  // gmsh::model::setCurrent(currentModel);


  //
  // Vertices
  //
  std::set<int> vertexTags;
  std::vector<int> faceTags(triangles.size()/3);
  std::map<int, int> faceTags2Index;
  for (size_t i = 0; i < triangles.size()/3; ++i) {
    std::set<int> faces;
    for (int j = 0; j < 3; ++j) {
      int index = pointVertices[triangles[3*i+j]]->data;
      vertexTags.insert(index); // TODO: manage non-vertex sp
      PolyMesh::HalfEdge *he = pm_new->vertices[index]->he;
      std::set<int> otherFaces;
      do {
        otherFaces.insert(he->f->data);
        if (he->opposite != nullptr)
          he = he->opposite->next;
        else {
          while (he->prev->opposite != nullptr) {
            he = he->prev->opposite;
            otherFaces.insert(he->f->data);
          }
          pm_new->vertices[index]->he = he;
        }
      } while (he != pm_new->vertices[index]->he);
      if (j == 0)
        faces = otherFaces;
      else {
        std::set<int> intersection;
        std::set_intersection(faces.begin(), faces.end(),
                              otherFaces.begin(), otherFaces.end(),
                              std::inserter(intersection, intersection.begin()));
        faces = intersection;
      }
    }
    if (faces.size() != 1) {
      Msg::Error("Triangle %lu correspond to %lu faces", i, faces.size());
      return;
    }
    faceTags[i] = *faces.begin();
    faceTags2Index[faceTags[i]] = i;
  }
  Msg::Info("%lu vertices ", vertexTags.size());
  // std::vector<int> vertexTags(points.size());
  Msg::Info("Writing 'vertices.csv'...");
  std::ofstream outputVertices("vertices.csv");
  outputVertices << "vertexTag\n";
  for (auto it = vertexTags.begin(); it != vertexTags.end(); ++it) {
    pointAssigned[*it] = 1;
    outputVertices << *it <<"\n";
  }
  outputVertices.close();
  Msg::Info("Done writing 'vertices.csv'");


  // Msg::Info("%lu vertices ", points.size());
  // std::vector<int> vertexTags(points.size());
  // Msg::Info("Writing 'vertices.csv'...");
  // std::ofstream outputVertices("vertices.csv");
  // outputVertices << "vertexTag\n";
  // for (size_t i = 0; i < points.size(); ++i) {
  //   int id = points[i].base_element()->id();
  //   vertexTags[i] = id;
  //   pointAssigned[id] = 1;
  //   outputVertices << id <<"\n";
  // }
  // outputVertices.close();
  // Msg::Info("Done writing 'vertices.csv'");


  //
  // Edges
  //
  Msg::Info("%lu edges", triangles.size());
  Msg::Info("Writing 'edges.csv'...");
  std::ofstream outputEdges("edges.csv");
  outputEdges << "firstVertexTag,secondVertexTag,pointTag\n";
  std::vector<std::vector<PolyMesh::HalfEdge*>> triangleHEdges(triangles.size());
  for (size_t i = 0; i < triangles.size()/3; ++i) {
    int faceTag = faceTags[i];
    for (int j = 0; j < 3; ++j) {
      int index0 = pointVertices[triangles[3*i+j]]->data;
      int index1 = pointVertices[triangles[3*i+(j+1)%3]]->data;
      PolyMesh::HalfEdge *he = pm_new->vertices[index0]->he;
      while (he->v->data != index1) {
        while (he->f->data != faceTag || he->data == -1) {
          if (he->opposite == nullptr) {
            Msg::Error("HalfEdge not found");
            return;
          }
          he = he->opposite->next;
        }
        triangleHEdges[3*i+j].push_back(he);
        outputEdges << index0 << "," << index1 << "," << he->v->data << "\n";
        he = he->next;
      }
      outputEdges << index0 << "," << index1 << "," << he->v->data << "\n";
    }
  }
  outputEdges.close();
  Msg::Info("Done writing 'edges.csv'");



  //
  // Faces
  //
  Msg::Info("%lu faces", triangles.size()/3);
  Msg::Info("Writing 'faces.csv'...");
  std::ofstream outputFaces("faces.csv");
  outputFaces << "firstVertexTag,secondVertexTag,thridVertexTag," << "pointTag\n";
  Msg::Info("Writing 'triangles.csv'...");
  std::ofstream outputTriangles("triangles.csv");
  outputTriangles << "firstVertexTag,secondVertexTag,thridVertexTag,"
                  << "firstPointTag,secondPointTag,thridPointTag\n";
  Msg::Info("Writing 'parametrization.csv'...");
  std::ofstream outputParametrization("parametrization.csv");
  outputParametrization << "firstVertexTag,secondVertexTag,thridVertexTag,"
                        << "pointTag,pointU,pointV\n";
  for (size_t index = 0; index < triangles.size()/3; ++index) {
    size_t i0 = pointVertices[triangles[3*index]]->data;
    size_t i1 = pointVertices[triangles[3*index+1]]->data;
    size_t i2 = pointVertices[triangles[3*index+2]]->data;
    std::set<int> pts;
    std::set<int> boundaryPts;

    std::vector<size_t> vertices(3);
    std::vector<MVertex*> mVertices(3);
    for (int i = 0; i < 3; i++) {
      vertices[i] = pointVertices[triangles[3*index+i]]->data;
      mVertices[i] = index2MVertex[vertices[i]];
    }
    std::vector<MTriangle *> mTriangles;
    for (size_t i = 0; i < pm_new->faces.size(); ++i) {
      PolyMesh::Face *f = pm_new->faces[i];
      if (f->data != faceTags[index]) continue;
      PolyMesh::HalfEdge *hes[3] = {f->he,
                                    f->he->next,
                                    f->he->next->next};

      outputTriangles << i0 << "," << i1 << "," << i2;
      for (size_t j = 0; j < 3; ++j) {
        outputTriangles << "," << hes[j]->v->data;
        if (hes[j]->data == -1)
          pts.insert(hes[j]->v->data);
        else
          boundaryPts.insert(hes[j]->v->data);
      }
      outputTriangles << "\n";

      auto mTriangle = new MTriangle(index2MVertex[f->he->v->data],
                                     index2MVertex[f->he->next->v->data],
                                     index2MVertex[f->he->next->next->v->data]);
      mTriangles.push_back(mTriangle);
    }

    for (auto p: pts) {
      if (boundaryPts.find(p) == boundaryPts.end())
        outputFaces << i0 << "," << i1 << "," << i2 << "," << p << "\n";
    }

    std::vector<MVertex *> nodes;
    std::vector<SPoint2> stl_vertices_uv;
    std::vector<SPoint3> stl_vertices_xyz;
    std::vector<int> stl_triangles;
    computeParametrization(mTriangles, nodes, stl_vertices_uv, stl_vertices_xyz, stl_triangles, mVertices);
    for (size_t i = 0; i < nodes.size(); i++) {
      for (int j = 0; j < 3; j++)
        outputParametrization << vertices[j] << ",";
      outputParametrization << nodes[i]->getIndex() << "," << stl_vertices_uv[i].x() << "," << stl_vertices_uv[i].y() << "\n";
    }

    for (auto mTriangle : mTriangles)
      delete mTriangle;
  }
  outputFaces.close();
  Msg::Info("Done writing 'faces.csv'");
  outputTriangles.close();
  Msg::Info("Done writing 'triangles.csv'");
  outputParametrization.close();
  Msg::Info("Done writing 'parametrization.csv'");


  for (size_t i = 0; i < pm_new->vertices.size(); ++i) {
    delete index2MVertex[i];
  }
}
// END WRITE


// void saveIsoTriangles(int num, std::vector<int> & hopTriangles, std::vector<geodesic::SurfacePoint> & hopPoints, std::vector<double> & hopLCs)
void saveIsoTriangles(int num, std::vector<int> & hopTriangles, std::vector<geodesic::SurfacePoint> & hopPoints)
{
    char name[256];
    snprintf(name, sizeof(name), "isoTriangle%d.pos", num);
    std::ofstream f(name);
    if (!f) Msg::Error("Failed to open file: %s", name);
    f << "View \"P\"{\n";
    for (size_t i = 0; i < hopTriangles.size() / 3; ++i) {
        auto sp0 = hopPoints.at(hopTriangles.at(3 * i + 0));
        auto sp1 = hopPoints.at(hopTriangles.at(3 * i + 1));
        auto sp2 = hopPoints.at(hopTriangles.at(3 * i + 2));
        
        f << "ST(" << sp0.x() << "," << sp0.y() << "," << sp0.z() << ","
                << sp1.x() << "," << sp1.y() << "," << sp1.z() << ","
                << sp2.x() << "," << sp2.y() << "," << sp2.z() << "){"
                // << hopLCs[hopTriangles[3 * i + 0]] << ","
                // << hopLCs[hopTriangles[3 * i + 1]] << ","
                // << hopLCs[hopTriangles[3 * i + 2]] << "};\n";
                << hopTriangles[3 * i + 0] << ","
                << hopTriangles[3 * i + 1] << ","
                << hopTriangles[3 * i + 2] << "};\n";
    }
    f << "};\n";
    f.close();
}

bool colorFace(int index, int color, std::vector<int> & faceColors, int maxColor, std::vector<std::set<int>> & star)
{
  // std::cout << "Coloring " << index << " " << color << std::endl;
  if (index == star.size())
    return true;

  for (auto i: star[index]) {
    if (faceColors[i] == color)
      return false;
  }
  faceColors[index] = color;

  for (int c = 0; c < maxColor; c++) {
    if (colorFace(index+1, c, faceColors, maxColor, star))
      return true;
  }
  faceColors[index] = -1;
  return false;
}

bool greedyColorFace(int index, std::vector<int> & faceColors, int maxColor, std::vector<std::set<int>> & star)
{
  // std::cout << "Coloring " << index << " " << std::endl;
  if (index == star.size())
    return true;

  for (int c = 0; c < maxColor; c++) {
    bool sameColor = false;
    for (auto i: star[index]) {
      if (faceColors[i] == c) {
        sameColor = true;
        break;
      }
    }
    if (sameColor) continue;
    faceColors[index] = c;
    break;
  }
  if (faceColors[index] == -1)
    return false;

  return greedyColorFace(index+1, faceColors, maxColor, star);
}

bool colorFaces(PolyMesh *pm, std::map<int, int> & face2Colors, int maxColor)
{
  face2Colors.clear();
  for (size_t i = 0; i < pm->faces.size(); ++i) {
    auto it = face2Colors.find(pm->faces[i]->data);
    if (it == face2Colors.end())
      face2Colors[pm->faces[i]->data] = face2Colors.size();
  }
  std::vector<std::set<int>> star(face2Colors.size());
  for (size_t i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->hedges[i];
    if (he->opposite == nullptr) continue;
    if (he->f == nullptr || he->opposite->f == nullptr) Msg::Error("face not found");
    if (he->f->data == he->opposite->f->data) continue;
    star[face2Colors[he->f->data]].insert(face2Colors[he->opposite->f->data]);
    star[face2Colors[he->opposite->f->data]].insert(face2Colors[he->f->data]);
  }

  if (star.size() == 0) Msg::Error("face not found in polymesh");
  std::vector<int> faceColors(star.size(),-1);
  // if (!colorFace(0, 0, faceColors, maxColor, star))
  if (!greedyColorFace(0, faceColors, maxColor, star))
    return false;

  for (auto kv: face2Colors)
    face2Colors[kv.first] = faceColors[kv.second];
  return true;
}

void printCuttedMesh(PolyMesh *pm, std::map<int,int> colors)
{
  char name[256];
  snprintf(name, sizeof(name), "cutted.pos");
  std::ofstream f(name);
  if (!f) Msg::Error("Failed to open file: %s", name);
  f << "View \"P\"{\n";
  for (size_t i = 0; i < pm->faces.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->faces[i]->he;
    f << "ST(";
    for (int j = 0; j < 3; ++j) {
      f << he->v->position.x() << "," << he->v->position.y() << "," << he->v->position.z();
      if (j < 2)
        f << ",";
      he = he->next;
    }
    if (colors.size() == 0)
      f << "){" << pm->faces[i]->data << "," << pm->faces[i]->data << "," << pm->faces[i]->data << "};\n";
    else
      f << "){" << colors[pm->faces[i]->data] << "," << colors[pm->faces[i]->data] << "," << colors[pm->faces[i]->data] << "};\n";
  }
  f << "};\n";
  f.close();
}

bool highOrderPolyMesh::sanityCheck()
{
  //   SVector3 intersection;
  // for (auto it = edges.begin(); it != edges.end(); ++it) {
  //   std::vector<geodesic::SurfacePoint> path0;
  //   getPath(it->first, path0);
  //   // path0.erase(path0.begin());
  //   // path0.pop_back();
  //   for (auto itt = it; ++itt != edges.end(); ) {
  //     std::vector<geodesic::SurfacePoint> path1;
  //     getPath(itt->first, path1);
  //     if (intersectGeodesicPath(path0, path1, intersection)) {
  //       Msg::Info("Intersection between %d %d and %d %d", it->first.first, it->first.second, itt->first.first, itt->first.second);
  //       Msg::Info("Intersection at %g %g %g", intersection.x(), intersection.y(), intersection.z());
  //       Msg::Error("The geodesic mesh is incorrect, likely due to excessive decimation. Try reducing the decimation threshold by adjusting 'clmin' (currently %g).", 1);
  //     }
  //   }
  // }


  bool sane = true;
  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = i+1; j < points.size(); ++j) {
      if (abs(points[i].x() - points[j].x()) < 1.e-8 &&
          abs(points[i].y() - points[j].y()) < 1.e-8 &&
          abs(points[i].z() - points[j].z()) < 1.e-8) {
        Msg::Warning("Two points are too close: %d and %d", i, j);
        sane = false;
      }
    }
  }

  std::set<int> vertices;
  for (size_t i = 0; i < triangles.size(); ++i) {
    if (triangles[i] >= points.size()) {
      Msg::Warning("Triangle %lu has a vertex %d that does not exist", i, triangles[i]);
      sane = false;
    }
    vertices.insert(triangles[i]);
  }
  if (vertices.size() != points.size()) {
    Msg::Warning("Some vertices are not used in triangles");
    sane = false;
  }

  std::map<std::pair<int,int>, std::vector<int>> verifEdges;
  for (size_t i = 0; i < triangles.size(); i += 3) {
    for (int j = 0; j < 3; ++j) {
      std::pair<int,int> edge = {triangles[i+j], triangles[i+(j+1)%3]};
      if (edge.first > edge.second)
        std::swap(edge.first, edge.second);
      verifEdges[edge].push_back(i/3);
    }
  }

  if (edges.size() != verifEdges.size()) {
    Msg::Warning("Number of edges is %lu instead of %lu", edges.size(), verifEdges.size());
    sane = false;
  }
  for (auto kv: edges) {
    if (kv.second.size() != verifEdges[kv.first].size()) {
      Msg::Warning("Edge %d %d has %lu triangles instead of %lu", kv.first.first, kv.first.second, kv.second.size(), verifEdges[kv.first].size());
      sane = false;
    }
    for (auto i: kv.second) {
      auto it = std::find(verifEdges[kv.first].begin(), verifEdges[kv.first].end(), i);
      if (it == verifEdges[kv.first].end()) {
        Msg::Warning("Edge %d %d is not in triangle %d", kv.first.first, kv.first.second, i);
        sane = false;
      }
    }
  }

  for (size_t i = 0; i < triangles.size(); i += 3) {
    for (int j = 0; j < 3; ++j) {
      int i0 = triangles[i+j];
      int i1 = triangles[i+(j+1)%3];
      int i2 = triangles[i+(j+2)%3];
      std::vector<geodesic::SurfacePoint> p01, p20;
      getPath({i0, i1}, p01);
      getPath({i2, i0}, p20);
      SVector3 v01(getTrueCoords(p01[0]), getTrueCoords(p01[1]));
      SVector3 v02(getTrueCoords(p20[p20.size()-1]), getTrueCoords(p20[p20.size()-2]));
      SVector3 n = normal(i0);
      double angle = computeAngle(v01, v02, n);
      if (angle < 1e-10) {
        Msg::Warning("Angle %d %d %d is not positive (angle = %g)", i1, i0, i2, angle);
        sane = false;
      }
    }
  }
  // std::cout << std::endl;
  return sane;
}

int makeMeshGeodesic(GModel *gm)
{

  Msg::Info("Creating a Polymesh");
  PolyMesh *pm;
  GFace2PolyMesh((*gm->firstFace())->tag(), &pm);
  Msg::Info("Creating a Polymesh done -- %lu faces ", pm->faces.size());

  //    std::map<PolyMesh::Vertex*,SVector3> cogs,nrms;
  std::vector<size_t> tris;
  double threshold = CTX::instance()->mesh.lcMin != 0 ? CTX::instance()->mesh.lcMin : 0.1 * CTX::instance()->mesh.lcMax;
  {
    PolyMesh decimated(*pm);
    for (size_t i = 0; i < decimated.vertices.size(); ++i)
      decimated.vertices[i]->data = i;

    std::set<PolyMesh::Vertex *> keep;
    // while(decimated.decimateInOrder(CTX::instance()->mesh.lcMax) > 0) {};
    // while(decimated.decimateInOrder(.1 * CTX::instance()->mesh.lcMax, keep) > 0) {};
    while(decimated.decimate(threshold, keep) > 0) {};
    // while(decimated.collapseEdges(.3 * CTX::instance()->mesh.lcMax, keep) > 0) {};


    std::map<PolyMesh::Vertex *, double> nothing;
    print__("decimated.pos", &decimated, nothing);

    tris.resize(3*decimated.faces.size());
    for (size_t i = 0; i < decimated.faces.size(); ++i) {
      PolyMesh::HalfEdge *he = decimated.faces[i]->he;
      for (int j = 0; j < 3; ++j) {
        tris[3*i+j] = he->v->data;
        he = he->next;
      }
    }
  }


  Msg::Info("Creating a Geodesic Mesh");
  highOrderPolyMesh hop(pm, tris);

  hop.trueCoord = std::vector<SVector3>(hop.pm->vertices.size());
  hop.characLength = std::vector<double>(hop.pm->vertices.size());
  for (size_t i = 0; i < hop.pm->vertices.size(); ++i) {
    hop.trueCoord[i] = SVector3(hop.pm->vertices[i]->position);
    hop.characLength[i] = 1 * CTX::instance()->mesh.lcMax;
  }

  hop.createGeodesics();

  hop.printGeodesics("geodesics.pos");

  // saveIsoTriangles(0, hop.triangles, hop.points, hop.lcs);
  saveIsoTriangles(0, hop.triangles, hop.points);

  // hop.lcs = std::vector<double>(hop.points.size(), CTX::instance()->mesh.lcMax);
  std::set<size_t> keep;

  std::cout << "Begin adaptation:" << "\t\tTriangles: " << hop.triangles.size()/3 << std::endl;

  int nbrSwap = hop.swapEdges();
  // int nbrSwap = hop.intrinsicSwapEdges();
  std::cout << "Number of swaps: \t" << nbrSwap << "\tTriangles: " << hop.triangles.size()/3 << std::endl;

  hop.printGeodesics("geodesics_swapped.pos");
  // saveIsoTriangles(1, hop.triangles, hop.points, hop.lcs);
  saveIsoTriangles(1, hop.triangles, hop.points);
  bool sane = hop.sanityCheck();

  if (!sane)
    Msg::Error("The geodesic mesh is incorrect, likely due to excessive decimation. Try reducing the decimation threshold by adjusting 'clmin' (currently %g).", threshold);
  
  // SVector3 intersection;
  // for (auto it = hop.edges.begin(); it != hop.edges.end(); ++it) {
  //   std::vector<geodesic::SurfacePoint> path0;
  //   hop.getPath(it->first, path0);
  //   // path0.erase(path0.begin());
  //   // path0.pop_back();
  //   for (auto itt = it; ++itt != hop.edges.end(); ) {
  //     std::vector<geodesic::SurfacePoint> path1;
  //     hop.getPath(itt->first, path1);
  //     if (hop.intersectGeodesicPath(path0, path1, intersection)) {
  //       Msg::Info("Intersection between %d %d and %d %d", it->first.first, it->first.second, itt->first.first, itt->first.second);
  //       Msg::Info("Intersection at %g %g %g", intersection.x(), intersection.y(), intersection.z());
  //       Msg::Error("The geodesic mesh is incorrect, likely due to excessive decimation. Try reducing the decimation threshold by adjusting 'clmin' (currently %g).", threshold);
  //     }
  //   }
  // }


  int adapt = 10;
  // int adapt = 1;
  // int adapt = -1;
  int i = 0;
  for (; i < adapt; ++i) {

    int nbrSplit = hop.splitEdges(1.4, 0);
    // int nbrSplit = hop.splitEdges(1.4, M_PI/9);
    std::cout << "Number of split: \t" << nbrSplit << "\tTriangles: " << hop.triangles.size()/3 << std::endl;

      hop.printGeodesics("geodesics_splitted.pos");

    // Msg::Error("Force quit");


    // saveIsoTriangles(2, hop.triangles, hop.points, hop.lcs);
    saveIsoTriangles(2, hop.triangles, hop.points);
    // hop.sanityCheck();


    nbrSwap = hop.swapEdges();
    // nbrSwap = hop.intrinsicSwapEdges();
    std::cout << "Number of swaps: \t" << nbrSwap << "\tTriangles: " << hop.triangles.size()/3 << std::endl;

    // saveIsoTriangles(3, hop.triangles, hop.points, hop.lcs);
    saveIsoTriangles(3, hop.triangles, hop.points);
    // hop.sanityCheck();


    int nbrCollapse = hop.collapseEdges(.7, 0, keep);
    // int nbrCollapse = hop.intrinsicCollapseEdges(.7, 0, keep);
    // int nbrCollapse = hop.collapseEdges(.7, M_PI/9, keep);
    std::cout << "Number of collapse: \t" << nbrCollapse << "\tTriangles: " << hop.triangles.size()/3 << std::endl;
    std::cout << std::endl;

    // saveIsoTriangles(4, hop.triangles, hop.points, hop.lcs);
    saveIsoTriangles(4, hop.triangles, hop.points);
    // hop.sanityCheck();


    int nbrSwap = hop.swapEdges();
    // int nbrSwap = hop.intrinsicSwapEdges();
    std::cout << "Number of swaps: \t" << nbrSwap << "\tTriangles: " << hop.triangles.size()/3 << std::endl;

    // saveIsoTriangles(5, hop.triangles, hop.points, hop.lcs);
    saveIsoTriangles(5, hop.triangles, hop.points);
    // hop.sanityCheck();

    if (nbrSplit + nbrCollapse == 0) break;
  }


  hop.printGeodesics("geodesics_adapted.pos");
  std::cout << "Adaptation ended." << std::endl;

  if(0) {
    size_t NN = hop.triangles.size() / 3;
    for(size_t i = 0; i < NN; i++) {
      std::vector<geodesic::SurfacePoint> sp = hop.circumCenter(i);
      if(sp.empty()) sp = hop.circumCenter(i, 1.e22);
      if(!sp.empty()) hop.splitTriangle(i, sp[0]);
      char fn[245];
      sprintf(fn, "Split%ld.pos", i);
      hop.printGeodesics(fn);
    }
  }

  //  hop.printGeodesics("beforeall.pos");

  for(int k = 0; k < 0; k++) {
    //    int ns = 0;
    int ns = hop.splitEdges(.3);
    //    printf("nsplits %d\n",ns);
    int iter = 0, nswt = 0;
    while(1) {
      int nsw = hop.swapEdges(1);
      nswt += nsw;
      if(!nsw) break;
      if(iter++ > 10) break;
    }
    if(!ns) break;
    printf("%d splits %d swaps\n", ns, nswt);
  }
  //  hop.printGeodesics("afterall.pos");

  Msg::Info("Checking orientation");
  for(int K = 0; K < 1; K++) {
    std::vector<int> inverted;
    for(size_t i = 0; i < hop.triangles.size() / 3; i++) {
      double ori1 = hop.computeBoxProduct(hop.triangles[3 * i + 0],
                                          hop.triangles[3 * i + 1],
                                          hop.triangles[3 * i + 2]);
      double ori2 = hop.computeBoxProduct(hop.triangles[3 * i + 1],
                                          hop.triangles[3 * i + 2],
                                          hop.triangles[3 * i + 0]);
      double ori3 = hop.computeBoxProduct(hop.triangles[3 * i + 2],
                                          hop.triangles[3 * i + 0],
                                          hop.triangles[3 * i + 1]);
      if(ori1 < 0 || ori2 < 0 || ori3 < 0) {
        printf("Triangle %6ld --> %12.5E  %12.5E  %12.5E  \n", i, ori1, ori2,
               ori3);
        inverted.push_back(i);
      }
      //      std::vector<geodesic::SurfacePoint> sps = hop.circumCenter
      //      (i,1.e22); printf("Triangle %d --> %lu
      //      circumcenters\n",i,sps.size());
    }
    if(inverted.empty())
      Msg::Info("All %lu triangles are well oriented",
                hop.triangles.size() / 3);
    /*
        if (!inverted.empty()){
      Msg::Info("%lu inverted geodesic triangles have resisted swap -- splitting
    them",inverted.size()); for (auto t : inverted){
    std::vector<geodesic::SurfacePoint> sps = hop.circumCenter (t,1.e22);
    printf("Triangle %d --> %lu circumcenters\n",t,sps.size());
    for (auto sp : sps)
      if (hop.splitTriangle(t,sp) == 0)break;
      }
      hop.swapEdges(1);
      hop.swapEdges(1);
      hop.swapEdges(1);
      hop.swapEdges(1);
    }
    */
  }
  Msg::Info("Checking orientation Done");

  if (true) {
    std::vector<PolyMesh::Vertex *> pointVertices;
    PolyMesh *pm_new = hop.cutMesh(pointVertices);

    std::map<int,int> face2Colors;
    int c = 4;
    std::cout << "Trying to color with " << c << " colors." << std::endl;
    while (!colorFaces(pm_new, face2Colors, c)) {
      std::cout << "Coloring with " << c << " colors failed." << std::endl;
      c++;
      std::cout << "Trying to color with " << c << " colors." << std::endl;
    }
    printCuttedMesh(pm_new, face2Colors);

    hop.write(pm_new, pointVertices);
  }

  return 0;
}



// END FOR ARTHUR !!! --------------------------------------------------------

/*
class cutPolyMesh {
  PolyMesh *pm;
public :
  std::map<PolyMesh::HalfEdge *, std::vector<VertexOnEdge> > cuts;
  std::map<MVertex*, PolyMesh::Vertex *>  v2v;
  std::map<PolyMesh::Face *, std::vector<MVertex *> > fvs;
  std::map<MVertex *, std::vector<int> > vtags;
  std::map<PolyMesh::Vertex *, std::vector<int> > pvtags;

  cutPolyMesh (PolyMesh *_pm) : pm(_pm){
  }

  void addPolyMeshVertexTag(PolyMesh::Vertex * v, int tag){
    std::map<PolyMesh::Vertex *, std::vector<int> >::iterator it =
pvtags.find(v); if (it != pvtags.end()) it->second.push_back(tag); else {
      std::vector<int> tmp = {tag};
      pvtags[v] = tmp;
    }
  }

  void addVertexOnSurface (PolyMesh::Face*f,  MVertex *v){
    std::map<PolyMesh::Face *, std::vector<MVertex*> >::iterator it =
fvs.find(f); if (it != fvs.end()) it->second.push_back(v); else {
      std::vector<MVertex *> cut = {v};
      fvs[f] = cut;
    }
  }

  void addVertexOnEdge (PolyMesh::VertexOnSurface &vos,  MVertex *v){
    SVector3 p = vos.point();

    VertexOnEdge voe ; voe.he = vos.he; voe.t = vos.u; voe.tag = -1; voe.v = v;
    if (vos.he->opposite && voe.he->v->data > voe.he->next->v->data){
      voe.he = vos.he->opposite;
      voe.t = 1 - vos.u;
    }
    addEdgeCut (voe);
  }

  void addVertexOnVertex (PolyMesh::VertexOnSurface &vos,  MVertex *v){
    v2v[v] = vos.he->v;
  }

  void addTagToVertex (MVertex *v, int tag) {

    std::map<MVertex*, PolyMesh::Vertex *>::iterator itv2v = v2v.find(v);
    if (itv2v != v2v.end())addPolyMeshVertexTag (itv2v->second,tag);


    std::map<MVertex *, std::vector<int> >::iterator it = vtags.find(v);
    if (it != vtags.end() && std::find( it->second.begin(),  it->second.end(),
tag) ==  it->second.end()) it->second.push_back(tag); else { std::vector<int> vt
= {tag}; vtags[v] = vt;
    }
  }

  void addEdgeCut (const VertexOnEdge &voe){
    std::map<PolyMesh::HalfEdge *, std::vector<VertexOnEdge> >::iterator it =
cuts.find(voe.he); if (it == cuts.end()){ std::vector<VertexOnEdge> cut = {voe};
      cuts[voe.he] = cut;
    }
    else it->second.push_back(voe);
  }

  void stats(){
    for (auto it : cuts) printf("%d %d -->
%lu\n",it.first->v->data,it.first->next->v->data,it.second.size());
  }

  void addVertexOnEdges (int tag, std::vector<geodesic::SurfacePoint> &p){
    for (size_t i=1 ; i< p.size()-1 ; i++){
      geodesic::SurfacePoint _s = p[i];
      if (_s.type() == geodesic::EDGE){
    geodesic::Edge* pe = static_cast<geodesic::Edge*> (_s.base_element());
    geodesic::vertex_pointer v0 = pe->v0();
    geodesic::vertex_pointer v1 = pe->v1();
    // only add on edges from MIN to MAX !!!!
    PolyMesh::HalfEdge *he =
pm->getEdge(pm->vertices[std::min(v0->id(),v1->id())],pm->vertices[std::max(v0->id(),v1->id())]);
    if (!he) he =
pm->getEdge(pm->vertices[std::max(v0->id(),v1->id())],pm->vertices[std::min(v0->id(),v1->id())]);
    if (!he)Msg::Error("%s %d -- FAILURE",__FILE__,__LINE__);
    SPoint3 p0 (v0->x(),v0->y(),v0->z());
    SPoint3 p1 (_s.x(),_s.y(),_s.z());
    SVector3 d = p1 - p0;
    double l01 = d.norm();
    double l = he->l();
    VertexOnEdge voe ; voe.he = he; voe.t = l01/l; voe.tag = tag;
    addEdgeCut (voe);
      }
      else if (_s.type() == geodesic::VERTEX){
    // saddle point encountered
    geodesic::Vertex* pv = static_cast<geodesic::Vertex*> (_s.base_element());
    addPolyMeshVertexTag(pm->vertices[pv->id()], tag);
      }
      else printf("strange in %d --> %d %d for %lu
%lu\n",tag,_s.type()==geodesic::FACE, _s.type()==geodesic::VERTEX,i, p.size());
    }
  }

  void printFace (PolyMesh::Face *f,
          std::map<int,int> &ci, const char *c){

    printf("Printing %s\n",c);
    PolyMesh::HalfEdge *temp = f->he;
    printf("LOOP : ");
    do {
      std::map<int,int>::iterator itci = ci.find(temp->v->data);
      int yyy = itci == ci.end() ? -1 : itci->second;
      printf("(%d,%d) ",temp->v->data,yyy);
      temp = temp->next;
    }while (temp != f->he);
    printf("\n");
  }

  PolyMesh* cutMesh (){

    // ---  Compute local system of coordinates for every triangle

    size_t nbFaces = pm->faces.size();
    std::vector<SVector3> p0;
    std::vector<SVector3> t1;
    std::vector<SVector3> t2;
    std::vector<SVector3> ns;

    for (size_t i=0;i<nbFaces;i++){
      PolyMesh::HalfEdge *he = pm->faces[i]->he;
      p0.push_back(he->v->position);
      SVector3 _t1 = he->d();
      SVector3 _t2 = he->next->d();
      _t1.normalize();
      SVector3 _n  = crossprod(_t1,_t2);
      _t2 = crossprod(_n,_t1);
      _t2.normalize();
      p0.push_back(he->v->position);
      t1.push_back(_t1);
      t2.push_back(_t2);
      _n.normalize();
      ns.push_back(_n);
    }

    //    printf("coucouc3\n");


    FILE *f = fopen ("triangulate.pos","w");
    fprintf(f,"View \"\"{\n");

    FILE *f2 = fopen ("tags.pos","w");
    fprintf(f2,"View \"\"{\n");

    // ---  Cut every mesh edge with eventual additional points

    for (auto it : cuts){

      std::vector<VertexOnEdge> vv2 = it.second;
      std::sort(vv2.begin(),vv2.end(),compareVertexOnEdge);
      std::vector<VertexOnEdge> vv;
      std::vector<SVector3> pos;

      for (size_t k = 0 ;k < vv2.size() ; k++) {
    if (k == 0 || (vv2[k].t - vv[vv.size()-1].t) > 1.e-8){
      pos.push_back(vv2[k].point());
      vv.push_back(vv2[k]);
    }
    else {
      SVector3 P = vv2[k].point();
      Msg::Error("skipping on %d %d %22.15E %22.15E %22.15E (tags %d %d) k [%d
--> %d] pointer %p", it.first->v->data,it.first->next->v->data,
         P.x(),P.y(),P.z(),
         vv2[k].tag,vv[vv.size()-1].tag,k,vv2.size(),vv2[k].v);
      fprintf(f,"SP(%22.15E,%22.15E,%22.15E){0};\n",
          P.x(),P.y(),P.z());
    }
      }
      //    printf("coucouc221\n");

      fprintf(f,"SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E){%d,%d};\n",
          it.first->v->position.x(),
          it.first->v->position.y(),
          it.first->v->position.z(),
          it.first->next->v->position.x(),
          it.first->next->v->position.y(),
          it.first->next->v->position.z(),
          it.first->v->data,it.first->next->v->data);

      PolyMesh::HalfEdge *he = vv[0].he;
      for (size_t k = 0 ;k < vv.size() ; k++){
    VertexOnEdge voe = vv[k];
    pm->split_edge_general (he, pos[k]);
    he = he->next;
    if (voe.v){
      std::map<MVertex *, std::vector<int> >::iterator itvv = vtags.find(voe.v);
      if( itvv != vtags.end()){
        for (auto tt : itvv->second)addPolyMeshVertexTag(he->v, tt);
      }
    }
    else
      addPolyMeshVertexTag(he->v, voe.tag);
      }
    }

    // ---  Split every face taking into account constrained edges
    // ---  that belong to geodesic lines

    std::vector<size_t> tris;
    std::vector<size_t> bnds;

    for (size_t i=0;i<nbFaces;i++){
      std::vector<double> coord;
      std::vector<PolyMesh::Vertex*> pp;
      PolyMesh::HalfEdge *he = pm->faces[i]->he;


      do{
    SVector3 pos = he->v->position;
    double x = dot (pos-p0[i], t1[i]);
    double y = dot (pos-p0[i], t2[i]);
    coord.push_back(x);
    coord.push_back(y);
    pp.push_back( he->v );
    he = he->next;
      }while (he != pm->faces[i]->he);

      // Want to recover the boundary of the triangle
      std::vector<size_t> recover_all;
      for (size_t j=0;j<pp.size();j++){
    recover_all.push_back(j);
    recover_all.push_back((j+1)%pp.size());
      }

      // There exist internal points on the triangle
      std::map<PolyMesh::Face *, std::vector<MVertex *> >::iterator it =
fvs.find(pm->faces[i]); if (it != fvs.end()){ for (auto v : it->second){
      PolyMesh::Vertex *newv = new PolyMesh::Vertex
(v->x(),v->y(),v->z(),pm->vertices.size()); pm->vertices.push_back(newv);
      std::map<MVertex *, std::vector<int> >::iterator itt = vtags.find(v);
      if (itt != vtags.end()){
        pvtags[newv] = itt->second;
      }

      SVector3 pos = newv->position;
      double x = dot (pos-p0[i], t1[i]);
      double y = dot (pos-p0[i], t2[i]);
      coord.push_back(x);
      coord.push_back(y);
      pp.push_back( newv );
    }
      }

      // Some other edges should be recovered because they belong to geodesics

      std::vector<size_t> recover;

      for (size_t j = 0; j<pp.size() ; j++){
    PolyMesh::Vertex* vj = pp[j];
    std::map<PolyMesh::Vertex*,std::vector<int> >::iterator itj =
pvtags.find(vj); if (itj != pvtags.end()){ for (size_t k = j+1; k<pp.size() ;
k++){ PolyMesh::Vertex* vk = pp[k]; std::map<PolyMesh::Vertex*,std::vector<int>
>::iterator itk = pvtags.find(vk); if (itk != pvtags.end()){ for (auto tagj :
itj -> second) { if (tagj != -1 &&
std::find(itk->second.begin(),itk->second.end(),tagj) != itk->second.end()){
          recover.push_back(j);
          recover.push_back(k);
          recover_all.push_back(j);
          recover_all.push_back(k);
          bnds.push_back(vj->data);
          bnds.push_back(vk->data);
          bnds.push_back(tagj);

          fprintf(f2,"SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E){%d,%d};\n",
              vj->position.x(),vj->position.y(),vj->position.z(),
              vk->position.x(),vk->position.y(),vk->position.z(),
              tagj,tagj);
        }
          }
        }
      }
    }
      }

      if (pp.size() >= 3){
    std::vector<size_t> tri;
    meshTriangulate2d (coord,tri,recover_all.empty() ? nullptr : &recover_all);

    // verify if orientation is ok (it should be thet case ...)
    if (1){
      for (size_t j=0;j<tri.size(); j+=3){
        int n0 = tri[j]-1;
        int n1 = tri[j+1]-1;
        int n2 = tri[j+2]-1;
        PolyMesh::Vertex *j0 = pp[n0];
        PolyMesh::Vertex *j1 = pp[n1];
        PolyMesh::Vertex *j2 = pp[n2];
        SVector3 _t1 = j1->position - j0->position;
        SVector3 _t2 = j2->position - j0->position;
        SVector3 _n  = crossprod(_t1,_t2);
        double area = _n.norm();
        _n.normalize();
        double ps = dot(_n,ns[i]);
        if (area < 1.e-12){
          Msg::Warning("prodsca %12.5E %lu area %12.5E",ps,i,area);
          for (size_t k = 0; k<pp.size() ; k++){
        Msg::Warning("pt %d %lu %12.5E %12.5E
%12.5E",k,pp[k]->data,pp[k]->position.x(),
                 pp[k]->position.y(),pp[k]->position.z());
          }
        }
        if (ps < 0){
          size_t tmp = tri[j];
          tri[j] = tri[j+2];
          tri[j+2] = tmp;
        }
      }
    }

    for (size_t j=0;j<tri.size(); j+=3){
      int n0 = tri[j]-1;
      int n1 = tri[j+1]-1;
      int n2 = tri[j+2]-1;
      PolyMesh::Vertex *j0 = pp[n0];
      PolyMesh::Vertex *j1 = pp[n1];
      PolyMesh::Vertex *j2 = pp[n2];
      tris.push_back(j0->data);
      tris.push_back(j1->data);
      tris.push_back(j2->data);
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
          j0->position.x(),j0->position.y(),j0->position.z(),
          j1->position.x(),j1->position.y(),j1->position.z(),
          j2->position.x(),j2->position.y(),j2->position.z(),
          j0->data,j1->data,j2->data);
    }
      }
    }
    fprintf(f,"};\n");
    fclose(f);
    fprintf(f2,"};\n");
    fclose(f2);

    PolyMesh *pm_new = createPolyMesh (pm, tris, bnds);

    return pm_new;
  }
};


int makeMeshGeodesic (PolyMesh *pm, std::set<MEdge,MEdgeLessThan> &ed,
              std::map<MVertex*, int,MVertexPtrLessThan> *trianglePositions =
nullptr){

  {// print some stuff
    std::map<PolyMesh::Vertex*,double> gc;
    std::map<PolyMesh::Vertex*,double> num;
    for (auto v : pm->vertices){
      gc[v] = v->gaussianCurvature();
      num[v] = v->data;
    }
    print__ ("GaussianCurvature.pos", pm, gc);
    print__ ("Num.pos", pm, num);
  }

  char name [245];
  sprintf(name,"Geodesics.pos");
  FILE *f = fopen (name, "w");
  fprintf(f,"View \"Geodesics\" {\n");

  geodesic::Mesh mesh;
  std::map<PolyMesh::Face*,int> f2n;
  polyMeshToGeodesicMesh (pm, mesh, f2n);

  //  double D = 0.0;
  int counter = 0;

  std::vector<MEdge> tmp;
  tmp.insert(tmp.begin(),ed.begin(),ed.end());

  std::map<MVertex*,PolyMesh::VertexOnSurface> v2p;
  for (size_t i=0 ; i<tmp.size() ; i++){
    for (int j=0;j<2;j++){
      MVertex *v0 = j == 0 ? tmp[i].getMinVertex() : tmp[i].getMaxVertex() ;
      std::map<MVertex*,PolyMesh::VertexOnSurface>::iterator it = v2p.find(v0);
      int pos0 = -1;
      if (trianglePositions){
    auto it0 = trianglePositions->find(v0);
    if (it0 != trianglePositions->end())pos0 = it0->second;
      }
      if (it == v2p.end()){
    PolyMesh::VertexOnSurface vof =  findVertexOnSurface (pm, v0, pos0, true);
    int result = onBoundary (vof, 1.e-10, v0->onWhat()->dim());
    if (result == -1){
      // should be on a boundary and is not
      Msg::Error("Point %d classified on (%d %d) should be on the right
dimension entity of the background triangulation but is not",
             v0->getNum(),v0->onWhat()->tag(),v0->onWhat()->dim());
      debug_2 (v0,vof.he,"gasp.pos");
    }
    SVector3 v = vof.point();
    SVector3 d0 (v0->x(),v0->y(),v0->z());
    SVector3 dist  = v - d0;
    if (dist.norm() > 1.e-12)printf("error %22.15E\n",dist.norm());
    v2p[v0] = vof;
      }
    }
  }

  Msg::Info("found all %lu vertices",tmp.size());

  cutPolyMesh CPM (pm);

  // store vertices on faces
  for (auto it : v2p){
    MVertex *v = it.first;
    PolyMesh::VertexOnSurface vof = it.second;
    if (vof.dim == 2)
      CPM.addVertexOnSurface (vof.he->f, v);
    else if (vof.dim == 1)
      CPM.addVertexOnEdge (vof, v);
    else if (vof.dim == 0)
      CPM.addVertexOnVertex (vof, v);
  }

  size_t gCounter = 0;

  PolyMesh::VertexOnSurface _start;

  size_t i_start = 0;
  for (size_t i=1 ; i_start<tmp.size() ; i++){
    if (tmp[i].getMinVertex() == tmp[i_start].getMinVertex())continue;
    std::vector<PolyMesh::VertexOnSurface> _ends;
    std::vector<MEdge> _endsGmsh;
    _start = v2p[tmp[i_start].getMinVertex()];
    for (size_t j=i_start; j<i; j++){
      MVertex *v1 = tmp[j].getMaxVertex();
      PolyMesh::VertexOnSurface  _end = v2p[v1];
      _endsGmsh.push_back(tmp[j]);
      _ends.push_back(_end);
    }
    std::vector<std::vector<geodesic::SurfacePoint> > paths;
    exactGeodesics (_start, _ends, mesh, f2n, counter++, f, paths);

    for (size_t kk = 0 ; kk < paths.size() ; kk++){
      MEdge me = _endsGmsh[kk];
      CPM.addTagToVertex (me.getVertex(0),gCounter);
      CPM.addTagToVertex (me.getVertex(1),gCounter);
      CPM.addVertexOnEdges (gCounter++, paths[kk]);
    }
    i_start = i;
  }

  fprintf(f,"};\n");
  fclose(f);

  PolyMesh* pm_new = CPM.cutMesh ();
  std::map<PolyMesh::Vertex*,double> nothing;
  print__ ("toto.pos", pm_new, nothing);

  return 0;
}



int makeMeshGeodesic (GFace *gf) {

  discreteFace *df = static_cast<discreteFace *> (gf);
  if (!df)return -1;

  PolyMesh *pm = createPolyMesh (df);

  std::set<MEdge,MEdgeLessThan> ed;
  for (auto t : gf->triangles){
    ed.insert(t->getEdge(0));
    ed.insert(t->getEdge(1));
    ed.insert(t->getEdge(2));
  }

  makeMeshGeodesic (pm, ed);

  delete pm;
  return 0;
}


int makeMeshGeodesic (GModel *gm) {

  Msg::Info("Computing all Geodesics");
  highOrderPolyMesh hop (gm);

  //  return 0;

  {
    size_t NN = hop.triangles.size()/3;
    for (int i=0;i<NN;i++){
      if (0 && i == 76){
    geodesic::SurfacePoint sp = hop.circumCenter (i);
    if (sp.x() > 1.e10)sp = hop.circumCenter (i,1.e22);
    hop.splitTriangle (i, sp);
    char fn[245];
    sprintf(fn,"Split%d.pos",i);
    hop.printGeodesics(fn);
      }
    }
  }
  hop.printGeodesics("beforeall.pos");

  for (int k=0;k<1;k++){
    int ns = 0;
    //    int ns = hop.splitEdges ();
    //    printf("nsplits %d\n",ns);
    //    if (!ns) break;
    int iter=0, nswt=0;
    while(1){
      int nsw = hop.swapEdges(1);
      nswt += nsw;
      if (!nsw)break;
      if (iter++ > 10)break;
    }
    printf("%d splits %d swaps\n",ns,nswt);
  }
  hop.printGeodesics("afterall.pos");

  {
    printf("Cutting Mesh\n");
    PolyMesh *pm_new = hop.cutMesh();
    printf("Cutting Mesh Done\n");

    std::map<PolyMesh::Vertex*,double> nothing;
    print__ ("toto.pos", pm_new, nothing);
  }
  return 0;

  std::map<MVertex*, int, MVertexPtrLessThan> trianglePositions;
  PolyMesh *pm = createPolyMesh (gm,trianglePositions);
  std::set<MEdge,MEdgeLessThan> ed;
  for (GModel::fiter fit = gm->firstFace() ; fit != gm->lastFace(); fit++){
    discreteFace *df = static_cast<discreteFace *> (*fit);
    if (!df) continue;
    for (auto t : df->triangles){
      ed.insert(t->getEdge(0));
      ed.insert(t->getEdge(1));
      ed.insert(t->getEdge(2));
    }
  }
  //  printf("all done %lu edges\n",ed.size());
  makeMeshGeodesic (pm, ed, &trianglePositions);
  delete pm;
  return 0;
}

static void exactGeodesics (const PolyMesh::VertexOnSurface &_start,
                std::vector<PolyMesh::VertexOnSurface> &incident_edges,
                geodesic::Mesh &mesh, std::map<PolyMesh::Face*,int> &f2n,
                int save_, FILE *f,
                std::vector<std::vector<geodesic::SurfacePoint> > &paths){

  SVector3 p_start = _start.point();

  geodesic::face_pointer fp = &mesh.faces()[f2n[_start.he->f]];

  std::vector<geodesic::SurfacePoint> pts = {getSP (_start, fp)};

  std::vector<geodesic::SurfacePoint> _stop ;
  for (auto v : incident_edges){
    _stop.push_back(getSP(v,&mesh.faces()[f2n[v.he->f]]));
  }

  geodesic::GeodesicAlgorithmExact algorithm(&mesh);
  algorithm.propagate(pts,0,&_stop);
  for (auto v : incident_edges){
    SVector3 p_end = v.point();
    geodesic::SurfacePoint spe = getSP(v,&mesh.faces()[f2n[v.he->f]]);
    std::vector<geodesic::SurfacePoint> path;
    algorithm.trace_back(spe, path);
    filterPath (path, 1.e-6); // fixme use relative error
    if (f && path.size() > 1){
      for (size_t i = 0; i< path.size()-1;i++){
    fprintf(f,"SL(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E){%d,%d};\n",
        path[i].x(),path[i].y(),path[i].z(),
        path[i+1].x(),path[i+1].y(),path[i+1].z(),_start.he->v->data,_start.he->v->data);
      }
    }
    else{
      Msg::Error("Impossible to trace back -- ");
    }
    paths.push_back(path);
  }
}


static void debug_2 (MVertex *v, PolyMesh::HalfEdge *he, const char *fn){
  FILE *f = fopen(fn,"w");
  SVector3 p0 = he->v->position;
  SVector3 p1 = he->next->v->position;
  SVector3 p2 = he->next->next->v->position;
  fprintf(f,"View \"\"{\n");
  fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){0,1,2};\n",
      p0.x(),p0.y(),p0.z(),
      p1.x(),p1.y(),p1.z(),
      p2.x(),p2.y(),p2.z());
  fprintf(f,"SP(%g,%g,%g){-1};\n",
      v->x(),v->y(),v->z());
  fprintf(f,"};\n");
  fclose(f);
}

static PolyMesh* createPolyMesh (discreteFace *df) {
  const double eps = 1.e-8; //FIXME
  MVertexRTree pos(eps);

  PolyMesh *pm = new PolyMesh;

  //  printf("setting %lu indices to -1\n",df->_param.v3d.size());
  for(std::size_t i = 0; i < df->_param.v3d.size(); i++)
    df->_param.v3d[i].setIndex(-1);

  printf("unifyning %lu vertices\n",df->_param.v3d.size());
  int counter = 0;
  for(std::size_t i = 0; i < df->_param.t3d.size(); i++){
    for(std::size_t j = 0; j < 3; j++){
      MVertex *vv = pos.insert(df->_param.t3d[i].getVertex(j));
      if (!vv) vv = df->_param.t3d[i].getVertex(j);
      //      printf("%lu %lu %p\n",i,j,vv);
      if (vv->getIndex() == -1){
    pm->vertices.push_back(new PolyMesh::Vertex(vv->x(), vv->y(), vv->z(),
counter)); vv->setIndex(counter++);
      }
    }
  }
  //  printf("%lu vertices unified\n",pm->vertices.size());

  for(std::size_t i = 0; i < df->_param.t3d.size(); i++){
    PolyMesh::HalfEdge *he[3];
    for(std::size_t j = 0; j < 3; j++){
      PolyMesh::Vertex *vv =
pm->vertices[df->_param.t3d[i].getVertex(j)->getIndex()]; he[j] = new
PolyMesh::HalfEdge(vv); pm->hedges.push_back(he[j]); vv->he = he[j];
    }
    PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
    pm->faces.push_back(ff);
    for(int j = 0; j < 3; j++) {
      he[j]->next = he[(j + 1) % 3];
      he[j]->prev = he[(j - 1 + 3) % 3];
      he[j]->f = ff;
    }
  }
  //  printf("%lu faces created\n",pm->faces.size());

  HalfEdgePtrLessThan compare;
  std::sort(pm->hedges.begin(), pm->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(size_t i = 0; i < pm->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = pm->hedges[i];
    PolyMesh::HalfEdge *h1 = pm->hedges[i + 1];
    if(equal(h0, h1)) {
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
    }
  }
  return pm;
}

*/

#else

int makeMeshGeodesic(GModel *gm)
{
  Msg::Error("Geodesic meshing not available");
  return 0;
}

#endif
