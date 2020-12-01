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
#include "meshSurfaceProjection.h"
#include "meshWinslow2d.h"

#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing
#include "robin_hood.h"
#include "meshQuadUtils.h"

#if defined(_OPENMP)
#include <omp.h>
#endif


#if defined(HAVE_MESQUITE)
#include "Mesquite_all_headers.hpp"
#endif

using std::vector;
using std::array;
using namespace QuadUtils;

#if defined(HAVE_MESQUITE)
  struct QuadMeshData {
    vector<double> coords;
    vector<int> fixed;
    vector<MVertex*> origin;
    vector<unsigned long> quads;
  };

bool fillDataFromGFace(const GFace* gf, QuadMeshData& M,
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

bool fillDataFromCavity(
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    QuadMeshData& M,
    std::unordered_map<MVertex*,size_t>& old2new) {
  M.coords.reserve(3*freeVertices.size());
  M.fixed.reserve(freeVertices.size());
  M.origin.reserve(freeVertices.size());
  M.quads.resize(4*elements.size());
  size_t vcount = 0;
  for (MVertex* v: freeVertices) {
    old2new[v] = vcount;
    vcount += 1;
    M.coords.push_back(v->x());
    M.coords.push_back(v->y());
    M.coords.push_back(v->z());
    M.origin.push_back(v);
    M.fixed.push_back(0);
  }
  size_t qcount = 0;
  for (MElement* q: elements) {
    if (q->getNumVertices() != 4) return false;
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
        M.fixed.push_back(1);
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

bool closestBoundaryPoint(const QuadMeshData& M, const SPoint3& query, SPoint3& closest) {
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

    MeshDomainGFace(GFace * gf_, const QuadMeshData& M_): gf(gf_), M(M_) {}

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
    const QuadMeshData& M;
};

class MeshDomainSurfaceProjector : public MeshDomain
{
  public:

    MeshDomainSurfaceProjector(SurfaceProjector * sp_, const QuadMeshData& M_): sp(sp_), M(M_) {
      projectionCache = new std::unordered_map<Mesh::VertexHandle,size_t>;
    }

    virtual ~MeshDomainSurfaceProjector() {
      delete projectionCache;
    }

    void snap_to( Mesh::VertexHandle entity_handle, Vector3D& coordinat ) const {
      size_t cache = (*projectionCache)[entity_handle];
      SPoint3 query(coordinat.x(),coordinat.y(),coordinat.z());
      GPoint proj = sp->closestPoint(query.data(),cache,true,true);
      if (proj.succeeded()) {
        coordinat.set(proj.x(),proj.y(),proj.z());
        (*projectionCache)[entity_handle] = cache;
      } else {
        Msg::Debug("MeshDomainSurfaceProjector::snap_to(): failed to projected query=(%f,%f,%f)", query.x(),query.y(),query.z());
      }
    }

    void vertex_normal_at( Mesh::VertexHandle entity_handle,
        Vector3D& coordinate ) const {
      size_t cache = (*projectionCache)[entity_handle];
      SPoint3 query(coordinate.x(),coordinate.y(),coordinate.z());
      GPoint proj = sp->closestPoint(query.data(),cache,true,false);
      if (proj.succeeded()) {
        SPoint2 uv(proj.u(),proj.v());
        SVector3 n = sp->gf->normal(uv);
        // n = -1. * n;
        coordinate.set(n.data());
        (*projectionCache)[entity_handle] = cache;
      } else {
        Msg::Debug("MeshDomainSurfaceProjector::vertex_normal_at(): failed to projected query=(%f,%f,%f)", query.x(),query.y(),query.z());
        coordinate.set(0.,0.,0.);
      }
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
      size_t cache = (*projectionCache)[handle];
      SPoint3 query(position.x(),position.y(),position.z());
      GPoint proj = sp->closestPoint(query.data(),cache,true,true);
      if (proj.succeeded()) {
        closest.set(proj.x(),proj.y(),proj.z());
        SPoint2 uv(proj.u(),proj.v());
        SVector3 n = sp->gf->normal(uv);
        // n = -1. * n;
        normal.set(n.data());
        (*projectionCache)[handle] = cache;
      } else {
        Msg::Debug("MeshDomainSurfaceProjector::closestPoint(): failed to projected query=(%f,%f,%f)", query.x(),query.y(),query.z());
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
            dof_array[i] = 1;
          } else {
            GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
            if (gv != NULL) {
              dof_array[i] = 0;
            } else {
              MSQ_SETERR(err)("MeshDomainSurfaceProjector: MVertex* has no valid entity", MsqError::INVALID_ARG);
              return;
            }
          }
        }
      }
    }

  private:
    SurfaceProjector* sp;
    const QuadMeshData& M;
    std::unordered_map<Mesh::VertexHandle,size_t>* projectionCache;
};




int optimizeQuadGeometry(GFace* gf) {

  try {
    std::unordered_map<MVertex*,size_t> old2new;
    QuadMeshData M;
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
      if (Msg::GetVerbosity() < 99) {
        smoother.quality_assessor().disable_printing_results();
      }
      smoother.run_instructions(&mesh_and_domain, err); 
    } else {
      Mesquite::ShapeImprovementWrapper smoother;
      if (Msg::GetVerbosity() < 99) {
        smoother.quality_assessor().disable_printing_results();
      }
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

  return 0;
}

void computeQualitySICN(const std::vector<MElement*>& elements, std::vector<double>& quality,
    double& minSICN, double& avgSICN) {
  minSICN = DBL_MAX;
  avgSICN = 0.;
  quality.resize(elements.size());
  for (size_t i = 0; i < elements.size(); ++i)  {
    quality[i] = elements[i]->minSICNShapeMeasure();
    minSICN = std::min(minSICN,quality[i]);
    avgSICN += quality[i];
  }
  if (elements.size() > 0) avgSICN /= double(elements.size());
}

void computeQualitySICN(const std::vector<MQuadrangle*>& elements, std::vector<double>& quality,
    double& minSICN, double& avgSICN) {
  minSICN = DBL_MAX;
  avgSICN = 0.;
  quality.resize(elements.size());
  for (size_t i = 0; i < elements.size(); ++i)  {
    quality[i] = elements[i]->minSICNShapeMeasure();
    minSICN = std::min(minSICN,quality[i]);
    avgSICN += quality[i];
  }
  if (elements.size() > 0) avgSICN /= double(elements.size());
}
int quadQualityStats(const std::vector<MElement*>& elements, double& qualityMin, double& qualityAvg) {
  vector<double> quality(elements.size());
  computeQualitySICN(elements, quality, qualityMin, qualityAvg);
  return 0;
}
int quadQualityStats(const std::vector<MQuadrangle*>& elements, double& qualityMin, double& qualityAvg) {
  vector<double> quality(elements.size());
  computeQualitySICN(elements, quality, qualityMin, qualityAvg);
  return 0;
}

int optimizeQuadCavity(
    const MesquiteOptions& opt,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    double& qualityMin,
    double& qualityAvg) {
  if (elements.size() == 0 || freeVertices.size() == 0) return 0;

  double minSICN, avgSICN;
  try {
    quadQualityStats(elements, minSICN, avgSICN);

    std::unordered_map<MVertex*,size_t> old2new;
    QuadMeshData M;
    fillDataFromCavity(elements, freeVertices, M, old2new);

    Mesquite::ArrayMesh mesh(3, 
        M.coords.size()/3,M.coords.data(),M.fixed.data(),
        M.quads.size()/4,Mesquite::QUADRILATERAL,M.quads.data());

    MeshDomainSurfaceProjector domain(sp, M);

    bool full_compatibility_check = false;
    bool proceed = true;
    bool skip_compatibility_check = true;
    Mesquite::MeshDomainAssoc mesh_and_domain(&mesh,&domain,full_compatibility_check,proceed,skip_compatibility_check);
    Mesquite::MsqPrintError err(std::cout);

    bool untangle = (minSICN < 0.);
    if (untangle) {
      Mesquite::UntangleWrapper smoother;
      // smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::SHAPESIZE);
      smoother.set_untangle_metric(Mesquite::UntangleWrapper::UntangleMetric::BETA);
      smoother.set_vertex_movement_limit_factor(1.e-3);
      // smoother.enable_culling(true);
      if (Msg::GetVerbosity() < 999) {
        smoother.quality_assessor().disable_printing_results();
      }
      if (opt.cpu_time_limit_sec != 0.) smoother.set_cpu_time_limit(opt.cpu_time_limit_sec);
      smoother.run_instructions(&mesh_and_domain, err); 
      for (size_t i = 0; i < freeVertices.size(); ++i) {
        M.origin[i]->x() = M.coords[3*i+0];
        M.origin[i]->y() = M.coords[3*i+1];
        M.origin[i]->z() = M.coords[3*i+2];
      }
      double minSICNb = minSICN;
      quadQualityStats(elements, minSICN, avgSICN);
      Msg::Debug("- Untangling of (%li quads, %li free vertices) with Mesquite: SICN %f -> %f", elements.size(), freeVertices.size(), minSICNb, minSICN);
    }

    if (minSICN > 0.) {
      if (opt.smoother == MesquiteShapeImprovement) {
        Mesquite::ShapeImprovementWrapper smoother;
        smoother.quality_assessor().disable_printing_results();
        if (Msg::GetVerbosity() < 999) smoother.quality_assessor().disable_printing_results();
        smoother.run_instructions(&mesh_and_domain, err); 
      } else if (opt.smoother == MesquitePaverMinEdgeLengthWrapper) {
        double relative_vtx_movement = 1.e-2;
        Mesquite::PaverMinEdgeLengthWrapper smoother(relative_vtx_movement);
        if (Msg::GetVerbosity() < 999) {
          smoother.quality_assessor().disable_printing_results();
        }
        smoother.run_instructions(&mesh_and_domain, err); 
      }

      for (size_t i = 0; i < freeVertices.size(); ++i) {
        M.origin[i]->x() = M.coords[3*i+0];
        M.origin[i]->y() = M.coords[3*i+1];
        M.origin[i]->z() = M.coords[3*i+2];
      }
      double minSICNb = minSICN;
      quadQualityStats(elements, minSICN, avgSICN);
      Msg::Debug("- Optimization of (%li quads, %li free vertices) with Mesquite: SICN %f -> %f", elements.size(), freeVertices.size(), minSICNb, minSICN);
    }
  } catch (...) {
    Msg::Error("- failed to optimize with Mesquite (%li quads)", elements.size());
  }

  qualityMin = minSICN;
  qualityAvg = avgSICN;

  return 0;
}

bool growCavity(
    const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
    vector<MElement*>& elements,
    int n = 1)  {

  vector<MElement*> bdr = elements;
  vector<MElement*> newElements;
  for (size_t iter = 0; iter < (size_t) n; ++iter) {
    newElements.clear();
    for (MElement* e: bdr) {
      for (size_t j=0;j<e->getNumVertices();j++){
        MVertex* v = e->getVertex(j);
        auto it = adj.find(v);
        if (it == adj.end()) {
          Msg::Error("growCavity: vertex %li not found in adj", v->getNum());
          continue;
        }
        for (MElement* e2: it->second) {
          newElements.push_back(e2);
        }
      }
    }
    sort_unique(newElements);
    bdr = newElements;
    append(elements,newElements);
    sort_unique(elements);
  }

  return true;
}

bool simpleWinslowSmoothing(
    GFace* gf,
    SurfaceProjector* sp,
    std::vector<MElement*>& elements,
    int iter,
    double qMin) {

  vector<MVertex*> bnd;
  bool okb = buildBoundary(elements, bnd);
  if (!okb) {
    Msg::Error("optimizeQuadMeshWithSubPatches: failed to build boundary (%li quads)", elements.size());
    return false;
  }

  std::vector<MVertex*> freeVertices;
  bool oki = verticesStrictlyInside(elements, bnd, freeVertices);
  if (!oki) {
    Msg::Error("optimizeQuadMeshWithSubPatches: failed to get vertices inside");
    return -1;
  }

  /* Save in case of deterioration */
  std::vector<SPoint3> before(freeVertices.size());
  for (size_t v = 0; v < freeVertices.size(); ++v) {
    before[v] = freeVertices[v]->point();
  }

  std::vector<MQuadrangle*> quads(elements.size());
  for (size_t i = 0; i < elements.size(); ++i) {
    quads[i] = dynamic_cast<MQuadrangle*>(elements[i]);
  }

  double minSICNb = DBL_MAX;
  double avgSICNb = 0.;
  quadQualityStats(elements, minSICNb, avgSICNb);

  meshWinslow2d(gf, quads, freeVertices, iter, NULL, false, sp);

  double minSICNa = DBL_MAX;
  double avgSICNa = 0.;
  quadQualityStats(elements, minSICNa, avgSICNa);

  bool keep = true;
  if (minSICNa < minSICNb && avgSICNa < avgSICNb) keep = false;
  if (minSICNa < 0.3 && minSICNa < minSICNb) keep = false;
  if (minSICNa < 0.75 * minSICNb) keep = false;

  if (keep) {
    Msg::Debug("- cavity with %li quads: small smoothing, SICN min: %f -> %f, avg: %f -> %f",
        elements.size(),minSICNb,minSICNa,avgSICNb,avgSICNa);
  } else {
    Msg::Debug("- cavity with %li quads: worst quality after smoothing, roll back (SICN min: %f -> %f, avg: %f -> %f)",
        elements.size(),minSICNb,minSICNa,avgSICNb,avgSICNa);
    for (size_t v = 0; v < freeVertices.size(); ++v) {
      freeVertices[v]->setXYZ(before[v].x(),before[v].y(),before[v].z());
    }
  }

  return true;
}

int optimizeQuadMeshWithSubPatches(
    GFace* gf,
    SurfaceProjector* sp,
    double& qualityMin,
    double& qualityAvg) {
  if (gf->quadrangles.size() == 0) return 0;

  double minSICNb = DBL_MAX;
  double avgSICNb = 0.;
  quadQualityStats(gf->quadrangles, minSICNb, avgSICNb);

  vector<MElement*> elements(gf->quadrangles.size());
  for (size_t i = 0; i < gf->quadrangles.size(); ++i) {
    elements[i] = dynamic_cast<MQuadrangle*>(gf->quadrangles[i]);
  }
  vector<MVertex*> freeVertices = gf->mesh_vertices;

  /* Vertex to elements map */
  robin_hood::unordered_map<MVertex *, std::vector<MElement *> > adj;
  for (MElement* e: elements) {
    for (size_t i=0;i<e->getNumVertices();i++){
      MVertex* v = e->getVertex(i);
      adj[v].push_back(e);
    }
  }

  double qMin = DBL_MAX;
  double qAvg = 0.;
  robin_hood::unordered_flat_map<MElement*,double> quality;
  for (MElement* e: elements) {
    double q = e->minSICNShapeMeasure();
    quality[e] = q;
    qMin = std::min(qMin,q);
    qAvg += q;
  }
  qAvg /= double(elements.size());

  /* Local optimization loop */
  bool running = true;
  size_t iter = 0;
  size_t iterMax = 5;
  vector<std::pair<double,MElement*> > quality_elt;
  while (running && iter < iterMax) {
    running = false;
    iter += 1;
    quality_elt.clear();
    for (auto& kv: quality) if (kv.second < qAvg) {
      quality_elt.push_back({kv.second,kv.first});
    }
    std::sort(quality_elt.begin(),quality_elt.end());

    double q025 = quality_elt[quality_elt.size()/4].first;

    vector<MElement*> quads;
    for (auto& kv: quality_elt) {
      MElement* e = kv.second;
      if (quality[e] > q025) continue;
      quads = {e};
      growCavity(adj, quads, 3);

      double qMin = kv.first;
      bool okw = simpleWinslowSmoothing(gf, sp, quads, 10, qMin);
      if (!okw) {
        continue;
      }
      for (MElement* q: elements) {
        quality[q] = q->minSICNShapeMeasure();
      }
      running = true;
    }

  }

  double minSICNa = DBL_MAX;
  double avgSICNa = 0.;
  quadQualityStats(gf->quadrangles, minSICNa, avgSICNa);

  Msg::Info("- Face %i: local smoothing, SICN min: %f -> %f, avg: %f -> %f",
      gf->tag(),minSICNb,minSICNa,avgSICNb,avgSICNa);

  return 0;
}

#else

int optimizeQuadCavity(
    const MesquiteOptions& opt,
    SurfaceProjector* sp,
    const std::vector<MElement*>& elements,
    const std::vector<MVertex*>& freeVertices,
    std::vector<SPoint3>& freePositions,
    double& qualityMin,
    double& qualityAvg) {
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
  return -1;
}

int optimizeQuadGeometry(GFace* gf) {
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
  return -1;
}

int optimizeQuadMeshWithSubPatches(
    GFace* gf,
    SurfaceProjector* sp,
    double& qualityMin,
    double& qualityAvg
    ){
  Msg::Error("Mesquite module required to optimize quad geometry. Recompile with ENABLE_MESQUITE=YES");
  return -1;
}

#endif
