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
#include "MFace.h"
#include "MEdge.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "ElementType.h"
#include "FaceMatcher.h"
#include "GModelVertexArrays.h"

StringXNumber SkinOptions_Number[] = {{GMSH_FULLRC, "Visible", nullptr, 1., ""},
                                      {GMSH_FULLRC, "FromMesh", nullptr, 0., ""},
                                      {GMSH_FULLRC, "View", nullptr, -1., ""}};

extern "C" {
GMSH_Plugin *GMSH_RegisterSkinPlugin() { return new GMSH_SkinPlugin(); }
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

int GMSH_SkinPlugin::getNbOptions() const
{
  return sizeof(SkinOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SkinPlugin::getOption(int iopt)
{
  return &SkinOptions_Number[iopt];
}

// The faces of an element, or the edges of a 2D one, outward as the old
// tables of this plugin had them
static int getBoundary(int type, const int (**boundary)[6][4])
{
  static const int tri[6][4] = {{0, 1, -1, -1}, {1, 2, -1, -1}, {2, 0, -1, -1}};
  static const int qua[6][4] = {
    {0, 1, -1, -1}, {1, 2, -1, -1}, {2, 3, -1, -1}, {3, 0, -1, -1}};
  static const int tet[6][4] = {
    {0, 1, 3, -1}, {0, 2, 1, -1}, {0, 3, 2, -1}, {1, 2, 3, -1}};
  static const int hex[6][4] = {{0, 1, 5, 4}, {0, 3, 2, 1}, {0, 4, 7, 3},
                                {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  static const int pri[6][4] = {
    {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}, {0, 2, 1, -1}, {3, 4, 5, -1}};
  static const int pyr[6][4] = {
    {0, 3, 2, 1}, {0, 1, 4, -1}, {0, 4, 3, -1}, {1, 2, 4, -1}, {2, 3, 4, -1}};
  switch(type) {
  case TYPE_TRI: *boundary = &tri; return 3;
  case TYPE_QUA: *boundary = &qua; return 4;
  case TYPE_TET: *boundary = &tet; return 4;
  case TYPE_HEX: *boundary = &hex; return 6;
  case TYPE_PRI: *boundary = &pri; return 5;
  case TYPE_PYR: *boundary = &pyr; return 5;
  default: return 0;
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
      if(fa.getNumVertices() == 3)
        f->triangles.push_back(
          new MTriangle(fa.getVertex(0), fa.getVertex(1), fa.getVertex(2)));
      else if(fa.getNumVertices() == 4)
        f->quadrangles.push_back(new MQuadrangle(
          fa.getVertex(0), fa.getVertex(1), fa.getVertex(2), fa.getVertex(3)));
    }
  }
  CTX::instance()->meshChanged();
}

// where the values of an element with numNodes nodes and numComp components
// go in a list-based view
static std::vector<double> *getList(PViewDataList *data, int numNodes,
                                    int numComp, int **num)
{
  int c = (numComp == 1) ? 0 : (numComp == 3) ? 1 : (numComp == 9) ? 2 : -1;
  if(c < 0) return nullptr;
  switch(numNodes) {
  case 2: {
    std::vector<double> *l[3] = {&data->SL, &data->VL, &data->TL};
    int *n[3] = {&data->NbSL, &data->NbVL, &data->NbTL};
    *num = n[c];
    return l[c];
  }
  case 3: {
    std::vector<double> *l[3] = {&data->ST, &data->VT, &data->TT};
    int *n[3] = {&data->NbST, &data->NbVT, &data->NbTT};
    *num = n[c];
    return l[c];
  }
  case 4: {
    std::vector<double> *l[3] = {&data->SQ, &data->VQ, &data->TQ};
    int *n[3] = {&data->NbSQ, &data->NbVQ, &data->NbTQ};
    *num = n[c];
    return l[c];
  }
  }
  return nullptr;
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
  int visible = (int)SkinOptions_Number[0].def;
  int fromMesh = (int)SkinOptions_Number[1].def;
  int iView = (int)SkinOptions_Number[2].def;

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

  // the elements that have a boundary, and what stands for their corners
  struct element {
    int ent, ele, type, first; // (first: of its corners in the keys)
  };
  std::vector<element> elements;
  std::vector<std::uint64_t> keys;
  double tol = CTX::instance()->lc * 1.e-12;
  if(tol <= 0.) tol = 1.e-12;
  for(int ent = 0; ent < data1->getNumEntities(step0); ent++) {
    if(visible && data1->skipEntity(step0, ent)) continue;
    for(int ele = 0; ele < data1->getNumElements(step0, ent); ele++) {
      if(data1->skipElement(step0, ent, ele, visible)) continue;
      int type = data1->getType(step0, ent, ele);
      const int(*boundary)[6][4];
      if(!getBoundary(type, &boundary)) continue;
      int numCorners =
        ElementType::getNumVertices(ElementType::getType(type, 1));
      if(data1->getNumNodes(step0, ent, ele) < numCorners) continue;
      elements.push_back({ent, ele, type, (int)keys.size()});
      for(int nod = 0; nod < numCorners; nod++)
        keys.push_back(nodeKey(data1, step0, ent, ele, nod, tol));
    }
  }
  if(keys.size() >= 0x7fffffffu) {
    Msg::Error("Too many elements for the Skin plugin");
    return v;
  }

  // their faces (edges in 2D) that no other shares
  typedef std::pair<std::uint32_t, int> bnd; // element, face or edge
  int nthreads = CTX::instance()->numThreadsFor(elements.size(), 10000);
  std::vector<std::vector<bnd> > left(nthreads);
#pragma omp parallel for schedule(static, 1) num_threads(nthreads)
  for(int t = 0; t < nthreads; t++) {
    FaceMatcher<std::uint64_t, std::uint32_t> matcher;
    for(std::size_t i = 0; i < elements.size(); i++) {
      const int(*boundary)[6][4];
      int n = getBoundary(elements[i].type, &boundary);
      const std::uint64_t *k = &keys[elements[i].first];
      std::uint64_t hash[6];
      for(int j = 0; j < n; j++) {
        std::uint64_t key[4] = {0, 0, 0, 0};
        int nc = 0;
        for(int c = 0; c < 4; c++)
          if((*boundary)[j][c] >= 0) key[nc++] = k[(*boundary)[j][c]];
        hash[j] = (matcher.share(key, nc, nthreads) == t) ?
                    matcher.hashOf(key, nc, 0) : 0;
      }
      for(int j = 0; j < n; j++)
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
    const int(*boundary)[6][4];
    getBoundary(e.type, &boundary);
    int nodes[4], numNodes = 0;
    for(int c = 0; c < 4; c++)
      if((*boundary)[b.second][c] >= 0)
        nodes[numNodes++] = (*boundary)[b.second][c];
    int numComp = data1->getNumComponents(step0, e.ent, e.ele);
    int *num = nullptr;
    std::vector<double> *list = getList(data2, numNodes, numComp, &num);
    if(!list) continue;
    (*num)++;
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
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    if(data1->hasTimeStep(i)) data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_Skin");
  data2->setFileName(data1->getName() + "_Skin.pos");
  data2->finalize();

  return v2;
}
