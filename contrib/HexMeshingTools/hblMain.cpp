// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblMain.h"

#include <queue>

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"
#include "qmtMeshUtils.h"

/* HexMeshingTools includes */
#include "hblLogging.hpp"
#include "hblTypes.hpp"
#include "hblBrepMesh.h"
#include "hblUtils.h"
#include "hblDiskTriangulation.h"
#include "hblGecode.h"
#include "hblSolveAllHexLayer.h"
#include "hblBuildAllHexLayer.h"
#include "hblOptimizeGeometry.h"
#include "hblBuildInteriorMesh.h"
#include "hblGmshIO.h"

/* Gmsh includes */
#include "GmshGlobal.h"
#include "Options.h"
#include "GmshConfig.h"
#include "Context.h"
#include "GmshMessage.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "meshGFace.h"
#include "GRegion.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MHexahedron.h"
#include "MTetrahedron.h"
#include "drawContext.h"
#include "discreteFace.h"
#include "discreteRegion.h"

#include "gmsh.h"

/* - Loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)


using std::vector;
using std::map;
using std::unordered_map;
using std::unordered_set;
using std::array;
using std::pair;


namespace hbl {
  using namespace CppUtils;

  const int colorBase = 1;
  const int colorCurve = 2;
  const int colorNonIdeal = 3;
  const int colorInterior = 4;

  bool createAnisotropicHexLayer(
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output) {

    int Nl = 3;

    ElementMesh A;
    subdivide_hex_boundary_layer_anistropic(output.H, output.h2q, Nl, A);

    GRegion* gr = *GModel::current()->firstRegion();

    int tag = 2000;
    // GRegion* grReg = nullptr;
    // grReg = new GRegion(gr->model(),tag);
    // gr->model()->add(grReg);
    GRegion* grReg = gr;

    GRegion* grIrreg = nullptr;
    GRegion* grCurve = nullptr;
    grIrreg = new GRegion(gr->model(),tag+1);
    grCurve = new GRegion(gr->model(),tag+2);
    gr->model()->add(grIrreg);
    gr->model()->add(grCurve);

    grReg  ->meshStatistics.status = GRegion::DONE;
    grIrreg->meshStatistics.status = GRegion::DONE;
    grCurve->meshStatistics.status = GRegion::DONE;
    gr->model()->addPhysicalGroup(3,1,{grReg->tag()});
    gr->model()->addPhysicalGroup(3,2,{grCurve->tag()});
    gr->model()->addPhysicalGroup(3,3,{grIrreg->tag()});

    vector<MVertex*> old2new(A.points.size(),nullptr);
    for (size_t c = 0; c < A.cells.size(); ++c) {
      MVertex* vert[8];
      F(lv,8) {
        id v = A.cells[c][lv];
        if (old2new[v] == nullptr) {
          vec3 p = A.points[v];
          MVertex* nv = new MVertex(p[0],p[1],p[2], gr);
          gr->mesh_vertices.push_back(nv);
          vert[lv] = nv;
          old2new[v] = nv;
        } else {
          vert[lv] = old2new[v];
        }
      }
      MHexahedron* hex = new MHexahedron(
          vert[0],vert[1],vert[2],vert[3],
          vert[4],vert[5],vert[6],vert[7]);
      int hexType = A.cellData[c];
      if (hexType == colorBase) {
        grReg->hexahedra.push_back(hex);
      } else if (hexType == colorCurve) {
        grCurve->hexahedra.push_back(hex);
      } else if (hexType == colorNonIdeal) {
        grIrreg->hexahedra.push_back(hex);
      }
    }

    if (grReg->hexahedra.size() == 0) {
      gr->model()->remove(grReg);
      delete grReg;
    }
    if (grCurve->hexahedra.size() == 0) {
      gr->model()->remove(grCurve);
      delete grCurve;
    }
    if (grIrreg->hexahedra.size() == 0) {
      gr->model()->remove(grIrreg);
      delete grIrreg;
    }

    Msg::Info("- Remove duplicated vertices (temporary solution, bad) ...");
    double tol = 1.e-14;
    GModel::current()->removeDuplicateMeshVertices(tol);

    return true;
  }

  bool setHexColors(
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output) {
    for (size_t i = 0; i < output.hexahedra.size(); ++i) {
      size_t nFaceOnBdr = 0;
      int hexType = 0;
      for (id f: output.H.cells[i].faces) if (output.h2q.faceParent[f].first <= 2) {
        nFaceOnBdr += 1;
      }
      if (nFaceOnBdr == 1) {
        hexType = colorBase;
      } else {
        hexType = colorCurve;
      }

      /* Flag hexes on curve fans */
      vector<id> cedges(12);
      cell_edges(output.H, i, cedges);
      for (size_t le = 0; le < cedges.size(); ++le) {
        id e = cedges[le];
        if (output.h2q.edgeParent[e].first == 1) {
          if (output.H.edgeToFaces[e].size() != 3) {
            hexType = colorCurve;
            break;
          }
        }
      }

      /* Flag hexes in non-trivial configs */
      for (size_t lv = 0; lv < 8; ++lv) {
        id v = output.hexahedra[i][lv];
        if (output.h2q.vertexParent[v].first == 0) {
          id qv = output.h2q.vertexParent[v].second;
          if (!output.configIsIdeal[qv]) {
            hexType = colorNonIdeal;
          }
        }
      }
      output.H.cells[i].data = hexType;
    }
    return true;
  }

  bool addGRegionElements(
      GRegion* gr,
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output,
      bool addTets = true,
      bool differentGRegions = false,
      bool differentPartitions = false) {
    if (output.hexahedra.size() == 0) {
      Msg::Error("- Region %i: no hexahedra to add", gr->tag());
      return false;
    }
    Msg::Info("- Region %i: add %li hexahedra", gr->tag(),output.hexahedra.size());

    GRegion* grReg = gr;
    // GRegion* grReg = nullptr;
    GRegion* grIrreg = nullptr;
    GRegion* grCurve = nullptr;
    GRegion* grInt = nullptr;
    if (differentGRegions) {
      /* temporary stuff for vizu */
      int tag = gr->tag()*1000; 
      // grReg = new GRegion(gr->model(),tag);
      grIrreg = new GRegion(gr->model(),tag+1);
      grCurve = new GRegion(gr->model(),tag+2);
      grInt = new GRegion(gr->model(),tag+3);
      gr->model()->add(grReg);
      gr->model()->add(grIrreg);
      gr->model()->add(grCurve);
      gr->model()->add(grInt);
      grReg  ->meshStatistics.status = GRegion::DONE;
      grIrreg->meshStatistics.status = GRegion::DONE;
      grCurve->meshStatistics.status = GRegion::DONE;
      grInt->meshStatistics.status = GRegion::DONE;
      gr->model()->addPhysicalGroup(3,1,{gr->tag()});
      gr->model()->addPhysicalGroup(3,2,{tag+2});
      gr->model()->addPhysicalGroup(3,3,{tag+1});
      gr->model()->addPhysicalGroup(3,4,{tag+3});
    }

    /* warning: fill vertex origin in H during creation */
    gr->deleteMesh();
    gr->hexahedra.reserve(output.hexahedra.size());
    for (size_t i = 0; i < output.hexahedra.size(); ++i) {
      MVertex* vert[8];
      for (size_t lv = 0; lv < 8; ++lv) {
        id v = output.hexahedra[i][lv];
        vec3 p = output.H.vertices[v].pt;
        if (output.H.vertices[v].origin != nullptr) {
          vert[lv] = output.H.vertices[v].origin;
          vert[lv]->setXYZ(p[0],p[1],p[2]);
        } else {
          GEntity* ge = getEntity(output.H, v, output.h2q, input.Q);
          if (ge == nullptr || ge == gr) {
            MVertex* nv = new MVertex(p[0],p[1],p[2], gr);
            gr->mesh_vertices.push_back(nv);
            output.H.vertices[v].origin = nv;
            vert[lv] = nv;
          } else if (dynamic_cast<GEdge*>(ge) != nullptr) {
            MVertex* nv = new MEdgeVertex(p[0],p[1],p[2], ge, 0.);
            ge->mesh_vertices.push_back(nv);
            output.H.vertices[v].origin = nv;
            vert[lv] = nv;
          } else if (dynamic_cast<GFace*>(ge) != nullptr) {
            MVertex* nv = new MFaceVertex(p[0],p[1],p[2],ge, 0., 0.);
            ge->mesh_vertices.push_back(nv);
            output.H.vertices[v].origin = nv;
            vert[lv] = nv;
          }
        }
      }
      MHexahedron* hex = new MHexahedron(
          vert[0],vert[1],vert[2],vert[3],
          vert[4],vert[5],vert[6],vert[7]);

      int hexType = colorInterior;
      if (i < output.H.cells.size()) {
        hexType = output.H.cells[i].data;
      }

      if (differentGRegions) {
        if (hexType == colorBase) {
          grReg->hexahedra.push_back(hex);
        } else if (hexType == colorCurve) {
          grCurve->hexahedra.push_back(hex);
        } else if (hexType == colorNonIdeal) {
          grIrreg->hexahedra.push_back(hex);
        } else if (hexType == colorInterior) {
          grInt->hexahedra.push_back(hex);
        }
      } else {
        if (differentPartitions) {
          hex->setPartition(hexType);
        }
        gr->hexahedra.push_back(hex);
      }
    }

    size_t ntet = 0;
    gr->tetrahedra.reserve(output.tetrahedra.size());
    for (size_t i = 0; i < output.tetrahedra.size(); ++i) {
      MVertex* vert[4];
      for (size_t lv = 0; lv < 4; ++lv) {
        id v = output.tetrahedra[i][lv];
        vec3 p = output.H.vertices[v].pt;
        if (output.H.vertices[v].origin != nullptr) {
          vert[lv] = output.H.vertices[v].origin;
          vert[lv]->setXYZ(p[0],p[1],p[2]);
        } else {
          GEntity* ge = getEntity(output.H, v, output.h2q, input.Q);
          if (ge == nullptr || ge == gr) {
            MVertex* nv = new MVertex(p[0],p[1],p[2], gr);
            gr->mesh_vertices.push_back(nv);
            output.H.vertices[v].origin = nv;
            vert[lv] = nv;
          } else if (dynamic_cast<GEdge*>(ge) != nullptr) {
            MVertex* nv = new MEdgeVertex(p[0],p[1],p[2], ge, 0.);
            ge->mesh_vertices.push_back(nv);
            output.H.vertices[v].origin = nv;
            vert[lv] = nv;
          } else if (dynamic_cast<GFace*>(ge) != nullptr) {
            MVertex* nv = new MFaceVertex(p[0],p[1],p[2],ge, 0., 0.);
            ge->mesh_vertices.push_back(nv);
            output.H.vertices[v].origin = nv;
            vert[lv] = nv;
          }
        }
      }
      MTetrahedron* tet = new MTetrahedron(
          vert[0],vert[1],vert[2],vert[3]);
      if (differentGRegions) {
        grInt->tetrahedra.push_back(tet);
      } else {
        gr->tetrahedra.push_back(tet);
      }
      ntet += 1;
    }


    if (differentGRegions) {
      if (grCurve->hexahedra.size() == 0) {
        gr->model()->remove(grCurve);
        delete grCurve;
      }
      if (grIrreg->hexahedra.size() == 0) {
        gr->model()->remove(grIrreg);
        delete grIrreg;
      }
      if (grInt->getNumMeshElements() == 0) {
        gr->model()->remove(grInt);
        delete grInt;
      }
    } else if (differentPartitions) {
      gr->model()->setNumPartitions(3);
    }
    Msg::Info("- Region %i: add %li tetrahedra", gr->tag(),ntet);

    bool createBdrQuads = true;
    if (createBdrQuads) {
      for (GFace* gf: gr->faces()) {
        for (MQuadrangle* q: gf->quadrangles) {
          delete q;
        }
        gf->quadrangles.clear();
      }
      for (id f = 0; f < output.H.faces.size(); ++f) {
        if (output.h2q.faceParent[f].first == 2) {
          vector<id> fvert(4);
          face_vertices(output.H,f,fvert);
          if (fvert.size() != 4) continue;
          MQuadrangle* q = new MQuadrangle(
              output.H.vertices[fvert[0]].origin,
              output.H.vertices[fvert[1]].origin,
              output.H.vertices[fvert[2]].origin,
              output.H.vertices[fvert[3]].origin);
          GFace* gf = dynamic_cast<GFace*>(output.H.faces[f].entity);
          if (gf != nullptr) {
            gf->quadrangles.push_back(q);
          } else {
            Msg::Debug("addGRegionElements: no GFace to add quad");
          }
        }
      }
      // for (GFace* gf: gr->faces()) {
      //   gf->meshStatistics.status = GFace::DONE;
      // }
    }

    // Quick way to connect boundary and interior
    // TODO FIXME better way...
    std::pair<vec3,vec3> bb = bbox_of_mesh(output.H);
    double diag = length(bb.second - bb.first);
    gr->model()->removeDuplicateMeshVertices(1.e-12*diag);

    return true;
  }

  bool generateAllHexBoundaryLayerMeshForGRegion(
      GRegion* gr,
      HblInput& input,
      HblOptions& opt,
      HblOutput& output) {

    bool oki = buildBoundaryMeshFromGRegion(gr, input.Q);
    if (!oki) {
      Msg::Error("hexbl: failed to build boundary mesh for region %i", gr->tag());
      return false;
    }

    bool okc = prepareHexblInput(gr, input, output);
    if (!okc) {
      Msg::Error("hexbl: failed to compute ideal hexahedral valences for region %i", gr->tag());
      return false;
    }

    if (Msg::GetVerbosity() >= 99) {
      std::vector<id> faces(input.Q.faces.size());
      F(i,faces.size()) faces[i] = i;
      visualization_show_faces(input.Q,faces, "input_Q");
    }

    bool oks = solveAllHexBoundaryLayerProblem(input, opt, output); 
    if (!oks) {
      Msg::Error("hexbl: failed to solve all-hex boundary layer problem for region %i", gr->tag());
      return false;
    }

    bool okb = buildAllHexBoundaryLayer(input, opt, output);
    if (!okb) {
      if (output.QvertTangled.size() == 0) {
        Msg::Error("hexbl: failed to build all-hex boundary layer mesh for region %i", gr->tag());
        return false;
      }  else {
        Msg::Warning("hexbl: tangled elements in all-hex boundary layer mesh geometry for region %i", gr->tag());
        // return false;
      }
    }

    setHexColors(input, opt, output);

    return true;
  }

  void fillStatisticts(
      const HblInput& input, const HblOptions& opt, const HblOutput& output,
      HblStats& stats) {
    stats.inNbVertices = input.Q.vertices.size();
    stats.inNbFacets = input.Q.faces.size();
    stats.outNbVertices = output.H.vertices.size();
    stats.outNbHexes = output.hexahedra.size();
    stats.outNbTets = output.tetrahedra.size();

    QualityMetric m = QualityMetric::SIGE;
    stats.qualityInputMinMedAvgMaxInv = computeInputQualityStatsMinMedAvgMaxInv(input.Q, m);
    stats.qualityHexMinMedAvgMaxInv = computeHexQualityStatsMinMedAvgMaxInv(output, m);
    stats.qualityTetMinMedAvgMaxInv = computeTetQualityStatsMinMedAvgMaxInv(output, m);
  }

  int generateAllHexBoundaryLayerMesh(GModel* gm) {
    Msg::Info("Generate all-hex boundary layer for %li volumes ...", gm->getNumRegions());

    if (gm->getFaces().size() > 0 && gm->getNumRegions() == 0) {
      Msg::Warning("%li faces but 0 volumes, try to create a volume ...", gm->getFaces().size());
      if (gm->getFaces().size() == 1) {
        GFace* gf = *gm->getFaces().begin();
        discreteFace* df = dynamic_cast<discreteFace*>(gf);
        if (df != nullptr) {
          discreteRegion* dr = new discreteRegion(GModel::current());
          GModel::current()->add(dr);
          dr->setFace(df,1);
          Msg::Info("create one discrete volume from one discrete face");
        }
      }
    }

    if (gm->getNumRegions() == 0) {
      Msg::Error("no volumes, cancel");
      return -1;
    }

    DiskTriangulations trgls;
    load_disk_triangulations(trgls);

    HblOptions opt;
    opt.dt = &trgls;
    // opt.extrusion_factor = 1./3.;
    opt.extrusion_factor = 1./2.;
    if (Msg::GetVerbosity() >= 99) {
      opt.debug = true;
      opt.viz = true;
    }
    opt.gecodeTimeMaxInit = 30e3; // 30 seconds for initial guess
    opt.gecodeTimeMaxImprove = 3e3; // 3 seconds to improve

    for (GFace* gf: gm->getFaces()) {
      if (gf->isFullyDiscrete())  opt.discreteModel = true;
    }

    char* pure_extrusion = getenv("pure_extrusion");
    if (pure_extrusion) {
      Msg::Warning("Imposing pure-extrusion of surface mesh");
      opt.imposed_valence = 2;
    }

    HblStats statsAllRegions;

    /* Special case for M4:
     * setOutwardOrientationMeshConstraint is going into a infinite
     * loop, so we manually set the orientation */
    const bool manualOrient = false;

    /* Boundary mesh */
    for (GRegion* gr: gm->getRegions()) {
      if (gr->meshStatistics.status == GRegion::DONE) continue;

      if (!manualOrient) {
        Msg::Info("Orient boundary mesh ...");
        /* Fix boundary mesh orientation */
        gr->setOutwardOrientationMeshConstraint();
        for (GFace* gf: gr->faces()) {
          /* invert orientation to get normals pointing inside the volune */
          gf->meshAttributes.reverseMesh = !gf->meshAttributes.reverseMesh;

          /* re-orient the mesh elements */
          orientMeshGFace orient;
          orient(gf);
        }
      } else {
        Msg::Warning("! MANUAL SURFACE ORIENTATION !");
        for (GFace* gf: gr->faces()) {
          /* invert orientation to get normals pointing inside the volune */
          gf->meshAttributes.reverseMesh = !gf->meshAttributes.reverseMesh;
          /* re-orient the mesh elements */
          orientMeshGFace orient;
          orient(gf);
        }
      }

      HblInput input;
      HblOutput output;

      /* Build all-hex boundary layer */
      bool okbl = generateAllHexBoundaryLayerMeshForGRegion(gr, input, opt, output);
      if (!okbl) {
        if (output.QvertTangled.size() > 0) {
          bool oks = smoothGModelSurfaceMesh(input.Q, output.QvertTangled);

          if (oks) {
            /* Re-try with smoothed boundary */
            Msg::Warning("New all-hex boundary layer process with updated surface mesh");
            input = HblInput();
            output = HblOutput();
            opt.noCADproj = true;
            okbl = generateAllHexBoundaryLayerMeshForGRegion(gr, input, opt, output);
          }
        }
      }
      if (!okbl) {
        Msg::Error("hexbl: failed to build all-hex boundary layer mesh for region %i", gr->tag());
        continue;
      }


      /* Transfer the hexahedra to the gmsh GModel */
      bool hexdom = true;
      char* no_interior = getenv("no_interior");
      if (no_interior) {
        Msg::Warning("No interior volume filling");
        hexdom = false;
      }

      if (hexdom) {
        Msg::Info("- Region %i: build interior hex-dominant mesh", gr->tag());
        bool oki = buildInteriorHexdomMesh(input, opt, output);
        if (!oki) {
          Msg::Warning("hexbl: failed to build interior mesh in region %i", gr->tag());
        }
      }

      bool oka = addGRegionElements(gr, input, opt, output);
      if (!oka) {
        Msg::Error("hexbl: failed to add hexes in region %i", gr->tag());
        continue;
      }

      gr->meshStatistics.status = GRegion::DONE;

      fillStatisticts(input, opt, output, output.stats);

      // bool compareStatsExtrusion = false;
      // if (compareStatsExtrusion) {
      //   Msg::Warning("Build a extruded boundary layer for comparison");
      //   HblInput input2 = input;
      //   std::fill(input2.edgeHexValIdeal.begin(),input2.edgeHexValIdeal.end(),2.);
      //   HblOutput output2;
      //   solveAllHexBoundaryLayerProblem(input2, opt, output2); 
      //   buildAllHexBoundaryLayer(input2, opt, output2);
      // }

      printHblStats(output.stats);
      writeHblStats(output.stats, "hexbl_statistics.json");
      // TODO: merge output.stats with statsAllRegions
    }

    Msg::Info("... hex boundary layer built");

    {
      unsigned int colorCarousel = 0;
      opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI,  colorCarousel);
      unsigned int hexCol = CTX::instance()->packColor(242, 242, 242, 1.);
      opt_mesh_color_hexahedra(0, GMSH_SET | GMSH_GUI, hexCol);
      unsigned int tetCol = CTX::instance()->packColor(179, 255, 102, 1.);
      opt_mesh_color_tetrahedra(0, GMSH_SET | GMSH_GUI, tetCol);
    }
    { /* Mesh visualization options */
      Msg::Warning("vizu ...");
      gmsh::initialize();
      if (opt.viz) GeoLog::flush();

      // By partition
      // unsigned int colorCarousel = 3;
      // opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI,  colorCarousel);

      // By physical tag
      // unsigned int colorCarousel = 2;
      // opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI,  colorCarousel);

      unsigned int hexExtr = CTX::instance()->packColor(242, 242, 242, 1.);
      opt_mesh_color_1(0, GMSH_SET | GMSH_GUI, hexExtr);

      // unsigned int hexCurve = CTX::instance()->packColor(149, 210, 236, 1.);
      unsigned int hexCurve = CTX::instance()->packColor(71, 171, 216, 1.);
      opt_mesh_color_2(0, GMSH_SET | GMSH_GUI, hexCurve);

      unsigned int hexIrreg = CTX::instance()->packColor(255, 66, 66, 1.);
      opt_mesh_color_3(0, GMSH_SET | GMSH_GUI, hexIrreg);

      unsigned int interior = CTX::instance()->packColor(179, 255, 102, 1.);
      opt_mesh_color_4(0, GMSH_SET | GMSH_GUI, interior);

      unsigned int cadCurves = CTX::instance()->packColor(0, 58, 93, 1.);
      opt_geometry_color_curves(0, GMSH_SET | GMSH_GUI, cadCurves);
      opt_geometry_color_points(0, GMSH_SET | GMSH_GUI, cadCurves);


      opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_volume_edges(0, GMSH_SET | GMSH_GUI, 1);
      opt_mesh_volume_faces(0, GMSH_SET | GMSH_GUI, 1);


      CTX::instance()->mesh.changed = ENT_ALL;
    }

    // disable optimization after hexbl meshing
    CTX::instance()->mesh.optimize = 0;
    
    return 0;
  }
}
