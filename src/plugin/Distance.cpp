// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "OS.h"
#include "Distance.h"
#include "Context.h"
#include "Numeric.h"
#include <algorithm>
#include <array>

#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "distanceTerm.h"
#endif

GMSH_DistancePlugin::GMSH_DistancePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "PhysicalPoint", nullptr, 0., ""},
                     {GMSH_FULLRC, "PhysicalLine", nullptr, 0., ""},
                     {GMSH_FULLRC, "PhysicalSurface", nullptr, 0., ""},
                     {GMSH_FULLRC, "DistanceType", nullptr, 0, ""},
                     {GMSH_FULLRC, "MinScale", nullptr, 0, ""},
                     {GMSH_FULLRC, "MaxScale", nullptr, 0, ""}})
{
  _maxDim = 0;
  _data = nullptr;
}

template <class scalar> class simpleFunction;

std::string GMSH_DistancePlugin::getHelp() const
{
  return "Plugin(Distance) computes distances to entities in a mesh.\n\n"
         "If `PhysicalPoint', `PhysicalLine' and `PhysicalSurface' are 0, the "
         "distance is computed to all the boundaries. Otherwise the distance "
         "is computed to the given physical group.\n\n"
         "If `DistanceType' is 0, the plugin computes the geometrical "
         "Euclidean "
         "distance using the naive O(N^2) algorithm. If `DistanceType' > 0, "
         "the plugin computes an approximate distance by solving a PDE with "
         "a diffusion constant equal to `DistanceType' time the maximum size "
         "of the bounding box of the mesh as in [Legrand et al. 2006].\n\n"
         "Positive `MinScale' and `MaxScale' scale the distance function.\n\n"
         "Plugin(Distance) creates one new list-based view.";
}

namespace {
  // a piece of the entities the distance is computed to: a point, a segment
  // or a triangle (quadrangles are cut in two)
  struct Piece {
    int n;
    SPoint3 p[3];
    double center(int d) const
    {
      double c = 0.;
      for(int i = 0; i < n; i++) c += p[i][d] / n;
      return c;
    }
    // the unsigned distance to a point, 1e22 for degenerate triangles
    double distance(const SPoint3 &x) const
    {
      double d = 1.e22;
      SPoint3 cp;
      if(n == 1)
        d = x.distance(p[0]);
      else if(n == 2)
        signedDistancePointLine(p[0], p[1], x, d, cp);
      else
        signedDistancePointTriangle(p[0], p[1], p[2], x, d, cp);
      return std::abs(d);
    }
  };

  // a bounding volume hierarchy of the pieces, to find the closest to a
  // point without computing the distance to each
  class PieceTree {
  private:
    struct Node {
      double min[3], max[3];
      int left, right; // children, or -1 for a leaf
      int beg, end; // its pieces, in a leaf
    };
    std::vector<Piece> _pieces;
    std::vector<Node> _nodes;
    int _build(int beg, int end)
    {
      Node n;
      for(int d = 0; d < 3; d++) {
        n.min[d] = 1.e300;
        n.max[d] = -1.e300;
      }
      for(int i = beg; i < end; i++) {
        for(int j = 0; j < _pieces[i].n; j++) {
          for(int d = 0; d < 3; d++) {
            n.min[d] = std::min(n.min[d], _pieces[i].p[j][d]);
            n.max[d] = std::max(n.max[d], _pieces[i].p[j][d]);
          }
        }
      }
      n.left = n.right = -1;
      n.beg = beg;
      n.end = end;
      int index = _nodes.size();
      _nodes.push_back(n);
      if(end - beg > 4) { // split at the median along the longest side
        int d = 0;
        for(int k = 1; k < 3; k++)
          if(n.max[k] - n.min[k] > n.max[d] - n.min[d]) d = k;
        int mid = (beg + end) / 2;
        std::nth_element(_pieces.begin() + beg, _pieces.begin() + mid,
                         _pieces.begin() + end,
                         [d](const Piece &a, const Piece &b) {
                           return a.center(d) < b.center(d);
                         });
        int left = _build(beg, mid);
        int right = _build(mid, end);
        _nodes[index].left = left;
        _nodes[index].right = right;
      }
      return index;
    }
    double _boxDistance2(const Node &n, const SPoint3 &x) const
    {
      double d2 = 0.;
      for(int d = 0; d < 3; d++) {
        double e = std::max(0., std::max(n.min[d] - x[d], x[d] - n.max[d]));
        d2 += e * e;
      }
      return d2;
    }

  public:
    PieceTree(std::vector<Piece> &pieces) : _pieces(pieces)
    {
      if(_pieces.size()) _build(0, _pieces.size());
    }
    // the distance to the closest piece, 1e22 if there is none
    double closest(const SPoint3 &x) const
    {
      double best = 1.e22;
      if(_nodes.empty()) return best;
      std::vector<int> stack(1, 0);
      while(stack.size()) {
        const Node &n = _nodes[stack.back()];
        stack.pop_back();
        if(_boxDistance2(n, x) >= best * best) continue;
        if(n.left < 0) {
          for(int i = n.beg; i < n.end; i++)
            best = std::min(best, _pieces[i].distance(x));
          continue;
        }
        // the closer child last, to be visited first
        double dl = _boxDistance2(_nodes[n.left], x);
        double dr = _boxDistance2(_nodes[n.right], x);
        if(dl < dr) {
          stack.push_back(n.right);
          stack.push_back(n.left);
        }
        else {
          stack.push_back(n.left);
          stack.push_back(n.right);
        }
      }
      return best;
    }
  };
} // namespace

void GMSH_DistancePlugin::printView(std::vector<GEntity *> &entities,
                                    std::map<MVertex *, double> &distanceMap)
{
  double minScale = (double)option(4);
  double maxScale = (double)option(5);

  double minDist = 1.e22;
  double maxDist = 0.0;
  for(auto itv = distanceMap.begin(); itv != distanceMap.end(); ++itv) {
    double dist = itv->second;
    if(dist > maxDist) maxDist = dist;
    if(dist < minDist) minDist = dist;
    itv->second = dist;
  }

  for(std::size_t ii = 0; ii < entities.size(); ii++) {
    if(entities[ii]->dim() == _maxDim) {
      for(std::size_t i = 0; i < entities[ii]->getNumMeshElements(); i++) {
        MElement *e = entities[ii]->getMeshElement(i);
        std::size_t numNodes = e->getNumPrimaryVertices();
        if(e->getNumChildren())
          numNodes = e->getNumChildren() * e->getChild(0)->getNumVertices();
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        std::vector<double> *out =
          _data->incrementList(1, e->getType(), numNodes);
        if(!out) continue;
        std::vector<MVertex *> nods;

        if(!e->getNumChildren())
          for(std::size_t i = 0; i < numNodes; i++)
            nods.push_back(e->getVertex(i));
        else
          for(int i = 0; i < e->getNumChildren(); i++)
            for(std::size_t j = 0; j < e->getChild(i)->getNumVertices(); j++)
              nods.push_back(e->getChild(i)->getVertex(j));

        for(std::size_t nod = 0; nod < numNodes; nod++)
          out->push_back((nods[nod])->x());
        for(std::size_t nod = 0; nod < numNodes; nod++)
          out->push_back((nods[nod])->y());
        for(std::size_t nod = 0; nod < numNodes; nod++)
          out->push_back((nods[nod])->z());

        std::vector<double> dist;
        for(std::size_t j = 0; j < numNodes; j++) {
          MVertex *v = nods[j];
          auto it = distanceMap.find(v);
          dist.push_back(it != distanceMap.end() ? it->second : 0.);
        }

        for(std::size_t i = 0; i < dist.size(); i++) {
          if(minScale > 0 && maxScale > 0 && maxDist != minDist)
            dist[i] = minScale + ((dist[i] - minDist) / (maxDist - minDist)) *
                                   (maxScale - minScale);
          else if(minScale > 0)
            dist[i] = minScale + dist[i];
          out->push_back(dist[i]);
        }
      }
    }
  }
}

PView *GMSH_DistancePlugin::execute(PView *v)
{
  int id_point = (int)option(0);
  int id_line = (int)option(1);
  int id_face = (int)option(2);
  double type = (double)option(3);

  GModel *m = GModel::current();
  int totNumNodes = m->getNumMeshVertices();
  if(!totNumNodes) {
    Msg::Error("Plugin(Distance) needs a mesh");
    return v;
  }

  PView *view = new PView();
  _data = getDataList(view);

  _maxDim = m->getMeshDim();

  std::vector<GEntity *> entities;
  m->getEntities(entities);

  // the entities the distance is computed to: the boundaries (of highest
  // dimension) if no physical group is given, the groups given otherwise
  auto isTarget = [&](GEntity *ge) {
    int d = ge->dim();
    if(!id_point && !id_line && !id_face) return d == _maxDim - 1;
    for(int p : ge->getPhysicalEntities())
      if((p == id_point && d == 0) || (p == id_line && d == 1) ||
         (p == id_face && d == 2))
        return true;
    return false;
  };

  std::vector<SPoint3> pts(totNumNodes);
  std::vector<double> distances(totNumNodes, 1.e22);
  std::vector<MVertex *> pt2Vertex(totNumNodes);
  std::map<MVertex *, double> distanceMap;

  std::size_t k = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->mesh_vertices.size(); j++) {
      MVertex *v = ge->mesh_vertices[j];
      pts[k] = SPoint3(v->x(), v->y(), v->z());
      pt2Vertex[k] = v;
      distanceMap.insert(std::make_pair(v, 0.0));
      k++;
    }
  }

  if(type <= 0.0) { // Compute geometrical distance to mesh boundaries
    bool existEntity = false;
    std::vector<Piece> pieces;
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *g2 = entities[i];
      if(!isTarget(g2)) continue;
      existEntity = true;
      for(std::size_t k = 0; k < g2->getNumMeshElements(); k++) {
        MElement *e = g2->getMeshElement(k);
        std::vector<SPoint3> p(e->getNumPrimaryVertices());
        for(std::size_t i = 0; i < p.size(); i++)
          p[i] = e->getVertex(i)->point();
        if(e->getType() == TYPE_PNT)
          pieces.push_back({1, {p[0]}});
        else if(e->getType() == TYPE_LIN)
          pieces.push_back({2, {p[0], p[1]}});
        else if(e->getType() == TYPE_TRI)
          pieces.push_back({3, {p[0], p[1], p[2]}});
        else if(e->getType() == TYPE_QUA) {
          pieces.push_back({3, {p[0], p[1], p[2]}});
          pieces.push_back({3, {p[0], p[2], p[3]}});
        }
      }
    }
    PieceTree tree(pieces);
    int nthreads = CTX::instance()->numThreadsFor(pts.size(), 1000);
#pragma omp parallel for num_threads(nthreads) schedule(dynamic, 256)
    for(std::size_t kk = 0; kk < pts.size(); kk++)
      distances[kk] = tree.closest(pts[kk]);
    for(std::size_t kk = 0; kk < pts.size(); kk++)
      if(distances[kk] < 1.e22) distanceMap[pt2Vertex[kk]] = distances[kk];
    if(!existEntity) {
      if(id_point) Msg::Warning("Physical Point %d does not exist", id_point);
      if(id_line) Msg::Warning("Physical Curve %d does not exist", id_line);
      if(id_face) Msg::Warning("Physical Surface %d does not exist", id_face);
    }
    else {
      printView(entities, distanceMap);
    }
  }
  else { // Compute PDE for distance function
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
    linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
    linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif
    dofManager<double> *dofView = new dofManager<double>(lsys);

    bool existEntity = false;
    SBoundingBox3d bbox;
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      if(isTarget(ge)) {
        existEntity = true;
        for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
          MElement *t = ge->getMeshElement(i);
          for(std::size_t k = 0; k < t->getNumVertices(); k++) {
            MVertex *v = t->getVertex(k);
            dofView->fixVertex(v, 0, 1, 0.);
            bbox += SPoint3(v->x(), v->y(), v->z());
          }
        }
      }
    }
    if(!existEntity) {
      if(id_point) Msg::Warning("Physical Point %d does not exist", id_point);
      if(id_line) Msg::Warning("Physical Curve %d does not exist", id_line);
      if(id_face) Msg::Warning("Physical Surface %d does not exist", id_face);
    }
    else {
      std::vector<MElement *> allElems;
      for(std::size_t ii = 0; ii < entities.size(); ii++) {
        if(entities[ii]->dim() == _maxDim) {
          GEntity *ge = entities[ii];
          for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
            MElement *t = ge->getMeshElement(i);
            allElems.push_back(t);
            for(std::size_t k = 0; k < t->getNumVertices(); k++)
              dofView->numberVertex(t->getVertex(k), 0, 1);
          }
        }
      }
      double L = norm(SVector3(bbox.max(), bbox.min()));
      double mu = type * L;
      simpleFunction<double> DIFF(mu * mu), ONE(1.0);
      distanceTerm distance(GModel::current(), 1, &DIFF, &ONE);
      for(auto it = allElems.begin(); it != allElems.end(); it++) {
        SElement se((*it));
        distance.addToMatrix(*dofView, &se);
      }
      groupOfElements gr(allElems);
      distance.addToRightHandSide(*dofView, gr);
      lsys->systemSolve();
      for(auto itv = distanceMap.begin(); itv != distanceMap.end(); ++itv) {
        MVertex *v = itv->first;
        double value;
        dofView->getDofValue(v, 0, 1, value);
        value = std::min(0.9999, value);
        double dist = -mu * log(1. - value);
        itv->second = dist;
      }
      printView(entities, distanceMap);
    }
    delete lsys;
    delete dofView;
#endif
  }

  _data->setName("distance");
  _data->Time.push_back(0);
  _data->setFileName("distance.pos");
  _data->finalize();
  return view;
}
