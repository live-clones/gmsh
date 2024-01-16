// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Contributors: Amaury Johnen

#ifndef BOUNDARY_LAYER_CURVER_H
#define BOUNDARY_LAYER_CURVER_H

#include <algorithm>
#include <list>

#include "MEdge.h"
#include "MFace.h"
#include "nodalBasis.h"
#include "fullMatrix.h"

class MElement;
class GEntity;
class MVertex;
struct IntPt;

typedef std::pair<MElement *, std::vector<MElement *> > PairMElemVecMElem;
typedef std::vector<PairMElemVecMElem> VecPairMElemVecMElem;

namespace BoundaryLayerCurver {
  bool computeCommonEdge(MElement *el1, MElement *el2, MEdge &e);

  void repositionInnerVertices(const std::vector<MFaceN> &stackFaces,
                               const GFace *gface);

  MElement *createPrimaryElement(MElement *el);

  // The boundary layer curver algorithm is seperated into different modules:
  namespace EdgeCurver2D {
  }
  namespace EdgeCurver3D {
  }
  namespace FaceCurver {
  }
  namespace InteriorEdgeCurver {
  }
  namespace InteriorFaceCurver {
  }

  namespace EdgeCurver2D {
    // A 2D edge can be on a 3D face or in a plane. The normal to the surface
    // that contain the edge is needed. It is computed from the CAD if 'gface'
    // and 'gedge' are provided. Otherwise, 'normal' is taken into account.
    // At least 'gface' & 'gedge' or 'normal' have to be provided.
    void curveEdge(const MEdgeN *baseEdge, MEdgeN *edge, const GFace *gface,
                   const GEdge *gedge, const SVector3 &normal);

    void recoverQualityElements(std::vector<MEdgeN> &stackEdges,
                                std::vector<MFaceN> &stackFaces,
                                std::vector<MElement *> &stackElements,
                                int iFirst, int iLast, const GFace *gface);

    class _Frame {
      SVector3 _normalToTheMesh;
      const GFace *_gface;
      const GEdge *_gedge;
      const MEdgeN *_edgeOnBoundary;
      double _paramVerticesOnGFace[40];
      double _paramVerticesOnGEdge[20];

    public:
      _Frame(const MEdgeN *edge, const GFace *gface, const GEdge *gedge,
             const SVector3 &normal);

      void computeFrame(double paramEdge, SVector3 &t, SVector3 &n, SVector3 &w,
                        bool atExtremity = false) const;

      SPoint3 pnt(double u) const;
    };
  } // namespace EdgeCurver2D

  namespace InteriorEdgeCurver {
    void curveEdges(std::vector<MEdgeN> &stack, int iFirst, int iLast,
                    const GFace *gface);

    void curveEdgesAndPreserveQuality(std::vector<MEdgeN> &stackEdges,
                                      std::vector<MFaceN> &stackFaces,
                                      std::vector<MElement *> &stackElements,
                                      int iFirst, int iLast,
                                      const GFace *gface);
  } // namespace InteriorEdgeCurver

  struct Parameters3DCurve {
    double thickness[2];
    double coeffb[2];
    double coeffc[2];

    double thicknessAtPoint(double xi, int triDirection = 0) const
    {
      if(triDirection == 0)
        return thickness[0] * (1 - xi) / 2 + thickness[1] * (1 + xi) / 2;
      else if(triDirection > 0)
        return thickness[1] * (1 + xi) / 2;
      else
        return thickness[0] * (1 - xi) / 2;
    }
    double coeffbAtPoint(double xi, int triDirection = 0) const
    {
      if(triDirection == 0)
        return coeffb[0] * (1 - xi) / 2 + coeffb[1] * (1 + xi) / 2;
      else if(triDirection > 0)
        return coeffb[1] * (1 + xi) / 2;
      else
        return coeffb[0] * (1 - xi) / 2;
    }
    double coeffcAtPoint(double xi, int triDirection = 0) const
    {
      if(triDirection == 0)
        return coeffc[0] * (1 - xi) / 2 + coeffc[1] * (1 + xi) / 2;
      else if(triDirection > 0)
        return coeffc[1] * (1 + xi) / 2;
      else
        return coeffc[0] * (1 - xi) / 2;
    }
    double characteristicThickness()
    {
      return std::min(std::abs(thickness[0]), std::abs(thickness[1]));
    }
  };

  class Parameters3DSurface {
    std::vector<double> _thickness;
    std::vector<double> _coeffb;
    std::vector<double> _coeffc;
    int _nCorner;
    int _order; // not necessary
    double _factorDegenerate[4];
    const nodalBasis *_fs, *_primaryFs;
    //    const MFaceN baseFace;

  public:
    Parameters3DSurface() {}
    ~Parameters3DSurface() {}

    void computeParameters(const MFaceN &baseFace, const MFaceN &topFace);

    SPoint3 computeIdealPositionTopFace(const MFaceN &baseFace, double u,
                                        double v) const;

    //    double characteristicThickness() {
    //      return std::min(std::abs(thickness[0]), std::abs(thickness[1]));
    //    }
  };

  struct LeastSquareData {
    fullMatrix<double> invA;
    //    fullMatrix<double> Leg2Lag;
    int nbPoints;
    IntPt *intPoints;
  };

  struct TFIData {
    fullMatrix<double> T0;
    fullMatrix<double> T1;
  };

  // Least square data
  typedef std::pair<int, std::pair<int, int> > TupleLeastSquareData;
  static std::map<TupleLeastSquareData, LeastSquareData *> leastSquareData;
  LeastSquareData *getLeastSquareData(int typeElement, int order,
                                      int orderGauss);
  LeastSquareData *constructLeastSquareData(int typeElement, int order,
                                            int orderGauss);

  namespace InnerVertPlacementMatrices {
    const fullMatrix<double> *triangle(int order, bool linear, int edge = 2);
    const fullMatrix<double> *quadrangle(int order, bool linear);
    const fullMatrix<double> *tetrahedron(int order, bool linear, int face = 0,
                                          int otherFace = 0);
    const fullMatrix<double> *hexahedron(int order, bool linear, int face = 0);
    const fullMatrix<double> *prism(int order, bool linear, int face = 0);
  } // namespace InnerVertPlacementMatrices

} // namespace BoundaryLayerCurver

// BL in planar surface (always prefer this one if possible)
void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, SVector3 normal,
                          const GEdge *edge = nullptr);

// BL on CAD surface
void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, const GFace *,
                          const GEdge *);

// 3D BL
void curve3DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, const GFace *);

#endif
