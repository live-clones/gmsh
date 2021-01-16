// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GEDGE_H
#define GEDGE_H

#include <string>
#include <vector>
#include <stdio.h>
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "GEntity.h"
#include "GVertex.h"
#include "SVector3.h"
#include "SPoint3.h"
#include "SPoint2.h"

class MElement;
class MLine;
class ExtrudeParams;
class closestPointFinder;

// A model edge.
class GEdge : public GEntity {
private:
  double _length;
  bool _tooSmall;
  closestPointFinder *_cp;
  // prescribed mesh size (_lc) at parametric points (_u_lc) (sorted by _u_lc)
  std::vector<double> _u_lc, _lc;

protected:
  GVertex *_v0, *_v1;
  std::vector<GFace *> _faces;

public:
  // same or opposite direction to the master
  int masterOrientation;

  std::vector<MLine *> lines;

  // when a compound of curves is created, both meshes should be kept alive
  // (because the 2D meshing procedure will need to access the mesh of each of
  // the original curves, in addition to the mesh of the compound curve)
  GEdge *compoundCurve;

  // the STL discretization
  std::vector<SPoint3> stl_vertices_xyz;

public:
  GEdge(GModel *model, int tag, GVertex *v0, GVertex *v1);
  GEdge(GModel *model, int tag);
  virtual ~GEdge();

  // delete mesh data
  virtual void deleteMesh();

  // get the start/end vertices of the edge
  void setBeginVertex(GVertex *gv) { _v0 = gv; }
  void setEndVertex(GVertex *gv) { _v1 = gv; }
  virtual GVertex *getBeginVertex() const { return _v0; }
  virtual GVertex *getEndVertex() const { return _v1; }
  void setVertex(GVertex *const f, const int orientation)
  {
    if(orientation > 0)
      _v0 = f;
    else if(orientation < 0)
      _v1 = f;
  }

  // specify mesh master with transformation, deduce edgeCounterparts
  void setMeshMaster(GEdge *master, const std::vector<double> &);

  // specify mesh master and edgeCounterparts, deduce transformation
  void setMeshMaster(GEdge *master, int sign);

  void reverse();

  // add/delete a face bounded by this edge
  void addFace(GFace *f);
  void delFace(GFace *f);

  // get the dimension of the edge (1)
  virtual int dim() const { return 1; }

  // returns the parent entity for partitioned entities
  virtual GEntity *getParentEntity() { return nullptr; }

  // get the list of vertices
  virtual std::vector<GVertex *> vertices() const;

  // set the visibility flag
  virtual void setVisibility(char val, bool recursive = false);

  // set color
  virtual void setColor(unsigned int val, bool recursive = false);

  // true if the edge is a seam for the given face.
  virtual bool isSeam(const GFace *face) const { return false; }

  // get the bounding box
  virtual SBoundingBox3d bounds(bool fast = false);

  // get the oriented bounding box
  virtual SOrientedBoundingBox getOBB();

  // regions that are bounded by this entity
  virtual std::list<GRegion *> regions() const;

  // faces that this entity bounds
  virtual std::vector<GFace *> faces() const { return _faces; }

  // get number of faces
  virtual std::size_t numFaces() const { return _faces.size(); }

  // get the point for the given parameter location
  virtual GPoint point(double p) const = 0;

  // true if the edge contains the given parameter
  virtual bool containsParam(double pt) const;

  // get the position for the given parameter location
  virtual SVector3 position(double p) const
  {
    GPoint gp = point(p);
    return SVector3(gp.x(), gp.y(), gp.z());
  }

  // get first derivative of edge at the given parameter
  virtual SVector3 firstDer(double par) const = 0;

  // get second derivative of edge at the given parameter (default
  // implentation using central differences)
  virtual SVector3 secondDer(double par) const;

  // get the curvature
  virtual double curvature(double par) const;

  // reparmaterize the point onto the given face
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;

  // return the minimum number of segments used for meshing the edge
  virtual int minimumMeshSegments() const { return 1; }

  // return the minimum number of segments used for drawing the edge
  virtual int minimumDrawSegments() const { return 1; }

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString(bool multline = false);

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // tell if the edge is a 3D edge (in opposition with a trimmed curve on a
  // surface)
  virtual bool is3D() const { return true; }

  // get/set/compute the length of the model edge
  double length() const { return _length; }
  void setLength(const double l) { _length = l; }
  double length(const double &u0, const double &u1, const int nbQuadPoints = 4);

  // get the prescribed mesh size on the edge
  double prescribedMeshSizeAtVertex() const { return meshAttributes.meshSize; }

  double prescribedMeshSizeAtParam(double u);

  void setMeshSizeParametric(const std::vector<double> u,
                             const std::vector<double> lc);

  // true if start == end and no more than 2 segments
  void setTooSmall(bool const b) { _tooSmall = b; }
  virtual bool isMeshDegenerated() const
  {
    if(_tooSmall) Msg::Debug("Degenerated mesh on curve %d: too small", tag());
    if(_v0 && _v0 == _v1 && mesh_vertices.size() < 2)
      Msg::Debug("Degenerated mesh on curve %d: %d mesh nodes", tag(),
                 (int)mesh_vertices.size());
    return _tooSmall || (_v0 && _v0 == _v1 && mesh_vertices.size() < 2);
  }

  // types of elements
  virtual void getElementTypes(std::vector<int> &types) const
  {
    types.clear();
    types.push_back(TYPE_LIN);
  };

  // get total/by-type number of elements in the mesh
  std::size_t getNumMeshElements() const { return lines.size(); }
  std::size_t getNumMeshElementsByType(const int familyType) const;
  std::size_t getNumMeshParentElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(std::size_t index) const;
  // get the element at the given index for a given familyType
  MElement *getMeshElementByType(const int familyType,
                                 const std::size_t index) const;

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  // true if entity is periodic in the "dim" direction.
  virtual bool periodic(int dim) const { return _v0 == _v1; }

  // get bounds of parametric coordinate
  virtual Range<double> parBounds(int i) const = 0;
  virtual Range<double> parBoundsOnFace(GFace *face = nullptr) const
  {
    return parBounds(0);
  }
  double getLowerBound() const { return parBounds(0).low(); };
  double getUpperBound() const { return parBounds(0).high(); };

  // return the point on the face closest to the given point
  virtual GPoint closestPoint(const SPoint3 &queryPoint, double &param) const;

  // return the parmater location on the edge given a point in space
  // that is on the edge
  virtual double parFromPoint(const SPoint3 &P) const;
  virtual bool refineProjection(const SVector3 &Q, double &u, int MaxIter,
                                double relax, double tol, double &err) const;

  // compute the parameter U from a point XYZ
  virtual bool XYZToU(const double X, const double Y, const double Z, double &U,
                      const double relax = 1, bool first = true) const;

  // relocate mesh vertices using parametric coordinates
  void relocateMeshVertices();

  struct {
    char method;
    double coeffTransfinite;
    double meshSize, meshSizeFactor;
    int nbPointsTransfinite;
    int typeTransfinite;
    int minimumMeshSegments;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // reverse mesh orientation
    bool reverseMesh;
  } meshAttributes;

  struct {
    mutable GEntity::MeshGenerationStatus status;
  } meshStatistics;

  void addLine(MLine *line) { lines.push_back(line); }
  void addElement(int type, MElement *e);
  void removeElement(int type, MElement *e);

  virtual void discretize(double tol, std::vector<SPoint3> &dpts,
                          std::vector<double> &ts);
  SPoint3 closestPointWithTol(SPoint3 &p, double tolerance);
  virtual void mesh(bool verbose);

  virtual bool reorder(const int elementType,
                       const std::vector<std::size_t> &ordering);
};

#endif
