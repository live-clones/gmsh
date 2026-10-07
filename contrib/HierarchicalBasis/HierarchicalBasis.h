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

#include "Dual.h"

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

  // Each element computes its basis functions at the point x (the reference
  // coordinates u, v, w as dual numbers), each function once, as a dual number
  // (Dual) for H1 or a vector of dual numbers (Vec) for H(curl) and H(div): the
  // derivatives (gradients, curls, divergences) follow. functions() gives the
  // functions in the reference orientation, faceFunctions() replaces those of
  // face faceNumber by the functions for the orientation of the face given by
  // the flags. Each element implements the version of its space; the other one
  // does nothing.
  virtual void functions(const Dual *x, std::vector<Dual> &vertex,
                         std::vector<Dual> &edge, std::vector<Dual> &face,
                         std::vector<Dual> &bubble);
  virtual void functions(const Dual *x, std::vector<Vec> &vertex,
                         std::vector<Vec> &edge, std::vector<Vec> &face,
                         std::vector<Vec> &bubble);
  virtual void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                             int faceNumber, std::vector<Dual> &face);
  virtual void faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                             int faceNumber, std::vector<Vec> &face);

private:
  // the functions at the point uvw in the reference orientation, and the face
  // functions for the 8 orientations of the quadrilateral faces and the 6
  // orientations of the triangular faces, getNumComponents() values per
  // function
  template <class E>
  void _generate(const double *uvw, double *vertex, double *edge, double *face,
                 double *bubble, double *quadFaces, double *triFaces);
  // the value or the derivative of a function, depending on the space
  void _store(const Dual &f, double *out) const;
  void _store(const Vec &f, double *out) const;
};

#endif
