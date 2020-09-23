// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <iostream>
#include "meshQuadQuasiStructured.h"
#include "meshGFace.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "Options.h"
#include "fastScaledCrossField.h"

#include "Generator.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Field.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

using std::vector;
using std::array;

namespace QSQ {

  inline void normalize_accurate(SVector3& a) {
    double amp = std::abs(a.data()[0]);
    amp = std::max(amp,std::abs(a.data()[1]));
    amp = std::max(amp,std::abs(a.data()[2]));
    if (amp == 0.) {
      Msg::Error("cannot normalize vector whose length is strictly 0 !");
      return ;
    }
    a = amp * a;
    a.normalize();
  }


  inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }

  inline double angleVectors(SVector3 a, SVector3 b) {
    if (a.normSq() == 0. || b.normSq() == 0.) return DBL_MAX;
    normalize_accurate(a);
    normalize_accurate(b);
    return acos(clamp(dot(a,b),-1.,1.)); 
  }

  template<class T> 
    void sort_unique(std::vector<T>& vec) {
      std::sort( vec.begin(), vec.end() );
      vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() );
    }

  int computeFaceCornerAngles(const std::vector<GFace*>& faces, std::map<std::array<int,2>,double>& surfCornerAngle) {
    surfCornerAngle.clear();

    for (GFace* gf: faces) {
      if (gf->triangles.size() == 0) {
        int algo = gf->getMeshingAlgo();
        gf->setMeshingAlgo(ALGO_2D_FRONTAL);
        meshGFace mesher;
        mesher(gf);
        if (gf->triangles.size() == 0) {
          Msg::Error("failed to compute triangulated mesh for surface with tag %i", gf->tag());
          return -1;
        }
        gf->setMeshingAlgo(algo);
      }
      for (MTriangle* t: gf->triangles) {
        for (size_t lv = 0; lv < 3; ++lv) {
          MVertex* v = t->getVertex(lv);
          GVertex* gv = v->onWhat()->cast2Vertex();
          if (gv != nullptr) {
            MVertex* vPrev = t->getVertex((3+lv-1)%3);
            MVertex* vNext = t->getVertex((lv+1)%3);
            SVector3 pNext = vNext->point();
            SVector3 pPrev = vPrev->point();
            SVector3 pCurr = v->point();
            double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
            array<int,2> surfCorner = {gf->tag(),gv->tag()};
            surfCornerAngle[surfCorner] += agl;
          }
        }

      }
    }

    return 0;
  }

  bool surfaceContourIsManifold(GFace* gf) {
    std::map<GVertex*,std::set<GEdge*> > v2e;
    for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
      v2e[gv].insert(ge);
    }
    for (const auto& kv : v2e) {
      if (kv.second.size() > 2) {
        return false;
      }
    }
    return true;
  }

  int surfaceEulerCharacteristicDiscrete(GFace* gf) {
    if (gf->triangles.size() == 0) {
      Msg::Error("no triangulation for face %i, cannot compute discrete Euler characteristic", gf->tag());
      return std::numeric_limits<int>::max();
    }
    vector<size_t> vertices;
    vector<array<size_t,2> > edges;
    vertices.reserve(3*gf->triangles.size());
    edges.reserve(3*gf->triangles.size());
    for (MTriangle* t: gf->triangles) {
      for (size_t lv = 0; lv < 3; ++lv) {
        size_t v1 = t->getVertex(lv)->getNum();
        size_t v2 = t->getVertex((lv+1)%3)->getNum();
        array<size_t,2> vPair = {v1,v2};
        if (v1 > v2) vPair = {v2,v1};
        edges.push_back(vPair);
        vertices.push_back(v1);
      }
    }
    sort_unique(vertices);
    sort_unique(edges);
    int S = gf->triangles.size();
    int E = edges.size();
    int V = vertices.size();
    return V - E + S;
  }

  std::vector<GVertex*> face_corners(GFace* gf) {
    vector<GVertex*> corners;
    for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
      corners.push_back(gv);
    }
    sort_unique(corners);
    return corners;
  }

  /* discrete topological relations between irregular vertices:
   *   n_val5 + n_val3 = 4 \chi + m_val1 - m_val3  - 2 m_val4 */
  int sumNbInteriorIrregularVerticesValence3And5(GFace* gf,
      const std::map<std::array<int,2>,double>& surfCornerAngle) {

    int chi = surfaceEulerCharacteristicDiscrete(gf);
    vector<GVertex*> corners = face_corners(gf);

    int m_val1 = 0;
    int m_val2 = 0;
    int m_val3 = 0;
    int m_val4 = 0;
    for (GVertex* gv: corners) {
      array<int,2> query = {gf->tag(),gv->tag()};
      auto it = surfCornerAngle.find(query);
      if (it == surfCornerAngle.end()) {
        Msg::Error("failed to find (surf=%i,node=%i) in surfCornerAngle", query[0], query[1]);
        return std::numeric_limits<int>::max();
      }
      double angle_deg = 180. / M_PI * it->second;
      if (angle_deg < 90. + 45.) {
        m_val1 += 1;
      } else if (angle_deg < 180. + 45.) {
        m_val2 += 1;
      } else if (angle_deg < 270. + 45.) {
        m_val3 += 1;
      } else if (angle_deg < 360.) {
        m_val4 += 1;
      } else {
        Msg::Error("weird angle, corner (surf=%i,node=%i), angle = %f deg", query[0], query[1], angle_deg);
        return std::numeric_limits<int>::max();
      }
    }

    return 4*chi + m_val1 - m_val3 - 2 * m_val4;
  }

}

using namespace QSQ;

int setQuadCoherentCurveTransfiniteConstraints(const std::vector<GFace*>& faces) 
{
  Msg::Debug("mesh %li faces with quad integer constraint solver ...", faces.size());
  std::map<std::array<int,2>,double> surfCornerAngle;
  int s1 = computeFaceCornerAngles(faces, surfCornerAngle);
  if (s1 != 0) {
    Msg::Error("failed to compute face corner angles");
    return s1;
  }

  for (GFace* gf: faces) {
    if (!surfaceContourIsManifold(gf)) {
      Msg::Info("surface %i contour is not manifold, ignore it", gf->tag());
      continue;
    }
  }

  return 0;
}

std::vector<GFace*> model_faces(GModel* gm) {
  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }
  return faces;
}

std::vector<GEdge*> model_edges(GModel* gm) {
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) {
    for (GEdge* ge: gf->edges()) {
      edges.push_back(ge);
    }
    for (GEdge* ge: gf->embeddedEdges()) {
      edges.push_back(ge);

    }
  }
  sort_unique(edges);
  return edges;
}

int generateInitialTriangulation(GModel* gm) {
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_FRONTAL);

  CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
  CTX::instance()->lock = 0;
  GenerateMesh(gm, 2);
  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;

  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_QUAD_QUASI_STRUCT);
  return 0;
}

size_t numberOfTriangles(GModel* gm) {
  size_t N = 0;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    N += (*it)->triangles.size();
  }
  return N;
}

int computeScaledCrossField(GModel* gm) {
  int viewTag = -1;
  int targetNumberOfQuads = 0.5*numberOfTriangles(gm);
  // FIXME: scaling the number of quads break something ! the number of points
  //        on curves are not scaled with the background field
  // targetNumberOfQuads *= 0.25; /* because of future midpoint subdivision */
  int nbDiffusionLevels = 7;
  double thresholdNormConvergence = 1.e-2;
  int nbBoundaryExtensionLayer = 1;
  std::string name = "scaled_cross_field";
  {
    PView* view_s = PView::getViewByName(name);
    if (view_s) {
      viewTag = view_s->getTag();
    }
  }
  int verbosity = 1;
  int st = computeScaledCrossFieldView(gm, viewTag, targetNumberOfQuads, 
      nbDiffusionLevels, thresholdNormConvergence, nbBoundaryExtensionLayer, 
      name, verbosity);
  if (st == 0) {
    gm->getFields()->setBackgroundMesh(viewTag);
    // gm->getFields()->initialize(); // required ?
    // PView* view_s = PView::getViewByName(name);
    // if (view_s) view_s->getOptions()->visible = 0;
  }
  return st;
}

int computeQuadCurveMeshConstraints(GModel* gm) {
  Msg::Warning("-- curve constraints not yet implemented ...");
  return 1;
}

int generateCurve1DMeshes(GModel* gm) {
  computeQuadCurveMeshConstraints(gm);

  /* Remove triangulations */
  std::for_each(gm->firstFace(), gm->lastFace(), deMeshGFace());

  std::vector<GEdge*> edges = model_edges(gm);
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (GEdge* ge: edges) {
    ge->mesh(false);
  }

  return 0;
}

int generateUnstructuredQuadMeshes(GModel* gm) {

  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_PACK_PRLGRMS);

  CTX::instance()->mesh.algo2d = ALGO_2D_PACK_PRLGRMS;
  CTX::instance()->lock = 0;

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (GFace* gf: faces) {
    gf->mesh(true);
  }


  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;

  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_QUAD_QUASI_STRUCT);

  return 0;
}


int Mesh2DWithQuadQuasiStructured(GModel* gm)
{
  if (CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT) {
    return 1;
  }
  std::vector<GFace*> faces;

  Msg::Info("Generate quasi-structured all-quadrilateral mesh ...");

  Msg::Info("[Step 1] Generate initial triangulation ...");
  int s1 = generateInitialTriangulation(gm);
  if (s1 != 0) {
    Msg::Error("failed to generate initial triangulation, abort");
    return s1;
  }

  Msg::Info("[Step 2] Generate scaled cross field ...");
  int s2 = computeScaledCrossField(gm);
  if (s2 != 0) {
    Msg::Error("failed to compute scaled cross field, abort");
    return s2;
  }

  Msg::Info("[Step 3] Generate curve 1D meshes ...");
  int s3 = generateCurve1DMeshes(gm);
  if (s3 != 0) {
    Msg::Warning("failed to generate curve 1D meshes, abort");
    return s3;
  }

  Msg::Info("[Step 4] Generate unstructured quad meshes ...");
  int s4 = generateUnstructuredQuadMeshes(gm);
  if (s4 != 0) {
    Msg::Warning("failed to generate 2D unstructured quad meshes, abort");
    return s4;
  }


  return 0;
}
