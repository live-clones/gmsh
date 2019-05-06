// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <limits>
#include <sstream>
#include <stdlib.h>
#include <map>
#include "GmshMessage.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "GPoint.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "MVertex.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGFaceBDS.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceBamg.h"
#include "meshGFaceOptimize.h"
#include "DivideAndConquer.h"
#include "BackgroundMesh.h"
#include "robustPredicates.h"
#include "Numeric.h"
#include "BDS.h"
#include "qualityMeasures.h"
#include "OS.h"
#include "MElementOctree.h"
#include "HighOrder.h"
#include "Context.h"
#include "boundaryLayersData.h"
#include "filterElements.h"

// define this to use the old initial delaunay
#define OLD_CODE_DELAUNAY 1

bool pointInsideParametricDomain(std::vector<SPoint2> &bnd, SPoint2 &p,
                                 SPoint2 &out, int &N)
{
  int count = 0;
  for(size_t i = 0; i < bnd.size(); i += 2) {
    SPoint2 p1 = bnd[i];
    SPoint2 p2 = bnd[i + 1];
    double a = robustPredicates::orient2d(p1, p2, p);
    double b = robustPredicates::orient2d(p1, p2, out);
    if(a * b < 0) {
      a = robustPredicates::orient2d(p, out, p1);
      b = robustPredicates::orient2d(p, out, p2);
      if(a * b < 0) count++;
    }
  }
  N = count;
  if(count % 2 == 0) return false;
  return true;
}

static void trueBoundary(GFace *gf, std::vector<SPoint2> &bnd, int debug)
{
  FILE *view_t = 0;
  if(debug) {
    char name[245];
    sprintf(name, "trueBoundary%d.pos", gf->tag());
    view_t = Fopen(name, "w");
    if(view_t) fprintf(view_t, "View \"True Boundary\"{\n");
  }
  std::vector<GEdge *> edg = gf->edges();
  std::set<GEdge *> edges(edg.begin(), edg.end());

  for(std::set<GEdge *>::iterator it = edges.begin(); it != edges.end(); ++it) {
    GEdge *ge = *it;
    Range<double> r = ge->parBoundsOnFace(gf);
    SPoint2 p[300];
    int NITER = ge->isSeam(gf) ? 2 : 1;
    for(int i = 0; i < NITER; i++) {
      int count = NITER == 2 ? 300 : 300;
      for(int k = 0; k < count; k++) {
        double t = (double)k / (count - 1);
        double xi = r.low() + (r.high() - r.low()) * t;
        p[k] = ge->reparamOnFace(gf, xi, i);
        if(k > 0) {
          if(view_t) {
            fprintf(view_t, "SL(%g,%g,%g,%g,%g,%g){1,1};\n", p[k - 1].x(),
                    p[k - 1].y(), 0.0, p[k].x(), p[k].y(), 0.0);
          }
          bnd.push_back(p[k - 1]);
          bnd.push_back(p[k]);
        }
      }
    }
  }
  if(view_t) {
    fprintf(view_t, "};\n");
    fclose(view_t);
  }
}

static void computeElementShapes(GFace *gf, double &worst, double &avg,
                                 double &best, int &nT, int &greaterThan)
{
  worst = 1.e22;
  avg = 0.0;
  best = 0.0;
  nT = 0;
  greaterThan = 0;
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    double q = qmTriangle::gamma(gf->triangles[i]);
    if(q > .9) greaterThan++;
    avg += q;
    worst = std::min(worst, q);
    best = std::max(best, q);
    nT++;
  }
  avg /= nT;
}

class quadMeshRemoveHalfOfOneDMesh {
private:
  GFace *_gf;
  std::map<GEdge *, std::vector<MLine *> > _backup;
  std::map<MEdge, MVertex *, Less_Edge> _middle;
  void _subdivide()
  {
    std::vector<MQuadrangle *> qnew;
    std::map<MEdge, MVertex *, Less_Edge> eds;
    for(std::size_t i = 0; i < _gf->triangles.size(); i++) {
      MVertex *v[3];
      SPoint2 m[3];
      for(int j = 0; j < 3; j++) {
        MEdge E = _gf->triangles[i]->getEdge(j);
        SPoint2 p1, p2;
        reparamMeshEdgeOnFace(E.getVertex(0), E.getVertex(1), _gf, p1, p2);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it = _middle.find(E);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it2 = eds.find(E);
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
        std::map<MEdge, MVertex *, Less_Edge>::iterator it = _middle.find(E);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it2 = eds.find(E);
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
  void _restore()
  {
    std::vector<GEdge *> const &edges = _gf->edges();
    std::vector<GEdge *>::const_iterator ite = edges.begin();
    while(ite != edges.end()) {
      for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
        delete(*ite)->lines[i];
      }
      (*ite)->lines = _backup[*ite];
      ++ite;
    }
  }

public:
  // remove one point every two and remember middle points
  quadMeshRemoveHalfOfOneDMesh(GFace *gf, bool periodic) : _gf(gf)
  {
    // only do it if a full recombination has to (and can) be done
    if(!CTX::instance()->mesh.recombineAll && !gf->meshAttributes.recombine)
      return;
    if(CTX::instance()->mesh.algoRecombine < 2) return;
    if(periodic) {
      Msg::Error("Full-quad recombination not ready yet for periodic surfaces");
      return;
    }
    std::vector<GEdge *> const &edges = gf->edges();
    std::vector<GEdge *>::const_iterator ite = edges.begin();
    while(ite != edges.end()) {
      if(!(*ite)->isMeshDegenerated()) {
        std::vector<MLine *> temp;
        (*ite)->mesh_vertices.clear();
        for(std::size_t i = 0; i < (*ite)->lines.size(); i += 2) {
          if(i + 1 >= (*ite)->lines.size()) {
            Msg::Error("1D mesh cannot be divided by 2");
            break;
          }
          MVertex *v1 = (*ite)->lines[i]->getVertex(0);
          MVertex *v2 = (*ite)->lines[i]->getVertex(1);
          MVertex *v3 = (*ite)->lines[i + 1]->getVertex(1);
          v2->x() = 0.5 * (v1->x() + v3->x());
          v2->y() = 0.5 * (v1->y() + v3->y());
          v2->z() = 0.5 * (v1->z() + v3->z());
          temp.push_back(new MLine(v1, v3));
          if(v1->onWhat() == *ite) (*ite)->mesh_vertices.push_back(v1);
          _middle[MEdge(v1, v3)] = v2;
        }
        _backup[*ite] = (*ite)->lines;
        (*ite)->lines = temp;
      }
      ++ite;
    }
    CTX::instance()->mesh.lcFactor *= 2.0;
  }
  void finish()
  {
    if(_backup.empty()) return;
    // recombine the elements on the half mesh
    CTX::instance()->mesh.lcFactor /= 2.0;
    bool blossom = (CTX::instance()->mesh.algoRecombine == 3);
    int topo = CTX::instance()->mesh.recombineOptimizeTopology;
    recombineIntoQuads(_gf, blossom, topo, true, 0.1);
    _subdivide();
    _restore();
    recombineIntoQuads(_gf, blossom, topo, true, 1.e-3);
    computeElementShapes(_gf, _gf->meshStatistics.worst_element_shape,
                         _gf->meshStatistics.average_element_shape,
                         _gf->meshStatistics.best_element_shape,
                         _gf->meshStatistics.nbTriangle,
                         _gf->meshStatistics.nbGoodQuality);
  }
};

static void copyMesh(GFace *source, GFace *target)
{
  std::map<MVertex *, MVertex *> vs2vt;

  // add principal vertex pairs

  std::vector<GVertex *> const &s_vtcs = source->vertices();
  std::vector<GVertex *> const &t_vtcs = target->vertices();

  if(s_vtcs.size() != t_vtcs.size()) {
    Msg::Info("Periodicity imposed on topologically incompatible surfaces"
              "(%d vs %d bounding vertices)",
              s_vtcs.size(), t_vtcs.size());
  }

  std::set<GVertex *> checkVtcs(s_vtcs.begin(), s_vtcs.end());

  for(std::vector<GVertex *>::const_iterator tvIter = t_vtcs.begin();
      tvIter != t_vtcs.end(); ++tvIter) {
    GVertex *gvt = *tvIter;
    std::map<GVertex *, GVertex *>::iterator gvsIter =
      target->vertexCounterparts.find(gvt);

    if(gvsIter == target->vertexCounterparts.end()) {
      Msg::Error("Periodic meshing of surface %d with surface %d: "
                 "point %d has no periodic counterpart",
                 target->tag(), source->tag(), gvt->tag());
    }
    else {
      GVertex *gvs = gvsIter->second;
      if(checkVtcs.find(gvs) == checkVtcs.end()) {
        if(gvs)
          Msg::Error(
            "Periodic meshing of surface %d with surface %d: "
            "point %d has periodic counterpart %d outside of source surface",
            target->tag(), source->tag(), gvt->tag(), gvs->tag());

        else
          Msg::Error("Periodic meshing of surface %d with surface %d: "
                     "point %d has no periodic counterpart",
                     target->tag(), source->tag(), gvt->tag());
      }
      if(gvs) {
        MVertex *vs = gvs->mesh_vertices[0];
        MVertex *vt = gvt->mesh_vertices[0];
        vs2vt[vs] = vt;
        target->correspondingVertices[vt] = vs;
      }
    }
  }

  // add corresponding edge nodes assuming edges were correctly meshed already

  std::vector<GEdge *> s_edges = source->edges();
  std::vector<GEdge *> t_edges = target->edges();

  std::set<GEdge *> checkEdges;
  checkEdges.insert(s_edges.begin(), s_edges.end());

  for(std::vector<GEdge *>::iterator te_iter = t_edges.begin();
      te_iter != t_edges.end(); ++te_iter) {
    GEdge *get = *te_iter;

    std::map<GEdge *, std::pair<GEdge *, int> >::iterator gesIter =
      target->edgeCounterparts.find(get);
    if(gesIter == target->edgeCounterparts.end()) {
      Msg::Error("Periodic meshing of surface %d with surface %d: "
                 "curve %d has no periodic counterpart",
                 target->tag(), source->tag(), get->tag());
    }
    else {
      GEdge *ges = gesIter->second.first;
      if(checkEdges.find(ges) == checkEdges.end()) {
        Msg::Error(
          "Periodic meshing of surface %d with surface %d: "
          "curve %d has periodic counterpart %d outside of get surface",
          target->tag(), source->tag(), get->tag(), ges->tag());
      }
      if(get->mesh_vertices.size() != ges->mesh_vertices.size()) {
        Msg::Error("Periodic meshing of surface %d with surface %d: "
                   "curve %d has %d vertices, whereas correspondant %d has %d",
                   target->tag(), source->tag(), get->tag(),
                   get->mesh_vertices.size(), ges->tag(),
                   ges->mesh_vertices.size());
      }
      int orientation = gesIter->second.second;
      int is = orientation == 1 ? 0 : get->mesh_vertices.size() - 1;
      for(unsigned it = 0; it < get->mesh_vertices.size();
          it++, is += orientation) {
        MVertex *vs = ges->mesh_vertices[is];
        MVertex *vt = get->mesh_vertices[it];
        vs2vt[vs] = vt;
        target->correspondingVertices[vt] = vs;
      }
    }
  }

  // now transform
  std::vector<double> &tfo = target->affineTransform;

  for(std::size_t i = 0; i < source->mesh_vertices.size(); i++) {
    MVertex *vs = source->mesh_vertices[i];
    SPoint2 XXX;

    double ps[4] = {vs->x(), vs->y(), vs->z(), 1.};
    double res[4] = {0., 0., 0., 0.};
    int idx = 0;
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) res[i] += tfo[idx++] * ps[j];

    SPoint3 tp(res[0], res[1], res[2]);
    XXX = target->parFromPoint(tp);

    GPoint gp = target->point(XXX);
    MVertex *vt =
      new MFaceVertex(gp.x(), gp.y(), gp.z(), target, gp.u(), gp.v());
    target->mesh_vertices.push_back(vt);
    target->correspondingVertices[vt] = vs;
    vs2vt[vs] = vt;
  }

  for(unsigned i = 0; i < source->triangles.size(); i++) {
    MVertex *vt[3];
    for(int j = 0; j < 3; j++) {
      MVertex *vs = source->triangles[i]->getVertex(j);
      vt[j] = vs2vt[vs];
    }
    if(!vt[0] || !vt[1] || !vt[2]) {
      Msg::Error("Problem in mesh copying procedure %p %p %p %d %d %d", vt[0],
                 vt[1], vt[2],
                 source->triangles[i]->getVertex(0)->onWhat()->dim(),
                 source->triangles[i]->getVertex(1)->onWhat()->dim(),
                 source->triangles[i]->getVertex(2)->onWhat()->dim());
      return;
    }
    target->triangles.push_back(new MTriangle(vt[0], vt[1], vt[2]));
  }

  for(unsigned i = 0; i < source->quadrangles.size(); i++) {
    MVertex *v1 = vs2vt[source->quadrangles[i]->getVertex(0)];
    MVertex *v2 = vs2vt[source->quadrangles[i]->getVertex(1)];
    MVertex *v3 = vs2vt[source->quadrangles[i]->getVertex(2)];
    MVertex *v4 = vs2vt[source->quadrangles[i]->getVertex(3)];
    if(!v1 || !v2 || !v3 || !v4) {
      Msg::Error("Problem in mesh copying procedure %p %p %p %p %d %d %d %d",
                 v1, v2, v3, v4,
                 source->quadrangles[i]->getVertex(0)->onWhat()->dim(),
                 source->quadrangles[i]->getVertex(1)->onWhat()->dim(),
                 source->quadrangles[i]->getVertex(2)->onWhat()->dim(),
                 source->quadrangles[i]->getVertex(3)->onWhat()->dim());
    }
    target->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
  }
}

void fourthPoint(double *p1, double *p2, double *p3, double *p4)
{
  double c[3];
  circumCenterXYZ(p1, p2, p3, c);
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3];
  prodve(vx, vy, vz);
  norme(vz);
  double R =
    sqrt((p1[0] - c[0]) * (p1[0] - c[0]) + (p1[1] - c[1]) * (p1[1] - c[1]) +
         (p1[2] - c[2]) * (p1[2] - c[2]));
  p4[0] = c[0] + R * vz[0];
  p4[1] = c[1] + R * vz[1];
  p4[2] = c[2] + R * vz[2];
}

static void remeshUnrecoveredEdges(
  std::multimap<MVertex *, BDS_Point *> &recoverMultiMapInv,
  std::set<EdgeToRecover> &edgesNotRecovered, bool all)
{
  deMeshGFace dem;

  std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
  for(; itr != edgesNotRecovered.end(); ++itr) {
    std::vector<GFace *> l_faces = itr->ge->faces();
    // un-mesh model faces adjacent to the model edge
    for(std::vector<GFace *>::iterator it = l_faces.begin();
        it != l_faces.end(); ++it) {
      if((*it)->triangles.size() || (*it)->quadrangles.size()) {
        (*it)->meshStatistics.status = GFace::PENDING;
        dem(*it);
      }
    }

    // add a new point in the middle of the intersecting segment
    int p1 = itr->p1;
    int p2 = itr->p2;
    int N = itr->ge->lines.size();
    GVertex *g1 = itr->ge->getBeginVertex();
    GVertex *g2 = itr->ge->getEndVertex();
    Range<double> bb = itr->ge->parBounds(0);

    std::vector<MLine *> newLines;

    for(int i = 0; i < N; i++) {
      MVertex *v1 = itr->ge->lines[i]->getVertex(0);
      MVertex *v2 = itr->ge->lines[i]->getVertex(1);

      std::multimap<MVertex *, BDS_Point *>::iterator itp1 =
        recoverMultiMapInv.lower_bound(v1);
      std::multimap<MVertex *, BDS_Point *>::iterator itp2 =
        recoverMultiMapInv.lower_bound(v2);

      if(itp1 != recoverMultiMapInv.end() && itp2 != recoverMultiMapInv.end()) {
        BDS_Point *pp1 = itp1->second;
        BDS_Point *pp2 = itp2->second;
        BDS_Point *pp1b = itp1->second;
        BDS_Point *pp2b = itp2->second;
        if(recoverMultiMapInv.count(v1) == 2) {
          itp1++;
          pp1b = itp1->second;
        }
        if(recoverMultiMapInv.count(v2) == 2) {
          itp2++;
          pp2b = itp2->second;
        }

        if((pp1->iD == p1 && pp2->iD == p2) ||
           (pp1->iD == p2 && pp2->iD == p1) ||
           (pp1b->iD == p1 && pp2b->iD == p2) ||
           (pp1b->iD == p2 && pp2b->iD == p1) || all) {
          double t1;
          double lc1 = -1;
          if(v1->onWhat() == g1)
            t1 = bb.low();
          else if(v1->onWhat() == g2)
            t1 = bb.high();
          else {
            MEdgeVertex *ev1 = (MEdgeVertex *)v1;
            lc1 = ev1->getLc();
            v1->getParameter(0, t1);
          }
          double t2;
          double lc2 = -1;
          if(v2->onWhat() == g1)
            t2 = bb.low();
          else if(v2->onWhat() == g2)
            t2 = bb.high();
          else {
            MEdgeVertex *ev2 = (MEdgeVertex *)v2;
            lc2 = ev2->getLc();
            v2->getParameter(0, t2);
          }

          // periodic
          if(v1->onWhat() == g1 && v1->onWhat() == g2)
            t1 =
              fabs(t2 - bb.low()) < fabs(t2 - bb.high()) ? bb.low() : bb.high();
          if(v2->onWhat() == g1 && v2->onWhat() == g2)
            t2 =
              fabs(t1 - bb.low()) < fabs(t1 - bb.high()) ? bb.low() : bb.high();

          if(lc1 == -1)
            lc1 = BGM_MeshSize(v1->onWhat(), 0, 0, v1->x(), v1->y(), v1->z());
          if(lc2 == -1)
            lc2 = BGM_MeshSize(v2->onWhat(), 0, 0, v2->x(), v2->y(), v2->z());
          // should be better, i.e. equidistant
          double t = 0.5 * (t2 + t1);
          double lc = 0.5 * (lc1 + lc2);
          GPoint V = itr->ge->point(t);
          MEdgeVertex *newv =
            new MEdgeVertex(V.x(), V.y(), V.z(), itr->ge, t, 0, lc);
          newLines.push_back(new MLine(v1, newv));
          newLines.push_back(new MLine(newv, v2));
          delete itr->ge->lines[i];
        }
        else {
          newLines.push_back(itr->ge->lines[i]);
        }
      }
      else {
        newLines.push_back(itr->ge->lines[i]);
      }
    }

    itr->ge->lines = newLines;
    itr->ge->mesh_vertices.clear();
    N = itr->ge->lines.size();
    for(int i = 1; i < N; i++) {
      itr->ge->mesh_vertices.push_back(itr->ge->lines[i]->getVertex(0));
    }
  }
}

static void
remeshUnrecoveredEdges(std::map<MVertex *, BDS_Point *> &recoverMapInv,
                       std::set<EdgeToRecover> &edgesNotRecovered)
{
  deMeshGFace dem;

  std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
  for(; itr != edgesNotRecovered.end(); ++itr) {
    std::vector<GFace *> l_faces = itr->ge->faces();
    // un-mesh model faces adjacent to the model edge
    for(std::vector<GFace *>::iterator it = l_faces.begin();
        it != l_faces.end(); ++it) {
      if((*it)->triangles.size() || (*it)->quadrangles.size()) {
        (*it)->meshStatistics.status = GFace::PENDING;
        dem(*it);
      }
    }

    // add a new point in the middle of the intersecting segment
    int p1 = itr->p1;
    int p2 = itr->p2;
    int N = itr->ge->lines.size();
    GVertex *g1 = itr->ge->getBeginVertex();
    GVertex *g2 = itr->ge->getEndVertex();
    Range<double> bb = itr->ge->parBounds(0);

    std::vector<MLine *> newLines;

    for(int i = 0; i < N; i++) {
      MVertex *v1 = itr->ge->lines[i]->getVertex(0);
      MVertex *v2 = itr->ge->lines[i]->getVertex(1);
      std::map<MVertex *, BDS_Point *>::iterator itp1 = recoverMapInv.find(v1);
      std::map<MVertex *, BDS_Point *>::iterator itp2 = recoverMapInv.find(v2);
      if(itp1 != recoverMapInv.end() && itp2 != recoverMapInv.end()) {
        BDS_Point *pp1 = itp1->second;
        BDS_Point *pp2 = itp2->second;
        if((pp1->iD == p1 && pp2->iD == p2) ||
           (pp1->iD == p2 && pp2->iD == p1)) {
          double t1;
          double lc1 = -1;
          if(v1->onWhat() == g1)
            t1 = bb.low();
          else if(v1->onWhat() == g2)
            t1 = bb.high();
          else {
            MEdgeVertex *ev1 = (MEdgeVertex *)v1;
            lc1 = ev1->getLc();
            v1->getParameter(0, t1);
          }
          double t2;
          double lc2 = -1;
          if(v2->onWhat() == g1)
            t2 = bb.low();
          else if(v2->onWhat() == g2)
            t2 = bb.high();
          else {
            MEdgeVertex *ev2 = (MEdgeVertex *)v2;
            lc2 = ev2->getLc();
            v2->getParameter(0, t2);
          }

          // periodic
          if(v1->onWhat() == g1 && v1->onWhat() == g2)
            t1 =
              fabs(t2 - bb.low()) < fabs(t2 - bb.high()) ? bb.low() : bb.high();
          if(v2->onWhat() == g1 && v2->onWhat() == g2)
            t2 =
              fabs(t1 - bb.low()) < fabs(t1 - bb.high()) ? bb.low() : bb.high();

          if(lc1 == -1)
            lc1 = BGM_MeshSize(v1->onWhat(), 0, 0, v1->x(), v1->y(), v1->z());
          if(lc2 == -1)
            lc2 = BGM_MeshSize(v2->onWhat(), 0, 0, v2->x(), v2->y(), v2->z());
          // should be better, i.e. equidistant
          double t = 0.5 * (t2 + t1);
          double lc = 0.5 * (lc1 + lc2);
          GPoint V = itr->ge->point(t);
          MEdgeVertex *newv =
            new MEdgeVertex(V.x(), V.y(), V.z(), itr->ge, t, 0, lc);
          newLines.push_back(new MLine(v1, newv));
          newLines.push_back(new MLine(newv, v2));
          delete itr->ge->lines[i];
        }
        else {
          newLines.push_back(itr->ge->lines[i]);
        }
      }
      else {
        newLines.push_back(itr->ge->lines[i]);
      }
    }

    itr->ge->lines = newLines;
    itr->ge->mesh_vertices.clear();
    N = itr->ge->lines.size();
    for(int i = 1; i < N; i++) {
      itr->ge->mesh_vertices.push_back(itr->ge->lines[i]->getVertex(0));
    }
  }
}

static bool algoDelaunay2D(GFace *gf)
{
  if(gf->getMeshingAlgo() == ALGO_2D_DELAUNAY ||
     gf->getMeshingAlgo() == ALGO_2D_BAMG ||
     gf->getMeshingAlgo() == ALGO_2D_FRONTAL ||
     gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD ||
     gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
     gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR ||
     gf->getMeshingAlgo() == ALGO_2D_BAMG)
    return true;

  if(gf->getMeshingAlgo() == ALGO_2D_AUTO && gf->geomType() == GEntity::Plane)
    return true;

  return false;
}

static bool recoverEdge(BDS_Mesh *m, GFace *gf, GEdge *ge,
                        std::map<MVertex *, BDS_Point *> &recoverMapInv,
                        std::set<EdgeToRecover> *e2r,
                        std::set<EdgeToRecover> *notRecovered, int pass)
{
  BDS_GeomEntity *g = 0;
  if(pass == 2) {
    m->add_geom(ge->tag(), 1);
    g = m->get_geom(ge->tag(), 1);
  }

  bool _fatallyFailed;

  for(std::size_t i = 0; i < ge->lines.size(); i++) {
    MVertex *vstart = ge->lines[i]->getVertex(0);
    MVertex *vend = ge->lines[i]->getVertex(1);
    std::map<MVertex *, BDS_Point *>::iterator itpstart =
      recoverMapInv.find(vstart);
    std::map<MVertex *, BDS_Point *>::iterator itpend =
      recoverMapInv.find(vend);
    if(itpstart != recoverMapInv.end() && itpend != recoverMapInv.end()) {
      BDS_Point *pstart = itpstart->second;
      BDS_Point *pend = itpend->second;
      if(pass == 1)
        e2r->insert(EdgeToRecover(pstart->iD, pend->iD, ge));
      else {
        BDS_Edge *e = m->recover_edge(pstart->iD, pend->iD, _fatallyFailed, e2r,
                                      notRecovered);
        if(e)
          e->g = g;
        else {
          if(_fatallyFailed) {
            Msg::Error("Unable to recover the edge %d (%d/%d) on curve %d (on "
                       "surface %d)",
                       ge->lines[i]->getNum(), i + 1, ge->lines.size(),
                       ge->tag(), gf->tag());
            if(Msg::GetVerbosity() == 99) {
              outputScalarField(m->triangles, "wrongmesh.pos", 0);
              outputScalarField(m->triangles, "wrongparam.pos", 1);
            }
          }
          return !_fatallyFailed;
        }
      }
    }
  }

  if(pass == 2 && ge->getBeginVertex()) {
    MVertex *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
    MVertex *vend = *(ge->getEndVertex()->mesh_vertices.begin());
    std::map<MVertex *, BDS_Point *>::iterator itpstart =
      recoverMapInv.find(vstart);
    std::map<MVertex *, BDS_Point *>::iterator itpend =
      recoverMapInv.find(vend);
    if(itpstart != recoverMapInv.end() && itpend != recoverMapInv.end()) {
      BDS_Point *pstart = itpstart->second;
      BDS_Point *pend = itpend->second;
      if(!pstart->g) {
        m->add_geom(pstart->iD, 0);
        BDS_GeomEntity *g0 = m->get_geom(pstart->iD, 0);
        pstart->g = g0;
      }
      if(!pend->g) {
        m->add_geom(pend->iD, 0);
        BDS_GeomEntity *g0 = m->get_geom(pend->iD, 0);
        pend->g = g0;
      }
    }
  }

  return true;
}

static void addOrRemove(MVertex *v1, MVertex *v2,
                        std::set<MEdge, Less_Edge> &bedges,
                        std::set<MEdge, Less_Edge> &removed)
{
  MEdge e(v1, v2);
  if(removed.find(e) != removed.end()) return;
  std::set<MEdge, Less_Edge>::iterator it = bedges.find(e);
  if(it == bedges.end())
    bedges.insert(e);
  else {
    bedges.erase(it);
    removed.insert(e);
  }
}

static void modifyInitialMeshForBoundaryLayers(
  GFace *gf, std::vector<MQuadrangle *> &blQuads,
  std::vector<MTriangle *> &blTris, std::set<MVertex *> &verts, bool debug)
{
  if(!buildAdditionalPoints2D(gf)) return;
  BoundaryLayerColumns *_columns = gf->getColumns();

  std::set<MEdge, Less_Edge> bedges;
  std::set<MEdge, Less_Edge> removed;

  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> const &embedded_edges = gf->embeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(), embedded_edges.end());
  std::vector<GEdge *>::iterator ite = edges.begin();

  FILE *ff2 = 0;
  if(debug) ff2 = Fopen("tato.pos", "w");
  if(ff2) fprintf(ff2, "View \" \"{\n");

  std::vector<MLine *> _lines;

  while(ite != edges.end()) {
    for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
      _lines.push_back((*ite)->lines[i]);
      MVertex *v1 = (*ite)->lines[i]->getVertex(0);
      MVertex *v2 = (*ite)->lines[i]->getVertex(1);
      MEdge dv(v1, v2);
      addOrRemove(v1, v2, bedges, removed);
      for(std::size_t SIDE = 0; SIDE < _columns->_normals.count(dv); SIDE++) {
        std::vector<MElement *> myCol;
        edgeColumn ec = _columns->getColumns(v1, v2, SIDE);
        const BoundaryLayerData &c1 = ec._c1;
        const BoundaryLayerData &c2 = ec._c2;
        int N = std::min(c1._column.size(), c2._column.size());
        if(!N) continue;
        for(int l = 0; l < N; ++l) {
          MVertex *v11, *v12, *v21, *v22;
          v21 = c1._column[l];
          v22 = c2._column[l];
          if(l == 0) {
            v11 = v1;
            v12 = v2;
          }
          else {
            v11 = c1._column[l - 1];
            v12 = c2._column[l - 1];
          }
          MQuadrangle *qq = new MQuadrangle(v11, v21, v22, v12);
          qq->setPartition(l + 1);
          myCol.push_back(qq);
          blQuads.push_back(qq);
          if(ff2)
            fprintf(ff2,
                    "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                    v11->x(), v11->y(), v11->z(), v12->x(), v12->y(), v12->z(),
                    v22->x(), v22->y(), v22->z(), v21->x(), v21->y(), v21->z(),
                    l + 1, l + 1, l + 1, l + 1);
        }
        if(c1._column.size() != c2._column.size()) {
          MVertex *v11, *v12, *v;
          v11 = c1._column[N - 1];
          v12 = c2._column[N - 1];
          v = c1._column.size() > c2._column.size() ? c1._column[N] :
                                                      c2._column[N];
          MTriangle *qq = new MTriangle(v11, v12, v);
          qq->setPartition(N + 1);
          myCol.push_back(qq);
          blTris.push_back(qq);
          if(ff2)
            fprintf(ff2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                    v11->x(), v11->y(), v11->z(), v12->x(), v12->y(), v12->z(),
                    v->x(), v->y(), v->z(), N + 1, N + 1, N + 1);
        }
        // int M = std::max(c1._column.size(),c2._column.size());
        for(std::size_t l = 0; l < myCol.size(); l++)
          _columns->_toFirst[myCol[l]] = myCol[0];
        _columns->_elemColumns[myCol[0]] = myCol;
      }
    }
    ++ite;
  }

  for(BoundaryLayerColumns::iterf itf = _columns->beginf();
      itf != _columns->endf(); ++itf) {
    MVertex *v = itf->first;
    int nbCol = _columns->getNbColumns(v);

    for(int i = 0; i < nbCol - 1; i++) {
      const BoundaryLayerData &c1 = _columns->getColumn(v, i);
      const BoundaryLayerData &c2 = _columns->getColumn(v, i + 1);
      int N = std::min(c1._column.size(), c2._column.size());
      std::vector<MElement *> myCol;
      for(int l = 0; l < N; ++l) {
        MVertex *v11, *v12, *v21, *v22;
        v21 = c1._column[l];
        v22 = c2._column[l];
        if(l == 0) {
          v11 = v;
          v12 = v;
        }
        else {
          v11 = c1._column[l - 1];
          v12 = c2._column[l - 1];
        }
        if(v11 != v12) {
          MQuadrangle *qq = new MQuadrangle(v11, v12, v22, v21);
          qq->setPartition(l + 1);
          myCol.push_back(qq);
          blQuads.push_back(qq);
          if(ff2)
            fprintf(ff2,
                    "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                    v11->x(), v11->y(), v11->z(), v12->x(), v12->y(), v12->z(),
                    v22->x(), v22->y(), v22->z(), v21->x(), v21->y(), v21->z(),
                    l + 1, l + 1, l + 1, l + 1);
        }
        else {
          MTriangle *qq = new MTriangle(v, v22, v21);
          qq->setPartition(l + 1);
          myCol.push_back(qq);
          blTris.push_back(qq);
          if(ff2)
            fprintf(ff2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n", v->x(),
                    v->y(), v->z(), v22->x(), v22->y(), v22->z(), v21->x(),
                    v21->y(), v21->z(), l + 1, l + 1, l + 1);
        }
      }
      for(std::size_t l = 0; l < myCol.size(); l++)
        _columns->_toFirst[myCol[l]] = myCol[0];
      _columns->_elemColumns[myCol[0]] = myCol;
    }
  }

  if(ff2) {
    fprintf(ff2, "};\n");
    fclose(ff2);
  }

  filterOverlappingElements(_lines, blTris, blQuads, _columns->_elemColumns,
                            _columns->_toFirst);

  for(std::size_t i = 0; i < blQuads.size(); i++) {
    addOrRemove(blQuads[i]->getVertex(0), blQuads[i]->getVertex(1), bedges,
                removed);
    addOrRemove(blQuads[i]->getVertex(1), blQuads[i]->getVertex(2), bedges,
                removed);
    addOrRemove(blQuads[i]->getVertex(2), blQuads[i]->getVertex(3), bedges,
                removed);
    addOrRemove(blQuads[i]->getVertex(3), blQuads[i]->getVertex(0), bedges,
                removed);
    for(int j = 0; j < 4; j++)
      if(blQuads[i]->getVertex(j)->onWhat() == gf)
        verts.insert(blQuads[i]->getVertex(j));
  }
  for(std::size_t i = 0; i < blTris.size(); i++) {
    addOrRemove(blTris[i]->getVertex(0), blTris[i]->getVertex(1), bedges,
                removed);
    addOrRemove(blTris[i]->getVertex(1), blTris[i]->getVertex(2), bedges,
                removed);
    addOrRemove(blTris[i]->getVertex(2), blTris[i]->getVertex(0), bedges,
                removed);
    for(int j = 0; j < 3; j++)
      if(blTris[i]->getVertex(j)->onWhat() == gf)
        verts.insert(blTris[i]->getVertex(j));
  }

  discreteEdge ne(gf->model(), 444444, 0, (*edges.begin())->getEndVertex());
  std::vector<GEdge *> hop;
  std::set<MEdge, Less_Edge>::iterator it = bedges.begin();

  FILE *ff = 0;
  if(debug) ff = Fopen("toto.pos", "w");
  if(ff) fprintf(ff, "View \" \"{\n");
  for(; it != bedges.end(); ++it) {
    ne.lines.push_back(new MLine(it->getVertex(0), it->getVertex(1)));
    if(ff)
      fprintf(ff, "SL(%g,%g,%g,%g,%g,%g){1,1};\n", it->getVertex(0)->x(),
              it->getVertex(0)->y(), it->getVertex(0)->z(),
              it->getVertex(1)->x(), it->getVertex(1)->y(),
              it->getVertex(1)->z());
  }
  if(ff) {
    fprintf(ff, "};\n");
    fclose(ff);
  }
  hop.push_back(&ne);

  deMeshGFace kil_;
  kil_(gf);
  meshGenerator(gf, 0, 0, true, false, &hop);
}

static bool improved_translate(GFace *gf, MVertex *vertex, SVector3 &v1,
                               SVector3 &v2)
{
  double x, y;
  double angle;
  SPoint2 point;
  SVector3 s1, s2;
  SVector3 normal;
  SVector3 basis_u, basis_v;
  Pair<SVector3, SVector3> derivatives;

  reparamMeshVertexOnFace(vertex, gf, point);
  x = point.x();
  y = point.y();

  angle = backgroundMesh::current()->getAngle(x, y, 0.0);
  derivatives = gf->firstDer(point);

  s1 = derivatives.first();
  s2 = derivatives.second();
  normal = crossprod(s1, s2);

  basis_u = s1;
  basis_u.normalize();
  basis_v = crossprod(normal, basis_u);
  basis_v.normalize();

  v1 = basis_u * cos(angle) + basis_v * sin(angle);
  v2 = crossprod(v1, normal);
  v2.normalize();

  return 1;
}

static void directions_storage(GFace *gf)
{
  std::set<MVertex *> vertices;
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      vertices.insert(vertex);
    }
  }

  backgroundMesh::set(gf);

  gf->storage1.clear();
  gf->storage2.clear();
  gf->storage3.clear();
  gf->storage4.clear();

  for(std::set<MVertex *>::iterator it = vertices.begin(); it != vertices.end();
      it++) {
    SPoint2 point;
    SVector3 v1;
    SVector3 v2;
    bool ok = improved_translate(gf, *it, v1, v2);
    if(ok) {
      gf->storage1.push_back(SPoint3((*it)->x(), (*it)->y(), (*it)->z()));
      gf->storage2.push_back(v1);
      gf->storage3.push_back(v2);
      reparamMeshVertexOnFace(*it, gf, point);
      gf->storage4.push_back(
        backgroundMesh::current()->operator()(point.x(), point.y(), 0.0));
    }
  }

  backgroundMesh::unset();
}

static void
BDS2GMSH(BDS_Mesh *m, GFace *gf,
         std::map<BDS_Point *, MVertex *, PointLessThan> &recoverMap)
{
  std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
  while(itt != m->triangles.end()) {
    BDS_Face *t = *itt;
    if(!t->deleted) {
      BDS_Point *n[4];
      t->getNodes(n);
      MVertex *v[4] = {0, 0, 0, 0};
      for(int i = 0; i < 4; i++) {
        if(!n[i]) continue;
        if(recoverMap.find(n[i]) == recoverMap.end()) {
          v[i] =
            new MFaceVertex(n[i]->X, n[i]->Y, n[i]->Z, gf, n[i]->u, n[i]->v);
          recoverMap[n[i]] = v[i];
          gf->mesh_vertices.push_back(v[i]);
        }
        else
          v[i] = recoverMap[n[i]];
      }
      if(!v[3]) {
        // when a singular point is present, degenerated triangles may be
        // created, for example on a sphere that contains one pole
        if(v[0] != v[1] && v[0] != v[2] && v[1] != v[2])
          gf->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
      }
      else {
        gf->quadrangles.push_back(new MQuadrangle(v[0], v[1], v[2], v[3]));
      }
    }
    ++itt;
  }
}

static void _deleteUnusedVertices(GFace *gf)
{
  std::set<MVertex *, MVertexLessThanNum> allverts;
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    for(int j = 0; j < 3; j++) {
      if(gf->triangles[i]->getVertex(j)->onWhat() == gf)
        allverts.insert(gf->triangles[i]->getVertex(j));
    }
  }
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    for(int j = 0; j < 4; j++) {
      if(gf->quadrangles[i]->getVertex(j)->onWhat() == gf)
        allverts.insert(gf->quadrangles[i]->getVertex(j));
    }
  }
  for(std::size_t i = 0; i < gf->mesh_vertices.size(); i++) {
    if(allverts.find(gf->mesh_vertices[i]) == allverts.end())
      delete gf->mesh_vertices[i];
  }
  gf->mesh_vertices.clear();
  gf->mesh_vertices.insert(gf->mesh_vertices.end(), allverts.begin(),
                           allverts.end());
}

// Builds An initial triangular mesh that respects the boundaries of
// the domain, including embedded points and surfaces
bool meshGenerator(GFace *gf, int RECUR_ITER, bool repairSelfIntersecting1dMesh,
                   bool onlyInitialMesh, bool debug,
                   std::vector<GEdge *> *replacement_edges)
{
  if(CTX::instance()->debugSurface > 0 &&
     gf->tag() != CTX::instance()->debugSurface) {
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }
  if(CTX::instance()->debugSurface > 0) debug = true;

  // onlyInitialMesh=true;
  BDS_GeomEntity CLASS_F(1, 2);
  BDS_GeomEntity CLASS_EXTERIOR(1, 3);
  std::map<BDS_Point *, MVertex *, PointLessThan> recoverMap;
  std::map<MVertex *, BDS_Point *> recoverMapInv;
  std::vector<GEdge *> edges =
    replacement_edges ? *replacement_edges : gf->edges();

  // build a set with all points of the boundaries
  std::set<MVertex *, MVertexLessThanNum> all_vertices, boundary;
  std::vector<GEdge *>::const_iterator ite = edges.begin();

  FILE *fdeb = NULL;
  if(debug && RECUR_ITER == 0) {
    char name[245];
    sprintf(name, "surface%d-boundary-real.pos", gf->tag());
    fdeb = fopen(name, "w");
    fprintf(fdeb, "View \"\"{\n");
  }

  while(ite != edges.end()) {
    if((*ite)->isSeam(gf)) {
      if(fdeb != NULL) fclose(fdeb);
      return false;
    }
    if(!(*ite)->isMeshDegenerated()) {
      for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
        MVertex *v1 = (*ite)->lines[i]->getVertex(0);
        MVertex *v2 = (*ite)->lines[i]->getVertex(1);

        if(fdeb) {
          fprintf(fdeb, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", v1->x(), v1->y(),
                  v1->z(), v2->x(), v2->y(), v2->z(), (*ite)->tag(),
                  (*ite)->tag());
        }

        all_vertices.insert(v1);
        all_vertices.insert(v2);
        if(boundary.find(v1) == boundary.end())
          boundary.insert(v1);
        else
          boundary.erase(v1);
        if(boundary.find(v2) == boundary.end())
          boundary.insert(v2);
        else
          boundary.erase(v2);
      }
    }
    else
      Msg::Debug("Degenerated mesh on edge %d", (*ite)->tag());
    ++ite;
  }

  if(fdeb) {
    fprintf(fdeb, "};\n");
    fclose(fdeb);
  }

  if(boundary.size()) {
    Msg::Error("The 1D mesh seems not to be forming a closed loop (%d boundary "
               "nodes are considered once)",
               boundary.size());
    for(std::set<MVertex *, MVertexLessThanNum>::iterator it = boundary.begin();
        it != boundary.end(); it++){
      Msg::Debug("Remaining node %lu", (*it)->getNum());
    }
    gf->meshStatistics.status = GFace::FAILED;
    return false;
  }

  std::vector<GEdge *> const &emb_edges = gf->embeddedEdges();
  ite = emb_edges.begin();
  while(ite != emb_edges.end()) {
    if(!(*ite)->isMeshDegenerated()) {
      all_vertices.insert((*ite)->mesh_vertices.begin(),
                          (*ite)->mesh_vertices.end());
      if((*ite)->getBeginVertex())
        all_vertices.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
                            (*ite)->getBeginVertex()->mesh_vertices.end());
      if((*ite)->getEndVertex())
        all_vertices.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
                            (*ite)->getEndVertex()->mesh_vertices.end());
    }
    ++ite;
  }

  // add embedded vertices
  std::set<GVertex *, GEntityLessThan> emb_vertx = gf->embeddedVertices();
  std::set<GVertex *, GEntityLessThan>::iterator itvx = emb_vertx.begin();
  while(itvx != emb_vertx.end()) {
    all_vertices.insert((*itvx)->mesh_vertices.begin(),
                        (*itvx)->mesh_vertices.end());
    ++itvx;
  }

  if(all_vertices.size() < 3) {
    Msg::Warning("Mesh generation of surface %d skipped: only %d nodes on "
                 "the boundary",
                 gf->tag(), all_vertices.size());
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }
  else if(all_vertices.size() == 3) {
    MVertex *vv[3] = {0, 0, 0};
    int i = 0;
    for(std::set<MVertex *, MVertexLessThanNum>::iterator it =
          all_vertices.begin();
        it != all_vertices.end(); it++) {
      vv[i++] = *it;
    }
    gf->triangles.push_back(new MTriangle(vv[0], vv[1], vv[2]));
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }

  // Buid a BDS_Mesh structure that is convenient for doing the actual
  // meshing procedure
  BDS_Mesh *m = new BDS_Mesh;

  std::vector<BDS_Point *> points(all_vertices.size());
  SBoundingBox3d bbox;
  int count = 0;
  for(std::set<MVertex *, MVertexLessThanNum>::iterator it =
        all_vertices.begin();
      it != all_vertices.end(); it++) {
    MVertex *here = *it;
    GEntity *ge = here->onWhat();
    SPoint2 param;
    reparamMeshVertexOnFace(here, gf, param);
    BDS_Point *pp = m->add_point(count, param[0], param[1], gf);
    m->add_geom(ge->tag(), ge->dim());
    BDS_GeomEntity *g = m->get_geom(ge->tag(), ge->dim());
    pp->g = g;
    recoverMap[pp] = here;
    recoverMapInv[here] = pp;
    points[count] = pp;
    bbox += SPoint3(param[0], param[1], 0);
    count++;
  }

  bbox.makeCube();

  // use a divide & conquer type algorithm to create a triangulation.
  // We add to the triangulation a box with 4 points that encloses the
  // domain.
#ifdef OLD_CODE_DELAUNAY
  {
    // compute the bounding box in parametric space
    SVector3 dd(bbox.max(), bbox.min());
    double LC2D = norm(dd);
    DocRecord doc(points.size() + 4);
    for(std::size_t i = 0; i < points.size(); i++) {
      double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
                  (double)RAND_MAX;
      double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
                  (double)RAND_MAX;
      doc.points[i].where.h = points[i]->u + XX;
      doc.points[i].where.v = points[i]->v + YY;
      doc.points[i].data = points[i];
      doc.points[i].adjacent = NULL;
    }

    // increase the size of the bounding box
    bbox *= 2.5;

    // add 4 points than encloses the domain (use negative number to
    // distinguish those fake vertices)
    double bb[4][2] = {{bbox.min().x(), bbox.min().y()},
                       {bbox.min().x(), bbox.max().y()},
                       {bbox.max().x(), bbox.min().y()},
                       {bbox.max().x(), bbox.max().y()}};
    for(int ip = 0; ip < 4; ip++) {
      BDS_Point *pp = m->add_point(-ip - 1, bb[ip][0], bb[ip][1], gf);
      m->add_geom(gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
      doc.points[points.size() + ip].where.h = bb[ip][0];
      doc.points[points.size() + ip].where.v = bb[ip][1];
      doc.points[points.size() + ip].adjacent = 0;
      doc.points[points.size() + ip].data = pp;
    }

    // Use "fast" inhouse recursive algo to generate the triangulation.
    // At this stage the triangulation is not what we need
    //   -) It does not necessary recover the boundaries
    //   -) It contains triangles outside the domain (the first edge
    //      loop is the outer one)
    Msg::Debug("Meshing of the convex hull (%d points)", points.size());
    try {
      doc.MakeMeshWithPoints();
    } catch(const char *err) {
      Msg::Error("%s", err);
    }
    Msg::Debug("Meshing of the convex hull (%d points) done", points.size());

    for(int i = 0; i < doc.numTriangles; i++) {
      int a = doc.triangles[i].a;
      int b = doc.triangles[i].b;
      int c = doc.triangles[i].c;
      int n = doc.numPoints;
      if(a < 0 || a >= n || b < 0 || b >= n || c < 0 || c >= n) {
        Msg::Warning("Skipping bad triangle %d", i);
        continue;
      }
      BDS_Point *p1 = (BDS_Point *)doc.points[doc.triangles[i].a].data;
      BDS_Point *p2 = (BDS_Point *)doc.points[doc.triangles[i].b].data;
      BDS_Point *p3 = (BDS_Point *)doc.points[doc.triangles[i].c].data;
      m->add_triangle(p1->iD, p2->iD, p3->iD);
    }
  }
#else
  {
    std::vector<MVertex *> v;
    std::vector<MTriangle *> result;
    v.insert(v.end(), all_vertices.begin(), all_vertices.end());

    std::map<MVertex *, SPoint3> pos;
    for(std::size_t i = 0; i < v.size(); i++) {
      MVertex *v0 = v[i];
      BDS_Point *p0 = recoverMapInv[v0];
      pos[v0] = SPoint3(v0->x(), v0->y(), v0->z());
      v0->setXYZ(p0->u, p0->v, 0.0);
    }
    delaunayMeshIn2D(v, result, 0);

    for(std::size_t i = 0; i < v.size() - 4; i++) {
      MVertex *v0 = v[i];
      SPoint3 pp = pos[v0];
      v0->setXYZ(pp.x(), pp.y(), pp.z());
    }

    // add the four corners
    for(int ip = 0; ip < 4; ip++) {
      MVertex *vv = v[v.size() - ip - 1];
      BDS_Point *pp = m->add_point(-ip - 1, vv->x(), vv->y(), gf);
      m->add_geom(gf->tag(), 2);
      recoverMapInv[vv] = pp;
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
    }
    // add the triangles
    for(std::size_t i = 0; i < result.size(); i++) {
      MVertex *v0 = result[i]->getVertex(0);
      MVertex *v1 = result[i]->getVertex(1);
      MVertex *v2 = result[i]->getVertex(2);
      BDS_Point *p0 = recoverMapInv[v0];
      BDS_Point *p1 = recoverMapInv[v1];
      BDS_Point *p2 = recoverMapInv[v2];
      m->add_triangle(p0->iD, p1->iD, p2->iD);
    }
  }
#endif

  if(debug && RECUR_ITER == 0) {
    char name[245];
    sprintf(name, "surface%d-initial-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-initial-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  // Recover the boundary edges and compute characteristic lenghts using mesh
  // edge spacing. If two of these edges intersect, then the 1D mesh have to be
  // densified
  Msg::Debug("Recovering %d model edges", edges.size());
  std::set<EdgeToRecover> edgesToRecover;
  std::set<EdgeToRecover> edgesNotRecovered;
  ite = edges.begin();
  while(ite != edges.end()) {
    if(!(*ite)->isMeshDegenerated())
      recoverEdge(m, gf, *ite, recoverMapInv, &edgesToRecover,
                  &edgesNotRecovered, 1);
    ++ite;
  }
  ite = emb_edges.begin();
  while(ite != emb_edges.end()) {
    if(!(*ite)->isMeshDegenerated())
      recoverEdge(m, gf, *ite, recoverMapInv, &edgesToRecover,
                  &edgesNotRecovered, 1);
    ++ite;
  }

  // effectively recover the medge
  ite = edges.begin();
  while(ite != edges.end()) {
    if(!(*ite)->isMeshDegenerated()) {
      if(!recoverEdge(m, gf, *ite, recoverMapInv, &edgesToRecover,
                      &edgesNotRecovered, 2)) {
        delete m;
        gf->meshStatistics.status = GFace::FAILED;
        return false;
      }
    }
    ++ite;
  }

  Msg::Debug("Recovering %d mesh edges (%d not recovered)",
             edgesToRecover.size(), edgesNotRecovered.size());

  if(edgesNotRecovered.size() || gf->meshStatistics.refineAllEdges) {
    std::ostringstream sstream;
    for(std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
        itr != edgesNotRecovered.end(); ++itr)
      sstream << " " << itr->ge->tag();
    if(gf->meshStatistics.refineAllEdges) {
      Msg::Info("8-| Splitting all edges and trying again");
    }
    else {
      Msg::Info(":-( There are %d intersections in the 1D mesh (curves%s)",
                edgesNotRecovered.size(), sstream.str().c_str());
      if(repairSelfIntersecting1dMesh)
        Msg::Info("8-| Splitting those edges and trying again");
    }
    if(debug) {
      char name[245];
      sprintf(name, "surface%d-not_yet_recovered-real-%d.msh", gf->tag(),
              RECUR_ITER);
      gf->model()->writeMSH(name);
    }

    if(repairSelfIntersecting1dMesh) {
      remeshUnrecoveredEdges(recoverMapInv, edgesNotRecovered);
      gf->meshStatistics.refineAllEdges = false;
    }
    else {
      std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
      int I = 0;
      for(; itr != edgesNotRecovered.end(); ++itr) {
        int p1 = itr->p1;
        int p2 = itr->p2;
        int tag = itr->ge->tag();
        Msg::Error("Edge not recovered: %d %d %d", p1, p2, tag);
        I++;
      }
    }

    // delete the mesh
    delete m;
    if(RECUR_ITER < 10) {
      return meshGenerator(gf, RECUR_ITER + 1, repairSelfIntersecting1dMesh,
                           onlyInitialMesh, debug, replacement_edges);
    }
    return false;
  }

  if(RECUR_ITER > 0)
    Msg::Info(":-) All edges recovered after %d iteration%s", RECUR_ITER,
              (RECUR_ITER > 1) ? "s" : "");

  Msg::Debug("Boundary edges recovered for surface %d", gf->tag());

  // look for a triangle that has a negative node and recursively tag all
  // exterior triangles
  {
    std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      (*itt)->g = 0;
      ++itt;
    }
    itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      BDS_Face *t = *itt;
      BDS_Point *n[4];
      t->getNodes(n);
      if(n[0]->iD < 0 || n[1]->iD < 0 || n[2]->iD < 0) {
        recur_tag(t, &CLASS_EXTERIOR);
        break;
      }
      ++itt;
    }
  }

  // now find an edge that has belongs to one of the exterior triangles
  {
    std::vector<BDS_Edge *>::iterator ite = m->edges.begin();
    while(ite != m->edges.end()) {
      BDS_Edge *e = *ite;
      if(e->g && e->numfaces() == 2) {
        if(e->faces(0)->g == &CLASS_EXTERIOR) {
          recur_tag(e->faces(1), &CLASS_F);
          break;
        }
        else if(e->faces(1)->g == &CLASS_EXTERIOR) {
          recur_tag(e->faces(0), &CLASS_F);
          break;
        }
      }
      ++ite;
    }
    std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      if((*itt)->g == &CLASS_EXTERIOR) (*itt)->g = 0;
      ++itt;
    }
  }

  {
    std::vector<BDS_Edge *>::iterator ite = m->edges.begin();
    while(ite != m->edges.end()) {
      BDS_Edge *e = *ite;
      if(e->g && e->numfaces() == 2) {
        BDS_Point *oface[2];
        e->oppositeof(oface);
        if(oface[0]->iD < 0) {
          recur_tag(e->faces(1), &CLASS_F);
          break;
        }
        else if(oface[1]->iD < 0) {
          recur_tag(e->faces(0), &CLASS_F);
          break;
        }
      }
      ++ite;
    }
  }

  ite = emb_edges.begin();
  while(ite != emb_edges.end()) {
    if(!(*ite)->isMeshDegenerated())
      recoverEdge(m, gf, *ite, recoverMapInv, &edgesToRecover,
                  &edgesNotRecovered, 2);
    ++ite;
  }

  // compute characteristic lengths at vertices
  if(CTX::instance()->mesh.algo2d != ALGO_2D_BAMG && !onlyInitialMesh) {
    Msg::Debug("Computing mesh size field at mesh vertices %d",
               edgesToRecover.size());
    std::set<BDS_Point *, PointLessThan>::iterator it = m->points.begin();
    for(; it != m->points.end(); ++it) {
      BDS_Point *pp = *it;
      std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itv =
        recoverMap.find(pp);
      if(itv != recoverMap.end()) {
        MVertex *here = itv->second;
        GEntity *ge = here->onWhat();
        if(ge->dim() == 0) {
          pp->lcBGM() = BGM_MeshSize(ge, 0, 0, here->x(), here->y(), here->z());
        }
        else if(ge->dim() == 1) {
          double u;
          here->getParameter(0, u);
          pp->lcBGM() = BGM_MeshSize(ge, u, 0, here->x(), here->y(), here->z());
        }
        else
          pp->lcBGM() = MAX_LC;
        pp->lc() = pp->lcBGM();
      }
    }
  }

  // delete useless stuff
  std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
  while(itt != m->triangles.end()) {
    BDS_Face *t = *itt;
    if(!t->g) m->del_face(t);
    ++itt;
  }
  m->cleanup();

  {
    std::vector<BDS_Edge *>::iterator ite = m->edges.begin();
    while(ite != m->edges.end()) {
      BDS_Edge *e = *ite;
      if(e->numfaces() == 0)
        m->del_edge(e);
      else {
        if(!e->g) e->g = &CLASS_F;
        if(!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree)
          e->p1->g = e->g;
        if(!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree)
          e->p2->g = e->g;
      }
      ++ite;
    }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  if(debug) {
    char name[245];
    sprintf(name, "surface%d-recovered-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-recovered-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  if(1) {
    std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      BDS_Face *t = *itt;
      if(!t->deleted) {
        BDS_Point *n[4];
        t->getNodes(n);
        MVertex *v1 = recoverMap[n[0]];
        MVertex *v2 = recoverMap[n[1]];
        MVertex *v3 = recoverMap[n[2]];
        if(!n[3]) {
          if(v1 != v2 && v1 != v3 && v2 != v3)
            gf->triangles.push_back(new MTriangle(v1, v2, v3));
        }
        else {
          MVertex *v4 = recoverMap[n[3]];
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        }
      }
      ++itt;
    }
  }

  {
    int nb_swap;
    Msg::Debug("Delaunizing the initial mesh");
    delaunayizeBDS(gf, *m, nb_swap);
  }

  // only delete the mesh data stored in the base GFace class
  gf->GFace::deleteMesh();

  Msg::Debug("Starting to add internal points");
  // start mesh generation
  if(!algoDelaunay2D(gf) && !onlyInitialMesh) {
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, true,
                  &recoverMapInv, NULL);
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, false,
                  &recoverMapInv, NULL);
  }

  gf->meshStatistics.status = GFace::DONE;

  // fill the small gmsh structures
  BDS2GMSH(m, gf, recoverMap);

  std::vector<MQuadrangle *> blQuads;
  std::vector<MTriangle *> blTris;
  std::set<MVertex *> verts;

  bool infty = false;
  if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD) {
    infty = true;
    if(!onlyInitialMesh)
      buildBackgroundMesh(gf, CTX::instance()->mesh.crossFieldClosestPoint);
  }
  else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
          gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR) {
    infty = true;
    if(!onlyInitialMesh) buildBackgroundMesh(gf, false);
  }

  if(!onlyInitialMesh)
    modifyInitialMeshForBoundaryLayers(gf, blQuads, blTris, verts, debug);

  // the delaunay algo is based directly on internal gmsh structures BDS mesh is
  // passed in order not to recompute local coordinates of vertices
  if(algoDelaunay2D(gf) && !onlyInitialMesh) {
    if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL) { bowyerWatsonFrontal(gf); }
    else if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD) {
      bowyerWatsonFrontalLayers(gf, true);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS) {
      bowyerWatsonParallelograms(gf);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR) {
      bowyerWatsonParallelogramsConstrained(gf, gf->constr_vertices);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_DELAUNAY ||
            gf->getMeshingAlgo() == ALGO_2D_AUTO) {
      bowyerWatson(gf);
    }
    else {
      bowyerWatson(gf, 15000);
      meshGFaceBamg(gf);
    }
    if(!infty ||
       !(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine))
      laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing, infty);
  }

  if(debug) {
    char name[256];
    // sprintf(name, "trueBoundary%d.pos", gf->tag());
    // std::vector<SPoint2> bnd;
    // trueBoundary(name, gf,bnd);
    sprintf(name, "real%d.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "param%d.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  delete m;

  gf->quadrangles.insert(gf->quadrangles.begin(), blQuads.begin(),
                         blQuads.end());
  gf->triangles.insert(gf->triangles.begin(), blTris.begin(), blTris.end());
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(), verts.begin(),
                           verts.end());

  splitElementsInBoundaryLayerIfNeeded(gf);

  if((CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine) &&
     !onlyInitialMesh && CTX::instance()->mesh.algoRecombine <= 1) {
    bool blossom = (CTX::instance()->mesh.algoRecombine == 1);
    int topo = CTX::instance()->mesh.recombineOptimizeTopology;
    recombineIntoQuads(gf, blossom, topo, true, 0.1);
  }

  computeElementShapes(gf, gf->meshStatistics.worst_element_shape,
                       gf->meshStatistics.average_element_shape,
                       gf->meshStatistics.best_element_shape,
                       gf->meshStatistics.nbTriangle,
                       gf->meshStatistics.nbGoodQuality);

  if(CTX::instance()->mesh.algo3d == ALGO_3D_RTREE) { directions_storage(gf); }

  // remove unused vertices, generated e.g. during background mesh
  _deleteUnusedVertices(gf);

  return true;
}

// this function buils a list of vertices (BDS) that are consecutive in one
// given edge loop. We take care of periodic surfaces. In the case of
// periodicty, some curves are present 2 times in the wire (seams). Those must
// be meshed separately

static inline double dist2(const SPoint2 &p1, const SPoint2 &p2)
{
  const double dx = p1.x() - p2.x();
  const double dy = p1.y() - p2.y();
  return dx * dx + dy * dy;
}

/*
static void printMesh1d(int iEdge, int seam, std::vector<SPoint2> &m)
{
  printf("Mesh1D for edge %d seam %d\n", iEdge, seam);
  for(std::size_t i = 0; i < m.size(); i++){
    printf("%12.5E %12.5E\n", m[i].x(), m[i].y());
  }
}
*/

static bool buildConsecutiveListOfVertices(
  GFace *gf, GEdgeLoop &gel, std::vector<BDS_Point *> &result,
  SBoundingBox3d &bbox, BDS_Mesh *m,
  std::map<BDS_Point *, MVertex *, PointLessThan> &recoverMap, int &count,
  int countTot, double tol, bool seam_the_first = false)
{
  // for each edge, we build a list of points that are the mapping of the edge
  // points on the face for seams, we build the list for every side for closed
  // loops, we build it on both senses

  std::map<GEntity *, std::vector<SPoint2> > meshes;
  std::map<GEntity *, std::vector<SPoint2> > meshes_seam;

  const int MYDEBUG = false;

  std::map<BDS_Point *, MVertex *, PointLessThan> recoverMapLocal;

  result.clear();
  count = 0;

  GEdgeLoop::iter it = gel.begin();

  if(MYDEBUG)
    printf("face %d with %d edges case %d\n", gf->tag(),
           (int)gf->edges().size(), seam_the_first);

  while(it != gel.end()) {
    GEdgeSigned ges = *it;
    std::vector<SPoint2> mesh1d;
    std::vector<SPoint2> mesh1d_seam;

    bool seam = ges.ge->isSeam(gf);
    Range<double> range = ges.ge->parBoundsOnFace(gf);

    mesh1d.push_back(ges.ge->reparamOnFace(gf, range.low(), 1));
    if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, range.low(), -1));
    for(std::size_t i = 0; i < ges.ge->mesh_vertices.size(); i++) {
      MVertex *here = ges.ge->mesh_vertices[i];
      double u;
      here->getParameter(0, u);
      mesh1d.push_back(ges.ge->reparamOnFace(gf, u, 1));
      if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, u, -1));
    }
    mesh1d.push_back(ges.ge->reparamOnFace(gf, range.high(), 1));
    if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, range.high(), -1));
    meshes.insert(std::pair<GEntity *, std::vector<SPoint2> >(ges.ge, mesh1d));
    if(seam)
      meshes_seam.insert(
        std::pair<GEntity *, std::vector<SPoint2> >(ges.ge, mesh1d_seam));
    // printMesh1d(ges.ge->tag(), seam, mesh1d);
    // if(seam) printMesh1d(ges.ge->tag(), seam, mesh1d_seam);
    it++;
  }

  std::list<GEdgeSigned> unordered(gel.begin(), gel.end());

  GEdgeSigned found(0, 0);
  SPoint2 last_coord(0, 0);
  int counter = 0;

  while(unordered.size()) {
    if(MYDEBUG) printf("unordered.size() = %d\n", (int)unordered.size());
    std::list<GEdgeSigned>::iterator it = unordered.begin();
    std::vector<SPoint2> coords;

    while(it != unordered.end()) {
      std::vector<SPoint2> mesh1d;
      std::vector<SPoint2> mesh1d_seam;
      std::vector<SPoint2> mesh1d_reversed;
      std::vector<SPoint2> mesh1d_seam_reversed;
      GEdge *ge = (*it).ge;
      bool seam = ge->isSeam(gf);
      mesh1d = meshes[ge];
      if(seam) { mesh1d_seam = meshes_seam[ge]; }
      mesh1d_reversed.insert(mesh1d_reversed.begin(), mesh1d.rbegin(),
                             mesh1d.rend());
      if(seam)
        mesh1d_seam_reversed.insert(mesh1d_seam_reversed.begin(),
                                    mesh1d_seam.rbegin(), mesh1d_seam.rend());
      if(!counter) {
        counter++;
        if(seam && seam_the_first) {
          coords = ((*it)._sign == 1) ? mesh1d_seam : mesh1d_seam_reversed;
          found = (*it);
        }
        else {
          coords = ((*it)._sign == 1) ? mesh1d : mesh1d_reversed;
          found = (*it);
        }
        if(MYDEBUG)
          printf("Starting with edge = %d seam %d\n", (*it).ge->tag(), seam);
        unordered.erase(it);
        break;
      }
      else {
        if(MYDEBUG) printf("Followed by edge = %d\n", (*it).ge->tag());
        SPoint2 first_coord = mesh1d[0];
        double d = -1, d_reversed = -1, d_seam = -1, d_seam_reversed = -1;
        d = dist2(last_coord, first_coord);
        if(MYDEBUG)
          printf("%g %g dist = %12.5E\n", first_coord.x(), first_coord.y(), d);
        SPoint2 first_coord_reversed = mesh1d_reversed[0];
        d_reversed = dist2(last_coord, first_coord_reversed);
        if(MYDEBUG)
          printf("%g %g dist_reversed = %12.5E\n", first_coord_reversed.x(),
                 first_coord_reversed.y(), d_reversed);
        if(d < tol && d < d_reversed) {
          coords.clear();
          coords = mesh1d;
          found = GEdgeSigned(1, ge);
          unordered.erase(it);
          goto Finalize;
        }
        if(d_reversed < tol) {
          coords.clear();
          coords = mesh1d_reversed;
          found = (GEdgeSigned(-1, ge));
          unordered.erase(it);
          goto Finalize;
        }
        if(seam) {
          SPoint2 first_coord_seam = mesh1d_seam[0];
          SPoint2 first_coord_seam_reversed = mesh1d_seam_reversed[0];
          d_seam = dist2(last_coord, first_coord_seam);
          if(MYDEBUG) printf("dist_seam = %12.5E\n", d_seam);
          if(d_seam < tol) {
            coords.clear();
            coords = mesh1d_seam;
            found = (GEdgeSigned(1, ge));
            unordered.erase(it);
            goto Finalize;
          }
          d_seam_reversed = dist2(last_coord, first_coord_seam_reversed);
          if(MYDEBUG) printf("dist_seam_reversed = %12.5E\n", d_seam_reversed);
          if(d_seam_reversed < tol) {
            coords.clear();
            coords = mesh1d_seam_reversed;
            found = GEdgeSigned(-1, ge);
            unordered.erase(it);
            break;
            goto Finalize;
          }
        }
      }
      ++it;
    }
  Finalize:
    if(MYDEBUG) printf("Finalize, found %d points\n", (int)coords.size());
    if(coords.size() == 0) {
      // It has not worked : either tolerance is wrong or the first seam edge
      // has to be taken with the other parametric coordinates (because it is
      // only present once in the closure of the domain).
      for(std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
            recoverMapLocal.begin();
          it != recoverMapLocal.end(); ++it) {
        m->del_point(it->first);
      }
      return false;
    }

    std::vector<MVertex *> edgeLoop;
    if(found._sign == 1) {
      if(found.ge->getBeginVertex()) {
        edgeLoop.push_back(found.ge->getBeginVertex()->mesh_vertices[0]);
        for(std::size_t i = 0; i < found.ge->mesh_vertices.size(); i++)
          edgeLoop.push_back(found.ge->mesh_vertices[i]);
      }
    }
    else {
      if(found.ge->getEndVertex()) {
        edgeLoop.push_back(found.ge->getEndVertex()->mesh_vertices[0]);
        for(int i = found.ge->mesh_vertices.size() - 1; i >= 0; i--)
          edgeLoop.push_back(found.ge->mesh_vertices[i]);
      }
    }

    if(MYDEBUG)
      printf("edge %d size %d size %d\n", found.ge->tag(), (int)edgeLoop.size(),
             (int)coords.size());

    std::vector<BDS_Point *> edgeLoop_BDS;
    for(std::size_t i = 0; i < edgeLoop.size(); i++) {
      MVertex *here = edgeLoop[i];
      GEntity *ge = here->onWhat();

      BDS_Point *pp = 0;
      if(ge->dim() == 0) {
        // Point might already be part of other loop
        double smallestDistance = std::numeric_limits<double>::infinity();
        for(std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
              recoverMap.begin();
            it != recoverMap.end(); ++it) {
          if(it->second == here) {
            // Also check on 2D coordinates as the point might lie on the seam
            SPoint2 param = coords[i];
            SPoint2 paramPoint(it->first->u, it->first->v);
            const double distance = param.distance(paramPoint);
            if(distance < smallestDistance) {
              smallestDistance = distance;
              pp = it->first;
              if(distance < tol) break;
            }
          }
        }
      }
      if(pp == 0) {
        double U, V;
        SPoint2 param = coords[i];
        U = param.x();
        V = param.y();
        pp = m->add_point(count + countTot, U, V, gf);
        if(ge->dim() == 0) {
          pp->lcBGM() = BGM_MeshSize(ge, 0, 0, here->x(), here->y(), here->z());
        }
        else if(ge->dim() == 1) {
          double u;
          here->getParameter(0, u);
          pp->lcBGM() = BGM_MeshSize(ge, u, 0, here->x(), here->y(), here->z());
        }
        else
          pp->lcBGM() = MAX_LC;

        pp->lc() = pp->lcBGM();
        m->add_geom(ge->tag(), ge->dim());
        BDS_GeomEntity *g = m->get_geom(ge->tag(), ge->dim());
        pp->g = g;
        if(MYDEBUG)
          printf("point %3d (%8.5f %8.5f : %8.5f %8.5f) (%2d,%2d)\n", count,
                 pp->u, pp->v, param.x(), param.y(), pp->g->classif_tag,
                 pp->g->classif_degree);
        bbox += SPoint3(U, V, 0);
      }
      edgeLoop_BDS.push_back(pp);
      recoverMapLocal[pp] = here;
      count++;
    }
    last_coord = coords[coords.size() - 1];
    if(MYDEBUG) printf("last coord %g %g\n", last_coord.x(), last_coord.y());
    result.insert(result.end(), edgeLoop_BDS.begin(), edgeLoop_BDS.end());
  }

  // It has worked, so we add all the points to the recover map
  recoverMap.insert(recoverMapLocal.begin(), recoverMapLocal.end());

  return true;
}

static GEdge *getGEdge(GFace *gf, MVertex *v1, MVertex *v2)
{
  std::vector<GEdge *> e = gf->edges();
  for(size_t i = 0; i < e.size(); i++) {
    GEdge *ge = e[i];
    for(size_t j = 0; j < ge->lines.size(); j++) {
      MLine *l = ge->lines[j];
      if(l->getVertex(0) == v1 && l->getVertex(1) == v2) return ge;
      if(l->getVertex(1) == v1 && l->getVertex(0) == v2) return ge;
    }
  }
  return NULL;
}

static bool meshGeneratorPeriodic(GFace *gf, int RECUR_ITER,
                                  bool repairSelfIntersecting1dMesh,
                                  bool debug = true)
{
  if(CTX::instance()->debugSurface > 0 &&
     gf->tag() != CTX::instance()->debugSurface) {
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }
  if(CTX::instance()->debugSurface > 0) debug = true;

  std::map<BDS_Point *, MVertex *, PointLessThan> recoverMap;
  std::multimap<MVertex *, BDS_Point *> recoverMultiMapInv;

  std::vector<SPoint2> true_boundary;
  trueBoundary(gf, true_boundary, debug);

  Range<double> rangeU = gf->parBounds(0);
  Range<double> rangeV = gf->parBounds(1);

  double du = rangeU.high() - rangeU.low();
  double dv = rangeV.high() - rangeV.low();

  const double LC2D = std::sqrt(du * du + dv * dv);

  // Buid a BDS_Mesh structure that is convenient for doing the actual meshing
  // procedure
  BDS_Mesh *m = new BDS_Mesh;

  std::vector<std::vector<BDS_Point *> > edgeLoops_BDS;
  SBoundingBox3d bbox;
  int nbPointsTotal = 0;
  {
    for(std::list<GEdgeLoop>::iterator it = gf->edgeLoops.begin();
        it != gf->edgeLoops.end(); it++) {
      std::vector<BDS_Point *> edgeLoop_BDS;
      int nbPointsLocal;
      const double fact[4] = {1.e-12, 1.e-7, 1.e-5, 1.e-3};
      bool ok = false;
      for(int i = 0; i < 4; i++) {
        if(buildConsecutiveListOfVertices(gf, *it, edgeLoop_BDS, bbox, m,
                                          recoverMap, nbPointsLocal,
                                          nbPointsTotal, fact[i] * LC2D)) {
          ok = true;
          break;
        }
        if(buildConsecutiveListOfVertices(
             gf, *it, edgeLoop_BDS, bbox, m, recoverMap, nbPointsLocal,
             nbPointsTotal, fact[i] * LC2D, true)) {
          ok = true;
          break;
        }
      }
      if(!ok) {
        gf->meshStatistics.status = GFace::FAILED;
        Msg::Error("The 1D mesh seems not to be forming a closed loop");
        delete m;
        return false;
      }
      nbPointsTotal += nbPointsLocal;
      edgeLoops_BDS.push_back(edgeLoop_BDS);
    }
  }

  {
    std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
      recoverMap.begin();
    std::map<MVertex *, BDS_Point *> INV;
    for(; it != recoverMap.end(); ++it) {
      recoverMultiMapInv.insert(std::make_pair(it->second, it->first));

      std::map<MVertex *, BDS_Point *>::iterator it2 = INV.find(it->second);
      if(it2 != INV.end()) {
        it->first->_periodicCounterpart = it2->second;
        it2->second->_periodicCounterpart = it->first;
      }
      INV[it->second] = it->first;
    }
  }

  if(nbPointsTotal < 3) {
    Msg::Warning("Mesh generation of surface %d skipped: only %d nodes on "
                 "the boundary",
                 gf->tag(), nbPointsTotal);
    gf->meshStatistics.status = GFace::DONE;
    delete m;
    return true;
  }
  else if(nbPointsTotal == 3) {
    MVertex *vv[3] = {0, 0, 0};
    int i = 0;
    for(std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
          recoverMap.begin();
        it != recoverMap.end(); it++) {
      vv[i++] = it->second;
    }
    if(vv[0] && vv[1] && vv[2])
      gf->triangles.push_back(new MTriangle(vv[0], vv[1], vv[2]));
    gf->meshStatistics.status = GFace::DONE;
    delete m;
    return true;
  }

  // Use a divide & conquer type algorithm to create a triangulation.  We add to
  // the triangulation a box with 4 points that encloses the domain.

  std::vector<int> edgesEmbedded;

  {
    int count = 0;

    // Embedded Vertices
    // add embedded vertices
    std::set<GVertex *, GEntityLessThan> emb_vertx = gf->embeddedVertices();
    std::set<GVertex *, GEntityLessThan>::iterator itvx = emb_vertx.begin();

    std::map<MVertex *, std::set<BDS_Point *> > invertedRecoverMap;
    for(std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
          recoverMap.begin();
        it != recoverMap.end(); it++) {
      invertedRecoverMap[it->second].insert(it->first);
    }

    int pNum = m->MAXPOINTNUMBER;
    nbPointsTotal += emb_vertx.size();
    {
      std::vector<GEdge *> const &emb_edges = gf->embeddedEdges();
      std::vector<GEdge *>::const_iterator ite = emb_edges.begin();
      std::set<MVertex *> vs;
      while(ite != emb_edges.end()) {
        for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
          for(std::size_t j = 0; j < 2; j++) {
            MVertex *v = (*ite)->lines[i]->getVertex(j);
            if(invertedRecoverMap.find(v) == invertedRecoverMap.end() &&
               vs.find(v) == vs.end()) {
              vs.insert(v);
            }
          }
        }
        ++ite;
      }
      nbPointsTotal += vs.size();
    }
    DocRecord doc(nbPointsTotal + 4);

    while(itvx != emb_vertx.end()) {
      MVertex *v = (*itvx)->mesh_vertices[0];
      double uv[2] = {0, 0};
      GPoint gp = gf->closestPoint(SPoint3(v->x(), v->y(), v->z()), uv);
      BDS_Point *pp = m->add_point(++pNum, gp.u(), gp.v(), gf);
      m->add_geom(-(*itvx)->tag(), 0);
      pp->g = m->get_geom(-(*itvx)->tag(), 0);
      pp->lcBGM() = BGM_MeshSize(*itvx, 0, 0, v->x(), v->y(), v->z());
      pp->lc() = pp->lcBGM();
      recoverMap[pp] = v;
      double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
                  (double)RAND_MAX;
      double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
                  (double)RAND_MAX;
      doc.points[count].where.h = pp->u + XX;
      doc.points[count].where.v = pp->v + YY;
      doc.points[count].adjacent = NULL;
      doc.points[count].data = pp;
      count++;
      ++itvx;
    }

    std::vector<GEdge *> const &emb_edges = gf->embeddedEdges();
    std::vector<GEdge *>::const_iterator ite = emb_edges.begin();
    std::set<MVertex *> vs;
    std::map<MVertex *, BDS_Point *> facile;
    while(ite != emb_edges.end()) {
      m->add_geom(-(*ite)->tag(), 1);
      for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
        for(std::size_t j = 0; j < 2; j++) {
          MVertex *v = (*ite)->lines[i]->getVertex(j);
          BDS_Point *pp = 0;
          const std::map<MVertex *, std::set<BDS_Point *> >::iterator it =
            invertedRecoverMap.find(v);
          if(it != invertedRecoverMap.end()) {
            if(it->second.size() > 1) {
              const GEdge *edge = (*ite);
              const Range<double> parBounds = edge->parBoundsOnFace(gf);
              GPoint firstPoint = edge->point(parBounds.low());
              GPoint lastPoint = edge->point(parBounds.high());
              double param;
              if(v->point().distance(
                   SPoint3(firstPoint.x(), firstPoint.y(), firstPoint.z())) <
                 v->point().distance(
                   SPoint3(lastPoint.x(), lastPoint.y(), lastPoint.z()))) {
                // Vertex lies on first point of edge
                param = parBounds.low();
              }
              else {
                // Vertex lies on last point of edge
                param = parBounds.high();
              }
              SPoint2 pointOnSurface = edge->reparamOnFace(gf, param, 1);

              const std::set<BDS_Point *> &possiblePoints = it->second;
              for(std::set<BDS_Point *>::iterator pntIt =
                    possiblePoints.begin();
                  pntIt != possiblePoints.end(); ++pntIt) {
                if(pointOnSurface.distance(SPoint2((*pntIt)->u, (*pntIt)->v)) <
                   1e-10) {
                  pp = (*pntIt);
                  break;
                }
              }
              if(pp == 0) {
                Msg::Error("Embedded edge vertex %d is on the seam edge of "
                           "surface %d and no appropriate point could be "
                           "found!",
                           v->getNum(), gf->tag());
              }
            }
            else {
              pp = *(it->second.begin());
            }
            facile[v] = pp;
          }
          if(pp == 0 && vs.find(v) == vs.end()) {
            vs.insert(v);
            double uv[2] = {0, 0};
            GPoint gp = gf->closestPoint(SPoint3(v->x(), v->y(), v->z()), uv);
            BDS_Point *pp = m->add_point(++pNum, gp.u(), gp.v(), gf);
            pp->g = m->get_geom(-(*ite)->tag(), 1);
            if(v->onWhat()->dim() == 0)
              pp->lcBGM() =
                BGM_MeshSize(v->onWhat(), 0, 0, v->x(), v->y(), v->z());
            else {
              double uu;
              v->getParameter(0, uu);
              pp->lcBGM() = BGM_MeshSize(*ite, uu, 0, v->x(), v->y(), v->z());
            }
            pp->lc() = pp->lcBGM();
            recoverMap[pp] = v;
            facile[v] = pp;
            double XX = CTX::instance()->mesh.randFactor * LC2D *
                        (double)rand() / (double)RAND_MAX;
            double YY = CTX::instance()->mesh.randFactor * LC2D *
                        (double)rand() / (double)RAND_MAX;
            doc.points[count].where.h = pp->u + XX;
            doc.points[count].where.v = pp->v + YY;
            doc.points[count].adjacent = NULL;
            doc.points[count].data = pp;
            count++;
          }
        }
      }
      for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
        BDS_Point *p0 = facile[(*ite)->lines[i]->getVertex(0)];
        BDS_Point *p1 = facile[(*ite)->lines[i]->getVertex(1)];
        edgesEmbedded.push_back(p0->iD);
        edgesEmbedded.push_back(p1->iD);
      }
      ++ite;
    }

    for(std::size_t i = 0; i < edgeLoops_BDS.size(); i++) {
      std::vector<BDS_Point *> &edgeLoop_BDS = edgeLoops_BDS[i];
      for(std::size_t j = 0; j < edgeLoop_BDS.size(); j++) {
        BDS_Point *pp = edgeLoop_BDS[j];
        double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
                    (double)RAND_MAX;
        double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
                    (double)RAND_MAX;
        doc.points[count].where.h = pp->u + XX;
        doc.points[count].where.v = pp->v + YY;
        doc.points[count].adjacent = NULL;
        doc.points[count].data = pp;
        count++;
      }
    }

    // Increase the size of the bounding box, add 4 points that enclose
    // the domain, use negative number to distinguish those fake
    // vertices

    if(du / dv < 1200 && dv / du < 1200) {
      // Fix a bug here if the size of the box is zero
      bbox.makeCube();
    }

    bbox *= 3.5;
    GPoint bb[4] = {GPoint(bbox.min().x(), bbox.min().y(), 0),
                    GPoint(bbox.min().x(), bbox.max().y(), 0),
                    GPoint(bbox.max().x(), bbox.min().y(), 0),
                    GPoint(bbox.max().x(), bbox.max().y(), 0)};
    for(int ip = 0; ip < 4; ip++) {
      BDS_Point *pp = m->add_point(-ip - 1, bb[ip].x(), bb[ip].y(), gf);
      m->add_geom(gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
      doc.points[nbPointsTotal + ip].where.h = bb[ip].x();
      doc.points[nbPointsTotal + ip].where.v = bb[ip].y();
      doc.points[nbPointsTotal + ip].adjacent = 0;
      doc.points[nbPointsTotal + ip].data = pp;
    }

    // Use "fast" inhouse recursive algo to generate the triangulation
    // At this stage the triangulation is not what we need
    //   -) It does not necessary recover the boundaries
    //   -) It contains triangles outside the domain (the first edge
    //      loop is the outer one)
    Msg::Debug("Meshing of the convex hull (%d nodes)", nbPointsTotal);

    try {
      doc.MakeMeshWithPoints();
    } catch(const char *err) {
      Msg::Error("%s", err);
    }

    for(int i = 0; i < doc.numTriangles; i++) {
      int a = doc.triangles[i].a;
      int b = doc.triangles[i].b;
      int c = doc.triangles[i].c;
      int n = doc.numPoints;
      if(a < 0 || a >= n || b < 0 || b >= n || c < 0 || c >= n) {
        Msg::Warning("Skipping bad triangle %d", i);
        continue;
      }
      BDS_Point *p1 = (BDS_Point *)doc.points[doc.triangles[i].a].data;
      BDS_Point *p2 = (BDS_Point *)doc.points[doc.triangles[i].b].data;
      BDS_Point *p3 = (BDS_Point *)doc.points[doc.triangles[i].c].data;
      m->add_triangle(p1->iD, p2->iD, p3->iD);
    }
  }

  // Recover the boundary edges and compute characteristic lenghts using mesh
  // edge spacing
  BDS_GeomEntity CLASS_F(1, 2);
  BDS_GeomEntity CLASS_E(1, 1);
  BDS_GeomEntity CLASS_EXTERIOR(3, 2);

  if(debug) {
    char name[245];
    sprintf(name, "surface%d-initial-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-initial-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  bool _fatallyFailed;

  for(std::size_t i = 0; i < edgesEmbedded.size() / 2; i++) {
    BDS_Edge *e = m->recover_edge(edgesEmbedded[2 * i],
                                  edgesEmbedded[2 * i + 1], _fatallyFailed);
    if(!e) {
      Msg::Error("Impossible to recover the edge %d %d", edgesEmbedded[2 * i],
                 edgesEmbedded[2 * i + 1]);
      gf->meshStatistics.status = GFace::FAILED;
      delete m;
      return false;
    }
    else
      e->g = &CLASS_E;
  }

  std::set<EdgeToRecover> edgesNotRecovered;

  bool doItAgain = gf->meshStatistics.refineAllEdges;
  for(std::size_t i = 0; i < edgeLoops_BDS.size(); i++) {
    std::vector<BDS_Point *> &edgeLoop_BDS = edgeLoops_BDS[i];
    for(std::size_t j = 0; j < edgeLoop_BDS.size(); j++) {
      int num1 = edgeLoop_BDS[j]->iD;
      int num2 = edgeLoop_BDS[(j + 1) % edgeLoop_BDS.size()]->iD;
      BDS_Edge *e = m->find_edge(num1, num2);
      if(!e) {
        // printf("recovering %d %d\n",num1,num2);
        e = m->recover_edge(num1, num2, _fatallyFailed);
        BDS_Point *p1 = m->find_point(num1);
        BDS_Point *p2 = m->find_point(num2);
        MVertex *v1 = recoverMap[p1];
        MVertex *v2 = recoverMap[p2];
        GEdge *ge = getGEdge(gf, v1, v2);
        // if (!ge){
        //   Msg::Error("cannot find GEdge with mesh edge %d %d (%d %d)\n",
        //              num1, num2, v1->getNum(), v2->getNum());
        // }
        if(ge) edgesNotRecovered.insert(EdgeToRecover(num1, num2, ge));
        if(!e) {
          // what is before does not seem to work properly
          // Msg::Warning("ITER %d Impossible to recover the edge %d %d",
          //              RECUR_ITER, num1, num2);
          // Msg::Warning("Will split model edge  %d and try again", ge->tag());
          doItAgain = true;
          // gf->meshStatistics.status = GFace::FAILED;
          // delete m;
          // return false;
        }
        else {
          // Msg::Warning("ITER %d edge %d %d RECOVERED",RECUR_ITER, num1,num2);
          e->g = &CLASS_E;
        }
      }
      else
        e->g = &CLASS_E;
    }
  }

  if(doItAgain) {
    // this block is not thread safe. 2D mesh will be serialized for surfaces
    // that have their 1D mesh self-intersect
    if(Msg::GetNumThreads() != 1) {
      gf->meshStatistics.status = GFace::PENDING;
      delete m;
      Msg::Info("Surface %d has self-intersections in its 1D mesh: serializing "
                "this one",
                gf->tag());
      return true;
    }

    if(!gf->meshStatistics.refineAllEdges) {
      std::ostringstream sstream;
      for(std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
          itr != edgesNotRecovered.end(); ++itr)
        sstream
          << " " << itr->ge->tag() << "("
          << (itr->ge->getBeginVertex() ? itr->ge->getBeginVertex()->tag() : -1)
          << ","
          << (itr->ge->getEndVertex() ? itr->ge->getEndVertex()->tag() : -1)
          << ")";
      Msg::Info(":-( There are %d intersections in the 1D mesh (curves%s)",
                edgesNotRecovered.size(), sstream.str().c_str());
    }
    if(repairSelfIntersecting1dMesh) {
      Msg::Info("8-| Splitting those edges and trying again");
      if(gf->meshStatistics.refineAllEdges) {
        std::vector<GEdge *> eds = gf->edges();
        edgesNotRecovered.clear();
        for(size_t i = 0; i < eds.size(); i++) {
          const std::size_t NN = eds[i]->lines.size() ? 1 : 0;
          for(size_t j = 0; j < NN; j++) {
            MVertex *v1 = eds[i]->lines[j]->getVertex(0);
            MVertex *v2 = eds[i]->lines[j]->getVertex(1);
            std::multimap<MVertex *, BDS_Point *>::iterator itp1 =
              recoverMultiMapInv.lower_bound(v1);
            std::multimap<MVertex *, BDS_Point *>::iterator itp2 =
              recoverMultiMapInv.lower_bound(v2);
            if(itp1 != recoverMultiMapInv.end() &&
               itp2 != recoverMultiMapInv.end())
              edgesNotRecovered.insert(
                EdgeToRecover(itp1->second->iD, itp2->second->iD, eds[i]));
          }
        }
      }
      remeshUnrecoveredEdges(recoverMultiMapInv, edgesNotRecovered,
                             gf->meshStatistics.refineAllEdges);
      gf->meshStatistics.refineAllEdges = false;
    }
    // delete the mesh
    // getchar();
    if(debug) {
      char name[245];
      sprintf(name, "surface%d-initial-real-afterITER%d.pos", gf->tag(),
              RECUR_ITER);
      outputScalarField(m->triangles, name, 0, gf);
      sprintf(name, "surface%d-initial-param-afterITER%d.pos", gf->tag(),
              RECUR_ITER);
      outputScalarField(m->triangles, name, 1, gf);
    }
    delete m;
    if(RECUR_ITER < 10) {
      return meshGeneratorPeriodic(gf, RECUR_ITER + 1,
                                   repairSelfIntersecting1dMesh, debug);
    }
    return false;
  }

  if(RECUR_ITER > 0)
    Msg::Info(":-) All edges recovered after %d iteration%s", RECUR_ITER,
              (RECUR_ITER > 1) ? "s" : "");

  // look for a triangle that has a negative node and recursively tag all
  // exterior triangles
  {
    std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      (*itt)->g = 0;
      ++itt;
    }
    itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      BDS_Face *t = *itt;
      if(t->deleted) {
        // If triangle is deleted, it won't have the correct neighbours
        // to tag recursively
        ++itt;
        continue;
      }
      BDS_Point *n[4];
      t->getNodes(n);
      if(n[0]->iD < 0 || n[1]->iD < 0 || n[2]->iD < 0) {
        recur_tag(t, &CLASS_EXTERIOR);
        break;
      }
      ++itt;
    }
  }

  // now find an edge that has belongs to one of the exterior triangles
  {
    std::vector<BDS_Edge *>::const_iterator ite = m->edges.begin();
    while(ite != m->edges.end()) {
      BDS_Edge *edge = *ite;
      if(edge->g && edge->numfaces() == 2) {
        if(edge->faces(0)->g == &CLASS_EXTERIOR) {
          recur_tag(edge->faces(1), &CLASS_F);
          break;
        }
        else if(edge->faces(1)->g == &CLASS_EXTERIOR) {
          recur_tag(edge->faces(0), &CLASS_F);
          break;
        }
      }
      ++ite;
    }
    std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      if((*itt)->g == &CLASS_EXTERIOR) (*itt)->g = 0;
      ++itt;
    }
  }

  // delete useless stuff
  {
    std::vector<BDS_Face *>::iterator itt = m->triangles.begin();
    while(itt != m->triangles.end()) {
      BDS_Face *t = *itt;
      if(!t->g) { m->del_face(t); }
      ++itt;
    }
  }

  m->cleanup();

  {
    std::vector<BDS_Edge *>::const_iterator ite = m->edges.begin();
    while(ite != m->edges.end()) {
      BDS_Edge *edge = *ite;
      if(edge->numfaces() == 0)
        m->del_edge(edge);
      else {
        if(!edge->g) edge->g = &CLASS_F;
        if(!edge->p1->g ||
           edge->p1->g->classif_degree > edge->g->classif_degree)
          edge->p1->g = edge->g;
        if(!edge->p2->g ||
           edge->p2->g->classif_degree > edge->g->classif_degree)
          edge->p2->g = edge->g;
      }
      ++ite;
    }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  if(debug) {
    char name[245];
    sprintf(name, "surface%d-recovered-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-recovered-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  if(algoDelaunay2D(gf)){
    // Call this function to untangle elements in Cartesian space
    Msg::Debug("Delaunizing the initial mesh");
    int nb_swap;
    delaunayizeBDS(gf, *m, nb_swap);
  }
  else{
    modifyInitialMeshToRemoveDegeneracies(gf, *m, &recoverMap);

    Msg::Debug("Delaunizing the initial mesh");
    int nb_swap;
    delaunayizeBDS(gf, *m, nb_swap);

    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, true, NULL,
                  &recoverMap, &true_boundary);
    if(debug) {
      char name[245];
      sprintf(name, "surface%d-phase1-real.pos", gf->tag());
      outputScalarField(m->triangles, name, 0, gf);
      sprintf(name, "surface%d-phase1-param.pos", gf->tag());
      outputScalarField(m->triangles, name, 1, gf);
    }
    if(debug) {
      char name[245];
      sprintf(name, "surface%d-phase2-real.pos", gf->tag());
      outputScalarField(m->triangles, name, 0, gf);
      sprintf(name, "surface%d-phase2-param.pos", gf->tag());
      outputScalarField(m->triangles, name, 1, gf);
    }
    refineMeshBDS(gf, *m, -CTX::instance()->mesh.refineSteps, false, NULL,
                  &recoverMap, &true_boundary);
    if(debug) {
      char name[245];
      sprintf(name, "surface%d-phase3-real.pos", gf->tag());
      outputScalarField(m->triangles, name, 0);
      sprintf(name, "surface%d-phase3-param.pos", gf->tag());
      outputScalarField(m->triangles, name, 1, gf);
    }
    if(debug) {
      char name[245];
      sprintf(name, "surface%d-phase4-real.pos", gf->tag());
      outputScalarField(m->triangles, name, 0);
      sprintf(name, "surface%d-phase4-param.pos", gf->tag());
      outputScalarField(m->triangles, name, 1, gf);
    }

    if(gf->meshStatistics.status == GFace::FAILED) {
      // splitall
      gf->meshStatistics.status = GFace::PENDING;
      gf->meshStatistics.refineAllEdges = true;
      delete m;
      Msg::Info("Serializing surface %d and refining all its bounding edges",
                gf->tag());
      return true;
    }
    else {
      gf->meshStatistics.status = GFace::DONE;
    }

    if(debug) {
      char name[245];
      sprintf(name, "surface%d-just-real.pos", gf->tag());
      outputScalarField(m->triangles, name, 0, gf);
    }
  }

  // This is a structure that we need only for periodic cases. We will duplicate
  // the vertices (MVertex) that are on seams

  std::map<MVertex *, MVertex *> equivalence;
  std::map<MVertex *, SPoint2> parametricCoordinates;
  if(algoDelaunay2D(gf)) {
    std::map<MVertex *, BDS_Point *> invertMap;
    std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
      recoverMap.begin();
    while(it != recoverMap.end()) {
      // we have twice vertex MVertex with 2 different coordinates
      MVertex *mv1 = it->second;
      BDS_Point *bds = it->first;
      std::map<MVertex *, BDS_Point *>::iterator invIt = invertMap.find(mv1);
      if(invIt != invertMap.end()) {
        // create a new "fake" vertex that will be destroyed afterwards
        MVertex *mv2 = 0;
        if(mv1->onWhat()->dim() == 1) {
          double t;
          mv1->getParameter(0, t);
          mv2 = new MEdgeVertex(mv1->x(), mv1->y(), mv1->z(), mv1->onWhat(), t,
                                0, ((MEdgeVertex *)mv1)->getLc());
        }
        else if(mv1->onWhat()->dim() == 0) {
          mv2 = new MVertex(mv1->x(), mv1->y(), mv1->z(), mv1->onWhat());
        }
        else
          Msg::Error("Could not reconstruct seam");
        if(mv2) {
          it->second = mv2;
          equivalence[mv2] = mv1;
          parametricCoordinates[mv2] = SPoint2(bds->u, bds->v);
          invertMap[mv2] = bds;
        }
      }
      else {
        parametricCoordinates[mv1] = SPoint2(bds->u, bds->v);
        invertMap[mv1] = bds;
      }
      ++it;
    }
    // recoverMap.insert(new_relations.begin(), new_relations.end());
  }

  // Msg::Info("%d points that are duplicated for Delaunay meshing",
  //           equivalence.size());

  // fill the small gmsh structures
  BDS2GMSH(m, gf, recoverMap);

  if(debug) {
    char name[245];
    sprintf(name, "surface%d-final-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-final-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  bool infty = false;
  if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD) {
    infty = true;
    buildBackgroundMesh(gf, CTX::instance()->mesh.crossFieldClosestPoint,
                        &equivalence, &parametricCoordinates);
  }
  else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
          gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR) {
    infty = true;
    buildBackgroundMesh(gf, false, &equivalence, &parametricCoordinates);
  }

  // boundary layer
  std::vector<MQuadrangle *> blQuads;
  std::vector<MTriangle *> blTris;
  std::set<MVertex *> verts;
  modifyInitialMeshForBoundaryLayers(gf, blQuads, blTris, verts, debug);
  gf->quadrangles.insert(gf->quadrangles.begin(), blQuads.begin(),
                         blQuads.end());
  gf->triangles.insert(gf->triangles.begin(), blTris.begin(), blTris.end());
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(), verts.begin(),
                           verts.end());

  if(algoDelaunay2D(gf)) {
    if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL)
      bowyerWatsonFrontal(gf, &equivalence, &parametricCoordinates,
                          &true_boundary);
    else if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD)
      bowyerWatsonFrontalLayers(gf, true, &equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS)
      bowyerWatsonParallelograms(gf, &equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR)
      bowyerWatsonParallelogramsConstrained(
        gf, gf->constr_vertices, &equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_DELAUNAY ||
            gf->getMeshingAlgo() == ALGO_2D_AUTO)
      bowyerWatson(gf, 1000000000, &equivalence, &parametricCoordinates);
    else
      meshGFaceBamg(gf);
    if(!infty ||
       !(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine))
      laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing, infty);
  }

  if(debug) {
    char name[256];
    sprintf(name, "real%d.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "param%d.pos", gf->tag());
    outputScalarField(m->triangles, name, 1, gf);
  }

  // delete the mesh
  delete m;

  if((CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine) &&
     CTX::instance()->mesh.algoRecombine <= 1) {
    bool blossom = (CTX::instance()->mesh.algoRecombine == 1);
    int topo = CTX::instance()->mesh.recombineOptimizeTopology;
    recombineIntoQuads(gf, blossom, topo, false, 0.1); // no node repositioning
  }

  computeElementShapes(gf, gf->meshStatistics.worst_element_shape,
                       gf->meshStatistics.average_element_shape,
                       gf->meshStatistics.best_element_shape,
                       gf->meshStatistics.nbTriangle,
                       gf->meshStatistics.nbGoodQuality);
  gf->meshStatistics.status = GFace::DONE;

  // remove unused vertices, generated e.g. during background mesh
  _deleteUnusedVertices(gf);

  return true;
}

void deMeshGFace::operator()(GFace *gf)
{
  if(gf->geomType() == GEntity::DiscreteSurface) {
    if(!static_cast<discreteFace *>(gf)->haveParametrization()) return;
  }
  gf->deleteMesh();
  gf->meshStatistics.status = GFace::PENDING;
  gf->meshStatistics.nbTriangle = gf->meshStatistics.nbEdge = 0;
  gf->correspondingVertices.clear();
  gf->correspondingHOPoints.clear();
}

static double TRIANGLE_VALIDITY(GFace *gf, MTriangle *t)
{
  SPoint2 p1, p2, p3;
  reparamMeshVertexOnFace(t->getVertex(0), gf, p1);
  reparamMeshVertexOnFace(t->getVertex(1), gf, p2);
  reparamMeshVertexOnFace(t->getVertex(2), gf, p3);
  SVector3 N1 = gf->normal(p1);
  SVector3 N2 = gf->normal(p2);
  SVector3 N3 = gf->normal(p3);
  SVector3 N = N1 + N2 + N3;
  N.normalize();
  SVector3 d1(t->getVertex(1)->x() - t->getVertex(0)->x(),
              t->getVertex(1)->y() - t->getVertex(0)->y(),
              t->getVertex(1)->z() - t->getVertex(0)->z());
  SVector3 d2(t->getVertex(2)->x() - t->getVertex(0)->x(),
              t->getVertex(2)->y() - t->getVertex(0)->y(),
              t->getVertex(2)->z() - t->getVertex(0)->z());
  SVector3 c = crossprod(d1, d2);
  return dot(N, c);
}

static bool isMeshValid(GFace *gf)
{
  size_t invalid = 0;
  for(size_t i = 0; i < gf->triangles.size(); i++) {
    double v = TRIANGLE_VALIDITY(gf, gf->triangles[i]);
    if(v < 0) invalid++;
  }
  if(invalid == 0 || invalid == gf->triangles.size()) return true;

  return false;
}

// for debugging, change value from -1 to -100;
int debugSurface = -1; //-100;

void meshGFace::operator()(GFace *gf, bool print)
{
  gf->model()->setCurrentMeshEntity(gf);

  if(gf->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) return;

  // destroy the mesh if it exists
  deMeshGFace dem;
  dem(gf);

  if(MeshTransfiniteSurface(gf)) return;
  if(MeshExtrudedSurface(gf)) return;
  if(gf->getMeshMaster() != gf) {
    GFace *gff = dynamic_cast<GFace *>(gf->getMeshMaster());
    if(gff) {
      if(gff->meshStatistics.status != GFace::DONE) {
        gf->meshStatistics.status = GFace::PENDING;
        return;
      }
      Msg::Info("Meshing surface %d (%s) as a copy of %d", gf->tag(),
                gf->getTypeString().c_str(), gf->getMeshMaster()->tag());
      copyMesh(gff, gf);
      gf->meshStatistics.status = GFace::DONE;
      return;
    }
    else
      Msg::Warning("Unknown mesh master surface %d",
                   gf->getMeshMaster()->tag());
  }

  const char *algo = "Unknown";

  switch(gf->getMeshingAlgo()) {
  case ALGO_2D_MESHADAPT: algo = "MeshAdapt"; break;
  case ALGO_2D_FRONTAL: algo = "Frontal"; break;
  case ALGO_2D_FRONTAL_QUAD: algo = "Frontal Quad"; break;
  case ALGO_2D_DELAUNAY: algo = "Delaunay"; break;
  case ALGO_2D_BAMG: algo = "Bamg"; break;
  case ALGO_2D_PACK_PRLGRMS: algo = "Square Packing"; break;
  case ALGO_2D_AUTO:
    algo = (gf->geomType() == GEntity::Plane) ? "Delaunay" : "MeshAdapt";
    break;
  }
  if(!algoDelaunay2D(gf)) { algo = "MeshAdapt"; }

  if(print)
    Msg::Info("Meshing surface %d (%s, %s)", gf->tag(),
              gf->getTypeString().c_str(), algo);

  bool singularEdges = false;
  std::vector<GEdge *>::const_iterator ite = gf->edges().begin();
  while(ite != gf->edges().end()) {
    if((*ite)->isSeam(gf)) singularEdges = true;
    ite++;
  }

  bool periodic = (gf->getNativeType() != GEntity::GmshModel) &&
                  (gf->periodic(0) || gf->periodic(1) || singularEdges);

  quadMeshRemoveHalfOfOneDMesh halfmesh(gf, periodic);

  if(periodic) {
    if(!meshGeneratorPeriodic(gf, 0, repairSelfIntersecting1dMesh,
                              debugSurface >= 0 || debugSurface == -100)) {
      Msg::Error("Impossible to mesh periodic surface %d", gf->tag());
      gf->meshStatistics.status = GFace::FAILED;
    }
  }
  else {
    meshGenerator(gf, 0, repairSelfIntersecting1dMesh, onlyInitialMesh,
                  debugSurface >= 0 || debugSurface == -100);
  }

  Msg::Debug("Type %d %d triangles generated, %d internal vertices",
             gf->geomType(), gf->triangles.size(), gf->mesh_vertices.size());

  halfmesh.finish();

  if(gf->getNumMeshElements() == 0 &&
     gf->meshStatistics.status == GFace::DONE) {
    Msg::Warning("Surface %d consists of no elements", gf->tag());
  }

  // test validity for non-Gmsh models (currently we cannot reliably evaluate
  // the normal on the boundary of surfaces with the Gmsh kernel)
  if(gf->getNativeType() != GEntity::GmshModel && algoDelaunay2D(gf) &&
     !isMeshValid(gf)) {
    Msg::Debug(
      "Delaunay-based mesher failed on surface %d -> moving to MeshAdapt",
      gf->tag());
    deMeshGFace killer;
    killer(gf);
    gf->setMeshingAlgo(1);
    (*this)(gf, print);
    gf->unsetMeshingAlgo();
  }
}

static bool getGFaceNormalFromVert(GFace *gf, MElement *el, SVector3 &nf)
{
  // TODO C++11 use std::find_if
  bool found = false;
  for(std::size_t iElV = 0; iElV < el->getNumVertices(); iElV++) {
    MVertex *v = el->getVertex(iElV);
    SPoint2 param;
    if(v->onWhat() == gf && v->getParameter(0, param[0]) &&
       v->getParameter(1, param[1])) {
      nf = gf->normal(param);
      found = true;
      break;
    }
  }
  return found;
}

static bool getGFaceNormalFromBary(GFace *gf, MElement *el, SVector3 &nf)
{
  SPoint2 param(0., 0.);
  bool ok = true;
  for(std::size_t j = 0; j < el->getNumVertices(); j++) {
    SPoint2 p;
    // FIXME: use inexact reparam because some vertices might not be exactly on
    // the surface after the 3D Delaunay
    ok = reparamMeshVertexOnFace(el->getVertex(j), gf, p, false);
    if(!ok) break;
    param += p;
  }
  if(ok) {
    param *= 1.0 / el->getNumVertices();
    nf = gf->normal(param);
  }
  return ok;
}

static void getGFaceOrientation(GFace *gf, BoundaryLayerColumns *blc,
                                bool existBL, bool fromVert, int &orientNonBL,
                                int &orientBL)
{
  for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
    MElement *e = gf->getMeshElement(iEl);
    const bool isBLEl =
      existBL && (blc->_toFirst.find(e) != blc->_toFirst.end());
    SVector3 nf;
    // Check only if orientation of BL/non-BL el. not already known
    if((!isBLEl && orientNonBL == 0) || (isBLEl && orientBL == 0)) {
      const bool found = fromVert ? getGFaceNormalFromVert(gf, e, nf) :
                                    getGFaceNormalFromBary(gf, e, nf);
      if(found) {
        SVector3 ne = e->getFace(0).normal();
        const int orient = (dot(ne, nf) > 0.) ? 1 : -1;
        if(isBLEl)
          orientBL = orient;
        else
          orientNonBL = orient;
      }
    }
    // Stop when orientation found for non-BL and BL el.
    if((orientNonBL != 0) && (orientBL != 0)) break;
  }
}

void orientMeshGFace::operator()(GFace *gf)
{
  if(!gf->getNumMeshElements()) return;

  gf->model()->setCurrentMeshEntity(gf);

  if(gf->geomType() == GEntity::DiscreteSurface ||
     gf->geomType() == GEntity::BoundaryLayerSurface) {
    // don't do anything
  }
  else {
    // In old versions we checked the orientation by comparing the orientation
    // of a line element on the boundary w.r.t. its connected surface
    // element. This is probably better than what follows, but
    // * it failed when the 3D Delaunay changes the 1D mesh (since we don't
    //    recover it yet)
    // * it failed with OpenCASCADE geometries, where surface orientions do not
    //   seem to be consistent with the orientation of the bounding edges

    // Now: orient surface elements w.r.t. normal to geometric model.
    // Assumes that originally, orientation is consistent among boundary layer
    // (BL) elements, and orientation is consistent among non-BL elements, but
    // BL and non-BL elements can be oriented differently

    // Determine whether there is a boundary layer (BL)
    BoundaryLayerColumns *blc = gf->getColumns();
    const bool existBL = !blc->_toFirst.empty();

    // Get orientation of BL and non-BL elements.
    // First, try to get normal to GFace from vertices.
    // If it fails, try to get normal to GFace from element barycenter
    int orientNonBL = 0, orientBL = existBL ? 0 : 1;
    getGFaceOrientation(gf, blc, existBL, true, orientNonBL, orientBL);
    if((orientNonBL == 0) || (orientBL == 0))
      getGFaceOrientation(gf, blc, existBL, false, orientNonBL, orientBL);

    // Exit if could not determine orientation of both non-BL el. and BL el.
    if((orientNonBL == 0) && (orientBL == 0)) {
      Msg::Warning("Could not orient mesh in surface %d", gf->tag());
      return;
    }

    // Reverse BL and non-BL elements if needed
    if(existBL) { // If there is a BL, test BL/non-BL elements
      if((orientNonBL == -1) || (orientBL == -1)) {
        for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
          MElement *e = gf->getMeshElement(iEl);
          // If el. outside of BL...
          if(blc->_toFirst.find(e) == blc->_toFirst.end()) {
            // ... reverse if needed
            if(orientNonBL == -1) e->reverse();
          }
          else { // If el. in BL ... reverse if needed
            if(orientBL == -1) e->reverse();
          }
        }
      }
    }
    else { // If no BL, reverse all elements if needed
      if(orientNonBL == -1) {
        for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++)
          gf->getMeshElement(iEl)->reverse();
      }
    }
  }

  // Apply user-specified mesh orientation constraints
  if(gf->meshAttributes.reverseMesh) {
    for(std::size_t k = 0; k < gf->getNumMeshElements(); k++)
      gf->getMeshElement(k)->reverse();
  }
}
