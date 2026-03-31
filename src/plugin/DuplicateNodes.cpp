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

#include <algorithm>

constexpr uint64_t SHIFT = 32LL;

StringXNumber DuplicateNodesOption_Number[] = {
  {GMSH_FULLRC, "Insert quads (0), triangles (1)", nullptr, 0.0},
  {GMSH_FULLRC, "Shrink factor", nullptr, 0.0},
  {GMSH_FULLRC, "TFEM-DG mesh on 1D etities", nullptr, 0.0}};

extern "C" {
GMSH_Plugin *GMSH_RegisterDuplicateNodesPlugin()
{ return new GMSH_DuplicateNodesPlugin(); }
}

std::string GMSH_DuplicateNodesPlugin::getHelp() const
{
  return "This plugin enhances 2D meshes by inserting dummy zero-measure "
         "elements along each edge of every element. This facilitates "
         "straightforward implementation of the discontinuous Galerkin method "
         "(DG) within the tempered finite element method (TFEM) framework, "
         "enabling users to efficiently use DG in FEM-based implementations. "
         "For more information about TFEM-DG, see the companion papers `DG = "
         "FEM + flat elements' (Part I: Diffusion, Part II: Convection).\n"
         "\n"
         "The description of the plugin parameters follows:\n- `Insert quads "
         "(0), "
         "triangles (1)' - The user has the choice between the insertion of a "
         "quadrangle or a pair of triangles along each edge. The type of dummy "
         "elements chosen here does not have to coincide with the type of "
         "elements in the original mesh. Quadrangles can be inserted into a "
         "triangular mesh and vice versa.\n"
         "- `Shrink factor' - This parameter "
         "serves the debugging purposes, should be a real number from the "
         "half-closed interval [0, 1), and describes how much the original "
         "elements are scaled down. For TFEM-DG purposes, the value of this "
         "parameter should be zero. To see the inserted dummy elements while "
         "also keeping the original elements large enough, we recommend "
         "setting this parameter to 0.25.\n"
         "- `TFEM-DG mesh on 1D entities' - "
         "In the original TFEM-DG paper, only 2D dummy elements are inserted. "
         "However, there might be applications in which there is some "
         "computation taking place on the edges of the surfaces. Therefore, we "
         "add this boolean parameter (1 = true, 0 = false) by which it can be "
         "specified whether the dummy elements should also be included in 1D "
         "entities.";
}

int GMSH_DuplicateNodesPlugin::getNbOptions() const
{ return sizeof(DuplicateNodesOption_Number) / sizeof(StringXNumber); }

StringXNumber *GMSH_DuplicateNodesPlugin::getOption(int iopt)
{ return &DuplicateNodesOption_Number[iopt]; }

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

void generateNewVerticesDependingOnShrinkFactorAndCentroid(
  double lam, const std::vector<MVertex *> &vs, std::vector<MVertex *> &nvs,
  GEntity *e)
{
  double cenx = 0.0, ceny = 0.0, cenz = 0.0;

  for(size_t i = 0; i < vs.size(); i++) {
    MVertex *v = vs[i];
    cenx += v->x() / ((double)vs.size());
    ceny += v->y() / ((double)vs.size());
    cenz += v->z() / ((double)vs.size());
  }

  for(size_t i = 0; i < vs.size(); i++) {
    MVertex *v = vs[i];
    nvs.push_back(new MVertex((1.0 - lam) * v->x() + lam * cenx,
                              (1.0 - lam) * v->y() + lam * ceny,
                              (1.0 - lam) * v->z() + lam * cenz, e));
  }
}

uint64_t getEdgeHash(const size_t a, const size_t b)
{ return (a << SHIFT) | b; }

void decryptEdgeHash(const uint64_t edgeHash, size_t &a, size_t &b)
{
  a = (edgeHash >> SHIFT);
  b = edgeHash & ((1LL << SHIFT) - 1);
}

void removeVerticesAndElementsFromEntities(
  GModel *m, const std::vector<GEntity *> &entities)
{
  for(auto e : entities) {
    for(size_t i = 0; i < e->getNumMeshElements(); i++) {
      MElement *el = e->getMeshElement(i);

      std::vector<MVertex *> vs;
      el->getVertices(vs);

      for(size_t j = 0; j < vs.size(); j++) {
        e->removeMeshVertex(vs[j], true);
      }
    }

    e->removeElements(true);
  }

  m->destroyMeshCaches();
}

void insert2DDummyElement(const int elType, const size_t iel, const size_t ioel,
                          MVertex *a, MVertex *b, MVertex *oa, MVertex *ob,
                          std::vector<MElement *> &newElements,
                          std::vector<size_t> &newElementsEntity)
{
  if(elType == 0) // QUADS
  {
    MQuadrangle *q = new MQuadrangle(b, a, oa, ob);
    newElements.push_back(q);
    if(newElementsEntity[iel] == 12) {}
    newElementsEntity.push_back(
      std::max(newElementsEntity[iel], newElementsEntity[ioel]));
  }
  else if(elType == 1) // TRIANGLES
  {
    MTriangle *t1 = new MTriangle(b, a, oa);
    newElements.push_back(t1);
    newElementsEntity.push_back(
      std::max(newElementsEntity[iel], newElementsEntity[ioel]));
    MTriangle *t2 = new MTriangle(oa, ob, b);
    newElements.push_back(t2);
    newElementsEntity.push_back(
      std::max(newElementsEntity[iel], newElementsEntity[ioel]));
  }
}

void handleCornersWhenMeshing1DEntity(
  std::vector<MVertex *> vs, std::vector<MVertex *> nvs, size_t i,
  std::map<size_t, size_t> &nodeNumTo0DEntity, size_t parentNum,
  std::vector<GEntity *> &entities, std::vector<MVertex *> &newNodes,
  std::vector<size_t> &targetEntityOfCopiedNode,
  std::map<size_t, std::vector<MVertex *>> &oneDNodesByNumsOfTheirParents,
  std::map<size_t, size_t> &newNodesNumToLineIndexToWhich1DElementWillBeAdded,
  size_t oneDEntityIndex)
{
  if(!nodeNumTo0DEntity.count(parentNum)) return;
  MVertex *zeroDEntityVertex = new MVertex(
    vs[i]->x(), vs[i]->y(), vs[i]->z(), entities[nodeNumTo0DEntity[parentNum]]);
  newNodes.push_back(zeroDEntityVertex);
  targetEntityOfCopiedNode.push_back(nodeNumTo0DEntity[parentNum]);
  oneDNodesByNumsOfTheirParents[parentNum].push_back(zeroDEntityVertex);
  newNodesNumToLineIndexToWhich1DElementWillBeAdded[zeroDEntityVertex
                                                      ->getNum()] =
    oneDEntityIndex;
}

/*
ELEMENT TYPE:
1 - point
2 - line
3 - triangle
*/

PView *GMSH_DuplicateNodesPlugin::execute(PView *view)
{
  const size_t DNPP_ELTYPETOINSERT = (size_t)DuplicateNodesOption_Number[0].def;
  const double DNPP_SHRINK = DuplicateNodesOption_Number[1].def;
  const bool DNPP_MESH1DENT = (bool)DuplicateNodesOption_Number[2].def;

  Msg::Info("Insert quads (0), triangles (1): %d", DNPP_ELTYPETOINSERT);
  Msg::Info("Shrink factor parameter: %f", DNPP_SHRINK);
  Msg::Info("TFEM-DG mesh 1D entities: %s", DNPP_MESH1DENT ? "true" : "false");

  GModel *m = GModel::current();

  std::vector<GEntity *> entities;
  m->getEntities(entities);

  // std::vector<std::pair<int, int>> lineDimTags;
  // for(size_t i = 0; i < entities.size(); i++) {
  //   GEntity *e = entities[i];
  //   if(e->dim() != 1) continue;

  //   lineDimTags.emplace_back(1, e->tag());
  // }

  // std::vector<std::pair<int, int>> boundaryDimTags;
  // m->getBoundaryTags(lineDimTags, boundaryDimTags, false);

  // for(size_t i = 0; i < lineDimTags.size(); i++) {
  //   Msg::Info("line: %d %d", lineDimTags[i].first, lineDimTags[i].second);
  // }

  // for(size_t i = 0; i < boundaryDimTags.size(); i++) {
  //   Msg::Info("boundary: %d %d", boundaryDimTags[i].first,
  //             boundaryDimTags[i].second);
  // }

  // return view;

  std::vector<MVertex *> newNodes;
  std::vector<size_t> newNodesEntity;
  std::vector<MElement *> newElements;
  std::vector<size_t> newElementsEntity;
  std::map<uint64_t, size_t> edgeHashToElementIndex;
  std::map<size_t, size_t> parentVertexNum;
  std::map<uint64_t, size_t> edgeHashTo1DElementNum;
  std::map<size_t, std::vector<size_t>>
    neighboringSurfacesOf1DElements; // 1D elem by num, entity by index
  std::map<size_t, size_t> oneDElementNumToLineIndex;
  std::map<size_t, std::vector<MVertex *>> oneDNodesByNumsOfTheirParents;
  std::map<size_t, size_t> nodeNumTo0DEntity;
  std::map<size_t, size_t> newNodesNumToLineIndexToWhich1DElementWillBeAdded;

  // Fill nodeNumTo0DEntity datastructure
  for(size_t ie = 0; ie < entities.size(); ie++) {
    GEntity *e = entities[ie];
    if(e->dim() != 0) continue;
    for(size_t i = 0; i < e->mesh_vertices.size(); i++) {
      nodeNumTo0DEntity[e->mesh_vertices[i]->getNum()] = ie;
    }
  }

  // Fill edgeHashTo1DElementNum datastructure
  //  and oneDElementNumToLineIndex
  for(size_t ie = 0; ie < entities.size(); ie++) {
    GEntity *e = entities[ie];
    if(e->dim() != 1) continue;

    for(size_t iel = 0; iel < e->getNumMeshElements(); iel++) {
      MElement *el = e->getMeshElement(iel);

      oneDElementNumToLineIndex[el->getNum()] = ie;

      std::vector<MVertex *> vs;
      el->getVertices(vs);

      std::vector<size_t> ivs;
      for(size_t i = 0; i < vs.size(); i++) { ivs.push_back(vs[i]->getNum()); }

      for(size_t i = 0; i < ivs.size(); i++) {
        const size_t a = ivs[i], b = ivs[(i + 1) % ivs.size()];
        uint64_t hash = getEdgeHash(a, b);
        uint64_t dualHash = getEdgeHash(b, a);
        edgeHashTo1DElementNum[hash] = el->getNum();
        edgeHashTo1DElementNum[dualHash] = el->getNum();
      }
    }
  }

  // Fill neighboringSurfacesTo1DElements datastructure
  for(size_t ie = 0; ie < entities.size(); ie++) {
    GEntity *e = entities[ie];
    if(e->dim() != 2) continue;

    for(size_t iel = 0; iel < e->getNumMeshElements(); iel++) {
      MElement *el = e->getMeshElement(iel);

      std::vector<MVertex *> vs;
      el->getVertices(vs);

      std::vector<size_t> ivs;
      for(size_t i = 0; i < vs.size(); i++) { ivs.push_back(vs[i]->getNum()); }

      for(size_t i = 0; i < ivs.size(); i++) {
        const size_t a = ivs[i], b = ivs[(i + 1) % ivs.size()];
        uint64_t hash = getEdgeHash(a, b);

        if(edgeHashTo1DElementNum.count(hash)) {
          neighboringSurfacesOf1DElements[edgeHashTo1DElementNum[hash]]
            .push_back(ie);
        }
      }
    }
  }

  for(size_t ie = 0; ie < entities.size(); ie++) {
    GEntity *e = entities[ie];
    if(e->dim() != 2) continue;

    for(size_t iel = 0; iel < e->getNumMeshElements(); iel++) {
      MElement *el = e->getMeshElement(iel);

      std::vector<MVertex *> vs;
      el->getVertices(vs);
      std::vector<MVertex *> nvs;
      generateNewVerticesDependingOnShrinkFactorAndCentroid(DNPP_SHRINK, vs,
                                                            nvs, e);

      for(size_t i = 0; i < nvs.size(); i++) { newNodes.push_back(nvs[i]); }

      MElement *nel;
      if(nvs.size() == 3) { nel = new MTriangle(nvs[0], nvs[1], nvs[2]); }
      else if(nvs.size() == 4) {
        nel = new MQuadrangle(nvs[0], nvs[1], nvs[2], nvs[3]);
      }
      else {
        Msg::Error("The mesh contains 2D element which is not triangle nor "
                   "quadrangle.");
        return view;
      }
      newElements.push_back(nel);
      newElementsEntity.push_back(ie);
      const size_t newFullMeasureElementIndex = newElements.size() - 1;

      std::vector<size_t> nums_vs;
      for(size_t i = 0; i < vs.size(); i++) {
        nums_vs.push_back(vs[i]->getNum());
      }

      for(size_t i = 0; i < nvs.size(); i++) {
        parentVertexNum[nvs[i]->getNum()] = nums_vs[i];
      }

      std::vector<size_t> targetEntityOfCopiedNode(nvs.size(), ie);
      for(size_t i = 0; i < nums_vs.size(); i++) {
        const size_t ia = i, ib = (i + 1) % nums_vs.size();
        const size_t a = nums_vs[ia], b = nums_vs[ib];
        uint64_t hash = getEdgeHash(a, b);
        edgeHashToElementIndex[hash] = newFullMeasureElementIndex;

        if(edgeHashTo1DElementNum.count(hash)) {
          size_t num1DElement = edgeHashTo1DElementNum[hash];
          const auto &surfaces = neighboringSurfacesOf1DElements[num1DElement];

          if(surfaces.size() == 1) {
            // Boundary --> add 1D element and dummy element
            const size_t oneDEntityIndex =
              oneDElementNumToLineIndex[num1DElement];

            std::vector<MVertex *> oneDvs = {vs[ia], vs[ib]};
            std::vector<MVertex *> oneDnvs;

            generateNewVerticesDependingOnShrinkFactorAndCentroid(
              DNPP_SHRINK, oneDvs, oneDnvs, entities[oneDEntityIndex]);

            MVertex *oa = oneDnvs[0];
            MVertex *ob = oneDnvs[1];

            newNodes.push_back(oa);
            newNodes.push_back(ob);

            targetEntityOfCopiedNode.push_back(oneDEntityIndex);
            targetEntityOfCopiedNode.push_back(oneDEntityIndex);

            if(DNPP_MESH1DENT) {
              oneDNodesByNumsOfTheirParents[parentVertexNum[nvs[ia]->getNum()]]
                .push_back(oa);
              oneDNodesByNumsOfTheirParents[parentVertexNum[nvs[ib]->getNum()]]
                .push_back(ob);

              newNodesNumToLineIndexToWhich1DElementWillBeAdded[oa->getNum()] =
                oneDEntityIndex;
              newNodesNumToLineIndexToWhich1DElementWillBeAdded[ob->getNum()] =
                oneDEntityIndex;

              handleCornersWhenMeshing1DEntity(
                vs, nvs, ia, nodeNumTo0DEntity,
                parentVertexNum[nvs[ia]->getNum()], entities, newNodes,
                targetEntityOfCopiedNode, oneDNodesByNumsOfTheirParents,
                newNodesNumToLineIndexToWhich1DElementWillBeAdded,
                oneDEntityIndex);

              handleCornersWhenMeshing1DEntity(
                vs, nvs, ib, nodeNumTo0DEntity,
                parentVertexNum[nvs[ib]->getNum()], entities, newNodes,
                targetEntityOfCopiedNode, oneDNodesByNumsOfTheirParents,
                newNodesNumToLineIndexToWhich1DElementWillBeAdded,
                oneDEntityIndex);
            }

            newElements.push_back(new MLine(oa, ob));
            newElementsEntity.push_back(oneDEntityIndex);

            insert2DDummyElement(DNPP_ELTYPETOINSERT,
                                 newFullMeasureElementIndex,
                                 newElements.size() - 1, nvs[ia], nvs[ib], oa,
                                 ob, newElements, newElementsEntity);

            continue;
          }

          if(surfaces.size() == 2) {
            // Inner edge (line, 1D entity) --> one side of the 2D element will
            // be also 1D element; which one of the two elements will be chosen
            // is decided by the surface tag <-- the 2D element in the surface
            // with lesser tag will contain the 1D element
            if(*std::min_element(surfaces.begin(), surfaces.end()) != ie)
              continue;

            size_t oneDEntityIndex = oneDElementNumToLineIndex[num1DElement];
            targetEntityOfCopiedNode[ia] = oneDEntityIndex;
            targetEntityOfCopiedNode[ib] = oneDEntityIndex;
            newElements.push_back(new MLine(nvs[ia], nvs[ib]));
            newElementsEntity.push_back(oneDEntityIndex);

            if(!DNPP_MESH1DENT) continue;
            oneDNodesByNumsOfTheirParents[parentVertexNum[nvs[ia]->getNum()]]
              .push_back(nvs[ia]);
            oneDNodesByNumsOfTheirParents[parentVertexNum[nvs[ib]->getNum()]]
              .push_back(nvs[ib]);

            newNodesNumToLineIndexToWhich1DElementWillBeAdded[nvs[ia]
                                                                ->getNum()] =
              oneDEntityIndex;
            newNodesNumToLineIndexToWhich1DElementWillBeAdded[nvs[ib]
                                                                ->getNum()] =
              oneDEntityIndex;

            handleCornersWhenMeshing1DEntity(
              vs, nvs, ia, nodeNumTo0DEntity,
              parentVertexNum[nvs[ia]->getNum()], entities, newNodes,
              targetEntityOfCopiedNode, oneDNodesByNumsOfTheirParents,
              newNodesNumToLineIndexToWhich1DElementWillBeAdded,
              oneDEntityIndex);

            handleCornersWhenMeshing1DEntity(
              vs, nvs, ib, nodeNumTo0DEntity,
              parentVertexNum[nvs[ib]->getNum()], entities, newNodes,
              targetEntityOfCopiedNode, oneDNodesByNumsOfTheirParents,
              newNodesNumToLineIndexToWhich1DElementWillBeAdded,
              oneDEntityIndex);

            continue;
          }

          Msg::Error(
            "There is a 1D element that has more than 2 neighboring surfaces.");
          return view;
        }
      }

      for(size_t i = 0; i < targetEntityOfCopiedNode.size(); i++) {
        newNodesEntity.push_back(targetEntityOfCopiedNode[i]);
      }
    }
  }

  if(DNPP_MESH1DENT) {
    for(const auto &[parentNum, vs] : oneDNodesByNumsOfTheirParents) {
      for(size_t i = 0; i < vs.size() - 1; i++) {
        for(size_t j = i + 1; j < vs.size(); j++) {
          MVertex *a = vs[i], *b = vs[j];
          size_t aLine =
            newNodesNumToLineIndexToWhich1DElementWillBeAdded[a->getNum()];
          size_t bLine =
            newNodesNumToLineIndexToWhich1DElementWillBeAdded[b->getNum()];
          if(aLine != bLine) continue;

          newElements.push_back(new MLine(a, b));
          newElementsEntity.push_back(aLine);
        }
      }
    }
  }

  removeVerticesAndElementsFromEntities(m, entities);

  std::map<uint64_t, bool> edgeVisited;
  // Iterate through edges within the entity
  for(auto &[edgeHash, iel] : edgeHashToElementIndex) {
    // Check whether this edge was already processed
    if(edgeVisited.count(edgeHash)) continue;
    edgeVisited[edgeHash] = true;
    size_t ia, ib;
    decryptEdgeHash(edgeHash, ia, ib);
    uint64_t dualHash = getEdgeHash(ib, ia);
    if(!edgeHashToElementIndex.count(dualHash)) continue;
    edgeVisited[dualHash] = true;
    const size_t ioel = edgeHashToElementIndex[dualHash];

    // Find, which vertices (from the set of newly added ones) need to be
    // connected
    size_t iael = -1, ibel = -1, iaoel = -1, iboel = -1;

    std::vector<MVertex *> elv;
    newElements[iel]->getVertices(elv);
    for(size_t i = 0; i < elv.size(); i++) {
      auto v = elv[i];
      auto vNum = v->getNum();
      if(parentVertexNum[vNum] == ia) {
        iael = i;
        continue;
      }
      if(parentVertexNum[vNum] == ib) {
        ibel = i;
        continue;
      }
    }
    std::vector<MVertex *> oelv;
    newElements[ioel]->getVertices(oelv);
    for(size_t i = 0; i < oelv.size(); i++) {
      auto v = oelv[i];
      auto vNum = v->getNum();
      if(parentVertexNum[vNum] == ia) {
        iaoel = i;
        continue;
      }
      if(parentVertexNum[vNum] == ib) {
        iboel = i;
        continue;
      }
    }

    // Add the quad or triangle
    MVertex *a, *b, *oa, *ob;
    a = newElements[iel]->getVertex(iael);
    b = newElements[iel]->getVertex(ibel);
    oa = newElements[ioel]->getVertex(iaoel);
    ob = newElements[ioel]->getVertex(iboel);

    insert2DDummyElement(DNPP_ELTYPETOINSERT, iel, ioel, a, b, oa, ob,
                         newElements, newElementsEntity);
  }

  for(size_t iv = 0; iv < newNodes.size(); iv++) {
    MVertex *v = newNodes[iv];
    entities[newNodesEntity[iv]]->addMeshVertex(v);
  }

  for(size_t iel = 0; iel < newElements.size(); iel++) {
    MElement *el = newElements[iel];
    entities[newElementsEntity[iel]]->addElement(el);
  }

  m->destroyMeshCaches();
  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}