#include "meshRelaying.h"

#include "GModel.h"
#include "MLine.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "qualityMeasures.h"
#include "queue"

#if defined(HAVE_WINSLOWUNTANGLER)
#include "meshSurfaceUntangling.h"
#include "meshVolumeUntangling.h"
#include "winslowUntangler.h"
#endif

discreteFront *discreteFront::_instance = nullptr;
meshRelaying *meshRelaying::_instance = nullptr;

using vec2 = std::array<double, 2>;
inline vec2 operator-(const vec2 &a, const vec2 &b)
{
  return {{a[0] - b[0], a[1] - b[1]}};
}
inline vec2 operator+(const vec2 &a, const vec2 &b)
{
  return {{a[0] + b[0], a[1] + b[1]}};
}
inline vec2 operator*(const double &a, const vec2 &b)
{
  return {{a * b[0], a * b[1]}};
}
inline vec2 operator*(const vec2 &a, const double &b)
{
  return {{a[0] * b, a[1] * b}};
}

inline double triangle_area_2d(vec2 a, vec2 b, vec2 c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

// meshRelaying functions

meshRelaying::meshRelaying(GModel *gm)
{
  if(!gm) gm = GModel::current();

  _RATIO = 1.0;
  _distMax = 1.0;

  std::set<MVertex *, MVertexPtrLessThan> vs;

  // Get all vertices.
  for(auto eit = gm->firstEdge(); eit != gm->lastEdge(); ++eit) {
    for(auto e : (*eit)->lines) {
      for(size_t i = 0; i < 2; i++) vs.insert(e->getVertex(i));
    }
  }
  for(auto fit = gm->firstFace(); fit != gm->lastFace(); ++fit) {
    for(auto t : (*fit)->triangles) {
      for(size_t i = 0; i < 3; i++) vs.insert(t->getVertex(i));
    }
  }
  for(auto git = gm->firstRegion(); git != gm->lastRegion(); ++git) {
    for(auto t : (*git)->tetrahedra) {
      for(size_t i = 0; i < 4; i++) vs.insert(t->getVertex(i));
    }
  }

  // Store positions
  size_t counter = 0;
  for(auto v : vs) {
    v->setIndex(counter++);
    pos.push_back(v->x());
    pos.push_back(v->y());
    pos.push_back(v->z());
    dimVertex.push_back(v->onWhat()->dim());
  }

  v2v.resize(counter);
  v2tet.resize(counter);
  v2tri.resize(counter);
  v2edg.resize(counter);

  size_t tetCount = 0;
  for(auto git = gm->firstRegion(); git != gm->lastRegion(); ++git) {
    for(auto t : (*git)->tetrahedra) {
      for(size_t i = 0; i < 6; i++) {
        MEdge e = t->getEdge(i);
        v2v[e.getVertex(0)->getIndex()].push_back(e.getVertex(1)->getIndex());
        v2v[e.getVertex(1)->getIndex()].push_back(e.getVertex(0)->getIndex());
      }
      for(size_t i = 0; i < 4; i++) {
        tets.push_back(t->getVertex(i)->getIndex());
        v2tet[t->getVertex(i)->getIndex()].push_back(tetCount);
      }
      tetCount++;
    }
  }

  size_t triCount = 0;
  for(auto fit = gm->firstFace(); fit != gm->lastFace(); ++fit) {
    for(auto t : (*fit)->triangles) {
      for(size_t i = 0; i < 3; i++) {
        MEdge e = t->getEdge(i);
        v2v[e.getVertex(0)->getIndex()].push_back(e.getVertex(1)->getIndex());
        v2v[e.getVertex(1)->getIndex()].push_back(e.getVertex(0)->getIndex());
        if(tetCount) {
          std::pair<size_t, size_t> p = std::make_pair(
            std::min(e.getVertex(0)->getIndex(), e.getVertex(1)->getIndex()),
            std::max(e.getVertex(0)->getIndex(), e.getVertex(1)->getIndex()));
          bnd2d.push_back(p);
        }
      }
      for(size_t i = 0; i < 3; i++) {
        tris.push_back(t->getVertex(i)->getIndex());
        v2tri[t->getVertex(i)->getIndex()].push_back(triCount);
      }
      triCount++;
    }
  }

  size_t edgCount = 0;
  for(auto eit = gm->firstEdge(); eit != gm->lastEdge(); ++eit) {
    for(auto e : (*eit)->lines) {
      if(triCount) {
        std::pair<size_t, size_t> p = std::make_pair(
          std::min(e->getVertex(0)->getIndex(), e->getVertex(1)->getIndex()),
          std::max(e->getVertex(0)->getIndex(), e->getVertex(1)->getIndex()));
        bnd1d.push_back(p);
      }
      for(size_t i = 0; i < 2; i++) {
        edgs.push_back(e->getVertex(i)->getIndex());
        v2edg[e->getVertex(i)->getIndex()].push_back(edgCount);
      }
      edgCount++;
    }
  }

  {
    std::sort(bnd2d.begin(), bnd2d.end());
    auto last = std::unique(bnd2d.begin(), bnd2d.end());
    bnd2d.erase(last, bnd2d.end());
  }
  {
    std::sort(bnd1d.begin(), bnd1d.end());
    auto last = std::unique(bnd1d.begin(), bnd1d.end());
    bnd1d.erase(last, bnd1d.end());
  }
  {
    size_t count = 0;
    for(auto v : v2v) {
      std::sort(v.begin(), v.end());
      auto last = std::unique(v.begin(), v.end());
      v.erase(last, v.end());
      v2v[count++] = v;
    }
  }
  initial_pos = pos;
}

// interface relaying functions

void meshRelaying::doRelaying(double relax)
{
  auto f_levelset = [this](size_t i, size_t j)
    -> std::vector<std::pair<double, std::pair<size_t, size_t>>> {
    std::vector<std::pair<double, std::pair<size_t, size_t>>> ds;
    for(size_t k = 0; k < levelsets.size(); k++) {
      double l0 = levelsets[k][i];
      double l1 = levelsets[k][j];
      if(l0 * l1 < 0) {
        double t = l0 / (l0 - l1);
        std::pair<double, std::pair<size_t, size_t>> d =
          std::make_pair(t, std::make_pair(k, k));
        ds.push_back(d);
      }
    }
    std::sort(ds.begin(), ds.end());
    return ds;
  };

  auto f_discrete = [this](size_t i, size_t j)
    -> std::vector<std::pair<double, std::pair<size_t, size_t>>> {
    SVector3 p0(pos[3 * i], pos[3 * i + 1], pos[3 * i + 2]);
    SVector3 p1(pos[3 * j], pos[3 * j + 1], pos[3 * j + 2]);

    std::vector<double> d;
    std::vector<int> c;
    discreteFront::instance()->intersectLine2d(p0, p1, d, c);

    std::vector<std::pair<double, std::pair<size_t, size_t>>> ds;
    for(size_t i = 0; i < d.size(); i++) {
      std::pair<double, std::pair<size_t, size_t>> p =
        std::make_pair(d[i], std::make_pair(c[2 * i], c[2 * i + 1]));
      ds.push_back(p);
    }
    std::sort(ds.begin(), ds.end());
    return ds;
  };

  // if no discreteFront is available, use levelset
  if(discreteFront::instance()->empty()){
    doRelaying(f_levelset);
  }
  else {
    // pos = initial_pos;
    // relax position
    for(size_t i = 0; i < pos.size() / 3; i++) {
      pos[3 * i] = (1 - relax) * pos[3 * i] + relax * initial_pos[3 * i];
      pos[3 * i + 1] =
        (1 - relax) * pos[3 * i + 1] + relax * initial_pos[3 * i + 1];
      pos[3 * i + 2] = 0.0;
    }
    doRelaying(f_discrete);
  }

  if(pm_mesh == nullptr){
    pm_mesh = new PolyMesh();
    std::vector<size_t> tris_p1;
    for(size_t i=0; i<tris.size(); i++) {
      tris_p1.push_back(tris[i]+1);
    }
    std::vector<double> pos_2d;
    for(size_t i=0; i<pos.size(); i+=3) {
      pos_2d.push_back(pos[i]);
      pos_2d.push_back(pos[i+1]);
    }
    triangulation2PolyMesh(tris_p1, pos_2d, &pm_mesh);
    
    //sort vertices
    std::sort(pm_mesh->vertices.begin(), pm_mesh->vertices.end(), [](PolyMesh::Vertex *a, PolyMesh::Vertex *b) {
      return a->data < b->data;
    });
  }

  for(size_t i=0; i<pm_mesh->vertices.size(); i++) {
    int v = pm_mesh->vertices[i]->data-1;
    SVector3 p(pos[3*v], pos[3*v+1], pos[3*v+2]);
    pm_mesh->vertices[i]->position = p;
  }
}

void meshRelaying::doRelaying(
  const std::function<std::vector<std::pair<double, std::pair<size_t, size_t>>>(
    size_t, size_t)> &f)
{
  front_nodes.clear();
  discreteFront::instance()->clearFrontNodes();
  discreteFront::instance()->buildSpatialSearchStructure();

  std::vector<int> bnd_markers;
  discreteFront::instance()->getBndMarkers(&bnd_markers);
  std::vector<interface> interfaces = discreteFront::instance()->getInterfaces();

  int MAXIT = 5;
  int ITTT = 0;

  std::vector<size_t> marker_corner_done;
  corners.clear();
  while(true) {
    
    if(ITTT++ == MAXIT) break;

    if(tets.empty() && ITTT == 1) {
      for(size_t i = 0; i < tris.size(); i += 3) {
        
        std::vector<SVector3> cornerPos;
        std::vector<std::pair<size_t, size_t>> corner;
        discreteFront::instance()->cornersInTriangle2d(
          SVector3(pos[3 * tris[i]], pos[3 * tris[i] + 1],
                   pos[3 * tris[i] + 2]),
          SVector3(pos[3 * tris[i + 1]], pos[3 * tris[i + 1] + 1],
                   pos[3 * tris[i + 1] + 2]),
          SVector3(pos[3 * tris[i + 2]], pos[3 * tris[i + 2] + 1],
                   pos[3 * tris[i + 2] + 2]),
          cornerPos, corner);
        if(!corner.empty()) {
          if(std::find(marker_corner_done.begin(), marker_corner_done.end(),
                       corner[0].second) != marker_corner_done.end()) {
            continue;
          }
          for(int j = 0; j < 3; j++) {
            int dimEdge = tets.size() ? 3 : 2;
            int dimi = dimVertex[tris[i + j]];
            if(dimi < dimEdge) continue;
            size_t m_ = tris[i+j];
            double qMin = smallest_measure(m_, cornerPos[0]);
            if(qMin > 0) {
              pos[3 * m_] = cornerPos[0].x();
              pos[3 * m_ + 1] = cornerPos[0].y();
              pos[3 * m_ + 2] = 0.0;

              front_nodes.push_back(m_);
              discreteFront::instance()->addFrontNode(
                m_, corner[0].first, corner[0].second,
                corner[0].second, cornerPos[0], interfaces[corner[0].first].markers);
              corners.push_back(m_);
              marker_corner_done.push_back(corner[0].second);
              break;
            }
          }
        }
      }

     
      for(size_t i = 0; i < tris.size(); i += 3) {
        std::vector<size_t> interface_id;
        std::vector<size_t> m;
        std::vector<SVector3> p_triple;
        discreteFront::instance()->tripleInTriangle2d(
          SVector3(pos[3 * tris[i]], pos[3 * tris[i] + 1],
                   pos[3 * tris[i] + 2]),
          SVector3(pos[3 * tris[i + 1]], pos[3 * tris[i + 1] + 1],
                   pos[3 * tris[i + 1] + 2]),
          SVector3(pos[3 * tris[i + 2]], pos[3 * tris[i + 2] + 1],
                   pos[3 * tris[i + 2] + 2]),
          m, p_triple);
        if(!p_triple.empty()) {
          for(int j = 0; j < 3; j++) {
            int dimi = dimVertex[tris[i + j]];
            if(dimi < 1) continue;

            double qMin = smallest_measure(tris[i + j], p_triple[0]);
            if(qMin > 0) {
              pos[3 * tris[i + j]] = p_triple[0].x();
              pos[3 * tris[i + j] + 1] = p_triple[0].y();
              front_nodes.push_back(tris[i + j]);
              break;
            }
          }
        }
      }
    }

    std::sort(front_nodes.begin(), front_nodes.end());
    std::sort(corners.begin(), corners.end());
    std::set<std::pair<size_t, size_t>> cuts;
    std::vector<edgeCut> moves;

    for(size_t i = 0; i < v2v.size(); i++) {
      for(auto j : v2v[i]) {
        if(i < j) {
          std::pair<size_t, size_t> pa = std::make_pair(i, j);

          std::vector<std::pair<double, std::pair<size_t, size_t>>> ds =
            f(i, j);
          if(ds.empty()) continue;

          std::pair<size_t, size_t> p =
            std::make_pair(std::min(i, j), std::max(i, j));
          cuts.insert(p);

          size_t indexi = 0;
          size_t indexj = ds.size() - 1;

          const double di = ds[indexi].first;
          const double dj = ds[indexj].first;
          const size_t m1i = ds[indexi].second.first;
          const size_t m2i = ds[indexi].second.second;
          const size_t m1j = ds[indexj].second.first;
          const size_t m2j = ds[indexj].second.second;
          int dimEdge = tets.size() ? 3 : 2;
          if(std::binary_search(bnd2d.begin(), bnd2d.end(), p))
            dimEdge = std::min(dimEdge, 2);

          if(std::binary_search(bnd1d.begin(), bnd1d.end(), p))
            dimEdge = std::min(dimEdge, 1);

          int dimi = dimVertex[i];
          int dimj = dimVertex[j];
          SVector3 pi(pos[3 * i], pos[3 * i + 1], pos[3 * i + 2]);
          SVector3 pj(pos[3 * j], pos[3 * j + 1], pos[3 * j + 2]);
          SVector3 pOpti = pi + (pj - pi) * di;
          SVector3 pOptj = pi + (pj - pi) * dj;
          SVector3 DI = pi - pOpti;
          SVector3 DJ = pj - pOptj;

          int interface_i_ = discreteFront::instance()->findMarker(m1i);
          int interface_j_ = discreteFront::instance()->findMarker(m1j);
	  if (!discreteFront::instance()->empty())
	    if(interface_i_==-1 || interface_j_==-1) continue;

          size_t interface_i = static_cast<size_t>(interface_i_);
          size_t interface_j = static_cast<size_t>(interface_j_);
          
          edgeCut mi(i, j, pOpti, DI.norm(), interface_i, m1i, m2i);
          edgeCut mj(j, i, pOptj, DJ.norm(), interface_j, m1j, m2j);

          if(!std::binary_search(front_nodes.begin(), front_nodes.end(), i)) {
            if(di > 0.0000001 && di < 0.999999 && dimi >= dimEdge) {
              if(discreteFront::instance()->empty() || bnd_markers[m1i]==0 || bnd_markers[m2i]==0) {
                moves.push_back(mi);
              }
            }
          }

          if(!std::binary_search(front_nodes.begin(), front_nodes.end(), j)) {
            if(dj > 0.0000001 && dj < 0.999999 && dimj >= dimEdge) {
              if(discreteFront::instance()->empty() || bnd_markers[m1j]==0 || bnd_markers[m2j]==0) {
                moves.push_back(mj);
              }
            }
          }
        }
      }
    }

    if(moves.empty()) break;

    std::sort(moves.begin(), moves.end());
    for(auto c : moves) {
      size_t i = c.a;
      size_t j = c.b;
      std::pair<size_t, size_t> p =
        std::make_pair(std::min(i, j), std::max(i, j));
      if(cuts.find(p) == cuts.end()) continue;

      SVector3 pOpt = c.p;
      double qMin = smallest_measure(i, pOpt);
      if(qMin <= 0) continue;

      for(auto k : v2v[i]) {
        p = std::make_pair(std::min(i, k), std::max(i, k));
        cuts.erase(p);
      }

      if(levelsets.size()) { levelsets[c.m1][i] = 0.0; }

      front_nodes.push_back(i);
      double posP[2] = {pOpt.x(), pOpt.y()};

      if (!discreteFront::instance()->empty())
	discreteFront::instance()->addFrontNode(i, c.interface, c.m1, c.m2, pOpt,interfaces[c.interface].markers);
      pos[3 * i] = pOpt.x();
      pos[3 * i + 1] = pOpt.y();
      pos[3 * i + 2] = pOpt.z();
    }
    std::sort(front_nodes.begin(), front_nodes.end());
  }
}

double meshRelaying::smallest_measure(const size_t n, const SVector3 &t)
{
  double volume = 1.e22;
  if(tets.size()) {
    for(auto tri : v2tet[n]) {
      size_t n0 = tets[4 * tri];
      size_t n1 = tets[4 * tri + 1];
      size_t n2 = tets[4 * tri + 2];
      size_t n3 = tets[4 * tri + 3];
      double x0 = n0 == n ? t.x() : pos[3 * n0];
      double y0 = n0 == n ? t.y() : pos[3 * n0 + 1];
      double z0 = n0 == n ? t.z() : pos[3 * n0 + 2];
      double x1 = n1 == n ? t.x() : pos[3 * n1];
      double y1 = n1 == n ? t.y() : pos[3 * n1 + 1];
      double z1 = n1 == n ? t.z() : pos[3 * n1 + 2];
      double x2 = n2 == n ? t.x() : pos[3 * n2];
      double y2 = n2 == n ? t.y() : pos[3 * n2 + 1];
      double z2 = n2 == n ? t.z() : pos[3 * n2 + 2];
      double x3 = n3 == n ? t.x() : pos[3 * n3];
      double y3 = n3 == n ? t.y() : pos[3 * n3 + 1];
      double z3 = n3 == n ? t.z() : pos[3 * n3 + 2];
      double p0[3] = {x0, y0, z0};
      double p1[3] = {x1, y1, z1};
      double p2[3] = {x2, y2, z2};
      double p3[3] = {x3, y3, z3};
      double v = robustPredicates::orient3d(p0, p1, p2, p3);
      volume = std::min(v, volume);
    }
  }
  else if(tris.size()) {
    for(auto tri : v2tri[n]) {
      size_t n0 = tris[3 * tri];
      size_t n1 = tris[3 * tri + 1];
      size_t n2 = tris[3 * tri + 2];
      double x0 = n0 == n ? t.x() : pos[3 * n0];
      double y0 = n0 == n ? t.y() : pos[3 * n0 + 1];
      double x1 = n1 == n ? t.x() : pos[3 * n1];
      double y1 = n1 == n ? t.y() : pos[3 * n1 + 1];
      double x2 = n2 == n ? t.x() : pos[3 * n2];
      double y2 = n2 == n ? t.y() : pos[3 * n2 + 1];
      double p0[2] = {x0, y0};
      double p1[2] = {x1, y1};
      double p2[2] = {x2, y2};
      double v = robustPredicates::orient2d(p0, p1, p2);
      volume = std::min(v, volume);
    }
  }
  return volume;
}

void meshRelaying::curvatureFromMarkers(std::vector<int> concentration_list,
                                        std::vector<double> tension_table,
                                        std::vector<int> concentration,
                                        std::vector<double> *curvature)
{
  curvature->resize(tris.size(), 0.0);
  std::vector<double> markers_curvature;
  discreteFront::instance()->markersCurvature(concentration_list, tension_table,
                                              &markers_curvature);

  std::vector<double> marker_pos = discreteFront::instance()->getPos();

  std::vector<double> node_curvature(v2v.size(), 0.0);
  std::vector<int> map;
  map.resize(v2v.size(), -1);
  std::vector<frontNode> fns = discreteFront::instance()->getFn();
  for(size_t i = 0; i < fns.size(); i++) map[fns[i].meshNode] = i;

  for(size_t i = 0; i < map.size(); ++i) {
    if(map[i] == -1) continue;
    frontNode fn = fns[map[i]];
    size_t v = fn.meshNode;
    size_t m1 = fn.m1;
    size_t m2 = fn.m2;
    if(m1 == m2) { node_curvature[v] = markers_curvature[m1]; }
    else {
      double c1 = markers_curvature[m1];
      double c2 = markers_curvature[m2];
      double d1 = sqrt((marker_pos[3 * m1] - pos[3 * v]) *
                  (marker_pos[3 * m1] - pos[3 * v]) +
                  (marker_pos[3 * m1 + 1] - pos[3 * v + 1]) *
                  (marker_pos[3 * m1 + 1] - pos[3 * v + 1]));

      double d2 = sqrt((marker_pos[3 * m2] - pos[3 * v]) *
                  (marker_pos[3 * m2] - pos[3 * v]) +
                  (marker_pos[3 * m2 + 1] - pos[3 * v + 1]) *
                  (marker_pos[3 * m2 + 1] - pos[3 * v + 1]));
      
      double t = d1 / (d1 + d2);
      node_curvature[v] = t * c2 + (1.0 - t) * c1;
    }
  }

  std::vector<int> node_dominant_color(v2v.size(), 11);
  for(size_t i = 0; i < tris.size(); ++i) {
    for(size_t j = 0; j < 3; ++j) {
      if(node_dominant_color[tris[i + j]] > concentration[i / 3]) {
        node_dominant_color[tris[i + j]] = concentration[i / 3];
      }
    }
  }
  for(size_t i = 0; i < tris.size(); i += 3) {
    for(size_t j = 0; j < 3; j++) {
      if(node_dominant_color[tris[i + j]] == concentration[i / 3]) {
        (*curvature)[i + j] = node_curvature[tris[i + j]];
      }
    }
  }
}

void meshRelaying::curvatureFromConcentration(std::vector<double>*curvature){
  curvature->resize(tris.size(), 0.0);
  std::vector<double> nodes_curvature(v2v.size(), 0.0);
  std::vector<int> node_dominant_color(v2v.size(), 0);
  for(size_t i = 0; i < pm_mesh->vertices.size(); i++) {
    size_t id = pm_mesh->vertices[i]->data;
    PolyMesh::Vertex *v = pm_mesh->vertices[i];
    PolyMesh::HalfEdge *he = v->he;
    PolyMesh::HalfEdge *bndhe = nullptr;
    std::vector<int> colors;
    do{
      colors.push_back(he->f->data);
      if(he->opposite == nullptr) {
        bndhe = he;
        break;
      }
      he = he->opposite->next;
    }while(he != v->he);
    if(bndhe != nullptr) continue; // skip triple points for now

    
    std::sort(colors.begin(), colors.end());
    auto last = std::unique(colors.begin(), colors.end());
    colors.erase(last, colors.end());
    
    if(colors.size() == 0){
      continue;
    } 

    int dominant_color = colors[0];
    node_dominant_color[id-1] = dominant_color;

    if(colors.size()==1) continue;
    
    he = v->he;
    double pos0[3] = {0, 0, 0};
    double pos1[3] = {v->position[0], v->position[1], 0};
    double pos2[3] = {0, 0, 0};
    do{
      if(he->f->data != he->opposite->f->data) {
        if(he->f->data == dominant_color) {
          pos2[0] = he->opposite->v->position[0];
          pos2[1] = he->opposite->v->position[1];
          pos2[2] = 0;
        } else {
          pos0[0] = he->opposite->v->position[0];
          pos0[1] = he->opposite->v->position[1];
          pos0[2] = 0;
        }
      }
      he = he->opposite->next;
    }while(he!=v->he);

    // compute curvature circle
    double a = pos1[0] - pos0[0];
    double b = pos1[1] - pos0[1];
    double c = pos2[0] - pos0[0];
    double d = pos2[1] - pos0[1];
    double e = a * (pos0[0] + pos1[0]) + b * (pos0[1] + pos1[1]);
    double f = c * (pos0[0] + pos2[0]) + d * (pos0[1] + pos2[1]);
    double g = 2.0 * (a * (pos2[1] - pos1[1]) - b * (pos2[0] - pos1[0]));
    if(g > 1e-10) {
      double x = (d * e - b * f) / g;
      double y = (a * f - c * e) / g;
      double r = sqrt((x - pos0[0]) * (x - pos0[0]) + (y - pos0[1]) * (y - pos0[1]));
      nodes_curvature[id-1] = 1.0 / r;
    } else {
      nodes_curvature[id-1] = 0.0;
    }

  }

  for(size_t i = 0; i < tris.size()/3; ++i) {
    for(size_t j = 0; j < 3; j++) {
      if(node_dominant_color[tris[3*i + j]] == tris_concentration[i]) {
        (*curvature)[3*i + j] = nodes_curvature[tris[3*i + j]];
      }
    }
  }

}

void meshRelaying::concentration(std::vector<int> *concentration)
{

  if(pm_mesh == nullptr) {
    pm_mesh = new PolyMesh();
    std::vector<size_t> tris_p1;
    for(size_t i=0; i<tris.size(); i++) {
      tris_p1.push_back(tris[i]+1);
    }
    std::vector<double> pos_2d;
    for(size_t i=0; i<pos.size(); i+=3) {
      pos_2d.push_back(pos[i]);
      pos_2d.push_back(pos[i+1]);
    }
    triangulation2PolyMesh(tris_p1, pos_2d, &pm_mesh);
    
    //sort vertices
    std::sort(pm_mesh->vertices.begin(), pm_mesh->vertices.end(), [](PolyMesh::Vertex *a, PolyMesh::Vertex *b) {
      return a->data < b->data;
    });

  } else {
    // update position
    for(size_t i=0; i<pm_mesh->vertices.size(); ++i){
      pm_mesh->vertices[i]->position = SVector3(pos[3 * (pm_mesh->vertices[i]->data-1)],
                                                pos[3 * (pm_mesh->vertices[i]->data-1) + 1],
                                                pos[3 * (pm_mesh->vertices[i]->data-1) + 2]);
    }
  }

  concentration->resize(tris.size() / 3, 0);
  tris_concentration.resize(tris.size() / 3, 0);
  PolyMesh **pm = discreteFront::instance()->getPm();
  for(size_t i = 0; i < tris.size() / 3; i++) {
    double center[3] = {0.0, 0.0, 0.0};
    for(int j = 0; j < 3; j++) {
      center[0] += pos[3 * tris[3 * i + j]] / 3.0;
      center[1] += pos[3 * tris[3 * i + j] + 1] / 3.0;
      center[2] += pos[3 * tris[3 * i + j] + 2] / 3.0;
    }
    PolyMesh::Face *f = (*pm)->walk_from(center, (*pm)->faces[10]);
    if(f) {
      (*concentration)[i] = f->data;
      tris_concentration[i] = f->data;
    }
  }

  for(size_t i=0; i<pm_mesh->faces.size(); i++) {
    pm_mesh->faces[i]->data = tris_concentration[i];
  }
}

void meshRelaying::concentration_bfs(std::vector<int> *concentration){
  concentration->resize(tris.size() / 3, 0);
  tris_concentration.resize(tris.size() / 3, 0);
  if(pm_mesh == nullptr) {
    pm_mesh = new PolyMesh();
    std::vector<size_t> tris_p1;
    for(size_t i=0; i<tris.size(); i++) {
      tris_p1.push_back(tris[i]+1);
    }
    std::vector<double> pos_2d;
    for(size_t i=0; i<pos.size(); i+=3) {
      pos_2d.push_back(pos[i]);
      pos_2d.push_back(pos[i+1]);
    }
    triangulation2PolyMesh(tris_p1, pos_2d, &pm_mesh);
    
    //sort vertices
    std::sort(pm_mesh->vertices.begin(), pm_mesh->vertices.end(), [](PolyMesh::Vertex *a, PolyMesh::Vertex *b) {
      return a->data < b->data;
    });

  } else {
    // update position
    for(size_t i=0; i<pm_mesh->vertices.size(); ++i){
      pm_mesh->vertices[i]->position = SVector3(pos[3 * (pm_mesh->vertices[i]->data-1)],
                                                pos[3 * (pm_mesh->vertices[i]->data-1) + 1],
                                                pos[3 * (pm_mesh->vertices[i]->data-1) + 2]);
    }
  }

  PolyMesh **pm = discreteFront::instance()->getPm();

  int debug = 0;
  // generate front edges 
  std::vector<frontNode> fns = discreteFront::instance()->getFn();
  std::vector<std::vector<frontNode>> fn_interfaces;
  for(size_t i = 0; i < fns.size(); i++) {
    size_t interface = fns[i].interface;
    if(fn_interfaces.size() <= interface) {
      fn_interfaces.resize(interface + 1);
    }
    fn_interfaces[interface].push_back(fns[i]);
  }


  std::vector<std::pair<size_t, size_t>> front_edges;
  for(size_t i=0; i<fn_interfaces.size(); i++) {
    std::sort(fn_interfaces[i].begin(), fn_interfaces[i].end());
    for(size_t j=0; j<fn_interfaces[i].size(); j++) {
      size_t n = fn_interfaces[i].size();
      size_t n1 = fn_interfaces[i][j].meshNode;
      size_t n2 = fn_interfaces[i][(j+1)%n].meshNode;
      front_edges.push_back(std::make_pair(std::min(n1,n2), std::max(n1,n2)));
    }
  }

  for(size_t i=0; i<pm_mesh->hedges.size(); i++) {
    pm_mesh->hedges[i]->data = 0;
  }

  for(size_t i=0; i<front_edges.size(); i++) {
    PolyMesh::HalfEdge *front_he = pm_mesh->getEdge(pm_mesh->vertices[front_edges[i].first], pm_mesh->vertices[front_edges[i].second]);
    if(front_he == nullptr) {
      printf("front_he is nullptr : %lu - %lu \n", front_edges[i].first, front_edges[i].second);
      printf("data = %d - %d \n", pm_mesh->vertices[front_edges[i].first]->data, pm_mesh->vertices[front_edges[i].second]->data);
      continue;
    }
    front_he->data = 5;

    if(front_he->opposite != nullptr) {
      front_he->opposite->data = 5;
    }
  }


  for(size_t i=0; i<pm_mesh->faces.size(); i++) {
    pm_mesh->faces[i]->data = -10;
  }

  std::queue<PolyMesh::Face*> q;
  while(true){
    int id = -1;
    for(size_t i=0; i<pm_mesh->faces.size(); i++) {
      if(pm_mesh->faces[i]->data == -10) {
        id = i;
        break;
      }
    }
    if(id == -1) break;
    
    
    // find starting triangle
    while(true){
      if(id == -1 || id>= pm_mesh->faces.size()) break;
      // test if good starting point
      if(pm_mesh->faces[id]->data != -10) {
        id++;
        continue;
      }
      int start_concentration = full_concentration_triangle(id);
      if(start_concentration != -10) {
        q.push(pm_mesh->faces[id]);
        pm_mesh->faces[id]->data = start_concentration;
        break;
      }
      id++;
    }
    if(id == -1 || id>= pm_mesh->faces.size()) break;

    //color triangles bfs
    while(!q.empty()){
      PolyMesh::Face *f = q.front();
      q.pop();
      PolyMesh::HalfEdge *he = f->he;
      for(size_t i=0; i<3; i++) {
        if(he->opposite == nullptr) {
          he = he->next;
          continue;
        }
        if(he->data == 5){
          he = he->next;
          continue;
        }
        
        PolyMesh::Face *f2 = he->opposite->f;
        if(f2->data == -10) {
          f2->data = f->data;

          q.push(f2);
        }
        he = he->next;
      }
      
    }
    debug++;
  }

  // finish coloring triangles if remaining for robustness
  for(size_t i=0; i<pm_mesh->faces.size(); i++) {
    if(pm_mesh->faces[i]->data == -10) {
      int concentration = full_concentration_triangle(i);
      if(concentration != -10) {
        pm_mesh->faces[i]->data = concentration;
      }else{
        double center[3] = {0,0,0};
        for(size_t j=0; j<3; j++) {
          center[0] += pm_mesh->faces[i]->he->v->position.x();
          center[1] += pm_mesh->faces[i]->he->v->position.y();
          center[2] += pm_mesh->faces[i]->he->v->position.z();
          pm_mesh->faces[i]->he = pm_mesh->faces[i]->he->next;
        }
        center[0] /= 3.0;
        center[1] /= 3.0;
        center[2] /= 3.0;

        int concentration_center = (*pm)->walk_from(center, (*pm)->faces[10])->data;
        pm_mesh->faces[i]->data = concentration_center;
      }
    }

    (*concentration)[i] = pm_mesh->faces[i]->data;
    tris_concentration[i] = pm_mesh->faces[i]->data;
  }
}

int meshRelaying::full_concentration_triangle(int id){
  if(id<0) return -10;
  SVector3 pos = pm_mesh->faces[id]->he->v->position;
  double x1[3] = {pos.x(), pos.y(), pos.z()};
  pos = pm_mesh->faces[id]->he->next->v->position;
  double x2[3] = {pos.x(), pos.y(), pos.z()};
  pos = pm_mesh->faces[id]->he->next->next->v->position;
  double x3[3] = {pos.x(), pos.y(), pos.z()};
  double center[3] = {(x1[0]+x2[0]+x3[0])/3.0, (x1[1]+x2[1]+x3[1])/3.0, (x1[2]+x2[2]+x3[2])/3.0};
  PolyMesh **pm = discreteFront::instance()->getPm();

  int concentration_center = (*pm)->walk_from(center, (*pm)->faces[10])->data;
  int concentration1 = (*pm)->walk_from(x1, (*pm)->faces[10])->data;
  int concentration2 = (*pm)->walk_from(x2, (*pm)->faces[10])->data;
  int concentration3 = (*pm)->walk_from(x3, (*pm)->faces[10])->data;

  if(concentration1 == concentration_center && concentration2 == concentration_center && concentration3 == concentration_center) {
    return concentration_center;
  }
  return -10;
}

void meshRelaying::print4debug(const char *fn)
{
  FILE *f = fopen(fn, "w");
  if(discreteFront::instance()->empty()) {
    for(size_t k = 0; k < levelsets.size(); k++) {
      fprintf(f, "View \" Levelset %lu \" {\n", k);
      for(size_t i = 0; i < tris.size(); i += 3) {
        fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
                pos[3 * tris[i]], pos[3 * tris[i] + 1], pos[3 * tris[i] + 2],
                pos[3 * tris[i + 1]], pos[3 * tris[i + 1] + 1],
                pos[3 * tris[i + 1] + 2], pos[3 * tris[i + 2]],
                pos[3 * tris[i + 2] + 1], pos[3 * tris[i + 2] + 2],
                levelsets[k][tris[i]], levelsets[k][tris[i + 1]],
                levelsets[k][tris[i + 2]]);
      }
      for(size_t i = 0; i < tets.size(); i += 4) {
        fprintf(f, "SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                pos[3 * tets[i]], pos[3 * tets[i] + 1], pos[3 * tets[i] + 2],
                pos[3 * tets[i + 1]], pos[3 * tets[i + 1] + 1],
                pos[3 * tets[i + 1] + 2], pos[3 * tets[i + 2]],
                pos[3 * tets[i + 2] + 1], pos[3 * tets[i + 2] + 2],
                pos[3 * tets[i + 3]], pos[3 * tets[i + 3] + 1],
                pos[3 * tets[i + 3] + 2], levelsets[k][tets[i]],
                levelsets[k][tets[i + 1]], levelsets[k][tets[i + 2]],
                levelsets[k][tets[i + 3]]);
      }
      fprintf(f, "};\n");
    }
  }
  else {
    discreteFront::instance()->printInterfaces(f);
  }
  fclose(f);
}

double meshRelaying::myDensity2D(size_t iTriangle, double distMax, double RATIO,
                                 std::vector<double> &distances)
{
  // assume levelsets represent the distance to the front

  double DMIN = 1;
  double DMAX = RATIO;

  size_t i0 = tris[3 * iTriangle];
  size_t i1 = tris[3 * iTriangle + 1];
  size_t i2 = tris[3 * iTriangle + 2];
  double lsmin = 1.e22;
  if(discreteFront::instance()->empty()) {
    for(size_t k = 0; k < levelsets.size(); k++) {
      double ls0 = levelsets[k][i0];
      double ls1 = levelsets[k][i1];
      double ls2 = levelsets[k][i2];
      double lsk = fabs(ls0 + ls1 + ls2) / 3.0;
      if(lsk < lsmin) lsmin = lsk;
    }
  }
  else {
    lsmin = 0.0;
    for(int k = 0; k < 3; k++) {
      size_t ii = tris[3 * iTriangle + k];
      //      double x = pos[3*ii];
      //      double y = pos[3*ii+1];
      //      SVector3 P (x,y,0);
      //      SVector3 C  = discreteFront::instance()->closestPoints2d(P);
      lsmin += distances[ii] / 3.0;
      //      printf("%12.5E %12.5E\n",distances[ii],(P-C).norm());
      //      lsmin = std::min((P-C).norm(),lsmin);
    }
  }
  double size =
    (lsmin < distMax) ? DMIN + (DMAX - DMIN) * lsmin / distMax : DMAX;
  return 1. / (size * size);
}

void meshRelaying::untangle(double lambda, int nIterOut, int nIterIn,
                            double distMax, double RATIO)
{
  // update the triangular shapes for enabling
  auto sizeField =
    [this](const std::vector<std::array<double, 2>> &points,
           const std::vector<std::array<uint32_t, 3>> &triangles,
           std::vector<double> &s, // size and grad sizes at nodes
           std::vector<std::array<double, 3>> &grads) {
      double DMIN = 1;
      double DMAX = _RATIO;
      double distMax = _distMax;
      std::vector<int> bnd_markers;
      discreteFront::instance()->getBndMarkers(&bnd_markers);
      std::vector<bool> flag_bnd_markers(bnd_markers.size(), false);
      for(size_t i = 0; i < bnd_markers.size(); i++) {
        if(bnd_markers[i] == 1) flag_bnd_markers[i] = true;
      }


      s.resize(points.size());
      grads.resize(points.size());
      for(size_t i = 0; i < points.size(); i++) {
        SVector3 P(points[i][0], points[i][1], points[i][2]);
        SVector3 C = discreteFront::instance()->closestPoints2d(P, flag_bnd_markers);
        // has to be done for levelsets
        SVector3 CP = P - C;
        double d = CP.norm();
        CP.normalize();
        double size = (d < distMax) ? DMIN + (DMAX - DMIN) * d / distMax : DMAX;
        s[i] = size;
        SVector3 gradSize = (d < distMax) ? ((DMAX - DMIN) * d / distMax) * CP :
                                            SVector3(0, 0, 0);
        grads[i] = {gradSize.x(), gradSize.y(), gradSize.z()};
      }

      double SUM = 0.0;

      for(size_t i = 0; i < triangles.size(); i++) {
        vec2 v0 = points[triangles[i][0]];
        vec2 v1 = points[triangles[i][1]];
        vec2 v2 = points[triangles[i][2]];
        double s0 = s[triangles[i][0]];
        double s1 = s[triangles[i][1]];
        double s2 = s[triangles[i][2]];
        double area = triangle_area_2d(v0, v1, v2);
        SUM += 3.0 * area / (s0 * s0 + s1 * s1 + s2 * s2);
      }
      double C = sqrt(SUM / triangles.size());
      for(size_t i = 0; i < points.size(); i++) {
        s[i] *= C;
        grads[i][0] *= C;
        grads[i][1] *= C;
        grads[i][2] *= C;
      }
    };

  auto updateIdealTriangularShapes =
    [this](const std::vector<std::array<double, 2>> &points,
           const std::vector<std::array<uint32_t, 3>> &triangles,
           std::vector<std::array<std::array<double, 2>, 3>> &triIdealShapes) {
      triIdealShapes.clear();
      std::array<vec2, 3> equi = {
        vec2{1., 0.}, vec2{cos(2. * M_PI / 3.), sin(2 * M_PI / 3.)},
        vec2{cos(4. * M_PI / 3.), sin(4 * M_PI / 3.)}};
      double totArea = 0.0;
      double totOneOverWeight = 0.0;
      std::vector<double> distances;
      std::vector<int> bnd_markers;
      discreteFront::instance()->getBndMarkers(&bnd_markers);
      std::vector<bool> flag_bnd_markers(bnd_markers.size(), false);
      for(size_t i = 0; i < bnd_markers.size(); i++) {
        if(bnd_markers[i] == 1) flag_bnd_markers[i] = true;
      }
      std::vector<size_t> triple_markers;

      if(!discreteFront::instance()->empty()) {
        for(size_t i = 0; i < pos.size(); i += 3) {
          double x = pos[i];
          double y = pos[i + 1];
          SVector3 P(x, y, 0);
          SVector3 C =
            discreteFront::instance()->closestPoints2d(P, flag_bnd_markers);
          distances.push_back((P - C).norm());
        }
      }

      for(size_t i = 0; i < triangles.size(); i++) {
        vec2 v0 = points[triangles[i][0]];
        vec2 v1 = points[triangles[i][1]];
        vec2 v2 = points[triangles[i][2]];
        double density = myDensity2D(i, _distMax, _RATIO, distances);
        double area = triangle_area_2d(v0, v1, v2);
        totArea += area;
        totOneOverWeight += 1. / density;
      }
      double C = totArea / totOneOverWeight;
      double newArea = 0;
      for(size_t i = 0; i < triangles.size(); i++) {
        double density = myDensity2D(i, _distMax, _RATIO, distances);
        double fact = sqrt(C / density);
        vec2 p0 = equi[0] * fact;
        vec2 p1 = equi[1] * fact;
        vec2 p2 = equi[2] * fact;
        std::array<vec2, 3> perfect = {p0, p1, p2};
        double area = triangle_area_2d(p0, p1, p2);
        newArea += area;
        triIdealShapes.push_back(perfect);
      }
    };

  _distMax = distMax;
  _RATIO = RATIO;

#if defined(HAVE_WINSLOWUNTANGLER)
  std::vector<bool> _locked;
  // if(tets.size()) {
  //   std::vector<std::vector<uint32_t>> _elements;
  //   std::vector<std::array<double, 3>> _points;
  //   for(size_t i = 0; i < tets.size() / 4; i++)
  //     _elements.push_back({static_cast<unsigned int>(tets[4 * i]),
  //                          static_cast<unsigned int>(tets[4 * i + 1]),
  //                          static_cast<unsigned int>(tets[4 * i + 2]),
  //                          static_cast<unsigned int>(tets[4 * i + 3])});
  //   for(size_t i = 0; i < pos.size() / 3; i++)
  //     _points.push_back({pos[3 * i], pos[3 * i + 1], pos[3 * i + 2]});
  //   for(size_t i = 0; i < pos.size() / 3; i++)
  //     _locked.push_back(dimVertex[i] == 3 ? false : true);
  //   for(size_t i = 0; i < front_nodes.size(); i++)
  //     _locked[front_nodes[i]] = true;
  //   std::vector<std::array<uint32_t, 4>> _tets;
  //   std::vector<std::array<std::array<double, 3>, 4>> _tetIdealShapes;
  //   std::vector<std::vector<std::array<double, 3>>> _elementTargetShapes;
  //   {
  //     //      double minQual = 1.0;
  //     double avgQual = 0.0;
  //     for(size_t i = 0; i < tets.size() / 4; i++) {
  //       //	minQual = std::min(qualityElement(i),minQual);
  //       avgQual += qualityElement(i);
  //     }
  //     avgQual /= (tets.size() / 4);
  //     Msg::Info("Avg Quality Before Untangling %12.5E", avgQual);
  //   }
  //   buildTetrahedraFromElements(_elements, _elementTargetShapes, _tets,
  //                               _tetIdealShapes);
  //   untangle_tetrahedra(_points, _locked, _tets, _tetIdealShapes);
  //   for(size_t i = 0; i < _points.size(); i++) {
  //     pos[3 * i] = _points[i][0];
  //     pos[3 * i + 1] = _points[i][1];
  //     pos[3 * i + 2] = _points[i][2];
  //   }
  //   {
  //     //      double minQual = 1.0;
  //     double avgQual = 0.0;
  //     for(size_t i = 0; i < tets.size() / 4; i++) {
  //       //	minQual = std::min(qualityElement(i),minQual);
  //       avgQual += qualityElement(i);
  //     }
  //     avgQual /= (tets.size() / 4);
  //     //      Msg::Info ("Min Quality Before Untangling %12.5E",avgQual);
  //     //      for (size_t i=0;i<tets.size()/4;i++)minQual =
  //     //      std::min(qualityElement(i),minQual);
  //     Msg::Info("Avg Quality After Untangling %12.5E", avgQual);
  //   }
  // }
  if(tris.size()) {
    std::vector<std::array<uint32_t, 4>> _elements;
    std::vector<std::array<double, 2>> _points;
    for(size_t i = 0; i < tris.size() / 3; i++)
      _elements.push_back({static_cast<unsigned int>(tris[3 * i]),
                           static_cast<unsigned int>(tris[3 * i + 1]),
                           static_cast<unsigned int>(tris[3 * i + 2]),
                           uint32_t(-1)});
    for(size_t i = 0; i < pos.size() / 3; i++)
      _points.push_back({pos[3 * i], pos[3 * i + 1]});
    for(size_t i = 0; i < pos.size() / 3; i++)
      _locked.push_back(dimVertex[i] == 2 ? false : true);
    for(size_t i = 0; i < front_nodes.size(); i++)
      _locked[front_nodes[i]] = true;
    std::vector<std::array<uint32_t, 3>> _triangles;
    std::vector<std::array<std::array<double, 2>, 3>> _triIdealShapes;
    buildTrianglesAndTargetsFromElements(_points, _elements, _triangles,
                                         _triIdealShapes);
    untangle_triangles_2D(_points, _locked, _triangles, _triIdealShapes, lambda,
                          nIterIn, nIterOut, 10, 100000, sizeField,
                          updateIdealTriangularShapes);
    for(size_t i = 0; i < _points.size(); i++) {
      pos[3 * i] = _points[i][0];
      pos[3 * i + 1] = _points[i][1];
    }
  }
#else
  Msg::Error("Gmsh Must Be Compiled With WinslowUntangler to be able to use "
             "meshRelaying::untangle()");
#endif

  if(pm_mesh == nullptr){
    pm_mesh = new PolyMesh();
    std::vector<size_t> tris_p1;
    for(size_t i=0; i<tris.size(); i++) {
      tris_p1.push_back(tris[i]+1);
    }
    std::vector<double> pos_2d;
    for(size_t i=0; i<pos.size(); i+=3) {
      pos_2d.push_back(pos[i]);
      pos_2d.push_back(pos[i+1]);
    }
    triangulation2PolyMesh(tris_p1, pos_2d, &pm_mesh);
    
    //sort vertices
    std::sort(pm_mesh->vertices.begin(), pm_mesh->vertices.end(), [](PolyMesh::Vertex *a, PolyMesh::Vertex *b) {
      return a->data < b->data;
    });
  }

  for(size_t i=0; i<pm_mesh->vertices.size(); i++) {
    int v = pm_mesh->vertices[i]->data-1;
    SVector3 p(pos[3*v], pos[3*v+1], pos[3*v+2]);
    pm_mesh->vertices[i]->position = p;
  }
}

void meshRelaying::getPm(PolyMesh **pm)
{
  std::vector<double> pos_2d;

  for(size_t i = 0; i < pos.size(); i += 3) {
    pos_2d.push_back(pos[i]);
    pos_2d.push_back(pos[i + 1]);
  }
  std::vector<size_t> tris_1;
  for(size_t i = 0; i < tris.size(); i += 3) {
    tris_1.push_back(tris[i] + 1);
    tris_1.push_back(tris[i + 1] + 1);
    tris_1.push_back(tris[i + 2] + 1);
  }

  triangulation2PolyMesh(tris_1, pos_2d, pm);
  for(size_t i = 0; i < (*pm)->faces.size(); i++) {
    PolyMesh::Face *f = (*pm)->faces[i];
    f->data = tris_concentration[i];
  }
}

void meshRelaying::setNodesPosition(std::vector<double> mesh_pos){
  if (mesh_pos.size() != pos.size()){
    Msg::Error("The size of the input mesh_pos is not the same as the size of the current mesh");
  }
  pos = mesh_pos;
}


void meshRelaying::construct_DF_to_mesh_relation(std::vector<size_t> &DF_to_meshNodes, std::vector<double> &DF_to_mesh_parametric){
  size_t max_m = discreteFront::instance()->getMaxMarker();
  std::vector<interface> interfaces = discreteFront::instance()->getInterfaces();
  std::vector<double> DF_pos = discreteFront::instance()->getPos();

  DF_to_meshNodes.resize(2*(max_m+1));
  DF_to_mesh_parametric.resize(max_m+1);
  
  std::vector<bool> visited(max_m+1, false);

  if(pm_mesh == nullptr){
    pm_mesh = new PolyMesh();
    std::vector<size_t> tris_p1;
    for(size_t i=0; i<tris.size(); i++) {
      tris_p1.push_back(tris[i]+1);
    }
    std::vector<double> pos_2d;
    for(size_t i=0; i<pos.size(); i+=3) {
      pos_2d.push_back(pos[i]);
      pos_2d.push_back(pos[i+1]);
    }
    triangulation2PolyMesh(tris_p1, pos_2d, &pm_mesh);
    
    //sort vertices
    std::sort(pm_mesh->vertices.begin(), pm_mesh->vertices.end(), [](PolyMesh::Vertex *a, PolyMesh::Vertex *b) {
      return a->data < b->data;
    });

  }

  PolyMesh::Face *middle_face = pm_mesh->faces[pm_mesh->faces.size()/2];

  std::vector<int> bnd_markers;
  discreteFront::instance()->getBndMarkers(&bnd_markers);

  for(size_t i=0; i<interfaces.size(); i++){
    size_t n = interfaces[i].markers.size();
    for(size_t j=0; j<n; ++j){
      size_t marker = interfaces[i].markers[j];
      if(bnd_markers[marker] == 1) continue;
      if(visited[marker] == true) continue;
      visited[marker] = true;
      double marker_pos[3] = {DF_pos[3*marker], DF_pos[3*marker+1], DF_pos[3*marker+2]};
      PolyMesh::Face *f = pm_mesh->walk_from(marker_pos, middle_face);
      if(f == nullptr){
        Msg::Error("The marker %lu is not in the mesh", marker);
      }

      int v = point_on_triangle_vertex(f, marker_pos);
      if(v>-1){
        PolyMesh::HalfEdge *he = f->he;
        for(size_t k=0; k<v; k++){
          he = he->next;
        }
        DF_to_meshNodes[2*marker] = he->v->data-1;
        DF_to_meshNodes[2*marker+1] = he->v->data-1;
        DF_to_mesh_parametric[marker] = 0.0;
        continue;
      }

      PolyMesh::Face *f_current = f;
      size_t next = interfaces[i].markers[(j+1)%n];
      size_t current = marker;
      size_t iter = 1;
      double dist_forward = 0.0;
      size_t meshNode_forward = 0;

      while(true){
        double next_pos[3] = {DF_pos[3*next], DF_pos[3*next+1], DF_pos[3*next+2]};
        double current_pos[3] = {DF_pos[3*current], DF_pos[3*current+1], DF_pos[3*current+2]};

        PolyMesh::Face *f_next = pm_mesh->walk_from(next_pos, f_current);
        if(f_next == nullptr){
          Msg::Error("The marker %lu is not in the mesh", next);
        }

        int v_next = point_on_triangle_vertex(f_next, next_pos);
        if(v_next>-1){
          PolyMesh::HalfEdge *he = f_next->he;
          for(size_t k=0; k<v_next; k++){
            he = he->next;
          }
          meshNode_forward = he->v->data-1;
          dist_forward += sqrt((he->v->position.x()-current_pos[0])*(he->v->position.x()-current_pos[0]) + (he->v->position.y()-current_pos[1])*(he->v->position.y()-current_pos[1]));
          break;
        }

        
        if(f_next != f_current){
          bool found_vertex = false;
          PolyMesh::HalfEdge *he = f_current->he;
          for(size_t k=0; k<3; k++){
            size_t vertex = he->v->data;
            double vertex_pos[3] = {he->v->position.x(), he->v->position.y(), he->v->position.z()};

            double orient = robustPredicates::orient2d(next_pos, current_pos, vertex_pos);
            if(orient < 1e-10 && orient > -1e-10){
              double normal_pos[2] = {vertex_pos[0] + (next_pos[1]-current_pos[1]), vertex_pos[1] + (current_pos[0]-next_pos[0])};

              double orient1 = robustPredicates::orient2d(next_pos, vertex_pos, normal_pos);
              double orient2 = robustPredicates::orient2d(current_pos, vertex_pos, normal_pos);
              if((orient1<0 && orient2 > 0) || (orient1>0 && orient2 < 0)){
                meshNode_forward = vertex-1;
                dist_forward += sqrt((vertex_pos[0]-current_pos[0])*(vertex_pos[0]-current_pos[0]) + (vertex_pos[1]-current_pos[1])*(vertex_pos[1]-current_pos[1]));
                found_vertex = true;
                break;
              }
            }
            he = he->next;
          }
          if(found_vertex) break;
        }
        iter++;
        current = next;
        f_current = f_next;
        next = interfaces[i].markers[(j+iter)%n];

        double new_next_pos[3] = {DF_pos[3*next], DF_pos[3*next+1], DF_pos[3*next+2]};
        dist_forward += sqrt((new_next_pos[0]-next_pos[0])*(new_next_pos[0]-next_pos[0]) + (new_next_pos[1]-next_pos[1])*(new_next_pos[1]-next_pos[1]));
        
        if(iter > 20){
          exit(1);
        }
      }

      size_t prev = interfaces[i].markers[(j+n-1)%n];
      current = marker;
      iter = 1;
      double dist_backward = 0.0;
      size_t meshNode_backward = 0;
      f_current = f;
      while(true){
        double prev_pos[3] = {DF_pos[3*prev], DF_pos[3*prev+1], DF_pos[3*prev+2]};
        double current_pos[3] = {DF_pos[3*current], DF_pos[3*current+1], DF_pos[3*current+2]};
        PolyMesh::Face *f_prev = pm_mesh->walk_from(prev_pos, f_current);
        if(f_prev == nullptr){
          Msg::Error("The marker %lu is not in the mesh", next);
        }

        int v_prev = point_on_triangle_vertex(f_prev, prev_pos);
        if(v_prev>-1){
          PolyMesh::HalfEdge *he = f_prev->he;
          for(size_t k=0; k<v_prev; k++){
            he = he->next;
          }
          meshNode_backward = he->v->data-1;
          dist_backward += sqrt((he->v->position.x()-current_pos[0])*(he->v->position.x()-current_pos[0]) + (he->v->position.y()-current_pos[1])*(he->v->position.y()-current_pos[1]));
          break;
        }
        
        if(f_prev!= f_current){
          bool found_vertex = false;
          PolyMesh::HalfEdge *he = f_current->he;
          for(size_t k=0; k<3; k++){
            size_t vertex = he->v->data;
            double vertex_pos[2] = {he->v->position.x(), he->v->position.y()};

            double orient = robustPredicates::orient2d(prev_pos, current_pos, vertex_pos);
            if(orient < 1e-10 && orient > -1e-10){
              double normal_pos[2] = {vertex_pos[0] + (prev_pos[1]-current_pos[1]), vertex_pos[1] + (current_pos[0]-prev_pos[0])};
              
              double orient1 = robustPredicates::orient2d(prev_pos, vertex_pos, normal_pos);
              double orient2 = robustPredicates::orient2d(current_pos, vertex_pos, normal_pos);
              if((orient1<0 && orient2 > 0) || (orient1>0 && orient2 < 0)){
                meshNode_backward = vertex-1;
                dist_backward += sqrt((vertex_pos[0]-current_pos[0])*(vertex_pos[0]-current_pos[0]) + (vertex_pos[1]-current_pos[1])*(vertex_pos[1]-current_pos[1]));
                found_vertex = true;
                break;
              }
            }
            he = he->next;
          }
          if(found_vertex) break;
        }
        
        iter++;
        current = prev;
        f_current = f_prev;
        prev = interfaces[i].markers[(j+n-iter)%n];
        
        double new_prev_pos[3] = {DF_pos[3*prev], DF_pos[3*prev+1], DF_pos[3*prev+2]};
        dist_backward += sqrt((new_prev_pos[0]-prev_pos[0])*(new_prev_pos[0]-prev_pos[0]) + (new_prev_pos[1]-prev_pos[1])*(new_prev_pos[1]-prev_pos[1]));
      }

      double t;
      if(dist_forward+dist_backward<1e-13){
        t = 0.5;
      }else{
        t = dist_backward/(dist_forward+dist_backward);
      }
      
      DF_to_meshNodes[2*marker] = meshNode_backward;
      DF_to_meshNodes[2*marker+1] = meshNode_forward;
      DF_to_mesh_parametric[marker] = t;
    }
  }
    
}

void meshRelaying::construct_mesh_to_DF_relation(std::vector<size_t> &meshNodes_to_DF, std::vector<double> &mesh_to_DF_parametric){
  size_t max_m = discreteFront::instance()->getMaxMarker();
  std::vector<interface> interfaces = discreteFront::instance()->getInterfaces();
  std::vector<double> DF_pos = discreteFront::instance()->getPos();

  if(pm_mesh == nullptr){
    pm_mesh = new PolyMesh();
    std::vector<size_t> tris_p1;
    for(size_t i=0; i<tris.size(); i++) {
      tris_p1.push_back(tris[i]+1);
    }
    std::vector<double> pos_2d;
    for(size_t i=0; i<pos.size(); i+=3) {
      pos_2d.push_back(pos[i]);
      pos_2d.push_back(pos[i+1]);
    }
    triangulation2PolyMesh(tris_p1, pos_2d, &pm_mesh);
    
    //sort vertices
    std::sort(pm_mesh->vertices.begin(), pm_mesh->vertices.end(), [](PolyMesh::Vertex *a, PolyMesh::Vertex *b) {
      return a->data < b->data;
    });

  }

  meshNodes_to_DF.resize(2*(pm_mesh->vertices.size()));
  mesh_to_DF_parametric.resize(pm_mesh->vertices.size());

  PolyMesh::Face *middle_face = pm_mesh->faces[pm_mesh->faces.size()/2];

  std::vector<int> bnd_markers;
  discreteFront::instance()->getBndMarkers(&bnd_markers);
  
  for(size_t i=0; i<interfaces.size(); ++i){
    size_t n = interfaces[i].markers.size();
    for(size_t j=0; j<n; ++j){
      size_t m1 = interfaces[i].markers[j];
      if(bnd_markers[m1] == 1) continue;
      size_t m2 = interfaces[i].markers[(j+1)%n];

      double pos1[2] = {DF_pos[3*m1], DF_pos[3*m1+1]};
      double pos2[2] = {DF_pos[3*m2], DF_pos[3*m2+1]};
      double dist_1_2 = sqrt((pos1[0]-pos2[0])*(pos1[0]-pos2[0]) + (pos1[1]-pos2[1])*(pos1[1]-pos2[1]));

      PolyMesh::Face *start_f = pm_mesh->walk_from(pos1, middle_face);
      PolyMesh::Face *end_f = pm_mesh->walk_from(pos2, start_f);

      if(start_f == nullptr || end_f == nullptr){
        Msg::Error("The marker %lu or %lu is not in the mesh", m1, m2);
      }

      int found_triple = 0;
      PolyMesh::HalfEdge *he = start_f->he;
      for(size_t k=0; k<3; k++){
        size_t vertex = he->v->data-1;
        double vertex_pos[2] = {he->v->position.x(), he->v->position.y()};
        double dist_v_1 = sqrt((vertex_pos[0]-pos1[0])*(vertex_pos[0]-pos1[0]) + (vertex_pos[1]-pos1[1])*(vertex_pos[1]-pos1[1]));
        double dist_v_2 = sqrt((vertex_pos[0]-pos2[0])*(vertex_pos[0]-pos2[0]) + (vertex_pos[1]-pos2[1])*(vertex_pos[1]-pos2[1]));

        if(dist_v_1<1e-10){
          meshNodes_to_DF[2*vertex] = m1;
          meshNodes_to_DF[2*vertex+1] = m1;
          mesh_to_DF_parametric[vertex] = 0.0;
          found_triple = 1;
          break;
        }

        if(dist_v_2<1e-10){
          meshNodes_to_DF[2*vertex] = m2;
          meshNodes_to_DF[2*vertex+1] = m2;
          mesh_to_DF_parametric[vertex] = 0.0;
          found_triple = 1;
          break;
        }

        he = he->next;
      }

      if(start_f == end_f){
        continue;
      }

        

      PolyMesh::Face *current_f = start_f;
      int current_v = -1;
      size_t iter = 0;

      while(true){
        if(iter > 20){
          exit(1);
        }
        iter++;

        std::pair<size_t, size_t> intersect = intersect_face(current_f, pos1, pos2);

        if(intersect.first == intersect.second){
          if(intersect.first != current_v){
            meshNodes_to_DF[2*intersect.first] = m1;
            meshNodes_to_DF[2*intersect.first+1] = m2;
            double pos_node[2] = {pm_mesh->vertices[intersect.first]->position.x(), pm_mesh->vertices[intersect.first]->position.y()};
            double dist_1node = sqrt((pos1[0]-pos_node[0])*(pos1[0]-pos_node[0]) + (pos1[1]-pos_node[1])*(pos1[1]-pos_node[1]));

            mesh_to_DF_parametric[intersect.first] = dist_1node/dist_1_2;
          }
        }

        PolyMesh::HalfEdge *he = current_f->he;
        do{
          he = he->next;
        }while(he->v->data-1 != intersect.first);
        current_v = intersect.first;
        current_f = he->opposite->f;
        if(current_f == end_f){
          break;
        }
      }

    }
  }
}



std::pair<size_t, size_t> intersect_face(PolyMesh::Face *f, double *pos1, double *pos2){
  PolyMesh::HalfEdge *he = f->he;
  
  size_t n1 = he->v->data-1;
  size_t n2 = he->next->v->data-1;
  size_t n3 = he->next->next->v->data-1;

  size_t ns[3] = {n1, n2, n3};

  double pos_n1[2] = {he->v->position.x(), he->v->position.y()};
  double pos_n2[2] = {he->next->v->position.x(), he->next->v->position.y()};
  double pos_n3[2] = {he->next->next->v->position.x(), he->next->next->v->position.y()};

  double dist12 = sqrt((pos1[0]-pos2[0])*(pos1[0]-pos2[0]) + (pos1[1]-pos2[1])*(pos1[1]-pos2[1]));

  double distn11 = sqrt((pos1[0]-pos_n1[0])*(pos1[0]-pos_n1[0]) + (pos1[1]-pos_n1[1])*(pos1[1]-pos_n1[1]));
  double distn21 = sqrt((pos1[0]-pos_n2[0])*(pos1[0]-pos_n2[0]) + (pos1[1]-pos_n2[1])*(pos1[1]-pos_n2[1]));
  double distn12 = sqrt((pos2[0]-pos_n1[0])*(pos2[0]-pos_n1[0]) + (pos2[1]-pos_n1[1])*(pos2[1]-pos_n1[1]));
  double distn22 = sqrt((pos2[0]-pos_n2[0])*(pos2[0]-pos_n2[0]) + (pos2[1]-pos_n2[1])*(pos2[1]-pos_n2[1]));
  double distn31 = sqrt((pos1[0]-pos_n3[0])*(pos1[0]-pos_n3[0]) + (pos1[1]-pos_n3[1])*(pos1[1]-pos_n3[1]));
  double distn32 = sqrt((pos2[0]-pos_n3[0])*(pos2[0]-pos_n3[0]) + (pos2[1]-pos_n3[1])*(pos2[1]-pos_n3[1]));

  bool vertex_inter[3] = {false, false, false};
  double vertex_dist[3] = {distn12, distn22, distn32};

  if(distn11 + distn12 - dist12 < 1e-10){
    vertex_inter[0] = true;
  }
  if(distn21 + distn22 - dist12 < 1e-10){
    vertex_inter[1] = true;
  }
  if(distn31 + distn32 - dist12 < 1e-10){
    vertex_inter[2] = true;
  }

  double inter_pos[2];
  bool edge_inter[3] = {false, false, false};
  double edge_dist[3];
  double param;

  int inter = computeIntersection(pos1, pos2, pos_n1, pos_n2, inter_pos, &param);
  if(inter == 1){
    edge_inter[0] = true;
    edge_dist[0] = sqrt((inter_pos[0]-pos2[0])*(inter_pos[0]-pos2[0]) + (inter_pos[1]-pos2[1])*(inter_pos[1]-pos2[1]));
  }

  inter = computeIntersection(pos1, pos2, pos_n2, pos_n3, inter_pos, &param);
  if(inter == 1){
    edge_inter[1] = true;
    edge_dist[1] = sqrt((inter_pos[0]-pos2[0])*(inter_pos[0]-pos2[0]) + (inter_pos[1]-pos2[1])*(inter_pos[1]-pos2[1]));
  }

  inter = computeIntersection(pos1, pos2, pos_n3, pos_n1, inter_pos, &param);
  if(inter == 1){
    edge_inter[2] = true;
    edge_dist[2] = sqrt((inter_pos[0]-pos2[0])*(inter_pos[0]-pos2[0]) + (inter_pos[1]-pos2[1])*(inter_pos[1]-pos2[1]));
  }

  double min_dist = 1e10;
  std::pair<size_t, size_t> min_pair = {0, 0};

  for(size_t i=0; i<3; i++){
    if(vertex_inter[i]){
      if(vertex_dist[i] < min_dist){
        min_dist = vertex_dist[i];
        min_pair = {ns[i], ns[i]};
      }
    }
    if(edge_inter[i]){
      if(edge_dist[i] < min_dist){
        min_dist = edge_dist[i];
        min_pair = {ns[i], ns[(i+1)%3]};
      }
    }
  }

  return min_pair;

}



int point_on_triangle_vertex(PolyMesh::Face *f, double *pos){
  PolyMesh::HalfEdge *he = f->he;
  for(size_t i=0; i<3; i++){
    double vertex_pos[3] = {he->v->position.x(), he->v->position.y(), 0};
    double dist = sqrt((vertex_pos[0]-pos[0])*(vertex_pos[0]-pos[0]) + (vertex_pos[1]-pos[1])*(vertex_pos[1]-pos[1]));
    if(dist < 1e-8){
      return i;
    }
    he = he->next;
  }
  return -1;
}

int point_on_triangle_edge(PolyMesh::Face *f, double *pos){
  PolyMesh::HalfEdge *he = f->he;
  for(size_t i=0; i<3; ++i){
    double vertex_pos[2] = {he->v->position.x(), he->v->position.y()};
    double next_vertex_pos[2] = {he->next->v->position.x(), he->next->v->position.y()};
    double area = robustPredicates::orient2d(vertex_pos, next_vertex_pos, pos);

    he = he->next;
  }
}

void meshRelaying::print_DF(const std::string DF_filename){
  FILE *f = std::fopen(DF_filename.c_str(), "w");
  if(f == nullptr) {
    Msg::Error("Could not open file %s", DF_filename.c_str());
  } 

  discreteFront::instance()->printInterfaces(f);
  fprintf(f, "View \" Mesh \" {\n");
  for(size_t i = 0; i < tris.size(); i += 3) {
    for(size_t j = 0; j < 3; ++j) {
      fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", pos[3 * tris[i + j]],
              pos[3 * tris[i + j] + 1], pos[3 * tris[i + j] + 2],
              pos[3 * tris[i + (j + 1) % 3]],
              pos[3 * tris[i + (j + 1) % 3] + 1],
              pos[3 * tris[i + (j + 1) % 3] + 2], 10, 10);
    }
  }
  fprintf(f, "};\n");

  fprintf(f, "View \" Concentration \" {\n");
  for(size_t i = 0; i < tris.size(); i += 3) {
    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n", pos[3 * tris[i]],
            pos[3 * tris[i] + 1], pos[3 * tris[i] + 2], pos[3 * tris[i + 1]],
            pos[3 * tris[i + 1] + 1], pos[3 * tris[i + 1] + 2],
            pos[3 * tris[i + 2]], pos[3 * tris[i + 2] + 1],
            pos[3 * tris[i + 2] + 2], (tris_concentration)[i / 3],
            (tris_concentration)[i / 3], (tris_concentration)[i / 3]);
  }
  fprintf(f, "};\n");
  fclose(f);
}

void meshRelaying::setMeshPos(const std::vector<double> &mesh_pos)
{
  if(mesh_pos.size() != pos.size()) {
    Msg::Error("The size of the input mesh_pos is not the same as the size of the size of the current mesh");
  }
  pos = mesh_pos;
  if(pm_mesh != nullptr) {
    for(size_t i = 0; i < pm_mesh->vertices.size(); i++) {
      int v = pm_mesh->vertices[i]->data - 1;
      SVector3 p(pos[3 * v], pos[3 * v + 1], pos[3 * v + 2]);
      pm_mesh->vertices[i]->position = p;
    }
  }

}

// discreteFront functions

std::vector<std::pair<size_t, size_t>> discreteFront::getFrontEdges()
{
  std::sort(fn.begin(), fn.end());
  std::vector<std::pair<size_t, size_t>> pp;
  std::vector<size_t> curr;
  if(fn.size() == 0) return pp;
  int current_color = interfaces[fn[0].interface].tag;
  for(size_t i = 0; i < fn.size(); i++) {
    const frontNode &n = fn[i];
    int color = interfaces[fn[i].interface].tag;
    if(current_color != color) {
      for(size_t j = 0; j < curr.size(); j++) {
        size_t A = curr[j];
        size_t B = curr[(j + 1) % curr.size()];
        std::pair<size_t, size_t> pa =
          std::make_pair(std::min(A, B), std::max(A, B));
        pp.push_back(pa);
      }
      curr.clear();
      current_color = color;
    }
    curr.push_back(n.meshNode);
  }

  for(size_t j = 0; j < curr.size(); j++) {
    size_t A = curr[j];
    size_t B = curr[(j + 1) % curr.size()];
    std::pair<size_t, size_t> pa =
      std::make_pair(std::min(A, B), std::max(A, B));
    pp.push_back(pa);
  }
  std::sort(pp.begin(), pp.end());
  return pp;
}

void discreteFront::intersectLine2d(const SVector3 &p0, const SVector3 &p1,
                                    std::vector<double> &d, std::vector<int> &c)
{
  SPoint2 a1(p0.x(), p0.y());
  SPoint2 a2(p1.x(), p1.y());

  double xmin = std::min(p0.x(), p1.x());
  double xmax = std::max(p0.x(), p1.x());
  double ymin = std::min(p0.y(), p1.y());
  double ymax = std::max(p0.y(), p1.y());

  if(xmin < bbox.min().x()) return;
  if(xmax > bbox.max().x()) return;
  if(ymin < bbox.min().y()) return;
  if(ymax > bbox.max().y()) return;

  std::vector<std::pair<size_t, size_t>> _ind;
  int IMIN, IMAX, JMIN, JMAX;
  getCoordinates(xmin, ymin, IMIN, JMIN);
  getCoordinates(xmax, ymax, IMAX, JMAX);
  for(int I = IMIN; I <= IMAX; I++) {
    for(int J = JMIN; J <= JMAX; J++) {
      int index = I + NX * J;
      for(size_t k = 0; k < sss[index].size(); k++) {
        _ind.push_back(sss[index][k].second);
      }
    }
  }

  std::sort(_ind.begin(), _ind.end());
  auto last = std::unique(_ind.begin(), _ind.end());
  _ind.erase(last, _ind.end());
  for(size_t I = 0; I < _ind.size(); I++) {
    std::pair<size_t, size_t> line = _ind[I];
    int m = line.first;
    int mp1 = line.second;
    double a3[2] = {pos[3 * m], pos[3 * m + 1]};
    double a4[2] = {pos[3 * mp1], pos[3 * mp1 + 1]};

    double xminb = std::min(a3[0], a4[0]);
    double xmaxb = std::max(a3[0], a4[0]);
    double yminb = std::min(a3[1], a4[1]);
    double ymaxb = std::max(a3[1], a4[1]);
    if(ymaxb < ymin) continue;
    if(xmaxb < xmin) continue;
    if(xminb > xmax) continue;
    if(yminb > ymax) continue;

    double a143 = robustPredicates::orient2d(a1, a4, a3);
    double a243 = robustPredicates::orient2d(a2, a4, a3);
    if(a143 * a243 > 0) continue;

    double a123 = robustPredicates::orient2d(a1, a2, a3);
    double a124 = robustPredicates::orient2d(a1, a2, a4);
    if(a123 * a124 > 0) continue;

    d.push_back(a143 / (a143 - a243));
    c.push_back(m);
    c.push_back(mp1);
  }
}

void discreteFront::getCoordinates(double x, double y, int &IX, int &IY)
{
  IX = (NX - 1) * (x - bbox.min().x()) / (bbox.max().x() - bbox.min().x());
  IY = (NY - 1) * (y - bbox.min().y()) / (bbox.max().y() - bbox.min().y());
}

int discreteFront::findMarker(size_t marker)
{
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      if(interfaces[i].markers[j] == marker) { return i; }
    }
  }
  return -1;
}

void discreteFront::cornersInTriangle2d(
  const SVector3 &p0, const SVector3 &p1, const SVector3 &p2,
  std::vector<SVector3> &cornerPos,
  std::vector<std::pair<size_t, size_t>> &corner)
{
  SPoint2 a0(p0.x(), p0.y());
  SPoint2 a1(p1.x(), p1.y());
  SPoint2 a2(p2.x(), p2.y());
  for(auto i : corners) {
    SPoint2 p(pos[3 * i], pos[3 * i + 1]);
    SVector3 p3(pos[3 * i], pos[3 * i + 1], 0);
    double d =
      std::min(std::min((p0 - p3).norm(), (p1 - p3).norm()), (p2 - p3).norm());
    if(d < 1.e-12) continue; // FIXME
    double a01p = robustPredicates::orient2d(a0, a1, p);
    double a12p = robustPredicates::orient2d(a1, a2, p);
    double a20p = robustPredicates::orient2d(a2, a0, p);

    if(a01p * a12p > 0 && a01p * a20p > 0 && a20p * a12p > 0) {
      int id_interface_ = findMarker(i);
      if(id_interface_ == -1) {
        continue;
      }
      size_t id_interface = id_interface_;
      cornerPos.push_back(SVector3(pos[3 * i], pos[3 * i + 1], 0));
      corner.push_back(std::make_pair(id_interface, i));
    }
  }
}

void discreteFront::tripleInTriangle2d(const SVector3 &p0, const SVector3 &p1,
                                       const SVector3 &p2,
                                       std::vector<size_t> &m,
                                       std::vector<SVector3> &p_out)
{
  SPoint2 a0(p0.x(), p0.y());
  SPoint2 a1(p1.x(), p1.y());
  SPoint2 a2(p2.x(), p2.y());
  for(size_t ii = 0; ii < triple_points.size(); ++ii) {
    size_t i = triple_points[ii];
    SPoint2 p(pos[3 * i], pos[3 * i + 1]);
    SVector3 p3(pos[3 * i], pos[3 * i + 1], 0);
    double d =
      std::min(std::min((p0 - p3).norm(), (p1 - p3).norm()), (p2 - p3).norm());
    if(d < 1.e-12) continue; // FIXME

    double a01p = robustPredicates::orient2d(a0, a1, p);
    double a12p = robustPredicates::orient2d(a1, a2, p);
    double a20p = robustPredicates::orient2d(a2, a0, p);
    if(a01p * a12p >= 0 && a01p * a20p >= 0 && a20p * a12p >= 0) {
      m.push_back(triple_points[ii]);
      p_out.push_back(SVector3(pos[3 * i], pos[3 * i + 1], 0));
    }
  }
}

void discreteFront::getBndMarkers(std::vector<int> *bnd_markers)
{
  bnd_markers->clear();
  size_t m_max = getMaxMarker();
  bnd_markers->resize(m_max + 1, 0);
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t m = interfaces[i].markers[j];
      int colors[3] = {0, 0, 0};
      PolyMesh::Vertex *v;
      int triple = vertexType(findVertex(m, v), colors);
      if(triple == 1) {
        if(colors[0] == -10 || colors[1] == -10 || colors[2] == -10) {
          (*bnd_markers)[m] = 1;
        }
        else {
          (*bnd_markers)[m] = 0;
        }
      }
      else {
        if(colors[0] == -10 || colors[1] == -10) { (*bnd_markers)[m] = 1; }
        else {
          (*bnd_markers)[m] = 0;
        }
      }
    }
  }
}

void discreteFront::getSolidMarkers(std::vector<int> *solid_markers)
{
  solid_markers->clear();
  size_t m_max = getMaxMarker();
  solid_markers->resize(m_max + 1, 0);
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t m = interfaces[i].markers[j];
      int colors[3] = {0, 0, 0};
      PolyMesh::Vertex *v;
      int triple = vertexType(findVertex(m, v), colors);
      if(triple == 1) {
        if(colors[0] < 0 || colors[1] < 0 || colors[2] < 0) {
          (*solid_markers)[m] = 1;
        }
        else {
          (*solid_markers)[m] = 0;
        }
      }
      else {
        if(colors[0] < 0 || colors[1] < 0) { (*solid_markers)[m] = 1; }
        else {
          (*solid_markers)[m] = 0;
        }
      }
    }
  }
}

void discreteFront::markersCurvature(std::vector<int> concentration_list,
                                     std::vector<double> tension_table,
                                     std::vector<double> *curvature)
{
  size_t m_max = getMaxMarker();
  curvature->resize(m_max + 1, 0.0);

  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t m = interfaces[i].markers[j];
      size_t n = interfaces[i].markers.size();
      int colors[3] = {0, 0, 0};
      PolyMesh::Vertex *v;
      int id_v = findVertex(m, v);
      if(id_v == -1) {
        printf("marker %lu not found\n", m);
        exit(1);
      }else{
        v = pm->vertices[id_v];
      }
      int triple = vertexType(id_v, colors);

      if(triple != 1) {
        if(colors[0] < 0 || colors[1] < 0) { // marker between solid and fluid
          (*curvature)[m] = 0.0;
        }
        else { // marker between two fluids
          int dominant = colors[0];
          std::vector<PolyMesh::Vertex *> dom_neigh;
          findNDoubleNeighbours(v, &dom_neigh, 1, dominant, true);
          size_t m_p1 = dom_neigh[2]->data - 1;
          size_t m_m1 = dom_neigh[0]->data - 1;
          double pos_m[3] = {pos[3 * m], pos[3 * m + 1], pos[3 * m + 2]};
          double pos_p1[3] = {pos[3 * m_p1], pos[3 * m_p1 + 1],
                              pos[3 * m_p1 + 2]};
          double pos_m1[3] = {pos[3 * m_m1], pos[3 * m_m1 + 1],
                              pos[3 * m_m1 + 2]};

          int fluid1 = colors[0];
          int fluid2 = colors[1];
          size_t id_fluid1 = std::find(concentration_list.begin(),
                                       concentration_list.end(), fluid1) -
                             concentration_list.begin();
          size_t id_fluid2 = std::find(concentration_list.begin(),
                                       concentration_list.end(), fluid2) -
                             concentration_list.begin();
          size_t n_concentration = concentration_list.size();
          // double gamma_12 =
          //   tension_table[n_concentration * id_fluid1 + id_fluid2];
          (*curvature)[m] = kappa(pos_m1, pos_m, pos_p1);
        }
      }
      else {
        (*curvature)[m] = 0.0;
        // int dominant = colors[0];
        // int fluid1 = colors[1];
        // int fluid2 = colors[2];
        // size_t id_dom = std::find(concentration_list.begin(),
        //                           concentration_list.end(), dominant) -
        //                 concentration_list.begin();
        // size_t id_fluid1 = std::find(concentration_list.begin(),
        //                              concentration_list.end(), fluid1) -
        //                    concentration_list.begin();
        // size_t id_fluid2 = std::find(concentration_list.begin(),
        //                              concentration_list.end(), fluid2) -
        //                    concentration_list.begin();
        // size_t n_concentration = concentration_list.size();

        // double gamma_12 =
        //   tension_table[n_concentration * id_fluid1 + id_fluid2];
        // double gamma_dom1 = tension_table[n_concentration * id_dom + id_fluid1];
        // double gamma_dom2 = tension_table[n_concentration * id_dom + id_fluid2];

        // std::vector<PolyMesh::Vertex *> dom_neigh;
        // findNDoubleNeighbours(v, &dom_neigh, 1, dominant);
        // std::vector<PolyMesh::Vertex *> fluid1_neigh;
        // findNDoubleNeighbours(v, &fluid1_neigh, 1, fluid1);
        // size_t m_fluid;
        // size_t m_dom;
        // if(fluid1_neigh[0]->data == dom_neigh[0]->data) {
        //   m_fluid = fluid1_neigh[1]->data - 1;
        //   m_dom = dom_neigh[0]->data - 1;
        // }
        // else if(fluid1_neigh[0]->data == dom_neigh[1]->data) {
        //   m_fluid = fluid1_neigh[1]->data - 1;
        //   m_dom = dom_neigh[1]->data - 1;
        // }
        // else if(fluid1_neigh[1]->data == dom_neigh[0]->data) {
        //   m_fluid = fluid1_neigh[0]->data - 1;
        //   m_dom = dom_neigh[0]->data - 1;
        // }
        // else if(fluid1_neigh[1]->data == dom_neigh[1]->data) {
        //   m_fluid = fluid1_neigh[0]->data - 1;
        //   m_dom = dom_neigh[1]->data - 1;
        // }

        // double theta = acos((gamma_dom2 - gamma_dom1) / gamma_12);
        // double edge[2] = {pos[3 * m_dom] - pos[3 * m],
        //                   pos[3 * m_dom + 1] - pos[3 * m + 1]};
        // double edge_norm = sqrt(edge[0] * edge[0] + edge[1] * edge[1]);
        // edge[0] /= edge_norm;
        // edge[1] /= edge_norm;

        // double rotated_edge[2] = {cos(theta) * edge[0] - sin(theta) * edge[1],
        //                           sin(theta) * edge[0] + cos(theta) * edge[1]};
        // double dist = sqrt((pos[3 * m_fluid] - pos[3 * m]) *
        //                      (pos[3 * m_fluid] - pos[3 * m]) +
        //                    (pos[3 * m_fluid + 1] - pos[3 * m + 1]) *
        //                      (pos[3 * m_fluid + 1] - pos[3 * m + 1]));

        // double ghost[3] = {pos[3 * m] - dist * rotated_edge[0],
        //                    pos[3 * m + 1] - dist * rotated_edge[1], 0};
        // double pos_m[3] = {pos[3 * m], pos[3 * m + 1], pos[3 * m + 2]};
        // double pos_m_fluid[3] = {pos[3 * m_fluid], pos[3 * m_fluid + 1],
        //                          pos[3 * m_fluid + 2]};
        // (*curvature)[m] = gamma_12 * kappa(ghost, pos_m, pos_m_fluid);
      }
    }
  }
}

size_t discreteFront::getMaxMarker()
{
  size_t max_marker = 0;
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      if(interfaces[i].markers[j] > max_marker) {
        max_marker = interfaces[i].markers[j];
      }
    }
  }
  return max_marker;
}

void discreteFront::getDF(std::vector<double> *doubleMarkers,
                          std::vector<int> *doubleTags,
                          std::vector<size_t> *doubleIds,
                          std::vector<double> *tripleMarkers,
                          std::vector<int> *tripleTags,
                          std::vector<size_t> *tripleIds,
                          std::vector<size_t> *DF_to_meshNodes, 
                          std::vector<double> *DF_to_mesh_parametric,
                          std::vector<size_t> *meshNodes_to_DF, 
                          std::vector<double> *mesh_to_DF_parametric, 
                          const bool mesh_relation)
{
  doubleMarkers->clear();
  doubleTags->clear();
  tripleMarkers->clear();
  tripleTags->clear();

  for(size_t i = 0; i < pm->vertices.size(); ++i) {
    int colors[3] = {0, 0, 0};
    int vIsTriple = vertexType(i, colors);
    if(vIsTriple == 1) {
      tripleMarkers->push_back(pm->vertices[i]->position.x());
      tripleMarkers->push_back(pm->vertices[i]->position.y());
      tripleTags->push_back(colors[0]);
      tripleTags->push_back(colors[1]);
      tripleTags->push_back(colors[2]);
      tripleIds->push_back(pm->vertices[i]->data - 1);
    }
    else if(vIsTriple == 0) {
      doubleMarkers->push_back(pm->vertices[i]->position.x());
      doubleMarkers->push_back(pm->vertices[i]->position.y());
      doubleTags->push_back(colors[0]);
      doubleTags->push_back(colors[1]);
      doubleIds->push_back(pm->vertices[i]->data - 1);
    }
  }

  if(mesh_relation){
    meshRelaying::instance()->construct_DF_to_mesh_relation(*DF_to_meshNodes, *DF_to_mesh_parametric);
    meshRelaying::instance()->construct_mesh_to_DF_relation(*meshNodes_to_DF, *mesh_to_DF_parametric);
  }
  
  return;
}

int discreteFront::vertexType(size_t i, int *colors)
{
  PolyMesh::Vertex *v = pm->vertices[i];
  PolyMesh::HalfEdge *he = v->he;
  PolyMesh::HalfEdge *bnd_he = nullptr;
  std::vector<int> f_colors;
  do {
    if(he->opposite == nullptr) {
      bnd_he = he;
      break;
    }
    f_colors.push_back(he->f->data);
    he = he->opposite->next;
  } while(he != v->he);
  if(bnd_he != nullptr) {
    f_colors.clear();
    he = bnd_he;
    do {
      f_colors.push_back(he->f->data);
      he = he->next->next->opposite;
    } while(he != nullptr);
  }

  std::sort(f_colors.begin(), f_colors.end());
  auto it = std::unique(f_colors.begin(), f_colors.end());
  f_colors.resize(std::distance(f_colors.begin(), it));
  
  if(f_colors.size() == 3) {
    colors[0] = f_colors[0];
    colors[1] = f_colors[1];
    colors[2] = f_colors[2];
    return 1;
  }
  else if(bnd_he == nullptr) {
    colors[0] = f_colors[0];
    colors[1] = f_colors[1];
    return 0;
  }
  else {
    if(f_colors.size() == 1) {
      colors[0] = f_colors[0];
      colors[1] = -10; // fix me
      colors[2] = -10; // fix me
      return 0;
    }
    else {
      colors[0] = f_colors[0];
      colors[1] = f_colors[1];
      colors[2] = -10; // fix me
      return 1;
    }
  }
}

void discreteFront::moveFromV(double dt, const std::vector<SVector3> &v, const bool triple_slip)
{
  // detect triple points and store them
  std::vector<PolyMesh::Vertex *> triple_v;
  std::vector<size_t> triples_id;
  PolyMesh::Vertex *dummy;
  for(size_t i = 0; i < v.size(); ++i) {
    int id = findVertex(i, dummy);
    if(id == -1) continue;
    int colors[3] = {0, 0, 0};
    if(vertexType(id, colors) == 1) {
      triple_v.push_back(pm->vertices[id]);
      triples_id.push_back(id);
    }
  }

  std::vector<SVector3> remaining_vel(triple_v.size(), SVector3(0, 0, 0));
  std::vector<int> dom_colors(triple_v.size(), 0);
  std::vector<std::vector<size_t>> triple_neighs;
  if(triple_slip){
    // move triple points with their two double neighbour and compute remaining
    // velocity
    triple_neighs.resize(triple_v.size());
    for(size_t i = 0; i < triple_v.size(); ++i) {
      PolyMesh::Vertex *vertex = triple_v[i];
      size_t id = triples_id[i];
      size_t m = vertex->data - 1;
      int colors[3] = {0, 0, 0};
      vertexType(id, colors);
      size_t priority_level = 100;
      for(size_t c = 0; c < 3; ++c) {
        size_t level = std::find(priority.begin(), priority.end(), colors[c]) -
                      priority.begin();
        if(level < priority_level) priority_level = level;
      }
      int dominant_color = priority[priority_level];
      if(colors[0] == -10 || colors[1] == -10 || colors[2] == -10) {
        dominant_color = -10;
      }
      dom_colors[i] = dominant_color;

      // find the neighbours with the pm
      std::vector<size_t> neighbours;
      std::vector<PolyMesh::Vertex *> v_neighs;
      findNDoubleNeighbours(vertex, &v_neighs, 1, dominant_color);
      PolyMesh::Vertex *n1 = v_neighs[0];
      PolyMesh::Vertex *n2 = v_neighs[2];
      if(n1->data == -1 || n2->data == -1) {
        printf("n1 == nullptr || n2 == nullptr\n");
        exit(1);
      }

      // move triple point with two neighbours
      size_t m_n1 = n1->data - 1;
      size_t m_n2 = n2->data - 1;
      double n1_pos[2] = {pos[3 * m_n1], pos[3 * m_n1 + 1]};
      double n2_pos[2] = {pos[3 * m_n2], pos[3 * m_n2 + 1]};
      double dist_n1 =
        sqrt((n1_pos[0] - pos[3 * m]) * (n1_pos[0] - pos[3 * m]) +
            (n1_pos[1] - pos[3 * m + 1]) * (n1_pos[1] - pos[3 * m + 1]));
      double dist_n2 =
        sqrt((n2_pos[0] - pos[3 * m]) * (n2_pos[0] - pos[3 * m]) +
            (n2_pos[1] - pos[3 * m + 1]) * (n2_pos[1] - pos[3 * m + 1]));
      double n1_weight = dist_n2 / (dist_n1 + dist_n2);
      double n2_weight = dist_n1 / (dist_n1 + dist_n2);

      double v_x = (n1_weight * v[m_n1].x() + n2_weight * v[m_n2].x());
      double v_y = (n1_weight * v[m_n1].y() + n2_weight * v[m_n2].y());
      pos[3 * m] += dt * v_x;
      pos[3 * m + 1] += dt * v_y;
      pos[3 * m + 2] = 0;

      remaining_vel[i] = SVector3(v[m].x() - v_x, v[m].y() - v_y, 0);

      // stock a certain number of 4 neighbours from both side
      triple_neighs[i].resize(9);
      findNDoubleNeighbours(vertex, &v_neighs, 4, dominant_color);
      for(size_t j = 0; j < 9; ++j) {
        triple_neighs[i][j] = v_neighs[j]->data - 1;
      }
    }
  } else {
    for(size_t i = 0; i < triple_v.size(); ++i) {
      PolyMesh::Vertex *vertex = triple_v[i];
      size_t id = triples_id[i];
      size_t m = vertex->data - 1;
      remaining_vel[i] = SVector3(v[m].x(), v[m].y(), 0);
    }
  }

  
  // move double points
  for(size_t i = 0; i < v.size(); ++i) {
    int id = findVertex(i, dummy);
    if(id == -1) continue;
    int colors[3] = {0, 0, 0};
    if(vertexType(id, colors) == 0) {
      pos[3 * i] += dt * v[i].x();
      pos[3 * i + 1] += dt * v[i].y();
      pos[3 * i + 2] += 0;
    }
  }

  triple_points.clear();
  on_edge_triples.clear();

  if(triple_slip){
    // finalize move of triple points
    for(size_t i = 0; i < triple_v.size(); ++i) {
      int dominant_color = dom_colors[i];
      size_t m = triple_v[i]->data - 1;
      // chose direction
      int direction = 0;
      double n1_pos[2] = {pos[3 * triple_neighs[i][3]],
                          pos[3 * triple_neighs[i][3] + 1]};
      double n2_pos[2] = {pos[3 * triple_neighs[i][5]],
                          pos[3 * triple_neighs[i][5] + 1]};
      double m_pos[2] = {pos[3 * m], pos[3 * m + 1]};
      double edge1[2] = {n1_pos[0] - m_pos[0], n1_pos[1] - m_pos[1]};
      double edge2[2] = {n2_pos[0] - m_pos[0], n2_pos[1] - m_pos[1]};

      double dot1 =
        edge1[0] * remaining_vel[i].x() + edge1[1] * remaining_vel[i].y();
      double dot2 =
        edge2[0] * remaining_vel[i].x() + edge2[1] * remaining_vel[i].y();

      double dist_todo;
      if(dot1 > dot2) {
        direction = -1;
        dist_todo =
          dt * (dot1 / (sqrt(edge1[0] * edge1[0] + edge1[1] * edge1[1])));
      }
      else {
        direction = 1;
        dist_todo =
          dt * (dot2 / (sqrt(edge2[0] * edge2[0] + edge2[1] * edge2[1])));
      }

      dist_todo = std::max(0.0, dist_todo);
      double dist_done = 0;

      // move in that direction
      size_t current = 4;
      while(dist_done < dist_todo) {
        size_t current_m = triple_neighs[i][current];
        size_t next_m = triple_neighs[i][current + direction];
        double dist = sqrt((pos[3 * next_m] - pos[3 * current_m]) *
                            (pos[3 * next_m] - pos[3 * current_m]) +
                          (pos[3 * next_m + 1] - pos[3 * current_m + 1]) *
                            (pos[3 * next_m + 1] - pos[3 * current_m + 1]));

        if(dist_done + dist < dist_todo) {
          switchMarkers(dominant_color, m, next_m, direction);
          dist_done += dist;
          current += direction;
          if(current < 0 || current > 8) {
            printf("displacement was more than 4 neighbours, that's a lot -> "
                  "simu crashed? or dense neighbourhood?\n");
            exit(1);
          }
        }
        else {
          double ratio = (dist_todo - dist_done) / dist;
          pos[3 * m] =
            pos[3 * current_m] + ratio * (pos[3 * next_m] - pos[3 * current_m]);
          pos[3 * m + 1] = pos[3 * current_m + 1] +
                          ratio * (pos[3 * next_m + 1] - pos[3 * current_m + 1]);
          pos[3 * current_m + 2] = 0;
          std::pair<size_t, std::pair<size_t, size_t>> p_m;
          if (current == 4){
            current_m = triple_neighs[i][current-direction];
          }
          if(current_m < next_m) { 
            p_m = std::make_pair(current_m, std::make_pair(m, next_m)); 
          } else {
            p_m = std::make_pair(next_m, std::make_pair(m, current_m));
          }

          on_edge_triples.push_back(p_m);
          triple_points.push_back(m);
          break;
        }
      }
    }
  } else {
    for(size_t i = 0; i < triple_v.size(); ++i) {
      size_t m = triple_v[i]->data - 1;
      pos[3 * m] += dt * remaining_vel[i].x();
      pos[3 * m + 1] += dt * remaining_vel[i].y();
      pos[3 * m + 2] = 0;
      triple_points.push_back(m);
    }
  }

  return;
}

// void discreteFront::findDoubleNeighbours(PolyMesh::Vertex *vertex,
//                                          std::vector<PolyMesh::Vertex *> *ns,
//                                          int dominant_color)
// {
//   printf("in findDoubleNeighbours\n");
//   printf("look for neighbours of %d\n", vertex->data - 1);
//   PolyMesh::HalfEdge *he = vertex->he;
//   PolyMesh::HalfEdge *bnd_he = nullptr;
//   std::vector<PolyMesh::Vertex *> neighs;
//   do {
//     if(he->opposite == nullptr && dominant_color == -10) {
//       neighs.push_back(he->next->v);
//       bnd_he = he;
//       break;
//     }
//     else if(he->opposite == nullptr && dominant_color != -10) {
//       printf(
//         "error in findDoubleNeighbours :opposite == null && dominant != 10
//         \n");
//       exit(1);
//     }
//     else if(he->f->data == dominant_color &&
//             he->opposite->f->data != dominant_color) {
//       neighs.push_back(he->next->v);
//     }
//     else if(he->f->data != dominant_color &&
//             he->opposite->f->data == dominant_color) {
//       neighs.push_back(he->next->v);
//     }

//     he = he->opposite->next;
//   } while(he != vertex->he);

//   if(bnd_he != nullptr) {
//     he = bnd_he;
//     do {
//       if(he->next->next->opposite == nullptr && dominant_color == -10) {
//         neighs.push_back(he->next->next->v);
//         break;
//       }
//       he = he->next->next->opposite;
//     } while(he != nullptr);
//   }

//   if(neighs.size() != 2) {
//     printf("error in findDoubleNeighbours :neighs.size() != 2\n");
//     exit(1);
//   }
//   printf("found neighs %lu %lu\n", neighs[0]->data - 1, neighs[1]->data - 1);
//   for(size_t i = 0; i < neighs.size(); ++i) {
//     int colors[3] = {0, 0, 0};
//     if(vertexType(findVertex(neighs[i]->data - 1, nullptr), colors) == 1) {
//       printf("is triple \n");
//       std::vector<PolyMesh::Vertex *> new_ns;
//       findDoubleNeighbours(neighs[i], &new_ns, dominant_color);
//       if(new_ns[0]->data == vertex->data) { ns->push_back(new_ns[1]); }
//       else {
//         ns->push_back(new_ns[0]);
//       }
//     }
//     else {
//       printf("not triple\n");
//       printf("neighs[%lu]->data = %d\n", i, neighs[i]->data);
//       ns->push_back(neighs[i]);
//     }
//   }
//   if(ns->size() != 2 || ns->at(0) == nullptr || ns->at(1) == nullptr) {
//     printf("error in findDoubleNeighbours :n1 == nullptr || n2 ==
//     nullptr\n"); printf("ns->size() = %lu\n", ns->size());
//     printf("ns->at(0)-> data = %d \n", ns->at(0)->data);
//     printf("ns->at(1)-> data = %d \n", ns->at(1)->data);
//   }
//   else {
//     printf(" out of double : %d %d\n", ns->at(0)->data - 1,
//      ns->at(1)->data - 1);
//   }
//   return;
// }

void discreteFront::findNDoubleNeighbours(PolyMesh::Vertex *vertex,
                                          std::vector<PolyMesh::Vertex *> *ns,
                                          size_t n, int dominant_color, bool with_triple)
{
  PolyMesh::HalfEdge *he_pos = nullptr;
  PolyMesh::HalfEdge *he_neg = nullptr;

  // find first half edges
  PolyMesh::HalfEdge *he = vertex->he;
  PolyMesh::HalfEdge *bnd_he = nullptr;

  do {
    if(he->opposite == nullptr){
      bnd_he = he;
      break;
    }
    if(he->f->data == dominant_color && he->opposite->f->data != dominant_color) {
      he_pos = he;
    }
    else if(he->f->data != dominant_color && he->opposite->f->data == dominant_color) {
      he_neg = he->opposite;
    }
    he = he->opposite->next;
  } while(he != vertex->he);

  if(bnd_he!=nullptr){
    he = bnd_he;
    if(dominant_color==-10){
      he_pos = he;
    } else if (he->f->data == dominant_color){
      he_pos = he;
    } 

    do {
      if(he->next->next->opposite == nullptr) {
        he_neg = he->next->next;
        break;
      }

      he = he->next->next->opposite;

      if(he->f->data == dominant_color && he->opposite->f->data != dominant_color) {
        he_pos = he;
      }
      else if(he->f->data != dominant_color && he->opposite->f->data == dominant_color) {
        he_neg = he;
      }
        
      
    } while(he != nullptr);
  }

  if(he_pos == nullptr || he_neg == nullptr) {
    printf("error in findNDoubleNeighbours :he_pos == nullptr || he_neg == "
           "nullptr\n");
    exit(1);
  }

  // go in the direction of the first he and stock neighbours
  ns->clear();
  ns->resize(2 * n + 1);
  ns->at(n) = vertex;
  he = he_pos;
  for(size_t i = 0; i < n; ++i) {
    PolyMesh::HalfEdge *old_he = he;
    int colors[3] = {0, 0, 0};
    int triple_ =
      vertexType(findVertex(he->next->v->data - 1, nullptr), colors);
    if(triple_ == 1 && with_triple==false) { i--; }
    else {
      ns->at(n + i + 1) = he->next->v;
    }

    do {
      if(he->next->opposite == nullptr) {
        he = he->next;
        break;
      }
      else if(he->next->f->data == dominant_color &&
              he->next->opposite->f->data != dominant_color) {
        he = he->next;
        break;
      }
      he = he->next->opposite;
    } while(he != old_he);
  }

  // go in the direction of the second he and stock neighbours
  he = he_neg;
  for(size_t i = 0; i < n; ++i) {
    PolyMesh::HalfEdge *old_he = he;
    int colors[3] = {0, 0, 0};
    int triple_ = vertexType(findVertex(he->v->data - 1, nullptr), colors);
    if(triple_ == 1 && with_triple==false) { i--; }
    else {
      ns->at(n - i - 1) = he->v;
    }
    do {
      if(he->next->next->opposite == nullptr) {
        he = he->next->next;
        break;
      }
      else if(he->next->next->f->data == dominant_color &&
              he->next->next->opposite->f->data != dominant_color) {
        he = he->next->next;
        break;
      }
      he = he->next->next->opposite;
    } while(he != old_he);
  }

  return;
}

void discreteFront::switchMarkers(int dominant, size_t m, size_t next,
                                  int direction)
{
  // check for all interface
  for(size_t i = 0; i < interfaces.size(); ++i) {
    size_t n = interfaces[i].markers.size();
    auto it =
      std::find(interfaces[i].markers.begin(), interfaces[i].markers.end(), m);
    if(it == interfaces[i].markers.end()) continue;
    size_t id_m = it - interfaces[i].markers.begin();
    auto it_next = std::find(interfaces[i].markers.begin(),
                             interfaces[i].markers.end(), next);
    if(interfaces[i].tag == dominant) { // dominant interface -> switch
      size_t id_next = it_next - interfaces[i].markers.begin();
      interfaces[i].markers[id_m] = next;
      interfaces[i].markers[id_next] = m;
    } else { // normal interface -> add or delete
      if(it_next == interfaces[i].markers.end()) { // add to markers
        size_t next_m_interface = interfaces[i].markers[(id_m + 1) % n];
        PolyMesh::Vertex *v;
        int id_pm = findVertex(next_m_interface, v);
        int colors[3] = {0, 0, 0};
        vertexType(id_pm, colors);
        if(colors[0] == dominant) {
          interfaces[i].markers.insert(it+1, next);
        }
        else {
          interfaces[i].markers.insert(it, next);
        }
      }
      else { // delete from markers
        interfaces[i].markers.erase(it_next);
      }
    }
  }
}

size_t discreteFront::nextDouble(size_t interface, size_t id_m, int direction)
{
  if(direction < 0)
    direction = -1;
  else
    direction = 1;

  size_t m = interfaces[interface].markers[id_m];
  PolyMesh::Vertex *v;
  int id_pm = findVertex(m, v);
  size_t n = interfaces[interface].markers.size();
  size_t m_next = interfaces[interface].markers[(id_m + direction + n) % n];
  size_t iter = 2;
  int colors[3] = {0, 0, 0};
  while(vertexType(id_pm, colors) == 1) {
    m_next = interfaces[interface].markers[(id_m + iter * direction + n) % n];
    iter++;
  }
  return m_next;
}

int discreteFront::findVertex(size_t i, PolyMesh::Vertex *v)
{
  for(size_t j = 0; j < pm->vertices.size(); ++j) {
    if(pm->vertices[j]->data == i + 1) {
      v = pm->vertices[j];
      return j;
    }
  }
  return -1;
}

void discreteFront::buildSpatialSearchStructure()
{
  if(empty()) return;
  for(size_t i = 0; i < pos.size(); i += 3) {
    bbox += SPoint3(pos[i], pos[i + 1], pos[i + 2]);
  }

  sss.clear();
  sss.resize(NX * NY);
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t n_m = interfaces[i].markers.size();
      size_t m = interfaces[i].markers[j];
      size_t mp1 = interfaces[i].markers[(j + 1) % n_m];

      int IX, IY, JX, JY;
      getCoordinates(pos[3 * m], pos[3 * m + 1], IX, IY);
      getCoordinates(pos[3 * mp1], pos[3 * mp1 + 1], JX, JY);
      for(size_t I = std::min(IX, JX); I <= std::max(IX, JX); I++) {
        for(size_t J = std::min(IY, JY); J <= std::max(IY, JY); J++) {
          sss[I + J * NX].push_back(std::make_pair(i, std::make_pair(m, mp1)));
        }
      }
    }
  }
  // for(size_t j = 0; j < boundary->markers.size(); ++j) {
  //   size_t n_m = boundary->markers.size();
  //   size_t m = boundary->markers[j];
  //   size_t mp1 = boundary->markers[(j + 1) % n_m];

  //   int IX, IY, JX, JY;
  //   getCoordinates(pos[3 * m], pos[3 * m + 1], IX, IY);
  //   getCoordinates(pos[3 * mp1], pos[3 * mp1 + 1], JX, JY);
  //   for(size_t I = std::min(IX, JX); I <= std::max(IX, JX); I++) {
  //     for(size_t J = std::min(IY, JY); J <= std::max(IY, JY); J++) {
  //       sss[I + J * NX].push_back(std::make_pair(-1, std::make_pair(m,
  //       mp1)));
  //     }
  //   }
  // }

  return;
}

void discreteFront::buildSpatialSearchStructureInit()
{
  if(empty()) return;
  for(size_t i = 0; i < pos.size(); i += 3) {
    bbox += SPoint3(pos[i], pos[i + 1], pos[i + 2]);
  }

  sss.clear();
  sss.resize(NX * NY);
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t n_m = interfaces[i].markers.size();
      if(interfaces[i].loop == false && j == n_m - 1) continue;
      size_t m = interfaces[i].markers[j];
      size_t mp1 = interfaces[i].markers[(j + 1) % n_m];

      int IX, IY, JX, JY;
      getCoordinates(pos[3 * m], pos[3 * m + 1], IX, IY);
      getCoordinates(pos[3 * mp1], pos[3 * mp1 + 1], JX, JY);
      for(size_t I = std::min(IX, JX); I <= std::max(IX, JX); I++) {
        for(size_t J = std::min(IY, JY); J <= std::max(IY, JY); J++) {
          sss[I + J * NX].push_back(std::make_pair(i, std::make_pair(m, mp1)));
        }
      }
    }
  }
  for(size_t j = 0; j < boundary->markers.size(); ++j) {
    size_t n_m = boundary->markers.size();
    size_t m = boundary->markers[j];
    size_t mp1 = boundary->markers[(j + 1) % n_m];

    int IX, IY, JX, JY;
    getCoordinates(pos[3 * m], pos[3 * m + 1], IX, IY);
    getCoordinates(pos[3 * mp1], pos[3 * mp1 + 1], JX, JY);
    for(size_t I = std::min(IX, JX); I <= std::max(IX, JX); I++) {
      for(size_t J = std::min(IY, JY); J <= std::max(IY, JY); J++) {
        sss[I + J * NX].push_back(std::make_pair(-1, std::make_pair(m, mp1)));
      }
    }
  }

  return;
}

void discreteFront::removeFromSpatialSearchStructure(
  std::pair<int, std::pair<size_t, size_t>> edge)
{
  size_t m = edge.second.first;
  size_t mp1 = edge.second.second;
  double a1[2] = {pos[3 * m], pos[3 * m + 1]};
  double a2[2] = {pos[3 * mp1], pos[3 * mp1 + 1]};
  int IMIN, IMAX, JMIN, JMAX;
  getCoordinates(std::min(a1[0], a2[0]), std::min(a1[1], a2[1]), IMIN, JMIN);
  getCoordinates(std::max(a1[0], a2[0]), std::max(a1[1], a2[1]), IMAX, JMAX);
  for(size_t I = IMIN; I <= IMAX; I++) {
    for(size_t J = JMIN; J <= JMAX; J++) {
      size_t index = I + NX * J;
      auto it = std::find(sss[index].begin(), sss[index].end(), edge);
      if(it != sss[index].end()) sss[index].erase(it);
    }
  }
}

void discreteFront::addToSpatialSearchStructure(
  std::pair<int, std::pair<size_t, size_t>> edge)
{
  int i = edge.first;
  size_t m = edge.second.first;
  size_t mp1 = edge.second.second;
  double a1[2] = {pos[3 * m], pos[3 * m + 1]};
  double a2[2] = {pos[3 * mp1], pos[3 * mp1 + 1]};
  int IMIN, IMAX, JMIN, JMAX;
  getCoordinates(std::min(a1[0], a2[0]), std::min(a1[1], a2[1]), IMIN, JMIN);
  getCoordinates(std::max(a1[0], a2[0]), std::max(a1[1], a2[1]), IMAX, JMAX);
  for(size_t I = IMIN; I <= IMAX; I++) {
    for(size_t J = JMIN; J <= JMAX; J++) {
      sss[I + J * NX].push_back(std::make_pair(i, std::make_pair(m, mp1)));
    }
  }
}

void discreteFront::intersectInterfaces(bool bnd)
{
  std::vector<std::pair<int, std::pair<size_t, size_t>>> todo;
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t n_m = interfaces[i].markers.size();
      if(interfaces[i].loop == false && j == n_m - 1) continue;
      size_t m = interfaces[i].markers[j];
      size_t mp1 = interfaces[i].markers[(j + 1) % n_m];
      todo.push_back(std::make_pair(i, std::make_pair(m, mp1)));
    }
  }
  if(bnd) {
    for(size_t j = 0; j < boundary->markers.size(); ++j) {
      size_t n_m = boundary->markers.size();
      size_t m = boundary->markers[j];
      size_t mp1 = boundary->markers[(j + 1) % n_m];
      todo.push_back(std::make_pair(-1, std::make_pair(m, mp1)));
    }
  }

  size_t debug_counter = 0;

  while(todo.size() > 0) {
    std::pair<int, std::pair<size_t, size_t>> edge = todo.back();
    todo.pop_back();

    int i = edge.first;
    size_t m = edge.second.first;
    size_t mp1 = edge.second.second;
    interface interface_i = i == -1 ? *boundary : interfaces[i];

    double a1[2] = {pos[3 * m], pos[3 * m + 1]};
    double a2[2] = {pos[3 * mp1], pos[3 * mp1 + 1]};

    int IMIN, IMAX, JMIN, JMAX;
    getCoordinates(std::min(a1[0], a2[0]), std::min(a1[1], a2[1]), IMIN, JMIN);
    getCoordinates(std::max(a1[0], a2[0]), std::max(a1[1], a2[1]), IMAX, JMAX);
    std::set<std::pair<size_t, std::pair<int, int>>> touched;
    bool found = false;
    for(size_t I = IMIN; I <= IMAX; I++) {
      for(size_t J = JMIN; J <= JMAX; J++) {
        size_t index = I + NX * J;

        for(auto s : sss[index]) {
          int s_i = s.first;
          size_t s_m = s.second.first;
          size_t s_mp1 = s.second.second;

          if(touched.find(s) != touched.end()) continue;
          touched.insert(s);
          if(i > s_i)
            continue; // only compute once intersections and allow interface
                      // auto-intersecion
          if(s_m == m || s_m == mp1 || s_mp1 == m || s_mp1 == mp1)
            continue; // don't compute intersection with himself

          if(i == s_i) { // compute auto-intersection only once
            size_t it_s = std::find(interface_i.markers.begin(),
                                    interface_i.markers.end(), s_m) -
                          interface_i.markers.begin();
            size_t it = std::find(interface_i.markers.begin(),
                                  interface_i.markers.end(), m) -
                        interface_i.markers.begin();
            if(it_s > it) continue;
          }

          double a3[2] = {pos[3 * s_m], pos[3 * s_m + 1]};
          double a4[2] = {pos[3 * s_mp1], pos[3 * s_mp1 + 1]};
          double inter[2] = {0, 0};
          double param[1] = {0};
          int b_inter = computeIntersection(a1, a2, a3, a4, inter, param);
          if(b_inter) {
            debug_counter++;
            if(debug_counter > 10) {
              printf("debug_counter = %lu\n", debug_counter);
              // exit(1);
            }
            
            // add new marker
            size_t new_m = pos.size() / 3;
            pos.push_back(inter[0]);
            pos.push_back(inter[1]);
            pos.push_back(0);

            if(interface_i.tag != interfaces[s_i].tag) {
              if(interface_i.tag < interfaces[s_i].tag){
                std::pair<size_t, std::pair<size_t, size_t>> p_m;
                p_m = std::make_pair(m, std::make_pair(new_m, mp1));
                on_edge_triples.push_back(p_m);
              } else {
                std::pair<size_t, std::pair<size_t, size_t>> p_m;
                p_m = std::make_pair(s_m, std::make_pair(new_m, s_mp1));
                on_edge_triples.push_back(p_m);
              }
            }

            // add and remove edge for m and mp1
            for(size_t c = 0; c < 2; ++c) {
              size_t m_ = c == 0 ? m : s_m;
              size_t mp1_ = c == 0 ? mp1 : s_mp1;
              for(int in = 0; in < interfaces.size(); in++) {
                // find all occurence of m and mp1 in the interface
                std::vector<size_t> occ_m;
                auto it_m = std::find(interfaces[in].markers.begin(),
                                      interfaces[in].markers.end(), m_);
                while(it_m != interfaces[in].markers.end()) {
                  occ_m.push_back(it_m - interfaces[in].markers.begin());
                  it_m = std::find(it_m + 1, interfaces[in].markers.end(), m_);
                }

                std::vector<size_t> occ_mp1;
                auto it_mp1 = std::find(interfaces[in].markers.begin(),
                                        interfaces[in].markers.end(), mp1_);
                while(it_mp1 != interfaces[in].markers.end()) {
                  occ_mp1.push_back(it_mp1 - interfaces[in].markers.begin());
                  it_mp1 =
                    std::find(it_mp1 + 1, interfaces[in].markers.end(), mp1_);
                }

                for(size_t k1 = 0; k1 < occ_m.size(); ++k1) {
                  for(size_t k2 = 0; k2 < occ_mp1.size(); ++k2) {
                    size_t m1, m2;
                    size_t id1 = occ_m[k1];
                    size_t id2 = occ_mp1[k2];
                    size_t n = interfaces[in].markers.size();

                    if(id2 == (id1 + 1) % n) {
                      m1 = m_;
                      m2 = mp1_;
                    }
                    else if(id1 == (id2 + 1) % n) {
                      m1 = mp1_;
                      m2 = m_;
                      id1 = id2;
                    }
                    else {
                      printf("not found in interface %d for %lu, %lu \n", in,
                             m_, mp1_);
                      printf("id1 = %lu, id2 = %lu \n", id1, id2);
                      continue;
                    }

                    // add new marker in the interfaces
                    interfaces[in].markers.insert(
                      interfaces[in].markers.begin() + id1 + 1, new_m);

                    // remove edges in the todo list
                    auto it =
                      std::find(todo.begin(), todo.end(),
                                std::make_pair(in, std::make_pair(m1, m2)));
                    if(it != todo.end()) todo.erase(it);

                    // add new edges in the todo list
                    todo.push_back(
                      std::make_pair(in, std::make_pair(m1, new_m)));
                    todo.push_back(
                      std::make_pair(in, std::make_pair(new_m, m2)));

                    // remove old edges spatial search
                    removeFromSpatialSearchStructure(
                      std::make_pair(in, std::make_pair(m1, m2)));

                    // add new edges spatial search
                    addToSpatialSearchStructure(
                      std::make_pair(in, std::make_pair(m1, new_m)));
                    addToSpatialSearchStructure(
                      std::make_pair(in, std::make_pair(new_m, m2)));
                    
                  }
                }
              }
              if(bnd == true) {
                // find all occurence of m and mp1 in the interface
                std::vector<size_t> occ_m;
                auto it_m = std::find(boundary->markers.begin(),
                                      boundary->markers.end(), m_);
                while(it_m != boundary->markers.end()) {
                  occ_m.push_back(it_m - boundary->markers.begin());
                  it_m = std::find(it_m + 1, boundary->markers.end(), m_);
                }

                std::vector<size_t> occ_mp1;
                auto it_mp1 = std::find(boundary->markers.begin(),
                                        boundary->markers.end(), mp1_);
                while(it_mp1 != boundary->markers.end()) {
                  occ_mp1.push_back(it_mp1 - boundary->markers.begin());
                  it_mp1 = std::find(it_mp1 + 1, boundary->markers.end(), mp1_);
                }

                for(size_t k1 = 0; k1 < occ_m.size(); ++k1) {
                  for(size_t k2 = 0; k2 < occ_mp1.size(); ++k2) {
                    size_t m1, m2;
                    size_t id1 = occ_m[k1];
                    size_t id2 = occ_mp1[k2];
                    size_t n = boundary->markers.size();
                    
                    if(id2 == (id1 + 1) % n) {
                      m1 = m_;
                      m2 = mp1_;
                    }
                    else if(id1 == (id2 + 1) % n) {
                      m1 = mp1_;
                      m2 = m_;
                      id1 = id2;
                    }
                    else {
                      printf("not found in bnd for %lu, %lu \n", m_, mp1_);
                      printf("id1 = %lu, id2 = %lu \n", id1, id2);
                      continue;
                    }

                    // add new marker in the interfaces
                    boundary->markers.insert(
                      boundary->markers.begin() + id1 + 1, new_m);

                    // // remove edges in the todo list
                    auto it =
                      std::find(todo.begin(), todo.end(),
                                std::make_pair(-1, std::make_pair(m1, m2)));
                    if(it != todo.end()) todo.erase(it);

                    // add new edges in the todo list
                    todo.push_back(
                      std::make_pair(-1, std::make_pair(m1, new_m)));
                    todo.push_back(
                      std::make_pair(-1, std::make_pair(new_m, m2)));

                    // remove old edges spatial search
                    removeFromSpatialSearchStructure(
                      std::make_pair(-1, std::make_pair(m1, m2)));

                    // add new edges spatial search
                    addToSpatialSearchStructure(
                      std::make_pair(-1, std::make_pair(m1, new_m)));
                    addToSpatialSearchStructure(
                      std::make_pair(-1, std::make_pair(new_m, m2)));
                  }
                }
              }
            }
            found = true;
            break;
          }
        }
        if(found) break;
      }
      if(found) break;
    }
  }
}

void discreteFront::addFreeForm(int tag, const std::vector<SVector3> &poly,
                                const std::vector<size_t> &_corners, bool loop)
{
  std::vector<double> p;
  for(size_t k = 0; k < poly.size(); k++) {
    SVector3 p0 = poly[k];
    p.push_back(p0.x());
    p.push_back(p0.y());
    p.push_back(0.);
  }
  discreteFront::instance()->addInterface(p, tag, _corners, loop);
}

void discreteFront::triangulateInterfaces()
{
  size_t max_marker = getMaxMarker();
  std::vector<bool> visited(max_marker + 1, false);
  std::vector<int> pos2m(max_marker + 1, -1);
  std::vector<int> m2pos(max_marker + 1, -1);

  std::vector<double> pos2d;
  std::vector<size_t> rec;

  std::vector<bool> bool_edge_triple = std::vector<bool>(max_marker + 1, false);
  std::vector<bool> bool_triple = std::vector<bool>(max_marker + 1, false);
  for(size_t i = 0; i < triple_points.size(); ++i) {
    bool_triple[triple_points[i]] = true;
  }
  for(size_t i = 0; i < on_edge_triples.size(); ++i) {
    bool_edge_triple[on_edge_triples[i].first] = true;
    bool_edge_triple[on_edge_triples[i].second.second] = true;
  }

  for(size_t i = 0; i < interfaces.size(); ++i) {
    size_t n_m = interfaces[i].markers.size();
    for(size_t j = 0; j < n_m; ++j) {
      visited[interfaces[i].markers[j]] = true;
      if(interfaces[i].markers[j] == interfaces[i].markers[(j + 1) % n_m])
        continue;

      if(bool_triple[interfaces[i].markers[j]] &&
         bool_triple[interfaces[i].markers[(j + 1) % n_m]])
        continue;
      if(bool_edge_triple[interfaces[i].markers[j]] &&
         bool_triple[interfaces[i].markers[(j + 1) % n_m]])
        continue;
      if(bool_edge_triple[interfaces[i].markers[(j + 1) % n_m]] &&
         bool_triple[interfaces[i].markers[j]])
        continue;

      rec.push_back(interfaces[i].markers[j]);
      rec.push_back(interfaces[i].markers[(j + 1) % n_m]);
    }
  }
  
  for(size_t i = 0; i < max_marker + 1; ++i) {
    if(visited[i]) {
      pos2m[pos2d.size() / 2] = i;
      m2pos[i] = pos2d.size() / 2;
      pos2d.push_back(pos[3 * i]);
      pos2d.push_back(pos[3 * i + 1]);
    }
  }

  // check if there is triple nodes on the same edge and correct rec if needed
  std::vector<bool> done = std::vector<bool>(on_edge_triples.size(), false);
  std::vector<std::vector<size_t>> edges_with_triples;
  if(on_edge_triples.size() > 0) {
    for(size_t i = 0; i < on_edge_triples.size(); ++i) {
      if(done[i]) continue;
      done[i] = true;
      size_t m1 = on_edge_triples[i].first;
      size_t m2 = on_edge_triples[i].second.second;
      size_t triple_ = on_edge_triples[i].second.first;
      std::vector<size_t> temp = {m1, triple_, m2};
      size_t n_edges_ = edges_with_triples.size();
      edges_with_triples.push_back(temp);
      if (i == on_edge_triples.size() - 1) {
        break;
      }
      for(size_t j = i + 1; j < on_edge_triples.size(); ++j) {
        if(done[j]) continue;
        size_t m3 = on_edge_triples[j].first;
        size_t m4 = on_edge_triples[j].second.second;
        if(m1 == m3 && m2 == m4) {
          done[j] = true;
          edges_with_triples[n_edges_].insert(std::prev(edges_with_triples[n_edges_].end(),1),
                                       on_edge_triples[j].second.first);
        }
      }
    }

    for(size_t i = 0; i < edges_with_triples.size(); ++i) {
      size_t m1 = edges_with_triples[i][0];
      size_t m2 = edges_with_triples[i][edges_with_triples[i].size() - 1];
      size_t n_m = edges_with_triples[i].size();
      std::vector<std::pair<double, size_t>> parametric_t;
      for(size_t j = 1; j < n_m - 1; ++j) {
        size_t m = edges_with_triples[i][j];
        double dm1_2 = (pos[3 * m1] - pos[3 * m]) * (pos[3 * m1] - pos[3 * m]) +
                       (pos[3 * m1 + 1] - pos[3 * m + 1]) *
                         (pos[3 * m1 + 1] - pos[3 * m + 1]);
        double dm2_2 = (pos[3 * m2] - pos[3 * m]) * (pos[3 * m2] - pos[3 * m]) +
                       (pos[3 * m2 + 1] - pos[3 * m + 1]) *
                         (pos[3 * m2 + 1] - pos[3 * m + 1]);
        double dm1 = sqrt(dm1_2);
        double dm2 = sqrt(dm2_2);
        double t = dm1 / (dm1 + dm2);
        parametric_t.push_back(std::make_pair(t, j));
      }

      std::sort(parametric_t.begin(), parametric_t.end(),
                [](std::pair<double, size_t> a, std::pair<double, size_t> b) {
                  return a.first < b.first;
                });
    }
  }

  std::vector<size_t> rec_mapped;
  for(size_t i = 0; i < rec.size(); ++i) {
    rec_mapped.push_back(m2pos[rec[i]]);
  }

  size_t n_m = pos2d.size() / 2;
  SBoundingBox3d bbTri = bbox;
  bbTri *= 1.3;
  pos2d.push_back(bbTri.min().x());
  pos2d.push_back(bbTri.min().y());
  pos2d.push_back(bbTri.max().x());
  pos2d.push_back(bbTri.min().y());
  pos2d.push_back(bbTri.max().x());
  pos2d.push_back(bbTri.max().y());
  pos2d.push_back(bbTri.min().x());
  pos2d.push_back(bbTri.max().y());

  std::vector<size_t> tri;
  meshTriangulate2d(pos2d, tri, &rec_mapped);
  for(size_t i = 0; i < tri.size(); i += 3) {
    if(tri[i] > n_m || tri[i + 1] > n_m || tri[i + 2] > n_m) {
      tri.erase(tri.begin() + i, tri.begin() + i + 3);
      i -= 3;
      continue;
    }
    double rotation = robustPredicates::orient2d(&pos2d[2 * (tri[i] - 1)],
                                                 &pos2d[2 * (tri[i + 1] - 1)],
                                                 &pos2d[2 * (tri[i + 2] - 1)]);
    if(rotation < 0) {
      size_t tmp = tri[i];
      tri[i] = tri[i + 1];
      tri[i + 1] = tmp;
    }
  }

  pm->reset();
  triangulation2PolyMesh(tri, pos2d, &pm);

  std::sort(pm->vertices.begin(), pm->vertices.end(),
            [](PolyMesh::Vertex *v1, PolyMesh::Vertex *v2) {
              return v1->data < v2->data;
            });
  for(size_t i = 0; i < pm->vertices.size(); ++i) {
    pm->vertices[i]->data = pos2m[i] + 1;
  }
}

void discreteFront::colorTriangles(bool bnd)
{
  if(Tree == nullptr) { createTree(); }
  
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    PolyMesh::Face *face = pm->faces[i];
    face->data = -10;

    double center[2] = {0, 0};
    center[0] = (face->he->v->position.x() + face->he->next->v->position.x() +
                 face->he->next->next->v->position.x()) /
                3.0;
    center[1] = (face->he->v->position.y() + face->he->next->v->position.y() +
                 face->he->next->next->v->position.y()) /
                3.0;
    if(bnd){
      if(insideList(boundary->markers, center) == -1) {
        pm->faces[i]->data = -10;
        printf("i'm here : outside bnd \n");
        continue;
      }
    }
    

    TreeNode *current = Tree;
    std::vector<TreeNode *> stack;
    while(true) {
      stack.clear();
      for(size_t l = 0; l < current->leafs.size(); ++l) {
        std::vector<size_t> markers = interfaces[current->leafs[l]->id].markers;
        if(insideList(markers, center) == 1) {
          stack.push_back(current->leafs[l]);
        }
      }

      if(stack.size() == 0) { break; }
      else if(stack.size() == 1) {
        current = stack[0];
      }
      else {
        size_t priority_level = 100;
        size_t id_interface_prior;
        for(size_t l = 0; l < stack.size(); ++l) {
          size_t priority_l =
            std::find(priority.begin(), priority.end(), stack[l]->tag) -
            priority.begin();
          if(priority_l < priority_level) {
            priority_level = priority_l;
            id_interface_prior = l;
          }
        }
        if(priority_level == 100) {
          printf("error priority \n");
          exit(0);
        }
        else {
          current = stack[id_interface_prior];
        }
      }
    }

    pm->faces[i]->data = current->tag;
  }

  // keep only the triangles that are inside the domain
  std::vector<size_t> tri;
  std::vector<int> tri_tag;
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    if(pm->faces[i]->data != -10) {
      tri.push_back(pm->faces[i]->he->v->data);
      tri.push_back(pm->faces[i]->he->next->v->data);
      tri.push_back(pm->faces[i]->he->next->next->v->data);
      tri_tag.push_back(pm->faces[i]->data);
    }
  }
  std::vector<double> pos2d;
  for(size_t i = 0; i < pos.size(); i += 3) {
    pos2d.push_back(pos[i]);
    pos2d.push_back(pos[i + 1]);
  }
  pm->reset();
  triangulation2PolyMesh(tri, pos2d, &pm);
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    pm->faces[i]->data = tri_tag[i];
  }

  for(size_t i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->hedges[i];
    PolyMesh::Vertex *v1 = he->v;
    PolyMesh::Vertex *v2 = he->next->v;

    double dist = (v1->position - v2->position).norm();
    if(dist > 1e-6) continue;
    if(he->opposite == nullptr) continue;
    if(he->f->data != he->opposite->f->data) continue;
    int edge_type = he->f->data;
    if(edge_type < 0) continue;

    PolyMesh::Vertex *v;
    int id1 = findVertex(v1->data - 1, v);
    int id2 = findVertex(v2->data - 1, v);
    int colors1[3] = {0, 0, 0};
    int colors2[3] = {0, 0, 0};
    int triple1 = vertexType(id1, colors1);
    int triple2 = vertexType(id2, colors2);
    if(triple1 == 1 || triple2 == 1) continue;

    int dom_color = -1;
    if(colors1[0] < 0 && colors2[0] < 0) continue;
    if(colors1[0] < 0) { dom_color = colors2[0]; }
    else if(colors2[0] < 0) {
      dom_color = colors1[0];
    }
    else {
      dom_color = std::min(colors1[0], colors2[0]);
    }

    // color neighbours triangles of v1 and v2 with dom_color
    for(size_t j = 0; j < 2; ++j) {
      PolyMesh::Vertex *v = j == 0 ? v1 : v2;
      PolyMesh::HalfEdge *current = v->he;
      PolyMesh::HalfEdge *bnd = nullptr;
      do {
        if(current->opposite == nullptr) {
          bnd = current;
          break;
        }
        if(current->f->data == edge_type) { current->f->data = dom_color; }
        current = current->opposite->next;
      } while(current != v1->he);
      if(bnd != nullptr) {
        current = bnd;
        do {
          if(current->f->data == edge_type) { current->f->data = dom_color; }
          current = current->next;
        } while(current != bnd);
      }
    }
  }
}

void discreteFront::computeNewInterfaces()
{
  std::vector<std::vector<size_t>> new_loops;
  std::vector<interface> new_interfaces;
  std::vector<int> interface_tag;

  std::vector<bool> visited_hedge(pm->hedges.size(), false);
  for(size_t i = 0; i < pm->hedges.size(); ++i) { pm->hedges[i]->data = i; }

  for(size_t i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm->hedges[i];
    if(visited_hedge[he->data]) continue;
    if(he->opposite != nullptr) {
      if(he->opposite->f->data == he->f->data) continue;
    }

    std::vector<PolyMesh::HalfEdge *> loop_he;
    std::vector<size_t> loop_v;
    rotate_pm(he, &loop_he, &loop_v);
    for(auto h : loop_he) { visited_hedge[h->data] = true; }

    // check if loop is counter clockwise
    std::vector<double> loop_pos;
    for(size_t j = 0; j < loop_v.size(); ++j) {
      loop_v[j] = loop_v[j] - 1;
      loop_pos.push_back(pos[3 * loop_v[j]]);
      loop_pos.push_back(pos[3 * loop_v[j] + 1]);
    }
    
    int clock = clockwise(loop_pos);
    if(clock == -1) {
      new_loops.push_back(loop_v);
      interface_tag.push_back(he->f->data);
    }
    else {
      // printf("clockwise loop : %d \n", loop_v.size());
      // for(size_t j = 0; j < loop_v.size(); ++j) { printf("%lu, ", loop_v[j]); }
      // printf("\n");

      // printf("loop pos \n");
      // for(size_t j = 0; j < loop_pos.size(); ++j) {
      //   printf("%f, ", loop_pos[j]);
      // }
      // printf("\n");
    }
  }

  for(size_t i = 0; i < new_loops.size(); ++i) {
    for(size_t j = 0; j < new_loops[i].size(); ++j) {
      new_loops[i][j] = new_loops[i][j];
    }
    new_interfaces.push_back(
      interface(i, interface_tag[i], new_loops[i], true));
  }

  interfaces = new_interfaces;

  triple_points.clear();
  size_t max_m = getMaxMarker();
  std::vector<bool> visited(max_m + 1, false);
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t m = interfaces[i].markers[j];
      if(visited[m]) continue;
      visited[m] = true;
      PolyMesh::Vertex *dummy;
      int id = findVertex(m, dummy);
      int colors[3] = {0, 0, 0};
      if(vertexType(id, colors) == 1) { triple_points.push_back(m); }
    }
  }
}

void discreteFront::rotate_pm(PolyMesh::HalfEdge *start,
                              std::vector<PolyMesh::HalfEdge *> *loop_he,
                              std::vector<size_t> *loop_v)
{
  int color = start->f->data;
  PolyMesh::HalfEdge *current = start;
  while(true) {
    loop_he->push_back(current);
    loop_v->push_back(current->v->data);

    while(true) {
      if(current->next->opposite == nullptr) {
        current = current->next;
        break;
      }
      else if(current->next->opposite->f->data != color) {
        current = current->next;
        break;
      }
      else {
        current = current->next->opposite;
      }
    }

    if(current == start) break;
  }
}

void discreteFront::rotate_pm_vertex(
  PolyMesh::HalfEdge *start, std::vector<PolyMesh::HalfEdge *> *loop_he,
  std::vector<PolyMesh::Vertex *> *loop_vertex)
{
  int color = start->f->data;
  PolyMesh::HalfEdge *current = start;
  while(true) {
    loop_he->push_back(current);
    loop_vertex->push_back(current->v);

    while(true) {
      if(current->next->opposite == nullptr) {
        current = current->next;
        break;
      }
      else if(current->next->opposite->f->data != color) {
        current = current->next;
        break;
      }
      else {
        current = current->next->opposite;
      }
    }

    if(current == start) break;
  }
}

void discreteFront::createTree()
{
  TreeNode *init = newTreeNode(-1, boundary->tag);
  for(size_t i = 0; i < interfaces.size(); ++i) {
    TreeNode *node_i = newTreeNode(i, interfaces[i].tag);
    init->leafs.push_back(node_i);
  }

  std::vector<TreeNode *> todo;
  std::vector<TreeNode *> new_todo;
  todo.push_back(init);
  while(todo.size() > 0) {
    for(size_t td = 0; td < todo.size(); td++) {
      TreeNode *level = todo[td];
      for(size_t i = 0; i < level->leafs.size(); ++i) {
        for(size_t j = 0; j < level->leafs.size(); ++j) {
          if(j == i) continue;
          size_t iter = 0;
          int inside = 0;
          while(inside == 0) {
            inside = insideList(
              interfaces[level->leafs[j]->id].markers,
              &pos[3 * interfaces[level->leafs[i]->id].markers[iter]]);
            iter++;
            if(iter == interfaces[level->leafs[i]->id].markers.size()) {
              break;
            }
          }
          if(inside == 1) {
            level->leafs[j]->leafs.push_back(level->leafs[i]);
            level->leafs.erase(level->leafs.begin() + i);
            i--;
            new_todo.push_back(level->leafs[j]);
            break;
          }
        }
      }
    }
    todo = new_todo;
    new_todo.clear();
  }
  Tree = init;
}

void discreteFront::printTree(TreeNode *node, int depth)
{
  if(!node) return;

  // Print the current node with indentation based on depth
  for(int i = 0; i < depth; ++i)
    printf(" "); // Indentation for visual hierarchy
  printf("id: %d, tag: %d\n", node->id, node->tag);

  // Recursively print each child node
  for(TreeNode *child : node->leafs) { printTree(child, depth + 1); }
}

int discreteFront::insideList(std::vector<size_t> loop, double P[2])
{
  int wn = 0;
  size_t n = loop.size();
  for(size_t i = 0; i < loop.size(); ++i) {
    double aa[2] = {pos[3 * loop[i]], pos[3 * loop[i] + 1]};
    double bb[2] = {pos[3 * loop[(i + 1) % n]], pos[3 * loop[(i + 1) % n] + 1]};
    if(aa[0] == P[0] && aa[1] == P[1]) return 0;
    if(bb[0] == P[0] && bb[1] == P[1]) return 0;
    double area = robustPredicates::orient2d(aa, bb, P);
    if(aa[1] <= P[1]) {
      if(bb[1] > P[1] && area < 0) wn++;
    }
    else if(bb[1] <= P[1]) {
      if(area > 0) wn--;
    }
  }
  if(wn < 0) { return 1; }
  return -1;
}

void discreteFront::printInterfaces(FILE *f)
{
  fprintf(f, "View \"Interface \" {\n");
  for(size_t i = 0; i < interfaces.size(); ++i) {
    size_t n_m = interfaces[i].markers.size();
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      fprintf(f, "SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
              pos[3 * interfaces[i].markers[j]],
              pos[3 * interfaces[i].markers[j] + 1],
              pos[3 * interfaces[i].markers[(j + 1) % n_m]],
              pos[3 * interfaces[i].markers[(j + 1) % n_m] + 1],
              interfaces[i].tag, interfaces[i].tag);
      fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%d'};\n",
              pos[3 * interfaces[i].markers[j]],
              pos[3 * interfaces[i].markers[j] + 1], interfaces[i].markers[j]);
    }
  }

  size_t n_m = boundary->markers.size();
  for(size_t j = 0; j < boundary->markers.size(); ++j) {
    fprintf(f, "SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
            pos[3 * boundary->markers[j]], pos[3 * boundary->markers[j] + 1],
            pos[3 * boundary->markers[(j + 1) % n_m]],
            pos[3 * boundary->markers[(j + 1) % n_m] + 1], boundary->tag,
            boundary->tag);
    fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%d'};\n",
            pos[3 * boundary->markers[j]], pos[3 * boundary->markers[j] + 1],
            boundary->markers[j]);
  }
  fprintf(f, "};\n");
}

void discreteFront::setBoundaryFromMesh(std::vector<double> *bnd_pos)
{
  // get the boundary from the mesh
  std::vector<std::pair<size_t, size_t>> bnd;
  meshRelaying::instance()->getBnd1d(&bnd);

  std::vector<size_t> loop;
  size_t start = bnd[0].first;
  size_t prev = start;
  size_t current = bnd[0].second;
  loop.push_back(start);
  loop.push_back(current);
  while(true) {
    auto it =
      std::find_if(bnd.begin(), bnd.end(), [&](std::pair<size_t, size_t> p) {
        if(p.first == current && p.second != prev) { return true; }
        else if(p.second == current && p.first != prev) {
          return true;
        }
        return false;
      });
    if(it == bnd.end()) { break; }

    if(it->first == current) {
      prev = current;
      current = it->second;
    }
    else {
      prev = current;
      current = it->first;
    }
    if(current == start) { break; }
    loop.push_back(current);
  }

  std::vector<double> nodes_positions;
  meshRelaying::instance()->getNodesPosition(nodes_positions);
  std::vector<double> pos2d;
  std::vector<size_t> markers_bnd;
  for(size_t i = 0; i < loop.size(); ++i) {
    pos.push_back(nodes_positions[3 * loop[i]]);
    pos.push_back(nodes_positions[3 * loop[i] + 1]);
    pos.push_back(0);
    bnd_pos->push_back(nodes_positions[3 * loop[i]]);
    bnd_pos->push_back(nodes_positions[3 * loop[i] + 1]);
    bnd_pos->push_back(0);
    markers_bnd.push_back(pos.size() / 3 - 1);

    pos2d.push_back(nodes_positions[3 * loop[i]]);
    pos2d.push_back(nodes_positions[3 * loop[i] + 1]);
  }

  int clock = clockwise(pos2d);
  if(clock == 1) { std::reverse(markers_bnd.begin(), markers_bnd.end()); }

  boundary->markers = markers_bnd;
}

void discreteFront::redistFront(double lc)
{
  std::vector<std::pair<size_t, size_t>> to_split;
  std::vector<std::vector<double>> to_add;
  std::vector<std::pair<size_t, size_t>> to_remove;

  std::vector<int> bnd_markers;
  getBndMarkers(&bnd_markers);

  std::vector<int> solid_markers;
  getSolidMarkers(&solid_markers);

  for(size_t i = 0; i < interfaces.size(); ++i) {
    size_t n_m = interfaces[i].markers.size();
    for(size_t j = 0; j < n_m; ++j) {
      size_t m1 = std::min(interfaces[i].markers[j],
                           interfaces[i].markers[(j + 1) % n_m]);
      size_t m2 = std::max(interfaces[i].markers[j],
                           interfaces[i].markers[(j + 1) % n_m]);

      if(bnd_markers[m1]==1 && bnd_markers[m2]==1) continue;
      if(solid_markers[m1]==1 && solid_markers[m2]==1) continue;

      double x1[2] = {pos[3 * m1], pos[3 * m1 + 1]};
      double x2[2] = {pos[3 * m2], pos[3 * m2 + 1]};
      double d = sqrt((x1[0] - x2[0]) * (x1[0] - x2[0]) +
                      (x1[1] - x2[1]) * (x1[1] - x2[1]));
      if(d > 1.5 * lc) { to_split.push_back(std::make_pair(m1, m2)); }
      else if(d < 0.1 * lc) {
        to_remove.push_back(std::make_pair(m1, m2));
      }
    }
  }
  std::sort(to_split.begin(), to_split.end());
  to_split.erase(std::unique(to_split.begin(), to_split.end()), to_split.end());
  std::sort(to_remove.begin(), to_remove.end());
  to_remove.erase(std::unique(to_remove.begin(), to_remove.end()),
                  to_remove.end());

  // add edges
  for(size_t i = 0; i < to_split.size(); ++i) {
    size_t id_new = pos.size() / 3;
    std::pair<size_t, size_t> s = to_split[i];
    size_t m1 = s.first;
    size_t m2 = s.second;

    double x1[2] = {pos[3 * m1], pos[3 * m1 + 1]};
    double x2[2] = {pos[3 * m2], pos[3 * m2 + 1]};
    double d = sqrt((x1[0] - x2[0]) * (x1[0] - x2[0]) +
                    (x1[1] - x2[1]) * (x1[1] - x2[1]));
    int n_to_add = int((d - 0.5 * lc) / lc);

    for(size_t j = 0; j < n_to_add; ++j) {
      pos.push_back(x1[0] + (j + 1) * (x2[0] - x1[0]) / (n_to_add + 1));
      pos.push_back(x1[1] + (j + 1) * (x2[1] - x1[1]) / (n_to_add + 1));
      pos.push_back(0);
    }
    for(size_t i = 0; i < interfaces.size(); ++i) {
      auto it1 = std::find(interfaces[i].markers.begin(),
                           interfaces[i].markers.end(), m1);
      auto it2 = std::find(interfaces[i].markers.begin(),
                           interfaces[i].markers.end(), m2);
      if(it1 == interfaces[i].markers.end() ||
         it2 == interfaces[i].markers.end())
        continue;

      size_t id1 = it1 - interfaces[i].markers.begin();
      size_t id2 = it2 - interfaces[i].markers.begin();
      size_t n = interfaces[i].markers.size();

      bool end1 = false;
      bool end2 = false;
      if(id1 == n - 1) { end1 = true; }
      if(id2 == n - 1) { end2 = true; }

      if((id1 + 1) % n == id2) {
        for(size_t j = 0; j < n_to_add; ++j) {
          if(end1) {
            interfaces[i].markers.push_back(id_new + j);
          }
          else {
            interfaces[i].markers.insert(it1 + 1 + j, id_new + j);
          }
        }
      }
      else if((id2 + 1) % n == id1) {
        for(size_t j = 0; j < n_to_add; ++j) {
          if(end2) {
            interfaces[i].markers.push_back(id_new + j);
          }
          else {
            interfaces[i].markers.insert(it2 + 1 + j,
                                         id_new + (n_to_add - 1 - j));
          }
        }
      }
    }
  }

  size_t max_m = getMaxMarker();
  std::vector<int> is_corner(max_m+1, 0);
  for(size_t c=0; c<corners.size(); c++) {
    is_corner[corners[c]] = 1;
  }

  // remove edges
  for(size_t i_r = 0; i_r < to_remove.size(); ++i_r) {
    std::pair<size_t, size_t> r = to_remove[i_r];
    size_t m1 = r.first;
    size_t m2 = r.second;
    double mean_pos[2] = {0.5 * (pos[3 * m1] + pos[3 * m2]),
                          0.5 * (pos[3 * m1 + 1] + pos[3 * m2 + 1])};

    if(is_corner[m1] == 1 || is_corner[m2] == 1) {
      continue;
    }
    int colors[3] = {0, 0, 0};
    PolyMesh::Vertex *v;
    int triple1 = vertexType(findVertex(m1, v), colors);
    int triple2 = vertexType(findVertex(m2, v), colors);

    if(triple1 == 1 || triple2 == 1) {
      continue;
    }

    for(size_t i = 0; i < interfaces.size(); ++i) {
      auto it1 = std::find(interfaces[i].markers.begin(),
                           interfaces[i].markers.end(), m1);
      auto it2 = std::find(interfaces[i].markers.begin(),
                           interfaces[i].markers.end(), m2);
      if(it1 == interfaces[i].markers.end() ||
         it2 == interfaces[i].markers.end())
        continue;

      size_t id1 = it1 - interfaces[i].markers.begin();
      size_t id2 = it2 - interfaces[i].markers.begin();
      size_t n = interfaces[i].markers.size();

      if(n < 4) continue;

      if((id1 + 1) % n != id2 && (id2 + 1) % n != id1) continue;

      if(triple1 != 1 && triple2 != 1) {
        pos[3 * m2] = mean_pos[0];
        pos[3 * m2 + 1] = mean_pos[1];
      }

      if(triple1 == 1) {
        int only_type2 = checkIfOnlyType(i, m2);
        if(only_type2 != 1) {
          interfaces[i].markers.erase(it2);
        }
      }
      else if(triple2 == 1) {
        int only_type1 = checkIfOnlyType(i, m1);
        if(only_type1 != 1) {
          interfaces[i].markers.erase(it1);
        }
      }
      else {
        int only_type1 = checkIfOnlyType(i, m1);
        if(only_type1 == 1) {
          int only_type2 = checkIfOnlyType(i, m2);
          if(only_type2 == 1) {
            printf("both are only type -> weird if their not triple... \n");
            continue;
          }
          else {
            interfaces[i].markers.erase(it2);
          }
        }
        else {
          interfaces[i].markers.erase(it1);
        }
      }
    }
  }

  triangulateInterfaces();
  colorTriangles();
}

int discreteFront::checkIfOnlyType(size_t id_interface, size_t marker)
{
  int colors_ref[3] = {0, 0, 0};
  PolyMesh::Vertex *v;
  int id_marker = findVertex(marker, v);
  if (id_marker == -1) {
    return 0;
  }
  int triple_ref = vertexType(id_marker, colors_ref);

  for(size_t j = 0; j < interfaces[id_interface].markers.size(); ++j) {
    if(interfaces[id_interface].markers[j] == marker) continue;
    int colors[3] = {0, 0, 0};
    int id = findVertex(interfaces[id_interface].markers[j], v);
    if(id == -1) {
      continue;
    }
    int triple = vertexType(id, colors);
    if(triple != triple_ref) { continue; }
    else {
      if(triple == 1) {
        if(colors[0] == colors_ref[0] && colors[1] == colors_ref[1] &&
           colors[2] == colors_ref[2]) {
          return 0;
        }
      }
      else {
        if(colors[0] == colors_ref[0] && colors[1] == colors_ref[1]) {
          return 0;
        }
      }
    }
  }
  return 1;
}

void discreteFront::initFront(std::vector<double> points,
                              std::vector<int> concentration)
{
  if(boundary->markers.size() == 0) {
    std::vector<double> bnd_pos;
    setBoundaryFromMesh(&bnd_pos);
  }

  buildSpatialSearchStructureInit();
  intersectInterfaces(true);
  size_t max_marker = getMaxMarker();
  std::vector<bool> visited(max_marker + 1, false);
  std::vector<int> pos2m(max_marker + 1, -1);
  std::vector<int> m2pos(max_marker + 1, -1);

  std::vector<double> pos2d;
  std::vector<size_t> rec;
  for(size_t i = 0; i < boundary->markers.size(); ++i) {
    visited[boundary->markers[i]] = true;
    rec.push_back(boundary->markers[i]);
    rec.push_back(boundary->markers[(i + 1) % boundary->markers.size()]);
  }

  for(size_t i = 0; i < interfaces.size(); ++i) {
    size_t n_m = interfaces[i].markers.size();
    for(size_t j = 0; j < n_m; ++j) {
      visited[interfaces[i].markers[j]] = true;
      if(interfaces[i].loop == false && j == n_m - 1) continue;
      rec.push_back(interfaces[i].markers[j]);
      rec.push_back(interfaces[i].markers[(j + 1) % n_m]);
    }
  }

  for(size_t i = 0; i < max_marker + 1; ++i) {
    if(visited[i]) {
      pos2m[pos2d.size() / 2] = i;
      m2pos[i] = pos2d.size() / 2;
      pos2d.push_back(pos[3 * i]);
      pos2d.push_back(pos[3 * i + 1]);
      bbox += SPoint3(pos[3 * i], pos[3 * i + 1], 0);
    }
  }

  std::vector<size_t> rec_mapped;
  for(size_t i = 0; i < rec.size(); ++i) {
    rec_mapped.push_back(m2pos[rec[i]]);
  }

  size_t n_m = pos2d.size() / 2;
  SBoundingBox3d bbTri = bbox;
  bbTri *= 1.3;
  pos2d.push_back(bbTri.min().x());
  pos2d.push_back(bbTri.min().y());
  pos2d.push_back(bbTri.max().x());
  pos2d.push_back(bbTri.min().y());
  pos2d.push_back(bbTri.max().x());
  pos2d.push_back(bbTri.max().y());
  pos2d.push_back(bbTri.min().x());
  pos2d.push_back(bbTri.max().y());

  std::vector<size_t> tri;
  meshTriangulate2d(pos2d, tri, &rec_mapped);
  for(size_t i = 0; i < tri.size(); i += 3) {
    double rotation = robustPredicates::orient2d(&pos2d[2 * (tri[i] - 1)],
                                                 &pos2d[2 * (tri[i + 1] - 1)],
                                                 &pos2d[2 * (tri[i + 2] - 1)]);
    if(rotation < 0) {
      size_t tmp = tri[i];
      tri[i] = tri[i + 1];
      tri[i + 1] = tmp;
    }
  }

  
  pm->reset();
  triangulation2PolyMesh(tri, pos2d, &pm);
  
  std::sort(pm->vertices.begin(), pm->vertices.end(),
            [](PolyMesh::Vertex *v1, PolyMesh::Vertex *v2) {
              return v1->data < v2->data;
            });
  // color the edges
  for(size_t i = 0; i < rec_mapped.size() / 2; ++i) {
    size_t m1 = rec_mapped[2 * i];
    size_t m2 = rec_mapped[2 * i + 1];
    PolyMesh::Vertex *v = pm->vertices[m1];
    PolyMesh::HalfEdge *he = v->he;
    PolyMesh::HalfEdge *bnd_he = nullptr;
    do {
      if(he->next->v->data - 1 == m2) {
        he->data = 5;
        break;
      }
      else if(he->opposite == nullptr) {
        bnd_he = he;
        break;
      }
      he = he->opposite->next;
    } while(he != v->he);
    if(bnd_he != nullptr) {
      he = bnd_he;
      do {
        if(he->next->next->v->data - 1 == m2) { he->next->next->data = 5; }
        else if(he->next->next->opposite == nullptr) {
          break;
        }
        he = he->next->next->opposite;
      } while(he != bnd_he);
    }
  }

  //find center_face
  double center[2] = {bbTri.center().x(), bbTri.center().y()};
  PolyMesh::Face *f = pm->faces[0];
  PolyMesh::Face *f_center = pm->walk_from(center, f);


  // color the faces with the concentration
  for(size_t i = 0; i < pm->faces.size(); ++i) { pm->faces[i]->data = -10; }
  for(size_t i = 0; i < points.size() / 3; ++i) {
    double pos[3] = {points[3 * i], points[3 * i + 1], 0};
    PolyMesh::Face *f_point = pm->walk_from(pos, f_center);
    std::vector<PolyMesh::Face *> todo;
    std::vector<PolyMesh::Face *> new_todo;
    todo.push_back(f_point);
    while(todo.size() > 0) {
      for(size_t td = 0; td < todo.size(); ++td) {
        PolyMesh::Face *current = todo[td];
        current->data = concentration[i];
        PolyMesh::HalfEdge *he = current->he;
        do {
          if(he->opposite == nullptr) {
            he = he->next;
            continue;
          }
          if(he->data == 5 || he->opposite->data == 5) {
            he = he->next;
            continue;
          }
          if(he->opposite->f->data == -10) {
            new_todo.push_back(he->opposite->f);
          }
          he = he->next;
        } while(he != current->he);
      }
      todo = new_todo;
      new_todo.clear();
    }
  }

  

  // keep only the triangles that are inside the domain
  tri.clear();
  std::vector<int> tri_tag;
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    if(pm->faces[i]->data != -10) {
      tri.push_back(pm->faces[i]->he->v->data);
      tri.push_back(pm->faces[i]->he->next->v->data);
      tri.push_back(pm->faces[i]->he->next->next->v->data);
      tri_tag.push_back(pm->faces[i]->data);
    }
  }

  pm->reset();
  triangulation2PolyMesh(tri, pos2d, &pm);
  for(size_t i = 0; i < pm->faces.size(); ++i) {
    pm->faces[i]->data = tri_tag[i];
  }

  for(size_t i = 0; i < pm->vertices.size(); ++i) {
    pm->vertices[i]->data = pos2m[pm->vertices[i]->data - 1] + 1;
  }

  computeNewInterfaces();
  triangulateInterfaces();
  colorTriangles();

  // correct corners that dissapeared
  for(size_t i=0; i<corners.size(); i++) {
    int id_interface = findMarker(corners[i]);
    if(id_interface == -1) {
      corners.erase(corners.begin() + i);
      i--; 
    }
  }

}

SVector3 discreteFront::closestPoints2d(const SVector3 &P,
                                        const std::vector<bool> &bnd_markers)
{
  double dmin = 1.e22;
  SVector3 res;
  for(size_t i = 0; i < interfaces.size(); ++i) {
    // if(interfaces[i].tag < 0) continue;
    size_t n_m = interfaces[i].markers.size();
    for(size_t j = 0; j < n_m; ++j) {
      size_t m1 = interfaces[i].markers[j];
      size_t m2 = interfaces[i].markers[(j + 1) % n_m];
      if(bnd_markers[m1] && bnd_markers[m2]) {
        if(std::find(triple_points.begin(), triple_points.end(), m1) ==
             triple_points.end() &&
           std::find(triple_points.begin(), triple_points.end(), m2) ==
             triple_points.end())
          continue;
      }
      SVector3 A(pos[3 * m1], pos[3 * m1 + 1], 0);
      SVector3 B(pos[3 * m2], pos[3 * m2 + 1], 0);
      SVector3 AB = B - A;
      double lAB = AB.norm();
      AB.normalize();
      SVector3 AP = P - A;
      double L = dot(AP, AB);
      SVector3 H;
      if(L < 0)
        H = A;
      else if(L > lAB)
        H = B;
      else
        H = A + AB * L;
      SVector3 HP = P - H;
      double d = HP.norm();
      if(d < dmin) {
        dmin = d;
        res = H;
      }
    }
  }

  return res;
}

void discreteFront::resetInterfacesMesh()
{
  PolyMesh *pm_mesh = new PolyMesh();
  meshRelaying::instance()->getPm(&pm_mesh);
  
  std::vector<std::vector<size_t>> new_loops;
  std::vector<interface> new_interfaces;
  std::vector<int> interface_tag;

  pos.clear();

  std::vector<bool> visited_hedge(pm_mesh->hedges.size(), false);
  std::vector<int> meshNode2m(pm_mesh->vertices.size(), -1);
  for(size_t i = 0; i < pm_mesh->hedges.size(); ++i) {
    pm_mesh->hedges[i]->data = i;
  }

  for(size_t i = 0; i < pm_mesh->hedges.size(); ++i) {
    PolyMesh::HalfEdge *he = pm_mesh->hedges[i];
    if(visited_hedge[he->data]) continue;
    if(he->opposite != nullptr) {
      if(he->opposite->f->data == he->f->data) continue;
    }

    std::vector<PolyMesh::HalfEdge *> loop_he;
    std::vector<PolyMesh::Vertex *> loop_v;
    std::vector<size_t> loop_m;
    rotate_pm_vertex(he, &loop_he, &loop_v);
    for(auto h : loop_he) { visited_hedge[h->data] = true; }

    // check if loop is counter clockwise
    std::vector<double> loop_pos;
    for(size_t j = 0; j < loop_v.size(); ++j) {
      loop_pos.push_back(loop_v[j]->position.x());
      loop_pos.push_back(loop_v[j]->position.y());
      if(meshNode2m[loop_v[j]->data - 1] == -1) {
        meshNode2m[loop_v[j]->data - 1] = pos.size() / 3;
        loop_m.push_back(pos.size() / 3);
        pos.push_back(loop_v[j]->position.x());
        pos.push_back(loop_v[j]->position.y());
        pos.push_back(0);
      }
      else {
        loop_m.push_back(meshNode2m[loop_v[j]->data - 1]);
      }
    }

    int clock = clockwise(loop_pos);
    if(clock == -1) {
      new_loops.push_back(loop_m);
      interface_tag.push_back(he->f->data);
    }
    else {
      // printf("clockwise loop : %d \n", loop_v.size());
      // for(size_t j = 0; j < loop_v.size(); ++j) { printf("%lu, ", loop_v[j]); }
      // printf("\n");

      // printf("loop pos \n");
      // for(size_t j = 0; j < loop_pos.size(); ++j) {
      //   printf("%f, ", loop_pos[j]);
      // }
      // printf("\n");
    }
  }

  for(size_t i = 0; i < new_loops.size(); ++i) {
    new_interfaces.push_back(
      interface(i, interface_tag[i], new_loops[i], true));
  }

  interfaces = new_interfaces;

  // update boundary
  boundary->markers.clear();
  std::vector<std::pair<size_t, size_t>> bnd;
  meshRelaying::instance()->getBnd1d(&bnd);
  std::vector<size_t> loop;
  size_t start = bnd[0].first;
  size_t prev = start;
  size_t current = bnd[0].second;
  loop.push_back(start);
  loop.push_back(current);
  while(true) {
    auto it =
      std::find_if(bnd.begin(), bnd.end(), [&](std::pair<size_t, size_t> p) {
        if(p.first == current && p.second != prev) { return true; }
        else if(p.second == current && p.first != prev) {
          return true;
        }
        return false;
      });
    if(it == bnd.end()) { break; }

    if(it->first == current) {
      prev = current;
      current = it->second;
    }
    else {
      prev = current;
      current = it->first;
    }
    if(current == start) { break; }
    loop.push_back(current);
  }
  for(size_t i = 0; i < loop.size(); ++i) {
    boundary->markers.push_back(meshNode2m[loop[i]]);
  }
  triangulateInterfaces();

  colorTriangles();
  triple_points.clear();
  for(size_t i = 0; i < interfaces.size(); ++i) {
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      size_t m = interfaces[i].markers[j];
      PolyMesh::Vertex *dummy;
      int id = findVertex(m, dummy);
      int colors[3] = {0, 0, 0};
      if(vertexType(id, colors) == 1) { triple_points.push_back(m); }
    }
  }
}

void discreteFront::write_DF(const std::string DF_filename){
  FILE *f = std::fopen(DF_filename.c_str(), "w");
  if(f == nullptr) {
    Msg::Error("Could not open file %s", DF_filename.c_str());
  } 

  fprintf(f, "%lu interfaces \n", interfaces.size());
  for(size_t i = 0; i < interfaces.size(); ++i) {
    fprintf(f, "interface %lu \n", i);
    fprintf(f, "tag %d \n", interfaces[i].tag);
    fprintf(f, "loop %d \n", interfaces[i].loop);
    fprintf(f, "markers %lu \n", interfaces[i].markers.size());
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j) {
      fprintf(f, "%lu \n", interfaces[i].markers[j]);
    }
  }
  fprintf(f, "marker positions %lu \n", pos.size() / 3);
  for(size_t i = 0; i < pos.size() / 3; ++i) {
    fprintf(f, "%f, %f, %f \n", pos[3 * i], pos[3 * i + 1], 0.0);
  }
  fprintf(f, "corners %lu \n", corners.size());
  for(size_t i = 0; i < corners.size(); ++i) {
    fprintf(f, "%lu \n", corners[i]);
  }
  std::vector<double> mesh_pos;
  meshRelaying::instance()->getNodesPosition(mesh_pos);
  fprintf(f, "mesh positions %lu \n", mesh_pos.size() / 3);
  for(size_t i = 0; i < mesh_pos.size() / 3; ++i) {
    fprintf(f, "%f, %f, %f \n", mesh_pos[3 * i], mesh_pos[3 * i + 1], 0.0);
  }
  fclose(f);
}

void discreteFront::read_DF(const std::string DF_filename, const bool pos_flag){
  FILE *f = std::fopen(DF_filename.c_str(), "r");
  if(f == nullptr) {
    Msg::Error("Could not open file %s", DF_filename.c_str());
  } 
  size_t n_interfaces_file;
  fscanf(f, "%lu interfaces \n", &n_interfaces_file);

  // clear
  interfaces.clear();
  pos.clear();
  corners.clear();
  boundary->markers.clear();
  fn.clear();
  triple_points.clear();
  on_edge_triples.clear(); 
  Tree = nullptr;

  meshRelaying::instance()->reset_DF();

  for(size_t i = 0; i < n_interfaces_file; ++i) {
    size_t id;
    int tag;
    int loop;
    size_t n_markers;
    fscanf(f, "interface %lu \n", &id);
    fscanf(f, "tag %d \n", &tag);
    fscanf(f, "loop %d \n", &loop);
    fscanf(f, "markers %lu \n", &n_markers);
    std::vector<size_t> markers;
    for(size_t j = 0; j < n_markers; ++j) {
      size_t m;
      fscanf(f, "%lu \n", &m);
      markers.push_back(m);
    }
    bool loop_ = loop;
    printf("read interface %lu with tag %d and %lu markers \n", id, tag, n_markers);
    interfaces.push_back(interface(id, tag, markers, loop_));
  }
  
  size_t n_markers_tot;
  fscanf(f, "marker positions %lu \n", &n_markers_tot);
  pos.clear();
  for(size_t i = 0; i < n_markers_tot; ++i) {
    double x, y, z;
    fscanf(f, "%lf, %lf, %lf \n", &x, &y, &z);
    pos.push_back(x);
    pos.push_back(y);
    pos.push_back(z);
  }
  
  size_t n_corners;
  fscanf(f, "corners %lu \n", &n_corners);
  for(size_t i = 0; i < n_corners; ++i) {
    size_t c;
    fscanf(f, "%lu \n", &c);
    corners.push_back(c);
  }
  
  if(pos_flag){
    size_t n_mesh_pos;
    fscanf(f, "mesh positions %lu \n", &n_mesh_pos);
    std::vector<double> mesh_pos;
    for(size_t i = 0; i < n_mesh_pos; ++i) {
      double x, y, z;
      fscanf(f, "%lf, %lf, %lf \n", &x, &y, &z);
      mesh_pos.push_back(x);
      mesh_pos.push_back(y);
      mesh_pos.push_back(z);
    }
    meshRelaying::instance()->setNodesPosition(mesh_pos);
  }
  fclose(f);
  
  for(size_t i = 0; i < pos.size(); i += 3) {
    bbox += SPoint3(pos[i], pos[i + 1], pos[i + 2]);
  }  
  

  triangulateInterfaces();
  colorTriangles(false);
  computeNewInterfaces();
  
  //define boundary
  
  //find first bnd edge
  PolyMesh::HalfEdge *start_he;
  for(size_t i = 0; i < pm->hedges.size(); ++i) {
    if(pm->hedges[i]->opposite == nullptr) {
      int colors[3] = {0, 0, 0};
      PolyMesh::Vertex *v;
      int id = findVertex(pm->hedges[i]->v->data-1, v);
      int is_triple = vertexType(id, colors);
      if(is_triple == 0){
        start_he = pm->hedges[i];
        break;
      }
    }
  }
  PolyMesh::HalfEdge *he = start_he;
  do{
    if(he->next->opposite == nullptr){
      PolyMesh::Vertex *v;
      int id = findVertex(he->next->v->data-1, v);
      int colors[3] = {0, 0, 0};
      int is_triple = vertexType(id, colors);
      if(is_triple == 0){
        boundary->markers.push_back(he->next->v->data-1);
      }
      he = he->next;
      continue;
    }
    
    he = he->next->opposite;
  }while (he != start_he); 
  
}

void discreteFront::remove_features(double l){
  createTree();

  // get the different phases
  std::vector<int> phases;
  for(size_t i = 0; i < interfaces.size(); ++i) {
    phases.push_back(interfaces[i].tag);
  }
  std::sort(phases.begin(), phases.end());
  auto new_end = std::unique(phases.begin(), phases.end());
  phases.erase(new_end, phases.end());
  size_t n_phases = phases.size();

  std::vector<int> solid_markers;
  getSolidMarkers(&solid_markers);

  // move the markers in perpendicular direction
  std::vector<double> new_pos = pos;
  size_t max_m = getMaxMarker();
  std::vector<bool> flag_prev(max_m+1, false);
  std::vector<bool> flag_intersected(max_m+1, false);

  size_t iter = 0;
  for(size_t i_p=0; i_p<n_phases; ++i_p){
    // if(iter>1) break;
    std::vector<double> old_pos = pos;
    for(size_t s=0; s<2; ++s){
      int sign = 0;
      if (s==0){
        sign = 1;
      }else{
        sign = -1;
      }

      std::vector<bool> moved(max_m+1, false);

      for(size_t i = 0; i < interfaces.size(); ++i) {
        if(interfaces[i].tag != phases[i_p]) continue;
        if(interfaces[i].tag<0) continue;
        size_t n_m = interfaces[i].markers.size();
        for(size_t j = 0; j < n_m; ++j) {
          if(solid_markers[interfaces[i].markers[j]]==1) continue;
          if(flag_intersected[interfaces[i].markers[j]]) continue;
          size_t m1 = interfaces[i].markers[(j+n_m-1)%n_m];
          size_t m2 = interfaces[i].markers[j];
          size_t m3 = interfaces[i].markers[(j+1)%n_m];

          flag_prev[m2] = true;
          moved[m2] = true;

          double x1[2] = {pos[3*m1], pos[3*m1+1]};
          double x2[2] = {pos[3*m2], pos[3*m2+1]};
          double x3[2] = {pos[3*m3], pos[3*m3+1]};

          double edge21[2] = {x2[0]-x1[0], x2[1]-x1[1]};
          double edge32[2] = {x3[0]-x2[0], x3[1]-x2[1]}; 
          double norm21 = sqrt(edge21[0]*edge21[0] + edge21[1]*edge21[1]);
          double norm32 = sqrt(edge32[0]*edge32[0] + edge32[1]*edge32[1]);

          edge21[0] /= norm21;
          edge21[1] /= norm21;
          edge32[0] /= norm32;
          edge32[1] /= norm32;

          double n21[2] = {edge21[1], -edge21[0]};
          double n32[2] = {edge32[1], -edge32[0]};

          new_pos[3*m2] += sign*l*0.5*(n21[0] + n32[0]);
          new_pos[3*m2+1] += sign*l*0.5*(n21[1] + n32[1]);
        }
      }

      iter++;

      // update the positions
      pos = new_pos;

      // update the polymesh
      for(size_t i=0; i<pm->vertices.size(); ++i){
        size_t id = pm->vertices[i]->data - 1;
        pm->vertices[i]->position = SVector3(pos[3*id], pos[3*id+1], 0);
      }

      // intersect the interfaces
      buildSpatialSearchStructure();
      intersectInterfaces(false);

      triangulateInterfaces();
      colorTriangles();
      computeNewInterfaces();

      max_m = getMaxMarker();
      flag_prev.resize(max_m+1, false);
      flag_intersected.resize(max_m+1, false);
      moved.resize(max_m+1, true);
      solid_markers.resize(max_m+1, 0);
      new_pos = pos;

      std::vector<size_t> new_markers;
      
      for(size_t i = 0; i < interfaces.size(); ++i) {
        // if(interfaces[i].tag != phases[i_p]) continue;
        size_t n_m = interfaces[i].markers.size();
        for(size_t j = 0; j < n_m; ++j) {
          if(solid_markers[interfaces[i].markers[j]]==1) continue;
          if(!moved[interfaces[i].markers[j]]) continue;
          size_t m1 = interfaces[i].markers[(j+n_m-1)%n_m];
          size_t m2 = interfaces[i].markers[j];
          size_t m3 = interfaces[i].markers[(j+1)%n_m];

          if(flag_prev[m2]){
            new_pos[3*m2] = old_pos[3*m2];
            new_pos[3*m2+1] = old_pos[3*m2+1];
            continue;
          } else {
            new_markers.push_back(m2);
            flag_intersected[m2] = true;
            flag_intersected[m1] = true;
            flag_intersected[m3] = true;
            new_pos[3*m2] = pos[3*m2];
            new_pos[3*m2+1] = pos[3*m2+1];
            continue;
          }
        }
      }

      pos = new_pos;

      // update the polymesh
      for(size_t i=0; i<pm->vertices.size(); ++i){
        size_t id = pm->vertices[i]->data - 1;
        pm->vertices[i]->position = SVector3(pos[3*id], pos[3*id+1], 0);
      }

      createTree();
    }
  }

  renumber_DF();

  return;
}

void discreteFront::renumber_DF(){
  size_t max_m = getMaxMarker();
  std::vector<int> mapping(max_m+1, -1);

  std::vector<double> new_pos;
  std::vector<interface> new_interfaces = interfaces;
  std::vector<size_t> new_triple_points;
  std::vector<std::pair<size_t, std::pair<size_t, size_t>>> new_on_edge_triples;

  std::vector<int> bnd_markers;
  getBndMarkers(&bnd_markers);

  std::vector<int> original_bnd_markers(max_m+1, 0);
  for(size_t i = 0; i < boundary->markers.size(); ++i){
    original_bnd_markers[boundary->markers[i]] = 1;
  }

  std::vector<int> is_triple(max_m+1, 0);
  for(size_t i = 0; i < triple_points.size(); ++i){
    is_triple[triple_points[i]] = 1;
  }

  for(size_t i = 0; i < interfaces.size(); ++i){
    std::vector<size_t> new_markers(interfaces[i].markers.size(), 0);
    size_t it_ = 0;
    for(size_t j = 0; j < interfaces[i].markers.size(); ++j){
      size_t m = interfaces[i].markers[j];
      if(bnd_markers[m] && original_bnd_markers[m]==0 && is_triple[m]==0){ // recover original bnd except for current triple points
        printf("marker %lu is on the boundary \n", m);
        printf("bnd = %d, orignal_bnd = %d, is_triple = %d \n", bnd_markers[m], original_bnd_markers[m], is_triple[m]);
        continue;
      }

      if(mapping[m] == -1){
        mapping[m] = new_pos.size()/3;
        new_pos.push_back(pos[3*m]);
        new_pos.push_back(pos[3*m+1]);
        new_pos.push_back(pos[3*m+2]);
      }
      new_markers[it_] = mapping[m];
      it_++;
    }
    new_markers.resize(it_);
    new_interfaces[i].markers = new_markers;
  }

  for(size_t i = 0; i < triple_points.size(); ++i){
    new_triple_points.push_back(mapping[triple_points[i]]);
  }

  for(size_t i = 0; i < boundary->markers.size(); ++i){
    boundary->markers[i] = mapping[boundary->markers[i]];
  }

  for(size_t i=0; i<corners.size(); ++i){
    corners[i] = mapping[corners[i]];
  }
  

  pos = new_pos;
  interfaces = new_interfaces;
  triple_points = new_triple_points;

  // update the polymesh
  triangulateInterfaces();
  colorTriangles();

  on_edge_triples.clear();

  // compute new on edge triple with pm
  for(size_t i =0; i<triple_points.size(); ++i){
    size_t m = triple_points[i];
    PolyMesh::Vertex *v;
    int id = findVertex(m, v);
    int colors[3] = {0, 0, 0};
    vertexType(id, colors);
    //find double neighs
    std::vector<PolyMesh::Vertex*> neighs;
    findNDoubleNeighbours(pm->vertices[id], &neighs, 1, colors[0]);
    if(neighs[0]->data < neighs[1]->data){
      on_edge_triples.push_back(std::make_pair(neighs[0]->data-1, std::make_pair(m, neighs[1]->data-1)));
    } else {
      on_edge_triples.push_back(std::make_pair(neighs[1]->data-1, std::make_pair(m, neighs[0]->data-1)));
    }
  }
}
  

int clockwise(std::vector<double> loop)
{
  double area = 0;
  size_t n = loop.size() / 2;
  for(size_t j = 0; j < n; ++j) {
    double aa[2] = {loop[2 * j], loop[2 * j + 1]};
    double bb[2] = {loop[2 * ((j + 1) % n)], loop[2 * ((j + 1) % n) + 1]};
    area += (bb[0] - aa[0]) * (bb[1] + aa[1]);
  }
  if(area > 0) { return 1; }
  else {
    return -1;
  }
}

// int w_number(double P[2], std::vector<double> loop)
// {
//   // compute winding number -- slow
//   double angTot = 0.0;
//   size_t n = loop.size() / 2;
//   for(size_t i = 0; i < n; ++i) {
//     double A[2] = {loop[2 * i], loop[2 * i + 1]};
//     double B[2] = {loop[2 * ((i + 1) % n)], loop[2 * ((i + 1) % n) + 1]};
//     double PA[2] = {A[0] - P[0], A[1] - P[1]};
//     double PB[2] = {B[0] - P[0], B[1] - P[1]};
//     double cross = PB[0] * PA[1] - PB[1] * PA[0];
//     double dot = PA[0] * PB[0] + PA[1] * PB[1];
//     double a = atan2(cross, dot);
//     angTot += a;
//   }

//   if(angTot > M_PI * 1.99)
//     return 1;
//   else if(angTot < -M_PI * 1.99)
//     return -1;
//   else
//     return 0;
// }

int w_number(double P[2], std::vector<double> loop)
{
  // compute winding number -- fast

  int wn = 0;
  size_t n = loop.size() / 2;
  for(size_t j = 0; j < n; ++j) {
    double aa[2] = {loop[2 * j], loop[2 * j + 1]};
    double bb[2] = {loop[2 * ((j + 1) % n)], loop[2 * ((j + 1) % n) + 1]};
    double area = robustPredicates::orient2d(aa, bb, P);
    if(area == 0) return 2;
    if(aa[1] <= P[1]) {
      if(bb[1] > P[1] && area < 0) wn++;
    }
    else if(bb[1] <= P[1]) {
      if(area > 0) wn--;
    }
  }
  if(wn > 0) { return -1; }
  else if(wn < 0) {
    return 1;
  }
  else {
    return 0;
  }
}

double kappa(double x1[2], double x2[2], double x3[2])
{
  double dy1 = x1[1] - x2[1];
  double dy2 = x2[1] - x3[1];
  double dy3 = x3[1] - x1[1];

  double n1 = x1[0] * x1[0] + x1[1] * x1[1];
  double n2 = x2[0] * x2[0] + x2[1] * x2[1];
  double n3 = x3[0] * x3[0] + x3[1] * x3[1];

  double area = 0.5 * (x1[0] * dy2 + x2[0] * dy3 + x3[0] * dy1);
  if(area == 0.0) { return 0.0; }
  else {
    double Ux = (1 / (4 * area)) * (n1 * dy2 + n2 * dy3 + n3 * dy1);
    double Uy =
      (1 / (4 * area)) *
      (n1 * (x3[0] - x2[0]) + n2 * (x1[0] - x3[0]) + n3 * (x2[0] - x1[0]));

    double radius =
      sqrt((Ux - x2[0]) * (Ux - x2[0]) + (Uy - x2[1]) * (Uy - x2[1]));
    double sign = 0.0;
    if(robustPredicates::orient2d(x1, x2, x3) > 0) { sign = 1.0; }
    else {
      sign = -1.0;
    }
    return -sign * (1.0 / radius);
  }
  return 0;
}

int computeIntersection(double a1[2], double a2[2], double a3[2], double a4[2],
                        double *inter, double *param)
{
  double a143 = robustPredicates::orient2d(a1, a4, a3);
  double a243 = robustPredicates::orient2d(a2, a4, a3);
  double eps = 1e-15;
  if((a143 > eps && a243 < -eps) || (a143 < -eps && a243 > eps)) {
    double a123 = robustPredicates::orient2d(a1, a2, a3);
    double a124 = robustPredicates::orient2d(a1, a2, a4);
    if((a123 > eps && a124 < -eps) || (a123 < -eps && a124 > eps)) {
      double t = fabs(a143) / (fabs(a143) + fabs(a243));
      inter[0] = a1[0] + t * (a2[0] - a1[0]);
      inter[1] = a1[1] + t * (a2[1] - a1[1]);
      param[0] = t;
      return 1;
    }
  }
  return 0;
}

TreeNode *newTreeNode(int id, int tag)
{
  TreeNode *temp = new TreeNode;
  temp->id = id;
  temp->tag = tag;
  temp->leafs = {};
  return temp;
}

double loopOrientation(std::vector<double> pos)
{
  double tot = 0;
  int n = pos.size() / 3;
  for(int i = 0; i < n; ++i) {
    double a[2] = {pos[3 * i], pos[3 * i + 1]};
    double b[2] = {pos[3 * ((i + 1) % n)], pos[3 * ((i + 1) % n) + 1]};
    tot += (b[0] - a[0]) * (b[1] + a[1]);
  }
  return tot;
}
