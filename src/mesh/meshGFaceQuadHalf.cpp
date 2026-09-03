// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "Context.h"
#include "meshGFaceQuadHalf.h"
#include "meshGFaceOptimize.h"

void quadMeshRemoveHalfOfOneDMesh::_subdivide()
{
  std::vector<MQuadrangle *> qnew;
  std::map<MEdge, MVertex *, MEdgeLessThan> eds;
  for(std::size_t i = 0; i < _gf->triangles.size(); i++) {
    MVertex *v[3];
    SPoint2 m[3];
    for(int j = 0; j < 3; j++) {
      MEdge E = _gf->triangles[i]->getEdge(j);
      SPoint2 p1, p2;
      reparamMeshEdgeOnFace(E.getVertex(0), E.getVertex(1), _gf, p1, p2);
      auto it = _middle.find(E);
      auto it2 = eds.find(E);
      m[j] = p1;
      if(it == _middle.end() && it2 == eds.end()) {
        GPoint gp = _gf->point((p1 + p2) * 0.5);
        double XX = 0.5 * (E.getVertex(0)->x() + E.getVertex(1)->x());
        double YY = 0.5 * (E.getVertex(0)->y() + E.getVertex(1)->y());
        double ZZ = 0.5 * (E.getVertex(0)->z() + E.getVertex(1)->z());
        v[j] = new MFaceVertex(XX, YY, ZZ, _gf, gp.u(), gp.v());
        _gf->mesh_vertices.push_back(v[j]);
        eds[E] = v[j];
      }
      else if(it == _middle.end()) {
        v[j] = it2->second;
      }
      else {
        v[j] = it->second;
        v[j]->onWhat()->mesh_vertices.push_back(v[j]);
        if(!CTX::instance()->mesh.secondOrderLinear) {
          // re-push middle vertex on the curve (this can of course lead to an
          // invalid mesh)
          double u = 0.;
          if(v[j]->getParameter(0, u) && v[j]->onWhat()->dim() == 1) {
            GEdge *ge = static_cast<GEdge *>(v[j]->onWhat());
            GPoint p = ge->point(u);
            v[j]->x() = p.x();
            v[j]->y() = p.y();
            v[j]->z() = p.z();
          }
        }
      }
    }
    GPoint gp = _gf->point((m[0] + m[1] + m[2]) * (1. / 3.));
    double XX = (v[0]->x() + v[1]->x() + v[2]->x()) * (1. / 3.);
    double YY = (v[0]->y() + v[1]->y() + v[2]->y()) * (1. / 3.);
    double ZZ = (v[0]->z() + v[1]->z() + v[2]->z()) * (1. / 3.);
    MFaceVertex *vmid = new MFaceVertex(XX, YY, ZZ, _gf, gp.u(), gp.v());
    _gf->mesh_vertices.push_back(vmid);
    qnew.push_back(
      new MQuadrangle(_gf->triangles[i]->getVertex(0), v[0], vmid, v[2]));
    qnew.push_back(
      new MQuadrangle(_gf->triangles[i]->getVertex(1), v[1], vmid, v[0]));
    qnew.push_back(
      new MQuadrangle(_gf->triangles[i]->getVertex(2), v[2], vmid, v[1]));
    delete _gf->triangles[i];
  }
  _gf->triangles.clear();
  for(std::size_t i = 0; i < _gf->quadrangles.size(); i++) {
    MVertex *v[4];
    SPoint2 m[4];
    for(int j = 0; j < 4; j++) {
      MEdge E = _gf->quadrangles[i]->getEdge(j);
      SPoint2 p1, p2;
      reparamMeshEdgeOnFace(E.getVertex(0), E.getVertex(1), _gf, p1, p2);
      auto it = _middle.find(E);
      auto it2 = eds.find(E);
      m[j] = p1;
      if(it == _middle.end() && it2 == eds.end()) {
        GPoint gp = _gf->point((p1 + p2) * 0.5);
        double XX = 0.5 * (E.getVertex(0)->x() + E.getVertex(1)->x());
        double YY = 0.5 * (E.getVertex(0)->y() + E.getVertex(1)->y());
        double ZZ = 0.5 * (E.getVertex(0)->z() + E.getVertex(1)->z());
        v[j] = new MFaceVertex(XX, YY, ZZ, _gf, gp.u(), gp.v());
        _gf->mesh_vertices.push_back(v[j]);
        eds[E] = v[j];
      }
      else if(it == _middle.end()) {
        v[j] = it2->second;
      }
      else {
        v[j] = it->second;
        v[j]->onWhat()->mesh_vertices.push_back(v[j]);
        if(!CTX::instance()->mesh.secondOrderLinear) {
          // re-push middle vertex on the curve (this can of course lead to an
          // invalid mesh)
          double u = 0.;
          if(v[j]->getParameter(0, u) && v[j]->onWhat()->dim() == 1) {
            GEdge *ge = static_cast<GEdge *>(v[j]->onWhat());
            GPoint p = ge->point(u);
            v[j]->x() = p.x();
            v[j]->y() = p.y();
            v[j]->z() = p.z();
          }
        }
      }
    }
    GPoint gp = _gf->point((m[0] + m[1] + m[2] + m[3]) * 0.25);
    // FIXME: not exactly correct, but that's the place where we want the
    // point to reside
    double XX = 0.25 * (v[0]->x() + v[1]->x() + v[2]->x() + v[3]->x());
    double YY = 0.25 * (v[0]->y() + v[1]->y() + v[2]->y() + v[3]->y());
    double ZZ = 0.25 * (v[0]->z() + v[1]->z() + v[2]->z() + v[3]->z());
    MVertex *vmid = new MFaceVertex(XX, YY, ZZ, _gf, gp.u(), gp.v());
    _gf->mesh_vertices.push_back(vmid);
    qnew.push_back(
      new MQuadrangle(_gf->quadrangles[i]->getVertex(0), v[0], vmid, v[3]));
    qnew.push_back(
      new MQuadrangle(_gf->quadrangles[i]->getVertex(1), v[1], vmid, v[0]));
    qnew.push_back(
      new MQuadrangle(_gf->quadrangles[i]->getVertex(2), v[2], vmid, v[1]));
    qnew.push_back(
      new MQuadrangle(_gf->quadrangles[i]->getVertex(3), v[3], vmid, v[2]));
    delete _gf->quadrangles[i];
  }
  _gf->quadrangles = qnew;
}

void quadMeshRemoveHalfOfOneDMesh::_restore()
{
  std::vector<GEdge *> edges = _gf->edges();
  std::vector<GEdge *> const &emb = _gf->embeddedEdges();
  edges.insert(edges.begin(), emb.begin(), emb.end());
  auto ite = edges.begin();
  while(ite != edges.end()) {
    for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
      delete(*ite)->lines[i];
    }
    (*ite)->lines = _backup[*ite];
    (*ite)->mesh_vertices = _backupv[*ite];
    ++ite;
  }
}

// remove one point every two and remember middle points
quadMeshRemoveHalfOfOneDMesh::quadMeshRemoveHalfOfOneDMesh(GFace *gf,
                                                           bool periodic)
  : _gf(gf)
{
  // only do it if a full recombination has to (and can) be done
  if(!CTX::instance()->mesh.recombineAll && !gf->meshAttributes.recombine)
    return;
  if(CTX::instance()->mesh.algoRecombine < 2 ||
     CTX::instance()->mesh.algoRecombine == 4)
    return;

  if(gf->compound.size()) return;
  if(periodic) {
    Msg::Error("Full-quad recombination not ready yet for periodic surfaces");
    return;
  }
  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> const &emb = gf->embeddedEdges();
  edges.insert(edges.begin(), emb.begin(), emb.end());
  auto ite = edges.begin();
  while(ite != edges.end()) {
    if((*ite)->meshAttributes.method == MESH_TRANSFINITE) {
      Msg::Warning("Full-quad recombination only compatible with "
                   "transfinite meshes if those are performed first");
    }
    if(!(*ite)->isMeshDegenerated()) {
      std::vector<MLine *> temp;
      _backupv[*ite] = (*ite)->mesh_vertices;
      (*ite)->mesh_vertices.clear();
      for(std::size_t i = 0; i < (*ite)->lines.size(); i += 2) {
        if(i + 1 >= (*ite)->lines.size()) {
          Msg::Error("1D mesh of MEdge %d cannot be divided by 2 --  %lu lines",
                     (*ite)->tag(), (*ite)->lines.size());
          break;
        }
        MVertex *v1 = (*ite)->lines[i]->getVertex(0);
        MVertex *v2 = (*ite)->lines[i]->getVertex(1);
        MVertex *v3 = (*ite)->lines[i + 1]->getVertex(1);
        v2->x() = 0.5 * (v1->x() + v3->x());
        v2->y() = 0.5 * (v1->y() + v3->y());
        v2->z() = 0.5 * (v1->z() + v3->z());
        temp.push_back(new MLine(v1, v3));
        if(v1->onWhat() == *ite &&
           std::find((*ite)->mesh_vertices.begin(), (*ite)->mesh_vertices.end(),
                     v1) == (*ite)->mesh_vertices.end()) {
          (*ite)->mesh_vertices.push_back(v1);
        }
        _middle[MEdge(v1, v3)] = v2;
      }
      _backup[*ite] = (*ite)->lines;
      (*ite)->lines = temp;
    }
    ++ite;
  }
  CTX::instance()->mesh.lcFactor *= 2.0;
}

void quadMeshRemoveHalfOfOneDMesh::finish()
{
  if(_backup.empty()) return;
  // recombine the elements on the half mesh
  CTX::instance()->mesh.lcFactor /= 2.0;
  bool blossom = (CTX::instance()->mesh.algoRecombine == 3);
  int topo = CTX::instance()->mesh.recombineOptimizeTopology;
  int repos = CTX::instance()->mesh.recombineNodeRepositioning;
  recombineIntoQuads(_gf, blossom, topo, repos, 0.1);
  _subdivide();
  _restore();
  recombineIntoQuads(_gf, blossom, topo, repos, 1.e-3);
  computeElementShapes(_gf, _gf->meshStatistics.worst_element_shape,
                       _gf->meshStatistics.average_element_shape,
                       _gf->meshStatistics.best_element_shape,
                       _gf->meshStatistics.nbTriangle,
                       _gf->meshStatistics.nbGoodQuality);
}
