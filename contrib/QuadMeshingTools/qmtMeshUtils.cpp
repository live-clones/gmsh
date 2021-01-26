// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtMeshUtils.h"

/* System includes */
#include <vector>
#include <array>
#include <unordered_map>
#include <cstdint>
#include <math.h>
#include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"

// /* QuadMeshingTools includes */
#include "cppUtils.h"

using namespace CppUtils;

std::vector<GFace*> model_faces(const GModel* gm) {
  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }
  return faces;
}

std::vector<GEdge*> face_edges(const GFace* gf) {
  std::vector<GEdge*> edges;
  for (GEdge* ge: gf->edges()) {
    edges.push_back(ge);
  }
  GFace* gfc = const_cast<GFace*>(gf);
  for (GEdge* ge: gfc->embeddedEdges()) {
    edges.push_back(ge);
  }
  sort_unique(edges);
  return edges;
}

std::vector<GEdge*> model_edges(const GModel* gm) {
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) append(edges,face_edges(gf));
  sort_unique(edges);
  return edges;
}

bool buildVertexToVertexMap(
    const std::vector<MTriangle*>& triangles,
    std::unordered_map<MVertex*,std::vector<MVertex*> >& v2v) {
  v2v.clear();
  v2v.rehash(3*triangles.size());

  size_t N = 3;
  for (MTriangle* f: triangles) {
    for (size_t le = 0; le < N; ++le) {
      MVertex* v1 = f->getVertex(le);
      MVertex* v2 = f->getVertex((le+1)%N);
      v2v[v1].push_back(v2);
      v2v[v2].push_back(v1);
    }
  }
  for (auto& kv: v2v) {
    sort_unique(kv.second);
  }

  return true;
}

