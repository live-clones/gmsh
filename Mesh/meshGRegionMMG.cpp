// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Algiane Froehly
//

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegionMMG.h"

#if defined(HAVE_MMG)

#include <set>
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "BackgroundMeshTools.h"
#include "Context.h"

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
      // if (CTX::instance()->mesh.lcExtendFromBoundary){
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
  // if (CTX::instance()->mesh.lcExtendFromBoundary){
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

    if(it != mmg2gmsh.end() && CTX::instance()->mesh.lcExtendFromBoundary) {
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

#else

void refineMeshMMG(GRegion *gr)
{
  Msg::Warning("This version of Gmsh is not compiled with MMG support: "
               "skipping refinement");
}

#endif
