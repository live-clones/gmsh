// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshQuadGeometry.h"
#include <map>
#include <iostream>
#include "meshGFace.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "discreteFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "Options.h"
#include "fastScaledCrossField.h"

#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing

#if defined(_OPENMP)
#include <omp.h>
#endif


#if defined(HAVE_MESQUITE)
#include "Mesquite_all_headers.hpp"
#endif

using std::vector;
using std::array;

#if defined(HAVE_MESQUITE)
  struct GFaceQuadMeshData {
    vector<double> coords;
    vector<int> fixed;
    vector<MVertex*> origin;
    vector<unsigned long> quads;
  };

bool fillDataFromGFace(const GFace* gf, GFaceQuadMeshData& M,
  std::unordered_map<MVertex*,size_t>& old2new) {
  size_t vcount = 0;
  M.coords.reserve(3*gf->quadrangles.size());
  M.fixed.reserve(gf->quadrangles.size());
  M.origin.reserve(gf->quadrangles.size());
  M.quads.resize(4*gf->quadrangles.size());
  size_t qcount = 0;
  for (MQuadrangle* q: gf->quadrangles) {
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = q->getVertex(lv);
      auto it = old2new.find(v);
      size_t nv;
      if (it == old2new.end()) {
        old2new[v] = vcount;
        nv = vcount;
        vcount += 1;
        M.coords.push_back(v->x());
        M.coords.push_back(v->y());
        M.coords.push_back(v->z());
        M.origin.push_back(v);
        M.fixed.push_back(0);
      } else {
        nv = it->second;
      }
      M.quads[4*qcount+lv] = nv;
    }
    qcount += 1;
  }
  M.coords.shrink_to_fit();
  M.fixed.shrink_to_fit();
  M.origin.shrink_to_fit();
  M.quads.shrink_to_fit();

  return true;
}

using namespace Mesquite;

void quad_normal(const double* coords, unsigned long v0, unsigned long v1, unsigned long v2, unsigned long v3,
    double* normal) {
  double t_u[3];
  double t_v[3];
  for (size_t d = 0; d < 3; ++ d) {
    t_u[d] = 0.5 * (coords[3*v1+d]+coords[3*v2+d]-coords[3*v0+d]-coords[3*v3+d]);
    t_v[d] = 0.5 * (coords[3*v2+d]+coords[3*v3+d]-coords[3*v0+d]-coords[3*v1+d]);
  }
  normal[0] = t_u[1] * t_v[2] - t_v[1] * t_u[2];
  normal[1] = -(t_u[0] * t_v[2] - t_v[0] * t_u[2]);
  normal[2] = t_u[0] * t_v[1] - t_v[0] * t_u[1];
  double len = std::sqrt( normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
  normal[0] /= len;
  normal[1] /= len;
  normal[2] /= len;
}

GPoint project(MVertex* mv, SPoint3& query) {
  GFace* gf = dynamic_cast<GFace*>(mv->onWhat());
  if (gf != NULL) {
    SPoint2 uv;
    mv->getParameter(0,uv[0]);
    mv->getParameter(1,uv[1]);
    GPoint proj = gf->closestPoint(query,uv);
    return proj;
  } else {
    GEdge* ge = dynamic_cast<GEdge*>(mv->onWhat());
    if (ge != NULL) {
      double t;
      mv->getParameter(0,t);
      GPoint proj = ge->closestPoint(query,t);
      return proj;
    } else {
      GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
      if (gv != NULL) {
        GPoint proj(gv->x(),gv->y(),gv->z(),gv);
        return proj;
      } 
    }
  }
  GPoint proj;
  proj.setNoSuccess();
  return proj;
}

bool closestBoundaryPoint(const GFaceQuadMeshData& M, const SPoint3& query, SPoint3& closest) {
  double dMin = DBL_MAX;
  MVertex* best = NULL;
  for (MVertex* v: M.origin) {
    GFace* gf = dynamic_cast<GFace*>(v->onWhat());
    if (gf != NULL) continue;
    double d = query.distance(v->point());
    if (d < dMin) {
      dMin = d;
      best = v;
    }
  }
  if (best == NULL) return false;
  closest = best->point();
  return true;
}


class MeshDomainGFace : public MeshDomain
{
  public:

    MeshDomainGFace(GFace * gf_, const GFaceQuadMeshData& M_): gf(gf_), M(M_) {}

    virtual ~MeshDomainGFace() {}

    void snap_to( Mesh::VertexHandle entity_handle, Vector3D& coordinat ) const {
      size_t v = (size_t) (entity_handle);
      if (v >= M.origin.size()) { return; }
      MVertex* mv = M.origin[v];
      if (mv == NULL) { return; }
      SPoint3 query(coordinat.x(),coordinat.y(),coordinat.z());
      GPoint proj = project(mv,query);
      if (proj.succeeded()) {
        coordinat.set(proj.x(),proj.y(),proj.z());
      } else {
        Msg::Debug("MeshDomainGFace::snap_to(): failed to projected vertex %li, query=(%f,%f,%f), initial_position=(%f,%f,%f)", 
            v, query.x(),query.y(),query.z(),mv->x(),mv->y(),mv->z());
      }
    }

    void vertex_normal_at( Mesh::VertexHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t v = (size_t) (entity_handle);
      if (v >= M.origin.size()) { return; }
      MVertex* mv = M.origin[v];
      if (mv == NULL) { return; }
      SPoint3 query(coordinate.x(),coordinate.y(),coordinate.z());
      GPoint proj = project(mv,query);
      if (proj.succeeded()) {
        GFace* cgf = dynamic_cast<GFace*>(mv->onWhat());
        if (cgf != NULL) {
          SPoint2 uv(proj.u(),proj.v());
          SVector3 n = gf->normal(uv);
          coordinate.set(n.data());
        } 
      } 
      coordinate.set(0.,0.,0.);
    }

    void element_normal_at( Mesquite::Mesh::ElementHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t f = (size_t) (entity_handle);
      // TODO: project center and use CAD normal ?
      double n[3];
      quad_normal(M.coords.data(), M.quads[4*f+0], M.quads[4*f+1], M.quads[4*f+2], M.quads[4*f+3], n);
      coordinate.set(n);
    }

    void vertex_normal_at( const Mesh::VertexHandle* handles,
        Vector3D coordinates[],
        unsigned count,
        MsqError& err ) const {
      for (size_t i = 0; i < count; ++i) {
        vertex_normal_at(handles[i], coordinates[i]);
      }
      return;
    }

    void closest_point( Mesh::VertexHandle handle,
        const Vector3D& position,
        Vector3D& closest,
        Vector3D& normal,
        MsqError& err ) const {
      size_t v = (size_t) (handle);
      if (v >= M.origin.size()) {
        MSQ_SETERR(err)("MeshDomainGFace: VertexHandle not found", MsqError::INVALID_ARG);
        return;
      }
      MVertex* mv = M.origin[v];
      if (mv == NULL) {
        MSQ_SETERR(err)("MeshDomainGFace: MVertex* is null", MsqError::INVALID_ARG);
        return;
      }
      SPoint3 query(position.x(),position.y(),position.z());
      GPoint proj = project(mv,query);
      if (proj.succeeded()) {
        closest.set(proj.x(),proj.y(),proj.z());
        GFace* cgf = dynamic_cast<GFace*>(mv->onWhat());
        if (cgf != NULL) {
          SPoint2 uv(proj.u(),proj.v());
          SVector3 n = gf->normal(uv);
          normal.set(n.data());
        } else {
          normal.set(0.,0.,0.);
        }
        return;
      } else {
        GFace* dgf = dynamic_cast<GFace*>(mv->onWhat());
        SPoint3 clp;
        bool okc = closestBoundaryPoint(M, query, clp);
        if (okc) {
          closest.set(clp.data());
          normal.set(0.,0.,0.);
          return;
        }
        Msg::Debug("MeshDomainGFace::closest_point(): failed to projected vertex %li, query=(%f,%f,%f)", v, query.x(),query.y(),query.z());
        GEdge* dge = dynamic_cast<GEdge*>(mv->onWhat());
        GVertex* dgv = dynamic_cast<GVertex*>(mv->onWhat());
        Msg::Debug(" entity casts: GFace* %p, GEdge* %p, GVertex* %p", dgf, dge, dgv);
        MSQ_SETERR(err)("MeshDomainGFace::closest_point(): projection failed", MsqError::INVALID_ARG);
      } 
    }

    void domain_DoF( const Mesh::VertexHandle* handle_array,
        unsigned short* dof_array,
        size_t num_vertices,
        MsqError& err ) const {
      for (size_t i = 0; i < num_vertices; ++i) {
        size_t v = (size_t) handle_array[i];
        MVertex* mv = M.origin[v];
        GFace* cur_gf = dynamic_cast<GFace*>(mv->onWhat());
        if (cur_gf != NULL) {
          dof_array[i] = 2;
        } else {
          GEdge* ge = dynamic_cast<GEdge*>(mv->onWhat());
          if (ge != NULL) {
            dof_array[i] = 0;
          } else {
            GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
            if (gv != NULL) {
              dof_array[i] = 0;
            } else {
              MSQ_SETERR(err)("MeshDomainGFace: MVertex* has no valid entity", MsqError::INVALID_ARG);
              return;
            }
          }
        }
      }
    }

  private:
    GFace* gf;
    const GFaceQuadMeshData& M;
};



#endif

int optimizeQuadGeometry(GFace* gf) {
#if defined(HAVE_MESQUITE)

  try {
    std::unordered_map<MVertex*,size_t> old2new;
    GFaceQuadMeshData M;
    fillDataFromGFace(gf, M, old2new);

    Mesquite::ArrayMesh mesh(3, 
        M.coords.size()/3,M.coords.data(),M.fixed.data(),
        M.quads.size()/4,Mesquite::QUADRILATERAL,M.quads.data());

    MeshDomainGFace domain(gf, M);

    for (size_t i = 0; i < M.origin.size(); ++i) {
      MVertex* v = M.origin[i];
      GEntity* ent = v->onWhat();
      if (dynamic_cast<GEdge*>(ent) != NULL) {
        M.fixed[i] = 1;
      } else if (dynamic_cast<GVertex*>(ent) != NULL) {
        M.fixed[i] = 1;
      }
    }

    Mesquite::MeshDomainAssoc mesh_and_domain(&mesh,&domain,true);
    Mesquite::MsqPrintError err(std::cout);

    bool untangle = true;
    if (untangle) {
      Mesquite::UntangleWrapper smoother;
      // smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::SHAPESIZE);
      smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::BETA);
      smoother.set_vertex_movement_limit_factor(1.e-3);
      // smoother.enable_culling(true);
      smoother.run_instructions(&mesh_and_domain, err); 
    } else {
      Mesquite::ShapeImprovementWrapper smoother;
      smoother.run_instructions(&mesh_and_domain, err); 
    }

    for (size_t i = 0; i < M.origin.size(); ++i) {
      M.origin[i]->x() = M.coords[3*i+0];
      M.origin[i]->y() = M.coords[3*i+1];
      M.origin[i]->z() = M.coords[3*i+2];
    }
  } catch (...) {
    Msg::Error("- Face %i: failed to optimize with Mesquite (%li quads)", gf->tag(), gf->quadrangles.size());
  }


#else
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
#endif
  return 0;
}
