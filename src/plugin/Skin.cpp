// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdint>
#include <cmath>
#include "Skin.h"
#include "Context.h"
#include "GmshDefines.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "MPolyhedron.h"
#include "MFace.h"
#include "MEdge.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "ElementType.h"
#include "FaceMatcher.h"
#include "GModelVertexArrays.h"

GMSH_SkinPlugin::GMSH_SkinPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "Visible", nullptr, 1., ""},
                     {GMSH_FULLRC, "FromMesh", nullptr, 0., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_SkinPlugin::getHelp() const
{
  return "Plugin(Skin) extracts the boundary (skin) of the current "
         "mesh (if `FromMesh' = 1), or from the view `View' (in which "
         "case it creates a new view). If `View' < 0 and `FromMesh' = 0, "
         "the plugin is run on the current view.\n"
         "If `Visible' is set, the plugin only extracts the skin of visible "
         "entities.";
}

// The faces of an element (its edges, in 2D) as indices of its nodes: a flat
// list, with where each face starts in it (numFaces + 1 entries)
struct boundary {
  const int *offset, *nodes;
  int numFaces;
};

// the faces of the standard elements, outward as the old tables of this
// plugin had them
static boundary getBoundary(int type)
{
  static const int triOffset[] = {0, 2, 4, 6}, triNodes[] = {0, 1, 1, 2, 2, 0};
  static const int quaOffset[] = {0, 2, 4, 6, 8},
                   quaNodes[] = {0, 1, 1, 2, 2, 3, 3, 0};
  static const int tetOffset[] = {0, 3, 6, 9, 12},
                   tetNodes[] = {0, 1, 3, 0, 2, 1, 0, 3, 2, 1, 2, 3};
  static const int hexOffset[] = {0, 4, 8, 12, 16, 20, 24},
                   hexNodes[] = {0, 1, 5, 4, 0, 3, 2, 1, 0, 4, 7, 3,
                                 1, 2, 6, 5, 2, 3, 7, 6, 4, 5, 6, 7};
  static const int priOffset[] = {0, 4, 8, 12, 15, 18},
                   priNodes[] = {0, 1, 4, 3, 0, 3, 5, 2, 1,
                                 2, 5, 4, 0, 2, 1, 3, 4, 5};
  static const int pyrOffset[] = {0, 4, 7, 10, 13, 16},
                   pyrNodes[] = {0, 3, 2, 1, 0, 1, 4, 0,
                                 4, 3, 1, 2, 4, 2, 3, 4};
  switch(type) {
  case TYPE_TRI: return {triOffset, triNodes, 3};
  case TYPE_QUA: return {quaOffset, quaNodes, 4};
  case TYPE_TET: return {tetOffset, tetNodes, 4};
  case TYPE_HEX: return {hexOffset, hexNodes, 6};
  case TYPE_PRI: return {priOffset, priNodes, 5};
  case TYPE_PYR: return {pyrOffset, pyrNodes, 5};
  default: return {nullptr, nullptr, 0};
  }
}

// the faces of a polygon or polyhedron of a view, from the element itself
// (model-based data only), appended to offset (relative to the first node
// appended) and nodes; returns the number of boundary nodes of the element,
// 0 if its faces are unknown
static int getPolytopeBoundary(PViewData *data, int step, int ent, int ele,
                               std::vector<int> &offset,
                               std::vector<int> &nodes)
{
  MElement *e = data->getElement(step, ent, ele);
  if(!e) return 0;
  std::size_t base = nodes.size();
  int numCorners = e->getNumPrimaryVertices();
  if(e->getType() == TYPE_POLYG) {
    for(int i = 0; i < numCorners; i++) {
      offset.push_back((int)(nodes.size() - base));
      nodes.push_back(i);
      nodes.push_back((i + 1) % numCorners);
    }
  }
  else if(e->getType() == TYPE_POLYH) {
    MPolyhedron *p = static_cast<MPolyhedron *>(e);
    if(p->getNumFaces() > 255) return 0; // (faces are numbered on 8 bits)
    for(int f = 0; f < p->getNumPolygons(); f++) {
      offset.push_back((int)(nodes.size() - base));
      for(int i = p->getPolygonStart(f); i < p->getPolygonStart(f + 1); i++)
        nodes.push_back(p->getPolygonVertexIndex(i));
    }
  }
  else
    return 0;
  offset.push_back((int)(nodes.size() - base));
  return numCorners;
}

// a face of up to four nodes as it is, a larger one (of a polyhedron) as a
// fan of triangles from its first node, as it is drawn
template <class F> static void forEachSimplex(const int *nodes, int n, F f)
{
  if(n <= 4) {
    f(nodes, n);
    return;
  }
  for(int i = 1; i + 1 < n; i++) {
    int tri[3] = {nodes[0], nodes[i], nodes[i + 1]};
    f(tri, 3);
  }
}

// The skin of the elements of highest dimension of a mesh: their faces (or
// edges, in 2D) that no other element shares, whatever the entity, found as
// the drawing of the mesh finds them.
static void getBoundaryFromMesh(GModel *m, int visible)
{
  int dim = m->getDim();
  if(dim < 2) return;
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  std::vector<MElement *> elements;
  for(auto ge : entities) {
    if(ge->dim() != dim) continue;
    if(visible && !ge->getVisibility()) continue;
    for(std::size_t j = 0; j < ge->getNumMeshElements(); j++)
      elements.push_back(ge->getMeshElement(j));
  }
  if(elements.size() >= 0xffffffffu) {
    Msg::Error("Too many elements for the Skin plugin");
    return;
  }

  std::vector<std::pair<std::uint32_t, int> > skin; // element, face or edge
  findBoundaryOfElements(elements, dim == 2, nullptr, skin);

  if(dim == 2) {
    discreteEdge *e =
      new discreteEdge(m, m->getMaxElementaryNumber(1) + 1, nullptr, nullptr);
    m->add(e);
    for(auto &b : skin) {
      MEdge ed = elements[b.first]->getEdge(b.second);
      e->lines.push_back(new MLine(ed.getVertex(0), ed.getVertex(1)));
    }
  }
  else {
    discreteFace *f = new discreteFace(m, m->getMaxElementaryNumber(2) + 1);
    m->add(f);
    for(auto &b : skin) {
      MFace fa = elements[b.first]->getFace(b.second);
      std::vector<int> idx(fa.getNumVertices());
      for(std::size_t i = 0; i < idx.size(); i++) idx[i] = (int)i;
      forEachSimplex(idx.data(), (int)idx.size(), [&](const int *nod, int n) {
        if(n == 3)
          f->triangles.push_back(new MTriangle(
            fa.getVertex(nod[0]), fa.getVertex(nod[1]), fa.getVertex(nod[2])));
        else if(n == 4)
          f->quadrangles.push_back(
            new MQuadrangle(fa.getVertex(nod[0]), fa.getVertex(nod[1]),
                            fa.getVertex(nod[2]), fa.getVertex(nod[3])));
      });
    }
  }
  CTX::instance()->meshChanged();
}

// What stands for a node when the faces of a view are matched: its
// coordinates, as before (a view need not have a topology, and where it has
// one, nodes at the same place - both sides of what was cut out of a mesh, an
// element given nodes of its own - are still the same point of the field),
// on a grid of the tolerance the plugin always had.
static std::uint64_t nodeKey(PViewData *data, int step, int ent, int ele,
                             int nod, double tol)
{
  double x[3];
  data->getNode(step, ent, ele, nod, x[0], x[1], x[2]);
  std::uint64_t h = 0x9e3779b97f4a7c15ull;
  for(int i = 0; i < 3; i++) {
    h ^= (std::uint64_t)std::llround(x[i] / tol);
    h *= 0xff51afd7ed558ccdull;
    h ^= h >> 32;
  }
  return h | 1; // never 0
}

PView *GMSH_SkinPlugin::execute(PView *v)
{
  int visible = (int)option(0);
  int fromMesh = (int)option(1);
  int iView = (int)option(2);

  // compute boundary of current mesh
  if(fromMesh) {
    getBoundaryFromMesh(GModel::current(), visible);
    return v;
  }

  // compute boundary of post-processing data set
  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = getPossiblyAdaptiveData(v1);

  if(data1->hasMultipleMeshes()) {
    Msg::Error("Skin plugin cannot be applied to multi-mesh views");
    return v;
  }

  Msg::Info("Extracting boundary from View[%d]", v1->getIndex());

  int step0 = data1->getFirstNonEmptyTimeStep();

  // the elements that have a boundary, and what stands for their corners;
  // the faces of the polytopes, which have no table
  struct element {
    int ent, ele, type, first; // (first: of its corners in the keys)
    int faces, numFaces, nodeStart; // (in polyOffset/polyNodes, or -1)
  };
  std::vector<element> elements;
  std::vector<std::uint64_t> keys;
  std::vector<int> polyOffset, polyNodes;
  double tol = CTX::instance()->lc * 1.e-12;
  if(tol <= 0.) tol = 1.e-12;
  for(int ent = 0; ent < data1->getNumEntities(step0); ent++) {
    if(visible && data1->skipEntity(step0, ent)) continue;
    for(int ele = 0; ele < data1->getNumElements(step0, ent); ele++) {
      if(data1->skipElement(step0, ent, ele, visible)) continue;
      int type = data1->getType(step0, ent, ele);
      int numCorners, faces = -1, numFaces = 0, nodeStart = 0;
      if(type == TYPE_POLYG || type == TYPE_POLYH) {
        faces = (int)polyOffset.size();
        nodeStart = (int)polyNodes.size();
        numCorners =
          getPolytopeBoundary(data1, step0, ent, ele, polyOffset, polyNodes);
        if(!numCorners) continue;
        numFaces = (int)polyOffset.size() - faces - 1;
      }
      else {
        if(!getBoundary(type).numFaces) continue;
        numCorners = ElementType::getNumVertices(ElementType::getType(type, 1));
        if(data1->getNumNodes(step0, ent, ele) < numCorners) continue;
      }
      elements.push_back(
        {ent, ele, type, (int)keys.size(), faces, numFaces, nodeStart});
      for(int nod = 0; nod < numCorners; nod++)
        keys.push_back(nodeKey(data1, step0, ent, ele, nod, tol));
    }
  }
  if(keys.size() >= 0x7fffffffu) {
    Msg::Error("Too many elements for the Skin plugin");
    return v;
  }
  auto boundaryOf = [&](const element &e) -> boundary {
    if(e.faces < 0) return getBoundary(e.type);
    return {&polyOffset[e.faces], &polyNodes[e.nodeStart], e.numFaces};
  };

  // their faces (edges in 2D) that no other shares
  typedef std::pair<std::uint32_t, int> bnd; // element, face or edge
  int nthreads = CTX::instance()->numThreadsFor(elements.size(), 10000);
  std::vector<std::vector<bnd> > left(nthreads);
#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    FaceMatcher<std::uint64_t, std::uint32_t> matcher;
    std::vector<std::uint64_t> hash, key;
    for(std::size_t i = 0; i < elements.size(); i++) {
      boundary b = boundaryOf(elements[i]);
      const std::uint64_t *k = &keys[elements[i].first];
      hash.resize(b.numFaces);
      for(int j = 0; j < b.numFaces; j++) {
        int nc = b.offset[j + 1] - b.offset[j];
        key.resize(nc);
        for(int c = 0; c < nc; c++) key[c] = k[b.nodes[b.offset[j] + c]];
        hash[j] = (matcher.share(key.data(), nc, nthreads) == t) ?
                    matcher.hashOf(key.data(), nc, 0) :
                    0;
      }
      for(int j = 0; j < b.numFaces; j++)
        if(hash[j]) matcher.add(hash[j], (std::uint32_t)i, j);
    }
    matcher.forEachLeft(
      [&](std::uint32_t i, int j) { left[t].push_back(bnd(i, j)); });
  }
  std::vector<bnd> skin;
  for(auto &l : left) skin.insert(skin.end(), l.begin(), l.end());
  std::sort(skin.begin(), skin.end());

  // the values are only read for what is left
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  for(auto &b : skin) {
    const element &e = elements[b.first];
    boundary bd = boundaryOf(e);
    int numComp = data1->getNumComponents(step0, e.ent, e.ele);
    forEachSimplex(
      bd.nodes + bd.offset[b.second],
      bd.offset[b.second + 1] - bd.offset[b.second],
      [&](const int *nodes, int numNodes) {
        const int types[5] = {0, 0, TYPE_LIN, TYPE_TRI, TYPE_QUA};
        std::vector<double> *list =
          data2->incrementList(numComp, types[numNodes]);
        if(!list) return;
        double xyz[4][3];
        for(int j = 0; j < numNodes; j++)
          data1->getNode(step0, e.ent, e.ele, nodes[j], xyz[j][0], xyz[j][1],
                         xyz[j][2]);
        for(int k = 0; k < 3; k++)
          for(int j = 0; j < numNodes; j++) list->push_back(xyz[j][k]);
        for(int step = 0; step < data1->getNumTimeSteps(); step++) {
          if(!data1->hasTimeStep(step)) continue;
          for(int j = 0; j < numNodes; j++)
            for(int comp = 0; comp < numComp; comp++) {
              double val;
              data1->getValue(step, e.ent, e.ele, nodes[j], comp, val);
              list->push_back(val);
            }
        }
      });
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    if(data1->hasTimeStep(i)) data2->addTime(data1->getTime(i));
  data2->setName(data1->getName() + "_Skin");
  data2->setFileName(data1->getName() + "_Skin.pos");
  data2->finalize();

  return v2;
}
