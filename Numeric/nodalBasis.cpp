// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <limits>
#include <cmath>
#include <algorithm>
#include "nodalBasis.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"
#include "MPrism.h"

namespace ClosureGen {
  inline double pow2(double x) { return x * x; }

  void rotateHex(int iFace, int iRot, int iSign, double uI, double vI,
                 double &uO, double &vO, double &wO)
  {
    if(iSign < 0) {
      double tmp = uI;
      uI = vI;
      vI = tmp;
    }
    for(int i = 0; i < iRot; i++) {
      double tmp = uI;
      uI = -vI;
      vI = tmp;
    }
    switch(iFace) {
    case 0:
      uO = vI;
      vO = uI;
      wO = -1;
      break;
    case 1:
      uO = uI;
      vO = -1;
      wO = vI;
      break;
    case 2:
      uO = -1;
      vO = vI;
      wO = uI;
      break;
    case 3:
      uO = 1;
      vO = uI;
      wO = vI;
      break;
    case 4:
      uO = -uI;
      vO = 1;
      wO = vI;
      break;
    case 5:
      uO = uI;
      vO = vI;
      wO = 1;
      break;
    }
  }

  void rotateHexFull(int iFace, int iRot, int iSign, double uI, double vI,
                     double wI, double &uO, double &vO, double &wO)
  {
    switch(iFace) {
    case 0:
      uO = uI;
      vO = vI;
      wO = wI;
      break;
    case 1:
      uO = wI;
      vO = uI;
      wO = vI;
      break;
    case 2:
      uO = vI;
      vO = wI;
      wO = uI;
      break;
    case 3:
      uO = wI;
      vO = vI;
      wO = -uI;
      break;
    case 4:
      uO = wI;
      vO = -uI;
      wO = -vI;
      break;
    case 5:
      uO = vI;
      vO = uI;
      wO = -wI;
      break;
    }
    for(int i = 0; i < iRot; i++) {
      double tmp = uO;
      uO = -vO;
      vO = tmp;
    }
    if(iSign < 0) {
      double tmp = uO;
      uO = vO;
      vO = tmp;
    }
  }

  void rotatePyr(int iFace, int iRot, int iSign, double uI, double vI,
                 double &uO, double &vO, double &wO)
  {
    if(iSign < 0) {
      double tmp = uI;
      uI = vI;
      vI = tmp;
    }
    for(int i = 0; i < iRot; i++) {
      double tmp = uI;
      uI = -vI;
      vI = tmp;
    }
    switch(iFace) {
    case 0:
      uO = uI;
      vO = vI - 1;
      wO = vI;
      break;
    case 1:
      uO = vI - 1;
      vO = -uI;
      wO = vI;
      break;
    case 2:
      uO = 1 - vI;
      vO = uI;
      wO = vI;
      break;
    case 3:
      uO = -uI;
      vO = 1 - vI;
      wO = vI;
      break;
    case 4:
      uO = vI;
      vO = uI;
      wO = 0;
      break;
    }
  }

  void generate1dVertexClosure(nodalBasis::clCont &closure, int order)
  {
    closure.clear();
    closure.resize(2);
    closure[0].push_back(0);
    closure[1].push_back(order == 0 ? 0 : 1);
    closure[0].type = MSH_PNT;
    closure[1].type = MSH_PNT;
  }

  void generate1dVertexClosureFull(nodalBasis::clCont &closure,
                                   std::vector<int> &closureRef, int order)
  {
    closure.clear();
    closure.resize(2);
    closure[0].push_back(0);
    if(order != 0) {
      closure[0].push_back(1);
      closure[1].push_back(1);
    }
    closure[1].push_back(0);
    for(int i = 0; i < order - 1; i++) {
      closure[0].push_back(2 + i);
      closure[1].push_back(2 + order - 2 - i);
    }
    closureRef.resize(2);
    closureRef[0] = 0;
    closureRef[1] = 0;
  }

  void getFaceClosureTet(int iFace, int iSign, int iRotate,
                         nodalBasis::closure &closure, int order)
  {
    closure.clear();
    closure.resize((order + 1) * (order + 2) / 2);
    closure.type = ElementType::getType(TYPE_TRI, order, false);

    switch(order) {
    case 0: closure[0] = 0; break;
    default:
      int face[4][3] = {{-3, -2, -1}, {1, -6, 4}, {-4, 5, 3}, {6, 2, -5}};
      int order1node[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
      for(int i = 0; i < 3; ++i) {
        int k = (3 + (iSign * i) + iRotate) % 3; //- iSign * iRotate
        closure[i] = order1node[iFace][k];
      }
      for(int i = 0; i < 3; ++i) {
        int edgenumber =
          iSign * face[iFace][(6 + i * iSign + (-1 + iSign) / 2 + iRotate) %
                              3]; //- iSign * iRotate
        for(int k = 0; k < (order - 1); k++) {
          if(edgenumber > 0)
            closure[3 + i * (order - 1) + k] =
              4 + (edgenumber - 1) * (order - 1) + k;
          else
            closure[3 + i * (order - 1) + k] =
              4 + (-edgenumber) * (order - 1) - 1 - k;
        }
      }
      int fi = 3 + 3 * (order - 1);
      int ti = 4 + 6 * (order - 1);
      int ndofff = (order - 3 + 2) * (order - 3 + 1) / 2;
      ti = ti + iFace * ndofff;
      for(int k = 0; k < order / 3; k++) {
        int orderint = order - 3 - k * 3;
        if(orderint > 0) {
          for(int ci = 0; ci < 3; ci++) {
            int shift = (3 + iSign * ci + iRotate) % 3; //- iSign * iRotate
            closure[fi + ci] = ti + shift;
          }
          fi = fi + 3;
          ti = ti + 3;
          for(int l = 0; l < orderint - 1; l++) {
            for(int ei = 0; ei < 3; ei++) {
              int edgenumber =
                (6 + ei * iSign + (-1 + iSign) / 2 + iRotate) % 3;
              //- iSign * iRotate
              if(iSign > 0)
                closure[fi + ei * (orderint - 1) + l] =
                  ti + edgenumber * (orderint - 1) + l;
              else
                closure[fi + ei * (orderint - 1) + l] =
                  ti + (1 + edgenumber) * (orderint - 1) - 1 - l;
            }
          }
          fi = fi + 3 * (orderint - 1);
          ti = ti + 3 * (orderint - 1);
        }
        else {
          closure[fi] = ti;
          ti++;
          fi++;
        }
      }
      break;
    }
  }

  void generate2dEdgeClosureFull(nodalBasis::clCont &closure,
                                 std::vector<int> &closureRef, int order,
                                 int nNod, bool serendip)
  {
    closure.clear();
    closure.resize(2 * nNod);
    closureRef.resize(2 * nNod);
    int shift = 0;
    for(int corder = order; corder >= 0; corder -= (nNod == 3 ? 3 : 2)) {
      if(corder == 0) {
        for(int r = 0; r < nNod; r++) {
          closure[r].push_back(shift);
          closure[r + nNod].push_back(shift);
        }
        break;
      }
      for(int r = 0; r < nNod; r++) {
        for(int j = 0; j < nNod; j++) {
          closure[r].push_back(shift + (r + j) % nNod);
          closure[r + nNod].push_back(shift + (r - j + 1 + nNod) % nNod);
        }
      }
      shift += nNod;
      int n = nNod * (corder - 1);
      for(int r = 0; r < nNod; r++) {
        for(int j = 0; j < n; j++) {
          closure[r].push_back(shift + (j + (corder - 1) * r) % n);
          closure[r + nNod].push_back(shift +
                                      (n - j - 1 + (corder - 1) * (r + 1)) % n);
        }
      }
      shift += n;
      if(serendip) break;
    }
    for(int r = 0; r < nNod * 2; r++) {
      closure[r].type = ElementType::getType(TYPE_LIN, order);
      closureRef[r] = 0;
    }
  }

  void addEdgeNodes(nodalBasis::clCont &closureFull, const int *edges,
                    int order)
  {
    if(order < 2) return;
    int numNodes = 0;
    for(int i = 0; edges[i] >= 0; ++i) {
      numNodes = std::max(numNodes, edges[i] + 1);
    }
    std::vector<std::vector<int> > nodes2edges(numNodes,
                                               std::vector<int>(numNodes, -1));
    for(int i = 0; edges[i] >= 0; i += 2) {
      nodes2edges[edges[i]][edges[i + 1]] = i;
      nodes2edges[edges[i + 1]][edges[i]] = i + 1;
    }
    for(std::size_t iClosure = 0; iClosure < closureFull.size(); iClosure++) {
      std::vector<int> &cl = closureFull[iClosure];
      for(int iEdge = 0; edges[iEdge] >= 0; iEdge += 2) {
        if(cl.empty()) continue;
        int n0 = cl[edges[iEdge]];
        int n1 = cl[edges[iEdge + 1]];
        int oEdge = nodes2edges[n0][n1];
        if(oEdge == -1) Msg::Error("invalid p1 closure or invalid edges list");
        for(int i = 0; i < order - 1; i++)
          cl.push_back(numNodes + oEdge / 2 * (order - 1) +
                       ((oEdge % 2) ? order - 2 - i : i));
      }
    }
  }

  void generateFaceClosureTet(nodalBasis::clCont &closure, int order)
  {
    closure.clear();
    for(int iRotate = 0; iRotate < 3; iRotate++) {
      for(int iSign = 1; iSign >= -1; iSign -= 2) {
        for(int iFace = 0; iFace < 4; iFace++) {
          nodalBasis::closure closure_face;
          getFaceClosureTet(iFace, iSign, iRotate, closure_face, order);
          closure.push_back(closure_face);
        }
      }
    }
  }

  void generateFaceClosureTetFull(nodalBasis::clCont &closureFull,
                                  std::vector<int> &closureRef, int order,
                                  bool serendip)
  {
    closureFull.clear();
    // input :
    static const short int faces[4][3] = {
      {0, 1, 2}, {0, 3, 1}, {0, 2, 3}, {3, 2, 1}};
    static const int edges[] = {0, 1, 1, 2, 2, 0, 3, 0, 3, 2, 3, 1, -1};
    static const int faceOrientation[6] = {0, 1, 2, 5, 3, 4};
    closureFull.resize(24);
    closureRef.resize(24);
    for(int i = 0; i < 24; i++) closureRef[i] = 0;
    if(order == 0) {
      for(int i = 0; i < 24; i++) { closureFull[i].push_back(0); }
      return;
    }
    // Mapping for the p1 nodes
    nodalBasis::clCont closure;
    generateFaceClosureTet(closure, 1);
    for(std::size_t i = 0; i < closureFull.size(); i++) {
      std::vector<int> &clFull = closureFull[i];
      std::vector<int> &cl = closure[i];
      clFull.resize(4, -1);
      closureRef[i] = 0;
      for(std::size_t j = 0; j < cl.size(); j++) clFull[closure[0][j]] = cl[j];
      for(int j = 0; j < 4; j++)
        if(clFull[j] == -1)
          clFull[j] = (6 - clFull[(j + 1) % 4] - clFull[(j + 2) % 4] -
                       clFull[(j + 3) % 4]);
    }
    int nodes2Faces[4][4][4];
    for(int i = 0; i < 4; i++) {
      for(int iRotate = 0; iRotate < 3; iRotate++) {
        short int n0 = faces[i][(3 - iRotate) % 3];
        short int n1 = faces[i][(4 - iRotate) % 3];
        short int n2 = faces[i][(5 - iRotate) % 3];
        nodes2Faces[n0][n1][n2] = i * 6 + iRotate;
        nodes2Faces[n0][n2][n1] = i * 6 + iRotate + 3;
      }
    }
    nodalBasis::clCont closureTriangles;
    std::vector<int> closureTrianglesRef;
    if(order >= 3)
      generate2dEdgeClosureFull(closureTriangles, closureTrianglesRef,
                                order - 3, 3, false);
    addEdgeNodes(closureFull, edges, order);
    for(std::size_t iClosure = 0; iClosure < closureFull.size(); iClosure++) {
      // faces
      std::vector<int> &cl = closureFull[iClosure];
      if(order >= 3) {
        for(int iFace = 0; iFace < 4; iFace++) {
          int n0 = cl[faces[iFace][0]];
          int n1 = cl[faces[iFace][1]];
          int n2 = cl[faces[iFace][2]];
          short int id = nodes2Faces[n0][n1][n2];
          short int iTriClosure = faceOrientation[id % 6];
          short int idFace = id / 6;
          int nOnFace = closureTriangles[iTriClosure].size();
          for(int i = 0; i < nOnFace; i++) {
            cl.push_back(4 + 6 * (order - 1) + idFace * nOnFace +
                         closureTriangles[iTriClosure][i]);
          }
        }
      }
    }
    if(order >= 4 && !serendip) {
      nodalBasis::clCont insideClosure;
      std::vector<int> fakeClosureRef;
      generateFaceClosureTetFull(insideClosure, fakeClosureRef, order - 4,
                                 false);
      for(std::size_t i = 0; i < closureFull.size(); i++) {
        std::size_t shift = closureFull[i].size();
        for(std::size_t j = 0; j < insideClosure[i].size(); j++)
          closureFull[i].push_back(insideClosure[i][j] + shift);
      }
    }
  }

  /*
  void checkClosure(int tag){
    printf("TYPE = %i\n", tag);
    const nodalBasis &fs = *nodalBases::find(tag);
    for(int i = 0; i < fs.closures.size(); ++i){
      const std::vector<int> &clRef = fs.closures[fs.closureRef[i]];
      const std::vector<int> &cl = fs.closures[i];
      const std::vector<int> &clFull = fs.fullClosures[i];
      printf("i = %i\n", i);
      for(int j = 0; j < cl.size(); ++j){
        printf("%3i ", clFull[clRef[j]]);
      }
      printf("\n");
      for(int j = 0; j < cl.size(); ++j){
        printf("%3i ", cl[j]);
      }
      printf("\n");
    }
  }
  */

  void generateFaceClosureHex(nodalBasis::clCont &closure, int order,
                              bool serendip, const fullMatrix<double> &points)
  {
    closure.clear();
    const nodalBasis &fsFace = *BasisFactory::getNodalBasis(
      ElementType::getType(TYPE_QUA, order, serendip));
    for(int iRotate = 0; iRotate < 4; iRotate++) {
      for(int iSign = 1; iSign >= -1; iSign -= 2) {
        for(int iFace = 0; iFace < 6; iFace++) {
          nodalBasis::closure cl;
          cl.type = fsFace.type;
          cl.resize(fsFace.points.size1());
          for(std::size_t iNode = 0; iNode < cl.size(); ++iNode) {
            double u, v, w;
            rotateHex(iFace, iRotate, iSign, fsFace.points(iNode, 0),
                      fsFace.points(iNode, 1), u, v, w);
            cl[iNode] = 0;
            double D = std::numeric_limits<double>::max();
            for(int jNode = 0; jNode < points.size1(); ++jNode) {
              double d = pow2(points(jNode, 0) - u) +
                         pow2(points(jNode, 1) - v) +
                         pow2(points(jNode, 2) - w);
              if(d < D) {
                cl[iNode] = jNode;
                D = d;
              }
            }
          }
          closure.push_back(cl);
        }
      }
    }
  }

  void generateFaceClosureHexFull(nodalBasis::clCont &closure,
                                  std::vector<int> &closureRef, int order,
                                  bool serendip,
                                  const fullMatrix<double> &points)
  {
    closure.clear();
    int clId = 0;
    for(int iRotate = 0; iRotate < 4; iRotate++) {
      for(int iSign = 1; iSign >= -1; iSign -= 2) {
        for(int iFace = 0; iFace < 6; iFace++) {
          nodalBasis::closure cl;
          cl.resize(points.size1());
          for(int iNode = 0; iNode < points.size1(); ++iNode) {
            double u, v, w;
            rotateHexFull(iFace, iRotate, iSign, points(iNode, 0),
                          points(iNode, 1), points(iNode, 2), u, v, w);
            int J = 0;
            double D = std::numeric_limits<double>::max();
            for(int jNode = 0; jNode < points.size1(); ++jNode) {
              double d = pow2(points(jNode, 0) - u) +
                         pow2(points(jNode, 1) - v) +
                         pow2(points(jNode, 2) - w);
              if(d < D) {
                J = jNode;
                D = d;
              }
            }
            cl[J] = iNode;
          }
          closure.push_back(cl);
          closureRef.push_back(0);
          clId++;
        }
      }
    }
  }

  void fillInteriorFaceNodes(nodalBasis::closure &closure, int idx, int order,
                             int isTriangle, int start)
  {
    // Numbering of nodes in Gmsh is as the following: The first nodes are the
    // corners. Then follow the nodes on the edges, with an edge being
    // completely filled before the following is filled. After come the nodes on
    // faces, with the same strategy. (Eventually, there are the volume nodes.)
    // Moreover, the numbering of the face interior nodes is coherent with the
    // numbering of the equivalent 2D element. This explains why this function
    // is so simple.
    int nNodes =
      isTriangle ? (order - 2) * (order - 1) / 2 : (order - 1) * (order - 1);
    for(int i = 0; i < nNodes; ++i, ++idx, ++start) { closure[idx] = start; }
  }

  void reorderFaceClosure(int iSign, int iRotate, nodalBasis::closure &closure,
                          int idx, int order, int isTriangle)
  {
    if(order <= 0) return;
    nodalBasis::closure old = closure;
    int start = idx;

    const int nCorner = isTriangle ? 3 : 4;
    for(int i = 0; i < nCorner; ++i, ++idx) {
      closure[idx] = old[start + (nCorner + i * iSign + iRotate) % nCorner];
    }

    const int &nEdge = nCorner;
    for(int i = 0; i < nEdge; ++i) {
      int iOldEdge =
        (nEdge + i * iSign + iRotate + (iSign == -1 ? -1 : 0)) % nEdge;
      int startOldEdge = start + nCorner + iOldEdge * (order - 1);
      if(iSign > 0) {
        for(int j = startOldEdge; j < startOldEdge + order - 1; ++j, ++idx)
          closure[idx] = old[j];
      }
      else if(iSign < 0) {
        for(int j = startOldEdge + order - 2; j >= startOldEdge; --j, ++idx)
          closure[idx] = old[j];
      }
    }
    if(isTriangle && order > 3)
      reorderFaceClosure(iSign, iRotate, closure, idx, order - 3, isTriangle);
    else if(!isTriangle && order > 2)
      reorderFaceClosure(iSign, iRotate, closure, idx, order - 2, isTriangle);
  }

  void getFaceClosurePrism(int iFace, int iSign, int iRotate,
                           nodalBasis::closure &closure, int order)
  {
    closure.clear();
    bool isTriangle = iFace < 2;
    if(isTriangle && iRotate > 2) return;
    closure.type =
      ElementType::getType(isTriangle ? TYPE_TRI : TYPE_QUA, order);

    int nNodes =
      isTriangle ? (order + 1) * (order + 2) / 2 : (order + 1) * (order + 1);
    closure.resize(nNodes);
    if(order == 0) {
      closure[0] = 0;
      return;
    }

    // map edge number to the nodes number
    int *edge2nodes[9];
    int n = 6;
    for(int i = 0; i < 9; ++i) {
      edge2nodes[i] = new int[order - 1];
      for(int k = 0; k < order - 1; ++k, ++n) edge2nodes[i][k] = n;
    }

    // fill corner node number
    const int nCorner = isTriangle ? 3 : 4;
    for(int i = 0; i < nCorner; ++i) {
      closure[i] = MPrism::faces_prism(iFace, i);
    }

    // fill high-order nodes number
    if(order > 1) {
      int idx = nCorner;
      const int &nEdge = nCorner;

      // fill edge nodes number
      for(int i = 0; i < nEdge; ++i) {
        int edge = MPrism::faceClosureEdge2edge(iFace, i);
        if(edge > 0) {
          edge = edge - 1;
          for(int k = 0; k < order - 1; ++k, ++idx) {
            closure[idx] = edge2nodes[edge][k];
          }
        }
        else if(edge < 0) {
          edge = -edge - 1;
          for(int k = order - 2; k >= 0; --k, ++idx) {
            closure[idx] = edge2nodes[edge][k];
          }
        }
      }
      for(int i = 0; i < 9; ++i) delete edge2nodes[i];

      // Numbering of nodes inside the face start at
      int start = 6 + 9 * (order - 1) +
                  std::min(iFace, 2) * (order - 2) * (order - 1) / 2 +
                  std::max(iFace - 2, 0) * (order - 1) * (order - 1);

      // fill interior nodes number
      fillInteriorFaceNodes(closure, idx, order, isTriangle, start);
    }

    reorderFaceClosure(iSign, iRotate, closure, 0, order, isTriangle);
  }

  void generateFaceClosurePrism(nodalBasis::clCont &closure, int order)
  {
    closure.clear();
    for(int iRotate = 0; iRotate < 4; iRotate++) {
      for(int iSign = 1; iSign >= -1; iSign -= 2) {
        for(int iFace = 0; iFace < 5; iFace++) {
          nodalBasis::closure closure_face;
          getFaceClosurePrism(iFace, iSign, iRotate, closure_face, order);
          closure.push_back(closure_face);
        }
      }
    }
  }

  void generateFaceClosurePrismFull(nodalBasis::clCont &closureFull,
                                    std::vector<int> &closureRef, int order)
  {
    nodalBasis::clCont closure;
    closureFull.clear();
    closureFull.resize(40);
    closureRef.resize(40);
    generateFaceClosurePrism(closure, 1);
    int ref3 = -1, ref4a = -1, ref4b = -1;
    for(std::size_t i = 0; i < closure.size(); i++) {
      std::vector<int> &clFull = closureFull[i];
      std::vector<int> &cl = closure[i];
      if(cl.size() == 0) continue;
      clFull.resize(6, -1);
      int &ref = cl.size() == 3              ? ref3 :
                 (cl[0] / 3 + cl[1] / 3) % 2 ? ref4b :
                                               ref4a;
      if(ref == -1) ref = i;
      closureRef[i] = ref;
      for(std::size_t j = 0; j < cl.size(); j++)
        clFull[closure[ref][j]] = cl[j];
      for(int j = 0; j < 6; j++) {
        if(clFull[j] == -1) {
          int k = ((j / 3) + 1) % 2 * 3;
          int sum = (clFull[k + (j + 1) % 3] + clFull[k + (j + 2) % 3]);
          clFull[j] = ((sum / 6 + 1) % 2) * 3 + (12 - sum) % 3;
        }
      }
    }
    static const int edges[] = {0, 1, 0, 2, 0, 3, 1, 2, 1, 4,
                                2, 5, 3, 4, 3, 5, 4, 5, -1};
    addEdgeNodes(closureFull, edges, order);
    if(order < 2) return;
    // face center nodes for p2 prism
    static const int faces[5][4] = {
      {0, 2, 1, -1}, {3, 4, 5, -1}, {0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};

    if(order == 2) {
      int nextFaceNode = 15;
      int numFaces = 5;
      int numFaceNodes = 4;
      std::map<int, int> nodeSum2Face;
      for(int iFace = 0; iFace < numFaces; iFace++) {
        int nodeSum = 0;
        for(int iNode = 0; iNode < numFaceNodes; iNode++) {
          nodeSum += faces[iFace][iNode];
        }
        nodeSum2Face[nodeSum] = iFace;
      }
      for(std::size_t i = 0; i < closureFull.size(); i++) {
        if(closureFull[i].empty()) continue;
        for(int iFace = 0; iFace < numFaces; iFace++) {
          int nodeSum = 0;
          for(int iNode = 0; iNode < numFaceNodes; iNode++)
            nodeSum += faces[iFace][iNode] < 0 ?
                         faces[iFace][iNode] :
                         closureFull[i][faces[iFace][iNode]];
          auto it = nodeSum2Face.find(nodeSum);
          if(it == nodeSum2Face.end()) Msg::Error("Prism face not found");
          int mappedFaceId = it->second;
          if(mappedFaceId > 1) {
            closureFull[i].push_back(nextFaceNode + mappedFaceId - 2);
          }
        }
      }
    }
    else {
      Msg::Error("FaceClosureFull not implemented for prisms of order %d",
                 order);
    }
  }

  void generateFaceClosurePyr(nodalBasis::clCont &closure, int order,
                              bool serendip, const fullMatrix<double> &points)
  {
    closure.clear();
    const int typeTri = ElementType::getType(TYPE_TRI, order, serendip);
    const int typeQua = ElementType::getType(TYPE_QUA, order, serendip);
    const nodalBasis *fsFaceTri = BasisFactory::getNodalBasis(typeTri);
    const nodalBasis *fsFaceQua = BasisFactory::getNodalBasis(typeQua);

    for(int iRotate = 0; iRotate < 4; iRotate++) {
      for(int iSign = 1; iSign >= -1; iSign -= 2) {
        for(int iFace = 0; iFace < 5; iFace++) {
          const nodalBasis *fsFace;
          if(iFace < 4)
            fsFace = fsFaceTri;
          else
            fsFace = fsFaceQua;
          nodalBasis::closure cl;
          cl.type = fsFace->type;
          cl.resize(fsFace->points.size1());
          for(std::size_t iNode = 0; iNode < cl.size(); ++iNode) {
            double u, v, w;
            rotatePyr(iFace, iRotate, iSign, fsFace->points(iNode, 0),
                      fsFace->points(iNode, 1), u, v, w);
            cl[iNode] = 0;
            double D = std::numeric_limits<double>::max();
            for(int jNode = 0; jNode < points.size1(); ++jNode) {
              double d = pow2(points(jNode, 0) - u) +
                         pow2(points(jNode, 1) - v) +
                         pow2(points(jNode, 2) - w);
              if(d < D) {
                cl[iNode] = jNode;
                D = d;
              }
            }
          }
          closure.push_back(cl);
        }
      }
    }
  }

  void generate2dEdgeClosure(nodalBasis::clCont &closure, int order,
                             int nNod = 3)
  {
    closure.clear();
    closure.resize(2 * nNod);
    for(int j = 0; j < nNod; j++) {
      closure[j].push_back(j);
      closure[j].push_back((j + 1) % nNod);
      closure[nNod + j].push_back((j + 1) % nNod);
      closure[nNod + j].push_back(j);
      for(int i = 0; i < order - 1; i++) {
        closure[j].push_back(nNod + (order - 1) * j + i);
        closure[nNod + j].push_back(nNod + (order - 1) * (j + 1) - i - 1);
      }
      closure[j].type = closure[nNod + j].type =
        ElementType::getType(TYPE_LIN, order);
    }
  }

  void generateClosureOrder0(nodalBasis::clCont &closure, int nb)
  {
    closure.clear();
    closure.resize(nb);
    for(int i = 0; i < nb; i++) {
      closure[i].push_back(0);
      closure[i].type = MSH_PNT;
    }
  }
} // namespace ClosureGen

nodalBasis::nodalBasis(int tag)
{
  using namespace ClosureGen;
  type = tag;
  parentType = ElementType::getParentType(tag);
  order = ElementType::getOrder(tag);
  serendip = ElementType::getSerendipity(tag) > 1;
  dimension = ElementType::getDimension(tag);

  switch(parentType) {
  case TYPE_PNT:
    numFaces = 1;
    points = gmshGeneratePointsLine(0);
    break;
  case TYPE_LIN:
    numFaces = 2;
    points = gmshGeneratePointsLine(order);
    generate1dVertexClosure(closures, order);
    generate1dVertexClosureFull(fullClosures, closureRef, order);
    break;
  case TYPE_TRI:
    numFaces = 3;
    points = gmshGeneratePointsTriangle(order, serendip);
    if(order == 0) {
      generateClosureOrder0(closures, 6);
      generateClosureOrder0(fullClosures, 6);
      closureRef.resize(6, 0);
    }
    else {
      generate2dEdgeClosure(closures, order);
      generate2dEdgeClosureFull(fullClosures, closureRef, order, 3, serendip);
    }
    break;
  case TYPE_QUA:
    numFaces = 4;
    points = gmshGeneratePointsQuadrangle(order, serendip);
    if(order == 0) {
      generateClosureOrder0(closures, 8);
      generateClosureOrder0(fullClosures, 8);
      closureRef.resize(8, 0);
    }
    else {
      generate2dEdgeClosure(closures, order, 4);
      generate2dEdgeClosureFull(fullClosures, closureRef, order, 4, serendip);
    }
    break;
  case TYPE_TET:
    numFaces = 4;
    points = gmshGeneratePointsTetrahedron(order, serendip);
    if(order == 0) {
      generateClosureOrder0(closures, 24);
      generateClosureOrder0(fullClosures, 24);
      closureRef.resize(24, 0);
    }
    else {
      generateFaceClosureTet(closures, order);
      generateFaceClosureTetFull(fullClosures, closureRef, order, serendip);
    }
    break;
  case TYPE_PRI:
    numFaces = 5;
    points = gmshGeneratePointsPrism(order, serendip);
    if(order == 0) {
      generateClosureOrder0(closures, 48);
      generateClosureOrder0(fullClosures, 48);
      closureRef.resize(48, 0);
    }
    else {
      generateFaceClosurePrism(closures, order);
      generateFaceClosurePrismFull(fullClosures, closureRef, order);
    }
    break;
  case TYPE_HEX:
    numFaces = 6;
    points = gmshGeneratePointsHexahedron(order, serendip);
    generateFaceClosureHex(closures, order, serendip, points);
    generateFaceClosureHexFull(fullClosures, closureRef, order, serendip,
                               points);
    break;
  case TYPE_PYR:
    numFaces = 5;
    points = gmshGeneratePointsPyramid(order, serendip);
    generateFaceClosurePyr(closures, order, serendip, points);
    break;
  }
}

int nodalBasis::getNumBubbleShapeFunctions() const
{
  int numBubble = -1;
  switch(parentType) {
  case TYPE_PNT: numBubble = 0; break;
  case TYPE_LIN: numBubble = ElementType::getNumVertices(type) - 2; break;
  case TYPE_TRI:
    if(serendip) { numBubble = 0; }
    else {
      numBubble = (order - 1) * (order - 2) / 2;
    }
    break;
  case TYPE_QUA:
    if(serendip) { numBubble = 0; }
    else {
      numBubble = (order - 1) * (order - 1);
    }
    break;
  case TYPE_TET:
    if(serendip) { numBubble = 0; }
    else {
      numBubble = ((order - 1) * (order - 2) * (order - 3)) / 6;
    }
    break;
  case TYPE_PRI:
    if(serendip) { numBubble = 0; }
    else {
      numBubble = (order - 1) * (((order - 1) - 1) * (order - 1) / 2);
    }
    break;
  case TYPE_HEX:
    if(serendip) { numBubble = 0; }
    else {
      numBubble = (order - 1) * (order - 1) * (order - 1);
    }
    break;
  case TYPE_PYR:
    if(serendip) { numBubble = 0; }
    else {
      numBubble = (order - 2) * ((order - 2) + 1) * (2 * (order - 2) + 1) / 6;
    }
    break;
  }

  return numBubble;
}

bool nodalBasis::forwardTransformation(const fullMatrix<double> &nodes,
                                       fullMatrix<double> &projection,
                                       int elementType) const
{
  if(elementType != -1 && elementType != type) {
    std::cout << "Incorrect element type " << std::endl;
    return false;
  }
  if(nodes.size1() != points.size1()) return false;

  projection.resize(nodes.size1(), points.size1());
  f(nodes, projection);

  projection.invertInPlace();
  // projection.transposeInPlace();
  return true;
}

bool nodalBasis::forwardRenumbering(const fullMatrix<double> &nodes, int *renum,
                                    int elementType) const
{
  if(nodes.size1() != points.size1()) {
    std::cout << "Non-matching node counts " << nodes.size1() << " vs "
              << points.size1() << std::endl;
    return false;
  }

  double tol = 1e-10;

  fullMatrix<double> tfo;
  if(!forwardTransformation(nodes, tfo, elementType)) {
    std::cout << "Could not find forward transformation " << std::endl;
    return false;
  }

  // tfo.print("Projection matrix","%1.f");

  for(int i = 0; i < nodes.size1(); i++) {
    int idx = -1;
    int nbOnes = 0;
    int nbZeroes = 0;
    for(int j = 0; j < nodes.size1(); j++) {
      if(fabs(tfo(i, j) - 1.0) < tol) {
        idx = j;
        nbOnes++;
      }
      if(fabs(tfo(i, j)) < tol) { nbZeroes++; }
    }
    if(nbOnes != 1) return false;
    if(nbZeroes != nodes.size1() - 1) return false;
    renum[i] = idx;
  }

  // for (int i=0;i<nodes.size1();i++) {
  //   std::cout << i << " -> " << renum[i] << std::endl;
  // }

  return renum;
}
