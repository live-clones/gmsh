// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GVERTEX_H
#define GVERTEX_H

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include "GmshDefines.h"
#include "GEntity.h"
#include "GPoint.h"
#include "SPoint2.h"
#include "SPoint3.h"

class MElement;
class MPoint;

// A model vertex.
class GVertex : public GEntity {
protected:
  std::vector<GEdge *> l_edges;
  double meshSize;

public:
  GVertex(GModel *m, int tag, double ms = MAX_LC);
  virtual ~GVertex();

  // delete mesh data
  virtual void deleteMesh();

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  // get/set the coordinates of the vertex
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  virtual SPoint3 xyz() const { return SPoint3(x(), y(), z()); }
  virtual void setPosition(GPoint &p);

  // add/delete an edge bounded by this vertex
  void addEdge(GEdge *e);
  void delEdge(GEdge *e);

  // regions that bound this entity or that this entity bounds.
  virtual std::list<GRegion *> regions() const;

  // get the edges that this vertex bounds
  virtual std::vector<GEdge *> const &edges() const { return l_edges; }

  // get number of edges
  virtual std::size_t numEdges() const { return l_edges.size(); }

  // faces that bound this entity or that this entity bounds.
  virtual std::vector<GFace *> faces() const;

  // get the dimension of the vertex (0)
  virtual int dim() const { return 0; }

  // returns the parent entity for partitioned entities
  virtual GEntity *getParentEntity() { return nullptr; }

  // get the geometric type of the vertex
  virtual GeomType geomType() const { return Point; }

  // get/set the prescribed mesh size at the vertex
  virtual inline double prescribedMeshSizeAtVertex() const { return meshSize; }
  virtual void setPrescribedMeshSizeAtVertex(double l) { meshSize = l; }

  // get the bounding box
  virtual SBoundingBox3d bounds(bool fast = false)
  {
    return SBoundingBox3d(SPoint3(x(), y(), z()));
  }

  // reparmaterize the point onto the given face
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString(bool multline = false);

  // export in GEO format
  virtual void writeGEO(FILE *fp, const std::string &meshSizeParameter = "");

  // types of elements
  virtual void getElementTypes(std::vector<int> &types) const
  {
    types.clear();
    types.push_back(TYPE_PNT);
  };

  // get number of elements in the mesh
  std::size_t getNumMeshElements() const { return points.size(); }
  std::size_t getNumMeshElementsByType(const int familyType) const;
  void getNumMeshElements(unsigned *const c) const;

  // get the element at the given index
  MElement *getMeshElement(std::size_t index) const;
  // get the element at the given index for a given familyType
  MElement *getMeshElementByType(const int familyType,
                                 const std::size_t index) const;

  // return true if this vertex is on a seam of the given face
  bool isOnSeam(const GFace *gf) const;

  // relocate mesh vertex using GVertex coordinates
  void relocateMeshVertices();

  std::vector<MPoint *> points;

  void addPoint(MPoint *p) { points.push_back(p); }
  void addElement(int type, MElement *e);
  void removeElement(int type, MElement *e);

  virtual bool reorder(const int elementType,
                       const std::vector<std::size_t> &ordering);
};

#endif
