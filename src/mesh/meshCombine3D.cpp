// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "GModel.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "meshGRegion.h"

static void buildUniqueFaces(GRegion *gr,
                             std::map<MFace, GRegion *, MFaceLessThan> &bnd)
{
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *e = gr->getMeshElement(i);
    for(int j = 0; j < e->getNumFaces(); j++) {
      MFace f = e->getFace(j);
      auto it = bnd.find(f);
      if(it == bnd.end())
        bnd[f] = gr;
      else
        bnd.erase(it);
    }
  }
}

#if defined(HAVE_HXT)

#include "hxt_combine_cpp_api.h"

static void createMeshStore(GRegion *gr, HXTCombine::MeshStore &ms,
                            std::map<MVertex *, uint32_t> &v2c,
                            std::vector<MVertex *> &c2v)
{
  for(auto t : gr->tetrahedra) {
    for(size_t i = 0; i < 4; i++) {
      MVertex *v = t->getVertex(i);
      if(v2c.find(v) == v2c.end()) {
        v2c[v] = c2v.size();
        c2v.push_back(v);
      }
    }
  }

  for(auto v : c2v) {
    ms.vertices.push_back(v->x());
    ms.vertices.push_back(v->y());
    ms.vertices.push_back(v->z());
    ms.vertices.push_back(0.0);
  }

  for(auto t : gr->tetrahedra) {
    for(size_t i = 0; i < 4; i++) {
      MVertex *v = t->getVertex(i);
      ms.tetCorners.push_back(v2c[v]);
    }
  }

  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces) {
    for(auto t : gf->triangles) {
      ms.triangleColors.push_back(gf->tag());
      for(size_t i = 0; i < 3; i++) {
        MVertex *v = t->getVertex(i);
        ms.triangleCorners.push_back(v2c[v]);
      }
    }
  }
  computeTetAdjacencies(ms);
}

int meshCombine3D(GRegion *gr)
{
  Msg::Info("Creating Mesh Wrapper for region %d", gr->tag());
  double volHex = 0, volTet = 0;
  int numHex = 0, numTet = 0;

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  HXTCombine::MeshStore ms;
  createMeshStore(gr, ms, v2c, c2v);
  // ----------------- I D E N T I F Y   H E X E S
  // -------------------------------------
  Msg::Info("Identifying Hexes for region %d", gr->tag());
  HXTCombine::TetMeshForCombining tm4c(&ms);
  HXTCombine::HXTCombineCellStore ccs(tm4c);
  double minQuality = 0.0001;
  ccs.computeHexes(minQuality);
  Msg::Info("%d Hexes found", ccs.hexes().size());
  // ----------------- S E L E C T I N G   H E X E S
  // -------------------------------------
  std::array<bool, 4> cellTypes{true, false, false, true};
  ccs.selectCellsGreedy(cellTypes);
  Msg::Info("%d Hexes selected", ccs.nbSelectedHexes());
  //	ccs.saveMSH("hexdom.msh",cellTypes);
  // ----------------- C R E A T I N G  V O L U M E    E L E M E N T S
  // --------------------
  for(auto t : gr->tetrahedra) delete t;
  gr->tetrahedra.clear();

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);

  std::set<MFace, MFaceLessThan> faceToDelete;

  std::unordered_set<MVertex *> all_v;

  for(size_t k = 0; k < ccs.hexes().size(); k++) {
    if(ccs.selectedHexes()[k]) {
      MVertex *v0 = c2v[ccs.hexes()[k].vertexes[0]];
      MVertex *v1 = c2v[ccs.hexes()[k].vertexes[1]];
      MVertex *v2 = c2v[ccs.hexes()[k].vertexes[2]];
      MVertex *v3 = c2v[ccs.hexes()[k].vertexes[3]];
      MVertex *v4 = c2v[ccs.hexes()[k].vertexes[4]];
      MVertex *v5 = c2v[ccs.hexes()[k].vertexes[5]];
      MVertex *v6 = c2v[ccs.hexes()[k].vertexes[6]];
      MVertex *v7 = c2v[ccs.hexes()[k].vertexes[7]];
      all_v.insert(v0);
      all_v.insert(v1);
      all_v.insert(v2);
      all_v.insert(v3);
      all_v.insert(v4);
      all_v.insert(v5);
      all_v.insert(v6);
      all_v.insert(v7);
      MHexahedron *h = new MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7);
      volHex += h->getVolume();
      numHex++;
      gr->hexahedra.push_back(h);
      for(int l = 0; l < 6; l++) {
        MFace f = h->getFace(l);
        MFace f012(f.getVertex(0), f.getVertex(1), f.getVertex(2));
        MFace f230(f.getVertex(2), f.getVertex(3), f.getVertex(0));
        GFace *gfound012 = findInFaceSearchStructure(f012, search);
        GFace *gfound230 = findInFaceSearchStructure(f230, search);
        if(gfound012 && gfound230 && gfound012 == gfound230) {
          gfound012->quadrangles.push_back(new MQuadrangle(
            f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
          faceToDelete.insert(f012);
          faceToDelete.insert(f230);
        }
        else {
          MFace f013(f.getVertex(0), f.getVertex(1), f.getVertex(3));
          MFace f312(f.getVertex(3), f.getVertex(1), f.getVertex(2));
          GFace *gfound013 = findInFaceSearchStructure(f013, search);
          GFace *gfound312 = findInFaceSearchStructure(f312, search);
          if(gfound013 && gfound312 && gfound013 == gfound312) {
            gfound013->quadrangles.push_back(new MQuadrangle(
              f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3)));
            faceToDelete.insert(f013);
            faceToDelete.insert(f312);
          }
        }
      }
    }
  }
  for(unsigned int k = 0; k < ms.tetCorners.size() / 4; k++) {
    if(ccs.selectedTets()[k]) {
      MVertex *v0 = c2v[ms.tetCorners[4 * k]];
      MVertex *v1 = c2v[ms.tetCorners[4 * k + 1]];
      MVertex *v2 = c2v[ms.tetCorners[4 * k + 2]];
      MVertex *v3 = c2v[ms.tetCorners[4 * k + 3]];
      all_v.insert(v0);
      all_v.insert(v1);
      all_v.insert(v2);
      all_v.insert(v3);
      MTetrahedron *tet = new MTetrahedron(v0, v1, v2, v3);
      gr->tetrahedra.push_back(tet);
      volTet += tet->getVolume();
      numTet++;
    }
  }

  {
    std::vector<MVertex *> vr;
    for(auto v : gr->mesh_vertices) {
      if(all_v.find(v) != all_v.end())
        vr.push_back(v);
      else {
        delete v;
      }
    }
    Msg::Info("%d vertice have been removed durin tet2hex combination",
              gr->mesh_vertices.size() - vr.size());
    gr->mesh_vertices = vr;
  }
  std::vector<GFace *> faces = gr->faces();
  for(auto gf : faces) {
    std::vector<MTriangle *> temp;
    for(auto t : gf->triangles) {
      if(faceToDelete.find(t->getFace(0)) == faceToDelete.end()) {
        temp.push_back(t);
      }
      else
        delete t;
    }
    gf->triangles = temp;
  }

  Msg::Info("Hybrid mesh statistics");
  Msg::Info(
    "Volume Hex %12.5E --- Volume Tet %12.5E --- Percentage Vol Hex %12.5E",
    volHex, volTet, 100 * volHex / (volHex + volTet));
  Msg::Info("Number Hex %12d --- Number Tet %12d --- Percentage Num Hex %12.5E",
            numHex, numTet, 100 * (double)numHex / (numHex + numTet));

  return 0;
}
#else

int meshCombine3D(GRegion *gr)
{
  Msg::Warning(
    "Gmsh must be compiled with HXT to enable hybrid mesh generation");
  return -1;
}

#endif

bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm)
{
  fs_cont search;
  // on boundary.
  buildFaceSearchStructure(gm, search);
  std::map<MFace, GRegion *, MFaceLessThan> bnd;
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    GRegion *gr = *rit;
    // look at every face that only comes once
    buildUniqueFaces(gr, bnd);
  }
  // bnd2 contains non conforming faces
  std::map<MFace, GRegion *, MFaceLessThan> bnd2;
  for(auto itf = bnd.begin(); itf != bnd.end(); ++itf) {
    GFace *gfound = findInFaceSearchStructure(itf->first, search);
    if(!gfound) { bnd2[itf->first] = itf->second; }
  }
  bnd.clear();

  //  Msg::Info("%d hanging faces", bnd2.size());

  // create trihedron

  for(auto itf = bnd2.begin(); itf != bnd2.end(); ++itf) {
    const MFace &f = itf->first;
    if(f.getNumVertices() == 4) { // quad face
      auto it1 =
        bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(2)));
      auto it2 =
        bnd2.find(MFace(f.getVertex(2), f.getVertex(3), f.getVertex(0)));
      if(it1 != bnd2.end() && it2 != bnd2.end()) {
        MTrihedron *th = new MTrihedron(f.getVertex(3), f.getVertex(0),
                                        f.getVertex(1), f.getVertex(2));
        itf->second->trihedra.push_back(th);
      }
      else {
        it1 = bnd2.find(MFace(f.getVertex(0), f.getVertex(1), f.getVertex(3)));
        it2 = bnd2.find(MFace(f.getVertex(3), f.getVertex(1), f.getVertex(2)));
        if(it1 != bnd2.end() && it2 != bnd2.end()) {
          MTrihedron *th = new MTrihedron(f.getVertex(0), f.getVertex(1),
                                          f.getVertex(2), f.getVertex(3));
          itf->second->trihedra.push_back(th);
        }
        else {
          Msg::Warning("MakeMeshConformal: wrong mesh topology");
          //          return false;
        }
      }
    }
  }
  return true;
}
