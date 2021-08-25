// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblOptimizeGeometry.h"
#include "hblSolveAllHexLayer.h"

#include <unordered_map>
#include <queue>

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

/* HexMeshingTools includes */
#include "hblLogging.hpp"
#include "hblTypes.hpp"
#include "hblUtils.h"
#include "hblBrepMesh.h"
#include "hblBuildAllHexLayer.h"
#include "hblGmshIO.h"
#include "hblBuildInteriorMesh.h"
#include "cppUtils.h"
#include "geolog.h"

/* WinslowUntangler includes */
#if defined(HAVE_WINSLOWUNTANGLER)
#include "winslowUntangler.h"
#include "meshVolumeUntangling.h"
#endif

/* Gmsh includes */
#include "GEntity.h"
#include "GEdge.h"
#include "GFace.h"
#include "gmsh.h"
#include "MHexahedron.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MVertex.h"
#include "StringUtils.h"
#include "Numeric.h"
#include "BasisFactory.h"
#include "CondNumBasis.h"
#include "robin_hood.h"


/* - Useful macros */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)


using std::vector;
using std::map;
using std::unordered_map;
using std::array;
using std::pair;


namespace hbl {
  using namespace CppUtils;
  using namespace ArrayGeometry;

  const double EPS0 = 1.e-15;

  const uint32_t hex2tet_corners[8][4] = {
    {0,1,2,5}, {1,2,3,6}, {2,3,0,7}, {3,0,1,4},
    {6,5,4,1}, {5,4,7,0}, {4,7,6,3}, {7,6,5,2}, 
  };

  const uint32_t hex2tet_24[24][4] = {
    {0, 1, 2, 4}, {0, 1, 3, 5}, {0, 3, 7, 1}, {0, 3, 4, 2},
    {0, 4, 1, 7}, {0, 4, 5, 3}, {1, 2, 0, 6}, {1, 2, 3, 5},
    {1, 5, 2, 4}, {1, 5, 6, 0}, {3, 2, 6, 0}, {3, 2, 7, 1},
    {3, 7, 0, 6}, {3, 7, 4, 2}, {2, 6, 7, 1}, {2, 6, 3, 5},
    {4, 5, 0, 6}, {4, 5, 1, 7}, {4, 7, 5, 3}, {4, 7, 6, 0},
    {5, 6, 1, 7}, {5, 6, 2, 4}, {7, 6, 5, 3}, {7, 6, 4, 2}
  };

  enum HexDcp {
    TO_8TETS,
    TO_24TETS,
    TO_32TETS
  };

  std::vector<std::array<uint32_t,4> > tetsFromHex(const id8& hex, HexDcp dcp = TO_24TETS) {
    vector<array<uint32_t,4> > tets;
    if (dcp == TO_8TETS || dcp == TO_32TETS) {
      for (size_t i = 0; i < 8; ++i) {
        tets.push_back({hex[hex2tet_corners[i][0]], hex[hex2tet_corners[i][1]],
            hex[hex2tet_corners[i][2]], hex[hex2tet_corners[i][3]]});
      }
    }
    if (dcp == TO_24TETS || dcp == TO_32TETS) {
      for (size_t i = 0; i < 24; ++i) {
        tets.push_back({hex[hex2tet_24[i][0]], hex[hex2tet_24[i][1]],
            hex[hex2tet_24[i][2]], hex[hex2tet_24[i][3]]});
      }
    }
    return tets;
  }

  const std::vector<std::array<double,3> > unit_cube = {
    {0.,0.,0.}, {1.,0.,0.}, {1.,1.,0.}, {0.,1.,0.},
    {0.,0.,1.}, {1.,0.,1.}, {1.,1.,1.}, {0.,1.,1.}
  };

  std::vector<std::array<std::array<double,3>,4> > tetsFromHexIdealShapes(HexDcp dcp = TO_24TETS) {
    std::vector<std::array<std::array<double,3>,4> > shapes;
    if (dcp == TO_8TETS || dcp == TO_32TETS) {
      for (size_t i = 0; i < 8; ++i) {
        shapes.push_back({unit_cube[hex2tet_corners[i][0]], unit_cube[hex2tet_corners[i][1]],
            unit_cube[hex2tet_corners[i][2]], unit_cube[hex2tet_corners[i][3]]});
      }
    }
    if (dcp == TO_24TETS || dcp == TO_32TETS) {
      for (size_t i = 0; i < 24; ++i) {
        shapes.push_back({unit_cube[hex2tet_24[i][0]], unit_cube[hex2tet_24[i][1]],
            unit_cube[hex2tet_24[i][2]], unit_cube[hex2tet_24[i][3]]});
      }
    }
    return shapes;
  }


  std::array<uint32_t,4> invert(const std::array<uint32_t,4>& tet) {
    return {tet[0],tet[1],tet[3],tet[2]};
  }

  std::array<array<double,3>,4 > invert_shape(const std::array<array<double,3>,4 >& shape) {
    return {shape[0],shape[1],shape[3],shape[2]};
  }

  double tetrahedronScaledJacobian(const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3) {
    /* From Verdict quality library PDF */
    const vec3 L0 = p1-p0;
    const vec3 L1 = p2-p1;
    const vec3 L2 = p0-p2;
    const vec3 L3 = p3-p0;
    const vec3 L4 = p3-p1;
    const vec3 L5 = p3-p2;
    const double J = dot(cross(L2,L0),L3);
    const double len[6] = {length(L0), length(L1), length(L2), length(L3), length(L4), length(L5)};
    double lambda_max = std::max(J,len[0]*len[2]*len[3]);
    lambda_max = std::max(lambda_max,len[0]*len[2]*len[4]);
    lambda_max = std::max(lambda_max,len[1]*len[2]*len[5]);
    lambda_max = std::max(lambda_max,len[3]*len[4]*len[5]);
    if (lambda_max == 0.) return -1.;
    return clamp(std::sqrt(2.) * J / lambda_max,-1.,1.);
  }

//   double hexQuality(const vector<vec3>& points, const id8& hex, HexDcp dcp) {
//     double qMin = DBL_MAX;
//     vector<array<uint32_t,4> > htets = tetsFromHex(hex,dcp);
//     for (size_t j = 0; j < htets.size(); ++j) {
//       double o = tetrahedronScaledJacobian(points[htets[j][0]], points[htets[j][1]], points[htets[j][2]], points[htets[j][3]]);
//       qMin = std::min(qMin,o);
//     }
//     return qMin;
//   }
// 
//   bool hexQualities(const vector<vec3>& points, const vector<id8>& hexes, vector<double>& quality, 
//       HexDcp dcp) {
//     quality.resize(hexes.size());
//     for (size_t i = 0; i < hexes.size(); ++i) {
//       quality[i] = hexQuality(points, hexes[i], dcp);
//     }
//     return true;
//   }
// 
//   double elementQuality(const vector<vec3>& points, const vector<id>& vert, HexDcp dcp = TO_8TETS) {
//     if (vert.size() == 8) {
//       const id8 hex = {
//         vert[0], vert[1], vert[2], vert[3],
//         vert[4], vert[5], vert[6], vert[7] };
//       return hexQuality(points, hex, dcp);
//     } else if (vert.size() == 4) {
//       return tetrahedronScaledJacobian(points[vert[0]], points[vert[1]], 
//           points[vert[2]], points[vert[3]]);
//     }
//     return -DBL_MAX;
//   }
// 
//   double tetMinSICN(const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3) 
//   {
// #if defined(HAVE_MESH)
//     const CondNumBasis *cnb = BasisFactory::getCondNumBasis(MSH_TET_4);
//     const int numCNNodes = cnb->getNumCondNumNodes();
//     fullMatrix<double> nodesXYZ(cnb->getNumMapNodes(), 3), normals;
//     for (size_t d = 0; d < 3; ++d) {
//       nodesXYZ(0,d) = p0[d];
//       nodesXYZ(1,d) = p1[d];
//       nodesXYZ(2,d) = p2[d];
//       nodesXYZ(3,d) = p3[d];
//     }
//     fullVector<double> invCondNum(numCNNodes);
//     cnb->getSignedInvCondNum(nodesXYZ, normals, invCondNum);
//     double q = *std::min_element(invCondNum.getDataPtr(),
//         invCondNum.getDataPtr() + numCNNodes);
//     if (std::isnan(q)) return -1.;
//     return q;
// #endif
//     return -DBL_MAX;
//   }
// 
//   double hexMinSICN(const vec3& p0, const vec3& p1, const vec3& p2, const vec3& p3, 
//       const vec3& p4, const vec3& p5, const vec3& p6, const vec3& p7) {
// #if defined(HAVE_MESH)
//     const CondNumBasis *cnb = BasisFactory::getCondNumBasis(MSH_HEX_8);
//     const int numCNNodes = cnb->getNumCondNumNodes();
//     fullMatrix<double> nodesXYZ(cnb->getNumMapNodes(), 3), normals;
//     for (size_t d = 0; d < 3; ++d) {
//       nodesXYZ(0,d) = p0[d];
//       nodesXYZ(1,d) = p1[d];
//       nodesXYZ(2,d) = p2[d];
//       nodesXYZ(3,d) = p3[d];
//       nodesXYZ(4,d) = p4[d];
//       nodesXYZ(5,d) = p5[d];
//       nodesXYZ(6,d) = p6[d];
//       nodesXYZ(7,d) = p7[d];
//     }
//     fullVector<double> invCondNum(numCNNodes);
//     cnb->getSignedInvCondNum(nodesXYZ, normals, invCondNum);
//     double q = *std::min_element(invCondNum.getDataPtr(),
//         invCondNum.getDataPtr() + numCNNodes);
//     if (std::isnan(q)) return -1.;
//     return q;
// #endif
//     return -DBL_MAX;
//   }


  std::string metricName(QualityMetric m) {
    if (m == QualityMetric::SICN) {
      return "SICN";
    } else if (m == QualityMetric::SIGE) {
      return "SIGE";
    } 
    return "NONE";
  }

  class QualityComputer {
    // WARNING: not thread safe !!
    public:
      QualityComputer() {
        F(k,8) { vert[k] = new MVertex(0.,0.,0.,nullptr); }
        hex = new MHexahedron(vert[0], vert[1], vert[2], vert[3], vert[4], vert[5], vert[6], vert[7]);
        tet = new MTetrahedron(vert[0], vert[1], vert[2], vert[3]);
        quad = new MQuadrangle(vert[0], vert[1], vert[2], vert[3]);
        tri = new MTriangle(vert[0], vert[1], vert[2]);
      }

      ~QualityComputer() {
        F(k,8) {delete vert[k]; }
        delete hex;
        delete tet;
        delete quad;
        delete tri;
      }

      double minQualityTet(const std::array<vec3,4>& pts, QualityMetric m) {
        F(k,pts.size()) { vert[k]->setXYZ(pts[k][0],pts[k][1],pts[k][2]); }
        double q = -1.;
        if (m == QualityMetric::SICN) {
          q = tet->minSICNShapeMeasure();
        } else if (m == QualityMetric::SIGE) {
          q = tet->minSIGEShapeMeasure();
        }
        if (std::isnan(q)) return -1.;
        return q;
      }

      double minQualityTri(const std::array<vec3,3>& pts, QualityMetric m) {
        F(k,pts.size()) { vert[k]->setXYZ(pts[k][0],pts[k][1],pts[k][2]); }
        double q = -1.;
        if (m == QualityMetric::SICN) {
          q = tri->minSICNShapeMeasure();
        } else if (m == QualityMetric::SIGE) {
          q = tri->minSIGEShapeMeasure();
        }
        if (std::isnan(q)) return -1.;
        return q;
      }

      double minQualityQuad(const std::array<vec3,4>& pts, QualityMetric m) {
        F(k,pts.size()) { vert[k]->setXYZ(pts[k][0],pts[k][1],pts[k][2]); }
        double q = -1.;
        if (m == QualityMetric::SICN) {
          q = quad->minSICNShapeMeasure();
        } else if (m == QualityMetric::SIGE) {
          q = quad->minSIGEShapeMeasure();
        }
        if (std::isnan(q)) return -1.;
        return q;
      }

      double minQualityHex(const std::array<vec3,8>& pts, QualityMetric m) {
        F(k,pts.size()) { vert[k]->setXYZ(pts[k][0],pts[k][1],pts[k][2]); }
        double q = -1.;
        if (m == QualityMetric::SICN) {
          q = hex->minSICNShapeMeasure();
        } else if (m == QualityMetric::SIGE) {
          q = hex->minSIGEShapeMeasure();
        }
        if (std::isnan(q)) return -1.;
        return q;
      }

      double volume(const std::vector<vec3>& pts) {
        if (pts.size() == 4) {
          return 1./6.*basicOrient3d(pts[0],pts[1],pts[2],pts[3]);
        } else if (pts.size() == 8) {
          F(k,pts.size()) { vert[k]->setXYZ(pts[k][0],pts[k][1],pts[k][2]); }
          return hex->getVolume();
        } 
        Msg::Error("unexpected");
        return -DBL_MAX;
      }


    private:
      MVertex* vert[8];
      MHexahedron* hex;
      MTetrahedron* tet;
      MQuadrangle *quad;
      MTriangle *tri;
  };

  QualityComputer qcomp;

  double cellQuality(const vector<vec3>& points, const vector<id>& vert, QualityMetric m) {
    if (vert.size() == 8) {
      return qcomp.minQualityHex({points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]],
          points[vert[4]], points[vert[5]], points[vert[6]], points[vert[7]]},m);
    } else if (vert.size() == 4) {
      return qcomp.minQualityTet({points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]]},m);
    }
    Msg::Error("cellQuality, size %li unexpected", vert.size());
    return -DBL_MAX;
  }

  bool computeQuadQualities(const vector<vec3>& points, const vector<id4>& quads, vector<double>& quality, QualityMetric m) {
    quality.resize(quads.size(),-1.);
    F(c,quads.size()) {
      const std::array<vec3,4> pts = { points[quads[c][0]], points[quads[c][1]], points[quads[c][2]], points[quads[c][3]] };
      quality[c] = qcomp.minQualityQuad(pts,m);
    }
    return true;
  }

  bool computeHexQualities(const vector<vec3>& points, const vector<id8>& hexes, vector<double>& quality, QualityMetric m) {
    quality.resize(hexes.size(),-1.);
    F(c,hexes.size()) {
      const id8& vert = hexes[c];
      quality[c] = qcomp.minQualityHex({points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]],
          points[vert[4]], points[vert[5]], points[vert[6]], points[vert[7]]},m);
    }
    return true;
  }

  bool computeTetQualities(const vector<vec3>& points, const vector<id4>& tets, vector<double>& quality, QualityMetric m) {
    quality.resize(tets.size(),-1.);
    F(c,tets.size()) {
      const id4& vert = tets[c];
      quality[c] = qcomp.minQualityTet({points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]]},m);
    }
    return true;
  }

  double vector_median(const vector<double>& values) {
    vector<double> values2 = values;
    size_t n = values.size() / 2;
    nth_element(values2.begin(), values2.begin()+n, values2.end());
    double median = values2[n];
    return median;
  }

  void print_stats(const std::string& text, const vector<double>& values) {
    double vMin, vMax, vAvg;
    vector_statistics(values, vMin, vMax, vAvg);
    double med = vector_median(values);
    size_t nneg = 0;
    for (double v: values) if (v<0.) nneg += 1;
    if (vMin > -9.9 && vMax < 9.9 && (std::abs(vMin) > 0.1 || std::abs(vMax) > 0.1) ) {
      info("{}: min={} < avg={} - median={} < max={}, {} negative", text, vMin, vAvg, med, vMax, nneg);
    } else {
      info("{}: min={} < avg={} - median={} < max={}, {} negative", text, vMin, vAvg, med, vMax, nneg);
    }
  }

  double get_min_quality(const vector<vec3>& points, const vector<id8>& hexes, QualityMetric m) {
    vector<double> quality(hexes.size());
    computeHexQualities(points, hexes, quality, m);
    double vMin, vMax, vAvg;
    vector_statistics(quality, vMin, vMax, vAvg);
    return vMin;
  }

  void print_quality_stats(const std::string& text, const vector<vec3>& points, const vector<id8>& hexes, QualityMetric m) {
    vector<double> quality(hexes.size());
    computeHexQualities(points, hexes, quality, m);
    print_stats(text, quality);
  }

  void print_quality_stats(const std::string& text, const vector<vec3>& points, const vector<vector<id> >& eltVertices, QualityMetric m) {
    vector<double> quality(eltVertices.size(),-1.);
    F(i,eltVertices.size()) {
      quality[i] = cellQuality(points,eltVertices[i],m);
    }
    print_stats(text, quality);
  }

  bool invert_elements_if_required(const vector<vec3>& points, vector<vector<id> >& eltVertices, const vector<int>& ballId) {
    if (eltVertices.size() == 0) return false;

    int ballMax = *std::max_element(ballId.begin(),ballId.end());

    for (int ball = 1; ball <= ballMax; ++ball) {
    /* Check average volume */
      double sum = 0.;
      for (size_t i = 0; i < eltVertices.size(); ++i) if (ballId[i] == ball) {
        if (eltVertices[i].size() == 8) {
          const id8 hex = {
            eltVertices[i][0], eltVertices[i][1], eltVertices[i][2], eltVertices[i][3],
            eltVertices[i][4], eltVertices[i][5], eltVertices[i][6], eltVertices[i][7] };
          vector<array<uint32_t,4> > htets = tetsFromHex(hex, HexDcp::TO_8TETS);
          for (size_t j = 0; j < htets.size(); ++j) {
            double o = basicOrient3d(points[htets[j][0]], points[htets[j][1]], points[htets[j][2]], points[htets[j][3]]);
            sum += o;
          }
        } else if (eltVertices[i].size() == 4) {
          double o = basicOrient3d(points[eltVertices[i][0]], points[eltVertices[i][1]], 
              points[eltVertices[i][2]], points[eltVertices[i][3]]);
          sum += o;
        }
      }

      if (sum < 0.) {
        debug("invert hexes | ball {}, total volume is negative: {}, inverting all elements", ball, sum);

        for (size_t i = 0; i < eltVertices.size(); ++i) if (ballId[i] == ball) {
          if (eltVertices[i].size() == 8) {
            const id8 hex = {
              eltVertices[i][0], eltVertices[i][1], eltVertices[i][2], eltVertices[i][3],
              eltVertices[i][4], eltVertices[i][5], eltVertices[i][6], eltVertices[i][7] };
            const id8 ihex = invert_hex(hex);
            for (size_t j = 0; j < 8; ++j) eltVertices[i][j] = ihex[j];
          } else if (eltVertices[i].size() == 4) {
            id v3 = eltVertices[i][3];
            eltVertices[i][3] = eltVertices[i][2];
            eltVertices[i][2] = v3;
          }
        }
      }
    }

    return true;
  }

  std::array<double,5> computeInputQualityStatsMinMedAvgMaxInv(const BrepMesh& M, QualityMetric m) {
    vector<double> values(M.faces.size(),-1.);
    vector<id> vert(4);
    F(f,M.faces.size()) {
      face_vertices(M,f,vert);
      if (vert.size() == 3) {
        std::array<vec3,3> pts = {
          M.vertices[vert[0]].pt, M.vertices[vert[1]].pt,
          M.vertices[vert[2]].pt};
        values[f] = qcomp.minQualityTri(pts,m);
      } else if (vert.size() == 4) {
        std::array<vec3,4> pts = {
          M.vertices[vert[0]].pt, M.vertices[vert[1]].pt,
          M.vertices[vert[2]].pt, M.vertices[vert[3]].pt};
        values[f] = qcomp.minQualityQuad(pts,m);
      }
    }
    std::array<double,5> minMedAvgMaxInv = {-1.,-1.,-1.,-1.,-1.};
    vector_statistics(values, minMedAvgMaxInv[0], minMedAvgMaxInv[3], minMedAvgMaxInv[2]);
    minMedAvgMaxInv[1] = vector_median(values);
    minMedAvgMaxInv[4] = 0;
    for (double v: values) if (v<0.) minMedAvgMaxInv[4] += 1;
    return minMedAvgMaxInv;
  }

  std::array<double,5> computeHexQualityStatsMinMedAvgMaxInv(const HblOutput& output, QualityMetric m) {
    std::array<double,5> minMedAvgMaxInv = {-1.,-1.,-1.,-1.,-1.};
    vector<vec3> points;
    points.resize(output.H.vertices.size());
    F(v,points.size()) points[v] = output.H.vertices[v].pt;
    vector<double> qualities;
    F(i,output.hexahedra.size()) {
      const id8& vert = output.hexahedra[i];
      std::array<vec3,8> pts = {points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]],
          points[vert[4]], points[vert[5]], points[vert[6]], points[vert[7]]};
      qualities.push_back(qcomp.minQualityHex(pts,m));
    }
    vector_statistics(qualities, minMedAvgMaxInv[0], minMedAvgMaxInv[3], minMedAvgMaxInv[2]);
    minMedAvgMaxInv[1] = vector_median(qualities);
    minMedAvgMaxInv[4] = 0;
    for (double v: qualities) if (v<0.) minMedAvgMaxInv[4] += 1;
    return minMedAvgMaxInv;

  }
  std::array<double,5> computeTetQualityStatsMinMedAvgMaxInv(const HblOutput& output, QualityMetric m) {
    std::array<double,5> minMedAvgMaxInv = {-1.,-1.,-1.,-1.,-1.};
    vector<vec3> points;
    points.resize(output.H.vertices.size());
    F(v,points.size()) points[v] = output.H.vertices[v].pt;
    vector<double> qualities;
    F(i,output.tetrahedra.size()) {
      const id4& vert = output.tetrahedra[i];
      std::array<vec3,4> pts = {points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]]};
      qualities.push_back(qcomp.minQualityTet(pts,m));
    }
    vector_statistics(qualities, minMedAvgMaxInv[0], minMedAvgMaxInv[3], minMedAvgMaxInv[2]);
    minMedAvgMaxInv[1] = vector_median(qualities);
    minMedAvgMaxInv[4] = 0;
    for (double v: qualities) if (v<0.) minMedAvgMaxInv[4] += 1;
    return minMedAvgMaxInv;

  }

  std::array<double,5> computeHexTetQualityStatsMinMedAvgMaxInv(const HblOutput& output, QualityMetric m) {
    std::array<double,5> minMedAvgMaxInv = {-1.,-1.,-1.,-1.,-1.};
    vector<vec3> points;
    points.resize(output.H.vertices.size());
    F(v,points.size()) points[v] = output.H.vertices[v].pt;
    vector<double> qualities;
    F(i,output.hexahedra.size()) {
      const id8& vert = output.hexahedra[i];
      std::array<vec3,8> pts = {points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]],
          points[vert[4]], points[vert[5]], points[vert[6]], points[vert[7]]};
      qualities.push_back(qcomp.minQualityHex(pts,m));
    }
    F(i,output.tetrahedra.size()) {
      const id4& vert = output.tetrahedra[i];
      std::array<vec3,4> pts = {points[vert[0]], points[vert[1]], points[vert[2]], points[vert[3]]};
      qualities.push_back(qcomp.minQualityTet(pts,m));
    }
    vector_statistics(qualities, minMedAvgMaxInv[0], minMedAvgMaxInv[3], minMedAvgMaxInv[2]);
    minMedAvgMaxInv[1] = vector_median(qualities);
    minMedAvgMaxInv[4] = 0;
    for (double v: qualities) if (v<0.) minMedAvgMaxInv[4] += 1;
    return minMedAvgMaxInv;
  }

  bool extract_interior_quad_meshes(
      const BrepMesh& H, 
      const HexToBoundaryMeshMatching& h2q,
      std::vector<std::vector<id> >& quadMeshFaces
    ) {
    RFC(H.faceToCells.size() != H.faces.size(), "extract interior quad meshes requires updated faceToCells mapping");
    RFC(H.edgeToFaces.size() != H.edges.size(), "extract interior quad meshes requires updated edgeToFaces mapping");

    /* Flag interior quad faces (not touching initial boundary) */
    vector<bool> iquad(H.faces.size(),false);
    F(f,H.faces.size()) {
      if (H.faceToCells[f].size() == 2) continue;
      if (h2q.faceParent[f].first < 3) continue;
      iquad[f] = true;
    }

    /* BFS on interior quads to multiple components if there are */
    vector<id> assigned(H.faces.size(),NO_ID);
    vector<vector<id>> ball_quads;
    FC(fInit,H.faces.size(),iquad[fInit] && assigned[fInit] == NO_ID) {
      vector<id> quads;
      std::queue<id> Q;
      Q.push(fInit);
      assigned[fInit] = ball_quads.size();

      while(Q.size() > 0) {
        id f = Q.front();
        Q.pop();
        quads.push_back(f);
        for (id e: H.faces[f].edges) {
          for (id f2: H.edgeToFaces[e]) {
            if (f2 == f) continue;
            if (!iquad[f2]) continue;
            if (assigned[f2] != NO_ID) continue;
            Q.push(f2);
            assigned[f2] = ball_quads.size();
          }
        }
      }
      sort_unique(quads);
      ball_quads.push_back(quads);
    }

    /* Create quad meshes */
    F(i,ball_quads.size()) {
      quadMeshFaces.resize(quadMeshFaces.size()+1);
      vector<id>& qmFaces = quadMeshFaces.back();
      for (id f: ball_quads[i]) {
        qmFaces.push_back(f);
      }
    }

    return true;
  }

  bool brep_boundary_fan_around_vertex(
      const BrepMesh& M, 
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      id v, vector<id>& faces, vector<id>& edges) {
    faces.clear();
    edges.clear();
    RFC(v > M.vertToEdges.size(), "fan | v = {} > M.vertToEdges.size() = {}", v, M.vertToEdges.size());
    RFC(M.vertToEdges[v].size() < 2, "fan | v = {}, M.vertToEdges[v].size() = {}", v, M.vertToEdges[v].size());

    /* Initialization */
    id eStart = NO_ID;
    id fStart = NO_ID;
    for (id e: M.vertToEdges[v]) if (h2q.edgeParent[e].first <= 2) {
      eStart = e;
      break;
    }
    RFC(eStart == NO_ID, "fan | v = {}, eStart not found", v);

    for (id f: M.edgeToFaces[eStart]) if (h2q.faceParent[f].first <= 2) {
      fStart = f;
      break;
    }
    RFC(fStart == NO_ID, "fan | v = {} (parent: {}), fStart not found", v, h2q.vertexParent[v]);

    /* Fan around v */
    id e = eStart;
    id f = fStart;
    id it = 0;
    while (edges.size() == 0 || e != eStart) {
      it += 1;
      RFC(it > 1000, "fan | infinite loop ? it = {}", it);
      // RFC(M.edgeToFaces[e].size() != 2, "fan | M.edgeToFaces[{}] = {}", e, M.edgeToFaces[e]);
      faces.push_back(f);
      edges.push_back(e);
      id e_next = NO_ID;
      F(i,M.faces[f].edges.size()) {
        id e2 = M.faces[f].edges[i];
        if (h2q.edgeParent[e2].first >= 3) continue;
        if (e2 != e && (M.edges[e2].vertices[0] == v || M.edges[e2].vertices[1] == v)) {
          e_next = e2;
          break;
        }
      }
      RFC(e_next == NO_ID, "fan | e_next = {}, it = {}", e_next, it);
      // RFC(M.edgeToFaces[e_next].size() != 2, "fan | M.edgeToFaces[{}] = {}", e, M.edgeToFaces[e]);
      id f_next = NO_ID;
      for (id fc: M.edgeToFaces[e_next]) if (h2q.faceParent[fc].first <= 2) {
        if (fc != f) {
          f_next = fc;
          break;
        }
      }
      RFC(f_next == NO_ID, "fan | e_next = {}, f_next = {}, it = {}", e_next, f_next, it);

      e = e_next;
      f = f_next;
    }
    RFC(edges.size() < 2 || faces.size() < 2, "fan | v = {}, it = {}, edges = {}, faces = {}", v, it, edges, faces);

    return true;
  }

  std::vector<id> incidentBoundaryEdges(
      const BrepMesh& H, 
      const HexToBoundaryMeshMatching& h2q,
      id v) {
    vector<id> bedges;
    for (id e: H.vertToEdges[v]) {
      if (h2q.edgeParent[e].first <= 2) {
        bedges.push_back(e);
      }
    }
    return bedges;
  }

  double averageBoundaryEdgeLengthAround(
      const BrepMesh& H, 
      const HexToBoundaryMeshMatching& h2q,
      id v,
      bool secondRing) {
    vector<id> bedges = incidentBoundaryEdges(H,h2q,v);
    if (secondRing) {
      vector<id> others;
      for (id e: bedges) {
        id v2 = edge_opposite_vertex(H.edges[e].vertices,v);
        append(others,incidentBoundaryEdges(H,h2q,v2));
      }
      append(bedges,others);
      sort_unique(bedges);
    }
    if (bedges.size() == 0) return 0.;
    double avg = 0.;
    for (id e: bedges) {
      avg += edge_length(H,e);
    }
    return avg / double(bedges.size());
  }

  bool set_position_extruded_edges(const HblOptions& opt, BrepMesh& H, 
      const vector<int>& edgeVal, /* edge hex-valence */
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      const std::vector<vec3>& HfaceNormal,
      vector<bool>& bdrVertexDone,
      double uniformExtrusionLength = DBL_MAX) {
    debug("set_position_extruded_edges ...");
    warn("OBSOLETE ? ...");

    vector<vec3> new_pos(H.vertices.size(),{0.,0.,0.});
    vector<double> new_pos_sum(H.vertices.size(),0.);
    vector<id> faces;
    vector<id> edges;
    FC(v,H.vertices.size(),h2q.vertexParent[v].first <= 2) {
      brep_boundary_fan_around_vertex(H, Q, h2q, v, faces, edges);
      RFC(edges.size() < 3 || edges.size() != faces.size(), "wrong quad mesh at v={}, faces={}, edges={}", v, faces, edges);
      vector<id> bdrVal(edges.size(),0);
      F(i,edges.size()) {
        id e = edges[i];
        if (h2q.edgeParent[e].first == 1) {
          bdrVal[i] = edgeVal[h2q.edgeParent[e].second];
        } else {
          bdrVal[i] = 2;
        }
      }
      vector<id> nb_each(1000);
      for (id val: bdrVal) nb_each[val] += 1;
      /* Check if extrusion */
      if (nb_each[2] != bdrVal.size()) continue; /* not extrusion */

      /* Interior extruded vertex */
      id v2 = NO_ID;
      F(le,H.vertToEdges[v].size()) {
        id e = H.vertToEdges[v][le];
        if (h2q.edgeParent[e].first >= 3) {
          if (v2 != NO_ID) {
            error("extruded edge (n_i = 2 around vertex) but multiple interior edges ?");
            for (id ee: edges) {
              DBG("--", ee, h2q.edgeParent[ee], edgeVal[ee], H.edgeToFaces[ee].size());
            }
            DBG("-----");
            for (id ee: H.vertToEdges[v]) {
              DBG("--", ee, h2q.edgeParent[ee], edgeVal[ee], H.edgeToFaces[ee].size());
            }
            return false;
          }
          v2 = edge_opposite_vertex(H.edges[e].vertices,v);
        }
      }
      RFC(v2 == NO_ID, "extruded edge (n_i = 2) but no interior edge ?");

      /* Compute quad normal */
      vec3 n = {0.,0.,0.};
      F(i,faces.size()) {
        vec3 qn = HfaceNormal[faces[i]];
        if (length2(qn) > 0) normalize(qn);
        n = n + qn;
      }
      // double avgLen = 0.;
      // F(i,edges.size()) avgLen += edge_length(H, edges[i]);
      // avgLen /= double(edges.size());
      // avgLen = std::min(avgLen, uniformExtrusionLength);
      // double ulen = opt.extrusion_factor * avgLen;

      double ulen = opt.extrusion_factor * averageBoundaryEdgeLengthAround(H, h2q, v, true);

      // Msg::Warning("FOR FIGURE, UNIFORM EDGE LENGTH");
      // ulen = uniformExtrusionLength;

      if (length(n) < EPS0) { /* cannot do a meaning full extrusion */
        bdrVertexDone[v] = false;
        continue;
      }
      normalize(n);

      /* Compute extruded position */
      vec3 pos = H.vertices[v].pt + ulen * n;

      new_pos[v2] = new_pos[v2] + pos;
      new_pos_sum[v2] += 1.;
      bdrVertexDone[v] = true;
    }

    /* Update position, average if required */
    id nb_set = 0;
    FC(v,H.vertices.size(),new_pos_sum[v] > 0.) {
      if (new_pos_sum[v] == 1.) {
        H.vertices[v].pt = new_pos[v];
      } else { /* average ... */
        H.vertices[v].pt = 1. / new_pos_sum[v] * new_pos[v];
      }
      nb_set += 1;
    }

    info("set position for {} extruded vertices", nb_set);

    return true;
  }

  inline vec3 vertex_normal(id v, 
      const HexToBoundaryMeshMatching& h2q, 
      const BrepMesh& Q,
      const std::vector<vec3>& vNormals) {
    if (h2q.vertexParent[v].first == 0) {
      id qv = h2q.vertexParent[v].second;
      return vNormals[qv];
    } else if (h2q.vertexParent[v].first == 1) {
      id qe = h2q.vertexParent[v].second;
      id qv1 = Q.edges[qe].vertices[0];
      id qv2 = Q.edges[qe].vertices[1];
      vec3 ref = 0.5*(vNormals[qv1] + vNormals[qv2]);
      if (Q.edgeToFaces[qe].size() == 2) { /* edge midpoint, check adjacent faces */
        vec3 nf1 = face_normal(Q, Q.edgeToFaces[qe][0]);
        if (dot(ref,nf1) < 0.) nf1 = -1. * nf1;
        vec3 nf2 = face_normal(Q, Q.edgeToFaces[qe][1]);
        if (dot(ref,nf2) < 0.) nf2 = -1. * nf2;
        return 0.5 * (nf1 + nf2);
      }
      return ref;
    } else if (h2q.vertexParent[v].first == 2) {
      id qf = h2q.vertexParent[v].second;
      vector<id> vs = face_vertices(Q,qf);
      vec3 avg = 0.25*(vNormals[vs[0]] + vNormals[vs[1]] + vNormals[vs[2]] + vNormals[vs[3]]);
      vec3 n = face_normal(Q, qf);
      if (dot(avg,n) > 0.) {
        return n;
      } else {
        return -1. * n;
      }
    }
    return {0.,0.,0.};
  }

  bool set_position_extruded_vertices(
      const HblOptions& opt, BrepMesh& H, 
      const vector<int>& edgeVal, /* edge hex-valence */
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      const std::vector<vec3>& qvNormals, /* in initial quad mesh */
      const std::vector<double>& vExtrusionLength, /* absolute extrusion length at vertex in H */
      vector<bool>& bdrVertexDone,
      double uniformExtrusionLength = DBL_MAX,  /* only used if != DBL_MAX */
      double extrusion_factor = 1.) {
    debug("set_position_extruded_vertices ...");

    vector<vec3> new_pos(H.vertices.size(),{0.,0.,0.});
    vector<double> new_pos_sum(H.vertices.size(),0.);
    vector<id> faces;
    vector<id> edges;
    FC(v,H.vertices.size(),h2q.vertexParent[v].first <= 2) {
      brep_boundary_fan_around_vertex(H, Q, h2q, v, faces, edges);
      RFC(edges.size() < 3 || edges.size() != faces.size(), "wrong quad mesh at v={}, faces={}, edges={}", v, faces, edges);
      vector<id> bdrVal(edges.size(),0);
      F(i,edges.size()) {
        id e = edges[i];
        if (h2q.edgeParent[e].first == 1) {
          bdrVal[i] = edgeVal[h2q.edgeParent[e].second];
        } else {
          bdrVal[i] = 2;
        }
      }
      vector<id> nb_each(1000);
      for (id val: bdrVal) nb_each[val] += 1;
      /* Check if extrusion */
      if (nb_each[2] != bdrVal.size()) continue; /* not extrusion */

      /* Interior extruded vertex */
      id v2 = NO_ID;
      F(le,H.vertToEdges[v].size()) {
        id e = H.vertToEdges[v][le];
        if (h2q.edgeParent[e].first >= 3) {
          if (v2 != NO_ID) {
            error("extruded edge (n_i = 2 around vertex) but multiple interior edges ?");
            for (id ee: edges) {
              DBG("--", ee, h2q.edgeParent[ee], edgeVal[ee], H.edgeToFaces[ee].size());
            }
            DBG("-----");
            for (id ee: H.vertToEdges[v]) {
              DBG("--", ee, h2q.edgeParent[ee], edgeVal[ee], H.edgeToFaces[ee].size());
            }
            return false;
          }
          v2 = edge_opposite_vertex(H.edges[e].vertices,v);
        }
      }
      RFC(v2 == NO_ID, "extruded edge (n_i = 2) but no interior edge ?");

      double ulen = uniformExtrusionLength;
      if (ulen == DBL_MAX) {
        if (v < vExtrusionLength.size()) {
          ulen = vExtrusionLength[v];
        } else {
          ulen = extrusion_factor * averageBoundaryEdgeLengthAround(H, h2q, v, true);
        }
      }

      vec3 n = vertex_normal(v, h2q, Q, qvNormals);
      if (length(n) < EPS0) { /* cannot do a meaning full extrusion */
        bdrVertexDone[v] = false;
        continue;
      }
      normalize(n);
      // GeoLog::add(H.vertices[v].pt,n,"normalsExtrusion");

      /* Compute extruded position */
      vec3 pos = H.vertices[v].pt + ulen * n;

      new_pos[v2] = new_pos[v2] + pos;
      new_pos_sum[v2] += 1.;
      bdrVertexDone[v] = true;
    }

    /* Update position, average if required */
    id nb_set = 0;
    FC(v,H.vertices.size(),new_pos_sum[v] > 0.) {
      if (new_pos_sum[v] == 1.) {
        H.vertices[v].pt = new_pos[v];
      } else { /* average ... */
        H.vertices[v].pt = 1. / new_pos_sum[v] * new_pos[v];
      }
      bdrVertexDone[v] = true;
      // GeoLog::add(H.vertices[v].pt,new_pos_sum[v],"regular_extruded");
      nb_set += 1;
    }

    info("set position for {} extruded vertices", nb_set);

    return true;
  }

  inline double angle_oriented(vec3 u, vec3 v, vec3 n) {
    const double dp = dot(u,v);
    const double tp = dot(n,cross(u,v));
    double angle = atan2(tp,dp);
    if (angle < 0) angle += 2.*M_PI;
    return angle;
  }

  bool set_position_regular_fans(const HblOptions& opt, BrepMesh& H, 
      const vector<int>& edgeVal, /* edge hex-valence */
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      const std::vector<vec3>& HfaceNormal,
      vector<bool>& bdrVertexDone) {
    debug("set_position_regular_fans ...");
    warn("OBSOLETE ? ...");

    vector<id> bdrQuadVal(H.vertices.size(),0);
    vector<id> vert;
    FC(f,H.faces.size(),h2q.faceParent[f].first <= 2) {
      face_vertices(H, f, vert);
      for (id v: vert) bdrQuadVal[v] += 1;
    }

    vector<vec3> new_pos(H.vertices.size(),{0.,0.,0.});
    vector<double> new_pos_sum(H.vertices.size(),0.);
    vector<vector<id3>> right_angle_corners(H.vertices.size());

    FC(v,H.vertices.size(), bdrQuadVal[v] == 4  /* Regular quad vertex */
        && h2q.vertexParent[v].first <= 2) { /* Loop on bdr vertices */
      vector<id> faces;
      vector<id> edges;
      bool okf = brep_boundary_fan_around_vertex(H, Q, h2q, v, faces, edges);
      RFC(!okf, "failed to get boundary fan around v = {}", v);
      RFC(edges.size() != 4 || faces.size() != 4, "wrong fan, edges = {}, faces = {}", edges, faces);
      if (edges.size() != 4) continue;

      vector<id> bdrVal(edges.size(),0);
      F(i,edges.size()) {
        id e = edges[i];
        if (h2q.edgeParent[e].first == 1) {
          bdrVal[i] = edgeVal[h2q.edgeParent[e].second];
        } else {
          bdrVal[i] = 2;
        }
      }

      /* Boundary fan */
      bool regular_fan = false;
      id4 fanEdges;
      id4 fanEdgeVal;
      F(k,2) {
        if (   bdrVal[k] != 2 
            && bdrVal[k] == bdrVal[k+2]
            && bdrVal[k+1] == 2
            && bdrVal[(k+3)%4] == 2) {
          fanEdges = {edges[k], edges[k+1], edges[k+2], edges[(k+3)%4] };
          fanEdgeVal = {bdrVal[k], bdrVal[k+1], bdrVal[k+2], bdrVal[(k+3)%4]};
          regular_fan = true;
          break;
        }
      }
      if (!regular_fan) continue;

      /* Interior fan (in the volume) */
      bool valid_interior_fan = true;
      vector<id> iFanEdges;
      vector<id> iFanFaces;
      {
        id eStart = fanEdges[1];
        id fStart = NO_ID;
        bool oks = true;
        for (id f: H.edgeToFaces[eStart]) if (h2q.faceParent[f].first >= 3) {
          if (fStart == NO_ID) {
            fStart = f;
          } else {
            warn("regular_fan | f = {} for fStart but already fStart = {}", f, fStart);
            valid_interior_fan = false;
            oks = false;
          }
        }
        RFC(!oks, "regular_fan | failed to find edge/face start");
        id e = eStart;
        id f = fStart;
        id iter = 0;
        while(e != fanEdges[3]) {
          iter += 1;
          if(iter > 1000) {
            warn("regular_fan | v = {}, eStart = {}, fStart = {}, infinite loop ? iter = {}", v, eStart, fStart, iter);
            valid_interior_fan = false;
            break;
          }
          iFanEdges.push_back(e);
          iFanFaces.push_back(f);
          id e_next = NO_ID;
          for (id ec: H.faces[f].edges) if (ec != e && (H.edges[ec].vertices[0] == v || H.edges[ec].vertices[1] == v)) {
            e_next = ec;
          }
          RFC(e_next == NO_ID, "e = {}, e_next = {}", e, e_next);
          if (e_next == fanEdges[3]) {
            iFanEdges.push_back(e_next);
            break;
          }
          id f_next = NO_ID;
          for (id fc: H.edgeToFaces[e_next]) if (fc != f && h2q.faceParent[fc].first >= 3) {
            bool perp = false;
            for (id fc_e: H.faces[fc].edges) if (fc_e == fanEdges[0] || fc_e == fanEdges[2]) {
              perp = true; break;
            }
            if (perp) continue;
            f_next = fc;
          }
          if (f_next == NO_ID) {
            warn("interior fan, failed to get f_next, e = {}, e_next = {}, f = {}, f_next = {}", e, e_next, f, f_next);
            valid_interior_fan = false;
            break;
          }

          e = e_next;
          f = f_next;
        }
      }
      if (!valid_interior_fan) {
        warn("set_position_regular_fans | invalid interior fan at v={}, ignore it", v);
        continue;
      }
      RFC(iFanEdges.size() != iFanFaces.size() + 1, "weird: iFanEdges = {}, iFanFaces = {}", 
          iFanEdges, iFanFaces);

      vector<id> iFanVertex(iFanEdges.size()+iFanFaces.size()); /* including opposite quad vertex via diagonal */
      F(i,iFanEdges.size()) iFanVertex[2*i] = edge_opposite_vertex(H.edges[iFanEdges[i]].vertices,v);
      F(i,iFanFaces.size()) iFanVertex[2*i+1] = quad_opposite_vertex(H,iFanFaces[i],v);

      /* Local frame */
      double avgLen = 0.25 * (edge_length(H,fanEdges[0]) + edge_length(H,fanEdges[1])
          + edge_length(H,fanEdges[2]) + edge_length(H,fanEdges[3]));
      vec3 e_x = H.vertices[iFanVertex[0]].pt - H.vertices[v].pt;
      vec3 e_f = H.vertices[iFanVertex.back()].pt - H.vertices[v].pt;
      /* TODO: to get something symmetric:
       *         e_x = 0.5 * (e_x - proj(e_f, plane e_x with normal two quads adj. to e_x)) */
      // e_x = 0.5 * (e_x - e_f); /* to get something symmetric -> does not work */
      double len_x = length(e_x);
      double len_f = length(e_f);
      if (len_x < EPS0 || len_f < EPS0) {
        warn("set_position_regular_fans | small lengths at v={}, len_x or len_f, ignore it", v);
        continue;
      }
      e_x = 1./len_x * e_x;
      e_f = 1./len_f * e_f;
      vec3 n = {0.,0.,0.};
      F(i,faces.size()) {
        n = n + HfaceNormal[faces[i]];
      }
      if (length(n) < EPS0) {
        warn("set_position_regular_fans | small lengths at v={}, n, ignore it", v);
        continue;
      }
      normalize(n);
      vec3 e_y = n - dot(n,e_x) * e_x;
      if (length(e_y) < EPS0) {
        warn("set_position_regular_fans | small lengths at v={}, e_y, ignore it", v);
        continue;
      }
      normalize(e_y);
      vec3 e_z = cross(e_x,e_y);
      if (length(e_z) < EPS0) {
        warn("set_position_regular_fans | small lengths at v={}, e_z, ignore it", v);
        continue;
      }

      double agl_total = angle_oriented(e_x,e_f,e_z);


      /* Set the edge opposite vertex positions (interior edges) */
      F(i,iFanEdges.size()) {
        if (i == 0 || i == iFanEdges.size()-1) continue;
        double agl = double(i)  / double(iFanEdges.size()-1.) * agl_total;
        vec3 pos = H.vertices[v].pt;
        pos = pos + opt.extrusion_factor * avgLen * (cos(agl) * e_x + sin(agl) * e_y);
        new_pos[iFanVertex[2*i]] = new_pos[iFanVertex[2*i]] + pos;
        new_pos_sum[iFanVertex[2*i]] += 1.;
      }

      /* Set the quad opposite vertex positions (interior quads) */
      vec3 pCorner = H.vertices[v].pt;
      F(i,iFanFaces.size()) {
        id vPrev = iFanVertex[2*i];
        id vCorner = v;
        id vNext = iFanVertex[2*(i+1)];
        id target = iFanVertex[2*i+1];
        right_angle_corners[target].push_back({vPrev,vCorner,vNext});
      }

      bdrVertexDone[v] = true;
    }

    id nb_set = 0;
    /*  Average the position on edges */
    FC(v,H.vertices.size(),new_pos_sum[v] > 0.) {
      if (new_pos_sum[v] == 1.) {
        H.vertices[v].pt = new_pos[v];
      } else {
        H.vertices[v].pt = 1./new_pos_sum[v] * new_pos[v];
      }
      GeoLog::add(H.vertices[v].pt,3+new_pos_sum[v],"regular_fan");
      nb_set += 1;
    }

    /*  Average the position on quad diagonals */
    FC(v,H.vertices.size(),right_angle_corners[v].size() > 0) {
      vec3 avg = {0.,0.,0.};
      F(j,right_angle_corners[v].size()) {
        vec3 prev = H.vertices[right_angle_corners[v][j][0]].pt;
        vec3 cur = H.vertices[right_angle_corners[v][j][1]].pt;
        vec3 next = H.vertices[right_angle_corners[v][j][2]].pt;
        avg = avg + opposite_right_angled_corner(prev, cur, next);
      }
      avg = 1./double(right_angle_corners[v].size()) * avg;
      H.vertices[v].pt = avg;
      bdrVertexDone[v] = true;
      nb_set += 1;
      GeoLog::add(H.vertices[v].pt,3+new_pos_sum[v],"regular_fan_diag");
    }

    info("set position for {} vertices on regular curve configs", nb_set);

    return true;
  }
  
  bool set_position_regular_fan_vertices(const HblOptions& opt, BrepMesh& H, 
      const vector<int>& edgeVal, /* edge hex-valence */
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      const std::vector<vec3>& vNormals, /* in initial quad mesh */
      vector<bool>& bdrVertexDone,
      double extrusion_factor) {
    debug("set_position_regular_fan_vertices ...");

    vector<id> bdrQuadVal(H.vertices.size(),0);
    vector<id> vert;
    FC(f,H.faces.size(),h2q.faceParent[f].first <= 2) {
      face_vertices(H, f, vert);
      for (id v: vert) bdrQuadVal[v] += 1;
    }

    vector<vec3> new_pos(H.vertices.size(),{0.,0.,0.});
    vector<double> new_pos_sum(H.vertices.size(),0.);
    vector<vector<id3>> right_angle_corners(H.vertices.size());

    FC(v,H.vertices.size(), bdrQuadVal[v] == 4  /* Regular quad vertex */
        && h2q.vertexParent[v].first <= 2) { /* Loop on bdr vertices */
      vector<id> faces;
      vector<id> edges;
      bool okf = brep_boundary_fan_around_vertex(H, Q, h2q, v, faces, edges);
      RFC(!okf, "failed to get boundary fan around v = {}", v);
      RFC(edges.size() != 4 || faces.size() != 4, "wrong fan, edges = {}, faces = {}", edges, faces);
      if (edges.size() != 4) continue;

      vector<id> bdrVal(edges.size(),0);
      F(i,edges.size()) {
        id e = edges[i];
        if (h2q.edgeParent[e].first == 1) {
          bdrVal[i] = edgeVal[h2q.edgeParent[e].second];
        } else {
          bdrVal[i] = 2;
        }
      }

      /* Boundary fan */
      bool regular_fan = false;
      id4 fanEdges;
      id4 fanEdgeVal;
      F(k,2) {
        if (   bdrVal[k] != 2 
            && bdrVal[k] == bdrVal[k+2]
            && bdrVal[k+1] == 2
            && bdrVal[(k+3)%4] == 2) {
          fanEdges = {edges[k], edges[k+1], edges[k+2], edges[(k+3)%4] };
          fanEdgeVal = {bdrVal[k], bdrVal[k+1], bdrVal[k+2], bdrVal[(k+3)%4]};
          regular_fan = true;
          break;
        }
      }
      if (!regular_fan) continue;

      /* Interior fan (in the volume) */
      bool valid_interior_fan = true;
      vector<id> iFanEdges;
      vector<id> iFanFaces;
      {
        id eStart = fanEdges[1];
        id fStart = NO_ID;
        bool oks = true;
        for (id f: H.edgeToFaces[eStart]) if (h2q.faceParent[f].first >= 3) {
          if (fStart == NO_ID) {
            fStart = f;
          } else {
            warn("regular_fan | f = {} for fStart but already fStart = {}", f, fStart);
            valid_interior_fan = false;
            oks = false;
          }
        }
        RFC(!oks, "regular_fan | failed to find edge/face start");
        id e = eStart;
        id f = fStart;
        id iter = 0;
        while(e != fanEdges[3]) {
          iter += 1;
          if(iter > 1000) {
            warn("regular_fan | v = {}, eStart = {}, fStart = {}, infinite loop ? iter = {}", v, eStart, fStart, iter);
            valid_interior_fan = false;
            break;
          }
          iFanEdges.push_back(e);
          iFanFaces.push_back(f);
          id e_next = NO_ID;
          for (id ec: H.faces[f].edges) if (ec != e && (H.edges[ec].vertices[0] == v || H.edges[ec].vertices[1] == v)) {
            e_next = ec;
          }
          RFC(e_next == NO_ID, "e = {}, e_next = {}", e, e_next);
          if (e_next == fanEdges[3]) {
            iFanEdges.push_back(e_next);
            break;
          }
          id f_next = NO_ID;
          for (id fc: H.edgeToFaces[e_next]) if (fc != f && h2q.faceParent[fc].first >= 3) {
            bool perp = false;
            for (id fc_e: H.faces[fc].edges) if (fc_e == fanEdges[0] || fc_e == fanEdges[2]) {
              perp = true; break;
            }
            if (perp) continue;
            f_next = fc;
          }
          if (f_next == NO_ID) {
            warn("interior fan, failed to get f_next, e = {}, e_next = {}, f = {}, f_next = {}", e, e_next, f, f_next);
            valid_interior_fan = false;
            break;
          }

          e = e_next;
          f = f_next;
        }
      }
      if (!valid_interior_fan) {
        warn("set position regular fan vertices | invalid interior fan at v={}, ignore it", v);
        continue;
      }
      RFC(iFanEdges.size() != iFanFaces.size() + 1, "weird: iFanEdges = {}, iFanFaces = {}", 
          iFanEdges, iFanFaces);

      vector<id> iFanVertex(iFanEdges.size()+iFanFaces.size()); /* including opposite quad vertex via diagonal */
      F(i,iFanEdges.size()) iFanVertex[2*i] = edge_opposite_vertex(H.edges[iFanEdges[i]].vertices,v);
      F(i,iFanFaces.size()) iFanVertex[2*i+1] = quad_opposite_vertex(H,iFanFaces[i],v);

      /* Local frame */
      double avgLen = 0.5 * (edge_length(H,fanEdges[1]) + edge_length(H,fanEdges[3]));
      vec3 e_x = H.vertices[iFanVertex[0]].pt - H.vertices[v].pt;
      vec3 e_f = H.vertices[iFanVertex.back()].pt - H.vertices[v].pt;
      /* TODO: to get something symmetric:
       *         e_x = 0.5 * (e_x - proj(e_f, plane e_x with normal two quads adj. to e_x)) */
      // e_x = 0.5 * (e_x - e_f); /* to get something symmetric -> does not work */
      double len_x = length(e_x);
      double len_f = length(e_f);
      if (len_x < EPS0 || len_f < EPS0) {
        warn("set_position_regular_fan vertices | small lengths at v={}, len_x or len_f, ignore it", v);
        continue;
      }
      e_x = 1./len_x * e_x;
      e_f = 1./len_f * e_f;

      vec3 n = vertex_normal(v, h2q, Q, vNormals);

      if (length(n) < EPS0) {
        warn("set position regular fan vertices | small lengths at v={}, n={}, ignore it", v, n);
        continue;
      }
      normalize(n);
      vec3 e_y = n - dot(n,e_x) * e_x;
      if (length(e_y) < EPS0) {
        warn("set_position_regular_fan vertices | small lengths at v={}, e_y, ignore it", v);
        continue;
      }
      normalize(e_y);
      vec3 e_z = cross(e_x,e_y);
      if (length(e_z) < EPS0) {
        warn("set_position_regular_fan vertices | small lengths at v={}, e_z, ignore it", v);
        continue;
      }

      double agl_total = angle_oriented(e_x,e_f,e_z);


      /* Set the edge opposite vertex positions (interior edges) */
      F(i,iFanEdges.size()) {
        if (i == 0 || i == iFanEdges.size()-1) continue;
        double agl = double(i)  / double(iFanEdges.size()-1.) * agl_total;
        vec3 pos = H.vertices[v].pt;
        pos = pos + avgLen * (cos(agl) * e_x + sin(agl) * e_y);
        new_pos[iFanVertex[2*i]] = new_pos[iFanVertex[2*i]] + pos;
        new_pos_sum[iFanVertex[2*i]] += 1.;
      }

      /* Set the quad opposite vertex positions (interior quads) */
      vec3 pCorner = H.vertices[v].pt;
      F(i,iFanFaces.size()) {
        id vPrev = iFanVertex[2*i];
        id vCorner = v;
        id vNext = iFanVertex[2*(i+1)];
        id target = iFanVertex[2*i+1];
        right_angle_corners[target].push_back({vPrev,vCorner,vNext});
      }

      bdrVertexDone[v] = true;
    }

    id nb_set = 0;
    /*  Average the position on edges */
    FC(v,H.vertices.size(),new_pos_sum[v] > 0.) {
      if (new_pos_sum[v] == 1.) {
        H.vertices[v].pt = new_pos[v];
      } else {
        H.vertices[v].pt = 1./new_pos_sum[v] * new_pos[v];
      }
      bdrVertexDone[v] = true;
      nb_set += 1;
    }

    /*  Average the position on quad diagonals */
    FC(v,H.vertices.size(),right_angle_corners[v].size() > 0) {
      vec3 avg = {0.,0.,0.};
      F(j,right_angle_corners[v].size()) {
        vec3 prev = H.vertices[right_angle_corners[v][j][0]].pt;
        vec3 cur = H.vertices[right_angle_corners[v][j][1]].pt;
        vec3 next = H.vertices[right_angle_corners[v][j][2]].pt;
        avg = avg + opposite_right_angled_corner(prev, cur, next);
      }
      avg = 1./double(right_angle_corners[v].size()) * avg;
      H.vertices[v].pt = avg;
      bdrVertexDone[v] = true;
      nb_set += 1;
    }

    info("set position for {} vertices on regular curve configs", nb_set);

    return true;
  }

  bool set_boundary_quad_mesh_anisotropic(
      const HblOptions& opt, BrepMesh& H, 
      const BrepMesh& Q,
      const vector<int>& edgeVal, /* edge hex-valence in Q */
      const vector<double>& edgeDihedralAngle, /* edge dihedral angle in Q */
      const HexToBoundaryMeshMatching& h2q,
      double extrusion_factor) {

    /* Reset midpoint positions
     * (necessary if function called multiple times)*/
    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first == 0) {
        H.vertices[v].pt = Q.vertices[h2q.vertexParent[v].second].pt;
      } else if (h2q.vertexParent[v].first == 1) {
        H.vertices[v].pt = edge_center(Q, h2q.vertexParent[v].second);
      } else if (h2q.vertexParent[v].first == 2) {
        H.vertices[v].pt = face_center(Q, h2q.vertexParent[v].second);
      }
    }

    /* Flag vertices of H that will attract adjacent
     * vertices on the surfaces */
    vector<int> attractor(H.vertices.size(),0);
    {
      vector<int> qv_attractor(Q.vertices.size(),0);
      vector<bool> qe_attractor(Q.edges.size(),false);
      FC(e,Q.edges.size(),edgeVal[e] != 2) {

        if (!opt.discreteModel) { // Ignore attractors outside CAD curves
          if (Q.edges[e].entity != nullptr && Q.edges[e].entity->dim() > 1) continue;
        } else { // Use dihedral angle on discrete model
          double agl = edgeDihedralAngle[e] * 180. / M_PI;
          if (90 + 45 < agl && agl < 180 + 45) continue;
        }

        qe_attractor[e] = true;
        qv_attractor[Q.edges[e].vertices[0]] += 1;
        qv_attractor[Q.edges[e].vertices[1]] += 1;
      }
      F(v,H.vertices.size()) {
        if (h2q.vertexParent[v].first == 0) {
          if (qv_attractor[h2q.vertexParent[v].second] > 2) { /* corner */
            attractor[v] = 2;
          } else if (qv_attractor[h2q.vertexParent[v].second] > 0) {
            attractor[v] = 1;
          }
        } else if (h2q.vertexParent[v].first == 1 && qe_attractor[h2q.vertexParent[v].second]) {
          attractor[v] = 1;
        }
      }
    }

    vector<vec3> new_pos(H.vertices.size(),{0.,0.,0.});
    vector<double> new_pos_sum(H.vertices.size(),0.);
    FC(e,H.edges.size(),h2q.edgeParent[e].first <= 2) {
      id v1 = H.edges[e].vertices[0];
      id v2 = H.edges[e].vertices[1];
      if (attractor[v1] > attractor[v2]) {
        vec3 p1 = H.vertices[v1].pt;
        vec3 p2 = H.vertices[v2].pt;
        new_pos[v2] = new_pos[v2] + (1-extrusion_factor) * p1 + extrusion_factor * p2;
        new_pos_sum[v2] += 1.;
      } else if (attractor[v1] < attractor[v2]) {
        vec3 p1 = H.vertices[v1].pt;
        vec3 p2 = H.vertices[v2].pt;
        new_pos[v1] = new_pos[v1] + (1-extrusion_factor) * p2 + extrusion_factor * p1;
        new_pos_sum[v1] += 1.;
      }
    }

    size_t n = 0;
    FC(v,H.vertices.size(),new_pos_sum[v] > 0.) {
      if (new_pos_sum[v] == 1.) {
        H.vertices[v].pt = new_pos[v];
      } else {
        H.vertices[v].pt = 1./new_pos_sum[v] * new_pos[v];
      }
      n += 1;
    }

    /* Corners */
    vector<id> aquads;
    vector<id> fvert;
    FC(v,H.vertices.size(),attractor[v] >= 2) {
      /* Adjacent bdr quads */
      vertex_adjacent_faces(H, v, aquads);
      FC(lq,aquads.size(),h2q.faceParent[aquads[lq]].first <= 2) {
        face_vertices(H,aquads[lq],fvert);
        FC(lv,fvert.size(),fvert[lv] == v) {
          id vp = fvert[(lv + fvert.size() - 1) % fvert.size()];
          id vn = fvert[(lv + 1) % fvert.size()];
          id vo = fvert[(lv + 2) % fvert.size()];
          if (new_pos_sum[vp] > 0. && new_pos_sum[vn] > 0.) {
            vec3 newPosOp = opposite_right_angled_corner(H.vertices[vp].pt,H.vertices[v].pt,H.vertices[vn].pt);
            H.vertices[vo].pt = newPosOp;
          }
          break;
        }
      }
    }

    return true;
  }


  bool laplacian_smoothing(
      BrepMesh& H, 
      const vector<bool>& locked,
      const vector<vector<id> >& v2v,
      size_t nIter = 10,
      double lambda = 0.05) {

    F(iter,nIter) {
      FC(v,v2v.size(),!locked[v] && v2v[v].size() > 0)  {
        vec3 avg = {0.,0.,0.};
        for (id v2: v2v[v]) {
          avg = avg + H.vertices[v2].pt;
        }
        avg = avg * double(1./v2v[v].size());
        H.vertices[v].pt = (1.-lambda) * H.vertices[v].pt + lambda * avg;
      }
    }

    return true;
  }

  std::array<double,3> computeMinAvgMaxSurfaceEdgeLength(
      BrepMesh& H, 
      const HexToBoundaryMeshMatching& h2q) {
    double avg = 0.;
    double sum = 0.;
    double vmin = DBL_MAX;
    double vmax = -DBL_MAX;
    FC(f,H.faces.size(),H.faceToCells[f].size() == 1
        && h2q.faceParent[f].first <= 2) {
      double flen = face_average_edge_length(H, f);
      vmin = std::min(vmin,flen);
      vmax = std::max(vmax,flen);
      avg += flen;
      sum += 1.;
    }
    if (sum != 0.) avg = avg/sum;
    return {vmin,avg,vmax};
  }

  bool computeLocalExtrusionLength(BrepMesh& H, 
      const HexToBoundaryMeshMatching& h2q,
      double extrusion_factor,
      std::vector<double> vExtrusionLength /* absolute extrusion length at vertex in H */
      ) {
    debug("compute local extrusion length ...");
    vExtrusionLength.clear();

    /* Initialize */
    vector<vector<id> > v2v(H.vertices.size());
    vExtrusionLength.resize(H.vertices.size(),0.);
    vector<bool> locked(H.vertices.size(),false);
    /* - compute length at feature edges (hex-val != 2) */
    FC(e,H.edges.size(),h2q.edgeParent[e].first <= 2) {
      id v1 = H.edges[e].vertices[0];
      id v2 = H.edges[e].vertices[1];
      v2v[v1].push_back(v2);
      v2v[v2].push_back(v1);
      if (H.edgeToFaces[e].size() != 3) { /* hex-valence != 2 -> feature */
        F(lv,2) {
          id v = H.edges[e].vertices[lv];
          if (!locked[v]) {
            locked[v] = true;

            double avgElen = 0.;
            double s = 0.;
            for (id e2: H.vertToEdges[v]) {
              if (h2q.edgeParent[e2].first <= 2 && H.edgeToFaces[e2].size() == 3) {
                avgElen += edge_length(H, e2);
                s += 1.;
              }
            }
            if (s == 0.) continue;
            avgElen /= s;
            vExtrusionLength[v] = avgElen;
          }
        }
      }
    }
    /* - initialize length on rest of surface with extrusion_factor */
    FC(v,H.vertices.size(),!locked[v] && h2q.vertexParent[v].first <= 2) {
      double avgElen = 0.;
      double s = 0.;
      for (id e2: H.vertToEdges[v]) if (h2q.edgeParent[e2].first <= 2) {
        avgElen += edge_length(H, e2);
        s += 1.;
      }
      if (s == 0.) continue;
      avgElen /= s;
      vExtrusionLength[v] = extrusion_factor * avgElen;
    }


    /* Propagate with laplacian smoothing */
    // TODO fixme: check local convergence delta
    size_t nIter = 200;
    F(iter,nIter) {
      FC(v,v2v.size(),!locked[v] && v2v[v].size() > 0)  {
        double avg = 0.;
        for (id v2: v2v[v]) {
          avg = avg + vExtrusionLength[v2];
        }
        avg *= double(1./v2v[v].size());
        vExtrusionLength[v] = avg;
      }
    }

    // FC(v,v2v.size(), v2v[v].size() > 0) {
    //   GeoLog::add(H.vertices[v].pt,vExtrusionLength[v],"vExtrusionLength");
    // }
    // GeoLog::flush();

    return true;
  }

  bool initial_extruded_geometry(
      const HblOptions& opt, 
      BrepMesh& H, 
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      const std::vector<vec3>& HfaceNormal,
      double factor, /* factor on face_average_edge_length */
      double uniformExtrusionLength,
      vector<bool>& extruded,
      size_t niterSmoothing = 10
      ) {

    vector<vec3> newPos(H.vertices.size(),{0.,0.,0.});
    vector<double> newPosSum(H.vertices.size(),0.);

    /* Loop on hex faces on model boundary */
    vector<id> _fvert(4);
    vector<id> _fvert_op(4);
    FC(f,H.faces.size(),H.faceToCells[f].size() == 1
        && h2q.faceParent[f].first <= 2) {
      face_vertices(H, f, _fvert);
      id c = H.faceToCells[f][0];
      hex_opposite_face_vertices(H, c, _fvert, _fvert_op);
      vec3 n = HfaceNormal[f];
      RFC(n == NO_VEC3, "normal not defined, should not happen");
      vec3 center = face_center(H, f);
      double flen = face_average_edge_length(H, f);
      F(lv,4) {
        id v = _fvert[lv];
        double ulen = std::min(factor * flen,uniformExtrusionLength);
        vec3 pos_op = 0.5 * (H.vertices[v].pt + center) + ulen * n;
        newPos[_fvert_op[lv]] = newPos[_fvert_op[lv]] + pos_op;
        newPosSum[_fvert_op[lv]] += 1.;
        GeoLog::add({H.vertices[v].pt,pos_op},vector<double>{0.,1.},"push");
      }
    }

    extruded.clear();
    extruded.resize(H.vertices.size(),false);
    vector<bool> locked(H.vertices.size(),false);
    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first <= 2) {
        extruded[v] = true;
        locked[v] = true;
      } else {
        if (newPosSum[v] > 0.) {
          H.vertices[v].pt = newPos[v] * (1./newPosSum[v]);
          extruded[v] = true;
          size_t nob = 0;
          for (id e: H.vertToEdges[v]) {
            id v2 = edge_opposite_vertex(H.edges[e].vertices,v);
            if (h2q.vertexParent[v2].first <= 2) nob += 1;
          }
          if (nob == 1) {
            locked[v] = true;
          }
        }
      }
    }

    if (niterSmoothing > 0) {
      vector<vector<id> > v2v(H.vertices.size());
      FC(e,H.edges.size(),h2q.edgeParent[e].first >= 3) {
        id v1 = H.edges[e].vertices[0];
        id v2 = H.edges[e].vertices[1];
        if (h2q.vertexParent[v1].first <= 2) continue;
        if (h2q.vertexParent[v2].first <= 2) continue;
        v2v[v1].push_back(v2);
        v2v[v2].push_back(v1);
      }
      laplacian_smoothing(H, locked, v2v, niterSmoothing, 0.1);
    }

    return true;
  }

  bool build_hexahedral_cavity(
      const BrepMesh& H,
      const vector<double>& quality,
      id cStart, /* Initial hex */
      double qualityThreshold,
      id dist_threshold, /* Number of layer of hexes around under threshold hexes */
      vector<id>& cavity) {

    /* Init */
    id dist_max = std::numeric_limits<id>::max();
    unordered_map<id,id> dist;
    std::priority_queue<std::pair<id,id>,  std::vector<std::pair<id,id> >,  std::greater<std::pair<id,id> > > Q; 
    dist[cStart] = 0;
    Q.push({0,cStart});

    /* Dijkstra growth */
    while (Q.size() > 0) {
      id c = Q.top().second;
      Q.pop();
      for (id f: H.cells[c].faces) {
        for (id c2: H.faceToCells[f]) {
          if (c2 == c) continue;
          auto it = dist.find(c2);
          if (it == dist.end() && quality[c2] <= qualityThreshold) {
            dist[c2] = 0;
            Q.push({0,c2});
          } else {
            id dist1 = dist[c];
            id dist2 = (it != dist.end()) ? dist[c2] : dist_max;
            if (dist1 + 1 < dist2) {
              dist2 = dist1 + 1;
              dist[c2] = dist2;
              if (dist2 <= dist_threshold) {
                Q.push({dist2,c2});
              }
            }
          }
        }
      }
    }

    cavity.clear();
    cavity.push_back(cStart);
    for (const auto& kv : dist) {
      id c = kv.first;
      id d = kv.second;
      if (c != cStart && d <= dist_threshold) {
        cavity.push_back(c);
      }
    }
    sort_unique(cavity);

    return true;
  }

  /* Cavity in generic polyhedral mesh */
  bool build_cavity(
      const vector<vector<id> >& eltVertices,
      const vector<vector<id> >& v2c,
      const vector<double>& qualities,
      id cStart, /* Initial hex */
      double qualityThreshold,
      id dist_threshold, /* Number of layer of hexes around under threshold hexes */
      vector<id>& cavity) {

    /* Init */
    id dist_max = std::numeric_limits<id>::max();
    unordered_map<id,id> dist;
    std::priority_queue<std::pair<id,id>,  std::vector<std::pair<id,id> >,  std::greater<std::pair<id,id> > > Q; 
    dist[cStart] = 0;
    Q.push({0,cStart});

    vector<id> _adjCells;

    /* Dijkstra growth */
    while (Q.size() > 0) {
      id c = Q.top().second;
      Q.pop();

      _adjCells.clear();
      const vector<id>& _cvert = eltVertices[c];
      F(lv,_cvert.size()) {
        id v = _cvert[lv];
        F(lc,v2c[v].size()) {
          _adjCells.push_back(v2c[v][lc]);
        }
      }
      sort_unique(_adjCells);

      for (id c2: _adjCells) if (c2 != c) {
        auto it = dist.find(c2);
        if (it == dist.end() && qualities[c2] <= qualityThreshold) {
          dist[c2] = 0;
          Q.push({0,c2});
        } else {
          id dist1 = dist[c];
          id dist2 = (it != dist.end()) ? dist[c2] : dist_max;
          if (dist1 + 1 < dist2) {
            dist2 = dist1 + 1;
            dist[c2] = dist2;
            if (dist2 <= dist_threshold) {
              Q.push({dist2,c2});
            }
          }
        }
      }
    }

    cavity.clear();
    cavity.push_back(cStart);
    for (const auto& kv : dist) {
      id c = kv.first;
      id d = kv.second;
      if (c != cStart && d <= dist_threshold) {
        cavity.push_back(c);
      }
    }
    sort_unique(cavity);

    return true;
  }

  bool extract_cavity_problem(
      const vector<id>& cavity,
      const vector<vec3>& points,
      const std::vector<bool>& locked,
      const vector<vector<id> >& elts,
      vector<id>& old2new,
      vector<vector<id> >& r_elts,
      vector<vec3>& r_points,
      vector<bool>& r_locked,
      vector<id>& r_new2old,
      vector<id>& r_new2old_cell
      ) {
    r_points.clear();
    r_locked.clear();
    r_new2old.clear();
    r_locked.reserve(cavity.size()*8);
    r_points.reserve(cavity.size()*8);
    r_new2old.reserve(cavity.size()*8);

    r_elts.resize(cavity.size());
    r_new2old_cell.resize(cavity.size());
    old2new.clear();
    old2new.resize(points.size(),NO_ID);
    id count = 0;
    F(lc,cavity.size()) {
      id c = cavity[lc];
      r_new2old_cell[lc] = c;
      r_elts[lc].resize(elts[c].size());
      F(lv,elts[c].size()) {
        id v = elts[c][lv];
        if (old2new[v] == NO_ID) {
          old2new[v] = count;
          count += 1;
          r_new2old.push_back(v);
          r_locked.push_back(locked[v]);
          r_points.push_back(points[v]);
        }
        r_elts[lc][lv] = old2new[v];
      }
    }

    /* Lock vertices on cavity boundary by 
     * iterating on elts outside cavity and locking
     * their vertices */
    vector<bool> eltInCavity(elts.size(),false);
    for (id c: cavity) eltInCavity[c] = true;
    FC(c,elts.size(),!eltInCavity[c]) {
      F(lv,elts[c].size()) {
        id v = elts[c][lv];
        if (old2new[v] != NO_ID) {
          r_locked[old2new[v]] = true;
        }
      }
    }

    return true;
  }

  bool build_interface_tets_to_avoid_multiple_covering(
      const HblInput& input,
      HblOutput& output,
      const vector<id>& cavity,
      const vector<vec3>& points,
      const vector<bool>& locked,
      vector<id4>& tets
      ) {
    BrepMesh& H = output.H;

    vector<id> _fvert(4);
    vector<id> _fvert_ord(4);
    vector<id> _fvert_opc1(4);
    vector<id> _fvert_opc2(4);
    F(lc,cavity.size()) {
      id c = cavity[lc];
      /* Look for an interior face between two hexes,
       * connected to the boundary by a boundary edge */
      for (id f: H.cells[c].faces) if (H.faceToCells[f].size() == 2) {

        /* Check the interface is inside the cavity */
        id c1 = H.faceToCells[f][0];
        id c2 = H.faceToCells[f][1];
        if (c1 != c && !inVector(c1,cavity)) continue;
        if (c2 != c && !inVector(c2,cavity)) continue;

        /* Check the face is adjacent to a convex initial edge of the boundary mesh,
         * with more than two tets assigned */
        bool keep = false;
        id2 edge_vert = {NO_ID,NO_ID};
        for (id e: H.faces[f].edges) {
          if (output.h2q.edgeParent[e].first == 1) {
            id old_e = output.h2q.edgeParent[e].second;
            if (output.hexValence[old_e] > 2 && input.edgeDihedralAngle[old_e] < M_PI) {
              edge_vert = H.edges[e].vertices;
              keep = true;
            }
          }
        }
        if (!keep) continue;

        face_vertices(H, f, _fvert);
        RFC(_fvert.size() != 4, "face should be a quad !");
        bool ok = false;
        F(lv,4) {
          if (_fvert[lv] == edge_vert[0] && _fvert[(lv+1)%4] == edge_vert[1]) {
            ok = true;
            _fvert_ord[0] = _fvert[lv];
            _fvert_ord[1] = _fvert[(lv+1)%4];
            _fvert_ord[2] = _fvert[(lv+2)%4];
            _fvert_ord[3] = _fvert[(lv+3)%4];
          } else if (_fvert[lv] == edge_vert[1] && _fvert[(lv+1)%4] == edge_vert[0]) {
            ok = true;
            _fvert_ord[0] = _fvert[lv];
            _fvert_ord[1] = _fvert[(lv+1)%4];
            _fvert_ord[2] = _fvert[(lv+2)%4];
            _fvert_ord[3] = _fvert[(lv+3)%4];
          }
        }
        if (!ok) continue;

        /* Get the vertices on the parallel faces */
        bool ok1 = hex_opposite_face_vertices(H, c1, _fvert_ord, _fvert_opc1);
        if (!ok1) continue;
        bool ok2 = hex_opposite_face_vertices(H, c2, _fvert_ord, _fvert_opc2);
        if (!ok1) continue;
        
        /* Add the tangling-protection tets */
        id4 tet1 = {_fvert_opc1[0],_fvert_ord[0],_fvert_opc2[0],_fvert_ord[1]};
        id4 tet2 = {_fvert_opc2[1],_fvert_ord[1],_fvert_opc1[1],_fvert_ord[0]};
        double vol1 = basicOrient3d(
            H.vertices[tet1[0]].pt, 
            H.vertices[tet1[1]].pt, 
            H.vertices[tet1[2]].pt, 
            H.vertices[tet1[3]].pt);
        double vol2 = basicOrient3d(
            H.vertices[tet2[0]].pt, 
            H.vertices[tet2[1]].pt, 
            H.vertices[tet2[2]].pt, 
            H.vertices[tet2[3]].pt);
        double vol1inv = basicOrient3d(
            H.vertices[tet1[0]].pt, 
            H.vertices[tet1[1]].pt, 
            H.vertices[tet1[3]].pt, 
            H.vertices[tet1[2]].pt);
        double vol2inv = basicOrient3d(
            H.vertices[tet2[0]].pt, 
            H.vertices[tet2[1]].pt, 
            H.vertices[tet2[3]].pt, 
            H.vertices[tet2[2]].pt);
        if (vol1inv + vol2inv > vol1 + vol2) {
          tet1 = invert(tet1);
          tet2 = invert(tet2);
        }

        std::vector<vec3> pts1 = {
          H.vertices[tet1[0]].pt,
          H.vertices[tet1[1]].pt,
          H.vertices[tet1[2]].pt,
          H.vertices[tet1[3]].pt
        };
        std::vector<vec3> pts2 = {
          H.vertices[tet2[0]].pt,
          H.vertices[tet2[1]].pt,
          H.vertices[tet2[2]].pt,
          H.vertices[tet2[3]].pt
        };
        GeoLog::add(pts1,0.,"tet1", true);
        GeoLog::add(pts2,0.,"tet2", true);
        tets.push_back(tet1);
        tets.push_back(tet2);
      }
    }
    return true;
  }

  struct SmoothingProblem {
    vector<vec3> points;
    vector<bool> locked;
    vector<vector<uint32_t> > eltVertices; /* assume orientation is ok */
    vector<vector<vec3> > elementTargetShapes;
    int iterMaxOuter = 50;
    int iterMaxInner = 300;
    int nFailMax = 10;
    double timeMax = 30;
    double lambda = 0.;
    int verbosity = 0;
  };

  bool solveSmoothingProblem(SmoothingProblem& pb) {
    vector<std::array<uint32_t,4> > tets;
    std::vector<std::array<std::array<double,3>,4> > tetIdealShapes;

    // TODO FIXME use 32 !
    const int dcpHex = 32; // each hex becomes 32 sub-tets
    bool okb = buildTetrahedraFromElements(pb.eltVertices, pb.elementTargetShapes, tets, tetIdealShapes, dcpHex);
    if (!okb) {
      Msg::Error("Failed to build tets from elements");
      return false;
    }

    F(i,tetIdealShapes.size()) {
      double q = qcomp.minQualityTet({
          tetIdealShapes[i][0],
          tetIdealShapes[i][1],
          tetIdealShapes[i][2],
          tetIdealShapes[i][3]},QualityMetric::SICN);
      double q2 = qcomp.minQualityTet({
          tetIdealShapes[i][0],
          tetIdealShapes[i][1],
          tetIdealShapes[i][3],
          tetIdealShapes[i][2]},QualityMetric::SICN);
      if (q2 < 0.) {
        Msg::Warning("solveSmoothingProblem: ideal tet %li quality: %f", i, q2);
      }
    }

    Msg::Debug("- Untangle/Smooth hex-tet mesh (%li elements -> %li optim tets, %li vertices) ...", 
        pb.eltVertices.size(), tets.size(), pb.points.size());

    pb.lambda = 0.;

    bool oku = untangle_tetrahedra(pb.points, pb.locked, tets, tetIdealShapes,
        pb.lambda, pb.iterMaxInner, pb.iterMaxOuter, pb.nFailMax, pb.timeMax);
    if (!oku) {
      Msg::Debug("---- failed to untangle");
    }
    return true;
  }

  struct id2Hash {
    size_t operator()(const id2 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };

  struct id4Hash {
    size_t operator()(const id4 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[2]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[3]), sizeof(id)));
      return seed;
    }
  };

  bool setTargetShapeForAnisotropicBoundaryHexahedra(
      SmoothingProblem& pb) {
    if (pb.eltVertices.size() == 0) return false;

    constexpr int hex_facet_vertex[6][4] = {
      {0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3}, 
      {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
    constexpr int hex_edges[12][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2},
                                 {1, 5}, {2, 3}, {2, 6}, {3, 7},
                                 {4, 5}, {4, 7}, {5, 6}, {6, 7}};
    constexpr int face_to_axis[6] = {2,1,0,0,1,2};
    constexpr int axis_to_faces[3][2] = {{2,3},{1,4},{0,5}};
    constexpr int axis_to_edges[3][4] = {{0,5,11,8},{1,3,10,9},{2,4,6,7}};

    std::vector<vec3> equi = {
      vec3{.5, 0, -1. / (2. * std::sqrt(2.))},
      vec3{-.5, 0, -1. / (2. * std::sqrt(2.))},
      vec3{0, -.5, 1. / (2. * std::sqrt(2.))},
      vec3{0, .5, 1. / (2. * std::sqrt(2.))},
    };
    double reg_vol = qcomp.volume({equi[0],equi[1],equi[2],equi[3]});
    if (reg_vol < 0.) { Msg::Error("inverted ref tet"); abort(); }
    for(size_t lv = 0; lv < 4; ++lv) {
      equi[lv] = equi[lv] * (1. / std::pow(reg_vol, 1. / 3.));
    }


    double avgVol = 0.;
    pb.elementTargetShapes.clear();
    size_t nTetSetToReg = 0;
    F(i,pb.eltVertices.size()) {
      if (pb.eltVertices[i].size() == 4) {
        // Using current shape for tetra
        array<id,4> tVert = {
          pb.eltVertices[i][0], pb.eltVertices[i][1],
          pb.eltVertices[i][2], pb.eltVertices[i][3]};
        std::vector<std::array<double, 3> > target = {
          pb.points[tVert[0]],
          pb.points[tVert[1]],
          pb.points[tVert[2]],
          pb.points[tVert[3]]};
        /* regularize volume */
        double vol = qcomp.volume(target);
        if (std::isnan(vol) || vol <= 0) {
          target = equi;
          nTetSetToReg += 1;
          vol = qcomp.volume(target);
          // Msg::Warning("setTargetShapeForAnisotropicBoundaryHexahedra: tet %li ideal vol: %f", i, vol);
        }
        F(lv,target.size()) {
          target[lv] = (1./std::pow(vol,1./3.))*target[lv];
        }
        pb.elementTargetShapes.push_back(target);
        avgVol += vol;
      } else if (pb.eltVertices[i].size() == 8) {
        // Check if shape should be anisotropic, and in how many directions
        array<id,8> hVert = {
          pb.eltVertices[i][0], pb.eltVertices[i][1],
          pb.eltVertices[i][2], pb.eltVertices[i][3],
          pb.eltVertices[i][4], pb.eltVertices[i][5],
          pb.eltVertices[i][6], pb.eltVertices[i][7]
        };

        vec3 deltaAvg = {0.,0.,0.};
        vec3 deltamax = {0.,0.,0.};
        F(a,3) {
          F(le,4) {
            id v1 = hVert[hex_edges[axis_to_edges[a][le]][0]];
            id v2 = hVert[hex_edges[axis_to_edges[a][le]][1]];
            double len = length(pb.points[v1]-pb.points[v2]);
            deltaAvg[a] += 0.25 * len;
            deltamax[a] = std::max(deltamax[a], len);
          }
        }

        // TODO INFO:
        // for the moment, not using anisotropic directions, just
        // using existing ratio of dx, dy, dz
        vec3 w = {1.,1.,1.};
        double lmax = max_value(deltamax[0],deltamax[1],deltamax[2]);
        w = {deltamax[0]/lmax,deltamax[1]/lmax,deltamax[2]/lmax};

        std::vector<std::array<double, 3> > target = {
          {0., 0., 0.}, {w[0], 0., 0.}, {w[0], w[1], 0.}, {0., w[1], 0.},
          {0., 0., w[2]}, {w[0], 0., w[2]}, {w[0], w[1], w[2]}, {0., w[1], w[2]}};

        /* regularize volume */
        double vol = qcomp.volume(target);
        F(lv,target.size()) {
          target[lv] = (1./std::pow(vol,1./3.))*target[lv];
        }

        pb.elementTargetShapes.push_back(target);

        avgVol += vol;
      } else {
        Msg::Error("set target shape: element type not supported");
        return false;
      }
    }
    avgVol /= double(pb.elementTargetShapes.size());
    if (nTetSetToReg > 0) {
      Msg::Debug("set target shape: %li initial tets had negative volume, set to regular tet", nTetSetToReg);
    }

    // Scale the target shapes
    F(i,pb.elementTargetShapes.size()) {
      F(lv,pb.elementTargetShapes[i].size()) {
        pb.elementTargetShapes[i][lv] = (1./std::pow(avgVol,1./3.))*pb.elementTargetShapes[i][lv];
      }
    }

    return true;
  }

  bool smoothSmallCavity(
      vector<vec3>& points, /* all mesh points */
      const std::vector<bool>& locked,
      const vector<vector<id> >& elts,
      const vector<id>& cavity, /* cavity to smooth */
      const BrepMesh& H,/* useful for faceToCells info */
      bool anisoHexTargetShapes) 
  {

    SmoothingProblem pb;

    /* Build sub problem */
    vector<id> r_new2old;
    vector<id> r_new2old_cell;
    vector<id> old2new;
    bool okr = extract_cavity_problem(cavity, points, locked, elts, old2new, pb.eltVertices,
        pb.points, pb.locked, r_new2old, r_new2old_cell);
    RFC(!okr,"failed to extract cavity problem, cavity = {}",cavity);
    id nbf = 0;
    FC(i,pb.locked.size(),!pb.locked[i]) nbf += 1;
    if (nbf == 0) return true;

    /* Problem options */
    pb.verbosity = 0;
    if (Msg::GetVerbosity() >= 99) {
      pb.verbosity = 3;
    }
    pb.iterMaxInner = 1000;
    pb.iterMaxOuter = 100;
    pb.lambda = 0.;
    pb.nFailMax = 5;
    if (nbf < 5) {
      pb.timeMax = 1;
    } else {
      pb.timeMax = 0.3*nbf;
    }

    if (anisoHexTargetShapes) {
      setTargetShapeForAnisotropicBoundaryHexahedra(pb);
    }

    std::string text;
    if (Msg::GetVerbosity() >= 99) {
      info("----");
      text = "smoothing (";
      text += std::to_string(nbf) + "/" + std::to_string(pb.points.size()) + " free, ";
      text += "w/ WinslowUntangler";
      text += "), SICN <stage>:";
      print_quality_stats(ReplaceSubString("<stage>","before",text), pb.points, pb.eltVertices, QualityMetric::SICN);
    }

    /* Call untangler */
    solveSmoothingProblem(pb);

    if (Msg::GetVerbosity() >= 99) {
      print_quality_stats(ReplaceSubString("<stage>","after",text), pb.points, pb.eltVertices, QualityMetric::SICN);
    }

    /* Update global positions */
    FC(i,pb.points.size(),!pb.locked[i]) {
      points[r_new2old[i]] = pb.points[i];
    }

    return true;
  }

  // bool untangle_and_smooth_hexahedral_cavity(
  //     const HblOptions& opt,
  //     vector<vec3>& points, /* all mesh points */
  //     const std::vector<bool>& locked,
  //     const vector<id8>& hexes, /* all mesh hexes */
  //     const vector<id>& cavity, /* hexes of the cavity to smooth */
  //     const BrepMesh& H, /* useful for faceToCells info */
  //     const vector<id4>& additional_tets, /* local tets to avoid tangling */
  //     vector<double>& quality)
  // {
  //   /* Build sub problem */
  //   vector<id> r_cavity;
  //   vector<id8> r_hexes;
  //   vector<bool> r_locked;
  //   vector<vec3> r_points;
  //   vector<id> r_new2old;
  //   vector<id> r_new2old_cell;
  //   vector<id> old2new;
  //   bool okr = extract_cavity_problem(H, cavity, points, locked, hexes, old2new, r_cavity, r_hexes,
  //       r_points, r_locked, r_new2old, r_new2old_cell);
  //   RFC(!okr,"failed to extract cavity problem, cavity = {}",cavity);
  //   id nbf = 0;
  //   FC(i,r_points.size(),!r_locked[i]) nbf += 1;
  //   if (nbf == 0) {
  //     if (opt.debug) debug("-- smoothing cavity with {} hexes and {}/{} free vertices, ignore it",
  //         r_hexes.size(), nbf, r_points.size());
  //     return true;
  //   }

  //   /* Check cavity quality */
  //   quality.resize(cavity.size(),0.);
  //   hexQualities(r_points, r_hexes, quality, HexDcp::TO_24TETS);
  //   double vMin, vMax, vAvg;
  //   vector_statistics(quality, vMin, vMax, vAvg);

  //   if (opt.debug) {
  //     info("-- smoothing cavity with {} hexes and {}/{} free vertices ...", r_hexes.size(), nbf, r_points.size());
  //     print_stats("---- sub-tet quality initial ", quality);
  //   }

  //   /* Call the Winslow untangler/smoother */
  //   HexDcp dcp = HexDcp::TO_32TETS;
  //   bool version24tets = true;
  //   vector<array<uint32_t,4> > tets;
  //   tets.reserve(r_hexes.size()*8);
  //   vector<double> tetWeights;
  //   tetWeights.reserve(r_hexes.size()*8);
  //   size_t nfree = 0;
  //   for (size_t v = 0; v < r_points.size(); ++v) if (!r_locked[v]) {
  //     nfree += 1;
  //   }
  //   for (size_t c = 0; c < r_hexes.size(); ++c) {
  //     vector<array<uint32_t,4> > htets = tetsFromHex(r_hexes[c],dcp);
  //     for (size_t j = 0; j < htets.size(); ++j) {
  //       /* In Geogram convention, tets have the opposite ordering */
  //       tets.push_back(invert(htets[j]));
  //       tetWeights.push_back(1.);
  //     }
  //   }
  //   debug("---- call untangler ({} vertices, {} free, {} tets from {} hexes, {} anti multiple-covering tets) ...",
  //       r_points.size(), nfree, tets.size(), r_hexes.size(), additional_tets.size());

  //   /* Tets to avoid tangling via multiple covering */
  //   F(lt,additional_tets.size()) {
  //     id4 tet = {
  //       old2new[additional_tets[lt][0]],
  //       old2new[additional_tets[lt][1]],
  //       old2new[additional_tets[lt][2]],
  //       old2new[additional_tets[lt][3]]};
  //     if (tet[0] == NO_ID || tet[1] == NO_ID || tet[2] == NO_ID || tet[3] == NO_ID) {
  //       Msg::Error("anti-tangling tet not in cavity ?! should not happen");
  //       return false;
  //     }
  //     tets.push_back(tet);
  //   }

  //   Msg::Error("disabled");
  //   // int verbosity = 3;
  //   // std::string pp = "Debug   : ---- ";
  //   // int iterMaxOuter = 100;
  //   // int iterMaxInner = 300;
  //   // int nFailMax = 6;
  //   // bool oku = UNT::untangle(r_points, r_locked, tets, tetWeights, iterMaxInner, iterMaxOuter, nFailMax, verbosity, pp);
  //   // if (!oku) {
  //   //   Msg::Warning("---- failed to untangle");
  //   // }

  //   // /* Recompute quality */
  //   // hexQualities(r_points, r_hexes, quality, true);
  //   // vector_statistics(quality, vMin, vMax, vAvg);
  //   // if (opt.debug) {
  //   //   print_stats("---- sub-tet quality final   ", quality);
  //   // }
  //   // if (vMin < 0. && opt.debug) {
  //   //   warn("cavity still tangled, min sub-tet quality = {}", vMin);
  //   // }

  //   // /* Update global positions */
  //   // FC(j,r_points.size(),!r_locked[j]) {
  //   //   points[r_new2old[j]] = r_points[j];
  //   // }


  //   return true;
  // }


  bool untangleAndSmoothHexTetMesh(
      HblOutput& output,
      const HblOptions& opt,
      std::vector<bool>& locked, /* bool on H vertices */
      int iterMaxOuter = 50,
      int nFailMax = 10
      ) {

    BrepMesh& H = output.H;
    HexToBoundaryMeshMatching& h2q = output.h2q;

    SmoothingProblem pb; /* contains all info for smoothing */
    pb.locked = locked;

    size_t nFree = 0;
    pb.points.resize(H.vertices.size());
    F(v,pb.points.size()) {
      pb.points[v] = H.vertices[v].pt;
      if (!pb.locked[v]) nFree += 1;
    }

    if (pb.locked.size() == 0) {
      pb.locked.resize(H.vertices.size(),false);
    }
    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first >= 0 && h2q.vertexParent[v].first <= 2) {
        pb.locked[v] = true;
      }
    }

    /* Oriented coherent hexahedra */
    debug("- compute oriented elements");
    vector<int> ballId; /* if multiple disconnected components */
    bool oko = compute_oriented_elements(H, pb.eltVertices, ballId);
    RFC(!oko, "failed to compute oriented elements");


    bool oki = invert_elements_if_required(pb.points, pb.eltVertices, ballId);
    RFC(!oki, "failed to invert elements (as required)");


    /* Problem options */
      pb.verbosity = 0;
    if (Msg::GetVerbosity() >= 99) {
      pb.verbosity = 3;
    }
    pb.iterMaxInner = 300;
    pb.lambda = 0.01;

    /* Call untangler */
    solveSmoothingProblem(pb);

    /* Update global positions */
    FC(i,pb.points.size(),!pb.locked[i]) {
      H.vertices[i].pt = pb.points[i];
    }

    /* Export hexes */
    vector<id8> hexes;
    hexes.reserve(pb.eltVertices.size()/32);
    F(i,pb.eltVertices.size()) if (pb.eltVertices[i].size() == 8) {
      const id8 hex = {
        pb.eltVertices[i][0], pb.eltVertices[i][1], pb.eltVertices[i][2], pb.eltVertices[i][3],
        pb.eltVertices[i][4], pb.eltVertices[i][5], pb.eltVertices[i][6], pb.eltVertices[i][7] };
      hexes.push_back(hex);
    }
    output.hexahedra = hexes;

    vector<double> qualities;
    computeHexQualities(pb.points, hexes, qualities, QualityMetric::SIGE);
    print_stats("- SIGE quality stats",qualities);

    return true;
  }

  // bool untangleAndSmoothHexahedralConfigurations(
  //     HblOutput& output,
  //     const HblOptions& opt,
  //     int iterMaxOuter = 50,
  //     int nFailMax = 10
  //     ) {

  //   QualityMetric m = QualityMetric::SIGE;

  //   BrepMesh& H = output.H;
  //   HexToBoundaryMeshMatching& h2q = output.h2q;

  //   /* Points to optimize */
  //   vector<vec3> points;
  //   points.resize(H.vertices.size());
  //   F(v,points.size()) {
  //     points[v] = H.vertices[v].pt;
  //   }

  //   /* Oriented coherent elements */
  //   vector<vector<id> > eltVertices(H.cells.size());
  //   debug("- compute oriented elements");
  //   vector<int> ballId; /* if multiple disconnected components */
  //   bool oko = compute_oriented_elements(H, eltVertices, ballId);
  //   RFC(!oko, "failed to compute oriented elements");

  //   bool oki = invert_elements_if_required(points, eltVertices, ballId);
  //   RFC(!oki, "failed to invert elements (as required)");

  //   /* Element quality, scaled jacobien of tets or sub-tets */
  //   vector<double> qualities(eltVertices.size(),-1.);
  //   for (size_t i = 0; i < eltVertices.size(); ++i) {
  //     qualities[i] = cellQuality(points, eltVertices[i], m);
  //   }
  //   double qMin, qMax, qAvg;
  //   vector_statistics(qualities, qMin, qMax, qAvg);

  //   /* Vertex to cells */
  //   vector<vector<id> > v2c(H.vertices.size());
  //   vector<id> _cvert(8);
  //   F(c,H.cells.size()) {
  //     cell_vertices(H,c,_cvert);
  //     F(lv,_cvert.size()) {
  //       v2c[_cvert[lv]].push_back(c);
  //     }
  //   }

  //   /* Base locks */
  //   vector<bool> locked(H.vertices.size(),false);
  //   FC(v,H.vertices.size(),h2q.vertexParent[v].first <= 2) {
  //     locked[v] = true;
  //   }

  //   /* Build one cavity for each boundary hexahedral configuration */
  //   FC(v,H.vertices.size(),h2q.vertexParent[v].first == 0) {
  //     vector<id> cavity = v2c[v];

  //     double qMin = DBL_MAX;
  //     for (id c: cavity) qMin = std::min(qMin,qualities[c]);
  //     if (qMin > 0.3) continue;

  //     /* In the small cavity extraction, vertices of quad faces 
  //      * adjacent to boundary are also locked */
  //     bool oks = smoothSmallCavity(points, locked, eltVertices, cavity, H, output.h2q);
  //     RFC(!oks, "failed to smooth cavity around v={}", v);
  //   }


  //   /* Update global positions */
  //   FC(i,points.size(),!locked[i]) {
  //     H.vertices[i].pt = points[i];
  //   }

  //   return true;
  // }

  bool untangleAndSmoothHexTetMeshWithLocalCavities(
      HblOutput& output,
      const HblOptions& opt,
      std::vector<bool>& locked, /* bool on H vertices */
      bool anisoHexTargetShapes = false,
      bool forceFullMesh = false,
      bool smoothLocalHexConfigs = false
      ) {

    QualityMetric m = QualityMetric::SIGE;

    BrepMesh& H = output.H;
    HexToBoundaryMeshMatching& h2q = output.h2q;


    /* Set the locked vertices on boundary mesh */
    if (locked.size() == 0) {
      locked.resize(H.vertices.size(),false);
    }
    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first >= 0 && h2q.vertexParent[v].first <= 2) {
        locked[v] = true;
      }
    }

    /* Points to optimize */
    vector<vec3> points;
    size_t nFree = 0;
    points.resize(H.vertices.size());
    F(v,points.size()) {
      points[v] = H.vertices[v].pt;
      if (!locked[v]) nFree += 1;
    }

    /* Retrieve oriented and coherent elements */
    vector<vector<id> > eltVertices;
    eltVertices.reserve(output.hexahedra.size()+output.tetrahedra.size());
    F(i,output.hexahedra.size()) {
      const id8& e = output.hexahedra[i];
      eltVertices.push_back({e[0],e[1],e[2],e[3],e[4],e[5],e[6],e[7]});
    }
    F(i,output.tetrahedra.size()) {
      const id4& e = output.tetrahedra[i];
      eltVertices.push_back({e[0],e[1],e[2],e[3]});
    }


    /* Element quality, SICN for hex and tet */
    vector<double> qualities(eltVertices.size(),-1.);
    for (size_t i = 0; i < eltVertices.size(); ++i) {
      qualities[i] = cellQuality(points, eltVertices[i], m);
    }
    double qMin, qMax, qAvg;
    vector_statistics(qualities, qMin, qMax, qAvg);

    vector<vector<id> > v2c(points.size());
    F(c,eltVertices.size()) F(lv,eltVertices[c].size()) {
      v2c[eltVertices[c][lv]].push_back(c);
    }

    /* Build the local cavities and smooth them */
    int DIST = 3; /* # buffer layers around hexahedra below threshold */

    const int PASS_NEGATIVE = 0;
    const int PASS_LOW = 1;
    vector<int> passes = {PASS_NEGATIVE,PASS_LOW};
    if (forceFullMesh || smoothLocalHexConfigs) passes.clear(); /* no local passes, see later */

    for (int pass: passes) {
      double threshold = 0.;
      if (pass == PASS_LOW) {
        vector_statistics(qualities, qMin, qMax, qAvg);
        threshold = 0.5 * (qMin + qAvg);
        DIST = 1;
      // } else if (pass == PASS_UNTANGLE_FREE) {
      //   DIST = 4;
      } else {
        DIST = 3;
      }

      vector<bool> done(eltVertices.size(),false);
      vector<id> cavity;
      info("- pass {}: untangling/smoothing of cavities where sub-tet quality < {} ...", pass, threshold);
      FC(seed,eltVertices.size(),!done[seed] && qualities[seed] <= threshold) {
        debug("-- untangling/smoothing with threshold = {}, seed = {}, quality = {}", threshold, seed, qualities[seed]);
        cavity.clear();
        double vMin, vMax, vAvg;

        bool okbc = build_cavity(eltVertices, v2c, qualities, seed, threshold, DIST, cavity);
        RFC(!okbc, "failed to build hex-tet cavity around seed = {}", seed);

        bool oks = smoothSmallCavity(points, locked, eltVertices, cavity, H,
             anisoHexTargetShapes);
        RFC(!oks, "failed to smooth cavity around seed={}", seed);

        /* Update global quality */
        F(lc,cavity.size()) {
          id c = cavity[lc];
          qualities[c] = cellQuality(points, eltVertices[c], m);
        }

        /* Mark hexes as done (even if it failed) */
        F(lc,cavity.size()) done[cavity[lc]] = true; 
      }
    }

    if (smoothLocalHexConfigs) {
      info("- smoothing local hex configurations");
      /* Base locks */
      vector<bool> locked(H.vertices.size(),false);
      FC(v,H.vertices.size(),h2q.vertexParent[v].first <= 2) {
        locked[v] = true;
      }

      /* Build one cavity for each boundary hexahedral configuration */
      FC(v,H.vertices.size(),h2q.vertexParent[v].first == 0) {
        vector<id> cavity = v2c[v];

        double qMin = DBL_MAX;
        for (id c: cavity) qMin = std::min(qMin,qualities[c]);
        if (qMin > 0.05) continue;

        /* In the small cavity extraction, vertices of quad faces 
         * adjacent to boundary are also locked */
        bool oks = smoothSmallCavity(points, locked, eltVertices, cavity, H);
        RFC(!oks, "failed to smooth cavity around v={}", v);
      }
    }

    if (forceFullMesh) {
      vector<id> cavity;
      info("- smoothing full mesh (forced), {} elements", H.cells.size());
      cavity.resize(H.cells.size(),false);
      F(k,H.cells.size()) cavity[k] = k;
      bool oks = smoothSmallCavity(points, locked, eltVertices, cavity, H, anisoHexTargetShapes);
      RFC(!oks, "failed to smooth full mesh");
    }


    /* Update global positions */
    FC(i,points.size(),!locked[i]) {
      H.vertices[i].pt = points[i];
    }

    m = QualityMetric::SICN;
    computeHexQualities(points, output.hexahedra, qualities, m);
    print_stats("- hex " + metricName(m) +" stats",qualities);
    m = QualityMetric::SIGE;
    computeHexQualities(points, output.hexahedra, qualities, m);
    print_stats("- hex " + metricName(m) +" stats",qualities);
    vector_statistics(qualities, qMin, qMax, qAvg);
    if (output.tetrahedra.size() > 0) {
      computeTetQualities(points, output.tetrahedra, qualities, QualityMetric::SICN);
      print_stats("- tet SICN stats",qualities);
      computeTetQualities(points, output.tetrahedra, qualities, QualityMetric::SIGE);
      print_stats("- tet SIGE stats",qualities);
    }

    if (qMin <= 0.) return false;

    return true;
  }

  bool simpleMeshFromBrepMeshElements(
      const BrepMesh& H,
      const vector<id>& faces,
      const vector<id>& cells,
      SimpleMesh& M) {
    M.points.clear();
    M.origin.clear();
    M.triangles.clear();
    M.tets.clear();
    M.hexahedra.clear();

    vector<id> old2new(H.vertices.size(),NO_ID);
    vector<id> fvert;
    vector<id> nvert;
    for (size_t i = 0; i < faces.size(); ++i) {
      face_vertices(H,faces[i],fvert);
      nvert.resize(fvert.size());
      for (size_t lv = 0; lv < fvert.size(); ++lv) {
        size_t v = fvert[lv];
        if (old2new[v] == NO_ID) {
          size_t nv = M.points.size();
          vec3 p = H.vertices[v].pt;
          M.points.push_back(p);
          M.origin.push_back(v);
          old2new[v] = nv;
          nvert[lv] = nv;
        } else {
          nvert[lv] = old2new[v];
        }
        if (fvert.size() == 3) {
          M.triangles.push_back({nvert[0],nvert[1],nvert[2]});
        } else if (fvert.size() == 4) {
          double diag1 = length(H.vertices[fvert[2]].pt - H.vertices[fvert[0]].pt);
          double diag2 = length(H.vertices[fvert[3]].pt - H.vertices[fvert[1]].pt);
          if (diag1 < diag2) {
            M.triangles.push_back({nvert[0],nvert[1],nvert[2]});
            M.triangles.push_back({nvert[0],nvert[2],nvert[3]});
          } else {
            M.triangles.push_back({nvert[0],nvert[1],nvert[3]});
            M.triangles.push_back({nvert[3],nvert[1],nvert[2]});
          }
        }
      }
    }

    return true;
  }

  bool localSurfaceMeshIsValid(const vector<vec3>& points, const BrepMesh& H, const vector<id>& faces,
      double quality_threshold)
  {
    bool valid = true;
    /* Check quality of elements */
    vector<id> fvert;
    for (id f: faces) if (H.faces[f].edges.size() == 4){
      face_vertices(H,f,fvert);
      const std::array<vec3,4> pts = {
        points[fvert[0]], points[fvert[1]],
        points[fvert[2]], points[fvert[3]] };
      double sige = qcomp.minQualityQuad(pts, QualityMetric::SIGE);
      if (sige < quality_threshold) {
        debug("-- invalid quad, SIGE = {} < threshold, cancel", sige);
        valid = false;
        break;
      }
    }

    /* Check self-intersections of the surface */
    if (valid) {
      /* Extract points and triangles */
      std::vector<vec3> spoints;
      std::vector<std::array<int32_t,3> > triangles;

      vector<int32_t> nvert;
      std::unordered_map<id,int32_t> old2new;
      for (id f: faces) if (H.faces[f].edges.size() == 4){
        face_vertices(H,f,fvert);
        nvert.resize(fvert.size());
        for (size_t lv = 0; lv < fvert.size(); ++lv) {
          id v = fvert[lv];
          auto it = old2new.find(v);
          if (it == old2new.end()) {
            int32_t nv = spoints.size();
            spoints.push_back(points[v]);
            old2new[v] = nv;
            nvert[lv] = nv;
          } else {
            nvert[lv] = it->second;
          }
        }
        double diag1 = length(spoints[nvert[2]] - spoints[nvert[0]]);
        double diag2 = length(spoints[nvert[3]] - spoints[nvert[1]]);
        if (diag1 < diag2) {
          triangles.push_back({nvert[0],nvert[1],nvert[2]});
          triangles.push_back({nvert[0],nvert[2],nvert[3]});
        } else {
          triangles.push_back({nvert[0],nvert[1],nvert[3]});
          triangles.push_back({nvert[3],nvert[1],nvert[2]});
        }
      }

      std::vector<id2> intersections;
      checkTriangleIntersections(spoints, triangles, intersections, true);
      if (intersections.size() > 0) {
        debug("-- self-intersections in the smooth quad patch, cancel");
        valid = false;
      }
    }
    return valid;
  }

  bool localSurfaceSmoothing(vector<vec3>& points, const BrepMesh& H, std::vector<id>& faces) {
    debug("- local surface smoothing ({} elements)...", faces.size());
    size_t iterMax = 100;

    /* Taubin coefficients */
    double lambda = 0.33;
    double mu = -0.34;

    /* Laplacian / Taubin smoothing */
    std::unordered_set<id> locked;
    std::unordered_map<id2,int,id2Hash> edgeValence;
    std::unordered_map<id,vector<id> > v2v;
    for (id f: faces) for (id e: H.faces[f].edges) {
      id v1 = H.edges[e].vertices[0];
      id v2 = H.edges[e].vertices[1];
      edgeValence[sorted(v1,v2)] += 1;
    }
    size_t nbdr = 0;
    for (auto& kv: edgeValence) if (kv.second == 1) {
      locked.insert(kv.first[0]);
      locked.insert(kv.first[1]);
      nbdr += 1;
    }
    if (nbdr == 0) {
      Msg::Warning("no cavity boundary edge");
    }
    for (auto& kv: edgeValence) if (kv.second == 2) {
      id v1 = kv.first[0];
      id v2 = kv.first[1];
      if (locked.find(v1) == locked.end()) v2v[v1].push_back(v2);
      if (locked.find(v2) == locked.end()) v2v[v2].push_back(v1);
    }

    /* Backup geometry */
    std::unordered_map<id,vec3> backup;
    for (auto& kv: v2v) if (kv.second.size() > 0) {
      backup[kv.first] = points[kv.first];
    }

    // TODO FIXME: fairing instead of laplacian smoothing ?

    /* Explicit Taubin smoothing loop */
    double dx0max = 0.;
    for (size_t iter = 0; iter < iterMax; ++iter) {
      // Laplacian smoothing step
      double dxmax = 0.;
      for (auto& kv: v2v) if (kv.second.size() > 0) {
        id v = kv.first;
        vec3 avg = {0.,0.,0.};
        for (id v2: kv.second) {
          avg = avg + points[v2];
        }
        avg = avg * (1./double(kv.second.size()));
        vec3 delta = avg - points[v];
        vec3 newPos = (iter % 2 == 0) ? points[v] + lambda * delta : points[v] + mu * delta;
        double dx = length(newPos - points[v]);
        if (dx > dxmax) dxmax = dx;
        points[v] = newPos;
      }
      // Msg::Debug("- smoothing: iter %i, dxmax = %.3e (dx0max = %.3e)", iter, dxmax, dx0max);

      if (iter == 0) {
        dx0max = dxmax;
      } else if (dxmax < 1.e-3 * dx0max) { // vertices no longer moving much, stop
        Msg::Debug("- smoothing: break at iter %i (vertices no longer moving much)", iter);
        break;
      }
    }

    /* Check quality self-intersections of the surface */
    double quality_threshold = 0.1;
    bool valid = localSurfaceMeshIsValid(points, H, faces, quality_threshold);

    /* Try iteratively to move points closer to initial position */
    if (valid) {
      const vector<double> lambdas = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.95};
      vector<vec3> points0 = points;
      vector<vec3> points2 = points;
      for (double lambda: lambdas) {
        for (auto& kv: v2v) if (kv.second.size() > 0) {
          id v = kv.first;
          points2[v] = (1.-lambda) * points0[v] + lambda * H.vertices[v].pt;
        }
        bool valid2 = localSurfaceMeshIsValid(points2, H, faces, quality_threshold);
        if (valid2) {
          points = points2;
        } else {
          break;
        }
      }
    }

    if (!valid) { /* restore geometry */
      for (auto& kv: backup) points[kv.first] = kv.second;
    }

    return valid;
  }

  bool untangleWithMovingBoundaries(
      HblOutput& output,
      const HblOptions& opt,
      std::vector<bool>& locked  /* bool on H vertices */
      ) {

    QualityMetric m = QualityMetric::SIGE;

    BrepMesh& H = output.H;
    HexToBoundaryMeshMatching& h2q = output.h2q;

    /* Set the locked vertices on boundary mesh */
    if (locked.size() == 0) {
      locked.resize(H.vertices.size(),false);
    }
    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first >= 0 && h2q.vertexParent[v].first <= 2) {
        locked[v] = true;
      }
    }

    /* Points to optimize */
    vector<vec3> points;
    size_t nFree = 0;
    points.resize(H.vertices.size());
    F(v,points.size()) {
      points[v] = H.vertices[v].pt;
      if (!locked[v]) nFree += 1;
    }

    /* Retrieve oriented and coherent elements */
    vector<vector<id> > eltVertices;
    eltVertices.reserve(output.hexahedra.size()+output.tetrahedra.size());
    F(i,output.hexahedra.size()) {
      const id8& e = output.hexahedra[i];
      eltVertices.push_back({e[0],e[1],e[2],e[3],e[4],e[5],e[6],e[7]});
    }
    F(i,output.tetrahedra.size()) {
      const id4& e = output.tetrahedra[i];
      eltVertices.push_back({e[0],e[1],e[2],e[3]});
    }


    /* Element quality, SICN for hex and tet */
    vector<double> qualities(eltVertices.size(),-1.);
    for (size_t i = 0; i < eltVertices.size(); ++i) {
      qualities[i] = cellQuality(points, eltVertices[i], m);
    }
    double qMin, qMax, qAvg;
    vector_statistics(qualities, qMin, qMax, qAvg);

    vector<vector<id> > v2c(H.vertices.size());
    vector<id> _cvert(8);
    F(c,H.cells.size()) {
      cell_vertices(H,c,_cvert);
      F(lv,_cvert.size()) {
        v2c[_cvert[lv]].push_back(c);
      }
    }

    vector<int> dists = {1,2,3,4,5,6,7,8,9,10};
    for (int dist: dists) {
      bool all_fixed = true;

      vector<bool> done(eltVertices.size(),false);
      vector<id> cavity;
      info("- untangling of cavities with tangled hexahedra by moving boundary vertices, dist = {} ...", dist);
      FC(seed,eltVertices.size(),!done[seed] && qualities[seed] <= 0 && eltVertices[seed].size() == 8) {
        debug("-- untangling/smoothing seed = {}, quality = {}", seed, qualities[seed]);
        cavity.clear();
        double vMin, vMax, vAvg;

        double threshold = 0.;
        bool okbc = build_cavity(eltVertices, v2c, qualities, seed, threshold, dist, cavity);
        RFC(!okbc, "failed to build hex-tet cavity around seed = {}", seed);

        // Extract cavity boundary which on model boundary
        vector<id> faces;
        for (id c: cavity) for (id f: H.cells[c].faces) if (h2q.faceParent[f].first <= 2) {
          faces.push_back(f);
        }
        // visualization_show_faces(H, faces, "bdr_d"+std::to_string(dist)+"_s"+std::to_string(seed));
        // GeoLog::flush();

        // Smooth the surface mesh and ensures that the
        // quads are valid and that there is no self-intersections
        bool fixed = localSurfaceSmoothing(points,H,faces);

        if (fixed) {
          debug("-- local surface smoothed successfully");
          // visualization_show_faces(H, faces, "bdr_d"+std::to_string(dist)+"_s"+std::to_string(seed) + "_FIX");
          // GeoLog::flush();

          // Vertices of edges of hex-valence 1 are unlocked because
          // else the hex would be forced to be flat on the smoothed surface
          vector<bool> locked2 = locked;
          for (id c: cavity) for (id f: H.cells[c].faces) if (h2q.faceParent[f].first <= 2) {
            for (id e: H.faces[f].edges) if (h2q.edgeParent[e].first == 1) {
              id qe = h2q.edgeParent[e].second;
              if (output.hexValence[qe] == 1) {
                locked2[H.edges[e].vertices[0]] = false;
                locked2[H.edges[e].vertices[1]] = false;
              }
            }
          }

          bool anisoHexTargetShapes = true;
          bool oks = smoothSmallCavity(points, locked2, eltVertices, cavity, H,
              anisoHexTargetShapes);
          RFC(!oks, "failed to smooth cavity around seed={}", seed);

          /* Update global quality */
          double localQmin = DBL_MAX;
          F(lc,cavity.size()) {
            id c = cavity[lc];
            qualities[c] = cellQuality(points, eltVertices[c], m);
            localQmin = std::min(localQmin,qualities[c]);
          }
          if (localQmin <= 0.) {
            all_fixed = false;
            debug("-- local surface smoothed but hexa still tangled");
          }
        } else {
          debug("-- local surface not fixed");
          all_fixed = false;
        }

        /* Mark hexes as done (even if it failed) */
        F(lc,cavity.size()) done[cavity[lc]] = true; 
      }
      if (all_fixed) break;
    }

    /* Update global positions (including moved points on boundary) */
    F(i,points.size()) {
      H.vertices[i].pt = points[i];
    }

    m = QualityMetric::SICN;
    computeHexQualities(points, output.hexahedra, qualities, m);
    print_stats("- hex " + metricName(m) +" stats",qualities);
    m = QualityMetric::SIGE;
    computeHexQualities(points, output.hexahedra, qualities, m);
    print_stats("- hex " + metricName(m) +" stats",qualities);
    vector_statistics(qualities, qMin, qMax, qAvg);
    if (qMin <= 0.) return false;

    return true;
  }


  bool createInteriorTetMesh(
      const HblOptions& opt, 
      BrepMesh& H, 
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q,
      const std::vector<vec3>& HfaceNormal) {

    // std::vector<vec3> posInit(H.vertices.size());
    // for (size_t v = 0; v < posInit.size(); ++v)
    //   posInit[v] = H.vertices[v].pt;

    // /* Prepate the boundary geometry for tet meshing
    //  * The goal is to avoid self intersections */
    // vector<bool> extruded;
    // double factor = 0.;
    // double uel = DBL_MAX;
    // size_t nSmooth = 100;
    // bool oki = initial_extruded_geometry(opt, H, Q, h2q, HfaceNormal, factor, uel, extruded, nSmooth);
    // RFC(!oki, "failed initial extruded geometry");


    std::vector<std::vector<id> > quadMeshFaces;
    bool okq = extract_interior_quad_meshes(H, h2q, quadMeshFaces);
    RFC(!okq, "failed to extract interior quad meshes");

    if (opt.viz && opt.debug) {
      for (size_t i = 0; i < quadMeshFaces.size(); ++i) {
        visualization_show_faces(H, quadMeshFaces[i], "_tet_bdr");
        GeoLog::flush();
      }
    }

    vector<id4> tets;
    bool ok = appendTetMeshBuiltFromQuadBoundary(H, quadMeshFaces);
    RFC(!ok, "failed to build interior tet mesh");

    // /* Restore initial positions before smoothing/untangling */
    // for (size_t v = 0; v < posInit.size(); ++v)
    //   H.vertices[v].pt = posInit[v];

    return true;
  }

  bool build_surface_cavity(
      const BrepMesh& M,
      id fStart, 
      const vector<bool>& isSeed,
      id dist_threshold, /* Number of layer of elements around seeds */
      vector<id>& cavity) {
    /* Init */
    id dist_max = std::numeric_limits<id>::max();
    unordered_map<id,id> dist;
    std::priority_queue<std::pair<id,id>,  std::vector<std::pair<id,id> >,  std::greater<std::pair<id,id> > > Q; 
    dist[fStart] = 0;
    Q.push({0,fStart});

    vector<id> _fvert;
    vector<id> _adjFaces;
    vector<id> _adjFacesL;

    /* Dijkstra growth */
    while (Q.size() > 0) {
      id f = Q.top().second;
      Q.pop();

      _adjFaces.clear();
      face_vertices(M, f, _fvert);
      F(lv,_fvert.size()) {
        id v = _fvert[lv];
        vertex_adjacent_faces(M,v,_adjFacesL);
        append(_adjFaces,_adjFacesL);
      }
      sort_unique(_adjFaces);

      for (id f2: _adjFaces) if (f2 != f) {
        auto it = dist.find(f2);
        if (it == dist.end() && isSeed[f2]) {
          dist[f2] = 0;
          Q.push({0,f2});
        } else {
          id dist1 = dist[f];
          id dist2 = (it != dist.end()) ? dist[f2] : dist_max;
          if (dist1 + 1 < dist2) {
            dist2 = dist1 + 1;
            dist[f2] = dist2;
            if (dist2 <= dist_threshold) {
              Q.push({dist2,f2});
            }
          }
        }
      }
    }

    cavity.clear();
    cavity.push_back(fStart);
    for (const auto& kv : dist) {
      id c = kv.first;
      id d = kv.second;
      if (c != fStart && d <= dist_threshold) {
        cavity.push_back(c);
      }
    }
    sort_unique(cavity);

    return true;
  }

  bool isConcaveCorner(
      const BrepMesh& M,
      const vector<bool>& faceInCavity,
      id v, id& fOut) {
    vector<id> adjFaces;
    vertex_adjacent_faces(M,v,adjFaces);
    size_t valOut = 0;
    for (id f: adjFaces) if (!faceInCavity[f]) {
      fOut = f;
      valOut += 1;
    }
    if (valOut == 1) return true;
    fOut = NO_ID;
    return false;
  }

  bool convexify_surface_cavity(
      const BrepMesh& M,
      vector<id>& cavity) {

    vector<bool> inCavity(M.faces.size(),false);
    for (id f: cavity) inCavity[f] = true;

    vector<id> fvert;
    bool running = true;
    while (running) {
      running = false;
      size_t nf = cavity.size();
      for (size_t i = 0; i < nf; ++i) {
        id f = cavity[i];
        face_vertices(M,f,fvert);
        for (id v: fvert) {
          id fOut = NO_ID;
          if (isConcaveCorner(M,inCavity,v,fOut) && fOut != NO_ID) {
            inCavity[fOut] = true;
            cavity.push_back(fOut);
            running = true;
            break;
          }
        }
      }
    }

    return true;
  }

  bool smoothGModelSurfaceMesh(const BrepMesh& Qin, const std::vector<id>& QvertTangled) {
    if (QvertTangled.size() == 0) {
      Msg::Error("smoothGModelSurfaceMesh: no seeds");
      return false;
    }
    BrepMesh Q = Qin;

    /* Initialize seed quads */
    vector<bool> seed(Q.faces.size(),false);
    {
      vector<bool> vTangled(Q.vertices.size(),false);
      for (id v: QvertTangled) vTangled[v] = true;

      vector<id> fvert;
      F(f,Q.faces.size()) {
        face_vertices(Q,f,fvert);
        for (id v: fvert) if (vTangled[v]) {
          seed[f] = true; break;
        }
      }
    }
    
    bool all_fixed = true;
    for (id dist = 1; dist < 6; ++dist) {
      vector<bool> done(Q.faces.size(),false);
      all_fixed = true;
      FC(f,Q.faces.size(),seed[f] && !done[f])  {
        vector<id> cavity;
        build_surface_cavity(Q, f, seed, dist, cavity);
        if (cavity.size() == 0) continue;
        convexify_surface_cavity(Q, cavity);

        vector<vec3> points(Q.vertices.size());
        F(v,Q.vertices.size()) points[v] = Q.vertices[v].pt;
        bool fixed = localSurfaceSmoothing(points, Q, cavity);
        if (fixed) {
          visualization_show_faces(Q, cavity, "scav_d"+std::to_string(dist)+"_s"+std::to_string(f));
          F(v,Q.vertices.size()) Q.vertices[v].pt = points[v];
          visualization_show_faces(Q, cavity, "scav_d"+std::to_string(dist)+"_s"+std::to_string(f) + "_FIX");
          for (id f: cavity) seed[f] = false;
        } else {
          all_fixed = false;
        }

        for (id f: cavity) done[f] = true;
      }

      if (all_fixed) break;
    }

    GeoLog::flush();

    if (all_fixed) { /* Update GModel */
      F(v,Q.vertices.size()) {
        if (Q.vertices[v].origin != nullptr) {
          vec3 pt = Q.vertices[v].pt;
          Q.vertices[v].origin->setXYZ(pt[0],pt[1],pt[2]);
        }
      }
    }

    return all_fixed;
  }

  bool project_midpoint_vertices_on_surface_if_available(
      const HblOptions& opt, 
      BrepMesh& H, 
      const BrepMesh& Q,
      const HexToBoundaryMeshMatching& h2q) {
    // info("Project midpoint vertices on CAD (if available) ...");
    info("Project vertices on CAD (if available) ...");
    for (size_t v = 0; v < H.vertices.size(); ++v) {
      // if (h2q.vertexParent[v].first == 0) continue;
      GEntity* ge = getEntity(H, v, h2q, Q);
      if (ge != nullptr) {
        if (ge->dim() == 1) {
          GEdge* ged = dynamic_cast<GEdge*>(ge);
          if (ged->isFullyDiscrete()) continue;;
          double t = 0.;
          SPoint3 query(H.vertices[v].pt[0],H.vertices[v].pt[1],H.vertices[v].pt[2]);
          GPoint proj = ged->closestPoint(query,t);
          if (proj.succeeded()) {
            H.vertices[v].pt = {proj.x(),proj.y(),proj.z()};
          }
        } else if (ge->dim() == 2) {
          GFace* gf = dynamic_cast<GFace*>(ge);
          if (gf->isFullyDiscrete()) continue;;
          double uv[2] = {0.,0.};
          SPoint3 query(H.vertices[v].pt[0],H.vertices[v].pt[1],H.vertices[v].pt[2]);
          GPoint proj = gf->closestPoint(query,uv);
          if (proj.succeeded()) {
            H.vertices[v].pt = {proj.x(),proj.y(),proj.z()};
          }
        }
      }
    }
    return true;
  }




  bool initializeHexLayerGeometry(
      const HblInput& input,
      const HblOptions& opt, 
      HblOutput& output) {
    BrepMesh& H = output.H;
    double extrusion_factor = opt.extrusion_factor;

    info("Initialize geometry of hex layer ({} vertices, {} hexahedra), with extrusion_factor = {} ...",
        H.vertices.size(), H.cells.size(), extrusion_factor);

    bool oks = set_boundary_quad_mesh_anisotropic(opt, H, 
        input.Q, output.hexValence, input.edgeDihedralAngle, output.h2q, extrusion_factor);
    RFC(!oks, "failed to boundary quad mesh anisotropic");


    /* Project vertices on CAD */
    if (!opt.noCADproj) {
      project_midpoint_vertices_on_surface_if_available(opt, H, input.Q, output.h2q);
    }


    // std::array<double,3> lenStats = computeMinAvgMaxSurfaceEdgeLength(H, output.h2q);
    // double uExtrLen = 0.5 * (lenStats[0]+lenStats[1]) * extrusion_factor;
    std::vector<double> vExtrusionLength; /* absolute extrusion length at vertex in H */
    computeLocalExtrusionLength(H, output.h2q, extrusion_factor, vExtrusionLength);

    /* 1. Position of vertices with one adjacent edge inside (local extrusion) */
    vector<bool> bdrVertexDone(H.vertices.size(),false);
    bool okl = set_position_extruded_vertices(opt, H, output.hexValence, 
        input.Q, output.h2q, input.vertexNormals, vExtrusionLength, bdrVertexDone, DBL_MAX, 
        extrusion_factor);
    RFC(!okl, "failed to set position of extruded vertices");

    /* 2. Fans on quad regular vertices (ie nice feature curves) */
    bool okf = set_position_regular_fan_vertices(opt, H, output.hexValence, 
        input.Q, output.h2q, input.vertexNormals, bdrVertexDone, 
        extrusion_factor);
    RFC(!okf, "failed to set position on regular curve fans");


    /* 3. Laplacian smoothing of remaining interior vertices */
    vector<vector<id> > v2v(H.vertices.size());
    FC(e,H.edges.size(),output.h2q.edgeParent[e].first >= 3) {
      id v1 = H.edges[e].vertices[0];
      id v2 = H.edges[e].vertices[1];
      if (output.h2q.vertexParent[v1].first <= 2) continue;
      if (output.h2q.vertexParent[v2].first <= 2) continue;
      v2v[v1].push_back(v2);
      v2v[v2].push_back(v1);
    }
    size_t niterSmoothing = 10;
    laplacian_smoothing(H, bdrVertexDone, v2v, niterSmoothing, 0.1);

    vector<vec3> points;
    points.resize(H.vertices.size());
    F(v,points.size()) {
      points[v] = H.vertices[v].pt;
    }

    if (output.hexahedra.size() == 0) {
      /* Oriented coherent elements */
      vector<vector<id> > eltVertices(H.cells.size());
      debug("- compute oriented elements");
      vector<int> ballId; /* if multiple disconnected components */
      bool oko = compute_oriented_elements(H, eltVertices, ballId);
      RFC(!oko, "failed to compute oriented elements");
      bool oki = invert_elements_if_required(points, eltVertices, ballId);
      RFC(!oki, "failed to invert elements (as required)");

      /* Export hexes */
      vector<id8> hexes;
      hexes.reserve(eltVertices.size()/32);
      F(i,eltVertices.size()) if (eltVertices[i].size() == 8) {
        const id8 hex = {
          eltVertices[i][0], eltVertices[i][1], eltVertices[i][2], eltVertices[i][3],
          eltVertices[i][4], eltVertices[i][5], eltVertices[i][6], eltVertices[i][7] };
        hexes.push_back(hex);
      }
      output.hexahedra = hexes;
    }

    /* 4. Stats */
    vector<double> qualities(output.hexahedra.size(),-1.);
    computeHexQualities(points, output.hexahedra, qualities, QualityMetric::SICN);
    print_stats("- hex SICN stats",qualities);
    computeHexQualities(points, output.hexahedra, qualities, QualityMetric::SIGE);
    print_stats("- hex SIGE stats",qualities);
    if (output.tetrahedra.size() > 0) {
      computeTetQualities(points, output.tetrahedra, qualities, QualityMetric::SICN);
      print_stats("- tet SICN stats",qualities);
      computeTetQualities(points, output.tetrahedra, qualities, QualityMetric::SIGE);
      print_stats("- tet SIGE stats",qualities);
    }

    return true;
  }

  bool optimizeHexLayerGeometry(
      const HblInput& input,
      const HblOptions& opt, 
      HblOutput& output) {

    Msg::Info("Untangle boundary layer locally ...");
    vector<bool> locked;

    bool anisoHexTargetShapes = false;
    bool forceFullMesh = false;

    // // Note: local config untangling not well coded or useless
    // bool smoothLocalHexConfigs = true;
    // bool oks1 = untangleAndSmoothHexTetMeshWithLocalCavities(output, opt, locked,
    //     iterMaxOuter, nFailMax, anisoHexTargetShapes, forceFullMesh, smoothLocalHexConfigs);
    // RFC(!oks1, "failed to untangle and smooth local configurations");
    // if (true) {
    //   std::vector<id> cells(output.H.cells.size());
    //   F(i,output.H.cells.size()) cells[i] = i;
    //   visualization_show_cells(output.H, cells, "hex_layer_initial_ls");
    // }

    char* ffm = getenv("smooth_all");
    if (ffm) {
      Msg::Warning("forcing smoothing of all the mesh");
      forceFullMesh = true;
    }
    anisoHexTargetShapes = true;
    char* noaniso = getenv("no_aniso");
    if (noaniso) {
      Msg::Warning("disable anisotropic target shapes");
      anisoHexTargetShapes = false;
    }

    bool smoothLocalHexConfigs = false;

    bool untangled = untangleAndSmoothHexTetMeshWithLocalCavities(output, opt, locked,
        anisoHexTargetShapes, forceFullMesh, 
        smoothLocalHexConfigs);

    if (!untangled) {
      bool tryToMoveBdrVertices = false;
      if (tryToMoveBdrVertices) {
        untangled = untangleWithMovingBoundaries(output, opt, locked);
        if (!untangled) {
          Msg::Warning("hex layer mesh still have tangled elements");
        }
      } else {
        /* Mark input vertices associated to tangled hexahedra */
        for (size_t i = 0; i < output.hexahedra.size(); ++i) {
          double q = qcomp.minQualityHex({
              output.H.vertices[output.hexahedra[i][0]].pt,
              output.H.vertices[output.hexahedra[i][1]].pt,
              output.H.vertices[output.hexahedra[i][2]].pt,
              output.H.vertices[output.hexahedra[i][3]].pt,
              output.H.vertices[output.hexahedra[i][4]].pt,
              output.H.vertices[output.hexahedra[i][5]].pt,
              output.H.vertices[output.hexahedra[i][6]].pt,
              output.H.vertices[output.hexahedra[i][7]].pt, 
              }, QualityMetric::SIGE);
          if (q <= 0.) {
            for (size_t lv = 0; lv < 8; ++lv) {
              id v = output.hexahedra[i][lv];
              if (output.h2q.vertexParent[v].first == 0) {
                id qv = output.h2q.vertexParent[v].second;
                output.QvertTangled.push_back(qv);
              }
            }
          }
        }
        sort_unique(output.QvertTangled);
        if (output.QvertTangled.size() > 0) {
          Msg::Warning("hex elements still tangled, flagged %li input vertices", output.QvertTangled.size());
        }
      }
    }

    return untangled;
  }

}
