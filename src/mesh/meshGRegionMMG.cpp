// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Algiane Froehly
//

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegionMMG.h"

#if defined(HAVE_MMG)

#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <vector>
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "BackgroundMeshTools.h"
#include "Context.h"
#include "meshGRegionDelaunay.h"

extern "C" {
#include <mmg/libmmg.h>
}

static void MMG2gmsh(GRegion *gr, MMG5_pMesh mmg,
                     std::map<int, MVertex *> &mmg2gmsh)
{
  std::map<int, MVertex *> kToMVertex;
  int np, ne, nt, na, ref;
  double cx, cy, cz;

  if(MMG3D_Get_meshSize(mmg, &np, &ne, nullptr, &nt, nullptr, &na) != 1)
    Msg::Error("Mmg3d: unable to get mesh size");

  // Store the nodes from the Mmg structures into the gmsh structures

  // TODO: when MMG is allowed to modify the surface mesh, reclassify nodes
  // accordingly
  for(int k = 1; k <= np; k++) {
    if(MMG3D_Get_vertex(mmg, &cx, &cy, &cz, &ref, nullptr, nullptr) != 1)
      Msg::Error("Mmg3d: unable to get vertex %d", k);

    auto it = mmg2gmsh.find(ref);

    if(it == mmg2gmsh.end()) {
      MVertex *v = new MVertex(cx, cy, cz, gr);
      gr->mesh_vertices.push_back(v);
      kToMVertex[k] = v;
    }
    else
      kToMVertex[k] = it->second;
  }

  // Store the tets from the Mmg structures into the Gmsh structures
  for(int k = 1; k <= ne; k++) {
    int v1mmg, v2mmg, v3mmg, v4mmg;
    if(MMG3D_Get_tetrahedron(mmg, &v1mmg, &v2mmg, &v3mmg, &v4mmg, &ref,
                             nullptr) != 1)
      Msg::Error("Mmg3d: unable to get tetrahedron %d", k);

    MVertex *v1 = kToMVertex[v1mmg];
    MVertex *v2 = kToMVertex[v2mmg];
    MVertex *v3 = kToMVertex[v3mmg];
    MVertex *v4 = kToMVertex[v4mmg];
    if(!v1 || !v2 || !v3 || !v4) {
      Msg::Error("Mmg3d: unknown vertex in tetrahedron %d", k);
    }
    else {
      gr->tetrahedra.push_back(new MTetrahedron(v1, v2, v3, v4));
    }
  }

#if 0
  // Store the triangles from the Mmg structures into the Gmsh structures

  // TODO: allow MMG to remesh (some of the) input surfaces; then store the new
  // mesh
  for(int k = 1; k <= nt; k++) {
    int v1mmg, v2mmg, v3mmg;
    if(MMG3D_Get_triangle(mmg, &v1mmg, &v2mmg, &v3mmg, &ref, nullptr) != 1)
      Msg::Error("Mmg3d: unable to get triangle %d", k);

    MVertex *v1 = kToMVertex[v1mmg];
    MVertex *v2 = kToMVertex[v2mmg];
    MVertex *v3 = kToMVertex[v3mmg];
    if(!v1 || !v2 || !v3) {
      Msg::Error("Mmg3d: unknown vertex in triangle %d", k);
    }
    else{
      // ...
    }
  }
#endif
}

static void gmsh2MMG(GRegion *gr, MMG5_pMesh mmg, MMG5_pSol sol,
                     std::map<int, MVertex *> &mmg2gmsh)
{
  // Count mesh vertices
  std::set<MVertex *> allVertices;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++) {
    allVertices.insert(gr->tetrahedra[i]->getVertex(0));
    allVertices.insert(gr->tetrahedra[i]->getVertex(1));
    allVertices.insert(gr->tetrahedra[i]->getVertex(2));
    allVertices.insert(gr->tetrahedra[i]->getVertex(3));
  }
  int np = allVertices.size();

  // Count boundary triangles
  std::vector<GFace *> f = gr->faces();
  int nt = 0;
  for(auto it = f.begin(); it != f.end(); ++it) {
    nt += (*it)->triangles.size();
  }

  // TODO: also import mesh lines

  // Get mesh tetrahedra
  int ne = gr->tetrahedra.size();

  if(MMG3D_Set_meshSize(mmg, np, ne, 0, nt, 0, 0) != 1)
    Msg::Error("Mmg3d: unable to set mesh size");

  if(MMG3D_Set_solSize(mmg, sol, MMG5_Vertex, np, MMG5_Tensor) != 1)
    Msg::Error("Mmg3d: unable to set metric size");

  std::map<MVertex *, std::pair<double, int> > LCS;
  for(auto it = f.begin(); it != f.end(); ++it) {
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      double L = t->maxEdge();
      for(int k = 0; k < 3; k++) {
        MVertex *v = t->getVertex(k);
        auto itv = LCS.find(v);
        if(itv != LCS.end()) {
          itv->second.first += L;
          itv->second.second++;
        }
        else {
          LCS[v] = std::make_pair(L, 1);
        }
      }
    }
  }

  int k = 1;
  std::map<int, int> gmsh2mmg_num;
  for(auto it = allVertices.begin(); it != allVertices.end(); ++it) {
    if(MMG3D_Set_vertex(mmg, (*it)->x(), (*it)->y(), (*it)->z(),
                        (*it)->getNum(), k) != 1)
      Msg::Error("Mmg3d: unable to set vertex %d", k);

    gmsh2mmg_num[(*it)->getNum()] = k;

    MVertex *v = *it;
    double U = 0, V = 0;
    if(!v->onWhat()) continue;

    if(v->onWhat()->dim() == 1) { v->getParameter(0, U); }
    else if(v->onWhat()->dim() == 2) {
      v->getParameter(0, U);
      v->getParameter(1, V);
    }

    // double lc = BGM_MeshSize(v->onWhat(), U, V, v->x(), v->y(), v->z());
    SMetric3 m = BGM_MeshMetric(v->onWhat(), U, V, v->x(), v->y(), v->z());

    auto itv = LCS.find(v);
    if(itv != LCS.end()) {
      mmg2gmsh[(*it)->getNum()] = *it;
      // if (Extend2dMeshIn3dVolumes()){
      double LL = itv->second.first / itv->second.second;
      SMetric3 l4(1. / (LL * LL));
      SMetric3 MM = intersection_conserve_mostaniso(l4, m);
      m = MM;
      // lc = std::min(LL,lc);
      // }
    }

    if(MMG3D_Set_tensorSol(sol, m(0, 0), m(1, 0), m(2, 0), m(1, 1), m(2, 1),
                           m(2, 2), k) != 1) {
      Msg::Error("Mmg3d: unable to set solution %d", k);
    }
    k++;
  }

  for(k = 1; k <= ne; k++) {
    if(MMG3D_Set_tetrahedron(
         mmg, gmsh2mmg_num[gr->tetrahedra[k - 1]->getVertex(0)->getNum()],
         gmsh2mmg_num[gr->tetrahedra[k - 1]->getVertex(1)->getNum()],
         gmsh2mmg_num[gr->tetrahedra[k - 1]->getVertex(2)->getNum()],
         gmsh2mmg_num[gr->tetrahedra[k - 1]->getVertex(3)->getNum()], gr->tag(),
         k) != 1)
      Msg::Error("Mmg3d: unable to set tetrahedron %d", k);
  }

  k = 1;
  for(auto it = f.begin(); it != f.end(); ++it) {
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++) {
      if(MMG3D_Set_triangle(
           mmg, gmsh2mmg_num[(*it)->triangles[i]->getVertex(0)->getNum()],
           gmsh2mmg_num[(*it)->triangles[i]->getVertex(1)->getNum()],
           gmsh2mmg_num[(*it)->triangles[i]->getVertex(2)->getNum()],
           (*it)->tag(), k) != 1)
        Msg::Error("Mmg3d: unable to set triangle %d", k);
      k++;
    }
  }
}

static void updateSizes(GRegion *gr, MMG5_pMesh mmg, MMG5_pSol sol,
                        std::map<int, MVertex *> &mmg2gmsh)
{
  std::vector<GFace *> f = gr->faces();

  std::map<MVertex *, std::pair<double, int> > LCS;
  // if (Extend2dMeshIn3dVolumes()){
  for(auto it = f.begin(); it != f.end(); ++it) {
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      double L = t->maxEdge();
      for(int k = 0; k < 3; k++) {
        MVertex *v = t->getVertex(k);
        auto itv = LCS.find(v);
        if(itv != LCS.end()) {
          itv->second.first += L;
          itv->second.second++;
        }
        else {
          LCS[v] = std::make_pair(L, 1);
        }
      }
    }
  }
  // }

  int np;

  MMG3D_Get_meshSize(mmg, &np, nullptr, nullptr, nullptr, nullptr, nullptr);
  for(int k = 1; k <= np; k++) {
    double cx, cy, cz;
    if(MMG3D_Get_vertex(mmg, &cx, &cy, &cz, nullptr, nullptr, nullptr) != 1)
      Msg::Error("Mmg3d: unable to get vertex %d", k);

    SMetric3 m = BGM_MeshMetric(gr, 0, 0, cx, cy, cz);

    auto it = mmg2gmsh.find(k);

    if(it != mmg2gmsh.end() && Extend2dMeshIn3dVolumes()) {
      auto itv = LCS.find(it->second);
      if(itv != LCS.end()) {
        double LL = itv->second.first / itv->second.second;
        SMetric3 l4(1. / (LL * LL));
        // printf("adding a size %g\n",LL);
        SMetric3 MM = intersection_conserve_mostaniso(l4, m);
        m = MM;
      }
    }
    if(m.determinant() < 1.e-30) {
      m(0, 0) += 1.e-12;
      m(1, 1) += 1.e-12;
      m(2, 2) += 1.e-12;
    }

    if(MMG3D_Set_tensorSol(sol, m(0, 0), m(1, 0), m(2, 0), m(1, 1), m(2, 1),
                           m(2, 2), k) != 1)
      Msg::Error("Mmg3d: unable to set solution %d", k);
  }
}

void refineMeshMMG(GRegion *gr)
{
  MMG5_pMesh mmg = nullptr;
  MMG5_pSol sol = nullptr;

  std::map<int, MVertex *> mmg2gmsh;

  // Mmg structures allocations
  MMG3D_Init_mesh(MMG5_ARG_start, MMG5_ARG_ppMesh, &mmg, MMG5_ARG_ppMet, &sol,
                  MMG5_ARG_end);

  // Store the Gmsh mesh into the Mmg structures
  gmsh2MMG(gr, mmg, sol, mmg2gmsh);

  int iterMax = 10;

// #define DEBUG
#ifdef DEBUG
  char test0[] = "init.mesh";
  MMG3D_saveMesh(mmg, test0);
  MMG3D_saveSol(mmg, sol, test0);
#endif

  for(int ITER = 0; ITER < iterMax; ITER++) {
    int nT, nTnow, np;

    MMG3D_Get_meshSize(mmg, nullptr, &nT, nullptr, nullptr, nullptr, nullptr);

    // Mmg parameters : verbosity + nosurf option
    int verb_mmg = (Msg::GetVerbosity() < 2) ? -1 : Msg::GetVerbosity() - 4;
    if(MMG3D_Set_iparameter(mmg, sol, MMG3D_IPARAM_verbose, verb_mmg) != 1)
      Msg::Error("Mmsg3d: unable to set verbosity");

    // Set the nosurf parameter to 1 to preserve the boundaries
    if(MMG3D_Set_iparameter(mmg, sol, MMG3D_IPARAM_nosurf, 1) != 1)
      Msg::Error("Mmg3d: unable to preserve the boundaries");

    // Set the hausdorff parameter
    double sqrt3Inv = 0.57735026919;
    double hausd = 0.01 * sqrt3Inv * gr->bounds().diag();

    if(MMG3D_Set_dparameter(mmg, sol, MMG3D_DPARAM_hausd, hausd) != 1) {
      Msg::Error("Mmg3d: unable to set the hausdorff parameter");
    }

    if(MMG3D_mmg3dlib(mmg, sol) != MMG5_SUCCESS) {
      Msg::Error("Mmg3d: failed (iteration %d)", ITER);
    }
    else {
      MMG3D_Get_meshSize(mmg, &np, &nTnow, nullptr, nullptr, nullptr, nullptr);
      Msg::Info("Mmg3d: success (iteration %d) - %d nodes %d tetrahedra", ITER,
                np, nTnow);

      // Here we should interact with BGM
      updateSizes(gr, mmg, sol, mmg2gmsh);

      if(fabs((double)(nTnow - nT)) < 0.05 * nT) break;
    }
  }

#ifdef DEBUG
  char test[] = "end.mesh";
  MMG3D_saveMesh(mmg, test);
  MMG3D_saveSol(mmg, sol, test);
#endif

  gr->deleteVertexArrays();
  for(unsigned int i = 0; i < gr->tetrahedra.size(); ++i)
    delete gr->tetrahedra[i];
  gr->tetrahedra.clear();
  for(unsigned int i = 0; i < gr->mesh_vertices.size(); ++i)
    delete gr->mesh_vertices[i];
  gr->mesh_vertices.clear();

  // Store the Mmg mesh into the Gmsh structures
  MMG2gmsh(gr, mmg, mmg2gmsh);

  // Free the Mmg structure
  MMG3D_Free_all(MMG5_ARG_start, MMG5_ARG_ppMesh, &mmg, MMG5_ARG_ppMet, &sol,
                 MMG5_ARG_end);
}

static void MMG2gmshGroup(std::vector<GRegion *> &regions, MMG5_pMesh mmg,
                          std::map<int, MVertex *> &mmg2gmsh)
{
  int np, ne, nt, na;

  if(MMG3D_Get_meshSize(mmg, &np, &ne, nullptr, &nt, nullptr, &na) != 1)
    Msg::Error("Mmg3d: unable to get mesh size");

  std::map<int, GRegion *> tagToRegion;
  for(GRegion *gr : regions) tagToRegion[gr->tag()] = gr;

  // Read back all vertex coordinates first. Vertex creation is deferred to
  // the tetrahedron loop below: unlike tetrahedra/triangles, Mmg vertex refs
  // here are the *original gmsh vertex numbers* (set in gmsh2MMGGroup), not
  // a region tag, so a newly-inserted interior point's owning region can
  // only be determined from the region-tagged tetrahedron that first uses
  // it (same approach as Hxt2Gmsh in meshGRegionHxt.cpp).
  std::vector<double> vx(np + 1), vy(np + 1), vz(np + 1);
  std::vector<int> vref(np + 1);
  for(int k = 1; k <= np; k++) {
    double cx, cy, cz;
    int ref;
    if(MMG3D_Get_vertex(mmg, &cx, &cy, &cz, &ref, nullptr, nullptr) != 1) {
      Msg::Error("Mmg3d: unable to get vertex %d", k);
      continue;
    }
    vx[k] = cx;
    vy[k] = cy;
    vz[k] = cz;
    vref[k] = ref;
  }

  std::map<int, MVertex *> kToMVertex;
  for(int k = 1; k <= np; k++) {
    auto it = mmg2gmsh.find(vref[k]);
    if(it != mmg2gmsh.end()) kToMVertex[k] = it->second;
  }

  // Mmg can overwrite a boundary vertex's smuggled ref (the original gmsh
  // vertex number) with the region reference of an adjacent tetrahedron,
  // for points sitting on an internal multi-material interface -- even
  // though their position is preserved exactly. Fall back to matching by
  // coordinate for anything the ref-based lookup above missed.
  std::map<std::array<double, 3>, MVertex *> coordToGmsh;
  for(auto &p : mmg2gmsh)
    coordToGmsh[{p.second->x(), p.second->y(), p.second->z()}] = p.second;
  for(int k = 1; k <= np; k++) {
    if(kToMVertex.count(k)) continue;
    auto cit = coordToGmsh.find({vx[k], vy[k], vz[k]});
    if(cit != coordToGmsh.end()) kToMVertex[k] = cit->second;
  }

  // A vertex not recognized above as an existing boundary/interface vertex
  // gets created fresh, attached to whichever region's tetrahedron uses it
  // first below -- correct for a genuine new interior point, but Mmg can
  // also return tetrahedra on both sides of an internal multi-material
  // interface that all reference the very same (unrecognized) point index,
  // for reasons not fully understood (observed even with every boundary
  // triangle/vertex explicitly marked required in Mmg, and even though Mmg
  // never allocates a new point there -- see the investigation notes on
  // fix/mmg3d-multidomain). Track which regions end up claiming each
  // region-classified vertex so such cases can be repaired below.
  std::map<MVertex *, std::set<GRegion *>> multiRegionVertices;

  for(int k = 1; k <= ne; k++) {
    int v1mmg, v2mmg, v3mmg, v4mmg, ref;
    if(MMG3D_Get_tetrahedron(mmg, &v1mmg, &v2mmg, &v3mmg, &v4mmg, &ref,
                             nullptr) != 1) {
      Msg::Error("Mmg3d: unable to get tetrahedron %d", k);
      continue;
    }

    auto rit = tagToRegion.find(ref);
    if(rit == tagToRegion.end()) {
      Msg::Error("Mmg3d: unknown region reference %d for tetrahedron %d", ref,
                 k);
      continue;
    }
    GRegion *gr = rit->second;

    int vmmg[4] = {v1mmg, v2mmg, v3mmg, v4mmg};
    bool valid = true;
    for(int j = 0; j < 4; j++) {
      if(vmmg[j] < 1 || vmmg[j] > np) {
        Msg::Error("Mmg3d: invalid vertex index %d in tetrahedron %d",
                   vmmg[j], k);
        valid = false;
        break;
      }
    }
    if(!valid) continue;

    MVertex *v[4];
    for(int j = 0; j < 4; j++) {
      auto vit = kToMVertex.find(vmmg[j]);
      if(vit != kToMVertex.end()) {
        v[j] = vit->second;
      }
      else {
        MVertex *nv = new MVertex(vx[vmmg[j]], vy[vmmg[j]], vz[vmmg[j]], gr);
        gr->mesh_vertices.push_back(nv);
        kToMVertex[vmmg[j]] = nv;
        v[j] = nv;
      }
      // Vertices matched above are boundary vertices (dim 2) unless they
      // were themselves created earlier in this same loop as a new,
      // region-classified point (dim 3): only the latter can be a
      // multi-region sharing case, an already-correct boundary vertex used
      // by both regions' tetrahedra is normal and not touched here.
      if(v[j]->onWhat() && v[j]->onWhat()->dim() == 3)
        multiRegionVertices[v[j]].insert(gr);
    }
    gr->tetrahedra.push_back(new MTetrahedron(v[0], v[1], v[2], v[3]));
  }

  for(auto &pr : multiRegionVertices) {
    MVertex *v = pr.first;
    std::set<GRegion *> &claimants = pr.second;
    if(claimants.size() < 2) continue;
    if(claimants.size() != 2) {
      Msg::Warning("Mesh vertex %lu was claimed by %zu regions in the "
                   "combined MMG3D write-back; leaving it as is",
                   v->getNum(), claimants.size());
      continue;
    }
    auto cit = claimants.begin();
    GRegion *r1 = *cit++;
    GRegion *r2 = *cit;
    GFace *shared = getSharedFace(r1, r2);
    if(!shared) {
      Msg::Warning("Mesh vertex %lu is shared between regions %d and %d "
                   "with no common surface; leaving it classified on a "
                   "region",
                   v->getNum(), r1->tag(), r2->tag());
      continue;
    }
    if(!insertVertexInFaceTriangulation(shared, v)) {
      Msg::Warning("Could not locate a triangle of surface %d containing "
                   "mesh vertex %lu; leaving it classified on a region",
                   shared->tag(), v->getNum());
      continue;
    }
    GEntity *currentGe = v->onWhat();
    if(currentGe) {
      std::vector<MVertex *> &curMV = currentGe->mesh_vertices;
      curMV.erase(std::remove(curMV.begin(), curMV.end(), v), curMV.end());
    }
    shared->addMeshVertex(v);
    v->setEntity(shared);
  }
}

static void gmsh2MMGGroup(std::vector<GRegion *> &regions,
                          std::vector<GFace *> &allFaces, MMG5_pMesh mmg,
                          MMG5_pSol sol, std::map<int, MVertex *> &mmg2gmsh)
{
  // Count mesh vertices across every region of the group
  std::set<MVertex *> allVertices;
  for(GRegion *gr : regions) {
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
      allVertices.insert(gr->tetrahedra[i]->getVertex(0));
      allVertices.insert(gr->tetrahedra[i]->getVertex(1));
      allVertices.insert(gr->tetrahedra[i]->getVertex(2));
      allVertices.insert(gr->tetrahedra[i]->getVertex(3));
    }
  }
  int np = allVertices.size();

  // Boundary triangles, including any interface shared between two regions
  // of the group, counted once (allFaces is already deduplicated)
  int nt = 0;
  for(GFace *gf : allFaces) nt += gf->triangles.size();

  int ne = 0;
  for(GRegion *gr : regions) ne += gr->tetrahedra.size();

  if(MMG3D_Set_meshSize(mmg, np, ne, 0, nt, 0, 0) != 1)
    Msg::Error("Mmg3d: unable to set mesh size");

  if(MMG3D_Set_solSize(mmg, sol, MMG5_Vertex, np, MMG5_Tensor) != 1)
    Msg::Error("Mmg3d: unable to set metric size");

  std::map<MVertex *, std::pair<double, int>> LCS;
  for(GFace *gf : allFaces) {
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      double L = t->maxEdge();
      for(int k = 0; k < 3; k++) {
        MVertex *v = t->getVertex(k);
        auto itv = LCS.find(v);
        if(itv != LCS.end()) {
          itv->second.first += L;
          itv->second.second++;
        }
        else {
          LCS[v] = std::make_pair(L, 1);
        }
      }
    }
  }

  int k = 1;
  std::map<int, int> gmsh2mmg_num;
  for(auto it = allVertices.begin(); it != allVertices.end(); ++it) {
    if(MMG3D_Set_vertex(mmg, (*it)->x(), (*it)->y(), (*it)->z(),
                        (*it)->getNum(), k) != 1)
      Msg::Error("Mmg3d: unable to set vertex %d", k);

    gmsh2mmg_num[(*it)->getNum()] = k;

    MVertex *v = *it;
    if(v->onWhat()) {
      double U = 0, V = 0;
      if(v->onWhat()->dim() == 1) { v->getParameter(0, U); }
      else if(v->onWhat()->dim() == 2) {
        v->getParameter(0, U);
        v->getParameter(1, V);
      }

      SMetric3 m = BGM_MeshMetric(v->onWhat(), U, V, v->x(), v->y(), v->z());

      auto itv = LCS.find(v);
      if(itv != LCS.end()) {
        mmg2gmsh[(*it)->getNum()] = *it;
        double LL = itv->second.first / itv->second.second;
        SMetric3 l4(1. / (LL * LL));
        SMetric3 MM = intersection_conserve_mostaniso(l4, m);
        m = MM;
      }

      if(MMG3D_Set_tensorSol(sol, m(0, 0), m(1, 0), m(2, 0), m(1, 1), m(2, 1),
                             m(2, 2), k) != 1) {
        Msg::Error("Mmg3d: unable to set solution %d", k);
      }
    }
    k++;
  }

  k = 1;
  for(GRegion *gr : regions) {
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
      MTetrahedron *t = gr->tetrahedra[i];
      if(MMG3D_Set_tetrahedron(mmg, gmsh2mmg_num[t->getVertex(0)->getNum()],
                               gmsh2mmg_num[t->getVertex(1)->getNum()],
                               gmsh2mmg_num[t->getVertex(2)->getNum()],
                               gmsh2mmg_num[t->getVertex(3)->getNum()],
                               gr->tag(), k) != 1)
        Msg::Error("Mmg3d: unable to set tetrahedron %d", k);
      k++;
    }
  }

  k = 1;
  for(GFace *gf : allFaces) {
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      if(MMG3D_Set_triangle(
           mmg, gmsh2mmg_num[gf->triangles[i]->getVertex(0)->getNum()],
           gmsh2mmg_num[gf->triangles[i]->getVertex(1)->getNum()],
           gmsh2mmg_num[gf->triangles[i]->getVertex(2)->getNum()], gf->tag(),
           k) != 1)
        Msg::Error("Mmg3d: unable to set triangle %d", k);
      k++;
    }
  }
}

static void updateSizesGroup(std::vector<GRegion *> &regions,
                             std::vector<GFace *> &allFaces, MMG5_pMesh mmg,
                             MMG5_pSol sol, std::map<int, MVertex *> &mmg2gmsh)
{
  std::map<MVertex *, std::pair<double, int>> LCS;
  for(GFace *gf : allFaces) {
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      double L = t->maxEdge();
      for(int k = 0; k < 3; k++) {
        MVertex *v = t->getVertex(k);
        auto itv = LCS.find(v);
        if(itv != LCS.end()) {
          itv->second.first += L;
          itv->second.second++;
        }
        else {
          LCS[v] = std::make_pair(L, 1);
        }
      }
    }
  }

  int np;

  MMG3D_Get_meshSize(mmg, &np, nullptr, nullptr, nullptr, nullptr, nullptr);
  for(int k = 1; k <= np; k++) {
    double cx, cy, cz;
    if(MMG3D_Get_vertex(mmg, &cx, &cy, &cz, nullptr, nullptr, nullptr) != 1)
      Msg::Error("Mmg3d: unable to get vertex %d", k);

    // There is no cheap way, mid-iteration, to know which of the group's
    // regions a newly-inserted interior point falls into (see
    // MMG2gmshGroup): query the background field through the first region
    // of the group. This only matters for a field restricted to a subset of
    // the group's regions (e.g. the "Restrict" field), which does not
    // preserve anisotropy correctly yet regardless of this combined-call
    // path.
    SMetric3 m = BGM_MeshMetric(regions[0], 0, 0, cx, cy, cz);

    auto it = mmg2gmsh.find(k);

    if(it != mmg2gmsh.end() && Extend2dMeshIn3dVolumes()) {
      auto itv = LCS.find(it->second);
      if(itv != LCS.end()) {
        double LL = itv->second.first / itv->second.second;
        SMetric3 l4(1. / (LL * LL));
        SMetric3 MM = intersection_conserve_mostaniso(l4, m);
        m = MM;
      }
    }
    if(m.determinant() < 1.e-30) {
      m(0, 0) += 1.e-12;
      m(1, 1) += 1.e-12;
      m(2, 2) += 1.e-12;
    }

    if(MMG3D_Set_tensorSol(sol, m(0, 0), m(1, 0), m(2, 0), m(1, 1), m(2, 1),
                           m(2, 2), k) != 1)
      Msg::Error("Mmg3d: unable to set solution %d", k);
  }
}

void refineMeshMMGGroup(std::vector<GRegion *> &regions,
                        std::vector<GFace *> &allFaces)
{
  MMG5_pMesh mmg = nullptr;
  MMG5_pSol sol = nullptr;

  std::map<int, MVertex *> mmg2gmsh;

  // Mmg structures allocations
  MMG3D_Init_mesh(MMG5_ARG_start, MMG5_ARG_ppMesh, &mmg, MMG5_ARG_ppMet, &sol,
                  MMG5_ARG_end);

  // Store the whole group's Gmsh mesh into the Mmg structures
  gmsh2MMGGroup(regions, allFaces, mmg, sol, mmg2gmsh);

  int iterMax = 10;

  for(int ITER = 0; ITER < iterMax; ITER++) {
    int nT, nTnow, np;

    MMG3D_Get_meshSize(mmg, nullptr, &nT, nullptr, nullptr, nullptr, nullptr);

    int verb_mmg = (Msg::GetVerbosity() < 2) ? -1 : Msg::GetVerbosity() - 4;
    if(MMG3D_Set_iparameter(mmg, sol, MMG3D_IPARAM_verbose, verb_mmg) != 1)
      Msg::Error("Mmsg3d: unable to set verbosity");

    // Set the nosurf parameter to 1 to preserve the boundaries, including
    // the interface(s) shared between regions of the group
    if(MMG3D_Set_iparameter(mmg, sol, MMG3D_IPARAM_nosurf, 1) != 1)
      Msg::Error("Mmg3d: unable to preserve the boundaries");

    double sqrt3Inv = 0.57735026919;
    SBoundingBox3d bbox;
    for(GRegion *gr : regions) bbox += gr->bounds();
    double hausd = 0.01 * sqrt3Inv * bbox.diag();

    if(MMG3D_Set_dparameter(mmg, sol, MMG3D_DPARAM_hausd, hausd) != 1) {
      Msg::Error("Mmg3d: unable to set the hausdorff parameter");
    }

    if(MMG3D_mmg3dlib(mmg, sol) != MMG5_SUCCESS) {
      Msg::Error("Mmg3d: failed (iteration %d)", ITER);
    }
    else {
      MMG3D_Get_meshSize(mmg, &np, &nTnow, nullptr, nullptr, nullptr, nullptr);
      Msg::Info("Mmg3d: success (iteration %d) - %d nodes %d tetrahedra", ITER,
                np, nTnow);

      updateSizesGroup(regions, allFaces, mmg, sol, mmg2gmsh);

      if(fabs((double)(nTnow - nT)) < 0.05 * nT) break;
    }
  }

  for(GRegion *gr : regions) {
    gr->deleteVertexArrays();
    for(std::size_t i = 0; i < gr->tetrahedra.size(); ++i)
      delete gr->tetrahedra[i];
    gr->tetrahedra.clear();
    for(std::size_t i = 0; i < gr->mesh_vertices.size(); ++i)
      delete gr->mesh_vertices[i];
    gr->mesh_vertices.clear();
  }

  // Store the Mmg mesh into the Gmsh structures, demultiplexed by region
  MMG2gmshGroup(regions, mmg, mmg2gmsh);

  // Free the Mmg structure
  MMG3D_Free_all(MMG5_ARG_start, MMG5_ARG_ppMesh, &mmg, MMG5_ARG_ppMet, &sol,
                 MMG5_ARG_end);
}

#else

void refineMeshMMG(GRegion *gr)
{
  Msg::Warning("This version of Gmsh is not compiled with MMG support: "
               "skipping refinement");
}

void refineMeshMMGGroup(std::vector<GRegion *> &regions,
                        std::vector<GFace *> &allFaces)
{
  Msg::Warning("This version of Gmsh is not compiled with MMG support: "
               "skipping refinement");
}

#endif
