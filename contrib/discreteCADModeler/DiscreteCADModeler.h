// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_CAD_MODELER_H
#define DISCRETE_CAD_MODELER_H

#include <array>
#include <map>
#include <set>
#include <utility>
#include <vector>

class GModel;

// The internal data of the discrete CAD modeler: points, polylines and
// triangulations, copied into the model as discrete vertices, curves,
// surfaces and volumes by synchronize(). The nodes are shared: the
// triangulations of two surfaces with a common curve use the nodes of its
// polyline. Every surface is a topological disk, as its parametrization
// requires: a sphere has two surfaces.
class DiscreteCAD_Internals {
public:
  struct Vertex {
    int node;
  };
  // an open polyline from the node of vertex v0 to the node of vertex v1
  struct Curve {
    int v0, v1;
    std::vector<int> nodes;
  };
  // a triangulation (oriented outwards for the surfaces of a volume) bounded
  // by a loop of curves, a negative tag for a curve used backwards
  struct Surface {
    std::vector<int> curves;
    std::vector<std::array<int, 3> > triangles;
  };
  // a closed shell of surfaces, a negative tag for a surface used reversed
  struct Volume {
    std::vector<int> surfaces;
  };

private:
  std::vector<std::array<double, 3> > _nodes;
  std::map<int, Vertex> _vertices;
  std::map<int, Curve> _curves;
  std::map<int, Surface> _surfaces;
  std::map<int, Volume> _volumes;
  int _maxTag[4];
  // the entities copied into the model by the last synchronize
  std::vector<std::pair<int, int> > _synchronized;
  bool _exists(int dim, int tag) const;
  // a free tag of dimension dim if tag <= 0, else tag if it is free
  bool _assignTag(int dim, int &tag);
  int _addNode(double x, double y, double z);
  int _addVertex(int node);
  int _addCurve(int v0, int v1, const std::vector<int> &nodes);
  int _addSurface(const std::vector<int> &curves,
                  const std::vector<std::array<int, 3> > &triangles);

public:
  DiscreteCAD_Internals();
  void reset();
  // a box with a corner at (x, y, z) and extents dx, dy, dz; tag is the tag
  // of the volume (a new one if tag <= 0)
  bool addBox(int &tag, double x, double y, double z, double dx, double dy,
              double dz);
  // a sphere whose triangulation is at most tolerance away from the exact
  // surface (Geometry.DiscreteTolerance times the radius if tolerance <= 0)
  bool addSphere(int &tag, double xc, double yc, double zc, double radius,
                 double tolerance);
  // the entities copied into the model, replacing those of the previous call
  void synchronize(GModel *model);
};

#endif
