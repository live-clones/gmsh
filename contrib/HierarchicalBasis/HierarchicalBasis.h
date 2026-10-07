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

  // Each element computes, at one point (u, v, w), the basis functions in the
  // reference orientation (generateBasis), and the face functions of face
  // faceNumber for the orientation of the face given by the flags
  // (orientOneFace). Both are implemented for scalar (std::vector<double>)
  // and vector (std::vector<std::vector<double>>) functions; which version is
  // used depends on the space (scalar values and vector gradients for H1,
  // vector values and curls for H(curl), vector values and scalar divergences
  // for H(div)). The versions an element does not need do nothing.
  virtual void generateBasis(double u, double v, double w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis);
  virtual void generateBasis(double u, double v, double w,
                             std::vector<std::vector<double>> &vertexBasis,
                             std::vector<std::vector<double>> &edgeBasis,
                             std::vector<std::vector<double>> &faceBasis,
                             std::vector<std::vector<double>> &bubbleBasis);
  virtual void orientOneFace(double u, double v, double w, int flag1, int flag2,
                             int flag3, int faceNumber,
                             std::vector<double> &faceFunctions);
  virtual void orientOneFace(double u, double v, double w, int flag1, int flag2,
                             int flag3, int faceNumber,
                             std::vector<std::vector<double>> &faceFunctions);

private:
  // the functions at the point uvw in the reference orientation, and the face
  // functions for the 8 orientations of the quadrilateral faces and the 6
  // orientations of the triangular faces, getNumComponents() values per
  // function
  template <class T>
  void _generate(const double *uvw, double *vertex, double *edge, double *face,
                 double *bubble);
  template <class T>
  void _orientFaces(const double *uvw, const double *face, double *quadFaces,
                    double *triFaces);
};

#endif
