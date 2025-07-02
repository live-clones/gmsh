// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GRegion.h"
#include "GModel.h"
#include "GFace.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MPrism.h"
#include "MLine.h"
#include "SVector3.h"
#include "xyFace.h"
#include "xyEdge.h"
#include "Numeric.h"

/*

  EDGES        :  both faces BL   --> EDGE = RIDGE
  EDGES        :  one face BL   --> FACE = BOUNDARY, EDGE = RIDGE

--> VERTICES

  VERTICES     :  all edges RIDGE --> corner

*/

static GFace *haveTowGEdges(std::vector<GFace *> &faces, GEdge *ge1, GEdge *ge2)
{
  for(size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> e = faces[i]->edges();
    if(std::find(e.begin(), e.end(), ge1) != e.end() &&
       std::find(e.begin(), e.end(), ge2) != e.end())
      return faces[i];
  }
  return nullptr;
}

static void meshPolygon(GRegion *gr, std::vector<MLine *> &poly,
                        std::vector<MTriangle *> &mesh,
                        std::vector<MVertex *> &new_vertices)
{
  // we want to mesh a simple polygon
  // Create a planar surface
  xyEdge e(gr->model(), 1111);
  e.lines = poly;
  xyFace f(gr->model(), 1111, &e);
  f.mesh(true);
  //  printf("mesh done %d triangles %d
  //  size\n",f.triangles.size(),f.mesh_vertices.size());
  new_vertices = f.mesh_vertices;
  mesh = f.triangles;
  f.mesh_vertices.clear();
  f.triangles.clear();
}

class blyr_ridge {
public:
  enum type { INTERNAL, EXTERNAL, FLAT };
  type _t;
  GEdge *_ge;
  GRegion *_gr;
  GFace *_f[2];
  double max_angle, min_angle;
  std::size_t N_SUBNORMALS;

  void computeType(double angle)
  {
    if(max_angle > angle)
      _t = EXTERNAL;
    else if(min_angle < -angle)
      _t = INTERNAL;
    else
      _t = FLAT;
  }

  void setType(type t) { _t = t; }

  type getType() const { return _t; }

  blyr_ridge(GEdge *ge, GRegion *gr, GFace *f0, GFace *f1)
    : _ge(ge), _gr(gr), N_SUBNORMALS(0)
  {
    _f[0] = f0;
    _f[1] = f1;
  }
  GEdge *getEdge() const { return _ge; }
  bool operator<(const blyr_ridge &other)
  {
    return _ge->tag() < other._ge->tag();
  }
};

class blyr_mvertex {
public:
  MVertex *_v;
  // all triangles connected to that vertex

  mutable std::vector<MTriangle *> _triangles;
  mutable std::vector<SVector3> _normals;
  mutable std::vector<GFace *> _gfaces;

  // all mesh edges connected to that vertex

  mutable std::vector<MLine *> _lines;
  mutable std::vector<GEdge *> _gedges;

  // one extruded vertex per face ...
  mutable std::vector<MVertex *> _v_per_face;
  mutable std::vector<SVector3> _n_per_vertex;
  mutable std::vector<GFace *> _f_per_normal;

  // ridge points
  mutable std::map<std::pair<GFace *, GFace *>, std::vector<MVertex *> >
    _v_per_ridge;

  // triangles for external corners
  mutable std::vector<MTriangle *> _triangles_at_corner;

  bool operator<(const blyr_mvertex &other) const
  {
    return _v->getNum() < other._v->getNum();
  }
  blyr_mvertex(MVertex *v) : _v(v) {}

  MVertex *extruded_vertex(GFace *gf) const
  {
    if(_f_per_normal.size() == 1) return _v_per_face[0];
    for(size_t i = 0; i < _f_per_normal.size(); i++) {
      if(gf == _f_per_normal[i]) return _v_per_face[i];
    }
    // if (gf) printf("NONE for face %d\n",gf->tag());
    return nullptr;
  }

  SVector3 average_normal(GFace *gf = nullptr) const
  {
    SVector3 n(0, 0, 0);
    //    printf("%d %d\n",_normals.size(),_f_per_normal.size());
    for(size_t i = 0; i < _normals.size(); i++) {
      if(!gf || gf == _gfaces[i]) n += _normals[i];
    }
    n.normalize();
    return n;
  }

  void add_triangle(MTriangle *t, SVector3 &n, GFace *gf) const
  {
    if(std::find(_triangles.begin(), _triangles.end(), t) == _triangles.end()) {
      _triangles.push_back(t);
      _normals.push_back(n);
      _gfaces.push_back(gf);
    }
  }
  void add_line(MLine *l, GEdge *ge) const
  {
    if(std::find(_lines.begin(), _lines.end(), l) == _lines.end()) {
      _lines.push_back(l);
      _gedges.push_back(ge);
    }
  }
};

class blyr_manager {
  // blayer thickness (this could change
  // by imposing a function)...

  double _thickness;

  // threshold for angles
  double _threshold_angle;

  // the 3D region where the fluid is flowing
  GRegion *_gr;

  // one face BL   --> FACE = BOUNDARY, EDGE = RIDGE
  std::vector<GFace *> _faces;

  // both faces BL   --> RIDGE
  std::vector<blyr_ridge> _ridges;

  // vertices of the surface
  std::set<blyr_mvertex> _vertices;

public:
  blyr_manager(GRegion *gr, std::vector<GFace *> &bls, double t)
    : _thickness(t), _gr(gr), _faces(bls)
  {
    std::map<MFace, SVector3, MFaceLessThan> t_normals;
    for(size_t i = 0; i < _gr->tetrahedra.size(); i++) {
      for(int j = 0; j < 4; j++) {
        MFace f = _gr->tetrahedra[i]->getFace(j);
        auto it = t_normals.find(f);
        if(it == t_normals.end()) {
          SVector3 n = f.normal();
          MVertex *v = _gr->tetrahedra[i]->getVertex(3 - j);
          SPoint3 b = f.barycenter();
          SVector3 t(v->x() - b.x(), v->y() - b.y(), v->z() - b.z());
          if(dot(t, n) < 0) n *= -1.0;
          t_normals[f] = n;
        }
        else
          t_normals.erase(it);
      }
    }

    //    printf("%d triangles are ok\n",t_normals.size());

    _threshold_angle = M_PI / 6; // one normal per vertex for now
    // compute all vertices
    for(size_t i = 0; i < bls.size(); i++) {
      for(size_t j = 0; j < bls[i]->triangles.size(); j++) {
        for(int k = 0; k < 3; k++) {
          _vertices.insert(blyr_mvertex(bls[i]->triangles[j]->getVertex(k)));
        }
      }
    }

    Msg::Debug("Boundary layer manager computes extruded elements in region %d",
               gr->tag());

    // compute ridges and boundaries
    std::vector<GEdge *> edges = gr->edges();
    std::vector<GFace *> faces = gr->faces();
    for(size_t i = 0; i < edges.size(); i++) {
      GFace *f[2] = {nullptr, nullptr};
      std::vector<GFace *> efaces = edges[i]->faces();
      int count = 0;
      bool seam = false;
      for(size_t j = 0; j < efaces.size(); j++) {
        if(edges[i]->isSeam(efaces[j])) seam = true;
        if(std::find(faces.begin(), faces.end(), efaces[j]) != faces.end()) {
          f[count++] = efaces[j];
        }
      }
      // seams are virtual so NO ridge is present
      // also remove flat ridges
      if(!seam) {
        if(count >= 1) {
          _ridges.push_back(blyr_ridge(edges[i], gr, f[0], f[1]));
        }
        for(size_t j = 0; j < edges[i]->lines.size(); j++) {
          for(int k = 0; k < 2; k++) {
            MVertex *v = edges[i]->lines[j]->getVertex(k);
            auto it = _vertices.find(v);
            if(it == _vertices.end())
              Msg::Error("Unknown node in boundary layer");
            it->add_line(edges[i]->lines[j], edges[i]);
          }
        }
      }
    }

    Msg::Debug("Boundary layer manager : %d ridges", _ridges.size());

    // then compute normals

    for(size_t i = 0; i < bls.size(); i++) {
      for(size_t j = 0; j < bls[i]->triangles.size(); j++) {
        MTriangle *t = bls[i]->triangles[j];
        auto it = t_normals.find(t->getFace(0));
        SVector3 n;
        if(it == t_normals.end())
          Msg::Error("Unknown face in boundary layer");
        else
          n = it->second;
        for(int k = 0; k < 3; k++) {
          MVertex *v = t->getVertex(k);
          auto it = _vertices.find(v);
          if(it == _vertices.end())
            Msg::Error("Unknown node in boundary layer");
          it->add_triangle(t, n, bls[i]);
        }
      }
    }
  }

  blyr_ridge *getRidge(GEdge *ge)
  {
    for(size_t i = 0; i < _ridges.size(); i++) {
      if(_ridges[i]._ge == ge) return &_ridges[i];
    }
    Msg::Error("Unknown ridge %d", ge->tag());
    return nullptr;
  }

  void classify_ridges()
  {
    for(size_t i = 0; i < _ridges.size(); i++) {
      GEdge *ge = _ridges[i].getEdge();
      GFace *f0 = _ridges[i]._f[0];
      GFace *f1 = _ridges[i]._f[1];
      _ridges[i].max_angle = -2 * M_PI;
      _ridges[i].min_angle = 2 * M_PI;
      for(size_t j = 0; j < ge->lines.size(); j++) {
        MLine *l = ge->lines[j];
        MVertex *l0 = l->getVertex(0);
        MVertex *l1 = l->getVertex(1);
        MVertex *op1 = nullptr;
        SVector3 N[2];
        auto it = _vertices.find(l->getVertex(0));
        for(size_t k = 0; k < it->_triangles.size(); k++) {
          MVertex *v0 = it->_triangles[k]->getVertex(0);
          MVertex *v1 = it->_triangles[k]->getVertex(1);
          MVertex *v2 = it->_triangles[k]->getVertex(2);
          GFace *gf = it->_gfaces[k];
          if((v0 == l0 && v1 == l1) || (v0 == l1 && v1 == l0)) {
            if(gf == f0) { N[0] = it->_normals[k]; }
            if(gf == f1) {
              N[1] = it->_normals[k];
              op1 = v2;
            }
          }
          if((v0 == l0 && v2 == l1) || (v0 == l1 && v2 == l0)) {
            if(gf == f0) { N[0] = it->_normals[k]; }
            if(gf == f1) {
              N[1] = it->_normals[k];
              op1 = v1;
            }
          }
          if((v1 == l0 && v2 == l1) || (v1 == l1 && v2 == l0)) {
            if(gf == f0) { N[0] = it->_normals[k]; }
            if(gf == f1) {
              N[1] = it->_normals[k];
              op1 = v0;
            }
          }
        }
        double alpha = angle(N[0], N[1]);
        if(op1) {
          SVector3 dir(0.5 * (l0->x() + l1->x()) - op1->x(),
                       0.5 * (l0->y() + l1->y()) - op1->y(),
                       0.5 * (l0->z() + l1->z()) - op1->z());
          dir.normalize();
          // sign < 0 ---> re-intrant corner
          double sign = dot(dir, N[0]);
          if(sign < 0) alpha = -alpha;
        }

        _ridges[i].max_angle = std::max(alpha, _ridges[i].max_angle);
        _ridges[i].min_angle = std::min(alpha, _ridges[i].min_angle);
        _ridges[i].computeType(_threshold_angle);
      }
      // nice "outer" ridge
      if(_ridges[i].min_angle > 0 && _ridges[i].max_angle > 0) {
        while(_ridges[i].max_angle / (_ridges[i].N_SUBNORMALS + 1) >
              _threshold_angle) {
          _ridges[i].N_SUBNORMALS++;
        }
      }
      if(_ridges[i].min_angle < 0 && _ridges[i].max_angle < 0) {
        _ridges[i].N_SUBNORMALS = 0;
      }
    }
  }

  void classify_corners()
  {
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {}
  }

  void add_fan(const blyr_mvertex &v)
  {
    std::vector<GFace *> _unique;
    for(size_t i = 0; i < v._gfaces.size(); i++) {
      if(std::find(_unique.begin(), _unique.end(), v._gfaces[i]) ==
         _unique.end())
        _unique.push_back(v._gfaces[i]);
    }

    double t = blyr_thickness(v._v->x(), v._v->y(), v._v->z());
    for(size_t i = 0; i < _unique.size(); i++) {
      SVector3 n = v.average_normal(_unique[i]);
      MVertex *new_v = new MVertex(v._v->x() + n.x() * t, v._v->y() + n.y() * t,
                                   v._v->z() + n.z() * t, _gr);
      v._v_per_face.push_back(new_v);
      v._n_per_vertex.push_back(n);
      v._f_per_normal.push_back(_unique[i]);
      _gr->mesh_vertices.push_back(new_v);
    }

    for(size_t i = 0; i < _unique.size(); i++) {
      for(size_t j = i + 1; j < _unique.size(); j++) {
        int num_subnormals = 0;
        for(size_t k = 0; k < _ridges.size(); k++) {
          if((_ridges[k]._f[0] == _unique[i] &&
              _ridges[k]._f[1] == _unique[j]) ||
             (_ridges[k]._f[1] == _unique[i] &&
              _ridges[k]._f[0] == _unique[j])) {
            num_subnormals = _ridges[k].N_SUBNORMALS;
          }
        }

        SVector3 n0 = v._n_per_vertex[i];
        SVector3 n1 = v._n_per_vertex[j];
        std::vector<MVertex *> fan;
        for(int k = 0; k < num_subnormals; k++) {
          double u = (double)(k + 1) / (num_subnormals + 1);
          SVector3 n = n0 * (1. - u) + n1 * u;
          n.normalize();
          MVertex *new_v =
            new MVertex(v._v->x() + n.x() * t, v._v->y() + n.y() * t,
                        v._v->z() + n.z() * t, _gr);
          fan.push_back(new_v);
          _gr->mesh_vertices.push_back(new_v);
        }
        std::pair<GFace *, GFace *> pa = std::make_pair(_unique[i], _unique[j]);
        v._v_per_ridge[pa] = fan;
      }
    }
  }

  void add_external_corner(const blyr_mvertex &v)
  {
    std::vector<SPoint3> aaa;
    for(size_t i = 0; i < v._v_per_face.size(); i++) {
      aaa.push_back(SPoint3(v._v_per_face[i]->x(), v._v_per_face[i]->y(),
                            v._v_per_face[i]->z()));
    }
    mean_plane plane;
    computeMeanPlaneSimple(aaa, plane);

    auto it = v._v_per_ridge.begin();

    std::vector<MLine *> plane_lines;
    std::map<MVertex *, MVertex *> plane_vertices;

    for(; it != v._v_per_ridge.end(); ++it) {
      GFace *f0 = it->first.first;
      GFace *f1 = it->first.second;
      std::vector<MVertex *> &verts = it->second;
      MVertex *v0 = nullptr;
      MVertex *v1 = nullptr;
      for(size_t i = 0; i < v._v_per_face.size(); i++) {
        if(f0 == v._f_per_normal[i]) v0 = v._v_per_face[i];
        if(f1 == v._f_per_normal[i]) v1 = v._v_per_face[i];
      }

      SPoint3 p0, p1;
      projectPointToPlane(SPoint3(v0->x(), v0->y(), v0->z()), p0, plane);
      projectPointToPlane(SPoint3(v1->x(), v1->y(), v1->z()), p1, plane);
      SPoint2 P0((p0.x() - plane.x) * plane.plan[0][0] +
                   (p0.y() - plane.y) * plane.plan[0][1] +
                   (p0.z() - plane.z) * plane.plan[0][2],
                 (p0.x() - plane.x) * plane.plan[1][0] +
                   (p0.y() - plane.y) * plane.plan[1][1] +
                   (p0.z() - plane.z) * plane.plan[1][2]);
      SPoint2 P1((p1.x() - plane.x) * plane.plan[0][0] +
                   (p1.y() - plane.y) * plane.plan[0][1] +
                   (p1.z() - plane.z) * plane.plan[0][2],
                 (p1.x() - plane.x) * plane.plan[1][0] +
                   (p1.y() - plane.y) * plane.plan[1][1] +
                   (p1.z() - plane.z) * plane.plan[1][2]);

      MVertex *v_plane_0 = nullptr;
      auto itp = plane_vertices.find(v0);
      if(itp != plane_vertices.end())
        v_plane_0 = itp->second;
      else {
        v_plane_0 = new MVertex(P0.x(), P0.y(), 0, _gr);
        plane_vertices[v0] = v_plane_0;
      }
      MVertex *v_plane_1 = nullptr;
      itp = plane_vertices.find(v1);
      if(itp != plane_vertices.end())
        v_plane_1 = itp->second;
      else {
        v_plane_1 = new MVertex(P1.x(), P1.y(), 0, _gr);
        plane_vertices[v1] = v_plane_1;
      }

      for(size_t i = 0; i < verts.size(); i++) {
        MVertex *vv = verts[i];
        SPoint3 pp;
        projectPointToPlane(SPoint3(vv->x(), vv->y(), vv->z()), pp, plane);
        SPoint2 PP((pp.x() - plane.x) * plane.plan[0][0] +
                     (pp.y() - plane.y) * plane.plan[0][1] +
                     (pp.z() - plane.z) * plane.plan[0][2],
                   (pp.x() - plane.x) * plane.plan[1][0] +
                     (pp.y() - plane.y) * plane.plan[1][1] +
                     (pp.z() - plane.z) * plane.plan[1][2]);
        MVertex *v_plane = new MVertex(PP.x(), PP.y(), 0, _gr);
        plane_vertices[vv] = v_plane;
        if(i == 0)
          plane_lines.push_back(new MLine(v_plane_0, v_plane));
        else if(i == verts.size() - 1) {
          plane_lines.push_back(new MLine(
            plane_lines[plane_lines.size() - 1]->getVertex(1), v_plane));
          plane_lines.push_back(new MLine(v_plane, v_plane_1));
        }
        else {
          MVertex *vV = plane_lines[plane_lines.size() - 1]->getVertex(1);
          plane_lines.push_back(new MLine(vV, v_plane));
        }
      }
    }

    std::vector<MTriangle *> mesh;
    std::vector<MVertex *> new_vertices;
    meshPolygon(_gr, plane_lines, mesh, new_vertices);

    for(size_t i = 0; i < new_vertices.size(); i++) {
      MVertex *vv = new_vertices[i];
      SPoint3 pp(
        plane.x + plane.plan[0][0] * vv->x() + plane.plan[1][0] * vv->y(),
        plane.y + plane.plan[0][1] * vv->x() + plane.plan[1][1] * vv->y(),
        plane.z + plane.plan[0][2] * vv->x() + plane.plan[1][2] * vv->y());
      SVector3 dx(pp.x() - v._v->x(), pp.y() - v._v->y(), pp.z() - v._v->z());
      dx.normalize();
      MVertex *newv = new MVertex(
        v._v->x() + dx.x() * blyr_thickness(v._v->x(), v._v->y(), v._v->z()),
        v._v->y() + dx.y() * blyr_thickness(v._v->x(), v._v->y(), v._v->z()),
        v._v->z() + dx.z() * blyr_thickness(v._v->x(), v._v->y(), v._v->z()),
        _gr);
      _gr->mesh_vertices.push_back(newv);
      plane_vertices[newv] = vv;
    }

    std::map<int, MVertex *> plane_vertices_inv;
    for(auto it = plane_vertices.begin(); it != plane_vertices.end(); ++it)
      plane_vertices_inv[it->second->getNum()] = it->first;
    //    printf("%d vertices there\n",plane_vertices_inv.size());
    //    printf("%d triangles\n",mesh.size());
    for(size_t i = 0; i < mesh.size(); i++) {
      MVertex *v0 = plane_vertices_inv[mesh[i]->getVertex(0)->getNum()];
      MVertex *v1 = plane_vertices_inv[mesh[i]->getVertex(1)->getNum()];
      MVertex *v2 = plane_vertices_inv[mesh[i]->getVertex(2)->getNum()];
      //
      v._triangles_at_corner.push_back(new MTriangle(v0, v1, v2));
      delete mesh[i];
    }

    for(size_t i = 0; i < new_vertices.size(); i++) delete new_vertices[i];

    //    printf("%d new vertices\n",new_vertices.size());
  }

  void add_one_normal(const blyr_mvertex &v)
  {
    SVector3 n = v.average_normal();
    double t = blyr_thickness(v._v->x(), v._v->y(), v._v->z());
    MVertex *new_v = new MVertex(v._v->x() + n.x() * t, v._v->y() + n.y() * t,
                                 v._v->z() + n.z() * t, _gr);
    v._v_per_face.push_back(new_v);
    v._n_per_vertex.push_back(n);
    v._f_per_normal.push_back(v._gfaces[0]);
    _gr->mesh_vertices.push_back(new_v);
  }

  void extrude_vertex_on_both_surfaces_of_a_ridge(
    const blyr_mvertex &v, blyr_ridge *ridge,
    std::vector<blyr_mvertex> &new_vertices)
  {
    MVertex *vs[2];

    double t = blyr_thickness(v._v->x(), v._v->y(), v._v->z());
    SVector3 n = v.average_normal();
    SPoint3 newp(v._v->x() + t * sqrt(2.0) * n.x(),
                 v._v->y() + t * sqrt(2.0) * n.y(),
                 v._v->z() + t * sqrt(2.0) * n.z());
    MVertex *vmid = new MVertex(newp.x(), newp.y(), newp.z(), _gr);
    _gr->mesh_vertices.push_back(vmid);

    for(int i = 0; i < 2; i++) {
      GFace *f = ridge->_f[i];
      GFace *f_other = ridge->_f[(i + 1) % 2];
      n = v.average_normal(f_other);
      newp = SPoint3(v._v->x() + t * n.x(), v._v->y() + t * n.y(),
                     v._v->z() + t * n.z());
      double initialGuess[2] = {0, 0};
      GPoint p = f->closestPoint(newp, initialGuess);
      vs[i] = new MFaceVertex(p.x(), p.y(), p.z(), f, p.u(), p.v());
      f->mesh_vertices.push_back(vs[i]);
      ridge->N_SUBNORMALS = 1;
      v._v_per_face.push_back(vs[i]);
      v._n_per_vertex.push_back(n);
      v._f_per_normal.push_back(f);
      for(size_t j = 0; j < v._triangles.size(); j++) {
        if(v._gfaces[j] == f) {
          for(int k = 0; k < 3; k++)
            if(v._triangles[j]->getVertex(k) == v._v)
              v._triangles[j]->setVertex(k, vs[i]);
        }
      }
      blyr_mvertex bv(vs[i]);
      bv._v_per_face.push_back(vmid);
      bv._f_per_normal.push_back(f);
      bv._n_per_vertex.push_back(v.average_normal(f));
      new_vertices.push_back(bv);
    }
    std::pair<GFace *, GFace *> pa = std::make_pair(ridge->_f[0], ridge->_f[1]);
    std::vector<MVertex *> fan;
    fan.push_back(vmid);

    v._v_per_ridge[pa] = fan;
    v._triangles.clear();
    v._normals.clear();
    v._gfaces.clear();
  }

  void extrude_ridges_on_faces()
  {
    for(size_t i = 0; i < _ridges.size(); i++) {
      blyr_ridge &r = _ridges[i];
      GFace *f0 = r._f[0];
      GFace *f1 = r._f[1];
      if(r.getType() == blyr_ridge::INTERNAL) {
        for(size_t j = 0; j < r._ge->lines.size(); j++) {
          MLine *l = r._ge->lines[j];
          MVertex *v0 = l->getVertex(0);
          MVertex *v1 = l->getVertex(1);
          auto it0 = _vertices.find(v0);
          auto it1 = _vertices.find(v1);

          MVertex *o00 = it0->extruded_vertex(f0);
          MVertex *o01 = it0->extruded_vertex(f1);
          MVertex *o10 = it1->extruded_vertex(f0);
          MVertex *o11 = it1->extruded_vertex(f1);
          if(o10 && o00)
            f0->quadrangles.push_back(new MQuadrangle(v0, v1, o10, o00));
          if(o01 && o11)
            f1->quadrangles.push_back(new MQuadrangle(v0, v1, o11, o01));
        }
      }
    }
  }

  void extrude_vertices_on_faces()
  {
    std::vector<blyr_mvertex> new_vertices;
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {
      //      printf ("%d has %d lines %d tris\n",it->_v->getNum(),
      //      it->_lines.size(), it->_triangles.size());
      if(it->_lines.size() == 2) {
        GEdge *ge0 = it->_gedges[0];
        GEdge *ge1 = it->_gedges[1];
        blyr_ridge *ridge0 = getRidge(ge0);
        blyr_ridge *ridge1 = getRidge(ge1);
        if(ridge0 == nullptr && ridge1 == nullptr) // not a ridge
          continue;
        else {
          if(ridge0->getType() == blyr_ridge::INTERNAL) {
            if(ridge0 == ridge1) {
              extrude_vertex_on_both_surfaces_of_a_ridge(*it, ridge0,
                                                         new_vertices);
            }
            else {
              Msg::Warning(
                "there is a seam... and we should extrude on that seam");
            }
          }
        }
      }
    }
    //    printf("-------------- %d new vertices \n",new_vertices.size());
    _vertices.insert(new_vertices.begin(), new_vertices.end());
  }

  void extrude_one_external()
  {
    std::vector<blyr_mvertex> vplus;
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {
      if(it->_lines.size() > 2) {
        std::vector<blyr_ridge *> _internals;
        std::vector<blyr_ridge *> _externals;
        std::vector<MVertex *> _externals_v;
        std::vector<MVertex *> _internals_v;
        for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
          GEdge *ge = it->_gedges[iGe];
          MLine *ml = it->_lines[iGe];
          MVertex *o =
            ml->getVertex(0) == it->_v ? ml->getVertex(1) : ml->getVertex(0);
          blyr_ridge *ridge = getRidge(ge);
          if(ridge->getType() == blyr_ridge::EXTERNAL) {
            _externals.push_back(ridge);
            _externals_v.push_back(o);
          }
          else if(ridge->getType() == blyr_ridge::INTERNAL) {
            _internals.push_back(ridge);
            _internals_v.push_back(o);
          }
        }
        size_t nINTERNAL = _internals.size();
        size_t nEXTERNAL = _externals.size();

        //	printf("%d %d\n",nINTERNAL,nEXTERNAL);

        if(nINTERNAL == (it->_gedges.size() - 1) && nEXTERNAL == 1) {
          // add one normal on the face that is incident to the external ridge
          //  we could add a FAN (commented below) on the face, quite
          //  complicated indeed ... if users really want it, we may code that
          //  feature. Yet, I beleive that fans
          // should only be "embedded" to close a O mesh.

          double initialGuess[2] = {0, 0};
          blyr_ridge *ridge = _externals[0];
          printf("average normals --> %d %d\n", ridge->_f[0]->tag(),
                 ridge->_f[1]->tag());
          SVector3 n1 = it->average_normal(ridge->_f[0]);
          SVector3 n2 = it->average_normal(ridge->_f[1]);
          double thk = blyr_thickness(it->_v->x(), it->_v->y(), it->_v->z());
          SVector3 n = (n1 + n2) * thk;
          printf("%g %g %g -- %g %g %g\n", n1.x(), n1.y(), n1.z(), n2.x(),
                 n2.y(), n2.z());
          SPoint3 p(it->_v->x() + n.x(), it->_v->y() + n.y(),
                    it->_v->z() + n.z());
          GFace *gf = nullptr;
          for(size_t k = 0; k < it->_gfaces.size(); k++) {
            std::vector<GEdge *> e = it->_gfaces[k]->edges();
            if(std::find(e.begin(), e.end(), ridge->_ge) == e.end()) {
              gf = it->_gfaces[k];
              break;
            }
          }
          if(!gf)
            Msg::Error("Topological error in 3D boundary layer generation");
          GPoint gp = gf->closestPoint(p, initialGuess);
          printf("adding a point %g %g %g in face %d\n", n.x(), n.y(), n.z(),
                 gf->tag());
          MVertex *vf =
            new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
          gf->mesh_vertices.push_back(vf);
          blyr_mvertex blv(vf);
          for(size_t j = 0; j < it->_triangles.size(); j++) {
            MTriangle *t = it->_triangles[j];
            blv._gfaces.push_back(gf);
            blv._triangles.push_back(t);
            blv._normals.push_back(it->_normals[j]);
            if(it->_gfaces[j] == gf) {
              for(int k = 0; k < 3; k++) {
                if(t->getVertex(k) == it->_v) { t->setVertex(k, vf); }
              }
            }
          }
          auto ite = _vertices.find(blyr_mvertex(_externals_v[0]));
          if(ite != _vertices.end()) {
            blv._v_per_face.push_back(ite->_v_per_face[0]);
            blv._n_per_vertex.push_back(n);
            blv._f_per_normal.push_back(_externals[0]->_f[0]);
            // add the corner info
            std::vector<MVertex *> fan;
            fan.push_back(ite->_v_per_face[0]);

            it->_v_per_face.push_back(vf);
            it->_n_per_vertex.push_back(n);
            it->_f_per_normal.push_back(gf);
            it->_v_per_face.push_back(ite->_v);
            it->_n_per_vertex.push_back(n);
            it->_f_per_normal.push_back(_externals[0]->_f[0]);
            it->_v_per_face.push_back(ite->_v);
            it->_n_per_vertex.push_back(n);
            it->_f_per_normal.push_back(_externals[0]->_f[1]);

            for(size_t k = 0; k < _internals.size(); k++) {
              std::pair<GFace *, GFace *> pa =
                std::make_pair(_internals[k]->_f[0], _internals[k]->_f[1]);
              it->_v_per_ridge[pa] = fan;
              auto iti = _vertices.find(blyr_mvertex(_internals_v[k]));
              MVertex *o = iti->_v_per_face[0];
              gf->quadrangles.push_back(
                new MQuadrangle(it->_v, iti->_v, o, vf));
              if(_externals[0]->_f[0] == _internals[k]->_f[0] ||
                 _externals[0]->_f[0] == _internals[k]->_f[1]) {
                MVertex *l = iti->extruded_vertex(_externals[0]->_f[0]);
                _externals[0]->_f[0]->quadrangles.push_back(
                  new MQuadrangle(it->_v, ite->_v, l, iti->_v));
              }
              else if(_externals[0]->_f[1] == _internals[k]->_f[0] ||
                      _externals[0]->_f[1] == _internals[k]->_f[1]) {
                MVertex *l = iti->extruded_vertex(_externals[0]->_f[1]);
                _externals[0]->_f[1]->quadrangles.push_back(
                  new MQuadrangle(it->_v, ite->_v, l, iti->_v));
              }
            }
          }

          vplus.push_back(blv);
        }
      }
    }
    for(size_t i = 0; i < vplus.size(); i++)
      if(vplus[i]._v) _vertices.insert(vplus[i]);
  }

  void extrude_vertices_basic()
  {
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {
      if(!it->_triangles.empty()) add_one_normal(*it);
    }
  }

  void extrude_vertices()
  {
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {
      if(it->_lines.empty()) {
        // simple vertex that is extruded along the average of face normals
        //	printf("simple %d\n",it->_v->getNum());
        if(!it->_triangles.empty()) add_one_normal(*it);
        //	printf("simple done\n");
      }
      else if(it->_lines.size() == 2) {
        // simple ridge, look if more than one normal is necessary
        // internal vertex to a  model edge
        GEdge *ge0 = it->_gedges[0];
        GEdge *ge1 = it->_gedges[1];
        // normal case
        blyr_ridge *ridge0 = getRidge(ge0);
        blyr_ridge *ridge1 = getRidge(ge1);
        //	printf("%d %d %g %g %d
        //%d\n",ge0->tag(),ge1->tag(),ridge0->min_angle,ridge0->max_angle,ridge0->getType(),blyr_ridge::FLAT);
        if(ridge0 == nullptr && ridge1 == nullptr) { // not a ridge
          if(!it->_triangles.empty()) add_one_normal(*it);
        }
        else {
          if(ridge0->getType() == blyr_ridge::FLAT) {
            if(!it->_triangles.empty()) add_one_normal(*it);
          }
          else if(ridge0->getType() == blyr_ridge::EXTERNAL) {
            //	    printf("verex %d has 2 lines (%d
            //%d)\n",it->_v->getNum(),ge0->tag(), ge1->tag());
            if(!it->_triangles.empty()) add_one_normal(*it);
            //	    add_fan (*it);
          }
        }
      }
      // standard corner
      else {
        std::vector<blyr_ridge *> _internals;
        std::vector<blyr_ridge *> _externals;
        std::vector<blyr_ridge *> _flats;
        for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
          GEdge *ge = it->_gedges[iGe];
          blyr_ridge *ridge = getRidge(ge);
          if(ridge->getType() == blyr_ridge::EXTERNAL)
            _externals.push_back(ridge);
          else if(ridge->getType() == blyr_ridge::INTERNAL)
            _internals.push_back(ridge);
          else if(ridge->getType() == blyr_ridge::FLAT)
            _flats.push_back(ridge);
        }
        size_t nINTERNAL = _internals.size();
        size_t nEXTERNAL = _externals.size();

        if(nEXTERNAL == it->_gedges.size()) {
          if(!it->_triangles.empty()) add_one_normal(*it);
          //    CAN BE DONE TOO BUT NOT SURE THIS "FAN" COMPLEXITY IS USEFUL
          //	  add_fan (*it);
          //	  add_external_corner(*it);
        }
        // internal corner
        else if(nINTERNAL == it->_gedges.size()) {
          // ALREADY DONE (see function below)
        }
        else if(nINTERNAL == 0 && nEXTERNAL == 0) {
          // ALL IS FLAT  ...
          if(!it->_triangles.empty()) add_one_normal(*it);
        }
        else if(nINTERNAL == (it->_gedges.size() - 1) && nEXTERNAL == 1) {
          // ALREADY DONE (see function above)
        }
        else {
          Msg::Error("Corner with %d internal ridges and %d external ridges "
                     "should be coded",
                     nINTERNAL, nEXTERNAL);
          printf("EXTERNALS :");
          for(size_t i = 0; i < _externals.size(); i++)
            printf("%d ", _externals[i]->_ge->tag());
          printf("\n");
          printf("INTERNALS :");
          for(size_t i = 0; i < _internals.size(); i++)
            printf("%d ", _internals[i]->_ge->tag());
          printf("\n");
        }
      }
    }
    //    printf("done\n");
  }

  //---------------+---------------+---------------+---------------+---------------+
  //  I  N  T  E  R  N  A  L    C  O  R  N  E  R  S
  //---------------+---------------+---------------+---------------+---------------+
  // --------       extrude vertices on model edges
  // --------------------------------
  //  MOST COMPLICATED PART OF THAT CODE
  // ------------------------------------------------------------------------------+

  void extrude_vertices_on_edges()
  {
    std::vector<blyr_mvertex> additional_vertices;
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {
      MVertex *v = it->_v;

      // create a new vertex for every internal ridges
      std::map<GEdge *, MVertex *> e2v;

      std::vector<blyr_ridge *> _internals;
      std::vector<blyr_ridge *> _externals;
      std::vector<blyr_ridge *> _flats;
      for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
        GEdge *ge = it->_gedges[iGe];
        blyr_ridge *ridge = getRidge(ge);
        if(ridge->getType() == blyr_ridge::EXTERNAL)
          _externals.push_back(ridge);
        else if(ridge->getType() == blyr_ridge::INTERNAL)
          _internals.push_back(ridge);
        else if(ridge->getType() == blyr_ridge::FLAT)
          _flats.push_back(ridge);
      }

      if(_internals.empty()) continue;
      if(it->_lines.size() <= 2) continue;

      SVector3 NR(0, 0, 0);
      double thk = blyr_thickness(v->x(), v->y(), v->z());
      std::vector<blyr_mvertex> vplus;
      std::vector<blyr_mvertex> vplusf;
      for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
        GEdge *ge = it->_gedges[iGe];
        Range<double> bounds = ge->parBounds(0);
        blyr_ridge *ridge = getRidge(ge);
        bool create_vertices_on_edge =
          _externals.empty() || ridge->getType() == blyr_ridge::EXTERNAL;
        if(create_vertices_on_edge) {
          double t = 0.0;
          if(ge->getBeginVertex() &&
             v == ge->getBeginVertex()->mesh_vertices[0]) {
            SVector3 tgt = ge->firstDer(bounds.low());
            t = bounds.low() + thk / tgt.norm();
          }
          else if(ge->getEndVertex() &&
                  v == ge->getEndVertex()->mesh_vertices[0]) {
            SVector3 tgt = ge->firstDer(bounds.high());
            t = bounds.high() - thk / tgt.norm();
          }
          else
            Msg::Error("Topological error in boundary layer");
          GPoint gp = ge->point(t);
          MEdgeVertex *mev = new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, t);
          ge->mesh_vertices.push_back(mev);
          e2v[ge] = mev;
          vplus.push_back(blyr_mvertex(mev));
          NR +=
            SVector3(mev->x() - v->x(), mev->y() - v->y(), mev->z() - v->z());
        }
        else {
          vplus.push_back(blyr_mvertex(nullptr));
        }
      }

      // CREATE A VOLUME VERTEX IN CASE OF A FULL INTERNAL CORNER
      MVertex *vr = nullptr;
      if(_externals.empty()) {
        vr =
          new MVertex(v->x() + NR.x(), v->y() + NR.y(), v->z() + NR.z(), _gr);
        _gr->mesh_vertices.push_back(vr);
      }

      // ADD POINTS ON BOTH NEIGHBORING FACES IF RIDGE IS INTERNAL
      for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
        if(vplus[iGe]._v != nullptr) {
          GEdge *gei = it->_gedges[iGe];
          blyr_ridge *ridgei = getRidge(gei);

          for(size_t jGe = 0; jGe < it->_gedges.size(); jGe++) {
            if(jGe != iGe) {
              GEdge *gej = it->_gedges[jGe];
              blyr_ridge *ridgej = getRidge(gej);
              GFace *gf = haveTowGEdges(_faces, gei, gej);
              if(gf) {
                MVertex *vf = nullptr;
                //		printf("s %d %d %d -- %d %d -- %d -- %p
                //%p\n",v->getNum(),iGe,jGe,gei->tag(),gej->tag(),gf->tag(),vplus[iGe]._v,vplus[jGe]._v);

                SVector3 dx1(vplus[iGe]._v->x() - v->x(),
                             vplus[iGe]._v->y() - v->y(),
                             vplus[iGe]._v->z() - v->z());
                if((vplus[jGe]._v != nullptr) && (jGe > iGe)) {
                  SVector3 dx2(vplus[jGe]._v->x() - v->x(),
                               vplus[jGe]._v->y() - v->y(),
                               vplus[jGe]._v->z() - v->z());
                  SPoint3 PNEW(v->x() + dx1.x() + dx2.x(),
                               v->y() + dx1.y() + dx2.y(),
                               v->z() + dx1.z() + dx2.z());

                  // NEW POINT IS IN THE VOLUME
                  if(ridgei->getType() == blyr_ridge::EXTERNAL &&
                     ridgej->getType() == blyr_ridge::EXTERNAL &&
                     !_internals.empty()) {
                    printf("ON VOLUME %d\n", gf->tag());
                    vf = new MVertex(PNEW.x(), PNEW.y(), PNEW.z(), _gr);
                    _gr->mesh_vertices.push_back(vf);

                    it->_n_per_vertex.push_back(dx1);
                    it->_n_per_vertex.push_back(dx2);
                    it->_v_per_face.push_back(vplus[iGe]._v);
                    it->_v_per_face.push_back(vplus[jGe]._v);
                    std::vector<GEdge *> e0 = _internals[0]->_f[0]->edges();
                    if(std::find(e0.begin(), e0.end(), gei) != e0.end()) {
                      it->_f_per_normal.push_back(_internals[0]->_f[0]);
                      it->_f_per_normal.push_back(_internals[0]->_f[1]);
                    }
                    else {
                      it->_f_per_normal.push_back(_internals[0]->_f[1]);
                      it->_f_per_normal.push_back(_internals[0]->_f[0]);
                    }
                    std::vector<MVertex *> fan;
                    fan.push_back(vf);
                    std::pair<GFace *, GFace *> pa = std::make_pair(
                      _internals[0]->_f[0], _internals[0]->_f[1]);
                    it->_v_per_ridge[pa] = fan;

                    vplus[iGe]._v_per_face.push_back(vf);
                    vplus[jGe]._v_per_face.push_back(vf);
                    vplus[iGe]._n_per_vertex.push_back(dx1);
                    vplus[jGe]._n_per_vertex.push_back(dx2);
                    vplus[iGe]._f_per_normal.push_back(_internals[0]->_f[0]);
                    vplus[jGe]._f_per_normal.push_back(_internals[0]->_f[1]);
                  }
                  else {
                    double initialGuess[2];
                    GPoint p = gf->closestPoint(PNEW, initialGuess);
                    vf = new MFaceVertex(p.x(), p.y(), p.z(), gf, p.u(), p.v());

                    if(_externals.empty()) {
                      blyr_mvertex blv(vf);
                      blv._v_per_face.push_back(vr);
                      blv._f_per_normal.push_back(gf);
                      blv._n_per_vertex.push_back(dx1); // wrong but who cares
                      vplusf.push_back(blv);
                    }

                    gf->mesh_vertices.push_back(vf);
                    gf->quadrangles.push_back(
                      new MQuadrangle(v, vplus[iGe]._v, vf, vplus[jGe]._v));

                    dx1.normalize();
                    dx2.normalize();
                    vplus[iGe]._v_per_face.push_back(vf);
                    vplus[jGe]._v_per_face.push_back(vf);
                    vplus[iGe]._n_per_vertex.push_back(dx1);
                    vplus[jGe]._n_per_vertex.push_back(dx2);
                    vplus[iGe]._f_per_normal.push_back(gf);
                    vplus[jGe]._f_per_normal.push_back(gf);
                  }
                }
                else if(vplus[jGe]._v == nullptr) {
                  //		  printf("-------------------------------------->%d
                  //%d %d -- %d %d -- %d -- %p
                  //%p\n",v->getNum(),iGe,jGe,gei->tag(),gej->tag(),gf->tag(),vplus[iGe]._v,vplus[jGe]._v);
                  //		  printf("-------------------------------------- >
                  //%d -- %d %d -- %d %d\n",gf->tag(), gei->tag(),
                  // gej->tag(),iGe,jGe);
                  vf = vplus[iGe]._v;
                }
                if(!vf || vf->onWhat() != _gr) {
                  if(!vf) printf("a bon\n");
                  std::vector<MTriangle *> remaining_t;
                  std::vector<GFace *> remaining_f;
                  std::vector<SVector3> remaining_n;
                  for(size_t j = 0; j < it->_triangles.size(); j++) {
                    MTriangle *t = it->_triangles[j];
                    if(it->_gfaces[j] == gf) {
                      for(int k = 0; k < 3; k++) {
                        if(vf && t->getVertex(k) == v) t->setVertex(k, vf);
                      }
                      vplus[iGe]._triangles.push_back(t);
                      vplus[iGe]._gfaces.push_back(it->_gfaces[j]);
                      vplus[iGe]._normals.push_back(it->_normals[j]);
                    }
                    else {
                      remaining_t.push_back(t);
                      remaining_f.push_back(it->_gfaces[j]);
                      remaining_n.push_back(it->_normals[j]);
                    }
                  }
                }
                //		printf("AFTER2 %d %d %d -- %d %d -- %d -- %p
                //%p\n",v->getNum(),iGe,jGe,gei->tag(),gej->tag(),gf->tag(),vplus[iGe]._v,vplus[jGe]._v);
              }
            }
          }
        }
        if(vr) {
          std::vector<MVertex *> fan;
          fan.push_back(vr);
          for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
            if(vplus[iGe]._v) {
              GEdge *gei = it->_gedges[iGe];
              blyr_ridge *ridgei = getRidge(gei);
              std::pair<GFace *, GFace *> pa =
                std::make_pair(ridgei->_f[0], ridgei->_f[1]);
              vplus[iGe]._v_per_ridge[pa] = fan;
            }
          }
        }
      }
      std::vector<MLine *> update_lines;
      std::vector<GEdge *> update_gedges;
      // update on mesh edges
      for(size_t iGe = 0; iGe < it->_gedges.size(); iGe++) {
        GEdge *ge = it->_gedges[iGe];
        MLine *ml = it->_lines[iGe];
        auto itev = e2v.find(ge);
        if(itev != e2v.end()) {
          MVertex *mev = itev->second;
          if(ml->getVertex(0) == v)
            ml->setVertex(0, mev);
          else
            ml->setVertex(1, mev);
          MLine *newl = new MLine(v, mev);
          update_lines.push_back(newl);
          update_gedges.push_back(ge);
          if(vplus[iGe]._v) {
            vplus[iGe]._lines.push_back(ml);
            vplus[iGe]._gedges.push_back(ge);
            vplus[iGe]._lines.push_back(newl);
            vplus[iGe]._gedges.push_back(ge);
          }
          ge->lines.push_back(newl);
        }
        else {
          update_lines.push_back(ml);
          update_gedges.push_back(ge);
        }
      }

      //	it->_triangles.clear();
      //	it->_gfaces.clear();
      //	it->_normals.clear();

      it->_lines = update_lines;
      it->_gedges = update_gedges;
      for(size_t i = 0; i < vplus.size(); i++)
        if(vplus[i]._v) additional_vertices.push_back(vplus[i]);
      if(vplusf.size())
        additional_vertices.insert(additional_vertices.end(), vplusf.begin(),
                                   vplusf.end());
    }
    //    printf("%d additional vertices\n",additional_vertices.size());

    _vertices.insert(additional_vertices.begin(), additional_vertices.end());
    //    printf("lous\n");
  }
  //---------------+---------------+---------------+---------------+---------------+

  void extrude_triangles()
  {
    for(size_t i = 0; i < _faces.size(); i++) {
      for(size_t j = 0; j < _faces[i]->triangles.size(); j++) {
        MVertex *v0 = _faces[i]->triangles[j]->getVertex(0);
        MVertex *v1 = _faces[i]->triangles[j]->getVertex(1);
        MVertex *v2 = _faces[i]->triangles[j]->getVertex(2);
        auto it0 = _vertices.find(v0);
        auto it1 = _vertices.find(v1);
        auto it2 = _vertices.find(v2);
        MVertex *o0 = it0->extruded_vertex(_faces[i]);
        MVertex *o1 = it1->extruded_vertex(_faces[i]);
        MVertex *o2 = it2->extruded_vertex(_faces[i]);
        //	printf("%p %p %p\n",o0,o1,o2);
        if(o0 && o1 && o2)
          _gr->prisms.push_back(new MPrism(v0, v1, v2, o0, o1, o2));
      }
    }
    //    printf("a\n");
  }

  void extrude_ridges()
  {
    for(size_t i = 0; i < _ridges.size(); i++) {
      blyr_ridge &r = _ridges[i];
      GFace *f0 = r._f[0];
      GFace *f1 = r._f[1];
      std::pair<GFace *, GFace *> pa_pos = std::make_pair(f0, f1);
      std::pair<GFace *, GFace *> pa_neg = std::make_pair(f1, f0);

      //      printf("ridge %d %d\n",f0->tag(),f1->tag());

      if(r.N_SUBNORMALS) {
        for(size_t j = 0; j < r._ge->lines.size(); j++) {
          MLine *l = r._ge->lines[j];
          MVertex *v0 = l->getVertex(0);
          MVertex *v1 = l->getVertex(1);
          auto it0 = _vertices.find(v0);
          auto it1 = _vertices.find(v1);

          MVertex *o00 = it0->extruded_vertex(f0);
          MVertex *o01 = it0->extruded_vertex(f1);
          MVertex *o10 = it1->extruded_vertex(f0);
          MVertex *o11 = it1->extruded_vertex(f1);

          //	  printf("%d %d %p %p %p
          //%p\n",v0->getNum(),v1->getNum(),o00,o01,o10,o11);

          std::vector<MVertex *> fan0;
          std::vector<MVertex *> fan1;

          auto it = it0->_v_per_ridge.find(pa_pos);
          if(it != it0->_v_per_ridge.end())
            fan0 = it->second;
          else {
            it = it0->_v_per_ridge.find(pa_neg);
            if(it != it0->_v_per_ridge.end()) {
              fan0 = it->second;
              std::reverse(fan0.begin(), fan0.end());
            }
          }
          it = it1->_v_per_ridge.find(pa_pos);
          if(it != it1->_v_per_ridge.end())
            fan1 = it->second;
          else {
            it = it1->_v_per_ridge.find(pa_neg);
            if(it != it1->_v_per_ridge.end()) {
              fan1 = it->second;
              std::reverse(fan1.begin(), fan1.end());
            }
          }

          // printf("%d %d %d\n",fan0.size(),fan1.size(),r.N_SUBNORMALS);
          if(fan0.size() == r.N_SUBNORMALS && fan1.size() == r.N_SUBNORMALS) {
            for(std::size_t k = 0; k <= r.N_SUBNORMALS; k++) {
              MVertex *v00 = (k == 0 ? o00 : fan0[k - 1]);
              MVertex *v10 = (k == 0 ? o10 : fan1[k - 1]);
              MVertex *v01 = (k == r.N_SUBNORMALS ? o01 : fan0[k]);
              MVertex *v11 = (k == r.N_SUBNORMALS ? o11 : fan1[k]);
              // printf("%p %p %p %p\n",v00,v01,v10,v11);
              _gr->prisms.push_back(new MPrism(v0, v00, v01, v1, v10, v11));
            }
          }
        }
      }
    }
    //    printf("gasp\n");
  }

  void extrude_external_corners()
  {
    auto it = _vertices.begin();
    for(; it != _vertices.end(); ++it) {
      const blyr_mvertex &v = *it;
      for(size_t j = 0; j < v._triangles_at_corner.size(); j++) {
        MTriangle *t = v._triangles_at_corner[j];
        /// TEMPORARY --> SHOULD BE A TET BUT I PREFER THAT FOR NOW FOR VIZU
        //	printf("%p %p %p\n",
        // t->getVertex(0),t->getVertex(1),t->getVertex(2));
        _gr->prisms.push_back(new MPrism(v._v, v._v, v._v, t->getVertex(0),
                                         t->getVertex(1), t->getVertex(2)));
      }
    }
  }

  double blyr_thickness(double x, double y, double z) { return _thickness; }
};

bool createBoundaryLayerOneLayer(GRegion *gr, std::vector<GFace *> &bls)
{
  Msg::Info("Computing boundary layer mesh of volume %d", gr->tag());

  bool basic = false;

  blyr_manager mgr(gr, bls, 0.015);

  //  for (size_t i=0;i<gr->tetrahedra.size();i++)delete gr->tetrahedra[i];
  gr->tetrahedra.clear();
  //  for (size_t i=0;i<gr->mesh_vertices.size();i++)delete
  //  gr->mesh_vertices[i];
  gr->mesh_vertices.clear();

  if(basic) { mgr.extrude_vertices_basic(); }
  else {
    Msg::Info("Classifying ridges (INTERNAL / EXTERNAL / FLAT)");
    mgr.classify_ridges();
    Msg::Info("Extrusion of vertices for internal corners");
    mgr.extrude_vertices_on_edges();
    Msg::Info("Extrusion of vertices for internal edges");
    mgr.extrude_vertices_on_faces();
    Msg::Info("Extruding ridges on faces");
    mgr.extrude_ridges_on_faces();
    Msg::Info("Treating REGULAR vertices");
    mgr.extrude_vertices();
    Msg::Info("Treating corners with one external ridge and others internal");
    mgr.extrude_one_external();

    Msg::Info("Generating ONLE LAYER of 3D elements");
    mgr.extrude_external_corners();
    mgr.extrude_ridges();
  }
  mgr.extrude_triangles();

  return true;
}
