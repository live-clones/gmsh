// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_H
#define HIERARCHICAL_BASIS_H

#include <array>
#include <cassert>
#include <string>
#include <vector>

#include "OrthogonalPoly.h"

// Hierarchical basis functions on a reference element. The functions are
// associated with the vertices, edges, faces and interior ("bubble") of the
// element; the edge and face functions depend on the orientation of the
// element, given by the ordering of the tags of its vertices.
class HierarchicalBasis {
public:
  // the function spaces, and their derivatives
  enum Space { H1, GRAD_H1, HCURL, CURL_HCURL, HDIV, DIV_HDIV };

  // create the basis of the function space named fsName ("H1Legendre",
  // "GradH1Legendre", "HcurlLegendre", "CurlHcurlLegendre", "HdivLegendre" or
  // "DivHdivLegendre") of the given order on the elements of the given family
  // (TYPE_LIN, TYPE_TRI, ...); return nullptr, with an error message, if it is
  // not available
  static HierarchicalBasis *create(const std::string &fsName, int familyType,
                                   int order);

  virtual ~HierarchicalBasis() = default;

  Space getSpace() const { return _space; }
  // number of components of each basis function: 1 or 3
  int getNumComponents() const
  { return (_space == H1 || _space == DIV_HDIV) ? 1 : 3; }
  // number of orientations of the element, i.e. of permutations of its
  // vertices
  int getNumberOfOrientations() const;

  int getNumEdge() const { return _numEdge; }
  int getNumTriFace() const { return _numTriFace; }
  int getNumQuadFace() const { return _numQuadFace; }
  int getNumVertexFunction() const { return _numVertexFunction; }
  int getNumEdgeFunction() const { return _numEdgeFunction; }
  int getNumTriFaceFunction() const { return _numTriFaceFunction; }
  int getNumQuadFaceFunction() const { return _numQuadFaceFunction; }
  int getNumBubbleFunction() const { return _numBubbleFunction; }
  int getNumFunctions() const
  {
    return _numVertexFunction + _numEdgeFunction + _numTriFaceFunction +
           _numQuadFaceFunction + _numBubbleFunction;
  }

  // evaluate the basis functions at the points uvw (u, v, w for each point),
  // for the given orientations of the element (all of them if empty). The
  // values are ordered by orientation, then by point, then by function
  // (vertex, edge, face and bubble functions), with getNumComponents() values
  // per function
  void evaluate(const std::vector<double> &uvw,
                const std::vector<int> &orientations,
                std::vector<double> &values);

  // the sign (1 or -1) taken by each edge function when its edge is reversed
  std::vector<int> getEdgeFunctionSignsForReversedEdges();

  // the type (0 for vertex, 1 for edge, 2 for face, 3 for bubble functions)
  // and the order of each basis function
  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo) = 0;

protected:
  Space _space = H1;
  int _familyType = 0;

  // number of vertices, edges, quadrilateral and triangular faces
  int _numVertex;
  int _numEdge;
  int _numQuadFace;
  int _numTriFace;

  // number of basis functions
  int _numVertexFunction;
  int _numEdgeFunction;
  int _numQuadFaceFunction;
  int _numTriFaceFunction;
  int _numBubbleFunction;

  HierarchicalBasis() = default;

  // The operations below are implemented by each element, for scalar
  // (std::vector<double>) and vector (std::vector<std::vector<double>>)
  // functions; which ones are used depends on the space (e.g. vector values
  // for H(curl), vector gradients for H1).

  // the basis functions at (u, v, w) in the reference orientation
  virtual void generateBasis(double u, double v, double w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis) = 0;
  virtual void generateBasis(double u, double v, double w,
                             std::vector<std::vector<double>> &vertexBasis,
                             std::vector<std::vector<double>> &edgeBasis,
                             std::vector<std::vector<double>> &faceBasis,
                             std::vector<std::vector<double>> &bubbleBasis) = 0;

  // the edge functions for the reversed orientation of all the edges
  virtual void
  orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions) = 0;
  virtual void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double>> &edgeFunctions) = 0;

  // copy the functions of edge edgeNumber from eTablePositiveFlag (computed by
  // generateBasis) or from eTableNegativeFlag (computed by
  // orientEdgeFunctionsForNegativeFlag), depending on the orientation flag
  virtual void orientEdge(int flagOrientation, int edgeNumber,
                          std::vector<double> &edgeFunctions,
                          const std::vector<double> &eTablePositiveFlag,
                          const std::vector<double> &eTableNegativeFlag) = 0;
  virtual void
  orientEdge(int flagOrientation, int edgeNumber,
             std::vector<std::vector<double>> &edgeBasis,
             const std::vector<std::vector<double>> &eTablePositiveFlag,
             const std::vector<std::vector<double>> &eTableNegativeFlag) = 0;

  // the face functions for all the orientations of the faces (8 for
  // quadrilateral faces, 6 for triangular faces)
  virtual void addAllOrientedFaceFunctions(
    double u, double v, double w, const std::vector<double> &faceFunctions,
    std::vector<double> &quadFaceFunctionsAllOrientation,
    std::vector<double> &triFaceFunctionsAllOrientation) = 0;
  virtual void addAllOrientedFaceFunctions(
    double u, double v, double w,
    const std::vector<std::vector<double>> &faceFunctions,
    std::vector<std::vector<double>> &quadFaceFunctionsAllOrientation,
    std::vector<std::vector<double>> &triFaceFunctionsAllOrientation) = 0;

  // copy the functions of face faceNumber, for the orientation given by the
  // flags, from the tables computed by addAllOrientedFaceFunctions
  virtual void
  orientFace(int flag1, int flag2, int flag3, int faceNumber,
             const std::vector<double> &quadFaceFunctionsAllOrientation,
             const std::vector<double> &triFaceFunctionsAllOrientation,
             std::vector<double> &fTableCopy) = 0;
  virtual void orientFace(
    int flag1, int flag2, int flag3, int faceNumber,
    const std::vector<std::vector<double>> &quadFaceFunctionsAllOrientation,
    const std::vector<std::vector<double>> &triFaceFunctionsAllOrientation,
    std::vector<std::vector<double>> &fTableCopy) = 0;

  // the face functions of face faceNumber for the orientation given by the
  // flags, used by addAllOrientedFaceFunctions
  virtual void orientOneFace(double u, double v, double w, int flag1, int flag2,
                             int flag3, int faceNumber,
                             std::vector<double> &faceFunctions) = 0;
  virtual void
  orientOneFace(double u, double v, double w, int flag1, int flag2, int flag3,
                int faceNumber,
                std::vector<std::vector<double>> &faceFunctions) = 0;

  // the index of an orientation of a quadrilateral face (0 to 7) or of a
  // triangular face (0 to 5) in the tables of addAllOrientedFaceFunctions,
  // and the reverse:
  //
  //  quadrilateral faces                 triangular faces
  //  flag1   flag2   flag3   index       flag1   flag2   index
  //   +1      +1      +1       0           0      +1       0
  //   -1      +1      +1       1           1      +1       1
  //   +1      -1      +1       2           2      +1       2
  //   -1      -1      +1       3           0      -1       3
  //   +1      +1      -1       4           1      -1       4
  //   -1      +1      -1       5           2      -1       5
  //   +1      -1      -1       6
  //   -1      -1      -1       7
  static int getOrientationQuadFaceIndex(int flag1, int flag2, int flag3)
  {
    assert((flag1 == 1 || flag1 == -1) && (flag2 == 1 || flag2 == -1) &&
           (flag3 == 1 || flag3 == -1));
    return (flag1 == -1 ? 1 : 0) | (flag2 == -1 ? 2 : 0) |
           (flag3 == -1 ? 4 : 0);
  }
  static int getOrientationTriFaceIndex(int flag1, int flag2)
  {
    assert((flag1 == 0 || flag1 == 1 || flag1 == 2) &&
           (flag2 == 1 || flag2 == -1));
    return flag1 + (flag2 == -1 ? 3 : 0);
  }
  static std::array<int, 3> getQuadFaceFlagsFromIndex(int index)
  {
    assert(index >= 0 && index < 8);
    return {(index & 1) ? -1 : 1, (index & 2) ? -1 : 1, (index & 4) ? -1 : 1};
  }
  static std::array<int, 2> getTriFaceFlagsFromIndex(int index)
  {
    assert(index >= 0 && index < 6);
    return {index % 3, (index < 3) ? 1 : -1};
  }

private:
  template <class T>
  void _evaluate(const std::vector<double> &uvw,
                 const std::vector<int> &orientations,
                 std::vector<double> &values);
};

#endif
