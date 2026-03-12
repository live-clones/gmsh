// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Erik Schnaubelt
//   Louis Denis

#include "DuplicateNodes.h"
#include "GModel.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MEdge.h"
#include "Context.h"

#include "FlGui.h"

// StringXNumber DuplicateNodesOption_Number[] = {
//   {GMSH_FULLRC, "Dimension", nullptr, 1.},
//   {GMSH_FULLRC, "PhysicalGroup", nullptr, 1.},
//   {GMSH_FULLRC, "OpenBoundaryPhysicalGroup", nullptr, 0.},
//   {GMSH_FULLRC, "NormalX", nullptr, 0.},
//   {GMSH_FULLRC, "NormalY", nullptr, 0.},
//   {GMSH_FULLRC, "NormalZ", nullptr, 1.},
//   {GMSH_FULLRC, "NewPhysicalGroup", nullptr, 0},
//   {GMSH_FULLRC, "DebugView", nullptr, 0},
//   {GMSH_FULLRC, "SwapOrientation", nullptr, 0}};

constexpr uint64_t SHIFT = 32LL;

StringXNumber DuplicateNodesOption_Number[] = {
  {GMSH_FULLRC, "Insert quads (0), triangles (1)", nullptr, 0.0},
  {GMSH_FULLRC, "Shrink factor", nullptr, 0.25}};

extern "C" {
GMSH_Plugin *GMSH_RegisterDuplicateNodesPlugin()
{
  return new GMSH_DuplicateNodesPlugin();
}
}

std::string GMSH_DuplicateNodesPlugin::getHelp() const
{
  return "Plugin(Crack) creates a crack around the orientable, "
         "manifold physical group `PhysicalGroup' of dimension "
         "`Dimension' (1 or 2), embedded in a mesh of dimension "
         "`Dimension' + 1."
         "The plugin duplicates the nodes and the elements on "
         "the crack and stores them in a new discrete curve "
         "(`Dimension' = 1) or surface (`Dimension' = 2). The "
         "elements touching the crack on the positive side "
         "are modified to use the newly generated nodes."
         "If `OpenBoundaryPhysicalGroup' is given (> 0), its "
         "nodes are duplicated and the crack will be left "
         "open on that (part of the) boundary. Otherwise, the "
         "lips of the crack are sealed, i.e., its nodes are "
         "not duplicated. For 1D cracks, `NormalX', `NormalY' and "
         "`NormalZ' provide the reference normal of the surface "
         "in which the crack is supposed to be embedded. If "
         "`NewPhysicalGroup' is positive, use it as the tag of "
         "the newly created curve or surface; otherwise use "
         "`PhysicalGroup'. If `SwapOrientation' is set to 1, "
         "the orientation of the duplicated elements on the "
         "crack is reversed.";
}

int GMSH_DuplicateNodesPlugin::getNbOptions() const
{
  return sizeof(DuplicateNodesOption_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DuplicateNodesPlugin::getOption(int iopt)
{
  return &DuplicateNodesOption_Number[iopt];
}

class EdgeData {
public:
  EdgeData(MEdge e) : edge(e) {}
  MEdge edge;
  std::vector<MVertex *> data;
};

struct MEdgeDataLessThan {
  bool operator()(const EdgeData &e1, const EdgeData &e2) const
  {
    if(e1.edge.getMinVertex() < e2.edge.getMinVertex()) return true;
    if(e1.edge.getMinVertex() > e2.edge.getMinVertex()) return false;
    if(e1.edge.getMaxVertex() < e2.edge.getMaxVertex()) return true;
    return false;
  }
};

/*
ELEMENT TYPE:
1 - point
2 - line
3 - triangle
*/

PView *GMSH_DuplicateNodesPlugin::execute(PView *view)
{
  size_t DNPP_ELTYPETOINSERT = (size_t)DuplicateNodesOption_Number[0].def;
  double DNPP_SHRINK = DuplicateNodesOption_Number[1].def;

  Msg::Info("Insert quads (0), triangles (1): %d", DNPP_ELTYPETOINSERT);
  Msg::Info("Shrink factor parameter: %f", DNPP_SHRINK);

  GModel *m = GModel::current();

  std::vector<GEntity *> entities;
  m->getEntities(entities);

  // m->getBoundaryTags()

  std::map<size_t, std::vector<MVertex *>> newNodes;
  std::map<size_t, std::vector<MElement *>> newElements;
  std::map<size_t, std::map<uint64_t, size_t>> edgeToElement;
  std::map<size_t, size_t> parentVertex;

  for(size_t ie = 0; ie < entities.size(); ie++) {
    GEntity *e = entities[ie];
    if(e->dim() != 2) continue;

    for(size_t iel = 0; iel < e->getNumMeshElements(); iel++) {
      MElement *el = e->getMeshElement(iel);

      std::vector<MVertex *> vs;
      el->getVertices(vs);

      double cenx = 0.0, ceny = 0.0, cenz = 0.0;
      for(size_t i = 0; i < vs.size(); i++) {
        MVertex *v = vs[i];
        cenx += v->x() / ((double)vs.size());
        ceny += v->y() / ((double)vs.size());
        cenz += v->z() / ((double)vs.size());
      }

      std::vector<MVertex *> nvs;
      double lam = DNPP_SHRINK;

      for(size_t i = 0; i < vs.size(); i++) {
        MVertex *v = vs[i];
        nvs.push_back(new MVertex((1.0 - lam) * v->x() + lam * cenx,
                                  (1.0 - lam) * v->y() + lam * ceny,
                                  (1.0 - lam) * v->z() + lam * cenz, e));
      }

      for(size_t i = 0; i < nvs.size(); i++) { newNodes[ie].push_back(nvs[i]); }

      MElement *nel;
      if(nvs.size() == 3) { nel = new MTriangle(nvs[0], nvs[1], nvs[2]); }
      else if(nvs.size() == 4) {
        nel = new MQuadrangle(nvs[0], nvs[1], nvs[2], nvs[3]);
      }
      else {
        Msg::Error(
          "The mesh contains 2D element which is not triangle nor quadrangle.");
        return view;
      }
      newElements[ie].push_back(nel);

      std::vector<size_t> ivs;
      for(size_t i = 0; i < vs.size(); i++) { ivs.push_back(vs[i]->getNum()); }

      for(size_t i = 0; i < ivs.size(); i++) {
        edgeToElement[ie][(ivs[i] << SHIFT) | ivs[(i + 1) % ivs.size()]] =
          newElements[ie].size() - 1;
      }

      for(size_t i = 0; i < nvs.size(); i++) {
        parentVertex[nvs[i]->getNum()] = ivs[i];
      }
    }
  }

  for(auto e : entities) {
    if(e->dim() != 2) continue;

    for(size_t i = 0; i < e->getNumMeshElements(); i++) {
      MElement *el = e->getMeshElement(i);

      std::vector<MVertex *> vs;
      el->getVertices(vs);

      for(size_t i = 0; i < vs.size(); i++) {
        e->removeMeshVertex(vs[i], true);
      }
    }

    e->removeElements(true);
  }

  m->destroyMeshCaches();

  std::map<uint64_t, bool> edgeVisited;
  for(size_t ie = 0; ie < entities.size(); ie++) {
    if(entities[ie]->dim() != 2) continue;
    for(auto &[edgeHash, iel] : edgeToElement[ie]) {
      if(edgeVisited.count(edgeHash)) continue;
      edgeVisited[edgeHash] = true;

      size_t ia, ib;
      ib = edgeHash & ((1LL << SHIFT) - 1);
      ia = (edgeHash >> SHIFT);

      uint64_t dualHash = (ib << SHIFT) | ia;
      if(!edgeToElement[ie].count(dualHash)) continue;
      edgeVisited[dualHash] = true;
      const size_t ioel = edgeToElement[ie][dualHash];

      size_t iael = -1, ibel = -1, iaoel = -1, iboel = -1;
      std::vector<MVertex *> elv;
      newElements[ie][iel]->getVertices(elv);
      for(size_t i = 0; i < elv.size(); i++) {
        auto v = elv[i];
        auto vNum = v->getNum();
        if(parentVertex[vNum] == ia) {
          iael = i;
          continue;
        }
        if(parentVertex[vNum] == ib) {
          ibel = i;
          continue;
        }
      }
      std::vector<MVertex *> oelv;
      newElements[ie][ioel]->getVertices(oelv);
      for(size_t i = 0; i < oelv.size(); i++) {
        auto v = oelv[i];
        auto vNum = v->getNum();
        if(parentVertex[vNum] == ia) {
          iaoel = i;
          continue;
        }
        if(parentVertex[vNum] == ib) {
          iboel = i;
          continue;
        }
      }

      MVertex *a, *b, *oa, *ob;
      a = newElements[ie][iel]->getVertex(iael);
      b = newElements[ie][iel]->getVertex(ibel);
      oa = newElements[ie][ioel]->getVertex(iaoel);
      ob = newElements[ie][ioel]->getVertex(iboel);

      if(DNPP_ELTYPETOINSERT == 0) // QUADS
      {
        MQuadrangle *q = new MQuadrangle(b, a, oa, ob);
        newElements[ie].push_back(q);
      }
      else if(DNPP_ELTYPETOINSERT == 1) // TRIANGLES
      {
        MTriangle *nel1 = new MTriangle(b, a, oa);
        newElements[ie].push_back(nel1);
        MTriangle *nel2 = new MTriangle(oa, ob, b);
        newElements[ie].push_back(nel2);
      }
    }
  }

  for(size_t ie = 0; ie < entities.size(); ie++) {
    GEntity *e = entities[ie];
    if(e->dim() != 2) continue;

    if(!newNodes.count(ie)) continue;
    for(size_t iv = 0; iv < newNodes[ie].size(); iv++) {
      MVertex *v = newNodes[ie][iv];
      e->addMeshVertex(v);
    }

    if(!newElements.count(ie)) continue;
    for(size_t iel = 0; iel < newElements[ie].size(); iel++) {
      MElement *el = newElements[ie][iel];
      e->addElement(el);
    }
  }

  m->destroyMeshCaches();
  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}