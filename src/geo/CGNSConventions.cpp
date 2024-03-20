// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "SVector3.h"
#include "GmshDefines.h"
#include "fullMatrix.h"
#include "ElementType.h"
#include "BasisFactory.h"
#include "nodalBasis.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "StringUtils.h"

#if defined(HAVE_LIBCGNS)

namespace {

  // ------------- Conversion of node ordering between CGNS and Gmsh
  // -------------

  void addEdgePointsCGNS(const SVector3 p0, const SVector3 p1, int order,
                         std::vector<SVector3> &points)
  {
    if(order < 2) return;

    double ds = 1. / order;
    for(int i = 1; i < order; i++) {
      double f = ds * i;
      points.push_back(p0 * (1. - f) + p1 * f);
    }
  }

  std::vector<SVector3> generatePointsTriCGNS(int order, bool complete);

  void addTriPointsCGNS(const SVector3 p0, const SVector3 p1, const SVector3 p2,
                        int order, std::vector<SVector3> &points)
  {
    if(order < 3) return;

    std::vector<SVector3> triPoints = generatePointsTriCGNS(order - 3, true);

    double scale = double(order - 3) / double(order);
    SVector3 offset(1. / order, 1. / order, 0);

    for(size_t i = 0; i < triPoints.size(); i++) {
      SVector3 ip = triPoints[i];
      double u = ip[0] * scale + 1. / order;
      double v = ip[1] * scale + 1. / order;
      SVector3 pt = (1. - u - v) * p0 + u * p1 + v * p2;
      points.push_back(pt);
    }
  }

  void addQuaPointsCGNS(int order, std::vector<SVector3> &points)
  {
    if(order > 2) {
      double scale = double(order - 2) / double(order);

      SVector3 corner[4] = {SVector3(-1, -1, 0), SVector3(1, -1, 0),
                            SVector3(1, 1, 0), SVector3(-1, 1, 0)};

      for(int i = 0; i < 4; i++) {
        SVector3 c1 = corner[i];
        SVector3 c2 = corner[(i + 1) % 4];
        double ds = 1. / (order - 2);
        for(int i = 0; i < order - 2; i++)
          points.push_back((c1 * (1. - i * ds) + c2 * (i * ds)) * scale);
      }
    }

    if(order == 2 || order == 4) points.push_back(SVector3(0, 0, 0));
  }

  void addQuaPointsCGNS(const SVector3 p0, const SVector3 p1, const SVector3 p2,
                        const SVector3 p3, int order,
                        std::vector<SVector3> &points)
  {
    std::vector<SVector3> quaPoints;

    addQuaPointsCGNS(order, quaPoints);

    for(size_t i = 0; i < quaPoints.size(); i++) {
      SVector3 ip = quaPoints[i];
      double u = ip[0];
      double v = ip[1];
      SVector3 pt = ((1. - u) * (1. - v) * p0 + (1. + u) * (1. - v) * p1 +
                     (1. + u) * (1. + v) * p2 + (1. - u) * (1. + v) * p3) *
                    0.25;
      points.push_back(pt);
    }
  }

  // void print(std::vector<SVector3> &points, const char *title, int iStart,
  //            int iEnd = -1)
  // {
  //   iEnd = iEnd == -1 ? points.size() : iEnd;

  //   std::cout << title << std::endl;
  //   for(int i = iStart; i < iEnd; i++) {
  //     std::cout << i << " :";
  //     for(int d = 0; d < 3; d++) std::cout << " " << points[i][d];
  //     std::cout << std::endl;
  //   }
  // }

  std::vector<SVector3> generatePointsEdgeCGNS(int order)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(0., 0., 0.));
      return pp;
    }

    // primary vertices
    pp.push_back(SVector3(-1, 0, 0));
    pp.push_back(SVector3(1, 0, 0));

    // internal points
    addEdgePointsCGNS(pp[0], pp[1], order, pp);

    return pp;
  }

  std::vector<SVector3> generatePointsTriCGNS(int order, bool complete)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(1. / 3., 1. / 3., 0.));
      return pp;
    }

    // primary vertices
    pp.push_back(SVector3(0, 0, 0));
    pp.push_back(SVector3(1, 0, 0));
    pp.push_back(SVector3(0, 1, 0));

    // internal points of edges
    for(int i = 0; i < 3; i++) {
      addEdgePointsCGNS(pp[i], pp[(i + 1) % 3], order, pp);
    }

    // internal points
    if(complete && order > 2) {
      addTriPointsCGNS(pp[0], pp[1], pp[2], order, pp);
    }

    return pp;
  }

  std::vector<SVector3> generatePointsQuaCGNS(int order, bool complete)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(0., 0., 0.));
      return pp;
    }

    // primary vertices
    pp.push_back(SVector3(-1, -1, 0));
    pp.push_back(SVector3(1, -1, 0));
    pp.push_back(SVector3(1, 1, 0));
    pp.push_back(SVector3(-1, 1, 0));

    // internal points of edges
    for(int i = 0; i < 4; i++) {
      addEdgePointsCGNS(pp[i], pp[(i + 1) % 4], order, pp);
    }

    // internal points
    if(complete && order > 1) {
      addQuaPointsCGNS(pp[0], pp[1], pp[2], pp[3], order, pp);
    }

    return pp;
  }

  std::vector<SVector3> generatePointsTetCGNS(int order, bool complete)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(1. / 4., 1. / 4., 1. / 4.));
      return pp;
    }

    // primary vertices
    pp.push_back(SVector3(0, 0, 0));
    pp.push_back(SVector3(1, 0, 0));
    pp.push_back(SVector3(0, 1, 0));
    pp.push_back(SVector3(0, 0, 1));

    // internal points in edges of base triangle
    for(int i = 0; i < 3; i++)
      addEdgePointsCGNS(pp[i], pp[(i + 1) % 3], order, pp);

    // internal points in upstanding edges
    for(int i = 0; i < 3; i++) addEdgePointsCGNS(pp[i], pp[3], order, pp);

    if(complete && order > 2) {
      // internal points of base triangle
      addTriPointsCGNS(pp[0], pp[1], pp[2], order, pp);

      // internal points of upstanding triangles
      for(int i = 0; i < 3; i++) {
        addTriPointsCGNS(pp[i], pp[(i + 1) % 3], pp[3], order, pp);
      }

      // internal points as a tet of order p-3
      if(order > 3) {
        std::vector<SVector3> tetPp = generatePointsTetCGNS(order - 4, true);

        double scale = (order - 4) / order;
        SVector3 offset(1. / order, 1. / order, 1. / order);
        for(size_t i = 0; i < tetPp.size(); i++) {
          SVector3 volumePoint = tetPp[i];
          volumePoint *= scale;
          volumePoint += offset;
          pp.push_back(volumePoint);
        }
      }
    }

    return pp;
  }

  std::vector<SVector3> generatePointsHexCGNS(int order, bool complete)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(0., 0., 0.));
      return pp;
    }

    // principal vertices
    pp.push_back(SVector3(-1, -1, -1));
    pp.push_back(SVector3(1, -1, -1));
    pp.push_back(SVector3(1, 1, -1));
    pp.push_back(SVector3(-1, 1, -1));
    pp.push_back(SVector3(-1, -1, 1));
    pp.push_back(SVector3(1, -1, 1));
    pp.push_back(SVector3(1, 1, 1));
    pp.push_back(SVector3(-1, 1, 1));

    // internal points of base quadrangle edges
    for(int i = 0; i < 4; i++)
      addEdgePointsCGNS(pp[i], pp[(i + 1) % 4], order, pp);

    std::vector<SVector3> up[4];
    // internal points of mounting edges
    for(int i = 0; i < 4; i++) {
      addEdgePointsCGNS(pp[i], pp[i + 4], order, up[i]);
      pp.insert(pp.end(), up[i].begin(), up[i].end());
    }

    // internal points of top quadrangle edges
    for(int i = 0; i < 4; i++)
      addEdgePointsCGNS(pp[i + 4], pp[(i + 1) % 4 + 4], order, pp);

    if(complete && order > 1) {
      // internal points of base quadrangle
      addQuaPointsCGNS(pp[0], pp[1], pp[2], pp[3], order, pp);

      // internal points of upstanding faces
      for(int i = 0; i < 4; i++) {
        addQuaPointsCGNS(pp[i], pp[(i + 1) % 4], pp[(i + 1) % 4 + 4], pp[i + 4],
                         order, pp);
      }

      // internal points of top quadrangle
      addQuaPointsCGNS(pp[4], pp[5], pp[6], pp[7], order, pp);

      // internal volume points as a succession of internal planes
      for(int i = 0; i <= order - 2; i++) {
        addQuaPointsCGNS(up[0][i], up[1][i], up[2][i], up[3][i], order, pp);
      }
    }

    return pp;
  }

  std::vector<SVector3> generatePointsPriCGNS(int order, bool complete)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(1. / 3., 1. / 3., 0.));
      return pp;
    }

    // principal vertices
    pp.push_back(SVector3(0, 0, -1));
    pp.push_back(SVector3(1, 0, -1));
    pp.push_back(SVector3(0, 1, -1));
    pp.push_back(SVector3(0, 0, 1));
    pp.push_back(SVector3(1, 0, 1));
    pp.push_back(SVector3(0, 1, 1));

    // internal points in edges of base triangle
    for(int i = 0; i < 3; i++)
      addEdgePointsCGNS(pp[i], pp[(i + 1) % 3], order, pp);

    // internal points in upstanding edges
    std::vector<SVector3> edge[3]; // keep for definition of volume pp
    for(int i = 0; i < 3; i++) {
      addEdgePointsCGNS(pp[i], pp[i + 3], order, edge[i]);
      pp.insert(pp.end(), edge[i].begin(), edge[i].end());
    }

    // internal points in edges of top triangle
    for(int i = 0; i < 3; i++)
      addEdgePointsCGNS(pp[i + 3], pp[(i + 1) % 3 + 3], order, pp);

    if(complete) {
      // internal vertices for base triangle
      addTriPointsCGNS(pp[0], pp[1], pp[2], order, pp);

      // internal vertices for upstanding quadrilaterals
      for(int i = 0; i < 3; i++) {
        addQuaPointsCGNS(pp[i], pp[(i + 1) % 3], pp[(i + 1) % 3 + 3], pp[i + 3],
                         order, pp);
      }

      // internal points for top triangle
      addTriPointsCGNS(pp[3], pp[4], pp[5], order, pp);

      // internal points in the volume as a succession of "triangles"
      for(int o = 0; o < order - 1; o++) {
        addTriPointsCGNS(edge[0][o], edge[1][o], edge[2][o], order, pp);
      }
    }

    return pp;
  }

  // WARNING: incomplete pyramid order 2 is wrong
  std::vector<SVector3> generatePointsPyrCGNS(int order, bool complete)
  {
    std::vector<SVector3> pp;

    if(order == 0) {
      pp.push_back(SVector3(0., 0., 0.));
      return pp;
    }

    // principal vertices
    pp.push_back(SVector3(-1, -1, 0));
    pp.push_back(SVector3(1, -1, 0));
    pp.push_back(SVector3(1, 1, 0));
    pp.push_back(SVector3(-1, 1, 0));
    pp.push_back(SVector3(0, 0, 1));

    // internal points in edges of base quadrilateral
    for(int i = 0; i < 4; i++)
      addEdgePointsCGNS(pp[i], pp[(i + 1) % 4], order, pp);

    // internal points in upstanding edges
    for(int i = 0; i < 4; i++) addEdgePointsCGNS(pp[i], pp[4], order, pp);

    // internal points in base quadrilateral
    addQuaPointsCGNS(pp[0], pp[1], pp[2], pp[3], order, pp);

    // internal points in upstanding triangles
    for(int i = 0; i < 4; i++)
      addTriPointsCGNS(pp[i], pp[(i + 1) % 4], pp[4], order, pp);

    // internal points as an internal pyramid of order p-3
    if(order > 2) {
      std::vector<SVector3> pyr = generatePointsPyrCGNS(order - 3, true);
      SVector3 offset(0, 0, 1. / order);
      double scale = double(order - 3) / double(order);
      for(size_t i = 0; i < pyr.size(); ++i)
        pp.push_back((pyr[i] * scale) + offset);
    }

    return pp;
  }

  fullMatrix<double> generatePointsCGNS(int parentType, int order,
                                        bool complete)
  {
    std::vector<SVector3> pts;

    switch(parentType) {
    case TYPE_LIN: pts = generatePointsEdgeCGNS(order); break;
    case TYPE_TRI: pts = generatePointsTriCGNS(order, complete); break;
    case TYPE_QUA: pts = generatePointsQuaCGNS(order, complete); break;
    case TYPE_TET: pts = generatePointsTetCGNS(order, complete); break;
    case TYPE_HEX: pts = generatePointsHexCGNS(order, complete); break;
    case TYPE_PRI: pts = generatePointsPriCGNS(order, complete); break;
    case TYPE_PYR: pts = generatePointsPyrCGNS(order, complete); break;
    default:
      Msg::Error("CGNS element %s of order %i not yet implemented",
                 ElementType::nameOfParentType(parentType).c_str(),
                 order);
    }

    size_t dim = 0;
    switch(parentType) {
    case TYPE_PNT: dim = 3; break;
    case TYPE_LIN: dim = 1; break;
    case TYPE_TRI:
    case TYPE_QUA: dim = 2; break;
    case TYPE_TET:
    case TYPE_HEX:
    case TYPE_PRI:
    case TYPE_PYR: dim = 3; break;
    }

    fullMatrix<double> ptsCGNS(pts.size(), dim);
    for(size_t i = 0; i < pts.size(); i++) {
      for(size_t d = 0; d < dim; d++) ptsCGNS(i, d) = pts[i][d];
    }

    return ptsCGNS;
  }

  std::vector<int> cgns2MshNodeIndexInit(int mshTag)
  {
    const nodalBasis *nb = BasisFactory::getNodalBasis(mshTag);
    const int nNode = nb->points.size1();

    std::vector<int> nodes(nNode);

    switch(mshTag) {
    case MSH_PNT:
    case MSH_LIN_2:
    case MSH_TRI_3:
    case MSH_QUA_4:
    case MSH_TET_4:
    case MSH_HEX_8:
    case MSH_PRI_6:
    case MSH_PYR_5: // linear elements: same ordering between Gmsh and CGNS
      for(int i = 0; i < nNode; i++) nodes[i] = i;
      break;
    default: // high-order elements: get reordering by comparing points
      int parent = ElementType::getParentType(mshTag);
      int order = ElementType::getOrder(mshTag);
      bool complete = (ElementType::getSerendipity(mshTag) <= 1);
      fullMatrix<double> ptsCGNS = generatePointsCGNS(parent, order, complete);
      const bool reorderOK = computeReordering(ptsCGNS, nb->points, nodes);
      if(!reorderOK) {
        Msg::Error("Could not compute reordering between Gmsh and CGNS element "
                   "nodes for MSH type %i", mshTag);
      }
      break;
    }

    return nodes;
  }

  // ------------- Conversion of element types between CGNS and Gmsh
  // -------------

  std::vector<CGNS_ENUMT(ElementType_t)> msh2CgnsEltTypeInit()
  {
    std::vector<CGNS_ENUMT(ElementType_t)> cgnsType(
      MSH_MAX_NUM + 1, CGNS_ENUMV(ElementTypeNull));

    // All orders
    cgnsType[MSH_PNT] = CGNS_ENUMV(NODE);

    // Linear elements
    cgnsType[MSH_LIN_2] = CGNS_ENUMV(BAR_2);
    cgnsType[MSH_TRI_3] = CGNS_ENUMV(TRI_3);
    cgnsType[MSH_QUA_4] = CGNS_ENUMV(QUAD_4);
    cgnsType[MSH_TET_4] = CGNS_ENUMV(TETRA_4);
    cgnsType[MSH_PYR_5] = CGNS_ENUMV(PYRA_5);
    cgnsType[MSH_PRI_6] = CGNS_ENUMV(PENTA_6);
    cgnsType[MSH_HEX_8] = CGNS_ENUMV(HEXA_8);

    // Quadratic elements
    cgnsType[MSH_LIN_3] = CGNS_ENUMV(BAR_3);
    cgnsType[MSH_TRI_6] = CGNS_ENUMV(TRI_6);
    cgnsType[MSH_QUA_8] = CGNS_ENUMV(QUAD_8);
    cgnsType[MSH_QUA_9] = CGNS_ENUMV(QUAD_9);
    cgnsType[MSH_TET_10] = CGNS_ENUMV(TETRA_10);
    cgnsType[MSH_PYR_13] = CGNS_ENUMV(PYRA_13);
    cgnsType[MSH_PYR_14] = CGNS_ENUMV(PYRA_14);
    cgnsType[MSH_PRI_15] = CGNS_ENUMV(PENTA_15);
    cgnsType[MSH_PRI_18] = CGNS_ENUMV(PENTA_18);
    cgnsType[MSH_HEX_20] = CGNS_ENUMV(HEXA_20);
    cgnsType[MSH_HEX_27] = CGNS_ENUMV(HEXA_27);

    // Cubic elements
    cgnsType[MSH_LIN_4] = CGNS_ENUMV(BAR_4);
    cgnsType[MSH_TRI_9] = CGNS_ENUMV(TRI_9);
    cgnsType[MSH_TRI_10] = CGNS_ENUMV(TRI_10);
    cgnsType[MSH_QUA_12] = CGNS_ENUMV(QUAD_12);
    cgnsType[MSH_QUA_16] = CGNS_ENUMV(QUAD_16);
    cgnsType[MSH_TET_16] = CGNS_ENUMV(TETRA_16);
    cgnsType[MSH_TET_20] = CGNS_ENUMV(TETRA_20);
    cgnsType[MSH_PYR_21] = CGNS_ENUMV(PYRA_21);
    cgnsType[MSH_PYR_29] = CGNS_ENUMV(PYRA_29);
    cgnsType[MSH_PYR_30] = CGNS_ENUMV(PYRA_30);
    cgnsType[MSH_PRI_24] = CGNS_ENUMV(PENTA_24);
    //  cgnsType[MSH_PRI_38] = CGNS_ENUMV(PENTA_38);
    cgnsType[MSH_PRI_40] = CGNS_ENUMV(PENTA_40);
    cgnsType[MSH_HEX_32] = CGNS_ENUMV(HEXA_32);
    cgnsType[MSH_HEX_56] = CGNS_ENUMV(HEXA_56);
    cgnsType[MSH_HEX_64] = CGNS_ENUMV(HEXA_64);

    // Quartic elements
    cgnsType[MSH_LIN_5] = CGNS_ENUMV(BAR_5);
    cgnsType[MSH_TRI_12] = CGNS_ENUMV(TRI_12);
    cgnsType[MSH_TRI_15] = CGNS_ENUMV(TRI_15);
    cgnsType[MSH_QUA_16] = CGNS_ENUMV(QUAD_16);
    cgnsType[MSH_QUA_25] = CGNS_ENUMV(QUAD_25);
    cgnsType[MSH_TET_22] = CGNS_ENUMV(TETRA_22);
    cgnsType[MSH_TET_34] = CGNS_ENUMV(TETRA_34);
    cgnsType[MSH_TET_35] = CGNS_ENUMV(TETRA_35);
    cgnsType[MSH_PYR_29] = CGNS_ENUMV(PYRA_29);
    //  cgnsType[MSH_PYR_50] = CGNS_ENUMV(PYRA_50);
    cgnsType[MSH_PYR_55] = CGNS_ENUMV(PYRA_55);
    cgnsType[MSH_PRI_33] = CGNS_ENUMV(PENTA_33);
    //  cgnsType[MSH_PRI_66] = CGNS_ENUMV(PENTA_66);
    cgnsType[MSH_PRI_75] = CGNS_ENUMV(PENTA_75);
    cgnsType[MSH_HEX_44] = CGNS_ENUMV(HEXA_44);
    //  cgnsType[MSH_HEX_98] = CGNS_ENUMV(HEXA_98);
    cgnsType[MSH_HEX_125] = CGNS_ENUMV(HEXA_125);

    return cgnsType;
  }

  std::vector<int> cgns2MshEltTypeInit()
  {
    std::vector<int> mshType(NofValidElementTypes, 0);

    // All orders
    mshType[CGNS_ENUMV(NODE)] = MSH_PNT;

    // Linear elements
    mshType[CGNS_ENUMV(BAR_2)] = MSH_LIN_2;
    mshType[CGNS_ENUMV(TRI_3)] = MSH_TRI_3;
    mshType[CGNS_ENUMV(QUAD_4)] = MSH_QUA_4;
    mshType[CGNS_ENUMV(TETRA_4)] = MSH_TET_4;
    mshType[CGNS_ENUMV(PYRA_5)] = MSH_PYR_5;
    mshType[CGNS_ENUMV(PENTA_6)] = MSH_PRI_6;
    mshType[CGNS_ENUMV(HEXA_8)] = MSH_HEX_8;

    // Quadratic elements
    mshType[CGNS_ENUMV(BAR_3)] = MSH_LIN_3;
    mshType[CGNS_ENUMV(TRI_6)] = MSH_TRI_6;
    mshType[CGNS_ENUMV(QUAD_8)] = MSH_QUA_8;
    mshType[CGNS_ENUMV(QUAD_9)] = MSH_QUA_9;
    mshType[CGNS_ENUMV(TETRA_10)] = MSH_TET_10;
    mshType[CGNS_ENUMV(PYRA_13)] = MSH_PYR_13;
    mshType[CGNS_ENUMV(PYRA_14)] = MSH_PYR_14;
    mshType[CGNS_ENUMV(PENTA_15)] = MSH_PRI_15;
    mshType[CGNS_ENUMV(PENTA_18)] = MSH_PRI_18;
    mshType[CGNS_ENUMV(HEXA_20)] = MSH_HEX_20;
    mshType[CGNS_ENUMV(HEXA_27)] = MSH_HEX_27;

    // Cubic elements
    mshType[CGNS_ENUMV(BAR_4)] = MSH_LIN_4;
    mshType[CGNS_ENUMV(TRI_9)] = MSH_TRI_9;
    mshType[CGNS_ENUMV(TRI_10)] = MSH_TRI_10;
    mshType[CGNS_ENUMV(QUAD_12)] = MSH_QUA_12;
    mshType[CGNS_ENUMV(QUAD_16)] = MSH_QUA_16;
    mshType[CGNS_ENUMV(TETRA_16)] = MSH_TET_16;
    mshType[CGNS_ENUMV(TETRA_20)] = MSH_TET_20;
    mshType[CGNS_ENUMV(PYRA_21)] = MSH_PYR_21;
    mshType[CGNS_ENUMV(PYRA_29)] = MSH_PYR_29;
    mshType[CGNS_ENUMV(PYRA_30)] = MSH_PYR_30;
    mshType[CGNS_ENUMV(PENTA_24)] = MSH_PRI_24;
    //  mshType[CGNS_ENUMV(PENTA_38)] = MSH_PRI_38;
    mshType[CGNS_ENUMV(PENTA_40)] = MSH_PRI_40;
    mshType[CGNS_ENUMV(HEXA_32)] = MSH_HEX_32;
    mshType[CGNS_ENUMV(HEXA_56)] = MSH_HEX_56;
    mshType[CGNS_ENUMV(HEXA_64)] = MSH_HEX_64;

    // Quartic elements
    mshType[CGNS_ENUMV(BAR_5)] = MSH_LIN_5;
    mshType[CGNS_ENUMV(TRI_12)] = MSH_TRI_12;
    mshType[CGNS_ENUMV(TRI_15)] = MSH_TRI_15;
    mshType[CGNS_ENUMV(QUAD_16)] = MSH_QUA_16;
    mshType[CGNS_ENUMV(QUAD_25)] = MSH_QUA_25;
    mshType[CGNS_ENUMV(TETRA_22)] = MSH_TET_22;
    mshType[CGNS_ENUMV(TETRA_34)] = MSH_TET_34;
    mshType[CGNS_ENUMV(TETRA_35)] = MSH_TET_35;
    mshType[CGNS_ENUMV(PYRA_29)] = MSH_PYR_29;
    //  mshType[CGNS_ENUMV(PYRA_50)] = MSH_PYR_50;
    mshType[CGNS_ENUMV(PYRA_55)] = MSH_PYR_55;
    mshType[CGNS_ENUMV(PENTA_33)] = MSH_PRI_33;
    //  mshType[CGNS_ENUMV(PENTA_66)] = MSH_PRI_66;
    mshType[CGNS_ENUMV(PENTA_75)] = MSH_PRI_75;
    mshType[CGNS_ENUMV(HEXA_44)] = MSH_HEX_44;
    //  mshType[CGNS_ENUMV(HEXA_98)] = MSH_HEX_98;
    mshType[CGNS_ENUMV(HEXA_125)] = MSH_HEX_125;

    return mshType;
  }

} // namespace

// msh to CGNS element type
CGNS_ENUMT(ElementType_t) msh2CgnsEltType(int mshTag)
{
  static std::vector<CGNS_ENUMT(ElementType_t)> cgnsType =
    msh2CgnsEltTypeInit();

  if(mshTag >= static_cast<int>(cgnsType.size()))
    return CGNS_ENUMV(ElementTypeNull);
  return cgnsType[mshTag];
}

// CGNS to msh element type
int cgns2MshEltType(CGNS_ENUMT(ElementType_t) cgnsType)
{
  static std::vector<int> mshType = cgns2MshEltTypeInit();

  if(cgnsType >= static_cast<int>(mshType.size())) return 0;
  return mshType[cgnsType];
}

// CGNS to msh node ordering
std::vector<int> &cgns2MshNodeIndex(int mshTag)
{
  static std::vector<std::vector<int> > mshInd(MSH_MAX_NUM + 1);
  static std::vector<int> dumInd;

  if(mshTag > MSH_MAX_NUM) return dumInd;

  if(mshInd[mshTag].size() == 0) {
    mshInd[mshTag] = cgns2MshNodeIndexInit(mshTag);
  }

  return mshInd[mshTag];
}

// // msh to CGNS node ordering
// std::vector<int> &msh2CgnsNodeIndex(int mshTag)
// {
//   static std::vector<std::vector<int> > cgnsInd(MSH_MAX_NUM+1);
//   static std::vector<int> dumInd;

//   if(mshTag > MSH_MAX_NUM) return dumInd;

//   if(cgnsInd[mshTag].size() == 0) {
//     std::vector<int> &mshInd = cgns2MshNodeIndex(mshTag);
//     std::vector<int> &ind = cgnsInd[mshTag];
//     for(int iV = 0; iV < mshInd.size(); iV++) ind[mshInd[iV]] = iV;
//   }

//   return cgnsInd[mshTag];
// }

void msh2CgnsReferenceElement(int mshType, const fullMatrix<double> &mshPts,
                              std::vector<double> &u, std::vector<double> &v,
                              std::vector<double> &w)
{
  int parentType = ElementType::getParentType(mshType);

  switch(parentType) {
  case TYPE_PNT: u[0] = mshPts(0, 0); break;
  case TYPE_LIN: // Gmsh and CGNS both in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) { u[i] = mshPts(i, 0); }
    break;
  case TYPE_QUA: // Gmsh and CGNS both in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) {
      u[i] = mshPts(i, 0);
      v[i] = mshPts(i, 1);
    }
    break;
  case TYPE_HEX: // Gmsh and CGNS both in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) {
      u[i] = mshPts(i, 0);
      v[i] = mshPts(i, 1);
      w[i] = mshPts(i, 2);
    }
    break;
  case TYPE_TRI: // Gmsh in [0, 1], CGNS in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) {
      u[i] = 2. * mshPts(i, 0) - 1.;
      v[i] = 2. * mshPts(i, 1) - 1.;
    }
    break;
  case TYPE_TET: // Gmsh in [0, 1], CGNS in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) {
      u[i] = 2. * mshPts(i, 0) - 1.;
      v[i] = 2. * mshPts(i, 1) - 1.;
      w[i] = 2. * mshPts(i, 2) - 1.;
    }
    break;
  case TYPE_PRI: // uv: Gmsh in [0, 1] and CGNS in [-1, 1], w: both in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) {
      u[i] = 2. * mshPts(i, 0) - 1.;
      v[i] = 2. * mshPts(i, 1) - 1.;
      w[i] = mshPts(i, 2);
    }
    break;
  case TYPE_PYR: // uv: both in [-1, 1], w: Gmsh in [0, 1] and CGNS in [-1, 1]
    for(int i = 0; i < mshPts.size1(); i++) {
      u[i] = mshPts(i, 0);
      v[i] = mshPts(i, 1);
      w[i] = 2. * mshPts(i, 2) - 1.;
    }
    break;
  default:
    Msg::Error("CGNS element %s not yet implemented",
               ElementType::nameOfParentType(parentType).c_str());
  }
}

bool computeReordering(fullMatrix<double> src, fullMatrix<double> dest,
                       std::vector<int> &ind)
{
  static const double TOLSQ = 1e-10 * 1e-10;

  const size_t nNode = src.size1(), dim = src.size2();
  ind.resize(nNode, -1);

  // Loop over src and dest nodes and check distance
  std::set<int> found;
  for(size_t iSrc = 0; iSrc < nNode; iSrc++) {
    for(size_t iDest = 0; iDest < nNode; iDest++) {
      const double xx = src(iSrc, 0) - dest(iDest, 0);
      const double yy = (dim > 1) ? src(iSrc, 1) - dest(iDest, 1) : 0.;
      const double zz = (dim > 2) ? src(iSrc, 2) - dest(iDest, 2) : 0.;
      const double dd = xx * xx + yy * yy + zz * zz;
      if(dd < TOLSQ) {
        ind[iSrc] = iDest;
        found.insert(iDest);
        break;
      }
    }
  }

  // Check bijectivity
  return (found.size() == nNode);
}

std::string cgnsString(const std::string &s, std::string::size_type maxLength)
{
  // From the CGNS documentation: "Names or identifiers contain no spaces and
  // capitalization is used to distinguish individual words making up a name;
  // names are case-sensitive. The character "/" should be avoided in names, as
  // well as the names "." and "..", as these have special meaning when
  // referencing elements of a structure entity. An entity name cannot exceed 32
  // characters."

  std::string s2(s);

  if(!s2.compare(0, 1, ".")) s2[0] = '_';
  if(!s2.compare(0, 2, "..")) s2[0] = s2[1] = '_';
  ReplaceSubStringInPlace("/", "_", s2);
  ReplaceSubStringInPlace(" ", "_", s2);

  if(s2.size() > maxLength) s2.resize(maxLength);
  return s2;
}

#endif // HAVE_LIBCGNS
