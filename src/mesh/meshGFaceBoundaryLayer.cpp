// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <set>
#include <vector>
#include "GmshMessage.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "discreteEdge.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MEdge.h"
#include "OS.h"
#include "Context.h"
#include "boundaryLayersData.h"
#include "filterElements.h"
#include "meshGFace.h"
#include "meshGFaceInternal.h"
#include "meshGFaceBoundaryLayer.h"

static void addOrRemove(MVertex *v1, MVertex *v2,
                        std::set<MEdge, MEdgeLessThan> &bedges,
                        std::set<MEdge, MEdgeLessThan> &removed)
{
  MEdge e(v1, v2);
  if(removed.find(e) != removed.end()) return;
  auto it = bedges.find(e);
  if(it == bedges.end())
    bedges.insert(e);
  else {
    bedges.erase(it);
    removed.insert(e);
  }
}

void modifyInitialMeshForBoundaryLayers(
  GFace *gf, std::vector<MQuadrangle *> &blQuads,
  std::vector<MTriangle *> &blTris,
  std::set<MVertex *, MVertexPtrLessThan> &verts, bool debug)
{
  if(!buildAdditionalPoints2D(gf)) return;
  BoundaryLayerColumns *_columns = gf->getColumns();

  std::set<MEdge, MEdgeLessThan> bedges;
  std::set<MEdge, MEdgeLessThan> removed;

  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> embedded_edges = gf->getEmbeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(), embedded_edges.end());
  auto ite = edges.begin();

  FILE *ff2 = nullptr;
  if(debug) ff2 = Fopen("tato.pos", "w");
  if(ff2) fprintf(ff2, "View \" \"{\n");

  std::vector<MLine *> _lines;

  while(ite != edges.end()) {
    for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
      _lines.push_back((*ite)->lines[i]);
      MVertex *v1 = (*ite)->lines[i]->getVertex(0);
      MVertex *v2 = (*ite)->lines[i]->getVertex(1);
      MEdge dv(v1, v2);
      addOrRemove(v1, v2, bedges, removed);
      for(std::size_t SIDE = 0; SIDE < _columns->_normals.count(dv); SIDE++) {
        std::vector<MElement *> myCol;
        edgeColumn ec = _columns->getColumns(v1, v2, SIDE);
        const BoundaryLayerData &c1 = ec._c1;
        const BoundaryLayerData &c2 = ec._c2;
        int N = std::min(c1._column.size(), c2._column.size());
        if(!N) continue;

        for(int l = 0; l < N; ++l) {
          MVertex *v11 = nullptr, *v12 = nullptr, *v21 = nullptr,
                  *v22 = nullptr;
          v21 = c1._column[l];
          v22 = c2._column[l];
          if(l == 0) {
            v11 = v1;
            v12 = v2;
          }
          else {
            v11 = c1._column[l - 1];
            v12 = c2._column[l - 1];
          }

          MQuadrangle *qq = new MQuadrangle(v11, v21, v22, v12);
          qq->setPartition(l + 1);
          myCol.push_back(qq);
          blQuads.push_back(qq);

          if(ff2)
            fprintf(ff2,
                    "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                    v11->x(), v11->y(), v11->z(), v12->x(), v12->y(), v12->z(),
                    v22->x(), v22->y(), v22->z(), v21->x(), v21->y(), v21->z(),
                    l + 1, l + 1, l + 1, l + 1);
        }

        if(c1._column.size() != c2._column.size()) {
          MVertex *v11 = nullptr, *v12 = nullptr, *v = nullptr;
          v11 = c1._column[N - 1];
          v12 = c2._column[N - 1];
          v = c1._column.size() > c2._column.size() ? c1._column[N] :
                                                      c2._column[N];
          MTriangle *qq = new MTriangle(v11, v12, v);
          qq->setPartition(N + 1);
          myCol.push_back(qq);
          blTris.push_back(qq);
          if(ff2)
            fprintf(ff2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                    v11->x(), v11->y(), v11->z(), v12->x(), v12->y(), v12->z(),
                    v->x(), v->y(), v->z(), N + 1, N + 1, N + 1);
        }

        for(std::size_t l = 0; l < myCol.size(); l++)
          _columns->_toFirst[myCol[l]] = myCol[0];
        _columns->_elemColumns[myCol[0]] = myCol;
      }
    }
    ++ite;
  }

  for(auto itf = _columns->beginf(); itf != _columns->endf(); ++itf) {
    MVertex *v = itf->first;
    int nbCol = _columns->getNbColumns(v);
    int fanType = itf->second.type;

    if(fanType == -1) { // fan

      for(int i = 0; i < nbCol - 1; i++) {
        const BoundaryLayerData &c1 = _columns->getColumn(v, i);
        const BoundaryLayerData &c2 = _columns->getColumn(v, i + 1);
        int N = std::min(c1._column.size(), c2._column.size());
        std::vector<MElement *> myCol;
        for(int l = 0; l < N; ++l) {
          MVertex *v11 = nullptr, *v12 = nullptr, *v21 = nullptr,
                  *v22 = nullptr;
          v21 = c1._column[l];
          v22 = c2._column[l];
          if(l == 0) {
            v11 = v;
            v12 = v;
          }
          else {
            v11 = c1._column[l - 1];
            v12 = c2._column[l - 1];
          }
          if(v11 != v12) {
            MQuadrangle *qq = new MQuadrangle(v11, v12, v22, v21);
            qq->setPartition(l + 1);
            myCol.push_back(qq);
            blQuads.push_back(qq);

            if(ff2)
              fprintf(ff2,
                      "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                      v11->x(), v11->y(), v11->z(), v12->x(), v12->y(),
                      v12->z(), v22->x(), v22->y(), v22->z(), v21->x(),
                      v21->y(), v21->z(), l + 1, l + 1, l + 1, l + 1);
          }
          else {
            MTriangle *qq = new MTriangle(v, v22, v21);
            qq->setPartition(l + 1);
            myCol.push_back(qq);
            blTris.push_back(qq);
            if(ff2)
              fprintf(ff2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                      v->x(), v->y(), v->z(), v22->x(), v22->y(), v22->z(),
                      v21->x(), v21->y(), v21->z(), l + 1, l + 1, l + 1);
          }
        }
        if(myCol.size()) {
          for(std::size_t l = 0; l < myCol.size(); l++)
            _columns->_toFirst[myCol[l]] = myCol[0];
          _columns->_elemColumns[myCol[0]] = myCol;
        }
      }
    }
    else if(fanType == 1) { // cross

      const BoundaryLayerData &c1 = _columns->getColumn(v, 0);
      int N = c1._column.size();
      nbCol = N + 1;

      const BoundaryLayerData &cl = _columns->getColumn(v, nbCol);
      for(int i = 0; i < nbCol - 1; i++) {
        const BoundaryLayerData &c1 = _columns->getColumn(v, i);
        const BoundaryLayerData &c2 = _columns->getColumn(v, i + 1);
        int N = std::min(c1._column.size(), c2._column.size());
        std::vector<MElement *> myCol;
        MVertex *v11 = nullptr, *v12 = nullptr, *v21 = nullptr, *v22 = nullptr;
        for(int l = 0; l < N; ++l) {
          if(l == 0) {
            if(i == 0) { v11 = v; }
            else {
              v11 = cl._column[i - 1];
            }
            v12 = cl._column[i];
          }
          else {
            v11 = v21;
            v12 = v22;
          }
          v21 = c1._column[l];
          v22 = c2._column[l];

          MQuadrangle *qq = new MQuadrangle(v11, v12, v22, v21);
          qq->setPartition(l + 1);
          myCol.push_back(qq);
          blQuads.push_back(qq);
        }

        if(myCol.size()) {
          for(std::size_t l = 0; l < myCol.size(); l++)
            _columns->_toFirst[myCol[l]] = myCol[0];
          _columns->_elemColumns[myCol[0]] = myCol;
        }
      }
    }
    else if(fanType == 2) { // mix

      const BoundaryLayerData &c1 = _columns->getColumn(v, 0);
      int N = c1._column.size();
      nbCol = N + 1;
      int cp = (N - 1) / 2 + 1;

      const BoundaryLayerData &cl = _columns->getColumn(v, nbCol);
      for(int i = 0; i < nbCol - 1; i++) {
        const BoundaryLayerData &c1 = _columns->getColumn(v, i);
        const BoundaryLayerData &c2 = _columns->getColumn(v, i + 1);
        int N = std::min(c1._column.size(), c2._column.size());
        std::vector<MElement *> myCol;
        MVertex *v11 = nullptr, *v12 = nullptr, *v21 = nullptr, *v22 = nullptr;
        for(int l = 0; l < N; ++l) {
          if(i >= cp && l >= cp) continue;

          if(l == 0) {
            if(i == 0) { v11 = v; }
            else {
              v11 = cl._column[i - 1];
            }
            v12 = cl._column[i];
          }
          else {
            v11 = v21;
            v12 = v22;
          }

          if(l == cp - 1 && i >= cp) {
            const BoundaryLayerData &cc = _columns->getColumn(v, cp);
            v21 = cc._column[i - 1];
            v22 = cc._column[i];
          }
          else {
            v21 = c1._column[l];
            v22 = c2._column[l];
          }

          MQuadrangle *qq = new MQuadrangle(v11, v12, v22, v21);
          qq->setPartition(l + 1);
          myCol.push_back(qq);
          blQuads.push_back(qq);
        }

        if(myCol.size()) {
          for(std::size_t l = 0; l < myCol.size(); l++)
            _columns->_toFirst[myCol[l]] = myCol[0];
          _columns->_elemColumns[myCol[0]] = myCol;
        }
      }
    }
    else if(fanType == 3) { // tail

      const int dir_half = nbCol / 2 + 1;
      const BoundaryLayerData &c1 = _columns->getColumn(v, 0);
      const int N = c1._column.size();
      const BoundaryLayerData &cc = _columns->getColumn(v, 1);
      const int NN = cc._column.size();

      for(int i = 0; i < NN; i++) {
        std::vector<MElement *> myCol;

        for(int l = 0; l < N; l++) {
          MVertex *v11 = nullptr, *v12 = nullptr, *v21 = nullptr,
                  *v22 = nullptr;
          int k = dir_half - l - 1;
          const BoundaryLayerData &c2 = _columns->getColumn(v, k);
          const BoundaryLayerData &c3 = _columns->getColumn(v, k - 1);

          if(i == 0) {
            if(l == 0) { v11 = v; }
            else {
              v11 = c1._column[l - 1];
            }
            v21 = c1._column[l];
          }
          else {
            v11 = c2._column[i - 1];
            v21 = c3._column[i - 1];
          }

          v12 = c2._column[i];
          v22 = c3._column[i];

          if(v11 != v12) {
            MQuadrangle *qq = new MQuadrangle(v11, v12, v22, v21);
            qq->setPartition(l + 1);
            myCol.push_back(qq);
            blQuads.push_back(qq);
            if(ff2)
              fprintf(ff2,
                      "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                      v11->x(), v11->y(), v11->z(), v12->x(), v12->y(),
                      v12->z(), v22->x(), v22->y(), v22->z(), v21->x(),
                      v21->y(), v21->z(), l + 1, l + 1, l + 1, l + 1);
          }
          else {
            MTriangle *qq = new MTriangle(v, v22, v21);
            qq->setPartition(l + 1);
            myCol.push_back(qq);
            blTris.push_back(qq);
            if(ff2)
              fprintf(ff2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                      v->x(), v->y(), v->z(), v22->x(), v22->y(), v22->z(),
                      v21->x(), v21->y(), v21->z(), l + 1, l + 1, l + 1);
          }

        } // l

        if(myCol.size()) {
          for(std::size_t l = 0; l < myCol.size(); l++)
            _columns->_toFirst[myCol[l]] = myCol[0];
          _columns->_elemColumns[myCol[0]] = myCol;
        }

      } // i

      const BoundaryLayerData &cn = _columns->getColumn(v, nbCol - 1);

      for(int i = 0; i < NN; i++) {
        std::vector<MElement *> myCol;

        for(int l = 0; l < N; l++) {
          MVertex *v11 = nullptr, *v12 = nullptr, *v21 = nullptr,
                  *v22 = nullptr;

          int k = dir_half + l - 1;

          const BoundaryLayerData &c2 = _columns->getColumn(v, k);
          const BoundaryLayerData &c3 = _columns->getColumn(v, k + 1);

          if(i == 0) {
            if(l == 0) { v11 = v; }
            else {
              v11 = cn._column[l - 1];
            }
            v21 = cn._column[l];
          }
          else {
            v11 = c2._column[i - 1];
            v21 = c3._column[i - 1];
          }

          v12 = c2._column[i];
          v22 = c3._column[i];

          if(v11 != v12) {
            MQuadrangle *qq = new MQuadrangle(v11, v12, v22, v21);
            qq->setPartition(l + 1);
            myCol.push_back(qq);
            blQuads.push_back(qq);
            if(ff2)
              fprintf(ff2,
                      "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                      v11->x(), v11->y(), v11->z(), v12->x(), v12->y(),
                      v12->z(), v22->x(), v22->y(), v22->z(), v21->x(),
                      v21->y(), v21->z(), l + 1, l + 1, l + 1, l + 1);
          }
          else {
            MTriangle *qq = new MTriangle(v, v22, v21);
            qq->setPartition(l + 1);
            myCol.push_back(qq);
            blTris.push_back(qq);
            if(ff2)
              fprintf(ff2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                      v->x(), v->y(), v->z(), v22->x(), v22->y(), v22->z(),
                      v21->x(), v21->y(), v21->z(), l + 1, l + 1, l + 1);
          }

        } // l

        if(myCol.size()) {
          for(std::size_t l = 0; l < myCol.size(); l++)
            _columns->_toFirst[myCol[l]] = myCol[0];
          _columns->_elemColumns[myCol[0]] = myCol;
        }

      } // i

    } // if

  } // for itf

  if(ff2) {
    fprintf(ff2, "};\n");
    fclose(ff2);
  }

  filterOverlappingElements(_lines, blTris, blQuads, _columns->_elemColumns,
                            _columns->_toFirst);
  for(std::size_t i = 0; i < blQuads.size(); i++) blQuads[i]->setPartition(0);
  for(std::size_t i = 0; i < blTris.size(); i++) blTris[i]->setPartition(0);

  for(std::size_t i = 0; i < blQuads.size(); i++) {
    addOrRemove(blQuads[i]->getVertex(0), blQuads[i]->getVertex(1), bedges,
                removed);
    addOrRemove(blQuads[i]->getVertex(1), blQuads[i]->getVertex(2), bedges,
                removed);
    addOrRemove(blQuads[i]->getVertex(2), blQuads[i]->getVertex(3), bedges,
                removed);
    addOrRemove(blQuads[i]->getVertex(3), blQuads[i]->getVertex(0), bedges,
                removed);
    for(int j = 0; j < 4; j++)
      if(blQuads[i]->getVertex(j)->onWhat() == gf)
        verts.insert(blQuads[i]->getVertex(j));
  }
  for(std::size_t i = 0; i < blTris.size(); i++) {
    addOrRemove(blTris[i]->getVertex(0), blTris[i]->getVertex(1), bedges,
                removed);
    addOrRemove(blTris[i]->getVertex(1), blTris[i]->getVertex(2), bedges,
                removed);
    addOrRemove(blTris[i]->getVertex(2), blTris[i]->getVertex(0), bedges,
                removed);
    for(int j = 0; j < 3; j++)
      if(blTris[i]->getVertex(j)->onWhat() == gf)
        verts.insert(blTris[i]->getVertex(j));
  }

  discreteEdge ne(gf->model(), 444444, nullptr,
                  (*edges.begin())->getEndVertex());
  std::vector<GEdge *> hop;
  auto it = bedges.begin();

  FILE *ff = nullptr;
  if(debug) ff = Fopen("toto.pos", "w");
  if(ff) fprintf(ff, "View \" \"{\n");
  for(; it != bedges.end(); ++it) {
    ne.lines.push_back(new MLine(it->getVertex(0), it->getVertex(1)));
    if(ff)
      fprintf(ff, "SL(%g,%g,%g,%g,%g,%g){1,1};\n", it->getVertex(0)->x(),
              it->getVertex(0)->y(), it->getVertex(0)->z(),
              it->getVertex(1)->x(), it->getVertex(1)->y(),
              it->getVertex(1)->z());
  }
  if(ff) {
    fprintf(ff, "};\n");
    fclose(ff);
  }
  hop.push_back(&ne);

  deMeshGFace kil_;
  kil_(gf);
  meshGenerator(gf, 0, false, MeshExtent::BoundaryLayerRemesh, false, &hop);
}