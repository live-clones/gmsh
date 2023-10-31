#include "GmshConfig.h"

#if defined(HAVE_MESH) && defined(HAVE_GEODESIC)

#include "OS.h"
#include "Context.h"
#include "meshTriangulation.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertexRTree.h"
#include "robustPredicates.h"
#include "Numeric.h"

#include "geodesic_mesh.h"
#include "geodesic_algorithm_exact.h"
#include "graphColoringGreedy.h"
PolyMesh *createPolyMesh(const std::vector<double> &p,
                         const std::vector<size_t> &t,
                         const std::vector<size_t> &e = {},
                         const std::vector<size_t> &vertexNum = {})
{
  PolyMesh *pm_new = new PolyMesh;

  int cc = 0;
  for(size_t i = 0; i < p.size(); i += 3) {
    int tag = vertexNum.empty() ? i : vertexNum[i];
    pm_new->vertices.push_back(
      new PolyMesh::Vertex(p[i], p[i + 1], p[i + 2], tag));
  }
  for (size_t i=0;i<t.size();i+=3){
    if (t[i] == t[i+1] || t[i] == t[i+2] || t[i+1] == t[i+2]){
      Msg::Warning("triangle %d %d %d singular",t[i],t[i+1],t[i+2]);
      continue;
    }
    PolyMesh::HalfEdge *he[3];
    for(std::size_t j = 0; j < 3; j++) {
      PolyMesh::Vertex *vv = pm_new->vertices[t[i + j]];
      he[j] = new PolyMesh::HalfEdge(vv);
      pm_new->hedges.push_back(he[j]);
      vv->he = he[j];
    }
    PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
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
  for(size_t i = 0; i < pm_new->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = pm_new->hedges[i];
    PolyMesh::HalfEdge *h1 = pm_new->hedges[i + 1];
    if(equal(h0, h1)) {
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
      while (1){
	if (i+1 <  pm_new->hedges.size()){
	  PolyMesh::HalfEdge *h2 = pm_new->hedges[i + 1];
	  if (equal(h0, h2)){
	    h0->v->he = h0;
	    h1->v->he = h1;
	    Msg::Warning ("Non Manifold Triangulation edge %d %d appears more than 2 times!!",h0->v->data,h0->next->v->data);
	    i++;
	  }
	  else break;
	}
	else break;
      }
    }
  }

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

  Msg::Info("%d isogeometric triangles were generated", faceTag - 1);

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

static bool decimate(const std::vector<geodesic::SurfacePoint> &points,
                     std::vector<size_t> &triangles,
                     const double distanceThreshold)
{
  std::vector<double> p;
  for(auto sp : points) {
    p.push_back(sp.x());
    p.push_back(sp.y());
    p.push_back(sp.z());
  }
  PolyMesh *pm = createPolyMesh(p, triangles);

  pm->decimate(distanceThreshold);

  delete pm;

  return false;
}

static bool decimate(const std::vector<geodesic::SurfacePoint> &points,
                     std::vector<int> &triangles,
                     const double distanceThreshold)
{
  std::vector<size_t> t;
  for(auto x : triangles) t.push_back(x);
  decimate(points, t, distanceThreshold);
  triangles.clear();
  for(auto x : t) triangles.push_back(x);
}

/*-------------------------------------------------*/

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

static PolyMesh *
createPolyMesh(GModel *gm,
               std::map<MVertex *, int, MVertexPtrLessThan> &trianglePositions)
{
  const double eps = 1.e-8; // FIXME
  MVertexRTree pos(eps);
  PolyMesh *pm = new PolyMesh;

  int counter = 0;
  for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
    discreteFace *df = static_cast<discreteFace *>(*fit);
    if(!df) continue;
    for(std::size_t i = 0; i < df->_param.v3d.size(); i++)
      df->_param.v3d[i].setIndex(-1);
  }

  size_t faceCounter = 0;

  for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
    std::set<MVertex *> vs;
    for(auto t : (*fit)->triangles) {
      vs.insert(t->getVertex(0));
      vs.insert(t->getVertex(1));
      vs.insert(t->getVertex(2));
    }
    discreteFace *df = static_cast<discreteFace *>(*fit);
    //-------------------------------------------------------------
    for(auto _v : vs) {
      MFaceVertex *vk = dynamic_cast<MFaceVertex *>(_v);
      if(vk) {
        double u, v, uloc, vloc;
        vk->getParameter(0, u);
        vk->getParameter(1, v);
        int tp = df->trianglePosition(u, v, uloc, vloc);
        //	printf("face %d vertex %d param %g %g triangle position %d
        //parametric ? %d\n",
        //	       df->tag(),vk->getNum(),u,v,tp,vk->getParameter(0,u));
        trianglePositions[vk] = tp + faceCounter;
      }
      MEdgeVertex *ve = dynamic_cast<MEdgeVertex *>(_v);
      if(ve) {
        GEdge *ge = dynamic_cast<GEdge *>(ve->onWhat());
        if(ge) {
          double epar;
          ve->getParameter(0, epar);
          SPoint2 p2 = ge->reparamOnFace(df, epar, 0);
          double uloc, vloc;
          int tp = df->trianglePosition(p2.x(), p2.y(), uloc, vloc);
          trianglePositions[ve] = tp + faceCounter;
        }
      }
      if(!ve && !vk) { trianglePositions[_v] = -1; }
    }
    //-------------------------------------------------------------
    for(std::size_t i = 0; i < df->_param.t3d.size(); i++) {
      for(std::size_t j = 0; j < 3; j++) {
        MVertex *vv = pos.insert(df->_param.t3d[i].getVertex(j));
        if(!vv)
          vv = df->_param.t3d[i].getVertex(j);
        else
          df->_param.t3d[i].getVertex(j)->setIndex(vv->getIndex());
        //	else   printf("FOUND face %d t %lu v %lu %p\n",df->tag(),i,j,vv);
        if(vv->getIndex() == -1) {
          pm->vertices.push_back(
            new PolyMesh::Vertex(vv->x(), vv->y(), vv->z(), counter));
          vv->setIndex(counter++);
        }
      }
    }
    faceCounter += df->_param.t3d.size();
  }

  for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
    discreteFace *df = static_cast<discreteFace *>(*fit);
    if(!df) continue;
    for(std::size_t i = 0; i < df->_param.t3d.size(); i++) {
      PolyMesh::HalfEdge *he[3];
      for(std::size_t j = 0; j < 3; j++) {
        PolyMesh::Vertex *vv =
          pm->vertices[df->_param.t3d[i].getVertex(j)->getIndex()];
        he[j] = new PolyMesh::HalfEdge(vv);
        pm->hedges.push_back(he[j]);
        vv->he = he[j];
      }
      PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
      pm->faces.push_back(ff);
      for(int j = 0; j < 3; j++) {
        he[j]->next = he[(j + 1) % 3];
        he[j]->prev = he[(j - 1 + 3) % 3];
        he[j]->f = ff;
      }
    }
  }

  HalfEdgePtrLessThan compare;
  std::sort(pm->hedges.begin(), pm->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(int i = 0; i < pm->hedges.size() - 1; i++) {
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
  std::vector<geodesic::SurfacePoint> filtered_path;
  filtered_path.push_back(path[0]);
  for(size_t i = 1; i < path.size(); i++) {
    SVector3 dx(filtered_path[filtered_path.size() - 1].x() - path[i].x(),
                filtered_path[filtered_path.size() - 1].y() - path[i].y(),
                filtered_path[filtered_path.size() - 1].z() - path[i].z());
    if(dx.norm() > eps) { filtered_path.push_back(path[i]); }
    else {
      if(filtered_path[filtered_path.size() - 1].type() > path[i].type()) {
        printf("filtering %22.15E %22.15E %22.15E %d %22.15E %22.15E %22.15E "
               "%d %lu/%lu\n",
               filtered_path[filtered_path.size() - 1].x(),
               filtered_path[filtered_path.size() - 1].y(),
               filtered_path[filtered_path.size() - 1].z(),
               filtered_path[filtered_path.size() - 1].type(), path[i].x(),
               path[i].y(), path[i].z(), path[i].type(), i, path.size());
        //	filtered_path[filtered_path.size() - 1] = path[i];
      }
    }
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
  printf("coucou1 %lu %lu\n", _faces.size() / 3, _points.size() / 3);
  mesh.initialize_mesh_data(_points, _faces);
  printf("coucou2\n");
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

class highOrderPolyMesh {
  int maxTag;

public:
  PolyMesh *pm;
  geodesic::Mesh geoMesh; // geometric mesh
  std::vector<geodesic::SurfacePoint> points; // points of the IGA
  std::map<std::pair<int, int>, int> tags; // edge <a b>, triangles
  std::map<std::pair<int, int>, std::vector<size_t>>
    edges; // edge <a b>, triangles
  std::map<std::pair<int, int>, std::vector<geodesic::SurfacePoint>>
    geodesics; // one geodesic per edge
  std::vector<int> triangles; // 3 integers per triangle
  std::map<PolyMesh::Face *, int> f2n;
  std::map<PolyMesh::Vertex *, std::vector<int>> pvtags;
  //  std::map<PolyMesh::HalfEdge *, std::vector<VertexOnEdge> > cuts;
  std::map<PolyMesh::Face *, std::vector<int>> fvs;
  std::map<PolyMesh::HalfEdge *, std::vector<int>> evs;
  // detect intersecting geodesic @ saddle_points
  std::map<int, int> _saddle;

  // just for fun
  std::vector<int> computeColoring (){
    geeksforgeeks::Graph g (triangles.size()/3);
    for (auto it : edges){
      if (it.second.size() == 2){
	g.addEdge (it.second[0],it.second[1]);
      }
    }
    std::vector<int> result(triangles.size()/3);
    g.greedyColoring(result);
    return result;
  }
  
private:
  void createGeodesicsInParallel(std::vector<int> &__rows,
                                 std::vector<int> &__columns,
                                 std::vector<int> &__starts);
  int getTag(const std::pair<int, int> &e2)
  {
    std::pair<int, int> e = std::make_pair(std::min(e2.first, e2.second),
                                           std::max(e2.first, e2.second));
    auto it = tags.find(e);
    if(it == tags.end()) { tags[e] = maxTag++; }
    return tags[e];
  }

  SVector3 unit_normal(geodesic::Face *f)
  {
    geodesic::vertex_pointer v0 = f->adjacent_vertices()[0];
    geodesic::vertex_pointer v1 = f->adjacent_vertices()[1];
    geodesic::vertex_pointer v2 = f->adjacent_vertices()[2];
    SVector3 t0(v2->x() - v0->x(), v2->y() - v0->y(), v2->z() - v0->z());
    SVector3 t1(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
    SVector3 n = crossprod(t1, t0);
    n.normalize();
    return n;
  }

  SVector3 normal(int p)
  {
    geodesic::SurfacePoint &sp = points[p];

    SVector3 n(0, 0, 0);
    if(sp.type() == geodesic::FACE) { // point on a face (start of geodesic)
      geodesic::Face *pf = static_cast<geodesic::Face *>(sp.base_element());
      n = unit_normal(pf);
    }
    else {
      for(size_t i = 0; i < sp.base_element()->adjacent_faces().size(); i++) {
        geodesic::face_pointer f = sp.base_element()->adjacent_faces()[i];
        SVector3 ni = unit_normal(f);
        n += ni;
      }
      n.normalize();
    }
    //    SVector3 rr (sp.x()+0.2,sp.y()+0.1,sp.z());
    //    rr.normalize();
    //    printf("NORMAL(%6d,%2d,%lu)(%12.5E %12.5E %12.5E) = %12.5E %12.5E
    //    %12.5E
    //    \n",p,sp.type(),sp.base_element()->adjacent_faces().size(),rr.x(),rr.y(),rr.z(),n.x(),n.y(),n.z());

    return n;
  }

  double computeAngle(int p0, int p1, int p2)
  {
    std::vector<geodesic::SurfacePoint> p10, p12;
    createGeodesicPath(p1, p0, p10);
    createGeodesicPath(p1, p2, p12);
    SVector3 v10(p10[1].x() - p10[0].x(), p10[1].y() - p10[0].y(),
                 p10[1].z() - p10[0].z());
    SVector3 v12(p12[1].x() - p12[0].x(), p12[1].y() - p12[0].y(),
                 p12[1].z() - p12[0].z());
    return angle(v12, v10);
  }

  bool edgeValid(int p0, int p1, int p2, int p3)
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
    double a3 = computeAngleTrue(p0, p1, p2);
    double a4 = computeAngleTrue(p3, p1, p2);
    //    printf("%12.5E %12.5E -- %12.5E %12.5E
    //    \n",a1*180/M_PI,a2*180/M_PI,a1,a2-a1); if (a3 < 0) a3 += 2*M_PI; if
    //    (a4 < 0) a4 += 2*M_PI;

    if(a1 < a2) return true; // edge valid
    return false;
  }

  bool doWeSwap ( int p0, int p1, int p2, int p3, int onlyMisoriented ){

    double ori012 = computeBoxProduct (p0,p1,p2);
    double ori103 = computeBoxProduct (p1,p0,p3);

    if (ori012 > 0 && ori103 > 0 && onlyMisoriented)return false;

    double ori032 = computeBoxProduct (p0,p3,p2);
    double ori231 = computeBoxProduct (p2,p3,p1);
    
    if (ori012 < 0 || ori103 < 0){
      if (ori032 > 0 && ori231 > 0){
	printf("FORCING SWAP (creating 2 positive elements) %d %d %d %d : %g %g --> %g %g\n",p0,p1,p2,p3,ori012,ori103,ori032,ori231);
	return true;
      }
      else return false;
    }
    if(ori032 < 0 || ori231 < 0) return false;
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

  void addVertexOnSurface(PolyMesh::Face *f, int v)
  {
    std::map<PolyMesh::Face *, std::vector<int>>::iterator it = fvs.find(f);
    if(it != fvs.end())
      it->second.push_back(v);
    else {
      std::vector<int> cut = {v};
      fvs[f] = cut;
    }
  }

  void addVertexOnEdge(PolyMesh::HalfEdge *e, int v)
  {
    std::map<PolyMesh::HalfEdge *, std::vector<int>>::iterator it = evs.find(e);
    if(it != evs.end())
      it->second.push_back(v);
    else {
      std::vector<int> cut = {v};
      evs[e] = cut;
    }
  }

  void addPolyMeshVertexTag(PolyMesh::Vertex *v, int tag)
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

  void classifyGeodesic(std::pair<int, int> pair,
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

  void classifyGeodesicVertices()
  {
    std::set<int> pts;
    for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
      auto ite = edges.find(it->first);
      if(ite != edges.end() && ite->second.size()) {
        pts.insert(it->first.first);
        pts.insert(it->first.second);
      }
    }

    std::map<int, PolyMesh::Vertex *> i2pts;
    for(auto i : pts) {
      geodesic::SurfacePoint _s = points[i];
      //      printf("end point %lu geodesic vertex - %g %g %g - type
      //      %d\n",i,_s.x(),_s.y(),_s.z(),_s.type());
      if(_s.type() == geodesic::VERTEX) { // saddle vertex
        geodesic::Vertex *pv =
          static_cast<geodesic::Vertex *>(_s.base_element());
        i2pts[i] = pm->vertices[pv->id()];
      }
      else if(_s.type() == geodesic::FACE) {
        geodesic::Face *pf = static_cast<geodesic::Face *>(_s.base_element());
        PolyMesh::Vertex *newv =
          new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
        addVertexOnSurface(pm->faces[pf->id()], pm->vertices.size());
        pm->vertices.push_back(newv);
        i2pts[i] = newv;
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
          printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  argh : %d --- %g %g %g --> "
                 "%g %g %g\n",
                 i, he->v->position.x(), he->v->position.y(),
                 he->v->position.z(), he->next->v->position.x(),
                 he->next->v->position.y(), he->next->v->position.z());
        }
        PolyMesh::Vertex *newv =
          new PolyMesh::Vertex(_s.x(), _s.y(), _s.z(), pm->vertices.size());
        addVertexOnEdge(he, pm->vertices.size());
        pm->vertices.push_back(newv);
        i2pts[i] = newv;
      }
    }

    for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
      auto ite = edges.find(it->first);
      if(ite != edges.end() && ite->second.size()) {
        PolyMesh::Vertex *v0 = i2pts[it->first.first];
        PolyMesh::Vertex *v1 = i2pts[it->first.second];
        int tag = getTag(it->first);
        addPolyMeshVertexTag(v0, tag);
        addPolyMeshVertexTag(v1, tag);
      }
    }

    //    for (auto it : pvtags){
    //      printf("vertex %d -- tags",it.first->data);
    //      for (auto i : it.second)printf ("%d ",i);
    //      printf("\n");
    //    }

    for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
      auto ite = edges.find(it->first);
      if(ite != edges.end() && ite->second.size()) {
        classifyGeodesic(it->first, it->second);
      }
    }
  }

public:
  ///  std::map<int, std::map<int,double> > nodalDistances; // points --> distances to mesh vertices
  // MAIN FUNCTIONS ---- 
  highOrderPolyMesh (GModel *gm);
  PolyMesh *cutMesh ();  
  bool createGeodesicPath (int p0, int p1, std::vector<geodesic::SurfacePoint> &path);
  bool intersectGeodesicPath (std::vector<geodesic::SurfacePoint> &p0,
			      std::vector<geodesic::SurfacePoint> &p1,
			      SVector3 &intersection);

  int splitTriangle (size_t iTriangle, geodesic::SurfacePoint &sp);
  int swapEdge (const std::pair<int,int> &p01,
		const int onlyMisoriented, 
		std::pair<int,int> *p23 = nullptr);
  std::vector<geodesic::SurfacePoint> circumCenter (int iTriangle, double dist_max = 0);
  int splitEdge (const std::pair<int,int> &p01, double lTarget, double adimMin = 0.7, double adimMax = 1.4);
  double pathLength (const std::pair<int,int> &p01);

  // END MAIN FUNCTIONS ---- 
  
  void printGeodesics(const char *fn){
    FILE *f = fopen (fn,"w");
    fprintf(f,"View \"\"{\n");
    int count = 1;
    for(auto it = geodesics.begin(); it != geodesics.end(); ++it) {
      auto ite = edges.find(it->first);
      if (ite !=edges.end() && ite->second.size()){
		
	const size_t last = it->second.size() - 1;
	fprintf(f,"SP(%g,%g,%g){%d};\n",it->second[0].x(),it->second[0].y(),it->second[0].z(),it->first.first);	
	fprintf(f,"SP(%g,%g,%g){%d};\n",it->second[last].x(),it->second[last].y(),it->second[last].z(),it->first.second);	
	for (size_t i = 1; i < it->second.size() ; ++i){
	  fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",it->second[i-1].x(),it->second[i-1].y(),it->second[i-1].z(),
		  it->second[i].x(),it->second[i].y(),it->second[i].z(),ite->second[0],ite->second[0]);	
	}
	if (ite->second.size() == 2){
	  for (size_t i = 1; i < it->second.size() ; ++i){
	    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",it->second[i-1].x(),it->second[i-1].y(),it->second[i-1].z(),
		    it->second[i].x(),it->second[i].y(),it->second[i].z(),ite->second[1],ite->second[1]);	
	  }
	}
	count ++;
      }
    }
    fprintf(f, "};\n");
    fclose(f);
  }

  // Parallelizing edge swapping should be done
  // The only thiong to parallelize is to

  int swapEdges(int niter = 1, int onlyMisoriented = 1)
  {
    int countTot = 0;
    int iter = 0;

    while(1) {
      int count = 0;
      std::vector<std::pair<int,int> > eds;
      std::vector<std::pair<int,int> > eds_o;
      int nbInValid=0;
      for (auto it : edges) {
	if (it.second.size() > 1){
	  std::pair<int,int> opposite = std::make_pair(-1,-1);
	  swapEdge (it.first,onlyMisoriented, &opposite);
	  std::pair<int,int> opp = std::make_pair(std::min(opposite.first,opposite.second),
						  std::max(opposite.first,opposite.second));
	  if (opposite.second >=0){
	    if (!onlyMisoriented){
	      eds_o.push_back(opp);
	      eds.push_back(it.first);
	    }
	    else {
	      bool v = edgeValid (it.first.first,it.first.second,
				  opposite.first, opposite.second);
	      if (!v) {
		eds_o.push_back(opp);
		eds.push_back(it.first);
	      }	      
	      if (!v)nbInValid ++;
	    }
	  }
	}
      }
      /*
      Msg::Info("%lu edge invalid -- instersecing with all",eds.size());
      for (auto e_invalid : eds){
	int start_i = e_invalid.first;
	int end_i = e_invalid.second;
	Msg::Info("invalid -- %d %d",start_i, end_i);
	std::vector<geodesic::SurfacePoint> pe_invalid;
	createGeodesicPath (start_i, end_i,pe_invalid);
	for (auto it : edges) {
	  auto e = it.first;
	  int start = e.first;
	  int end = e.second;
	  if (it.second.size() == 2 &&
	      start_i != start &&
	      start_i != end &&
	      end_i != start&&
	      end_i != end){
	    std::vector<geodesic::SurfacePoint> pe;
	    createGeodesicPath (start, end,pe);
	    SVector3 intersection;
	    bool result = intersectGeodesicPath (pe_invalid, pe, intersection);
	    if (result)Msg::Warning ("intersection  %d %d X %d %d",
				     start, end, start_i, end_i);
	  }
	}
      }
      */
      
      std::sort(eds_o.begin(),eds_o.end());
      Msg::Info("%lu geodesics to be computed",eds_o.size());
      
      // -- OMP PARALLELISATION --- change map to CSR 
      std::vector<int> __rows;
      std::vector<int> __columns;
      std::vector<int> __starts;
      for(auto it = eds_o.begin(); it != eds_o.end(); ++it) {
        int row = it->first;
        int column = it->second;
        if(__rows.empty() || __rows[__rows.size() - 1] != row) {
          __starts.push_back(__columns.size());
          __rows.push_back(row);
        }
        __columns.push_back(column);
      }
      __starts.push_back(__columns.size());
      // --- END CSR FORMATTING

      createGeodesicsInParallel (__rows,__columns,__starts);
      
      for (auto it : eds) count += (swapEdge (it, onlyMisoriented,nullptr) == 0 ? 1 : 0);
      if (count == 0)break;
      Msg::Info("Swapping Edges -- iter %d -- %d swaps",iter,count);
      if (++iter >= niter)break;
      countTot += count;
    }
    Msg::Info("Swapping Edges -- %d iterations needed", iter);
    return countTot;
  }

  int splitEdges(double L)
  {
    int count = 0;
    std::vector<std::pair<int, int>> eds;
    for(auto it : edges) eds.push_back(it.first);
    for(auto it : eds) count += (splitEdge(it, L) == 0 ? 1 : 0);
    return count;
  }

  double computeAngleTrue(int p0, int p1, int p2)
  {
    std::vector<geodesic::SurfacePoint> p10, p12;
    createGeodesicPath(p1, p0, p10);
    createGeodesicPath(p1, p2, p12);
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

  double computeBoxProduct(int p0, int p1, int p2)
  {
    std::vector<geodesic::SurfacePoint> p10, p12;
    createGeodesicPath(p1, p0, p10);
    createGeodesicPath(p1, p2, p12);
    SVector3 v10(p10[1].x() - p10[0].x(), p10[1].y() - p10[0].y(),
                 p10[1].z() - p10[0].z());
    SVector3 v12(p12[1].x() - p12[0].x(), p12[1].y() - p12[0].y(),
                 p12[1].z() - p12[0].z());
    v10.normalize();
    v12.normalize();
    SVector3 n = normal(p1);
    return dot(n, crossprod(v12, v10));
  }
};

static int getNumThreads()
{
  int nthreads = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    nthreads = CTX::instance()->mesh.maxNumThreads3D;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  return nthreads;
}

void highOrderPolyMesh::createGeodesicsInParallel(std::vector<int> &__rows,
                                                  std::vector<int> &__columns,
                                                  std::vector<int> &__starts)
{
  double t1 = TimeOfDay();

  int nthreads = getNumThreads();

  Msg::Info("Computing geodesics using %d threads", nthreads);

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
    std::vector<std::pair<int,int> > pairs;
    for (size_t j=start; j<end;j++){
      auto p = std::make_pair(__rows[i],__columns[j]);
      if (geodesics.find(p) == geodesics.end()){
	pts_end.push_back(points[__columns[j]]);
	pairs.push_back(p);
      }
    }
    if (pairs.empty())continue;

    geodesic::GeodesicAlgorithmExact algorithm(&geoMesh);
    algorithm.propagate(pts_start, 0, &pts_end);
    for(size_t j = 0; j < pts_end.size(); j++) {
      std::vector<geodesic::SurfacePoint> path;
      algorithm.trace_back(pts_end[j], path);
      if (path.empty()){
	Msg::Info("propagation did not go far enough, widening the search");
	algorithm.propagate(pts_start,1.e22,&pts_end);
	algorithm.trace_back(pts_end[j], path);
      }      
      filterPath (path, 1.e-6); // fixme use relative error
      std::pair<int,int> inv = pairs[j];
      __geodesics[Msg::GetThreadNum()] [std::make_pair(inv.second,inv.first)] = path;
      std::reverse(path.begin(),path.end());
      __geodesics[Msg::GetThreadNum()] [pairs[j]] = path;
    }
  }    

  for (auto g : __geodesics) geodesics.insert(g.begin(), g.end());

  /*
  for (auto g : geodesics){
    int start = g.first.first;
    int end = g.first.second;
    geodesic::SurfacePoint ps = points[start];
    geodesic::SurfacePoint pe = points[end];
    SVector3 dir (pe.x()-ps.x(),pe.y()-ps.y(),pe.z()-ps.z());
    SVector3 dir2 (g.second[1].x()-g.second[0].x(),
		   g.second[1].y()-g.second[0].y(),
		   g.second[1].z()-g.second[0].z());
    if (dot(dir, dir2) > 0)
      Msg::Debug("geodesic beween %7d %7d -- sp %12.5E\n",
		 start, end, dot(dir, dir2));
    else 
      Msg::Warning("geodesic beween %7d %7d -- sp %12.5E\n",
		 start, end, dot(dir, dir2));
  }
  */  
  
  double t2 = TimeOfDay();

  Msg::Info("Time for computing Geodesics : %12.5E sec", t2 - t1);
}

// CONSTRUCTOR
highOrderPolyMesh::highOrderPolyMesh(GModel *gm) : maxTag(1)
{
  std::map<MVertex *, int, MVertexPtrLessThan> trianglePositions;

  int option = 2;

  Msg::Info("Creating a Polymesh");

  if(option == 1)
    pm = createPolyMesh(gm, trianglePositions);
  else {
    GFace2PolyMesh((*gm->firstFace())->tag(), &pm);
  }
  Msg::Info("Creating a Polymesh done -- %lu faces ",pm->faces.size());

  if (CTX::instance()->mesh.lcMin < 100){
    pm->decimate (CTX::instance()->mesh.lcMin);    
    std::map<PolyMesh::Vertex*,double> nothing;
    print__ ("decimated_orig.pos", pm, nothing);
  }
  
  polyMeshToGeodesicMesh (pm,geoMesh,f2n);
  
  if (option == 1){  
    Msg::Info("Computing positions of mesh points inside the geometric mesh");
    for(auto it = trianglePositions.begin(); it != trianglePositions.end();
        it++) {
      MVertex *v = it->first;
      int pos = it->second;
      geodesic::SurfacePoint gsp =
        MVertexToGeodesicSurfacePoint(v, pm, geoMesh, f2n, pos);
      v->setIndex(points.size());
      //    printf("vertex %d dim %d type %d %22.15E %22.15E %22.15E
      //    \n",v->getIndex(),v->onWhat()->dim(),gsp.type(),gsp.x(),gsp.y(),gsp.z());
      points.push_back(gsp);
    }

    for(GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
      discreteFace *df = static_cast<discreteFace *>(*fit);
      if(!df) continue;
      for(auto t : df->triangles) {
        for(size_t i = 0; i < 3; i++) {
          int i0 = t->getVertex(i)->getIndex();
          int i1 = t->getVertex((i + 1) % 3)->getIndex();
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
        triangles.push_back(t->getVertex(0)->getIndex());
        triangles.push_back(t->getVertex(1)->getIndex());
        triangles.push_back(t->getVertex(2)->getIndex());
      }
    }
  }
  else if(option == 2) {
    //    std::map<PolyMesh::Vertex*,SVector3> cogs,nrms;
    PolyMesh decimated(*pm);
    //    decimated.computeNormalsAndCentersOfGravity(cogs,nrms);
    while(decimated.decimate(CTX::instance()->mesh.lcMax) > 0) {};
    std::map<PolyMesh::Vertex *, double> nothing;
    print__("decimated.pos", &decimated, nothing);
    std::map<int, int> v2n;
    for(auto v : decimated.vertices) {
      geodesic::SurfacePoint gv = geodesic::SurfacePoint(
        &geoMesh.vertices()[v->data], v->position.x(), v->position.y(),
        v->position.z(), geodesic::VERTEX);
      v2n[v->data] = points.size();
      points.push_back(gv);
    }
    for(auto f : decimated.faces) {
      PolyMesh::Vertex *vs[3] = {f->he->v, f->he->next->v,
                                 f->he->next->next->v};
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

  // -- OMP PARALLELISATION --- change map to CSR
  std::vector<int> __rows;
  std::vector<int> __columns;
  std::vector<int> __starts;
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    int row = it->first.first;
    int column = it->first.second;
    if(__rows.empty() || __rows[__rows.size() - 1] != row) {
      __starts.push_back(__columns.size());
      __rows.push_back(row);
    }
    __columns.push_back(column);
  }
  __starts.push_back(__columns.size());
  // --- END CSR FORMATTING

  createGeodesicsInParallel(__rows, __columns, __starts);

  return;

#if 0
      std::map<PolyMesh::Vertex*, double> dist;
      for (size_t k=0;k<geoMesh.vertices().size(); k++){
	double d;
	geodesic::Vertex *v = &geoMesh.vertices()[k];
	geodesic::SurfacePoint sp (v);
	algorithm.best_source(sp,d);
	if (d < 1.e10)dist[pm->vertices[k]] = d;
      }
      char _name[256];
      sprintf(_name,"distanceToVertex%d.pos",e.first.first);
      print__ (_name, pm, dist);

#endif
}
// END CONSTRUCTOR

// CREATE GEODESIC PATH
bool highOrderPolyMesh::createGeodesicPath (int p0, int p1, std::vector<geodesic::SurfacePoint> &path){    
  std::pair<int,int> p    = std::make_pair(p0,p1);
  std::pair<int,int> pinv = std::make_pair(p1,p0);
  auto it    = geodesics.find(p);
  auto itinv = geodesics.find(pinv);
  if (it != geodesics.end()) {
    path = it->second;
    return false;
  }
  else if (itinv != geodesics.end()) {
    path = itinv->second;
    std::reverse (path.begin(),path.end());
    geodesics [p] = path;
    return false;
  }
  else {
    //    printf("geodesic %d %d must be computed\n",p0,p1);
    std::vector<geodesic::SurfacePoint> pts0 = {points[p0]};
    std::vector<geodesic::SurfacePoint> pts1 = {points[p1]};
    geodesic::GeodesicAlgorithmExact algorithm(&geoMesh);
    algorithm.propagate(pts0, 0, &pts1);
    algorithm.trace_back(pts1[0], path);
    if(path.empty()) {
      algorithm.propagate(pts0, 1.e22, &pts1);
      algorithm.trace_back(pts1[0], path);
    }
    filterPath (path, 1.e-6); // fixme use relative error
    geodesics [pinv] = path;
    std::reverse (path.begin(),path.end());
    geodesics [p] = path;
    return true;
  }
}
// END CREATE GEODESIC PATH

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
          return true;
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

  createGeodesicPath(p0, p1, p01);
  createGeodesicPath(p1, p2, p12);
  createGeodesicPath(p2, p0, p20);

  std::vector<geodesic::SurfacePoint> p03, p13, p23;

  createGeodesicPath(p0, p3, p03);
  createGeodesicPath(p1, p3, p13);
  createGeodesicPath(p2, p3, p23);

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
  createGeodesicPath(p0, p1, oldPath);
  createGeodesicPath(p2, p3, newPath);
  SVector3 intersection;
  if (  doWeSwap ( p0, p1, p2, p3, onlyMisoriented )/* && intersectGeodesicPath (oldPath, newPath,intersection)*/){
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
    geodesic::GeodesicAlgorithmExact algorithm(&geoMesh);
    algorithm.propagate(_start, dist_max, &_END);
    // algorithm.propagate(_start);

    for(size_t k = 0; k < geoMesh.vertices().size(); k++) {
      double d;
      geodesic::Vertex *v = &geoMesh.vertices()[k];
      geodesic::SurfacePoint sp(v);
      algorithm.best_source(sp, d);
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
  createGeodesicPath(p0, p1, oldPath);
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
  createGeodesicPath(p0, p1, oldPath);
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
  createGeodesicPath(p2, pmid, p2mid);
  //    double l2mid = pathLength (e2mid);
  // if (l2mid/lTarget < adimMin) return -3
  createGeodesicPath(pmid, p3, pmid3);
  //    double lmid3 = pathLength (e3mid);
  // if (lmid3/lTarget < adimMin) return -3

  // FIXME I have them already ...
  createGeodesicPath(p0, pmid, p0mid);
  createGeodesicPath(pmid, p1, pmid1);

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
// END SPLIT EDGE

PolyMesh *highOrderPolyMesh::cutMesh()
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
  classifyGeodesicVertices();
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

int makeMeshGeodesic(GModel *gm)
{
  Msg::Info("Creating a Geodesic Mesh");

  highOrderPolyMesh hop (gm);
  
  std::vector<int> coloring = hop.computeColoring ();
  
  hop.printGeodesics("geodesics.pos");

  for (int i=0;i<hop.triangles.size()/3;i++){
    double ori1 = hop.computeBoxProduct(hop.triangles[3*i+0],hop.triangles[3*i+1],hop.triangles[3*i+2]);
    double ori2 = hop.computeBoxProduct(hop.triangles[3*i+1],hop.triangles[3*i+2],hop.triangles[3*i+0]);
    double ori3 = hop.computeBoxProduct(hop.triangles[3*i+2],hop.triangles[3*i+0],hop.triangles[3*i+1]);
    if (ori1 < 0 || ori2 < 0 || ori3 < 0) {
      printf("Before swap Triangle %6d --> %12.5E  %12.5E  %12.5E  \n",i,ori1,ori2,ori3);
    }
  }
  
  Msg::Info("Swapping Edges");

  hop.swapEdges(8,1);

  Msg::Info("Swapping Edges Done");

  hop.printGeodesics("geodesics_swapped.pos");

  hop.swapEdges(2,0);
  
  //  hop.printGeodesics("geodesics_improved.pos");

  if (0){
    size_t NN = hop.triangles.size()/3;
    for (int i=0;i<NN;i++){
      std::vector<geodesic::SurfacePoint> sp = hop.circumCenter (i);
      if (sp.empty())sp = hop.circumCenter (i,1.e22);
      if (!sp.empty())hop.splitTriangle (i, sp[0]);
      //      char fn[245];
      //      sprintf(fn,"Split%d.pos",i);
      //      hop.printGeodesics(fn);
    }
    hop.printGeodesics("geodesics_after_del.pos");
  }

  for (int k=0;k<0;k++){
    //    int ns = 0;
    int ns = hop.splitEdges (4);
    //    printf("nsplits %d\n",ns);
    int iter=0, nswt=0;
    while(1){
      int nsw = hop.swapEdges(1,0);
      nswt += nsw;
      if (!nsw)break;
      if (iter++ > 2)break;
    }
    if(!ns) break;
    printf("%d splits %d swaps\n", ns, nswt);
  }
  hop.printGeodesics("afterall.pos");

  Msg::Info("Checking orientation");
  for(int K = 0; K < 1; K++) {
    std::vector<int> inverted;
    for(int i = 0; i < hop.triangles.size() / 3; i++) {
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
        printf("Triangle %6d --> %12.5E  %12.5E  %12.5E  \n", i, ori1, ori2,
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
      hop.swapEdges();
      hop.swapEdges();
      hop.swapEdges();
      hop.swapEdges();
    }
    */
  }
  Msg::Info("Checking orientation Done");

  {
    PolyMesh *pm_new = hop.cutMesh();
    std::map<PolyMesh::Vertex*,double> nothing;
    for (auto t : pm_new->faces)t->data = coloring[t->data];
    print__ ("toto.pos", pm_new, nothing);
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
      int nsw = hop.swapEdges();
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

#endif
